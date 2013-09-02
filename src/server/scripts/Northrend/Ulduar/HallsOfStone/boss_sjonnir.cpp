/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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
#include "ScriptedCreature.h"
#include "halls_of_stone.h"

enum Spells
{
    SPELL_LIGHTING_RING                               = 51849, // Periodic Trigger (interval 2s) spell = 50841
    H_SPELL_LIGHTING_RING                             = 59861, // Periodic Trigger (interval 2s) spell = 59849
    SPELL_LIGHTING_RING_1                             = 50840, // Periodic Trigger (interval 2s) spell = 50841
    H_SPELL_LIGHTING_RING_1                           = 59848, // Periodic Trigger (interval 2s) spell = 59849
    SPELL_STATIC_CHARGE                               = 50834, // Periodic Trigger 2s interval, spell =50835
    H_SPELL_STATIC_CHARGE                             = 59846, // Periodic Trigger 2s interval, spell =50847
    SPELL_CHAIN_LIGHTING                              = 50830,
    H_SPELL_CHAIN_LIGHTING                            = 59844,
    SPELL_LIGHTING_SHIELD                             = 50831,
    H_SPELL_LIGHTING_SHIELD                           = 59845,
    SPELL_FRENZY                                      = 28747
};

enum Yells
{
    SAY_AGGRO                                         = 0,
    SAY_SLAY                                          = 1,
    SAY_DEATH                                         = 2
};

#define EMOTE_GENERIC_FRENZY                          -1000002

enum SjonnirCreatures
{
    NPC_FORGED_IRON_TROGG                             = 27979,
    NPC_MALFORMED_OOZE                                = 27981,
    NPC_FORGED_IRON_DWARF                             = 27982,
    NPC_IRON_SLUDGE                                   = 28165,
    NPC_EARTHEN_DWARF                                 = 27980
};

enum Misc
{
    ACTION_OOZE_DEAD                                  = 1,
    DATA_ABUSE_THE_OOZE                               = 2
};

enum Events
{
    EVENT_CHAIN_LIGHTNING                             = 1,
    EVENT_LIGHTNING_SHIELD,
    EVENT_STATIC_CHARGE,
    EVENT_LIGHTNING_RING,
    EVENT_SUMMON,
    EVENT_FRENZY,
};

Position const PipeLocations[] =
{
    { 1295.44f, 734.07f, 200.3f, 0.0f }, // left
    { 1297.7f,  595.6f,  199.9f, 0.0f }  // right
};

Position const CenterPoint = { 1295.21f, 667.157f, 189.691f, 0.0f };

