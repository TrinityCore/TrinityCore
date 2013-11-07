#include "ScriptMgr.h"
#include "GameObjectAI.h"
#include "Player.h"
#include "Transport.h"
#include "Common.h"
#ifdef __APPLE__
#include "UpdateData.h"
#include "WorldPacket.h"
#endif

const std::string MURADIN_BUTTON_TEXT = "My companinos are all accounted for, Muradin. Let's go!";

enum gObjectId
{
	GO_ALLIANCE_GUNSHIP = 201580,
	GO_HORDE_GUNSHIP = 201812
};

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


void StartFlyShip(Transport* t)
{
	t->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_IN_USE);
	t->SetGoState(GO_STATE_ACTIVE);
	t->SetUInt32Value(GAMEOBJECT_DYNAMIC, 0x10830010);
	t->SetFloatValue(GAMEOBJECT_PARENTROTATION + 3, 1.0f);
    
	Map* map = t->GetMap();
	
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

void ShowToPlayer(Transport* trans, Player* plr)
{
	UpdateData transData;
	trans->BuildCreateUpdateBlockForPlayer(&transData, plr);
    
	WorldPacket packet;
	transData.BuildPacket(&packet);
	plr->SendDirectMessage(&packet);
};

Creature* AddNPCToTransport(Transport* trans, uint32 entry, float x, float y, float z, float o)
{
	Creature* creature = new Creature;
	if(creature->Create(sObjectMgr->GenerateLowGuid(HIGHGUID_UNIT), trans->GetMap(), trans->GetPhaseMask(), entry, 0, trans->GetGOInfo()->faction, 0, 0, 0, 0))
	{
		creature->SetTransport(trans);
		creature->AddUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT);
		creature->m_movementInfo.guid = trans->GetGUID();
		creature->m_movementInfo.pos.Relocate(x, y, z, o);
        
		o += trans->GetOrientation();
		o = trans->NormalizeOrientation(o);
        
		creature->Relocate(trans->GetPositionX() + (x * cos(trans->GetOrientation()) + y * sin(trans->GetOrientation()) + float(M_PI)),
                           trans->GetPositionY() + (y * cos(trans->GetOrientation()) + x * sin(trans->GetOrientation())),
                           z + trans->GetPositionZ(),
                           o);
		creature->SetHomePosition(creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation());
        
		trans->GetMap()->AddToMap(creature);
		trans->AddPassenger(creature);
		creature->setActive(true);
		sScriptMgr->OnAddCreaturePassenger(trans, creature);
        
		return creature;
	}
	return NULL;
};

class GunshipStairs : public GameObjectScript
{
public:
	GunshipStairs() : GameObjectScript("icc_gunship_stairs") { }
    
	bool OnGossipHello(Player* plr, GameObject* go)
	{
		if(plr->GetTeamId() == 0)
		{
			// Alliance
			if(go->FindNearestGameObject(GO_ALLIANCE_GUNSHIP, 10000.0f) == NULL)
			{
				Transport* trans = sTransportMgr->CreateTransport(GO_ALLIANCE_GUNSHIP, 0, plr->GetMap());
				AddNPCToTransport(trans, 36948, 13.51547f, -0.160213f, 20.87252f, 3.10672f);
                
                
				ShowToPlayer(trans, plr);
				//Creature* muradin = plr->SummonCreature(36948, trans->GetPositionX() + 13.51547f, trans->GetPositionY() - 0.160213f, trans->GetPositionZ() + 20.87252f, 3.10672f);
                
				//trans->AddPassenger(muradin);
				trans->AddPassenger(plr);
				plr->SetTransport(trans);
			}
		}else{
			// Horde
			if(go->FindNearestGameObject(gObjectId::GO_HORDE_GUNSHIP, 10000.0f) == NULL)
			{
				Transport* trans = sTransportMgr->CreateTransport(GO_HORDE_GUNSHIP, 0, plr->GetMap());
				trans->AddPassenger(plr);
                
				ShowToPlayer(trans, plr);
			}
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
	npc_muradin_bronzebeard() : CreatureScript("npc_muradin_bronzebeard" )  { }
    
    
	bool OnGossipHello(Player* plr, Creature* npc)
	{
		plr->PlayerTalkClass->GetGossipMenu().AddMenuItem(0, GOSSIP_ICON_CHAT, MURADIN_BUTTON_TEXT, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1,"", 0);
        
		plr->PlayerTalkClass->SendGossipMenu(TEXT_MURADIN_MENU_TEXT, npc->GetGUID());
		return true;
	}
    
	bool OnGossipSelect(Player* plr, Creature* npc, uint32 sender, uint32 action)
	{
		switch(action)
		{
            case GOSSIP_ACTION_INFO_DEF + 1:
                plr->PlayerTalkClass->SendCloseGossip();
                StartFlyShip(plr->GetTransport());
		}
        
		return true;
	}
    
	struct npc_muradin_bronzebeardAI : public ScriptedAI
	{
		npc_muradin_bronzebeardAI(Creature* creature) : ScriptedAI(creature)
		{
		}
        
		void Reset()
		{
			me->SetReactState(REACT_PASSIVE);
			me->setFaction(1802);
			me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
			TC_LOG_ERROR(LOG_FILTER_WORLDSERVER, "AI Reset creature: %u", me->GetGUID());
		}
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