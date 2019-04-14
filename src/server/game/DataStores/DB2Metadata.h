/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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
        static DB2MetaField const fields[15] =
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
        static DB2Meta instance(3, 15, 0x13CB7BEE, fields, 11);
        return &instance;
    }
};

struct Achievement_CategoryMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_STRING, 1, true },
            { FT_INT, 1, false },
            { FT_SHORT, 1, true },
            { FT_BYTE, 1, true },
        };
        static DB2Meta instance(1, 4, 0x0B008A91, fields, 3);
        return &instance;
    }
};

struct AdventureJournalMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[22] =
        {
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_BYTE, 1, false },
            { FT_INT, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
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
        static DB2Meta instance(-1, 22, 0x9D620FC8, fields, -1);
        return &instance;
    }
};

struct AdventureMapPOIMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[12] =
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
        static DB2Meta instance(-1, 12, 0x4AABC870, fields, -1);
        return &instance;
    }
};

struct AlliedRaceMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[8] =
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
        static DB2Meta instance(0, 8, 0xE89FA2D2, fields, -1);
        return &instance;
    }
};

struct AlliedRaceRacialAbilityMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[5] =
        {
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_INT, 1, true },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 5, 0x96902165, fields, 4);
        return &instance;
    }
};

struct AnimKitMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_INT, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 3, 0x0C4BCDEC, fields, -1);
        return &instance;
    }
};

struct AnimKitBoneSetMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[5] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, true },
        };
        static DB2Meta instance(-1, 5, 0x1C432613, fields, -1);
        return &instance;
    }
};

struct AnimKitBoneSetAliasMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 2, 0xB307E8FC, fields, -1);
        return &instance;
    }
};

struct AnimKitConfigMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[1] =
        {
            { FT_INT, 1, false },
        };
        static DB2Meta instance(-1, 1, 0x972D46F8, fields, -1);
        return &instance;
    }
};

struct AnimKitConfigBoneSetMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 3, 0x48518303, fields, 2);
        return &instance;
    }
};

struct AnimKitPriorityMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[1] =
        {
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 1, 0x27ED596B, fields, -1);
        return &instance;
    }
};

struct AnimKitReplacementMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[5] =
        {
            { FT_INT, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(0, 5, 0xB0BBA55F, fields, 4);
        return &instance;
    }
};

struct AnimKitSegmentMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[18] =
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
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
            { FT_BYTE, 1, true },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 18, 0xEBF796F5, fields, 0);
        return &instance;
    }
};

struct AnimReplacementMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[5] =
        {
            { FT_INT, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(0, 5, 0x5D91ABFD, fields, 4);
        return &instance;
    }
};

struct AnimReplacementSetMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[1] =
        {
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 1, 0x15AFC3D6, fields, -1);
        return &instance;
    }
};

struct AnimationDataMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 2, true },
        };
        static DB2Meta instance(-1, 4, 0xFB408E92, fields, -1);
        return &instance;
    }
};

struct AoiBoxMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[5] =
        {
            { FT_FLOAT, 6, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 5, 0x173154C8, fields, 4);
        return &instance;
    }
};

struct AreaConditionalDataMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[5] =
        {
            { FT_STRING, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(1, 5, 0xBE8C656A, fields, 4);
        return &instance;
    }
};

struct AreaFarClipOverrideMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_INT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 4, 0xD7028AD6, fields, -1);
        return &instance;
    }
};

struct AreaGroupMemberMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 2, 0x27C84A16, fields, 1);
        return &instance;
    }
};

struct AreaPOIMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[17] =
        {
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_INT, 1, false },
            { FT_FLOAT, 3, true },
            { FT_INT, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
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
        static DB2Meta instance(2, 17, 0x34D56581, fields, 11);
        return &instance;
    }
};

struct AreaPOIStateMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[5] =
        {
            { FT_STRING, 1, true },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, false },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 5, 0xEB8CA12C, fields, 4);
        return &instance;
    }
};

struct AreaTableMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[23] =
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
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, true },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 2, true },
            { FT_SHORT, 4, false },
        };
        static DB2Meta instance(-1, 23, 0x22229BE7, fields, -1);
        return &instance;
    }
};

struct AreaTriggerMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[15] =
        {
            { FT_FLOAT, 3, true },
            { FT_INT, 1, false },
            { FT_SHORT, 1, true },
            { FT_BYTE, 1, true },
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
        static DB2Meta instance(1, 15, 0x61A4F966, fields, 2);
        return &instance;
    }
};

struct AreaTriggerActionSetMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[1] =
        {
            { FT_SHORT, 1, true },
        };
        static DB2Meta instance(-1, 1, 0xBE34F649, fields, -1);
        return &instance;
    }
};

struct AreaTriggerBoxMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[1] =
        {
            { FT_FLOAT, 3, true },
        };
        static DB2Meta instance(-1, 1, 0x14918F12, fields, -1);
        return &instance;
    }
};

struct AreaTriggerCreatePropertiesMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_BYTE, 1, true },
            { FT_SHORT, 1, true },
        };
        static DB2Meta instance(-1, 2, 0xAAE6E300, fields, -1);
        return &instance;
    }
};

struct AreaTriggerCylinderMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
        };
        static DB2Meta instance(-1, 3, 0x867834A9, fields, -1);
        return &instance;
    }
};

struct AreaTriggerSphereMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[1] =
        {
            { FT_FLOAT, 1, true },
        };
        static DB2Meta instance(-1, 1, 0xF1D2220B, fields, -1);
        return &instance;
    }
};

struct ArmorLocationMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[5] =
        {
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
        };
        static DB2Meta instance(-1, 5, 0x1C0BBC02, fields, -1);
        return &instance;
    }
};

struct ArtifactMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[11] =
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
        static DB2Meta instance(1, 11, 0x780D61EA, fields, -1);
        return &instance;
    }
};

struct ArtifactAppearanceMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[15] =
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
        static DB2Meta instance(1, 15, 0x330F75C9, fields, 2);
        return &instance;
    }
};

struct ArtifactAppearanceSetMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[9] =
        {
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_INT, 1, false },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(2, 9, 0xBB4DB4D3, fields, 8);
        return &instance;
    }
};

struct ArtifactCategoryMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_SHORT, 1, true },
            { FT_SHORT, 1, true },
        };
        static DB2Meta instance(-1, 2, 0x484A6D55, fields, -1);
        return &instance;
    }
};

struct ArtifactItemToTransmogMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 3, 0xD54CBBE1, fields, 0);
        return &instance;
    }
};

struct ArtifactPowerMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[7] =
        {
            { FT_FLOAT, 2, true },
            { FT_INT, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(1, 7, 0x1F7637C8, fields, 2);
        return &instance;
    }
};

struct ArtifactPowerLinkMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 2, 0xBB7E3584, fields, -1);
        return &instance;
    }
};

struct ArtifactPowerPickerMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[1] =
        {
            { FT_INT, 1, false },
        };
        static DB2Meta instance(-1, 1, 0x253242BA, fields, -1);
        return &instance;
    }
};

struct ArtifactPowerRankMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[5] =
        {
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
            { FT_SHORT, 1, false },
            { FT_FLOAT, 1, true },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 5, 0x7DC78F1E, fields, 4);
        return &instance;
    }
};

struct ArtifactQuestXPMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[1] =
        {
            { FT_INT, 10, false },
        };
        static DB2Meta instance(-1, 1, 0x7E00C5B6, fields, -1);
        return &instance;
    }
};

struct ArtifactTierMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[5] =
        {
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
        };
        static DB2Meta instance(-1, 5, 0xA47F6D9D, fields, -1);
        return &instance;
    }
};

struct ArtifactUnlockMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[5] =
        {
            { FT_INT, 1, false },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
            { FT_INT, 1, false },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 5, 0x40C54B9F, fields, 4);
        return &instance;
    }
};

struct AuctionHouseMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_STRING, 1, true },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 4, 0x61E641BA, fields, -1);
        return &instance;
    }
};

struct AzeriteEmpoweredItemMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
        };
        static DB2Meta instance(-1, 3, 0x4078BECD, fields, -1);
        return &instance;
    }
};

struct AzeriteItemMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[1] =
        {
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 1, 0xDAC6A93C, fields, -1);
        return &instance;
    }
};

struct AzeriteItemMilestonePowerMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, true },
        };
        static DB2Meta instance(-1, 2, 0x7C4DC43D, fields, -1);
        return &instance;
    }
};

struct AzeritePowerMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 4, 0xE7FE46AC, fields, -1);
        return &instance;
    }
};

struct AzeritePowerSetMemberMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[5] =
        {
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 5, 0xDB24A281, fields, 4);
        return &instance;
    }
};

struct AzeriteTierUnlockMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 4, 0x2B04F059, fields, 3);
        return &instance;
    }
};

struct BankBagSlotPricesMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[1] =
        {
            { FT_INT, 1, false },
        };
        static DB2Meta instance(-1, 1, 0x897A4D1E, fields, -1);
        return &instance;
    }
};

struct BannedAddonsMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 3, 0xF4525F59, fields, -1);
        return &instance;
    }
};

struct BarberShopStyleMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[8] =
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
        static DB2Meta instance(2, 8, 0x2DD3952C, fields, -1);
        return &instance;
    }
};

struct BattlePetAbilityMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[7] =
        {
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_INT, 1, true },
            { FT_BYTE, 1, true },
            { FT_INT, 1, false },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 7, 0x4C3AF583, fields, -1);
        return &instance;
    }
};

struct BattlePetAbilityEffectMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[7] =
        {
            { FT_INT, 1, false },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 6, true },
        };
        static DB2Meta instance(0, 7, 0xC850B549, fields, 1);
        return &instance;
    }
};

struct BattlePetAbilityStateMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 3, 0x73DDAA6A, fields, 2);
        return &instance;
    }
};

struct BattlePetAbilityTurnMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[6] =
        {
            { FT_INT, 1, false },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, true },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(0, 6, 0xF2218887, fields, 1);
        return &instance;
    }
};

struct BattlePetBreedQualityMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_FLOAT, 1, true },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 2, 0x6CD46EB5, fields, -1);
        return &instance;
    }
};

struct BattlePetBreedStateMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 3, 0xC1A59CCF, fields, 2);
        return &instance;
    }
};

struct BattlePetDisplayOverrideMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 4, 0x6F9CB092, fields, -1);
        return &instance;
    }
};

struct BattlePetEffectPropertiesMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_STRING_NOT_LOCALIZED, 6, true },
            { FT_SHORT, 1, false },
            { FT_BYTE, 6, false },
        };
        static DB2Meta instance(-1, 3, 0xA2D4ADF5, fields, -1);
        return &instance;
    }
};

struct BattlePetNPCTeamMemberMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[1] =
        {
            { FT_STRING, 1, true },
        };
        static DB2Meta instance(-1, 1, 0x9F2C8370, fields, -1);
        return &instance;
    }
};

struct BattlePetSpeciesMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[11] =
        {
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(2, 11, 0x78A6B928, fields, -1);
        return &instance;
    }
};

struct BattlePetSpeciesStateMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 3, 0x99EBACAA, fields, 2);
        return &instance;
    }
};

struct BattlePetSpeciesXAbilityMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, true },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 4, 0x630BA932, fields, 3);
        return &instance;
    }
};

struct BattlePetStateMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 3, 0xF9579FAC, fields, -1);
        return &instance;
    }
};

struct BattlePetVisualMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[7] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_INT, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 7, 0x284AF258, fields, -1);
        return &instance;
    }
};

struct BattlemasterListMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[17] =
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
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, true },
            { FT_SHORT, 1, true },
            { FT_BYTE, 1, true },
            { FT_INT, 1, true },
            { FT_SHORT, 1, true },
            { FT_SHORT, 16, true },
        };
        static DB2Meta instance(-1, 17, 0x167284E8, fields, -1);
        return &instance;
    }
};

struct BeamEffectMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[10] =
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
        static DB2Meta instance(-1, 10, 0x0E55B843, fields, -1);
        return &instance;
    }
};

struct BoneWindModifierModelMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 2, 0x77B007CA, fields, 0);
        return &instance;
    }
};

struct BoneWindModifiersMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_FLOAT, 3, true },
            { FT_FLOAT, 1, true },
        };
        static DB2Meta instance(-1, 2, 0xC6F446CE, fields, -1);
        return &instance;
    }
};

struct BonusRollMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
        };
        static DB2Meta instance(-1, 4, 0xF7A194FA, fields, -1);
        return &instance;
    }
};

struct BountyMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[5] =
        {
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 5, 0x797CCAA0, fields, 4);
        return &instance;
    }
};

struct BountySetMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_INT, 1, false },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 2, 0xB67E3F83, fields, -1);
        return &instance;
    }
};

struct BroadcastTextMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[11] =
        {
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_INT, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 2, false },
            { FT_SHORT, 3, false },
            { FT_SHORT, 3, false },
        };
        static DB2Meta instance(2, 11, 0x6318993B, fields, -1);
        return &instance;
    }
};

struct CameraEffectMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[1] =
        {
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 1, 0xAB0FD78E, fields, -1);
        return &instance;
    }
};

struct CameraEffectEntryMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[16] =
        {
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
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
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 16, 0xED27DC2F, fields, 15);
        return &instance;
    }
};

struct CameraModeMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[11] =
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
        };
        static DB2Meta instance(-1, 11, 0xEE5489F4, fields, -1);
        return &instance;
    }
};

struct CampaignMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[7] =
        {
            { FT_STRING, 1, true },
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_STRING, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
        };
        static DB2Meta instance(3, 7, 0x2D49AABD, fields, -1);
        return &instance;
    }
};

struct CampaignXConditionMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
        };
        static DB2Meta instance(-1, 3, 0x638FC159, fields, 2);
        return &instance;
    }
};

struct CampaignXQuestLineMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
        };
        static DB2Meta instance(-1, 3, 0x7303E0F9, fields, 0);
        return &instance;
    }
};

struct CastableRaidBuffsMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_INT, 1, false },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 2, 0x3B349C01, fields, 1);
        return &instance;
    }
};

struct CelestialBodyMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[15] =
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
        static DB2Meta instance(1, 15, 0xFC417DCA, fields, -1);
        return &instance;
    }
};

struct Cfg_CategoriesMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[5] =
        {
            { FT_STRING, 1, true },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 5, 0xB6FEB874, fields, -1);
        return &instance;
    }
};

struct Cfg_ConfigsMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
            { FT_FLOAT, 1, true },
        };
        static DB2Meta instance(-1, 4, 0xA275539B, fields, -1);
        return &instance;
    }
};

