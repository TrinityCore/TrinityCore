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

#include "SmoothPhasing.h"
#include "Containers.h"

void SmoothPhasing::SetViewerDependentInfo(ObjectGuid seer, SmoothPhasingInfo const& info)
{
    if (!std::holds_alternative<SmoothPhasingInfoViewerDependent>(_storage))
        _storage.emplace<SmoothPhasingInfoViewerDependent>();

    std::get<SmoothPhasingInfoViewerDependent>(_storage)[seer] = info;
}

void SmoothPhasing::ClearViewerDependentInfo(ObjectGuid seer)
{
    if (std::holds_alternative<SmoothPhasingInfoViewerDependent>(_storage))
        std::get<SmoothPhasingInfoViewerDependent>(_storage).erase(seer);
}

void SmoothPhasing::SetSingleInfo(SmoothPhasingInfo const& info)
{
    _storage.emplace<SmoothPhasingInfoSingle>() = info;
}

bool SmoothPhasing::IsReplacing(ObjectGuid guid) const
{
    return std::holds_alternative<SmoothPhasingInfoSingle>(_storage) && std::get<SmoothPhasingInfoSingle>(_storage).ReplaceObject == guid;
}

bool SmoothPhasing::IsBeingReplacedForSeer(ObjectGuid seer) const
{
    if (std::holds_alternative<SmoothPhasingInfoViewerDependent>(_storage))
        if (SmoothPhasingInfo const* smoothPhasingInfo = Trinity::Containers::MapGetValuePtr(std::get<SmoothPhasingInfoViewerDependent>(_storage), seer))
            return !smoothPhasingInfo->Disabled;

    return false;
}

SmoothPhasingInfo const* SmoothPhasing::GetInfoForSeer(ObjectGuid seer) const
{
    if (std::holds_alternative<SmoothPhasingInfoViewerDependent>(_storage))
        return Trinity::Containers::MapGetValuePtr(std::get<SmoothPhasingInfoViewerDependent>(_storage), seer);

    return &std::get<SmoothPhasingInfoSingle>(_storage);
}

void SmoothPhasing::DisableReplacementForSeer(ObjectGuid seer)
{
    if (std::holds_alternative<SmoothPhasingInfoViewerDependent>(_storage))
        if (SmoothPhasingInfo* smoothPhasingInfo = Trinity::Containers::MapGetValuePtr(std::get<SmoothPhasingInfoViewerDependent>(_storage), seer))
            smoothPhasingInfo->Disabled = true;
}
