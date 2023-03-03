///*
//    World Boss: Ordos <Fire-God of the Yaungol>
//*/
//
//#include "ObjectMgr.h"
//#include "ScriptMgr.h"
//#include "ScriptedCreature.h"
//#include "CreatureTextMgr.h"
//#include "QuestDef.h"
//
//enum Texts
//{
//    SAY_AGGRO         = 0, // You will take my place on the eternal brazier.
//    SAY_DEATH         = 1, // The eternal fire will never be extinguished.
//    SAY_SLAY          = 2, // Up in smoke.
//    SAY_ANCIENT_FLAME = 3, // Your flesh will melt.
//    SAY_ETERNAL_AGONY = 4, // Your pain will be endless.
//    SAY_POOL_OF_FIRE  = 5, // You will feel but a fraction of my agony.
//    SAY_BURNING_SOUL  = 6  // Burn!
//};
//
//enum Spells
//{
//    SPELL_ANCIENT_FLAME_S   = 144695, // 40s
//    SPELL_ANCIENT_FLAME_A   = 144691, // Periodic dmg. aura.
//    SPELL_ANCIENT_FLAME_D   = 144699, // Dmg spell.
//    SPELL_BURNING_SOUL      = 144689, // 20s, every 30 s.
//    SPELL_BURNING_SOUL_EX   = 144690, // Removal Explode spell.
//    SPELL_MAGMA_CRUSH       = 144688, // 10s, every 15 s.
//    SPELL_POOL_OF_FIRE      = 144692, // 30s - Summon spell.
//    SPELL_POOL_OF_FIRE_A    = 144693, // Periodic dmg. aura.
//    SPELL_ETERNAL_AGONY     = 144696  // Enrage spell, 5 min.
//};
//
//enum Events
//{
//    EVENT_ANCIENT_FLAME    = 1,
//    EVENT_BURNING_SOUL     = 2,
//    EVENT_POOL_OF_FIRE     = 3,
//    EVENT_MAGMA_CRUSH      = 4,
//
//    EVENT_ETERNAL_AGONY    = 5 // Berserk.
//};
//
//enum Npcs
//{
//    NPC_ANCIENT_FLAME      = 72059
//};
//
//class boss_ordos : public CreatureScript
//{
//    public:
//        boss_ordos() : CreatureScript("boss_ordos") { }
//
//        struct boss_ordosAI : public ScriptedAI
//        {
//            boss_ordosAI(Creature* creature) : ScriptedAI(creature), summons(me) { }
//
//            EventMap _events;
//            SummonList summons;
//
//            void InitializeAI()
//            {
//                if (!me->isDead())
//                    Reset();
//            }
//            void Reset()
//            {
//                _events.Reset();
//                summons.DespawnAll();            
//            }   
//            void EnterCombat(Unit* /*who*/)
//            {
//                Talk(SAY_AGGRO);
//
//                _events.ScheduleEvent(EVENT_MAGMA_CRUSH, urand(10000, 13000)); // 10-13
//                _events.ScheduleEvent(EVENT_ANCIENT_FLAME, urand(40000, 45000)); // 40-45
//                _events.ScheduleEvent(EVENT_BURNING_SOUL, urand(20000, 30000)); // 20-30
//                _events.ScheduleEvent(EVENT_POOL_OF_FIRE, urand(30000, 45000)); // 30-40
//
//                _events.ScheduleEvent(EVENT_ETERNAL_AGONY, 300000); // Berserk. After 5 minutes.
//            }
//            void KilledUnit(Unit* victim)
//            {
//                if (victim->GetTypeId() == TYPEID_PLAYER)
//                    Talk(SAY_SLAY);
//            }
//            void EnterEvadeMode()
//            {
//                Reset();
//                me->DeleteThreatList();
//                me->CombatStop(false);
//                me->GetMotionMaster()->MoveTargetedHome();
//            }
//            void JustDied(Unit* /*killer*/)
//            {
//                Talk(SAY_DEATH);
//                summons.DespawnAll();
//           
//                /*
//                const std::list<HostileReference*>& threatlist = me->getThreatManager().getThreatList();
//
//                std::list<Unit*> targetList;
//                targetList.clear();
//                for (std::list<HostileReference*>::const_iterator itr = threatlist.begin(); itr != threatlist.end(); ++itr)
//                {
//                    std::list<Unit*>::iterator itr = targetList.begin();
//                    itr-
//                }    
//                */
//                /*
//                QueryResult result = CharacterDatabase.PQuery("SELECT guid, quest FROM character_queststatus_weekly WHERE id = %u", guid, 99999);
//
//                Field* dields = result->Fetch();
//                uint32 bop = dields[0].GetUInt32();
//                uint32 lb = dields[1].GetUInt32();
//                */
//          
//                Quest const* quest = sObjectMgr->GetQuestTemplate(99999);
//
//                if (!quest)
//                    return;
//
//                std::list<Player*> pl_list;
//                pl_list.clear();
//
//                me->GetPlayerListInGrid(pl_list, 50.0f);
//
//                if (pl_list.empty())
//                    return;
//
//                for (auto itr : pl_list)
//                {
//                    if (itr->CheckWeeklyCooldown(99999))
//                    {
//                        itr->AddQuest(quest, me);
//                        itr->CompleteQuest(99999);
//                        itr->RewardQuest(quest, 0, me, true);
//                        itr->SetWeeklyQuestStatus(99999);
//                    }
//                    else
//                    {
//                        ChatHandler(itr->GetSession()).PSendSysMessage("You are saved for this loot, this can only acquired once a week");
//                    }
//                }
//            }
//            void JustSummoned(Creature* summon)
//            {
//                summons.Summon(summon);
//                summon->setActive(true);
//
//		        if (me->isInCombat())
//                    summon->SetInCombatWithZone();
//
//                if (summon->GetEntry() == NPC_ANCIENT_FLAME)
//                {
//                    summon->AddAura(SPELL_ANCIENT_FLAME_A, summon);
//                    summon->SetReactState(REACT_PASSIVE);
//                }
//            }
//            void UpdateAI(const uint32 diff)
//            {
//                if (!UpdateVictim())
//                    return;
//
//                _events.Update(diff);
//
//                if (me->HasUnitState(UNIT_STATE_CASTING))
//                    return;
//
//                while (uint32 eventId = _events.ExecuteEvent())
//                {
//                    switch (eventId)
//                    {
//                        case EVENT_MAGMA_CRUSH:
//                            DoCastVictim(SPELL_MAGMA_CRUSH);
//                            _events.ScheduleEvent(EVENT_MAGMA_CRUSH, urand(7000, 27000));
//                            break;
//
//                        case EVENT_ANCIENT_FLAME:
//                            Talk(SAY_ANCIENT_FLAME);
//                            //DoCast(me, SPELL_ANCIENT_FLAME);
//                            _events.ScheduleEvent(EVENT_ANCIENT_FLAME, urand(40000, 45000));
//                            break;
//
//                        case EVENT_POOL_OF_FIRE:
//                            Talk(SAY_POOL_OF_FIRE);
//                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, NonTankTargetSelector(me)))
//                                DoCast(target, SPELL_POOL_OF_FIRE);
//                            _events.ScheduleEvent(EVENT_POOL_OF_FIRE, urand(30000, 40000));
//                            break;
//
//                        case EVENT_BURNING_SOUL:
//                            Talk(SAY_BURNING_SOUL);
//                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, NonTankTargetSelector(me)))
//                                DoCast(target, SPELL_BURNING_SOUL);
//                            _events.ScheduleEvent(EVENT_BURNING_SOUL, urand(10000, 25000));
//                            break;
//
//                        case EVENT_ETERNAL_AGONY: // Berserk.
//                            Talk(SAY_ETERNAL_AGONY);
//                            DoCast(me, SPELL_ETERNAL_AGONY);
//                            _events.ScheduleEvent(EVENT_ETERNAL_AGONY, urand(20000, 25000));
//                            break;
//
//                        default: break;
//                    }
//                }
//
//                DoMeleeAttackIfReady();
//            }
//        };
//
//        CreatureAI* GetAI(Creature* creature) const
//        {
//            return new boss_ordosAI(creature);
//        }
//};
//
//// Ancient Flames 144691.
//class spell_ancient_flames : public SpellScriptLoader
//{
//    public:
//        spell_ancient_flames() : SpellScriptLoader("spell_ancient_flames") { }
//
//    private:
//        class spell_ancient_flames_AuraScript : public AuraScript
//        {
//            PrepareAuraScript(spell_ancient_flames_AuraScript)
//
//            void HandlePeriodicTick(constAuraEffectPtr /*aurEff*/)
//            {
//                PreventDefaultAction();
//                if (Unit* target = ObjectAccessor::GetUnit(*GetCaster(), GetCaster()->GetUInt64Value(UNIT_FIELD_CHANNEL_OBJECT)))
//                    GetCaster()->CastSpell(target, GetSpellInfo()->Effects[EFFECT_0].TriggerSpell, true); // SPELL_ANCIENT_FLAME_D
//            }
//
//            void Register()
//            {
//                OnEffectPeriodic += AuraEffectPeriodicFn(spell_ancient_flames_AuraScript::HandlePeriodicTick, EFFECT_1, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
//            }
//        };
//
//        AuraScript* GetAuraScript() const
//        {
//            return new spell_ancient_flames_AuraScript();
//        }
//};
//
//// Ordos Burning Soul 144689.
//class spell_ordos_burning_soul_aura : public SpellScriptLoader
//{
//    public:
//        spell_ordos_burning_soul_aura() : SpellScriptLoader("spell_ordos_burning_soul_aura") { }
//
//        class spell_ordos_burning_soul_aura_AuraScript : public AuraScript
//        {
//            PrepareAuraScript(spell_ordos_burning_soul_aura_AuraScript);
//
//            void OnRemove(constAuraEffectPtr /*aurEff*/, AuraEffectHandleModes /*mode*/)
//            {
//                switch (GetTargetApplication()->GetRemoveMode())
//                {
//                    case AURA_REMOVE_BY_EXPIRE: // On expire.
//                        break;
//
//                    default: return;
//                }
//
//                GetTarget()->CastSpell(GetTarget(), SPELL_BURNING_SOUL_EX, true);
//            }
//
//            void Register()
//            {
//                AfterEffectRemove += AuraEffectRemoveFn(spell_ordos_burning_soul_aura_AuraScript::OnRemove, EFFECT_1, SPELL_AURA_MOD_FEAR, AURA_EFFECT_HANDLE_REAL);
//            }
//        };
//
//        AuraScript* GetAuraScript() const
//        {
//            return new spell_ordos_burning_soul_aura_AuraScript();
//        }
//};
//
//void AddSC_boss_ordos()
//{
//    new boss_ordos();
//    new spell_ancient_flames();
//    new spell_ordos_burning_soul_aura();
//}
