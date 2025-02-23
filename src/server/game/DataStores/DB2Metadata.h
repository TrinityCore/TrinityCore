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

struct AccountStoreCategoryMeta
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

    static constexpr DB2Meta Instance{ 6220124, 1, 6, 6, 0xE78C9607, Fields, 2 };
};

struct AccountStoreItemMeta
{
    static constexpr DB2MetaField Fields[17] =
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
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 6197817, 2, 17, 17, 0x818F4DA6, Fields, 3 };
};

struct AchievementMeta
{
    static constexpr DB2MetaField Fields[15] =
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
        { FT_INT, 1, false },
        { FT_SHORT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1260179, 3, 15, 15, 0x7B166E4B, Fields, 11 };
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
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 2, false },
        { FT_BYTE, 2, false },
    };

    static constexpr DB2Meta Instance{ 1115949, -1, 22, 22, 0xDE04598C, Fields, -1 };
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
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1710672, 0, 8, 8, 0xD60FC8BF, Fields, -1 };
};

struct AlliedRaceRacialAbilityMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1720145, -1, 5, 4, 0x0F2AA8B5, Fields, 4 };
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
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1375433, -1, 5, 5, 0x94F5DA04, Fields, -1 };
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
    static constexpr DB2MetaField Fields[18] =
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
    };

    static constexpr DB2Meta Instance{ 1304324, -1, 18, 18, 0x748C966C, Fields, 0 };
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

struct AoiBoxMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_FLOAT, 6, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2140223, -1, 5, 4, 0xBDA8526F, Fields, 4 };
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
    static constexpr DB2MetaField Fields[17] =
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
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, true },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1000630, 2, 17, 17, 0xB03CC0D5, Fields, 11 };
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
        { FT_BYTE, 1, true },
        { FT_SHORT, 1, false },
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
        { FT_SHORT, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 2, true },
        { FT_SHORT, 4, false },
    };

    static constexpr DB2Meta Instance{ 1353545, -1, 23, 23, 0x0A6204DD, Fields, -1 };
};

struct AreaTriggerMeta
{
    static constexpr DB2MetaField Fields[16] =
    {
        { FT_STRING, 1, true },
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

    static constexpr DB2Meta Instance{ 1354401, 2, 16, 16, 0xB4ACA6C2, Fields, 3 };
};

struct AreaTriggerActionSetMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_SHORT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1352378, -1, 1, 1, 0x6942F9DD, Fields, -1 };
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

struct AreaTriggerSphereMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1315630, -1, 1, 1, 0xB851EBF6, Fields, -1 };
};

struct ArenaCcItemMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3849793, 0, 3, 2, 0x4C5721FD, Fields, 2 };
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

    static constexpr DB2Meta Instance{ 1007934, 1, 11, 11, 0x9284635D, Fields, -1 };
};

struct ArtifactAppearanceMeta
{
    static constexpr DB2MetaField Fields[15] =
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
    };

    static constexpr DB2Meta Instance{ 1116407, 1, 15, 15, 0xFC032ED7, Fields, 2 };
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

    static constexpr DB2Meta Instance{ 1116408, 2, 9, 8, 0x0F103A17, Fields, 8 };
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
    static constexpr DB2MetaField Fields[9] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4366440, 2, 9, 8, 0x034AADE3, Fields, 8 };
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
    static constexpr DB2MetaField Fields[8] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
        { FT_FLOAT, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1237437, 2, 8, 8, 0xEDF37179, Fields, -1 };
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
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 801576, -1, 3, 2, 0x6994570D, Fields, 2 };
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
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_FLOAT, 1, true },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 801578, -1, 2, 2, 0x77560795, Fields, -1 };
};

struct BattlePetBreedStateMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 801579, -1, 3, 2, 0x0DA4A2A5, Fields, 2 };
};

struct BattlePetDisplayOverrideMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1802988, -1, 4, 4, 0x8F75CC44, Fields, -1 };
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
    static constexpr DB2MetaField Fields[11] =
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
    };

    static constexpr DB2Meta Instance{ 841622, 2, 11, 11, 0xE306EEEA, Fields, -1 };
};

struct BattlePetSpeciesStateMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 801581, -1, 3, 2, 0x5999BD05, Fields, 2 };
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
    static constexpr DB2MetaField Fields[18] =
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
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1360265, -1, 18, 18, 0x757BE902, Fields, -1 };
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
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1367866, -1, 5, 4, 0x218C9656, Fields, 4 };
};

struct BountySetMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1367865, -1, 2, 2, 0xE32AA927, Fields, -1 };
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
        { FT_SHORT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 2, false },
        { FT_SHORT, 3, false },
        { FT_SHORT, 3, false },
    };

    static constexpr DB2Meta Instance{ 841604, 2, 12, 12, 0x0DD39BE3, Fields, -1 };
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
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1117696, -1, 16, 15, 0x2B6832AA, Fields, 15 };
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
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 2031607, 2, 6, 6, 0x3ABB9FCC, Fields, -1 };
};

