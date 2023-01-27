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
#include "freehold.h"

enum HarlanSweeteSpells
{
    ///Harlan Sweete
    CannonBarrage = 257305,
    CannonBarrageMissile = 257309,
    FlamingShrapnel = 257308,
    FieryDebris = 257460,
    SwiftwindSaber = 257454,
    SwiftwindSaberSummon = 257268,
    SwiftwindSaberDmg = 257293,
    LoadedDiceAllHands = 257402, ///Aplied at 60% of the health
    LoadedDiceManOWar = 257458, ///Aplied at 30% of the health
    ///Irontide Grenadiers
    BlackPowderBomb = 257315,
    BlackPowderBombAura = 257314
};

enum HarlanSweeteEvents
{
    EventCannonBarrage = 1,
    EventSwiftwindSaber,
    EventSummonIrontideGrenadier,
    EventCheckPlayer,
};

enum HarlanTalk
{
    TalkAggro = 0,
    Talk60Percent,
    TalkDead,
    TalkGranadier,
    TalkCannon,
    Talk30Percent,
};

Position const GranadierSummonPos = { -1583.55f, -558.43f, 74.0f, 5.37f };

///126983 - Harlan Sweete
struct boss_harlan_sweete : public BossAI
{
    boss_harlan_sweete(Creature* creature) : BossAI(creature, FreeholdData::DataHarlanSweete)
    {}

    void Reset() override
    {
        _Reset();
        sixtyPercent = false;
        thirtyPercent = false;
        instance->SetBossState(FreeholdData::DataHarlanSweete, NOT_STARTED);
    }

    void JustReachedHome() override
    {
        _JustReachedHome();
        instance->SetBossState(FreeholdData::DataHarlanSweete, FAIL);
    }

    void EnterCombat(Unit* /*who*/) override
    {
        _EnterCombat(true);
        Talk(HarlanTalk::TalkAggro);
        instance->SetBossState(FreeholdData::DataHarlanSweete, IN_PROGRESS);
        events.ScheduleEvent(HarlanSweeteEvents::EventCannonBarrage, 8000);
        events.ScheduleEvent(HarlanSweeteEvents::EventSwiftwindSaber, 12000);
        events.ScheduleEvent(HarlanSweeteEvents::EventSummonIrontideGrenadier, 15000);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(HarlanTalk::TalkDead);
        instance->SetBossState(FreeholdData::DataHarlanSweete, DONE);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        if (me->HealthWillBeBelowPctDamaged(60, damage) && !sixtyPercent)
        {
            sixtyPercent = true;
            Talk(HarlanTalk::Talk60Percent);
            me->CastSpell(me, HarlanSweeteSpells::LoadedDiceAllHands, true);
        }
        else if (me->HealthWillBeBelowPctDamaged(30, damage) && !thirtyPercent)
        {
            thirtyPercent = true;
            Talk(HarlanTalk::Talk30Percent);
            me->CastSpell(me, HarlanSweeteSpells::LoadedDiceManOWar, true);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case HarlanSweeteEvents::EventCannonBarrage:
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, NonTankTargetSelector(me)))
                {
                    Talk(HarlanTalk::TalkCannon);
                    me->CastSpell(target, HarlanSweeteSpells::CannonBarrage, false);

                    if (me->HasAura(HarlanSweeteSpells::LoadedDiceAllHands))
                    {
                        std::list<Player*> playerList;
                        me->GetPlayerListInGrid(playerList, 100.0f);

                        if (!playerList.empty())
                        {
                            playerList.remove_if([](Player* player) -> bool
                                {
                                    if (player->HasAura(HarlanSweeteSpells::CannonBarrage))
                                        return true;

                                    if (player->GetRoleForGroup() == Roles::ROLE_TANK)
                                        return true;

                                    return false;
                                });

                            if (Player* secondTarget = Trinity::Containers::SelectRandomContainerElement(playerList))
                                me->CastSpell(secondTarget, HarlanSweeteSpells::CannonBarrage, true);
                        }
                    }
                }
                if (!me->HasAura(HarlanSweeteSpells::LoadedDiceManOWar))
                    events.Repeat(12000);
                else
                    events.Repeat(8000);
                break;
            }
            case HarlanSweeteEvents::EventSwiftwindSaber:
            {
                me->CastSpell(me, HarlanSweeteSpells::SwiftwindSaber, false);

                if (!me->HasAura(HarlanSweeteSpells::LoadedDiceManOWar))
                    events.Repeat(12000);
                else
                    events.Repeat(8000);
                break;
            }
            case HarlanSweeteEvents::EventSummonIrontideGrenadier:
            {
                Talk(HarlanTalk::TalkGranadier);

                me->SummonCreature(FreeholdCreature::NpcIrontideGrenadier, GranadierSummonPos, TEMPSUMMON_MANUAL_DESPAWN);

                if (!me->HasAura(HarlanSweeteSpells::LoadedDiceManOWar))
                    events.Repeat(20000);
                else
                    events.Repeat(15000);
                break;
            }
            }
        }

        DoMeleeAttackIfReady();

    }

