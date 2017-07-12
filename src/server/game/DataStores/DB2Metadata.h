/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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

#ifndef DB2Metadata_h__
#define DB2Metadata_h__

#include "DB2Meta.h"

struct AchievementMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssishhhhhhbbbii";
        static uint8 const arraySizes[15] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[15] = { "", "", uint32(0), "", uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint8(0), uint8(0), uint8(0), uint32(0), uint32(0) };
        static DB2Meta instance(13, 15, 0x0A906D77, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct Achievement_CategoryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shbi";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[4] = { "", uint16(0), uint8(0), uint32(0) };
        static DB2Meta instance(3, 4, 0x1397F425, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct AdventureJournalMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sssiisshhhhhhbbbbbbbii";
        static uint8 const arraySizes[22] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[22] = { "", "", "", uint32(0), uint32(0), "", "", uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 22, 0x64712E77, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct AdventureMapPOIMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fissbiiiiiiii";
        static uint8 const arraySizes[13] = { 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[13] = { float(0), uint32(0), "", "", uint8(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 13, 0xC7FC77F3, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct AnimKitMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihh";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { uint32(0), uint16(0), uint16(0) };
        static DB2Meta instance(-1, 3, 0xE5B727EB, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct AnimKitBoneSetMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbbbb";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[5] = { "", uint8(0), uint8(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 5, 0x196B6380, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct AnimKitBoneSetAliasMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2FieldDefault const fieldDefaults[2] = { uint8(0), uint8(0) };
        static DB2Meta instance(-1, 2, 0x3D3DC96C, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct AnimKitConfigMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i";
        static uint8 const arraySizes[1] = { 1 };
        static DB2FieldDefault const fieldDefaults[1] = { uint32(0) };
        static DB2Meta instance(-1, 1, 0xA2950AAF, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct AnimKitConfigBoneSetMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { uint16(0), uint16(0), uint8(0) };
        static DB2Meta instance(-1, 3, 0x89A6756A, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct AnimKitPriorityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "b";
        static uint8 const arraySizes[1] = { 1 };
        static DB2FieldDefault const fieldDefaults[1] = { uint8(0) };
        static DB2Meta instance(-1, 1, 0x466FA3A4, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct AnimKitReplacementMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhhhi";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[5] = { uint16(0), uint16(0), uint16(0), uint16(0), uint32(0) };
        static DB2Meta instance(4, 5, 0xEEB10890, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct AnimKitSegmentMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiifihhhbbbbbbbi";
        static uint8 const arraySizes[16] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[16] = { uint32(0), uint32(0), uint32(0), float(0), uint32(0), uint16(0), uint16(0), uint16(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint32(0) };
        static DB2Meta instance(-1, 16, 0xE66FE1D5, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct AnimReplacementMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhhhi";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[5] = { uint16(0), uint16(0), uint16(0), uint16(0), uint32(0) };
        static DB2Meta instance(4, 5, 0x6BC90470, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct AnimReplacementSetMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "b";
        static uint8 const arraySizes[1] = { 1 };
        static DB2FieldDefault const fieldDefaults[1] = { uint8(0) };
        static DB2Meta instance(-1, 1, 0xD9FFC559, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct AnimationDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "isihhb";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[6] = { uint32(0), "", uint32(0), uint16(0), uint16(0), uint8(0) };
        static DB2Meta instance(0, 6, 0x13EB0DAC, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct AreaFarClipOverrideMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iffii";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[5] = { uint32(0), float(0), float(0), uint32(0), uint32(0) };
        static DB2Meta instance(4, 5, 0xF620496F, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct AreaGroupMemberMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hh";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2FieldDefault const fieldDefaults[2] = { uint16(0), uint16(0) };
        static DB2Meta instance(-1, 2, 0xE3DC15B6, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct AreaPOIMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ifssiihhhhbbii";
        static uint8 const arraySizes[14] = { 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[14] = { uint32(0), float(0), "", "", uint32(0), uint32(0), uint16(0), uint16(0), uint16(0), uint16(0), uint8(0), uint8(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 14, 0x7FE46F20, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct AreaPOIStateMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shbbi";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[5] = { "", uint16(0), uint8(0), uint8(0), uint32(0) };
        static DB2Meta instance(-1, 5, 0x26B07659, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct AreaTableMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "isfshhhhhhhhhhbbbbbbbbi";
        static uint8 const arraySizes[23] = { 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[23] = { uint32(0), "", float(0), "", uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint32(0) };
        static DB2Meta instance(-1, 23, 0x1A7A0860, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct AreaTriggerMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffffffhhhhhbbbi";
        static uint8 const arraySizes[15] = { 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[15] = { float(0), float(0), float(0), float(0), float(0), float(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint8(0), uint8(0), uint8(0), uint32(0) };
        static DB2Meta instance(14, 15, 0x1C34D111, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct AreaTriggerActionSetMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "h";
        static uint8 const arraySizes[1] = { 1 };
        static DB2FieldDefault const fieldDefaults[1] = { uint16(0) };
        static DB2Meta instance(-1, 1, 0x0043219C, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct AreaTriggerBoxMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "f";
        static uint8 const arraySizes[1] = { 3 };
        static DB2FieldDefault const fieldDefaults[1] = { float(0) };
        static DB2Meta instance(-1, 1, 0x78511B09, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct AreaTriggerCylinderMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fff";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { float(0), float(0), float(0) };
        static DB2Meta instance(-1, 3, 0xF9DDE5CE, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct AreaTriggerSphereMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "f";
        static uint8 const arraySizes[1] = { 1 };
        static DB2FieldDefault const fieldDefaults[1] = { float(0) };
        static DB2Meta instance(-1, 1, 0x188D1990, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ArmorLocationMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fffff";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[5] = { float(0), float(0), float(0), float(0), float(0) };
        static DB2Meta instance(-1, 5, 0xFD8EBF3D, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ArtifactMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "siiihhbbii";
        static uint8 const arraySizes[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[10] = { "", uint32(0), uint32(0), uint32(0), uint16(0), uint16(0), uint8(0), uint8(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 10, 0xE59CACA4, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ArtifactAppearanceMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "siffihhbbbbiiii";
        static uint8 const arraySizes[15] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[15] = { "", uint32(0), float(0), float(0), uint32(0), uint16(0), uint16(0), uint8(0), uint8(0), uint8(0), uint8(0), uint32(0), uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(11, 15, 0x97AC249A, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ArtifactAppearanceSetMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sshhbbbbi";
        static uint8 const arraySizes[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[9] = { "", "", uint16(0), uint16(0), uint8(0), uint8(0), uint8(0), uint8(0), uint32(0) };
        static DB2Meta instance(8, 9, 0xF10622F3, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ArtifactCategoryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hh";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2FieldDefault const fieldDefaults[2] = { uint16(0), uint16(0) };
        static DB2Meta instance(-1, 2, 0x8B77EABF, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ArtifactPowerMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fbbbbii";
        static uint8 const arraySizes[7] = { 2, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[7] = { float(0), uint8(0), uint8(0), uint8(0), uint8(0), uint32(0), uint32(0) };
        static DB2Meta instance(5, 7, 0x27D09323, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ArtifactPowerLinkMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hh";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2FieldDefault const fieldDefaults[2] = { uint16(0), uint16(0) };
        static DB2Meta instance(-1, 2, 0x7E5E19B4, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ArtifactPowerPickerMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i";
        static uint8 const arraySizes[1] = { 1 };
        static DB2FieldDefault const fieldDefaults[1] = { uint32(0) };
        static DB2Meta instance(-1, 1, 0xD00990E5, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ArtifactPowerRankMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ifhhb";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[5] = { uint32(0), float(0), uint16(0), uint16(0), uint8(0) };
        static DB2Meta instance(-1, 5, 0xB08EEA4D, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ArtifactQuestXPMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i";
        static uint8 const arraySizes[1] = { 10 };
        static DB2FieldDefault const fieldDefaults[1] = { uint32(0) };
        static DB2Meta instance(-1, 1, 0x9E5D9065, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ArtifactTierMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiii";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[5] = { uint32(0), uint32(0), uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 5, 0xEB558336, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ArtifactUnlockMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hbbii";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[5] = { uint16(0), uint8(0), uint8(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 5, 0x2123691C, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct AuctionHouseMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[4] = { "", uint16(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 4, 0xBB5A8B0D, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct BankBagSlotPricesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i";
        static uint8 const arraySizes[1] = { 1 };
        static DB2FieldDefault const fieldDefaults[1] = { uint32(0) };
        static DB2Meta instance(-1, 1, 0x8CA96389, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct BannedAddOnsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { "", "", uint8(0) };
        static DB2Meta instance(-1, 3, 0xE9283318, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct BarberShopStyleMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssfbbbbi";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[8] = { "", "", float(0), uint8(0), uint8(0), uint8(0), uint8(0), uint32(0) };
        static DB2Meta instance(7, 8, 0x8C05A540, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct BattlePetAbilityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "isshbbi";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[7] = { uint32(0), "", "", uint16(0), uint8(0), uint8(0), uint32(0) };
        static DB2Meta instance(-1, 7, 0xD9137C24, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct BattlePetAbilityEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhhhhbi";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 6, 1, 1 };
        static DB2FieldDefault const fieldDefaults[7] = { uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint8(0), uint32(0) };
        static DB2Meta instance(6, 7, 0xFE50DB72, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct BattlePetAbilityStateMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { uint32(0), uint16(0), uint8(0) };
        static DB2Meta instance(-1, 3, 0x300E2505, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct BattlePetAbilityTurnMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhbbbi";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[6] = { uint16(0), uint16(0), uint8(0), uint8(0), uint8(0), uint32(0) };
        static DB2Meta instance(5, 6, 0x85676425, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct BattlePetBreedQualityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2FieldDefault const fieldDefaults[2] = { float(0), uint8(0) };
        static DB2Meta instance(-1, 2, 0x2C3B279F, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct BattlePetBreedStateMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hbb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { uint16(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 3, 0xC24FEC66, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct BattlePetEffectPropertiesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shb";
        static uint8 const arraySizes[3] = { 6, 1, 6 };
        static DB2FieldDefault const fieldDefaults[3] = { "", uint16(0), uint8(0) };
        static DB2Meta instance(-1, 3, 0x57364822, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct BattlePetNPCTeamMemberMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2FieldDefault const fieldDefaults[1] = { "" };
        static DB2Meta instance(-1, 1, 0x5F081559, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct BattlePetSpeciesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiisshbbiii";
        static uint8 const arraySizes[11] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[11] = { uint32(0), uint32(0), uint32(0), "", "", uint16(0), uint8(0), uint8(0), uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(8, 11, 0x1CA66769, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct BattlePetSpeciesStateMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { uint32(0), uint16(0), uint8(0) };
        static DB2Meta instance(-1, 3, 0x3AC86CD5, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct BattlePetSpeciesXAbilityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[4] = { uint16(0), uint16(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 4, 0x73D79694, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct BattlePetStateMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shh";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { "", uint16(0), uint16(0) };
        static DB2Meta instance(-1, 3, 0x52C83A39, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct BattlePetVisualMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ishhhbb";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[7] = { uint32(0), "", uint16(0), uint16(0), uint16(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 7, 0xF0088BE3, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct BattlemasterListMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sissshhhbbbbbbbbb";
        static uint8 const arraySizes[17] = { 1, 1, 1, 1, 1, 16, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[17] = { "", uint32(0), "", "", "", uint16(0), uint16(0), uint16(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 17, 0x1D42D3EF, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct BeamEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iffihhhhhh";
        static uint8 const arraySizes[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[10] = { uint32(0), float(0), float(0), uint32(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0) };
        static DB2Meta instance(-1, 10, 0xDC0FF0EB, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct BoneWindModifierModelMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ii";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2FieldDefault const fieldDefaults[2] = { uint32(0), uint32(0) };
        static DB2Meta instance(-1, 2, 0xF1EEC916, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct BoneWindModifiersMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ff";
        static uint8 const arraySizes[2] = { 3, 1 };
        static DB2FieldDefault const fieldDefaults[2] = { float(0), float(0) };
        static DB2Meta instance(-1, 2, 0x9FFF09EC, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct BountyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihhb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[4] = { uint32(0), uint16(0), uint16(0), uint8(0) };
        static DB2Meta instance(-1, 4, 0xA542A1C1, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct BountySetMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hi";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2FieldDefault const fieldDefaults[2] = { uint16(0), uint32(0) };
        static DB2Meta instance(-1, 2, 0x360F6FFD, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct BroadcastTextMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sshhhbbii";
        static uint8 const arraySizes[9] = { 1, 1, 3, 3, 1, 1, 1, 2, 1 };
        static DB2FieldDefault const fieldDefaults[9] = { "", "", uint16(0), uint16(0), uint16(0), uint8(0), uint8(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 9, 0x404B3170, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct CameraEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "b";
        static uint8 const arraySizes[1] = { 1 };
        static DB2FieldDefault const fieldDefaults[1] = { uint8(0) };
        static DB2Meta instance(-1, 1, 0x9949E701, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct CameraEffectEntryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffffffffhhbbbbbb";
        static uint8 const arraySizes[16] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[16] = { float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), uint16(0), uint16(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 16, 0xFB84669B, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct CameraModeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fffffhbbbbb";
        static uint8 const arraySizes[11] = { 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[11] = { float(0), float(0), float(0), float(0), float(0), uint16(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 11, 0x777D00D4, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct CastableRaidBuffsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ii";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2FieldDefault const fieldDefaults[2] = { uint32(0), uint32(0) };
        static DB2Meta instance(-1, 2, 0x508C58D8, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct CelestialBodyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiiiifffffffhi";
        static uint8 const arraySizes[15] = { 1, 1, 2, 1, 1, 2, 2, 2, 1, 2, 1, 3, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[15] = { uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), uint16(0), uint32(0) };
        static DB2Meta instance(14, 15, 0xD3676873, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct Cfg_CategoriesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shbbb";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[5] = { "", uint16(0), uint8(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 5, 0x212D0A85, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct Cfg_ConfigsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fhbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[4] = { float(0), uint16(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 4, 0xB110A69B, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct Cfg_RegionsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "siibb";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[5] = { "", uint32(0), uint32(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 5, 0xBB581C66, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct CharBaseInfoMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2FieldDefault const fieldDefaults[2] = { uint8(0), uint8(0) };
        static DB2Meta instance(-1, 2, 0x754379C6, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct CharBaseSectionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { uint8(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 3, 0x5C6FBF9A, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct CharComponentTextureLayoutsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hh";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2FieldDefault const fieldDefaults[2] = { uint16(0), uint16(0) };
        static DB2Meta instance(-1, 2, 0xB966C960, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct CharComponentTextureSectionsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhhhbbb";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[7] = { uint16(0), uint16(0), uint16(0), uint16(0), uint8(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 7, 0xEC102748, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct CharHairGeosetsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ibbbbbbbbi";
        static uint8 const arraySizes[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[10] = { uint32(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint32(0) };
        static DB2Meta instance(-1, 10, 0x22C73E6A, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct CharSectionsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihbbbbb";
        static uint8 const arraySizes[7] = { 3, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[7] = { uint32(0), uint16(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 7, 0x534D8C12, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct CharShipmentMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiiihhbb";
        static uint8 const arraySizes[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[9] = { uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint16(0), uint16(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 9, 0xE5A1F674, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct CharShipmentContainerMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssihhhhhhbbbbbbi";
        static uint8 const arraySizes[16] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[16] = { "", "", uint32(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint32(0) };
        static DB2Meta instance(-1, 16, 0xBC15C40D, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct CharStartOutfitMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iibbbbb";
        static uint8 const arraySizes[7] = { 24, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[7] = { uint32(0), uint32(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 7, 0xF1166793, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct CharTitlesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sshb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[4] = { "", "", uint16(0), uint8(0) };
        static DB2Meta instance(-1, 4, 0xF4CFAF5F, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct CharacterFaceBoneSetMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ibbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[4] = { uint32(0), uint8(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 4, 0x08781414, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct CharacterFacialHairStylesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ibbb";
        static uint8 const arraySizes[4] = { 5, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[4] = { uint32(0), uint8(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 4, 0x70129D6C, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct CharacterLoadoutMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ibb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { uint32(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 3, 0xA77362E8, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct CharacterLoadoutItemMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ih";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2FieldDefault const fieldDefaults[2] = { uint32(0), uint16(0) };
        static DB2Meta instance(-1, 2, 0x3EE3AA59, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ChatChannelsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "issb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[4] = { uint32(0), "", "", uint8(0) };
        static DB2Meta instance(-1, 4, 0x2EF4243A, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ChatProfanityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2FieldDefault const fieldDefaults[2] = { "", uint8(0) };
        static DB2Meta instance(-1, 2, 0xA105BECA, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ChrClassRaceSexMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbbiii";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[6] = { uint8(0), uint8(0), uint8(0), uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 6, 0x053C5DBF, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ChrClassTitleMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { "", "", uint8(0) };
        static DB2Meta instance(-1, 3, 0x4040E131, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ChrClassUIDisplayMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { uint8(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 3, 0x92F61A82, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ChrClassVillainMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { "", uint8(0), uint8(0) };
        static DB2Meta instance(-1, 3, 0x7A6F0278, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ChrClassesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sssssiiiihhhbbbbbbi";
        static uint8 const arraySizes[19] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[19] = { "", "", "", "", "", uint32(0), uint32(0), uint32(0), uint32(0), uint16(0), uint16(0), uint16(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint32(0) };
        static DB2Meta instance(18, 19, 0x0F6B52A9, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ChrClassesXPowerTypesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2FieldDefault const fieldDefaults[2] = { uint8(0), uint8(0) };
        static DB2Meta instance(-1, 2, 0xDDA9B3B5, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ChrRacesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "isssssssiiffihhhhhhbbbbbbbbbbiii";
        static uint8 const arraySizes[32] = { 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3 };
        static DB2FieldDefault const fieldDefaults[32] = { uint32(0), "", "", "", "", "", "", "", uint32(0), uint32(0), float(0), float(0), uint32(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 32, 0x7D66CD5D, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ChrSpecializationMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "isssbbbbbiiii";
        static uint8 const arraySizes[13] = { 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[13] = { uint32(0), "", "", "", uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint32(0), uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(9, 13, 0x6B9C675E, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ChrUpgradeBucketMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hbi";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { uint16(0), uint8(0), uint32(0) };
        static DB2Meta instance(2, 3, 0xC6DCE691, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ChrUpgradeBucketSpellMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ih";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2FieldDefault const fieldDefaults[2] = { uint32(0), uint16(0) };
        static DB2Meta instance(-1, 2, 0xF1FEF7B7, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ChrUpgradeTierMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbbi";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[4] = { "", uint8(0), uint8(0), uint32(0) };
        static DB2Meta instance(3, 4, 0x4EA0BB7D, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct CinematicCameraMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iffi";
        static uint8 const arraySizes[4] = { 1, 3, 1, 1 };
        static DB2FieldDefault const fieldDefaults[4] = { uint32(0), float(0), float(0), uint32(0) };
        static DB2Meta instance(-1, 4, 0x85F98D68, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct CinematicSequencesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ih";
        static uint8 const arraySizes[2] = { 1, 8 };
        static DB2FieldDefault const fieldDefaults[2] = { uint32(0), uint16(0) };
        static DB2Meta instance(-1, 2, 0xE5589528, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct CloakDampeningMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fffffff";
        static uint8 const arraySizes[7] = { 5, 5, 2, 2, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[7] = { float(0), float(0), float(0), float(0), float(0), float(0), float(0) };
        static DB2Meta instance(-1, 7, 0x4C6C0A23, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct CombatConditionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhhhhbbbbbb";
        static uint8 const arraySizes[11] = { 1, 1, 1, 2, 2, 2, 2, 1, 2, 2, 1 };
        static DB2FieldDefault const fieldDefaults[11] = { uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 11, 0x974D0A2D, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct CommentatorStartLocationMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fi";
        static uint8 const arraySizes[2] = { 3, 1 };
        static DB2FieldDefault const fieldDefaults[2] = { float(0), uint32(0) };
        static DB2Meta instance(-1, 2, 0xC04769B3, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct CommentatorTrackedCooldownMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hbbi";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[4] = { uint16(0), uint8(0), uint8(0), uint32(0) };
        static DB2Meta instance(-1, 4, 0x8252AE1E, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ComponentModelFileDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[4] = { uint8(0), uint8(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 4, 0xBE8BC3B9, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ComponentTextureFileDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { uint8(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 3, 0x1E7268B6, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ContributionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iissii";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 4, 1 };
        static DB2FieldDefault const fieldDefaults[6] = { uint32(0), uint32(0), "", "", uint32(0), uint32(0) };
        static DB2Meta instance(0, 6, 0xBB79E214, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ConversationLineMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiihhbbb";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[8] = { uint32(0), uint32(0), uint32(0), uint16(0), uint16(0), uint8(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 8, 0x6D04DE51, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct CreatureMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiifssssbbbb";
        static uint8 const arraySizes[12] = { 3, 1, 4, 4, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[12] = { uint32(0), uint32(0), uint32(0), float(0), "", "", "", "", uint8(0), uint8(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 12, 0x9044D70F, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct CreatureDifficultyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iihbbb";
        static uint8 const arraySizes[6] = { 1, 7, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[6] = { uint32(0), uint32(0), uint16(0), uint8(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 6, 0x93E33102, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct CreatureDispXUiCameraMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ih";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2FieldDefault const fieldDefaults[2] = { uint32(0), uint16(0) };
        static DB2Meta instance(-1, 2, 0xBB53C829, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct CreatureDisplayInfoMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ifhhbbbiiibhfibhihhbifi";
        static uint8 const arraySizes[23] = { 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[23] = { uint32(0), float(0), uint16(0), uint16(0), uint8(0), uint8(0), uint8(0), uint32(0), uint32(0), uint32(0), uint8(255), uint16(0), float(0), uint32(0), uint8(0), uint16(0), uint32(0), uint16(0), uint16(0), uint8(255), uint32(0), float(1), uint32(0) };
        static DB2Meta instance(0, 23, 0x3CC55E5A, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct CreatureDisplayInfoCondMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiiibbiiiiiiii";
        static uint8 const arraySizes[15] = { 1, 1, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3 };
        static DB2FieldDefault const fieldDefaults[15] = { uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint8(0), uint8(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 15, 0xD59D16F9, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct CreatureDisplayInfoEvtMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 3, 0x40F6DAE0, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct CreatureDisplayInfoExtraMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iibbbbbbbbbb";
        static uint8 const arraySizes[12] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1 };
        static DB2FieldDefault const fieldDefaults[12] = { uint32(0), uint32(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 12, 0xBC7BC222, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct CreatureDisplayInfoTrnMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiif";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[4] = { uint32(0), uint32(0), uint32(0), float(0) };
        static DB2Meta instance(-1, 4, 0x41D09CD0, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct CreatureFamilyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffsihhbbb";
        static uint8 const arraySizes[9] = { 1, 1, 1, 1, 2, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[9] = { float(0), float(0), "", uint32(0), uint16(0), uint16(0), uint8(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 9, 0x10CEE40B, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct CreatureImmunitiesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ibbbbbiii";
        static uint8 const arraySizes[9] = { 2, 1, 1, 1, 1, 1, 1, 8, 16 };
        static DB2FieldDefault const fieldDefaults[9] = { uint32(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 9, 0x73483860, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct CreatureModelDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffffffffffffffffffiiiiiiiiii";
        static uint8 const arraySizes[28] = { 1, 1, 1, 1, 1, 1, 1, 6, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[28] = { float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 28, 0x3F37C132, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct CreatureMovementInfoMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "f";
        static uint8 const arraySizes[1] = { 1 };
        static DB2FieldDefault const fieldDefaults[1] = { float(0) };
        static DB2Meta instance(-1, 1, 0x8263690C, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct CreatureSoundDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffbiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii";
        static uint8 const arraySizes[37] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 5, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[37] = { float(0), float(0), uint8(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 37, 0xBD1B302E, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct CreatureTypeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2FieldDefault const fieldDefaults[2] = { "", uint8(0) };
        static DB2Meta instance(-1, 2, 0xD2D5A474, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct CreatureXContributionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(0, 3, 0xCE01E8F1, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct CriteriaMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiihhhbbbbb";
        static uint8 const arraySizes[11] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[11] = { uint32(0), uint32(0), uint32(0), uint16(0), uint16(0), uint16(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 11, 0xA31558B6, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct CriteriaTreeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ishhbii";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[7] = { uint32(0), "", uint16(0), uint16(0), uint8(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 7, 0x92A517B7, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct CriteriaTreeXEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hh";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2FieldDefault const fieldDefaults[2] = { uint16(0), uint16(0) };
        static DB2Meta instance(-1, 2, 0xC6898472, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct CurrencyCategoryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { "", uint8(0), uint8(0) };
        static DB2Meta instance(-1, 3, 0x58DDFDA9, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct CurrencyTypesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "siiisbbbii";
        static uint8 const arraySizes[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[10] = { "", uint32(0), uint32(0), uint32(0), "", uint8(0), uint8(0), uint8(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 10, 0x312E3E69, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct CurveMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2FieldDefault const fieldDefaults[2] = { uint8(0), uint8(0) };
        static DB2Meta instance(-1, 2, 0xCC46081E, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct CurvePointMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fhb";
        static uint8 const arraySizes[3] = { 2, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { float(0), uint16(0), uint8(0) };
        static DB2Meta instance(-1, 3, 0x44A183DE, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct DeathThudLookupsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbii";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[4] = { uint8(0), uint8(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 4, 0x027CD35A, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct DecalPropertiesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiffffffffbbiiiii";
        static uint8 const arraySizes[17] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[17] = { uint32(0), uint32(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), uint8(0), uint8(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(0, 17, 0x59887EDD, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct DeclinedWordMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "si";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2FieldDefault const fieldDefaults[2] = { "", uint32(0) };
        static DB2Meta instance(1, 2, 0xAC6534F6, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct DeclinedWordCasesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbi";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { "", uint8(0), uint32(0) };
        static DB2Meta instance(-1, 3, 0xD119CEC6, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct DestructibleModelDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhhhhbbbbbbbbbbbbbbbbb";
        static uint8 const arraySizes[22] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[22] = { uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 22, 0xF08A92F1, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct DeviceBlacklistMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hh";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2FieldDefault const fieldDefaults[2] = { uint16(0), uint16(0) };
        static DB2Meta instance(-1, 2, 0xA68DD8FD, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct DeviceDefaultSettingsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { uint16(0), uint16(0), uint8(0) };
        static DB2Meta instance(-1, 3, 0xFFAED9AF, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct DifficultyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shhhbbbbbbbbb";
        static uint8 const arraySizes[13] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[13] = { "", uint16(0), uint16(0), uint16(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 13, 0x198427A9, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct DissolveEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fffffffbbii";
        static uint8 const arraySizes[11] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[11] = { float(0), float(0), float(0), float(0), float(0), float(0), float(0), uint8(0), uint8(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 11, 0x9E215A41, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct DriverBlacklistMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iihbbbb";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[7] = { uint32(0), uint32(0), uint16(0), uint8(0), uint8(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 7, 0xBED272B2, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct DungeonEncounterMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sihbbbiii";
        static uint8 const arraySizes[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[9] = { "", uint32(0), uint16(0), uint8(0), uint8(0), uint8(0), uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(6, 9, 0x710B4A11, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct DungeonMapMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffhhbbbi";
        static uint8 const arraySizes[8] = { 2, 2, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[8] = { float(0), float(0), uint16(0), uint16(0), uint8(0), uint8(0), uint8(0), uint32(0) };
        static DB2Meta instance(7, 8, 0xA0B38918, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct DungeonMapChunkMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fihhh";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[5] = { float(0), uint32(0), uint16(0), uint16(0), uint16(0) };
        static DB2Meta instance(-1, 5, 0xA2D6F6E2, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct DurabilityCostsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hh";
        static uint8 const arraySizes[2] = { 21, 8 };
        static DB2FieldDefault const fieldDefaults[2] = { uint16(0), uint16(0) };
        static DB2Meta instance(-1, 2, 0x0B2FD6C0, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct DurabilityQualityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "f";
        static uint8 const arraySizes[1] = { 1 };
        static DB2FieldDefault const fieldDefaults[1] = { float(0) };
        static DB2Meta instance(-1, 1, 0x6C3562D2, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct EdgeGlowEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffffffffffb";
        static uint8 const arraySizes[11] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[11] = { float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), uint8(0) };
        static DB2Meta instance(-1, 11, 0xC51928D0, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct EmotesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "siiihbiii";
        static uint8 const arraySizes[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[9] = { "", uint32(0), uint32(0), uint32(0), uint16(0), uint8(0), uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 9, 0xCE25ADEC, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct EmotesTextMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sh";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2FieldDefault const fieldDefaults[2] = { "", uint16(0) };
        static DB2Meta instance(-1, 2, 0xFD161EDC, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct EmotesTextDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { "", uint16(0), uint8(0) };
        static DB2Meta instance(-1, 3, 0x2D5D6EAE, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct EmotesTextSoundMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hbbbi";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[5] = { uint16(0), uint8(0), uint8(0), uint8(0), uint32(0) };
        static DB2Meta instance(-1, 5, 0x6C500E43, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct EnvironmentalDamageMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2FieldDefault const fieldDefaults[2] = { uint16(0), uint8(0) };
        static DB2Meta instance(-1, 2, 0x51DD4764, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ExhaustionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ifffsfsi";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[8] = { uint32(0), float(0), float(0), float(0), "", float(0), "", uint32(0) };
        static DB2Meta instance(7, 8, 0x8AD076B3, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct FactionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiifssihhhhhbbbb";
        static uint8 const arraySizes[16] = { 1, 4, 4, 2, 1, 1, 4, 1, 4, 4, 1, 1, 2, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[16] = { uint32(0), uint32(0), uint32(0), float(0), "", "", uint32(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint8(0), uint8(0), uint8(0), uint8(0) };
        static DB2Meta instance(0, 16, 0xDAD6D4BA, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct FactionGroupMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssbii";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[5] = { "", "", uint8(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 5, 0xAA5D6DA4, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct FactionTemplateMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhhhbbb";
        static uint8 const arraySizes[7] = { 1, 1, 4, 4, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[7] = { uint16(0), uint16(0), uint16(0), uint16(0), uint8(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 7, 0x05AF4856, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct FootprintTexturesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 3, 0x5784B862, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct FootstepTerrainLookupMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hbii";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[4] = { uint16(0), uint8(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 4, 0x100A7912, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct FriendshipRepReactionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { "", uint16(0), uint8(0) };
        static DB2Meta instance(-1, 3, 0x46A22CAC, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct FriendshipReputationMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ishi";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[4] = { uint32(0), "", uint16(0), uint32(0) };
        static DB2Meta instance(3, 4, 0xCF470D75, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct FullScreenEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fffffffffffffffffffiiffffffffffffffbiii";
        static uint8 const arraySizes[39] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[39] = { float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), uint32(0), uint32(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), uint8(0), uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 39, 0x16E44121, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct GMSurveyAnswersMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbi";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { "", uint8(0), uint32(0) };
        static DB2Meta instance(-1, 3, 0xCDB0A5E3, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct GMSurveyCurrentSurveyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "b";
        static uint8 const arraySizes[1] = { 1 };
        static DB2FieldDefault const fieldDefaults[1] = { uint8(0) };
        static DB2Meta instance(-1, 1, 0x494DE85C, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct GMSurveyQuestionsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2FieldDefault const fieldDefaults[1] = { "" };
        static DB2Meta instance(-1, 1, 0xFAE68EFD, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct GMSurveySurveysMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "b";
        static uint8 const arraySizes[1] = { 15 };
        static DB2FieldDefault const fieldDefaults[1] = { uint8(0) };
        static DB2Meta instance(-1, 1, 0xBA9D98F1, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct GameObjectArtKitMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ss";
        static uint8 const arraySizes[2] = { 3, 4 };
        static DB2FieldDefault const fieldDefaults[2] = { "", "" };
        static DB2Meta instance(-1, 2, 0x9FD703CD, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct GameObjectDiffAnimMapMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hbbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[4] = { uint16(0), uint8(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 4, 0xAA766D85, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct GameObjectDisplayInfoMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ifffh";
        static uint8 const arraySizes[5] = { 1, 6, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[5] = { uint32(0), float(0), float(0), float(0), uint16(0) };
        static DB2Meta instance(-1, 5, 0x9EF36BC0, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct GameObjectDisplayInfoXSoundKitMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { uint8(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 3, 0x2B8E5987, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct GameObjectsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fffishhhhbbi";
        static uint8 const arraySizes[12] = { 3, 4, 1, 8, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[12] = { float(0), float(0), float(0), uint32(0), "", uint16(0), uint16(0), uint16(0), uint16(0), uint8(0), uint8(0), uint32(0) };
        static DB2Meta instance(11, 12, 0xB2AF06FB, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct GameTipsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shhb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[4] = { "", uint16(0), uint16(0), uint8(0) };
        static DB2Meta instance(-1, 4, 0x4FD29D69, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct GarrAbilityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssihhbbi";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[8] = { "", "", uint32(0), uint16(0), uint16(0), uint8(0), uint8(0), uint32(0) };
        static DB2Meta instance(7, 8, 0x19315777, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct GarrAbilityCategoryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2FieldDefault const fieldDefaults[1] = { "" };
        static DB2Meta instance(-1, 1, 0x3904DB9E, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct GarrAbilityEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fffihbbbbbbi";
        static uint8 const arraySizes[12] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[12] = { float(0), float(0), float(0), uint32(0), uint16(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint32(0) };
        static DB2Meta instance(11, 12, 0x36BC21D5, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct GarrBuildingMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iissssihhhhhhhhbbbbbbiii";
        static uint8 const arraySizes[24] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[24] = { uint32(0), uint32(0), "", "", "", "", uint32(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 24, 0x061062D0, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct GarrBuildingDoodadSetMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbbbb";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[5] = { uint8(0), uint8(0), uint8(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 5, 0x66789ED8, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct GarrBuildingPlotInstMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fhhbi";
        static uint8 const arraySizes[5] = { 2, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[5] = { float(0), uint16(0), uint16(0), uint8(0), uint32(0) };
        static DB2Meta instance(4, 5, 0xA2746F1A, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct GarrClassSpecMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssshhbbi";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[8] = { "", "", "", uint16(0), uint16(0), uint8(0), uint8(0), uint32(0) };
        static DB2Meta instance(7, 8, 0xAC7554D2, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct GarrClassSpecPlayerCondMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "isbiii";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[6] = { uint32(0), "", uint8(0), uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 6, 0x5132E0D2, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct GarrEncounterMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "isffiii";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[7] = { uint32(0), "", float(0), float(0), uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(5, 7, 0xFB05FEFD, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct GarrEncounterSetXEncounterMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ii";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2FieldDefault const fieldDefaults[2] = { uint32(0), uint32(0) };
        static DB2Meta instance(-1, 2, 0x49229773, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct GarrEncounterXMechanicMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hbb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { uint16(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 3, 0x946F8DCC, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct GarrFollItemSetMemberMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihhb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[4] = { uint32(0), uint16(0), uint16(0), uint8(0) };
        static DB2Meta instance(-1, 4, 0x887779FF, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct GarrFollSupportSpellMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iibi";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[4] = { uint32(0), uint32(0), uint8(0), uint32(0) };
        static DB2Meta instance(-1, 4, 0x44FE48FD, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct GarrFollowerMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iissiiiishhhhhhbbbbbbbbbbbbbbbbi";
        static uint8 const arraySizes[32] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[32] = { uint32(0), uint32(0), "", "", uint32(0), uint32(0), uint32(0), uint32(0), "", uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint32(0) };
        static DB2Meta instance(31, 32, 0xC1A8BA64, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct GarrFollowerLevelXPMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[4] = { uint16(0), uint16(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 4, 0xB7B0E5FA, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct GarrFollowerQualityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihbbbbi";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[7] = { uint32(0), uint16(0), uint8(0), uint8(0), uint8(0), uint8(0), uint32(0) };
        static DB2Meta instance(-1, 7, 0xD9C69119, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct GarrFollowerSetXFollowerMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ii";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2FieldDefault const fieldDefaults[2] = { uint32(0), uint32(0) };
        static DB2Meta instance(-1, 2, 0xCD2A828F, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct GarrFollowerTypeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hbbbbbb";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[7] = { uint16(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 7, 0xCEDCA983, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct GarrFollowerUICreatureMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ifhbbb";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[6] = { uint32(0), float(0), uint16(0), uint8(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 6, 0x0F87AA1E, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct GarrFollowerXAbilityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { uint16(0), uint16(0), uint8(0) };
        static DB2Meta instance(-1, 3, 0x7A5F43BE, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct GarrItemLevelUpgradeDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiii";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[5] = { uint32(0), uint32(0), uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(0, 5, 0x84F6F272, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct GarrMechanicMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fbi";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { float(0), uint8(0), uint32(0) };
        static DB2Meta instance(-1, 3, 0x94716B40, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct GarrMechanicSetXMechanicMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { uint8(0), uint32(0), uint32(0) };
        static DB2Meta instance(1, 3, 0x42F5FE36, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct GarrMechanicTypeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssibi";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[5] = { "", "", uint32(0), uint8(0), uint32(0) };
        static DB2Meta instance(4, 5, 0x76E45BEE, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct GarrMissionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iisssffhhhbbbbbbbbbiiiiiiiiii";
        static uint8 const arraySizes[29] = { 1, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[29] = { uint32(0), uint32(0), "", "", "", float(0), float(0), uint16(0), uint16(0), uint16(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(19, 29, 0x6F87532B, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct GarrMissionTextureMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fh";
        static uint8 const arraySizes[2] = { 2, 1 };
        static DB2FieldDefault const fieldDefaults[2] = { float(0), uint16(0) };
        static DB2Meta instance(-1, 2, 0x0334D66C, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct GarrMissionTypeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shh";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { "", uint16(0), uint16(0) };
        static DB2Meta instance(-1, 3, 0xA9188907, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct GarrMissionXEncounterMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "biiii";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[5] = { uint8(0), uint32(0), uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(1, 5, 0x920689A3, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct GarrMissionXFollowerMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 3, 0x06888018, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct GarrMssnBonusAbilityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fihbb";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[5] = { float(0), uint32(0), uint16(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 5, 0xB9920FA7, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct GarrPlotMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "siibbbi";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 2 };
        static DB2FieldDefault const fieldDefaults[7] = { "", uint32(0), uint32(0), uint8(0), uint8(0), uint8(0), uint32(0) };
        static DB2Meta instance(-1, 7, 0xF6F3DFA3, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct GarrPlotBuildingMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2FieldDefault const fieldDefaults[2] = { uint8(0), uint8(0) };
        static DB2Meta instance(-1, 2, 0xAB0E67EA, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct GarrPlotInstanceMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2FieldDefault const fieldDefaults[2] = { "", uint8(0) };
        static DB2Meta instance(-1, 2, 0xD42E767D, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct GarrPlotUICategoryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2FieldDefault const fieldDefaults[2] = { "", uint8(0) };
        static DB2Meta instance(-1, 2, 0x9E938E44, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct GarrSiteLevelMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fhhhhhbbb";
        static uint8 const arraySizes[9] = { 2, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[9] = { float(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint8(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 9, 0x82CAFD63, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct GarrSiteLevelPlotInstMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fhbb";
        static uint8 const arraySizes[4] = { 2, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[4] = { float(0), uint16(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 4, 0x0FCB9EBB, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct GarrSpecializationMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ifssbbb";
        static uint8 const arraySizes[7] = { 1, 2, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[7] = { uint32(0), float(0), "", "", uint8(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 7, 0xB39D24D6, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct GarrStringMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2FieldDefault const fieldDefaults[1] = { "" };
        static DB2Meta instance(-1, 1, 0x07B475A1, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct GarrTalentMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "issibbbiiiiiiiiiiiii";
        static uint8 const arraySizes[20] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[20] = { uint32(0), "", "", uint32(0), uint8(0), uint8(0), uint8(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(7, 20, 0x2AAEEA1A, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct GarrTalentTreeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hbbii";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[5] = { uint16(0), uint8(0), uint8(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 5, 0x6A32C419, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct GarrTypeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiii";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[5] = { uint32(0), uint32(0), uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 5, 0x2D86EF39, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct GarrUiAnimClassInfoMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ifbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[4] = { uint32(0), float(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 4, 0xA646EE4A, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct GarrUiAnimRaceInfoMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffffffffffffb";
        static uint8 const arraySizes[13] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[13] = { float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), uint8(0) };
        static DB2Meta instance(-1, 13, 0xCC2DE241, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct GemPropertiesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihh";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { uint32(0), uint16(0), uint16(0) };
        static DB2Meta instance(-1, 3, 0xF35D29FC, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct GlobalStringsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { "", "", uint8(0) };
        static DB2Meta instance(-1, 3, 0xA6D579DB, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct GlyphBindableSpellMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ih";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2FieldDefault const fieldDefaults[2] = { uint32(0), uint16(0) };
        static DB2Meta instance(-1, 2, 0x9CBB20C4, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct GlyphExclusiveCategoryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2FieldDefault const fieldDefaults[1] = { "" };
        static DB2Meta instance(-1, 1, 0x90608A4C, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct GlyphPropertiesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[4] = { uint32(0), uint16(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 4, 0xA7A2499B, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct GlyphRequiredSpecMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hh";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2FieldDefault const fieldDefaults[2] = { uint16(0), uint16(0) };
        static DB2Meta instance(-1, 2, 0x9B490422, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct GroundEffectDoodadMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sffb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[4] = { "", float(0), float(0), uint8(0) };
        static DB2Meta instance(-1, 4, 0x424C8B10, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct GroundEffectTextureMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hbbi";
        static uint8 const arraySizes[4] = { 4, 4, 1, 1 };
        static DB2FieldDefault const fieldDefaults[4] = { uint16(0), uint8(0), uint8(0), uint32(0) };
        static DB2Meta instance(-1, 4, 0xBCF4D942, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct GroupFinderActivityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sshhhbbbbbbbbb";
        static uint8 const arraySizes[14] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[14] = { "", "", uint16(0), uint16(0), uint16(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 14, 0xCCC85A77, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct GroupFinderActivityGrpMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2FieldDefault const fieldDefaults[2] = { "", uint8(0) };
        static DB2Meta instance(-1, 2, 0x913C69EC, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct GroupFinderCategoryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { "", uint8(0), uint8(0) };
        static DB2Meta instance(-1, 3, 0x51233D98, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct GuildColorBackgroundMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { uint8(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 3, 0xA719A458, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct GuildColorBorderMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { uint8(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 3, 0xA719A458, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct GuildColorEmblemMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { uint8(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 3, 0xA719A458, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct GuildPerkSpellsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i";
        static uint8 const arraySizes[1] = { 1 };
        static DB2FieldDefault const fieldDefaults[1] = { uint32(0) };
        static DB2Meta instance(-1, 1, 0x63FC0F7E, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct HeirloomMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "isiiiihbbi";
        static uint8 const arraySizes[10] = { 1, 1, 1, 1, 1, 3, 3, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[10] = { uint32(0), "", uint32(0), uint32(0), uint32(0), uint32(0), uint16(0), uint8(0), uint8(0), uint32(0) };
        static DB2Meta instance(9, 10, 0x3CE7D5FF, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct HelmetAnimScalingMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { float(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 3, 0x1EDA4C97, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct HelmetGeosetVisDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i";
        static uint8 const arraySizes[1] = { 9 };
        static DB2FieldDefault const fieldDefaults[1] = { uint32(0) };
        static DB2Meta instance(-1, 1, 0xDDD77A78, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct HighlightColorMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiibb";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[5] = { uint32(0), uint32(0), uint32(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 5, 0x5A5613AE, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct HolidayDescriptionsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2FieldDefault const fieldDefaults[1] = { "" };
        static DB2Meta instance(-1, 1, 0xF00AB471, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct HolidayNamesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2FieldDefault const fieldDefaults[1] = { "" };
        static DB2Meta instance(-1, 1, 0x3904DB9E, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct HolidaysMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iihhbbbbbiii";
        static uint8 const arraySizes[12] = { 1, 16, 10, 1, 1, 10, 1, 1, 1, 1, 1, 3 };
        static DB2FieldDefault const fieldDefaults[12] = { uint32(0), uint32(0), uint16(0), uint16(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(0, 12, 0x4CE0E634, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct HotfixMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { "", uint32(0), uint32(0) };
        static DB2Meta instance(-1, 3, 0xB21AEBA0, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ImportPriceArmorMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffff";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[4] = { float(0), float(0), float(0), float(0) };
        static DB2Meta instance(-1, 4, 0x3AA36BEB, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ImportPriceQualityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "f";
        static uint8 const arraySizes[1] = { 1 };
        static DB2FieldDefault const fieldDefaults[1] = { float(0) };
        static DB2Meta instance(-1, 1, 0x6C3562D2, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ImportPriceShieldMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "f";
        static uint8 const arraySizes[1] = { 1 };
        static DB2FieldDefault const fieldDefaults[1] = { float(0) };
        static DB2Meta instance(-1, 1, 0x6C3562D2, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ImportPriceWeaponMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "f";
        static uint8 const arraySizes[1] = { 1 };
        static DB2FieldDefault const fieldDefaults[1] = { float(0) };
        static DB2Meta instance(-1, 1, 0x6C3562D2, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct InvasionClientDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sfiiiiiiii";
        static uint8 const arraySizes[10] = { 1, 2, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[10] = { "", float(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(2, 10, 0x9F6F9573, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ItemMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ibbbbbbb";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[8] = { uint32(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 8, 0xC0DF3CD9, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ItemAppearanceMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiib";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[4] = { uint32(0), uint32(0), uint32(0), uint8(0) };
        static DB2Meta instance(-1, 4, 0x121F06BB, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ItemAppearanceXUiCameraMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hh";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2FieldDefault const fieldDefaults[2] = { uint16(0), uint16(0) };
        static DB2Meta instance(-1, 2, 0x7EE16A0D, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ItemArmorQualityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fh";
        static uint8 const arraySizes[2] = { 7, 1 };
        static DB2FieldDefault const fieldDefaults[2] = { float(0), uint16(0) };
        static DB2Meta instance(-1, 2, 0x394BF53C, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ItemArmorShieldMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fh";
        static uint8 const arraySizes[2] = { 7, 1 };
        static DB2FieldDefault const fieldDefaults[2] = { float(0), uint16(0) };
        static DB2Meta instance(-1, 2, 0x8F14CB07, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ItemArmorTotalMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffffh";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[5] = { float(0), float(0), float(0), float(0), uint16(0) };
        static DB2Meta instance(-1, 5, 0xBF25F97C, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ItemBagFamilyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2FieldDefault const fieldDefaults[1] = { "" };
        static DB2Meta instance(-1, 1, 0x3904DB9E, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ItemBonusMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihbb";
        static uint8 const arraySizes[4] = { 2, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[4] = { uint32(0), uint16(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 4, 0x23702544, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ItemBonusListLevelDeltaMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hi";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2FieldDefault const fieldDefaults[2] = { uint16(0), uint32(0) };
        static DB2Meta instance(1, 2, 0x0D7E0F69, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ItemBonusTreeNodeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhhhb";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[5] = { uint16(0), uint16(0), uint16(0), uint16(0), uint8(0) };
        static DB2Meta instance(-1, 5, 0xDFCBD330, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ItemChildEquipmentMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iib";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { uint32(0), uint32(0), uint8(0) };
        static DB2Meta instance(-1, 3, 0xC6828B5F, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ItemClassMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fsbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[4] = { float(0), "", uint8(0), uint8(0) };
        static DB2Meta instance(-1, 4, 0x9996F3E4, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ItemContextPickerEntryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbiii";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[5] = { uint8(0), uint8(0), uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 5, 0xE9470653, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ItemCurrencyCostMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i";
        static uint8 const arraySizes[1] = { 1 };
        static DB2FieldDefault const fieldDefaults[1] = { uint32(0) };
        static DB2Meta instance(-1, 1, 0x4060B5A9, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ItemDamageAmmoMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fh";
        static uint8 const arraySizes[2] = { 7, 1 };
        static DB2FieldDefault const fieldDefaults[2] = { float(0), uint16(0) };
        static DB2Meta instance(-1, 2, 0x8F14CB07, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ItemDamageOneHandMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fh";
        static uint8 const arraySizes[2] = { 7, 1 };
        static DB2FieldDefault const fieldDefaults[2] = { float(0), uint16(0) };
        static DB2Meta instance(-1, 2, 0x8F14CB07, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ItemDamageOneHandCasterMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fh";
        static uint8 const arraySizes[2] = { 7, 1 };
        static DB2FieldDefault const fieldDefaults[2] = { float(0), uint16(0) };
        static DB2Meta instance(-1, 2, 0x8F14CB07, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ItemDamageTwoHandMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fh";
        static uint8 const arraySizes[2] = { 7, 1 };
        static DB2FieldDefault const fieldDefaults[2] = { float(0), uint16(0) };
        static DB2Meta instance(-1, 2, 0x8F14CB07, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ItemDamageTwoHandCasterMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fh";
        static uint8 const arraySizes[2] = { 7, 1 };
        static DB2FieldDefault const fieldDefaults[2] = { float(0), uint16(0) };
        static DB2Meta instance(-1, 2, 0x8F14CB07, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ItemDisenchantLootMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhhbbb";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[6] = { uint16(0), uint16(0), uint16(0), uint8(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 6, 0xED814E91, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ItemDisplayInfoMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiiiiiiiiiiiii";
        static uint8 const arraySizes[15] = { 2, 2, 3, 3, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[15] = { uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 15, 0x62BBDA36, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ItemDisplayInfoMaterialResMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iib";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { uint32(0), uint32(0), uint8(0) };
        static DB2Meta instance(-1, 3, 0x6435FD14, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ItemDisplayXUiCameraMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ih";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2FieldDefault const fieldDefaults[2] = { uint32(0), uint16(0) };
        static DB2Meta instance(-1, 2, 0x1EB6CE14, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ItemEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiihhhbb";
        static uint8 const arraySizes[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[9] = { uint32(0), uint32(0), uint32(0), uint32(0), uint16(0), uint16(0), uint16(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 9, 0xE7C4FB49, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ItemExtendedCostMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iihhhbbbbb";
        static uint8 const arraySizes[10] = { 5, 5, 5, 1, 5, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[10] = { uint32(0), uint32(0), uint16(0), uint16(0), uint16(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 10, 0xA69B7665, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ItemGroupSoundsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i";
        static uint8 const arraySizes[1] = { 4 };
        static DB2FieldDefault const fieldDefaults[1] = { uint32(0) };
        static DB2Meta instance(-1, 1, 0x094808C1, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ItemLevelSelectorMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "h";
        static uint8 const arraySizes[1] = { 1 };
        static DB2FieldDefault const fieldDefaults[1] = { uint16(0) };
        static DB2Meta instance(-1, 1, 0x858C1619, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ItemLimitCategoryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { "", uint8(0), uint8(0) };
        static DB2Meta instance(-1, 3, 0xAC1539C8, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ItemLimitCategoryConditionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { uint8(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 3, 0xD3A638FA, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ItemModifiedAppearanceMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihbbbi";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[6] = { uint32(0), uint16(0), uint8(0), uint8(0), uint8(0), uint32(0) };
        static DB2Meta instance(5, 6, 0xA3FDFED1, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ItemModifiedAppearanceExtraMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iibbb";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[5] = { uint32(0), uint32(0), uint8(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 5, 0x383879CB, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ItemNameDescriptionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "si";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2FieldDefault const fieldDefaults[2] = { "", uint32(0) };
        static DB2Meta instance(-1, 2, 0x05098966, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ItemPetFoodMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2FieldDefault const fieldDefaults[1] = { "" };
        static DB2Meta instance(-1, 1, 0x8730DCFE, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ItemPriceBaseMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffh";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { float(0), float(0), uint16(0) };
        static DB2Meta instance(-1, 3, 0x03750934, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ItemRandomPropertiesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sh";
        static uint8 const arraySizes[2] = { 1, 5 };
        static DB2FieldDefault const fieldDefaults[2] = { "", uint16(0) };
        static DB2Meta instance(-1, 2, 0x7D6F4EDC, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ItemRandomSuffixMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shh";
        static uint8 const arraySizes[3] = { 1, 5, 5 };
        static DB2FieldDefault const fieldDefaults[3] = { "", uint16(0), uint16(0) };
        static DB2Meta instance(-1, 3, 0x826E5016, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ItemRangedDisplayInfoMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiii";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[4] = { uint32(0), uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 4, 0xCE6F98AF, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ItemSearchNameMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "siiihhhhbbbbi";
        static uint8 const arraySizes[13] = { 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[13] = { "", uint32(0), uint32(0), uint32(0), uint16(0), uint16(0), uint16(0), uint16(0), uint8(0), uint8(0), uint8(0), uint8(0), uint32(0) };
        static DB2Meta instance(-1, 13, 0xF245D75D, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ItemSetMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sihii";
        static uint8 const arraySizes[5] = { 1, 17, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[5] = { "", uint32(0), uint16(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 5, 0x64E9C31D, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ItemSetSpellMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihhb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[4] = { uint32(0), uint16(0), uint16(0), uint8(0) };
        static DB2Meta instance(-1, 4, 0x68B26488, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ItemSparseMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iffiiiiiiiiffsssssififhhhhhhhhhhhhhhhhhhhhhhhbbbbbbbbbbbbbbbbbbb";
        static uint8 const arraySizes[64] = { 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 10, 10, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 10, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 10, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[64] = { uint32(0), float(0), float(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), float(0), float(0), "", "", "", "", "", uint32(0), float(0), uint32(0), float(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 64, 0x2CDA679A, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ItemSpecMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hbbbbb";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[6] = { uint16(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 6, 0x91EB0140, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ItemSpecOverrideMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ih";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2FieldDefault const fieldDefaults[2] = { uint32(0), uint16(0) };
        static DB2Meta instance(-1, 2, 0x998D0348, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ItemSubClassMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sshbbbbbbb";
        static uint8 const arraySizes[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[10] = { "", "", uint16(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 10, 0x4656936D, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ItemSubClassMaskMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "isb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { uint32(0), "", uint8(0) };
        static DB2Meta instance(-1, 3, 0x3A3C009D, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ItemUpgradeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihhbb";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[5] = { uint32(0), uint16(0), uint16(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 5, 0x8C289A02, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ItemVisualEffectsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2FieldDefault const fieldDefaults[1] = { "" };
        static DB2Meta instance(-1, 1, 0x3024FF02, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ItemVisualsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "h";
        static uint8 const arraySizes[1] = { 5 };
        static DB2FieldDefault const fieldDefaults[1] = { uint16(0) };
        static DB2Meta instance(-1, 1, 0xDFC58D7E, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ItemXBonusTreeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ih";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2FieldDefault const fieldDefaults[2] = { uint32(0), uint16(0) };
        static DB2Meta instance(-1, 2, 0x1513D39F, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct JournalEncounterMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fsshhhhbbii";
        static uint8 const arraySizes[11] = { 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[11] = { float(0), "", "", uint16(0), uint16(0), uint16(0), uint16(0), uint8(0), uint8(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 11, 0xF58D8B3E, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct JournalEncounterCreatureMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iisshbi";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[7] = { uint32(0), uint32(0), "", "", uint16(0), uint8(0), uint32(0) };
        static DB2Meta instance(6, 7, 0xD3A6C2CF, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct JournalEncounterItemMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihbbbi";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[6] = { uint32(0), uint16(0), uint8(0), uint8(0), uint8(0), uint32(0) };
        static DB2Meta instance(5, 6, 0xA4AF3B4B, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct JournalEncounterSectionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssiiihhhhhhbbb";
        static uint8 const arraySizes[14] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[14] = { "", "", uint32(0), uint32(0), uint32(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint8(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 14, 0xA3FC6A6B, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct JournalEncounterXDifficultyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2FieldDefault const fieldDefaults[2] = { uint16(0), uint8(0) };
        static DB2Meta instance(-1, 2, 0xAC8AC546, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct JournalInstanceMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiisshhbbi";
        static uint8 const arraySizes[11] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[11] = { uint32(0), uint32(0), uint32(0), uint32(0), "", "", uint16(0), uint16(0), uint8(0), uint8(0), uint32(0) };
        static DB2Meta instance(10, 11, 0x5ADEB91A, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct JournalItemXDifficultyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2FieldDefault const fieldDefaults[2] = { uint16(0), uint8(0) };
        static DB2Meta instance(-1, 2, 0xA2434FB5, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct JournalSectionXDifficultyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2FieldDefault const fieldDefaults[2] = { uint16(0), uint8(0) };
        static DB2Meta instance(-1, 2, 0x58F088AB, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct JournalTierMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2FieldDefault const fieldDefaults[1] = { "" };
        static DB2Meta instance(-1, 1, 0x22E5531E, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct JournalTierXInstanceMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hh";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2FieldDefault const fieldDefaults[2] = { uint16(0), uint16(0) };
        static DB2Meta instance(-1, 2, 0x148D3EC4, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct KeyChainMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "b";
        static uint8 const arraySizes[1] = { 32 };
        static DB2FieldDefault const fieldDefaults[1] = { uint8(0) };
        static DB2Meta instance(-1, 1, 0xFDBFEF61, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct KeystoneAffixMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssi";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { "", "", uint32(0) };
        static DB2Meta instance(-1, 3, 0x96AEEFE1, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct LanguageWordsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2FieldDefault const fieldDefaults[2] = { "", uint8(0) };
        static DB2Meta instance(-1, 2, 0xB128C39B, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct LanguagesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "si";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2FieldDefault const fieldDefaults[2] = { "", uint32(0) };
        static DB2Meta instance(1, 2, 0x5FDF22D6, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct LfgDungeonExpansionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhbbbii";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[7] = { uint16(0), uint16(0), uint8(0), uint8(0), uint8(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 7, 0xA1F7409C, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct LfgDungeonGroupMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[4] = { "", uint16(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 4, 0xF75B9257, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct LfgDungeonsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sisfhhhhhhhhhbbbbbbbbbbbbbbbbbiii";
        static uint8 const arraySizes[33] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[33] = { "", uint32(0), "", float(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 33, 0x0FBB2573, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct LfgDungeonsGroupingMapMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { uint16(0), uint16(0), uint8(0) };
        static DB2Meta instance(-1, 3, 0x459FD93F, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct LfgRoleRequirementMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hbi";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { uint16(0), uint8(0), uint32(0) };
        static DB2Meta instance(-1, 3, 0x8F8987DE, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct LightMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fffhh";
        static uint8 const arraySizes[5] = { 3, 1, 1, 1, 8 };
        static DB2FieldDefault const fieldDefaults[5] = { float(0), float(0), float(0), uint16(0), uint16(0) };
        static DB2Meta instance(-1, 5, 0xD7A45504, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct LightDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiiiiiiiiiiiiiiiifffffffffiiiiiihh";
        static uint8 const arraySizes[35] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[35] = { uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint16(0), uint16(0) };
        static DB2Meta instance(-1, 35, 0xCFCF6A11, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct LightParamsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffffffhbbbi";
        static uint8 const arraySizes[11] = { 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[11] = { float(0), float(0), float(0), float(0), float(0), float(0), uint16(0), uint8(0), uint8(0), uint8(0), uint32(0) };
        static DB2Meta instance(10, 11, 0x96B9BFD4, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct LightSkyboxMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "siib";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[4] = { "", uint32(0), uint32(0), uint8(0) };
        static DB2Meta instance(-1, 4, 0x599D510E, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct LiquidMaterialMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2FieldDefault const fieldDefaults[2] = { uint8(0), uint8(0) };
        static DB2Meta instance(-1, 2, 0x0BACC5EA, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct LiquidObjectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffhbb";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[5] = { float(0), float(0), uint16(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 5, 0x936412BD, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct LiquidTypeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sifffffsifihhbbbbbi";
        static uint8 const arraySizes[19] = { 1, 1, 1, 1, 1, 1, 1, 6, 2, 18, 4, 1, 1, 1, 1, 1, 1, 6, 1 };
        static DB2FieldDefault const fieldDefaults[19] = { "", uint32(0), float(0), float(0), float(0), float(0), float(0), "", uint32(0), float(0), uint32(0), uint16(0), uint16(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint32(0) };
        static DB2Meta instance(-1, 19, 0xEB9E4B52, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct LoadingScreenTaxiSplinesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffhhb";
        static uint8 const arraySizes[5] = { 10, 10, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[5] = { float(0), float(0), uint16(0), uint16(0), uint8(0) };
        static DB2Meta instance(-1, 5, 0x14126CDE, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct LoadingScreensMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 3, 0x68B99439, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct LocaleMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ibbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[4] = { uint32(0), uint8(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 4, 0xAE598A8F, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct LocationMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ff";
        static uint8 const arraySizes[2] = { 3, 3 };
        static DB2FieldDefault const fieldDefaults[2] = { float(0), float(0) };
        static DB2Meta instance(-1, 2, 0x0C9FA688, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct LockMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihbb";
        static uint8 const arraySizes[4] = { 8, 8, 8, 8 };
        static DB2FieldDefault const fieldDefaults[4] = { uint32(0), uint16(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 4, 0x2A5174FF, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct LockTypeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssssi";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[5] = { "", "", "", "", uint32(0) };
        static DB2Meta instance(4, 5, 0x45B49052, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct LookAtControllerMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffffhhhhbbbbbiiiii";
        static uint8 const arraySizes[18] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[18] = { float(0), float(0), float(0), float(0), uint16(0), uint16(0), uint16(0), uint16(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 18, 0x5CADD6CE, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct MailTemplateMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2FieldDefault const fieldDefaults[1] = { "" };
        static DB2Meta instance(-1, 1, 0x832A35ED, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ManagedWorldStateMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiiiiiiii";
        static uint8 const arraySizes[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[10] = { uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(9, 10, 0xF7EDCAD1, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ManagedWorldStateBuffMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiii";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[4] = { uint32(0), uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 4, 0x60EA865B, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ManagedWorldStateInputMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 3, 0x7160F4F3, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ManifestInterfaceActionIconMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i";
        static uint8 const arraySizes[1] = { 1 };
        static DB2FieldDefault const fieldDefaults[1] = { uint32(0) };
        static DB2Meta instance(0, 1, 0x0CF14016, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ManifestInterfaceDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ss";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2FieldDefault const fieldDefaults[2] = { "", "" };
        static DB2Meta instance(-1, 2, 0x08EA6AC9, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ManifestInterfaceItemIconMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i";
        static uint8 const arraySizes[1] = { 1 };
        static DB2FieldDefault const fieldDefaults[1] = { uint32(0) };
        static DB2Meta instance(0, 1, 0x0CF14016, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ManifestInterfaceTOCDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2FieldDefault const fieldDefaults[1] = { "" };
        static DB2Meta instance(-1, 1, 0x121BDA5C, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ManifestMP3Meta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i";
        static uint8 const arraySizes[1] = { 1 };
        static DB2FieldDefault const fieldDefaults[1] = { uint32(0) };
        static DB2Meta instance(0, 1, 0x0CF14016, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct MapMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "siffssssshhhhhhhbbbbb";
        static uint8 const arraySizes[21] = { 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[21] = { "", uint32(0), float(0), float(0), "", "", "", "", "", uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 21, 0xC34CD39B, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct MapCelestialBodyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhi";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { uint16(0), uint16(0), uint32(0) };
        static DB2Meta instance(-1, 3, 0x4A133A37, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct MapChallengeModeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ishhb";
        static uint8 const arraySizes[5] = { 1, 1, 1, 3, 1 };
        static DB2FieldDefault const fieldDefaults[5] = { uint32(0), "", uint16(0), uint16(0), uint8(0) };
        static DB2Meta instance(0, 5, 0x20D6D025, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct MapDifficultyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shbbbbbbi";
        static uint8 const arraySizes[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[9] = { "", uint16(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint32(0) };
        static DB2Meta instance(-1, 9, 0x592DC1E1, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct MapDifficultyXConditionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "siii";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[4] = { "", uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 4, 0x5326D470, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct MarketingPromotionsXLocaleMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiisbb";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[7] = { uint32(0), uint32(0), uint32(0), uint32(0), "", uint8(0), uint8(0) };
        static DB2Meta instance(-1, 7, 0xD7CA6C38, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct MaterialMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "biii";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[4] = { uint8(0), uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 4, 0xCD76BC84, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct MinorTalentMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 3, 0xE365DD95, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ModelAnimCloakDampeningMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 3, 0xBF0CF2C8, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ModelFileDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { uint8(0), uint32(0), uint32(0) };
        static DB2Meta instance(1, 3, 0x8994DB79, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ModelRibbonQualityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ib";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2FieldDefault const fieldDefaults[2] = { uint32(0), uint8(0) };
        static DB2Meta instance(-1, 2, 0x7AFA1F55, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ModifierTreeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iihbbbb";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[7] = { uint32(0), uint32(0), uint16(0), uint8(0), uint8(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 7, 0xE3B45A7D, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct MountMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "isssfhhbiii";
        static uint8 const arraySizes[11] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[11] = { uint32(0), "", "", "", float(0), uint16(0), uint16(0), uint8(0), uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(8, 11, 0xBCA6C106, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct MountCapabilityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iihhhbii";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[8] = { uint32(0), uint32(0), uint16(0), uint16(0), uint16(0), uint8(0), uint32(0), uint32(0) };
        static DB2Meta instance(6, 8, 0xE81038CA, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct MountTypeXCapabilityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { uint16(0), uint16(0), uint8(0) };
        static DB2Meta instance(-1, 3, 0xA5E685D0, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct MountXDisplayMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 3, 0x0CEBAA11, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct MovieMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iibb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[4] = { uint32(0), uint32(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 4, 0xEBC7B6C9, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct MovieFileDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "h";
        static uint8 const arraySizes[1] = { 1 };
        static DB2FieldDefault const fieldDefaults[1] = { uint16(0) };
        static DB2Meta instance(-1, 1, 0x5B4C50A0, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct MovieVariationMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihi";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { uint32(0), uint16(0), uint32(0) };
        static DB2Meta instance(-1, 3, 0x2A319023, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct NPCSoundsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i";
        static uint8 const arraySizes[1] = { 4 };
        static DB2FieldDefault const fieldDefaults[1] = { uint32(0) };
        static DB2Meta instance(-1, 1, 0xC48F798C, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct NameGenMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { "", uint8(0), uint8(0) };
        static DB2Meta instance(-1, 3, 0xF5753138, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct NamesProfanityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2FieldDefault const fieldDefaults[2] = { "", uint8(0) };
        static DB2Meta instance(-1, 2, 0xA99B2912, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct NamesReservedMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2FieldDefault const fieldDefaults[1] = { "" };
        static DB2Meta instance(-1, 1, 0x8730DCFE, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct NamesReservedLocaleMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2FieldDefault const fieldDefaults[2] = { "", uint8(0) };
        static DB2Meta instance(-1, 2, 0x38161F55, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct NpcModelItemSlotDisplayInfoMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iib";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { uint32(0), uint32(0), uint8(0) };
        static DB2Meta instance(-1, 3, 0x6F4C79CF, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ObjectEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sfhbbbbii";
        static uint8 const arraySizes[9] = { 1, 3, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[9] = { "", float(0), uint16(0), uint8(0), uint8(0), uint8(0), uint8(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 9, 0x068A1648, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ObjectEffectGroupMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2FieldDefault const fieldDefaults[1] = { "" };
        static DB2Meta instance(-1, 1, 0x3904DB9E, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ObjectEffectModifierMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fbbb";
        static uint8 const arraySizes[4] = { 4, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[4] = { float(0), uint8(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 4, 0x1BB6C439, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ObjectEffectPackageMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2FieldDefault const fieldDefaults[1] = { "" };
        static DB2Meta instance(-1, 1, 0x3904DB9E, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ObjectEffectPackageElemMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhh";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { uint16(0), uint16(0), uint16(0) };
        static DB2Meta instance(-1, 3, 0xC470C33C, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct OutlineEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fiiiii";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[6] = { float(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 6, 0x937C8918, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct OverrideSpellDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iib";
        static uint8 const arraySizes[3] = { 10, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { uint32(0), uint32(0), uint8(0) };
        static DB2Meta instance(-1, 3, 0x57896951, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct PageTextMaterialMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2FieldDefault const fieldDefaults[1] = { "" };
        static DB2Meta instance(-1, 1, 0x3904DB9E, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct PaperDollItemFrameMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { "", "", uint8(0) };
        static DB2Meta instance(-1, 3, 0x3949398C, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ParagonReputationMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 3, 0x835D97B5, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ParticleColorMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 3, 3, 3 };
        static DB2FieldDefault const fieldDefaults[3] = { uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 3, 0xA3E6ABEE, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct PathMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbbbbbb";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[7] = { uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 7, 0x33962B1C, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct PathNodeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iihh";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[4] = { uint32(0), uint32(0), uint16(0), uint16(0) };
        static DB2Meta instance(0, 4, 0x74A74F2E, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct PathNodePropertyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhbii";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[5] = { uint16(0), uint16(0), uint8(0), uint32(0), uint32(0) };
        static DB2Meta instance(3, 5, 0x8ECAC0B2, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct PathPropertyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihbi";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[4] = { uint32(0), uint16(0), uint8(0), uint32(0) };
        static DB2Meta instance(3, 4, 0x9A295667, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct PhaseMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "h";
        static uint8 const arraySizes[1] = { 1 };
        static DB2FieldDefault const fieldDefaults[1] = { uint16(0) };
        static DB2Meta instance(-1, 1, 0xE1C0D763, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct PhaseShiftZoneSoundsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhhhhbbbbiiii";
        static uint8 const arraySizes[13] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[13] = { uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint8(0), uint8(0), uint8(0), uint8(0), uint32(0), uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 13, 0x0892E505, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct PhaseXPhaseGroupMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hh";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2FieldDefault const fieldDefaults[2] = { uint16(0), uint16(0) };
        static DB2Meta instance(-1, 2, 0x058995BA, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct PlayerConditionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiiiiiiiiiiiishhhhhhhhhhhhhhhhhhbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbiiiiiiiiiiiiiiii";
        static uint8 const arraySizes[80] = { 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 4, 1, 1, 1, 1, 1, 1, 4, 4, 4, 1, 4, 4, 4, 2, 1, 4, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 1, 4, 1, 1, 1, 4, 4, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 4, 4, 4, 1, 4, 1, 4, 6, 1, 1, 1, 2, 1 };
        static DB2FieldDefault const fieldDefaults[80] = { uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), "", uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 80, 0xC1DF2C51, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct PositionerMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fhbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[4] = { float(0), uint16(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 4, 0xA8251F4D, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct PositionerStateMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fbiiiiii";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[8] = { float(0), uint8(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 8, 0xFE756728, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct PositionerStateEntryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffhhhhbbbbi";
        static uint8 const arraySizes[11] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[11] = { float(0), float(0), uint16(0), uint16(0), uint16(0), uint16(0), uint8(0), uint8(0), uint8(0), uint8(0), uint32(0) };
        static DB2Meta instance(-1, 11, 0xA6C68AB6, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct PowerDisplayMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbbbb";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[5] = { "", uint8(0), uint8(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 5, 0x34D32464, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct PowerTypeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssffhhhbbbbb";
        static uint8 const arraySizes[12] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[12] = { "", "", float(0), float(0), uint16(0), uint16(0), uint16(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 12, 0xB1EC389B, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct PrestigeLevelInfoMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "isbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[4] = { uint32(0), "", uint8(0), uint8(0) };
        static DB2Meta instance(-1, 4, 0x3BFC82FB, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct PvpBracketTypesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bi";
        static uint8 const arraySizes[2] = { 1, 4 };
        static DB2FieldDefault const fieldDefaults[2] = { uint8(0), uint32(0) };
        static DB2Meta instance(-1, 2, 0x26EDA043, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct PvpDifficultyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hbbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[4] = { uint16(0), uint8(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 4, 0x86D72D63, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct PvpItemMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ib";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2FieldDefault const fieldDefaults[2] = { uint32(0), uint8(0) };
        static DB2Meta instance(-1, 2, 0xF92326FB, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct PvpRewardMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 3, 0x13470FF5, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct PvpScalingEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { float(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 3, 0x473E3F4A, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct PvpScalingEffectTypeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2FieldDefault const fieldDefaults[1] = { "" };
        static DB2Meta instance(-1, 1, 0x3904DB9E, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct PvpTalentMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iisiiiiiii";
        static uint8 const arraySizes[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[10] = { uint32(0), uint32(0), "", uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 10, 0x8868B3E8, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct PvpTalentUnlockMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 3, 0x9500E5F3, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct QuestFactionRewardMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "h";
        static uint8 const arraySizes[1] = { 10 };
        static DB2FieldDefault const fieldDefaults[1] = { uint16(0) };
        static DB2Meta instance(-1, 1, 0x537EC620, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct QuestFeedbackEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihbbbb";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[6] = { uint32(0), uint16(0), uint8(0), uint8(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 6, 0x6F933FDB, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct QuestInfoMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[4] = { "", uint16(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 4, 0xBBA77DA5, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct QuestLineMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2FieldDefault const fieldDefaults[1] = { "" };
        static DB2Meta instance(-1, 1, 0x22E5531E, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct QuestLineXQuestMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { uint16(0), uint16(0), uint8(0) };
        static DB2Meta instance(-1, 3, 0x7DBDC94A, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct QuestMoneyRewardMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i";
        static uint8 const arraySizes[1] = { 10 };
        static DB2FieldDefault const fieldDefaults[1] = { uint32(0) };
        static DB2Meta instance(-1, 1, 0x28D813E1, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct QuestObjectiveMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iishbbbb";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[8] = { uint32(0), uint32(0), "", uint16(0), uint8(0), uint8(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 8, 0x2C239174, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct QuestPOIBlobMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihhbbiii";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[8] = { uint32(0), uint16(0), uint16(0), uint8(0), uint8(0), uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(0, 8, 0xA9FB7F3E, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct QuestPOIPointMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihhi";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[4] = { uint32(0), uint16(0), uint16(0), uint32(0) };
        static DB2Meta instance(3, 4, 0xEAFC2A23, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct QuestPackageItemMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihbi";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[4] = { uint32(0), uint16(0), uint8(0), uint32(0) };
        static DB2Meta instance(-1, 4, 0x156B634B, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct QuestSortMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2FieldDefault const fieldDefaults[2] = { "", uint8(0) };
        static DB2Meta instance(-1, 2, 0x222914B6, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct QuestV2Meta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "h";
        static uint8 const arraySizes[1] = { 1 };
        static DB2FieldDefault const fieldDefaults[1] = { uint16(0) };
        static DB2Meta instance(-1, 1, 0x0C89D0A4, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct QuestV2CliTaskMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "issihhhhhhbbbbbbbbbbiii";
        static uint8 const arraySizes[23] = { 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[23] = { uint32(0), "", "", uint32(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(20, 23, 0x9DF4A8B7, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct QuestXGroupActivityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ii";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2FieldDefault const fieldDefaults[2] = { uint32(0), uint32(0) };
        static DB2Meta instance(-1, 2, 0x193C0151, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct QuestXPMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "h";
        static uint8 const arraySizes[1] = { 10 };
        static DB2FieldDefault const fieldDefaults[1] = { uint16(0) };
        static DB2Meta instance(-1, 1, 0x1A4139BF, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct RandPropPointsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 5, 5, 5 };
        static DB2FieldDefault const fieldDefaults[3] = { uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 3, 0x599C6627, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ResearchBranchMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssihb";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[5] = { "", "", uint32(0), uint16(0), uint8(0) };
        static DB2Meta instance(-1, 5, 0xE5317F8B, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ResearchFieldMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbi";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { "", uint8(0), uint32(0) };
        static DB2Meta instance(2, 3, 0x819D5A2C, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ResearchProjectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssishbbii";
        static uint8 const arraySizes[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[9] = { "", "", uint32(0), "", uint16(0), uint8(0), uint8(0), uint32(0), uint32(0) };
        static DB2Meta instance(7, 9, 0x8DFB0CED, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ResearchSiteMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ishi";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[4] = { uint32(0), "", uint16(0), uint32(0) };
        static DB2Meta instance(-1, 4, 0xA9B8D8DB, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ResistancesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbi";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { "", uint8(0), uint32(0) };
        static DB2Meta instance(-1, 3, 0xC254EDE9, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct RewardPackMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ifbbii";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[6] = { uint32(0), float(0), uint8(0), uint8(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 6, 0xC8C347FF, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct RewardPackXCurrencyTypeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 3, 0xCDD4B84B, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct RewardPackXItemMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 3, 0xF2271B6C, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct RibbonQualityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fffbi";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[5] = { float(0), float(0), float(0), uint8(0), uint32(0) };
        static DB2Meta instance(-1, 5, 0x87409B0D, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct RulesetItemUpgradeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ih";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2FieldDefault const fieldDefaults[2] = { uint32(0), uint16(0) };
        static DB2Meta instance(-1, 2, 0xFBB306B8, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ScalingStatDistributionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { uint16(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 3, 0xC502D749, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ScenarioMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[4] = { "", uint16(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 4, 0xD58F8986, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ScenarioEventEntryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2FieldDefault const fieldDefaults[2] = { uint16(0), uint8(0) };
        static DB2Meta instance(-1, 2, 0xEEB2D437, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ScenarioStepMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sshhhhbbi";
        static uint8 const arraySizes[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[9] = { "", "", uint16(0), uint16(0), uint16(0), uint16(0), uint8(0), uint8(0), uint32(0) };
        static DB2Meta instance(-1, 9, 0x7E9FAC31, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SceneScriptMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sshh";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[4] = { "", "", uint16(0), uint16(0) };
        static DB2Meta instance(-1, 4, 0x49EEB338, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SceneScriptPackageMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2FieldDefault const fieldDefaults[1] = { "" };
        static DB2Meta instance(-1, 1, 0x3904DB9E, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SceneScriptPackageMemberMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhhb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[4] = { uint16(0), uint16(0), uint16(0), uint8(0) };
        static DB2Meta instance(-1, 4, 0x106EBEE9, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ScheduledIntervalMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiii";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[5] = { uint32(0), uint32(0), uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 5, 0x0E1CD95F, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ScheduledWorldStateMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiiiiii";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[8] = { uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 8, 0xF79BBEDA, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ScheduledWorldStateGroupMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiii";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[5] = { uint32(0), uint32(0), uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 5, 0x7DAC0988, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ScheduledWorldStateXUniqCatMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(0, 3, 0x35A6F286, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ScreenEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sihhhhbbbiii";
        static uint8 const arraySizes[12] = { 1, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[12] = { "", uint32(0), uint16(0), uint16(0), uint16(0), uint16(0), uint8(0), uint8(0), uint8(0), uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 12, 0x6BAE60BD, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ScreenLocationMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2FieldDefault const fieldDefaults[1] = { "" };
        static DB2Meta instance(-1, 1, 0x3904DB9E, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SeamlessSiteMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i";
        static uint8 const arraySizes[1] = { 1 };
        static DB2FieldDefault const fieldDefaults[1] = { uint32(0) };
        static DB2Meta instance(-1, 1, 0x62865AB2, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ServerMessagesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2FieldDefault const fieldDefaults[1] = { "" };
        static DB2Meta instance(-1, 1, 0xBF18B426, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ShadowyEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iifffffffbb";
        static uint8 const arraySizes[11] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[11] = { uint32(0), uint32(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 11, 0x64A913F2, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SkillLineMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssshbbii";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[8] = { "", "", "", uint16(0), uint8(0), uint8(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 8, 0x1BD123BF, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SkillLineAbilityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiihhhhhhbbbi";
        static uint8 const arraySizes[13] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[13] = { uint32(0), uint32(0), uint32(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint8(0), uint8(0), uint8(0), uint32(0) };
        static DB2Meta instance(-1, 13, 0x52975082, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SkillRaceClassInfoMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihhhbbi";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[7] = { uint32(0), uint16(0), uint16(0), uint16(0), uint8(0), uint8(0), uint32(0) };
        static DB2Meta instance(-1, 7, 0x83AE7FF7, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SoundAmbienceMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "biii";
        static uint8 const arraySizes[4] = { 1, 2, 1, 1 };
        static DB2FieldDefault const fieldDefaults[4] = { uint8(0), uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 4, 0x7B848517, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SoundAmbienceFlavorMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { uint16(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 3, 0x62F54C8C, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SoundBusMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fhbbbbbi";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[8] = { float(0), uint16(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint32(0) };
        static DB2Meta instance(7, 8, 0x4B191162, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SoundBusOverrideMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ifbbbii";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[7] = { uint32(0), float(0), uint8(0), uint8(0), uint8(0), uint32(0), uint32(0) };
        static DB2Meta instance(0, 7, 0xFDAA0F97, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SoundEmitterPillPointsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fh";
        static uint8 const arraySizes[2] = { 3, 1 };
        static DB2FieldDefault const fieldDefaults[2] = { float(0), uint16(0) };
        static DB2Meta instance(-1, 2, 0x39121A39, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SoundEmittersMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffshhhbbbiii";
        static uint8 const arraySizes[12] = { 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[12] = { float(0), float(0), "", uint16(0), uint16(0), uint16(0), uint8(0), uint8(0), uint8(0), uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(9, 12, 0xE270720C, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SoundFilterMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2FieldDefault const fieldDefaults[1] = { "" };
        static DB2Meta instance(-1, 1, 0x3904DB9E, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SoundFilterElemMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fbb";
        static uint8 const arraySizes[3] = { 9, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { float(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 3, 0x17D9566E, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SoundKitMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sffffffffhhhbbbbi";
        static uint8 const arraySizes[17] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[17] = { "", float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), uint16(0), uint16(0), uint16(0), uint8(0), uint8(0), uint8(0), uint8(0), uint32(0) };
        static DB2Meta instance(16, 17, 0xD0C5E77B, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SoundKitAdvancedMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fiiiiiifffffiiffffffihbbbbiiiiii";
        static uint8 const arraySizes[32] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[32] = { float(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), float(0), float(0), float(0), float(0), float(0), uint32(0), uint32(0), float(0), float(0), float(0), float(0), float(0), float(0), uint32(0), uint16(0), uint8(0), uint8(0), uint8(0), uint8(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 32, 0xE365C92B, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SoundKitChildMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ii";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2FieldDefault const fieldDefaults[2] = { uint32(0), uint32(0) };
        static DB2Meta instance(-1, 2, 0xEC08C629, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SoundKitEntryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ifbi";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[4] = { uint32(0), float(0), uint8(0), uint32(0) };
        static DB2Meta instance(-1, 4, 0x78A32CE1, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SoundKitFallbackMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ii";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2FieldDefault const fieldDefaults[2] = { uint32(0), uint32(0) };
        static DB2Meta instance(-1, 2, 0x37114C5F, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SoundOverrideMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhhb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[4] = { uint16(0), uint16(0), uint16(0), uint8(0) };
        static DB2Meta instance(-1, 4, 0x2EEBF2F8, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SoundProviderPreferencesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sfffffffffffffffhhhhhbb";
        static uint8 const arraySizes[23] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[23] = { "", float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 23, 0x67B76B4D, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SourceInfoMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "isbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[4] = { uint32(0), "", uint8(0), uint8(0) };
        static DB2Meta instance(-1, 4, 0x5CBB0CF1, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SpamMessagesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2FieldDefault const fieldDefaults[1] = { "" };
        static DB2Meta instance(-1, 1, 0xAFEA48C6, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SpecializationSpellsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iishbi";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[6] = { uint32(0), uint32(0), "", uint16(0), uint8(0), uint32(0) };
        static DB2Meta instance(5, 6, 0x25DB72F3, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SpellMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssssiii";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[7] = { "", "", "", "", uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(5, 7, 0xEBFC7B2F, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SpellActionBarPrefMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ih";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2FieldDefault const fieldDefaults[2] = { uint32(0), uint16(0) };
        static DB2Meta instance(-1, 2, 0xE575AC95, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SpellActivationOverlayMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiifibbi";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 4, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[8] = { uint32(0), uint32(0), uint32(0), float(0), uint32(0), uint8(0), uint8(0), uint32(0) };
        static DB2Meta instance(-1, 8, 0x19C2E363, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SpellAuraOptionsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiihbbb";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[8] = { uint32(0), uint32(0), uint32(0), uint32(0), uint16(0), uint8(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 8, 0x41785ED1, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SpellAuraRestrictionsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiiibbbbb";
        static uint8 const arraySizes[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[10] = { uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 10, 0x2F389373, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SpellAuraVisXChrSpecMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hh";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2FieldDefault const fieldDefaults[2] = { uint16(0), uint16(0) };
        static DB2Meta instance(-1, 2, 0x598B6692, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SpellAuraVisibilityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ibbi";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[4] = { uint32(0), uint8(0), uint8(0), uint32(0) };
        static DB2Meta instance(3, 4, 0x37B086CE, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SpellCastTimesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iih";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { uint32(0), uint32(0), uint16(0) };
        static DB2Meta instance(-1, 3, 0xAF90DE83, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SpellCastingRequirementsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihhhbbb";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[7] = { uint32(0), uint16(0), uint16(0), uint16(0), uint8(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 7, 0xF6016D9C, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SpellCategoriesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihhhbbbbb";
        static uint8 const arraySizes[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[9] = { uint32(0), uint16(0), uint16(0), uint16(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 9, 0xD10E84D7, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SpellCategoryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sibbbi";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[6] = { "", uint32(0), uint8(0), uint8(0), uint8(0), uint32(0) };
        static DB2Meta instance(-1, 6, 0x0D6146A0, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SpellChainEffectsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fffiiffffffffffffffffffffffffffffffffffiffshhhhbbbbbbbbbbii";
        static uint8 const arraySizes[59] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 11, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3 };
        static DB2FieldDefault const fieldDefaults[59] = { float(0), float(0), float(0), uint32(0), uint32(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), uint32(0), float(0), float(0), "", uint16(0), uint16(0), uint16(0), uint16(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 59, 0x96AA6737, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SpellClassOptionsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iibi";
        static uint8 const arraySizes[4] = { 1, 4, 1, 1 };
        static DB2FieldDefault const fieldDefaults[4] = { uint32(0), uint32(0), uint8(0), uint32(0) };
        static DB2Meta instance(-1, 4, 0x3BE81516, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SpellCooldownsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiib";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[5] = { uint32(0), uint32(0), uint32(0), uint32(0), uint8(0) };
        static DB2Meta instance(-1, 5, 0x95FA67DF, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SpellDescriptionVariablesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2FieldDefault const fieldDefaults[1] = { "" };
        static DB2Meta instance(-1, 1, 0x4B8C883A, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SpellDispelTypeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[4] = { "", "", uint8(0), uint8(0) };
        static DB2Meta instance(-1, 4, 0xE2AA3CC1, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SpellDurationMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 3, 0xA41CBED3, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SpellEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiiiiiiiiififfiiiiffififf";
        static uint8 const arraySizes[26] = { 4, 1, 1, 1, 1, 1, 1, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[26] = { uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), float(0), uint32(0), float(0), float(1), uint32(0), uint32(0), uint32(0), uint32(0), float(0), float(0), uint32(0), float(0), uint32(0), float(0), float(1) };
        static DB2Meta instance(1, 26, 0xD6D07FDD, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SpellEffectEmissionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffhb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[4] = { float(0), float(0), uint16(0), uint8(0) };
        static DB2Meta instance(-1, 4, 0xC3341591, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SpellEffectGroupSizeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "if";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2FieldDefault const fieldDefaults[2] = { uint32(0), float(0) };
        static DB2Meta instance(-1, 2, 0x923E253D, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SpellEffectScalingMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fffi";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[4] = { float(0), float(0), float(0), uint32(0) };
        static DB2Meta instance(-1, 4, 0x904C49AB, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SpellEquippedItemsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiib";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[4] = { uint32(0), uint32(0), uint32(0), uint8(0) };
        static DB2Meta instance(-1, 4, 0x2DFDFA1C, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SpellFlyoutMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "issbii";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[6] = { uint32(0), "", "", uint8(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 6, 0x7F571FDD, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SpellFlyoutItemMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ibb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { uint32(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 3, 0x4B16566A, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SpellFocusObjectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2FieldDefault const fieldDefaults[1] = { "" };
        static DB2Meta instance(-1, 1, 0x3904DB9E, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SpellInterruptsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiihb";
        static uint8 const arraySizes[5] = { 1, 2, 2, 1, 1 };
        static DB2FieldDefault const fieldDefaults[5] = { uint32(0), uint32(0), uint32(0), uint16(0), uint8(0) };
        static DB2Meta instance(-1, 5, 0x617FAC67, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SpellItemEnchantmentMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "isfiihhhhhhbbbbbbbi";
        static uint8 const arraySizes[19] = { 3, 1, 3, 1, 1, 3, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[19] = { uint32(0), "", float(0), uint32(0), uint32(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint32(0) };
        static DB2Meta instance(-1, 19, 0x39848BCB, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SpellItemEnchantmentConditionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbbbbi";
        static uint8 const arraySizes[6] = { 5, 5, 5, 5, 5, 5 };
        static DB2FieldDefault const fieldDefaults[6] = { uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint32(0) };
        static DB2Meta instance(-1, 6, 0xEF6322FD, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SpellKeyboundOverrideMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "isb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { uint32(0), "", uint8(0) };
        static DB2Meta instance(-1, 3, 0x9E91C799, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SpellLabelMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ii";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2FieldDefault const fieldDefaults[2] = { uint32(0), uint32(0) };
        static DB2Meta instance(-1, 2, 0xEF1E888C, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SpellLearnSpellMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 3, 0xF49DE0EB, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SpellLevelsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihhhbb";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[6] = { uint32(0), uint16(0), uint16(0), uint16(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 6, 0xDE445A89, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SpellMechanicMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2FieldDefault const fieldDefaults[1] = { "" };
        static DB2Meta instance(-1, 1, 0x4F68BCAD, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SpellMiscMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iffhhhbii";
        static uint8 const arraySizes[9] = { 14, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[9] = { uint32(0), float(0), float(0), uint16(0), uint16(0), uint16(0), uint8(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 9, 0xCF15456A, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SpellMiscDifficultyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ibi";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { uint32(0), uint8(0), uint32(0) };
        static DB2Meta instance(2, 3, 0x15277128, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SpellMissileMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ifffffffffffffb";
        static uint8 const arraySizes[15] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[15] = { uint32(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), uint8(0) };
        static DB2Meta instance(-1, 15, 0xD15D882B, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SpellMissileMotionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[4] = { "", "", uint8(0), uint8(0) };
        static DB2Meta instance(-1, 4, 0xB4A475EB, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SpellPowerMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiffifbbiiiiii";
        static uint8 const arraySizes[14] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[14] = { uint32(0), uint32(0), float(0), float(0), uint32(0), float(0), uint8(0), uint8(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(8, 14, 0x7E56F4D6, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SpellPowerDifficultyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbi";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { uint8(0), uint8(0), uint32(0) };
        static DB2Meta instance(2, 3, 0xCE90A34A, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SpellProceduralEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fbi";
        static uint8 const arraySizes[3] = { 4, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { float(0), uint8(0), uint32(0) };
        static DB2Meta instance(2, 3, 0xB92EDA80, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SpellProcsPerMinuteMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2FieldDefault const fieldDefaults[2] = { float(0), uint8(0) };
        static DB2Meta instance(-1, 2, 0x8B1DA391, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SpellProcsPerMinuteModMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fhbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[4] = { float(0), uint16(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 4, 0x777C8E87, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SpellRadiusMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffff";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[4] = { float(0), float(0), float(0), float(0) };
        static DB2Meta instance(-1, 4, 0xA7115276, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SpellRangeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffssb";
        static uint8 const arraySizes[5] = { 2, 2, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[5] = { float(0), float(0), "", "", uint8(0) };
        static DB2Meta instance(-1, 5, 0xF800EFF5, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SpellReagentsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iih";
        static uint8 const arraySizes[3] = { 1, 8, 8 };
        static DB2FieldDefault const fieldDefaults[3] = { uint32(0), uint32(0), uint16(0) };
        static DB2Meta instance(-1, 3, 0x56EDE5AB, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SpellReagentsCurrencyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihh";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { uint32(0), uint16(0), uint16(0) };
        static DB2Meta instance(-1, 3, 0xB1B6E25D, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SpellScalingMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihiii";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[5] = { uint32(0), uint16(0), uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 5, 0x9ED127A4, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SpellShapeshiftMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiib";
        static uint8 const arraySizes[4] = { 1, 2, 2, 1 };
        static DB2FieldDefault const fieldDefaults[4] = { uint32(0), uint32(0), uint32(0), uint8(0) };
        static DB2Meta instance(-1, 4, 0x1DDAC1DB, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SpellShapeshiftFormMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sfihhbbiii";
        static uint8 const arraySizes[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 4, 8 };
        static DB2FieldDefault const fieldDefaults[10] = { "", float(0), uint32(0), uint16(0), uint16(0), uint8(0), uint8(0), uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 10, 0x3B74E677, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SpellSpecialUnitEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hi";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2FieldDefault const fieldDefaults[2] = { uint16(0), uint32(0) };
        static DB2Meta instance(-1, 2, 0x3E8DA6A5, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SpellTargetRestrictionsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iffihbbi";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[8] = { uint32(0), float(0), float(0), uint32(0), uint16(0), uint8(0), uint8(0), uint32(0) };
        static DB2Meta instance(-1, 8, 0x14146B0A, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SpellTotemsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iih";
        static uint8 const arraySizes[3] = { 1, 2, 2 };
        static DB2FieldDefault const fieldDefaults[3] = { uint32(0), uint32(0), uint16(0) };
        static DB2Meta instance(-1, 3, 0xC384E067, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SpellVisualMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iffhhbbiiiiiiiiiiiiiiiiiiiiiii";
        static uint8 const arraySizes[30] = { 1, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[30] = { uint32(0), float(0), float(0), uint16(0), uint16(0), uint8(0), uint8(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(7, 30, 0x8E440CD2, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SpellVisualAnimMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhh";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { uint16(0), uint16(0), uint16(0) };
        static DB2Meta instance(-1, 3, 0x999CD8F6, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SpellVisualColorEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fifhhhhhbbi";
        static uint8 const arraySizes[11] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[11] = { float(0), uint32(0), float(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint8(0), uint8(0), uint32(0) };
        static DB2Meta instance(-1, 11, 0x59B20857, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SpellVisualEffectNameMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sffffffiiibii";
        static uint8 const arraySizes[13] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[13] = { "", float(0), float(0), float(0), float(0), float(0), float(0), uint32(0), uint32(0), uint32(0), uint8(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 13, 0x1FBC2750, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SpellVisualKitMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ifhhi";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[5] = { uint32(0), float(0), uint16(0), uint16(0), uint32(0) };
        static DB2Meta instance(-1, 5, 0x73E2BF35, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SpellVisualKitAreaModelMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ifffhb";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[6] = { uint32(0), float(0), float(0), float(0), uint16(0), uint8(0) };
        static DB2Meta instance(-1, 6, 0xB1470E0F, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SpellVisualKitEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 3, 0xA0F573D3, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SpellVisualKitModelAttachMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iffhbbihffffffffhhhhif";
        static uint8 const arraySizes[22] = { 1, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[22] = { uint32(0), float(0), float(0), uint16(0), uint8(0), uint8(0), uint32(0), uint16(0), float(0), float(0), float(0), float(0), float(0), float(0), float(1), float(0), uint16(65535), uint16(65535), uint16(65535), uint16(0), uint32(0), float(0) };
        static DB2Meta instance(6, 22, 0x84E65313, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SpellVisualMissileMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiffhhhhhhbbiii";
        static uint8 const arraySizes[16] = { 1, 1, 1, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[16] = { uint32(0), uint32(0), uint32(0), float(0), float(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint8(0), uint8(0), uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(13, 16, 0x5BC97153, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SpellXSpellVisualMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiifhhhhiibbb";
        static uint8 const arraySizes[13] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[13] = { uint32(0), uint32(0), uint32(0), float(1), uint16(0), uint16(0), uint16(0), uint16(0), uint32(0), uint32(0), uint8(0), uint8(0), uint8(0) };
        static DB2Meta instance(2, 13, 0xC8455F07, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct StartupFilesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 3, 0x3DDEE73C, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct Startup_StringsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ss";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2FieldDefault const fieldDefaults[2] = { "", "" };
        static DB2Meta instance(-1, 2, 0x57A2EA45, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct StationeryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbi";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { "", uint8(0), uint32(0) };
        static DB2Meta instance(-1, 3, 0xFC4B1219, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct StringLookupsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2FieldDefault const fieldDefaults[1] = { "" };
        static DB2Meta instance(-1, 1, 0x2273F460, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct SummonPropertiesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiii";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[5] = { uint32(0), uint32(0), uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 5, 0x431AC5BD, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct TactKeyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "b";
        static uint8 const arraySizes[1] = { 16 };
        static DB2FieldDefault const fieldDefaults[1] = { uint8(0) };
        static DB2Meta instance(-1, 1, 0x93982C41, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct TactKeyLookupMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "b";
        static uint8 const arraySizes[1] = { 8 };
        static DB2FieldDefault const fieldDefaults[1] = { uint8(0) };
        static DB2Meta instance(-1, 1, 0xDEB96A09, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct TalentMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iishbbbbb";
        static uint8 const arraySizes[9] = { 1, 1, 1, 1, 1, 1, 1, 2, 1 };
        static DB2FieldDefault const fieldDefaults[9] = { uint32(0), uint32(0), "", uint16(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 9, 0xED04256B, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct TaxiNodesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fsifhhhbi";
        static uint8 const arraySizes[9] = { 3, 1, 2, 2, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[9] = { float(0), "", uint32(0), float(0), uint16(0), uint16(0), uint16(0), uint8(0), uint32(0) };
        static DB2Meta instance(8, 9, 0x7F24204C, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct TaxiPathMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhii";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[4] = { uint16(0), uint16(0), uint32(0), uint32(0) };
        static DB2Meta instance(2, 4, 0xCD215FC7, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct TaxiPathNodeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fihhhhbbi";
        static uint8 const arraySizes[9] = { 3, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[9] = { float(0), uint32(0), uint16(0), uint16(0), uint16(0), uint16(0), uint8(0), uint8(0), uint32(0) };
        static DB2Meta instance(8, 9, 0x5D49C8E0, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct TerrainMaterialMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { "", "", uint8(0) };
        static DB2Meta instance(-1, 3, 0x49A78572, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct TerrainTypeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shhbb";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[5] = { "", uint16(0), uint16(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 5, 0x88A1087E, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct TerrainTypeSoundsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2FieldDefault const fieldDefaults[1] = { "" };
        static DB2Meta instance(-1, 1, 0x8730DCFE, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct TextureBlendSetMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ifffffbbbb";
        static uint8 const arraySizes[10] = { 3, 3, 3, 3, 3, 4, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[10] = { uint32(0), float(0), float(0), float(0), float(0), float(0), uint8(0), uint8(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 10, 0x5BFDA3B4, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct TextureFileDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ibi";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { uint32(0), uint8(0), uint32(0) };
        static DB2Meta instance(2, 3, 0x35167055, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct TotemCategoryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sib";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { "", uint32(0), uint8(0) };
        static DB2Meta instance(-1, 3, 0x789625BB, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ToyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "isbbi";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[5] = { uint32(0), "", uint8(0), uint8(0), uint32(0) };
        static DB2Meta instance(4, 5, 0xC6934651, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct TradeSkillCategoryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shhhb";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[5] = { "", uint16(0), uint16(0), uint16(0), uint8(0) };
        static DB2Meta instance(-1, 5, 0x6F15EA1C, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct TradeSkillItemMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2FieldDefault const fieldDefaults[2] = { uint16(0), uint8(0) };
        static DB2Meta instance(-1, 2, 0x3E65917A, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct TransformMatrixMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fffff";
        static uint8 const arraySizes[5] = { 3, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[5] = { float(0), float(0), float(0), float(0), float(0) };
        static DB2Meta instance(-1, 5, 0xAA37BA84, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct TransmogHolidayMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ii";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2FieldDefault const fieldDefaults[2] = { uint32(0), uint32(0) };
        static DB2Meta instance(0, 2, 0x70F0928A, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct TransmogSetMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shhbiiiiii";
        static uint8 const arraySizes[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[10] = { "", uint16(0), uint16(0), uint8(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(4, 10, 0xA64E0723, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct TransmogSetGroupMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "si";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2FieldDefault const fieldDefaults[2] = { "", uint32(0) };
        static DB2Meta instance(1, 2, 0x027DC3B5, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct TransmogSetItemMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiii";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[4] = { uint32(0), uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(0, 4, 0x1C481EF6, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct TransportAnimationMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iifb";
        static uint8 const arraySizes[4] = { 1, 1, 3, 1 };
        static DB2FieldDefault const fieldDefaults[4] = { uint32(0), uint32(0), float(0), uint8(0) };
        static DB2Meta instance(-1, 4, 0xAA08A913, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct TransportPhysicsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffffffffff";
        static uint8 const arraySizes[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[10] = { float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0) };
        static DB2Meta instance(-1, 10, 0x376AB472, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct TransportRotationMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iif";
        static uint8 const arraySizes[3] = { 1, 1, 4 };
        static DB2FieldDefault const fieldDefaults[3] = { uint32(0), uint32(0), float(0) };
        static DB2Meta instance(-1, 3, 0x5B310112, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct TrophyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shbi";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[4] = { "", uint16(0), uint8(0), uint32(0) };
        static DB2Meta instance(-1, 4, 0x29385F9B, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct UiCamFbackTransmogChrRaceMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hbbbb";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[5] = { uint16(0), uint8(0), uint8(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 5, 0xEFFB716F, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct UiCamFbackTransmogWeaponMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hbbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[4] = { uint16(0), uint8(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 4, 0x6E8DF14F, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct UiCameraMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sfffhbbbi";
        static uint8 const arraySizes[9] = { 1, 3, 3, 3, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[9] = { "", float(0), float(0), float(0), uint16(0), uint8(0), uint8(0), uint8(0), uint32(0) };
        static DB2Meta instance(-1, 9, 0x2F06438B, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct UiCameraTypeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { "", uint32(0), uint32(0) };
        static DB2Meta instance(-1, 3, 0x8B2D7DE5, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct UiMapPOIMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ifiihhi";
        static uint8 const arraySizes[7] = { 1, 3, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[7] = { uint32(0), float(0), uint32(0), uint32(0), uint16(0), uint16(0), uint32(0) };
        static DB2Meta instance(6, 7, 0xB7E7C56F, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct UiModelSceneMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2FieldDefault const fieldDefaults[2] = { uint8(0), uint8(0) };
        static DB2Meta instance(-1, 2, 0x2B5C21A2, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct UiModelSceneActorMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sfffffbiii";
        static uint8 const arraySizes[10] = { 1, 3, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[10] = { "", float(0), float(0), float(0), float(0), float(0), uint8(0), uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(7, 10, 0x978EC181, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct UiModelSceneActorDisplayMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fffii";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[5] = { float(0), float(0), float(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 5, 0xEF60E9F1, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct UiModelSceneCameraMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sfffffffffffbbii";
        static uint8 const arraySizes[16] = { 1, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[16] = { "", float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), uint8(0), uint8(0), uint32(0), uint32(0) };
        static DB2Meta instance(14, 16, 0xD61C5690, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct UiTextureAtlasMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihh";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { uint32(0), uint16(0), uint16(0) };
        static DB2Meta instance(-1, 3, 0xF3571B19, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct UiTextureAtlasMemberMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shhhhhb";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[7] = { "", uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint8(0) };
        static DB2Meta instance(-1, 7, 0xDDD972E0, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct UiTextureKitMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2FieldDefault const fieldDefaults[1] = { "" };
        static DB2Meta instance(-1, 1, 0x89DF6293, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct UnitBloodMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "siiiiii";
        static uint8 const arraySizes[7] = { 5, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[7] = { "", uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 7, 0xFF251107, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct UnitBloodLevelsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "b";
        static uint8 const arraySizes[1] = { 3 };
        static DB2FieldDefault const fieldDefaults[1] = { uint8(0) };
        static DB2Meta instance(-1, 1, 0x49CADABB, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct UnitConditionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ibbb";
        static uint8 const arraySizes[4] = { 8, 1, 8, 8 };
        static DB2FieldDefault const fieldDefaults[4] = { uint32(0), uint8(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 4, 0x553D556E, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct UnitPowerBarMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffiissssffhhbbii";
        static uint8 const arraySizes[16] = { 1, 1, 6, 6, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[16] = { float(0), float(0), uint32(0), uint32(0), "", "", "", "", float(0), float(0), uint16(0), uint16(0), uint8(0), uint8(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 16, 0x5D8A83F5, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct UnitTestMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssiii";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[5] = { "", "", uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(2, 5, 0x5FFDAE98, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct VehicleMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iffffffffffffffffffsssffhhhbb";
        static uint8 const arraySizes[29] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 8, 1, 3, 1, 1 };
        static DB2FieldDefault const fieldDefaults[29] = { uint32(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), "", "", "", float(0), float(0), uint16(0), uint16(0), uint16(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 29, 0xED882E60, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct VehicleSeatMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiffffffffffffffffffffffffffffffihhhhhhhhhhhhhhhhhhhbbbbbbii";
        static uint8 const arraySizes[61] = { 1, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[61] = { uint32(0), uint32(0), uint32(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), uint32(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 61, 0xEA9DC246, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct VehicleUIIndSeatMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffhb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[4] = { float(0), float(0), uint16(0), uint8(0) };
        static DB2Meta instance(-1, 4, 0xD0300612, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct VehicleUIIndicatorMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2FieldDefault const fieldDefaults[1] = { "" };
        static DB2Meta instance(-1, 1, 0x3A5FB494, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct VideoHardwareMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sshhbbbbbbbbbbiiiiiiii";
        static uint8 const arraySizes[22] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[22] = { "", "", uint16(0), uint16(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(14, 22, 0xA9321875, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct VignetteMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sffbiii";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[7] = { "", float(0), float(0), uint8(0), uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 7, 0x0398F23E, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct VocalUISoundsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbbi";
        static uint8 const arraySizes[4] = { 1, 1, 1, 2 };
        static DB2FieldDefault const fieldDefaults[4] = { uint8(0), uint8(0), uint8(0), uint32(0) };
        static DB2Meta instance(-1, 4, 0x9BA0B42F, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct WMOAreaTableMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ishhhhhhhbbbbii";
        static uint8 const arraySizes[15] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[15] = { uint32(0), "", uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint8(0), uint8(0), uint8(0), uint8(0), uint32(0), uint32(0) };
        static DB2Meta instance(13, 15, 0x09F2B3A0, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct WbAccessControlListMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shbbb";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[5] = { "", uint16(0), uint8(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 5, 0x52E15D57, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct WbCertWhitelistMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[4] = { "", uint8(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 4, 0xBF5326EA, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct WeaponImpactSoundsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbbiiii";
        static uint8 const arraySizes[7] = { 1, 1, 1, 11, 11, 11, 11 };
        static DB2FieldDefault const fieldDefaults[7] = { uint8(0), uint8(0), uint8(0), uint32(0), uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 7, 0xEBF50A99, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct WeaponSwingSounds2Meta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbi";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { uint8(0), uint8(0), uint32(0) };
        static DB2Meta instance(-1, 3, 0x673C95BC, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct WeaponTrailMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ifffiffff";
        static uint8 const arraySizes[9] = { 1, 1, 1, 1, 3, 3, 3, 3, 3 };
        static DB2FieldDefault const fieldDefaults[9] = { uint32(0), float(0), float(0), float(0), uint32(0), float(0), float(0), float(0), float(0) };
        static DB2Meta instance(-1, 9, 0xB7A023AF, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct WeaponTrailModelDefMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihh";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { uint32(0), uint16(0), uint16(0) };
        static DB2Meta instance(-1, 3, 0x3C200963, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct WeaponTrailParamMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fffffhbbbb";
        static uint8 const arraySizes[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[10] = { float(0), float(0), float(0), float(0), float(0), uint16(0), uint8(0), uint8(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 10, 0x7B0FCD36, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct WeatherMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fffsfffffhbbbi";
        static uint8 const arraySizes[14] = { 2, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[14] = { float(0), float(0), float(0), "", float(0), float(0), float(0), float(0), float(0), uint16(0), uint8(0), uint8(0), uint8(0), uint32(0) };
        static DB2Meta instance(-1, 14, 0xC40545BA, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct WindSettingsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fffffffffb";
        static uint8 const arraySizes[10] = { 1, 3, 1, 1, 3, 1, 3, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[10] = { float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), float(0), uint8(0) };
        static DB2Meta instance(-1, 10, 0x2A355F82, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct WmoMinimapTextureMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihhbb";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[5] = { uint32(0), uint16(0), uint16(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 5, 0x5193E175, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct WorldBossLockoutMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sh";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2FieldDefault const fieldDefaults[2] = { "", uint16(0) };
        static DB2Meta instance(-1, 2, 0x663E9CD8, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct WorldChunkSoundsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hbbbbb";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[6] = { uint16(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 6, 0xF0C19FF2, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct WorldEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihbbii";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[6] = { uint32(0), uint16(0), uint8(0), uint8(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 6, 0xDA8BA65D, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct WorldElapsedTimerMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { "", uint8(0), uint8(0) };
        static DB2Meta instance(-1, 3, 0xB4A23411, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct WorldMapAreaMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sffffhhhhhhbbbbii";
        static uint8 const arraySizes[17] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[17] = { "", float(0), float(0), float(0), float(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint8(0), uint8(0), uint8(0), uint8(0), uint32(0), uint32(0) };
        static DB2Meta instance(15, 17, 0x432C75FC, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct WorldMapContinentMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffffhhbbbbb";
        static uint8 const arraySizes[11] = { 2, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[11] = { float(0), float(0), float(0), float(0), uint16(0), uint16(0), uint8(0), uint8(0), uint8(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 11, 0x5125D564, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct WorldMapOverlayMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ishhiiiiiiiiii";
        static uint8 const arraySizes[14] = { 1, 1, 1, 1, 1, 4, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[14] = { uint32(0), "", uint16(0), uint16(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(0, 14, 0x0A93D579, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct WorldMapTransformsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fffhhhhhb";
        static uint8 const arraySizes[9] = { 6, 2, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[9] = { float(0), float(0), float(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint8(0) };
        static DB2Meta instance(-1, 9, 0x24A4E819, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct WorldSafeLocsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffsh";
        static uint8 const arraySizes[4] = { 3, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[4] = { float(0), float(0), "", uint16(0) };
        static DB2Meta instance(-1, 4, 0xF93B18FC, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct WorldStateExpressionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2FieldDefault const fieldDefaults[1] = { "" };
        static DB2Meta instance(-1, 1, 0x03FDF733, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct WorldStateUIMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sssssshhhhhhbbbi";
        static uint8 const arraySizes[16] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[16] = { "", "", "", "", "", "", uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint8(0), uint8(0), uint8(0), uint32(0) };
        static DB2Meta instance(15, 16, 0xC5B480F0, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct WorldStateZoneSoundsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihhhhhhb";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[8] = { uint32(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint8(0) };
        static DB2Meta instance(-1, 8, 0x64FD3227, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct World_PVP_AreaMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhhhhbb";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[7] = { uint16(0), uint16(0), uint16(0), uint16(0), uint16(0), uint8(0), uint8(0) };
        static DB2Meta instance(-1, 7, 0x95A9D694, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ZoneIntroMusicTableMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shbi";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[4] = { "", uint16(0), uint8(0), uint32(0) };
        static DB2Meta instance(-1, 4, 0x55275147, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ZoneLightMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shh";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { "", uint16(0), uint16(0) };
        static DB2Meta instance(-1, 3, 0x7563563C, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ZoneLightPointMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fhb";
        static uint8 const arraySizes[3] = { 2, 1, 1 };
        static DB2FieldDefault const fieldDefaults[3] = { float(0), uint16(0), uint8(0) };
        static DB2Meta instance(-1, 3, 0x43EC5BFD, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

struct ZoneMusicMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "siii";
        static uint8 const arraySizes[4] = { 1, 2, 2, 2 };
        static DB2FieldDefault const fieldDefaults[4] = { "", uint32(0), uint32(0), uint32(0) };
        static DB2Meta instance(-1, 4, 0x526CEF03, types, arraySizes, fieldDefaults);
        return &instance;
    }
};

#endif // DB2Metadata_h__
