/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
        static char const* types = "sssihhhhhbbbiii";
        static uint8 const arraySizes[15] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(12, 15, 0x2C4BE18C, types, arraySizes, 7);
        return &instance;
    }
};

struct Achievement_CategoryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shbi";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(3, 4, 0xED226BC9, types, arraySizes, 2);
        return &instance;
    }
};

struct AdventureJournalMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sssssiihhhhhhbbbbbbbii";
        static uint8 const arraySizes[22] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1 };
        static DB2Meta instance(-1, 22, 0xB2FFA8DD, types, arraySizes, -1);
        return &instance;
    }
};

struct AdventureMapPOIMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssfibiiiiiiii";
        static uint8 const arraySizes[13] = { 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 13, 0x0C288A82, types, arraySizes, -1);
        return &instance;
    }
};

struct AlliedRaceMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiiiiii";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(1, 8, 0xB13ABE04, types, arraySizes, -1);
        return &instance;
    }
};

struct AlliedRaceRacialAbilityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssbii";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x9EBF9B09, types, arraySizes, 4);
        return &instance;
    }
};

struct AnimKitMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihh";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x81D6D250, types, arraySizes, -1);
        return &instance;
    }
};

struct AnimKitBoneSetMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbbbb";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0xFE4B9B1F, types, arraySizes, -1);
        return &instance;
    }
};

struct AnimKitBoneSetAliasMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xEA8B67BC, types, arraySizes, -1);
        return &instance;
    }
};

struct AnimKitConfigMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x8A70ED4C, types, arraySizes, -1);
        return &instance;
    }
};

struct AnimKitConfigBoneSetMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hbh";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x3D9B3BA7, types, arraySizes, 2);
        return &instance;
    }
};

struct AnimKitPriorityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "b";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x5E93C107, types, arraySizes, -1);
        return &instance;
    }
};

struct AnimKitReplacementMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhhih";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(3, 5, 0x0735DB83, types, arraySizes, 4);
        return &instance;
    }
};

struct AnimKitSegmentMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiifihhhhhhbbbbbbi";
        static uint8 const arraySizes[18] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 18, 0x08F09B89, types, arraySizes, 5);
        return &instance;
    }
};

struct AnimReplacementMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhhih";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(3, 5, 0x2C8B0F35, types, arraySizes, 4);
        return &instance;
    }
};

struct AnimReplacementSetMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "b";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x3761247A, types, arraySizes, -1);
        return &instance;
    }
};

struct AnimationDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihhb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x03182786, types, arraySizes, -1);
        return &instance;
    }
};

struct AreaFarClipOverrideMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iffii";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(4, 5, 0xEB5921CC, types, arraySizes, -1);
        return &instance;
    }
};

struct AreaGroupMemberMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hh";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x50AA43EE, types, arraySizes, 1);
        return &instance;
    }
};

struct AreaPOIMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssifiihhhhbbiiii";
        static uint8 const arraySizes[16] = { 1, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 16, 0xB161EE90, types, arraySizes, -1);
        return &instance;
    }
};

struct AreaPOIStateMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbbih";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x673BDA80, types, arraySizes, 4);
        return &instance;
    }
};

struct AreaTableMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssifhhhhhhhhhhbbbbbbbbi";
        static uint8 const arraySizes[23] = { 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 23, 0x0CA01129, types, arraySizes, -1);
        return &instance;
    }
};

struct AreaTriggerMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffffffhhhhhbbbi";
        static uint8 const arraySizes[15] = { 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(14, 15, 0x378573E8, types, arraySizes, 6);
        return &instance;
    }
};

struct AreaTriggerActionSetMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "h";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x5DA480BD, types, arraySizes, -1);
        return &instance;
    }
};

struct AreaTriggerBoxMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "f";
        static uint8 const arraySizes[1] = { 3 };
        static DB2Meta instance(-1, 1, 0x602CFDA6, types, arraySizes, -1);
        return &instance;
    }
};

struct AreaTriggerCylinderMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fff";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x26D4052D, types, arraySizes, -1);
        return &instance;
    }
};

struct AreaTriggerSphereMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "f";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x9141AC7F, types, arraySizes, -1);
        return &instance;
    }
};

struct ArmorLocationMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fffff";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0xCCFBD16E, types, arraySizes, -1);
        return &instance;
    }
};

struct ArtifactMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "siiihhbbii";
        static uint8 const arraySizes[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 10, 0x76CF31A8, types, arraySizes, -1);
        return &instance;
    }
};

struct ArtifactAppearanceMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "siffihhbbbbiiii";
        static uint8 const arraySizes[15] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(11, 15, 0xAEED7395, types, arraySizes, 5);
        return &instance;
    }
};

struct ArtifactAppearanceSetMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sshhbbbib";
        static uint8 const arraySizes[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(7, 9, 0x53DFED74, types, arraySizes, 8);
        return &instance;
    }
};

struct ArtifactCategoryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hh";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x21328475, types, arraySizes, -1);
        return &instance;
    }
};

struct ArtifactPowerMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fbbbbii";
        static uint8 const arraySizes[7] = { 2, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(5, 7, 0x45240818, types, arraySizes, 1);
        return &instance;
    }
};

struct ArtifactPowerLinkMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hh";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xE179618C, types, arraySizes, -1);
        return &instance;
    }
};

struct ArtifactPowerPickerMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x2D6AF006, types, arraySizes, -1);
        return &instance;
    }
};

struct ArtifactPowerRankMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ifhbh";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0xA87EACC4, types, arraySizes, 4);
        return &instance;
    }
};

struct ArtifactQuestXPMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i";
        static uint8 const arraySizes[1] = { 10 };
        static DB2Meta instance(-1, 1, 0x86397302, types, arraySizes, -1);
        return &instance;
    }
};

struct ArtifactTierMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiii";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x1A5A50B9, types, arraySizes, -1);
        return &instance;
    }
};

struct ArtifactUnlockMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hbiib";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x52839A77, types, arraySizes, 4);
        return &instance;
    }
};

struct AuctionHouseMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x51CFEEFF, types, arraySizes, -1);
        return &instance;
    }
};

struct BankBagSlotPricesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xEA0AC2AA, types, arraySizes, -1);
        return &instance;
    }
};

struct BannedAddonsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xF779B6E5, types, arraySizes, -1);
        return &instance;
    }
};

struct BarberShopStyleMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssfbbbbi";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(7, 8, 0x670C71AE, types, arraySizes, -1);
        return &instance;
    }
};

struct BattlePetAbilityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssihbbi";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0x0F29944D, types, arraySizes, -1);
        return &instance;
    }
};

struct BattlePetAbilityEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhhhhbi";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 6, 1, 1 };
        static DB2Meta instance(6, 7, 0x5D30EBC5, types, arraySizes, 0);
        return &instance;
    }
};

struct BattlePetAbilityStateMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ibh";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x0E40A884, types, arraySizes, 2);
        return &instance;
    }
};

struct BattlePetAbilityTurnMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhbbbi";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(5, 6, 0xCB063F4F, types, arraySizes, 0);
        return &instance;
    }
};

struct BattlePetBreedQualityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xBDE74E1D, types, arraySizes, -1);
        return &instance;
    }
};

struct BattlePetBreedStateMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hbb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x68D5C999, types, arraySizes, 2);
        return &instance;
    }
};

struct BattlePetDisplayOverrideMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiib";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xDE5129EA, types, arraySizes, -1);
        return &instance;
    }
};

struct BattlePetEffectPropertiesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shb";
        static uint8 const arraySizes[3] = { 6, 1, 6 };
        static DB2Meta instance(-1, 3, 0x56070751, types, arraySizes, -1);
        return &instance;
    }
};

struct BattlePetNPCTeamMemberMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x4423F004, types, arraySizes, -1);
        return &instance;
    }
};

struct BattlePetSpeciesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssiiihbbiii";
        static uint8 const arraySizes[11] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(8, 11, 0x8A3D97A4, types, arraySizes, -1);
        return &instance;
    }
};

struct BattlePetSpeciesStateMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ibh";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x8F958D5C, types, arraySizes, 2);
        return &instance;
    }
};

struct BattlePetSpeciesXAbilityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hbbh";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x9EE27D6A, types, arraySizes, 3);
        return &instance;
    }
};

struct BattlePetStateMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shh";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x1797AB4A, types, arraySizes, -1);
        return &instance;
    }
};

struct BattlePetVisualMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sihhhbb";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0x097E0F6C, types, arraySizes, -1);
        return &instance;
    }
};

struct BattlemasterListMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssssihhhbbbbbbbbb";
        static uint8 const arraySizes[17] = { 1, 1, 1, 1, 1, 16, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 17, 0xD8AAA088, types, arraySizes, -1);
        return &instance;
    }
};

struct BeamEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iffihhhhhh";
        static uint8 const arraySizes[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 10, 0x42C18603, types, arraySizes, -1);
        return &instance;
    }
};

struct BoneWindModifierModelMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ii";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x577A0772, types, arraySizes, 0);
        return &instance;
    }
};

struct BoneWindModifiersMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ff";
        static uint8 const arraySizes[2] = { 3, 1 };
        static DB2Meta instance(-1, 2, 0xB4E7449E, types, arraySizes, -1);
        return &instance;
    }
};

struct BountyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihhib";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0xE76E716C, types, arraySizes, 4);
        return &instance;
    }
};

struct BountySetMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hi";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x96B908A5, types, arraySizes, -1);
        return &instance;
    }
};

struct BroadcastTextMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sshhhbbii";
        static uint8 const arraySizes[9] = { 1, 1, 3, 3, 1, 1, 1, 1, 2 };
        static DB2Meta instance(-1, 9, 0x51BF0C33, types, arraySizes, -1);
        return &instance;
    }
};

struct CameraEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "b";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xF6AB4622, types, arraySizes, -1);
        return &instance;
    }
};

struct CameraEffectEntryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffffffffhbbbbbbh";
        static uint8 const arraySizes[16] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 16, 0xC5105557, types, arraySizes, 15);
        return &instance;
    }
};

struct CameraModeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fffffhbbbbb";
        static uint8 const arraySizes[11] = { 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 11, 0xCDB6BC2F, types, arraySizes, -1);
        return &instance;
    }
};

struct CastableRaidBuffsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ii";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x5BDD4028, types, arraySizes, 1);
        return &instance;
    }
};

struct CelestialBodyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiiiifffffffhi";
        static uint8 const arraySizes[15] = { 1, 1, 2, 1, 1, 2, 2, 2, 1, 2, 1, 3, 1, 1, 1 };
        static DB2Meta instance(14, 15, 0xD09BE31C, types, arraySizes, -1);
        return &instance;
    }
};

struct Cfg_CategoriesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shbbb";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x705B82C8, types, arraySizes, -1);
        return &instance;
    }
};

struct Cfg_ConfigsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fhbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xC618392F, types, arraySizes, -1);
        return &instance;
    }
};

struct Cfg_RegionsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "siihb";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x9F4272BF, types, arraySizes, -1);
        return &instance;
    }
};

struct CharBaseInfoMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x9E9939B8, types, arraySizes, -1);
        return &instance;
    }
};

struct CharBaseSectionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x4F08B5F3, types, arraySizes, -1);
        return &instance;
    }
};

struct CharComponentTextureLayoutsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hh";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x0F515E34, types, arraySizes, -1);
        return &instance;
    }
};

