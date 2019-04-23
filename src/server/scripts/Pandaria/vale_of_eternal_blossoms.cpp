/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
 * Copyright (C) 2016 Firestorm Servers <https://firestorm-servers.com>
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

#include "SpellScript.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "ScriptedEscortAI.h"
#include "vale_of_eternal_blossoms.h"

// Zhao-Jin the Bloodletter - 60273
class mob_zhao_jin : public CreatureScript
{
    public:
        mob_zhao_jin() : CreatureScript("mob_zhao_jin") {}

        struct mob_zhao_jinAI : public ScriptedAI
        {
            mob_zhao_jinAI(Creature* creature) : ScriptedAI(creature) {}

            EventMap events;

            void Reset() override
            {
                events.Reset();

                events.ScheduleEvent(EVENT_LAVA_BURST, 10000);
                events.ScheduleEvent(EVENT_LIGHTNING_SPEAR, 15000);
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
                        case EVENT_LAVA_BURST:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_LAVA_BURST, false);
                            events.ScheduleEvent(EVENT_LAVA_BURST, 10000);
                            break;
                        case EVENT_LIGHTNING_SPEAR:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_LIGHTNING_SPEAR, false);
                            events.ScheduleEvent(EVENT_LIGHTNING_SPEAR, 15000);
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
            return new mob_zhao_jinAI(creature);
        }
};

// Reanimated Jade Warrior - 60121
class mob_reanimated_jade_warrior : public CreatureScript
{
    public:
        mob_reanimated_jade_warrior() : CreatureScript("mob_reanimated_jade_warrior") {}

        struct mob_reanimated_jade_warriorAI : public ScriptedAI
        {
            mob_reanimated_jade_warriorAI(Creature* creature) : ScriptedAI(creature) {}

            uint32 jadeFireTimer;
            uint32 jadeStrenghtTimer;

            void Reset() override
            {
                jadeFireTimer = urand(10000, 12000);
                jadeStrenghtTimer = urand(5000, 7000);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (jadeFireTimer <= diff)
                {
                    if (Unit* target = me->SelectNearestTarget(5.0f))
                        if (!target->IsFriendlyTo(me))
                            me->CastSpell(target, SPELL_JADE_FIRE, true);

                    jadeFireTimer = urand(20000, 22000);
                }
                else
                    jadeFireTimer -= diff;

                if (jadeStrenghtTimer <= diff)
                {
                    me->CastSpell(me, SPELL_JADE_STRENGHT, true);
                    jadeStrenghtTimer = urand(20000, 22000);
                }
                else
                   jadeStrenghtTimer -= diff;

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_reanimated_jade_warriorAI(creature);
        }
};

// Subjugated Serpent - 59158
class mob_subjuged_serpent : public CreatureScript
{
    public:
        mob_subjuged_serpent() : CreatureScript("mob_subjuged_serpent") {}

        struct mob_subjuged_serpentAI : public ScriptedAI
        {
            mob_subjuged_serpentAI(Creature* creature) : ScriptedAI(creature) { }

            uint32 lightningBreathTimer;
            uint32 lightningPoolTimer;
            uint32 lightningWhirlTimer;

            void Reset() override
            {
                lightningBreathTimer = urand(2000, 3000);
                lightningPoolTimer = urand(5000, 7000);
                lightningWhirlTimer = urand(3000, 6000);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (lightningBreathTimer <= diff)
                {
                    if (Unit* target = me->SelectNearestTarget(5.0f))
                    {
                        if (!target->IsFriendlyTo(me))
                        {
                            me->CastSpell(target, SPELL_LIGHTNING_BREATH, true);
                            lightningBreathTimer = urand(13000, 18000);
                        }
                    }
                }
                else
                    lightningBreathTimer -= diff;

                if (lightningPoolTimer <= diff)
                {
                    if (Unit* target = me->SelectNearestTarget(5.0f))
                    {
                        if (!target->IsFriendlyTo(me))
                        {
                            me->CastSpell(target, SPELL_LIGHTNING_POOL, true);
                            lightningPoolTimer = urand(27000, 29000);
                        }
                    }
                 }
                 else
                     lightningPoolTimer -= diff;

                 if (lightningWhirlTimer <= diff)
                 {
                     if (Unit* target = me->SelectNearestTarget(5.0f))
                     {
                         if (!target->IsFriendlyTo(me))
                         {
                             me->CastSpell(target, SPELL_LIGHTNING_WHIRL, true);
                             lightningWhirlTimer = urand(7000, 10000);
                         }
                     }
                 }
                 else
                 lightningWhirlTimer -= diff;

                 DoMeleeAttackIfReady();
                 }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_subjuged_serpentAI(creature);
        }
};

// Shao-Tien Behemoth - 65824
class mob_shao_tien_behemoth : public CreatureScript
{
    public:
        mob_shao_tien_behemoth() : CreatureScript("mob_shao_tien_behemoth") {}

