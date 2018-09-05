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
        static char const* types = "sssihbhhbbihiih";
        static uint8 const arraySizes[15] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 15, 0x13CB7BEE, types, arraySizes, -1);
        return &instance;
    }
};

struct Achievement_CategoryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sihb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x0B008A91, types, arraySizes, -1);
        return &instance;
    }
};

struct AdventureJournalMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sssssbibbihhhbbiihbhib";
        static uint8 const arraySizes[22] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 22, 0x9D620FC8, types, arraySizes, -1);
        return &instance;
    }
};

struct AdventureMapPOIMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssfbiiiiiiii";
        static uint8 const arraySizes[12] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 12, 0x4AABC870, types, arraySizes, -1);
        return &instance;
    }
};

struct AlliedRaceMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiiiiii";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 8, 0xE89FA2D2, types, arraySizes, -1);
        return &instance;
    }
};

struct AlliedRaceRacialAbilityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssib?";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x96902165, types, arraySizes, -1);
        return &instance;
    }
};

struct AnimKitMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihh";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x0C4BCDEC, types, arraySizes, -1);
        return &instance;
    }
};

struct AnimKitBoneSetMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbbbb";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x1C432613, types, arraySizes, -1);
        return &instance;
    }
};

struct AnimKitBoneSetAliasMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xB307E8FC, types, arraySizes, -1);
        return &instance;
    }
};

struct AnimKitConfigMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x972D46F8, types, arraySizes, -1);
        return &instance;
    }
};

struct AnimKitConfigBoneSetMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bh?";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x48518303, types, arraySizes, -1);
        return &instance;
    }
};

struct AnimKitPriorityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "b";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x27ED596B, types, arraySizes, -1);
        return &instance;
    }
};

struct AnimKitReplacementMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihhh?";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0xB0BBA55F, types, arraySizes, -1);
        return &instance;
    }
};

struct AnimKitSegmentMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hbhihbbibiifhbibhh";
        static uint8 const arraySizes[18] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 18, 0xEBF796F5, types, arraySizes, -1);
        return &instance;
    }
};

struct AnimReplacementMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihhh?";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x5D91ABFD, types, arraySizes, -1);
        return &instance;
    }
};

struct AnimReplacementSetMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "b";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x15AFC3D6, types, arraySizes, -1);
        return &instance;
    }
};

struct AnimationDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hbii";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xFB408E92, types, arraySizes, -1);
        return &instance;
    }
};

struct AoiBoxMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fiii?";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x173154C8, types, arraySizes, -1);
        return &instance;
    }
};

struct AreaConditionalDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "siii?";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0xBE8C656A, types, arraySizes, -1);
        return &instance;
    }
};

struct AreaFarClipOverrideMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iffi";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xD7028AD6, types, arraySizes, -1);
        return &instance;
    }
};

struct AreaGroupMemberMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "h?";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x27C84A16, types, arraySizes, -1);
        return &instance;
    }
};

struct AreaPOIMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssifiiiiiiihhhhbb";
        static uint8 const arraySizes[17] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 17, 0x34D56581, types, arraySizes, -1);
        return &instance;
    }
};

struct AreaPOIStateMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbbi?";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0xEB8CA12C, types, arraySizes, -1);
        return &instance;
    }
};

struct AreaTableMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sshhhbbhhhhbhibfbhbbbih";
        static uint8 const arraySizes[23] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 23, 0x22229BE7, types, arraySizes, -1);
        return &instance;
    }
};

struct AreaTriggerMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fihbhhfffffbhhb";
        static uint8 const arraySizes[15] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 15, 0x61A4F966, types, arraySizes, -1);
        return &instance;
    }
};

struct AreaTriggerActionSetMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "h";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xBE34F649, types, arraySizes, -1);
        return &instance;
    }
};

struct AreaTriggerBoxMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "f";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x14918F12, types, arraySizes, -1);
        return &instance;
    }
};

struct AreaTriggerCreatePropertiesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bh";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xAAE6E300, types, arraySizes, -1);
        return &instance;
    }
};

struct AreaTriggerCylinderMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fff";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x867834A9, types, arraySizes, -1);
        return &instance;
    }
};

struct AreaTriggerSphereMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "f";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xF1D2220B, types, arraySizes, -1);
        return &instance;
    }
};

struct ArmorLocationMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fffff";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x1C0BBC02, types, arraySizes, -1);
        return &instance;
    }
};

struct ArtifactMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sihiiihbbii";
        static uint8 const arraySizes[11] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 11, 0x780D61EA, types, arraySizes, -1);
        return &instance;
    }
};

struct ArtifactAppearanceMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sihbibiffbiiibh";
        static uint8 const arraySizes[15] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 15, 0x330F75C9, types, arraySizes, -1);
        return &instance;
    }
};

struct ArtifactAppearanceSetMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssibhhbb?";
        static uint8 const arraySizes[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 9, 0xBB4DB4D3, types, arraySizes, -1);
        return &instance;
    }
};

struct ArtifactCategoryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hh";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x484A6D55, types, arraySizes, -1);
        return &instance;
    }
};

struct ArtifactItemToTransmogMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ii?";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xD54CBBE1, types, arraySizes, -1);
        return &instance;
    }
};

struct ArtifactPowerMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fibbibb";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0x1F7637C8, types, arraySizes, -1);
        return &instance;
    }
};

struct ArtifactPowerLinkMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hh";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xBB7E3584, types, arraySizes, -1);
        return &instance;
    }
};

struct ArtifactPowerPickerMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x253242BA, types, arraySizes, -1);
        return &instance;
    }
};

struct ArtifactPowerRankMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bihf?";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x7DC78F1E, types, arraySizes, -1);
        return &instance;
    }
};

struct ArtifactQuestXPMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x7E00C5B6, types, arraySizes, -1);
        return &instance;
    }
};

struct ArtifactTierMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiii";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0xA47F6D9D, types, arraySizes, -1);
        return &instance;
    }
};

struct ArtifactUnlockMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ibhi?";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x40C54B9F, types, arraySizes, -1);
        return &instance;
    }
};

struct AuctionHouseMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x61E641BA, types, arraySizes, -1);
        return &instance;
    }
};

struct AzeriteEmpoweredItemMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x4078BECD, types, arraySizes, -1);
        return &instance;
    }
};

struct AzeriteItemMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xDAC6A93C, types, arraySizes, -1);
        return &instance;
    }
};

struct AzeriteItemMilestonePowerMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bh";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x7C4DC43D, types, arraySizes, -1);
        return &instance;
    }
};

struct AzeritePowerMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiii";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xE7FE46AC, types, arraySizes, -1);
        return &instance;
    }
};

struct AzeritePowerSetMemberMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hbbb?";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0xDB24A281, types, arraySizes, -1);
        return &instance;
    }
};

struct AzeriteTierUnlockMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbb?";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x2B04F059, types, arraySizes, -1);
        return &instance;
    }
};

struct BankBagSlotPricesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x897A4D1E, types, arraySizes, -1);
        return &instance;
    }
};

struct BannedAddOnsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xF4525F59, types, arraySizes, -1);
        return &instance;
    }
};

struct BarberShopStyleMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssibfbbb";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 8, 0x2DD3952C, types, arraySizes, -1);
        return &instance;
    }
};

struct BattlePetAbilityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssibihb";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0x4C3AF583, types, arraySizes, -1);
        return &instance;
    }
};

struct BattlePetAbilityEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihbhhhh";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0xC850B549, types, arraySizes, -1);
        return &instance;
    }
};

struct BattlePetAbilityStateMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bi?";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x73DDAA6A, types, arraySizes, -1);
        return &instance;
    }
};

struct BattlePetAbilityTurnMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihbbbh";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 6, 0xF2218887, types, arraySizes, -1);
        return &instance;
    }
};

struct BattlePetBreedQualityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x6CD46EB5, types, arraySizes, -1);
        return &instance;
    }
};

struct BattlePetBreedStateMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bh?";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xC1A59CCF, types, arraySizes, -1);
        return &instance;
    }
};

struct BattlePetDisplayOverrideMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiib";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x6F9CB092, types, arraySizes, -1);
        return &instance;
    }
};

struct BattlePetEffectPropertiesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xA2D4ADF5, types, arraySizes, -1);
        return &instance;
    }
};

struct BattlePetNPCTeamMemberMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x9F2C8370, types, arraySizes, -1);
        return &instance;
    }
};

struct BattlePetSpeciesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssiiiibhbii";
        static uint8 const arraySizes[11] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 11, 0x78A6B928, types, arraySizes, -1);
        return &instance;
    }
};

struct BattlePetSpeciesStateMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bi?";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x99EBACAA, types, arraySizes, -1);
        return &instance;
    }
};

struct BattlePetSpeciesXAbilityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hbb?";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x630BA932, types, arraySizes, -1);
        return &instance;
    }
};

struct BattlePetStateMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shh";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xF9579FAC, types, arraySizes, -1);
        return &instance;
    }
};

struct BattlePetVisualMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sihhbbh";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0x284AF258, types, arraySizes, -1);
        return &instance;
    }
};

struct BattlemasterListMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssssbbbbbbbbhbihh";
        static uint8 const arraySizes[17] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 17, 0x167284E8, types, arraySizes, -1);
        return &instance;
    }
};

struct BeamEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iffiiiiiii";
        static uint8 const arraySizes[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 10, 0x0E55B843, types, arraySizes, -1);
        return &instance;
    }
};

struct BoneWindModifierModelMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ii";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x77B007CA, types, arraySizes, -1);
        return &instance;
    }
};

struct BoneWindModifiersMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ff";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xC6F446CE, types, arraySizes, -1);
        return &instance;
    }
};

struct BonusRollMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiii";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xF7A194FA, types, arraySizes, -1);
        return &instance;
    }
};

struct BountyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhii?";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x797CCAA0, types, arraySizes, -1);
        return &instance;
    }
};

struct BountySetMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ih";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xB67E3F83, types, arraySizes, -1);
        return &instance;
    }
};

struct BroadcastTextMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssibihbiihh";
        static uint8 const arraySizes[11] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 11, 0x6318993B, types, arraySizes, -1);
        return &instance;
    }
};

struct CameraEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "b";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xAB0FD78E, types, arraySizes, -1);
        return &instance;
    }
};

struct CameraEffectEntryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bhffffffffbbbbb?";
        static uint8 const arraySizes[16] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 16, 0xED27DC2F, types, arraySizes, -1);
        return &instance;
    }
};

