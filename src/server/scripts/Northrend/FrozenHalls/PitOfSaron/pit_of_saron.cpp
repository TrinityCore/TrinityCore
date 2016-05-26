/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "pit_of_saron.h"
#include "Vehicle.h"

enum Spells
{
    SPELL_FIREBALL              = 69583, //Ymirjar Flamebearer
    SPELL_HELLFIRE              = 69586,
    SPELL_TACTICAL_BLINK        = 69584,
    SPELL_FROST_BREATH          = 69527, //Iceborn Proto-Drake
    SPELL_LEAPING_FACE_MAUL     = 69504, // Geist Ambusher
};

enum Events
{
    // Ymirjar Flamebearer
    EVENT_FIREBALL              = 1,
    EVENT_TACTICAL_BLINK        = 2,
};

class npc_ymirjar_flamebearer : public CreatureScript
{
    public:
        npc_ymirjar_flamebearer() : CreatureScript("npc_ymirjar_flamebearer") { }

        struct npc_ymirjar_flamebearerAI: public ScriptedAI
        {
            npc_ymirjar_flamebearerAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            void Reset() override
            {
                _events.Reset();
            }

            void EnterCombat(Unit* /*who*/) override
            {
                _events.ScheduleEvent(EVENT_FIREBALL, 4000);
                _events.ScheduleEvent(EVENT_TACTICAL_BLINK, 15000);
            }

            void UpdateAI(uint32 diff) override
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

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_ymirjar_flamebearerAI(creature);
        }
};

class npc_iceborn_protodrake : public CreatureScript
{
    public:
        npc_iceborn_protodrake() : CreatureScript("npc_iceborn_protodrake") { }

        struct npc_iceborn_protodrakeAI: public ScriptedAI
        {
            npc_iceborn_protodrakeAI(Creature* creature) : ScriptedAI(creature)
            {
                Initialize();
            }

            void Initialize()
            {
                _frostBreathCooldown = 5000;
            }

            void Reset() override
            {
                Initialize();
            }

            void EnterCombat(Unit* /*who*/) override
            {
                if (Vehicle* _vehicle = me->GetVehicleKit())
                    _vehicle->RemoveAllPassengers();
            }

            void UpdateAI(uint32 diff) override
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
            uint32 _frostBreathCooldown;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_iceborn_protodrakeAI(creature);
        }
};

class npc_geist_ambusher : public CreatureScript
{
    public:
        npc_geist_ambusher() : CreatureScript("npc_geist_ambusher") { }

        struct npc_geist_ambusherAI: public ScriptedAI
        {
            npc_geist_ambusherAI(Creature* creature) : ScriptedAI(creature)
            {
                Initialize();
            }

            void Initialize()
            {
                _leapingFaceMaulCooldown = 9000;
            }

            void Reset() override
            {
                Initialize();
            }

            void EnterCombat(Unit* who) override
            {
                if (who->GetTypeId() != TYPEID_PLAYER)
                    return;

                // the max range is determined by aggro range
                if (me->GetDistance(who) > 5.0f)
                    DoCast(who, SPELL_LEAPING_FACE_MAUL);
            }

            void UpdateAI(uint32 diff) override
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

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_geist_ambusherAI(creature);
        }
};

class spell_trash_npc_glacial_strike : public SpellScriptLoader
{
    public:
        spell_trash_npc_glacial_strike() : SpellScriptLoader("spell_trash_npc_glacial_strike") { }

        class spell_trash_npc_glacial_strike_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_trash_npc_glacial_strike_AuraScript);

            void PeriodicTick(AuraEffect const* /*aurEff*/)
            {
                if (GetTarget()->IsFullHealth())
                {
                    GetTarget()->RemoveAura(GetId(), ObjectGuid::Empty, 0, AURA_REMOVE_BY_ENEMY_SPELL);
                    PreventDefaultAction();
                }
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_trash_npc_glacial_strike_AuraScript::PeriodicTick, EFFECT_2, SPELL_AURA_PERIODIC_DAMAGE_PERCENT);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_trash_npc_glacial_strike_AuraScript();
        }
};

void AddSC_pit_of_saron()
{
    new npc_ymirjar_flamebearer();
    new npc_iceborn_protodrake();
    new npc_geist_ambusher();
    new spell_trash_npc_glacial_strike();
}
