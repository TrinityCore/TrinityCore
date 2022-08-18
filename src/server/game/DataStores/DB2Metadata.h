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
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[17] =
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
        static constexpr DB2Meta instance(1260179, 3, 17, 17, 0x6F3CA62E, fields, 11);
        return &instance;
    }
};

struct Achievement_CategoryMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_STRING, 1, true },
            { FT_INT, 1, false },
            { FT_SHORT, 1, true },
            { FT_BYTE, 1, true },
        };
        static constexpr DB2Meta instance(1324299, 1, 4, 4, 0xC3562871, fields, 3);
        return &instance;
    }
};

struct AdventureJournalMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[22] =
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
        static constexpr DB2Meta instance(1115949, -1, 22, 22, 0xC165B3AF, fields, -1);
        return &instance;
    }
};

struct AdventureMapPOIMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[12] =
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
        static constexpr DB2Meta instance(1267070, -1, 12, 12, 0x347D1163, fields, -1);
        return &instance;
    }
};

struct AlliedRaceMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[8] =
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
        static constexpr DB2Meta instance(1710672, -1, 8, 8, 0xA21C7C29, fields, -1);
        return &instance;
    }
};

struct AnimKitMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_INT, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
        };
        static constexpr DB2Meta instance(1304323, -1, 3, 3, 0x6287EB21, fields, -1);
        return &instance;
    }
};

struct AnimKitBoneSetMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[5] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_INT, 1, true },
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1375433, -1, 5, 5, 0x570E50A4, fields, -1);
        return &instance;
    }
};

struct AnimKitBoneSetAliasMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
        };
        static constexpr DB2Meta instance(1266937, -1, 2, 2, 0x8DA67A60, fields, -1);
        return &instance;
    }
};

struct AnimKitConfigMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[1] =
        {
            { FT_INT, 1, false },
        };
        static constexpr DB2Meta instance(1300872, -1, 1, 1, 0xA3858D19, fields, -1);
        return &instance;
    }
};

struct AnimKitConfigBoneSetMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1300873, -1, 3, 2, 0x2D94E68E, fields, 2);
        return &instance;
    }
};

struct AnimKitPriorityMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[1] =
        {
            { FT_BYTE, 1, false },
        };
        static constexpr DB2Meta instance(1266540, -1, 1, 1, 0x9CF0DCAA, fields, -1);
        return &instance;
    }
};

struct AnimKitReplacementMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[5] =
        {
            { FT_INT, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1559807, 0, 5, 4, 0xCC7EFF2A, fields, 4);
        return &instance;
    }
};

struct AnimKitSegmentMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[19] =
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
            { FT_FLOAT, 1, true },
        };
        static constexpr DB2Meta instance(1304324, -1, 19, 19, 0xDCD09D5C, fields, 0);
        return &instance;
    }
};

struct AnimReplacementMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[5] =
        {
            { FT_INT, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1301100, 0, 5, 4, 0x1A7DFDFA, fields, 4);
        return &instance;
    }
};

struct AnimReplacementSetMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[1] =
        {
            { FT_BYTE, 1, false },
        };
        static constexpr DB2Meta instance(1284817, -1, 1, 1, 0x54CC07B7, fields, -1);
        return &instance;
    }
};

struct AnimaCableMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[35] =
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
        static constexpr DB2Meta instance(3286805, -1, 35, 35, 0x1F19EFC8, fields, -1);
        return &instance;
    }
};

struct AnimaCylinderMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[7] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3286804, -1, 7, 7, 0xA8314AE6, fields, -1);
        return &instance;
    }
};

struct AnimaMaterialMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[31] =
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
        static constexpr DB2Meta instance(3153990, -1, 31, 31, 0xEA8F56B4, fields, -1);
        return &instance;
    }
};

struct AnimationDataMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 2, true },
        };
        static constexpr DB2Meta instance(1375431, -1, 4, 4, 0xE4D647E7, fields, -1);
        return &instance;
    }
};

struct AreaConditionalDataMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[5] =
        {
            { FT_STRING, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(2123730, 1, 5, 4, 0xE7DA5527, fields, 4);
        return &instance;
    }
};

struct AreaFarClipOverrideMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_INT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1537162, -1, 4, 4, 0xA9F91574, fields, -1);
        return &instance;
    }
};

struct AreaGroupMemberMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_SHORT, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1093406, -1, 2, 1, 0x93C93492, fields, 1);
        return &instance;
    }
};

struct AreaPOIMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[20] =
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
            { FT_INT, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, true },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
        };
        static constexpr DB2Meta instance(1000630, 2, 20, 20, 0xF44FDD3B, fields, 12);
        return &instance;
    }
};

struct AreaPOIStateMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[5] =
        {
            { FT_STRING, 1, true },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1000631, -1, 5, 4, 0xC236B11E, fields, 4);
        return &instance;
    }
};

struct AreaTableMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[23] =
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
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, true },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 2, true },
            { FT_SHORT, 4, false },
        };
        static constexpr DB2Meta instance(1353545, -1, 23, 23, 0x16AE706B, fields, -1);
        return &instance;
    }
};

struct AreaTriggerMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[15] =
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
        static constexpr DB2Meta instance(1354401, 1, 15, 15, 0x5444D57A, fields, 2);
        return &instance;
    }
};

struct AreaTriggerActionSetMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[1] =
        {
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1352378, -1, 1, 1, 0x3CC972C6, fields, -1);
        return &instance;
    }
};

struct AreaTriggerBoxMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[1] =
        {
            { FT_FLOAT, 3, true },
        };
        static constexpr DB2Meta instance(1332554, -1, 1, 1, 0x0D4BC031, fields, -1);
        return &instance;
    }
};

struct AreaTriggerCreatePropertiesMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_BYTE, 1, true },
            { FT_SHORT, 1, true },
        };
        static constexpr DB2Meta instance(1937227, -1, 2, 2, 0x0345EC9C, fields, -1);
        return &instance;
    }
};

struct AreaTriggerCylinderMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
        };
        static constexpr DB2Meta instance(1121943, -1, 3, 3, 0xAF2720AC, fields, -1);
        return &instance;
    }
};

struct AreaTriggerDiskMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
        };
        static constexpr DB2Meta instance(4223661, -1, 4, 4, 0x5C424FAE, fields, -1);
        return &instance;
    }
};

struct AreaTriggerSphereMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[1] =
        {
            { FT_FLOAT, 1, true },
        };
        static constexpr DB2Meta instance(1315630, -1, 1, 1, 0xAE82194A, fields, -1);
        return &instance;
    }
};

struct ArenaCcItemMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3849793, -1, 2, 1, 0x440B809B, fields, 1);
        return &instance;
    }
};

struct ArmorLocationMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[5] =
        {
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
        };
        static constexpr DB2Meta instance(1284818, -1, 5, 5, 0x6FA608FB, fields, -1);
        return &instance;
    }
};

struct ArtifactMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[11] =
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
        static constexpr DB2Meta instance(1007934, 1, 11, 11, 0x7F55AC46, fields, -1);
        return &instance;
    }
};

struct ArtifactAppearanceMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[16] =
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
        static constexpr DB2Meta instance(1116407, 1, 16, 16, 0x5D77042E, fields, 2);
        return &instance;
    }
};

struct ArtifactAppearanceSetMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[9] =
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
        static constexpr DB2Meta instance(1116408, 2, 9, 8, 0xE8D3AE79, fields, 8);
        return &instance;
    }
};

struct ArtifactCategoryMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_SHORT, 1, true },
            { FT_SHORT, 1, true },
        };
        static constexpr DB2Meta instance(1376210, -1, 2, 2, 0xAA92CE1F, fields, -1);
        return &instance;
    }
};

struct ArtifactItemToTransmogMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(2029780, -1, 3, 3, 0xEB962C15, fields, 0);
        return &instance;
    }
};

struct ArtifactPowerMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[7] =
        {
            { FT_FLOAT, 2, true },
            { FT_INT, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
        };
        static constexpr DB2Meta instance(1007937, 1, 7, 7, 0x421879C5, fields, 2);
        return &instance;
    }
};

struct ArtifactPowerLinkMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
        };
        static constexpr DB2Meta instance(1133731, -1, 2, 2, 0xD2E6E484, fields, -1);
        return &instance;
    }
};

struct ArtifactPowerPickerMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[1] =
        {
            { FT_INT, 1, false },
        };
        static constexpr DB2Meta instance(1597467, -1, 1, 1, 0xAA18FF1B, fields, -1);
        return &instance;
    }
};

struct ArtifactPowerRankMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[5] =
        {
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
            { FT_SHORT, 1, false },
            { FT_FLOAT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1261405, -1, 5, 4, 0xD1061B77, fields, 4);
        return &instance;
    }
};

struct ArtifactQuestXPMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[1] =
        {
            { FT_INT, 10, false },
        };
        static constexpr DB2Meta instance(1036203, -1, 1, 1, 0xBFB6413C, fields, -1);
        return &instance;
    }
};

struct ArtifactTierMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[5] =
        {
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
        };
        static constexpr DB2Meta instance(1600114, -1, 5, 5, 0x91AD7570, fields, -1);
        return &instance;
    }
};

struct ArtifactUnlockMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[5] =
        {
            { FT_INT, 1, false },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1094540, -1, 5, 4, 0xAED3BBEA, fields, 4);
        return &instance;
    }
};

struct AuctionHouseMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_STRING, 1, true },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
        };
        static constexpr DB2Meta instance(1237439, -1, 4, 4, 0x8925F061, fields, -1);
        return &instance;
    }
};

struct AuctionHouseCategoryMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[9] =
        {
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_BYTE, 1, true },
            { FT_INT, 1, true },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(4366440, 2, 9, 8, 0xA528FA70, fields, 8);
        return &instance;
    }
};

struct AzeriteEmpoweredItemMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
        };
        static constexpr DB2Meta instance(1846046, -1, 3, 3, 0xA33729C4, fields, -1);
        return &instance;
    }
};

struct AzeriteEssenceMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(2829665, -1, 3, 3, 0x78739DBC, fields, -1);
        return &instance;
    }
};

struct AzeriteEssencePowerMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[8] =
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
        static constexpr DB2Meta instance(2829666, -1, 8, 8, 0x054DFF02, fields, -1);
        return &instance;
    }
};

struct AzeriteItemMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[1] =
        {
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1846048, -1, 1, 1, 0x358673DD, fields, -1);
        return &instance;
    }
};

struct AzeriteItemMilestonePowerMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1915395, -1, 4, 4, 0x82DD9DC4, fields, -1);
        return &instance;
    }
};

struct AzeriteKnowledgeMultiplierMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[1] =
        {
            { FT_FLOAT, 1, true },
        };
        static constexpr DB2Meta instance(3148050, -1, 1, 1, 0x9DCCF58B, fields, -1);
        return &instance;
    }
};

struct AzeriteLevelInfoMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_LONG, 1, false },
            { FT_LONG, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3147968, -1, 3, 3, 0xFB87ABE1, fields, -1);
        return &instance;
    }
};

struct AzeritePowerMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1846044, -1, 4, 4, 0x20D09908, fields, -1);
        return &instance;
    }
};

struct AzeritePowerSetMemberMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[5] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1846040, -1, 5, 5, 0xDD075CEB, fields, 0);
        return &instance;
    }
};

struct AzeriteTierUnlockMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1846043, -1, 4, 3, 0x63D128C5, fields, 3);
        return &instance;
    }
};

struct AzeriteTierUnlockSetMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[1] =
        {
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(2446322, -1, 1, 1, 0x0E377BCA, fields, -1);
        return &instance;
    }
};

struct AzeriteUnlockMappingMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[5] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(2564314, -1, 5, 4, 0x22A21AA1, fields, 4);
        return &instance;
    }
};

struct BankBagSlotPricesMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[1] =
        {
            { FT_INT, 1, false },
        };
        static constexpr DB2Meta instance(1284819, -1, 1, 1, 0x972171FF, fields, -1);
        return &instance;
    }
};

struct BannedAddonsMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_BYTE, 1, false },
        };
        static constexpr DB2Meta instance(1373459, -1, 3, 3, 0x3BE3470D, fields, -1);
        return &instance;
    }
};

struct BarberShopStyleMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[7] =
        {
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_BYTE, 1, false },
            { FT_FLOAT, 1, true },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
        };
        static constexpr DB2Meta instance(1237437, -1, 7, 7, 0xD7B2816B, fields, -1);
        return &instance;
    }
};

struct BarrageEffectMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[12] =
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
        static constexpr DB2Meta instance(2499852, -1, 12, 12, 0x26B3A638, fields, -1);
        return &instance;
    }
};

struct BattlePetAbilityMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[7] =
        {
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_INT, 1, true },
            { FT_BYTE, 1, true },
            { FT_INT, 1, false },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
        };
        static constexpr DB2Meta instance(841610, -1, 7, 7, 0xA35F647F, fields, -1);
        return &instance;
    }
};

struct BattlePetAbilityEffectMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[7] =
        {
            { FT_INT, 1, false },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 6, true },
        };
        static constexpr DB2Meta instance(801575, 0, 7, 7, 0x6E6DF628, fields, 1);
        return &instance;
    }
};

struct BattlePetAbilityStateMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_INT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(801576, -1, 3, 2, 0xAAB55D53, fields, 2);
        return &instance;
    }
};

struct BattlePetAbilityTurnMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[6] =
        {
            { FT_INT, 1, false },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, true },
            { FT_SHORT, 1, false },
        };
        static constexpr DB2Meta instance(801577, 0, 6, 6, 0x4BFF1620, fields, 1);
        return &instance;
    }
};

struct BattlePetBreedQualityMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_FLOAT, 1, true },
            { FT_BYTE, 1, false },
        };
        static constexpr DB2Meta instance(801578, -1, 2, 2, 0x2D17B177, fields, -1);
        return &instance;
    }
};

struct BattlePetBreedStateMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_INT, 1, true },
            { FT_SHORT, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(801579, -1, 3, 2, 0xF449E0D3, fields, 2);
        return &instance;
    }
};

struct BattlePetDisplayOverrideMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1802988, -1, 4, 3, 0x9FADCDB4, fields, 3);
        return &instance;
    }
};

struct BattlePetEffectPropertiesMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_STRING_NOT_LOCALIZED, 6, true },
            { FT_SHORT, 1, false },
            { FT_BYTE, 6, false },
        };
        static constexpr DB2Meta instance(801580, -1, 3, 3, 0x830F4FD2, fields, -1);
        return &instance;
    }
};

struct BattlePetNPCTeamMemberMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[1] =
        {
            { FT_STRING, 1, true },
        };
        static constexpr DB2Meta instance(841648, -1, 1, 1, 0xB0DD8F60, fields, -1);
        return &instance;
    }
};

struct BattlePetSpeciesMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[12] =
        {
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_BYTE, 1, true },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(841622, 2, 12, 12, 0x48CF80A3, fields, -1);
        return &instance;
    }
};

struct BattlePetSpeciesStateMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_SHORT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(801581, -1, 3, 2, 0x3D1D7C9D, fields, 2);
        return &instance;
    }
};

struct BattlePetSpeciesXAbilityMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(801582, -1, 4, 3, 0x98E73E87, fields, 3);
        return &instance;
    }
};

struct BattlePetSpeciesXCovenantMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_SHORT, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3669304, -1, 2, 1, 0xD9C25504, fields, 1);
        return &instance;
    }
};

struct BattlePetStateMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_INT, 1, true },
            { FT_SHORT, 1, false },
        };
        static constexpr DB2Meta instance(801583, -1, 3, 3, 0x59238591, fields, -1);
        return &instance;
    }
};

struct BattlePetVisualMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[7] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_INT, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
        };
        static constexpr DB2Meta instance(801584, -1, 7, 7, 0x55227F53, fields, -1);
        return &instance;
    }
};

struct BattlemasterListMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[17] =
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
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_SHORT, 16, true },
        };
        static constexpr DB2Meta instance(1360265, -1, 17, 17, 0xE162FCC0, fields, -1);
        return &instance;
    }
};

struct BeamEffectMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[10] =
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
        static constexpr DB2Meta instance(1525607, -1, 10, 10, 0xF1E61217, fields, -1);
        return &instance;
    }
};

struct BoneWindModifierModelMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1467254, -1, 2, 2, 0x1487387B, fields, 0);
        return &instance;
    }
};

struct BoneWindModifiersMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_FLOAT, 3, true },
            { FT_FLOAT, 1, true },
        };
        static constexpr DB2Meta instance(1416756, -1, 2, 2, 0x9FEA042E, fields, -1);
        return &instance;
    }
};

struct BonusRollMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
        };
        static constexpr DB2Meta instance(1983274, -1, 4, 4, 0xDEC02884, fields, -1);
        return &instance;
    }
};

struct BountyMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[5] =
        {
            { FT_INT, 1, true },
            { FT_SHORT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1367866, -1, 5, 4, 0xD23ECB64, fields, 4);
        return &instance;
    }
};

struct BountySetMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_INT, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1367865, -1, 2, 2, 0x501CD5A6, fields, -1);
        return &instance;
    }
};

struct BroadcastTextMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[12] =
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
        static constexpr DB2Meta instance(841604, 2, 12, 12, 0x9FB1FE4B, fields, -1);
        return &instance;
    }
};

struct BroadcastTextDurationMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(2166900, -1, 3, 3, 0xFFDF8DBB, fields, 0);
        return &instance;
    }
};

struct CameraEffectMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[1] =
        {
            { FT_BYTE, 1, false },
        };
        static constexpr DB2Meta instance(1117695, -1, 1, 1, 0x8E37DA6F, fields, -1);
        return &instance;
    }
};

struct CameraEffectEntryMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[16] =
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
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1117696, -1, 16, 15, 0x9F59F6DD, fields, 15);
        return &instance;
    }
};

struct CameraModeMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[11] =
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
        static constexpr DB2Meta instance(1343308, -1, 11, 11, 0xC26A74A9, fields, -1);
        return &instance;
    }
};

struct CampaignMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[12] =
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
            { FT_INT, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(2031607, -1, 12, 12, 0x345FBC23, fields, -1);
        return &instance;
    }
};

struct CampaignXConditionMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[5] =
        {
            { FT_STRING, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(2031611, -1, 5, 4, 0x3B0D3F8C, fields, 4);
        return &instance;
    }
};

struct CampaignXQuestLineMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
        };
        static constexpr DB2Meta instance(2036722, -1, 3, 3, 0x10BF2FCD, fields, 0);
        return &instance;
    }
};

struct CastableRaidBuffsMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_INT, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1283018, -1, 2, 1, 0xBEB03EF2, fields, 1);
        return &instance;
    }
};

struct CelestialBodyMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[14] =
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
        static constexpr DB2Meta instance(1592470, -1, 14, 14, 0x3F9BA1DD, fields, -1);
        return &instance;
    }
};

struct Cfg_CategoriesMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[6] =
        {
            { FT_STRING, 1, true },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, true },
        };
        static constexpr DB2Meta instance(1068162, -1, 6, 6, 0x37159FFC, fields, -1);
        return &instance;
    }
};

struct Cfg_ConfigsMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
            { FT_FLOAT, 1, true },
        };
        static constexpr DB2Meta instance(1080949, -1, 4, 4, 0xF7B1322B, fields, -1);
        return &instance;
    }
};

struct Cfg_RegionsMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[5] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_SHORT, 1, false },
            { FT_INT, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, false },
        };
        static constexpr DB2Meta instance(1082876, -1, 5, 5, 0xFC93C56C, fields, -1);
        return &instance;
    }
};

struct ChallengeModeItemBonusOverrideMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[6] =
        {
            { FT_INT, 1, true },
            { FT_BYTE, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(2965645, -1, 6, 5, 0x54B1B4A1, fields, 5);
        return &instance;
    }
};

struct CharBaseInfoMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, true },
        };
        static constexpr DB2Meta instance(1343386, -1, 2, 2, 0xFE79090E, fields, -1);
        return &instance;
    }
};

