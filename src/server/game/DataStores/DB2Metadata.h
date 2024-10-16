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
    static constexpr DB2MetaField Fields[19] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_SHORT, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
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
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1260179, 3, 19, 19, 0x31925D4B, Fields, 11 };
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

    static constexpr DB2Meta Instance{ 1324299, 1, 4, 4, 0x67B2B4BD, Fields, 3 };
};

struct ActionBarGroupMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4572795, -1, 1, 1, 0xBBBE80CE, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 4572797, -1, 5, 4, 0xF28AF796, Fields, 4 };
};

struct AdventureJournalMeta
{
    static constexpr DB2MetaField Fields[20] =
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
        { FT_SHORT, 1, false },
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 2, false },
        { FT_BYTE, 2, false },
    };

    static constexpr DB2Meta Instance{ 1115949, -1, 20, 20, 0x88BFAFA8, Fields, -1 };
};

struct AdventureJournalItemMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5599873, -1, 5, 4, 0x2A065EC6, Fields, 4 };
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

    static constexpr DB2Meta Instance{ 1267070, -1, 12, 12, 0x8672E9D5, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1710672, -1, 8, 8, 0x979EBCE5, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 5156218, 0, 4, 4, 0xDDEF5F2D, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 5156219, -1, 4, 4, 0xBF516172, Fields, -1 };
};

struct AltMinimapWMOMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5156220, -1, 2, 2, 0xC6594274, Fields, -1 };
};

struct AnimKitMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1304323, -1, 3, 3, 0xDA4C91AF, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1375433, -1, 5, 5, 0x43E7736F, Fields, -1 };
};

struct AnimKitBoneSetAliasMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1266937, -1, 2, 2, 0x19A6986C, Fields, -1 };
};

struct AnimKitConfigMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1300872, -1, 1, 1, 0x140718EF, Fields, -1 };
};

struct AnimKitConfigBoneSetMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1300873, -1, 3, 2, 0x482E3ED3, Fields, 2 };
};

struct AnimKitPriorityMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1266540, -1, 1, 1, 0xCCF889D8, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1559807, 0, 5, 4, 0xD9A65034, Fields, 4 };
};

struct AnimKitSegmentMeta
{
    static constexpr DB2MetaField Fields[19] =
    {
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, true },
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

    static constexpr DB2Meta Instance{ 1304324, -1, 19, 19, 0xA6C970CA, Fields, 0 };
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

    static constexpr DB2Meta Instance{ 1301100, 0, 5, 4, 0x61B149CC, Fields, 4 };
};

struct AnimReplacementSetMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1284817, -1, 1, 1, 0x7C047695, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 3286805, -1, 35, 35, 0xC7843A94, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 3286804, -1, 7, 7, 0x351564A7, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 3153990, -1, 31, 31, 0xEE2975D2, Fields, -1 };
};

struct AnimationDataMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, true },
        { FT_INT, 2, true },
    };

    static constexpr DB2Meta Instance{ 1375431, -1, 4, 4, 0x18A959FC, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 2123730, 1, 5, 4, 0xFFC38678, Fields, 4 };
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

    static constexpr DB2Meta Instance{ 1537162, -1, 4, 4, 0x56BEE3FC, Fields, -1 };
};

struct AreaGroupMemberMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1093406, -1, 2, 1, 0x6746D145, Fields, 1 };
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

    static constexpr DB2Meta Instance{ 1000630, 2, 21, 21, 0x5F5EE2EF, Fields, 12 };
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

    static constexpr DB2Meta Instance{ 1000631, -1, 5, 4, 0x60943110, Fields, 4 };
};

struct AreaPOIUiWidgetSetMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 5634691, -1, 3, 3, 0xCE229645, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1353545, -1, 23, 23, 0x9864CADF, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1354401, 1, 15, 15, 0xC9EC1745, Fields, 2 };
};

struct AreaTriggerActionSetMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1352378, -1, 1, 1, 0x6D5EB3BD, Fields, -1 };
};

struct AreaTriggerBoundedPlaneMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_FLOAT, 2, true },
    };

    static constexpr DB2Meta Instance{ 4266572, -1, 1, 1, 0x6BD39F3C, Fields, -1 };
};

struct AreaTriggerBoxMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_FLOAT, 3, true },
    };

    static constexpr DB2Meta Instance{ 1332554, -1, 1, 1, 0xC934FE5D, Fields, -1 };
};

struct AreaTriggerCreatePropertiesMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_BYTE, 1, true },
        { FT_SHORT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1937227, -1, 3, 3, 0xAEDFD657, Fields, -1 };
};

struct AreaTriggerCylinderMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1121943, -1, 3, 3, 0xC54F3688, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 4223661, -1, 4, 4, 0xC7E0D346, Fields, -1 };
};

struct AreaTriggerSphereMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1315630, -1, 1, 1, 0xB851EBF6, Fields, -1 };
};

struct ArenaTrackedItemMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5226140, -1, 3, 3, 0xFB956EB0, Fields, 1 };
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

    static constexpr DB2Meta Instance{ 1284818, -1, 5, 5, 0xFB67352F, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1007934, 1, 11, 11, 0x8194B69D, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1116407, 1, 16, 16, 0x4E8E48F3, Fields, 2 };
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

    static constexpr DB2Meta Instance{ 1116408, 2, 9, 8, 0xAA95B5A7, Fields, 8 };
};

struct ArtifactCategoryMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_SHORT, 1, true },
        { FT_SHORT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1376210, -1, 2, 2, 0xEE30ED65, Fields, -1 };
};

struct ArtifactItemToTransmogMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2029780, -1, 3, 3, 0x847F68D6, Fields, 0 };
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

    static constexpr DB2Meta Instance{ 1007937, 1, 7, 7, 0xEAA59D67, Fields, 2 };
};

struct ArtifactPowerLinkMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1133731, -1, 2, 2, 0x6929FE1C, Fields, -1 };
};

struct ArtifactPowerPickerMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1597467, -1, 1, 1, 0x39566E31, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1261405, -1, 5, 4, 0x39F69979, Fields, 4 };
};

struct ArtifactQuestXPMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 10, false },
    };

    static constexpr DB2Meta Instance{ 1036203, -1, 1, 1, 0x01D6219A, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1600114, -1, 5, 5, 0xA9FC62B2, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1094540, -1, 5, 4, 0xA71AB31F, Fields, 4 };
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

    static constexpr DB2Meta Instance{ 1237439, -1, 4, 4, 0x9D007DB2, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 4366440, 2, 10, 10, 0xCF37C344, Fields, 7 };
};

struct AzeriteEmpoweredItemMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1846046, -1, 3, 3, 0x48AC4E05, Fields, -1 };
};

struct AzeriteEssenceMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2829665, -1, 3, 3, 0xCCE26295, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 2829666, -1, 8, 8, 0x2EB43EDD, Fields, -1 };
};

struct AzeriteItemMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1846048, -1, 1, 1, 0x3923C31A, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1915395, -1, 4, 4, 0x4B01B39E, Fields, -1 };
};

struct AzeriteKnowledgeMultiplierMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3148050, -1, 1, 1, 0x47546927, Fields, -1 };
};

struct AzeriteLevelInfoMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_LONG, 1, false },
        { FT_LONG, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3147968, -1, 3, 3, 0x22722A9A, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1846044, -1, 4, 4, 0xEC6B5E70, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1846040, -1, 5, 5, 0x91D7F535, Fields, 0 };
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

    static constexpr DB2Meta Instance{ 1846043, -1, 4, 3, 0xFE36FA5C, Fields, 3 };
};

struct AzeriteTierUnlockSetMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2446322, -1, 1, 1, 0x65273FFD, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 2564314, -1, 5, 4, 0xD052621C, Fields, 4 };
};

struct BankBagSlotPricesMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1284819, -1, 1, 1, 0xDBCA3459, Fields, -1 };
};

struct BankTabMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_LONG, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5242411, -1, 4, 4, 0xD47B62CA, Fields, -1 };
};

struct BannedAddonsMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1373459, -1, 3, 3, 0xC7F734D9, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1237437, -1, 7, 7, 0xD86F8C4D, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 2499852, -1, 12, 12, 0x0FE8427F, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 841610, -1, 7, 7, 0xAAD491D2, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 801575, 0, 7, 7, 0x221D1FE6, Fields, 1 };
};

struct BattlePetAbilityStateMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 801576, -1, 3, 2, 0x3381AC8D, Fields, 2 };
};

struct BattlePetAbilityTurnMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 801577, 0, 6, 6, 0x20C3BE16, Fields, 1 };
};

struct BattlePetBreedQualityMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 801578, -1, 3, 3, 0xF3E3FDFC, Fields, -1 };
};

struct BattlePetBreedStateMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 801579, -1, 3, 2, 0x030182F5, Fields, 2 };
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

    static constexpr DB2Meta Instance{ 1802988, -1, 4, 3, 0xFC2D3715, Fields, 3 };
};

struct BattlePetEffectPropertiesMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_STRING_NOT_LOCALIZED, 6, true },
        { FT_SHORT, 1, false },
        { FT_BYTE, 6, false },
    };

    static constexpr DB2Meta Instance{ 801580, -1, 3, 3, 0xED4FBC95, Fields, -1 };
};

struct BattlePetNPCTeamMemberMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_STRING, 1, true },
    };

    static constexpr DB2Meta Instance{ 841648, -1, 1, 1, 0x782EE721, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 841622, 2, 12, 12, 0x589BE282, Fields, -1 };
};

struct BattlePetSpeciesStateMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 801581, -1, 3, 2, 0x2ABE26A5, Fields, 2 };
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

    static constexpr DB2Meta Instance{ 801582, -1, 4, 3, 0x69104208, Fields, 3 };
};

struct BattlePetStateMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 801583, -1, 3, 3, 0x489B22AD, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 801584, -1, 7, 7, 0x257B890E, Fields, -1 };
};

struct BattlemasterListMeta
{
    static constexpr DB2MetaField Fields[16] =
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
    };

    static constexpr DB2Meta Instance{ 1360265, -1, 16, 16, 0x0063AE4C, Fields, -1 };
};

struct BattlemasterListXMapMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5916746, -1, 2, 1, 0x449D9C1C, Fields, 1 };
};

struct BattlepayCurrencyMeta
{
    static constexpr DB2MetaField Fields[8] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5549327, 4, 8, 8, 0x38F48A2E, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1525607, -1, 10, 10, 0xC4C53E61, Fields, -1 };
};

struct BoneWindModifierModelMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1467254, -1, 2, 2, 0xF84A16EF, Fields, 0 };
};

struct BoneWindModifiersMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_FLOAT, 3, true },
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1416756, -1, 2, 2, 0x2CD1770E, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1983274, -1, 4, 4, 0x567FCB5C, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1367866, -1, 5, 4, 0xEF863306, Fields, 4 };
};

struct BountySetMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1367865, -1, 2, 2, 0x487670F7, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 841604, 2, 12, 12, 0xA5F4A303, Fields, -1 };
};

struct BroadcastTextDurationMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2166900, -1, 3, 3, 0xE60CAC24, Fields, 0 };
};

struct CameraEffectMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1117695, -1, 1, 1, 0x1B09C75D, Fields, -1 };
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
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1117696, -1, 16, 15, 0x00CFA83A, Fields, 15 };
};

struct CameraModeMeta
{
    static constexpr DB2MetaField Fields[12] =
    {
        { FT_FLOAT, 3, true },
        { FT_FLOAT, 3, true },
        { FT_INT, 1, true },
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

    static constexpr DB2Meta Instance{ 1343308, -1, 12, 12, 0x2AD4ECDE, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 2031607, -1, 13, 13, 0x4D8139BB, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 2031611, -1, 5, 4, 0x7A8A4E75, Fields, 4 };
};

struct CampaignXQuestLineMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 2036722, -1, 3, 3, 0x703CADAB, Fields, 0 };
};

struct CastableRaidBuffsMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1283018, -1, 2, 1, 0x63E1AEB7, Fields, 1 };
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

    static constexpr DB2Meta Instance{ 1592470, -1, 14, 14, 0x7C85C5E0, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1068162, -1, 6, 6, 0x5ED75B84, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1080949, -1, 4, 4, 0xE7594137, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1082876, -1, 5, 5, 0x8CDAAC27, Fields, -1 };
};

struct ChallengeModeItemBonusOverrideMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2965645, -1, 5, 4, 0x095B5B95, Fields, 4 };
};

struct CharBaseInfoMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1343386, -1, 3, 3, 0xCBCCA287, Fields, -1 };
};

struct CharBaseSectionMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1375798, -1, 3, 3, 0xCCB98D5E, Fields, -1 };
};

struct CharComponentTextureLayoutsMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1360262, -1, 2, 2, 0x0B9AF134, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1360263, -1, 7, 7, 0x2173BA71, Fields, 0 };
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

    static constexpr DB2Meta Instance{ 1256914, -1, 11, 11, 0x41E34B0F, Fields, 0 };
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

    static constexpr DB2Meta Instance{ 2388725, -1, 6, 5, 0x0EC8D97C, Fields, 5 };
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

    static constexpr DB2Meta Instance{ 972425, -1, 9, 9, 0x91BEA68A, Fields, 0 };
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

    static constexpr DB2Meta Instance{ 972405, -1, 16, 16, 0xC3E07E9C, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 3055696, -1, 16, 15, 0x53D4BFF2, Fields, 15 };
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

    static constexpr DB2Meta Instance{ 1349054, -1, 4, 4, 0x1EEF17FF, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1369752, -1, 4, 4, 0xEC412D3B, Fields, -1 };
};

struct CharacterLoadoutMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_LONG, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1344281, -1, 4, 4, 0xBC929075, Fields, -1 };
};

struct CharacterLoadoutItemMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_SHORT, 1, false },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1302846, -1, 2, 2, 0x0C7A1862, Fields, 0 };
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

    static constexpr DB2Meta Instance{ 3724843, -1, 4, 3, 0xB4B8349E, Fields, 3 };
};

struct CharacterServiceInfoMeta
{
    static constexpr DB2MetaField Fields[13] =
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
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1815417, -1, 13, 13, 0xD31E4776, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1345278, -1, 5, 5, 0xD5E402DC, Fields, -1 };
};

struct ChatProfanityMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_BYTE, 1, true },
    };

    static constexpr DB2Meta Instance{ 1117084, -1, 2, 2, 0x7EACA150, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1306188, -1, 6, 6, 0xA2F2B211, Fields, -1 };
};

