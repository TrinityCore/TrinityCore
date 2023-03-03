//
//#include "ObjectMgr.h"
//#include "Player.h"
//#include "ScriptMgr.h"
//#include "ScriptedCreature.h"
//#include "AchievementMgr.h"
//
//enum Spells
//{
//	TEMPEST_SLASH_TRIGGER_VISUAL = 122854,
//	TEMPEST_SLASH_ADDON_SPELL = 122842,
//
//	INTESIFY = 123471,
//
//	WIND_STEP = 123175,
//
//	SPELL_UNSEEN_STRIKE_TARGET = 123017,
//	SPELL_UNSEEN_STRIKE = 122949,
//	UNSEEN_STRIKE_DMG_SPELL = 122994,
//
//	OVERWHELMING_ASSAULT = 123474,
//
//	// Phase 2
//	TORNADO_VISUAL_PLAYER_EFFECT = 125398,
//	TORNADO_NPC_VISUAL = 122842,
//	TORNADO_PLAYER_JUMP = 125327,
//	TORANDO_BOSS_VISUAL = 123598,
//
//    SPELL_TAYAK_BERSERK = 26662,
//};
//enum Mobs
//{
//	TEMPEST_SLASH_TRIGGER = 9432545,
//
//	// phase 2
//	PHASE_2_RIGHT_TRONADO = 2321432,
//	PHASE_2_LEFT_TRONADO = 2121433,
//	PHASE_2_DEACTIVATE_TRIGGER = 4324325,
//};
//enum Events
//{
//	EVENT_TEMPEST_SLASH = 1,
//	EVENT_TEMPEST_SLASH_SUMMON = 2,
//	EVENT_TEMPEST_SLASH_SUMMON_RANDOM_MOVEMENT = 3,
//
//	EVENT_WIND_STEP = 4,
//
//	EVENT_INTENSIFY = 5,
//
//	EVENT_UNSEEN_STRIKE = 6,
//
//	EVENT_OVERWHELMING_ASSAULT = 7,
//
//	// phase 2
//	SIDE_A_TORNADO = 8,
//	SIDE_B_TORNADO = 9,
//	
//	EVENT_DRAG_ALL_SIDE_A = 10,
//	EVENT_DRAG_ALL_SIDE_B = 11,
//
//	DISABLE_MOVEMENT = 12,
//
//	SUMMON_TORNADO_A = 13,
//	SUMMON_TORNADO_B = 14,
//
//	EVENT_UNSEEN_STRIKE_DMG = 15,
//
//    EVENT_TAYAK_BERSERK = 16,
//};
//Position const GhostGates[13] =
//{
//	{ -2139.68f, 223.62f, 421.404f, 3.178375f },
//	{ -2131.85f, 282.05f, 420.900f, 3.209791f },
//	{ -2129.44f, 254.02f, 421.064f, 3.166596f },
//	{ -2128.73f, 225.47f, 420.900f, 3.166596f },
//	{ -2127.97f, 195.09f, 421.626f, 3.166596f },
//	{ -2128.41f, 310.90f, 420.900f, 3.116169f },
//	{ -2130.58f, 338.06f, 420.900f, 3.087918f },
//	{ -2107.83f, 339.86f, 420.900f, 6.245404f },
//	{ -2108.99f, 309.15f, 421.056f, 6.245404f },
//	{ -2109.89f, 285.44f, 420.900f, 6.245404f },
//	{ -2110.79f, 261.65f, 420.900f, 6.245404f },
//	{ -2109.40f, 235.82f, 420.900f, 6.245404f },
//	{ -2110.26f, 213.09f, 420.900f, 6.245404f },
//};
//
//class boss_lord_tayak : public CreatureScript
//{
//public:
//	boss_lord_tayak() : CreatureScript("boss_lord_tayak") { }
//
//	struct boss_lord_tayakAI : public BossAI
//	{
//		boss_lord_tayakAI(Creature* creature) : BossAI(creature, 0)
//		{
//			me->SetLevel(94);
//			me->setFaction(16);
//			me->SetSpeed(MOVE_RUN, 3.5f, true);
//			me->SetSpeed(MOVE_FLIGHT, 3.5f, true);
//
//			/*
//			if (IsHeroic() && Is25ManRaid())
//			{
//				me->SetMaxHealth(527943840);
//				me->SetHealth(527943840);
//			}
//			else if (Is25ManRaid())
//			{
//				me->SetMaxHealth(406261600);
//				me->SetHealth(406261600);
//			}
//			else if (IsHeroic())
//			{
//				me->SetMaxHealth(196261648);
//				me->SetHealth(196261648);
//			}
//			else
//			{
//				me->SetMaxHealth(150467264);
//				me->SetHealth(150467264);
//			}
//			*/
//		}
//
//		InstanceScript* instance;
//		bool cdchange;
//		bool cdchange2;
//
//		void Reset()
//		{
//			_Reset();
//
//			cdchange = false;
//			cdchange2 = false;
//		}
//		void EnterCombat(Unit* who)
//		{
//			_EnterCombat();
//
//			// Cancel
//			events.CancelEvent(EVENT_TEMPEST_SLASH);
//			events.CancelEvent(EVENT_WIND_STEP);
//			events.CancelEvent(EVENT_INTENSIFY);
//			events.CancelEvent(EVENT_UNSEEN_STRIKE);
//			events.CancelEvent(EVENT_OVERWHELMING_ASSAULT);
//            events.CancelEvent(EVENT_TAYAK_BERSERK);
//
//			// Say AGGRO
//			me->MonsterYell("On your guard invadors! I Ta'yak lord of blades will be your opponent.", LANG_UNIVERSAL, me->GetGUID());
//			DoPlaySoundToSet(me, 29252);
//
//			// Events
//			events.ScheduleEvent(EVENT_UNSEEN_STRIKE, 60000);
//			events.ScheduleEvent(EVENT_TEMPEST_SLASH, 10000);
//			events.ScheduleEvent(EVENT_WIND_STEP, 14000);
//			events.ScheduleEvent(EVENT_INTENSIFY, 30000);
//			events.ScheduleEvent(EVENT_UNSEEN_STRIKE, 24000);
//			events.ScheduleEvent(EVENT_OVERWHELMING_ASSAULT, 30000);
//            // 8:15 minutes Enrage timer
//            events.ScheduleEvent(EVENT_TAYAK_BERSERK, 495000);
//
//			// Spawn door -- vizier entrance middle
//			me->SummonGameObject(183847, -2187.371857f, 281.407440f, 423.931305f, 0.008068f, 0,0,0,0,0,0);
//
//			// Spawn other exit door
//			me->SummonGameObject(180322, -2120.730957f, 385.181702f, 422.534668f, 1.507048f, 0,0,0,0,0,0);
//
//		}
//		void JustReachedHome()
//		{
//			//instance->SetBossState(DATA_TAYAK, FAIL);
//			summons.DespawnAll();
//			std::list<GameObject*> Ghost_list;
//
//			if (GameObject* door = me->FindNearestGameObject(183847, 300.0f))
//				door->Delete();
//
//			me->GetGameObjectListWithEntryInGrid(Ghost_list, 180322, 300.0f);
//
//			for (std::list<GameObject*>::const_iterator itr = Ghost_list.begin(); itr != Ghost_list.end(); itr++)
//			{
//				if ((*itr) && (*itr)->IsInWorld())
//				(*itr)->Delete();
//				//(*itr)->DeleteFromDB(); 
//			}
//		}
//		void DamageTaken(Unit* attacker, uint32& damage)
//		{
//			if (!me->HealthAbovePct(23) && !cdchange) // ramps changes
//			{
//				cdchange = true;
//				events.CancelEvent(EVENT_WIND_STEP);
//				events.CancelEvent(EVENT_TEMPEST_SLASH);
//				events.CancelEvent(EVENT_UNSEEN_STRIKE);
//				events.CancelEvent(EVENT_OVERWHELMING_ASSAULT);
//				events.ScheduleEvent(EVENT_INTENSIFY, 30000);
//
//				me->DespawnCreaturesInArea(9432545); // despawns tornados	
//
//				me->AddAura(69652, me);
//				me->AddAura(123598, me);
//
//				if (me->HasAura(69652))
//				{
//					AuraPtr BS = me->GetAura(69652);
//					if (BS)
//						BS->SetDuration(10000000);
//				}
//				events.ScheduleEvent(SIDE_A_TORNADO, 1000);
//
//				me->SummonCreature(PHASE_2_DEACTIVATE_TRIGGER, -2111.67f, 350.64f, 420.899994f);
//			}
//			if (!me->HealthAbovePct(10) && !cdchange2) // ramps changes
//			{
//				me->DespawnCreaturesInArea(PHASE_2_DEACTIVATE_TRIGGER);
//
//				cdchange2 = true;
//				events.CancelEvent(SIDE_A_TORNADO);
//
//				me->DespawnCreaturesInArea(9432545);
//				me->DespawnCreaturesInArea(PHASE_2_DEACTIVATE_TRIGGER);
//
//				events.ScheduleEvent(SIDE_B_TORNADO, 1000);
//
//				me->SummonCreature(PHASE_2_DEACTIVATE_TRIGGER, -2112.29f, 208.94f, 420.899994f);
//			}
//		}
//		void UpdateAI(uint32 const diff)
//		{
//			events.Update(diff);
//
//			if (!UpdateVictim())
//				return;
//
//			while (uint32 eventId = events.ExecuteEvent())
//			{
//				switch (eventId)
//				{
//					// Phase 2
//				case SIDE_A_TORNADO:
//				{
//					me->SummonGameObject(180322, -2139.68f, 223.62f, 421.404f, 3.178375f, 0, 0, 0, 0, 0, 0);
//					me->SummonGameObject(180322, -2139.68f, 223.62f, 421.404f, 3.178375f, 0, 0, 0, 0, 0, 0);
//					me->SummonGameObject(180322, -2131.85f, 282.05f, 420.900f, 3.209791f, 0, 0, 0, 0, 0, 0);
//					me->SummonGameObject(180322, -2129.44f, 254.02f, 421.064f, 3.166596f, 0, 0, 0, 0, 0, 0);
//					me->SummonGameObject(180322, -2127.97f, 195.09f, 421.626f, 3.166596f, 0, 0, 0, 0, 0, 0);
//					me->SummonGameObject(180322, -2128.41f, 310.90f, 420.900f, 3.116169f, 0, 0, 0, 0, 0, 0);
//					me->SummonGameObject(180322, -2130.58f, 338.06f, 420.900f, 3.087918f, 0, 0, 0, 0, 0, 0);
//					me->SummonGameObject(180322, -2107.83f, 339.86f, 420.900f, 6.245404f, 0, 0, 0, 0, 0, 0);
//					me->SummonGameObject(180322, -2108.99f, 309.15f, 421.056f, 6.245404f, 0, 0, 0, 0, 0, 0);
//					me->SummonGameObject(180322, -2109.89f, 285.44f, 420.900f, 6.245404f, 0, 0, 0, 0, 0, 0);
//					me->SummonGameObject(180322, -2110.79f, 261.65f, 420.900f, 6.245404f, 0, 0, 0, 0, 0, 0);
//					me->SummonGameObject(180322, -2109.89f, 285.44f, 420.900f, 6.245404f, 0, 0, 0, 0, 0, 0);
//					me->SummonGameObject(180322, -2109.40f, 235.82f, 420.900f, 6.245404f, 0, 0, 0, 0, 0, 0);
//					me->SummonGameObject(180322, -2110.26f, 213.09f, 420.900f, 6.245404f, 0, 0, 0, 0, 0, 0);
//				
//					if (MotionMaster* motion = me->GetMotionMaster())
//					{
//						me->SetSpeed(MOVE_RUN, 50.0f, true);
//
//						motion->MovePoint(1, -2119.330811f, 291.268768f, 420.900604f);
//	
//						me->CastSpell(me ,125310);
//
//
//						events.ScheduleEvent(EVENT_DRAG_ALL_SIDE_A, 3000);
//					}
//				}
//					break;
//				case EVENT_DRAG_ALL_SIDE_A:
//				{
//					if (MotionMaster* motion = me->GetMotionMaster())
//					{
//						std::list<Player*> Players;
//						JadeCore::AnyPlayerInObjectRangeCheck u_check(me, 50.0f);
//						JadeCore::PlayerListSearcher <JadeCore::AnyPlayerInObjectRangeCheck> searcher(me, Players, u_check);
//						me->VisitNearbyObject(50.0f, searcher);
//
//
//						for (std::list<Player*>::const_iterator it = Players.begin(); it != Players.end(); ++it)
//						{
//							if (!(*it))
//								return;
//
//							(*it)->SummonCreature(PHASE_2_RIGHT_TRONADO, (*it)->GetPositionX(), (*it)->GetPositionY(), (*it)->GetPositionZ(), (*it)->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN, 4000);
//						}
//
//						motion->MovePoint(1, -2119.229248f, 185.237350f, 422.161530f); // actual position
//						events.ScheduleEvent(DISABLE_MOVEMENT, 2500);
//						events.ScheduleEvent(SUMMON_TORNADO_A, 1000);
//					}	
//					break;
//				}
//				case DISABLE_MOVEMENT:
//					me->SetSpeed(MOVE_RUN, 0.0f, true);
//					break;		
//				case SIDE_B_TORNADO:
//					if (MotionMaster* motion = me->GetMotionMaster())
//					{
//						events.CancelEvent(SUMMON_TORNADO_A);
//
//						me->SetSpeed(MOVE_RUN, 50.0f, true);
//
//						motion->MovePoint(1, -2119.330811f, 291.268768f, 420.900604f);
//
//						me->CastSpell(me, 125310);
//
//						events.ScheduleEvent(EVENT_DRAG_ALL_SIDE_B, 3000);
//					}
//					break;
//				case EVENT_DRAG_ALL_SIDE_B:
//				{
//					if (MotionMaster* motion = me->GetMotionMaster())
//					{
//						std::list<Player*> Players;
//						JadeCore::AnyPlayerInObjectRangeCheck u_check(me, 50.0f);
//						JadeCore::PlayerListSearcher <JadeCore::AnyPlayerInObjectRangeCheck> searcher(me, Players, u_check);
//						me->VisitNearbyObject(50.0f, searcher);
//
//
//						for (std::list<Player*>::const_iterator it = Players.begin(); it != Players.end(); ++it)
//						{
//							if (!(*it))
//								return;
//
//							(*it)->SummonCreature(PHASE_2_LEFT_TRONADO, (*it)->GetPositionX(), (*it)->GetPositionY(), (*it)->GetPositionZ(), (*it)->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN, 4000);
//						}
//
//						motion->MovePoint(1, -2118.701416f, 380.399536f, 422.161560f); // actual position _ 2
//						events.ScheduleEvent(DISABLE_MOVEMENT, 2500);
//						events.ScheduleEvent(SUMMON_TORNADO_B, 1000);
//					}
//					break;
//				}
//				case SUMMON_TORNADO_A:
//				{
//					switch (urand(0, 2))
//					{
//					case 0:
//					{
//						Creature* L = me->SummonCreature(PHASE_2_RIGHT_TRONADO, -2111.67f, 210.71f, 420.900f, 1.630864f, TEMPSUMMON_TIMED_DESPAWN, 10000);
//						if (MotionMaster* motion = L->GetMotionMaster())
//							motion->MovePoint(1, -2111.67f, 350.64f, 420.899994f);
//						break;
//					}
//					case 1:
//					{
//						Creature* R = me->SummonCreature(PHASE_2_RIGHT_TRONADO, -2127.37f, 209.73f, 420.900f, 1.560178f, TEMPSUMMON_TIMED_DESPAWN, 10000);
//						if (MotionMaster* motion = R->GetMotionMaster())
//							motion->MovePoint(1, -2127.03f, 352.90f, 420.899994f);
//						break;
//					}
//					case 2:
//					{
//						Creature* F = me->SummonCreature(PHASE_2_RIGHT_TRONADO, -2118.90f, 209.96f, 420.900f, 1.591594f, TEMPSUMMON_TIMED_DESPAWN, 10000);
//						if (MotionMaster* motion = F->GetMotionMaster())
//							motion->MovePoint(1, -2119.54f, 358.99f, 420.900330f);
//						break;
//					}
//					}
//	
//					events.ScheduleEvent(SUMMON_TORNADO_A, urand(1500, 2500));
//				}
//					break;
//				case SUMMON_TORNADO_B:
//				{
//					switch (urand(0, 2))
//					{
//					case 0:
//					{
//						Creature* L = me->SummonCreature(PHASE_2_LEFT_TRONADO, -2111.67f, 350.64f, 420.899994f, me->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN, 10000);
//						if (MotionMaster* motion = L->GetMotionMaster())
//							motion->MovePoint(1, -2112.29f, 208.94f, 420.899994f);
//						break;
//					}
//					case 1:
//					{
//						Creature* R = me->SummonCreature(PHASE_2_LEFT_TRONADO, -2127.03f, 352.90f, 420.899994f, me->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN, 10000);
//						if (MotionMaster* motion = R->GetMotionMaster())
//							motion->MovePoint(1, -2128.49f, 214.93f, 420.899994f);
//						break;
//					}
//					case 2:
//					{
//						Creature* F = me->SummonCreature(PHASE_2_LEFT_TRONADO, -2119.54f, 358.99f, 420.900330f, me->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN, 10000);
//						if (MotionMaster* motion = F->GetMotionMaster())
//							motion->MovePoint(1, -2118.81f, 206.04f, 420.900330f);
//						break;
//					}
//					}
//					
//					events.ScheduleEvent(SUMMON_TORNADO_B, urand(1500, 2500));
//				}
//					break;
//					// Phase 1
//					// Tempest Slash
//				case EVENT_TEMPEST_SLASH:
//					me->CastSpell(me, TEMPEST_SLASH_ADDON_SPELL);
//
//					events.ScheduleEvent(EVENT_TEMPEST_SLASH, 16000);
//					events.ScheduleEvent(EVENT_TEMPEST_SLASH_SUMMON, 2500);
//					break;
//				case EVENT_TEMPEST_SLASH_SUMMON:
//				{
//					Creature* Tornado = me->SummonCreature(TEMPEST_SLASH_TRIGGER, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation());
//
//                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 20, true))
//                    {
//                        if (MotionMaster* motion = Tornado->GetMotionMaster())
//                        {
//                            motion->MovePoint(1, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ());
//                        }
//                    }
//					break;
//				}
//					// Random Shadow Step
//				case EVENT_WIND_STEP:
//					if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 20, true))
//					{
//						me->CastSpell(target, WIND_STEP);
//						events.ScheduleEvent(EVENT_WIND_STEP, 17000);
//					}
//					break;
//				case EVENT_INTENSIFY:
//					if (!me->HasAura(INTESIFY))
//					{
//						me->AddAura(INTESIFY, me);
//						// Say Inhale
//					}
//					else
//					{
//						AuraPtr aura_B = me->GetAura(INTESIFY);
//
//						if (aura_B)
//						{
//							// Say Inhale
//							aura_B->SetStackAmount(aura_B->GetStackAmount() + 1);
//						}
//					}
//					events.ScheduleEvent(EVENT_INTENSIFY, 30000);
//					break;
//				case EVENT_UNSEEN_STRIKE:
//					if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 20, true))
//					{
//						events.CancelEvent(EVENT_WIND_STEP);
//						events.CancelEvent(EVENT_TEMPEST_SLASH);
//
//                        me->MonsterTextEmote("Blade Lord Ta'yak marks a player with [Unseen Strike]", me->GetGUID(), true);
//
//						me->AddAura(SPELL_UNSEEN_STRIKE_TARGET, target);			
//						events.ScheduleEvent(EVENT_UNSEEN_STRIKE_DMG, 6000);
//
//						events.ScheduleEvent(EVENT_UNSEEN_STRIKE, 80000);
//						events.ScheduleEvent(EVENT_WIND_STEP, 14000);
//						events.ScheduleEvent(EVENT_TEMPEST_SLASH, 10000);
//					}
//					break;
//				case EVENT_UNSEEN_STRIKE_DMG:
//				{
//					std::list<Player*> PL_list;
//
//					JadeCore::AnyPlayerInObjectRangeCheck check(me, 40.0f);
//					JadeCore::PlayerListSearcher<JadeCore::AnyPlayerInObjectRangeCheck> searcher(me, PL_list, check);
//					me->VisitNearbyObject(40.0f, searcher);
//
//					for (std::list<Player*>::const_iterator it = PL_list.begin(); it != PL_list.end(); ++it)
//					{
//						if (!(*it))
//							return;
//
//						if ((*it)->HasAura(SPELL_UNSEEN_STRIKE_TARGET))
//						{
//                            me->Attack((*it), true);
//							me->CastSpell((*it), UNSEEN_STRIKE_DMG_SPELL);
//						}
//					}
//					break;
//				}
//				case EVENT_OVERWHELMING_ASSAULT:
//					me->CastSpell(me->getVictim(), OVERWHELMING_ASSAULT);
//					events.ScheduleEvent(EVENT_OVERWHELMING_ASSAULT, urand(25000, 30000));
//					break;
//                case EVENT_TAYAK_BERSERK: // Nasty if you're here!
//                {
//                    me->AddAura(SPELL_TAYAK_BERSERK, me);
//                    break;
//                }
//				}
//			}
//			DoMeleeAttackIfReady();
//		}
//		void JustDied(Unit* killer)
//		{
//			_JustDied();
//	
//			me->MonsterYell("I always hoped to cut someone like that someday, to hear that sound.. but to have it happen to my own pedorax.. is.. ridiculous", LANG_UNIVERSAL, me->GetGUID());
//			DoPlaySoundToSet(me, 29253);
//
//			std::list<GameObject*> Ghost_list;
//
//			if (GameObject* door = me->FindNearestGameObject(183847, 300.0f))
//				door->Delete();
//
//			me->GetGameObjectListWithEntryInGrid(Ghost_list, 180322, 300.0f);
//
//			for (std::list<GameObject*>::const_iterator itr = Ghost_list.begin(); itr != Ghost_list.end(); itr++)
//			{
//				if ((*itr) && (*itr)->IsInWorld())
//					(*itr)->Delete();
//				//(*itr)->DeleteFromDB(); 
//			}
//		}
//		void KilledUnit(Unit* victim)
//		{
//			if (victim->GetTypeId() == TYPEID_PLAYER)
//			{
//				switch (urand(0, 1))
//				{
//				case 0:
//					me->MonsterYell("A perfect cut!", LANG_UNIVERSAL, me->GetGUID());
//					DoPlaySoundToSet(me, 29259);
//					break;
//				case 1:
//					me->MonsterYell("This is the tecnique of a Blade Lord!", LANG_UNIVERSAL, me->GetGUID());
//					DoPlaySoundToSet(me, 29260);
//					break;
//				}
//			}
//		}
//	private:
//		EventMap events;
//	};
//
//	CreatureAI* GetAI(Creature* creature) const
//	{
//		return new boss_lord_tayakAI(creature);
//	}
//};
//class wind_step_lord_tayak : public SpellScriptLoader
//{
//public:
//	wind_step_lord_tayak() : SpellScriptLoader("wind_step_lord_tayak") { }
//
//	class wind_step_lord_tayak_spell : public SpellScript
//	{
//		PrepareSpellScript(wind_step_lord_tayak_spell);
//
//		void HAfterHit()
//		{
//			if (!GetCaster())
//				return;
//
//			if (!GetHitUnit())
//				return;
//
//			Unit* target = GetHitUnit();
//
//			std::list<Player*> PL_list;
//
//			JadeCore::AnyPlayerInObjectRangeCheck check(target, 4.0f);
//			JadeCore::PlayerListSearcher<JadeCore::AnyPlayerInObjectRangeCheck> searcher(target, PL_list, check);
//			target->VisitNearbyObject(4.0f, searcher);
//
//			for (std::list<Player*>::const_iterator it = PL_list.begin(); it != PL_list.end(); ++it)
//			{
//				if (!(*it))
//					return;
//
//				if (target->IsWithinDistInMap((*it), 4.0f, true))
//				{
//					GetCaster()->AddAura(123180, (*it));
//				}
//			}
//		}
//
//		void Register()
//		{
//			AfterHit += SpellHitFn(wind_step_lord_tayak_spell::HAfterHit);
//		}
//	};
//
//	SpellScript* GetSpellScript() const
//	{
//		return new wind_step_lord_tayak_spell;
//	}
//};
//
//class tempest_pull_all : public SpellScriptLoader
//{
//public:
//	tempest_pull_all() : SpellScriptLoader("tempest_pull_all") { }
//
//	class tempest_pull_all_spell : public SpellScript
//	{
//		PrepareSpellScript(tempest_pull_all_spell);
//
//		void HAfterCast()
//		{
//			if (!GetCaster())
//				return;
//
//			Creature* me = GetCaster()->ToCreature();
//
//			if (!me)
//				return;
//
//			std::list<Player*> Players;
//			JadeCore::AnyPlayerInObjectRangeCheck u_check(me, 100.0f);
//			JadeCore::PlayerListSearcher <JadeCore::AnyPlayerInObjectRangeCheck> searcher(me, Players, u_check);
//			me->VisitNearbyObject(50.0f, searcher);
//
//
//			for (std::list<Player*>::const_iterator it = Players.begin(); it != Players.end(); ++it)
//			{
//				if (!(*it))
//					return;
//
//				(*it)->CastSpell(me, TORNADO_PLAYER_JUMP);
//			}
//		}
//
//		void Register()
//		{
//			AfterCast += SpellCastFn(tempest_pull_all_spell::HAfterCast);
//		}
//	};
//
//	SpellScript* GetSpellScript() const
//	{
//		return new tempest_pull_all_spell;
//	}
//};
//class npc_tornado_lord_tayak : public CreatureScript
//{
//public:
//	npc_tornado_lord_tayak() : CreatureScript("npc_tornado_lord_tayak") { }
//
//	struct npc_tornado_lord_tayakAI : public CreatureAI
//	{
//		npc_tornado_lord_tayakAI(Creature* creature) : CreatureAI(creature)
//		{
//			me->SetObjectScale(1.0f);
//		}
//
//        uint32 effectcanstart;
//        bool caneffectstart;
//
//		void Reset()
//		{
//			me->SetSpeed(MOVE_RUN, 2.0F, true);
//			me->setFaction(me->getFaction());
//			me->AddAura(TEMPEST_SLASH_TRIGGER_VISUAL, me);
//
//            effectcanstart = 3000;
//            caneffectstart = false;
//		}
//
//		void UpdateAI(uint32 const diff)
//		{
//			events.Update(diff);
//
//            if (effectcanstart <= diff)
//            {
//                caneffectstart = true;
//            }
//            else
//                effectcanstart -= diff;
//
//
//            if (caneffectstart)
//            {
//                std::list<Player*> PL_list;
//
//                JadeCore::AnyPlayerInObjectRangeCheck check(me, 1.4f);
//                JadeCore::PlayerListSearcher<JadeCore::AnyPlayerInObjectRangeCheck> searcher(me, PL_list, check);
//                me->VisitNearbyObject(1.4f, searcher);
//
//                for (std::list<Player*>::const_iterator it = PL_list.begin(); it != PL_list.end(); ++it)
//                {
//                    if (!(*it))
//                        return;
//
//                    (*it)->KnockbackFrom(me->GetPositionX(), me->GetPositionY(), 10, 8);
//                    //me->DealDamage((*it), 20000, NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
//                    (*it)->EnvironmentalDamage(DAMAGE_FIRE, 20000);
//                }
//            }
//		}
//	private:
//		EventMap events;
//		std::list<Player*> Player_List;
//	};
//
//	CreatureAI* GetAI(Creature* creature) const
//	{
//		return new npc_tornado_lord_tayakAI(creature);
//	}
//};
//class deactivate_phase_2_tornado_effect : public CreatureScript
//{
//public:
//	deactivate_phase_2_tornado_effect() : CreatureScript("deactivate_phase_2_tornado_effect") { }
//
//	struct deactivate_phase_2_tornado_effectAI : public CreatureAI
//	{
//		deactivate_phase_2_tornado_effectAI(Creature* creature) : CreatureAI(creature)
//		{
//			me->SetObjectScale(1.0f);
//		}
//		void UpdateAI(uint32 const diff)
//		{
//			events.Update(diff);
//
//			std::list<Player*> PL_list;
//
//			JadeCore::AnyPlayerInObjectRangeCheck check(me, 8.0F);
//			JadeCore::PlayerListSearcher<JadeCore::AnyPlayerInObjectRangeCheck> searcher(me, PL_list, check);
//			me->VisitNearbyObject(8.0F, searcher);
//
//			for (std::list<Player*>::const_iterator it = PL_list.begin(); it != PL_list.end(); ++it)
//			{
//				if (!(*it))
//					return;
//
//				if ((*it)->HasAura(37640))
//				{
//					(*it)->RemoveAura(37640);
//				}
//				if ((*it)->HasAura(TEMPEST_SLASH_TRIGGER_VISUAL))
//				{
//					(*it)->RemoveAura(TEMPEST_SLASH_TRIGGER_VISUAL);
//				}
//
//				(*it)->SetSpeed(MOVE_RUN, 1.2f, false);
//			}
//		}
//	private:
//		EventMap events;
//		std::list<Player*> Player_List;
//	};
//
//	CreatureAI* GetAI(Creature* creature) const
//	{
//		return new deactivate_phase_2_tornado_effectAI(creature);
//	}
//};
//class npc_tornado_lord_tayak_phase2_Left : public CreatureScript
//{
//public:
//	npc_tornado_lord_tayak_phase2_Left() : CreatureScript("npc_tornado_lord_tayak_phase2_Left") { }
//
//	struct npc_tornado_lord_tayakAI : public CreatureAI
//	{
//		npc_tornado_lord_tayakAI(Creature* creature) : CreatureAI(creature)
//		{
//			me->SetObjectScale(1.0f);
//		}
//		bool Fetch;
//		void Reset()
//		{
//			Fetch = false;
//
//			me->SetSpeed(MOVE_RUN, 3.0F, true);
//			me->setFaction(me->getFaction());
//			me->AddAura(TEMPEST_SLASH_TRIGGER_VISUAL, me);
//		}
//		void UpdateAI(uint32 const diff)
//		{
//			events.Update(diff);
//
//			std::list<Player*> PL_list;
//
//			if (TempSummon* tempo = me->ToTempSummon())
//			{
//				if (tempo->GetSummoner()->GetTypeId() == TYPEID_PLAYER)
//				{
//					if (Player* pl = tempo->GetSummoner()->ToPlayer())
//					{
//						if (MotionMaster* motion = pl->GetMotionMaster())
//						{
//								if (pl->IsWithinDistInMap(me, 1.2f, true))
//								{
//									if (!Fetch)
//									{
//										Fetch = true;
//
//										me->DespawnOrUnsummon(1000);
//										pl->AddAura(37640, pl);
//										pl->AddAura(TEMPEST_SLASH_TRIGGER_VISUAL, pl);
//										
//										pl->SetSpeed(MOVE_RUN, 4.0f);
//										motion->MovePoint(1, -2118.761230f, 365.442505f, 420.900513f);
//									}
//								}
//						}
//					}
//				}
//				else if (tempo->GetSummoner()->GetTypeId() != TYPEID_PLAYER)
//				{
//					std::list<Player*> PL_list;
//
//					JadeCore::NearestPlayerInObjectRangeCheck check(me, 1.0f);
//					JadeCore::PlayerListSearcher<JadeCore::NearestPlayerInObjectRangeCheck> searcher(me, PL_list, check);
//					me->VisitNearbyObject(1.0f, searcher);
//
//					for (std::list<Player*>::const_iterator it = PL_list.begin(); it != PL_list.end(); ++it)
//					{
//						if (!(*it))
//							return;
//
//						if (!Fetch)
//						{
//							Fetch = true;
//							if (MotionMaster* motion = (*it)->GetMotionMaster())
//							{
//									me->DespawnOrUnsummon(1000);
//									(*it)->SetSpeed(MOVE_RUN, 4.0f);
//									(*it)->AddAura(37640, (*it));
//									(*it)->AddAura(TEMPEST_SLASH_TRIGGER_VISUAL, (*it));
//									motion->MovePoint(1, -2118.761230f, 365.442505f, 420.900513f);
//							}
//						}
//					}
//				}
//			}
//		}
//	private:
//		EventMap events;
//		std::list<Player*> Player_List;
//	};
//
//	CreatureAI* GetAI(Creature* creature) const
//	{
//		return new npc_tornado_lord_tayakAI(creature);
//	}
//};
//class npc_tornado_lord_tayak_phase2_Right : public CreatureScript
//{
//public:
//	npc_tornado_lord_tayak_phase2_Right() : CreatureScript("npc_tornado_lord_tayak_phase2_Right") { }
//
//	struct npc_tornado_lord_tayakAI : public CreatureAI
//	{
//		npc_tornado_lord_tayakAI(Creature* creature) : CreatureAI(creature)
//		{
//			me->SetObjectScale(1.0f);
//		}
//		bool Fetch;
//		void Reset()
//		{
//			Fetch = false;
//
//			me->SetSpeed(MOVE_RUN, 3.0F, true);
//			me->setFaction(me->getFaction());
//			me->AddAura(TEMPEST_SLASH_TRIGGER_VISUAL, me);
//		}
//
//		void UpdateAI(uint32 const diff)
//		{
//			events.Update(diff);
//
//			std::list<Player*> PL_list;
//
//			if (TempSummon* tempo = me->ToTempSummon())
//			{
//				if (tempo->GetSummoner()->GetTypeId() == TYPEID_PLAYER)
//				{
//					if (Player* pl = tempo->GetSummoner()->ToPlayer())
//					{
//						if (MotionMaster* motion = pl->GetMotionMaster())
//						{
//								if (pl->IsWithinDistInMap(me, 1.2f, true))
//								{
//									if (!Fetch)
//									{
//										Fetch = true;
//
//										pl->SetSpeed(MOVE_RUN, 4.0f);
//										me->DespawnOrUnsummon(1000);
//										pl->AddAura(37640, pl);
//										pl->AddAura(TEMPEST_SLASH_TRIGGER_VISUAL, pl);
//										motion->MovePoint(1, -2119.329102f, 184.325562f, 422.161896f);
//									}
//								}
//						}
//					}
//				}
//				else if (tempo->GetSummoner()->GetTypeId() != TYPEID_PLAYER)
//				{
//					std::list<Player*> PL_list;
//
//					JadeCore::NearestPlayerInObjectRangeCheck check(me, 1.0f);
//					JadeCore::PlayerListSearcher<JadeCore::NearestPlayerInObjectRangeCheck> searcher(me, PL_list, check);
//					me->VisitNearbyObject(1.0f, searcher);
//
//					for (std::list<Player*>::const_iterator it = PL_list.begin(); it != PL_list.end(); ++it)
//					{
//						if (!(*it))
//							return;
//
//						if (!Fetch)
//						{
//							Fetch = true;
//							if (MotionMaster* motion = (*it)->GetMotionMaster())
//							{
//									(*it)->SetSpeed(MOVE_RUN, 4.0f);
//									me->DespawnOrUnsummon(1000);
//									(*it)->AddAura(37640, (*it));
//									(*it)->AddAura(TEMPEST_SLASH_TRIGGER_VISUAL, (*it));
//									motion->MovePoint(1, -2119.329102f, 184.325562f, 422.161896f);
//							}
//						}
//					}
//				}
//			}
//		}
//	private:
//		EventMap events;
//		std::list<Player*> Player_List;
//	};
//
//	CreatureAI* GetAI(Creature* creature) const
//	{
//		return new npc_tornado_lord_tayakAI(creature);
//	}
//};
//void AddSC_Lord_Tayak()
//{
//	new wind_step_lord_tayak();
//	new boss_lord_tayak();
//	new npc_tornado_lord_tayak();
//
//	// phase 2
//	new npc_tornado_lord_tayak_phase2_Left();
//	new npc_tornado_lord_tayak_phase2_Right();
//	new tempest_pull_all();
//	new deactivate_phase_2_tornado_effect();
//}