struct CampaignXConditionMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2031611, -1, 3, 2, 0x59F4979F, Fields, 2 };
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
    static constexpr DB2MetaField Fields[15] =
    {
        { FT_FLOAT, 3, true },
        { FT_INT, 1, false },
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

    static constexpr DB2Meta Instance{ 1592470, 1, 15, 15, 0x9A9DA61C, Fields, -1 };
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

struct CharBaseInfoMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
    };

    static constexpr DB2Meta Instance{ 1343386, -1, 2, 2, 0xCF7B9440, Fields, -1 };
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
        { FT_SHORT, 1, true },
        { FT_SHORT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1360262, -1, 2, 2, 0x9CA2CFB4, Fields, -1 };
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
    static constexpr DB2MetaField Fields[10] =
    {
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1256914, -1, 10, 10, 0x80105E60, Fields, 0 };
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
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 972425, -1, 9, 9, 0xFF41E21A, Fields, 0 };
};

struct CharShipmentContainerMeta
{
    static constexpr DB2MetaField Fields[16] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
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

    static constexpr DB2Meta Instance{ 972405, -1, 16, 16, 0xC5BCDA8C, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1237591, -1, 7, 6, 0xEF63572A, Fields, 6 };
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
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_LONG, 1, true },
        { FT_INT, 1, false },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1344281, 1, 5, 5, 0xD040DB31, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1815417, -1, 12, 12, 0x6C7A7648, Fields, -1 };
};

struct ChatChannelsMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1345278, 2, 6, 6, 0x396374C8, Fields, -1 };
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
    static constexpr DB2MetaField Fields[26] =
    {
        { FT_STRING, 1, true },
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1361031, 5, 26, 26, 0xE20D59D3, Fields, -1 };
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

struct ChrCustClientChoiceConversionMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3590348, 0, 4, 3, 0x8ED0FBED, Fields, 3 };
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
    static constexpr DB2MetaField Fields[7] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3526439, -1, 7, 7, 0x7617515B, Fields, -1 };
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
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3593032, 0, 6, 6, 0x9BA35F7B, Fields, -1 };
};

struct ChrCustomizationElementMeta
{
    static constexpr DB2MetaField Fields[14] =
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
    };

    static constexpr DB2Meta Instance{ 3512765, 0, 14, 14, 0xD68DCDEA, Fields, -1 };
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
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3459652, 0, 3, 3, 0xE61F7A35, Fields, -1 };
};

struct ChrCustomizationOptionMeta
{
    static constexpr DB2MetaField Fields[12] =
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
    };

    static constexpr DB2Meta Instance{ 3384247, 1, 12, 12, 0x6714C155, Fields, 4 };
};

struct ChrCustomizationReqMeta
{
    static constexpr DB2MetaField Fields[9] =
    {
        { FT_LONG, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3450453, 2, 9, 9, 0xCD8FE1D1, Fields, -1 };
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
    static constexpr DB2MetaField Fields[10] =
    {
        { FT_INT, 1, false },
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

    static constexpr DB2Meta Instance{ 3548976, 0, 10, 9, 0x31F57E28, Fields, 9 };
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
    static constexpr DB2MetaField Fields[57] =
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
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 3, false },
        { FT_INT, 3, false },
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
        { FT_SHORT, 1, true },
        { FT_SHORT, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
    };

    static constexpr DB2Meta Instance{ 1305311, -1, 57, 57, 0xE8A71CAF, Fields, -1 };
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
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_FLOAT, 3, true },
        { FT_INT, 1, false },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1294214, -1, 4, 4, 0xF96842A0, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 3067644, -1, 3, 2, 0x37C7ABA7, Fields, 2 };
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
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1661584, -1, 4, 3, 0x1EA5D83E, Fields, 3 };
};

struct CommunityIconMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2098645, 0, 3, 3, 0x9E7BAA93, Fields, -1 };
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

struct ContentTuningMeta
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

    static constexpr DB2Meta Instance{ 1962930, 0, 6, 6, 0x1FB45111, Fields, -1 };
};

struct ContributionMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 4, true },
    };

    static constexpr DB2Meta Instance{ 1587153, 2, 7, 7, 0x167173C3, Fields, 3 };
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
    static constexpr DB2MetaField Fields[8] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1260801, -1, 8, 8, 0x0F1FE894, Fields, -1 };
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
    static constexpr DB2MetaField Fields[7] =
    {
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 8, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 879282, -1, 7, 6, 0x43F263AF, Fields, 6 };
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
    static constexpr DB2MetaField Fields[26] =
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
        { FT_INT, 4, true },
    };

    static constexpr DB2Meta Instance{ 1108759, 0, 26, 26, 0xD89C751C, Fields, -1 };
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
    static constexpr DB2MetaField Fields[13] =
    {
        { FT_INT, 1, false },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 3, false },
    };

    static constexpr DB2Meta Instance{ 1264997, 0, 13, 13, 0x4C6F7221, Fields, -1 };
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

struct CreatureFamilyMeta
{
    static constexpr DB2MetaField Fields[10] =
    {
        { FT_STRING, 1, true },
        { FT_FLOAT, 1, true },
        { FT_BYTE, 1, true },
        { FT_FLOAT, 1, true },
        { FT_BYTE, 1, true },
        { FT_SHORT, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_SHORT, 2, true },
    };

    static constexpr DB2Meta Instance{ 1351351, -1, 10, 10, 0x71DA07B7, Fields, -1 };
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

struct CreatureModelDataMeta
{
    static constexpr DB2MetaField Fields[29] =
    {
        { FT_FLOAT, 6, true },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
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
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1365368, -1, 29, 29, 0x4A4CF256, Fields, -1 };
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

struct CreatureSpellDataMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 4, true },
        { FT_INT, 4, true },
    };

    static constexpr DB2Meta Instance{ 3032554, -1, 2, 2, 0x9189AF29, Fields, -1 };
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
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1587158, 0, 3, 2, 0x8EAB9EE3, Fields, 2 };
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
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1125667, -1, 3, 3, 0x12EB5F37, Fields, -1 };
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
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1934603, -1, 8, 7, 0x4A649F1A, Fields, 7 };
};

