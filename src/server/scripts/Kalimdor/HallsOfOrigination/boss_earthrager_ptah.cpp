/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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
 
#include "ScriptPCH.h"
#include "WorldPacket.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"

#define SAY_AGGRO "More carrion for the swarm..."
#define SAY_DIED "Ptah... is... no more..."
#define SAY_SPELL "Dust to dust."

enum CreatureIds
{
    BOSS_EARTHRAGER_PTAH        = 39428,
    MOB_HORROR                  = 40810,
    MOB_SCARAB                  = 40458,
};

enum Spells
{
    SPELL_FLAME_BOLT = 77370,
    SPELL_RAGING_SMASH = 83650,
    SPELL_EARTH_POINT = 75339,
    SPELL_DUST_MOVE = 75547,
    SPELL_VORTEX_DUST = 93570,
};

enum Events
{
    EVENT_FLAME_BOLT,
    EVENT_RAGING_SMASH,
    EVENT_EARTH_POINT,
    EVENT_SUMMON,
    EVENT_DUST_MOVE,
    EVENT_VORTEX_DUST,
};

enum SummonIds
{
    NPC_HORROR   = 40810,
    NPC_SCARAB   = 40458,
};

const Position aSpawnLocations[3] =
{
    {-530.561584f, -370.613525f, 156.935913f, 5.081081f},
    {-484.478302f, -371.117584f, 155.954208f, 4.429200f},
    {-507.319977f, -381.939392f, 154.764664f, 4.700163f},
};

class boss_ptah : public CreatureScript
{
    public:
        boss_ptah() : CreatureScript("boss_ptah") {}

        struct boss_ptahAI : public ScriptedAI
        {
            boss_ptahAI(Creature* creature) : ScriptedAI(creature), Summons(me)
            {
                instance = creature->GetInstanceScript();
            }

            InstanceScript* instance;
            EventMap events;
            SummonList Summons;

            void EnterCombat(Unit * /*who*/)
            {
                EnterPhaseGround();
                me->MonsterYell(SAY_AGGRO, 0, 0);
            }

            void JustDied(Unit* /*killer*/)
            {
                me->MonsterYell(SAY_DIED, 0, 0);
            }

            void JustSummoned(Creature *summoned)
            {
                summoned->SetInCombatWithZone();
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    summoned->AI()->AttackStart(target);
                Summons.Summon(summoned);
            }

            void SummonedCreatureDespawn(Creature* summon)
            {
                Summons.Despawn(summon);
            }

            void EnterPhaseGround()
            {
                events.ScheduleEvent(EVENT_FLAME_BOLT, 7500);
                events.ScheduleEvent(EVENT_RAGING_SMASH, urand(4000, 10000));
                events.ScheduleEvent(EVENT_EARTH_POINT, 8000);
                events.ScheduleEvent(EVENT_SUMMON, 50000);
                events.ScheduleEvent(EVENT_DUST_MOVE, 15000);
                events.ScheduleEvent(EVENT_VORTEX_DUST, urand(14000, 20000));
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                    case EVENT_FLAME_BOLT:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, true))
                            DoCast(target, SPELL_FLAME_BOLT);
                        events.ScheduleEvent(EVENT_FLAME_BOLT, 7500);
                        return;
                    case EVENT_RAGING_SMASH:
                        DoCast(me->getVictim(), SPELL_RAGING_SMASH);
                        events.ScheduleEvent(EVENT_RAGING_SMASH, urand(4000, 10000));
                        return;
                    case EVENT_EARTH_POINT:
                        me->MonsterYell(SAY_SPELL, LANG_UNIVERSAL, NULL);
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 100, true))
                            DoCast(target, SPELL_EARTH_POINT);
                        events.ScheduleEvent(EVENT_EARTH_POINT, 8000);
                        return;
                    case EVENT_SUMMON:
                        me->SummonCreature(NPC_HORROR, aSpawnLocations[0].GetPositionX(), aSpawnLocations[0].GetPositionY(), aSpawnLocations[0].GetPositionZ(), 0.0f, TEMPSUMMON_CORPSE_DESPAWN);
                        me->SummonCreature(NPC_SCARAB, aSpawnLocations[1].GetPositionX(), aSpawnLocations[1].GetPositionY(), aSpawnLocations[1].GetPositionZ(), 0.0f, TEMPSUMMON_CORPSE_DESPAWN);
                        events.ScheduleEvent(EVENT_SUMMON, 50000);
                        return;
                    case EVENT_DUST_MOVE:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, true))
                            DoCast(target, SPELL_DUST_MOVE);
                        events.ScheduleEvent(EVENT_DUST_MOVE, 15000);
                        return;
                    case EVENT_VORTEX_DUST:
                        if (IsHeroic())
                        {
                            DoCastAOE(SPELL_VORTEX_DUST);
                        }
                        events.ScheduleEvent(EVENT_VORTEX_DUST, urand(14000, 20000));
                        return;
                    }
                }
                DoMeleeAttackIfReady();
            }
        };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_ptahAI(creature);
    }
};

void AddSC_boss_ptah()
{
    new boss_ptah();
}