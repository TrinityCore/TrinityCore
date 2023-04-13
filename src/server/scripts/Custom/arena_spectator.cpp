///*
// * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
// * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
// *
// * This program is free software; you can redistribute it and/or modify it
// * under the terms of the GNU General Public License as published by the
// * Free Software Foundation; either version 2 of the License, or (at your
// * option) any later version.
// *
// * This program is distributed in the hope that it will be useful, but WITHOUT
// * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
// * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
// * more details.
// *
// * You should have received a copy of the GNU General Public License along
// * with this program. If not, see <http://www.gnu.org/licenses/>.
// */
//
//#include "Arena.h"
//#include "BattlegroundMgr.h"
//#include "Bracket.h"
//#include "Group.h"
//#include "SpectatorAddon.h"
//
//class arena_spectator_commands : public CommandScript
//{
//public:
//    arena_spectator_commands() : CommandScript("arena_spectator_commands") { }
//
//    static bool HandleSpectateCommand(ChatHandler* handler, const char* args)
//    {
//        Player* player = nullptr;
//        auto name = handler->extractPlayerNameFromLink((char*)args);
//        if (!name.empty())
//            player = sObjectAccessor->FindPlayerByName(name.c_str());
//        else
//            player = handler->getSelectedPlayer();
//
//        if (!player)
//        {
//            handler->SendSysMessage(LANG_PLAYER_NOT_FOUND);
//            return false;
//        }
//
//        return SpectateByGuid(handler, player->GetGUID());
//    }
//
//    static bool SpectateByGuid(ChatHandler* handler, ObjectGuid guid)
//    {
//        auto targetGuid = guid;
//        auto player = handler->GetSession()->GetPlayer();
//
//        if (targetGuid == player->GetGUID())
//        {
//            handler->SendSysMessage(LANG_CANT_TELEPORT_SELF);
//            handler->SetSentErrorMessage(true);
//            return false;
//        }
//
//        if (player->isInCombat())
//        {
//            handler->SendSysMessage(LANG_YOU_IN_COMBAT);
//            handler->SetSentErrorMessage(true);
//            return false;
//        }
//
//        if (!player->isAlive())
//        {
//            handler->SendSysMessage("You are dead.");
//            handler->SetSentErrorMessage(true);
//            return false;
//        }
//
//        if (player->GetPet())
//        {
//            handler->PSendSysMessage("You must hide your pet.");
//            handler->SetSentErrorMessage(true);
//            return false;
//        }
//
//        if (auto tPlayer = ObjectAccessor::FindPlayer(targetGuid))
//        {
//            if (tPlayer && player && !player->GetMap()->IsBattlegroundOrArena())
//            {
//                Battleground* bg = tPlayer->GetBattleground();
//                if (!bg || bg->GetStatus() != STATUS_IN_PROGRESS)
//                {
//                    handler->PSendSysMessage("Battleground has not started.");
//                    handler->SetSentErrorMessage(true);
//                    return false;
//                }
//
//                player->SetBattlegroundId(tPlayer->GetBattlegroundId(), tPlayer->GetBattlegroundTypeId());
//                player->SetBattlegroundEntryPoint();
//
//                if (player->TeleportTo(tPlayer->GetMapId(), tPlayer->GetPositionX(), tPlayer->GetPositionY(), tPlayer->GetPositionZ(), 0.0f))
//                {
//                    player->SetSpectate(true);
//                    if (player->GetBattleground())
//                        player->GetBattleground()->AddSpectator(player);
//                }
//            }
//        }
//
//        return true;
//    }
//
//    static bool HandleSpectateCancelCommand(ChatHandler* handler, const char* /*args*/)
//    {
//        auto player = handler->GetSession()->GetPlayer();
//        if (!player->IsSpectator())
//        {
//            handler->PSendSysMessage("You are not spectator.");
//            handler->SetSentErrorMessage(true);
//            return false;
//        }
//
//        if (!player->GetBattleground())
//        {
//            handler->PSendSysMessage("You are not spectator.");
//            handler->SetSentErrorMessage(true);
//            return false;
//        }
//
//        //player->GetBattleground()->RemoveSpectator(player);
//        //player->CancelSpectate();
//        player->TeleportToBGEntryPoint();
//
//        return true;
//    }
//
//    static bool HandleSpectateFromCommand(ChatHandler* handler, const char* args)
//    {
//        Player* target;
//        ObjectGuid target_guid;
//        std::string target_name;
//        if (!handler->extractPlayerTarget((char*)args, &target, &target_guid, &target_name))
//            return false;
//
//        auto player = handler->GetSession()->GetPlayer();
//        if (!target || target->isGameMaster())
//        {
//            handler->PSendSysMessage("Cant find player.");
//            handler->SetSentErrorMessage(true);
//            return false;
//        }
//
//        if (!player->IsSpectator())
//        {
//            //handler->PSendSysMessage(LANG_SPECTATOR_NOT_SPECTATOR);
//            handler->SetSentErrorMessage(true);
//            return false;
//        }
//
//        if (target->IsSpectator() && target != player)
//        {
//            handler->PSendSysMessage("Can`t do that. Your target is spectator.");
//            handler->SetSentErrorMessage(true);
//            return false;
//        }
//
//        if (player->GetMap() != target->GetMap())
//        {
//            handler->PSendSysMessage("Cant do that. Different arenas?");
//            handler->SetSentErrorMessage(true);
//            return false;
//        }
//
//        auto bGround = target->GetBattleground();
//        if (!bGround)
//            return false;
//
//        if (target->HasAura(32728) || target->HasAura(32727))
//        {
//            //handler->PSendSysMessage(LANG_SPECTATOR_BG_NOT_STARTED);
//            handler->SetSentErrorMessage(true);
//            return false;
//        }
//
//        if (target->HasAuraType(SPELL_AURA_MOD_STEALTH) || target->HasAuraType(SPELL_AURA_MOD_INVISIBILITY))
//        {
//            //handler->PSendSysMessage(LANG_SPECTATOR_CANNT_SEE);
//            handler->SetSentErrorMessage(true);
//            return false;
//        }
//
//        target == player && player->GetSpectateFrom() ? player->SetViewpoint(player->GetSpectateFrom(), false) : player->SetViewpoint(target, true);
//        return true;
//    }
//
//    static bool HandleSpectateResetCommand(ChatHandler* handler, const char* /*args*/)
//    {
//        auto player = handler->GetSession()->GetPlayer();
//        if (!player)
//        {
//            handler->PSendSysMessage("Cant find player.");
//            handler->SetSentErrorMessage(true);
//            return false;
//        }
//
//        if (!player->IsSpectator())
//        {
//            //handler->PSendSysMessage(LANG_SPECTATOR_NOT_SPECTATOR);
//            handler->SetSentErrorMessage(true);
//            return false;
//        }
//
//        auto bGround = player->GetBattleground();
//        if (!bGround)
//            return false;
//
//        if (bGround->GetStatus() != STATUS_IN_PROGRESS)
//            return true;
//
//        for (auto itr : bGround->GetBattlegroundScoreMap())
//            if (auto tmpPlayer = ObjectAccessor::FindPlayer(itr.first))
//            {
//                auto tmpID = bGround->GetPlayerTeam(tmpPlayer->GetGUID());
//                auto pGuid = tmpPlayer->GetGUID();
//                auto pName = tmpPlayer->GetName();
//                ObjectGuid tGuid;
//
//                if (auto target = tmpPlayer->GetSelectedPlayer())
//                    tGuid = target->GetGUID();
//
//                SpectatorAddonMsg msg;
//                msg.SetPlayer(pGuid);
//                msg.SetName(pName);
//                if (tGuid)
//                    msg.SetTarget(tGuid);
//                if (Pet* pPet = tmpPlayer->GetPet())
//                {
//                    msg.SetPet(pPet->GetCreatureTemplate()->Family);
//                    msg.SetPetHP(pPet->GetHealthPct());
//                }
//                else
//                {
//                    msg.SetPet(0);
//                    msg.SetPetHP(0);
//                }
//                msg.SetStatus(tmpPlayer->isAlive());
//                msg.SetClass(tmpPlayer->getClass());
//                msg.SetCurrentHP(tmpPlayer->GetHealth());
//                msg.SetMaxHP(tmpPlayer->GetMaxHealth());
//                auto powerType = tmpPlayer->getPowerType();
//                msg.SetMaxPower(tmpPlayer->GetMaxPower(powerType));
//                msg.SetCurrentPower(tmpPlayer->GetPower(powerType));
//                msg.SetPowerType(powerType);
//                msg.SetTeam(tmpID);
//                msg.SetEndTime(int32(time(nullptr) + std::chrono::duration_cast<Seconds>(Minutes(25) - bGround->GetElapsedTime()).count()));
//                msg.SendPacket(player->GetGUID());
//            }
//
//        return true;
//    }
//
//    ChatCommand* GetCommands() const override
//    {
//        static ChatCommand spectateCommandTable[] =
//        {
//            { "player", SEC_PLAYER, true, &HandleSpectateCommand, "", nullptr },
//            { "view", SEC_PLAYER, true, &HandleSpectateFromCommand, "", nullptr },
//            { "reset", SEC_PLAYER, true, &HandleSpectateResetCommand, "", nullptr },
//            { "leave", SEC_PLAYER, true, &HandleSpectateCancelCommand, "", nullptr },
//            { nullptr, SEC_PLAYER, false, nullptr, "", nullptr }
//        };
//
//        static ChatCommand commandTable[] =
//        {
//            { "spectate", SEC_PLAYER, false, nullptr, "", spectateCommandTable },
//            { nullptr, SEC_PLAYER, false, nullptr, "", nullptr }
//        };
//        return commandTable;
//    }
//};
//
//
//enum NpcSpectatorAtions
//{
//    NPC_SPECTATOR_REFRESH_LOW = 1,
//    NPC_SPECTATOR_REFRESH_HIGH = 2,
//    NPC_SPECTATOR_REFRESH_RBG = 3,
//    NPC_SPECTATOR_ACTION_LIST_ARENA = 1000,
//    NPC_SPECTATOR_ACTION_LIST_RATED_BG = 2000,
//    NPC_SPECTATOR_ACTION_LIST_LOW_GAMES = 3000,
//    NPC_SPECTATOR_ACTION_LIST_TOP_GAMES = 4000,
//    NPC_SPECTATOR_ACTION_SELECTED_PLAYER = 5000
//};
//
//static uint16 const TopGamesRating = 1800;
//static uint8 const GamesOnPage = 20;
//
//class npc_arena_spectator : public CreatureScript
//{
//public:
//    npc_arena_spectator() : CreatureScript("npc_arena_spectator") { }
//
//    bool OnGossipHello(Player* player, Creature* creature) override
//    {
//        if (player->InBattlegroundQueue())
//        {
//            creature->MonsterWhisper("You should leave the queue!", player->GetGUID(), true);
//            return false;
//        }
//
//        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Arena", GOSSIP_SENDER_MAIN, NPC_SPECTATOR_ACTION_LIST_ARENA);
//        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Rated Battleground", GOSSIP_SENDER_MAIN, NPC_SPECTATOR_ACTION_LIST_RATED_BG);
//        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
//        return true;
//    }
//
//    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
//    {
//        player->PlayerTalkClass->ClearMenus();
//
//        if (action == NPC_SPECTATOR_ACTION_LIST_ARENA)
//        {
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "View games with high rating...", GOSSIP_SENDER_MAIN, NPC_SPECTATOR_ACTION_LIST_TOP_GAMES);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "View games with low rating...", GOSSIP_SENDER_MAIN, NPC_SPECTATOR_ACTION_LIST_LOW_GAMES);
//            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
//        }
//        else if (action == NPC_SPECTATOR_REFRESH_RBG || action == NPC_SPECTATOR_ACTION_LIST_RATED_BG)
//        {
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Refresh", GOSSIP_SENDER_MAIN, NPC_SPECTATOR_REFRESH_RBG);
//            ShowRBGPage(player, action == NPC_SPECTATOR_REFRESH_RBG ? 0 : action - NPC_SPECTATOR_ACTION_LIST_RATED_BG);
//            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
//        }
//        else if (action == NPC_SPECTATOR_REFRESH_LOW || action >= NPC_SPECTATOR_ACTION_LIST_LOW_GAMES && action < NPC_SPECTATOR_ACTION_LIST_TOP_GAMES)
//        {
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Refresh", GOSSIP_SENDER_MAIN, NPC_SPECTATOR_REFRESH_LOW);
//            ShowPage(player, action == NPC_SPECTATOR_REFRESH_LOW ? 0 : action - NPC_SPECTATOR_ACTION_LIST_LOW_GAMES, false);
//            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
//        }
//        else if (action == NPC_SPECTATOR_REFRESH_HIGH || action >= NPC_SPECTATOR_ACTION_LIST_TOP_GAMES && action < NPC_SPECTATOR_ACTION_SELECTED_PLAYER)
//        {
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Refresh", GOSSIP_SENDER_MAIN, NPC_SPECTATOR_REFRESH_HIGH);
//            ShowPage(player, action == NPC_SPECTATOR_REFRESH_HIGH ? 0 : action - NPC_SPECTATOR_ACTION_LIST_TOP_GAMES, true);
//            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
//        }
//        else
//        {
//            ChatHandler handler(player);
//            arena_spectator_commands::SpectateByGuid(&handler, ObjectGuid::Create<HighGuid::Player>(action - NPC_SPECTATOR_ACTION_SELECTED_PLAYER));
//        }
//        return true;
//    }
//
//    std::string GetGamesStringData(Battleground* bg, uint16 team)
//    {
//        std::string teamsMember[MAX_TEAMS];
//        uint16 firstTeamMMR = 0;
//        uint16 secondTeamMMR = 0;
//
//        for (auto itr = bg->GetPlayers().begin(); itr != bg->GetPlayers().end(); ++itr)
//        {
//            if (auto player = ObjectAccessor::FindPlayer(itr->first))
//            {
//                if (player->IsSpectator())
//                    continue;
//
//                uint8 bracketType = MS::Battlegrounds::GetBracketByJoinType(bg->GetJoinType());
//
//                auto* grp = player->GetGroup();
//                if (!grp || grp->GetLeaderGUID() != player->GetGUID())
//                    continue;
//
//                if (player->GetBGTeam() == team)
//                    firstTeamMMR = grp->GetAverageMMR(bracketType);
//                else
//                    secondTeamMMR = grp->GetAverageMMR(bracketType);
//
//                teamsMember[team != player->GetBGTeam()] += GetSpecClassNameById(player->getClass(), player->GetSpecializationId());
//            }
//        }
//
//        std::stringstream data;
//        data << teamsMember[0] << "[" << firstTeamMMR << "] - " << teamsMember[1] << "[" << secondTeamMMR << "]";
//        return data.str();
//    }
//
//    Player* GetFirstPlayer(Battleground* arena)
//    {
//        for (auto itr = arena->GetPlayers().begin(); itr != arena->GetPlayers().end(); ++itr)
//            if (auto player = ObjectAccessor::FindPlayer(itr->first))
//                return player;
//
//        return nullptr;
//    }
//
//    void ShowPage(Player* gPlayer, uint16 page, bool isTop)
//    {
//        uint16 highGames = 0;
//        uint16 lowGames = 0;
//        bool haveNextPage = false;
//
//        auto sdataStore = sBattlegroundMgr->GetSpectatorData();
//        for (auto& kv : sdataStore)
//        {
//            std::string data;
//            uint8 PtLeaderCount = 0;
//            uint8 type = 2;
//            uint16 team = 0;
//            uint32 lowGuid = 0;
//            Battleground* bg = nullptr;
//
//            for (std::list<ObjectGuid>::const_iterator itr = kv.second.begin(); itr != kv.second.end(); ++itr)
//            {
//                ObjectGuid guid = *itr;
//                auto player = ObjectAccessor::FindPlayer(guid);
//                if (!player)
//                    continue;
//
//                if (!bg)
//                    bg = player->GetBattleground();
//
//                if (!bg || !bg->IsArena() || !bg->IsRated())
//                    continue;
//
//                auto bracket = player->getBracket(MS::Battlegrounds::GetBracketByJoinType(bg->GetJoinType()));
//                if (!bracket)
//                    continue;
//
//                if (bracket->getMMV() > TopGamesRating)
//                    type = 1;
//
//                team = player->GetBGTeam();
//                lowGuid = guid.GetGUIDLow();
//                PtLeaderCount++;
//            }
//
//            if (PtLeaderCount != 2)
//                continue;
//
//            data += GetGamesStringData(bg, team);
//
//            if (isTop && type == 1/*'H'*/)
//            {
//                highGames++;
//                if (highGames > (page + 1) * GamesOnPage)
//                {
//                    haveNextPage = true;
//                    break;
//                }
//
//                if (highGames >= page * GamesOnPage)
//                    gPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_BATTLE, data, GOSSIP_SENDER_MAIN, NPC_SPECTATOR_ACTION_SELECTED_PLAYER + lowGuid);
//            }
//            else if (!isTop && type == 2/*'L'*/)
//            {
//                lowGames++;
//                if (lowGames > (page + 1) * GamesOnPage)
//                {
//                    haveNextPage = true;
//                    break;
//                }
//
//                if (lowGames >= page * GamesOnPage)
//                    gPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_BATTLE, data, GOSSIP_SENDER_MAIN, NPC_SPECTATOR_ACTION_SELECTED_PLAYER + lowGuid);
//            }
//        }
//
//        if (page > 0)
//            gPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Prev...", GOSSIP_SENDER_MAIN, NPC_SPECTATOR_ACTION_LIST_LOW_GAMES + page - 1);
//
//        if (haveNextPage)
//            gPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Next...", GOSSIP_SENDER_MAIN, NPC_SPECTATOR_ACTION_LIST_LOW_GAMES + page + 1);
//    }
//
//    void ShowRBGPage(Player* gPlayer, uint16 page)
//    {
//        uint16 games = 0;
//        bool haveNextPage = false;
//
//        auto sdataStore = sBattlegroundMgr->GetSpectatorData();
//        for (auto& kv : sdataStore)
//        {
//            std::string data;
//            uint8 PtLeaderCount = 0;
//            uint16 team = 0;
//            uint32 lowGuid = 0;
//            Battleground* bg = nullptr;
//
//            for (std::list<ObjectGuid>::const_iterator itr = kv.second.begin(); itr != kv.second.end(); ++itr)
//            {
//                ObjectGuid guid = *itr;
//                auto player = ObjectAccessor::FindPlayer(guid);
//                if (!player)
//                    continue;
//
//                if (!bg)
//                    bg = player->GetBattleground();
//
//                if (!bg || !bg->IsRBG())
//                    continue;
//
//                auto bracket = player->getBracket(MS::Battlegrounds::GetBracketByJoinType(bg->GetJoinType()));
//                if (!bracket)
//                    continue;
//
//                team = player->GetBGTeam();
//                lowGuid = guid.GetGUIDLow();
//                PtLeaderCount++;
//            }
//
//            if (PtLeaderCount != 2)
//                continue;
//
//            data += GetGamesStringData(bg, team);
//
//            games++;
//            if (games > (page + 1) * GamesOnPage)
//            {
//                haveNextPage = true;
//                break;
//            }
//
//            if (games >= page * GamesOnPage)
//                gPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_BATTLE, data, GOSSIP_SENDER_MAIN, NPC_SPECTATOR_ACTION_SELECTED_PLAYER + lowGuid);
//        }
//
//        if (page > 0)
//            gPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Prev...", GOSSIP_SENDER_MAIN, NPC_SPECTATOR_ACTION_LIST_RATED_BG + page - 1);
//
//        if (haveNextPage)
//            gPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Next...", GOSSIP_SENDER_MAIN, NPC_SPECTATOR_ACTION_LIST_RATED_BG + page + 1);
//    }
//
//    std::string GetSpecClassNameById(uint8 Id, uint32 Spec)
//    {
//        std::string sClass = "";
//        switch (Id)
//        {
//        case CLASS_WARRIOR:
//            switch (Spec)
//            {
//            case SPEC_WARRIOR_ARMS:
//                sClass = "AWarrior ";
//                break;
//            case SPEC_WARRIOR_FURY:
//                sClass = "FWarrior ";
//                break;
//            case SPEC_WARRIOR_PROTECTION:
//                sClass = "PWarrior ";
//                break;
//            }
//            break;
//        case CLASS_PALADIN:
//            switch (Spec)
//            {
//            case SPEC_PALADIN_HOLY:
//                sClass = "HPala ";
//                break;
//            case SPEC_PALADIN_PROTECTION:
//                sClass = "PPala ";
//                break;
//            case SPEC_PALADIN_RETRIBUTION:
//                sClass = "RPala ";
//                break;
//            }
//            break;
//        case CLASS_HUNTER:
//            switch (Spec)
//            {
//            case SPEC_HUNTER_BEASTMASTER:
//                sClass = "BHunt ";
//                break;
//            case SPEC_HUNTER_MARKSMAN:
//                sClass = "MHunt ";
//                break;
//            case SPEC_HUNTER_SURVIVAL:
//                sClass = "SHunt ";
//                break;
//            }
//            break;
//        case CLASS_ROGUE:
//            switch (Spec)
//            {
//            case SPEC_ROGUE_ASSASSINATION:
//                sClass = "ARogue ";
//                break;
//            case SPEC_ROGUE_COMBAT:
//                sClass = "CRogue ";
//                break;
//            case SPEC_ROGUE_SUBTLETY:
//                sClass = "SRogue ";
//                break;
//            }
//            break;
//        case CLASS_PRIEST:
//            switch (Spec)
//            {
//            case SPEC_PRIEST_DISCIPLINE:
//                sClass = "DPriest ";
//                break;
//            case SPEC_PRIEST_HOLY:
//                sClass = "HPriest ";
//                break;
//            case SPEC_PRIEST_SHADOW:
//                sClass = "SPriest ";
//                break;
//            }
//            break;
//        case CLASS_DEATH_KNIGHT:
//            switch (Spec)
//            {
//            case SPEC_DK_BLOOD:
//                sClass = "BDk ";
//                break;
//            case SPEC_DK_FROST:
//                sClass = "FDk ";
//                break;
//            case SPEC_DK_UNHOLY:
//                sClass = "UDk ";
//                break;
//            }
//            break;
//        case CLASS_SHAMAN:
//            switch (Spec)
//            {
//            case SPEC_SHAMAN_ELEMENTAL:
//                sClass = "ELShaman ";
//                break;
//            case SPEC_SHAMAN_ENHANCEMENT:
//                sClass = "ENShaman ";
//                break;
//            case SPEC_SHAMAN_RESTORATION:
//                sClass = "RShaman ";
//                break;
//            }
//            break;
//        case CLASS_MAGE:
//            switch (Spec)
//            {
//            case SPEC_MAGE_ARCANE:
//                sClass = "AMage ";
//                break;
//            case SPEC_MAGE_FIRE:
//                sClass = "FIMage ";
//                break;
//            case SPEC_MAGE_FROST:
//                sClass = "FRMage ";
//                break;
//            }
//            break;
//        case CLASS_WARLOCK:
//            switch (Spec)
//            {
//            case SPEC_WARLOCK_AFFLICTION:
//                sClass = "ALock ";
//                break;
//            case SPEC_WARLOCK_DEMONOLOGY:
//                sClass = "DemoLock ";
//                break;
//            case SPEC_WARLOCK_DESTRUCTION:
//                sClass = "DestLock ";
//                break;
//            }
//            break;
//        case CLASS_DRUID:
//            switch (Spec)
//            {
//            case SPEC_DRUID_BALANCE:
//                sClass = "BDruid ";
//                break;
//            case SPEC_DRUID_CAT:
//                sClass = "FDruid ";
//                break;
//            case SPEC_DRUID_BEAR:
//                sClass = "FDruid ";
//                break;
//            case SPEC_DRUID_RESTORATION:
//                sClass = "RDruid ";
//                break;
//            }
//            break;
//        case CLASS_MONK:
//            switch (Spec)
//            {
//            case SPEC_MONK_BREWMASTER:
//                sClass = "BmMonk ";
//                break;
//            case SPEC_MONK_WINDWALKER:
//                sClass = "WwMonk ";
//                break;
//            case SPEC_MONK_MISTWEAVER:
//                sClass = "MwMonk ";
//                break;
//            }
//            break;
//        case CLASS_DEMON_HUNTER:
//            switch (Spec)
//            {
//            case SPEC_DEMON_HUNER_HAVOC:
//                sClass = "HavocDH ";
//                break;
//            case SPEC_DEMON_HUNER_VENGEANCE:
//                sClass = "VengDH ";
//                break;
//            }
//            break;
//        }
//        return sClass;
//    }
//};
//
//void AddSC_arena_spectator_script()
//{
//    new arena_spectator_commands();
//    new npc_arena_spectator();
//}
