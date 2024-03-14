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

    static constexpr DB2Meta Instance{ 1260179, 3, 15, 15, 0xB885355D, Fields, 11 };
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

    static constexpr DB2Meta Instance{ 1115949, -1, 22, 22, 0xD04C194C, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 5599873, -1, 5, 4, 0x7C64B965, Fields, 4 };
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
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1710672, 0, 8, 8, 0xF8D004E8, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1720145, -1, 5, 4, 0x5DBE9639, Fields, 4 };
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
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1375433, -1, 5, 5, 0x3ACB272E, Fields, -1 };
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
    static constexpr DB2MetaField Fields[18] =
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
    };

    static constexpr DB2Meta Instance{ 1304324, -1, 18, 18, 0xFAE6F96F, Fields, 0 };
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

    static constexpr DB2Meta Instance{ 2140223, -1, 5, 4, 0xDD0613DF, Fields, 4 };
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

    static constexpr DB2Meta Instance{ 1000630, 2, 17, 17, 0x4C7DFFFF, Fields, 11 };
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

    static constexpr DB2Meta Instance{ 1353545, -1, 23, 23, 0x19CA1DC6, Fields, -1 };
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
        { FT_SHORT, 1, true },
        { FT_BYTE, 1, true },
    };

    static constexpr DB2Meta Instance{ 1354401, 2, 16, 16, 0x0D7E8ED2, Fields, 3 };
};

struct AreaTriggerActionSetMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_SHORT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1352378, -1, 1, 1, 0xA5807748, Fields, -1 };
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

struct AreaTriggerSphereMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1315630, -1, 1, 1, 0xAE82194A, Fields, -1 };
};

struct ArenaCcItemMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3849793, 0, 3, 2, 0x9BFC449E, Fields, 2 };
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

    static constexpr DB2Meta Instance{ 1007934, 1, 11, 11, 0x727E7DFA, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1116407, 1, 15, 15, 0xAF622182, Fields, 2 };
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

    static constexpr DB2Meta Instance{ 1116408, 2, 9, 8, 0x14519E02, Fields, 8 };
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

    static constexpr DB2Meta Instance{ 4366440, 2, 9, 8, 0xB60740F7, Fields, 8 };
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

    static constexpr DB2Meta Instance{ 1237437, 2, 8, 8, 0x465D901C, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 841610, -1, 7, 7, 0xF9548A5A, Fields, -1 };
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
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 801576, -1, 3, 2, 0xBA9C2E9B, Fields, 2 };
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

    static constexpr DB2Meta Instance{ 801577, 0, 6, 6, 0x23EE1864, Fields, 1 };
};

struct BattlePetBreedQualityMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_FLOAT, 1, true },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 801578, -1, 2, 2, 0x15F18463, Fields, -1 };
};

struct BattlePetBreedStateMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 801579, -1, 3, 2, 0xFACA6D44, Fields, 2 };
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

    static constexpr DB2Meta Instance{ 1802988, -1, 4, 4, 0x34CDCEE8, Fields, -1 };
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
    static constexpr DB2MetaField Fields[11] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 841622, 2, 11, 11, 0xA8750D81, Fields, -1 };
};

struct BattlePetSpeciesStateMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 801581, -1, 3, 2, 0x474FCD33, Fields, 2 };
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
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_SHORT, 16, true },
    };

    static constexpr DB2Meta Instance{ 1360265, -1, 17, 17, 0xFF326044, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 5549327, 4, 8, 8, 0x6B8D71CD, Fields, -1 };
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
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1367866, -1, 5, 4, 0x234EEB13, Fields, 4 };
};

struct BountySetMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1367865, -1, 2, 2, 0xA7F21AAB, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 841604, 2, 12, 12, 0x4CCDE707, Fields, -1 };
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
        { FT_INT, 1, true },
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

    static constexpr DB2Meta Instance{ 1117696, -1, 16, 15, 0x0196FD7C, Fields, 15 };
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
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 2031607, 2, 6, 6, 0x56BE08F7, Fields, -1 };
};

struct CampaignXConditionMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2031611, -1, 3, 2, 0x22508FD4, Fields, 2 };
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

    static constexpr DB2Meta Instance{ 1592470, 1, 15, 15, 0xCCC000EC, Fields, -1 };
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

