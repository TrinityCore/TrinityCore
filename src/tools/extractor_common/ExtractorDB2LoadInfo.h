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

#ifndef TRINITYCORE_EXTRACTOR_DB2_LOAD_INFO_H
#define TRINITYCORE_EXTRACTOR_DB2_LOAD_INFO_H

#include "DB2FileLoader.h"
#include "DB2Meta.h"

struct CinematicCameraLoadInfo
{
    static constexpr DB2MetaField MetaFields[5] =
    {
        { .Type = FT_FLOAT,                .ArraySize =  3, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta MetaInstance =
    {
        .FileDataId         = 1294214,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 5,
        .FileFieldCount     = 5,
        .LayoutHash         = 0x8BFD752B,
        .Fields             = MetaFields
    };

    static constexpr DB2FieldMeta Fields[8] =
    {
        { false, FT_INT, "ID" },
        { false, FT_FLOAT, "OriginX" },
        { false, FT_FLOAT, "OriginY" },
        { false, FT_FLOAT, "OriginZ" },
        { false, FT_INT, "SoundID" },
        { false, FT_FLOAT, "OriginFacing" },
        { false, FT_INT, "FileDataID" },
        { false, FT_INT, "ConversationID" },
    };

    static constexpr DB2FileLoadInfo Instance{ Fields, 8, & MetaInstance };
};

struct GameobjectDisplayInfoLoadInfo
{
    static constexpr DB2MetaField MetaFields[9] =
    {
        { .Type = FT_FLOAT,                .ArraySize =  6, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta MetaInstance =
    {
        .FileDataId         = 1266277,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 9,
        .FileFieldCount     = 9,
        .LayoutHash         = 0xD85414D1,
        .Fields             = MetaFields
    };

    static constexpr DB2FieldMeta Fields[15] =
    {
        { false, FT_INT, "ID" },
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
        { true, FT_INT, "AlternateDisplayType" },
        { true, FT_INT, "ClientCreatureDisplayInfoID" },
        { true, FT_INT, "ClientItemID" },
        { false, FT_SHORT, "Unknown1100" },
    };

    static constexpr DB2FileLoadInfo Instance{ Fields, 15, &MetaInstance };
};

struct LiquidMaterialLoadInfo
{
    static constexpr DB2MetaField MetaFields[2] =
    {
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned =  true },
    };

    static constexpr DB2Meta MetaInstance =
    {
        .FileDataId         = 1132538,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 2,
        .FileFieldCount     = 2,
        .LayoutHash         = 0x98E5D7AA,
        .Fields             = MetaFields
    };

    static constexpr DB2FieldMeta Fields[3] =
    {
        { false, FT_INT, "ID" },
        { true, FT_INT, "Flags" },
        { true, FT_BYTE, "LVF" },
    };

    static constexpr DB2FileLoadInfo Instance{ Fields, 3, &MetaInstance };
};

struct LiquidObjectLoadInfo
{
    static constexpr DB2MetaField MetaFields[5] =
    {
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
    };

    static constexpr DB2Meta MetaInstance =
    {
        .FileDataId         = 1308058,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 5,
        .FileFieldCount     = 5,
        .LayoutHash         = 0xCB0D39E8,
        .Fields             = MetaFields
    };

    static constexpr DB2FieldMeta Fields[6] =
    {
        { false, FT_INT, "ID" },
        { false, FT_FLOAT, "FlowDirection" },
        { false, FT_FLOAT, "FlowSpeed" },
        { true, FT_SHORT, "LiquidTypeID" },
        { false, FT_BYTE, "Fishable" },
        { false, FT_BYTE, "Reflection" },
    };

    static constexpr DB2FileLoadInfo Instance{ Fields, 6, &MetaInstance };
};

struct LiquidTypeLoadInfo
{
    static constexpr DB2MetaField MetaFields[21] =
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

    static constexpr DB2Meta MetaInstance =
    {
        .FileDataId         = 1371380,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 21,
        .FileFieldCount     = 21,
        .LayoutHash         = 0x4397CEE6,
        .Fields             = MetaFields
    };

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
        { true, FT_INT, "Flags" },
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
    static constexpr DB2MetaField MetaFields[25] =
    {
        { .Type = FT_STRING_NOT_LOCALIZED, .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_STRING,               .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_FLOAT,                .ArraySize =  2, .IsSigned =  true },
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
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_BYTE,                 .ArraySize =  1, .IsSigned = false },
        { .Type = FT_SHORT,                .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  1, .IsSigned =  true },
        { .Type = FT_INT,                  .ArraySize =  3, .IsSigned =  true },
    };

    static constexpr DB2Meta MetaInstance =
    {
        .FileDataId         = 1349477,
        .IndexField         = -1,
        .ParentIndexField   = -1,
        .FieldCount         = 25,
        .FileFieldCount     = 25,
        .LayoutHash         = 0xE0196C63,
        .Fields             = MetaFields
    };

    static constexpr DB2FieldMeta Fields[29] =
    {
        { false, FT_INT, "ID" },
        { false, FT_STRING_NOT_LOCALIZED, "Directory" },
        { false, FT_STRING, "MapName" },
        { false, FT_STRING, "MapDescription0" },
        { false, FT_STRING, "MapDescription1" },
        { false, FT_STRING, "PvpShortDescription" },
        { false, FT_STRING, "PvpLongDescription" },
        { false, FT_FLOAT, "CorpseX" },
        { false, FT_FLOAT, "CorpseY" },
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
        { true, FT_SHORT, "CorpseMapID" },
        { false, FT_BYTE, "MaxPlayers" },
        { true, FT_SHORT, "WindSettingsID" },
        { true, FT_INT, "ZmpFileDataID" },
        { true, FT_INT, "WdtFileDataID" },
        { true, FT_INT, "NavigationMaxDistance" },
        { true, FT_INT, "PreloadFileDataID" },
        { true, FT_INT, "Flags1" },
        { true, FT_INT, "Flags2" },
        { true, FT_INT, "Flags3" },
    };

    static constexpr DB2FileLoadInfo Instance{ Fields, 29, &MetaInstance };
};

#endif // TRINITYCORE_EXTRACTOR_DB2_LOAD_INFO_H
