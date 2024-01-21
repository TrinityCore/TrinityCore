/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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
    static constexpr DB2MetaField Fields[17] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_SHORT, 1, true },
        { FT_BYTE, 1, true },
        { FT_SHORT, 1, true },
        { FT_SHORT, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_SHORT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_SHORT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1260179, 3, 17, 17, 0xFA2C0B62, Fields, 11 };
};

struct Achievement_CategoryMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_SHORT, 1, true },
        { FT_BYTE, 1, true },
    };

    static constexpr DB2Meta Instance{ 1324299, 1, 4, 4, 0xC3562871, Fields, 3 };
};

struct ActionBarGroupMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4572795, -1, 1, 1, 0xE490BC05, Fields, -1 };
};

struct ActionBarGroupEntryMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4572797, -1, 5, 4, 0x40E3832D, Fields, 4 };
};

struct AdventureJournalMeta
{
    static constexpr DB2MetaField Fields[22] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 2, false },
        { FT_BYTE, 2, false },
    };

    static constexpr DB2Meta Instance{ 1115949, -1, 22, 22, 0xC165B3AF, Fields, -1 };
};

struct AdventureMapPOIMeta
{
    static constexpr DB2MetaField Fields[12] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_FLOAT, 2, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1267070, -1, 12, 12, 0x347D1163, Fields, -1 };
};

struct AlliedRaceMeta
{
    static constexpr DB2MetaField Fields[8] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1710672, -1, 8, 8, 0xA21C7C29, Fields, -1 };
};

struct AltMinimapMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5156218, 0, 4, 4, 0x459AD0B9, Fields, -1 };
};

struct AltMinimapFiledataMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5156219, -1, 4, 4, 0xCDDE9476, Fields, -1 };
};

struct AltMinimapWMOMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5156220, -1, 2, 2, 0xEF863B4E, Fields, -1 };
};

struct AnimKitMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1304323, -1, 3, 3, 0x6287EB21, Fields, -1 };
};

struct AnimKitBoneSetMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1375433, -1, 5, 5, 0x570E50A4, Fields, -1 };
};

struct AnimKitBoneSetAliasMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1266937, -1, 2, 2, 0x8DA67A60, Fields, -1 };
};

struct AnimKitConfigMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1300872, -1, 1, 1, 0x4BB04814, Fields, -1 };
};

struct AnimKitConfigBoneSetMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1300873, -1, 3, 2, 0x2D94E68E, Fields, 2 };
};

struct AnimKitPriorityMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1266540, -1, 1, 1, 0x9CF0DCAA, Fields, -1 };
};

struct AnimKitReplacementMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1559807, 0, 5, 4, 0xCC7EFF2A, Fields, 4 };
};

struct AnimKitSegmentMeta
{
    static constexpr DB2MetaField Fields[19] =
    {
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1304324, -1, 19, 19, 0xC72DE963, Fields, 0 };
};

struct AnimReplacementMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1301100, 0, 5, 4, 0x1A7DFDFA, Fields, 4 };
};

struct AnimReplacementSetMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1284817, -1, 1, 1, 0x54CC07B7, Fields, -1 };
};

struct AnimaCableMeta
{
    static constexpr DB2MetaField Fields[35] =
    {
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3286805, -1, 35, 35, 0x1F19EFC8, Fields, -1 };
};

struct AnimaCylinderMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3286804, -1, 7, 7, 0xA8314AE6, Fields, -1 };
};

struct AnimaMaterialMeta
{
    static constexpr DB2MetaField Fields[31] =
    {
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 3, true },
    };

    static constexpr DB2Meta Instance{ 3153990, -1, 31, 31, 0xEA8F56B4, Fields, -1 };
};

struct AnimationDataMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 2, true },
    };

    static constexpr DB2Meta Instance{ 1375431, -1, 4, 4, 0xE4D647E7, Fields, -1 };
};

struct AreaConditionalDataMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2123730, 1, 5, 4, 0xE7DA5527, Fields, 4 };
};

struct AreaFarClipOverrideMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1537162, -1, 4, 4, 0xA9F91574, Fields, -1 };
};

struct AreaGroupMemberMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1093406, -1, 2, 1, 0x93C93492, Fields, 1 };
};

struct AreaPOIMeta
{
    static constexpr DB2MetaField Fields[21] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_FLOAT, 3, true },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, true },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, true },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1000630, 2, 21, 21, 0x605253EC, Fields, 12 };
};

struct AreaPOIStateMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_STRING, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1000631, -1, 5, 4, 0xC236B11E, Fields, 4 };
};

struct AreaTableMeta
{
    static constexpr DB2MetaField Fields[23] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_STRING, 1, true },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
        { FT_SHORT, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 2, true },
        { FT_SHORT, 4, false },
    };

    static constexpr DB2Meta Instance{ 1353545, -1, 23, 23, 0xCD6850F0, Fields, -1 };
};

struct AreaTriggerMeta
{
    static constexpr DB2MetaField Fields[15] =
    {
        { FT_FLOAT, 3, true },
        { FT_INT, 1, false },
        { FT_SHORT, 1, true },
        { FT_INT, 1, true },
        { FT_SHORT, 1, true },
        { FT_SHORT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_BYTE, 1, true },
        { FT_SHORT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
    };

    static constexpr DB2Meta Instance{ 1354401, 1, 15, 15, 0x755974EC, Fields, 2 };
};

struct AreaTriggerActionSetMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1352378, -1, 1, 1, 0x3CC972C6, Fields, -1 };
};

struct AreaTriggerBoundedPlaneMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_FLOAT, 2, true },
    };

    static constexpr DB2Meta Instance{ 4266572, -1, 1, 1, 0xAFEA6110, Fields, -1 };
};

struct AreaTriggerBoxMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_FLOAT, 3, true },
    };

    static constexpr DB2Meta Instance{ 1332554, -1, 1, 1, 0x0D4BC031, Fields, -1 };
};

struct AreaTriggerCreatePropertiesMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_BYTE, 1, true },
        { FT_SHORT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1937227, -1, 3, 3, 0x95719F5A, Fields, -1 };
};

struct AreaTriggerCylinderMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1121943, -1, 3, 3, 0xAF2720AC, Fields, -1 };
};

struct AreaTriggerDiskMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4223661, -1, 4, 4, 0x5C424FAE, Fields, -1 };
};

struct AreaTriggerSphereMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1315630, -1, 1, 1, 0xAE82194A, Fields, -1 };
};

struct ArenaTrackedItemMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5226140, -1, 3, 3, 0x953C54A9, Fields, 1 };
};

struct ArmorLocationMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1284818, -1, 5, 5, 0x6FA608FB, Fields, -1 };
};

struct ArtifactMeta
{
    static constexpr DB2MetaField Fields[11] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1007934, 1, 11, 11, 0x7F55AC46, Fields, -1 };
};

struct ArtifactAppearanceMeta
{
    static constexpr DB2MetaField Fields[16] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1116407, 1, 16, 16, 0x5D77042E, Fields, 2 };
};

struct ArtifactAppearanceSetMeta
{
    static constexpr DB2MetaField Fields[9] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1116408, 2, 9, 8, 0xE8D3AE79, Fields, 8 };
};

struct ArtifactCategoryMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_SHORT, 1, true },
        { FT_SHORT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1376210, -1, 2, 2, 0xAA92CE1F, Fields, -1 };
};

struct ArtifactItemToTransmogMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2029780, -1, 3, 3, 0xEB962C15, Fields, 0 };
};

struct ArtifactPowerMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { FT_FLOAT, 2, true },
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1007937, 1, 7, 7, 0x421879C5, Fields, 2 };
};

struct ArtifactPowerLinkMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1133731, -1, 2, 2, 0xD2E6E484, Fields, -1 };
};

struct ArtifactPowerPickerMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1597467, -1, 1, 1, 0xAA18FF1B, Fields, -1 };
};

struct ArtifactPowerRankMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1261405, -1, 5, 4, 0xD1061B77, Fields, 4 };
};

struct ArtifactQuestXPMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 10, false },
    };

    static constexpr DB2Meta Instance{ 1036203, -1, 1, 1, 0xBFB6413C, Fields, -1 };
};

struct ArtifactTierMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1600114, -1, 5, 5, 0x91AD7570, Fields, -1 };
};

struct ArtifactUnlockMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1094540, -1, 5, 4, 0xAED3BBEA, Fields, 4 };
};

struct AuctionHouseMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_STRING, 1, true },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1237439, -1, 4, 4, 0x8925F061, Fields, -1 };
};

struct AuctionHouseCategoryMeta
{
    static constexpr DB2MetaField Fields[10] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 4366440, 2, 10, 10, 0x4945050B, Fields, 7 };
};

struct AzeriteEmpoweredItemMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1846046, -1, 3, 3, 0xA33729C4, Fields, -1 };
};

struct AzeriteEssenceMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2829665, -1, 3, 3, 0x78739DBC, Fields, -1 };
};

struct AzeriteEssencePowerMeta
{
    static constexpr DB2MetaField Fields[8] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2829666, -1, 8, 8, 0x054DFF02, Fields, -1 };
};

struct AzeriteItemMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1846048, -1, 1, 1, 0x358673DD, Fields, -1 };
};

struct AzeriteItemMilestonePowerMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1915395, -1, 4, 4, 0x82DD9DC4, Fields, -1 };
};

struct AzeriteKnowledgeMultiplierMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3148050, -1, 1, 1, 0x9DCCF58B, Fields, -1 };
};

struct AzeriteLevelInfoMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_LONG, 1, false },
        { FT_LONG, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3147968, -1, 3, 3, 0xFB87ABE1, Fields, -1 };
};

struct AzeritePowerMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1846044, -1, 4, 4, 0x20D09908, Fields, -1 };
};

struct AzeritePowerSetMemberMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1846040, -1, 5, 5, 0xDD075CEB, Fields, 0 };
};

struct AzeriteTierUnlockMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1846043, -1, 4, 3, 0x63D128C5, Fields, 3 };
};

struct AzeriteTierUnlockSetMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2446322, -1, 1, 1, 0x0E377BCA, Fields, -1 };
};

struct AzeriteUnlockMappingMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2564314, -1, 5, 4, 0x22A21AA1, Fields, 4 };
};

struct BankBagSlotPricesMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1284819, -1, 1, 1, 0x972171FF, Fields, -1 };
};

struct BannedAddonsMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1373459, -1, 3, 3, 0x3BE3470D, Fields, -1 };
};

struct BarberShopStyleMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_BYTE, 1, false },
        { FT_FLOAT, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1237437, -1, 7, 7, 0xD7B2816B, Fields, -1 };
};

struct BarrageEffectMeta
{
    static constexpr DB2MetaField Fields[12] =
    {
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2499852, -1, 12, 12, 0x26B3A638, Fields, -1 };
};

struct BattlePetAbilityMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 841610, -1, 7, 7, 0xA35F647F, Fields, -1 };
};

struct BattlePetAbilityEffectMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 6, true },
    };

    static constexpr DB2Meta Instance{ 801575, 0, 7, 7, 0x6E6DF628, Fields, 1 };
};

struct BattlePetAbilityStateMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 801576, -1, 3, 2, 0xAAB55D53, Fields, 2 };
};

struct BattlePetAbilityTurnMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, true },
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 801577, 0, 6, 6, 0x4BFF1620, Fields, 1 };
};

struct BattlePetBreedQualityMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 801578, -1, 3, 3, 0x13065D19, Fields, -1 };
};

struct BattlePetBreedStateMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 801579, -1, 3, 2, 0xF449E0D3, Fields, 2 };
};

struct BattlePetDisplayOverrideMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1802988, -1, 4, 3, 0x9FADCDB4, Fields, 3 };
};

struct BattlePetEffectPropertiesMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_STRING_NOT_LOCALIZED, 6, true },
        { FT_SHORT, 1, false },
        { FT_BYTE, 6, false },
    };

    static constexpr DB2Meta Instance{ 801580, -1, 3, 3, 0x830F4FD2, Fields, -1 };
};

struct BattlePetNPCTeamMemberMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_STRING, 1, true },
    };

    static constexpr DB2Meta Instance{ 841648, -1, 1, 1, 0xB0DD8F60, Fields, -1 };
};

struct BattlePetSpeciesMeta
{
    static constexpr DB2MetaField Fields[12] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 841622, 2, 12, 12, 0x7E3C11F2, Fields, -1 };
};

struct BattlePetSpeciesStateMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 801581, -1, 3, 2, 0x3D1D7C9D, Fields, 2 };
};

struct BattlePetSpeciesXAbilityMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 801582, -1, 4, 3, 0x98E73E87, Fields, 3 };
};

struct BattlePetSpeciesXCovenantMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3669304, -1, 2, 1, 0xD9C25504, Fields, 1 };
};

struct BattlePetStateMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 801583, -1, 3, 3, 0x59238591, Fields, -1 };
};

struct BattlePetVisualMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 801584, -1, 7, 7, 0x55227F53, Fields, -1 };
};

struct BattlemasterListMeta
{
    static constexpr DB2MetaField Fields[17] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_SHORT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_SHORT, 16, true },
    };

    static constexpr DB2Meta Instance{ 1360265, -1, 17, 17, 0x145B6F18, Fields, -1 };
};

struct BeamEffectMeta
{
    static constexpr DB2MetaField Fields[10] =
    {
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1525607, -1, 10, 10, 0xF1E61217, Fields, -1 };
};

struct BeckonTriggerMeta
{
    static constexpr DB2MetaField Fields[9] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3491563, -1, 9, 8, 0x7DF24A7B, Fields, 8 };
};

struct BoneWindModifierModelMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1467254, -1, 2, 2, 0x1487387B, Fields, 0 };
};

struct BoneWindModifiersMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_FLOAT, 3, true },
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1416756, -1, 2, 2, 0x9FEA042E, Fields, -1 };
};

struct BonusRollMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1983274, -1, 4, 4, 0xDEC02884, Fields, -1 };
};

struct BountyMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1367866, -1, 5, 4, 0xD23ECB64, Fields, 4 };
};

struct BountySetMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1367865, -1, 2, 2, 0x501CD5A6, Fields, -1 };
};

struct BroadcastTextMeta
{
    static constexpr DB2MetaField Fields[12] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 2, false },
        { FT_SHORT, 3, false },
        { FT_SHORT, 3, false },
    };

    static constexpr DB2Meta Instance{ 841604, 2, 12, 12, 0x9FB1FE4B, Fields, -1 };
};

struct BroadcastTextDurationMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2166900, -1, 3, 3, 0xFFDF8DBB, Fields, 0 };
};

struct CameraEffectMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1117695, -1, 1, 1, 0x8E37DA6F, Fields, -1 };
};

struct CameraEffectEntryMeta
{
    static constexpr DB2MetaField Fields[16] =
    {
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1117696, -1, 16, 15, 0x10047B37, Fields, 15 };
};

struct CameraModeMeta
{
    static constexpr DB2MetaField Fields[12] =
    {
        { FT_FLOAT, 3, true },
        { FT_FLOAT, 3, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1343308, -1, 12, 12, 0x5F08423B, Fields, -1 };
};

struct CampaignMeta
{
    static constexpr DB2MetaField Fields[13] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2031607, -1, 13, 13, 0x49228B74, Fields, -1 };
};

struct CampaignXConditionMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2031611, -1, 5, 4, 0x3B0D3F8C, Fields, 4 };
};

struct CampaignXQuestLineMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 2036722, -1, 3, 3, 0x10BF2FCD, Fields, 0 };
};

struct CastableRaidBuffsMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1283018, -1, 2, 1, 0xBEB03EF2, Fields, 1 };
};

struct CelestialBodyMeta
{
    static constexpr DB2MetaField Fields[14] =
    {
        { FT_FLOAT, 3, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_SHORT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 2, true },
        { FT_FLOAT, 2, true },
        { FT_INT, 2, true },
        { FT_FLOAT, 2, true },
        { FT_FLOAT, 2, true },
    };

    static constexpr DB2Meta Instance{ 1592470, -1, 14, 14, 0x3F9BA1DD, Fields, -1 };
};

struct Cfg_CategoriesMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_STRING, 1, true },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, true },
    };

    static constexpr DB2Meta Instance{ 1068162, -1, 6, 6, 0x37159FFC, Fields, -1 };
};

struct Cfg_ConfigsMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1080949, -1, 4, 4, 0xF7B1322B, Fields, -1 };
};

struct Cfg_RegionsMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_SHORT, 1, false },
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1082876, -1, 5, 5, 0xFC93C56C, Fields, -1 };
};

struct ChallengeModeItemBonusOverrideMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2965645, -1, 7, 6, 0xB5EA51A7, Fields, 6 };
};

struct CharBaseInfoMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1343386, -1, 3, 3, 0x862C2392, Fields, -1 };
};

struct CharBaseSectionMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1375798, -1, 3, 3, 0xC0783DC4, Fields, -1 };
};

struct CharComponentTextureLayoutsMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1360262, -1, 2, 2, 0x7F7D8978, Fields, -1 };
};

struct CharComponentTextureSectionsMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1360263, -1, 7, 7, 0x5F538036, Fields, 0 };
};

struct CharHairGeosetsMeta
{
    static constexpr DB2MetaField Fields[11] =
    {
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
    };

    static constexpr DB2Meta Instance{ 1256914, -1, 11, 11, 0x69E34903, Fields, 0 };
};

struct CharSectionConditionMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2388725, -1, 6, 5, 0x5E6E8D02, Fields, 5 };
};

struct CharShipmentMeta
{
    static constexpr DB2MetaField Fields[9] =
    {
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 972425, -1, 9, 9, 0x604F76F0, Fields, 0 };
};

struct CharShipmentContainerMeta
{
    static constexpr DB2MetaField Fields[16] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, true },
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 972405, -1, 16, 16, 0xBE1415EF, Fields, -1 };
};

struct CharStartKitMeta
{
    static constexpr DB2MetaField Fields[16] =
    {
        { FT_STRING, 1, true },
        { FT_FLOAT, 3, true },
        { FT_FLOAT, 3, true },
        { FT_FLOAT, 3, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3055696, -1, 16, 15, 0x00B44453, Fields, 15 };
};

struct CharStartOutfitMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 24, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1237591, -1, 7, 6, 0x3CF88584, Fields, 6 };
};

struct CharTitlesMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_SHORT, 1, true },
        { FT_BYTE, 1, true },
    };

    static constexpr DB2Meta Instance{ 1349054, -1, 4, 4, 0xD7398A05, Fields, -1 };
};

struct CharacterFaceBoneSetMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1028733, -1, 5, 4, 0xD21C8EC2, Fields, 4 };
};

struct CharacterFacialHairStylesMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 5, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1369752, -1, 4, 4, 0x4ED873D6, Fields, -1 };
};

struct CharacterLoadoutMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_LONG, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
    };

    static constexpr DB2Meta Instance{ 1344281, -1, 4, 4, 0xEF41DC0A, Fields, -1 };
};

struct CharacterLoadoutItemMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_SHORT, 1, false },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1302846, -1, 2, 2, 0x24843CD8, Fields, 0 };
};

struct CharacterLoadoutPetMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3724843, -1, 4, 3, 0x0E32BEB6, Fields, 3 };
};

struct CharacterServiceInfoMeta
{
    static constexpr DB2MetaField Fields[12] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1815417, -1, 12, 12, 0x7C1EF738, Fields, -1 };
};

