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
        static DB2Meta instance(14, 15, 0x95189824, types, arraySizes);
        return &instance;
    }
};

struct Achievement_CategoryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shbi";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(3, 4, 0xCDFE144A, types, arraySizes);
        return &instance;
    }
};

struct AdventureJournalMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sssiisshhhhhhbbbbbbbbb";
        static uint8 const arraySizes[22] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1 };
        static DB2Meta instance(-1, 22, 0xD3689E19, types, arraySizes);
        return &instance;
    }
};

struct AdventureMapPOIMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fissbiiiiiiii";
        static uint8 const arraySizes[13] = { 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 13, 0x8DD3DD67, types, arraySizes);
        return &instance;
    }
};

struct AnimKitMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihh";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x99250BF2, types, arraySizes);
        return &instance;
    }
};

struct AnimKitBoneSetMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbbbb";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0xA63507C5, types, arraySizes);
        return &instance;
    }
};

struct AnimKitBoneSetAliasMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xFD752B70, types, arraySizes);
        return &instance;
    }
};

struct AnimKitConfigMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x0B40EAF2, types, arraySizes);
        return &instance;
    }
};

struct AnimKitConfigBoneSetMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x203DD58D, types, arraySizes);
        return &instance;
    }
};

struct AnimKitPriorityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "b";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x90C43431, types, arraySizes);
        return &instance;
    }
};

struct AnimKitSegmentMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiifihhhbbbbbbbi";
        static uint8 const arraySizes[16] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 16, 0xFC70F1F7, types, arraySizes);
        return &instance;
    }
};

struct AnimReplacementMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhhh";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xC2595AFB, types, arraySizes);
        return &instance;
    }
};

struct AnimReplacementSetMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "b";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xCCB4EEFC, types, arraySizes);
        return &instance;
    }
};

struct AnimationDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sihhb";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x0C30F30A, types, arraySizes);
        return &instance;
    }
};

struct AreaFarClipOverrideMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iffii";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(4, 5, 0x3D8AF772, types, arraySizes);
        return &instance;
    }
};

struct AreaGroupMemberMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hh";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xEF8BF246, types, arraySizes);
        return &instance;
    }
};

struct AreaPOIMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fsshhhhhhihbbi";
        static uint8 const arraySizes[14] = { 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 14, 0xF472BD34, types, arraySizes);
        return &instance;
    }
};

struct AreaPOIStateMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shbbi";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x22D72122, types, arraySizes);
        return &instance;
    }
};

struct AreaTableMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "isfshhhhhhhhhhbbbbbbbbi";
        static uint8 const arraySizes[23] = { 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 23, 0x34DD9AFD, types, arraySizes);
        return &instance;
    }
};

struct AreaTriggerMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffffffhhhhhbbbi";
        static uint8 const arraySizes[15] = { 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(14, 15, 0xEDF45FE2, types, arraySizes);
        return &instance;
    }
};

struct AreaTriggerActionSetMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "h";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x031AD377, types, arraySizes);
        return &instance;
    }
};

struct AreaTriggerBoxMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "f";
        static uint8 const arraySizes[1] = { 3 };
        static DB2Meta instance(-1, 1, 0xB6CF49AC, types, arraySizes);
        return &instance;
    }
};

struct AreaTriggerCylinderMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fff";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x0BF8A90F, types, arraySizes);
        return &instance;
    }
};

struct AreaTriggerSphereMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "f";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x532CDBE5, types, arraySizes);
        return &instance;
    }
};

struct ArmorLocationMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fffff";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x1354FFD8, types, arraySizes);
        return &instance;
    }
};

struct ArtifactMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "siiihhbb";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 8, 0x045C232B, types, arraySizes);
        return &instance;
    }
};

struct ArtifactAppearanceMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "siffihhhbbbbiii";
        static uint8 const arraySizes[15] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(12, 15, 0x80AD1607, types, arraySizes);
        return &instance;
    }
};

struct ArtifactAppearanceSetMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sshhbbbbi";
        static uint8 const arraySizes[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(8, 9, 0xC53DCC8A, types, arraySizes);
        return &instance;
    }
};

struct ArtifactCategoryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hh";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x73691C0D, types, arraySizes);
        return &instance;
    }
};

struct ArtifactPowerMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fbbbii";
        static uint8 const arraySizes[6] = { 2, 1, 1, 1, 1, 1 };
        static DB2Meta instance(4, 6, 0xB81D03F6, types, arraySizes);
        return &instance;
    }
};

struct ArtifactPowerLinkMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hh";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x668C691C, types, arraySizes);
        return &instance;
    }
};

struct ArtifactPowerRankMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ifhhb";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0xC6BC97C0, types, arraySizes);
        return &instance;
    }
};

struct ArtifactQuestXPMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i";
        static uint8 const arraySizes[1] = { 10 };
        static DB2Meta instance(-1, 1, 0xBF20E8C0, types, arraySizes);
        return &instance;
    }
};

struct ArtifactUnlockMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhbbi";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0xD456B4E1, types, arraySizes);
        return &instance;
    }
};

struct AuctionHouseMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x575B67A7, types, arraySizes);
        return &instance;
    }
};

struct BankBagSlotPricesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xB05E02B4, types, arraySizes);
        return &instance;
    }
};

struct BannedAddOnsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xAE353B8F, types, arraySizes);
        return &instance;
    }
};

struct BarberShopStyleMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssfbbbbi";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(7, 8, 0xB5E14DAA, types, arraySizes);
        return &instance;
    }
};

struct BattlePetAbilityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "isshbbi";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0xB120A510, types, arraySizes);
        return &instance;
    }
};

struct BattlePetAbilityEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhhhhbi";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 6, 1, 1 };
        static DB2Meta instance(6, 7, 0x90F49D37, types, arraySizes);
        return &instance;
    }
};

struct BattlePetAbilityStateMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x3819C91A, types, arraySizes);
        return &instance;
    }
};

struct BattlePetAbilityTurnMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhbbbi";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(5, 6, 0x9683E767, types, arraySizes);
        return &instance;
    }
};

struct BattlePetBreedQualityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x7BA0AA85, types, arraySizes);
        return &instance;
    }
};

struct BattlePetBreedStateMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hbb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x86797087, types, arraySizes);
        return &instance;
    }
};

struct BattlePetEffectPropertiesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shb";
        static uint8 const arraySizes[3] = { 6, 1, 6 };
        static DB2Meta instance(-1, 3, 0xB4163BC7, types, arraySizes);
        return &instance;
    }
};

struct BattlePetNPCTeamMemberMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xC7290625, types, arraySizes);
        return &instance;
    }
};

struct BattlePetSpeciesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiisshbbi";
        static uint8 const arraySizes[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(8, 9, 0x294C6926, types, arraySizes);
        return &instance;
    }
};

struct BattlePetSpeciesStateMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xAFB2B852, types, arraySizes);
        return &instance;
    }
};

struct BattlePetSpeciesXAbilityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xE5CA0BAA, types, arraySizes);
        return &instance;
    }
};

struct BattlePetStateMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x13716630, types, arraySizes);
        return &instance;
    }
};

struct BattlePetVisualMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shhhhbb";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0x7857D92C, types, arraySizes);
        return &instance;
    }
};

struct BattlemasterListMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sishhhbbbbbbbbb";
        static uint8 const arraySizes[15] = { 1, 1, 1, 16, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 15, 0x99250B06, types, arraySizes);
        return &instance;
    }
};

struct BoneWindModifierModelMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ii";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x4A4D9772, types, arraySizes);
        return &instance;
    }
};

struct BoneWindModifiersMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ff";
        static uint8 const arraySizes[2] = { 3, 1 };
        static DB2Meta instance(-1, 2, 0x4372F1C2, types, arraySizes);
        return &instance;
    }
};

struct BountyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihhb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x55137DC9, types, arraySizes);
        return &instance;
    }
};

struct BountySetMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hh";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x9F2C269D, types, arraySizes);
        return &instance;
    }
};

struct BroadcastTextMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sshhhbbii";
        static uint8 const arraySizes[9] = { 1, 1, 3, 3, 1, 1, 1, 2, 1 };
        static DB2Meta instance(-1, 9, 0xA5D40DCD, types, arraySizes);
        return &instance;
    }
};

struct CameraEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "b";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xC78EC624, types, arraySizes);
        return &instance;
    }
};

struct CameraEffectEntryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffffffffhhbbbbbb";
        static uint8 const arraySizes[16] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 16, 0x5B2E6D11, types, arraySizes);
        return &instance;
    }
};

struct CameraModeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fffffhbbbbb";
        static uint8 const arraySizes[11] = { 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 11, 0xE917E35D, types, arraySizes);
        return &instance;
    }
};

struct CastableRaidBuffsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ii";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xB679347C, types, arraySizes);
        return &instance;
    }
};

struct Cfg_CategoriesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shbbb";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x9D74E29F, types, arraySizes);
        return &instance;
    }
};

struct Cfg_ConfigsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fhbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x614156FB, types, arraySizes);
        return &instance;
    }
};

struct Cfg_RegionsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sibb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x12FE83BB, types, arraySizes);
        return &instance;
    }
};

struct CharBaseInfoMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x02E25610, types, arraySizes);
        return &instance;
    }
};

struct CharBaseSectionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x4A6DADB1, types, arraySizes);
        return &instance;
    }
};

struct CharComponentTextureLayoutsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hh";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xC4B70FAC, types, arraySizes);
        return &instance;
    }
};

struct CharComponentTextureSectionsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhhhbbb";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0x38B71859, types, arraySizes);
        return &instance;
    }
};

struct CharHairGeosetsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ibbbbbbbbi";
        static uint8 const arraySizes[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 10, 0xC9C48A1A, types, arraySizes);
        return &instance;
    }
};

struct CharSectionsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihbbbbb";
        static uint8 const arraySizes[7] = { 3, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0x24CEF061, types, arraySizes);
        return &instance;
    }
};

struct CharShipmentMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiiihbb";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 8, 0x67EDB3A4, types, arraySizes);
        return &instance;
    }
};

struct CharShipmentContainerMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sshhhhhhbbbbbbbi";
        static uint8 const arraySizes[16] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 16, 0xA277E259, types, arraySizes);
        return &instance;
    }
};

struct CharStartOutfitMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iibbbbb";
        static uint8 const arraySizes[7] = { 24, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0xA01541A2, types, arraySizes);
        return &instance;
    }
};

struct CharTitlesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sshb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xD9F524BD, types, arraySizes);
        return &instance;
    }
};

struct CharacterFaceBoneSetMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ibbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x7FF28BE6, types, arraySizes);
        return &instance;
    }
};

