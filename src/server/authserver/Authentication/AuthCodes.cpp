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

#include "AuthCodes.h"
#include "RealmList.h"

namespace AuthHelper
{
    constexpr static uint32 MAX_PRE_BC_CLIENT_BUILD = 6141;

    bool IsPreBCAcceptedClientBuild(uint32 build)
    {
        return build <= MAX_PRE_BC_CLIENT_BUILD && sRealmList->GetBuildInfo(build);
    }

    bool IsPostBCAcceptedClientBuild(uint32 build)
    {
        return build > MAX_PRE_BC_CLIENT_BUILD && sRealmList->GetBuildInfo(build);
    }

    bool IsAcceptedClientBuild(uint32 build)
    {
        return sRealmList->GetBuildInfo(build) != nullptr;
    }
}