private:
    bool thirtyPercent;
    bool sixtyPercent;
};

/// 129758 - Npc Irontide Granadier
struct npc_irontide_granadier : public ScriptedAI
{
    npc_irontide_granadier(Creature* creature) : ScriptedAI(creature) { }

    void IsSummonedBy(Unit* summoner) override
    {
        me->SetReactState(REACT_PASSIVE);
        targetGUID.Clear();
        AddTimedDelayedOperation(800, [this]() -> void
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true))
                {
                    me->CastSpell(target, HarlanSweeteSpells::BlackPowderBombAura, true);
                    me->getThreatManager().resetAllAggro();
                    me->getThreatManager().addThreat(target, 1000000.0f);
                    me->GetMotionMaster()->MoveChase(target);
                    targetGUID = target->GetGUID();
                }

                events.ScheduleEvent(HarlanSweeteEvents::EventCheckPlayer, 500);
            });
    }

    void UpdateAI(uint32 diff) override
    {
        UpdateOperations(diff);
        events.Update(diff);

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case HarlanSweeteEvents::EventCheckPlayer:
            {
                if (!me->HasAura(HarlanSweeteSpells::BlackPowderBombAura))
                    me->CastSpell(me, HarlanSweeteSpells::BlackPowderBomb, false);

                if (Creature* target = ObjectAccessor::GetCreature(*me, targetGUID))
                {
                    if (me->GetDistance(target) <= 3.0f)
                        me->CastSpell(me, HarlanSweeteSpells::BlackPowderBomb, false);
                }
                events.Repeat(500);
                break;
            }
            }
        }
    }

private:
    ObjectGuid targetGUID;
};

/// 129747 -Npc Swiftwind Saber
struct npc_swiftwind_saber : public ScriptedAI
{
    npc_swiftwind_saber(Creature* creature) : ScriptedAI(creature) { }

    void IsSummonedBy(Unit* summoner) override
    {
        me->SetReactState(REACT_PASSIVE);
        float orientation = me->GetOrientation();

        AddTimedDelayedOperation(2 * TimeConstants::IN_MILLISECONDS, [this, orientation]() -> void
            {
                float x = 0, y = 0;
                GetPositionWithDistInOrientation(me, 100.0f, orientation, x, y);
                me->GetMotionMaster()->MoveCharge(x, y, me->GetPositionZ(), 24.0f);
            });
    }

    void UpdateAI(uint32 diff) override
    {
        UpdateOperations(diff);
    }
};

///257305 Cannon Barrage Aura
class spell_cannon_barrage_aura : public AuraScript
{
    PrepareAuraScript(spell_cannon_barrage_aura);

