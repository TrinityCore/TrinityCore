#include "tristam_catacombs.h"
#include "Creature.h"
#include "EventProcessor.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ObjectGuid.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptedEscortAI.h"
#include "ScriptedGossip.h"
#include "ScriptMgr.h"
#include "TemporarySummon.h"
#include "Unit.h"

#include <iostream>

enum Events
{
	EVENT_START_01 = 1,
	EVENT_START_02,
	EVENT_START_03,
	EVENT_START_04,

	EVENT_ANTONN_GRAVE_01,
	EVENT_ANTONN_GRAVE_02,
	EVENT_ANTONN_GRAVE_03,
};

enum Texts
{
	SAY_NETRISTRASZA_INTRO_01   = 0,
	SAY_NETRISTRASZA_INTRO_02   = 1,

	SAY_NETRISTRASZA_ESCORT_01  = 2,
	SAY_NETRISTRASZA_ESCORT_02  = 3,
	SAY_NETRISTRASZA_ESCORT_03  = 4,
	SAY_NETRISTRASZA_ESCORT_04  = 5,

	SAY_AG_ANTONN_GRAVE_01      = 0,
    SAY_AG_ANTONN_GRAVE_02      = 2,
	SAY_AG_NETRISTRASZA_03      = 6,
    SAY_AG_ANTONN_GRAVE_04      = 3,
};

enum Gossips
{
	GOSSIP_MENU_START = 57024,
	GOSSIP_MENU_FINAL = 57025,
};

// 100075
class npc_netristrasza : public CreatureScript
{
	public:
	npc_netristrasza() : CreatureScript("npc_netristrasza")
	{
	}

	struct npc_netristraszaAI : public EscortAI
	{
		npc_netristraszaAI(Creature* creature) : EscortAI(creature),
			instance(creature->GetInstanceScript()), started(false)
		{
		}

		void Reset() override
		{
			events.Reset();

			me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
			me->SetVisible(false);
		}

		void DoAction(int32 actionId) override
		{
			switch (actionId)
			{
				case ACTION_START_DUNGEON:
					if (started)
						return;
					if (Player* player = me->SelectNearestPlayer(50.f))
						playerGUID = player->GetGUID();
					started = true;
                    Start(true, true, playerGUID);
                    SetDespawnAtEnd(false);
					events.ScheduleEvent(EVENT_START_01, 0s);
					break;
				case ACTION_START_ANTONN:
					if (Creature* antonn = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_ANTONN_GRAVE)))
					{
						me->SetFacingToObject(antonn);
						antonn->AI()->Talk(SAY_AG_ANTONN_GRAVE_01);
					}
					events.ScheduleEvent(EVENT_ANTONN_GRAVE_01, 4s);
					break;
				default:
					break;
			}
		}

		void WaypointReached(uint32 waypointId, uint32 /*pathId*/) override
		{
			switch (waypointId)
			{
				case 1:
					SetEscortPaused(true);
					if (Player* player = ObjectAccessor::GetPlayer(*me, playerGUID))
						me->SetFacingToObject(player);
					events.ScheduleEvent(EVENT_START_02, 1s);
					break;
				case 4:
					me->AI()->Talk(SAY_NETRISTRASZA_ESCORT_01);
					break;
                case 10:
                    instance->ProcessEvent(me, EVENT_ANTONN_GRAVE);
                    break;
				case 15:
					SetEscortPaused(true);
					DoAction(ACTION_START_ANTONN);
					break;
				default:
					break;
			}
		}

		void UpdateAI(uint32 diff) override
		{
			EscortAI::UpdateAI(diff);

			events.Update(diff);

			while (uint32 event = events.ExecuteEvent())
			{
				switch (event)
				{
					case EVENT_START_01:
						if (Creature* portal = DoSummon(NPC_TIME_RIFT, *me, 20s, TEMPSUMMON_TIMED_DESPAWN))
							portal->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
						me->SetVisible(true);
						break;
                    // Handle after waypoint 1
					case EVENT_START_02:
						me->AI()->Talk(SAY_NETRISTRASZA_INTRO_01);
						events.ScheduleEvent(EVENT_START_03, 6s);
						break;
					case EVENT_START_03:
						me->AI()->Talk(SAY_NETRISTRASZA_INTRO_02);
						events.ScheduleEvent(EVENT_START_04, 4s);
						break;
					case EVENT_START_04:
						me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
						break;
					case EVENT_ANTONN_GRAVE_01:
                        if (Creature* antonn = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_ANTONN_GRAVE)))
                            antonn->AI()->Talk(SAY_AG_ANTONN_GRAVE_02);
                        events.ScheduleEvent(EVENT_ANTONN_GRAVE_02, 4s);
                        break;
                    case EVENT_ANTONN_GRAVE_02:
						me->AI()->Talk(SAY_AG_NETRISTRASZA_03);
                        events.ScheduleEvent(EVENT_ANTONN_GRAVE_03, 4s);
                        break;
                    case EVENT_ANTONN_GRAVE_03:
                        if (Creature* antonn = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_ANTONN_GRAVE)))
                            antonn->AI()->Talk(SAY_AG_ANTONN_GRAVE_04);
                        break;
                    default:
                        break;
				}
			}

			DoMeleeAttackIfReady();
		}

		bool OnGossipHello(Player* player) override
		{
			// override default gossip
			if (instance->GetBossState(DATA_NETRISTRASZA_ENTRANCE) == DONE)
			{
				player->PrepareGossipMenu(me, GOSSIP_MENU_FINAL, true);
				player->SendPreparedGossip(me);
				return true;
			}

			// load default gossip
			return false;
		}

		bool OnGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
		{
			ClearGossipMenuFor(player);

			switch (gossipListId)
			{
				case 0:
					player->PlayerTalkClass->SendCloseGossip();
					me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
					SetEscortPaused(false);
					break;
				default:
					break;
			}
			return false;
		}

		private:
		InstanceScript* instance;
		EventMap events;
		bool started;
		ObjectGuid playerGUID;
	};

	CreatureAI* GetAI(Creature* creature) const override
	{
		return GetTristamCatacombsAI<npc_netristraszaAI>(creature);
	}
};

// 5873
class at_entrance_catacombs : public AreaTriggerScript
{
	public:
	at_entrance_catacombs() : AreaTriggerScript("at_entrance_catacombs")
	{
	}

	bool OnTrigger(Player* player, AreaTriggerEntry const* /*at*/) override
	{
		if (player->IsGameMaster())
			return true;

		InstanceScript* _instance = player->GetInstanceScript();

		if (_instance->GetBossState(DATA_NETRISTRASZA_ENTRANCE) == NOT_STARTED)
			_instance->SetBossState(DATA_NETRISTRASZA_ENTRANCE, IN_PROGRESS);

		return true;
	}
};

void AddSC_tristam_catacombs()
{
	new at_entrance_catacombs();
	new npc_netristrasza();
}
