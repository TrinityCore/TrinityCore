/*
* Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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

#include "AreaTriggerAI.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "neltharions_lair.h"
#include "CreatureTextMgr.h"

// 96247
class mob_vileshard_crawler : public CreatureScript
{
public:
    mob_vileshard_crawler() : CreatureScript("mob_vileshard_crawler") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new mob_vileshard_crawler_AI(creature);
    }

    enum eSpells
    {
        SPELL_ACID_SPLATTER = 183401
    };

    struct mob_vileshard_crawler_AI : public ScriptedAI
    {
        mob_vileshard_crawler_AI(Creature* creature) : ScriptedAI(creature) {}
        
        void JustDied(Unit* killer) override
        {
            me->CastSpell(killer, SPELL_ACID_SPLATTER, false);
        }
    };
};

class at_acid_splatter : public AreaTriggerEntityScript
{
public:
    at_acid_splatter() : AreaTriggerEntityScript("at_acid_splatter") { }

    struct at_acid_splatterAI : AreaTriggerAI
    {
        at_acid_splatterAI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

        void OnUnitEnter(Unit* unit) override
        {
            if (unit)
                unit->AddAura(183407, unit);
        }

        void OnUnitExit(Unit* unit) override
        {
            if (unit && unit->HasAura(183407))
                unit->RemoveAura(183407);
        }
    };

    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
    {
        return new at_acid_splatterAI(areatrigger);
    }
};

// 98406
class mob_embershard_scorpion : public CreatureScript
{
public:
    mob_embershard_scorpion() : CreatureScript("mob_embershard_scorpion") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new mob_embershard_scorpion_AI(creature);
    }

    enum eEvents
    {
        EVENT_IMPALING_SHARD = 1
    };

    enum eSpells
    {
        SPELL_IMPALING_SHARD = 193941
    };

    struct mob_embershard_scorpion_AI : public ScriptedAI
    {
        mob_embershard_scorpion_AI(Creature* creature) : ScriptedAI(creature) {}

        EventMap events;

        void EnterCombat(Unit* unit) override
        {
            events.ScheduleEvent(EVENT_IMPALING_SHARD, 2 * IN_MILLISECONDS);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (events.ExecuteEvent() == EVENT_IMPALING_SHARD)
            {
                if (me->GetVictim())
                    me->CastSpell(me->GetVictim(), SPELL_IMPALING_SHARD, false);
                events.ScheduleEvent(EVENT_IMPALING_SHARD, urand(8,12) * IN_MILLISECONDS);
            }

            DoMeleeAttackIfReady();
        }
    };
};

class mob_trigger_start_waterfall : public CreatureScript
{
public:
    mob_trigger_start_waterfall() : CreatureScript("mob_trigger_start_waterfall") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new mob_trigger_start_waterfall_AI(creature);
    }

    struct mob_trigger_start_waterfall_AI : public ScriptedAI
    {
        mob_trigger_start_waterfall_AI(Creature* creature) : ScriptedAI(creature) 
        {
            me->SetVisible(false);
        }
        
        void MoveInLineOfSight(Unit* who) override
        {
            if (me->GetMapId() == 1458 && who->GetTypeId() == TYPEID_PLAYER && !who->ToPlayer()->IsGameMaster() && me->IsWithinDistInMap(who, 150.0f))
            {
                if (who->GetPositionZ() < 350 && who->GetPositionZ() > 114 && !who->HasAura(SPELL_FALLING_VISUAL))
                {
                    who->CastSpell(who, SPELL_FALLING_VISUAL, false);
                    who->SetCanFly(true);
                    float allSpeed = 4.0f;
                    who->SetSpeedRate(MOVE_WALK, allSpeed);
                    who->SetSpeedRate(MOVE_RUN, allSpeed);
                    who->SetSpeedRate(MOVE_SWIM, allSpeed);
                    who->SetSpeedRate(MOVE_FLIGHT, allSpeed);
                    
                    std::vector<uint32> destinations;
                    destinations.push_back(TAXI_NODE_FALLING_END_POINT);
                    destinations.push_back(TAXI_NODE_FALLING_START_POINT);
                    who->ToPlayer()->m_taxi.SetTaxiDestination(destinations);
                    who->ToPlayer()->SaveToDB();
                    who->ToPlayer()->ContinueTaxiFlight();
                }
                
                if (who->GetPositionZ() < 112 && who->HasAura(SPELL_FALLING_VISUAL))
                {
                    who->RemoveAura(SPELL_FALLING_VISUAL);
                    float allSpeed = 1.0f;
                    who->SetSpeedRate(MOVE_WALK, allSpeed);
                    who->SetSpeedRate(MOVE_RUN, allSpeed);
                    who->SetSpeedRate(MOVE_SWIM, allSpeed);
                    who->SetSpeedRate(MOVE_FLIGHT, allSpeed);
                    who->SetCanFly(false);
                    who->ToPlayer()->m_taxi.ClearTaxiDestinations();
                    who->ToPlayer()->SaveToDB();
                }
                
            }
        }
    };
};

class mob_neltharionslair_trigger : public CreatureScript
{
public:
    mob_neltharionslair_trigger() : CreatureScript("mob_neltharionslair_trigger") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new mob_neltharionslair_trigger_AI(creature);
    }

    struct mob_neltharionslair_trigger_AI : public ScriptedAI
    {
        mob_neltharionslair_trigger_AI(Creature* creature) : ScriptedAI(creature) 
        {
            me->SetVisible(false);
        }
        
        void MoveInLineOfSight(Unit* who) override
        {
            if (me->GetMapId() == 1458 && me->GetAreaId() ==  8339 && who->GetTypeId() == TYPEID_PLAYER && !who->ToPlayer()->IsGameMaster() && me->IsWithinDistInMap(who, 20.0f))
            {
                float allSpeed = 1.0f;
                who->ToPlayer()->SetSpeedRate(MOVE_WALK, allSpeed);
                who->ToPlayer()->SetSpeedRate(MOVE_RUN, allSpeed);
                who->ToPlayer()->SetSpeedRate(MOVE_SWIM, allSpeed);
                who->ToPlayer()->SetSpeedRate(MOVE_FLIGHT, allSpeed);
                who->ToPlayer()->m_taxi.ClearTaxiDestinations();
                who->ToPlayer()->SaveToDB();
            }
        }
    };
};

// 91006
class mob_rockback_gnasher : public CreatureScript
{
public:
    mob_rockback_gnasher() : CreatureScript("mob_rockback_gnasher") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new mob_rockback_gnasher_AI(creature);
    }

    enum eEvents
    {
        EVENT_BONE_CHOMP = 1,
        EVENT_STONE_GAZE = 2
    };

    enum eSpells
    {
        SPELL_BONE_CHOMP = 193639,
        SPELL_STONE_GAZE = 202181,
    };

    struct mob_rockback_gnasher_AI : public ScriptedAI
    {
        mob_rockback_gnasher_AI(Creature* creature) : ScriptedAI(creature) {}

        EventMap events;

        void EnterCombat(Unit* unit) override
        {
            events.ScheduleEvent(EVENT_BONE_CHOMP, 2 * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_STONE_GAZE, 6 * IN_MILLISECONDS);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            switch (events.ExecuteEvent())
            {
                case EVENT_BONE_CHOMP:
                    if (me->GetVictim())
                        me->CastSpell(me->GetVictim(), SPELL_BONE_CHOMP, false);
                    events.ScheduleEvent(EVENT_BONE_CHOMP, urand(11, 13) * IN_MILLISECONDS);
                    break;
                case EVENT_STONE_GAZE:
                    me->CastSpell(me->GetVictim(), SPELL_STONE_GAZE, false);
                    events.ScheduleEvent(EVENT_STONE_GAZE, urand(14, 16) * IN_MILLISECONDS);
                    break;
            }

            DoMeleeAttackIfReady();
        }
    };
};

// 101438
class mob_vileshard_chunk : public CreatureScript
{
public:
    mob_vileshard_chunk() : CreatureScript("mob_vileshard_chunk") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new mob_vileshard_chunk_AI(creature);
    }

    enum eEvents
    {
        EVENT_CRUSH = 1
    };

    enum eSpells
    {
        SPELL_CRUSH = 226287,
    };

    struct mob_vileshard_chunk_AI : public ScriptedAI
    {
        mob_vileshard_chunk_AI(Creature* creature) : ScriptedAI(creature) {}

        EventMap events;

        void EnterCombat(Unit* unit) override
        {
            events.ScheduleEvent(EVENT_CRUSH, 4 * IN_MILLISECONDS);
        }
        
        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            switch (events.ExecuteEvent())
            {
                case EVENT_CRUSH:
                    me->CastSpell(me->GetVictim(), SPELL_CRUSH, false);
                    events.ScheduleEvent(EVENT_CRUSH, urand(14, 16) * IN_MILLISECONDS);
                    break;
            }

            DoMeleeAttackIfReady();
        }
    };
};

// 91001
class mob_tarspitter_lurker : public CreatureScript
{
public:
    mob_tarspitter_lurker() : CreatureScript("mob_tarspitter_lurker") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new mob_tarspitter_lurker_AI(creature);
    }

    enum eEvents
    {
        EVENT_SUBMERGE = 1,
        EVENT_VISCID_BILE = 2,
    };

    enum eSpells
    {
        SPELL_SUBMERGE = 183433,
        SPELL_VISCID_BILE = 183465,
        SPELL_RANCID_OOZE = 226385,
    };

    struct mob_tarspitter_lurker_AI : public ScriptedAI
    {
        mob_tarspitter_lurker_AI(Creature* creature) : ScriptedAI(creature) {}

        EventMap events;

        void EnterCombat(Unit* unit) override
        {
            events.ScheduleEvent(EVENT_SUBMERGE, 2 * IN_MILLISECONDS);
        }
        
        void JustDied(Unit* killer) override
        {
            me->CastSpell(killer, SPELL_RANCID_OOZE, false);
        }
        
        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            switch (events.ExecuteEvent())
            {
                case EVENT_SUBMERGE:
                    me->CastSpell(me->GetVictim(), SPELL_SUBMERGE, false); // need script
                    events.ScheduleEvent(EVENT_VISCID_BILE, 9 * IN_MILLISECONDS);
                    events.ScheduleEvent(EVENT_SUBMERGE, urand(17, 19) * IN_MILLISECONDS);
                    break;
                case EVENT_VISCID_BILE:
                    me->CastSpell(me->GetVictim(), SPELL_VISCID_BILE, false);
                    break;
            }

            DoMeleeAttackIfReady();
        }
    };
};

// 91000
class mob_vileshard_hulk : public CreatureScript
{
public:
    mob_vileshard_hulk() : CreatureScript("mob_vileshard_hulk") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new mob_vileshard_hulk_AI(creature);
    }

    enum eEvents
    {
        EVENT_PIERCING_SHARDS = 1,
        EVENT_FRACTURE = 2
    };

    enum eSpells
    {
        SPELL_PIERCING_SHARDS = 226296,
        SPELL_FRACTURE = 193505,
    };

    struct mob_vileshard_hulk_AI : public ScriptedAI
    {
        mob_vileshard_hulk_AI(Creature* creature) : ScriptedAI(creature) {}

        EventMap events;
        
        uint32 firstShardsCounter = 0;
        uint32 _milliseconds = 0;

        void EnterCombat(Unit* unit) override
        {
            if (Creature* drudge = me->FindNearestCreature(NPC_UNDERSTONE_DRUDGE, 80.0f, true))
                sCreatureTextMgr->SendChat(drudge, 1);
            
            events.ScheduleEvent(EVENT_PIERCING_SHARDS, 5 * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_FRACTURE, 10 * IN_MILLISECONDS);
        }
        
        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            switch (events.ExecuteEvent())
            {
                case EVENT_PIERCING_SHARDS:
                    me->CastSpell(me->GetVictim(), SPELL_PIERCING_SHARDS, false);
                    ++firstShardsCounter;
                    _milliseconds = urand(12000, 14000);
                    if (InstanceScript* instance = me->GetInstanceScript())
                        if (instance->instance->GetDifficultyID() >= DIFFICULTY_HEROIC && (firstShardsCounter % 2 != 0))
                            _milliseconds = 2500;
                    events.ScheduleEvent(EVENT_PIERCING_SHARDS, _milliseconds);
                    break;
                case EVENT_FRACTURE:
                    me->CastSpell(me->GetVictim(), SPELL_FRACTURE, false);
                    events.ScheduleEvent(EVENT_FRACTURE, urand(14, 16) * IN_MILLISECONDS);
                    break;
            }

            DoMeleeAttackIfReady();
        }
    };
};

// 92350
class mob_understone_drudge : public CreatureScript
{
public:
    mob_understone_drudge() : CreatureScript("mob_understone_drudge") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new mob_understone_drudge_AI(creature);
    }

    enum eTalk
    {
        TALK_ATTACK       = 2
    };

    struct mob_understone_drudge_AI : public ScriptedAI
    {
        mob_understone_drudge_AI(Creature* creature) : ScriptedAI(creature) {}
        
        bool phraseSays;
        
        void MoveInLineOfSight(Unit* who) override
        {
            if (!phraseSays && who->GetTypeId() == TYPEID_PLAYER && !who->ToPlayer()->IsGameMaster() && me->IsWithinDistInMap(who, 8.0f))
            {
                Talk(TALK_ATTACK);
                phraseSays = true;
            }    
        }
    };
};

// 92612
class mob_mightstone_breaker : public CreatureScript
{
public:
    mob_mightstone_breaker() : CreatureScript("mob_mightstone_breaker") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new mob_mightstone_breaker_AI(creature);
    }

    enum eEvents
    {
        EVENT_AVALANCHE             = 1
    };

    enum eSpells
    {
        SPELL_AVALANCHE             = 183088
    };

    struct mob_mightstone_breaker_AI : public ScriptedAI
    {
        mob_mightstone_breaker_AI(Creature* creature) : ScriptedAI(creature) {}

        EventMap events;

        void EnterCombat(Unit* unit) override
        {
            events.ScheduleEvent(EVENT_AVALANCHE, 5 * IN_MILLISECONDS);
        }
        
        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            switch (events.ExecuteEvent())
            {
                case EVENT_AVALANCHE:
                    me->CastSpell((Unit*)nullptr, SPELL_AVALANCHE, false);
                    events.ScheduleEvent(EVENT_AVALANCHE, urand(8, 12) * IN_MILLISECONDS);
                    break;
            }

            DoMeleeAttackIfReady();
        }
    };
};

// 91008
class mob_rockbound_pelter : public CreatureScript
{
public:
    mob_rockbound_pelter() : CreatureScript("mob_rockbound_pelter") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new mob_rockbound_pelter_AI(creature);
    }

    enum eEvents
    {
        EVENT_RETREAT             = 1,
        EVENT_JUGGED_DISK         = 2
    };

    enum eSpells
    {
        SPELL_RETREAT             = 226361,
        SPELL_JUGGED_DISK         = 183633
        
    };

    struct mob_rockbound_pelter_AI : public ScriptedAI
    {
        mob_rockbound_pelter_AI(Creature* creature) : ScriptedAI(creature) {}

        EventMap events;

        void EnterCombat(Unit* unit) override
        {
            events.ScheduleEvent(EVENT_RETREAT, 5 * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_JUGGED_DISK, 7 * IN_MILLISECONDS);
        }
        
        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            switch (events.ExecuteEvent())
            {
                case EVENT_RETREAT:
                    me->CastSpell(me, SPELL_RETREAT, false);
                    events.ScheduleEvent(EVENT_RETREAT, urand(10, 12) * IN_MILLISECONDS);
                    break;
                case EVENT_JUGGED_DISK:
                    if (me->GetVictim())
                        me->CastSpell(me->GetVictim(), SPELL_JUGGED_DISK, false);
                    events.ScheduleEvent(EVENT_JUGGED_DISK, urand(5, 7) * IN_MILLISECONDS);
                    break;
            }

            DoMeleeAttackIfReady();
        }
    };
};

// 91332
class mob_stoneclaw_hunter : public CreatureScript
{
public:
    mob_stoneclaw_hunter() : CreatureScript("mob_stoneclaw_hunter") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new mob_stoneclaw_hunter_AI(creature);
    }

    enum eEvents
    {
        EVENT_STONE_SHUTTER       = 1
    };

    enum eSpells
    {
        SPELL_STONE_SHUTTER       = 226347
        
    };

    struct mob_stoneclaw_hunter_AI : public ScriptedAI
    {
        mob_stoneclaw_hunter_AI(Creature* creature) : ScriptedAI(creature) {}

        EventMap events;

        void EnterCombat(Unit* unit) override
        {
            events.ScheduleEvent(EVENT_STONE_SHUTTER, 5 * IN_MILLISECONDS);
        }
        
        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            switch (events.ExecuteEvent())
            {
                case EVENT_STONE_SHUTTER:
                    me->CastSpell((Unit*)nullptr, SPELL_STONE_SHUTTER, false);
                    events.ScheduleEvent(EVENT_STONE_SHUTTER, urand(10, 12) * IN_MILLISECONDS);
                    break;
            }

            DoMeleeAttackIfReady();
        }
    };
};

// 90998
class mob_blightshard_shaper : public CreatureScript
{
public:
    mob_blightshard_shaper() : CreatureScript("mob_blightshard_shaper") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new mob_blightshard_shaper_AI(creature);
    }

    enum eEvents
    {
        EVENT_STONE_BOLT       = 1
    };

    enum eSpells
    {
        SPELL_STONE_BOLT       = 186269
        
    };

    struct mob_blightshard_shaper_AI : public ScriptedAI
    {
        mob_blightshard_shaper_AI(Creature* creature) : ScriptedAI(creature) {}

        EventMap events;

        void EnterCombat(Unit* unit) override
        {
            events.ScheduleEvent(EVENT_STONE_BOLT, 5 * IN_MILLISECONDS);
        }
        
        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            switch (events.ExecuteEvent())
            {
                case EVENT_STONE_BOLT:
                    me->CastSpell(me->GetVictim(), SPELL_STONE_BOLT, false);
                    events.ScheduleEvent(EVENT_STONE_BOLT, urand(10, 12) * IN_MILLISECONDS);
                    break;
            }

            DoMeleeAttackIfReady();
        }
    };
};

// 102404
class mob_stoneclaw_grubmaster : public CreatureScript
{
public:
    mob_stoneclaw_grubmaster() : CreatureScript("mob_stoneclaw_grubmaster") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new mob_stoneclaw_grubmaster_AI(creature);
    }

    enum eEvents
    {
        EVENT_LEECH             = 1,
        EVENT_STONE_SHUTTER     = 2,
    };

    enum eSpells
    {
        SPELL_LEECH             = 202230,
        SPELL_STONE_SHUTTER     = 226347,
        
    };

    struct mob_stoneclaw_grubmaster_AI : public ScriptedAI
    {
        mob_stoneclaw_grubmaster_AI(Creature* creature) : ScriptedAI(creature) {}

        EventMap events;

        void EnterCombat(Unit* unit) override
        {
            events.ScheduleEvent(EVENT_LEECH, 5 * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_STONE_SHUTTER, 3 * IN_MILLISECONDS);
        }
        
        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            switch (events.ExecuteEvent())
            {
                case EVENT_LEECH:
                    me->CastSpell(me->GetVictim(), SPELL_LEECH, false);
                    events.ScheduleEvent(EVENT_LEECH, urand(10, 12) * IN_MILLISECONDS);
                    break;
                case EVENT_STONE_SHUTTER:
                    me->CastSpell((Unit*)nullptr, SPELL_STONE_SHUTTER, false);
                    events.ScheduleEvent(EVENT_STONE_SHUTTER, urand(6, 8) * IN_MILLISECONDS);
                    break;
            }

            DoMeleeAttackIfReady();
        }
    };
};

// 183433
class spell_lurker_submerge : public SpellScriptLoader
{
    public:
        spell_lurker_submerge() : SpellScriptLoader("spell_lurker_submerge") { }

        class spell_lurker_submerge_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_lurker_submerge_AuraScript);

            void HandleEffectRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* caster = GetCaster())
                    caster->CastSpell(caster, 183438, true);
            }

            void Register() override
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_lurker_submerge_AuraScript::HandleEffectRemove, EFFECT_0, SPELL_AURA_TRANSFORM, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_lurker_submerge_AuraScript();
        }
};

void AddSC_neltharions_lair()
{
    new mob_vileshard_crawler();
    new mob_embershard_scorpion();
    new mob_neltharionslair_trigger();
    new mob_trigger_start_waterfall();
    new mob_rockback_gnasher();
    new mob_vileshard_chunk();
    new mob_tarspitter_lurker();
    new mob_vileshard_hulk();
    new mob_understone_drudge();
    new mob_mightstone_breaker();
    new mob_rockbound_pelter();
    new mob_stoneclaw_hunter();
    new mob_blightshard_shaper();
    new mob_stoneclaw_grubmaster();
    new spell_lurker_submerge();
    new at_acid_splatter();
}