struct CharBaseInfoMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
    };

    static constexpr DB2Meta Instance{ 1343386, -1, 2, 2, 0xFE79090E, Fields, -1 };
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
        { FT_SHORT, 1, true },
        { FT_SHORT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1360262, -1, 2, 2, 0xB4407510, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1256914, -1, 10, 10, 0x641ADC4E, Fields, 0 };
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

struct CharSectionsMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_SHORT, 1, true },
        { FT_INT, 3, true },
    };

    static constexpr DB2Meta Instance{ 1365366, -1, 7, 7, 0x15DB31C4, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 972425, -1, 9, 9, 0x8992C4F9, Fields, 0 };
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

    static constexpr DB2Meta Instance{ 972405, -1, 16, 16, 0xCF9B1E26, Fields, -1 };
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
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_LONG, 1, true },
        { FT_INT, 1, false },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
    };

    static constexpr DB2Meta Instance{ 1344281, 1, 5, 5, 0xCA30C801, Fields, -1 };
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
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1345278, 2, 6, 6, 0x117C72BB, Fields, -1 };
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
    static constexpr DB2MetaField Fields[25] =
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

    static constexpr DB2Meta Instance{ 1361031, 5, 25, 25, 0x3F74F8D7, Fields, -1 };
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

struct ChrCustClientChoiceConversionMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3590348, 0, 4, 3, 0x9DA8C109, Fields, 3 };
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
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3526439, 1, 9, 9, 0xDE552A6A, Fields, -1 };
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
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3593032, 0, 6, 6, 0xD11FB7A8, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 3512765, 0, 14, 14, 0xE5D5E59C, Fields, -1 };
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
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 3459652, 0, 3, 3, 0x328DEA6B, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 3384247, 1, 12, 12, 0x26DBFCD5, Fields, 4 };
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

    static constexpr DB2Meta Instance{ 3450453, 2, 9, 9, 0x9B25E739, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 3548976, 0, 10, 9, 0xCB9100A6, Fields, 9 };
};

struct ChrModelTextureTargetMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 3536417, 0, 1, 1, 0x6657BD0A, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1305311, -1, 57, 57, 0x756C30D6, Fields, -1 };
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
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_FLOAT, 3, true },
        { FT_INT, 1, false },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1294214, -1, 4, 4, 0x744B99BC, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 3067644, -1, 3, 2, 0xA73B926A, Fields, 2 };
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
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1661584, -1, 4, 3, 0xFD5BC625, Fields, 3 };
};

struct CommunityIconMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2098645, 0, 3, 3, 0x6737B398, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1962930, 0, 6, 6, 0x7BE7E4B1, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1587153, 2, 7, 7, 0x71B61AEC, Fields, 3 };
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

    static constexpr DB2Meta Instance{ 1260801, -1, 8, 8, 0x9EE67C1B, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 879282, -1, 7, 6, 0xE12CEABF, Fields, 6 };
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

    static constexpr DB2Meta Instance{ 1108759, 0, 25, 25, 0xC99CB5F9, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1264997, 0, 13, 13, 0x03BFCF96, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1351351, -1, 10, 10, 0x67175047, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1131322, -1, 9, 9, 0x6103DDDA, Fields, -1 };
};

struct CreatureModelDataMeta
{
    static constexpr DB2MetaField Fields[28] =
    {
        { FT_FLOAT, 6, true },
        { FT_INT, 1, false },
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
    };

    static constexpr DB2Meta Instance{ 1365368, -1, 28, 28, 0x925EA78B, Fields, -1 };
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

struct CreatureSpellDataMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 4, true },
        { FT_INT, 4, true },
    };

    static constexpr DB2Meta Instance{ 3032554, -1, 2, 2, 0xC3A09A3D, Fields, -1 };
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
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1587158, 0, 3, 2, 0x5CAD3660, Fields, 2 };
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
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1934603, -1, 8, 7, 0x43B60080, Fields, 7 };
};

