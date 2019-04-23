/*
* Copyright (C) 2008-2018 TrinityCore <http://www.trinitycore.org/>
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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "MotionMaster.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "CellImpl.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "neltharions_lair.h"
#include "CreatureTextMgr.h"
#include "ObjectAccessor.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "SpellHistory.h"
#include "SpellPackets.h"
#include "SpellMgr.h"
#include "SpellScript.h"

class npc_navarogg_rokmora_start : public CreatureScript
{
public:
    npc_navarogg_rokmora_start() : CreatureScript("npc_navarogg_rokmora_start") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_navarogg_rokmora_start_AI(creature);
    }

    enum eTexts
    {
        TALK_ROKMORA_PHRASE           = 1,
        TALK_ENTRANCE_PHRASE          = 2,
        TALK_OBSTRUCTION              = 3,
        TALK_BARREL                   = 4
    };
    
    enum eEvents
    {
        EVENT_ULAROGG_INITIATE           = 1,
        EVENT_TALK_ROKMORA               = 2,
        EVENT_DESPAWN                    = 3,
        EVENT_START_JUMP                 = 4,
        EVENT_GO_TO_BARREL               = 5,
        EVENT_SPIRITWALKER_DONT_BARREL   = 6
    };
    
    struct npc_navarogg_rokmora_start_AI : public ScriptedAI
    {
        npc_navarogg_rokmora_start_AI(Creature* creature) : ScriptedAI(creature) { }
        
        InstanceScript* instance;
        EventMap events;
        bool entranceTalkSays = false;
        bool runStarted = false;
        
        void InitializeAI() override
        {
            instance = me->GetInstanceScript();
        }
        
        void MoveInLineOfSight(Unit* who) override
        {
            if (instance)
            {
                if (who->GetTypeId() == TYPEID_PLAYER && !who->ToPlayer()->IsGameMaster() && me->IsWithinDistInMap(who, 75.0f))
                {
                    if (instance->GetData(DATA_ENTRANCE_START_DIALOG) == NOT_STARTED && !entranceTalkSays)
                    {
                        Talk(TALK_ENTRANCE_PHRASE);
                        entranceTalkSays = true;
                        events.ScheduleEvent(EVENT_START_JUMP, 11 * IN_MILLISECONDS);
                    }
                    
                    if (instance->GetData(DATA_ROKMORA_START_DIALOG) == NOT_STARTED)
                    {
                        if (round(me->GetPositionX()) == round(navaroggRokmoraPos.GetPositionX()) &&
                        round(me->GetPositionY()) == round(navaroggRokmoraPos.GetPositionY()) &&
                        round(me->GetPositionZ()) == round(navaroggRokmoraPos.GetPositionZ()))
                        {
                            me->GetMotionMaster()->MoveJump(navaroggRokmoraJumpPos, 30.0f, 30.0f, EVENT_JUMP, true);
                            instance->SetData(DATA_ROKMORA_START_DIALOG, IN_PROGRESS);
                            events.ScheduleEvent(EVENT_ULAROGG_INITIATE, 6 * IN_MILLISECONDS);
                            events.ScheduleEvent(EVENT_TALK_ROKMORA, 14 * IN_MILLISECONDS);
                        }
                    }
                }
                if (instance->GetData(DATA_BARRELS_EVENT) == NOT_STARTED && who->GetTypeId() == TYPEID_PLAYER && !who->ToPlayer()->IsGameMaster() &&
                instance->GetData(DATA_ROKMORA) == DONE && me->IsWithinDistInMap(who, 40.0f))
                {
                    if (Creature* rokmora = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_ROKMORA)))
                        if (rokmora->IsAlive())
                            return;
                        
                    instance->SetData(DATA_BARRELS_EVENT, IN_PROGRESS);
                        
                    if (GameObject* goObstruction = ObjectAccessor::GetGameObject(*me, instance->GetGuidData(DATA_GO_NAVARROGG_OBSTRUCTION)))
                        goObstruction->SetGoState(GO_STATE_READY);
                        
                    Talk(TALK_OBSTRUCTION);
                    me->SetWalk(false);
                    me->GetMotionMaster()->MovePoint(0, navaroggObstructionPos);
                    events.ScheduleEvent(EVENT_GO_TO_BARREL, 10 * IN_MILLISECONDS);
                }
            }
        }
        
        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            switch (events.ExecuteEvent())
            {
                case EVENT_START_JUMP:
                    me->GetMotionMaster()->MoveJump(startFallingPos, 15.0f, 15.0f, EVENT_JUMP, true);
                    if (instance)
                        instance->SetData(DATA_ENTRANCE_START_DIALOG, DONE);
                    
                    events.ScheduleEvent(EVENT_DESPAWN, 4 * IN_MILLISECONDS);
                    break;
                case EVENT_ULAROGG_INITIATE:
                    if (Creature* ularogg_rokmora_starter = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_ULAROGG_ROKMORA_STARTER)))
                    {
                       if (ularogg_rokmora_starter->IsAIEnabled)
                       {
                           ularogg_rokmora_starter->AI()->DoAction(1);
                           ularogg_rokmora_starter->SetFacingToObject(me);
                       }
                    }
                    break;
                case EVENT_TALK_ROKMORA:
                    Talk(TALK_ROKMORA_PHRASE);
                    break;
                case EVENT_DESPAWN:
                    me->DespawnOrUnsummon();
                    break;
                case EVENT_GO_TO_BARREL:
                        Talk(TALK_BARREL);
                        events.ScheduleEvent(EVENT_SPIRITWALKER_DONT_BARREL, 3500);
                    break;
                case EVENT_SPIRITWALKER_DONT_BARREL:
					if (Creature* spiritwalkerNpc = me->FindNearestCreature(NPC_SPIRITWALKER, 90.0f, true))
                       if (spiritwalkerNpc->IsAIEnabled)
                           spiritwalkerNpc->AI()->DoAction(1);

                    instance->SetData(DATA_BARRELS_EVENT, DONE);
                    break;
            }
            
            if (!runStarted && instance->GetData(DATA_ROKMORA_START_DIALOG) == DONE)
            {
                if (round(me->GetPositionX()) == round(navaroggRokmoraJumpPos.GetPositionX()) &&
                    round(me->GetPositionY()) == round(navaroggRokmoraJumpPos.GetPositionY()) &&
                    round(me->GetPositionZ()) == round(navaroggRokmoraJumpPos.GetPositionZ()))
                {
                    me->SetWalk(false);
                    if (Creature* ularogg_rokmora_starter = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_ULAROGG_ROKMORA_STARTER)))
                        me->GetMotionMaster()->MoveFollow(ularogg_rokmora_starter, 5.0f, (float)M_PI/2.f, MOTION_SLOT_ACTIVE);
                    events.ScheduleEvent(EVENT_DESPAWN, 7 * IN_MILLISECONDS);
                    runStarted = true;
                }
            }
        }
    }; 
};

class npc_spiritwalker_ebonhorn : public CreatureScript
{
public:
    npc_spiritwalker_ebonhorn() : CreatureScript("npc_spiritwalker_ebonhorn") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_spiritwalker_ebonhorn_AI(creature);
    }

    enum eTexts
    {
        TALK_ENTRANCE_PHRASE          = 1,
        TALK_CONVERSATION_SAY         = 2,
        TALK_DONT_BARREL              = 3
    };
    
    enum eActions
    {
        ACTION_BARREL_TALK            = 1,
    };
    
    enum eEvents
    {
        EVENT_SPIRITWALKER_TALK          = 1,
        EVENT_START_JUMP                 = 2,
        EVENT_DESPAWN                    = 3,
        EVENT_TALK_DONT_BARREL           = 4,
    };
    
    struct npc_spiritwalker_ebonhorn_AI : public ScriptedAI
    {
        npc_spiritwalker_ebonhorn_AI(Creature* creature) : ScriptedAI(creature) { }
        
        InstanceScript* instance;

        void InitializeAI() override
        {
            instance = me->GetInstanceScript();
        }
        
        bool conversationSays = false;
        bool obstructed = false;
        bool entranceTalkSays = false;
        
        void DoAction(int32 action) override
        {
            switch(action)
            {
                case ACTION_BARREL_TALK:
                    events.ScheduleEvent(EVENT_TALK_DONT_BARREL, 500);
                    break;
            }
        }
        
        void MoveInLineOfSight(Unit* who) override
        {
            if (instance)
            {
                if (who->GetTypeId() == TYPEID_PLAYER && !who->ToPlayer()->IsGameMaster() && me->IsWithinDistInMap(who, 160.0f))
                {
                    if (instance->GetData(DATA_ENTRANCE_START_DIALOG) == NOT_STARTED && !entranceTalkSays)
                    {
                        entranceTalkSays = true;
                        events.ScheduleEvent(EVENT_SPIRITWALKER_TALK, 6 * IN_MILLISECONDS);
                        events.ScheduleEvent(EVENT_START_JUMP, 11 * IN_MILLISECONDS);
                    }
                    
                    if (instance->GetData(DATA_ENTRANCE_START_DIALOG) == DONE && instance->GetData(DATA_ROKMORA_START_DIALOG) == NOT_STARTED && me->GetPositionZ() < 0 && !conversationSays)
                    {
                        conversationSays = true;
                        Talk(TALK_CONVERSATION_SAY);
                    }
                }

                if (who->GetTypeId() == TYPEID_PLAYER && !who->ToPlayer()->IsGameMaster() &&
                instance->GetData(DATA_ROKMORA) == DONE && instance->GetData(DATA_BARRELS_EVENT) != DONE && !obstructed && me->IsWithinDistInMap(who, 25.0f))
                {
                    if (Creature* rokmora = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_ROKMORA)))
                        if (rokmora->IsAlive())
                            return;

                    obstructed = true;
                    me->SetWalk(false);
                    me->GetMotionMaster()->MovePoint(0, spiritwalkerBarrelPos);
                }
            }
        }
        
        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            switch (events.ExecuteEvent())
            {
                case EVENT_START_JUMP:
                    me->GetMotionMaster()->MoveJump(startFallingPos, 15.0f, 15.0f, EVENT_JUMP, true);
                    events.ScheduleEvent(EVENT_DESPAWN, 4 * IN_MILLISECONDS);
                    break;
                case EVENT_SPIRITWALKER_TALK:
                    Talk(TALK_ENTRANCE_PHRASE);
                    break;
                case EVENT_DESPAWN:
                    me->DespawnOrUnsummon();
                    break;
                case EVENT_TALK_DONT_BARREL:
                    Talk(TALK_DONT_BARREL);
                    break;
            }
        }
    }; 
};

class npc_ularogg_rokmora_start : public CreatureScript
{
public:
    npc_ularogg_rokmora_start() : CreatureScript("npc_ularogg_rokmora_start") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_ularogg_rokmora_start_AI(creature);
    }
    
    enum eTexts
    {
        TALK_PHRASE_1                    = 1,
        TALK_PHRASE_2                    = 2
    };
    
    enum eEvents
    {
        EVENT_PHRASE_2                   = 1,
        EVENT_AWAY                       = 2,
        EVENT_DATA_DONE                  = 3,
        EVENT_DESPAWN                    = 4
    };
    
    enum eActions
    {
        ACTION_START_DIALOG              = 1
    };
    
    struct npc_ularogg_rokmora_start_AI : public ScriptedAI
    {
        npc_ularogg_rokmora_start_AI(Creature* creature) : ScriptedAI(creature) { }
        
        EventMap events;
        InstanceScript* instance;
        
        void InitializeAI() override
        {
            instance = me->GetInstanceScript();
        }

        void DoAction(int32 action)
        {
            switch(action)
            {
                case ACTION_START_DIALOG:
                    Talk(TALK_PHRASE_1);
                    events.ScheduleEvent(EVENT_PHRASE_2, 17 * IN_MILLISECONDS);
                    break;
            }
        }
        
        
        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            switch (events.ExecuteEvent())
            {
                case EVENT_PHRASE_2:
                    Talk(TALK_PHRASE_2);
                    events.ScheduleEvent(EVENT_AWAY, 6 * IN_MILLISECONDS);
                    events.ScheduleEvent(EVENT_DATA_DONE, 5500);
                    break;
                case EVENT_AWAY:
                    me->SetWalk(false);
                    me->GetMotionMaster()->MovePoint(0, ularoggAwayPos);
                    
                    if (Creature* rokmora = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_ROKMORA)))
                       rokmora->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                    
                    events.ScheduleEvent(EVENT_DESPAWN, 7 * IN_MILLISECONDS);
                    break;
                case EVENT_DATA_DONE:
                    instance->SetData(DATA_ROKMORA_START_DIALOG, DONE);
                    break;
                case EVENT_DESPAWN:
                    me->DespawnOrUnsummon();
                    break;
            }
        }
    }; 
};

class boss_rokmora : public CreatureScript
{
public:
    boss_rokmora() : CreatureScript("boss_rokmora") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_rokmora_AI(creature);
    }
    
    enum eTexts
    {
        TALK_AGGRO                        = 0,
        TALK_SHATTER                      = 1,
        TALK_DEATH                        = 2,
        TALK_CRYSTALLINE_GROUND           = 3
    };
    
    enum eEvents
    {
        EVENT_MANAREGEN_TICK             = 1,
        EVENT_SHATTER                    = 2,
        EVENT_RAZOR_SHARDS               = 3,
        EVENT_MANARESET                  = 4,
        EVENT_CRYSTALLINE_GROUND         = 5,
    };
    
    enum eSpells
    {
        SPELL_SHATTER                    = 188114,
        SPELL_RAZOR_SHARDS               = 188169,
        SPELL_CRYSTALLINE_GROUND         = 198024
    };
    
    struct boss_rokmora_AI : public BossAI
    {
        boss_rokmora_AI(Creature* creature) : BossAI(creature, DATA_ROKMORA) { }
        
        EventMap events;
        InstanceScript* instance;
        bool manaRegenerated = false;
        bool firstShardsCasted = false;
        bool firstGroundCasted = false;
        
        void InitializeAI() override
        {
            instance = me->GetInstanceScript();
            me->SetPower(POWER_MANA, 0);
        }
        
        void Reset() override
        {
            _Reset();
            events.Reset();
            me->SetPower(POWER_MANA, 0);

            if (instance)
                instance->SetData(DATA_ROKMORA, NOT_STARTED);
        }
        
        void EnterCombat(Unit* who) override
        {
            Talk(TALK_AGGRO);
            me->SetInCombatWithZone();
            me->SetPower(POWER_MANA, 0);
            if (instance && instance->instance->GetDifficultyID() >= 2)
                events.ScheduleEvent(EVENT_CRYSTALLINE_GROUND, IN_MILLISECONDS);
            
            events.ScheduleEvent(EVENT_MANAREGEN_TICK, 2 * IN_MILLISECONDS);
            
            if (instance)
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
                instance->SetData(DATA_ROKMORA, IN_PROGRESS);
            }
        }
        
        void JustDied(Unit* /*unit*/) override
        {
            Talk(TALK_DEATH);
            
            if (GameObject* barrier = ObjectAccessor::GetGameObject(*me, instance->GetGuidData(DATA_MYSTIC_BARRIER)))
                barrier->SetGoState(GO_STATE_ACTIVE);
            
            instance->SetData(DATA_ROKMORA, DONE);
        }
        
        void EnterEvadeMode(EvadeReason) override
        {
            BossAI::EnterEvadeMode();
            if (instance)
            {
                instance->SetData(DATA_ROKMORA, FAIL);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            }
        }
        
        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;
            
            events.Update(diff);

            switch (events.ExecuteEvent())
            {
                case EVENT_MANAREGEN_TICK:
                    if (!manaRegenerated && me->GetPower(POWER_MANA) < me->GetMaxPower(POWER_MANA))
                    {
                        me->SetPower(POWER_MANA, me->GetPower(POWER_MANA)+(me->GetMaxPower(POWER_MANA)*5/100));
                        
                        if (me->GetPower(POWER_MANA) == me->GetMaxPower(POWER_MANA))
                        {
                            manaRegenerated = true;
                            events.ScheduleEvent(EVENT_SHATTER, IN_MILLISECONDS);
                        }
                        else
                            events.ScheduleEvent(EVENT_MANAREGEN_TICK, 2 * IN_MILLISECONDS);
                    }
                    break;
                case EVENT_SHATTER:
                    Talk(TALK_SHATTER);
                    me->CastSpell(me->GetVictim(), SPELL_SHATTER, false);
                    if (!firstShardsCasted)
                        events.ScheduleEvent(EVENT_RAZOR_SHARDS, 4400);
                    else if (instance->instance->GetDifficultyID() >= 2)
                        events.ScheduleEvent(EVENT_CRYSTALLINE_GROUND, 4400);
                    else
                        events.ScheduleEvent(EVENT_MANARESET, 4400);
                    break;
                case EVENT_RAZOR_SHARDS:
                    me->CastSpell(me->GetVictim(), SPELL_RAZOR_SHARDS, false);
                    if (!firstShardsCasted)
                        firstShardsCasted = true;
                    
                    events.ScheduleEvent(EVENT_MANARESET, 3900);
                    events.ScheduleEvent(EVENT_RAZOR_SHARDS, 30 * IN_MILLISECONDS);
                    break;
                case EVENT_CRYSTALLINE_GROUND:
                    Talk(TALK_CRYSTALLINE_GROUND);
                    me->CastSpell(me->GetVictim(), SPELL_CRYSTALLINE_GROUND, false);
                     events.ScheduleEvent(EVENT_MANARESET, IN_MILLISECONDS);
                    break;
                case EVENT_MANARESET:
                    me->SetPower(POWER_MANA, 0);
                    manaRegenerated = false;
                    events.ScheduleEvent(EVENT_MANAREGEN_TICK, 2 * IN_MILLISECONDS);
                    break;
                case SPELL_CRYSTALLINE_GROUND:
                    me->CastSpell(me->GetVictim(), SPELL_CRYSTALLINE_GROUND, false);
                    break;
            }
            
            DoMeleeAttackIfReady();
        }
    }; 
};

