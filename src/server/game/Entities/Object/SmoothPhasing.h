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

#ifndef TRINITYCORE_SMOOTHPHASING_H
#define TRINITYCORE_SMOOTHPHASING_H

#include "ObjectGuid.h"
#include "Optional.h"
#include <unordered_map>
#include <variant>

struct SmoothPhasingInfo
{
    // Fields visible on client
    Optional<ObjectGuid> ReplaceObject;
    bool ReplaceActive = true;
    bool StopAnimKits = true;

    // Serverside fields
    bool Disabled = false;
};

class TC_GAME_API SmoothPhasing
{
public:
    void SetViewerDependentInfo(ObjectGuid seer, SmoothPhasingInfo const& info);
    void ClearViewerDependentInfo(ObjectGuid seer);

    void SetSingleInfo(SmoothPhasingInfo const& info);

    bool IsReplacing(ObjectGuid guid) const;

    bool IsBeingReplacedForSeer(ObjectGuid seer) const;
    SmoothPhasingInfo const* GetInfoForSeer(ObjectGuid seer) const;
    void DisableReplacementForSeer(ObjectGuid seer);

private:
    using SmoothPhasingInfoViewerDependent = std::unordered_map<ObjectGuid /* Seer */, SmoothPhasingInfo>;
    using SmoothPhasingInfoSingle = SmoothPhasingInfo;

    std::variant<SmoothPhasingInfoSingle, SmoothPhasingInfoViewerDependent> _storage;
};

#endif // TRINITYCORE_SMOOTHPHASING_H
