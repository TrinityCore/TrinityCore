#include "ScriptMgr.h"
#include "Player.h"
#include "InstanceScript.h"
#include "battle_of_dazaralor.h"
#include "GameObject.h"
#include "ObjectMgr.h"
#include "Conversation.h"
#include "PhasingHandler.h"

DoorData const doorData[] =
{
	{ GO_FRIDA_WALL_OF_SPEARS, DATA_FRIDA_IRONBELLOWS, DOOR_TYPE_ROOM },
	{ GO_WALL_OF_SPEARS_GRONG, DATA_GRONG, DOOR_TYPE_ROOM },
	{ GO_MEKKATORQUE_WALL_OF_SPEARS_ENTRANCE, DATA_HIGH_TINKER_MEKKATORQUE, DOOR_TYPE_ROOM },
	{ GO_MEKKATORQUE_WALL_OF_SPEARS_EXIT, DATA_HIGH_TINKER_MEKKATORQUE, DOOR_TYPE_PASSAGE },
	{ GO_RAWANI_WALL_OF_SPEARS, DATA_RAWANI_KANAE, DOOR_TYPE_ROOM },
	{ GO_JADEFIRE_MASTERS_ALLIANCE_ENTRANCE, DATA_JADEFIRE_MASTERS, DOOR_TYPE_ROOM },
	{ GO_JADEFIRE_MASTERS_ALLIANCE_EXIT, DATA_JADEFIRE_MASTERS, DOOR_TYPE_PASSAGE },
	{ GO_JADEFIRE_MASTERS_ALLIANCE_COLLISION, DATA_JADEFIRE_MASTERS, DOOR_TYPE_PASSAGE },
};

ObjectGuid frida_guid;
ObjectGuid rawani_guid;
ObjectGuid grong_guid;
ObjectGuid grong_revenant_guid;
ObjectGuid manceroy_guid;
ObjectGuid mestrah_guid;
ObjectGuid mekkatorque_guid;
ObjectGuid laminaria_guid;
ObjectGuid sister_katherine_guid;
ObjectGuid brother_joseph_guid;
ObjectGuid otoye_guid;
ObjectGuid go_rawani_collsion_horde_only_guid;
ObjectGuid jaina_guid;
ObjectGuid rastakhan_guid;
ObjectGuid go_stairs_stormwall_blockade;
ObjectGuid wallOfIceGuid;
ObjectGuid frozenOceanGuid;
ObjectGuid corsairGuid;

struct instance_battle_of_dazaralor : public InstanceScript
{
    instance_battle_of_dazaralor(InstanceMap* InstanceMap) : InstanceScript(InstanceMap), isHorde(false), isAlliance(false)
	{
		SetHeaders(DataHeader);
		SetBossNumber(EncounterCount);
        InstanceMap->GetInstanceScript();		
	}

	void Initialize() override
	{
		LoadDoorData(doorData);
	}

	void OnPlayerEnter(Player* player)
	{
		if (isHorde == true || isAlliance == true)
		{
			/*if (player->GetTeam() == HORDE)
				player->TeleportTo(2070, -417.682f, 1191.241f, 320.289f, 3.113f);
			else
				player->TeleportTo(2070, -2250.870f, 803.828f, 5.919f, 0.000f);*/
		}
		else
		{
			if (player->GetTeam() == HORDE)
			{
				isHorde = true;
				//player->TeleportTo(2070, -417.682f, 1191.241f, 320.289f, 3.113f);

                if (InstanceScript* script = instance->GetInstanceScript())
                {					
					if (script->GetBossState(DATA_FRIDA_IRONBELLOWS) != DONE && player->GetAreaId() == 10370)
						player->SendMovieStart(876);
                }
                
                player->GetSceneMgr().RecreateScene(SCENE_CORPSES, SCENEFLAG_NOT_CANCELABLE | SCENEFLAG_UNK16);
                player->GetSceneMgr().RecreateScene(SCENE_BATTLEFIELD_ACTION, SCENEFLAG_NOT_CANCELABLE | SCENEFLAG_UNK16);

				Conversation::CreateConversation(BOD_CONVERSATION_1, player, player->GetPosition(), { player->GetGUID() });
			}
			if (player->GetTeam() == ALLIANCE)
			{
				isAlliance = true;				

                if (InstanceScript* script = instance->GetInstanceScript())
                {
					if (script->GetBossState(DATA_RAWANI_KANAE) != DONE && player->GetAreaId() == 10375)
						player->SendMovieStart(876);
                }
	
				player->GetSceneMgr().RecreateScene(SCENE_ALLIANCE_LANDING, SCENEFLAG_NOT_CANCELABLE | SCENEFLAG_UNK16);
				player->GetSceneMgr().RecreateScene(SCENE_ALLIANCE_LANDING_2, SCENEFLAG_NOT_CANCELABLE | SCENEFLAG_UNK16);
                player->GetSceneMgr().RecreateScene(SCENE_CORPSES, SCENEFLAG_NOT_CANCELABLE | SCENEFLAG_UNK16);
                player->GetSceneMgr().RecreateScene(SCENE_BATTLEFIELD_ACTION, SCENEFLAG_NOT_CANCELABLE | SCENEFLAG_UNK16);

				Conversation::CreateConversation(BOD_CONVERSATION_2, player, player->GetPosition(), { player->GetGUID() });
			}
		}
		/**********************************************************************************************************************************************/
		if (isHorde == true)
		{			
		}
		if (isAlliance == true)
		{
		}
	}