struct CharBaseSectionMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
        };
        static constexpr DB2Meta instance(1375798, -1, 3, 3, 0xC0783DC4, fields, -1);
        return &instance;
    }
};

struct CharComponentTextureLayoutsMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_SHORT, 1, true },
            { FT_SHORT, 1, true },
        };
        static constexpr DB2Meta instance(1360262, -1, 2, 2, 0xB4407510, fields, -1);
        return &instance;
    }
};

struct CharComponentTextureSectionsMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[7] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1360263, -1, 7, 7, 0x5F538036, fields, 0);
        return &instance;
    }
};

struct CharHairGeosetsMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[11] =
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
        static constexpr DB2Meta instance(1256914, -1, 11, 11, 0x69E34903, fields, 0);
        return &instance;
    }
};

struct CharSectionConditionMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[6] =
        {
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(2388725, -1, 6, 5, 0x5E6E8D02, fields, 5);
        return &instance;
    }
};

struct CharShipmentMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[9] =
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
        static constexpr DB2Meta instance(972425, -1, 9, 9, 0x604F76F0, fields, 0);
        return &instance;
    }
};

struct CharShipmentContainerMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[16] =
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
        static constexpr DB2Meta instance(972405, -1, 16, 16, 0xBE1415EF, fields, -1);
        return &instance;
    }
};

struct CharStartKitMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[16] =
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
        static constexpr DB2Meta instance(3055696, -1, 16, 15, 0x00B44453, fields, 15);
        return &instance;
    }
};

struct CharTitlesMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_SHORT, 1, true },
            { FT_BYTE, 1, true },
        };
        static constexpr DB2Meta instance(1349054, -1, 4, 4, 0xD7398A05, fields, -1);
        return &instance;
    }
};

struct CharacterFacialHairStylesMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_INT, 5, true },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
        };
        static constexpr DB2Meta instance(1369752, -1, 4, 4, 0x4ED873D6, fields, -1);
        return &instance;
    }
};

struct CharacterLoadoutMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_LONG, 1, true },
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, true },
        };
        static constexpr DB2Meta instance(1344281, -1, 4, 4, 0x8B9E97B1, fields, -1);
        return &instance;
    }
};

struct CharacterLoadoutItemMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_SHORT, 1, false },
            { FT_INT, 1, false },
        };
        static constexpr DB2Meta instance(1302846, -1, 2, 2, 0x24843CD8, fields, 0);
        return &instance;
    }
};

struct CharacterLoadoutPetMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3724843, -1, 4, 3, 0x0E32BEB6, fields, 3);
        return &instance;
    }
};

struct CharacterServiceInfoMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[12] =
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
        static constexpr DB2Meta instance(1815417, -1, 12, 12, 0x7C1EF738, fields, -1);
        return &instance;
    }
};

struct ChatChannelsMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[5] =
        {
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_INT, 1, true },
            { FT_BYTE, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1345278, -1, 5, 5, 0x34EBC257, fields, -1);
        return &instance;
    }
};

struct ChatProfanityMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_BYTE, 1, true },
        };
        static constexpr DB2Meta instance(1117084, -1, 2, 2, 0xF05E7E22, fields, -1);
        return &instance;
    }
};

struct ChrClassRaceSexMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[6] =
        {
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
        };
        static constexpr DB2Meta instance(1306188, -1, 6, 6, 0xCE5A498A, fields, -1);
        return &instance;
    }
};

struct ChrClassTitleMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_BYTE, 1, false },
        };
        static constexpr DB2Meta instance(1267497, -1, 3, 3, 0x7F14E4E9, fields, -1);
        return &instance;
    }
};

struct ChrClassUIChrModelInfoMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_FLOAT, 3, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_FLOAT, 1, true },
        };
        static constexpr DB2Meta instance(3754770, -1, 4, 4, 0xC4043CA4, fields, -1);
        return &instance;
    }
};

struct ChrClassUIDisplayMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_BYTE, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
        };
        static constexpr DB2Meta instance(1316515, -1, 3, 3, 0x89E07C1C, fields, -1);
        return &instance;
    }
};

struct ChrClassVillainMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_STRING, 1, true },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, true },
        };
        static constexpr DB2Meta instance(1267498, -1, 3, 3, 0x24AF0FFD, fields, -1);
        return &instance;
    }
};

struct ChrClassesMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[39] =
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
        };
        static constexpr DB2Meta instance(1361031, 10, 39, 39, 0xCD8CBEDA, fields, -1);
        return &instance;
    }
};

struct ChrClassesXPowerTypesMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_BYTE, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1121420, -1, 2, 1, 0x71C99BFD, fields, 1);
        return &instance;
    }
};

struct ChrCreateClassAnimTargetMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[7] =
        {
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3671168, -1, 7, 6, 0x3AC1561C, fields, 6);
        return &instance;
    }
};

struct ChrCreateClassAnimTargetInfoMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_INT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3671169, 0, 4, 3, 0x7DF65661, fields, 3);
        return &instance;
    }
};

struct ChrCustClientChoiceConversionMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3590348, -1, 3, 2, 0xF1AE177C, fields, 2);
        return &instance;
    }
};

struct ChrCustItemGeoModifyMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3952714, -1, 3, 3, 0x09A78C46, fields, -1);
        return &instance;
    }
};

struct ChrCustomizationMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[7] =
        {
            { FT_STRING, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 3, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1611874, -1, 7, 6, 0x3E81F9D4, fields, 6);
        return &instance;
    }
};

struct ChrCustomizationBoneSetMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3460181, -1, 2, 2, 0xF45B8890, fields, -1);
        return &instance;
    }
};

struct ChrCustomizationCategoryMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[8] =
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
        static constexpr DB2Meta instance(3526439, -1, 8, 8, 0x885434EF, fields, -1);
        return &instance;
    }
};

struct ChrCustomizationChoiceMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[9] =
        {
            { FT_STRING, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 2, true },
        };
        static constexpr DB2Meta instance(3450554, 1, 9, 9, 0xAA51F086, fields, 2);
        return &instance;
    }
};

struct ChrCustomizationCondModelMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_INT, 1, true },
            { FT_INT, 3, true },
        };
        static constexpr DB2Meta instance(3460182, -1, 2, 2, 0xA91BA37D, fields, -1);
        return &instance;
    }
};

struct ChrCustomizationConversionMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[7] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3463337, -1, 7, 7, 0x7AA98C56, fields, 4);
        return &instance;
    }
};

struct ChrCustomizationDisplayInfoMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
        };
        static constexpr DB2Meta instance(3593032, -1, 4, 4, 0x7CD43881, fields, -1);
        return &instance;
    }
};

struct ChrCustomizationElementMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[9] =
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
        static constexpr DB2Meta instance(3512765, -1, 9, 9, 0x726D9D9B, fields, -1);
        return &instance;
    }
};

struct ChrCustomizationGeosetMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3456171, -1, 3, 3, 0x9D95412A, fields, -1);
        return &instance;
    }
};

struct ChrCustomizationMaterialMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3459652, -1, 2, 2, 0x68D0798C, fields, -1);
        return &instance;
    }
};

struct ChrCustomizationOptionMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[13] =
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
        static constexpr DB2Meta instance(3384247, 1, 13, 13, 0x77A321D5, fields, 4);
        return &instance;
    }
};

struct ChrCustomizationReqMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[5] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3450453, -1, 5, 5, 0x9997AC13, fields, -1);
        return &instance;
    }
};

struct ChrCustomizationReqChoiceMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3580359, -1, 2, 1, 0x52D624D9, fields, 1);
        return &instance;
    }
};

struct ChrCustomizationSkinnedModelMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3460183, -1, 4, 4, 0x6DA5BD1E, fields, -1);
        return &instance;
    }
};

struct ChrModelMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[17] =
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
        static constexpr DB2Meta instance(3384313, 2, 17, 17, 0x3FE3E372, fields, -1);
        return &instance;
    }
};

struct ChrModelMaterialMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[7] =
        {
            { FT_INT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3566562, 0, 7, 7, 0xB4AB9DAB, fields, 1);
        return &instance;
    }
};

struct ChrModelTextureLayerMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[8] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 3, true },
            { FT_INT, 2, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3548976, -1, 8, 7, 0x3357359C, fields, 7);
        return &instance;
    }
};

struct ChrRaceRacialAbilityMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[6] =
        {
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3507821, -1, 6, 5, 0xB6115535, fields, 5);
        return &instance;
    }
};

struct ChrRaceXChrModelMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3490304, -1, 2, 2, 0xDCBBE9D5, fields, 0);
        return &instance;
    }
};

struct ChrRacesMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[51] =
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
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, true },
        };
        static constexpr DB2Meta instance(1305311, -1, 51, 51, 0xBAD9D8A9, fields, -1);
        return &instance;
    }
};

struct ChrSelectBackgroundCDIMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(4195187, -1, 3, 3, 0x5C22B87C, fields, -1);
        return &instance;
    }
};

struct ChrSpecializationMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[13] =
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
        static constexpr DB2Meta instance(1343390, 3, 13, 13, 0x1F1A9A8F, fields, 4);
        return &instance;
    }
};

struct ChrUpgradeBucketMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_INT, 1, false },
            { FT_SHORT, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(984529, 0, 3, 2, 0x5DD8D93F, fields, 2);
        return &instance;
    }
};

struct ChrUpgradeBucketSpellMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(984528, -1, 2, 1, 0xD5209FCF, fields, 1);
        return &instance;
    }
};

struct ChrUpgradeTierMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_STRING, 1, true },
            { FT_INT, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
        };
        static constexpr DB2Meta instance(984530, 1, 4, 4, 0xC4B6C048, fields, -1);
        return &instance;
    }
};

struct CinematicCameraMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[5] =
        {
            { FT_FLOAT, 3, true },
            { FT_INT, 1, false },
            { FT_FLOAT, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1294214, -1, 5, 5, 0x3920D07C, fields, -1);
        return &instance;
    }
};

struct CinematicSequencesMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_INT, 1, false },
            { FT_SHORT, 8, false },
        };
        static constexpr DB2Meta instance(1134583, -1, 2, 2, 0x32B8FB41, fields, -1);
        return &instance;
    }
};

struct ClientSceneEffectMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[1] =
        {
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1939843, -1, 1, 1, 0x8C4BEE67, fields, -1);
        return &instance;
    }
};

struct CloakDampeningMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[7] =
        {
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 5, true },
            { FT_FLOAT, 5, true },
            { FT_FLOAT, 2, true },
            { FT_FLOAT, 2, true },
        };
        static constexpr DB2Meta instance(1465903, -1, 7, 7, 0x1C66DB37, fields, -1);
        return &instance;
    }
};

struct CloneEffectMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[8] =
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
        static constexpr DB2Meta instance(2175218, -1, 8, 8, 0xC045A5E8, fields, -1);
        return &instance;
    }
};

struct CombatConditionMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[11] =
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
        static constexpr DB2Meta instance(1120958, -1, 11, 11, 0x5CA63D01, fields, -1);
        return &instance;
    }
};

struct CommentatorIndirectSpellMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3067644, -1, 3, 2, 0x415C0D91, fields, 2);
        return &instance;
    }
};

struct CommentatorStartLocationMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_FLOAT, 3, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1664251, -1, 2, 2, 0x36EDE137, fields, -1);
        return &instance;
    }
};

struct CommentatorTrackedCooldownMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_INT, 1, true },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1661584, -1, 4, 3, 0xDF3511FC, fields, 3);
        return &instance;
    }
};

struct CommunityIconMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(2098645, -1, 2, 2, 0xAD2830F3, fields, -1);
        return &instance;
    }
};

struct ComponentModelFileDataMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, true },
        };
        static constexpr DB2Meta instance(1349053, -1, 4, 4, 0x34E0ADCF, fields, -1);
        return &instance;
    }
};

struct ComponentTextureFileDataMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
        };
        static constexpr DB2Meta instance(1278239, -1, 3, 3, 0x2DD855B4, fields, -1);
        return &instance;
    }
};

struct ConditionalContentTuningMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3501965, -1, 4, 3, 0x8DF8B6EC, fields, 3);
        return &instance;
    }
};

struct ConfigurationWarningMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_STRING, 1, true },
            { FT_INT, 1, false },
        };
        static constexpr DB2Meta instance(1709409, -1, 2, 2, 0x6E7F031C, fields, -1);
        return &instance;
    }
};

struct ContentRestrictionRuleSetMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(4281307, -1, 2, 2, 0xD4E8BEC4, fields, -1);
        return &instance;
    }
};

struct ContentTuningMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[11] =
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
        static constexpr DB2Meta instance(1962930, -1, 11, 11, 0xACA848DF, fields, -1);
        return &instance;
    }
};

struct ContentTuningXExpectedMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(2976765, -1, 4, 3, 0x886CD205, fields, 3);
        return &instance;
    }
};

struct ContributionMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[6] =
        {
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 4, true },
        };
        static constexpr DB2Meta instance(1587153, -1, 6, 6, 0xB773D94B, fields, 2);
        return &instance;
    }
};

struct ContributionStyleMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[7] =
        {
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(2143633, -1, 7, 7, 0x001E87C8, fields, -1);
        return &instance;
    }
};

struct ContributionStyleContainerMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[1] =
        {
            { FT_INT, 5, true },
        };
        static constexpr DB2Meta instance(2143634, -1, 1, 1, 0xBCE21C5E, fields, -1);
        return &instance;
    }
};

struct ConversationLineMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[8] =
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
        static constexpr DB2Meta instance(1260801, -1, 8, 8, 0x9EE67C1B, fields, -1);
        return &instance;
    }
};

struct CorruptionEffectsMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_FLOAT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3220711, -1, 4, 4, 0xCD3D02D2, fields, -1);
        return &instance;
    }
};

struct CovenantMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[8] =
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
        static constexpr DB2Meta instance(3384973, -1, 8, 8, 0xAD445FBB, fields, -1);
        return &instance;
    }
};

struct CreatureMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[11] =
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
        static constexpr DB2Meta instance(841631, -1, 11, 11, 0x8246E41C, fields, -1);
        return &instance;
    }
};

struct CreatureDifficultyMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[6] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_SHORT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 8, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(879282, -1, 6, 5, 0x1633422F, fields, 5);
        return &instance;
    }
};

struct CreatureDispXUiCameraMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_INT, 1, false },
            { FT_SHORT, 1, false },
        };
        static constexpr DB2Meta instance(1146692, -1, 2, 2, 0xA8582ED5, fields, -1);
        return &instance;
    }
};

struct CreatureDisplayInfoMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[25] =
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
        static constexpr DB2Meta instance(1108759, 0, 25, 25, 0x1D5BDC6A, fields, -1);
        return &instance;
    }
};

struct CreatureDisplayInfoCondMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[8] =
        {
            { FT_LONG, 1, true },
            { FT_INT, 1, false },
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 3, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1332686, 1, 8, 7, 0xBCC79C0C, fields, 7);
        return &instance;
    }
};

struct CreatureDisplayInfoCondXChoiceMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3670439, -1, 2, 2, 0x3B360250, fields, 0);
        return &instance;
    }
};

struct CreatureDisplayInfoEvtMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_BYTE, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1586882, -1, 4, 3, 0xFD7C9FA8, fields, 3);
        return &instance;
    }
};

struct CreatureDisplayInfoExtraMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[7] =
        {
            { FT_INT, 1, false },
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1264997, 0, 7, 7, 0x8FCCFF0C, fields, -1);
        return &instance;
    }
};

struct CreatureDisplayInfoGeosetDataMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1720141, -1, 3, 2, 0x6A7C8343, fields, 2);
        return &instance;
    }
};

struct CreatureDisplayInfoOptionMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3692043, -1, 3, 2, 0xDBD77820, fields, 2);
        return &instance;
    }
};

struct CreatureDisplayInfoTrnMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[6] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_FLOAT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1146698, -1, 6, 5, 0x7B61A667, fields, 5);
        return &instance;
    }
};

struct CreatureFamilyMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[9] =
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
        static constexpr DB2Meta instance(1351351, -1, 9, 9, 0x78019FD1, fields, -1);
        return &instance;
    }
};

struct CreatureImmunitiesMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[9] =
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
        static constexpr DB2Meta instance(1131322, -1, 9, 9, 0x1B605529, fields, -1);
        return &instance;
    }
};

struct CreatureModelDataMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[31] =
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
            { FT_BYTE, 1, true },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 2, true },
        };
        static constexpr DB2Meta instance(1365368, -1, 31, 31, 0xEDDF3253, fields, -1);
        return &instance;
    }
};

struct CreatureMovementInfoMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[1] =
        {
            { FT_FLOAT, 1, true },
        };
        static constexpr DB2Meta instance(1125666, -1, 1, 1, 0x4A558056, fields, -1);
        return &instance;
    }
};

struct CreatureSoundDataMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[38] =
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
            { FT_INT, 5, false },
            { FT_INT, 4, false },
        };
        static constexpr DB2Meta instance(1344466, 0, 38, 38, 0x0FE7B1EC, fields, -1);
        return &instance;
    }
};

struct CreatureSoundFidgetMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(4178576, -1, 3, 2, 0xECFBE76A, fields, 2);
        return &instance;
    }
};

struct CreatureTypeMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_STRING, 1, true },
            { FT_BYTE, 1, false },
        };
        static constexpr DB2Meta instance(1131315, -1, 2, 2, 0xBDB743EB, fields, -1);
        return &instance;
    }
};

struct CreatureXContributionMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1587158, -1, 2, 1, 0x08F0A453, fields, 1);
        return &instance;
    }
};

struct CreatureXDisplayInfoMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[5] =
        {
            { FT_INT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1864302, -1, 5, 4, 0xF5C33B70, fields, 4);
        return &instance;
    }
};

struct CreatureXUiWidgetSetMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3055738, -1, 3, 3, 0xD5F78F74, fields, -1);
        return &instance;
    }
};

struct CriteriaMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[11] =
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
        static constexpr DB2Meta instance(1263817, -1, 11, 11, 0x1C237366, fields, -1);
        return &instance;
    }
};

struct CriteriaTreeMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[7] =
        {
            { FT_STRING, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_BYTE, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1263818, -1, 7, 7, 0x9C1C42E0, fields, -1);
        return &instance;
    }
};

struct CriteriaTreeXEffectMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_SHORT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1345969, -1, 2, 1, 0xD09A14A8, fields, 1);
        return &instance;
    }
};

struct CurrencyCategoryMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_STRING, 1, true },
            { FT_INT, 1, true },
            { FT_BYTE, 1, false },
        };
        static constexpr DB2Meta instance(1125667, -1, 3, 3, 0xDEE5E915, fields, -1);
        return &instance;
    }
};

struct CurrencyContainerMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[8] =
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
        static constexpr DB2Meta instance(1934603, -1, 8, 7, 0x43B60080, fields, 7);
        return &instance;
    }
};

struct CurrencyTypesMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[15] =
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
            { FT_INT, 2, true },
        };
        static constexpr DB2Meta instance(1095531, -1, 15, 15, 0x9DB809D5, fields, -1);
        return &instance;
    }
};

struct CurveMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
        };
        static constexpr DB2Meta instance(892585, -1, 2, 2, 0x7266948A, fields, -1);
        return &instance;
    }
};

struct CurvePointMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_FLOAT, 2, true },
            { FT_FLOAT, 2, true },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
        };
        static constexpr DB2Meta instance(892586, -1, 4, 4, 0x205CB4E6, fields, -1);
        return &instance;
    }
};

struct DeathThudLookupsMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
        };
        static constexpr DB2Meta instance(1279415, -1, 4, 4, 0xEA2448BE, fields, -1);
        return &instance;
    }
};

struct DecalPropertiesMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[21] =
        {
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
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_FLOAT, 4, true },
            { FT_FLOAT, 4, true },
        };
        static constexpr DB2Meta instance(1278176, -1, 21, 21, 0xAC35CDEF, fields, -1);
        return &instance;
    }
};

struct DeclinedWordMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_INT, 1, false },
        };
        static constexpr DB2Meta instance(1279100, 1, 2, 2, 0xD648129D, fields, -1);
        return &instance;
    }
};

