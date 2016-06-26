/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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
        static char const* types = "ssishhhhhhhbbbi";
        static uint8 const arraySizes[15] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(14, 15, 0x057D1672, types, arraySizes);
        return &instance;
    }
};

struct Achievement_CategoryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shbi";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(3, 4, 0x5F7AFA62, types, arraySizes);
        return &instance;
    }
};

struct AdventureJournalMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sssiisshhhhhhbbbbbbbbb";
        static uint8 const arraySizes[22] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1 };
        static DB2Meta instance(-1, 22, 0xA6E97BED, types, arraySizes);
        return &instance;
    }
};

struct AdventureMapPOIMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fissbiiiiiiii";
        static uint8 const arraySizes[13] = { 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 13, 0x1BFEDEA5, types, arraySizes);
        return &instance;
    }
};

struct AnimKitMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihh";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x2BD42EF8, types, arraySizes);
        return &instance;
    }
};

struct AnimKitBoneSetMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbbbb";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x9A2DD037, types, arraySizes);
        return &instance;
    }
};

struct AnimKitBoneSetAliasMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xD2683E5C, types, arraySizes);
        return &instance;
    }
};

struct AnimKitConfigMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xAB996914, types, arraySizes);
        return &instance;
    }
};

struct AnimKitConfigBoneSetMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xC8D4518B, types, arraySizes);
        return &instance;
    }
};

struct AnimKitPriorityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "b";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xF32FA71F, types, arraySizes);
        return &instance;
    }
};

struct AnimKitSegmentMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiifihhhbbbbbbbi";
        static uint8 const arraySizes[16] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 16, 0x8E562093, types, arraySizes);
        return &instance;
    }
};

struct AnimReplacementMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhhh";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x2E145FA3, types, arraySizes);
        return &instance;
    }
};

struct AnimReplacementSetMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "b";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xAAFA7852, types, arraySizes);
        return &instance;
    }
};

struct AnimationDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sihhb";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x541FCB2C, types, arraySizes);
        return &instance;
    }
};

struct AreaGroupMemberMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hh";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x61DEFC72, types, arraySizes);
        return &instance;
    }
};

struct AreaPOIMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fsshhhhhhbbbi";
        static uint8 const arraySizes[13] = { 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 13, 0xF56B4ECA, types, arraySizes);
        return &instance;
    }
};

struct AreaPOIStateMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shbbi";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x9ACE5A2C, types, arraySizes);
        return &instance;
    }
};

struct AreaTableMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iSfshhhhhhhhhhbbbbbbbbi";
        static uint8 const arraySizes[23] = { 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 23, 0xFCC856E3, types, arraySizes);
        return &instance;
    }
};

struct AreaTriggerMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffffffhhhhhbbbi";
        static uint8 const arraySizes[15] = { 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(14, 15, 0x33CB66C0, types, arraySizes);
        return &instance;
    }
};

struct AreaTriggerActionSetMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "h";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x62C25555, types, arraySizes);
        return &instance;
    }
};

struct AreaTriggerBoxMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "f";
        static uint8 const arraySizes[1] = { 3 };
        static DB2Meta instance(-1, 1, 0x5727C7CE, types, arraySizes);
        return &instance;
    }
};

struct AreaTriggerCylinderMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fff";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x32D70665, types, arraySizes);
        return &instance;
    }
};

struct AreaTriggerSphereMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "f";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xF3855A07, types, arraySizes);
        return &instance;
    }
};

struct ArmorLocationMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fffff";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x7D19CBE6, types, arraySizes);
        return &instance;
    }
};

struct ArtifactMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "siiihhbb";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 8, 0x0B635E27, types, arraySizes);
        return &instance;
    }
};

struct ArtifactAppearanceMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "siffihhhbbbbiii";
        static uint8 const arraySizes[15] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(12, 15, 0x269F6469, types, arraySizes);
        return &instance;
    }
};

struct ArtifactAppearanceSetMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sshhbbbbi";
        static uint8 const arraySizes[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(8, 9, 0xB11A5708, types, arraySizes);
        return &instance;
    }
};

struct ArtifactCategoryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hh";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x015DF345, types, arraySizes);
        return &instance;
    }
};

struct ArtifactPowerMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fbbbii";
        static uint8 const arraySizes[6] = { 2, 1, 1, 1, 1, 1 };
        static DB2Meta instance(4, 6, 0xDF650D3E, types, arraySizes);
        return &instance;
    }
};

struct ArtifactPowerLinkMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hh";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x01233BBC, types, arraySizes);
        return &instance;
    }
};

struct ArtifactPowerRankMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ifhhb";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0xB4D8591A, types, arraySizes);
        return &instance;
    }
};

struct ArtifactQuestXPMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i";
        static uint8 const arraySizes[1] = { 10 };
        static DB2Meta instance(-1, 1, 0x24504CBE, types, arraySizes);
        return &instance;
    }
};

struct ArtifactUnlockMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhbbi";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x5F27F07F, types, arraySizes);
        return &instance;
    }
};

struct AuctionHouseMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x554432EF, types, arraySizes);
        return &instance;
    }
};

struct BankBagSlotPricesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x10058492, types, arraySizes);
        return &instance;
    }
};

struct BannedAddOnsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "SSb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xC0BBE91D, types, arraySizes);
        return &instance;
    }
};

struct BarberShopStyleMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssfbbbbi";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(7, 8, 0x39C1F86E, types, arraySizes);
        return &instance;
    }
};

struct BattlePetAbilityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "isshbbi";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0x5B7B567E, types, arraySizes);
        return &instance;
    }
};

struct BattlePetAbilityEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhhhhbi";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 6, 1, 1 };
        static DB2Meta instance(6, 7, 0x3273A2ED, types, arraySizes);
        return &instance;
    }
};

struct BattlePetAbilityStateMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xD2BE6D5C, types, arraySizes);
        return &instance;
    }
};

struct BattlePetAbilityTurnMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhbbbi";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(5, 6, 0x39FDB23F, types, arraySizes);
        return &instance;
    }
};

struct BattlePetBreedQualityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xC3D0125D, types, arraySizes);
        return &instance;
    }
};

struct BattlePetBreedStateMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hbb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x4AC36A1D, types, arraySizes);
        return &instance;
    }
};

struct BattlePetEffectPropertiesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shb";
        static uint8 const arraySizes[3] = { 6, 1, 6 };
        static DB2Meta instance(-1, 3, 0x891BD229, types, arraySizes);
        return &instance;
    }
};

struct BattlePetNPCTeamMemberMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x67818447, types, arraySizes);
        return &instance;
    }
};

struct BattlePetSpeciesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiisshbbi";
        static uint8 const arraySizes[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(8, 9, 0xA44A31E4, types, arraySizes);
        return &instance;
    }
};

struct BattlePetSpeciesStateMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x0D345864, types, arraySizes);
        return &instance;
    }
};

struct BattlePetSpeciesXAbilityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x563A7D2A, types, arraySizes);
        return &instance;
    }
};

struct BattlePetStateMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xDE5B505E, types, arraySizes);
        return &instance;
    }
};

struct BattlePetVisualMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shhhhbb";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0x8DAD67C6, types, arraySizes);
        return &instance;
    }
};

struct BattlemasterListMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sishhhbbbbbbbbb";
        static uint8 const arraySizes[15] = { 1, 1, 1, 16, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 15, 0xF61E6A94, types, arraySizes);
        return &instance;
    }
};

struct BoneWindModifierModelMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ii";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x784E6052, types, arraySizes);
        return &instance;
    }
};

struct BoneWindModifiersMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ff";
        static uint8 const arraySizes[2] = { 3, 1 };
        static DB2Meta instance(-1, 2, 0x305E43BE, types, arraySizes);
        return &instance;
    }
};

struct BountyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihhb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x0478B1B1, types, arraySizes);
        return &instance;
    }
};

struct BountySetMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hh";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x664666E1, types, arraySizes);
        return &instance;
    }
};

struct BroadcastTextMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sshhhbbii";
        static uint8 const arraySizes[9] = { 1, 1, 3, 3, 1, 1, 1, 2, 1 };
        static DB2Meta instance(-1, 9, 0x4B97C103, types, arraySizes);
        return &instance;
    }
};

struct CameraEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "b";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xA898408A, types, arraySizes);
        return &instance;
    }
};

struct CameraEffectEntryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffffffffhhbbbbbb";
        static uint8 const arraySizes[16] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 16, 0x82BF9A49, types, arraySizes);
        return &instance;
    }
};

struct CameraModeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fffffhbbbbb";
        static uint8 const arraySizes[11] = { 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 11, 0x1D6DC577, types, arraySizes);
        return &instance;
    }
};

struct CameraShakesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffffbbbbi";
        static uint8 const arraySizes[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 9, 0x83DE01F4, types, arraySizes);
        return &instance;
    }
};

struct CastableRaidBuffsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ii";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x9CAA85E8, types, arraySizes);
        return &instance;
    }
};

struct Cfg_CategoriesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shbbb";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0xBAB445D5, types, arraySizes);
        return &instance;
    }
};

struct Cfg_ConfigsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fhbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x4622933F, types, arraySizes);
        return &instance;
    }
};

struct Cfg_RegionsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sib";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x63F4A5AD, types, arraySizes);
        return &instance;
    }
};

struct CharBaseInfoMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x16E3FA38, types, arraySizes);
        return &instance;
    }
};

struct CharBaseSectionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x6B5EEA0B, types, arraySizes);
        return &instance;
    }
};

struct CharComponentTextureLayoutsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hh";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xF1760594, types, arraySizes);
        return &instance;
    }
};

struct CharComponentTextureSectionsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhhhbbb";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0xABDEFA33, types, arraySizes);
        return &instance;
    }
};

struct CharHairGeosetsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ibbbbbbbbi";
        static uint8 const arraySizes[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 10, 0xC269B9B2, types, arraySizes);
        return &instance;
    }
};

struct CharSectionsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihbbbbb";
        static uint8 const arraySizes[7] = { 3, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0x9B7A7C33, types, arraySizes);
        return &instance;
    }
};

struct CharShipmentMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiiihbb";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 8, 0x268EC200, types, arraySizes);
        return &instance;
    }
};

struct CharShipmentContainerMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sshhhhhhbbbbbbbi";
        static uint8 const arraySizes[16] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 16, 0x45AF32E1, types, arraySizes);
        return &instance;
    }
};

struct CharStartOutfitMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iibbbbb";
        static uint8 const arraySizes[7] = { 24, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0xB96E2E2C, types, arraySizes);
        return &instance;
    }
};

struct CharTitlesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sshb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xECCBDBF9, types, arraySizes);
        return &instance;
    }
};

struct CharacterFaceBoneSetMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ibbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x87BC82E6, types, arraySizes);
        return &instance;
    }
};

struct CharacterFacialHairStylesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ibbb";
        static uint8 const arraySizes[4] = { 5, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xC8DFD1F8, types, arraySizes);
        return &instance;
    }
};

struct CharacterLoadoutMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ibb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xEA2447D5, types, arraySizes);
        return &instance;
    }
};

struct CharacterLoadoutItemMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ih";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x89C0A3E9, types, arraySizes);
        return &instance;
    }
};

struct ChatChannelsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "issb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x23043EC6, types, arraySizes);
        return &instance;
    }
};

struct ChatProfanityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x589CBD66, types, arraySizes);
        return &instance;
    }
};

struct ChrClassRaceSexMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbbiii";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 6, 0x8AAD17A1, types, arraySizes);
        return &instance;
    }
};

struct ChrClassTitleMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xBFB19B72, types, arraySizes);
        return &instance;
    }
};

struct ChrClassUIDisplayMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x1AFA49DF, types, arraySizes);
        return &instance;
    }
};

struct ChrClassVillainMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x0EFF13C2, types, arraySizes);
        return &instance;
    }
};

struct ChrClassesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "SsssSiiihhhbbbbbbbi";
        static uint8 const arraySizes[19] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(18, 19, 0xCFEFCD72, types, arraySizes);
        return &instance;
    }
};

struct ChrClassesXPowerTypesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x8BB8B9A3, types, arraySizes);
        return &instance;
    }
};

struct ChrRacesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iSSsssSSiiffihhhhhhhhhbbbbbbbbbbiii";
        static uint8 const arraySizes[35] = { 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3 };
        static DB2Meta instance(-1, 35, 0x6B0D0422, types, arraySizes);
        return &instance;
    }
};

struct ChrSpecializationMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "isssshbbbbbiii";
        static uint8 const arraySizes[14] = { 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(11, 14, 0xFC72AC38, types, arraySizes);
        return &instance;
    }
};

struct ChrUpgradeBucketMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hbi";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(2, 3, 0xB2B4798C, types, arraySizes);
        return &instance;
    }
};

struct ChrUpgradeBucketSpellMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ih";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xD671C191, types, arraySizes);
        return &instance;
    }
};

struct ChrUpgradeTierMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbbi";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(3, 4, 0x2ABC2F82, types, arraySizes);
        return &instance;
    }
};

struct CinematicCameraMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sffh";
        static uint8 const arraySizes[4] = { 1, 3, 1, 1 };
        static DB2Meta instance(-1, 4, 0x97F7A9AD, types, arraySizes);
        return &instance;
    }
};

struct CinematicSequencesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hh";
        static uint8 const arraySizes[2] = { 1, 8 };
        static DB2Meta instance(-1, 2, 0x8CF8A102, types, arraySizes);
        return &instance;
    }
};

struct CloakDampeningMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fffffff";
        static uint8 const arraySizes[7] = { 5, 5, 2, 2, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0x4BEFEBC2, types, arraySizes);
        return &instance;
    }
};

struct CombatConditionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhhhhbbbbbb";
        static uint8 const arraySizes[11] = { 1, 1, 1, 2, 2, 2, 2, 1, 2, 2, 1 };
        static DB2Meta instance(-1, 11, 0x01A085BE, types, arraySizes);
        return &instance;
    }
};

struct ComponentModelFileDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x9174BFE7, types, arraySizes);
        return &instance;
    }
};

struct ComponentTextureFileDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x45CD0227, types, arraySizes);
        return &instance;
    }
};

struct ConversationLineMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiihhbbb";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 8, 0x39FCD24B, types, arraySizes);
        return &instance;
    }
};

struct CreatureMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiifssssbbbb";
        static uint8 const arraySizes[12] = { 3, 1, 4, 4, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 12, 0xAA6999A9, types, arraySizes);
        return &instance;
    }
};

struct CreatureDifficultyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iihbbb";
        static uint8 const arraySizes[6] = { 1, 7, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 6, 0x6EF17698, types, arraySizes);
        return &instance;
    }
};

struct CreatureDispXUiCameraMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ih";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x5A17D4B5, types, arraySizes);
        return &instance;
    }
};

struct CreatureDisplayInfoMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iffiSiiifhhhhhhbbbbbb";
        static uint8 const arraySizes[21] = { 1, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 21, 0x4E3ED532, types, arraySizes);
        return &instance;
    }
};

struct CreatureDisplayInfoCondMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiibbiiiiiiiii";
        static uint8 const arraySizes[15] = { 1, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3 };
        static DB2Meta instance(-1, 15, 0x227D7C8A, types, arraySizes);
        return &instance;
    }
};

struct CreatureDisplayInfoExtraMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iibbbbbbbbbb";
        static uint8 const arraySizes[12] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1 };
        static DB2Meta instance(-1, 12, 0x780B4996, types, arraySizes);
        return &instance;
    }
};

struct CreatureDisplayInfoTrnMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iifh";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xDB9A44C4, types, arraySizes);
        return &instance;
    }
};

struct CreatureFamilyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffsShhbbb";
        static uint8 const arraySizes[9] = { 1, 1, 1, 1, 2, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 9, 0xC9BA80A3, types, arraySizes);
        return &instance;
    }
};

struct CreatureImmunitiesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ibbbbbiii";
        static uint8 const arraySizes[9] = { 2, 1, 1, 1, 1, 1, 1, 8, 16 };
        static DB2Meta instance(-1, 9, 0x4AFCE8AB, types, arraySizes);
        return &instance;
    }
};

struct CreatureModelDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffffffffffffffffffiiiiiiiiiiii";
        static uint8 const arraySizes[30] = { 1, 1, 1, 1, 1, 1, 1, 6, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 30, 0x676B5D95, types, arraySizes);
        return &instance;
    }
};

struct CreatureMovementInfoMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "f";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xF569713B, types, arraySizes);
        return &instance;
    }
};

struct CreatureSoundDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffbbiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii";
        static uint8 const arraySizes[37] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 5, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 37, 0x386F5FBB, types, arraySizes);
        return &instance;
    }
};

struct CreatureTypeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x62B41D78, types, arraySizes);
        return &instance;
    }
};

struct CriteriaMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiihhhbbbbb";
        static uint8 const arraySizes[11] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 11, 0x02F8C797, types, arraySizes);
        return &instance;
    }
};

struct CriteriaTreeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iishhbi";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0xB46EE452, types, arraySizes);
        return &instance;
    }
};

struct CriteriaTreeXEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hh";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xFA3C1BDE, types, arraySizes);
        return &instance;
    }
};

struct CurrencyCategoryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x3948FA3E, types, arraySizes);
        return &instance;
    }
};

struct CurrencyTypesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sSiiisbbbi";
        static uint8 const arraySizes[10] = { 1, 2, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 10, 0xDEBE9278, types, arraySizes);
        return &instance;
    }
};

struct CurveMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xE07382D4, types, arraySizes);
        return &instance;
    }
};

struct CurvePointMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fhb";
        static uint8 const arraySizes[3] = { 2, 1, 1 };
        static DB2Meta instance(-1, 3, 0xFBC72093, types, arraySizes);
        return &instance;
    }
};

struct DeathThudLookupsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbii";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xFD6ACECC, types, arraySizes);
        return &instance;
    }
};

struct DecalPropertiesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iffffffffbbiii";
        static uint8 const arraySizes[14] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 14, 0xD7E2B520, types, arraySizes);
        return &instance;
    }
};

struct DeclinedWordMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "si";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(1, 2, 0xCA0EA44E, types, arraySizes);
        return &instance;
    }
};

struct DeclinedWordCasesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbi";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x3DFEB231, types, arraySizes);
        return &instance;
    }
};

struct DestructibleModelDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhhhhbbbbbbbbbbbbbbbbb";
        static uint8 const arraySizes[22] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 22, 0x08773F4F, types, arraySizes);
        return &instance;
    }
};

struct DeviceBlacklistMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hh";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xCC3C554D, types, arraySizes);
        return &instance;
    }
};

struct DeviceDefaultSettingsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xC0EFD6F4, types, arraySizes);
        return &instance;
    }
};

struct DifficultyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbbbbbbbbbbbb";
        static uint8 const arraySizes[13] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 13, 0x7F62CC40, types, arraySizes);
        return &instance;
    }
};

struct DissolveEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fffffffbbii";
        static uint8 const arraySizes[11] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 11, 0x4CDA6220, types, arraySizes);
        return &instance;
    }
};

struct DriverBlacklistMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iihbbbb";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0x024A28A5, types, arraySizes);
        return &instance;
    }
};

struct DungeonEncounterMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sihhbbbi";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 8, 0x96AD5F03, types, arraySizes);
        return &instance;
    }
};

struct DungeonMapMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffhhbbi";
        static uint8 const arraySizes[7] = { 2, 2, 1, 1, 1, 1, 1 };
        static DB2Meta instance(6, 7, 0x5E653BAE, types, arraySizes);
        return &instance;
    }
};

struct DungeonMapChunkMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fihhh";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x681635FF, types, arraySizes);
        return &instance;
    }
};

struct DurabilityCostsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hh";
        static uint8 const arraySizes[2] = { 21, 8 };
        static DB2Meta instance(-1, 2, 0x07F62CCA, types, arraySizes);
        return &instance;
    }
};

struct DurabilityQualityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "f";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x26FFB6E5, types, arraySizes);
        return &instance;
    }
};

struct EdgeGlowEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fffffffffb";
        static uint8 const arraySizes[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 10, 0x83E5CA94, types, arraySizes);
        return &instance;
    }
};

struct EmotesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "Siihbiiii";
        static uint8 const arraySizes[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 9, 0xAF8BBDFD, types, arraySizes);
        return &instance;
    }
};

struct EmotesTextMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sh";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x290CA5E0, types, arraySizes);
        return &instance;
    }
};

struct EmotesTextDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x00659303, types, arraySizes);
        return &instance;
    }
};

struct EmotesTextSoundMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hbbbi";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x8729AA2E, types, arraySizes);
        return &instance;
    }
};

struct EnvironmentalDamageMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xFAB902E4, types, arraySizes);
        return &instance;
    }
};

struct ExhaustionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ifffsfsi";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(7, 8, 0xE3D4EEF5, types, arraySizes);
        return &instance;
    }
};

struct FactionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iifssihhhhbbbb";
        static uint8 const arraySizes[14] = { 4, 4, 2, 1, 1, 4, 1, 4, 4, 1, 2, 1, 1, 1 };
        static DB2Meta instance(-1, 14, 0x5807F583, types, arraySizes);
        return &instance;
    }
};