struct ChrClassTitleMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1267497, -1, 3, 3, 0x9771B69D, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 3754770, -1, 4, 4, 0xCE0676C0, Fields, -1 };
};

struct ChrClassUIDisplayMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1316515, -1, 3, 3, 0xE6877A46, Fields, -1 };
};

struct ChrClassVillainMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_STRING, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, true },
    };

    static constexpr DB2Meta Instance{ 1267498, -1, 3, 3, 0x449C6890, Fields, -1 };
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
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1361031, 10, 39, 39, 0xB3938245, Fields, -1 };
};

struct ChrClassesXPowerTypesMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1121420, -1, 2, 1, 0xD625E75C, Fields, 1 };
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

    static constexpr DB2Meta Instance{ 3671168, -1, 7, 6, 0x951CEB58, Fields, 6 };
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

    static constexpr DB2Meta Instance{ 3671169, 0, 4, 3, 0xD5A84E5B, Fields, 3 };
};

struct ChrCustClientChoiceConversionMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3590348, -1, 3, 2, 0x48271419, Fields, 2 };
};

struct ChrCustGeoComponentLinkMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5387095, -1, 1, 1, 0x892316B4, Fields, -1 };
};

struct ChrCustItemGeoModifyMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3952714, -1, 3, 3, 0xFE865CC3, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1611874, -1, 7, 6, 0xB5F3C6B5, Fields, 6 };
};

struct ChrCustomizationBoneSetMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3460181, -1, 2, 2, 0xCC2CFF6E, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 3526439, -1, 8, 8, 0x1605B68A, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 3450554, 1, 11, 11, 0x9559C358, Fields, 2 };
};

struct ChrCustomizationCondModelMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 4, true },
    };

    static constexpr DB2Meta Instance{ 3460182, -1, 2, 2, 0x601A4522, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 3463337, -1, 8, 8, 0xA31CB58D, Fields, 4 };
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

    static constexpr DB2Meta Instance{ 3593032, -1, 5, 5, 0xB24CE54F, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 3512765, -1, 13, 13, 0x6483C37E, Fields, -1 };
};

struct ChrCustomizationGeosetMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3456171, -1, 3, 3, 0x44C80DEB, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 5347591, -1, 6, 6, 0xE9159047, Fields, -1 };
};

struct ChrCustomizationMaterialMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3459652, -1, 2, 2, 0xBE9767E9, Fields, -1 };
};

struct ChrCustomizationOptionMeta
{
    static constexpr DB2MetaField Fields[15] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
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
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3384247, 1, 15, 15, 0x3F9B06FB, Fields, 6 };
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

    static constexpr DB2Meta Instance{ 3450453, -1, 8, 8, 0x618D5A55, Fields, -1 };
};

struct ChrCustomizationReqChoiceMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3580359, -1, 2, 1, 0xF925BC6F, Fields, 1 };
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

    static constexpr DB2Meta Instance{ 3460183, -1, 5, 5, 0xE447963A, Fields, -1 };
};

struct ChrCustomizationVisReqMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4724136, -1, 2, 2, 0x52C27B83, Fields, -1 };
};

struct ChrCustomizationVoiceMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_BYTE, 1, true },
    };

    static constexpr DB2Meta Instance{ 4672833, -1, 1, 1, 0x03684BD2, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 3384313, 2, 17, 17, 0x03FAB755, Fields, 4 };
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

    static constexpr DB2Meta Instance{ 3566562, 0, 7, 7, 0x22469480, Fields, 1 };
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

    static constexpr DB2Meta Instance{ 3548976, -1, 9, 8, 0xD0583FB4, Fields, 8 };
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

    static constexpr DB2Meta Instance{ 3507821, -1, 6, 5, 0x0FC0F0D5, Fields, 5 };
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

    static constexpr DB2Meta Instance{ 3490304, -1, 4, 4, 0x6D1E51C9, Fields, 0 };
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

    static constexpr DB2Meta Instance{ 1305311, -1, 52, 52, 0xFBB0AF72, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 4566929, 0, 4, 4, 0x24C83D97, Fields, 1 };
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

    static constexpr DB2Meta Instance{ 5320971, -1, 4, 4, 0x4A9D37A3, Fields, -1 };
};

struct ChrSelectBackgroundCDIMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4195187, -1, 3, 3, 0xECF7F0D1, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1343390, 3, 13, 13, 0xE5FCCC5B, Fields, 4 };
};

struct ChrUpgradeBucketMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 984529, 0, 3, 2, 0x0FFDE299, Fields, 2 };
};

struct ChrUpgradeBucketSpellMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 984528, -1, 2, 1, 0x666AF1D3, Fields, 1 };
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

    static constexpr DB2Meta Instance{ 984530, 1, 4, 4, 0xA0CEF7CA, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1294214, -1, 5, 5, 0x8BFD752B, Fields, -1 };
};

struct CinematicSequencesMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, false },
        { FT_SHORT, 8, false },
    };

    static constexpr DB2Meta Instance{ 1134583, -1, 2, 2, 0x07D874FF, Fields, -1 };
};

struct ClientSceneEffectMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1939843, -1, 1, 1, 0xF3B2D340, Fields, -1 };
};

struct ClientSettingsMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5874295, 1, 5, 5, 0x0ACED075, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1465903, -1, 7, 7, 0x4D53C04B, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 2175218, -1, 8, 8, 0x65C255A4, Fields, -1 };
};

struct CollectableSourceEncounterMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5152111, 0, 2, 1, 0xFC4F6701, Fields, 1 };
};

struct CollectableSourceEncounterSparseMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5152908, -1, 3, 2, 0xC7F0206A, Fields, 2 };
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

    static constexpr DB2Meta Instance{ 5152112, 1, 4, 4, 0x2EFCC218, Fields, -1 };
};

struct CollectableSourceQuestMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5205183, -1, 1, 1, 0x49EA6C2C, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 5205600, -1, 5, 4, 0x434EEF8A, Fields, 4 };
};

struct CollectableSourceVendorMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5163410, 0, 3, 2, 0xB6FB0394, Fields, 2 };
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

    static constexpr DB2Meta Instance{ 5159897, -1, 7, 6, 0x1EC1925C, Fields, 6 };
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

    static constexpr DB2Meta Instance{ 1120958, -1, 11, 11, 0xE4823C69, Fields, -1 };
};

struct CommentatorIndirectSpellMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3067644, -1, 3, 2, 0x2DD1B7F8, Fields, 2 };
};

struct CommentatorStartLocationMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_FLOAT, 3, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1664251, -1, 2, 2, 0x8EA27BA8, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1661584, -1, 6, 5, 0xCF118CBC, Fields, 5 };
};

struct CommunityIconMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2098645, -1, 2, 2, 0x7737DBB7, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1349053, -1, 4, 4, 0x070B9B9A, Fields, -1 };
};

struct ComponentTextureFileDataMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1278239, -1, 3, 3, 0x6B7CDBEA, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 5211412, 0, 6, 6, 0x8236CAE9, Fields, 1 };
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

    static constexpr DB2Meta Instance{ 3501965, -1, 4, 3, 0x15616FBC, Fields, 3 };
};

struct ConditionalCreatureModelDataMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 4, true },
    };

    static constexpr DB2Meta Instance{ 5525474, -1, 4, 4, 0xC974B48B, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 5345180, -1, 6, 5, 0x5303936C, Fields, 5 };
};

struct ConfigurationWarningMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1709409, -1, 2, 2, 0xE476B573, Fields, -1 };
};

struct ContentPushMeta
{
    static constexpr DB2MetaField Fields[9] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5742435, -1, 9, 9, 0xE12AA1EF, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 4668112, -1, 8, 7, 0xB9C0B42E, Fields, 7 };
};

struct ContentRestrictionRuleSetMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4281307, 0, 3, 3, 0xFE3B102A, Fields, -1 };
};

struct ContentTuningMeta
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
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1962930, 0, 15, 15, 0x7B58533B, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 2976765, -1, 4, 3, 0x897A4313, Fields, 3 };
};

struct ContentTuningXLabelMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4659576, -1, 2, 1, 0xCFAAE43E, Fields, 1 };
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

    static constexpr DB2Meta Instance{ 1587153, -1, 6, 6, 0x2310FD57, Fields, 2 };
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

    static constexpr DB2Meta Instance{ 2143633, -1, 7, 7, 0x88C22204, Fields, -1 };
};

struct ContributionStyleContainerMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 5, true },
    };

    static constexpr DB2Meta Instance{ 2143634, -1, 1, 1, 0x8879F685, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1260801, -1, 9, 9, 0xAA1E7988, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 3220711, -1, 4, 4, 0xFD8BA257, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 3384973, -1, 10, 10, 0xB8563783, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 4545611, 0, 16, 16, 0xC21C854F, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 4659601, -1, 4, 3, 0x39F2F30B, Fields, 3 };
};

struct CraftingDataItemQualityMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4545612, -1, 2, 1, 0xDE11A051, Fields, 1 };
};

struct CraftingDifficultyMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4373536, -1, 7, 7, 0x7744A1A6, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 4373537, 0, 6, 5, 0xE2C031D4, Fields, 5 };
};

struct CraftingOrderMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4529122, -1, 3, 3, 0x05F8699D, Fields, -1 };
};

struct CraftingOrderHouseMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_FLOAT, 1, true },
        { FT_INT, 3, true },
    };

    static constexpr DB2Meta Instance{ 4688652, -1, 2, 2, 0x807F433C, Fields, -1 };
};

struct CraftingOrderXLabelMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5875491, 0, 3, 3, 0x4AA53C3A, Fields, 1 };
};

struct CraftingQualityMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4373538, -1, 1, 1, 0xD0952E97, Fields, -1 };
};

struct CraftingReagentEffectMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4541803, -1, 3, 2, 0x70597398, Fields, 2 };
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

    static constexpr DB2Meta Instance{ 4382197, 0, 6, 5, 0x7E46ED08, Fields, 5 };
};

struct CraftingReagentRequirementMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5049814, -1, 2, 1, 0x0BE9179D, Fields, 1 };
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

    static constexpr DB2Meta Instance{ 841631, -1, 11, 11, 0x0F1A4E20, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 879282, -1, 6, 5, 0xFC42F936, Fields, 5 };
};

struct CreatureDifficultyTreasureMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4044373, -1, 3, 2, 0x75E963A9, Fields, 2 };
};

struct CreatureDispXUiCameraMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1146692, -1, 2, 2, 0xA5E810E7, Fields, -1 };
};

struct CreatureDisplayInfoMeta
{
    static constexpr DB2MetaField Fields[28] =
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
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
        { FT_SHORT, 1, false },
        { FT_FLOAT, 1, true },
        { FT_SHORT, 1, false },
        { FT_INT, 4, true },
    };

    static constexpr DB2Meta Instance{ 1108759, 0, 28, 28, 0x19189406, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1332686, 1, 8, 7, 0x4A85E6DE, Fields, 7 };
};

struct CreatureDisplayInfoCondXChoiceMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3670439, -1, 2, 2, 0x8AB1D7E8, Fields, 0 };
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

    static constexpr DB2Meta Instance{ 1586882, -1, 4, 3, 0xF2A5FCAA, Fields, 3 };
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

    static constexpr DB2Meta Instance{ 1264997, 0, 7, 7, 0x1685A9BC, Fields, -1 };
};

struct CreatureDisplayInfoGeosetDataMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1720141, -1, 3, 2, 0x5E539080, Fields, 2 };
};

struct CreatureDisplayInfoOptionMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3692043, -1, 3, 2, 0x2F331C33, Fields, 2 };
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

    static constexpr DB2Meta Instance{ 1146698, -1, 6, 5, 0xD3A7F438, Fields, 5 };
};

struct CreatureDisplayXUIModelSceneMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5551196, -1, 2, 2, 0x50CD0BBB, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1351351, -1, 9, 9, 0x126721A8, Fields, -1 };
};

struct CreatureFamilyXUIModelSceneMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5551197, -1, 2, 2, 0xE06E122D, Fields, -1 };
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
        { FT_INT, 11, false },
        { FT_INT, 20, false },
    };

    static constexpr DB2Meta Instance{ 1131322, -1, 9, 9, 0x3CE6BCF7, Fields, -1 };
};

struct CreatureLabelMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3055733, -1, 2, 1, 0x25B2B438, Fields, 1 };
};

struct CreatureModelDataMeta
{
    static constexpr DB2MetaField Fields[34] =
    {
        { FT_FLOAT, 6, true },
        { FT_INT, 1, true },
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
        { FT_SHORT, 1, false },
        { FT_FLOAT, 2, true },
    };

    static constexpr DB2Meta Instance{ 1365368, -1, 34, 34, 0x6148D238, Fields, -1 };
};

struct CreatureMovementInfoMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1125666, -1, 1, 1, 0x30A3C9CA, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1344466, 0, 39, 39, 0x2AFA921B, Fields, -1 };
};

struct CreatureSoundFidgetMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4178576, -1, 3, 2, 0x9BDF9BD7, Fields, 2 };
};

struct CreatureTypeMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_STRING, 1, true },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1131315, -1, 2, 2, 0xFE55D4D2, Fields, -1 };
};

struct CreatureXContributionMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1587158, -1, 2, 1, 0x29D9C37F, Fields, 1 };
};

struct CreatureXDisplayInfoMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1864302, -1, 6, 5, 0x2EA19FCF, Fields, 5 };
};

struct CreatureXUiWidgetSetMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3055738, -1, 3, 3, 0x8D874E99, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1263817, -1, 11, 11, 0x531EB93F, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1263818, -1, 7, 7, 0xFF97AE12, Fields, -1 };
};

struct CriteriaTreeXEffectMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_SHORT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1345969, -1, 2, 1, 0xA95C5FCA, Fields, 1 };
};

struct CurrencyCategoryMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1125667, -1, 4, 4, 0x72B9AF57, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1934603, -1, 8, 7, 0xA5E771CA, Fields, 7 };
};

struct CurrencyTypesMeta
{
    static constexpr DB2MetaField Fields[18] =
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
        { FT_FLOAT, 1, true },
        { FT_INT, 2, true },
    };

    static constexpr DB2Meta Instance{ 1095531, -1, 18, 18, 0x4042BF2D, Fields, -1 };
};

struct CurveMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 892585, 0, 3, 3, 0x48AE7F4A, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 892586, 2, 5, 5, 0x8DB83C21, Fields, 3 };
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

    static constexpr DB2Meta Instance{ 1279415, -1, 4, 4, 0xDDC6DB32, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1278176, -1, 25, 25, 0x6F09046F, Fields, -1 };
};

