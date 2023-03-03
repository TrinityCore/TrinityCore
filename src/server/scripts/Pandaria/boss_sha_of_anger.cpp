///*
//Pandaria
//World boss
//*/
//#include "ScriptPCH.h"
//#include "ObjectMgr.h"
//#include "ScriptMgr.h"
//#include "ScriptedCreature.h"
//#include "CreatureTextMgr.h"
//#include "QuestDef.h"
//#include "CreatureAI.h"
//#include "CreatureData.h"
//#include "CreatureTextMgr.h"
//#include "Creature.h"
//#include "CreatureGroups.h"
//#include <Player.cpp>
//enum FindNearestPlayer
//{
//    BOSS_SHA_OF_ANGER,
//};
//
//enum SetCreatureFlag
//{
//    BOSS_SHA_OF_ANGER,
//};
//
//enum eBosses
//{
//    BOSS_SHA_OF_ANGER,
//};
//
//enum eSpells
//{
//    SPELL_SEETHE                = 119487, 
//    SPELL_ENDLESS_RAGE          = 119587, 
//    SPELL_BITTER_THOUGHTS       = 119601, 
//    SPELL_BERSERK               =  47008,
//    SPELL_DOMINATE_MIND_WARNING = 119622, 
//    SPELL_DOMINATE_MIND         = 119626, 
//    SPELL_UNLEASHED_WRATH       = 119488,
//};
////CREATURE_SHA_OF_ANGER 60491,
//
//class boss_sha_of_anger : public CreatureScript
//{
//public:
//    boss_sha_of_anger() : CreatureScript("boss_sha_of_anger") { }
//
//    struct boss_sha_of_anger_AI : public BossAI
//    {
//        boss_sha_of_anger_AI(Creature* creature) : BossAI(creature, BOSS_SHA_OF_ANGER)
//        {
//            //me->SetCreatureFlag(UNIT_CREATURE_FIELD, UNIT_CREATURE_DISABLE_MOVE);
//        }
//
//        uint32 checkdistance;
//        uint32 berserk;
//        uint32 energy;
//        uint32 spawn;
//        bool phaseone;
//
//        std::list<uint64> targetedDominationPlayerGuids;
//
//        void Reset()
//        {
//            Talk(3);
//            _Reset();
//            me->SetPowerType(POWER_ENERGY);
//            me->SetPower(POWER_ENERGY, 0);
//            checkdistance = 0;
//            berserk = 0;
//            energy = 0;
//            spawn = 0;
//            phaseone = true;
//        }
//        
//        void RegeneratePower(Powers power, float &value)
//        {
//            //if (!me->isInCombat())
//            //{
//              //  value = 0;
//                //return;
//            //}
//
//            if (phaseone)
//                value = 2;
//            else
//                value = 0;
//        }
//
//        void KilledUnit(Unit* who)
//        {
//            if (who->GetTypeId() == TYPEID_PLAYER)
//                Talk(4);
//        }
//
//        void EnterCombat(Unit* unit)
//        {
//            Talk(5);
//            checkdistance = 1500; 
//            spawn = 5000;
//            berserk = 900000;
//        }
//
//        void UpdateAI(uint32 diff)
//        {
//            if (!UpdateVictim())
//                return;
//
//            if (me->HasUnitState(UNIT_STATE_CASTING))
//                return;
//
//            if (energy && !phaseone)
//            {
//                if (energy <= diff)
//                {
//                    if (me->GetPower(POWER_ENERGY) >= 4)
//                    {
//                        me->SetPower(POWER_ENERGY, me->GetPower(POWER_ENERGY) - 4);
//                        energy = 1000;
//                    }
//                    else
//                    {
//                        energy = 0;
//                        phaseone = true;
//                    }
//                }
//                else
//                    energy -= diff;
//            }
//
//            if (checkdistance <= diff)
//            {
//                if (me->GetVictim())
//                {
//                    if (me->GetDistance(me->GetVictim()) >= 25.0f)
//                    {
//                        EnterEvadeMode();
//                        return;
//                    }
//                    
//                    if ((!me->IsWithinMeleeRange(me->GetVictim())))
//                        DoCastAOE(SPELL_SEETHE);
//
//                    if (me->GetPower(POWER_ENERGY) == 100 && phaseone) //Check intro phase two
//                    {
//                        phaseone = false;
//                        DoCast(me, SPELL_UNLEASHED_WRATH);
//                        energy = 1000; 
//                    }
//                }
//                checkdistance = 1500;
//            }
//            else
//                checkdistance -= diff;
//            
//            if (spawn && phaseone)
//            {
//                if (spawn <= diff)
//                {
//                    Talk(2);
//                    for (uint8 n = 0; n < 3; n++)
//                    {
//                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 30.0f, true))
//                            DoCast(target, SPELL_ENDLESS_RAGE);
//                    }
//                    spawn = 15000;
//                }
//                else
//                    spawn -= diff;
//            }
//
//            if (berserk)
//            {
//                if (berserk <= diff)
//                {
//                    DoCast(me, SPELL_BERSERK);
//                    berserk = 0;
//                }
//                else
//                    berserk -= diff;
//            }
//
//            DoMeleeAttackIfReady();
//        }
//    };
//
//    CreatureAI* GetAI(Creature* creature) const
//    {
//        return new boss_sha_of_anger_AI(creature);
//    }
//};
//
//class npc_bitter_thoughths : public CreatureScript
//{
//    public:
//        npc_bitter_thoughths() : CreatureScript("npc_bitter_thoughths") {}
//
//        struct npc_bitter_thoughthsAI : public ScriptedAI
//        {
//            npc_bitter_thoughthsAI(Creature* creature) : ScriptedAI(creature)
//            {
//                me->SetReactState(REACT_PASSIVE);
//                me->SetDisplayId(11686);
//               // me->SetCreatureFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_DISABLE_MOVE | UNIT_FLAG_NON_ATTACKABLE);
//            }
//            
//            uint32 unsummon;
//            
//            void Reset()
//            {
//                me->AddAura(SPELL_BITTER_THOUGHTS, me);
//                unsummon = 30000;
//            }
//
//            void EnterCombat(Unit* who){}
//
//            void EnterEvadeMode(){}
//
//            void UpdateAI(uint32 diff)
//            {
//                if (unsummon <= diff)
//                {
//                    me->DespawnOrUnsummon();
//                }
//                else
//                    unsummon -= diff;
//            }
//        };
//
//        CreatureAI* GetAI(Creature* creature) const
//        {
//            return new npc_bitter_thoughthsAI(creature);
//        }
//};
//
//class npc_ire : public CreatureScript
//{
//    public:
//        npc_ire() : CreatureScript("npc_ire") {}
//
//        struct npc_ireAI : public ScriptedAI
//        {
//            npc_ireAI(Creature* creature) : ScriptedAI(creature){}
//            
//            void Reset()
//            {
//               // if (Unit* target = me->FocusTarget(15.0f, true))
//                 //   AttackStart(target);
//            }
//
//            void UpdateAI(uint32 diff)
//            {
//                DoMeleeAttackIfReady();
//            }
//        };
//
//        CreatureAI* GetAI(Creature* creature) const
//        {
//            return new npc_ireAI(creature);
//        }
//};
//
//class spell_sha_of_anger_aggressive_behaviour : public SpellScriptLoader
//{
//    public:
//        spell_sha_of_anger_aggressive_behaviour() : SpellScriptLoader("spell_sha_of_anger_aggressive_behaviour") { }
//
//        class spell_sha_of_anger_aggressive_behaviour_AuraScript : public AuraScript
//        {
//            PrepareAuraScript(spell_sha_of_anger_aggressive_behaviour_AuraScript);
//            uint32 factionSave;
//            bool pvpFlag;
//
//            void HandlePeriodicTick(AuraEffect const* /*aurEff*/)
//            {
//                PreventDefaultAction();
//                if (Unit* target = GetTarget())
//                    if (target->GetHealthPct() < 50.0f)
//                        this->Remove(AURA_REMOVE_BY_DEFAULT);
//            }
//
//            void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
//            {
//                pvpFlag = false;
//                if(Unit* target = GetTarget())
//                {
//                    if (!target->ToPlayer())
//                        return;
//                    
//                    target->SetPvP(true);
//                    target->SetFaction(16);
//                    //target->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PLAYER_CONTROLLED);
//                }
//
//            }
//
//            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
//            {
//                if(Unit* target = GetTarget())
//                {
//                    target->RestoreFaction();
//              //      target->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PLAYER_CONTROLLED);
//                }
//            }
//
//            void Register()
//            {
//                OnEffectPeriodic += AuraEffectPeriodicFn(spell_sha_of_anger_aggressive_behaviour_AuraScript::HandlePeriodicTick, EFFECT_5, SPELL_AURA_PERIODIC_DUMMY);
//                OnEffectApply += AuraEffectApplyFn(spell_sha_of_anger_aggressive_behaviour_AuraScript::OnApply, EFFECT_5, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
//                OnEffectRemove += AuraEffectRemoveFn(spell_sha_of_anger_aggressive_behaviour_AuraScript::OnRemove, EFFECT_5, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
//            }
//        };
//
//        AuraScript* GetAuraScript() const
//        {
//            return new spell_sha_of_anger_aggressive_behaviour_AuraScript();
//        }
//};
//
//void AddSC_boss_sha_of_anger()
//{
//    new boss_sha_of_anger();
//    new npc_bitter_thoughths();
//    new npc_ire();
//    new spell_sha_of_anger_aggressive_behaviour();
//}
