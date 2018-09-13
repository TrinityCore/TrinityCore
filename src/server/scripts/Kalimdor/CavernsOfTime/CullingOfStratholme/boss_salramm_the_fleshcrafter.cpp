/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
#include "culling_of_stratholme.h"

enum Spells
{
    SPELL_CURSE_OF_TWISTED_FLESH                = 58845,
    SPELL_EXPLODE_GHOUL                         = 52480,
    SPELL_SHADOW_BOLT                           = 57725,
    SPELL_STEAL_FLESH                           = 52708,
    SPELL_SUMMON_GHOULS                         = 52451
};

enum Yells
{
    SAY_AGGRO                                   = 0,
    SAY_SPAWN                                   = 1,
    SAY_SLAY                                    = 2,
    SAY_DEATH                                   = 3,
    SAY_EXPLODE_GHOUL                           = 4,
    SAY_STEAL_FLESH                             = 5,
    SAY_SUMMON_GHOULS                           = 6
};

enum Events
{
    EVENT_CURSE_FLESH                           = 1,
    EVENT_EXPLODE_GHOUL,
    EVENT_SHADOW_BOLT,
    EVENT_STEAL_FLESH,
    EVENT_SUMMON_GHOULS
};

class boss_salramm : public CreatureScript
{
    public:
        boss_salramm() : CreatureScript("boss_salramm") { }

        struct boss_salrammAI : public BossAI
        {
            boss_salrammAI(Creature* creature) : BossAI(creature, DATA_SALRAMM)
            {
                Talk(SAY_SPAWN);
            }

            void JustEngagedWith(Unit* /*who*/) override
            {
                Talk(SAY_AGGRO);
                _JustEngagedWith();

                events.ScheduleEvent(EVENT_CURSE_FLESH, 30s);
                events.ScheduleEvent(EVENT_SUMMON_GHOULS, 19s, 24s);
                events.ScheduleEvent(EVENT_SHADOW_BOLT, 8s, 12s);
                events.ScheduleEvent(EVENT_STEAL_FLESH, 12345); /// @todo: adjust timer
            }

            void ExecuteEvent(uint32 eventId) override
            {
                switch (eventId)
                {
                    case EVENT_CURSE_FLESH:
                        DoCastVictim(SPELL_CURSE_OF_TWISTED_FLESH);
                        events.ScheduleEvent(EVENT_CURSE_FLESH, 35s);
                        break;
                    case EVENT_SUMMON_GHOULS:
                        Talk(SAY_SUMMON_GHOULS);
                        DoCast(me, SPELL_SUMMON_GHOULS);
                        events.ScheduleEvent(EVENT_SUMMON_GHOULS, 10s);
                        events.ScheduleEvent(EVENT_EXPLODE_GHOUL, 6s);
                        break;
                    case EVENT_SHADOW_BOLT:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 40.0f, true))
                            DoCast(target, SPELL_SHADOW_BOLT);
                        events.ScheduleEvent(EVENT_SHADOW_BOLT, 8s, 12s);
                        break;
                    case EVENT_STEAL_FLESH:
                        Talk(SAY_STEAL_FLESH);
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 50.0f, true))
                            DoCast(target, SPELL_STEAL_FLESH);
                        events.ScheduleEvent(EVENT_STEAL_FLESH, 12345);
                        break;
                    case EVENT_EXPLODE_GHOUL:
                        Talk(SAY_EXPLODE_GHOUL);
                        DoCast(me, SPELL_EXPLODE_GHOUL, true);
                        break;
                    default:
                        break;
                }
            }

            void JustDied(Unit* /*killer*/) override
            {
                Talk(SAY_DEATH);
                _JustDied();
            }

            void KilledUnit(Unit* victim) override
            {
                if (victim->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_SLAY);
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetCullingOfStratholmeAI<boss_salrammAI>(creature);
        }
};

void AddSC_boss_salramm()
{
    new boss_salramm();
}
