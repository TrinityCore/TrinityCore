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

#ifndef ExtractorDB2LoadInfo_h__
#define ExtractorDB2LoadInfo_h__

#include "DB2FileLoader.h"
#include "DB2Meta.h"

struct CinematicCameraLoadInfo
{
    static constexpr DB2MetaField MetaFields[4] =
    {
        { FT_FLOAT, 3, true },
        { FT_INT, 1, false },
        { FT_FLOAT, 1, true },
        { FT_INT, 1, false },
    };

    static constexpr DB2Meta MetaInstance{ 1294214, -1, 4, 4, 0x744B99BC, MetaFields, -1 };

    static constexpr DB2FieldMeta Fields[7] =
    {
        { false, FT_INT, "ID" },
        { false, FT_FLOAT, "OriginX" },
        { false, FT_FLOAT, "OriginY" },
        { false, FT_FLOAT, "OriginZ" },
        { false, FT_INT, "SoundID" },
        { false, FT_FLOAT, "OriginFacing" },
        { false, FT_INT, "FileDataID" },
    };

    static constexpr DB2FileLoadInfo Instance{ Fields, 7, & MetaInstance };
};

struct GameobjectDisplayInfoLoadInfo
{
    static constexpr DB2MetaField MetaFields[6] =
    {
        { FT_STRING_NOT_LOCALIZED, 1, true },
        { FT_FLOAT, 6, true },
        { FT_INT, 1, true },
        { FT_SHORT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
    };

    static constexpr DB2Meta MetaInstance{ 1266277, -1, 6, 6, 0xB59CF0B2, MetaFields, -1 };

    static constexpr DB2FieldMeta Fields[12] =
    {
        { false, FT_INT, "ID" },
        { false, FT_STRING_NOT_LOCALIZED, "ModelName" },
        { false, FT_FLOAT, "GeoBoxMinX" },
        { false, FT_FLOAT, "GeoBoxMinY" },
        { false, FT_FLOAT, "GeoBoxMinZ" },
        { false, FT_FLOAT, "GeoBoxMaxX" },
        { false, FT_FLOAT, "GeoBoxMaxY" },
        { false, FT_FLOAT, "GeoBoxMaxZ" },
        { true, FT_INT, "FileDataID" },
        { true, FT_SHORT, "ObjectEffectPackageID" },
        { false, FT_FLOAT, "OverrideLootEffectScale" },
        { false, FT_FLOAT, "OverrideNameScale" },
    };

    static constexpr DB2FileLoadInfo Instance{ Fields, 12, &MetaInstance };
};

struct LiquidMaterialLoadInfo
{
    static constexpr DB2MetaField MetaFields[2] =
    {
        { FT_BYTE, 1, true },
        { FT_BYTE, 1, true },
    };

    static constexpr DB2Meta MetaInstance{ 1132538, -1, 2, 2, 0x2CFFEA40, MetaFields, -1 };

    static constexpr DB2FieldMeta Fields[3] =
    {
        { false, FT_INT, "ID" },
        { true, FT_BYTE, "Flags" },
        { true, FT_BYTE, "LVF" },
    };

    static constexpr DB2FileLoadInfo Instance{ Fields, 3, &MetaInstance };
};

struct LiquidObjectLoadInfo
{
    static constexpr DB2MetaField MetaFields[5] =
    {
        { FT_FLOAT, 1, true },
        { FT_FLOAT, 1, true },
        { FT_SHORT, 1, true },
        { FT_BYTE, 1, false },
        { FT_BYTE, 1, false },
    };

    static constexpr DB2Meta MetaInstance{ 1308058, -1, 5, 5, 0x6CAEB8A1, MetaFields, -1 };

    static constexpr DB2FieldMeta Fields[6] =
    {
        { false, FT_INT, "ID" },
        { false, FT_FLOAT, "FlowDirection" },
        { false, FT_FLOAT, "FlowSpeed" },
        { true, FT_SHORT, "LiquidTypeID" },
        { false, FT_BYTE, "Fishable" },
        { false, FT_BYTE, "Reflection" },
    };

    static constexpr DB2FileLoadInfo Instance{ Fields, 3, & MetaInstance };
};

struct LiquidTypeLoadInfo
{
    static constexpr DB2MetaField MetaFields[21] =
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

    static constexpr DB2Meta MetaInstance{ 1371380, -1, 21, 21, 0xAFFFC9E0, MetaFields, -1 };