struct CurrencyTypesMeta
{
    static constexpr DB2MetaField Fields[12] =
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
        { FT_INT, 2, true },
    };

    static constexpr DB2Meta Instance{ 1095531, -1, 12, 12, 0xE814E32E, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1278176, 0, 18, 18, 0xDE20B910, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1122116, -1, 22, 22, 0xA4261431, Fields, -1 };
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
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1352127, -1, 13, 13, 0x3FE0C298, Fields, -1 };
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
    static constexpr DB2MetaField Fields[8] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_SHORT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1347279, 1, 8, 8, 0x737936D8, Fields, 2 };
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

    static constexpr DB2Meta Instance{ 1343313, 2, 8, 8, 0xCCAADB90, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1361972, 3, 18, 18, 0x767B5394, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1343595, 2, 6, 6, 0x4A40A16E, Fields, -1 };
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
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_STRING, 1, true },
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1237638, -1, 3, 3, 0x511B0C62, Fields, 1 };
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

    static constexpr DB2Meta Instance{ 1237639, 1, 4, 4, 0x25F91756, Fields, -1 };
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
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2922072, 0, 2, 2, 0x6F2F4D3B, Fields, -1 };
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
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_FLOAT, 6, true },
        { FT_INT, 1, true },
        { FT_SHORT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1266277, -1, 6, 6, 0xB59CF0B2, Fields, -1 };
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

struct GameObjectsMeta
{
    static constexpr DB2MetaField Fields[12] =
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
        { FT_INT, 8, true },
    };

    static constexpr DB2Meta Instance{ 841620, 3, 12, 12, 0xDFE3AFF5, Fields, 4 };
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

    static constexpr DB2Meta Instance{ 1368021, -1, 4, 4, 0x9A01E238, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 966238, 2, 8, 8, 0x3F8D9F51, Fields, -1 };
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
        { FT_BYTE, 1, false },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 966241, 0, 12, 12, 0x05C17E2A, Fields, 1 };
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

    static constexpr DB2Meta Instance{ 929747, -1, 24, 24, 0xDFE31A36, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 981570, 3, 8, 8, 0x77F0D8C1, Fields, -1 };
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
    static constexpr DB2MetaField Fields[7] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 975304, 1, 7, 7, 0xB264780D, Fields, -1 };
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
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 967961, -1, 3, 2, 0xDA76EC26, Fields, 2 };
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
    static constexpr DB2MetaField Fields[32] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
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
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 949906, 3, 32, 32, 0x4041380E, Fields, -1 };
};

struct GarrFollowerLevelXPMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 970979, -1, 4, 4, 0x0FD039D8, Fields, -1 };
};

struct GarrFollowerQualityMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1027793, -1, 7, 7, 0xEB047C01, Fields, -1 };
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
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1118784, -1, 7, 7, 0x41011281, Fields, -1 };
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
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1572314, 0, 5, 5, 0xBB59F126, Fields, -1 };
};

struct GarrMechanicMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_BYTE, 1, false },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 967963, -1, 3, 3, 0x755DA660, Fields, -1 };
};

struct GarrMechanicSetXMechanicMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1391531, 0, 3, 2, 0xBEF6FEFA, Fields, 2 };
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

    static constexpr DB2Meta Instance{ 967964, 2, 5, 5, 0x51D19412, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 967962, 5, 29, 28, 0x6A1F7660, Fields, 28 };
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
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 967960, 0, 5, 4, 0xFBEB9A41, Fields, 4 };
};

struct GarrMissionXFollowerMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1359096, -1, 3, 2, 0x117BF99B, Fields, 2 };
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

struct GarrTalentMeta
{
    static constexpr DB2MetaField Fields[20] =
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
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_BYTE, 1, true },
    };

    static constexpr DB2Meta Instance{ 1361032, 2, 20, 20, 0x3273A5C3, Fields, 3 };
};

struct GarrTalentTreeMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1361030, -1, 7, 7, 0xC3477D19, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1333161, -1, 5, 5, 0xBC0C747F, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 976037, -1, 6, 6, 0xD9F77F3D, Fields, -1 };
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
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1343604, -1, 3, 3, 0x20BDE912, Fields, -1 };
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
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1345274, -1, 5, 5, 0x768B120C, Fields, -1 };
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

struct GlyphSlotMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1130095, -1, 2, 2, 0xCCC77A3D, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 4278503, -1, 12, 12, 0x30CA59EB, Fields, -1 };
};

struct GossipNPCOptionDisplayInfoMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4335720, -1, 3, 3, 0x243CF578, Fields, -1 };
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
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1308057, -1, 4, 4, 0x81558202, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1308499, -1, 4, 4, 0xF3C0A296, Fields, -1 };
};

