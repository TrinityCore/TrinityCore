////LegionPlayerBot
//#include "PlayerBotMgr.h"
//#include "World.h"
//#include "DB2Stores.h"
//#include "Player.h"
//#include "BattlegroundMgr.h"
//#include "BotAI.h"
//#include "BotFieldAI.h"
//#include "BotGroupAI.h"
//#include "BotDuelAI.h"
//#include "BotArenaAI.h"
//#include "OnlineMgr.h"
//#include "Group.h"
//#include "SocialMgr.h"
//#include "LFGMgr.h"
//#include "Config.h"
//#include "PlayerBotSession.h"
//#include "AccountMgr.h"
//#include "CharacterPackets.h"
//
//#include <boost/algorithm/string.hpp>
////#include <boost/format.hpp>
//
//PlayerBotCharBaseInfo PlayerBotBaseInfo::empty;
//std::map<uint32, std::list<UnitAI*> > PlayerBotMgr::m_DelayDestroyAIs;
//std::mutex PlayerBotMgr::g_uniqueLock;
//
//std::string PlayerBotCharBaseInfo::GetNameANDClassesText()
//{
//    //std::string clsName;
//    uint32 clsEntry = 620000;
//    switch (profession)
//    {
//    case 1:
//        //clsName = "  战  士 : ";
//        clsEntry += 1;
//        break;
//    case 2:
//        //clsName = "  圣骑士 : ";
//        clsEntry += 2;
//        break;
//    case 3:
//        //clsName = "  猎  人 : ";
//        clsEntry += 3;
//        break;
//    case 4:
//        //clsName = "  盗  贼 : ";
//        clsEntry += 4;
//        break;
//    case 5:
//        //clsName = "  牧  师 : ";
//        clsEntry += 5;
//        break;
//    case 6:
//        //clsName = "  死  骑 : ";
//        clsEntry += 6;
//        break;
//    case 7:
//        //clsName = "  萨  满 : ";
//        clsEntry += 7;
//        break;
//    case 8:
//        //clsName = "  法  师 : ";
//        clsEntry += 8;
//        break;
//    case 9:
//        //clsName = "  术  士 : ";
//        clsEntry += 9;
//        break;
//    case 11:
//        //clsName = "  德鲁伊 : ";
//        clsEntry += 10;
//        break;
//    }
//    std::string clsText = sObjectMgr->GetTrinityStringForDBCLocale(clsEntry);
//    //consoleToUtf8(clsName, clsText);
//    return clsText + name;
//}
//
//uint32 PlayerBotBaseInfo::GetCharIDByNoArenaType(bool faction, uint32 prof, uint32 arenaType, std::vector<ObjectGuid>& fliters)
//{
//    for (ObjectGuid& guid : fliters)
//    {
//        if (ExistCharacterByGUID(guid))
//            return 0;
//    }
//    if (characters.size() <= 0)
//        return 0;
//    for (CharInfoMap::iterator it = characters.begin();
//        it != characters.end();
//        it++)
//    {
//        if (!MatchRaceByFuction(faction, it->second.race))
//            continue;
//        if (it->second.profession != prof)
//            continue;
//    }
//    return 0;
//}
//
//PlayerBotMgr::PlayerBotMgr() :
//    m_BotAccountAmount(90),
//    m_LastBotAccountIndex(0),
//    m_MaxOnlineBot(10),
//    m_BotOnlineCount(0),
//    m_LFGSearchTick(0),
//    m_ArenaSearchTick(0)
//{
//    m_BGTypes.push_back(MS::Battlegrounds::BattlegroundTypeId::BattlegroundWarsongGulch);
//    m_BGTypes.push_back(MS::Battlegrounds::BattlegroundTypeId::BattlegroundArathiBasin);
//    m_BGTypes.push_back(MS::Battlegrounds::BattlegroundTypeId::BattlegroundEyeOfTheStorm);
//#ifndef NON_SINGLE_GAME
//    m_BGTypes.push_back(MS::Battlegrounds::BattlegroundTypeId::BattlegroundAlteracValley);
//    m_BGTypes.push_back(MS::Battlegrounds::BattlegroundTypeId::BattlegroundIsleOfConquest);
//    m_BGTypes.push_back(MS::Battlegrounds::BattlegroundTypeId::BattlegroundRandom);
//
//    m_BGTypes.push_back(MS::Battlegrounds::BattlegroundTypeId::ArenaOldNagrandArena);
//    m_BGTypes.push_back(MS::Battlegrounds::BattlegroundTypeId::ArenaOldBladesEdgeArena);
//    m_BGTypes.push_back(MS::Battlegrounds::BattlegroundTypeId::ArenaRuinsOfLordaeron);
//    m_BGTypes.push_back(MS::Battlegrounds::BattlegroundTypeId::ArenaOldRingOfValor);
//    m_BGTypes.push_back(MS::Battlegrounds::BattlegroundTypeId::ArenaBladesEdge);
//    m_BGTypes.push_back(MS::Battlegrounds::BattlegroundTypeId::ArenaAll);
//    //m_BGTypes.push_back(BattlegroundTypeId::BATTLEGROUND_SA);
//#endif
//}
//
//PlayerBotMgr::~PlayerBotMgr()
//{
//    ClearBaseInfo();
//}
//
//PlayerBotMgr* PlayerBotMgr::instance()
//{
//    static PlayerBotMgr instance;
//    return &instance;
//}
//
//void PlayerBotMgr::SwitchPlayerBotAI(Player* player, PlayerBotAIType aiType, bool force)
//{
//    if (!force && player->isInCombat())
//        return;
//    if (force && player->isInCombat())
//        player->ClearInCombat();
//    player->SetSelection(ObjectGuid::Empty);
//    UnitAI* pAI = player->GetAI();
//    player->IsAIEnabled = false;
//    switch (aiType)
//    {
//    case PlayerBotAIType::PBAIT_FIELD:
//        if (pAI)
//        {
//            if (dynamic_cast<BotFieldAI*>(pAI) != NULL)
//            {
//                player->IsAIEnabled();
//                return;
//            }
//            PlayerBotMgr::m_DelayDestroyAIs[getMSTime()].push_back(pAI);
//            player->SetAI(NULL);
//        }
//        pAI = BotFieldAI::CreateBotFieldAIByPlayerClass(player);
//        if (pAI)
//        {
//            pAI->Reset();
//            player->SetAI(pAI);
//            player->IsAIEnabled();
//        }
//        break;
//    case PlayerBotAIType::PBAIT_GROUP:
//        if (pAI)
//        {
//            if (dynamic_cast<BotGroupAI*>(pAI) != NULL)
//            {
//                player->IsAIEnabled();
//                return;
//            }
//            PlayerBotMgr::m_DelayDestroyAIs[getMSTime()].push_back(pAI);
//            player->SetAI(NULL);
//        }
//        pAI = BotGroupAI::CreateBotGroupAIByPlayerClass(player);
//        if (pAI)
//        {
//            pAI->Reset();
//            player->SetAI(pAI);
//            player->IsAIEnabled();
//        }
//        break;
//    case PlayerBotAIType::PBAIT_DUEL:
//        if (pAI)
//        {
//            if (dynamic_cast<BotDuelAI*>(pAI) != NULL)
//            {
//                player->IsAIEnabled();
//                return;
//            }
//            PlayerBotMgr::m_DelayDestroyAIs[getMSTime()].push_back(pAI);
//            player->SetAI(NULL);
//        }
//        pAI = BotDuelAI::CreateBotDuelAIByPlayerClass(player);
//        if (pAI)
//        {
//            pAI->Reset();
//            player->SetAI(pAI);
//            player->IsAIEnabled();
//            ((BotDuelAI*)pAI)->ResetBotAI();
//        }
//        break;
//    case PlayerBotAIType::PBAIT_ARENA:
//#ifndef CONVERT_ARENAAI_TOBG
//        if (pAI)
//        {
//            if (dynamic_cast<BotArenaAI*>(pAI) != NULL)
//            {
//                player->IsAIEnabled();
//                return;
//            }
//            PlayerBotMgr::m_DelayDestroyAIs[getMSTime()].push_back(pAI);
//            player->SetAI(NULL);
//        }
//        pAI = BotArenaAI::CreateBotArenaAIByPlayerClass(player);
//        if (pAI)
//        {
//            pAI->Reset();
//            player->SetAI(pAI);
//            player->IsAIEnabled();
//        }
//        break;
//#endif
//    case PlayerBotAIType::PBAIT_BG:
//        if (pAI)
//        {
//            if (dynamic_cast<BotBGAI*>(pAI) != NULL)
//            {
//                player->IsAIEnabled();
//                return;
//            }
//            PlayerBotMgr::m_DelayDestroyAIs[getMSTime()].push_back(pAI);
//            player->SetAI(NULL);
//        }
//        player->SetAI(BotBGAI::CreateBotBGAIByPlayerClass(player));
//        player->IsAIEnabled();
//        break;
//    case PlayerBotAIType::PBAIT_DUNGEON:
//        if (pAI)
//        {
//            //if (dynamic_cast<BotFieldAI*>(pAI) != NULL)
//            //{
//            //	player->IsAIEnabled();
//            //	return;
//            //}
//            PlayerBotMgr::m_DelayDestroyAIs[getMSTime()].push_back(pAI);
//            player->SetAI(NULL);
//        }
//        break;
//    }
//}
//
//std::string PlayerBotMgr::GetPlayerLinkText(Player const* player) const
//{
//    const std::string& name = player->GetName();
//    if (player->GetTeamId() == TeamId::TEAM_ALLIANCE)
//        return "|cff0000ff|Hplayer:" + name + "|h[" + name + "]|h|r";
//    else if (player->GetTeamId() == TeamId::TEAM_HORDE)
//        return "|cffff0000|Hplayer:" + name + "|h[" + name + "]|h|r";
//    return "|cffffffff|Hplayer:" + name + "|h[" + name + "]|h|r";
//}
//
//PlayerBotSession* PlayerBotMgr::GetBotSessionByCharGUID(ObjectGuid& guid)
//{
//    for (std::map<uint32, PlayerBotBaseInfo*>::iterator itInfo = m_idPlayerBotBase.begin();
//        itInfo != m_idPlayerBotBase.end();
//        itInfo++)
//    {
//        PlayerBotBaseInfo* pInfo = itInfo->second;
//        if (!(pInfo->ExistCharacterByGUID(guid)))
//            continue;
//        WorldSession* pWorldSession = sWorld->FindSession(pInfo->id).get();
//        if (!pWorldSession)
//            return NULL;
//        PlayerBotSession* pSession = dynamic_cast<PlayerBotSession*>(pWorldSession);
//        return pSession;
//    }
//    return NULL;
//}
//
//TeamId PlayerBotMgr::GetTeamIDByPlayerBotGUID(ObjectGuid& guid)
//{
//    for (std::map<uint32, PlayerBotBaseInfo*>::iterator itInfo = m_idPlayerBotBase.begin();
//        itInfo != m_idPlayerBotBase.end();
//        itInfo++)
//    {
//        PlayerBotBaseInfo* pInfo = itInfo->second;
//        TeamId team = pInfo->GetTeamIDByChar(guid);
//        if (team == TeamId::TEAM_NEUTRAL)
//            continue;
//        return team;
//    }
//    return TeamId::TEAM_NEUTRAL;
//}
//
//bool PlayerBotMgr::IsPlayerBot(WorldSession* pSession)
//{
//    if (pSession && dynamic_cast<PlayerBotSession*> (pSession))
//        return true;
//    return false;
//}
//
//bool PlayerBotMgr::IsBotAccuntName(std::string name)
//{
//    if (name.size() < 10)
//        return false;
//    std::string head = name.substr(0, 9);
//    if (head != "playerbot")
//        return false;
//    std::string numText = name.substr(9);
//    int num = atoi(numText.c_str());
//    return num > 0;
//}
//
//bool PlayerBotMgr::IsIDLEPlayerBot(Player* player)
//{
//    if (!player || player->isBeingLoaded() || !player->IsInWorld())
//        return false;
//    if (player->isInCombat() || !player->isAlive())
//        return false;
//    if (player->InBattleground() || player->InArena() || player->GetMap()->IsDungeon() ||
//        player->GetGroup() || player->isUsingLfg())
//        return false;
//    if (player->InBattlegroundQueue())
//        return false;
//    if (!player->IsSettingFinish())
//        return false;
//    if (player->HasAura(26013))
//        return false;
//    return true;
//}
//
//std::set<uint32> PlayerBotMgr::GetArenaTeamPlayerBotIDCountByTeam(TeamId team, int32 count, ArenaTeamTypes type)
//{
//    std::vector<uint32> allInfoEntrys;
//    for (std::map<uint32, PlayerBotBaseInfo*>::iterator itInfo = m_idPlayerBotBase.begin(); itInfo != m_idPlayerBotBase.end(); itInfo++)
//        allInfoEntrys.push_back(itInfo->first);
//    Trinity::Containers::RandomShuffle(allInfoEntrys);
//    //unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
//    //std::shuffle(allInfoEntrys.begin(), allInfoEntrys.end(), std::default_random_engine(seed));
//
//    std::set<uint32> ids;
//    if (allInfoEntrys.empty())
//        return ids;
//    for (uint32 infoEntry : allInfoEntrys)
//    {
//        PlayerBotBaseInfo* info = GetPlayerBotAccountInfo(infoEntry);
//        if (!info)
//            continue;
//        std::vector<uint32> faildIDs = info->GetNoArenaTeamCharacterIDsByFuction((team == TEAM_ALLIANCE) ? true : false, type);
//        if (faildIDs.empty())
//            continue;
//        for (uint32 id : faildIDs)
//        {
//            if (ids.find(id) != ids.end())
//                continue;
//            ids.insert(id);
//            break;
//        }
//        if (ids.size() >= uint32(count))
//            return ids;
//    }
//    ids.clear();
//    return ids;
//}
//
//PlayerBotBaseInfo* PlayerBotMgr::GetPlayerBotAccountInfo(uint32 guid)
//{
//    std::map<uint32, PlayerBotBaseInfo*>::iterator it = m_idPlayerBotBase.find(guid);
//    if (it == m_idPlayerBotBase.end())
//        return NULL;
//    return it->second;
//}
//
//PlayerBotBaseInfo* PlayerBotMgr::GetAccountBotAccountInfo(uint32 guid)
//{
//    std::map<uint32, PlayerBotBaseInfo*>::iterator it = m_idAccountBotBase.find(guid);
//    if (it == m_idAccountBotBase.end())
//        return NULL;
//    return it->second;
//}
//
//bool PlayerBotMgr::ExistClassByRace(uint8 race, uint8 prof)
//{
//    switch (prof)
//    {
//    case 1:
//        return (race != 10);
//    case 2:
//        return (race == 1 || race == 3 || race == 10 || race == 11);
//    case 3:
//        return (race == 2 || race == 3 || race == 4 || race == 6 || race == 8 || race == 10 || race == 11);
//    case 4:
//        return (race == 1 || race == 2 || race == 3 || race == 4 || race == 5 || race == 7 || race == 8 || race == 10);
//    case 5:
//        return (race == 1 || race == 3 || race == 4 || race == 5 || race == 8 || race == 10 || race == 11);
//    case 6:
//        return true;
//    case 7:
//        return (race == 2 || race == 6 || race == 8 || race == 11);
//    case 8:
//        return (race == 1 || race == 5 || race == 7 || race == 8 || race == 10 || race == 11);
//    case 9:
//        return (race == 1 || race == 2 || race == 5 || race == 7 || race == 10);
//    case 11:
//        return (race == 4 || race == 6);
//    }
//    return false;
//}
//void PlayerBotMgr::InitializeCreatePlayerBotName()
//{
//    allName.clear();
//    PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_ALLRANDOM_NAME);
//    PreparedQueryResult result = LoginDatabase.Query(stmt);
//    if (result)
//    {
//        do
//        {
//            Field* fields = result->Fetch();
//            std::string dbName = fields[0].GetString();
//            if (dbName.size() > 0)
//                allName.push_back(dbName);
//        } while (result->NextRow());
//    }
//
//    allArenaName.clear();
//    PreparedStatement* stmt2 = LoginDatabase.GetPreparedStatement(LOGIN_SEL_ALLARENA_NAME);
//    PreparedQueryResult result2 = LoginDatabase.Query(stmt2);
//    if (result2)
//    {
//        do
//        {
//            Field* fields = result2->Fetch();
//            std::string dbName = fields[0].GetString();
//            if (dbName.size() > 0)
//                allArenaName.push_back(dbName);
//        } while (result2->NextRow());
//    }
//}
//std::string PlayerBotMgr::RandomName()
//{
//    if (allName.size() <= 0)
//        InitializeCreatePlayerBotName();
//    int32 maxLoop = allName.size() / 2;
//    if (maxLoop <= 0)
//        return "";
//    do
//    {
//        uint32 index = irand(0, allName.size() - 1);
//        std::string selectName = allName[index];
//        std::string sql = "SELECT guid FROM characters WHERE name = '" + selectName + "'";
//        QueryResult result = CharacterDatabase.Query(sql.c_str());
//        if (!result)
//            return selectName;
//        --maxLoop;
//        if (maxLoop <= 0)
//            break;
//    } while (true);
//    return "";
//}
//std::string PlayerBotMgr::RandomArenaName()
//{
//    return "Arena" + std::to_string(urand(0, 100));
//}
//uint8 PlayerBotMgr::RandomRace(bool group, uint8 prof)
//{
//    uint8 race = 1;
//    for (int i = 0; i < 80; i++)
//    {
//        race = irand(1, 11);
//        if (race == 9) continue;
//        if (group)
//        {
//            if (race == 1 || race == 3 || race == 4 || race == 7 || race == 11)
//            {
//                if (ExistClassByRace(race, prof))
//                    return race;
//            }
//        }
//        else
//        {
//            if (race == 2 || race == 5 || race == 6 || race == 8 || race == 10)
//            {
//                if (ExistClassByRace(race, prof))
//                    return race;
//            }
//        }
//    }
//
//    TC_LOG_INFO(LOG_FILTER_PLAYER, "server.loading", ">> Random player custom Race timeout!");
//    if (group)
//        return 1;
//    return 2;
//}
//uint8 PlayerBotMgr::RandomSkinColor(uint8 race, uint8 gender, uint8 prof)
//{
//    uint8 skinColor = 0;
//    for (int i = 0; i < 80; i++)
//    {
//        skinColor = irand(0, 9);
//        CharSectionsEntry const* entry = sDB2Manager.GetCharSectionEntry(race, gender, CharBaseSectionVariation::Skin, 0, skinColor);
//        if (entry)
//        {
//            if ((entry->Flags & SECTION_FLAG_DEATH_KNIGHT) && prof != CLASS_DEATH_KNIGHT)
//                continue;
//            if (!(entry->Flags & SECTION_FLAG_PLAYER))
//                continue;
//            return skinColor;
//        }
//    }
//    TC_LOG_INFO(LOG_FILTER_PLAYER, "server.loading", ">> Random player custom SkinColor timeout!");
//    return 1;
//}
//uint8 PlayerBotMgr::RandomFace(uint8 race, uint8 gender, uint8 skinColor, uint8 prof)
//{
//    uint8 faceID = 0;
//    for (int i = 0; i < 80; i++)
//    {
//        faceID = irand(0, 9);
//        CharSectionsEntry const* entry = sDB2Manager.GetCharSectionEntry(race, gender, CharBaseSectionVariation::Face, faceID, skinColor);
//        if (entry)
//        {
//            if ((entry->Flags & SECTION_FLAG_DEATH_KNIGHT) && prof != CLASS_DEATH_KNIGHT)
//                continue;
//            if (!(entry->Flags & SECTION_FLAG_PLAYER))
//                continue;
//            return faceID;
//        }
//    }
//    TC_LOG_INFO(LOG_FILTER_PLAYER, "server.loading", ">> Random player custom Face timeout!");
//    return 1;
//}
//uint8 PlayerBotMgr::RandomHair(uint8 race, uint8 gender, uint8 prof)
//{
//    uint8 hairID = 0;
//    for (uint8 hc = 0; hc < 80; hc++)
//    {
//        for (int i = 0; i < 80; i++)
//        {
//            hairID = irand(0, 8);
//            CharSectionsEntry const* entry = sDB2Manager.GetCharSectionEntry(race, gender, CharBaseSectionVariation::Hair, hairID, hc);
//            if (entry)
//            {
//                if ((entry->Flags & SECTION_FLAG_DEATH_KNIGHT) && prof != CLASS_DEATH_KNIGHT)
//                    continue;
//                if (!(entry->Flags & SECTION_FLAG_PLAYER))
//                    continue;
//                return hairID;
//            }
//        }
//    }
//    TC_LOG_INFO(LOG_FILTER_PLAYER, "server.loading", ">> Random player custom Hair timeout!");
//    return 0;
//}
//uint8 PlayerBotMgr::RandomHairColor(uint8 race, uint8 gender, uint8 hairID, uint8 prof)
//{
//    uint8 hairColor = 0;
//    for (int i = 0; i < 80; i++)
//    {
//        hairColor = irand(0, 8);
//        CharSectionsEntry const* entry = sDB2Manager.GetCharSectionEntry(race, gender, CharBaseSectionVariation::Hair, hairID, hairColor);
//        if (entry)
//        {
//            if ((entry->Flags & SECTION_FLAG_DEATH_KNIGHT) && prof != CLASS_DEATH_KNIGHT)
//                continue;
//            if (!(entry->Flags & SECTION_FLAG_PLAYER))
//                continue;
//            return hairColor;
//        }
//    }
//    TC_LOG_INFO(LOG_FILTER_PLAYER, "server.loading", ">> Random player custom HairColor timeout!");
//    return 1;
//}
//uint8 PlayerBotMgr::RandomFacialHair(uint8 race, uint8 gender, uint8 hairColor, uint8 prof)
//{
//    uint8 facialHair = 0;
//    for (int i = 0; i < 80; i++)
//    {
//        facialHair = irand(0, 7);
//        CharSectionsEntry const* entry = sDB2Manager.GetCharSectionEntry(race, gender, CharBaseSectionVariation::FacialHair, facialHair, hairColor);
//        if (entry)
//        {
//            if ((entry->Flags & SECTION_FLAG_DEATH_KNIGHT) && prof != CLASS_DEATH_KNIGHT)
//                continue;
//            if (!(entry->Flags & SECTION_FLAG_PLAYER))
//                continue;
//            return facialHair;
//        }
//    }
//    TC_LOG_INFO(LOG_FILTER_PLAYER, "server.loading", ">> Random player custom FacialHair timeout!");
//    return 0;
//}
//
//WorldPacket PlayerBotMgr::BuildCreatePlayerData(bool group, uint8 prof)
//{
//    std::string name = RandomName();
//    uint8 race = RandomRace(group, prof);
//    uint8 gender = irand(0, 1);
//    uint8 skinColor = RandomSkinColor(race, gender, prof);
//    uint8 faceID = RandomFace(race, gender, skinColor, prof);
//    uint8 hairID = RandomHair(race, gender, prof);
//    uint8 hairColor = RandomHairColor(race, gender, hairID, prof);
//    uint8 facialHair = RandomFacialHair(race, gender, hairColor, prof);
//    WorldPacket cmd(0x36);
//    cmd << name;
//    cmd << race;
//    cmd << prof;
//    cmd << gender;
//    cmd << skinColor;
//    cmd << faceID;
//    cmd << hairID;
//    cmd << hairColor;
//    cmd << facialHair;
//    cmd << 0;//OutfitId
//
//    return cmd;
//}
//
//void PlayerBotMgr::CreateOncePlayerBot()
//{
//    for (std::map<uint32, PlayerBotBaseInfo*>::iterator it = m_idPlayerBotBase.begin();
//        it != m_idPlayerBotBase.end();
//        it++)
//    {
//        PlayerBotBaseInfo* pInfo = it->second;
//        if (pInfo->needCreateBots.size() > 0)
//        {
//            WorldPacket& packet = pInfo->needCreateBots.front();
//            WorldSession* pSession = sWorld->FindSession(pInfo->id).get();
//            if (pSession)
//            {
//                //std::shared_ptr<CharacterCreateInfo> CreateInfo;
//                //pSession->HandleCharCreateOpcode(packet);
//            }
//            pInfo->needCreateBots.pop();
//            break;
//        }
//    }
//}
//
//void PlayerBotMgr::ClearBaseInfo()
//{
//    for (std::map<uint32, PlayerBotBaseInfo*>::iterator it = m_idPlayerBotBase.begin();
//        it != m_idPlayerBotBase.end();
//        it++)
//    {
//        delete it->second;
//    }
//    m_idPlayerBotBase.clear();
//    for (std::map<uint32, PlayerBotBaseInfo*>::iterator it = m_idAccountBotBase.begin();
//        it != m_idAccountBotBase.end();
//        it++)
//    {
//        delete it->second;
//    }
//    m_idAccountBotBase.clear();
//}
//
//void PlayerBotMgr::UpdateLastAccountIndex(std::string& username)
//{
//    //std::unique_lock<std::mutex> sessionGuard(PlayerBotMgr::g_uniqueLock);
//    if (username.empty())
//        return;
//    std::string querySql = "SELECT id FROM account WHERE username='" + username + "'";
//    QueryResult result = LoginDatabase.Query(querySql.c_str());
//    if (result)
//    {
//        Field* fields = result->Fetch();
//        if (fields)
//        {
//            uint32 id = fields[0].GetUInt32();
//            m_LastBotAccountIndex = id;
//        }
//    }
//}
//
//void PlayerBotMgr::SupplementAccount()
//{
//    uint32 needAccount = m_BotAccountAmount * 2 - m_idPlayerBotBase.size();
//    if (needAccount <= 0)
//        return;
//
//    for (uint32 i = 0; i < needAccount; i++)
//    {
//        ++m_LastBotAccountIndex;
//        char indexText[25] = { 0 };
//        itoa(m_LastBotAccountIndex, indexText, 10);
//        std::string userName = "playerbot";
//        userName += indexText;
//        if (AccountMgr::CreateAccount(userName, "botxxx") == AccountOpResult::AOR_OK)
//        {
//            std::string querySql = "SELECT id, username, sha_pass_hash FROM account WHERE username='";
//            querySql += userName + "'";
//            QueryResult result = LoginDatabase.Query(querySql.c_str());
//            if (result)
//            {
//                Field* fields = result->Fetch();
//                if (fields)
//                {
//                    uint32 id = fields[0].GetUInt32();
//                    std::string username = fields[1].GetString();
//                    std::string pass = fields[2].GetString();
//
//                    std::string lowerName = boost::algorithm::to_lower_copy(username);
//                    if (m_idPlayerBotBase.find(id) == m_idPlayerBotBase.end())
//                    {
//                        PlayerBotBaseInfo* pInfo = new PlayerBotBaseInfo(id, username.c_str(), pass, false);
//                        m_idPlayerBotBase[id] = pInfo;
//                    }
//                    m_LastBotAccountIndex = id;
//                }
//            }
//        }
//    }
//}
//
//void PlayerBotMgr::DestroyBotMail(uint32 guid)
//{
//    char sql[256] = { 0 };
//    sprintf_s(sql, 255, "DELETE FROM mail WHERE receiver = %d", guid);
//    CharacterDatabase.Execute(sql);
//    //memset(sql, 0, 256);
//    //sprintf_s(sql, 255, "DELETE FROM mail_items WHERE receiver = %d", guid);
//    //CharacterDatabase.Execute(sql);
//    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_MAIL_ITEMS);
//    stmt->setUInt32(0, guid);
//    CharacterDatabase.Execute(stmt);
//}
//
//void PlayerBotMgr::AddNewAccountBotBaseInfo(std::string name)
//{
//    std::string upperName = boost::algorithm::to_upper_copy(name);
//    std::string sql("SELECT id, username, sha_pass_hash FROM account WHERE `username`='"); sql += upperName + "'";
//    QueryResult result = LoginDatabase.Query(sql.c_str());
//    if (!result)
//        return;
//    Field* fields = result->Fetch();
//    uint32 id = fields[0].GetUInt32();
//    std::string username = fields[1].GetString();
//    std::string pass = fields[2].GetString();
//    if (m_idAccountBotBase.find(id) == m_idAccountBotBase.end())
//    {
//        PlayerBotBaseInfo* pInfo = new PlayerBotBaseInfo(id, username.c_str(), pass, true);
//        m_idAccountBotBase[id] = pInfo;
//    }
//}
//
//void PlayerBotMgr::LoadPlayerBotBaseInfo()
//{
//    uint32 oldMSTime = getMSTime();
//
//    ClearBaseInfo();
//    QueryResult result = LoginDatabase.Query("SELECT id, username, sha_pass_hash FROM account");
//    if (!result)
//    {
//        TC_LOG_INFO(LOG_FILTER_PLAYER, "server.loading", ">> LoadPlayerBot Find 0 account!");
//        return;
//    }
//
//    do
//    {
//        Field* fields = result->Fetch();
//
//        uint32 id = fields[0].GetUInt32();
//        std::string username = fields[1].GetString();
//        std::string pass = fields[2].GetString();
//        sOnlineMgr->AddNewAccount(id, username); // Real player acc and bot acc all in
//
//        std::string lowerName = boost::algorithm::to_lower_copy(username);
//        if (IsBotAccuntName(lowerName))
//        {
//            if (m_idPlayerBotBase.find(id) == m_idPlayerBotBase.end())
//            {
//                PlayerBotBaseInfo* pInfo = new PlayerBotBaseInfo(id, username.c_str(), pass, false);
//                m_idPlayerBotBase[id] = pInfo;
//            }
//            m_LastBotAccountIndex = id;
//        }
//        else
//        {
//            if (m_idAccountBotBase.find(id) == m_idAccountBotBase.end())
//            {
//                PlayerBotBaseInfo* pInfo = new PlayerBotBaseInfo(id, username.c_str(), pass, true);
//                m_idAccountBotBase[id] = pInfo;
//            }
//        }
//        //if (m_idPlayerBotBase.size() >= m_BotAccountAmount * 2)
//        //	break;
//    } while (result->NextRow());
//
//    SupplementAccount();
//
//    if (m_idPlayerBotBase.size() > 0 || m_idAccountBotBase.size() > 0)
//        LoadCharBaseInfo();
//
//    TC_LOG_INFO(LOG_FILTER_PLAYER, "server.loading", ">> Loaded %u Player bot account base info in %u ms", m_idPlayerBotBase.size(), GetMSTimeDiffToNow(oldMSTime));
//}
//
//void PlayerBotMgr::LoadCharBaseInfo()
//{
//    QueryResult result = CharacterDatabase.Query("SELECT guid, account, name, race, class, gender, level FROM characters");
//
//    if (!result)
//    {
//        TC_LOG_INFO(LOG_FILTER_PLAYER, "server.loading", ">> LoadPlayerBot Find 0 characters!");
//        return;
//    }
//
//    do
//    {
//        Field* fields = result->Fetch();
//
//        uint64 guid = fields[0].GetUInt64();
//        uint32 accID = fields[1].GetUInt32();
//        PlayerBotBaseInfo* pInfo = GetPlayerBotAccountInfo(accID);
//        if (pInfo)
//        {
//            if (pInfo->characters.find(guid) == pInfo->characters.end())
//            {
//                std::string charName = fields[2].GetString();
//                uint16 race = fields[3].GetInt16();
//                uint16 pro = fields[4].GetInt16();
//                uint16 gender = fields[5].GetInt16();
//                uint16 level = fields[6].GetInt16();
//                pInfo->characters.emplace(guid, PlayerBotCharBaseInfo{ guid, accID, charName, race, pro, gender, level });
//                DestroyBotMail(guid);
//            }
//        }
//        else if (pInfo = GetAccountBotAccountInfo(accID))
//        {
//            if (pInfo->characters.find(guid) == pInfo->characters.end())
//            {
//                std::string charName = fields[2].GetString();
//                uint16 race = fields[3].GetInt16();
//                uint16 pro = fields[4].GetInt16();
//                uint16 gender = fields[5].GetInt16();
//                uint16 level = fields[6].GetInt16();
//                pInfo->characters.emplace(guid, PlayerBotCharBaseInfo{ guid, accID, charName, race, pro, gender, level });
//                //DestroyBotMail(guid);
//            }
//        }
//    } while (result->NextRow());
//}
//
//void PlayerBotMgr::UpAllPlayerBotSession()
//{
//    PlayerBotSetting::Initialize();
//    for (std::map<uint32, PlayerBotBaseInfo*>::iterator it = m_idPlayerBotBase.begin();
//        it != m_idPlayerBotBase.end();
//        it++)
//    {
//        PlayerBotBaseInfo* pInfo = it->second;
//        UpPlayerBotSessionByBaseInfo(pInfo, false);
//    }
//}
//
//PlayerBotSession* PlayerBotMgr::UpPlayerBotSessionByBaseInfo(PlayerBotBaseInfo* pAcc, bool accountInfo)
//{
//    if (!pAcc)
//        return NULL;
//    auto pSession = sWorld->FindSession(pAcc->id).get();
//    if (pSession)
//        return NULL;
//    std::string name = pAcc->username.c_str();
//    auto pBotSession = std::shared_ptr<PlayerBotSession>(new PlayerBotSession{ pAcc->id, name, AccountTypes::SEC_GAMEMASTER, 2, 0, LocaleConstant::LOCALE_zhTW, 0, false });
//    //pbSession->ReadAddonsInfo("");
//    if (accountInfo)
//        pBotSession->SetAccountBotSession();
//
//    sWorld->AddSession(pBotSession);
//    return pBotSession.get();
//}
//
//void PlayerBotMgr::OnPlayerBotCreate(ObjectGuid const& guid, uint32 accountId, std::string const& name, uint8 gender, uint8 race, uint8 playerClass, uint8 level)
//{
//    PlayerBotBaseInfo* pInfo = GetPlayerBotAccountInfo(accountId);
//    if (!pInfo)
//        return;
//    uint32 id = guid.GetGUIDLow();
//    if (pInfo->characters.find(id) != pInfo->characters.end())
//    {
//        return;
//    }
//    pInfo->characters[id] = PlayerBotCharBaseInfo(id, accountId, name, uint16(race), uint16(playerClass), uint16(gender), uint16(level));
//
//    CreateOncePlayerBot();
//}
//
//void PlayerBotMgr::OnAccountBotCreate(ObjectGuid const& guid, uint32 accountId, std::string const& name, uint8 gender, uint8 race, uint8 playerClass, uint8 level)
//{
//    PlayerBotBaseInfo* pInfo = GetAccountBotAccountInfo(accountId);
//    if (!pInfo)
//        return;
//    uint32 id = guid.GetGUIDLow();
//    if (pInfo->characters.find(id) != pInfo->characters.end())
//    {
//        return;
//    }
//    pInfo->characters[id] = PlayerBotCharBaseInfo(id, accountId, name, uint16(race), uint16(playerClass), uint16(gender), uint16(level));
//}
//
//void PlayerBotMgr::OnAccountBotDelete(ObjectGuid& guid, uint32 accountId)
//{
//    PlayerBotBaseInfo* pInfo = GetAccountBotAccountInfo(accountId);
//    if (!pInfo)
//        return;
//    pInfo->RemoveCharacterByGUID(guid);
//}
//
//void PlayerBotMgr::OnPlayerBotLogin(WorldSession* pSession, Player* pPlayer)
//{
//    ++m_BotOnlineCount;
//    Group* pGroup = pPlayer->GetGroup();
//    if (pGroup)
//    {
//        if (!pGroup->GroupExistRealPlayer())
//        {
//            pPlayer->RemoveFromGroup(RemoveMethod::GROUP_REMOVEMETHOD_LEAVE);
//        }
//        else
//            SwitchPlayerBotAI(pPlayer, PlayerBotAIType::PBAIT_GROUP, false);
//    }
//    else
//        SwitchPlayerBotAI(pPlayer, PlayerBotAIType::PBAIT_FIELD, false);
//
//    if (pPlayer->GetBattleground())
//    {
//        pPlayer->LeaveBattleground();
//        if (pSession)
//            pSession->HandleWorldPortAck();
//    }
//
//    BotUtility::RemoveArenaBotSpellsByPlayer(pPlayer);
//    sPlayerBotTalkMgr->JoinDefaultChannel(pPlayer);
//    if (pSession)
//    {
//        std::string outString;
//        consoleToUtf8(std::string(" 上 线"), outString);
//        sWorld->SendGlobalText((GetPlayerLinkText(pPlayer) + outString).c_str(), NULL);
//    }
//    if (PlayerBotSession* pBotSession = dynamic_cast<PlayerBotSession*>(pSession))
//    {
//        if (!pSession->HasSchedules() && !pPlayer->EquipIsTidiness())
//        {
//            uint32 curTType = pPlayer->FindTalentType();
//            uint32 newTType = curTType;
//            while (newTType == curTType)
//                newTType = urand(0, 2);
//            BotGlobleSchedule schedule2(BotGlobleScheduleType::BGSType_Settting, 0);
//            schedule2.parameter1 = pPlayer->getLevel();
//            schedule2.parameter2 = pPlayer->getLevel();
//            schedule2.parameter3 = newTType + 1;
//            pBotSession->PushScheduleToQueue(schedule2);
//        }
//    }
//}
//
//void PlayerBotMgr::OnPlayerBotLogout(WorldSession* pSession)
//{
//    --m_BotOnlineCount;
//    if (m_BotOnlineCount < 0) m_BotOnlineCount = 0;
//
//    std::string outString;
//    consoleToUtf8(std::string("机器人下线"), outString);
//    sWorld->SendGlobalText(outString.c_str(), NULL);
//    PlayerBotSession* pBotSession = dynamic_cast<PlayerBotSession*>(pSession);
//    if (pBotSession && !pBotSession->HasScheduleByType(BotGlobleScheduleType::BGSType_Online) &&
//        !pBotSession->HasScheduleByType(BotGlobleScheduleType::BGSType_Online_GUID))
//        pBotSession->ClearAllSchedule();
//}
//
//void PlayerBotMgr::OnPlayerBotLeaveOriginalGroup(Player* pPlayer)
//{
//    SwitchPlayerBotAI(pPlayer, PlayerBotAIType::PBAIT_FIELD, true);
//}
//
//void PlayerBotMgr::LoginGroupBotByPlayer(Player* pPlayer)
//{
//#ifndef INCOMPLETE_BOT
//    if (pPlayer->IsPlayerBot())
//        return;
//    int32 isok = sConfigMgr->GetIntDefault("pbot", 1);
//    Group* pGroup = pPlayer->GetGroup();
//    if (!pGroup || pGroup->isBFGroup() || pGroup->isBGGroup())
//        return;
//    Group::MemberSlotList const& memList = pGroup->GetMemberSlots();
//    for (Group::MemberSlot const& slot : memList)
//    {
//        ObjectGuid guid = slot.Guid;
//        if (guid == pPlayer->GetGUID())
//            continue;
//        Player* friendPlayer = ObjectAccessor::FindPlayer(guid);
//        if (friendPlayer)
//            continue;
//        if (isok == 0)
//            AddNewPlayerBotByGUID2(guid);
//        else
//            DelayLoginPlayerBotByGUID(guid);
//    }
//#endif
//}
//
//void PlayerBotMgr::LoginFriendBotByPlayer(Player* pPlayer)
//{
//    //#ifndef INCOMPLETE_BOT
//    //	if (pPlayer->IsPlayerBot())
//    //		return;
//    //	int32 isok = sConfigMgr->GetIntDefault("pbot", 1);
//    //
//    //	std::vector<ObjectGuid> friends = pPlayer->GetSocial()->Get();
//    //	for (ObjectGuid& guid : friends)
//    //	{
//    //
//    //	if (isok==0)
//    //		AddNewPlayerBotByGUID2(guid);
//    //		else
//    //		DelayLoginPlayerBotByGUID(guid);
//    //	}
//    //#else
//    //	std::string allonlineText;
//    //	consoleToUtf8(std::string("|cffff8800体验版无法召唤好友机器人上线。|r"), allonlineText);
//    //	sWorld->SendGlobalText(allonlineText.c_str(), NULL);
//    //#endif
//}
//
//void PlayerBotMgr::LogoutAllGroupPlayerBot(Group* pGroup, bool force)
//{
//    if (!pGroup)
//        return;
//    if (!force && pGroup->GroupExistRealPlayer())
//        return;
//    Group::MemberSlotList const& memList = pGroup->GetMemberSlots();
//    for (Group::MemberSlot const& slot : memList)
//    {
//        ObjectGuid guid = slot.Guid;
//        Player* player = ObjectAccessor::FindPlayer(guid);
//        if (!player || !player->IsPlayerBot())
//            continue;
//        WorldSession* pSession = player->GetSession();
//        if (pSession)
//            pSession->LogoutPlayer(false, "bot");
//    }
//}
//
//bool PlayerBotMgr::AllPlayerLeaveBG(uint32 account)
//{
//    if (account == 0)
//        return false;
//    //std::unique_lock<std::mutex> sessionGuard(PlayerBotMgr::g_uniqueLock);
//    WorldSession* pSession = sWorld->FindSession(account).get();
//    if (pSession && pSession->IsBotSession() && !pSession->PlayerLoading())
//    {
//        Player* pPlayer = pSession->GetPlayer();
//        if (!pPlayer || pPlayer->GetTransport() || !pPlayer->InBattleground())
//            return false;
//        const Battleground* bg = pPlayer->GetBattleground();
//        if (!bg || bg->GetStatus() == BattlegroundStatus::STATUS_WAIT_LEAVE || bg->GetStatus() == BattlegroundStatus::STATUS_WAIT_JOIN)
//            return false;
//        ((Battleground*)bg)->EndBattleground((pPlayer->GetTeamId() == TEAM_ALLIANCE) ? HORDE : ALLIANCE);
//        return true;
//    }
//    return false;
//}
//
//void PlayerBotMgr::AllPlayerBotRandomLogin(const char* name)
//{
//    int32 needOnline = m_MaxOnlineBot - m_BotOnlineCount;
//    if (needOnline <= 0)
//        return;
//    for (std::map<uint32, PlayerBotBaseInfo*>::iterator it = m_idPlayerBotBase.begin();
//        it != m_idPlayerBotBase.end();
//        it++)
//    {
//        PlayerBotBaseInfo* pInfo = it->second;
//        WorldSession* pSession = sWorld->FindSession(pInfo->id).get();
//        if (pSession && pSession->IsBotSession() && !pSession->PlayerLoading() && !pSession->GetPlayer())
//        {
//            if (pInfo->characters.size() <= 0)
//                continue;
//
//            if (name[0] != '\0')
//            {
//                for (auto i = 0; i < pInfo->characters.size(); ++i)
//                {
//                    if (strcmp(name, pInfo->characters[i].name.c_str()) == 0)
//                    {
//                        PlayerBotCharBaseInfo& charInfo = pInfo->characters[i];
//                        WorldPacket _worldPacket(CMSG_PLAYER_LOGIN);
//                        WorldPackets::Character::PlayerLogin cmd(std::move(_worldPacket));
//                        cmd.Guid = ObjectGuid::Create<HighGuid::Player>(charInfo.guid);
//                        cmd.FarClip = 0.0f;
//                        pSession->HandlePlayerLoginOpcode(cmd);
//                        pSession->HandleContinuePlayerLogin();
//                        return;
//                    }
//                }
//            }
//            else
//            {
//                int sel = irand(0, pInfo->characters.size() - 1);
//                for (auto itChar = pInfo->characters.begin();
//                    itChar != pInfo->characters.end();
//                    itChar++)
//                {
//                    if (sel <= 0)
//                    {
//                        PlayerBotCharBaseInfo& charInfo = itChar->second;
//                        WorldPacket _worldPacket(CMSG_PLAYER_LOGIN);
//                        WorldPackets::Character::PlayerLogin cmd(std::move(_worldPacket));
//                        cmd.Guid = ObjectGuid::Create<HighGuid::Player>(charInfo.guid);
//                        cmd.FarClip = 0.0f;
//                        pSession->HandlePlayerLoginOpcode(cmd);
//                        pSession->HandleContinuePlayerLogin();
//                        --needOnline;
//                        break;
//                    }
//                    --sel;
//                }
//            }
//            if (needOnline <= 0)
//                return;
//        }
//    }
//}
//
//void PlayerBotMgr::AllPlayerBotLogout()
//{
//    //std::unique_lock<std::mutex> sessionGuard(PlayerBotMgr::g_uniqueLock);
//    for (std::map<uint32, PlayerBotBaseInfo*>::iterator it = m_idPlayerBotBase.begin();
//        it != m_idPlayerBotBase.end();
//        it++)
//    {
//        PlayerBotBaseInfo* pInfo = it->second;
//        PlayerBotLogout(pInfo->id);
//    }
//    for (std::map<uint32, PlayerBotBaseInfo*>::iterator it = m_idAccountBotBase.begin();
//        it != m_idAccountBotBase.end();
//        it++)
//    {
//        PlayerBotBaseInfo* pInfo = it->second;
//        PlayerBotLogout(pInfo->id);
//    }
//}
//
//bool PlayerBotMgr::PlayerBotLogout(uint32 account)
//{
//    if (account == 0)
//        return false;
//    //std::unique_lock<std::mutex> sessionGuard(PlayerBotMgr::g_uniqueLock);
//    WorldSession* pSession = sWorld->FindSession(account).get();
//    if (pSession && pSession->IsBotSession() && !pSession->PlayerLoading())
//    {
//        Player* pBot = pSession->GetPlayer();
//        if (!pBot || !pBot->IsPlayerBot() || !pBot->IsSettingFinish())
//            return false;
//        PlayerBotSession* pBotSession = dynamic_cast<PlayerBotSession*>(pSession);
//        if (pBotSession)
//        {
//            if (pBotSession->HasSchedules())
//                pBotSession->ClearAllSchedule();
//
//            pSession->LogoutPlayer(false, "bot");
//            return true;
//        }
//    }
//    return false;
//}
//
//void PlayerBotMgr::SupplementPlayerBot()
//{
//    for (std::map<uint32, PlayerBotBaseInfo*>::iterator itInfo = m_idPlayerBotBase.begin();
//        itInfo != m_idPlayerBotBase.end();
//        itInfo++)
//    {
//        PlayerBotBaseInfo* pInfo = itInfo->second;
//        if (pInfo->username.size() <= 0)
//            continue;
//        if (pInfo->characters.size() >= 18)
//            continue;
//        WorldSession* pSession = sWorld->FindSession(pInfo->id).get();
//        if (!pSession)
//        {
//            TC_LOG_INFO(LOG_FILTER_PLAYER, "server.loading", ">> Create bot, but session offline.");
//            continue;
//        }
//        std::string firstName = pInfo->username.substr(6);
//        char botname[30] = { 0 };
//        for (int i = 1; i < 10; i++)
//        {
//            if (i == 6) continue;
//            if (!pInfo->ExistClass(true, i))
//            {
//                memset(botname, 0, 30);
//                sprintf(botname, "%sA%d", firstName.c_str(), i);
//                pInfo->needCreateBots.push(BuildCreatePlayerData(true, i));
//            }
//            if (!pInfo->ExistClass(false, i))
//            {
//                memset(botname, 0, 30);
//                sprintf(botname, "%sB%d", firstName.c_str(), i);
//                pInfo->needCreateBots.push(BuildCreatePlayerData(false, i));
//            }
//        }
//        if (!pInfo->ExistClass(true, 11))
//        {
//            memset(botname, 0, 30);
//            sprintf(botname, "%sA11", firstName.c_str());
//            pInfo->needCreateBots.push(BuildCreatePlayerData(true, 11));
//        }
//        if (!pInfo->ExistClass(false, 11))
//        {
//            memset(botname, 0, 30);
//            sprintf(botname, "%sB11", firstName.c_str());
//            pInfo->needCreateBots.push(BuildCreatePlayerData(false, 11));
//        }
//    }
//    CreateOncePlayerBot();
//}
//
//void PlayerBotMgr::OnRealPlayerJoinBattlegroundQueue(uint32 bgTypeId, uint32 level)
//{
//}
//
//void PlayerBotMgr::OnRealPlayerLeaveBattlegroundQueue(uint32 bgTypeId, uint32 level)
//{
//    uint8 bgQueueTypeId = MS::Battlegrounds::GetBgQueueTypeIdByBgTypeID(bgTypeId, 0);
//    BattlegroundQueue& bgQueue = sBattlegroundMgr->GetBattlegroundQueue(bgQueueTypeId);
//    Battleground* bg = sBattlegroundMgr->GetBattlegroundTemplate(BattlegroundTypeId(bgTypeId));
//    if (!bg)
//        return;
//    PVPDifficultyEntry const* bracketEntry = sDB2Manager.GetBattlegroundBracketByLevel(bg->GetMapId(), level);
//    if (!bracketEntry)
//        return;
//
//    if (bgQueue.ExistRealPlayer(bracketEntry))
//        return;
//    const SessionMap& allSession = sWorld->GetAllSessions();
//    for (SessionMap::const_iterator itSession = allSession.begin(); itSession != allSession.end(); itSession++)
//    {
//        PlayerBotSession* pSession = dynamic_cast<PlayerBotSession*>((WorldSession*)itSession->second.get());
//        if (!pSession)
//            continue;
//        Player* player = pSession->GetPlayer();
//        if (!player || player->isBeingLoaded())
//            continue;
//        if (player->InBattleground() || player->InArena() || !player->IsInWorld())
//            continue;
//        uint32 lv = player->getLevel();
//        if (lv < bracketEntry->MinLevel || lv > bracketEntry->MaxLevel)
//            continue;
//        if (player->InBattlegroundQueue())
//        {
//            BotGlobleSchedule schedule1(BotGlobleScheduleType::BGSType_OutBGQueue, 0);
//            schedule1.parameter1 = bgTypeId;
//            pSession->PushScheduleToQueue(schedule1);
//        }
//    }
//}
//
//void PlayerBotMgr::OnRealPlayerLeaveArenaQueue(uint32 bgTypeId, uint32 level, uint32 aaType)
//{
//    uint8 bgQueueTypeId = MS::Battlegrounds::GetBgQueueTypeIdByBgTypeID(bgTypeId, aaType);
//    BattlegroundQueue& bgQueue = sBattlegroundMgr->GetBattlegroundQueue(bgQueueTypeId);
//    Battleground* bg = sBattlegroundMgr->GetBattlegroundTemplate(BattlegroundTypeId(bgTypeId));
//    if (!bg)
//        return;
//    PVPDifficultyEntry const* bracketEntry = sDB2Manager.GetBattlegroundBracketByLevel(bg->GetMapId(), level);
//    if (!bracketEntry)
//        return;
//
//    if (bgQueue.ExistRealPlayer(bracketEntry))
//        return;
//    const SessionMap& allSession = sWorld->GetAllSessions();
//    for (SessionMap::const_iterator itSession = allSession.begin(); itSession != allSession.end(); itSession++)
//    {
//        PlayerBotSession* pSession = dynamic_cast<PlayerBotSession*>((WorldSession*)itSession->second.get());
//        if (!pSession)
//            continue;
//        Player* player = pSession->GetPlayer();
//        if (!player || player->isBeingLoaded())
//            continue;
//        if (player->InBattleground() || player->InArena() || !player->IsInWorld())
//            continue;
//        uint32 lv = player->getLevel();
//        if (lv < bracketEntry->MinLevel || lv > bracketEntry->MaxLevel)
//            continue;
//        if (player->InBattlegroundQueue())
//        {
//            BotGlobleSchedule schedule1(BotGlobleScheduleType::BGSType_OutAAQueue, 0);
//            schedule1.parameter1 = bgTypeId;
//            schedule1.parameter2 = bracketEntry->RangeIndex;
//            schedule1.parameter3 = aaType;
//            pSession->PushScheduleToQueue(schedule1);
//        }
//    }
//}
//
//void PlayerBotMgr::OnRealPlayerEnterBattleground(uint32 bgTypeId, uint32 level)
//{
//}
//
//void PlayerBotMgr::OnRealPlayerLeaveBattleground(const Player* player)
//{
//    Battleground* bg = player->GetBattleground();
//    if (!bg || bg->GetStatus() != BattlegroundStatus::STATUS_WAIT_LEAVE)
//        return;
//    PVPDifficultyEntry const* bracketEntry = sDB2Manager.GetBattlegroundBracketByLevel(bg->GetMapId(), player->getLevel());
//    if (!bracketEntry)
//        return;
//
//    auto& allPlayerIDs = bg->GetPlayers();
//    for (auto itIDs = allPlayerIDs.begin(); itIDs != allPlayerIDs.end(); itIDs++)
//    {
//        Player* otherPlayer = ObjectAccessor::FindPlayer(itIDs->first);
//        if (!otherPlayer || otherPlayer->isBeingLoaded())
//            continue;
//        if (!otherPlayer->InBattleground())
//            continue;
//        PlayerBotSession* pSession = dynamic_cast<PlayerBotSession*>((WorldSession*)otherPlayer->GetSession());
//        if (pSession)
//        {
//            BotGlobleSchedule schedule1(BotGlobleScheduleType::BGSType_LeaveBG, 0);
//            pSession->PushScheduleToQueue(schedule1);
//        }
//    }
//}
//
//bool PlayerBotMgr::LoginBotByAccountIndex(uint32 account, uint32 index)
//{
//#ifndef INCOMPLETE_BOT
//    PlayerBotBaseInfo* botInfo = GetPlayerBotAccountInfo(account);
//    if (!botInfo)
//        return false;
//    if (index >= botInfo->characters.size())
//        return false;
//    for (auto itChar = botInfo->characters.begin();
//        itChar != botInfo->characters.end();
//        itChar++)
//    {
//        if (index > 0)
//        {
//            --index;
//            continue;
//        }
//        PlayerBotCharBaseInfo& charInfo = itChar->second;
//        WorldSession* pWorldSession = sWorld->FindSession(account).get();
//        PlayerBotSession* pSession = dynamic_cast<PlayerBotSession*>(pWorldSession);
//        if (!pSession || pSession->PlayerLoading() || pSession->HasSchedules() || pSession->GetPlayer())
//            return false;
//        BotGlobleSchedule schedule1(BotGlobleScheduleType::BGSType_Online_GUID, charInfo.guid);
//        pSession->PushScheduleToQueue(schedule1);
//        return true;
//    }
//#endif
//    return false;
//}
//
//bool PlayerBotMgr::AddNewPlayerBotByGUID(ObjectGuid& guid)
//{
//    int32 isok = sConfigMgr->GetIntDefault("pbot", 1);
//
//    if (isok == 0 && !guid)
//        return false;
//
//    int32 allianceCount = (int32)sPlayerBotMgr->GetOnlineBotCount(TEAM_ALLIANCE, true);
//    int32 hordeCount = (int32)sPlayerBotMgr->GetOnlineBotCount(TEAM_HORDE, true);
//
//    if ((allianceCount + hordeCount) >= m_MaxOnlineBot)
//        return false;
//
//
//    const SessionMap& allSession = sWorld->GetAllSessions();
//    for (SessionMap::const_iterator itSession = allSession.begin(); itSession != allSession.end(); itSession++)
//    {
//
//        Player* player = itSession->second->GetPlayer();
//        if (player)
//        {
//            if (player->isBeingLoaded())
//                return false;
//            if (player->GetSession()->PlayerLoading())
//                return false;
//
//        }
//    }
//
//    for (SessionMap::const_iterator itSession = allSession.begin(); itSession != allSession.end(); itSession++)
//    {
//
//        Player* player = itSession->second->GetPlayer();
//        if (player)
//        {
//            if (player->isBeingLoaded())
//                return false;
//            if (player->GetSession()->PlayerLoading())
//                return false;
//
//        }
//    }
//
//
//    for (std::map<uint32, PlayerBotBaseInfo*>::iterator itInfo = m_idPlayerBotBase.begin();
//        itInfo != m_idPlayerBotBase.end();
//        itInfo++)
//    {
//        if (!(itInfo->second->ExistCharacterByGUID(guid)))
//            continue;
//        WorldSession* pWorldSession = sWorld->FindSession(itInfo->first).get();
//        PlayerBotSession* pSession = dynamic_cast<PlayerBotSession*>(pWorldSession);
//        if (!pSession || pSession->PlayerLoading() || pSession->HasSchedules())
//            return false;
//        if (Player* player = pSession->GetPlayer())
//        {
//            if (!player->GetGroup() && !player->isInCombat() && pSession->GetPlayer()->GetGUID() != guid)
//            {
//                BotGlobleSchedule schedule(BotGlobleScheduleType::BGSType_Offline, 0);
//                pSession->PushScheduleToQueue(schedule);
//            }
//            else
//                return false;
//        }
//        BotGlobleSchedule schedule1(BotGlobleScheduleType::BGSType_Online_GUID, guid);
//        pSession->PushScheduleToQueue(schedule1);
//        return true;
//    }
//
//    for (std::map<uint32, PlayerBotBaseInfo*>::iterator itInfo = m_idAccountBotBase.begin();
//        itInfo != m_idAccountBotBase.end();
//        itInfo++)
//    {
//        if (!(itInfo->second->ExistCharacterByGUID(guid)))
//            continue;
//        WorldSession* pWorldSession = sWorld->FindSession(itInfo->first).get();
//        if (pWorldSession)
//        {
//            PlayerBotSession* pSession = dynamic_cast<PlayerBotSession*>(pWorldSession);
//            if (!pSession || pSession->PlayerLoading() || pSession->HasSchedules())
//                return false;
//            if (Player* player = pSession->GetPlayer())
//            {
//                if (!player->GetGroup() && !player->isInCombat() && pSession->GetPlayer()->GetGUID() != guid)
//                {
//                    BotGlobleSchedule schedule(BotGlobleScheduleType::BGSType_Offline, 0);
//                    pSession->PushScheduleToQueue(schedule);
//                }
//                else
//                    return false;
//            }
//            BotGlobleSchedule schedule1(BotGlobleScheduleType::BGSType_Online_GUID, guid);
//            pSession->PushScheduleToQueue(schedule1);
//            return true;
//        }
//        else
//        {
//            PlayerBotSession* pSession = UpPlayerBotSessionByBaseInfo(itInfo->second, true);
//            if (!pSession)
//                return false;
//            BotGlobleSchedule schedule1(BotGlobleScheduleType::BGSType_Online_GUID, guid);
//            pSession->PushScheduleToQueue(schedule1);
//            return true;
//        }
//    }
//    return false;
//}
//
//
//bool PlayerBotMgr::AddNewPlayerBotByGUID2(ObjectGuid& guid)
//{
//    int32 allianceCount = (int32)sPlayerBotMgr->GetOnlineBotCount(TEAM_ALLIANCE, true);
//    int32 hordeCount = (int32)sPlayerBotMgr->GetOnlineBotCount(TEAM_HORDE, true);
//
//    if ((allianceCount + hordeCount) >= m_MaxOnlineBot) return false;
//
//
//    const SessionMap& allSession = sWorld->GetAllSessions();
//    for (SessionMap::const_iterator itSession = allSession.begin(); itSession != allSession.end(); itSession++)
//    {
//
//        Player* player = itSession->second->GetPlayer();
//        if (player)
//        {
//            if (player->isBeingLoaded())
//                return false;
//            if (player->GetSession()->PlayerLoading())
//                return false;
//
//        }
//    }
//
//    for (SessionMap::const_iterator itSession = allSession.begin(); itSession != allSession.end(); itSession++)
//    {
//
//        Player* player = itSession->second->GetPlayer();
//        if (player)
//        {
//            if (player->isBeingLoaded())
//                return false;
//            if (player->GetSession()->PlayerLoading())
//                return false;
//
//        }
//    }
//
//    for (SessionMap::const_iterator itSession = allSession.begin(); itSession != allSession.end(); itSession++)
//    {
//
//        Player* player = itSession->second->GetPlayer();
//        if (player)
//        {
//            if (player->isBeingLoaded())
//                return false;
//            if (player->GetSession()->PlayerLoading())
//                return false;
//
//        }
//    }
//
//    for (std::map<uint32, PlayerBotBaseInfo*>::iterator itInfo = m_idPlayerBotBase.begin();
//        itInfo != m_idPlayerBotBase.end();
//        itInfo++)
//    {
//        if (!(itInfo->second->ExistCharacterByGUID(guid)))
//            continue;
//        WorldSession* pWorldSession = sWorld->FindSession(itInfo->first).get();
//        PlayerBotSession* pSession = dynamic_cast<PlayerBotSession*>(pWorldSession);
//        if (!pSession || pSession->PlayerLoading() || pSession->HasSchedules())
//            return false;
//        if (Player* player = pSession->GetPlayer())
//        {
//            if (!player->GetGroup() && !player->isInCombat() && pSession->GetPlayer()->GetGUID() != guid)
//            {
//                BotGlobleSchedule schedule(BotGlobleScheduleType::BGSType_Offline, 0);
//                pSession->PushScheduleToQueue(schedule);
//            }
//            else
//                return false;
//        }
//        BotGlobleSchedule schedule1(BotGlobleScheduleType::BGSType_Online_GUID, guid);
//        pSession->PushScheduleToQueue(schedule1);
//        return true;
//    }
//
//    for (std::map<uint32, PlayerBotBaseInfo*>::iterator itInfo = m_idAccountBotBase.begin();
//        itInfo != m_idAccountBotBase.end();
//        itInfo++)
//    {
//        if (!(itInfo->second->ExistCharacterByGUID(guid)))
//            continue;
//        WorldSession* pWorldSession = sWorld->FindSession(itInfo->first).get();
//        if (pWorldSession)
//        {
//            PlayerBotSession* pSession = dynamic_cast<PlayerBotSession*>(pWorldSession);
//            if (!pSession || pSession->PlayerLoading() || pSession->HasSchedules())
//                return false;
//            if (Player* player = pSession->GetPlayer())
//            {
//                if (!player->GetGroup() && !player->isInCombat() && pSession->GetPlayer()->GetGUID() != guid)
//                {
//                    BotGlobleSchedule schedule(BotGlobleScheduleType::BGSType_Offline, 0);
//                    pSession->PushScheduleToQueue(schedule);
//                }
//                else
//                    return false;
//            }
//            BotGlobleSchedule schedule1(BotGlobleScheduleType::BGSType_Online_GUID, guid);
//            pSession->PushScheduleToQueue(schedule1);
//            return true;
//        }
//        else
//        {
//            PlayerBotSession* pSession = UpPlayerBotSessionByBaseInfo(itInfo->second, true);
//            if (!pSession)
//                return false;
//            BotGlobleSchedule schedule1(BotGlobleScheduleType::BGSType_Online_GUID, guid);
//            pSession->PushScheduleToQueue(schedule1);
//            return true;
//        }
//    }
//    return false;
//}
//
//void PlayerBotMgr::AddNewPlayerBot(bool faction, Classes prof, uint32 count)
//{
//
//    int32 isok = sConfigMgr->GetIntDefault("pbot", 1);
//    if (isok == 0 && prof == CLASS_NONE)
//        return;
//
//    int32 allianceCount = (int32)sPlayerBotMgr->GetOnlineBotCount(TEAM_ALLIANCE, true);
//    int32 hordeCount = (int32)sPlayerBotMgr->GetOnlineBotCount(TEAM_HORDE, true);
//
//    if ((allianceCount + hordeCount) >= m_MaxOnlineBot)
//        return;
//
//    const SessionMap& allSession = sWorld->GetAllSessions();
//    for (SessionMap::const_iterator itSession = allSession.begin(); itSession != allSession.end(); itSession++)
//    {
//        Player* player = itSession->second->GetPlayer();
//        if (player)
//        {
//            if (player->isBeingLoaded())
//                return;
//            if (player->GetSession()->PlayerLoading())
//                return;
//
//        }
//    }
//
//
//    for (SessionMap::const_iterator itSession = allSession.begin(); itSession != allSession.end(); itSession++)
//    {
//
//        Player* player = itSession->second->GetPlayer();
//        if (player)
//        {
//            if (player->isBeingLoaded())
//                return;
//            if (player->GetSession()->PlayerLoading())
//                return;
//
//        }
//    }
//
//    if (count <= 0)
//        return;
//
//
//
//    if (prof == CLASS_NONE)
//    {
//        uint32 rndCls = 0;
//        while (rndCls == 0 || rndCls == 6 || rndCls == 10 || rndCls > 11)
//        {
//            rndCls = urand(Classes::CLASS_WARRIOR, Classes::CLASS_DRUID);
//        }
//        prof = Classes(rndCls);
//    }
//#ifdef INCOMPLETE_BOT
//    if (prof != 1 && prof != 5 && prof != 9)
//    {
//        if (prof == 2 || prof == 6)
//            prof = Classes::CLASS_WARRIOR;
//        else if (prof == 3 || prof == 4 || prof == 8 || prof == 10)
//            prof = Classes::CLASS_WARLOCK;
//        else if (prof == 7 || prof == 11)
//            prof = Classes::CLASS_PRIEST;
//    }
//#endif
//    //const SessionMap& allSession = sWorld->GetAllSessions();
//    for (SessionMap::const_iterator itSession = allSession.begin(); itSession != allSession.end(); itSession++)
//    {
//        if (count <= 0)
//            return;
//        if (!itSession->second->IsBotSession())
//            continue;
//        PlayerBotSession* pSession = dynamic_cast<PlayerBotSession*>((WorldSession*)itSession->second.get());
//        if (!pSession || pSession->PlayerLoading() || pSession->HasSchedules() || pSession->IsAccountBotSession())
//            continue;
//        Player* player = pSession->GetPlayer();
//        if (player)
//            continue;
//        BotGlobleSchedule schedule1(BotGlobleScheduleType::BGSType_Online, 0);
//        if (faction)
//        {
//            schedule1.parameter1 = 1;
//        }
//        else
//        {
//            schedule1.parameter1 = 2;
//        }
//        schedule1.parameter2 = prof;
//        pSession->PushScheduleToQueue(schedule1);
//        --count;
//    }
//
//    if (count > 0)
//    {
//        std::string allonlineText;
//        consoleToUtf8(std::string("|cffff8800所有机器人账号已经全部在线，无法上线新机器人。|r"), allonlineText);
//        sWorld->SendGlobalText(allonlineText.c_str(), NULL);
//    }
//}
//
//void PlayerBotMgr::AddNewAccountBot(bool faction, Classes prof)
//{
//    int32 isok = sConfigMgr->GetIntDefault("pbotall", 1);
//    if (isok == 0)
//        return;
//
//    int32 allianceCount = (int32)sPlayerBotMgr->GetOnlineBotCount(TEAM_ALLIANCE, true);
//    int32 hordeCount = (int32)sPlayerBotMgr->GetOnlineBotCount(TEAM_HORDE, true);
//
//    if ((allianceCount + hordeCount) >= m_MaxOnlineBot)
//        return;
//
//
//    const SessionMap& allSession = sWorld->GetAllSessions();
//    for (SessionMap::const_iterator itSession = allSession.begin(); itSession != allSession.end(); itSession++)
//    {
//
//        Player* player = itSession->second->GetPlayer();
//        if (player)
//        {
//            if (player->isBeingLoaded())
//                return;
//            if (player->GetSession()->PlayerLoading())
//                return;
//
//        }
//    }
//
//    for (SessionMap::const_iterator itSession = allSession.begin(); itSession != allSession.end(); itSession++)
//    {
//
//        Player* player = itSession->second->GetPlayer();
//        if (player)
//        {
//            if (player->isBeingLoaded())
//                return;
//            if (player->GetSession()->PlayerLoading())
//                return;
//
//        }
//    }
//    std::string allonlineText;
//#ifdef INCOMPLETE_BOT
//    consoleToUtf8(std::string("|cffff8800体验版无法召唤上线自建账号角色|r"), allonlineText);
//    sWorld->SendGlobalText(allonlineText.c_str(), NULL);
//    return;
//#endif
//    if (prof == CLASS_NONE)
//    {
//        uint32 rndCls = 0;
//        while (rndCls == 0 || rndCls == 6 || rndCls == 10 || rndCls > 11)
//        {
//            rndCls = urand(Classes::CLASS_WARRIOR, Classes::CLASS_DRUID);
//        }
//        prof = Classes(rndCls);
//    }
//    //std::set<uint32> hasSessionIDs;
////	const SessionMap& allSession = sWorld->GetAllSessions();
//    for (SessionMap::const_iterator itSession = allSession.begin(); itSession != allSession.end(); itSession++)
//    {
//        if (!itSession->second->IsBotSession())
//            continue;
//        PlayerBotSession* pSession = dynamic_cast<PlayerBotSession*>((WorldSession*)itSession->second.get());
//        if (!pSession || pSession->PlayerLoading() || pSession->HasSchedules() || !pSession->IsAccountBotSession())
//            continue;
//        //hasSessionIDs.insert(pSession->GetAccountId());
//        Player* player = pSession->GetPlayer();
//        if (player)
//            continue;
//        PlayerBotBaseInfo* pBaseInfo = GetAccountBotAccountInfo(pSession->GetAccountId());
//        if (!pBaseInfo)
//            continue;
//        if (!pBaseInfo->ExistClass(faction, prof))
//            continue;
//        BotGlobleSchedule schedule1(BotGlobleScheduleType::BGSType_Online, 0);
//        if (faction)
//            schedule1.parameter1 = 1;
//        else
//            schedule1.parameter1 = 2;
//        schedule1.parameter2 = prof;
//        pSession->PushScheduleToQueue(schedule1);
//        return;
//    }
//
//    for (std::map<uint32, PlayerBotBaseInfo*>::iterator it = m_idAccountBotBase.begin();
//        it != m_idAccountBotBase.end();
//        it++)
//    {
//        PlayerBotBaseInfo* pInfo = it->second;
//        WorldSession* pSession = sWorld->FindSession(pInfo->id).get();
//        if (pSession)
//            continue;
//        if (!pInfo->ExistClass(faction, prof))
//            continue;
//        PlayerBotSession* pBotSession = UpPlayerBotSessionByBaseInfo(pInfo, true);
//        if (pBotSession)
//        {
//            BotGlobleSchedule schedule1(BotGlobleScheduleType::BGSType_Online, 0);
//            if (faction)
//                schedule1.parameter1 = 1;
//            else
//                schedule1.parameter1 = 2;
//            schedule1.parameter2 = prof;
//            pBotSession->PushScheduleToQueue(schedule1);
//            return;
//        }
//    }
//
//    consoleToUtf8(std::string("|cffff8800没有找到和你相同阵营的指定职业的自建账号角色|r"), allonlineText);
//    sWorld->SendGlobalText(allonlineText.c_str(), NULL);
//}
//
//void PlayerBotMgr::AddNewPlayerBotByClass(uint32 count, Classes prof)
//{
//    int32 isok = sConfigMgr->GetIntDefault("pbotall", 1);
//    if (isok == 0)
//        return;
//
//    int32 allianceCount = (int32)sPlayerBotMgr->GetOnlineBotCount(TEAM_ALLIANCE, true);
//    int32 hordeCount = (int32)sPlayerBotMgr->GetOnlineBotCount(TEAM_HORDE, true);
//
//    if ((allianceCount + hordeCount) >= m_MaxOnlineBot) return;
//
//    const SessionMap& allSession = sWorld->GetAllSessions();
//    for (SessionMap::const_iterator itSession = allSession.begin(); itSession != allSession.end(); itSession++)
//    {
//
//        Player* player = itSession->second->GetPlayer();
//        if (player)
//        {
//            if (player->isBeingLoaded())
//                return;
//            if (player->GetSession()->PlayerLoading())
//                return;
//
//        }
//    }
//
//
//    for (SessionMap::const_iterator itSession = allSession.begin(); itSession != allSession.end(); itSession++)
//    {
//
//        Player* player = itSession->second->GetPlayer();
//        if (player)
//        {
//            if (player->isBeingLoaded())
//                return;
//            if (player->GetSession()->PlayerLoading())
//                return;
//
//        }
//    }
//
//#ifdef INCOMPLETE_BOT
//    if (prof != 1 && prof != 5 && prof != 9)
//    {
//        if (prof == 2 || prof == 6)
//            prof = Classes::CLASS_WARRIOR;
//        else if (prof == 3 || prof == 4 || prof == 8 || prof == 10)
//            prof = Classes::CLASS_WARLOCK;
//        else if (prof == 7 || prof == 11)
//            prof = Classes::CLASS_PRIEST;
//    }
//#endif
//
//    //	const SessionMap& allSession = sWorld->GetAllSessions();
//    for (SessionMap::const_iterator itSession = allSession.begin(); itSession != allSession.end(); itSession++)
//    {
//        if (allianceCount <= 0 && hordeCount <= 0)
//            return;
//        if (!itSession->second->IsBotSession())
//            continue;
//        PlayerBotSession* pSession = dynamic_cast<PlayerBotSession*>((WorldSession*)itSession->second.get());
//        if (!pSession || pSession->PlayerLoading() || pSession->HasSchedules() || pSession->IsAccountBotSession())
//            continue;
//        Player* player = pSession->GetPlayer();
//        if (player && player->getClass() != prof)
//            continue;
//        if (player)
//        {
//            if (player->GetTeamId() == TeamId::TEAM_ALLIANCE)
//                --allianceCount;
//            else
//                --hordeCount;
//        }
//        else
//        {
//            BotGlobleSchedule schedule1(BotGlobleScheduleType::BGSType_Online, 0);
//            if (allianceCount > 0)
//            {
//                schedule1.parameter1 = 1;
//                --allianceCount;
//            }
//            else if (hordeCount > 0)
//            {
//                schedule1.parameter1 = 2;
//                --hordeCount;
//            }
//            else
//                continue;
//            schedule1.parameter2 = prof;
//            pSession->PushScheduleToQueue(schedule1);
//        }
//    }
//
//    if (allianceCount > 0 || hordeCount > 0)
//    {
//        std::string allonlineText;
//        consoleToUtf8(std::string("|cffff8800所有机器人账号已经全部在线，无法上线新机器人。|r"), allonlineText);
//        sWorld->SendGlobalText(allonlineText.c_str(), NULL);
//    }
//}
//
//bool PlayerBotMgr::ChangePlayerBotSetting(uint32 account, uint32 minLV, uint32 maxLV, uint32 talent)
//{
//    if (account == 0)
//        return false;
//    maxLV = PlayerBotSetting::CheckMaxLevel(maxLV);
//    if (maxLV < minLV)
//        maxLV = minLV;
//    WorldSession* pWorldSession = sWorld->FindSession(account).get();
//    if (pWorldSession && pWorldSession->IsBotSession() && !pWorldSession->PlayerLoading())
//    {
//        Player* player = pWorldSession->GetPlayer();
//        if (!player || player->InBattlegroundQueue() || player->InBattleground() ||
//            player->GetBattleground() || player->isInCombat())
//            return false;
//        PlayerBotSession* pSession = dynamic_cast<PlayerBotSession*>(pWorldSession);
//        if (!pSession || pSession->HasSchedules())
//            return false;
//        BotGlobleSchedule schedule2(BotGlobleScheduleType::BGSType_Settting, 0);
//        schedule2.parameter1 = minLV;
//        schedule2.parameter2 = maxLV;
//        schedule2.parameter3 = talent + 1;
//        pSession->PushScheduleToQueue(schedule2);
//        return true;
//    }
//    return false;
//}
//
//void PlayerBotMgr::AddNewPlayerBotToBG(TeamId team, uint32 minLV, uint32 maxLV, BattlegroundTypeId bgTypeID)
//{
//    const SessionMap& allSession = sWorld->GetAllSessions();
//    for (SessionMap::const_iterator itSession = allSession.begin(); itSession != allSession.end(); itSession++)
//    {
//        Player* player = itSession->second->GetPlayer();
//        if (player)
//        {
//            if (player->isBeingLoaded())
//                return;
//            if (player->GetSession()->PlayerLoading())
//                return;
//        }
//    }
//
//    for (SessionMap::const_iterator itSession = allSession.begin(); itSession != allSession.end(); itSession++)
//    {
//        Player* player = itSession->second->GetPlayer();
//        if (player)
//        {
//            if (player->isBeingLoaded())
//                return;
//            if (player->GetSession()->PlayerLoading())
//                return;
//
//        }
//    }
//
//    maxLV = PlayerBotSetting::CheckMaxLevel(maxLV);
//    if (maxLV < minLV)
//        maxLV = minLV;
//    //	const SessionMap& allSession = sWorld->GetAllSessions();
//    for (SessionMap::const_iterator itSession = allSession.begin(); itSession != allSession.end(); itSession++)
//    {
//        if (!itSession->second->IsBotSession())
//            continue;
//        PlayerBotSession* pSession = dynamic_cast<PlayerBotSession*>((WorldSession*)itSession->second.get());
//        if (!pSession || pSession->PlayerLoading() || pSession->HasSchedules() || pSession->IsAccountBotSession())
//            continue;
//        Player* player = pSession->GetPlayer();
//        if (player)
//        {
//            if (!player || player->isBeingLoaded() || !player->IsInWorld())
//                continue;
//            if (player->InBattleground() || player->InArena() || player->GetMap()->IsDungeon() || player->isUsingLfg())
//                continue;
//            if (player->InBattlegroundQueue())
//                continue;
//            if (!player->IsSettingFinish())
//                continue;
//            if (player->GetTeamId() != team)
//                continue;
//
//            BotGlobleSchedule schedule2(BotGlobleScheduleType::BGSType_Settting, 0);
//            schedule2.parameter1 = maxLV;
//            schedule2.parameter2 = maxLV;
//            schedule2.parameter3 = 4;
//            pSession->PushScheduleToQueue(schedule2);
//
//            BotGlobleSchedule schedule3(BotGlobleScheduleType::BGSType_InBGQueue, 0);
//            schedule3.parameter1 = bgTypeID;
//            pSession->PushScheduleToQueue(schedule3);
//            return;
//        }
//    }
//
//    for (SessionMap::const_iterator itSession = allSession.begin(); itSession != allSession.end(); itSession++)
//    {
//        if (!itSession->second->IsBotSession())
//            continue;
//        PlayerBotSession* pSession = dynamic_cast<PlayerBotSession*>((WorldSession*)itSession->second.get());
//        if (!pSession || pSession->PlayerLoading() || pSession->HasSchedules() || pSession->IsAccountBotSession())
//            continue;
//        Player* player = pSession->GetPlayer();
//        if (!player)
//        {
//            BotGlobleSchedule schedule1(BotGlobleScheduleType::BGSType_Online, 0);
//            schedule1.parameter1 = (team == TeamId::TEAM_ALLIANCE) ? 1 : 2;
//            pSession->PushScheduleToQueue(schedule1);
//
//            BotGlobleSchedule schedule2(BotGlobleScheduleType::BGSType_Settting, 0);
//            schedule2.parameter1 = minLV;
//            schedule2.parameter2 = maxLV;
//            schedule2.parameter3 = 4;
//            pSession->PushScheduleToQueue(schedule2);
//
//            BotGlobleSchedule schedule3(BotGlobleScheduleType::BGSType_InBGQueue, 0);
//            schedule3.parameter1 = bgTypeID;
//            pSession->PushScheduleToQueue(schedule3);
//            return;
//        }
//    }
//
//    std::string allonlineText;
//    consoleToUtf8(std::string("|cffff8800所有机器人账号已经全部在线，无法加入新机器人到战场中。|r"), allonlineText);
//    sWorld->SendGlobalText(allonlineText.c_str(), NULL);
//}
//
////void PlayerBotMgr::AddNewPlayerBotToLFG(lfg::LFGBotRequirement* botRequirement)
////{
////	if (!botRequirement || botRequirement->selectedDungeons.empty())
////		return;
////		
////	int32 isok = sConfigMgr->GetIntDefault("pbotall", 1);
////	if (isok==0)
////		return;
////
////int32 isoka = sConfigMgr->GetIntDefault("pbotasl", 88);
////
////	int32 allianceCount = (int32)sPlayerBotMgr->GetOnlineBotCount(TEAM_ALLIANCE, true);
////	int32 hordeCount = (int32)sPlayerBotMgr->GetOnlineBotCount(TEAM_HORDE, true);
////
////if ((allianceCount+hordeCount) >isoka) return;
////
////
////	const SessionMap& allSession = sWorld->GetAllSessions();
////	for (SessionMap::const_iterator itSession = allSession.begin(); itSession != allSession.end(); itSession++)
////	{
////
////		Player* player = itSession->second->GetPlayer();
////		if (player)
////{
////		if (player->isBeingLoaded())
////			return;
////if (player->GetSession()->PlayerLoading())
////return;
//////if (player->isInCombat())
//////return;
////	}
////	}
////	
////
////	//const SessionMap& allSession = sWorld->GetAllSessions();
////	for (SessionMap::const_iterator itSession = allSession.begin(); itSession != allSession.end(); itSession++)
////	{
////
////		Player* player = itSession->second->GetPlayer();
////		if (player)
////{
////		if (player->isBeingLoaded())
////			return;
////if (player->GetSession()->PlayerLoading())
////return;
//////if (player->isInCombat())
//////return;
////	}
////	}
////		
////	std::vector<uint32> duns;
////	for (lfg::LfgDungeonSet::iterator itLfgSet = botRequirement->selectedDungeons.begin(); itLfgSet != botRequirement->selectedDungeons.end(); itLfgSet++)
////	{
////		uint32 dun = *itLfgSet;
////		duns.push_back(dun);
////	}
//////	const SessionMap& allSession = sWorld->GetAllSessions();
////	for (SessionMap::const_iterator itSession = allSession.begin(); itSession != allSession.end(); itSession++)
////	{
////		if (!itSession->second->IsBotSession())
////			continue;
////		PlayerBotSession* pSession = dynamic_cast<PlayerBotSession*>((WorldSession*)itSession->second);
////		if (!pSession || pSession->PlayerLoading() || pSession->HasSchedules() || pSession->IsAccountBotSession())
////			continue;
////		Player* player = pSession->GetPlayer();
////		if (!player)
////		{
////			BotGlobleSchedule schedule1(BotGlobleScheduleType::BGSType_Online, 0);
////			if (!FillOnlineBotScheduleByLFGRequirement(botRequirement, &schedule1))
////				continue;
////			pSession->PushScheduleToQueue(schedule1);
////
////			BotGlobleSchedule schedule2(BotGlobleScheduleType::BGSType_Settting, 0);
////			schedule2.parameter1 = botRequirement->needLevel;
////			schedule2.parameter2 = botRequirement->needLevel;
////			schedule2.parameter3 = GetScheduleTalentByLFGRequirement(botRequirement->needRole, schedule1.parameter2) + 1;
////			pSession->PushScheduleToQueue(schedule2);
////
////			BotGlobleSchedule schedule3(BotGlobleScheduleType::BGSType_InLFGQueue, 0);
////			schedule3.parameter1 = uint32(botRequirement->needRole);
////			uint32 count = botRequirement->selectedDungeons.size();
////			schedule3.parameter2 = (count > 3) ? 3 : count;
////			if (count >= 1)
////				schedule3.parameter3 = duns[0];
////			if (count >= 2)
////				schedule3.parameter4 = duns[1];
////			if (count >= 3)
////				schedule3.parameter5 = duns[2];
////			pSession->PushScheduleToQueue(schedule3);
////
////			return;
////		}
////		else if (IsIDLEPlayerBot(player))
////		{
////			if (player->GetTeamId() != botRequirement->needTeam)
////				continue;
////			lfg::LfgRoles playerRole = lfg::LfgRoles::PLAYER_ROLE_NONE;
////			if (BotFieldAI* pFieldAI = dynamic_cast<BotFieldAI*>(player->GetAI()))
////			{
////				if ((player->getClass() == 1 && player->FindTalentType() == 2) || (player->getClass() == 2 && player->FindTalentType() == 1))
////					playerRole = lfg::LfgRoles::PLAYER_ROLE_TANK;
////				else if (pFieldAI->IsHealerBotAI())
////					playerRole = lfg::LfgRoles::PLAYER_ROLE_HEALER;
////				else
////					playerRole = lfg::LfgRoles::PLAYER_ROLE_DAMAGE;
////			}
////			else if (BotGroupAI* pGroupAI = dynamic_cast<BotGroupAI*>(player->GetAI()))
////			{
////				if (pGroupAI->IsTankBotAI())
////					playerRole = lfg::LfgRoles::PLAYER_ROLE_TANK;
////				else if (pGroupAI->IsHealerBotAI())
////					playerRole = lfg::LfgRoles::PLAYER_ROLE_HEALER;
////				else
////					playerRole = lfg::LfgRoles::PLAYER_ROLE_DAMAGE;
////			}
////			if (playerRole != botRequirement->needRole)
////				continue;
////
////			BotGlobleSchedule schedule2(BotGlobleScheduleType::BGSType_Settting, 0);
////			schedule2.parameter1 = botRequirement->needLevel;
////			schedule2.parameter2 = botRequirement->needLevel;
////			schedule2.parameter3 = player->FindTalentType() + 1;
////			pSession->PushScheduleToQueue(schedule2);
////
////			BotGlobleSchedule schedule3(BotGlobleScheduleType::BGSType_InLFGQueue, 0);
////			schedule3.parameter1 = uint32(botRequirement->needRole);
////			uint32 count = botRequirement->selectedDungeons.size();
////			schedule3.parameter2 = (count > 3) ? 3 : count;
////			if (count >= 1)
////				schedule3.parameter3 = duns[0];
////			if (count >= 2)
////				schedule3.parameter4 = duns[1];
////			if (count >= 3)
////				schedule3.parameter5 = duns[2];
////			pSession->PushScheduleToQueue(schedule3);
////
////			return;
////		}
////	}
////
////	std::string allonlineText;
////	consoleToUtf8(std::string("|cffff8800所有机器人账号已经全部在线，无法加入新机器人到地下城队列中。|r"), allonlineText);
////	sWorld->SendGlobalText(allonlineText.c_str(), NULL);
////}
//
//void PlayerBotMgr::AddNewPlayerBotToAA(TeamId team, BattlegroundTypeId bgTypeID, uint32 bracketID, uint32 aaType)
//{
//    const SessionMap& allSession = sWorld->GetAllSessions();
//    for (SessionMap::const_iterator itSession = allSession.begin(); itSession != allSession.end(); itSession++)
//    {
//
//        Player* player = itSession->second->GetPlayer();
//        if (player)
//        {
//            if (player->isBeingLoaded())
//                return;
//            if (player->GetSession()->PlayerLoading())
//                return;
//            //if (player->isInCombat())
//            //return;
//        }
//    }
//
//    for (SessionMap::const_iterator itSession = allSession.begin(); itSession != allSession.end(); itSession++)
//    {
//
//        Player* player = itSession->second->GetPlayer();
//        if (player)
//        {
//            if (player->isBeingLoaded())
//                return;
//            if (player->GetSession()->PlayerLoading())
//                return;
//            //if (player->isInCombat())
//            //return;
//        }
//    }
//
//
//    if (aaType != 2 && aaType != 3 && aaType != 5)
//        return;
//    //	const SessionMap& allSession = sWorld->GetAllSessions();
//    std::vector<uint32> rndIDs;
//    for (SessionMap::const_iterator itSession = allSession.begin(); itSession != allSession.end(); itSession++)
//        rndIDs.push_back(itSession->first);
//    Trinity::Containers::RandomShuffle(rndIDs);
//    for (uint32 account : rndIDs)
//    {
//        WorldSession* pWorldSession = sWorld->FindSession(account).get();
//        if (!pWorldSession || !pWorldSession->IsBotSession())
//            continue;
//        PlayerBotSession* pSession = dynamic_cast<PlayerBotSession*>(pWorldSession);
//        if (!pSession || pSession->PlayerLoading() || pSession->HasSchedules() || pSession->IsAccountBotSession())
//            continue;
//        Player* player = pSession->GetPlayer();
//        if (player)
//        {
//            if (!player || player->isBeingLoaded() || !player->IsInWorld())
//                continue;
//            if (player->InBattleground() || player->InArena() || player->GetMap()->IsDungeon() || player->isUsingLfg())
//                continue;
//            if (player->InBattlegroundQueue())
//                continue;
//            if (!player->IsSettingFinish())
//                continue;
//            if (player->GetTeamId() != team)
//                continue;
//
//            BotGlobleSchedule schedule2(BotGlobleScheduleType::BGSType_Settting, 0);
//            schedule2.parameter1 = 110;
//            schedule2.parameter2 = 110;
//            schedule2.parameter3 = 4;
//            pSession->PushScheduleToQueue(schedule2);
//
//            BotGlobleSchedule schedule3(BotGlobleScheduleType::BGSType_InAAQueue, 0);
//            schedule3.parameter1 = 14;
//            schedule3.parameter2 = 4;
//            pSession->PushScheduleToQueue(schedule3);
//
//            return;
//        }
//    }
//
//    for (uint32 account : rndIDs)
//    {
//        WorldSession* pWorldSession = sWorld->FindSession(account).get();
//        if (!pWorldSession || !pWorldSession->IsBotSession())
//            continue;
//        PlayerBotSession* pSession = dynamic_cast<PlayerBotSession*>(pWorldSession);
//        if (!pSession || pSession->PlayerLoading() || pSession->HasSchedules() || pSession->IsAccountBotSession())
//            continue;
//        Player* player = pSession->GetPlayer();
//        if (!player)
//        {
//            BotGlobleSchedule schedule1(BotGlobleScheduleType::BGSType_Online, 0);
//            schedule1.parameter1 = (team == TeamId::TEAM_ALLIANCE) ? 1 : 2;
//            pSession->PushScheduleToQueue(schedule1);
//
//            BotGlobleSchedule schedule2(BotGlobleScheduleType::BGSType_Settting, 0);
//            schedule2.parameter1 = 110;
//            schedule2.parameter2 = 110;
//            schedule2.parameter3 = 4;
//            pSession->PushScheduleToQueue(schedule2);
//
//            BotGlobleSchedule schedule3(BotGlobleScheduleType::BGSType_InAAQueue, 0);
//            schedule3.parameter1 = 14;
//            schedule3.parameter2 = 4;
//            pSession->PushScheduleToQueue(schedule3);
//
//            return;
//        }
//    }
//
//    std::string allonlineText;
//    consoleToUtf8(std::string("|cffff8800所有机器人账号已经全部在线，无法加入新机器人到竞技场中。|r"), allonlineText);
//    sWorld->SendGlobalText(allonlineText.c_str(), NULL);
//}
//
//void PlayerBotMgr::AddTeamBotToRatedArena(uint32 arenaTeamId)
//{
//    //	int32 isok = sConfigMgr->GetIntDefault("pbot", 1);
//    //	if (isok==0)
//    //		return;
//    //
//    //int32 isoka = sConfigMgr->GetIntDefault("pbotasl", 88);
//    //
//    //	int32 allianceCount = (int32)sPlayerBotMgr->GetOnlineBotCount(TEAM_ALLIANCE, true);
//    //	int32 hordeCount = (int32)sPlayerBotMgr->GetOnlineBotCount(TEAM_HORDE, true);
//    //
//    //if ((allianceCount+hordeCount) >isoka) return;
//    //
//    //
//    //	const SessionMap& allSession = sWorld->GetAllSessions();
//    //	for (SessionMap::const_iterator itSession = allSession.begin(); itSession != allSession.end(); itSession++)
//    //	{
//    //
//    //		Player* player = itSession->second->GetPlayer();
//    //		if (player)
//    //{
//    //		if (player->isBeingLoaded())
//    //			return;
//    //if (player->GetSession()->PlayerLoading())
//    //return;
//    //
//    ////if (player->isInCombat())
//    ////return;
//    //	}
//    //	}
//    //	
//    //
//    //	if (arenaTeamId == 0)
//    //		return;
//    //	ArenaTeam* arenaTeam = sArenaTeamMgr->GetArenaTeamById(arenaTeamId);
//    //	if (!arenaTeam)
//    //		return;
//    //	BattlegroundQueueTypeId bgQueueTypeID = BattlegroundMgr::BGQueueTypeId(BattlegroundTypeId(BattlegroundTypeId::BATTLEGROUND_AA), arenaTeam->GetType());
//    //	BattlegroundQueue& bgQueue = sBattlegroundMgr->GetBattlegroundQueue(bgQueueTypeID);
//    //	for (ArenaTeam::MemberList::iterator itaMem = arenaTeam->m_membersBegin(); itaMem != arenaTeam->m_membersEnd(); itaMem++)
//    //	{
//    //		ArenaTeamMember& mem = *itaMem;
//    //		ObjectGuid guid = mem.Guid;
//    //		if (bgQueue.ExistQueueByRatedArena(guid, true))
//    //			continue;
//    //		if (Player* player = ObjectAccessor::FindConnectedPlayer(guid))
//    //		{
//    //			if (!player->IsPlayerBot() || player->GetGroup())
//    //				continue;
//    //			if (PlayerBotSession* pSession = dynamic_cast<PlayerBotSession*>(player->GetSession()))
//    //			{
//    //				BotGlobleSchedule schedule2(BotGlobleScheduleType::BGSType_Settting, 0);
//    //				schedule2.parameter1 = 80;
//    //				schedule2.parameter2 = 80;
//    //				schedule2.parameter3 = sArenaTeamMgr->FindArenaTeamPlayerBotTalent(guid) + 1;
//    //				schedule2.parameter4 = (pSession->IsAccountBotSession()) ? 0 : 1;
//    //				pSession->PushScheduleToQueue(schedule2);
//    //
//    //				BotGlobleSchedule schedule3(BotGlobleScheduleType::BGSType_InAAQueue, 0);
//    //				schedule3.parameter1 = BattlegroundTypeId::BATTLEGROUND_AA;
//    //				if (arenaTeam->GetType() == 2)
//    //					schedule3.parameter2 = 0;
//    //				else if (arenaTeam->GetType() == 3)
//    //					schedule3.parameter2 = 1;
//    //				else if (arenaTeam->GetType() == 5)
//    //					schedule3.parameter2 = 2;
//    //				schedule3.parameter3 = 1;
//    //				pSession->PushScheduleToQueue(schedule3);
//    //
//    //				BotGlobleSchedule schedule4(BotGlobleScheduleType::BGSType_EnterAA, 0);
//    //				schedule4.parameter1 = BattlegroundTypeId::BATTLEGROUND_AA;
//    //				schedule4.parameter2 = 14;
//    //				schedule4.parameter3 = arenaTeam->GetType();
//    //				schedule4.parameter4 = 1;
//    //				pSession->PushScheduleToQueue(schedule4);
//    //			}
//    //		}
//    //		else if (PlayerBotSession* pSession = GetBotSessionByCharGUID(guid))
//    //		{
//    //			Player* player = pSession->GetPlayer();
//    //			if (player)
//    //			{
//    //				BotGlobleSchedule schedule(BotGlobleScheduleType::BGSType_Offline, 0);
//    //				pSession->PushScheduleToQueue(schedule);
//    //			}
//    //			BotGlobleSchedule schedule1(BotGlobleScheduleType::BGSType_Online_GUID, 0);
//    //			schedule1.parameter1 = guid.GetCounter();
//    //			pSession->PushScheduleToQueue(schedule1);
//    //
//    //			BotGlobleSchedule schedule2(BotGlobleScheduleType::BGSType_Settting, 0);
//    //			schedule2.parameter1 = 80;
//    //			schedule2.parameter2 = 80;
//    //			schedule2.parameter3 = sArenaTeamMgr->FindArenaTeamPlayerBotTalent(guid) + 1;
//    //			schedule2.parameter4 = (pSession->IsAccountBotSession()) ? 0 : 1;
//    //			pSession->PushScheduleToQueue(schedule2);
//    //
//    //			BotGlobleSchedule schedule3(BotGlobleScheduleType::BGSType_InAAQueue, 0);
//    //			schedule3.parameter1 = BattlegroundTypeId::BATTLEGROUND_AA;
//    //			if (arenaTeam->GetType() == 2)
//    //				schedule3.parameter2 = 0;
//    //			else if (arenaTeam->GetType() == 3)
//    //				schedule3.parameter2 = 1;
//    //			else if (arenaTeam->GetType() == 5)
//    //				schedule3.parameter2 = 2;
//    //			schedule3.parameter3 = 1;
//    //			pSession->PushScheduleToQueue(schedule3);
//    //
//    //			BotGlobleSchedule schedule4(BotGlobleScheduleType::BGSType_EnterAA, 0);
//    //			schedule4.parameter1 = BattlegroundTypeId::BATTLEGROUND_AA;
//    //			schedule4.parameter2 = 14;
//    //			schedule4.parameter3 = arenaTeam->GetType();
//    //			schedule4.parameter4 = 1;
//    //			pSession->PushScheduleToQueue(schedule4);
//    //		}
//    //	}
//}
//
////bool PlayerBotMgr::FillOnlineBotScheduleByLFGRequirement(lfg::LFGBotRequirement* botRequirement, BotGlobleSchedule* botSchedule)
////{
////	if (!botRequirement || !botSchedule)
////		return false;
////	botSchedule->parameter1 = 0;
////	if (botRequirement->needTeam == TEAM_ALLIANCE)
////		botSchedule->parameter1 = 1;
////	else if (botRequirement->needTeam == TEAM_HORDE)
////		botSchedule->parameter1 = 2;
////	else
////		return false;
////	std::vector<uint32> matchClasses;
////	botSchedule->parameter2 = 0;
////	if (botRequirement->needRole == lfg::LfgRoles::PLAYER_ROLE_TANK)
////	{
////		matchClasses.push_back(1);
////#ifndef INCOMPLETE_BOT
////		matchClasses.push_back(2);
////#endif
////		//matchClasses.push_back(6);
////	}
////	else if (botRequirement->needRole == lfg::LfgRoles::PLAYER_ROLE_HEALER)
////	{
////		matchClasses.push_back(5);
////#ifndef INCOMPLETE_BOT
////		matchClasses.push_back(2);
////		matchClasses.push_back(7);
////		matchClasses.push_back(11);
////#endif
////	}
////	else if (botRequirement->needRole == lfg::LfgRoles::PLAYER_ROLE_DAMAGE)
////	{
////#ifndef INCOMPLETE_BOT
////		matchClasses.push_back(3);
////		matchClasses.push_back(4);
////		matchClasses.push_back(8);
////#endif
////		matchClasses.push_back(9);
////	}
////	if (matchClasses.empty())
////		return false;
////	botSchedule->parameter2 = matchClasses[urand(0, matchClasses.size() - 1)];
////	return true;
////}
//
//uint32 PlayerBotMgr::GetScheduleTalentByLFGRequirement(lfg::LfgRoles roles, uint32 botCls)
//{
//    uint32 talentType = 3;
//    switch (botCls)
//    {
//    case 1:
//        if (roles == lfg::LfgRoles::PLAYER_ROLE_TANK)
//            talentType = 2;
//        else
//            talentType = urand(0, 1);
//        break;
//    case 2:
//        if (roles == lfg::LfgRoles::PLAYER_ROLE_TANK)
//            talentType = 1;
//        else if (roles == lfg::LfgRoles::PLAYER_ROLE_HEALER)
//            talentType = 0;
//        else
//            talentType = 2;
//        break;
//    case 6:
//        if (roles == lfg::LfgRoles::PLAYER_ROLE_TANK)
//            talentType = 1;
//        else
//        {
//            if (urand(0, 1) == 0)
//                talentType = 0;
//            else
//                talentType = 2;
//        }
//        break;
//    case 5:
//        if (roles == lfg::LfgRoles::PLAYER_ROLE_DAMAGE)
//            talentType = 2;
//        else
//            talentType = urand(0, 1);
//        break;
//    case 7:
//        if (roles == lfg::LfgRoles::PLAYER_ROLE_HEALER)
//            talentType = 2;
//        else
//            talentType = urand(0, 1);
//        break;
//    case 11:
//        if (roles == lfg::LfgRoles::PLAYER_ROLE_HEALER)
//            talentType = 2;
//        else
//            talentType = urand(0, 1);
//        break;
//    }
//    return talentType;
//}
//
//lfg::LfgRoles PlayerBotMgr::GetPlayerBotCurrentLFGRoles(Player* player)
//{
//    if (!player)
//        return lfg::LfgRoles::PLAYER_ROLE_NONE;
//    uint32 talentType = player->FindTalentType();
//    switch (player->getClass())
//    {
//    case 1:
//        if (talentType == 2)
//            return lfg::LfgRoles::PLAYER_ROLE_TANK;
//        else
//            return lfg::LfgRoles::PLAYER_ROLE_DAMAGE;
//        break;
//    case 2:
//        if (talentType == 0)
//            return lfg::LfgRoles::PLAYER_ROLE_HEALER;
//        else if (talentType == 1)
//            return lfg::LfgRoles::PLAYER_ROLE_TANK;
//        else
//            return lfg::LfgRoles::PLAYER_ROLE_DAMAGE;
//        break;
//    case 6:
//        if (talentType == 1)
//            return lfg::LfgRoles::PLAYER_ROLE_TANK;
//        else
//            return lfg::LfgRoles::PLAYER_ROLE_DAMAGE;
//        break;
//    case 3:
//    case 4:
//    case 8:
//    case 9:
//        return lfg::LfgRoles::PLAYER_ROLE_DAMAGE;
//        break;
//    case 5:
//        if (talentType == 2)
//            return lfg::LfgRoles::PLAYER_ROLE_DAMAGE;
//        else
//            return lfg::LfgRoles::PLAYER_ROLE_HEALER;
//        break;
//    case 7:
//        if (talentType == 2)
//            return lfg::LfgRoles::PLAYER_ROLE_HEALER;
//        else
//            return lfg::LfgRoles::PLAYER_ROLE_DAMAGE;
//        break;
//    case 11:
//        if (talentType == 2)
//            return lfg::LfgRoles::PLAYER_ROLE_HEALER;
//        else
//            return lfg::LfgRoles::PLAYER_ROLE_DAMAGE;
//        break;
//    default:
//        return lfg::LfgRoles::PLAYER_ROLE_DAMAGE;
//    }
//    return lfg::LfgRoles::PLAYER_ROLE_DAMAGE;
//}
//
//ObjectGuid PlayerBotMgr::GetNoArenaMatchCharacter(TeamId team, uint32 arenaType, Classes cls, std::vector<ObjectGuid>& fliters)
//{
//    if (team != TEAM_ALLIANCE && team != TEAM_HORDE)
//        return ObjectGuid::Empty;
//    if (arenaType != 2 && arenaType != 3 && arenaType != 5)
//        return ObjectGuid::Empty;
//    if (m_idPlayerBotBase.empty())
//        return ObjectGuid::Empty;
//    std::vector<PlayerBotBaseInfo*> allBotBaseInfos;
//    for (std::map<uint32, PlayerBotBaseInfo*>::iterator itInfo = m_idPlayerBotBase.begin();
//        itInfo != m_idPlayerBotBase.end();
//        itInfo++)
//        allBotBaseInfos.push_back(itInfo->second);
//    for (uint32 i = allBotBaseInfos.size() - 1; i >= 0; --i)
//    {
//        PlayerBotBaseInfo* pInfo = allBotBaseInfos[i];
//        uint32 id = pInfo->GetCharIDByNoArenaType((team == TEAM_ALLIANCE) ? true : false, cls, arenaType, fliters);
//        if (id == 0)
//            continue;
//        bool exist = false;
//        for (ObjectGuid& guid : fliters)
//        {
//            if (guid.GetCounter() == id)
//            {
//                exist = true;
//                break;
//            }
//        }
//        if (!exist)
//            return ObjectGuid::Create<HighGuid::Player>(id);
//    }
//
//    //for (std::map<uint32, PlayerBotBaseInfo*>::iterator itInfo = m_idPlayerBotBase.begin();
//    //	itInfo != m_idPlayerBotBase.end();
//    //	itInfo++)
//    //{
//    //	PlayerBotBaseInfo* pInfo = itInfo->second;
//    //	uint32 id = pInfo->GetCharIDByNoArenaType((team == TEAM_ALLIANCE) ? true : false, cls, arenaType, fliters);
//    //	if (id == 0)
//    //		continue;
//    //	bool exist = false;
//    //	for (ObjectGuid& guid : fliters)
//    //	{
//    //		if (guid.GetCounter() == id)
//    //		{
//    //			exist = true;
//    //			break;
//    //		}
//    //	}
//    //	if (!exist)
//    //		return ObjectGuid(uint64(id));
//    //}
//    return ObjectGuid::Empty;
//}
//
//std::string PlayerBotMgr::GetNameANDClassesText(ObjectGuid& guid)
//{
//    for (std::map<uint32, PlayerBotBaseInfo*>::iterator itInfo = m_idPlayerBotBase.begin();
//        itInfo != m_idPlayerBotBase.end();
//        itInfo++)
//    {
//        PlayerBotBaseInfo* pInfo = itInfo->second;
//        std::string text = pInfo->GetCharNameANDClassesText(guid);
//        if (!text.empty())
//            return text;
//    }
//    return "";
//}
//
//bool PlayerBotMgr::CanReadyArenaByArenaTeamID(uint32 arenaTeamId)
//{
//
//    return true;
//}
//
//void PlayerBotMgr::QueryBattlegroundRequirement()
//{
//    for (BattleGroundTypes::iterator itType = m_BGTypes.begin(); itType != m_BGTypes.end(); itType++)
//    {
//        BattlegroundTypeId bgTypeID = *itType;
//        Battleground* bg_template = sBattlegroundMgr->GetBattlegroundTemplate(bgTypeID);
//        if (!bg_template)
//            continue;
//        auto& bgFreeSlotQueues = sBattlegroundMgr->BGFreeSlotQueue;
//        for (auto itr = bgFreeSlotQueues.begin(); itr != bgFreeSlotQueues.end(); itr++)
//        {
//            Battleground* bg = *itr;
//            if (!bg->ExistRealPlayer())
//                continue;
//            uint32 minLV = bg->GetMinLevel();
//            uint32 maxLV = bg->GetMaxLevel();
//            if (!bg->IsRated() && bg->GetStatus() > STATUS_WAIT_QUEUE && bg->GetStatus() < STATUS_WAIT_LEAVE)
//            {
//                if (bg->GetFreeSlotsForTeam(Team::ALLIANCE) > 0 && bg->GetFreeSlotsForTeam(Team::ALLIANCE) >= bg->GetFreeSlotsForTeam(Team::HORDE))
//                    AddNewPlayerBotToBG(TeamId::TEAM_ALLIANCE, minLV, maxLV, bgTypeID);
//                else if (bg->GetFreeSlotsForTeam(Team::HORDE) > 0)
//                    AddNewPlayerBotToBG(TeamId::TEAM_HORDE, minLV, maxLV, bgTypeID);
//                else
//                    continue;
//                return;
//            }
//        }
//
//        uint8 bgQueueTypeID = MS::Battlegrounds::GetBgQueueTypeIdByBgTypeID(bgTypeID, 0);
//        BattlegroundQueue& bgQueue = sBattlegroundMgr->GetBattlegroundQueue(bgQueueTypeID);
//        for (uint8 j = 0; j < MS::Battlegrounds::MaxBrackets; j++)
//        {
//            uint8 bracket = j;
//            PVPDifficultyEntry const* bracketEntry = sDB2Manager.GetBattlegroundBracketById(bg_template->GetMapId(), bracket);
//            if (!bracketEntry)
//                continue;
//            if (!bgQueue.ExistRealPlayer(bracketEntry))
//                continue;
//            int32 needAlliancePlayerCount = 0;
//            int32 needHordePlayerCount = 0;
//            if (bgQueue.QueryNeedPlayerCount(bgTypeID, bracket, 0, needAlliancePlayerCount, needHordePlayerCount))
//            {
//                if (needAlliancePlayerCount > 0 && needAlliancePlayerCount >= needHordePlayerCount)
//                    AddNewPlayerBotToBG(TeamId::TEAM_ALLIANCE, bracketEntry->MinLevel, bracketEntry->MaxLevel, bgTypeID);
//                else if (needHordePlayerCount > 0)
//                    AddNewPlayerBotToBG(TeamId::TEAM_HORDE, bracketEntry->MinLevel, bracketEntry->MaxLevel, bgTypeID);
//                else
//                    continue;
//                return;
//            }
//        }
//    }
//}
//
//void PlayerBotMgr::QueryRatedArenaRequirement()
//{
//    if (m_ArenaSearchTick > 0)
//    {
//        --m_ArenaSearchTick;
//        return;
//    }
//    Battleground* bg_template = sBattlegroundMgr->GetBattlegroundTemplate(MS::Battlegrounds::BattlegroundTypeId::ArenaAll);
//    if (!bg_template)
//        return;
//    PVPDifficultyEntry const* bracketEntry = FindBGBracketEntry(bg_template, 80);
//    if (!bracketEntry)
//        return;
//
//    uint32 arenaType[3] = { 2, 3, 5 };
//    for (uint32 i = 0; i < 3; i++)
//    {
//        uint8 bgQueueTypeID = MS::Battlegrounds::GetBgQueueTypeIdByBgTypeID(MS::Battlegrounds::BattlegroundTypeId::ArenaAll, arenaType[i]);
//        BattlegroundQueue& bgQueue = sBattlegroundMgr->GetBattlegroundQueue(bgQueueTypeID);
//        if (!bgQueue.ExistRealPlayer(bracketEntry, true))
//        {
//            bgQueue.AllPlayerBotLeaveQueueFromRatedArena(bracketEntry->RangeIndex);
//            continue;
//        }
//        uint32 allianceGroupID = 0;
//        uint32 hordeGroupID = 0;
//        GroupQueueInfo* allianceGroupInfo = bgQueue.GetFirstRealPlayerGroupInfo(bracketEntry->RangeIndex, MS::Battlegrounds::QueueGroupTypes::PremadeAlliance);
//        GroupQueueInfo* hordeGroupInfo = bgQueue.GetFirstRealPlayerGroupInfo(bracketEntry->RangeIndex, MS::Battlegrounds::QueueGroupTypes::PremadeHorde);
//        if (!allianceGroupInfo && !hordeGroupInfo)
//            continue;
//        if (allianceGroupInfo && hordeGroupInfo)
//        {
//            allianceGroupID = allianceGroupInfo->GroupId;
//            hordeGroupID = hordeGroupInfo->GroupId;
//        }
//        /*else if (allianceGroupInfo && !BotUtility::DownBotArenaTeam)
//        {
//            allianceGroupID = allianceGroupInfo->GroupId;
//            hordeGroupID = hordeGroupInfo->GroupId;
//            if (hordeGroupID == 0)
//                continue;
//            AddTeamBotToRatedArena(hordeGroupID);
//        }
//        else if (hordeGroupInfo && !BotUtility::DownBotArenaTeam)
//        {
//            hordeGroupID = hordeGroupInfo->GroupId;
//            allianceGroupID = sArenaTeamMgr->SearchEnemyArenaTeam(hordeGroupID, ALLIANCE);
//            if (allianceGroupID == 0)
//                continue;
//            AddTeamBotToRatedArena(allianceGroupID);
//        }*/
//        else
//            continue;
//        m_ArenaSearchTick = 14;
//        break;
//    }
//}
//
//void PlayerBotMgr::QueryNonRatedArenaRequirement()
//{
//    Battleground* bg_template = sBattlegroundMgr->GetBattlegroundTemplate(MS::Battlegrounds::BattlegroundTypeId::ArenaAll);
//    if (!bg_template)
//        return;
//    PVPDifficultyEntry const* bracketEntry = FindBGBracketEntry(bg_template, 110);
//    if (!bracketEntry)
//        return;
//    auto& bgFreeSlotQueues = sBattlegroundMgr->BGFreeSlotQueue;
//    for (auto itr = bgFreeSlotQueues.begin(); itr != bgFreeSlotQueues.end(); itr++)
//    {
//        Battleground* bg = *itr;
//        if (!bg->ExistRealPlayer())
//            continue;
//        if (bg->GetStatus() > STATUS_WAIT_QUEUE && bg->GetStatus() < STATUS_WAIT_LEAVE)
//        {
//            if (bg->GetFreeSlotsForTeam(Team::ALLIANCE) > 0)
//                AddNewPlayerBotToAA(TeamId::TEAM_ALLIANCE, MS::Battlegrounds::BattlegroundTypeId::ArenaAll, bracketEntry->RangeIndex, bg->GetMaxPlayers() / 2);
//            else if (bg->GetFreeSlotsForTeam(Team::HORDE) > 0)
//                AddNewPlayerBotToAA(TeamId::TEAM_HORDE, MS::Battlegrounds::BattlegroundTypeId::ArenaAll, bracketEntry->RangeIndex, bg->GetMaxPlayers() / 2);
//            else
//                continue;
//            return;
//        }
//    }
//
//    uint32 arenaType[3] = { 2, 3, 5 };
//    for (uint32 i = 0; i < 3; i++)
//    {
//        uint8 bgQueueTypeID = MS::Battlegrounds::GetBgQueueTypeIdByBgTypeID(MS::Battlegrounds::BattlegroundTypeId::ArenaAll, arenaType[i]);
//        BattlegroundQueue& bgQueue = sBattlegroundMgr->GetBattlegroundQueue(bgQueueTypeID);
//        if (!bgQueue.ExistRealPlayer(bracketEntry, false))
//            continue;
//        int32 needAlliancePlayerCount = 0;
//        int32 needHordePlayerCount = 0;
//        if (bgQueue.QueryNeedPlayerCount(MS::Battlegrounds::BattlegroundTypeId::ArenaAll, bracketEntry->RangeIndex, arenaType[i], needAlliancePlayerCount, needHordePlayerCount))
//        {
//            if (needAlliancePlayerCount > 0 && needAlliancePlayerCount >= needHordePlayerCount)
//                AddNewPlayerBotToAA(TeamId::TEAM_ALLIANCE, MS::Battlegrounds::BattlegroundTypeId::ArenaAll, bracketEntry->RangeIndex, arenaType[i]);
//            else if (needHordePlayerCount > 0)
//                AddNewPlayerBotToAA(TeamId::TEAM_HORDE, MS::Battlegrounds::BattlegroundTypeId::ArenaAll, bracketEntry->RangeIndex, arenaType[i]);
//            else
//                continue;
//            return;
//        }
//    }
//}
//
//void PlayerBotMgr::OnlinePlayerBotByGUIDQueue()
//{
//    while (!m_DelayOnlineBots.empty())
//    {
//        ObjectGuid& guid = m_DelayOnlineBots.front();
//        m_DelayOnlineBots.pop();
//        if (AddNewPlayerBotByGUID(guid))
//            return;
//    }
//}
//
//bool PlayerBotMgr::ExistUnBGPlayerBot()
//{
//    const SessionMap& allSession = sWorld->GetAllSessions();
//    for (SessionMap::const_iterator itSession = allSession.begin(); itSession != allSession.end(); itSession++)
//    {
//        if (!itSession->second->IsBotSession())
//            continue;
//        PlayerBotSession* pSession = dynamic_cast<PlayerBotSession*>((WorldSession*)itSession->second.get());
//        if (!pSession)
//            continue;
//        if (pSession->PlayerLoading() || pSession->IsAccountBotSession())
//            continue;
//        Player* player = pSession->GetPlayer();
//        if (!player || !player->IsInWorld())
//            continue;
//        if (player->InBattleground() || player->InBattlegroundQueue() || player->isUsingLfg() || player->GetGroup())
//            continue;
//        if (player->HasAura(26013))
//            continue;
//        if (!pSession->HasSchedules())
//            continue;
//        return true;
//    }
//    return false;
//}
//
//PVPDifficultyEntry const* PlayerBotMgr::FindBGBracketEntry(Battleground* bg_template, uint32 level)
//{
//    if (!bg_template)
//        return NULL;
//    for (uint32 j = 0; j < MS::Battlegrounds::MaxBrackets; j++)
//    {
//        uint8 bracket = j;
//        PVPDifficultyEntry const* bracketEntry = sDB2Manager.GetBattlegroundBracketById(bg_template->GetMapId(), bracket);
//        if (!bracketEntry)
//            continue;
//        if (bracketEntry->MinLevel <= level && bracketEntry->MaxLevel >= level)
//            return bracketEntry;
//    }
//    return NULL;
//}
//
//uint32 PlayerBotMgr::GetOnlineBotCount(TeamId team, bool hasReal)
//{
//    uint32 onlineCount = 0;
//    const SessionMap& allSession = sWorld->GetAllSessions();
//    for (SessionMap::const_iterator itSession = allSession.begin(); itSession != allSession.end(); itSession++)
//    {
//        if (itSession->second->IsBotSession())
//        {
//            PlayerBotSession* pSession = dynamic_cast<PlayerBotSession*>((WorldSession*)itSession->second.get());
//            if (!pSession)
//                continue;
//            if (pSession->PlayerLoading())
//            {
//                ++onlineCount;
//                continue;
//            }
//            Player* player = pSession->GetPlayer();
//            if (!player || !player->IsInWorld())
//                continue;
//            if (team != TEAM_NEUTRAL)
//            {
//                if (player->GetTeamId() != team)
//                    continue;
//            }
//            ++onlineCount;
//        }
//        else if (hasReal)
//        {
//            WorldSession* pSession = itSession->second.get();
//            if (pSession->PlayerLoading())
//                continue;
//            Player* player = pSession->GetPlayer();
//            if (!player || !player->IsInWorld())
//                continue;
//            if (team != TEAM_NEUTRAL)
//            {
//                if (player->GetTeamId() != team)
//                    continue;
//            }
//            ++onlineCount;
//        }
//    }
//    return onlineCount;
//}
//
//
//uint32 PlayerBotMgr::GetOnlineBotCount2(TeamId team, bool hasReal)
//{
//    uint32 onlineCount = 0;
//    const SessionMap& allSession = sWorld->GetAllSessions();
//    for (SessionMap::const_iterator itSession = allSession.begin(); itSession != allSession.end(); itSession++)
//    {
//        if (itSession->second->IsBotSession())
//        {
//            PlayerBotSession* pSession = dynamic_cast<PlayerBotSession*>((WorldSession*)itSession->second.get());
//            if (!pSession)
//                continue;
//            if (pSession->PlayerLoading())
//            {
//                //++onlineCount;
//                continue;
//            }
//            Player* player = pSession->GetPlayer();
//            if (!player || !player->IsInWorld())
//                continue;
//
//            if (!player->InBattleground() && !player->InBattlegroundQueue())
//                continue;
//
//            if (team != TEAM_NEUTRAL)
//            {
//                if (player->GetTeamId() != team)
//                    continue;
//            }
//            ++onlineCount;
//        }
//        else if (hasReal)
//        {
//            WorldSession* pSession = itSession->second.get();
//            if (pSession->PlayerLoading())
//                continue;
//            Player* player = pSession->GetPlayer();
//            if (!player || !player->IsInWorld())
//                continue;
//
//            if (!player->InBattleground() && !player->InBattlegroundQueue())
//                continue;
//
//            if (team != TEAM_NEUTRAL)
//            {
//                if (player->GetTeamId() != team)
//                    continue;
//            }
//            ++onlineCount;
//        }
//    }
//    return onlineCount;
//}
//
//void PlayerBotMgr::Update()
//{
//
//    OnlinePlayerBotByGUIDQueue();
//
//    //if (!ExistUnBGPlayerBot())
//    QueryBattlegroundRequirement();
//#ifndef INCOMPLETE_BOT
//    //sArenaTeamMgr->CheckPlayerBotArenaTeam();
//    QueryRatedArenaRequirement();
//    QueryNonRatedArenaRequirement();
//    if (m_LFGSearchTick > 1)
//    {
//        m_LFGSearchTick = 0;
//        //if (lfg::LFGBotRequirement* pbotReq = sLFGMgr->SearchLFGBotRequirement())
//        //{
//        //	AddNewPlayerBotToLFG(pbotReq);
//        //	delete pbotReq;
//        //}
//    }
//    else
//        ++m_LFGSearchTick;
//#endif
//
//    std::list<std::map<uint32, std::list<UnitAI*> >::iterator > delITer;
//    uint32 currentTick = getMSTime();
//    for (std::map<uint32, std::list<UnitAI*> >::iterator itDelayAi = m_DelayDestroyAIs.begin();
//        itDelayAi != m_DelayDestroyAIs.end();
//        itDelayAi++)
//    {
//        uint32 delayTick = itDelayAi->first;
//        if (delayTick + 5000 >= currentTick)
//        {
//            for (std::list<UnitAI*>::iterator itAI = itDelayAi->second.begin();
//                itAI != itDelayAi->second.end();
//                itAI++)
//            {
//                UnitAI* pAI = (*itAI);
//                if (pAI)
//                    delete pAI;
//            }
//            itDelayAi->second.clear();
//            delITer.push_back(itDelayAi);
//        }
//    }
//    for (std::list<std::map<uint32, std::list<UnitAI*> >::iterator >::iterator itDel = delITer.begin();
//        itDel != delITer.end();
//        itDel++)
//    {
//        m_DelayDestroyAIs.erase(*itDel);
//    }
//}