struct DeclinedWordCasesMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_BYTE, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1279099, -1, 3, 2, 0x626BC51A, fields, 2);
        return &instance;
    }
};

struct DestructibleModelDataMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[22] =
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
        static constexpr DB2Meta instance(1122116, -1, 22, 22, 0x7BC9B1D9, fields, -1);
        return &instance;
    }
};

struct DeviceBlacklistMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
        };
        static constexpr DB2Meta instance(922722, -1, 2, 2, 0x1458ACA1, fields, -1);
        return &instance;
    }
};

struct DifficultyMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[13] =
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
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
        };
        static constexpr DB2Meta instance(1352127, -1, 13, 13, 0x9B05F092, fields, -1);
        return &instance;
    }
};

struct DisplaySeasonMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_STRING, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(4279827, -1, 4, 4, 0x80AFE414, fields, -1);
        return &instance;
    }
};

struct DissolveEffectMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[19] =
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
        };
        static constexpr DB2Meta instance(1304325, -1, 19, 19, 0xA9203D0B, fields, -1);
        return &instance;
    }
};

struct DriverBlacklistMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[7] =
        {
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
        };
        static constexpr DB2Meta instance(922720, -1, 7, 7, 0x3FDF91BC, fields, -1);
        return &instance;
    }
};

struct DungeonEncounterMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[11] =
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
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1347279, 1, 11, 11, 0xAEAB1A82, fields, 2);
        return &instance;
    }
};

struct DurabilityCostsMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_SHORT, 21, false },
            { FT_SHORT, 8, false },
        };
        static constexpr DB2Meta instance(1283019, -1, 2, 2, 0x3DBDFDD1, fields, -1);
        return &instance;
    }
};

struct DurabilityQualityMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[1] =
        {
            { FT_FLOAT, 1, true },
        };
        static constexpr DB2Meta instance(1130268, -1, 1, 1, 0xD4F6FFC8, fields, -1);
        return &instance;
    }
};

struct EdgeGlowEffectMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[13] =
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
        static constexpr DB2Meta instance(1387381, -1, 13, 13, 0x1589CA63, fields, -1);
        return &instance;
    }
};

struct EmotesMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[9] =
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
        static constexpr DB2Meta instance(1343602, -1, 9, 9, 0xC2B2FDD1, fields, -1);
        return &instance;
    }
};

struct EmotesTextMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_SHORT, 1, false },
        };
        static constexpr DB2Meta instance(1347273, -1, 2, 2, 0x8C749D28, fields, -1);
        return &instance;
    }
};

struct EmotesTextDataMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_STRING, 1, true },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1283024, -1, 3, 2, 0x3E78FC97, fields, 2);
        return &instance;
    }
};

struct EmotesTextSoundMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[5] =
        {
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1286524, -1, 5, 4, 0xF058B2EF, fields, 4);
        return &instance;
    }
};

struct EnvironmentalDamageMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
        };
        static constexpr DB2Meta instance(1278398, -1, 2, 2, 0x0D289832, fields, -1);
        return &instance;
    }
};

struct ExhaustionMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[7] =
        {
            { FT_STRING, 1, true },
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_INT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
        };
        static constexpr DB2Meta instance(1343313, -1, 7, 7, 0x115BE21D, fields, -1);
        return &instance;
    }
};

struct ExpectedStatMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[11] =
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
        static constexpr DB2Meta instance(1937326, -1, 11, 10, 0xD0570787, fields, 10);
        return &instance;
    }
};

struct ExpectedStatModMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[9] =
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
        static constexpr DB2Meta instance(1969773, -1, 9, 9, 0x462D65F2, fields, -1);
        return &instance;
    }
};

struct ExtraAbilityInfoMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[6] =
        {
            { FT_STRING, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3527889, -1, 6, 6, 0x006F6DEF, fields, 1);
        return &instance;
    }
};

struct FactionMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[15] =
        {
            { FT_LONG, 4, true },
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_SHORT, 1, true },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, false },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 4, true },
            { FT_SHORT, 4, false },
            { FT_INT, 4, true },
            { FT_INT, 4, true },
            { FT_FLOAT, 2, true },
            { FT_BYTE, 2, false },
        };
        static constexpr DB2Meta instance(1361972, -1, 15, 15, 0xEB3D0F9B, fields, -1);
        return &instance;
    }
};

struct FactionGroupMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[5] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_STRING, 1, true },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1343595, -1, 5, 5, 0x5CCF4BE3, fields, -1);
        return &instance;
    }
};

struct FactionTemplateMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[7] =
        {
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_SHORT, 4, false },
            { FT_SHORT, 4, false },
        };
        static constexpr DB2Meta instance(1361579, -1, 7, 7, 0x0DCC3090, fields, -1);
        return &instance;
    }
};

struct FootprintTexturesMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1308056, -1, 3, 3, 0x6E56D772, fields, -1);
        return &instance;
    }
};

struct FootstepTerrainLookupMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
        };
        static constexpr DB2Meta instance(1267647, -1, 4, 4, 0xC8B9FDAC, fields, -1);
        return &instance;
    }
};

struct FriendshipRepReactionMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_STRING, 1, true },
            { FT_INT, 1, false },
            { FT_SHORT, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1237638, -1, 4, 4, 0xA1157C1F, fields, 1);
        return &instance;
    }
};

struct FriendshipReputationMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[7] =
        {
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1237639, 3, 7, 7, 0xDCF9508F, fields, -1);
        return &instance;
    }
};

struct FullScreenEffectMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[28] =
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
        static constexpr DB2Meta instance(1348282, -1, 28, 28, 0x6D545850, fields, -1);
        return &instance;
    }
};

struct GMSurveyAnswersMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_STRING, 1, true },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1283025, -1, 3, 2, 0x8C4F9BE3, fields, 2);
        return &instance;
    }
};

struct GMSurveyCurrentSurveyMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[1] =
        {
            { FT_BYTE, 1, false },
        };
        static constexpr DB2Meta instance(1278177, -1, 1, 1, 0x29F86C92, fields, -1);
        return &instance;
    }
};

struct GMSurveyQuestionsMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[1] =
        {
            { FT_STRING, 1, true },
        };
        static constexpr DB2Meta instance(1278178, -1, 1, 1, 0x10770511, fields, -1);
        return &instance;
    }
};

struct GMSurveySurveysMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[1] =
        {
            { FT_BYTE, 15, false },
        };
        static constexpr DB2Meta instance(1283020, -1, 1, 1, 0x808736D1, fields, -1);
        return &instance;
    }
};

struct GameClockDebugMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[1] =
        {
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(2922072, -1, 1, 1, 0xD30981EC, fields, -1);
        return &instance;
    }
};

struct GameObjectAnimGroupMemberMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
        };
        static constexpr DB2Meta instance(3565753, -1, 4, 4, 0x375C3387, fields, 0);
        return &instance;
    }
};

struct GameObjectArtKitMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_INT, 1, true },
            { FT_INT, 3, true },
        };
        static constexpr DB2Meta instance(1266737, -1, 2, 2, 0x520690EF, fields, -1);
        return &instance;
    }
};

struct GameObjectDiffAnimMapMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1302847, -1, 4, 3, 0x7403DFA2, fields, 3);
        return &instance;
    }
};

struct GameObjectDisplayInfoMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[5] =
        {
            { FT_FLOAT, 6, true },
            { FT_INT, 1, true },
            { FT_SHORT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
        };
        static constexpr DB2Meta instance(1266277, -1, 5, 5, 0x7E33A93F, fields, -1);
        return &instance;
    }
};

struct GameObjectDisplayInfoXSoundKitMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_INT, 1, false },
            { FT_BYTE, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1345272, -1, 3, 2, 0x16B43E1B, fields, 2);
        return &instance;
    }
};

struct GameObjectsMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[12] =
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
        static constexpr DB2Meta instance(841620, 3, 12, 12, 0xE1536F72, fields, 4);
        return &instance;
    }
};

struct GameParameterMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[5] =
        {
            { FT_INT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3405438, -1, 5, 5, 0xE2A34B99, fields, -1);
        return &instance;
    }
};

struct GameTipsMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[5] =
        {
            { FT_STRING, 1, true },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1368021, -1, 5, 5, 0x3D7E744D, fields, -1);
        return &instance;
    }
};

struct GarrAbilityMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[7] =
        {
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
            { FT_SHORT, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(966238, -1, 7, 7, 0x895C6CBD, fields, -1);
        return &instance;
    }
};

struct GarrAbilityCategoryMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[1] =
        {
            { FT_STRING, 1, true },
        };
        static constexpr DB2Meta instance(1020248, -1, 1, 1, 0xB0DD8F60, fields, -1);
        return &instance;
    }
};

struct GarrAbilityEffectMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[12] =
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
        static constexpr DB2Meta instance(966241, 0, 12, 12, 0x42A6AC5E, fields, 1);
        return &instance;
    }
};

struct GarrAutoCombatantMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[9] =
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
        static constexpr DB2Meta instance(3305399, -1, 9, 9, 0xC6049FC4, fields, -1);
        return &instance;
    }
};

struct GarrAutoSpellMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[7] =
        {
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3305400, -1, 7, 7, 0x4229E5FF, fields, -1);
        return &instance;
    }
};

struct GarrAutoSpellEffectMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[8] =
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
        static constexpr DB2Meta instance(3307335, 0, 8, 8, 0x71E3FAFA, fields, 1);
        return &instance;
    }
};

struct GarrBuildingMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[24] =
        {
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_BYTE, 1, false },
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
        static constexpr DB2Meta instance(929747, -1, 24, 24, 0x76E04D94, fields, -1);
        return &instance;
    }
};

struct GarrBuildingDoodadSetMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[5] =
        {
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
        };
        static constexpr DB2Meta instance(943937, -1, 5, 5, 0x398E9742, fields, -1);
        return &instance;
    }
};

struct GarrBuildingPlotInstMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[5] =
        {
            { FT_FLOAT, 2, true },
            { FT_INT, 1, false },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
        };
        static constexpr DB2Meta instance(983298, 1, 5, 5, 0xDEF48812, fields, 2);
        return &instance;
    }
};

struct GarrClassSpecMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[7] =
        {
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(981570, -1, 7, 7, 0x0872F30A, fields, -1);
        return &instance;
    }
};

struct GarrClassSpecPlayerCondMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[6] =
        {
            { FT_STRING, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_BYTE, 1, false },
        };
        static constexpr DB2Meta instance(1380674, -1, 6, 6, 0x1F048C5D, fields, -1);
        return &instance;
    }
};

struct GarrEncounterMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[8] =
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
        static constexpr DB2Meta instance(975304, -1, 8, 8, 0x00F63E78, fields, -1);
        return &instance;
    }
};

struct GarrEncounterSetXEncounterMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1354772, 0, 3, 2, 0x0C38FD7C, fields, 2);
        return &instance;
    }
};

struct GarrEncounterXMechanicMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_INT, 1, true },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(967961, -1, 3, 2, 0x4727DED7, fields, 2);
        return &instance;
    }
};

struct GarrFollItemSetMemberMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_INT, 1, true },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(981569, -1, 4, 3, 0x01FD0F5B, fields, 3);
        return &instance;
    }
};

struct GarrFollSupportSpellMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1345970, -1, 4, 3, 0xDCED652F, fields, 3);
        return &instance;
    }
};

struct GarrFollowerMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[33] =
        {
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
        static constexpr DB2Meta instance(949906, -1, 33, 33, 0x2F65E7B8, fields, -1);
        return &instance;
    }
};

struct GarrFollowerLevelXPMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
        };
        static constexpr DB2Meta instance(970979, -1, 4, 4, 0xC6D9156C, fields, -1);
        return &instance;
    }
};

struct GarrFollowerQualityMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[7] =
        {
            { FT_BYTE, 1, false },
            { FT_INT, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
            { FT_INT, 1, false },
        };
        static constexpr DB2Meta instance(1027793, -1, 7, 7, 0x12E3D869, fields, -1);
        return &instance;
    }
};

struct GarrFollowerSetXFollowerMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1361029, -1, 2, 1, 0x0E5F4858, fields, 1);
        return &instance;
    }
};

struct GarrFollowerTypeMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[7] =
        {
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1118784, -1, 7, 7, 0x90DE9D04, fields, -1);
        return &instance;
    }
};

struct GarrFollowerUICreatureMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[6] =
        {
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1412636, -1, 6, 5, 0x48A9C93E, fields, 5);
        return &instance;
    }
};

struct GarrFollowerXAbilityMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(968468, -1, 4, 3, 0xDC1338B5, fields, 3);
        return &instance;
    }
};

struct GarrItemLevelUpgradeDataMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_BYTE, 1, false },
        };
        static constexpr DB2Meta instance(1572314, -1, 4, 4, 0xFF309F3E, fields, -1);
        return &instance;
    }
};

struct GarrMechanicMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_INT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(967963, -1, 3, 3, 0xEC754F2F, fields, -1);
        return &instance;
    }
};

struct GarrMechanicSetXMechanicMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_INT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1391531, 0, 3, 2, 0xD2D3C4ED, fields, 2);
        return &instance;
    }
};

struct GarrMechanicTypeMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_INT, 1, true },
            { FT_BYTE, 1, false },
        };
        static constexpr DB2Meta instance(967964, -1, 4, 4, 0xF88C0C01, fields, -1);
        return &instance;
    }
};

struct GarrMissionMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[31] =
        {
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_FLOAT, 2, true },
            { FT_FLOAT, 2, true },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
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
        static constexpr DB2Meta instance(967962, -1, 31, 31, 0xCA0E980C, fields, 16);
        return &instance;
    }
};

struct GarrMissionSetMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[6] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3055759, -1, 6, 6, 0x1858B6AD, fields, -1);
        return &instance;
    }
};

struct GarrMissionTextureMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_FLOAT, 2, true },
            { FT_SHORT, 1, false },
        };
        static constexpr DB2Meta instance(1125220, -1, 2, 2, 0x17FF9F33, fields, -1);
        return &instance;
    }
};

struct GarrMissionTypeMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_STRING, 1, true },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
        };
        static constexpr DB2Meta instance(984174, -1, 3, 3, 0xEE85FBAD, fields, -1);
        return &instance;
    }
};

struct GarrMissionXEncounterMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[5] =
        {
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(967960, -1, 5, 4, 0x902619AC, fields, 4);
        return &instance;
    }
};

struct GarrMissionXFollowerMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_BYTE, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1359096, -1, 4, 3, 0x5B84EFCD, fields, 3);
        return &instance;
    }
};

struct GarrMssnBonusAbilityMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[5] =
        {
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
            { FT_FLOAT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1138458, -1, 5, 5, 0x607D4E83, fields, -1);
        return &instance;
    }
};

struct GarrPlotMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[7] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 2, false },
        };
        static constexpr DB2Meta instance(937634, -1, 7, 7, 0x47067617, fields, -1);
        return &instance;
    }
};

struct GarrPlotBuildingMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
        };
        static constexpr DB2Meta instance(929743, -1, 2, 2, 0x9C6539B2, fields, -1);
        return &instance;
    }
};

struct GarrPlotInstanceMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_BYTE, 1, false },
        };
        static constexpr DB2Meta instance(929742, -1, 2, 2, 0xC5609120, fields, -1);
        return &instance;
    }
};

struct GarrPlotUICategoryMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_STRING, 1, true },
            { FT_BYTE, 1, false },
        };
        static constexpr DB2Meta instance(937635, -1, 2, 2, 0xD6167CD7, fields, -1);
        return &instance;
    }
};

struct GarrSiteLevelMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[9] =
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
        static constexpr DB2Meta instance(939295, -1, 9, 9, 0x41BF2E0A, fields, -1);
        return &instance;
    }
};

struct GarrSiteLevelPlotInstMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_FLOAT, 2, true },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
        };
        static constexpr DB2Meta instance(940404, -1, 4, 4, 0x1CAD597B, fields, 1);
        return &instance;
    }
};

struct GarrSpecializationMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[7] =
        {
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
            { FT_FLOAT, 2, true },
        };
        static constexpr DB2Meta instance(937647, -1, 7, 7, 0x7983E7D9, fields, -1);
        return &instance;
    }
};

struct GarrStringMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[1] =
        {
            { FT_STRING, 1, true },
        };
        static constexpr DB2Meta instance(1416758, -1, 1, 1, 0x9588F8C8, fields, -1);
        return &instance;
    }
};

struct GarrTalTreeXGarrTalResearchMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3195601, -1, 3, 3, 0xF00FA3EA, fields, -1);
        return &instance;
    }
};

struct GarrTalentMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[15] =
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
        static constexpr DB2Meta instance(1361032, 2, 15, 15, 0xEF4DB72A, fields, 3);
        return &instance;
    }
};

struct GarrTalentCostMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[9] =
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
        static constexpr DB2Meta instance(3514438, 1, 9, 9, 0x8E3D05D3, fields, 2);
        return &instance;
    }
};

struct GarrTalentMapPOIMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_FLOAT, 2, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3534056, -1, 2, 2, 0x75F07445, fields, -1);
        return &instance;
    }
};

struct GarrTalentRankMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[18] =
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
        static constexpr DB2Meta instance(3069763, 0, 18, 17, 0x1D54CA3C, fields, 17);
        return &instance;
    }
};

struct GarrTalentRankGroupEntryMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(4382239, -1, 2, 1, 0xE2F5D419, fields, 1);
        return &instance;
    }
};

struct GarrTalentRankGroupResearchModMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(4389481, -1, 4, 3, 0x14AF829F, fields, 3);
        return &instance;
    }
};

struct GarrTalentResearchMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[8] =
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
        static constexpr DB2Meta instance(3195518, -1, 8, 8, 0x8A171D9D, fields, -1);
        return &instance;
    }
};

struct GarrTalentSocketPropertiesMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3612617, -1, 2, 2, 0xDA437EE1, fields, -1);
        return &instance;
    }
};

struct GarrTalentTreeMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[12] =
        {
            { FT_STRING, 1, true },
            { FT_BYTE, 1, false },
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
        static constexpr DB2Meta instance(1361030, -1, 12, 12, 0xC148F18E, fields, -1);
        return &instance;
    }
};

struct GarrTypeMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[9] =
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
        static constexpr DB2Meta instance(1333161, 0, 9, 9, 0x6C12C0C5, fields, -1);
        return &instance;
    }
};

struct GarrUiAnimClassInfoMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[6] =
        {
            { FT_INT, 1, true },
            { FT_BYTE, 1, false },
            { FT_FLOAT, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
        };
        static constexpr DB2Meta instance(976037, -1, 6, 6, 0x3D333DD8, fields, -1);
        return &instance;
    }
};

struct GarrUiAnimRaceInfoMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[13] =
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
        static constexpr DB2Meta instance(976035, -1, 13, 13, 0x225F0657, fields, -1);
        return &instance;
    }
};

struct GemPropertiesMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_SHORT, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1343604, -1, 2, 2, 0x61DF3B70, fields, -1);
        return &instance;
    }
};

struct GlobalCurveMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3752002, -1, 2, 2, 0x7EA5C3BF, fields, -1);
        return &instance;
    }
};

struct GlobalGameContentTuningMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3756368, -1, 2, 2, 0xC5E2173D, fields, -1);
        return &instance;
    }
};

struct GlobalPlayerConditionMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(4082838, -1, 3, 2, 0x30F25618, fields, 2);
        return &instance;
    }
};

struct GlobalPlayerConditionSetMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_INT, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(4082839, 0, 2, 2, 0xD111129C, fields, -1);
        return &instance;
    }
};

struct GlobalStringsMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_STRING, 1, true },
            { FT_BYTE, 1, false },
        };
        static constexpr DB2Meta instance(1394440, -1, 3, 3, 0x9D50610A, fields, -1);
        return &instance;
    }
};

struct GlyphBindableSpellMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1270147, -1, 2, 1, 0x7F8BAF7B, fields, 1);
        return &instance;
    }
};

struct GlyphExclusiveCategoryMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[1] =
        {
            { FT_STRING, 1, true },
        };
        static constexpr DB2Meta instance(948546, -1, 1, 1, 0x283BBF49, fields, -1);
        return &instance;
    }
};

struct GlyphPropertiesMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_INT, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1345274, -1, 4, 4, 0x8242C866, fields, -1);
        return &instance;
    }
};

struct GlyphRequiredSpecMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_SHORT, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(948496, -1, 2, 1, 0xCC301712, fields, 1);
        return &instance;
    }
};

struct GossipXGarrTalentTreesMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(4407361, -1, 2, 1, 0x9BE63EB3, fields, 1);
        return &instance;
    }
};

struct GossipXUIDisplayInfoMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3622253, -1, 4, 4, 0xB59290B4, fields, -1);
        return &instance;
    }
};

struct GradientEffectMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[16] =
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
        };
        static constexpr DB2Meta instance(2433582, -1, 16, 16, 0x1E246107, fields, -1);
        return &instance;
    }
};

struct GroundEffectDoodadMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[9] =
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
        static constexpr DB2Meta instance(1308057, -1, 9, 9, 0xF592B773, fields, -1);
        return &instance;
    }
};

struct GroundEffectTextureMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[5] =
        {
            { FT_INT, 1, false },
            { FT_BYTE, 1, false },
            { FT_SHORT, 4, false },
            { FT_BYTE, 4, true },
            { FT_BYTE, 4, true },
        };
        static constexpr DB2Meta instance(1308499, -1, 5, 5, 0x3DEC72D8, fields, -1);
        return &instance;
    }
};

struct GroupFinderActivityMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[15] =
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
        static constexpr DB2Meta instance(974813, -1, 15, 15, 0x2646188E, fields, -1);
        return &instance;
    }
};

struct GroupFinderActivityGrpMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_STRING, 1, true },
            { FT_BYTE, 1, false },
        };
        static constexpr DB2Meta instance(974814, -1, 2, 2, 0x89256FF7, fields, -1);
        return &instance;
    }
};

struct GroupFinderActivityXPvpBracketMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(4206623, -1, 2, 2, 0xEE2CD2C6, fields, -1);
        return &instance;
    }
};

struct GroupFinderCategoryMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(974812, -1, 4, 4, 0x9B053B0D, fields, -1);
        return &instance;
    }
};

struct GuildColorBackgroundMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
        };
        static constexpr DB2Meta instance(1286526, -1, 3, 3, 0x1364EF78, fields, -1);
        return &instance;
    }
};

struct GuildColorBorderMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
        };
        static constexpr DB2Meta instance(1286527, -1, 3, 3, 0x1364EF78, fields, -1);
        return &instance;
    }
};

struct GuildColorEmblemMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
        };
        static constexpr DB2Meta instance(1286525, -1, 3, 3, 0x1364EF78, fields, -1);
        return &instance;
    }
};

struct GuildEmblemMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(2734754, -1, 2, 2, 0xFA4DFEEA, fields, -1);
        return &instance;
    }
};

struct GuildPerkSpellsMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[1] =
        {
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1135238, -1, 1, 1, 0x465F6F2A, fields, -1);
        return &instance;
    }
};

struct GuildShirtBackgroundMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(2921008, -1, 4, 3, 0xF7862CB0, fields, 3);
        return &instance;
    }
};

struct GuildShirtBorderMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[5] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(2921475, -1, 5, 4, 0x67FA04AE, fields, 4);
        return &instance;
    }
};

struct GuildTabardBackgroundMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(2909769, -1, 4, 3, 0xB5B6CD95, fields, 3);
        return &instance;
    }
};

struct GuildTabardBorderMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[5] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(2920485, -1, 5, 4, 0x6C616EAA, fields, 4);
        return &instance;
    }
};

struct GuildTabardEmblemMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(2910470, -1, 4, 3, 0xB8CF8F15, fields, 3);
        return &instance;
    }
};

struct HeirloomMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[10] =
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
        static constexpr DB2Meta instance(1097696, 1, 10, 10, 0xFD204E4C, fields, -1);
        return &instance;
    }
};

struct HelmetAnimScalingMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_INT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1348283, -1, 3, 2, 0x2152D6E4, fields, 2);
        return &instance;
    }
};

struct HelmetGeosetDataMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_INT, 1, true },
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(2821752, -1, 4, 3, 0xE253742F, fields, 3);
        return &instance;
    }
};

struct HighlightColorMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[5] =
        {
            { FT_BYTE, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_BYTE, 1, false },
        };
        static constexpr DB2Meta instance(996358, -1, 5, 5, 0x5F6F32BA, fields, -1);
        return &instance;
    }
};

struct HolidayDescriptionsMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[1] =
        {
            { FT_STRING, 1, true },
        };
        static constexpr DB2Meta instance(996360, -1, 1, 1, 0xD981411C, fields, -1);
        return &instance;
    }
};

struct HolidayNamesMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[1] =
        {
            { FT_STRING, 1, true },
        };
        static constexpr DB2Meta instance(996359, -1, 1, 1, 0x31516347, fields, -1);
        return &instance;
    }
};

struct HolidaysMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[11] =
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
        static constexpr DB2Meta instance(996357, -1, 11, 11, 0xDEC453C4, fields, -1);
        return &instance;
    }
};

struct HotfixesMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1995523, -1, 4, 4, 0xC02BA201, fields, -1);
        return &instance;
    }
};

struct ImportPriceArmorMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
        };
        static constexpr DB2Meta instance(1121229, -1, 4, 4, 0x7979D30F, fields, -1);
        return &instance;
    }
};

struct ImportPriceQualityMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[1] =
        {
            { FT_FLOAT, 1, true },
        };
        static constexpr DB2Meta instance(1121228, -1, 1, 1, 0xD4F6FFC8, fields, -1);
        return &instance;
    }
};

struct ImportPriceShieldMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[1] =
        {
            { FT_FLOAT, 1, true },
        };
        static constexpr DB2Meta instance(1121227, -1, 1, 1, 0xD4F6FFC8, fields, -1);
        return &instance;
    }
};

struct ImportPriceWeaponMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[1] =
        {
            { FT_FLOAT, 1, true },
        };
        static constexpr DB2Meta instance(1121230, -1, 1, 1, 0xD4F6FFC8, fields, -1);
        return &instance;
    }
};

struct InvasionClientDataMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[10] =
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
        static constexpr DB2Meta instance(1336651, 2, 10, 9, 0xC66039FC, fields, 9);
        return &instance;
    }
};

struct ItemMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[10] =
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
        };
        static constexpr DB2Meta instance(841626, -1, 10, 10, 0x327E4945, fields, -1);
        return &instance;
    }
};

struct ItemAppearanceMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[5] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(982462, -1, 5, 5, 0x33C9038E, fields, -1);
        return &instance;
    }
};

struct ItemAppearanceXUiCameraMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
        };
        static constexpr DB2Meta instance(1248126, -1, 2, 2, 0x7E42B0D5, fields, -1);
        return &instance;
    }
};

struct ItemArmorQualityMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[1] =
        {
            { FT_FLOAT, 7, true },
        };
        static constexpr DB2Meta instance(1283021, -1, 1, 1, 0x5DAB3131, fields, -1);
        return &instance;
    }
};

struct ItemArmorShieldMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_FLOAT, 7, true },
            { FT_SHORT, 1, false },
        };
        static constexpr DB2Meta instance(1277741, -1, 2, 2, 0x4E03E769, fields, -1);
        return &instance;
    }
};

struct ItemArmorTotalMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[5] =
        {
            { FT_SHORT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
        };
        static constexpr DB2Meta instance(1283022, -1, 5, 5, 0xC1DD3156, fields, -1);
        return &instance;
    }
};

struct ItemBagFamilyMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[1] =
        {
            { FT_STRING, 1, true },
        };
        static constexpr DB2Meta instance(1278179, -1, 1, 1, 0xB0DD8F60, fields, -1);
        return &instance;
    }
};

struct ItemBonusMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_INT, 4, true },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
        };
        static constexpr DB2Meta instance(959070, -1, 4, 4, 0x7864A3E0, fields, 1);
        return &instance;
    }
};

struct ItemBonusListMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_INT, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1805807, 0, 2, 2, 0x31228AEF, fields, -1);
        return &instance;
    }
};

struct ItemBonusListGroupMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3755382, -1, 2, 2, 0x465A33AE, fields, -1);
        return &instance;
    }
};

struct ItemBonusListGroupEntryMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[7] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3025306, -1, 7, 7, 0xA5579C9E, fields, 0);
        return &instance;
    }
};

struct ItemBonusListLevelDeltaMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_SHORT, 1, true },
            { FT_INT, 1, false },
        };
        static constexpr DB2Meta instance(1320358, 1, 2, 2, 0xC6EA2151, fields, -1);
        return &instance;
    }
};

struct ItemBonusListWarforgeLevelDeltaMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_SHORT, 1, true },
            { FT_INT, 1, false },
        };
        static constexpr DB2Meta instance(2924997, 1, 2, 2, 0xC6EA2151, fields, -1);
        return &instance;
    }
};

struct ItemBonusSequenceSpellMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3026822, -1, 2, 1, 0x2AA71F9B, fields, 1);
        return &instance;
    }
};

struct ItemBonusTreeMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3055768, -1, 2, 2, 0xBC8C367C, fields, -1);
        return &instance;
    }
};

struct ItemBonusTreeGroupEntryMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(4407505, -1, 2, 1, 0x0D33F559, fields, 1);
        return &instance;
    }
};

struct ItemBonusTreeNodeMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[7] =
        {
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(987134, -1, 7, 6, 0xC1AEA21E, fields, 6);
        return &instance;
    }
};

struct ItemChildEquipmentMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_BYTE, 1, false },
        };
        static constexpr DB2Meta instance(1247926, -1, 3, 3, 0xE726DCEE, fields, 0);
        return &instance;
    }
};

struct ItemClassMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_STRING, 1, true },
            { FT_BYTE, 1, true },
            { FT_FLOAT, 1, true },
            { FT_BYTE, 1, false },
        };
        static constexpr DB2Meta instance(1140189, -1, 4, 4, 0xC21C5BEA, fields, -1);
        return &instance;
    }
};

struct ItemContextPickerEntryMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[6] =
        {
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1405665, -1, 6, 5, 0xA71A3E17, fields, 5);
        return &instance;
    }
};

struct ItemConversionMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(4337196, -1, 3, 3, 0x63D17D1A, fields, -1);
        return &instance;
    }
};

struct ItemConversionEntryMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(4337197, -1, 2, 1, 0xFDC43755, fields, 1);
        return &instance;
    }
};

struct ItemCurrencyCostMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[1] =
        {
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(801670, -1, 1, 1, 0xE55A34CC, fields, 0);
        return &instance;
    }
};

struct ItemCurrencyValueMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_INT, 1, true },
            { FT_INT, 4, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3755770, -1, 3, 2, 0x664B8E34, fields, 2);
        return &instance;
    }
};

struct ItemDamageAmmoMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_SHORT, 1, false },
            { FT_FLOAT, 7, true },
        };
        static constexpr DB2Meta instance(1277740, -1, 2, 2, 0xBD540229, fields, -1);
        return &instance;
    }
};

struct ItemDamageOneHandMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_SHORT, 1, false },
            { FT_FLOAT, 7, true },
        };
        static constexpr DB2Meta instance(1277743, -1, 2, 2, 0xBD540229, fields, -1);
        return &instance;
    }
};

struct ItemDamageOneHandCasterMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_SHORT, 1, false },
            { FT_FLOAT, 7, true },
        };
        static constexpr DB2Meta instance(1277739, -1, 2, 2, 0xBD540229, fields, -1);
        return &instance;
    }
};

struct ItemDamageTwoHandMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_SHORT, 1, false },
            { FT_FLOAT, 7, true },
        };
        static constexpr DB2Meta instance(1277738, -1, 2, 2, 0xBD540229, fields, -1);
        return &instance;
    }
};

struct ItemDamageTwoHandCasterMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_SHORT, 1, false },
            { FT_FLOAT, 7, true },
        };
        static constexpr DB2Meta instance(1277742, -1, 2, 2, 0xBD540229, fields, -1);
        return &instance;
    }
};

struct ItemDisenchantLootMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[7] =
        {
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1134087, -1, 7, 6, 0xB1D813A9, fields, 6);
        return &instance;
    }
};

struct ItemDisplayInfoMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[15] =
        {
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
        static constexpr DB2Meta instance(1266429, -1, 15, 15, 0xF2D99687, fields, -1);
        return &instance;
    }
};

struct ItemDisplayInfoMaterialResMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_BYTE, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1280614, -1, 3, 2, 0x83420BDB, fields, 2);
        return &instance;
    }
};

struct ItemDisplayXUiCameraMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_INT, 1, true },
            { FT_SHORT, 1, false },
        };
        static constexpr DB2Meta instance(1146690, -1, 2, 2, 0x5867E622, fields, -1);
        return &instance;
    }
};

struct ItemEffectMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[8] =
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
        static constexpr DB2Meta instance(969941, -1, 8, 8, 0xF9253409, fields, -1);
        return &instance;
    }
};

struct ItemExtendedCostMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[10] =
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
        static constexpr DB2Meta instance(801681, -1, 10, 10, 0x8EA78043, fields, -1);
        return &instance;
    }
};

struct ItemFallbackVisualMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(2358574, -1, 3, 3, 0xB0198BA2, fields, -1);
        return &instance;
    }
};

struct ItemGroupSoundsMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[1] =
        {
            { FT_INT, 4, false },
        };
        static constexpr DB2Meta instance(1283023, -1, 1, 1, 0xBFD29A96, fields, -1);
        return &instance;
    }
};

struct ItemLevelSelectorMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
        };
        static constexpr DB2Meta instance(1588911, -1, 3, 3, 0x25BC6A6B, fields, -1);
        return &instance;
    }
};

struct ItemLevelSelectorQualityMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_INT, 1, true },
            { FT_BYTE, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1624937, -1, 3, 2, 0xBAF7EC29, fields, 2);
        return &instance;
    }
};

struct ItemLevelSelectorQualitySetMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_SHORT, 1, true },
            { FT_SHORT, 1, true },
        };
        static constexpr DB2Meta instance(1624933, -1, 2, 2, 0x4080CC90, fields, -1);
        return &instance;
    }
};

struct ItemLimitCategoryMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_STRING, 1, true },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
        };
        static constexpr DB2Meta instance(1237440, -1, 3, 3, 0x403BC7B2, fields, -1);
        return &instance;
    }
};

struct ItemLimitCategoryConditionMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_BYTE, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1378590, -1, 3, 2, 0x9E37B423, fields, 2);
        return &instance;
    }
};

struct ItemModifiedAppearanceMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[6] =
        {
            { FT_INT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_BYTE, 1, false },
        };
        static constexpr DB2Meta instance(982457, 0, 6, 6, 0x0120090C, fields, 1);
        return &instance;
    }
};

struct ItemModifiedAppearanceExtraMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[5] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, true },
        };
        static constexpr DB2Meta instance(1278399, -1, 5, 5, 0x08968F49, fields, -1);
        return &instance;
    }
};

struct ItemNameDescriptionMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_STRING, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1332559, -1, 2, 2, 0xB60E60BD, fields, -1);
        return &instance;
    }
};

struct ItemNameSlotOverrideMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_STRING, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3723474, -1, 3, 2, 0xCF0119FB, fields, 2);
        return &instance;
    }
};

struct ItemPetFoodMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[1] =
        {
            { FT_STRING, 1, true },
        };
        static constexpr DB2Meta instance(1302240, -1, 1, 1, 0x332FA55B, fields, -1);
        return &instance;
    }
};

struct ItemPriceBaseMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_SHORT, 1, false },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
        };
        static constexpr DB2Meta instance(1121231, -1, 3, 3, 0xAA32653C, fields, -1);
        return &instance;
    }
};

struct ItemRangedDisplayInfoMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
        };
        static constexpr DB2Meta instance(1270315, -1, 4, 4, 0x08C2EB5B, fields, -1);
        return &instance;
    }
};

struct ItemSearchNameMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[13] =
        {
            { FT_LONG, 1, true },
            { FT_STRING, 1, true },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
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
        static constexpr DB2Meta instance(1273408, -1, 13, 13, 0x3F17889F, fields, -1);
        return &instance;
    }
};

struct ItemSetMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[5] =
        {
            { FT_STRING, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_SHORT, 1, false },
            { FT_INT, 17, false },
        };
        static constexpr DB2Meta instance(1343609, -1, 5, 5, 0x4F7008BF, fields, -1);
        return &instance;
    }
};

struct ItemSetSpellMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_SHORT, 1, false },
            { FT_INT, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1314689, -1, 4, 3, 0xBF92BB46, fields, 3);
        return &instance;
    }
};

struct ItemSparseMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[64] =
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
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, true },
        };
        static constexpr DB2Meta instance(1572924, -1, 64, 64, 0xE80AABF8, fields, -1);
        return &instance;
    }
};

struct ItemSpecMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[6] =
        {
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
        };
        static constexpr DB2Meta instance(1135120, -1, 6, 6, 0x72013ECD, fields, 2);
        return &instance;
    }
};

struct ItemSpecOverrideMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_SHORT, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1134576, -1, 2, 1, 0xD621A05B, fields, 1);
        return &instance;
    }
};

struct ItemSubClassMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[11] =
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
        static constexpr DB2Meta instance(1261604, 2, 11, 11, 0xC096A1B1, fields, 3);
        return &instance;
    }
};

struct ItemSubClassMaskMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_STRING, 1, true },
            { FT_BYTE, 1, false },
            { FT_INT, 1, false },
        };
        static constexpr DB2Meta instance(1302852, -1, 3, 3, 0x42DC1188, fields, -1);
        return &instance;
    }
};

struct ItemVisualsMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 5, true },
        };
        static constexpr DB2Meta instance(1343605, -1, 3, 3, 0xC5D076A1, fields, -1);
        return &instance;
    }
};

struct ItemVisualsXEffectMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[6] =
        {
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3043873, -1, 6, 5, 0xE011E7C1, fields, 5);
        return &instance;
    }
};

struct ItemXBonusTreeMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_SHORT, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(987133, -1, 2, 1, 0xB088DCDC, fields, 1);
        return &instance;
    }
};

struct ItemXItemEffectMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3177687, -1, 2, 1, 0x96428A69, fields, 1);
        return &instance;
    }
};

struct JournalEncounterMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[12] =
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
        static constexpr DB2Meta instance(1240336, 3, 12, 12, 0x37948505, fields, -1);
        return &instance;
    }
};

struct JournalEncounterCreatureMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[8] =
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
        static constexpr DB2Meta instance(1301155, 2, 8, 8, 0x8D6F8786, fields, 3);
        return &instance;
    }
};

struct JournalEncounterItemMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[6] =
        {
            { FT_INT, 1, false },
            { FT_SHORT, 1, false },
            { FT_INT, 1, false },
            { FT_BYTE, 1, true },
            { FT_INT, 1, true },
            { FT_BYTE, 1, true },
        };
        static constexpr DB2Meta instance(1344467, 0, 6, 6, 0xDAC92896, fields, 1);
        return &instance;
    }
};

struct JournalEncounterSectionMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[15] =
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
        static constexpr DB2Meta instance(1134413, -1, 15, 15, 0xF617A4B5, fields, -1);
        return &instance;
    }
};

struct JournalEncounterXDifficultyMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1121901, -1, 2, 1, 0xF103C808, fields, 1);
        return &instance;
    }
};

struct JournalEncounterXMapLocMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[5] =
        {
            { FT_FLOAT, 2, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1722928, -1, 5, 4, 0xF9E973F0, fields, 4);
        return &instance;
    }
};

struct JournalInstanceMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[10] =
        {
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_SHORT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
            { FT_SHORT, 1, false },
        };
        static constexpr DB2Meta instance(1237438, -1, 10, 10, 0xCBFE4A96, fields, -1);
        return &instance;
    }
};

