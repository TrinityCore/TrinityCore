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

#ifndef VMAPEXPORT_H
#define VMAPEXPORT_H

#include "Define.h"
#include <atomic>
#include <memory>
#include <string>
#include <unordered_map>

// flags of each spawn
enum ModelInstanceFlags
{
    MOD_HAS_BOUND       = 1 << 0,
    MOD_PARENT_SPAWN    = 1 << 1,
    MOD_PATH_ONLY       = 1 << 2
};

// flags of each model
enum class ModelFlags : uint32
{
    None    = 0x0,
    IsM2    = 0x1
};

struct WMODoodadData;

extern const char * szWorkDirWmo;

uint32 GenerateUniqueObjectId(uint32 clientId, uint16 clientDoodadId, bool isWmo);

struct ExtractedModelData
{
    enum ExtractionState : uint8
    {
        InProgress,
        Ok,
        OkNoCollision,  // has no data by itself but its WMO doodads do
        Failed
    };

    std::atomic<ExtractionState> State;
    std::unique_ptr<WMODoodadData> Doodads;

    void Wait()
    {
        State.wait(InProgress);
    }

    void Fail()
    {
        State.store(Failed);
        State.notify_all();
    }

    void Complete(ExtractionState state = Ok)
    {
        State.store(state);
        State.notify_all();
    }

    bool HasCollision() const { return State.load(std::memory_order::relaxed) == Ok; }
};

std::pair<ExtractedModelData*, bool> BeginModelExtraction(std::string const& outputName);

ExtractedModelData const* ExtractSingleWmo(std::string& fname);
ExtractedModelData const* ExtractSingleModel(std::string& fname);

void ExtractGameobjectModels();

bool IsLiquidIgnored(uint32 liquidTypeId);

#endif