#include "Config.h"
#include "PlayerBotMgr.h"
#include "EventProcessor.h"
#include "World.h"
#include "DB2Stores.h"
#include "Player.h"
#include "BattlegroundMgr.h"
#include "BotAI.h"
#include "BotFieldAI.h"
#include "BotGroupAI.h"
#include "BotDuelAI.h"
#include "BotArenaAI.h"
#include "Group.h"
#include "SocialMgr.h"
#include "GuildMgr.h"
#include "Guild.h"
#include "GroupMgr.h"
#include "LFGMgr.h"
#include "AccountMgr.h"
#include "CharacterPackets.h"
#include <boost/algorithm/string.hpp>
//#include <boost/format.hpp>

PlayerBotCharBaseInfo PlayerBotBaseInfo::empty;
std::map<uint32, std::list<UnitAI*> > PlayerBotMgr::m_DelayDestroyAIs;
std::mutex PlayerBotMgr::g_uniqueLock;

std::string PlayerBotCharBaseInfo::GetNameANDClassesText()
{
    std::string sClass = "";
    if (ChrClassesEntry const* cEntry = sChrClassesStore.LookupEntry(Class))
        //  sClass = cEntry->Name->Str[LOCALE_zhCN];
        return sClass + name;
    return "I wrote this:2023.4.10-19:22";
}