struct CharComponentTextureSectionsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihhhhbb";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0xCE76000F, types, arraySizes, -1);
        return &instance;
    }
};

struct CharHairGeosetsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ibbbbbbbbi";
        static uint8 const arraySizes[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 10, 0x33EB32D2, types, arraySizes, 1);
        return &instance;
    }
};

struct CharSectionsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihbbbbb";
        static uint8 const arraySizes[7] = { 3, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0xE349E55B, types, arraySizes, -1);
        return &instance;
    }
};

struct CharShipmentMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiiihhbb";
        static uint8 const arraySizes[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 9, 0xE6D3C7C1, types, arraySizes, 5);
        return &instance;
    }
};

struct CharShipmentContainerMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssihhhhhhbbbbbbi";
        static uint8 const arraySizes[16] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 16, 0x194896E3, types, arraySizes, -1);
        return &instance;
    }
};

struct CharStartOutfitMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iibbbbb";
        static uint8 const arraySizes[7] = { 24, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0x0EEBEE24, types, arraySizes, 6);
        return &instance;
    }
};

struct CharTitlesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sshb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x7A58AA5F, types, arraySizes, -1);
        return &instance;
    }
};

struct CharacterFaceBoneSetMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ibbbb";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x1C634076, types, arraySizes, 4);
        return &instance;
    }
};

struct CharacterFacialHairStylesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ibbb";
        static uint8 const arraySizes[4] = { 5, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x47D79688, types, arraySizes, -1);
        return &instance;
    }
};

struct CharacterLoadoutMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "lbb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x87B51673, types, arraySizes, -1);
        return &instance;
    }
};

struct CharacterLoadoutItemMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ih";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x3C3D40B9, types, arraySizes, 1);
        return &instance;
    }
};

struct CharacterServiceInfoMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sssiiiiiiii";
        static uint8 const arraySizes[11] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 11, 0xADE120EF, types, arraySizes, -1);
        return &instance;
    }
};

struct ChatChannelsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssib";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x1A325E80, types, arraySizes, -1);
        return &instance;
    }
};

struct ChatProfanityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x328E1FE6, types, arraySizes, -1);
        return &instance;
    }
};

struct ChrClassRaceSexMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbbiii";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 6, 0x5E29DFA1, types, arraySizes, -1);
        return &instance;
    }
};

struct ChrClassTitleMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xC155DB2C, types, arraySizes, -1);
        return &instance;
    }
};

struct ChrClassUIDisplayMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x59A95A73, types, arraySizes, -1);
        return &instance;
    }
};

struct ChrClassVillainMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xA6AC18CD, types, arraySizes, -1);
        return &instance;
    }
};

struct ChrClassesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sssssiiiiihhhbbbbbbi";
        static uint8 const arraySizes[20] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(19, 20, 0x6F7AB8E7, types, arraySizes, -1);
        return &instance;
    }
};

struct ChrClassesXPowerTypesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xAF977B23, types, arraySizes, 1);
        return &instance;
    }
};

struct ChrCustomizationMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "siiiii";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 3, 1 };
        static DB2Meta instance(-1, 6, 0x71833CE5, types, arraySizes, 5);
        return &instance;
    }
};

struct ChrRacesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssssssiiiiiffiiihhhhbbbbbbbbbbiiiiiiii";
        static uint8 const arraySizes[38] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3 };
        static DB2Meta instance(30, 38, 0x51C511F9, types, arraySizes, -1);
        return &instance;
    }
};

struct ChrSpecializationMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sssibbbbbiiii";
        static uint8 const arraySizes[13] = { 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(9, 13, 0x3D86B8F7, types, arraySizes, 4);
        return &instance;
    }
};

struct ChrUpgradeBucketMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hib";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(1, 3, 0xACF64A80, types, arraySizes, 2);
        return &instance;
    }
};

struct ChrUpgradeBucketSpellMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ih";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xDF939031, types, arraySizes, 1);
        return &instance;
    }
};

struct ChrUpgradeTierMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbbi";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(3, 4, 0x2C87937D, types, arraySizes, -1);
        return &instance;
    }
};

struct CinematicCameraMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iffi";
        static uint8 const arraySizes[4] = { 1, 3, 1, 1 };
        static DB2Meta instance(-1, 4, 0x0062B0F4, types, arraySizes, -1);
        return &instance;
    }
};

struct CinematicSequencesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ih";
        static uint8 const arraySizes[2] = { 1, 8 };
        static DB2Meta instance(-1, 2, 0x470FDA8C, types, arraySizes, -1);
        return &instance;
    }
};

struct CloakDampeningMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fffffff";
        static uint8 const arraySizes[7] = { 5, 5, 2, 2, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0xB2DF7F2A, types, arraySizes, -1);
        return &instance;
    }
};

struct CombatConditionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhhhhbbbbbb";
        static uint8 const arraySizes[11] = { 1, 1, 1, 2, 2, 2, 2, 1, 2, 2, 1 };
        static DB2Meta instance(-1, 11, 0x28D253C6, types, arraySizes, -1);
        return &instance;
    }
};

struct CommentatorStartLocationMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fi";
        static uint8 const arraySizes[2] = { 3, 1 };
        static DB2Meta instance(-1, 2, 0xEFD540EF, types, arraySizes, -1);
        return &instance;
    }
};

struct CommentatorTrackedCooldownMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbih";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x84985168, types, arraySizes, 3);
        return &instance;
    }
};

struct ComponentModelFileDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x25BB55A7, types, arraySizes, -1);
        return &instance;
    }
};

struct ComponentTextureFileDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x50C58D4F, types, arraySizes, -1);
        return &instance;
    }
};

struct ConfigurationWarningMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "si";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x0B350390, types, arraySizes, -1);
        return &instance;
    }
};

struct ContributionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssiiii";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 4, 1 };
        static DB2Meta instance(2, 6, 0x8EDF6090, types, arraySizes, 3);
        return &instance;
    }
};

struct ConversationLineMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiihhbbb";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 8, 0x032B137B, types, arraySizes, -1);
        return &instance;
    }
};

struct CreatureMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssssiiifbbbb";
        static uint8 const arraySizes[12] = { 1, 1, 1, 1, 3, 1, 4, 4, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 12, 0xCFB508A9, types, arraySizes, -1);
        return &instance;
    }
};

struct CreatureDifficultyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihbbbi";
        static uint8 const arraySizes[6] = { 7, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 6, 0x4291EEC6, types, arraySizes, 5);
        return &instance;
    }
};

struct CreatureDispXUiCameraMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ih";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x6E0E7C15, types, arraySizes, -1);
        return &instance;
    }
};

struct CreatureDisplayInfoMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ifhhbbbiibhfibhihhbifii";
        static uint8 const arraySizes[23] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3 };
        static DB2Meta instance(0, 23, 0x406268DF, types, arraySizes, -1);
        return &instance;
    }
};

struct CreatureDisplayInfoCondMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "liiibbiiiiiiiii";
        static uint8 const arraySizes[15] = { 1, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1 };
        static DB2Meta instance(-1, 15, 0x26CD44AB, types, arraySizes, 14);
        return &instance;
    }
};

struct CreatureDisplayInfoEvtMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iibi";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x3FEF69BB, types, arraySizes, 3);
        return &instance;
    }
};

struct CreatureDisplayInfoExtraMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iibbbbbbbbbb";
        static uint8 const arraySizes[12] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1 };
        static DB2Meta instance(-1, 12, 0x6DF98EF6, types, arraySizes, -1);
        return &instance;
    }
};

struct CreatureDisplayInfoTrnMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ifiiii";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 6, 0x8E687740, types, arraySizes, 5);
        return &instance;
    }
};

struct CreatureFamilyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sffihhbbb";
        static uint8 const arraySizes[9] = { 1, 1, 1, 1, 2, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 9, 0xE2DC5126, types, arraySizes, -1);
        return &instance;
    }
};

struct CreatureImmunitiesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ibbbbbiii";
        static uint8 const arraySizes[9] = { 2, 1, 1, 1, 1, 1, 1, 8, 16 };
        static DB2Meta instance(-1, 9, 0x2D20050B, types, arraySizes, -1);
        return &instance;
    }
};

struct CreatureModelDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffffffffffffffffffiiiiiiiiii";
        static uint8 const arraySizes[28] = { 1, 1, 1, 1, 1, 1, 1, 6, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 28, 0x983BD312, types, arraySizes, -1);
        return &instance;
    }
};

struct CreatureMovementInfoMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "f";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x39F710E3, types, arraySizes, -1);
        return &instance;
    }
};

struct CreatureSoundDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffbiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii";
        static uint8 const arraySizes[37] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 5, 4 };
        static DB2Meta instance(-1, 37, 0x7C3C39B9, types, arraySizes, -1);
        return &instance;
    }
};

struct CreatureTypeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x7BA9D2F8, types, arraySizes, -1);
        return &instance;
    }
};

struct CreatureXContributionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(0, 3, 0x3448DF58, types, arraySizes, 2);
        return &instance;
    }
};

struct CriteriaMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiihhbbbbb";
        static uint8 const arraySizes[11] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 11, 0xA87A5BB9, types, arraySizes, -1);
        return &instance;
    }
};

struct CriteriaTreeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sihbiii";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0x0A1B99C2, types, arraySizes, -1);
        return &instance;
    }
};

struct CriteriaTreeXEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hi";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x929D9B0C, types, arraySizes, 1);
        return &instance;
    }
};

struct CurrencyCategoryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xC3735D76, types, arraySizes, -1);
        return &instance;
    }
};

struct CurrencyTypesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssiiibbbii";
        static uint8 const arraySizes[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 10, 0x6CC25CBF, types, arraySizes, -1);
        return &instance;
    }
};

struct CurveMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x17EA5154, types, arraySizes, -1);
        return &instance;
    }
};

struct CurvePointMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fhb";
        static uint8 const arraySizes[3] = { 2, 1, 1 };
        static DB2Meta instance(-1, 3, 0xF36752EB, types, arraySizes, -1);
        return &instance;
    }
};

struct DeathThudLookupsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbii";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xD469085C, types, arraySizes, -1);
        return &instance;
    }
};

struct DecalPropertiesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiffffffffbbiiiii";
        static uint8 const arraySizes[17] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(0, 17, 0xDD48C72A, types, arraySizes, -1);
        return &instance;
    }
};

struct DeclinedWordMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "si";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(1, 2, 0x3FF5EC3E, types, arraySizes, -1);
        return &instance;
    }
};

struct DeclinedWordCasesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbi";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x821A20A9, types, arraySizes, 2);
        return &instance;
    }
};

struct DestructibleModelDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhhhhbbbbbbbbbbbbbbbbb";
        static uint8 const arraySizes[22] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 22, 0x1092C9AF, types, arraySizes, -1);
        return &instance;
    }
};

struct DeviceBlacklistMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hh";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xD956413D, types, arraySizes, -1);
        return &instance;
    }
};

struct DeviceDefaultSettingsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x90CFEC8C, types, arraySizes, -1);
        return &instance;
    }
};

struct DifficultyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shhhbbbbbbbbb";
        static uint8 const arraySizes[13] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 13, 0x92302BB8, types, arraySizes, -1);
        return &instance;
    }
};

struct DissolveEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffffffffbbiiii";
        static uint8 const arraySizes[14] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 14, 0x566413E7, types, arraySizes, -1);
        return &instance;
    }
};

struct DriverBlacklistMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iihbbbb";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0x1466ACAD, types, arraySizes, -1);
        return &instance;
    }
};