struct CharacterFacialHairStylesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ibbb";
        static uint8 const arraySizes[4] = { 5, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xC2DF2CBC, types, arraySizes);
        return &instance;
    }
};

struct CharacterLoadoutMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ibb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x7569FA0F, types, arraySizes);
        return &instance;
    }
};

struct CharacterLoadoutItemMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ih";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xAF935C05, types, arraySizes);
        return &instance;
    }
};

struct ChatChannelsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "issb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x2BA2AD26, types, arraySizes);
        return &instance;
    }
};

struct ChatProfanityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x1ECE183A, types, arraySizes);
        return &instance;
    }
};

struct ChrClassRaceSexMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbbiii";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 6, 0xCBF79DCD, types, arraySizes);
        return &instance;
    }
};

struct ChrClassTitleMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x55B37180, types, arraySizes);
        return &instance;
    }
};

struct ChrClassUIDisplayMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x714A7125, types, arraySizes);
        return &instance;
    }
};

struct ChrClassVillainMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x0FF98924, types, arraySizes);
        return &instance;
    }
};

struct ChrClassesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sssssiiiihhhbbbbbbi";
        static uint8 const arraySizes[19] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(18, 19, 0x60BF86D8, types, arraySizes);
        return &instance;
    }
};

struct ChrClassesXPowerTypesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x698836AB, types, arraySizes);
        return &instance;
    }
};

struct ChrRacesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "isssssssiiffihhhhhhhhhbbbbbbbbbbiii";
        static uint8 const arraySizes[35] = { 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3 };
        static DB2Meta instance(-1, 35, 0xA3A7EAC0, types, arraySizes);
        return &instance;
    }
};

struct ChrSpecializationMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "isssshbbbbbiii";
        static uint8 const arraySizes[14] = { 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(11, 14, 0x1A96EDE4, types, arraySizes);
        return &instance;
    }
};

struct ChrUpgradeBucketMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hbi";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(2, 3, 0xA1617BFA, types, arraySizes);
        return &instance;
    }
};

struct ChrUpgradeBucketSpellMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ih";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x51190FCD, types, arraySizes);
        return &instance;
    }
};

struct ChrUpgradeTierMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbbi";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(3, 4, 0x7A954DB6, types, arraySizes);
        return &instance;
    }
};

struct CinematicCameraMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sffh";
        static uint8 const arraySizes[4] = { 1, 3, 1, 1 };
        static DB2Meta instance(-1, 4, 0xA7B95349, types, arraySizes);
        return &instance;
    }
};

struct CinematicSequencesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hh";
        static uint8 const arraySizes[2] = { 1, 8 };
        static DB2Meta instance(-1, 2, 0xEDED096E, types, arraySizes);
        return &instance;
    }
};

struct CloakDampeningMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fffffff";
        static uint8 const arraySizes[7] = { 5, 5, 2, 2, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0x12019748, types, arraySizes);
        return &instance;
    }
};

struct CombatConditionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhhhhbbbbbb";
        static uint8 const arraySizes[11] = { 1, 1, 1, 2, 2, 2, 2, 1, 2, 2, 1 };
        static DB2Meta instance(-1, 11, 0x272B0E74, types, arraySizes);
        return &instance;
    }
};

struct ComponentModelFileDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xCB3BCC73, types, arraySizes);
        return &instance;
    }
};

struct ComponentTextureFileDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xEFF4D5A1, types, arraySizes);
        return &instance;
    }
};

struct ConversationLineMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiihhbbb";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 8, 0x9630B1BB, types, arraySizes);
        return &instance;
    }
};

struct CreatureMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiifssssbbbb";
        static uint8 const arraySizes[12] = { 3, 1, 4, 4, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 12, 0xE4FD6645, types, arraySizes);
        return &instance;
    }
};

struct CreatureDifficultyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iihbbb";
        static uint8 const arraySizes[6] = { 1, 7, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 6, 0x32877374, types, arraySizes);
        return &instance;
    }
};

struct CreatureDispXUiCameraMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ih";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xB29B32B1, types, arraySizes);
        return &instance;
    }
};

struct CreatureDisplayInfoMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iffisiiifhhhhhhbbbbbb";
        static uint8 const arraySizes[21] = { 1, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 21, 0xABD08A04, types, arraySizes);
        return &instance;
    }
};

struct CreatureDisplayInfoCondMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiibbiiiiiiiii";
        static uint8 const arraySizes[15] = { 1, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3 };
        static DB2Meta instance(-1, 15, 0x0D0A694C, types, arraySizes);
        return &instance;
    }
};

struct CreatureDisplayInfoExtraMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iibbbbbbbbbb";
        static uint8 const arraySizes[12] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1 };
        static DB2Meta instance(-1, 12, 0xE5D838DA, types, arraySizes);
        return &instance;
    }
};

struct CreatureDisplayInfoTrnMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iifh";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xDEBF0D7C, types, arraySizes);
        return &instance;
    }
};

struct CreatureFamilyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffsshhbbb";
        static uint8 const arraySizes[9] = { 1, 1, 1, 1, 2, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 9, 0xDF8261E1, types, arraySizes);
        return &instance;
    }
};

struct CreatureImmunitiesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ibbbbbiii";
        static uint8 const arraySizes[9] = { 2, 1, 1, 1, 1, 1, 1, 8, 16 };
        static DB2Meta instance(-1, 9, 0xB19897AD, types, arraySizes);
        return &instance;
    }
};

struct CreatureModelDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffffffffffffffffffiiiiiiiiii";
        static uint8 const arraySizes[28] = { 1, 1, 1, 1, 1, 1, 1, 6, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 28, 0xE9433C0E, types, arraySizes);
        return &instance;
    }
};

struct CreatureMovementInfoMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "f";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x5510F319, types, arraySizes);
        return &instance;
    }
};

struct CreatureSoundDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffbbiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii";
        static uint8 const arraySizes[37] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 5, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 37, 0x902B75D5, types, arraySizes);
        return &instance;
    }
};

struct CreatureTypeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xC284FF64, types, arraySizes);
        return &instance;
    }
};

struct CriteriaMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiihhhbbbbb";
        static uint8 const arraySizes[11] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 11, 0x82A6B9CD, types, arraySizes);
        return &instance;
    }
};

struct CriteriaTreeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iishhbi";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0x896CF168, types, arraySizes);
        return &instance;
    }
};

struct CriteriaTreeXEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hh";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x4EB7207E, types, arraySizes);
        return &instance;
    }
};

struct CurrencyCategoryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xD77A397C, types, arraySizes);
        return &instance;
    }
};

struct CurrencyTypesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssiiisbbbi";
        static uint8 const arraySizes[10] = { 1, 2, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 10, 0x9404737C, types, arraySizes);
        return &instance;
    }
};

struct CurveMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xB2E1D774, types, arraySizes);
        return &instance;
    }
};

struct CurvePointMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fhb";
        static uint8 const arraySizes[3] = { 2, 1, 1 };
        static DB2Meta instance(-1, 3, 0x9A0F148D, types, arraySizes);
        return &instance;
    }
};

struct DeathThudLookupsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbii";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x047DB23C, types, arraySizes);
        return &instance;
    }
};

struct DecalPropertiesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iffffffffbbiii";
        static uint8 const arraySizes[14] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 14, 0x11C0EE5C, types, arraySizes);
        return &instance;
    }
};

struct DeclinedWordMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "si";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(1, 2, 0x0ADEF922, types, arraySizes);
        return &instance;
    }
};

struct DeclinedWordCasesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbi";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x69C1484B, types, arraySizes);
        return &instance;
    }
};

struct DestructibleModelDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhhhhbbbbbbbbbbbbbbbbb";
        static uint8 const arraySizes[22] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 22, 0x51E17C9F, types, arraySizes);
        return &instance;
    }
};

struct DeviceBlacklistMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hh";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x8D8F5139, types, arraySizes);
        return &instance;
    }
};

struct DeviceDefaultSettingsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x1D359D4E, types, arraySizes);
        return &instance;
    }
};

struct DifficultyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbbbbbbbbbbbb";
        static uint8 const arraySizes[13] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 13, 0xA4863806, types, arraySizes);
        return &instance;
    }
};

struct DissolveEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fffffffbbii";
        static uint8 const arraySizes[11] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 11, 0xF2FF2CDE, types, arraySizes);
        return &instance;
    }
};

struct DriverBlacklistMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iihbbbb";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0x5B13B6CF, types, arraySizes);
        return &instance;
    }
};

struct DungeonEncounterMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "isihhbbbi";
        static uint8 const arraySizes[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(0, 9, 0x8E0853BB, types, arraySizes);
        return &instance;
    }
};

struct DungeonMapMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffhhbbbi";
        static uint8 const arraySizes[8] = { 2, 2, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(7, 8, 0x778A28E4, types, arraySizes);
        return &instance;
    }
};

struct DungeonMapChunkMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fihhh";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x3D797109, types, arraySizes);
        return &instance;
    }
};

struct DurabilityCostsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hh";
        static uint8 const arraySizes[2] = { 21, 8 };
        static DB2Meta instance(-1, 2, 0xC0CAAB42, types, arraySizes);
        return &instance;
    }
};

struct DurabilityQualityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "f";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xC7583507, types, arraySizes);
        return &instance;
    }
};

struct EdgeGlowEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fffffffffb";
        static uint8 const arraySizes[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 10, 0x5F18B5D8, types, arraySizes);
        return &instance;
    }
};

struct EmotesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "siihbiiii";
        static uint8 const arraySizes[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 9, 0xB540EE47, types, arraySizes);
        return &instance;
    }
};

struct EmotesTextMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sh";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xB9A8E504, types, arraySizes);
        return &instance;
    }
};

struct EmotesTextDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xD3577B09, types, arraySizes);
        return &instance;
    }
};

struct EmotesTextSoundMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hbbbi";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x3F7731F0, types, arraySizes);
        return &instance;
    }
};

struct EnvironmentalDamageMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xD6505814, types, arraySizes);
        return &instance;
    }
};

struct ExhaustionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ifffsfsi";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(7, 8, 0x5868E9E5, types, arraySizes);
        return &instance;
    }
};

struct FactionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iifssihhhhbbbb";
        static uint8 const arraySizes[14] = { 4, 4, 2, 1, 1, 4, 1, 4, 4, 1, 2, 1, 1, 1 };
        static DB2Meta instance(-1, 14, 0x3C7163E7, types, arraySizes);
        return &instance;
    }
};

struct FactionGroupMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xF72219DD, types, arraySizes);
        return &instance;
    }
};

