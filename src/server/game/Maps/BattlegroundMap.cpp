//#include "BattlegroundMap.h"
//#include "ObjectMgr.h"
//#include "Map.h"
//#include "PlayerBotMgr.h"
//#include "BotAITool.h"/*
//#include "CommandBG/CommandAB.h"
//#include "CommandBG/CommandAV.h"
//#include "CommandBG/CommandEY.h"
//#include "CommandBG/CommandIC.h"
//#include "CommandBG/CommandWS.h"
//
//BattlegroundMap::BattlegroundMap(uint32 id, time_t expiry, uint32 instanceId, Map* parent, Difficulty difficulty) : Map(id, expiry, instanceId, difficulty, parent)
//{
//    m_bg = nullptr;
//
//    BattlegroundMap::InitVisibilityDistance();
//
//    if (auto _distMap = GetVisibleDistance(TYPE_VISIBLE_MAP, id))
//        m_VisibleDistance = _distMap;
//}
//
//BattlegroundMap::~BattlegroundMap()
//{
//    if (!m_bg)
//        return;
//
//    m_bg->SetBgMap(nullptr);
//    m_bg = nullptr;
//}*/
//
////void BattlegroundMap::InitVisibilityDistance()
////{
////    m_VisibleDistance = GetEntry()->IsBattleArena() ? sWorld->GetMaxVisibleDistanceInArenas() : sWorld->GetMaxVisibleDistanceInBG();
////    m_VisibilityNotifyPeriod = World::GetVisibilityNotifyPeriodInBGArenas();
////}
////
////void BattlegroundMap::Update(const uint32 diff)
////{
////    Map::Update(diff);
////    if (m_pAllianceCommander)
////        m_pAllianceCommander->Update(diff);
////    if (m_pHordeCommander)
////        m_pHordeCommander->Update(diff);
////}
////
////void BattlegroundMap::InsureCommander(uint8 bgType)
////{
////    if (!m_pAllianceCommander)
////    {
////        switch (bgType)
////        {
////        case MS::Battlegrounds::BattlegroundTypeId::BattlegroundArathiBasin:
////            m_pAllianceCommander = new CommandAB(m_bg, TeamId::TEAM_ALLIANCE);
////            break;
////        case MS::Battlegrounds::BattlegroundTypeId::BattlegroundWarsongGulch:
////            m_pAllianceCommander = new CommandWS(m_bg, TeamId::TEAM_ALLIANCE);
////            break;
////        case MS::Battlegrounds::BattlegroundTypeId::BattlegroundEyeOfTheStorm:
////            m_pAllianceCommander = new CommandEY(m_bg, TeamId::TEAM_ALLIANCE);
////            break;
////        case MS::Battlegrounds::BattlegroundTypeId::BattlegroundAlteracValley:
////            m_pAllianceCommander = new CommandAV(m_bg, TeamId::TEAM_ALLIANCE);
////            break;
////        case MS::Battlegrounds::BattlegroundTypeId::BattlegroundIsleOfConquest:
////            m_pAllianceCommander = new CommandIC(m_bg, TeamId::TEAM_ALLIANCE);
////            break;
////        }
////    }
////    if (!m_pHordeCommander)
////    {
////        switch (bgType)
////        {
////        case MS::Battlegrounds::BattlegroundTypeId::BattlegroundArathiBasin:
////            m_pHordeCommander = new CommandAB(m_bg, TeamId::TEAM_HORDE);
////            break;
////        case MS::Battlegrounds::BattlegroundTypeId::BattlegroundWarsongGulch:
////            m_pHordeCommander = new CommandWS(m_bg, TeamId::TEAM_HORDE);
////            break;
////        case MS::Battlegrounds::BattlegroundTypeId::BattlegroundEyeOfTheStorm:
////            m_pHordeCommander = new CommandEY(m_bg, TeamId::TEAM_HORDE);
////            break;
////        case MS::Battlegrounds::BattlegroundTypeId::BattlegroundAlteracValley:
////            m_pHordeCommander = new CommandAV(m_bg, TeamId::TEAM_HORDE);
////            break;
////        case MS::Battlegrounds::BattlegroundTypeId::BattlegroundIsleOfConquest:
////            m_pHordeCommander = new CommandIC(m_bg, TeamId::TEAM_HORDE);
////            break;
////        }
////    }
////}
////
////void BattlegroundMap::InitCommander()
////{
////    if (m_pAllianceCommander)
////        m_pAllianceCommander->Initialize();
////    if (m_pHordeCommander)
////        m_pHordeCommander->Initialize();
////}
////
////void BattlegroundMap::ResetCommander()
////{
////    if (m_pAllianceCommander)
////        m_pAllianceCommander->UpdateBelongBattleground(m_bg);
////    if (m_pHordeCommander)
////        m_pHordeCommander->UpdateBelongBattleground(m_bg);
////}
////
////void BattlegroundMap::ReadyCommander()
////{
////    if (m_pAllianceCommander)
////        m_pAllianceCommander->ReadyGame();
////    if (m_pHordeCommander)
////        m_pHordeCommander->ReadyGame();
////}
////
////void BattlegroundMap::StartCommander()
////{
////    if (m_pAllianceCommander)
////        m_pAllianceCommander->StartGame();
////    if (m_pHordeCommander)
////        m_pHordeCommander->StartGame();
////}
//
//CommandBG* BattlegroundMap::GetCommander(TeamId team)
//{
//    if (team == TEAM_ALLIANCE)
//        return m_pAllianceCommander;
//    else if (team == TEAM_HORDE)
//        return m_pHordeCommander;
//    return NULL;
//}
//
////
////Battleground* BattlegroundMap::GetBG()
////{
////    return m_bg;
////}
////
////void BattlegroundMap::SetBG(Battleground* bg)
////{
////    m_bg = bg;
////}
////
////bool BattlegroundMap::CanEnter(Player* player)
////{
////    if (player->GetMapRef().getTarget() == this)
////    {
////        TC_LOG_ERROR(LOG_FILTER_MAPS, "BGMap::CanEnter - player %u is already in map!", player->GetGUIDLow());
////        ASSERT(false);
////        return false;
////    }
////
////    if (player->GetBattlegroundId() != GetInstanceId())
////        return false;
////
////    return Map::CanEnter(player);
////}
////
////bool BattlegroundMap::AddPlayerToMap(Player* player, bool initPlayer /*= true*/)
////{
////    if (auto bg = player->GetBattleground())
////        bg->OnPlayerEnter(player);
////
////    player->AddDelayedEvent(10, [player]() -> void
////        {
////            player->OnEnterMap(); // UpdatePhase
////        });
////
////    player->m_InstanceValid = true;
////    bool ret = Map::AddPlayerToMap(player, initPlayer);
////    if (ret && player->IsPlayerBot())
////    {
////        if (player->GetTeamId() == TEAM_ALLIANCE && m_pAllianceCommander)
////        {
////            m_pAllianceCommander->AddPlayerBot(player, m_bg);
////        }
////        else if (player->GetTeamId() == TEAM_HORDE && m_pHordeCommander)
////        {
////            m_pHordeCommander->AddPlayerBot(player, m_bg);
////        }
////    }
////
////    return ret;
////}
////
////void BattlegroundMap::RemovePlayerFromMap(Player* player, bool remove)
////{
////    if (player->IsPlayerBot())
////    {
////        PlayerBotMgr::SwitchPlayerBotAI(player, PlayerBotAIType::PBAIT_FIELD, true);
////        if (player->GetTeamId() == TEAM_ALLIANCE && m_pAllianceCommander)
////        {
////            m_pAllianceCommander->RemovePlayerBot(player);
////        }
////        else if (player->GetTeamId() == TEAM_HORDE && m_pHordeCommander)
////        {
////            m_pHordeCommander->RemovePlayerBot(player);
////        }
////    }
////
////    if (player && player->IsSpectator() && !player->IsSpectateCanceled())
////        if (GetBG())
////            GetBG()->RemoveSpectator(player);
////
////#ifdef TRINITY_DEBUG
////    TC_LOG_INFO(LOG_FILTER_MAPS, "MAP: Removing player '%s' from bg '%u' of map '%s' before relocating to another map", player->GetName(), GetInstanceId(), GetMapName());
////#endif
////    Map::RemovePlayerFromMap(player, remove);
////}
////
////void BattlegroundMap::SetUnload()
////{
////    m_unloadTimer = MIN_UNLOAD_DELAY;
////}
////
////void BattlegroundMap::RemoveAllPlayers()
////{
////    if (!HavePlayers())
////        return;
////
////    for (auto& itr : m_mapRefManager)
////    {
////        auto player = itr.getSource();
////        if (!player || player->IsBeingTeleportedFar())
////            continue;
////
////        if (player->IsSpectator())
////            player->SetSpectateRemoving(true);
////        player->TeleportTo(player->GetBattlegroundEntryPoint());
////    }
////}