struct DungeonEncounterMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sihbbbiii";
        static uint8 const arraySizes[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(6, 9, 0xB04A2596, types, arraySizes, 2);
        return &instance;
    }
};

struct DungeonMapMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffhhbbbi";
        static uint8 const arraySizes[8] = { 2, 2, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(7, 8, 0xB5A245F4, types, arraySizes, 2);
        return &instance;
    }
};

struct DungeonMapChunkMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fihhh";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x7927A3A7, types, arraySizes, 2);
        return &instance;
    }
};

struct DurabilityCostsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hh";
        static uint8 const arraySizes[2] = { 21, 8 };
        static DB2Meta instance(-1, 2, 0x8447966A, types, arraySizes, -1);
        return &instance;
    }
};

struct DurabilityQualityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "f";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x6F64793D, types, arraySizes, -1);
        return &instance;
    }
};

struct EdgeGlowEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffffffffffbii";
        static uint8 const arraySizes[13] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 13, 0x083BF2C4, types, arraySizes, -1);
        return &instance;
    }
};

struct EmotesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "lsiihbiii";
        static uint8 const arraySizes[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 9, 0x14467F27, types, arraySizes, -1);
        return &instance;
    }
};

struct EmotesTextMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sh";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xE85AFA10, types, arraySizes, -1);
        return &instance;
    }
};

struct EmotesTextDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbh";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x0E19BCF1, types, arraySizes, 2);
        return &instance;
    }
};

struct EmotesTextSoundMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbbih";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x6DFAF9BC, types, arraySizes, 4);
        return &instance;
    }
};

struct EnvironmentalDamageMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xC4552C14, types, arraySizes, -1);
        return &instance;
    }
};

struct ExhaustionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssiffffi";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(7, 8, 0xE6E16045, types, arraySizes, -1);
        return &instance;
    }
};

struct FactionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "lssiifihhhhhbbbb";
        static uint8 const arraySizes[16] = { 4, 1, 1, 1, 4, 2, 4, 1, 4, 4, 1, 1, 2, 1, 1, 1 };
        static DB2Meta instance(3, 16, 0x6BFE8737, types, arraySizes, -1);
        return &instance;
    }
};

struct FactionGroupMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssibii";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(2, 6, 0x7A7F9A51, types, arraySizes, -1);
        return &instance;
    }
};

struct FactionTemplateMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhhhbbb";
        static uint8 const arraySizes[7] = { 1, 1, 4, 4, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0x6F1D2135, types, arraySizes, -1);
        return &instance;
    }
};

struct FootprintTexturesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xFD6FF285, types, arraySizes, -1);
        return &instance;
    }
};

struct FootstepTerrainLookupMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hbii";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x454895AE, types, arraySizes, -1);
        return &instance;
    }
};

struct FriendshipRepReactionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x9C412E5B, types, arraySizes, 2);
        return &instance;
    }
};

struct FriendshipReputationMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sihi";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(3, 4, 0x406EE0AB, types, arraySizes, -1);
        return &instance;
    }
};

struct FullScreenEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fffffffffffffffffffffffiiii";
        static uint8 const arraySizes[27] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 27, 0x5CBF1D1B, types, arraySizes, -1);
        return &instance;
    }
};

struct GMSurveyAnswersMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbi";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x422747F6, types, arraySizes, 2);
        return &instance;
    }
};

struct GMSurveyCurrentSurveyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "b";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x617205BF, types, arraySizes, -1);
        return &instance;
    }
};

struct GMSurveyQuestionsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x9D852FDC, types, arraySizes, -1);
        return &instance;
    }
};

struct GMSurveySurveysMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "b";
        static uint8 const arraySizes[1] = { 15 };
        static DB2Meta instance(-1, 1, 0x17FEF812, types, arraySizes, -1);
        return &instance;
    }
};

struct GameObjectArtKitMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ii";
        static uint8 const arraySizes[2] = { 1, 3 };
        static DB2Meta instance(-1, 2, 0x6F65BC41, types, arraySizes, -1);
        return &instance;
    }
};

struct GameObjectDiffAnimMapMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hbbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x89A617CF, types, arraySizes, 3);
        return &instance;
    }
};

struct GameObjectDisplayInfoMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ifffh";
        static uint8 const arraySizes[5] = { 1, 6, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x9F2098D1, types, arraySizes, -1);
        return &instance;
    }
};

struct GameObjectDisplayInfoXSoundKitMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x4BBA66F2, types, arraySizes, 2);
        return &instance;
    }
};

struct GameObjectsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sfffihhhhbbi";
        static uint8 const arraySizes[12] = { 1, 3, 4, 1, 8, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(11, 12, 0x597E8643, types, arraySizes, 5);
        return &instance;
    }
};

struct GameTipsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shhb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x547E3F0F, types, arraySizes, -1);
        return &instance;
    }
};

struct GarrAbilityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssihhbbi";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(7, 8, 0x5DF95DBD, types, arraySizes, -1);
        return &instance;
    }
};

struct GarrAbilityCategoryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x96663ABF, types, arraySizes, -1);
        return &instance;
    }
};

struct GarrAbilityEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fffihbbbbbbi";
        static uint8 const arraySizes[12] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(11, 12, 0xE6A6CB99, types, arraySizes, 4);
        return &instance;
    }
};

struct GarrBuildingMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssssiiihhhhhhhhbbbbbbiii";
        static uint8 const arraySizes[24] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 24, 0x200F9858, types, arraySizes, -1);
        return &instance;
    }
};

struct GarrBuildingDoodadSetMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbbbb";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x2A861C7F, types, arraySizes, -1);
        return &instance;
    }
};

struct GarrBuildingPlotInstMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fhhbi";
        static uint8 const arraySizes[5] = { 2, 1, 1, 1, 1 };
        static DB2Meta instance(4, 5, 0xF45B6227, types, arraySizes, 3);
        return &instance;
    }
};

struct GarrClassSpecMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssshhbbi";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(7, 8, 0x194CD478, types, arraySizes, -1);
        return &instance;
    }
};

struct GarrClassSpecPlayerCondMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sibiii";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 6, 0x06936172, types, arraySizes, -1);
        return &instance;
    }
};

struct GarrEncounterMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "siffiii";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(5, 7, 0x63EF121A, types, arraySizes, -1);
        return &instance;
    }
};

struct GarrEncounterSetXEncounterMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(0, 3, 0x3AA64423, types, arraySizes, 2);
        return &instance;
    }
};

struct GarrEncounterXMechanicMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbh";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x97080E17, types, arraySizes, 2);
        return &instance;
    }
};

struct GarrFollItemSetMemberMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihbh";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xCA1C4CBF, types, arraySizes, 3);
        return &instance;
    }
};

struct GarrFollSupportSpellMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iibi";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xB7DBA2D1, types, arraySizes, 3);
        return &instance;
    }
};

struct GarrFollowerMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sssiiiiiihhhhhhbbbbbbbbbbbbbbbbi";
        static uint8 const arraySizes[32] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(31, 32, 0xAAB75E04, types, arraySizes, -1);
        return &instance;
    }
};

struct GarrFollowerLevelXPMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x1ED485E2, types, arraySizes, -1);
        return &instance;
    }
};

struct GarrFollowerQualityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihbbbbi";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0xAFF4CF7E, types, arraySizes, -1);
        return &instance;
    }
};

struct GarrFollowerSetXFollowerMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ii";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xDB0E0A17, types, arraySizes, 1);
        return &instance;
    }
};

struct GarrFollowerTypeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hbbbbbb";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0xD676FBC0, types, arraySizes, -1);
        return &instance;
    }
};

struct GarrFollowerUICreatureMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ifbbbh";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 6, 0x7E275E96, types, arraySizes, 5);
        return &instance;
    }
};

struct GarrFollowerXAbilityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hbh";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x996447F1, types, arraySizes, 2);
        return &instance;
    }
};

struct GarrItemLevelUpgradeDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiii";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(0, 5, 0x069F44E5, types, arraySizes, -1);
        return &instance;
    }
};

struct GarrMechanicMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fbi";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xAB49DA61, types, arraySizes, -1);
        return &instance;
    }
};

struct GarrMechanicSetXMechanicMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(1, 3, 0x59514F7B, types, arraySizes, 2);
        return &instance;
    }
};

struct GarrMechanicTypeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssibi";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(4, 5, 0x6FEA569F, types, arraySizes, -1);
        return &instance;
    }
};

struct GarrMissionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sssiiffhhhbbbbbbbbbiiiiiiiiii";
        static uint8 const arraySizes[29] = { 1, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(19, 29, 0xDDD70490, types, arraySizes, 28);
        return &instance;
    }
};

struct GarrMissionTextureMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fh";
        static uint8 const arraySizes[2] = { 2, 1 };
        static DB2Meta instance(-1, 2, 0x3071301C, types, arraySizes, -1);
        return &instance;
    }
};

struct GarrMissionTypeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shh";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xA289655E, types, arraySizes, -1);
        return &instance;
    }
};

struct GarrMissionXEncounterMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "biiii";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(1, 5, 0xBCB016C6, types, arraySizes, 4);
        return &instance;
    }
};

struct GarrMissionXFollowerMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x1EBABA29, types, arraySizes, 2);
        return &instance;
    }
};

struct GarrMssnBonusAbilityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fihbb";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x35F5AE92, types, arraySizes, -1);
        return &instance;
    }
};

struct GarrPlotMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "siibbbi";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 2 };
        static DB2Meta instance(-1, 7, 0xE12049E0, types, arraySizes, -1);
        return &instance;
    }
};

struct GarrPlotBuildingMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x3F77A6FA, types, arraySizes, -1);
        return &instance;
    }
};

struct GarrPlotInstanceMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xB708BB37, types, arraySizes, -1);
        return &instance;
    }
};

struct GarrPlotUICategoryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xA94645EE, types, arraySizes, -1);
        return &instance;
    }
};

struct GarrSiteLevelMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fhhhhhbbb";
        static uint8 const arraySizes[9] = { 2, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 9, 0xD3979C38, types, arraySizes, -1);
        return &instance;
    }
};

struct GarrSiteLevelPlotInstMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fhbb";
        static uint8 const arraySizes[4] = { 2, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xC4E74201, types, arraySizes, 1);
        return &instance;
    }
};

struct GarrSpecializationMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssifbbb";
        static uint8 const arraySizes[7] = { 1, 1, 1, 2, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0x797A0F2F, types, arraySizes, -1);
        return &instance;
    }
};

struct GarrStringMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xE1C08C0C, types, arraySizes, -1);
        return &instance;
    }
};

struct GarrTalentMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssiibbbiiiiiiiiiiiii";
        static uint8 const arraySizes[20] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(7, 20, 0x53D5FD16, types, arraySizes, 8);
        return &instance;
    }
};

struct GarrTalentTreeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hbbii";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x676CBC04, types, arraySizes, -1);
        return &instance;
    }
};

struct GarrTypeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiii";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 2 };
        static DB2Meta instance(-1, 5, 0x7C52F3B7, types, arraySizes, -1);
        return &instance;
    }
};

struct GarrUiAnimClassInfoMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fbbiii";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 6, 0xDBF4633D, types, arraySizes, -1);
        return &instance;
    }
};

struct GarrUiAnimRaceInfoMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffffffffffffb";
        static uint8 const arraySizes[13] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 13, 0x44B9C1DE, types, arraySizes, -1);
        return &instance;
    }
};

