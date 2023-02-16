/*
 * Made by ConanHUN for Single Player Project - Ashamane (legion) repack
 */

#include "Config.h"
#include "ScriptPCH.h"

#ifndef SC_PRECOMPILED_H
#define SC_PRECOMPILED_H

#include "ScriptMgr.h"
#include "Cell.h"
#include "CellImpl.h"
#include "GameEventMgr.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "Unit.h"
#include "GameObject.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "InstanceScript.h"
#include "ScriptMgr.h"
#include "CombatAI.h"
#include "PassiveAI.h"
#include "Chat.h"
#include "ObjectMgr.h"
#include "SpellScript.h"

#include "SpellAuraEffects.h"
#include "AccountMgr.h"
#include "ArenaTeamMgr.h"
#include "CellImpl.h"
#include "GridNotifiers.h"
#include "Group.h"
#include "InstanceSaveMgr.h"//临时注释,下同
#include "Language.h"
#include "MovementGenerator.h"
#include "ObjectAccessor.h"
#include "Opcodes.h"
#include "SpellAuras.h"
//#include "TargetedMovementGenerator.h"
#include "WeatherMgr.h"
#include "Player.h"
#include "Pet.h"
#include "LFG.h"
#include "GroupMgr.h"
#include "MMapFactory.h"
#include "DisableMgr.h"
#include "SpellHistory.h"
#include "MiscPackets.h"
#include "Transport.h"
#include "DatabaseEnv.h"
#include "World.h"
#include "WorldSession.h"
#include "Mail.h"



#ifdef _WIN32
#include <windows.h>
#endif

#endif
//
//class PandarenFaction : public PlayerScript
//{
//public:
//    PandarenFaction() : PlayerScript("PandarenFaction") { }
//
//    void OnLogin(Player* player, bool /*firstLogin*/) override
//    {
//        if (sConfigMgr->GetBoolDefault("Skip.Pandaren.Enable", true))
//        {
//            if (player->getRace() == RACE_PANDAREN_NEUTRAL)
//            {
//                player->ShowNeutralPlayerFactionSelectUI();
//            }
//        }
//    }
//};

//class Player_skybox : public PlayerScript
//{
//public:
//    Player_skybox() : PlayerScript("Player_skybox") { }
//
//
//    void OnLogin(Player* player, bool /*firstLogin*/) override
//    {
//
//        //Select Customs
//        QueryResult getDisplay = WorldDatabase.PQuery("SELECT skybox from player_skybox WHERE guid = %u", player->GetGUID().GetCounter());
//        if (!getDisplay)
//            return;
//
//        Field* field = getDisplay->Fetch();
//
//        uint32 skyboxId = field[0].GetUInt32();
//        uint32 map = player->GetMapId();
//        uint32 mapCache = player->GetMapId();
//
//            if (map)
//            {
//                if (player->GetMapId())
//                {
//                    if (MapEntry const* entry = sMapStore.AssertEntry(map))
//                        map = entry->ParentMapID;
//                }
//
//                uint32 lightId = DB2Manager::GetMapLightId(map);
//
//                WorldPacket data(SMSG_OVERRIDE_LIGHT, 12);
//                data << lightId;
//                data << skyboxId;
//                data << 200;
//
//                sWorld->SendMapMessage(mapCache, WorldPackets::Misc::OverrideLight(int32(lightId), int32(200), int32(skyboxId)).Write());
//
//            }
//            else
//            {
//                uint32 lightId = DB2Manager::GetMapLightId(map);
//
//                WorldPacket data(SMSG_OVERRIDE_LIGHT, 12);
//                data << lightId;
//                data << skyboxId;
//                data << 200;
//
//                player->GetSession()->SendPacket(&data, true);
//            }
//    }
//
//};

class playerscript_recruiter : public PlayerScript
{
public:
    playerscript_recruiter() : PlayerScript("playerscript_recruiter") {}

    void OnLogin(Player* player, bool /*firstLogin*/) override
    {
        QueryResult result = LoginDatabase.PQuery("SELECT recruiter, recruiter_rewarded FROM account WHERE id = %u", player->GetSession()->GetAccountId());
        if (!result)
            return;

        Field* fields = result->Fetch();
        uint32 recruiter = fields[0].GetUInt32();
        bool recruiterRewarded = fields[1].GetBool();

        if (recruiterRewarded)
            return;

        result = CharacterDatabase.PQuery("SELECT guid, NAME FROM characters WHERE account = %u ORDER BY totaltime DESC LIMIT 1", recruiter);
        if (!result)
            return;

        fields = result->Fetch();
        uint64 recruiterCharacterGUID = fields[0].GetUInt64();

        if (!recruiterCharacterGUID)
            return;

        //Check account ip - start
        result = LoginDatabase.PQuery("SELECT last_ip, NAME FROM account WHERE id = %u", recruiter);
        if (!result)
            return;

        QueryResult last_ip_player = LoginDatabase.PQuery("SELECT last_ip, NAME FROM account WHERE id = %u", player->GetSession()->GetAccountId());
        if (!last_ip_player)
            return;

        if (result == last_ip_player)
            return;
        //Check account ip - end

        if (player->GetLevel() <= 15)
            return;

        result = LoginDatabase.PQuery("SELECT COUNT(*) FROM account WHERE recruiter = %u AND recruiter_rewarded = 1", recruiter);
        if (!result)
            return;

        fields = result->Fetch();
        uint32 recruiterRewardCount = fields[0].GetUInt32();
        uint32 rewardItem = 0;

        switch (++recruiterRewardCount)
        {
        case 1: rewardItem = 880003;     break; // X-53 Touring Rocket
        case 2: rewardItem = 880003;     break; // Swift Zhevra
        case 5: rewardItem = 348162;    break; // Emerald Hippogryph
        default: break;
        }

        if (rewardItem)
        {
            CharacterDatabase.PExecute("INSERT INTO character_shop (guid, type, itemId, itemCount) VALUES (" UI64FMTD ", 0, %u, 1)", recruiterCharacterGUID, rewardItem);
            LoginDatabase.PExecute("UPDATE account SET recruiter_rewarded = 1 WHERE id = %u", player->GetSession()->GetAccountId());
        }
    }
};

class OnLearnFishing : public PlayerScript //Temp Fix on Fishing Skill learn
{
public:
    OnLearnFishing() : PlayerScript("OnLearnFishing") { }

    void OnLogin(Player* player, bool /*firstLogin*/) override
    {

        if (player->HasSkill(2592))
        {
            player->SetSkill(356, 0, 1, 300);
        }
        
    }

};

void AddSC_PandarenFaction()
{
  //  new PandarenFaction;
  //  new playerscript_recruiter;
    new OnLearnFishing;
}
