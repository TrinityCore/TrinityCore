#include "ScriptMgr.h"
#include "GameObjectAI.h"
#include "Player.h"
#include "Transport.h" 
#include "Common.h"

enum gObjectId
{
	GO_ALLIANCE_GUNSHIP = 201580,
	GO_HORDE_GUNSHIP = 201812
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

class GunshipStairs : public GameObjectScript
{
public:
	GunshipStairs() : GameObjectScript("icc_gunship_stairs") { }

	bool OnGossipHello(Player* plr, GameObject* go)
	{
		plr->Say("I clicked the stairs", 13);
		TC_LOG_ERROR(LOG_FILTER_WORLDSERVER, "Player Faction %u", plr->getFaction());
		
		
		if(plr->GetTeamId() == 0)
		{
			if(go->FindNearestGameObject(GO_ALLIANCE_GUNSHIP, 10000.0f) == NULL)
			{
				// Alliance
				GameObject* gunship = plr->SummonGameObject(gObjectId::GO_ALLIANCE_GUNSHIP, -448.0f, 1923.0f, 193.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 600);
				Creature* temp = gunship->SummonCreature(37200, gunship->GetPositionX() + 13.51547f, gunship->GetPositionY() - 0.160213f, gunship->GetPositionZ() + 20.87252f, 3.10672f);

				
				if(gunship->ToTransport()->Create(sObjectMgr->GenerateLowGuid(HIGHGUID_MO_TRANSPORT), GO_ALLIANCE_GUNSHIP, gunship->GetMapId(), gunship->GetPositionX(), gunship->GetPositionY(), gunship->GetPositionY(), 0, 255))
				{
					TC_LOG_ERROR(LOG_FILTER_WORLDSERVER, "Alliance: gunship transport created");
					TC_LOG_ERROR(LOG_FILTER_WORLDSERVER, "Alliance: setting map");
					//gunship->ToTransport()->SetMap(gunship->GetMap());
					TC_LOG_ERROR(LOG_FILTER_WORLDSERVER, "Alliance: map set, adding to world");
					gunship->ToTransport()->GetMap()->AddToMap<Transport>(gunship->ToTransport());
					TC_LOG_ERROR(LOG_FILTER_WORLDSERVER, "Alliance: added to world");
				}else{
					TC_LOG_ERROR(LOG_FILTER_WORLDSERVER, "Alliance: gunship is no transport");
				}
			} 
		}else{
			// Horde
			if(go->FindNearestGameObject(gObjectId::GO_HORDE_GUNSHIP, 10000.0f) == NULL)
			{
				plr->SummonGameObject(gObjectId::GO_HORDE_GUNSHIP, -448.0f, 1923.0f, 193.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 10);
				TC_LOG_ERROR(LOG_FILTER_WORLDSERVER, "Horde: use of gunship stairs");
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



void AddSC_icc_gunship_battle()
{
		new GunshipStairs();
		new Gunship();
}
