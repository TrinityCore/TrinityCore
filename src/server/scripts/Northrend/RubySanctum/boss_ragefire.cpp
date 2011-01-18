/* Copyright (C) 2010 Easy for TrinityCore <http://trinity-core.ru/>
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#include "ScriptPCH.h"
#include "ruby_sanctum.h"

enum eScriptTexts
{
    SAY_AGGRO           = -1752022,
    SAY_SLAY1           = -1752023,
    SAY_SLAY2           = -1752024,
    SAY_DEATH           = -1752025
};

enum eSpells
{
    SPELL_CONFLAGRATION     = 74456,
    SPELL_ENRAGE            = 78722,
    SPELL_FLAME_BREATH_10   = 74403,
    SPELL_FLAME_BREATH_25   = 74404,
    SPELL_FLAME_BEACON      = 74453
};

enum eEvents
{
    EVENT_CAST_CONFLAGRATION      = 1,
    EVENT_CAST_ENRAGE             = 2,
    EVENT_CAST_FLAME_BREATH       = 3,
    EVENT_CAST_FLAME_BEACON       = 4,
    EVENT_CAST_CONFLAGRATION_FLY  = 5,
    EVENT_CAST_CONFLAGRATION_CAST = 6
};

#define TARGETS_10 2
#define TARGETS_25 5

class boss_ragefire : public CreatureScript
{
    public:
        boss_ragefire() : CreatureScript("boss_ragefire") { }

        struct boss_ragefireAI : public BossAI
        {
            boss_ragefireAI(Creature *pCreature) : BossAI(pCreature, DATA_RAGEFIRE)
            {
                ASSERT(instance);
                me->SetUnitMovementFlags(MOVEMENTFLAG_CAN_FLY);
            }

            void Reset()
            {
                instance->SetBossState(DATA_RAGEFIRE, NOT_STARTED);
                playerList.clear();
                bConflagration = false;
                events.Reset();
                events.ScheduleEvent(EVENT_CAST_CONFLAGRATION, urand(45000,55000));
                events.ScheduleEvent(EVENT_CAST_ENRAGE, urand(25000,35000));
                events.ScheduleEvent(EVENT_CAST_FLAME_BREATH, urand(10000,15000));
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim() || !CheckInRoom())
                    return;

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                events.Update(diff);

                if (!bConflagration)
                {
                    while (uint32 eventId = events.ExecuteEvent())
                    {
                        switch (eventId)
                        {
                            case EVENT_CAST_CONFLAGRATION:
                                bConflagration = true;
                                events.ScheduleEvent(EVENT_CAST_CONFLAGRATION_FLY, 1000);
                                break;
                            case EVENT_CAST_ENRAGE:
                                DoCast(SPELL_ENRAGE);
                                events.ScheduleEvent(EVENT_CAST_ENRAGE, urand(25000,35000));
                                break;
                            case EVENT_CAST_FLAME_BREATH:
                                DoCast(RAID_MODE(SPELL_FLAME_BREATH_10,SPELL_FLAME_BREATH_25,SPELL_FLAME_BREATH_10,SPELL_FLAME_BREATH_25));
                                events.ScheduleEvent(EVENT_CAST_FLAME_BREATH, urand(10000,15000));
                                break;
                        }
                    }
                }
                else
                {
                    while (uint32 eventId = events.ExecuteEvent())
                    {
                        switch (eventId)
                        {
                            case EVENT_CAST_CONFLAGRATION_FLY:
                                me->GetMotionMaster()->MovePoint(1, (float)3159.04, (float)676.08, (float)103.05);
                                SelectTargetList(playerList, RAID_MODE(TARGETS_10,TARGETS_25,TARGETS_10,TARGETS_25), SELECT_TARGET_RANDOM, 0, true);
                                for (std::list<Unit*>::const_iterator itr = playerList.begin(); itr != playerList.end(); ++itr)
                                {
                                    Unit *pTemp = (*itr);
                                    me->CastSpell(pTemp, SPELL_FLAME_BEACON, true);
                                }
                                events.ScheduleEvent(EVENT_CAST_CONFLAGRATION_CAST, 5000);
                                break;
                            case EVENT_CAST_CONFLAGRATION_CAST:
                                for (std::list<Unit*>::const_iterator itr = playerList.begin(); itr != playerList.end(); ++itr)
                                {
                                    Unit *pTemp = (*itr);
                                    me->CastSpell(pTemp, SPELL_CONFLAGRATION, true);
                                }
                                playerList.clear();
                                me->GetMotionMaster()->MoveTargetedHome();
                                bConflagration = false;
                                events.ScheduleEvent(EVENT_CAST_CONFLAGRATION, urand(45000,55000));
                                break;
                        }
                    }
                }

                DoMeleeAttackIfReady();
            }

            void EnterCombat(Unit*)
            {
                instance->SetBossState(DATA_RAGEFIRE, IN_PROGRESS);
                DoScriptText(SAY_AGGRO, me);
            }

            void KilledUnit(Unit* /*victim*/)
            {
                DoScriptText(RAND(SAY_SLAY1,SAY_SLAY2), me);
            }

            void JustDied(Unit*)
            {
                _JustDied();
                DoScriptText(SAY_DEATH, me);
                instance->SetBossState(DATA_RAGEFIRE, DONE);
            }

        private:
            bool bConflagration;
            std::list<Unit *> playerList;

        };

        CreatureAI* GetAI(Creature *pCreature) const
        {
            return new boss_ragefireAI(pCreature);
        }

};


void AddSC_boss_ragefire()
{
    new boss_ragefire;
}