        struct mob_shao_tien_behemothAI : public ScriptedAI
        {
            mob_shao_tien_behemothAI(Creature* creature) : ScriptedAI(creature) {}

            uint32 lightningBreathTimer;
            uint32 lightningPoolTimer;
            uint32 lightningWhirlTimer;
            EventMap events;

            void Reset() override
            {
                events.Reset();

                events.ScheduleEvent(EVENT_CRUSHING_STOMP, 8000);
                events.ScheduleEvent(EVENT_GROUND_STOMP, 12000);
                events.ScheduleEvent(EVENT_PARALYZED, 17000);
                events.ScheduleEvent(EVENT_THUNDERING_SLAM, 25000);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_CRUSHING_STOMP:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_CRUSHING_STOMP, false);
                            events.ScheduleEvent(EVENT_CRUSHING_STOMP, 320000);
                            break;
                        case EVENT_GROUND_STOMP:
                            me->CastSpell(me, SPELL_GROUND_STOMP, false);
                            events.ScheduleEvent(EVENT_GROUND_STOMP, 17000);
                            break;
                        case EVENT_PARALYZED:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_PARALYZED, false);
                            events.ScheduleEvent(EVENT_PARALYZED, 21000);
                            break;
                        case EVENT_THUNDERING_SLAM:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_THUNDERING_SLAM, false);
                            events.ScheduleEvent(EVENT_THUNDERING_SLAM, 25000);
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
            return new mob_shao_tien_behemothAI(creature);
        }
};

// Shao-Tien Surveyor - 59379
class mob_shao_tien_surveyor : public CreatureScript
{
    public:
        mob_shao_tien_surveyor() : CreatureScript("mob_shao_tien_surveyor") {}

        struct mob_shao_tien_surveyorAI : public ScriptedAI
        {
            mob_shao_tien_surveyorAI(Creature* creature) : ScriptedAI(creature) {}

            EventMap events;

            void Reset() override
            {
                me->CastSpell(me, SPELL_STEALTH, true);
                events.Reset();
                events.ScheduleEvent(EVENT_CRUSHING_STOMP, 8000);
                events.ScheduleEvent(EVENT_GROUND_STOMP, 12000);
                events.ScheduleEvent(EVENT_PARALYZED, 17000);
                events.ScheduleEvent(EVENT_THUNDERING_SLAM, 25000);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_CRUSHING_STOMP:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_CRUSHING_STOMP, false);
                            events.ScheduleEvent(EVENT_CRUSHING_STOMP, 320000);
                            break;
                        case EVENT_GROUND_STOMP:
                            me->CastSpell(me, SPELL_GROUND_STOMP, false);
                            events.ScheduleEvent(EVENT_GROUND_STOMP, 17000);
                            break;
                        case EVENT_PARALYZED:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_PARALYZED, false);
                            events.ScheduleEvent(EVENT_PARALYZED, 21000);
                            break;
                        case EVENT_THUNDERING_SLAM:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_THUNDERING_SLAM, false);
                            events.ScheduleEvent(EVENT_THUNDERING_SLAM, 25000);
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
            return new mob_shao_tien_surveyorAI(creature);
        }
};

// Shado Pan Flare - 123193
class spell_shadow_pan_flare: public SpellScriptLoader
{
    public:
        spell_shadow_pan_flare() : SpellScriptLoader("spell_shadow_pan_flare") {}

        class spell_shadow_pan_flare_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_shadow_pan_flare_SpellScript);

            void HandleOnHit()
            {
                if (Unit* caster = GetCaster()->ToPlayer())
                {
                    std::list<Creature*> surveyorList;
                    GetCreatureListWithEntryInGrid(surveyorList, caster, MOB_SHAO_TIEN_SURVEYOR, 100.0f);

                    for (auto surveyor : surveyorList)
                        surveyor->RemoveAura(SPELL_STEALTH);
                }
            }

            void Register() override
            {
                OnHit += SpellHitFn(spell_shadow_pan_flare_SpellScript::HandleOnHit);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_shadow_pan_flare_SpellScript();
        }
};

void AddSC_vale_of_eternal_blossoms()
{
    new mob_zhao_jin();
    new mob_reanimated_jade_warrior();
    new mob_subjuged_serpent();
    new mob_shao_tien_behemoth();
    new mob_shao_tien_surveyor();
    new spell_shadow_pan_flare();
}
