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

#ifndef TRINITYCORE_DB2_METADATA_H
#define TRINITYCORE_DB2_METADATA_H

#include "DB2Meta.h"

struct AccountStoreCategoryMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 6220124,
        .IndexField         = 1,
        .ParentIndexField   = 2,
        .FieldCount         = 6,
        .FileFieldCount     = 6,
        .LayoutHash         = 0xE78C9607,
        .Fields             = Fields
    };
};

struct AccountStoreItemMeta
{
    static constexpr DB2MetaField Fields[17] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 6197817,
        .IndexField         = 2,
        .ParentIndexField   = 3,
        .FieldCount         = 17,
        .FileFieldCount     = 17,
        .LayoutHash         = 0x818F4DA6,
        .Fields             = Fields
    };
};

struct AchievementMeta
{
    static constexpr DB2MetaField Fields[15] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1260179,
        .IndexField         = 3,
        .ParentIndexField   = 11,
        .FieldCount         = 15,
        .FileFieldCount     = 15,
        .LayoutHash         = 0x0183051B,
        .Fields             = Fields
    };
};

struct Achievement_CategoryMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1324299,
        .IndexField         = 1,
        .ParentIndexField   = 3,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0x67B2B4BD,
        .Fields             = Fields
    };
};

struct ActionBarGroupMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 4572795,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 1,
        .FileFieldCount     = 1,
        .LayoutHash         = 0xBBBE80CE,
        .Fields             = Fields
    };
};

struct ActionBarGroupEntryMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 4572797,
        .IndexField         = -1,
        .ParentIndexField   = 4,
        .FieldCount         = 5,
        .FileFieldCount     = 4,
        .LayoutHash         = 0xF28AF796,
        .Fields             = Fields
    };
};

struct AdventureJournalMeta
{
    static constexpr DB2MetaField Fields[22] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  2, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  2, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1115949,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 22,
        .FileFieldCount     = 22,
        .LayoutHash         = 0xDE04598C,
        .Fields             = Fields
    };
};

struct AdventureJournalItemMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 5599873,
        .IndexField         = -1,
        .ParentIndexField   = 4,
        .FieldCount         = 5,
        .FileFieldCount     = 4,
        .LayoutHash         = 0x2A065EC6,
        .Fields             = Fields
    };
};

struct AdventureMapPOIMeta
{
    static constexpr DB2MetaField Fields[12] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  2, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1267070,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 12,
        .FileFieldCount     = 12,
        .LayoutHash         = 0x8672E9D5,
        .Fields             = Fields
    };
};

struct AlliedRaceMeta
{
    static constexpr DB2MetaField Fields[8] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1710672,
        .IndexField         = 0,
        .ParentIndexField   = -1,
        .FieldCount         = 8,
        .FileFieldCount     = 8,
        .LayoutHash         = 0xD60FC8BF,
        .Fields             = Fields
    };
};

struct AlliedRaceRacialAbilityMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1720145,
        .IndexField         = -1,
        .ParentIndexField   = 4,
        .FieldCount         = 5,
        .FileFieldCount     = 4,
        .LayoutHash         = 0x0F2AA8B5,
        .Fields             = Fields
    };
};

struct AltMinimapMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 5156218,
        .IndexField         = 0,
        .ParentIndexField   = -1,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0xDDEF5F2D,
        .Fields             = Fields
    };
};

struct AltMinimapFiledataMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 5156219,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0xBF516172,
        .Fields             = Fields
    };
};

struct AltMinimapWMOMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 5156220,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0xC6594274,
        .Fields             = Fields
    };
};

struct AnimKitMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1304323,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0xDA4C91AF,
        .Fields             = Fields
    };
};

struct AnimKitBoneSetMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1375433,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 5,
        .FileFieldCount     = 5,
        .LayoutHash         = 0x94F5DA04,
        .Fields             = Fields
    };
};

struct AnimKitBoneSetAliasMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1266937,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x19A6986C,
        .Fields             = Fields
    };
};

struct AnimKitConfigMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1300872,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 1,
        .FileFieldCount     = 1,
        .LayoutHash         = 0x140718EF,
        .Fields             = Fields
    };
};

struct AnimKitConfigBoneSetMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1300873,
        .IndexField         = -1,
        .ParentIndexField   = 2,
        .FieldCount         = 3,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x482E3ED3,
        .Fields             = Fields
    };
};

struct AnimKitPriorityMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1266540,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 1,
        .FileFieldCount     = 1,
        .LayoutHash         = 0xCCF889D8,
        .Fields             = Fields
    };
};

struct AnimKitReplacementMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1559807,
        .IndexField         = 0,
        .ParentIndexField   = 4,
        .FieldCount         = 5,
        .FileFieldCount     = 4,
        .LayoutHash         = 0xD9A65034,
        .Fields             = Fields
    };
};

struct AnimKitSegmentMeta
{
    static constexpr DB2MetaField Fields[18] =
    {
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1304324,
        .IndexField         = -1,
        .ParentIndexField   = 0,
        .FieldCount         = 18,
        .FileFieldCount     = 18,
        .LayoutHash         = 0x748C966C,
        .Fields             = Fields
    };
};

struct AnimReplacementMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1301100,
        .IndexField         = 0,
        .ParentIndexField   = 4,
        .FieldCount         = 5,
        .FileFieldCount     = 4,
        .LayoutHash         = 0x61B149CC,
        .Fields             = Fields
    };
};

struct AnimReplacementSetMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1284817,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 1,
        .FileFieldCount     = 1,
        .LayoutHash         = 0x7C047695,
        .Fields             = Fields
    };
};

struct AnimaCableMeta
{
    static constexpr DB2MetaField Fields[35] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 3286805,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 35,
        .FileFieldCount     = 35,
        .LayoutHash         = 0xC7843A94,
        .Fields             = Fields
    };
};

struct AnimaCylinderMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 3286804,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 7,
        .FileFieldCount     = 7,
        .LayoutHash         = 0x351564A7,
        .Fields             = Fields
    };
};

struct AnimaMaterialMeta
{
    static constexpr DB2MetaField Fields[31] =
    {
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  3, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 3153990,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 31,
        .FileFieldCount     = 31,
        .LayoutHash         = 0xF1514DA2,
        .Fields             = Fields
    };
};

struct AnimationDataMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  2, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1375431,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0x18A959FC,
        .Fields             = Fields
    };
};

struct AoiBoxMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_FLOAT,                .ArraySize =  6, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 2140223,
        .IndexField         = -1,
        .ParentIndexField   = 4,
        .FieldCount         = 5,
        .FileFieldCount     = 4,
        .LayoutHash         = 0xBDA8526F,
        .Fields             = Fields
    };
};

struct AreaConditionalDataMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 2123730,
        .IndexField         = 1,
        .ParentIndexField   = 4,
        .FieldCount         = 5,
        .FileFieldCount     = 4,
        .LayoutHash         = 0xFFC38678,
        .Fields             = Fields
    };
};

struct AreaFarClipOverrideMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1537162,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0x56BEE3FC,
        .Fields             = Fields
    };
};

struct AreaGroupMemberMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1093406,
        .IndexField         = -1,
        .ParentIndexField   = 1,
        .FieldCount         = 2,
        .FileFieldCount     = 1,
        .LayoutHash         = 0x6746D145,
        .Fields             = Fields
    };
};

struct AreaPOIMeta
{
    static constexpr DB2MetaField Fields[18] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  3, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1000630,
        .IndexField         = 2,
        .ParentIndexField   = 12,
        .FieldCount         = 18,
        .FileFieldCount     = 18,
        .LayoutHash         = 0x91335BF1,
        .Fields             = Fields
    };
};

struct AreaPOIStateMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1000631,
        .IndexField         = -1,
        .ParentIndexField   = 4,
        .FieldCount         = 5,
        .FileFieldCount     = 4,
        .LayoutHash         = 0x60943110,
        .Fields             = Fields
    };
};

struct AreaTableMeta
{
    static constexpr DB2MetaField Fields[23] =
    {
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  2, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  4, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1353545,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 23,
        .FileFieldCount     = 23,
        .LayoutHash         = 0x705C911D,
        .Fields             = Fields
    };
};

struct AreaTriggerMeta
{
    static constexpr DB2MetaField Fields[16] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  3, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1354401,
        .IndexField         = 2,
        .ParentIndexField   = 3,
        .FieldCount         = 16,
        .FileFieldCount     = 16,
        .LayoutHash         = 0xB4ACA6C2,
        .Fields             = Fields
    };
};

struct AreaTriggerActionSetMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1352378,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 1,
        .FileFieldCount     = 1,
        .LayoutHash         = 0x6942F9DD,
        .Fields             = Fields
    };
};

struct AreaTriggerBoxMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { .Type = FT_FLOAT,                .ArraySize =  3, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1332554,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 1,
        .FileFieldCount     = 1,
        .LayoutHash         = 0xC934FE5D,
        .Fields             = Fields
    };
};

struct AreaTriggerCreatePropertiesMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1937227,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0xAEDFD657,
        .Fields             = Fields
    };
};

struct AreaTriggerCylinderMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1121943,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0xC54F3688,
        .Fields             = Fields
    };
};

struct AreaTriggerSphereMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1315630,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 1,
        .FileFieldCount     = 1,
        .LayoutHash         = 0xB851EBF6,
        .Fields             = Fields
    };
};

struct ArenaCcItemMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 3849793,
        .IndexField         = 0,
        .ParentIndexField   = 2,
        .FieldCount         = 3,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x4C5721FD,
        .Fields             = Fields
    };
};

struct ArenaTrackedItemMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 5226140,
        .IndexField         = -1,
        .ParentIndexField   = 1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0xFB956EB0,
        .Fields             = Fields
    };
};

struct ArmorLocationMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1284818,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 5,
        .FileFieldCount     = 5,
        .LayoutHash         = 0xFB67352F,
        .Fields             = Fields
    };
};

struct ArtifactMeta
{
    static constexpr DB2MetaField Fields[11] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1007934,
        .IndexField         = 1,
        .ParentIndexField   = -1,
        .FieldCount         = 11,
        .FileFieldCount     = 11,
        .LayoutHash         = 0x9284635D,
        .Fields             = Fields
    };
};

struct ArtifactAppearanceMeta
{
    static constexpr DB2MetaField Fields[16] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1116407,
        .IndexField         = 1,
        .ParentIndexField   = 2,
        .FieldCount         = 16,
        .FileFieldCount     = 16,
        .LayoutHash         = 0x4E8E48F3,
        .Fields             = Fields
    };
};

struct ArtifactAppearanceSetMeta
{
    static constexpr DB2MetaField Fields[9] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1116408,
        .IndexField         = 2,
        .ParentIndexField   = 8,
        .FieldCount         = 9,
        .FileFieldCount     = 8,
        .LayoutHash         = 0x0F103A17,
        .Fields             = Fields
    };
};

struct ArtifactCategoryMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1376210,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0xEE30ED65,
        .Fields             = Fields
    };
};

struct ArtifactItemToTransmogMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 2029780,
        .IndexField         = -1,
        .ParentIndexField   = 0,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0x847F68D6,
        .Fields             = Fields
    };
};

struct ArtifactPowerMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { .Type = FT_FLOAT,                .ArraySize =  2, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1007937,
        .IndexField         = 1,
        .ParentIndexField   = 2,
        .FieldCount         = 7,
        .FileFieldCount     = 7,
        .LayoutHash         = 0xEAA59D67,
        .Fields             = Fields
    };
};

struct ArtifactPowerLinkMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1133731,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x6929FE1C,
        .Fields             = Fields
    };
};

struct ArtifactPowerPickerMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1597467,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 1,
        .FileFieldCount     = 1,
        .LayoutHash         = 0x39566E31,
        .Fields             = Fields
    };
};

struct ArtifactPowerRankMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1261405,
        .IndexField         = -1,
        .ParentIndexField   = 4,
        .FieldCount         = 5,
        .FileFieldCount     = 4,
        .LayoutHash         = 0x39F69979,
        .Fields             = Fields
    };
};

struct ArtifactQuestXPMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { .Type = FT_INT,                  .ArraySize = 10, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1036203,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 1,
        .FileFieldCount     = 1,
        .LayoutHash         = 0x01D6219A,
        .Fields             = Fields
    };
};

struct ArtifactTierMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1600114,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 5,
        .FileFieldCount     = 5,
        .LayoutHash         = 0xA9FC62B2,
        .Fields             = Fields
    };
};

struct ArtifactUnlockMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1094540,
        .IndexField         = -1,
        .ParentIndexField   = 4,
        .FieldCount         = 5,
        .FileFieldCount     = 4,
        .LayoutHash         = 0xA71AB31F,
        .Fields             = Fields
    };
};

struct AuctionHouseMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1237439,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0x9D007DB2,
        .Fields             = Fields
    };
};

struct AuctionHouseCategoryMeta
{
    static constexpr DB2MetaField Fields[9] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 4366440,
        .IndexField         = 2,
        .ParentIndexField   = 8,
        .FieldCount         = 9,
        .FileFieldCount     = 8,
        .LayoutHash         = 0x034AADE3,
        .Fields             = Fields
    };
};

struct AzeriteEmpoweredItemMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1846046,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0x48AC4E05,
        .Fields             = Fields
    };
};

struct AzeriteEssenceMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 2829665,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0xCCE26295,
        .Fields             = Fields
    };
};

struct AzeriteEssencePowerMeta
{
    static constexpr DB2MetaField Fields[8] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 2829666,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 8,
        .FileFieldCount     = 8,
        .LayoutHash         = 0x2EB43EDD,
        .Fields             = Fields
    };
};

struct AzeriteItemMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1846048,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 1,
        .FileFieldCount     = 1,
        .LayoutHash         = 0x3923C31A,
        .Fields             = Fields
    };
};

struct AzeriteItemMilestonePowerMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1915395,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0x4B01B39E,
        .Fields             = Fields
    };
};

struct AzeriteKnowledgeMultiplierMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 3148050,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 1,
        .FileFieldCount     = 1,
        .LayoutHash         = 0x47546927,
        .Fields             = Fields
    };
};

struct AzeriteLevelInfoMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_LONG,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_LONG,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 3147968,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0x22722A9A,
        .Fields             = Fields
    };
};

struct AzeritePowerMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1846044,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0xEC6B5E70,
        .Fields             = Fields
    };
};

struct AzeritePowerSetMemberMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1846040,
        .IndexField         = -1,
        .ParentIndexField   = 0,
        .FieldCount         = 5,
        .FileFieldCount     = 5,
        .LayoutHash         = 0x050A82C5,
        .Fields             = Fields
    };
};

struct AzeriteTierUnlockMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1846043,
        .IndexField         = -1,
        .ParentIndexField   = 3,
        .FieldCount         = 4,
        .FileFieldCount     = 3,
        .LayoutHash         = 0xFE36FA5C,
        .Fields             = Fields
    };
};

struct AzeriteTierUnlockSetMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 2446322,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 1,
        .FileFieldCount     = 1,
        .LayoutHash         = 0x65273FFD,
        .Fields             = Fields
    };
};

struct BankBagSlotPricesMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1284819,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 1,
        .FileFieldCount     = 1,
        .LayoutHash         = 0xDBCA3459,
        .Fields             = Fields
    };
};

struct BankTabMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_LONG,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 5242411,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0xD47B62CA,
        .Fields             = Fields
    };
};

struct BannedAddonsMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1373459,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0xC7F734D9,
        .Fields             = Fields
    };
};

struct BarberShopStyleMeta
{
    static constexpr DB2MetaField Fields[8] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1237437,
        .IndexField         = 2,
        .ParentIndexField   = -1,
        .FieldCount         = 8,
        .FileFieldCount     = 8,
        .LayoutHash         = 0x65EF4799,
        .Fields             = Fields
    };
};

struct BattlePetAbilityMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 841610,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 7,
        .FileFieldCount     = 7,
        .LayoutHash         = 0xAAD491D2,
        .Fields             = Fields
    };
};

struct BattlePetAbilityEffectMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  6, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 801575,
        .IndexField         = 0,
        .ParentIndexField   = 1,
        .FieldCount         = 7,
        .FileFieldCount     = 7,
        .LayoutHash         = 0x221D1FE6,
        .Fields             = Fields
    };
};

struct BattlePetAbilityStateMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 801576,
        .IndexField         = -1,
        .ParentIndexField   = 2,
        .FieldCount         = 3,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x6994570D,
        .Fields             = Fields
    };
};

struct BattlePetAbilityTurnMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 801577,
        .IndexField         = 0,
        .ParentIndexField   = 1,
        .FieldCount         = 6,
        .FileFieldCount     = 6,
        .LayoutHash         = 0x20C3BE16,
        .Fields             = Fields
    };
};

struct BattlePetBreedQualityMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 801578,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x77560795,
        .Fields             = Fields
    };
};

struct BattlePetBreedStateMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 801579,
        .IndexField         = -1,
        .ParentIndexField   = 2,
        .FieldCount         = 3,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x0DA4A2A5,
        .Fields             = Fields
    };
};

struct BattlePetDisplayOverrideMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1802988,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0x8F75CC44,
        .Fields             = Fields
    };
};

struct BattlePetEffectPropertiesMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  6, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  6, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 801580,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0xED4FBC95,
        .Fields             = Fields
    };
};

struct BattlePetNPCTeamMemberMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 841648,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 1,
        .FileFieldCount     = 1,
        .LayoutHash         = 0x782EE721,
        .Fields             = Fields
    };
};

struct BattlePetSpeciesMeta
{
    static constexpr DB2MetaField Fields[11] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 841622,
        .IndexField         = 2,
        .ParentIndexField   = -1,
        .FieldCount         = 11,
        .FileFieldCount     = 11,
        .LayoutHash         = 0xE306EEEA,
        .Fields             = Fields
    };
};

struct BattlePetSpeciesStateMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 801581,
        .IndexField         = -1,
        .ParentIndexField   = 2,
        .FieldCount         = 3,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x5999BD05,
        .Fields             = Fields
    };
};

struct BattlePetSpeciesXAbilityMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 801582,
        .IndexField         = -1,
        .ParentIndexField   = 3,
        .FieldCount         = 4,
        .FileFieldCount     = 3,
        .LayoutHash         = 0x69104208,
        .Fields             = Fields
    };
};

struct BattlePetStateMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 801583,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0x489B22AD,
        .Fields             = Fields
    };
};

struct BattlePetVisualMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 801584,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 7,
        .FileFieldCount     = 7,
        .LayoutHash         = 0x257B890E,
        .Fields             = Fields
    };
};

struct BattlemasterListMeta
{
    static constexpr DB2MetaField Fields[18] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1360265,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 18,
        .FileFieldCount     = 18,
        .LayoutHash         = 0x757BE902,
        .Fields             = Fields
    };
};

struct BattlemasterListXMapMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 5916746,
        .IndexField         = -1,
        .ParentIndexField   = 1,
        .FieldCount         = 2,
        .FileFieldCount     = 1,
        .LayoutHash         = 0x449D9C1C,
        .Fields             = Fields
    };
};

struct BattlepayCurrencyMeta
{
    static constexpr DB2MetaField Fields[8] =
    {
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 5549327,
        .IndexField         = 4,
        .ParentIndexField   = -1,
        .FieldCount         = 8,
        .FileFieldCount     = 8,
        .LayoutHash         = 0x38F48A2E,
        .Fields             = Fields
    };
};

struct BeamEffectMeta
{
    static constexpr DB2MetaField Fields[10] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1525607,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 10,
        .FileFieldCount     = 10,
        .LayoutHash         = 0xC4C53E61,
        .Fields             = Fields
    };
};

struct BoneWindModifierModelMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1467254,
        .IndexField         = -1,
        .ParentIndexField   = 0,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0xF84A16EF,
        .Fields             = Fields
    };
};

struct BoneWindModifiersMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_FLOAT,                .ArraySize =  3, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1416756,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x2CD1770E,
        .Fields             = Fields
    };
};

struct BonusRollMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1983274,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0x567FCB5C,
        .Fields             = Fields
    };
};

struct BountyMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1367866,
        .IndexField         = -1,
        .ParentIndexField   = 4,
        .FieldCount         = 5,
        .FileFieldCount     = 4,
        .LayoutHash         = 0x218C9656,
        .Fields             = Fields
    };
};

struct BountySetMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1367865,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0xE32AA927,
        .Fields             = Fields
    };
};

struct BroadcastTextMeta
{
    static constexpr DB2MetaField Fields[12] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  2, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  3, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  3, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 841604,
        .IndexField         = 2,
        .ParentIndexField   = -1,
        .FieldCount         = 12,
        .FileFieldCount     = 12,
        .LayoutHash         = 0x0DD39BE3,
        .Fields             = Fields
    };
};

struct CameraEffectMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1117695,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 1,
        .FileFieldCount     = 1,
        .LayoutHash         = 0x1B09C75D,
        .Fields             = Fields
    };
};

struct CameraEffectEntryMeta
{
    static constexpr DB2MetaField Fields[16] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1117696,
        .IndexField         = -1,
        .ParentIndexField   = 15,
        .FieldCount         = 16,
        .FileFieldCount     = 15,
        .LayoutHash         = 0x2B6832AA,
        .Fields             = Fields
    };
};

struct CameraModeMeta
{
    static constexpr DB2MetaField Fields[12] =
    {
        { .Type = FT_FLOAT,                .ArraySize =  3, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  3, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1343308,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 12,
        .FileFieldCount     = 12,
        .LayoutHash         = 0x2AD4ECDE,
        .Fields             = Fields
    };
};

struct CampaignMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 2031607,
        .IndexField         = 2,
        .ParentIndexField   = -1,
        .FieldCount         = 6,
        .FileFieldCount     = 6,
        .LayoutHash         = 0x3ABB9FCC,
        .Fields             = Fields
    };
};

struct CampaignXConditionMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 2031611,
        .IndexField         = -1,
        .ParentIndexField   = 2,
        .FieldCount         = 3,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x59F4979F,
        .Fields             = Fields
    };
};

struct CampaignXQuestLineMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 2036722,
        .IndexField         = -1,
        .ParentIndexField   = 0,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0x703CADAB,
        .Fields             = Fields
    };
};