// 97720
class mob_blightshard_skitter : public CreatureScript
{
public:
    mob_blightshard_skitter() : CreatureScript("mob_blightshard_skitter") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new mob_blightshard_skitter_AI(creature);
    }

    enum eSpells
    {
        SPELL_CHOKING_DUST = 192799
    };

    struct mob_blightshard_skitter_AI : public ScriptedAI
    {
        mob_blightshard_skitter_AI(Creature* creature) : ScriptedAI(creature) {}
        
        void JustDied(Unit* killer) override
        {
            me->CastSpell(killer, SPELL_CHOKING_DUST, false);
        }
        
        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;
            
            DoMeleeAttackIfReady();
        }
    };
};

class at_choking_dust : public AreaTriggerEntityScript
{
public:
    at_choking_dust() : AreaTriggerEntityScript("at_choking_dust") { }

    struct at_choking_dustAI : AreaTriggerAI
    {
        at_choking_dustAI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

        void OnUnitEnter(Unit* unit) override
        {
            if (unit)
                unit->AddAura(192800, unit);
        }

        void OnUnitExit(Unit* unit) override
        {
            if (unit && unit->HasAura(192800))
                unit->RemoveAura(192800);
        }
    };

    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
    {
        return new at_choking_dustAI(areatrigger);
    }
};

