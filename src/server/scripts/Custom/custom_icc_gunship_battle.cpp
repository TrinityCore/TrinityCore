#include "ScriptMgr.h"
#include "GameObjectAI.h"
#include "GameObject.h"
#include "Player.h"
#include "Transport.h"
#include "TransportMgr.h"
#include "Common.h"
#include "ScriptedGossip.h"
#include "ScriptedCreature.h"
#include "../Northrend/IcecrownCitadel/icecrown_citadel.h"
#include "MapManager.h"
#include "ObjectMgr.h"
#include "Path.h"
#include "Map.h"
#include "ScriptMgr.h"
#include "WorldPacket.h"

#ifdef __APPLE__
#include "UpdateData.h"
#include "WorldPacket.h"
#include "ObjectMgr.h"

#include "ScriptMgr.h"
#include "ScriptedCreature.h"

#include "MapManager.h"
#include "Vehicle.h"
#include "Group.h"
#include "Object.h"
#include "ScriptedCreature.h"
#include "SpellAuras.h"
#include "SpellScript.h"
#include "ScriptedEscortAI.h"
#include "CreatureTextMgr.h"
#endif

//TO DO: ^ Remove unnecessary headers

const std::string MURADIN_BUTTON_TEXT = "My companinos are all accounted for, Muradin. Let's go!";

enum TextIds
{
	TEXT_MURADIN_MENU_TEXT = 15101
};

enum Spells
{
	SPELL_ALLIANCE = 70120,
	SPELL_HORDE = 70121
};

enum Transports
{
	TRANSPORT_SKYBREAKER = 21,
	TRANSPORT_ORGRIM = 22
};

enum Events
{
	EVENT_START_FLIGHT,
    EVENT_DUMMY
};

enum Actions
{
    ACTION_START_FLIGHT             = 1,
    ACTION_DUMMY             = 1
};


void InitTransport(Transport* t)
{

	t->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_TRANSPORT);
	t->SetGoState(GO_STATE_ACTIVE);
	t->SetUInt32Value(GAMEOBJECT_DYNAMIC, 0x10830010);
	t->SetFloatValue(GAMEOBJECT_PARENTROTATION + 3, 1.0f);
    
	Map* map = t->GetMap();
    
    //GameObject* gs = ObjectAccessor::GetGameObject(GameObject* go, 164835);
    
	for(Map::PlayerList::const_iterator itr = map->GetPlayers().begin(); itr != map->GetPlayers().end(); ++itr)
	{
		if(Player* player = itr->GetSource())
		{
			UpdateData transData;
			t->BuildCreateUpdateBlockForPlayer(&transData, player);
            
			WorldPacket packet;
			transData.BuildPacket(&packet);
			player->SendDirectMessage(&packet);
		}
	}
};

class GunshipStairs : public GameObjectScript
{
public:
	GunshipStairs() : GameObjectScript("icc_gunship_stairs") { }
    
	bool OnGossipHello(Player* player, GameObject* go)
	{
        player->Say("I clicked the stairs!", LANG_UNIVERSAL);
		if(player->GetTeamId() == 0)
		{
                player->Say("Alliance Gunship spawned from Stairs!", LANG_UNIVERSAL);
            
                Transport* gunshipAlliance;
                gunshipAlliance = sTransportMgr->CreateTransport(GO_ALLIANCE_GUNSHIP, 0, player->GetMap());
            
            
            //Multipurpose function, best used to update ship visibility, can also be used to start the event, if there are 2 transports active at the same time.
            /*Map* map = player->GetMap();
            for (Map::PlayerList::const_iterator itr = map->GetPlayers().begin(); itr != map->GetPlayers().end(); ++itr)
                map->SendInitTransports(player);*/
            
            
                    
            TC_LOG_ERROR(LOG_FILTER_TRANSPORTS, "====== GUNSHIP SPAWNED! ======");
            
		}else{
            player->Say("Horde Gunship spawned from Stairs!", LANG_UNIVERSAL);

            
		}
        
		return true;
	}
};

class Gunship : public TransportScript
{
    
public:
	Gunship() : TransportScript("gunship_transport") { }
    
	void OnAddPassenger(Transport* transport, Player* player)
	{
		if(!transport || !player)
			return;
        
		switch(transport->GetEntry())
		{
            case GO_ALLIANCE_GUNSHIP:
                player->AddAura(SPELL_ALLIANCE, player);
                player->Say("Aura on me!", LANG_UNIVERSAL);
                TC_LOG_ERROR(LOG_FILTER_TRANSPORTS, "====== GUNSHIP AURA ADDED! ======");
                break;
                
            case GO_HORDE_GUNSHIP:
                player->AddAura(SPELL_HORDE, player);
                break;
                
            default:
                break;
		}
	}
};

class npc_muradin_bronzebeard : public CreatureScript
{
public:
	npc_muradin_bronzebeard() : CreatureScript("npc_muradin_bronzebeard_gunship" )  { }
    