uint32 PlayerBotBaseInfo::GetCharIDByNoArenaType(TeamId /*team*/, uint32 /*prof*/, uint32 /*arenaType*/, std::vector<ObjectGuid>& /*fliters*/)
{/*todo47
 for (ObjectGuid& guid : fliters)
 {
 if (ExistCharacterByGUID(guid))
 return 0;
 }
 #ifdef INCOMPLETE_BOT
 if (prof != 1 && prof != 5 && prof != 9)
 return 0;
 #endif
 if (characters.size() <= 0)
 return 0;
 for (std::map<uint32, PlayerBotCharBaseInfo>::iterator it = characters.begin();
 it != characters.end();
 it++)
 {
 if (!MatchRaceByFuction(faction, it->second.race))
 continue;
 if (it->second.profession != prof)
 continue;
 if (sArenaTeamMgr->GetArenaTypeTeamByGUID(ObjectGuid(uint64(it->second.guid)), arenaType) == NULL)
 return it->second.guid;
 }*/
    return 0;
}

PlayerBotMgr::PlayerBotMgr() :
    m_LastBotAccountIndex(0),
    m_BotOnlineCount(0),
    m_LFGSearchTick(0),
    m_BGSearchTick(0),
    m_ArenaSearchTick(0)
{
    m_BGTypes.push_back(BattlegroundTypeId::BATTLEGROUND_WS);
    m_BGTypes.push_back(BattlegroundTypeId::BATTLEGROUND_AB);
    m_BGTypes.push_back(BattlegroundTypeId::BATTLEGROUND_EY);
#ifndef NON_SINGLE_GAME
    m_BGTypes.push_back(BattlegroundTypeId::BATTLEGROUND_AV);
    m_BGTypes.push_back(BattlegroundTypeId::BATTLEGROUND_IC);
    //m_BGTypes.push_back(BattlegroundTypeId::BATTLEGROUND_SA);
#endif

    m_BotAccountAmount = sWorld->getIntConfig(CONFIG_PBOT_ACCOUNT_COUNT);
    m_MaxOnlineBot = sWorld->getIntConfig(CONFIG_PBOT_MAX_ONLINE_COUNT);
    m_AutoLoginAliCount = sWorld->getIntConfig(CONFIG_PBOT_AUTOLOGIN_A_COUNT);
    m_AutoLoginHorCount = sWorld->getIntConfig(CONFIG_PBOT_AUTOLOGIN_H_COUNT);
    m_AutoLoginStarted = false;
    is_break = false;
}

