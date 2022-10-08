/*
 * Copyright (C) 2022 BfaCore Reforged
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

#include "ScriptedCreature.h"
#include "heart_of_fear.h"
#include "ScriptMgr.h"
#include "ScriptedGossip.h"
#include "ScriptedEscortAI.h"
#include "CreatureAI.h"
#include "MoveSplineInit.h"

// 63048 - Kor'thik Slicer
class mob_kor_thik_slicer : public CreatureScript
{
    public:
        mob_kor_thik_slicer() : CreatureScript("mob_kor_thik_slicer") {}

        struct mob_kor_thik_slicerAI : public ScriptedAI
        {
            mob_kor_thik_slicerAI(Creature* creature) : ScriptedAI(creature)
            {
                eventScheduled = false;
            }

            EventMap events;
            bool eventScheduled;

            void Reset() override
            {
                events.Reset();

                if (IsHeroic())
                    events.ScheduleEvent(EVENT_SLOW, 3000);
                events.ScheduleEvent(EVENT_ARTERIAL_SPIRIT, 10000);
                events.ScheduleEvent(EVENT_VITAL_STRIKES, 5000);
                me->SetVirtualItem(0, EQUIP_TRASH_4);
            }

            void DamageTaken(Unit* /*p_Killer*/, uint32& damage) override
            {
                if(!eventScheduled)
                {
                    if (me->HealthBelowPctDamaged(25, damage))
                    {
                        events.ScheduleEvent(EVENT_GOUGE_THROAT, 12000);
                        eventScheduled = true;
                    }
                }
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 id = events.ExecuteEvent())
                {
                    switch (id)
                    {
                        case EVENT_ARTERIAL_SPIRIT:
                            if (Unit* target = SelectTarget(SELECT_TARGET_FARTHEST))
                                me->CastSpell(target, SPELL_ARTERIAL_SPIRIT, true);
                            events.ScheduleEvent(EVENT_ARTERIAL_SPIRIT, 20000);
                            break;
                        case EVENT_GOUGE_THROAT:
                            if (Unit* target = SelectTarget(SELECT_TARGET_FARTHEST))
                                me->CastSpell(target, SPELL_GOUGE_THROAT, true);
                            events.ScheduleEvent(EVENT_GOUGE_THROAT, 32000);
                            break;
                        case EVENT_VITAL_STRIKES:
                            if (Unit* target = SelectTarget(SELECT_TARGET_FARTHEST))
                                me->CastSpell(target, SPELL_VITAL_STRIKES, true);
                            events.ScheduleEvent(EVENT_VITAL_STRIKES, 20000);
                            break;
                        case EVENT_SLOW:
                            if (Unit* target = SelectTarget(SELECT_TARGET_FARTHEST))
                                me->CastSpell(target, SPELL_SLOW, true);
                            events.ScheduleEvent(EVENT_SLOW, 40000);
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
            return new mob_kor_thik_slicerAI(creature);
        }
};

// 63036 - Kor'thik extremist
class mob_kor_thik_extremist : public CreatureScript
{
    public:
        mob_kor_thik_extremist() : CreatureScript("mob_kor_thik_extremist") {}

        struct mob_kor_thik_extremistAI : public ScriptedAI
        {
            mob_kor_thik_extremistAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            EventMap events;

            void Reset() override
            {
                events.Reset();

                if (IsHeroic())
                    events.ScheduleEvent(EVENT_SLOW, 3000);
                events.ScheduleEvent(EVENT_UNDYING_DEVOTION, 5000);
                me->SetVirtualItem(0, EQUIP_TRASH_5);
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 id = events.ExecuteEvent())
                {
                    switch (id)
                    {
                        case EVENT_UNDYING_DEVOTION:
                            if (Unit* target = SelectTarget(SELECT_TARGET_FARTHEST))
                                me->CastSpell(target, SPELL_UNDYING_DEVOTION, true);
                            events.ScheduleEvent(EVENT_UNDYING_DEVOTION, 20000);
                            break;
                        case EVENT_SLOW:
                            if (Unit* target = SelectTarget(SELECT_TARGET_FARTHEST))
                                me->CastSpell(target, SPELL_SLOW, true);
                            events.ScheduleEvent(EVENT_SLOW, 40000);
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
            return new mob_kor_thik_extremistAI(creature);
        }
};

// 63032 - Sra'thik Shield Master
class mob_sra_thik_shield_master : public CreatureScript
{
    public:
        mob_sra_thik_shield_master() : CreatureScript("mob_sra_thik_shield_master") {}

        struct mob_sra_thik_shield_masterAI : public ScriptedAI
        {
            mob_sra_thik_shield_masterAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            EventMap events;

            void Reset() override
            {
                events.Reset();

                if (IsHeroic())
                    events.ScheduleEvent(EVENT_SLOW, 3000);
                events.ScheduleEvent(EVENT_BRAIN_FREEZE, 7000);
                events.ScheduleEvent(EVENT_DISMANTLED_ARMOR, 12000);
                events.ScheduleEvent(EVENT_MASS_SPELL_REFLEXION, 19000);
                events.ScheduleEvent(EVENT_SHIELD_SLAM, 26000);
                events.ScheduleEvent(EVENT_STUNNING_STRIKE, 35000);
                me->SetVirtualItem(0, EQUIP_TRASH_6);
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 id = events.ExecuteEvent())
                {
                    switch (id)
                    {
                        case EVENT_BRAIN_FREEZE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_BRAIN_FREEZE, true);
                            events.ScheduleEvent(EVENT_BRAIN_FREEZE, 60000);
                            break;
                        case EVENT_DISMANTLED_ARMOR:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_DISMANTLED_ARMOR, true);
                            events.ScheduleEvent(EVENT_DISMANTLED_ARMOR, 40000);
                            break;
                        case EVENT_MASS_SPELL_REFLEXION:
                                me->CastSpell(me, SPELL_MASS_SPELL_REFLEXION, true);
                            events.ScheduleEvent(EVENT_MASS_SPELL_REFLEXION, 40000);
                            break;
                        case EVENT_SHIELD_SLAM:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_SHIELD_SLAM, true);
                            events.ScheduleEvent(EVENT_SHIELD_SLAM, 40000);
                            break;
                        case EVENT_STUNNING_STRIKE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_STUNNING_STRIKE, true);
                            events.ScheduleEvent(EVENT_STUNNING_STRIKE, 40000);
                            break;
                        case EVENT_SLOW:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_SLOW, true);
                            events.ScheduleEvent(EVENT_SLOW, 40000);
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
            return new mob_sra_thik_shield_masterAI(creature);
        }
};

// 63049 - Set'thik Swiftblade
class mob_set_thik_swiftblade : public CreatureScript
{
    public:
        mob_set_thik_swiftblade() : CreatureScript("mob_set_thik_swiftblade") {}

