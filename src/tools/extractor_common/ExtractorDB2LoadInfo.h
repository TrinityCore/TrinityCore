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
#include <array>

struct CinematicCameraLoadInfo
{
    static DB2FileLoadInfo const* Instance()
    {
        static DB2FieldMeta const loadedFields[] =
        {
            { false, FT_INT, "ID" },
            { false, FT_FLOAT, "OriginX" },
            { false, FT_FLOAT, "OriginY" },
            { false, FT_FLOAT, "OriginZ" },
            { false, FT_INT, "SoundID" },
            { false, FT_FLOAT, "OriginFacing" },
            { false, FT_INT, "FileDataID" },
        };
        static DB2MetaField const fields[4] =
        {
            { FT_FLOAT, 3, true },
            { FT_INT, 1, false },
            { FT_FLOAT, 1, true },
            { FT_INT, 1, false },
        };
        static DB2Meta meta(1294214, -1, 4, 4, 0x744B99BC, fields, -1);
        static DB2FileLoadInfo const loadInfo(&loadedFields[0], std::extent<decltype(loadedFields)>::value, &meta);
        return &loadInfo;
    }
};

struct GameobjectDisplayInfoLoadInfo
{
    static DB2FileLoadInfo const* Instance()
    {
        static DB2FieldMeta const loadedFields[] =
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
        static DB2MetaField const fields[6] =
        {
            { FT_STRING_NOT_LOCALIZED, 1, true },
            { FT_FLOAT, 6, true },
            { FT_INT, 1, true },
            { FT_SHORT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
        };
        static DB2Meta meta(1266277, -1, 6, 6, 0xB59CF0B2, fields, -1);
        static DB2FileLoadInfo const loadInfo(&loadedFields[0], std::extent<decltype(loadedFields)>::value, &meta);
        return &loadInfo;
    }
};

struct LiquidMaterialLoadInfo
{
    static DB2FileLoadInfo const* Instance()
    {
        static DB2FieldMeta const loadedFields[] =
        {
            { false, FT_INT, "ID" },
            { true, FT_BYTE, "Flags" },
            { true, FT_BYTE, "LVF" },
        };
        static DB2MetaField const fields[2] =
        {
            { FT_BYTE, 1, true },
            { FT_BYTE, 1, true },
        };
        static DB2Meta meta(1132538, -1, 2, 2, 0x2CFFEA40, fields, -1);
        static DB2FileLoadInfo const loadInfo(&loadedFields[0], std::extent<decltype(loadedFields)>::value, &meta);
        return &loadInfo;
    }
};

struct LiquidObjectLoadInfo
{
    static DB2FileLoadInfo const* Instance()
    {
        static DB2FieldMeta const loadedFields[] =
        {
            { false, FT_INT, "ID" },
            { false, FT_FLOAT, "FlowDirection" },
            { false, FT_FLOAT, "FlowSpeed" },
            { true, FT_SHORT, "LiquidTypeID" },
            { false, FT_BYTE, "Fishable" },
            { false, FT_BYTE, "Reflection" },
        };
        static DB2MetaField const fields[5] =
        {
            { FT_FLOAT, 1, true },
            { FT_FLOAT, 1, true },
            { FT_SHORT, 1, true },
            { FT_BYTE, 1, false },
            { FT_BYTE, 1, false },
        };
        static DB2Meta meta(1308058, -1, 5, 5, 0x6CAEB8A1, fields, -1);
        static DB2FileLoadInfo const loadInfo(&loadedFields[0], std::extent<decltype(loadedFields)>::value, &meta);
        return &loadInfo;
    }
};

struct LiquidTypeLoadInfo
{
    static DB2FileLoadInfo const* Instance()
    {
        static DB2FieldMeta const loadedFields[] =
        {
            { false, FT_INT, "ID" },
            { false, FT_STRING_NOT_LOCALIZED, "ZoneName" },
            { false, FT_STRING, "AreaName" },
            { false, FT_SHORT, "ContinentID" },
            { false, FT_SHORT, "ParentAreaID" },
            { true, FT_SHORT, "AreaBit" },
            { false, FT_BYTE, "SoundProviderPref" },
            { false, FT_BYTE, "SoundProviderPrefUnderwater" },
            { false, FT_SHORT, "AmbienceID" },
            { false, FT_SHORT, "UwAmbience" },
            { false, FT_SHORT, "ZoneMusic" },
            { false, FT_SHORT, "UwZoneMusic" },
            { true, FT_BYTE, "ExplorationLevel" },
            { false, FT_SHORT, "IntroSound" },
            { false, FT_INT, "UwIntroSound" },
            { false, FT_BYTE, "FactionGroupMask" },
            { false, FT_FLOAT, "AmbientMultiplier" },
            { false, FT_BYTE, "MountFlags" },
            { true, FT_SHORT, "PvpCombatWorldStateID" },
            { false, FT_BYTE, "WildBattlePetLevelMin" },
            { false, FT_BYTE, "WildBattlePetLevelMax" },
            { false, FT_BYTE, "WindSettingsID" },
            { true, FT_INT, "Flags1" },
            { true, FT_INT, "Flags2" },
            { false, FT_SHORT, "LiquidTypeID1" },
            { false, FT_SHORT, "LiquidTypeID2" },
            { false, FT_SHORT, "LiquidTypeID3" },
            { false, FT_SHORT, "LiquidTypeID4" },
        };
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
        static DB2Meta meta(1371380, -1, 21, 21, 0xAFFFC9E0, fields, -1);
        static DB2FileLoadInfo const loadInfo(&loadedFields[0], std::extent<decltype(loadedFields)>::value, &meta);
        return &loadInfo;
    }
};

struct MapLoadInfo
{
    static DB2FileLoadInfo const* Instance()
    {
        static DB2FieldMeta const loadedFields[] =
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
        static DB2MetaField const fields[22] =
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
        static DB2Meta meta(1349477, -1, 22, 22, 0xBFC078A9, fields, -1);
        static DB2FileLoadInfo const loadInfo(&loadedFields[0], std::extent<decltype(loadedFields)>::value, &meta);
        return &loadInfo;
    }
};

#endif // ExtractorDB2LoadInfo_h__