struct FactionGroupMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xECF45BCB, types, arraySizes);
        return &instance;
    }
};

struct FactionTemplateMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhhhbbb";
        static uint8 const arraySizes[7] = { 1, 1, 4, 4, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0x433A9F1D, types, arraySizes);
        return &instance;
    }
};

struct FootprintTexturesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "si";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(1, 2, 0x45942CAD, types, arraySizes);
        return &instance;
    }
};

struct FootstepTerrainLookupMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hbii";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xA482F51E, types, arraySizes);
        return &instance;
    }
};

struct FriendshipRepReactionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x873670B3, types, arraySizes);
        return &instance;
    }
};

struct FriendshipReputationMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ishi";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(3, 4, 0x83EDDC57, types, arraySizes);
        return &instance;
    }
};

struct FullScreenEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fffffffffffffffffffiiffffffffffffffbiii";
        static uint8 const arraySizes[39] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 39, 0x3C821CD4, types, arraySizes);
        return &instance;
    }
};

struct GMSurveyAnswersMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbi";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xDA87352E, types, arraySizes);
        return &instance;
    }
};

struct GMSurveyCurrentSurveyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "b";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x1B969F47, types, arraySizes);
        return &instance;
    }
};

struct GMSurveyQuestionsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x729BB194, types, arraySizes);
        return &instance;
    }
};

struct GMSurveySurveysMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "b";
        static uint8 const arraySizes[1] = { 15 };
        static DB2Meta instance(-1, 1, 0xE62BB37A, types, arraySizes);
        return &instance;
    }
};

struct GameObjectArtKitMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ss";
        static uint8 const arraySizes[2] = { 3, 4 };
        static DB2Meta instance(-1, 2, 0x36033AFB, types, arraySizes);
        return &instance;
    }
};

struct GameObjectDiffAnimMapMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hbbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xE26ABF27, types, arraySizes);
        return &instance;
    }
};

struct GameObjectDisplayInfoMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ifffh";
        static uint8 const arraySizes[5] = { 1, 6, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0xDD4432B9, types, arraySizes);
        return &instance;
    }
};

struct GameObjectDisplayInfoXSoundKitMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x3D787E0A, types, arraySizes);
        return &instance;
    }
};

struct GameObjectsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fffishhhhbbi";
        static uint8 const arraySizes[12] = { 3, 4, 1, 8, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(11, 12, 0x1A493E93, types, arraySizes);
        return &instance;
    }
};

struct GameTipsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xE0D1CAFF, types, arraySizes);
        return &instance;
    }
};

struct GarrAbilityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssihhbbi";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(7, 8, 0x4E5A1C8D, types, arraySizes);
        return &instance;
    }
};

struct GarrAbilityCategoryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x67818447, types, arraySizes);
        return &instance;
    }
};

struct GarrAbilityEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fffihbbbbbbi";
        static uint8 const arraySizes[12] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(11, 12, 0xF0251DA9, types, arraySizes);
        return &instance;
    }
};

struct GarrBuildingMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iissssihhhhhhhhbbbbbbiii";
        static uint8 const arraySizes[24] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 24, 0xF387E4CE, types, arraySizes);
        return &instance;
    }
};

struct GarrBuildingDoodadSetMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbbbb";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0xA06217A7, types, arraySizes);
        return &instance;
    }
};

struct GarrBuildingPlotInstMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fhhbi";
        static uint8 const arraySizes[5] = { 2, 1, 1, 1, 1 };
        static DB2Meta instance(4, 5, 0xB4E9CCFF, types, arraySizes);
        return &instance;
    }
};

struct GarrClassSpecMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssshbbbi";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(7, 8, 0xD5AAD8F5, types, arraySizes);
        return &instance;
    }
};

struct GarrClassSpecPlayerCondMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "isbiii";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 6, 0x3F748D06, types, arraySizes);
        return &instance;
    }
};

struct GarrEncounterMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "isffihi";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(6, 7, 0xE0A164CC, types, arraySizes);
        return &instance;
    }
};

struct GarrEncounterSetXEncounterMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ii";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xC8270155, types, arraySizes);
        return &instance;
    }
};

struct GarrEncounterXMechanicMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hbb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x61A32627, types, arraySizes);
        return &instance;
    }
};

struct GarrFollItemSetMemberMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihhb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x332DC097, types, arraySizes);
        return &instance;
    }
};

struct GarrFollSupportSpellMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iibi";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x26A653E1, types, arraySizes);
        return &instance;
    }
};

struct GarrFollowerMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iissiiiihhhhhhbbbbbbbbbbbbbbbbi";
        static uint8 const arraySizes[31] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(30, 31, 0x0708BDE8, types, arraySizes);
        return &instance;
    }
};

struct GarrFollowerLevelXPMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x84E433B2, types, arraySizes);
        return &instance;
    }
};

struct GarrFollowerQualityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihbbbbi";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0xA47EFC96, types, arraySizes);
        return &instance;
    }
};

struct GarrFollowerSetXFollowerMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ii";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xAAC9B70B, types, arraySizes);
        return &instance;
    }
};

struct GarrFollowerTypeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hbbbbbb";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0x83347E98, types, arraySizes);
        return &instance;
    }
};

struct GarrFollowerUICreatureMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ifhbbb";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 6, 0xE375F0A0, types, arraySizes);
        return &instance;
    }
};

struct GarrFollowerXAbilityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x55374D4B, types, arraySizes);
        return &instance;
    }
};

struct GarrMechanicMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fbi";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x79C84299, types, arraySizes);
        return &instance;
    }
};

struct GarrMechanicSetXMechanicMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(1, 3, 0x965A35A3, types, arraySizes);
        return &instance;
    }
};

struct GarrMechanicTypeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssibi";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(4, 5, 0x201D5CC7, types, arraySizes);
        return &instance;
    }
};

struct GarrMissionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iisssiiffhhhhhhbbbbbbbbbiiiii";
        static uint8 const arraySizes[29] = { 1, 1, 1, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(24, 29, 0x1FFD19BB, types, arraySizes);
        return &instance;
    }
};

struct GarrMissionTextureMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fh";
        static uint8 const arraySizes[2] = { 2, 1 };
        static DB2Meta instance(-1, 2, 0x2CFA96FC, types, arraySizes);
        return &instance;
    }
};

struct GarrMissionTypeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shh";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xCFFD0036, types, arraySizes);
        return &instance;
    }
};

struct GarrMissionXEncounterMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "biiii";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(1, 5, 0xEDE238C4, types, arraySizes);
        return &instance;
    }
};

struct GarrMissionXFollowerMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xE2A30EE5, types, arraySizes);
        return &instance;
    }
};

struct GarrMssnBonusAbilityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fihbb";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x28358C8A, types, arraySizes);
        return &instance;
    }
};

struct GarrPlotMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "siibbbi";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 2 };
        static DB2Meta instance(-1, 7, 0x4F7D215C, types, arraySizes);
        return &instance;
    }
};

struct GarrPlotBuildingMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x31EE8F1A, types, arraySizes);
        return &instance;
    }
};

struct GarrPlotInstanceMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x0CE6FE07, types, arraySizes);
        return &instance;
    }
};

struct GarrPlotUICategoryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x784D025A, types, arraySizes);
        return &instance;
    }
};

struct GarrSiteLevelMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fhhhhbbbb";
        static uint8 const arraySizes[9] = { 2, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 9, 0xE57CCEA0, types, arraySizes);
        return &instance;
    }
};

struct GarrSiteLevelPlotInstMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fhbb";
        static uint8 const arraySizes[4] = { 2, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xBC111CF1, types, arraySizes);
        return &instance;
    }
};

struct GarrSpecializationMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ifssbbb";
        static uint8 const arraySizes[7] = { 1, 2, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0x30FB6FE9, types, arraySizes);
        return &instance;
    }
};

struct GarrStringMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x6414DFFF, types, arraySizes);
        return &instance;
    }
};

struct GarrTalentMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "issibbbiiiiiiiiiiiii";
        static uint8 const arraySizes[20] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(7, 20, 0x8C8B99B4, types, arraySizes);
        return &instance;
    }
};

struct GarrTalentTreeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbii";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x8BB9D1A2, types, arraySizes);
        return &instance;
    }
};

struct GarrTypeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiii";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x45DE3C50, types, arraySizes);
        return &instance;
    }
};

struct GarrUiAnimClassInfoMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fhbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xCEB08F4E, types, arraySizes);
        return &instance;
    }
};

struct GarrUiAnimRaceInfoMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffffffffffffb";
        static uint8 const arraySizes[13] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 13, 0x55DD4EA6, types, arraySizes);
        return &instance;
    }
};

struct GemPropertiesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihh";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x623B3533, types, arraySizes);
        return &instance;
    }
};

struct GlobalStringsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xBFF68C36, types, arraySizes);
        return &instance;
    }
};

struct GlyphBindableSpellMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ih";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xB164611A, types, arraySizes);
        return &instance;
    }
};

struct GlyphExclusiveCategoryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x67818447, types, arraySizes);
        return &instance;
    }
};

struct GlyphPropertiesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xBDD76E49, types, arraySizes);
        return &instance;
    }
};

struct GlyphRequiredSpecMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hh";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xF2A8C5FC, types, arraySizes);
        return &instance;
    }
};

struct GroundEffectDoodadMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sffb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xB9D8F312, types, arraySizes);
        return &instance;
    }
};

struct GroundEffectTextureMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hbbi";
        static uint8 const arraySizes[4] = { 4, 4, 1, 1 };
        static DB2Meta instance(-1, 4, 0x3F1F321A, types, arraySizes);
        return &instance;
    }
};

struct GroupFinderActivityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sshhhbbbbbbbbb";
        static uint8 const arraySizes[14] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 14, 0x89499D40, types, arraySizes);
        return &instance;
    }
};

struct GroupFinderActivityGrpMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x7F0F0A99, types, arraySizes);
        return &instance;
    }
};

struct GroupFinderCategoryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x8CD5AB4A, types, arraySizes);
        return &instance;
    }
};

struct GuildColorBackgroundMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xC6D20079, types, arraySizes);
        return &instance;
    }
};

struct GuildColorBorderMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xC6D20079, types, arraySizes);
        return &instance;
    }
};

struct GuildColorEmblemMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xC6D20079, types, arraySizes);
        return &instance;
    }
};

struct GuildPerkSpellsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xC7D74917, types, arraySizes);
        return &instance;
    }
};

struct HeirloomMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "isiiiihbbi";
        static uint8 const arraySizes[10] = { 1, 1, 1, 1, 1, 2, 2, 1, 1, 1 };
        static DB2Meta instance(9, 10, 0xF07281BE, types, arraySizes);
        return &instance;
    }
};