struct JournalItemXDifficultyMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1277744, -1, 2, 1, 0x19DEDAA3, fields, 1);
        return &instance;
    }
};

struct JournalSectionXDifficultyMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1121900, -1, 2, 1, 0x13D3283F, fields, 1);
        return &instance;
    }
};

struct JournalTierMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_STRING, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1349056, -1, 2, 2, 0x10E4DFC1, fields, -1);
        return &instance;
    }
};

struct JournalTierXInstanceMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
        };
        static constexpr DB2Meta instance(1285009, -1, 2, 2, 0xEF61F77B, fields, 0);
        return &instance;
    }
};

struct KeychainMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[1] =
        {
            { FT_BYTE, 32, false },
        };
        static constexpr DB2Meta instance(801693, -1, 1, 1, 0x683DDBCE, fields, -1);
        return &instance;
    }
};

struct KeystoneAffixMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1344761, 2, 4, 4, 0x6645021B, fields, -1);
        return &instance;
    }
};

struct LFGDungeonGroupMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_STRING, 1, true },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
        };
        static constexpr DB2Meta instance(1135058, -1, 4, 4, 0xFCCAFEFD, fields, -1);
        return &instance;
    }
};

struct LFGDungeonsMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[29] =
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
        static constexpr DB2Meta instance(1361033, -1, 29, 29, 0x11A21324, fields, -1);
        return &instance;
    }
};

struct LFGRoleRequirementMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_BYTE, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(982805, -1, 3, 2, 0x6112092C, fields, 2);
        return &instance;
    }
};

struct LabelXContentRestrictRuleSetMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(4281309, -1, 2, 1, 0x2FB539AB, fields, 1);
        return &instance;
    }
};

struct LanguageWordsMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_INT, 1, false },
        };
        static constexpr DB2Meta instance(984702, -1, 2, 2, 0x9CFC1981, fields, -1);
        return &instance;
    }
};

struct LanguagesMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_STRING, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1135325, -1, 4, 4, 0x409916EB, fields, -1);
        return &instance;
    }
};

struct LfgDungeonsGroupingMapMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1339818, -1, 3, 2, 0x3538AE33, fields, 2);
        return &instance;
    }
};

struct LightMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[5] =
        {
            { FT_FLOAT, 3, true },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_SHORT, 1, true },
            { FT_SHORT, 8, false },
        };
        static constexpr DB2Meta instance(1375579, -1, 5, 5, 0xAD1B2253, fields, -1);
        return &instance;
    }
};

struct LightDataMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[45] =
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
            { FT_FLOAT, 4, true },
            { FT_FLOAT, 4, true },
            { FT_FLOAT, 4, true },
        };
        static constexpr DB2Meta instance(1375580, -1, 45, 45, 0xD057E40C, fields, 0);
        return &instance;
    }
};

struct LightParamsMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[11] =
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
        static constexpr DB2Meta instance(1334669, -1, 11, 11, 0x9C29BEEF, fields, -1);
        return &instance;
    }
};

struct LightSkyboxMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1308501, -1, 4, 4, 0xF2269F12, fields, -1);
        return &instance;
    }
};

struct LightningMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[34] =
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
        static constexpr DB2Meta instance(2003383, -1, 34, 34, 0x09AF7B51, fields, -1);
        return &instance;
    }
};

struct LiquidMaterialMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, true },
        };
        static constexpr DB2Meta instance(1132538, -1, 2, 2, 0x2CFFEA40, fields, -1);
        return &instance;
    }
};

struct LiquidObjectMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[5] =
        {
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_SHORT, 1, true },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
        };
        static constexpr DB2Meta instance(1308058, -1, 5, 5, 0x6CAEB8A1, fields, -1);
        return &instance;
    }
};

struct LiquidTypeMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[21] =
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
        static constexpr DB2Meta instance(1371380, -1, 21, 21, 0xAFFFC9E0, fields, -1);
        return &instance;
    }
};

struct LiquidTypeXTextureMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_BYTE, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(2261065, -1, 4, 3, 0x5CC7EE1B, fields, 3);
        return &instance;
    }
};

struct LoadingScreenSkinMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[1] =
        {
            { FT_INT, 10, true },
        };
        static constexpr DB2Meta instance(2478235, -1, 1, 1, 0xE6C0E75D, fields, -1);
        return &instance;
    }
};

struct LoadingScreenTaxiSplinesMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[5] =
        {
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
            { FT_FLOAT, 10, true },
            { FT_FLOAT, 10, true },
        };
        static constexpr DB2Meta instance(1302239, -1, 5, 5, 0xD9F03CBC, fields, -1);
        return &instance;
    }
};

struct LoadingScreensMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[10] =
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
        static constexpr DB2Meta instance(1266541, -1, 10, 10, 0x112726F1, fields, -1);
        return &instance;
    }
};

struct LocaleMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[5] =
        {
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
        };
        static constexpr DB2Meta instance(801706, -1, 5, 5, 0x751D8F5F, fields, -1);
        return &instance;
    }
};

struct LocationMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_FLOAT, 3, true },
            { FT_FLOAT, 3, true },
        };
        static constexpr DB2Meta instance(801707, -1, 2, 2, 0xB0561808, fields, -1);
        return &instance;
    }
};

struct LockMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[5] =
        {
            { FT_INT, 1, true },
            { FT_INT, 8, true },
            { FT_SHORT, 8, false },
            { FT_BYTE, 8, false },
            { FT_BYTE, 8, false },
        };
        static constexpr DB2Meta instance(1343608, -1, 5, 5, 0xD359BBE0, fields, -1);
        return &instance;
    }
};

struct LockTypeMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[5] =
        {
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1284823, -1, 5, 5, 0x9C547CBC, fields, -1);
        return &instance;
    }
};

struct LookAtControllerMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[18] =
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
        static constexpr DB2Meta instance(1098785, -1, 18, 18, 0x01B2684C, fields, -1);
        return &instance;
    }
};

struct LoreTextMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3311370, -1, 3, 3, 0x886CC0CF, fields, -1);
        return &instance;
    }
};

struct LoreTextPublicMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[6] =
        {
            { FT_INT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3479846, 0, 6, 5, 0x54EE4E73, fields, 5);
        return &instance;
    }
};

struct MCRSlotXMCRCategoryMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3390955, -1, 2, 1, 0x9E7DBEAA, fields, 1);
        return &instance;
    }
};

struct MailTemplateMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[1] =
        {
            { FT_STRING, 1, true },
        };
        static constexpr DB2Meta instance(1240344, -1, 1, 1, 0x7C454945, fields, -1);
        return &instance;
    }
};

struct ManagedWorldStateMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[10] =
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
        static constexpr DB2Meta instance(1587159, -1, 10, 10, 0xE239E53B, fields, -1);
        return &instance;
    }
};

struct ManagedWorldStateBuffMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1587155, -1, 4, 3, 0xBA39FD6A, fields, 3);
        return &instance;
    }
};

struct ManagedWorldStateInputMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1587151, -1, 3, 3, 0x271DEDDF, fields, -1);
        return &instance;
    }
};

struct ManifestInterfaceActionIconMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[1] =
        {
            { FT_INT, 1, false },
        };
        static constexpr DB2Meta instance(1375803, 0, 1, 1, 0x6657BD0A, fields, -1);
        return &instance;
    }
};

struct ManifestInterfaceDataMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_STRING_NOT_LOCALIZED, 1, true },
        };
        static constexpr DB2Meta instance(1375801, -1, 2, 2, 0x13274651, fields, -1);
        return &instance;
    }
};

struct ManifestInterfaceItemIconMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[1] =
        {
            { FT_INT, 1, false },
        };
        static constexpr DB2Meta instance(1375804, 0, 1, 1, 0x6657BD0A, fields, -1);
        return &instance;
    }
};

struct ManifestInterfaceTOCDataMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[1] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
        };
        static constexpr DB2Meta instance(1267335, -1, 1, 1, 0x1FBF8808, fields, -1);
        return &instance;
    }
};

struct MapMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[23] =
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
            { FT_INT, 3, true },
        };
        static constexpr DB2Meta instance(1349477, -1, 23, 23, 0xAAA1F94E, fields, -1);
        return &instance;
    }
};

struct MapCelestialBodyMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_SHORT, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1597466, -1, 3, 2, 0x3B420F88, fields, 2);
        return &instance;
    }
};

struct MapChallengeModeMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[7] =
        {
            { FT_STRING, 1, true },
            { FT_INT, 1, false },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
            { FT_SHORT, 3, true },
        };
        static constexpr DB2Meta instance(801709, 1, 7, 7, 0xAAA9EAD7, fields, 2);
        return &instance;
    }
};

struct MapDifficultyMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[10] =
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
        static constexpr DB2Meta instance(1367868, -1, 10, 9, 0x43E2A417, fields, 9);
        return &instance;
    }
};

struct MapDifficultyXConditionMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_STRING, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1375435, -1, 4, 3, 0x08E872DB, fields, 3);
        return &instance;
    }
};

struct MapLoadingScreenMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[5] =
        {
            { FT_FLOAT, 2, true },
            { FT_FLOAT, 2, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1719707, -1, 5, 4, 0x2769A380, fields, 4);
        return &instance;
    }
};

struct MarketingPromotionsXLocaleMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[7] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(801710, -1, 7, 7, 0x71B7DCCF, fields, -1);
        return &instance;
    }
};

struct MaterialMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_BYTE, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
        };
        static constexpr DB2Meta instance(1294217, -1, 4, 4, 0x3D758F88, fields, -1);
        return &instance;
    }
};

struct MawPowerMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_INT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(2991315, 0, 3, 3, 0xE03BF02A, fields, 1);
        return &instance;
    }
};

struct MawPowerRarityMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(2997952, -1, 2, 2, 0x7B5245E6, fields, -1);
        return &instance;
    }
};

struct MinorTalentMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1347274, -1, 3, 2, 0x5ACB3BD8, fields, 2);
        return &instance;
    }
};

struct MissileTargetingMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[12] =
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
        static constexpr DB2Meta instance(1710117, -1, 12, 12, 0x057C9AA8, fields, -1);
        return &instance;
    }
};

struct ModelAnimCloakDampeningMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1465904, -1, 3, 2, 0x070144A6, fields, 2);
        return &instance;
    }
};

struct ModelFileDataMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_INT, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, false },
        };
        static constexpr DB2Meta instance(1337833, 0, 4, 4, 0xDFBC2A88, fields, 3);
        return &instance;
    }
};

struct ModelRibbonQualityMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1399953, -1, 2, 1, 0x682023A4, fields, 1);
        return &instance;
    }
};

struct ModifiedCraftingCategoryMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3386486, -1, 3, 3, 0xB867034E, fields, -1);
        return &instance;
    }
};

struct ModifiedCraftingReagentItemMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[6] =
        {
            { FT_STRING, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3386487, -1, 6, 6, 0x5F7E56EC, fields, -1);
        return &instance;
    }
};

struct ModifiedCraftingReagentSlotMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_STRING, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3386488, -1, 3, 3, 0x0A01A16B, fields, -1);
        return &instance;
    }
};

struct ModifiedCraftingSpellSlotMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3390956, -1, 4, 4, 0x4287A74D, fields, 0);
        return &instance;
    }
};

struct ModifiedReagentItemMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[1] =
        {
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3386490, -1, 1, 1, 0x106F4AE2, fields, -1);
        return &instance;
    }
};

struct ModifierTreeMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[7] =
        {
            { FT_INT, 1, false },
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1267645, -1, 7, 7, 0x71484C8E, fields, -1);
        return &instance;
    }
};

struct MountMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[13] =
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
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(921760, 3, 13, 13, 0x7A9CE26C, fields, -1);
        return &instance;
    }
};

struct MountCapabilityMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[8] =
        {
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_SHORT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1114709, -1, 8, 8, 0x4F0F6872, fields, -1);
        return &instance;
    }
};

struct MountEquipmentMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(2923510, -1, 4, 3, 0x2B5121CB, fields, 3);
        return &instance;
    }
};

struct MountTypeMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_INT, 1, true },
            { FT_INT, 24, true },
        };
        static constexpr DB2Meta instance(1114674, -1, 2, 2, 0x017C8C9F, fields, -1);
        return &instance;
    }
};

struct MountTypeXCapabilityMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
        };
        static constexpr DB2Meta instance(1114715, -1, 3, 3, 0xF438693D, fields, 0);
        return &instance;
    }
};

struct MountXDisplayMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1576117, -1, 3, 2, 0xC9D09486, fields, 2);
        return &instance;
    }
};

struct MountXSpellVisualKitPickerMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[5] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3989477, -1, 5, 4, 0x253A6DD0, fields, 4);
        return &instance;
    }
};

struct MovieMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
        };
        static constexpr DB2Meta instance(1332556, -1, 4, 4, 0xA3A2FAF5, fields, -1);
        return &instance;
    }
};

struct MovieFileDataMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[1] =
        {
            { FT_SHORT, 1, false },
        };
        static constexpr DB2Meta instance(1301154, -1, 1, 1, 0x1A7EB62A, fields, -1);
        return &instance;
    }
};

struct MovieVariationMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1339819, -1, 3, 2, 0xC0C6C93B, fields, 2);
        return &instance;
    }
};

struct MultiStatePropertiesMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[11] =
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
        static constexpr DB2Meta instance(1965592, -1, 11, 10, 0xBE0AE1EA, fields, 10);
        return &instance;
    }
};

struct MultiTransitionPropertiesMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[5] =
        {
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1965589, -1, 5, 5, 0x20221E9D, fields, -1);
        return &instance;
    }
};

struct MythicPlusSeasonMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(2400282, -1, 3, 3, 0x37FBB583, fields, -1);
        return &instance;
    }
};

struct MythicPlusSeasonRewardLevelsMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(2123783, -1, 4, 3, 0x2ABB5E15, fields, 3);
        return &instance;
    }
};

struct MythicPlusSeasonTrackedAffixMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[5] =
        {
            { FT_INT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(4067473, 0, 5, 4, 0x885D0924, fields, 4);
        return &instance;
    }
};

struct MythicPlusSeasonTrackedMapMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(4521365, -1, 2, 1, 0x5B26E537, fields, 1);
        return &instance;
    }
};

struct NPCModelItemSlotDisplayInfoMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_INT, 1, true },
            { FT_BYTE, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1340661, -1, 3, 2, 0x6345189C, fields, 2);
        return &instance;
    }
};

struct NPCSoundsMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[1] =
        {
            { FT_INT, 4, false },
        };
        static constexpr DB2Meta instance(1282621, -1, 1, 1, 0x775B157B, fields, -1);
        return &instance;
    }
};

struct NameGenMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
        };
        static constexpr DB2Meta instance(1122117, -1, 3, 3, 0xE43165A8, fields, -1);
        return &instance;
    }
};

struct NamesProfanityMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_BYTE, 1, true },
        };
        static constexpr DB2Meta instance(1117086, -1, 2, 2, 0xA3B1057A, fields, -1);
        return &instance;
    }
};

struct NamesReservedMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[1] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
        };
        static constexpr DB2Meta instance(1117085, -1, 1, 1, 0xA90C78EA, fields, -1);
        return &instance;
    }
};

struct NamesReservedLocaleMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_BYTE, 1, false },
        };
        static constexpr DB2Meta instance(1117087, -1, 2, 2, 0x4FC995DF, fields, -1);
        return &instance;
    }
};

struct NumTalentsAtLevelMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1953326, -1, 3, 3, 0xC31BC15A, fields, -1);
        return &instance;
    }
};

struct ObjectEffectMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[8] =
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
        static constexpr DB2Meta instance(1090577, -1, 8, 8, 0xB551B7D3, fields, -1);
        return &instance;
    }
};

struct ObjectEffectModifierMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_FLOAT, 4, true },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
        };
        static constexpr DB2Meta instance(1090575, -1, 4, 4, 0xBCDA92E8, fields, -1);
        return &instance;
    }
};

struct ObjectEffectPackageElemMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
        };
        static constexpr DB2Meta instance(1090578, -1, 3, 3, 0x4136FE8E, fields, -1);
        return &instance;
    }
};

struct OccluderMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[8] =
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
        static constexpr DB2Meta instance(2066958, -1, 8, 8, 0xD8AAC5E9, fields, -1);
        return &instance;
    }
};

struct OccluderCurtainMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[6] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3850529, -1, 6, 6, 0x4F3781D9, fields, -1);
        return &instance;
    }
};

struct OccluderLocationMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_FLOAT, 3, true },
            { FT_FLOAT, 3, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(2115224, -1, 3, 3, 0xD83C5AA5, fields, -1);
        return &instance;
    }
};

struct OccluderNodeMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(2066959, -1, 3, 3, 0x37234837, fields, -1);
        return &instance;
    }
};

struct OutlineEffectMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[6] =
        {
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_INT, 2, false },
        };
        static constexpr DB2Meta instance(1279739, -1, 6, 6, 0xB94FB0E3, fields, -1);
        return &instance;
    }
};

struct OverrideSpellDataMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_INT, 10, true },
            { FT_INT, 1, true },
            { FT_BYTE, 1, false },
        };
        static constexpr DB2Meta instance(1002186, -1, 3, 3, 0xDC04AC20, fields, -1);
        return &instance;
    }
};

struct PVPBracketTypesMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_BYTE, 1, true },
            { FT_INT, 4, false },
        };
        static constexpr DB2Meta instance(1394275, -1, 2, 2, 0x66C16B48, fields, -1);
        return &instance;
    }
};

struct PVPDifficultyMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1339820, -1, 4, 3, 0x6CAB5565, fields, 3);
        return &instance;
    }
};

struct PVPItemMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_INT, 1, true },
            { FT_BYTE, 1, false },
        };
        static constexpr DB2Meta instance(972287, -1, 2, 2, 0x95A06BE9, fields, -1);
        return &instance;
    }
};

struct PVPScoreboardCellInfoMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(2992916, -1, 3, 3, 0xC8E134F3, fields, 0);
        return &instance;
    }
};

struct PVPScoreboardColumnHeaderMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(2992917, -1, 3, 3, 0x268E3459, fields, -1);
        return &instance;
    }
};

struct PVPScoreboardLayoutMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(2992918, -1, 3, 3, 0x57EBF225, fields, 0);
        return &instance;
    }
};

struct PVPStatMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_STRING, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(2992919, 1, 3, 3, 0x33F25E0C, fields, 2);
        return &instance;
    }
};

struct PageTextMaterialMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[1] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
        };
        static constexpr DB2Meta instance(1271600, -1, 1, 1, 0xA0F05238, fields, -1);
        return &instance;
    }
};

struct PaperDollItemFrameMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_INT, 1, true },
            { FT_BYTE, 1, false },
        };
        static constexpr DB2Meta instance(1252503, -1, 3, 3, 0xA5067654, fields, -1);
        return &instance;
    }
};

struct ParagonReputationMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1581183, -1, 3, 3, 0xA78A1B30, fields, -1);
        return &instance;
    }
};

struct ParticleColorMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_INT, 3, true },
            { FT_INT, 3, true },
            { FT_INT, 3, true },
        };
        static constexpr DB2Meta instance(1284820, -1, 3, 3, 0xBD3FBADC, fields, -1);
        return &instance;
    }
};

struct ParticulateMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3396285, -1, 2, 2, 0x2203AD67, fields, -1);
        return &instance;
    }
};

struct ParticulateSoundMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[5] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(2053913, -1, 5, 5, 0x01C167D7, fields, 0);
        return &instance;
    }
};

struct PathMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[7] =
        {
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
        };
        static constexpr DB2Meta instance(801732, -1, 7, 7, 0xAB4D8ED6, fields, -1);
        return &instance;
    }
};

struct PathEdgeMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_INT, 2, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(2428705, -1, 2, 1, 0x3FAF3C23, fields, 1);
        return &instance;
    }
};

struct PathNodeMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(801733, -1, 3, 3, 0x37234837, fields, -1);
        return &instance;
    }
};

struct PathNodePropertyMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(801734, -1, 4, 4, 0xEC27351D, fields, -1);
        return &instance;
    }
};