struct CameraModeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffbifffbbbb";
        static uint8 const arraySizes[11] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 11, 0xEE5489F4, types, arraySizes, -1);
        return &instance;
    }
};

struct CampaignMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sssiiii";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0x2D49AABD, types, arraySizes, -1);
        return &instance;
    }
};

struct CampaignXConditionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ii?";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x638FC159, types, arraySizes, -1);
        return &instance;
    }
};

struct CampaignXQuestLineMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x7303E0F9, types, arraySizes, -1);
        return &instance;
    }
};

struct CastableRaidBuffsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i?";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x3B349C01, types, arraySizes, -1);
        return &instance;
    }
};

struct CelestialBodyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fiifiiffhiififf";
        static uint8 const arraySizes[15] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 15, 0xFC417DCA, types, arraySizes, -1);
        return &instance;
    }
};

struct Cfg_CategoriesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shbbb";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0xB6FEB874, types, arraySizes, -1);
        return &instance;
    }
};

struct Cfg_ConfigsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbhf";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xA275539B, types, arraySizes, -1);
        return &instance;
    }
};

struct Cfg_RegionsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shibi";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x0125202F, types, arraySizes, -1);
        return &instance;
    }
};

struct CharBaseInfoMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x10AA45F8, types, arraySizes, -1);
        return &instance;
    }
};

struct CharBaseSectionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xF9D1C513, types, arraySizes, -1);
        return &instance;
    }
};

struct CharComponentTextureLayoutsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hh";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x48D8D7BC, types, arraySizes, -1);
        return &instance;
    }
};

struct CharComponentTextureSectionsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbhhhhi";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0xD6EDA743, types, arraySizes, -1);
        return &instance;
    }
};

struct CharHairGeosetsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbbbbbbbii";
        static uint8 const arraySizes[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 10, 0xE3732EA9, types, arraySizes, -1);
        return &instance;
    }
};

struct CharSectionsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbbbbhi";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0x273A7F6F, types, arraySizes, -1);
        return &instance;
    }
};

struct CharShipmentMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hiiiiibhb";
        static uint8 const arraySizes[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 9, 0xD47EC921, types, arraySizes, -1);
        return &instance;
    }
};

struct CharShipmentContainerMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sshbbbhhhhiibbbh";
        static uint8 const arraySizes[16] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 16, 0x13048703, types, arraySizes, -1);
        return &instance;
    }
};

struct CharStartOutfitMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbbibi?";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0x0F59DD96, types, arraySizes, -1);
        return &instance;
    }
};

struct CharTitlesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sshb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x81B69C5F, types, arraySizes, -1);
        return &instance;
    }
};

struct CharacterFaceBoneSetMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bibi?";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x3C6DE4D7, types, arraySizes, -1);
        return &instance;
    }
};

struct CharacterFacialHairStylesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ibbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xAA817A08, types, arraySizes, -1);
        return &instance;
    }
};

struct CharacterLoadoutMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "?bb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xA07F9727, types, arraySizes, -1);
        return &instance;
    }
};

struct CharacterLoadoutItemMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hi";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xD892CDA9, types, arraySizes, -1);
        return &instance;
    }
};

struct CharacterServiceInfoMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sssiiiiiiii";
        static uint8 const arraySizes[11] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 11, 0xC263D77C, types, arraySizes, -1);
        return &instance;
    }
};

struct ChatChannelsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssib";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x113E92FA, types, arraySizes, -1);
        return &instance;
    }
};

struct ChatProfanityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xAF5F92A6, types, arraySizes, -1);
        return &instance;
    }
};

struct ChrClassRaceSexMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbbiii";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 6, 0x204BD561, types, arraySizes, -1);
        return &instance;
    }
};

struct ChrClassTitleMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xA01D47C8, types, arraySizes, -1);
        return &instance;
    }
};

struct ChrClassUIDisplayMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x3D58F88F, types, arraySizes, -1);
        return &instance;
    }
};

struct ChrClassVillainMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x601C7CCD, types, arraySizes, -1);
        return &instance;
    }
};

struct ChrClassesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sssssiiiiiihhhbbbbbb";
        static uint8 const arraySizes[20] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 20, 0x2CD115AC, types, arraySizes, -1);
        return &instance;
    }
};

struct ChrClassesXPowerTypesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "b?";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x6DE888E7, types, arraySizes, -1);
        return &instance;
    }
};

struct ChrCustomizationMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "siiiii?";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0xC29562A3, types, arraySizes, -1);
        return &instance;
    }
};

struct ChrRacesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssssssiiiiiiiiffiiiiiiiiihhhhbbbbbbbbbbbbbbbbb";
        static uint8 const arraySizes[46] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 46, 0xC8BCDC89, types, arraySizes, -1);
        return &instance;
    }
};

struct ChrSpecializationMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sssibbbbiibii";
        static uint8 const arraySizes[13] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 13, 0xFF9DD5DD, types, arraySizes, -1);
        return &instance;
    }
};

struct ChrUpgradeBucketMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ih?";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x81B7C74C, types, arraySizes, -1);
        return &instance;
    }
};

struct ChrUpgradeBucketSpellMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i?";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xC665F469, types, arraySizes, -1);
        return &instance;
    }
};

struct ChrUpgradeTierMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sibb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xEC517FDD, types, arraySizes, -1);
        return &instance;
    }
};

struct CinematicCameraMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fifi";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x20C5E540, types, arraySizes, -1);
        return &instance;
    }
};

struct CinematicSequencesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ih";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x6A232AD4, types, arraySizes, -1);
        return &instance;
    }
};

struct ClientSceneEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x0EE4486, types, arraySizes, -1);
        return &instance;
    }
};

struct CloakDampeningMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fffffff";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0xF7C03F6E, types, arraySizes, -1);
        return &instance;
    }
};

struct CloneEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiiiiii";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 8, 0x2F946F74, types, arraySizes, -1);
        return &instance;
    }
};

struct CombatConditionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhhbbhbbhbb";
        static uint8 const arraySizes[11] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 11, 0x75A29044, types, arraySizes, -1);
        return &instance;
    }
};

struct CommentatorStartLocationMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fi";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xF552D58F, types, arraySizes, -1);
        return &instance;
    }
};

struct CommentatorTrackedCooldownMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ibb?";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x3A1476FC, types, arraySizes, -1);
        return &instance;
    }
};

struct CommunityIconMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x7E19DEAD, types, arraySizes, -1);
        return &instance;
    }
};

struct ComponentModelFileDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x0F90AFAF, types, arraySizes, -1);
        return &instance;
    }
};

struct ComponentTextureFileDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x263AACE3, types, arraySizes, -1);
        return &instance;
    }
};

struct ConfigurationWarningMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "si";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x99BCBA2D, types, arraySizes, -1);
        return &instance;
    }
};

struct ContentTuningMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiiii";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 6, 0xD1A210D1, types, arraySizes, -1);
        return &instance;
    }
};

struct ContributionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssiiiii";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0x37C49135, types, arraySizes, -1);
        return &instance;
    }
};

struct ContributionStyleMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssiiiii";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0x799AE511, types, arraySizes, -1);
        return &instance;
    }
};

struct ContributionStyleContainerMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x55DAA69B, types, arraySizes, -1);
        return &instance;
    }
};

struct ConversationLineMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiihhbbb";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 8, 0x227B5003, types, arraySizes, -1);
        return &instance;
    }
};

struct CreatureMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssssbbhbifi";
        static uint8 const arraySizes[11] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 11, 0x0D492BF3, types, arraySizes, -1);
        return &instance;
    }
};

struct CreatureDifficultyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbbhii?";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0xD344A642, types, arraySizes, -1);
        return &instance;
    }
};

struct CreatureDispXUiCameraMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ih";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xD3D075FD, types, arraySizes, -1);
        return &instance;
    }
};

struct CreatureDisplayInfoMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihhbfbbihhiihhbiffbiibibi";
        static uint8 const arraySizes[25] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 25, 0x613413D1, types, arraySizes, -1);
        return &instance;
    }
};

struct CreatureDisplayInfoCondMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "?bbiiiiiiiiiii?";
        static uint8 const arraySizes[15] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 15, 0x596B4605, types, arraySizes, -1);
        return &instance;
    }
};

struct CreatureDisplayInfoEvtMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iib?";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x16C6EC13, types, arraySizes, -1);
        return &instance;
    }
};

struct CreatureDisplayInfoExtraMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbbbbbbbbiib";
        static uint8 const arraySizes[12] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 12, 0x89E31B13, types, arraySizes, -1);
        return &instance;
    }
};

struct CreatureDisplayInfoGeosetDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bb?";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x13350FA0, types, arraySizes, -1);
        return &instance;
    }
};

struct CreatureDisplayInfoTrnMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiifi?";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 6, 0xC3E28858, types, arraySizes, -1);
        return &instance;
    }
};

struct CreatureFamilyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sfbfbhbih";
        static uint8 const arraySizes[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 9, 0x9D14B492, types, arraySizes, -1);
        return &instance;
    }
};

struct CreatureImmunitiesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bibbbbiii";
        static uint8 const arraySizes[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 9, 0x36D9340F, types, arraySizes, -1);
        return &instance;
    }
};

struct CreatureModelDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fiiiifffiiiiifffifffffffffff";
        static uint8 const arraySizes[28] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 28, 0xF61D550A, types, arraySizes, -1);
        return &instance;
    }
};

struct CreatureMovementInfoMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "f";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x31BE6397, types, arraySizes, -1);
        return &instance;
    }
};

struct CreatureSoundDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiffbii";
        static uint8 const arraySizes[37] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 37, 0xA58BDB91, types, arraySizes, -1);
        return &instance;
    }
};

struct CreatureTypeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x218D575A, types, arraySizes, -1);
        return &instance;
    }
};

struct CreatureXContributionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ii?";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x2DC69C04, types, arraySizes, -1);
        return &instance;
    }
};

struct CreatureXDisplayInfoMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iffb?";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x44D147A6, types, arraySizes, -1);
        return &instance;
    }
};

struct CriteriaMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hiibihbibhb";
        static uint8 const arraySizes[11] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 11, 0x754DDF45, types, arraySizes, -1);
        return &instance;
    }
};

struct CriteriaTreeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "siibiih";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0xC926CF94, types, arraySizes, -1);
        return &instance;
    }
};

struct CriteriaTreeXEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "h?";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x80C700F5, types, arraySizes, -1);
        return &instance;
    }
};