struct FactionTemplateMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhhhbbb";
        static uint8 const arraySizes[7] = { 1, 1, 4, 4, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0x81451073, types, arraySizes);
        return &instance;
    }
};

struct FootprintTexturesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "si";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(1, 2, 0x93F7CD69, types, arraySizes);
        return &instance;
    }
};

struct FootstepTerrainLookupMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hbii";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x22C3D6AE, types, arraySizes);
        return &instance;
    }
};

struct FriendshipRepReactionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x41F0EB0D, types, arraySizes);
        return &instance;
    }
};

struct FriendshipReputationMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ishi";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(3, 4, 0xD0CC64D3, types, arraySizes);
        return &instance;
    }
};

struct FullScreenEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fffffffffffffffffffiiffffffffffffffbiii";
        static uint8 const arraySizes[39] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 39, 0x5477D956, types, arraySizes);
        return &instance;
    }
};

struct GMSurveyAnswersMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbi";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xD25A45BC, types, arraySizes);
        return &instance;
    }
};

struct GMSurveyCurrentSurveyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "b";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xBBEF1D69, types, arraySizes);
        return &instance;
    }
};

struct GMSurveyQuestionsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x12F42FB6, types, arraySizes);
        return &instance;
    }
};

struct GMSurveySurveysMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "b";
        static uint8 const arraySizes[1] = { 15 };
        static DB2Meta instance(-1, 1, 0x05223914, types, arraySizes);
        return &instance;
    }
};

struct GameObjectArtKitMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ss";
        static uint8 const arraySizes[2] = { 3, 4 };
        static DB2Meta instance(-1, 2, 0x9BD6060B, types, arraySizes);
        return &instance;
    }
};

struct GameObjectDiffAnimMapMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hbbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xA0585C8F, types, arraySizes);
        return &instance;
    }
};

struct GameObjectDisplayInfoMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ifffh";
        static uint8 const arraySizes[5] = { 1, 6, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0xE2D6FAB7, types, arraySizes);
        return &instance;
    }
};

struct GameObjectDisplayInfoXSoundKitMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xFF6FE0EC, types, arraySizes);
        return &instance;
    }
};

struct GameObjectsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fffishhhhbbi";
        static uint8 const arraySizes[12] = { 3, 4, 1, 8, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(11, 12, 0x4B699AFB, types, arraySizes);
        return &instance;
    }
};

struct GameTipsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x8412F9E7, types, arraySizes);
        return &instance;
    }
};

struct GarrAbilityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssihhbbi";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(7, 8, 0xEF3E98A9, types, arraySizes);
        return &instance;
    }
};

struct GarrAbilityCategoryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xC7290625, types, arraySizes);
        return &instance;
    }
};

struct GarrAbilityEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fffihbbbbbbi";
        static uint8 const arraySizes[12] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(11, 12, 0xF8543595, types, arraySizes);
        return &instance;
    }
};

struct GarrBuildingMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iissssihhhhhhhhbbbbbbiii";
        static uint8 const arraySizes[24] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 24, 0x9CB292DE, types, arraySizes);
        return &instance;
    }
};

struct GarrBuildingDoodadSetMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbbbb";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x6743FE91, types, arraySizes);
        return &instance;
    }
};

struct GarrBuildingPlotInstMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fhhbi";
        static uint8 const arraySizes[5] = { 2, 1, 1, 1, 1 };
        static DB2Meta instance(4, 5, 0x91C29C99, types, arraySizes);
        return &instance;
    }
};

struct GarrClassSpecMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssshbbbi";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(7, 8, 0x6E7FE0D1, types, arraySizes);
        return &instance;
    }
};

struct GarrClassSpecPlayerCondMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "isbiii";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 6, 0xC1F58546, types, arraySizes);
        return &instance;
    }
};

struct GarrEncounterMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "isffihi";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(6, 7, 0xDF397D9E, types, arraySizes);
        return &instance;
    }
};

struct GarrEncounterSetXEncounterMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ii";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x10FFAB35, types, arraySizes);
        return &instance;
    }
};

struct GarrEncounterXMechanicMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hbb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x18517C71, types, arraySizes);
        return &instance;
    }
};

struct GarrFollItemSetMemberMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihhb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xDCA5714F, types, arraySizes);
        return &instance;
    }
};

struct GarrFollSupportSpellMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iibi";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x1C55B981, types, arraySizes);
        return &instance;
    }
};

struct GarrFollowerMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iissiiiihhhhhhbbbbbbbbbbbbbbbbi";
        static uint8 const arraySizes[31] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(30, 31, 0x29B8937A, types, arraySizes);
        return &instance;
    }
};

struct GarrFollowerLevelXPMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xFFE1B062, types, arraySizes);
        return &instance;
    }
};

struct GarrFollowerQualityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihbbbbi";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0xFC4B0E8C, types, arraySizes);
        return &instance;
    }
};

struct GarrFollowerSetXFollowerMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ii";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xFBF2EEC7, types, arraySizes);
        return &instance;
    }
};

struct GarrFollowerTypeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hbbbbbb";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0xEA68CDE6, types, arraySizes);
        return &instance;
    }
};

struct GarrFollowerUICreatureMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ifhbbb";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 6, 0x438C8EE4, types, arraySizes);
        return &instance;
    }
};

struct GarrFollowerXAbilityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x383ECAF5, types, arraySizes);
        return &instance;
    }
};

struct GarrMechanicMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fbi";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x53840C97, types, arraySizes);
        return &instance;
    }
};

struct GarrMechanicSetXMechanicMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(1, 3, 0xB1E026AD, types, arraySizes);
        return &instance;
    }
};

struct GarrMechanicTypeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssibi";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(4, 5, 0xA0666F41, types, arraySizes);
        return &instance;
    }
};

struct GarrMissionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iisssffhhhhhhbbbbbbbbbiiiiiii";
        static uint8 const arraySizes[29] = { 1, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(22, 29, 0xD5EA8A8F, types, arraySizes);
        return &instance;
    }
};

struct GarrMissionTextureMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fh";
        static uint8 const arraySizes[2] = { 2, 1 };
        static DB2Meta instance(-1, 2, 0x23676140, types, arraySizes);
        return &instance;
    }
};

struct GarrMissionTypeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shh";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xDB3475F8, types, arraySizes);
        return &instance;
    }
};

struct GarrMissionXEncounterMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "biiii";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(1, 5, 0x46A9DA96, types, arraySizes);
        return &instance;
    }
};

struct GarrMissionXFollowerMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xD690F927, types, arraySizes);
        return &instance;
    }
};

struct GarrMssnBonusAbilityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fihbb";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0xF38EA42C, types, arraySizes);
        return &instance;
    }
};

struct GarrPlotMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "siibbbi";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 2 };
        static DB2Meta instance(-1, 7, 0xD59B7CAE, types, arraySizes);
        return &instance;
    }
};

struct GarrPlotBuildingMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xD1C720D2, types, arraySizes);
        return &instance;
    }
};

struct GarrPlotInstanceMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x97FC2737, types, arraySizes);
        return &instance;
    }
};

struct GarrPlotUICategoryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x7A4BC3A6, types, arraySizes);
        return &instance;
    }
};

struct GarrSiteLevelMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fhhhhbbbb";
        static uint8 const arraySizes[9] = { 2, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 9, 0x149CFC3A, types, arraySizes);
        return &instance;
    }
};

struct GarrSiteLevelPlotInstMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fhbb";
        static uint8 const arraySizes[4] = { 2, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xC927B825, types, arraySizes);
        return &instance;
    }
};

struct GarrSpecializationMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ifssbbb";
        static uint8 const arraySizes[7] = { 1, 2, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0xFCB39A5B, types, arraySizes);
        return &instance;
    }
};

struct GarrStringMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xC3BC61DD, types, arraySizes);
        return &instance;
    }
};

struct GarrTalentMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "issibbbiiiiiiiiiiiii";
        static uint8 const arraySizes[20] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(7, 20, 0x2CD56738, types, arraySizes);
        return &instance;
    }
};

struct GarrTalentTreeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbii";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x473D1B66, types, arraySizes);
        return &instance;
    }
};

struct GarrTypeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiii";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0xF4EAC5C2, types, arraySizes);
        return &instance;
    }
};

struct GarrUiAnimClassInfoMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fhbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x0CCE756E, types, arraySizes);
        return &instance;
    }
};

struct GarrUiAnimRaceInfoMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffffffffffffb";
        static uint8 const arraySizes[13] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 13, 0x332C8478, types, arraySizes);
        return &instance;
    }
};

struct GemPropertiesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihh";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x2C970C09, types, arraySizes);
        return &instance;
    }
};

struct GlobalStringsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xAA0E6518, types, arraySizes);
        return &instance;
    }
};

struct GlyphBindableSpellMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ih";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x27B5FEE6, types, arraySizes);
        return &instance;
    }
};

struct GlyphExclusiveCategoryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xC7290625, types, arraySizes);
        return &instance;
    }
};

struct GlyphPropertiesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xF6DCEE71, types, arraySizes);
        return &instance;
    }
};

struct GlyphRequiredSpecMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hh";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xD29FB6FC, types, arraySizes);
        return &instance;
    }
};

struct GroundEffectDoodadMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sffb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xF1841C2E, types, arraySizes);
        return &instance;
    }
};

struct GroundEffectTextureMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hbbi";
        static uint8 const arraySizes[4] = { 4, 4, 1, 1 };
        static DB2Meta instance(-1, 4, 0x7D3B912E, types, arraySizes);
        return &instance;
    }
};

struct GroupFinderActivityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sshhhbbbbbbbbb";
        static uint8 const arraySizes[14] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 14, 0x82B60500, types, arraySizes);
        return &instance;
    }
};

struct GroupFinderActivityGrpMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x8B38FE85, types, arraySizes);
        return &instance;
    }
};

struct GroupFinderCategoryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x5EC4D7B0, types, arraySizes);
        return &instance;
    }
};

struct GuildColorBackgroundMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x0D49EA9B, types, arraySizes);
        return &instance;
    }
};

struct GuildColorBorderMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x0D49EA9B, types, arraySizes);
        return &instance;
    }
};

struct GuildColorEmblemMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x0D49EA9B, types, arraySizes);
        return &instance;
    }
};

struct GuildPerkSpellsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xE6CDCEB1, types, arraySizes);
        return &instance;
    }
};

struct HeirloomMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "isiiiihbbi";
        static uint8 const arraySizes[10] = { 1, 1, 1, 1, 1, 2, 2, 1, 1, 1 };
        static DB2Meta instance(9, 10, 0xBE1439F6, types, arraySizes);
        return &instance;
    }
};