struct HelmetAnimScalingMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x41EDD5DA, types, arraySizes);
        return &instance;
    }
};

struct HelmetGeosetVisDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i";
        static uint8 const arraySizes[1] = { 9 };
        static DB2Meta instance(-1, 1, 0xDB3E9871, types, arraySizes);
        return &instance;
    }
};

struct HighlightColorMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiibb";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x42A52A5B, types, arraySizes);
        return &instance;
    }
};

struct HolidayDescriptionsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x8E1D98D8, types, arraySizes);
        return &instance;
    }
};

struct HolidayNamesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x67818447, types, arraySizes);
        return &instance;
    }
};

struct HolidaysMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iShhbbbbbbb";
        static uint8 const arraySizes[11] = { 16, 1, 10, 1, 1, 10, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 11, 0x41A15068, types, arraySizes);
        return &instance;
    }
};

struct ImportPriceArmorMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffff";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xD00C26AF, types, arraySizes);
        return &instance;
    }
};

struct ImportPriceQualityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "f";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x26FFB6E5, types, arraySizes);
        return &instance;
    }
};

struct ImportPriceShieldMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "f";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x26FFB6E5, types, arraySizes);
        return &instance;
    }
};

struct ImportPriceWeaponMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "f";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x26FFB6E5, types, arraySizes);
        return &instance;
    }
};

struct InvasionClientDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sfiiiiiiii";
        static uint8 const arraySizes[10] = { 1, 2, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(2, 10, 0x0C8EFD74, types, arraySizes);
        return &instance;
    }
};

struct ItemMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ibbbbbbb";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 8, 0xBAB9954D, types, arraySizes);
        return &instance;
    }
};

struct ItemAppearanceMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiib";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xD203A3E9, types, arraySizes);
        return &instance;
    }
};

struct ItemAppearanceXUiCameraMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hh";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x4A8796B5, types, arraySizes);
        return &instance;
    }
};

struct ItemArmorQualityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fh";
        static uint8 const arraySizes[2] = { 7, 1 };
        static DB2Meta instance(-1, 2, 0xC3CD05A0, types, arraySizes);
        return &instance;
    }
};

struct ItemArmorShieldMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fh";
        static uint8 const arraySizes[2] = { 7, 1 };
        static DB2Meta instance(-1, 2, 0xA38C0C55, types, arraySizes);
        return &instance;
    }
};

struct ItemArmorTotalMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffffh";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x12D739A5, types, arraySizes);
        return &instance;
    }
};

struct ItemBagFamilyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x67818447, types, arraySizes);
        return &instance;
    }
};

struct ItemBonusMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihbb";
        static uint8 const arraySizes[4] = { 2, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x7D937400, types, arraySizes);
        return &instance;
    }
};

struct ItemBonusListLevelDeltaMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hi";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(1, 2, 0xCB953E49, types, arraySizes);
        return &instance;
    }
};

struct ItemBonusTreeNodeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhhb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xE2ED6BA0, types, arraySizes);
        return &instance;
    }
};

struct ItemChildEquipmentMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iib";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x5E08B8E2, types, arraySizes);
        return &instance;
    }
};

struct ItemClassMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fsb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xFC2CE47C, types, arraySizes);
        return &instance;
    }
};

struct ItemContextPickerEntryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbiii";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x41FD05DE, types, arraySizes);
        return &instance;
    }
};

struct ItemCurrencyCostMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x48C57690, types, arraySizes);
        return &instance;
    }
};

struct ItemDamageAmmoMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fh";
        static uint8 const arraySizes[2] = { 7, 1 };
        static DB2Meta instance(-1, 2, 0xA38C0C55, types, arraySizes);
        return &instance;
    }
};

struct ItemDamageOneHandMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fh";
        static uint8 const arraySizes[2] = { 7, 1 };
        static DB2Meta instance(-1, 2, 0xA38C0C55, types, arraySizes);
        return &instance;
    }
};

struct ItemDamageOneHandCasterMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fh";
        static uint8 const arraySizes[2] = { 7, 1 };
        static DB2Meta instance(-1, 2, 0xA38C0C55, types, arraySizes);
        return &instance;
    }
};

struct ItemDamageTwoHandMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fh";
        static uint8 const arraySizes[2] = { 7, 1 };
        static DB2Meta instance(-1, 2, 0xA38C0C55, types, arraySizes);
        return &instance;
    }
};

struct ItemDamageTwoHandCasterMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fh";
        static uint8 const arraySizes[2] = { 7, 1 };
        static DB2Meta instance(-1, 2, 0xA38C0C55, types, arraySizes);
        return &instance;
    }
};

struct ItemDisenchantLootMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhhbbb";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 6, 0x9E738C93, types, arraySizes);
        return &instance;
    }
};

struct ItemDisplayInfoMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiiiiiiiiiiiii";
        static uint8 const arraySizes[15] = { 2, 2, 3, 3, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 15, 0x07D2E6CF, types, arraySizes);
        return &instance;
    }
};

struct ItemDisplayInfoMaterialResMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iib";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xAC466DE7, types, arraySizes);
        return &instance;
    }
};

struct ItemDisplayXUiCameraMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ih";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x6EEE8622, types, arraySizes);
        return &instance;
    }
};

struct ItemEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiihhhbb";
        static uint8 const arraySizes[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 9, 0x131233D4, types, arraySizes);
        return &instance;
    }
};

struct ItemExtendedCostMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iihhhbbbbb";
        static uint8 const arraySizes[10] = { 5, 5, 5, 1, 5, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 10, 0x56C5664F, types, arraySizes);
        return &instance;
    }
};

struct ItemGroupSoundsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i";
        static uint8 const arraySizes[1] = { 4 };
        static DB2Meta instance(-1, 1, 0x22B7B75A, types, arraySizes);
        return &instance;
    }
};

struct ItemLimitCategoryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xDFE88B15, types, arraySizes);
        return &instance;
    }
};

struct ItemLimitCategoryConditionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x66B27D0B, types, arraySizes);
        return &instance;
    }
};

struct ItemModifiedAppearanceMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihbbbi";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(5, 6, 0x89E44FCB, types, arraySizes);
        return &instance;
    }
};

struct ItemModifiedAppearanceExtraMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iibbb";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0xA44269EE, types, arraySizes);
        return &instance;
    }
};

struct ItemNameDescriptionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "si";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xB914CD84, types, arraySizes);
        return &instance;
    }
};

struct ItemPetFoodMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x47B62FA7, types, arraySizes);
        return &instance;
    }
};

struct ItemPriceBaseMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffh";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x79EFBA2F, types, arraySizes);
        return &instance;
    }
};

struct ItemRandomPropertiesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sh";
        static uint8 const arraySizes[2] = { 1, 5 };
        static DB2Meta instance(-1, 2, 0x17DC5118, types, arraySizes);
        return &instance;
    }
};

struct ItemRandomSuffixMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shh";
        static uint8 const arraySizes[3] = { 1, 5, 5 };
        static DB2Meta instance(-1, 3, 0x20CC67CD, types, arraySizes);
        return &instance;
    }
};

struct ItemRangedDisplayInfoMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiii";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x99013BB1, types, arraySizes);
        return &instance;
    }
};

struct ItemSearchNameMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "siiihhhhbbbbi";
        static uint8 const arraySizes[13] = { 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 13, 0xE3F1487C, types, arraySizes);
        return &instance;
    }
};

struct ItemSetMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sihii";
        static uint8 const arraySizes[5] = { 1, 17, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x5089F4A2, types, arraySizes);
        return &instance;
    }
};

struct ItemSetSpellMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihhb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x939730D0, types, arraySizes);
        return &instance;
    }
};

struct ItemSparseMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iffiiiiiiiiffsssssififhhhhhhhhhhhhhhhhhhhhbbbbbbbbbbbbbbbbbbbbb";
        static uint8 const arraySizes[63] = { 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 10, 10, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 10, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 10, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 63, 0x27909DB0, types, arraySizes);
        return &instance;
    }
};

struct ItemSpecMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hbbbbb";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 6, 0x9AE2EA46, types, arraySizes);
        return &instance;
    }
};

struct ItemSpecOverrideMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ih";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x85832A2E, types, arraySizes);
        return &instance;
    }
};

struct ItemSubClassMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sshbbbbbbb";
        static uint8 const arraySizes[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 10, 0xB94F4659, types, arraySizes);
        return &instance;
    }
};

struct ItemSubClassMaskMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "isb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x82EEF3E8, types, arraySizes);
        return &instance;
    }
};

struct ItemUpgradeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihhbb";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x196B9A4F, types, arraySizes);
        return &instance;
    }
};

struct ItemVisualEffectsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x12126A7B, types, arraySizes);
        return &instance;
    }
};

struct ItemVisualsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "h";
        static uint8 const arraySizes[1] = { 5 };
        static DB2Meta instance(-1, 1, 0xD4015649, types, arraySizes);
        return &instance;
    }
};

struct ItemXBonusTreeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ih";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xEB27B98B, types, arraySizes);
        return &instance;
    }
};

struct JournalEncounterMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fsshhhhbbi";
        static uint8 const arraySizes[10] = { 2, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 10, 0x02224293, types, arraySizes);
        return &instance;
    }
};

struct JournalEncounterCreatureMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iisshbi";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(6, 7, 0xDEB5EEB8, types, arraySizes);
        return &instance;
    }
};

struct JournalEncounterItemMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihbbbi";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(5, 6, 0x2B6945A8, types, arraySizes);
        return &instance;
    }
};

struct JournalEncounterSectionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssiiihhhhhhbbb";
        static uint8 const arraySizes[14] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 14, 0xF08A57BF, types, arraySizes);
        return &instance;
    }
};

struct JournalEncounterXDifficultyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x911A7222, types, arraySizes);
        return &instance;
    }
};

struct JournalInstanceMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiisshhbbi";
        static uint8 const arraySizes[11] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(10, 11, 0xDFF1896D, types, arraySizes);
        return &instance;
    }
};

struct JournalItemXDifficultyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x3DD3BD11, types, arraySizes);
        return &instance;
    }
};

struct JournalSectionXDifficultyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x084FB517, types, arraySizes);
        return &instance;
    }
};

struct JournalTierMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x67818447, types, arraySizes);
        return &instance;
    }
};

struct JournalTierXInstanceMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hh";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xC5F39D3A, types, arraySizes);
        return &instance;
    }
};

struct KeyChainMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "b";
        static uint8 const arraySizes[1] = { 32 };
        static DB2Meta instance(-1, 1, 0xD27482EA, types, arraySizes);
        return &instance;
    }
};

