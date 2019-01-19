#include "TeleporterStoneMgr.hpp"

///Database
#include "DatabaseEnv.h" ///< For queryresult and worlddatabase

///Game
#include "GossipDef.h"
#include "Item.h"
#include "Player.h"
#include "ScriptedGossip.h"
#include "ScriptMgr.h"
#include "WorldSession.h"

void TeleporterStoneMgr::LoadFromDatabase(bool p_Reload /*= false*/)
{
    if (p_Reload)
             ;
    if (QueryResult l_Result = WorldDatabase.Query("SELECT ID, Text, ConfirmText, RefID, HardCodedID, RequiredVIPLevel, RequiredMG, MapID, X, Y, Z, O, LinkedIDS FROM z_teleporter_stone"))
    {
        do
        {
            Field* l_Fields = l_Result->Fetch();

            uint32 l_Index = 0;

            int32 l_ID = l_Fields[++l_Index].GetInt32(); ///< Negative ID = mainmenu!

            TeleporterStoneTable l_Table;

            l_Table.Text                = l_Fields[++l_Index].GetString();
            l_Table.ConfirmText         = l_Fields[++l_Index].GetString();
            l_Table.RefID               = l_Fields[++l_Index].GetInt32();
            l_Table.HardCodedID         = l_Fields[++l_Index].GetUInt32();
            l_Table.RequiredVIPLevel    = l_Fields[++l_Index].GetUInt32();
            l_Table.RequiredMG          = l_Fields[++l_Index].GetUInt32();
            l_Table.MapID               = l_Fields[++l_Index].GetUInt32();
            l_Table.X                   = l_Fields[++l_Index].GetFloat();
            l_Table.Y                   = l_Fields[++l_Index].GetFloat();
            l_Table.Z                   = l_Fields[++l_Index].GetFloat();
            l_Table.O                   = l_Fields[++l_Index].GetFloat();

            Tokenizer l_Tokens(l_Fields[++l_Index].GetString(), ' ');

            for (auto const& l_Parse : l_Tokens)
            {
                int32 l_Linked = atol(l_Parse);

                l_Table.IncludeIds.emplace_back(l_Linked);
            }

            m_TeleporterStoneData[l_ID] = l_Table;

        } while (l_Result->NextRow());
    }
}

TeleporterStoneTable const* TeleporterStoneMgr::GetDataForId(uint32 p_ID)
{
    if (m_TeleporterStoneData.find(p_ID) == m_TeleporterStoneData.end())
        return nullptr;

    return &m_TeleporterStoneData[p_ID];
}

class teleporter_stone_worldscript : public WorldScript
{
public:
    teleporter_stone_worldscript() : WorldScript("teleporter_stone_worldscript") { }

    void OnStartup()
    {
        sTeleporterStoneMgr->LoadFromDatabase();
    }
};

enum eSenders
{
    SenderTeleport = 1,
    SenderMenu     = 2,

    ///CUSTOM HARDCODED
    SenderHardcodedCheckerMenu,
};

class item_teleporter_stone_db : public ItemScript
{
public:
    item_teleporter_stone_db() : ItemScript("item_teleporter_stone_db") { }

    ///! TODO MOVE THIS DOWN TO PRIVATE
    uint32 _GetSenderFromTableData(TeleporterStoneTable const* p_Table)
    {
        if (p_Table->HardCodedID)
            return p_Table->HardCodedID;

        if (p_Table->X != 0.0f || p_Table->Y != 0.0f || p_Table->Z != 0.0f || p_Table->O != 0.0f)
            return SenderTeleport;

        return SenderMenu;
    }

    uint32 _GetActionFromSigned(int32 p_ID)
    {
        if (p_ID >= 0)
            return p_ID;

        p_ID *= -1;
        p_ID += 1000000;

        return p_ID;
    }

    bool OnUse(Player* p_Player, Item* p_Item, SpellCastTargets const& /*p_Targets*/) override
    {
        for (auto const& l_Data : sTeleporterStoneMgr->GetAllData())
        {
            auto const& l_Table = l_Data.second;

            if (l_Data.first >= 0) ///< less than 0 id is going to be main menu
                continue;

            std::string const& l_ConfirmText = l_Table.ConfirmText;

            if (l_ConfirmText.empty())
                AddGossipItemFor(p_Player, l_Table.GossipMenuIcon, l_Table.Text, _GetSenderFromTableData(&l_Table), _GetActionFromSigned(l_Data.first));
            else
                AddGossipItemFor(p_Player, l_Table.GossipMenuIcon, l_Table.Text, _GetSenderFromTableData(&l_Table), _GetActionFromSigned(l_Data.first), l_ConfirmText, 0, false);
        }

        SendGossipMenuFor(p_Player, p_Item->GetEntry(), p_Item->GetGUID());

        return true;
    }

    void OnGossipSelect(Player* p_Player, Item* p_Item, uint32 p_Sender, uint32 p_Action)
    {
        ClearGossipMenuFor(p_Player);

        switch (p_Sender)
        {
            case SenderTeleport:

                if (TeleporterStoneTable const* l_TeleportStone = sTeleporterStoneMgr->GetDataForId(p_Action))
                {
                    uint32 const& l_RequiredMG = l_TeleportStone->RequiredMG;

                    if (l_RequiredMG && p_Player->GetCustomCurrency(CustomCurrency::MG) < l_RequiredMG)
                    {
                        p_Player->GetSession()->SendAreaTriggerMessage("You don't have the required amount of MG to teleport here!");
                        return;
                    }

                    if (l_RequiredMG)
                        p_Player->RemoveCustomCurrency(CustomCurrency::MG, l_RequiredMG, true);

                    if(uint32 const& l_RequiredVIPLevel = l_TeleportStone->RequiredVIPLevel)
                        if (p_Player->GetSession()->GetVIPLevel() < l_RequiredVIPLevel)
                        {
                            p_Player->GetSession()->SendAreaTriggerMessage("You need vip to teleport here");
                            return;
                        }

                    p_Player->TeleportTo(l_TeleportStone->MapID, l_TeleportStone->X, l_TeleportStone->Y, l_TeleportStone->Z, l_TeleportStone->O);
                }
                else
                    CloseGossipMenuFor(p_Player);

                break;

            case SenderMenu:

                if (TeleporterStoneTable const* l_TeleportStone = sTeleporterStoneMgr->GetDataForId(p_Action))
                {
                    for (uint32 const& l_Link : l_TeleportStone->IncludeIds)
                    {
                        if (TeleporterStoneTable const* l_LinkedTable = sTeleporterStoneMgr->GetDataForId(l_Link))
                        {
                            std::string const& l_ConfirmText = l_LinkedTable->ConfirmText;

                            if (l_ConfirmText.empty())
                                AddGossipItemFor(p_Player, l_LinkedTable->GossipMenuIcon, l_LinkedTable->Text, _GetSenderFromTableData(l_LinkedTable), _GetActionFromSigned(l_Link));
                            else
                                AddGossipItemFor(p_Player, l_LinkedTable->GossipMenuIcon, l_LinkedTable->Text, _GetSenderFromTableData(l_LinkedTable), _GetActionFromSigned(l_Link), l_ConfirmText, 0, false);
                        }
                    }

                    SendGossipMenuFor(p_Player, p_Item->GetEntry(), p_Item->GetGUID());
                }
                else
                    CloseGossipMenuFor(p_Player);

                break;
        }
    }
};

void AddSC_teleporter_stone()
{
    new teleporter_stone_worldscript();
    new item_teleporter_stone_db();
}
