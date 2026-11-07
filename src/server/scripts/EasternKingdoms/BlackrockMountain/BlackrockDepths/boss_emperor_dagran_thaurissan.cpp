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
#include "blackrock_depths.h"
#include "InstanceScript.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"

enum Yells
{
    SAY_AGGRO                                              = 0,
    SAY_SLAY                                               = 1
};

enum Spells
{
    SPELL_HANDOFTHAURISSAN                                 = 17492,
    SPELL_AVATAROFFLAME                                    = 15636
};

enum Events
{
    EVENT_HANDOFTHAURISSAN                                 = 1,
    EVENT_AVATAROFFLAME                                    = 2
};

enum Emotes
{
    EMOTE_SHAKEN                                           = 0
};

class boss_emperor_dagran_thaurissan : public CreatureScript
{
    public:
        boss_emperor_dagran_thaurissan() : CreatureScript("boss_emperor_dagran_thaurissan") { }

        struct boss_draganthaurissanAI : public BossAI
        {
            boss_draganthaurissanAI(Creature* creature) : BossAI(creature, BOSS_EMPEROR_DAGRAN_THAURISSAN)
            {
            }

            void JustEngagedWith(Unit* who) override
            {
                _JustEngagedWith(who);
                Talk(SAY_AGGRO);
                me->CallForHelp(VISIBLE_RANGE);
                events.ScheduleEvent(EVENT_HANDOFTHAURISSAN, 4s);
                events.ScheduleEvent(EVENT_AVATAROFFLAME, 25s);
            }

            void KilledUnit(Unit* who) override
            {
                if (who->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_SLAY);
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();
                if (Creature* moira = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_MOIRA)))
                {
                    moira->AI()->EnterEvadeMode();
                    moira->SetFaction(FACTION_FRIENDLY);
                    moira->AI()->Talk(EMOTE_SHAKEN);
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_HANDOFTHAURISSAN:
                            if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                                DoCast(target, SPELL_HANDOFTHAURISSAN);
                            events.ScheduleEvent(EVENT_HANDOFTHAURISSAN, 5s);
                            break;
                        case EVENT_AVATAROFFLAME:
                            DoCastVictim(SPELL_AVATAROFFLAME);
                            events.ScheduleEvent(EVENT_AVATAROFFLAME, 18s);
                            break;
                        default:
                            break;
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetBlackrockDepthsAI<boss_draganthaurissanAI>(creature);
        }
};

void AddSC_boss_draganthaurissan()
{
    new boss_emperor_dagran_thaurissan();
}
