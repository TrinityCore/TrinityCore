/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

/* ScriptData
Name: Transmogrification
By Rochet2
Remake By Saqirmdev
%Complete: 100
Comment: Script allow spectate arena games
Category: Custom Script
EndScriptData */

#ifndef DEF_TRANSMOGRIFICATION_H
#define DEF_TRANSMOGRIFICATION_H

#include "Config.h"

enum TransmogTrinityStrings
{
    LANG_REM_TRANSMOGRIFICATIONS_ITEMS  = 11100,
    LANG_ERR_NO_TRANSMOGRIFICATIONS     = 11101,
    LANG_REM_TRANSMOGRIFICATION_ITEM    = 11102,
    LANG_ERR_NO_TRANSMOGRIFICATION      = 11103,
    LANG_ITEM_TRANSMOGRIFIED            = 11104,
    LANG_ERR_NO_ITEM_SUITABLE           = 11105,
    LANG_ERR_NO_ITEM_EXISTS             = 11106,
    LANG_ERR_EQUIP_SLOT_EMPTY           = 11107,

    LANG_SLOT_NAME_HEAD                 = 11108,
    LANG_SLOT_NAME_SHOULDERS            = 11109,
    LANG_SLOT_NAME_BODY                 = 11110,
    LANG_SLOT_NAME_CHEST                = 11111,
    LANG_SLOT_NAME_WAIST                = 11112,
    LANG_SLOT_NAME_LEGS                 = 11113,
    LANG_SLOT_NAME_FEET                 = 11114,
    LANG_SLOT_NAME_WRISTS               = 11115,
    LANG_SLOT_NAME_HANDS                = 11116,
    LANG_SLOT_NAME_BACK                 = 11117,
    LANG_SLOT_NAME_MAINHAND             = 11118,
    LANG_SLOT_NAME_OFFHAND              = 11119,
    LANG_SLOT_NAME_RANGED               = 11120,
    LANG_SLOT_NAME_TABARD               = 11121,

    LANG_OPTION_BACK                    = 11122,
    LANG_OPTION_REMOVE_ALL              = 11123,
    LANG_POPUP_REMOVE_ALL               = 11124,
    LANG_OPTION_UPDATE_MENU             = 11125,
    LANG_OPTION_REMOVE_ONE              = 11126,
    LANG_POPUP_REMOVE_ONE               = 11127,
    LANG_POPUP_TRANSMOGRIFY             = 11128,

    LANG_ERR_NO_TOKEN                   = 11129
};

enum TransmogrificationResult // custom
{
    ERR_FAKE_NEW_BAD_QUALITY,
    ERR_FAKE_OLD_BAD_QUALITY,
    ERR_FAKE_SAME_DISPLAY,
    ERR_FAKE_SAME_DISPLAY_FAKE,
    ERR_FAKE_CANT_USE,
    ERR_FAKE_NOT_SAME_CLASS,
    ERR_FAKE_BAD_CLASS,
    ERR_FAKE_BAD_SUBLCASS,
    ERR_FAKE_BAD_INVENTORYTYPE,
    ERR_FAKE_OK
};

class Transmogrification
{
public:
    Transmogrification() { };
    ~Transmogrification() { };

    uint32 GetRequireGold() { return RequireGold; }
    float GetGoldModifier() { return GoldModifier; }
    uint32 GetGoldCost() { return GoldCost; }

    bool GetRequireToken() { return RequireToken; }
    uint32 GetTokenEntry() { return TokenEntry; }
    uint32 GetTokenAmount() { return TokenAmount; }

    static uint32 GetFakeEntry(Item* item);
    static void DeleteFakeFromDB(uint32 lowGUID);
    static bool DeleteFakeEntry(Item* item);
    static void SetFakeEntry(Item* item, uint32 entry);
    static uint32 SuitableForTransmogrification(Player* player, Item* oldItem, Item* newItem);

    bool AllowedQuality(uint32 quality) // Only thing used elsewhere (Player.cpp)
    {
        switch(quality)
        {
        case ITEM_QUALITY_POOR: return AllowPoor;
        case ITEM_QUALITY_NORMAL: return AllowCommon;
        case ITEM_QUALITY_UNCOMMON: return AllowUncommon;
        case ITEM_QUALITY_RARE: return AllowRare;
        case ITEM_QUALITY_EPIC: return AllowEpic;
        case ITEM_QUALITY_LEGENDARY: return AllowLegendary;
        case ITEM_QUALITY_ARTIFACT: return AllowArtifact;
        case ITEM_QUALITY_HEIRLOOM: return AllowHeirloom;
        default: return false;
        }
    }

    void LoadConfig()
    {
        RequireGold = (uint32)ConfigMgr::GetIntDefault("Transmogrification.RequireGold", 1);
        GoldModifier = ConfigMgr::GetFloatDefault("Transmogrification.GoldModifier", 1.0f);
        GoldCost = (uint32)ConfigMgr::GetIntDefault("Transmogrification.GoldCost", 100000);

        RequireToken = ConfigMgr::GetBoolDefault("Transmogrification.RequireToken", false);
        TokenEntry = (uint32)ConfigMgr::GetIntDefault("Transmogrification.TokenEntry", 49426);
        TokenAmount = (uint32)ConfigMgr::GetIntDefault("Transmogrification.TokenAmount", 1);

        AllowPoor = ConfigMgr::GetBoolDefault("Transmogrification.AllowPoor", false);
        AllowCommon = ConfigMgr::GetBoolDefault("Transmogrification.AllowCommon", false);
        AllowUncommon = ConfigMgr::GetBoolDefault("Transmogrification.AllowUncommon", true);
        AllowRare = ConfigMgr::GetBoolDefault("Transmogrification.AllowRare", true);
        AllowEpic = ConfigMgr::GetBoolDefault("Transmogrification.AllowEpic", true);
        AllowLegendary = ConfigMgr::GetBoolDefault("Transmogrification.AllowLegendary", false);
        AllowArtifact = ConfigMgr::GetBoolDefault("Transmogrification.AllowArtifact", false);
        AllowHeirloom = ConfigMgr::GetBoolDefault("Transmogrification.AllowHeirloom", true);

        if(!sObjectMgr->GetItemTemplate(TokenEntry))
        {
            sLog->outError(LOG_FILTER_SERVER_LOADING, "Transmogrification.TokenEntry (%u) does not exist. Using default.", TokenEntry);
            TokenEntry = 49426;
        }
    }

private:

    uint32 RequireGold;
    float GoldModifier;
    uint32 GoldCost;

    bool RequireToken;
    uint32 TokenEntry;
    uint32 TokenAmount;

    bool AllowPoor;
    bool AllowCommon;
    bool AllowUncommon;
    bool AllowRare;
    bool AllowEpic;
    bool AllowLegendary;
    bool AllowArtifact;
    bool AllowHeirloom;
};
#define sTransmogrification ACE_Singleton<Transmogrification, ACE_Null_Mutex>::instance()

#endif