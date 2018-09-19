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
#include "scarlet_monastery.h"

enum Yells
{
    SAY_AGGRO               = 0,
    SAY_HEALTH              = 1,
    SAY_KILL                = 2
};

enum Spells
{
    SPELL_FLAMESHOCK        = 8053,
    SPELL_SHADOWBOLT        = 1106,
    SPELL_FLAMESPIKE        = 8814,
    SPELL_FIRENOVA          = 16079
};

enum Events
{
    EVENT_FLAME_SHOCK       = 1,
    EVENT_SHADOW_BOLT,
    EVENT_FLAME_SPIKE,
    EVENT_FIRE_NOVA
};

class boss_bloodmage_thalnos : public CreatureScript
{
    public:
        boss_bloodmage_thalnos() : CreatureScript("boss_bloodmage_thalnos") { }

        struct boss_bloodmage_thalnosAI : public BossAI
        {
            boss_bloodmage_thalnosAI(Creature* creature) : BossAI(creature, DATA_BLOODMAGE_THALNOS)
            {
                _hpYell = false;
            }

            void Reset() override
            {
                _hpYell = false;
                _Reset();
            }

            void JustEngagedWith(Unit* /*who*/) override
            {
                Talk(SAY_AGGRO);
                _JustEngagedWith();
                events.ScheduleEvent(EVENT_FLAME_SHOCK, 10s);
                events.ScheduleEvent(EVENT_SHADOW_BOLT, 2s);
                events.ScheduleEvent(EVENT_FLAME_SPIKE, 8s);
                events.ScheduleEvent(EVENT_FIRE_NOVA, 40s);
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();
            }

            void KilledUnit(Unit* /*victim*/) override
            {
                Talk(SAY_KILL);
            }

            void DamageTaken(Unit* /*attacker*/, uint32& damage) override
            {
                if (!_hpYell && me->HealthBelowPctDamaged(35, damage))
                {
                    Talk(SAY_HEALTH);
                    _hpYell = true;
                }
            }

            void ExecuteEvent(uint32 eventId) override
            {
                switch (eventId)
                {
                    case EVENT_FLAME_SHOCK:
                        DoCastVictim(SPELL_FLAMESHOCK);
                        events.ScheduleEvent(EVENT_FLAME_SHOCK, 10s, 15s);
                        break;
                    case EVENT_SHADOW_BOLT:
                        DoCastVictim(SPELL_SHADOWBOLT);
                        events.ScheduleEvent(EVENT_SHADOW_BOLT, 2s);
                        break;
                    case EVENT_FLAME_SPIKE:
                        DoCastVictim(SPELL_FLAMESPIKE);
                        events.ScheduleEvent(EVENT_FLAME_SPIKE, 30s);
                        break;
                    case EVENT_FIRE_NOVA:
                        DoCastVictim(SPELL_FIRENOVA);
                        events.ScheduleEvent(EVENT_FIRE_NOVA, 40s);
                        break;
                    default:
                        break;
                }
            }

            private:
                bool _hpYell;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetScarletMonasteryAI<boss_bloodmage_thalnosAI>(creature);
        }
};

void AddSC_boss_bloodmage_thalnos()
{
    new boss_bloodmage_thalnos();
}