struct CurrencyTypesMeta
{
    static constexpr DB2MetaField Fields[14] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 2, true },
    };

    static constexpr DB2Meta Instance{ 1095531, -1, 14, 14, 0xA0DA38E0, Fields, -1 };
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
    static constexpr DB2MetaField Fields[18] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
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
    };

    static constexpr DB2Meta Instance{ 1278176, 0, 18, 18, 0xF39349FF, Fields, -1 };
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
        { FT_INT, 1, false },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
    };

    static constexpr DB2Meta Instance{ 1122116, -1, 22, 22, 0xC0CB9712, Fields, -1 };
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
    static constexpr DB2MetaField Fields[14] =
    {
        { FT_STRING, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1352127, -1, 14, 14, 0xB338FF51, Fields, -1 };
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
    static constexpr DB2MetaField Fields[8] =
    {
        { FT_STRING, 1, true },
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1343313, 2, 8, 8, 0x9FAD46FA, Fields, -1 };
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

struct FactionMeta
{
    static constexpr DB2MetaField Fields[18] =
    {
        { FT_LONG, 4, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_SHORT, 1, true },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
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

    static constexpr DB2Meta Instance{ 1361972, 3, 18, 18, 0xE3A94265, Fields, -1 };
};

struct FactionGroupMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1343595, 2, 6, 6, 0x62684017, Fields, -1 };
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
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_STRING, 1, true },
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1237638, -1, 3, 3, 0xDA471F1D, Fields, 1 };
};

struct FriendshipReputationMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1237639, 1, 4, 4, 0x7E69A97F, Fields, -1 };
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
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2922072, 0, 2, 2, 0x08DEAF7F, Fields, -1 };
};

struct GameModeMeta
{
    static constexpr DB2MetaField Fields[9] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5008306, -1, 9, 9, 0x60A1CBA9, Fields, -1 };
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
    static constexpr DB2MetaField Fields[7] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_FLOAT, 6, true },
        { FT_INT, 1, true },
        { FT_SHORT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1266277, -1, 7, 7, 0x7C5F0B90, Fields, -1 };
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

struct GameObjectsMeta
{
    static constexpr DB2MetaField Fields[13] =
    {
        { FT_STRING, 1, true },
        { FT_FLOAT, 3, true },
        { FT_FLOAT, 4, true },
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, false },
        { FT_FLOAT, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 8, true },
    };

    static constexpr DB2Meta Instance{ 841620, 3, 13, 13, 0x9E707394, Fields, 4 };
};

struct GameTipsMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_STRING, 1, true },
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1368021, -1, 4, 4, 0xF70DB051, Fields, -1 };
};

struct GarrAbilityMeta
{
    static constexpr DB2MetaField Fields[8] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 966238, 2, 8, 8, 0x1297C851, Fields, -1 };
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
        { FT_BYTE, 1, false },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 966241, 0, 12, 12, 0xCEA59782, Fields, 1 };
};

struct GarrBuildingMeta
{
    static constexpr DB2MetaField Fields[24] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
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
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 929747, -1, 24, 24, 0x7785BDDC, Fields, -1 };
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
    static constexpr DB2MetaField Fields[8] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 981570, 3, 8, 8, 0xEBFDA71A, Fields, -1 };
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
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1118784, -1, 7, 7, 0xA2093B95, Fields, -1 };
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
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1572314, 0, 5, 5, 0x3E6B889F, Fields, -1 };
};

struct GarrMechanicMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_BYTE, 1, false },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 967963, -1, 3, 3, 0xED9C4A65, Fields, -1 };
};

struct GarrMechanicSetXMechanicMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1391531, 0, 3, 2, 0xE3B55DDA, Fields, 2 };
};

struct GarrMechanicTypeMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 967964, 2, 5, 5, 0x84BA4276, Fields, -1 };
};

struct GarrMissionMeta
{
    static constexpr DB2MetaField Fields[29] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_FLOAT, 2, true },
        { FT_FLOAT, 2, true },
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
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
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 967962, 5, 29, 28, 0x1452FB94, Fields, 28 };
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
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 967960, 0, 5, 4, 0xBED2763F, Fields, 4 };
};

struct GarrMissionXFollowerMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1359096, -1, 3, 2, 0x68F00E16, Fields, 2 };
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

struct GarrTypeMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 2, true },
    };

    static constexpr DB2Meta Instance{ 1333161, -1, 5, 5, 0x0B1AC288, Fields, -1 };
};

struct GarrUiAnimClassInfoMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 976037, -1, 6, 6, 0x8EB2E057, Fields, -1 };
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
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1343604, -1, 3, 3, 0x68ADF6E0, Fields, -1 };
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
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1345274, -1, 5, 5, 0x73F1D2B7, Fields, -1 };
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

struct GlyphSlotMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1130095, -1, 2, 2, 0x36A4E8D8, Fields, -1 };
};

struct GossipNPCOptionMeta
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
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4278503, -1, 12, 12, 0xA92751B6, Fields, -1 };
};

struct GossipNPCOptionDisplayInfoMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4335720, -1, 3, 3, 0x10CC2F94, Fields, -1 };
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
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1308057, -1, 4, 4, 0x99BE0B89, Fields, -1 };
};