struct CurrencyCategoryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x0DB1F53C, types, arraySizes, -1);
        return &instance;
    }
};

struct CurrencyContainerMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssiiiii?";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 8, 0xAC6030BF, types, arraySizes, -1);
        return &instance;
    }
};

struct CurrencyTypesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssbiibiiibi";
        static uint8 const arraySizes[11] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 11, 0x998F0AAA, types, arraySizes, -1);
        return &instance;
    }
};

struct CurveMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x4E6F1184, types, arraySizes, -1);
        return &instance;
    }
};

struct CurvePointMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fhb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xFA003217, types, arraySizes, -1);
        return &instance;
    }
};

struct DeathThudLookupsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbii";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x3BF7542C, types, arraySizes, -1);
        return &instance;
    }
};

struct DecalPropertiesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiifffffifffbbiif";
        static uint8 const arraySizes[18] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 18, 0xB11F3B40, types, arraySizes, -1);
        return &instance;
    }
};

struct DeclinedWordMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "si";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x10D7C6A6, types, arraySizes, -1);
        return &instance;
    }
};

struct DeclinedWordCasesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sb?";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x3E19B9C5, types, arraySizes, -1);
        return &instance;
    }
};

struct DestructibleModelDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbhbbbhbbbhbbbbhbhbbbb";
        static uint8 const arraySizes[22] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 22, 0xF245BA93, types, arraySizes, -1);
        return &instance;
    }
};

struct DeviceBlacklistMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hh";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x2A350905, types, arraySizes, -1);
        return &instance;
    }
};

struct DeviceDefaultSettingsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x2AB8A38C, types, arraySizes, -1);
        return &instance;
    }
};

struct DifficultyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbbbbbbbbbhhh";
        static uint8 const arraySizes[13] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 13, 0x29FC158C, types, arraySizes, -1);
        return &instance;
    }
};

struct DissolveEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffffffbbifiiif";
        static uint8 const arraySizes[14] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 14, 0x77C510EC, types, arraySizes, -1);
        return &instance;
    }
};

struct DriverBlacklistMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hbiibbb";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0x88C28C05, types, arraySizes, -1);
        return &instance;
    }
};

struct DungeonEncounterMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sihbibibi";
        static uint8 const arraySizes[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 9, 0x6E5C2332, types, arraySizes, -1);
        return &instance;
    }
};

struct DurabilityCostsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hh";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xBB493F52, types, arraySizes, -1);
        return &instance;
    }
};

struct DurabilityQualityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "f";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xCFF4EEC9, types, arraySizes, -1);
        return &instance;
    }
};

struct EdgeGlowEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fffffffffbfii";
        static uint8 const arraySizes[13] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 13, 0xCBCC7336, types, arraySizes, -1);
        return &instance;
    }
};

struct EmotesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "?siibiiii";
        static uint8 const arraySizes[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 9, 0xA909E182, types, arraySizes, -1);
        return &instance;
    }
};

struct EmotesTextMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sh";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xE255C6B0, types, arraySizes, -1);
        return &instance;
    }
};

struct EmotesTextDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sb?";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x460E8F09, types, arraySizes, -1);
        return &instance;
    }
};

struct EmotesTextSoundMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbbi?";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x3A15105C, types, arraySizes, -1);
        return &instance;
    }
};

struct EnvironmentalDamageMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bh";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x448422B4, types, arraySizes, -1);
        return &instance;
    }
};

struct ExhaustionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssiiffff";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 8, 0xF0F48BB5, types, arraySizes, -1);
        return &instance;
    }
};

struct ExpectedStatMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ifffffffff?";
        static uint8 const arraySizes[11] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 11, 0xF0E61875, types, arraySizes, -1);
        return &instance;
    }
};

struct ExpectedStatModMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fffffffff";
        static uint8 const arraySizes[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 9, 0xEA56E599, types, arraySizes, -1);
        return &instance;
    }
};

struct FactionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "?ssihhbbbhhhiifb";
        static uint8 const arraySizes[16] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 16, 0x86FE2D69, types, arraySizes, -1);
        return &instance;
    }
};

struct FactionGroupMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssibii";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 6, 0xB9B4369B, types, arraySizes, -1);
        return &instance;
    }
};

struct FactionTemplateMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhbbbhh";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0xD7143473, types, arraySizes, -1);
        return &instance;
    }
};

struct FootprintTexturesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xF82F1359, types, arraySizes, -1);
        return &instance;
    }
};

struct FootstepTerrainLookupMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hbii";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xC70AACC6, types, arraySizes, -1);
        return &instance;
    }
};

struct FriendshipRepReactionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbh";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x8B096063, types, arraySizes, -1);
        return &instance;
    }
};

struct FriendshipReputationMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "siih";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xECCE459C, types, arraySizes, -1);
        return &instance;
    }
};

struct FullScreenEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ifffffffffffffffffffiffffiii";
        static uint8 const arraySizes[28] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 28, 0x9854A6AC, types, arraySizes, -1);
        return &instance;
    }
};

struct GMSurveyAnswersMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sb?";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xDE59EC07, types, arraySizes, -1);
        return &instance;
    }
};

struct GMSurveyCurrentSurveyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "b";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xAD0D7453, types, arraySizes, -1);
        return &instance;
    }
};

struct GMSurveyQuestionsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x12B097E1, types, arraySizes, -1);
        return &instance;
    }
};

struct GMSurveySurveysMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "b";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x24BB51BE, types, arraySizes, -1);
        return &instance;
    }
};

struct GameObjectArtKitMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ii";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xECF16719, types, arraySizes, -1);
        return &instance;
    }
};

struct GameObjectDiffAnimMapMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbh?";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xDB3508F3, types, arraySizes, -1);
        return &instance;
    }
};

struct GameObjectDisplayInfoMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fihff";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x7A816799, types, arraySizes, -1);
        return &instance;
    }
};

struct GameObjectDisplayInfoXSoundKitMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ib?";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x456E4627, types, arraySizes, -1);
        return &instance;
    }
};

struct GameObjectsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sffihhfbbhhi";
        static uint8 const arraySizes[12] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 12, 0x0995B956, types, arraySizes, -1);
        return &instance;
    }
};

struct GameTipsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbhh";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x768EB877, types, arraySizes, -1);
        return &instance;
    }
};

struct GarrAbilityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssibbihh";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 8, 0x8256E595, types, arraySizes, -1);
        return &instance;
    }
};

struct GarrAbilityCategoryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x9F2C8370, types, arraySizes, -1);
        return &instance;
    }
};

struct GarrAbilityEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihbbbfffbbib";
        static uint8 const arraySizes[12] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 12, 0x682EE0E1, types, arraySizes, -1);
        return &instance;
    }
};

struct GarrBuildingMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssssbbiibbihihhihhibhhhb";
        static uint8 const arraySizes[24] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 24, 0x158D48D4, types, arraySizes, -1);
        return &instance;
    }
};

struct GarrBuildingDoodadSetMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbbbb";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x9A6DE309, types, arraySizes, -1);
        return &instance;
    }
};

struct GarrBuildingPlotInstMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fibhh";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0xFB61E627, types, arraySizes, -1);
        return &instance;
    }
};

struct GarrClassSpecMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sssihhbb";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 8, 0x644E1AC4, types, arraySizes, -1);
        return &instance;
    }
};

struct GarrClassSpecPlayerCondMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "siiiib";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 6, 0x561DEBFE, types, arraySizes, -1);
        return &instance;
    }
};

struct GarrEncounterMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "siiiiff";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0xD193D559, types, arraySizes, -1);
        return &instance;
    }
};

struct GarrEncounterSetXEncounterMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ii?";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xCA7143E7, types, arraySizes, -1);
        return &instance;
    }
};

struct GarrEncounterXMechanicMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bb?";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x0960A66B, types, arraySizes, -1);
        return &instance;
    }
};

struct GarrFollItemSetMemberMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ibh?";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x9166B16F, types, arraySizes, -1);
        return &instance;
    }
};

struct GarrFollSupportSpellMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iib?";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xDB563FC8, types, arraySizes, -1);
        return &instance;
    }
};

struct GarrFollowerMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sssibbiibbbbbbhhbbiihhhhbbbiibbb";
        static uint8 const arraySizes[32] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 32, 0x7C5C19F1, types, arraySizes, -1);
        return &instance;
    }
};

struct GarrFollowerLevelXPMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbhh";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xABD178B2, types, arraySizes, -1);
        return &instance;
    }
};

struct GarrFollowerQualityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bibbbhi";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0xCAE87042, types, arraySizes, -1);
        return &instance;
    }
};

struct GarrFollowerSetXFollowerMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i?";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x621C60FF, types, arraySizes, -1);
        return &instance;
    }
};

struct GarrFollowerTypeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbbhbbb";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0xB4B34EF0, types, arraySizes, -1);
        return &instance;
    }
};

struct GarrFollowerUICreatureMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbifb?";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 6, 0x93A1FAA6, types, arraySizes, -1);
        return &instance;
    }
};

struct GarrFollowerXAbilityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbh?";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x590C69F7, types, arraySizes, -1);
        return &instance;
    }
};

struct GarrItemLevelUpgradeDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiii";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x6B8723A1, types, arraySizes, -1);
        return &instance;
    }
};

struct GarrMechanicMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bfi";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xA83BF5A9, types, arraySizes, -1);
        return &instance;
    }
};

struct GarrMechanicSetXMechanicMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ib?";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xFC7F16A3, types, arraySizes, -1);
        return &instance;
    }
};

struct GarrMechanicTypeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssiib";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x05F19FE7, types, arraySizes, -1);
        return &instance;
    }
};

struct GarrMissionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sssffibbbbihbhibibhiiibiibii?";
        static uint8 const arraySizes[29] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 29, 0x0777205, types, arraySizes, -1);
        return &instance;
    }
};

struct GarrMissionTextureMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fh";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x0D378464, types, arraySizes, -1);
        return &instance;
    }
};

struct GarrMissionTypeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shh";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x3FC87149, types, arraySizes, -1);
        return &instance;
    }
};

struct GarrMissionXEncounterMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiib?";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x539B5B1B, types, arraySizes, -1);
        return &instance;
    }
};

struct GarrMissionXFollowerMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ii?";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xFB9C7E3D, types, arraySizes, -1);
        return &instance;
    }
};

struct GarrMssnBonusAbilityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbhfi";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x91DD4CE6, types, arraySizes, -1);
        return &instance;
    }
};

