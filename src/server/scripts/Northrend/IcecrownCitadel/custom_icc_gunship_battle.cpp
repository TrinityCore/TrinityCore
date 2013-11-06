#include "ScriptMgr.h"
#include "GameObjectAI.h"
#include "Player.h"
#include "Transport.h" 

enum gObjectId
{
	GO_ALLIANCE_GUNSHIP = 195121,
	GO_HORDE_GUNSHIP = 195276
};

enum Spells
{
	SPELL_ALLIANCE = 70120,
	SPELL_HORDE = 70121
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
				TC_LOG_ERROR(LOG_FILTER_WORLDSERVER, "Alliance: use of gunship stairs");
				Creature* temp = gunship->SummonCreature(37200, plr->GetPositionX(), plr->GetPositionY(), plr->GetPositionZ(), 3.10672f);
				gunship->ToTransport()->AddPassenger(plr);
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

class AllianceGunship : public TransportScript
{

public:
	AllianceGunship() : TransportScript("gunship_transport") { }

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

class HordeGunship : public GameObjectScript
{
public:
	HordeGunship() : GameObjectScript("horde_gunship") { }
};


void AddSC_icc_gunship_battle()
{
		new GunshipStairs();
}