struct GroupFinderActivityMeta
{
    static constexpr DB2MetaField Fields[17] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 974813, -1, 17, 17, 0xEA8282BE, Fields, -1 };
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
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 974812, -1, 5, 5, 0x9DE6FF1D, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 996357, 0, 13, 13, 0xF07BB5AA, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 841626, -1, 20, 20, 0xFFF62904, Fields, -1 };
};

struct ItemAppearanceMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 982462, -1, 4, 4, 0xB7D37BC9, Fields, -1 };
};

struct ItemAppearanceXUiCameraMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1248126, -1, 2, 2, 0x7E42B0D5, Fields, -1 };
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

struct ItemBonusListLevelDeltaMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_SHORT, 1, true },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1320358, 1, 2, 2, 0xC6EA2151, Fields, -1 };
};

struct ItemBonusTreeNodeMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_BYTE, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 987134, -1, 5, 4, 0xB396FA9A, Fields, 4 };
};

struct ItemChildEquipmentMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1247926, -1, 3, 2, 0x1360F4BC, Fields, 2 };
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

    static constexpr DB2Meta Instance{ 1405665, -1, 6, 5, 0xA71A3E17, Fields, 5 };
};

struct ItemCurrencyCostMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 801670, -1, 1, 1, 0x711019C0, Fields, 0 };
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

    static constexpr DB2Meta Instance{ 969941, -1, 9, 8, 0xF2A2E644, Fields, 8 };
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
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1588911, -1, 2, 2, 0xDAC5C754, Fields, -1 };
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

struct ItemModifiedAppearanceMeta
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

    static constexpr DB2Meta Instance{ 982457, 0, 6, 6, 0xF6BAD95D, Fields, 1 };
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

struct ItemRandomPropertiesMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_STRING, 1, true },
        { FT_SHORT, 5, true },
    };

    static constexpr DB2Meta Instance{ 1237441, -1, 2, 2, 0x0D2C3577, Fields, -1 };
};

struct ItemRandomSuffixMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 5, true },
        { FT_INT, 5, true },
    };

    static constexpr DB2Meta Instance{ 1237592, -1, 3, 3, 0x07FFE191, Fields, -1 };
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

struct ItemReforgeMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
        { FT_FLOAT, 1, true },
        { FT_SHORT, 1, false },
        { FT_FLOAT, 1, true },
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 5633983, 0, 6, 6, 0xF3A870E9, Fields, -1 };
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
        { FT_INT, 4, true },
    };

    static constexpr DB2Meta Instance{ 1273408, 2, 14, 14, 0xA0BCA534, Fields, -1 };
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
        { FT_BYTE, 10, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, true },
    };

    static constexpr DB2Meta Instance{ 1572924, -1, 74, 74, 0xE3090D23, Fields, -1 };
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
    static constexpr DB2MetaField Fields[10] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, true },
        { FT_SHORT, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
    };

    static constexpr DB2Meta Instance{ 1261604, -1, 10, 10, 0xD3EC5442, Fields, 2 };
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

    static constexpr DB2Meta Instance{ 801687, -1, 5, 5, 0x6654AC08, Fields, -1 };
};

struct ItemVisualsMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 5, true },
    };

    static constexpr DB2Meta Instance{ 1343605, -1, 1, 1, 0xB1112D93, Fields, -1 };
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

struct JournalEncounterMeta
{
    static constexpr DB2MetaField Fields[10] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_FLOAT, 2, true },
        { FT_SHORT, 1, false },
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_BYTE, 1, true },
    };

    static constexpr DB2Meta Instance{ 1240336, -1, 10, 10, 0x6C77939B, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1344467, 0, 6, 6, 0x13C68F9B, Fields, 1 };
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
    static constexpr DB2MetaField Fields[10] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1237438, 2, 10, 10, 0xF4F48AF6, Fields, -1 };
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
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_STRING, 1, true },
    };

    static constexpr DB2Meta Instance{ 1349056, -1, 1, 1, 0x7C81683B, Fields, -1 };
};

struct JournalTierXInstanceMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1285009, -1, 3, 3, 0x003E6589, Fields, 0 };
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

    static constexpr DB2Meta Instance{ 1344761, 2, 4, 4, 0x264D2A97, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1343606, -1, 7, 6, 0x6EA3052A, Fields, 6 };
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
    static constexpr DB2MetaField Fields[33] =
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
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 2, true },
    };

    static constexpr DB2Meta Instance{ 1361033, -1, 33, 33, 0x42F904E6, Fields, -1 };
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

