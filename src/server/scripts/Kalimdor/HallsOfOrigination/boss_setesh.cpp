/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#include "halls_of_origination.h"
#include "Map.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "SpellInfo.h"

enum Spells
{
    SPELL_CHAOS_BOLT                    = 77069,
    SPELL_CHAOS_BLAST                   = 76674, // Forcecast player to summon npc that Setesh fires missle at.
    SPELL_SEED_OF_CHAOS                 = 76888,
    SPELL_REIGN_OF_CHAOS                = 77023,
    SPELL_CHANNEL_CHAOS_PORTAL          = 76784,

    // Chaos Blast
    SPELL_CHAOS_BLAST_ME                = 76737, // Tells Setesh to launch missle at it.
    SPELL_CHAOS_BLAST_MISSLE            = 76676,
    SPELL_CHAOS_BLAST_AURA              = 76681,

    // Seed of Chaos
    SPELL_SEED_OF_CHAOS_DUMMY           = 76865,
    SPELL_SEED_OF_CHAOS_EXPLOSION       = 76870,

    // Void Rift
    SPELL_VOID_RIFT                     = 73699,

    // Chaos Portal
    SPELL_DUMMY_AURA                    = 94562, // Using random dummy aura without effect - for Setesh to target the correct portal.
    SPELL_NIGHTMARE_PORTAL_VISUAL       = 76714,
    SPELL_SUMMON_VOID_SENTINEL          = 77242, // summons 41208
    SPELL_SUMMON_VOID_SEEKER            = 77271, // summons 41148
    SPELL_SUMMON_VOID_WYRM_1            = 77272, // summons 41212
    SPELL_SUMMON_VOID_WYRM_2            = 79439, // summons 41212

    // Add Stalker
    SPELL_CHANNEL_SUMMON_ADDS           = 77607
};

enum Events
{
    // Ammunae
    EVENT_CHAOS_PORTAL = 1,
    EVENT_CONTINUE_FIGHT,
    EVENT_CHAOS_BLAST,
    EVENT_SEED_OF_CHAOS,
    EVENT_REIGN_OF_CHAOS,    

    // Chaos Portal
    EVENT_CAST_VISUAL,
    EVENT_SUMMON_WAVE_1,
    EVENT_SUMMON_WAVE_2,
    EVENT_SUMMON_WAVE_3,
    EVENT_SUMMON_WAVE_RANDOM
};

enum Actions
{
    ACTION_SETESH_ATTACK
};
enum Faction
{
    FACTION_ENEMY_14        = 14,
    FACTION_ENEMY_16        = 16
};

enum Phases
{
    PHASE_FIGHT             = 1,
    PHASE_CHAOS_PORTAL      = 2
};

enum Points
{
    POINT_CHANNEL_CHAOS_PORTAL,
    POINT_GROUND
};

enum Texts
{
    SAY_DEATH               = 0,
    SAY_AGGRO               = 1,
    SAY_SPECIAL             = 2,
    SAY_PLAYER_KILL         = 3
};

class NPCEntryPred
{
public:
    NPCEntryPred(uint32 entry) : _entry(entry) { }

    bool operator()(Unit* unit) const { return unit->GetEntry() == _entry; }

private:
    uint32 _entry;
};

// 39732 Setesh <Construct of Destruction>
class boss_setesh : public CreatureScript
{
    public:
        boss_setesh() : CreatureScript("boss_setesh") { }

        struct boss_seteshAI : public BossAI
        {
            boss_seteshAI(Creature* creature) : BossAI(creature, DATA_SETESH) { }

            void JustEngagedWith(Unit* who) override
            {
                BossAI::JustEngagedWith(who);
                Talk(SAY_AGGRO);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
                
                events.ScheduleEvent(EVENT_CHAOS_PORTAL, Seconds(5));
                events.ScheduleEvent(EVENT_CHAOS_BLAST, Seconds(15));
                events.ScheduleEvent(EVENT_SEED_OF_CHAOS, Seconds(20));
                events.ScheduleEvent(EVENT_REIGN_OF_CHAOS, Seconds(30));
            }

            void KilledUnit(Unit* victim) override
            {
                if (victim->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_PLAYER_KILL);
            }