struct Cfg_RegionsMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[5] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_SHORT, 1, false },
            { FT_INT, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, false },
        };
        static DB2Meta instance(-1, 5, 0x0125202F, fields, -1);
        return &instance;
    }
};

struct CharBaseInfoMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, true },
        };
        static DB2Meta instance(-1, 2, 0x10AA45F8, fields, -1);
        return &instance;
    }
};

struct CharBaseSectionMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 3, 0xF9D1C513, fields, -1);
        return &instance;
    }
};

struct CharComponentTextureLayoutsMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_SHORT, 1, true },
            { FT_SHORT, 1, true },
        };
        static DB2Meta instance(-1, 2, 0x48D8D7BC, fields, -1);
        return &instance;
    }
};

struct CharComponentTextureSectionsMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[7] =
        {
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, true },
            { FT_SHORT, 1, true },
            { FT_SHORT, 1, true },
            { FT_SHORT, 1, true },
            { FT_SHORT, 1, true },
            { FT_INT, 1, false },
        };
        static DB2Meta instance(-1, 7, 0xD6EDA743, fields, -1);
        return &instance;
    }
};

struct CharHairGeosetsMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[10] =
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
        static DB2Meta instance(-1, 10, 0xE3732EA9, fields, 0);
        return &instance;
    }
};

struct CharSectionsMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[7] =
        {
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, true },
            { FT_SHORT, 1, true },
            { FT_INT, 3, true },
        };
        static DB2Meta instance(-1, 7, 0x273A7F6F, fields, -1);
        return &instance;
    }
};

struct CharShipmentMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[9] =
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
        static DB2Meta instance(-1, 9, 0xD47EC921, fields, 0);
        return &instance;
    }
};

struct CharShipmentContainerMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[16] =
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
            { FT_SHORT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, true },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 16, 0x13048703, fields, -1);
        return &instance;
    }
};

struct CharStartOutfitMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[7] =
        {
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 24, true },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 7, 0x0F59DD96, fields, 6);
        return &instance;
    }
};

struct CharTitlesMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_SHORT, 1, true },
            { FT_BYTE, 1, true },
        };
        static DB2Meta instance(-1, 4, 0x81B69C5F, fields, -1);
        return &instance;
    }
};

struct CharacterFaceBoneSetMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[5] =
        {
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 5, 0x3C6DE4D7, fields, 4);
        return &instance;
    }
};

struct CharacterFacialHairStylesMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_INT, 5, true },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 4, 0xAA817A08, fields, -1);
        return &instance;
    }
};

struct CharacterLoadoutMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_LONG, 1, true },
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, true },
        };
        static DB2Meta instance(-1, 3, 0xA07F9727, fields, -1);
        return &instance;
    }
};

struct CharacterLoadoutItemMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_SHORT, 1, false },
            { FT_INT, 1, false },
        };
        static DB2Meta instance(-1, 2, 0xD892CDA9, fields, 0);
        return &instance;
    }
};

struct CharacterServiceInfoMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[11] =
        {
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 11, 0xC263D77C, fields, -1);
        return &instance;
    }
};

struct ChatChannelsMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_INT, 1, true },
            { FT_BYTE, 1, true },
        };
        static DB2Meta instance(-1, 4, 0x113E92FA, fields, -1);
        return &instance;
    }
};

struct ChatProfanityMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_BYTE, 1, true },
        };
        static DB2Meta instance(-1, 2, 0xAF5F92A6, fields, -1);
        return &instance;
    }
};

struct ChrClassRaceSexMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[6] =
        {
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
        };
        static DB2Meta instance(-1, 6, 0x204BD561, fields, -1);
        return &instance;
    }
};

struct ChrClassTitleMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 3, 0xA01D47C8, fields, -1);
        return &instance;
    }
};

struct ChrClassUIDisplayMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_BYTE, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
        };
        static DB2Meta instance(-1, 3, 0x3D58F88F, fields, -1);
        return &instance;
    }
};

struct ChrClassVillainMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_STRING, 1, true },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, true },
        };
        static DB2Meta instance(-1, 3, 0x601C7CCD, fields, -1);
        return &instance;
    }
};

struct ChrClassesMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[20] =
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
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(5, 20, 0x2CD115AC, fields, -1);
        return &instance;
    }
};

struct ChrClassesXPowerTypesMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 2, 0x6DE888E7, fields, 1);
        return &instance;
    }
};

struct ChrCustomizationMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[7] =
        {
            { FT_STRING, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 3, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 7, 0xC29562A3, fields, 6);
        return &instance;
    }
};

struct ChrRacesMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[46] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_FLOAT, 3, true },
            { FT_FLOAT, 3, true },
            { FT_INT, 1, true },
            { FT_INT, 3, false },
            { FT_INT, 3, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_SHORT, 1, true },
            { FT_SHORT, 1, true },
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
            { FT_BYTE, 1, true },
        };
        static DB2Meta instance(6, 46, 0xC8BCDC89, fields, -1);
        return &instance;
    }
};

struct ChrSpecializationMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[13] =
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
        static DB2Meta instance(3, 13, 0xFF9DD5DD, fields, 4);
        return &instance;
    }
};

struct ChrUpgradeBucketMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_INT, 1, false },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(0, 3, 0x81B7C74C, fields, 2);
        return &instance;
    }
};

struct ChrUpgradeBucketSpellMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_INT, 1, true },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 2, 0xC665F469, fields, 1);
        return &instance;
    }
};

struct ChrUpgradeTierMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_STRING, 1, true },
            { FT_INT, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(1, 4, 0xEC517FDD, fields, -1);
        return &instance;
    }
};

struct CinematicCameraMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_FLOAT, 3, true },
            { FT_INT, 1, false },
            { FT_FLOAT, 1, true },
            { FT_INT, 1, false },
        };
        static DB2Meta instance(-1, 4, 0x20C5E540, fields, -1);
        return &instance;
    }
};

struct CinematicSequencesMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_INT, 1, false },
            { FT_SHORT, 8, false },
        };
        static DB2Meta instance(-1, 2, 0x6A232AD4, fields, -1);
        return &instance;
    }
};

struct ClientSceneEffectMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[1] =
        {
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 1, 0x00EE4486, fields, -1);
        return &instance;
    }
};

struct CloakDampeningMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[7] =
        {
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 5, true },
            { FT_FLOAT, 5, true },
            { FT_FLOAT, 2, true },
            { FT_FLOAT, 2, true },
        };
        static DB2Meta instance(-1, 7, 0xF7C03F6E, fields, -1);
        return &instance;
    }
};

struct CloneEffectMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[8] =
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
        static DB2Meta instance(-1, 8, 0x2F946F74, fields, -1);
        return &instance;
    }
};

struct CombatConditionMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[11] =
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
        static DB2Meta instance(-1, 11, 0x75A29044, fields, -1);
        return &instance;
    }
};

struct CommentatorStartLocationMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_FLOAT, 3, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 2, 0xF552D58F, fields, -1);
        return &instance;
    }
};

struct CommentatorTrackedCooldownMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_INT, 1, true },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, true },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 4, 0x3A1476FC, fields, 3);
        return &instance;
    }
};

struct CommunityIconMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_INT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(0, 3, 0x7E19DEAD, fields, -1);
        return &instance;
    }
};

struct ComponentModelFileDataMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, true },
        };
        static DB2Meta instance(-1, 4, 0x0F90AFAF, fields, -1);
        return &instance;
    }
};

struct ComponentTextureFileDataMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 3, 0x263AACE3, fields, -1);
        return &instance;
    }
};

struct ConfigurationWarningMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_STRING, 1, true },
            { FT_INT, 1, false },
        };
        static DB2Meta instance(-1, 2, 0x99BCBA2D, fields, -1);
        return &instance;
    }
};

struct ContentTuningMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[6] =
        {
            { FT_INT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(0, 6, 0xD1A210D1, fields, -1);
        return &instance;
    }
};

struct ContributionMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[7] =
        {
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 4, true },
        };
        static DB2Meta instance(2, 7, 0x37C49135, fields, 3);
        return &instance;
    }
};

struct ContributionStyleMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[7] =
        {
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 7, 0x799AE511, fields, -1);
        return &instance;
    }
};

struct ContributionStyleContainerMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[1] =
        {
            { FT_INT, 5, true },
        };
        static DB2Meta instance(-1, 1, 0x55DAA69B, fields, -1);
        return &instance;
    }
};

struct ConversationLineMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[8] =
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
        static DB2Meta instance(-1, 8, 0x227B5003, fields, -1);
        return &instance;
    }
};

struct CreatureMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[11] =
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
        static DB2Meta instance(-1, 11, 0x0D492BF3, fields, -1);
        return &instance;
    }
};

struct CreatureDifficultyMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[7] =
        {
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, true },
            { FT_SHORT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 7, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 7, 0xD344A642, fields, 6);
        return &instance;
    }
};

struct CreatureDispXUiCameraMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_INT, 1, false },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 2, 0xD3D075FD, fields, -1);
        return &instance;
    }
};

struct CreatureDisplayInfoMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[25] =
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
            { FT_INT, 3, true },
        };
        static DB2Meta instance(0, 25, 0x613413D1, fields, -1);
        return &instance;
    }
};

struct CreatureDisplayInfoCondMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[15] =
        {
            { FT_LONG, 1, true },
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 2, true },
            { FT_INT, 2, true },
            { FT_INT, 2, true },
            { FT_INT, 3, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 15, 0x596B4605, fields, 14);
        return &instance;
    }
};

struct CreatureDisplayInfoEvtMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_BYTE, 1, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 4, 0x16C6EC13, fields, 3);
        return &instance;
    }
};

struct CreatureDisplayInfoExtraMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[12] =
        {
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
        static DB2Meta instance(-1, 12, 0x89E31B13, fields, -1);
        return &instance;
    }
};

struct CreatureDisplayInfoGeosetDataMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, false },
        };
        static DB2Meta instance(-1, 3, 0x13350FA0, fields, 2);
        return &instance;
    }
};

struct CreatureDisplayInfoTrnMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[6] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_FLOAT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 6, 0xC3E28858, fields, 5);
        return &instance;
    }
};

struct CreatureFamilyMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[9] =
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
        static DB2Meta instance(-1, 9, 0x9D14B492, fields, -1);
        return &instance;
    }
};

struct CreatureImmunitiesMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[9] =
        {
            { FT_BYTE, 1, false },
            { FT_INT, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 2, true },
            { FT_INT, 9, false },
            { FT_INT, 16, false },
        };
        static DB2Meta instance(-1, 9, 0x36D9340F, fields, -1);
        return &instance;
    }
};

struct CreatureModelDataMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[28] =
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
        static DB2Meta instance(-1, 28, 0xF61D550A, fields, -1);
        return &instance;
    }
};

struct CreatureMovementInfoMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[1] =
        {
            { FT_FLOAT, 1, true },
        };
        static DB2Meta instance(-1, 1, 0x31BE6397, fields, -1);
        return &instance;
    }
};

struct CreatureSoundDataMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[37] =
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
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_BYTE, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 5, false },
            { FT_INT, 4, false },
        };
        static DB2Meta instance(-1, 37, 0xA58BDB91, fields, -1);
        return &instance;
    }
};

struct CreatureTypeMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_STRING, 1, true },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 2, 0x218D575A, fields, -1);
        return &instance;
    }
};

struct CreatureXContributionMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_INT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(0, 3, 0x2DC69C04, fields, 2);
        return &instance;
    }
};

struct CreatureXDisplayInfoMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[5] =
        {
            { FT_INT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 5, 0x44D147A6, fields, 4);
        return &instance;
    }
};

struct CriteriaMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[11] =
        {
            { FT_SHORT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, true },
            { FT_BYTE, 1, true },
        };
        static DB2Meta instance(-1, 11, 0x754DDF45, fields, -1);
        return &instance;
    }
};

struct CriteriaTreeMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[7] =
        {
            { FT_STRING, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_BYTE, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
            { FT_SHORT, 1, true },
        };
        static DB2Meta instance(-1, 7, 0xC926CF94, fields, -1);
        return &instance;
    }
};

struct CriteriaTreeXEffectMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_SHORT, 1, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 2, 0x80C700F5, fields, 1);
        return &instance;
    }
};

struct CurrencyCategoryMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_STRING, 1, true },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 3, 0x0DB1F53C, fields, -1);
        return &instance;
    }
};

struct CurrencyContainerMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[8] =
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
        static DB2Meta instance(-1, 8, 0xAC6030BF, fields, 7);
        return &instance;
    }
};

struct CurrencyTypesMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[11] =
        {
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_BYTE, 1, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 11, 0x998F0AAA, fields, -1);
        return &instance;
    }
};

struct CurveMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 2, 0x4E6F1184, fields, -1);
        return &instance;
    }
};

struct CurvePointMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_FLOAT, 2, true },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 3, 0xFA003217, fields, -1);
        return &instance;
    }
};

struct DeathThudLookupsMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
        };
        static DB2Meta instance(-1, 4, 0x3BF7542C, fields, -1);
        return &instance;
    }
};

struct DecalPropertiesMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[18] =
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
        static DB2Meta instance(0, 18, 0xB11F3B40, fields, -1);
        return &instance;
    }
};

struct DeclinedWordMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_INT, 1, false },
        };
        static DB2Meta instance(1, 2, 0x10D7C6A6, fields, -1);
        return &instance;
    }
};

struct DeclinedWordCasesMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_BYTE, 1, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 3, 0x3E19B9C5, fields, 2);
        return &instance;
    }
};

struct DestructibleModelDataMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[22] =
        {
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, true },
        };
        static DB2Meta instance(-1, 22, 0xF245BA93, fields, -1);
        return &instance;
    }
};

struct DeviceBlacklistMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 2, 0x2A350905, fields, -1);
        return &instance;
    }
};

struct DeviceDefaultSettingsMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, true },
        };
        static DB2Meta instance(-1, 3, 0x2AB8A38C, fields, -1);
        return &instance;
    }
};

struct DifficultyMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[13] =
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
        static DB2Meta instance(-1, 13, 0x29FC158C, fields, -1);
        return &instance;
    }
};

struct DissolveEffectMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[14] =
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
        };
        static DB2Meta instance(-1, 14, 0x77C510EC, fields, -1);
        return &instance;
    }
};

struct DriverBlacklistMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[7] =
        {
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 7, 0x88C28C05, fields, -1);
        return &instance;
    }
};