struct CastableRaidBuffsMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1283018,
        .IndexField         = -1,
        .ParentIndexField   = 1,
        .FieldCount         = 2,
        .FileFieldCount     = 1,
        .LayoutHash         = 0x63E1AEB7,
        .Fields             = Fields
    };
};

struct CelestialBodyMeta
{
    static constexpr DB2MetaField Fields[15] =
    {
        { .Type = FT_FLOAT,                .ArraySize =  3, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  2, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  2, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  2, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  2, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  2, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1592470,
        .IndexField         = 1,
        .ParentIndexField   = -1,
        .FieldCount         = 15,
        .FileFieldCount     = 15,
        .LayoutHash         = 0x9A9DA61C,
        .Fields             = Fields
    };
};

struct Cfg_CategoriesMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1068162,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 6,
        .FileFieldCount     = 6,
        .LayoutHash         = 0x5ED75B84,
        .Fields             = Fields
    };
};

struct Cfg_ConfigsMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1080949,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0xE7594137,
        .Fields             = Fields
    };
};

struct Cfg_RegionsMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1082876,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 5,
        .FileFieldCount     = 5,
        .LayoutHash         = 0x8CDAAC27,
        .Fields             = Fields
    };
};

struct CharBaseInfoMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1343386,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x781A2640,
        .Fields             = Fields
    };
};

struct CharBaseSectionMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1375798,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0xCCB98D5E,
        .Fields             = Fields
    };
};

struct CharComponentTextureLayoutsMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1360262,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x9CA2CFB4,
        .Fields             = Fields
    };
};

struct CharComponentTextureSectionsMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1360263,
        .IndexField         = -1,
        .ParentIndexField   = 0,
        .FieldCount         = 7,
        .FileFieldCount     = 7,
        .LayoutHash         = 0x2173BA71,
        .Fields             = Fields
    };
};

struct CharHairGeosetsMeta
{
    static constexpr DB2MetaField Fields[10] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1256914,
        .IndexField         = -1,
        .ParentIndexField   = 0,
        .FieldCount         = 10,
        .FileFieldCount     = 10,
        .LayoutHash         = 0x0DFA0F80,
        .Fields             = Fields
    };
};

struct CharSectionConditionMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 2388725,
        .IndexField         = -1,
        .ParentIndexField   = 5,
        .FieldCount         = 6,
        .FileFieldCount     = 5,
        .LayoutHash         = 0x04C96A6C,
        .Fields             = Fields
    };
};

struct CharShipmentMeta
{
    static constexpr DB2MetaField Fields[9] =
    {
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 972425,
        .IndexField         = -1,
        .ParentIndexField   = 0,
        .FieldCount         = 9,
        .FileFieldCount     = 9,
        .LayoutHash         = 0xFF41E21A,
        .Fields             = Fields
    };
};

struct CharShipmentContainerMeta
{
    static constexpr DB2MetaField Fields[16] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 972405,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 16,
        .FileFieldCount     = 16,
        .LayoutHash         = 0xC5BCDA8C,
        .Fields             = Fields
    };
};

struct CharStartOutfitMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize = 24, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1237591,
        .IndexField         = -1,
        .ParentIndexField   = 6,
        .FieldCount         = 7,
        .FileFieldCount     = 6,
        .LayoutHash         = 0xDB39675A,
        .Fields             = Fields
    };
};

struct CharTitlesMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1349054,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0x1EEF17FF,
        .Fields             = Fields
    };
};

struct CharacterFacialHairStylesMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_INT,                  .ArraySize =  5, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1369752,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0x7D8B51FB,
        .Fields             = Fields
    };
};

struct CharacterLoadoutMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_LONG,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1344281,
        .IndexField         = 1,
        .ParentIndexField   = -1,
        .FieldCount         = 5,
        .FileFieldCount     = 5,
        .LayoutHash         = 0x40E16BC1,
        .Fields             = Fields
    };
};

struct CharacterLoadoutItemMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1302846,
        .IndexField         = -1,
        .ParentIndexField   = 0,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x0C7A1862,
        .Fields             = Fields
    };
};

struct CharacterServiceInfoMeta
{
    static constexpr DB2MetaField Fields[12] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1815417,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 12,
        .FileFieldCount     = 12,
        .LayoutHash         = 0x6C7A7648,
        .Fields             = Fields
    };
};

struct ChatChannelsMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1345278,
        .IndexField         = 2,
        .ParentIndexField   = -1,
        .FieldCount         = 6,
        .FileFieldCount     = 6,
        .LayoutHash         = 0x20E8D278,
        .Fields             = Fields
    };
};

struct ChatProfanityMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1117084,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x7EACA150,
        .Fields             = Fields
    };
};

struct ChrClassRaceSexMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1306188,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 6,
        .FileFieldCount     = 6,
        .LayoutHash         = 0x0FB99891,
        .Fields             = Fields
    };
};

struct ChrClassTitleMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1267497,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0xC086F95D,
        .Fields             = Fields
    };
};

struct ChrClassUIDisplayMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1316515,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0x50F5AD66,
        .Fields             = Fields
    };
};

struct ChrClassVillainMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1267498,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0x46041630,
        .Fields             = Fields
    };
};

struct ChrClassesMeta
{
    static constexpr DB2MetaField Fields[26] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1361031,
        .IndexField         = 15,
        .ParentIndexField   = -1,
        .FieldCount         = 26,
        .FileFieldCount     = 26,
        .LayoutHash         = 0x7F76B35B,
        .Fields             = Fields
    };
};

struct ChrClassesXPowerTypesMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1121420,
        .IndexField         = -1,
        .ParentIndexField   = 1,
        .FieldCount         = 2,
        .FileFieldCount     = 1,
        .LayoutHash         = 0x70DA1F8C,
        .Fields             = Fields
    };
};

struct ChrCustClientChoiceConversionMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 3590348,
        .IndexField         = 0,
        .ParentIndexField   = 3,
        .FieldCount         = 4,
        .FileFieldCount     = 3,
        .LayoutHash         = 0x8ED0FBED,
        .Fields             = Fields
    };
};

struct ChrCustGeoComponentLinkMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 5387095,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 1,
        .FileFieldCount     = 1,
        .LayoutHash         = 0x892316B4,
        .Fields             = Fields
    };
};

struct ChrCustItemGeoModifyMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 3952714,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0xFE865CC3,
        .Fields             = Fields
    };
};

struct ChrCustomizationMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  3, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1611874,
        .IndexField         = -1,
        .ParentIndexField   = 6,
        .FieldCount         = 7,
        .FileFieldCount     = 6,
        .LayoutHash         = 0xE5EEFBF5,
        .Fields             = Fields
    };
};

struct ChrCustomizationBoneSetMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 3460181,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0xCC2CFF6E,
        .Fields             = Fields
    };
};

struct ChrCustomizationCategoryMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 3526439,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 7,
        .FileFieldCount     = 7,
        .LayoutHash         = 0x7617515B,
        .Fields             = Fields
    };
};

struct ChrCustomizationChoiceMeta
{
    static constexpr DB2MetaField Fields[11] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  2, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 3450554,
        .IndexField         = 1,
        .ParentIndexField   = 2,
        .FieldCount         = 11,
        .FileFieldCount     = 11,
        .LayoutHash         = 0x9559C358,
        .Fields             = Fields
    };
};

struct ChrCustomizationCondModelMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  4, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 3460182,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x601A4522,
        .Fields             = Fields
    };
};

struct ChrCustomizationConversionMeta
{
    static constexpr DB2MetaField Fields[8] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 3463337,
        .IndexField         = -1,
        .ParentIndexField   = 4,
        .FieldCount         = 8,
        .FileFieldCount     = 8,
        .LayoutHash         = 0xFE20D48D,
        .Fields             = Fields
    };
};

struct ChrCustomizationDisplayInfoMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 3593032,
        .IndexField         = 0,
        .ParentIndexField   = -1,
        .FieldCount         = 6,
        .FileFieldCount     = 6,
        .LayoutHash         = 0x9BA35F7B,
        .Fields             = Fields
    };
};

struct ChrCustomizationElementMeta
{
    static constexpr DB2MetaField Fields[14] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 3512765,
        .IndexField         = 0,
        .ParentIndexField   = -1,
        .FieldCount         = 14,
        .FileFieldCount     = 14,
        .LayoutHash         = 0xD68DCDEA,
        .Fields             = Fields
    };
};

struct ChrCustomizationGeosetMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 3456171,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0x44C80DEB,
        .Fields             = Fields
    };
};

struct ChrCustomizationGlyphPetMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 5347591,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 6,
        .FileFieldCount     = 6,
        .LayoutHash         = 0xE9159047,
        .Fields             = Fields
    };
};

struct ChrCustomizationMaterialMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 3459652,
        .IndexField         = 0,
        .ParentIndexField   = -1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0xE61F7A35,
        .Fields             = Fields
    };
};

struct ChrCustomizationOptionMeta
{
    static constexpr DB2MetaField Fields[12] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 3384247,
        .IndexField         = 1,
        .ParentIndexField   = 4,
        .FieldCount         = 12,
        .FileFieldCount     = 12,
        .LayoutHash         = 0x6714C155,
        .Fields             = Fields
    };
};

struct ChrCustomizationReqMeta
{
    static constexpr DB2MetaField Fields[10] =
    {
        { .Type = FT_LONG,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 3450453,
        .IndexField         = 2,
        .ParentIndexField   = -1,
        .FieldCount         = 10,
        .FileFieldCount     = 10,
        .LayoutHash         = 0x13431BC6,
        .Fields             = Fields
    };
};

struct ChrCustomizationReqChoiceMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 3580359,
        .IndexField         = -1,
        .ParentIndexField   = 1,
        .FieldCount         = 2,
        .FileFieldCount     = 1,
        .LayoutHash         = 0xF925BC6F,
        .Fields             = Fields
    };
};

struct ChrCustomizationSkinnedModelMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 3460183,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 5,
        .FileFieldCount     = 5,
        .LayoutHash         = 0xE447963A,
        .Fields             = Fields
    };
};

struct ChrCustomizationVisReqMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 4724136,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x52C27B83,
        .Fields             = Fields
    };
};

struct ChrCustomizationVoiceMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 4672833,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 1,
        .FileFieldCount     = 1,
        .LayoutHash         = 0x03684BD2,
        .Fields             = Fields
    };
};

struct ChrModelMeta
{
    static constexpr DB2MetaField Fields[17] =
    {
        { .Type = FT_FLOAT,                .ArraySize =  3, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  3, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 3384313,
        .IndexField         = 2,
        .ParentIndexField   = 4,
        .FieldCount         = 17,
        .FileFieldCount     = 17,
        .LayoutHash         = 0x03FAB755,
        .Fields             = Fields
    };
};

struct ChrModelMaterialMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 3566562,
        .IndexField         = 0,
        .ParentIndexField   = 1,
        .FieldCount         = 7,
        .FileFieldCount     = 7,
        .LayoutHash         = 0x22469480,
        .Fields             = Fields
    };
};

struct ChrModelTextureLayerMeta
{
    static constexpr DB2MetaField Fields[10] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  3, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  2, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 3548976,
        .IndexField         = 0,
        .ParentIndexField   = 9,
        .FieldCount         = 10,
        .FileFieldCount     = 9,
        .LayoutHash         = 0x31F57E28,
        .Fields             = Fields
    };
};

struct ChrRaceXChrModelMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 3490304,
        .IndexField         = -1,
        .ParentIndexField   = 0,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0xA203BC29,
        .Fields             = Fields
    };
};

struct ChrRacesMeta
{
    static constexpr DB2MetaField Fields[57] =
    {
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  3, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  3, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  3, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  3, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  3, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1305311,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 57,
        .FileFieldCount     = 57,
        .LayoutHash         = 0x47A2E62F,
        .Fields             = Fields
    };
};

struct ChrRacesPingMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 5320971,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0x37899423,
        .Fields             = Fields
    };
};

struct ChrSpecializationMeta
{
    static constexpr DB2MetaField Fields[13] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  2, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1343390,
        .IndexField         = 3,
        .ParentIndexField   = 4,
        .FieldCount         = 13,
        .FileFieldCount     = 13,
        .LayoutHash         = 0xBF17DE0B,
        .Fields             = Fields
    };
};

struct ChrUpgradeBucketMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 984529,
        .IndexField         = 0,
        .ParentIndexField   = 2,
        .FieldCount         = 3,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x0FFDE299,
        .Fields             = Fields
    };
};

struct ChrUpgradeBucketSpellMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 984528,
        .IndexField         = -1,
        .ParentIndexField   = 1,
        .FieldCount         = 2,
        .FileFieldCount     = 1,
        .LayoutHash         = 0x666AF1D3,
        .Fields             = Fields
    };
};

struct ChrUpgradeTierMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 984530,
        .IndexField         = 1,
        .ParentIndexField   = -1,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0xA0CEF7CA,
        .Fields             = Fields
    };
};

struct CinematicCameraMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_FLOAT,                .ArraySize =  3, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1294214,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0xF96842A0,
        .Fields             = Fields
    };
};

struct CinematicSequencesMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  8, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1134583,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x07D874FF,
        .Fields             = Fields
    };
};

struct ClientSceneEffectMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1939843,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 1,
        .FileFieldCount     = 1,
        .LayoutHash         = 0xF3B2D340,
        .Fields             = Fields
    };
};

struct ClientSettingsMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 5874295,
        .IndexField         = 1,
        .ParentIndexField   = -1,
        .FieldCount         = 5,
        .FileFieldCount     = 5,
        .LayoutHash         = 0x0ACED075,
        .Fields             = Fields
    };
};

struct CloakDampeningMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  5, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  5, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  2, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  2, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1465903,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 7,
        .FileFieldCount     = 7,
        .LayoutHash         = 0x4D53C04B,
        .Fields             = Fields
    };
};

struct CloneEffectMeta
{
    static constexpr DB2MetaField Fields[8] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 2175218,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 8,
        .FileFieldCount     = 8,
        .LayoutHash         = 0x65C255A4,
        .Fields             = Fields
    };
};

struct CombatConditionMeta
{
    static constexpr DB2MetaField Fields[11] =
    {
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  2, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  2, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  2, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  2, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  2, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  2, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1120958,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 11,
        .FileFieldCount     = 11,
        .LayoutHash         = 0xE4823C69,
        .Fields             = Fields
    };
};

struct CommentatorIndirectSpellMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 3067644,
        .IndexField         = -1,
        .ParentIndexField   = 2,
        .FieldCount         = 3,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x63CDB0D7,
        .Fields             = Fields
    };
};

struct CommentatorStartLocationMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_FLOAT,                .ArraySize =  3, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1664251,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x8EA27BA8,
        .Fields             = Fields
    };
};

struct CommentatorTrackedCooldownMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1661584,
        .IndexField         = -1,
        .ParentIndexField   = 3,
        .FieldCount         = 4,
        .FileFieldCount     = 3,
        .LayoutHash         = 0xB95A106E,
        .Fields             = Fields
    };
};

struct CommunityIconMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 2098645,
        .IndexField         = 0,
        .ParentIndexField   = -1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0x9E7BAA93,
        .Fields             = Fields
    };
};

struct ComponentModelFileDataMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1349053,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0xAD90D87A,
        .Fields             = Fields
    };
};

struct ComponentTextureFileDataMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1278239,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0xB32B030A,
        .Fields             = Fields
    };
};

struct ConditionalChrModelMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 5211412,
        .IndexField         = 0,
        .ParentIndexField   = 1,
        .FieldCount         = 6,
        .FileFieldCount     = 6,
        .LayoutHash         = 0x8236CAE9,
        .Fields             = Fields
    };
};

struct ConditionalContentTuningMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 3501965,
        .IndexField         = -1,
        .ParentIndexField   = 3,
        .FieldCount         = 4,
        .FileFieldCount     = 3,
        .LayoutHash         = 0x15616FBC,
        .Fields             = Fields
    };
};

struct ConditionalCreatureModelDataMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  4, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 5525474,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0xC974B48B,
        .Fields             = Fields
    };
};

struct ConditionalItemAppearanceMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 5345180,
        .IndexField         = -1,
        .ParentIndexField   = 5,
        .FieldCount         = 6,
        .FileFieldCount     = 5,
        .LayoutHash         = 0x5303936C,
        .Fields             = Fields
    };
};

struct ConfigurationWarningMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1709409,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0xE476B573,
        .Fields             = Fields
    };
};

struct ContentPushMeta
{
    static constexpr DB2MetaField Fields[9] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 5742435,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 9,
        .FileFieldCount     = 9,
        .LayoutHash         = 0xE12AA1EF,
        .Fields             = Fields
    };
};

struct ContentTuningMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1962930,
        .IndexField         = 0,
        .ParentIndexField   = -1,
        .FieldCount         = 6,
        .FileFieldCount     = 6,
        .LayoutHash         = 0x1FB45111,
        .Fields             = Fields
    };
};

struct ContributionMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  4, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1587153,
        .IndexField         = 2,
        .ParentIndexField   = 3,
        .FieldCount         = 7,
        .FileFieldCount     = 7,
        .LayoutHash         = 0x167173C3,
        .Fields             = Fields
    };
};

struct ContributionStyleMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 2143633,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 7,
        .FileFieldCount     = 7,
        .LayoutHash         = 0x88C22204,
        .Fields             = Fields
    };
};

struct ContributionStyleContainerMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { .Type = FT_INT,                  .ArraySize =  5, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 2143634,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 1,
        .FileFieldCount     = 1,
        .LayoutHash         = 0x8879F685,
        .Fields             = Fields
    };
};

struct ConversationLineMeta
{
    static constexpr DB2MetaField Fields[8] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1260801,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 8,
        .FileFieldCount     = 8,
        .LayoutHash         = 0x0F1FE894,
        .Fields             = Fields
    };
};

struct CraftingDataMeta
{
    static constexpr DB2MetaField Fields[16] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 4545611,
        .IndexField         = 0,
        .ParentIndexField   = -1,
        .FieldCount         = 16,
        .FileFieldCount     = 16,
        .LayoutHash         = 0xC21C854F,
        .Fields             = Fields
    };
};

struct CraftingDifficultyMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 4373536,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 7,
        .FileFieldCount     = 7,
        .LayoutHash         = 0x7744A1A6,
        .Fields             = Fields
    };
};

struct CraftingOrderXLabelMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 5875491,
        .IndexField         = 0,
        .ParentIndexField   = 1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0x4AA53C3A,
        .Fields             = Fields
    };
};

struct CreatureMeta
{
    static constexpr DB2MetaField Fields[11] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  4, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  4, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  3, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 841631,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 11,
        .FileFieldCount     = 11,
        .LayoutHash         = 0xAEA084C0,
        .Fields             = Fields
    };
};

struct CreatureDifficultyMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  8, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 879282,
        .IndexField         = -1,
        .ParentIndexField   = 6,
        .FieldCount         = 7,
        .FileFieldCount     = 6,
        .LayoutHash         = 0x43F263AF,
        .Fields             = Fields
    };
};

struct CreatureDispXUiCameraMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1146692,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0xA5E810E7,
        .Fields             = Fields
    };
};

struct CreatureDisplayInfoMeta
{
    static constexpr DB2MetaField Fields[26] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  4, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1108759,
        .IndexField         = 0,
        .ParentIndexField   = -1,
        .FieldCount         = 26,
        .FileFieldCount     = 26,
        .LayoutHash         = 0xD89C751C,
        .Fields             = Fields
    };
};

struct CreatureDisplayInfoCondMeta
{
    static constexpr DB2MetaField Fields[8] =
    {
        { .Type = FT_LONG,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  4, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1332686,
        .IndexField         = 1,
        .ParentIndexField   = 7,
        .FieldCount         = 8,
        .FileFieldCount     = 7,
        .LayoutHash         = 0xD6D105AE,
        .Fields             = Fields
    };
};

struct CreatureDisplayInfoCondXChoiceMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 3670439,
        .IndexField         = -1,
        .ParentIndexField   = 0,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x8AB1D7E8,
        .Fields             = Fields
    };
};

struct CreatureDisplayInfoEvtMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1586882,
        .IndexField         = -1,
        .ParentIndexField   = 3,
        .FieldCount         = 4,
        .FileFieldCount     = 3,
        .LayoutHash         = 0xF2A5FCAA,
        .Fields             = Fields
    };
};

struct CreatureDisplayInfoExtraMeta
{
    static constexpr DB2MetaField Fields[13] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  3, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1264997,
        .IndexField         = 0,
        .ParentIndexField   = -1,
        .FieldCount         = 13,
        .FileFieldCount     = 13,
        .LayoutHash         = 0xF5E49981,
        .Fields             = Fields
    };
};

struct CreatureDisplayInfoGeosetDataMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1720141,
        .IndexField         = -1,
        .ParentIndexField   = 2,
        .FieldCount         = 3,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x5E539080,
        .Fields             = Fields
    };
};

struct CreatureDisplayInfoOptionMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 3692043,
        .IndexField         = -1,
        .ParentIndexField   = 2,
        .FieldCount         = 3,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x2F331C33,
        .Fields             = Fields
    };
};

struct CreatureDisplayInfoTrnMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1146698,
        .IndexField         = -1,
        .ParentIndexField   = 5,
        .FieldCount         = 6,
        .FileFieldCount     = 5,
        .LayoutHash         = 0xD3A7F438,
        .Fields             = Fields
    };
};

struct CreatureFamilyMeta
{
    static constexpr DB2MetaField Fields[10] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  2, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1351351,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 10,
        .FileFieldCount     = 10,
        .LayoutHash         = 0x71DA07B7,
        .Fields             = Fields
    };
};

struct CreatureImmunitiesMeta
{
    static constexpr DB2MetaField Fields[9] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  2, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize = 11, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize = 20, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1131322,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 9,
        .FileFieldCount     = 9,
        .LayoutHash         = 0xA1D7B067,
        .Fields             = Fields
    };
};

struct CreatureModelDataMeta
{
    static constexpr DB2MetaField Fields[29] =
    {
        { .Type = FT_FLOAT,                .ArraySize =  6, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1365368,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 29,
        .FileFieldCount     = 29,
        .LayoutHash         = 0x4A4CF256,
        .Fields             = Fields
    };
};

struct CreatureMovementInfoMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1125666,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 1,
        .FileFieldCount     = 1,
        .LayoutHash         = 0x30A3C9CA,
        .Fields             = Fields
    };
};