struct DeclinedWordMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1279100, 1, 2, 2, 0x104E18EF, Fields, -1 };
};

struct DeclinedWordCasesMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1279099, -1, 3, 2, 0x24277AA1, Fields, 2 };
};

struct DelvesSeasonMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5920079, -1, 1, 1, 0xDB8CA312, Fields, -1 };
};

struct DelvesSeasonXSpellMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5920080, -1, 2, 1, 0x13DB27BC, Fields, 1 };
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

    static constexpr DB2Meta Instance{ 1122116, -1, 22, 22, 0x781EE932, Fields, -1 };
};

struct DeviceBlacklistMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 922722, -1, 2, 2, 0x29FEDBB1, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1352127, -1, 13, 13, 0xDDC70D8E, Fields, -1 };
};

struct DisplaySeasonMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4279827, 1, 7, 7, 0x95C01F30, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1304325, -1, 21, 21, 0x1E2060A7, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 922720, -1, 7, 7, 0x5A336370, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1347279, 1, 10, 10, 0x7B6AC42A, Fields, 2 };
};

struct DurabilityCostsMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_SHORT, 21, false },
        { FT_SHORT, 8, false },
    };

    static constexpr DB2Meta Instance{ 1283019, -1, 2, 2, 0x917714A1, Fields, -1 };
};

struct DurabilityQualityMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1130268, -1, 1, 1, 0x08763C54, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1387381, -1, 13, 13, 0x9B3C5463, Fields, -1 };
};

struct EmotesMeta
{
    static constexpr DB2MetaField Fields[9] =
    {
        { FT_LONG, 1, true },
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_SHORT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1343602, -1, 9, 9, 0x590311E0, Fields, -1 };
};

struct EmotesTextMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1347273, -1, 2, 2, 0xCCDBFBAF, Fields, -1 };
};

struct EmotesTextDataMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_STRING, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1283024, -1, 3, 2, 0x4BF58EA9, Fields, 2 };
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

    static constexpr DB2Meta Instance{ 1286524, -1, 5, 4, 0x4244D600, Fields, 4 };
};

struct EnvironmentalDamageMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1278398, -1, 2, 2, 0x4B8F9058, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1343313, -1, 7, 7, 0xB6456916, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1937326, -1, 11, 10, 0xFD4F2D39, Fields, 10 };
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

    static constexpr DB2Meta Instance{ 1969773, -1, 9, 9, 0x8C41CCCE, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 3527889, -1, 6, 6, 0x54A151A3, Fields, 1 };
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

    static constexpr DB2Meta Instance{ 1361972, -1, 17, 17, 0xCD0F0C19, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1343595, -1, 5, 5, 0x8BC1F2F3, Fields, -1 };
};

struct FactionTemplateMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_SHORT, 8, false },
        { FT_SHORT, 8, false },
    };

    static constexpr DB2Meta Instance{ 1361579, -1, 7, 7, 0x47624A42, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 4501047, -1, 25, 25, 0x5CF8CAA8, Fields, -1 };
};

struct FlightCapabilityXGlideEventMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4644249, -1, 2, 1, 0x78D22F93, Fields, 1 };
};

struct FootprintTexturesMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1308056, -1, 3, 3, 0xA762B817, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1267647, -1, 4, 4, 0x747D783F, Fields, -1 };
};

struct FriendshipRepReactionMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1237638, -1, 4, 4, 0x1BC0DC59, Fields, 1 };
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

    static constexpr DB2Meta Instance{ 1237639, 3, 7, 7, 0x3D52E27A, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1348282, -1, 28, 28, 0xC0799EA5, Fields, -1 };
};

struct GMSurveyAnswersMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_STRING, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1283025, -1, 3, 2, 0xA8167E67, Fields, 2 };
};

struct GMSurveyCurrentSurveyMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1278177, -1, 1, 1, 0x42C33040, Fields, -1 };
};

struct GMSurveyQuestionsMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_STRING, 1, true },
    };

    static constexpr DB2Meta Instance{ 1278178, -1, 1, 1, 0xA07C5F5C, Fields, -1 };
};

struct GMSurveySurveysMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_BYTE, 15, false },
    };

    static constexpr DB2Meta Instance{ 1283020, -1, 1, 1, 0x986268B3, Fields, -1 };
};

struct GameClockDebugMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2922072, -1, 1, 1, 0x0305FD3B, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 3565753, -1, 4, 4, 0xD36FC187, Fields, 0 };
};

struct GameObjectArtKitMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 3, true },
    };

    static constexpr DB2Meta Instance{ 1266737, -1, 2, 2, 0xF1996F13, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1302847, -1, 4, 3, 0x41A0ED3A, Fields, 3 };
};

struct GameObjectDisplayConditionMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5634246, 0, 6, 5, 0x52044F17, Fields, 5 };
};

struct GameObjectDisplayInfoMeta
{
    static constexpr DB2MetaField Fields[9] =
    {
        { FT_FLOAT, 6, true },
        { FT_INT, 1, true },
        { FT_SHORT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1266277, -1, 9, 9, 0xD85414D1, Fields, -1 };
};

struct GameObjectDisplayInfoXSoundKitMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1345272, -1, 3, 2, 0x70E1497B, Fields, 2 };
};

struct GameObjectLabelMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4621877, -1, 2, 1, 0xE55A8C65, Fields, 1 };
};

struct GameObjectsMeta
{
    static constexpr DB2MetaField Fields[13] =
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
        { FT_SHORT, 1, false },
        { FT_INT, 8, true },
    };

    static constexpr DB2Meta Instance{ 841620, 3, 13, 13, 0xD2E7A9E4, Fields, 4 };
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

    static constexpr DB2Meta Instance{ 3405438, -1, 5, 5, 0x7E79D13A, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1368021, -1, 5, 5, 0xA180E707, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 966238, -1, 7, 7, 0x33E93215, Fields, -1 };
};

struct GarrAbilityCategoryMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_STRING, 1, true },
    };

    static constexpr DB2Meta Instance{ 1020248, -1, 1, 1, 0x782EE721, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 966241, 0, 12, 12, 0xDBE1C842, Fields, 1 };
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

    static constexpr DB2Meta Instance{ 3305399, -1, 9, 9, 0x6ADAF487, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 3305400, -1, 7, 7, 0x8067D16A, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 3307335, 0, 8, 8, 0xACEA7666, Fields, 1 };
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

    static constexpr DB2Meta Instance{ 929747, -1, 24, 24, 0xF2559D7C, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 943937, -1, 5, 5, 0x8D671E1C, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 983298, 1, 5, 5, 0x772B63F1, Fields, 2 };
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

    static constexpr DB2Meta Instance{ 981570, -1, 7, 7, 0x9B74983E, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1380674, -1, 6, 6, 0x5EB2C2BE, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 975304, -1, 8, 8, 0x90365AF7, Fields, -1 };
};

struct GarrEncounterSetXEncounterMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1354772, 0, 3, 2, 0x8A61976C, Fields, 2 };
};

struct GarrEncounterXMechanicMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 967961, -1, 3, 2, 0x4EBD3495, Fields, 2 };
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

    static constexpr DB2Meta Instance{ 981569, -1, 4, 3, 0xE01C9167, Fields, 3 };
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

    static constexpr DB2Meta Instance{ 1345970, -1, 4, 3, 0x52B363F4, Fields, 3 };
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
        { FT_INT, 1, true },
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

    static constexpr DB2Meta Instance{ 949906, -1, 33, 33, 0x32307958, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 970979, -1, 4, 4, 0x83953EF8, Fields, -1 };
};

struct GarrFollowerQualityMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1027793, -1, 7, 7, 0x5DE27929, Fields, -1 };
};

struct GarrFollowerSetXFollowerMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1361029, -1, 2, 1, 0x078F8ACE, Fields, 1 };
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

    static constexpr DB2Meta Instance{ 1118784, -1, 7, 7, 0x0DF04685, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1412636, -1, 6, 5, 0x3B69F3A8, Fields, 5 };
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

    static constexpr DB2Meta Instance{ 968468, -1, 4, 3, 0x11D80996, Fields, 3 };
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

    static constexpr DB2Meta Instance{ 1572314, -1, 4, 4, 0x89799C9B, Fields, -1 };
};

struct GarrMechanicMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 967963, -1, 3, 3, 0x3BF3FDD5, Fields, -1 };
};

struct GarrMechanicSetXMechanicMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1391531, 0, 3, 2, 0xE598BF8A, Fields, 2 };
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

    static constexpr DB2Meta Instance{ 967964, -1, 4, 4, 0x2005D512, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 967962, -1, 31, 31, 0x954C4831, Fields, 16 };
};

struct GarrMissionSetMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3055759, -1, 6, 6, 0x80900D87, Fields, -1 };
};

struct GarrMissionTextureMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_FLOAT, 2, true },
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1125220, -1, 2, 2, 0x3151B2BB, Fields, -1 };
};

struct GarrMissionTypeMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_STRING, 1, true },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 984174, -1, 3, 3, 0xC10BF76C, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 967960, -1, 5, 4, 0x08428AE4, Fields, 4 };
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

    static constexpr DB2Meta Instance{ 1359096, -1, 4, 3, 0x5FED477D, Fields, 3 };
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

    static constexpr DB2Meta Instance{ 1138458, -1, 5, 5, 0xA15614BC, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 937634, -1, 7, 7, 0x3A27A44E, Fields, -1 };
};

struct GarrPlotBuildingMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 929743, -1, 2, 2, 0xA5104F1A, Fields, -1 };
};

struct GarrPlotInstanceMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 929742, -1, 2, 2, 0x9403779B, Fields, -1 };
};

struct GarrPlotUICategoryMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_STRING, 1, true },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 937635, -1, 2, 2, 0xB0A277C0, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 939295, -1, 9, 9, 0xE7D632F8, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 940404, -1, 4, 4, 0x75F81A87, Fields, 1 };
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

    static constexpr DB2Meta Instance{ 937647, -1, 7, 7, 0x0A0EBC1C, Fields, -1 };
};

struct GarrStringMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_STRING, 1, true },
    };

    static constexpr DB2Meta Instance{ 1416758, -1, 1, 1, 0x7D513539, Fields, -1 };
};

struct GarrTalTreeXGarrTalResearchMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3195601, -1, 3, 3, 0x6D36F491, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1361032, 2, 15, 15, 0x8FBDD72A, Fields, 3 };
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

    static constexpr DB2Meta Instance{ 3514438, 1, 9, 9, 0x8C81B978, Fields, 2 };
};

struct GarrTalentMapPOIMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_FLOAT, 2, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3534056, -1, 2, 2, 0xFFBBEE1A, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 3069763, 0, 18, 17, 0xF7D6BB03, Fields, 17 };
};

struct GarrTalentRankGroupEntryMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4382239, -1, 2, 1, 0xAEED1BF9, Fields, 1 };
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

    static constexpr DB2Meta Instance{ 4389481, -1, 4, 3, 0x06CF9782, Fields, 3 };
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

    static constexpr DB2Meta Instance{ 3195518, -1, 8, 8, 0x00586BA9, Fields, -1 };
};

struct GarrTalentSocketPropertiesMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3612617, -1, 2, 2, 0x96AA4BFB, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1361030, -1, 12, 12, 0xCD2EF0B5, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1333161, 0, 9, 9, 0x06733C36, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 976037, -1, 6, 6, 0xBE9C8287, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 976035, -1, 13, 13, 0x18D01391, Fields, -1 };
};

struct GemPropertiesMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1343604, -1, 2, 2, 0x86487AD2, Fields, -1 };
};

struct GlideEventMeta
{
    static constexpr DB2MetaField Fields[12] =
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
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4644012, -1, 12, 12, 0x205E317B, Fields, -1 };
};

struct GlideEventBlendTimesMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4682325, -1, 3, 2, 0x8A7326E7, Fields, 2 };
};

struct GlobalColorMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4328468, -1, 2, 2, 0x760E0516, Fields, -1 };
};

struct GlobalCurveMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3752002, -1, 2, 2, 0xBED3B583, Fields, -1 };
};

struct GlobalGameContentTuningMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3756368, -1, 2, 2, 0xD96DE315, Fields, -1 };
};

struct GlobalPlayerConditionMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4082838, -1, 3, 2, 0x6C3B89B7, Fields, 2 };
};

struct GlobalPlayerConditionSetMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4082839, 0, 2, 2, 0xF00A7AB4, Fields, -1 };
};

struct GlobalStringsMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_STRING, 1, true },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1394440, -1, 3, 3, 0x62707826, Fields, -1 };
};

struct GlyphBindableSpellMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1270147, -1, 2, 1, 0x8AB55EA9, Fields, 1 };
};

struct GlyphExclusiveCategoryMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_STRING, 1, true },
    };

    static constexpr DB2Meta Instance{ 948546, -1, 1, 1, 0xEB3B0B94, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1345274, -1, 4, 4, 0x2601475B, Fields, -1 };
};

struct GlyphRequiredSpecMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 948496, -1, 2, 1, 0x7FA14D85, Fields, 1 };
};

struct GossipNPCOptionMeta
{
    static constexpr DB2MetaField Fields[15] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
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

    static constexpr DB2Meta Instance{ 4278503, -1, 15, 15, 0xFA46016E, Fields, -1 };
};

struct GossipNPCOptionDisplayInfoMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4335720, -1, 3, 3, 0xFEE7A6C4, Fields, -1 };
};

struct GossipOptionXUIWidgetSetMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5746391, -1, 3, 2, 0x0C61CF7D, Fields, 2 };
};

struct GossipUIDisplayInfoConditionMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5902977, 1, 4, 3, 0xD287A02A, Fields, 3 };
};

struct GossipXGarrTalentTreesMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4407361, -1, 2, 1, 0x1A30C99B, Fields, 1 };
};

struct GossipXUIDisplayInfoMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3622253, 2, 5, 5, 0x4B452272, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 2433582, -1, 18, 18, 0xAFB2AC4C, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1308057, -1, 9, 9, 0xD8C42C51, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1308499, -1, 5, 5, 0xD93D5678, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 974813, -1, 15, 15, 0x395D3022, Fields, -1 };
};

struct GroupFinderActivityGrpMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_STRING, 1, true },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 974814, -1, 2, 2, 0xB3F025D8, Fields, -1 };
};

struct GroupFinderActivityXPvpBracketMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
    };

    static constexpr DB2Meta Instance{ 4206623, -1, 2, 2, 0x0E3530F0, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 974812, -1, 4, 4, 0x039D6BF9, Fields, -1 };
};

struct GuildColorBackgroundMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1286526, -1, 3, 3, 0x1C82913E, Fields, -1 };
};

struct GuildColorBorderMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1286527, -1, 3, 3, 0x1C82913E, Fields, -1 };
};

struct GuildColorEmblemMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1286525, -1, 3, 3, 0x1C82913E, Fields, -1 };
};

struct GuildEmblemMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2734754, -1, 2, 2, 0x2532676C, Fields, -1 };
};

struct GuildPerkSpellsMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1135238, -1, 1, 1, 0xC933095D, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 2921008, -1, 4, 3, 0x1DC85F62, Fields, 3 };
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

    static constexpr DB2Meta Instance{ 2921475, -1, 5, 4, 0x5363EE75, Fields, 4 };
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

    static constexpr DB2Meta Instance{ 2909769, -1, 4, 3, 0xFA17E913, Fields, 3 };
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

    static constexpr DB2Meta Instance{ 2920485, -1, 5, 4, 0x4A8DDE7F, Fields, 4 };
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

    static constexpr DB2Meta Instance{ 2910470, -1, 4, 3, 0x9A3366EF, Fields, 3 };
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

    static constexpr DB2Meta Instance{ 1097696, 1, 10, 10, 0x2F8299AE, Fields, -1 };
};

struct HelmetAnimScalingMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1348283, -1, 3, 2, 0xFF7E3A8A, Fields, 2 };
};

struct HelmetGeosetDataMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2821752, -1, 5, 4, 0x103B3B37, Fields, 4 };
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

    static constexpr DB2Meta Instance{ 996358, -1, 5, 5, 0x6A5296CF, Fields, -1 };
};

struct HolidayDescriptionsMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_STRING, 1, true },
    };

    static constexpr DB2Meta Instance{ 996360, -1, 1, 1, 0xA7B94A81, Fields, -1 };
};

struct HolidayNamesMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_STRING, 1, true },
    };

    static constexpr DB2Meta Instance{ 996359, -1, 1, 1, 0xD76CBBD2, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 996357, -1, 11, 11, 0xDB91019C, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1995523, -1, 4, 4, 0xA2CB2E77, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1121229, -1, 4, 4, 0xC9501AE7, Fields, -1 };
};

struct ImportPriceQualityMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1121228, -1, 1, 1, 0x08763C54, Fields, -1 };
};

struct ImportPriceShieldMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1121227, -1, 1, 1, 0x08763C54, Fields, -1 };
};

struct ImportPriceWeaponMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1121230, -1, 1, 1, 0x08763C54, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1336651, 2, 10, 9, 0x2B0F31F8, Fields, 9 };
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

    static constexpr DB2Meta Instance{ 841626, -1, 11, 11, 0xD43146DA, Fields, -1 };
};

struct ItemAppearanceMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 982462, -1, 5, 5, 0x481C4281, Fields, -1 };
};

struct ItemAppearanceXUiCameraMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1248126, -1, 2, 2, 0x055C50AD, Fields, -1 };
};

struct ItemArmorQualityMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_FLOAT, 7, true },
    };

    static constexpr DB2Meta Instance{ 1283021, -1, 1, 1, 0x2935AA9D, Fields, -1 };
};

struct ItemArmorShieldMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_FLOAT, 7, true },
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1277741, -1, 2, 2, 0x7E6C94F9, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1283022, -1, 5, 5, 0xEB155D51, Fields, -1 };
};

struct ItemBagFamilyMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_STRING, 1, true },
    };

    static constexpr DB2Meta Instance{ 1278179, -1, 1, 1, 0x782EE721, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 959070, -1, 4, 4, 0x79CD4525, Fields, 1 };
};

struct ItemBonusListMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1805807, 0, 2, 2, 0x22A28539, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 3755382, -1, 5, 5, 0xFBF090DA, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 3025306, 0, 9, 9, 0x24840319, Fields, 1 };
};

struct ItemBonusListLevelDeltaMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_SHORT, 1, true },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1320358, 1, 2, 2, 0x52DF470F, Fields, -1 };
};

struct ItemBonusListWarforgeLevelDeltaMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_SHORT, 1, true },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 2924997, 1, 2, 2, 0x52DF470F, Fields, -1 };
};

struct ItemBonusSeasonMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5155639, 0, 2, 2, 0xB838B9A8, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 5155640, 0, 4, 4, 0x3245391D, Fields, 3 };
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

    static constexpr DB2Meta Instance{ 5155641, 1, 8, 8, 0x8A24592F, Fields, 5 };
};

struct ItemBonusSequenceSpellMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3026822, -1, 2, 1, 0x70713473, Fields, 1 };
};

struct ItemBonusTreeMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3055768, -1, 2, 2, 0xDD92E4D6, Fields, -1 };
};

struct ItemBonusTreeGroupEntryMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4407505, -1, 2, 2, 0x4549B315, Fields, 0 };
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

    static constexpr DB2Meta Instance{ 987134, -1, 9, 8, 0x6304AE19, Fields, 8 };
};

struct ItemChildEquipmentMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1247926, -1, 3, 3, 0x2B57F9DE, Fields, 0 };
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

    static constexpr DB2Meta Instance{ 1140189, -1, 4, 4, 0xA2EB4A48, Fields, -1 };
};

struct ItemConditionMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5128111, -1, 1, 1, 0x5D03D2C4, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1405665, -1, 7, 6, 0x18546FD3, Fields, 6 };
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

    static constexpr DB2Meta Instance{ 4337196, -1, 5, 5, 0xB01EC8EF, Fields, -1 };
};

struct ItemConversionEntryMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4337197, -1, 2, 1, 0x0FE5EF55, Fields, 1 };
};

struct ItemCurrencyCostMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 801670, -1, 1, 1, 0x8950022B, Fields, 0 };
};

struct ItemCurrencyValueMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 4, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3755770, -1, 3, 2, 0x30FB7CF7, Fields, 2 };
};

struct ItemDamageAmmoMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_SHORT, 1, false },
        { FT_FLOAT, 7, true },
    };

    static constexpr DB2Meta Instance{ 1277740, -1, 2, 2, 0x56F30531, Fields, -1 };
};

struct ItemDamageOneHandMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_SHORT, 1, false },
        { FT_FLOAT, 7, true },
    };

    static constexpr DB2Meta Instance{ 1277743, -1, 2, 2, 0x56F30531, Fields, -1 };
};

struct ItemDamageOneHandCasterMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_SHORT, 1, false },
        { FT_FLOAT, 7, true },
    };

    static constexpr DB2Meta Instance{ 1277739, -1, 2, 2, 0x56F30531, Fields, -1 };
};

struct ItemDamageTwoHandMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_SHORT, 1, false },
        { FT_FLOAT, 7, true },
    };

    static constexpr DB2Meta Instance{ 1277738, -1, 2, 2, 0x56F30531, Fields, -1 };
};

struct ItemDamageTwoHandCasterMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_SHORT, 1, false },
        { FT_FLOAT, 7, true },
    };

    static constexpr DB2Meta Instance{ 1277742, -1, 2, 2, 0x56F30531, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1134087, -1, 7, 6, 0x5845A4AA, Fields, 6 };
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

    static constexpr DB2Meta Instance{ 1266429, -1, 16, 16, 0x45C2F619, Fields, -1 };
};

struct ItemDisplayInfoMaterialResMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1280614, -1, 3, 2, 0xAA462C0E, Fields, 2 };
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

    static constexpr DB2Meta Instance{ 4050937, -1, 4, 3, 0x52510D63, Fields, 3 };
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

    static constexpr DB2Meta Instance{ 969941, -1, 8, 8, 0x2CEB026E, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 801681, -1, 10, 10, 0xD2894EC8, Fields, -1 };
};

struct ItemFixupMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5152256, -1, 1, 1, 0xB98F95BF, Fields, -1 };
};

struct ItemFixupActionMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5475699, -1, 2, 1, 0x2F54E0F0, Fields, 1 };
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

    static constexpr DB2Meta Instance{ 5015219, -1, 5, 4, 0x8C0C0A82, Fields, 4 };
};

struct ItemGroupSoundsMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 4, false },
    };

    static constexpr DB2Meta Instance{ 1283023, -1, 1, 1, 0xA7CEF530, Fields, -1 };
};

struct ItemLevelSelectorMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1588911, -1, 3, 3, 0xAEACAB9F, Fields, -1 };
};

struct ItemLevelSelectorQualityMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1624937, -1, 3, 2, 0x3016B2C0, Fields, 2 };
};

struct ItemLevelSelectorQualitySetMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_SHORT, 1, true },
        { FT_SHORT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1624933, -1, 2, 2, 0x6EF696F8, Fields, -1 };
};

struct ItemLimitCategoryMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_STRING, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1237440, -1, 3, 3, 0x22467A2D, Fields, -1 };
};

struct ItemLimitCategoryConditionMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_BYTE, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1378590, -1, 3, 2, 0x8DC9459D, Fields, 2 };
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

    static constexpr DB2Meta Instance{ 4677533, -1, 4, 3, 0x8BFEFC5C, Fields, 3 };
};

struct ItemLogicalCostGroupMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 4677534, 0, 1, 1, 0xF2103A31, Fields, -1 };
};

struct ItemModifiedAppearanceMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 982457, 0, 7, 7, 0x03A6C979, Fields, 1 };
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

    static constexpr DB2Meta Instance{ 1278399, -1, 5, 5, 0x5F7C0B7F, Fields, -1 };
};

struct ItemNameDescriptionMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1332559, -1, 2, 2, 0xB616608D, Fields, -1 };
};

struct ItemNameSlotOverrideMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3723474, -1, 3, 2, 0x6D223985, Fields, 2 };
};

struct ItemPetFoodMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_STRING, 1, true },
    };

    static constexpr DB2Meta Instance{ 1302240, -1, 1, 1, 0xDAD218A6, Fields, -1 };
};

struct ItemPriceBaseMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_SHORT, 1, false },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1121231, -1, 3, 3, 0x9AD504F0, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1270315, -1, 4, 4, 0x16D5D0A7, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 5150118, 0, 5, 4, 0xD7F3331F, Fields, 4 };
};

struct ItemReforgeMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_SHORT, 1, false },
        { FT_FLOAT, 1, true },
        { FT_SHORT, 1, false },
        { FT_FLOAT, 1, true },
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 5633983, -1, 5, 5, 0xE3284DDC, Fields, -1 };
};

struct ItemSalvageMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4548446, -1, 3, 3, 0x83141ADC, Fields, -1 };
};

struct ItemSalvageLootMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4549058, -1, 3, 3, 0xD8C41341, Fields, 0 };
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
        { FT_INT, 5, true },
    };

    static constexpr DB2Meta Instance{ 1273408, -1, 13, 13, 0x40C3317A, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1343609, -1, 5, 5, 0xEEB090F4, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1314689, -1, 4, 3, 0xCDEF234D, Fields, 3 };
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
        { FT_INT, 5, true },
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
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
    };

    static constexpr DB2Meta Instance{ 1572924, -1, 64, 64, 0x35E390AC, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1135120, -1, 6, 6, 0x83F3D113, Fields, 2 };
};

struct ItemSpecOverrideMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1134576, -1, 2, 1, 0xB292998C, Fields, 1 };
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

    static constexpr DB2Meta Instance{ 1261604, 2, 11, 11, 0x1E67DB87, Fields, 3 };
};

struct ItemSubClassMaskMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_STRING, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1302852, -1, 3, 3, 0xD1A996F3, Fields, -1 };
};

struct ItemVisualsMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 5, true },
    };

    static constexpr DB2Meta Instance{ 1343605, -1, 3, 3, 0x4D7EF22C, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 3043873, -1, 6, 5, 0x62F4C094, Fields, 5 };
};

struct ItemXBonusTreeMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 987133, -1, 2, 1, 0x5A99E55B, Fields, 1 };
};

struct ItemXItemEffectMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3177687, -1, 2, 1, 0x96F083AD, Fields, 1 };
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

    static constexpr DB2Meta Instance{ 1240336, 3, 12, 12, 0xB88D11CC, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1301155, 2, 8, 8, 0x81A3C769, Fields, 3 };
};

struct JournalEncounterItemMeta
{
    static constexpr DB2MetaField Fields[8] =
    {
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, false },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1344467, 0, 8, 8, 0xD95559FA, Fields, 1 };
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

    static constexpr DB2Meta Instance{ 1134413, -1, 15, 15, 0xCB88312B, Fields, -1 };
};

struct JournalEncounterXDifficultyMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1121901, -1, 2, 1, 0x1E14364D, Fields, 1 };
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

    static constexpr DB2Meta Instance{ 1722928, -1, 5, 4, 0x330EE16F, Fields, 4 };
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

    static constexpr DB2Meta Instance{ 1237438, -1, 9, 9, 0x811ABB6A, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 5228481, -1, 5, 4, 0xC6E4ECB2, Fields, 4 };
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

    static constexpr DB2Meta Instance{ 5228217, -1, 6, 5, 0x7005598D, Fields, 5 };
};

struct JournalItemXDifficultyMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1277744, -1, 2, 1, 0x6F46EEA2, Fields, 1 };
};

struct JournalSectionXDifficultyMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1121900, -1, 2, 1, 0x6CF791BA, Fields, 1 };
};

struct JournalTierMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1349056, -1, 3, 3, 0xF4AFE752, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1285009, -1, 4, 4, 0xBFCBF1F0, Fields, 0 };
};

struct KeychainMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_BYTE, 32, false },
    };

    static constexpr DB2Meta Instance{ 801693, -1, 1, 1, 0x019E306C, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1344761, 2, 4, 4, 0x166FC575, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1135058, -1, 4, 4, 0x920DFF98, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1361033, -1, 29, 29, 0xBA9CE7CB, Fields, -1 };
};

struct LFGRoleRequirementMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_BYTE, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 982805, -1, 3, 2, 0x8D26EA6B, Fields, 2 };
};

struct LabelXContentRestrictRuleSetMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4281309, -1, 3, 2, 0x7829CA93, Fields, 2 };
};

struct LanguageWordsMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 984702, -1, 2, 2, 0x1865582A, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1135325, 1, 6, 6, 0x5D934E12, Fields, -1 };
};

struct LfgDungeonsGroupingMapMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1339818, -1, 3, 2, 0x105EA15A, Fields, 2 };
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

    static constexpr DB2Meta Instance{ 1375579, -1, 5, 5, 0x5F16BC84, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1375580, -1, 46, 46, 0xB5052D20, Fields, 0 };
};

struct LightParamsMeta
{
    static constexpr DB2MetaField Fields[16] =
    {
        { FT_FLOAT, 3, true },
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
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1334669, -1, 16, 16, 0x96239779, Fields, -1 };
};

struct LightParamsLightShaftMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5350588, -1, 3, 2, 0xFBB113FA, Fields, 2 };
};

struct LightShaftMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5350589, -1, 3, 3, 0xC22F4FD9, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1308501, -1, 4, 4, 0x407FEBCF, Fields, -1 };
};

struct LightWorldShadowMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4680119, -1, 3, 2, 0xA909CB00, Fields, 2 };
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

    static constexpr DB2Meta Instance{ 2003383, -1, 34, 34, 0x645F11FD, Fields, -1 };
};

struct LiquidMaterialMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
    };

    static constexpr DB2Meta Instance{ 1132538, -1, 2, 2, 0x01033D2A, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1308058, -1, 5, 5, 0xCB0D39E8, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1371380, -1, 21, 21, 0x95DB15B6, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 2261065, -1, 4, 3, 0x7BEECC7F, Fields, 3 };
};

struct LivingWorldObjectTemplateMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4276965, -1, 1, 1, 0xC3D5DF0A, Fields, -1 };
};

struct LoadingScreenSkinMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 10, true },
    };

    static constexpr DB2Meta Instance{ 2478235, -1, 1, 1, 0x7FF1EF86, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1302239, -1, 5, 5, 0x7B0D052E, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1266541, -1, 10, 10, 0xF6E51D7F, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 801706, -1, 5, 5, 0x95961A74, Fields, -1 };
};

struct LocationMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_FLOAT, 3, true },
        { FT_FLOAT, 3, true },
    };

    static constexpr DB2Meta Instance{ 801707, -1, 2, 2, 0xD18A3880, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1343608, -1, 5, 5, 0xFCC491D2, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1284823, -1, 6, 6, 0xAF114F71, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1098785, -1, 18, 18, 0x92FF222C, Fields, -1 };
};

struct LoreTextMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3311370, -1, 3, 3, 0xF6908A5C, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 3479846, 0, 6, 5, 0x35AA0D60, Fields, 5 };
};

struct MCRSlotXMCRCategoryMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3390955, -1, 3, 2, 0x9CFFA4CF, Fields, 2 };
};

struct MailTemplateMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_STRING, 1, true },
    };

    static constexpr DB2Meta Instance{ 1240344, -1, 1, 1, 0xB436C1C8, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1587159, -1, 10, 10, 0xA4E9EA9F, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1587155, -1, 4, 3, 0xB8C3D344, Fields, 3 };
};

struct ManagedWorldStateInputMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1587151, -1, 3, 3, 0x16683306, Fields, -1 };
};

struct ManifestInterfaceActionIconMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1375803, 0, 1, 1, 0xF2103A31, Fields, -1 };
};

struct ManifestInterfaceDataMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_STRING_NOT_LOCALIZED, 1, true },
    };

    static constexpr DB2Meta Instance{ 1375801, -1, 2, 2, 0x618AD009, Fields, -1 };
};

struct ManifestInterfaceItemIconMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1375804, 0, 1, 1, 0xF2103A31, Fields, -1 };
};

struct ManifestInterfaceTOCDataMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
    };

    static constexpr DB2Meta Instance{ 1267335, -1, 1, 1, 0x4AB64495, Fields, -1 };
};

struct MapMeta
{
    static constexpr DB2MetaField Fields[25] =
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
        { FT_INT, 1, true },
        { FT_INT, 3, true },
    };

    static constexpr DB2Meta Instance{ 1349477, -1, 25, 25, 0xE0196C63, Fields, -1 };
};

struct MapCelestialBodyMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_SHORT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1597466, -1, 3, 2, 0xA320FA08, Fields, 2 };
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

    static constexpr DB2Meta Instance{ 801709, 1, 7, 7, 0xC31A3CC1, Fields, 2 };
};

struct MapDifficultyMeta
{
    static constexpr DB2MetaField Fields[11] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1367868, -1, 11, 10, 0xC18134AF, Fields, 10 };
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

    static constexpr DB2Meta Instance{ 1375435, -1, 4, 3, 0xD514B4CA, Fields, 3 };
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

    static constexpr DB2Meta Instance{ 1719707, -1, 5, 4, 0xB7151FA7, Fields, 4 };
};

struct MapRenderScaleMeta
{
    static constexpr DB2MetaField Fields[9] =
    {
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4633656, -1, 9, 9, 0x7A7EA4FD, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 801710, -1, 7, 7, 0xA76A6607, Fields, -1 };
};

struct MaterialMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1294217, -1, 4, 4, 0xBE3E0E4C, Fields, -1 };
};

struct MawPowerMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2991315, 0, 3, 3, 0xE768E837, Fields, 1 };
};

struct MawPowerRarityMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2997952, -1, 2, 2, 0x3DFF7866, Fields, -1 };
};

struct MinorTalentMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1347274, -1, 3, 2, 0x6EF747EB, Fields, 2 };
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

    static constexpr DB2Meta Instance{ 1710117, -1, 12, 12, 0x9492D27D, Fields, -1 };
};

struct ModelAnimCloakDampeningMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1465904, -1, 3, 2, 0xF2AE9C79, Fields, 2 };
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

    static constexpr DB2Meta Instance{ 1337833, 1, 5, 5, 0x1045BE38, Fields, 4 };
};

struct ModelRibbonQualityMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1399953, -1, 2, 1, 0x6444FDE5, Fields, 1 };
};

struct ModelSoundMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5393273, -1, 2, 2, 0xB38E4BBC, Fields, -1 };
};

struct ModelSoundAnimEntryMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5393274, -1, 2, 2, 0x324E0B06, Fields, 0 };
};

struct ModelSoundEntryMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5393275, -1, 1, 1, 0x4A95649C, Fields, 0 };
};

struct ModelSoundOverrideMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5393276, -1, 2, 2, 0x1B5019C8, Fields, 0 };
};

struct ModelSoundSettingsMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5682517, -1, 2, 1, 0xDB67A4DC, Fields, 1 };
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

    static constexpr DB2Meta Instance{ 5393277, -1, 6, 6, 0x2DAEAE9D, Fields, 5 };
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

    static constexpr DB2Meta Instance{ 3386486, -1, 5, 5, 0xA552864D, Fields, -1 };
};

struct ModifiedCraftingItemMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4530643, 0, 3, 3, 0xAEFCC238, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 3386487, -1, 6, 6, 0x03563096, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 3386488, 1, 6, 6, 0x61863510, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 3390956, -1, 6, 6, 0x00739B08, Fields, 0 };
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

    static constexpr DB2Meta Instance{ 1267645, -1, 7, 7, 0xF13BB1D8, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 921760, 3, 13, 13, 0xE4B71B79, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1114709, -1, 9, 9, 0x791A3C76, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 2923510, -1, 4, 3, 0x04BEE573, Fields, 3 };
};

struct MountTypeMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 24, true },
    };

    static constexpr DB2Meta Instance{ 1114674, -1, 2, 2, 0xD7BB0C67, Fields, -1 };
};

struct MountTypeXCapabilityMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1114715, -1, 3, 3, 0x218BBE7F, Fields, 0 };
};

struct MountXDisplayMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1576117, -1, 4, 3, 0xC05B05EF, Fields, 3 };
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

    static constexpr DB2Meta Instance{ 3989477, -1, 5, 4, 0x519C3E97, Fields, 4 };
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

    static constexpr DB2Meta Instance{ 1332556, -1, 5, 5, 0x2C44DB9A, Fields, -1 };
};

struct MovieFileDataMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1301154, -1, 1, 1, 0xA80F88DE, Fields, -1 };
};

struct MovieVariationMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1339819, -1, 3, 2, 0xB5C17F58, Fields, 2 };
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

    static constexpr DB2Meta Instance{ 1965592, -1, 11, 10, 0x63E1D6FB, Fields, 10 };
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

    static constexpr DB2Meta Instance{ 1965589, -1, 5, 5, 0xA20DA38D, Fields, -1 };
};

struct MusicOverrideMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 5161908, -1, 3, 3, 0xD33F9337, Fields, -1 };
};

struct MythicPlusSeasonMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2400282, 0, 5, 5, 0xDC94262F, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 2123783, -1, 5, 5, 0xA256317C, Fields, 0 };
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

    static constexpr DB2Meta Instance{ 4067473, 0, 5, 4, 0xEFDAF463, Fields, 4 };
};

struct MythicPlusSeasonTrackedMapMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4521365, -1, 2, 1, 0x03958F0D, Fields, 1 };
};

struct NPCCraftingOrderCustomerMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5875492, -1, 6, 6, 0x4A3AC30B, Fields, -1 };
};

struct NPCCraftingOrderCustomerXLabelMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5875493, 0, 3, 3, 0xA5267D1B, Fields, 1 };
};

struct NPCCraftingOrderSetMeta
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
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5875494, -1, 11, 11, 0xF05BCCBD, Fields, -1 };
};

struct NPCCraftingOrderSetXCraftOrderMeta
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

    static constexpr DB2Meta Instance{ 5875495, 0, 6, 6, 0x8CB4AEB8, Fields, 1 };
};

struct NPCCraftingOrderSetXCustomerMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5875496, 0, 4, 4, 0x3464F1DD, Fields, 2 };
};

struct NPCCraftingOrderSetXTreasureMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5912882, -1, 4, 3, 0xCC093D65, Fields, 3 };
};

struct NPCModelItemSlotDisplayInfoMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1340661, -1, 3, 2, 0xC2057F5B, Fields, 2 };
};

struct NPCSoundsMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 4, false },
    };

    static constexpr DB2Meta Instance{ 1282621, -1, 1, 1, 0x020BE1ED, Fields, -1 };
};

struct NameGenMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1122117, -1, 3, 3, 0x4AA46133, Fields, -1 };
};

struct NamesProfanityMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_BYTE, 1, true },
    };

    static constexpr DB2Meta Instance{ 1117086, -1, 2, 2, 0xF227E638, Fields, -1 };
};

struct NamesReservedMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
    };

    static constexpr DB2Meta Instance{ 1117085, -1, 1, 1, 0x2B2D5D97, Fields, -1 };
};

struct NamesReservedLocaleMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1117087, -1, 2, 2, 0x7B9823D4, Fields, -1 };
};

struct NumTalentsAtLevelMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1953326, -1, 3, 3, 0x9E707863, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1090577, -1, 8, 8, 0x3471C362, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1090575, -1, 4, 4, 0x764AE63A, Fields, -1 };
};

struct ObjectEffectPackageElemMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1090578, -1, 3, 3, 0x8AF314FA, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 2066958, -1, 8, 8, 0x70EC3040, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 3850529, -1, 6, 6, 0xEA29F303, Fields, -1 };
};

struct OccluderLocationMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_FLOAT, 3, true },
        { FT_FLOAT, 3, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2115224, -1, 3, 3, 0xE56AD56A, Fields, -1 };
};

struct OccluderNodeMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2066959, -1, 3, 3, 0xC1037415, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1279739, -1, 6, 6, 0xD720BC0B, Fields, -1 };
};

struct OverrideSpellDataMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 10, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1002186, -1, 3, 3, 0x96FFF958, Fields, -1 };
};

struct PVPBracketTypesMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_BYTE, 1, true },
        { FT_INT, 4, false },
    };

    static constexpr DB2Meta Instance{ 1394275, -1, 2, 2, 0xA3A33123, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1339820, -1, 4, 3, 0x583BCBE4, Fields, 3 };
};

struct PVPItemMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 972287, -1, 2, 2, 0xF812933C, Fields, -1 };
};

struct PVPScoreboardCellInfoMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2992916, -1, 3, 3, 0xC7E06276, Fields, 0 };
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

    static constexpr DB2Meta Instance{ 2992917, -1, 4, 4, 0xEA59FC11, Fields, -1 };
};

struct PVPScoreboardLayoutMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2992918, -1, 3, 3, 0xB7570DFC, Fields, 0 };
};

struct PVPStatMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2992919, 1, 3, 3, 0x5FE7D861, Fields, 2 };
};

struct PageTextMaterialMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
    };

    static constexpr DB2Meta Instance{ 1271600, -1, 1, 1, 0x728678A5, Fields, -1 };
};

struct PaperDollItemFrameMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1252503, -1, 3, 3, 0xD45CB1FC, Fields, -1 };
};

struct ParagonReputationMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1581183, -1, 3, 3, 0xD4AF2D4F, Fields, -1 };
};

struct ParticleColorMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 3, true },
        { FT_INT, 3, true },
        { FT_INT, 3, true },
    };

    static constexpr DB2Meta Instance{ 1284820, -1, 3, 3, 0xD58506F1, Fields, -1 };
};

struct ParticulateMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3396285, -1, 2, 2, 0x458CF691, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 2053913, -1, 5, 5, 0x2EE2C1E4, Fields, 0 };
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

    static constexpr DB2Meta Instance{ 801732, -1, 7, 7, 0xBB621A50, Fields, -1 };
};

struct PathEdgeMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 2, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2428705, -1, 2, 1, 0x9A2EF543, Fields, 1 };
};

struct PathNodeMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 801733, -1, 3, 3, 0xC1037415, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 801734, -1, 4, 4, 0x4C0E1D44, Fields, -1 };
};

struct PathPropertyMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 801735, -1, 3, 3, 0x27A2BE5C, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 4519766, 2, 7, 7, 0x5361589F, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 5524226, 0, 4, 3, 0x2E9DF173, Fields, 3 };
};

struct PerksActivityTagMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 4694317, 1, 2, 2, 0xEBA8ED0E, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 4519767, 0, 5, 4, 0x7995A0C8, Fields, 4 };
};

struct PerksActivityThresholdGroupMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4519768, 1, 3, 3, 0x377370DC, Fields, -1 };
};

struct PerksActivityXHolidaysMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5330797, -1, 2, 1, 0x3663AC24, Fields, 1 };
};

struct PerksActivityXIntervalMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4519781, 0, 3, 2, 0x2E6128D2, Fields, 2 };
};

struct PerksActivityXTagMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4694318, 0, 3, 2, 0xFFB58E04, Fields, 2 };
};