struct DungeonEncounterMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[9] =
        {
            { FT_STRING, 1, true },
            { FT_INT, 1, false },
            { FT_SHORT, 1, true },
            { FT_BYTE, 1, true },
            { FT_INT, 1, true },
            { FT_BYTE, 1, true },
            { FT_INT, 1, true },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(1, 9, 0x6E5C2332, fields, 2);
        return &instance;
    }
};

struct DurabilityCostsMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_SHORT, 21, false },
            { FT_SHORT, 8, false },
        };
        static DB2Meta instance(-1, 2, 0xBB493F52, fields, -1);
        return &instance;
    }
};

struct DurabilityQualityMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[1] =
        {
            { FT_FLOAT, 1, true },
        };
        static DB2Meta instance(-1, 1, 0xCFF4EEC9, fields, -1);
        return &instance;
    }
};

struct EdgeGlowEffectMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[13] =
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
        static DB2Meta instance(-1, 13, 0xCBCC7336, fields, -1);
        return &instance;
    }
};

struct EmotesMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[9] =
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
        static DB2Meta instance(-1, 9, 0xA909E182, fields, -1);
        return &instance;
    }
};

struct EmotesTextMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 2, 0xE255C6B0, fields, -1);
        return &instance;
    }
};

struct EmotesTextDataMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_STRING, 1, true },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 3, 0x460E8F09, fields, 2);
        return &instance;
    }
};

struct EmotesTextSoundMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[5] =
        {
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, false },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 5, 0x3A15105C, fields, 4);
        return &instance;
    }
};

struct EnvironmentalDamageMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 4, 0x448422B4, fields, -1);
        return &instance;
    }
};

struct ExhaustionMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[8] =
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
        static DB2Meta instance(2, 8, 0xF0F48BB5, fields, -1);
        return &instance;
    }
};

struct ExpectedStatMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[11] =
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
        static DB2Meta instance(-1, 11, 0xF0E61875, fields, 10);
        return &instance;
    }
};

struct ExpectedStatModMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[9] =
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
        static DB2Meta instance(-1, 9, 0xEA56E599, fields, -1);
        return &instance;
    }
};

struct FactionMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[16] =
        {
            { FT_LONG, 4, true },
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_INT, 1, false },
            { FT_SHORT, 1, true },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 4, true },
            { FT_SHORT, 4, false },
            { FT_INT, 4, true },
            { FT_INT, 4, true },
            { FT_FLOAT, 2, true },
            { FT_BYTE, 2, false },
        };
        static DB2Meta instance(3, 16, 0x86FE2D69, fields, -1);
        return &instance;
    }
};

struct FactionGroupMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[6] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_STRING, 1, true },
            { FT_INT, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(2, 6, 0xB9B4369B, fields, -1);
        return &instance;
    }
};

struct FactionTemplateMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[7] =
        {
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_SHORT, 4, false },
            { FT_SHORT, 4, false },
        };
        static DB2Meta instance(-1, 7, 0xD7143473, fields, -1);
        return &instance;
    }
};

struct FootprintTexturesMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 3, 0xF82F1359, fields, -1);
        return &instance;
    }
};

struct FootstepTerrainLookupMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
        };
        static DB2Meta instance(-1, 4, 0xC70AACC6, fields, -1);
        return &instance;
    }
};

struct FriendshipRepReactionMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_STRING, 1, true },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 3, 0x8B096063, fields, 1);
        return &instance;
    }
};

struct FriendshipReputationMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_STRING, 1, true },
            { FT_INT, 1, false },
            { FT_SHORT, 1, false },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(1, 4, 0xECCE459C, fields, -1);
        return &instance;
    }
};

struct FullScreenEffectMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[28] =
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
        static DB2Meta instance(-1, 28, 0x9854A6AC, fields, -1);
        return &instance;
    }
};

struct GMSurveyAnswersMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_STRING, 1, true },
            { FT_BYTE, 1, false },
            { FT_INT, 1, false },
        };
        static DB2Meta instance(-1, 3, 0xDE59EC07, fields, 2);
        return &instance;
    }
};

struct GMSurveyCurrentSurveyMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[1] =
        {
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 1, 0xAD0D7453, fields, -1);
        return &instance;
    }
};

struct GMSurveyQuestionsMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[1] =
        {
            { FT_STRING, 1, true },
        };
        static DB2Meta instance(-1, 1, 0x12B097E1, fields, -1);
        return &instance;
    }
};

struct GMSurveySurveysMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[1] =
        {
            { FT_BYTE, 15, false },
        };
        static DB2Meta instance(-1, 1, 0x24BB51BE, fields, -1);
        return &instance;
    }
};

struct GameObjectArtKitMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_INT, 1, true },
            { FT_INT, 3, true },
        };
        static DB2Meta instance(-1, 2, 0xECF16719, fields, -1);
        return &instance;
    }
};

struct GameObjectDiffAnimMapMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 4, 0xDB3508F3, fields, 3);
        return &instance;
    }
};

struct GameObjectDisplayInfoMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[5] =
        {
            { FT_FLOAT, 6, true },
            { FT_INT, 1, true },
            { FT_SHORT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
        };
        static DB2Meta instance(-1, 5, 0x7A816799, fields, -1);
        return &instance;
    }
};

struct GameObjectDisplayInfoXSoundKitMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_INT, 1, false },
            { FT_BYTE, 1, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 3, 0x456E4627, fields, 2);
        return &instance;
    }
};

struct GameObjectsMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[12] =
        {
            { FT_STRING, 1, true },
            { FT_FLOAT, 3, true },
            { FT_FLOAT, 4, true },
            { FT_INT, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_FLOAT, 1, true },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_INT, 8, true },
        };
        static DB2Meta instance(3, 12, 0x0995B956, fields, 4);
        return &instance;
    }
};

struct GameTipsMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_STRING, 1, true },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 4, 0x768EB877, fields, -1);
        return &instance;
    }
};

struct GarrAbilityMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[8] =
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
        static DB2Meta instance(2, 8, 0x8256E595, fields, -1);
        return &instance;
    }
};

struct GarrAbilityCategoryMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[1] =
        {
            { FT_STRING, 1, true },
        };
        static DB2Meta instance(-1, 1, 0x9F2C8370, fields, -1);
        return &instance;
    }
};

struct GarrAbilityEffectMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[12] =
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
        static DB2Meta instance(0, 12, 0x682EE0E1, fields, 1);
        return &instance;
    }
};

struct GarrBuildingMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[24] =
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
        static DB2Meta instance(-1, 24, 0x158D48D4, fields, -1);
        return &instance;
    }
};

struct GarrBuildingDoodadSetMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[5] =
        {
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 5, 0x9A6DE309, fields, -1);
        return &instance;
    }
};

struct GarrBuildingPlotInstMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[5] =
        {
            { FT_FLOAT, 2, true },
            { FT_INT, 1, false },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(1, 5, 0xFB61E627, fields, 2);
        return &instance;
    }
};

struct GarrClassSpecMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[8] =
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
        static DB2Meta instance(3, 8, 0x644E1AC4, fields, -1);
        return &instance;
    }
};

struct GarrClassSpecPlayerCondMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[6] =
        {
            { FT_STRING, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 6, 0x561DEBFE, fields, -1);
        return &instance;
    }
};

struct GarrEncounterMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[7] =
        {
            { FT_STRING, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, false },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
        };
        static DB2Meta instance(1, 7, 0xD193D559, fields, -1);
        return &instance;
    }
};

struct GarrEncounterSetXEncounterMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
        };
        static DB2Meta instance(0, 3, 0xCA7143E7, fields, 2);
        return &instance;
    }
};

struct GarrEncounterXMechanicMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 3, 0x0960A66B, fields, 2);
        return &instance;
    }
};

struct GarrFollItemSetMemberMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_INT, 1, true },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 4, 0x9166B16F, fields, 3);
        return &instance;
    }
};

struct GarrFollSupportSpellMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 4, 0xDB563FC8, fields, 3);
        return &instance;
    }
};

struct GarrFollowerMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[32] =
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
        static DB2Meta instance(3, 32, 0x7C5C19F1, fields, -1);
        return &instance;
    }
};

struct GarrFollowerLevelXPMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 4, 0xABD178B2, fields, -1);
        return &instance;
    }
};

struct GarrFollowerQualityMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[7] =
        {
            { FT_BYTE, 1, false },
            { FT_INT, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
            { FT_INT, 1, false },
        };
        static DB2Meta instance(-1, 7, 0xCAE87042, fields, -1);
        return &instance;
    }
};

struct GarrFollowerSetXFollowerMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 2, 0x621C60FF, fields, 1);
        return &instance;
    }
};

struct GarrFollowerTypeMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[7] =
        {
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 7, 0xB4B34EF0, fields, -1);
        return &instance;
    }
};

struct GarrFollowerUICreatureMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[6] =
        {
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 6, 0x93A1FAA6, fields, 5);
        return &instance;
    }
};

struct GarrFollowerXAbilityMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 4, 0x590C69F7, fields, 3);
        return &instance;
    }
};

struct GarrItemLevelUpgradeDataMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[5] =
        {
            { FT_INT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(0, 5, 0x6B8723A1, fields, -1);
        return &instance;
    }
};

struct GarrMechanicMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_BYTE, 1, false },
            { FT_FLOAT, 1, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 3, 0xA83BF5A9, fields, -1);
        return &instance;
    }
};

struct GarrMechanicSetXMechanicMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_INT, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, false },
        };
        static DB2Meta instance(0, 3, 0xFC7F16A3, fields, 2);
        return &instance;
    }
};

struct GarrMechanicTypeMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[5] =
        {
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(2, 5, 0x05F19FE7, fields, -1);
        return &instance;
    }
};

struct GarrMissionMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[29] =
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
        static DB2Meta instance(5, 29, 0x00777205, fields, 28);
        return &instance;
    }
};

struct GarrMissionTextureMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_FLOAT, 2, true },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 2, 0x0D378464, fields, -1);
        return &instance;
    }
};

struct GarrMissionTypeMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_STRING, 1, true },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 3, 0x3FC87149, fields, -1);
        return &instance;
    }
};

struct GarrMissionXEncounterMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[5] =
        {
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(0, 5, 0x539B5B1B, fields, 4);
        return &instance;
    }
};

struct GarrMissionXFollowerMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 3, 0xFB9C7E3D, fields, 2);
        return &instance;
    }
};

struct GarrMssnBonusAbilityMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[5] =
        {
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
            { FT_FLOAT, 1, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 5, 0x91DD4CE6, fields, -1);
        return &instance;
    }
};

struct GarrPlotMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[7] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 2, false },
        };
        static DB2Meta instance(-1, 7, 0x3897880E, fields, -1);
        return &instance;
    }
};

struct GarrPlotBuildingMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 2, 0x1ECDCE0A, fields, -1);
        return &instance;
    }
};

struct GarrPlotInstanceMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 2, 0x1FD77CCF, fields, -1);
        return &instance;
    }
};

struct GarrPlotUICategoryMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_STRING, 1, true },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 2, 0x867482E6, fields, -1);
        return &instance;
    }
};

struct GarrSiteLevelMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[9] =
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
        static DB2Meta instance(-1, 9, 0x4D823E68, fields, -1);
        return &instance;
    }
};

struct GarrSiteLevelPlotInstMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_FLOAT, 2, true },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 4, 0xA3DF8AD1, fields, 1);
        return &instance;
    }
};

struct GarrSpecializationMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[7] =
        {
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
            { FT_FLOAT, 2, true },
        };
        static DB2Meta instance(-1, 7, 0x8400A7E7, fields, -1);
        return &instance;
    }
};

struct GarrStringMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[1] =
        {
            { FT_STRING, 1, true },
        };
        static DB2Meta instance(-1, 1, 0xF404C7D8, fields, -1);
        return &instance;
    }
};

struct GarrTalentMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[20] =
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
        static DB2Meta instance(2, 20, 0x96BE787E, fields, 3);
        return &instance;
    }
};

struct GarrTalentTreeMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[7] =
        {
            { FT_STRING, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, true },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 7, 0x9A3BC97D, fields, -1);
        return &instance;
    }
};

struct GarrTypeMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[5] =
        {
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 2, true },
        };
        static DB2Meta instance(-1, 5, 0xCCA7D7B5, fields, -1);
        return &instance;
    }
};

struct GarrUiAnimClassInfoMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[6] =
        {
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_FLOAT, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
        };
        static DB2Meta instance(-1, 6, 0xF6444415, fields, -1);
        return &instance;
    }
};

struct GarrUiAnimRaceInfoMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[13] =
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
        static DB2Meta instance(-1, 13, 0x62B1D302, fields, -1);
        return &instance;
    }
};

struct GemPropertiesMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_SHORT, 1, false },
            { FT_INT, 1, true },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 3, 0xBCE902DB, fields, -1);
        return &instance;
    }
};

struct GlobalStringsMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_STRING, 1, true },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 3, 0x843675FD, fields, -1);
        return &instance;
    }
};

struct GlyphBindableSpellMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_INT, 1, true },
            { FT_SHORT, 1, true },
        };
        static DB2Meta instance(-1, 2, 0x03429C72, fields, 1);
        return &instance;
    }
};

struct GlyphExclusiveCategoryMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[1] =
        {
            { FT_STRING, 1, true },
        };
        static DB2Meta instance(-1, 1, 0x59622339, fields, -1);
        return &instance;
    }
};

struct GlyphPropertiesMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_INT, 1, false },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 4, 0x7C1C2F11, fields, -1);
        return &instance;
    }
};

struct GlyphRequiredSpecMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 2, 0x70D4ECC6, fields, 1);
        return &instance;
    }
};

struct GroundEffectDoodadMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_INT, 1, true },
            { FT_BYTE, 1, false },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
        };
        static DB2Meta instance(-1, 4, 0xAB0C6E12, fields, -1);
        return &instance;
    }
};

struct GroundEffectTextureMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_INT, 1, false },
            { FT_BYTE, 1, false },
            { FT_SHORT, 4, false },
            { FT_BYTE, 4, true },
        };
        static DB2Meta instance(-1, 4, 0xCCBD52E8, fields, -1);
        return &instance;
    }
};

struct GroupFinderActivityMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[14] =
        {
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 14, 0xEC40E4B1, fields, -1);
        return &instance;
    }
};

struct GroupFinderActivityGrpMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_STRING, 1, true },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 2, 0x1EC8D046, fields, -1);
        return &instance;
    }
};

struct GroupFinderCategoryMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_STRING, 1, true },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 3, 0xBFF47DC0, fields, -1);
        return &instance;
    }
};

struct GuildColorBackgroundMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 3, 0xCC5FFB4D, fields, -1);
        return &instance;
    }
};

struct GuildColorBorderMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 3, 0xCC5FFB4D, fields, -1);
        return &instance;
    }
};