struct GroundEffectTextureMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
        { FT_SHORT, 4, false },
        { FT_BYTE, 4, true },
    };

    static constexpr DB2Meta Instance{ 1308499, -1, 4, 4, 0xE77A386D, Fields, -1 };
};

struct GroupFinderActivityMeta
{
    static constexpr DB2MetaField Fields[19] =
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
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 974813, -1, 19, 19, 0x1EE9C586, Fields, -1 };
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
    static constexpr DB2MetaField Fields[13] =
    {
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
        { FT_SHORT, 10, false },
        { FT_INT, 16, false },
        { FT_BYTE, 10, false },
        { FT_INT, 3, true },
    };

    static constexpr DB2Meta Instance{ 996357, 0, 13, 13, 0xC53840D5, Fields, -1 };
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
    static constexpr DB2MetaField Fields[20] =
    {
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, true },
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_BYTE, 5, false },
        { FT_INT, 7, true },
        { FT_INT, 5, true },
        { FT_INT, 5, true },
    };

    static constexpr DB2Meta Instance{ 841626, -1, 20, 20, 0x62FE3B1A, Fields, -1 };
};

struct ItemAppearanceMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 982462, -1, 4, 4, 0x33E7B546, Fields, -1 };
};

struct ItemAppearanceXUiCameraMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1248126, -1, 2, 2, 0x4BEBE0CD, Fields, -1 };
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

struct ItemBonusListLevelDeltaMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_SHORT, 1, true },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1320358, 1, 2, 2, 0x52DF470F, Fields, -1 };
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
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1247926, -1, 3, 2, 0x97EA02AE, Fields, 2 };
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

struct ItemContextPickerEntryMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1405665, -1, 6, 5, 0x70D08611, Fields, 5 };
};

struct ItemCurrencyCostMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 801670, -1, 1, 1, 0xA1F65D6B, Fields, 0 };
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

struct ItemDamageRangedMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_SHORT, 1, false },
        { FT_FLOAT, 7, true },
    };

    static constexpr DB2Meta Instance{ 6156256, -1, 2, 2, 0x56F30531, Fields, -1 };
};

struct ItemDamageThrownMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_SHORT, 1, false },
        { FT_FLOAT, 7, true },
    };

    static constexpr DB2Meta Instance{ 6156257, -1, 2, 2, 0x56F30531, Fields, -1 };
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

struct ItemDamageWandMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_SHORT, 1, false },
        { FT_FLOAT, 7, true },
    };

    static constexpr DB2Meta Instance{ 6156258, -1, 2, 2, 0x56F30531, Fields, -1 };
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
    static constexpr DB2MetaField Fields[9] =
    {
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, true },
        { FT_SHORT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 969941, -1, 9, 8, 0xEB717848, Fields, 8 };
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
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1588911, -1, 2, 2, 0x3FC77064, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 982457, 0, 6, 6, 0x9433A6B1, Fields, 1 };
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

struct ItemRandomPropertiesMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 5, true },
    };

    static constexpr DB2Meta Instance{ 1237441, -1, 2, 2, 0x3FB9ECA3, Fields, -1 };
};

struct ItemRandomSuffixMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 5, true },
        { FT_INT, 5, true },
    };

    static constexpr DB2Meta Instance{ 1237592, -1, 3, 3, 0x4C5DE61E, Fields, -1 };
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

struct ItemReforgeMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_FLOAT, 1, true },
        { FT_SHORT, 1, false },
        { FT_FLOAT, 1, true },
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 5633983, 0, 6, 6, 0xF56D7AF0, Fields, -1 };
};

struct ItemSearchNameMeta
{
    static constexpr DB2MetaField Fields[14] =
    {
        { FT_LONG, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, true },
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

    static constexpr DB2Meta Instance{ 1273408, 2, 14, 14, 0x43F60F2E, Fields, -1 };
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
    static constexpr DB2MetaField Fields[74] =
    {
        { FT_LONG, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, false },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 10, true },
        { FT_INT, 10, true },
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
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
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
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 5, false },
        { FT_SHORT, 5, false },
        { FT_SHORT, 7, true },
        { FT_SHORT, 1, false },
        { FT_SHORT, 10, true },
        { FT_BYTE, 1, false },
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
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, true },
    };

    static constexpr DB2Meta Instance{ 1572924, -1, 74, 74, 0xDF925D47, Fields, -1 };
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

struct ItemUpgradeMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 801687, -1, 5, 5, 0xC034A392, Fields, -1 };
};

struct ItemVisualsMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 5, true },
    };

    static constexpr DB2Meta Instance{ 1343605, -1, 1, 1, 0x4E9F1674, Fields, -1 };
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
    static constexpr DB2MetaField Fields[7] =
    {
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, false },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1344467, 0, 7, 7, 0xBEA0FECD, Fields, 1 };
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
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_STRING, 1, true },
    };

    static constexpr DB2Meta Instance{ 1349056, -1, 1, 1, 0xCA44F886, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1344761, 2, 4, 4, 0x63C870B5, Fields, -1 };
};

struct LFGDungeonExpansionMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1343606, -1, 7, 6, 0x5040432F, Fields, 6 };
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
    static constexpr DB2MetaField Fields[36] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
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
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
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
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 2, true },
    };

    static constexpr DB2Meta Instance{ 1361033, -1, 36, 36, 0xC1EF299A, Fields, -1 };
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

