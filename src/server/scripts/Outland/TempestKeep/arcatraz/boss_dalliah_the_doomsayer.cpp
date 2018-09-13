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
#include "arcatraz.h"
#include "InstanceScript.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"

enum Say
{
    // Dalliah the Doomsayer
    SAY_AGGRO                       = 1,
    SAY_SLAY                        = 2,
    SAY_WHIRLWIND                   = 3,
    SAY_HEAL                        = 4,
    SAY_DEATH                       = 5,
    SAY_SOCCOTHRATES_DEATH          = 7,

    // Wrath-Scryer Soccothrates
    SAY_AGGRO_DALLIAH_FIRST         = 0,
    SAY_DALLIAH_25_PERCENT          = 5
};

enum Spells
{
    SPELL_GIFT_OF_THE_DOOMSAYER     = 36173,
    SPELL_WHIRLWIND                 = 36142,
    SPELL_HEAL                      = 36144,
    SPELL_SHADOW_WAVE               = 39016  // Heroic only
};

enum Events
{
    EVENT_GIFT_OF_THE_DOOMSAYER     = 1,
    EVENT_WHIRLWIND                 = 2,
    EVENT_HEAL                      = 3,
    EVENT_SHADOW_WAVE               = 4, // Heroic only
    EVENT_ME_FIRST                  = 5,
    EVENT_SOCCOTHRATES_DEATH        = 6
};

class boss_dalliah_the_doomsayer : public CreatureScript
{
    public:
        boss_dalliah_the_doomsayer() : CreatureScript("boss_dalliah_the_doomsayer") { }

        struct boss_dalliah_the_doomsayerAI : public BossAI
        {
            boss_dalliah_the_doomsayerAI(Creature* creature) : BossAI(creature, DATA_DALLIAH)
            {
                soccothratesTaunt = false;
                soccothratesDeath = false;
            }

            void Reset() override
            {
                _Reset();
                soccothratesTaunt = false;
                soccothratesDeath = false;
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();
                Talk(SAY_DEATH);

                if (Creature* soccothrates = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_SOCCOTHRATES)))
                    if (soccothrates->IsAlive() && !soccothrates->IsInCombat())
                        soccothrates->AI()->SetData(1, 1);
            }

            void JustEngagedWith(Unit* /*who*/) override
            {
                _JustEngagedWith();
                events.ScheduleEvent(EVENT_GIFT_OF_THE_DOOMSAYER, 1s, 4s);
                events.ScheduleEvent(EVENT_WHIRLWIND, 7s, 9s);
                if (IsHeroic())
                    events.ScheduleEvent(EVENT_SHADOW_WAVE, 11s, 16s);
                events.ScheduleEvent(EVENT_ME_FIRST, 6s);
                Talk(SAY_AGGRO);
            }

            void KilledUnit(Unit* /*victim*/) override
            {
                Talk(SAY_SLAY);
            }

            void SetData(uint32 /*type*/, uint32 data) override
            {
                switch (data)
                {
                    case 1:
                        events.ScheduleEvent(EVENT_SOCCOTHRATES_DEATH, 6s);
                        soccothratesDeath = true;
                        break;
                    default:
                        break;
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                {
                    if (soccothratesDeath)
                    {
                        events.Update(diff);

                        while (uint32 eventId = events.ExecuteEvent())
                        {
                            switch (eventId)
                            {
                                case EVENT_SOCCOTHRATES_DEATH:
                                    Talk(SAY_SOCCOTHRATES_DEATH);
                                    break;
                                default:
                                    break;
                            }
                        }
                    }

                    return;
                }

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_GIFT_OF_THE_DOOMSAYER:
                            DoCastVictim(SPELL_GIFT_OF_THE_DOOMSAYER, true);
                            events.ScheduleEvent(EVENT_GIFT_OF_THE_DOOMSAYER, 16s, 21s);
                            break;
                        case EVENT_WHIRLWIND:
                            DoCast(me, SPELL_WHIRLWIND);
                            Talk(SAY_WHIRLWIND);
                            events.ScheduleEvent(EVENT_WHIRLWIND, 19s, 21s);
                            events.ScheduleEvent(EVENT_HEAL, 6s);
                            break;
                        case EVENT_HEAL:
                            DoCast(me, SPELL_HEAL);
                            Talk(SAY_HEAL);
                            break;
                        case EVENT_SHADOW_WAVE:
                            DoCastVictim(SPELL_SHADOW_WAVE, true);
                            events.ScheduleEvent(EVENT_SHADOW_WAVE, 11s, 16s);
                            break;
                        case EVENT_ME_FIRST:
                            if (Creature* soccothrates = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_SOCCOTHRATES)))
                                if (soccothrates->IsAlive() && !soccothrates->IsInCombat())
                                    soccothrates->AI()->Talk(SAY_AGGRO_DALLIAH_FIRST);
                            break;
                        default:
                            break;
                    }

                    if (me->HasUnitState(UNIT_STATE_CASTING))
                        return;
                }

                if (HealthBelowPct(25) && !soccothratesTaunt)
                {
                    if (Creature* soccothrates = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_SOCCOTHRATES)))
                        soccothrates->AI()->Talk(SAY_DALLIAH_25_PERCENT);
                    soccothratesTaunt = true;
                }

                DoMeleeAttackIfReady();
            }

        private:
            bool soccothratesTaunt;
            bool soccothratesDeath;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetArcatrazAI<boss_dalliah_the_doomsayerAI>(creature);
        }
};

void AddSC_boss_dalliah_the_doomsayer()
{
    new boss_dalliah_the_doomsayer();
}