struct HelmetAnimScalingMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x4416251C, types, arraySizes);
        return &instance;
    }
};

struct HelmetGeosetVisDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i";
        static uint8 const arraySizes[1] = { 9 };
        static DB2Meta instance(-1, 1, 0xBC4812D7, types, arraySizes);
        return &instance;
    }
};

struct HighlightColorMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiibb";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x900036FD, types, arraySizes);
        return &instance;
    }
};

struct HolidayDescriptionsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x2E7616FA, types, arraySizes);
        return &instance;
    }
};

struct HolidayNamesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xC7290625, types, arraySizes);
        return &instance;
    }
};

struct HolidaysMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iishhbbbbbbb";
        static uint8 const arraySizes[12] = { 1, 16, 1, 10, 1, 1, 10, 1, 1, 1, 1, 1 };
        static DB2Meta instance(0, 12, 0xAB34E6EE, types, arraySizes);
        return &instance;
    }
};

struct ImportPriceArmorMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffff";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x62B804AB, types, arraySizes);
        return &instance;
    }
};

struct ImportPriceQualityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "f";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xC7583507, types, arraySizes);
        return &instance;
    }
};

struct ImportPriceShieldMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "f";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xC7583507, types, arraySizes);
        return &instance;
    }
};

struct ImportPriceWeaponMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "f";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xC7583507, types, arraySizes);
        return &instance;
    }
};

struct InvasionClientDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sfiiiiiiii";
        static uint8 const arraySizes[10] = { 1, 2, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(2, 10, 0x03273408, types, arraySizes);
        return &instance;
    }
};

struct ItemMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ibbbbbbb";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 8, 0x9EABD639, types, arraySizes);
        return &instance;
    }
};

struct ItemAppearanceMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiib";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xDA5B3C85, types, arraySizes);
        return &instance;
    }
};

struct ItemAppearanceXUiCameraMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hh";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xAE12D15D, types, arraySizes);
        return &instance;
    }
};

struct ItemArmorQualityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fh";
        static uint8 const arraySizes[2] = { 7, 1 };
        static DB2Meta instance(-1, 2, 0x7C79232C, types, arraySizes);
        return &instance;
    }
};

struct ItemArmorShieldMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fh";
        static uint8 const arraySizes[2] = { 7, 1 };
        static DB2Meta instance(-1, 2, 0xB7443971, types, arraySizes);
        return &instance;
    }
};

struct ItemArmorTotalMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffffh";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x253BAEE3, types, arraySizes);
        return &instance;
    }
};

struct ItemBagFamilyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xC7290625, types, arraySizes);
        return &instance;
    }
};

struct ItemBonusMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihbb";
        static uint8 const arraySizes[4] = { 2, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x8081F714, types, arraySizes);
        return &instance;
    }
};

struct ItemBonusListLevelDeltaMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hi";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(1, 2, 0x7697CF5D, types, arraySizes);
        return &instance;
    }
};

struct ItemBonusTreeNodeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhhb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x26374458, types, arraySizes);
        return &instance;
    }
};

struct ItemChildEquipmentMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iib";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x88AA718C, types, arraySizes);
        return &instance;
    }
};

struct ItemClassMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fsbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xAA6F70FC, types, arraySizes);
        return &instance;
    }
};

struct ItemContextPickerEntryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbiii";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0xE5AC6798, types, arraySizes);
        return &instance;
    }
};

struct ItemCurrencyCostMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x29CEF0F6, types, arraySizes);
        return &instance;
    }
};

struct ItemDamageAmmoMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fh";
        static uint8 const arraySizes[2] = { 7, 1 };
        static DB2Meta instance(-1, 2, 0xB7443971, types, arraySizes);
        return &instance;
    }
};

struct ItemDamageOneHandMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fh";
        static uint8 const arraySizes[2] = { 7, 1 };
        static DB2Meta instance(-1, 2, 0xB7443971, types, arraySizes);
        return &instance;
    }
};

struct ItemDamageOneHandCasterMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fh";
        static uint8 const arraySizes[2] = { 7, 1 };
        static DB2Meta instance(-1, 2, 0xB7443971, types, arraySizes);
        return &instance;
    }
};

struct ItemDamageTwoHandMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fh";
        static uint8 const arraySizes[2] = { 7, 1 };
        static DB2Meta instance(-1, 2, 0xB7443971, types, arraySizes);
        return &instance;
    }
};

struct ItemDamageTwoHandCasterMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fh";
        static uint8 const arraySizes[2] = { 7, 1 };
        static DB2Meta instance(-1, 2, 0xB7443971, types, arraySizes);
        return &instance;
    }
};

struct ItemDisenchantLootMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhhbbb";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 6, 0x6756CB43, types, arraySizes);
        return &instance;
    }
};

struct ItemDisplayInfoMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiiiiiiiiiiiii";
        static uint8 const arraySizes[15] = { 2, 2, 3, 3, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 15, 0xBE73C711, types, arraySizes);
        return &instance;
    }
};

struct ItemDisplayInfoMaterialResMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iib";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xC2F154A5, types, arraySizes);
        return &instance;
    }
};

struct ItemDisplayXUiCameraMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ih";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x68C79226, types, arraySizes);
        return &instance;
    }
};

struct ItemEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiihhhbb";
        static uint8 const arraySizes[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 9, 0x874EE6D6, types, arraySizes);
        return &instance;
    }
};

struct ItemExtendedCostMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iihhhbbbbb";
        static uint8 const arraySizes[10] = { 5, 5, 5, 1, 5, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 10, 0xDFABA73B, types, arraySizes);
        return &instance;
    }
};

struct ItemGroupSoundsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i";
        static uint8 const arraySizes[1] = { 4 };
        static DB2Meta instance(-1, 1, 0x3EEA4BE4, types, arraySizes);
        return &instance;
    }
};

struct ItemLimitCategoryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x74E301FB, types, arraySizes);
        return &instance;
    }
};

struct ItemLimitCategoryConditionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x1609ED4D, types, arraySizes);
        return &instance;
    }
};

struct ItemModifiedAppearanceMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihbbbi";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(5, 6, 0xDFD4F953, types, arraySizes);
        return &instance;
    }
};

struct ItemModifiedAppearanceExtraMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iibbb";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x0D36FDB0, types, arraySizes);
        return &instance;
    }
};

struct ItemNameDescriptionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "si";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x5C280FE0, types, arraySizes);
        return &instance;
    }
};

struct ItemPetFoodMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xA75DB185, types, arraySizes);
        return &instance;
    }
};

struct ItemPriceBaseMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffh";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x5B07F241, types, arraySizes);
        return &instance;
    }
};

struct ItemRandomPropertiesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sh";
        static uint8 const arraySizes[2] = { 1, 5 };
        static DB2Meta instance(-1, 2, 0x76CA3B88, types, arraySizes);
        return &instance;
    }
};

struct ItemRandomSuffixMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shh";
        static uint8 const arraySizes[3] = { 1, 5, 5 };
        static DB2Meta instance(-1, 3, 0xE2A58F9F, types, arraySizes);
        return &instance;
    }
};

struct ItemRangedDisplayInfoMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiii";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xD8FA47D9, types, arraySizes);
        return &instance;
    }
};

struct ItemSearchNameMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "siiihhhhbbbbi";
        static uint8 const arraySizes[13] = { 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 13, 0x1F0753BA, types, arraySizes);
        return &instance;
    }
};

struct ItemSetMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sihii";
        static uint8 const arraySizes[5] = { 1, 17, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x0390F3A4, types, arraySizes);
        return &instance;
    }
};

struct ItemSetSpellMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihhb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xF9A57500, types, arraySizes);
        return &instance;
    }
};

struct ItemSparseMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iffiiiiiiiiffsssssififhhhhhhhhhhhhhhhhhhhhbbbbbbbbbbbbbbbbbbbbb";
        static uint8 const arraySizes[63] = { 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 10, 10, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 10, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 10, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 63, 0xF62C72EE, types, arraySizes);
        return &instance;
    }
};

struct ItemSpecMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hbbbbb";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 6, 0x0F323686, types, arraySizes);
        return &instance;
    }
};

struct ItemSpecOverrideMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ih";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x158F7C4E, types, arraySizes);
        return &instance;
    }
};

struct ItemSubClassMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sshbbbbbbb";
        static uint8 const arraySizes[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 10, 0x2B6ECF61, types, arraySizes);
        return &instance;
    }
};

struct ItemSubClassMaskMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "isb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x002D222A, types, arraySizes);
        return &instance;
    }
};

struct ItemUpgradeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihhbb";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0xF7CA02D9, types, arraySizes);
        return &instance;
    }
};

struct ItemVisualEffectsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x71B9EC59, types, arraySizes);
        return &instance;
    }
};

struct ItemVisualsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "h";
        static uint8 const arraySizes[1] = { 5 };
        static DB2Meta instance(-1, 1, 0x7459D46B, types, arraySizes);
        return &instance;
    }
};

struct ItemXBonusTreeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ih";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xA672E053, types, arraySizes);
        return &instance;
    }
};

struct JournalEncounterMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fsshhhhbbi";
        static uint8 const arraySizes[10] = { 2, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 10, 0xD59A20F7, types, arraySizes);
        return &instance;
    }
};

struct JournalEncounterCreatureMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iisshbi";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(6, 7, 0xC527E3A6, types, arraySizes);
        return &instance;
    }
};

struct JournalEncounterItemMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihbbbi";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(5, 6, 0x06112EE4, types, arraySizes);
        return &instance;
    }
};

struct JournalEncounterSectionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssiiihhhhhhbbb";
        static uint8 const arraySizes[14] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 14, 0x9D01F1EF, types, arraySizes);
        return &instance;
    }
};

struct JournalEncounterXDifficultyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xD14F0A02, types, arraySizes);
        return &instance;
    }
};

struct JournalInstanceMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiisshhbbi";
        static uint8 const arraySizes[11] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(10, 11, 0x6569C6CB, types, arraySizes);
        return &instance;
    }
};

struct JournalItemXDifficultyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x9EDCD781, types, arraySizes);
        return &instance;
    }
};

struct JournalSectionXDifficultyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x332C40F7, types, arraySizes);
        return &instance;
    }
};

struct JournalTierMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xC7290625, types, arraySizes);
        return &instance;
    }
};

struct JournalTierXInstanceMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hh";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x6D895E3A, types, arraySizes);
        return &instance;
    }
};

struct KeyChainMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "b";
        static uint8 const arraySizes[1] = { 32 };
        static DB2Meta instance(-1, 1, 0xF16B0884, types, arraySizes);
        return &instance;
    }
};

