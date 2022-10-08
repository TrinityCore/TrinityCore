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
    SPELL_DIMENSIONAL_TEAR_CAST = 328437,
    SPELL_DIMENSIONAL_TEAR_DEBUFF = 328448,
    SPELL_DIMENSIONAL_TEAR_EXP = 328545,
    SPELL_WORMHOLE_A_SUMMON = 328308, //168726
    SPELL_WORMHOLE_B_SUMMON = 328312, //168730
    SPELL_GLYPH_OF_DESTRUCTION = 325361,
    SPELL_GLYPH_OF_DESTRUCTION_PERIODIC = 325236,
    SPELL_GLYPH_OF_DESTRUCTION_EXP = 325324,
    SPELL_RIFT_BLAST_CAST = 335013,
    SPELL_RIFT_BLAST_DAMAGE = 329256, //169271
    SPELL_RIFT_BLAST_SUMMON = 329459,
    SPELL_HYPERLIGHT_SPARK = 325399,
    SPELL_CRYSTAL_OF_PHANTASM = 327887,
    SPELL_POSSESION = 327414,
    SPELL_SOUL_SINGE = 340824,
    //Phase 2
    SPELL_ROOT_OF_EXTINCTION_CAST = 329770,
    SPELL_ROOT_OF_EXTINCTION_VISUAL = 329243,
    SPELL_ROOT_OF_EXTINCTION_CREATE_AT = 329982, //1697 explode on create after 18s
    SPELL_SEED_OF_EXTINCTION_BUTTON = 329090,
    SPELL_SEED_OF_EXTINCTION_CAST = 329834,
    SPELL_SEED_OF_EXTINCTION_EXP = 329107,
    SPELL_WITHERING_TOUCH_MISSILE = 340854,
    SPELL_WITHERING_TOUCH_PERIODIC_DAMAGE = 340860,
    //Phase 3
    SPELL_EDGE_OF_ANNIHILATION_CAST = 328880,
    SPELL_EDGE_OF_ANNIHILATION_VISUAL = 258832,
    SPELL_EDGE_OF_ANNIHILATION_KNOCKBACK = 329613,
    EVENT_EDGE_OF_ANNIHILATION_DRAG = 1, // every 35s, 45s
    SPELL_AURA_OF_DREAD = 340870,
    //Heroic
    SPELL_STASIS_TRAP_CAST = 326271,
    SPELL_STASIS_TRAP_TRIGGER = 326272,
    SPELL_STASIS_TRAP_CREATE_AT = 326275, //20168
    SPELL_STASIS_TRAP_STUN = 326302,
    //Mythic
};

//166644
struct boss_artificer_xymox : public BossAI
{
    boss_artificer_xymox(Creature* creature) : BossAI(creature, DATA_ARTIFICER_XYMOX), summonList(me) { }

    bool stage_two;
    bool stage_three;
    SummonList summonList;

    void Reset() override
    {
        BossAI::Reset();
        me->SetPowerType(POWER_ENERGY);
        me->SetMaxPower(POWER_ENERGY, 100);
        me->SetPower(POWER_ENERGY, 0);
        me->SetReactState(REACT_AGGRESSIVE);
        me->SetObjectScale(2.0);
        stage_two = false;
        stage_three = false;
    }

