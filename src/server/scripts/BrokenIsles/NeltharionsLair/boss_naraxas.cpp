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

#include "AreaTriggerAI.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "neltharions_lair.h"
#include "CreatureTextMgr.h"
#include "EnumClassFlag.h"
#include "ObjectAccessor.h"
#include "GameObject.h"
#include "PhasingHandler.h"

class at_rancid_maw : public AreaTriggerEntityScript
{
public:
    at_rancid_maw() : AreaTriggerEntityScript("at_rancid_maw") { }

    struct at_rancid_mawAI : AreaTriggerAI
    {
        at_rancid_mawAI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

        void OnUnitEnter(Unit* unit) override
        {
            if (unit && unit->ToPlayer())
                unit->AddAura(188494, unit);
        }

        void OnUnitExit(Unit* unit) override
        {
            if (unit && unit->ToPlayer() && unit->HasAura(188494))
                unit->RemoveAura(188494);
        }
    };

    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
    {
        return new at_rancid_mawAI(areatrigger);
    }
};

class boss_naraxas : public CreatureScript
{
public:
    boss_naraxas() : CreatureScript("boss_naraxas") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_naraxas_AI(creature);
    }
    
    enum eTexts
    {
        TALK_DEVOUTERS_SPAWN                 = 0,
    };
    
    enum eEvents
    {
        EVENT_MANAREGEN_TICK                 = 1,
        EVENT_SUMMON_WORMSPEACKER_DEVOUT     = 2,
        EVENT_RANCID_MAW                     = 3,
        EVENT_TOXIC_RETCH                    = 4,
        EVENT_SPIKED_TONGUE                  = 5,
        EVENT_PLAYER_DEVOURING               = 6,
        EVENT_TO_1_PHASE                     = 7
    };
    
    enum eSpells
    {
        SPELL_DEVOURING                      = 199705,
        SPELL_DEVOURING_BUFF                 = 199246,
        SPELL_RANCID_MAW                     = 205549,
        SPELL_TOXIC_RETCH                    = 210150,
        SPELL_SPIKED_TONGUE                  = 199178,
        SPELL_SPIKED_TONGUE_VEHICLE          = 205418,
        SPELL_PUTRID_SKIES                   = 198963
    };
    
    struct boss_naraxas_AI : public BossAI
    {
        boss_naraxas_AI(Creature* creature) : BossAI(creature, DATA_NARAXAS) 
        {
            me->SetReactState(REACT_DEFENSIVE);
            me->AddUnitState(UNIT_STATE_ROOT);
        }
        
        EventMap events;
        InstanceScript* instance;
        bool manaRegenerated = false;
        Unit* currentDevout = nullptr;
        uint8 mawRepeating = urand(10, 14);
        TempSummon* wormspeakerDevout1 = nullptr;
        TempSummon* wormspeakerDevout2 = nullptr;
        bool isInSecondPhase = false;
        
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
                instance->SetData(DATA_NARAXAS, NOT_STARTED);
        }
        
        void EnterCombat(Unit* who) override
        {
            me->SetInCombatWithZone();
            me->SetPower(POWER_MANA, 0);
            me->RemoveAllAuras();
            
            events.ScheduleEvent(EVENT_MANAREGEN_TICK, IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_SUMMON_WORMSPEACKER_DEVOUT, 5 * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_RANCID_MAW, 4 * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_TOXIC_RETCH, 7 * IN_MILLISECONDS);
			
            if (instance)
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
                instance->SetData(DATA_NARAXAS, IN_PROGRESS);
            }
        }
        
        void MoveInLineOfSight(Unit* who) override
        {
            if (!isInSecondPhase && who != currentDevout && who->ToCreature() && who->ToCreature()->GetEntry() == NPC_WORMSPEACKER_DEVOUT && me->IsWithinDistInMap(who, 5.0f))
            {
                currentDevout = who;
                currentDevout->CastSpell(me, SPELL_SPIKED_TONGUE_VEHICLE, false);
                me->CastSpell(who, SPELL_DEVOURING, false);
                me->AddAura(SPELL_DEVOURING_BUFF, me);
                who->ToCreature()->DespawnOrUnsummon();
            }
        }
        
        void JustDied(Unit* /*unit*/) override
        {
			if (GameObject* barrier = ObjectAccessor::GetGameObject(*me, instance->GetGuidData(DATA_BARRIER_NARAXAS)))
				PhasingHandler::AddPhase(barrier, 3, true);
            
            if (GameObject* naraxasLoot = ObjectAccessor::GetGameObject(*me, instance->GetGuidData(DATA_NARAXAS_LOOT)))
                naraxasLoot->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_LOCKED | GO_FLAG_NOT_SELECTABLE | GO_FLAG_NODESPAWN);
            
            instance->SetData(DATA_NARAXAS, DONE);
        }
        
        void EnterEvadeMode(EvadeReason) override
        {
            //BossAI::EnterEvadeMode();
            if (instance)
            {
                instance->SetData(DATA_NARAXAS, FAIL);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            }
            manaRegenerated = false;
            me->RemoveAllAuras();
            me->SetPower(POWER_MANA, 0);
            me->SetHealth(me->GetMaxHealth());
            me->CombatStop();
            currentDevout = nullptr;
            mawRepeating = urand(10, 14);
            wormspeakerDevout1 = nullptr;
            wormspeakerDevout2 = nullptr;
            isInSecondPhase = false;
            while(Creature* _devout = me->FindNearestCreature(NPC_WORMSPEACKER_DEVOUT, 100.0f,true))
                _devout->DespawnOrUnsummon();
        }
        
        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;
            
            if (!me->SelectNearestPlayer(ATTACK_DISTANCE) && me->IsInCombat() && !isInSecondPhase)
                me->CastSpell((Unit*)nullptr, SPELL_PUTRID_SKIES, false);
            
            events.Update(diff);
            
            switch (events.ExecuteEvent())
            {
                case EVENT_TO_1_PHASE:
                    isInSecondPhase = false;
                    manaRegenerated = false;
                    me->SetPower(POWER_MANA, 0);
                    events.ScheduleEvent(EVENT_MANAREGEN_TICK, IN_MILLISECONDS);
                    events.ScheduleEvent(EVENT_SUMMON_WORMSPEACKER_DEVOUT, 5 * IN_MILLISECONDS);
                    events.ScheduleEvent(EVENT_RANCID_MAW, 4 * IN_MILLISECONDS);
                    events.ScheduleEvent(EVENT_TOXIC_RETCH, 7 * IN_MILLISECONDS);
                    break;
                case EVENT_MANAREGEN_TICK:
                    if (!manaRegenerated && me->GetPower(POWER_MANA) < me->GetMaxPower(POWER_MANA) && !isInSecondPhase)
                    {
						if (instance)
						{
							float manaRegenMod = 4;
							me->SetPower(POWER_MANA, me->GetPower(POWER_MANA)+(me->GetMaxPower(POWER_MANA)*manaRegenMod/100));
							
							if (me->GetPower(POWER_MANA) == me->GetMaxPower(POWER_MANA))
							{
								manaRegenerated = true;
								events.ScheduleEvent(EVENT_SPIKED_TONGUE, 3 * IN_MILLISECONDS);
							}
							else
								events.ScheduleEvent(EVENT_MANAREGEN_TICK, 2 * IN_MILLISECONDS);
						}
                    }
                    break;
                case EVENT_SUMMON_WORMSPEACKER_DEVOUT:
                    if (!isInSecondPhase)
                    {
                        Talk(TALK_DEVOUTERS_SPAWN);
                        wormspeakerDevout1 = me->SummonCreature(NPC_WORMSPEACKER_DEVOUT, Position(WormspeakerDevoutPositions[0][0], WormspeakerDevoutPositions[0][1], WormspeakerDevoutPositions[0][2], WormspeakerDevoutPositions[0][3]), TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 25000);
                        wormspeakerDevout2 = me->SummonCreature(NPC_WORMSPEACKER_DEVOUT, Position(WormspeakerDevoutPositions[1][0], WormspeakerDevoutPositions[1][1], WormspeakerDevoutPositions[1][2], WormspeakerDevoutPositions[1][3]), TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 25000);
                        
                        if (wormspeakerDevout1)
                            wormspeakerDevout1->GetMotionMaster()->MoveFollow(me, 5.0f, (float)M_PI/2.f, MOTION_SLOT_ACTIVE);
                        
                        if (wormspeakerDevout2)
                            wormspeakerDevout2->GetMotionMaster()->MoveFollow(me, 5.0f, (float)M_PI/2.f, MOTION_SLOT_ACTIVE);
                        
                        events.ScheduleEvent(EVENT_SUMMON_WORMSPEACKER_DEVOUT, urand(25, 30) * IN_MILLISECONDS);
                    }
                    break;
                case EVENT_RANCID_MAW:
                    if (!isInSecondPhase)
                    {
                        me->CastSpell(me, SPELL_RANCID_MAW, false);
                        if (me->GetHealthPct() <= 20)
                            mawRepeating = 6;
                        events.ScheduleEvent(EVENT_RANCID_MAW, urand(10, 14) * IN_MILLISECONDS);
                    }
                    break;
                case EVENT_TOXIC_RETCH:
                    if (!isInSecondPhase)
                    {
                        me->CastSpell(me, SPELL_TOXIC_RETCH, false);
                        events.ScheduleEvent(EVENT_TOXIC_RETCH, urand(9, 11) * IN_MILLISECONDS);
                    }
                    break;
                case EVENT_SPIKED_TONGUE:
                    isInSecondPhase = true;
                    if (me->GetVictim())
                    {
                        me->CastSpell(me->GetVictim(), SPELL_SPIKED_TONGUE, false);
                        events.ScheduleEvent(EVENT_PLAYER_DEVOURING, 6100);
                    }
                    break;
                case EVENT_PLAYER_DEVOURING:
                    if (me->GetVictim() && me->IsWithinDistInMap(me->GetVictim(), 30.0f))
                    {
                        me->GetVictim()->CastSpell(me, SPELL_SPIKED_TONGUE_VEHICLE, false);
                        me->CastSpell(me->GetVictim(), SPELL_DEVOURING, false);
                        me->AddAura(SPELL_DEVOURING_BUFF, me);
                    }
                    events.ScheduleEvent(EVENT_TO_1_PHASE, 3500);
                    break;
            }
            
            DoMeleeAttackIfReady();
        }
    }; 
};