PlayerBotMgr::~PlayerBotMgr()
{
    m_Events.KillAllEvents(true);
    ClearBaseInfo();
}

PlayerBotMgr* PlayerBotMgr::instance()
{
    static PlayerBotMgr instance;
    return &instance;
}

void PlayerBotMgr::SwitchPlayerBotAI(Player* player, PlayerBotAIType aiType, bool force)
{
    if (!force && player->IsInCombat())
        return;
    if (force && player->IsInCombat())
        player->ClearInCombat();
    player->SetSelection(ObjectGuid::Empty);
    UnitAI* pAI = player->GetAI();
    player->IsAIEnabled();//false
    switch (aiType)
    {
    case PlayerBotAIType::PBAIT_FIELD:
        if (pAI)
        {
            if (dynamic_cast<BotFieldAI*>(pAI) != NULL)
            {
                player->IsAIEnabled();
                return;
            }
            PlayerBotMgr::m_DelayDestroyAIs[getMSTime()].push_back(pAI);
            player->SetAI(NULL);
        }
        pAI = BotFieldAI::CreateBotFieldAIByPlayerClass(player);
        if (pAI)
        {
            pAI->Reset();
            player->SetAI(pAI);
            player->IsAIEnabled();
        }
        break;
    case PlayerBotAIType::PBAIT_GROUP:
        if (pAI)
        {
            if (dynamic_cast<BotGroupAI*>(pAI) != NULL)
            {
                player->IsAIEnabled();
                return;
            }
            PlayerBotMgr::m_DelayDestroyAIs[getMSTime()].push_back(pAI);
            player->SetAI(NULL);
        }
        pAI = BotGroupAI::CreateBotGroupAIByPlayerClass(player);
        if (pAI)
        {
            pAI->Reset();
            player->SetAI(pAI);
            player->IsAIEnabled();
        }
        break;
    case PlayerBotAIType::PBAIT_DUEL:
        if (pAI)
        {
            if (dynamic_cast<BotDuelAI*>(pAI) != NULL)
            {
                player->IsAIEnabled();
                return;
            }
            PlayerBotMgr::m_DelayDestroyAIs[getMSTime()].push_back(pAI);
            player->SetAI(NULL);
        }
        pAI = BotDuelAI::CreateBotDuelAIByPlayerClass(player);
        if (pAI)
        {
            pAI->Reset();
            player->SetAI(pAI);
            player->IsAIEnabled();
            ((BotDuelAI*)pAI)->ResetBotAI();
        }
        break;
    case PlayerBotAIType::PBAIT_ARENA:
#ifndef CONVERT_ARENAAI_TOBG
        if (pAI)
        {
            if (dynamic_cast<BotArenaAI*>(pAI) != NULL)
            {
                player->IsAIEnabled();
                return;
            }
            PlayerBotMgr::m_DelayDestroyAIs[getMSTime()].push_back(pAI);
            player->SetAI(NULL);
        }
        pAI = BotArenaAI::CreateBotArenaAIByPlayerClass(player);
        if (pAI)
        {
            pAI->Reset();
            player->SetAI(pAI);
            player->IsAIEnabled();
        }
        break;
#endif
    case PlayerBotAIType::PBAIT_BG:
        if (pAI)
        {
            if (dynamic_cast<BotBGAI*>(pAI) != NULL)
            {
                player->IsAIEnabled();
                return;
            }
            PlayerBotMgr::m_DelayDestroyAIs[getMSTime()].push_back(pAI);
            player->SetAI(NULL);
        }
        player->SetAI(BotBGAI::CreateBotBGAIByPlayerClass(player));
        player->IsAIEnabled();
        break;
    case PlayerBotAIType::PBAIT_DUNGEON:
        if (pAI)
        {
            //if (dynamic_cast<BotFieldAI*>(pAI) != NULL)
            //{
            //	player->IsAIEnabled();
            //	return;
            //}
            PlayerBotMgr::m_DelayDestroyAIs[getMSTime()].push_back(pAI);
            player->SetAI(NULL);
        }
        break;
    }
}