struct GuildColorEmblemMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 3, 0xCC5FFB4D, fields, -1);
        return &instance;
    }
};

struct GuildPerkSpellsMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[1] =
        {
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 1, 0xC9961BEB, fields, -1);
        return &instance;
    }
};

struct HeirloomMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[10] =
        {
            { FT_STRING, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 3, true },
            { FT_SHORT, 3, false },
        };
        static DB2Meta instance(1, 10, 0xB5925FE9, fields, -1);
        return &instance;
    }
};

struct HelmetAnimScalingMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_INT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 3, 0xC43CA2FC, fields, 2);
        return &instance;
    }
};

struct HelmetGeosetVisDataMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[1] =
        {
            { FT_INT, 9, true },
        };
        static DB2Meta instance(-1, 1, 0x2E7C7FED, fields, -1);
        return &instance;
    }
};

struct HighlightColorMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[5] =
        {
            { FT_BYTE, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 5, 0xDC14DB43, fields, -1);
        return &instance;
    }
};

struct HolidayDescriptionsMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[1] =
        {
            { FT_STRING, 1, true },
        };
        static DB2Meta instance(-1, 1, 0xE70F298C, fields, -1);
        return &instance;
    }
};

struct HolidayNamesMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[1] =
        {
            { FT_STRING, 1, true },
        };
        static DB2Meta instance(-1, 1, 0xF2917D77, fields, -1);
        return &instance;
    }
};

struct HolidaysMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[12] =
        {
            { FT_INT, 1, false },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, false },
            { FT_SHORT, 10, false },
            { FT_INT, 16, false },
            { FT_BYTE, 10, false },
            { FT_INT, 3, true },
        };
        static DB2Meta instance(0, 12, 0xF6DA3904, fields, -1);
        return &instance;
    }
};

struct HotfixesMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 3, 0xB67D3F47, fields, -1);
        return &instance;
    }
};

struct ImportPriceArmorMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
        };
        static DB2Meta instance(-1, 4, 0xC4C8D847, fields, -1);
        return &instance;
    }
};

struct ImportPriceQualityMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[1] =
        {
            { FT_FLOAT, 1, true },
        };
        static DB2Meta instance(-1, 1, 0xCFF4EEC9, fields, -1);
        return &instance;
    }
};

struct ImportPriceShieldMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[1] =
        {
            { FT_FLOAT, 1, true },
        };
        static DB2Meta instance(-1, 1, 0xCFF4EEC9, fields, -1);
        return &instance;
    }
};

struct ImportPriceWeaponMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[1] =
        {
            { FT_FLOAT, 1, true },
        };
        static DB2Meta instance(-1, 1, 0xCFF4EEC9, fields, -1);
        return &instance;
    }
};

struct InvasionClientDataMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[10] =
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
        static DB2Meta instance(2, 10, 0x04FC0B4F, fields, 9);
        return &instance;
    }
};

struct ItemMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[8] =
        {
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, true },
            { FT_INT, 1, true },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 8, 0xF9600007, fields, -1);
        return &instance;
    }
};

struct ItemAppearanceMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 4, 0x422F764D, fields, -1);
        return &instance;
    }
};

struct ItemAppearanceXUiCameraMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 2, 0xCD3677FD, fields, -1);
        return &instance;
    }
};

struct ItemArmorQualityMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[1] =
        {
            { FT_FLOAT, 7, true },
        };
        static DB2Meta instance(-1, 1, 0x0B17E016, fields, -1);
        return &instance;
    }
};

struct ItemArmorShieldMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_FLOAT, 7, true },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 2, 0xC88C8C8D, fields, -1);
        return &instance;
    }
};

struct ItemArmorTotalMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[5] =
        {
            { FT_SHORT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
        };
        static DB2Meta instance(-1, 5, 0xC4CD0FD9, fields, -1);
        return &instance;
    }
};

struct ItemBagFamilyMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[1] =
        {
            { FT_STRING, 1, true },
        };
        static DB2Meta instance(-1, 1, 0x9F2C8370, fields, -1);
        return &instance;
    }
};

struct ItemBonusMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_INT, 3, true },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 4, 0xB96C1748, fields, 1);
        return &instance;
    }
};

struct ItemBonusListLevelDeltaMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_SHORT, 1, true },
            { FT_INT, 1, false },
        };
        static DB2Meta instance(1, 2, 0x819C0CC1, fields, -1);
        return &instance;
    }
};

struct ItemBonusTreeNodeMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[5] =
        {
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 5, 0x1DDAA885, fields, 4);
        return &instance;
    }
};

struct ItemChildEquipmentMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_INT, 1, true },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 3, 0x48E64550, fields, 2);
        return &instance;
    }
};

struct ItemClassMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_STRING, 1, true },
            { FT_BYTE, 1, true },
            { FT_FLOAT, 1, true },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 4, 0xB6C67A3D, fields, -1);
        return &instance;
    }
};

struct ItemContextPickerEntryMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[6] =
        {
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
        };
        static DB2Meta instance(-1, 6, 0x1596EAF3, fields, 5);
        return &instance;
    }
};

struct ItemCurrencyCostMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[1] =
        {
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 1, 0xDAC6A93C, fields, 0);
        return &instance;
    }
};

struct ItemDamageAmmoMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_SHORT, 1, false },
            { FT_FLOAT, 7, true },
        };
        static DB2Meta instance(-1, 2, 0x1309BE8D, fields, -1);
        return &instance;
    }
};

struct ItemDamageOneHandMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_SHORT, 1, false },
            { FT_FLOAT, 7, true },
        };
        static DB2Meta instance(-1, 2, 0x1309BE8D, fields, -1);
        return &instance;
    }
};

struct ItemDamageOneHandCasterMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_SHORT, 1, false },
            { FT_FLOAT, 7, true },
        };
        static DB2Meta instance(-1, 2, 0x1309BE8D, fields, -1);
        return &instance;
    }
};

struct ItemDamageTwoHandMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_SHORT, 1, false },
            { FT_FLOAT, 7, true },
        };
        static DB2Meta instance(-1, 2, 0x1309BE8D, fields, -1);
        return &instance;
    }
};

struct ItemDamageTwoHandCasterMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_SHORT, 1, false },
            { FT_FLOAT, 7, true },
        };
        static DB2Meta instance(-1, 2, 0x1309BE8D, fields, -1);
        return &instance;
    }
};

struct ItemDisenchantLootMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[7] =
        {
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 7, 0x146B9F40, fields, 6);
        return &instance;
    }
};

struct ItemDisplayInfoMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[15] =
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
            { FT_INT, 6, true },
            { FT_INT, 6, true },
            { FT_INT, 2, true },
        };
        static DB2Meta instance(-1, 15, 0x089404D9, fields, -1);
        return &instance;
    }
};

struct ItemDisplayInfoMaterialResMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_BYTE, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 3, 0x936E6A99, fields, 2);
        return &instance;
    }
};

struct ItemDisplayXUiCameraMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_INT, 1, true },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 2, 0x3E999EAA, fields, -1);
        return &instance;
    }
};

struct ItemEffectMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[9] =
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
        static DB2Meta instance(-1, 9, 0x46818AA6, fields, 8);
        return &instance;
    }
};

struct ItemExtendedCostMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[10] =
        {
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 5, true },
            { FT_SHORT, 5, false },
            { FT_SHORT, 5, false },
            { FT_INT, 5, false },
        };
        static DB2Meta instance(-1, 10, 0x2AC5BE11, fields, -1);
        return &instance;
    }
};

struct ItemGroupSoundsMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[1] =
        {
            { FT_INT, 4, false },
        };
        static DB2Meta instance(-1, 1, 0x909375D2, fields, -1);
        return &instance;
    }
};

struct ItemLevelSelectorMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 2, 0x3112276E, fields, -1);
        return &instance;
    }
};

struct ItemLevelSelectorQualityMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_INT, 1, true },
            { FT_BYTE, 1, true },
            { FT_SHORT, 1, true },
        };
        static DB2Meta instance(-1, 3, 0xC40169D5, fields, 2);
        return &instance;
    }
};

struct ItemLevelSelectorQualitySetMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_SHORT, 1, true },
            { FT_SHORT, 1, true },
        };
        static DB2Meta instance(-1, 2, 0x89657A48, fields, -1);
        return &instance;
    }
};

struct ItemLimitCategoryMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_STRING, 1, true },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 3, 0xE068171C, fields, -1);
        return &instance;
    }
};

struct ItemLimitCategoryConditionMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_BYTE, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 3, 0x7F847085, fields, 2);
        return &instance;
    }
};

struct ItemModifiedAppearanceMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[6] =
        {
            { FT_INT, 1, false },
            { FT_INT, 1, true },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, true },
        };
        static DB2Meta instance(0, 6, 0x9C32B7FF, fields, 1);
        return &instance;
    }
};

struct ItemModifiedAppearanceExtraMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[5] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, true },
        };
        static DB2Meta instance(-1, 5, 0x7E2FD302, fields, -1);
        return &instance;
    }
};

struct ItemNameDescriptionMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_STRING, 1, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 2, 0xBBF04CCC, fields, -1);
        return &instance;
    }
};

struct ItemPetFoodMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[1] =
        {
            { FT_STRING, 1, true },
        };
        static DB2Meta instance(-1, 1, 0xD6AB60EB, fields, -1);
        return &instance;
    }
};

struct ItemPriceBaseMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_SHORT, 1, false },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
        };
        static DB2Meta instance(-1, 3, 0xC90092C7, fields, -1);
        return &instance;
    }
};

struct ItemRandomPropertiesMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_STRING, 1, true },
            { FT_SHORT, 5, false },
        };
        static DB2Meta instance(-1, 2, 0xBDA8BFCD, fields, -1);
        return &instance;
    }
};

struct ItemRandomSuffixMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_STRING, 1, true },
            { FT_SHORT, 5, false },
            { FT_SHORT, 5, false },
        };
        static DB2Meta instance(-1, 3, 0xABCC4871, fields, -1);
        return &instance;
    }
};

struct ItemRangedDisplayInfoMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
        };
        static DB2Meta instance(-1, 4, 0xA6B99F0D, fields, -1);
        return &instance;
    }
};

struct ItemSearchNameMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[14] =
        {
            { FT_LONG, 1, true },
            { FT_STRING, 1, true },
            { FT_INT, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
            { FT_BYTE, 1, true },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_INT, 1, false },
            { FT_SHORT, 1, false },
            { FT_INT, 4, true },
        };
        static DB2Meta instance(2, 14, 0xF0940AFC, fields, -1);
        return &instance;
    }
};

struct ItemSetMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[5] =
        {
            { FT_STRING, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_SHORT, 1, false },
            { FT_INT, 17, false },
        };
        static DB2Meta instance(-1, 5, 0xB02A9041, fields, -1);
        return &instance;
    }
};

struct ItemSetSpellMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_SHORT, 1, false },
            { FT_INT, 1, false },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 4, 0xD6AEEA60, fields, 3);
        return &instance;
    }
};

struct ItemSparseMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[64] =
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
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 10, true },
            { FT_INT, 10, true },
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
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
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
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 64, 0xF9021F01, fields, -1);
        return &instance;
    }
};

struct ItemSpecMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[6] =
        {
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 6, 0xEB138F8E, fields, 2);
        return &instance;
    }
};

struct ItemSpecOverrideMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_SHORT, 1, false },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 2, 0xB235D33A, fields, 1);
        return &instance;
    }
};

struct ItemSubClassMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[10] =
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
        static DB2Meta instance(-1, 10, 0xC7178B11, fields, 2);
        return &instance;
    }
};

struct ItemSubClassMaskMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_STRING, 1, true },
            { FT_BYTE, 1, false },
            { FT_INT, 1, false },
        };
        static DB2Meta instance(-1, 3, 0x146E3154, fields, -1);
        return &instance;
    }
};

struct ItemUpgradeMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[5] =
        {
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_INT, 1, false },
        };
        static DB2Meta instance(-1, 5, 0x706FA369, fields, -1);
        return &instance;
    }
};

struct ItemVisualsMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[1] =
        {
            { FT_INT, 5, true },
        };
        static DB2Meta instance(-1, 1, 0x4025FA36, fields, -1);
        return &instance;
    }
};

struct ItemXBonusTreeMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_SHORT, 1, false },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 2, 0x57244BD5, fields, 1);
        return &instance;
    }
};

struct JournalEncounterMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[10] =
        {
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_FLOAT, 2, true },
            { FT_SHORT, 1, false },
            { FT_INT, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_INT, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, true },
        };
        static DB2Meta instance(-1, 10, 0x5E057FAD, fields, -1);
        return &instance;
    }
};

struct JournalEncounterCreatureMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[8] =
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
        static DB2Meta instance(2, 8, 0x71CE658D, fields, 3);
        return &instance;
    }
};

struct JournalEncounterItemMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[6] =
        {
            { FT_INT, 1, false },
            { FT_SHORT, 1, false },
            { FT_INT, 1, false },
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, true },
        };
        static DB2Meta instance(0, 6, 0x5FD94071, fields, 1);
        return &instance;
    }
};

struct JournalEncounterSectionMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[15] =
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
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, true },
        };
        static DB2Meta instance(-1, 15, 0x582FB4F6, fields, -1);
        return &instance;
    }
};

struct JournalEncounterXDifficultyMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 2, 0x436676BA, fields, 1);
        return &instance;
    }
};

struct JournalEncounterXMapLocMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[5] =
        {
            { FT_FLOAT, 2, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 5, 0xBCE56697, fields, 4);
        return &instance;
    }
};

struct JournalInstanceMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[11] =
        {
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_INT, 1, false },
            { FT_SHORT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(2, 11, 0xBB10478F, fields, -1);
        return &instance;
    }
};

struct JournalItemXDifficultyMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 2, 0xF938F4BD, fields, 1);
        return &instance;
    }
};

struct JournalSectionXDifficultyMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 2, 0xE02C355F, fields, 1);
        return &instance;
    }
};

struct JournalTierMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[1] =
        {
            { FT_STRING, 1, true },
        };
        static DB2Meta instance(-1, 1, 0xE0D727CB, fields, -1);
        return &instance;
    }
};

struct JournalTierXInstanceMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 2, 0xD584CE6A, fields, 0);
        return &instance;
    }
};

struct KeychainMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[1] =
        {
            { FT_BYTE, 32, false },
        };
        static DB2Meta instance(-1, 1, 0x67DDA82E, fields, -1);
        return &instance;
    }
};

struct KeystoneAffixMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(2, 4, 0x60D97B7F, fields, -1);
        return &instance;
    }
};