struct LanguageWordsMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 984702, -1, 2, 2, 0x07F670AA, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1135325, 1, 6, 6, 0xD259DA42, Fields, -1 };
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
        { FT_INT, 1, false },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, false },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_FLOAT, 4, true },
        { FT_FLOAT, 4, true },
        { FT_FLOAT, 4, true },
    };

    static constexpr DB2Meta Instance{ 1375580, -1, 46, 46, 0x70C6CD80, Fields, 0 };
};

struct LightParamsMeta
{
    static constexpr DB2MetaField Fields[17] =
    {
        { FT_FLOAT, 3, true },
        { FT_FLOAT, 3, true },
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1334669, 2, 17, 17, 0x51C96BAD, Fields, -1 };
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
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1266541, -1, 3, 3, 0xA28F3422, Fields, -1 };
};

struct LocaleMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 801706, -1, 4, 4, 0xD82F8985, Fields, -1 };
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
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 8, true },
        { FT_SHORT, 8, false },
        { FT_BYTE, 8, false },
        { FT_BYTE, 8, false },
    };

    static constexpr DB2Meta Instance{ 1343608, -1, 4, 4, 0x377BDA0A, Fields, -1 };
};

struct LockTypeMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1284823, 4, 5, 5, 0x9687001F, Fields, -1 };
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
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 4, true },
    };

    static constexpr DB2Meta Instance{ 1587159, 0, 10, 10, 0xFD996676, Fields, -1 };
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
    static constexpr DB2MetaField Fields[23] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
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
        { FT_INT, 1, true },
        { FT_SHORT, 1, true },
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 3, true },
    };

    static constexpr DB2Meta Instance{ 1349477, -1, 23, 23, 0x32401DC5, Fields, -1 };
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
    static constexpr DB2MetaField Fields[12] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
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

    static constexpr DB2Meta Instance{ 1367868, 1, 12, 11, 0xCF621FA3, Fields, 11 };
};

struct MapDifficultyRedirectMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4913557, -1, 3, 2, 0xD5D43631, Fields, 2 };
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
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1294217, -1, 4, 4, 0x72533C7C, Fields, -1 };
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
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1337833, 0, 4, 4, 0x66E0BE4F, Fields, 3 };
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
        { FT_BYTE, 1, true },
    };

    static constexpr DB2Meta Instance{ 1267645, -1, 7, 7, 0xE0CCCA58, Fields, -1 };
};

struct MountMeta
{
    static constexpr DB2MetaField Fields[11] =
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
    };

    static constexpr DB2Meta Instance{ 921760, 3, 11, 11, 0xDB77F653, Fields, -1 };
};

struct MountCapabilityMeta
{
    static constexpr DB2MetaField Fields[10] =
    {
        { FT_INT, 1, false },
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

    static constexpr DB2Meta Instance{ 1114709, 0, 10, 10, 0x6B7A5ED2, Fields, -1 };
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

struct MovieMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1332556, -1, 4, 4, 0x32E3E5C1, Fields, -1 };
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
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1953326, 0, 5, 5, 0x1B85660E, Fields, -1 };
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
    static constexpr DB2MetaField Fields[9] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 2066958, 0, 9, 9, 0x5B0B4934, Fields, -1 };
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
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_FLOAT, 3, true },
        { FT_FLOAT, 3, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2115224, 2, 4, 4, 0xDE4869EE, Fields, -1 };
};

struct OccluderNodeMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2066959, 0, 4, 4, 0x042B9E79, Fields, -1 };
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

struct PathNodeMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 801733, 0, 4, 4, 0x042B9E79, Fields, -1 };
};

struct PathNodePropertyMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 801734, 0, 5, 5, 0x2B340168, Fields, -1 };
};

struct PathPropertyMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 801735, 0, 4, 4, 0x8F9C7C98, Fields, -1 };
};

struct PetLoyaltyMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_STRING, 1, true },
    };

    static constexpr DB2Meta Instance{ 2179604, -1, 1, 1, 0xAD6104C6, Fields, -1 };
};

struct PetPersonalityMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_FLOAT, 3, true },
        { FT_INT, 3, true },
        { FT_FLOAT, 3, true },
        { FT_FLOAT, 8, true },
    };

    static constexpr DB2Meta Instance{ 2179609, -1, 4, 4, 0x4736D6E1, Fields, -1 };
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
    static constexpr DB2MetaField Fields[86] =
    {
        { FT_LONG, 1, true },
        { FT_STRING, 1, true },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
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

    static constexpr DB2Meta Instance{ 1045411, -1, 86, 86, 0x395C1D28, Fields, -1 };
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
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5426706, -1, 2, 2, 0x23ECE2B1, Fields, -1 };
};

struct PlayerDataFlagCharacterMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5426708, -1, 2, 2, 0x23ECE2B1, Fields, -1 };
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

struct ProfessionMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4508544, -1, 2, 2, 0xC2D5BEB1, Fields, -1 };
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

struct PvpTalentMeta
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

    static constexpr DB2Meta Instance{ 1302853, 1, 9, 9, 0x37611B53, Fields, 2 };
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
    static constexpr DB2MetaField Fields[8] =
    {
        { FT_STRING, 1, true },
        { FT_SHORT, 1, true },
        { FT_SHORT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2066871, -1, 8, 8, 0x8F30CD7C, Fields, 5 };
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
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1343388, -1, 6, 6, 0x7ACCDB6D, Fields, -1 };
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
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 973430, -1, 3, 3, 0x5675F41C, Fields, -1 };
};