struct CreatureSoundDataMeta
{
    static constexpr DB2MetaField Fields[39] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  5, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  4, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1344466,
        .IndexField         = 0,
        .ParentIndexField   = -1,
        .FieldCount         = 39,
        .FileFieldCount     = 39,
        .LayoutHash         = 0xE5EE765B,
        .Fields             = Fields
    };
};

struct CreatureSoundFidgetMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 4178576,
        .IndexField         = -1,
        .ParentIndexField   = 2,
        .FieldCount         = 3,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x9BDF9BD7,
        .Fields             = Fields
    };
};

struct CreatureSpellDataMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_INT,                  .ArraySize =  4, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  4, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 3032554,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x9189AF29,
        .Fields             = Fields
    };
};

struct CreatureTypeMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1131315,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x6FF4CA42,
        .Fields             = Fields
    };
};

struct CreatureXContributionMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1587158,
        .IndexField         = 0,
        .ParentIndexField   = 2,
        .FieldCount         = 3,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x8EAB9EE3,
        .Fields             = Fields
    };
};

struct CreatureXDisplayInfoMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1864302,
        .IndexField         = -1,
        .ParentIndexField   = 5,
        .FieldCount         = 6,
        .FileFieldCount     = 5,
        .LayoutHash         = 0x2EA19FCF,
        .Fields             = Fields
    };
};

struct CriteriaMeta
{
    static constexpr DB2MetaField Fields[12] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1263817,
        .IndexField         = 0,
        .ParentIndexField   = -1,
        .FieldCount         = 12,
        .FileFieldCount     = 12,
        .LayoutHash         = 0xB06E4073,
        .Fields             = Fields
    };
};

struct CriteriaTreeMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1263818,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 7,
        .FileFieldCount     = 7,
        .LayoutHash         = 0xFF97AE12,
        .Fields             = Fields
    };
};

struct CriteriaTreeXEffectMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1345969,
        .IndexField         = -1,
        .ParentIndexField   = 1,
        .FieldCount         = 2,
        .FileFieldCount     = 1,
        .LayoutHash         = 0xA95C5FCA,
        .Fields             = Fields
    };
};

struct CurrencyCategoryMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1125667,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0x12EB5F37,
        .Fields             = Fields
    };
};

struct CurrencyContainerMeta
{
    static constexpr DB2MetaField Fields[8] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1934603,
        .IndexField         = -1,
        .ParentIndexField   = 7,
        .FieldCount         = 8,
        .FileFieldCount     = 7,
        .LayoutHash         = 0x4A649F1A,
        .Fields             = Fields
    };
};

struct CurrencyTypesMeta
{
    static constexpr DB2MetaField Fields[14] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  2, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1095531,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 14,
        .FileFieldCount     = 14,
        .LayoutHash         = 0xA0DA38E0,
        .Fields             = Fields
    };
};

struct CurveMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 892585,
        .IndexField         = 0,
        .ParentIndexField   = -1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0x48AE7F4A,
        .Fields             = Fields
    };
};

struct CurvePointMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_FLOAT,                .ArraySize =  2, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  2, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 892586,
        .IndexField         = 2,
        .ParentIndexField   = 3,
        .FieldCount         = 5,
        .FileFieldCount     = 5,
        .LayoutHash         = 0x8DB83C21,
        .Fields             = Fields
    };
};

struct DeathThudLookupsMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1279415,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0xDDC6DB32,
        .Fields             = Fields
    };
};

struct DecalPropertiesMeta
{
    static constexpr DB2MetaField Fields[18] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1278176,
        .IndexField         = 0,
        .ParentIndexField   = -1,
        .FieldCount         = 18,
        .FileFieldCount     = 18,
        .LayoutHash         = 0xF39349FF,
        .Fields             = Fields
    };
};

struct DeclinedWordMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1279100,
        .IndexField         = 1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x104E18EF,
        .Fields             = Fields
    };
};

struct DeclinedWordCasesMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1279099,
        .IndexField         = -1,
        .ParentIndexField   = 2,
        .FieldCount         = 3,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x24277AA1,
        .Fields             = Fields
    };
};

struct DelvesSeasonMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 5920079,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 1,
        .FileFieldCount     = 1,
        .LayoutHash         = 0xDB8CA312,
        .Fields             = Fields
    };
};

struct DelvesSeasonXSpellMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 5920080,
        .IndexField         = -1,
        .ParentIndexField   = 1,
        .FieldCount         = 2,
        .FileFieldCount     = 1,
        .LayoutHash         = 0x13DB27BC,
        .Fields             = Fields
    };
};

struct DestructibleModelDataMeta
{
    static constexpr DB2MetaField Fields[22] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1122116,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 22,
        .FileFieldCount     = 22,
        .LayoutHash         = 0xC0CB9712,
        .Fields             = Fields
    };
};

struct DeviceBlacklistMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 922722,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x29FEDBB1,
        .Fields             = Fields
    };
};

struct DifficultyMeta
{
    static constexpr DB2MetaField Fields[14] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1352127,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 14,
        .FileFieldCount     = 14,
        .LayoutHash         = 0xB338FF51,
        .Fields             = Fields
    };
};

struct DisplaySeasonMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 4279827,
        .IndexField         = 1,
        .ParentIndexField   = -1,
        .FieldCount         = 7,
        .FileFieldCount     = 7,
        .LayoutHash         = 0x95C01F30,
        .Fields             = Fields
    };
};

struct DissolveEffectMeta
{
    static constexpr DB2MetaField Fields[21] =
    {
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1304325,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 21,
        .FileFieldCount     = 21,
        .LayoutHash         = 0x1E2060A7,
        .Fields             = Fields
    };
};

struct DriveCapabilityMeta
{
    static constexpr DB2MetaField Fields[17] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 6320418,
        .IndexField         = 0,
        .ParentIndexField   = -1,
        .FieldCount         = 17,
        .FileFieldCount     = 17,
        .LayoutHash         = 0xE1CBCBD3,
        .Fields             = Fields
    };
};

struct DriveCapabilityTierMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 6336219,
        .IndexField         = 0,
        .ParentIndexField   = 3,
        .FieldCount         = 5,
        .FileFieldCount     = 5,
        .LayoutHash         = 0x428EF14F,
        .Fields             = Fields
    };
};

struct DriverBlacklistMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 922720,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 7,
        .FileFieldCount     = 7,
        .LayoutHash         = 0x5A336370,
        .Fields             = Fields
    };
};

struct DungeonEncounterMeta
{
    static constexpr DB2MetaField Fields[10] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1347279,
        .IndexField         = 1,
        .ParentIndexField   = 2,
        .FieldCount         = 10,
        .FileFieldCount     = 10,
        .LayoutHash         = 0x7B6AC42A,
        .Fields             = Fields
    };
};

struct DurabilityCostsMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_SHORT,                .ArraySize = 21, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  8, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1283019,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x917714A1,
        .Fields             = Fields
    };
};

struct DurabilityQualityMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1130268,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 1,
        .FileFieldCount     = 1,
        .LayoutHash         = 0x08763C54,
        .Fields             = Fields
    };
};

struct EdgeGlowEffectMeta
{
    static constexpr DB2MetaField Fields[13] =
    {
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1387381,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 13,
        .FileFieldCount     = 13,
        .LayoutHash         = 0x9B3C5463,
        .Fields             = Fields
    };
};

struct EmotesMeta
{
    static constexpr DB2MetaField Fields[9] =
    {
        { .Type = FT_LONG,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1343602,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 9,
        .FileFieldCount     = 9,
        .LayoutHash         = 0x590311E0,
        .Fields             = Fields
    };
};

struct EmotesTextMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1347273,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0xCCDBFBAF,
        .Fields             = Fields
    };
};

struct EmotesTextDataMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1283024,
        .IndexField         = -1,
        .ParentIndexField   = 2,
        .FieldCount         = 3,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x4BF58EA9,
        .Fields             = Fields
    };
};

struct EmotesTextSoundMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1286524,
        .IndexField         = -1,
        .ParentIndexField   = 4,
        .FieldCount         = 5,
        .FileFieldCount     = 4,
        .LayoutHash         = 0x3ECA1BE0,
        .Fields             = Fields
    };
};

struct EnvironmentalDamageMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1278398,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x4B8F9058,
        .Fields             = Fields
    };
};

struct ExhaustionMeta
{
    static constexpr DB2MetaField Fields[8] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1343313,
        .IndexField         = 2,
        .ParentIndexField   = -1,
        .FieldCount         = 8,
        .FileFieldCount     = 8,
        .LayoutHash         = 0x9FAD46FA,
        .Fields             = Fields
    };
};

struct ExpectedStatMeta
{
    static constexpr DB2MetaField Fields[11] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1937326,
        .IndexField         = -1,
        .ParentIndexField   = 10,
        .FieldCount         = 11,
        .FileFieldCount     = 10,
        .LayoutHash         = 0xFD4F2D39,
        .Fields             = Fields
    };
};

struct ExpectedStatModMeta
{
    static constexpr DB2MetaField Fields[9] =
    {
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1969773,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 9,
        .FileFieldCount     = 9,
        .LayoutHash         = 0x8C41CCCE,
        .Fields             = Fields
    };
};

struct FactionMeta
{
    static constexpr DB2MetaField Fields[18] =
    {
        { .Type = FT_LONG,                 .ArraySize =  4, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  4, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  4, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  4, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  4, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  2, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  2, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1361972,
        .IndexField         = 3,
        .ParentIndexField   = -1,
        .FieldCount         = 18,
        .FileFieldCount     = 18,
        .LayoutHash         = 0xE3A94265,
        .Fields             = Fields
    };
};

struct FactionGroupMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1343595,
        .IndexField         = 2,
        .ParentIndexField   = -1,
        .FieldCount         = 6,
        .FileFieldCount     = 6,
        .LayoutHash         = 0x1587C7D7,
        .Fields             = Fields
    };
};

struct FactionTemplateMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  8, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  8, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1361579,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 7,
        .FileFieldCount     = 7,
        .LayoutHash         = 0x22B6DC22,
        .Fields             = Fields
    };
};

struct FlightCapabilityMeta
{
    static constexpr DB2MetaField Fields[25] =
    {
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 4501047,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 25,
        .FileFieldCount     = 25,
        .LayoutHash         = 0x5CF8CAA8,
        .Fields             = Fields
    };
};

struct FootprintTexturesMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1308056,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0xA762B817,
        .Fields             = Fields
    };
};

struct FootstepTerrainLookupMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1267647,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0x747D783F,
        .Fields             = Fields
    };
};

struct FriendshipRepReactionMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1237638,
        .IndexField         = -1,
        .ParentIndexField   = 1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0xDA471F1D,
        .Fields             = Fields
    };
};

struct FriendshipReputationMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1237639,
        .IndexField         = 1,
        .ParentIndexField   = -1,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0x7E69A97F,
        .Fields             = Fields
    };
};

struct FullScreenEffectMeta
{
    static constexpr DB2MetaField Fields[28] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1348282,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 28,
        .FileFieldCount     = 28,
        .LayoutHash         = 0xC0799EA5,
        .Fields             = Fields
    };
};

struct GMSurveyAnswersMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1283025,
        .IndexField         = -1,
        .ParentIndexField   = 2,
        .FieldCount         = 3,
        .FileFieldCount     = 2,
        .LayoutHash         = 0xA8167E67,
        .Fields             = Fields
    };
};

struct GMSurveyCurrentSurveyMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1278177,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 1,
        .FileFieldCount     = 1,
        .LayoutHash         = 0x42C33040,
        .Fields             = Fields
    };
};

struct GMSurveyQuestionsMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1278178,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 1,
        .FileFieldCount     = 1,
        .LayoutHash         = 0xA07C5F5C,
        .Fields             = Fields
    };
};

struct GMSurveySurveysMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { .Type = FT_BYTE,                 .ArraySize = 15, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1283020,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 1,
        .FileFieldCount     = 1,
        .LayoutHash         = 0x986268B3,
        .Fields             = Fields
    };
};

struct GameClockDebugMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 2922072,
        .IndexField         = 0,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x08DEAF7F,
        .Fields             = Fields
    };
};

struct GameModeMeta
{
    static constexpr DB2MetaField Fields[9] =
    {
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 5008306,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 9,
        .FileFieldCount     = 9,
        .LayoutHash         = 0x60A1CBA9,
        .Fields             = Fields
    };
};

struct GameObjectAnimGroupMemberMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 3565753,
        .IndexField         = -1,
        .ParentIndexField   = 0,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0xD36FC187,
        .Fields             = Fields
    };
};

struct GameObjectArtKitMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  3, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1266737,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0xF1996F13,
        .Fields             = Fields
    };
};

struct GameObjectDiffAnimMapMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1302847,
        .IndexField         = -1,
        .ParentIndexField   = 3,
        .FieldCount         = 4,
        .FileFieldCount     = 3,
        .LayoutHash         = 0x41A0ED3A,
        .Fields             = Fields
    };
};

struct GameObjectDisplayConditionMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 5634246,
        .IndexField         = 0,
        .ParentIndexField   = 5,
        .FieldCount         = 6,
        .FileFieldCount     = 5,
        .LayoutHash         = 0x52044F17,
        .Fields             = Fields
    };
};

struct GameObjectDisplayInfoMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  6, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1266277,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 7,
        .FileFieldCount     = 7,
        .LayoutHash         = 0x7C5F0B90,
        .Fields             = Fields
    };
};

struct GameObjectDisplayInfoXSoundKitMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1345272,
        .IndexField         = -1,
        .ParentIndexField   = 2,
        .FieldCount         = 3,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x70E1497B,
        .Fields             = Fields
    };
};

struct GameObjectsMeta
{
    static constexpr DB2MetaField Fields[13] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  3, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  4, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  8, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 841620,
        .IndexField         = 3,
        .ParentIndexField   = 4,
        .FieldCount         = 13,
        .FileFieldCount     = 13,
        .LayoutHash         = 0x9E707394,
        .Fields             = Fields
    };
};

struct GameTipsMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1368021,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0xF70DB051,
        .Fields             = Fields
    };
};

struct GarrAbilityMeta
{
    static constexpr DB2MetaField Fields[8] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 966238,
        .IndexField         = 2,
        .ParentIndexField   = -1,
        .FieldCount         = 8,
        .FileFieldCount     = 8,
        .LayoutHash         = 0x1297C851,
        .Fields             = Fields
    };
};

struct GarrAbilityCategoryMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1020248,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 1,
        .FileFieldCount     = 1,
        .LayoutHash         = 0x782EE721,
        .Fields             = Fields
    };
};

struct GarrAbilityEffectMeta
{
    static constexpr DB2MetaField Fields[12] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 966241,
        .IndexField         = 0,
        .ParentIndexField   = 1,
        .FieldCount         = 12,
        .FileFieldCount     = 12,
        .LayoutHash         = 0xCEA59782,
        .Fields             = Fields
    };
};

struct GarrFollowerXAbilityMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 968468,
        .IndexField         = -1,
        .ParentIndexField   = 3,
        .FieldCount         = 4,
        .FileFieldCount     = 3,
        .LayoutHash         = 0x11D80996,
        .Fields             = Fields
    };
};

struct GarrItemLevelUpgradeDataMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1572314,
        .IndexField         = 0,
        .ParentIndexField   = -1,
        .FieldCount         = 5,
        .FileFieldCount     = 5,
        .LayoutHash         = 0x3E6B889F,
        .Fields             = Fields
    };
};

struct GarrMechanicMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 967963,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0xED9C4A65,
        .Fields             = Fields
    };
};

struct GarrMechanicSetXMechanicMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1391531,
        .IndexField         = 0,
        .ParentIndexField   = 2,
        .FieldCount         = 3,
        .FileFieldCount     = 2,
        .LayoutHash         = 0xE3B55DDA,
        .Fields             = Fields
    };
};

struct GarrMechanicTypeMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 967964,
        .IndexField         = 2,
        .ParentIndexField   = -1,
        .FieldCount         = 5,
        .FileFieldCount     = 5,
        .LayoutHash         = 0x84BA4276,
        .Fields             = Fields
    };
};

struct GarrMissionMeta
{
    static constexpr DB2MetaField Fields[29] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  2, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  2, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 967962,
        .IndexField         = 5,
        .ParentIndexField   = 28,
        .FieldCount         = 29,
        .FileFieldCount     = 28,
        .LayoutHash         = 0x1452FB94,
        .Fields             = Fields
    };
};

struct GarrMissionTextureMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_FLOAT,                .ArraySize =  2, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1125220,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x3151B2BB,
        .Fields             = Fields
    };
};

struct GarrMissionTypeMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 984174,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0xC10BF76C,
        .Fields             = Fields
    };
};

struct GemPropertiesMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1343604,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0x68ADF6E0,
        .Fields             = Fields
    };
};

struct GlobalColorMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 4328468,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x760E0516,
        .Fields             = Fields
    };
};

struct GlobalPlayerConditionMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 4082838,
        .IndexField         = -1,
        .ParentIndexField   = 2,
        .FieldCount         = 3,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x6C3B89B7,
        .Fields             = Fields
    };
};

struct GlobalPlayerConditionSetMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 4082839,
        .IndexField         = 0,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0xF00A7AB4,
        .Fields             = Fields
    };
};

struct GlobalStringsMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1394440,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0x62707826,
        .Fields             = Fields
    };
};

struct GlyphBindableSpellMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1270147,
        .IndexField         = -1,
        .ParentIndexField   = 1,
        .FieldCount         = 2,
        .FileFieldCount     = 1,
        .LayoutHash         = 0x8AB55EA9,
        .Fields             = Fields
    };
};

struct GlyphExclusiveCategoryMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 948546,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 1,
        .FileFieldCount     = 1,
        .LayoutHash         = 0xEB3B0B94,
        .Fields             = Fields
    };
};

struct GlyphPropertiesMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1345274,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 5,
        .FileFieldCount     = 5,
        .LayoutHash         = 0x73F1D2B7,
        .Fields             = Fields
    };
};

struct GlyphRequiredSpecMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 948496,
        .IndexField         = -1,
        .ParentIndexField   = 1,
        .FieldCount         = 2,
        .FileFieldCount     = 1,
        .LayoutHash         = 0x7FA14D85,
        .Fields             = Fields
    };
};

struct GlyphSlotMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1130095,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x36A4E8D8,
        .Fields             = Fields
    };
};

struct GossipNPCOptionMeta
{
    static constexpr DB2MetaField Fields[12] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 4278503,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 12,
        .FileFieldCount     = 12,
        .LayoutHash         = 0xA92751B6,
        .Fields             = Fields
    };
};

struct GossipNPCOptionDisplayInfoMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 4335720,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0x10CC2F94,
        .Fields             = Fields
    };
};

struct GradientEffectMeta
{
    static constexpr DB2MetaField Fields[18] =
    {
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 2433582,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 18,
        .FileFieldCount     = 18,
        .LayoutHash         = 0xAFB2AC4C,
        .Fields             = Fields
    };
};

struct GroundEffectDoodadMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1308057,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0x99BE0B89,
        .Fields             = Fields
    };
};

struct GroundEffectTextureMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  4, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  4, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1308499,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0xE77A386D,
        .Fields             = Fields
    };
};

struct GroupFinderActivityMeta
{
    static constexpr DB2MetaField Fields[19] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 974813,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 19,
        .FileFieldCount     = 19,
        .LayoutHash         = 0x1EE9C586,
        .Fields             = Fields
    };
};

struct GroupFinderActivityGrpMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 974814,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0xB3F025D8,
        .Fields             = Fields
    };
};

struct GroupFinderActivityXPvpBracketMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 4206623,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x0E3530F0,
        .Fields             = Fields
    };
};

struct GroupFinderCategoryMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 974812,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0x039D6BF9,
        .Fields             = Fields
    };
};

struct GuildColorBackgroundMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1286526,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0x1C82913E,
        .Fields             = Fields
    };
};

struct GuildColorBorderMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1286527,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0x1C82913E,
        .Fields             = Fields
    };
};

struct GuildColorEmblemMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1286525,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0x1C82913E,
        .Fields             = Fields
    };
};

struct GuildEmblemMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 2734754,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x2532676C,
        .Fields             = Fields
    };
};

struct GuildPerkSpellsMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1135238,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 1,
        .FileFieldCount     = 1,
        .LayoutHash         = 0xC933095D,
        .Fields             = Fields
    };
};

struct GuildShirtBackgroundMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 2921008,
        .IndexField         = -1,
        .ParentIndexField   = 3,
        .FieldCount         = 4,
        .FileFieldCount     = 3,
        .LayoutHash         = 0x1DC85F62,
        .Fields             = Fields
    };
};

struct GuildShirtBorderMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 2921475,
        .IndexField         = -1,
        .ParentIndexField   = 4,
        .FieldCount         = 5,
        .FileFieldCount     = 4,
        .LayoutHash         = 0x5363EE75,
        .Fields             = Fields
    };
};

struct GuildTabardBackgroundMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 2909769,
        .IndexField         = -1,
        .ParentIndexField   = 3,
        .FieldCount         = 4,
        .FileFieldCount     = 3,
        .LayoutHash         = 0xFA17E913,
        .Fields             = Fields
    };
};

struct GuildTabardBorderMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 2920485,
        .IndexField         = -1,
        .ParentIndexField   = 4,
        .FieldCount         = 5,
        .FileFieldCount     = 4,
        .LayoutHash         = 0x4A8DDE7F,
        .Fields             = Fields
    };
};

struct GuildTabardEmblemMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 2910470,
        .IndexField         = -1,
        .ParentIndexField   = 3,
        .FieldCount         = 4,
        .FileFieldCount     = 3,
        .LayoutHash         = 0x9A3366EF,
        .Fields             = Fields
    };
};

struct HeirloomMeta
{
    static constexpr DB2MetaField Fields[10] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  6, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  6, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1097696,
        .IndexField         = 1,
        .ParentIndexField   = -1,
        .FieldCount         = 10,
        .FileFieldCount     = 10,
        .LayoutHash         = 0x2F8299AE,
        .Fields             = Fields
    };
};