struct KeystoneAffixMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssi";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xF165D122, types, arraySizes);
        return &instance;
    }
};

struct LanguageWordsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x04C0BC5D, types, arraySizes);
        return &instance;
    }
};

struct LanguagesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "si";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(1, 2, 0x2CF66B24, types, arraySizes);
        return &instance;
    }
};

struct LfgDungeonExpansionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhbbbii";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0x0BDD9F25, types, arraySizes);
        return &instance;
    }
};

struct LfgDungeonGroupMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xC5A0B877, types, arraySizes);
        return &instance;
    }
};

struct LfgDungeonsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "siSsihhhhhhhhbbbbbbbbbbbbbbbbbi";
        static uint8 const arraySizes[31] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(30, 31, 0x27312D4F, types, arraySizes);
        return &instance;
    }
};

struct LfgDungeonsGroupingMapMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x4A7FA59C, types, arraySizes);
        return &instance;
    }
};

struct LfgRoleRequirementMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x7F56023F, types, arraySizes);
        return &instance;
    }
};

struct LightMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fffhh";
        static uint8 const arraySizes[5] = { 3, 1, 1, 1, 8 };
        static DB2Meta instance(-1, 5, 0x35A3D54B, types, arraySizes);
        return &instance;
    }
};

struct LightDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiiiiiiiiiiiiiiiifffffffffiiiiiihh";
        static uint8 const arraySizes[35] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 35, 0xA89E1596, types, arraySizes);
        return &instance;
    }
};

struct LightParamsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffffffhbbbi";
        static uint8 const arraySizes[11] = { 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1 };
        static DB2Meta instance(10, 11, 0xDB514597, types, arraySizes);
        return &instance;
    }
};

struct LightSkyboxMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x62B41D78, types, arraySizes);
        return &instance;
    }
};

struct LiquidMaterialMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x5AA70B00, types, arraySizes);
        return &instance;
    }
};

struct LiquidObjectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffhbb";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x551D907E, types, arraySizes);
        return &instance;
    }
};

struct LiquidTypeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sifffffSifihhbbbbbi";
        static uint8 const arraySizes[19] = { 1, 1, 1, 1, 1, 1, 1, 6, 2, 18, 4, 1, 1, 1, 1, 1, 1, 6, 1 };
        static DB2Meta instance(-1, 19, 0x28B44DCB, types, arraySizes);
        return &instance;
    }
};

struct LoadingScreenTaxiSplinesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffhhb";
        static uint8 const arraySizes[5] = { 10, 10, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0xBE26AA7B, types, arraySizes);
        return &instance;
    }
};

struct LoadingScreensMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x0C18B360, types, arraySizes);
        return &instance;
    }
};

struct LocaleMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ibbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x0BE3B70B, types, arraySizes);
        return &instance;
    }
};

struct LocationMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ff";
        static uint8 const arraySizes[2] = { 3, 3 };
        static DB2Meta instance(-1, 2, 0x6F5C6A8A, types, arraySizes);
        return &instance;
    }
};

struct LockMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihbb";
        static uint8 const arraySizes[4] = { 8, 8, 8, 8 };
        static DB2Meta instance(-1, 4, 0x8501126F, types, arraySizes);
        return &instance;
    }
};

struct LockTypeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssssi";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(4, 5, 0x4064FF07, types, arraySizes);
        return &instance;
    }
};

struct LookAtControllerMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffffhhhhbbbbbiiiii";
        static uint8 const arraySizes[18] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 18, 0xA17E9956, types, arraySizes);
        return &instance;
    }
};

struct MailTemplateMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xA1D9C984, types, arraySizes);
        return &instance;
    }
};

struct ManifestInterfaceActionIconMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(0, 1, 0x38F4113F, types, arraySizes);
        return &instance;
    }
};

struct ManifestInterfaceDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ss";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xBDA49B69, types, arraySizes);
        return &instance;
    }
};

struct ManifestInterfaceItemIconMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(0, 1, 0x38F4113F, types, arraySizes);
        return &instance;
    }
};

struct ManifestInterfaceTOCDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x6B30F325, types, arraySizes);
        return &instance;
    }
};

struct ManifestMP3Meta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(0, 1, 0x38F4113F, types, arraySizes);
        return &instance;
    }
};

struct MapMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "siffssshhhhhhhbbbbb";
        static uint8 const arraySizes[19] = { 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 19, 0xB32E648C, types, arraySizes);
        return &instance;
    }
};

struct MapChallengeModeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhb";
        static uint8 const arraySizes[3] = { 1, 3, 1 };
        static DB2Meta instance(-1, 3, 0xB9D43326, types, arraySizes);
        return &instance;
    }
};

struct MapDifficultyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shbbbbbi";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 8, 0x7ADE1C7B, types, arraySizes);
        return &instance;
    }
};

struct MapDifficultyXConditionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "siii";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x726559D6, types, arraySizes);
        return &instance;
    }
};

struct MarketingPromotionsXLocaleMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiisbb";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0xBDC16D0F, types, arraySizes);
        return &instance;
    }
};

struct MaterialMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "biii";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xB0DC1034, types, arraySizes);
        return &instance;
    }
};

struct MinorTalentMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xD8110E92, types, arraySizes);
        return &instance;
    }
};

struct ModelAnimCloakDampeningMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xAA3A793B, types, arraySizes);
        return &instance;
    }
};

struct ModelFileDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(1, 3, 0x5EF4BA08, types, arraySizes);
        return &instance;
    }
};

struct ModelRibbonQualityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ib";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x18636F99, types, arraySizes);
        return &instance;
    }
};

struct ModifierTreeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iihbbbb";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0x060C2D1C, types, arraySizes);
        return &instance;
    }
};

struct MountMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iisssfhhhbi";
        static uint8 const arraySizes[11] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(10, 11, 0x86A9FD37, types, arraySizes);
        return &instance;
    }
};

struct MountCapabilityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iihhhbii";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(6, 8, 0xB62CA122, types, arraySizes);
        return &instance;
    }
};

struct MountTypeXCapabilityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xADB0EE4D, types, arraySizes);
        return &instance;
    }
};

struct MovieMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iibb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xCAE1BC8B, types, arraySizes);
        return &instance;
    }
};

struct MovieFileDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "h";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x41B84017, types, arraySizes);
        return &instance;
    }
};

struct MovieVariationMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihi";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x87300FEE, types, arraySizes);
        return &instance;
    }
};

struct NPCSoundsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i";
        static uint8 const arraySizes[1] = { 4 };
        static DB2Meta instance(-1, 1, 0x48506E87, types, arraySizes);
        return &instance;
    }
};

struct NameGenMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xD7C1FC25, types, arraySizes);
        return &instance;
    }
};

struct NamesProfanityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "Sb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x4C7F576E, types, arraySizes);
        return &instance;
    }
};

struct NamesReservedMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "S";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x47B62FA7, types, arraySizes);
        return &instance;
    }
};

struct NamesReservedLocaleMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "Sb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x813B40C3, types, arraySizes);
        return &instance;
    }
};

struct NpcModelItemSlotDisplayInfoMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iib";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xA22F8680, types, arraySizes);
        return &instance;
    }
};

struct ObjectEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sfhbbbbbi";
        static uint8 const arraySizes[9] = { 1, 3, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 9, 0xDD9C935E, types, arraySizes);
        return &instance;
    }
};

struct ObjectEffectGroupMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x67818447, types, arraySizes);
        return &instance;
    }
};

struct ObjectEffectModifierMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fbbb";
        static uint8 const arraySizes[4] = { 4, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x02A080A3, types, arraySizes);
        return &instance;
    }
};

struct ObjectEffectPackageMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x67818447, types, arraySizes);
        return &instance;
    }
};

struct ObjectEffectPackageElemMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhh";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x041FFE7D, types, arraySizes);
        return &instance;
    }
};

struct OutlineEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fiiiii";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 6, 0xB5DB9B94, types, arraySizes);
        return &instance;
    }
};

struct OverrideSpellDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iib";
        static uint8 const arraySizes[3] = { 10, 1, 1 };
        static DB2Meta instance(-1, 3, 0x401AC574, types, arraySizes);
        return &instance;
    }
};

struct PageTextMaterialMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x67818447, types, arraySizes);
        return &instance;
    }
};

struct PaperDollItemFrameMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x15BA10F3, types, arraySizes);
        return &instance;
    }
};

struct ParticleColorMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 3, 3, 3 };
        static DB2Meta instance(-1, 3, 0xF1BF0CA9, types, arraySizes);
        return &instance;
    }
};

struct PathMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbbbbbb";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0xE6C80767, types, arraySizes);
        return &instance;
    }
};

struct PathNodeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iihh";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(0, 4, 0x57D19E50, types, arraySizes);
        return &instance;
    }
};

struct PathNodePropertyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhbii";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(3, 5, 0x9D908771, types, arraySizes);
        return &instance;
    }
};

struct PathPropertyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihbi";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(3, 4, 0x7353B599, types, arraySizes);
        return &instance;
    }
};

struct PhaseMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "h";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x12961644, types, arraySizes);
        return &instance;
    }
};

struct PhaseShiftZoneSoundsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhhhhbbbbiiii";
        static uint8 const arraySizes[13] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 13, 0x1A5C14A8, types, arraySizes);
        return &instance;
    }
};

struct PhaseXPhaseGroupMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hh";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xC5DECA36, types, arraySizes);
        return &instance;
    }
};

struct PlayerConditionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiiiiiiiiiiiishhhhhhhhhhhhhhhhhhbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbiiiiiiiiiiiiiii";
        static uint8 const arraySizes[79] = { 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 4, 1, 1, 1, 1, 1, 1, 4, 4, 4, 1, 4, 4, 4, 2, 1, 4, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 1, 4, 1, 1, 1, 4, 4, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 4, 4, 4, 1, 4, 1, 4, 6, 1, 1, 1, 2 };
        static DB2Meta instance(-1, 79, 0xBAA3CA64, types, arraySizes);
        return &instance;
    }
};

struct PositionerMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fhbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x3E7693C1, types, arraySizes);
        return &instance;
    }
};

struct PositionerStateMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fbiiiiii";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 8, 0x0EA8C354, types, arraySizes);
        return &instance;
    }
};

struct PositionerStateEntryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffbbbbbbbbi";
        static uint8 const arraySizes[11] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 11, 0x6CF8DBB6, types, arraySizes);
        return &instance;
    }
};

struct PowerDisplayMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "Sbbbb";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x996B7B03, types, arraySizes);
        return &instance;
    }
};

struct PowerTypeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssffhhhbbbbb";
        static uint8 const arraySizes[12] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 12, 0x042B76A1, types, arraySizes);
        return &instance;
    }
};

