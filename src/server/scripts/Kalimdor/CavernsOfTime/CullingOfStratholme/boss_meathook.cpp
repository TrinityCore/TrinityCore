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
    SPELL_CONSTRICTING_CHAINS                   = 52696, //Encases the targets in chains, dealing 1800 Physical damage every 1 sec. and stunning the target for 5 sec.
    SPELL_DISEASE_EXPULSION                     = 52666, //Meathook belches out a cloud of disease, dealing 1710 to 1890 Nature damage and interrupting the spell casting of nearby enemy targets for 4 sec.
    SPELL_FRENZY                                = 58841 //Increases the caster's Physical damage by 10% for 30 sec.
};

enum Yells
{
    SAY_AGGRO                                   = 0,
    SAY_SLAY                                    = 1,
    SAY_SPAWN                                   = 2,
    SAY_DEATH                                   = 3
};

enum Events
{
    EVENT_CHAIN                                 = 1,
    EVENT_DISEASE,
    EVENT_FRENZY
};

class boss_meathook : public CreatureScript
{
    public:
        boss_meathook() : CreatureScript("boss_meathook") { }

        struct boss_meathookAI : public BossAI
        {
            boss_meathookAI(Creature* creature) : BossAI(creature, DATA_MEATHOOK)
            {
                Talk(SAY_SPAWN);
            }

            void JustEngagedWith(Unit* /*who*/) override
            {
                Talk(SAY_AGGRO);
                _JustEngagedWith();
                events.ScheduleEvent(EVENT_CHAIN, 12s, 17s);
                events.ScheduleEvent(EVENT_DISEASE, 2s, 4s);
                events.ScheduleEvent(EVENT_FRENZY, 21s, 26s);
            }

            void ExecuteEvent(uint32 eventId) override
            {
                switch (eventId)
                {
                    case EVENT_CHAIN:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                            DoCast(target, SPELL_CONSTRICTING_CHAINS);
                        events.ScheduleEvent(EVENT_CHAIN, 2s, 4s);
                        break;
                    case EVENT_DISEASE:
                        DoCastAOE(SPELL_DISEASE_EXPULSION);
                        events.ScheduleEvent(EVENT_DISEASE, 1500ms, 4s);
                        break;
                    case EVENT_FRENZY:
                        DoCast(me, SPELL_FRENZY);
                        events.ScheduleEvent(EVENT_FRENZY, 21s, 26s);
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
            return GetCullingOfStratholmeAI<boss_meathookAI>(creature);
        }
};

void AddSC_boss_meathook()
{
    new boss_meathook();
}