struct KeystoneAffixMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssi";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xDDD973A4, types, arraySizes);
        return &instance;
    }
};

struct LanguageWordsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xABBAA499, types, arraySizes);
        return &instance;
    }
};

struct LanguagesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "si";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(1, 2, 0x557617F0, types, arraySizes);
        return &instance;
    }
};

struct LfgDungeonExpansionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhbbbii";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0x709756FB, types, arraySizes);
        return &instance;
    }
};

struct LfgDungeonGroupMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x45E343EF, types, arraySizes);
        return &instance;
    }
};

struct LfgDungeonsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sissifhhhhhhhhbbbbbbbbbbbbbbbbbi";
        static uint8 const arraySizes[32] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(31, 32, 0x40D77668, types, arraySizes);
        return &instance;
    }
};

struct LfgDungeonsGroupingMapMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xD9B4F21E, types, arraySizes);
        return &instance;
    }
};

struct LfgRoleRequirementMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x6C04E981, types, arraySizes);
        return &instance;
    }
};

struct LightMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fffhh";
        static uint8 const arraySizes[5] = { 3, 1, 1, 1, 8 };
        static DB2Meta instance(-1, 5, 0x125FB33D, types, arraySizes);
        return &instance;
    }
};

struct LightDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiiiiiiiiiiiiiiiifffffffffiiiiiihh";
        static uint8 const arraySizes[35] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 35, 0xE3E8B600, types, arraySizes);
        return &instance;
    }
};

struct LightParamsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffffffhbbbi";
        static uint8 const arraySizes[11] = { 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1 };
        static DB2Meta instance(10, 11, 0xB6AE9B79, types, arraySizes);
        return &instance;
    }
};

struct LightSkyboxMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xC284FF64, types, arraySizes);
        return &instance;
    }
};

struct LiquidMaterialMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xDB7E353C, types, arraySizes);
        return &instance;
    }
};

struct LiquidObjectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffhbb";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x0FA85D64, types, arraySizes);
        return &instance;
    }
};

struct LiquidTypeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sifffffsifihhbbbbbi";
        static uint8 const arraySizes[19] = { 1, 1, 1, 1, 1, 1, 1, 6, 2, 18, 4, 1, 1, 1, 1, 1, 1, 6, 1 };
        static DB2Meta instance(-1, 19, 0x99FC34E5, types, arraySizes);
        return &instance;
    }
};

struct LoadingScreenTaxiSplinesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffhhb";
        static uint8 const arraySizes[5] = { 10, 10, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0xC020B1BD, types, arraySizes);
        return &instance;
    }
};

struct LoadingScreensMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xD8EA0A1E, types, arraySizes);
        return &instance;
    }
};

struct LocaleMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ibbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x16687537, types, arraySizes);
        return &instance;
    }
};

struct LocationMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ff";
        static uint8 const arraySizes[2] = { 3, 3 };
        static DB2Meta instance(-1, 2, 0xEC59DBEA, types, arraySizes);
        return &instance;
    }
};

struct LockMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihbb";
        static uint8 const arraySizes[4] = { 8, 8, 8, 8 };
        static DB2Meta instance(-1, 4, 0x8036B9F7, types, arraySizes);
        return &instance;
    }
};

struct LockTypeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssssi";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(4, 5, 0xB2F2A80D, types, arraySizes);
        return &instance;
    }
};

struct LookAtControllerMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffffhhhhbbbbbiiiii";
        static uint8 const arraySizes[18] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 18, 0x306B35FA, types, arraySizes);
        return &instance;
    }
};

struct MailTemplateMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x423247A6, types, arraySizes);
        return &instance;
    }
};

struct ManifestInterfaceActionIconMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(0, 1, 0xD94C8F61, types, arraySizes);
        return &instance;
    }
};

struct ManifestInterfaceDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ss";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x4A072B71, types, arraySizes);
        return &instance;
    }
};

struct ManifestInterfaceItemIconMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(0, 1, 0xD94C8F61, types, arraySizes);
        return &instance;
    }
};

struct ManifestInterfaceTOCDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x0B897147, types, arraySizes);
        return &instance;
    }
};

struct ManifestMP3Meta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(0, 1, 0xD94C8F61, types, arraySizes);
        return &instance;
    }
};

struct MapMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "siffssshhhhhhhbbbbb";
        static uint8 const arraySizes[19] = { 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 19, 0xF7CF2DA2, types, arraySizes);
        return &instance;
    }
};

struct MapChallengeModeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhb";
        static uint8 const arraySizes[3] = { 1, 3, 1 };
        static DB2Meta instance(-1, 3, 0x71154C5C, types, arraySizes);
        return &instance;
    }
};

struct MapDifficultyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shbbbbbi";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 8, 0x7C085B97, types, arraySizes);
        return &instance;
    }
};

struct MapDifficultyXConditionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "siii";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x19ABF9EE, types, arraySizes);
        return &instance;
    }
};

struct MarketingPromotionsXLocaleMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiisbb";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0x59F09849, types, arraySizes);
        return &instance;
    }
};

struct MaterialMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "biii";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x33D0FF68, types, arraySizes);
        return &instance;
    }
};

struct MinorTalentMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x86299404, types, arraySizes);
        return &instance;
    }
};

struct ModelAnimCloakDampeningMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xABAAC3BD, types, arraySizes);
        return &instance;
    }
};

struct ModelFileDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(1, 3, 0x0F24B84E, types, arraySizes);
        return &instance;
    }
};

struct ModelRibbonQualityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ib";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x941830DD, types, arraySizes);
        return &instance;
    }
};

struct ModifierTreeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iihbbbb";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0x46CC701E, types, arraySizes);
        return &instance;
    }
};

struct MountMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iisssfhhhbi";
        static uint8 const arraySizes[11] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(10, 11, 0x9E01F745, types, arraySizes);
        return &instance;
    }
};

struct MountCapabilityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iihhhbii";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(6, 8, 0x3F0A62EE, types, arraySizes);
        return &instance;
    }
};

struct MountTypeXCapabilityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x73CEF21F, types, arraySizes);
        return &instance;
    }
};

struct MovieMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iibb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x1295D923, types, arraySizes);
        return &instance;
    }
};

struct MovieFileDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "h";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xA15FC1F5, types, arraySizes);
        return &instance;
    }
};

struct MovieVariationMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihi";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x1A77D958, types, arraySizes);
        return &instance;
    }
};

struct NPCSoundsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i";
        static uint8 const arraySizes[1] = { 4 };
        static DB2Meta instance(-1, 1, 0xE5E4FB99, types, arraySizes);
        return &instance;
    }
};

struct NameGenMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xDFD3BCC7, types, arraySizes);
        return &instance;
    }
};

struct NamesProfanityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x14126F92, types, arraySizes);
        return &instance;
    }
};

struct NamesReservedMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xA75DB185, types, arraySizes);
        return &instance;
    }
};

struct NamesReservedLocaleMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xEA8688CB, types, arraySizes);
        return &instance;
    }
};

struct NpcModelItemSlotDisplayInfoMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iib";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x82126742, types, arraySizes);
        return &instance;
    }
};

struct ObjectEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sfhbbbbbi";
        static uint8 const arraySizes[9] = { 1, 3, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 9, 0x50D174A8, types, arraySizes);
        return &instance;
    }
};

struct ObjectEffectGroupMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xC7290625, types, arraySizes);
        return &instance;
    }
};

struct ObjectEffectModifierMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fbbb";
        static uint8 const arraySizes[4] = { 4, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x78E883C3, types, arraySizes);
        return &instance;
    }
};

struct ObjectEffectPackageMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xC7290625, types, arraySizes);
        return &instance;
    }
};

struct ObjectEffectPackageElemMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhh";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xD29A59FB, types, arraySizes);
        return &instance;
    }
};

struct OutlineEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fiiiii";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 6, 0xF8D79D78, types, arraySizes);
        return &instance;
    }
};

struct OverrideSpellDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iib";
        static uint8 const arraySizes[3] = { 10, 1, 1 };
        static DB2Meta instance(-1, 3, 0x0F841B9A, types, arraySizes);
        return &instance;
    }
};

struct PageTextMaterialMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xC7290625, types, arraySizes);
        return &instance;
    }
};

struct PaperDollItemFrameMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x9C3CC0A9, types, arraySizes);
        return &instance;
    }
};

struct ParticleColorMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 3, 3, 3 };
        static DB2Meta instance(-1, 3, 0xBC5D3597, types, arraySizes);
        return &instance;
    }
};

struct PathMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbbbbbb";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0x2B91D905, types, arraySizes);
        return &instance;
    }
};

struct PathNodeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iihh";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(0, 4, 0x9B535598, types, arraySizes);
        return &instance;
    }
};

struct PathNodePropertyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhbii";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(3, 5, 0xF446CDBB, types, arraySizes);
        return &instance;
    }
};

struct PathPropertyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihbi";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(3, 4, 0xF4469671, types, arraySizes);
        return &instance;
    }
};

struct PhaseMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "h";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xB2EE9466, types, arraySizes);
        return &instance;
    }
};

struct PhaseShiftZoneSoundsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhhhhbbbbiiii";
        static uint8 const arraySizes[13] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 13, 0x1AA0596A, types, arraySizes);
        return &instance;
    }
};

struct PhaseXPhaseGroupMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hh";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xB494BBD2, types, arraySizes);
        return &instance;
    }
};

struct PlayerConditionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiiiiiiiiiiiishhhhhhhhhhhhhhhhhhbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbiiiiiiiiiiiiiii";
        static uint8 const arraySizes[79] = { 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 4, 1, 1, 1, 1, 1, 1, 4, 4, 4, 1, 4, 4, 4, 2, 1, 4, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 1, 4, 1, 1, 1, 4, 4, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 4, 4, 4, 1, 4, 1, 4, 6, 1, 1, 1, 2 };
        static DB2Meta instance(-1, 79, 0x97CEA4E6, types, arraySizes);
        return &instance;
    }
};

struct PositionerMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fhbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x0DC56BF9, types, arraySizes);
        return &instance;
    }
};

struct PositionerStateMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fbiiiiii";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 8, 0xB64314AC, types, arraySizes);
        return &instance;
    }
};

struct PositionerStateEntryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffhhbbbbbbi";
        static uint8 const arraySizes[11] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 11, 0x92FB58E8, types, arraySizes);
        return &instance;
    }
};

struct PowerDisplayMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbbbb";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x18C540B5, types, arraySizes);
        return &instance;
    }
};

struct PowerTypeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssffhhhbbbbb";
        static uint8 const arraySizes[12] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 12, 0x9B2B3F6D, types, arraySizes);
        return &instance;
    }
};