struct PerksUIThemeMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5389878, 0, 3, 3, 0x3FC4E853, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 4281310, 1, 4, 4, 0x00ECA515, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 4281311, 0, 9, 9, 0x7709D03B, Fields, -1 };
};

struct PerksVendorItemUIGroupMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5386256, 1, 3, 3, 0xF67D8F83, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 4281312, 0, 4, 4, 0x75DC10F3, Fields, -1 };
};

struct PerksVendorItemXIntervalMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4872513, -1, 2, 2, 0xF901FDA4, Fields, -1 };
};

struct PhaseMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1348558, -1, 1, 1, 0x6D5EB3BD, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1267336, -1, 13, 13, 0x3DC135AF, Fields, -1 };
};

struct PhaseXPhaseGroupMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 987581, -1, 2, 1, 0xF3FF427F, Fields, 1 };
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

    static constexpr DB2Meta Instance{ 5152358, -1, 5, 5, 0xE7C4153F, Fields, -1 };
};

struct PlayerCompanionInfoMeta
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

    static constexpr DB2Meta Instance{ 5922429, -1, 8, 8, 0x4EF4C3DB, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1045411, -1, 84, 84, 0x311C5FAE, Fields, -1 };
};

struct PlayerDataElementAccountMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5715394, 0, 3, 3, 0x7F54ED49, Fields, -1 };
};

struct PlayerDataElementCharacterMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5715395, 0, 3, 3, 0x7F54ED49, Fields, -1 };
};

struct PlayerDataFlagAccountMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5426706, -1, 1, 1, 0x2A4C0DDD, Fields, -1 };
};

struct PlayerDataFlagCharacterMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5426708, -1, 1, 1, 0x2A4C0DDD, Fields, -1 };
};

struct PlayerInteractionInfoMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5346849, 0, 4, 4, 0xD40A8C49, Fields, -1 };
};

struct PointLightConditionMapMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5735564, -1, 5, 5, 0x57294411, Fields, 0 };
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

    static constexpr DB2Meta Instance{ 1251523, -1, 4, 4, 0xE0D4FD55, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1251506, -1, 8, 8, 0x9CDFBF30, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1251533, -1, 11, 11, 0x855AA6BC, Fields, -1 };
};

struct PowerDisplayMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1332557, -1, 5, 5, 0x613FAAFD, Fields, -1 };
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
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1266022, 2, 13, 13, 0x14BBEEA1, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1275869, -1, 5, 5, 0x6582638F, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 4542069, 0, 5, 5, 0x8622E546, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 4542084, 0, 4, 4, 0x741F7E26, Fields, -1 };
};

struct ProfTraitTreeMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4542085, 0, 2, 2, 0xD2C4C5BD, Fields, -1 };
};

struct ProfTraitTreeHighlightMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4999865, -1, 3, 2, 0x884E0222, Fields, 2 };
};

struct ProfessionMeta
{
    static constexpr DB2MetaField Fields[11] =
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
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4508544, 0, 11, 11, 0x86FE926D, Fields, -1 };
};

struct ProfessionEffectMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4505297, -1, 3, 3, 0x04C16FA9, Fields, -1 };
};

struct ProfessionEffectTypeMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4556715, -1, 2, 1, 0x39C33588, Fields, 1 };
};

struct ProfessionExpansionMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5662322, 0, 5, 4, 0x285BD241, Fields, 4 };
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

    static constexpr DB2Meta Instance{ 4452078, -1, 6, 6, 0x4B324AE9, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 4623413, 2, 6, 5, 0x0C8C8309, Fields, 5 };
};

struct ProfessionTraitMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4505298, 0, 2, 2, 0x306455FE, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 4505494, 0, 4, 4, 0x97A0A286, Fields, 1 };
};

struct ProfessionTraitXLabelMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4505299, 0, 3, 3, 0x584FA44E, Fields, 1 };
};

struct ProfessionXRatingMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4868299, -1, 3, 3, 0xBB253F69, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1585723, 3, 7, 7, 0x62524271, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 4699082, -1, 4, 4, 0x8B89647A, Fields, -1 };
};

struct PvpScalingEffectMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1591100, -1, 3, 3, 0x295E05C1, Fields, 1 };
};

struct PvpScalingEffectTypeMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
    };

    static constexpr DB2Meta Instance{ 1591098, -1, 1, 1, 0x21188F13, Fields, -1 };
};

struct PvpSeasonMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2966426, -1, 3, 3, 0xC2D9E52E, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 2470695, -1, 4, 3, 0x4C592860, Fields, 3 };
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

    static constexpr DB2Meta Instance{ 1302853, 1, 10, 10, 0xBE69BB5A, Fields, 2 };
};

struct PvpTalentCategoryMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1891534, -1, 1, 1, 0xECB2C5C2, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1950197, -1, 4, 4, 0x9685CBCC, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 2066871, 1, 9, 9, 0xABE9CCC8, Fields, 6 };
};

struct QuestDrivenScenarioMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5917361, -1, 3, 3, 0x408DD33F, Fields, -1 };
};

struct QuestFactionRewardMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_SHORT, 10, true },
    };

    static constexpr DB2Meta Instance{ 1282622, -1, 1, 1, 0x221FFDAA, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1343388, -1, 8, 8, 0xA23F6D50, Fields, -1 };
};

struct QuestHubMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5905413, -1, 2, 2, 0x0DCCAAF0, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1120960, -1, 4, 4, 0xE505C927, Fields, -1 };
};

struct QuestLabelMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5202058, -1, 2, 1, 0x357F8064, Fields, 1 };
};

struct QuestLineMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 973430, -1, 7, 7, 0x27C5AD69, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 973441, -1, 4, 4, 0xDC11F6CD, Fields, 0 };
};

struct QuestMoneyRewardMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 10, false },
    };

    static constexpr DB2Meta Instance{ 1139047, -1, 1, 1, 0x01D6219A, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1251960, -1, 8, 7, 0x0262E5DB, Fields, 7 };
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

    static constexpr DB2Meta Instance{ 1251882, 0, 10, 10, 0xFDC814CF, Fields, 1 };
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

    static constexpr DB2Meta Instance{ 1251883, 0, 5, 4, 0x5CBBEFE7, Fields, 4 };
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

    static constexpr DB2Meta Instance{ 801743, -1, 4, 4, 0xD54BB6BA, Fields, -1 };
};

struct QuestSortMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_STRING, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1134585, -1, 3, 3, 0x9B92BE63, Fields, -1 };
};

struct QuestV2Meta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1139443, -1, 2, 2, 0x255073D5, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1028735, -1, 24, 24, 0xC8D602DB, Fields, -1 };
};

struct QuestXGroupActivityMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1573634, -1, 2, 2, 0xD85CBF41, Fields, -1 };
};

struct QuestXPMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_SHORT, 10, false },
    };

    static constexpr DB2Meta Instance{ 1139378, -1, 1, 1, 0x05F1DB7A, Fields, -1 };
};

struct QuestXUIQuestDetailsThemeMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3448517, -1, 2, 2, 0x8960239C, Fields, -1 };
};

struct QuestXUiWidgetSetMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 3923421, -1, 3, 3, 0x1DE0A282, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 3405439, 0, 6, 6, 0xD4FC9423, Fields, 5 };
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

    static constexpr DB2Meta Instance{ 3405440, -1, 5, 5, 0xBC0E9DE3, Fields, 0 };
};

struct RafActivityMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3081207, -1, 2, 2, 0x99D8A8BB, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1310245, -1, 10, 10, 0x4FD22743, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 3671785, -1, 6, 6, 0xC55E122F, Fields, 0 };
};

struct RelicSlotTierRequirementMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1716803, -1, 3, 3, 0xA6DB0949, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1671256, -1, 5, 5, 0x56CB54B7, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 3743117, -1, 18, 18, 0xBB3B0072, Fields, 3 };
};

struct RenownRewardsPlunderstormMeta
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

    static constexpr DB2Meta Instance{ 5662591, -1, 7, 7, 0x993A3149, Fields, 2 };
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

    static constexpr DB2Meta Instance{ 1133729, -1, 6, 6, 0x6BB8E374, Fields, -1 };
};

struct ResearchFieldMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_STRING, 1, true },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1133711, -1, 2, 2, 0xADCB0A04, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1134090, -1, 8, 8, 0x0D364DBB, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1134091, -1, 4, 4, 0xBD957EAB, Fields, -1 };
};

struct ResistancesMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_STRING, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1135072, -1, 3, 3, 0xF7AC4E26, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1307156, -1, 6, 6, 0x5FABA92D, Fields, -1 };
};

struct RewardPackXCurrencyTypeMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1307153, -1, 3, 2, 0x160ED195, Fields, 2 };
};

struct RewardPackXItemMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1307155, -1, 3, 2, 0x8BE182DE, Fields, 2 };
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

    static constexpr DB2Meta Instance{ 1398908, -1, 5, 5, 0xA3E01F13, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 3256786, -1, 9, 9, 0xCDF3F1B5, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 3500241, 1, 11, 11, 0x49ACF9E3, Fields, -1 };
};

struct SDReplacementModelMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1712172, -1, 1, 1, 0xA051D530, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 2056369, -1, 7, 7, 0xAC8B8862, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1139062, -1, 5, 5, 0x1D56A4D5, Fields, -1 };
};

struct ScenarioEventEntryMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1141065, -1, 2, 2, 0xC6F833BF, Fields, -1 };
};

struct ScenarioStepMeta
{
    static constexpr DB2MetaField Fields[12] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
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

    static constexpr DB2Meta Instance{ 1132761, 2, 12, 12, 0x00430C03, Fields, 3 };
};

struct SceneScriptMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 801754, -1, 3, 3, 0x48BF6E91, Fields, -1 };
};

struct SceneScriptGlobalTextMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_STRING_NOT_LOCALIZED, 1, true },
    };

    static constexpr DB2Meta Instance{ 1758036, -1, 2, 2, 0x4A2C4981, Fields, -1 };
};

struct SceneScriptPackageMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 801755, -1, 2, 2, 0x571B942C, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 801756, -1, 4, 4, 0x0A4D9E92, Fields, 0 };
};

struct SceneScriptTextMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_STRING_NOT_LOCALIZED, 1, true },
    };

    static constexpr DB2Meta Instance{ 1758037, -1, 2, 2, 0x4A2C4981, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1327082, -1, 5, 5, 0xEA2984EC, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1302849, -1, 12, 12, 0x8FAECE44, Fields, -1 };
};

struct ScreenEffectTypeMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3063174, -1, 1, 1, 0x5F754E48, Fields, -1 };
};

struct ScreenLocationMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
    };

    static constexpr DB2Meta Instance{ 1279416, -1, 1, 1, 0x4E07A6EC, Fields, -1 };
};

struct SeamlessSiteMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1328719, -1, 1, 1, 0x5F662944, Fields, 0 };
};

struct ServerMessagesMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_STRING, 1, true },
    };

    static constexpr DB2Meta Instance{ 1301141, -1, 1, 1, 0x022C43AA, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1239844, -1, 13, 13, 0xCDD57428, Fields, -1 };
};

struct SharedStringMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 4620073, 1, 3, 3, 0x02A60C13, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1954391, -1, 4, 4, 0x444C6957, Fields, -1 };
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
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1240935, 5, 15, 15, 0x6763217C, Fields, -1 };
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
        { FT_INT, 1, true },
        { FT_SHORT, 1, true },
        { FT_SHORT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
        { FT_SHORT, 1, true },
        { FT_SHORT, 1, true },
        { FT_SHORT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1266278, 3, 17, 17, 0xC070825E, Fields, 4 };
};

struct SkillLineXTraitTreeMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4505477, -1, 3, 3, 0x853B88D6, Fields, 0 };
};

struct SkillRaceClassInfoMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { FT_LONG, 1, true },
        { FT_SHORT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
        { FT_SHORT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1240406, -1, 7, 7, 0x7BCD9960, Fields, 1 };
};

struct SkySceneXPlayerConditionMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3581893, -1, 2, 1, 0xB57B5277, Fields, 1 };
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

    static constexpr DB2Meta Instance{ 3488583, -1, 6, 6, 0xB8BEC833, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 3594380, -1, 4, 4, 0x775CCBED, Fields, -1 };
};

struct SoulbindConduitEnhancedSocketMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4069554, -1, 2, 2, 0xFDA1BD8F, Fields, -1 };
};

struct SoulbindConduitItemMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3604984, -1, 2, 2, 0xEDC6BB40, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 3620681, -1, 4, 3, 0xA4866506, Fields, 3 };
};

struct SoulbindConduitRankPropertiesMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
    };

    static constexpr DB2Meta Instance{ 3858895, -1, 3, 3, 0x6EFBF7C9, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 3490472, -1, 8, 8, 0x943C338F, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1310628, -1, 7, 7, 0x6E25D515, Fields, -1 };
};

struct SoundAmbienceFlavorMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1267065, -1, 3, 2, 0x34C96927, Fields, 2 };
};

struct SoundBusMeta
{
    static constexpr DB2MetaField Fields[8] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_FLOAT, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1310246, 0, 8, 7, 0xA591AA63, Fields, 7 };
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

    static constexpr DB2Meta Instance{ 1598732, 0, 7, 7, 0x969A673E, Fields, 1 };
};

struct SoundEmitterPillPointsMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_FLOAT, 3, true },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1092317, -1, 3, 3, 0xC7C71E97, Fields, 1 };
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

    static constexpr DB2Meta Instance{ 1092316, 3, 12, 11, 0xB09CDD89, Fields, 11 };
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

    static constexpr DB2Meta Instance{ 1693131, -1, 7, 7, 0xFA91357A, Fields, 0 };
};

struct SoundFilterMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
    };

    static constexpr DB2Meta Instance{ 1271601, -1, 1, 1, 0x21188F13, Fields, -1 };
};

struct SoundFilterElemMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_FLOAT, 9, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1267066, -1, 3, 2, 0x7F024953, Fields, 2 };
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

    static constexpr DB2Meta Instance{ 1237434, -1, 16, 16, 0xA7FB0451, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1237436, -1, 56, 56, 0x3EE0D3A8, Fields, -1 };
};

struct SoundKitChildMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1307289, -1, 2, 2, 0x2927CB50, Fields, 1 };
};

struct SoundKitEntryMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1237435, -1, 5, 5, 0x8F82FF7D, Fields, 0 };
};