        struct mob_set_thik_swiftbladeAI : public ScriptedAI
        {
            mob_set_thik_swiftbladeAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            EventMap events;

            void Reset() override
            {
                events.Reset();

                if (IsHeroic())
                    events.ScheduleEvent(EVENT_SLOW, 3000);
                events.ScheduleEvent(EVENT_BLURRING_SLASH, 7000);
                events.ScheduleEvent(EVENT_RIPOSTE, 12000);

                me->SetVirtualItem(0, EQUIP_TRASH_7);

            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 id = events.ExecuteEvent())
                {
                    switch (id)
                    {
                        case EVENT_BLURRING_SLASH:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_BLURRING_SLASH, true);
                            events.ScheduleEvent(EVENT_BLURRING_SLASH, 22000);
                            break;
                        case EVENT_RIPOSTE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_RIPOSTE, true);
                            events.ScheduleEvent(EVENT_RIPOSTE, 22000);
                            break;
                        case EVENT_SLOW:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_SLOW, true);
                            events.ScheduleEvent(EVENT_SLOW, 40000);
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
            return new mob_set_thik_swiftbladeAI(creature);
        }
};

// 67177 - 66181 - 63853 - Zar'thik Supplicant
class mob_zar_thik_supplicant : public CreatureScript
{
    public:
        mob_zar_thik_supplicant() : CreatureScript("mob_zar_thik_supplicant") {}

        struct mob_zar_thik_supplicantAI : public ScriptedAI
        {
            mob_zar_thik_supplicantAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            EventMap events;

            void Reset() override
            {
                events.Reset();

                if (IsHeroic() && me->GetEntry() == NPC_ZARTHIK_SUPPLICANT)
                    events.ScheduleEvent(EVENT_SLOW, 3000);
                if (me->GetEntry() == NPC_ZARTHIK_SUPPLICANT_3 || me->GetEntry() == NPC_ZARTHIK_SUPPLICANT)
                    events.ScheduleEvent(EVENT_ICE_TRAP, 7000);
                events.ScheduleEvent(EVENT_MASH_AND_GNASH, 12000);
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 id = events.ExecuteEvent())
                {
                    switch (id)
                    {
                        case EVENT_ICE_TRAP:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_ICE_TRAP, true);
                            events.ScheduleEvent(EVENT_ICE_TRAP, 22000);
                            break;
                        case EVENT_MASH_AND_GNASH:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_MASH_AND_GNASH, true);
                            events.ScheduleEvent(EVENT_MASH_AND_GNASH, 22000);
                            break;
                        case EVENT_SLOW:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_SLOW, true);
                            events.ScheduleEvent(EVENT_SLOW, 40000);
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
            return new mob_zar_thik_supplicantAI(creature);
        }
};

// 63030 - Enslaved Bonesmasher
class mob_enslaved_bonesmasher : public CreatureScript
{
    public:
        mob_enslaved_bonesmasher() : CreatureScript("mob_enslaved_bonesmasher") {}

        struct mob_enslaved_bonesmasherAI : public ScriptedAI
        {
            mob_enslaved_bonesmasherAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            EventMap events;

            void Reset() override
            {
                events.Reset();

                if (IsHeroic())
                    events.ScheduleEvent(EVENT_SLOW, 3000);
                events.ScheduleEvent(EVENT_JAWBONE_SLAM, 7000);

                me->SetVirtualItem(0, EQUIP_TRASH_8);
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 id = events.ExecuteEvent())
                {
                    switch (id)
                    {
                        case EVENT_JAWBONE_SLAM:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_JAWBONE_SLAM, true);
                            events.ScheduleEvent(EVENT_JAWBONE_SLAM, 22000);
                            break;
                        case EVENT_SLOW:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_SLOW, true);
                            events.ScheduleEvent(EVENT_SLOW, 40000);
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
            return new mob_enslaved_bonesmasherAI(creature);
        }
};

// 64358 - Set'thik Tempest
class mob_set_thik_tempest : public CreatureScript
{
    public:
        mob_set_thik_tempest() : CreatureScript("mob_set_thik_tempest") {}

        struct mob_set_thik_tempestAI : public ScriptedAI
        {
            mob_set_thik_tempestAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();
            }

            InstanceScript* pInstance;
            EventMap events;

            void Reset() override
            {
                events.Reset();
                events.ScheduleEvent(EVENT_WIND_SLASH, 7000);
                me->SetVirtualItem(0, EQUIP_TRASH_4);
            }

            void JustDied(Unit* /*killer*/) override
            {
                if (pInstance)
                {
                    if (Creature* tayak = pInstance->GetCreature(NPC_TAYAK))
                        tayak->AI()->DoAction(ACTION_TAYAK_TALK_TRASH);
                }
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 id = events.ExecuteEvent())
                {
                    if (id == EVENT_WIND_SLASH)
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                            me->CastSpell(target, SPELL_WIND_SLASH, true);
                        events.ScheduleEvent(EVENT_WIND_SLASH, 40000);
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_set_thik_tempestAI(creature);
        }
};

// 63031 - Set'thik Fanatic
class mob_set_thik_fanatic : public CreatureScript
{
    public:
        mob_set_thik_fanatic() : CreatureScript("mob_set_thik_fanatic") {}

        struct mob_set_thik_fanaticAI : public ScriptedAI
        {
            mob_set_thik_fanaticAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            EventMap events;

            void Reset() override
            {
                events.Reset();

                if (!IsHeroic())
                    events.ScheduleEvent(EVENT_SLOW, 3000);
                events.ScheduleEvent(EVENT_GALE_FORCE_WINDS, 7000);
                events.ScheduleEvent(EVENT_WINDBURST, 15000);
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 id = events.ExecuteEvent())
                {
                    switch (id)
                    {
                        case EVENT_GALE_FORCE_WINDS:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_GALE_FORCE_WINDS, true);
                            events.ScheduleEvent(EVENT_GALE_FORCE_WINDS, 22000);
                            break;
                        case EVENT_WINDBURST:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_WINDBURST, true);
                            events.ScheduleEvent(EVENT_WINDBURST, 22000);
                            break;
                        case EVENT_SLOW:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_SLOW, true);
                            events.ScheduleEvent(EVENT_SLOW, 40000);
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
            return new mob_set_thik_fanaticAI(creature);
        }
};

// 63593 - Set'thik Zephyrian
class mob_set_thik_zephyrian : public CreatureScript
{
    public:
        mob_set_thik_zephyrian() : CreatureScript("mob_set_thik_zephyrian") {}

        struct mob_set_thik_zephyrianAI : public ScriptedAI
        {
            mob_set_thik_zephyrianAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();
            }

            EventMap events;
            InstanceScript* pInstance;

            void Reset() override
            {
                events.Reset();
                events.ScheduleEvent(EVENT_SUMMON_ZEPHYR, 4000);
                me->SetVirtualItem(0, EQUIP_TRASH_2);
            }