    static constexpr DB2FieldMeta Fields[56] =
    {
        { false, FT_INT, "ID" },
        { false, FT_STRING_NOT_LOCALIZED, "Name" },
        { false, FT_STRING_NOT_LOCALIZED, "Texture1" },
        { false, FT_STRING_NOT_LOCALIZED, "Texture2" },
        { false, FT_STRING_NOT_LOCALIZED, "Texture3" },
        { false, FT_STRING_NOT_LOCALIZED, "Texture4" },
        { false, FT_STRING_NOT_LOCALIZED, "Texture5" },
        { false, FT_STRING_NOT_LOCALIZED, "Texture6" },
        { false, FT_SHORT, "Flags" },
        { false, FT_BYTE, "SoundBank" },
        { false, FT_INT, "SoundID" },
        { false, FT_INT, "SpellID" },
        { false, FT_FLOAT, "MaxDarkenDepth" },
        { false, FT_FLOAT, "FogDarkenIntensity" },
        { false, FT_FLOAT, "AmbDarkenIntensity" },
        { false, FT_FLOAT, "DirDarkenIntensity" },
        { false, FT_SHORT, "LightID" },
        { false, FT_FLOAT, "ParticleScale" },
        { false, FT_BYTE, "ParticleMovement" },
        { false, FT_BYTE, "ParticleTexSlots" },
        { false, FT_BYTE, "MaterialID" },
        { true, FT_INT, "MinimapStaticCol" },
        { false, FT_BYTE, "FrameCountTexture1" },
        { false, FT_BYTE, "FrameCountTexture2" },
        { false, FT_BYTE, "FrameCountTexture3" },
        { false, FT_BYTE, "FrameCountTexture4" },
        { false, FT_BYTE, "FrameCountTexture5" },
        { false, FT_BYTE, "FrameCountTexture6" },
        { true, FT_INT, "Color1" },
        { true, FT_INT, "Color2" },
        { false, FT_FLOAT, "Float1" },
        { false, FT_FLOAT, "Float2" },
        { false, FT_FLOAT, "Float3" },
        { false, FT_FLOAT, "Float4" },
        { false, FT_FLOAT, "Float5" },
        { false, FT_FLOAT, "Float6" },
        { false, FT_FLOAT, "Float7" },
        { false, FT_FLOAT, "Float8" },
        { false, FT_FLOAT, "Float9" },
        { false, FT_FLOAT, "Float10" },
        { false, FT_FLOAT, "Float11" },
        { false, FT_FLOAT, "Float12" },
        { false, FT_FLOAT, "Float13" },
        { false, FT_FLOAT, "Float14" },
        { false, FT_FLOAT, "Float15" },
        { false, FT_FLOAT, "Float16" },
        { false, FT_FLOAT, "Float17" },
        { false, FT_FLOAT, "Float18" },
        { false, FT_INT, "Int1" },
        { false, FT_INT, "Int2" },
        { false, FT_INT, "Int3" },
        { false, FT_INT, "Int4" },
        { false, FT_FLOAT, "Coefficient1" },
        { false, FT_FLOAT, "Coefficient2" },
        { false, FT_FLOAT, "Coefficient3" },
        { false, FT_FLOAT, "Coefficient4" },
    };

    static constexpr DB2FileLoadInfo Instance{ Fields, 56, &MetaInstance };
};

struct MapLoadInfo
{
    static constexpr DB2MetaField MetaFields[22] =
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

    static constexpr DB2Meta MetaInstance{ 1349477, -1, 22, 22, 0xEE526FA5, MetaFields, -1 };

    static constexpr DB2FieldMeta Fields[25] =
    {
        { false, FT_INT, "ID" },
        { false, FT_STRING_NOT_LOCALIZED, "Directory" },
        { false, FT_STRING, "MapName" },
        { false, FT_STRING, "MapDescription0" },
        { false, FT_STRING, "MapDescription1" },
        { false, FT_STRING, "PvpShortDescription" },
        { false, FT_STRING, "PvpLongDescription" },
        { false, FT_BYTE, "MapType" },
        { true, FT_BYTE, "InstanceType" },
        { false, FT_BYTE, "ExpansionID" },
        { false, FT_SHORT, "AreaTableID" },
        { true, FT_SHORT, "LoadingScreenID" },
        { true, FT_SHORT, "TimeOfDayOverride" },
        { true, FT_SHORT, "ParentMapID" },
        { true, FT_SHORT, "CosmeticParentMapID" },
        { false, FT_BYTE, "TimeOffset" },
        { false, FT_FLOAT, "MinimapIconScale" },
        { true, FT_INT, "RaidOffset" },
        { true, FT_SHORT, "CorpseMapID" },
        { false, FT_BYTE, "MaxPlayers" },
        { true, FT_SHORT, "WindSettingsID" },
        { true, FT_INT, "ZmpFileDataID" },
        { true, FT_INT, "Flags1" },
        { true, FT_INT, "Flags2" },
        { true, FT_INT, "Flags3" },
    };

    static constexpr DB2FileLoadInfo Instance{ Fields, 25, &MetaInstance };
};

#endif // ExtractorDB2LoadInfo_h__