	bool OnGossipHello(Player* plr, Creature* npc)
	{
		Map* map = npc->GetMap();

		plr->PlayerTalkClass->GetGossipMenu().AddMenuItem(0, GOSSIP_ICON_CHAT, MURADIN_BUTTON_TEXT, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1,"", 0);
        
		plr->PlayerTalkClass->SendGossipMenu(TEXT_MURADIN_MENU_TEXT, npc->GetGUID());

		Transport* gunshipAlliance = npc->GetTransport();
		uint64 guid = npc->GetInstanceScript()->GetData64(DATA_ENEMY_SHIP);
		Transport* gunshipAllianceEnemy = NULL;

		if(guid)
		{
			gunshipAllianceEnemy = map->GetGameObject(guid)->ToTransport();
			plr->Say("custom_icc_gunship_battle: guid is set ", LANG_UNIVERSAL);

			TC_LOG_ERROR(LOG_FILTER_TRANSPORTS, "custom_icc_gunship_battle: guid gunshipAllianceEnemy = %u", guid);
		}else{
			TC_LOG_ERROR(LOG_FILTER_TRANSPORTS, "custom_icc_gunship_battle: guid gunshipAllianceEnemy not set");
			delete gunshipAllianceEnemy;
		}
        
		if(gunshipAlliance)
		{
			plr->Say("custom_icc_gunship_battle: spawned gunshipAlliance", LANG_UNIVERSAL);
			TC_LOG_ERROR(LOG_FILTER_TRANSPORTS, "custom_icc_gunship_battle: gunshipAlliance = spawned", guid);
			InitTransport(gunshipAlliance);
		}else{
			delete gunshipAlliance;
		}

		if(gunshipAllianceEnemy)
		{
			plr->Say("custiom_icc_gunship_battle: spawned gunshipAllianceEnemy", LANG_UNIVERSAL);
			TC_LOG_ERROR(LOG_FILTER_TRANSPORTS, "custom_icc_gunship_battle: gunshipAllianceEnemy = spawned", guid);
			InitTransport(gunshipAllianceEnemy);
		}else{
			delete gunshipAllianceEnemy;
		}
        /*Map* map = plr->GetMap();
        for (Map::PlayerList::const_iterator itr = map->GetPlayers().begin(); itr != map->GetPlayers().end(); ++itr)
            map->SendInitTransports(plr);*/
		return true;
	}
    
	bool OnGossipSelect(Player* plr, Creature* npc, uint32 sender, uint32 action)
	{
        plr->PlayerTalkClass->ClearMenus();
        
        if (action == GOSSIP_ACTION_INFO_DEF + 2)
            npc->MonsterSay("I'll wait for the raid leader", LANG_UNIVERSAL, plr->GetGUID());
        
        if (action == GOSSIP_ACTION_INFO_DEF + 1)
            plr->PlayerTalkClass->SendCloseGossip();
            npc->AI()->DoAction(ACTION_START_FLIGHT);
        
		return true;
	}
    
	struct npc_muradin_bronzebeardAI : public ScriptedAI
	{
		npc_muradin_bronzebeardAI(Creature* creature) : ScriptedAI(creature)
		{
            instance = creature->GetInstanceScript();
		}
        
		void Reset() OVERRIDE
		{
            if (instance->GetBossState(DATA_GUNSHIP_EVENT) == IN_PROGRESS)
                return;
			me->SetReactState(REACT_PASSIVE);
			me->setFaction(1802);
			me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
            events.Reset();
            EventScheduled = false;
            
            Map* map = me->GetMap();
            for (Map::PlayerList::const_iterator itr = map->GetPlayers().begin(); itr != map->GetPlayers().end(); ++itr)
                map->SendInitTransports(plr = itr->GetSource());
            
			TC_LOG_ERROR(LOG_FILTER_WORLDSERVER, "AI Reset creature: %u", me->GetGUID());
		}
        
        
        // Timers are broken... i think.
        void DoAction(int32 action) OVERRIDE
        {
            switch (action)
            {
                case ACTION_START_FLIGHT:
                    me->MonsterSay("ACTION_START_FLIGHT!",LANG_UNIVERSAL, 0);
                    events.ScheduleEvent(EVENT_START_FLIGHT, 5000);
                    break;
                default:
                    break;
            }
        }
        
        
        //Further testing sugests this is the problem.
        void UpdateAI(uint32 uDiff) OVERRIDE
        {
            
            events.Update(uDiff);
            
            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_START_FLIGHT:
                        me->MonsterSay("EVENT_START_FLIGHT",LANG_UNIVERSAL, 0);
                        Transport* skybreaker = me->GetTransport();
                        InitTransport(skybreaker);
                        break;
                }
            }
            
            DoMeleeAttackIfReady();
        }
        
    private:
        //Transport* skybreaker;
        //Map* map;
        InstanceScript* instance;
        Player* plr;
        EventMap events;
        bool EventScheduled;
        
    };
    
    CreatureAI* GetAI(Creature* creature) const
	{
		return new npc_muradin_bronzebeardAI(creature);
	}
    
};



void AddSC_icc_gunship_battle()
{
    new GunshipStairs();
    new Gunship();
    
    new npc_muradin_bronzebeard();
}