class boss_sjonnir : public CreatureScript
{
    public:
        boss_sjonnir() : CreatureScript("boss_sjonnir") { }

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return new boss_sjonnirAI(creature);
        }

        struct boss_sjonnirAI : public BossAI
        {
            boss_sjonnirAI(Creature* creature) : BossAI(creature, DATA_SJONNIR) { }

            void Reset() OVERRIDE
            {
                _Reset();
                bIsFrenzy = false;
                abuseTheOoze = 0;
            }

            void EnterCombat(Unit* /*who*/) OVERRIDE
            {
                Talk(SAY_AGGRO);
                _EnterCombat();

                if (GameObject* pDoor = instance->instance->GetGameObject(instance->GetData64(DATA_SJONNIR_DOOR)))
                {
                    if (pDoor->GetGoState() == GO_STATE_READY)
                    {
                        EnterEvadeMode();
                        return;
                    }
                }

                events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, urand(3000, 8000));
                events.ScheduleEvent(EVENT_LIGHTNING_SHIELD, urand(20000, 25000));
                events.ScheduleEvent(EVENT_STATIC_CHARGE, urand(20000, 25000));
                events.ScheduleEvent(EVENT_LIGHTNING_RING, urand(30000, 35000));
                events.ScheduleEvent(EVENT_SUMMON, 5000);
                events.ScheduleEvent(EVENT_FRENZY, 300000);
            }

            void UpdateAI(uint32 diff) OVERRIDE
            {
                // Return since we have no target
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                uint32 uiSummonPipe = rand()%2;
                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_CHAIN_LIGHTNING:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                                DoCast(target, SPELL_CHAIN_LIGHTING);
                            events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, urand(10000, 15000));
                            break;
                        case EVENT_LIGHTNING_SHIELD:
                            DoCast(me, SPELL_LIGHTING_SHIELD);
                            break;
                        case EVENT_STATIC_CHARGE:
                            DoCastVictim(SPELL_STATIC_CHARGE);
                            events.ScheduleEvent(EVENT_STATIC_CHARGE, urand(20000, 25000));
                            break;
                        case EVENT_LIGHTNING_RING:
                            if (me->IsNonMeleeSpellCasted(false))
                                me->InterruptNonMeleeSpells(false);
                            DoCast(me, SPELL_LIGHTING_RING);
                            events.ScheduleEvent(EVENT_LIGHTNING_RING, urand(30000, 35000));
                            break;
                        case EVENT_SUMMON:
                            if (HealthAbovePct(75))
                            {
                                me->SummonCreature(NPC_FORGED_IRON_DWARF, PipeLocations[uiSummonPipe], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 30000);
                            }
                            else if (HealthAbovePct(50) && HealthBelowPct(75))
                            {
                                me->SummonCreature(NPC_FORGED_IRON_TROGG, PipeLocations[uiSummonPipe], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 30000);
                            }
                            else if (HealthAbovePct(25) && HealthBelowPct(50))
                            {
                                me->SummonCreature(NPC_MALFORMED_OOZE, PipeLocations[uiSummonPipe], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 30000);
                            }
                            else
                            {
                                me->SummonCreature(NPC_EARTHEN_DWARF, PipeLocations[uiSummonPipe], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 30000);
                            }
                            events.ScheduleEvent(EVENT_SUMMON, 20000);
                            return;
                        case EVENT_FRENZY:
                            if (!bIsFrenzy)
                            {
                                DoCast(me, SPELL_FRENZY);
                                bIsFrenzy = true;
                            }
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

            void JustSummoned(Creature* summon) OVERRIDE
            {
                summon->GetMotionMaster()->MovePoint(0, CenterPoint);
                /*if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    summon->AI()->AttackStart(target);*/
                summons.Summon(summon);
            }

            void JustDied(Unit* /*killer*/) OVERRIDE
            {
                Talk(SAY_DEATH);
                _JustDied();
            }

            void KilledUnit(Unit* victim) OVERRIDE
            {
                if (victim->GetTypeId() != TYPEID_PLAYER)
                    return;

                Talk(SAY_SLAY);
            }

            void DoAction(int32 action) OVERRIDE
            {
                if (action == ACTION_OOZE_DEAD)
                    ++abuseTheOoze;
            }

            uint32 GetData(uint32 type) const OVERRIDE
            {
                if (type == DATA_ABUSE_THE_OOZE)
                    return abuseTheOoze;

                return 0;
            }

            private:
                bool bIsFrenzy;
                uint8 abuseTheOoze;
        };
};

class npc_malformed_ooze : public CreatureScript
{
    public:
        npc_malformed_ooze() : CreatureScript("npc_malformed_ooze") { }

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return new npc_malformed_oozeAI(creature);
        }

        struct npc_malformed_oozeAI : public ScriptedAI
        {
            npc_malformed_oozeAI(Creature* creature) : ScriptedAI(creature) {}

            uint32 uiMergeTimer;

            void Reset() OVERRIDE
            {
                uiMergeTimer = 10000;
            }

            void UpdateAI(uint32 diff) OVERRIDE
            {
                if (uiMergeTimer <= diff)
                {
                    if (Creature* temp = me->FindNearestCreature(NPC_MALFORMED_OOZE, 3.0f, true))
                    {
                        DoSpawnCreature(NPC_IRON_SLUDGE, 0, 0, 0, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 20000);
                        temp->DisappearAndDie();
                        me->DisappearAndDie();
                    }
                    uiMergeTimer = 3000;
                } else uiMergeTimer -= diff;

                if (!UpdateVictim())
                    return;

                DoMeleeAttackIfReady();
            }
        };
};

class npc_iron_sludge : public CreatureScript
{
    public:
        npc_iron_sludge() : CreatureScript("npc_iron_sludge") { }

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return new npc_iron_sludgeAI(creature);
        }

        struct npc_iron_sludgeAI : public ScriptedAI
        {
            npc_iron_sludgeAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = creature->GetInstanceScript();
            }

            InstanceScript* instance;

            void JustDied(Unit* /*killer*/) OVERRIDE
            {
                if (instance)
                    if (Creature* Sjonnir = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_SJONNIR)))
                        Sjonnir->AI()->DoAction(ACTION_OOZE_DEAD);
            }
        };
};

class achievement_abuse_the_ooze : public AchievementCriteriaScript
{
    public:
        achievement_abuse_the_ooze() : AchievementCriteriaScript("achievement_abuse_the_ooze")
        {
        }

        bool OnCheck(Player* /*player*/, Unit* target) OVERRIDE
        {
            if (!target)
                return false;

            if (Creature* Sjonnir = target->ToCreature())
                if (Sjonnir->AI()->GetData(DATA_ABUSE_THE_OOZE) >= 5)
                    return true;

            return false;
        }
};

void AddSC_boss_sjonnir()
{
    new boss_sjonnir();
    new npc_malformed_ooze();
    new npc_iron_sludge();
    new achievement_abuse_the_ooze();
}