            void JustDied(Unit* /*killer*/) override
            {
                if (!GetClosestCreatureWithEntry(me, me->GetEntry(), 200.0f))
                {
                    if (!GetClosestCreatureWithEntry(me, NPC_SETTHIK_GUSTWING, 200.0f))
                    {
                        if (pInstance)
                        {
                            if (Creature* garalon = pInstance->GetCreature(NPC_GARALON))
                                garalon->AI()->DoAction(ACTION_GARALON_VISIBLE);
                        }
                    }
                }
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 id = events.ExecuteEvent())
                {
                    if (id == EVENT_SUMMON_ZEPHYR)
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                            me->CastSpell(target, SPELL_SUMMON_ZEPHYR, true);
                        events.ScheduleEvent(EVENT_SUMMON_ZEPHYR, 22000);
                        break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_set_thik_zephyrianAI(creature);
        }
};

// 64353 - Set'thik Gale-Slicer
class mob_set_thik_gale_slicer : public CreatureScript
{
    public:
        mob_set_thik_gale_slicer() : CreatureScript("mob_set_thik_gale_slicer") {}

        struct mob_set_thik_gale_slicerAI : public ScriptedAI
        {
            mob_set_thik_gale_slicerAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();
            }

            EventMap events;
            InstanceScript* pInstance;

            void Reset() override
            {
                events.Reset();
                events.ScheduleEvent(EVENT_SWIFT_STEP, 4000);
                me->SetVirtualItem(0, EQUIP_TRASH_7);
            }

            void JustDied(Unit* /*killer*/) override
            {
                if (pInstance)
                {
                    if (Creature* tayak = pInstance->GetCreature(NPC_TAYAK))
                        tayak->AI()->DoAction(ACTION_TAYAK_TALK_TRASH);
                }
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 id = events.ExecuteEvent())
                {
                    if (id == EVENT_SWIFT_STEP)
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                            me->CastSpell(target, SPELL_SWIFT_STEP, true);
                        events.ScheduleEvent(EVENT_SWIFT_STEP, 22000);
                        break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_set_thik_gale_slicerAI(creature);
        }
};

// 64338 - Instructor Kli'thak <Keeper of Wind Step>
class mob_instructor_kli_thak : public CreatureScript
{
    public:
        mob_instructor_kli_thak() : CreatureScript("mob_instructor_kli_thak") {}

        struct mob_instructor_kli_thakAI : public ScriptedAI
        {
            mob_instructor_kli_thakAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();
            }

            EventMap events;
            InstanceScript* pInstance;

            void Reset() override
            {
                events.Reset();
                events.ScheduleEvent(EVENT_WIND_STEP, 15000);
                me->SetVirtualItem(0, EQUIP_TRASH_7);
            }

            void JustDied(Unit* /*killer*/) override
            {
                if (pInstance)
                {
                    if (Creature* tayak = pInstance->GetCreature(NPC_TAYAK))
                        tayak->AI()->DoAction(ACTION_TAYAK_TALK_TRASH);
                }
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 id = events.ExecuteEvent())
                {
                    switch (id)
                    {
                        case EVENT_WIND_STEP:
                        {
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_WIND_STEP_TP, true);
                            events.ScheduleEvent(EVENT_WIND_STEP, 22000);
                            break;
                        }
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_instructor_kli_thakAI(creature);
        }
};

// 64339 - Instructor Tak'thok <Keeper of Overwhelming Assault>
class mob_instructor_tak_thok : public CreatureScript
{
    public:
        mob_instructor_tak_thok() : CreatureScript("mob_instructor_tak_thok") {}

        struct mob_instructor_tak_thokAI : public ScriptedAI
        {
            mob_instructor_tak_thokAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();
            }

            EventMap events;
            InstanceScript* pInstance;

            void Reset() override
            {
                events.Reset();
                events.ScheduleEvent(EVENT_OVERWHELMING_ASSAULT, 4000);

                me->SetVirtualItem(0, EQUIP_TRASH_6);
            }

            void JustDied(Unit* /*killer*/) override
            {
                if (pInstance)
                {
                    if (Creature* tayak = pInstance->GetCreature(NPC_TAYAK))
                        tayak->AI()->DoAction(ACTION_TAYAK_TALK_TRASH);
                }
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 id = events.ExecuteEvent())
                {
                    if (id == EVENT_OVERWHELMING_ASSAULT)
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                            me->CastSpell(target, SPELL_OVERWHELMING_ASS, true);
                        events.ScheduleEvent(EVENT_OVERWHELMING_ASSAULT, 22000);
                        break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_instructor_tak_thokAI(creature);
        }
};

// 64340 - Instructor Maltik <Keeper of Unseen Strike>
class mob_instructor_maltik : public CreatureScript
{
    public:
        mob_instructor_maltik() : CreatureScript("mob_instructor_maltik") { }

        struct mob_instructor_maltikAI : public ScriptedAI
        {
            mob_instructor_maltikAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();
            }

            EventMap events;
            InstanceScript* pInstance;

            void Reset() override
            {
                events.Reset();
                events.ScheduleEvent(EVENT_TRASH_UNSEEN_STRIKE, 15000);
                me->SetVirtualItem(0, EQUIP_TRASH_1);
            }

            void JustDied(Unit* /*killer*/) override
            {
                if (pInstance)
                {
                    if (Creature* tayak = pInstance->GetCreature(NPC_TAYAK))
                        tayak->AI()->DoAction(ACTION_TAYAK_TALK_TRASH);
                }
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 id = events.ExecuteEvent())
                {
                    switch (id)
                    {
                        case EVENT_TRASH_UNSEEN_STRIKE:
                        {
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                            {
                                me->CastSpell(target, SPELL_UNSEEN_STRIKE_TR, true);
                                me->AddAura(SPELL_UNSEEN_STRIKE_MKR, target);
                                me->GetMotionMaster()->MoveChase(target);
                                me->SetReactState(REACT_PASSIVE);
                            }
                            events.ScheduleEvent(EVENT_TRASH_UNSEEN_STRIKE, 22000);

                        }
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_instructor_maltikAI(creature);
        }
};

// 64341 - Instructor Zarik <Keeper of Tempest Slash>
class mob_instructor_zarik : public CreatureScript
{
    public:
        mob_instructor_zarik() : CreatureScript("mob_instructor_zarik") { }

        struct mob_instructor_zarikAI : public ScriptedAI
        {
            mob_instructor_zarikAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();
            }

            EventMap events;
            InstanceScript* pInstance;

            void Reset() override
            {
                events.Reset();
                events.ScheduleEvent(EVENT_TRASH_TEMPEST_SLASH, 15000);
                me->SetVirtualItem(0, EQUIP_TRASH_4);
            }