struct HelmetAnimScalingMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1348283,
        .IndexField         = -1,
        .ParentIndexField   = 2,
        .FieldCount         = 3,
        .FileFieldCount     = 2,
        .LayoutHash         = 0xFF7E3A8A,
        .Fields             = Fields
    };
};

struct HelmetGeosetDataMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 2821752,
        .IndexField         = -1,
        .ParentIndexField   = 4,
        .FieldCount         = 5,
        .FileFieldCount     = 4,
        .LayoutHash         = 0x103B3B37,
        .Fields             = Fields
    };
};

struct HighlightColorMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 996358,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 5,
        .FileFieldCount     = 5,
        .LayoutHash         = 0x6A5296CF,
        .Fields             = Fields
    };
};

struct HolidayDescriptionsMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 996360,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 1,
        .FileFieldCount     = 1,
        .LayoutHash         = 0xA7B94A81,
        .Fields             = Fields
    };
};

struct HolidayNamesMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 996359,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 1,
        .FileFieldCount     = 1,
        .LayoutHash         = 0xD76CBBD2,
        .Fields             = Fields
    };
};

struct HolidaysMeta
{
    static constexpr DB2MetaField Fields[13] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize = 10, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize = 16, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize = 10, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  3, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 996357,
        .IndexField         = 0,
        .ParentIndexField   = -1,
        .FieldCount         = 13,
        .FileFieldCount     = 13,
        .LayoutHash         = 0xC53840D5,
        .Fields             = Fields
    };
};

struct HotfixesMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1995523,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0xA2CB2E77,
        .Fields             = Fields
    };
};

struct ImportPriceArmorMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1121229,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0xC9501AE7,
        .Fields             = Fields
    };
};

struct ImportPriceQualityMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1121228,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 1,
        .FileFieldCount     = 1,
        .LayoutHash         = 0x08763C54,
        .Fields             = Fields
    };
};

struct ImportPriceShieldMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1121227,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 1,
        .FileFieldCount     = 1,
        .LayoutHash         = 0x08763C54,
        .Fields             = Fields
    };
};

struct ImportPriceWeaponMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1121230,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 1,
        .FileFieldCount     = 1,
        .LayoutHash         = 0x08763C54,
        .Fields             = Fields
    };
};

struct InvasionClientDataMeta
{
    static constexpr DB2MetaField Fields[10] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  2, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1336651,
        .IndexField         = 2,
        .ParentIndexField   = 9,
        .FieldCount         = 10,
        .FileFieldCount     = 9,
        .LayoutHash         = 0x2B0F31F8,
        .Fields             = Fields
    };
};

struct ItemMeta
{
    static constexpr DB2MetaField Fields[20] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  5, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  7, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  5, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  5, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 841626,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 20,
        .FileFieldCount     = 20,
        .LayoutHash         = 0x62FE3B1A,
        .Fields             = Fields
    };
};

struct ItemAppearanceMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 982462,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 5,
        .FileFieldCount     = 5,
        .LayoutHash         = 0x481C4281,
        .Fields             = Fields
    };
};

struct ItemAppearanceXUiCameraMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1248126,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x4BEBE0CD,
        .Fields             = Fields
    };
};

struct ItemArmorQualityMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { .Type = FT_FLOAT,                .ArraySize =  7, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1283021,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 1,
        .FileFieldCount     = 1,
        .LayoutHash         = 0x2935AA9D,
        .Fields             = Fields
    };
};

struct ItemArmorShieldMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_FLOAT,                .ArraySize =  7, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1277741,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x7E6C94F9,
        .Fields             = Fields
    };
};

struct ItemArmorTotalMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1283022,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 5,
        .FileFieldCount     = 5,
        .LayoutHash         = 0xEB155D51,
        .Fields             = Fields
    };
};

struct ItemBagFamilyMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1278179,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 1,
        .FileFieldCount     = 1,
        .LayoutHash         = 0x782EE721,
        .Fields             = Fields
    };
};

struct ItemBonusMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_INT,                  .ArraySize =  4, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 959070,
        .IndexField         = -1,
        .ParentIndexField   = 1,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0x79CD4525,
        .Fields             = Fields
    };
};

struct ItemBonusListLevelDeltaMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1320358,
        .IndexField         = 1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x52DF470F,
        .Fields             = Fields
    };
};

struct ItemBonusTreeNodeMeta
{
    static constexpr DB2MetaField Fields[9] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 987134,
        .IndexField         = -1,
        .ParentIndexField   = 8,
        .FieldCount         = 9,
        .FileFieldCount     = 8,
        .LayoutHash         = 0x6304AE19,
        .Fields             = Fields
    };
};

struct ItemChildEquipmentMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1247926,
        .IndexField         = -1,
        .ParentIndexField   = 0,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0x2B57F9DE,
        .Fields             = Fields
    };
};

struct ItemClassMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1140189,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0xA2EB4A48,
        .Fields             = Fields
    };
};

struct ItemContextPickerEntryMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1405665,
        .IndexField         = -1,
        .ParentIndexField   = 5,
        .FieldCount         = 6,
        .FileFieldCount     = 5,
        .LayoutHash         = 0x70D08611,
        .Fields             = Fields
    };
};

struct ItemCurrencyCostMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 801670,
        .IndexField         = -1,
        .ParentIndexField   = 0,
        .FieldCount         = 1,
        .FileFieldCount     = 1,
        .LayoutHash         = 0xA1F65D6B,
        .Fields             = Fields
    };
};

struct ItemDamageAmmoMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  7, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1277740,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x56F30531,
        .Fields             = Fields
    };
};

struct ItemDamageOneHandMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  7, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1277743,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x56F30531,
        .Fields             = Fields
    };
};

struct ItemDamageOneHandCasterMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  7, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1277739,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x56F30531,
        .Fields             = Fields
    };
};

struct ItemDamageRangedMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  7, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 6156256,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x56F30531,
        .Fields             = Fields
    };
};

struct ItemDamageThrownMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  7, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 6156257,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x56F30531,
        .Fields             = Fields
    };
};

struct ItemDamageTwoHandMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  7, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1277738,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x56F30531,
        .Fields             = Fields
    };
};

struct ItemDamageTwoHandCasterMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  7, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1277742,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x56F30531,
        .Fields             = Fields
    };
};

struct ItemDamageWandMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  7, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 6156258,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x56F30531,
        .Fields             = Fields
    };
};

struct ItemDisenchantLootMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1134087,
        .IndexField         = -1,
        .ParentIndexField   = 6,
        .FieldCount         = 7,
        .FileFieldCount     = 6,
        .LayoutHash         = 0x5845A4AA,
        .Fields             = Fields
    };
};

struct ItemDisplayInfoMeta
{
    static constexpr DB2MetaField Fields[16] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  2, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  2, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  2, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  6, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  6, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  2, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1266429,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 16,
        .FileFieldCount     = 16,
        .LayoutHash         = 0x9F3AB8A9,
        .Fields             = Fields
    };
};

struct ItemDisplayInfoMaterialResMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1280614,
        .IndexField         = -1,
        .ParentIndexField   = 2,
        .FieldCount         = 3,
        .FileFieldCount     = 2,
        .LayoutHash         = 0xAA462C0E,
        .Fields             = Fields
    };
};

struct ItemDisplayInfoModelMatResMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 4050937,
        .IndexField         = -1,
        .ParentIndexField   = 3,
        .FieldCount         = 4,
        .FileFieldCount     = 3,
        .LayoutHash         = 0x52510D63,
        .Fields             = Fields
    };
};

struct ItemEffectMeta
{
    static constexpr DB2MetaField Fields[9] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 969941,
        .IndexField         = -1,
        .ParentIndexField   = 8,
        .FieldCount         = 9,
        .FileFieldCount     = 8,
        .LayoutHash         = 0xEB717848,
        .Fields             = Fields
    };
};

struct ItemExtendedCostMeta
{
    static constexpr DB2MetaField Fields[10] =
    {
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  5, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  5, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  5, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  5, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 801681,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 10,
        .FileFieldCount     = 10,
        .LayoutHash         = 0xD2894EC8,
        .Fields             = Fields
    };
};

struct ItemGroupSoundsMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { .Type = FT_INT,                  .ArraySize =  4, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1283023,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 1,
        .FileFieldCount     = 1,
        .LayoutHash         = 0xA7CEF530,
        .Fields             = Fields
    };
};

struct ItemLevelSelectorMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1588911,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x3FC77064,
        .Fields             = Fields
    };
};

struct ItemLevelSelectorQualityMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1624937,
        .IndexField         = -1,
        .ParentIndexField   = 2,
        .FieldCount         = 3,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x3016B2C0,
        .Fields             = Fields
    };
};

struct ItemLevelSelectorQualitySetMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1624933,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x6EF696F8,
        .Fields             = Fields
    };
};

struct ItemLimitCategoryMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1237440,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0x22467A2D,
        .Fields             = Fields
    };
};

struct ItemLimitCategoryConditionMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1378590,
        .IndexField         = -1,
        .ParentIndexField   = 2,
        .FieldCount         = 3,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x8DC9459D,
        .Fields             = Fields
    };
};

struct ItemModifiedAppearanceMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 982457,
        .IndexField         = 0,
        .ParentIndexField   = 1,
        .FieldCount         = 7,
        .FileFieldCount     = 7,
        .LayoutHash         = 0x03A6C979,
        .Fields             = Fields
    };
};

struct ItemModifiedAppearanceExtraMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1278399,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 5,
        .FileFieldCount     = 5,
        .LayoutHash         = 0x5F7C0B7F,
        .Fields             = Fields
    };
};

struct ItemNameDescriptionMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1332559,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0xB616608D,
        .Fields             = Fields
    };
};

struct ItemPetFoodMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1302240,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 1,
        .FileFieldCount     = 1,
        .LayoutHash         = 0xDAD218A6,
        .Fields             = Fields
    };
};

struct ItemPriceBaseMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1121231,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0x9AD504F0,
        .Fields             = Fields
    };
};

struct ItemRandomPropertiesMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  5, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1237441,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x3FB9ECA3,
        .Fields             = Fields
    };
};

struct ItemRandomSuffixMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  5, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  5, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1237592,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0x4C5DE61E,
        .Fields             = Fields
    };
};

struct ItemRangedDisplayInfoMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1270315,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0x16D5D0A7,
        .Fields             = Fields
    };
};

struct ItemReforgeMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 5633983,
        .IndexField         = 0,
        .ParentIndexField   = -1,
        .FieldCount         = 6,
        .FileFieldCount     = 6,
        .LayoutHash         = 0xF56D7AF0,
        .Fields             = Fields
    };
};

struct ItemSearchNameMeta
{
    static constexpr DB2MetaField Fields[14] =
    {
        { .Type = FT_LONG,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  5, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1273408,
        .IndexField         = 2,
        .ParentIndexField   = -1,
        .FieldCount         = 14,
        .FileFieldCount     = 14,
        .LayoutHash         = 0x43F60F2E,
        .Fields             = Fields
    };
};

struct ItemSetMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize = 17, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1343609,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 5,
        .FileFieldCount     = 5,
        .LayoutHash         = 0xEEB090F4,
        .Fields             = Fields
    };
};

struct ItemSetSpellMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1314689,
        .IndexField         = -1,
        .ParentIndexField   = 3,
        .FieldCount         = 4,
        .FileFieldCount     = 3,
        .LayoutHash         = 0xCDEF234D,
        .Fields             = Fields
    };
};

struct ItemSparseMeta
{
    static constexpr DB2MetaField Fields[74] =
    {
        { .Type = FT_LONG,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize = 10, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize = 10, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize = 10, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize = 10, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  5, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  2, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  5, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  5, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  7, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize = 10, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  3, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1572924,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 74,
        .FileFieldCount     = 74,
        .LayoutHash         = 0x8F14EAC7,
        .Fields             = Fields
    };
};

struct ItemSpecMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1135120,
        .IndexField         = -1,
        .ParentIndexField   = 2,
        .FieldCount         = 6,
        .FileFieldCount     = 6,
        .LayoutHash         = 0x83F3D113,
        .Fields             = Fields
    };
};

struct ItemSpecOverrideMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1134576,
        .IndexField         = -1,
        .ParentIndexField   = 1,
        .FieldCount         = 2,
        .FileFieldCount     = 1,
        .LayoutHash         = 0xB292998C,
        .Fields             = Fields
    };
};

struct ItemSubClassMeta
{
    static constexpr DB2MetaField Fields[11] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1261604,
        .IndexField         = 2,
        .ParentIndexField   = 3,
        .FieldCount         = 11,
        .FileFieldCount     = 11,
        .LayoutHash         = 0x1E67DB87,
        .Fields             = Fields
    };
};

struct ItemSubClassMaskMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1302852,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0xD1A996F3,
        .Fields             = Fields
    };
};

struct ItemUpgradeMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 801687,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 5,
        .FileFieldCount     = 5,
        .LayoutHash         = 0xC034A392,
        .Fields             = Fields
    };
};

struct ItemVisualsMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { .Type = FT_INT,                  .ArraySize =  5, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1343605,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 1,
        .FileFieldCount     = 1,
        .LayoutHash         = 0x4E9F1674,
        .Fields             = Fields
    };
};

struct ItemVisualsXEffectMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 3043873,
        .IndexField         = -1,
        .ParentIndexField   = 5,
        .FieldCount         = 6,
        .FileFieldCount     = 5,
        .LayoutHash         = 0x62F4C094,
        .Fields             = Fields
    };
};

struct ItemXBonusTreeMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 987133,
        .IndexField         = -1,
        .ParentIndexField   = 1,
        .FieldCount         = 2,
        .FileFieldCount     = 1,
        .LayoutHash         = 0x5A99E55B,
        .Fields             = Fields
    };
};

struct JournalEncounterMeta
{
    static constexpr DB2MetaField Fields[12] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  2, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1240336,
        .IndexField         = 3,
        .ParentIndexField   = -1,
        .FieldCount         = 12,
        .FileFieldCount     = 12,
        .LayoutHash         = 0xB88D11CC,
        .Fields             = Fields
    };
};

struct JournalEncounterCreatureMeta
{
    static constexpr DB2MetaField Fields[8] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1301155,
        .IndexField         = 2,
        .ParentIndexField   = 3,
        .FieldCount         = 8,
        .FileFieldCount     = 8,
        .LayoutHash         = 0x81A3C769,
        .Fields             = Fields
    };
};

struct JournalEncounterItemMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1344467,
        .IndexField         = 0,
        .ParentIndexField   = 1,
        .FieldCount         = 7,
        .FileFieldCount     = 7,
        .LayoutHash         = 0xBEA0FECD,
        .Fields             = Fields
    };
};

struct JournalEncounterSectionMeta
{
    static constexpr DB2MetaField Fields[15] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1134413,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 15,
        .FileFieldCount     = 15,
        .LayoutHash         = 0xCB88312B,
        .Fields             = Fields
    };
};

struct JournalEncounterXDifficultyMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1121901,
        .IndexField         = -1,
        .ParentIndexField   = 1,
        .FieldCount         = 2,
        .FileFieldCount     = 1,
        .LayoutHash         = 0x1E14364D,
        .Fields             = Fields
    };
};

struct JournalEncounterXMapLocMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_FLOAT,                .ArraySize =  2, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1722928,
        .IndexField         = -1,
        .ParentIndexField   = 4,
        .FieldCount         = 5,
        .FileFieldCount     = 4,
        .LayoutHash         = 0x330EE16F,
        .Fields             = Fields
    };
};

struct JournalInstanceMeta
{
    static constexpr DB2MetaField Fields[9] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1237438,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 9,
        .FileFieldCount     = 9,
        .LayoutHash         = 0x811ABB6A,
        .Fields             = Fields
    };
};

struct JournalInstanceEntranceMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_FLOAT,                .ArraySize =  3, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 5228481,
        .IndexField         = -1,
        .ParentIndexField   = 4,
        .FieldCount         = 5,
        .FileFieldCount     = 4,
        .LayoutHash         = 0x874E7CC2,
        .Fields             = Fields
    };
};

struct JournalInstanceQueueLocMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { .Type = FT_FLOAT,                .ArraySize =  3, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 5228217,
        .IndexField         = -1,
        .ParentIndexField   = 5,
        .FieldCount         = 6,
        .FileFieldCount     = 5,
        .LayoutHash         = 0x1ADDCB9D,
        .Fields             = Fields
    };
};

struct JournalItemXDifficultyMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1277744,
        .IndexField         = -1,
        .ParentIndexField   = 1,
        .FieldCount         = 2,
        .FileFieldCount     = 1,
        .LayoutHash         = 0x6F46EEA2,
        .Fields             = Fields
    };
};

struct JournalSectionXDifficultyMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1121900,
        .IndexField         = -1,
        .ParentIndexField   = 1,
        .FieldCount         = 2,
        .FileFieldCount     = 1,
        .LayoutHash         = 0x6CF791BA,
        .Fields             = Fields
    };
};

struct JournalTierMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1349056,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 1,
        .FileFieldCount     = 1,
        .LayoutHash         = 0xCA44F886,
        .Fields             = Fields
    };
};

struct JournalTierXInstanceMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1285009,
        .IndexField         = -1,
        .ParentIndexField   = 0,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0xBFCBF1F0,
        .Fields             = Fields
    };
};

struct KeychainMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { .Type = FT_BYTE,                 .ArraySize = 32, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 801693,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 1,
        .FileFieldCount     = 1,
        .LayoutHash         = 0x019E306C,
        .Fields             = Fields
    };
};

struct KeystoneAffixMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1344761,
        .IndexField         = 2,
        .ParentIndexField   = -1,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0x63C870B5,
        .Fields             = Fields
    };
};

struct LFGDungeonExpansionMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1343606,
        .IndexField         = -1,
        .ParentIndexField   = 6,
        .FieldCount         = 7,
        .FileFieldCount     = 6,
        .LayoutHash         = 0x5040432F,
        .Fields             = Fields
    };
};

struct LFGDungeonGroupMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1135058,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0x920DFF98,
        .Fields             = Fields
    };
};

struct LFGDungeonsMeta
{
    static constexpr DB2MetaField Fields[36] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  2, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1361033,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 36,
        .FileFieldCount     = 36,
        .LayoutHash         = 0x4E41E52A,
        .Fields             = Fields
    };
};

struct LFGRoleRequirementMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 982805,
        .IndexField         = -1,
        .ParentIndexField   = 2,
        .FieldCount         = 3,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x8D26EA6B,
        .Fields             = Fields
    };
};

struct LanguageWordsMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 984702,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x07F670AA,
        .Fields             = Fields
    };
};

struct LanguagesMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1135325,
        .IndexField         = 1,
        .ParentIndexField   = -1,
        .FieldCount         = 6,
        .FileFieldCount     = 6,
        .LayoutHash         = 0xD259DA42,
        .Fields             = Fields
    };
};

struct LfgDungeonsGroupingMapMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1339818,
        .IndexField         = -1,
        .ParentIndexField   = 2,
        .FieldCount         = 3,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x105EA15A,
        .Fields             = Fields
    };
};

struct LightMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_FLOAT,                .ArraySize =  3, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  8, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1375579,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 5,
        .FileFieldCount     = 5,
        .LayoutHash         = 0x5F16BC84,
        .Fields             = Fields
    };
};

struct LightDataMeta
{
    static constexpr DB2MetaField Fields[46] =
    {
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  4, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  4, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  4, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1375580,
        .IndexField         = -1,
        .ParentIndexField   = 0,
        .FieldCount         = 46,
        .FileFieldCount     = 46,
        .LayoutHash         = 0x70C6CD80,
        .Fields             = Fields
    };
};

struct LightParamsMeta
{
    static constexpr DB2MetaField Fields[17] =
    {
        { .Type = FT_FLOAT,                .ArraySize =  3, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  3, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1334669,
        .IndexField         = 2,
        .ParentIndexField   = -1,
        .FieldCount         = 17,
        .FileFieldCount     = 17,
        .LayoutHash         = 0x51C96BAD,
        .Fields             = Fields
    };
};

struct LightParamsLightShaftMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 5350588,
        .IndexField         = -1,
        .ParentIndexField   = 2,
        .FieldCount         = 3,
        .FileFieldCount     = 2,
        .LayoutHash         = 0xFBB113FA,
        .Fields             = Fields
    };
};

struct LightShaftMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 5350589,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0xC22F4FD9,
        .Fields             = Fields
    };
};

struct LightSkyboxMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1308501,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0x407FEBCF,
        .Fields             = Fields
    };
};

struct LightWorldShadowMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 4680119,
        .IndexField         = -1,
        .ParentIndexField   = 2,
        .FieldCount         = 3,
        .FileFieldCount     = 2,
        .LayoutHash         = 0xA909CB00,
        .Fields             = Fields
    };
};

struct LightningMeta
{
    static constexpr DB2MetaField Fields[34] =
    {
        { .Type = FT_FLOAT,                .ArraySize =  2, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  3, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 2003383,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 34,
        .FileFieldCount     = 34,
        .LayoutHash         = 0x645F11FD,
        .Fields             = Fields
    };
};

struct LiquidMaterialMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1132538,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x98E5D7AA,
        .Fields             = Fields
    };
};

struct LiquidObjectMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1308058,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 5,
        .FileFieldCount     = 5,
        .LayoutHash         = 0xCB0D39E8,
        .Fields             = Fields
    };
};

struct LiquidTypeMeta
{
    static constexpr DB2MetaField Fields[21] =
    {
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  6, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  6, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  2, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize = 18, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  4, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  4, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1371380,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 21,
        .FileFieldCount     = 21,
        .LayoutHash         = 0x4397CEE6,
        .Fields             = Fields
    };
};

struct LiquidTypeXTextureMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 2261065,
        .IndexField         = -1,
        .ParentIndexField   = 3,
        .FieldCount         = 4,
        .FileFieldCount     = 3,
        .LayoutHash         = 0x7BEECC7F,
        .Fields             = Fields
    };
};

struct LoadingScreenTaxiSplinesMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize = 10, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize = 10, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1302239,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 5,
        .FileFieldCount     = 5,
        .LayoutHash         = 0x7B0D052E,
        .Fields             = Fields
    };
};

struct LoadingScreensMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1266541,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0xA28F3422,
        .Fields             = Fields
    };
};

struct LocaleMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 801706,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0xD82F8985,
        .Fields             = Fields
    };
};

struct LocationMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_FLOAT,                .ArraySize =  3, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  3, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 801707,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0xD18A3880,
        .Fields             = Fields
    };
};

struct LockMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_INT,                  .ArraySize =  8, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  8, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  8, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  8, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1343608,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0x8FA7E48A,
        .Fields             = Fields
    };
};

struct LockTypeMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1284823,
        .IndexField         = 4,
        .ParentIndexField   = -1,
        .FieldCount         = 5,
        .FileFieldCount     = 5,
        .LayoutHash         = 0x9687001F,
        .Fields             = Fields
    };
};

struct LookAtControllerMeta
{
    static constexpr DB2MetaField Fields[18] =
    {
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1098785,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 18,
        .FileFieldCount     = 18,
        .LayoutHash         = 0x92FF222C,
        .Fields             = Fields
    };
};

struct MailTemplateMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1240344,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 1,
        .FileFieldCount     = 1,
        .LayoutHash         = 0xB436C1C8,
        .Fields             = Fields
    };
};

struct ManagedWorldStateMeta
{
    static constexpr DB2MetaField Fields[10] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  4, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1587159,
        .IndexField         = 0,
        .ParentIndexField   = -1,
        .FieldCount         = 10,
        .FileFieldCount     = 10,
        .LayoutHash         = 0xFD996676,
        .Fields             = Fields
    };
};

struct ManagedWorldStateBuffMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1587155,
        .IndexField         = -1,
        .ParentIndexField   = 3,
        .FieldCount         = 4,
        .FileFieldCount     = 3,
        .LayoutHash         = 0xB8C3D344,
        .Fields             = Fields
    };
};

struct ManagedWorldStateInputMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1587151,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0x16683306,
        .Fields             = Fields
    };
};

struct ManifestInterfaceActionIconMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1375803,
        .IndexField         = 0,
        .ParentIndexField   = -1,
        .FieldCount         = 1,
        .FileFieldCount     = 1,
        .LayoutHash         = 0xF2103A31,
        .Fields             = Fields
    };
};

struct ManifestInterfaceDataMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1375801,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x618AD009,
        .Fields             = Fields
    };
};

struct ManifestInterfaceItemIconMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1375804,
        .IndexField         = 0,
        .ParentIndexField   = -1,
        .FieldCount         = 1,
        .FileFieldCount     = 1,
        .LayoutHash         = 0xF2103A31,
        .Fields             = Fields
    };
};

struct ManifestInterfaceTOCDataMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1267335,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 1,
        .FileFieldCount     = 1,
        .LayoutHash         = 0x4AB64495,
        .Fields             = Fields
    };
};

struct MapMeta
{
    static constexpr DB2MetaField Fields[23] =
    {
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  3, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1349477,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 23,
        .FileFieldCount     = 23,
        .LayoutHash         = 0x32401DC5,
        .Fields             = Fields
    };
};

struct MapCelestialBodyMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1597466,
        .IndexField         = -1,
        .ParentIndexField   = 2,
        .FieldCount         = 3,
        .FileFieldCount     = 2,
        .LayoutHash         = 0xA320FA08,
        .Fields             = Fields
    };
};

struct MapChallengeModeMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  3, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 801709,
        .IndexField         = 1,
        .ParentIndexField   = 2,
        .FieldCount         = 7,
        .FileFieldCount     = 7,
        .LayoutHash         = 0xC31A3CC1,
        .Fields             = Fields
    };
};

struct MapChallengeModeAffixCriteriaMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 6374834,
        .IndexField         = -1,
        .ParentIndexField   = 0,
        .FieldCount         = 5,
        .FileFieldCount     = 5,
        .LayoutHash         = 0xEC0A9905,
        .Fields             = Fields
    };
};

struct MapDifficultyMeta
{
    static constexpr DB2MetaField Fields[12] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1367868,
        .IndexField         = 1,
        .ParentIndexField   = 11,
        .FieldCount         = 12,
        .FileFieldCount     = 11,
        .LayoutHash         = 0xCF621FA3,
        .Fields             = Fields
    };
};

struct MapDifficultyRedirectMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 4913557,
        .IndexField         = -1,
        .ParentIndexField   = 2,
        .FieldCount         = 3,
        .FileFieldCount     = 2,
        .LayoutHash         = 0xD5D43631,
        .Fields             = Fields
    };
};

struct MapDifficultyXConditionMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1375435,
        .IndexField         = -1,
        .ParentIndexField   = 3,
        .FieldCount         = 4,
        .FileFieldCount     = 3,
        .LayoutHash         = 0xD514B4CA,
        .Fields             = Fields
    };
};

struct MapLoadingScreenMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_FLOAT,                .ArraySize =  2, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  2, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1719707,
        .IndexField         = -1,
        .ParentIndexField   = 4,
        .FieldCount         = 5,
        .FileFieldCount     = 4,
        .LayoutHash         = 0xB7151FA7,
        .Fields             = Fields
    };
};

struct MarketingPromotionsXLocaleMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 801710,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 7,
        .FileFieldCount     = 7,
        .LayoutHash         = 0xA76A6607,
        .Fields             = Fields
    };
};

struct MaterialMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1294217,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0x72533C7C,
        .Fields             = Fields
    };
};

struct MinorTalentMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1347274,
        .IndexField         = -1,
        .ParentIndexField   = 2,
        .FieldCount         = 3,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x6EF747EB,
        .Fields             = Fields
    };
};

struct MissileTargetingMeta
{
    static constexpr DB2MetaField Fields[12] =
    {
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  2, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  2, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1710117,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 12,
        .FileFieldCount     = 12,
        .LayoutHash         = 0x9492D27D,
        .Fields             = Fields
    };
};

struct ModelAnimCloakDampeningMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1465904,
        .IndexField         = -1,
        .ParentIndexField   = 2,
        .FieldCount         = 3,
        .FileFieldCount     = 2,
        .LayoutHash         = 0xF2AE9C79,
        .Fields             = Fields
    };
};

struct ModelFileDataMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1337833,
        .IndexField         = 0,
        .ParentIndexField   = 3,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0x66E0BE4F,
        .Fields             = Fields
    };
};

struct ModelRibbonQualityMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1399953,
        .IndexField         = -1,
        .ParentIndexField   = 1,
        .FieldCount         = 2,
        .FileFieldCount     = 1,
        .LayoutHash         = 0x6444FDE5,
        .Fields             = Fields
    };
};

struct ModelSoundTagEntryMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 5393277,
        .IndexField         = -1,
        .ParentIndexField   = 5,
        .FieldCount         = 6,
        .FileFieldCount     = 6,
        .LayoutHash         = 0x2DAEAE9D,
        .Fields             = Fields
    };
};

struct ModifiedCraftingSpellSlotMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 3390956,
        .IndexField         = -1,
        .ParentIndexField   = 0,
        .FieldCount         = 6,
        .FileFieldCount     = 6,
        .LayoutHash         = 0x00739B08,
        .Fields             = Fields
    };
};

struct ModifierTreeMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1267645,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 7,
        .FileFieldCount     = 7,
        .LayoutHash         = 0xE0CCCA58,
        .Fields             = Fields
    };
};

struct MountMeta
{
    static constexpr DB2MetaField Fields[11] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 921760,
        .IndexField         = 3,
        .ParentIndexField   = -1,
        .FieldCount         = 11,
        .FileFieldCount     = 11,
        .LayoutHash         = 0xDB77F653,
        .Fields             = Fields
    };
};

struct MountCapabilityMeta
{
    static constexpr DB2MetaField Fields[10] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1114709,
        .IndexField         = 0,
        .ParentIndexField   = -1,
        .FieldCount         = 10,
        .FileFieldCount     = 10,
        .LayoutHash         = 0x6B7A5ED2,
        .Fields             = Fields
    };
};

struct MountTypeMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize = 24, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1114674,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0xD7BB0C67,
        .Fields             = Fields
    };
};

struct MountTypeXCapabilityMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1114715,
        .IndexField         = -1,
        .ParentIndexField   = 0,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0x218BBE7F,
        .Fields             = Fields
    };
};

struct MountXDisplayMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1576117,
        .IndexField         = -1,
        .ParentIndexField   = 3,
        .FieldCount         = 4,
        .FileFieldCount     = 3,
        .LayoutHash         = 0xC05B05EF,
        .Fields             = Fields
    };
};

struct MovieMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1332556,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0x32E3E5C1,
        .Fields             = Fields
    };
};

struct MovieFileDataMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1301154,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 1,
        .FileFieldCount     = 1,
        .LayoutHash         = 0xA80F88DE,
        .Fields             = Fields
    };
};

struct MovieVariationMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1339819,
        .IndexField         = -1,
        .ParentIndexField   = 2,
        .FieldCount         = 3,
        .FileFieldCount     = 2,
        .LayoutHash         = 0xB5C17F58,
        .Fields             = Fields
    };
};

struct MultiStatePropertiesMeta
{
    static constexpr DB2MetaField Fields[11] =
    {
        { .Type = FT_FLOAT,                .ArraySize =  3, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1965592,
        .IndexField         = -1,
        .ParentIndexField   = 10,
        .FieldCount         = 11,
        .FileFieldCount     = 10,
        .LayoutHash         = 0x63E1D6FB,
        .Fields             = Fields
    };
};

struct MultiTransitionPropertiesMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1965589,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 5,
        .FileFieldCount     = 5,
        .LayoutHash         = 0xA20DA38D,
        .Fields             = Fields
    };
};

struct MusicOverrideMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 5161908,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0xD33F9337,
        .Fields             = Fields
    };
};

struct MythicPlusSeasonMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 2400282,
        .IndexField         = 0,
        .ParentIndexField   = -1,
        .FieldCount         = 5,
        .FileFieldCount     = 5,
        .LayoutHash         = 0xDC94262F,
        .Fields             = Fields
    };
};

struct MythicPlusSeasonKeyFloorMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 6684235,
        .IndexField         = -1,
        .ParentIndexField   = 2,
        .FieldCount         = 3,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x4033E02C,
        .Fields             = Fields
    };
};

struct MythicPlusSeasonRewardLevelsMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 2123783,
        .IndexField         = -1,
        .ParentIndexField   = 3,
        .FieldCount         = 4,
        .FileFieldCount     = 3,
        .LayoutHash         = 0x83142F7A,
        .Fields             = Fields
    };
};

struct MythicPlusSeasonTrackedAffixMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 4067473,
        .IndexField         = 0,
        .ParentIndexField   = 4,
        .FieldCount         = 5,
        .FileFieldCount     = 4,
        .LayoutHash         = 0xEFDAF463,
        .Fields             = Fields
    };
};

struct MythicPlusSeasonTrackedMapMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 4521365,
        .IndexField         = -1,
        .ParentIndexField   = 1,
        .FieldCount         = 2,
        .FileFieldCount     = 1,
        .LayoutHash         = 0x03958F0D,
        .Fields             = Fields
    };
};

struct NPCCraftingOrderCustomerMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 5875492,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 6,
        .FileFieldCount     = 6,
        .LayoutHash         = 0x4A3AC30B,
        .Fields             = Fields
    };
};

struct NPCCraftingOrderCustomerXLabelMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 5875493,
        .IndexField         = 0,
        .ParentIndexField   = 1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0xA5267D1B,
        .Fields             = Fields
    };
};

struct NPCCraftingOrderSetMeta
{
    static constexpr DB2MetaField Fields[11] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 5875494,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 11,
        .FileFieldCount     = 11,
        .LayoutHash         = 0xF05BCCBD,
        .Fields             = Fields
    };
};

struct NPCCraftingOrderSetXCraftOrderMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 5875495,
        .IndexField         = 0,
        .ParentIndexField   = 1,
        .FieldCount         = 6,
        .FileFieldCount     = 6,
        .LayoutHash         = 0x8CB4AEB8,
        .Fields             = Fields
    };
};

struct NPCCraftingOrderSetXCustomerMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 5875496,
        .IndexField         = 0,
        .ParentIndexField   = 2,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0x3464F1DD,
        .Fields             = Fields
    };
};

struct NPCCraftingOrderSetXTreasureMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 5912882,
        .IndexField         = -1,
        .ParentIndexField   = 3,
        .FieldCount         = 4,
        .FileFieldCount     = 3,
        .LayoutHash         = 0xCC093D65,
        .Fields             = Fields
    };
};

struct NPCModelItemSlotDisplayInfoMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1340661,
        .IndexField         = -1,
        .ParentIndexField   = 2,
        .FieldCount         = 3,
        .FileFieldCount     = 2,
        .LayoutHash         = 0xC2057F5B,
        .Fields             = Fields
    };
};

struct NPCSoundsMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { .Type = FT_INT,                  .ArraySize =  4, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1282621,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 1,
        .FileFieldCount     = 1,
        .LayoutHash         = 0x020BE1ED,
        .Fields             = Fields
    };
};

struct NameGenMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1122117,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0x3CA45193,
        .Fields             = Fields
    };
};

struct NamesProfanityMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1117086,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0xF227E638,
        .Fields             = Fields
    };
};

struct NamesReservedMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1117085,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 1,
        .FileFieldCount     = 1,
        .LayoutHash         = 0x2B2D5D97,
        .Fields             = Fields
    };
};

struct NamesReservedLocaleMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1117087,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x7B9823D4,
        .Fields             = Fields
    };
};

struct NumTalentsAtLevelMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1953326,
        .IndexField         = 0,
        .ParentIndexField   = -1,
        .FieldCount         = 5,
        .FileFieldCount     = 5,
        .LayoutHash         = 0x1B85660E,
        .Fields             = Fields
    };
};

struct ObjectEffectMeta
{
    static constexpr DB2MetaField Fields[8] =
    {
        { .Type = FT_FLOAT,                .ArraySize =  3, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1090577,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 8,
        .FileFieldCount     = 8,
        .LayoutHash         = 0x3471C362,
        .Fields             = Fields
    };
};

struct ObjectEffectModifierMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_FLOAT,                .ArraySize =  4, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1090575,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0x764AE63A,
        .Fields             = Fields
    };
};

struct ObjectEffectPackageElemMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1090578,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0x8AF314FA,
        .Fields             = Fields
    };
};

struct OccluderMeta
{
    static constexpr DB2MetaField Fields[9] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 2066958,
        .IndexField         = 0,
        .ParentIndexField   = -1,
        .FieldCount         = 9,
        .FileFieldCount     = 9,
        .LayoutHash         = 0x5B0B4934,
        .Fields             = Fields
    };
};

struct OccluderCurtainMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 3850529,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 6,
        .FileFieldCount     = 6,
        .LayoutHash         = 0xEA29F303,
        .Fields             = Fields
    };
};

struct OccluderLocationMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_FLOAT,                .ArraySize =  3, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  3, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 2115224,
        .IndexField         = 2,
        .ParentIndexField   = -1,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0xDE4869EE,
        .Fields             = Fields
    };
};

struct OccluderNodeMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 2066959,
        .IndexField         = 0,
        .ParentIndexField   = -1,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0x042B9E79,
        .Fields             = Fields
    };
};

struct OutlineEffectMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  2, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1279739,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 6,
        .FileFieldCount     = 6,
        .LayoutHash         = 0xD720BC0B,
        .Fields             = Fields
    };
};

struct OverrideSpellDataMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize = 10, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1002186,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0x96FFF958,
        .Fields             = Fields
    };
};

struct PVPBracketTypesMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  4, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1394275,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0xA3A33123,
        .Fields             = Fields
    };
};

struct PVPDifficultyMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1339820,
        .IndexField         = -1,
        .ParentIndexField   = 3,
        .FieldCount         = 4,
        .FileFieldCount     = 3,
        .LayoutHash         = 0x583BCBE4,
        .Fields             = Fields
    };
};

struct PVPItemMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 972287,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0xF812933C,
        .Fields             = Fields
    };
};

struct PageTextMaterialMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1271600,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 1,
        .FileFieldCount     = 1,
        .LayoutHash         = 0x728678A5,
        .Fields             = Fields
    };
};

struct PaperDollItemFrameMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1252503,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0xD45CB1FC,
        .Fields             = Fields
    };
};

struct ParagonReputationMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1581183,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0xD4AF2D4F,
        .Fields             = Fields
    };
};

struct ParticleColorMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  3, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  3, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  3, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1284820,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0xD58506F1,
        .Fields             = Fields
    };
};

struct ParticulateMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 3396285,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x458CF691,
        .Fields             = Fields
    };
};

struct ParticulateSoundMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 2053913,
        .IndexField         = -1,
        .ParentIndexField   = 0,
        .FieldCount         = 5,
        .FileFieldCount     = 5,
        .LayoutHash         = 0x2EE2C1E4,
        .Fields             = Fields
    };
};

struct PathMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 801732,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 7,
        .FileFieldCount     = 7,
        .LayoutHash         = 0xDF0EF640,
        .Fields             = Fields
    };
};

struct PathNodeMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 801733,
        .IndexField         = 0,
        .ParentIndexField   = -1,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0x042B9E79,
        .Fields             = Fields
    };
};

struct PathNodePropertyMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 801734,
        .IndexField         = 0,
        .ParentIndexField   = -1,
        .FieldCount         = 5,
        .FileFieldCount     = 5,
        .LayoutHash         = 0x2B340168,
        .Fields             = Fields
    };
};

struct PathPropertyMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 801735,
        .IndexField         = 0,
        .ParentIndexField   = -1,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0x8F9C7C98,
        .Fields             = Fields
    };
};

struct PetLoyaltyMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 2179604,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 1,
        .FileFieldCount     = 1,
        .LayoutHash         = 0xAD6104C6,
        .Fields             = Fields
    };
};

struct PetPersonalityMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_FLOAT,                .ArraySize =  3, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  3, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  3, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  8, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 2179609,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0x4736D6E1,
        .Fields             = Fields
    };
};

struct PhaseMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1348558,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 1,
        .FileFieldCount     = 1,
        .LayoutHash         = 0x6D5EB3BD,
        .Fields             = Fields
    };
};

struct PhaseShiftZoneSoundsMeta
{
    static constexpr DB2MetaField Fields[13] =
    {
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1267336,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 13,
        .FileFieldCount     = 13,
        .LayoutHash         = 0x3DC135AF,
        .Fields             = Fields
    };
};

struct PhaseXPhaseGroupMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 987581,
        .IndexField         = -1,
        .ParentIndexField   = 1,
        .FieldCount         = 2,
        .FileFieldCount     = 1,
        .LayoutHash         = 0xF3FF427F,
        .Fields             = Fields
    };
};

struct PingTypeMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 5152358,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 5,
        .FileFieldCount     = 5,
        .LayoutHash         = 0xE7C4153F,
        .Fields             = Fields
    };
};

struct PlayerCompanionInfoMeta
{
    static constexpr DB2MetaField Fields[11] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 5922429,
        .IndexField         = 0,
        .ParentIndexField   = -1,
        .FieldCount         = 11,
        .FileFieldCount     = 11,
        .LayoutHash         = 0x7E32E521,
        .Fields             = Fields
    };
};

struct PlayerConditionMeta
{
    static constexpr DB2MetaField Fields[86] =
    {
        { .Type = FT_LONG,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  4, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  4, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  4, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  3, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  3, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  4, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  4, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  4, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  4, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  4, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  4, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  2, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  2, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  4, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  4, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  4, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  4, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  4, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  4, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  4, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  4, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  4, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  6, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  2, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  4, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  4, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  4, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1045411,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 86,
        .FileFieldCount     = 86,
        .LayoutHash         = 0x91789B48,
        .Fields             = Fields
    };
};

struct PlayerDataElementAccountMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 5715394,
        .IndexField         = 0,
        .ParentIndexField   = -1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0x7F54ED49,
        .Fields             = Fields
    };
};

struct PlayerDataElementCharacterMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 5715395,
        .IndexField         = 0,
        .ParentIndexField   = -1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0x7F54ED49,
        .Fields             = Fields
    };
};

struct PlayerDataFlagAccountMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 5426706,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x23ECE2B1,
        .Fields             = Fields
    };
};

struct PlayerDataFlagCharacterMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 5426708,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x23ECE2B1,
        .Fields             = Fields
    };
};

struct PlayerInteractionInfoMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 5346849,
        .IndexField         = 0,
        .ParentIndexField   = -1,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0xD40A8C49,
        .Fields             = Fields
    };
};

struct PointLightConditionMapMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 5735564,
        .IndexField         = -1,
        .ParentIndexField   = 0,
        .FieldCount         = 5,
        .FileFieldCount     = 5,
        .LayoutHash         = 0x57294411,
        .Fields             = Fields
    };
};

struct PositionerMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1251523,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0xE0D4FD55,
        .Fields             = Fields
    };
};

struct PositionerStateMeta
{
    static constexpr DB2MetaField Fields[8] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1251506,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 8,
        .FileFieldCount     = 8,
        .LayoutHash         = 0x9CDFBF30,
        .Fields             = Fields
    };
};

struct PositionerStateEntryMeta
{
    static constexpr DB2MetaField Fields[11] =
    {
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1251533,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 11,
        .FileFieldCount     = 11,
        .LayoutHash         = 0x855AA6BC,
        .Fields             = Fields
    };
};

struct PowerDisplayMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1332557,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 5,
        .FileFieldCount     = 5,
        .LayoutHash         = 0x613FAAFD,
        .Fields             = Fields
    };
};

struct PowerTypeMeta
{
    static constexpr DB2MetaField Fields[13] =
    {
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1266022,
        .IndexField         = 2,
        .ParentIndexField   = -1,
        .FieldCount         = 13,
        .FileFieldCount     = 13,
        .LayoutHash         = 0x14BBEEA1,
        .Fields             = Fields
    };
};

struct PrestigeLevelInfoMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1275869,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 5,
        .FileFieldCount     = 5,
        .LayoutHash         = 0x6582638F,
        .Fields             = Fields
    };
};