struct LanguageWordsMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 984702, -1, 2, 2, 0x3FD82B89, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1135325, 1, 6, 6, 0xE73E1D81, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1375580, -1, 46, 46, 0x5A08CEBB, Fields, 0 };
};

struct LightParamsMeta
{
    static constexpr DB2MetaField Fields[12] =
    {
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
    };

    static constexpr DB2Meta Instance{ 1334669, 1, 12, 12, 0xFA62F9B6, Fields, -1 };
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
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1266541, -1, 3, 3, 0x2F4F6F9D, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 801706, -1, 4, 4, 0xD7B62A14, Fields, -1 };
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
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 8, true },
        { FT_SHORT, 8, false },
        { FT_BYTE, 8, false },
        { FT_BYTE, 8, false },
    };

    static constexpr DB2Meta Instance{ 1343608, -1, 4, 4, 0x82DBCD97, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1284823, 4, 5, 5, 0x2C772BE0, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1587159, 0, 10, 10, 0x2191EBA2, Fields, -1 };
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
    static constexpr DB2MetaField Fields[22] =
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
        { FT_INT, 3, true },
    };

    static constexpr DB2Meta Instance{ 1349477, -1, 22, 22, 0xEE526FA5, Fields, -1 };
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
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1367868, -1, 10, 9, 0x1D0486C0, Fields, 9 };
};

struct MapDifficultyRedirectMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4913557, -1, 3, 2, 0xAE1892F2, Fields, 2 };
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
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1337833, 0, 4, 4, 0xDFBC2A88, Fields, 3 };
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
        { FT_BYTE, 1, true },
    };

    static constexpr DB2Meta Instance{ 1267645, -1, 7, 7, 0x36C062E7, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 921760, 3, 11, 11, 0x8756BD04, Fields, -1 };
};

struct MountCapabilityMeta
{
    static constexpr DB2MetaField Fields[8] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_SHORT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1114709, 0, 8, 8, 0x675B432D, Fields, -1 };
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

struct MovieMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1332556, -1, 4, 4, 0xA3A2FAF5, Fields, -1 };
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
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2123783, -1, 4, 3, 0x0725CCB8, Fields, 3 };
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
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1953326, 0, 5, 5, 0x6CA01D0C, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 2066958, 0, 9, 9, 0x2C56A558, Fields, -1 };
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
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_FLOAT, 3, true },
        { FT_FLOAT, 3, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2115224, 2, 4, 4, 0xCDD9AA68, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 2066959, 0, 4, 4, 0x21B91AA8, Fields, -1 };
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

struct PathNodeMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 801733, 0, 4, 4, 0x21B91AA8, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 801734, 0, 5, 5, 0x4C02E642, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 801735, 0, 4, 4, 0xC4C11DF6, Fields, -1 };
};

struct PetLoyaltyMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_STRING, 1, true },
    };

    static constexpr DB2Meta Instance{ 2179604, -1, 1, 1, 0x25D58CFB, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 2179609, -1, 4, 4, 0xA6AC5A8A, Fields, -1 };
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
    static constexpr DB2MetaField Fields[81] =
    {
        { FT_LONG, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
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
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
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
        { FT_BYTE, 1, false },
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
        { FT_SHORT, 4, false },
        { FT_SHORT, 4, false },
        { FT_SHORT, 4, false },
        { FT_INT, 3, false },
        { FT_BYTE, 3, false },
        { FT_INT, 4, false },
        { FT_INT, 4, false },
        { FT_INT, 4, false },
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
    };

    static constexpr DB2Meta Instance{ 1045411, 2, 81, 81, 0xD1764989, Fields, -1 };
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
    static constexpr DB2MetaField Fields[12] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_STRING_NOT_LOCALIZED, 1, true },
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

    static constexpr DB2Meta Instance{ 1266022, -1, 12, 12, 0xA1F55F15, Fields, -1 };
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

struct ProfessionMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 4508544, -1, 2, 2, 0x64EEACF2, Fields, -1 };
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

