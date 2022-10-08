/*
* Copyright (C) 2021 ShadowCore
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

#include "ScriptMgr.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "InstanceScript.h"
#include "SpellAuraEffects.h"
#include "castle_nathria.h"

enum Spells
{
    //Grashaal
    SPELL_STONE_SPIKE_MISSILE = 170926,
    SPELL_STONE_BREAKERS_COMBO = 339645,
    SPELL_CRYSTALIZE_CHANNEL = 339690,
    SPELL_CRYSTALLINE_BURST_DAMAGE = 339693,
    SPELL_PULVERIZING_METEOR_MISSILE = 342544,
    SPELL_STONE_FIST = 342425,
    SPELL_SEISMIC_UPHEAVAL_MISSILE = 337595,
    SPELL_REVERBERATING_ERUPTION_MARK = 344496,
    SPELL_REVERBERATING_ERUPTION_DAMAGE_SUMMON = 344500,
    //Kaaal
    SPELL_SERRATED_SWIPE = 334929,
    SPELL_HEART_REND = 334765,
    SPELL_HEART_HEMORRAGE = 334771, //triggers from rend after dispel and expire
    SPELL_WICKED_BLADE = 333387,
    SPELL_HARDENED_STONEFORM = 329636,
    SPELL_ANIMA_ORB_CREATE_AT = 332393, //20793
    EVENT_STONEFORM_ADDS = 1,
    ACTION_PHASE_TWO = 2,
    ACTION_PHASE_THREE,
    SPELL_RICOCHETING_SHURIKEN = 343086,
    //Prince Renathal
    SPELL_SHATTERING_BLAST = 332683,
    //Stalker
    SPELL_UNSTABLE_GROUND_APPLY_AT = 344503,//21991
    SPELL_ECHOING_ANNIHILATION = 344721,
    SPELL_REVERBERATING_VULNERABILITY = 344655,
    SPELL_ECHOING_BLAST = 344740,
    SPELL_SOLDIERS_OATH = 336212,
};

//168113,168112
struct boss_stone_legion_generals : public BossAI
{
    boss_stone_legion_generals(Creature* creature) : BossAI(creature, DATA_STONE_LEGION_GENERALS) { }

private:
    bool isFlyingGeneral;
    bool hardenedStoneFormKaal;
    bool hardenedStoneForGrashaal;
    uint8 seismicUpheaval;

    void Reset() override
    {
        BossAI::Reset();
        me->SetReactState(REACT_DEFENSIVE);
        switch (me->GetEntry())
        {
        case NPC_GENERAL_GRASHAAL:
            me->CanFly();
            me->SetFlying(true);
            break;

        case NPC_GENERAL_KAAL:
            me->SetPowerType(POWER_ENERGY);
            me->SetMaxPower(POWER_ENERGY, 100);
            me->SetPower(POWER_ENERGY, 0);
            isFlyingGeneral = false;
            hardenedStoneFormKaal = false;
            break;
        }
    }

    void EnterCombat(Unit* /*who*/) override
    {
        switch (me->GetEntry())
        {
        case NPC_GENERAL_GRASHAAL:
            _EnterCombat();
            events.ScheduleEvent(SPELL_STONE_SPIKE_MISSILE, 5s);
            events.ScheduleEvent(SPELL_STONE_BREAKERS_COMBO, 30s);
            hardenedStoneForGrashaal = false;
            break;

        case NPC_GENERAL_KAAL:
            _EnterCombat();
            events.ScheduleEvent(SPELL_SERRATED_SWIPE, 5s);
            events.ScheduleEvent(SPELL_HEART_REND, 10s);
            events.ScheduleEvent(SPELL_WICKED_BLADE, 15s);
            this->seismicUpheaval = 0;
            hardenedStoneFormKaal = false;
            break;
        }
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case SPELL_STONE_SPIKE_MISSILE:
        {
            UnitList targetList;
            SelectTargetList(targetList, 5, SELECT_TARGET_RANDOM, 100.0f, true);
            for (Unit* targets : targetList)
            {
                me->CastSpell(targets, SPELL_STONE_SPIKE_MISSILE, true);
            }
            events.Repeat(15s, 20s);
            break;
        }
        case SPELL_STONE_BREAKERS_COMBO:
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
            {
                me->CastSpell(target, SPELL_CRYSTALIZE_CHANNEL, false);
                target->GetScheduler().Schedule(5100ms, [this, target](TaskContext /*context*/)
                    {
                        if (!target)
                            return;

                        me->CastSpell(target, SPELL_CRYSTALLINE_BURST_DAMAGE, true);
                        std::list<Player*> playerList;
                        target->GetPlayerListInGrid(playerList, 8.0f);
                        for (Player* targets : playerList)
                        {
                            me->CastSpell(targets, SPELL_CRYSTALLINE_BURST_DAMAGE, true);
                        }

                        me->CastSpell(target, SPELL_PULVERIZING_METEOR_MISSILE, false);
                    });
            }
            events.Repeat(60s);
            break;

        case SPELL_SERRATED_SWIPE:
            DoCastVictim(SPELL_SERRATED_SWIPE, false);
            events.Repeat(20s);
            break;

        case SPELL_HEART_REND:
        {
            me->CastSpell(nullptr, SPELL_HEART_REND, false);
            UnitList targetList;
            SelectTargetList(targetList, 4, SELECT_TARGET_RANDOM, 100.0f, true);
            for (Unit* targets : targetList)
            {
                me->AddAura(SPELL_HEART_REND, targets);
            }
            events.Repeat(25s);
            break;
        }

        case SPELL_WICKED_BLADE:
            me->CastSpell(nullptr, SPELL_WICKED_BLADE, false);
            events.Repeat(30s);
            break;

        case EVENT_STONEFORM_ADDS:
            me->SummonCreature(NPC_STONE_LEGION_GOLIATH_TWO, me->GetRandomNearPosition(25.0f), TEMPSUMMON_MANUAL_DESPAWN);
            for (uint8 i = 0; i < 3; i++)
            {
                me->SummonCreature(NPC_STONE_LEGION_COMMANDO, me->GetRandomNearPosition(25.0f), TEMPSUMMON_MANUAL_DESPAWN);
            }
            break;

        case SPELL_RICOCHETING_SHURIKEN:
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                me->CastSpell(target, SPELL_RICOCHETING_SHURIKEN, false);
            events.Repeat(15s);
            break;

        case SPELL_STONE_FIST:
            DoCastVictim(SPELL_STONE_FIST, false);
            events.Repeat(20s);
            break;

        case SPELL_SEISMIC_UPHEAVAL_MISSILE:
            me->GetScheduler().Schedule(1s, [this](TaskContext context)
            {
                if (!me)
                    return;

                std::list<Player*> playerList;
                me->GetPlayerListInGrid(playerList, 100.0f);
                for (Player* targets : playerList)
                {
                    seismicUpheaval++;
                    me->CastSpell(targets, SPELL_SEISMIC_UPHEAVAL_MISSILE, true);
                }

                if (this->seismicUpheaval != 5)
                    context.Repeat(1s);

                if (this->seismicUpheaval == 5)
                    this->seismicUpheaval = 0;
            });
            events.Repeat(30s);
            break;

        case SPELL_REVERBERATING_ERUPTION_MARK:
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
            {
                me->CastSpell(target->GetPosition(), SPELL_REVERBERATING_ERUPTION_MARK, false);
                me->GetScheduler().Schedule(5100ms, [this, target](TaskContext /*context*/)
                {
                    if (!target)
                        return;

                    me->CastSpell(target->GetPosition(), SPELL_REVERBERATING_ERUPTION_DAMAGE_SUMMON, false);
                    if (Creature* reverberationStalker = me->FindNearestCreature(NPC_REVERBERATING_ERUPTION_STALKER, 150.0f, true))
                    {
                        reverberationStalker->RemoveAllAuras();
                        me->CastSpell(reverberationStalker->GetPosition(), SPELL_ECHOING_ANNIHILATION, true);
                    }
                });
            }
            events.Repeat(35s);
            break;
        }
    }

    void SpellHitTarget(Unit* target, SpellInfo const* spellInfo) override
    {
        if (me->GetEntry() != NPC_GENERAL_GRASHAAL)
            return;

        switch (spellInfo->Id)
        {
        case SPELL_ECHOING_ANNIHILATION:
        case SPELL_REVERBERATING_ERUPTION_DAMAGE_SUMMON:
            me->AddAura(SPELL_REVERBERATING_VULNERABILITY, target);
            break;
        }
    }

    void SummonedCreatureDies(Creature* summon, Unit* /*killer*/)
    {
        switch (summon->GetEntry())
        {
        case NPC_STONE_LEGION_COMMANDO:
            summon->CastSpell(nullptr, SPELL_ANIMA_ORB_CREATE_AT, true);
            break;
        }
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        if (me->HealthBelowPct(50) && !hardenedStoneFormKaal && me->GetEntry() == NPC_GENERAL_KAAL)
        {
            hardenedStoneFormKaal = true;
            me->CastSpell(nullptr, SPELL_HARDENED_STONEFORM, false);
            events.ScheduleEvent(EVENT_STONEFORM_ADDS, 3s);
        }
        if (me->HealthBelowPct(50) && !hardenedStoneForGrashaal && me->GetEntry() == NPC_GENERAL_GRASHAAL)
        {
            hardenedStoneForGrashaal = true;
            me->CastSpell(nullptr, SPELL_HARDENED_STONEFORM, false);
            events.ScheduleEvent(EVENT_STONEFORM_ADDS, 3s);
        }
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
        case ACTION_PHASE_TWO:
            switch (me->GetEntry())
            {
            case NPC_GENERAL_KAAL:
                events.Reset();
                events.ScheduleEvent(SPELL_WICKED_BLADE, 5s);
                events.ScheduleEvent(SPELL_RICOCHETING_SHURIKEN, 10s);
                break;

            case NPC_GENERAL_GRASHAAL:
                events.Reset();
                events.ScheduleEvent(SPELL_STONE_BREAKERS_COMBO, 5s);
                events.ScheduleEvent(SPELL_STONE_FIST, 10s);
                events.ScheduleEvent(SPELL_SEISMIC_UPHEAVAL_MISSILE, 15s);
                events.ScheduleEvent(SPELL_REVERBERATING_ERUPTION_MARK, 20s);
                break;
            }
            break;

        case ACTION_PHASE_THREE:
            switch (me->GetEntry())
            {
            case NPC_GENERAL_GRASHAAL:
                events.Reset();                
                events.ScheduleEvent(SPELL_STONE_SPIKE_MISSILE, 5s);
                events.ScheduleEvent(SPELL_STONE_FIST, 10s);
                events.ScheduleEvent(SPELL_STONE_BREAKERS_COMBO, 30s);
                break;

            case NPC_GENERAL_KAAL:
                events.Reset();
                events.ScheduleEvent(SPELL_SERRATED_SWIPE, 5s);
                events.ScheduleEvent(SPELL_HEART_REND, 10s);
                events.ScheduleEvent(SPELL_WICKED_BLADE, 15s);
                break;
            }
            break;
        }
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        switch (me->GetEntry())
        {
        case NPC_GENERAL_GRASHAAL:
        case NPC_GENERAL_KAAL:
            me->RemoveAllAreaTriggers();
            me->NearTeleportTo(me->GetHomePosition());
            _JustReachedHome();
            _DespawnAtEvade();
            break;
        }
    }

    void JustDied(Unit* /*victim*/) override
    {
        switch (me->GetEntry())
        {
        case NPC_GENERAL_GRASHAAL:
        case NPC_GENERAL_KAAL:
            _JustDied();
            break;
        }

        if (Creature* generalGrashaal = me->FindNearestCreature(NPC_GENERAL_GRASHAAL, 150.0f, true))
            generalGrashaal->AddAura(SPELL_SOLDIERS_OATH);

        if (Creature* generalKaal = me->FindNearestCreature(NPC_GENERAL_KAAL, 150.0f, true))
            generalKaal->AddAura(SPELL_SOLDIERS_OATH);
    }
};