class at_crystalline_ground : public AreaTriggerEntityScript
{
public:
    at_crystalline_ground() : AreaTriggerEntityScript("at_crystalline_ground") { }

    struct at_crystalline_groundAI : AreaTriggerAI
    {
        at_crystalline_groundAI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

        void OnUnitEnter(Unit* unit) override
        {
            if (unit)
                unit->AddAura(215898, unit);
        }

        void OnUnitExit(Unit* unit) override
        {
            if (unit && unit->HasAura(215898))
                unit->RemoveAura(215898);
        }
    };

    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
    {
        return new at_crystalline_groundAI(areatrigger);
    }
};

// -215898
class spell_crystalline_ground_damage : public SpellScriptLoader
{
    public:
        spell_crystalline_ground_damage() : SpellScriptLoader("spell_crystalline_ground_damage") { }

        class spell_crystalline_ground_damage_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_crystalline_ground_damage_AuraScript);

            void ATDamage(AuraEffect const* /*aurEff*/)
            {
                PreventDefaultAction();
                Unit* target = GetTarget();
                if (target->GetTypeId() != TYPEID_UNIT)
                    return;

                if (!target->isMoving())
                    return;
                
                target->CastSpell(target, 198028, false);
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_crystalline_ground_damage_AuraScript::ATDamage, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_crystalline_ground_damage_AuraScript();
        }
};