struct PvpRewardMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1307154, -1, 3, 3, 0xBB6DB3D9, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1302853, 1, 9, 9, 0x13ABD6C8, Fields, 2 };
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

    static constexpr DB2Meta Instance{ 2066871, -1, 8, 8, 0xF5A42A7C, Fields, 5 };
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
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1343388, -1, 6, 6, 0x96F7DC0F, Fields, -1 };
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
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 973430, -1, 3, 3, 0x4B1C4A54, Fields, -1 };
};

struct QuestLineXQuestMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 973441, -1, 3, 3, 0x83C5B32B, Fields, 0 };
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
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1251960, -1, 8, 7, 0x0CF5606A, Fields, 7 };
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
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1139443, -1, 1, 1, 0xBB71B2AE, Fields, -1 };
};

struct QuestV2CliTaskMeta
{
    static constexpr DB2MetaField Fields[24] =
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
        { FT_INT, 1, false },
        { FT_INT, 1, false },
        { FT_INT, 3, false },
    };

    static constexpr DB2Meta Instance{ 1028735, 3, 24, 24, 0x2C9FD7F0, Fields, -1 };
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
        { FT_INT, 10, true },
    };

    static constexpr DB2Meta Instance{ 1139378, -1, 1, 1, 0xEF69DA71, Fields, -1 };
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
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, true },
        { FT_INT, 5, false },
        { FT_INT, 5, false },
        { FT_INT, 5, false },
    };

    static constexpr DB2Meta Instance{ 1310245, -1, 4, 4, 0x16C5E260, Fields, -1 };
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
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1133711, 1, 3, 3, 0xE0BBD6D8, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1134090, 2, 9, 9, 0x4B169F6A, Fields, -1 };
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

struct RulesetItemUpgradeMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 801749, -1, 2, 2, 0x6C34B5E6, Fields, -1 };
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
    static constexpr DB2MetaField Fields[5] =
    {
        { FT_INT, 1, false },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2056369, 0, 5, 5, 0xC35ECCDC, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1141728, -1, 5, 5, 0x2F06EE49, Fields, -1 };
};

struct ScalingStatValuesMeta
{
    static constexpr DB2MetaField Fields[23] =
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
    };

    static constexpr DB2Meta Instance{ 4719537, -1, 23, 23, 0x7037AEF9, Fields, -1 };
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
        { FT_INT, 1, false },
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1132761, -1, 11, 11, 0xFAB5BD3A, Fields, 2 };
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
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
    };

    static constexpr DB2Meta Instance{ 801755, -1, 1, 1, 0x490A170A, Fields, -1 };
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
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1240935, 5, 13, 13, 0x5CB7F941, Fields, -1 };
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
        { FT_BYTE, 1, true },
        { FT_SHORT, 1, true },
        { FT_SHORT, 1, true },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_SHORT, 1, true },
        { FT_SHORT, 1, true },
        { FT_SHORT, 1, true },
        { FT_INT, 2, true },
    };

    static constexpr DB2Meta Instance{ 1266278, 1, 16, 16, 0x5DEA6909, Fields, 2 };
};

struct SkillLineCategoryMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_STRING, 1, true },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 2179610, -1, 2, 2, 0x5807D28B, Fields, -1 };
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
    static constexpr DB2MetaField Fields[8] =
    {
        { FT_LONG, 1, true },
        { FT_SHORT, 1, true },
        { FT_INT, 1, true },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
        { FT_SHORT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1240406, -1, 8, 8, 0x97B1C484, Fields, 1 };
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

    static constexpr DB2Meta Instance{ 1310628, -1, 6, 6, 0x69BCDC3F, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1598732, 0, 7, 7, 0x484FEC66, Fields, 1 };
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
    static constexpr DB2MetaField Fields[17] =
    {
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
        { FT_FLOAT, 1, true },
        { FT_SHORT, 1, false },
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

    static constexpr DB2Meta Instance{ 1237434, 0, 17, 17, 0x69EC2D22, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1237436, 0, 43, 43, 0x9E67FFA7, Fields, -1 };
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

struct SoundKitNameMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
    };

    static constexpr DB2Meta Instance{ 1665033, -1, 1, 1, 0x0F422F8A, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1313612, -1, 4, 3, 0x15B725A7, Fields, 3 };
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

    static constexpr DB2Meta Instance{ 1261603, -1, 8, 8, 0x55B33B2E, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1139952, -1, 8, 7, 0xB247D703, Fields, 7 };
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

    static constexpr DB2Meta Instance{ 981566, -1, 10, 9, 0x98916922, Fields, 9 };
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

struct SpellAuraVisXTalentTabMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_SHORT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5634801, -1, 2, 1, 0xBE816056, Fields, 1 };
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
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_SHORT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1134089, -1, 3, 3, 0x11B57305, Fields, -1 };
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
        { FT_SHORT, 1, false },
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

    static constexpr DB2Meta Instance{ 1343310, -1, 60, 60, 0xD76BE290, Fields, -1 };
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