struct QuestLineXQuestMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 973441, -1, 3, 3, 0x74023255, Fields, 0 };
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
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_STRING, 1, true },
        { FT_BYTE, 1, true },
    };

    static constexpr DB2Meta Instance{ 1134585, -1, 2, 2, 0xADCB489B, Fields, -1 };
};

struct QuestV2Meta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1139443, -1, 1, 1, 0x282AB79A, Fields, -1 };
};

struct QuestV2CliTaskMeta
{
    static constexpr DB2MetaField Fields[26] =
    {
        { FT_LONG, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
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
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 3, true },
        { FT_INT, 3, false },
    };

    static constexpr DB2Meta Instance{ 1028735, 3, 26, 26, 0xCB1396DA, Fields, -1 };
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
        { FT_INT, 10, true },
    };

    static constexpr DB2Meta Instance{ 1139378, -1, 1, 1, 0x7790D0EA, Fields, -1 };
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
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, true },
        { FT_INT, 5, false },
        { FT_INT, 5, false },
        { FT_INT, 5, false },
    };

    static constexpr DB2Meta Instance{ 1310245, -1, 4, 4, 0x5DAD011D, Fields, -1 };
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
    static constexpr DB2MetaField Fields[8] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5662591, -1, 8, 8, 0x30F69B43, Fields, 2 };
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
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1133711, 1, 3, 3, 0x75B20B30, Fields, -1 };
};

struct ResearchProjectMeta
{
    static constexpr DB2MetaField Fields[9] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1134090, 2, 9, 9, 0x5702F5FF, Fields, -1 };
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

struct RulesetItemUpgradeMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 801749, -1, 2, 2, 0xFD873767, Fields, -1 };
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
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_INT, 1, false },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2056369, 0, 5, 5, 0xFD35E147, Fields, -1 };
};

struct ScalingStatDistributionMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 10, true },
        { FT_INT, 10, true },
    };

    static constexpr DB2Meta Instance{ 1141728, -1, 5, 5, 0x68031639, Fields, -1 };
};

struct ScalingStatValuesMeta
{
    static constexpr DB2MetaField Fields[38] =
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
        { FT_INT, 4, true },
        { FT_INT, 4, true },
        { FT_INT, 4, true },
        { FT_INT, 4, true },
        { FT_INT, 4, true },
        { FT_INT, 4, true },
        { FT_INT, 4, true },
        { FT_INT, 4, true },
    };

    static constexpr DB2Meta Instance{ 4719537, -1, 38, 38, 0x8EDC6F8F, Fields, -1 };
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
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
    };

    static constexpr DB2Meta Instance{ 801755, -1, 1, 1, 0xFDBC49B7, Fields, -1 };
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
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1279416, -1, 2, 2, 0xB5DB4956, Fields, -1 };
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
    static constexpr DB2MetaField Fields[13] =
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
    };

    static constexpr DB2Meta Instance{ 1240935, 5, 13, 13, 0x1123150E, Fields, -1 };
};

struct SkillLineAbilityMeta
{
    static constexpr DB2MetaField Fields[16] =
    {
        { FT_LONG, 1, true },
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
        { FT_INT, 2, true },
    };

    static constexpr DB2Meta Instance{ 1266278, 1, 16, 16, 0x738BFEE1, Fields, 2 };
};

struct SkillLineCategoryMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_STRING, 1, true },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 2179610, -1, 2, 2, 0xF61608B2, Fields, -1 };
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
    static constexpr DB2MetaField Fields[8] =
    {
        { FT_LONG, 1, true },
        { FT_SHORT, 1, true },
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
        { FT_SHORT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1240406, -1, 8, 8, 0x78AC2343, Fields, 1 };
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

struct SoundAmbienceMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 2, false },
        { FT_INT, 2, false },
        { FT_INT, 2, false },
    };

    static constexpr DB2Meta Instance{ 1310628, -1, 6, 6, 0x3FBF2710, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1598732, 0, 7, 7, 0x8D9C5CFE, Fields, 1 };
};

struct SoundEmitterPillPointsMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_FLOAT, 3, true },
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1092317, -1, 2, 2, 0xC937A96A, Fields, 1 };
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
    static constexpr DB2MetaField Fields[17] =
    {
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
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

    static constexpr DB2Meta Instance{ 1237434, 0, 17, 17, 0x2EB0F915, Fields, -1 };
};

struct SoundKitAdvancedMeta
{
    static constexpr DB2MetaField Fields[43] =
    {
        { FT_INT, 1, false },
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
    };

    static constexpr DB2Meta Instance{ 1237436, 0, 43, 43, 0xE61A9EE0, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1313612, -1, 4, 3, 0xB0BD8AE3, Fields, 3 };
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
    static constexpr DB2MetaField Fields[8] =
    {
        { FT_INT, 4, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_BYTE, 1, true },
    };

    static constexpr DB2Meta Instance{ 1261603, -1, 8, 8, 0x66EFB31A, Fields, -1 };
};

struct SpellAuraOptionsMeta
{
    static constexpr DB2MetaField Fields[8] =
    {
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
        { FT_INT, 2, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1139952, -1, 8, 7, 0x2760D1A1, Fields, 7 };
};

struct SpellAuraRestrictionsMeta
{
    static constexpr DB2MetaField Fields[10] =
    {
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 981566, -1, 10, 9, 0x6E11DD41, Fields, 9 };
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

struct SpellAuraVisXTalentTabMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_SHORT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5634801, -1, 2, 1, 0x0AD72CC2, Fields, 1 };
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
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_SHORT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1134089, -1, 3, 3, 0x5786BD00, Fields, -1 };
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
        { FT_SHORT, 1, false },
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

    static constexpr DB2Meta Instance{ 1343310, -1, 61, 61, 0x3E3B28F5, Fields, -1 };
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