class spell_rokmora_shatter : public SpellScriptLoader
{
public:
    spell_rokmora_shatter() : SpellScriptLoader("spell_rokmora_shatter") { }

    class spell_rokmora_shatter_SpellScript : public SpellScript
    {
        enum eSpells
        {
            SPELL_RUPTURING_SKITTER = 215929
        };
        
        PrepareSpellScript(spell_rokmora_shatter_SpellScript);

        void KillSkitters()
        { 
            if (Unit* caster = GetCaster())
            {
                Player* _player = nullptr;
                if (InstanceScript* instance = caster->GetInstanceScript())
                {
                    Map::PlayerList const &PlayerList = instance->instance->GetPlayers();
                    if (!PlayerList.isEmpty())
                    {
                        for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                        {
                            _player = i->GetSource();
                            if (_player && _player->IsAlive() && caster->IsWithinDistInMap(_player, 85.0f))
                                    break;
                        }
                    }
        
                    if (_player)
                    {
                        std::list<Unit*> TargetList;
                        Trinity::NearestAttackableUnitInObjectRangeCheck check(_player, _player, 85.0f);
                        Trinity::UnitListSearcher<Trinity::NearestAttackableUnitInObjectRangeCheck> searcher(_player, TargetList, check);
						Cell::VisitAllObjects(_player, searcher, 85.0f);

                        if (!TargetList.empty())
                        {
                            for (Unit* target : TargetList)
                            {
                                if (target->ToCreature() && target->ToCreature()->GetEntry() == NPC_BLIGHTSHARD_SKITTER)
                                {
                                    if (instance->instance->GetDifficultyID() >= 2)
                                    {
                                        int32 bp = target->GetHealth()/2;
                                        target->CastCustomSpell(_player, SPELL_RUPTURING_SKITTER, &bp, 0, 0, 0);
                                    }
                                    caster->Kill(target, false);
                                }
                            }
                        }
                    }
                }
            }
        }