struct SpellCraftUIMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_BYTE, 1, true },
    };

    static constexpr DB2Meta Instance{ 2620904, -1, 1, 1, 0xC232367A, Fields, -1 };
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
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1137828, -1, 3, 3, 0x5ECABAFD, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1140088, -1, 29, 28, 0x6B64DD7A, Fields, 28 };
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

    static constexpr DB2Meta Instance{ 1362771, -1, 22, 22, 0x31CF18E7, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1001907, -1, 3, 3, 0x6E612037, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1140079, -1, 6, 5, 0x1045DB60, Fields, 5 };
};

struct SpellMechanicMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_STRING, 1, true },
    };

    static constexpr DB2Meta Instance{ 1014438, -1, 1, 1, 0x4E0C4A43, Fields, -1 };
};

struct SpellMiscMeta
{
    static constexpr DB2MetaField Fields[14] =
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
    };

    static constexpr DB2Meta Instance{ 1003144, -1, 14, 13, 0x316AB86A, Fields, 13 };
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

    static constexpr DB2Meta Instance{ 982806, 0, 14, 13, 0xD61F566E, Fields, 13 };
};

struct SpellPowerDifficultyMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 982804, 0, 3, 3, 0x8CDFB01A, Fields, -1 };
};

struct SpellProceduralEffectMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_BYTE, 1, true },
        { FT_FLOAT, 4, true },
    };

    static constexpr DB2Meta Instance{ 1140477, 0, 3, 3, 0x443F1831, Fields, -1 };
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
        { FT_SHORT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1133525, -1, 4, 3, 0x4BFCB147, Fields, 3 };
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
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 8, true },
        { FT_SHORT, 8, true },
    };

    static constexpr DB2Meta Instance{ 841946, -1, 3, 3, 0xF0E58683, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1139940, -1, 10, 10, 0x0308E06A, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1280618, -1, 11, 11, 0xF8FD06AC, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 897952, -1, 18, 18, 0xBAA2E3FD, Fields, -1 };
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
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1094006, -1, 11, 11, 0x83A4A24B, Fields, -1 };
};

struct SpellVisualEffectNameMeta
{
    static constexpr DB2MetaField Fields[14] =
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
    };

    static constexpr DB2Meta Instance{ 897948, -1, 14, 14, 0x6F64D3DD, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1685317, -1, 9, 8, 0x54DB405C, Fields, 8 };
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

    static constexpr DB2Meta Instance{ 897949, -1, 5, 5, 0xB08DAE10, Fields, -1 };
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
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 897953, 2, 22, 21, 0x7025F954, Fields, 21 };
};

struct SpellVisualMissileMeta
{
    static constexpr DB2MetaField Fields[16] =
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
    };

    static constexpr DB2Meta Instance{ 897954, 2, 16, 15, 0xC15741C9, Fields, 15 };
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

    static constexpr DB2Meta Instance{ 1101657, 0, 13, 12, 0x83B098CF, Fields, 12 };
};

struct StableSlotPricesMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 2179613, -1, 1, 1, 0x032886D2, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1369062, -1, 14, 14, 0x8384964D, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 2178102, -1, 10, 10, 0xC1B1F32D, Fields, -1 };
};

struct TalentTreePrimarySpellsMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 5581887, -1, 3, 3, 0xDDF6669B, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1068100, 4, 14, 14, 0x609F20BF, Fields, 5 };
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
        { FT_INT, 1, false },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1000437, 1, 9, 9, 0xC38748B1, Fields, 2 };
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
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1310249, -1, 6, 6, 0xA0C11CA4, Fields, -1 };
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
    static constexpr DB2MetaField Fields[7] =
    {
        { FT_STRING, 1, true },
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, false },
        { FT_SHORT, 1, true },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1301101, 2, 7, 7, 0xDF09A044, Fields, -1 };
};