std::string PlayerBotMgr::GetPlayerLinkText(Player const* player) const
{
    const std::string& name = player->GetName();
    if (player->GetTeamId() == TeamId::TEAM_ALLIANCE)
        return "|cff0000ff|Hplayer:" + name + "|h[" + name + "]|h|r";
    else if (player->GetTeamId() == TeamId::TEAM_HORDE)
        return "|cffff0000|Hplayer:" + name + "|h[" + name + "]|h|r";
    return "|cffffffff|Hplayer:" + name + "|h[" + name + "]|h|r";
}

PlayerBotSession* PlayerBotMgr::GetBotSessionByCharGUID(ObjectGuid& guid)
{
    for (std::map<uint32, PlayerBotBaseInfo*>::iterator itInfo = m_idPlayerBotBase.begin();
        itInfo != m_idPlayerBotBase.end();
        itInfo++)
    {
        PlayerBotBaseInfo* pInfo = itInfo->second;
        if (!(pInfo->ExistCharacterByGUID(guid)))
            continue;
        WorldSession* pWorldSession = sWorld->FindSession(pInfo->id);
        if (!pWorldSession)
            return NULL;
        PlayerBotSession* pSession = dynamic_cast<PlayerBotSession*>(pWorldSession);
        return pSession;
    }
    return NULL;
}

TeamId PlayerBotMgr::GetTeamIDByPlayerBotGUID(ObjectGuid& guid)
{
    for (std::map<uint32, PlayerBotBaseInfo*>::iterator itInfo = m_idPlayerBotBase.begin();
        itInfo != m_idPlayerBotBase.end();
        itInfo++)
    {
        PlayerBotBaseInfo* pInfo = itInfo->second;
        TeamId team = pInfo->GetTeamIDByChar(guid);
        if (team == TeamId::TEAM_NEUTRAL)
            continue;
        return team;
    }
    return TeamId::TEAM_NEUTRAL;
}

bool PlayerBotMgr::IsPlayerBot(WorldSession* pSession)
{
    if (pSession && dynamic_cast<PlayerBotSession*> (pSession))
        return true;
    return false;
}

bool PlayerBotMgr::IsBotAccuntName(std::string name)
{
    if (name.size() < 10)
        return false;
    std::string head = name.substr(0, 9);
    if (head != "playerbot")
        return false;
    std::string numText = name.substr(9);
    int num = atoi(numText.c_str());
    return num > 0;
}

bool PlayerBotMgr::IsIDLEPlayerBot(Player* player)
{
    if (!player || player->IsLoading() || !player->IsInWorld())
        return false;
    if (!player->IsAlive())//player->IsInCombat() || 
        return false;
    if (player->InBattleground() || player->InArena() || player->GetMap()->IsDungeon() ||
        player->GetGroup() || player->isUsingLfg())
        return false;
    if (player->InBattlegroundQueue())
        return false;
    if (!player->IsSettingFinish())
        return false;
    if (player->HasAura(26013))
        return false;
    return true;
}
/*todo47
std::set<uint32> PlayerBotMgr::GetArenaTeamPlayerBotIDCountByTeam(TeamId team, int32 count, ArenaTeamTypes type)
{
std::vector<uint32> allInfoEntrys;
for (std::map<uint32, PlayerBotBaseInfo*>::iterator itInfo = m_idPlayerBotBase.begin(); itInfo != m_idPlayerBotBase.end(); itInfo++)
allInfoEntrys.push_back(itInfo->first);
Trinity::Containers::RandomShuffle(allInfoEntrys);
//unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
//std::shuffle(allInfoEntrys.begin(), allInfoEntrys.end(), std::default_random_engine(seed));

std::set<uint32> ids;
if (allInfoEntrys.empty())
return ids;
for (uint32 infoEntry : allInfoEntrys)
{
PlayerBotBaseInfo* info = GetPlayerBotAccountInfo(infoEntry);
if (!info)
continue;
std::vector<uint32> faildIDs = info->GetNoArenaTeamCharacterIDsByFuction((team == TEAM_ALLIANCE) ? true : false, type);
if (faildIDs.empty())
continue;
for (uint32 id : faildIDs)
{
if (ids.find(id) != ids.end())
continue;
ids.insert(id);
break;
}
if (ids.size() >= uint32(count))
return ids;
}
ids.clear();
return ids;
}
*/
PlayerBotBaseInfo* PlayerBotMgr::GetPlayerBotAccountInfo(uint32 guid)
{
    std::map<uint32, PlayerBotBaseInfo*>::iterator it = m_idPlayerBotBase.find(guid);
    if (it == m_idPlayerBotBase.end())
        return NULL;
    return it->second;
}

PlayerBotBaseInfo* PlayerBotMgr::GetAccountBotAccountInfo(uint32 guid)
{
    std::map<uint32, PlayerBotBaseInfo*>::iterator it = m_idAccountBotBase.find(guid);
    if (it == m_idAccountBotBase.end())
        return NULL;
    return it->second;
}

bool PlayerBotMgr::ExistClassByRace(uint8 race, uint8 prof)
{
    switch (prof)
    {
    case CLASS_WARRIOR:
        return (race != RACE_BLOODELF);
    case CLASS_PALADIN:
        return (race == RACE_HUMAN || race == RACE_DWARF || race == RACE_BLOODELF || race == RACE_DRAENEI);
    case CLASS_HUNTER:
        return (race == RACE_ORC || race == RACE_DWARF || race == RACE_NIGHTELF || race == RACE_TAUREN || race == RACE_TROLL || race == RACE_BLOODELF || race == RACE_DRAENEI);
    case CLASS_ROGUE:
        return (race == RACE_HUMAN || race == RACE_ORC || race == RACE_DWARF || race == RACE_NIGHTELF || race == RACE_UNDEAD_PLAYER || race == RACE_GNOME || race == RACE_TROLL || race == RACE_BLOODELF);
    case CLASS_PRIEST:
        return (race == RACE_HUMAN || race == RACE_DWARF || race == RACE_NIGHTELF || race == RACE_UNDEAD_PLAYER || race == RACE_TROLL || race == RACE_BLOODELF || race == RACE_DRAENEI);
    case CLASS_DEATH_KNIGHT:
        return true;
    case CLASS_SHAMAN:
        return (race == RACE_ORC || race == RACE_TAUREN || race == RACE_TROLL || race == RACE_DRAENEI);
    case CLASS_MAGE:
        return (race == RACE_HUMAN || race == RACE_UNDEAD_PLAYER || race == RACE_GNOME || race == RACE_TROLL || race == RACE_BLOODELF || race == RACE_DRAENEI);
    case CLASS_WARLOCK:
        return (race == RACE_HUMAN || race == RACE_ORC || race == RACE_UNDEAD_PLAYER || race == RACE_GNOME || race == RACE_BLOODELF);
    case CLASS_MONK:
        return true;
    case CLASS_DRUID:
        return (race == RACE_NIGHTELF || race == RACE_TAUREN);
    case CLASS_DEMON_HUNTER:
        return (race == RACE_NIGHTELF || race == RACE_BLOODELF);
    }
    return false;
}
void PlayerBotMgr::InitializeCreatePlayerBotName()
{
    allName.clear();
    LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_ALLRANDOM_NAME);
    PreparedQueryResult result = LoginDatabase.Query(stmt);
    if (result)
    {
        do
        {
            Field* fields = result->Fetch();
            std::string dbName = fields[1].GetString();
            if (dbName.size() > 0)
                allName.push_back(dbName);
        } while (result->NextRow());
    }

    allArenaName.clear();
    LoginDatabasePreparedStatement* stmt2 = LoginDatabase.GetPreparedStatement(LOGIN_SEL_ALLARENA_NAME);
    PreparedQueryResult result2 = LoginDatabase.Query(stmt2);
    if (result2)
    {
        do
        {
            Field* fields = result2->Fetch();
            std::string dbName = fields[1].GetString();
            if (dbName.size() > 0)
                allArenaName.push_back(dbName);
        } while (result2->NextRow());
    }
}
std::string PlayerBotMgr::RandomName()
{
    if (allName.size() <= 0)
        InitializeCreatePlayerBotName();
    int32 maxLoop = allName.size() / 2;
    if (maxLoop <= 0)
        return "";
    do
    {
        uint32 index = irand(0, allName.size() - 1);
        std::string selectName = allName[index];
        std::string sql = "SELECT guid FROM characters WHERE name = '" + selectName + "'";
        QueryResult result = CharacterDatabase.Query(sql.c_str());
        if (!result)
            return selectName;
        --maxLoop;
        if (maxLoop <= 0)
            break;
    } while (true);
    return "";
}
std::string PlayerBotMgr::RandomArenaName()
{/*todo47
 if (allArenaName.size() <= 0)
 InitializeCreatePlayerBotName();
 std::vector<std::string> rndArenaName;
 for (std::string& selectName : allArenaName)
 {
 rndArenaName.push_back(selectName);
 }
 Trinity::Containers::RandomShuffle(rndArenaName);
 //unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
 //std::shuffle(rndArenaName.begin(), rndArenaName.end(), std::default_random_engine(seed));
 for (std::string& selectName : rndArenaName)
 {
 if (!sArenaTeamMgr->GetArenaTeamByName(selectName))
 return selectName;
 }*/
    return "";
}
uint8 PlayerBotMgr::RandomRace(bool group, uint8 prof)
{
    uint8 race = 1;
    for (int i = 0; i < 80; i++)
    {
        race = irand(1, 11);
        if (race == RACE_GOBLIN) continue;
        if (group)
        {
            if (race == RACE_HUMAN || race == RACE_DWARF || race == RACE_NIGHTELF || race == RACE_GNOME || race == RACE_DRAENEI)
            {
                if (ExistClassByRace(race, prof))
                    return race;
            }
        }
        else
        {
            if (race == RACE_ORC || race == RACE_UNDEAD_PLAYER || race == RACE_TAUREN || race == RACE_TROLL || race == RACE_BLOODELF)
            {
                if (ExistClassByRace(race, prof))
                    return race;
            }
        }
    }

    TC_LOG_INFO("server.loading", ">> Random player custom Race timeout!");
    if (group)
        return 1;
    return 2;
}
uint8 PlayerBotMgr::RandomSkinColor(uint8 /*race*/, uint8 /*gender*/, uint8 /*prof*/)
{
    uint8 skinColor = 0;
    for (int i = 0; i < 80; i++)
    {
        skinColor = irand(0, 9);
        /*  CharSectionsEntry const* entry = sDB2Manager.GetCharSectionEntry(race, gender, CharBaseSectionVariation::Skin, 0, skinColor);
          if (entry)
          {
              if ((entry->Flags & SECTION_FLAG_DEATH_KNIGHT) && prof != CLASS_DEATH_KNIGHT)
                  continue;
              if (!(entry->Flags & SECTION_FLAG_PLAYER))
                  continue;
              return skinColor;
          }*/
    }
    TC_LOG_INFO("server.loading", ">> Random player custom SkinColor timeout!");
    return 1;
}
uint8 PlayerBotMgr::RandomFace(uint8 /*race*/, uint8 /*gender*/, uint8 /*skinColor*/, uint8 /*prof*/)
{
    uint8 faceID = 0;
    for (int i = 0; i < 80; i++)
    {
        faceID = irand(0, 9);
        /* CharSectionsEntry const* entry = sDB2Manager.GetCharSectionEntry(race, gender, CharBaseSectionVariation::Face, faceID, skinColor);
         if (entry)
         {
             if ((entry->Flags & SECTION_FLAG_DEATH_KNIGHT) && prof != CLASS_DEATH_KNIGHT)
                 continue;
             if (!(entry->Flags & SECTION_FLAG_PLAYER))
                 continue;
             return faceID;
         }*/
    }
    TC_LOG_INFO("server.loading", ">> Random player custom Face timeout!");
    return 1;
}
uint8 PlayerBotMgr::RandomHair(uint8 /*race*/, uint8 /*gender*/, uint8 /*prof*/)
{
    uint8 hairID = 0;
    for (uint8 hc = 0; hc < 80; hc++)
    {
        for (int i = 0; i < 80; i++)
        {
            hairID = irand(0, 8);
            /*CharSectionsEntry const* entry = sDB2Manager.GetCharSectionEntry(race, gender, CharBaseSectionVariation::Hair, hairID, hc);
            if (entry)
            {
                if ((entry->Flags & SECTION_FLAG_DEATH_KNIGHT) && prof != CLASS_DEATH_KNIGHT)
                    continue;
                if (!(entry->Flags & SECTION_FLAG_PLAYER))
                    continue;
                return hairID;
            }*/
        }
    }
    TC_LOG_INFO("server.loading", ">> Random player custom Hair timeout!");
    return 0;
}
uint8 PlayerBotMgr::RandomHairColor(uint8 /*race*/, uint8 /*gender*/, uint8 /*hairID*/, uint8 /*prof*/)
{
    uint8 hairColor = 0;
    for (int i = 0; i < 80; i++)
    {
        hairColor = irand(0, 8);
        /* CharSectionsEntry const* entry = sDB2Manager.GetCharSectionEntry(race, gender, CharBaseSectionVariation::Hair, hairID, hairColor);
         if (entry)
         {
             if ((entry->Flags & SECTION_FLAG_DEATH_KNIGHT) && prof != CLASS_DEATH_KNIGHT)
                 continue;
             if (!(entry->Flags & SECTION_FLAG_PLAYER))
                 continue;
             return hairColor;
         }*/
    }
    TC_LOG_INFO("server.loading", ">> Random player custom HairColor timeout!");
    return 1;
}
uint8 PlayerBotMgr::RandomFacialHair(uint8 /*race*/, uint8 /*gender*/, uint8 /*hairColor*/, uint8 /*prof*/)
{
    uint8 facialHair = 0;
    for (int i = 0; i < 80; i++)
    {
        facialHair = irand(0, 7);
        /* CharSectionsEntry const* entry = sDB2Manager.GetCharSectionEntry(race, gender, CharBaseSectionVariation::Hair, facialHair, hairColor);
         if (entry)
         {
             if ((entry->Flags & SECTION_FLAG_DEATH_KNIGHT) && prof != CLASS_DEATH_KNIGHT)
                 continue;
             if (!(entry->Flags & SECTION_FLAG_PLAYER))
                 continue;
             return facialHair;
         }*/
    }
    TC_LOG_INFO("server.loading", ">> Random player custom FacialHair timeout!");
    return 0;
}

createInfo PlayerBotMgr::BuildCreatePlayerData(bool group, uint8 prof)
{
    createInfo res;
    std::string name = RandomName();
    uint8 race = RandomRace(group, prof);
    uint8 gender = irand(0, 1);
    uint8 skinColor = RandomSkinColor(race, gender, prof);
    uint8 faceID = RandomFace(race, gender, skinColor, prof);
    uint8 hairID = RandomHair(race, gender, prof);
    uint8 hairColor = RandomHairColor(race, gender, hairID, prof);
    uint8 facialHair = RandomFacialHair(race, gender, hairColor, prof);

    res.Name = name;
    res.Race = race;
    res.Class = prof;
    res.Sex = gender;
    res.Skin = skinColor;
    res.Face = faceID;
    res.HairStyle = hairID;
    res.HairColor = hairColor;
    res.FacialHairStyle = facialHair;
    res.OutfitId = 0;//OutfitId

    return res;
}

void PlayerBotMgr::CreateOncePlayerBot()
{
    for (std::map<uint32, PlayerBotBaseInfo*>::iterator it = m_idPlayerBotBase.begin();
        it != m_idPlayerBotBase.end();
        it++)
    {
        PlayerBotBaseInfo* pInfo = it->second;
        if (pInfo->needCreateBots.size() > 0)
        {
            createInfo createinfo = pInfo->needCreateBots.front();
            WorldSession* pSession = sWorld->FindSession(pInfo->id);
            if (pSession)
            {
                WorldPacket packet;
                WorldPackets::Character::CreateCharacter CharCreate(std::move(packet));
                CharCreate.CreateInfo.reset(new WorldPackets::Character::CharacterCreateInfo());
                CharCreate.CreateInfo->Race = createinfo.Race;
                CharCreate.CreateInfo->Class = createinfo.Class;
                CharCreate.CreateInfo->Sex = createinfo.Sex;
                //CharCreate.CreateInfo->Skin = createinfo.Skin;
                //CharCreate.CreateInfo->Face = createinfo.Face;
                //CharCreate.CreateInfo->HairStyle = createinfo.HairStyle;
                //CharCreate.CreateInfo->HairColor = createinfo.HairColor;
                //CharCreate.CreateInfo->FacialHairStyle = createinfo.FacialHairStyle;
                //CharCreate.CreateInfo->OutfitId = createinfo.OutfitId;
                CharCreate.CreateInfo->Name = createinfo.Name;
                pSession->HandleCharCreateOpcode(CharCreate);
            }
            pInfo->needCreateBots.pop();
            break;
        }
    }
}

void PlayerBotMgr::ClearBaseInfo()
{
    for (std::map<uint32, PlayerBotBaseInfo*>::iterator it = m_idPlayerBotBase.begin();
        it != m_idPlayerBotBase.end();
        it++)
    {
        delete it->second;
    }
    m_idPlayerBotBase.clear();
    for (std::map<uint32, PlayerBotBaseInfo*>::iterator it = m_idAccountBotBase.begin();
        it != m_idAccountBotBase.end();
        it++)
    {
        delete it->second;
    }
    m_idAccountBotBase.clear();
}

void PlayerBotMgr::UpdateLastAccountIndex(std::string& username)
{
    //std::unique_lock<std::mutex> sessionGuard(PlayerBotMgr::g_uniqueLock);
    if (username.empty())
        return;
    std::string querySql = "SELECT id FROM account WHERE username='" + username + "'";
    QueryResult result = LoginDatabase.Query(querySql.c_str());
    if (result)
    {
        Field* fields = result->Fetch();
        if (fields)
        {
            uint32 id = fields[0].GetUInt32();
            m_LastBotAccountIndex = id;
        }
    }
}

void PlayerBotMgr::SupplementAccount()
{
    int32 needAccount = m_BotAccountAmount * 2 - m_idPlayerBotBase.size();
    if (needAccount <= 0)
        return;

    for (int32 i = 0; i < needAccount; i++)
    {
        ++m_LastBotAccountIndex;
        char indexText[25] = { 0 };
        itoa(m_LastBotAccountIndex, indexText, 10);
        std::string userName = "playerbot";
        userName += indexText;
        if (sAccountMgr->CreateAccount(userName, userName, "PBot@email.com") == AccountOpResult::AOR_OK)
        {
            std::string querySql = "SELECT id, username, sha_pass_hash FROM account WHERE username='";
            querySql += userName + "'";
            QueryResult result = LoginDatabase.Query(querySql.c_str());
            if (result)
            {
                Field* fields = result->Fetch();
                if (fields)
                {
                    uint32 id = fields[0].GetUInt32();
                    std::string username = fields[1].GetString();
                    std::string pass = fields[2].GetString();

                    std::string lowerName = boost::algorithm::to_lower_copy(username);
                    if (m_idPlayerBotBase.find(id) == m_idPlayerBotBase.end())
                    {
                        PlayerBotBaseInfo* pInfo = new PlayerBotBaseInfo(id, username.c_str(), pass, false);
                        m_idPlayerBotBase[id] = pInfo;
                    }
                    m_LastBotAccountIndex = id;
                }
            }
        }
    }
}