struct ChatChannelsMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1345278, -1, 5, 5, 0x905CF2AE, Fields, -1 };
};

struct ChatProfanityMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_BYTE, 1, true },
    };

    static constexpr DB2Meta Instance{ 1117084, -1, 2, 2, 0xF05E7E22, Fields, -1 };
};

struct ChrClassRaceSexMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1306188, -1, 6, 6, 0xCE5A498A, Fields, -1 };
};

struct ChrClassTitleMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1267497, -1, 3, 3, 0x7F14E4E9, Fields, -1 };
};

struct ChrClassUIChrModelInfoMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_FLOAT, 3, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3754770, -1, 4, 4, 0xC4043CA4, Fields, -1 };
};

struct ChrClassUIDisplayMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1316515, -1, 3, 3, 0x89E07C1C, Fields, -1 };
};

struct ChrClassVillainMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_STRING, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, true },
    };

    static constexpr DB2Meta Instance{ 1267498, -1, 3, 3, 0x24AF0FFD, Fields, -1 };
};

struct ChrClassesMeta
{
    static constexpr DB2MetaField Fields[39] =
    {
        { FT_STRING, 1, true },
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1361031, 10, 39, 39, 0xA9224C3E, Fields, -1 };
};

struct ChrClassesXPowerTypesMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1121420, -1, 2, 1, 0x71C99BFD, Fields, 1 };
};

struct ChrCreateClassAnimTargetMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3671168, -1, 7, 6, 0x3AC1561C, Fields, 6 };
};

struct ChrCreateClassAnimTargetInfoMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3671169, 0, 4, 3, 0x9CC6607E, Fields, 3 };
};

struct ChrCustClientChoiceConversionMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3590348, -1, 3, 2, 0xF1AE177C, Fields, 2 };
};

struct ChrCustGeoComponentLinkMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5387095, -1, 1, 1, 0xB7E1E35F, Fields, -1 };
};

struct ChrCustItemGeoModifyMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3952714, -1, 3, 3, 0x09A78C46, Fields, -1 };
};

struct ChrCustomizationMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 3, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1611874, -1, 7, 6, 0x3E81F9D4, Fields, 6 };
};

struct ChrCustomizationBoneSetMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3460181, -1, 2, 2, 0xF45B8890, Fields, -1 };
};

struct ChrCustomizationCategoryMeta
{
    static constexpr DB2MetaField Fields[8] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3526439, -1, 8, 8, 0x885434EF, Fields, -1 };
};

struct ChrCustomizationChoiceMeta
{
    static constexpr DB2MetaField Fields[11] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 2, true },
    };

    static constexpr DB2Meta Instance{ 3450554, 1, 11, 11, 0xAA548AE1, Fields, 2 };
};

struct ChrCustomizationCondModelMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 4, true },
    };

    static constexpr DB2Meta Instance{ 3460182, -1, 2, 2, 0x90F7861A, Fields, -1 };
};

struct ChrCustomizationConversionMeta
{
    static constexpr DB2MetaField Fields[8] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3463337, -1, 8, 8, 0x685C2AB5, Fields, 4 };
};

struct ChrCustomizationDisplayInfoMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3593032, -1, 5, 5, 0x5C04D385, Fields, -1 };
};

struct ChrCustomizationElementMeta
{
    static constexpr DB2MetaField Fields[13] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3512765, -1, 13, 13, 0x79DFED35, Fields, -1 };
};

struct ChrCustomizationGeosetMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3456171, -1, 3, 3, 0x9D95412A, Fields, -1 };
};

struct ChrCustomizationGlyphPetMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5347591, -1, 6, 6, 0xD58B0F29, Fields, -1 };
};

struct ChrCustomizationMaterialMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3459652, -1, 2, 2, 0x68D0798C, Fields, -1 };
};

struct ChrCustomizationOptionMeta
{
    static constexpr DB2MetaField Fields[13] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3384247, 1, 13, 13, 0x77A321D5, Fields, 4 };
};

struct ChrCustomizationReqMeta
{
    static constexpr DB2MetaField Fields[8] =
    {
        { FT_LONG, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3450453, -1, 8, 8, 0x1BF53EBE, Fields, -1 };
};

struct ChrCustomizationReqChoiceMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3580359, -1, 2, 1, 0x52D624D9, Fields, 1 };
};

struct ChrCustomizationSkinnedModelMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3460183, -1, 5, 5, 0xB02FB5F3, Fields, -1 };
};

struct ChrCustomizationVisReqMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4724136, -1, 2, 2, 0xF5C3ABD9, Fields, -1 };
};

struct ChrCustomizationVoiceMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_BYTE, 1, true },
    };

    static constexpr DB2Meta Instance{ 4672833, -1, 1, 1, 0x647E0FF4, Fields, -1 };
};

struct ChrModelMeta
{
    static constexpr DB2MetaField Fields[17] =
    {
        { FT_FLOAT, 3, true },
        { FT_FLOAT, 3, true },
        { FT_INT, 1, false },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3384313, 2, 17, 17, 0x79F06E99, Fields, 4 };
};

struct ChrModelMaterialMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3566562, 0, 7, 7, 0xB4AB9DAB, Fields, 1 };
};

struct ChrModelTextureLayerMeta
{
    static constexpr DB2MetaField Fields[9] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 3, true },
        { FT_INT, 2, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3548976, -1, 9, 8, 0x0CE385AF, Fields, 8 };
};

struct ChrRaceRacialAbilityMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3507821, -1, 6, 5, 0xB6115535, Fields, 5 };
};

struct ChrRaceXChrModelMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3490304, -1, 4, 4, 0xE0B5AE0D, Fields, 0 };
};

struct ChrRacesMeta
{
    static constexpr DB2MetaField Fields[52] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 3, true },
        { FT_INT, 3, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 3, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 3, true },
        { FT_FLOAT, 3, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
    };

    static constexpr DB2Meta Instance{ 1305311, -1, 52, 52, 0xCD316971, Fields, -1 };
};

struct ChrRacesCreateScreenIconMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4566929, 0, 4, 4, 0x892075D2, Fields, 1 };
};

struct ChrRacesPingMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5320971, -1, 4, 4, 0xEEFB570B, Fields, -1 };
};

struct ChrSelectBackgroundCDIMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4195187, -1, 3, 3, 0x5C22B87C, Fields, -1 };
};

struct ChrSpecializationMeta
{
    static constexpr DB2MetaField Fields[13] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 2, true },
    };

    static constexpr DB2Meta Instance{ 1343390, 3, 13, 13, 0x1F1A9A8F, Fields, 4 };
};

struct ChrUpgradeBucketMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 984529, 0, 3, 2, 0x5DD8D93F, Fields, 2 };
};

struct ChrUpgradeBucketSpellMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 984528, -1, 2, 1, 0xD5209FCF, Fields, 1 };
};

struct ChrUpgradeTierMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 984530, 1, 4, 4, 0xC4B6C048, Fields, -1 };
};

struct CinematicCameraMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_FLOAT, 3, true },
        { FT_INT, 1, false },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1294214, -1, 5, 5, 0x4B3DF171, Fields, -1 };
};

struct CinematicSequencesMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, false },
        { FT_SHORT, 8, false },
    };

    static constexpr DB2Meta Instance{ 1134583, -1, 2, 2, 0x32B8FB41, Fields, -1 };
};

struct ClientSceneEffectMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1939843, -1, 1, 1, 0x8C4BEE67, Fields, -1 };
};

struct CloakDampeningMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 5, true },
        { FT_FLOAT, 5, true },
        { FT_FLOAT, 2, true },
        { FT_FLOAT, 2, true },
    };

    static constexpr DB2Meta Instance{ 1465903, -1, 7, 7, 0x1C66DB37, Fields, -1 };
};

struct CloneEffectMeta
{
    static constexpr DB2MetaField Fields[8] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2175218, -1, 8, 8, 0xC045A5E8, Fields, -1 };
};

struct CollectableSourceEncounterMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5152111, 0, 2, 1, 0x4FE04777, Fields, 1 };
};

struct CollectableSourceEncounterSparseMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5152908, -1, 3, 2, 0x2283C289, Fields, 2 };
};

struct CollectableSourceInfoMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5152112, 1, 4, 4, 0xF20F935A, Fields, -1 };
};

struct CollectableSourceQuestMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5205183, -1, 1, 1, 0xED2B4E47, Fields, -1 };
};

struct CollectableSourceQuestSparseMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 3, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5205600, -1, 5, 4, 0xF3A48090, Fields, 4 };
};

struct CollectableSourceVendorMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5163410, 0, 3, 2, 0x79CFD6DF, Fields, 2 };
};

struct CollectableSourceVendorSparseMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { FT_INT, 1, true },
        { FT_FLOAT, 3, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5159897, -1, 7, 6, 0xD0863376, Fields, 6 };
};

struct CombatConditionMeta
{
    static constexpr DB2MetaField Fields[11] =
    {
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_SHORT, 2, false },
        { FT_BYTE, 2, false },
        { FT_BYTE, 2, false },
        { FT_SHORT, 2, false },
        { FT_BYTE, 2, false },
        { FT_BYTE, 2, false },
    };

    static constexpr DB2Meta Instance{ 1120958, -1, 11, 11, 0x5CA63D01, Fields, -1 };
};

struct CommentatorIndirectSpellMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3067644, -1, 3, 2, 0x415C0D91, Fields, 2 };
};

struct CommentatorStartLocationMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_FLOAT, 3, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1664251, -1, 2, 2, 0x36EDE137, Fields, -1 };
};

struct CommentatorTrackedCooldownMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1661584, -1, 6, 5, 0x43CD7801, Fields, 5 };
};

struct CommunityIconMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2098645, -1, 2, 2, 0xAD2830F3, Fields, -1 };
};

struct ComponentModelFileDataMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, true },
    };

    static constexpr DB2Meta Instance{ 1349053, -1, 4, 4, 0x34E0ADCF, Fields, -1 };
};

struct ComponentTextureFileDataMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1278239, -1, 3, 3, 0x2DD855B4, Fields, -1 };
};

struct ConditionalChrModelMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5211412, 0, 6, 6, 0xACE42127, Fields, 1 };
};

struct ConditionalContentTuningMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3501965, -1, 4, 3, 0x8DF8B6EC, Fields, 3 };
};

struct ConditionalItemAppearanceMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5345180, -1, 6, 5, 0x46A8294C, Fields, 5 };
};

struct ConfigurationWarningMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1709409, -1, 2, 2, 0x6E7F031C, Fields, -1 };
};

struct ContentRestrictionRuleMeta
{
    static constexpr DB2MetaField Fields[8] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4668112, -1, 8, 7, 0x5A5B939C, Fields, 7 };
};

struct ContentRestrictionRuleSetMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4281307, 0, 3, 3, 0x7AA89A89, Fields, -1 };
};

struct ContentTuningMeta
{
    static constexpr DB2MetaField Fields[12] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1962930, -1, 12, 12, 0x3E5D4B74, Fields, -1 };
};

struct ContentTuningXExpectedMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2976765, -1, 4, 3, 0x886CD205, Fields, 3 };
};

struct ContentTuningXLabelMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4659576, -1, 2, 1, 0x62982D18, Fields, 1 };
};

struct ContributionMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 4, true },
    };

    static constexpr DB2Meta Instance{ 1587153, -1, 6, 6, 0xB773D94B, Fields, 2 };
};

struct ContributionStyleMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2143633, -1, 7, 7, 0x001E87C8, Fields, -1 };
};

struct ContributionStyleContainerMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 5, true },
    };

    static constexpr DB2Meta Instance{ 2143634, -1, 1, 1, 0xBCE21C5E, Fields, -1 };
};

struct ConversationLineMeta
{
    static constexpr DB2MetaField Fields[9] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1260801, -1, 9, 9, 0xD199D7B9, Fields, -1 };
};

struct CorruptionEffectsMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3220711, -1, 4, 4, 0xCD3D02D2, Fields, -1 };
};

struct CovenantMeta
{
    static constexpr DB2MetaField Fields[10] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3384973, -1, 10, 10, 0x1918652F, Fields, -1 };
};

struct CraftingDataMeta
{
    static constexpr DB2MetaField Fields[16] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4545611, 0, 16, 16, 0xE8316F5C, Fields, -1 };
};

struct CraftingDataEnchantQualityMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4659601, -1, 4, 3, 0x31677DFD, Fields, 3 };
};

struct CraftingDataItemQualityMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4545612, -1, 2, 1, 0x25756325, Fields, 1 };
};

struct CraftingDifficultyMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4373536, -1, 5, 5, 0xA38AD18A, Fields, -1 };
};

struct CraftingDifficultyQualityMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4373537, 0, 6, 5, 0xC1A830DE, Fields, 5 };
};

struct CraftingOrderMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4529122, -1, 3, 3, 0xB84EEC7E, Fields, -1 };
};

struct CraftingOrderHouseMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_FLOAT, 1, true },
        { FT_INT, 3, true },
    };

    static constexpr DB2Meta Instance{ 4688652, -1, 2, 2, 0xAC451DAB, Fields, -1 };
};

struct CraftingQualityMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4373538, -1, 1, 1, 0xE97DD64C, Fields, -1 };
};

struct CraftingReagentEffectMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4541803, -1, 3, 2, 0xC85861E7, Fields, 2 };
};

struct CraftingReagentQualityMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4382197, 0, 6, 5, 0xCE4DB0CC, Fields, 5 };
};

struct CraftingReagentRequirementMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5049814, -1, 2, 1, 0x3F971F7F, Fields, 1 };
};

struct CreatureMeta
{
    static constexpr DB2MetaField Fields[11] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 4, true },
        { FT_FLOAT, 4, true },
        { FT_INT, 3, true },
    };

    static constexpr DB2Meta Instance{ 841631, -1, 11, 11, 0x8246E41C, Fields, -1 };
};

struct CreatureDifficultyMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 8, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 879282, -1, 6, 5, 0xCDB617FB, Fields, 5 };
};

struct CreatureDifficultyTreasureMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4044373, -1, 3, 2, 0x69361BEA, Fields, 2 };
};

struct CreatureDispXUiCameraMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1146692, -1, 2, 2, 0xA8582ED5, Fields, -1 };
};

struct CreatureDisplayInfoMeta
{
    static constexpr DB2MetaField Fields[25] =
    {
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, true },
        { FT_FLOAT, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 4, true },
    };

    static constexpr DB2Meta Instance{ 1108759, 0, 25, 25, 0x357FF9CD, Fields, -1 };
};

struct CreatureDisplayInfoCondMeta
{
    static constexpr DB2MetaField Fields[8] =
    {
        { FT_LONG, 1, true },
        { FT_INT, 1, false },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 4, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1332686, 1, 8, 7, 0x5EAC4BFD, Fields, 7 };
};

struct CreatureDisplayInfoCondXChoiceMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3670439, -1, 2, 2, 0x3B360250, Fields, 0 };
};

struct CreatureDisplayInfoEvtMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1586882, -1, 4, 3, 0xFD7C9FA8, Fields, 3 };
};

struct CreatureDisplayInfoExtraMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { FT_INT, 1, false },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1264997, 0, 7, 7, 0x8FCCFF0C, Fields, -1 };
};

struct CreatureDisplayInfoGeosetDataMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1720141, -1, 3, 2, 0x6A7C8343, Fields, 2 };
};

struct CreatureDisplayInfoOptionMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3692043, -1, 3, 2, 0xDBD77820, Fields, 2 };
};

struct CreatureDisplayInfoTrnMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1146698, -1, 6, 5, 0x7B61A667, Fields, 5 };
};

struct CreatureFamilyMeta
{
    static constexpr DB2MetaField Fields[9] =
    {
        { FT_STRING, 1, true },
        { FT_FLOAT, 1, true },
        { FT_BYTE, 1, true },
        { FT_FLOAT, 1, true },
        { FT_BYTE, 1, true },
        { FT_SHORT, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_SHORT, 2, true },
    };

    static constexpr DB2Meta Instance{ 1351351, -1, 9, 9, 0x78019FD1, Fields, -1 };
};

struct CreatureImmunitiesMeta
{
    static constexpr DB2MetaField Fields[9] =
    {
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 2, true },
        { FT_INT, 10, false },
        { FT_INT, 20, false },
    };

    static constexpr DB2Meta Instance{ 1131322, -1, 9, 9, 0x1B605529, Fields, -1 };
};

struct CreatureLabelMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3055733, -1, 2, 1, 0xF7C12CAC, Fields, 1 };
};

struct CreatureModelDataMeta
{
    static constexpr DB2MetaField Fields[33] =
    {
        { FT_FLOAT, 6, true },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, false },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_BYTE, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 2, true },
    };

    static constexpr DB2Meta Instance{ 1365368, -1, 33, 33, 0xCD28D54B, Fields, -1 };
};

struct CreatureMovementInfoMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1125666, -1, 1, 1, 0x4A558056, Fields, -1 };
};

struct CreatureSoundDataMeta
{
    static constexpr DB2MetaField Fields[39] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 5, false },
        { FT_INT, 4, false },
    };

    static constexpr DB2Meta Instance{ 1344466, 0, 39, 39, 0x6EF96ED7, Fields, -1 };
};

struct CreatureSoundFidgetMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4178576, -1, 3, 2, 0xECFBE76A, Fields, 2 };
};

struct CreatureTypeMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_STRING, 1, true },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1131315, -1, 2, 2, 0xBDB743EB, Fields, -1 };
};

struct CreatureXContributionMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1587158, -1, 2, 1, 0x08F0A453, Fields, 1 };
};

struct CreatureXDisplayInfoMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1864302, -1, 5, 4, 0xF5C33B70, Fields, 4 };
};

struct CreatureXUiWidgetSetMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3055738, -1, 3, 3, 0xD5F78F74, Fields, -1 };
};

struct CriteriaMeta
{
    static constexpr DB2MetaField Fields[11] =
    {
        { FT_SHORT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_SHORT, 1, true },
        { FT_BYTE, 1, true },
    };

    static constexpr DB2Meta Instance{ 1263817, -1, 11, 11, 0x2C87F5ED, Fields, -1 };
};

struct CriteriaTreeMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1263818, -1, 7, 7, 0xFDD54C23, Fields, -1 };
};

struct CriteriaTreeXEffectMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_SHORT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1345969, -1, 2, 1, 0xD09A14A8, Fields, 1 };
};

struct CurrencyCategoryMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1125667, -1, 3, 3, 0xDEE5E915, Fields, -1 };
};

struct CurrencyContainerMeta
{
    static constexpr DB2MetaField Fields[8] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1934603, -1, 8, 7, 0xBF622379, Fields, 7 };
};

struct CurrencyTypesMeta
{
    static constexpr DB2MetaField Fields[17] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 2, true },
    };

    static constexpr DB2Meta Instance{ 1095531, -1, 17, 17, 0x2085AB84, Fields, -1 };
};

struct CurveMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 892585, 0, 3, 3, 0x58B43CA3, Fields, -1 };
};

struct CurvePointMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_FLOAT, 2, true },
        { FT_FLOAT, 2, true },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 892586, 2, 5, 5, 0x861A11A0, Fields, 3 };
};

struct DeathThudLookupsMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1279415, -1, 4, 4, 0xEA2448BE, Fields, -1 };
};