struct PrestigeLevelInfoMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "isbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x85DC9691, types, arraySizes);
        return &instance;
    }
};

struct PvpBracketTypesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bi";
        static uint8 const arraySizes[2] = { 1, 4 };
        static DB2Meta instance(-1, 2, 0x15D5D38F, types, arraySizes);
        return &instance;
    }
};

struct PvpDifficultyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hbbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x987332DF, types, arraySizes);
        return &instance;
    }
};

struct PvpItemMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ib";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xBCA228D1, types, arraySizes);
        return &instance;
    }
};

struct PvpRewardMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x8D746A4E, types, arraySizes);
        return &instance;
    }
};

struct PvpTalentMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iisiiiiii";
        static uint8 const arraySizes[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 9, 0x46E787AF, types, arraySizes);
        return &instance;
    }
};

struct PvpTalentUnlockMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xDA321AC4, types, arraySizes);
        return &instance;
    }
};

struct QuestFactionRewardMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "h";
        static uint8 const arraySizes[1] = { 10 };
        static DB2Meta instance(-1, 1, 0x90E2CCC9, types, arraySizes);
        return &instance;
    }
};

struct QuestFeedbackEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihbbbb";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 6, 0x15232667, types, arraySizes);
        return &instance;
    }
};

struct QuestInfoMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x134A3185, types, arraySizes);
        return &instance;
    }
};

struct QuestLineMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x67818447, types, arraySizes);
        return &instance;
    }
};

struct QuestLineXQuestMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xE6F65F4F, types, arraySizes);
        return &instance;
    }
};

struct QuestMoneyRewardMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i";
        static uint8 const arraySizes[1] = { 10 };
        static DB2Meta instance(-1, 1, 0xE39F507A, types, arraySizes);
        return &instance;
    }
};

struct QuestObjectiveMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iishbbbb";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 8, 0xFBAC2A6D, types, arraySizes);
        return &instance;
    }
};

struct QuestPOIBlobMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhbbi";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0xA11D5590, types, arraySizes);
        return &instance;
    }
};

struct QuestPOIPointMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihhi";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(3, 4, 0x356F39B9, types, arraySizes);
        return &instance;
    }
};

struct QuestPOIPointCliTaskMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhhhhbi";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0x6F65A1E7, types, arraySizes);
        return &instance;
    }
};

struct QuestPackageItemMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x9B308EDF, types, arraySizes);
        return &instance;
    }
};

struct QuestSortMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xCD4A8256, types, arraySizes);
        return &instance;
    }
};

struct QuestV2Meta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "h";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xA33E0F53, types, arraySizes);
        return &instance;
    }
};

struct QuestV2CliTaskMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "issihhhhhhhbbbbbbbbbiii";
        static uint8 const arraySizes[23] = { 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(20, 23, 0xB92018B7, types, arraySizes);
        return &instance;
    }
};

struct QuestXPMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "h";
        static uint8 const arraySizes[1] = { 10 };
        static DB2Meta instance(-1, 1, 0x4346D258, types, arraySizes);
        return &instance;
    }
};

struct RacialMountsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ib";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xD4825187, types, arraySizes);
        return &instance;
    }
};

struct RandPropPointsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 5, 5, 5 };
        static DB2Meta instance(-1, 3, 0xBB6728B0, types, arraySizes);
        return &instance;
    }
};

struct ResearchBranchMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssihb";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0xC54288AC, types, arraySizes);
        return &instance;
    }
};

struct ResearchFieldMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbi";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(2, 3, 0x3C4783A7, types, arraySizes);
        return &instance;
    }
};

struct ResearchProjectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssishbbii";
        static uint8 const arraySizes[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(7, 9, 0xF188A6B0, types, arraySizes);
        return &instance;
    }
};

struct ResearchSiteMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ishi";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x53309323, types, arraySizes);
        return &instance;
    }
};

struct ResistancesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbi";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x8B169B16, types, arraySizes);
        return &instance;
    }
};

struct RewardPackMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ifbbii";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 6, 0x2804996B, types, arraySizes);
        return &instance;
    }
};

struct RewardPackXCurrencyTypeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x5AD7107A, types, arraySizes);
        return &instance;
    }
};

struct RewardPackXItemMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x648BC961, types, arraySizes);
        return &instance;
    }
};

struct RibbonQualityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fffb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x689AB407, types, arraySizes);
        return &instance;
    }
};

struct RulesetItemUpgradeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ih";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xF434A1F0, types, arraySizes);
        return &instance;
    }
};

struct ScalingStatDistributionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x883E80FE, types, arraySizes);
        return &instance;
    }
};

struct ScenarioMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xE71EFDEA, types, arraySizes);
        return &instance;
    }
};

struct ScenarioEventEntryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x4E0E3AC5, types, arraySizes);
        return &instance;
    }
};

struct ScenarioStepMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sshhhhbbi";
        static uint8 const arraySizes[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 9, 0xACF5556A, types, arraySizes);
        return &instance;
    }
};

struct SceneScriptMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sshh";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xE564690A, types, arraySizes);
        return &instance;
    }
};

struct SceneScriptPackageMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x67818447, types, arraySizes);
        return &instance;
    }
};

struct SceneScriptPackageMemberMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhhb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x122FCD3F, types, arraySizes);
        return &instance;
    }
};

struct ScheduledIntervalMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiii";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x861AEB4E, types, arraySizes);
        return &instance;
    }
};

struct ScheduledWorldStateMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiiiiii";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 8, 0x39E4B20A, types, arraySizes);
        return &instance;
    }
};

struct ScheduledWorldStateGroupMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiii";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0xDBCC318B, types, arraySizes);
        return &instance;
    }
};

struct ScheduledWorldStateXUniqCatMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(0, 3, 0x6E0F3FC1, types, arraySizes);
        return &instance;
    }
};

struct ScreenEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sihhhhbbbiii";
        static uint8 const arraySizes[12] = { 1, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 12, 0xDD021285, types, arraySizes);
        return &instance;
    }
};

struct ScreenLocationMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x67818447, types, arraySizes);
        return &instance;
    }
};

struct SeamlessSiteMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x2FE47A1B, types, arraySizes);
        return &instance;
    }
};

struct ServerMessagesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x9599555F, types, arraySizes);
        return &instance;
    }
};

struct ShadowyEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiffffffbb";
        static uint8 const arraySizes[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 10, 0x091E9D1A, types, arraySizes);
        return &instance;
    }
};

struct SkillLineMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssshhbbi";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 8, 0xF1CDEABF, types, arraySizes);
        return &instance;
    }
};

struct SkillLineAbilityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiihhhhhhbbi";
        static uint8 const arraySizes[13] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 13, 0xC3E8E26F, types, arraySizes);
        return &instance;
    }
};

struct SkillRaceClassInfoMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihhhbbi";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0xEDA3A4D4, types, arraySizes);
        return &instance;
    }
};

struct SoundAmbienceMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "biii";
        static uint8 const arraySizes[4] = { 1, 2, 1, 1 };
        static DB2Meta instance(-1, 4, 0x6F03BA39, types, arraySizes);
        return &instance;
    }
};

struct SoundAmbienceFlavorMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x917AB671, types, arraySizes);
        return &instance;
    }
};

struct SoundBusMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffhbbbbbbbbi";
        static uint8 const arraySizes[12] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(11, 12, 0x3A647CAE, types, arraySizes);
        return &instance;
    }
};

struct SoundEmitterPillPointsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fh";
        static uint8 const arraySizes[2] = { 3, 1 };
        static DB2Meta instance(-1, 2, 0x24A008CB, types, arraySizes);
        return &instance;
    }
};

struct SoundEmittersMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffshhhbbbbii";
        static uint8 const arraySizes[12] = { 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(10, 12, 0xAED6FA80, types, arraySizes);
        return &instance;
    }
};

struct SoundFilterMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x67818447, types, arraySizes);
        return &instance;
    }
};

struct SoundFilterElemMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fbb";
        static uint8 const arraySizes[3] = { 9, 1, 1 };
        static DB2Meta instance(-1, 3, 0x700BC63F, types, arraySizes);
        return &instance;
    }
};

struct SoundKitMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sffffffffhhhbbbbi";
        static uint8 const arraySizes[17] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(16, 17, 0x45160162, types, arraySizes);
        return &instance;
    }
};

struct SoundKitAdvancedMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fiiiiiifffffiiffffffihbbbbiiiiii";
        static uint8 const arraySizes[32] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 32, 0x27606F57, types, arraySizes);
        return &instance;
    }
};

struct SoundKitChildMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ii";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x8C2AEA75, types, arraySizes);
        return &instance;
    }
};

struct SoundKitEntryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ifbi";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xD29B5B47, types, arraySizes);
        return &instance;
    }
};

struct SoundKitFallbackMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ii";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x751D6B9F, types, arraySizes);
        return &instance;
    }
};

struct SoundOverrideMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhhb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xAAFD0E26, types, arraySizes);
        return &instance;
    }
};

struct SoundProviderPreferencesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sfffffffffffffffhhhhhbb";
        static uint8 const arraySizes[23] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 23, 0x85F511FC, types, arraySizes);
        return &instance;
    }
};

struct SourceInfoMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "isbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x796AD8C7, types, arraySizes);
        return &instance;
    }
};

struct SpamMessagesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x6414DFFF, types, arraySizes);
        return &instance;
    }
};

struct SpecializationSpellsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iishbi";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(5, 6, 0x9FC404CF, types, arraySizes);
        return &instance;
    }
};

struct SpellMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssssiii";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(5, 7, 0x15C9999E, types, arraySizes);
        return &instance;
    }
};

struct SpellActionBarPrefMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ih";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xB1F8D61B, types, arraySizes);
        return &instance;
    }
};

struct SpellActivationOverlayMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiifibbi";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 4, 1, 1, 1 };
        static DB2Meta instance(-1, 8, 0x2FD43517, types, arraySizes);
        return &instance;
    }
};

struct SpellAuraOptionsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiihbbb";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 8, 0xE99ACF7D, types, arraySizes);
        return &instance;
    }
};

struct SpellAuraRestrictionsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiiibbbbb";
        static uint8 const arraySizes[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 10, 0xCC928C2D, types, arraySizes);
        return &instance;
    }
};

struct SpellAuraVisXChrSpecMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hh";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x19C6D5BC, types, arraySizes);
        return &instance;
    }
};

struct SpellAuraVisibilityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ibbi";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(3, 4, 0xD4FFE0FE, types, arraySizes);
        return &instance;
    }
};

struct SpellCastTimesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iih";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xB44CBB5C, types, arraySizes);
        return &instance;
    }
};