struct GemPropertiesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihh";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x84558CAB, types, arraySizes, -1);
        return &instance;
    }
};

struct GlobalStringsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x2CA3EA1E, types, arraySizes, -1);
        return &instance;
    }
};

struct GlyphBindableSpellMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ih";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xEA228DFA, types, arraySizes, 1);
        return &instance;
    }
};

struct GlyphExclusiveCategoryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xFE598FCD, types, arraySizes, -1);
        return &instance;
    }
};

struct GlyphPropertiesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xD0046829, types, arraySizes, -1);
        return &instance;
    }
};

struct GlyphRequiredSpecMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hh";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xDD6481CE, types, arraySizes, 1);
        return &instance;
    }
};

struct GroundEffectDoodadMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffbi";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x0376B2D6, types, arraySizes, -1);
        return &instance;
    }
};

struct GroundEffectTextureMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hbbi";
        static uint8 const arraySizes[4] = { 4, 4, 1, 1 };
        static DB2Meta instance(-1, 4, 0x84549F0A, types, arraySizes, -1);
        return &instance;
    }
};

struct GroupFinderActivityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sshhhbbbbbbbbb";
        static uint8 const arraySizes[14] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 14, 0x3EF2F3BD, types, arraySizes, -1);
        return &instance;
    }
};

struct GroupFinderActivityGrpMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xC9458196, types, arraySizes, -1);
        return &instance;
    }
};

struct GroupFinderCategoryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x9213552F, types, arraySizes, -1);
        return &instance;
    }
};

struct GuildColorBackgroundMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xCC0CEFF1, types, arraySizes, -1);
        return &instance;
    }
};

struct GuildColorBorderMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xCC0CEFF1, types, arraySizes, -1);
        return &instance;
    }
};

struct GuildColorEmblemMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xCC0CEFF1, types, arraySizes, -1);
        return &instance;
    }
};

struct GuildPerkSpellsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xC15D6E9F, types, arraySizes, -1);
        return &instance;
    }
};

struct HeirloomMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "siiiiihbbi";
        static uint8 const arraySizes[10] = { 1, 1, 1, 1, 1, 3, 3, 1, 1, 1 };
        static DB2Meta instance(9, 10, 0x36887C6F, types, arraySizes, -1);
        return &instance;
    }
};

struct HelmetAnimScalingMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xB9EC1058, types, arraySizes, 2);
        return &instance;
    }
};

struct HelmetGeosetVisDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i";
        static uint8 const arraySizes[1] = { 9 };
        static DB2Meta instance(-1, 1, 0x3B38D999, types, arraySizes, -1);
        return &instance;
    }
};

struct HighlightColorMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiibb";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x5FADC5D3, types, arraySizes, -1);
        return &instance;
    }
};

struct HolidayDescriptionsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x92A95550, types, arraySizes, -1);
        return &instance;
    }
};

struct HolidayNamesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x96663ABF, types, arraySizes, -1);
        return &instance;
    }
};

struct HolidaysMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iihhbbbbbiii";
        static uint8 const arraySizes[12] = { 1, 16, 10, 1, 1, 10, 1, 1, 1, 1, 1, 3 };
        static DB2Meta instance(0, 12, 0x7C3E60FC, types, arraySizes, -1);
        return &instance;
    }
};

struct HotfixMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x3747930B, types, arraySizes, -1);
        return &instance;
    }
};

struct ImportPriceArmorMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffff";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x1F7A850F, types, arraySizes, -1);
        return &instance;
    }
};

struct ImportPriceQualityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "f";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x6F64793D, types, arraySizes, -1);
        return &instance;
    }
};

struct ImportPriceShieldMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "f";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x6F64793D, types, arraySizes, -1);
        return &instance;
    }
};

struct ImportPriceWeaponMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "f";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x6F64793D, types, arraySizes, -1);
        return &instance;
    }
};

struct InvasionClientDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sfiiiiiiii";
        static uint8 const arraySizes[10] = { 1, 2, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(2, 10, 0x4C93379F, types, arraySizes, 9);
        return &instance;
    }
};

struct ItemMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ibbbbbbb";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 8, 0x0DFCC83D, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemAppearanceMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiib";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x06D35A59, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemAppearanceXUiCameraMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hh";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x67747E15, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemArmorQualityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fh";
        static uint8 const arraySizes[2] = { 7, 1 };
        static DB2Meta instance(-1, 2, 0x85642CC0, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemArmorShieldMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fh";
        static uint8 const arraySizes[2] = { 7, 1 };
        static DB2Meta instance(-1, 2, 0xC2186F95, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemArmorTotalMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffffh";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x45C396DD, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemBagFamilyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x96663ABF, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemBonusMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihbb";
        static uint8 const arraySizes[4] = { 3, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xE12FB1A0, types, arraySizes, 1);
        return &instance;
    }
};

struct ItemBonusListLevelDeltaMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hi";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(1, 2, 0xDFBF5AC9, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemBonusTreeNodeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhhbh";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x84FE93B7, types, arraySizes, 4);
        return &instance;
    }
};

struct ItemChildEquipmentMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ibi";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xB6940674, types, arraySizes, 2);
        return &instance;
    }
};

struct ItemClassMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sfbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xA1E4663C, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemContextPickerEntryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbiiii";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 6, 0x4A6DF90B, types, arraySizes, 5);
        return &instance;
    }
};

struct ItemCurrencyCostMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xE2FF5688, types, arraySizes, 0);
        return &instance;
    }
};

struct ItemDamageAmmoMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fh";
        static uint8 const arraySizes[2] = { 7, 1 };
        static DB2Meta instance(-1, 2, 0xC2186F95, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemDamageOneHandMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fh";
        static uint8 const arraySizes[2] = { 7, 1 };
        static DB2Meta instance(-1, 2, 0xC2186F95, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemDamageOneHandCasterMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fh";
        static uint8 const arraySizes[2] = { 7, 1 };
        static DB2Meta instance(-1, 2, 0xC2186F95, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemDamageTwoHandMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fh";
        static uint8 const arraySizes[2] = { 7, 1 };
        static DB2Meta instance(-1, 2, 0xC2186F95, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemDamageTwoHandCasterMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fh";
        static uint8 const arraySizes[2] = { 7, 1 };
        static DB2Meta instance(-1, 2, 0xC2186F95, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemDisenchantLootMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhhbbbb";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0xC0D926CC, types, arraySizes, 6);
        return &instance;
    }
};

struct ItemDisplayInfoMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiiiiiiiiiiiii";
        static uint8 const arraySizes[15] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 4, 4, 2 };
        static DB2Meta instance(-1, 15, 0x99606089, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemDisplayInfoMaterialResMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ibi";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xDEE4ED7B, types, arraySizes, 2);
        return &instance;
    }
};

struct ItemDisplayXUiCameraMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ih";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xE57737B2, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiihhhbbi";
        static uint8 const arraySizes[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 9, 0xA390FA40, types, arraySizes, 8);
        return &instance;
    }
};

struct ItemExtendedCostMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iihhhbbbbb";
        static uint8 const arraySizes[10] = { 5, 5, 5, 1, 5, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 10, 0xC31F4DEF, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemGroupSoundsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i";
        static uint8 const arraySizes[1] = { 4 };
        static DB2Meta instance(-1, 1, 0xDC2EE466, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemLevelSelectorMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hh";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x8143060E, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemLevelSelectorQualityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ibh";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xB7174A51, types, arraySizes, 2);
        return &instance;
    }
};

struct ItemLevelSelectorQualitySetMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hh";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x20055BA8, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemLimitCategoryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xB6BB188D, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemLimitCategoryConditionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xDE8EAD49, types, arraySizes, 2);
        return &instance;
    }
};

struct ItemModifiedAppearanceMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iibhbb";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(1, 6, 0xE64FD18B, types, arraySizes, 0);
        return &instance;
    }
};

struct ItemModifiedAppearanceExtraMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iibbb";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x77212236, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemNameDescriptionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "si";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x16760BD4, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemPetFoodMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xE4923C1F, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemPriceBaseMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffh";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x4BD234D7, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemRandomPropertiesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sh";
        static uint8 const arraySizes[2] = { 1, 5 };
        static DB2Meta instance(-1, 2, 0xB67375F8, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemRandomSuffixMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shh";
        static uint8 const arraySizes[3] = { 1, 5, 5 };
        static DB2Meta instance(-1, 3, 0x95CAB825, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemRangedDisplayInfoMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiii";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x687A28D1, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemSearchNameMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "lsiihbbbhbihhi";
        static uint8 const arraySizes[14] = { 1, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(2, 14, 0x2D4B72FA, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemSetMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sihii";
        static uint8 const arraySizes[5] = { 1, 17, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x847FF58A, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemSetSpellMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihbh";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xF65D0AF8, types, arraySizes, 3);
        return &instance;
    }
};

struct ItemSparseMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "lsssssiffiiiiiiiffififhhhhhhhhhhhhhhhhhhhhhhhbbbbbbbbbbbbbbbbbbb";
        static uint8 const arraySizes[64] = { 1, 1, 1, 1, 1, 1, 4, 1, 1, 1, 1, 1, 1, 1, 1, 10, 10, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 10, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 10, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 64, 0x4007DE16, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemSpecMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hbbbbb";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 6, 0xB17B7986, types, arraySizes, 3);
        return &instance;
    }
};

struct ItemSpecOverrideMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hi";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xE499CD2A, types, arraySizes, 1);
        return &instance;
    }
};

struct ItemSubClassMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sshbbbbbbb";
        static uint8 const arraySizes[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 10, 0xDAD92A67, types, arraySizes, 3);
        return &instance;
    }
};

struct ItemSubClassMaskMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sib";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xFC1DA850, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemUpgradeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihhbb";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x8F3A4137, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemVisualsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i";
        static uint8 const arraySizes[1] = { 5 };
        static DB2Meta instance(-1, 1, 0x485EA782, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemXBonusTreeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hi";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x87C4B605, types, arraySizes, 1);
        return &instance;
    }
};

struct JournalEncounterMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssfhhhhbbii";
        static uint8 const arraySizes[11] = { 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 11, 0x2935A0FD, types, arraySizes, -1);
        return &instance;
    }
};

struct JournalEncounterCreatureMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssiiihbi";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(7, 8, 0x22C79A42, types, arraySizes, 5);
        return &instance;
    }
};

struct JournalEncounterItemMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihbbbi";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(5, 6, 0x39230FF9, types, arraySizes, 1);
        return &instance;
    }
};

struct JournalEncounterSectionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssiiiihhhhhhbbb";
        static uint8 const arraySizes[15] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 15, 0x13E56B12, types, arraySizes, -1);
        return &instance;
    }
};

struct JournalEncounterXDifficultyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bh";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x321FD542, types, arraySizes, 1);
        return &instance;
    }
};

struct JournalEncounterXMapLocMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fbiiii";
        static uint8 const arraySizes[6] = { 2, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 6, 0x430540E4, types, arraySizes, 5);
        return &instance;
    }
};

struct JournalInstanceMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssiiiihhbbi";
        static uint8 const arraySizes[11] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(10, 11, 0x1691CC3D, types, arraySizes, -1);
        return &instance;
    }
};

struct JournalItemXDifficultyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bh";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x60D9CA15, types, arraySizes, 1);
        return &instance;
    }
};