struct PathPropertyMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(801735, -1, 3, 3, 0x635DCADD, fields, -1);
        return &instance;
    }
};

struct PhaseMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[1] =
        {
            { FT_SHORT, 1, false },
        };
        static constexpr DB2Meta instance(1348558, -1, 1, 1, 0x2BE7B349, fields, -1);
        return &instance;
    }
};

struct PhaseShiftZoneSoundsMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[13] =
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
        static constexpr DB2Meta instance(1267336, -1, 13, 13, 0x48F50F33, fields, -1);
        return &instance;
    }
};

struct PhaseXPhaseGroupMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_SHORT, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(987581, -1, 2, 1, 0xEC8D5E98, fields, 1);
        return &instance;
    }
};

struct PlayerConditionMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[80] =
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
            { FT_BYTE, 1, false },
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
        };
        static constexpr DB2Meta instance(1045411, -1, 80, 80, 0xCBD65EC2, fields, -1);
        return &instance;
    }
};

struct PositionerMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
            { FT_FLOAT, 1, true },
            { FT_BYTE, 1, false },
        };
        static constexpr DB2Meta instance(1251523, -1, 4, 4, 0xCBBBBD15, fields, -1);
        return &instance;
    }
};

struct PositionerStateMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[8] =
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
        static constexpr DB2Meta instance(1251506, -1, 8, 8, 0x0276AAB6, fields, -1);
        return &instance;
    }
};

struct PositionerStateEntryMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[11] =
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
        static constexpr DB2Meta instance(1251533, -1, 11, 11, 0x10BB0190, fields, -1);
        return &instance;
    }
};

struct PowerDisplayMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[5] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
        };
        static constexpr DB2Meta instance(1332557, -1, 5, 5, 0xE9B4E78C, fields, -1);
        return &instance;
    }
};

struct PowerTypeMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[13] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_INT, 1, false },
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
        static constexpr DB2Meta instance(1266022, 2, 13, 13, 0x5DEC7C8C, fields, -1);
        return &instance;
    }
};

struct PrestigeLevelInfoMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[5] =
        {
            { FT_STRING, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1275869, -1, 5, 5, 0xB4AE6313, fields, -1);
        return &instance;
    }
};

struct PvpBrawlMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[7] =
        {
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1585723, 3, 7, 7, 0x8D15C420, fields, -1);
        return &instance;
    }
};

struct PvpScalingEffectMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_FLOAT, 1, true },
        };
        static constexpr DB2Meta instance(1591100, -1, 3, 3, 0x63F0BE5D, fields, 1);
        return &instance;
    }
};

struct PvpScalingEffectTypeMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[1] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
        };
        static constexpr DB2Meta instance(1591098, -1, 1, 1, 0xB21E02AE, fields, -1);
        return &instance;
    }
};

struct PvpSeasonMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(2966426, -1, 3, 3, 0x8623DD7F, fields, -1);
        return &instance;
    }
};

struct PvpSeasonRewardLevelsMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(2470695, -1, 4, 3, 0x8BAE9DBE, fields, 3);
        return &instance;
    }
};

struct PvpTalentMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[9] =
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
        static constexpr DB2Meta instance(1302853, 1, 9, 9, 0x7150D804, fields, 2);
        return &instance;
    }
};

struct PvpTalentCategoryMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[1] =
        {
            { FT_BYTE, 1, false },
        };
        static constexpr DB2Meta instance(1891534, -1, 1, 1, 0x93410D30, fields, -1);
        return &instance;
    }
};

struct PvpTalentSlotUnlockMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_BYTE, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1950197, -1, 4, 4, 0xA08CCB66, fields, -1);
        return &instance;
    }
};

struct PvpTierMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[9] =
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
        static constexpr DB2Meta instance(2066871, 1, 9, 9, 0x80FD72F9, fields, 6);
        return &instance;
    }
};

struct QuestFactionRewardMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[1] =
        {
            { FT_SHORT, 10, true },
        };
        static constexpr DB2Meta instance(1282622, -1, 1, 1, 0xE6DC889F, fields, -1);
        return &instance;
    }
};

struct QuestFeedbackEffectMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[8] =
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
        static constexpr DB2Meta instance(1343388, -1, 8, 8, 0x4FF1C55A, fields, -1);
        return &instance;
    }
};

struct QuestInfoMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_STRING, 1, true },
            { FT_BYTE, 1, true },
            { FT_INT, 1, true },
            { FT_SHORT, 1, false },
        };
        static constexpr DB2Meta instance(1120960, -1, 4, 4, 0x8CE69EF5, fields, -1);
        return &instance;
    }
};

struct QuestLineMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(973430, -1, 4, 4, 0x8972E620, fields, -1);
        return &instance;
    }
};

struct QuestLineXQuestMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(973441, -1, 4, 4, 0xABFF78E8, fields, 0);
        return &instance;
    }
};

struct QuestMoneyRewardMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[1] =
        {
            { FT_INT, 10, false },
        };
        static constexpr DB2Meta instance(1139047, -1, 1, 1, 0xBFB6413C, fields, -1);
        return &instance;
    }
};

struct QuestObjectiveMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[8] =
        {
            { FT_STRING, 1, true },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1251960, -1, 8, 7, 0xBE46257D, fields, 7);
        return &instance;
    }
};

struct QuestPOIBlobMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[9] =
        {
            { FT_INT, 1, false },
            { FT_SHORT, 1, true },
            { FT_INT, 1, true },
            { FT_BYTE, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
        };
        static constexpr DB2Meta instance(1251882, 0, 9, 9, 0xBD552CA4, fields, 1);
        return &instance;
    }
};

struct QuestPOIPointMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[5] =
        {
            { FT_INT, 1, false },
            { FT_SHORT, 1, true },
            { FT_SHORT, 1, true },
            { FT_SHORT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1251883, 0, 5, 4, 0x38867756, fields, 4);
        return &instance;
    }
};

struct QuestPackageItemMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_SHORT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, false },
            { FT_BYTE, 1, false },
        };
        static constexpr DB2Meta instance(801743, -1, 4, 4, 0xA2C252CF, fields, -1);
        return &instance;
    }
};

struct QuestSortMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_STRING, 1, true },
            { FT_BYTE, 1, true },
        };
        static constexpr DB2Meta instance(1134585, -1, 2, 2, 0x1DDCABD9, fields, -1);
        return &instance;
    }
};

struct QuestV2Meta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[1] =
        {
            { FT_SHORT, 1, false },
        };
        static constexpr DB2Meta instance(1139443, -1, 1, 1, 0xBB71B2AE, fields, -1);
        return &instance;
    }
};

struct QuestV2CliTaskMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[24] =
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
        static constexpr DB2Meta instance(1028735, -1, 24, 24, 0x3F80A435, fields, -1);
        return &instance;
    }
};

struct QuestXGroupActivityMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_INT, 1, false },
            { FT_INT, 1, false },
        };
        static constexpr DB2Meta instance(1573634, -1, 2, 2, 0x6642C715, fields, -1);
        return &instance;
    }
};

struct QuestXPMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[1] =
        {
            { FT_SHORT, 10, false },
        };
        static constexpr DB2Meta instance(1139378, -1, 1, 1, 0xCC84B93E, fields, -1);
        return &instance;
    }
};

struct QuestXUIQuestDetailsThemeMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3448517, -1, 2, 2, 0x1AE2FA16, fields, -1);
        return &instance;
    }
};

struct QuestXUiWidgetSetMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3923421, -1, 2, 2, 0x2B4CA6A1, fields, -1);
        return &instance;
    }
};

struct RTPCMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[6] =
        {
            { FT_INT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3405439, 0, 6, 6, 0x32115955, fields, 5);
        return &instance;
    }
};

struct RTPCDataMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[5] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3405440, -1, 5, 5, 0xFB37E702, fields, 0);
        return &instance;
    }
};

struct RafActivityMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3081207, -1, 2, 2, 0x64C41FC9, fields, -1);
        return &instance;
    }
};

struct RandPropPointsMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[10] =
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
        static constexpr DB2Meta instance(1310245, -1, 10, 10, 0xC35A699D, fields, -1);
        return &instance;
    }
};

struct RecipeProgressionGroupEntryMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[6] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3671785, -1, 6, 6, 0x5481052D, fields, 0);
        return &instance;
    }
};

struct RelicSlotTierRequirementMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1716803, -1, 3, 3, 0xB83E9EBE, fields, -1);
        return &instance;
    }
};

struct RelicTalentMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[5] =
        {
            { FT_INT, 1, true },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1671256, -1, 5, 5, 0xE2CB2DDC, fields, -1);
        return &instance;
    }
};

struct RenownRewardsMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[18] =
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
        static constexpr DB2Meta instance(3743117, -1, 18, 18, 0xB1FF79CA, fields, 3);
        return &instance;
    }
};

struct ResearchBranchMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[6] =
        {
            { FT_STRING, 1, true },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1133729, -1, 6, 6, 0xAD4D7AD8, fields, -1);
        return &instance;
    }
};

struct ResearchFieldMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_STRING, 1, true },
            { FT_BYTE, 1, false },
        };
        static constexpr DB2Meta instance(1133711, -1, 2, 2, 0x3767B1BF, fields, -1);
        return &instance;
    }
};

struct ResearchProjectMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[8] =
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
        static constexpr DB2Meta instance(1134090, -1, 8, 8, 0x97798A9D, fields, -1);
        return &instance;
    }
};

struct ResearchSiteMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_STRING, 1, true },
            { FT_SHORT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, false },
        };
        static constexpr DB2Meta instance(1134091, -1, 4, 4, 0x7906CEDE, fields, -1);
        return &instance;
    }
};

struct ResistancesMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_STRING, 1, true },
            { FT_BYTE, 1, false },
            { FT_INT, 1, false },
        };
        static constexpr DB2Meta instance(1135072, -1, 3, 3, 0xCE78DB9B, fields, -1);
        return &instance;
    }
};

struct RewardPackMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[6] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, false },
            { FT_BYTE, 1, true },
            { FT_FLOAT, 1, true },
            { FT_BYTE, 1, false },
            { FT_INT, 1, false },
        };
        static constexpr DB2Meta instance(1307156, -1, 6, 6, 0x214B9595, fields, -1);
        return &instance;
    }
};

struct RewardPackXCurrencyTypeMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_INT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1307153, -1, 3, 2, 0x5692D477, fields, 2);
        return &instance;
    }
};

struct RewardPackXItemMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1307155, -1, 3, 2, 0x219E3F5D, fields, 2);
        return &instance;
    }
};

struct RibbonQualityMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[5] =
        {
            { FT_BYTE, 1, false },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_INT, 1, false },
        };
        static constexpr DB2Meta instance(1398908, -1, 5, 5, 0x8B3DD1B3, fields, -1);
        return &instance;
    }
};

struct RopeEffectMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[9] =
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
        static constexpr DB2Meta instance(3256786, -1, 9, 9, 0xC049D78F, fields, -1);
        return &instance;
    }
};

struct RuneforgeLegendaryAbilityMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[11] =
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
        static constexpr DB2Meta instance(3500241, 1, 11, 11, 0x35605374, fields, -1);
        return &instance;
    }
};

struct SDReplacementModelMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[1] =
        {
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1712172, -1, 1, 1, 0x9415B157, fields, -1);
        return &instance;
    }
};

struct SSAOSettingsMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[7] =
        {
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
        };
        static constexpr DB2Meta instance(2056369, -1, 7, 7, 0xE18F5D96, fields, -1);
        return &instance;
    }
};

struct ScenarioMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[5] =
        {
            { FT_STRING, 1, true },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, false },
        };
        static constexpr DB2Meta instance(1139062, -1, 5, 5, 0x6CEEC7F6, fields, -1);
        return &instance;
    }
};

struct ScenarioEventEntryMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_BYTE, 1, false },
            { FT_INT, 1, false },
        };
        static constexpr DB2Meta instance(1141065, -1, 2, 2, 0x8643ED17, fields, -1);
        return &instance;
    }
};

struct ScenarioStepMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[11] =
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
        static constexpr DB2Meta instance(1132761, -1, 11, 11, 0x12DAED63, fields, 2);
        return &instance;
    }
};

struct SceneScriptMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(801754, -1, 3, 3, 0xF24D5AEA, fields, -1);
        return &instance;
    }
};

struct SceneScriptGlobalTextMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_STRING_NOT_LOCALIZED, 1, true },
        };
        static constexpr DB2Meta instance(1758036, -1, 2, 2, 0x8239EFCD, fields, -1);
        return &instance;
    }
};

struct SceneScriptPackageMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(801755, -1, 2, 2, 0x5642AF7C, fields, -1);
        return &instance;
    }
};

struct SceneScriptPackageMemberMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(801756, -1, 4, 4, 0xD2EA425C, fields, 0);
        return &instance;
    }
};

struct SceneScriptTextMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_STRING_NOT_LOCALIZED, 1, true },
        };
        static constexpr DB2Meta instance(1758037, -1, 2, 2, 0x8239EFCD, fields, -1);
        return &instance;
    }
};

struct ScheduledIntervalMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[5] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1327082, -1, 5, 5, 0xBD3FEB04, fields, -1);
        return &instance;
    }
};

struct ScreenEffectMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[12] =
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
        static constexpr DB2Meta instance(1302849, -1, 12, 12, 0x49CD4814, fields, -1);
        return &instance;
    }
};

struct ScreenEffectTypeMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[1] =
        {
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3063174, -1, 1, 1, 0x807C06A3, fields, -1);
        return &instance;
    }
};

struct ScreenLocationMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[1] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
        };
        static constexpr DB2Meta instance(1279416, -1, 1, 1, 0x8730B3B5, fields, -1);
        return &instance;
    }
};

struct SeamlessSiteMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[1] =
        {
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1328719, -1, 1, 1, 0x60B3CFFF, fields, 0);
        return &instance;
    }
};

struct ServerMessagesMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[1] =
        {
            { FT_STRING, 1, true },
        };
        static constexpr DB2Meta instance(1301141, -1, 1, 1, 0xBF527CAF, fields, -1);
        return &instance;
    }
};

struct ShadowyEffectMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[13] =
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
        static constexpr DB2Meta instance(1239844, -1, 13, 13, 0x65EF6B87, fields, -1);
        return &instance;
    }
};

struct SiegeablePropertiesMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_INT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, false },
        };
        static constexpr DB2Meta instance(1954391, -1, 4, 4, 0xD237D615, fields, -1);
        return &instance;
    }
};

struct SkillLineMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[13] =
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
        static constexpr DB2Meta instance(1240935, 5, 13, 13, 0x83E286E5, fields, -1);
        return &instance;
    }
};

struct SkillLineAbilityMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[15] =
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
            { FT_INT, 1, true },
            { FT_BYTE, 1, true },
            { FT_SHORT, 1, true },
            { FT_SHORT, 1, true },
            { FT_SHORT, 1, true },
        };
        static constexpr DB2Meta instance(1266278, 1, 15, 15, 0x0FCCC8B4, fields, 2);
        return &instance;
    }
};

struct SkillRaceClassInfoMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[7] =
        {
            { FT_LONG, 1, true },
            { FT_SHORT, 1, true },
            { FT_INT, 1, true },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, true },
            { FT_SHORT, 1, true },
        };
        static constexpr DB2Meta instance(1240406, -1, 7, 7, 0x0271228C, fields, 1);
        return &instance;
    }
};

struct SkySceneXPlayerConditionMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3581893, -1, 2, 1, 0x62B60407, fields, 1);
        return &instance;
    }
};

struct SoulbindMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[6] =
        {
            { FT_STRING, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3488583, -1, 6, 6, 0x9031600B, fields, -1);
        return &instance;
    }
};

struct SoulbindConduitMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3594380, -1, 4, 4, 0xD87C19D7, fields, -1);
        return &instance;
    }
};

struct SoulbindConduitEnhancedSocketMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(4069554, -1, 2, 2, 0xC5F12335, fields, -1);
        return &instance;
    }
};

struct SoulbindConduitItemMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3604984, -1, 2, 2, 0x0378426E, fields, -1);
        return &instance;
    }
};

struct SoulbindConduitRankMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3620681, -1, 4, 3, 0x197CCA07, fields, 3);
        return &instance;
    }
};

struct SoulbindConduitRankPropertiesMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3858895, -1, 3, 3, 0x17D85084, fields, -1);
        return &instance;
    }
};

struct SoulbindUIDisplayInfoMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[8] =
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
        static constexpr DB2Meta instance(3490472, -1, 8, 8, 0xCED83DDB, fields, -1);
        return &instance;
    }
};

struct SoundAmbienceMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[7] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 2, false },
            { FT_INT, 2, false },
            { FT_INT, 2, false },
            { FT_INT, 2, false },
        };
        static constexpr DB2Meta instance(1310628, -1, 7, 7, 0xCB856968, fields, -1);
        return &instance;
    }
};

struct SoundAmbienceFlavorMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1267065, -1, 3, 2, 0x36D1007C, fields, 2);
        return &instance;
    }
};

struct SoundBusMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[8] =
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
        static constexpr DB2Meta instance(1310246, 0, 8, 7, 0x7854CF39, fields, 7);
        return &instance;
    }
};

struct SoundBusOverrideMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[7] =
        {
            { FT_INT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, false },
            { FT_BYTE, 1, false },
            { FT_FLOAT, 1, true },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
        };
        static constexpr DB2Meta instance(1598732, 0, 7, 7, 0xF5BD8202, fields, 1);
        return &instance;
    }
};

struct SoundEmitterPillPointsMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_FLOAT, 3, true },
            { FT_SHORT, 1, false },
        };
        static constexpr DB2Meta instance(1092317, -1, 2, 2, 0xFB1F432A, fields, 1);
        return &instance;
    }
};

struct SoundEmittersMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[12] =
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
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1092316, 3, 12, 11, 0xA4A5BBC4, fields, 11);
        return &instance;
    }
};

struct SoundEnvelopeMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[7] =
        {
            { FT_INT, 1, true },
            { FT_BYTE, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
        };
        static constexpr DB2Meta instance(1693131, -1, 7, 7, 0x7C68FF4A, fields, 0);
        return &instance;
    }
};

struct SoundFilterMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[1] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
        };
        static constexpr DB2Meta instance(1271601, -1, 1, 1, 0xB21E02AE, fields, -1);
        return &instance;
    }
};

struct SoundFilterElemMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_FLOAT, 9, true },
            { FT_BYTE, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1267066, -1, 3, 2, 0xA934E155, fields, 2);
        return &instance;
    }
};

struct SoundKitMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[15] =
        {
            { FT_INT, 1, true },
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
        static constexpr DB2Meta instance(1237434, -1, 15, 15, 0x3FE1D132, fields, -1);
        return &instance;
    }
};

struct SoundKitAdvancedMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[56] =
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
        static constexpr DB2Meta instance(1237436, -1, 56, 56, 0x864490D3, fields, -1);
        return &instance;
    }
};

struct SoundKitChildMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_INT, 1, false },
            { FT_INT, 1, false },
        };
        static constexpr DB2Meta instance(1307289, -1, 2, 2, 0x102526D8, fields, 1);
        return &instance;
    }
};

struct SoundKitEntryMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_INT, 1, false },
            { FT_INT, 1, true },
            { FT_BYTE, 1, false },
            { FT_FLOAT, 1, true },
        };
        static constexpr DB2Meta instance(1237435, -1, 4, 4, 0x962B1DCC, fields, 0);
        return &instance;
    }
};

struct SoundKitFallbackMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_INT, 1, false },
            { FT_INT, 1, false },
        };
        static constexpr DB2Meta instance(1307288, -1, 2, 2, 0x006A5AA3, fields, -1);
        return &instance;
    }
};

struct SoundOverrideMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[5] =
        {
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
        };
        static constexpr DB2Meta instance(1266542, -1, 5, 5, 0x61F508F8, fields, -1);
        return &instance;
    }
};

struct SoundParameterMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[5] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3405441, -1, 5, 5, 0xA84DAECD, fields, -1);
        return &instance;
    }
};