    void EnterCombat(Unit* /*who*/) override
    {
        events.ScheduleEvent(SPELL_HYPERLIGHT_SPARK, 4800ms);
        events.ScheduleEvent(SPELL_DIMENSIONAL_TEAR_CAST, 13s);
        events.ScheduleEvent(SPELL_GLYPH_OF_DESTRUCTION, 8s);
        events.ScheduleEvent(SPELL_RIFT_BLAST_CAST, 19s);
        events.ScheduleEvent(SPELL_CRYSTAL_OF_PHANTASM, 25s);
        if (IsHeroic() || IsMythic())
            events.ScheduleEvent(SPELL_STASIS_TRAP_CAST, 10s);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        if (HealthBelowPct(70) && !stage_two)
        {
            stage_two = true;
            events.Reset();
            events.ScheduleEvent(SPELL_HYPERLIGHT_SPARK, 4800ms);
            events.ScheduleEvent(SPELL_DIMENSIONAL_TEAR_CAST, 13s);
            events.ScheduleEvent(SPELL_GLYPH_OF_DESTRUCTION, 8s);
            events.ScheduleEvent(SPELL_RIFT_BLAST_CAST, 19s);
            if (IsHeroic() || IsMythic())
            {
                events.ScheduleEvent(SPELL_STASIS_TRAP_CAST, 10s);
                events.ScheduleEvent(SPELL_CRYSTAL_OF_PHANTASM, 25s);
            }
            events.ScheduleEvent(SPELL_ROOT_OF_EXTINCTION_CAST, 3s);
            events.ScheduleEvent(SPELL_SEED_OF_EXTINCTION_CAST, 45s);
            events.ScheduleEvent(SPELL_WITHERING_TOUCH_MISSILE, 50s);
        }
        if (HealthBelowPct(40) && !stage_three)
        {
            stage_three = true;
            events.Reset();
            if (Creature* root = me->FindNearestCreature(NPC_ROOT_OF_EXTINCTION, 100.0F, true))
                if (!IsMythic())
                    root->DespawnOrUnsummon();

            events.ScheduleEvent(SPELL_HYPERLIGHT_SPARK, 4800ms);
            events.ScheduleEvent(SPELL_DIMENSIONAL_TEAR_CAST, 13s);
            events.ScheduleEvent(SPELL_GLYPH_OF_DESTRUCTION, 8s);
            events.ScheduleEvent(SPELL_RIFT_BLAST_CAST, 19s);
            if (IsHeroic() || IsMythic())
            {
                events.ScheduleEvent(SPELL_STASIS_TRAP_CAST, 10s);
                events.ScheduleEvent(SPELL_CRYSTAL_OF_PHANTASM, 25s);
            }

            events.ScheduleEvent(SPELL_EDGE_OF_ANNIHILATION_CAST, 3s);
        }
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case SPELL_HYPERLIGHT_SPARK:
        {
            std::list<Player*> playerList;
            me->GetPlayerListInGrid(playerList, 100.0f);
            for (Player* targets : playerList)
            {
                me->CastSpell(targets, SPELL_HYPERLIGHT_SPARK, false);
            }
            events.Repeat(14s, 18s);
            break;
        }

        case SPELL_DIMENSIONAL_TEAR_CAST:
            me->CastSpell(nullptr, SPELL_DIMENSIONAL_TEAR_CAST, false);
            events.Repeat(40s);
            break;

        /*case SPELL_GLYPH_OF_DESTRUCTION:
            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO, 0, 100.0f, true))
                me->CastSpell(target, SPELL_GLYPH_OF_DESTRUCTION, false);
            events.Repeat(30s);
            break;
            */
        case SPELL_RIFT_BLAST_CAST:
            me->CastSpell(nullptr, SPELL_RIFT_BLAST_CAST, false);
            events.Repeat(45s);
            break;

        case SPELL_CRYSTAL_OF_PHANTASM:
            me->CastSpell(nullptr, SPELL_CRYSTAL_OF_PHANTASM, false);
            events.Repeat(50s);
            break;

        case SPELL_ROOT_OF_EXTINCTION_CAST:
            me->CastSpell(nullptr, SPELL_ROOT_OF_EXTINCTION_CAST, false);
            break;

        case SPELL_SEED_OF_EXTINCTION_CAST:
            me->CastSpell(nullptr, SPELL_SEED_OF_EXTINCTION_CAST, false);
            events.Repeat(45s);
            break;

        case SPELL_WITHERING_TOUCH_MISSILE:
            DoCastRandom(SPELL_WITHERING_TOUCH_MISSILE, 100.0f, true);
            events.Repeat(21s);
            break;

        case SPELL_EDGE_OF_ANNIHILATION_CAST:
            me->CastSpell(nullptr, SPELL_EDGE_OF_ANNIHILATION_CAST, false);
            break;

        case SPELL_STASIS_TRAP_CAST:
            me->CastSpell(nullptr, SPELL_STASIS_TRAP_CAST, true);
            events.Repeat(28s);
            break;
        }
    }

    void OnSpellFinished(SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id)
        {
        case SPELL_DIMENSIONAL_TEAR_CAST:
        {
            UnitList targetList;
            SelectTargetList(targetList, 2, SELECT_TARGET_RANDOM, 100.0f, true);
            for (Unit* targets : targetList)
            {
                me->AddAura(SPELL_DIMENSIONAL_TEAR_DEBUFF, targets);
                targets->GetScheduler().Schedule(8100ms, [this, targets](TaskContext /*context*/)
                    {
                        if (!targets)
                            return;

                        me->CastSpell(targets, SPELL_DIMENSIONAL_TEAR_EXP, true);
                    });
            }
            break;
        }

        case SPELL_RIFT_BLAST_CAST:
        {
            UnitList targetList;
            SelectTargetList(targetList, 3, SELECT_TARGET_RANDOM, 100.0f, true);
            for (Unit* targets : targetList)
            {
                me->SummonCreature(NPC_RIFT_BLAST, targets->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN);
                std::list<Creature*> riftList;
                me->GetCreatureListWithEntryInGrid(riftList, NPC_RIFT_BLAST, 100.0f);
                for (Creature* rifts : riftList)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 30.0f, true))
                    {
                        rifts->SetFacingToObject(target);
                        rifts->CastSpell(target, SPELL_RIFT_BLAST_DAMAGE, false);
                    }
                }
            }
            break;
        }

        case SPELL_CRYSTAL_OF_PHANTASM:
            //fixate on random, on reach 327414, remove on 50% hp
            me->SummonCreature(NPC_FLEETING_SPIRIT, me->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN);
            break;

        case SPELL_ROOT_OF_EXTINCTION_CAST:
            me->SummonCreature(NPC_ROOT_OF_EXTINCTION, -1846.248f, 6402.999f, 4364.875f, TEMPSUMMON_MANUAL_DESPAWN);
            break;

        case SPELL_SEED_OF_EXTINCTION_CAST:
            if (!IsMythic())
            {
                for (uint8 i = 0; i < 4; i++)
                {
                    me->SummonCreature(NPC_SEED_OF_EXTINCTION, me->GetRandomNearPosition(30.0f), TEMPSUMMON_MANUAL_DESPAWN);
                }
            }
            else
            {
                for (uint8 i = 0; i < 8; i++)
                {
                    me->SummonCreature(NPC_SEED_OF_EXTINCTION, me->GetRandomNearPosition(30.0f), TEMPSUMMON_MANUAL_DESPAWN);
                }
            }
            break;

        case SPELL_EDGE_OF_ANNIHILATION_CAST:
            me->SummonCreature(NPC_EDGE_OF_ANNIHILATION, -1845.812f, 6402.990f, 4331.588f, TEMPSUMMON_MANUAL_DESPAWN);
            break;

        case SPELL_STASIS_TRAP_CAST:
        {
            UnitList targetList;
            SelectTargetList(targetList, 3, SELECT_TARGET_RANDOM, 100.0f, true);
            for (Unit* targets : targetList)
            {
                me->CastSpell(targets, SPELL_STASIS_TRAP_TRIGGER, true);
            }
            break;
        }

        /* case SPELL_GLYPH_OF_DESTRUCTION:
            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO, 0, 100.0f, true))
            {
                me->AddAura(SPELL_GLYPH_OF_DESTRUCTION_PERIODIC, target); */
                //target->GetScheduler().Schedule(4s, [this, target](TaskContext /*context*/);
                  //  {
                    //    if (!target)
                      //      return;

                        //me->CastSpell(target, SPELL_GLYPH_OF_DESTRUCTION_EXP, true);
                   // });
            //}
            //break;
        }
    }

    void JustSummoned(Creature* summon) override
    {
        summonList.Summon(summon);
        switch (summon->GetEntry())
        {
        case NPC_FLEETING_SPIRIT:
            summon->AI()->DoZoneInCombat();
            //if (Unit* target = SelectTarget(SELECT_TARGET_FARTHEST, 0, 100.0F, true))
              //  me->AddThreat(target, 100.0f);
            break;

        case NPC_RIFT_BLAST:
            break;

        case NPC_ROOT_OF_EXTINCTION:
            summon->SetReactState(REACT_PASSIVE);
            summon->CanFly();
            summon->SetFlying(true);
            summon->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
            break;

        case NPC_SEED_OF_EXTINCTION:
            summon->SetFaction(35);
            summon->AddNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
            summon->CastSpell(nullptr, SPELL_ROOT_OF_EXTINCTION_CREATE_AT);
            summon->GetScheduler().Schedule(18100ms, [this, summon](TaskContext /*context*/)
                {
                    if (!summon)
                        return;

                    summon->CastSpell(nullptr, SPELL_SEED_OF_EXTINCTION_EXP, true);
                    summon->DespawnOrUnsummon();
                });
            break;

        case NPC_EDGE_OF_ANNIHILATION:
            summon->AddUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_NPC | UNIT_STATE_UNATTACKABLE));
            summon->SetReactState(REACT_PASSIVE);
            summon->AddAura(SPELL_EDGE_OF_ANNIHILATION_VISUAL);
            std::list<Player*> playerList;
            summon->GetPlayerListInGrid(playerList, 100.0f);
            for (Player* targets : playerList)
            {
                summon->CastSpell(targets, SPELL_AURA_OF_DREAD, true);
            }
            break;
        }
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _JustReachedHome();
        me->NearTeleportTo(me->GetHomePosition());
        me->RemoveAllAreaTriggers();
        summons.DespawnAll();
        _DespawnAtEvade();
    }

    void JustDied(Unit*) override
    {
        _JustDied();
        me->RemoveAllAreaTriggers();
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_AURA_OF_DREAD);
        summons.DespawnAll();
    }
};