void PlayerBotMgr::DestroyBotMail(uint32 guid)
{
    char sql[256] = { 0 };
    sprintf_s(sql, 255, "DELETE FROM mail WHERE receiver = %d", guid);
    CharacterDatabase.Execute(sql);
    //memset(sql, 0, 256);
    //sprintf_s(sql, 255, "DELETE FROM mail_items WHERE receiver = %d", guid);
    //CharacterDatabase.Execute(sql);
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_MAIL_ITEMS);
    stmt->setUInt32(0, guid);
    CharacterDatabase.Execute(stmt);
}

void PlayerBotMgr::AddNewAccountBotBaseInfo(std::string name)
{
    std::string upperName = boost::algorithm::to_upper_copy(name);
    std::string sql("SELECT id, username, sha_pass_hash FROM account WHERE `username`='"); sql += upperName + "'";
    QueryResult result = LoginDatabase.Query(sql.c_str());
    if (!result)
        return;
    Field* fields = result->Fetch();
    uint32 id = fields[0].GetUInt32();
    std::string username = fields[1].GetString();
    std::string pass = fields[2].GetString();
    if (m_idAccountBotBase.find(id) == m_idAccountBotBase.end())
    {
        PlayerBotBaseInfo* pInfo = new PlayerBotBaseInfo(id, username.c_str(), pass, true);
        m_idAccountBotBase[id] = pInfo;
    }
}

void PlayerBotMgr::LoadPlayerBotBaseInfo()
{
    uint32 oldMSTime = getMSTime();

    ClearBaseInfo();
    QueryResult result = LoginDatabase.Query("SELECT id, username, sha_pass_hash FROM account");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> LoadPlayerBot Find 0 account!");
        return;
    }

    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        std::string username = fields[1].GetString();
        std::string pass = fields[2].GetString();
        //sOnlineMgr->AddNewAccount(id, username); // Real player acc and bot acc all in

        std::string lowerName = boost::algorithm::to_lower_copy(username);
        if (IsBotAccuntName(lowerName))
        {
            if (m_idPlayerBotBase.find(id) == m_idPlayerBotBase.end())
            {
                PlayerBotBaseInfo* pInfo = new PlayerBotBaseInfo(id, username.c_str(), pass, false);
                m_idPlayerBotBase[id] = pInfo;
            }
            m_LastBotAccountIndex = id;
        }
        else
        {
            if (m_idAccountBotBase.find(id) == m_idAccountBotBase.end())
            {
                PlayerBotBaseInfo* pInfo = new PlayerBotBaseInfo(id, username.c_str(), pass, true);
                m_idAccountBotBase[id] = pInfo;
            }
        }
        //if (m_idPlayerBotBase.size() >= m_BotAccountAmount * 2)
        //	break;
    } while (result->NextRow());

    SupplementAccount();

    if (m_idPlayerBotBase.size() > 0 || m_idAccountBotBase.size() > 0)
        LoadCharBaseInfo();

    TC_LOG_INFO("server.loading", ">> Loaded %u Player bot account base info in %u ms", m_idPlayerBotBase.size(), GetMSTimeDiffToNow(oldMSTime));
}

void PlayerBotMgr::LoadCharBaseInfo()
{
    QueryResult result = CharacterDatabase.Query("SELECT guid, account, name, race, class, gender, level FROM characters");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> LoadPlayerBot Find 0 characters!");
        return;
    }

    do
    {
        Field* fields = result->Fetch();

        uint32 guid = fields[0].GetUInt32();
        uint32 accID = fields[1].GetUInt32();
        PlayerBotBaseInfo* pInfo = GetPlayerBotAccountInfo(accID);
        if (pInfo)
        {
            if (pInfo->characters.find(guid) == pInfo->characters.end())
            {
                std::string charName = fields[2].GetString();
                uint16 race = fields[3].GetInt16();
                uint16 cls = fields[4].GetInt16();
                uint16 gender = fields[5].GetInt16();
                uint16 level = fields[6].GetInt16();
                pInfo->characters[guid] = PlayerBotCharBaseInfo(guid, accID, charName, race, cls, gender, level);
                DestroyBotMail(guid);
            }
        }
        else if (pInfo = GetAccountBotAccountInfo(accID))
        {
            if (pInfo->characters.find(guid) == pInfo->characters.end())
            {
                std::string charName = fields[2].GetString();
                uint16 race = fields[3].GetInt16();
                uint16 cls = fields[4].GetInt16();
                uint16 gender = fields[5].GetInt16();
                uint16 level = fields[6].GetInt16();
                pInfo->characters[guid] = PlayerBotCharBaseInfo(guid, accID, charName, race, cls, gender, level);
                //DestroyBotMail(guid);
            }
        }
    } while (result->NextRow());
}

void PlayerBotMgr::UpAllPlayerBotSession()
{
    PlayerBotSetting::Initialize();
    for (std::map<uint32, PlayerBotBaseInfo*>::iterator it = m_idPlayerBotBase.begin();
        it != m_idPlayerBotBase.end();
        it++)
    {
        PlayerBotBaseInfo* pInfo = it->second;
        UpPlayerBotSessionByBaseInfo(pInfo, false);
    }
}

PlayerBotSession* PlayerBotMgr::UpPlayerBotSessionByBaseInfo(PlayerBotBaseInfo* pAcc, bool accountInfo)
{
    if (!pAcc)
        return NULL;
    WorldSession* pSession = sWorld->FindSession(pAcc->id);
    if (pSession)
        return NULL;
    std::string name = pAcc->username.c_str();
    PlayerBotSession* pBotSession = new PlayerBotSession(pAcc->id, name, AccountTypes::SEC_GAMEMASTER, 7, 0, LocaleConstant::LOCALE_zhCN, 0, false);
    //pbSession->ReadAddonsInfo("");
    if (accountInfo)
        pBotSession->SetAccountBotSession();

    pBotSession->LoadPermissions();
    sWorld->AddSession(pBotSession);
    return pBotSession;
}

void PlayerBotMgr::OnPlayerBotCreate(ObjectGuid const& guid, uint32 accountId, std::string const& name, uint8 gender, uint8 race, uint8 playerClass, uint8 level)
{
    PlayerBotBaseInfo* pInfo = GetPlayerBotAccountInfo(accountId);
    if (!pInfo)
        return;
    uint32 id = guid.GetCounter();
    if (pInfo->characters.find(id) != pInfo->characters.end())
        return;

    pInfo->characters[id] = PlayerBotCharBaseInfo(id, accountId, name, uint16(race), uint16(playerClass), uint16(gender), uint16(level));

    CreateOncePlayerBot();
}

void PlayerBotMgr::OnAccountBotCreate(ObjectGuid const& guid, uint32 accountId, std::string const& name, uint8 gender, uint8 race, uint8 playerClass, uint8 level)
{
    PlayerBotBaseInfo* pInfo = GetAccountBotAccountInfo(accountId);
    if (!pInfo)
        return;
    uint32 id = guid.GetCounter();
    if (pInfo->characters.find(id) != pInfo->characters.end())
        return;

    pInfo->characters[id] = PlayerBotCharBaseInfo(id, accountId, name, uint16(race), uint16(playerClass), uint16(gender), uint16(level));
}

void PlayerBotMgr::OnAccountBotDelete(ObjectGuid& guid, uint32 accountId)
{
    PlayerBotBaseInfo* pInfo = GetAccountBotAccountInfo(accountId);
    if (!pInfo)
        return;
    pInfo->RemoveCharacterByGUID(guid);
}

void PlayerBotMgr::OnPlayerBotLogin(WorldSession* pSession, Player* pPlayer)
{
    ++m_BotOnlineCount;


    //Group* pGroup = pPlayer->GetGroup();
    //if (pGroup)
    //{
    //    if (!pGroup->GroupExistRealPlayer())
    //    {
    //        pPlayer->RemoveFromGroup(RemoveMethod::GROUP_REMOVEMETHOD_LEAVE);
    //    }
    //    else
    //        SwitchPlayerBotAI(pPlayer, PlayerBotAIType::PBAIT_GROUP, false);
    //}
    //else
    SwitchPlayerBotAI(pPlayer, PlayerBotAIType::PBAIT_FIELD, false);

    if (pPlayer->GetBattleground())
    {
        pPlayer->LeaveBattleground();
        if (pSession)
            pSession->HandleMoveWorldportAck();
    }

    BotUtility::RemoveArenaBotSpellsByPlayer(pPlayer);
    sPlayerBotTalkMgr->JoinDefaultChannel(pPlayer);
    if (pSession)
    {
        char text[128] = { 0 };
        // sprintf_s(text, 127, "%s %s", GetPlayerLinkText(pPlayer).c_str(), wchar_t2char(L"??"));

        sWorld->SendGlobalText(text, NULL);
    }
    pPlayer->SetGameMaster(false);

    if (m_DelayGroupBots.find(pPlayer->GetGUID()) != m_DelayGroupBots.end())
    {
        auto leaderGUID = m_DelayGroupBots[pPlayer->GetGUID()];
        if (Group* pGroup = pPlayer->GetGroup())
            if (pGroup->GetLeaderGUID() != leaderGUID)
                pPlayer->RemoveFromGroup();

        if (Player* leader = ObjectAccessor::FindPlayer(leaderGUID))
        {
            if (auto g = leader->GetGroup())
            {
                if (!g->IsFull())
                {
                    g->AddMember(pPlayer);
                    SwitchPlayerBotAI(pPlayer, PlayerBotAIType::PBAIT_GROUP, false);
                }
            }
            else
            {
                Group* group = new Group;
                group->Create(leader);
                sGroupMgr->AddGroup(group);
                group->AddMember(pPlayer);
            }
        }
        //m_DelayGroupBots.erase(pPlayer->GetGUID());
    }

    if (PlayerBotSession* pBotSession = dynamic_cast<PlayerBotSession*>(pSession))
    {
        if (!pSession->HasSchedules())// && !pPlayer->EquipIsTidiness()
        {
            uint32 curTType = pPlayer->FindTalentType();
            //uint32 newTType = curTType;
            //while (newTType == curTType)
            //    newTType = urand(0, 2);
            BotGlobleSchedule schedule2(BotGlobleScheduleType::BGSType_Settting, 0);
            schedule2.parameter1 = pPlayer->getLevel();
            schedule2.parameter2 = pPlayer->getLevel();
            schedule2.parameter3 = curTType + 1;
            pBotSession->PushScheduleToQueue(schedule2);
        }
    }
}

void PlayerBotMgr::OnPlayerBotLogout(WorldSession* pSession)
{
    --m_BotOnlineCount;
    if (m_BotOnlineCount < 0) m_BotOnlineCount = 0;

    char text[128] = { 0 };
    //  sprintf_s(text, 127, "robot %s", wchar_t2char(L"??"));
    sWorld->SendGlobalText(text, NULL);
    PlayerBotSession* pBotSession = dynamic_cast<PlayerBotSession*>(pSession);
    if (pBotSession && !pBotSession->HasScheduleByType(BotGlobleScheduleType::BGSType_Online) &&
        !pBotSession->HasScheduleByType(BotGlobleScheduleType::BGSType_Online_GUID))
        pBotSession->ClearAllSchedule();
}

void PlayerBotMgr::OnPlayerBotLeaveOriginalGroup(Player* pPlayer)
{
    SwitchPlayerBotAI(pPlayer, PlayerBotAIType::PBAIT_FIELD, true);
}

void PlayerBotMgr::LoginGroupBotByPlayer(Player* pPlayer)
{
#ifndef INCOMPLETE_BOT
    if (pPlayer->IsPlayerBot())
        return;
    Group* pGroup = pPlayer->GetGroup();
    if (!pGroup || pGroup->isBFGroup() || pGroup->isBGGroup())
        return;
    Group::MemberSlotList const& memList = pGroup->GetMemberSlots();
    for (Group::MemberSlot const& slot : memList)
    {
        ObjectGuid guid = slot.guid;
        if (guid == pPlayer->GetGUID())
            continue;
        Player* friendPlayer = ObjectAccessor::FindPlayer(guid);
        if (friendPlayer)
            continue;
        //AddNewPlayerBotByGUID(guid);
        DelayLoginPlayerBotByGUID(guid);
    }
#endif
}

void PlayerBotMgr::LoginFriendBotByPlayer(Player* pPlayer)
{
    if (pPlayer->IsPlayerBot())
        return;
    //std::vector<ObjectGuid> friends = pPlayer->GetSocial()->GetAllFriends();
    //for (ObjectGuid& guid : friends)
    //{
    //    //AddNewPlayerBotByGUID(guid);
    //    DelayLoginPlayerBotByGUID(guid);
    //}
}

void PlayerBotMgr::LoginGuildMemberBotByPlayer(Player* pPlayer)
{
    if (pPlayer->IsPlayerBot())
        return;

    Guild* pGuild = pPlayer->GetGuild();
    if (pGuild)
    {
        //std::list<ObjectGuid> guids = pGuild->GetAllMemberGUID();
        /*for (ObjectGuid& guid : guids)
            if (pPlayer->GetGUID() != guid)
                DelayLoginPlayerBotByGUID(guid);*/
    }
}

void PlayerBotMgr::LogoutAllGroupPlayerBot(Group* pGroup, bool /*force*/)
{
    if (!pGroup)
        return;
    /* if (!force && pGroup->GroupExistRealPlayer())
         return;*/
    Group::MemberSlotList const& memList = pGroup->GetMemberSlots();
    for (Group::MemberSlot const& slot : memList)
    {
        ObjectGuid guid = slot.guid;
        Player* player = ObjectAccessor::FindPlayer(guid);
        if (!player || !player->IsPlayerBot())
            continue;
        WorldSession* pSession = player->GetSession();
        if (pSession)
            pSession->LogoutPlayer(false);
    }
}

bool PlayerBotMgr::AllPlayerLeaveBG(uint32 account)
{
    if (account == 0)
        return false;
    //std::unique_lock<std::mutex> sessionGuard(PlayerBotMgr::g_uniqueLock);
    WorldSession* pSession = sWorld->FindSession(account);
    if (pSession && pSession->IsBotSession() && !pSession->PlayerLoading())
    {
        Player* pPlayer = pSession->GetPlayer();
        if (!pPlayer || pPlayer->GetTransport() || !pPlayer->InBattleground())
            return false;
        const Battleground* bg = pPlayer->GetBattleground();
        if (!bg || bg->GetStatus() == BattlegroundStatus::STATUS_WAIT_LEAVE || bg->GetStatus() == BattlegroundStatus::STATUS_WAIT_JOIN)
            return false;
        ((Battleground*)bg)->EndBattleground((pPlayer->GetTeamId() == TEAM_ALLIANCE) ? HORDE : ALLIANCE);
        return true;
    }
    return false;
}

void PlayerBotMgr::AllPlayerBotRandomLogin()
{
    uint32 needOnline = m_MaxOnlineBot - m_BotOnlineCount;
    if (needOnline <= 0)
        return;
    for (std::map<uint32, PlayerBotBaseInfo*>::iterator it = m_idPlayerBotBase.begin();
        it != m_idPlayerBotBase.end();
        it++)
    {
        PlayerBotBaseInfo* pInfo = it->second;
        WorldSession* pSession = sWorld->FindSession(pInfo->id);
        if (pSession && pSession->IsBotSession() && !pSession->PlayerLoading() && !pSession->GetPlayer())
        {
            if (pInfo->characters.size() <= 0)
                continue;
            int sel = irand(0, pInfo->characters.size() - 1);
            for (std::map<uint32, PlayerBotCharBaseInfo>::iterator itChar = pInfo->characters.begin();
                itChar != pInfo->characters.end();
                itChar++)
            {
                if (sel <= 0)
                {
                    PlayerBotCharBaseInfo& charInfo = itChar->second;

                    WorldPacket packet(CMSG_PLAYER_LOGIN);
                    WorldPackets::Character::PlayerLogin sPacket(std::move(packet));
                    sPacket.Guid = ObjectGuid::Create<HighGuid::Player>(charInfo.guid);
                    pSession->HandlePlayerLoginOpcode(sPacket);
                    pSession->HandleContinuePlayerLogin();
                    --needOnline;
                    break;
                }
                --sel;
            }
            if (needOnline <= 0)
                return;
        }
    }
}

void PlayerBotMgr::AutoPlayerBotRandomLogin()
{
    if (!m_AutoLoginStarted)
        return;
    if (m_AutoLoginAliCount)
    {
        if (AddOnePlayerBot(TeamId::TEAM_ALLIANCE, Classes(urand(CLASS_WARRIOR, MAX_CLASSES - 1))))
            m_AutoLoginAliCount--;
    }
    if (m_AutoLoginHorCount)
    {
        if (AddOnePlayerBot(TeamId::TEAM_HORDE, Classes(urand(CLASS_WARRIOR, MAX_CLASSES - 1))))
            m_AutoLoginHorCount--;
    }
}


void PlayerBotMgr::AllPlayerBotLogout()
{
    //std::unique_lock<std::mutex> sessionGuard(PlayerBotMgr::g_uniqueLock);
    for (std::map<uint32, PlayerBotBaseInfo*>::iterator it = m_idPlayerBotBase.begin();
        it != m_idPlayerBotBase.end();
        it++)
    {
        PlayerBotBaseInfo* pInfo = it->second;
        PlayerBotLogout(pInfo->id);
    }
    for (std::map<uint32, PlayerBotBaseInfo*>::iterator it = m_idAccountBotBase.begin();
        it != m_idAccountBotBase.end();
        it++)
    {
        PlayerBotBaseInfo* pInfo = it->second;
        PlayerBotLogout(pInfo->id);
    }
}

bool PlayerBotMgr::PlayerBotLogout(uint32 account)
{
    if (account == 0)
        return false;
    //std::unique_lock<std::mutex> sessionGuard(PlayerBotMgr::g_uniqueLock);
    WorldSession* pSession = sWorld->FindSession(account);
    if (pSession && pSession->IsBotSession() && !pSession->PlayerLoading())
    {
        Player* pBot = pSession->GetPlayer();
        if (!pBot || !pBot->IsPlayerBot() || !pBot->IsSettingFinish())
            return false;
        PlayerBotSession* pBotSession = dynamic_cast<PlayerBotSession*>(pSession);
        if (pBotSession && pBotSession->HasSchedules())
            return false;
        //if (pBot->InBattlegroundQueue() || pBot->InBattleground())
        //	return false;
        Group* pGroup = pBot->GetGroup();
        if (pGroup)
            return false;
        pSession->LogoutPlayer(false);
        return true;
    }
    return false;
}

bool PlayerBotMgr::PlayerBotLogout(Player* player)
{
    if (!player || !player->IsPlayerBot())
        return false;

    Group* pGroup = player->GetGroup();
    if (pGroup)
        return false;

    WorldSession* pSession = player->GetSession();
    if (pSession)
        pSession->LogoutPlayer(false);
    return true;
}

void PlayerBotMgr::SupplementPlayerBot()
{
    for (std::map<uint32, PlayerBotBaseInfo*>::iterator itInfo = m_idPlayerBotBase.begin();
        itInfo != m_idPlayerBotBase.end();
        itInfo++)
    {
        PlayerBotBaseInfo* pInfo = itInfo->second;
        if (pInfo->username.size() <= 0)
            continue;
        if (pInfo->characters.size() >= 18)
            continue;
        WorldSession* pSession = sWorld->FindSession(pInfo->id);
        if (!pSession)
        {
            TC_LOG_INFO("server.loading", ">> Create bot, but session offline.");
            continue;
        }
        std::string firstName = pInfo->username.substr(6);
        char botname[30] = { 0 };
        for (int i = CLASS_WARRIOR; i < MAX_CLASSES; i++)
        {
            if (!pInfo->ExistClass(TEAM_ALLIANCE, i))
            {
                memset(botname, 0, 30);
                sprintf(botname, "%sA%d", firstName.c_str(), i);
                pInfo->needCreateBots.push(BuildCreatePlayerData(true, i));
            }
            if (!pInfo->ExistClass(TEAM_HORDE, i))
            {
                memset(botname, 0, 30);
                sprintf(botname, "%sB%d", firstName.c_str(), i);
                pInfo->needCreateBots.push(BuildCreatePlayerData(false, i));
            }
        }
    }
    CreateOncePlayerBot();
}

void PlayerBotMgr::OnRealPlayerJoinBattlegroundQueue(uint32 /*bgTypeId*/, uint32 /*level*/)
{
    /*
    BattlegroundTypeId _bgTypeId = BattlegroundTypeId(bgTypeId);
    BattlegroundQueueTypeId bgQueueTypeId = BattlegroundMgr::BGQueueTypeId(BattlegroundTypeId(bgTypeId), 0);
    BattlegroundQueue& bgQueue = sBattlegroundMgr->GetBattlegroundQueue(bgQueueTypeId);
    Battleground* bg = sBattlegroundMgr->GetBattlegroundTemplate(BattlegroundTypeId(bgTypeId));
    if (!bg)
        return;

    int32 needAlliancePlayerCount = 5;
    int32 needHordePlayerCount = 5;
    uint32 _time = 0;

    for (uint32 j = BattlegroundBracketId::BG_BRACKET_ID_FIRST; j <= BattlegroundBracketId::BG_BRACKET_ID_LAST; j++)
    {
        BattlegroundBracketId bracket = BattlegroundBracketId(j);
        PVPDifficultyEntry const* bracketEntry = DB2Manager::GetBattlegroundBracketById(bg->GetMapId(), bracket);
        if (!bracketEntry)
            continue;
        if (!bgQueue.ExistRealPlayer(bracketEntry))
            continue;
        if (needAlliancePlayerCount > 0)
        {
            for (uint32 k = 0; k <= needAlliancePlayerCount; k++)
                AddNewPlayerBotToBG(TeamId::TEAM_ALLIANCE, bracketEntry->MinLevel, bracketEntry->MaxLevel, _bgTypeId);
        }

        if (needHordePlayerCount > 0)
        {
            for (uint32 k = 0; k <= needHordePlayerCount; k++)
                AddNewPlayerBotToBG(TeamId::TEAM_HORDE, bracketEntry->MinLevel, bracketEntry->MaxLevel, _bgTypeId);
        }

        printf("QueryNeedPlayerCount %d %d \n", needAlliancePlayerCount, needHordePlayerCount);
        return;
    }
    */
}

void PlayerBotMgr::OnRealPlayerLeaveBattlegroundQueue(uint32 bgTypeId, uint32 level)
{
    BattlegroundQueueTypeId bgQueueTypeId = BattlegroundMgr::BGQueueTypeId(BattlegroundTypeId(bgTypeId), {}, true, 5);
    BattlegroundQueue& bgQueue = sBattlegroundMgr->GetBattlegroundQueue(bgQueueTypeId);
    Battleground* bg = sBattlegroundMgr->GetBattlegroundTemplate(BattlegroundTypeId(bgTypeId));
    if (!bg)
        return;
    PVPDifficultyEntry const* bracketEntry = DB2Manager::GetBattlegroundBracketByLevel(bg->GetMapId(), level);
    if (!bracketEntry)
        return;

    if (bgQueue.ExistRealPlayer(bracketEntry))
        return;
    const SessionMap& allSession = sWorld->GetAllSessions();
    for (SessionMap::const_iterator itSession = allSession.begin(); itSession != allSession.end(); itSession++)
    {
        PlayerBotSession* pSession = dynamic_cast<PlayerBotSession*>((WorldSession*)itSession->second);
        if (!pSession)
            continue;
        Player* player = pSession->GetPlayer();
        if (!player || player->IsLoading())
            continue;
        if (player->InBattleground() || player->InArena() || !player->IsInWorld())
            continue;
        uint32 lv = player->getLevel();
        if (lv < bracketEntry->MinLevel || lv > bracketEntry->MaxLevel)
            continue;
        if (player->InBattlegroundQueue())
        {
            BotGlobleSchedule schedule1(BotGlobleScheduleType::BGSType_OutBGQueue, 0);
            schedule1.parameter1 = bgTypeId;
            pSession->PushScheduleToQueue(schedule1);
        }
    }
}

void PlayerBotMgr::OnRealPlayerLeaveArenaQueue(uint32 bgTypeId, uint32 level, uint32 aaType)
{

    BattlegroundQueueTypeId bgQueueTypeId = { 0,false,0 };// = BattlegroundMgr::BGQueueTypeId(BattlegroundTypeId(bgTypeId), aaType);

    BattlegroundQueue& bgQueue = sBattlegroundMgr->GetBattlegroundQueue(bgQueueTypeId);
    Battleground* bg = sBattlegroundMgr->GetBattlegroundTemplate(BattlegroundTypeId(bgTypeId));
    if (!bg)
        return;
    PVPDifficultyEntry const* bracketEntry = DB2Manager::GetBattlegroundBracketByLevel(bg->GetMapId(), level);
    if (!bracketEntry)
        return;

    if (bgQueue.ExistRealPlayer(bracketEntry))
        return;
    const SessionMap& allSession = sWorld->GetAllSessions();
    for (SessionMap::const_iterator itSession = allSession.begin(); itSession != allSession.end(); itSession++)
    {
        PlayerBotSession* pSession = dynamic_cast<PlayerBotSession*>((WorldSession*)itSession->second);
        if (!pSession)
            continue;
        Player* player = pSession->GetPlayer();
        if (!player || player->IsLoading())
            continue;
        if (player->InBattleground() || player->InArena() || !player->IsInWorld())
            continue;
        uint32 lv = player->getLevel();
        if (lv < bracketEntry->MinLevel || lv > bracketEntry->MaxLevel)
            continue;
        if (player->InBattlegroundQueue())
        {
            BotGlobleSchedule schedule1(BotGlobleScheduleType::BGSType_OutAAQueue, 0);
            schedule1.parameter1 = bgTypeId;
            schedule1.parameter2 = bracketEntry->GetBracketId();
            schedule1.parameter3 = aaType;
            pSession->PushScheduleToQueue(schedule1);
        }
    }
}

void PlayerBotMgr::OnRealPlayerEnterBattleground(uint32 /*bgTypeId*/, uint32 /*level*/)
{
}

void PlayerBotMgr::OnRealPlayerLeaveBattleground(const Player* player)
{
    Battleground* bg = player->GetBattleground();
    if (!bg || bg->GetStatus() != BattlegroundStatus::STATUS_WAIT_LEAVE)
        return;
    PVPDifficultyEntry const* bracketEntry = DB2Manager::GetBattlegroundBracketByLevel(bg->GetMapId(), player->getLevel());
    if (!bracketEntry)
        return;

    const Battleground::BattlegroundPlayerMap& allPlayerIDs = bg->GetPlayers();
    for (Battleground::BattlegroundPlayerMap::const_iterator itIDs = allPlayerIDs.begin(); itIDs != allPlayerIDs.end(); itIDs++)
    {
        Player* otherPlayer = ObjectAccessor::FindConnectedPlayer(itIDs->first);
        if (!otherPlayer || otherPlayer->IsLoading())
            continue;
        if (!otherPlayer->InBattleground())
            continue;
        PlayerBotSession* pSession = dynamic_cast<PlayerBotSession*>((WorldSession*)otherPlayer->GetSession());
        if (pSession)
        {
            BotGlobleSchedule schedule1(BotGlobleScheduleType::BGSType_LeaveBG, 0);
            pSession->PushScheduleToQueue(schedule1);
        }
    }
}

bool PlayerBotMgr::LoginBotByAccountIndex(uint32 account, uint32 index)
{
#ifndef INCOMPLETE_BOT
    PlayerBotBaseInfo* botInfo = GetPlayerBotAccountInfo(account);
    if (!botInfo)
        return false;
    if (index >= botInfo->characters.size())
        return false;
    for (std::map<uint32, PlayerBotCharBaseInfo>::iterator itChar = botInfo->characters.begin();
        itChar != botInfo->characters.end();
        itChar++)
    {
        if (index > 0)
        {
            --index;
            continue;
        }
        PlayerBotCharBaseInfo& charInfo = itChar->second;
        WorldSession* pWorldSession = sWorld->FindSession(account);
        PlayerBotSession* pSession = dynamic_cast<PlayerBotSession*>(pWorldSession);
        if (!pSession || pSession->PlayerLoading() || pSession->HasSchedules() || pSession->GetPlayer())
            return false;
        BotGlobleSchedule schedule1(BotGlobleScheduleType::BGSType_Online_GUID, 0);
        schedule1.parameter1 = charInfo.guid;
        pSession->PushScheduleToQueue(schedule1);
        return true;
    }
#endif
    return false;
}