//332393
struct at_anima_orb : public AreaTriggerAI
{
    at_anima_orb(AreaTrigger* at) : AreaTriggerAI(at) { }

private:
    bool giveEnergy;

    void OnCreate() override
    {
        giveEnergy = false;
    }

    void OnUnitEnter(Unit* target) override
    {
        if (!target->IsPlayer() || giveEnergy)
            return;

        if (Creature* renathal = at->FindNearestCreature(NPC_PRINCE_RENATHAL_END, 100.f, true))
        {
            giveEnergy = true;
            renathal->ModifyPower(POWER_MANA, + 40);
        }
    }
};

//172652
struct npc_prince_renathal_stone_legion : public ScriptedAI
{
    npc_prince_renathal_stone_legion(Creature* c) : ScriptedAI(c) { }

private:
    bool shatteringBlastKaal;
    bool shatteringBlastGrashaal;

    void Reset() override
    {
        ScriptedAI::Reset();
        me->SetPowerType(POWER_MANA);
        me->SetMaxPower(POWER_MANA, 100);
        me->SetPower(POWER_MANA, 0);
        shatteringBlastKaal = false;
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
        case 1:
            if (Creature* generalKall = me->FindNearestCreature(NPC_GENERAL_KAAL, 180.0f, true))
            {
                me->CastSpell(generalKall, SPELL_SHATTERING_BLAST, false);
                generalKall->GetScheduler().Schedule(5100ms, [this, generalKall](TaskContext /*context*/)
                {
                    if (!generalKall)
                        return;

                    generalKall->RemoveAura(SPELL_HARDENED_STONEFORM);
                    generalKall->AI()->DoAction(ACTION_PHASE_TWO);
                });
            }
            break;

        case 2:
            if (Creature* generalGrashaal = me->FindNearestCreature(NPC_GENERAL_GRASHAAL, 180.0f, true))
            {
                me->CastSpell(generalGrashaal, SPELL_SHATTERING_BLAST, false);
                generalGrashaal->GetScheduler().Schedule(5100ms, [this, generalGrashaal](TaskContext /*context*/)
                {
                    if (!generalGrashaal)
                        return;

                   generalGrashaal->RemoveAura(SPELL_HARDENED_STONEFORM);
                   generalGrashaal->AI()->DoAction(ACTION_PHASE_THREE);
               });
            }
            break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (instance->GetBossState(DATA_STONE_LEGION_GENERALS) != IN_PROGRESS)
            return;

        if (Creature* generalKaal = me->FindNearestCreature(NPC_GENERAL_KAAL, 180.0f, true))
            if (!generalKaal->HasAura(SPELL_HARDENED_STONEFORM))
                return;

        if (Creature* generalGrashaal = me->FindNearestCreature(NPC_GENERAL_GRASHAAL, 180.0f, true))
            if (!generalGrashaal->HasAura(SPELL_HARDENED_STONEFORM))
                return;

        if (Creature* generalKaal = me->FindNearestCreature(NPC_GENERAL_KAAL, 180.0f, true))
            if (me->GetPower(POWER_MANA) >= 100 && !shatteringBlastKaal && generalKaal->HasAura(SPELL_HARDENED_STONEFORM))
            {
                me->SetPower(POWER_MANA, 0);
                shatteringBlastKaal = true;
                me->AI()->DoAction(1);
            }

        if (Creature* generalGrashaal = me->FindNearestCreature(NPC_GENERAL_GRASHAAL, 180.0f, true))
            if (me->GetPower(POWER_MANA) >= 100 && !shatteringBlastGrashaal && generalGrashaal->HasAura(SPELL_HARDENED_STONEFORM))
            {
                me->SetPower(POWER_MANA, 0);
                shatteringBlastGrashaal = true;
                me->AI()->DoAction(2);
            }
    }
};

//175102
struct npc_reverberation_stalker : public ScriptedAI
{
    npc_reverberation_stalker(Creature* c) : ScriptedAI(c) { }

    void Reset() override
    {
        ScriptedAI::Reset();
        me->AddAura(SPELL_UNSTABLE_GROUND_APPLY_AT);
    }
};

void AddSC_boss_stone_legion_generals()
{
    RegisterCreatureAI(boss_stone_legion_generals);
    RegisterAreaTriggerAI(at_anima_orb);
    RegisterCreatureAI(npc_prince_renathal_stone_legion);
    RegisterCreatureAI(npc_reverberation_stalker);
}