//169267
struct npc_root_of_extinction : public ScriptedAI
{
    npc_root_of_extinction(Creature* c) : ScriptedAI(c) { SetCombatMovement(false); }

    void Reset() override
    {
        me->CastSpell(nullptr, SPELL_ROOT_OF_EXTINCTION_VISUAL, true);
    }
};

//168317
struct npc_fleeting_spirit : public ScriptedAI
{
    npc_fleeting_spirit(Creature* c) : ScriptedAI(c) { }

    void MoveInLineOfSight(Unit* target) override
    {
        if (!target->IsPlayer() || target->GetDistance2d(me) <= 5.0f)
            return;

        me->AddAura(SPELL_POSSESION, target);
    }
};

//326275
struct at_stasis_trap : public AreaTriggerAI
{
    at_stasis_trap(AreaTrigger* at) : AreaTriggerAI(at) { }

    void OnUnitEnter(Unit* target) override
    {
        if (!target->IsPlayer())
            return;

        if (at->GetCaster())
            at->GetCaster()->AddAura(SPELL_STASIS_TRAP_STUN, target);
    }

    void OnUnitExit(Unit* target) override
    {
        if (!target->IsPlayer())
            return;

        if (target->HasAura(SPELL_STASIS_TRAP_STUN))
            target->RemoveAura(SPELL_STASIS_TRAP_STUN);
    }
};

void AddSC_boss_artificer_xymox()
{
    RegisterCreatureAI(boss_artificer_xymox);
    RegisterCreatureAI(npc_root_of_extinction);
    RegisterCreatureAI(npc_fleeting_spirit);
    RegisterAreaTriggerAI(at_stasis_trap);
}