bool PlayerBotMgr::AddNewPlayerBotByGUID(ObjectGuid& guid)
{
    for (std::map<uint32, PlayerBotBaseInfo*>::iterator itInfo = m_idPlayerBotBase.begin();
        itInfo != m_idPlayerBotBase.end();
        itInfo++)
    {
        if (!(itInfo->second->ExistCharacterByGUID(guid)))
            continue;
        WorldSession* pWorldSession = sWorld->FindSession(itInfo->first);
        PlayerBotSession* pSession = dynamic_cast<PlayerBotSession*>(pWorldSession);
        if (!pSession || pSession->PlayerLoading() || pSession->HasSchedules())
            return false;
        if (Player* player = pSession->GetPlayer())
        {
            if (!player->GetGroup() && !player->IsInCombat() && pSession->GetPlayer()->GetGUID() != guid)
            {
                BotGlobleSchedule schedule(BotGlobleScheduleType::BGSType_Offline, 0);
                pSession->PushScheduleToQueue(schedule);
            }
            else
                return false;
        }
        BotGlobleSchedule schedule1(BotGlobleScheduleType::BGSType_Online_GUID, 0);
        schedule1.parameter1 = guid.GetCounter();
        pSession->PushScheduleToQueue(schedule1);
        return true;
    }

    for (std::map<uint32, PlayerBotBaseInfo*>::iterator itInfo = m_idAccountBotBase.begin();
        itInfo != m_idAccountBotBase.end();
        itInfo++)
    {
        if (!(itInfo->second->ExistCharacterByGUID(guid)))
            continue;
        WorldSession* pWorldSession = sWorld->FindSession(itInfo->first);
        if (pWorldSession)
        {
            PlayerBotSession* pSession = dynamic_cast<PlayerBotSession*>(pWorldSession);
            if (!pSession || pSession->PlayerLoading() || pSession->HasSchedules())
                return false;
            if (Player* player = pSession->GetPlayer())
            {
                if (!player->GetGroup() && !player->IsInCombat() && pSession->GetPlayer()->GetGUID() != guid)
                {
                    BotGlobleSchedule schedule(BotGlobleScheduleType::BGSType_Offline, 0);
                    pSession->PushScheduleToQueue(schedule);
                }
                else
                    return false;
            }
            BotGlobleSchedule schedule1(BotGlobleScheduleType::BGSType_Online_GUID, 0);
            schedule1.parameter1 = guid.GetCounter();
            pSession->PushScheduleToQueue(schedule1);
            return true;
        }
        else
        {
            PlayerBotSession* pSession = UpPlayerBotSessionByBaseInfo(itInfo->second, true);
            if (!pSession)
                return false;
            BotGlobleSchedule schedule1(BotGlobleScheduleType::BGSType_Online_GUID, 0);
            schedule1.parameter1 = guid.GetCounter();
            pSession->PushScheduleToQueue(schedule1);
            return true;
        }
    }
    return false;
}

bool PlayerBotMgr::AddOnePlayerBot(TeamId team, Classes cls)
{
    for (std::map<uint32, PlayerBotBaseInfo*>::iterator it = m_idPlayerBotBase.begin();
        it != m_idPlayerBotBase.end();
        it++)
    {
        PlayerBotBaseInfo* pInfo = it->second;
        WorldSession* pSession = sWorld->FindSession(pInfo->id);
        if (pSession && pSession->IsBotSession() && !pSession->PlayerLoading() && !pSession->GetPlayer())
        {
            PlayerBotCharBaseInfo charInfo;
            if (pInfo->characters.size() <= 0)
                charInfo = PlayerBotBaseInfo::empty;
            charInfo = pInfo->GetCharacter(team, cls);

            if (charInfo.guid != 0)
            {
                //DelayLoginPlayerBotByGUID(ObjectGuid::Create<HighGuid::Player>(charInfo.guid));

                BotGlobleSchedule schedule1(BotGlobleScheduleType::BGSType_Online, 0);
                schedule1.parameter1 = (team == TeamId::TEAM_ALLIANCE) ? 1 : 2;
                schedule1.parameter2 = cls;
                //pSession->PushScheduleToQueue(schedule1);
                WorldPacket packet(CMSG_PLAYER_LOGIN);
                WorldPackets::Character::PlayerLogin sPacket(std::move(packet));
                sPacket.Guid = ObjectGuid::Create<HighGuid::Player>(charInfo.guid);
                pSession->HandlePlayerLoginOpcode(sPacket);
                pSession->HandleContinuePlayerLogin();
                return true;
            }
        }
    }
    return false;
}

void PlayerBotMgr::AddNewPlayerBot(TeamId team, Classes cls, uint32 count)
{
    if (count <= 0)
        return;
    if (cls == CLASS_NONE)
        cls = Classes(urand(CLASS_WARRIOR, MAX_CLASSES - 1));

    const SessionMap& allSession = sWorld->GetAllSessions();
    for (SessionMap::const_iterator itSession = allSession.begin(); itSession != allSession.end(); itSession++)
    {
        if (count <= 0)
            return;
        if (!itSession->second->IsBotSession())
            continue;
        PlayerBotSession* pSession = dynamic_cast<PlayerBotSession*>((WorldSession*)itSession->second);
        if (!pSession || pSession->PlayerLoading() || pSession->HasSchedules() || pSession->IsAccountBotSession())
            continue;
        Player* player = pSession->GetPlayer();
        if (player)
            continue;

        BotGlobleSchedule schedule1(BotGlobleScheduleType::BGSType_Online, 0);
        schedule1.parameter1 = (team == TeamId::TEAM_ALLIANCE) ? 1 : 2;
        schedule1.parameter2 = cls;
        pSession->PushScheduleToQueue(schedule1);
        if (pSession->PlayerOnline(schedule1))
            //if (AddOnePlayerBot(team, cls))
            --count;
    }

    if (count > 0)
    {
        std::string allonlineText;
        consoleToUtf8(std::string("|cffff8800?????????????,?????????|r"), allonlineText);
        sWorld->SendGlobalText(allonlineText.c_str(), NULL);
    }
}

void PlayerBotMgr::AddNewAccountBot(TeamId team, Classes cls)
{
    std::string allonlineText;
    if (cls == CLASS_NONE)
    {
        cls = Classes(urand(CLASS_WARRIOR, MAX_CLASSES - 1));
    }
    //std::set<uint32> hasSessionIDs;
    const SessionMap& allSession = sWorld->GetAllSessions();
    for (SessionMap::const_iterator itSession = allSession.begin(); itSession != allSession.end(); itSession++)
    {
        if (!itSession->second->IsBotSession())
            continue;
        PlayerBotSession* pSession = dynamic_cast<PlayerBotSession*>((WorldSession*)itSession->second);
        if (!pSession || pSession->PlayerLoading() || pSession->HasSchedules() || !pSession->IsAccountBotSession())
            continue;
        //hasSessionIDs.insert(pSession->GetAccountId());
        Player* player = pSession->GetPlayer();
        if (player)
            continue;
        PlayerBotBaseInfo* pBaseInfo = GetAccountBotAccountInfo(pSession->GetAccountId());
        if (!pBaseInfo)
            continue;
        if (!pBaseInfo->ExistClass(team, cls))
            continue;
        BotGlobleSchedule schedule1(BotGlobleScheduleType::BGSType_Online, 0);
        schedule1.parameter1 = (team == TeamId::TEAM_ALLIANCE) ? 1 : 2;
        schedule1.parameter2 = cls;
        pSession->PushScheduleToQueue(schedule1);
        //if (AddOnePlayerBot(team, cls))
        return;
    }

    for (std::map<uint32, PlayerBotBaseInfo*>::iterator it = m_idAccountBotBase.begin();
        it != m_idAccountBotBase.end();
        it++)
    {
        PlayerBotBaseInfo* pInfo = it->second;
        WorldSession* pSession = sWorld->FindSession(pInfo->id);
        if (pSession)
            continue;
        if (!pInfo->ExistClass(team, cls))
            continue;
        PlayerBotSession* pBotSession = UpPlayerBotSessionByBaseInfo(pInfo, true);
        if (pBotSession)
        {
            BotGlobleSchedule schedule1(BotGlobleScheduleType::BGSType_Online, 0);
            schedule1.parameter1 = (team == TeamId::TEAM_ALLIANCE) ? 1 : 2;
            schedule1.parameter2 = cls;
            pBotSession->PushScheduleToQueue(schedule1);
            //AddOnePlayerBot(team, cls);
            if (pBotSession->PlayerOnline(schedule1))
                return;
        }
    }

    consoleToUtf8(std::string("|cffff8800??????????????????????|r"), allonlineText);
    sWorld->SendGlobalText(allonlineText.c_str(), NULL);
}

void PlayerBotMgr::AddNewPlayerBotByClass(uint32 count, Classes cls)
{
    int32 allianceCount = int32(count);
    int32 hordeCount = int32(count);
    const SessionMap& allSession = sWorld->GetAllSessions();
    for (SessionMap::const_iterator itSession = allSession.begin(); itSession != allSession.end(); itSession++)
    {
        if (allianceCount <= 0 && hordeCount <= 0)
            return;
        if (!itSession->second->IsBotSession())
            continue;
        PlayerBotSession* pSession = dynamic_cast<PlayerBotSession*>((WorldSession*)itSession->second);
        if (!pSession || pSession->PlayerLoading() || pSession->HasSchedules() || pSession->IsAccountBotSession())
            continue;
        Player* player = pSession->GetPlayer();
        if (player && player->getClass() != cls)
            continue;
        if (player)
        {
            if (player->GetTeamId() == TeamId::TEAM_ALLIANCE)
                --allianceCount;
            else
                --hordeCount;
        }
        else
        {
            BotGlobleSchedule schedule1(BotGlobleScheduleType::BGSType_Online, 0);
            if (allianceCount > 0)
            {
                schedule1.parameter1 = 1;
                //if (AddOnePlayerBot(player->GetTeamId(), cls))
                --allianceCount;
            }
            else if (hordeCount > 0)
            {
                schedule1.parameter1 = 2;
                //if (AddOnePlayerBot(player->GetTeamId(), cls))
                --hordeCount;
            }
            else
                continue;
            schedule1.parameter2 = cls;
            pSession->PushScheduleToQueue(schedule1);
        }
    }

    if (allianceCount > 0 || hordeCount > 0)
    {
        std::string allonlineText;
        consoleToUtf8(std::string("|cffff8800?????????????,?????????|r"), allonlineText);
        sWorld->SendGlobalText(allonlineText.c_str(), NULL);
    }
}

bool PlayerBotMgr::ChangePlayerBotSetting(uint32 account, uint32 minLV, uint32 maxLV, uint32 talent)
{
    if (account == 0)
        return false;
    maxLV = PlayerBotSetting::CheckMaxLevel(maxLV);
    if (maxLV < minLV)
        maxLV = minLV;
    WorldSession* pWorldSession = sWorld->FindSession(account);
    if (pWorldSession && pWorldSession->IsBotSession() && !pWorldSession->PlayerLoading())
    {
        Player* player = pWorldSession->GetPlayer();
        if (!player || player->InBattlegroundQueue() || player->InBattleground() ||
            player->GetBattleground() || player->IsInCombat())
            return false;
        PlayerBotSession* pSession = dynamic_cast<PlayerBotSession*>(pWorldSession);
        if (!pSession || pSession->HasSchedules())
            return false;
        BotGlobleSchedule schedule2(BotGlobleScheduleType::BGSType_Settting, 0);
        schedule2.parameter1 = minLV;
        schedule2.parameter2 = maxLV;
        schedule2.parameter3 = talent + 1;
        pSession->PushScheduleToQueue(schedule2);
        return true;
    }
    return false;
}

void PlayerBotMgr::AddNewPlayerBotToBG(TeamId team, uint32 minLV, uint32 maxLV, BattlegroundTypeId bgTypeID)
{
    maxLV = PlayerBotSetting::CheckMaxLevel(maxLV);
    if (maxLV < minLV)
        maxLV = minLV;

    //uint32 needOnline = 100 - m_BotOnlineCount;//m_MaxOnlineBot
    //if (needOnline <= 0)
    //    return;

    for (std::map<uint32, PlayerBotBaseInfo*>::iterator it = m_idPlayerBotBase.begin();
        it != m_idPlayerBotBase.end();
        it++)
    {
        PlayerBotBaseInfo* pInfo = it->second;
        PlayerBotSession* pSession = dynamic_cast<PlayerBotSession*>((WorldSession*)sWorld->FindSession(pInfo->id));
        if (!pSession || pSession->PlayerLoading() || pSession->HasSchedules() || pSession->IsAccountBotSession())
            continue;
        Player* player = pSession->GetPlayer();
        if (!player)
        {
            PlayerBotCharBaseInfo charInfo;
            if (pInfo->characters.size() <= 0)
                charInfo = PlayerBotBaseInfo::empty;
            charInfo = pInfo->GetCharacter(team, urand(CLASS_WARRIOR, (MAX_CLASSES - 1)));//GetRandomCharacterByFuction GetCharacterByTeam 

            if (charInfo.guid != 0)
            {
                if (m_MaxOnlineBot < m_BotOnlineCount)
                    return;
                //DelayLoginPlayerBotByGUID(ObjectGuid::Create<HighGuid::Player>(charInfo.guid));
                ++m_BotOnlineCount;
                WorldPacket packet;
                WorldPackets::Character::PlayerLogin sPacket(std::move(packet));
                sPacket.Guid = ObjectGuid::Create<HighGuid::Player>(charInfo.guid);
                pSession->HandlePlayerLoginOpcode(sPacket);
                pSession->HandleContinuePlayerLogin();

                BotGlobleSchedule schedule2(BotGlobleScheduleType::BGSType_Settting, 0);
                schedule2.parameter1 = minLV;
                schedule2.parameter2 = maxLV;
                schedule2.parameter3 = 5;
                pSession->PushScheduleToQueue(schedule2);

                BotGlobleSchedule schedule3(BotGlobleScheduleType::BGSType_InBGQueue, 0);
                schedule3.parameter1 = bgTypeID;
                pSession->PushScheduleToQueue(schedule3);

                BotGlobleSchedule schedule4(BotGlobleScheduleType::BGSType_EnterBG, 0);
                schedule4.parameter1 = bgTypeID;
                pSession->PushScheduleToQueue(schedule4);

                return;
            }

        }
        else if (IsIDLEPlayerBot(player))
        {
            if (player->GetTeamId() != team)
                continue;

            BotGlobleSchedule schedule2(BotGlobleScheduleType::BGSType_Settting, 0);
            schedule2.parameter1 = minLV;
            schedule2.parameter2 = maxLV;
            schedule2.parameter3 = 5;
            pSession->PushScheduleToQueue(schedule2);

            BotGlobleSchedule schedule3(BotGlobleScheduleType::BGSType_InBGQueue, 0);
            schedule3.parameter1 = bgTypeID;
            pSession->PushScheduleToQueue(schedule3);

            BotGlobleSchedule schedule4(BotGlobleScheduleType::BGSType_EnterBG, 0);
            schedule4.parameter1 = bgTypeID;
            pSession->PushScheduleToQueue(schedule4);
            return;
        }
    }
    /*
    const SessionMap& allSession = sWorld->GetAllSessions();
    for (SessionMap::const_iterator itSession = allSession.begin(); itSession != allSession.end(); itSession++)
    {
        if (!itSession->second->IsBotSession())
            continue;
        PlayerBotSession* pSession = dynamic_cast<PlayerBotSession*>((WorldSession*)itSession->second);
        if (!pSession || pSession->PlayerLoading() || pSession->HasSchedules() || pSession->IsAccountBotSession())
            continue;
        Player* player = pSession->GetPlayer();
        if (!player)
        {
            BotGlobleSchedule schedule1(BotGlobleScheduleType::BGSType_Online, 0);
            schedule1.parameter1 = (team == TeamId::TEAM_ALLIANCE) ? 1 : 2;
            pSession->PushScheduleToQueue(schedule1);

            BotGlobleSchedule schedule2(BotGlobleScheduleType::BGSType_Settting, 0);
            schedule2.parameter1 = minLV;
            schedule2.parameter2 = maxLV;
            schedule2.parameter3 = 5;
            pSession->PushScheduleToQueue(schedule2);

            BotGlobleSchedule schedule3(BotGlobleScheduleType::BGSType_InBGQueue, 0);
            schedule3.parameter1 = bgTypeID;
            pSession->PushScheduleToQueue(schedule3);

            BotGlobleSchedule schedule4(BotGlobleScheduleType::BGSType_EnterBG, 0);
            schedule4.parameter1 = bgTypeID;
            pSession->PushScheduleToQueue(schedule4);

            return;
        }
        else if (IsIDLEPlayerBot(player))
        {
            if (player->GetTeamId() != team)
                continue;

            BotGlobleSchedule schedule2(BotGlobleScheduleType::BGSType_Settting, 0);
            schedule2.parameter1 = minLV;
            schedule2.parameter2 = maxLV;
            schedule2.parameter3 = 5;
            pSession->PushScheduleToQueue(schedule2);

            BotGlobleSchedule schedule3(BotGlobleScheduleType::BGSType_InBGQueue, 0);
            schedule3.parameter1 = bgTypeID;
            pSession->PushScheduleToQueue(schedule3);

            BotGlobleSchedule schedule4(BotGlobleScheduleType::BGSType_EnterBG, 0);
            schedule4.parameter1 = bgTypeID;
            pSession->PushScheduleToQueue(schedule4);

            return;
        }
    }
    */
    std::string allonlineText;
    consoleToUtf8(std::string("|cffff8800?????????????,?????????????|r"), allonlineText);
    sWorld->SendGlobalText(allonlineText.c_str(), NULL);
}

void PlayerBotMgr::AddNewPlayerBotToLFG(lfg::LFGBotRequirement* botRequirement)
{
    if (!botRequirement || botRequirement->selectedDungeons.empty())
        return;

    //uint32 needOnline = m_MaxOnlineBot - m_BotOnlineCount;//m_MaxOnlineBot
    //if (needOnline <= 0)
    //    return;

    std::vector<uint32> duns;
    for (lfg::LfgDungeonSet::iterator itLfgSet = botRequirement->selectedDungeons.begin(); itLfgSet != botRequirement->selectedDungeons.end(); itLfgSet++)
    {
        uint32 dun = *itLfgSet;
        duns.push_back(dun);
    }

    for (std::map<uint32, PlayerBotBaseInfo*>::iterator it = m_idPlayerBotBase.begin();
        it != m_idPlayerBotBase.end();
        it++)
    {
        PlayerBotBaseInfo* pInfo = it->second;
        PlayerBotSession* pSession = dynamic_cast<PlayerBotSession*>((WorldSession*)sWorld->FindSession(pInfo->id));
        if (!pSession || pSession->PlayerLoading() || pSession->HasSchedules() || pSession->IsAccountBotSession())
            continue;
        Player* player = pSession->GetPlayer();
        if (!player)
        {
            if (m_MaxOnlineBot < m_BotOnlineCount)
                return;
            BotGlobleSchedule schedule1(BotGlobleScheduleType::BGSType_Online, 0);
            if (!FillOnlineBotScheduleByLFGRequirement(botRequirement, &schedule1))
                continue;
            PlayerBotCharBaseInfo charInfo;
            if (pInfo->characters.size() <= 0)
                charInfo = PlayerBotBaseInfo::empty;
            charInfo = pInfo->GetCharacter(botRequirement->needTeam, schedule1.parameter2);
            if (charInfo.guid != 0)
            {
                pSession->PushScheduleToQueue(schedule1);
                //++m_BotOnlineCount;
                /*
                WorldPacket packet(CMSG_PLAYER_LOGIN);
                WorldPackets::Character::PlayerLogin sPacket(std::move(packet));
                sPacket.Guid = ObjectGuid::Create<HighGuid::Player>(charInfo.guid);
                pSession->HandlePlayerLoginOpcode(sPacket);
                pSession->HandleContinuePlayerLogin();
                */
                BotGlobleSchedule schedule2(BotGlobleScheduleType::BGSType_Settting, 0);
                schedule2.parameter1 = botRequirement->needLevel;
                schedule2.parameter2 = botRequirement->needLevel;
                schedule2.parameter3 = GetScheduleTalentByLFGRequirement(botRequirement->needRole, schedule1.parameter2) + 1;
                pSession->PushScheduleToQueue(schedule2);

                BotGlobleSchedule schedule3(BotGlobleScheduleType::BGSType_InLFGQueue, 0);
                schedule3.parameter1 = uint32(botRequirement->needRole);
                uint32 count = botRequirement->selectedDungeons.size();
                schedule3.parameter2 = (count > 3) ? 3 : count;
                if (count >= 1)
                    schedule3.parameter3 = duns[0];
                if (count >= 2)
                    schedule3.parameter4 = duns[1];
                if (count >= 3)
                    schedule3.parameter5 = duns[2];
                pSession->PushScheduleToQueue(schedule3);

                if (player)
                {
                    BotGlobleSchedule schedule4(BotGlobleScheduleType::BGSType_DelayLevelup, player->GetGUID());
                    pSession->PushScheduleToQueue(schedule4);
                }


                return;
            }

        }
        else if (IsIDLEPlayerBot(player))
        {
            if (player->GetTeamId() != botRequirement->needTeam)
                continue;

            lfg::LfgRoles playerRole = lfg::LfgRoles::PLAYER_ROLE_NONE;
            if (BotFieldAI* pFieldAI = dynamic_cast<BotFieldAI*>(player->GetAI()))
            {
                if (pFieldAI->IsTankBotAI() && botRequirement->needRole == lfg::LfgRoles::PLAYER_ROLE_TANK)
                    playerRole = lfg::LfgRoles::PLAYER_ROLE_TANK;
                else if (pFieldAI->IsHealerBotAI() && botRequirement->needRole == lfg::LfgRoles::PLAYER_ROLE_HEALER)
                    playerRole = lfg::LfgRoles::PLAYER_ROLE_HEALER;
                else
                    playerRole = lfg::LfgRoles::PLAYER_ROLE_DAMAGE;
            }
            else if (BotGroupAI* pGroupAI = dynamic_cast<BotGroupAI*>(player->GetAI()))
            {
                if (pGroupAI->IsTankBotAI() && botRequirement->needRole == lfg::LfgRoles::PLAYER_ROLE_TANK)
                    playerRole = lfg::LfgRoles::PLAYER_ROLE_TANK;
                else if (pGroupAI->IsHealerBotAI() && botRequirement->needRole == lfg::LfgRoles::PLAYER_ROLE_HEALER)
                    playerRole = lfg::LfgRoles::PLAYER_ROLE_HEALER;
                else
                    playerRole = lfg::LfgRoles::PLAYER_ROLE_DAMAGE;
            }
            if (playerRole != botRequirement->needRole)
                continue;

            BotGlobleSchedule schedule2(BotGlobleScheduleType::BGSType_Settting, 0);
            schedule2.parameter1 = botRequirement->needLevel;
            schedule2.parameter2 = botRequirement->needLevel;
            schedule2.parameter3 = GetScheduleTalentByLFGRequirement(botRequirement->needRole, player->getClass()) + 1;
            pSession->PushScheduleToQueue(schedule2);

            BotGlobleSchedule schedule3(BotGlobleScheduleType::BGSType_InLFGQueue, 0);
            schedule3.parameter1 = uint32(botRequirement->needRole);
            uint32 count = botRequirement->selectedDungeons.size();
            schedule3.parameter2 = (count > 3) ? 3 : count;
            if (count >= 1)
                schedule3.parameter3 = duns[0];
            if (count >= 2)
                schedule3.parameter4 = duns[1];
            if (count >= 3)
                schedule3.parameter5 = duns[2];
            pSession->PushScheduleToQueue(schedule3);
            return;
        }


    }

    std::string allonlineText;
    consoleToUtf8(std::string("|cffff8800?????????????,????????????????|r"), allonlineText);
    sWorld->SendGlobalText(allonlineText.c_str(), NULL);
}

void PlayerBotMgr::AddNewPlayerBotToAA(TeamId team, BattlegroundTypeId bgTypeID, uint32 bracketID, uint32 aaType)
{
    if (aaType != 2 && aaType != 3 && aaType != 5)
        return;
    const SessionMap& allSession = sWorld->GetAllSessions();
    std::vector<uint32> rndIDs;
    for (SessionMap::const_iterator itSession = allSession.begin(); itSession != allSession.end(); itSession++)
        rndIDs.push_back(itSession->first);
    Trinity::Containers::RandomShuffle(rndIDs);
    for (uint32 account : rndIDs)
    {
        WorldSession* pWorldSession = sWorld->FindSession(account);
        if (!pWorldSession || !pWorldSession->IsBotSession())
            continue;
        PlayerBotSession* pSession = dynamic_cast<PlayerBotSession*>(pWorldSession);
        if (!pSession || pSession->PlayerLoading() || pSession->HasSchedules() || pSession->IsAccountBotSession())
            continue;
        Player* player = pSession->GetPlayer();
        if (!player)
        {
            if (m_MaxOnlineBot < m_BotOnlineCount)
                return;
            BotGlobleSchedule schedule1(BotGlobleScheduleType::BGSType_Online, 0);
            schedule1.parameter1 = (team == TeamId::TEAM_ALLIANCE) ? 1 : 2;
            pSession->PushScheduleToQueue(schedule1);

            BotGlobleSchedule schedule2(BotGlobleScheduleType::BGSType_Settting, 0);
            schedule2.parameter1 = CURRENT_MAX_LEVEL;
            schedule2.parameter2 = CURRENT_MAX_LEVEL;
            schedule2.parameter3 = 5;
            pSession->PushScheduleToQueue(schedule2);

            BotGlobleSchedule schedule3(BotGlobleScheduleType::BGSType_InAAQueue, 0);
            schedule3.parameter1 = bgTypeID;
            if (aaType == 2)
                schedule3.parameter2 = 0;
            else if (aaType == 3)
                schedule3.parameter2 = 1;
            else if (aaType == 5)
                schedule3.parameter2 = 2;
            pSession->PushScheduleToQueue(schedule3);

            BotGlobleSchedule schedule4(BotGlobleScheduleType::BGSType_EnterAA, 0);
            schedule4.parameter1 = bgTypeID;
            schedule4.parameter2 = bracketID;
            schedule4.parameter3 = aaType;
            schedule4.parameter4 = 0;
            pSession->PushScheduleToQueue(schedule4);

            return;
        }
        else if (IsIDLEPlayerBot(player))
        {
            //if (player->GetTeamId() != team)
            //	continue;

            BotGlobleSchedule schedule2(BotGlobleScheduleType::BGSType_Settting, 0);
            schedule2.parameter1 = CURRENT_MAX_LEVEL;
            schedule2.parameter2 = CURRENT_MAX_LEVEL;
            schedule2.parameter3 = 5;
            pSession->PushScheduleToQueue(schedule2);

            BotGlobleSchedule schedule3(BotGlobleScheduleType::BGSType_InAAQueue, 0);
            schedule3.parameter1 = bgTypeID;
            if (aaType == 2)
                schedule3.parameter2 = 0;
            else if (aaType == 3)
                schedule3.parameter2 = 1;
            else if (aaType == 5)
                schedule3.parameter2 = 2;
            pSession->PushScheduleToQueue(schedule3);

            BotGlobleSchedule schedule4(BotGlobleScheduleType::BGSType_EnterAA, 0);
            schedule4.parameter1 = bgTypeID;
            schedule4.parameter2 = bracketID;
            schedule4.parameter3 = aaType;
            schedule4.parameter4 = 0;
            pSession->PushScheduleToQueue(schedule4);

            return;
        }
    }

    std::string allonlineText;
    consoleToUtf8(std::string("|cffff8800?????????????,??????????????|r"), allonlineText);//此处是汉字输出的典型例子//This is the typical example of use Han language
    sWorld->SendGlobalText(allonlineText.c_str(), NULL);
}

void PlayerBotMgr::AddTeamBotToRatedArena(uint32 /*arenaTeamId*/)
{/*todo47
 if (arenaTeamId == 0)
 return;
 ArenaTeam* arenaTeam = sArenaTeamMgr->GetArenaTeamById(arenaTeamId);
 if (!arenaTeam)
 return;
 BattlegroundQueueTypeId bgQueueTypeID = BattlegroundMgr::BGQueueTypeId(BattlegroundTypeId(BattlegroundTypeId::BATTLEGROUND_AA), arenaTeam->GetType());
 BattlegroundQueue& bgQueue = sBattlegroundMgr->GetBattlegroundQueue(bgQueueTypeID);
 for (ArenaTeam::MemberList::iterator itaMem = arenaTeam->m_membersBegin(); itaMem != arenaTeam->m_membersEnd(); itaMem++)
 {
 ArenaTeamMember& mem = *itaMem;
 ObjectGuid guid = mem.Guid;
 if (bgQueue.ExistQueueByRatedArena(guid, true))
 continue;
 if (Player* player = ObjectAccessor::FindConnectedPlayer(guid))
 {
 if (!player->IsPlayerBot() || player->GetGroup())
 continue;
 if (PlayerBotSession* pSession = dynamic_cast<PlayerBotSession*>(player->GetSession()))
 {
 BotGlobleSchedule schedule2(BotGlobleScheduleType::BGSType_Settting, 0);
 schedule2.parameter1 = 80;
 schedule2.parameter2 = 80;
 schedule2.parameter3 = sArenaTeamMgr->FindArenaTeamPlayerBotTalent(guid) + 1;
 schedule2.parameter4 = (pSession->IsAccountBotSession()) ? 0 : 1;
 pSession->PushScheduleToQueue(schedule2);

 BotGlobleSchedule schedule3(BotGlobleScheduleType::BGSType_InAAQueue, 0);
 schedule3.parameter1 = BattlegroundTypeId::BATTLEGROUND_AA;
 if (arenaTeam->GetType() == 2)
 schedule3.parameter2 = 0;
 else if (arenaTeam->GetType() == 3)
 schedule3.parameter2 = 1;
 else if (arenaTeam->GetType() == 5)
 schedule3.parameter2 = 2;
 schedule3.parameter3 = 1;
 pSession->PushScheduleToQueue(schedule3);

 BotGlobleSchedule schedule4(BotGlobleScheduleType::BGSType_EnterAA, 0);
 schedule4.parameter1 = BattlegroundTypeId::BATTLEGROUND_AA;
 schedule4.parameter2 = 14;
 schedule4.parameter3 = arenaTeam->GetType();
 schedule4.parameter4 = 1;
 pSession->PushScheduleToQueue(schedule4);
 }
 }
 else if (PlayerBotSession* pSession = GetBotSessionByCharGUID(guid))
 {
 Player* player = pSession->GetPlayer();
 if (player)
 {
 BotGlobleSchedule schedule(BotGlobleScheduleType::BGSType_Offline, 0);
 pSession->PushScheduleToQueue(schedule);
 }
 BotGlobleSchedule schedule1(BotGlobleScheduleType::BGSType_Online_GUID, 0);
 schedule1.parameter1 = guid.GetCounter();
 pSession->PushScheduleToQueue(schedule1);

 BotGlobleSchedule schedule2(BotGlobleScheduleType::BGSType_Settting, 0);
 schedule2.parameter1 = 80;
 schedule2.parameter2 = 80;
 schedule2.parameter3 = sArenaTeamMgr->FindArenaTeamPlayerBotTalent(guid) + 1;
 schedule2.parameter4 = (pSession->IsAccountBotSession()) ? 0 : 1;
 pSession->PushScheduleToQueue(schedule2);

 BotGlobleSchedule schedule3(BotGlobleScheduleType::BGSType_InAAQueue, 0);
 schedule3.parameter1 = BattlegroundTypeId::BATTLEGROUND_AA;
 if (arenaTeam->GetType() == 2)
 schedule3.parameter2 = 0;
 else if (arenaTeam->GetType() == 3)
 schedule3.parameter2 = 1;
 else if (arenaTeam->GetType() == 5)
 schedule3.parameter2 = 2;
 schedule3.parameter3 = 1;
 pSession->PushScheduleToQueue(schedule3);

 BotGlobleSchedule schedule4(BotGlobleScheduleType::BGSType_EnterAA, 0);
 schedule4.parameter1 = BattlegroundTypeId::BATTLEGROUND_AA;
 schedule4.parameter2 = 14;
 schedule4.parameter3 = arenaTeam->GetType();
 schedule4.parameter4 = 1;
 pSession->PushScheduleToQueue(schedule4);
 }
 }
 */
}