struct LFGDungeonExpansionMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[7] =
        {
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 7, 0x6754EDAB, fields, 6);
        return &instance;
    }
};

struct LFGDungeonGroupMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_STRING, 1, true },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 4, 0x4E84BE76, fields, -1);
        return &instance;
    }
};

struct LFGDungeonsMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[33] =
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
        static DB2Meta instance(-1, 33, 0xD9B678AD, fields, -1);
        return &instance;
    }
};

struct LFGRoleRequirementMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_BYTE, 1, true },
            { FT_INT, 1, false },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 3, 0x35B34A59, fields, 2);
        return &instance;
    }
};

struct LanguageWordsMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 2, 0xFBB33D15, fields, -1);
        return &instance;
    }
};

struct LanguagesMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_STRING, 1, true },
            { FT_INT, 1, false },
        };
        static DB2Meta instance(1, 2, 0xAA508D47, fields, -1);
        return &instance;
    }
};

struct LfgDungeonsGroupingMapMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 3, 0xD50B89E4, fields, 2);
        return &instance;
    }
};

struct LightMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[5] =
        {
            { FT_FLOAT, 3, true },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_SHORT, 1, true },
            { FT_SHORT, 8, false },
        };
        static DB2Meta instance(-1, 5, 0x04052B1F, fields, -1);
        return &instance;
    }
};

struct LightDataMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[36] =
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
            { FT_INT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, false },
            { FT_FLOAT, 1, true },
            { FT_INT, 1, false },
            { FT_FLOAT, 1, true },
            { FT_INT, 1, false },
        };
        static DB2Meta instance(-1, 36, 0xE7CA3F85, fields, 0);
        return &instance;
    }
};

struct LightParamsMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[12] =
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
        static DB2Meta instance(1, 12, 0xA08FAABA, fields, -1);
        return &instance;
    }
};

struct LightSkyboxMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 4, 0x757E9EB6, fields, -1);
        return &instance;
    }
};

struct LightningMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[34] =
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
        static DB2Meta instance(-1, 34, 0x8B6D192C, fields, -1);
        return &instance;
    }
};

struct LiquidMaterialMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, true },
        };
        static DB2Meta instance(-1, 2, 0x6A7287A2, fields, -1);
        return &instance;
    }
};

struct LiquidObjectMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[5] =
        {
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_SHORT, 1, true },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 5, 0x7AF380AA, fields, -1);
        return &instance;
    }
};

struct LiquidTypeMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[21] =
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
        static DB2Meta instance(-1, 21, 0x29F8C65E, fields, -1);
        return &instance;
    }
};

struct LoadingScreenTaxiSplinesMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[5] =
        {
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
            { FT_FLOAT, 10, true },
            { FT_FLOAT, 10, true },
        };
        static DB2Meta instance(-1, 5, 0xCDF5DDF1, fields, -1);
        return &instance;
    }
};

struct LoadingScreensMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 3, 0xA2488A1C, fields, -1);
        return &instance;
    }
};

struct LocaleMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 4, 0x65638FD5, fields, -1);
        return &instance;
    }
};

struct LocationMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_FLOAT, 3, true },
            { FT_FLOAT, 3, true },
        };
        static DB2Meta instance(-1, 2, 0x71BD1122, fields, -1);
        return &instance;
    }
};

struct LockMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_INT, 8, true },
            { FT_SHORT, 8, false },
            { FT_BYTE, 8, false },
            { FT_BYTE, 8, false },
        };
        static DB2Meta instance(-1, 4, 0x156C0BD7, fields, -1);
        return &instance;
    }
};

struct LockTypeMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[5] =
        {
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_INT, 1, false },
        };
        static DB2Meta instance(4, 5, 0x3F736720, fields, -1);
        return &instance;
    }
};

struct LookAtControllerMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[18] =
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
        static DB2Meta instance(-1, 18, 0x2E077E56, fields, -1);
        return &instance;
    }
};

struct MailTemplateMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[1] =
        {
            { FT_STRING, 1, true },
        };
        static DB2Meta instance(-1, 1, 0xC6E0D9B5, fields, -1);
        return &instance;
    }
};

struct ManagedWorldStateMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[10] =
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
        static DB2Meta instance(0, 10, 0x043BFC8F, fields, -1);
        return &instance;
    }
};

struct ManagedWorldStateBuffMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 4, 0x049B986F, fields, 3);
        return &instance;
    }
};

struct ManagedWorldStateInputMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 3, 0x21237CDC, fields, -1);
        return &instance;
    }
};

struct ManifestInterfaceActionIconMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[1] =
        {
            { FT_INT, 1, false },
        };
        static DB2Meta instance(0, 1, 0xB5EE0DCB, fields, -1);
        return &instance;
    }
};

struct ManifestInterfaceDataMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_STRING_NOT_LOCALIZED, 1, true },
        };
        static DB2Meta instance(-1, 2, 0x03E4C021, fields, -1);
        return &instance;
    }
};

struct ManifestInterfaceItemIconMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[1] =
        {
            { FT_INT, 1, false },
        };
        static DB2Meta instance(0, 1, 0xB5EE0DCB, fields, -1);
        return &instance;
    }
};

struct ManifestInterfaceTOCDataMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[1] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
        };
        static DB2Meta instance(-1, 1, 0xD00DAF09, fields, -1);
        return &instance;
    }
};

struct ManifestMP3Meta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[1] =
        {
            { FT_INT, 1, false },
        };
        static DB2Meta instance(0, 1, 0xB5EE0DCB, fields, -1);
        return &instance;
    }
};

struct MapMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[22] =
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
            { FT_INT, 2, true },
        };
        static DB2Meta instance(-1, 22, 0x503A3E58, fields, -1);
        return &instance;
    }
};

struct MapCelestialBodyMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_SHORT, 1, true },
            { FT_INT, 1, false },
            { FT_SHORT, 1, true },
        };
        static DB2Meta instance(-1, 3, 0x14543648, fields, 2);
        return &instance;
    }
};

struct MapChallengeModeMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[5] =
        {
            { FT_STRING, 1, true },
            { FT_INT, 1, false },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
            { FT_SHORT, 3, true },
        };
        static DB2Meta instance(1, 5, 0x50F3ABC2, fields, 2);
        return &instance;
    }
};

struct MapDifficultyMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[10] =
        {
            { FT_STRING, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 10, 0xF876E8BA, fields, 9);
        return &instance;
    }
};

struct MapDifficultyXConditionMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_STRING, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, false },
        };
        static DB2Meta instance(-1, 4, 0x8DBA5D16, fields, 3);
        return &instance;
    }
};

struct MapLoadingScreenMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[5] =
        {
            { FT_FLOAT, 2, true },
            { FT_FLOAT, 2, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 5, 0xC4CFD9A8, fields, 4);
        return &instance;
    }
};

struct MarketingPromotionsXLocaleMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[7] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 7, 0xC04E61FB, fields, -1);
        return &instance;
    }
};

struct MaterialMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_BYTE, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
        };
        static DB2Meta instance(-1, 4, 0x370D43B4, fields, -1);
        return &instance;
    }
};

struct MinorTalentMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 3, 0x09F57B9C, fields, 2);
        return &instance;
    }
};

struct MissileTargetingMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[12] =
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
        static DB2Meta instance(-1, 12, 0xF695DDBA, fields, -1);
        return &instance;
    }
};

struct ModelAnimCloakDampeningMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
        };
        static DB2Meta instance(-1, 3, 0xAA668B4F, fields, 2);
        return &instance;
    }
};

struct ModelFileDataMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_INT, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, false },
        };
        static DB2Meta instance(0, 4, 0x9C9B4543, fields, 3);
        return &instance;
    }
};

struct ModelRibbonQualityMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 2, 0xA26E8DD1, fields, 1);
        return &instance;
    }
};

struct ModifierTreeMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[7] =
        {
            { FT_INT, 1, false },
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_BYTE, 1, true },
        };
        static DB2Meta instance(-1, 7, 0x643002AE, fields, -1);
        return &instance;
    }
};

struct MountMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[11] =
        {
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_INT, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, false },
            { FT_FLOAT, 1, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(3, 11, 0x629E87E2, fields, -1);
        return &instance;
    }
};

struct MountCapabilityMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[8] =
        {
            { FT_INT, 1, false },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_SHORT, 1, true },
        };
        static DB2Meta instance(0, 8, 0xD8A906D6, fields, -1);
        return &instance;
    }
};

struct MountTypeXCapabilityMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 3, 0x613701E9, fields, 0);
        return &instance;
    }
};

struct MountXDisplayMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 3, 0x2D4F3D78, fields, 2);
        return &instance;
    }
};

struct MovieMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
        };
        static DB2Meta instance(-1, 4, 0x4848C4FB, fields, -1);
        return &instance;
    }
};

struct MovieFileDataMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[1] =
        {
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 1, 0xB24F82EB, fields, -1);
        return &instance;
    }
};

struct MovieVariationMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 3, 0xAEA671AA, fields, 2);
        return &instance;
    }
};

struct MultiStatePropertiesMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[11] =
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
        static DB2Meta instance(-1, 11, 0x50BB5EDC, fields, 10);
        return &instance;
    }
};

struct MultiTransitionPropertiesMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[5] =
        {
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 5, 0x5720F452, fields, -1);
        return &instance;
    }
};

struct MythicPlusSeasonRewardLevelsMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 4, 0xAD6A6D9F, fields, 3);
        return &instance;
    }
};

struct NPCModelItemSlotDisplayInfoMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_INT, 1, true },
            { FT_BYTE, 1, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 3, 0xB8EC2628, fields, 2);
        return &instance;
    }
};

struct NPCSoundsMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[1] =
        {
            { FT_INT, 4, false },
        };
        static DB2Meta instance(-1, 1, 0x5EF56D1F, fields, -1);
        return &instance;
    }
};

struct NameGenMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 3, 0xB0EBC6C9, fields, -1);
        return &instance;
    }
};

struct NamesProfanityMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_BYTE, 1, true },
        };
        static DB2Meta instance(-1, 2, 0xCD33D2BE, fields, -1);
        return &instance;
    }
};

struct NamesReservedMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[1] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
        };
        static DB2Meta instance(-1, 1, 0xECCAE96B, fields, -1);
        return &instance;
    }
};

struct NamesReservedLocaleMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 2, 0x5AAEEDD3, fields, -1);
        return &instance;
    }
};

struct NumTalentsAtLevelMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_INT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(0, 4, 0xDE3268EF, fields, -1);
        return &instance;
    }
};

struct ObjectEffectMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[8] =
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
        static DB2Meta instance(-1, 8, 0x48D89FCF, fields, -1);
        return &instance;
    }
};

struct ObjectEffectModifierMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_FLOAT, 4, true },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 4, 0x68D120B3, fields, -1);
        return &instance;
    }
};

struct ObjectEffectPackageElemMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 3, 0x3B8C53F9, fields, -1);
        return &instance;
    }
};

struct OccluderMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[9] =
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
        static DB2Meta instance(0, 9, 0xFEDCAAB3, fields, -1);
        return &instance;
    }
};

struct OccluderLocationMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_FLOAT, 3, true },
            { FT_FLOAT, 3, true },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(2, 4, 0x95F8BBE4, fields, -1);
        return &instance;
    }
};

struct OccluderNodeMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_INT, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(0, 4, 0x19A34490, fields, -1);
        return &instance;
    }
};

struct OutlineEffectMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[6] =
        {
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_INT, 2, false },
        };
        static DB2Meta instance(-1, 6, 0xECA16738, fields, -1);
        return &instance;
    }
};

struct OverrideSpellDataMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_INT, 10, true },
            { FT_INT, 1, true },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 3, 0xCEE01938, fields, -1);
        return &instance;
    }
};

struct PVPBracketTypesMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_BYTE, 1, true },
            { FT_INT, 4, false },
        };
        static DB2Meta instance(-1, 2, 0x54CF87FB, fields, -1);
        return &instance;
    }
};

struct PVPDifficultyMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 4, 0x794DB95D, fields, 3);
        return &instance;
    }
};

struct PVPItemMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_INT, 1, true },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 2, 0x0CD750C1, fields, -1);
        return &instance;
    }
};

struct PageTextMaterialMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[1] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
        };
        static DB2Meta instance(-1, 1, 0xF6F6B04B, fields, -1);
        return &instance;
    }
};

struct PaperDollItemFrameMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_INT, 1, true },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 3, 0xB85F646E, fields, -1);
        return &instance;
    }
};

struct ParagonReputationMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_INT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 3, 0xF9AC6E2E, fields, 0);
        return &instance;
    }
};

struct ParticleColorMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_INT, 3, true },
            { FT_INT, 3, true },
            { FT_INT, 3, true },
        };
        static DB2Meta instance(-1, 3, 0xB44B4D4D, fields, -1);
        return &instance;
    }
};

struct ParticulateSoundMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[5] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 5, 0xF60E0955, fields, 0);
        return &instance;
    }
};

struct PathMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[7] =
        {
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 7, 0x3551690B, fields, -1);
        return &instance;
    }
};

struct PathNodeMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_INT, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(0, 4, 0x19A34490, fields, -1);
        return &instance;
    }
};

struct PathNodePropertyMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[5] =
        {
            { FT_INT, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(0, 5, 0x578DA815, fields, -1);
        return &instance;
    }
};

struct PathPropertyMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_INT, 1, false },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(0, 4, 0x3B269A90, fields, -1);
        return &instance;
    }
};

struct PhaseMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[1] =
        {
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 1, 0x60D39728, fields, -1);
        return &instance;
    }
};

struct PhaseShiftZoneSoundsMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[13] =
        {
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 13, 0x7CA0A010, fields, -1);
        return &instance;
    }
};

struct PhaseXPhaseGroupMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 2, 0xF00195AE, fields, 1);
        return &instance;
    }
};

struct PlayerConditionMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[81] =
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
            { FT_SHORT, 1, false },
            { FT_INT, 1, false },
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
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
            { FT_SHORT, 4, false },
            { FT_SHORT, 4, false },
            { FT_SHORT, 4, false },
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
        static DB2Meta instance(2, 81, 0xF28CBD18, fields, -1);
        return &instance;
    }
};

struct PositionerMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
            { FT_FLOAT, 1, true },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 4, 0x533B33CB, fields, -1);
        return &instance;
    }
};

struct PositionerStateMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[8] =
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
        static DB2Meta instance(-1, 8, 0x9E87B63A, fields, -1);
        return &instance;
    }
};

