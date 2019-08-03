/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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
#include "InstanceScript.h"
#include "Map.h"
#include "ObjectAccessor.h"
#include "PassiveAI.h"
#include "pit_of_saron.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
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

bool ScheduledIcicleSummons::Execute(uint64 /*time*/, uint32 /*diff*/)
{
    if (roll_chance_i(12))
    {
        _trigger->CastSpell(_trigger, SPELL_ICICLE_SUMMON, true);
        _trigger->m_Events.AddEvent(new ScheduledIcicleSummons(_trigger), _trigger->m_Events.CalculateTime(urand(20000, 35000)));
    }
    else
        _trigger->m_Events.AddEvent(new ScheduledIcicleSummons(_trigger), _trigger->m_Events.CalculateTime(urand(1000, 20000)));

    return true;
}

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

            void JustEngagedWith(Unit* /*who*/) override
            {
                _events.ScheduleEvent(EVENT_FIREBALL, 4s);
                _events.ScheduleEvent(EVENT_TACTICAL_BLINK, 15s);
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
            return GetPitOfSaronAI<npc_ymirjar_flamebearerAI>(creature);
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

            void JustEngagedWith(Unit* /*who*/) override
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
            return GetPitOfSaronAI<npc_iceborn_protodrakeAI>(creature);
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

            void JustEngagedWith(Unit* who) override
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
            return GetPitOfSaronAI<npc_geist_ambusherAI>(creature);
        }
};

class npc_pit_of_saron_icicle : public CreatureScript
{
    public:
        npc_pit_of_saron_icicle() : CreatureScript("npc_pit_of_saron_icicle") { }

        struct npc_pit_of_saron_icicleAI : public PassiveAI
        {
            npc_pit_of_saron_icicleAI(Creature* creature) : PassiveAI(creature)
            {
                me->SetDisplayId(me->GetCreatureTemplate()->Modelid1);
            }

            void IsSummonedBy(WorldObject* summoner) override
            {
                _summonerGUID = summoner->GetGUID();

                _scheduler.Schedule(Milliseconds(3650), [this](TaskContext /*context*/)
                {
                    DoCastSelf(SPELL_ICICLE_FALL_TRIGGER, true);
                    DoCastSelf(SPELL_ICICLE_FALL_VISUAL);

                    if (Unit* caster = ObjectAccessor::GetUnit(*me, _summonerGUID))
                        caster->RemoveDynObject(SPELL_ICICLE_SUMMON);
                });
            }

            void UpdateAI(uint32 diff) override
            {
                _scheduler.Update(diff);
            }

        private:
            TaskScheduler _scheduler;
            ObjectGuid _summonerGUID;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetPitOfSaronAI<npc_pit_of_saron_icicleAI>(creature);
        }
};


class spell_pos_ice_shards : public SpellScriptLoader
{
    public:
        spell_pos_ice_shards() : SpellScriptLoader("spell_pos_ice_shards") { }

        class spell_pos_ice_shards_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pos_ice_shards_SpellScript);

            bool Load() override
            {
                // This script should execute only in Pit of Saron
                return InstanceHasScript(GetCaster(), PoSScriptName);
            }

            void HandleScriptEffect(SpellEffIndex /*effIndex*/)
            {
                if (GetHitPlayer())
                    GetCaster()->GetInstanceScript()->SetData(DATA_ICE_SHARDS_HIT, 1);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_pos_ice_shards_SpellScript::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_pos_ice_shards_SpellScript();
        }
};

enum TyrannusEventCavernEmote
{
    SAY_TYRANNUS_CAVERN_ENTRANCE = 3
};

class at_pit_cavern_entrance : public AreaTriggerScript
{
    public:
        at_pit_cavern_entrance() : AreaTriggerScript("at_pit_cavern_entrance") { }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/) override
        {
            if (InstanceScript* instance = player->GetInstanceScript())
            {
                if (instance->GetData(DATA_CAVERN_ACTIVE))
                    return true;

                instance->SetData(DATA_CAVERN_ACTIVE, 1);

                if (Creature* tyrannus = ObjectAccessor::GetCreature(*player, instance->GetGuidData(DATA_TYRANNUS_EVENT)))
                    tyrannus->AI()->Talk(SAY_TYRANNUS_CAVERN_ENTRANCE);
            }
            return true;
        }
};

class at_pit_cavern_end : public AreaTriggerScript
{
public:
    at_pit_cavern_end() : AreaTriggerScript("at_pit_cavern_end") { }

    bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/) override
    {
        if (InstanceScript* instance = player->GetInstanceScript())
        {
            instance->SetData(DATA_CAVERN_ACTIVE, 0);

            if (!instance->GetData(DATA_ICE_SHARDS_HIT))
                instance->DoUpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET, SPELL_DONT_LOOK_UP_ACHIEV_CREDIT, 0, player);
        }

        return true;
    }
};

void AddSC_pit_of_saron()
{
    new npc_ymirjar_flamebearer();
    new npc_iceborn_protodrake();
    new npc_geist_ambusher();
    new npc_pit_of_saron_icicle();
    new spell_pos_ice_shards();
    new at_pit_cavern_entrance();
    new at_pit_cavern_end();
}