bool PlayerBotMgr::FillOnlineBotScheduleByLFGRequirement(lfg::LFGBotRequirement* botRequirement, BotGlobleSchedule* botSchedule)
{
    if (!botRequirement || !botSchedule)
        return false;
    botSchedule->parameter1 = 0;
    if (botRequirement->needTeam == TEAM_ALLIANCE)
        botSchedule->parameter1 = 1;
    else if (botRequirement->needTeam == TEAM_HORDE)
        botSchedule->parameter1 = 2;
    else
        return false;
    std::vector<uint32> matchClasses;
    botSchedule->parameter2 = 0;
    if (botRequirement->needRole == lfg::LfgRoles::PLAYER_ROLE_TANK)
    {
        matchClasses.push_back(CLASS_WARRIOR);
        matchClasses.push_back(CLASS_PALADIN);
        matchClasses.push_back(CLASS_MONK);
        matchClasses.push_back(CLASS_DRUID);
        matchClasses.push_back(CLASS_DEMON_HUNTER);
        matchClasses.push_back(CLASS_DEATH_KNIGHT);
    }
    else if (botRequirement->needRole == lfg::LfgRoles::PLAYER_ROLE_HEALER)
    {
        matchClasses.push_back(CLASS_PRIEST);
        matchClasses.push_back(CLASS_MONK);
        matchClasses.push_back(CLASS_DRUID);
        matchClasses.push_back(CLASS_PALADIN);
        matchClasses.push_back(CLASS_SHAMAN);
    }
    else if (botRequirement->needRole == lfg::LfgRoles::PLAYER_ROLE_DAMAGE)
    {
        matchClasses.push_back(CLASS_WARRIOR);
        matchClasses.push_back(CLASS_PALADIN);
        matchClasses.push_back(CLASS_HUNTER);
        matchClasses.push_back(CLASS_ROGUE);
        matchClasses.push_back(CLASS_SHAMAN);
        matchClasses.push_back(CLASS_MAGE);
        matchClasses.push_back(CLASS_WARLOCK);
        matchClasses.push_back(CLASS_MONK);
        matchClasses.push_back(CLASS_DRUID);
        matchClasses.push_back(CLASS_DEMON_HUNTER);
        matchClasses.push_back(CLASS_PRIEST);
        matchClasses.push_back(CLASS_DEATH_KNIGHT);
    }
    if (matchClasses.empty())
        return false;
    botSchedule->parameter2 = matchClasses[urand(0, matchClasses.size() - 1)];
    return true;
}

uint32 PlayerBotMgr::GetScheduleTalentByLFGRequirement(lfg::LfgRoles roles, uint32 botCls)
{
    uint32 talentType = 3;
    switch (botCls)
    {
    case CLASS_WARRIOR:
        if (roles == lfg::LfgRoles::PLAYER_ROLE_TANK)
            talentType = 2;
        else
            talentType = urand(0, 1);
        break;
    case CLASS_PALADIN:
        if (roles == lfg::LfgRoles::PLAYER_ROLE_TANK)
            talentType = 1;
        else if (roles == lfg::LfgRoles::PLAYER_ROLE_HEALER)
            talentType = 0;
        else
            talentType = 2;
        break;
    case CLASS_DEATH_KNIGHT:
        if (roles == lfg::LfgRoles::PLAYER_ROLE_TANK)
            talentType = 0;
        else
            talentType = urand(1, 2);
        break;
    case CLASS_PRIEST:
        if (roles == lfg::LfgRoles::PLAYER_ROLE_DAMAGE)
            talentType = 2;
        else
            talentType = urand(0, 1);
        break;
    case CLASS_SHAMAN:
        if (roles == lfg::LfgRoles::PLAYER_ROLE_HEALER)
            talentType = 2;
        else
            talentType = urand(0, 1);
        break;
    case CLASS_DRUID:
        if (roles == lfg::LfgRoles::PLAYER_ROLE_HEALER)
            talentType = 3;
        else if (roles == lfg::LfgRoles::PLAYER_ROLE_TANK)
            talentType = 2;
        else
            talentType = urand(0, 1);
        break;
    case CLASS_MONK:
        if (roles == lfg::LfgRoles::PLAYER_ROLE_HEALER)
            talentType = 2;
        else if (roles == lfg::LfgRoles::PLAYER_ROLE_TANK)
            talentType = 0;
        else
            talentType = 1;
        break;
    case CLASS_DEMON_HUNTER:
        if (roles == lfg::LfgRoles::PLAYER_ROLE_TANK)
            talentType = 1;
        else
            talentType = 0;
        break;
    case CLASS_MAGE:
    case CLASS_HUNTER:
    case CLASS_WARLOCK:
    case CLASS_ROGUE:
        talentType = urand(0, 2);
        break;
    }
    return talentType;
}

lfg::LfgRoles PlayerBotMgr::GetPlayerBotCurrentLFGRoles(Player* player)
{
    if (!player)
        return lfg::LfgRoles::PLAYER_ROLE_NONE;
    uint32 talentType = player->FindTalentType();
    switch (player->getClass())
    {
    case CLASS_WARRIOR:
        if (talentType == 2)
            return lfg::LfgRoles::PLAYER_ROLE_TANK;
        else
            return lfg::LfgRoles::PLAYER_ROLE_DAMAGE;
        break;
    case CLASS_PALADIN:
        if (talentType == 0)
            return lfg::LfgRoles::PLAYER_ROLE_HEALER;
        else if (talentType == 1)
            return lfg::LfgRoles::PLAYER_ROLE_TANK;
        else
            return lfg::LfgRoles::PLAYER_ROLE_DAMAGE;
        break;
    case CLASS_DEATH_KNIGHT:
        if (talentType == 0)
            return lfg::LfgRoles::PLAYER_ROLE_TANK;
        else
            return lfg::LfgRoles::PLAYER_ROLE_DAMAGE;
        break;
    case CLASS_HUNTER:
    case CLASS_ROGUE:
    case CLASS_MAGE:
    case CLASS_WARLOCK:
        return lfg::LfgRoles::PLAYER_ROLE_DAMAGE;
        break;
    case CLASS_PRIEST:
        if (talentType == 2)
            return lfg::LfgRoles::PLAYER_ROLE_DAMAGE;
        else
            return lfg::LfgRoles::PLAYER_ROLE_HEALER;
        break;
    case CLASS_SHAMAN:
        if (talentType == 2)
            return lfg::LfgRoles::PLAYER_ROLE_HEALER;
        else
            return lfg::LfgRoles::PLAYER_ROLE_DAMAGE;
        break;
    case CLASS_DRUID:
        if (talentType == 2)
            return lfg::LfgRoles::PLAYER_ROLE_TANK;
        else if (talentType == 3)
            return lfg::LfgRoles::PLAYER_ROLE_HEALER;
        else
            return lfg::LfgRoles::PLAYER_ROLE_DAMAGE;
        break;
    case CLASS_MONK:
        if (talentType == 0)
            return lfg::LfgRoles::PLAYER_ROLE_TANK;
        else if (talentType == 2)
            return lfg::LfgRoles::PLAYER_ROLE_HEALER;
        else
            return lfg::LfgRoles::PLAYER_ROLE_DAMAGE;
        break;
    case CLASS_DEMON_HUNTER:
        if (talentType == 1)
            return lfg::LfgRoles::PLAYER_ROLE_TANK;
        else
            return lfg::LfgRoles::PLAYER_ROLE_DAMAGE;
        break;
    default:
        return lfg::LfgRoles::PLAYER_ROLE_DAMAGE;
    }
    return lfg::LfgRoles::PLAYER_ROLE_DAMAGE;
}

ObjectGuid PlayerBotMgr::GetNoArenaMatchCharacter(TeamId /*team*/, uint32 /*arenaType*/, Classes /*cls*/, std::vector<ObjectGuid>& /*fliters*/)
{/*todo47
 if (team != TEAM_ALLIANCE && team != TEAM_HORDE)
 return ObjectGuid::Empty;
 if (arenaType != 2 && arenaType != 3 && arenaType != 5)
 return ObjectGuid::Empty;
 if (m_idPlayerBotBase.empty())
 return ObjectGuid::Empty;
 std::vector<PlayerBotBaseInfo*> allBotBaseInfos;
 for (std::map<uint32, PlayerBotBaseInfo*>::iterator itInfo = m_idPlayerBotBase.begin();
 itInfo != m_idPlayerBotBase.end();
 itInfo++)
 allBotBaseInfos.push_back(itInfo->second);
 for (uint32 i = allBotBaseInfos.size() - 1; i >= 0; --i)
 {
 PlayerBotBaseInfo* pInfo = allBotBaseInfos[i];
 uint32 id = pInfo->GetCharIDByNoArenaType((team == TEAM_ALLIANCE) ? true : false, cls, arenaType, fliters);
 if (id == 0)
 continue;
 bool exist = false;
 for (ObjectGuid& guid : fliters)
 {
 if (guid.GetCounter() == id)
 {
 exist = true;
 break;
 }
 }
 if (!exist)
 return ObjectGuid(uint64(id));
 }*/

 //for (std::map<uint32, PlayerBotBaseInfo*>::iterator itInfo = m_idPlayerBotBase.begin();
 //	itInfo != m_idPlayerBotBase.end();
 //	itInfo++)
 //{
 //	PlayerBotBaseInfo* pInfo = itInfo->second;
 //	uint32 id = pInfo->GetCharIDByNoArenaType((team == TEAM_ALLIANCE) ? true : false, cls, arenaType, fliters);
 //	if (id == 0)
 //		continue;
 //	bool exist = false;
 //	for (ObjectGuid& guid : fliters)
 //	{
 //		if (guid.GetCounter() == id)
 //		{
 //			exist = true;
 //			break;
 //		}
 //	}
 //	if (!exist)
 //		return ObjectGuid(uint64(id));
 //}
    return ObjectGuid::Empty;
}

std::string PlayerBotMgr::GetNameANDClassesText(ObjectGuid& guid)
{
    for (std::map<uint32, PlayerBotBaseInfo*>::iterator itInfo = m_idPlayerBotBase.begin();
        itInfo != m_idPlayerBotBase.end();
        itInfo++)
    {
        PlayerBotBaseInfo* pInfo = itInfo->second;
        std::string text = pInfo->GetCharNameANDClassesText(guid);
        if (!text.empty())
            return text;
    }
    return "";
}

bool PlayerBotMgr::CanReadyArenaByArenaTeamID(uint32 /*arenaTeamId*/)
{/*todo47
 if (arenaTeamId == 0)
 return false;
 ArenaTeam* arenaTeam = sArenaTeamMgr->GetArenaTeamById(arenaTeamId);
 if (!arenaTeam || !arenaTeam->IsPurityPlayerBotTeam())
 return false;
 BattlegroundQueue* bgQueue = arenaTeam->GetMatchBattlegroundQueue();
 if (!bgQueue)
 return false;
 for (ArenaTeam::MemberList::iterator itaMem = arenaTeam->m_membersBegin(); itaMem != arenaTeam->m_membersEnd(); itaMem++)
 {
 ArenaTeamMember& mem = *itaMem;
 ObjectGuid guid = mem.Guid;
 if (Player* player = ObjectAccessor::FindConnectedPlayer(guid))
 {
 if (!player->IsPlayerBot())
 return false;
 if (player->InBattleground() || player->InArena() || player->isUsingLfg() || player->GetGroup())
 return false;
 if (player->GetSession() && player->GetSession()->HasSchedules())
 {
 if (!bgQueue->ExistQueueByRatedArena(guid, true))
 return false;
 }
 }
 else if (PlayerBotSession* pSession = GetBotSessionByCharGUID(guid))
 {
 if (pSession->PlayerLoading())
 return false;
 if (Player* player = pSession->GetPlayer())
 {
 if (player->InBattleground() || player->InArena() || player->isUsingLfg() || player->GetGroup())
 return false;
 if (pSession->HasSchedules())
 {
 if (!bgQueue->ExistQueueByRatedArena(guid, true))
 return false;
 }
 }
 }
 }*/
    return true;
}

void PlayerBotMgr::QueryBattlegroundRequirement()
{
    for (BattleGroundTypes::iterator itType = m_BGTypes.begin(); itType != m_BGTypes.end(); itType++)
    {
        BattlegroundTypeId bgTypeID = *itType;
        Battleground* bg_template = sBattlegroundMgr->GetBattlegroundTemplate(bgTypeID);
        if (!bg_template)
            continue;

        /* BGFreeSlotQueueContainer& bgFreeSlotQueues = sBattlegroundMgr->GetBGFreeSlotQueueStore(bgTypeID);
         for (BGFreeSlotQueueContainer::iterator itr = bgFreeSlotQueues.begin(); itr != bgFreeSlotQueues.end(); itr++)
         {
             Battleground* bg = *itr;
             if (!bg->ExistRealPlayer())
                 continue;
             uint32 minLV = bg->GetMinLevel();
             uint32 maxLV = bg->GetMaxLevel();
             int32 needAllianceCount = bg->GetFreeSlotsForTeam(Team::ALLIANCE);
             int32 needHordeCount = bg->GetFreeSlotsForTeam(Team::HORDE);
             if (!bg->isRated() && bg->GetStatus() > STATUS_WAIT_QUEUE && bg->GetStatus() < STATUS_WAIT_LEAVE)
             {
                 //printf("BGFreeSlotQueueContainer %d %d \n", needAllianceCount, needHordeCount);
                 if (needAllianceCount > 0 && needAllianceCount>= needHordeCount)
                     AddNewPlayerBotToBG(TeamId::TEAM_ALLIANCE, minLV, maxLV, bgTypeID);
                 else if (needHordeCount > 0)
                     AddNewPlayerBotToBG(TeamId::TEAM_HORDE, minLV, maxLV, bgTypeID);
                 else
                     continue;
                 return;
             }
         }
         */
        BattlegroundQueueTypeId bgQueueTypeID= BattlegroundMgr::BGQueueTypeId(BattlegroundTypeId(bgTypeID),{}, false,0);
        BattlegroundQueue& bgQueue = sBattlegroundMgr->GetBattlegroundQueue(bgQueueTypeID);
        for (uint32 j = BattlegroundBracketId::BG_BRACKET_ID_FIRST; j <= BattlegroundBracketId::BG_BRACKET_ID_LAST; j++)
        {
            BattlegroundBracketId bracket = BattlegroundBracketId(j);
            PVPDifficultyEntry const* bracketEntry = DB2Manager::GetBattlegroundBracketById(bg_template->GetMapId(), bracket);
            if (!bracketEntry)
                continue;
            if (!bgQueue.ExistRealPlayer(bracketEntry))
                continue;
            //int32 needAlliancePlayerCount = 0;
            //int32 needHordePlayerCount = 0;
            //if (bgQueue.QueryNeedPlayerCount(bgTypeID, bracket, 0, needAlliancePlayerCount, needHordePlayerCount))
            //{
            //    if (needAlliancePlayerCount > 0 && needAlliancePlayerCount >= needHordePlayerCount)
            //        AddNewPlayerBotToBG(TeamId::TEAM_ALLIANCE, bracketEntry->MinLevel, bracketEntry->MaxLevel, bgTypeID);
            //    else if (needHordePlayerCount > 0)
            //        AddNewPlayerBotToBG(TeamId::TEAM_HORDE, bracketEntry->MinLevel, bracketEntry->MaxLevel, bgTypeID);
            //    else
            //        continue;

            //    printf("QueryNeedPlayerCount %d %d \n", needAlliancePlayerCount, needHordePlayerCount);
            //    return;
            //}
        }

    }
}

void PlayerBotMgr::QueryRatedArenaRequirement()
{/*todo47
 if (m_ArenaSearchTick > 0)
 {
 --m_ArenaSearchTick;
 return;
 }
 Battleground* bg_template = sBattlegroundMgr->GetBattlegroundTemplate(BattlegroundTypeId::BATTLEGROUND_AA);
 if (!bg_template)
 return;
 PVPDifficultyEntry const* bracketEntry = FindBGBracketEntry(bg_template, 80);
 if (!bracketEntry)
 return;

 uint32 arenaType[3] = { 2, 3, 5 };
 for (uint32 i = 0; i < 3; i++)
 {
 BattlegroundQueueTypeId bgQueueTypeID = BattlegroundMgr::BGQueueTypeId(BattlegroundTypeId(BattlegroundTypeId::BATTLEGROUND_AA), arenaType[i]);
 BattlegroundQueue& bgQueue = sBattlegroundMgr->GetBattlegroundQueue(bgQueueTypeID);
 if (!bgQueue.ExistRealPlayer(bracketEntry, true))
 {
 bgQueue.AllPlayerBotLeaveQueueFromRatedArena(bracketEntry->GetBracketId());
 continue;
 }
 uint32 allianceArenaTeamID = 0;
 uint32 hordeArenaTeamID = 0;
 GroupQueueInfo* allianceGroupInfo = bgQueue.GetFirstRealPlayerGroupInfo(bracketEntry->GetBracketId(), BattlegroundQueueGroupTypes::BG_QUEUE_PREMADE_ALLIANCE);
 GroupQueueInfo* hordeGroupInfo = bgQueue.GetFirstRealPlayerGroupInfo(bracketEntry->GetBracketId(), BattlegroundQueueGroupTypes::BG_QUEUE_PREMADE_HORDE);
 if (!allianceGroupInfo && !hordeGroupInfo)
 continue;
 if (allianceGroupInfo && hordeGroupInfo)
 {
 allianceArenaTeamID = allianceGroupInfo->ArenaTeamId;
 hordeArenaTeamID = hordeGroupInfo->ArenaTeamId;
 }
 else if (allianceGroupInfo && !BotUtility::DownBotArenaTeam)
 {
 allianceArenaTeamID = allianceGroupInfo->ArenaTeamId;
 hordeArenaTeamID = sArenaTeamMgr->SearchEnemyArenaTeam(allianceArenaTeamID, HORDE);
 if (hordeArenaTeamID == 0)
 continue;
 AddTeamBotToRatedArena(hordeArenaTeamID);
 }
 else if (hordeGroupInfo && !BotUtility::DownBotArenaTeam)
 {
 hordeArenaTeamID = hordeGroupInfo->ArenaTeamId;
 allianceArenaTeamID = sArenaTeamMgr->SearchEnemyArenaTeam(hordeArenaTeamID, ALLIANCE);
 if (allianceArenaTeamID == 0)
 continue;
 AddTeamBotToRatedArena(allianceArenaTeamID);
 }
 else
 continue;
 m_ArenaSearchTick = 14;
 break;
 }*/
}

void PlayerBotMgr::QueryNonRatedArenaRequirement()
{
    Battleground* bg_template = sBattlegroundMgr->GetBattlegroundTemplate(BattlegroundTypeId::BATTLEGROUND_AA);
    if (!bg_template)
        return;
    PVPDifficultyEntry const* bracketEntry = FindBGBracketEntry(bg_template, CURRENT_MAX_LEVEL);
    if (!bracketEntry)
        return;
    /*BGFreeSlotQueueContainer& bgFreeSlotQueues = sBattlegroundMgr->GetBGFreeSlotQueueStore(BattlegroundTypeId::BATTLEGROUND_AA);
    for (BGFreeSlotQueueContainer::iterator itr = bgFreeSlotQueues.begin(); itr != bgFreeSlotQueues.end(); itr++)
    {
        Battleground* bg = *itr;
        if (!bg->ExistRealPlayer())
            continue;
        if (bg->GetStatus() > STATUS_WAIT_QUEUE && bg->GetStatus() < STATUS_WAIT_LEAVE)
        {
            if (bg->GetFreeSlotsForTeam(Team::ALLIANCE) > 0)
                AddNewPlayerBotToAA(TeamId::TEAM_ALLIANCE, BattlegroundTypeId::BATTLEGROUND_AA, bracketEntry->GetBracketId(), bg->GetMaxPlayers() / 2);
            else if (bg->GetFreeSlotsForTeam(Team::HORDE) > 0)
                AddNewPlayerBotToAA(TeamId::TEAM_HORDE, BattlegroundTypeId::BATTLEGROUND_AA, bracketEntry->GetBracketId(), bg->GetMaxPlayers() / 2);
            else
                continue;
            return;*/
            // }
       //  }

    uint32 arenaType[3] = { 2, 3, 5 };
    for (uint32 i = 0; i < 3; i++)
    {
        BattlegroundQueueTypeId bgQueueTypeID = BattlegroundMgr::BGQueueTypeId(BattlegroundTypeId(BattlegroundTypeId::BATTLEGROUND_AA), BattlegroundQueueIdType::Arena, true, 5);//BattlegroundQueueIdType::Arena-->arenaType[i]
        BattlegroundQueue& bgQueue = sBattlegroundMgr->GetBattlegroundQueue(bgQueueTypeID);
        if (!bgQueue.ExistRealPlayer(bracketEntry, false))
            continue;
        //int32 needAlliancePlayerCount = 0;
        //int32 needHordePlayerCount = 0;
        //if (bgQueue.QueryNeedPlayerCount(BattlegroundTypeId::BATTLEGROUND_AA, bracketEntry->GetBracketId(), arenaType[i], needAlliancePlayerCount, needHordePlayerCount))
        //{
        //    if (needAlliancePlayerCount > 0 && needAlliancePlayerCount >= needHordePlayerCount)
        //        AddNewPlayerBotToAA(TeamId::TEAM_ALLIANCE, BattlegroundTypeId::BATTLEGROUND_AA, bracketEntry->GetBracketId(), arenaType[i]);
        //    else if (needHordePlayerCount > 0)
        //        AddNewPlayerBotToAA(TeamId::TEAM_HORDE, BattlegroundTypeId::BATTLEGROUND_AA, bracketEntry->GetBracketId(), arenaType[i]);
        //    else
        //        continue;
        //    return;
        //}
    }
}

void PlayerBotMgr::OnlinePlayerBotByGUIDQueue()
{
    while (!m_DelayOnlineBots.empty())
    {
        ObjectGuid& guid = m_DelayOnlineBots.front();
        m_DelayOnlineBots.pop();
        if (AddNewPlayerBotByGUID(guid))
            return;
    }
}

bool PlayerBotMgr::ExistUnBGPlayerBot()
{
    const SessionMap& allSession = sWorld->GetAllSessions();
    for (SessionMap::const_iterator itSession = allSession.begin(); itSession != allSession.end(); itSession++)
    {
        if (!itSession->second->IsBotSession())
            continue;
        PlayerBotSession* pSession = dynamic_cast<PlayerBotSession*>((WorldSession*)itSession->second);
        if (!pSession)
            continue;
        if (pSession->PlayerLoading() || pSession->IsAccountBotSession())
            continue;
        Player* player = pSession->GetPlayer();
        if (!player || !player->IsInWorld())
            continue;
        if (player->InBattleground() || player->InBattlegroundQueue() || player->isUsingLfg() || player->GetGroup())
            continue;
        if (player->HasAura(26013))
            continue;
        if (!pSession->HasSchedules())
            continue;
        return true;
    }
    return false;
}

PVPDifficultyEntry const* PlayerBotMgr::FindBGBracketEntry(Battleground* bg_template, uint32 level)
{
    if (!bg_template)
        return NULL;
    for (uint32 j = BattlegroundBracketId::BG_BRACKET_ID_FIRST; j <= BattlegroundBracketId::BG_BRACKET_ID_LAST; j++)
    {
        BattlegroundBracketId bracket = BattlegroundBracketId(j);
        PVPDifficultyEntry const* bracketEntry = DB2Manager::GetBattlegroundBracketById(bg_template->GetMapId(), bracket);
        if (!bracketEntry)
            continue;
        if (bracketEntry->MinLevel <= level && bracketEntry->MaxLevel >= level)
            return bracketEntry;
    }
    return NULL;
}

uint32 PlayerBotMgr::GetOnlineBotCount(TeamId team, bool hasReal)
{
    uint32 onlineCount = 0;
    const SessionMap& allSession = sWorld->GetAllSessions();
    for (SessionMap::const_iterator itSession = allSession.begin(); itSession != allSession.end(); itSession++)
    {
        if (itSession->second->IsBotSession())
        {
            PlayerBotSession* pSession = dynamic_cast<PlayerBotSession*>((WorldSession*)itSession->second);
            if (!pSession)
                continue;
            if (pSession->PlayerLoading())
            {
                ++onlineCount;
                continue;
            }
            Player* player = pSession->GetPlayer();
            if (!player || !player->IsInWorld())
                continue;
            if (team != TEAM_NEUTRAL)
            {
                if (player->GetTeamId() != team)
                    continue;
            }
            ++onlineCount;
        }
        else if (hasReal)
        {
            WorldSession* pSession = itSession->second;
            if (pSession->PlayerLoading())
                continue;
            Player* player = pSession->GetPlayer();
            if (!player || !player->IsInWorld())
                continue;
            if (team != TEAM_NEUTRAL)
            {
                if (player->GetTeamId() != team)
                    continue;
            }
            ++onlineCount;
        }
    }
    return onlineCount;
}

uint32 PlayerBotMgr::GetAllowMaxBotCount()
{
    return sConfigMgr->GetIntDefault("PBot.MaxOnlineCount", 20);
}

uint32 PlayerBotMgr::GetAllowMaxWarrfareBotCount()
{
    return sConfigMgr->GetIntDefault("PBot.MaxWarrfareCount", 20);
}

void PlayerBotMgr::Update(uint32 diff)
{
    m_Events.Update(diff);

    OnlinePlayerBotByGUIDQueue();

    AutoPlayerBotRandomLogin();

    //if (!ExistUnBGPlayerBot())
    if (m_BGSearchTick > 1)
    {
        m_BGSearchTick = 0;
        QueryBattlegroundRequirement();
    }
    else
        ++m_BGSearchTick;

    //sArenaTeamMgr->CheckPlayerBotArenaTeam();todo47
    QueryRatedArenaRequirement();
    QueryNonRatedArenaRequirement();
    if (m_LFGSearchTick > 1)
    {
        m_LFGSearchTick = 0;
        //if (lfg::LFGBotRequirement* pbotReq = sLFGMgr->SearchLFGBotRequirement())
        //{
        //    AddNewPlayerBotToLFG(pbotReq);
        //    delete pbotReq;
        //}
    }
    else
        ++m_LFGSearchTick;


    std::list<std::map<uint32, std::list<UnitAI*> >::iterator > delITer;
    uint32 currentTick = getMSTime();
    for (std::map<uint32, std::list<UnitAI*> >::iterator itDelayAi = m_DelayDestroyAIs.begin();
        itDelayAi != m_DelayDestroyAIs.end();
        itDelayAi++)
    {
        uint32 delayTick = itDelayAi->first;
        if (delayTick + 5000 >= currentTick)
        {
            for (std::list<UnitAI*>::iterator itAI = itDelayAi->second.begin();
                itAI != itDelayAi->second.end();
                itAI++)
            {
                UnitAI* pAI = (*itAI);
                if (pAI)
                    delete pAI;
            }
            itDelayAi->second.clear();
            delITer.push_back(itDelayAi);
        }
    }
    for (std::list<std::map<uint32, std::list<UnitAI*> >::iterator >::iterator itDel = delITer.begin();
        itDel != delITer.end();
        itDel++)
    {
        m_DelayDestroyAIs.erase(*itDel);
    }
}

void PlayerBotMgr::ProcessMoveToCommand(ObjectGuid& guid, float x, float y, float z, float o, float offset)
{
    Player* findPlayer = ObjectAccessor::FindPlayer(guid);
    if (!findPlayer)
        return;
    if (BotGroupAI* pGroupAI = dynamic_cast<BotGroupAI*>(findPlayer->GetAI()))
    {
        if (pGroupAI->IsTankBotAI())
            pGroupAI->ProcessMoveToCommand(x, y, z, o, offset);
        else if (pGroupAI->IsHealerBotAI())
            pGroupAI->ProcessMoveToCommand(x, y, z, o, offset);
        else
            pGroupAI->ProcessMoveToCommand(x, y, z, o, offset);
    }
}

