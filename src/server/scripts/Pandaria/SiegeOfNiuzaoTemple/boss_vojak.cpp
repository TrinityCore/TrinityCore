///*
//* Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
//* Copyright (C) 2012-2014 Danielx[Davethebrave]
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
//*
//* You should have received a copy of the GNU General Public License along
//* with this program. If not, see <http://www.gnu.org/licenses/>.
//*/
//
//
//#include "ScriptMgr.h"
//#include "ScriptedCreature.h"
//#include "siege_of_the_niuzoa_temple.h"
//#include "SpellScript.h"
//#include "SpellAuraEffects.h"
//#include "ScriptedGossip.h"
//#include "PassiveAI.h"
//#include "AchievementMgr.h"
//#include "ScriptedEscortAI.h"
//
//enum eSpells
//{
//	EVENT_WHIRLWHIND = 4432,
//	EVENT_COOLDOWN = 55503,
//	EVENT_HIT = 55504,
//	EVENT_RISING_SPEED = 55505,
//	EVENT_BOMBARD = 55506,
//};
//enum Achievements
//{
//	ACHIEVEMENT_WHERE_MY_AIR_SUPPORT = 6688,
//};
//
//enum eEvents
//{
//	EVENT_AMBER_WING_1 = 23231,
//	EVENT_AMBER_WING_2 = 23232,
//	EVENT_AMBER_WING_3 = 23234,
//	CANCEL_AMBER_WING = 23233,
//
//	EVENT_COOLDOWN_Trigger = 114,
//	EVENT_HIT_Trigger = 112,
//};
//
//enum Pre_Fight_Events
//{
//	EVENT_PRE_CINEMATIC = 1,
//	EVENT_1_CINEMATIC = 2,
//	EVENT_2_CINEMATIC = 3,
//	EVENT_3_CINEMATIC = 4,
//	EVENT_4_CINEMATIC = 5,
//	EVENT_5_CINEMATIC = 6,
//	EVENT_6_CINEMATIC = 7,
//	EVENT_7_CINEMATIC = 8,
//	EVENT_8_CINEMATIC = 9,
//	EVENT_9_CINEMATIC = 10,
//	EVENT_10_CINEMATIC = 11,
//	EVENT_11_CINEMATIC = 12,
//	EVENT_12_CINEMATIC = 13,
//	EVENT_13_CINEMATIC = 14,
//	EVENT_14_CINEMATIC = 15,
//	EVENT_15_CINEMATIC = 16,
//	EVENT_16_CINEMATIC = 17,
//	EVENT_17_CINEMATIC = 18,
//	EVENT_18_CINEMATIC = 19,
//	EVENT_19_CINEMATIC = 20,
//	EVENT_GONG = 9223,
//	EVENT_CONTINUE = 9555,
//	EVENT_CONTINUE_1 = 9556,
//};
//enum Fight_Events
//{
//	LICHUANDLOCHU = 34343,
//	PHASE_1 = 96,
//	PHASE_2 = 97,
//	PHASE_3 = 98,
//	PHASE_4 = 99,
//	PHASE_5 = 100,
//};
//enum Movements
//{
//	EVENT_MOVE = 470,
//	EVENT_MOVE_1 = 471,
//	EVENT_MOVE_2 = 472,
//	EVENT_MOVE_3 = 473,
//	EVENT_MOVE_4 = 474,
//	EVENT_MOVE_5 = 475,
//	EVENT_MOVE_6 = 476,
//	EVENT_MOVE_7 = 477,
//	EVENT_MOVE_8 = 478,
//	EVENT_MOVE_9 = 479,
//};
//
//class Yang_Ironclaw : public CreatureScript // npc_tut_ai - Class constructor, name this anything that doesn't conflict with another name
//{
//public:
//	Yang_Ironclaw() : CreatureScript("Yang_Ironclaw") { } // npc_tut_ai, should be the same as class npc_tut_ai -- CreatureScript("npc_tut_ai") - This is your 'ScriptName' that you will assign in your database
//
//	bool OnGossipHello(Player* player, Creature* creature)
//	{
//		if (Yang_IronClaw_AI* linkAI = CAST_AI(Yang_IronClaw_AI, creature->GetAI()))
//		{
//			if (!linkAI->stopgossip)
//			{
//				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "We're ready to defend!", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
//				player->PlayerTalkClass->SendGossipMenu(9443435, creature->GetGUID());
//				return true;
//			}
//		}
//		return false;
//	}
//	bool OnGossipSelect(Player * player, Creature * creature, uint32 sender, uint32 actions)
//	{
//		player->PlayerTalkClass->ClearMenus();
//		if (sender != GOSSIP_SENDER_MAIN)
//			return false;
//
//		if (actions == GOSSIP_ACTION_INFO_DEF + 1)
//		{
//			if (Yang_IronClaw_AI* linkAI = CAST_AI(Yang_IronClaw_AI, creature->GetAI()))
//			{
//				linkAI->bossencounterstarted = true;
//			}
//		}
//		return true;
//	}
//	struct Yang_IronClaw_AI : public ScriptedAI
//	{
//		Yang_IronClaw_AI(Creature* creature) : ScriptedAI(creature)
//		{
//			me->AddUnitState(UNIT_STATE_CANNOT_AUTOATTACK);
//		}
//		bool bossencounterstarted;
//		bool hasstarted;
//		int32 Health = 0;
//
//		std::list<Creature*> Wave_List_1;
//		std::list<Creature*> Wave_List_2;
//		std::list<Creature*> Wave_List_3;
//
//		// Check up lists
//		std::list<Creature*> CHECK;
//		std::list<Creature*> CHECK2;
//		std::list<Creature*> CHECK3;
//
//		std::list<Player*> PL_LIST;
//		// Phases triggers
//		bool phase_1;
//		bool phase_2;
//		bool phase_3;
//		bool phase_4;
//		bool pregong;
//		bool hasgong;
//		bool bosscandespawn;
//		bool bosscansummon;
//		bool stopgossip;
//		bool canwipe;
//		bool haswipe;
//		bool stopcontinue;
//		bool achievementamberweaver;
//		bool achivemenetbosskilled;
//		void Reset()
//		{
//			stopgossip = true;
//			bosscandespawn = false;
//			events.Reset();
//			hasstarted = true;
//			bosscansummon = false;
//			phase_1 = false;
//			phase_2 = false;
//			phase_3 = false;
//			phase_4 = false;
//			hasgong = false;
//			canwipe = false;
//			haswipe = true;
//			bossencounterstarted = false;
//			stopcontinue = false;
//			achievementamberweaver = false;
//			achivemenetbosskilled = false;
//		}
//		void Re_Reset()
//		{
//			stopgossip = true;
//			events.Reset();
//			hasstarted = false;
//			phase_1 = false;
//			phase_2 = false;
//			phase_3 = false;
//			phase_4 = false;
//			hasgong = false;
//			bossencounterstarted = false;
//			canwipe = true;
//			//haswipe = true;
//			achivemenetbosskilled = false;
//			achievementamberweaver = false;
//
//			if (MotionMaster* motion = me->GetMotionMaster())
//			{
//				motion->MovePoint(1, 1524.619995f, 5301.770020f, 184.649002f);
//			}
//			if (Creature* Lo_Chu = me->FindNearestCreature(62794, 100.0f, true))
//			{
//				Lo_Chu->DespawnOrUnsummon();
//				me->SummonCreature(62794, 1519.511230f, 5304.276367f, 184.649261f, 1.169800f);
//			}
//			if (Creature* Li_Chu = me->FindNearestCreature(61812, 100.0f, true))
//			{
//				Li_Chu->DespawnOrUnsummon();
//				me->SummonCreature(61812, 1529.413086f, 5305.459961f, 184.649261f, 2.321194f);
//			}
//
//		}
//		void DespawnMinions()
//		{
//			me->DespawnCreaturesInArea(62794);
//			me->DespawnCreaturesInArea(61812);
//			me->DespawnCreaturesInArea(948342);
//			me->DespawnCreaturesInArea(61701);
//			me->DespawnCreaturesInArea(987846);
//			me->DespawnCreaturesInArea(987845);
//			me->DespawnCreaturesInArea(61670);
//			me->DespawnCreaturesInArea(63106);
//			me->DespawnCreaturesInArea(99923);
//			me->DespawnCreaturesInArea(61817);
//		}
//        void Event_LastPhase()
//        {
//            stopcontinue = true;
//            stopgossip = true;
//            DespawnMinions();
//            me->DespawnCreaturesInArea(61634);
//        }
//		void UpdateAI(uint32 const diff)
//		{
//			events.Update(diff);
//
//			if (!haswipe)
//			{
//				Map::PlayerList const& players = me->GetMap()->GetPlayers();
//				if (players.isEmpty())
//				{
//					if (Creature* Boss = me->FindNearestCreature(61634, 400.0f, true))
//					{
//						Boss->DespawnOrUnsummon(50);
//						DespawnMinions();
//					}
//					events.Reset();
//					Re_Reset();
//				}
//
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
//									if (Creature* Boss = me->FindNearestCreature(61634, 400.0f, true))
//									{
//										Boss->DespawnOrUnsummon(50);
//										DespawnMinions();
//									}
//									events.Reset();
//									Re_Reset();
//                                    Event_LastPhase();
//								}
//							}
//						}
//					}
//				}
//			}
//			// Pre Cinematic after they kill the Sikthik Warden
//			if (!hasstarted)
//			{
//				hasstarted = true;
//				// BOSS
//				me->SummonCreature(61634, 1508.458252f, 5399.667969f, 139.173431f, 4.744346f);
//				events.ScheduleEvent(EVENT_PRE_CINEMATIC, 2000);
//			}
//			// If player has gossiped with the npc to start the encounter
//			if (bossencounterstarted)
//			{
//				if (!me->FindNearestCreature(61634, 200.0f, true))
//				{
//					me->SummonCreature(61634, 1508.458252f, 5399.667969f, 139.173431f, 4.744346f);
//				}
//
//				if (!me->FindNearestCreature(62794, 100.0f, true))
//				{
//					me->SummonCreature(62794, 1519.511230f, 5304.276367f, 184.649261f, 1.169800f);
//				}
//				if (!me->FindNearestCreature(61812, 100.0f, true))
//				{
//					me->SummonCreature(61812, 1529.413086f, 5305.459961f, 184.649261f, 2.321194f);
//				}
//				canwipe = false;
//				bossencounterstarted = false;
//				haswipe = false;
//
//
//				events.CancelEvent(EVENT_PRE_CINEMATIC);
//				events.CancelEvent(EVENT_1_CINEMATIC);
//				events.CancelEvent(EVENT_2_CINEMATIC);
//				events.CancelEvent(EVENT_3_CINEMATIC);
//
//
//				stopgossip = true;
//				events.ScheduleEvent(EVENT_4_CINEMATIC, 1000);
//			}
//
//			// GONG SKIPPERS
//			if (phase_1 && hasgong)
//			{
//				pregong = false;
//				hasgong = false;
//				phase_1 = false;
//				phase_2 = true;
//				events.CancelEvent(EVENT_10_CINEMATIC);
//				events.ScheduleEvent(EVENT_10_CINEMATIC, 1000);
//			}
//			if (phase_2 && hasgong)
//			{
//				pregong = false;
//				hasgong = false;
//				phase_2 = false;
//				phase_3 = true;
//				events.CancelEvent(EVENT_AMBER_WING_1);
//				events.CancelEvent(EVENT_12_CINEMATIC);
//				events.ScheduleEvent(EVENT_12_CINEMATIC, 1000);
//			}
//			if (phase_3 && hasgong)
//			{
//				pregong = false;
//				hasgong = false;
//				phase_3 = false;
//				phase_4 = true;
//				events.CancelEvent(EVENT_AMBER_WING_2);
//				events.CancelEvent(EVENT_14_CINEMATIC);
//				events.ScheduleEvent(EVENT_14_CINEMATIC, 1000);
//			}
//			if (phase_4 && hasgong)
//			{
//				pregong = false;
//				hasgong = false;
//				phase_4 = false;
//				events.CancelEvent(EVENT_AMBER_WING_2);
//				events.CancelEvent(EVENT_15_CINEMATIC);
//				events.ScheduleEvent(EVENT_15_CINEMATIC, 1000);
//			}
//			if (stopcontinue)
//			{
//				stopcontinue = false;
//				events.ScheduleEvent(EVENT_CONTINUE, 6000);
//			}
//
//			// Introduction Switch
//			while (uint32 eventId = events.ExecuteEvent())
//			{
//				switch (eventId)
//				{
//				case EVENT_PRE_CINEMATIC:
//				{
//					if (MotionMaster* motion = me->GetMotionMaster())
//					{
//						me->SetSpeed(MOVE_RUN, 0.9f, true);
//						motion->MovePoint(1, 1524.285767f, 5309.688965f, 185.227280f);
//
//						me->MonsterSay("Thanks for the save, but we're still stuck in the middle of the entire mantid army.", LANG_UNIVERSAL, me->GetGUID());
//					}
//					DoPlaySoundToSet(me, 31505);
//					events.ScheduleEvent(EVENT_1_CINEMATIC, 6000);
//					break;
//				}
//				case EVENT_1_CINEMATIC:
//				{
//					DoPlaySoundToSet(me, 31506);
//
//					// summon all
//
//					/*
//					Summon all EN EMY UNITS
//					*/
//					// SWARMERS addon
//					me->SummonCreature(99923, 1505.609009f, 5383.343262f, 139.830872f, 4.744346f);
//					me->SummonCreature(99923, 1513.676636f, 5384.251465f, 138.875488f, 4.744346f);
//					me->SummonCreature(99923, 1512.662598f, 5393.255859f, 138.950760f, 4.744346f);
//					me->SummonCreature(99923, 1504.489258f, 5392.335449f, 138.621674f, 4.744346f);
//					// SWARMER LEFT SIDE 63106
//					me->SummonCreature(63106, 1521.650024f, 5380.474609f, 138.943695f, 4.744346f);
//					me->SummonCreature(63106, 1524.483521f, 4380.564941f, 139.551987f, 4.744346f);
//					me->SummonCreature(63106, 1526.496826f, 5380.629395f, 139.816940f, 4.744346f);
//					// SWARMERS RIGHT SIDE 99923
//					me->SummonCreature(63106, 1502.348389f, 5378.777832f, 139.205261f, 4.744346f);
//					me->SummonCreature(63106, 1500.457397f, 5378.555664f, 139.395630f, 4.744346f);
//					me->SummonCreature(63106, 1497.360718f, 5378.192871f, 139.438049f, 4.744346f);
//					// Demolisher front right 61670
//					me->SummonCreature(61670, 1519.408203f, 5386.154785f, 138.803680f, 4.744346f);
//					me->SummonCreature(61670, 1521.191528f, 5386.147461f, 138.900421f, 4.744346f);
//					me->SummonCreature(61670, 1522.940674f, 5386.202637f, 139.343979f, 4.744346f);
//					me->SummonCreature(61670, 1524.514893f, 5386.252441f, 139.652985f, 4.744346f);
//					me->SummonCreature(61670, 1526.054199f, 5386.300781f, 139.818649f, 4.744346f);
//					// Demlolisher front left  987845
//					me->SummonCreature(987845, 1499.368042f, 5390.716309f, 139.014114f, 4.744346f);
//					me->SummonCreature(987845, 1497.407349f, 5390.347656f, 139.148529f, 4.744346f);
//					me->SummonCreature(987845, 1496.086426f, 5390.099121f, 139.227585f, 4.744346f);
//					me->SummonCreature(987845, 1494.648560f, 5389.828613f, 139.285980f, 4.744346f);
//					me->SummonCreature(987845, 1493.183228f, 5389.553223f, 139.335617f, 4.744346f);
//					// Demolisher back right 987846
//					me->SummonCreature(987846, 1526.659790f, 5391.655762f, 139.160721f, 4.744346f);
//					me->SummonCreature(987846, 1524.353882f, 5391.764160f, 139.057434f, 4.744346f);
//					me->SummonCreature(987846, 1523.144287f, 5391.706543f, 139.016602f, 4.744346f);
//					me->SummonCreature(987846, 1521.650991f, 5391.634766f, 138.966965f, 4.744346f);
//					me->SummonCreature(987846, 1520.172607f, 5391.564941f, 138.936417f, 4.744346f);
//					// Demolisher back left 987847
//					me->SummonCreature(987846, 1494.289917f, 5384.093262f, 139.438339f, 4.744346f);
//					me->SummonCreature(987846, 1495.322266f, 5384.005859f, 139.438339f, 4.744346f);
//					me->SummonCreature(987846, 1497.114868f, 5383.854492f, 139.430847f, 4.744346f);
//					me->SummonCreature(987846, 1498.726074f, 5383.718262f, 139.425964f, 4.744346f);
//					me->SummonCreature(987846, 1500.365234f, 5383.579590f, 139.374344f, 4.744346f);
//					// Warrior Right 61701
//					me->SummonCreature(61701, 1497.903442f, 5400.875977f, 140.859985f, 4.744346f);
//					// Warrior Left 948342
//					me->SummonCreature(948342, 1517.220581f, 5400.403809f, 139.456451f, 4.744346f);
//
//					me->MonsterSay("look out there. Too many for us to take head on.", LANG_UNIVERSAL, me->GetGUID());
//					me->PlayOneShotAnimKit(25);
//
//					stopgossip = false;
//					bosscansummon = true;
//					events.ScheduleEvent(EVENT_2_CINEMATIC, 9000);
//					break;
//				}
//				case EVENT_2_CINEMATIC:
//				{
//					me->MonsterSay("Hmmm.. I have a crazy idea that just might work. but we'll need your help heroes!", LANG_UNIVERSAL, me->GetGUID());
//					DoPlaySoundToSet(me, 31507);
//
//				}
//					events.ScheduleEvent(EVENT_3_CINEMATIC, 9000);
//					break;
//				case EVENT_3_CINEMATIC:
//				{
//					me->MonsterSay("lets give these mantids a taste of their on medicine!", LANG_UNIVERSAL, me->GetGUID());
//					DoPlaySoundToSet(me, 31508);
//				}
//					break;
//					// AFTER GOSSIP
//				case EVENT_4_CINEMATIC:
//				{
//					DoPlaySoundToSet(me, 31509);
//
//					events.ScheduleEvent(LICHUANDLOCHU, 1000);
//
//					me->MonsterSay("Li and Lo, get the sap into position", LANG_UNIVERSAL, me->GetGUID());
//				}
//					events.ScheduleEvent(EVENT_5_CINEMATIC, 4000);
//					break;
//				case EVENT_5_CINEMATIC:
//				{
//					DoPlaySoundToSet(me, 31510);
//					me->MonsterSay("Let's get this party started.. Shall we?", LANG_UNIVERSAL, me->GetGUID());
//				}
//					events.ScheduleEvent(EVENT_6_CINEMATIC, 7000);
//					break;
//				case EVENT_6_CINEMATIC:
//				{
//
//					DoPlaySoundToSet(me, 31513);
//
//					if (MotionMaster* motion = me->GetMotionMaster())
//					{
//						motion->MovePoint(2, 1550.537354f, 5313.797852f, 184.648605f);
//						me->setFaction(35);
//					}
//					me->MonsterYell("Bring it uglies!", LANG_UNIVERSAL, me->GetGUID());
//					phase_1 = true;
//					events.ScheduleEvent(PHASE_1, 20000);
//					pregong = false;
//
//					events.ScheduleEvent(EVENT_7_CINEMATIC, 5000);
//				}
//					break;
//				case EVENT_7_CINEMATIC:
//				{
//					DoPlaySoundToSet(me, 30264);
//
//					if (Creature* Boss = me->FindNearestCreature(61634, 200.0f, true))
//					{
//						Boss->MonsterYell("Fools.. Attacking the might of the mantid head on? Your death will be swift.", LANG_UNIVERSAL, Boss->GetGUID());
//						events.ScheduleEvent(EVENT_8_CINEMATIC, 11000);
//					}
//				}
//					break;
//				case EVENT_8_CINEMATIC:
//				{
//					DoPlaySoundToSet(me, 30265);
//
//					if (Creature* Boss = me->FindNearestCreature(61634, 200.0f, true))
//					{
//						events.ScheduleEvent(EVENT_AMBER_WING_1, 12000);
//						Boss->MonsterYell("Swarmers, attack! Tear their flash from their bones.", LANG_UNIVERSAL, Boss->GetGUID());
//						Boss->MonsterTextEmote("A wave of Sik'thik Swarmers joins the battle.", Boss->GetGUID(), true);
//					}
//					events.ScheduleEvent(EVENT_9_CINEMATIC, 8000);
//
//				}
//					break;
//				case EVENT_9_CINEMATIC:
//					DoPlaySoundToSet(me, 31511);
//
//					me->MonsterSay("Swarmers are coming up the ramp -- use the sap the slow them down!", LANG_UNIVERSAL, me->GetGUID());
//					events.ScheduleEvent(EVENT_10_CINEMATIC, 80000);
//					events.CancelEvent(EVENT_GONG);
//					events.ScheduleEvent(EVENT_GONG, 40000);
//					break;
//				case EVENT_10_CINEMATIC:
//					if (Creature* Boss = me->FindNearestCreature(61634, 200.0f, true))
//					{
//						DoPlaySoundToSet(me, 30266);
//
//
//						Boss->MonsterYell("Demolishers, get in there! Leave nothing but a pile of ash!", LANG_UNIVERSAL, Boss->GetGUID());
//						me->MonsterTextEmote("A wave of Sik'thik Demolishers joins the battle.", me->GetGUID(), true);
//						events.ScheduleEvent(PHASE_2, 5000);
//						if (!achievementamberweaver)
//						{
//							events.ScheduleEvent(EVENT_AMBER_WING_2, 10000);
//						}
//
//						phase_1 = false;
//						if (!hasgong)
//							phase_2 = true;
//					}
//					events.ScheduleEvent(EVENT_11_CINEMATIC, 7000);
//					break;
//				case EVENT_11_CINEMATIC:
//					DoPlaySoundToSet(me, 31504);
//
//
//
//					me->MonsterSay("Demolishers are carrying explosives! Any direct hit will blow them up!", LANG_UNIVERSAL, me->GetGUID());
//					events.ScheduleEvent(EVENT_12_CINEMATIC, 70000);
//					pregong = false;
//					events.CancelEvent(EVENT_GONG);
//					events.ScheduleEvent(EVENT_GONG, 40000);
//					break;
//				case EVENT_12_CINEMATIC:
//					if (Creature* Boss = me->FindNearestCreature(61634, 200.0f, true))
//					{
//						DoPlaySoundToSet(me, 30267);
//
//
//						Boss->MonsterYell("Warriors, trample these weaklings. Crush them!", LANG_UNIVERSAL, Boss->GetGUID());
//						me->MonsterTextEmote("A wave of Sik'thik Warrior joins the battle.", me->GetGUID(), true);
//						events.ScheduleEvent(PHASE_3, 5000);
//
//						pregong = false;
//						phase_2 = false;
//						if (!hasgong)
//						{
//							phase_3 = true;
//						}
//						events.ScheduleEvent(EVENT_13_CINEMATIC, 6000);
//					}
//					break;
//				case EVENT_13_CINEMATIC:
//					DoPlaySoundToSet(me, 31512);
//					events.CancelEvent(EVENT_AMBER_WING_2);
//					if (!achievementamberweaver)
//					{
//						events.ScheduleEvent(EVENT_AMBER_WING_3, 5000);
//					}
//					me->MonsterSay("Warrior coming in! Focus your fire!", LANG_UNIVERSAL, me->GetGUID());
//					events.ScheduleEvent(EVENT_14_CINEMATIC, 90000);
//					events.ScheduleEvent(EVENT_GONG, 40000);
//					break;
//				case EVENT_14_CINEMATIC:
//					if (Creature* Boss = me->FindNearestCreature(61634, 200.0f, true))
//					{
//						DoPlaySoundToSet(me, 30268);
//						Boss->MonsterYell("Everyone! Send everything! Slaughter these cowards, they are making us look like fools!", LANG_UNIVERSAL, Boss->GetGUID());
//						me->MonsterTextEmote("A wave of Sik'thik Demolishers and a Sik'thik Warrior joins the battle.", me->GetGUID(), true);
//						events.ScheduleEvent(PHASE_4, 5000);
//						pregong = false;
//						phase_3 = false;
//						if (!hasgong)
//						{
//							phase_4 = true;
//						}
//
//						events.ScheduleEvent(EVENT_15_CINEMATIC, 80000);
//						events.CancelEvent(EVENT_GONG);
//						events.ScheduleEvent(EVENT_GONG, 32000);
//					}
//					break;
//				case EVENT_15_CINEMATIC:
//					if (Creature* Boss = me->FindNearestCreature(61634, 200.0f, true))
//					{
//						DoPlaySoundToSet(me, 30262);
//						Boss->MonsterYell("Pah! Those who failed deserves to die; you have merely culled the weak!", LANG_UNIVERSAL, Boss->GetGUID());
//						events.ScheduleEvent(EVENT_16_CINEMATIC, 6000);
//					}
//					break;
//				case EVENT_16_CINEMATIC:
//					if (Creature* Boss = me->FindNearestCreature(61634, 200.0f, true))
//					{
//						DoPlaySoundToSet(me, 30263);
//						Boss->MonsterYell("I must finish it myself, then. So be it!", LANG_UNIVERSAL, Boss->GetGUID());
//						me->MonsterTextEmote("Commander Vojak begins to approach the platform.", me->GetGUID(), true);
//						events.ScheduleEvent(PHASE_5, 6000);
//					}
//					break;
//
//				case LICHUANDLOCHU:
//				{
//					if (Creature* Li_Chu = me->FindNearestCreature(61812, 100.0f, true))
//					{
//						Li_Chu->setFaction(35);
//					}
//					if (Creature* Lo_Chu = me->FindNearestCreature(62794, 100.0f, true))
//					{
//						Lo_Chu->setFaction(35);
//					}
//				}
//					break;
//				case EVENT_GONG:
//					pregong = true;
//					break;
//				case PHASE_1:
//                    Wave_List_1.clear();
//
//					GetCreatureListWithEntryInGrid(Wave_List_1, me, 63106, 200.0f);
//
//					if (Wave_List_1.empty())
//						return;
//
//					for (std::list<Creature*>::const_iterator it = Wave_List_1.begin(); it != Wave_List_1.end(); ++it)
//					{
//						if (!(*it))
//							return;
//						// Object scales triggers
//                        if ((*it) && (*it)->IsInWorld() && (*it)->getFaction() == 35)
//							(*it)->setFaction(16);
//					}
//					break;
//				case PHASE_2:
//                    Wave_List_2.clear();
//                    Wave_List_3.clear();
//
//					GetCreatureListWithEntryInGrid(Wave_List_2, me, 61670, 200.0f);
//                    GetCreatureListWithEntryInGrid(Wave_List_3, me, 987845, 200.0f);
//
//					if (Wave_List_2.empty())
//						return;
//
//                    if (Wave_List_3.empty())
//                        return;
//
//                    for (std::list<Creature*>::const_iterator it = Wave_List_2.begin(); it != Wave_List_2.end(); ++it)
//                    {
//                        if (!(*it))
//                            return;
//
//                        // Object scales triggers
//                        if ((*it) && (*it)->IsInWorld() && (*it)->getFaction() == 35)
//                            (*it)->setFaction(16);
//                        pregong = true;
//                    }
//
//					for (std::list<Creature*>::const_iterator it = Wave_List_3.begin(); it != Wave_List_3.end(); ++it)
//					{
//						if (!(*it))
//							return;
//						// Object scales triggers
//                        if ((*it) && (*it)->IsInWorld())
//						(*it)->setFaction(16);
//						// boss fight no gong
//					}
//					break;
//				case PHASE_3:
//                    Wave_List_2.clear();
//                    Wave_List_3.clear();
//
//					GetCreatureListWithEntryInGrid(Wave_List_2, me, 61701, 200.0f);
//
//
//					if (Wave_List_2.empty())
//						return;
//
//					for (std::list<Creature*>::const_iterator it = Wave_List_2.begin(); it != Wave_List_2.end(); ++it)
//					{
//						if (!(*it))
//							return;
//						if ((*it) && (*it)->IsInWorld() && (*it)->getFaction() == 35)
//							// Object scales triggers
//							(*it)->setFaction(16);
//					}
//
//					GetCreatureListWithEntryInGrid(Wave_List_3, me, 99923, 200.0f);
//
//					if (Wave_List_3.empty())
//						return;
//
//					for (std::list<Creature*>::const_iterator it = Wave_List_3.begin(); it != Wave_List_3.end(); ++it)
//					{
//						if (!(*it))
//							return;
//                        if ((*it) && (*it)->IsInWorld() && (*it)->getFaction() == 35)
//							(*it)->setFaction(16);
//						// boss fight no gong
//					}
//					break;
//                case PHASE_4:
//                    Wave_List_1.clear();
//                    Wave_List_2.clear();
//
//					GetCreatureListWithEntryInGrid(Wave_List_1, me, 948342, 200.0f);
//
//
//					if (Wave_List_1.empty())
//						return;
//
//					for (std::list<Creature*>::const_iterator it = Wave_List_1.begin(); it != Wave_List_1.end(); ++it)
//					{
//						if (!(*it))
//							return;
//                        if ((*it) && (*it)->IsInWorld() && (*it)->getFaction() == 35)
//							// Object scales triggers
//							(*it)->setFaction(16);
//					}
//
//					GetCreatureListWithEntryInGrid(Wave_List_2, me, 987846, 200.0f);
//
//					if (Wave_List_2.empty())
//						return;
//
//
//					for (std::list<Creature*>::const_iterator it = Wave_List_2.begin(); it != Wave_List_2.end(); ++it)
//					{
//						if (!(*it))
//							return;
//						if ((*it) && (*it)->IsInWorld() && (*it)->getFaction() == 35)
//							// Object scales triggers
//							(*it)->setFaction(16);
//					}
//
//					GetCreatureListWithEntryInGrid(Wave_List_3, me, 987847, 200.0f);
//
//					if (Wave_List_3.empty())
//						return;
//
//					for (std::list<Creature*>::const_iterator it = Wave_List_3.begin(); it != Wave_List_3.end(); ++it)
//					{
//						if (!(*it))
//							return;
//						if ((*it)->getFaction() == 35)
//							// Object scales triggers
//							(*it)->setFaction(16);
//						// boss fight no gong
//					}
//					break;
//				case PHASE_5:
//                    Wave_List_1.clear();
//
//					GetCreatureListWithEntryInGrid(Wave_List_1, me, 61634, 200.0f);
//
//					if (Wave_List_1.empty())
//						return;
//
//
//					for (std::list<Creature*>::const_iterator it = Wave_List_1.begin(); it != Wave_List_1.end(); ++it)
//					{
//						if (!(*it))
//							return;
//						if ((*it) && (*it)->IsInWorld() && (*it)->getFaction() == 35)
//							// Object scales triggers
//							(*it)->setFaction(16);
//					}
//					break;
//				case EVENT_CONTINUE:
//				{
//					if (MotionMaster* motion = me->GetMotionMaster())
//					{
//						motion->MovePoint(4, 1531.403442f, 5307.058594f, 184.649780f);
//						DoPlaySoundToSet(me, 31497);
//						me->MonsterSay("Well.. that was fun! wasn't it?", LANG_UNIVERSAL, me->GetGUID());
//						events.ScheduleEvent(EVENT_CONTINUE_1, 6000);
//					}
//				}
//					break;
//				case EVENT_CONTINUE_1:
//				{
//					if (MotionMaster* motion = me->GetMotionMaster())
//					{
//						DoPlaySoundToSet(me, 31498);
//						me->DespawnCreaturesInArea(61817);
//						me->MonsterSay("Li and Lo.. go look after our friends down below", LANG_UNIVERSAL, me->GetGUID());
//						me->SetPhaseMask(7, true);
//
//						if (Creature* Lo_Chu = me->FindNearestCreature(62794, 100.0f, true))
//						{
//							Lo_Chu->SetPhaseMask(7, true);
//						}
//						if (Creature* Li_Chu = me->FindNearestCreature(61812, 100.0f, true))
//						{
//							Li_Chu->SetPhaseMask(7, true);
//						}
//						// summon new yang
//						me->SummonCreature(654757, 1535.496704f, 5378.242188f, 140.046753f);
//					}
//				}
//					break;
//				case EVENT_AMBER_WING_1:
//				{
//					if (Creature* Boss = me->FindNearestCreature(61634, 200.0f, true))
//					{
//						DoPlaySoundToSet(me, 30269);
//						Boss->MonsterYell("Carpet bomb the platform! Send in the Amberwing!", LANG_UNIVERSAL, me->GetGUID());
//						me->MonsterTextEmote("The Sik'thik Amberwing moves int position to bombard the platform", me->GetGUID(), true);
//
//						if (!me->FindNearestCreature(324252, 200.0f, true))
//						{
//							me->SummonCreature(324252, 1528.270020f, 5313.854980f, 199.096436f, 4.720955f);
//							events.ScheduleEvent(CANCEL_AMBER_WING, 30000);
//
//						}
//					}
//					break;
//				}
//				case CANCEL_AMBER_WING:
//				{
//					if (Creature* amberwing = me->FindNearestCreature(324252, 200.0f, true))
//					{
//
//						Health = amberwing->GetHealth();
//						me->MonsterTextEmote("The Sik'thik Amberwing runs out of ammunition and flies away", me->GetGUID(), true);
//						amberwing->DespawnOrUnsummon(1000);
//					}
//					break;
//				}
//				case EVENT_AMBER_WING_2:
//				{
//					if (Creature* Boss = me->FindNearestCreature(61634, 200.0f, true))
//					{
//						DoPlaySoundToSet(me, 30270);
//						Creature* amberwing = me->SummonCreature(324252, 1528.270020f, 5313.854980f, 199.096436f, 4.720955f);
//						amberwing->SetHealth(Health);
//						Boss->MonsterYell("They are holding us off, bring in the air support", LANG_UNIVERSAL, me->GetGUID());
//						me->MonsterTextEmote("The Sik'thik Amberwing moves int position to bombard the platform", me->GetGUID(), true);
//						events.ScheduleEvent(CANCEL_AMBER_WING, 30000);
//					}
//				}
//					break;
//				case EVENT_AMBER_WING_3:
//				{
//					if (Creature* Boss = me->FindNearestCreature(61634, 200.0f, true))
//					{
//						DoPlaySoundToSet(me, 30271);
//						Creature* amberwing = me->SummonCreature(324252, 1528.270020f, 5313.854980f, 199.096436f, 4.720955f);
//						amberwing->SetHealth(Health);
//						Boss->MonsterYell("Amberwing get in there!", LANG_UNIVERSAL, me->GetGUID());
//						me->MonsterTextEmote("The Sik'thik Amberwing moves int position to bombard the platform", me->GetGUID(), true);
//						events.ScheduleEvent(CANCEL_AMBER_WING, 30000);
//					}
//				}
//					break;
//				}
//			}
//
//
//		}
//	private:
//		EventMap events;
//	};
//
//	CreatureAI* GetAI(Creature* creature) const
//	{
//		return new Yang_IronClaw_AI(creature);
//	}
//};
//class Trash : public CreatureScript // npc_tut_ai - Class constructor, name this anything that doesn't conflict with another name
//{
//public:
//	Trash() : CreatureScript("Trash") { } // npc_tut_ai, should be the same as class npc_tut_ai -- CreatureScript("npc_tut_ai") - This is your 'ScriptName' that you will assign in your database
//
//	struct Yang_IronClaw_AI : public ScriptedAI
//	{
//		Yang_IronClaw_AI(Creature* creature) : ScriptedAI(creature)
//		{
//			int32 random_movement = urand(1, 4);
//			float speed = 0;
//			switch (random_movement)
//			{
//			case 1:
//				speed = 1.0f;
//				break;
//			case 2:
//				speed = 1.5f;
//				break;
//			case 3:
//				speed = 1.2f;
//				break;
//			case 4:
//				speed = 1.4f;
//				break;
//			}
//			me->SetSpeed(MOVE_RUN, speed, true);
//		}
//		bool bossencounterstarted;
//		bool hasstarted;
//		bool move;
//		uint32 damage_taken = 0;
//		void Reset()
//		{
//			move = true;
//			hasstarted = true;
//			me->setFaction(35);
//			me->SetReactState(REACT_PASSIVE);
//
//			// demolishers
//			if (me->GetEntry() == 61670 || me->GetEntry() == 987845 || me->GetEntry() == 987846 || me->GetEntry() == 987847)
//			{
//				me->AddAura(121986, me);
//			}
//
//			// hack fix to the ramp, it's the only possible hack really.
//			me->SetHealth(me->GetMaxHealth() - damage_taken);
//		}
//		void DamageTaken(Unit* /*attacker*/, uint32& damage)
//		{
//			damage_taken = damage_taken + damage;
//		}
//		void MovementInform(uint32 /*type*/, uint32 id)
//		{
//			if (id == 0)
//			{
//				if (move)
//				{
//					move = false;
//					events.ScheduleEvent(EVENT_MOVE, 1000);
//				}
//			}
//			if (id == 1)
//			{
//				if (move)
//				{
//					move = false;
//					events.ScheduleEvent(EVENT_MOVE_1, 1000);
//				}
//			}
//			if (id == 2)
//			{
//				if (move)
//				{
//					move = false;
//					events.ScheduleEvent(EVENT_MOVE_2, 1000);
//				}
//
//			}
//			if (id == 3)
//			{
//				if (move)
//				{
//					move = false;
//					events.ScheduleEvent(EVENT_MOVE_3, 1000);
//				}
//			}
//			if (id == 4)
//			{
//				if (move)
//				{
//					move = false;
//					events.ScheduleEvent(EVENT_MOVE_4, 1000);
//				}
//			}
//			if (id == 5)
//			{
//				if (move)
//				{
//					move = false;
//					events.ScheduleEvent(EVENT_MOVE_5, 1000);
//				}
//			}
//			if (id == 6)
//			{
//				if (move)
//				{
//					move = false;
//					events.ScheduleEvent(EVENT_MOVE_6, 1000);
//				}
//			}
//			if (id == 7)
//			{
//				if (move)
//				{
//					move = false;
//					events.ScheduleEvent(EVENT_MOVE_7, 1000);
//				}
//			}
//		}
//		void UpdateAI(uint32 const diff)
//		{
//			events.Update(diff);
//
//			if (me->getFaction() == 16 && hasstarted)
//			{
//				hasstarted = false;
//				events.ScheduleEvent(EVENT_MOVE, 1000);
//			}
//			if (!move)
//			{
//				me->AttackStop();
//			}
//			if (me->SelectNearestPlayer(4.0f))
//			{
//				me->SetReactState(REACT_AGGRESSIVE);
//			}
//			// Phase Switch Switch
//			while (uint32 eventId = events.ExecuteEvent())
//			{
//				switch (eventId)
//				{
//				case EVENT_MOVE:
//					if (MotionMaster* motion = me->GetMotionMaster())
//					{
//						motion->MovePoint(1, 1513.229492f, 5347.822266f, 146.233994f);
//					}
//					break;
//				case EVENT_MOVE_1:
//					if (MotionMaster* motion = me->GetMotionMaster())
//					{
//						move = true;
//						motion->MovePoint(2, 1561.511475f, 5350.225586f, 161.192337f);
//					}
//					break;
//				case EVENT_MOVE_2:
//				{
//					if (MotionMaster* motion = me->GetMotionMaster())
//					{
//						move = true;
//						motion->MovePoint(3, 1563.637207f, 5330.388672f, 161.230545f);
//					}
//					break;
//				}
//				case EVENT_MOVE_3:
//				{
//					if (MotionMaster* motion = me->GetMotionMaster())
//					{
//						move = true;
//						motion->MovePoint(4, 1508.112061f, 5328.333008f, 161.209290f);
//					}
//					break;
//				}
//				case EVENT_MOVE_4:
//				{
//					if (MotionMaster* motion = me->GetMotionMaster())
//					{
//						move = true;
//						motion->MovePoint(5, 1482.801147f, 5323.564941f, 175.445038f);
//					}
//					break;
//				}
//				case EVENT_MOVE_5:
//				{
//					if (MotionMaster* motion = me->GetMotionMaster())
//					{
//						move = true;
//						motion->MovePoint(6, 1470.351929f, 5323.047852f, 176.123947f);
//					}
//					break;
//				}
//				case EVENT_MOVE_6:
//				{
//					if (MotionMaster* motion = me->GetMotionMaster())
//					{
//						move = true;
//						motion->MovePoint(7, 1472.628906f, 5286.789551f, 179.764008f);
//					}
//					break;
//				}
//				case EVENT_MOVE_7:
//				{
//					if (MotionMaster* motion = me->GetMotionMaster())
//					{
//						move = true;
//						motion->MovePoint(8, 1517.883667f, 5290.775391f, 184.709412f);
//					}
//					break;
//				}
//				}
//			}
//
//			DoMeleeAttackIfReady();
//		}
//	private:
//		EventMap events;
//	};
//
//	CreatureAI* GetAI(Creature* creature) const
//	{
//		return new Yang_IronClaw_AI(creature);
//	}
//};
//class Amberweaver : public CreatureScript // npc_tut_ai - Class constructor, name this anything that doesn't conflict with another name
//{
//public:
//	Amberweaver() : CreatureScript("Amberweaver") { } // npc_tut_ai, should be the same as class npc_tut_ai -- CreatureScript("npc_tut_ai") - This is your 'ScriptName' that you will assign in your database
//
//	struct Yang_IronClaw_AI : public ScriptedAI
//	{
//		Yang_IronClaw_AI(Creature* creature) : ScriptedAI(creature)
//		{
//			//me->AddUnitState(UNIT_STATE_CANNOT_AUTOATTACK);
//			me->AddUnitMovementFlag(MOVEMENTFLAG_ROOT);
//			me->CanFreeMove();
//			me->SetSpeed(MOVE_RUN, 0.0, true);
//
//			if (IsHeroic())
//			{
//				me->SetMaxHealth(5318204);
//				me->SetHealth(5318204);
//			}
//			else
//			{
//				me->SetMaxHealth(3269660);
//				me->SetHealth(3269660);
//			}
//		}
//		bool bossencounterstarted;
//		bool hasstarted;
//
//		void Reset()
//		{
//			events.ScheduleEvent(EVENT_BOMBARD, 4000);
//		}
//		void UpdateAI(uint32 const diff)
//		{
//			events.Update(diff);
//
//			// Phase Switch Switch
//			while (uint32 eventId = events.ExecuteEvent())
//			{
//				switch (eventId)
//				{
//				case EVENT_BOMBARD:
//					if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
//					{
//						me->CastSpell(target, 120561);
//						events.ScheduleEvent(EVENT_BOMBARD, 4000);
//					}
//					break;
//				}
//			}
//		}
//		void JustDied(Unit* /*killer*/)
//		{
//			if (Creature* Yang = me->FindNearestCreature(61620, 300.0f, true))
//			{
//				if (Yang_Ironclaw::Yang_IronClaw_AI* linkAI = CAST_AI(Yang_Ironclaw::Yang_IronClaw_AI, Yang->GetAI()))
//				{
//					if (!linkAI->achievementamberweaver)
//					{
//						linkAI->achievementamberweaver = true;
//						me->DespawnOrUnsummon(500);
//
//						if (Creature* Boss = me->FindNearestCreature(61634, 400.0f, true))
//						{
//							Boss->MonsterYell("Where? where is it!? Worthless, useless.. damn you!", LANG_UNIVERSAL, me->GetGUID());
//							DoPlaySoundToSet(Boss, 30272);
//						}
//					}
//				}
//			}
//		}
//	private:
//		EventMap events;
//	};
//
//	CreatureAI* GetAI(Creature* creature) const
//	{
//		return new Yang_IronClaw_AI(creature);
//	}
//
//};
//class Gong : public GameObjectScript // npc_tut_ai - Class constructor, name this anything that doesn't conflict with another name
//{
//public:
//	Gong() : GameObjectScript("Gong") { }
//
//	bool OnGossipHello(Player* player, GameObject* object)
//	{
//		if (Creature* Yang = object->FindNearestCreature(61620, 100.f, true))
//		{
//			if (Yang_Ironclaw::Yang_IronClaw_AI* linkAI = CAST_AI(Yang_Ironclaw::Yang_IronClaw_AI, Yang->GetAI()))
//			{
//				if (linkAI->pregong)
//				{
//					if (linkAI->phase_1 || linkAI->phase_2 || linkAI->phase_3 || linkAI->phase_4)
//					{
//						linkAI->hasgong = true;
//						linkAI->pregong = false;
//
//						object->MonsterTextEmote("The gong peals a taunting note to the mantid armies below, accelerating the pace of their assault.", object->GetGUID(), true);
//					}
//				}
//				return true;
//			}
//		}
//		return false;
//	}
//};
//class Li_chu : public CreatureScript // npc_tut_ai - Class constructor, name this anything that doesn't conflict with another name
//{
//public:
//	Li_chu() : CreatureScript("Li_chu") { } // npc_tut_ai, should be the same as class npc_tut_ai -- CreatureScript("npc_tut_ai") - This is your 'ScriptName' that you will assign in your database
//
//	struct Yang_IronClaw_AI : public CreatureAI
//	{
//		Yang_IronClaw_AI(Creature* creature) : CreatureAI(creature)
//		{
//			me->SetSpeed(MOVE_RUN, 0.8f, true);
//			//me->AddUnitState(UNIT_STATE_CANNOT_AUTOATTACK);
//		}
//		bool bossencounterstarted;
//		bool hasstarted;
//		bool canrestart;
//		bool act;
//		void Reset()
//		{
//			me->SetReactState(REACT_PASSIVE);
//			act = true;
//			hasstarted = true;
//			canrestart = false;
//		}
//		void MovementInform(uint32 /*type*/, uint32 id)
//		{
//			if (id == 1)
//			{
//				if (act)
//				{
//					act = false;
//					events.ScheduleEvent(EVENT_MOVE_1, 3000);
//				}
//			}
//			if (id == 2)
//			{
//				if (act)
//				{
//					act = false;
//					events.ScheduleEvent(EVENT_MOVE_2, 3000);
//				}
//			}
//			if (id == 3)
//			{
//
//				if (act)
//				{
//					act = false;
//					events.ScheduleEvent(EVENT_MOVE_3, 3000);
//				}
//			}
//			if (id == 4)
//			{
//
//				if (act)
//				{
//					act = false;
//					events.ScheduleEvent(EVENT_MOVE_4, 3000);
//				}
//			}
//		}
//		void UpdateAI(uint32 const diff)
//		{
//			events.Update(diff);
//
//			if (me->getFaction() == 35 && hasstarted)
//			{
//				hasstarted = false;
//				events.ScheduleEvent(EVENT_MOVE, 1000);
//			}
//
//			// Phase Switch Switch
//			while (uint32 eventId = events.ExecuteEvent())
//			{
//				switch (eventId)
//				{
//				case EVENT_MOVE:
//					if (MotionMaster* motion = me->GetMotionMaster())
//					{
//						motion->MovePoint(1, 1540.542480f, 5288.630859f, 184.765640f);
//
//					}
//					break;
//				case EVENT_MOVE_1:
//					if (MotionMaster* motion = me->GetMotionMaster())
//					{
//						me->AddAura(123032, me);
//						motion->MovePoint(2, 1545.490967f, 5315.372559f, 184.649094f);
//						act = true;
//					}
//					break;
//				case EVENT_MOVE_2:
//					if (MotionMaster* motion = me->GetMotionMaster())
//					{
//						me->RemoveAura(123032);
//						Unit* Tar = me->SummonCreature(61817, float(1545.490967 + urand(2, 4)), 5315.372559f, 184.649094f);
//						motion->MovePoint(3, 1540.542480f, 5288.630859f, 184.765640f);
//						act = true;
//					}
//					break;
//				case EVENT_MOVE_3:
//					if (MotionMaster* motion = me->GetMotionMaster())
//					{
//						me->AddAura(123032, me);
//						motion->MovePoint(4, 1537.142456f, 5314.982422f, 184.548911f);
//						canrestart = true;
//						act = true;
//					}
//					break;
//				case EVENT_MOVE_4:
//					Unit* Tar = me->SummonCreature(61817, 1532.659424f, 5313.379883f, 184.648926f);
//					if (canrestart)
//					{
//						me->RemoveAura(123032);
//						canrestart = false;
//						events.ScheduleEvent(EVENT_MOVE, 1000);
//						act = true;
//					}
//					break;
//				}
//			}
//
//			DoMeleeAttackIfReady();
//		}
//	private:
//		EventMap events;
//	};
//
//	CreatureAI* GetAI(Creature* creature) const
//	{
//		return new Yang_IronClaw_AI(creature);
//	}
//};
//class Lo_cho : public CreatureScript // npc_tut_ai - Class constructor, name this anything that doesn't conflict with another name
//{
//public:
//	Lo_cho() : CreatureScript("Lo_cho") { } // npc_tut_ai, should be the same as class npc_tut_ai -- CreatureScript("npc_tut_ai") - This is your 'ScriptName' that you will assign in your database
//
//	struct Yang_IronClaw_AI : public CreatureAI
//	{
//		Yang_IronClaw_AI(Creature* creature) : CreatureAI(creature)
//		{
//			me->SetSpeed(MOVE_RUN, 0.8f, true);
//			//me->AddUnitState(UNIT_STATE_CANNOT_AUTOATTACK);
//		}
//		bool bossencounterstarted;
//		bool hasstarted;
//		bool canrestart;
//		bool acted;
//		void Reset()
//		{
//			hasstarted = true;
//			canrestart = false;
//			acted = true;
//		}
//		void MovementInform(uint32 /*type*/, uint32 id)
//		{
//			if (id == 1)
//			{
//				if (acted)
//				{
//					acted = false;
//					events.ScheduleEvent(EVENT_MOVE_1, 2000);
//				}
//			}
//			if (id == 2)
//			{
//				if (acted)
//				{
//					acted = false;
//					events.ScheduleEvent(EVENT_MOVE_2, 2000);
//				}
//			}
//		}
//		void UpdateAI(uint32 const diff)
//		{
//			events.Update(diff);
//
//			if (me->getFaction() == 35 && hasstarted)
//			{
//				hasstarted = false;
//				events.ScheduleEvent(EVENT_MOVE, 1000);
//			}
//
//			// Phase Switch Switch
//			while (uint32 eventId = events.ExecuteEvent())
//			{
//				switch (eventId)
//				{
//				case EVENT_MOVE:
//					if (MotionMaster* motion = me->GetMotionMaster())
//					{
//						motion->MovePoint(1, 1503.455200f, 5296.409668f, 184.950592f);
//						acted = true;
//					}
//					break;
//				case EVENT_MOVE_1:
//					if (MotionMaster* motion = me->GetMotionMaster())
//					{
//						motion->MovePoint(2, 1514.923096f, 5312.033203f, 184.649033f);
//						canrestart = true;
//						acted = true;
//						me->AddAura(123032, me);
//					}
//					break;
//				case EVENT_MOVE_2:
//					if (MotionMaster* motion = me->GetMotionMaster())
//					{
//						TempSummon* Tar = me->SummonCreature(61817, float(1514.923096 + urand(1, 5)), float(5312.033203 + urand(1, 3)), 184.649033f);
//						motion->MovePoint(3, 1540.542480f, 5288.630859f, 184.765640f);
//						me->RemoveAura(123032);
//						if (canrestart)
//						{
//							canrestart = false;
//							events.ScheduleEvent(EVENT_MOVE, 1000);
//						}
//						events.ScheduleEvent(EVENT_MOVE, 4000);
//					}
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
//		return new Yang_IronClaw_AI(creature);
//	}
//};
//class boss_vojak : public CreatureScript
//{
//public:
//	boss_vojak() : CreatureScript("boss_vojak") {}
//
//	struct boss_vojakAI : public BossAI
//	{
//		boss_vojakAI(Creature* creature) : BossAI(creature, DATA_VOJAK)
//		{
//			instance = creature->GetInstanceScript();
//			me->SetSpeed(MOVE_RUN, 1.2f, true);
//		}
//
//		InstanceScript* instance;
//		bool hasstarted;
//		bool move;
//		void Reset()
//		{
//			events.Reset();
//			_Reset();
//			hasstarted = true;
//			move = true;
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
//
//		}
//
//		void EnterCombat(Unit* /*who*/)
//		{
//			_EnterCombat();
//			events.ScheduleEvent(EVENT_CHARGE, 20000);
//			events.ScheduleEvent(EVENT_RISING_SPEED, 8000);
//
//			instance->SetBossState(DATA_VOJAK, IN_PROGRESS);
//		}
//
//		void JustReachedHome()
//		{
//			instance->SetBossState(DATA_VOJAK, FAIL);
//			summons.DespawnAll();
//		}
//		void DamageTaken(Unit* attacker, uint32& damage)
//		{}
//
//		void JustSummoned(Creature* summoned)
//		{
//			summons.Summon(summoned);
//			summons.DespawnAll();
//		}
//		void MovementInform(uint32 /*type*/, uint32 id)
//		{
//			if (id == 0)
//			{
//				if (move)
//				{
//					move = false;
//					events.ScheduleEvent(EVENT_MOVE, 1000);
//				}
//			}
//			if (id == 1)
//			{
//				if (move)
//				{
//					move = false;
//					events.ScheduleEvent(EVENT_MOVE_1, 1000);
//				}
//			}
//			if (id == 2)
//			{
//				if (move)
//				{
//					move = false;
//					events.ScheduleEvent(EVENT_MOVE_2, 1000);
//				}
//
//			}
//			if (id == 3)
//			{
//				if (move)
//				{
//					move = false;
//					events.ScheduleEvent(EVENT_MOVE_3, 1000);
//				}
//			}
//			if (id == 4)
//			{
//				if (move)
//				{
//					move = false;
//					events.ScheduleEvent(EVENT_MOVE_4, 1000);
//				}
//			}
//			if (id == 5)
//			{
//				if (move)
//				{
//					move = false;
//					events.ScheduleEvent(EVENT_MOVE_5, 1000);
//				}
//			}
//			if (id == 6)
//			{
//				if (move)
//				{
//					move = false;
//					events.ScheduleEvent(EVENT_MOVE_6, 1000);
//				}
//			}
//			if (id == 7)
//			{
//				if (move)
//				{
//					if (MotionMaster* motion = me->GetMotionMaster())
//					{
//						motion->Clear(true);
//					}
//
//					move = false;
//					events.ScheduleEvent(EVENT_MOVE_7, 1000);
//				}
//			}
//			if (id == 8)
//			{
//				if (MotionMaster* motion = me->GetMotionMaster())
//				{
//					motion->Clear(true);
//				}
//			}
//		}
//		void UpdateAI(uint32 const diff)
//		{
//			events.Update(diff);
//
//			if (me->getFaction() == 16 && hasstarted)
//			{
//				hasstarted = false;
//				events.ScheduleEvent(EVENT_MOVE, 1000);
//			}
//
//			// Phase Switch Switch
//
//			// Phase Switch Switch
//			while (uint32 eventId = events.ExecuteEvent())
//			{
//				switch (eventId)
//				{
//				case EVENT_MOVE:
//					if (MotionMaster* motion = me->GetMotionMaster())
//					{
//						motion->MovePoint(1, 1513.229492f, 5347.822266f, 146.233994f);
//					}
//					break;
//				case EVENT_MOVE_1:
//					if (MotionMaster* motion = me->GetMotionMaster())
//					{
//						move = true;
//						motion->MovePoint(2, 1561.511475f, 5350.225586f, 161.192337f);
//					}
//					break;
//				case EVENT_MOVE_2:
//				{
//					if (MotionMaster* motion = me->GetMotionMaster())
//					{
//						move = true;
//						motion->MovePoint(3, 1563.637207f, 5330.388672f, 161.230545f);
//					}
//					break;
//				}
//				case EVENT_MOVE_3:
//				{
//					if (MotionMaster* motion = me->GetMotionMaster())
//					{
//						move = true;
//						motion->MovePoint(4, 1508.112061f, 5328.333008f, 161.209290f);
//					}
//					break;
//				}
//				case EVENT_MOVE_4:
//				{
//					if (MotionMaster* motion = me->GetMotionMaster())
//					{
//						move = true;
//						motion->MovePoint(5, 1482.801147f, 5323.564941f, 175.445038f);
//					}
//					break;
//				}
//				case EVENT_MOVE_5:
//				{
//					if (MotionMaster* motion = me->GetMotionMaster())
//					{
//						move = true;
//						motion->MovePoint(6, 1470.351929f, 5323.047852f, 176.123947f);
//					}
//					break;
//				}
//				case EVENT_MOVE_6:
//				{
//					if (MotionMaster* motion = me->GetMotionMaster())
//					{
//						move = true;
//						motion->MovePoint(7, 1472.628906f, 5286.789551f, 179.764008f);
//					}
//					break;
//				}
//				case EVENT_MOVE_7:
//				{
//					if (MotionMaster* motion = me->GetMotionMaster())
//					{
//						if (MotionMaster* motion = me->GetMotionMaster())
//						{
//							motion->Clear(true);
//						}
//
//						move = true;
//						motion->MovePoint(8, 1517.883667f, 5290.775391f, 184.709412f);
//					}
//					break;
//				}
//					// IN COMBAT
//				case EVENT_CHARGE:
//					if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
//						me->CastSpell(target, 120789);
//					events.ScheduleEvent(EVENT_WHIRLWHIND, 1000);
//					events.ScheduleEvent(EVENT_CHARGE, 16000);
//					break;
//				case EVENT_WHIRLWHIND:
//					me->RemoveAura(120270);
//					me->CastSpell(me->SelectNearestTarget(), 120759);
//					me->RemoveAura(120778);
//					break;
//				case EVENT_RISING_SPEED:
//				{
//					if (me->HasAura(120758))
//					{
//						if (AuraPtr aura = me->GetAura(120758))
//						{
//							int32 stacks = aura->GetStackAmount();
//							aura->SetStackAmount(stacks + 1);
//						}
//					}
//					else
//					{
//						me->AddAura(120758, me);
//					}
//					events.ScheduleEvent(EVENT_RISING_SPEED, 8000);
//					break;
//				}
//				}
//
//			}
//			DoMeleeAttackIfReady();
//		}
//		void KilledUnit(Unit* victim)
//		{
//			if (victim->GetTypeId() == TYPEID_PLAYER)
//			{
//				int32 xrand = urand(1, 3);
//
//				if (xrand == 1)
//				{
//					me->MonsterYell("Too.. Easy!", LANG_UNIVERSAL, me->GetGUID());
//					DoPlaySoundToSet(me, 30274);
//				}
//				else if (xrand == 2)
//				{
//					me->MonsterYell("Were you even trying!?", LANG_UNIVERSAL, me->GetGUID());
//					DoPlaySoundToSet(me, 30275);
//				}
//				else if (xrand == 3)
//				{
//					me->MonsterYell("Haha! You die so easily!", LANG_UNIVERSAL, me->GetGUID());
//					DoPlaySoundToSet(me, 30276);
//				}
//			}
//		}
//		void JustDied(Unit* /*killer*/)
//		{
//			// Ending event
//			if (Creature* Yang = me->FindNearestCreature(61620, 100.f, true))
//			{
//				if (Yang_Ironclaw::Yang_IronClaw_AI* linkAI = CAST_AI(Yang_Ironclaw::Yang_IronClaw_AI, Yang->GetAI()))
//				{
//					if (!linkAI->stopcontinue)
//					{
//						linkAI->stopcontinue = true;
//					}
//				}
//			}
//			// Achievement
//			if (Creature* Yang = me->FindNearestCreature(61620, 300.0f, true))
//			{
//				if (Yang_Ironclaw::Yang_IronClaw_AI* linkAI = CAST_AI(Yang_Ironclaw::Yang_IronClaw_AI, Yang->GetAI()))
//				{
//					if (linkAI->achievementamberweaver)
//					{
//						Map::PlayerList const& players = me->GetMap()->GetPlayers();
//						if (!players.isEmpty())
//						{
//							for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
//							{
//								Player* player = itr->getSource();
//
//								if (!player->GetAchievementMgr().HasAchieved(ACHIEVEMENT_WHERE_MY_AIR_SUPPORT))
//								{
//									AchievementEntry const* achievementEntry = sAchievementMgr->GetAchievement(ACHIEVEMENT_WHERE_MY_AIR_SUPPORT);
//
//									player->CompletedAchievement(achievementEntry);
//								}
//							}
//						}
//					}
//				}
//			}
//			DoPlaySoundToSet(me, 30273);
//			me->MonsterYell("It was.. a trap..", LANG_UNIVERSAL, me->GetGUID());
//			_JustDied();
//			instance->SetBossState(DATA_VOJAK, DONE);
//		}
//
//	};
//
//	CreatureAI* GetAI(Creature* creature) const
//	{
//		return new boss_vojakAI(creature);
//	}
//};
//// ENDING CREATURES
//class Yang_Ironclaw_ending : public CreatureScript // npc_tut_ai - Class constructor, name this anything that doesn't conflict with another name
//{
//public:
//	Yang_Ironclaw_ending() : CreatureScript("Yang_Ironclaw_ending") { } // npc_tut_ai, should be the same as class npc_tut_ai -- CreatureScript("npc_tut_ai") - This is your 'ScriptName' that you will assign in your database
//
//	struct Yang_IronClaw_AI : public ScriptedAI
//	{
//		Yang_IronClaw_AI(Creature* creature) : ScriptedAI(creature)
//		{
//			me->SetSpeed(MOVE_RUN, 1.0, true);
//		}
//		bool act;
//		void Reset()
//		{
//			act = true;
//			events.ScheduleEvent(EVENT_MOVE, 8000);
//
//			Creature* Li = me->SummonCreature(657884, 1533.419800f, 5372.576172f, 140.052826f, 0.509092f);
//			Creature* Lo = me->SummonCreature(578745, 1527.923584f, 5382.733887f, 139.928040f, 0.259335f);
//
//			if (Li)
//			{
//				Li->SetStandState(432);
//				if (MotionMaster* motion_LU_CHU = Li->GetMotionMaster())
//				{
//					motion_LU_CHU->Clear(true);
//					motion_LU_CHU->MovePoint(1, 1584.006714f, 5386.606445f, 139.478531f);
//				}
//			}
//			if (Lo)
//			{
//				Lo->SetStandState(432);
//				if (MotionMaster* motion_LI_CHU = Lo->GetMotionMaster())
//				{
//					motion_LI_CHU->Clear(true);
//					motion_LI_CHU->MovePoint(1, 1597.187256f, 5390.384766f, 139.726517f);
//				}
//			}
//
//		}
//		void MovementInform(uint32 /*type*/, uint32 id)
//		{
//			if (id == 1)
//			{
//				if (act)
//				{
//					act = false;
//					events.ScheduleEvent(EVENT_MOVE_1, 3000);
//				}
//			}
//			if (id == 2)
//			{
//				if (act)
//				{
//					act = false;
//					events.ScheduleEvent(EVENT_MOVE_2, 3000);
//				}
//			}
//			if (id == 3)
//			{
//				if (act)
//				{
//					act = false;
//					events.ScheduleEvent(EVENT_MOVE_3, 3000);
//				}
//			}
//			if (id == 4)
//			{
//				if (act)
//				{
//					act = false;
//					events.ScheduleEvent(EVENT_MOVE_4, 5000);
//				}
//			}
//			if (id == 5)
//			{
//				if (act)
//				{
//					act = false;
//					events.ScheduleEvent(EVENT_MOVE_5, 5000);
//				}
//			}
//		}
//		void UpdateAI(uint32 const diff)
//		{
//			events.Update(diff);
//
//			// Phase Switch Switch
//			while (uint32 eventId = events.ExecuteEvent())
//			{
//				switch (eventId)
//				{
//				case EVENT_MOVE:
//					if (MotionMaster* motion = me->GetMotionMaster())
//					{
//						motion->MovePoint(1, 1589.704468f, 5402.752930f, 138.998566f);
//
//						act = true;
//					}
//					break;
//				case EVENT_MOVE_1:
//					if (MotionMaster* motion = me->GetMotionMaster())
//					{
//						act = true;
//						motion->MovePoint(2, 1610.527954f, 5406.795410f, 138.574966f);
//					}
//					break;
//				case EVENT_MOVE_2:
//					if (MotionMaster* motion = me->GetMotionMaster())
//					{
//						act = true;
//						DoPlaySoundToSet(me, 31499);
//						me->MonsterSay("Ah, this gate is locked, but I think I have something that'll open it", LANG_UNIVERSAL, me->GetGUID());
//						motion->MovePoint(3, 1620.034058f, 5411.857422f, 138.74920f);
//
//					}
//					break;
//				case EVENT_MOVE_3:
//					if (MotionMaster* motion = me->GetMotionMaster())
//					{
//						act = true;
//						motion->MovePoint(4, 1619.976807f, 5407.600586f, 138.752060f);
//						me->CastSpell(me, 127408);
//					}
//					break;
//				case EVENT_MOVE_4:
//					if (MotionMaster* motion = me->GetMotionMaster())
//					{
//						act = true;
//						motion->MovePoint(5, 1619.467407f, 5401.726563f, 138.958618f);
//						me->CastSpell(me, 127408);
//					}
//					break;
//				case EVENT_MOVE_5:
//					if (MotionMaster* motion = me->GetMotionMaster())
//					{
//						act = true;
//						DoPlaySoundToSet(me, 31500);
//						motion->MovePoint(6, 1619.384521f, 5397.630371f, 139.040955f);
//						me->CastSpell(me, 127408);
//						me->MonsterSay("Let me see here.. thirty seconds fuse.", LANG_UNIVERSAL, me->GetGUID());
//						events.ScheduleEvent(EVENT_MOVE_6, 9000);
//					}
//					break;
//				case EVENT_MOVE_6:
//					if (MotionMaster* motion = me->GetMotionMaster())
//					{
//						std::list<Creature*> explosion;
//
//						GetCreatureListWithEntryInGrid(explosion, me, 65168, 10.0f);
//
//						for (std::list<Creature*>::const_iterator itr = explosion.begin(); itr != explosion.end(); itr++)
//						{
//							me->CastSpell((*itr), 127417);
//							(*itr)->DespawnOrUnsummon();
//						}
//						GameObject* door = me->FindNearestGameObject(213286, 20.0f);
//
//						if (door)
//						{
//							door->Delete();
//							door->DeleteFromDB();
//						}
//						events.ScheduleEvent(EVENT_MOVE_7, 7000);
//					}
//					break;
//				case EVENT_MOVE_7:
//					me->MonsterSay("Whoops.. did I say thirty? I meant three", LANG_UNIVERSAL, me->GetGUID());
//					DoPlaySoundToSet(me, 31501);
//					events.ScheduleEvent(EVENT_MOVE_8, 7000);
//					break;
//				case EVENT_MOVE_8:
//					if (MotionMaster* motion = me->GetMotionMaster())
//					{
//						motion->MovePoint(10, 1527.923584f, 5382.733887f, 139.928040f);
//					}
//					me->MonsterSay("Go.. Hurry, you must stop the siege!", LANG_UNIVERSAL, me->GetGUID());
//					DoPlaySoundToSet(me, 31502);
//					events.ScheduleEvent(EVENT_MOVE_9, 10000);
//					break;
//				case EVENT_MOVE_9:
//					me->DespawnOrUnsummon(1000);
//					if (Creature* Lo_Chu = me->FindNearestCreature(657884, 100.0f, true))
//					{
//						Lo_Chu->DespawnOrUnsummon(1000);
//					}
//					if (Creature* Li_Chu = me->FindNearestCreature(578745, 100.0f, true))
//					{
//						Li_Chu->DespawnOrUnsummon(1000);
//					}
//					break;
//				}
//			}
//
//			DoMeleeAttackIfReady();
//		}
//	private:
//		EventMap events;
//	};
//
//	CreatureAI* GetAI(Creature* creature) const
//	{
//		return new Yang_IronClaw_AI(creature);
//	}
//};
//// NPC value 61579
//class npc_puddle_summon_x : public CreatureScript
//{
//public:
//	npc_puddle_summon_x() : CreatureScript("npc_puddle_summon_x") { }
//
//	struct npc_sap_puddleAI : public ScriptedAI
//	{
//		npc_sap_puddleAI(Creature* creature) : ScriptedAI(creature)
//		{
//
//		}
//		void Reset()
//		{
//			me->SummonCreature(615777, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN, 24000);
//		}
//		void UpdateAI(uint32 const diff)
//		{
//		}
//	};
//
//	CreatureAI* GetAI(Creature *creature) const
//	{
//		return new npc_sap_puddleAI(creature);
//	}
//};
//class npc_sap_puddle_x : public CreatureScript
//{
//public:
//	npc_sap_puddle_x() : CreatureScript("npc_sap_puddle_x") { }
//
//	struct Resin_Trigger_AI : public CreatureAI
//	{
//		Resin_Trigger_AI(Creature* creature) : CreatureAI(creature)
//		{
//			me->AddExtraUnitMovementFlag(MOVEMENTFLAG_ROOT);
//
//			/*
//			me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
//			me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_1);
//			me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
//			me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
//			me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);
//			*/
//		}
//		bool Used;
//
//		void Reset()
//		{
//			Used = false;
//			events.Reset();
//			me->CastSpell(me, 120591);
//		}
//		void UpdateAI(uint32 const diff)
//		{
//			events.Update(diff);
//
//			std::list<Creature*> list_p;
//			JadeCore::AnyCreatureInObjectRangeCheck check(me, 2.0f);
//			JadeCore::CreatureListSearcher<JadeCore::AnyCreatureInObjectRangeCheck> searcher(me, list_p, check);
//			me->VisitNearbyObject(2.0, searcher);
//
//			for (std::list<Creature*>::const_iterator itr = list_p.begin(); itr != list_p.end(); itr++)
//			{
//				if ((*itr)->IsWithinDistInMap(me, 3.5f, true) && (*itr)->getFaction() != 35)
//				{
//					me->AddAura(120270, (*itr));
//				}
//			}
//
//			while (uint32 eventId = events.ExecuteEvent())
//			{
//				//switch (eventId)
//				//{
//
//				//}
//			}
//		}
//	private:
//		EventMap events;
//	};
//
//	CreatureAI* GetAI(Creature* creature) const
//	{
//		return new Resin_Trigger_AI(creature);
//	}
//
//};
//// spells
//class Summon_Tar_Damage : public CreatureScript
//{
//public:
//	Summon_Tar_Damage() : CreatureScript("Summon_Tar_Damage") { }
//
//	struct Resin_Trigger_AI : public CreatureAI
//	{
//		Resin_Trigger_AI(Creature* creature) : CreatureAI(creature)
//		{
//		}
//
//		void Reset()
//		{
//			events.Reset();
//		}
//		void JustDied(Unit* killer)
//		{
//			me->SummonCreature(213124, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN, 20000);
//		}
//		void UpdateAI(uint32 const diff)
//		{
//			events.Update(diff);
//
//			// Pre Cinematic after they kill the Sikthik Warden
//
//			while (uint32 eventId = events.ExecuteEvent())
//			{
//				//switch (eventId)
//				//{
//				//}
//			}
//		}
//	private:
//		EventMap events;
//	};
//
//	CreatureAI* GetAI(Creature* creature) const
//	{
//		return new Resin_Trigger_AI(creature);
//	}
//
//};
//class mantid_tar_keg_gossip : public CreatureScript // npc_tut_ai - Class constructor, name this anything that doesn't conflict with another name
//{
//public:
//	mantid_tar_keg_gossip() : CreatureScript("mantid_tar_keg_gossip") { } // npc_tut_ai, should be the same as class npc_tut_ai -- CreatureScript("npc_tut_ai") - This is your 'ScriptName' that you will assign in your database
//
//	bool OnGossipHello(Player* player, Creature* creature)
//	{
//		player->CastSpell(player, 123032, true);
//		creature->DespawnOrUnsummon(100);
//		return true;
//	}
//};
//// Id: 123039
//// Name: Player Throw Barrel
//class spell_player_throw_barrel : public SpellScriptLoader
//{
//public:
//	spell_player_throw_barrel() : SpellScriptLoader("spell_player_throw_barrel") {}
//
//	class spell_player_throw_barrel_SpellScript : public SpellScript
//	{
//		PrepareSpellScript(spell_player_throw_barrel_SpellScript);
//
//		bool Load()
//		{
//			return GetCaster()->GetTypeId() == TYPEID_PLAYER;
//		}
//		void HandleDummy(SpellEffIndex /*effIndex*/)
//		{
//			Unit* caster = GetCaster();
//
//			if (caster->GetTypeId() != TYPEID_PLAYER)
//				return;
//
//			// This removes Name: Carrying Caustic Tar(Id: 123032)
//			caster->ToPlayer()->CastSpell(caster, 123701, true);
//		}
//
//		void Register()
//		{
//			OnEffectHit += SpellEffectFn(spell_player_throw_barrel_SpellScript::HandleDummy, EFFECT_1, SPELL_EFFECT_DUMMY);
//		}
//	};
//
//	SpellScript* GetSpellScript() const
//	{
//		return new spell_player_throw_barrel_SpellScript();
//	}
//};
//// Id: 123032
//// Name: Carrying Caustic Tar
//class spell_carrying_caustic_tar : public SpellScriptLoader
//{
//public:
//	spell_carrying_caustic_tar() : SpellScriptLoader("spell_carrying_caustic_tar") { }
//
//	class spell_carrying_caustic_tar_AuraScript : public AuraScript
//	{
//		PrepareAuraScript(spell_carrying_caustic_tar_AuraScript);
//
//		void OnApply(constAuraEffectPtr /*aurEff*/, AuraEffectHandleModes /*mode*/)
//		{
//			if (GetCaster()->GetTypeId() != TYPEID_PLAYER)
//				return;
//
//			if (!GetTarget()->HasSpell(123039))
//				GetTarget()->ToPlayer()->learnSpell(123039, false);
//		}
//		void OnRemove(constAuraEffectPtr /*aurEff*/, AuraEffectHandleModes /*mode*/)
//		{
//			if (GetCaster()->GetTypeId() != TYPEID_PLAYER)
//				return;
//
//			if (GetTarget()->HasSpell(123039))
//				GetTarget()->ToPlayer()->removeSpell(123039);
//		}
//
//		void Register()
//		{
//			AfterEffectApply += AuraEffectApplyFn(spell_carrying_caustic_tar_AuraScript::OnApply, EFFECT_0, SPELL_AURA_MOD_DECREASE_SPEED, AURA_EFFECT_HANDLE_REAL);
//			AfterEffectRemove += AuraEffectRemoveFn(spell_carrying_caustic_tar_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_MOD_DECREASE_SPEED, AURA_EFFECT_HANDLE_REAL);
//		}
//	};
//
//	AuraScript* GetAuraScript() const
//	{
//		return new spell_carrying_caustic_tar_AuraScript();
//	}
//};
//class cancel_aura_spell_damage : public SpellScriptLoader
//{
//public:
//	cancel_aura_spell_damage() : SpellScriptLoader("cancel_aura_spell_damage") {}
//
//	class spell_player_throw_barrel_SpellScript : public SpellScript
//	{
//		PrepareSpellScript(spell_player_throw_barrel_SpellScript);
//
//		void HandleAfterCast()
//		{
//			if (!GetCaster())
//				return;
//
//			Unit* caster = GetCaster();
//
//			if (caster->GetTypeId() != TYPEID_PLAYER)
//				return;
//
//			if (SpellInfo const* spell = GetSpellInfo())
//			{
//				if (spell->Id == 123039)
//				{
//					if (caster->HasAura(123035))
//					{
//						caster->RemoveAura(123035);
//					}
//					if (caster->HasAura(123032))
//					{
//						caster->RemoveAura(123032);
//					}
//				}
//			}
//		}
//
//		void Register()
//		{
//			AfterCast += SpellCastFn(spell_player_throw_barrel_SpellScript::HandleAfterCast);
//		}
//	};
//
//	SpellScript* GetSpellScript() const
//	{
//		return new spell_player_throw_barrel_SpellScript();
//	}
//};
//class Sikthik_warden : public CreatureScript
//{
//public:
//	Sikthik_warden() : CreatureScript("Sikthik_warden") { }
//
//	struct Resin_Trigger_AI : public CreatureAI
//	{
//		Resin_Trigger_AI(Creature* creature) : CreatureAI(creature)
//		{
//		}
//
//		void Reset()
//		{
//			events.Reset();
//		}
//		void JustDied(Unit* killer)
//		{
//			if (Creature* Yang = me->FindNearestCreature(61620, 100.f, true))
//			{
//				if (Yang_Ironclaw::Yang_IronClaw_AI* linkAI = CAST_AI(Yang_Ironclaw::Yang_IronClaw_AI, Yang->GetAI()))
//				{
//					if (linkAI->hasstarted)
//					{
//						linkAI->hasstarted = false;
//					}
//					me->SetPhaseMask(50000, true);
//					me->DespawnOrUnsummon(10);
//				}
//			}
//		}
//		void UpdateAI(uint32 const diff)
//		{
//			events.Update(diff);
//
//			// Pre Cinematic after they kill the Sikthik Warden
//
//
//			while (uint32 eventId = events.ExecuteEvent())
//			{
//				//switch (eventId)
//				//{
//				//}
//			}
//		}
//	private:
//		EventMap events;
//	};
//
//	CreatureAI* GetAI(Creature* creature) const
//	{
//		return new Resin_Trigger_AI(creature);
//	}
//
//};
//void AddSC_boss_vojak()
//{
//	// System
//	new Yang_Ironclaw();
//	new Yang_Ironclaw_ending();
//	new Lo_cho();
//	new Li_chu();
//	new cancel_aura_spell_damage();
//	new spell_player_throw_barrel();
//	new spell_carrying_caustic_tar();
//	new mantid_tar_keg_gossip();
//	new npc_puddle_summon_x();
//	new npc_sap_puddle_x();
//	new Sikthik_warden();
//
//	// Boss
//	new boss_vojak();
//
//	// Trash
//	new Trash();
//	new Amberweaver();
//
//	// Gong
//	new Gong();
//}
