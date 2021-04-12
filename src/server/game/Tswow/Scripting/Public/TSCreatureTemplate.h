/*
 * This file is part of tswow (https://github.com/tswow/).
 * Copyright (C) 2020 tswow <https://github.com/tswow/>
 * 
 * This program is free software: you can redistribute it and/or 
 * modify it under the terms of the GNU General Public License as 
 * published by the Free Software Foundation, version 3.
 * 
 * This program is distributed in the hope that it will be useful, 
 * but WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License 
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */
#pragma once

#include "TSBase.h"
#include "TSMain.h"
#include "TSStorage.h"
#include "TSEntity.h"
#include "TSString.h"

struct CreatureTemplate;

class TC_GAME_API TSCreatureTemplate
{
public:
    CreatureTemplate * ct;
    TSCreatureTemplate(CreatureTemplate * ct);
    TSCreatureTemplate * operator->(){ return this; }

    uint32   GetEntry();
    uint32   GetDifficultyEntryA();
    uint32   GetDifficultyEntryB();
    uint32   GetDifficultyEntryC();

    uint32   GetKillCreditA();
    uint32   GetKillCreditB();
    uint32   GetModelID1();
    uint32   GetModelID2();
    uint32   GetModelID3();
    uint32   GetModelID4();
    TSString GetName();
    TSString GetTitle();
    TSString GetIconName();
    uint32   GetGossipMenuID();
    uint8    GetMinLevel();
    uint8    GetMaxLevel();
    uint32   GetExpansion();
    uint32   GetFaction();
    uint32   GetNPCFlag();
    float    GetSpeedWalk();
    float    GetSpeedRun();
    float    GetScale();
    uint32   GetRank();
    uint32   GetDamageSchool();
    uint32   GetBaseAttackTime();
    uint32   GetRangeAttackTime();
    float    GetBaseVariance();
    float    GetRangeVariance();
    uint32   GetUnitClass();                                     // enum Classes. Note only 4 classes are known for creatures.
    uint32   GetUnitFlags();                                     // enum UnitFlags mask values
    uint32   GetUnitFlags2();                                    // enum UnitFlags2 mask values
    uint32   GetDynamicFlags();
    uint32   GetFamily();                                 // enum CreatureFamily values (optional)
    uint32   GetType();                                           // enum CreatureType values
    uint32   GetTypeFlags();                                     // enum CreatureTypeFlags mask values
    uint32   GetLootID();
    uint32   GetPickpocketLootID();
    uint32   GetSkinLootID();

    int32    GetNormalResistance();
    int32    GetHolyResistance();
    int32    GetFireResistance();
    int32    GetNatureResistance();
    int32    GetFrostResistance();
    int32    GetShadowResistance();
    int32    GetArcaneResistance();

    uint32   GetSpellA();
    uint32   GetSpellB();
    uint32   GetSpellC();
    uint32   GetSpellD();
    uint32   GetSpellE();
    uint32   GetSpellF();
    uint32   GetSpellG();
    uint32   GetSpellH();
    uint32   GetPetSpellDataID();
    uint32   GetVehicleID();
    uint32   GetMinGold();
    uint32   GetMaxGold();
    TSString GetAIName();
    uint32   GetMovementType();

    float       GetHoverHeight();
    float       GetModHealth();
    float       GetModMana();
    float       GetModArmor();
    float       GetModDamage();
    float       GetModExperience();
    bool        GetRacialLeader();
    uint32      GetMovementID();
    bool        GetRegenHealth();
    uint32      GetMechanicImmuneMask();
    uint32      GetSpellSchoolImmuneMask();
    uint32      GetFlagsExtra();
    uint32      GetScriptID();
    uint32      GetRandomValidModelID() const;
    uint32      GetFirstValidModelID() const;
    uint32      GetFirstInvisibleModel() const;
    uint32      GetFirstVisibleModel() const;
    TSStorage * GetData();
    uint32      GetRequiredLootSkill() const;
    bool        GetIsExotic() const;
    bool        GetIsTameable(bool canTameExotic) const;
    TS_ENTITY_DATA_DECL(TSCreatureTemplate)

    // CreatureMovementData
    uint32    GetGroundMovement();
    uint32    GetFlightMovement();
    bool      GetSwims();
    bool      GetRooted();
    uint32    GetChaseMovement();
    uint32    GetRandomMovement();
    uint32    GetInteractionPauseTimer();
    bool      GetIsGroundAllowed();
    bool      GetIsSwimAllowed();
    bool      GetIsFlightAllowed();
    bool      GetIsRooted();
};

TC_GAME_API TSCreatureTemplate GetCreatureTemplate(uint32 entry);