            void EnterEvadeMode(EvadeReason /*why*/) override
            {
                _EnterEvadeMode();
                me->SetReactState(REACT_AGGRESSIVE);
                CleanUp();
            }

            void JustDied(Unit* /*who*/) override
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                _JustDied();
                Talk(SAY_DEATH);
            }

            void JustSummoned(Creature* summon) override
            {
                BossAI::JustSummoned(summon);

                switch (summon->GetEntry())
                {
                    case NPC_SETESH_VOID_RIFT:
                        summon->CastSpell((Unit*)nullptr, SPELL_VOID_RIFT, true);
                        break;
                    default:
                        break;
                }
            }

            void MovementInform(uint32 type, uint32 pointId) override
            {
                if (type != POINT_MOTION_TYPE && type != EFFECT_MOTION_TYPE)
                    return;

                switch (pointId)
                {
                    case POINT_CHANNEL_CHAOS_PORTAL:
                        if (Unit* npcChaosPortal = SelectTarget(SELECT_TARGET_MINDISTANCE, 0, 0.0f, false, true, SPELL_DUMMY_AURA))
                            DoCast(npcChaosPortal, SPELL_CHANNEL_CHAOS_PORTAL);
                        events.ScheduleEvent(EVENT_CONTINUE_FIGHT, Seconds(5));
                        break;
                    default:
                        break;
                }

                
            }

            void DoAction(int32 action) override
            {
                if (action != ACTION_SETESH_ATTACK)
                    return;

                // Start attacking
                me->SetReactState(REACT_AGGRESSIVE);
                events.SetPhase(PHASE_FIGHT);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim() || !CheckInRoom())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING) || events.IsInPhase(PHASE_CHAOS_PORTAL))
                    return;

                while(uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_CHAOS_PORTAL:
                            StartChaosPortalPhase();
                            events.Repeat(Seconds(45));
                            break;
                        case EVENT_CHAOS_BLAST:
                            DoCast(SPELL_CHAOS_BLAST);
                            events.Repeat(Seconds(20));
                            break;
                        case EVENT_SEED_OF_CHAOS:
                            DoCast(SPELL_SEED_OF_CHAOS);
                            events.Repeat(Seconds(40));
                            break;
                        default:
                            break;
                    }

                    if (me->HasUnitState(UNIT_STATE_CASTING))
                        return;
                }

                // Journal: Setesh casts Chaos Bolt at random players instead of performing a melee attack.
                if (events.IsInPhase(PHASE_CHAOS_PORTAL) || !me->isAttackReady())
                    return;

                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 40.0f, true))
                {
                    me->SetTarget(target->GetGUID());
                    DoCast(target, SPELL_CHAOS_BOLT);
                    me->resetAttackTimer();
                }
            }

        private:
            void StartChaosPortalPhase()
            {
                Unit* npcChaosPortal = SelectTarget(SELECT_TARGET_MAXDISTANCE, 0, NPCEntryPred(NPC_SETESH_CHAOS_PORTAL));
                if (!npcChaosPortal)
                    return;

                events.SetPhase(PHASE_CHAOS_PORTAL);

                me->SetReactState(REACT_PASSIVE);
                me->InterruptNonMeleeSpells(true);
                me->AttackStop();

                Talk(SAY_SPECIAL);

                // Walk towards chaos portal.
                npcChaosPortal->CastSpell((Unit*)nullptr, SPELL_DUMMY_AURA, true);
                me->GetMotionMaster()->MoveCloserAndStop(POINT_CHANNEL_CHAOS_PORTAL, npcChaosPortal, 18.0f);
            }

            void CleanUp()
            {
                std::list<Creature*> units;
                GetCreatureListWithEntryInGrid(units, me, NPC_SETESH_CHAOS_BLAST, 200.0f);
                for (std::list<Creature*>::iterator itr = units.begin(); itr != units.end(); ++itr)
                    (*itr)->DespawnOrUnsummon();

                units.clear();
                GetCreatureListWithEntryInGrid(units, me, NPC_SETESH_CHAOS_SEED, 200.0f);
                for (std::list<Creature*>::iterator itr = units.begin(); itr != units.end(); ++itr)
                    (*itr)->DespawnOrUnsummon();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_seteshAI(creature);
        }
};