struct SpellCraftUIMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_BYTE, 1, true },
    };

    static constexpr DB2Meta Instance{ 2620904, -1, 1, 1, 0x5190ECA9, Fields, -1 };
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
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1137828, -1, 3, 3, 0xBE65BD35, Fields, -1 };
};

struct SpellEffectMeta
{
    static constexpr DB2MetaField Fields[29] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
        { FT_SHORT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
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
        { FT_INT, 2, true },
        { FT_INT, 2, false },
        { FT_INT, 4, true },
        { FT_SHORT, 2, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1140088, -1, 29, 28, 0x7F31EDF7, Fields, 28 };
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
    static constexpr DB2MetaField Fields[22] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 3, true },
        { FT_INT, 3, true },
        { FT_INT, 3, true },
        { FT_INT, 3, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 3, true },
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

    static constexpr DB2Meta Instance{ 1362771, -1, 22, 22, 0x876C6732, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1001907, -1, 3, 3, 0x00CA7CE8, Fields, -1 };
};

struct SpellLevelsMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, true },
        { FT_SHORT, 1, true },
        { FT_SHORT, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1140079, -1, 6, 5, 0x98A2247E, Fields, 5 };
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
    static constexpr DB2MetaField Fields[14] =
    {
        { FT_INT, 16, true },
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
    };

    static constexpr DB2Meta Instance{ 1003144, -1, 14, 13, 0x7902DF8B, Fields, 13 };
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

struct SpellPowerMeta
{
    static constexpr DB2MetaField Fields[14] =
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
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 982806, 0, 14, 13, 0xDFC24E8B, Fields, 13 };
};

struct SpellPowerDifficultyMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 982804, 0, 3, 3, 0x5AA22CF5, Fields, -1 };
};

struct SpellProceduralEffectMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_BYTE, 1, true },
        { FT_FLOAT, 4, true },
    };

    static constexpr DB2Meta Instance{ 1140477, 0, 3, 3, 0x6BA7487D, Fields, -1 };
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
        { FT_SHORT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1133525, -1, 4, 3, 0x0DD2CE07, Fields, 3 };
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
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 8, true },
        { FT_SHORT, 8, true },
    };

    static constexpr DB2Meta Instance{ 841946, -1, 3, 3, 0xC65EBB84, Fields, -1 };
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

struct SpellScalingMeta
{
    static constexpr DB2MetaField Fields[10] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_SHORT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1139940, -1, 10, 10, 0x695DA5D3, Fields, -1 };
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
    static constexpr DB2MetaField Fields[11] =
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
        { FT_INT, 4, false },
        { FT_INT, 8, false },
    };

    static constexpr DB2Meta Instance{ 1280618, -1, 11, 11, 0x4424D0DE, Fields, -1 };
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
    static constexpr DB2MetaField Fields[18] =
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
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, true },
    };

    static constexpr DB2Meta Instance{ 897952, -1, 18, 18, 0x224A9435, Fields, -1 };
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
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1094006, -1, 11, 11, 0xDE73DDC8, Fields, -1 };
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
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 897948, -1, 15, 15, 0xE273C4B7, Fields, -1 };
};

struct SpellVisualEventMeta
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

    static constexpr DB2Meta Instance{ 1685317, -1, 9, 8, 0x89263837, Fields, 8 };
};

struct SpellVisualKitMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_FLOAT, 1, true },
        { FT_INT, 2, true },
    };

    static constexpr DB2Meta Instance{ 897949, -1, 5, 5, 0xB4A308CD, Fields, -1 };
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
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, true },
        { FT_SHORT, 1, false },
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
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
        { FT_FLOAT, 1, true },
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 897953, 2, 23, 22, 0xE0FF7EAF, Fields, 22 };
};

struct SpellVisualMissileMeta
{
    static constexpr DB2MetaField Fields[17] =
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
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 897954, 2, 17, 16, 0x8130FDC9, Fields, 16 };
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
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1101657, 0, 13, 12, 0x01147920, Fields, 12 };
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

struct StableSlotPricesMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2179613, -1, 1, 1, 0x31ADFC89, Fields, -1 };
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
    static constexpr DB2MetaField Fields[14] =
    {
        { FT_STRING, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 2, true },
        { FT_INT, 9, true },
        { FT_INT, 3, true },
        { FT_INT, 3, true },
    };

    static constexpr DB2Meta Instance{ 1369062, -1, 14, 14, 0x1EF14415, Fields, -1 };
};

struct TalentTabMeta
{
    static constexpr DB2MetaField Fields[10] =
    {
        { FT_STRING, 1, true },
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 2, true },
    };

    static constexpr DB2Meta Instance{ 2178102, -1, 10, 10, 0xB436F3C7, Fields, -1 };
};

struct TalentTreePrimarySpellsMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5581887, -1, 3, 3, 0x0C4D9DD6, Fields, -1 };
};