struct JournalSectionXDifficultyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bh";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x243822A7, types, arraySizes, 1);
        return &instance;
    }
};

struct JournalTierMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x8046B23F, types, arraySizes, -1);
        return &instance;
    }
};

struct JournalTierXInstanceMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hh";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x9C4F4D2A, types, arraySizes, 0);
        return &instance;
    }
};

struct KeychainMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "b";
        static uint8 const arraySizes[1] = { 32 };
        static DB2Meta instance(-1, 1, 0x5B214E82, types, arraySizes, -1);
        return &instance;
    }
};

struct KeystoneAffixMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssi";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x1BCB46AA, types, arraySizes, -1);
        return &instance;
    }
};

struct LFGDungeonExpansionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hbbbiih";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0xB41DEA61, types, arraySizes, 6);
        return &instance;
    }
};

struct LFGDungeonGroupMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x724D58E7, types, arraySizes, -1);
        return &instance;
    }
};

struct LFGDungeonsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssifhhhhhhhhhbbbbbbbbbbbbbbbbbiii";
        static uint8 const arraySizes[33] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 33, 0xF02081A0, types, arraySizes, -1);
        return &instance;
    }
};

struct LFGRoleRequirementMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bih";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x7EB8A359, types, arraySizes, 2);
        return &instance;
    }
};

struct LanguageWordsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xC15912BD, types, arraySizes, -1);
        return &instance;
    }
};

struct LanguagesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "si";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(1, 2, 0x6FA5D0C4, types, arraySizes, -1);
        return &instance;
    }
};

struct LfgDungeonsGroupingMapMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hbh";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x8CB35C50, types, arraySizes, 2);
        return &instance;
    }
};

struct LightMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fffhh";
        static uint8 const arraySizes[5] = { 3, 1, 1, 1, 8 };
        static DB2Meta instance(-1, 5, 0x25025A13, types, arraySizes, -1);
        return &instance;
    }
};

struct LightDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiiiiiiiiiiiiiiiifffffffffiiiiiihh";
        static uint8 const arraySizes[35] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 35, 0x2D2BA7FA, types, arraySizes, 34);
        return &instance;
    }
};

struct LightParamsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffffffhbbbi";
        static uint8 const arraySizes[11] = { 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1 };
        static DB2Meta instance(10, 11, 0xF67DE2AF, types, arraySizes, -1);
        return &instance;
    }
};

struct LightSkyboxMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "siib";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x8817C02C, types, arraySizes, -1);
        return &instance;
    }
};

struct LiquidMaterialMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x62BE0340, types, arraySizes, -1);
        return &instance;
    }
};

struct LiquidObjectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffhbb";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0xACC168A6, types, arraySizes, -1);
        return &instance;
    }
};

struct LiquidTypeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssifffffifihhbbbbbi";
        static uint8 const arraySizes[19] = { 1, 6, 1, 1, 1, 1, 1, 1, 2, 18, 4, 1, 1, 1, 1, 1, 1, 6, 1 };
        static DB2Meta instance(-1, 19, 0x3313BBF3, types, arraySizes, -1);
        return &instance;
    }
};

struct LoadingScreenTaxiSplinesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffhhb";
        static uint8 const arraySizes[5] = { 10, 10, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x4D6292C3, types, arraySizes, -1);
        return &instance;
    }
};

struct LoadingScreensMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x99C0EB78, types, arraySizes, -1);
        return &instance;
    }
};

struct LocaleMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ibbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x592AE13B, types, arraySizes, -1);
        return &instance;
    }
};

struct LocationMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ff";
        static uint8 const arraySizes[2] = { 3, 3 };
        static DB2Meta instance(-1, 2, 0xBBC1BE7A, types, arraySizes, -1);
        return &instance;
    }
};

struct LockMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihbb";
        static uint8 const arraySizes[4] = { 8, 8, 8, 8 };
        static DB2Meta instance(-1, 4, 0xDAC7F42F, types, arraySizes, -1);
        return &instance;
    }
};

struct LockTypeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssssi";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(4, 5, 0xCD5E1D2F, types, arraySizes, -1);
        return &instance;
    }
};

struct LookAtControllerMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffffhhhhbbbbbiiiii";
        static uint8 const arraySizes[18] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 18, 0x543C0D56, types, arraySizes, -1);
        return &instance;
    }
};

struct MailTemplateMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x25C8D6CC, types, arraySizes, -1);
        return &instance;
    }
};

struct ManagedWorldStateMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiiiiiiii";
        static uint8 const arraySizes[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(9, 10, 0xBA06FC33, types, arraySizes, -1);
        return &instance;
    }
};

struct ManagedWorldStateBuffMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiii";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x6D201DC7, types, arraySizes, 3);
        return &instance;
    }
};

struct ManagedWorldStateInputMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x0FC1A9B0, types, arraySizes, -1);
        return &instance;
    }
};

struct ManifestInterfaceActionIconMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(0, 1, 0x6A529F37, types, arraySizes, -1);
        return &instance;
    }
};

struct ManifestInterfaceDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ss";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x9E5F4C99, types, arraySizes, -1);
        return &instance;
    }
};

struct ManifestInterfaceItemIconMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(0, 1, 0x6A529F37, types, arraySizes, -1);
        return &instance;
    }
};

struct ManifestInterfaceTOCDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x6F7D397D, types, arraySizes, -1);
        return &instance;
    }
};

struct ManifestMP3Meta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(0, 1, 0x6A529F37, types, arraySizes, -1);
        return &instance;
    }
};

struct MapMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssssssiffhhhhhhhbbbbb";
        static uint8 const arraySizes[21] = { 1, 1, 1, 1, 1, 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 21, 0xF568DF12, types, arraySizes, -1);
        return &instance;
    }
};

struct MapCelestialBodyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hih";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xBDE1C11C, types, arraySizes, 2);
        return &instance;
    }
};

struct MapChallengeModeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sihhb";
        static uint8 const arraySizes[5] = { 1, 1, 1, 3, 1 };
        static DB2Meta instance(1, 5, 0xC5261662, types, arraySizes, 2);
        return &instance;
    }
};

struct MapDifficultyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbbbbbbih";
        static uint8 const arraySizes[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 9, 0x2B3B759E, types, arraySizes, 8);
        return &instance;
    }
};

struct MapDifficultyXConditionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "siii";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x5F5D7102, types, arraySizes, 3);
        return &instance;
    }
};

struct MapLoadingScreenMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffiii";
        static uint8 const arraySizes[5] = { 2, 2, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0xBBE57FE4, types, arraySizes, 4);
        return &instance;
    }
};

struct MarketingPromotionsXLocaleMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "siiiibb";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0x80362F57, types, arraySizes, -1);
        return &instance;
    }
};

struct MaterialMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "biii";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x0BC8C134, types, arraySizes, -1);
        return &instance;
    }
};

struct MinorTalentMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xAAEF0DF8, types, arraySizes, 2);
        return &instance;
    }
};

struct MissileTargetingMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fffffffffiii";
        static uint8 const arraySizes[12] = { 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 2 };
        static DB2Meta instance(-1, 12, 0x2305491E, types, arraySizes, -1);
        return &instance;
    }
};

struct ModelAnimCloakDampeningMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x839B4263, types, arraySizes, 2);
        return &instance;
    }
};

struct ModelFileDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(1, 3, 0xA395EB50, types, arraySizes, 2);
        return &instance;
    }
};

struct ModelRibbonQualityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bi";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x38F764D9, types, arraySizes, 1);
        return &instance;
    }
};

struct ModifierTreeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiibbbb";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0x7718AFC2, types, arraySizes, -1);
        return &instance;
    }
};

struct MountMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sssifhhbiii";
        static uint8 const arraySizes[11] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(8, 11, 0x4D812F19, types, arraySizes, -1);
        return &instance;
    }
};

struct MountCapabilityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iihhhbii";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(6, 8, 0xB0D11D52, types, arraySizes, -1);
        return &instance;
    }
};

struct MountTypeXCapabilityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xA34A8445, types, arraySizes, 0);
        return &instance;
    }
};

struct MountXDisplayMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xD59B9FE4, types, arraySizes, 2);
        return &instance;
    }
};

struct MovieMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iibb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xF3E9AE3B, types, arraySizes, -1);
        return &instance;
    }
};

struct MovieFileDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "h";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xAA16D59F, types, arraySizes, -1);
        return &instance;
    }
};

struct MovieVariationMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iih";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x3BFD250E, types, arraySizes, 2);
        return &instance;
    }
};

struct NPCModelItemSlotDisplayInfoMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ibi";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x11D16204, types, arraySizes, 2);
        return &instance;
    }
};

struct NPCSoundsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i";
        static uint8 const arraySizes[1] = { 4 };
        static DB2Meta instance(-1, 1, 0x672E1A6B, types, arraySizes, -1);
        return &instance;
    }
};

struct NameGenMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x2EF936CD, types, arraySizes, -1);
        return &instance;
    }
};

struct NamesProfanityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xDFB56E0E, types, arraySizes, -1);
        return &instance;
    }
};

struct NamesReservedMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xE4923C1F, types, arraySizes, -1);
        return &instance;
    }
};

struct NamesReservedLocaleMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xC1403093, types, arraySizes, -1);
        return &instance;
    }
};

struct ObjectEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fhbbbbii";
        static uint8 const arraySizes[8] = { 3, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 8, 0x6A0CF743, types, arraySizes, -1);
        return &instance;
    }
};

struct ObjectEffectModifierMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fbbb";
        static uint8 const arraySizes[4] = { 4, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xA482B053, types, arraySizes, -1);
        return &instance;
    }
};

struct ObjectEffectPackageElemMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhh";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x8CF043E5, types, arraySizes, -1);
        return &instance;
    }
};

struct OutlineEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fiiiii";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 6, 0x466B2BC4, types, arraySizes, -1);
        return &instance;
    }
};

struct OverrideSpellDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iib";
        static uint8 const arraySizes[3] = { 10, 1, 1 };
        static DB2Meta instance(-1, 3, 0x9417628C, types, arraySizes, -1);
        return &instance;
    }
};

struct PVPBracketTypesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bi";
        static uint8 const arraySizes[2] = { 1, 4 };
        static DB2Meta instance(-1, 2, 0x7C55E5BB, types, arraySizes, -1);
        return &instance;
    }
};

struct PVPDifficultyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbbh";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x970B5E15, types, arraySizes, 3);
        return &instance;
    }
};

struct PVPItemMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ib";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xBD449801, types, arraySizes, -1);
        return &instance;
    }
};

struct PageTextMaterialMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x96663ABF, types, arraySizes, -1);
        return &instance;
    }
};

struct PaperDollItemFrameMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbi";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x66B0597E, types, arraySizes, -1);
        return &instance;
    }
};

struct ParagonReputationMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xD7712F98, types, arraySizes, 2);
        return &instance;
    }
};

struct ParticleColorMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 3, 3, 3 };
        static DB2Meta instance(-1, 3, 0x1576D1E1, types, arraySizes, -1);
        return &instance;
    }
};

struct PathMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbbbbbb";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0x5017579F, types, arraySizes, -1);
        return &instance;
    }
};

struct PathNodeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iihh";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(0, 4, 0x76615830, types, arraySizes, -1);
        return &instance;
    }
};

struct PathNodePropertyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhbii";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(3, 5, 0x92C03009, types, arraySizes, -1);
        return &instance;
    }
};