            void JustDied(Unit* /*killer*/) override
            {
                if (pInstance)
                {
                    if (Creature* tayak = pInstance->GetCreature(NPC_TAYAK))
                        tayak->AI()->DoAction(ACTION_TAYAK_TALK_TRASH);
                }
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 id = events.ExecuteEvent())
                {
                    switch (id)
                    {
                        case EVENT_TRASH_TEMPEST_SLASH:
                        {
                            DoCast(me, SPELL_TEMPEST_SLASH);
                            events.ScheduleEvent(EVENT_TRASH_TEMPEST_SLASH, 22000);
                            break;
                        }
                        default:
                            break;
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_instructor_zarikAI(creature);
        }
};

// 63035 - Zar'thik Zealot
class mob_zar_thik_zealot : public CreatureScript
{
    public:
        mob_zar_thik_zealot() : CreatureScript("mob_zar_thik_zealot") {}

        struct mob_zar_thik_zealotAI : public ScriptedAI
        {
            mob_zar_thik_zealotAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            EventMap events;

            void Reset() override
            {
                events.Reset();

                if (IsHeroic())
                    events.ScheduleEvent(EVENT_SLOW, 3000);
                events.ScheduleEvent(EVENT_ZEALOUS_RUSH, 7000);

                me->SetVirtualItem(0, EQUIP_TRASH_9);
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 id = events.ExecuteEvent())
                {
                    switch (id)
                    {
                        case EVENT_ZEALOUS_RUSH:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                me->CastSpell(target, SPELL_ZEALOUS_RUSH, true);
                            events.ScheduleEvent(EVENT_ZEALOUS_RUSH, 22000);
                            break;
                        case EVENT_SLOW:
                            if (Unit* target = SelectTarget(SELECT_TARGET_FARTHEST))
                                me->CastSpell(target, SPELL_SLOW, true);
                            events.ScheduleEvent(EVENT_SLOW, 40000);
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
            return new mob_zar_thik_zealotAI(creature);
        }
};

// 64357 - Kor'thik Swarmer
class mob_kor_thik_swarmer : public CreatureScript
{
    public:
        mob_kor_thik_swarmer() : CreatureScript("mob_kor_thik_swarmer") {}

        struct mob_kor_thik_swarmerAI : public ScriptedAI
        {
            mob_kor_thik_swarmerAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();
            }

            EventMap events;
            InstanceScript* pInstance;

            void Reset() override
            {
                events.Reset();
                events.ScheduleEvent(EVENT_UNDERWHELMING_ASSAULT, 4000);

                me->SetVirtualItem(0, EQUIP_TRASH_6);
            }

            void JustDied(Unit* /*killer*/) override
            {
                if (pInstance)
                {
                    if (Creature* tayak = pInstance->GetCreature(NPC_TAYAK))
                        tayak->AI()->DoAction(ACTION_TAYAK_TALK_TRASH);
                }
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 id = events.ExecuteEvent())
                {
                    if (id == EVENT_UNDERWHELMING_ASSAULT)
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                            me->CastSpell(target, SPELL_UNDERWHELMING_ASSAULT, true);
                        events.ScheduleEvent(EVENT_UNDERWHELMING_ASSAULT, 22000);
                        break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_kor_thik_swarmerAI(creature);
        }
};

// 63592 - Set'thik Gustwing
class mob_set_thik_gustwing : public CreatureScript
{
    public:
        mob_set_thik_gustwing() : CreatureScript("mob_set_thik_gustwing") {}

        struct mob_set_thik_gustwingAI : public ScriptedAI
        {
            mob_set_thik_gustwingAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();
            }

            EventMap events;
            InstanceScript* pInstance;

            void Reset() override
            {
                events.Reset();

                events.ScheduleEvent(EVENT_GUST, 3000);
                events.ScheduleEvent(EVENT_ICE_TRAP, 7000);
                me->SetVirtualItem(0, EQUIP_TRASH_3);
            }

            void JustDied(Unit* /*killer*/) override
            {
                if (!GetClosestCreatureWithEntry(me, me->GetEntry(), 200.0f))
                {
                    if (!GetClosestCreatureWithEntry(me, NPC_SETTHIK_ZEPHYRIAN, 200.0f))
                    {
                        if (pInstance)
                        {
                            if (Creature* garalon = pInstance->GetCreature(NPC_GARALON))
                                garalon->AI()->DoAction(ACTION_GARALON_VISIBLE);
                        }
                    }
                }
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 id = events.ExecuteEvent())
                {
                    switch (id)
                    {
                        case EVENT_GUST:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                me->CastSpell(target, SPELL_GUST, true);
                            events.ScheduleEvent(EVENT_GUST, 22000);
                            break;
                        case EVENT_ICE_TRAP:
                            if (Unit* target = SelectTarget(SELECT_TARGET_FARTHEST))
                                me->CastSpell(target, SPELL_ICE_TRAP, true);
                            events.ScheduleEvent(EVENT_ICE_TRAP, 40000);
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
            return new mob_set_thik_gustwingAI(creature);
        }
};

Position unsokRoomAngle[4] =
{
    {-2440.82f, 662.18f, 581.55f, 0.0f},    // NE - Starting point for 63597
    {-2513.15f, 662.18f, 581.55f, 0.0f},    // SE - Starting point for 63594
    {-2513.15f, 734.44f, 581.55f, 0.0f},    // SW
    {-2440.82f, 734.44f, 581.55f, 0.0f},    // NW
};

Position unsokDiagPoint[2] =
{
    {-2409.33f, 630.0f, 582.92f, 0.0f},
    {-2549.87f, 770.0f, 582.92f, 0.0f}
};

// 63594 / 63597 - Coagulated Amber
class mob_coagulated_amber : public CreatureScript
{
    public:
        mob_coagulated_amber() : CreatureScript("mob_coagulated_amber") {}

        struct mob_coagulated_amberAI : public ScriptedAI
        {
            mob_coagulated_amberAI(Creature* creature) : ScriptedAI(creature) { }

            uint8 walkTimer;
            uint8 point;
            int8 clockwise;
            bool isTurning;
            bool isClockwise;

            void Reset() override
            {
                isTurning = me->GetPositionZ() < 582.0f;
                isClockwise = me->GetEntry() == 63597;

                walkTimer = 0;
                clockwise = isClockwise ? 1 : -1;

                if (isTurning)
                    point = isClockwise ? 1 : 2;
                else
                    point = me->GetPositionY() > 700 ? 0 : 1;

                if (isTurning)
                    me->GetMotionMaster()->MovePoint(point + 1, unsokRoomAngle[point]);
                else
                    me->GetMotionMaster()->MovePoint(point + 10, unsokDiagPoint[point]);

            }

