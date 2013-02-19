/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

/* ScriptData
SDName: Boss_Shazzrah
SD%Complete: 75
SDComment: Teleport NYI
SDCategory: Molten Core
EndScriptData */

#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "molten_core.h"

enum Spells
{
    SPELL_ARCANE_EXPLOSION  = 19712,
    SPELL_SHAZZRAH_CURSE    = 19713,
    SPELL_MAGIC_GROUNDING   = 19714,
    SPELL_COUNTERSPELL      = 19715,
};

enum Events
{
    EVENT_ARCANE_EXPLOSION  = 1,
    EVENT_SHAZZRAH_CURSE    = 2,
    EVENT_MAGIC_GROUNDING   = 3,
    EVENT_COUNTERSPELL      = 4,
    EVENT_BLINK             = 5,
};

class boss_shazzrah : public CreatureScript
{
    public:
        boss_shazzrah() : CreatureScript("boss_shazzrah") { }

        struct boss_shazzrahAI : public BossAI
        {
            boss_shazzrahAI(Creature* creature) : BossAI(creature, BOSS_SHAZZRAH)
            {
            }

            void EnterCombat(Unit* target)
            {
                BossAI::EnterCombat(target);
                events.ScheduleEvent(EVENT_ARCANE_EXPLOSION, 6000);
                events.ScheduleEvent(EVENT_SHAZZRAH_CURSE, 10000);
                events.ScheduleEvent(EVENT_MAGIC_GROUNDING, 24000);
                events.ScheduleEvent(EVENT_COUNTERSPELL, 15000);
                events.ScheduleEvent(EVENT_BLINK, 30000);
            }

            void UpdateAI(const uint32 diff)
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
                        case EVENT_ARCANE_EXPLOSION:
                            DoCastVictim(SPELL_ARCANE_EXPLOSION);
                            events.ScheduleEvent(EVENT_ARCANE_EXPLOSION, urand(5000, 9000));
                            break;
                        case EVENT_SHAZZRAH_CURSE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true, -EVENT_SHAZZRAH_CURSE))
                                DoCast(target, SPELL_SHAZZRAH_CURSE);
                            events.ScheduleEvent(EVENT_SHAZZRAH_CURSE, urand(25000, 30000));
                            break;
                        case EVENT_MAGIC_GROUNDING:
                            DoCast(me, SPELL_MAGIC_GROUNDING);
                            events.ScheduleEvent(EVENT_MAGIC_GROUNDING, 35000);
                            break;
                        case EVENT_COUNTERSPELL:
                            DoCastVictim(SPELL_COUNTERSPELL);
                            events.ScheduleEvent(EVENT_COUNTERSPELL, urand(16000, 20000));
                            break;
                        case EVENT_BLINK:
                            // Teleporting him to a random player and casting Arcane Explosion after that.
                            // Blink is not working cause of LoS System we need to do this hardcoded.
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 100.0f, true))
                            {
                                DoTeleportTo(target->GetPositionX(), target->GetPositionY(), target->GetPositionZ());
                                DoCast(target, SPELL_ARCANE_EXPLOSION);
                                DoResetThreat();
                            }
                            events.ScheduleEvent(EVENT_BLINK, 45000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_shazzrahAI(creature);
        }
};

void AddSC_boss_shazzrah()
{
    new boss_shazzrah();
}