struct GarrPlotMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbiibbi";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0x3897880E, types, arraySizes, -1);
        return &instance;
    }
};

struct GarrPlotBuildingMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x1ECDCE0A, types, arraySizes, -1);
        return &instance;
    }
};

struct GarrPlotInstanceMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x1FD77CCF, types, arraySizes, -1);
        return &instance;
    }
};

struct GarrPlotUICategoryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x867482E6, types, arraySizes, -1);
        return &instance;
    }
};

struct GarrSiteLevelMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fibhhhbhh";
        static uint8 const arraySizes[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 9, 0x4D823E68, types, arraySizes, -1);
        return &instance;
    }
};

struct GarrSiteLevelPlotInstMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fhbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xA3DF8AD1, types, arraySizes, -1);
        return &instance;
    }
};

struct GarrSpecializationMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssbbbif";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0x8400A7E7, types, arraySizes, -1);
        return &instance;
    }
};

struct GarrStringMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xF404C7D8, types, arraySizes, -1);
        return &instance;
    }
};

struct GarrTalentMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssiibbiiiiiiiiiiiiib";
        static uint8 const arraySizes[20] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 20, 0x96BE787E, types, arraySizes, -1);
        return &instance;
    }
};

struct GarrTalentTreeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "siibbbh";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0x9A3BC97D, types, arraySizes, -1);
        return &instance;
    }
};

struct GarrTypeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiii";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0xCCA7D7B5, types, arraySizes, -1);
        return &instance;
    }
};

struct GarrUiAnimClassInfoMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbfiii";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 6, 0xF6444415, types, arraySizes, -1);
        return &instance;
    }
};

struct GarrUiAnimRaceInfoMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bffffffffffff";
        static uint8 const arraySizes[13] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 13, 0x62B1D302, types, arraySizes, -1);
        return &instance;
    }
};

struct GemPropertiesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hih";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xBCE902DB, types, arraySizes, -1);
        return &instance;
    }
};

struct GlobalStringsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x843675FD, types, arraySizes, -1);
        return &instance;
    }
};

struct GlyphBindableSpellMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i?";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x03429C72, types, arraySizes, -1);
        return &instance;
    }
};

struct GlyphExclusiveCategoryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x59622339, types, arraySizes, -1);
        return &instance;
    }
};

struct GlyphPropertiesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x7C1C2F11, types, arraySizes, -1);
        return &instance;
    }
};

struct GlyphRequiredSpecMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "h?";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x70D4ECC6, types, arraySizes, -1);
        return &instance;
    }
};

struct GroundEffectDoodadMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ibff";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xAB0C6E12, types, arraySizes, -1);
        return &instance;
    }
};

struct GroundEffectTextureMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ibhb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xCCBD52E8, types, arraySizes, -1);
        return &instance;
    }
};

struct GroupFinderActivityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssbbbbbihhbhbb";
        static uint8 const arraySizes[14] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 14, 0xEC40E4B1, types, arraySizes, -1);
        return &instance;
    }
};

struct GroupFinderActivityGrpMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x1EC8D046, types, arraySizes, -1);
        return &instance;
    }
};

struct GroupFinderCategoryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xBFF47DC0, types, arraySizes, -1);
        return &instance;
    }
};

struct GuildColorBackgroundMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xCC5FFB4D, types, arraySizes, -1);
        return &instance;
    }
};

struct GuildColorBorderMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xCC5FFB4D, types, arraySizes, -1);
        return &instance;
    }
};

struct GuildColorEmblemMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xCC5FFB4D, types, arraySizes, -1);
        return &instance;
    }
};

struct GuildPerkSpellsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xC9961BEB, types, arraySizes, -1);
        return &instance;
    }
};

struct HeirloomMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "siiiibbiih";
        static uint8 const arraySizes[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 10, 0xB5925FE9, types, arraySizes, -1);
        return &instance;
    }
};

struct HelmetAnimScalingMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "if?";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xC43CA2FC, types, arraySizes, -1);
        return &instance;
    }
};

struct HelmetGeosetVisDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x2E7C7FED, types, arraySizes, -1);
        return &instance;
    }
};

struct HighlightColorMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "biiib";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0xDC14DB43, types, arraySizes, -1);
        return &instance;
    }
};

struct HolidayDescriptionsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xE70F298C, types, arraySizes, -1);
        return &instance;
    }
};

struct HolidayNamesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xF2917D77, types, arraySizes, -1);
        return &instance;
    }
};

struct HolidaysMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihbiibbbhibi";
        static uint8 const arraySizes[12] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 12, 0xF6DA3904, types, arraySizes, -1);
        return &instance;
    }
};

struct HotfixesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xB67D3F47, types, arraySizes, -1);
        return &instance;
    }
};

struct ImportPriceArmorMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffff";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xC4C8D847, types, arraySizes, -1);
        return &instance;
    }
};

struct ImportPriceQualityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "f";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xCFF4EEC9, types, arraySizes, -1);
        return &instance;
    }
};

struct ImportPriceShieldMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "f";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xCFF4EEC9, types, arraySizes, -1);
        return &instance;
    }
};

struct ImportPriceWeaponMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "f";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xCFF4EEC9, types, arraySizes, -1);
        return &instance;
    }
};

struct InvasionClientDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sfiiiiiii?";
        static uint8 const arraySizes[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 10, 0x04FC0B4F, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbbbbbib";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 8, 0xF9600007, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemAppearanceMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "biii";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x422F764D, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemAppearanceXUiCameraMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hh";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xCD3677FD, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemArmorQualityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "f";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x0B17E016, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemArmorShieldMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fh";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xC88C8C8D, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemArmorTotalMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hffff";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0xC4CD0FD9, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemBagFamilyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x9F2C8370, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemBonusMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xB96C1748, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemBonusListLevelDeltaMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hi";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x819C0CC1, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemBonusTreeNodeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bhhh?";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x1DDAA885, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemChildEquipmentMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ib?";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x48E64550, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemClassMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbfb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xB6C67A3D, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemContextPickerEntryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbiii?";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 6, 0x1596EAF3, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemCurrencyCostMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xDAC6A93C, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemDamageAmmoMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hf";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x1309BE8D, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemDamageOneHandMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hf";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x1309BE8D, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemDamageOneHandCasterMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hf";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x1309BE8D, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemDamageTwoHandMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hf";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x1309BE8D, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemDamageTwoHandCasterMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hf";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x1309BE8D, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemDisenchantLootMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbhhhb?";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0x146B9F40, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemDisplayInfoMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiiiiiiiiiiiii";
        static uint8 const arraySizes[15] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 15, 0x089404D9, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemDisplayInfoMaterialResMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bi?";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x936E6A99, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemDisplayXUiCameraMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ih";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x3E999EAA, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbhiihih?";
        static uint8 const arraySizes[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 9, 0x46818AA6, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemExtendedCostMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hbbbbbihhi";
        static uint8 const arraySizes[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 10, 0x2AC5BE11, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemGroupSoundsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x909375D2, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemLevelSelectorMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hh";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x3112276E, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemLevelSelectorQualityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ib?";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xC40169D5, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemLevelSelectorQualitySetMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hh";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x89657A48, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemLimitCategoryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xE068171C, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemLimitCategoryConditionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bi?";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x7F847085, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemModifiedAppearanceMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iibhbb";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 6, 0x9C32B7FF, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemModifiedAppearanceExtraMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iibbb";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x7E2FD302, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemNameDescriptionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "si";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xBBF04CCC, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemPetFoodMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xD6AB60EB, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemPriceBaseMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hff";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xC90092C7, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemRandomPropertiesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sh";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xBDA8BFCD, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemRandomSuffixMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shh";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xABCC4871, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemRangedDisplayInfoMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiii";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xA6B99F0D, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemSearchNameMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "?sibbhbibhhihi";
        static uint8 const arraySizes[14] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 14, 0xF0940AFC, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemSetMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "siihi";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0xB02A9041, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemSetSpellMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hib?";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xD6AEEA60, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemSparseMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "?sssssfififfiiiiiiiffiihhhhhhhhhhhhhhhhhhhhhhbbbbbbbbbbbbbbbbbbb";
        static uint8 const arraySizes[64] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 64, 0xF9021F01, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemSpecMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbbbbh";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 6, 0xEB138F8E, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemSpecOverrideMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "h?";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xB235D33A, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemSubClassMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssbbbbhbbb";
        static uint8 const arraySizes[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 10, 0xC7178B11, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemSubClassMaskMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbi";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x146E3154, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemUpgradeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbhhi";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x706FA369, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemVisualsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x4025FA36, types, arraySizes, -1);
        return &instance;
    }
};

struct ItemXBonusTreeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "h?";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x57244BD5, types, arraySizes, -1);
        return &instance;
    }
};

struct JournalEncounterMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssfhihhibb";
        static uint8 const arraySizes[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 10, 0x5E057FAD, types, arraySizes, -1);
        return &instance;
    }
};

struct JournalEncounterCreatureMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssihiibi";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 8, 0x71CE658D, types, arraySizes, -1);
        return &instance;
    }
};

struct JournalEncounterItemMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihibbb";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 6, 0x5FD94071, types, arraySizes, -1);
        return &instance;
    }
};

struct JournalEncounterSectionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sshbhhhbiiiihhb";
        static uint8 const arraySizes[15] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 15, 0x582FB4F6, types, arraySizes, -1);
        return &instance;
    }
};

struct JournalEncounterXDifficultyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "b?";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x436676BA, types, arraySizes, -1);
        return &instance;
    }
};

struct JournalEncounterXMapLocMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fiib?";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0xBCE56697, types, arraySizes, -1);
        return &instance;
    }
};

struct JournalInstanceMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssihiiiibbh";
        static uint8 const arraySizes[11] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 11, 0xBB10478F, types, arraySizes, -1);
        return &instance;
    }
};

struct JournalItemXDifficultyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "b?";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xF938F4BD, types, arraySizes, -1);
        return &instance;
    }
};

struct JournalSectionXDifficultyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "b?";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xE02C355F, types, arraySizes, -1);
        return &instance;
    }
};

struct JournalTierMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xE0D727CB, types, arraySizes, -1);
        return &instance;
    }
};

struct JournalTierXInstanceMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hh";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xD584CE6A, types, arraySizes, -1);
        return &instance;
    }
};

struct KeyChainMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "b";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x67DDA82E, types, arraySizes, -1);
        return &instance;
    }
};

struct KeystoneAffixMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssii";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x60D97B7F, types, arraySizes, -1);
        return &instance;
    }
};

