/*
 * Copyright (C) 2022 BfaCore Reforged
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

 //Missing scripts

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "Vehicle.h"
#include "freehold.h"

enum KraggSpells
{
    ///Rider SkyCap Kragg (Before Fight with Boss)
    VileBombadment = 256005,
    VileCoating = 256016,
    ///Boss SkyCap Kragg
    Charrrrrge = 255952, /// With Mount 
    PistolShot = 255966, /// With Mount 
    AzeritePowderShot = 256106, /// Without Mount 
    RevitalizingBrewSkyCap = 256060, /// Without Mount
    RevitalizingBrewPlayer = 263297,
    ///Heroic
    DiveBomb = 272046  ///Sharkbait will then charge across the arena in a straight line, dealing damage and knocking back all players in the path
};

enum KraggEvents
{
    EventVileBombadment = 1,
    EventChaaarrge,
    EventPistolShot,
    EventAzeritePowderShot,
    EventRevitalizingBrew,
    ///Heroic Event
    EventDiveBombs,
};

enum KraggDatas
{
    DataCharge,
    DataMountInCombat
};

enum KraggPhases
{
    PhaseMount,
    PhaseUnmount
};

enum KraggMovementPoint
{
    MovementPointMiddle,
    MovementPointDiveBomb,
    MovementPointDiveBombCasted
};

enum KraggTalk
{
    TalkAggro1 = 0,
    TalkUnmount = 1,
    TalkAzeritePowderShot1 = 2,
    TalkDead = 5,
    TalkAggro2 = 6,
    TalkAzeritePowderShot2 = 7,
    TalkDiveBomb = 8
};

Position const MiddlePos = { -1768.29f, -1009.25f, 110.0f, 0.418879f };

///Todo Add damage on mechanic Dive Bombs, is necesary make  SPELL_EFFECT_254 is something related about charge effect and target front the trajectory 

Position GetRandomPositionAround(Unit* unit, float distMin, float distMax)
{
    double angle = rand_norm() * 2.0 * M_PI;
    float x = unit->GetPositionX() + (float)(frand(distMin, distMax) * std::sin(angle));
    float y = unit->GetPositionY() + (float)(frand(distMin, distMax) * std::cos(angle));
    float z = unit->GetPositionZ();
    unit->UpdateAllowedPositionZ(x, y, z);
    return { x, y, z };
}

///126832 - Skycap Kragg 
struct boss_skycap_kragg : public BossAI
{
    boss_skycap_kragg(Creature* creature) : BossAI(creature, FreeholdData::DataSkycapKragg)
    {}

    void Reset() override
    {
        mountGUID.Clear();
        checkTimer = 1000;
        fightStarted = false;
        charge = false;
        resetFight = true;
        phase = PhaseMount;
        me->ResetLootMode();
        events.Reset();
        summons.DespawnAll();
        me->RemoveAllAreaTriggers();
        me->SetReactState(ReactStates::REACT_AGGRESSIVE);

        if (instance)
        {
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            instance->SetBossState(FreeholdData::DataSkycapKragg, NOT_STARTED);
        }

        if (!me->IsOnVehicle())
        {
            if (Creature* mount = me->SummonCreature(FreeholdCreature::NpcSharkBaitBoss, me->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN))
            {
                mountGUID = mount->GetGUID();
                me->EnterVehicle(mount);
                mount->AI()->SetData(KraggDatas::DataMountInCombat, false);
                mount->DeleteThreatList();
            }
        }
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        if (fightStarted)
        {
            fightStarted = false;
            me->InterruptNonMeleeSpells(true);
            me->SetReactState(ReactStates::REACT_PASSIVE);
            me->DeleteThreatList();
            me->CombatStop();
            me->CastStop();
            me->GetMotionMaster()->Clear();
            me->GetMotionMaster()->MoveTargetedHome();
        }
    }

    void JustReachedHome() override
    {
        _JustReachedHome();
        //instance->SetBossState(FreeholdData::DataSkycapKragg, FAIL); //CRASHES CORE
        Reset();
    }

    void EnterCombat(Unit* /*who*/) override
    {
        if (instance)
        {
            // bosses do not respawn, check only on enter combat
            if (!instance->CheckRequiredBosses(me->GetEntry()))
            {
                EnterEvadeMode(EVADE_REASON_SEQUENCE_BREAK);
                return;
            }
            instance->SetBossState(FreeholdData::DataSkycapKragg, IN_PROGRESS);
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);
        }

        if (urand(0, 1) == 1)
            Talk(KraggTalk::TalkAggro1);
        else
            Talk(KraggTalk::TalkAggro2);

        me->SetReactState(ReactStates::REACT_AGGRESSIVE);
        phase = PhaseMount;
        me->setActive(true);
        DoZoneInCombat();
        fightStarted = true;
        if (Creature* mount = ObjectAccessor::GetCreature(*me, mountGUID))
            mount->AI()->SetData(KraggDatas::DataMountInCombat, true);

        events.ScheduleEvent(KraggEvents::EventPistolShot, urand(3000, 5000));
        events.ScheduleEvent(KraggEvents::EventChaaarrge, 8000);
    }

    void OnSpellCastInterrupt(SpellInfo const* spell)
    {
        if (spell->Id == KraggSpells::RevitalizingBrewSkyCap)
        {
            me->RemoveAura(KraggSpells::RevitalizingBrewSkyCap);
            me->SummonCreature(FreeholdCreature::NpcRevitalizingBrew, GetRandomPositionAround(me, 3.0f, 5.0f), TEMPSUMMON_TIMED_DESPAWN, 15000);
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(KraggTalk::TalkDead);
        if (instance)
            instance->SetBossState(FreeholdData::DataSkycapKragg, DONE);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        if (me->HealthWillBeBelowPctDamaged(75, damage) && phase == PhaseMount)
        {
            phase = PhaseUnmount;
            Talk(KraggTalk::TalkUnmount);
            me->ExitVehicle();

            if (Creature* mount = ObjectAccessor::GetCreature(*me, mountGUID))
            {
                mount->SetReactState(REACT_PASSIVE);
                mount->GetMotionMaster()->MovePoint(KraggMovementPoint::MovementPointMiddle, MiddlePos);
            }

            events.Reset();

            events.ScheduleEvent(KraggEvents::EventAzeritePowderShot, 2000);
            events.ScheduleEvent(KraggEvents::EventRevitalizingBrew, 15000);
        }
    }

    void SetData(uint32 id, uint32 value)
    {
        if (id == KraggDatas::DataCharge)
            charge = value;
    }

    void UpdateAI(uint32 diff) override
    {
        if (fightStarted)
        {
            if (checkTimer <= diff)
            {
                // Retrieving targets
                Map::PlayerList const& PlayerList = me->GetMap()->GetPlayers();
                if (!PlayerList.isEmpty())
                {
                    for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                    {
                        Player* player = i->GetSource();
                        if (player->IsAlive())
                        {
                            resetFight = false;
                            break;
                        }
                        else
                            resetFight = true;
                    }
                }

                if (resetFight)
                    EnterEvadeMode(EVADE_REASON_NO_HOSTILES);

                checkTimer = 1000;
            }
            else
                checkTimer -= diff;
        }

        if (!UpdateVictim() && fightStarted)
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case KraggEvents::EventChaaarrge:
            {
                if (Creature* mount = ObjectAccessor::GetCreature(*me, mountGUID))
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0.0, 0.0, true))
                    {
                        charge = true;
                        mount->StopMoving();
                        mount->SetReactState(REACT_PASSIVE);
                        mount->CastSpell(target, KraggSpells::Charrrrrge, false);
                    }
                }

                events.Repeat(8000);
                break;
            }
            case KraggEvents::EventPistolShot:
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0.0, 0.0, true))
                    me->CastSpell(target, KraggSpells::PistolShot, false);

                events.Repeat(8000);
                break;
            }
            case KraggEvents::EventAzeritePowderShot:
            {
                if (urand(0, 1) == 1)
                    Talk(KraggTalk::TalkAzeritePowderShot1);
                else
                    Talk(KraggTalk::TalkAzeritePowderShot1);

                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0.0, 0.0, true))
                    me->CastSpell(target, KraggSpells::AzeritePowderShot, false);

                events.Repeat(8000);
                break;
            }
            case KraggEvents::EventRevitalizingBrew:
            {
                me->CastSpell(me, KraggSpells::RevitalizingBrewSkyCap, false);

                events.Repeat(15000);
                break;
            }
            }
        }

        DoMeleeAttackIfReady();

    }