struct SoundKitFallbackMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1307288, -1, 2, 2, 0x6EE7A367, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 4618887, -1, 5, 5, 0x06BC7A80, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1266542, -1, 5, 5, 0x72095100, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 3405441, -1, 5, 5, 0x04E58352, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1279417, -1, 23, 23, 0x8FF22D98, Fields, -1 };
};

struct SoundWaterfallEmitterMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4756178, -1, 2, 2, 0xA0FC976E, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1313612, -1, 4, 3, 0xBE3A7BF3, Fields, 3 };
};

struct SpamMessagesMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
    };

    static constexpr DB2Meta Instance{ 1117088, -1, 1, 1, 0x5F2CCE2B, Fields, -1 };
};

struct SpecSetMemberMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2057624, -1, 2, 1, 0x504CA82E, Fields, 1 };
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

    static constexpr DB2Meta Instance{ 1240335, 1, 6, 6, 0xFA4367B5, Fields, 2 };
};

struct SpecializationSpellsDisplayMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_SHORT, 1, false },
        { FT_INT, 6, false },
    };

    static constexpr DB2Meta Instance{ 2067238, -1, 2, 2, 0x60F7EE9A, Fields, 0 };
};

struct SpellMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
    };

    static constexpr DB2Meta Instance{ 1140089, -1, 3, 3, 0xE3D134FB, Fields, -1 };
};

struct SpellActionBarPrefMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1019373, -1, 2, 2, 0x45039384, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1261603, -1, 10, 10, 0xD958FCA4, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1139952, -1, 8, 7, 0xEE8F35C1, Fields, 7 };
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

    static constexpr DB2Meta Instance{ 981566, -1, 14, 13, 0xC480D0A3, Fields, 13 };
};

struct SpellAuraVisXChrSpecMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_SHORT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1280615, -1, 2, 1, 0x893DE38B, Fields, 1 };
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

    static constexpr DB2Meta Instance{ 1280616, 0, 4, 3, 0xAA4D3429, Fields, 3 };
};

struct SpellCastTimesMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1134089, -1, 2, 2, 0x75B6BD3A, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1002166, -1, 7, 7, 0xEB5F42A0, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1139939, -1, 9, 8, 0x56C7533E, Fields, 8 };
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

    static constexpr DB2Meta Instance{ 1280619, -1, 6, 6, 0x1691EA31, Fields, -1 };
};

struct SpellChainEffectsMeta
{
    static constexpr DB2MetaField Fields[61] =
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
        { FT_SHORT, 1, false },
        { FT_SHORT, 11, false },
        { FT_FLOAT, 3, true },
        { FT_FLOAT, 3, true },
        { FT_FLOAT, 3, true },
        { FT_FLOAT, 3, true },
        { FT_INT, 3, true },
    };

    static constexpr DB2Meta Instance{ 1343310, -1, 61, 61, 0x4B046A55, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 979663, -1, 4, 4, 0xDFE6B427, Fields, -1 };
};

struct SpellClutterAreaEffectCountsMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2428696, -1, 3, 3, 0x37611746, Fields, -1 };
};

struct SpellClutterFrameRatesMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2428707, -1, 3, 3, 0x826C7494, Fields, -1 };
};

struct SpellClutterImpactModelCountsMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2428708, -1, 3, 3, 0x37611746, Fields, -1 };
};

struct SpellClutterKitDistancesMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2428697, -1, 3, 3, 0xC00F1458, Fields, -1 };
};

struct SpellClutterMissileDistMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2428733, -1, 3, 3, 0xC00F1458, Fields, -1 };
};

struct SpellClutterWeaponTrailDistMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2428698, -1, 3, 3, 0xC00F1458, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1139924, -1, 6, 5, 0x1CD8296C, Fields, 5 };
};

struct SpellDescriptionVariablesMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
    };

    static constexpr DB2Meta Instance{ 1140004, -1, 1, 1, 0x33868CFD, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1137829, -1, 4, 4, 0x47AA7AEB, Fields, -1 };
};

struct SpellDurationMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1137828, -1, 2, 2, 0xC25E0667, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1140088, -1, 29, 28, 0xE745F803, Fields, 28 };
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

    static constexpr DB2Meta Instance{ 1888495, -1, 9, 9, 0xA42E28EC, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1310248, -1, 4, 4, 0x164F4941, Fields, -1 };
};

struct SpellEmpowerMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4507381, 0, 3, 3, 0x87C43ED2, Fields, -1 };
};

struct SpellEmpowerStageMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4871072, -1, 3, 2, 0x69BA286D, Fields, 2 };
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

    static constexpr DB2Meta Instance{ 1140011, -1, 4, 4, 0xEB6AC546, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1146819, -1, 6, 6, 0x380879DE, Fields, -1 };
};

struct SpellFlyoutItemMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1134085, -1, 3, 2, 0xCBAF7BE8, Fields, 2 };
};

struct SpellFocusObjectMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_STRING, 1, true },
    };

    static constexpr DB2Meta Instance{ 1280620, -1, 1, 1, 0x782EE721, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1139906, -1, 5, 4, 0x9C916E46, Fields, 4 };
};

struct SpellItemEnchantmentMeta
{
    static constexpr DB2MetaField Fields[23] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 3, false },
        { FT_INT, 1, true },
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
        { FT_BYTE, 1, false },
        { FT_BYTE, 3, false },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1362771, -1, 23, 23, 0xD5D2C264, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1121834, -1, 6, 6, 0x8A436D37, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1127327, -1, 4, 4, 0xFA067CB2, Fields, -1 };
};

struct SpellLabelMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1347275, -1, 2, 1, 0x2B9F0138, Fields, 1 };
};

struct SpellLearnSpellMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1001907, -1, 3, 3, 0x6B9C3AC9, Fields, 0 };
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

    static constexpr DB2Meta Instance{ 1140079, -1, 6, 5, 0xCB43D67C, Fields, 5 };
};

struct SpellMechanicMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_STRING, 1, true },
    };

    static constexpr DB2Meta Instance{ 1014438, -1, 1, 1, 0x636442CA, Fields, -1 };
};

struct SpellMiscMeta
{
    static constexpr DB2MetaField Fields[17] =
    {
        { FT_INT, 15, true },
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
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

    static constexpr DB2Meta Instance{ 1003144, -1, 17, 16, 0x4823459D, Fields, 16 };
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

    static constexpr DB2Meta Instance{ 897956, -1, 15, 15, 0xEA25F580, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 897955, -1, 4, 4, 0x0200AB02, Fields, -1 };
};

struct SpellNameMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_STRING, 1, true },
    };

    static constexpr DB2Meta Instance{ 1990283, -1, 1, 1, 0x782EE721, Fields, -1 };
};

struct SpellOverrideNameMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2618823, -1, 3, 3, 0x8A85E5EA, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 982806, 0, 15, 14, 0x61AD223F, Fields, 14 };
};

struct SpellPowerDifficultyMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 982804, -1, 2, 2, 0x95EE63B1, Fields, -1 };
};

struct SpellProceduralEffectMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_BYTE, 1, true },
        { FT_FLOAT, 4, true },
    };

    static constexpr DB2Meta Instance{ 1140477, -1, 2, 2, 0x28692171, Fields, -1 };
};

struct SpellProcsPerMinuteMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_FLOAT, 1, true },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1133526, -1, 2, 2, 0x93C5F6BB, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1133525, -1, 4, 3, 0x6FFD8DA7, Fields, 3 };
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

    static constexpr DB2Meta Instance{ 1134584, -1, 4, 4, 0xF9A913EE, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1146820, -1, 5, 5, 0xF2B48795, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 841946, -1, 5, 5, 0xFF40D202, Fields, -1 };
};

struct SpellReagentsCurrencyMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1135239, -1, 3, 3, 0xF02FA4EB, Fields, 0 };
};

struct SpellReplacementMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4674394, -1, 2, 2, 0x516D34E6, Fields, 0 };
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

    static constexpr DB2Meta Instance{ 1139940, -1, 4, 4, 0xA285F9EA, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 3055899, -1, 5, 5, 0xD699825C, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 3055901, 1, 5, 4, 0x9BF410C7, Fields, 4 };
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

    static constexpr DB2Meta Instance{ 1139929, -1, 4, 4, 0xE9111399, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1280618, -1, 10, 10, 0xE12B5B32, Fields, -1 };
};

struct SpellSpecialUnitEffectMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_SHORT, 1, false },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1268903, -1, 2, 2, 0xDA6DFF4B, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1139993, -1, 8, 7, 0x6CBAAD1E, Fields, 7 };
};

struct SpellTotemsMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_SHORT, 2, false },
        { FT_INT, 2, true },
    };

    static constexpr DB2Meta Instance{ 1002162, -1, 3, 3, 0x03B23619, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 897952, -1, 16, 16, 0xFB411669, Fields, -1 };
};

struct SpellVisualAnimMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_SHORT, 1, true },
        { FT_SHORT, 1, true },
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1140479, -1, 3, 3, 0xEE416568, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1094006, -1, 11, 11, 0x49955168, Fields, -1 };
};

struct SpellVisualEffectNameMeta
{
    static constexpr DB2MetaField Fields[16] =
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
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 897948, -1, 16, 16, 0x14F15AE6, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1685317, -1, 11, 10, 0xB872A39E, Fields, 10 };
};

struct SpellVisualKitMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 2, true },
    };

    static constexpr DB2Meta Instance{ 897949, -1, 5, 5, 0x0B92E9E2, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 897951, -1, 6, 6, 0x0B45E5D4, Fields, -1 };
};

struct SpellVisualKitEffectMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1140480, -1, 3, 2, 0xE3206CA2, Fields, 2 };
};

struct SpellVisualKitModelAttachMeta
{
    static constexpr DB2MetaField Fields[23] =
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
        { FT_SHORT, 1, true },
        { FT_SHORT, 1, true },
        { FT_SHORT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 897953, -1, 23, 22, 0x57620444, Fields, 22 };
};

struct SpellVisualKitPickerMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3989478, -1, 2, 2, 0x2F0CF749, Fields, -1 };
};

struct SpellVisualKitPickerEntryMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3989479, -1, 3, 2, 0x74A4E4CF, Fields, 2 };
};

struct SpellVisualMissileMeta
{
    static constexpr DB2MetaField Fields[19] =
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
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 897954, 2, 19, 18, 0x98490368, Fields, 18 };
};

struct SpellVisualScreenEffectMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3607312, -1, 2, 2, 0x2724A46D, Fields, -1 };
};

struct SpellXDescriptionVariablesMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1724949, -1, 2, 2, 0x23F4E51E, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1101657, 0, 13, 12, 0x6B6594B0, Fields, 12 };
};

struct SpotLightConditionMapMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5735565, -1, 5, 5, 0x04E3CAA3, Fields, 0 };
};

struct StartupFilesMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1604265, -1, 3, 3, 0x3E639C9F, Fields, -1 };
};

struct Startup_StringsMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_STRING, 1, true },
    };

    static constexpr DB2Meta Instance{ 1375805, -1, 2, 2, 0xD758674F, Fields, -1 };
};

struct StationeryMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 2, true },
    };

    static constexpr DB2Meta Instance{ 1140758, -1, 3, 3, 0xF075ED96, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1345276, -1, 5, 5, 0xA4CA5ECF, Fields, -1 };
};

struct TactKeyMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_BYTE, 16, false },
    };

    static constexpr DB2Meta Instance{ 1302850, -1, 1, 1, 0xCBA490FC, Fields, -1 };
};

struct TactKeyLookupMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_BYTE, 8, false },
    };

    static constexpr DB2Meta Instance{ 1302851, -1, 1, 1, 0x4983962C, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1369062, -1, 9, 9, 0x6CBC2884, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1068100, 4, 15, 15, 0xE7B597F0, Fields, 5 };
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

    static constexpr DB2Meta Instance{ 1067802, 0, 4, 4, 0xA303DE51, Fields, 1 };
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

    static constexpr DB2Meta Instance{ 1000437, 1, 9, 9, 0xB70D1EE0, Fields, 2 };
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

    static constexpr DB2Meta Instance{ 3501705, -1, 4, 4, 0xA22946B5, Fields, -1 };
};

struct TerrainMaterialMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1307290, -1, 3, 3, 0xE1D9583A, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1310249, -1, 5, 5, 0xEC0D143D, Fields, -1 };
};

struct TerrainTypeSoundsMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
    };

    static constexpr DB2Meta Instance{ 1284822, -1, 1, 1, 0xB99F5777, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1328721, -1, 11, 11, 0x4A955778, Fields, -1 };
};

struct TextureFileDataMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 982459, 0, 3, 3, 0x50299C02, Fields, 2 };
};

struct TierTransitionMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, true },
        { FT_SHORT, 1, true },
        { FT_SHORT, 1, true },
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3076928, -1, 4, 4, 0x2591A17F, Fields, -1 };
};

struct TotemCategoryMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_STRING, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1134586, -1, 3, 3, 0x86C8149C, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 988200, 1, 5, 5, 0xC55DB9B0, Fields, -1 };
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
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1301101, -1, 6, 6, 0x7F2B6CD0, Fields, -1 };
};

struct TradeSkillItemMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1329070, -1, 1, 1, 0x05D8D675, Fields, -1 };
};

struct TraitCondMeta
{
    static constexpr DB2MetaField Fields[17] =
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
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4543085, 0, 17, 17, 0xBFDD1994, Fields, 2 };
};

struct TraitCondAccountElementMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_LONG, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5890759, 1, 3, 3, 0xD753B438, Fields, 2 };
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

    static constexpr DB2Meta Instance{ 4420295, 1, 4, 4, 0x35853DF0, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 4524216, 0, 5, 5, 0x59214AB9, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 4539393, 1, 9, 9, 0x3FE6D68D, Fields, 2 };
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

    static constexpr DB2Meta Instance{ 4420327, 3, 8, 8, 0x060A9F4C, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 4536895, 0, 5, 5, 0x01AE39C2, Fields, 1 };
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

    static constexpr DB2Meta Instance{ 4420308, 0, 5, 5, 0xD4EA9447, Fields, 2 };
};

struct TraitNodeMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4420297, 0, 7, 7, 0xA01A518A, Fields, 1 };
};

struct TraitNodeEntryMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4420298, 0, 5, 5, 0x733B015D, Fields, -1 };
};

struct TraitNodeEntryXTraitCondMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4543088, 0, 3, 3, 0x59B38176, Fields, 2 };
};

struct TraitNodeEntryXTraitCostMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4420299, 0, 3, 3, 0xE87DE277, Fields, 1 };
};