struct ProfessionMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 4508544,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0xC2D5BEB1,
        .Fields             = Fields
    };
};

struct ProfessionEffectMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 4505297,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0x04C16FA9,
        .Fields             = Fields
    };
};

struct PvpRatingMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 4699082,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0x8B89647A,
        .Fields             = Fields
    };
};

struct PvpScalingEffectMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1591100,
        .IndexField         = -1,
        .ParentIndexField   = 1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0x295E05C1,
        .Fields             = Fields
    };
};

struct PvpScalingEffectTypeMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1591098,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 1,
        .FileFieldCount     = 1,
        .LayoutHash         = 0x21188F13,
        .Fields             = Fields
    };
};

struct PvpSeasonMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 2966426,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0xC2D9E52E,
        .Fields             = Fields
    };
};

struct PvpTalentMeta
{
    static constexpr DB2MetaField Fields[9] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1302853,
        .IndexField         = 1,
        .ParentIndexField   = 2,
        .FieldCount         = 9,
        .FileFieldCount     = 9,
        .LayoutHash         = 0x37611B53,
        .Fields             = Fields
    };
};

struct PvpTalentCategoryMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1891534,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 1,
        .FileFieldCount     = 1,
        .LayoutHash         = 0xECB2C5C2,
        .Fields             = Fields
    };
};

struct PvpTalentSlotUnlockMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1950197,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0x9685CBCC,
        .Fields             = Fields
    };
};

struct PvpTierMeta
{
    static constexpr DB2MetaField Fields[8] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 2066871,
        .IndexField         = -1,
        .ParentIndexField   = 5,
        .FieldCount         = 8,
        .FileFieldCount     = 8,
        .LayoutHash         = 0x8F30CD7C,
        .Fields             = Fields
    };
};

struct QuestDrivenScenarioMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 5917361,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0x408DD33F,
        .Fields             = Fields
    };
};

struct QuestFactionRewardMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { .Type = FT_SHORT,                .ArraySize = 10, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1282622,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 1,
        .FileFieldCount     = 1,
        .LayoutHash         = 0x221FFDAA,
        .Fields             = Fields
    };
};

struct QuestFeedbackEffectMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1343388,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 6,
        .FileFieldCount     = 6,
        .LayoutHash         = 0x092DE5FD,
        .Fields             = Fields
    };
};

struct QuestInfoMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1120960,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0xE505C927,
        .Fields             = Fields
    };
};

struct QuestLabelMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 5202058,
        .IndexField         = -1,
        .ParentIndexField   = 1,
        .FieldCount         = 2,
        .FileFieldCount     = 1,
        .LayoutHash         = 0x357F8064,
        .Fields             = Fields
    };
};

struct QuestLineMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 973430,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0x5675F41C,
        .Fields             = Fields
    };
};

struct QuestLineXQuestMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 973441,
        .IndexField         = -1,
        .ParentIndexField   = 0,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0x74023255,
        .Fields             = Fields
    };
};

struct QuestMoneyRewardMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { .Type = FT_INT,                  .ArraySize = 10, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1139047,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 1,
        .FileFieldCount     = 1,
        .LayoutHash         = 0x01D6219A,
        .Fields             = Fields
    };
};

struct QuestObjectiveMeta
{
    static constexpr DB2MetaField Fields[8] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1251960,
        .IndexField         = -1,
        .ParentIndexField   = 7,
        .FieldCount         = 8,
        .FileFieldCount     = 7,
        .LayoutHash         = 0x0262E5DB,
        .Fields             = Fields
    };
};

struct QuestPOIBlobMeta
{
    static constexpr DB2MetaField Fields[10] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1251882,
        .IndexField         = 0,
        .ParentIndexField   = 1,
        .FieldCount         = 10,
        .FileFieldCount     = 10,
        .LayoutHash         = 0xFDC814CF,
        .Fields             = Fields
    };
};

struct QuestPOIPointMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1251883,
        .IndexField         = 0,
        .ParentIndexField   = 4,
        .FieldCount         = 5,
        .FileFieldCount     = 4,
        .LayoutHash         = 0x5CBBEFE7,
        .Fields             = Fields
    };
};

struct QuestPackageItemMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 801743,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0xD54BB6BA,
        .Fields             = Fields
    };
};

struct QuestSortMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1134585,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0xADCB489B,
        .Fields             = Fields
    };
};

struct QuestV2Meta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1139443,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 1,
        .FileFieldCount     = 1,
        .LayoutHash         = 0x282AB79A,
        .Fields             = Fields
    };
};

struct QuestV2CliTaskMeta
{
    static constexpr DB2MetaField Fields[26] =
    {
        { .Type = FT_LONG,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  3, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  3, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1028735,
        .IndexField         = 3,
        .ParentIndexField   = -1,
        .FieldCount         = 26,
        .FileFieldCount     = 26,
        .LayoutHash         = 0xCB1396DA,
        .Fields             = Fields
    };
};

struct QuestXGroupActivityMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1573634,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0xD85CBF41,
        .Fields             = Fields
    };
};

struct QuestXPMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { .Type = FT_INT,                  .ArraySize = 10, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1139378,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 1,
        .FileFieldCount     = 1,
        .LayoutHash         = 0x7790D0EA,
        .Fields             = Fields
    };
};

struct RafActivityMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 3081207,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x99D8A8BB,
        .Fields             = Fields
    };
};

struct RandPropPointsMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  5, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  5, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  5, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1310245,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0x5DAD011D,
        .Fields             = Fields
    };
};

struct RelicSlotTierRequirementMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1716803,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0xA6DB0949,
        .Fields             = Fields
    };
};

struct RelicTalentMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1671256,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 5,
        .FileFieldCount     = 5,
        .LayoutHash         = 0x56CB54B7,
        .Fields             = Fields
    };
};

struct RenownRewardsMeta
{
    static constexpr DB2MetaField Fields[18] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 3743117,
        .IndexField         = -1,
        .ParentIndexField   = 3,
        .FieldCount         = 18,
        .FileFieldCount     = 18,
        .LayoutHash         = 0xBB3B0072,
        .Fields             = Fields
    };
};

struct RenownRewardsPlunderstormMeta
{
    static constexpr DB2MetaField Fields[8] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 5662591,
        .IndexField         = -1,
        .ParentIndexField   = 2,
        .FieldCount         = 8,
        .FileFieldCount     = 8,
        .LayoutHash         = 0x30F69B43,
        .Fields             = Fields
    };
};

struct ResearchBranchMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1133729,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 6,
        .FileFieldCount     = 6,
        .LayoutHash         = 0x6BB8E374,
        .Fields             = Fields
    };
};

struct ResearchFieldMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1133711,
        .IndexField         = 1,
        .ParentIndexField   = -1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0x75B20B30,
        .Fields             = Fields
    };
};

struct ResearchProjectMeta
{
    static constexpr DB2MetaField Fields[9] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1134090,
        .IndexField         = 2,
        .ParentIndexField   = -1,
        .FieldCount         = 9,
        .FileFieldCount     = 9,
        .LayoutHash         = 0x5702F5FF,
        .Fields             = Fields
    };
};

struct ResearchSiteMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1134091,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0xBD957EAB,
        .Fields             = Fields
    };
};

struct ResistancesMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1135072,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0xF7AC4E26,
        .Fields             = Fields
    };
};

struct RewardPackMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1307156,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 6,
        .FileFieldCount     = 6,
        .LayoutHash         = 0x5FABA92D,
        .Fields             = Fields
    };
};

struct RewardPackXCurrencyTypeMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1307153,
        .IndexField         = -1,
        .ParentIndexField   = 2,
        .FieldCount         = 3,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x160ED195,
        .Fields             = Fields
    };
};

struct RewardPackXItemMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1307155,
        .IndexField         = -1,
        .ParentIndexField   = 2,
        .FieldCount         = 3,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x8BE182DE,
        .Fields             = Fields
    };
};

struct RibbonQualityMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1398908,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 5,
        .FileFieldCount     = 5,
        .LayoutHash         = 0x21D24223,
        .Fields             = Fields
    };
};

struct RolodexTypeMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 5936950,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 1,
        .FileFieldCount     = 1,
        .LayoutHash         = 0x782EE721,
        .Fields             = Fields
    };
};

struct RulesetItemUpgradeMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 801749,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0xFD873767,
        .Fields             = Fields
    };
};

struct SDReplacementModelMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1712172,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 1,
        .FileFieldCount     = 1,
        .LayoutHash         = 0xA051D530,
        .Fields             = Fields
    };
};

struct SSAOSettingsMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 2056369,
        .IndexField         = 0,
        .ParentIndexField   = -1,
        .FieldCount         = 5,
        .FileFieldCount     = 5,
        .LayoutHash         = 0xFD35E147,
        .Fields             = Fields
    };
};

struct ScalingStatDistributionMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize = 10, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize = 10, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1141728,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 5,
        .FileFieldCount     = 5,
        .LayoutHash         = 0x68031639,
        .Fields             = Fields
    };
};

struct ScalingStatValuesMeta
{
    static constexpr DB2MetaField Fields[38] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  4, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  4, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  4, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  4, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  4, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  4, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  4, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  4, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 4719537,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 38,
        .FileFieldCount     = 38,
        .LayoutHash         = 0x8EDC6F8F,
        .Fields             = Fields
    };
};

struct ScenarioMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1139062,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 5,
        .FileFieldCount     = 5,
        .LayoutHash         = 0x1D56A4D5,
        .Fields             = Fields
    };
};

struct ScenarioEventEntryMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1141065,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0xF422AA1F,
        .Fields             = Fields
    };
};

struct ScenarioStepMeta
{
    static constexpr DB2MetaField Fields[12] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1132761,
        .IndexField         = 2,
        .ParentIndexField   = 3,
        .FieldCount         = 12,
        .FileFieldCount     = 12,
        .LayoutHash         = 0x00430C03,
        .Fields             = Fields
    };
};

struct SceneScriptMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 801754,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0x48BF6E91,
        .Fields             = Fields
    };
};

struct SceneScriptGlobalTextMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1758036,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x4A2C4981,
        .Fields             = Fields
    };
};

struct SceneScriptPackageMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 801755,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 1,
        .FileFieldCount     = 1,
        .LayoutHash         = 0xFDBC49B7,
        .Fields             = Fields
    };
};

struct SceneScriptPackageMemberMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 801756,
        .IndexField         = -1,
        .ParentIndexField   = 0,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0x0A4D9E92,
        .Fields             = Fields
    };
};

struct SceneScriptTextMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1758037,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x4A2C4981,
        .Fields             = Fields
    };
};

struct ScheduledIntervalMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1327082,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 5,
        .FileFieldCount     = 5,
        .LayoutHash         = 0xEA2984EC,
        .Fields             = Fields
    };
};

struct ScreenEffectMeta
{
    static constexpr DB2MetaField Fields[12] =
    {
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  4, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1302849,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 12,
        .FileFieldCount     = 12,
        .LayoutHash         = 0x014DC3B4,
        .Fields             = Fields
    };
};

struct ScreenEffectTypeMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 3063174,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 1,
        .FileFieldCount     = 1,
        .LayoutHash         = 0x5F754E48,
        .Fields             = Fields
    };
};

struct ScreenLocationMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1279416,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0xB5DB4956,
        .Fields             = Fields
    };
};

struct SeamlessSiteMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1328719,
        .IndexField         = -1,
        .ParentIndexField   = 0,
        .FieldCount         = 1,
        .FileFieldCount     = 1,
        .LayoutHash         = 0x5F662944,
        .Fields             = Fields
    };
};

struct ServerMessagesMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1301141,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 1,
        .FileFieldCount     = 1,
        .LayoutHash         = 0x022C43AA,
        .Fields             = Fields
    };
};

struct ShadowyEffectMeta
{
    static constexpr DB2MetaField Fields[13] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1239844,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 13,
        .FileFieldCount     = 13,
        .LayoutHash         = 0xCDD57428,
        .Fields             = Fields
    };
};

struct SharedStringMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 4620073,
        .IndexField         = 1,
        .ParentIndexField   = -1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0x02A60C13,
        .Fields             = Fields
    };
};

struct SiegeablePropertiesMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1954391,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0x444C6957,
        .Fields             = Fields
    };
};

struct SkillLineMeta
{
    static constexpr DB2MetaField Fields[13] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1240935,
        .IndexField         = 5,
        .ParentIndexField   = -1,
        .FieldCount         = 13,
        .FileFieldCount     = 13,
        .LayoutHash         = 0x1123150E,
        .Fields             = Fields
    };
};

struct SkillLineAbilityMeta
{
    static constexpr DB2MetaField Fields[16] =
    {
        { .Type = FT_LONG,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  2, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1266278,
        .IndexField         = 1,
        .ParentIndexField   = 2,
        .FieldCount         = 16,
        .FileFieldCount     = 16,
        .LayoutHash         = 0x738BFEE1,
        .Fields             = Fields
    };
};

struct SkillLineCategoryMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 2179610,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0xF61608B2,
        .Fields             = Fields
    };
};

struct SkillLineXTraitTreeMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 4505477,
        .IndexField         = -1,
        .ParentIndexField   = 0,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0x853B88D6,
        .Fields             = Fields
    };
};

struct SkillRaceClassInfoMeta
{
    static constexpr DB2MetaField Fields[8] =
    {
        { .Type = FT_LONG,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1240406,
        .IndexField         = -1,
        .ParentIndexField   = 1,
        .FieldCount         = 8,
        .FileFieldCount     = 8,
        .LayoutHash         = 0x78AC2343,
        .Fields             = Fields
    };
};

struct SkySceneXPlayerConditionMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 3581893,
        .IndexField         = -1,
        .ParentIndexField   = 1,
        .FieldCount         = 2,
        .FileFieldCount     = 1,
        .LayoutHash         = 0xB57B5277,
        .Fields             = Fields
    };
};

struct SoundAmbienceMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  2, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  2, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  2, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1310628,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 6,
        .FileFieldCount     = 6,
        .LayoutHash         = 0x3FBF2710,
        .Fields             = Fields
    };
};

struct SoundAmbienceFlavorMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1267065,
        .IndexField         = -1,
        .ParentIndexField   = 2,
        .FieldCount         = 3,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x34C96927,
        .Fields             = Fields
    };
};

struct SoundBusMeta
{
    static constexpr DB2MetaField Fields[8] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1310246,
        .IndexField         = 0,
        .ParentIndexField   = 7,
        .FieldCount         = 8,
        .FileFieldCount     = 7,
        .LayoutHash         = 0xA591AA63,
        .Fields             = Fields
    };
};

struct SoundBusOverrideMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1598732,
        .IndexField         = 0,
        .ParentIndexField   = 1,
        .FieldCount         = 7,
        .FileFieldCount     = 7,
        .LayoutHash         = 0x8D9C5CFE,
        .Fields             = Fields
    };
};

struct SoundEmitterPillPointsMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_FLOAT,                .ArraySize =  3, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1092317,
        .IndexField         = -1,
        .ParentIndexField   = 1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0xC937A96A,
        .Fields             = Fields
    };
};

struct SoundEmittersMeta
{
    static constexpr DB2MetaField Fields[12] =
    {
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  3, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  3, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1092316,
        .IndexField         = 3,
        .ParentIndexField   = 11,
        .FieldCount         = 12,
        .FileFieldCount     = 11,
        .LayoutHash         = 0xB09CDD89,
        .Fields             = Fields
    };
};

struct SoundEnvelopeMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1693131,
        .IndexField         = -1,
        .ParentIndexField   = 0,
        .FieldCount         = 7,
        .FileFieldCount     = 7,
        .LayoutHash         = 0xFA91357A,
        .Fields             = Fields
    };
};

struct SoundFilterMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1271601,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 1,
        .FileFieldCount     = 1,
        .LayoutHash         = 0x21188F13,
        .Fields             = Fields
    };
};

struct SoundFilterElemMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_FLOAT,                .ArraySize =  9, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1267066,
        .IndexField         = -1,
        .ParentIndexField   = 2,
        .FieldCount         = 3,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x7F024953,
        .Fields             = Fields
    };
};

struct SoundKitMeta
{
    static constexpr DB2MetaField Fields[17] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1237434,
        .IndexField         = 0,
        .ParentIndexField   = -1,
        .FieldCount         = 17,
        .FileFieldCount     = 17,
        .LayoutHash         = 0x2EB0F915,
        .Fields             = Fields
    };
};

struct SoundKitAdvancedMeta
{
    static constexpr DB2MetaField Fields[43] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1237436,
        .IndexField         = 0,
        .ParentIndexField   = -1,
        .FieldCount         = 43,
        .FileFieldCount     = 43,
        .LayoutHash         = 0xE61A9EE0,
        .Fields             = Fields
    };
};

struct SoundKitChildMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1307289,
        .IndexField         = -1,
        .ParentIndexField   = 1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x2927CB50,
        .Fields             = Fields
    };
};

struct SoundKitEntryMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1237435,
        .IndexField         = -1,
        .ParentIndexField   = 0,
        .FieldCount         = 5,
        .FileFieldCount     = 5,
        .LayoutHash         = 0x8F82FF7D,
        .Fields             = Fields
    };
};

struct SoundKitFallbackMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1307288,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x6EE7A367,
        .Fields             = Fields
    };
};

struct SoundMixGroupMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 4618887,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 5,
        .FileFieldCount     = 5,
        .LayoutHash         = 0x06BC7A80,
        .Fields             = Fields
    };
};

struct SoundOverrideMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1266542,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 5,
        .FileFieldCount     = 5,
        .LayoutHash         = 0x72095100,
        .Fields             = Fields
    };
};

struct SoundProviderPreferencesMeta
{
    static constexpr DB2MetaField Fields[23] =
    {
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1279417,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 23,
        .FileFieldCount     = 23,
        .LayoutHash         = 0x8FF22D98,
        .Fields             = Fields
    };
};

struct SoundWaterfallEmitterMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 4756178,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0xA0FC976E,
        .Fields             = Fields
    };
};

struct SourceInfoMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1313612,
        .IndexField         = -1,
        .ParentIndexField   = 3,
        .FieldCount         = 4,
        .FileFieldCount     = 3,
        .LayoutHash         = 0xB0BD8AE3,
        .Fields             = Fields
    };
};

struct SpamMessagesMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1117088,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 1,
        .FileFieldCount     = 1,
        .LayoutHash         = 0x5F2CCE2B,
        .Fields             = Fields
    };
};

struct SpecSetMemberMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 2057624,
        .IndexField         = -1,
        .ParentIndexField   = 1,
        .FieldCount         = 2,
        .FileFieldCount     = 1,
        .LayoutHash         = 0x504CA82E,
        .Fields             = Fields
    };
};

struct SpecializationSpellsMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1240335,
        .IndexField         = 1,
        .ParentIndexField   = 2,
        .FieldCount         = 6,
        .FileFieldCount     = 6,
        .LayoutHash         = 0xFA4367B5,
        .Fields             = Fields
    };
};

struct SpecializationSpellsDisplayMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  6, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 2067238,
        .IndexField         = -1,
        .ParentIndexField   = 0,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x60F7EE9A,
        .Fields             = Fields
    };
};

struct SpellMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1140089,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0xE3D134FB,
        .Fields             = Fields
    };
};

struct SpellActionBarPrefMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1019373,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x45039384,
        .Fields             = Fields
    };
};

struct SpellActivationOverlayMeta
{
    static constexpr DB2MetaField Fields[8] =
    {
        { .Type = FT_INT,                  .ArraySize =  4, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1261603,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 8,
        .FileFieldCount     = 8,
        .LayoutHash         = 0x66EFB31A,
        .Fields             = Fields
    };
};

struct SpellAuraOptionsMeta
{
    static constexpr DB2MetaField Fields[8] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  2, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1139952,
        .IndexField         = -1,
        .ParentIndexField   = 7,
        .FieldCount         = 8,
        .FileFieldCount     = 7,
        .LayoutHash         = 0x2760D1A1,
        .Fields             = Fields
    };
};

struct SpellAuraRestrictionsMeta
{
    static constexpr DB2MetaField Fields[10] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 981566,
        .IndexField         = -1,
        .ParentIndexField   = 9,
        .FieldCount         = 10,
        .FileFieldCount     = 9,
        .LayoutHash         = 0x6E11DD41,
        .Fields             = Fields
    };
};

struct SpellAuraVisXChrSpecMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1280615,
        .IndexField         = -1,
        .ParentIndexField   = 1,
        .FieldCount         = 2,
        .FileFieldCount     = 1,
        .LayoutHash         = 0x893DE38B,
        .Fields             = Fields
    };
};

struct SpellAuraVisXTalentTabMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 5634801,
        .IndexField         = -1,
        .ParentIndexField   = 1,
        .FieldCount         = 2,
        .FileFieldCount     = 1,
        .LayoutHash         = 0x0AD72CC2,
        .Fields             = Fields
    };
};

struct SpellAuraVisibilityMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1280616,
        .IndexField         = 0,
        .ParentIndexField   = 3,
        .FieldCount         = 4,
        .FileFieldCount     = 3,
        .LayoutHash         = 0xAA4D3429,
        .Fields             = Fields
    };
};

struct SpellCastTimesMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1134089,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0x5786BD00,
        .Fields             = Fields
    };
};

struct SpellCastingRequirementsMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1002166,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 7,
        .FileFieldCount     = 7,
        .LayoutHash         = 0xEB5F42A0,
        .Fields             = Fields
    };
};

struct SpellCategoriesMeta
{
    static constexpr DB2MetaField Fields[9] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1139939,
        .IndexField         = -1,
        .ParentIndexField   = 8,
        .FieldCount         = 9,
        .FileFieldCount     = 8,
        .LayoutHash         = 0x56C7533E,
        .Fields             = Fields
    };
};

struct SpellCategoryMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1280619,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 6,
        .FileFieldCount     = 6,
        .LayoutHash         = 0x1691EA31,
        .Fields             = Fields
    };
};

struct SpellChainEffectsMeta
{
    static constexpr DB2MetaField Fields[61] =
    {
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize = 11, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  3, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  3, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  3, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  3, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  3, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1343310,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 61,
        .FileFieldCount     = 61,
        .LayoutHash         = 0x3E3B28F5,
        .Fields             = Fields
    };
};