struct PositionerStateEntryMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[11] =
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
        static DB2Meta instance(-1, 11, 0xBA9A19C4, fields, -1);
        return &instance;
    }
};

struct PowerDisplayMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[5] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 5, 0xEB89C62F, fields, -1);
        return &instance;
    }
};

struct PowerTypeMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[12] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, true },
            { FT_SHORT, 1, true },
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, true },
            { FT_SHORT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_SHORT, 1, true },
        };
        static DB2Meta instance(-1, 12, 0x6D438CB5, fields, -1);
        return &instance;
    }
};

struct PrestigeLevelInfoMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[5] =
        {
            { FT_STRING, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 5, 0x31BD813F, fields, -1);
        return &instance;
    }
};

struct PvpScalingEffectMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_FLOAT, 1, true },
        };
        static DB2Meta instance(-1, 3, 0xAF88F6DB, fields, 1);
        return &instance;
    }
};

struct PvpScalingEffectTypeMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[1] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
        };
        static DB2Meta instance(-1, 1, 0xF6F6B04B, fields, -1);
        return &instance;
    }
};

struct PvpTalentMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[9] =
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
        static DB2Meta instance(1, 9, 0x340BABA3, fields, 2);
        return &instance;
    }
};

struct PvpTalentCategoryMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[1] =
        {
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 1, 0xBB4B5731, fields, -1);
        return &instance;
    }
};

struct PvpTalentSlotUnlockMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_BYTE, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 4, 0x572DDD84, fields, -1);
        return &instance;
    }
};

struct PvpTierMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[8] =
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
        static DB2Meta instance(-1, 8, 0x689983C8, fields, 5);
        return &instance;
    }
};

struct QuestFactionRewardMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[1] =
        {
            { FT_SHORT, 10, true },
        };
        static DB2Meta instance(-1, 1, 0x504FAFB5, fields, -1);
        return &instance;
    }
};

struct QuestFeedbackEffectMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[6] =
        {
            { FT_INT, 1, false },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 6, 0x58E79FBF, fields, -1);
        return &instance;
    }
};

struct QuestInfoMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_STRING, 1, true },
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 4, 0xDDB38B83, fields, -1);
        return &instance;
    }
};

struct QuestLineMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_INT, 1, false },
        };
        static DB2Meta instance(-1, 3, 0xC4BD3235, fields, -1);
        return &instance;
    }
};

struct QuestLineXQuestMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
        };
        static DB2Meta instance(-1, 3, 0x57EF18BF, fields, 0);
        return &instance;
    }
};

struct QuestMoneyRewardMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[1] =
        {
            { FT_INT, 10, false },
        };
        static DB2Meta instance(-1, 1, 0x7E00C5B6, fields, -1);
        return &instance;
    }
};

struct QuestObjectiveMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[8] =
        {
            { FT_STRING, 1, true },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 8, 0x37353FB6, fields, 7);
        return &instance;
    }
};

struct QuestPOIBlobMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[7] =
        {
            { FT_INT, 1, false },
            { FT_SHORT, 1, true },
            { FT_INT, 1, true },
            { FT_BYTE, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, false },
        };
        static DB2Meta instance(0, 7, 0x5DF4B040, fields, 1);
        return &instance;
    }
};

struct QuestPOIPointMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_INT, 1, false },
            { FT_SHORT, 1, true },
            { FT_SHORT, 1, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(0, 4, 0x18D6E719, fields, 3);
        return &instance;
    }
};

struct QuestPackageItemMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_SHORT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, false },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 4, 0xEB0764D1, fields, -1);
        return &instance;
    }
};

struct QuestSortMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_STRING, 1, true },
            { FT_BYTE, 1, true },
        };
        static DB2Meta instance(-1, 2, 0x2F5E2228, fields, -1);
        return &instance;
    }
};

struct QuestV2Meta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[1] =
        {
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 1, 0x638D02EF, fields, -1);
        return &instance;
    }
};

struct QuestV2CliTaskMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[24] =
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
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
            { FT_SHORT, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 3, false },
        };
        static DB2Meta instance(3, 24, 0xC0387D4E, fields, -1);
        return &instance;
    }
};

struct QuestXGroupActivityMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_INT, 1, false },
            { FT_INT, 1, false },
        };
        static DB2Meta instance(-1, 2, 0xAA88A593, fields, -1);
        return &instance;
    }
};

struct QuestXPMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[1] =
        {
            { FT_SHORT, 10, false },
        };
        static DB2Meta instance(-1, 1, 0xC33E0774, fields, -1);
        return &instance;
    }
};

struct RandPropPointsMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_INT, 1, true },
            { FT_INT, 5, false },
            { FT_INT, 5, false },
            { FT_INT, 5, false },
        };
        static DB2Meta instance(-1, 4, 0x7741F65C, fields, -1);
        return &instance;
    }
};

struct RelicSlotTierRequirementMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 3, 0x22CDBDE9, fields, -1);
        return &instance;
    }
};

struct RelicTalentMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[5] =
        {
            { FT_INT, 1, true },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 5, 0x8BEAE937, fields, -1);
        return &instance;
    }
};

struct ResearchBranchMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[6] =
        {
            { FT_STRING, 1, true },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 6, 0xA6CB64A5, fields, -1);
        return &instance;
    }
};

struct ResearchFieldMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_STRING, 1, true },
            { FT_INT, 1, false },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(1, 3, 0xD7448990, fields, -1);
        return &instance;
    }
};

struct ResearchProjectMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[9] =
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
        static DB2Meta instance(2, 9, 0x4A748755, fields, -1);
        return &instance;
    }
};

struct ResearchSiteMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_STRING, 1, true },
            { FT_SHORT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, false },
        };
        static DB2Meta instance(-1, 4, 0x14F7693B, fields, -1);
        return &instance;
    }
};

struct ResistancesMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_STRING, 1, true },
            { FT_BYTE, 1, false },
            { FT_INT, 1, false },
        };
        static DB2Meta instance(-1, 3, 0xF7F049B5, fields, -1);
        return &instance;
    }
};

struct RewardPackMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[6] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, false },
            { FT_BYTE, 1, true },
            { FT_FLOAT, 1, true },
            { FT_BYTE, 1, false },
            { FT_INT, 1, false },
        };
        static DB2Meta instance(-1, 6, 0xB0527FA7, fields, -1);
        return &instance;
    }
};

struct RewardPackXCurrencyTypeMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_INT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, false },
        };
        static DB2Meta instance(-1, 3, 0xEA88FC16, fields, 2);
        return &instance;
    }
};

struct RewardPackXItemMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 3, 0x277E8179, fields, 2);
        return &instance;
    }
};

struct RibbonQualityMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[5] =
        {
            { FT_BYTE, 1, false },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_INT, 1, false },
        };
        static DB2Meta instance(-1, 5, 0xBB0CC4F4, fields, -1);
        return &instance;
    }
};

struct RulesetItemUpgradeMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_INT, 1, true },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 2, 0xA03B4C48, fields, -1);
        return &instance;
    }
};

struct SDReplacementModelMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[1] =
        {
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 1, 0xD9C05976, fields, -1);
        return &instance;
    }
};

struct ScalingStatDistributionMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_SHORT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 3, 0x34B9A97A, fields, -1);
        return &instance;
    }
};

struct ScenarioMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[5] =
        {
            { FT_STRING, 1, true },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, false },
        };
        static DB2Meta instance(-1, 5, 0x0857765A, fields, -1);
        return &instance;
    }
};

struct ScenarioEventEntryMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_BYTE, 1, false },
            { FT_INT, 1, false },
        };
        static DB2Meta instance(-1, 2, 0x34B30E13, fields, -1);
        return &instance;
    }
};

struct ScenarioStepMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[11] =
        {
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_SHORT, 1, false },
            { FT_INT, 1, false },
            { FT_SHORT, 1, false },
            { FT_INT, 1, true },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, false },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 11, 0x8FF5E1E6, fields, 2);
        return &instance;
    }
};

struct SceneScriptMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 2, 0xEF472E96, fields, -1);
        return &instance;
    }
};

struct SceneScriptGlobalTextMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_STRING_NOT_LOCALIZED, 1, true },
        };
        static DB2Meta instance(-1, 2, 0xDE6E2251, fields, -1);
        return &instance;
    }
};

struct SceneScriptPackageMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[1] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
        };
        static DB2Meta instance(-1, 1, 0xF6F6B04B, fields, -1);
        return &instance;
    }
};

struct SceneScriptPackageMemberMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 4, 0x9E18D06F, fields, 0);
        return &instance;
    }
};

struct SceneScriptTextMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_STRING_NOT_LOCALIZED, 1, true },
        };
        static DB2Meta instance(-1, 2, 0xDE6E2251, fields, -1);
        return &instance;
    }
};

struct ScheduledIntervalMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[5] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 5, 0x0C287F7A, fields, -1);
        return &instance;
    }
};

struct ScheduledWorldStateMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[8] =
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
        static DB2Meta instance(-1, 8, 0xDC45735A, fields, 0);
        return &instance;
    }
};

struct ScheduledWorldStateGroupMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[5] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 5, 0xCF71B287, fields, -1);
        return &instance;
    }
};

struct ScheduledWorldStateXUniqCatMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_INT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(0, 3, 0xF512C749, fields, 2);
        return &instance;
    }
};

struct ScreenEffectMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[12] =
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
        static DB2Meta instance(-1, 12, 0x7A371491, fields, -1);
        return &instance;
    }
};

struct ScreenLocationMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[1] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
        };
        static DB2Meta instance(-1, 1, 0xF6F6B04B, fields, -1);
        return &instance;
    }
};

struct SeamlessSiteMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[1] =
        {
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 1, 0x9E36592F, fields, 0);
        return &instance;
    }
};

struct ServerMessagesMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[1] =
        {
            { FT_STRING, 1, true },
        };
        static DB2Meta instance(-1, 1, 0xCC7971DF, fields, -1);
        return &instance;
    }
};

struct ShadowyEffectMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[13] =
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
        static DB2Meta instance(-1, 13, 0x7292BC4C, fields, -1);
        return &instance;
    }
};

struct SiegeablePropertiesMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_INT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, false },
        };
        static DB2Meta instance(-1, 4, 0x98E42A9F, fields, -1);
        return &instance;
    }
};

struct SkillLineMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[13] =
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
        static DB2Meta instance(5, 13, 0xEC83FE8A, fields, -1);
        return &instance;
    }
};

struct SkillLineAbilityMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[15] =
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
        };
        static DB2Meta instance(1, 15, 0xA38AD072, fields, 2);
        return &instance;
    }
};

struct SkillRaceClassInfoMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[7] =
        {
            { FT_LONG, 1, true },
            { FT_SHORT, 1, true },
            { FT_INT, 1, true },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, true },
            { FT_SHORT, 1, true },
        };
        static DB2Meta instance(-1, 7, 0x4CFD464E, fields, 1);
        return &instance;
    }
};

struct SoundAmbienceMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[6] =
        {
            { FT_BYTE, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 2, false },
            { FT_INT, 2, false },
            { FT_INT, 2, false },
        };
        static DB2Meta instance(-1, 6, 0x625245C7, fields, -1);
        return &instance;
    }
};

struct SoundAmbienceFlavorMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 3, 0x41E33D5D, fields, 2);
        return &instance;
    }
};

struct SoundBusMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[8] =
        {
            { FT_INT, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_FLOAT, 1, true },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, true },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(0, 8, 0x7CC84C2D, fields, 7);
        return &instance;
    }
};

struct SoundBusOverrideMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[7] =
        {
            { FT_INT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, false },
            { FT_BYTE, 1, false },
            { FT_FLOAT, 1, true },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(0, 7, 0xF321EA82, fields, 1);
        return &instance;
    }
};

struct SoundEmitterPillPointsMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_FLOAT, 3, true },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 2, 0xD63C5DE3, fields, 1);
        return &instance;
    }
};

struct SoundEmittersMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[12] =
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
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, true },
        };
        static DB2Meta instance(3, 12, 0x1FDCDD5A, fields, 11);
        return &instance;
    }
};

struct SoundEnvelopeMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[7] =
        {
            { FT_INT, 1, true },
            { FT_BYTE, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 7, 0xBD6F1248, fields, 0);
        return &instance;
    }
};

struct SoundFilterMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[1] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
        };
        static DB2Meta instance(-1, 1, 0xF6F6B04B, fields, -1);
        return &instance;
    }
};

struct SoundFilterElemMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_FLOAT, 9, true },
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, true },
        };
        static DB2Meta instance(-1, 3, 0x84F8D205, fields, 2);
        return &instance;
    }
};

struct SoundKitMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[16] =
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
        };
        static DB2Meta instance(0, 16, 0xAF055926, fields, -1);
        return &instance;
    }
};

struct SoundKitAdvancedMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[43] =
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
        static DB2Meta instance(0, 43, 0x6EAFA63E, fields, -1);
        return &instance;
    }
};

struct SoundKitChildMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_INT, 1, false },
            { FT_INT, 1, false },
        };
        static DB2Meta instance(-1, 2, 0x4215B0DD, fields, 1);
        return &instance;
    }
};

struct SoundKitEntryMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_INT, 1, false },
            { FT_INT, 1, true },
            { FT_BYTE, 1, false },
            { FT_FLOAT, 1, true },
        };
        static DB2Meta instance(-1, 4, 0xCBC66B5F, fields, 0);
        return &instance;
    }
};

struct SoundKitFallbackMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_INT, 1, false },
            { FT_INT, 1, false },
        };
        static DB2Meta instance(-1, 2, 0x53D01CD7, fields, -1);
        return &instance;
    }
};

struct SoundKitNameMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[1] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
        };
        static DB2Meta instance(-1, 1, 0xF6F6B04B, fields, -1);
        return &instance;
    }
};

struct SoundOverrideMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[5] =
        {
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 5, 0x4EC15243, fields, -1);
        return &instance;
    }
};

struct SoundProviderPreferencesMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[23] =
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
        static DB2Meta instance(-1, 23, 0xF0F42A22, fields, -1);
        return &instance;
    }
};

struct SourceInfoMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_STRING, 1, true },
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, true },
            { FT_INT, 1, false },
        };
        static DB2Meta instance(-1, 4, 0xA94C7962, fields, 3);
        return &instance;
    }
};

struct SpamMessagesMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[1] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
        };
        static DB2Meta instance(-1, 1, 0x1A080193, fields, -1);
        return &instance;
    }
};

struct SpecSetMemberMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 2, 0xC05B6C73, fields, 1);
        return &instance;
    }
};