struct PathPropertyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihbi";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(3, 4, 0x3D29C266, types, arraySizes, -1);
        return &instance;
    }
};

struct PhaseMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "h";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x0043219C, types, arraySizes, -1);
        return &instance;
    }
};

struct PhaseShiftZoneSoundsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhhhhbbbbiiii";
        static uint8 const arraySizes[13] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 13, 0x85ACB830, types, arraySizes, -1);
        return &instance;
    }
};

struct PhaseXPhaseGroupMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hh";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x66517AF6, types, arraySizes, 1);
        return &instance;
    }
};

struct PlayerConditionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "lsibhhibbibbihbibbbbiiiiibihbbbiiiihibbbbbbbhiiihhbbbbbiihhhibhhhiiihiibhbbihiiii";
        static uint8 const arraySizes[81] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 4, 4, 3, 3, 4, 4, 4, 4, 4, 4, 2, 2, 4, 4, 4, 4, 4, 4, 4, 4, 4, 6, 2 };
        static DB2Meta instance(2, 81, 0x5B3DA113, types, arraySizes, -1);
        return &instance;
    }
};

struct PositionerMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fhbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xE830F1B1, types, arraySizes, -1);
        return &instance;
    }
};

struct PositionerStateMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fbiiiiii";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 8, 0x6C975DF4, types, arraySizes, -1);
        return &instance;
    }
};

struct PositionerStateEntryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffhhhhbbbbi";
        static uint8 const arraySizes[11] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 11, 0x667ED965, types, arraySizes, -1);
        return &instance;
    }
};

struct PowerDisplayMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbbbb";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0xFD152E5B, types, arraySizes, -1);
        return &instance;
    }
};

struct PowerTypeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssffhhhbbbbb";
        static uint8 const arraySizes[12] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 12, 0x0C3844E1, types, arraySizes, -1);
        return &instance;
    }
};

struct PrestigeLevelInfoMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sibb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xA7B2D559, types, arraySizes, -1);
        return &instance;
    }
};

struct PvpRewardMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x72F4C016, types, arraySizes, -1);
        return &instance;
    }
};

struct PvpScalingEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x52121A41, types, arraySizes, 1);
        return &instance;
    }
};

struct PvpScalingEffectTypeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x96663ABF, types, arraySizes, -1);
        return &instance;
    }
};

struct PvpTalentMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "siiiiiiiii";
        static uint8 const arraySizes[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 10, 0x6EB51740, types, arraySizes, -1);
        return &instance;
    }
};

struct PvpTalentUnlockMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x465C83BC, types, arraySizes, -1);
        return &instance;
    }
};

struct QuestFactionRewardMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "h";
        static uint8 const arraySizes[1] = { 10 };
        static DB2Meta instance(-1, 1, 0xB0E02541, types, arraySizes, -1);
        return &instance;
    }
};

struct QuestFeedbackEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihbbbb";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 6, 0x89D55A27, types, arraySizes, -1);
        return &instance;
    }
};

struct QuestInfoMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x4F45F445, types, arraySizes, -1);
        return &instance;
    }
};

struct QuestLineMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x8046B23F, types, arraySizes, -1);
        return &instance;
    }
};

struct QuestLineXQuestMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x8FA4A9C7, types, arraySizes, -1);
        return &instance;
    }
};

struct QuestMoneyRewardMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i";
        static uint8 const arraySizes[1] = { 10 };
        static DB2Meta instance(-1, 1, 0x86397302, types, arraySizes, -1);
        return &instance;
    }
};

struct QuestObjectiveMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "siibbbbh";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 8, 0xDD995180, types, arraySizes, 7);
        return &instance;
    }
};

struct QuestPOIBlobMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihhbbiii";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(0, 8, 0xEC15976E, types, arraySizes, 2);
        return &instance;
    }
};

struct QuestPOIPointMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihhi";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(0, 4, 0x8CF2B119, types, arraySizes, 3);
        return &instance;
    }
};

struct QuestPackageItemMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihbi";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xCF9401CF, types, arraySizes, -1);
        return &instance;
    }
};

struct QuestSortMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xAD7072C6, types, arraySizes, -1);
        return &instance;
    }
};

struct QuestV2Meta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "h";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x70495C9B, types, arraySizes, -1);
        return &instance;
    }
};

struct QuestV2CliTaskMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "lssihhhhhhbbbbbbbbbbiiii";
        static uint8 const arraySizes[24] = { 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(20, 24, 0x3F026A14, types, arraySizes, -1);
        return &instance;
    }
};

struct QuestXGroupActivityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ii";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x06CC45D3, types, arraySizes, -1);
        return &instance;
    }
};

struct QuestXPMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "h";
        static uint8 const arraySizes[1] = { 10 };
        static DB2Meta instance(-1, 1, 0xCB76B4C0, types, arraySizes, -1);
        return &instance;
    }
};

struct RandPropPointsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 5, 5, 5 };
        static DB2Meta instance(-1, 3, 0x4E2C0BCC, types, arraySizes, -1);
        return &instance;
    }
};

struct RelicSlotTierRequirementMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ibb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x129FCC09, types, arraySizes, -1);
        return &instance;
    }
};

struct RelicTalentMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hbiii";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x7A5963FD, types, arraySizes, -1);
        return &instance;
    }
};

struct ResearchBranchMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sihbii";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 6, 0x58A3876E, types, arraySizes, -1);
        return &instance;
    }
};

struct ResearchFieldMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbi";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(2, 3, 0x85868B9F, types, arraySizes, -1);
        return &instance;
    }
};

struct ResearchProjectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssihbbiii";
        static uint8 const arraySizes[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(6, 9, 0xB1CAB80B, types, arraySizes, -1);
        return &instance;
    }
};

struct ResearchSiteMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sihi";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x25F7DCC7, types, arraySizes, -1);
        return &instance;
    }
};

struct ResistancesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbi";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xA3EAE5AE, types, arraySizes, -1);
        return &instance;
    }
};

struct RewardPackMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ifbbii";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 6, 0xDB6CC0AB, types, arraySizes, -1);
        return &instance;
    }
};

struct RewardPackXCurrencyTypeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x217E6712, types, arraySizes, 2);
        return &instance;
    }
};

struct RewardPackXItemMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x74F6B9BD, types, arraySizes, 2);
        return &instance;
    }
};

struct RibbonQualityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fffbi";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0xC75DAEA8, types, arraySizes, -1);
        return &instance;
    }
};

struct RulesetItemUpgradeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ih";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xFB641AE0, types, arraySizes, -1);
        return &instance;
    }
};

struct SDReplacementModelMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xE1F906C2, types, arraySizes, -1);
        return &instance;
    }
};

struct SandboxScalingMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x5200B7F5, types, arraySizes, -1);
        return &instance;
    }
};

struct ScalingStatDistributionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xDED48286, types, arraySizes, -1);
        return &instance;
    }
};

struct ScenarioMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xD052232A, types, arraySizes, -1);
        return &instance;
    }
};

struct ScenarioEventEntryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x02E80455, types, arraySizes, -1);
        return &instance;
    }
};

struct ScenarioStepMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sshhhbbii";
        static uint8 const arraySizes[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 9, 0x201B0EFC, types, arraySizes, 2);
        return &instance;
    }
};

struct SceneScriptMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hh";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xC694B81E, types, arraySizes, -1);
        return &instance;
    }
};

struct SceneScriptGlobalTextMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ss";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xB9F8FDF1, types, arraySizes, -1);
        return &instance;
    }
};

struct SceneScriptPackageMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x96663ABF, types, arraySizes, -1);
        return &instance;
    }
};

struct SceneScriptPackageMemberMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhhb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x787A715F, types, arraySizes, 0);
        return &instance;
    }
};

struct SceneScriptTextMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ss";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xB9F8FDF1, types, arraySizes, -1);
        return &instance;
    }
};

struct ScheduledIntervalMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiii";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x5DD2FF46, types, arraySizes, -1);
        return &instance;
    }
};

struct ScheduledWorldStateMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiiiiii";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 8, 0xFCB13A6A, types, arraySizes, 0);
        return &instance;
    }
};

struct ScheduledWorldStateGroupMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiii";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x21F6EE03, types, arraySizes, -1);
        return &instance;
    }
};

struct ScheduledWorldStateXUniqCatMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(0, 3, 0x7EFF57FD, types, arraySizes, 2);
        return &instance;
    }
};

struct ScreenEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sihhhhbbbiii";
        static uint8 const arraySizes[12] = { 1, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 12, 0x4D5B91C5, types, arraySizes, -1);
        return &instance;
    }
};

struct ScreenLocationMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x96663ABF, types, arraySizes, -1);
        return &instance;
    }
};

struct SeamlessSiteMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xBFE7B9D3, types, arraySizes, 0);
        return &instance;
    }
};

struct ServerMessagesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x1C7A1347, types, arraySizes, -1);
        return &instance;
    }
};

struct ShadowyEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iifffffffbbii";
        static uint8 const arraySizes[13] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 13, 0xE909BB18, types, arraySizes, -1);
        return &instance;
    }
};

struct SkillLineMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssshbbii";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 8, 0x3F7E88AF, types, arraySizes, -1);
        return &instance;
    }
};

struct SkillLineAbilityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "liiihhhhhbihbb";
        static uint8 const arraySizes[14] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(1, 14, 0x97B5A653, types, arraySizes, 4);
        return &instance;
    }
};

struct SkillRaceClassInfoMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "lhhhbbi";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0x9752C2CE, types, arraySizes, 1);
        return &instance;
    }
};

struct SoundAmbienceMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "biii";
        static uint8 const arraySizes[4] = { 1, 1, 1, 2 };
        static DB2Meta instance(-1, 4, 0xB073D4B5, types, arraySizes, -1);
        return &instance;
    }
};

struct SoundAmbienceFlavorMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iih";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x2C58D929, types, arraySizes, 2);
        return &instance;
    }
};

struct SoundBusMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fbbbbbih";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(6, 8, 0xB2ACDE2A, types, arraySizes, 7);
        return &instance;
    }
};

struct SoundBusOverrideMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ifbbbii";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(0, 7, 0x6D887F48, types, arraySizes, 5);
        return &instance;
    }
};

struct SoundEmitterPillPointsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fh";
        static uint8 const arraySizes[2] = { 3, 1 };
        static DB2Meta instance(-1, 2, 0x41FCF15B, types, arraySizes, 1);
        return &instance;
    }
};

struct SoundEmittersMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sffhhbbbiiih";
        static uint8 const arraySizes[12] = { 1, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(8, 12, 0x55A3B17E, types, arraySizes, 11);
        return &instance;
    }
};

struct SoundEnvelopeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iihhhbi";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0x5B78031C, types, arraySizes, 0);
        return &instance;
    }
};

struct SoundFilterMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x96663ABF, types, arraySizes, -1);
        return &instance;
    }
};

struct SoundFilterElemMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fbb";
        static uint8 const arraySizes[3] = { 9, 1, 1 };
        static DB2Meta instance(-1, 3, 0xE17AC589, types, arraySizes, 2);
        return &instance;
    }
};

struct SoundKitMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ifffhhbbbfffffhb";
        static uint8 const arraySizes[16] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(0, 16, 0x0E9CB7AE, types, arraySizes, -1);
        return &instance;
    }
};

struct SoundKitAdvancedMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ifffffiifbiiiiiiiiiibffffbhffiiibbiiiiii";
        static uint8 const arraySizes[40] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(0, 40, 0x73F6F023, types, arraySizes, -1);
        return &instance;
    }
};