struct TraitNodeGroupMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4420300, 0, 3, 3, 0xECA626BE, Fields, 1 };
};

struct TraitNodeGroupXTraitCondMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4543090, 0, 3, 3, 0x3F06B639, Fields, 2 };
};

struct TraitNodeGroupXTraitCostMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4420301, 0, 3, 3, 0xFD4B937C, Fields, 1 };
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

    static constexpr DB2Meta Instance{ 4420302, 0, 4, 4, 0xB9288EB8, Fields, 1 };
};

struct TraitNodeXTraitCondMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4543092, 0, 3, 3, 0xE2160AA8, Fields, 2 };
};

struct TraitNodeXTraitCostMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4420303, 0, 3, 3, 0x4D8C0D05, Fields, 1 };
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

    static constexpr DB2Meta Instance{ 4420304, 0, 4, 4, 0x802ED455, Fields, 1 };
};

struct TraitSubTreeMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5534447, 2, 5, 5, 0x716FF6FB, Fields, 4 };
};

struct TraitSystemMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4635649, 0, 3, 3, 0x46225291, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 4420305, 0, 8, 8, 0xE0C67577, Fields, 1 };
};

struct TraitTreeLoadoutMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4669507, 0, 3, 3, 0x963A2972, Fields, 1 };
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

    static constexpr DB2Meta Instance{ 4669509, 0, 6, 6, 0xF17F8192, Fields, 1 };
};

struct TraitTreeXTraitCostMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4420306, 0, 3, 3, 0x19EEFE95, Fields, 1 };
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

    static constexpr DB2Meta Instance{ 4524218, 0, 4, 4, 0xE093CD62, Fields, 2 };
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

    static constexpr DB2Meta Instance{ 1338702, -1, 5, 5, 0x45999148, Fields, -1 };
};

struct TransmogDefaultLevelMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2399695, -1, 2, 2, 0xF003EFFC, Fields, -1 };
};

struct TransmogHolidayMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1589454, -1, 1, 1, 0x2E75ADD0, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 3580450, 0, 5, 5, 0xDCE032AF, Fields, -1 };
};

struct TransmogSetMeta
{
    static constexpr DB2MetaField Fields[13] =
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
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1376213, 1, 13, 13, 0xC6875C71, Fields, 7 };
};

struct TransmogSetGroupMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_STRING, 1, true },
    };

    static constexpr DB2Meta Instance{ 1576116, -1, 1, 1, 0xEDA13DE2, Fields, -1 };
};

struct TransmogSetItemMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1376212, -1, 3, 3, 0xE6EFF061, Fields, 0 };
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

    static constexpr DB2Meta Instance{ 1140686, -1, 4, 3, 0xE622B105, Fields, 3 };
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

    static constexpr DB2Meta Instance{ 1121973, -1, 10, 10, 0xE05919AE, Fields, -1 };
};

struct TransportRotationMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_FLOAT, 4, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1140687, -1, 3, 2, 0xD92B0C43, Fields, 2 };
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

    static constexpr DB2Meta Instance{ 975024, -1, 4, 4, 0xA17123C5, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 5011999, 2, 9, 9, 0x11F1EB32, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 3488582, -1, 13, 13, 0x3425F0FF, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 3502042, -1, 4, 4, 0x6809E08F, Fields, 0 };
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

    static constexpr DB2Meta Instance{ 3502043, 2, 16, 16, 0x97798781, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 4579858, 1, 8, 8, 0x3FCA960D, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 4065278, 0, 12, 12, 0x6242874E, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 3946498, 6, 22, 22, 0xEF224D81, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1729547, 0, 6, 6, 0x4C41293C, Fields, -1 };
};

struct UIExpansionDisplayInfoIconMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1729546, -1, 3, 3, 0x54B6542E, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 4861207, 3, 10, 10, 0x712E00ED, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 4530951, -1, 8, 8, 0x41E631A7, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 3556601, -1, 26, 26, 0x016692F7, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 2960122, -1, 15, 15, 0x258B0032, Fields, -1 };
};

struct UiCamFbackTalkingHeadChrRaceMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3055924, -1, 4, 3, 0x86B8A1FD, Fields, 3 };
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

    static constexpr DB2Meta Instance{ 1261406, -1, 5, 5, 0x73A05FC7, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1261407, -1, 4, 4, 0xBDAFC2E9, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1120287, -1, 9, 9, 0x2FD2C951, Fields, -1 };
};

struct UiCameraTypeMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1120288, -1, 3, 3, 0xF315BDCB, Fields, -1 };
};

struct UiCanvasMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_SHORT, 1, true },
        { FT_SHORT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1989363, -1, 2, 2, 0x9CA2CFB4, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 3509132, -1, 13, 13, 0xAB70272F, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 3182424, -1, 17, 17, 0x83EEB315, Fields, -1 };
};

struct UiMapMeta
{
    static constexpr DB2MetaField Fields[16] =
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
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
    };

    static constexpr DB2Meta Instance{ 1957206, 1, 16, 16, 0x77AEDBE6, Fields, 2 };
};

struct UiMapArtMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1957202, -1, 3, 3, 0x3AE7D144, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1957208, -1, 9, 8, 0x3F597F5A, Fields, 8 };
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

    static constexpr DB2Meta Instance{ 1957210, -1, 5, 4, 0x2DA5B77B, Fields, 4 };
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

    static constexpr DB2Meta Instance{ 1957219, 3, 10, 10, 0xF9899D73, Fields, 4 };
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

    static constexpr DB2Meta Instance{ 2006972, 0, 4, 4, 0xC42F6D05, Fields, 1 };
};

struct UiMapFogOfWarVisualizationMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2006973, -1, 3, 3, 0xD0E714A2, Fields, -1 };
};

struct UiMapGroupMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 6033745, -1, 1, 1, 0x6D5EB3BD, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1957204, -1, 5, 5, 0x0FF75B01, Fields, 1 };
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

    static constexpr DB2Meta Instance{ 2030690, 2, 10, 10, 0x712A46E6, Fields, 3 };
};

struct UiMapXMapArtMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1957217, -1, 3, 2, 0xEAE7DA2A, Fields, 2 };
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

    static constexpr DB2Meta Instance{ 1548215, 0, 4, 4, 0x7A47260D, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1548214, 2, 10, 10, 0xB506AAFE, Fields, 3 };
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

    static constexpr DB2Meta Instance{ 1548216, -1, 7, 7, 0x7BD2B582, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1548213, 3, 16, 16, 0xCA931A83, Fields, 4 };
};

struct UiPartyPoseMeta
{
    static constexpr DB2MetaField Fields[12] =
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
    };

    static constexpr DB2Meta Instance{ 1993323, 2, 12, 11, 0x1AE713AB, Fields, 11 };
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

    static constexpr DB2Meta Instance{ 3448518, -1, 4, 4, 0xE7D161DC, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 897470, 0, 5, 5, 0xEF905486, Fields, -1 };
};

struct UiTextureAtlasElementMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1989276, 1, 2, 2, 0x7CCBD18F, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 5319042, 0, 7, 7, 0x32F4C664, Fields, -1 };
};

struct UiTextureAtlasMemberMeta
{
    static constexpr DB2MetaField Fields[14] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, true },
        { FT_SHORT, 1, true },
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

    static constexpr DB2Meta Instance{ 897532, 1, 14, 14, 0x75E12F73, Fields, 9 };
};

struct UiTextureKitMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
    };

    static constexpr DB2Meta Instance{ 939159, -1, 1, 1, 0x4740638A, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 4737221, 0, 4, 4, 0x0AF4CDD1, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1983278, 1, 9, 9, 0x0B3EABFD, Fields, -1 };
};

struct UiWidgetConstantSourceMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1983639, -1, 3, 2, 0x689BD038, Fields, 2 };
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

    static constexpr DB2Meta Instance{ 1983640, -1, 4, 3, 0xC3560ADB, Fields, 3 };
};

struct UiWidgetMapMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2322531, -1, 2, 1, 0xF88A11E0, Fields, 1 };
};

struct UiWidgetSetMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3055925, -1, 2, 2, 0x53EBAF4D, Fields, -1 };
};

struct UiWidgetStringSourceMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_STRING, 1, true },
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1983641, -1, 3, 2, 0x0E572854, Fields, 2 };
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

    static constexpr DB2Meta Instance{ 2740907, 1, 6, 5, 0x7E725F61, Fields, 5 };
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

    static constexpr DB2Meta Instance{ 1983276, -1, 10, 10, 0x4FB2B780, Fields, -1 };
};

struct UiWidgetXWidgetSetMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3386363, -1, 2, 1, 0xA7D2352A, Fields, 1 };
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

    static constexpr DB2Meta Instance{ 1284821, -1, 6, 6, 0x3BE373BC, Fields, -1 };
};

struct UnitBloodLevelsMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_BYTE, 3, false },
    };

    static constexpr DB2Meta Instance{ 1268904, -1, 1, 1, 0x13B47815, Fields, -1 };
};

struct UnitConditionMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, true },
        { FT_BYTE, 8, false },
        { FT_BYTE, 8, false },
        { FT_INT, 8, true },
    };

    static constexpr DB2Meta Instance{ 1120959, -1, 4, 4, 0x215FAF83, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1237753, -1, 16, 16, 0x9840FB71, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1368621, -1, 18, 18, 0xEF5C7D41, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 3311405, -1, 5, 5, 0x55F18A29, Fields, -1 };
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
        { FT_INT, 1, true },
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

    static constexpr DB2Meta Instance{ 1345447, -1, 61, 61, 0x53C25193, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1279741, -1, 4, 3, 0x1A05C81D, Fields, 3 };
};

struct VehicleUIIndicatorMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1279740, -1, 1, 1, 0x13526596, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 892861, -1, 10, 10, 0x5F633954, Fields, -1 };
};

struct VignetteUiWidgetSetMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 5634692, -1, 3, 3, 0x371E3280, Fields, -1 };
};

struct VirtualAttachmentMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_SHORT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1634482, -1, 2, 2, 0xECAB5C57, Fields, -1 };
};

struct VirtualAttachmentCustomizationMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_SHORT, 1, true },
        { FT_INT, 1, true },
        { FT_SHORT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1634480, -1, 3, 3, 0xD7602227, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1267067, -1, 4, 4, 0xA68C221C, Fields, -1 };
};

struct VoiceOverPriorityMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4211372, -1, 3, 3, 0x11177BA9, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 3587230, -1, 4, 3, 0x00F4D6A5, Fields, 3 };
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

    static constexpr DB2Meta Instance{ 1355528, 1, 15, 15, 0x58247DE7, Fields, 2 };
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

    static constexpr DB2Meta Instance{ 1323241, -1, 5, 4, 0x01230A50, Fields, 4 };
};

struct WarbandSceneMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_FLOAT, 3, true },
        { FT_FLOAT, 3, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5736126, -1, 5, 5, 0x820B84A9, Fields, 2 };
};

struct WarbandSceneAnimationMeta
{
    static constexpr DB2MetaField Fields[8] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 2, true },
    };

    static constexpr DB2Meta Instance{ 5754555, -1, 8, 8, 0xFE782BEF, Fields, -1 };
};

struct WarbandScenePlacementMeta
{
    static constexpr DB2MetaField Fields[8] =
    {
        { FT_FLOAT, 3, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5736130, 1, 8, 7, 0x92B0F0A8, Fields, 7 };
};

struct WarbandScenePlcmntAnimOverrideMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5756286, -1, 2, 2, 0xDC611338, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 2565222, -1, 19, 19, 0xA04B6E29, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 2565258, -1, 5, 5, 0xA411A334, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 2565265, -1, 6, 6, 0x3B97E4DE, Fields, -1 };
};

struct WaypointSafeLocsMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_FLOAT, 3, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2820850, -1, 2, 2, 0xCB4F0BC3, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 879634, -1, 5, 5, 0x814E6C18, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1267648, -1, 7, 7, 0x21DD049D, Fields, -1 };
};

struct WeaponSwingSounds2Meta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1267068, -1, 3, 3, 0x8CC18B68, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 982461, -1, 9, 9, 0x334DF54B, Fields, -1 };
};

struct WeaponTrailModelDefMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1239843, -1, 3, 2, 0x0E7C9A0C, Fields, 2 };
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

    static constexpr DB2Meta Instance{ 1239842, -1, 10, 9, 0xD0867913, Fields, 9 };
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

    static constexpr DB2Meta Instance{ 1343311, -1, 23, 23, 0x62855DFC, Fields, -1 };
};

struct WeatherXParticulateMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1965591, -1, 2, 1, 0x568F5BC4, Fields, 1 };
};

struct WeeklyRewardChestActivityTierMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5390446, 0, 3, 3, 0x93CE3FB3, Fields, -1 };
};

struct WeeklyRewardChestThresholdMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3580962, -1, 3, 3, 0xD70784C5, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 943871, -1, 10, 10, 0x5DE91550, Fields, -1 };
};

struct WorldBossLockoutMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 975279, -1, 2, 2, 0xED46F0AE, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1267069, -1, 7, 7, 0x01DC06CF, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1343312, -1, 6, 6, 0x2134DDFE, Fields, -1 };
};

struct WorldElapsedTimerMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_STRING, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1135240, -1, 3, 3, 0x057E7307, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 4550228, 2, 4, 4, 0x416E01AD, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1134579, 0, 13, 13, 0x4CFAAE44, Fields, 1 };
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

    static constexpr DB2Meta Instance{ 1957212, -1, 5, 4, 0x2C843422, Fields, 4 };
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

    static constexpr DB2Meta Instance{ 4680120, -1, 4, 4, 0xFAF1FC05, Fields, -1 };
};

struct WorldStateExpressionMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
    };

    static constexpr DB2Meta Instance{ 1332558, -1, 1, 1, 0xCA33F540, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1266941, -1, 9, 9, 0xBF9A8A42, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1310255, -1, 7, 7, 0x06AB7E95, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1310251, -1, 4, 4, 0xE1F93744, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1310253, -1, 8, 8, 0x94CE95E0, Fields, -1 };
};

struct ZoneLightPointMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_FLOAT, 2, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1310256, -1, 3, 2, 0xDE2377FB, Fields, 2 };
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

    static constexpr DB2Meta Instance{ 1310254, -1, 4, 4, 0x72572D05, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1797864, -1, 4, 3, 0x3D386FF2, Fields, 3 };
};

#endif // DB2Metadata_h__