struct PrestigeLevelInfoMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "isbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x1F001219, types, arraySizes);
        return &instance;
    }
};

struct PvpBracketTypesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bi";
        static uint8 const arraySizes[2] = { 1, 4 };
        static DB2Meta instance(-1, 2, 0x621CD92F, types, arraySizes);
        return &instance;
    }
};

struct PvpDifficultyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hbbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xCF4D1AEB, types, arraySizes);
        return &instance;
    }
};

struct PvpItemMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ib";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x5C087651, types, arraySizes);
        return &instance;
    }
};

struct PvpRewardMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x951DE3BC, types, arraySizes);
        return &instance;
    }
};

struct PvpTalentMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iisiiiiii";
        static uint8 const arraySizes[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 9, 0xB6FF8059, types, arraySizes);
        return &instance;
    }
};

struct PvpTalentUnlockMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xC1A48E8A, types, arraySizes);
        return &instance;
    }
};

struct QuestFactionRewardMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "h";
        static uint8 const arraySizes[1] = { 10 };
        static DB2Meta instance(-1, 1, 0x313B4AEB, types, arraySizes);
        return &instance;
    }
};

struct QuestFeedbackEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihbbbb";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 6, 0x747AA1F3, types, arraySizes);
        return &instance;
    }
};

struct QuestInfoMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x11382F51, types, arraySizes);
        return &instance;
    }
};

struct QuestLineMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xC7290625, types, arraySizes);
        return &instance;
    }
};

struct QuestLineXQuestMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x0D1339BD, types, arraySizes);
        return &instance;
    }
};

struct QuestMoneyRewardMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i";
        static uint8 const arraySizes[1] = { 10 };
        static DB2Meta instance(-1, 1, 0x83F7CE9C, types, arraySizes);
        return &instance;
    }
};

struct QuestObjectiveMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iishbbbb";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 8, 0x22594899, types, arraySizes);
        return &instance;
    }
};

struct QuestPOIBlobMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihhbbiii";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(0, 8, 0x02EEA008, types, arraySizes);
        return &instance;
    }
};

struct QuestPOIPointMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihhi";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(3, 4, 0x602A18C5, types, arraySizes);
        return &instance;
    }
};

struct QuestPackageItemMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x31CD6A8B, types, arraySizes);
        return &instance;
    }
};

struct QuestSortMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xE784CEA6, types, arraySizes);
        return &instance;
    }
};

struct QuestV2Meta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "h";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x02E59131, types, arraySizes);
        return &instance;
    }
};

struct QuestV2CliTaskMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "issihhhhhhhbbbbbbbbbiii";
        static uint8 const arraySizes[23] = { 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(20, 23, 0x3AF80301, types, arraySizes);
        return &instance;
    }
};

struct QuestXPMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "h";
        static uint8 const arraySizes[1] = { 10 };
        static DB2Meta instance(-1, 1, 0xE39F507A, types, arraySizes);
        return &instance;
    }
};

struct RacialMountsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ib";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x12EABF67, types, arraySizes);
        return &instance;
    }
};

struct RandPropPointsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 5, 5, 5 };
        static DB2Meta instance(-1, 3, 0xE5202AE2, types, arraySizes);
        return &instance;
    }
};

struct ResearchBranchMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssihb";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x913C4C8E, types, arraySizes);
        return &instance;
    }
};

struct ResearchFieldMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbi";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(2, 3, 0x58E34F4D, types, arraySizes);
        return &instance;
    }
};

struct ResearchProjectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssishbbii";
        static uint8 const arraySizes[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(7, 9, 0xFFF56E96, types, arraySizes);
        return &instance;
    }
};

struct ResearchSiteMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ishi";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x17513E43, types, arraySizes);
        return &instance;
    }
};

struct ResistancesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbi";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xFB916DBC, types, arraySizes);
        return &instance;
    }
};

struct RewardPackMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ifbbii";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 6, 0x4AE87C13, types, arraySizes);
        return &instance;
    }
};

struct RewardPackXCurrencyTypeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x41F4ECBC, types, arraySizes);
        return &instance;
    }
};

struct RewardPackXItemMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xADFD44B7, types, arraySizes);
        return &instance;
    }
};

struct RibbonQualityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fffbi";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x7B2CFE42, types, arraySizes);
        return &instance;
    }
};

struct RulesetItemUpgradeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ih";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x11515F20, types, arraySizes);
        return &instance;
    }
};

struct ScalingStatDistributionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x1429D0B8, types, arraySizes);
        return &instance;
    }
};

struct ScenarioMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x5E81BCF6, types, arraySizes);
        return &instance;
    }
};

struct ScenarioEventEntryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x6FE49761, types, arraySizes);
        return &instance;
    }
};

struct ScenarioStepMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sshhhhbbi";
        static uint8 const arraySizes[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 9, 0x2C5EC158, types, arraySizes);
        return &instance;
    }
};

struct SceneScriptMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sshh";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x1EEAE156, types, arraySizes);
        return &instance;
    }
};

struct SceneScriptPackageMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xC7290625, types, arraySizes);
        return &instance;
    }
};

struct SceneScriptPackageMemberMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhhb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x25F30E6F, types, arraySizes);
        return &instance;
    }
};

struct ScheduledIntervalMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiii";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x5F6D83EC, types, arraySizes);
        return &instance;
    }
};

struct ScheduledWorldStateMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiiiiii";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 8, 0xA04FD7B6, types, arraySizes);
        return &instance;
    }
};

struct ScheduledWorldStateGroupMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiii";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x388C0CD9, types, arraySizes);
        return &instance;
    }
};

struct ScheduledWorldStateXUniqCatMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(0, 3, 0x55B274C3, types, arraySizes);
        return &instance;
    }
};

struct ScreenEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sihhhhbbbiii";
        static uint8 const arraySizes[12] = { 1, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 12, 0xE37F8225, types, arraySizes);
        return &instance;
    }
};

struct ScreenLocationMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xC7290625, types, arraySizes);
        return &instance;
    }
};

struct SeamlessSiteMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x519EF0C5, types, arraySizes);
        return &instance;
    }
};

struct ServerMessagesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xF540D73D, types, arraySizes);
        return &instance;
    }
};

struct ShadowyEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiffffffbb";
        static uint8 const arraySizes[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 10, 0x9072BD0E, types, arraySizes);
        return &instance;
    }
};

struct SkillLineMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssshhbbi";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 8, 0xD05F97DB, types, arraySizes);
        return &instance;
    }
};

struct SkillLineAbilityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiihhhhhhbbi";
        static uint8 const arraySizes[13] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 13, 0x33977235, types, arraySizes);
        return &instance;
    }
};

struct SkillRaceClassInfoMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihhhbbi";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0x23FE736E, types, arraySizes);
        return &instance;
    }
};

struct SoundAmbienceMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "biii";
        static uint8 const arraySizes[4] = { 1, 2, 1, 1 };
        static DB2Meta instance(-1, 4, 0xF6403AC1, types, arraySizes);
        return &instance;
    }
};

struct SoundAmbienceFlavorMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xBC4B2D4F, types, arraySizes);
        return &instance;
    }
};

struct SoundBusMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffhbbbbbbbbi";
        static uint8 const arraySizes[12] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(11, 12, 0xB3B4FD02, types, arraySizes);
        return &instance;
    }
};

struct SoundEmitterPillPointsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fh";
        static uint8 const arraySizes[2] = { 3, 1 };
        static DB2Meta instance(-1, 2, 0xB29E5CAB, types, arraySizes);
        return &instance;
    }
};

struct SoundEmittersMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffshhhbbbbii";
        static uint8 const arraySizes[12] = { 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(10, 12, 0xE757D4E0, types, arraySizes);
        return &instance;
    }
};

struct SoundFilterMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xC7290625, types, arraySizes);
        return &instance;
    }
};

struct SoundFilterElemMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fbb";
        static uint8 const arraySizes[3] = { 9, 1, 1 };
        static DB2Meta instance(-1, 3, 0x15C04229, types, arraySizes);
        return &instance;
    }
};

struct SoundKitMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sffffffffhhhbbbbi";
        static uint8 const arraySizes[17] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(16, 17, 0x38A184DC, types, arraySizes);
        return &instance;
    }
};

struct SoundKitAdvancedMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fiiiiiifffffiiffffffihbbbbiiiiii";
        static uint8 const arraySizes[32] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 32, 0x7CE3363B, types, arraySizes);
        return &instance;
    }
};

struct SoundKitChildMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ii";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xC1FC0B1D, types, arraySizes);
        return &instance;
    }
};

struct SoundKitEntryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ifbi";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x1F47A21F, types, arraySizes);
        return &instance;
    }
};

struct SoundKitFallbackMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ii";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x49EF8EA3, types, arraySizes);
        return &instance;
    }
};

struct SoundOverrideMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhhb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x6A119082, types, arraySizes);
        return &instance;
    }
};

struct SoundProviderPreferencesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sfffffffffffffffhhhhhbb";
        static uint8 const arraySizes[23] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 23, 0x280B4DCE, types, arraySizes);
        return &instance;
    }
};

struct SourceInfoMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "isbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x83D64CE7, types, arraySizes);
        return &instance;
    }
};

struct SpamMessagesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xC3BC61DD, types, arraySizes);
        return &instance;
    }
};

struct SpecializationSpellsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iishbi";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(5, 6, 0xFDA6037B, types, arraySizes);
        return &instance;
    }
};

struct SpellMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssssiii";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(5, 7, 0xE5833C90, types, arraySizes);
        return &instance;
    }
};

struct SpellActionBarPrefMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ih";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x7208084B, types, arraySizes);
        return &instance;
    }
};

struct SpellActivationOverlayMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiifibbi";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 4, 1, 1, 1 };
        static DB2Meta instance(-1, 8, 0xCA4F95F7, types, arraySizes);
        return &instance;
    }
};

struct SpellAuraOptionsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiihbbb";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 8, 0x3F86C0F9, types, arraySizes);
        return &instance;
    }
};

struct SpellAuraRestrictionsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiiibbbbb";
        static uint8 const arraySizes[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 10, 0xA3E6C359, types, arraySizes);
        return &instance;
    }
};

struct SpellAuraVisXChrSpecMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hh";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xAB095460, types, arraySizes);
        return &instance;
    }
};

struct SpellAuraVisibilityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ibbi";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(3, 4, 0xF5BCF9D6, types, arraySizes);
        return &instance;
    }
};

struct SpellCastTimesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iih";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x33483F8A, types, arraySizes);
        return &instance;
    }
};