struct SoundKitChildMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ii";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x2827A3B5, types, arraySizes, 0);
        return &instance;
    }
};

struct SoundKitEntryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iibf";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x6ED6E26F, types, arraySizes, 0);
        return &instance;
    }
};

struct SoundKitFallbackMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ii";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xB1A5106F, types, arraySizes, -1);
        return &instance;
    }
};

struct SoundKitNameMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x96663ABF, types, arraySizes, -1);
        return &instance;
    }
};

struct SoundOverrideMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhhb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xFB7643F6, types, arraySizes, -1);
        return &instance;
    }
};

struct SoundProviderPreferencesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sfffffffffffffffhhhhhbb";
        static uint8 const arraySizes[23] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 23, 0x85F218A4, types, arraySizes, -1);
        return &instance;
    }
};

struct SourceInfoMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbbi";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x7C214135, types, arraySizes, 3);
        return &instance;
    }
};

struct SpamMessagesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x0D4BA7E7, types, arraySizes, -1);
        return &instance;
    }
};

struct SpecializationSpellsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "siihbi";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(5, 6, 0xAE3436F3, types, arraySizes, 3);
        return &instance;
    }
};

struct SpellMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssss";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x2273DFFF, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellActionBarPrefMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ih";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x1EF80B2B, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellActivationOverlayMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiifibbi";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 4, 1, 1, 1 };
        static DB2Meta instance(-1, 8, 0x23568FC7, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellAuraOptionsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiihhbbi";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 8, 0xE05BE94F, types, arraySizes, 7);
        return &instance;
    }
};

struct SpellAuraRestrictionsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiibbbbbi";
        static uint8 const arraySizes[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 10, 0x7CDF3311, types, arraySizes, 9);
        return &instance;
    }
};

struct SpellAuraVisXChrSpecMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hh";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xA65B6A4A, types, arraySizes, 1);
        return &instance;
    }
};

struct SpellAuraVisibilityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbii";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(2, 4, 0xA549F79C, types, arraySizes, 3);
        return &instance;
    }
};

struct SpellCastTimesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iih";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x4129C6A4, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellCastingRequirementsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihhhbbb";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0xD8B56E5D, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellCategoriesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhhbbbbbi";
        static uint8 const arraySizes[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 9, 0x14E916CC, types, arraySizes, 8);
        return &instance;
    }
};

struct SpellCategoryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sibbbi";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 6, 0xEA60E384, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellChainEffectsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fffiiffffffffffffffffffffffffffffffffffiffffhhhhbbbbbbbbbbii";
        static uint8 const arraySizes[60] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 11, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3 };
        static DB2Meta instance(-1, 60, 0x4E8FF369, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellClassOptionsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iibi";
        static uint8 const arraySizes[4] = { 1, 4, 1, 1 };
        static DB2Meta instance(-1, 4, 0x80FBD67A, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellCooldownsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiibi";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0xCA8D8B3C, types, arraySizes, 4);
        return &instance;
    }
};

struct SpellDescriptionVariablesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xA8EDE75B, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellDispelTypeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xE9DDA799, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellDurationMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x0D6C9082, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiiiififfiiiiffififfffffiiiii";
        static uint8 const arraySizes[30] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 2, 2, 2, 1 };
        static DB2Meta instance(0, 30, 0x3244098B, types, arraySizes, 29);
        return &instance;
    }
};

struct SpellEffectEmissionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffhb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xC6E61A9B, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellEquippedItemsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiib";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xCE628176, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellFlyoutMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "lssbii";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 6, 0x437671BD, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellFlyoutItemMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ibb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xF86ADE09, types, arraySizes, 2);
        return &instance;
    }
};

struct SpellFocusObjectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x96663ABF, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellInterruptsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bhiii";
        static uint8 const arraySizes[5] = { 1, 1, 2, 2, 1 };
        static DB2Meta instance(-1, 5, 0x2FA8EA94, types, arraySizes, 4);
        return &instance;
    }
};

struct SpellItemEnchantmentMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sifiihhhhhhbbbbbbbi";
        static uint8 const arraySizes[19] = { 1, 3, 3, 1, 1, 3, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 19, 0x80DEA734, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellItemEnchantmentConditionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ibbbbb";
        static uint8 const arraySizes[6] = { 5, 5, 5, 5, 5, 5 };
        static DB2Meta instance(-1, 6, 0xB9C16961, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellKeyboundOverrideMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sib";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x6ECA16FC, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellLabelMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ii";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x68E44736, types, arraySizes, 1);
        return &instance;
    }
};

struct SpellLearnSpellMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x153EBA26, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellLevelsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhhbbi";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 6, 0x9E7D1CCD, types, arraySizes, 5);
        return &instance;
    }
};

struct SpellMechanicMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xF2075D8C, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellMiscMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhhbififbii";
        static uint8 const arraySizes[11] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 14, 1 };
        static DB2Meta instance(-1, 11, 0xCDC114D5, types, arraySizes, 10);
        return &instance;
    }
};

struct SpellMissileMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ifffffffffffffb";
        static uint8 const arraySizes[15] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 15, 0x1D35645E, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellMissileMotionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x6B78A45B, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellPowerMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iffifbbiiiiiii";
        static uint8 const arraySizes[14] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(7, 14, 0x8E5E46EC, types, arraySizes, 13);
        return &instance;
    }
};

struct SpellPowerDifficultyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbi";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(2, 3, 0x74714FF7, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellProceduralEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fbi";
        static uint8 const arraySizes[3] = { 4, 1, 1 };
        static DB2Meta instance(2, 3, 0x3E47F4EF, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellProcsPerMinuteMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x4BC1931B, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellProcsPerMinuteModMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fhbh";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x2503C18B, types, arraySizes, 3);
        return &instance;
    }
};

struct SpellRadiusMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffff";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xC12E5C90, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellRangeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssffb";
        static uint8 const arraySizes[5] = { 1, 1, 2, 2, 1 };
        static DB2Meta instance(-1, 5, 0xDE2E3F8E, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellReagentsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iih";
        static uint8 const arraySizes[3] = { 1, 8, 8 };
        static DB2Meta instance(-1, 3, 0x0463C688, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellReagentsCurrencyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihh";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x90A5E5D2, types, arraySizes, 0);
        return &instance;
    }
};

struct SpellScalingMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihiii";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0xF67A5719, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellShapeshiftMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiib";
        static uint8 const arraySizes[4] = { 1, 2, 2, 1 };
        static DB2Meta instance(-1, 4, 0xA461C24D, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellShapeshiftFormMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sfihhbbiii";
        static uint8 const arraySizes[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 4, 8 };
        static DB2Meta instance(-1, 10, 0x130819AF, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellSpecialUnitEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hi";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x76989615, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellTargetRestrictionsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffihbbii";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 8, 0x7B330026, types, arraySizes, 7);
        return &instance;
    }
};

struct SpellTotemsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iih";
        static uint8 const arraySizes[3] = { 1, 2, 2 };
        static DB2Meta instance(-1, 3, 0xEC0C4866, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellVisualMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffihbbiiiihiii";
        static uint8 const arraySizes[14] = { 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 14, 0x1C1301D2, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellVisualAnimMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhh";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x0ABD7A19, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellVisualColorEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fifhhhhhbbi";
        static uint8 const arraySizes[11] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 11, 0x7E5B2E66, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellVisualEffectNameMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffffffiiibiii";
        static uint8 const arraySizes[13] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 13, 0xB930A934, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellVisualEventMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiiiiiii";
        static uint8 const arraySizes[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 9, 0xAE75BC3C, types, arraySizes, 8);
        return &instance;
    }
};

struct SpellVisualKitMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ifihh";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0xDC04F488, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellVisualKitAreaModelMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ifffhb";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 6, 0xBE76E593, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellVisualKitEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xB78084B7, types, arraySizes, 2);
        return &instance;
    }
};

struct SpellVisualKitModelAttachMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffihbbhffffffffhhhhifi";
        static uint8 const arraySizes[22] = { 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(2, 22, 0xBCE18649, types, arraySizes, 21);
        return &instance;
    }
};

struct SpellVisualMissileMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiffhhhhhbbiiih";
        static uint8 const arraySizes[16] = { 1, 1, 1, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(12, 16, 0x00BA67A5, types, arraySizes, 15);
        return &instance;
    }
};

struct SpellXDescriptionVariablesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ii";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xB08E6876, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellXSpellVisualMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iifhhhhiibbbi";
        static uint8 const arraySizes[13] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(1, 13, 0x4F4B8A2A, types, arraySizes, 12);
        return &instance;
    }
};

struct StartupFilesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x51FEBBB5, types, arraySizes, -1);
        return &instance;
    }
};

struct Startup_StringsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ss";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xF8CDDEE7, types, arraySizes, -1);
        return &instance;
    }
};

struct StationeryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bii";
        static uint8 const arraySizes[3] = { 1, 1, 2 };
        static DB2Meta instance(-1, 3, 0x20F6BABD, types, arraySizes, -1);
        return &instance;
    }
};

struct SummonPropertiesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiii";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0xFB8338FC, types, arraySizes, -1);
        return &instance;
    }
};

struct TactKeyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "b";
        static uint8 const arraySizes[1] = { 16 };
        static DB2Meta instance(-1, 1, 0xF0F98B62, types, arraySizes, -1);
        return &instance;
    }
};

struct TactKeyLookupMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "b";
        static uint8 const arraySizes[1] = { 8 };
        static DB2Meta instance(-1, 1, 0x3C1AC92A, types, arraySizes, -1);
        return &instance;
    }
};

struct TalentMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "siihbbbbb";
        static uint8 const arraySizes[9] = { 1, 1, 1, 1, 1, 1, 1, 2, 1 };
        static DB2Meta instance(-1, 9, 0xE8850B48, types, arraySizes, -1);
        return &instance;
    }
};

struct TaxiNodesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sfifffhhhbii";
        static uint8 const arraySizes[12] = { 1, 3, 2, 2, 1, 2, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 12, 0xB46C6A8B, types, arraySizes, -1);
        return &instance;
    }
};

struct TaxiPathMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhii";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(2, 4, 0xF44E2BF5, types, arraySizes, 0);
        return &instance;
    }
};

struct TaxiPathNodeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fhhbibihh";
        static uint8 const arraySizes[9] = { 3, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(4, 9, 0xD38E8C01, types, arraySizes, 1);
        return &instance;
    }
};

struct TerrainMaterialMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x19D9496F, types, arraySizes, -1);
        return &instance;
    }
};

struct TerrainTypeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shhbb";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x4FE20345, types, arraySizes, -1);
        return &instance;
    }
};

struct TerrainTypeSoundsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xE4923C1F, types, arraySizes, -1);
        return &instance;
    }
};

struct TextureBlendSetMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ifffffbbbb";
        static uint8 const arraySizes[10] = { 3, 3, 3, 3, 3, 4, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 10, 0xA2323E0C, types, arraySizes, -1);
        return &instance;
    }
};

struct TextureFileDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iib";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(0, 3, 0xE0790D00, types, arraySizes, 1);
        return &instance;
    }
};

struct TotemCategoryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sib";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x20B9177A, types, arraySizes, -1);
        return &instance;
    }
};

struct ToyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sibbi";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(4, 5, 0x5409C5EA, types, arraySizes, -1);
        return &instance;
    }
};