struct SoundProviderPreferencesMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[23] =
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
        static constexpr DB2Meta instance(1279417, -1, 23, 23, 0x06599A4D, fields, -1);
        return &instance;
    }
};

struct SourceInfoMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_STRING, 1, true },
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1313612, -1, 4, 3, 0xF32B81DC, fields, 3);
        return &instance;
    }
};

struct SpamMessagesMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[1] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
        };
        static constexpr DB2Meta instance(1117088, -1, 1, 1, 0xEF771036, fields, -1);
        return &instance;
    }
};

struct SpecSetMemberMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(2057624, -1, 2, 1, 0x48C154DC, fields, 1);
        return &instance;
    }
};

struct SpecializationSpellsMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[6] =
        {
            { FT_STRING, 1, true },
            { FT_INT, 1, false },
            { FT_SHORT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_BYTE, 1, false },
        };
        static constexpr DB2Meta instance(1240335, 1, 6, 6, 0xA524AD21, fields, 2);
        return &instance;
    }
};

struct SpecializationSpellsDisplayMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_SHORT, 1, false },
            { FT_INT, 6, false },
        };
        static constexpr DB2Meta instance(2067238, -1, 2, 2, 0x2E79E9B0, fields, 0);
        return &instance;
    }
};

struct SpellMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
        };
        static constexpr DB2Meta instance(1140089, -1, 3, 3, 0xE2395468, fields, -1);
        return &instance;
    }
};

struct SpellActionBarPrefMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_INT, 1, true },
            { FT_SHORT, 1, false },
        };
        static constexpr DB2Meta instance(1019373, -1, 2, 2, 0x5CB6468B, fields, -1);
        return &instance;
    }
};

struct SpellActivationOverlayMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[10] =
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
        static constexpr DB2Meta instance(1261603, -1, 10, 10, 0x67CA82D4, fields, -1);
        return &instance;
    }
};

struct SpellAuraOptionsMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[8] =
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
        static constexpr DB2Meta instance(1139952, -1, 8, 7, 0x584EB0C9, fields, 7);
        return &instance;
    }
};

struct SpellAuraRestrictionsMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[10] =
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
        static constexpr DB2Meta instance(981566, -1, 10, 9, 0x98916922, fields, 9);
        return &instance;
    }
};

struct SpellAuraVisXChrSpecMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_SHORT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1280615, -1, 2, 1, 0x6402EE2B, fields, 1);
        return &instance;
    }
};

struct SpellAuraVisibilityMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_INT, 1, false },
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1280616, 0, 4, 3, 0x398764D3, fields, 3);
        return &instance;
    }
};

struct SpellCastTimesMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1134089, -1, 2, 2, 0x3EC041D4, fields, -1);
        return &instance;
    }
};

struct SpellCastingRequirementsMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[7] =
        {
            { FT_INT, 1, true },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, true },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
        };
        static constexpr DB2Meta instance(1002166, -1, 7, 7, 0xA1320F30, fields, -1);
        return &instance;
    }
};

struct SpellCategoriesMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[9] =
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
        static constexpr DB2Meta instance(1139939, -1, 9, 8, 0xE1D0C5AC, fields, 8);
        return &instance;
    }
};

struct SpellCategoryMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[6] =
        {
            { FT_STRING, 1, true },
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1280619, -1, 6, 6, 0x8C8A2CFC, fields, -1);
        return &instance;
    }
};

struct SpellChainEffectsMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[60] =
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
        static constexpr DB2Meta instance(1343310, -1, 60, 60, 0xD76BE290, fields, -1);
        return &instance;
    }
};

struct SpellClassOptionsMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 4, true },
        };
        static constexpr DB2Meta instance(979663, -1, 4, 4, 0x427E17F9, fields, -1);
        return &instance;
    }
};

struct SpellClutterAreaEffectCountsMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(2428696, -1, 3, 3, 0x362D8889, fields, -1);
        return &instance;
    }
};

struct SpellClutterFrameRatesMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_INT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
        };
        static constexpr DB2Meta instance(2428707, -1, 3, 3, 0x722797C7, fields, -1);
        return &instance;
    }
};

struct SpellClutterImpactModelCountsMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(2428708, -1, 3, 3, 0x362D8889, fields, -1);
        return &instance;
    }
};

struct SpellClutterKitDistancesMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_INT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
        };
        static constexpr DB2Meta instance(2428697, -1, 3, 3, 0x38C53911, fields, -1);
        return &instance;
    }
};

struct SpellClutterMissileDistMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_INT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
        };
        static constexpr DB2Meta instance(2428733, -1, 3, 3, 0x38C53911, fields, -1);
        return &instance;
    }
};

struct SpellClutterWeaponTrailDistMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_INT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
        };
        static constexpr DB2Meta instance(2428698, -1, 3, 3, 0x38C53911, fields, -1);
        return &instance;
    }
};

struct SpellCooldownsMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[5] =
        {
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1139924, -1, 5, 4, 0xDD35D72E, fields, 4);
        return &instance;
    }
};

struct SpellDescriptionVariablesMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[1] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
        };
        static constexpr DB2Meta instance(1140004, -1, 1, 1, 0x3846B8C4, fields, -1);
        return &instance;
    }
};

struct SpellDispelTypeMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_STRING, 1, true },
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
        };
        static constexpr DB2Meta instance(1137829, -1, 4, 4, 0xD31E57F3, fields, -1);
        return &instance;
    }
};

struct SpellDurationMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1137828, -1, 2, 2, 0xC1591711, fields, -1);
        return &instance;
    }
};

struct SpellEffectMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[29] =
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
        static constexpr DB2Meta instance(1140088, -1, 29, 28, 0x0ADBA46F, fields, 28);
        return &instance;
    }
};

struct SpellEffectAutoDescriptionMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[9] =
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
        static constexpr DB2Meta instance(1888495, -1, 9, 9, 0x6DCEA74D, fields, -1);
        return &instance;
    }
};

struct SpellEffectEmissionMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_SHORT, 1, true },
            { FT_BYTE, 1, true },
        };
        static constexpr DB2Meta instance(1310248, -1, 4, 4, 0x55D6415D, fields, -1);
        return &instance;
    }
};

struct SpellEquippedItemsMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_INT, 1, true },
            { FT_BYTE, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1140011, -1, 4, 4, 0x9E98F8F8, fields, -1);
        return &instance;
    }
};

struct SpellFlyoutMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[6] =
        {
            { FT_LONG, 1, true },
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1146819, -1, 6, 6, 0x0F34BE71, fields, -1);
        return &instance;
    }
};

struct SpellFlyoutItemMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_INT, 1, true },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1134085, -1, 3, 2, 0x5977DEAC, fields, 2);
        return &instance;
    }
};

struct SpellFocusObjectMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[1] =
        {
            { FT_STRING, 1, true },
        };
        static constexpr DB2Meta instance(1280620, -1, 1, 1, 0xB0DD8F60, fields, -1);
        return &instance;
    }
};

struct SpellInterruptsMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[5] =
        {
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, true },
            { FT_INT, 2, true },
            { FT_INT, 2, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1139906, -1, 5, 4, 0x15BFA3E0, fields, 4);
        return &instance;
    }
};

struct SpellItemEnchantmentMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[22] =
        {
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
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
        static constexpr DB2Meta instance(1362771, -1, 22, 22, 0x3C42D738, fields, -1);
        return &instance;
    }
};

struct SpellItemEnchantmentConditionMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[6] =
        {
            { FT_BYTE, 5, false },
            { FT_INT, 5, false },
            { FT_BYTE, 5, false },
            { FT_BYTE, 5, false },
            { FT_BYTE, 5, false },
            { FT_BYTE, 5, false },
        };
        static constexpr DB2Meta instance(1121834, -1, 6, 6, 0xC1340327, fields, -1);
        return &instance;
    }
};

struct SpellKeyboundOverrideMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_BYTE, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1127327, -1, 4, 4, 0x3E33E322, fields, -1);
        return &instance;
    }
};

struct SpellLabelMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_INT, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1347275, -1, 2, 1, 0x8FB85089, fields, 1);
        return &instance;
    }
};

struct SpellLearnSpellMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1001907, -1, 3, 3, 0x6E612037, fields, -1);
        return &instance;
    }
};

struct SpellLevelsMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[6] =
        {
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, true },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1140079, -1, 6, 5, 0x734BBB2C, fields, 5);
        return &instance;
    }
};

struct SpellMechanicMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[1] =
        {
            { FT_STRING, 1, true },
        };
        static constexpr DB2Meta instance(1014438, -1, 1, 1, 0x4E0C4A43, fields, -1);
        return &instance;
    }
};

struct SpellMiscMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[16] =
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
        static constexpr DB2Meta instance(1003144, -1, 16, 15, 0x22C4626A, fields, 15);
        return &instance;
    }
};

struct SpellMissileMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[15] =
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
        static constexpr DB2Meta instance(897956, -1, 15, 15, 0x8BE6A845, fields, -1);
        return &instance;
    }
};

struct SpellMissileMotionMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
        };
        static constexpr DB2Meta instance(897955, -1, 4, 4, 0xE98CFA44, fields, -1);
        return &instance;
    }
};

struct SpellNameMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[1] =
        {
            { FT_STRING, 1, true },
        };
        static constexpr DB2Meta instance(1990283, -1, 1, 1, 0xB0DD8F60, fields, -1);
        return &instance;
    }
};

struct SpellOverrideNameMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(2618823, -1, 3, 3, 0xC38F6613, fields, -1);
        return &instance;
    }
};

struct SpellPowerMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[14] =
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
        static constexpr DB2Meta instance(982806, 0, 14, 13, 0xD61F566E, fields, 13);
        return &instance;
    }
};

struct SpellPowerDifficultyMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
        };
        static constexpr DB2Meta instance(982804, -1, 2, 2, 0x831780E9, fields, -1);
        return &instance;
    }
};

struct SpellProceduralEffectMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_BYTE, 1, true },
            { FT_FLOAT, 4, true },
        };
        static constexpr DB2Meta instance(1140477, -1, 2, 2, 0x860F778C, fields, -1);
        return &instance;
    }
};

struct SpellProcsPerMinuteMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_FLOAT, 1, true },
            { FT_BYTE, 1, false },
        };
        static constexpr DB2Meta instance(1133526, -1, 2, 2, 0x8398D285, fields, -1);
        return &instance;
    }
};

struct SpellProcsPerMinuteModMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1133525, -1, 4, 3, 0x2C6FC571, fields, 3);
        return &instance;
    }
};

struct SpellRadiusMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
        };
        static constexpr DB2Meta instance(1134584, -1, 4, 4, 0x84246EAE, fields, -1);
        return &instance;
    }
};

struct SpellRangeMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[5] =
        {
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_BYTE, 1, false },
            { FT_FLOAT, 2, true },
            { FT_FLOAT, 2, true },
        };
        static constexpr DB2Meta instance(1146820, -1, 5, 5, 0x1A9D89B3, fields, -1);
        return &instance;
    }
};

struct SpellReagentsMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_INT, 1, true },
            { FT_INT, 8, true },
            { FT_SHORT, 8, true },
        };
        static constexpr DB2Meta instance(841946, -1, 3, 3, 0xF0E58683, fields, -1);
        return &instance;
    }
};

struct SpellReagentsCurrencyMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_INT, 1, true },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
        };
        static constexpr DB2Meta instance(1135239, -1, 3, 3, 0xA7C3638C, fields, 0);
        return &instance;
    }
};

struct SpellScalingMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_SHORT, 1, true },
        };
        static constexpr DB2Meta instance(1139940, -1, 4, 4, 0xDF5A7562, fields, -1);
        return &instance;
    }
};

struct SpellScriptMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[5] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3055899, -1, 5, 5, 0x7E8B242D, fields, -1);
        return &instance;
    }
};

struct SpellScriptTextMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[5] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3055901, 1, 5, 4, 0x035224C6, fields, 4);
        return &instance;
    }
};

struct SpellShapeshiftMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_INT, 1, true },
            { FT_BYTE, 1, true },
            { FT_INT, 2, true },
            { FT_INT, 2, true },
        };
        static constexpr DB2Meta instance(1139929, -1, 4, 4, 0xCBF64431, fields, -1);
        return &instance;
    }
};

struct SpellShapeshiftFormMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[10] =
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
        static constexpr DB2Meta instance(1280618, -1, 10, 10, 0xBFE8FFA1, fields, -1);
        return &instance;
    }
};

struct SpellSpecialUnitEffectMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_SHORT, 1, false },
            { FT_INT, 1, false },
        };
        static constexpr DB2Meta instance(1268903, -1, 2, 2, 0x7739B9C5, fields, -1);
        return &instance;
    }
};

struct SpellTargetRestrictionsMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[8] =
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
        static constexpr DB2Meta instance(1139993, -1, 8, 7, 0xAC82CF4B, fields, 7);
        return &instance;
    }
};

struct SpellTotemsMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_INT, 1, true },
            { FT_SHORT, 2, false },
            { FT_INT, 2, true },
        };
        static constexpr DB2Meta instance(1002162, -1, 3, 3, 0x230DD39D, fields, -1);
        return &instance;
    }
};

struct SpellVisualMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[16] =
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
        static constexpr DB2Meta instance(897952, -1, 16, 16, 0x536575A0, fields, -1);
        return &instance;
    }
};

struct SpellVisualAnimMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_SHORT, 1, false },
        };
        static constexpr DB2Meta instance(1140479, -1, 3, 3, 0x0D10BE24, fields, -1);
        return &instance;
    }
};

struct SpellVisualColorEffectMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[11] =
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
        static constexpr DB2Meta instance(1094006, -1, 11, 11, 0xBBAF68B7, fields, -1);
        return &instance;
    }
};

struct SpellVisualEffectNameMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[15] =
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
        static constexpr DB2Meta instance(897948, -1, 15, 15, 0xD10DE7C6, fields, -1);
        return &instance;
    }
};

struct SpellVisualEventMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[9] =
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
        static constexpr DB2Meta instance(1685317, -1, 9, 8, 0x54DB405C, fields, 8);
        return &instance;
    }
};

struct SpellVisualKitMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[5] =
        {
            { FT_BYTE, 1, true },
            { FT_INT, 1, true },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_INT, 2, true },
        };
        static constexpr DB2Meta instance(897949, -1, 5, 5, 0xA2B96B8A, fields, -1);
        return &instance;
    }
};

struct SpellVisualKitAreaModelMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[6] =
        {
            { FT_INT, 1, true },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
        };
        static constexpr DB2Meta instance(897951, -1, 6, 6, 0xFBA6277D, fields, -1);
        return &instance;
    }
};

struct SpellVisualKitEffectMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1140480, -1, 3, 2, 0x5D2E222A, fields, 2);
        return &instance;
    }
};

struct SpellVisualKitModelAttachMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[22] =
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
        static constexpr DB2Meta instance(897953, -1, 22, 21, 0x58DE8C95, fields, 21);
        return &instance;
    }
};

struct SpellVisualKitPickerMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3989478, -1, 2, 2, 0xE7A454BF, fields, -1);
        return &instance;
    }
};

struct SpellVisualKitPickerEntryMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_INT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3989479, -1, 3, 2, 0x6C80416B, fields, 2);
        return &instance;
    }
};

struct SpellVisualMissileMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[18] =
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
        static constexpr DB2Meta instance(897954, 2, 18, 17, 0x11D06D97, fields, 17);
        return &instance;
    }
};

struct SpellVisualScreenEffectMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3607312, -1, 2, 2, 0xDBF829D1, fields, -1);
        return &instance;
    }
};

struct SpellXDescriptionVariablesMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1724949, -1, 2, 2, 0x9A9D6850, fields, -1);
        return &instance;
    }
};

struct SpellXSpellVisualMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[12] =
        {
            { FT_INT, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, false },
            { FT_FLOAT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_SHORT, 1, false },
            { FT_INT, 1, false },
            { FT_SHORT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1101657, 0, 12, 11, 0x4C5EA5C5, fields, 11);
        return &instance;
    }
};

struct StartupFilesMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1604265, -1, 3, 3, 0x0DB4CD60, fields, -1);
        return &instance;
    }
};

struct Startup_StringsMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_STRING, 1, true },
        };
        static constexpr DB2Meta instance(1375805, -1, 2, 2, 0xD81204F9, fields, -1);
        return &instance;
    }
};

struct StationeryMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_INT, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 2, true },
        };
        static constexpr DB2Meta instance(1140758, -1, 3, 3, 0xC47D5B55, fields, -1);
        return &instance;
    }
};

struct SummonPropertiesMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[5] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 2, true },
        };
        static constexpr DB2Meta instance(1345276, -1, 5, 5, 0x927C6DBA, fields, -1);
        return &instance;
    }
};

struct TactKeyMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[1] =
        {
            { FT_BYTE, 16, false },
        };
        static constexpr DB2Meta instance(1302850, -1, 1, 1, 0xD3F61A9E, fields, -1);
        return &instance;
    }
};

struct TactKeyLookupMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[1] =
        {
            { FT_BYTE, 8, false },
        };
        static constexpr DB2Meta instance(1302851, -1, 1, 1, 0xB9312C4E, fields, -1);
        return &instance;
    }
};

struct TalentMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[9] =
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
        static constexpr DB2Meta instance(1369062, -1, 9, 9, 0x75423537, fields, -1);
        return &instance;
    }
};

struct TaxiNodesMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[15] =
        {
            { FT_STRING, 1, true },
            { FT_FLOAT, 3, true },
            { FT_FLOAT, 2, true },
            { FT_FLOAT, 2, true },
            { FT_INT, 1, false },
            { FT_SHORT, 1, false },
            { FT_INT, 1, true },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 2, true },
        };
        static constexpr DB2Meta instance(1068100, 4, 15, 15, 0x3F7CC8B2, fields, 5);
        return &instance;
    }
};

struct TaxiPathMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_INT, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_INT, 1, false },
        };
        static constexpr DB2Meta instance(1067802, 0, 4, 4, 0x9B67699C, fields, 1);
        return &instance;
    }
};

struct TaxiPathNodeMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[9] =
        {
            { FT_FLOAT, 3, true },
            { FT_INT, 1, false },
            { FT_SHORT, 1, false },
            { FT_INT, 1, true },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1000437, 1, 9, 9, 0xA20FF622, fields, 2);
        return &instance;
    }
};

struct TerrainColorGradingRampMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3501705, -1, 4, 4, 0x02B6E85D, fields, -1);
        return &instance;
    }
};

struct TerrainMaterialMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1307290, -1, 3, 3, 0x499A04BC, fields, -1);
        return &instance;
    }
};

struct TerrainTypeMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[5] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
        };
        static constexpr DB2Meta instance(1310249, -1, 5, 5, 0xD533642E, fields, -1);
        return &instance;
    }
};

struct TerrainTypeSoundsMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[1] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
        };
        static constexpr DB2Meta instance(1284822, -1, 1, 1, 0x5462668A, fields, -1);
        return &instance;
    }
};

struct TextureBlendSetMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[11] =
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
        static constexpr DB2Meta instance(1328721, -1, 11, 11, 0x420979A8, fields, -1);
        return &instance;
    }
};

struct TextureFileDataMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_INT, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(982459, 0, 3, 3, 0x1C9A021C, fields, 2);
        return &instance;
    }
};

struct TierTransitionMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_FLOAT, 1, true },
        };
        static constexpr DB2Meta instance(3076928, -1, 4, 4, 0xE71F230A, fields, -1);
        return &instance;
    }
};

struct TotemCategoryMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_STRING, 1, true },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1134586, -1, 3, 3, 0x81755C9C, fields, -1);
        return &instance;
    }
};

struct ToyMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[5] =
        {
            { FT_STRING, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, true },
        };
        static constexpr DB2Meta instance(988200, 1, 5, 5, 0xED0030EE, fields, -1);
        return &instance;
    }
};