struct DecalPropertiesMeta
{
    static constexpr DB2MetaField Fields[25] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 4, true },
        { FT_FLOAT, 4, true },
        { FT_FLOAT, 4, true },
    };

    static constexpr DB2Meta Instance{ 1278176, -1, 25, 25, 0x1E49EE02, Fields, -1 };
};

struct DeclinedWordMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1279100, 1, 2, 2, 0xD648129D, Fields, -1 };
};

struct DeclinedWordCasesMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1279099, -1, 3, 2, 0x626BC51A, Fields, 2 };
};

struct DestructibleModelDataMeta
{
    static constexpr DB2MetaField Fields[22] =
    {
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
    };

    static constexpr DB2Meta Instance{ 1122116, -1, 22, 22, 0x7BC9B1D9, Fields, -1 };
};

struct DeviceBlacklistMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 922722, -1, 2, 2, 0x1458ACA1, Fields, -1 };
};

struct DifficultyMeta
{
    static constexpr DB2MetaField Fields[13] =
    {
        { FT_STRING, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1352127, -1, 13, 13, 0xD3044EE8, Fields, -1 };
};

struct DisplaySeasonMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4279827, 1, 6, 6, 0x307B0C4C, Fields, -1 };
};

struct DissolveEffectMeta
{
    static constexpr DB2MetaField Fields[21] =
    {
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1304325, -1, 21, 21, 0xE41A3D3D, Fields, -1 };
};

struct DriverBlacklistMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 922720, -1, 7, 7, 0x3FDF91BC, Fields, -1 };
};

struct DungeonEncounterMeta
{
    static constexpr DB2MetaField Fields[10] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_SHORT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1347279, 1, 10, 10, 0x970800CA, Fields, 2 };
};

struct DurabilityCostsMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_SHORT, 21, false },
        { FT_SHORT, 8, false },
    };

    static constexpr DB2Meta Instance{ 1283019, -1, 2, 2, 0x3DBDFDD1, Fields, -1 };
};

struct DurabilityQualityMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1130268, -1, 1, 1, 0xD4F6FFC8, Fields, -1 };
};

struct EdgeGlowEffectMeta
{
    static constexpr DB2MetaField Fields[13] =
    {
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_BYTE, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1387381, -1, 13, 13, 0x1589CA63, Fields, -1 };
};

struct EmotesMeta
{
    static constexpr DB2MetaField Fields[9] =
    {
        { FT_LONG, 1, true },
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1343602, -1, 9, 9, 0xC2B2FDD1, Fields, -1 };
};

struct EmotesTextMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1347273, -1, 2, 2, 0x8C749D28, Fields, -1 };
};

struct EmotesTextDataMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_STRING, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1283024, -1, 3, 2, 0x3E78FC97, Fields, 2 };
};

struct EmotesTextSoundMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1286524, -1, 5, 4, 0xF058B2EF, Fields, 4 };
};

struct EnvironmentalDamageMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1278398, -1, 2, 2, 0x0D289832, Fields, -1 };
};

struct ExhaustionMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { FT_STRING, 1, true },
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1343313, -1, 7, 7, 0x115BE21D, Fields, -1 };
};

struct ExpectedStatMeta
{
    static constexpr DB2MetaField Fields[11] =
    {
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1937326, -1, 11, 10, 0xD0570787, Fields, 10 };
};

struct ExpectedStatModMeta
{
    static constexpr DB2MetaField Fields[9] =
    {
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1969773, -1, 9, 9, 0x462D65F2, Fields, -1 };
};

struct ExtraAbilityInfoMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3527889, -1, 6, 6, 0x006F6DEF, Fields, 1 };
};

struct FactionMeta
{
    static constexpr DB2MetaField Fields[17] =
    {
        { FT_LONG, 4, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_SHORT, 1, true },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_SHORT, 4, true },
        { FT_SHORT, 4, false },
        { FT_INT, 4, true },
        { FT_INT, 4, true },
        { FT_FLOAT, 2, true },
        { FT_BYTE, 2, false },
    };

    static constexpr DB2Meta Instance{ 1361972, -1, 17, 17, 0xBE1F09D5, Fields, -1 };
};

struct FactionGroupMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_STRING, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1343595, -1, 5, 5, 0x5CCF4BE3, Fields, -1 };
};

struct FactionTemplateMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_SHORT, 8, false },
        { FT_SHORT, 8, false },
    };

    static constexpr DB2Meta Instance{ 1361579, -1, 7, 7, 0x207C5E80, Fields, -1 };
};

struct FlightCapabilityMeta
{
    static constexpr DB2MetaField Fields[25] =
    {
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4501047, -1, 25, 25, 0x521F9F83, Fields, -1 };
};

struct FlightCapabilityXGlideEventMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4644249, -1, 2, 1, 0x002DF52F, Fields, 1 };
};

struct FootprintTexturesMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1308056, -1, 3, 3, 0x6E56D772, Fields, -1 };
};

struct FootstepTerrainLookupMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1267647, -1, 4, 4, 0xC8B9FDAC, Fields, -1 };
};

struct FriendshipRepReactionMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1237638, -1, 4, 4, 0xA1157C1F, Fields, 1 };
};

struct FriendshipReputationMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1237639, 3, 7, 7, 0xDCF9508F, Fields, -1 };
};

struct FullScreenEffectMeta
{
    static constexpr DB2MetaField Fields[28] =
    {
        { FT_INT, 1, false },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1348282, -1, 28, 28, 0x6D545850, Fields, -1 };
};

struct GMSurveyAnswersMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_STRING, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1283025, -1, 3, 2, 0x8C4F9BE3, Fields, 2 };
};

struct GMSurveyCurrentSurveyMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1278177, -1, 1, 1, 0x29F86C92, Fields, -1 };
};

struct GMSurveyQuestionsMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_STRING, 1, true },
    };

    static constexpr DB2Meta Instance{ 1278178, -1, 1, 1, 0x10770511, Fields, -1 };
};

struct GMSurveySurveysMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_BYTE, 15, false },
    };

    static constexpr DB2Meta Instance{ 1283020, -1, 1, 1, 0x808736D1, Fields, -1 };
};

struct GameClockDebugMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2922072, -1, 1, 1, 0xD30981EC, Fields, -1 };
};

struct GameModeMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5008306, -1, 6, 6, 0x45EE0D98, Fields, -1 };
};

struct GameObjectAnimGroupMemberMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 3565753, -1, 4, 4, 0x375C3387, Fields, 0 };
};

struct GameObjectArtKitMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 3, true },
    };

    static constexpr DB2Meta Instance{ 1266737, -1, 2, 2, 0x520690EF, Fields, -1 };
};

struct GameObjectDiffAnimMapMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1302847, -1, 4, 3, 0x7403DFA2, Fields, 3 };
};

struct GameObjectDisplayInfoMeta
{
    static constexpr DB2MetaField Fields[8] =
    {
        { FT_FLOAT, 6, true },
        { FT_INT, 1, true },
        { FT_SHORT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1266277, -1, 8, 8, 0x7F774625, Fields, -1 };
};

struct GameObjectDisplayInfoXSoundKitMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1345272, -1, 3, 2, 0x16B43E1B, Fields, 2 };
};

struct GameObjectLabelMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4621877, -1, 2, 1, 0xDC099311, Fields, 1 };
};

struct GameObjectsMeta
{
    static constexpr DB2MetaField Fields[12] =
    {
        { FT_STRING, 1, true },
        { FT_FLOAT, 3, true },
        { FT_FLOAT, 4, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 8, true },
    };

    static constexpr DB2Meta Instance{ 841620, 3, 12, 12, 0xE1536F72, Fields, 4 };
};

struct GameParameterMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3405438, -1, 5, 5, 0xE2A34B99, Fields, -1 };
};

struct GameTipsMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_STRING, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1368021, -1, 5, 5, 0x3D7E744D, Fields, -1 };
};

struct GarrAbilityMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 966238, -1, 7, 7, 0x895C6CBD, Fields, -1 };
};

struct GarrAbilityCategoryMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_STRING, 1, true },
    };

    static constexpr DB2Meta Instance{ 1020248, -1, 1, 1, 0xB0DD8F60, Fields, -1 };
};

struct GarrAbilityEffectMeta
{
    static constexpr DB2MetaField Fields[12] =
    {
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 966241, 0, 12, 12, 0x42A6AC5E, Fields, 1 };
};

struct GarrAutoCombatantMeta
{
    static constexpr DB2MetaField Fields[9] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3305399, -1, 9, 9, 0xC6049FC4, Fields, -1 };
};

struct GarrAutoSpellMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3305400, -1, 7, 7, 0x4229E5FF, Fields, -1 };
};

struct GarrAutoSpellEffectMeta
{
    static constexpr DB2MetaField Fields[8] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_FLOAT, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3307335, 0, 8, 8, 0x71E3FAFA, Fields, 1 };
};

struct GarrBuildingMeta
{
    static constexpr DB2MetaField Fields[24] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 929747, -1, 24, 24, 0x76E04D94, Fields, -1 };
};

struct GarrBuildingDoodadSetMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 943937, -1, 5, 5, 0x398E9742, Fields, -1 };
};

struct GarrBuildingPlotInstMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_FLOAT, 2, true },
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 983298, 1, 5, 5, 0xDEF48812, Fields, 2 };
};

struct GarrClassSpecMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 981570, -1, 7, 7, 0x0872F30A, Fields, -1 };
};

struct GarrClassSpecPlayerCondMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1380674, -1, 6, 6, 0x1F048C5D, Fields, -1 };
};

struct GarrEncounterMeta
{
    static constexpr DB2MetaField Fields[8] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 975304, -1, 8, 8, 0x00F63E78, Fields, -1 };
};

struct GarrEncounterSetXEncounterMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1354772, 0, 3, 2, 0x0C38FD7C, Fields, 2 };
};

struct GarrEncounterXMechanicMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 967961, -1, 3, 2, 0x4727DED7, Fields, 2 };
};

struct GarrFollItemSetMemberMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 981569, -1, 4, 3, 0x01FD0F5B, Fields, 3 };
};

struct GarrFollSupportSpellMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1345970, -1, 4, 3, 0xDCED652F, Fields, 3 };
};

struct GarrFollowerMeta
{
    static constexpr DB2MetaField Fields[33] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 949906, -1, 33, 33, 0x2F65E7B8, Fields, -1 };
};

struct GarrFollowerLevelXPMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 970979, -1, 4, 4, 0xC6D9156C, Fields, -1 };
};

struct GarrFollowerQualityMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1027793, -1, 7, 7, 0x12E3D869, Fields, -1 };
};

struct GarrFollowerSetXFollowerMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1361029, -1, 2, 1, 0x0E5F4858, Fields, 1 };
};

struct GarrFollowerTypeMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1118784, -1, 7, 7, 0x90DE9D04, Fields, -1 };
};

struct GarrFollowerUICreatureMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1412636, -1, 6, 5, 0x48A9C93E, Fields, 5 };
};

struct GarrFollowerXAbilityMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 968468, -1, 4, 3, 0xDC1338B5, Fields, 3 };
};

struct GarrItemLevelUpgradeDataMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
    };

    static constexpr DB2Meta Instance{ 1572314, -1, 4, 4, 0xFF309F3E, Fields, -1 };
};

struct GarrMechanicMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 967963, -1, 3, 3, 0xEC754F2F, Fields, -1 };
};

struct GarrMechanicSetXMechanicMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1391531, 0, 3, 2, 0xD2D3C4ED, Fields, 2 };
};

struct GarrMechanicTypeMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 967964, -1, 4, 4, 0xF88C0C01, Fields, -1 };
};

struct GarrMissionMeta
{
    static constexpr DB2MetaField Fields[31] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_FLOAT, 2, true },
        { FT_FLOAT, 2, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 967962, -1, 31, 31, 0xCA0E980C, Fields, 16 };
};

struct GarrMissionSetMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3055759, -1, 6, 6, 0x1858B6AD, Fields, -1 };
};

struct GarrMissionTextureMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_FLOAT, 2, true },
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1125220, -1, 2, 2, 0x17FF9F33, Fields, -1 };
};

struct GarrMissionTypeMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_STRING, 1, true },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 984174, -1, 3, 3, 0xEE85FBAD, Fields, -1 };
};

struct GarrMissionXEncounterMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 967960, -1, 5, 4, 0x902619AC, Fields, 4 };
};

struct GarrMissionXFollowerMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1359096, -1, 4, 3, 0x5B84EFCD, Fields, 3 };
};

struct GarrMssnBonusAbilityMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1138458, -1, 5, 5, 0x607D4E83, Fields, -1 };
};

struct GarrPlotMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 2, false },
    };

    static constexpr DB2Meta Instance{ 937634, -1, 7, 7, 0x47067617, Fields, -1 };
};

struct GarrPlotBuildingMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 929743, -1, 2, 2, 0x9C6539B2, Fields, -1 };
};

struct GarrPlotInstanceMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 929742, -1, 2, 2, 0xC5609120, Fields, -1 };
};

struct GarrPlotUICategoryMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_STRING, 1, true },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 937635, -1, 2, 2, 0xD6167CD7, Fields, -1 };
};

struct GarrSiteLevelMeta
{
    static constexpr DB2MetaField Fields[9] =
    {
        { FT_FLOAT, 2, true },
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 939295, -1, 9, 9, 0x41BF2E0A, Fields, -1 };
};

struct GarrSiteLevelPlotInstMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_FLOAT, 2, true },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 940404, -1, 4, 4, 0x1CAD597B, Fields, 1 };
};

struct GarrSpecializationMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_FLOAT, 2, true },
    };

    static constexpr DB2Meta Instance{ 937647, -1, 7, 7, 0x7983E7D9, Fields, -1 };
};

struct GarrStringMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_STRING, 1, true },
    };

    static constexpr DB2Meta Instance{ 1416758, -1, 1, 1, 0x9588F8C8, Fields, -1 };
};

struct GarrTalTreeXGarrTalResearchMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3195601, -1, 3, 3, 0xF00FA3EA, Fields, -1 };
};

struct GarrTalentMeta
{
    static constexpr DB2MetaField Fields[15] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1361032, 2, 15, 15, 0xEF4DB72A, Fields, 3 };
};

struct GarrTalentCostMeta
{
    static constexpr DB2MetaField Fields[9] =
    {
        { FT_LONG, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3514438, 1, 9, 9, 0x8E3D05D3, Fields, 2 };
};

struct GarrTalentMapPOIMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_FLOAT, 2, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3534056, -1, 2, 2, 0x75F07445, Fields, -1 };
};

struct GarrTalentRankMeta
{
    static constexpr DB2MetaField Fields[18] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3069763, 0, 18, 17, 0x1D54CA3C, Fields, 17 };
};

struct GarrTalentRankGroupEntryMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4382239, -1, 2, 1, 0xE2F5D419, Fields, 1 };
};

struct GarrTalentRankGroupResearchModMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4389481, -1, 4, 3, 0x14AF829F, Fields, 3 };
};

struct GarrTalentResearchMeta
{
    static constexpr DB2MetaField Fields[8] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3195518, -1, 8, 8, 0x8A171D9D, Fields, -1 };
};

struct GarrTalentSocketPropertiesMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3612617, -1, 2, 2, 0xDA437EE1, Fields, -1 };
};

struct GarrTalentTreeMeta
{
    static constexpr DB2MetaField Fields[12] =
    {
        { FT_STRING, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1361030, -1, 12, 12, 0xC148F18E, Fields, -1 };
};

struct GarrTypeMeta
{
    static constexpr DB2MetaField Fields[9] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 2, true },
    };

    static constexpr DB2Meta Instance{ 1333161, 0, 9, 9, 0x6C12C0C5, Fields, -1 };
};

struct GarrUiAnimClassInfoMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 976037, -1, 6, 6, 0x3D333DD8, Fields, -1 };
};

struct GarrUiAnimRaceInfoMeta
{
    static constexpr DB2MetaField Fields[13] =
    {
        { FT_BYTE, 1, false },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 976035, -1, 13, 13, 0x225F0657, Fields, -1 };
};

struct GemPropertiesMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1343604, -1, 2, 2, 0x61DF3B70, Fields, -1 };
};

struct GlideEventMeta
{
    static constexpr DB2MetaField Fields[11] =
    {
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4644012, -1, 11, 11, 0xAF8D7840, Fields, -1 };
};

struct GlideEventBlendTimesMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4682325, -1, 3, 2, 0xD91C3032, Fields, 2 };
};

struct GlobalColorMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4328468, -1, 2, 2, 0x70FE4450, Fields, -1 };
};

struct GlobalCurveMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3752002, -1, 2, 2, 0x7EA5C3BF, Fields, -1 };
};

struct GlobalGameContentTuningMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3756368, -1, 2, 2, 0xC5E2173D, Fields, -1 };
};

struct GlobalPlayerConditionMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4082838, -1, 3, 2, 0x30F25618, Fields, 2 };
};

struct GlobalPlayerConditionSetMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4082839, 0, 2, 2, 0xD111129C, Fields, -1 };
};

struct GlobalStringsMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_STRING, 1, true },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1394440, -1, 3, 3, 0x9D50610A, Fields, -1 };
};

struct GlyphBindableSpellMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1270147, -1, 2, 1, 0x7F8BAF7B, Fields, 1 };
};

struct GlyphExclusiveCategoryMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_STRING, 1, true },
    };

    static constexpr DB2Meta Instance{ 948546, -1, 1, 1, 0x283BBF49, Fields, -1 };
};

struct GlyphPropertiesMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1345274, -1, 4, 4, 0x8242C866, Fields, -1 };
};

struct GlyphRequiredSpecMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 948496, -1, 2, 1, 0xCC301712, Fields, 1 };
};

struct GossipNPCOptionMeta
{
    static constexpr DB2MetaField Fields[15] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4278503, -1, 15, 15, 0x9170AADA, Fields, -1 };
};

struct GossipNPCOptionDisplayInfoMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4335720, -1, 3, 3, 0x8B9BF10F, Fields, -1 };
};

struct GossipXGarrTalentTreesMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4407361, -1, 2, 1, 0x9BE63EB3, Fields, 1 };
};

struct GossipXUIDisplayInfoMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3622253, -1, 4, 4, 0x30595578, Fields, -1 };
};

struct GradientEffectMeta
{
    static constexpr DB2MetaField Fields[18] =
    {
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2433582, -1, 18, 18, 0xA5B6854E, Fields, -1 };
};

struct GroundEffectDoodadMeta
{
    static constexpr DB2MetaField Fields[9] =
    {
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1308057, -1, 9, 9, 0xF592B773, Fields, -1 };
};

struct GroundEffectTextureMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
        { FT_SHORT, 4, false },
        { FT_BYTE, 4, true },
        { FT_BYTE, 4, true },
    };

    static constexpr DB2Meta Instance{ 1308499, -1, 5, 5, 0x3DEC72D8, Fields, -1 };
};

struct GroupFinderActivityMeta
{
    static constexpr DB2MetaField Fields[15] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, true },
        { FT_SHORT, 1, false },
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 974813, -1, 15, 15, 0x2646188E, Fields, -1 };
};

struct GroupFinderActivityGrpMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_STRING, 1, true },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 974814, -1, 2, 2, 0x89256FF7, Fields, -1 };
};

struct GroupFinderActivityXPvpBracketMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
    };

    static constexpr DB2Meta Instance{ 4206623, -1, 2, 2, 0x8BBA3BDB, Fields, -1 };
};

struct GroupFinderCategoryMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 974812, -1, 4, 4, 0x257D1287, Fields, -1 };
};

struct GuildColorBackgroundMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1286526, -1, 3, 3, 0x1364EF78, Fields, -1 };
};

struct GuildColorBorderMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1286527, -1, 3, 3, 0x1364EF78, Fields, -1 };
};

struct GuildColorEmblemMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1286525, -1, 3, 3, 0x1364EF78, Fields, -1 };
};

struct GuildEmblemMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2734754, -1, 2, 2, 0xFA4DFEEA, Fields, -1 };
};

struct GuildPerkSpellsMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1135238, -1, 1, 1, 0x465F6F2A, Fields, -1 };
};

struct GuildShirtBackgroundMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2921008, -1, 4, 3, 0xF7862CB0, Fields, 3 };
};

struct GuildShirtBorderMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2921475, -1, 5, 4, 0x67FA04AE, Fields, 4 };
};

struct GuildTabardBackgroundMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2909769, -1, 4, 3, 0xB5B6CD95, Fields, 3 };
};

struct GuildTabardBorderMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2920485, -1, 5, 4, 0x6C616EAA, Fields, 4 };
};

struct GuildTabardEmblemMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2910470, -1, 4, 3, 0xB8CF8F15, Fields, 3 };
};

struct HeirloomMeta
{
    static constexpr DB2MetaField Fields[10] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 6, true },
        { FT_SHORT, 6, false },
    };

    static constexpr DB2Meta Instance{ 1097696, 1, 10, 10, 0xFD204E4C, Fields, -1 };
};

struct HelmetAnimScalingMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1348283, -1, 3, 2, 0x2152D6E4, Fields, 2 };
};

struct HelmetGeosetDataMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2821752, -1, 5, 4, 0x78C6B857, Fields, 4 };
};

struct HighlightColorMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 996358, -1, 5, 5, 0x5F6F32BA, Fields, -1 };
};

struct HolidayDescriptionsMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_STRING, 1, true },
    };

    static constexpr DB2Meta Instance{ 996360, -1, 1, 1, 0xD981411C, Fields, -1 };
};

struct HolidayNamesMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_STRING, 1, true },
    };

    static constexpr DB2Meta Instance{ 996359, -1, 1, 1, 0x31516347, Fields, -1 };
};

struct HolidaysMeta
{
    static constexpr DB2MetaField Fields[11] =
    {
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, false },
        { FT_SHORT, 10, false },
        { FT_INT, 26, false },
        { FT_BYTE, 10, false },
        { FT_INT, 3, true },
    };

    static constexpr DB2Meta Instance{ 996357, -1, 11, 11, 0xDEC453C4, Fields, -1 };
};

struct HotfixesMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1995523, -1, 4, 4, 0xC02BA201, Fields, -1 };
};

struct ImportPriceArmorMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1121229, -1, 4, 4, 0x7979D30F, Fields, -1 };
};

struct ImportPriceQualityMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1121228, -1, 1, 1, 0xD4F6FFC8, Fields, -1 };
};

struct ImportPriceShieldMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1121227, -1, 1, 1, 0xD4F6FFC8, Fields, -1 };
};

struct ImportPriceWeaponMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1121230, -1, 1, 1, 0xD4F6FFC8, Fields, -1 };
};

struct InvasionClientDataMeta
{
    static constexpr DB2MetaField Fields[10] =
    {
        { FT_STRING, 1, true },
        { FT_FLOAT, 2, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1336651, 2, 10, 9, 0xC66039FC, Fields, 9 };
};

struct ItemMeta
{
    static constexpr DB2MetaField Fields[11] =
    {
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 841626, -1, 11, 11, 0xBCC9BC83, Fields, -1 };
};

struct ItemAppearanceMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 982462, -1, 5, 5, 0x33C9038E, Fields, -1 };
};

struct ItemAppearanceXUiCameraMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1248126, -1, 2, 2, 0xD239EB9B, Fields, -1 };
};

struct ItemArmorQualityMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_FLOAT, 7, true },
    };

    static constexpr DB2Meta Instance{ 1283021, -1, 1, 1, 0x5DAB3131, Fields, -1 };
};

struct ItemArmorShieldMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_FLOAT, 7, true },
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1277741, -1, 2, 2, 0x4E03E769, Fields, -1 };
};

struct ItemArmorTotalMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_SHORT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1283022, -1, 5, 5, 0xC1DD3156, Fields, -1 };
};

struct ItemBagFamilyMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_STRING, 1, true },
    };

    static constexpr DB2Meta Instance{ 1278179, -1, 1, 1, 0xB0DD8F60, Fields, -1 };
};

struct ItemBonusMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 4, true },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 959070, -1, 4, 4, 0x7864A3E0, Fields, 1 };
};

struct ItemBonusListMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1805807, 0, 2, 2, 0x31228AEF, Fields, -1 };
};

struct ItemBonusListGroupMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3755382, -1, 5, 5, 0xF169B927, Fields, -1 };
};

struct ItemBonusListGroupEntryMeta
{
    static constexpr DB2MetaField Fields[9] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3025306, 0, 9, 9, 0x17163D82, Fields, 1 };
};

struct ItemBonusListLevelDeltaMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_SHORT, 1, true },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1320358, 1, 2, 2, 0xC6EA2151, Fields, -1 };
};

struct ItemBonusListWarforgeLevelDeltaMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_SHORT, 1, true },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 2924997, 1, 2, 2, 0xC6EA2151, Fields, -1 };
};

struct ItemBonusSeasonMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5155639, 0, 2, 2, 0x7F150202, Fields, -1 };
};

struct ItemBonusSeasonBonusListGroupMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5155640, 0, 4, 4, 0x284E8A83, Fields, 3 };
};

struct ItemBonusSeasonUpgradeCostMeta
{
    static constexpr DB2MetaField Fields[8] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5155641, 1, 8, 8, 0x76231EF7, Fields, 5 };
};

struct ItemBonusSequenceSpellMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3026822, -1, 2, 1, 0x2AA71F9B, Fields, 1 };
};

struct ItemBonusTreeMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3055768, -1, 2, 2, 0xBC8C367C, Fields, -1 };
};

struct ItemBonusTreeGroupEntryMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4407505, -1, 2, 2, 0xF3BB739B, Fields, 0 };
};

struct ItemBonusTreeNodeMeta
{
    static constexpr DB2MetaField Fields[9] =
    {
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 987134, -1, 9, 8, 0xF5BD96C0, Fields, 8 };
};

struct ItemChildEquipmentMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1247926, -1, 3, 3, 0xE726DCEE, Fields, 0 };
};

struct ItemClassMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_STRING, 1, true },
        { FT_BYTE, 1, true },
        { FT_FLOAT, 1, true },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1140189, -1, 4, 4, 0xC21C5BEA, Fields, -1 };
};

struct ItemConditionMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5128111, -1, 1, 1, 0xC2F7FE6F, Fields, -1 };
};

struct ItemContextPickerEntryMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1405665, -1, 7, 6, 0x3C496406, Fields, 6 };
};

struct ItemConversionMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4337196, -1, 5, 5, 0xAD670E90, Fields, -1 };
};

struct ItemConversionEntryMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4337197, -1, 2, 1, 0xFDC43755, Fields, 1 };
};

struct ItemCurrencyCostMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 801670, -1, 1, 1, 0xE55A34CC, Fields, 0 };
};

struct ItemCurrencyValueMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 4, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3755770, -1, 3, 2, 0x664B8E34, Fields, 2 };
};

struct ItemDamageAmmoMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_SHORT, 1, false },
        { FT_FLOAT, 7, true },
    };

    static constexpr DB2Meta Instance{ 1277740, -1, 2, 2, 0xBD540229, Fields, -1 };
};

struct ItemDamageOneHandMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_SHORT, 1, false },
        { FT_FLOAT, 7, true },
    };

    static constexpr DB2Meta Instance{ 1277743, -1, 2, 2, 0xBD540229, Fields, -1 };
};

struct ItemDamageOneHandCasterMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_SHORT, 1, false },
        { FT_FLOAT, 7, true },
    };

    static constexpr DB2Meta Instance{ 1277739, -1, 2, 2, 0xBD540229, Fields, -1 };
};

struct ItemDamageTwoHandMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_SHORT, 1, false },
        { FT_FLOAT, 7, true },
    };

    static constexpr DB2Meta Instance{ 1277738, -1, 2, 2, 0xBD540229, Fields, -1 };
};

struct ItemDamageTwoHandCasterMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_SHORT, 1, false },
        { FT_FLOAT, 7, true },
    };

    static constexpr DB2Meta Instance{ 1277742, -1, 2, 2, 0xBD540229, Fields, -1 };
};

struct ItemDisenchantLootMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1134087, -1, 7, 6, 0xB1D813A9, Fields, 6 };
};

struct ItemDisplayInfoMeta
{
    static constexpr DB2MetaField Fields[16] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 2, false },
        { FT_INT, 2, true },
        { FT_INT, 2, true },
        { FT_INT, 6, true },
        { FT_INT, 6, true },
        { FT_INT, 2, true },
    };

    static constexpr DB2Meta Instance{ 1266429, -1, 16, 16, 0xD922B51F, Fields, -1 };
};

struct ItemDisplayInfoMaterialResMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1280614, -1, 3, 2, 0x83420BDB, Fields, 2 };
};

struct ItemDisplayInfoModelMatResMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4050937, -1, 4, 3, 0x9601DF6B, Fields, 3 };
};

struct ItemEffectMeta
{
    static constexpr DB2MetaField Fields[8] =
    {
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, true },
        { FT_SHORT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 969941, -1, 8, 8, 0xF9253409, Fields, -1 };
};

struct ItemExtendedCostMeta
{
    static constexpr DB2MetaField Fields[10] =
    {
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 5, true },
        { FT_SHORT, 5, false },
        { FT_SHORT, 5, false },
        { FT_INT, 5, false },
    };

    static constexpr DB2Meta Instance{ 801681, -1, 10, 10, 0xF4D91D1F, Fields, -1 };
};

struct ItemFallbackVisualMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2358574, -1, 3, 3, 0xB0198BA2, Fields, -1 };
};

struct ItemFixupMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5152256, -1, 1, 1, 0x31DF97E4, Fields, -1 };
};

struct ItemFixupActionMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5475699, -1, 2, 1, 0x3B964A51, Fields, 1 };
};

struct ItemGroupIlvlScalingEntryMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5015219, -1, 5, 4, 0x38E9D642, Fields, 4 };
};

struct ItemGroupSoundsMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 4, false },
    };

    static constexpr DB2Meta Instance{ 1283023, -1, 1, 1, 0xBFD29A96, Fields, -1 };
};

struct ItemLevelSelectorMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1588911, -1, 3, 3, 0x25BC6A6B, Fields, -1 };
};

struct ItemLevelSelectorQualityMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1624937, -1, 3, 2, 0xBAF7EC29, Fields, 2 };
};

struct ItemLevelSelectorQualitySetMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_SHORT, 1, true },
        { FT_SHORT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1624933, -1, 2, 2, 0x4080CC90, Fields, -1 };
};

struct ItemLimitCategoryMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_STRING, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1237440, -1, 3, 3, 0x403BC7B2, Fields, -1 };
};

struct ItemLimitCategoryConditionMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_BYTE, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1378590, -1, 3, 2, 0x9E37B423, Fields, 2 };
};

struct ItemLogicalCostMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4677533, -1, 4, 3, 0xDB1BC742, Fields, 3 };
};

struct ItemLogicalCostGroupMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 4677534, 0, 1, 1, 0x6657BD0A, Fields, -1 };
};

struct ItemModifiedAppearanceMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 982457, 0, 6, 6, 0x0120090C, Fields, 1 };
};

struct ItemModifiedAppearanceExtraMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
    };

    static constexpr DB2Meta Instance{ 1278399, -1, 5, 5, 0x08968F49, Fields, -1 };
};

struct ItemNameDescriptionMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1332559, -1, 2, 2, 0xB60E60BD, Fields, -1 };
};

struct ItemNameSlotOverrideMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3723474, -1, 3, 2, 0xCF0119FB, Fields, 2 };
};

struct ItemPetFoodMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_STRING, 1, true },
    };

    static constexpr DB2Meta Instance{ 1302240, -1, 1, 1, 0x332FA55B, Fields, -1 };
};

struct ItemPriceBaseMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_SHORT, 1, false },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1121231, -1, 3, 3, 0xAA32653C, Fields, -1 };
};

struct ItemRangedDisplayInfoMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1270315, -1, 4, 4, 0x08C2EB5B, Fields, -1 };
};

struct ItemRecraftMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5150118, 0, 5, 4, 0xE00E7F34, Fields, 4 };
};

struct ItemSalvageMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4548446, -1, 3, 3, 0x362127B8, Fields, -1 };
};

struct ItemSalvageLootMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4549058, -1, 3, 3, 0x96554070, Fields, 0 };
};

struct ItemSearchNameMeta
{
    static constexpr DB2MetaField Fields[13] =
    {
        { FT_LONG, 1, true },
        { FT_STRING, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 4, true },
    };

    static constexpr DB2Meta Instance{ 1273408, -1, 13, 13, 0xBCDBBEFB, Fields, -1 };
};

struct ItemSetMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 17, false },
    };

    static constexpr DB2Meta Instance{ 1343609, -1, 5, 5, 0x4F7008BF, Fields, -1 };
};

struct ItemSetSpellMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_SHORT, 1, false },
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1314689, -1, 4, 3, 0xBF92BB46, Fields, 3 };
};

struct ItemSparseMeta
{
    static constexpr DB2MetaField Fields[64] =
    {
        { FT_LONG, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 10, true },
        { FT_INT, 10, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 4, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 2, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 3, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 10, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
    };

    static constexpr DB2Meta Instance{ 1572924, -1, 64, 64, 0xB07DD994, Fields, -1 };
};

struct ItemSpecMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1135120, -1, 6, 6, 0x72013ECD, Fields, 2 };
};

struct ItemSpecOverrideMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1134576, -1, 2, 1, 0xD621A05B, Fields, 1 };
};

struct ItemSubClassMeta
{
    static constexpr DB2MetaField Fields[11] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
    };

    static constexpr DB2Meta Instance{ 1261604, 2, 11, 11, 0xC096A1B1, Fields, 3 };
};

struct ItemSubClassMaskMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_STRING, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1302852, -1, 3, 3, 0x42DC1188, Fields, -1 };
};

struct ItemVisualsMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 5, true },
    };

    static constexpr DB2Meta Instance{ 1343605, -1, 3, 3, 0xC5D076A1, Fields, -1 };
};

struct ItemVisualsXEffectMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3043873, -1, 6, 5, 0xE011E7C1, Fields, 5 };
};

struct ItemXBonusTreeMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 987133, -1, 2, 1, 0xB088DCDC, Fields, 1 };
};

struct ItemXItemEffectMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3177687, -1, 2, 1, 0x96428A69, Fields, 1 };
};

struct JournalEncounterMeta
{
    static constexpr DB2MetaField Fields[12] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_FLOAT, 2, true },
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
    };

    static constexpr DB2Meta Instance{ 1240336, 3, 12, 12, 0x37948505, Fields, -1 };
};

struct JournalEncounterCreatureMeta
{
    static constexpr DB2MetaField Fields[8] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1301155, 2, 8, 8, 0x8D6F8786, Fields, 3 };
};

struct JournalEncounterItemMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, false },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
    };

    static constexpr DB2Meta Instance{ 1344467, 0, 6, 6, 0xDAC92896, Fields, 1 };
};

struct JournalEncounterSectionMeta
{
    static constexpr DB2MetaField Fields[15] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
    };

    static constexpr DB2Meta Instance{ 1134413, -1, 15, 15, 0xF617A4B5, Fields, -1 };
};

struct JournalEncounterXDifficultyMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1121901, -1, 2, 1, 0xF103C808, Fields, 1 };
};

struct JournalEncounterXMapLocMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_FLOAT, 2, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1722928, -1, 5, 4, 0xF9E973F0, Fields, 4 };
};

struct JournalInstanceMeta
{
    static constexpr DB2MetaField Fields[9] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1237438, -1, 9, 9, 0xE213FF3B, Fields, -1 };
};

struct JournalInstanceEntranceMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_FLOAT, 3, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5228481, -1, 5, 4, 0x3FD6C4DC, Fields, 4 };
};

struct JournalInstanceQueueLocMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_FLOAT, 3, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5228217, -1, 6, 5, 0xF0EB0976, Fields, 5 };
};

struct JournalItemXDifficultyMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1277744, -1, 2, 1, 0x19DEDAA3, Fields, 1 };
};

struct JournalSectionXDifficultyMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1121900, -1, 2, 1, 0x13D3283F, Fields, 1 };
};

struct JournalTierMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1349056, -1, 2, 2, 0x10E4DFC1, Fields, -1 };
};

struct JournalTierXInstanceMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1285009, -1, 4, 4, 0x1351FB2E, Fields, 0 };
};

struct KeychainMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_BYTE, 32, false },
    };

    static constexpr DB2Meta Instance{ 801693, -1, 1, 1, 0x683DDBCE, Fields, -1 };
};

struct KeystoneAffixMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1344761, 2, 4, 4, 0x6645021B, Fields, -1 };
};

struct LFGDungeonGroupMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_STRING, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1135058, -1, 4, 4, 0xFCCAFEFD, Fields, -1 };
};

struct LFGDungeonsMeta
{
    static constexpr DB2MetaField Fields[29] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, true },
        { FT_BYTE, 1, false },
        { FT_FLOAT, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 2, true },
    };

    static constexpr DB2Meta Instance{ 1361033, -1, 29, 29, 0x5314B0A9, Fields, -1 };
};

struct LFGRoleRequirementMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_BYTE, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 982805, -1, 3, 2, 0x6112092C, Fields, 2 };
};

struct LabelXContentRestrictRuleSetMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4281309, -1, 3, 2, 0x4F3F4F82, Fields, 2 };
};

struct LanguageWordsMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 984702, -1, 2, 2, 0x9CFC1981, Fields, -1 };
};

struct LanguagesMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1135325, 1, 6, 6, 0xE026BB06, Fields, -1 };
};

struct LfgDungeonsGroupingMapMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1339818, -1, 3, 2, 0x3538AE33, Fields, 2 };
};

struct LightMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_FLOAT, 3, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_SHORT, 1, true },
        { FT_SHORT, 8, false },
    };

    static constexpr DB2Meta Instance{ 1375579, -1, 5, 5, 0xAD1B2253, Fields, -1 };
};

struct LightDataMeta
{
    static constexpr DB2MetaField Fields[46] =
    {
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 4, true },
        { FT_FLOAT, 4, true },
        { FT_FLOAT, 4, true },
    };

    static constexpr DB2Meta Instance{ 1375580, -1, 46, 46, 0x1D523CA5, Fields, 0 };
};

struct LightParamsMeta
{
    static constexpr DB2MetaField Fields[11] =
    {
        { FT_FLOAT, 3, true },
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1334669, -1, 11, 11, 0x9C29BEEF, Fields, -1 };
};

struct LightSkyboxMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1308501, -1, 4, 4, 0xF2269F12, Fields, -1 };
};