struct LanguageWordsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xFBB33D15, types, arraySizes, -1);
        return &instance;
    }
};

struct LanguagesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "si";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xAA508D47, types, arraySizes, -1);
        return &instance;
    }
};

struct LfgDungeonExpansionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bhbbii?";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0x6754EDAB, types, arraySizes, -1);
        return &instance;
    }
};

struct LfgDungeonGroupMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbbh";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x4E84BE76, types, arraySizes, -1);
        return &instance;
    }
};

struct LfgDungeonsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssbhbbbiiibhbfbbibbhhhhbbbbbbhhbi";
        static uint8 const arraySizes[33] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 33, 0xD9B678AD, types, arraySizes, -1);
        return &instance;
    }
};

struct LfgDungeonsGroupingMapMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hb?";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xD50B89E4, types, arraySizes, -1);
        return &instance;
    }
};

struct LfgRoleRequirementMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bi?";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x35B34A59, types, arraySizes, -1);
        return &instance;
    }
};

struct LightMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fffhh";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x04052B1F, types, arraySizes, -1);
        return &instance;
    }
};

struct LightDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhiiiiiiiiiiiiiiiiiiffffffffiiiififi";
        static uint8 const arraySizes[36] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 36, 0xE7CA3F85, types, arraySizes, -1);
        return &instance;
    }
};

struct LightParamsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fibhbfffffbi";
        static uint8 const arraySizes[12] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 12, 0xA08FAABA, types, arraySizes, -1);
        return &instance;
    }
};

struct LightSkyboxMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbii";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x757E9EB6, types, arraySizes, -1);
        return &instance;
    }
};

struct LightningMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fiffffffffffiffffffffiifffffffffff";
        static uint8 const arraySizes[34] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 34, 0x8B6D192C, types, arraySizes, -1);
        return &instance;
    }
};

struct LiquidMaterialMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x6A7287A2, types, arraySizes, -1);
        return &instance;
    }
};

struct LiquidObjectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffhbb";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x7AF380AA, types, arraySizes, -1);
        return &instance;
    }
};

struct LiquidTypeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sshbiiffffhfbbbibifif";
        static uint8 const arraySizes[21] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 21, 0x29F8C65E, types, arraySizes, -1);
        return &instance;
    }
};

struct LoadingScreenTaxiSplinesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hbhff";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0xCDF5DDF1, types, arraySizes, -1);
        return &instance;
    }
};

struct LoadingScreensMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xA2488A1C, types, arraySizes, -1);
        return &instance;
    }
};

struct LocaleMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bibb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x65638FD5, types, arraySizes, -1);
        return &instance;
    }
};

struct LocationMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ff";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x71BD1122, types, arraySizes, -1);
        return &instance;
    }
};

struct LockMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x156C0BD7, types, arraySizes, -1);
        return &instance;
    }
};

struct LockTypeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssssi";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x3F736720, types, arraySizes, -1);
        return &instance;
    }
};

struct LookAtControllerMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fiihfihhhbbiibbffb";
        static uint8 const arraySizes[18] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 18, 0x2E077E56, types, arraySizes, -1);
        return &instance;
    }
};

struct MailTemplateMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xC6E0D9B5, types, arraySizes, -1);
        return &instance;
    }
};

struct ManagedWorldStateMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiiiiiiii";
        static uint8 const arraySizes[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 10, 0x043BFC8F, types, arraySizes, -1);
        return &instance;
    }
};

struct ManagedWorldStateBuffMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii?";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x049B986F, types, arraySizes, -1);
        return &instance;
    }
};

struct ManagedWorldStateInputMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x21237CDC, types, arraySizes, -1);
        return &instance;
    }
};

struct ManifestInterfaceActionIconMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xB5EE0DCB, types, arraySizes, -1);
        return &instance;
    }
};

struct ManifestInterfaceDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ss";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x03E4C021, types, arraySizes, -1);
        return &instance;
    }
};

struct ManifestInterfaceItemIconMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xB5EE0DCB, types, arraySizes, -1);
        return &instance;
    }
};

struct ManifestInterfaceTOCDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xD00DAF09, types, arraySizes, -1);
        return &instance;
    }
};

struct ManifestMP3Meta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xB5EE0DCB, types, arraySizes, -1);
        return &instance;
    }
};

struct MapMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssssssfbbbhhhhhbfhbhii";
        static uint8 const arraySizes[22] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 22, 0x503A3E58, types, arraySizes, -1);
        return &instance;
    }
};

struct MapCelestialBodyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hi?";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x14543648, types, arraySizes, -1);
        return &instance;
    }
};

struct MapChallengeModeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sihbh";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x50F3ABC2, types, arraySizes, -1);
        return &instance;
    }
};

struct MapDifficultyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "siibbbbbb?";
        static uint8 const arraySizes[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 10, 0xF876E8BA, types, arraySizes, -1);
        return &instance;
    }
};

struct MapDifficultyXConditionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sii?";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x8DBA5D16, types, arraySizes, -1);
        return &instance;
    }
};

struct MapLoadingScreenMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffii?";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0xC4CFD9A8, types, arraySizes, -1);
        return &instance;
    }
};

struct MarketingPromotionsXLocaleMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbbiiii";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0xC04E61FB, types, arraySizes, -1);
        return &instance;
    }
};

struct MaterialMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "biii";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x370D43B4, types, arraySizes, -1);
        return &instance;
    }
};

struct MinorTalentMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ii?";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x09F57B9C, types, arraySizes, -1);
        return &instance;
    }
};

struct MissileTargetingMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffffffffiifi";
        static uint8 const arraySizes[12] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 12, 0xF695DDBA, types, arraySizes, -1);
        return &instance;
    }
};

struct ModelAnimCloakDampeningMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ii?";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xAA668B4F, types, arraySizes, -1);
        return &instance;
    }
};

struct ModelFileDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ibbi";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x9C9B4543, types, arraySizes, -1);
        return &instance;
    }
};

struct ModelRibbonQualityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "b?";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xA26E8DD1, types, arraySizes, -1);
        return &instance;
    }
};

struct ModifierTreeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ibbbiib";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0x643002AE, types, arraySizes, -1);
        return &instance;
    }
};

struct MountMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sssihhbiifi";
        static uint8 const arraySizes[11] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 11, 0x629E87E2, types, arraySizes, -1);
        return &instance;
    }
};

struct MountCapabilityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ibhhiiih";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 8, 0xD8A906D6, types, arraySizes, -1);
        return &instance;
    }
};

struct MountTypeXCapabilityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x613701E9, types, arraySizes, -1);
        return &instance;
    }
};

struct MountXDisplayMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ii?";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x2D4F3D78, types, arraySizes, -1);
        return &instance;
    }
};

struct MovieMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbii";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x4848C4FB, types, arraySizes, -1);
        return &instance;
    }
};

struct MovieFileDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "h";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xB24F82EB, types, arraySizes, -1);
        return &instance;
    }
};

struct MovieVariationMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ii?";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xAEA671AA, types, arraySizes, -1);
        return &instance;
    }
};

struct MultiStatePropertiesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fibifiiiii?";
        static uint8 const arraySizes[11] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 11, 0x50BB5EDC, types, arraySizes, -1);
        return &instance;
    }
};

struct MultiTransitionPropertiesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiii";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x5720F452, types, arraySizes, -1);
        return &instance;
    }
};

struct MythicPlusSeasonRewardLevelsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii?";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xAD6A6D9F, types, arraySizes, -1);
        return &instance;
    }
};

struct NPCSoundsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x5EF56D1F, types, arraySizes, -1);
        return &instance;
    }
};

struct NameGenMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xB0EBC6C9, types, arraySizes, -1);
        return &instance;
    }
};

struct NamesProfanityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xCD33D2BE, types, arraySizes, -1);
        return &instance;
    }
};

struct NamesReservedMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xECCAE96B, types, arraySizes, -1);
        return &instance;
    }
};

struct NamesReservedLocaleMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x5AAEEDD3, types, arraySizes, -1);
        return &instance;
    }
};

struct NpcModelItemSlotDisplayInfoMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ib?";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xB8EC2628, types, arraySizes, -1);
        return &instance;
    }
};

struct NumTalentsAtLevelMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiii";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xDE3268EF, types, arraySizes, -1);
        return &instance;
    }
};

struct ObjectEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fhbbbibi";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 8, 0x48D89FCF, types, arraySizes, -1);
        return &instance;
    }
};

struct ObjectEffectModifierMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fbbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x68D120B3, types, arraySizes, -1);
        return &instance;
    }
};

struct ObjectEffectPackageElemMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhh";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x3B8C53F9, types, arraySizes, -1);
        return &instance;
    }
};

struct OccluderMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iibbbbbbb";
        static uint8 const arraySizes[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 9, 0xFEDCAAB3, types, arraySizes, -1);
        return &instance;
    }
};

struct OccluderLocationMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffii";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x95F8BBE4, types, arraySizes, -1);
        return &instance;
    }
};

struct OccluderNodeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihhi";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x19A34490, types, arraySizes, -1);
        return &instance;
    }
};

struct OutlineEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiifi";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 6, 0xECA16738, types, arraySizes, -1);
        return &instance;
    }
};

struct OverrideSpellDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iib";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xCEE01938, types, arraySizes, -1);
        return &instance;
    }
};

struct PageTextMaterialMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xF6F6B04B, types, arraySizes, -1);
        return &instance;
    }
};

struct PaperDollItemFrameMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sib";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xB85F646E, types, arraySizes, -1);
        return &instance;
    }
};

struct ParagonReputationMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xF9AC6E2E, types, arraySizes, -1);
        return &instance;
    }
};

struct ParticleColorMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xB44B4D4D, types, arraySizes, -1);
        return &instance;
    }
};

struct ParticulateSoundMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiii";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0xF60E0955, types, arraySizes, -1);
        return &instance;
    }
};

struct PathMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbbbbbb";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0x3551690B, types, arraySizes, -1);
        return &instance;
    }
};

struct PathNodeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihhi";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x19A34490, types, arraySizes, -1);
        return &instance;
    }
};

struct PathNodePropertyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihhbi";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x578DA815, types, arraySizes, -1);
        return &instance;
    }
};

struct PathPropertyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihbi";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x3B269A90, types, arraySizes, -1);
        return &instance;
    }
};

struct PhaseMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "h";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x60D39728, types, arraySizes, -1);
        return &instance;
    }
};

struct PhaseShiftZoneSoundsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hbhhbiihbiihb";
        static uint8 const arraySizes[13] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 13, 0x7CA0A010, types, arraySizes, -1);
        return &instance;
    }
};

struct PhaseXPhaseGroupMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "h?";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xF00195AE, types, arraySizes, -1);
        return &instance;
    }
};

struct PlayerConditionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "?sihhiibbihbibbiiiiibihbbbibbiiihibbiihhbhibbbibbbibbbbbbhhhibhhhiiihiibhhbbiiiii";
        static uint8 const arraySizes[81] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 81, 0xF28CBD18, types, arraySizes, -1);
        return &instance;
    }
};

struct PositionerMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hbfb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x533B33CB, types, arraySizes, -1);
        return &instance;
    }
};

struct PositionerStateMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiiiifb";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 8, 0x9E87B63A, types, arraySizes, -1);
        return &instance;
    }
};

struct PositionerStateEntryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffihhhhbbbb";
        static uint8 const arraySizes[11] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 11, 0xBA9A19C4, types, arraySizes, -1);
        return &instance;
    }
};

struct PowerDisplayMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbbbb";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0xEB89C62F, types, arraySizes, -1);
        return &instance;
    }
};

struct PowerTypeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssbbhbbbhffh";
        static uint8 const arraySizes[12] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 12, 0x6D438CB5, types, arraySizes, -1);
        return &instance;
    }
};

struct PrestigeLevelInfoMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "siibi";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x31BD813F, types, arraySizes, -1);
        return &instance;
    }
};

struct PvpBracketTypesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bi";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x54CF87FB, types, arraySizes, -1);
        return &instance;
    }
};

struct PvpDifficultyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbb?";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x794DB95D, types, arraySizes, -1);
        return &instance;
    }
};

struct PvpItemMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ib";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x0CD750C1, types, arraySizes, -1);
        return &instance;
    }
};

struct PvpScalingEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iif";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xAF88F6DB, types, arraySizes, -1);
        return &instance;
    }
};

struct PvpScalingEffectTypeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xF6F6B04B, types, arraySizes, -1);
        return &instance;
    }
};

struct PvpTalentMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "siiiiiiii";
        static uint8 const arraySizes[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 9, 0x340BABA3, types, arraySizes, -1);
        return &instance;
    }
};

struct PvpTalentCategoryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "b";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xBB4B5731, types, arraySizes, -1);
        return &instance;
    }
};

struct PvpTalentSlotUnlockMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "biii";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x572DDD84, types, arraySizes, -1);
        return &instance;
    }
};

struct PvpTierMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shhiibbi";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 8, 0x689983C8, types, arraySizes, -1);
        return &instance;
    }
};

struct QuestFactionRewardMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "h";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x504FAFB5, types, arraySizes, -1);
        return &instance;
    }
};

struct QuestFeedbackEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihbbbb";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 6, 0x58E79FBF, types, arraySizes, -1);
        return &instance;
    }
};

struct QuestInfoMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbbh";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xDDB38B83, types, arraySizes, -1);
        return &instance;
    }
};

struct QuestLineMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssi";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xC4BD3235, types, arraySizes, -1);
        return &instance;
    }
};

struct QuestLineXQuestMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x57EF18BF, types, arraySizes, -1);
        return &instance;
    }
};

struct QuestMoneyRewardMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x7E00C5B6, types, arraySizes, -1);
        return &instance;
    }
};

struct QuestObjectiveMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbiibbb?";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 8, 0x37353FB6, types, arraySizes, -1);
        return &instance;
    }
};

struct QuestPOIBlobMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihibiii";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0x5DF4B040, types, arraySizes, -1);
        return &instance;
    }
};

struct QuestPOIPointMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihh?";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x18D6E719, types, arraySizes, -1);
        return &instance;
    }
};

struct QuestPackageItemMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hiib";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xEB0764D1, types, arraySizes, -1);
        return &instance;
    }
};

struct QuestSortMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x2F5E2228, types, arraySizes, -1);
        return &instance;
    }
};

struct QuestV2Meta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "h";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x638D02EF, types, arraySizes, -1);
        return &instance;
    }
};

struct QuestV2CliTaskMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "?ssihiihiiiiiiiiiiiihiii";
        static uint8 const arraySizes[24] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 24, 0xC0387D4E, types, arraySizes, -1);
        return &instance;
    }
};

struct QuestXGroupActivityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ii";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xAA88A593, types, arraySizes, -1);
        return &instance;
    }
};

struct QuestXPMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "h";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xC33E0774, types, arraySizes, -1);
        return &instance;
    }
};

struct RandPropPointsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiii";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x7741F65C, types, arraySizes, -1);
        return &instance;
    }
};

struct RelicSlotTierRequirementMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbi";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x22CDBDE9, types, arraySizes, -1);
        return &instance;
    }
};

struct RelicTalentMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihbii";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x8BEAE937, types, arraySizes, -1);
        return &instance;
    }
};

struct ResearchBranchMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbhiii";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 6, 0xA6CB64A5, types, arraySizes, -1);
        return &instance;
    }
};

struct ResearchFieldMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sib";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xD7448990, types, arraySizes, -1);
        return &instance;
    }
};

struct ResearchProjectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssibihbii";
        static uint8 const arraySizes[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 9, 0x4A748755, types, arraySizes, -1);
        return &instance;
    }
};

struct ResearchSiteMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shii";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x14F7693B, types, arraySizes, -1);
        return &instance;
    }
};

struct ResistancesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbi";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xF7F049B5, types, arraySizes, -1);
        return &instance;
    }
};

struct RewardPackMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iibfbi";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 6, 0xB0527FA7, types, arraySizes, -1);
        return &instance;
    }
};

struct RewardPackXCurrencyTypeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ii?";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xEA88FC16, types, arraySizes, -1);
        return &instance;
    }
};

struct RewardPackXItemMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ii?";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x277E8179, types, arraySizes, -1);
        return &instance;
    }
};

struct RibbonQualityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bfffi";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0xBB0CC4F4, types, arraySizes, -1);
        return &instance;
    }
};

struct RulesetItemUpgradeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ih";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xA03B4C48, types, arraySizes, -1);
        return &instance;
    }
};

struct SDReplacementModelMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xD9C05976, types, arraySizes, -1);
        return &instance;
    }
};

struct ScalingStatDistributionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x34B9A97A, types, arraySizes, -1);
        return &instance;
    }
};

struct ScenarioMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shbbi";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x0857765A, types, arraySizes, -1);
        return &instance;
    }
};

struct ScenarioEventEntryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bi";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x34B30E13, types, arraySizes, -1);
        return &instance;
    }
};

struct ScenarioStepMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sshihihbbih";
        static uint8 const arraySizes[11] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 11, 0x8FF5E1E6, types, arraySizes, -1);
        return &instance;
    }
};

struct SceneScriptMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hh";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xEF472E96, types, arraySizes, -1);
        return &instance;
    }
};

struct SceneScriptGlobalTextMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ss";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xDE6E2251, types, arraySizes, -1);
        return &instance;
    }
};

struct SceneScriptPackageMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xF6F6B04B, types, arraySizes, -1);
        return &instance;
    }
};

struct SceneScriptPackageMemberMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhhb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x9E18D06F, types, arraySizes, -1);
        return &instance;
    }
};

struct SceneScriptTextMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ss";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xDE6E2251, types, arraySizes, -1);
        return &instance;
    }
};

struct ScheduledIntervalMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiii";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x0C287F7A, types, arraySizes, -1);
        return &instance;
    }
};

struct ScheduledWorldStateMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiiiiii";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 8, 0xDC45735A, types, arraySizes, -1);
        return &instance;
    }
};

struct ScheduledWorldStateGroupMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiii";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0xCF71B287, types, arraySizes, -1);
        return &instance;
    }
};

struct ScheduledWorldStateXUniqCatMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ii?";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xF512C749, types, arraySizes, -1);
        return &instance;
    }
};

struct ScreenEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sibihhhiihbb";
        static uint8 const arraySizes[12] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 12, 0x7A371491, types, arraySizes, -1);
        return &instance;
    }
};

struct ScreenLocationMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xF6F6B04B, types, arraySizes, -1);
        return &instance;
    }
};

struct SeamlessSiteMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x9E36592F, types, arraySizes, -1);
        return &instance;
    }
};

struct ServerMessagesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xCC7971DF, types, arraySizes, -1);
        return &instance;
    }
};

struct ShadowyEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiffffbbfffii";
        static uint8 const arraySizes[13] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 13, 0x7292BC4C, types, arraySizes, -1);
        return &instance;
    }
};

struct SiegeablePropertiesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiii";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x98E42A9F, types, arraySizes, -1);
        return &instance;
    }
};

struct SkillLineMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sssssibibiihi";
        static uint8 const arraySizes[13] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 13, 0xEC83FE8A, types, arraySizes, -1);
        return &instance;
    }
};

struct SkillLineAbilityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "?ihihiibhhbbhhh";
        static uint8 const arraySizes[15] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 15, 0xA38AD072, types, arraySizes, -1);
        return &instance;
    }
};

struct SkillRaceClassInfoMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "?hihbbh";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0x4CFD464E, types, arraySizes, -1);
        return &instance;
    }
};

struct SoundAmbienceMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "biiiii";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 6, 0x625245C7, types, arraySizes, -1);
        return &instance;
    }
};

struct SoundAmbienceFlavorMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ii?";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x41E33D5D, types, arraySizes, -1);
        return &instance;
    }
};

struct SoundBusMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ibbbfbb?";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 8, 0x7CC84C2D, types, arraySizes, -1);
        return &instance;
    }
};

struct SoundBusOverrideMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiibfbb";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0xF321EA82, types, arraySizes, -1);
        return &instance;
    }
};

struct SoundEmitterPillPointsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fh";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xD63C5DE3, types, arraySizes, -1);
        return &instance;
    }
};

struct SoundEmittersMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sffiihbhibb?";
        static uint8 const arraySizes[12] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 12, 0x1FDCDD5A, types, arraySizes, -1);
        return &instance;
    }
};

struct SoundEnvelopeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ibiihhh";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0xBD6F1248, types, arraySizes, -1);
        return &instance;
    }
};

struct SoundFilterMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xF6F6B04B, types, arraySizes, -1);
        return &instance;
    }
};

struct SoundFilterElemMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fb?";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x84F8D205, types, arraySizes, -1);
        return &instance;
    }
};