struct SpecializationSpellsMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[6] =
        {
            { FT_STRING, 1, true },
            { FT_INT, 1, false },
            { FT_SHORT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(1, 6, 0x88A56A2F, fields, 2);
        return &instance;
    }
};

struct SpecializationSpellsDisplayMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_SHORT, 1, false },
            { FT_INT, 6, false },
        };
        static DB2Meta instance(-1, 2, 0xBD5EEC46, fields, 0);
        return &instance;
    }
};

struct SpellMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
        };
        static DB2Meta instance(-1, 3, 0xFFF1DA38, fields, -1);
        return &instance;
    }
};

struct SpellActionBarPrefMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_INT, 1, true },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 2, 0xCF471C9B, fields, -1);
        return &instance;
    }
};

struct SpellActivationOverlayMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[8] =
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
        static DB2Meta instance(-1, 8, 0xE72C81EF, fields, -1);
        return &instance;
    }
};

struct SpellAuraOptionsMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[8] =
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
        static DB2Meta instance(-1, 8, 0xCBDA0981, fields, 7);
        return &instance;
    }
};

struct SpellAuraRestrictionsMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[10] =
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
        static DB2Meta instance(-1, 10, 0xD7479271, fields, 9);
        return &instance;
    }
};

struct SpellAuraVisXChrSpecMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_SHORT, 1, true },
            { FT_SHORT, 1, true },
        };
        static DB2Meta instance(-1, 2, 0x8F54FD52, fields, 1);
        return &instance;
    }
};

struct SpellAuraVisibilityMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_INT, 1, false },
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(0, 4, 0xB7F28C20, fields, 3);
        return &instance;
    }
};

struct SpellCastTimesMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_INT, 1, true },
            { FT_SHORT, 1, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 3, 0xA66E197C, fields, -1);
        return &instance;
    }
};

struct SpellCastingRequirementsMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[7] =
        {
            { FT_INT, 1, true },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, true },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 7, 0xC6D7C649, fields, -1);
        return &instance;
    }
};

struct SpellCategoriesMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[9] =
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
        static DB2Meta instance(-1, 9, 0xEF1D2548, fields, 8);
        return &instance;
    }
};

struct SpellCategoryMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[6] =
        {
            { FT_STRING, 1, true },
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 6, 0x53EB1CD3, fields, -1);
        return &instance;
    }
};

struct SpellChainEffectsMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[60] =
        {
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_INT, 1, false },
            { FT_SHORT, 1, false },
            { FT_INT, 1, false },
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
        static DB2Meta instance(-1, 60, 0x461F9829, fields, -1);
        return &instance;
    }
};

struct SpellClassOptionsMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 4, true },
        };
        static DB2Meta instance(-1, 4, 0xB4E205E0, fields, -1);
        return &instance;
    }
};

struct SpellCooldownsMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[5] =
        {
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 5, 0x24886B08, fields, 4);
        return &instance;
    }
};

struct SpellDescriptionVariablesMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[1] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
        };
        static DB2Meta instance(-1, 1, 0x9C318DAF, fields, -1);
        return &instance;
    }
};

struct SpellDispelTypeMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_STRING, 1, true },
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 4, 0xAA83295A, fields, -1);
        return &instance;
    }
};

struct SpellDurationMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 3, 0x22236CBC, fields, -1);
        return &instance;
    }
};

struct SpellEffectMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[28] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, false },
            { FT_FLOAT, 1, true },
            { FT_INT, 1, true },
            { FT_SHORT, 1, true },
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
            { FT_INT, 2, true },
            { FT_INT, 2, false },
            { FT_INT, 4, true },
            { FT_SHORT, 2, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 28, 0x803150B7, fields, 27);
        return &instance;
    }
};

struct SpellEffectAutoDescriptionMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[9] =
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
        static DB2Meta instance(-1, 9, 0x7C523D94, fields, -1);
        return &instance;
    }
};

struct SpellEffectEmissionMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_SHORT, 1, true },
            { FT_BYTE, 1, true },
        };
        static DB2Meta instance(-1, 4, 0x66D096CB, fields, -1);
        return &instance;
    }
};

struct SpellEquippedItemsMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_INT, 1, true },
            { FT_BYTE, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 4, 0xA0588766, fields, -1);
        return &instance;
    }
};

struct SpellFlyoutMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[6] =
        {
            { FT_LONG, 1, true },
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 6, 0x1F516F53, fields, -1);
        return &instance;
    }
};

struct SpellFlyoutItemMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_INT, 1, true },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 3, 0x650A0B4D, fields, 2);
        return &instance;
    }
};

struct SpellFocusObjectMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[1] =
        {
            { FT_STRING, 1, true },
        };
        static DB2Meta instance(-1, 1, 0x9F2C8370, fields, -1);
        return &instance;
    }
};

struct SpellInterruptsMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[5] =
        {
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, true },
            { FT_INT, 2, true },
            { FT_INT, 2, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 5, 0xF551B940, fields, 4);
        return &instance;
    }
};

struct SpellItemEnchantmentMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[20] =
        {
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_INT, 3, false },
            { FT_FLOAT, 3, true },
            { FT_INT, 1, false },
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
        static DB2Meta instance(-1, 20, 0x96D1828E, fields, -1);
        return &instance;
    }
};

struct SpellItemEnchantmentConditionMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[6] =
        {
            { FT_BYTE, 5, false },
            { FT_INT, 5, false },
            { FT_BYTE, 5, false },
            { FT_BYTE, 5, false },
            { FT_BYTE, 5, false },
            { FT_BYTE, 5, false },
        };
        static DB2Meta instance(-1, 6, 0xFAA95A11, fields, -1);
        return &instance;
    }
};

struct SpellKeyboundOverrideMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_BYTE, 1, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 3, 0xFB8AD330, fields, -1);
        return &instance;
    }
};

struct SpellLabelMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_INT, 1, false },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 2, 0xCCA24F16, fields, 1);
        return &instance;
    }
};

struct SpellLearnSpellMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 3, 0xCC8637D2, fields, -1);
        return &instance;
    }
};

struct SpellLevelsMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[6] =
        {
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, true },
            { FT_SHORT, 1, true },
            { FT_SHORT, 1, true },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 6, 0xE3096221, fields, 5);
        return &instance;
    }
};

struct SpellMechanicMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[1] =
        {
            { FT_STRING, 1, true },
        };
        static DB2Meta instance(-1, 1, 0x24C6F0F3, fields, -1);
        return &instance;
    }
};

struct SpellMiscMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[12] =
        {
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
            { FT_INT, 14, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 12, 0x76E982BB, fields, 11);
        return &instance;
    }
};

struct SpellMissileMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[15] =
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
        static DB2Meta instance(-1, 15, 0xAF286A50, fields, -1);
        return &instance;
    }
};

struct SpellMissileMotionMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 4, 0xA61A5983, fields, -1);
        return &instance;
    }
};

struct SpellNameMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[1] =
        {
            { FT_STRING, 1, true },
        };
        static DB2Meta instance(-1, 1, 0x9F2C8370, fields, -1);
        return &instance;
    }
};

struct SpellPowerMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[14] =
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
        static DB2Meta instance(0, 14, 0x12ED7A99, fields, 13);
        return &instance;
    }
};

struct SpellPowerDifficultyMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_INT, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(0, 3, 0x08FEDBFF, fields, -1);
        return &instance;
    }
};

struct SpellProceduralEffectMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_INT, 1, false },
            { FT_BYTE, 1, true },
            { FT_FLOAT, 4, true },
        };
        static DB2Meta instance(0, 3, 0xF320E3AD, fields, -1);
        return &instance;
    }
};

struct SpellProcsPerMinuteMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_FLOAT, 1, true },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 2, 0xBEBE0C8B, fields, -1);
        return &instance;
    }
};

struct SpellProcsPerMinuteModMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 4, 0xE5827335, fields, 3);
        return &instance;
    }
};

struct SpellRadiusMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
        };
        static DB2Meta instance(-1, 4, 0xAE4257F8, fields, -1);
        return &instance;
    }
};

struct SpellRangeMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[5] =
        {
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_BYTE, 1, false },
            { FT_FLOAT, 2, true },
            { FT_FLOAT, 2, true },
        };
        static DB2Meta instance(-1, 5, 0x6B9E2FD2, fields, -1);
        return &instance;
    }
};

struct SpellReagentsMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_INT, 1, true },
            { FT_INT, 8, true },
            { FT_SHORT, 8, true },
        };
        static DB2Meta instance(-1, 3, 0x4B7DC644, fields, -1);
        return &instance;
    }
};

struct SpellReagentsCurrencyMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_INT, 1, true },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 3, 0x4D3F01C6, fields, 0);
        return &instance;
    }
};

struct SpellScalingMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[5] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_SHORT, 1, true },
        };
        static DB2Meta instance(-1, 5, 0x4B0C2E65, fields, -1);
        return &instance;
    }
};

struct SpellShapeshiftMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_INT, 1, true },
            { FT_BYTE, 1, true },
            { FT_INT, 2, true },
            { FT_INT, 2, true },
        };
        static DB2Meta instance(-1, 4, 0x91C4FFE9, fields, -1);
        return &instance;
    }
};

struct SpellShapeshiftFormMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[10] =
        {
            { FT_STRING, 1, true },
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
        static DB2Meta instance(-1, 10, 0x7082136E, fields, -1);
        return &instance;
    }
};

struct SpellSpecialUnitEffectMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_SHORT, 1, false },
            { FT_INT, 1, false },
        };
        static DB2Meta instance(-1, 2, 0xF084B84D, fields, -1);
        return &instance;
    }
};

struct SpellTargetRestrictionsMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[8] =
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
        static DB2Meta instance(-1, 8, 0x47BE0E0C, fields, 7);
        return &instance;
    }
};

struct SpellTotemsMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_INT, 1, true },
            { FT_SHORT, 2, false },
            { FT_INT, 2, true },
        };
        static DB2Meta instance(-1, 3, 0x5214FD94, fields, -1);
        return &instance;
    }
};

struct SpellVisualMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[15] =
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
        };
        static DB2Meta instance(-1, 15, 0x514F85ED, fields, -1);
        return &instance;
    }
};

struct SpellVisualAnimMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 3, 0xB27FB4A5, fields, -1);
        return &instance;
    }
};

struct SpellVisualColorEffectMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[11] =
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
        static DB2Meta instance(-1, 11, 0x773CE0DE, fields, -1);
        return &instance;
    }
};

struct SpellVisualEffectNameMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[14] =
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
        static DB2Meta instance(-1, 14, 0x10206967, fields, -1);
        return &instance;
    }
};

struct SpellVisualEventMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[9] =
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
        static DB2Meta instance(-1, 9, 0x8352EE58, fields, 8);
        return &instance;
    }
};

struct SpellVisualKitMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[5] =
        {
            { FT_INT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_INT, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 5, 0x3F538334, fields, -1);
        return &instance;
    }
};

struct SpellVisualKitAreaModelMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[6] =
        {
            { FT_INT, 1, true },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
        };
        static DB2Meta instance(-1, 6, 0x34C79353, fields, -1);
        return &instance;
    }
};

struct SpellVisualKitEffectMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 3, 0xF104E59F, fields, 2);
        return &instance;
    }
};

struct SpellVisualKitModelAttachMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[22] =
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
        static DB2Meta instance(2, 22, 0x75650E39, fields, 21);
        return &instance;
    }
};

struct SpellVisualMissileMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[16] =
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
        };
        static DB2Meta instance(2, 16, 0x0A0345EB, fields, 15);
        return &instance;
    }
};

struct SpellXDescriptionVariablesMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 2, 0xFBC7B7AE, fields, -1);
        return &instance;
    }
};

struct SpellXSpellVisualMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[13] =
        {
            { FT_INT, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, false },
            { FT_FLOAT, 1, true },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_SHORT, 1, false },
            { FT_INT, 1, false },
            { FT_SHORT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(0, 13, 0xCDAF2854, fields, 12);
        return &instance;
    }
};

struct StartupFilesMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 3, 0xF1381769, fields, -1);
        return &instance;
    }
};

struct Startup_StringsMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_STRING, 1, true },
        };
        static DB2Meta instance(-1, 2, 0x82058A06, fields, -1);
        return &instance;
    }
};

struct StationeryMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_INT, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 2, true },
        };
        static DB2Meta instance(-1, 3, 0x8B250029, fields, -1);
        return &instance;
    }
};

struct SummonPropertiesMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[5] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 5, 0x4134937A, fields, -1);
        return &instance;
    }
};

struct TactKeyMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[1] =
        {
            { FT_BYTE, 16, false },
        };
        static DB2Meta instance(-1, 1, 0xA55E1CCE, fields, -1);
        return &instance;
    }
};

struct TactKeyLookupMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[1] =
        {
            { FT_BYTE, 8, false },
        };
        static DB2Meta instance(-1, 1, 0x1A696886, fields, -1);
        return &instance;
    }
};

struct TalentMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[9] =
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
        static DB2Meta instance(-1, 9, 0x2661E6C2, fields, -1);
        return &instance;
    }
};

struct TaxiNodesMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[14] =
        {
            { FT_STRING, 1, true },
            { FT_FLOAT, 3, true },
            { FT_FLOAT, 2, true },
            { FT_FLOAT, 2, true },
            { FT_INT, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 2, true },
        };
        static DB2Meta instance(4, 14, 0x91ADBF11, fields, 5);
        return &instance;
    }
};

struct TaxiPathMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_INT, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_INT, 1, false },
        };
        static DB2Meta instance(0, 4, 0x3716BBCD, fields, 1);
        return &instance;
    }
};

struct TaxiPathNodeMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[9] =
        {
            { FT_FLOAT, 3, true },
            { FT_INT, 1, false },
            { FT_SHORT, 1, false },
            { FT_INT, 1, true },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(1, 9, 0xE28C3360, fields, 2);
        return &instance;
    }
};

struct TerrainMaterialMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 3, 0x9F25E6D3, fields, -1);
        return &instance;
    }
};

struct TerrainTypeMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[5] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 5, 0xB4573071, fields, -1);
        return &instance;
    }
};

struct TerrainTypeSoundsMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[1] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
        };
        static DB2Meta instance(-1, 1, 0xECCAE96B, fields, -1);
        return &instance;
    }
};

struct TextureBlendSetMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[10] =
        {
            { FT_INT, 3, true },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_FLOAT, 3, true },
            { FT_FLOAT, 3, true },
            { FT_FLOAT, 3, true },
            { FT_FLOAT, 3, true },
            { FT_FLOAT, 4, true },
        };
        static DB2Meta instance(-1, 10, 0xF2AFFE4C, fields, -1);
        return &instance;
    }
};