struct LightWorldShadowMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4680119, -1, 3, 2, 0x59642561, Fields, 2 };
};

struct LightningMeta
{
    static constexpr DB2MetaField Fields[34] =
    {
        { FT_FLOAT, 2, true },
        { FT_INT, 3, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2003383, -1, 34, 34, 0x09AF7B51, Fields, -1 };
};

struct LiquidMaterialMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
    };

    static constexpr DB2Meta Instance{ 1132538, -1, 2, 2, 0x2CFFEA40, Fields, -1 };
};

struct LiquidObjectMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_SHORT, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1308058, -1, 5, 5, 0x6CAEB8A1, Fields, -1 };
};

struct LiquidTypeMeta
{
    static constexpr DB2MetaField Fields[21] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_STRING_NOT_LOCALIZED, 6, true },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_SHORT, 1, false },
        { FT_FLOAT, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_BYTE, 6, false },
        { FT_INT, 2, true },
        { FT_FLOAT, 18, true },
        { FT_INT, 4, false },
        { FT_FLOAT, 4, true },
    };

    static constexpr DB2Meta Instance{ 1371380, -1, 21, 21, 0xAFFFC9E0, Fields, -1 };
};

struct LiquidTypeXTextureMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2261065, -1, 4, 3, 0x5CC7EE1B, Fields, 3 };
};

struct LivingWorldObjectTemplateMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4276965, -1, 1, 1, 0x74706E81, Fields, -1 };
};

struct LivingWorldObjectTemplateModelMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4276966, -1, 4, 3, 0xA5D81C93, Fields, 3 };
};

struct LoadingScreenSkinMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 10, true },
    };

    static constexpr DB2Meta Instance{ 2478235, -1, 1, 1, 0xE6C0E75D, Fields, -1 };
};

struct LoadingScreenTaxiSplinesMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
        { FT_FLOAT, 10, true },
        { FT_FLOAT, 10, true },
    };

    static constexpr DB2Meta Instance{ 1302239, -1, 5, 5, 0xD9F03CBC, Fields, -1 };
};

struct LoadingScreensMeta
{
    static constexpr DB2MetaField Fields[10] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1266541, -1, 10, 10, 0x112726F1, Fields, -1 };
};

struct LocaleMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 801706, -1, 5, 5, 0x751D8F5F, Fields, -1 };
};

struct LocationMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_FLOAT, 3, true },
        { FT_FLOAT, 3, true },
    };

    static constexpr DB2Meta Instance{ 801707, -1, 2, 2, 0xB0561808, Fields, -1 };
};

struct LockMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_INT, 1, true },
        { FT_INT, 8, true },
        { FT_SHORT, 8, false },
        { FT_BYTE, 8, false },
        { FT_BYTE, 8, false },
    };

    static constexpr DB2Meta Instance{ 1343608, -1, 5, 5, 0xD359BBE0, Fields, -1 };
};

struct LockTypeMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1284823, -1, 6, 6, 0x62421B4C, Fields, -1 };
};

struct LookAtControllerMeta
{
    static constexpr DB2MetaField Fields[18] =
    {
        { FT_FLOAT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1098785, -1, 18, 18, 0x01B2684C, Fields, -1 };
};

struct LoreTextMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3311370, -1, 3, 3, 0x886CC0CF, Fields, -1 };
};

struct LoreTextPublicMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3479846, 0, 6, 5, 0x54EE4E73, Fields, 5 };
};

struct MCRSlotXMCRCategoryMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3390955, -1, 3, 2, 0x39F35458, Fields, 2 };
};

struct MailTemplateMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_STRING, 1, true },
    };

    static constexpr DB2Meta Instance{ 1240344, -1, 1, 1, 0x7C454945, Fields, -1 };
};

struct ManagedWorldStateMeta
{
    static constexpr DB2MetaField Fields[10] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 4, true },
    };

    static constexpr DB2Meta Instance{ 1587159, -1, 10, 10, 0xE239E53B, Fields, -1 };
};

struct ManagedWorldStateBuffMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1587155, -1, 4, 3, 0xBA39FD6A, Fields, 3 };
};

struct ManagedWorldStateInputMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1587151, -1, 3, 3, 0x271DEDDF, Fields, -1 };
};

struct ManifestInterfaceActionIconMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1375803, 0, 1, 1, 0x6657BD0A, Fields, -1 };
};

struct ManifestInterfaceDataMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_STRING_NOT_LOCALIZED, 1, true },
    };

    static constexpr DB2Meta Instance{ 1375801, -1, 2, 2, 0x13274651, Fields, -1 };
};

struct ManifestInterfaceItemIconMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1375804, 0, 1, 1, 0x6657BD0A, Fields, -1 };
};

struct ManifestInterfaceTOCDataMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
    };

    static constexpr DB2Meta Instance{ 1267335, -1, 1, 1, 0x1FBF8808, Fields, -1 };
};

struct ManifestMP3Meta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1375802, 0, 1, 1, 0x6657BD0A, Fields, -1 };
};

struct MapMeta
{
    static constexpr DB2MetaField Fields[24] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_FLOAT, 2, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, true },
        { FT_SHORT, 1, true },
        { FT_SHORT, 1, true },
        { FT_SHORT, 1, true },
        { FT_BYTE, 1, false },
        { FT_FLOAT, 1, true },
        { FT_SHORT, 1, true },
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 3, true },
    };

    static constexpr DB2Meta Instance{ 1349477, -1, 24, 24, 0x15542FE8, Fields, -1 };
};

struct MapCelestialBodyMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_SHORT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1597466, -1, 3, 2, 0x3B420F88, Fields, 2 };
};

struct MapChallengeModeMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_SHORT, 3, true },
    };

    static constexpr DB2Meta Instance{ 801709, 1, 7, 7, 0xAAA9EAD7, Fields, 2 };
};

struct MapDifficultyMeta
{
    static constexpr DB2MetaField Fields[10] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1367868, -1, 10, 9, 0x43E2A417, Fields, 9 };
};

struct MapDifficultyXConditionMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1375435, -1, 4, 3, 0x08E872DB, Fields, 3 };
};

struct MapLoadingScreenMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_FLOAT, 2, true },
        { FT_FLOAT, 2, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1719707, -1, 5, 4, 0x2769A380, Fields, 4 };
};

struct MapRenderScaleMeta
{
    static constexpr DB2MetaField Fields[8] =
    {
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4633656, -1, 8, 8, 0x1D8358EA, Fields, -1 };
};

struct MarketingPromotionsXLocaleMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 801710, -1, 7, 7, 0x71B7DCCF, Fields, -1 };
};

struct MaterialMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1294217, -1, 4, 4, 0x3D758F88, Fields, -1 };
};

struct MawPowerMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2991315, 0, 3, 3, 0xE03BF02A, Fields, 1 };
};

struct MawPowerRarityMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2997952, -1, 2, 2, 0x7B5245E6, Fields, -1 };
};

struct MinorTalentMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1347274, -1, 3, 2, 0x5ACB3BD8, Fields, 2 };
};

struct MissileTargetingMeta
{
    static constexpr DB2MetaField Fields[12] =
    {
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 2, true },
        { FT_INT, 2, true },
    };

    static constexpr DB2Meta Instance{ 1710117, -1, 12, 12, 0x057C9AA8, Fields, -1 };
};

struct ModelAnimCloakDampeningMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1465904, -1, 3, 2, 0x070144A6, Fields, 2 };
};

struct ModelFileDataMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_FLOAT, 6, true },
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1337833, 1, 5, 5, 0x825A2247, Fields, 4 };
};

struct ModelRibbonQualityMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1399953, -1, 2, 1, 0x682023A4, Fields, 1 };
};

struct ModelSoundMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5393273, -1, 2, 2, 0x9A4E453C, Fields, -1 };
};

struct ModelSoundAnimEntryMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5393274, -1, 2, 2, 0x98809C50, Fields, 0 };
};

struct ModelSoundEntryMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5393275, -1, 1, 1, 0x870082C7, Fields, 0 };
};

struct ModelSoundOverrideMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5393276, -1, 2, 2, 0x5A6FC74A, Fields, 0 };
};

struct ModelSoundOverrideNameMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
    };

    static constexpr DB2Meta Instance{ 5512584, -1, 1, 1, 0x0F422F8A, Fields, -1 };
};

struct ModelSoundTagEntryMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5393277, -1, 6, 6, 0x66973320, Fields, 5 };
};

struct ModifiedCraftingCategoryMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3386486, -1, 5, 5, 0xB8B17FD4, Fields, -1 };
};

struct ModifiedCraftingItemMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4530643, 0, 3, 3, 0x16C3DB39, Fields, -1 };
};

struct ModifiedCraftingReagentItemMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3386487, -1, 6, 6, 0x705BAAB0, Fields, -1 };
};

struct ModifiedCraftingReagentSlotMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 3386488, 1, 6, 6, 0x24D8DB66, Fields, -1 };
};

struct ModifiedCraftingSpellSlotMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3390956, -1, 6, 6, 0x87027844, Fields, 0 };
};

struct ModifierTreeMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { FT_INT, 1, false },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1267645, -1, 7, 7, 0xD99C74EF, Fields, -1 };
};

struct MountMeta
{
    static constexpr DB2MetaField Fields[13] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 921760, 3, 13, 13, 0x9A3BFE1E, Fields, -1 };
};

struct MountCapabilityMeta
{
    static constexpr DB2MetaField Fields[9] =
    {
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_SHORT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1114709, -1, 9, 9, 0xF662BA9A, Fields, -1 };
};

struct MountEquipmentMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2923510, -1, 4, 3, 0x2B5121CB, Fields, 3 };
};

struct MountTypeMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 24, true },
    };

    static constexpr DB2Meta Instance{ 1114674, -1, 2, 2, 0x017C8C9F, Fields, -1 };
};

struct MountTypeXCapabilityMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1114715, -1, 3, 3, 0xF438693D, Fields, 0 };
};

struct MountXDisplayMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1576117, -1, 3, 2, 0xC9D09486, Fields, 2 };
};

struct MountXSpellVisualKitPickerMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3989477, -1, 5, 4, 0xD9F7D5F2, Fields, 4 };
};

struct MovieMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1332556, -1, 5, 5, 0x6C52E628, Fields, -1 };
};

struct MovieFileDataMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1301154, -1, 1, 1, 0x1A7EB62A, Fields, -1 };
};

struct MovieVariationMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1339819, -1, 3, 2, 0xC0C6C93B, Fields, 2 };
};

struct MultiStatePropertiesMeta
{
    static constexpr DB2MetaField Fields[11] =
    {
        { FT_FLOAT, 3, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1965592, -1, 11, 10, 0xBE0AE1EA, Fields, 10 };
};

struct MultiTransitionPropertiesMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1965589, -1, 5, 5, 0x20221E9D, Fields, -1 };
};

struct MusicOverrideMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 5161908, -1, 3, 3, 0xEE5D12BD, Fields, -1 };
};

struct MythicPlusSeasonMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2400282, 0, 4, 4, 0x0FE9B9A8, Fields, -1 };
};

struct MythicPlusSeasonRewardLevelsMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2123783, -1, 5, 5, 0xA1A30565, Fields, 0 };
};

struct MythicPlusSeasonTrackedAffixMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4067473, 0, 5, 4, 0x885D0924, Fields, 4 };
};

struct MythicPlusSeasonTrackedMapMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4521365, -1, 2, 1, 0x5B26E537, Fields, 1 };
};

struct NPCModelItemSlotDisplayInfoMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1340661, -1, 3, 2, 0x6345189C, Fields, 2 };
};

struct NPCSoundsMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 4, false },
    };

    static constexpr DB2Meta Instance{ 1282621, -1, 1, 1, 0x775B157B, Fields, -1 };
};

struct NameGenMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1122117, -1, 3, 3, 0xE43165A8, Fields, -1 };
};

struct NamesProfanityMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_BYTE, 1, true },
    };

    static constexpr DB2Meta Instance{ 1117086, -1, 2, 2, 0xA3B1057A, Fields, -1 };
};

struct NamesReservedMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
    };

    static constexpr DB2Meta Instance{ 1117085, -1, 1, 1, 0xA90C78EA, Fields, -1 };
};

struct NamesReservedLocaleMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1117087, -1, 2, 2, 0x4FC995DF, Fields, -1 };
};

struct NumTalentsAtLevelMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1953326, -1, 3, 3, 0xC31BC15A, Fields, -1 };
};

struct ObjectEffectMeta
{
    static constexpr DB2MetaField Fields[8] =
    {
        { FT_FLOAT, 3, true },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
        { FT_BYTE, 1, true },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1090577, -1, 8, 8, 0xB551B7D3, Fields, -1 };
};

struct ObjectEffectModifierMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_FLOAT, 4, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1090575, -1, 4, 4, 0xBCDA92E8, Fields, -1 };
};

struct ObjectEffectPackageElemMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1090578, -1, 3, 3, 0x4136FE8E, Fields, -1 };
};

struct OccluderMeta
{
    static constexpr DB2MetaField Fields[8] =
    {
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 2066958, -1, 8, 8, 0xD8AAC5E9, Fields, -1 };
};

struct OccluderCurtainMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3850529, -1, 6, 6, 0x4F3781D9, Fields, -1 };
};

struct OccluderLocationMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_FLOAT, 3, true },
        { FT_FLOAT, 3, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2115224, -1, 3, 3, 0xD83C5AA5, Fields, -1 };
};

struct OccluderNodeMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2066959, -1, 3, 3, 0x37234837, Fields, -1 };
};

struct OutlineEffectMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 2, false },
    };

    static constexpr DB2Meta Instance{ 1279739, -1, 6, 6, 0xB94FB0E3, Fields, -1 };
};

struct OverrideSpellDataMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 10, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1002186, -1, 3, 3, 0xDC04AC20, Fields, -1 };
};

struct PVPBracketTypesMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_BYTE, 1, true },
        { FT_INT, 4, false },
    };

    static constexpr DB2Meta Instance{ 1394275, -1, 2, 2, 0xF8C41353, Fields, -1 };
};

struct PVPDifficultyMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1339820, -1, 4, 3, 0x6CAB5565, Fields, 3 };
};

struct PVPItemMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 972287, -1, 2, 2, 0x95A06BE9, Fields, -1 };
};

struct PVPScoreboardCellInfoMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2992916, -1, 3, 3, 0xC8E134F3, Fields, 0 };
};

struct PVPScoreboardColumnHeaderMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2992917, -1, 4, 4, 0x10110777, Fields, -1 };
};

struct PVPScoreboardLayoutMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2992918, -1, 3, 3, 0x57EBF225, Fields, 0 };
};

struct PVPStatMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2992919, 1, 3, 3, 0x33F25E0C, Fields, 2 };
};

struct PageTextMaterialMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
    };

    static constexpr DB2Meta Instance{ 1271600, -1, 1, 1, 0xA0F05238, Fields, -1 };
};

struct PaperDollItemFrameMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1252503, -1, 3, 3, 0xA5067654, Fields, -1 };
};

struct ParagonReputationMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1581183, -1, 3, 3, 0xA78A1B30, Fields, -1 };
};

struct ParticleColorMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 3, true },
        { FT_INT, 3, true },
        { FT_INT, 3, true },
    };

    static constexpr DB2Meta Instance{ 1284820, -1, 3, 3, 0xBD3FBADC, Fields, -1 };
};

struct ParticulateMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3396285, -1, 2, 2, 0x2203AD67, Fields, -1 };
};

struct ParticulateSoundMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2053913, -1, 5, 5, 0x01C167D7, Fields, 0 };
};

struct PathMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 801732, -1, 7, 7, 0xAB4D8ED6, Fields, -1 };
};

struct PathEdgeMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 2, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2428705, -1, 2, 1, 0x3FAF3C23, Fields, 1 };
};

struct PathNodeMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 801733, -1, 3, 3, 0x37234837, Fields, -1 };
};

struct PathNodePropertyMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 801734, -1, 4, 4, 0xEC27351D, Fields, -1 };
};

struct PathPropertyMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 801735, -1, 3, 3, 0x635DCADD, Fields, -1 };
};

struct PerksActivityMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4519766, 2, 7, 7, 0x4FF9AFB2, Fields, -1 };
};

struct PerksActivityConditionMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5524226, 0, 4, 3, 0x6DD21FC7, Fields, 3 };
};

struct PerksActivityTagMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 4694317, 1, 2, 2, 0x0FBA68B8, Fields, -1 };
};

struct PerksActivityThresholdMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4519767, 0, 5, 4, 0xF25916E9, Fields, 4 };
};

struct PerksActivityThresholdGroupMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4519768, 1, 3, 3, 0x780A31D9, Fields, -1 };
};

struct PerksActivityXHolidaysMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5330797, -1, 2, 1, 0x9B7FB7C6, Fields, 1 };
};

struct PerksActivityXIntervalMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4519781, 0, 3, 2, 0xA0A40503, Fields, 2 };
};

struct PerksActivityXTagMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4694318, 0, 3, 2, 0x5254EC49, Fields, 2 };
};

struct PerksUIThemeMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5389878, 0, 3, 3, 0x10119030, Fields, -1 };
};

struct PerksVendorCategoryMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4281310, 1, 4, 4, 0x94980739, Fields, -1 };
};

struct PerksVendorItemMeta
{
    static constexpr DB2MetaField Fields[9] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4281311, 0, 9, 9, 0x80A50418, Fields, -1 };
};

struct PerksVendorItemUIGroupMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5386256, 1, 3, 3, 0x3C22481A, Fields, -1 };
};

struct PerksVendorItemUIInfoMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4281312, 0, 4, 4, 0x8F2F6861, Fields, -1 };
};

struct PerksVendorItemXIntervalMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4872513, -1, 2, 2, 0xD8D92220, Fields, -1 };
};

struct PhaseMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1348558, -1, 1, 1, 0x3CC972C6, Fields, -1 };
};

struct PhaseShiftZoneSoundsMeta
{
    static constexpr DB2MetaField Fields[13] =
    {
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1267336, -1, 13, 13, 0x846C026E, Fields, -1 };
};

struct PhaseXPhaseGroupMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 987581, -1, 2, 1, 0xEC8D5E98, Fields, 1 };
};

struct PingTypeMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5152358, -1, 5, 5, 0x0CE5C49B, Fields, -1 };
};

struct PlayerConditionMeta
{
    static constexpr DB2MetaField Fields[84] =
    {
        { FT_LONG, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, false },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_SHORT, 4, false },
        { FT_SHORT, 4, false },
        { FT_SHORT, 4, false },
        { FT_INT, 3, false },
        { FT_BYTE, 3, false },
        { FT_INT, 4, true },
        { FT_INT, 4, true },
        { FT_INT, 4, true },
        { FT_INT, 4, true },
        { FT_INT, 4, true },
        { FT_INT, 4, false },
        { FT_SHORT, 2, false },
        { FT_INT, 2, false },
        { FT_INT, 4, true },
        { FT_BYTE, 4, false },
        { FT_SHORT, 4, false },
        { FT_SHORT, 4, false },
        { FT_BYTE, 4, false },
        { FT_BYTE, 4, false },
        { FT_INT, 4, false },
        { FT_INT, 4, false },
        { FT_INT, 4, false },
        { FT_INT, 6, false },
        { FT_INT, 2, true },
        { FT_INT, 4, true },
        { FT_SHORT, 4, false },
        { FT_SHORT, 4, false },
    };

    static constexpr DB2Meta Instance{ 1045411, -1, 84, 84, 0xEE0F1EDC, Fields, -1 };
};

struct PlayerDataFlagAccountMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5426706, -1, 1, 1, 0x5C476AE6, Fields, -1 };
};

struct PlayerDataFlagCharacterMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5426708, -1, 1, 1, 0x5C476AE6, Fields, -1 };
};

struct PositionerMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_FLOAT, 1, true },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1251523, -1, 4, 4, 0xCBBBBD15, Fields, -1 };
};

struct PositionerStateMeta
{
    static constexpr DB2MetaField Fields[8] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_FLOAT, 1, true },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1251506, -1, 8, 8, 0x0276AAB6, Fields, -1 };
};

struct PositionerStateEntryMeta
{
    static constexpr DB2MetaField Fields[11] =
    {
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, false },
        { FT_SHORT, 1, true },
        { FT_SHORT, 1, true },
        { FT_SHORT, 1, true },
        { FT_SHORT, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
    };

    static constexpr DB2Meta Instance{ 1251533, -1, 11, 11, 0x10BB0190, Fields, -1 };
};

struct PowerDisplayMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1332557, -1, 5, 5, 0xE9B4E78C, Fields, -1 };
};

struct PowerTypeMeta
{
    static constexpr DB2MetaField Fields[13] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_INT, 1, false },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_SHORT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1266022, 2, 13, 13, 0xE8AC7EEC, Fields, -1 };
};

struct PrestigeLevelInfoMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1275869, -1, 5, 5, 0xB4AE6313, Fields, -1 };
};

struct ProfTraitPathNodeMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4542069, 0, 5, 5, 0x93D92E33, Fields, -1 };
};

struct ProfTraitPerkNodeMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4542084, 0, 4, 4, 0x53D97158, Fields, -1 };
};

struct ProfTraitTreeMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4542085, 0, 2, 2, 0x55614ED1, Fields, -1 };
};

struct ProfTraitTreeHighlightMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4999865, -1, 3, 2, 0xCC9F815F, Fields, 2 };
};

struct ProfessionMeta
{
    static constexpr DB2MetaField Fields[12] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4508544, 0, 12, 12, 0x2E97F732, Fields, -1 };
};

struct ProfessionEffectMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4505297, -1, 3, 3, 0xB42F4258, Fields, -1 };
};

struct ProfessionEffectTypeMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4556715, -1, 2, 1, 0xFE8414F9, Fields, 1 };
};

struct ProfessionPropPointsMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_FLOAT, 2, true },
        { FT_FLOAT, 2, true },
        { FT_FLOAT, 2, true },
        { FT_INT, 2, false },
        { FT_INT, 2, false },
        { FT_INT, 2, false },
    };

    static constexpr DB2Meta Instance{ 4452078, -1, 6, 6, 0xE2DEF177, Fields, -1 };
};

struct ProfessionRatingMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4623413, 2, 6, 5, 0x78F181BD, Fields, 5 };
};

struct ProfessionTraitMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4505298, 0, 2, 2, 0xFB4B3FF8, Fields, -1 };
};

struct ProfessionTraitXEffectMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4505494, 0, 4, 4, 0x86D1D9C8, Fields, 1 };
};

struct ProfessionTraitXLabelMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4505299, 0, 3, 3, 0x3234BADF, Fields, 1 };
};

struct ProfessionXRatingMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4868299, -1, 3, 3, 0x72DDE591, Fields, -1 };
};

struct PvpBrawlMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1585723, 3, 7, 7, 0x8D15C420, Fields, -1 };
};

struct PvpRatingMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4699082, -1, 4, 4, 0xF3D01273, Fields, -1 };
};

struct PvpScalingEffectMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1591100, -1, 3, 3, 0x63F0BE5D, Fields, 1 };
};

struct PvpScalingEffectTypeMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
    };

    static constexpr DB2Meta Instance{ 1591098, -1, 1, 1, 0xB21E02AE, Fields, -1 };
};

struct PvpSeasonMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2966426, -1, 3, 3, 0x8623DD7F, Fields, -1 };
};

struct PvpSeasonRewardLevelsMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2470695, -1, 4, 3, 0x8BAE9DBE, Fields, 3 };
};

struct PvpTalentMeta
{
    static constexpr DB2MetaField Fields[10] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1302853, 1, 10, 10, 0xEC6943FA, Fields, 2 };
};

struct PvpTalentCategoryMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1891534, -1, 1, 1, 0x93410D30, Fields, -1 };
};

struct PvpTalentSlotUnlockMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1950197, -1, 4, 4, 0xA08CCB66, Fields, -1 };
};

struct PvpTierMeta
{
    static constexpr DB2MetaField Fields[9] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_SHORT, 1, true },
        { FT_SHORT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2066871, 1, 9, 9, 0x80FD72F9, Fields, 6 };
};

struct QuestFactionRewardMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_SHORT, 10, true },
    };

    static constexpr DB2Meta Instance{ 1282622, -1, 1, 1, 0xE6DC889F, Fields, -1 };
};

struct QuestFeedbackEffectMeta
{
    static constexpr DB2MetaField Fields[8] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1343388, -1, 8, 8, 0x4FF1C55A, Fields, -1 };
};

struct QuestInfoMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_STRING, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1120960, -1, 4, 4, 0x8CE69EF5, Fields, -1 };
};

struct QuestLabelMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5202058, -1, 2, 1, 0x1E62975A, Fields, 1 };
};

struct QuestLineMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 973430, -1, 5, 5, 0xA360A782, Fields, -1 };
};

struct QuestLineXQuestMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 973441, -1, 4, 4, 0xABFF78E8, Fields, 0 };
};

struct QuestMoneyRewardMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 10, false },
    };

    static constexpr DB2Meta Instance{ 1139047, -1, 1, 1, 0xBFB6413C, Fields, -1 };
};

struct QuestObjectiveMeta
{
    static constexpr DB2MetaField Fields[8] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1251960, -1, 8, 7, 0x6F7AE236, Fields, 7 };
};

struct QuestPOIBlobMeta
{
    static constexpr DB2MetaField Fields[10] =
    {
        { FT_INT, 1, false },
        { FT_SHORT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1251882, 0, 10, 10, 0x714523FD, Fields, 1 };
};

struct QuestPOIPointMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_INT, 1, false },
        { FT_SHORT, 1, true },
        { FT_SHORT, 1, true },
        { FT_SHORT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1251883, 0, 5, 4, 0x38867756, Fields, 4 };
};

struct QuestPackageItemMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 801743, -1, 4, 4, 0xA2C252CF, Fields, -1 };
};

struct QuestSortMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_STRING, 1, true },
        { FT_BYTE, 1, true },
    };

    static constexpr DB2Meta Instance{ 1134585, -1, 2, 2, 0x1DDCABD9, Fields, -1 };
};

struct QuestV2Meta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1139443, -1, 2, 2, 0xB2004732, Fields, -1 };
};

struct QuestV2CliTaskMeta
{
    static constexpr DB2MetaField Fields[24] =
    {
        { FT_LONG, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_SHORT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_SHORT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 3, true },
        { FT_INT, 3, false },
    };

    static constexpr DB2Meta Instance{ 1028735, -1, 24, 24, 0x3F80A435, Fields, -1 };
};

struct QuestXGroupActivityMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1573634, -1, 2, 2, 0x6642C715, Fields, -1 };
};

struct QuestXPMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_SHORT, 10, false },
    };

    static constexpr DB2Meta Instance{ 1139378, -1, 1, 1, 0xCC84B93E, Fields, -1 };
};

struct QuestXUIQuestDetailsThemeMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3448517, -1, 2, 2, 0x1AE2FA16, Fields, -1 };
};

struct QuestXUiWidgetSetMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3923421, -1, 2, 2, 0x2B4CA6A1, Fields, -1 };
};

struct RTPCMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3405439, 0, 6, 6, 0x32115955, Fields, 5 };
};

struct RTPCDataMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3405440, -1, 5, 5, 0xFB37E702, Fields, 0 };
};

struct RafActivityMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3081207, -1, 2, 2, 0x64C41FC9, Fields, -1 };
};

struct RandPropPointsMeta
{
    static constexpr DB2MetaField Fields[10] =
    {
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 5, true },
        { FT_FLOAT, 5, true },
        { FT_FLOAT, 5, true },
        { FT_INT, 5, false },
        { FT_INT, 5, false },
        { FT_INT, 5, false },
    };

    static constexpr DB2Meta Instance{ 1310245, -1, 10, 10, 0xC35A699D, Fields, -1 };
};

struct RecipeProgressionGroupEntryMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3671785, -1, 6, 6, 0x5481052D, Fields, 0 };
};

struct RelicSlotTierRequirementMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1716803, -1, 3, 3, 0xB83E9EBE, Fields, -1 };
};

struct RelicTalentMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1671256, -1, 5, 5, 0xE2CB2DDC, Fields, -1 };
};

struct RenownRewardsMeta
{
    static constexpr DB2MetaField Fields[18] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3743117, -1, 18, 18, 0xB1FF79CA, Fields, 3 };
};

struct ResearchBranchMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_STRING, 1, true },
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1133729, -1, 6, 6, 0xAD4D7AD8, Fields, -1 };
};

struct ResearchFieldMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_STRING, 1, true },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1133711, -1, 2, 2, 0x3767B1BF, Fields, -1 };
};

struct ResearchProjectMeta
{
    static constexpr DB2MetaField Fields[8] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1134090, -1, 8, 8, 0x97798A9D, Fields, -1 };
};

struct ResearchSiteMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_STRING, 1, true },
        { FT_SHORT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1134091, -1, 4, 4, 0x7906CEDE, Fields, -1 };
};

struct ResistancesMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_STRING, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1135072, -1, 3, 3, 0xCE78DB9B, Fields, -1 };
};

struct RewardPackMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_BYTE, 1, true },
        { FT_FLOAT, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1307156, -1, 6, 6, 0x214B9595, Fields, -1 };
};

struct RewardPackXCurrencyTypeMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1307153, -1, 3, 2, 0x5692D477, Fields, 2 };
};

struct RewardPackXItemMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1307155, -1, 3, 2, 0x219E3F5D, Fields, 2 };
};

struct RibbonQualityMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_BYTE, 1, false },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1398908, -1, 5, 5, 0x8B3DD1B3, Fields, -1 };
};

struct RopeEffectMeta
{
    static constexpr DB2MetaField Fields[9] =
    {
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3256786, -1, 9, 9, 0xC049D78F, Fields, -1 };
};

struct RuneforgeLegendaryAbilityMeta
{
    static constexpr DB2MetaField Fields[11] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3500241, 1, 11, 11, 0x35605374, Fields, -1 };
};

struct SDReplacementModelMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1712172, -1, 1, 1, 0x9415B157, Fields, -1 };
};

struct SSAOSettingsMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2056369, -1, 7, 7, 0xE18F5D96, Fields, -1 };
};

struct ScenarioMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_STRING, 1, true },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1139062, -1, 5, 5, 0x6CEEC7F6, Fields, -1 };
};

struct ScenarioEventEntryMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1141065, -1, 2, 2, 0x8643ED17, Fields, -1 };
};

struct ScenarioStepMeta
{
    static constexpr DB2MetaField Fields[11] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_SHORT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1132761, -1, 11, 11, 0x12DAED63, Fields, 2 };
};

struct SceneScriptMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 801754, -1, 3, 3, 0xF24D5AEA, Fields, -1 };
};

struct SceneScriptGlobalTextMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_STRING_NOT_LOCALIZED, 1, true },
    };

    static constexpr DB2Meta Instance{ 1758036, -1, 2, 2, 0x8239EFCD, Fields, -1 };
};

struct SceneScriptPackageMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 801755, -1, 2, 2, 0x5642AF7C, Fields, -1 };
};

struct SceneScriptPackageMemberMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 801756, -1, 4, 4, 0xD2EA425C, Fields, 0 };
};

struct SceneScriptTextMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_STRING_NOT_LOCALIZED, 1, true },
    };

    static constexpr DB2Meta Instance{ 1758037, -1, 2, 2, 0x8239EFCD, Fields, -1 };
};

struct ScheduledIntervalMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1327082, -1, 5, 5, 0xBD3FEB04, Fields, -1 };
};

struct ScreenEffectMeta
{
    static constexpr DB2MetaField Fields[12] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_INT, 4, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_SHORT, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1302849, -1, 12, 12, 0x49CD4814, Fields, -1 };
};

struct ScreenEffectTypeMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3063174, -1, 1, 1, 0x807C06A3, Fields, -1 };
};

struct ScreenLocationMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
    };

    static constexpr DB2Meta Instance{ 1279416, -1, 1, 1, 0x8730B3B5, Fields, -1 };
};

struct SeamlessSiteMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1328719, -1, 1, 1, 0x60B3CFFF, Fields, 0 };
};

struct ServerMessagesMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_STRING, 1, true },
    };

    static constexpr DB2Meta Instance{ 1301141, -1, 1, 1, 0xBF527CAF, Fields, -1 };
};

struct ShadowyEffectMeta
{
    static constexpr DB2MetaField Fields[13] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1239844, -1, 13, 13, 0x65EF6B87, Fields, -1 };
};

struct SharedStringMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 4620073, 1, 3, 3, 0x31B665AF, Fields, -1 };
};

struct SiegeablePropertiesMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1954391, -1, 4, 4, 0xD237D615, Fields, -1 };
};

struct SkillLineMeta
{
    static constexpr DB2MetaField Fields[15] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_INT, 1, false },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1240935, 5, 15, 15, 0xF0D60375, Fields, -1 };
};

struct SkillLineAbilityMeta
{
    static constexpr DB2MetaField Fields[17] =
    {
        { FT_LONG, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_SHORT, 1, true },
        { FT_INT, 1, true },
        { FT_SHORT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
        { FT_SHORT, 1, true },
        { FT_SHORT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
        { FT_SHORT, 1, true },
        { FT_SHORT, 1, true },
        { FT_SHORT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1266278, 3, 17, 17, 0x1D9E00B1, Fields, 4 };
};

struct SkillLineXTraitTreeMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4505477, -1, 3, 3, 0xB2E9968F, Fields, 0 };
};

struct SkillRaceClassInfoMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { FT_LONG, 1, true },
        { FT_SHORT, 1, true },
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_SHORT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1240406, -1, 7, 7, 0x0271228C, Fields, 1 };
};

struct SkySceneXPlayerConditionMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3581893, -1, 2, 1, 0x62B60407, Fields, 1 };
};

struct SoulbindMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3488583, -1, 6, 6, 0x9031600B, Fields, -1 };
};

struct SoulbindConduitMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3594380, -1, 4, 4, 0xD87C19D7, Fields, -1 };
};

struct SoulbindConduitEnhancedSocketMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4069554, -1, 2, 2, 0xC5F12335, Fields, -1 };
};

struct SoulbindConduitItemMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3604984, -1, 2, 2, 0x0378426E, Fields, -1 };
};

struct SoulbindConduitRankMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3620681, -1, 4, 3, 0x197CCA07, Fields, 3 };
};

struct SoulbindConduitRankPropertiesMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3858895, -1, 3, 3, 0x17D85084, Fields, -1 };
};

struct SoulbindUIDisplayInfoMeta
{
    static constexpr DB2MetaField Fields[8] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3490472, -1, 8, 8, 0xCED83DDB, Fields, -1 };
};

struct SoundAmbienceMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 2, false },
        { FT_INT, 2, false },
        { FT_INT, 2, false },
        { FT_INT, 2, false },
    };

    static constexpr DB2Meta Instance{ 1310628, -1, 7, 7, 0xCB856968, Fields, -1 };
};

struct SoundAmbienceFlavorMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1267065, -1, 3, 2, 0x36D1007C, Fields, 2 };
};

struct SoundBusMeta
{
    static constexpr DB2MetaField Fields[8] =
    {
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_FLOAT, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1310246, 0, 8, 7, 0x7854CF39, Fields, 7 };
};

struct SoundBusOverrideMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
        { FT_FLOAT, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1598732, 0, 7, 7, 0xF5BD8202, Fields, 1 };
};

struct SoundEmitterPillPointsMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_FLOAT, 3, true },
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1092317, -1, 2, 2, 0xFB1F432A, Fields, 1 };
};

struct SoundEmittersMeta
{
    static constexpr DB2MetaField Fields[12] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_FLOAT, 3, true },
        { FT_FLOAT, 3, true },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1092316, 3, 12, 11, 0xDCEA9A09, Fields, 11 };
};

struct SoundEnvelopeMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1693131, -1, 7, 7, 0x7C68FF4A, Fields, 0 };
};

struct SoundFilterMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
    };

    static constexpr DB2Meta Instance{ 1271601, -1, 1, 1, 0xB21E02AE, Fields, -1 };
};

struct SoundFilterElemMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_FLOAT, 9, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1267066, -1, 3, 2, 0xA934E155, Fields, 2 };
};

struct SoundKitMeta
{
    static constexpr DB2MetaField Fields[16] =
    {
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_BYTE, 1, true },
        { FT_FLOAT, 1, true },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1237434, -1, 16, 16, 0x170F2CC3, Fields, -1 };
};

struct SoundKitAdvancedMeta
{
    static constexpr DB2MetaField Fields[56] =
    {
        { FT_INT, 1, false },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1237436, -1, 56, 56, 0x864490D3, Fields, -1 };
};

struct SoundKitChildMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1307289, -1, 2, 2, 0x102526D8, Fields, 1 };
};

struct SoundKitEntryMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1237435, -1, 4, 4, 0x962B1DCC, Fields, 0 };
};

struct SoundKitFallbackMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1307288, -1, 2, 2, 0x006A5AA3, Fields, -1 };
};

struct SoundMixGroupMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4618887, -1, 5, 5, 0x25A56C20, Fields, -1 };
};

struct SoundOverrideMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1266542, -1, 5, 5, 0x61F508F8, Fields, -1 };
};

struct SoundParameterMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3405441, -1, 5, 5, 0xA84DAECD, Fields, -1 };
};

struct SoundProviderPreferencesMeta
{
    static constexpr DB2MetaField Fields[23] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_BYTE, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_SHORT, 1, true },
        { FT_SHORT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_SHORT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_SHORT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_BYTE, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1279417, -1, 23, 23, 0x06599A4D, Fields, -1 };
};

struct SoundWaterfallEmitterMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4756178, -1, 2, 2, 0xF82CAB0A, Fields, -1 };
};

struct SourceInfoMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_STRING, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1313612, -1, 4, 3, 0xF32B81DC, Fields, 3 };
};

struct SpamMessagesMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
    };

    static constexpr DB2Meta Instance{ 1117088, -1, 1, 1, 0xEF771036, Fields, -1 };
};

struct SpecSetMemberMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2057624, -1, 2, 1, 0x48C154DC, Fields, 1 };
};

struct SpecializationSpellsMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1240335, 1, 6, 6, 0xA524AD21, Fields, 2 };
};

struct SpecializationSpellsDisplayMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_SHORT, 1, false },
        { FT_INT, 6, false },
    };

    static constexpr DB2Meta Instance{ 2067238, -1, 2, 2, 0x2E79E9B0, Fields, 0 };
};