struct TradeSkillCategoryMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[6] =
        {
            { FT_STRING, 1, true },
            { FT_STRING, 1, true },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, true },
            { FT_BYTE, 1, false },
        };
        static constexpr DB2Meta instance(1301101, -1, 6, 6, 0x3C05077F, fields, -1);
        return &instance;
    }
};

struct TradeSkillItemMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[1] =
        {
            { FT_SHORT, 1, false },
        };
        static constexpr DB2Meta instance(1329070, -1, 1, 1, 0xD6BD8871, fields, -1);
        return &instance;
    }
};

struct TransformMatrixMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[5] =
        {
            { FT_FLOAT, 3, true },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
        };
        static constexpr DB2Meta instance(1338702, -1, 5, 5, 0x92BCCC4C, fields, -1);
        return &instance;
    }
};

struct TransmogDefaultLevelMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_BYTE, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(2399695, -1, 2, 2, 0x95FD2CA2, fields, -1);
        return &instance;
    }
};

struct TransmogHolidayMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[1] =
        {
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1589454, -1, 1, 1, 0xE3B900BB, fields, -1);
        return &instance;
    }
};

struct TransmogIllusionMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[5] =
        {
            { FT_INT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3580450, 0, 5, 5, 0x3DDD0672, fields, -1);
        return &instance;
    }
};

struct TransmogSetMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[13] =
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
        static constexpr DB2Meta instance(1376213, 1, 13, 13, 0x5B0E178F, fields, 7);
        return &instance;
    }
};

struct TransmogSetGroupMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[1] =
        {
            { FT_STRING, 1, true },
        };
        static constexpr DB2Meta instance(1576116, -1, 1, 1, 0xE59553DF, fields, -1);
        return &instance;
    }
};

struct TransmogSetItemMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1376212, -1, 3, 3, 0x7273E272, fields, 0);
        return &instance;
    }
};

struct TransportAnimationMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_FLOAT, 3, true },
            { FT_BYTE, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1140686, -1, 4, 3, 0x5C89E4E6, fields, 3);
        return &instance;
    }
};

struct TransportPhysicsMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[10] =
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
        static constexpr DB2Meta instance(1121973, -1, 10, 10, 0x3BE86156, fields, -1);
        return &instance;
    }
};

struct TransportRotationMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_FLOAT, 4, true },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1140687, -1, 3, 2, 0xC1124B6A, fields, 2);
        return &instance;
    }
};

struct TrophyMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_STRING, 1, true },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, false },
        };
        static constexpr DB2Meta instance(975024, -1, 4, 4, 0x72D11E6D, fields, -1);
        return &instance;
    }
};

struct UIChromieTimeExpansionInfoMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[11] =
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
        };
        static constexpr DB2Meta instance(3488582, -1, 11, 11, 0x53011113, fields, -1);
        return &instance;
    }
};

struct UICovenantAbilityMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3502042, -1, 4, 4, 0x11D03E08, fields, 0);
        return &instance;
    }
};

struct UICovenantPreviewMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[16] =
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
        static constexpr DB2Meta instance(3502043, 2, 16, 16, 0xDBB74257, fields, -1);
        return &instance;
    }
};

struct UIDungeonScoreRarityMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[12] =
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
        static constexpr DB2Meta instance(4065278, 0, 12, 12, 0xC8D50D38, fields, -1);
        return &instance;
    }
};

struct UIEventToastMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[20] =
        {
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
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3946498, -1, 20, 20, 0xD800F14D, fields, -1);
        return &instance;
    }
};

struct UIExpansionDisplayInfoMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, false },
        };
        static constexpr DB2Meta instance(1729547, -1, 3, 3, 0xF6D1CC7A, fields, -1);
        return &instance;
    }
};

struct UIExpansionDisplayInfoIconMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_STRING, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1729546, -1, 3, 3, 0xB5FB76BF, fields, -1);
        return &instance;
    }
};

struct UIModifiedInstanceMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[8] =
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
        static constexpr DB2Meta instance(4530951, -1, 8, 8, 0x1948D0B5, fields, -1);
        return &instance;
    }
};

struct UIScriptedAnimationEffectMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[26] =
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
        static constexpr DB2Meta instance(3556601, -1, 26, 26, 0xD9F17C48, fields, -1);
        return &instance;
    }
};

struct UISplashScreenMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[15] =
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
        static constexpr DB2Meta instance(2960122, -1, 15, 15, 0x5C67BB80, fields, -1);
        return &instance;
    }
};

struct UiCamFbackTransmogChrRaceMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[5] =
        {
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
        };
        static constexpr DB2Meta instance(1261406, -1, 5, 5, 0x7C47244B, fields, -1);
        return &instance;
    }
};

struct UiCamFbackTransmogWeaponMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
        };
        static constexpr DB2Meta instance(1261407, -1, 4, 4, 0xB6F384A3, fields, -1);
        return &instance;
    }
};

struct UiCameraMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[9] =
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
        static constexpr DB2Meta instance(1120287, -1, 9, 9, 0x2F44A4B5, fields, -1);
        return &instance;
    }
};

struct UiCameraTypeMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
        };
        static constexpr DB2Meta instance(1120288, -1, 3, 3, 0xB158BEC0, fields, -1);
        return &instance;
    }
};

struct UiCanvasMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_SHORT, 1, true },
            { FT_SHORT, 1, true },
        };
        static constexpr DB2Meta instance(1989363, -1, 2, 2, 0xB4407510, fields, -1);
        return &instance;
    }
};

struct UiCovenantDisplayInfoMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[12] =
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
        static constexpr DB2Meta instance(3509132, -1, 12, 12, 0x04B5154E, fields, -1);
        return &instance;
    }
};

struct UiItemInteractionMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[16] =
        {
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
        static constexpr DB2Meta instance(3182424, -1, 16, 16, 0xB9E40623, fields, -1);
        return &instance;
    }
};

struct UiMapMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[13] =
        {
            { FT_STRING, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
            { FT_BYTE, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1957206, 1, 13, 13, 0x7A60CD63, fields, 2);
        return &instance;
    }
};

struct UiMapArtMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1957202, -1, 3, 3, 0xED57CAFB, fields, -1);
        return &instance;
    }
};

struct UiMapArtStyleLayerMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[9] =
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
        static constexpr DB2Meta instance(1957208, -1, 9, 8, 0x7D2E349A, fields, 8);
        return &instance;
    }
};

struct UiMapArtTileMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[5] =
        {
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1957210, -1, 5, 4, 0xB262E4E9, fields, 4);
        return &instance;
    }
};

struct UiMapAssignmentMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[10] =
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
        static constexpr DB2Meta instance(1957219, 3, 10, 10, 0xFA228778, fields, 4);
        return &instance;
    }
};

struct UiMapFogOfWarMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_INT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(2006972, 0, 4, 4, 0x437EAE73, fields, 1);
        return &instance;
    }
};

struct UiMapFogOfWarVisualizationMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_FLOAT, 1, true },
        };
        static constexpr DB2Meta instance(2006973, -1, 3, 3, 0x6337502A, fields, -1);
        return &instance;
    }
};

struct UiMapGroupMemberMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[5] =
        {
            { FT_STRING, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_BYTE, 1, true },
        };
        static constexpr DB2Meta instance(1957204, -1, 5, 5, 0xBD83EBDC, fields, 1);
        return &instance;
    }
};

struct UiMapLinkMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[9] =
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
        static constexpr DB2Meta instance(2030690, 2, 9, 9, 0xAB3E538F, fields, 3);
        return &instance;
    }
};

struct UiMapXMapArtMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1957217, -1, 3, 2, 0x517CED19, fields, 2);
        return &instance;
    }
};

struct UiModelSceneMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, false },
        };
        static constexpr DB2Meta instance(1548215, -1, 2, 2, 0xB25F82C0, fields, -1);
        return &instance;
    }
};

struct UiModelSceneActorMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[10] =
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
        static constexpr DB2Meta instance(1548214, 2, 10, 9, 0xA3270DEE, fields, 9);
        return &instance;
    }
};

struct UiModelSceneActorDisplayMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[7] =
        {
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
        };
        static constexpr DB2Meta instance(1548216, -1, 7, 7, 0xF4A979A2, fields, -1);
        return &instance;
    }
};

struct UiModelSceneCameraMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[16] =
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
        static constexpr DB2Meta instance(1548213, 3, 16, 15, 0x10F8A956, fields, 15);
        return &instance;
    }
};

struct UiPartyPoseMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[6] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1993323, -1, 6, 5, 0xCE023AA8, fields, 5);
        return &instance;
    }
};

struct UiQuestDetailsThemeMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_STRING, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3448518, -1, 4, 4, 0xAF517528, fields, -1);
        return &instance;
    }
};

struct UiTextureAtlasMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_INT, 1, true },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
        };
        static constexpr DB2Meta instance(897470, -1, 4, 4, 0xA63B3475, fields, -1);
        return &instance;
    }
};

struct UiTextureAtlasElementMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_INT, 1, false },
        };
        static constexpr DB2Meta instance(1989276, 1, 2, 2, 0x402AB955, fields, -1);
        return &instance;
    }
};

struct UiTextureAtlasMemberMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[12] =
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
        static constexpr DB2Meta instance(897532, 1, 12, 12, 0x2BD64311, fields, 7);
        return &instance;
    }
};

struct UiTextureKitMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[1] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
        };
        static constexpr DB2Meta instance(939159, -1, 1, 1, 0x5B96D427, fields, -1);
        return &instance;
    }
};

struct UiWidgetMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[9] =
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
        static constexpr DB2Meta instance(1983278, 1, 9, 9, 0xD38CBB29, fields, -1);
        return &instance;
    }
};

struct UiWidgetConstantSourceMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_SHORT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1983639, -1, 3, 2, 0x4960D0A0, fields, 2);
        return &instance;
    }
};

struct UiWidgetDataSourceMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1983640, -1, 4, 3, 0x183FA098, fields, 3);
        return &instance;
    }
};

struct UiWidgetMapMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(2322531, -1, 2, 1, 0xF9ADC09E, fields, 1);
        return &instance;
    }
};

struct UiWidgetSetMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3055925, -1, 2, 2, 0x271866B0, fields, -1);
        return &instance;
    }
};

struct UiWidgetStringSourceMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_STRING, 1, true },
            { FT_SHORT, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1983641, -1, 3, 2, 0xA23E18E8, fields, 2);
        return &instance;
    }
};

struct UiWidgetVisTypeDataReqMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[6] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(2740907, 1, 6, 5, 0x5FB9338F, fields, 5);
        return &instance;
    }
};

struct UiWidgetVisualizationMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[10] =
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
        static constexpr DB2Meta instance(1983276, -1, 10, 10, 0xC3CDAA95, fields, -1);
        return &instance;
    }
};

struct UiWidgetXWidgetSetMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3386363, -1, 2, 1, 0x7704E8C2, fields, 1);
        return &instance;
    }
};

struct UnitBloodMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[6] =
        {
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
        };
        static constexpr DB2Meta instance(1284821, -1, 6, 6, 0x0FF08208, fields, -1);
        return &instance;
    }
};

struct UnitBloodLevelsMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[1] =
        {
            { FT_BYTE, 3, false },
        };
        static constexpr DB2Meta instance(1268904, -1, 1, 1, 0xCF406CD7, fields, -1);
        return &instance;
    }
};

struct UnitConditionMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_BYTE, 1, false },
            { FT_BYTE, 8, false },
            { FT_BYTE, 8, true },
            { FT_INT, 8, true },
        };
        static constexpr DB2Meta instance(1120959, -1, 4, 4, 0x383D75FD, fields, -1);
        return &instance;
    }
};

struct UnitPowerBarMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[16] =
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
        static constexpr DB2Meta instance(1237753, -1, 16, 16, 0xE815439F, fields, -1);
        return &instance;
    }
};

struct VehicleMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[18] =
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
            { FT_SHORT, 1, false },
            { FT_INT, 1, true },
            { FT_SHORT, 1, false },
            { FT_SHORT, 8, false },
            { FT_SHORT, 3, false },
        };
        static constexpr DB2Meta instance(1368621, -1, 18, 18, 0xA0087D9F, fields, -1);
        return &instance;
    }
};

struct VehiclePOITypeMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[5] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3311405, -1, 5, 5, 0xC5DB21A0, fields, -1);
        return &instance;
    }
};

struct VehicleSeatMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[61] =
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
        static constexpr DB2Meta instance(1345447, -1, 61, 61, 0x50B6088F, fields, -1);
        return &instance;
    }
};

struct VehicleUIIndSeatMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_BYTE, 1, false },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1279741, -1, 4, 3, 0xB64B1BD8, fields, 3);
        return &instance;
    }
};

struct VehicleUIIndicatorMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[1] =
        {
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1279740, -1, 1, 1, 0xB127675D, fields, -1);
        return &instance;
    }
};

struct VignetteMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[10] =
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
        static constexpr DB2Meta instance(892861, -1, 10, 10, 0xEC171292, fields, -1);
        return &instance;
    }
};

struct VirtualAttachmentMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_SHORT, 1, true },
        };
        static constexpr DB2Meta instance(1634482, -1, 2, 2, 0x96EE7037, fields, -1);
        return &instance;
    }
};

struct VirtualAttachmentCustomizationMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_SHORT, 1, true },
            { FT_INT, 1, true },
            { FT_SHORT, 1, true },
        };
        static constexpr DB2Meta instance(1634480, -1, 3, 3, 0xE7753F5C, fields, -1);
        return &instance;
    }
};

struct VocalUISoundsMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 2, false },
        };
        static constexpr DB2Meta instance(1267067, -1, 4, 4, 0x38987A6C, fields, -1);
        return &instance;
    }
};

struct VoiceOverPriorityMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(4211372, -1, 3, 3, 0xA54084F0, fields, -1);
        return &instance;
    }
};

struct VolumeFogConditionMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_INT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3587230, -1, 4, 3, 0xA8C126ED, fields, 3);
        return &instance;
    }
};

struct WMOAreaTableMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[15] =
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
        static constexpr DB2Meta instance(1355528, 1, 15, 15, 0xCD7AF6E0, fields, 2);
        return &instance;
    }
};

struct WMOMinimapTextureMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[5] =
        {
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1323241, -1, 5, 4, 0x2A1E430A, fields, 4);
        return &instance;
    }
};

struct WaterfallDataMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[19] =
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
        static constexpr DB2Meta instance(2565222, -1, 19, 19, 0x2169A76A, fields, -1);
        return &instance;
    }
};

struct WaypointEdgeMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[5] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(2565258, -1, 5, 5, 0x0E663F8B, fields, -1);
        return &instance;
    }
};

struct WaypointNodeMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[6] =
        {
            { FT_STRING, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(2565265, -1, 6, 6, 0xCE16D4A6, fields, -1);
        return &instance;
    }
};

struct WaypointSafeLocsMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_FLOAT, 3, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(2820850, -1, 2, 2, 0xEB35FD5C, fields, -1);
        return &instance;
    }
};

struct WbAccessControlListMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[5] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
        };
        static constexpr DB2Meta instance(879634, -1, 5, 5, 0xF9DAF847, fields, -1);
        return &instance;
    }
};

struct WeaponImpactSoundsMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[7] =
        {
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 11, false },
            { FT_INT, 11, false },
            { FT_INT, 11, false },
            { FT_INT, 11, false },
        };
        static constexpr DB2Meta instance(1267648, -1, 7, 7, 0xCC11734B, fields, -1);
        return &instance;
    }
};

struct WeaponSwingSounds2Meta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, false },
        };
        static constexpr DB2Meta instance(1267068, -1, 3, 3, 0x7F3FBC0A, fields, -1);
        return &instance;
    }
};

struct WeaponTrailMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[9] =
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
        static constexpr DB2Meta instance(982461, -1, 9, 9, 0xCD83E5F9, fields, -1);
        return &instance;
    }
};

struct WeaponTrailModelDefMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_INT, 1, true },
            { FT_SHORT, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1239843, -1, 3, 2, 0xC737CAD2, fields, 2);
        return &instance;
    }
};

struct WeaponTrailParamMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[10] =
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
        static constexpr DB2Meta instance(1239842, -1, 10, 9, 0xDC6EF9B4, fields, 9);
        return &instance;
    }
};

struct WeatherMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[23] =
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
        static constexpr DB2Meta instance(1343311, -1, 23, 23, 0x354627A5, fields, -1);
        return &instance;
    }
};

struct WeatherXParticulateMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1965591, -1, 2, 1, 0xD6E739FE, fields, 1);
        return &instance;
    }
};

struct WeeklyRewardChestThresholdMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_INT, 1, true },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(3580962, -1, 3, 3, 0xBEF159C4, fields, -1);
        return &instance;
    }
};

struct WindSettingsMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[10] =
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
        static constexpr DB2Meta instance(943871, -1, 10, 10, 0xE359B6F6, fields, -1);
        return &instance;
    }
};

struct WorldBossLockoutMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[2] =
        {
            { FT_STRING, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(975279, -1, 2, 2, 0x245D9086, fields, -1);
        return &instance;
    }
};

struct WorldChunkSoundsMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[6] =
        {
            { FT_SHORT, 1, false },
            { FT_INT, 1, true },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
        };
        static constexpr DB2Meta instance(1267069, -1, 6, 6, 0x967E93B7, fields, -1);
        return &instance;
    }
};

struct WorldEffectMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[6] =
        {
            { FT_INT, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, false },
            { FT_SHORT, 1, false },
        };
        static constexpr DB2Meta instance(1343312, -1, 6, 6, 0x79117AA9, fields, -1);
        return &instance;
    }
};

struct WorldElapsedTimerMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_STRING, 1, true },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
        };
        static constexpr DB2Meta instance(1135240, -1, 3, 3, 0x30FF7138, fields, -1);
        return &instance;
    }
};

struct WorldMapOverlayMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[13] =
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
        static constexpr DB2Meta instance(1134579, 0, 13, 13, 0x00F18FC5, fields, 1);
        return &instance;
    }
};

struct WorldMapOverlayTileMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[5] =
        {
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1957212, -1, 5, 4, 0x341D6DB6, fields, 4);
        return &instance;
    }
};

struct WorldStateExpressionMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[1] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
        };
        static constexpr DB2Meta instance(1332558, -1, 1, 1, 0x6695F131, fields, -1);
        return &instance;
    }
};

struct WorldStateZoneSoundsMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[9] =
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
        static constexpr DB2Meta instance(1266941, -1, 9, 9, 0x52C5ECE9, fields, -1);
        return &instance;
    }
};

struct World_PVP_AreaMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[7] =
        {
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_SHORT, 1, false },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, true },
        };
        static constexpr DB2Meta instance(1310255, -1, 7, 7, 0xDB4FFDE0, fields, -1);
        return &instance;
    }
};

struct ZoneIntroMusicTableMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_INT, 1, false },
            { FT_BYTE, 1, false },
            { FT_SHORT, 1, false },
        };
        static constexpr DB2Meta instance(1310251, -1, 4, 4, 0xBEB0D6B9, fields, -1);
        return &instance;
    }
};

struct ZoneLightMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[8] =
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
        static constexpr DB2Meta instance(1310253, -1, 8, 8, 0xF6796C55, fields, -1);
        return &instance;
    }
};

struct ZoneLightPointMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[3] =
        {
            { FT_FLOAT, 2, true },
            { FT_BYTE, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1310256, -1, 3, 2, 0x99D8C676, fields, 2);
        return &instance;
    }
};

struct ZoneMusicMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_INT, 2, false },
            { FT_INT, 2, false },
            { FT_INT, 2, false },
        };
        static constexpr DB2Meta instance(1310254, -1, 4, 4, 0x7894E43E, fields, -1);
        return &instance;
    }
};

struct ZoneStoryMeta
{
    static DB2Meta const* Instance()
    {
        static constexpr DB2MetaField fields[4] =
        {
            { FT_BYTE, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, false },
            { FT_INT, 1, true },
        };
        static constexpr DB2Meta instance(1797864, -1, 4, 3, 0x4C6C5CD7, fields, 3);
        return &instance;
    }
};

#endif // DB2Metadata_h__
