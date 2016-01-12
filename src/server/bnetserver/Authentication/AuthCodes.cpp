/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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
#include <cstddef>

namespace AuthHelper
{
    static RealmBuildInfo const PostBcAcceptedClientBuilds[] =
    {
        {15595, 4, 3, 4, ' '},
        {14545, 4, 2, 2, ' '},
        {13623, 4, 0, 6, 'a'},
        {13930, 3, 3, 5, 'a'},                                  // 3.3.5a China Mainland build
        {12340, 3, 3, 5, 'a'},
        {11723, 3, 3, 3, 'a'},
        {11403, 3, 3, 2, ' '},
        {11159, 3, 3, 0, 'a'},
        {10505, 3, 2, 2, 'a'},
        {9947,  3, 1, 3, ' '},
        {8606,  2, 4, 3, ' '},
        {6141,  1, 12, 3, ' '},
        {6005,  1, 12, 2, ' '},
        {5875,  1, 12, 1, ' '},
        {0,     0, 0, 0, ' '}                                   // terminator
    };

    RealmBuildInfo const* GetBuildInfo(int build)
    {
        for (int i = 0; PostBcAcceptedClientBuilds[i].Build; ++i)
            if (PostBcAcceptedClientBuilds[i].Build == build)
                return &PostBcAcceptedClientBuilds[i];

        return nullptr;
    }

    bool IsBuildSupportingBattlenet(int build)
    {
        return build >= 15595;
    }
}