struct SpellMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
    };

    static constexpr DB2Meta Instance{ 1140089, -1, 3, 3, 0xE2395468, Fields, -1 };
};

struct SpellActionBarPrefMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1019373, -1, 2, 2, 0x5CB6468B, Fields, -1 };
};

struct SpellActivationOverlayMeta
{
    static constexpr DB2MetaField Fields[10] =
    {
        { FT_INT, 4, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1261603, -1, 10, 10, 0x67CA82D4, Fields, -1 };
};

struct SpellAuraOptionsMeta
{
    static constexpr DB2MetaField Fields[8] =
    {
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
        { FT_INT, 2, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1139952, -1, 8, 7, 0x584EB0C9, Fields, 7 };
};

struct SpellAuraRestrictionsMeta
{
    static constexpr DB2MetaField Fields[14] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 981566, -1, 14, 13, 0x78912DD7, Fields, 13 };
};

struct SpellAuraVisXChrSpecMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_SHORT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1280615, -1, 2, 1, 0x6402EE2B, Fields, 1 };
};

struct SpellAuraVisibilityMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, false },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1280616, 0, 4, 3, 0x398764D3, Fields, 3 };
};

struct SpellCastTimesMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1134089, -1, 2, 2, 0x3EC041D4, Fields, -1 };
};

struct SpellCastingRequirementsMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1002166, -1, 7, 7, 0x76B9E4FB, Fields, -1 };
};

struct SpellCategoriesMeta
{
    static constexpr DB2MetaField Fields[9] =
    {
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_SHORT, 1, true },
        { FT_SHORT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1139939, -1, 9, 8, 0xE1D0C5AC, Fields, 8 };
};

struct SpellCategoryMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1280619, -1, 6, 6, 0xF7647E24, Fields, -1 };
};

struct SpellChainEffectsMeta
{
    static constexpr DB2MetaField Fields[60] =
    {
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
        { FT_FLOAT, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, false },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_SHORT, 11, false },
        { FT_FLOAT, 3, true },
        { FT_FLOAT, 3, true },
        { FT_FLOAT, 3, true },
        { FT_FLOAT, 3, true },
        { FT_INT, 3, true },
    };

    static constexpr DB2Meta Instance{ 1343310, -1, 60, 60, 0x5DA65BBA, Fields, -1 };
};

struct SpellClassOptionsMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 4, true },
    };

    static constexpr DB2Meta Instance{ 979663, -1, 4, 4, 0x427E17F9, Fields, -1 };
};

struct SpellClutterAreaEffectCountsMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2428696, -1, 3, 3, 0x362D8889, Fields, -1 };
};

struct SpellClutterFrameRatesMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2428707, -1, 3, 3, 0x722797C7, Fields, -1 };
};

struct SpellClutterImpactModelCountsMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2428708, -1, 3, 3, 0x362D8889, Fields, -1 };
};

struct SpellClutterKitDistancesMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2428697, -1, 3, 3, 0x38C53911, Fields, -1 };
};

struct SpellClutterMissileDistMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2428733, -1, 3, 3, 0x38C53911, Fields, -1 };
};

struct SpellClutterWeaponTrailDistMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2428698, -1, 3, 3, 0x38C53911, Fields, -1 };
};

struct SpellCooldownsMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1139924, -1, 6, 5, 0x254654DD, Fields, 5 };
};

struct SpellDescriptionVariablesMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
    };

    static constexpr DB2Meta Instance{ 1140004, -1, 1, 1, 0x3846B8C4, Fields, -1 };
};

struct SpellDispelTypeMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_STRING, 1, true },
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1137829, -1, 4, 4, 0xD31E57F3, Fields, -1 };
};

struct SpellDurationMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1137828, -1, 2, 2, 0xC1591711, Fields, -1 };
};

struct SpellEffectMeta
{
    static constexpr DB2MetaField Fields[29] =
    {
        { FT_SHORT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 2, true },
        { FT_INT, 2, false },
        { FT_INT, 4, true },
        { FT_SHORT, 2, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1140088, -1, 29, 28, 0x0ADBA46F, Fields, 28 };
};

struct SpellEffectAutoDescriptionMeta
{
    static constexpr DB2MetaField Fields[9] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1888495, -1, 9, 9, 0x6DCEA74D, Fields, -1 };
};

struct SpellEffectEmissionMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_SHORT, 1, true },
        { FT_BYTE, 1, true },
    };

    static constexpr DB2Meta Instance{ 1310248, -1, 4, 4, 0x55D6415D, Fields, -1 };
};

struct SpellEmpowerMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4507381, 0, 3, 3, 0x7F1952AF, Fields, -1 };
};

struct SpellEmpowerStageMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4871072, -1, 3, 2, 0x6A138C60, Fields, 2 };
};

struct SpellEquippedItemsMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1140011, -1, 4, 4, 0x9E98F8F8, Fields, -1 };
};

struct SpellFlyoutMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_LONG, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1146819, -1, 6, 6, 0x0F34BE71, Fields, -1 };
};

struct SpellFlyoutItemMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1134085, -1, 3, 2, 0x5977DEAC, Fields, 2 };
};

struct SpellFocusObjectMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_STRING, 1, true },
    };

    static constexpr DB2Meta Instance{ 1280620, -1, 1, 1, 0xB0DD8F60, Fields, -1 };
};

struct SpellInterruptsMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, true },
        { FT_INT, 2, true },
        { FT_INT, 2, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1139906, -1, 5, 4, 0x15BFA3E0, Fields, 4 };
};

struct SpellItemEnchantmentMeta
{
    static constexpr DB2MetaField Fields[23] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 3, false },
        { FT_FLOAT, 3, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_SHORT, 3, true },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 3, false },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1362771, -1, 23, 23, 0xF7D222D6, Fields, -1 };
};

struct SpellItemEnchantmentConditionMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_BYTE, 5, false },
        { FT_INT, 5, false },
        { FT_BYTE, 5, false },
        { FT_BYTE, 5, false },
        { FT_BYTE, 5, false },
        { FT_BYTE, 5, false },
    };

    static constexpr DB2Meta Instance{ 1121834, -1, 6, 6, 0xC1340327, Fields, -1 };
};

struct SpellKeyboundOverrideMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1127327, -1, 4, 4, 0x3E33E322, Fields, -1 };
};

struct SpellLabelMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1347275, -1, 2, 1, 0x8FB85089, Fields, 1 };
};

struct SpellLearnSpellMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1001907, -1, 3, 3, 0x33C8C506, Fields, 0 };
};

struct SpellLevelsMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1140079, -1, 6, 5, 0x734BBB2C, Fields, 5 };
};

struct SpellMechanicMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_STRING, 1, true },
    };

    static constexpr DB2Meta Instance{ 1014438, -1, 1, 1, 0x4E0C4A43, Fields, -1 };
};

struct SpellMemorizeCostMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3549053, -1, 2, 1, 0x6F1A6B5A, Fields, 1 };
};

struct SpellMiscMeta
{
    static constexpr DB2MetaField Fields[16] =
    {
        { FT_INT, 15, true },
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1003144, -1, 16, 15, 0x22C4626A, Fields, 15 };
};

struct SpellMissileMeta
{
    static constexpr DB2MetaField Fields[15] =
    {
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 897956, -1, 15, 15, 0x8BE6A845, Fields, -1 };
};

struct SpellMissileMotionMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 897955, -1, 4, 4, 0x65CEAA0A, Fields, -1 };
};

struct SpellNameMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_STRING, 1, true },
    };

    static constexpr DB2Meta Instance{ 1990283, -1, 1, 1, 0xB0DD8F60, Fields, -1 };
};

struct SpellOverrideNameMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2618823, -1, 3, 3, 0xC38F6613, Fields, -1 };
};

struct SpellPowerMeta
{
    static constexpr DB2MetaField Fields[15] =
    {
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 982806, 0, 15, 14, 0xE5EED97C, Fields, 14 };
};

struct SpellPowerDifficultyMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 982804, -1, 2, 2, 0x831780E9, Fields, -1 };
};

struct SpellProceduralEffectMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_BYTE, 1, true },
        { FT_FLOAT, 4, true },
    };

    static constexpr DB2Meta Instance{ 1140477, -1, 2, 2, 0x860F778C, Fields, -1 };
};

struct SpellProcsPerMinuteMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_FLOAT, 1, true },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1133526, -1, 2, 2, 0x8398D285, Fields, -1 };
};

struct SpellProcsPerMinuteModMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1133525, -1, 4, 3, 0x2C6FC571, Fields, 3 };
};

struct SpellRadiusMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1134584, -1, 4, 4, 0x84246EAE, Fields, -1 };
};

struct SpellRangeMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_BYTE, 1, false },
        { FT_FLOAT, 2, true },
        { FT_FLOAT, 2, true },
    };

    static constexpr DB2Meta Instance{ 1146820, -1, 5, 5, 0x1A9D89B3, Fields, -1 };
};

struct SpellReagentsMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_INT, 1, true },
        { FT_INT, 8, true },
        { FT_SHORT, 8, true },
        { FT_SHORT, 8, true },
        { FT_BYTE, 8, false },
    };

    static constexpr DB2Meta Instance{ 841946, -1, 5, 5, 0xB40074F0, Fields, -1 };
};

struct SpellReagentsCurrencyMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1135239, -1, 3, 3, 0xA7C3638C, Fields, 0 };
};

struct SpellReplacementMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4674394, -1, 2, 2, 0x88FB6F2C, Fields, 0 };
};

struct SpellScalingMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_SHORT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1139940, -1, 4, 4, 0xDF5A7562, Fields, -1 };
};

struct SpellScriptMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3055899, -1, 5, 5, 0x7E8B242D, Fields, -1 };
};

struct SpellScriptTextMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3055901, 1, 5, 4, 0x035224C6, Fields, 4 };
};

struct SpellShapeshiftMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 2, true },
        { FT_INT, 2, true },
    };

    static constexpr DB2Meta Instance{ 1139929, -1, 4, 4, 0xCBF64431, Fields, -1 };
};

struct SpellShapeshiftFormMeta
{
    static constexpr DB2MetaField Fields[10] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
        { FT_SHORT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_SHORT, 1, false },
        { FT_INT, 8, false },
    };

    static constexpr DB2Meta Instance{ 1280618, -1, 10, 10, 0x887ACBCE, Fields, -1 };
};

struct SpellSpecialUnitEffectMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_SHORT, 1, false },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1268903, -1, 2, 2, 0x7739B9C5, Fields, -1 };
};

struct SpellTargetRestrictionsMeta
{
    static constexpr DB2MetaField Fields[8] =
    {
        { FT_BYTE, 1, false },
        { FT_FLOAT, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
        { FT_SHORT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1139993, -1, 8, 7, 0xAC82CF4B, Fields, 7 };
};

struct SpellTotemsMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_SHORT, 2, false },
        { FT_INT, 2, true },
    };

    static constexpr DB2Meta Instance{ 1002162, -1, 3, 3, 0x230DD39D, Fields, -1 };
};

struct SpellVisualMeta
{
    static constexpr DB2MetaField Fields[16] =
    {
        { FT_FLOAT, 3, true },
        { FT_FLOAT, 3, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 897952, -1, 16, 16, 0x536575A0, Fields, -1 };
};

struct SpellVisualAnimMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1140479, -1, 3, 3, 0x0D10BE24, Fields, -1 };
};

struct SpellVisualColorEffectMeta
{
    static constexpr DB2MetaField Fields[11] =
    {
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1094006, -1, 11, 11, 0x3D80C011, Fields, -1 };
};

struct SpellVisualEffectNameMeta
{
    static constexpr DB2MetaField Fields[15] =
    {
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
    };

    static constexpr DB2Meta Instance{ 897948, -1, 15, 15, 0xD10DE7C6, Fields, -1 };
};

struct SpellVisualEventMeta
{
    static constexpr DB2MetaField Fields[11] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1685317, -1, 11, 10, 0xC9A05AD5, Fields, 10 };
};

struct SpellVisualKitMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 2, true },
    };

    static constexpr DB2Meta Instance{ 897949, -1, 5, 5, 0xA2B96B8A, Fields, -1 };
};

struct SpellVisualKitAreaModelMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 897951, -1, 6, 6, 0xFBA6277D, Fields, -1 };
};

struct SpellVisualKitEffectMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1140480, -1, 3, 2, 0x5D2E222A, Fields, 2 };
};

struct SpellVisualKitModelAttachMeta
{
    static constexpr DB2MetaField Fields[22] =
    {
        { FT_FLOAT, 3, true },
        { FT_FLOAT, 3, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 897953, -1, 22, 21, 0x58DE8C95, Fields, 21 };
};

struct SpellVisualKitPickerMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3989478, -1, 2, 2, 0xE7A454BF, Fields, -1 };
};

struct SpellVisualKitPickerEntryMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3989479, -1, 3, 2, 0x6C80416B, Fields, 2 };
};

struct SpellVisualMissileMeta
{
    static constexpr DB2MetaField Fields[18] =
    {
        { FT_FLOAT, 3, true },
        { FT_FLOAT, 3, true },
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, false },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, false },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 897954, 2, 18, 17, 0x11D06D97, Fields, 17 };
};

struct SpellVisualScreenEffectMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3607312, -1, 2, 2, 0xDBF829D1, Fields, -1 };
};

struct SpellXDescriptionVariablesMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1724949, -1, 2, 2, 0x9A9D6850, Fields, -1 };
};

struct SpellXSpellVisualMeta
{
    static constexpr DB2MetaField Fields[13] =
    {
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1101657, 0, 13, 12, 0x049D96D6, Fields, 12 };
};

struct StartupFilesMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1604265, -1, 3, 3, 0x0DB4CD60, Fields, -1 };
};

struct Startup_StringsMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_STRING, 1, true },
    };

    static constexpr DB2Meta Instance{ 1375805, -1, 2, 2, 0xD81204F9, Fields, -1 };
};

struct StationeryMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 2, true },
    };

    static constexpr DB2Meta Instance{ 1140758, -1, 3, 3, 0xC47D5B55, Fields, -1 };
};

struct SummonPropertiesMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 2, true },
    };

    static constexpr DB2Meta Instance{ 1345276, -1, 5, 5, 0x927C6DBA, Fields, -1 };
};

struct TactKeyMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_BYTE, 16, false },
    };

    static constexpr DB2Meta Instance{ 1302850, -1, 1, 1, 0xD3F61A9E, Fields, -1 };
};

struct TactKeyLookupMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_BYTE, 8, false },
    };

    static constexpr DB2Meta Instance{ 1302851, -1, 1, 1, 0xB9312C4E, Fields, -1 };
};

struct TalentMeta
{
    static constexpr DB2MetaField Fields[9] =
    {
        { FT_STRING, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_BYTE, 2, false },
    };

    static constexpr DB2Meta Instance{ 1369062, -1, 9, 9, 0x75423537, Fields, -1 };
};

struct TaxiNodesMeta
{
    static constexpr DB2MetaField Fields[15] =
    {
        { FT_STRING, 1, true },
        { FT_FLOAT, 3, true },
        { FT_FLOAT, 2, true },
        { FT_FLOAT, 2, true },
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 2, true },
    };

    static constexpr DB2Meta Instance{ 1068100, 4, 15, 15, 0x5EE95BA9, Fields, 5 };
};

struct TaxiPathMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1067802, 0, 4, 4, 0x9B67699C, Fields, 1 };
};

struct TaxiPathNodeMeta
{
    static constexpr DB2MetaField Fields[9] =
    {
        { FT_FLOAT, 3, true },
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1000437, 1, 9, 9, 0xF1BEC205, Fields, 2 };
};

struct TerrainColorGradingRampMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3501705, -1, 4, 4, 0x02B6E85D, Fields, -1 };
};

struct TerrainMaterialMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1307290, -1, 3, 3, 0x499A04BC, Fields, -1 };
};

struct TerrainTypeMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1310249, -1, 5, 5, 0xD533642E, Fields, -1 };
};

struct TerrainTypeSoundsMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
    };

    static constexpr DB2Meta Instance{ 1284822, -1, 1, 1, 0x5462668A, Fields, -1 };
};

struct TextureBlendSetMeta
{
    static constexpr DB2MetaField Fields[11] =
    {
        { FT_INT, 3, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_FLOAT, 3, true },
        { FT_FLOAT, 3, true },
        { FT_FLOAT, 3, true },
        { FT_FLOAT, 3, true },
        { FT_FLOAT, 4, true },
    };

    static constexpr DB2Meta Instance{ 1328721, -1, 11, 11, 0x420979A8, Fields, -1 };
};

struct TextureFileDataMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 982459, 0, 3, 3, 0x1C9A021C, Fields, 2 };
};

struct TierTransitionMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3076928, -1, 4, 4, 0xE71F230A, Fields, -1 };
};

struct TotemCategoryMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_STRING, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1134586, -1, 3, 3, 0x81755C9C, Fields, -1 };
};

struct ToyMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, true },
    };

    static constexpr DB2Meta Instance{ 988200, 1, 5, 5, 0xED0030EE, Fields, -1 };
};

struct TradeSkillCategoryMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, true },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1301101, -1, 6, 6, 0x3C05077F, Fields, -1 };
};

struct TradeSkillItemMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1329070, -1, 1, 1, 0xD6BD8871, Fields, -1 };
};

struct TraitCondMeta
{
    static constexpr DB2MetaField Fields[15] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4543085, 0, 15, 15, 0x91F4174C, Fields, 2 };
};

struct TraitCostMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4420295, 1, 4, 4, 0xCECF8496, Fields, -1 };
};

struct TraitCurrencyMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4524216, 0, 5, 5, 0x5BF919EC, Fields, -1 };
};

struct TraitCurrencySourceMeta
{
    static constexpr DB2MetaField Fields[9] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4539393, 1, 9, 9, 0xD42C05FC, Fields, 2 };
};

struct TraitDefinitionMeta
{
    static constexpr DB2MetaField Fields[8] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4420327, 3, 8, 8, 0x05675F68, Fields, -1 };
};

struct TraitDefinitionEffectPointsMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4536895, 0, 5, 5, 0x5C22E1DB, Fields, 1 };
};

struct TraitEdgeMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4420308, 0, 5, 5, 0x32F9DD9A, Fields, 2 };
};

struct TraitNodeMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4420297, 0, 6, 6, 0x839579A1, Fields, 1 };
};

struct TraitNodeEntryMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 4420298, 0, 4, 4, 0x81B195E8, Fields, -1 };
};

struct TraitNodeEntryXTraitCondMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4543088, 0, 3, 3, 0x53ACC501, Fields, 2 };
};

struct TraitNodeEntryXTraitCostMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4420299, 0, 3, 3, 0x4178D9E2, Fields, 1 };
};

struct TraitNodeGroupMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4420300, 0, 3, 3, 0xF4E2E579, Fields, 1 };
};

struct TraitNodeGroupXTraitCondMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4543090, 0, 3, 3, 0x28117816, Fields, 2 };
};

struct TraitNodeGroupXTraitCostMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4420301, 0, 3, 3, 0x97B85B29, Fields, 1 };
};

struct TraitNodeGroupXTraitNodeMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4420302, 0, 4, 4, 0xD91D6CFE, Fields, 1 };
};

struct TraitNodeXTraitCondMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4543092, 0, 3, 3, 0xFEFA16A7, Fields, 2 };
};

struct TraitNodeXTraitCostMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4420303, 0, 3, 3, 0x883FDE7A, Fields, 1 };
};

struct TraitNodeXTraitNodeEntryMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4420304, 0, 4, 4, 0xCED10275, Fields, 1 };
};

struct TraitSystemMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4635649, 0, 3, 3, 0xD92E8FE4, Fields, -1 };
};

struct TraitTreeMeta
{
    static constexpr DB2MetaField Fields[8] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4420305, 0, 8, 8, 0xCA7B3D57, Fields, 1 };
};

struct TraitTreeLoadoutMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4669507, 0, 3, 3, 0xDE3BFB35, Fields, 1 };
};

struct TraitTreeLoadoutEntryMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4669509, 0, 6, 6, 0x3B3D126A, Fields, 1 };
};

struct TraitTreeXTraitCostMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4420306, 0, 3, 3, 0x823738BA, Fields, 1 };
};

struct TraitTreeXTraitCurrencyMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4524218, 0, 4, 4, 0x298B67E6, Fields, 2 };
};

struct TransformMatrixMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_FLOAT, 3, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1338702, -1, 5, 5, 0x92BCCC4C, Fields, -1 };
};

struct TransmogDefaultLevelMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2399695, -1, 2, 2, 0x95FD2CA2, Fields, -1 };
};

struct TransmogHolidayMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1589454, -1, 1, 1, 0xE3B900BB, Fields, -1 };
};

struct TransmogIllusionMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3580450, 0, 5, 5, 0x3DDD0672, Fields, -1 };
};

struct TransmogSetMeta
{
    static constexpr DB2MetaField Fields[13] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_SHORT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1376213, 1, 13, 13, 0x5B0E178F, Fields, 7 };
};

struct TransmogSetGroupMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_STRING, 1, true },
    };

    static constexpr DB2Meta Instance{ 1576116, -1, 1, 1, 0xE59553DF, Fields, -1 };
};

struct TransmogSetItemMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1376212, -1, 3, 3, 0x7273E272, Fields, 0 };
};

struct TransportAnimationMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_FLOAT, 3, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1140686, -1, 4, 3, 0x5C89E4E6, Fields, 3 };
};

struct TransportPhysicsMeta
{
    static constexpr DB2MetaField Fields[10] =
    {
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1121973, -1, 10, 10, 0x3BE86156, Fields, -1 };
};

struct TransportRotationMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_FLOAT, 4, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1140687, -1, 3, 2, 0xC1124B6A, Fields, 2 };
};

struct TrophyMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_STRING, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 975024, -1, 4, 4, 0x72D11E6D, Fields, -1 };
};

struct UIArrowCalloutMeta
{
    static constexpr DB2MetaField Fields[9] =
    {
        { FT_STRING, 1, true },
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5011999, 2, 9, 9, 0xC42C586B, Fields, -1 };
};

struct UIChromieTimeExpansionInfoMeta
{
    static constexpr DB2MetaField Fields[13] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3488582, -1, 13, 13, 0x7C1717CE, Fields, -1 };
};

struct UICovenantAbilityMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3502042, -1, 4, 4, 0x11D03E08, Fields, 0 };
};

struct UICovenantPreviewMeta
{
    static constexpr DB2MetaField Fields[16] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3502043, 2, 16, 16, 0xDBB74257, Fields, -1 };
};

struct UIDeadlyDebuffMeta
{
    static constexpr DB2MetaField Fields[8] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4579858, 1, 8, 8, 0xFE4E561B, Fields, -1 };
};

struct UIDungeonScoreRarityMeta
{
    static constexpr DB2MetaField Fields[12] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4065278, 0, 12, 12, 0xC8D50D38, Fields, -1 };
};

struct UIEventToastMeta
{
    static constexpr DB2MetaField Fields[22] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3946498, 6, 22, 22, 0xE0B754D7, Fields, -1 };
};

struct UIExpansionDisplayInfoMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1729547, 0, 6, 6, 0x64FFA4B9, Fields, -1 };
};

struct UIExpansionDisplayInfoIconMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1729546, -1, 3, 3, 0xB5FB76BF, Fields, -1 };
};

struct UIGenericWidgetDisplayMeta
{
    static constexpr DB2MetaField Fields[10] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4861207, 3, 10, 10, 0x15320583, Fields, -1 };
};

struct UIModifiedInstanceMeta
{
    static constexpr DB2MetaField Fields[8] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4530951, -1, 8, 8, 0x1948D0B5, Fields, -1 };
};

struct UIScriptedAnimationEffectMeta
{
    static constexpr DB2MetaField Fields[26] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3556601, -1, 26, 26, 0xD9F17C48, Fields, -1 };
};

struct UISplashScreenMeta
{
    static constexpr DB2MetaField Fields[15] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2960122, -1, 15, 15, 0x5C67BB80, Fields, -1 };
};

struct UiCamFbackTransmogChrRaceMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1261406, -1, 5, 5, 0x7C47244B, Fields, -1 };
};

struct UiCamFbackTransmogWeaponMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1261407, -1, 4, 4, 0xB6F384A3, Fields, -1 };
};

struct UiCameraMeta
{
    static constexpr DB2MetaField Fields[9] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_FLOAT, 3, true },
        { FT_FLOAT, 3, true },
        { FT_FLOAT, 3, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_SHORT, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1120287, -1, 9, 9, 0x2F44A4B5, Fields, -1 };
};

struct UiCameraTypeMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1120288, -1, 3, 3, 0xB158BEC0, Fields, -1 };
};

struct UiCanvasMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_SHORT, 1, true },
        { FT_SHORT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1989363, -1, 2, 2, 0xB4407510, Fields, -1 };
};

struct UiCovenantDisplayInfoMeta
{
    static constexpr DB2MetaField Fields[13] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3509132, -1, 13, 13, 0xFB57169A, Fields, -1 };
};

struct UiItemInteractionMeta
{
    static constexpr DB2MetaField Fields[17] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3182424, -1, 17, 17, 0x4F85D70D, Fields, -1 };
};

struct UiMapMeta
{
    static constexpr DB2MetaField Fields[14] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1957206, 1, 14, 14, 0x69A8C369, Fields, 2 };
};

struct UiMapArtMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1957202, -1, 3, 3, 0xED57CAFB, Fields, -1 };
};

struct UiMapArtStyleLayerMeta
{
    static constexpr DB2MetaField Fields[9] =
    {
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1957208, -1, 9, 8, 0x7D2E349A, Fields, 8 };
};

struct UiMapArtTileMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1957210, -1, 5, 4, 0xB262E4E9, Fields, 4 };
};

struct UiMapAssignmentMeta
{
    static constexpr DB2MetaField Fields[10] =
    {
        { FT_FLOAT, 2, true },
        { FT_FLOAT, 2, true },
        { FT_FLOAT, 6, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1957219, 3, 10, 10, 0xFA228778, Fields, 4 };
};

struct UiMapFogOfWarMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2006972, 0, 4, 4, 0x437EAE73, Fields, 1 };
};

struct UiMapFogOfWarVisualizationMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2006973, -1, 3, 3, 0x6337502A, Fields, -1 };
};

struct UiMapGroupMemberMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
    };

    static constexpr DB2Meta Instance{ 1957204, -1, 5, 5, 0xBD83EBDC, Fields, 1 };
};

struct UiMapLinkMeta
{
    static constexpr DB2MetaField Fields[10] =
    {
        { FT_FLOAT, 2, true },
        { FT_FLOAT, 2, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2030690, 2, 10, 10, 0x11F6CF6C, Fields, 3 };
};

struct UiMapXMapArtMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1957217, -1, 3, 2, 0x517CED19, Fields, 2 };
};

struct UiModelSceneMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, false },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1548215, 0, 4, 4, 0xD6CFDD08, Fields, -1 };
};

struct UiModelSceneActorMeta
{
    static constexpr DB2MetaField Fields[10] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_FLOAT, 3, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1548214, 2, 10, 10, 0x6B7EE2AC, Fields, 3 };
};

struct UiModelSceneActorDisplayMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1548216, -1, 7, 7, 0xF4A979A2, Fields, -1 };
};

struct UiModelSceneCameraMeta
{
    static constexpr DB2MetaField Fields[16] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_FLOAT, 3, true },
        { FT_FLOAT, 3, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1548213, 3, 16, 16, 0x1C131B80, Fields, 4 };
};

struct UiPartyPoseMeta
{
    static constexpr DB2MetaField Fields[10] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1993323, 1, 10, 9, 0xF02E09B6, Fields, 9 };
};

struct UiQuestDetailsThemeMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3448518, -1, 4, 4, 0xAF517528, Fields, -1 };
};

struct UiTextureAtlasMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 897470, 0, 5, 5, 0x84691E24, Fields, -1 };
};

struct UiTextureAtlasElementMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1989276, 1, 2, 2, 0x402AB955, Fields, -1 };
};

struct UiTextureAtlasElementSliceDataMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 5319042, 0, 7, 7, 0x105CAB2E, Fields, -1 };
};

struct UiTextureAtlasMemberMeta
{
    static constexpr DB2MetaField Fields[12] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, true },
        { FT_SHORT, 1, true },
        { FT_SHORT, 1, true },
        { FT_SHORT, 1, true },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, true },
        { FT_SHORT, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 897532, 1, 12, 12, 0x2BD64311, Fields, 7 };
};

struct UiTextureKitMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
    };

    static constexpr DB2Meta Instance{ 939159, -1, 1, 1, 0x5B96D427, Fields, -1 };
};

struct UiWeeklyRewardMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4737221, 0, 4, 4, 0x03D3F36F, Fields, -1 };
};

struct UiWidgetMeta
{
    static constexpr DB2MetaField Fields[9] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1983278, 1, 9, 9, 0xD38CBB29, Fields, -1 };
};

struct UiWidgetConstantSourceMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1983639, -1, 3, 2, 0x4960D0A0, Fields, 2 };
};

struct UiWidgetDataSourceMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1983640, -1, 4, 3, 0xF2B11731, Fields, 3 };
};

struct UiWidgetMapMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2322531, -1, 2, 1, 0xF9ADC09E, Fields, 1 };
};

struct UiWidgetSetMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3055925, -1, 2, 2, 0x271866B0, Fields, -1 };
};

struct UiWidgetStringSourceMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_STRING, 1, true },
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1983641, -1, 3, 2, 0xA23E18E8, Fields, 2 };
};

struct UiWidgetVisTypeDataReqMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2740907, 1, 6, 5, 0x5FB9338F, Fields, 5 };
};

struct UiWidgetVisualizationMeta
{
    static constexpr DB2MetaField Fields[10] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_SHORT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1983276, -1, 10, 10, 0xC3CDAA95, Fields, -1 };
};

struct UiWidgetXWidgetSetMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3386363, -1, 2, 1, 0x7704E8C2, Fields, 1 };
};

struct UnitBloodMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1284821, -1, 6, 6, 0x0FF08208, Fields, -1 };
};

struct UnitBloodLevelsMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_BYTE, 3, false },
    };

    static constexpr DB2Meta Instance{ 1268904, -1, 1, 1, 0xCF406CD7, Fields, -1 };
};

struct UnitConditionMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_BYTE, 1, false },
        { FT_BYTE, 8, false },
        { FT_BYTE, 8, true },
        { FT_INT, 8, true },
    };

    static constexpr DB2Meta Instance{ 1120959, -1, 4, 4, 0x383D75FD, Fields, -1 };
};

struct UnitPowerBarMeta
{
    static constexpr DB2MetaField Fields[16] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 6, true },
        { FT_INT, 6, true },
    };

    static constexpr DB2Meta Instance{ 1237753, -1, 16, 16, 0xE815439F, Fields, -1 };
};

struct VehicleMeta
{
    static constexpr DB2MetaField Fields[18] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
        { FT_SHORT, 8, false },
        { FT_SHORT, 3, false },
    };

    static constexpr DB2Meta Instance{ 1368621, -1, 18, 18, 0xC064602E, Fields, -1 };
};

struct VehiclePOITypeMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3311405, -1, 5, 5, 0xC5DB21A0, Fields, -1 };
};

struct VehicleSeatMeta
{
    static constexpr DB2MetaField Fields[61] =
    {
        { FT_FLOAT, 3, true },
        { FT_FLOAT, 3, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_SHORT, 1, true },
        { FT_BYTE, 1, true },
        { FT_SHORT, 1, true },
        { FT_BYTE, 1, true },
        { FT_SHORT, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_SHORT, 1, true },
        { FT_SHORT, 1, true },
        { FT_SHORT, 1, true },
        { FT_SHORT, 1, true },
        { FT_SHORT, 1, true },
        { FT_SHORT, 1, true },
        { FT_SHORT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1345447, -1, 61, 61, 0x8FE8854B, Fields, -1 };
};

struct VehicleUIIndSeatMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_BYTE, 1, false },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1279741, -1, 4, 3, 0xB64B1BD8, Fields, 3 };
};

struct VehicleUIIndicatorMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1279740, -1, 1, 1, 0xB127675D, Fields, -1 };
};

struct VignetteMeta
{
    static constexpr DB2MetaField Fields[10] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 892861, -1, 10, 10, 0xEC171292, Fields, -1 };
};

struct VirtualAttachmentMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_SHORT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1634482, -1, 2, 2, 0x96EE7037, Fields, -1 };
};

struct VirtualAttachmentCustomizationMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_SHORT, 1, true },
        { FT_INT, 1, true },
        { FT_SHORT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1634480, -1, 3, 3, 0xE7753F5C, Fields, -1 };
};

struct VocalUISoundsMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 2, false },
    };

    static constexpr DB2Meta Instance{ 1267067, -1, 4, 4, 0x38987A6C, Fields, -1 };
};

struct VoiceOverPriorityMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4211372, -1, 3, 3, 0xA54084F0, Fields, -1 };
};

struct VolumeFogConditionMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3587230, -1, 4, 3, 0xA8C126ED, Fields, 3 };
};

struct WMOAreaTableMeta
{
    static constexpr DB2MetaField Fields[15] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1355528, 1, 15, 15, 0xCD7AF6E0, Fields, 2 };
};

struct WMOMinimapTextureMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1323241, -1, 5, 4, 0x2A1E430A, Fields, 4 };
};

struct WaterfallDataMeta
{
    static constexpr DB2MetaField Fields[19] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2565222, -1, 19, 19, 0x2169A76A, Fields, -1 };
};

struct WaypointEdgeMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2565258, -1, 5, 5, 0x0E663F8B, Fields, -1 };
};

struct WaypointNodeMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2565265, -1, 6, 6, 0xCE16D4A6, Fields, -1 };
};

struct WaypointSafeLocsMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_FLOAT, 3, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2820850, -1, 2, 2, 0xEB35FD5C, Fields, -1 };
};

struct WbAccessControlListMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 879634, -1, 5, 5, 0xF9DAF847, Fields, -1 };
};

struct WeaponImpactSoundsMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 11, false },
        { FT_INT, 11, false },
        { FT_INT, 11, false },
        { FT_INT, 11, false },
    };

    static constexpr DB2Meta Instance{ 1267648, -1, 7, 7, 0xCC11734B, Fields, -1 };
};

struct WeaponSwingSounds2Meta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1267068, -1, 3, 3, 0x7F3FBC0A, Fields, -1 };
};

struct WeaponTrailMeta
{
    static constexpr DB2MetaField Fields[9] =
    {
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 3, true },
        { FT_FLOAT, 3, true },
        { FT_FLOAT, 3, true },
        { FT_FLOAT, 3, true },
        { FT_FLOAT, 3, true },
    };

    static constexpr DB2Meta Instance{ 982461, -1, 9, 9, 0xCD83E5F9, Fields, -1 };
};

struct WeaponTrailModelDefMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1239843, -1, 3, 2, 0xC737CAD2, Fields, 2 };
};

struct WeaponTrailParamMeta
{
    static constexpr DB2MetaField Fields[10] =
    {
        { FT_BYTE, 1, false },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1239842, -1, 10, 9, 0xDC6EF9B4, Fields, 9 };
};

struct WeatherMeta
{
    static constexpr DB2MetaField Fields[23] =
    {
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 2, true },
        { FT_FLOAT, 3, true },
    };

    static constexpr DB2Meta Instance{ 1343311, -1, 23, 23, 0x354627A5, Fields, -1 };
};

struct WeatherXParticulateMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1965591, -1, 2, 1, 0xD6E739FE, Fields, 1 };
};

struct WeeklyRewardChestActivityTierMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5390446, 0, 3, 3, 0x4265F6DC, Fields, -1 };
};

struct WeeklyRewardChestThresholdMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3580962, -1, 3, 3, 0xBEF159C4, Fields, -1 };
};

struct WindSettingsMeta
{
    static constexpr DB2MetaField Fields[10] =
    {
        { FT_FLOAT, 3, true },
        { FT_FLOAT, 3, true },
        { FT_FLOAT, 3, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 943871, -1, 10, 10, 0xE359B6F6, Fields, -1 };
};

struct WorldBossLockoutMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 975279, -1, 2, 2, 0x245D9086, Fields, -1 };
};

struct WorldChunkSoundsMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1267069, -1, 7, 7, 0x589C31E5, Fields, -1 };
};

struct WorldEffectMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1343312, -1, 6, 6, 0x79117AA9, Fields, -1 };
};

struct WorldElapsedTimerMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_STRING, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1135240, -1, 3, 3, 0x30FF7138, Fields, -1 };
};

struct WorldLayerMapSetMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4550228, 2, 4, 4, 0x64C69433, Fields, -1 };
};

struct WorldMapOverlayMeta
{
    static constexpr DB2MetaField Fields[13] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 4, false },
    };

    static constexpr DB2Meta Instance{ 1134579, 0, 13, 13, 0x00F18FC5, Fields, 1 };
};

struct WorldMapOverlayTileMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1957212, -1, 5, 4, 0x341D6DB6, Fields, 4 };
};

struct WorldShadowMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_FLOAT, 2, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4680120, -1, 4, 4, 0x11BC9DDD, Fields, -1 };
};

struct WorldStateExpressionMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
    };

    static constexpr DB2Meta Instance{ 1332558, -1, 1, 1, 0x6695F131, Fields, -1 };
};

struct WorldStateZoneSoundsMeta
{
    static constexpr DB2MetaField Fields[9] =
    {
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1266941, -1, 9, 9, 0x52C5ECE9, Fields, -1 };
};

struct World_PVP_AreaMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1310255, -1, 7, 7, 0xDB4FFDE0, Fields, -1 };
};

struct ZoneIntroMusicTableMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1310251, -1, 4, 4, 0xBEB0D6B9, Fields, -1 };
};

struct ZoneLightMeta
{
    static constexpr DB2MetaField Fields[8] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1310253, -1, 8, 8, 0xF6796C55, Fields, -1 };
};

struct ZoneLightPointMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_FLOAT, 2, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1310256, -1, 3, 2, 0x99D8C676, Fields, 2 };
};

struct ZoneMusicMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_INT, 2, false },
        { FT_INT, 2, false },
        { FT_INT, 2, false },
    };

    static constexpr DB2Meta Instance{ 1310254, -1, 4, 4, 0x7894E43E, Fields, -1 };
};

struct ZoneStoryMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1797864, -1, 4, 3, 0x4C6C5CD7, Fields, 3 };
};

#endif // DB2Metadata_h__
