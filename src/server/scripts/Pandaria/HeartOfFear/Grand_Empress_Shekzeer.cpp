//
//#include "ObjectMgr.h"
//#include "Player.h"
//#include "ScriptMgr.h"
//#include "ScriptedCreature.h"
//#include "AchievementMgr.h"
//
//// THIS NO HEROIC
//
//enum Achievements
//{
//
//};
//enum Spells
//{
//	CRY_OF_TERROR = 123788,
//	CRY_OF_TERROR_TICK = 123788,
//
//	DEAD_SCREECH = 123735,
//	DEAD_SCREECH_DMG = 123743,
//
//	EYE_OF_THE_EMPRESS = 123707,
//	SERVANT_OF_THE_EMPRESS = 123713,
//
//	DISSONACE_TRIGGER_VISUAL = 123255,
//	DISSONANCE_DAMAGE = 123504,
//
//	TRANSFORM_AURA = 123713,
//
//	ADVANCE = 125304,
//
//	BAND_OF_VALOR = 125422,
//
//	/* Set'thik Windblade */
//	SONIC_BOMB = 125886,
//	FIXATE = 129149,
//	FIXATE_AURA = 125390,
//	DISPATCH = 129154,
//
//	STICKY_RESIN_DOT = 124097,
//	STICKY_RESIN_AURA = 124310,
//
//	AMBER_FROZEN_VISUAL = 125803,
//	AMBER_FROZEN_DOT_STUN = 125823,
//	AMBER_TRAP_STACKS_PRE_FROZEN = 124748,
//
//	AMBER_TRAP = 125826,
//
//	/* Kor'thik Reaver */
//	POISON_BOMB = 124777,
//	POISON_DRENCHED_ARMOR = 124821,
//	TOXIC_SLIME = 124807,
//
//	// PHASE 3
//	SHA_ENERGY = 125464,
//	AMASSING_DARKNESS = 124844,
//	AMASSING_DARKNESS_AURA = 124842,
//	CONSUMING_TERROR = 124849,
//	CALAMITY = 124845,
//};
//enum Mobs
//{
//	DISSONANCE_SHIELD_TRIGGER = 2317845,
//	STICKY_RESIN_TRIGGER = 3214431,
//	AMBER_TRAP_TRIGGER = 2534637,
//    DISSONANCE_TRIGGER_EXPLOSION = 423965,
//
//	MOB_REAVER = 63591,
//	MOB_WIND = 64453,
//};
//enum Events
//{
//	/* BOSS */
//	EVENT_ADVANCE = 20,
//	EVENT_DEADVANCE = 21,
//	EVENT_SUMMON_MOBS = 22,
//	// PHASE 1
//	EVENT_CRY_TERROR = 1, // RANDOM AOE ON THE RAID DMG
//	EVENT_EYE_OF_THE_EMPRESS = 2, // TANK STACK X5 MINDCONTROL
//	EVENT_DEAD_SCREECH = 3, // 80 K DMG TO 2 RANDOM PLAYERS AND DMG IN 4 YARDS
//	EVENT_DISSONANCE_SHIELD = 4,// HP GOES DOWN EACH SEC, 2 LIGHT SHIELD SPAWN ON THE GROUND IF YOU'RE INSIDE THEM THEY ABSORD ALL DMG AND CAST AND START TICKING DOWN EACH CAST THEY DETONATE IF THEY REECH 0 HP. DETONATNE DMG.s
//
//	// PHASE 2 
//	// starts after 150 seconds once energy goes 0
//	/* Set'thik Windblade */
//	EVENT_FIXATE = 10,
//	EVENT_DISPATCH = 11,
//	EVENT_SONIC_BLADE = 12,
//	EVENT_STICKY_RESIN = 13,
//
//	/* Kor'thik Reaver */
//	EVENT_POISON_BOMB = 14,
//	EVENT_TOXIC_SLIME = 15,
//	EVENT_POISON_DRENCHED_ARMOR = 16,
//
//	// PHASE 3
//	EVENT_SHA_ENERGY  = 17,
//	EVENT_CALAMITY = 18,
//	EVENT_CONSUMING_TERROR = 19,
//	EVENT_AMASSING_DARKNESS = 30,
//	EVENT_VISIONS_OF_DEMISE = 31,
//
//
//	// move fix
//	EVENT_MOVE_FIX = 32,
//};
//
//Position const dis_1 = { -2487.20f, 991.38f, 569.629f, 1.048513f };
//Position const dis_2 = { -2466.14f, 990.30f, 569.629f, 2.113513f };
//
//class boss_empress_shekzeer : public CreatureScript
//{
//public:
//	boss_empress_shekzeer() : CreatureScript("boss_empress_shekzeer") { }
//
//	struct boss_empress_shekzeerAI : public BossAI
//	{
//		boss_empress_shekzeerAI(Creature* creature) : BossAI(creature, 0)
//		{
//			me->SetLevel(94);
//			me->setFaction(16);
//		}
//		InstanceScript* instance;
//		uint32 phase1;
//		uint32 phase2;
//
//		bool phase1_timer;
//		bool phase2_timer;
//
//		bool deadvanced;
//
//		bool thirdphase;
//
//		bool SayCharmed;
//
//		void Reset()
//		{
//			_Reset();
//            events.Reset();
//
//            me->GetMotionMaster()->MovePoint(1, me->GetHomePosition());
//            me->setFaction(16);
//            me->SetReactState(REACT_AGGRESSIVE);
//            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NOT_ATTACKABLE_1);
//
//            me->SetDisplayId(42730); // revert to original display
//
//			// deadvancing when reseting 
//			events.ScheduleEvent(EVENT_DEADVANCE, 500);
//
//			phase1 = 120 * IN_MILLISECONDS;
//			phase2 = 130 * IN_MILLISECONDS;
//
//			deadvanced = false;
//
//			phase1_timer = true;
//			phase2_timer = false;
//
//			thirdphase = true;
//			SayCharmed = false;
//		}
//		void EnterCombat(Unit* who)
//		{
//			_EnterCombat();
//
//			me->MonsterYell("Death to all who dare challenge my empire!", LANG_UNIVERSAL, me->GetGUID());
//			DoPlaySoundToSet(me, 29283);
//
//			events.ScheduleEvent(EVENT_CRY_TERROR, 7500);
//			events.ScheduleEvent(EVENT_DEAD_SCREECH, 10000);
//			events.ScheduleEvent(EVENT_EYE_OF_THE_EMPRESS, 6000);
//			events.ScheduleEvent(EVENT_DISSONANCE_SHIELD, 30000);
//		}
//        void EnterEvadeMode()
//        {         
//            Reset();
//            me->DeleteThreatList();
//            me->CombatStop(false);
//            me->GetMotionMaster()->MoveTargetedHome();
//        }
//		void JustReachedHome()
//		{
//			//instance->SetBossState(DATA_PAVALAK, FAIL);
//			summons.DespawnAll();
//			me->DespawnCreaturesInArea(STICKY_RESIN_TRIGGER);
//            me->DespawnCreaturesInArea(DISSONANCE_SHIELD_TRIGGER);
//            me->DespawnCreaturesInArea(AMBER_TRAP_TRIGGER);
//		}
//		void DamageTaken(Unit* attacker, uint32& damage)
//		{
//			if (!HealthAbovePct(31) && thirdphase)
//			{
//				thirdphase = false;
//
//				// cancel first phase abilities
//				events.CancelEvent(EVENT_CRY_TERROR);
//				events.CancelEvent(EVENT_DEAD_SCREECH);
//				events.CancelEvent(EVENT_DISSONANCE_SHIELD);
//				events.CancelEvent(EVENT_EYE_OF_THE_EMPRESS);
//	
//				// scehdule new abilities third phase
//				events.ScheduleEvent(EVENT_SHA_ENERGY, 10000);
//				events.ScheduleEvent(EVENT_AMASSING_DARKNESS, 8000);
//				events.ScheduleEvent(EVENT_CONSUMING_TERROR, 40000);
//				events.ScheduleEvent(EVENT_VISIONS_OF_DEMISE, urand(29000, 35000));
//				events.ScheduleEvent(EVENT_CALAMITY, urand(15000, 20000));
//
//				me->MonsterSay("More! More! I must have more!", LANG_UNIVERSAL, me->GetGUID());
//				DoPlaySoundToSet(me, 29272);
//			}
//		}
//		void UpdateAI(uint32 const diff)
//		{
//			events.Update(diff);
//
//			if (!UpdateVictim())
//				return;
//
//			if (phase1_timer)
//			{
//				if (phase1 <= diff)
//				{
//					phase1_timer = false;
//					phase2_timer = true;
//					deadvanced = true;
//
//					me->CastSpell(me, ADVANCE);
//
//					if (me->HasAura(ADVANCE))
//					{
//						AuraPtr Advance = me->GetAura(ADVANCE);
//
//						if (Advance)
//						{
//							Advance->SetDuration(10000000);
//						}
//					}
//
//					me->MonsterSay("Power.. I must have more power.. Guards, Protect your empress!", LANG_UNIVERSAL, me->GetGUID());
//					DoPlaySoundToSet(me, 29270);
//
//					events.ScheduleEvent(EVENT_SUMMON_MOBS, 500);
//					events.ScheduleEvent(EVENT_ADVANCE, 500);
//				}
//				else
//					phase1 -= diff;
//			}
//			if (phase2_timer)
//			{
//				if (phase2 <= diff)
//				{
//					phase2_timer = false;
//
//					if (deadvanced)
//					{
//						deadvanced = false;
//
//						me->RemoveAura(ADVANCE);
//						events.ScheduleEvent(EVENT_DEADVANCE, 500);
//					}
//				}
//				else
//					phase2 -= diff;
//			}
//
//			if (thirdphase)
//			{
//				if (Unit* victim = me->getVictim())
//				{
//					if (!me->IsWithinDistInMap(victim, 2.0f))
//					{
//						events.ScheduleEvent(EVENT_MOVE_FIX, 1000);
//					}
//				}
//			}
//
//			if (SayCharmed)
//			{
//				SayCharmed = false;
//
//				me->MonsterYell("You are mine now!", LANG_UNIVERSAL, me->GetGUID());
//				DoPlaySoundToSet(me, 29282);
//			}
//			// Introduction RP	
//
//			while (uint32 eventId = events.ExecuteEvent())
//			{
//				switch (eventId)
//				{
//				case EVENT_SUMMON_MOBS:
//					// side a
//					me->SummonCreature(MOB_REAVER, -2453.20f, 989.60f, 569.630f, 3.498173f, TEMPSUMMON_MANUAL_DESPAWN);
//					me->SummonCreature(MOB_WIND, -2448.70f, 992.45f, 569.630f, 3.407852f, TEMPSUMMON_MANUAL_DESPAWN);
//					me->SummonCreature(MOB_WIND, -2445.68f, 989.26f, 569.630f, 3.407852f, TEMPSUMMON_MANUAL_DESPAWN);
//					// side b
//					me->SummonCreature(MOB_REAVER, -2504.68f, 987.24f, 569.630f, 0.295318f, TEMPSUMMON_MANUAL_DESPAWN);
//					me->SummonCreature(MOB_WIND, -2508.52f, 981.49f, 569.630f, 0.295318f, TEMPSUMMON_MANUAL_DESPAWN);
//					me->SummonCreature(MOB_WIND, -2510.62f, 992.30f, 569.630f, 0.295318f, TEMPSUMMON_MANUAL_DESPAWN);
//					break;
//				case EVENT_ADVANCE:
//					me->SetDisplayId(11686); // invis
//
//					if (MotionMaster* motion = me->GetMotionMaster())
//						motion->MovePoint(1, -2476.62f, 1035.45f, 572.818f);
//
//					me->SetReactState(REACT_PASSIVE);
//					me->AddUnitState(UNIT_STATE_CANNOT_AUTOATTACK);
//
//					me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
//					me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);
//
//					events.CancelEvent(EVENT_DEAD_SCREECH);
//					events.CancelEvent(EVENT_CRY_TERROR);
//					events.CancelEvent(EVENT_EYE_OF_THE_EMPRESS);
//					events.CancelEvent(EVENT_DISSONANCE_SHIELD);
//
//					me->DespawnCreaturesInArea(DISSONANCE_SHIELD_TRIGGER);
//					me->SetSpeed(MOVE_RUN, 0.0f);
//					break;
//				case EVENT_DEADVANCE:
//					me->SetDisplayId(42730); // originial dis
//
//                    events.ScheduleEvent(EVENT_CRY_TERROR, 7500);
//                    events.ScheduleEvent(EVENT_DEAD_SCREECH, 10000);
//                    events.ScheduleEvent(EVENT_EYE_OF_THE_EMPRESS, 8000);
//                    events.ScheduleEvent(EVENT_DISSONANCE_SHIELD, 30000);
//
//					me->Attack(me->getVictim(), true);
//
//					me->SetReactState(REACT_AGGRESSIVE);
//					me->ClearUnitState(UNIT_STATE_CANNOT_AUTOATTACK);
//					me->SetSpeed(MOVE_RUN, 1.13f);
//					me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
//					me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);
//					break;
//				case EVENT_CRY_TERROR:
//					if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 50, true))
//					{
//						me->AddAura(123788, target);
//					}
//					events.ScheduleEvent(EVENT_CRY_TERROR, 7500);
//					break;
//				case EVENT_DEAD_SCREECH:
//					for (int i = 0; i <= 1; i++)
//					{
//						if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 50, true))
//						{
//							me->CastSpell(target, DEAD_SCREECH_DMG);
//						}
//					}
//					events.ScheduleEvent(EVENT_DEAD_SCREECH, 10000);
//					break;
//				case EVENT_EYE_OF_THE_EMPRESS:
//					if (!me->getVictim()->HasAura(EYE_OF_THE_EMPRESS))
//					{
//						me->getVictim()->CastSpell(me->getVictim(), EYE_OF_THE_EMPRESS);
//					}
//					else
//					{
//						AuraPtr aura_B = me->getVictim()->GetAura(EYE_OF_THE_EMPRESS);
//
//						if (aura_B && aura_B->GetStackAmount() <= 5)
//						{
//							aura_B->SetStackAmount(aura_B->GetStackAmount() + 1);
//						}
//					}
//					events.ScheduleEvent(EVENT_EYE_OF_THE_EMPRESS, 6000);
//					break;
//				case EVENT_DISSONANCE_SHIELD:
//
//					if (!me->FindNearestCreature(DISSONANCE_SHIELD_TRIGGER, 100.0f, true))
//					{
//						me->SummonCreature(DISSONANCE_SHIELD_TRIGGER, dis_1, TEMPSUMMON_MANUAL_DESPAWN, 0);
//						me->SummonCreature(DISSONANCE_SHIELD_TRIGGER, dis_2, TEMPSUMMON_MANUAL_DESPAWN, 0);
//					}
//
//					events.ScheduleEvent(EVENT_DISSONANCE_SHIELD, 65000);
//					break;
//					// phase 3
//				case EVENT_SHA_ENERGY:
//
//					int count;
//
//					if (Is25ManRaid())
//						count = 4;
//					else
//						count = 1;
//
//					for (int i = 0; i <= count; i++)
//					{
//						if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 50, true))
//						{
//							me->CastSpell(target, SHA_ENERGY);
//						}
//					}
//					events.ScheduleEvent(EVENT_SHA_ENERGY, 10000);
//					break;
//				case EVENT_AMASSING_DARKNESS:
//					if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 50, true))
//					{
//						if (!target->HasAura(AMASSING_DARKNESS_AURA))
//						{
//							me->CastSpell(target, AMASSING_DARKNESS);
//							me->AddAura(AMASSING_DARKNESS_AURA, target);
//						}
//
//						UnitList targets;
//						JadeCore::AnyUnitHavingBuffInObjectRangeCheck u_check(target, target, 100, AMASSING_DARKNESS_AURA, true);
//						JadeCore::UnitListSearcher<JadeCore::AnyUnitHavingBuffInObjectRangeCheck> searcher(target, targets, u_check);
//						target->VisitNearbyObject(100, searcher);
//
//						for (UnitList::const_iterator it = targets.begin(); it != targets.end(); ++it)
//						{
//							if (!(*it))
//								return;
//
//							if ((*it)->GetGUID() != target->GetGUID())
//							me->CastSpell((*it), AMASSING_DARKNESS);
//						}
//
//						if (Is25ManRaid())
//							events.ScheduleEvent(EVENT_AMASSING_DARKNESS, 2500);
//						else
//							events.ScheduleEvent(EVENT_AMASSING_DARKNESS, 6500);
//					}
//					break;
//				case EVENT_CONSUMING_TERROR:
//					if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 50, true))
//					{
//						// cancel first phase abilities
//						events.CancelEvent(EVENT_SHA_ENERGY);
//						events.CancelEvent(EVENT_AMASSING_DARKNESS);;
//						events.CancelEvent(EVENT_VISIONS_OF_DEMISE);
//						events.CancelEvent(EVENT_CALAMITY);
//
//						// scehdule new abilities third phase
//						events.ScheduleEvent(EVENT_SHA_ENERGY, 10000);
//						events.ScheduleEvent(EVENT_AMASSING_DARKNESS, 10000);
//						events.ScheduleEvent(EVENT_CONSUMING_TERROR, 40000);
//						events.ScheduleEvent(EVENT_VISIONS_OF_DEMISE, urand(29000, 35000));
//						events.ScheduleEvent(EVENT_CALAMITY, urand(15000, 20000));
//
//						me->CastSpell(target, CONSUMING_TERROR);
//						events.ScheduleEvent(EVENT_CONSUMING_TERROR, 40000);
//					}
//					break;
//				case EVENT_CALAMITY:
//					DoCastAOE(CALAMITY);
//					events.ScheduleEvent(EVENT_CALAMITY, 20000);
//					break;
//				case EVENT_VISIONS_OF_DEMISE:
//					for (int i = 0; i <= 1; i++)
//					{
//						if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 50, true))
//						{
//							me->AddAura(124862, target);
//						}
//					}
//					events.ScheduleEvent(EVENT_VISIONS_OF_DEMISE, urand(29000, 35000));
//					break;
//				case EVENT_MOVE_FIX:
//					if (Unit* victim = me->getVictim())
//					{
//						if (!me->IsWithinDistInMap(victim, 2.0f))
//						{
//							if (MotionMaster* motion = me->GetMotionMaster())
//							{
//								motion->MovePoint(1, victim->GetPositionX(), victim->GetPositionY(), victim->GetPositionZ());
//							}
//							events.ScheduleEvent(EVENT_MOVE_FIX, 2000);
//						}
//					}
//					break;
//				}
//			}
//			DoMeleeAttackIfReady();
//		}
//		void JustDied(Unit* killer)
//		{
//			_JustDied();
//
//			me->DespawnCreaturesInArea(STICKY_RESIN_TRIGGER);
//
//			me->MonsterYell("I have... Failed", LANG_UNIVERSAL, me->GetGUID());
//			DoPlaySoundToSet(me, 29268);
//
//
//            Map::PlayerList const &PlList = me->GetMap()->GetPlayers();
//            if (PlList.isEmpty())
//                return;
//            AchievementEntry const* achievementEntry = sAchievementMgr->GetAchievement(6845);
//            for (Map::PlayerList::const_iterator i = PlList.begin(); i != PlList.end(); ++i)
//                if (Player* player = i->getSource())
//                    player->CompletedAchievement(achievementEntry);
//		}
//		void KilledUnit(Unit* victim)
//		{
//			if (victim->GetTypeId() == TYPEID_PLAYER)
//			{
//				switch (urand(0, 1))
//				{
//				case 0:
//					me->MonsterYell("Taste the feets.. Stranger!", LANG_UNIVERSAL, me->GetGUID());
//					DoPlaySoundToSet(me, 29279);
//					break;
//				case 1:
//					me->MonsterYell("Breath no longer!", LANG_UNIVERSAL, me->GetGUID());
//					DoPlaySoundToSet(me, 29280);
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
//		return new boss_empress_shekzeerAI(creature);
//	}
//};
//class eye_of_the_empress : public SpellScriptLoader {
//public:
//	eye_of_the_empress() : SpellScriptLoader("eye_of_the_empress") { }
//
//	class eye_of_the_empressaurascript : public AuraScript {
//		PrepareAuraScript(eye_of_the_empressaurascript);
//
//		void OnUpdate(uint32 diff, AuraEffectPtr aurEff)
//		{
//			if (GetCaster())
//			{
//				if (GetCaster()->HasAura(EYE_OF_THE_EMPRESS))
//				{
//					if (GetStackAmount() >= 5)
//					{
//						GetCaster()->RemoveAura(EYE_OF_THE_EMPRESS);
//						// transform
//						GetCaster()->AddAura(TRANSFORM_AURA, GetCaster());
//
//						if (Creature* boss = GetCaster()->FindNearestCreature(62837, 100.0f, true))
//						{
//							if (boss_empress_shekzeer::boss_empress_shekzeerAI* linkAI = CAST_AI(boss_empress_shekzeer::boss_empress_shekzeerAI, boss->GetAI()))
//							{
//								if (!linkAI->SayCharmed)
//								{
//									linkAI->SayCharmed = true;
//								}
//							}
//						}
//					}
//				}
//			}
//		}
//		void Register()
//		{
//			OnEffectUpdate += AuraEffectUpdateFn(eye_of_the_empressaurascript::OnUpdate, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
//		}
//	};
//
//	AuraScript* GetAuraScript() const
//	{
//		return new eye_of_the_empressaurascript();
//	}
//};
//class npc_dissonance_field : public CreatureScript
//{
//public:
//	npc_dissonance_field() : CreatureScript("npc_dissonance_field") { }
//
//	struct npc_dissonance_fieldAI : public Scripted_NoMovementAI
//	{
//		npc_dissonance_fieldAI(Creature* creature) : Scripted_NoMovementAI(creature)
//		{
//			me->SetDisplayId(43158);
//			me->SetObjectScale(1.0f);
//			me->SetMaxHealth(200000);
//			me->SetHealth(200000);
//			me->setFaction(16);
//			me->SetReactState(REACT_AGGRESSIVE);
//			me->AddUnitState(UNIT_STATE_CANNOT_AUTOATTACK);
//		}
//		uint32 ticking;
//		bool canexploade;
//		void Reset()
//		{
//			ticking = 2000;
//
//			me->CastSpell(me, DISSONACE_TRIGGER_VISUAL);
//			me->RemoveAura(123184);
//
//			canexploade = true;
//		}
//        void JustDied(Unit* killer)
//		{
//			if (canexploade)
//			{
//				canexploade = false;
//                me->SummonCreature(DISSONANCE_TRIGGER_EXPLOSION, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN);
//				me->DespawnOrUnsummon(500);
//			}
//		}
//		void UpdateAI(uint32 const diff)
//		{
//			events.Update(diff);
//
//			if (Creature* Boss = me->FindNearestCreature(62837, 100.0f, true))
//			{
//				if (ticking <= diff)
//				{
//					Boss->DealDamage(me, me->GetMaxHealth() * 0.04, NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
//					ticking = 2000;
//				}
//				else
//					ticking -= diff;
//
//				std::list<Player*> PL_list;
//
//				JadeCore::AnyPlayerInObjectRangeCheck check(me, 7.0f);
//				JadeCore::PlayerListSearcher<JadeCore::AnyPlayerInObjectRangeCheck> searcher(me, PL_list, check);
//				me->VisitNearbyObject(7.0f, searcher);
//
//				for (std::list<Player*>::const_iterator it = PL_list.begin(); it != PL_list.end(); ++it)
//				{
//					if (!(*it))
//						return;
//
//					if ((*it)->GetCurrentSpell(CURRENT_CHANNELED_SPELL))
//					{
//						Boss->DealDamage(me, me->GetMaxHealth() * 0.0003, NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
//					}
//					if ((*it)->HasAura(CRY_OF_TERROR))
//					{
//						Boss->DealDamage(me, me->GetMaxHealth() * 0.0003, NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
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
//		return new npc_dissonance_fieldAI(creature);
//	}
//};
//class npc_dissonance_trigger_explosion : public CreatureScript
//{
//public:
//    npc_dissonance_trigger_explosion() : CreatureScript("npc_dissonance_trigger_explosion") { }
//
//    struct npc_dissonance_trigger_explosionAI : public Scripted_NoMovementAI
//    {
//        npc_dissonance_trigger_explosionAI(Creature* creature) : Scripted_NoMovementAI(creature)
//        {
//            me->CastSpell(me, DISSONANCE_DAMAGE);
//        }
//
//    private:
//    };
//
//    CreatureAI* GetAI(Creature* creature) const
//    {
//        return new npc_dissonance_trigger_explosionAI(creature);
//    }
//};
//// phase 2
//class windblade : public CreatureScript
//{
//public:
//	windblade() : CreatureScript("windblade") {}
//
//	struct windblade_AI : public ScriptedAI
//	{
//		windblade_AI(Creature* creature) : ScriptedAI(creature)
//		{
//			me->SetLevel(93);
//			me->setFaction(16);
//		}
//		bool fixated;
//		Player* target_after = NULL;
//		std::list<Creature*> cr_list;
//
//		void EnterCombat(Unit* who)
//		{
//			events.ScheduleEvent(EVENT_FIXATE, 30000);
//			events.ScheduleEvent(EVENT_SONIC_BLADE, urand(6000, 10000));
//			events.ScheduleEvent(EVENT_DISPATCH, 21000);
//			events.ScheduleEvent(EVENT_STICKY_RESIN, urand(12000, 20000));
//		}
//		void Reset()
//		{
//			target_after = false;
//			target_after = NULL;
//		}
//
//		void UpdateAI(const uint32 diff)
//		{
//			events.Update(diff);
//
//			if (!UpdateVictim())
//				return;
//
//			if (fixated)
//			{
//				if (target_after != NULL && target_after && target_after->IsInWorld() && target_after->isAlive() && target_after->HasAura(FIXATE_AURA))
//				{
//					me->AttackStop();                                       // Stop attacking DoMeleeAttackIfReady()
//					me->SetReactState(REACT_PASSIVE);
//
//					me->GetMotionMaster()->MovePoint(1, target_after->GetPositionX(), target_after->GetPositionY(), target_after->GetPositionZ());
//				}
//				else
//				{
//					fixated = false;
//					target_after = NULL;
//
//					AttackStart(me->getVictim());                           // Start attack the victim (random?)
//					me->SetReactState(REACT_AGGRESSIVE);
//				}
//			}
//
//			// band of valor
//			std::list<Creature*> Cr_list;
//
//			JadeCore::AnyCreatureInObjectRangeCheck check(me, 8.0f);
//			JadeCore::CreatureListSearcher<JadeCore::AnyCreatureInObjectRangeCheck> searcher(me, Cr_list, check);
//			me->VisitNearbyObject(8.0f, searcher);
//
//			for (std::list<Creature*>::const_iterator it = Cr_list.begin(); it != Cr_list.end(); ++it)
//			{
//				if (!(*it))
//					return;
//
// 
//                if ((*it)->GetEntry() == 63591 || (*it)->GetEntry() == 64453)
//                {
//                    if (me->HasAura(125422))
//                    {
//                        AuraPtr band_of_valor = me->GetAura(125422);
//
//                        if (band_of_valor)
//                        {
//                            band_of_valor->SetStackAmount(Cr_list.size() - 1);
//                        }
//                    }
//                    else
//                    {
//                        me->AddAura(125422, me);
//                    }
//                }
//			} 
//			while (uint32 eventId = events.ExecuteEvent())
//			{
//				switch (eventId)
//				{
//				case EVENT_FIXATE:
//					if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 50, true))
//					{
//						me->CastSpell(target, FIXATE);
//
//						fixated = true;
//						target_after = target->ToPlayer();
//
//						events.ScheduleEvent(EVENT_FIXATE, urand(32000, 60000));
//					}
//					break;
//				case EVENT_SONIC_BLADE:
//					me->CastSpell(me->getVictim(), SONIC_BOMB);
//					events.ScheduleEvent(EVENT_SONIC_BLADE, urand(6000, 10000));
//					break;
//				case EVENT_DISPATCH:
//					me->AddAura(DISPATCH, me);
//					events.ScheduleEvent(DISPATCH, 21000);
//					break;
//				case EVENT_STICKY_RESIN:
//					Position pos;
//					int32 reduction = urand(0, 1);
//
//					if (reduction == 1)
//					{
//						me->GetRandomNearPosition(pos, frand(5.0f, 10.0f));
//						me->SummonCreature(STICKY_RESIN_TRIGGER, pos, TEMPSUMMON_MANUAL_DESPAWN);
//						events.ScheduleEvent(EVENT_STICKY_RESIN, urand(15000, 22000));
//					}
//					break;
//				}
//			}
//
//			DoMeleeAttackIfReady();
//		}
//
//	private:
//		EventMap events;
//	};
//	CreatureAI* GetAI(Creature* creature) const
//	{
//		return new windblade_AI(creature);
//	}
//};
//class reaver : public CreatureScript
//{
//public:
//	reaver() : CreatureScript("reaver") {}
//
//	struct reaver_AI : public ScriptedAI
//	{
//		reaver_AI(Creature* creature) : ScriptedAI(creature)
//		{
//			me->SetLevel(93);
//			me->setFaction(16);
//		}
//		void EnterCombat(Unit* who)
//		{
//			events.ScheduleEvent(EVENT_POISON_BOMB, urand(5000, 8000));
//			events.ScheduleEvent(EVENT_POISON_DRENCHED_ARMOR, urand(18000, 35000));
//			events.ScheduleEvent(EVENT_TOXIC_SLIME, urand(12000, 18000));
//		}
//		uint32 diffdmgtrap;
//		void Reset()
//		{
//			diffdmgtrap = 2000;
//		}
//		void UpdateAI(const uint32 diff)
//		{
//			events.Update(diff);
//
//			if (!UpdateVictim())
//				return;
//
//			// band of valor
//			std::list<Creature*> Cr_list;
//
//			JadeCore::AnyCreatureInObjectRangeCheck check(me, 8.0f);
//			JadeCore::CreatureListSearcher<JadeCore::AnyCreatureInObjectRangeCheck> searcher(me, Cr_list, check);
//			me->VisitNearbyObject(8.0f, searcher);
//
//            for (std::list<Creature*>::const_iterator it = Cr_list.begin(); it != Cr_list.end(); ++it)
//            {
//                if (!(*it))
//                    return;
//
//                if ((*it)->GetEntry() == 63591 || (*it)->GetEntry() == 64453)
//                {
//                    if (me->HasAura(125422))
//                    {
//                        AuraPtr band_of_valor = me->GetAura(125422);
//
//                        if (band_of_valor)
//                        {
//                            band_of_valor->SetStackAmount(Cr_list.size() - 1);
//                        }
//                    }
//                    else
//                    {
//                        me->AddAura(125422, me);
//                    }
//                }
//            }
//			if (me->HasAura(AMBER_TRAP))
//			{
//				if (diffdmgtrap <= diff)
//				{
//					me->DealDamage(me, me->GetHealth() * 0.05, NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
//					diffdmgtrap = 2100;
//				}
//				else
//					diffdmgtrap -= diff;
//			}
//
//			while (uint32 eventId = events.ExecuteEvent())
//			{
//				switch (eventId)
//				{
//				case EVENT_POISON_BOMB:
//					if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 50, true))
//					{
//						me->CastSpell(target, POISON_BOMB);
//					}
//					events.ScheduleEvent(EVENT_POISON_BOMB, urand(5000, 8000));
//					break;
//				case EVENT_POISON_DRENCHED_ARMOR:
//					me->CastSpell(me->getVictim(), POISON_DRENCHED_ARMOR);
//					events.ScheduleEvent(EVENT_POISON_DRENCHED_ARMOR, urand(18000, 35000));
//					break;
//				case EVENT_TOXIC_SLIME:
//					me->CastSpell(me->getVictim(), TOXIC_SLIME);
//					events.ScheduleEvent(EVENT_TOXIC_SLIME, urand(12000, 18000));
//					break;
//				}
//			}
//
//			DoMeleeAttackIfReady();
//		}
//	private:
//		EventMap events;
//	};
//	CreatureAI* GetAI(Creature* creature) const
//	{
//		return new reaver_AI(creature);
//	}
//};
//class sticky_resin_trigger : public CreatureScript
//{
//public:
//	sticky_resin_trigger() : CreatureScript("sticky_resin_trigger") { }
//
//	struct sticky_resin_triggerAI : public Scripted_NoMovementAI
//	{
//		sticky_resin_triggerAI(Creature* creature) : Scripted_NoMovementAI(creature)
//		{
//			me->SetObjectScale(1.0f);
//			me->setFaction(35);
//		}
//		void Reset()
//		{
//			me->CastSpell(me, STICKY_RESIN_AURA);
//		}
//		void UpdateAI(uint32 const diff)
//		{
//			events.Update(diff);
//
//			std::list<Player*> PL_list;
//
//			JadeCore::AnyPlayerInObjectRangeCheck check(me, 1.0f);
//			JadeCore::PlayerListSearcher<JadeCore::AnyPlayerInObjectRangeCheck> searcher(me, PL_list, check);
//			me->VisitNearbyObject(1.0f, searcher);
//
//			for (std::list<Player*>::const_iterator it = PL_list.begin(); it != PL_list.end(); ++it)
//			{
//				if (!(*it))
//					return;
//
//				if (!(*it)->HasAura(STICKY_RESIN_DOT))
//				{
//					me->DespawnOrUnsummon();
//					(*it)->AddAura(STICKY_RESIN_DOT, (*it));
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
//		return new sticky_resin_triggerAI(creature);
//	}
//};
//class amber_trap_progress : public CreatureScript
//{
//public:
//	amber_trap_progress() : CreatureScript("amber_trap_progress") { }
//
//	struct amber_trap_progressAI : public Scripted_NoMovementAI
//	{
//		amber_trap_progressAI(Creature* creature) : Scripted_NoMovementAI(creature)
//		{
//			me->SetObjectScale(3.0f);
//			me->setFaction(35);
//		}
//		bool pre;
//		bool post;
//		void Reset()
//		{
//			pre = true;
//			post = false;
//			me->CastSpell(me, STICKY_RESIN_AURA);
//		}
//		void UpdateAI(uint32 const diff)
//		{
//			events.Update(diff);
//
//			std::list<Player*> PL_list;
//			std::list<Creature*> Cr_list;
//			
//
//			if (pre)
//			{
//				JadeCore::AnyPlayerInObjectRangeCheck check(me, 1.0f);
//				JadeCore::PlayerListSearcher<JadeCore::AnyPlayerInObjectRangeCheck> searcher(me, PL_list, check);
//				me->VisitNearbyObject(1.0f, searcher);
//
//				for (std::list<Player*>::const_iterator it = PL_list.begin(); it != PL_list.end(); ++it)
//				{
//					if (!(*it))
//						return;
//
//					if ((*it)->HasAura(STICKY_RESIN_DOT))
//					{
//						(*it)->RemoveAura(STICKY_RESIN_DOT);
//
//						if (!me->HasAura(AMBER_TRAP_STACKS_PRE_FROZEN))
//						{
//							me->AddAura(AMBER_TRAP_STACKS_PRE_FROZEN, me);
//						}
//						else
//						{
//							AuraPtr aura_B = me->GetAura(AMBER_TRAP_STACKS_PRE_FROZEN);
//
//							if (aura_B)
//							{
//
//								aura_B->SetStackAmount(aura_B->GetStackAmount() + 1);
//							}
//						}
//					}
//				}
//				if (me->HasAura(AMBER_TRAP_STACKS_PRE_FROZEN))
//				{
//					AuraPtr aur = me->GetAura(AMBER_TRAP_STACKS_PRE_FROZEN);
//
//					if (pre)
//					{
//						if (aur)
//						{
//							if (aur->GetStackAmount() >= 5)
//							{
//								me->SetObjectScale(1.5f);
//								pre = false;
//								post = true;
//							}
//						}
//					}
//				}
//			}
//			if (post)
//			{
//				JadeCore::AnyCreatureInObjectRangeCheck check(me, 3.0f);
//				JadeCore::CreatureListSearcher<JadeCore::AnyCreatureInObjectRangeCheck> searcher(me, Cr_list, check);
//				me->VisitNearbyObject(3.0f, searcher);
//
//				for (std::list<Creature*>::const_iterator it = Cr_list.begin(); it != Cr_list.end(); ++it)
//				{
//					if (!(*it))
//						return;
//
//					if ((*it)->GetEntry() == 63591)
//					{
//						(*it)->AddAura(AMBER_TRAP, (*it));
//						me->DespawnOrUnsummon();
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
//		return new amber_trap_progressAI(creature);
//	}
//};
//class sticky_resin_dot : public SpellScriptLoader
//{
//public:
//	sticky_resin_dot() : SpellScriptLoader("sticky_resin_dot") { }
//
//	class sticky_resin_dot_Aura_Script : public AuraScript {
//		PrepareAuraScript(sticky_resin_dot_Aura_Script);
//
//		void OnUpdate(constAuraEffectPtr aurEff)
//		{
//			if (GetCaster())
//			{
//				if (GetTarget())
//				{
//					std::list<Player*> PL_list;
//
//					JadeCore::AnyPlayerInObjectRangeCheck check(GetTarget(), 1.0f);
//					JadeCore::PlayerListSearcher<JadeCore::AnyPlayerInObjectRangeCheck> searcher(GetTarget(), PL_list, check);
//					GetTarget()->VisitNearbyObject(1.12f, searcher);
//
//					for (std::list<Player*>::const_iterator it = PL_list.begin(); it != PL_list.end(); ++it)
//					{
//						if (!(*it))
//							return;
//
//						if ((*it)->HasAura(STICKY_RESIN_DOT) && (*it)->GetGUID() != GetTarget()->GetGUID() && GetTarget()->HasAura(STICKY_RESIN_DOT))
//						{
//							(*it)->RemoveAura(STICKY_RESIN_DOT);
//							GetTarget()->RemoveAura(STICKY_RESIN_DOT);
//
//							(*it)->SummonCreature(AMBER_TRAP_TRIGGER, (*it)->GetPositionX(), (*it)->GetPositionY(), (*it)->GetPositionZ(), (*it)->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN);
//						}
//					}
//				}
//			}
//		}
//		void Register()
//		{
//			OnEffectPeriodic += AuraEffectPeriodicFn(sticky_resin_dot_Aura_Script::OnUpdate, EFFECT_1, SPELL_AURA_PERIODIC_DAMAGE);
//		}
//	};
//
//	AuraScript* GetAuraScript() const
//	{
//		return new sticky_resin_dot_Aura_Script();
//	}
//};
//class amber_trap_stun : public SpellScriptLoader
//{
//public:
//	amber_trap_stun() : SpellScriptLoader("amber_trap_stun") { }
//
//	class amber_trap_stun_aura : public AuraScript
//	{
//		PrepareAuraScript(amber_trap_stun_aura);
//
//		void OnApply(constAuraEffectPtr /*aurEff*/, AuraEffectHandleModes /*mode*/)
//		{
//			if (GetTarget())
//			{
//				GetTarget()->SetControlled(true, UNIT_STATE_STUNNED);
//			}
//		}
//
//		void OnRemove(constAuraEffectPtr /*aurEff*/, AuraEffectHandleModes /*mode*/)
//		{
//			if (GetTarget())
//			{
//				GetTarget()->SetControlled(false, UNIT_STATE_STUNNED);
//			}
//		}
//		void Register()
//		{
//			OnEffectApply += AuraEffectApplyFn(amber_trap_stun_aura::OnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
//			OnEffectRemove += AuraEffectRemoveFn(amber_trap_stun_aura::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
//		}
//	};
//
//	AuraScript* GetAuraScript() const
//	{
//		return new amber_trap_stun_aura();
//	}
//};
//
//// called by 124862
//class visions_Demise : public SpellScriptLoader
//{
//public:
//	visions_Demise() : SpellScriptLoader("visions_Demise") { }
//
//	class visions_Demise_aura : public AuraScript
//	{
//		PrepareAuraScript(visions_Demise_aura);
//
//		void OnRemove(constAuraEffectPtr /*aurEff*/, AuraEffectHandleModes /*mode*/)
//		{
//			if (GetTarget())
//			{
//				GetTarget()->AddAura(124863, GetTarget());
//			}
//		}
//		void Register()
//		{
//			OnEffectRemove += AuraEffectRemoveFn(visions_Demise_aura::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
//		}
//	};
//
//	AuraScript* GetAuraScript() const
//	{
//		return new visions_Demise_aura();
//	}
//};
//
//class calamity_damage : public SpellScriptLoader
//{
//public:
//    calamity_damage() : SpellScriptLoader("calamity_damage") {}
//
//    class calamity_damage_spell_script : public SpellScript
//    {
//        PrepareSpellScript(calamity_damage_spell_script);
//
//        void HandleOnHit()
//        {
//            if (!GetCaster())
//                return;
//
//            Unit* caster = GetCaster();
//
//            if (!GetHitUnit())
//                return;
//            if (!GetSpellInfo())
//                return;
//
//            Unit* target = GetHitUnit();
//
//            int bp = target->GetHealth() * 0.5;
//
//            caster->CastCustomSpell(target, GetSpellInfo()->Id, &bp, NULL, NULL, true);
//        }
//
//        void Register()
//        {
//            OnHit += SpellHitFn(calamity_damage_spell_script::HandleOnHit);
//        }
//    };
//
//    SpellScript* GetSpellScript() const
//    {
//        return new calamity_damage_spell_script();
//    }
//};
//void AddSC_empress_shekzeer()
//{
//	// boss
//	new boss_empress_shekzeer();
//
//	// PHASE 1
//	// spells 
//	new npc_dissonance_field();
//    new npc_dissonance_trigger_explosion();
//	new eye_of_the_empress();
//
//	// PHASE 2
//	new amber_trap_progress();
//	new sticky_resin_trigger();
//	new sticky_resin_dot();
//	new amber_trap_stun();
//
//	// mobs
//	new reaver();
//	new windblade();
//
//	// phase 3
//	new visions_Demise();
//
//    new calamity_damage();
//}