private:
    ObjectGuid mountGUID;
    KraggPhases phase;
    bool fightStarted;
    bool resetFight;
    bool charge;
    uint32 checkTimer;
};

/// 129743, 126841 - Shark Bait
struct npc_sharkbait : public ScriptedAI
{
    npc_sharkbait(Creature* creature) : ScriptedAI(creature)
    {
        DiveBomb = false;
        InCombat = false;
        m_Instance = creature->GetInstanceScript();
    }

    void JustReachedHome() override
    {
        if (Creature* kragg = m_Instance->instance->GetCreature(m_Instance->GetGuidData(FreeholdCreature::NpcSkycapKragg)))
        {
            kragg->ExitVehicle();
            kragg->AI()->EnterEvadeMode(EVADE_REASON_NO_HOSTILES);
        }

        me->DespawnOrUnsummon();
    }

    void SetData(uint32 id, uint32 value)
    {
        if (id == KraggDatas::DataMountInCombat)
            InCombat = value;
    }

    void MovementInform(uint32 type, uint32 pointId) override
    {
        if (type != POINT_MOTION_TYPE && type != EFFECT_MOTION_TYPE)
            return;

        switch (pointId)
        {
        case KraggMovementPoint::MovementPointMiddle:
        {
            if (!me->IsInCombat())
                me->SetInCombatWithZone();

            events.Reset();
            events.ScheduleEvent(KraggEvents::EventVileBombadment, 5000);
            if (IsHeroic())
                events.ScheduleEvent(KraggEvents::EventDiveBombs, 17000);
            break;
        }
        case KraggMovementPoint::MovementPointDiveBomb:
        {
            DiveBomb = true;
            me->CastSpell(me, KraggSpells::DiveBomb, false);
            break;
        }
        case KraggMovementPoint::MovementPointDiveBombCasted:
        {
            events.Reset();
            DiveBomb = false;
            me->GetMotionMaster()->MovePoint(KraggMovementPoint::MovementPointMiddle, MiddlePos);
            break;
        }
        case EVENT_JUMP:
            me->SetReactState(REACT_AGGRESSIVE);
            if (Creature* kragg = m_Instance->instance->GetCreature(m_Instance->GetGuidData(FreeholdCreature::NpcSkycapKragg)))
                kragg->AI()->SetData(KraggDatas::DataCharge, false);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if ((!UpdateVictim() && InCombat) || DiveBomb)
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case KraggEvents::EventVileBombadment:
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0.0, 0.0, true))
                    me->CastSpell(target, KraggSpells::VileBombadment, false);

