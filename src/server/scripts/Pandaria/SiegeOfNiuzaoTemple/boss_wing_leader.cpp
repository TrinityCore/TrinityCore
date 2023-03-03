///*
//* Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
//* Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
//*
//* This program is free software; you can redistribute it and/or modify it
//* under the terms of the GNU General Public License as published by the
//* Free Software Foundation; either version 2 of the License, or (at your
//* option) any later version.
//*
//* This program is distributed in the hope that it will be useful, but WITHOUT
//* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
//* FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
//* more details.
//* You should have received a copy of the GNU General Public License along
//* with this program. If not, see <http://www.gnu.org/licenses/>.
//*/
//
//#include "ScriptMgr.h"
//#include "ScriptedCreature.h"
//#include "siege_of_the_niuzoa_temple.h"
//
//enum eSpells
//{
//	HURL_BRICK = 121762,
//	CAUSTIC_PITCH = 121443,
//	QUICK_DRY_RESIN = 3242352,
//	GUSTING_WINDS = 121282,
//	GUSTING_WINDS_2 = 121284,
//	TRIGGER_CAUSTIC = 987745,
//};
//enum eEvents
//{
//	EVENT_HURL_BRICK = 200,
//	EVENT_CAUSTIC_PITCH = 201,
//	EVENT_CAUSTIC_PITCH_FLY_BACK = 204,
//	EVENT_CAUSTIC_PITCH_FLY_FORWARD = 205,
//	EVENT_QUICK_DRY_REISIN = 202,
//	EVENT_GUSTING_WIND = 203,
//
//	EVENT_GUSTING_WIND_B = 209,
//};
//enum Pre_Fight_Events
//{
//	EVENT_FLY_SIDE_A = 100,
//	EVENT_FLY_SIDE_A_1 = 101,
//	EVENT_FLY_SIDE_A_2 = 102,
//	EVENT_FLY_SIDE_A_3 = 104,
//	EVENT_FLY_SIDE_A_4 = 105,
//
//	EVENT_FLY_SIDE_B = 110,
//	EVENT_FLY_SIDE_B_1 = 111,
//	EVENT_FLY_SIDE_B_2 = 112,
//	EVENT_FLY_SIDE_B_3 = 113,
//	EVENT_FLY_SIDE_B_4 = 114,
//};
//enum Triggers
//{
//	TRIGGER_GUSTWIND_A = 5436337,
//	TRIGGER_GUSTWIND_B = 5436338,
//};
//
//class boss_neronok : public CreatureScript
//{
//public:
//	boss_neronok() : CreatureScript("boss_neronok") {}
//
//	struct boss_neronokAI : public BossAI
//	{
//		boss_neronokAI(Creature* creature) : BossAI(creature, DATA_NERONOK),
//			instance(creature->GetInstanceScript())// Is this needed here? please test
//		{
//			instance = creature->GetInstanceScript();
//
//			if (IsHeroic())
//			{
//				me->SetHealth(12647760);
//				me->SetMaxHealth(12647760);
//				me->SetLevel(93);
//			}
//			else
//			{
//				me->SetHealth(10188300);
//				me->SetMaxHealth(10188300);
//				me->SetLevel(91);
//			}
//		}
//		bool side_1;
//		bool side_2;
//		bool StartFlyA;
//		bool move;
//		bool StartFlyB;
//		bool IsGustingWind;
//		InstanceScript* instance;
//		std::list<Player*> PL_LIST;
//		bool haswipe;
//		void Reset()
//		{
//			side_1 = true;
//			side_2 = false;
//			IsGustingWind = false;
//			move = true;
//			StartFlyA = false;
//			haswipe = true;
//			StartFlyB = false;
//			events.Reset();
//			_Reset();
//
//			if (!me->FindNearestCreature(95944, 20.0f, true))
//			{
//				me->SummonCreature(95944, 1866.937500f, 5197.359863f, 131.170166f);
//			}
//			if (!me->FindNearestCreature(95945, 60.0f, true))
//			{
//				me->SummonCreature(95945, 1824.406006f, 5235.410645f, 131.170166f);
//			}
//		}
//		void SpellHit(Unit* caster, SpellInfo const* spell)
//		{
//			if (spell->Id == 6552 || spell->Id == 96231 || spell->Id == 57994 || spell->Id == 1766 ||
//				spell->Id == 78675 || spell->Id == 2139 || spell->Id == 47528 || spell->Id == 106839 ||
//				spell->Id == 34490 || spell->Id == 19647 || spell->Id == 102060 || spell->Id == 116705)
//			{
//				if (IsGustingWind)
//				{
//					IsGustingWind = false;
//					events.CancelEvent(EVENT_GUSTING_WIND_B);
//					events.CancelEvent(EVENT_CAUSTIC_PITCH_FLY_FORWARD);
//
//					events.ScheduleEvent(EVENT_QUICK_DRY_REISIN, 13000);
//					events.ScheduleEvent(EVENT_HURL_BRICK, 4000);
//					events.ScheduleEvent(EVENT_CAUSTIC_PITCH, 5000);
//
//					me->SetReactState(REACT_AGGRESSIVE);
//					me->FinishSpell(CURRENT_CHANNELED_SPELL, false);
//					me->SetSpeed(MOVE_FLIGHT, 3.0f, true);
//					me->SetSpeed(MOVE_RUN, 3.0f, true);
//
//					me->ClearUnitState(UNIT_STATE_CANNOT_AUTOATTACK);
//				}
//			}
//		}
//		void EnterCombat(Unit* /*who*/)
//		{
//			haswipe = false;
//			_EnterCombat();
//			events.ScheduleEvent(EVENT_QUICK_DRY_REISIN, 7000);
//			events.ScheduleEvent(EVENT_CAUSTIC_PITCH, 5000);
//			events.ScheduleEvent(EVENT_HURL_BRICK, 4000);
//			DoPlaySoundToSet(me, 30359);
//			me->MonsterYell("You may have comed this far, you may have carved a path through my army.. but I.. I will kill you! And I will build the bridge!", LANG_UNIVERSAL, me->GetGUID()); // Upon Combat 
//		}
//		void JustReachedHome()
//		{
//			instance->SetBossState(DATA_NERONOK, FAIL);
//			summons.DespawnAll();
//		}
//		void DamageTaken(Unit* attacker, uint32& damage)
//		{}
//
//		void JustSummoned(Creature* summoned)
//		{
//			summons.Summon(summoned);
//		}
//		void KilledUnit(Unit* victim)
//		{
//			if (victim->GetTypeId() == TYPEID_PLAYER)
//			{
//				DoPlaySoundToSet(me, 30362);
//				me->MonsterYell("Argh! Out of my way!", LANG_UNIVERSAL, me->GetGUID());
//			}
//		}
//
//		void UpdateAI(const uint32 diff)
//		{
//			events.Update(diff);
//
//			// Different Wiping Mechanism, current one is just weird.
//			if (!haswipe)
//			{
//				Map::PlayerList const& players = me->GetMap()->GetPlayers();
//				if (players.isEmpty())
//				{
//					if (Creature* Boss = me->FindNearestCreature(62205, 400.0f, true))
//					{
//						Boss->DespawnOrUnsummon(50);
//						summons.DespawnAll();
//					}
//					events.Reset();
//				}
//				for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
//				{
//					if (InstanceScript* instance = me->GetInstanceScript())
//					{
//						if (Player* dead_first = players.getFirst()->getSource())
//						{
//							if (Player* dead_last = players.getLast()->getSource())
//							{
//								if (dead_first->isDead() || !dead_first && dead_last->isDead() || !dead_last)
//								{
//									if (Creature* Boss = me->FindNearestCreature(62205, 400.0f, true))
//									{
//										Boss->DespawnOrUnsummon(50);
//										summons.DespawnAll();
//										dead_last->SummonCreature(62205, 1886.143555f, 5180.187500f, 131.169083f, 2.517381f, TEMPSUMMON_CORPSE_DESPAWN, 0);
//									}
//									events.Reset();
//								}
//							}
//						}
//					}
//				}
//			}
//			// flying conditions
//			if (me->GetHealthPct() <= 66 && !StartFlyA)
//			{
//				StartFlyA = true;
//				events.ScheduleEvent(EVENT_FLY_SIDE_A, 1000);
//			}
//			if (me->GetHealthPct() <= 33 && !StartFlyB)
//			{
//				StartFlyB = true;
//				events.ScheduleEvent(EVENT_FLY_SIDE_B, 1000);
//			}
//
//			while (uint32 eventId = events.ExecuteEvent())
//			{
//				switch (eventId)
//				{
//				case EVENT_QUICK_DRY_REISIN:
//					if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
//					{
//						me->CastSpell(target, 121447);
//						events.ScheduleEvent(EVENT_QUICK_DRY_REISIN, 11000);
//					}
//					break;
//				case EVENT_GUSTING_WIND:
//					if (Creature* TargetA = me->FindNearestCreature(95945, 30.f))
//					{
//						me->CastSpell(TargetA, GUSTING_WINDS);
//					}
//					else if (Creature* TargetB = me->FindNearestCreature(95944, 30.f))
//					{
//						me->CastSpell(TargetB, GUSTING_WINDS_2);
//					}
//					events.ScheduleEvent(EVENT_GUSTING_WIND_B, 6500);
//					break;
//				case EVENT_GUSTING_WIND_B:
//					if (Creature* TargetA = me->FindNearestCreature(95945, 30.f))
//					{
//						me->CastSpell(TargetA, GUSTING_WINDS);
//					}
//					else if (Creature* TargetB = me->FindNearestCreature(95944, 30.f))
//					{
//						me->CastSpell(TargetB, GUSTING_WINDS_2);
//					}
//					IsGustingWind = true;
//					events.ScheduleEvent(EVENT_GUSTING_WIND_B, 6500);
//					break;
//				case EVENT_HURL_BRICK:
//					me->CastSpell(me->getVictim(), HURL_BRICK);
//					events.ScheduleEvent(EVENT_HURL_BRICK, 4000);
//					break;
//				case EVENT_CAUSTIC_PITCH_FLY_FORWARD:
//				{
//					// Cancel event to prevent spam
//					events.CancelEvent(EVENT_CAUSTIC_PITCH_FLY_BACK);
//					events.CancelEvent(EVENT_CAUSTIC_PITCH);
//
//					// Spawn Caustics
//					me->SummonCreature(TRIGGER_CAUSTIC, 1860.961548f, 5208.999512f, 131.170151f, 1.573783f, TEMPSUMMON_TIMED_DESPAWN, 30000);
//					me->SummonCreature(TRIGGER_CAUSTIC, 1856.734619f, 5218.906250f, 131.170151f, 3.187776f, TEMPSUMMON_TIMED_DESPAWN, 30000);
//					me->SummonCreature(TRIGGER_CAUSTIC, 1841.378662f, 5220.346191f, 131.170151f, 3.244325f, TEMPSUMMON_TIMED_DESPAWN, 30000);
//					me->SummonCreature(TRIGGER_CAUSTIC, 1832.898682f, 5224.446777f, 131.170151f, 1.576924f, TEMPSUMMON_TIMED_DESPAWN, 30000);
//					me->SummonCreature(TRIGGER_CAUSTIC, 1833.775146f, 5233.766113f, 131.170151f, 2.350542f, TEMPSUMMON_TIMED_DESPAWN, 30000);
//					me->SummonCreature(TRIGGER_CAUSTIC, 1828.995239f, 5237.943848f, 131.170151f, 2.968650f, TEMPSUMMON_TIMED_DESPAWN, 30000);
//					me->SummonCreature(TRIGGER_CAUSTIC, 1818.927856f, 5231.863770f, 131.170166f, 2.059945f, TEMPSUMMON_TIMED_DESPAWN, 30000);
//					events.ScheduleEvent(EVENT_CAUSTIC_PITCH_FLY_FORWARD, 30000);
//				}
//					break;
//				case EVENT_CAUSTIC_PITCH_FLY_BACK:
//				{
//					// Cancel event to prevent spam
//					events.CancelEvent(EVENT_CAUSTIC_PITCH_FLY_FORWARD);
//					events.CancelEvent(EVENT_CAUSTIC_PITCH);
//
//					// Spawn Caustics
//					me->SummonCreature(TRIGGER_CAUSTIC, 1839.698242f, 5218.154297f, 131.170151f, 0.123931f, TEMPSUMMON_TIMED_DESPAWN, 30000);
//					me->SummonCreature(TRIGGER_CAUSTIC, 1848.982788f, 5218.161621f, 131.170151f, 3.187776f, TEMPSUMMON_TIMED_DESPAWN, 30000);
//					me->SummonCreature(TRIGGER_CAUSTIC, 1847.752808f, 5210.481934f, 131.170151f, 3.244325f, TEMPSUMMON_TIMED_DESPAWN, 30000);
//					me->SummonCreature(TRIGGER_CAUSTIC, 1848.748413f, 5203.428223f, 131.170151f, 1.576924f, TEMPSUMMON_TIMED_DESPAWN, 30000);
//					me->SummonCreature(TRIGGER_CAUSTIC, 1833.775146f, 5233.766113f, 131.170151f, 2.350542f, TEMPSUMMON_TIMED_DESPAWN, 30000);
//					me->SummonCreature(TRIGGER_CAUSTIC, 1858.990967f, 5199.759277f, 131.170151f, 2.968650f, TEMPSUMMON_TIMED_DESPAWN, 30000);
//					me->SummonCreature(TRIGGER_CAUSTIC, 1869.899902f, 5189.296387f, 131.170166f, 2.059945f, TEMPSUMMON_TIMED_DESPAWN, 30000);
//					events.ScheduleEvent(EVENT_CAUSTIC_PITCH_FLY_BACK, 30000);
//				}
//					break;
//				case EVENT_CAUSTIC_PITCH:
//				{
//					// Cancel event to prevent spam
//					events.CancelEvent(EVENT_CAUSTIC_PITCH_FLY_BACK);
//					events.CancelEvent(EVENT_CAUSTIC_PITCH_FLY_FORWARD);
//					events.CancelEvent(EVENT_CAUSTIC_PITCH);
//
//					if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
//					{
//						// Spawn Caustics
//						me->SummonCreature(TRIGGER_CAUSTIC, target->GetPositionX() + frand(0.0f, 6.0f), target->GetPositionY() + frand(0.0f, 3.0f), 131.169418f, target->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN, 12000);
//						events.ScheduleEvent(EVENT_CAUSTIC_PITCH, 5000);
//					}
//				}
//					break;
//
//					//////////////////////////////////////////////////////////////////
//					// Flying Events
//				case EVENT_FLY_SIDE_A:
//				{
//					if (MotionMaster* motion = me->GetMotionMaster())
//					{
//						events.CancelEvent(EVENT_HURL_BRICK);
//						events.CancelEvent(EVENT_QUICK_DRY_REISIN);
//						events.CancelEvent(EVENT_CAUSTIC_PITCH);
//
//						me->SetReactState(REACT_PASSIVE);
//						me->InterruptNonMeleeSpells(false);
//						me->FinishSpell(CURRENT_CHANNELED_SPELL, false);
//						me->AttackStop();
//						me->SetSpeed(MOVE_FLIGHT, 3.0f, true);
//						me->SetSpeed(MOVE_RUN, 3.0f, true);
//
//						me->MonsterTextEmote("Wing Leader nero'onok lifts off and flies to the other end of the bridge!", LANG_UNIVERSAL, me->GetGUID());
//
//						//move = true;
//
//						// Remove the ability to attack
//						me->AddUnitState(UNIT_STATE_CANNOT_AUTOATTACK);
//
//
//						// Clear motionmaster
//						motion->Clear(true);
//
//						// Move to side B of the bridge
//						motion->MovePoint(1, 1881.100586f, 5183.056641f, 146.267258f);
//
//						events.ScheduleEvent(EVENT_FLY_SIDE_A_1, 1500);
//						// Schedule Caustic Event
//						events.ScheduleEvent(EVENT_CAUSTIC_PITCH_FLY_FORWARD, 1000);
//					}
//				}
//					break;
//				case EVENT_FLY_SIDE_A_1:
//				{
//					if (MotionMaster* motion = me->GetMotionMaster())
//					{
//						// Z COORDS FOR JUMPING
//						side_1 = false; 
//						side_2 = true;
//						events.ScheduleEvent(EVENT_FLY_SIDE_A_2, 4500);
//						motion->MovePoint(2, 1812.813477f, 5245.202148f, 146.193878f);
//					}
//				}
//					break;
//				case EVENT_FLY_SIDE_A_2:
//				{
//					// Add the ability to attack
//					me->ClearUnitState(UNIT_STATE_CANNOT_AUTOATTACK);
//					me->SetReactState(REACT_AGGRESSIVE);
//
//					if (MotionMaster* motion = me->GetMotionMaster())
//					{
//						move = true;
//
//						// Clear motionmaster
//						//motion->Clear(true);
//						me->SetSpeed(MOVE_FLIGHT, 2.0f, true);
//						me->SetSpeed(MOVE_RUN, 1.6f, true);
//						motion->MovePoint(3, 1815.002930f, 5244.597656f, 131.170441f);
//					}
//					events.ScheduleEvent(EVENT_GUSTING_WIND, 3000);
//				}
//					break;
//				case EVENT_FLY_SIDE_B:
//				{
//					me->MonsterTextEmote("Wing Leader nero'onok lifts off and flies to the other end of the bridge!", LANG_UNIVERSAL, me->GetGUID());
//
//					// Schedule Caustic Event
//					events.ScheduleEvent(EVENT_CAUSTIC_PITCH_FLY_BACK, 1000);
//					events.CancelEvent(EVENT_CAUSTIC_PITCH);
//					events.CancelEvent(EVENT_QUICK_DRY_REISIN);
//					events.CancelEvent(EVENT_HURL_BRICK);
//
//					// Remove the ability to attack
//					me->AddUnitState(UNIT_STATE_CANNOT_AUTOATTACK);
//					me->SetReactState(REACT_PASSIVE);
//
//					me->InterruptNonMeleeSpells(false);
//					me->FinishSpell(CURRENT_CHANNELED_SPELL, false);
//					me->AttackStop();
//
//					if (MotionMaster* motion = me->GetMotionMaster())
//					{
//						move = true;
//
//						events.ScheduleEvent(EVENT_FLY_SIDE_B_1, 1500);
//						// Schedule Caustic Event
//						events.ScheduleEvent(EVENT_CAUSTIC_PITCH_FLY_BACK, 1000);
//
//						// Clear motionmaster
//						motion->Clear(true);
//
//						motion->MovePoint(4, 1813.656738f, 5245.903809f, 147.996879f);
//					}
//					break;
//				}
//				case EVENT_FLY_SIDE_B_1:
//				{
//					if (MotionMaster* motion = me->GetMotionMaster())
//					{
//						move = true;
//
//						side_1 = true;
//						side_2 = false;
//						events.ScheduleEvent(EVENT_FLY_SIDE_B_2, 4500);
//						motion->MovePoint(5, 1885.431641f, 5179.691406f, 149.663666f);
//					}
//					break;
//				}
//				case EVENT_FLY_SIDE_B_2:
//				{
//					// Add the ability to attack
//					me->ClearUnitState(UNIT_STATE_CANNOT_AUTOATTACK);
//					me->SetReactState(REACT_AGGRESSIVE);
//
//					if (MotionMaster* motion = me->GetMotionMaster())
//					{
//						move = true;
//
//						// Clear motionmaster
//						motion->Clear(true);
//
//						motion->MovePoint(6, 1884.880005f, 5180.540039f, 131.169006f);
//						events.ScheduleEvent(EVENT_GUSTING_WIND, 6000);
//					}
//					break;
//				}
//			}
//		}
//	}
//		void JustDied(Unit* /*killer*/)
//		{
//			_JustDied();
//
//			instance->SetBossState(DATA_NERONOK, DONE);
//			summons.DespawnAll();
//
//            Map::PlayerList const &PlList = me->GetMap()->GetPlayers();
//            if (PlList.isEmpty())
//                return;
//            AchievementEntry const* achievementEntry = sAchievementMgr->GetAchievement(6214);
//            for (Map::PlayerList::const_iterator i = PlList.begin(); i != PlList.end(); ++i)
//                if (Player* player = i->getSource())
//                        player->CompletedAchievement(achievementEntry);
//
//			DoPlaySoundToSet(me, 30361);
//			me->MonsterYell("Kah.... The.. Bridge!", LANG_UNIVERSAL, me->GetGUID());
//		}
//	private:
//		EventMap events;
//	};
//
//	CreatureAI* GetAI(Creature* creature) const
//	{
//		return new boss_neronokAI(creature);
//	}
//};
//class Reisin_Boss_Traps : public CreatureScript
//{
//public:
//	Reisin_Boss_Traps() : CreatureScript("Reisin_Boss_Traps") { }
//
//	struct Resin_Trigger_AI : public CreatureAI
//	{
//		Resin_Trigger_AI(Creature* creature) : CreatureAI(creature)
//		{
//			me->AddExtraUnitMovementFlag(MOVEMENTFLAG_ROOT);
//			me->SetObjectScale(1.0);
//		}
//		bool Used;
//
//		void Reset()
//		{
//			Used = false;
//			events.Reset();
//			if (TempSummon* temp = me->ToTempSummon())
//				if (Creature* Summoner = temp->GetSummoner()->ToCreature())
//				{
//				me->setFaction(Summoner->getFaction());
//				me->CastSpell(me, CAUSTIC_PITCH);
//				}
//		}
//		void UpdateAI(uint32 const diff)
//		{
//			events.Update(diff);
//
//			if (Player* pl = me->SelectNearestPlayer(1.0))
//			{
//				if (pl->IsWithinDistInMap(me, 1.0f, true) && !Used)
//				{
//					if (MotionMaster* motion = pl->GetMotionMaster())
//					{
//						//motion->Clear(true);
//					}
//				}
//			}
//		}
//	private:
//		EventMap events;
//	};
//	CreatureAI* GetAI(Creature* creature) const
//	{
//		return new Resin_Trigger_AI(creature);
//	}
//};
//class quick_dry_resin_after_effect : public SpellScriptLoader
//{
//public:
//	quick_dry_resin_after_effect() : SpellScriptLoader("quick_dry_resin_after_effect") { }
//
//	class spell_carrying_caustic_tar_AuraScript : public AuraScript
//	{
//		PrepareAuraScript(spell_carrying_caustic_tar_AuraScript);
//
//		void OnRemove(constAuraEffectPtr /*aurEff*/, AuraEffectHandleModes /*mode*/)
//		{
//			if (!GetTarget())
//				return;
//
//			if (!GetTarget()->HasAura(122063))
//			{
//				GetTarget()->AddAura(121116, GetTarget());
//			}
//		
//		}
//		void Register()
//		{
//			AfterEffectRemove += AuraEffectRemoveFn(spell_carrying_caustic_tar_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
//		}
//	};
//
//	AuraScript* GetAuraScript() const
//	{
//		return new spell_carrying_caustic_tar_AuraScript();
//	}
//};
//class spell_gusting_wind_left : public SpellScriptLoader
//{
//public:
//	spell_gusting_wind_left() : SpellScriptLoader("spell_gusting_wind_left") { }
//
//	class spell_gusting_wind_spell_script : public SpellScript
//	{
//		PrepareSpellScript(spell_gusting_wind_spell_script);
//
//		std::list<Player*> PL_LIST;
//
//		void HandleOnCast()
//		{
//			if (!GetCaster())
//				return;
//			Creature* boss = GetCaster()->ToCreature();
//
//			if (!boss)
//				return;
//
//
//			JadeCore::AnyPlayerInObjectRangeCheck check(boss, 14.0f);
//			JadeCore::PlayerListSearcher<JadeCore::AnyPlayerInObjectRangeCheck> searcher(boss, PL_LIST, check);
//			boss->VisitNearbyObject(14.0f, searcher);
//
//			for (std::list<Player*>::const_iterator itr = PL_LIST.begin(); itr != PL_LIST.end(); itr++)
//			{
//				if (!(*itr))
//					return;
//
//				(*itr)->GetMotionMaster()->MoveBackward(1, 1834.417725f, 5232.359375f, 131.169464f);
//			}
//		}
//		void Unload() override
//		{
//			for (std::list<Player*>::const_iterator itr = PL_LIST.begin(); itr != PL_LIST.end(); itr++)
//			{
//				if (!(*itr))
//					return;
//
//				if (MotionMaster* motion = (*itr)->GetMotionMaster())
//					motion->Clear(true);
//			}
//		}
//
//		void Register()
//		{
//			OnCast += SpellCastFn(spell_gusting_wind_spell_script::HandleOnCast);
//		}
//	};
//
//	SpellScript* GetSpellScript() const
//	{
//		return new spell_gusting_wind_spell_script;
//	}
//};
//class spell_gusting_wind_right : public SpellScriptLoader
//{
//public:
//	spell_gusting_wind_right() : SpellScriptLoader("spell_gusting_wind_right") { }
//
//	class spell_gusting_wind_spell_script : public SpellScript
//	{
//		PrepareSpellScript(spell_gusting_wind_spell_script);
//
//		std::list<Player*> PL_LIST;
//
//		void HandleOnCast()
//		{
//			if (!GetCaster())
//				return;
//			Creature* boss = GetCaster()->ToCreature();
//
//			if (!boss)
//				return;
//
//			JadeCore::AnyPlayerInObjectRangeCheck check(boss, 22.0f);
//			JadeCore::PlayerListSearcher<JadeCore::AnyPlayerInObjectRangeCheck> searcher(boss, PL_LIST, check);
//			boss->VisitNearbyObject(22.0f, searcher);
//
//			for (std::list<Player*>::const_iterator itr = PL_LIST.begin(); itr != PL_LIST.end(); itr++)
//			{
//				if (!(*itr))
//					return;
//
//				int32 rand = urand(1, 2);
//				if (rand == 1)
//					(*itr)->GetMotionMaster()->MoveBackward(2, 1857.359131f, 5206.055664f, 131.169647f);
//				if (rand == 2)
//					(*itr)->GetMotionMaster()->MoveBackward(2, 1867.288940f, 5203.192871f, 131.169434f);
//			}
//		}
//		void Unload() override
//		{
//			for (std::list<Player*>::const_iterator itr = PL_LIST.begin(); itr != PL_LIST.end(); itr++)
//			{
//				if (!(*itr))
//					return;
//
//				if (MotionMaster* motion = (*itr)->GetMotionMaster())
//					motion->Clear(true);
//			}
//		}
//
//
//		void Register()
//		{
//			OnCast += SpellCastFn(spell_gusting_wind_spell_script::HandleOnCast);
//		}
//	};
//
//	SpellScript* GetSpellScript() const
//	{
//		return new spell_gusting_wind_spell_script;
//	}
//};
//class quick_dry_reisin_dummy : public SpellScriptLoader
//{
//public:
//	quick_dry_reisin_dummy() : SpellScriptLoader("quick_dry_reisin_dummy") { }
//
//	class quick_dry_reisin_dummy_spell_Script : public SpellScript
//	{
//		PrepareSpellScript(quick_dry_reisin_dummy_spell_Script);
//
//		std::list<Player*> PL_LIST;
//
//		void HandleAfterCast()
//		{
//			if (!GetCaster())
//				return;
//			Creature* boss = GetCaster()->ToCreature();
//
//			if (!boss)
//				return;
//
//			Unit* target = GetExplTargetUnit();
//
//			if (!target)
//				return;
//
//			boss->AddAura(121447, target);
//		}
//
//		void Register()
//		{
//			AfterCast += SpellCastFn(quick_dry_reisin_dummy_spell_Script::HandleAfterCast);
//		}
//	};
//
//	SpellScript* GetSpellScript() const
//	{
//		return new quick_dry_reisin_dummy_spell_Script;
//	}
//};
//
//void AddSC_WING_LEADER()
//{
//	// boss
//	new boss_neronok();
//	// npcs
//	new Reisin_Boss_Traps();
//	// spells
//	new quick_dry_reisin_dummy();
//	new quick_dry_resin_after_effect();
//	// gusting wind
//	// right
//	new spell_gusting_wind_right();
//	//left
//	new spell_gusting_wind_left();
//}
//
//
//