        void Register()
        {
            AfterCast += SpellCastFn(spell_rokmora_shatter_SpellScript::KillSkitters);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_rokmora_shatter_SpellScript();
    }
};

// 92473
class npc_empty_barrel : public CreatureScript
{
public:
    npc_empty_barrel() : CreatureScript("npc_empty_barrel") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_empty_barrel_AI(creature);
    }

    enum eSpells
    {
        SPELL_CHOKING_DUST = 192799
    };

    struct npc_empty_barrel_AI : public ScriptedAI
    {
        npc_empty_barrel_AI(Creature* creature) : ScriptedAI(creature) {}
        
        InstanceScript* instance;
        
        void InitializeAI() override
        {
            instance = me->GetInstanceScript();
        }
        
        void OnSpellClick(Unit* clicker, bool& result) override
        { 
            if (result && instance)
            {
                if (instance->GetData(DATA_ROKMORA) == DONE && clicker->ToPlayer())
                {
                    float allSpeed = 3.0f;
                    clicker->SetSpeedRate(MOVE_WALK, allSpeed);
                    clicker->SetSpeedRate(MOVE_RUN, allSpeed);
                    clicker->SetSpeedRate(MOVE_SWIM, allSpeed);
                    clicker->SetSpeedRate(MOVE_FLIGHT, allSpeed);

                    std::vector<uint32> destinations;
                    destinations.push_back(TAXI_NODE_BARREL_END_POINT);
                    destinations.push_back(TAXI_NODE_BARREL_START_POINT);
                    clicker->ToPlayer()->m_taxi.SetTaxiDestination(destinations);
                    clicker->ToPlayer()->SaveToDB();
                    clicker->ToPlayer()->ContinueTaxiFlight();
                }
            }
        }
    };
};

void AddSC_boss_rokmora()
{
    new npc_navarogg_rokmora_start();
    new npc_ularogg_rokmora_start();
    new boss_rokmora();
    new mob_blightshard_skitter();
    new npc_spiritwalker_ebonhorn();
    new spell_rokmora_shatter();
    new npc_empty_barrel();
    new at_choking_dust();
    new at_crystalline_ground();
    new spell_crystalline_ground_damage();
}