// 101075
class mob_wormspeaker_devout : public CreatureScript
{
public:
    mob_wormspeaker_devout() : CreatureScript("mob_wormspeaker_devout") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new mob_wormspeaker_devout_AI(creature);
    }

    enum eSpells
    {
    };
    
    struct mob_wormspeaker_devout_AI : public ScriptedAI
    {
        InstanceScript* instance;
        bool phraseSayd = false;
        
        mob_wormspeaker_devout_AI(Creature* creature) : ScriptedAI(creature) 
        {
            me->SetReactState(REACT_PASSIVE);
            instance = me->GetInstanceScript();
        }
        
        void MoveInLineOfSight(Unit* who) override
        {
            if (!phraseSayd && who->ToCreature() && who->ToCreature()->GetEntry() == NPC_NARAXAS && me->IsWithinDistInMap(who, 7.0f))
            {
                phraseSayd = true;
                Talk(0);
            }
        }
    };
};

// 109137
class mob_angry_crowd : public CreatureScript
{
public:
    mob_angry_crowd() : CreatureScript("mob_angry_crowd") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new mob_angry_crowd_AI(creature);
    }
    
    struct mob_angry_crowd_AI : public ScriptedAI
    {
        
        mob_angry_crowd_AI(Creature* creature) : ScriptedAI(creature) 
        {
            me->SetReactState(REACT_PASSIVE);
        }
    };
};