struct TradeSkillCategoryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shhhb";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x5D3ADD4D, types, arraySizes, -1);
        return &instance;
    }
};

struct TradeSkillItemMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xFDE283DA, types, arraySizes, -1);
        return &instance;
    }
};

struct TransformMatrixMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fffff";
        static uint8 const arraySizes[5] = { 3, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0xB6A2C431, types, arraySizes, -1);
        return &instance;
    }
};

struct TransmogHolidayMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ii";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(0, 2, 0xB420EB18, types, arraySizes, -1);
        return &instance;
    }
};

struct TransmogSetMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shhbiiiiii";
        static uint8 const arraySizes[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(4, 10, 0xBEDFD7D1, types, arraySizes, 1);
        return &instance;
    }
};

struct TransmogSetGroupMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "si";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(1, 2, 0xCD072FE5, types, arraySizes, -1);
        return &instance;
    }
};

struct TransmogSetItemMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiii";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(0, 4, 0x0E96B3A2, types, arraySizes, 1);
        return &instance;
    }
};

struct TransportAnimationMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ifbi";
        static uint8 const arraySizes[4] = { 1, 3, 1, 1 };
        static DB2Meta instance(-1, 4, 0x099987ED, types, arraySizes, 3);
        return &instance;
    }
};

struct TransportPhysicsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffffffffff";
        static uint8 const arraySizes[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 10, 0x2C1FB208, types, arraySizes, -1);
        return &instance;
    }
};

struct TransportRotationMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ifi";
        static uint8 const arraySizes[3] = { 1, 4, 1 };
        static DB2Meta instance(-1, 3, 0x72035AA9, types, arraySizes, 2);
        return &instance;
    }
};

struct TrophyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shbi";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xE16151C5, types, arraySizes, -1);
        return &instance;
    }
};

struct UIExpansionDisplayInfoMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x73DFDEC5, types, arraySizes, -1);
        return &instance;
    }
};

struct UIExpansionDisplayInfoIconMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x331022F2, types, arraySizes, -1);
        return &instance;
    }
};

struct UiCamFbackTransmogChrRaceMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hbbbb";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x9FB4CC78, types, arraySizes, -1);
        return &instance;
    }
};

struct UiCamFbackTransmogWeaponMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hbbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x020890B7, types, arraySizes, -1);
        return &instance;
    }
};

struct UiCameraMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sfffhbbbi";
        static uint8 const arraySizes[9] = { 1, 3, 3, 3, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 9, 0xCA6C98D4, types, arraySizes, -1);
        return &instance;
    }
};

struct UiCameraTypeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x644732AE, types, arraySizes, -1);
        return &instance;
    }
};

struct UiMapPOIMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ifiihhi";
        static uint8 const arraySizes[7] = { 1, 3, 1, 1, 1, 1, 1 };
        static DB2Meta instance(6, 7, 0x559E1F11, types, arraySizes, -1);
        return &instance;
    }
};

struct UiModelSceneMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xA7D62B8A, types, arraySizes, -1);
        return &instance;
    }
};

struct UiModelSceneActorMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sfffffbiii";
        static uint8 const arraySizes[10] = { 1, 3, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(7, 10, 0x679AC95F, types, arraySizes, 9);
        return &instance;
    }
};

struct UiModelSceneActorDisplayMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fffii";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x6137F4BE, types, arraySizes, -1);
        return &instance;
    }
};

struct UiModelSceneCameraMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sfffffffffffbbii";
        static uint8 const arraySizes[16] = { 1, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(14, 16, 0xC58AA5EC, types, arraySizes, 15);
        return &instance;
    }
};

struct UiTextureAtlasMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihh";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x9879592A, types, arraySizes, -1);
        return &instance;
    }
};

struct UiTextureAtlasMemberMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sihhhhhb";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(1, 8, 0x81E2055F, types, arraySizes, -1);
        return &instance;
    }
};

struct UiTextureKitMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x2C7E0372, types, arraySizes, -1);
        return &instance;
    }
};

struct UnitBloodMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiiii";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 6, 0x4689A9A0, types, arraySizes, -1);
        return &instance;
    }
};

struct UnitBloodLevelsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "b";
        static uint8 const arraySizes[1] = { 3 };
        static DB2Meta instance(-1, 1, 0x31A6BD58, types, arraySizes, -1);
        return &instance;
    }
};

struct UnitConditionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ibbb";
        static uint8 const arraySizes[4] = { 8, 1, 8, 8 };
        static DB2Meta instance(-1, 4, 0x62802D9C, types, arraySizes, -1);
        return &instance;
    }
};

struct UnitPowerBarMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssssffiiffhhbbii";
        static uint8 const arraySizes[16] = { 1, 1, 1, 1, 1, 1, 6, 6, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 16, 0x626C94CD, types, arraySizes, -1);
        return &instance;
    }
};

struct UnitTestMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssiii";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(2, 5, 0x63B4527B, types, arraySizes, -1);
        return &instance;
    }
};

struct VehicleMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ifffffffffffhhhbbi";
        static uint8 const arraySizes[18] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 8, 1, 3, 1, 1, 1 };
        static DB2Meta instance(-1, 18, 0x1606C582, types, arraySizes, -1);
        return &instance;
    }
};

struct VehicleSeatMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiffffffffffffffffffffffffffffffihhhhhhhhhhhhhhhhhhhbbbbbbii";
        static uint8 const arraySizes[61] = { 1, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 61, 0x242E0ECD, types, arraySizes, -1);
        return &instance;
    }
};

struct VehicleUIIndSeatMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffbh";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x5F688502, types, arraySizes, 3);
        return &instance;
    }
};

struct VehicleUIIndicatorMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x68486100, types, arraySizes, -1);
        return &instance;
    }
};

struct VignetteMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sffiiii";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0x52E3B381, types, arraySizes, -1);
        return &instance;
    }
};

struct VirtualAttachmentMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sh";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xEC767C57, types, arraySizes, -1);
        return &instance;
    }
};

struct VirtualAttachmentCustomizationMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihh";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xC354C931, types, arraySizes, -1);
        return &instance;
    }
};

struct VocalUISoundsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbbi";
        static uint8 const arraySizes[4] = { 1, 1, 1, 2 };
        static DB2Meta instance(-1, 4, 0xED48CFA9, types, arraySizes, -1);
        return &instance;
    }
};

struct WMOAreaTableMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sihhhhhhbbbbiih";
        static uint8 const arraySizes[15] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(12, 15, 0x4616C893, types, arraySizes, 14);
        return &instance;
    }
};

struct WMOMinimapTextureMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihbbh";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x8F4AE3C0, types, arraySizes, 4);
        return &instance;
    }
};

struct WbAccessControlListMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shbbb";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0xBE044710, types, arraySizes, -1);
        return &instance;
    }
};

struct WbCertWhitelistMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x01D13030, types, arraySizes, -1);
        return &instance;
    }
};

struct WeaponImpactSoundsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbbiiii";
        static uint8 const arraySizes[7] = { 1, 1, 1, 11, 11, 11, 11 };
        static DB2Meta instance(-1, 7, 0x774C043A, types, arraySizes, -1);
        return &instance;
    }
};

struct WeaponSwingSounds2Meta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbi";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xD45347C3, types, arraySizes, -1);
        return &instance;
    }
};

struct WeaponTrailMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ifffiffff";
        static uint8 const arraySizes[9] = { 1, 1, 1, 1, 3, 3, 3, 3, 3 };
        static DB2Meta instance(-1, 9, 0x49754C60, types, arraySizes, -1);
        return &instance;
    }
};

struct WeaponTrailModelDefMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihh";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x7DE7C508, types, arraySizes, 2);
        return &instance;
    }
};

struct WeaponTrailParamMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fffffbbbbh";
        static uint8 const arraySizes[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 10, 0x9B0F7200, types, arraySizes, 9);
        return &instance;
    }
};

struct WeatherMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffffffffhbbbii";
        static uint8 const arraySizes[14] = { 2, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 14, 0x7C160B07, types, arraySizes, -1);
        return &instance;
    }
};

struct WindSettingsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fffffffffb";
        static uint8 const arraySizes[10] = { 1, 3, 1, 1, 3, 1, 3, 1, 1, 1 };
        static DB2Meta instance(-1, 10, 0x5308550C, types, arraySizes, -1);
        return &instance;
    }
};

struct WorldBossLockoutMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sh";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x4D7103A0, types, arraySizes, -1);
        return &instance;
    }
};

struct WorldChunkSoundsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hbbbbb";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 6, 0xD06AA126, types, arraySizes, -1);
        return &instance;
    }
};

struct WorldEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihbbii";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 6, 0x2E9B9BFD, types, arraySizes, -1);
        return &instance;
    }
};

struct WorldElapsedTimerMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x6C026FDE, types, arraySizes, -1);
        return &instance;
    }
};

struct WorldMapAreaMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sffffihhhhhbbbbii";
        static uint8 const arraySizes[17] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(15, 17, 0xC7E90019, types, arraySizes, -1);
        return &instance;
    }
};

struct WorldMapContinentMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffffhhbbbbb";
        static uint8 const arraySizes[11] = { 2, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 11, 0x8F75E077, types, arraySizes, -1);
        return &instance;
    }
};

struct WorldMapOverlayMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sihhiiiiiiiiii";
        static uint8 const arraySizes[14] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4 };
        static DB2Meta instance(1, 14, 0xDC4B6AF3, types, arraySizes, 4);
        return &instance;
    }
};

struct WorldMapTransformsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fffhhhhhbi";
        static uint8 const arraySizes[10] = { 6, 2, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 10, 0x99FB4B71, types, arraySizes, 3);
        return &instance;
    }
};

struct WorldSafeLocsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sffh";
        static uint8 const arraySizes[4] = { 1, 3, 1, 1 };
        static DB2Meta instance(-1, 4, 0x605EA8A6, types, arraySizes, 3);
        return &instance;
    }
};

struct WorldStateExpressionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xA69C9812, types, arraySizes, -1);
        return &instance;
    }
};

struct WorldStateUIMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssssshhhhhhbbbiii";
        static uint8 const arraySizes[17] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(14, 17, 0x70808977, types, arraySizes, 5);
        return &instance;
    }
};

struct WorldStateZoneSoundsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihhhhhhb";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 8, 0xB9572D3D, types, arraySizes, -1);
        return &instance;
    }
};

struct World_PVP_AreaMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhhhhbb";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0x6FBBF76B, types, arraySizes, -1);
        return &instance;
    }
};

struct ZoneIntroMusicTableMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shbi";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x1F8417ED, types, arraySizes, -1);
        return &instance;
    }
};

struct ZoneLightMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shh";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x3C11F38B, types, arraySizes, -1);
        return &instance;
    }
};

struct ZoneLightPointMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fbh";
        static uint8 const arraySizes[3] = { 2, 1, 1 };
        static DB2Meta instance(-1, 3, 0xEF93DC50, types, arraySizes, 2);
        return &instance;
    }
};

struct ZoneMusicMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "siii";
        static uint8 const arraySizes[4] = { 1, 2, 2, 2 };
        static DB2Meta instance(-1, 4, 0x9E2B332D, types, arraySizes, -1);
        return &instance;
    }
};

struct ZoneStoryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iibi";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xEE16D6F3, types, arraySizes, 3);
        return &instance;
    }
};

#endif // DB2Metadata_h__
