/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

#include "culling_of_stratholme.h"
#include "InstanceScript.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"

enum Spells
{
    SPELL_CONSTRICTING_CHAINS = 52696,
    SPELL_DISEASE_EXPULSION = 52666,
    SPELL_FRENZY = 58841
};

enum Yells
{
    SAY_AGGRO = 0,
    SAY_SLAY = 1,
    SAY_SPAWN = 2,
    SAY_DEATH = 3
};

enum Events
{
    EVENT_CHAIN = 1,
    EVENT_DISEASE,
    EVENT_FRENZY
};

class boss_meathook : public CreatureScript
{
    public:
        boss_meathook() : CreatureScript("boss_meathook") { }

        struct boss_meathookAI : public BossAI
        {
            boss_meathookAI(Creature* creature) : BossAI(creature, DATA_MEATHOOK) { }

            void InitializeAI() override
            {
                Talk(SAY_SPAWN);
                if (instance->GetBossState(DATA_MEATHOOK) == DONE)
                    me->RemoveLootMode(LOOT_MODE_DEFAULT);
            }

            void JustEngagedWith(Unit* /*who*/) override
            {
                Talk(SAY_AGGRO);
                _JustEngagedWith();
                events.ScheduleEvent(EVENT_CHAIN, Seconds(7), Seconds(11));
                events.ScheduleEvent(EVENT_DISEASE, Seconds(2));
                events.ScheduleEvent(EVENT_FRENZY, Seconds(13), Seconds(17));
            }

            void ExecuteEvent(uint32 eventId) override
            {
                switch (eventId)
                {
                    case EVENT_CHAIN:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, -20.0f, true))
                            DoCast(target, SPELL_CONSTRICTING_CHAINS);
                        else if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 100.0f, true))
                            DoCast(target, SPELL_CONSTRICTING_CHAINS);
                        else
                            DoCastVictim(SPELL_CONSTRICTING_CHAINS);
                        events.Repeat(Seconds(10), Seconds(15));
                        break;
                    case EVENT_DISEASE:
                        DoCastAOE(SPELL_DISEASE_EXPULSION);
                        events.Repeat(Seconds(3)+Milliseconds(500));
                        break;
                    case EVENT_FRENZY:
                        DoCast(me, SPELL_FRENZY);
                        events.Repeat(Seconds(13), Seconds(17));
                        break;
                    default:
                        break;
                }
            }

            void JustDied(Unit* /*killer*/) override
            {
                Talk(SAY_DEATH);
                _JustDied();
                instance->SetData(DATA_NOTIFY_DEATH, 1);
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