struct SpellCastingRequirementsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihhhbbb";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0x8755DB03, types, arraySizes);
        return &instance;
    }
};

struct SpellCategoriesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihhhbbbbb";
        static uint8 const arraySizes[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 9, 0x781B3F38, types, arraySizes);
        return &instance;
    }
};

struct SpellCategoryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sibbbi";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 6, 0xE4524408, types, arraySizes);
        return &instance;
    }
};

struct SpellChainEffectsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffffiifffffffffffffffffffffffffffffffffffiffsshhhhbbbbbbbbbbbi";
        static uint8 const arraySizes[62] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 1, 1, 1, 3, 1, 1, 1, 11, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 62, 0xF1FA79EA, types, arraySizes);
        return &instance;
    }
};

struct SpellClassOptionsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iibi";
        static uint8 const arraySizes[4] = { 1, 4, 1, 1 };
        static DB2Meta instance(-1, 4, 0x56CB75EE, types, arraySizes);
        return &instance;
    }
};

struct SpellCooldownsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiib";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x8A2FB468, types, arraySizes);
        return &instance;
    }
};

struct SpellDescriptionVariablesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x4326E101, types, arraySizes);
        return &instance;
    }
};

struct SpellDispelTypeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x0849B551, types, arraySizes);
        return &instance;
    }
};

struct SpellDurationMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iih";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xA68538E2, types, arraySizes);
        return &instance;
    }
};

struct SpellEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fffffiffiiiiiiiiiiiiiiiii";
        static uint8 const arraySizes[25] = { 1, 1, 1, 1, 1, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 1, 2, 1, 1, 1 };
        static DB2Meta instance(8, 25, 0x16763148, types, arraySizes);
        return &instance;
    }
};

struct SpellEffectEmissionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffhb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x6561174B, types, arraySizes);
        return &instance;
    }
};

struct SpellEffectExtraMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "f";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x4DA79C50, types, arraySizes);
        return &instance;
    }
};

struct SpellEffectGroupSizeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "if";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x6F18EF9F, types, arraySizes);
        return &instance;
    }
};

struct SpellEffectScalingMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fffi";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xD8F7C7FB, types, arraySizes);
        return &instance;
    }
};

struct SpellEquippedItemsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiib";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x207DB8D6, types, arraySizes);
        return &instance;
    }
};

struct SpellFlyoutMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "isshbi";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 6, 0x23CEEA8A, types, arraySizes);
        return &instance;
    }
};

struct SpellFlyoutItemMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ibb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x877BCCA7, types, arraySizes);
        return &instance;
    }
};

struct SpellFocusObjectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xC7290625, types, arraySizes);
        return &instance;
    }
};

struct SpellIconMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x290CE6BA, types, arraySizes);
        return &instance;
    }
};

struct SpellInterruptsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiihb";
        static uint8 const arraySizes[5] = { 1, 2, 2, 1, 1 };
        static DB2Meta instance(-1, 5, 0xBCE11416, types, arraySizes);
        return &instance;
    }
};

struct SpellItemEnchantmentMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "isfiihhhhhhbbbbbbbi";
        static uint8 const arraySizes[19] = { 3, 1, 3, 1, 1, 3, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 19, 0x55410316, types, arraySizes);
        return &instance;
    }
};

struct SpellItemEnchantmentConditionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbbbbi";
        static uint8 const arraySizes[6] = { 5, 5, 5, 5, 5, 5 };
        static DB2Meta instance(-1, 6, 0xE7DAD37D, types, arraySizes);
        return &instance;
    }
};

struct SpellKeyboundOverrideMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "isb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x994DBA82, types, arraySizes);
        return &instance;
    }
};

struct SpellLabelMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ii";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x924C562C, types, arraySizes);
        return &instance;
    }
};

struct SpellLearnSpellMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x96E3FF5C, types, arraySizes);
        return &instance;
    }
};

struct SpellLevelsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihhhbb";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 6, 0xAAD87C71, types, arraySizes);
        return &instance;
    }
};

struct SpellMechanicMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x2B61E266, types, arraySizes);
        return &instance;
    }
};

struct SpellMiscMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iffhhhhhb";
        static uint8 const arraySizes[9] = { 14, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 9, 0x238E7BD9, types, arraySizes);
        return &instance;
    }
};

struct SpellMiscDifficultyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ibi";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(2, 3, 0xFF3CE8ED, types, arraySizes);
        return &instance;
    }
};

struct SpellMissileMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ifffffffffffffb";
        static uint8 const arraySizes[15] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 15, 0xDB6D042C, types, arraySizes);
        return &instance;
    }
};

struct SpellMissileMotionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x41A32383, types, arraySizes);
        return &instance;
    }
};

struct SpellPowerMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiffifbbiiiiii";
        static uint8 const arraySizes[14] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(8, 14, 0x5BC3DDCE, types, arraySizes);
        return &instance;
    }
};

struct SpellPowerDifficultyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbi";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(2, 3, 0xDD6987D1, types, arraySizes);
        return &instance;
    }
};

struct SpellProceduralEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fbi";
        static uint8 const arraySizes[3] = { 4, 1, 1 };
        static DB2Meta instance(2, 3, 0xFF66AE2D, types, arraySizes);
        return &instance;
    }
};

struct SpellProcsPerMinuteMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xBA59813B, types, arraySizes);
        return &instance;
    }
};

struct SpellProcsPerMinuteModMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fhbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x0044A109, types, arraySizes);
        return &instance;
    }
};

struct SpellRadiusMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffff";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x01D4170C, types, arraySizes);
        return &instance;
    }
};

struct SpellRangeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffssb";
        static uint8 const arraySizes[5] = { 2, 2, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x9A45DAC4, types, arraySizes);
        return &instance;
    }
};

struct SpellReagentsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iih";
        static uint8 const arraySizes[3] = { 1, 8, 8 };
        static DB2Meta instance(-1, 3, 0x91DD8682, types, arraySizes);
        return &instance;
    }
};

struct SpellReagentsCurrencyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihh";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xFD286C2C, types, arraySizes);
        return &instance;
    }
};

struct SpellScalingMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihiii";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x647B325B, types, arraySizes);
        return &instance;
    }
};

struct SpellShapeshiftMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiib";
        static uint8 const arraySizes[4] = { 1, 2, 2, 1 };
        static DB2Meta instance(-1, 4, 0x751BB86D, types, arraySizes);
        return &instance;
    }
};

struct SpellShapeshiftFormMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sfihhhhhbb";
        static uint8 const arraySizes[10] = { 1, 1, 1, 1, 1, 4, 8, 1, 1, 1 };
        static DB2Meta instance(-1, 10, 0xF2F53E9B, types, arraySizes);
        return &instance;
    }
};

struct SpellSpecialUnitEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hi";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x44CE5AA5, types, arraySizes);
        return &instance;
    }
};

struct SpellTargetRestrictionsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iffihbbi";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 8, 0x3E737FD4, types, arraySizes);
        return &instance;
    }
};

struct SpellTotemsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iih";
        static uint8 const arraySizes[3] = { 1, 2, 2 };
        static DB2Meta instance(-1, 3, 0xCEF20980, types, arraySizes);
        return &instance;
    }
};

struct SpellVisualMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiiiiiiiiiiiiiffiihhhbbiiii";
        static uint8 const arraySizes[28] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(24, 28, 0x2A5536DE, types, arraySizes);
        return &instance;
    }
};

struct SpellVisualAnimMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhh";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x9466CA0B, types, arraySizes);
        return &instance;
    }
};

struct SpellVisualColorEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fifhhhhhbbi";
        static uint8 const arraySizes[11] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 11, 0xB64EDACC, types, arraySizes);
        return &instance;
    }
};

struct SpellVisualEffectNameMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sffffffiiibii";
        static uint8 const arraySizes[13] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 13, 0x357EA96F, types, arraySizes);
        return &instance;
    }
};

struct SpellVisualKitMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ifhhii";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(4, 6, 0x4356273E, types, arraySizes);
        return &instance;
    }
};

struct SpellVisualKitAreaModelMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ifffhb";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 6, 0x3574C2E7, types, arraySizes);
        return &instance;
    }
};

struct SpellVisualKitEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x61637867, types, arraySizes);
        return &instance;
    }
};

struct SpellVisualKitModelAttachMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iffffffffffifhhhhhhbbi";
        static uint8 const arraySizes[22] = { 1, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(21, 22, 0x04B33CAD, types, arraySizes);
        return &instance;
    }
};

struct SpellVisualMissileMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiffhhhhhhbbiii";
        static uint8 const arraySizes[16] = { 1, 1, 1, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(13, 16, 0x53BAC2C9, types, arraySizes);
        return &instance;
    }
};

struct SpellXSpellVisualMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ifhhhhbbbi";
        static uint8 const arraySizes[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(9, 10, 0xBB7867F3, types, arraySizes);
        return &instance;
    }
};

struct Startup_StringsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ss";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x8C2A9B67, types, arraySizes);
        return &instance;
    }
};

struct StationeryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbi";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x5956C630, types, arraySizes);
        return &instance;
    }
};

struct StringLookupsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xCA7A241B, types, arraySizes);
        return &instance;
    }
};

struct SummonPropertiesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiii";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x1EE46E46, types, arraySizes);
        return &instance;
    }
};

struct TactKeyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "b";
        static uint8 const arraySizes[1] = { 16 };
        static DB2Meta instance(-1, 1, 0x08773764, types, arraySizes);
        return &instance;
    }
};

struct TactKeyLookupMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "b";
        static uint8 const arraySizes[1] = { 8 };
        static DB2Meta instance(-1, 1, 0x93C0A8AC, types, arraySizes);
        return &instance;
    }
};

struct TalentMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iishbbbbb";
        static uint8 const arraySizes[9] = { 1, 1, 1, 1, 1, 1, 1, 2, 1 };
        static DB2Meta instance(-1, 9, 0xE33B18D6, types, arraySizes);
        return &instance;
    }
};

struct TaxiNodesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fsifhhhbi";
        static uint8 const arraySizes[9] = { 3, 1, 2, 2, 1, 1, 1, 1, 1 };
        static DB2Meta instance(8, 9, 0x75BBE821, types, arraySizes);
        return &instance;
    }
};

struct TaxiPathMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhii";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(2, 4, 0x024DF2C5, types, arraySizes);
        return &instance;
    }
};

struct TaxiPathNodeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fihhhhbbi";
        static uint8 const arraySizes[9] = { 3, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(8, 9, 0x265B46FD, types, arraySizes);
        return &instance;
    }
};

struct TerrainMaterialMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xFEAC3DEB, types, arraySizes);
        return &instance;
    }
};