struct TradeSkillItemMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_SHORT, 1, false },
        { FT_BYTE, 1, true },
    };

    static constexpr DB2Meta Instance{ 1329070, -1, 2, 2, 0xD10A2270, Fields, -1 };
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

struct TransmogHolidayMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1589454, 0, 2, 2, 0xB1AA7BE2, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1376213, 1, 10, 10, 0x12BC4D7F, Fields, 7 };
};

struct TransmogSetGroupMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_STRING, 1, true },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1576116, 1, 2, 2, 0x0FBA68B8, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1376212, 0, 4, 4, 0xEF36A899, Fields, 1 };
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
        { FT_INT, 1, false },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 975024, -1, 4, 4, 0xF5E431DA, Fields, -1 };
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

struct UIExpansionDisplayInfoMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, false },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 1729547, -1, 4, 4, 0x85273A08, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 3556601, 0, 27, 27, 0xC7E169C1, Fields, -1 };
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
    static constexpr DB2MetaField Fields[3] =
    {
        { FT_INT, 1, false },
        { FT_SHORT, 1, true },
        { FT_SHORT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1989363, 0, 3, 3, 0x880425D9, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1957206, 1, 14, 14, 0x8B3C7011, Fields, 2 };
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

    static constexpr DB2Meta Instance{ 2030690, 2, 9, 9, 0xAB3E538F, Fields, 3 };
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
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 1548215, -1, 2, 2, 0xB25F82C0, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1548214, 2, 10, 9, 0xA3270DEE, Fields, 9 };
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

    static constexpr DB2Meta Instance{ 1548213, 3, 16, 15, 0x10F8A956, Fields, 15 };
};

struct UiPartyPoseMeta
{
    static constexpr DB2MetaField Fields[11] =
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
    };

    static constexpr DB2Meta Instance{ 1993323, 2, 11, 10, 0x4F7568D2, Fields, 10 };
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

    static constexpr DB2Meta Instance{ 897470, -1, 4, 4, 0xA63B3475, Fields, -1 };
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
    static constexpr DB2MetaField Fields[6] =
    {
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta Instance{ 5319042, -1, 6, 6, 0xBAAE8FF5, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1983278, -1, 6, 6, 0xFC00C13E, Fields, -1 };
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
        { FT_SHORT, 1, false },
        { FT_INT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1983640, -1, 4, 3, 0x7664767F, Fields, 3 };
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

struct UiWidgetVisualizationMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { FT_BYTE, 1, false },
        { FT_INT, 1, true },
        { FT_INT, 1, true },
        { FT_SHORT, 1, true },
    };

    static constexpr DB2Meta Instance{ 1983276, -1, 4, 4, 0x59CF6C63, Fields, -1 };
};

struct UnitBloodMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { FT_INT, 2, false },
        { FT_INT, 2, false },
    };

    static constexpr DB2Meta Instance{ 1284821, -1, 2, 2, 0x6CC62733, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1237753, -1, 16, 16, 0x6D90F2FD, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1368621, -1, 19, 19, 0x57BE2AC6, Fields, -1 };
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
    static constexpr DB2MetaField Fields[62] =
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

    static constexpr DB2Meta Instance{ 1345447, -1, 62, 62, 0x0BE4B80B, Fields, -1 };
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
    static constexpr DB2MetaField Fields[9] =
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
    };

    static constexpr DB2Meta Instance{ 892861, -1, 9, 9, 0x329D6DFF, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1239843, -1, 3, 2, 0x71C02291, Fields, 2 };
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

    static constexpr DB2Meta Instance{ 1343311, -1, 22, 22, 0x64BAFAAB, Fields, -1 };
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
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta Instance{ 975279, -1, 2, 2, 0x7C32D58B, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1343312, -1, 6, 6, 0x6732C81D, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1134579, 0, 13, 13, 0xD73DE991, Fields, 1 };
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

struct WorldStateExpressionMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
    };

    static constexpr DB2Meta Instance{ 1332558, -1, 1, 1, 0x6695F131, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1343596, 5, 17, 17, 0x19965256, Fields, 6 };
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

    static constexpr DB2Meta Instance{ 1266941, -1, 8, 8, 0x91F574B9, Fields, -1 };
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

    static constexpr DB2Meta Instance{ 1310253, -1, 7, 7, 0x1C1C0231, Fields, -1 };
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