struct TaxiNodesMeta
{
    static constexpr DB2MetaField Fields[14] =
    {
        { FT_STRING, 1, true },
        { FT_FLOAT, 3, true },
        { FT_FLOAT, 2, true },
        { FT_FLOAT, 2, true },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 2, true },
    };

    static constexpr DB2Meta Instance{ 1068100, 4, 14, 14, 0xA8EF6D9C, Fields, 5 };
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
        { FT_INT, 1, false },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1000437, 1, 9, 9, 0xD086E620, Fields, 2 };
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
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1310249, -1, 6, 6, 0x980DBE0A, Fields, -1 };
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
    static constexpr DB2MetaField Fields[7] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1301101, 2, 7, 7, 0x2FFC30A4, Fields, -1 };
};

struct TradeSkillItemMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, true },
    };

    static constexpr DB2Meta Instance{ 1329070, -1, 2, 2, 0xD2CEC727, Fields, -1 };
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
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1589454, 0, 2, 2, 0x1CF0A074, Fields, -1 };
};

struct TransmogSetMeta
{
    static constexpr DB2MetaField Fields[10] =
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
        { FT_SHORT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1376213, 1, 10, 10, 0x54EA6CA4, Fields, 7 };
};

struct TransmogSetGroupMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1576116, 1, 2, 2, 0xEBA8ED0E, Fields, -1 };
};

struct TransmogSetItemMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1376212, 0, 4, 4, 0x1330B84D, Fields, 1 };
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
        { FT_INT, 1, false },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 975024, -1, 4, 4, 0x45761395, Fields, -1 };
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

struct UIButtonMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 6237799, -1, 5, 5, 0x88A0B057, Fields, -1 };
};

struct UICinematicIntroInfoMeta
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

    static constexpr DB2Meta Instance{ 6155772, -1, 8, 8, 0x44820FD5, Fields, -1 };
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
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1729547, -1, 4, 4, 0x0A72AD12, Fields, -1 };
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

struct UIMapPinInfoMeta
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

    static constexpr DB2Meta Instance{ 6237800, -1, 6, 6, 0xE8E5C344, Fields, -1 };
};

struct UIScriptedAnimationEffectMeta
{
    static constexpr DB2MetaField Fields[27] =
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

    static constexpr DB2Meta Instance{ 3556601, 0, 27, 27, 0x796691DB, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 3055924, -1, 4, 4, 0xC1702F9E, Fields, -1 };
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
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_SHORT, 1, true },
        { FT_SHORT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1989363, 0, 3, 3, 0xC115A578, Fields, -1 };
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
        { FT_INT, 1, false },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1957206, 1, 14, 14, 0x27E926D0, Fields, 2 };
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
    static constexpr DB2MetaField Fields[9] =
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
    };

    static constexpr DB2Meta Instance{ 2030690, 2, 9, 9, 0x767439DE, Fields, 3 };
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
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1548214, 2, 10, 9, 0xF1E78B36, Fields, 9 };
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
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1548213, 3, 16, 15, 0xEA151443, Fields, 15 };
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

struct UiTextureAtlasMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 897470, -1, 4, 4, 0x1D9B7D22, Fields, -1 };
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
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 5319042, -1, 6, 6, 0xBB5710C0, Fields, -1 };
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

struct UiWidgetMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1983278, -1, 6, 6, 0xD100F6B5, Fields, -1 };
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
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1983640, -1, 4, 3, 0xD581563B, Fields, 3 };
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

struct UiWidgetVisualizationMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_SHORT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1983276, -1, 4, 4, 0x8F0ACA66, Fields, -1 };
};

struct UnitBloodMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 2, false },
        { FT_INT, 2, false },
    };

    static constexpr DB2Meta Instance{ 1284821, -1, 2, 2, 0x324585EB, Fields, -1 };
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
        { FT_SHORT, 1, false },
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

    static constexpr DB2Meta Instance{ 1237753, -1, 16, 16, 0xF11126D1, Fields, -1 };
};

struct VehicleMeta
{
    static constexpr DB2MetaField Fields[19] =
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
        { FT_INT, 1, true },
        { FT_SHORT, 8, false },
        { FT_SHORT, 3, false },
    };

    static constexpr DB2Meta Instance{ 1368621, -1, 19, 19, 0x7CC3210B, Fields, -1 };
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
    static constexpr DB2MetaField Fields[62] =
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

    static constexpr DB2Meta Instance{ 1345447, -1, 62, 62, 0x239D9941, Fields, -1 };
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
        { FT_BYTE, 1, true },
    };

    static constexpr DB2Meta Instance{ 892861, -1, 10, 10, 0xA6472C0E, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1239843, -1, 3, 2, 0xFF75FD57, Fields, 2 };
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
    static constexpr DB2MetaField Fields[22] =
    {
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

    static constexpr DB2Meta Instance{ 1343311, -1, 22, 22, 0x5CF35EA0, Fields, -1 };
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
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 975279, -1, 2, 2, 0x63019FFE, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1134579, 0, 13, 13, 0x7E893204, Fields, 1 };
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

struct WorldStateUIMeta
{
    static constexpr DB2MetaField Fields[17] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_INT, 1, false },
        { FT_SHORT, 1, true },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 3, false },
    };

    static constexpr DB2Meta Instance{ 1343596, 5, 17, 17, 0x1C87F1EC, Fields, 6 };
};

struct WorldStateZoneSoundsMeta
{
    static constexpr DB2MetaField Fields[8] =
    {
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1266941, -1, 8, 8, 0x8CC049D9, Fields, -1 };
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
    static constexpr DB2MetaField Fields[7] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1310253, -1, 7, 7, 0x92275F42, Fields, -1 };
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