// 41041 Chaos Blast
class npc_setesh_chaos_blast : public CreatureScript
{
public:
    npc_setesh_chaos_blast() : CreatureScript("npc_setesh_chaos_blast") { }

    struct npc_setesh_chaos_blastAI : public ScriptedAI
    {
        npc_setesh_chaos_blastAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            if (InstanceScript* instance = me->GetInstanceScript())
                if (Creature* setesh = instance->GetCreature(DATA_SETESH))
                    setesh->CastSpell(me, SPELL_CHAOS_BLAST_MISSLE, true);
        }

        void SpellHit(Unit* /*caster*/, const SpellInfo* spellInfo) override
        {
            if (spellInfo->Id != SPELL_CHAOS_BLAST_MISSLE)
                return;

            DoCastSelf(SPELL_CHAOS_BLAST_AURA);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetHallsOfOriginationAI<npc_setesh_chaos_blastAI>(creature);
    }
};

// 41126 Chaos Seed
class npc_setesh_chaos_seed : public CreatureScript
{
public:
    npc_setesh_chaos_seed() : CreatureScript("npc_setesh_chaos_seed") { }

    struct npc_setesh_chaos_seedAI : public ScriptedAI
    {
        npc_setesh_chaos_seedAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetDisableGravity(true);
            me->SetFloatValue(UNIT_FIELD_BOUNDINGRADIUS, 7.0f);
            me->SetFloatValue(UNIT_FIELD_COMBATREACH, 7.0f);
            me->SetFaction(FACTION_FRIENDLY);

            DoCastSelf(SPELL_SEED_OF_CHAOS_DUMMY);
        }

        void Reset() override
        {
            // Simulate slow fall
            float x = me->GetPositionX();
            float y = me->GetPositionY();
            float z = me->GetPositionZ();
            Position dest = { x, y, me->GetMap()->GetWaterOrGroundLevel(me->GetPhaseShift(), x, y, z) };
            const uint32 pathSize = 1;
            const Position path[pathSize] = { dest };
            me->GetMotionMaster()->MoveSmoothPath(POINT_GROUND, path, pathSize, true, true);
        }

        void MovementInform(uint32 type, uint32 pointId) override
        {
            if (type != FLIGHT_MOTION_TYPE || pointId != POINT_GROUND)
                return;

            me->SetDisableGravity(false);
            me->SetFaction(FACTION_ENEMY_14);
        }

        void JustEngagedWith(Unit* /*who*/) override
        {
            DoCast(SPELL_SEED_OF_CHAOS_EXPLOSION);

            me->RemoveAurasDueToSpell(SPELL_SEED_OF_CHAOS_DUMMY);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            me->DespawnOrUnsummon(Seconds(15));
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetHallsOfOriginationAI<npc_setesh_chaos_seedAI>(creature);
    }
};

// 41055 Chaos Portal - add waves:
//  - Normal: 1) 2x Void Wyrm  2) Void Seeker  3) Void Sentinel
//  - Heroic: 1) Void Sentinel 2) 2x Void Wyrm 3) Void Seeker   4+) Void Seeker or 2x Void Wyrm
class npc_setesh_chaos_portal : public CreatureScript
{
public:
    npc_setesh_chaos_portal() : CreatureScript("npc_setesh_chaos_portal") { }

    struct npc_setesh_chaos_portalAI : public ScriptedAI
    {
        npc_setesh_chaos_portalAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            events.Reset();
            me->SetFaction(FACTION_ENEMY_14);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        }

        void SpellHit(Unit* caster, const SpellInfo* spellInfo) override
        {
            if (spellInfo->Id != SPELL_CHANNEL_CHAOS_PORTAL)
                return;

            caster->InterruptNonMeleeSpells(true, SPELL_CHANNEL_CHAOS_PORTAL);
            me->RemoveAurasDueToSpell(SPELL_DUMMY_AURA);
            events.ScheduleEvent(EVENT_CAST_VISUAL, Seconds(1));
        }

        void JustDied(Unit* /*who*/) override
        {
            events.Reset();
            me->SetRespawnTime(0);
        }