            void MovementInform(uint32 type, uint32 id) override
            {
                if (type != POINT_MOTION_TYPE)
                    return;

                // turning movement
                if (id < 10)
                    /***
                     * +4 because if we're not clockwise (ie. clockwise = -1), at point = 0, point + clockwise = -1, and -1 % 4 = -1, and so, -1 + 4 = 3 and
                     * 3 % 4 = 3, so we go from 0 to 3. For any other value, it won't have any incidence (for ex. if point + clockwise = 2, then 2 + 4 = 6 and
                     * 6 % 4 = 2, and even if point + clockwise = 4, 4 + 4 = 8 and 8 % 4 = 0.
                     *
                     * So this will always return a valid value between 0 and 3, whatever the values of point and clockwise.
                     ***/
                    point = (point + clockwise + 4) % 4;
                // diagonal movement
                else
                    // As target point can be 0 or 1, 1-targetPoint can be either 1-0 = 1 or 1-1 = 0, so we switch the value of targetPoint
                    point = 1 - point;

                walkTimer = 1;
            }

            void JustDied(Unit* /*killer*/) override
            {
                // Explode
                DoCast(SPELL_BURST);
            }

            void UpdateAI(const uint32 diff) override
            {
                if (walkTimer)
                {
                    if (walkTimer > diff)
                        walkTimer -= diff;
                    else
                    {
                        if (isTurning)
                            me->GetMotionMaster()->MovePoint(point + 1, unsokRoomAngle[point]);
                        else
                            me->GetMotionMaster()->MovePoint(point + 10, unsokDiagPoint[point]);

                        walkTimer = 0;
                    }
                }

                if (!UpdateVictim())
                    return;

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_coagulated_amberAI(creature);
        }
};

// 64355 - Kor'thik Silentwing
class mob_kor_thik_silentwing : public CreatureScript
{
    public:
        mob_kor_thik_silentwing() : CreatureScript("mob_kor_thik_silentwing") { }

        struct mob_kor_thik_silentwingAI : public ScriptedAI
        {
            mob_kor_thik_silentwingAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();
            }

            EventMap events;
            InstanceScript* pInstance;

            void Reset() override
            {
                events.Reset();
                me->SetVirtualItem(0, EQUIP_TRASH_1);
                events.ScheduleEvent(EVENT_ALMOST_UNSEEN_STRIKE, 15000);
            }

            void JustDied(Unit* /*killer*/) override
            {
                if (pInstance)
                {
                    if (Creature* tayak = pInstance->GetCreature(NPC_TAYAK))
                        tayak->AI()->DoAction(ACTION_TAYAK_TALK_TRASH);
                }
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 id = events.ExecuteEvent())
                {
                    switch (id)
                    {
                        case EVENT_ALMOST_UNSEEN_STRIKE:
                        {
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_ALMOST_UNSEEN_STRIKE, true);
                            events.ScheduleEvent(EVENT_ALMOST_UNSEEN_STRIKE, 22000);
                            break;
                        }
                        default:
                            break;
                    }
                }
                DoMeleeAttackIfReady();
            }

        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_kor_thik_silentwingAI(creature);
        }
};

// 63599 - Zephyr (summoned by Set'thik Zephyrian - 63593)
class mob_zephyr : public CreatureScript
{
    public:
        mob_zephyr() : CreatureScript("mob_zephyr") { }

        struct mob_zephyrAI : public ScriptedAI
        {
            mob_zephyrAI(Creature* creature) : ScriptedAI(creature)
            {
                creature->SetDisplayId(38493);
                me->SetSpeed(MOVE_RUN, 5.0f);
                me->SetReactState(REACT_PASSIVE);
            }

            EventMap m_Events;

            void Reset() override
            {
                m_Events.Reset();
                me->CastSpell(me, SPELL_ZEPHYR, false);
                me->DespawnOrUnsummon(30000);
                m_Events.ScheduleEvent(EVENT_ZEPHYR_MOVE, 500);
            }

            void UpdateAI(uint32 const p_Diff) override
            {
                m_Events.Update(p_Diff);

                if (m_Events.ExecuteEvent() == EVENT_ZEPHYR_MOVE)
                {
                    float l_PosX = me->GetPositionX() + 100.0f * cos(me->GetOrientation());
                    float l_PosY = me->GetPositionY() + 100.0f * sin(me->GetOrientation());
                    Position targetPoint = { l_PosX, l_PosY, me->GetPositionZ(), me->GetOrientation() };
                    me->GetMotionMaster()->MovePoint(0, targetPoint);
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_zephyrAI(creature);
        }
};

enum eSwarmGuardType
{
    TYPE_SWARM_LOWGUID = 1,
    TYPE_AMBER_USED
};

// 64916 - Kor'thik Swarmguard
class mob_korthik_swarmguard : public CreatureScript
{
public:
    mob_korthik_swarmguard() : CreatureScript("mob_korthik_swarmguard") { }

    struct mob_korthik_swarmguardAI : public ScriptedAI
    {
        mob_korthik_swarmguardAI(Creature* creature) : ScriptedAI(creature)
        {
            pInstance = creature->GetInstanceScript();
        }

        EventMap events;
        uint32 protectedAmberCallerLowGuid;
        ObjectGuid protectedAmberGuid;
        InstanceScript* pInstance;
        bool inCombat;
        bool isProtecting;

        void Reset() override
        {
            events.Reset();
            me->SetVirtualItem(0, EQUIP_TRASH_7);
            me->SetReactState(REACT_AGGRESSIVE);
            protectedAmberCallerLowGuid = 0;
            protectedAmberGuid = ObjectGuid::Empty;
            inCombat = false;
            isProtecting = false;
        }

        void JustDied(Unit* /*killer*/) override
        {
            protectedAmberCallerLowGuid = 0;
            inCombat = false;
        }

        void DamageTaken(Unit* p_Attacker, uint32& /*p_Damage*/) override
        {
            if (!inCombat)
                EnterCombat(p_Attacker);
        }

        void EnterCombat(Unit* /*p_Attacker*/) override
        {
            if (!inCombat)
            {
                events.ScheduleEvent(EVENT_CARAPACE, 2000);
                inCombat = true;

                if (isProtecting)
                    return;

                // Retreiving list of ambercallers (maximum: 2 if all is alright)
                std::list<Creature*> amberCallerList;
                GetCreatureListWithEntryInGrid(amberCallerList, me, NPC_SRATHIK_AMBERCALLER, 50.0f);
                amberCallerList.sort(Trinity::DistanceCompareOrderPred(me));

                if (amberCallerList.size() > 1)
                {
                    for (std::list<Creature*>::iterator itr = amberCallerList.begin(); itr != amberCallerList.end(); ++itr)
                    {
                        Creature* amberCaller = *itr;

                        if (amberCaller)
                        {
                            if (!amberCaller->AI()->GetData(TYPE_AMBER_USED))
                            {
                                protectedAmberGuid = amberCaller->GetGUID();
                                isProtecting = true;
                                DoCast(amberCaller, SPELL_SWARMGUARDS_AEGIS);
                                amberCaller->AI()->SetData(TYPE_AMBER_USED, 1);
                                amberCaller->AI()->DoAction(ACTION_AMBER_VOLLEY);
                                return;
                            }
                        }
                    }
                }
            }
        }