struct TextureFileDataMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_INT, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(0, 3, 0x71D3BD92, fields, 2);
        return &instance;
    }
};

struct TotemCategoryMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_STRING, 1, true },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 3, 0x2AA9FB1E, fields, -1);
        return &instance;
    }
};

struct ToyMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[5] =
        {
            { FT_STRING, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, true },
        };
        static DB2Meta instance(1, 5, 0x6156EBCA, fields, -1);
        return &instance;
    }
};

struct TradeSkillCategoryMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[7] =
        {
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_INT, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, true },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(2, 7, 0xAFEA1AAD, fields, -1);
        return &instance;
    }
};

struct TradeSkillItemMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, true },
        };
        static DB2Meta instance(-1, 2, 0xA90CD5D2, fields, -1);
        return &instance;
    }
};

struct TransformMatrixMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[5] =
        {
            { FT_FLOAT, 3, true },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
        };
        static DB2Meta instance(-1, 5, 0xBA00B2FD, fields, -1);
        return &instance;
    }
};

struct TransmogHolidayMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_INT, 1, false },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(0, 2, 0x6FC325A0, fields, -1);
        return &instance;
    }
};

struct TransmogSetMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[10] =
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
        static DB2Meta instance(1, 10, 0x3F0E4AEF, fields, 7);
        return &instance;
    }
};

struct TransmogSetGroupMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_STRING, 1, true },
            { FT_INT, 1, false },
        };
        static DB2Meta instance(1, 2, 0x0F60CFC9, fields, -1);
        return &instance;
    }
};

struct TransmogSetItemMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(0, 4, 0x23855A82, fields, 1);
        return &instance;
    }
};

struct TransportAnimationMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_FLOAT, 3, true },
            { FT_BYTE, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 4, 0x6329464B, fields, 3);
        return &instance;
    }
};

struct TransportPhysicsMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[10] =
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
        static DB2Meta instance(-1, 10, 0x0B297C98, fields, -1);
        return &instance;
    }
};

struct TransportRotationMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_FLOAT, 4, true },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 3, 0x5FE3BC91, fields, 2);
        return &instance;
    }
};

struct TrophyMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_STRING, 1, true },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
            { FT_INT, 1, false },
        };
        static DB2Meta instance(-1, 4, 0x0AE68C93, fields, -1);
        return &instance;
    }
};

struct UIExpansionDisplayInfoMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, false },
        };
        static DB2Meta instance(-1, 3, 0xCD407FA1, fields, -1);
        return &instance;
    }
};

struct UIExpansionDisplayInfoIconMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_STRING, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 3, 0xC9B51E5D, fields, -1);
        return &instance;
    }
};

struct UiCamFbackTransmogChrRaceMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[5] =
        {
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 5, 0xB1C9DAC4, fields, -1);
        return &instance;
    }
};

struct UiCamFbackTransmogWeaponMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 4, 0x5148437F, fields, -1);
        return &instance;
    }
};

struct UiCameraMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[9] =
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
        static DB2Meta instance(-1, 9, 0xC54B36EE, fields, -1);
        return &instance;
    }
};

struct UiCameraTypeMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
        };
        static DB2Meta instance(-1, 3, 0x34F64532, fields, -1);
        return &instance;
    }
};

struct UiCanvasMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_INT, 1, false },
            { FT_SHORT, 1, true },
            { FT_SHORT, 1, true },
        };
        static DB2Meta instance(0, 3, 0x77DC2C2A, fields, -1);
        return &instance;
    }
};

struct UiMapMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[13] =
        {
            { FT_STRING, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
            { FT_BYTE, 1, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(1, 13, 0x4B07CF16, fields, 2);
        return &instance;
    }
};

struct UiMapArtMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 3, 0xD85EF8B6, fields, -1);
        return &instance;
    }
};

struct UiMapArtStyleLayerMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[9] =
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
        static DB2Meta instance(-1, 9, 0xAFF6429A, fields, 8);
        return &instance;
    }
};

struct UiMapArtTileMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[5] =
        {
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 5, 0xBA5290E9, fields, 4);
        return &instance;
    }
};

struct UiMapAssignmentMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[10] =
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
        static DB2Meta instance(3, 10, 0xFA919770, fields, 4);
        return &instance;
    }
};

struct UiMapFogOfWarMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_INT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(0, 4, 0x257E044E, fields, 1);
        return &instance;
    }
};

struct UiMapFogOfWarVisualizationMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_FLOAT, 1, true },
        };
        static DB2Meta instance(-1, 3, 0xB8110379, fields, -1);
        return &instance;
    }
};

struct UiMapGroupMemberMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[5] =
        {
            { FT_STRING, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_BYTE, 1, true },
        };
        static DB2Meta instance(-1, 5, 0x3D1DDDA1, fields, 1);
        return &instance;
    }
};

struct UiMapLinkMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[6] =
        {
            { FT_FLOAT, 2, true },
            { FT_FLOAT, 2, true },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(2, 6, 0x1A2F1836, fields, 3);
        return &instance;
    }
};

struct UiMapXMapArtMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 3, 0xD74B6E49, fields, 2);
        return &instance;
    }
};

struct UiModelSceneMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 2, 0x0B9EFECA, fields, -1);
        return &instance;
    }
};

struct UiModelSceneActorMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[10] =
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
        static DB2Meta instance(2, 10, 0x8B5BF449, fields, 9);
        return &instance;
    }
};

struct UiModelSceneActorDisplayMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[7] =
        {
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
        };
        static DB2Meta instance(-1, 7, 0xDD1DD903, fields, -1);
        return &instance;
    }
};

struct UiModelSceneCameraMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[16] =
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
        static DB2Meta instance(3, 16, 0xEDFBD5A2, fields, 15);
        return &instance;
    }
};

struct UiPartyPoseMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[6] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 6, 0x880480BF, fields, 5);
        return &instance;
    }
};

struct UiTextureAtlasMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_INT, 1, true },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 4, 0x6951B2FD, fields, -1);
        return &instance;
    }
};

struct UiTextureAtlasElementMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_INT, 1, false },
        };
        static DB2Meta instance(1, 2, 0xBBDA0A61, fields, -1);
        return &instance;
    }
};

struct UiTextureAtlasMemberMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[10] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_INT, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, true },
            { FT_SHORT, 1, true },
            { FT_SHORT, 1, true },
            { FT_SHORT, 1, true },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(1, 10, 0x4D58B085, fields, 7);
        return &instance;
    }
};

struct UiTextureKitMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[1] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
        };
        static DB2Meta instance(-1, 1, 0x1FC1A9C6, fields, -1);
        return &instance;
    }
};

struct UiWidgetMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[6] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_SHORT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, false },
        };
        static DB2Meta instance(-1, 6, 0xC4C60F67, fields, -1);
        return &instance;
    }
};

struct UiWidgetConstantSourceMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_SHORT, 1, false },
            { FT_INT, 1, true },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 3, 0xFE573B5D, fields, 2);
        return &instance;
    }
};

struct UiWidgetDataSourceMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, true },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 4, 0x27BC34FD, fields, 3);
        return &instance;
    }
};

struct UiWidgetStringSourceMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_STRING, 1, true },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 3, 0x86CECC21, fields, 2);
        return &instance;
    }
};

struct UiWidgetVisualizationMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_BYTE, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_SHORT, 1, true },
        };
        static DB2Meta instance(-1, 4, 0x1DB32AF9, fields, -1);
        return &instance;
    }
};

struct UnitBloodMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[6] =
        {
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
        };
        static DB2Meta instance(-1, 6, 0x007ED968, fields, -1);
        return &instance;
    }
};

struct UnitBloodLevelsMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[1] =
        {
            { FT_BYTE, 3, false },
        };
        static DB2Meta instance(-1, 1, 0x684D24F4, fields, -1);
        return &instance;
    }
};

struct UnitConditionMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_BYTE, 1, false },
            { FT_BYTE, 8, false },
            { FT_BYTE, 8, true },
            { FT_INT, 8, true },
        };
        static DB2Meta instance(-1, 4, 0x215CBCD2, fields, -1);
        return &instance;
    }
};

struct UnitPowerBarMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[16] =
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
        static DB2Meta instance(-1, 16, 0x2640852D, fields, -1);
        return &instance;
    }
};

struct VehicleMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[18] =
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
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
            { FT_INT, 1, true },
            { FT_SHORT, 8, false },
            { FT_SHORT, 3, false },
        };
        static DB2Meta instance(-1, 18, 0x221A0252, fields, -1);
        return &instance;
    }
};

struct VehicleSeatMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[61] =
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
        static DB2Meta instance(-1, 61, 0x7AB200FA, fields, -1);
        return &instance;
    }
};

struct VehicleUIIndSeatMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_BYTE, 1, false },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 4, 0x590E3162, fields, 3);
        return &instance;
    }
};

struct VehicleUIIndicatorMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[1] =
        {
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 1, 0x4B1AACBC, fields, -1);
        return &instance;
    }
};

struct VignetteMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[9] =
        {
            { FT_STRING, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_BYTE, 1, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 9, 0xE70E083E, fields, -1);
        return &instance;
    }
};

struct VirtualAttachmentMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_SHORT, 1, true },
        };
        static DB2Meta instance(-1, 2, 0xA9D90777, fields, -1);
        return &instance;
    }
};

struct VirtualAttachmentCustomizationMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_SHORT, 1, true },
            { FT_INT, 1, true },
            { FT_SHORT, 1, true },
        };
        static DB2Meta instance(-1, 3, 0x5812DF35, fields, -1);
        return &instance;
    }
};

struct VocalUISoundsMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 2, false },
        };
        static DB2Meta instance(-1, 4, 0x264C4E59, fields, -1);
        return &instance;
    }
};

struct WMOAreaTableMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[15] =
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
        static DB2Meta instance(1, 15, 0x60EC930B, fields, 2);
        return &instance;
    }
};

struct WMOMinimapTextureMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[5] =
        {
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
            { FT_SHORT, 1, true },
        };
        static DB2Meta instance(-1, 5, 0x48CE176C, fields, 4);
        return &instance;
    }
};

struct WbAccessControlListMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[5] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 5, 0xDC9D8334, fields, -1);
        return &instance;
    }
};

struct WbCertWhitelistMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 4, 0x1524F278, fields, -1);
        return &instance;
    }
};

struct WeaponImpactSoundsMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[7] =
        {
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 11, false },
            { FT_INT, 11, false },
            { FT_INT, 11, false },
            { FT_INT, 11, false },
        };
        static DB2Meta instance(-1, 7, 0x9C7F9BA6, fields, -1);
        return &instance;
    }
};

struct WeaponSwingSounds2Meta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, false },
        };
        static DB2Meta instance(-1, 3, 0x18B6CC57, fields, -1);
        return &instance;
    }
};

struct WeaponTrailMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[9] =
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
        static DB2Meta instance(-1, 9, 0xB05F809A, fields, -1);
        return &instance;
    }
};

struct WeaponTrailModelDefMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_INT, 1, true },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 3, 0xCE7AD194, fields, 2);
        return &instance;
    }
};

struct WeaponTrailParamMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[10] =
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
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 10, 0xC3B87CA4, fields, 9);
        return &instance;
    }
};

struct WeatherMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[22] =
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
        static DB2Meta instance(-1, 22, 0x784E91E0, fields, -1);
        return &instance;
    }
};

struct WeatherXParticulateMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 2, 0x791A7865, fields, 1);
        return &instance;
    }
};

struct WindSettingsMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[10] =
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
        static DB2Meta instance(-1, 10, 0xE09E01C4, fields, -1);
        return &instance;
    }
};

struct WorldBossLockoutMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[2] =
        {
            { FT_STRING, 1, true },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 2, 0x57E8ADB8, fields, -1);
        return &instance;
    }
};

struct WorldChunkSoundsMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[6] =
        {
            { FT_SHORT, 1, false },
            { FT_INT, 1, true },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 6, 0xA5616A27, fields, -1);
        return &instance;
    }
};

struct WorldEffectMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[6] =
        {
            { FT_INT, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, false },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 6, 0xBCB8719B, fields, -1);
        return &instance;
    }
};

struct WorldElapsedTimerMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_STRING, 1, true },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 3, 0x103B8712, fields, -1);
        return &instance;
    }
};

struct WorldMapOverlayMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[13] =
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
        static DB2Meta instance(0, 13, 0x837A3DAA, fields, 1);
        return &instance;
    }
};

struct WorldMapOverlayTileMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[5] =
        {
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 5, 0xC4DCC916, fields, 4);
        return &instance;
    }
};

struct WorldSafeLocsMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_STRING, 1, false },
            { FT_FLOAT, 3, false },
            { FT_SHORT, 1, false },
            { FT_FLOAT, 1, false }
        };
        static DB2Meta instance(-1, 4, 0x6BF0D7EC, fields, 3);
        return &instance;
    }
};

struct WorldStateExpressionMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[1] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
        };
        static DB2Meta instance(-1, 1, 0xF23806A6, fields, -1);
        return &instance;
    }
};

struct WorldStateUIMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[17] =
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
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 3, false },
        };
        static DB2Meta instance(5, 17, 0xE1F042FE, fields, 6);
        return &instance;
    }
};

struct WorldStateZoneSoundsMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[8] =
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
        static DB2Meta instance(-1, 8, 0x44CFA417, fields, -1);
        return &instance;
    }
};

struct World_PVP_AreaMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[7] =
        {
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, true },
        };
        static DB2Meta instance(-1, 7, 0x3F8DDC83, fields, -1);
        return &instance;
    }
};

struct ZoneIntroMusicTableMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_INT, 1, false },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 4, 0x5453B51D, fields, -1);
        return &instance;
    }
};

struct ZoneLightMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
        };
        static DB2Meta instance(-1, 4, 0xD553DE84, fields, -1);
        return &instance;
    }
};

struct ZoneLightPointMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[3] =
        {
            { FT_FLOAT, 2, true },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
        };
        static DB2Meta instance(-1, 3, 0xB21DA554, fields, 2);
        return &instance;
    }
};

struct ZoneMusicMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_INT, 2, false },
            { FT_INT, 2, false },
            { FT_INT, 2, false },
        };
        static DB2Meta instance(-1, 4, 0x9EBD4495, fields, -1);
        return &instance;
    }
};

struct ZoneStoryMeta
{
    static DB2Meta const* Instance()
    {
        static DB2MetaField const fields[4] =
        {
            { FT_BYTE, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
        };
        static DB2Meta instance(-1, 4, 0x5BFB82E8, fields, 3);
        return &instance;
    }
};

#endif // DB2Metadata_h__