// 113537
class mob_emberhusk_dominator : public CreatureScript
{
public:
    mob_emberhusk_dominator() : CreatureScript("mob_emberhusk_dominator") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new mob_emberhusk_dominator_AI(creature);
    }
    
    struct mob_emberhusk_dominator_AI : public ScriptedAI
    {
        
        mob_emberhusk_dominator_AI(Creature* creature) : ScriptedAI(creature) 
        {
            me->SetReactState(REACT_AGGRESSIVE);
        }
    };
};

// 205549
class spell_naraxas_rancid_maw : public SpellScriptLoader
{
public:
    spell_naraxas_rancid_maw() : SpellScriptLoader("spell_naraxas_rancid_maw") { }

    class spell_naraxas_rancid_maw_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_naraxas_rancid_maw_SpellScript);

        void CastTriggerSpell()
        {
            if (Unit* caster = GetCaster())
                    caster->CastSpell(caster->GetVictim(), 188493, false);
        }

        void Register()
        {
            AfterCast += SpellCastFn(spell_naraxas_rancid_maw_SpellScript::CastTriggerSpell);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_naraxas_rancid_maw_SpellScript();
    }
};

class at_toxic_retch : public AreaTriggerEntityScript
{
public:
    at_toxic_retch() : AreaTriggerEntityScript("at_toxic_retch") { }