    void OnPeriodic(AuraEffect const* aurEff)
    {
        if (Unit* caster = GetCaster())
            if (Unit* target = GetTarget())
                caster->CastSpell(target, HarlanSweeteSpells::FlamingShrapnel, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_cannon_barrage_aura::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

///258850 Cannon Barrage
class spell_cannon_barrage_target : public SpellScript
{
    PrepareSpellScript(spell_cannon_barrage_target);

    void FilterTargets(std::list<WorldObject*>& unitList)
    {
        unitList.remove_if([](WorldObject* object) -> bool
            {
                if (!object->ToPlayer())
                    return true;

                return false;
            });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (Unit* caster = GetCaster())
        {
            if (Unit* target = GetHitUnit())
            {
                std::list<Creature*> cannonList;
                caster->GetCreatureListWithEntryInGrid(cannonList, FreeholdCreature::NpcIrontideCannon, 200.0f);
                if (!cannonList.empty())
                {
                    if (Creature* cannon = Trinity::Containers::SelectRandomContainerElement(cannonList))
                    {
                        cannon->CastSpell(target, HarlanSweeteSpells::CannonBarrageMissile, true);
                    }
                }
            }
        }
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_cannon_barrage_target::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
        OnEffectHitTarget += SpellEffectFn(spell_cannon_barrage_target::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

///257454 Swiftwind Saber
class spell_swiftwind_saber : public SpellScript
{
    PrepareSpellScript(spell_swiftwind_saber);

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (Unit* caster = GetCaster())
        {
            uint8 count = 3;
            caster->CastSpell(caster, HarlanSweeteSpells::SwiftwindSaberSummon, true);

            if (caster->HasAura(HarlanSweeteSpells::LoadedDiceAllHands))
                count = 6;

            for (uint8 i = 0; i < count; i++)
                caster->SummonCreature(FreeholdCreature::NpcSwiftwindSaber, caster->GetPositionX(), caster->GetPositionY(), caster->GetPositionZ(), caster->GetOrientation() - (float(M_PI) / 6.0f) * (i), TEMPSUMMON_TIMED_DESPAWN, 5000);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_swiftwind_saber::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

///Spell 257310  Cannon Barrage Areatrigger Areatriger ID 12018
struct at_cannon_barrage : AreaTriggerAI
{
    at_cannon_barrage(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit)
    {
        if (Unit* caster = at->GetCaster())
            if (Player* player = unit->ToPlayer())
                if (!player->HasAura(HarlanSweeteSpells::FieryDebris))
                    caster->CastSpell(player, HarlanSweeteSpells::FieryDebris, true);
    }

    void OnUnitExit(Unit* unit)
    {
        unit->RemoveAurasDueToSpell(HarlanSweeteSpells::FieryDebris);
    }
};

///Spell 257269  Swiftwind Saber Areatriger ID 12004
struct at_swiftwind_saber : AreaTriggerAI
{
    at_swiftwind_saber(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnInitialize() override
    {
        at->SetPeriodicProcTimer(1000);
    }

    void OnPeriodicProc() override
    {
        if (Unit* caster = at->GetCaster())
        {
            GuidUnorderedSet const& insideUnits = at->GetInsideUnits();

            for (ObjectGuid guid : insideUnits)
                if (Player* player = ObjectAccessor::GetPlayer(*caster, guid))
                    player->CastSpell(player, HarlanSweeteSpells::SwiftwindSaberDmg, true);
        }
    }
};


void AddSC_boss_harlan_sweete()
{
    ///Creature
    RegisterCreatureAI(boss_harlan_sweete);
    RegisterCreatureAI(npc_irontide_granadier);
    RegisterCreatureAI(npc_swiftwind_saber);
    ///Spell
    RegisterSpellScript(spell_cannon_barrage_target);
    RegisterSpellScript(spell_swiftwind_saber);
    ///Aura
    RegisterAuraScript(spell_cannon_barrage_aura);
    ///Areatrigger
    RegisterAreaTriggerAI(at_cannon_barrage);
    RegisterAreaTriggerAI(at_swiftwind_saber);
}