        void UpdateAI(uint32 diff) override
        {
            if (events.Empty())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_CAST_VISUAL:
                        DoCast(SPELL_NIGHTMARE_PORTAL_VISUAL);
                        if (IsHeroic())
                            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        events.ScheduleEvent(EVENT_SUMMON_WAVE_1, Seconds(4));
                        break;
                    case EVENT_SUMMON_WAVE_1: // Also make Setesh attack.
                        if (InstanceScript* instance = me->GetInstanceScript())
                            if (Creature* setesh = instance->GetCreature(DATA_SETESH))
                                setesh->GetAI()->DoAction(ACTION_SETESH_ATTACK);
                         if (!IsHeroic()) // Normal
                            SummonVoidWyrms();
                        else // Heroic
                            SummonVoidSentinel();
                        events.ScheduleEvent(EVENT_SUMMON_WAVE_2, !IsHeroic() ? Seconds(12) : Seconds(6));
                        break;
                    case EVENT_SUMMON_WAVE_2:
                        if (!IsHeroic()) // Normal
                            SummonVoidSeeker();
                        else // Heroic
                            SummonVoidWyrms();
                        events.ScheduleEvent(EVENT_SUMMON_WAVE_3, !IsHeroic() ? Seconds(15) : Seconds(10));
                        break;
                    case EVENT_SUMMON_WAVE_3:
                        if (!IsHeroic()) // Normal
                            SummonVoidSentinel();
                        else // Heroic
                            SummonVoidSeeker();
                        // Normal: automatically closes after 3 waves of adds.
                        // Heroic: must be destroyed, summons more adds every 15 seconds after 3 waves.
                        if (!IsHeroic())
                            me->DespawnOrUnsummon(Seconds(5), Seconds(1));
                        else
                            events.ScheduleEvent(EVENT_SUMMON_WAVE_RANDOM, Seconds(15));
                        break;
                    case EVENT_SUMMON_WAVE_RANDOM: // Heroic only.
                        if (urand(0,1)) // 50% chance
                            SummonVoidSeeker();
                        else
                            SummonVoidWyrms();
                        events.Repeat(Seconds(15));
                        break;
                    default:
                        break;
                }
            }
        }

    private:
        void SummonAreaDamage()
        {
            if (Unit* npcSeteshAddStalker = SelectTarget(SELECT_TARGET_RANDOM, 200.0f, NPCEntryPred(NPC_SETESH_ADD_STALKER)))
                npcSeteshAddStalker->CastSpell(me, SPELL_CHANNEL_SUMMON_ADDS);
        }

        // Adds
        void SummonVoidWyrms() { SummonAreaDamage(); DoCast(SPELL_SUMMON_VOID_WYRM_1); DoCast(SPELL_SUMMON_VOID_WYRM_2); }
        void SummonVoidSeeker() { SummonAreaDamage(); DoCast(SPELL_SUMMON_VOID_SEEKER); }
        void SummonVoidSentinel() { SummonAreaDamage(); DoCast(SPELL_SUMMON_VOID_SENTINEL); }

        EventMap events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetHallsOfOriginationAI<npc_setesh_chaos_portalAI>(creature);
    }
};

// 76674 Chaos Blast
class spell_setesh_chaos_blast : public SpellScriptLoader
{
public:
    spell_setesh_chaos_blast() : SpellScriptLoader("spell_setesh_chaos_blast") { }

    class spell_setesh_chaos_blast_SpellScript : public SpellScript
    {
        void FilterTargets(std::list<WorldObject*>& unitList)
        {
            if (unitList.empty())
                return;

            Unit* caster = GetCaster();
            unitList.remove_if([caster](WorldObject* player) { return caster->IsWithinDist(player, 15.0f); });
            Trinity::Containers::RandomResize(unitList, 1);
        }

        void Register() override
        {
            OnObjectAreaTargetSelect.Register(&spell_setesh_chaos_blast_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_setesh_chaos_blast_SpellScript();
    }
};

void AddSC_boss_setesh()
{
    new boss_setesh();
    new npc_setesh_chaos_blast();
    new npc_setesh_chaos_seed();
    new npc_setesh_chaos_portal();
    new spell_setesh_chaos_blast();
}