    struct at_toxic_retchAI : AreaTriggerAI
    {
        at_toxic_retchAI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

        void OnUnitEnter(Unit* unit) override
        {
            if (unit && unit->ToPlayer())
                unit->AddAura(210166, unit);
        }

        void OnUnitExit(Unit* unit) override
        {
            if (unit && unit->ToPlayer() && unit->HasAura(210166))
                unit->RemoveAura(210166);
        }
    };

    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
    {
        return new at_toxic_retchAI(areatrigger);
    }
};

// 210150
class spell_naraxas_toxic_retch : public SpellScriptLoader
{
public:
    spell_naraxas_toxic_retch() : SpellScriptLoader("spell_naraxas_toxic_retch") { }

    class spell_naraxas_toxic_retch_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_naraxas_toxic_retch_SpellScript);

        void CastTriggerSpell()
        {
            if (Unit* caster = GetCaster())
                caster->CastSpell(caster, 210164, false);
        }

        void Register()
        {
            AfterCast += SpellCastFn(spell_naraxas_toxic_retch_SpellScript::CastTriggerSpell);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_naraxas_toxic_retch_SpellScript();
    }
};

// 199176
class spell_naraxas_spiked_tongue : public SpellScriptLoader
{
public:
    spell_naraxas_spiked_tongue() : SpellScriptLoader("spell_naraxas_spiked_tongue") { }

    class spell_naraxas_spiked_tongue_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_naraxas_spiked_tongue_SpellScript);

        void CastTriggerSpell()
        {
            if (Unit* caster = GetCaster())
                if (Unit* victim = caster->GetVictim())
                    caster->CastSpell(victim, 199178, false);
        }

        void Register()
        {
            AfterCast += SpellCastFn(spell_naraxas_spiked_tongue_SpellScript::CastTriggerSpell);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_naraxas_spiked_tongue_SpellScript();
    }
};

// -199705, -205418
class spell_naraxas_devourging_aura : public SpellScriptLoader
{
    public:
        spell_naraxas_devourging_aura() : SpellScriptLoader("spell_naraxas_devourging_aura") { }

        class spell_naraxas_devourging_aura_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_naraxas_devourging_aura_AuraScript);

            void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* target = GetTarget())
                {
                    if (target->ToCreature())
                        target->ToCreature()->DespawnOrUnsummon();
                }
            }

            void Register() override
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_naraxas_devourging_aura_AuraScript::HandleRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_naraxas_devourging_aura_AuraScript();
        }
};

void AddSC_boss_naraxas()
{
    new boss_naraxas();
    new mob_wormspeaker_devout();
    new spell_naraxas_rancid_maw();
    new spell_naraxas_toxic_retch();
    new spell_naraxas_spiked_tongue();
    new spell_naraxas_devourging_aura();
    new at_toxic_retch();
    new at_rancid_maw();
    new mob_angry_crowd();
    new mob_emberhusk_dominator();
}