        void UpdateAI(const uint32 diff) override
        {
            if (!inCombat)
                return;

            if (pInstance)
            {
                if (pInstance->IsWipe())
                {
                    me->GetMotionMaster()->MoveTargetedHome();
                    me->SetFullHealth();
                    me->RemoveAllAuras();
                    Reset();
                    return;
                }
            }

            events.Update(diff);

            // Looking for Sra'thik Ambercaller to protect
            Creature* amberCaller = nullptr;

            if (!protectedAmberGuid.IsEmpty())
                amberCaller = ObjectAccessor::GetCreature(*me, protectedAmberGuid);

            // Ambercaller not found, dead or too far
            if (!amberCaller || !amberCaller->IsAlive() || me->GetDistance(amberCaller) > 30.0f)
            {
                if (!me->HasAura(SPELL_SEPARATION_ANXIETY))
                    me->AddAura(SPELL_SEPARATION_ANXIETY, me);
            }
            // Ambercaller is here: we remove anxiety aura if set
            else if (me->HasAura(SPELL_SEPARATION_ANXIETY))
                me->RemoveAura(SPELL_SEPARATION_ANXIETY);

            while (uint32 eventId = events.ExecuteEvent())
            {
                if (eventId == EVENT_CARAPACE)
                {
                    DoCast(me, SPELL_CARAPACE);
                    events.ScheduleEvent(EVENT_CARAPACE, urand(10000, 20000));
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new mob_korthik_swarmguardAI(creature);
    }
};

// 64917 - Sra'thik Ambercaller
class mob_srathik_ambercaller : public CreatureScript
{
public:
    mob_srathik_ambercaller() : CreatureScript("mob_srathik_ambercaller") { }

    struct mob_srathik_ambercallerAI : public ScriptedAI
    {
        mob_srathik_ambercallerAI(Creature* creature) : ScriptedAI(creature)
        {
            pInstance = creature->GetInstanceScript();
        }

        EventMap events;
        InstanceScript* pInstance;
        bool isProtected;

        void Reset() override
        {
            events.Reset();
            me->SetVirtualItem(0, EQUIP_TRASH_9);
            me->SetReactState(REACT_PASSIVE);
            isProtected = false;
        }

        void DoAction(int32 const action) override
        {
            if (action == ACTION_AMBER_VOLLEY)
            {
                DoCast(SPELL_AMBER_VOLLEY);
                isProtected = true;
                events.ScheduleEvent(EVENT_AMBER_VOLLEY, 2000);
            }
        }

        uint32 GetData(uint32 p_Type) const override
        {
            if (p_Type == TYPE_AMBER_USED)
                return isProtected ? 1 : 0;

            return 0;
        }

        void UpdateAI(const uint32 diff) override
        {
            if (pInstance)
            {
                if (pInstance->IsWipe())
                {
                    me->RemoveAllAuras();
                    me->SetFullHealth();
                    Reset();
                    return;
                }
            }

            events.Update(diff);

            if (events.ExecuteEvent() == EVENT_AMBER_VOLLEY)
            {
                std::list<Player*> playerList;
                GetPlayerListInGrid(playerList, me, 100.0f);

                if (!playerList.empty())
                {
                    // Pick a random player to target
                    Trinity::Containers::RandomResize(playerList, 1);
                    me->CastSpell(playerList.front(), SPELL_AMBER_VOLLEY_MISSILE, true);
                    events.ScheduleEvent(EVENT_AMBER_VOLLEY, IsLFR() ? 3000 : Is25ManRaid() ? 2000 : 5000);
                }
            }
            // No melee attack
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new mob_srathik_ambercallerAI(creature);
    }
};

Position atriumPath[9] =
{
    { -2429.16f, 431.90f, 554.52f, 0.0f },
    { -2417.22f, 456.37f, 554.52f, 0.0f },
    { -2417.60f, 498.18f, 554.52f, 0.0f },
    { -2436.80f, 524.51f, 554.52f, 0.0f },
    { -2451.77f, 531.64f, 554.52f, 0.0f },
    { -2504.65f, 534.39f, 554.52f, 0.0f },
    { -2538.70f, 508.50f, 554.52f, 0.0f },
    { -2543.00f, 454.06f, 554.52f, 0.0f },
    { -2528.75f, 432.90f, 554.52f, 0.0f }
};

// 64902 - Kor'thik Fleshrender
class mob_korthik_fleshrender : public CreatureScript
{
public:
    mob_korthik_fleshrender() : CreatureScript("mob_korthik_fleshrender") { }

    struct mob_korthik_fleshrenderAI : ScriptedAI
    {
        mob_korthik_fleshrenderAI(Creature* creature) : ScriptedAI(creature) { }

        EventMap events;
        uint8 point;
        int8 direction;
        uint32 walkTimer;

        void Reset() override
        {
            events.Reset();
            me->SetVirtualItem(0, EQUIP_TAYAK_MELJARAK);
            point = me->GetPositionY() < 460.0f ? 0 : 1;
            direction = -1;
            me->SetWalk(true);
            if (me->IsAlive())
                me->GetMotionMaster()->MovePoint(point + 1, atriumPath[point]);
            walkTimer = 0;
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type != POINT_MOTION_TYPE || !id)
                return;

            walkTimer = 1;

            point += direction;
            // Turning back
            if (point < 0 || point > 8)
            {
                direction *= -1;
                point += 2 * direction;
            }
        }

        void EnterCombat(Unit* /*attacker*/) override
        {
            events.ScheduleEvent(EVENT_GREVIOUS_WHIRL, 5000);
            events.ScheduleEvent(EVENT_MORTAL_REND,    12000);
        }

        void UpdateAI(const uint32 diff) override
        {
            if (walkTimer)
            {
                if (walkTimer > diff)
                    walkTimer -= diff;
                else
                {
                    me->GetMotionMaster()->MovePoint(point + 1, atriumPath[point]);
                    walkTimer = 0;
                }
            }

            if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_GREVIOUS_WHIRL:
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                            me->CastSpell(target, SPELL_GREVIOUS_WHIRL, true);
                        events.ScheduleEvent(EVENT_GREVIOUS_WHIRL, 20000);
                        break;
                    }
                    case EVENT_MORTAL_REND:
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                            me->CastSpell(target, SPELL_MORTAL_REND, true);
                        events.ScheduleEvent(EVENT_MORTAL_REND, 20000);
                        break;
                    }
                    default:
                        break;
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new mob_korthik_fleshrenderAI(creature);
    }

};

// 63569 - Amber Searsting
class mob_amber_searsting : public CreatureScript
{
public:
    mob_amber_searsting() : CreatureScript("mob_amber_searsting") { }

