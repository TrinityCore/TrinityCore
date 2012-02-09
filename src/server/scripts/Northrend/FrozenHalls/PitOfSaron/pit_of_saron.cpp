/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptPCH.h"
#include "pit_of_saron.h"
#include "Vehicle.h"

enum eSpells
{
    SPELL_FIREBALL              = 69583, //Ymirjar Flamebearer
    SPELL_HELLFIRE              = 69586,
    SPELL_TACTICAL_BLINK        = 69584,
    SPELL_FROST_BREATH          = 69527, //Iceborn Proto-Drake
    SPELL_BLINDING_DIRT         = 70302, //Wrathbone Laborer
    SPELL_PUNCTURE_WOUND        = 70278,
    SPELL_SHOVELLED             = 69572,
    SPELL_LEAPING_FACE_MAUL     = 69504, // Geist Ambusher
};

enum eEvents
{
    // Ymirjar Flamebearer
    EVENT_FIREBALL              = 1,
    EVENT_TACTICAL_BLINK        = 2,

    //Wrathbone Laborer
    EVENT_BLINDING_DIRT         = 3,
    EVENT_PUNCTURE_WOUND        = 4,
    EVENT_SHOVELLED             = 5,
};

class mob_ymirjar_flamebearer : public CreatureScript
{
    public:
        mob_ymirjar_flamebearer() : CreatureScript("mob_ymirjar_flamebearer") { }

        struct mob_ymirjar_flamebearerAI: public ScriptedAI
        {
            mob_ymirjar_flamebearerAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            void Reset()
            {
                _events.Reset();
            }

            void EnterCombat(Unit* /*who*/)
            {
                _events.ScheduleEvent(EVENT_FIREBALL, 4000);
                _events.ScheduleEvent(EVENT_TACTICAL_BLINK, 15000);
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                _events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_FIREBALL:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                DoCast(target, SPELL_FIREBALL);
                            _events.RescheduleEvent(EVENT_FIREBALL, 5000);
                            break;
                        case EVENT_TACTICAL_BLINK:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                DoCast(target, SPELL_TACTICAL_BLINK);
                            DoCast(me, SPELL_HELLFIRE);
                            _events.RescheduleEvent(EVENT_TACTICAL_BLINK, 12000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            EventMap _events;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_ymirjar_flamebearerAI(creature);
        }
};

class mob_iceborn_protodrake : public CreatureScript
{
    public:
        mob_iceborn_protodrake() : CreatureScript("mob_iceborn_protodrake") { }

        struct mob_iceborn_protodrakeAI: public ScriptedAI
        {
            mob_iceborn_protodrakeAI(Creature* creature) : ScriptedAI(creature), _vehicle(creature->GetVehicleKit())
            {
                ASSERT(_vehicle);
            }

            void Reset()
            {
                _frostBreathCooldown = 5000;
            }

            void EnterCombat(Unit* /*who*/)
            {
                _vehicle->RemoveAllPassengers();
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                if (_frostBreathCooldown < diff)
                {
                    DoCastVictim(SPELL_FROST_BREATH);
                    _frostBreathCooldown = 10000;
                }
                else
                    _frostBreathCooldown -= diff;

                DoMeleeAttackIfReady();
            }

        private:
            Vehicle* _vehicle;
            uint32 _frostBreathCooldown;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_iceborn_protodrakeAI(creature);
        }
};

class mob_wrathbone_laborer : public CreatureScript
{
    public:
        mob_wrathbone_laborer() : CreatureScript("mob_wrathbone_laborer") { }

        struct mob_wrathbone_laborerAI: public ScriptedAI
        {
            mob_wrathbone_laborerAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            void Reset()
            {
                _events.Reset();
            }

            void EnterCombat(Unit* /*who*/)
            {
                _events.ScheduleEvent(EVENT_BLINDING_DIRT, 8000);
                _events.ScheduleEvent(EVENT_PUNCTURE_WOUND, 9000);
                _events.ScheduleEvent(EVENT_SHOVELLED, 5000);
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                _events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_BLINDING_DIRT:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 10.0f, true))
                                DoCast(target, SPELL_BLINDING_DIRT);
                            _events.RescheduleEvent(EVENT_BLINDING_DIRT, 10000);
                            return;
                        case EVENT_PUNCTURE_WOUND:
                            DoCastVictim(SPELL_PUNCTURE_WOUND);
                            _events.RescheduleEvent(EVENT_PUNCTURE_WOUND, 9000);
                            return;
                        case EVENT_SHOVELLED:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, -5.0f))
                                DoCast(target, SPELL_SHOVELLED);
                            _events.RescheduleEvent(EVENT_SHOVELLED, 7000);
                            return;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            EventMap _events;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_wrathbone_laborerAI(creature);
        }
};

class mob_geist_ambusher : public CreatureScript
{
    public:
        mob_geist_ambusher() : CreatureScript("mob_geist_ambusher") { }

        struct mob_geist_ambusherAI: public ScriptedAI
        {
            mob_geist_ambusherAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            void Reset()
            {
                _leapingFaceMaulCooldown = 9000;
            }

            void MoveInLineOfSight(Unit* who)
            {
                if (who->GetTypeId() != TYPEID_PLAYER)
                    return;

                if (me->IsWithinDistInMap(who, 30.0f))
                    DoCast(who, SPELL_LEAPING_FACE_MAUL);
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                if (_leapingFaceMaulCooldown < diff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 5.0f, true))
                        DoCast(target, SPELL_LEAPING_FACE_MAUL);
                    _leapingFaceMaulCooldown = urand(9000, 14000);
                }
                else
                    _leapingFaceMaulCooldown -= diff;

                DoMeleeAttackIfReady();
            }

        private:
            uint32 _leapingFaceMaulCooldown;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_geist_ambusherAI(creature);
        }
};

class spell_trash_mob_glacial_strike : public SpellScriptLoader
{
    public:
        spell_trash_mob_glacial_strike() : SpellScriptLoader("spell_trash_mob_glacial_strike") { }

        class spell_trash_mob_glacial_strike_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_trash_mob_glacial_strike_AuraScript);

            void PeriodicTick(AuraEffect const* /*aurEff*/)
            {
                if (GetTarget()->IsFullHealth())
                {
                    GetTarget()->RemoveAura(GetId(), AURA_REMOVE_BY_ENEMY_SPELL);
                    PreventDefaultAction();
                }
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_trash_mob_glacial_strike_AuraScript::PeriodicTick, EFFECT_2, SPELL_AURA_PERIODIC_DAMAGE_PERCENT);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_trash_mob_glacial_strike_AuraScript();
        }
};

void AddSC_pit_of_saron()
{
    new mob_ymirjar_flamebearer();
    new mob_wrathbone_laborer();
    new mob_iceborn_protodrake();
    new mob_geist_ambusher();
    new spell_trash_mob_glacial_strike();
}
