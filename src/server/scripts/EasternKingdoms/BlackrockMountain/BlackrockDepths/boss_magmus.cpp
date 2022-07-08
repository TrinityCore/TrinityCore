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
#include "ScriptedCreature.h"

enum Spells
{
    SPELL_FIERYBURST        = 13900,
    SPELL_WARSTOMP          = 24375
};

enum Events
{
    EVENT_FIERY_BURST       = 1,
    EVENT_WARSTOMP          = 2
};

enum Phases
{
    PHASE_ONE               = 1,
    PHASE_TWO               = 2
};

class boss_magmus : public CreatureScript
{
    public:
        boss_magmus() : CreatureScript("boss_magmus") { }

        struct boss_magmusAI : public ScriptedAI
        {
            boss_magmusAI(Creature* creature) : ScriptedAI(creature) { }

            void Reset() override
            {
                _events.Reset();
            }

            void JustEngagedWith(Unit* /*who*/) override
            {
                if (InstanceScript* instance = me->GetInstanceScript())
                    instance->SetData(TYPE_IRON_HALL, IN_PROGRESS);
                _events.SetPhase(PHASE_ONE);
                _events.ScheduleEvent(EVENT_FIERY_BURST, 5s);
            }

            void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
            {
                if (me->HealthBelowPctDamaged(50, damage) && _events.IsInPhase(PHASE_ONE))
                {
                    _events.SetPhase(PHASE_TWO);
                    _events.ScheduleEvent(EVENT_WARSTOMP, 0s, 0, PHASE_TWO);
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_FIERY_BURST:
                            DoCastVictim(SPELL_FIERYBURST);
                            _events.ScheduleEvent(EVENT_FIERY_BURST, 6s);
                            break;
                        case EVENT_WARSTOMP:
                            DoCastVictim(SPELL_WARSTOMP);
                            _events.ScheduleEvent(EVENT_WARSTOMP, 8s, 0, PHASE_TWO);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

            void JustDied(Unit* /*killer*/) override
            {
                if (InstanceScript* instance = me->GetInstanceScript())
                {
                    instance->HandleGameObject(instance->GetGuidData(DATA_THRONE_DOOR), true);
                    instance->SetData(TYPE_IRON_HALL, DONE);
                }
            }

        private:
            EventMap _events;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetBlackrockDepthsAI<boss_magmusAI>(creature);
        }
};

enum IronhandGuardian
{
    EVENT_GOUTOFFLAME = 1,
    SPELL_GOUTOFFLAME = 15529
};

class npc_ironhand_guardian : public CreatureScript
{
public:
    npc_ironhand_guardian() : CreatureScript("npc_ironhand_guardian") { }

    struct npc_ironhand_guardianAI : public ScriptedAI
    {
        npc_ironhand_guardianAI(Creature* creature) : ScriptedAI(creature)
        {
            _instance = me->GetInstanceScript();
            _active = false;
        }

        void Reset() override
        {
            _events.Reset();
        }

        void UpdateAI(uint32 diff) override
        {
            if (!_active)
            {
                if (_instance->GetData(TYPE_IRON_HALL) == NOT_STARTED)
                    return;
                // Once the boss is engaged, the guardians will stay activated until the next instance reset
                _events.ScheduleEvent(EVENT_GOUTOFFLAME, 0s, 10s);
                _active = true;
            }

            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                if (eventId == EVENT_GOUTOFFLAME)
                {
                    DoCastAOE(SPELL_GOUTOFFLAME);
                    _events.Repeat(16s, 21s);
                }
            }
        }

    private:
        EventMap _events;
        InstanceScript* _instance;
        bool _active;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetBlackrockDepthsAI<npc_ironhand_guardianAI>(creature);
    }
};

void AddSC_boss_magmus()
{
    new boss_magmus();
    new npc_ironhand_guardian();
}