struct SpellClassOptionsMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  4, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 979663,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0xDFE6B427,
        .Fields             = Fields
    };
};

struct SpellCooldownsMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1139924,
        .IndexField         = -1,
        .ParentIndexField   = 5,
        .FieldCount         = 6,
        .FileFieldCount     = 5,
        .LayoutHash         = 0x1CD8296C,
        .Fields             = Fields
    };
};

struct SpellCraftUIMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 2620904,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 1,
        .FileFieldCount     = 1,
        .LayoutHash         = 0x5190ECA9,
        .Fields             = Fields
    };
};

struct SpellDescriptionVariablesMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1140004,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 1,
        .FileFieldCount     = 1,
        .LayoutHash         = 0x33868CFD,
        .Fields             = Fields
    };
};

struct SpellDispelTypeMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1137829,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0x47AA7AEB,
        .Fields             = Fields
    };
};

struct SpellDurationMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1137828,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0xBE65BD35,
        .Fields             = Fields
    };
};

struct SpellEffectMeta
{
    static constexpr DB2MetaField Fields[29] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  2, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  2, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  4, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  2, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1140088,
        .IndexField         = -1,
        .ParentIndexField   = 28,
        .FieldCount         = 29,
        .FileFieldCount     = 28,
        .LayoutHash         = 0x7F31EDF7,
        .Fields             = Fields
    };
};

struct SpellEffectAutoDescriptionMeta
{
    static constexpr DB2MetaField Fields[9] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1888495,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 9,
        .FileFieldCount     = 9,
        .LayoutHash         = 0xA42E28EC,
        .Fields             = Fields
    };
};

struct SpellEffectEmissionMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1310248,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0x164F4941,
        .Fields             = Fields
    };
};

struct SpellEquippedItemsMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1140011,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0xEB6AC546,
        .Fields             = Fields
    };
};

struct SpellFlyoutMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { .Type = FT_LONG,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1146819,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 6,
        .FileFieldCount     = 6,
        .LayoutHash         = 0x380879DE,
        .Fields             = Fields
    };
};

struct SpellFlyoutItemMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1134085,
        .IndexField         = -1,
        .ParentIndexField   = 2,
        .FieldCount         = 3,
        .FileFieldCount     = 2,
        .LayoutHash         = 0xCBAF7BE8,
        .Fields             = Fields
    };
};

struct SpellFocusObjectMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1280620,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 1,
        .FileFieldCount     = 1,
        .LayoutHash         = 0x782EE721,
        .Fields             = Fields
    };
};

struct SpellInterruptsMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  2, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  2, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1139906,
        .IndexField         = -1,
        .ParentIndexField   = 4,
        .FieldCount         = 5,
        .FileFieldCount     = 4,
        .LayoutHash         = 0x9C916E46,
        .Fields             = Fields
    };
};

struct SpellItemEnchantmentMeta
{
    static constexpr DB2MetaField Fields[22] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  3, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  3, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  3, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  3, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  3, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1362771,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 22,
        .FileFieldCount     = 22,
        .LayoutHash         = 0x876C6732,
        .Fields             = Fields
    };
};

struct SpellItemEnchantmentConditionMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  5, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  5, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  5, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  5, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  5, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  5, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1121834,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 6,
        .FileFieldCount     = 6,
        .LayoutHash         = 0xD5348137,
        .Fields             = Fields
    };
};

struct SpellKeyboundOverrideMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1127327,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0xFA067CB2,
        .Fields             = Fields
    };
};

struct SpellLabelMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1347275,
        .IndexField         = -1,
        .ParentIndexField   = 1,
        .FieldCount         = 2,
        .FileFieldCount     = 1,
        .LayoutHash         = 0x2B9F0138,
        .Fields             = Fields
    };
};

struct SpellLearnSpellMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1001907,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0x00CA7CE8,
        .Fields             = Fields
    };
};

struct SpellLevelsMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1140079,
        .IndexField         = -1,
        .ParentIndexField   = 5,
        .FieldCount         = 6,
        .FileFieldCount     = 5,
        .LayoutHash         = 0x98A2247E,
        .Fields             = Fields
    };
};

struct SpellMechanicMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1014438,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 1,
        .FileFieldCount     = 1,
        .LayoutHash         = 0x636442CA,
        .Fields             = Fields
    };
};

struct SpellMiscMeta
{
    static constexpr DB2MetaField Fields[14] =
    {
        { .Type = FT_INT,                  .ArraySize = 16, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1003144,
        .IndexField         = -1,
        .ParentIndexField   = 13,
        .FieldCount         = 14,
        .FileFieldCount     = 13,
        .LayoutHash         = 0x7902DF8B,
        .Fields             = Fields
    };
};

struct SpellMissileMeta
{
    static constexpr DB2MetaField Fields[15] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 897956,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 15,
        .FileFieldCount     = 15,
        .LayoutHash         = 0xEA25F580,
        .Fields             = Fields
    };
};

struct SpellMissileMotionMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 897955,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0x0200AB02,
        .Fields             = Fields
    };
};

struct SpellNameMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1990283,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 1,
        .FileFieldCount     = 1,
        .LayoutHash         = 0x782EE721,
        .Fields             = Fields
    };
};

struct SpellPowerMeta
{
    static constexpr DB2MetaField Fields[14] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 982806,
        .IndexField         = 0,
        .ParentIndexField   = 13,
        .FieldCount         = 14,
        .FileFieldCount     = 13,
        .LayoutHash         = 0xDFC24E8B,
        .Fields             = Fields
    };
};

struct SpellPowerDifficultyMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 982804,
        .IndexField         = 0,
        .ParentIndexField   = -1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0x5AA22CF5,
        .Fields             = Fields
    };
};

struct SpellProceduralEffectMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  4, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1140477,
        .IndexField         = 0,
        .ParentIndexField   = -1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0x6BA7487D,
        .Fields             = Fields
    };
};

struct SpellProcsPerMinuteMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1133526,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x93C5F6BB,
        .Fields             = Fields
    };
};

struct SpellProcsPerMinuteModMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1133525,
        .IndexField         = -1,
        .ParentIndexField   = 3,
        .FieldCount         = 4,
        .FileFieldCount     = 3,
        .LayoutHash         = 0x0DD2CE07,
        .Fields             = Fields
    };
};

struct SpellRadiusMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1134584,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0xF9A913EE,
        .Fields             = Fields
    };
};

struct SpellRangeMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  2, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  2, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1146820,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 5,
        .FileFieldCount     = 5,
        .LayoutHash         = 0xF2B48795,
        .Fields             = Fields
    };
};

struct SpellReagentsMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  8, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  8, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 841946,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0xC65EBB84,
        .Fields             = Fields
    };
};

struct SpellReagentsCurrencyMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1135239,
        .IndexField         = -1,
        .ParentIndexField   = 0,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0xF02FA4EB,
        .Fields             = Fields
    };
};

struct SpellScalingMeta
{
    static constexpr DB2MetaField Fields[10] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1139940,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 10,
        .FileFieldCount     = 10,
        .LayoutHash         = 0x695DA5D3,
        .Fields             = Fields
    };
};

struct SpellShapeshiftMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  2, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  2, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1139929,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0xE9111399,
        .Fields             = Fields
    };
};

struct SpellShapeshiftFormMeta
{
    static constexpr DB2MetaField Fields[11] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  4, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  8, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1280618,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 11,
        .FileFieldCount     = 11,
        .LayoutHash         = 0xAB5F718E,
        .Fields             = Fields
    };
};

struct SpellSpecialUnitEffectMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1268903,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0xDA6DFF4B,
        .Fields             = Fields
    };
};

struct SpellTargetRestrictionsMeta
{
    static constexpr DB2MetaField Fields[8] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1139993,
        .IndexField         = -1,
        .ParentIndexField   = 7,
        .FieldCount         = 8,
        .FileFieldCount     = 7,
        .LayoutHash         = 0x6CBAAD1E,
        .Fields             = Fields
    };
};

struct SpellTotemsMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  2, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  2, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1002162,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0x03B23619,
        .Fields             = Fields
    };
};

struct SpellVisualMeta
{
    static constexpr DB2MetaField Fields[18] =
    {
        { .Type = FT_FLOAT,                .ArraySize =  3, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  3, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 897952,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 18,
        .FileFieldCount     = 18,
        .LayoutHash         = 0x224A9435,
        .Fields             = Fields
    };
};

struct SpellVisualAnimMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1140479,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0xEE416568,
        .Fields             = Fields
    };
};

struct SpellVisualColorEffectMeta
{
    static constexpr DB2MetaField Fields[11] =
    {
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1094006,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 11,
        .FileFieldCount     = 11,
        .LayoutHash         = 0xDE73DDC8,
        .Fields             = Fields
    };
};

struct SpellVisualEffectNameMeta
{
    static constexpr DB2MetaField Fields[15] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 897948,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 15,
        .FileFieldCount     = 15,
        .LayoutHash         = 0xE273C4B7,
        .Fields             = Fields
    };
};

struct SpellVisualEventMeta
{
    static constexpr DB2MetaField Fields[9] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1685317,
        .IndexField         = -1,
        .ParentIndexField   = 8,
        .FieldCount         = 9,
        .FileFieldCount     = 8,
        .LayoutHash         = 0x89263837,
        .Fields             = Fields
    };
};

struct SpellVisualKitMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  2, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 897949,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 5,
        .FileFieldCount     = 5,
        .LayoutHash         = 0xB4A308CD,
        .Fields             = Fields
    };
};

struct SpellVisualKitAreaModelMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 897951,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 6,
        .FileFieldCount     = 6,
        .LayoutHash         = 0x0B45E5D4,
        .Fields             = Fields
    };
};

struct SpellVisualKitEffectMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1140480,
        .IndexField         = -1,
        .ParentIndexField   = 2,
        .FieldCount         = 3,
        .FileFieldCount     = 2,
        .LayoutHash         = 0xE3206CA2,
        .Fields             = Fields
    };
};

struct SpellVisualKitModelAttachMeta
{
    static constexpr DB2MetaField Fields[23] =
    {
        { .Type = FT_FLOAT,                .ArraySize =  3, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  3, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 897953,
        .IndexField         = 2,
        .ParentIndexField   = 22,
        .FieldCount         = 23,
        .FileFieldCount     = 22,
        .LayoutHash         = 0xE0FF7EAF,
        .Fields             = Fields
    };
};

struct SpellVisualMissileMeta
{
    static constexpr DB2MetaField Fields[17] =
    {
        { .Type = FT_FLOAT,                .ArraySize =  3, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  3, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 897954,
        .IndexField         = 2,
        .ParentIndexField   = 16,
        .FieldCount         = 17,
        .FileFieldCount     = 16,
        .LayoutHash         = 0x8130FDC9,
        .Fields             = Fields
    };
};

struct SpellXDescriptionVariablesMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1724949,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x23F4E51E,
        .Fields             = Fields
    };
};

struct SpellXSpellVisualMeta
{
    static constexpr DB2MetaField Fields[13] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1101657,
        .IndexField         = 0,
        .ParentIndexField   = 12,
        .FieldCount         = 13,
        .FileFieldCount     = 12,
        .LayoutHash         = 0x01147920,
        .Fields             = Fields
    };
};

struct SpotLightConditionMapMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 5735565,
        .IndexField         = -1,
        .ParentIndexField   = 0,
        .FieldCount         = 5,
        .FileFieldCount     = 5,
        .LayoutHash         = 0x04E3CAA3,
        .Fields             = Fields
    };
};

struct StableSlotPricesMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 2179613,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 1,
        .FileFieldCount     = 1,
        .LayoutHash         = 0x31ADFC89,
        .Fields             = Fields
    };
};

struct StartupFilesMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1604265,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0x3E639C9F,
        .Fields             = Fields
    };
};

struct Startup_StringsMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1375805,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0xD758674F,
        .Fields             = Fields
    };
};

struct StationeryMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  2, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1140758,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0xF075ED96,
        .Fields             = Fields
    };
};

struct SummonPropertiesMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  2, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1345276,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 5,
        .FileFieldCount     = 5,
        .LayoutHash         = 0xA4CA5ECF,
        .Fields             = Fields
    };
};

struct TactKeyMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { .Type = FT_BYTE,                 .ArraySize = 16, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1302850,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 1,
        .FileFieldCount     = 1,
        .LayoutHash         = 0xCBA490FC,
        .Fields             = Fields
    };
};

struct TactKeyLookupMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  8, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1302851,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 1,
        .FileFieldCount     = 1,
        .LayoutHash         = 0x4983962C,
        .Fields             = Fields
    };
};

struct TalentMeta
{
    static constexpr DB2MetaField Fields[14] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  2, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  9, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  3, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  3, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1369062,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 14,
        .FileFieldCount     = 14,
        .LayoutHash         = 0x50A76955,
        .Fields             = Fields
    };
};

struct TalentTabMeta
{
    static constexpr DB2MetaField Fields[10] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  2, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 2178102,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 10,
        .FileFieldCount     = 10,
        .LayoutHash         = 0xB436F3C7,
        .Fields             = Fields
    };
};

struct TalentTreePrimarySpellsMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 5581887,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0x0C4D9DD6,
        .Fields             = Fields
    };
};

struct TaxiNodesMeta
{
    static constexpr DB2MetaField Fields[14] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  3, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  2, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  2, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  2, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1068100,
        .IndexField         = 4,
        .ParentIndexField   = 5,
        .FieldCount         = 14,
        .FileFieldCount     = 14,
        .LayoutHash         = 0xA8EF6D9C,
        .Fields             = Fields
    };
};

struct TaxiPathMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1067802,
        .IndexField         = 0,
        .ParentIndexField   = 1,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0xA303DE51,
        .Fields             = Fields
    };
};

struct TaxiPathNodeMeta
{
    static constexpr DB2MetaField Fields[9] =
    {
        { .Type = FT_FLOAT,                .ArraySize =  3, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1000437,
        .IndexField         = 1,
        .ParentIndexField   = 2,
        .FieldCount         = 9,
        .FileFieldCount     = 9,
        .LayoutHash         = 0xD086E620,
        .Fields             = Fields
    };
};

struct TerrainMaterialMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1307290,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0xE1D9583A,
        .Fields             = Fields
    };
};

struct TerrainTypeMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1310249,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 6,
        .FileFieldCount     = 6,
        .LayoutHash         = 0x980DBE0A,
        .Fields             = Fields
    };
};

struct TerrainTypeSoundsMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1284822,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 1,
        .FileFieldCount     = 1,
        .LayoutHash         = 0xB99F5777,
        .Fields             = Fields
    };
};

struct TextureBlendSetMeta
{
    static constexpr DB2MetaField Fields[11] =
    {
        { .Type = FT_INT,                  .ArraySize =  3, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  3, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  3, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  3, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  3, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  4, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1328721,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 11,
        .FileFieldCount     = 11,
        .LayoutHash         = 0x4A955778,
        .Fields             = Fields
    };
};

struct TextureFileDataMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 982459,
        .IndexField         = 0,
        .ParentIndexField   = 2,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0x50299C02,
        .Fields             = Fields
    };
};

struct TierTransitionMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 3076928,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0x2591A17F,
        .Fields             = Fields
    };
};

struct TotemCategoryMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1134586,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0x86C8149C,
        .Fields             = Fields
    };
};

struct ToyMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 988200,
        .IndexField         = 1,
        .ParentIndexField   = -1,
        .FieldCount         = 5,
        .FileFieldCount     = 5,
        .LayoutHash         = 0xC55DB9B0,
        .Fields             = Fields
    };
};

struct TradeSkillCategoryMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1301101,
        .IndexField         = 2,
        .ParentIndexField   = -1,
        .FieldCount         = 7,
        .FileFieldCount     = 7,
        .LayoutHash         = 0x2FFC30A4,
        .Fields             = Fields
    };
};

struct TradeSkillItemMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1329070,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0xD2CEC727,
        .Fields             = Fields
    };
};

struct TraitCondMeta
{
    static constexpr DB2MetaField Fields[17] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 4543085,
        .IndexField         = 0,
        .ParentIndexField   = 2,
        .FieldCount         = 17,
        .FileFieldCount     = 17,
        .LayoutHash         = 0xBFDD1994,
        .Fields             = Fields
    };
};

struct TraitCondAccountElementMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_LONG,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 5890759,
        .IndexField         = 1,
        .ParentIndexField   = 2,
        .FieldCount         = 5,
        .FileFieldCount     = 5,
        .LayoutHash         = 0xCC2EA83A,
        .Fields             = Fields
    };
};

struct TraitCostMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 4420295,
        .IndexField         = 1,
        .ParentIndexField   = -1,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0x35853DF0,
        .Fields             = Fields
    };
};

struct TraitCurrencyMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 4524216,
        .IndexField         = 0,
        .ParentIndexField   = -1,
        .FieldCount         = 5,
        .FileFieldCount     = 5,
        .LayoutHash         = 0x59214AB9,
        .Fields             = Fields
    };
};

struct TraitCurrencySourceMeta
{
    static constexpr DB2MetaField Fields[9] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 4539393,
        .IndexField         = 1,
        .ParentIndexField   = 2,
        .FieldCount         = 9,
        .FileFieldCount     = 9,
        .LayoutHash         = 0x3FE6D68D,
        .Fields             = Fields
    };
};

struct TraitDefinitionMeta
{
    static constexpr DB2MetaField Fields[8] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 4420327,
        .IndexField         = 3,
        .ParentIndexField   = -1,
        .FieldCount         = 8,
        .FileFieldCount     = 8,
        .LayoutHash         = 0x060A9F4C,
        .Fields             = Fields
    };
};

struct TraitDefinitionEffectPointsMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 4536895,
        .IndexField         = 0,
        .ParentIndexField   = 1,
        .FieldCount         = 5,
        .FileFieldCount     = 5,
        .LayoutHash         = 0x01AE39C2,
        .Fields             = Fields
    };
};

struct TraitEdgeMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 4420308,
        .IndexField         = 0,
        .ParentIndexField   = 2,
        .FieldCount         = 5,
        .FileFieldCount     = 5,
        .LayoutHash         = 0xD4EA9447,
        .Fields             = Fields
    };
};

struct TraitNodeMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 4420297,
        .IndexField         = 0,
        .ParentIndexField   = 1,
        .FieldCount         = 7,
        .FileFieldCount     = 7,
        .LayoutHash         = 0xA01A518A,
        .Fields             = Fields
    };
};

struct TraitNodeEntryMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 4420298,
        .IndexField         = 0,
        .ParentIndexField   = -1,
        .FieldCount         = 5,
        .FileFieldCount     = 5,
        .LayoutHash         = 0x733B015D,
        .Fields             = Fields
    };
};

struct TraitNodeEntryXTraitCondMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 4543088,
        .IndexField         = 0,
        .ParentIndexField   = 2,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0x59B38176,
        .Fields             = Fields
    };
};

struct TraitNodeEntryXTraitCostMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 4420299,
        .IndexField         = 0,
        .ParentIndexField   = 1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0xE87DE277,
        .Fields             = Fields
    };
};

struct TraitNodeGroupMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 4420300,
        .IndexField         = 0,
        .ParentIndexField   = 1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0xECA626BE,
        .Fields             = Fields
    };
};

struct TraitNodeGroupXTraitCondMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 4543090,
        .IndexField         = 0,
        .ParentIndexField   = 2,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0x3F06B639,
        .Fields             = Fields
    };
};

struct TraitNodeGroupXTraitCostMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 4420301,
        .IndexField         = 0,
        .ParentIndexField   = 1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0xFD4B937C,
        .Fields             = Fields
    };
};

struct TraitNodeGroupXTraitNodeMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 4420302,
        .IndexField         = 0,
        .ParentIndexField   = 1,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0xB9288EB8,
        .Fields             = Fields
    };
};

struct TraitNodeXTraitCondMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 4543092,
        .IndexField         = 0,
        .ParentIndexField   = 2,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0xE2160AA8,
        .Fields             = Fields
    };
};

struct TraitNodeXTraitCostMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 4420303,
        .IndexField         = 0,
        .ParentIndexField   = 1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0x4D8C0D05,
        .Fields             = Fields
    };
};

struct TraitNodeXTraitNodeEntryMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 4420304,
        .IndexField         = 0,
        .ParentIndexField   = 1,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0x802ED455,
        .Fields             = Fields
    };
};

struct TraitSubTreeMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 5534447,
        .IndexField         = 2,
        .ParentIndexField   = 4,
        .FieldCount         = 5,
        .FileFieldCount     = 5,
        .LayoutHash         = 0x716FF6FB,
        .Fields             = Fields
    };
};

struct TraitSystemMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 4635649,
        .IndexField         = 0,
        .ParentIndexField   = -1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0x46225291,
        .Fields             = Fields
    };
};

struct TraitTreeMeta
{
    static constexpr DB2MetaField Fields[8] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 4420305,
        .IndexField         = 0,
        .ParentIndexField   = 1,
        .FieldCount         = 8,
        .FileFieldCount     = 8,
        .LayoutHash         = 0xE0C67577,
        .Fields             = Fields
    };
};

struct TraitTreeLoadoutMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 4669507,
        .IndexField         = 0,
        .ParentIndexField   = 1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0x963A2972,
        .Fields             = Fields
    };
};

struct TraitTreeLoadoutEntryMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 4669509,
        .IndexField         = 0,
        .ParentIndexField   = 1,
        .FieldCount         = 6,
        .FileFieldCount     = 6,
        .LayoutHash         = 0xF17F8192,
        .Fields             = Fields
    };
};

struct TraitTreeXTraitCostMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 4420306,
        .IndexField         = 0,
        .ParentIndexField   = 1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0x19EEFE95,
        .Fields             = Fields
    };
};

struct TraitTreeXTraitCurrencyMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 4524218,
        .IndexField         = 0,
        .ParentIndexField   = 2,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0xE093CD62,
        .Fields             = Fields
    };
};

struct TransformMatrixMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_FLOAT,                .ArraySize =  3, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1338702,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 5,
        .FileFieldCount     = 5,
        .LayoutHash         = 0x45999148,
        .Fields             = Fields
    };
};