struct SpellCastingRequirementsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihhhbbb";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0x91AFF9C5, types, arraySizes);
        return &instance;
    }
};

struct SpellCategoriesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihhhbbbbb";
        static uint8 const arraySizes[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 9, 0xF7721E4A, types, arraySizes);
        return &instance;
    }
};

struct SpellCategoryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sibbbi";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 6, 0x5A212A44, types, arraySizes);
        return &instance;
    }
};

struct SpellChainEffectsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffffiifffffffffffffffffffffffffffffffffffiffsshhhhbbbbbbbbbbbi";
        static uint8 const arraySizes[62] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 1, 1, 1, 3, 1, 1, 1, 11, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 62, 0x89DAFC72, types, arraySizes);
        return &instance;
    }
};

struct SpellClassOptionsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iibi";
        static uint8 const arraySizes[4] = { 1, 4, 1, 1 };
        static DB2Meta instance(-1, 4, 0x23C0B83A, types, arraySizes);
        return &instance;
    }
};

struct SpellCooldownsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiib";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0xC44BCFEE, types, arraySizes);
        return &instance;
    }
};

struct SpellDescriptionVariablesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xE37F5F23, types, arraySizes);
        return &instance;
    }
};

struct SpellDispelTypeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xE8FCFE59, types, arraySizes);
        return &instance;
    }
};

struct SpellDurationMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iih";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xC40857BC, types, arraySizes);
        return &instance;
    }
};

struct SpellEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fffffiffiiiiiiiiiiiiiiiii";
        static uint8 const arraySizes[25] = { 1, 1, 1, 1, 1, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 1, 2, 1, 1, 1 };
        static DB2Meta instance(8, 25, 0xD5324B6A, types, arraySizes);
        return &instance;
    }
};

struct SpellEffectCameraShakesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hh";
        static uint8 const arraySizes[2] = { 3, 1 };
        static DB2Meta instance(-1, 2, 0x6F5E87B0, types, arraySizes);
        return &instance;
    }
};

struct SpellEffectEmissionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffhb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x744EB0EB, types, arraySizes);
        return &instance;
    }
};

struct SpellEffectGroupSizeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "if";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x6C6B6B5B, types, arraySizes);
        return &instance;
    }
};

struct SpellEffectScalingMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fffi";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xBAC40B9B, types, arraySizes);
        return &instance;
    }
};

struct SpellEquippedItemsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiib";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x9C6390C6, types, arraySizes);
        return &instance;
    }
};

struct SpellFlyoutMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "isshbi";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 6, 0xB35D88A2, types, arraySizes);
        return &instance;
    }
};

struct SpellFlyoutItemMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ibb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x60E17715, types, arraySizes);
        return &instance;
    }
};

struct SpellFocusObjectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x67818447, types, arraySizes);
        return &instance;
    }
};

struct SpellIconMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x88B46898, types, arraySizes);
        return &instance;
    }
};

struct SpellInterruptsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiihb";
        static uint8 const arraySizes[5] = { 1, 2, 2, 1, 1 };
        static DB2Meta instance(-1, 5, 0xFCE2DF7C, types, arraySizes);
        return &instance;
    }
};

struct SpellItemEnchantmentMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "isfiihhhhhhbbbbbbbi";
        static uint8 const arraySizes[19] = { 3, 1, 3, 1, 1, 3, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 19, 0xA21E7644, types, arraySizes);
        return &instance;
    }
};

struct SpellItemEnchantmentConditionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbbbbi";
        static uint8 const arraySizes[6] = { 5, 5, 5, 5, 5, 5 };
        static DB2Meta instance(-1, 6, 0xFE2C26F5, types, arraySizes);
        return &instance;
    }
};

struct SpellKeyboundOverrideMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "isb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x4C31B87C, types, arraySizes);
        return &instance;
    }
};

struct SpellLabelMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ii";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x2A4CDECC, types, arraySizes);
        return &instance;
    }
};

struct SpellLearnSpellMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x8C7EE18E, types, arraySizes);
        return &instance;
    }
};

struct SpellLevelsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihhhbb";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 6, 0xCFBB94B1, types, arraySizes);
        return &instance;
    }
};

struct SpellMechanicMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x8B096444, types, arraySizes);
        return &instance;
    }
};

struct SpellMiscMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iffhhhhhb";
        static uint8 const arraySizes[9] = { 14, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 9, 0x2B8ABAC3, types, arraySizes);
        return &instance;
    }
};

struct SpellMiscDifficultyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ibi";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(2, 3, 0xF88FAB97, types, arraySizes);
        return &instance;
    }
};

struct SpellMissileMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ifffffffffffffb";
        static uint8 const arraySizes[15] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 15, 0x398CF976, types, arraySizes);
        return &instance;
    }
};

struct SpellMissileMotionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x719D619B, types, arraySizes);
        return &instance;
    }
};

struct SpellPowerMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiffifbbiiiiii";
        static uint8 const arraySizes[14] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(8, 14, 0x8CDC380E, types, arraySizes);
        return &instance;
    }
};

struct SpellPowerDifficultyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbi";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(2, 3, 0x0117F40F, types, arraySizes);
        return &instance;
    }
};

struct SpellProceduralEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fbi";
        static uint8 const arraySizes[3] = { 4, 1, 1 };
        static DB2Meta instance(2, 3, 0xEC43FF27, types, arraySizes);
        return &instance;
    }
};

struct SpellProcsPerMinuteMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xEFCFD31B, types, arraySizes);
        return &instance;
    }
};

struct SpellProcsPerMinuteModMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fhbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xA339D9A5, types, arraySizes);
        return &instance;
    }
};

struct SpellRadiusMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffff";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xE948EB40, types, arraySizes);
        return &instance;
    }
};

struct SpellRangeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffssb";
        static uint8 const arraySizes[5] = { 2, 2, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x78704E1A, types, arraySizes);
        return &instance;
    }
};

struct SpellReagentsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iih";
        static uint8 const arraySizes[3] = { 1, 8, 8 };
        static DB2Meta instance(-1, 3, 0x86B17A70, types, arraySizes);
        return &instance;
    }
};

struct SpellReagentsCurrencyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihh";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x01173DCA, types, arraySizes);
        return &instance;
    }
};

struct SpellScalingMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihiii";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x47D87C91, types, arraySizes);
        return &instance;
    }
};

struct SpellShapeshiftMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiib";
        static uint8 const arraySizes[4] = { 1, 2, 2, 1 };
        static DB2Meta instance(-1, 4, 0x28AA9C0D, types, arraySizes);
        return &instance;
    }
};

struct SpellShapeshiftFormMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sfihhhhhbb";
        static uint8 const arraySizes[10] = { 1, 1, 1, 1, 1, 4, 8, 1, 1, 1 };
        static DB2Meta instance(-1, 10, 0x11AFAB53, types, arraySizes);
        return &instance;
    }
};

struct SpellSpecialUnitEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hi";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xB7AAD4C5, types, arraySizes);
        return &instance;
    }
};

struct SpellTargetRestrictionsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iffihbbi";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 8, 0xD496481C, types, arraySizes);
        return &instance;
    }
};

struct SpellTotemsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iih";
        static uint8 const arraySizes[3] = { 1, 2, 2 };
        static DB2Meta instance(-1, 3, 0x752DCE9E, types, arraySizes);
        return &instance;
    }
};

struct SpellVisualMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiiiiiiiiiiiiiffiihhhbbiiii";
        static uint8 const arraySizes[28] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(24, 28, 0xA2B85016, types, arraySizes);
        return &instance;
    }
};

struct SpellVisualAnimMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhh";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x0B1038D1, types, arraySizes);
        return &instance;
    }
};

struct SpellVisualColorEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fifhhhhhbbi";
        static uint8 const arraySizes[11] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 11, 0xD64D320E, types, arraySizes);
        return &instance;
    }
};

struct SpellVisualEffectNameMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sffffffiiibii";
        static uint8 const arraySizes[13] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 13, 0x4552DDC5, types, arraySizes);
        return &instance;
    }
};

struct SpellVisualKitMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ifhhii";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(4, 6, 0xC3D97636, types, arraySizes);
        return &instance;
    }
};

struct SpellVisualKitAreaModelMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ifffhb";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 6, 0xE63E62E3, types, arraySizes);
        return &instance;
    }
};

struct SpellVisualKitEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x2323470B, types, arraySizes);
        return &instance;
    }
};

struct SpellVisualKitModelAttachMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iffffffffffifhhhhhhbbi";
        static uint8 const arraySizes[22] = { 1, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(21, 22, 0x2CD44B15, types, arraySizes);
        return &instance;
    }
};

struct SpellVisualMissileMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiffhhhhhhbbiii";
        static uint8 const arraySizes[16] = { 1, 1, 1, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(13, 16, 0xA538BBD9, types, arraySizes);
        return &instance;
    }
};

struct SpellXSpellVisualMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ifhhhbbi";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(7, 8, 0x462EF5F7, types, arraySizes);
        return &instance;
    }
};

struct Startup_StringsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ss";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x1BE9FD87, types, arraySizes);
        return &instance;
    }
};

struct StationeryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbi";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xB7A33B6A, types, arraySizes);
        return &instance;
    }
};

struct StringLookupsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x2A21A5F9, types, arraySizes);
        return &instance;
    }
};

struct SummonPropertiesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiii";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x0013EE84, types, arraySizes);
        return &instance;
    }
};

struct TactKeyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "b";
        static uint8 const arraySizes[1] = { 16 };
        static DB2Meta instance(-1, 1, 0xE980B1CA, types, arraySizes);
        return &instance;
    }
};

struct TactKeyLookupMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "b";
        static uint8 const arraySizes[1] = { 8 };
        static DB2Meta instance(-1, 1, 0x72063202, types, arraySizes);
        return &instance;
    }
};

struct TalentMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iishbbbbb";
        static uint8 const arraySizes[9] = { 1, 1, 1, 1, 1, 1, 1, 2, 1 };
        static DB2Meta instance(-1, 9, 0xE408A87C, types, arraySizes);
        return &instance;
    }
};

struct TaxiNodesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fsifhhhbi";
        static uint8 const arraySizes[9] = { 3, 1, 2, 2, 1, 1, 1, 1, 1 };
        static DB2Meta instance(8, 9, 0x970E4A17, types, arraySizes);
        return &instance;
    }
};

struct TaxiPathMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhii";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(2, 4, 0xE194AB65, types, arraySizes);
        return &instance;
    }
};

struct TaxiPathNodeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fihhhhbbi";
        static uint8 const arraySizes[9] = { 3, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(8, 9, 0xF8DBC1E7, types, arraySizes);
        return &instance;
    }
};