                events.Repeat(5000);
                break;
            }
            case KraggEvents::EventDiveBombs:
            {
                if (Creature* kragg = m_Instance->instance->GetCreature(m_Instance->GetGuidData(FreeholdCreature::NpcSkycapKragg)))
                    kragg->AI()->Talk(KraggTalk::TalkDiveBomb);

                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0.0, 0.0, true))
                    me->GetMotionMaster()->MovePoint(KraggMovementPoint::MovementPointDiveBomb, GetRandomPositionAround(target, 10.0f, 15.0f));
                break;
            }
            }
        }
    }

private:
    bool DiveBomb;
    bool InCombat;
    InstanceScript* m_Instance;
};

/// 134021 - Revitalizing Brew
struct npc_revitalizing_brew : public ScriptedAI
{
    npc_revitalizing_brew(Creature* creature) : ScriptedAI(creature) { }

    void OnSpellClick(Unit* p_Clicker, bool& /*result*/) override
    {
        p_Clicker->CastSpell(p_Clicker, KraggSpells::RevitalizingBrewPlayer, true);
        me->DespawnOrUnsummon();
    }
};

///Spell 256035 Vile Bombardment Areatriger ID 11912
struct at_vile_bombardment : AreaTriggerAI
{
    at_vile_bombardment(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit)
    {
        if (Player* player = unit->ToPlayer())
            if (!player->HasAura(KraggSpells::VileCoating))
                player->CastSpell(player, KraggSpells::VileCoating, true);
    }

    void OnUnitExit(Unit* unit)
    {
        unit->RemoveAurasDueToSpell(KraggSpells::VileCoating);
    }
};

///272046 Dive Bomb
class spell_dive_bomb : public SpellScript
{
    PrepareSpellScript(spell_dive_bomb);

    void HandleOnCast()
    {
        if (Unit* caster = GetCaster())
        {
            if (caster->IsCreature())
            {
                if (Unit* target = caster->ToCreature()->AI()->SelectTarget(SELECT_TARGET_RANDOM, 0.0, 0.0, true))
                {
                    Position ChargePosition;
                    GetPositionWithDistInOrientation(target, 10.0f, caster->GetAngle(target), ChargePosition);
                    caster->GetMotionMaster()->MoveCharge(ChargePosition.GetPositionX(), ChargePosition.GetPositionY(), ChargePosition.GetPositionZ(), 20.0f, KraggMovementPoint::MovementPointDiveBombCasted);
                }
            }
        }
    }

    void Register() override
    {
        OnCast += SpellCastFn(spell_dive_bomb::HandleOnCast);
    }
};


void AddSC_boss_skycapn_kragg()
{
    ///Craeture
    RegisterCreatureAI(boss_skycap_kragg);
    RegisterCreatureAI(npc_sharkbait);
    RegisterCreatureAI(npc_revitalizing_brew);
    ///Areatrigger
    RegisterAreaTriggerAI(at_vile_bombardment);
    ///Spell
    RegisterSpellScript(spell_dive_bomb);
}
