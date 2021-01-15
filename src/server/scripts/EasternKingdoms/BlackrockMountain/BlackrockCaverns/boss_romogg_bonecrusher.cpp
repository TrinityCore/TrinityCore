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

#include "ScriptMgr.h"
#include "blackrock_caverns.h"
#include "InstanceScript.h"
#include "ScriptedCreature.h"

enum Romogg
{
    YELL_AGGRO                      = 0,
    YELL_KILL                       = 1,
    YELL_SKULLCRACKER               = 2,
    YELL_DEATH                      = 3,
    EMOTE_CALL_FOR_HELP             = 4,
    EMOTE_SKULLCRACKER              = 5,
    SPELL_CALL_FOR_HELP             = 82137, // Needs Scripting
    SPELL_CHAINS_OF_WOE             = 75539,
    SPELL_QUAKE                     = 75272,
    SPELL_SKULLCRACKER              = 75543,
    SPELL_WOUNDING_STRIKE           = 75571,
    EVENT_CHAINS_OF_WOE             = 1,
    EVENT_QUAKE                     = 2,     // Not yet sure of timing
    EVENT_SKULLCRACKER              = 3,
    EVENT_WOUNDING_STRIKE           = 4,
    TYPE_RAZ                        = 1,
    DATA_ROMOGG_DEAD                = 1
};

Position const SummonPos = { 249.2639f, 949.1614f, 191.7866f, 3.141593f };

class boss_romogg_bonecrusher : public CreatureScript
{
    public:
        boss_romogg_bonecrusher() : CreatureScript("boss_romogg_bonecrusher") { }

        struct boss_romogg_bonecrusherAI : public BossAI
        {
            boss_romogg_bonecrusherAI(Creature* creature) : BossAI(creature, DATA_ROMOGG_BONECRUSHER)
            {
                me->SummonCreature(NPC_RAZ_THE_CRAZED, SummonPos, TEMPSUMMON_MANUAL_DESPAWN, 200000);
            }

            void Reset() override
            {
                _Reset();
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();
                Talk(YELL_DEATH);

                if (Creature* raz = instance->GetCreature(DATA_RAZ_THE_CRAZED))
                    raz->AI()->SetData(TYPE_RAZ, DATA_ROMOGG_DEAD);
            }

            void KilledUnit(Unit* who) override
            {
                if (who->GetTypeId() == TYPEID_PLAYER)
                    Talk(YELL_KILL);
            }

            void EnterCombat(Unit* /*who*/) override
            {
                _EnterCombat();
                events.ScheduleEvent(EVENT_CHAINS_OF_WOE, urand(22000, 32000));
                events.ScheduleEvent(EVENT_WOUNDING_STRIKE, urand(26000, 32000));
                events.ScheduleEvent(EVENT_QUAKE, 45000);
                Talk(YELL_AGGRO);
                Talk(EMOTE_CALL_FOR_HELP);
                DoCast(me, SPELL_CALL_FOR_HELP);
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
                        case EVENT_CHAINS_OF_WOE:
                            Talk(YELL_SKULLCRACKER);
                            DoCast(me, SPELL_CHAINS_OF_WOE);
                            events.ScheduleEvent(EVENT_CHAINS_OF_WOE, urand(22000, 32000));
                            events.ScheduleEvent(EVENT_SKULLCRACKER, 3000);
                            break;
                        case EVENT_SKULLCRACKER:
                            Talk(EMOTE_SKULLCRACKER);
                            DoCast(me, SPELL_SKULLCRACKER);
                            break;
                        case EVENT_QUAKE:
                            DoCast(me, SPELL_QUAKE);
                            events.ScheduleEvent(EVENT_QUAKE, urand(32000, 40000));
                            break;
                        case EVENT_WOUNDING_STRIKE:
                            DoCastVictim(SPELL_WOUNDING_STRIKE, true);
                            events.ScheduleEvent(EVENT_WOUNDING_STRIKE, urand(26000, 32000));
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetBlackrockCavernsAI<boss_romogg_bonecrusherAI>(creature);
        }
};

void AddSC_boss_romogg_bonecrusher()
{
    new boss_romogg_bonecrusher();
}