    struct mob_amber_searstingAI : public ScriptedAI
    {
        mob_amber_searstingAI(Creature* creature) : ScriptedAI(creature) { }

        EventMap events;

        void Reset() override
        {
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            events.ScheduleEvent(EVENT_BURNING_STING, 8000);
            events.ScheduleEvent(EVENT_SEARING_SLASH, 4000);
        }

        void UpdateAI(const uint32 diff) override
        {
            if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_BURNING_STING:
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                            me->CastSpell(target, SPELL_BURNING_STING, true);
                        events.ScheduleEvent(EVENT_BURNING_STING, 15000);
                        break;
                    }
                    case EVENT_SEARING_SLASH:
                    {
                        DoCast(SPELL_SEARING_SLASH);
                        events.ScheduleEvent(EVENT_SEARING_SLASH, 12000);
                        break;
                    }
                    default:
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new mob_amber_searstingAI(creature);
    }
};

// 63568 - Amber-Ridden Mushan
class mob_amberridden_mushan : public CreatureScript
{
public:
    mob_amberridden_mushan() : CreatureScript("mob_amberridden_mushan") { }

    struct mob_amberridden_mushanAI : public ScriptedAI
    {
        mob_amberridden_mushanAI(Creature* creature) : ScriptedAI(creature) { }

        EventMap events;

        void Reset() override
        {
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            events.ScheduleEvent(EVENT_AMBER_SPEW, 9000);
            events.ScheduleEvent(EVENT_SLAM,       4000);
        }

        void UpdateAI(const uint32 diff) override
        {
            if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_AMBER_SPEW:
                    {
                        DoCast(SPELL_AMBER_SPEW);
                        events.ScheduleEvent(EVENT_AMBER_SPEW, 10000);
                        break;
                    }
                    case EVENT_SLAM:
                    {
                        DoCast(SPELL_SLAM);
                        events.ScheduleEvent(EVENT_SLAM, 22000);
                        break;
                    }
                default:
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new mob_amberridden_mushanAI(creature);
    }
};

// 63570 - Sra'thik Pool-Tender
class mob_srathik_pooltender : public CreatureScript
{
public:
    mob_srathik_pooltender() : CreatureScript("mob_srathik_pooltender") { }

    struct mob_srathik_pooltenderAI : public ScriptedAI
    {
        mob_srathik_pooltenderAI(Creature* creature) : ScriptedAI(creature) { }

        EventMap events;

        void Reset() override
        {
            events.Reset();
            DoCast(SPELL_AMBER_EMANATION);
            events.ScheduleEvent(EVENT_AMBER_INFUSION, 20000);
        }

        void UpdateAI(const uint32 diff) override
        {
            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            events.Update(diff);

            if (events.ExecuteEvent() == EVENT_AMBER_INFUSION)
            {
                DoCast(SPELL_AMBER_INFUSION);
                events.ScheduleEvent(EVENT_AMBER_INFUSION, urand(25000, 30000));
            }

            if (UpdateVictim())
                DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new mob_srathik_pooltenderAI(creature);
    }
};

void ShekZeerTrashBuff(Creature* me)
{
    uint32 addEntries[3] = {NPC_SETTHIK_WINDBLADE_TRASH, NPC_KORTHIK_WARSINGER, NPC_ZARTHIK_AUGURER};

    bool buff = false;
    uint8 stacks = 0;
    for (uint8 i = 0; i < 3; ++i)
    {
        std::list<Creature*> addList;
        GetCreatureListWithEntryInGrid(addList, me, addEntries[i], 8.0f);

        // Retaining only alive mobs who aren't me
        if (addList.empty())
            continue;

        for (Creature* mob : addList)
        {
            if (mob->IsAlive() && mob != me)
            {
                if (!buff)
                    buff = true;
                ++stacks;
            }
        }
    }

    // If buff should be applied, we have to check that we have the right number of stacks
    if (buff)
    {
        if (Aura* aura = me->AddAura(SPELL_BAND_OF_VALOR, me))
        {
            if (aura->GetStackAmount() != stacks)
                aura->SetStackAmount(stacks);
        }
    }

    // Remove aura if applied and there's no add around
    else if (!buff && me->HasAura(SPELL_BAND_OF_VALOR))
        me->RemoveAura(SPELL_BAND_OF_VALOR);
}

// Returns true if no trash remain before Shek'zeer, else returns false
bool ShekZeerCheckTrash(Creature* me)
{
    if (!GetClosestCreatureWithEntry(me, NPC_ZARTHIK_AUGURER, 200.0f))
    {
        if (!GetClosestCreatureWithEntry(me, NPC_SETTHIK_WINDBLADE_TRASH, 200.0f))
        {
            if (!GetClosestCreatureWithEntry(me, NPC_KORTHIK_WARSINGER, 200.0f))
                return true;
        }
    }

    return false;
}

// 64454 - Zar'thik Augurer
class mob_zarthik_augurer : public CreatureScript
{
public:
    mob_zarthik_augurer() : CreatureScript("mob_zarthik_augurer") { }

    struct mob_zarthik_augurerAI : public ScriptedAI
    {
        mob_zarthik_augurerAI(Creature* creature) : ScriptedAI(creature)
        {
            pInstance = creature->GetInstanceScript();
        }

        EventMap events;
        InstanceScript* pInstance;

        void Reset() override
        {
            events.Reset();
            me->SetVirtualItem(0, EQUIP_ZORLOK);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            events.ScheduleEvent(EVENT_TOXIC_HIVEBOMB, urand(2000, 4000));
            events.ScheduleEvent(EVENT_TOXIC_SPEW,     urand(15000, 20000));
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (ShekZeerCheckTrash(me))
            {
                if (pInstance)
                {
                    if (Creature* Shekzeer = pInstance->GetCreature(NPC_SHEKZEER))
                        Shekzeer->AI()->DoAction(ACTION_SHEKZEER_COMBAT);
                }
            }
        }

        void UpdateAI(const uint32 diff) override
        {
            if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                return;

            // Buff
            ShekZeerTrashBuff(me);

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_TOXIC_HIVEBOMB:
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                            me->CastSpell(target, SPELL_TOXIC_HIVEBOMB, true);
                        events.ScheduleEvent(EVENT_TOXIC_HIVEBOMB, urand(2000, 4000));
                        break;
                    }
                    case EVENT_TOXIC_SPEW:
                    {
                        DoCast(SPELL_TOXIC_SPEW);
                        events.ScheduleEvent(EVENT_TOXIC_SPEW, urand(15000, 20000));
                        break;
                    }
                    default:
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new mob_zarthik_augurerAI(creature);
    }
};

// 64453 - Set'thik Windblade
class mob_setthik_windblade : public CreatureScript
{
public:
    mob_setthik_windblade() : CreatureScript("mob_setthik_windblade") { }