struct TerrainTypeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shhbb";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0xCE859CB3, types, arraySizes);
        return &instance;
    }
};

struct TerrainTypeSoundsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xA75DB185, types, arraySizes);
        return &instance;
    }
};

struct TextureBlendSetMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ifffffbbbb";
        static uint8 const arraySizes[10] = { 3, 3, 3, 3, 3, 4, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 10, 0x5EB52530, types, arraySizes);
        return &instance;
    }
};

struct TextureFileDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ibi";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(2, 3, 0xEA25E12A, types, arraySizes);
        return &instance;
    }
};

struct TotemCategoryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sib";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xCCD2F8FC, types, arraySizes);
        return &instance;
    }
};

struct ToyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "isbbi";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(4, 5, 0x9C360567, types, arraySizes);
        return &instance;
    }
};

struct TradeSkillCategoryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shhhb";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x5E591FFB, types, arraySizes);
        return &instance;
    }
};

struct TradeSkillItemMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x1ECD3B6E, types, arraySizes);
        return &instance;
    }
};

struct TransformMatrixMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fffff";
        static uint8 const arraySizes[5] = { 3, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0xC3C28B27, types, arraySizes);
        return &instance;
    }
};

struct TransmogSetMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiii";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(0, 4, 0xAFBEBD1B, types, arraySizes);
        return &instance;
    }
};

struct TransmogSetItemMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiii";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(0, 4, 0x93D07FB6, types, arraySizes);
        return &instance;
    }
};

struct TransportAnimationMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iifb";
        static uint8 const arraySizes[4] = { 1, 1, 3, 1 };
        static DB2Meta instance(-1, 4, 0xD4A71B4F, types, arraySizes);
        return &instance;
    }
};

struct TransportPhysicsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffffffffff";
        static uint8 const arraySizes[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 10, 0x870455A8, types, arraySizes);
        return &instance;
    }
};

struct TransportRotationMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iif";
        static uint8 const arraySizes[3] = { 1, 1, 4 };
        static DB2Meta instance(-1, 3, 0xC1B2733B, types, arraySizes);
        return &instance;
    }
};

struct TrophyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shhb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x2DF28AE9, types, arraySizes);
        return &instance;
    }
};

struct UiCamFbackTransmogChrRaceMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hbbbb";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x23E76F22, types, arraySizes);
        return &instance;
    }
};

struct UiCamFbackTransmogWeaponMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hbbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x8BDD56D3, types, arraySizes);
        return &instance;
    }
};

struct UiCameraMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sfffhbbbi";
        static uint8 const arraySizes[9] = { 1, 3, 3, 3, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 9, 0x5EF7E92E, types, arraySizes);
        return &instance;
    }
};

struct UiCameraTypeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xBDDE3ED0, types, arraySizes);
        return &instance;
    }
};

struct UiMapPOIMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ifiiihi";
        static uint8 const arraySizes[7] = { 1, 3, 1, 1, 1, 1, 1 };
        static DB2Meta instance(6, 7, 0x51BCAE51, types, arraySizes);
        return &instance;
    }
};

struct UiTextureAtlasMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihh";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x22EA2544, types, arraySizes);
        return &instance;
    }
};

struct UiTextureAtlasMemberMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shhhhhb";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0x4C7B7833, types, arraySizes);
        return &instance;
    }
};

struct UiTextureKitMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x22DE4AB8, types, arraySizes);
        return &instance;
    }
};

struct UnitBloodMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shhhiii";
        static uint8 const arraySizes[7] = { 5, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0xE5224622, types, arraySizes);
        return &instance;
    }
};

struct UnitBloodLevelsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "b";
        static uint8 const arraySizes[1] = { 3 };
        static DB2Meta instance(-1, 1, 0x8740923E, types, arraySizes);
        return &instance;
    }
};

struct UnitConditionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ibbb";
        static uint8 const arraySizes[4] = { 8, 1, 8, 8 };
        static DB2Meta instance(-1, 4, 0x286CC164, types, arraySizes);
        return &instance;
    }
};

struct UnitPowerBarMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffiissssffhhbbii";
        static uint8 const arraySizes[16] = { 1, 1, 6, 6, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 16, 0x6F765621, types, arraySizes);
        return &instance;
    }
};

struct VehicleMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iffffffffffffffffffsssffhhhbb";
        static uint8 const arraySizes[29] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 8, 1, 3, 1, 1 };
        static DB2Meta instance(-1, 29, 0xA26138C3, types, arraySizes);
        return &instance;
    }
};

struct VehicleSeatMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiffffffffffffffffffffffffffffffihhhhhhhhhhhhhhhhhhhbbbbbbii";
        static uint8 const arraySizes[61] = { 1, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 61, 0x677A6917, types, arraySizes);
        return &instance;
    }
};

struct VehicleUIIndSeatMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffhb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xC3FFC7A2, types, arraySizes);
        return &instance;
    }
};

struct VehicleUIIndicatorMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x67C7890F, types, arraySizes);
        return &instance;
    }
};

struct VideoHardwareMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sshhbbbbbbbbbbiiiiiiii";
        static uint8 const arraySizes[22] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(14, 22, 0x58A67427, types, arraySizes);
        return &instance;
    }
};

struct VignetteMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sffhbii";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0x9E020834, types, arraySizes);
        return &instance;
    }
};

struct VocalUISoundsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbbi";
        static uint8 const arraySizes[4] = { 1, 1, 1, 2 };
        static DB2Meta instance(-1, 4, 0x5A79821D, types, arraySizes);
        return &instance;
    }
};

struct WMOAreaTableMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ishhhhhhhbbbbii";
        static uint8 const arraySizes[15] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(13, 15, 0x1723DB9B, types, arraySizes);
        return &instance;
    }
};

struct WbAccessControlListMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shbbb";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x49919892, types, arraySizes);
        return &instance;
    }
};

struct WbCertBlacklistMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sb";
        static uint8 const arraySizes[2] = { 1, 20 };
        static DB2Meta instance(-1, 2, 0x23D156DE, types, arraySizes);
        return &instance;
    }
};

struct WbCertWhitelistMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xE7A86A2C, types, arraySizes);
        return &instance;
    }
};

struct WbPermissionsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x7A15E8CA, types, arraySizes);
        return &instance;
    }
};

struct WeaponImpactSoundsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbbiiii";
        static uint8 const arraySizes[7] = { 1, 1, 1, 11, 11, 11, 11 };
        static DB2Meta instance(-1, 7, 0x7C22F8E0, types, arraySizes);
        return &instance;
    }
};

struct WeaponSwingSounds2Meta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbi";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xBDDE5D55, types, arraySizes);
        return &instance;
    }
};

struct WeaponTrailMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ifffiffff";
        static uint8 const arraySizes[9] = { 1, 1, 1, 1, 3, 3, 3, 3, 3 };
        static DB2Meta instance(-1, 9, 0x6CFF4862, types, arraySizes);
        return &instance;
    }
};

struct WeaponTrailModelDefMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihh";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xAC40A6A4, types, arraySizes);
        return &instance;
    }
};

struct WeaponTrailParamMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fffffhbbbb";
        static uint8 const arraySizes[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 10, 0x3714142A, types, arraySizes);
        return &instance;
    }
};

struct WeatherMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fffsfffffhbbbi";
        static uint8 const arraySizes[14] = { 2, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 14, 0xF70C3970, types, arraySizes);
        return &instance;
    }
};

struct WindSettingsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fffffffffb";
        static uint8 const arraySizes[10] = { 1, 3, 1, 1, 3, 1, 3, 1, 1, 1 };
        static DB2Meta instance(-1, 10, 0x039E80F8, types, arraySizes);
        return &instance;
    }
};

struct WmoMinimapTextureMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihhbb";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0xD98F4672, types, arraySizes);
        return &instance;
    }
};

struct WorldBossLockoutMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sh";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x40D1D0B9, types, arraySizes);
        return &instance;
    }
};

struct WorldChunkSoundsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hbbbbb";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 6, 0x7D17C7B2, types, arraySizes);
        return &instance;
    }
};

struct WorldEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihhhbb";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 6, 0xB1DDCD15, types, arraySizes);
        return &instance;
    }
};

struct WorldElapsedTimerMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xF01B4D84, types, arraySizes);
        return &instance;
    }
};

struct WorldMapAreaMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sffffhhhhhhbbbbii";
        static uint8 const arraySizes[17] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(15, 17, 0x95F8D79D, types, arraySizes);
        return &instance;
    }
};

struct WorldMapContinentMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffffhhbbbbb";
        static uint8 const arraySizes[11] = { 2, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 11, 0x6A1414E1, types, arraySizes);
        return &instance;
    }
};

struct WorldMapOverlayMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shhiiiiiiiiii";
        static uint8 const arraySizes[13] = { 1, 1, 1, 1, 4, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 13, 0x093857A3, types, arraySizes);
        return &instance;
    }
};

struct WorldMapTransformsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fffhhhhhb";
        static uint8 const arraySizes[9] = { 6, 2, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 9, 0x23B2A570, types, arraySizes);
        return &instance;
    }
};

struct WorldSafeLocsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffsh";
        static uint8 const arraySizes[4] = { 3, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xAA5CA0A8, types, arraySizes);
        return &instance;
    }
};

struct WorldStateExpressionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xCFD6D558, types, arraySizes);
        return &instance;
    }
};

struct WorldStateUIMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sssssshhhhhbbbbi";
        static uint8 const arraySizes[16] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1 };
        static DB2Meta instance(15, 16, 0xE5B5B5E2, types, arraySizes);
        return &instance;
    }
};

struct WorldStateZoneSoundsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihhhhhhb";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 8, 0xAB1B4B5D, types, arraySizes);
        return &instance;
    }
};

struct World_PVP_AreaMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhhhhbb";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0xBA892CFD, types, arraySizes);
        return &instance;
    }
};

struct ZoneIntroMusicTableMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shbi";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xDB2B4DE9, types, arraySizes);
        return &instance;
    }
};

struct ZoneLightMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shh";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x38749B85, types, arraySizes);
        return &instance;
    }
};

struct ZoneLightPointMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fhb";
        static uint8 const arraySizes[3] = { 2, 1, 1 };
        static DB2Meta instance(-1, 3, 0x198A5272, types, arraySizes);
        return &instance;
    }
};

struct ZoneMusicMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "siii";
        static uint8 const arraySizes[4] = { 1, 2, 2, 2 };
        static DB2Meta instance(-1, 4, 0x5DFA9925, types, arraySizes);
        return &instance;
    }
};

#endif // DB2Metadata_h__
