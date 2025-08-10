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

#ifndef InstanceScriptData_h__
#define InstanceScriptData_h__

#include "Errors.h" // rapidjson depends on WPAssert
#include <rapidjson/document.h>
#include <string>

class InstanceScript;
struct UpdateBossStateSaveDataEvent;
struct UpdateAdditionalSaveDataEvent;

class InstanceScriptDataReader
{
public:
    enum class Result
    {
        Ok,
        MalformedJson,
        RootIsNotAnObject,
        MissingHeader,
        UnexpectedHeader,
        MissingBossStates,
        BossStatesIsNotAnObject,
        UnknownBoss,
        BossStateIsNotAnObject,
        MissingBossState,
        BossStateValueIsNotANumber,
        AdditionalDataIsNotAnObject,
        AdditionalDataUnexpectedValueType
    };

    InstanceScriptDataReader(InstanceScript& instance) : _instance(instance) { }

    Result Load(char const* data);

private:
    Result ParseHeader();
    Result ParseBossStates();
    Result ParseAdditionalData();

    // logging helpers
    uint32 GetInstanceId() const;
    uint32 GetMapId() const;
    char const* GetMapName() const;
    uint32 GetDifficultyId() const;
    char const* GetDifficultyName() const;

    InstanceScript& _instance;
    rapidjson::Document _doc;
};

class InstanceScriptDataWriter
{
public:
    InstanceScriptDataWriter(InstanceScript& instance) : _instance(instance) { }

    std::string GetString();
    void FillData(bool withValues = true);
    void FillDataFrom(std::string const& data);

    void SetBossState(UpdateBossStateSaveDataEvent const& data);
    void SetAdditionalData(UpdateAdditionalSaveDataEvent const& data);

private:
    InstanceScript& _instance;
    rapidjson::Document _doc;
};

#endif // InstanceScriptData_h__