    struct mob_setthik_windbladeAI : public ScriptedAI
    {
        mob_setthik_windbladeAI(Creature* creature) : ScriptedAI(creature)
        {
            pInstance = creature->GetInstanceScript();
        }

        EventMap events;
        InstanceScript* pInstance;

        void Reset() override
        {
            events.Reset();

            me->SetVirtualItem(0, EQUIP_TRASH_5);
            me->SetVirtualItem(2,EQUIP_TRASH_5);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            events.ScheduleEvent(EVENT_DISPATCH, 7000);
            events.ScheduleEvent(EVENT_SONIC_BLADE, 15000);
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (ShekZeerCheckTrash(me))
            {
                if (pInstance)
                {
                    if (Creature* Shekzeer = pInstance->GetCreature(NPC_SHEKZEER))
                        Shekzeer->AI()->DoAction(ACTION_SHEKZEER_COMBAT);
                }
            }
        }

        void UpdateAI(const uint32 diff) override
        {
            if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                return;

            // Buff
            ShekZeerTrashBuff(me);

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_DISPATCH:
                    {
                        me->CastSpell(me, SPELL_DISPATCH, true);
                        events.ScheduleEvent(EVENT_DISPATCH, 30000);
                        break;
                    }
                    case EVENT_SONIC_BLADE:
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                            me->CastSpell(target, SPELL_SONIC_BLADE, true);
                        events.ScheduleEvent(EVENT_SONIC_BLADE, 30000);
                        break;
                    }
                    default:
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new mob_setthik_windbladeAI(creature);
    }
};

// 64458 - Kor'thik Warsinger
class mob_korthik_warsinger : public CreatureScript
{
public:
    mob_korthik_warsinger() : CreatureScript("mob_korthik_warsinger") { }

    struct mob_korthik_warsingerAI : ScriptedAI
    {
        mob_korthik_warsingerAI(Creature* creature) : ScriptedAI(creature)
        {
            pInstance = creature->GetInstanceScript();
        }

        EventMap events;
        InstanceScript* pInstance;

        void Reset() override
        {
            events.Reset();
            me->SetVirtualItem(0, EQUIP_TRASH_5);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            events.ScheduleEvent(EVENT_CRY_HAVOC, 6000);
            events.ScheduleEvent(EVENT_FRENZIED_ASSAULT, 12000);
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (ShekZeerCheckTrash(me))
            {
                if (pInstance)
                {
                    if (Creature* Shekzeer = pInstance->GetCreature(NPC_SHEKZEER))
                        Shekzeer->AI()->DoAction(ACTION_SHEKZEER_COMBAT);
                }
            }
        }

        void UpdateAI(const uint32 diff) override
        {
            if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                return;

            // Buff
            ShekZeerTrashBuff(me);

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_CRY_HAVOC:
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                            me->CastSpell(target, SPELL_CRY_HAVOC, true);
                        events.ScheduleEvent(EVENT_CRY_HAVOC, urand(15000, 20000));
                        break;
                    }
                    case EVENT_FRENZIED_ASSAULT:
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                            me->CastSpell(target, SPELL_FRENZIED_ASSAULT, true);
                        events.ScheduleEvent(EVENT_FRENZIED_ASSAULT, 30000);
                        break;
                    }
                    default:
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new mob_korthik_warsingerAI(creature);
    }
};

// 123421 - Vital Strikes
class spell_vital_strikes : public SpellScriptLoader
{
    public:
        spell_vital_strikes() : SpellScriptLoader("spell_vital_strikes") { }

        class spell_vital_strikes_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_vital_strikes_AuraScript);

            void OnProc(AuraEffect const* /*p_AurEff*/, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                if (!GetCaster())
                    return;

                int32 bp = (eventInfo.GetDamageInfo()->GetDamage() / 2) / 6;

                if (Unit* victim = eventInfo.GetProcTarget())
                {
                    if (!victim->HasAura(SPELL_ARTERIAL_SPIRIT))
                        GetCaster()->CastCustomSpell(victim, SPELL_ARTERIAL_SPIRIT, &bp, NULL, NULL, true);
                }
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_vital_strikes_AuraScript::OnProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_vital_strikes_AuraScript();
        }
};

void AddSC_heart_of_fear()
{
    // Trashes
    new mob_kor_thik_slicer();          // 63048 - Kor'thik Slicer
    new mob_kor_thik_extremist();       // 63036 - Kor'thik extremist
    new mob_sra_thik_shield_master();   // 63032 - Sra'thik Shield Master
    new mob_set_thik_swiftblade();      // 63049 - Set'thik Swiftblade
    new mob_zar_thik_supplicant();      // 67177 - 66181 - 63853 - Zar'thik Supplicant
    new mob_enslaved_bonesmasher();     // 63030 - Enslaved Bonesmasher
    new mob_set_thik_tempest();         // 64358 - Set'thik Tempest
    new mob_set_thik_fanatic();         // 63031 - Set'thik Fanatic
    new mob_set_thik_zephyrian();       // 63593 - Set'thik Zephyrian
    new mob_set_thik_gale_slicer();     // 64353 - Set'thik Gale-Slicer
    new mob_instructor_kli_thak();      // 64338 - Instructor Kli'thak <Keeper of Wind Step>
    new mob_instructor_tak_thok();      // 64339 - Instructor Tak'thok <Keeper of Overwhelming Assault>
    new mob_instructor_maltik();        // 64340 - Instructor Maltik <Keeper of Unseen Strike>
    new mob_instructor_zarik();         // 64341 - Instructor Zarik <Keeper of Tempest Slash>
    new mob_zar_thik_zealot();          // 63035 - Zar'thik Zealot
    new mob_kor_thik_swarmer();         // 64357 - Kor'thik Swarmer
    new mob_set_thik_gustwing();        // 63592 - Set'thik Gustwing
    new mob_coagulated_amber();         // 63597 / 63594 - Coagulated Amber
    new mob_kor_thik_silentwing();      // 64355 - Kor'thik Silentwing
    new mob_zephyr();                   // 63599 - Zephyr (summoned by Set'thik Zephyrian - 63593)
    new mob_korthik_swarmguard();       // 64916 - Kor'thik Swarmguard
    new mob_srathik_ambercaller();      // 64917 - Sra'thik Ambercaller
    new mob_korthik_fleshrender();      // 64902 - Kor'thik Fleshrender
    new mob_amber_searsting();          // 63569 - Amber Searsting
    new mob_amberridden_mushan();       // 63568 - Amber-Ridden Mushan
    new mob_srathik_pooltender();       // 63570 - Sra'thik Pool-Tender
    new mob_setthik_windblade();        // 64453 - Set'thik Windblade
    new mob_zarthik_augurer();          // 64454 - Zar'thik Augurer
    new mob_korthik_warsinger();        // 64458 - Kor'thik Warsinger
    new spell_vital_strikes();          // 123421 - Vital Strikes
}