struct SoundKitMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ibfhffbiffffbfhb";
        static uint8 const arraySizes[16] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 16, 0xAF055926, types, arraySizes, -1);
        return &instance;
    }
};

struct SoundKitAdvancedMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiffiiiiibiiiibfffffffffiifffbhiiibbiiiiiif";
        static uint8 const arraySizes[43] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 43, 0x6EAFA63E, types, arraySizes, -1);
        return &instance;
    }
};

struct SoundKitChildMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ii";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x4215B0DD, types, arraySizes, -1);
        return &instance;
    }
};

struct SoundKitEntryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iibf";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xCBC66B5F, types, arraySizes, -1);
        return &instance;
    }
};

struct SoundKitFallbackMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ii";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x53D01CD7, types, arraySizes, -1);
        return &instance;
    }
};

struct SoundKitNameMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xF6F6B04B, types, arraySizes, -1);
        return &instance;
    }
};

struct SoundOverrideMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhhbb";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x4EC15243, types, arraySizes, -1);
        return &instance;
    }
};

struct SoundProviderPreferencesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbfffhhfhfhfffbfffffffh";
        static uint8 const arraySizes[23] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 23, 0xF0F42A22, types, arraySizes, -1);
        return &instance;
    }
};

struct SourceInfoMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbb?";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xA94C7962, types, arraySizes, -1);
        return &instance;
    }
};

struct SpamMessagesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x1A080193, types, arraySizes, -1);
        return &instance;
    }
};

struct SpecSetMemberMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i?";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xC05B6C73, types, arraySizes, -1);
        return &instance;
    }
};

struct SpecializationSpellsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sihiib";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 6, 0x88A56A2F, types, arraySizes, -1);
        return &instance;
    }
};

struct SpecializationSpellsDisplayMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hi";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xBD5EEC46, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sss";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xFFF1DA38, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellActionBarPrefMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ih";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xCF471C9B, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellActivationOverlayMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiibiifb";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 8, 0xE72C81EF, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellAuraOptionsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bhibihi?";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 8, 0xCBDA0981, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellAuraRestrictionsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbbbbiiii?";
        static uint8 const arraySizes[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 10, 0xD7479271, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellAuraVisXChrSpecMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "h?";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x8F54FD52, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellAuraVisibilityMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ibb?";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xB7F28C20, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellCastTimesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihi";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xA66E197C, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellCastingRequirementsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ibhbhbh";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0xC6D7C649, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellCategoriesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bhbbbbhh?";
        static uint8 const arraySizes[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 9, 0xEF1D2548, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellCategoryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbbbii";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 6, 0x53EB1CD3, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellChainEffectsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fffihihfbbffffffffffffffffffffffffffbbbbbbfffiffhbbiffhffffi";
        static uint8 const arraySizes[60] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 60, 0x461F9829, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellClassOptionsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iibi";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xB4E205E0, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellCooldownsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "biii?";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x24886B08, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellDescriptionVariablesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x9C318DAF, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellDispelTypeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xAA83295A, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellDurationMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x22236CBC, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiifihiffiiifffifffffffiiih?";
        static uint8 const arraySizes[28] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 28, 0x803150B7, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellEffectAutoDescriptionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssiibbbii";
        static uint8 const arraySizes[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 9, 0x7C523D94, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellEffectEmissionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffhb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x66D096CB, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellEquippedItemsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ibii";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xA0588766, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellFlyoutMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "?ssbii";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 6, 0x1F516F53, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellFlyoutItemMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ib?";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x650A0B4D, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellFocusObjectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x9F2C8370, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellInterruptsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bhii?";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0xF551B940, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellItemEnchantmentMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssifiiihhhhhhbbbbbbb";
        static uint8 const arraySizes[20] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 20, 0x96D1828E, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellItemEnchantmentConditionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bibbbb";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 6, 0xFAA95A11, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellKeyboundOverrideMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbi";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xFB8AD330, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellLabelMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i?";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xCCA24F16, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellLearnSpellMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xCC8637D2, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellLevelsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bhhhb?";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 6, 0xE3096221, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellMechanicMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x24C6F0F3, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellMiscMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bhhhbfffiii?";
        static uint8 const arraySizes[12] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 12, 0x76E982BB, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellMissileMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ibfffffffffffff";
        static uint8 const arraySizes[15] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 15, 0xAF286A50, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellMissileMotionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xA61A5983, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellNameMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x9F2C8370, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellPowerMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ibiiiiifffbii?";
        static uint8 const arraySizes[14] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 14, 0x12ED7A99, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellPowerDifficultyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ibb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x08FEDBFF, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellProceduralEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ibf";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xF320E3AD, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellProcsPerMinuteMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xBEBE0C8B, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellProcsPerMinuteModMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bhf?";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xE5827335, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellRadiusMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffff";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xAE4257F8, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellRangeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssbff";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x6B9E2FD2, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellReagentsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iih";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x4B7DC644, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellReagentsCurrencyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihh";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x4D3F01C6, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellScalingMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiih";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x4B0C2E65, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellShapeshiftMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ibii";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x91C4FFE9, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellShapeshiftFormMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbiibhfhii";
        static uint8 const arraySizes[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 10, 0x7082136E, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellSpecialUnitEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hi";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xF084B84D, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellTargetRestrictionsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bfbihif?";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 8, 0x47BE0E0C, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellTotemsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihi";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x5214FD94, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellVisualMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffiibbiiiiihhii";
        static uint8 const arraySizes[15] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 15, 0x514F85ED, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellVisualAnimMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iih";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xB27FB4A5, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellVisualColorEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fibbhhhhhfi";
        static uint8 const arraySizes[11] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 11, 0x773CE0DE, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellVisualEffectNameMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ifffffiifiiiii";
        static uint8 const arraySizes[14] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 14, 0x10206967, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellVisualEventMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiiiiii?";
        static uint8 const arraySizes[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 9, 0x8352EE58, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellVisualKitMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ifihh";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x3F538334, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellVisualKitAreaModelMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ibhfff";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 6, 0x34C79353, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellVisualKitEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ii?";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xF104E59F, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellVisualKitModelAttachMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffihbhffffffffhhhhbif?";
        static uint8 const arraySizes[22] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 22, 0x75650E39, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellVisualMissileMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffihibbhhiihihi?";
        static uint8 const arraySizes[16] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 16, 0x0A0345EB, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellXDescriptionVariablesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ii";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xFBC7B7AE, types, arraySizes, -1);
        return &instance;
    }
};

struct SpellXSpellVisualMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ibifbbiihihi?";
        static uint8 const arraySizes[13] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 13, 0xCDAF2854, types, arraySizes, -1);
        return &instance;
    }
};

struct StartupFilesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xF1381769, types, arraySizes, -1);
        return &instance;
    }
};

struct Startup_StringsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ss";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x82058A06, types, arraySizes, -1);
        return &instance;
    }
};

struct StationeryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ibi";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x8B250029, types, arraySizes, -1);
        return &instance;
    }
};

struct SummonPropertiesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiii";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x4134937A, types, arraySizes, -1);
        return &instance;
    }
};

struct TactKeyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "b";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xA55E1CCE, types, arraySizes, -1);
        return &instance;
    }
};

struct TactKeyLookupMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "b";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x1A696886, types, arraySizes, -1);
        return &instance;
    }
};

struct TalentMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbbbbhiib";
        static uint8 const arraySizes[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 9, 0x2661E6C2, types, arraySizes, -1);
        return &instance;
    }
};

struct TaxiNodesMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sfffihhhbifiii";
        static uint8 const arraySizes[14] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 14, 0x91ADBF11, types, arraySizes, -1);
        return &instance;
    }
};

struct TaxiPathMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihhi";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x3716BBCD, types, arraySizes, -1);
        return &instance;
    }
};

struct TaxiPathNodeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fihihbihh";
        static uint8 const arraySizes[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 9, 0xE28C3360, types, arraySizes, -1);
        return &instance;
    }
};

struct TerrainMaterialMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x9F25E6D3, types, arraySizes, -1);
        return &instance;
    }
};

struct TerrainTypeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shhbb";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0xB4573071, types, arraySizes, -1);
        return &instance;
    }
};

struct TerrainTypeSoundsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xECCAE96B, types, arraySizes, -1);
        return &instance;
    }
};

struct TextureBlendSetMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ibbbbfffff";
        static uint8 const arraySizes[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 10, 0xF2AFFE4C, types, arraySizes, -1);
        return &instance;
    }
};

struct TextureFileDataMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ibi";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x71D3BD92, types, arraySizes, -1);
        return &instance;
    }
};

struct TotemCategoryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbi";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x2AA9FB1E, types, arraySizes, -1);
        return &instance;
    }
};

struct ToyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "siibb";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x6156EBCA, types, arraySizes, -1);
        return &instance;
    }
};

struct TradeSkillCategoryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssihhhb";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0xAFEA1AAD, types, arraySizes, -1);
        return &instance;
    }
};

struct TradeSkillItemMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xA90CD5D2, types, arraySizes, -1);
        return &instance;
    }
};

struct TransformMatrixMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fffff";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0xBA00B2FD, types, arraySizes, -1);
        return &instance;
    }
};

struct TransmogHolidayMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ii";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x6FC325A0, types, arraySizes, -1);
        return &instance;
    }
};

struct TransmogSetMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "siiiiiihbh";
        static uint8 const arraySizes[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 10, 0x3F0E4AEF, types, arraySizes, -1);
        return &instance;
    }
};

struct TransmogSetGroupMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "si";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x0F60CFC9, types, arraySizes, -1);
        return &instance;
    }
};

struct TransmogSetItemMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiii";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x23855A82, types, arraySizes, -1);
        return &instance;
    }
};

struct TransportAnimationMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fbi?";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x6329464B, types, arraySizes, -1);
        return &instance;
    }
};

struct TransportPhysicsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffffffffff";
        static uint8 const arraySizes[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 10, 0x0B297C98, types, arraySizes, -1);
        return &instance;
    }
};

struct TransportRotationMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fi?";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x5FE3BC91, types, arraySizes, -1);
        return &instance;
    }
};

struct TrophyMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbhi";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x0AE68C93, types, arraySizes, -1);
        return &instance;
    }
};

struct UIExpansionDisplayInfoMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xCD407FA1, types, arraySizes, -1);
        return &instance;
    }
};

struct UIExpansionDisplayInfoIconMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xC9B51E5D, types, arraySizes, -1);
        return &instance;
    }
};

struct UiCamFbackTransmogChrRaceMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbbbh";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0xB1C9DAC4, types, arraySizes, -1);
        return &instance;
    }
};

struct UiCamFbackTransmogWeaponMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbbh";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x5148437F, types, arraySizes, -1);
        return &instance;
    }
};

struct UiCameraMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sfffbihbb";
        static uint8 const arraySizes[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 9, 0xC54B36EE, types, arraySizes, -1);
        return &instance;
    }
};

struct UiCameraTypeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x34F64532, types, arraySizes, -1);
        return &instance;
    }
};

struct UiCanvasMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihh";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x77DC2C2A, types, arraySizes, -1);
        return &instance;
    }
};

struct UiMapMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "siiiiiiiiiibi";
        static uint8 const arraySizes[13] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 13, 0x4B07CF16, types, arraySizes, -1);
        return &instance;
    }
};

struct UiMapArtMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iii";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xD85EF8B6, types, arraySizes, -1);
        return &instance;
    }
};

struct UiMapArtStyleLayerMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bhhhhffi?";
        static uint8 const arraySizes[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 9, 0xAFF6429A, types, arraySizes, -1);
        return &instance;
    }
};

struct UiMapArtTileMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbbi?";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0xBA5290E9, types, arraySizes, -1);
        return &instance;
    }
};

struct UiMapAssignmentMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fffiiiiiii";
        static uint8 const arraySizes[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 10, 0xFA919770, types, arraySizes, -1);
        return &instance;
    }
};

struct UiMapFogOfWarMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiii";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x257E044E, types, arraySizes, -1);
        return &instance;
    }
};

struct UiMapFogOfWarVisualizationMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iif";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xB8110379, types, arraySizes, -1);
        return &instance;
    }
};

struct UiMapGroupMemberMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "siiib";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x3D1DDDA1, types, arraySizes, -1);
        return &instance;
    }
};

struct UiMapLinkMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffiiii";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 6, 0x1A2F1836, types, arraySizes, -1);
        return &instance;
    }
};

struct UiMapXMapArtMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ii?";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xD74B6E49, types, arraySizes, -1);
        return &instance;
    }
};

struct UiModelSceneMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bb";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x0B9EFECA, types, arraySizes, -1);
        return &instance;
    }
};

struct UiModelSceneActorMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sfibiffff?";
        static uint8 const arraySizes[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 10, 0x8B5BF449, types, arraySizes, -1);
        return &instance;
    }
};

struct UiModelSceneActorDisplayMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiifff";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0xDD1DD903, types, arraySizes, -1);
        return &instance;
    }
};

struct UiModelSceneCameraMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sffibbfffffffff?";
        static uint8 const arraySizes[16] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 16, 0xEDFBD5A2, types, arraySizes, -1);
        return &instance;
    }
};

struct UiPartyPoseMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiii?";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 6, 0x880480BF, types, arraySizes, -1);
        return &instance;
    }
};

struct UiTextureAtlasMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ihhb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x6951B2FD, types, arraySizes, -1);
        return &instance;
    }
};

struct UiTextureAtlasMemberMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sihhhhhhbb";
        static uint8 const arraySizes[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 10, 0x4D58B085, types, arraySizes, -1);
        return &instance;
    }
};

struct UiTextureKitMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x1FC1A9C6, types, arraySizes, -1);
        return &instance;
    }
};

struct UiWidgetMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shiiii";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 6, 0xC4C60F67, types, arraySizes, -1);
        return &instance;
    }
};

struct UiWidgetConstantSourceMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hi?";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xFE573B5D, types, arraySizes, -1);
        return &instance;
    }
};

struct UiWidgetDataSourceMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hbh?";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x27BC34FD, types, arraySizes, -1);
        return &instance;
    }
};

struct UiWidgetStringSourceMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sh?";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x86CECC21, types, arraySizes, -1);
        return &instance;
    }
};

struct UiWidgetVisualizationMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "biih";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x1DB32AF9, types, arraySizes, -1);
        return &instance;
    }
};

struct UnitBloodMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iiiiii";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 6, 0x07ED968, types, arraySizes, -1);
        return &instance;
    }
};

struct UnitBloodLevelsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "b";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x684D24F4, types, arraySizes, -1);
        return &instance;
    }
};

struct UnitConditionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbbi";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x215CBCD2, types, arraySizes, -1);
        return &instance;
    }
};

struct UnitPowerBarMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ssssiihbffbhffii";
        static uint8 const arraySizes[16] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 16, 0x2640852D, types, arraySizes, -1);
        return &instance;
    }
};

struct VehicleMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ibfffffffffffbhihh";
        static uint8 const arraySizes[18] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 18, 0x221A0252, types, arraySizes, -1);
        return &instance;
    }
};

struct VehicleSeatMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ffiiibfffffffiiiiiifffffffiiihbhbhbbfffffbiiifffffffffhhhhhhh";
        static uint8 const arraySizes[61] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 61, 0x7AB200FA, types, arraySizes, -1);
        return &instance;
    }
};

struct VehicleUIIndSeatMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bff?";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x590E3162, types, arraySizes, -1);
        return &instance;
    }
};

struct VehicleUIIndicatorMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0x4B1AACBC, types, arraySizes, -1);
        return &instance;
    }
};

struct VignetteMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "siiiiffbi";
        static uint8 const arraySizes[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 9, 0xE70E083E, types, arraySizes, -1);
        return &instance;
    }
};

struct VirtualAttachmentMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sh";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0xA9D90777, types, arraySizes, -1);
        return &instance;
    }
};

struct VirtualAttachmentCustomizationMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hih";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x5812DF35, types, arraySizes, -1);
        return &instance;
    }
};

struct VocalUISoundsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbbi";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x264C4E59, types, arraySizes, -1);
        return &instance;
    }
};

struct WMOAreaTableMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sihbibbhhhihhhb";
        static uint8 const arraySizes[15] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 15, 0x60EC930B, types, arraySizes, -1);
        return &instance;
    }
};

struct WbAccessControlListMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shbbb";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0xDC9D8334, types, arraySizes, -1);
        return &instance;
    }
};

struct WbCertWhitelistMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbbb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x1524F278, types, arraySizes, -1);
        return &instance;
    }
};

struct WeaponImpactSoundsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbbiiii";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0x9C7F9BA6, types, arraySizes, -1);
        return &instance;
    }
};

struct WeaponSwingSounds2Meta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbi";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x18B6CC57, types, arraySizes, -1);
        return &instance;
    }
};

struct WeaponTrailMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ifffiffff";
        static uint8 const arraySizes[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 9, 0xB05F809A, types, arraySizes, -1);
        return &instance;
    }
};

struct WeaponTrailModelDefMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ih?";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xCE7AD194, types, arraySizes, -1);
        return &instance;
    }
};

struct WeaponTrailParamMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bfffffbbb?";
        static uint8 const arraySizes[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 10, 0xC3B87CA4, types, arraySizes, -1);
        return &instance;
    }
};

struct WeatherMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bfihbibfffffififffiiff";
        static uint8 const arraySizes[22] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 22, 0x784E91E0, types, arraySizes, -1);
        return &instance;
    }
};

struct WeatherXParticulateMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "i?";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x791A7865, types, arraySizes, -1);
        return &instance;
    }
};

struct WindSettingsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fffffffffb";
        static uint8 const arraySizes[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 10, 0xE09E01C4, types, arraySizes, -1);
        return &instance;
    }
};

struct WmoMinimapTextureMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hbbi?";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0x48CE176C, types, arraySizes, -1);
        return &instance;
    }
};

struct WorldBossLockoutMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sh";
        static uint8 const arraySizes[2] = { 1, 1 };
        static DB2Meta instance(-1, 2, 0x57E8ADB8, types, arraySizes, -1);
        return &instance;
    }
};

struct WorldChunkSoundsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hibbbb";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 6, 0xA5616A27, types, arraySizes, -1);
        return &instance;
    }
};

struct WorldEffectMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "ibbiih";
        static uint8 const arraySizes[6] = { 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 6, 0xBCB8719B, types, arraySizes, -1);
        return &instance;
    }
};

struct WorldElapsedTimerMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sbb";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0x103B8712, types, arraySizes, -1);
        return &instance;
    }
};

struct WorldMapOverlayMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "iihhiiiiiiiii";
        static uint8 const arraySizes[13] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 13, 0x837A3DAA, types, arraySizes, -1);
        return &instance;
    }
};

struct WorldMapOverlayTileMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bbbi?";
        static uint8 const arraySizes[5] = { 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 5, 0xC4DCC916, types, arraySizes, -1);
        return &instance;
    }
};

struct WorldSafeLocsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sfhf";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x6BF0D7EC, types, arraySizes, -1);
        return &instance;
    }
};

struct WorldStateExpressionMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "s";
        static uint8 const arraySizes[1] = { 1 };
        static DB2Meta instance(-1, 1, 0xF23806A6, types, arraySizes, -1);
        return &instance;
    }
};

struct WorldStateUIMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sssssihhhbiibbhhh";
        static uint8 const arraySizes[17] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 17, 0xE1F042FE, types, arraySizes, -1);
        return &instance;
    }
};

struct WorldStateZoneSoundsMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhhihhhb";
        static uint8 const arraySizes[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 8, 0x44CFA417, types, arraySizes, -1);
        return &instance;
    }
};

struct World_PVP_AreaMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "hhhhbbh";
        static uint8 const arraySizes[7] = { 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 7, 0x3F8DDC83, types, arraySizes, -1);
        return &instance;
    }
};

struct ZoneIntroMusicTableMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sibh";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x5453B51D, types, arraySizes, -1);
        return &instance;
    }
};

struct ZoneLightMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "shhb";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0xD553DE84, types, arraySizes, -1);
        return &instance;
    }
};

struct ZoneLightPointMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "fb?";
        static uint8 const arraySizes[3] = { 1, 1, 1 };
        static DB2Meta instance(-1, 3, 0xB21DA554, types, arraySizes, -1);
        return &instance;
    }
};

struct ZoneMusicMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "siii";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x9EBD4495, types, arraySizes, -1);
        return &instance;
    }
};

struct ZoneStoryMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "bii?";
        static uint8 const arraySizes[4] = { 1, 1, 1, 1 };
        static DB2Meta instance(-1, 4, 0x5BFB82E8, types, arraySizes, -1);
        return &instance;
    }
};



#endif // DB2Metadata_h__