struct TerrainMaterialMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x8DB3D50D, types, arraySizes);
        return &instance;
    }
};

struct TerrainTypeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shhbb";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x6F34AF2D, types, arraySizes);
        return &instance;
    }
};

struct TerrainTypeSoundsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x47B62FA7, types, arraySizes);
        return &instance;
    }
};

struct TextureBlendSetMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ifffffbbbb";
        static uint8 const arraySizes[10] = { 3, 3, 3, 3, 3, 4, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 10, 0x6FF19F2C, types, arraySizes);
        return &instance;
    }
};

struct TextureFileDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ibi";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(2, 3, 0xD01C9708, types, arraySizes);
        return &instance;
    }
};

struct TotemCategoryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sib";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x52AA4462, types, arraySizes);
        return &instance;
    }
};

struct ToyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "isbbi";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(4, 5, 0xF0409D8D, types, arraySizes);
        return &instance;
    }
};

struct TradeSkillCategoryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shhhb";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x8795B715, types, arraySizes);
        return &instance;
    }
};

struct TradeSkillItemMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xD99B4F6A, types, arraySizes);
        return &instance;
    }
};

struct TransformMatrixMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fffff";
        static uint8 const arraySizes[5] = { 3, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0xCD652C09, types, arraySizes);
        return &instance;
    }
};

struct TransmogSetMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiii";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(0, 4, 0x64CA0A37, types, arraySizes);
        return &instance;
    }
};

struct TransmogSetItemMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiii";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(0, 4, 0x36FF3392, types, arraySizes);
        return &instance;
    }
};

struct TransportAnimationMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iifb";
        static uint8 const arraySizes[4] = { 1, 1, 3, 1 };
        static DB2Meta instance(-1, 4, 0x8F3D2D53, types, arraySizes);
        return &instance;
    }
};

struct TransportPhysicsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffffffffff";
        static uint8 const arraySizes[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 10, 0x8A98A638, types, arraySizes);
        return &instance;
    }
};

struct TransportRotationMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iif";
        static uint8 const arraySizes[3] = { 1, 1, 4 };
        static DB2Meta instance(-1, 3, 0x27FC8611, types, arraySizes);
        return &instance;
    }
};

struct TrophyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shhb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xB217955D, types, arraySizes);
        return &instance;
    }
};

struct UiCamFbackTransmogChrRaceMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hbbbb";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0xCC9066D0, types, arraySizes);
        return &instance;
    }
};

struct UiCamFbackTransmogWeaponMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hbbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x23AEBF37, types, arraySizes);
        return &instance;
    }
};

struct UiCameraMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sfffhbbbi";
        static uint8 const arraySizes[9] = { 1, 3, 3, 3, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 9, 0xB26544DC, types, arraySizes);
        return &instance;
    }
};

struct UiCameraTypeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x69F34A26, types, arraySizes);
        return &instance;
    }
};

struct UiMapPOIMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ifiiiii";
        static uint8 const arraySizes[7] = { 1, 3, 1, 1, 1, 1, 1 };
        static DB2Meta instance(6, 7, 0xCEED00B2, types, arraySizes);
        return &instance;
    }
};

struct UiTextureAtlasMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihh";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x6D5738D2, types, arraySizes);
        return &instance;
    }
};

struct UiTextureAtlasMemberMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shhhhhbb";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 8, 0xFDF0C65B, types, arraySizes);
        return &instance;
    }
};

struct UiTextureKitMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xC336C8DA, types, arraySizes);
        return &instance;
    }
};

struct UnitBloodMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shhhiii";
        static uint8 const arraySizes[7] = { 5, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0x0C19FB60, types, arraySizes);
        return &instance;
    }
};

struct UnitBloodLevelsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "b";
        static uint8 const arraySizes[1] = { 3 };
        static DB2Meta instance(-1, 1, 0x24D51F50, types, arraySizes);
        return &instance;
    }
};

struct UnitConditionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ibbb";
        static uint8 const arraySizes[4] = { 8, 1, 8, 8 };
        static DB2Meta instance(-1, 4, 0x3F2E499C, types, arraySizes);
        return &instance;
    }
};

struct UnitPowerBarMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffiissssffhhbbii";
        static uint8 const arraySizes[16] = { 1, 1, 6, 6, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 16, 0x4413ED21, types, arraySizes);
        return &instance;
    }
};

struct VehicleMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iffffffffffffffffffSSSffhhhbb";
        static uint8 const arraySizes[29] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 8, 1, 3, 1, 1 };
        static DB2Meta instance(-1, 29, 0x2AC865D9, types, arraySizes);
        return &instance;
    }
};

struct VehicleSeatMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiffffffffffffffffffffffffffffffihhhhhhhhhhhhhhhhhhhbbbbbbii";
        static uint8 const arraySizes[61] = { 1, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 61, 0x78C29525, types, arraySizes);
        return &instance;
    }
};

struct VehicleUIIndSeatMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffhb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xAD2E69CE, types, arraySizes);
        return &instance;
    }
};

struct VehicleUIIndicatorMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xC76F0AED, types, arraySizes);
        return &instance;
    }
};

struct VideoHardwareMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sshhbbbbbbbbbbiiiiiiii";
        static uint8 const arraySizes[22] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(14, 22, 0x28102E83, types, arraySizes);
        return &instance;
    }
};

struct VignetteMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sffhbii";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0xB2E8B652, types, arraySizes);
        return &instance;
    }
};

struct VocalUISoundsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbbi";
        static uint8 const arraySizes[4] = { 1, 1, 1, 2 };
        static DB2Meta instance(-1, 4, 0x7552ABFD, types, arraySizes);
        return &instance;
    }
};

struct WMOAreaTableMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ishhhhhhhbbbbii";
        static uint8 const arraySizes[15] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(13, 15, 0xBCABACED, types, arraySizes);
        return &instance;
    }
};

struct WbAccessControlListMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shbbb";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0xE9DAEF18, types, arraySizes);
        return &instance;
    }
};

struct WbCertBlacklistMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sb";
        static uint8 const arraySizes[2] = { 1, 20 };
        static DB2Meta instance(-1, 2, 0xFF4C7C92, types, arraySizes);
        return &instance;
    }
};

struct WbCertWhitelistMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x38D49A50, types, arraySizes);
        return &instance;
    }
};

struct WbPermissionsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x3DE53946, types, arraySizes);
        return &instance;
    }
};

struct WeaponImpactSoundsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbbiiii";
        static uint8 const arraySizes[7] = { 1, 1, 1, 11, 11, 11, 11 };
        static DB2Meta instance(-1, 7, 0xA75127FA, types, arraySizes);
        return &instance;
    }
};

struct WeaponSwingSounds2Meta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbi";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x0F38699B, types, arraySizes);
        return &instance;
    }
};

struct WeaponTrailMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ifffiffff";
        static uint8 const arraySizes[9] = { 1, 1, 1, 1, 3, 3, 3, 3, 3 };
        static DB2Meta instance(-1, 9, 0x0D505BC8, types, arraySizes);
        return &instance;
    }
};

struct WeaponTrailModelDefMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihh";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x1C6502AA, types, arraySizes);
        return &instance;
    }
};

struct WeaponTrailParamMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fffffhbbbb";
        static uint8 const arraySizes[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 10, 0x30130FBE, types, arraySizes);
        return &instance;
    }
};

struct WeatherMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fffsfffffhbbbi";
        static uint8 const arraySizes[14] = { 2, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 14, 0x651F8E28, types, arraySizes);
        return &instance;
    }
};

struct WindSettingsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fffffffffb";
        static uint8 const arraySizes[10] = { 1, 3, 1, 1, 3, 1, 3, 1, 1, 1 };
        static DB2Meta instance(-1, 10, 0xABCC7A7C, types, arraySizes);
        return &instance;
    }
};

struct WmoMinimapTextureMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihhbb";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x10897820, types, arraySizes);
        return &instance;
    }
};

struct WorldBossLockoutMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sh";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x3E48DAA1, types, arraySizes);
        return &instance;
    }
};

struct WorldChunkSoundsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hbbbbb";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 6, 0xFEFA6C76, types, arraySizes);
        return &instance;
    }
};

struct WorldEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihhhbb";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 6, 0x9594D9DD, types, arraySizes);
        return &instance;
    }
};

struct WorldElapsedTimerMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xB57F2FF6, types, arraySizes);
        return &instance;
    }
};

struct WorldMapAreaMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "Sffffhhhhhhbbbbii";
        static uint8 const arraySizes[17] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(15, 17, 0x40BE2B6B, types, arraySizes);
        return &instance;
    }
};

struct WorldMapContinentMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffffhhbbbbb";
        static uint8 const arraySizes[11] = { 2, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 11, 0x35915CEF, types, arraySizes);
        return &instance;
    }
};

struct WorldMapOverlayMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "Shhiiiiiiiiii";
        static uint8 const arraySizes[13] = { 1, 1, 1, 1, 4, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 13, 0x638A31A5, types, arraySizes);
        return &instance;
    }
};

struct WorldMapTransformsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fffhhhhhb";
        static uint8 const arraySizes[9] = { 6, 2, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 9, 0xBB1EA93A, types, arraySizes);
        return &instance;
    }
};

struct WorldSafeLocsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffsh";
        static uint8 const arraySizes[4] = { 3, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xD3E152D4, types, arraySizes);
        return &instance;
    }
};

struct WorldStateExpressionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x702F537A, types, arraySizes);
        return &instance;
    }
};

struct WorldStateUIMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sssssshhhhhbbbbi";
        static uint8 const arraySizes[16] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1 };
        static DB2Meta instance(15, 16, 0x41F0EDEA, types, arraySizes);
        return &instance;
    }
};

struct WorldStateZoneSoundsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihhhhhhb";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 8, 0xB746727D, types, arraySizes);
        return &instance;
    }
};

struct World_PVP_AreaMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhhhhbb";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0xD070A163, types, arraySizes);
        return &instance;
    }
};

struct ZoneIntroMusicTableMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shbi";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x6BF0DF5D, types, arraySizes);
        return &instance;
    }
};

struct ZoneLightMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shh";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xFD2DACC3, types, arraySizes);
        return &instance;
    }
};

struct ZoneLightPointMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fhb";
        static uint8 const arraySizes[3] = { 2, 1, 1 };
        static DB2Meta instance(-1, 3, 0xA2F676B8, types, arraySizes);
        return &instance;
    }
};

struct ZoneMusicMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "siii";
        static uint8 const arraySizes[4] = { 1, 2, 2, 2 };
        static DB2Meta instance(-1, 4, 0x56448249, types, arraySizes);
        return &instance;
    }
};

#endif // DB2Metadata_h__
