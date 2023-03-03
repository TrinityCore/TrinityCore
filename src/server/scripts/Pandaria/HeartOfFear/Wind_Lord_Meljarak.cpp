//
//#include "ObjectMgr.h"
//#include "Player.h"
//#include "ScriptMgr.h"
//#include "ScriptedCreature.h"
//#include "AchievementMgr.h"
///*
//REMEMBER! ALL ADD FROM ALL KIND SHARE SAME HP POOL, IF ONE ADD DIE THE OTHER TWO DIES AS WELL.
//*/
//enum Achievements
//{
//
//};
//enum Spells
//{
//	RAIN_OF_BLADE = 122406,
//	RECKLESSNESS = 122354, // when a type of adds dies
//
//	// WHIRLING BLADE
//	SPELL_WHIRLING_BLADE = 121896,
//	WHIRLING_BLADE_BLADE_VISAL = 121897,
//	WHIRLING_BLADE_DMG = 121898,
//	WHIRLING_RED_VISUAL = 122083,
//
//	// ADDS
//	// amber trapper
//
//	AMBER_PRISON = 121881,
//	AMBER_PRISON_AURA = 121874,
//	RESIDUE_CD_BETWEEN_PRISON_BREAK = 122055,  // amber prison 35 milli
//
//
//	CORROSIVE_RESIN_AURA_DOT = 129005,
//	CORROSIVE_RESIN_POOL_DOT = 122125,
//	CORROSIVE_RESIN_STACK = 122064,            // corriosive resin 35 milli
//	//battle mender
//	MENDING = 122193,
//	QUICKENING = 122149,
//
//	// blade master
//	KORTHIK_AURA_KNOW_TO_ATTACK = 123963,
//	KORTHIK_STRIKE = 123962, // needs to be added with a motionmaster toward the player
//
//	// Wind bomb
//	WIND_BOMB_VISUAL_AREA = 131835,
//	WIND_BOMB_EXPLOSION = 131842,
//
//    SPELL_BERSERK_MELJARAK = 120207, // 480 seconds or 8 mins Enrage.
//};
//enum Mobs
//{
//	AMBER_TRAPPER = 62405,
//	BLADE_MASTER = 62402,
//	BATTLE_MENDER = 624008,
//
//	// AMBER CONRROSIVE
//	CORROSIVE_POOL_TRIGGER = 453543,
//
//	// Whirlwind trigger
//	WHIRLWIND_TRIGGER = 4456457,
//
//	// WIND BOMB TRIGGER
//	WIND_BOMB_TRIGGER = 3353466,
//
//	BOSS_ENTRY = 62397,
//
//	// AMBER PRISON
//	AMBER_PRISON_NPC = 62531,
//};
//enum Events
//{
//	EVENT_RAIN_OF_BLADE = 1,
//	EVENT_WHIRLWIND_BLADE = 2,
//	EVENT_RECKLESNESS = 3,
//	EVENT_ACTIVATE_FIRST_ADDS = 4,
//	EVENT_ACTIVATE_SECOND_ADDS = 5,
//
//	// ADD
//	EVENT_AMBER_PRISON = 10,
//	EVENT_CORROSIVE_RESIN = 11,
//	EVENT_MENDING = 12,
//	EVENT_QUICKENING = 13,
//	EVENT_KORTHIK_STRIKE = 14,
//	// WIND BOMB
//	EVENT_WIND_BOMB = 15,
//    EVENT_BERSERK_MELJARAK = 16,
//};
//Position const BladeMaster_1[3] =
//{
//	{ -2091.07f, 482.76f, 503.568f, 3.097356f },
//	{ -2095.98f, 476.09f, 503.568f, 3.156261f },
//	{ -2093.21f, 466.45f, 503.567f, 3.010962f },
//};
//Position const BattleMender_1[3] =
//{
//	{ -2085.80f, 454.11f, 503.567f, 2.956772f },
//	{ -2092.17f, 450.75f, 503.566f, 3.011750f },
//	{ -2088.61f, 445.52f, 503.566f, 2.725080f },
//};
//Position const AmberTrapper_1[3] =
//{
//	{ -2086.56f, 497.64f, 503.567f, 3.411518f },
//	{ -2090.24f, 500.36f, 503.567f, 3.446861f },
//	{ -2090.07f, 506.86f, 503.566f, 3.505765f },
//};
//
//class boss_lord_meljarak : public CreatureScript
//{
//public:
//	boss_lord_meljarak() : CreatureScript("boss_lord_meljarak") { }
//
//	struct boss_lord_meljarakAI : public BossAI
//	{
//		boss_lord_meljarakAI(Creature* creature) : BossAI(creature, 0)
//		{
//			me->SetLevel(94);
//			me->setFaction(16);
//
//			/*
//			if (IsHeroic() && Is25ManRaid())
//			{
//				me->SetMaxHealth(1589719296);
//				me->SetHealth(1589719296);
//			}
//			else if (Is25ManRaid())
//			{
//				me->SetMaxHealth(768953152);
//				me->SetHealth(768953152);
//			}
//			else if (IsHeroic())
//			{
//				me->SetMaxHealth(588784960);
//				me->SetHealth(588784960);
//			}
//			else
//			{
//				me->SetMaxHealth(270404928);
//				me->SetHealth(270404928);
//			}
//			*/
//		}
//		std::list<Creature*> Dead_Adds;
//
//		std::list<Creature*> Dead_Blade_Masters;
//		std::list<Creature*> Dead_Amber_Trapper;
//		std::list<Creature*> Dead_Battle_Mender;
//
//		std::list<Creature*> CC_Blade_Masters;
//		std::list<Creature*> CC_Amber_Trapper;
//		std::list<Creature*> CC_Battle_Mender;
//
//		InstanceScript* instance;
//		bool cdchange;
//		bool cdchange2;
//
//		bool Battle_Mender_Down;
//		bool Amber_Trapper_Down;
//		bool Blade_Master_Down;
//
//		void Reset()
//		{
//			_Reset();
//
//			cdchange = false;
//
//			Battle_Mender_Down = false;
//			Amber_Trapper_Down = false;
//			Blade_Master_Down = false;
//
//			AddsDeSpawn();
//
//			// Erase All Lists
//			Dead_Adds.clear();
//
//			Dead_Blade_Masters.clear();
//			Dead_Amber_Trapper.clear();
//			Dead_Battle_Mender.clear();
//		}
//		void AddsDeSpawn()
//		{
//			// Delete adds if there are any left from last fights
//			me->DespawnCreaturesInArea(BATTLE_MENDER);
//			me->DespawnCreaturesInArea(AMBER_TRAPPER);
//			me->DespawnCreaturesInArea(BLADE_MASTER);
//			me->DespawnCreaturesInArea(CORROSIVE_POOL_TRIGGER);
//
//			// Summon Blade Master
//			// Summon Battle Mender
//			// Summon Amber Trapper
//		}
//		void EnterCombat(Unit* who)
//		{
//			_EnterCombat();
//
//			if (!me->FindNearestCreature(AMBER_TRAPPER, 50.0f, true)) // check if not duplicate
//			{
//				for (int i = 0; i <= 2; i++)
//				{
//					me->SummonCreature(AMBER_TRAPPER, AmberTrapper_1[i], TEMPSUMMON_MANUAL_DESPAWN, 0);
//					me->SummonCreature(BLADE_MASTER, BladeMaster_1[i], TEMPSUMMON_MANUAL_DESPAWN, 0);
//					me->SummonCreature(BATTLE_MENDER, BattleMender_1[i], TEMPSUMMON_MANUAL_DESPAWN, 0);
//				}
//			}
//
//			// say 
//			me->MonsterYell("All of pandaria will fall beneath the wings on the Empress!", LANG_UNIVERSAL, me->GetGUID());
//			DoPlaySoundToSet(me, 30336);
//
//            events.CancelEvent(EVENT_WIND_BOMB);
//            events.CancelEvent(EVENT_RAIN_OF_BLADE);
//
//			// Boss spells
//			events.ScheduleEvent(EVENT_RAIN_OF_BLADE, 60000);
//			events.ScheduleEvent(EVENT_KORTHIK_STRIKE, 35000);
//           // events.ScheduleEvent(EVENT_WHIRLING_BLADE, 36000);
//
//			// First adds
//			events.ScheduleEvent(EVENT_ACTIVATE_FIRST_ADDS, 500);
//
//			// Summon Weapon racks - near door east
//			me->SummonCreature(324256, -2107.39f, 437.93f, 503.569f, 1.255061f, TEMPSUMMON_MANUAL_DESPAWN, 0);
//			// - near door west
//            me->SummonCreature(324256, -2113.20f, 513.62f, 503.569f, 5.060318f, TEMPSUMMON_MANUAL_DESPAWN, 0);
//			// -- far door west
//            me->SummonCreature(324256, -2083.23f, 521.40f, 503.569f, 4.574944f, TEMPSUMMON_MANUAL_DESPAWN, 0);
//			// --- far door east
//            me->SummonCreature(324256, -2072.12f, 432.67f, 503.569f, 1.688611f, TEMPSUMMON_MANUAL_DESPAWN, 0);
//
//			// Doors
//			me->SummonGameObject(180322, -2107.30f, 416.22f, 498.141f, 5.992583f, 0, 0, 0, 0, 0);
//			me->SummonGameObject(180322, -2103.85f, 536.42f, 497.289f, 0.172781f, 0, 0, 0, 0, 0);
//			me->SummonGameObject(180322, -2163.86f, 475.93f, 503.571f, 3.129808f, 0, 0, 0, 0, 0);
//		}
//		void JustReachedHome()
//		{
//			//	instance->SetBossState(DATA_TAYAK, FAIL);
//			summons.DespawnAll();
//
//			me->DespawnCreaturesInArea(CORROSIVE_POOL_TRIGGER);
//			me->DespawnCreaturesInArea(AMBER_PRISON_NPC);
//            me->DespawnCreaturesInArea(324256); // weapons
//
//			std::list<GameObject*> racklist;
//			std::list<GameObject*> ghostlist;
//
//			me->GetGameObjectListWithEntryInGrid(ghostlist, 180322, 300.0f);
//
//			for (std::list<GameObject*>::const_iterator itr = ghostlist.begin(); itr != ghostlist.end(); itr++)
//			{
//				if ((*itr) && (*itr)->IsInWorld())
//					(*itr)->Delete();
//				//(*itr)->DeleteFromDB(); 
//			}
//		}
//		void DamageTaken(Unit* attacker, uint32& damage)
//		{
//			if (!me->HealthAbovePct(75) && !cdchange) // ramps changes
//			{
//				cdchange = true;
//				events.ScheduleEvent(EVENT_WIND_BOMB, 7000);
//			}
//		}
//		void UpdateAI(uint32 const diff)
//		{
//			events.Update(diff);
//
//			if (!UpdateVictim())
//				return;
//
//			if (Dead_Amber_Trapper.size() == 1 && !Amber_Trapper_Down)
//			{
//				Amber_Trapper_Down = true;
//				events.ScheduleEvent(EVENT_RECKLESNESS, 1000);
//			}
//			if (Dead_Battle_Mender.size() == 1 && !Battle_Mender_Down)
//			{
//				Battle_Mender_Down = true;
//				events.ScheduleEvent(EVENT_RECKLESNESS, 1000);
//			}
//			if (Dead_Blade_Masters.size() == 1 && !Blade_Master_Down)
//			{
//				Blade_Master_Down = true;
//				events.ScheduleEvent(EVENT_RECKLESNESS, 1000);
//			}
//
//			while (uint32 eventId = events.ExecuteEvent())
//			{
//				switch (eventId)
//				{
//				case EVENT_RECKLESNESS:
//					if (!me->HasAura(RECKLESSNESS))
//					{
//						me->AddAura(RECKLESSNESS, me);
//					}
//					else
//					{
//						AuraPtr aura_B = me->GetAura(RECKLESSNESS);
//
//						if (aura_B)
//						{
//							aura_B->SetStackAmount(aura_B->GetStackAmount() + 1);
//						}
//					}
//					break;
//				case EVENT_WIND_BOMB:
//					if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 20, true))
//					{
//						me->SummonCreature(WIND_BOMB_TRIGGER, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), target->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN, 0);
//					}
//					events.ScheduleEvent(EVENT_WIND_BOMB, 7000);
//					break;
//				case EVENT_KORTHIK_STRIKE:
//					// Order other to strike this target, DESERVE
//					if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 20, true))
//					{
//						me->CastSpell(target, KORTHIK_AURA_KNOW_TO_ATTACK);
//						events.ScheduleEvent(EVENT_KORTHIK_STRIKE, 60000);
//					}
//					break;
//				case EVENT_RAIN_OF_BLADE:
//					me->CastSpell(me, RAIN_OF_BLADE);
//					events.ScheduleEvent(EVENT_RAIN_OF_BLADE, 60000);
//					break;
//				case EVENT_WHIRLWIND_BLADE:
//				{
//					if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 20, true))
//					{
//							me->CastSpell(target, WHIRLING_BLADE_BLADE_VISAL);
//					}
//					events.ScheduleEvent(EVENT_WHIRLWIND_BLADE, 35000);
//					break;
//				}
//                case EVENT_BERSERK_MELJARAK:
//                    DoCast(me, SPELL_BERSERK_MELJARAK);
//                    break;
//				case EVENT_ACTIVATE_FIRST_ADDS:
//				{
//					std::list<Creature*> AT;
//					std::list<Creature*> BL;
//
//					me->GetCreatureListWithEntryInGrid(BL, BLADE_MASTER, 30.0f);
//					me->GetCreatureListWithEntryInGrid(AT, AMBER_TRAPPER, 30.0f);
//					Creature* BM = me->FindNearestCreature(BATTLE_MENDER, 30.0f, true);
//
//					if (AT.size() > 1)
//						AT.remove(AT.back());
//
//					if (BL.size() > 1)
//						BL.remove(BL.back());
//
//					if (BM && BM->isAlive())
//					{
//						BM->setFaction(16);
//
//						if (Unit* target = me->getVictim())
//							if (MotionMaster* motion = BM->GetMotionMaster())
//								motion->MovePoint(1, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ());
//					}
//
//					for (std::list<Creature*>::const_iterator it = AT.begin(); it != AT.end(); ++it)
//					{
//						if ((*it))
//						{
//							if ((*it)->isAlive())
//							{
//								(*it)->setFaction(16);
//
//								if (Unit* target = me->getVictim())
//									if (MotionMaster* motion = (*it)->GetMotionMaster())
//										motion->MovePoint(1, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ());
//							}
//						}
//					}
//					for (std::list<Creature*>::const_iterator it = BL.begin(); it != BL.end(); ++it)
//					{
//						if ((*it))
//						{
//							if ((*it)->isAlive())
//							{
//								(*it)->setFaction(16);
//
//								if (Unit* target = me->getVictim())
//								if (MotionMaster* motion = (*it)->GetMotionMaster())
//									motion->MovePoint(1, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ());
//							}
//						}
//					}
//					break;
//				}
//				}
//			}
//			DoMeleeAttackIfReady();
//		}
//		void JustDied(Unit* killer)
//		{
//			_JustDied();
//
//			me->DespawnCreaturesInArea(CORROSIVE_POOL_TRIGGER);
//			me->DespawnCreaturesInArea(AMBER_PRISON_NPC);
//
//
//			std::list<GameObject*> racklist;
//			std::list<GameObject*> ghostlist;
//
//            me->GetGameObjectListWithEntryInGrid(racklist, 324256, 300.0f);
//			me->GetGameObjectListWithEntryInGrid(ghostlist, 180322, 300.0f);
//
//			for (std::list<GameObject*>::const_iterator itr = racklist.begin(); itr != racklist.end(); itr++)
//			{
//				if ((*itr) && (*itr)->IsInWorld())
//					(*itr)->Delete();
//				//(*itr)->DeleteFromDB(); 
//			}
//			for (std::list<GameObject*>::const_iterator itr = ghostlist.begin(); itr != ghostlist.end(); itr++)
//			{
//				if ((*itr) && (*itr)->IsInWorld())
//					(*itr)->Delete();
//				//(*itr)->DeleteFromDB(); 
//			}
//
//			me->MonsterYell("Empress... I.. have failed you.", LANG_UNIVERSAL, me->GetGUID());
//			DoPlaySoundToSet(me, 30337);
//
//            Map::PlayerList const &PlList = me->GetMap()->GetPlayers();
//            if (PlList.isEmpty())
//                return;
//            AchievementEntry const* achievementEntry = sAchievementMgr->GetAchievement(6718);
//            for (Map::PlayerList::const_iterator i = PlList.begin(); i != PlList.end(); ++i)
//                if (Player* player = i->getSource())
//                        player->CompletedAchievement(achievementEntry);
//
//			me->DespawnCreaturesInArea(CORROSIVE_POOL_TRIGGER);
//		}
//		void KilledUnit(Unit* victim)
//		{
//			if (victim->GetTypeId() == TYPEID_PLAYER)
//			{
//				switch (urand(0, 1))
//				{
//				case 0:
//					me->MonsterYell("The Empress commands it!", LANG_UNIVERSAL, me->GetGUID());
//					DoPlaySoundToSet(me, 30338);
//					break;
//				case 1:
//					me->MonsterYell("Pitiful..", LANG_UNIVERSAL, me->GetGUID());
//					DoPlaySoundToSet(me, 30339);
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
//		return new boss_lord_meljarakAI(creature);
//	}
//};
//// Adds
//class npc_battle_mender : public CreatureScript
//{
//public:
//	npc_battle_mender() : CreatureScript("npc_battle_mender") { }
//
//	struct npc_battle_menderAI : public ScriptedAI
//	{
//		npc_battle_menderAI(Creature* creature) : ScriptedAI(creature)
//		{
//			me->SetLevel(92);
//			me->setFaction(35);
//
//			if (!Is25ManRaid())
//			{
//				me->SetMaxHealth(147978784);
//				me->SetHealth(147978784);
//			}
//			else
//			{
//				me->SetMaxHealth(54806960);
//				me->SetHealth(54806960);
//			}
//		}
//		void Reset()
//		{
//			events.Reset();
//		}
//		void EnterCombat(Unit* who)
//		{
//			events.ScheduleEvent(EVENT_MENDING, 15000);
//			events.ScheduleEvent(EVENT_QUICKENING, urand(8000, 12000));
//		}
//		void JustDied(Unit* killer)
//		{
//			std::list<Creature*> Brothers;
//			killer->GetCreatureListWithEntryInGrid(Brothers, BATTLE_MENDER, 40.0f);
//			if (Creature* boss = me->FindNearestCreature(BOSS_ENTRY, 40.0f, true))
//			{
//				if (boss_lord_meljarak::boss_lord_meljarakAI* linkAI = CAST_AI(boss_lord_meljarak::boss_lord_meljarakAI, boss->GetAI()))
//				{
//					linkAI->Dead_Adds.push_back(me);
//					linkAI->Dead_Battle_Mender.push_back(me);
//				}
//			}
//			for (std::list<Creature*>::const_iterator it = Brothers.begin(); it != Brothers.end(); ++it)
//			{
//				if (!(*it))
//					return;
//
//				if ((*it) && (*it)->IsInWorld())
//					(*it)->DespawnOrUnsummon();
//			}
//		}
//		void UpdateAI(uint32 const diff)
//		{
//			events.Update(diff);
//
//			while (uint32 eventId = events.ExecuteEvent())
//			{
//				switch (eventId)
//				{
//				case EVENT_MENDING:
//					switch (urand(0, 2))
//					{
//					case 0:
//						if (Creature* Blade = me->FindNearestCreature(BLADE_MASTER, 20.0f, true))
//							me->CastSpell(Blade, MENDING);
//						break;
//					case 1:
//						if (Creature* Battle = me->FindNearestCreature(BATTLE_MENDER, 20.0f, true))
//							me->CastSpell(Battle, MENDING);
//						break;
//					case 2:
//						if (Creature* Amber = me->FindNearestCreature(AMBER_TRAPPER, 20.0f, true))
//							me->CastSpell(Amber, MENDING);
//						break;
//					}
//					events.ScheduleEvent(EVENT_MENDING, 15000);
//					break;
//				case EVENT_QUICKENING:
//					DoCastAOE(QUICKENING);
//					events.ScheduleEvent(EVENT_QUICKENING, urand(8000, 12000));
//					break;
//				}
//			}
//			DoMeleeAttackIfReady();
//		}
//	private:
//		EventMap events;
//	};
//
//	CreatureAI* GetAI(Creature* creature) const
//	{
//		return new npc_battle_menderAI(creature);
//	}
//};
//class npc_trapper_sap : public CreatureScript
//{
//public:
//	npc_trapper_sap() : CreatureScript("npc_trapper_sap") { }
//
//	struct npc_trapper_sapAI : public ScriptedAI
//	{
//		npc_trapper_sapAI(Creature* creature) : ScriptedAI(creature)
//		{
//			me->SetLevel(92);
//			me->setFaction(35);
//
//			if (!Is25ManRaid())
//			{
//				me->SetMaxHealth(147978784);
//				me->SetHealth(147978784);
//			}
//			else
//			{
//				me->SetMaxHealth(54806960);
//				me->SetHealth(54806960);
//			}
//		}
//		void Reset()
//		{
//			events.Reset();
//		}
//		void EnterCombat(Unit* who)
//		{
//			events.ScheduleEvent(EVENT_CORROSIVE_RESIN, 35000);
//			events.ScheduleEvent(EVENT_AMBER_PRISON, 25000);
//		}
//		void JustDied(Unit* killer)
//		{
//			std::list<Creature*> Brothers;
//			killer->GetCreatureListWithEntryInGrid(Brothers, AMBER_TRAPPER, 40.0f);
//
//			if (Creature* boss = me->FindNearestCreature(BOSS_ENTRY, 40.0f, true))
//			{
//				if (boss_lord_meljarak::boss_lord_meljarakAI* linkAI = CAST_AI(boss_lord_meljarak::boss_lord_meljarakAI, boss->GetAI()))
//				{
//					linkAI->Dead_Adds.push_back(me);
//					linkAI->Dead_Amber_Trapper.push_back(me);
//				}
//			}
//			for (std::list<Creature*>::const_iterator it = Brothers.begin(); it != Brothers.end(); ++it)
//			{
//				if (!(*it))
//					return;
//
//				if ((*it) && (*it)->IsInWorld())
//					(*it)->DespawnOrUnsummon();
//			}
//		}
//		void UpdateAI(uint32 const diff)
//		{
//			events.Update(diff);
//
//			while (uint32 eventId = events.ExecuteEvent())
//			{
//				switch (eventId)
//				{
//				case EVENT_CORROSIVE_RESIN:
//					if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 20, true))
//					{
//							me->AddAura(CORROSIVE_RESIN_STACK, target);
//
//							if (target->HasAura(CORROSIVE_RESIN_STACK))
//							{
//								AuraPtr COR = target->GetAura(CORROSIVE_RESIN_STACK);
//
//								if (COR)
//									COR->SetStackAmount(5);
//							}
//						events.ScheduleEvent(EVENT_CORROSIVE_RESIN, 25000);
//					}
//					break;
//				case EVENT_AMBER_PRISON:
//					if (Unit* unitTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 20, true))
//					{
//						if (!unitTarget->HasAura(121885))
//						{
//							me->AddAura(121885, unitTarget);
//							Creature* Amber_Visual = unitTarget->SummonCreature(62531, unitTarget->GetPositionX(), unitTarget->GetPositionY(), unitTarget->GetPositionZ(), unitTarget->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN, 0);
//							events.ScheduleEvent(EVENT_AMBER_PRISON, 32000);
//						}
//					}
//					break;
//				}
//			}
//			DoMeleeAttackIfReady();
//		}
//	private:
//		EventMap events;
//	};
//
//	CreatureAI* GetAI(Creature* creature) const
//	{
//		return new npc_trapper_sapAI(creature);
//	}
//};
//class npc_blade_master : public CreatureScript
//{
//public:
//	npc_blade_master() : CreatureScript("npc_blade_master") { }
//
//	struct npc_blade_masterAI : public ScriptedAI
//	{
//		npc_blade_masterAI(Creature* creature) : ScriptedAI(creature)
//		{
//			me->SetLevel(92);
//			me->setFaction(35);
//
//			if (!Is25ManRaid())
//			{
//				me->SetMaxHealth(147978784);
//				me->SetHealth(147978784);
//			}
//			else
//			{
//				me->SetMaxHealth(54806960);
//				me->SetHealth(54806960);
//			}
//		}
//		bool HasAttacked;
//		void Reset()
//		{
//			HasAttacked = false;
//			events.Reset();
//		}
//		void EnterCombat(Unit* who)
//		{
//			events.ScheduleEvent(EVENT_KORTHIK_STRIKE, 35000);
//		}
//		void JustDied(Unit* killer)
//		{
//			if (!killer)
//				return;
//
//			std::list<Creature*> Brothers;
//			killer->GetCreatureListWithEntryInGrid(Brothers, BLADE_MASTER, 40.0f);
//			if (Creature* boss = me->FindNearestCreature(BOSS_ENTRY, 40.0f, true))
//			{
//				if (boss_lord_meljarak::boss_lord_meljarakAI* linkAI = CAST_AI(boss_lord_meljarak::boss_lord_meljarakAI, boss->GetAI()))
//				{
//					linkAI->Dead_Adds.push_back(me);
//					linkAI->Dead_Blade_Masters.push_back(me);
//				}
//			}
//			for (std::list<Creature*>::const_iterator it = Brothers.begin(); it != Brothers.end(); ++it)
//			{
//				if (!(*it))
//					return;
//
//				if ((*it) && (*it)->IsInWorld())
//					(*it)->DespawnOrUnsummon();
//			}
//		}
//		void UpdateAI(uint32 const diff)
//		{
//			events.Update(diff);
//
//			std::list<Player*> PL_list;
//
//			JadeCore::AnyPlayerInObjectRangeCheck check(me, 20.0f);
//			JadeCore::PlayerListSearcher<JadeCore::AnyPlayerInObjectRangeCheck> searcher(me, PL_list, check);
//			me->VisitNearbyObject(20.0f, searcher);
//
//			if (PL_list.size() > 1)
//				PL_list.resize(1);
//
//			for (std::list<Player*>::const_iterator it = PL_list.begin(); it != PL_list.end(); ++it)
//			{
//				if (!(*it))
//					return;
//
//				if ((*it)->HasAura(KORTHIK_AURA_KNOW_TO_ATTACK) && !HasAttacked)
//				{
//					events.ScheduleEvent(EVENT_KORTHIK_STRIKE, 1000);
//				}
//			}
//	
//			while (uint32 eventId = events.ExecuteEvent())
//			{
//				switch (eventId)
//				{
//				case EVENT_KORTHIK_STRIKE:
//				{
//					std::list<Player*> PL_list;
//
//					JadeCore::AnyPlayerInObjectRangeCheck check(me, 20.0f);
//					JadeCore::PlayerListSearcher<JadeCore::AnyPlayerInObjectRangeCheck> searcher(me, PL_list, check);
//					me->VisitNearbyObject(20.0f, searcher);
//
//					if (PL_list.size() > 1)
//						PL_list.resize(1);
//
//					for (std::list<Player*>::const_iterator it = PL_list.begin(); it != PL_list.end(); ++it)
//					{
//						if (!(*it))
//							return;
//
//						if ((*it)->HasAura(KORTHIK_AURA_KNOW_TO_ATTACK))
//						{
//							me->CastSpell((*it), KORTHIK_STRIKE);
//							(*it)->RemoveAura(KORTHIK_AURA_KNOW_TO_ATTACK);
//
//							HasAttacked = true;
//
//							if (MotionMaster* motion = me->GetMotionMaster())
//							{
//								motion->MovePoint(1, (*it)->GetPositionX(), (*it)->GetPositionY(), (*it)->GetPositionZ());
//							}
//						}
//					}
//					break;
//				}
//				
//				}
//			}
//			DoMeleeAttackIfReady();
//
//		}
//	private:
//		EventMap events;
//	};
//
//	CreatureAI* GetAI(Creature* creature) const
//	{
//		return new npc_blade_masterAI(creature);
//	}
//};
//// SPELLS
//// AMBER PRISON
//class AMBER_PRISON_TRIGGER : public CreatureScript
//{
//public:
//	AMBER_PRISON_TRIGGER() : CreatureScript("AMBER_PRISON_TRIGGER") {}
//
//	bool OnGossipHello(Player* player, Creature* creature)
//	{
//		if (TempSummon* tempo = creature->ToTempSummon())
//		{
//			if (Player* pl = tempo->GetSummoner()->ToPlayer())
//			{
//				if (pl->HasAura(121885))
//				{
//					if (!player->HasAura(RESIDUE_CD_BETWEEN_PRISON_BREAK))
//					{
//						if (player->GetGUID() != pl->GetGUID())
//						{
//							pl->RemoveAura(121885);
//
//							// Handle the one who gossip
//							player->AddAura(RESIDUE_CD_BETWEEN_PRISON_BREAK, player);
//
//							// Despawn the visual
//							creature->DespawnOrUnsummon();
//							return true;
//						}
//					}
//				}
//			}
//		}
//		return false;
//	}
//};
//// Corrosive Resin Stack
//class spell_corrosive_resin : public SpellScriptLoader
//{
//public:
//	spell_corrosive_resin() : SpellScriptLoader("spell_corrosive_resin") { }
//
//	class spell_corrosive_resinAURA : public AuraScript {
//		PrepareAuraScript(spell_corrosive_resinAURA);
//
//		int32 cooldownPer;
//
//		void OnUpdate(constAuraEffectPtr aurEff)
//		{
//			if (!GetTarget())
//				return;
//
//			if (GetTarget()->GetTypeId() != TYPEID_PLAYER)
//				return;
//
//			Player* pl = GetTarget()->ToPlayer();
//
//			if (pl->HasAura(CORROSIVE_RESIN_STACK))
//			{
//				AuraPtr CorrosiveResin = pl->GetAura(CORROSIVE_RESIN_STACK);
//
//				if (pl->isMoving())
//				{
//					pl->SummonCreature(CORROSIVE_POOL_TRIGGER, pl->GetPositionX(), pl->GetPositionY(), pl->GetPositionZ(), pl->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN, 25 * IN_MILLISECONDS);
//
//					if (CorrosiveResin->GetStackAmount() > 1)
//					{
//						CorrosiveResin->SetStackAmount(CorrosiveResin->GetStackAmount() - 1);
//					}
//					else
//					{
//						pl->RemoveAura(CorrosiveResin);
//					}
//				}
//			}
//		}
//		void Register()
//		{
//			OnEffectPeriodic += AuraEffectPeriodicFn(spell_corrosive_resinAURA::OnUpdate, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
//		}
//	};
//
//	AuraScript* GetAuraScript() const
//	{
//		return new spell_corrosive_resinAURA();
//	}
//};
//class npc_paddle_amber : public CreatureScript
//{
//public:
//	npc_paddle_amber() : CreatureScript("npc_paddle_amber") { }
//
//	struct npc_paddle_amberAI : public Scripted_NoMovementAI
//	{
//		npc_paddle_amberAI(Creature* creature) : Scripted_NoMovementAI(creature)
//		{
//			me->SetObjectScale(0.4f);
//			me->SetSpeed(MOVE_RUN, 0.0f, true);
//			me->setFaction(35);
//		}
//		void Reset()
//		{
//			me->AddAura(CORROSIVE_RESIN_AURA_DOT, me);
//		}
//		void UpdateAI(uint32 const diff)
//		{
//		}
//	private:
//		EventMap events;
//		std::list<Player*> Player_List;
//	};
//
//	CreatureAI* GetAI(Creature* creature) const
//	{
//		return new npc_paddle_amberAI(creature);
//	}
//};
//// Whirlwind Blade
//// CALLED BY 121881
//class Whirlwind_Blade_Spell : public SpellScriptLoader
//{
//public:
//	Whirlwind_Blade_Spell() : SpellScriptLoader("Whirlwind_Blade_Spell") {}
//
//	class Whirlwind_Blade_SpellScript : public SpellScript
//	{
//		PrepareSpellScript(Whirlwind_Blade_SpellScript);
//
//		void HandleOnCast()
//		{
//			if (!GetCaster())
//				return;
//
//			Unit* caster = GetCaster();
//
//			if (!GetExplTargetUnit())
//				return;
//
//			Player* target = GetExplTargetUnit()->ToPlayer();
//
//			caster->CastSpell(target, WHIRLING_RED_VISUAL);
//
//			// Handle Trigger
//			Creature* Ts = caster->SummonCreature(WHIRLWIND_TRIGGER, caster->GetPositionX(), caster->GetPositionY(), caster->GetPositionZ(), caster->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN, 10000);
//
//			if (MotionMaster* motion = Ts->GetMotionMaster())
//				motion->MovePoint(1, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ());
//		}
//		void HandleOnHit()
//		{
//			if (!GetCaster())
//				return;
//
//			Unit* caster = GetCaster();
//
//			if (!GetHitUnit())
//				return;
//
//			Creature* target = GetHitUnit()->ToCreature();
//
//			target->CastSpell(target, WHIRLING_RED_VISUAL);
//
//			if (Creature* Ts = caster->FindNearestCreature(WHIRLWIND_TRIGGER, 50.0f, true))
//			if (MotionMaster* motion = Ts->GetMotionMaster())
//				motion->MovePoint(1, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ());
//		}
//		void Register()
//		{
//			OnCast += SpellCastFn(Whirlwind_Blade_SpellScript::HandleOnCast);
//			OnHit += SpellHitFn(Whirlwind_Blade_SpellScript::HandleOnHit);
//		}
//	};
//
//	SpellScript* GetSpellScript() const
//	{
//		return new Whirlwind_Blade_SpellScript();
//	}
//};
//
//class Whirlwind_Trigger_Class : public CreatureScript
//{
//public:
//	Whirlwind_Trigger_Class() : CreatureScript("Whirlwind_Trigger_Class") { }
//
//	struct Whirlwind_Trigger_ClassAI : public CreatureAI
//	{
//		Whirlwind_Trigger_ClassAI(Creature* creature) : CreatureAI(creature)
//		{
//			me->SetObjectScale(1.2f);
//			me->SetSpeed(MOVE_RUN, 2.0f, true);
//			me->SetReactState(REACT_PASSIVE);
//			me->AddUnitState(UNIT_STATE_CANNOT_AUTOATTACK);
//		}
//		uint32 amplitude;
//		void Reset()
//		{
//			me->setFaction(16);
//			me->AddAura(119939, me);
//
//			amplitude = 250;
//		}
//		void UpdateAI(uint32 const diff)
//		{
//			events.Update(diff);
//
//			std::list<Player*> PL_list;
//
//			JadeCore::AnyPlayerInObjectRangeCheck check(me, 1.4f);
//			JadeCore::PlayerListSearcher<JadeCore::AnyPlayerInObjectRangeCheck> searcher(me, PL_list, check);
//			me->VisitNearbyObject(1.4f, searcher);
//
//			for (std::list<Player*>::const_iterator it = PL_list.begin(); it != PL_list.end(); ++it)
//			{
//				if (!(*it))
//					return;
//
//				if (amplitude <= diff)
//				{
//					me->CastSpell((*it), WHIRLING_BLADE_DMG);
//					amplitude = 250; 
//				}
//				else
//					amplitude -= diff;
//			}
//		}
//	private:
//		EventMap events;
//		std::list<Player*> Player_List;
//	};
//
//	CreatureAI* GetAI(Creature* creature) const
//	{
//		return new Whirlwind_Trigger_ClassAI(creature);
//	}
//};
//// Wind Bomb
//class npc_wind_bomb : public CreatureScript
//{
//public:
//	npc_wind_bomb() : CreatureScript("npc_wind_bomb") { }
//
//	struct npc_wind_bombAI : public Scripted_NoMovementAI
//	{
//		npc_wind_bombAI(Creature* creature) : Scripted_NoMovementAI(creature)
//		{
//			me->SetObjectScale(1.0f);
//			me->SetSpeed(MOVE_RUN, 0.0f, true);
//		}
//		uint32 CanBombTimer;
//		int32 CanBomb;
//
//		void Reset()
//		{
//			CanBombTimer = 4000;
//			CanBomb = false;
//
//			me->setFaction(35);
//			me->AddAura(WIND_BOMB_VISUAL_AREA, me);
//		}
//		void UpdateAI(uint32 const diff)
//		{
//			events.Update(diff);
//
//			if (CanBombTimer <= diff && !CanBomb)
//			{
//				CanBomb = true;
//			}
//			else
//				CanBombTimer -= diff;
//
//			std::list<Player*> PL_list;
//
//			JadeCore::AnyPlayerInObjectRangeCheck check(me, 1.4f);
//			JadeCore::PlayerListSearcher<JadeCore::AnyPlayerInObjectRangeCheck> searcher(me, PL_list, check);
//			me->VisitNearbyObject(1.4f, searcher);
//
//			for (std::list<Player*>::const_iterator it = PL_list.begin(); it != PL_list.end(); ++it)
//			{
//				if (!(*it))
//					return;
//
//				if (CanBomb)
//				{
//					me->CastSpell((*it), WIND_BOMB_EXPLOSION);
//					me->DespawnOrUnsummon();
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
//		return new npc_wind_bombAI(creature);
//	}
//};
//class WeaponRack : public CreatureScript
//{
//public:
//	WeaponRack() : CreatureScript("WeaponRack") { }
//
//	bool OnGossipHello(Player* player, Creature* creature)
//	{
//        if (!player->HasAura(122220))
//        {
//            player->AddAura(122220, player);
//            creature->DespawnOrUnsummon();
//
//            return true;
//        }
//		return false;
//	}
//};
//// called by 122224
//class spell_throw_spear_remove_aura : public SpellScriptLoader
//{
//public:
//	spell_throw_spear_remove_aura() : SpellScriptLoader("spell_throw_spear_remove_aura") { }
//
//	class spell_throw_spear_remove_aura_spell_script : public SpellScript {
//
//		PrepareSpellScript(spell_throw_spear_remove_aura_spell_script);
//
//		void HandleAfterHit()
//		{
//			if (GetCaster())
//			{
//				if (GetHitUnit())
//				{
//					if (GetCaster()->HasAura(122220))
//					{
//						GetCaster()->RemoveAura(122220);
//					}
//				}
//			}
//		}
//
//		void Register()
//		{
//			OnHit += SpellHitFn(spell_throw_spear_remove_aura_spell_script::HandleAfterHit);
//		}
//	};
//
//	SpellScript* GetSpellScript() const
//	{
//		return new spell_throw_spear_remove_aura_spell_script();
//	}
//};
//void AddSC_lord_meljarak()
//{
//	// boss
//	new boss_lord_meljarak();
//
//	// adds
//	new npc_battle_mender();
//	new npc_trapper_sap();
//	new npc_blade_master();
//
//	// objects
//	new WeaponRack();
//
//	// Spells
//	new AMBER_PRISON_TRIGGER();
//	new spell_corrosive_resin();
//	new npc_paddle_amber();
//	new Whirlwind_Blade_Spell();
//	new Whirlwind_Trigger_Class();
//	new npc_wind_bomb();
//	new spell_throw_spear_remove_aura();
//}