struct TransmogDefaultLevelMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 2399695,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0xF003EFFC,
        .Fields             = Fields
    };
};

struct TransmogHolidayMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1589454,
        .IndexField         = 0,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x1CF0A074,
        .Fields             = Fields
    };
};

struct TransmogIllusionMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 3580450,
        .IndexField         = 0,
        .ParentIndexField   = -1,
        .FieldCount         = 5,
        .FileFieldCount     = 5,
        .LayoutHash         = 0xDCE032AF,
        .Fields             = Fields
    };
};

struct TransmogSetMeta
{
    static constexpr DB2MetaField Fields[13] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1376213,
        .IndexField         = 1,
        .ParentIndexField   = 7,
        .FieldCount         = 13,
        .FileFieldCount     = 13,
        .LayoutHash         = 0xC6875C71,
        .Fields             = Fields
    };
};

struct TransmogSetGroupMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1576116,
        .IndexField         = 1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0xEBA8ED0E,
        .Fields             = Fields
    };
};

struct TransmogSetItemMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1376212,
        .IndexField         = 0,
        .ParentIndexField   = 1,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0x1330B84D,
        .Fields             = Fields
    };
};

struct TransportAnimationMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_FLOAT,                .ArraySize =  3, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1140686,
        .IndexField         = -1,
        .ParentIndexField   = 3,
        .FieldCount         = 4,
        .FileFieldCount     = 3,
        .LayoutHash         = 0xE622B105,
        .Fields             = Fields
    };
};

struct TransportPhysicsMeta
{
    static constexpr DB2MetaField Fields[10] =
    {
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1121973,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 10,
        .FileFieldCount     = 10,
        .LayoutHash         = 0xE05919AE,
        .Fields             = Fields
    };
};

struct TransportRotationMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_FLOAT,                .ArraySize =  4, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1140687,
        .IndexField         = -1,
        .ParentIndexField   = 2,
        .FieldCount         = 3,
        .FileFieldCount     = 2,
        .LayoutHash         = 0xD92B0C43,
        .Fields             = Fields
    };
};

struct TrophyMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 975024,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0x45761395,
        .Fields             = Fields
    };
};

struct UIArrowCalloutMeta
{
    static constexpr DB2MetaField Fields[9] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 5011999,
        .IndexField         = 2,
        .ParentIndexField   = -1,
        .FieldCount         = 9,
        .FileFieldCount     = 9,
        .LayoutHash         = 0x11F1EB32,
        .Fields             = Fields
    };
};

struct UIButtonMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 6237799,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 5,
        .FileFieldCount     = 5,
        .LayoutHash         = 0x88A0B057,
        .Fields             = Fields
    };
};

struct UICinematicIntroInfoMeta
{
    static constexpr DB2MetaField Fields[8] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 6155772,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 8,
        .FileFieldCount     = 8,
        .LayoutHash         = 0x44820FD5,
        .Fields             = Fields
    };
};

struct UIEventToastMeta
{
    static constexpr DB2MetaField Fields[22] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 3946498,
        .IndexField         = 6,
        .ParentIndexField   = -1,
        .FieldCount         = 22,
        .FileFieldCount     = 22,
        .LayoutHash         = 0xEF224D81,
        .Fields             = Fields
    };
};

struct UIExpansionDisplayInfoMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1729547,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0x0A72AD12,
        .Fields             = Fields
    };
};

struct UIExpansionDisplayInfoIconMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1729546,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0x54B6542E,
        .Fields             = Fields
    };
};

struct UIGenericWidgetDisplayMeta
{
    static constexpr DB2MetaField Fields[10] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 4861207,
        .IndexField         = 3,
        .ParentIndexField   = -1,
        .FieldCount         = 10,
        .FileFieldCount     = 10,
        .LayoutHash         = 0x712E00ED,
        .Fields             = Fields
    };
};

struct UIMapPinInfoMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 6237800,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 6,
        .FileFieldCount     = 6,
        .LayoutHash         = 0xE8E5C344,
        .Fields             = Fields
    };
};

struct UIScriptedAnimationEffectMeta
{
    static constexpr DB2MetaField Fields[27] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 3556601,
        .IndexField         = 0,
        .ParentIndexField   = -1,
        .FieldCount         = 27,
        .FileFieldCount     = 27,
        .LayoutHash         = 0x796691DB,
        .Fields             = Fields
    };
};

struct UiCamFbackTalkingHeadChrRaceMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 3055924,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0x0E6163DE,
        .Fields             = Fields
    };
};

struct UiCamFbackTransmogChrRaceMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1261406,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 5,
        .FileFieldCount     = 5,
        .LayoutHash         = 0xFFE702C7,
        .Fields             = Fields
    };
};

struct UiCamFbackTransmogWeaponMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1261407,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0xBDAFC2E9,
        .Fields             = Fields
    };
};

struct UiCameraMeta
{
    static constexpr DB2MetaField Fields[9] =
    {
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  3, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  3, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  3, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1120287,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 9,
        .FileFieldCount     = 9,
        .LayoutHash         = 0x2FD2C951,
        .Fields             = Fields
    };
};

struct UiCameraTypeMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1120288,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0xF315BDCB,
        .Fields             = Fields
    };
};

struct UiCanvasMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1989363,
        .IndexField         = 0,
        .ParentIndexField   = -1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0xC115A578,
        .Fields             = Fields
    };
};

struct UiMapMeta
{
    static constexpr DB2MetaField Fields[14] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1957206,
        .IndexField         = 1,
        .ParentIndexField   = 2,
        .FieldCount         = 14,
        .FileFieldCount     = 14,
        .LayoutHash         = 0x27E926D0,
        .Fields             = Fields
    };
};

struct UiMapArtMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1957202,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0x3AE7D144,
        .Fields             = Fields
    };
};

struct UiMapArtStyleLayerMeta
{
    static constexpr DB2MetaField Fields[9] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1957208,
        .IndexField         = -1,
        .ParentIndexField   = 8,
        .FieldCount         = 9,
        .FileFieldCount     = 8,
        .LayoutHash         = 0x3F597F5A,
        .Fields             = Fields
    };
};

struct UiMapArtTileMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1957210,
        .IndexField         = -1,
        .ParentIndexField   = 4,
        .FieldCount         = 5,
        .FileFieldCount     = 4,
        .LayoutHash         = 0x2DA5B77B,
        .Fields             = Fields
    };
};

struct UiMapAssignmentMeta
{
    static constexpr DB2MetaField Fields[10] =
    {
        { .Type = FT_FLOAT,                .ArraySize =  2, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  2, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  6, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1957219,
        .IndexField         = 3,
        .ParentIndexField   = 4,
        .FieldCount         = 10,
        .FileFieldCount     = 10,
        .LayoutHash         = 0xF9899D73,
        .Fields             = Fields
    };
};

struct UiMapFogOfWarMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 2006972,
        .IndexField         = 0,
        .ParentIndexField   = 1,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0xC42F6D05,
        .Fields             = Fields
    };
};

struct UiMapFogOfWarVisualizationMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 2006973,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0xD0E714A2,
        .Fields             = Fields
    };
};

struct UiMapGroupMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 6033745,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 1,
        .FileFieldCount     = 1,
        .LayoutHash         = 0x6D5EB3BD,
        .Fields             = Fields
    };
};

struct UiMapGroupMemberMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1957204,
        .IndexField         = -1,
        .ParentIndexField   = 1,
        .FieldCount         = 5,
        .FileFieldCount     = 5,
        .LayoutHash         = 0x0FF75B01,
        .Fields             = Fields
    };
};

struct UiMapLinkMeta
{
    static constexpr DB2MetaField Fields[9] =
    {
        { .Type = FT_FLOAT,                .ArraySize =  2, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  2, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 2030690,
        .IndexField         = 2,
        .ParentIndexField   = 3,
        .FieldCount         = 9,
        .FileFieldCount     = 9,
        .LayoutHash         = 0x767439DE,
        .Fields             = Fields
    };
};

struct UiMapXMapArtMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1957217,
        .IndexField         = -1,
        .ParentIndexField   = 2,
        .FieldCount         = 3,
        .FileFieldCount     = 2,
        .LayoutHash         = 0xEAE7DA2A,
        .Fields             = Fields
    };
};

struct UiModelSceneMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1548215,
        .IndexField         = 0,
        .ParentIndexField   = -1,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0x7A47260D,
        .Fields             = Fields
    };
};

struct UiModelSceneActorMeta
{
    static constexpr DB2MetaField Fields[10] =
    {
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  3, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1548214,
        .IndexField         = 2,
        .ParentIndexField   = 9,
        .FieldCount         = 10,
        .FileFieldCount     = 9,
        .LayoutHash         = 0xF1E78B36,
        .Fields             = Fields
    };
};

struct UiModelSceneActorDisplayMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1548216,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 7,
        .FileFieldCount     = 7,
        .LayoutHash         = 0x7BD2B582,
        .Fields             = Fields
    };
};

struct UiModelSceneCameraMeta
{
    static constexpr DB2MetaField Fields[16] =
    {
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  3, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  3, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1548213,
        .IndexField         = 3,
        .ParentIndexField   = 15,
        .FieldCount         = 16,
        .FileFieldCount     = 15,
        .LayoutHash         = 0xEA151443,
        .Fields             = Fields
    };
};

struct UiPartyPoseMeta
{
    static constexpr DB2MetaField Fields[12] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1993323,
        .IndexField         = 2,
        .ParentIndexField   = 11,
        .FieldCount         = 12,
        .FileFieldCount     = 11,
        .LayoutHash         = 0x1AE713AB,
        .Fields             = Fields
    };
};

struct UiTextureAtlasMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 897470,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0x1D9B7D22,
        .Fields             = Fields
    };
};

struct UiTextureAtlasElementMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1989276,
        .IndexField         = 1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x7CCBD18F,
        .Fields             = Fields
    };
};

struct UiTextureAtlasElementSliceDataMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 5319042,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 6,
        .FileFieldCount     = 6,
        .LayoutHash         = 0xBB5710C0,
        .Fields             = Fields
    };
};

struct UiTextureAtlasMemberMeta
{
    static constexpr DB2MetaField Fields[14] =
    {
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 897532,
        .IndexField         = 1,
        .ParentIndexField   = 9,
        .FieldCount         = 14,
        .FileFieldCount     = 14,
        .LayoutHash         = 0x75E12F73,
        .Fields             = Fields
    };
};

struct UiTextureKitMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 939159,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 1,
        .FileFieldCount     = 1,
        .LayoutHash         = 0x4740638A,
        .Fields             = Fields
    };
};

struct UiWidgetMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1983278,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 6,
        .FileFieldCount     = 6,
        .LayoutHash         = 0xD100F6B5,
        .Fields             = Fields
    };
};

struct UiWidgetConstantSourceMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1983639,
        .IndexField         = -1,
        .ParentIndexField   = 2,
        .FieldCount         = 3,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x689BD038,
        .Fields             = Fields
    };
};

struct UiWidgetDataSourceMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1983640,
        .IndexField         = -1,
        .ParentIndexField   = 3,
        .FieldCount         = 4,
        .FileFieldCount     = 3,
        .LayoutHash         = 0xD581563B,
        .Fields             = Fields
    };
};

struct UiWidgetStringSourceMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1983641,
        .IndexField         = -1,
        .ParentIndexField   = 2,
        .FieldCount         = 3,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x0E572854,
        .Fields             = Fields
    };
};

struct UiWidgetVisualizationMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1983276,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0x8F0ACA66,
        .Fields             = Fields
    };
};

struct UnitBloodMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_INT,                  .ArraySize =  2, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  2, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1284821,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x324585EB,
        .Fields             = Fields
    };
};

struct UnitBloodLevelsMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  3, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1268904,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 1,
        .FileFieldCount     = 1,
        .LayoutHash         = 0x13B47815,
        .Fields             = Fields
    };
};

struct UnitConditionMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  8, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  8, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  8, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1120959,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0x215FAF83,
        .Fields             = Fields
    };
};

struct UnitPowerBarMeta
{
    static constexpr DB2MetaField Fields[16] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  6, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  6, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1237753,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 16,
        .FileFieldCount     = 16,
        .LayoutHash         = 0xF11126D1,
        .Fields             = Fields
    };
};

struct VehicleMeta
{
    static constexpr DB2MetaField Fields[19] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  8, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  3, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1368621,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 19,
        .FileFieldCount     = 19,
        .LayoutHash         = 0x7CC3210B,
        .Fields             = Fields
    };
};

struct VehiclePOITypeMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 3311405,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 5,
        .FileFieldCount     = 5,
        .LayoutHash         = 0x55F18A29,
        .Fields             = Fields
    };
};

struct VehicleSeatMeta
{
    static constexpr DB2MetaField Fields[62] =
    {
        { .Type = FT_FLOAT,                .ArraySize =  3, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  3, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1345447,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 62,
        .FileFieldCount     = 62,
        .LayoutHash         = 0x239D9941,
        .Fields             = Fields
    };
};

struct VehicleUIIndSeatMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1279741,
        .IndexField         = -1,
        .ParentIndexField   = 3,
        .FieldCount         = 4,
        .FileFieldCount     = 3,
        .LayoutHash         = 0x1A05C81D,
        .Fields             = Fields
    };
};

struct VehicleUIIndicatorMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1279740,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 1,
        .FileFieldCount     = 1,
        .LayoutHash         = 0x13526596,
        .Fields             = Fields
    };
};

struct VignetteMeta
{
    static constexpr DB2MetaField Fields[10] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 892861,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 10,
        .FileFieldCount     = 10,
        .LayoutHash         = 0xA6472C0E,
        .Fields             = Fields
    };
};

struct VirtualAttachmentMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1634482,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0xECAB5C57,
        .Fields             = Fields
    };
};

struct VirtualAttachmentCustomizationMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1634480,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0xD7602227,
        .Fields             = Fields
    };
};

struct VocalUISoundsMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  2, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1267067,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0xF192151C,
        .Fields             = Fields
    };
};

struct VoiceOverPriorityMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 4211372,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0x11177BA9,
        .Fields             = Fields
    };
};

struct VolumeFogConditionMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 3587230,
        .IndexField         = -1,
        .ParentIndexField   = 3,
        .FieldCount         = 4,
        .FileFieldCount     = 3,
        .LayoutHash         = 0x00F4D6A5,
        .Fields             = Fields
    };
};

struct WMOAreaTableMeta
{
    static constexpr DB2MetaField Fields[15] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1355528,
        .IndexField         = 1,
        .ParentIndexField   = 2,
        .FieldCount         = 15,
        .FileFieldCount     = 15,
        .LayoutHash         = 0x58247DE7,
        .Fields             = Fields
    };
};

struct WMOMinimapTextureMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1323241,
        .IndexField         = -1,
        .ParentIndexField   = 4,
        .FieldCount         = 5,
        .FileFieldCount     = 4,
        .LayoutHash         = 0x01230A50,
        .Fields             = Fields
    };
};

struct WarbandSceneMeta
{
    static constexpr DB2MetaField Fields[15] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  3, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  3, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 5736126,
        .IndexField         = 5,
        .ParentIndexField   = 6,
        .FieldCount         = 15,
        .FileFieldCount     = 15,
        .LayoutHash         = 0xF0593458,
        .Fields             = Fields
    };
};

struct WarbandScenePlacementMeta
{
    static constexpr DB2MetaField Fields[8] =
    {
        { .Type = FT_FLOAT,                .ArraySize =  3, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 5736130,
        .IndexField         = 1,
        .ParentIndexField   = 7,
        .FieldCount         = 8,
        .FileFieldCount     = 7,
        .LayoutHash         = 0x92B0F0A8,
        .Fields             = Fields
    };
};

struct WbAccessControlListMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 879634,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 5,
        .FileFieldCount     = 5,
        .LayoutHash         = 0x814E6C18,
        .Fields             = Fields
    };
};

struct WeaponImpactSoundsMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize = 11, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize = 11, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize = 11, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize = 11, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1267648,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 7,
        .FileFieldCount     = 7,
        .LayoutHash         = 0x21DD049D,
        .Fields             = Fields
    };
};

struct WeaponSwingSounds2Meta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1267068,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0x8CC18B68,
        .Fields             = Fields
    };
};

struct WeaponTrailMeta
{
    static constexpr DB2MetaField Fields[9] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  3, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  3, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  3, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  3, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  3, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 982461,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 9,
        .FileFieldCount     = 9,
        .LayoutHash         = 0x334DF54B,
        .Fields             = Fields
    };
};

struct WeaponTrailModelDefMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1239843,
        .IndexField         = -1,
        .ParentIndexField   = 2,
        .FieldCount         = 3,
        .FileFieldCount     = 2,
        .LayoutHash         = 0xFF75FD57,
        .Fields             = Fields
    };
};

struct WeaponTrailParamMeta
{
    static constexpr DB2MetaField Fields[10] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1239842,
        .IndexField         = -1,
        .ParentIndexField   = 9,
        .FieldCount         = 10,
        .FileFieldCount     = 9,
        .LayoutHash         = 0x17D0C0A3,
        .Fields             = Fields
    };
};

struct WeatherMeta
{
    static constexpr DB2MetaField Fields[22] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  2, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  3, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1343311,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 22,
        .FileFieldCount     = 22,
        .LayoutHash         = 0x5CF35EA0,
        .Fields             = Fields
    };
};

struct WeatherXParticulateMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1965591,
        .IndexField         = -1,
        .ParentIndexField   = 1,
        .FieldCount         = 2,
        .FileFieldCount     = 1,
        .LayoutHash         = 0x568F5BC4,
        .Fields             = Fields
    };
};

struct WeeklyRewardChestThresholdMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 3580962,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0xD70784C5,
        .Fields             = Fields
    };
};

struct WindSettingsMeta
{
    static constexpr DB2MetaField Fields[10] =
    {
        { .Type = FT_FLOAT,                .ArraySize =  3, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  3, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  3, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 943871,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 10,
        .FileFieldCount     = 10,
        .LayoutHash         = 0x5DE91550,
        .Fields             = Fields
    };
};

struct WorldBossLockoutMeta
{
    static constexpr DB2MetaField Fields[2] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 975279,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x63019FFE,
        .Fields             = Fields
    };
};

struct WorldChunkSoundsMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1267069,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 7,
        .FileFieldCount     = 7,
        .LayoutHash         = 0x01DC06CF,
        .Fields             = Fields
    };
};

struct WorldEffectMeta
{
    static constexpr DB2MetaField Fields[6] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1343312,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 6,
        .FileFieldCount     = 6,
        .LayoutHash         = 0xB841BBEE,
        .Fields             = Fields
    };
};

struct WorldElapsedTimerMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1135240,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 3,
        .FileFieldCount     = 3,
        .LayoutHash         = 0x057E7307,
        .Fields             = Fields
    };
};

struct WorldLayerMapSetMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 4550228,
        .IndexField         = 2,
        .ParentIndexField   = -1,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0x416E01AD,
        .Fields             = Fields
    };
};

struct WorldMapOverlayMeta
{
    static constexpr DB2MetaField Fields[13] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  4, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1134579,
        .IndexField         = 0,
        .ParentIndexField   = 1,
        .FieldCount         = 13,
        .FileFieldCount     = 13,
        .LayoutHash         = 0x7E893204,
        .Fields             = Fields
    };
};

struct WorldMapOverlayTileMeta
{
    static constexpr DB2MetaField Fields[5] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1957212,
        .IndexField         = -1,
        .ParentIndexField   = 4,
        .FieldCount         = 5,
        .FileFieldCount     = 4,
        .LayoutHash         = 0x2C843422,
        .Fields             = Fields
    };
};

struct WorldShadowMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_FLOAT,                .ArraySize =  2, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 4680120,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0xFAF1FC05,
        .Fields             = Fields
    };
};

struct WorldStateExpressionMeta
{
    static constexpr DB2MetaField Fields[1] =
    {
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1332558,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 1,
        .FileFieldCount     = 1,
        .LayoutHash         = 0xCA33F540,
        .Fields             = Fields
    };
};

struct WorldStateUIMeta
{
    static constexpr DB2MetaField Fields[17] =
    {
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  3, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1343596,
        .IndexField         = 5,
        .ParentIndexField   = 6,
        .FieldCount         = 17,
        .FileFieldCount     = 17,
        .LayoutHash         = 0x1C87F1EC,
        .Fields             = Fields
    };
};

struct WorldStateZoneSoundsMeta
{
    static constexpr DB2MetaField Fields[8] =
    {
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1266941,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 8,
        .FileFieldCount     = 8,
        .LayoutHash         = 0x8CC049D9,
        .Fields             = Fields
    };
};

struct World_PVP_AreaMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1310255,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 7,
        .FileFieldCount     = 7,
        .LayoutHash         = 0x06AB7E95,
        .Fields             = Fields
    };
};

struct ZoneIntroMusicTableMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1310251,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0xE1F93744,
        .Fields             = Fields
    };
};

struct ZoneLightMeta
{
    static constexpr DB2MetaField Fields[7] =
    {
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1310253,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 7,
        .FileFieldCount     = 7,
        .LayoutHash         = 0x92275F42,
        .Fields             = Fields
    };
};

struct ZoneLightPointMeta
{
    static constexpr DB2MetaField Fields[3] =
    {
        { .Type = FT_FLOAT,                .ArraySize =  2, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1310256,
        .IndexField         = -1,
        .ParentIndexField   = 2,
        .FieldCount         = 3,
        .FileFieldCount     = 2,
        .LayoutHash         = 0xDE2377FB,
        .Fields             = Fields
    };
};

struct ZoneMusicMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  2, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  2, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  2, .IsSigned = false },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1310254,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 4,
        .FileFieldCount     = 4,
        .LayoutHash         = 0x72572D05,
        .Fields             = Fields
    };
};

struct ZoneStoryMeta
{
    static constexpr DB2MetaField Fields[4] =
    {
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta Instance =
    {
        .FileDataId         = 1797864,
        .IndexField         = -1,
        .ParentIndexField   = 3,
        .FieldCount         = 4,
        .FileFieldCount     = 3,
        .LayoutHash         = 0x3D386FF2,
        .Fields             = Fields
    };
};

#endif // TRINITYCORE_DB2_METADATA_H