	void OnPlayerExit(Player* player)
	{
		player->GetSceneMgr().CancelSceneByPackageId(SCENE_CORPSES);
		player->GetSceneMgr().CancelSceneByPackageId(SCENE_BATTLEFIELD_ACTION);
		player->GetSceneMgr().CancelSceneByPackageId(SCENE_ALLIANCE_LANDING);
		player->GetSceneMgr().CancelSceneByPackageId(SCENE_ALLIANCE_LANDING_2);
		player->GetSceneMgr().CancelSceneByPackageId(SCENE_CORPSES);
		//This should remove black screens
		player->GetSceneMgr().RemoveAurasDueToSceneId(2219);
		player->GetSceneMgr().RemoveAurasDueToSceneId(2200);
		player->GetSceneMgr().RemoveAurasDueToSceneId(2185);
		player->GetSceneMgr().RemoveAurasDueToSceneId(2178);
		player->GetSceneMgr().RemoveAurasDueToSceneId(2224);
	}

	void OnCreatureCreate(Creature* creature) override
	{
		switch (creature->GetEntry())
		{
		case NPC_FRIDA_IRONBELLOWS:
			frida_guid = creature->GetGUID();
			break;

		case NPC_RAWANI_KANAE:
			rawani_guid = creature->GetGUID();
			break;

		case NPC_GRONG:
			grong_guid = creature->GetGUID();
			break;

		case NPC_MANCEROY_FLAMEFIST:
			manceroy_guid = creature->GetGUID();
			break;

		case NPC_MESTRAH:
			mestrah_guid = creature->GetGUID();
			break;

		case NPC_HIGH_TINKER_MEKKATORQUE:
			 mekkatorque_guid = creature->GetGUID();
			 break;

		case NPC_LAMINARIA:
			laminaria_guid = creature->GetGUID();
			break;

		case NPC_SISTER_KATHERINE:
			sister_katherine_guid = creature->GetGUID();
			break;

		case NPC_BROTHER_JOSEPH:
			brother_joseph_guid = creature->GetGUID();
			break;

		case NPC_LADY_JAINA_PROUDMOORE:
			jaina_guid = creature->GetGUID();
			break;

		case NPC_KING_RASTAKHAN:
			rastakhan_guid = creature->GetGUID();
			break;

		case NPC_DARKFORGED_CRUSADER:
		case NPC_ZANDALARI_CRUSADER:
			creature->SetBaseHealth(creature->GetMaxHealth() * 4.0f);
			break;

		case 146369:
			creature->SetDisplayId(90007, creature->GetNativeDisplayScale());
			break;

		case NPC_BWONSAMDI:
			creature->SetVisible(false);
			break;

		case NPC_OTOYE:
			otoye_guid = creature->GetGUID();
			break;

		case NPC_JAINA_WALL_OF_ICE:
			wallOfIceGuid = creature->GetGUID();
			creature->SetVisible(false);
			break;

		case NPC_KUL_TIRAN_CORSAIR:
			corsairGuid = creature->GetGUID();
			break;
		}
	}

	void OnGameObjectCreate(GameObject* go) override
	{
		switch (go->GetEntry())
		{
		case GO_EXPEDITION_STRONGBOX_GRONG:
			go->SetFlags(GO_FLAG_LOCKED);
			break;

		case GO_ZULDAZAR_RAID_INTERIOR_ELEVATOR:
			go->SetGoState(GO_STATE_TRANSPORT_ACTIVE);
			break;

		case GO_RAWANI_COLLISION_HORDE_ONLY_1:
		case GO_RAWANI_COLLISION_HORDE_ONLY_2:
			go_rawani_collsion_horde_only_guid = go->GetGUID();
			break;
		}
	}

private:
	bool isHorde;
	bool isAlliance;
	TaskScheduler scheduler;
};

void AddSC_instance_battle_of_dazaralor()
{
	RegisterInstanceScript(instance_battle_of_dazaralor, 2070);
}
