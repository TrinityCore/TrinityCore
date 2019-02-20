/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

namespace AuthHelper
{
    static RealmBuildInfo const PostBcAcceptedClientBuilds[] =
    {
        {15595, 4, 3, 4, ' ', {{}}, {{}}},
        {14545, 4, 2, 2, ' ', {{}}, {{}}},
        {13623, 4, 0, 6, 'a', {{}}, {{}}},
        {13930, 3, 3, 5, 'a', {{}}, {{}}},                                  // 3.3.5a China Mainland build
        {12340, 3, 3, 5, 'a',
            {{ 0xCD, 0xCB, 0xBD, 0x51, 0x88, 0x31, 0x5E, 0x6B, 0x4D, 0x19, 0x44, 0x9D, 0x49, 0x2D, 0xBC, 0xFA, 0xF1, 0x56, 0xA3, 0x47 }},
            {{ 0xB7, 0x06, 0xD1, 0x3F, 0xF2, 0xF4, 0x01, 0x88, 0x39, 0x72, 0x94, 0x61, 0xE3, 0xF8, 0xA0, 0xE2, 0xB5, 0xFD, 0xC0, 0x34 }},
        },
        {11723, 3, 3, 3, 'a', {{}}, {{}}},
        {11403, 3, 3, 2, ' ', {{}}, {{}}},
        {11159, 3, 3, 0, 'a', {{}}, {{}}},
        {10505, 3, 2, 2, 'a', {{}}, {{}}},
        {9947,  3, 1, 3, ' ', {{}}, {{}}},
        {8606,  2, 4, 3, ' ',
            {{ 0x31, 0x9A, 0xFA, 0xA3, 0xF2, 0x55, 0x96, 0x82, 0xF9, 0xFF, 0x65, 0x8B, 0xE0, 0x14, 0x56, 0x25, 0x5F, 0x45, 0x6F, 0xB1 }},
            {{}},
        },
        {0,     0, 0, 0, ' ', {{}}, {{}}}                                   // terminator
    };

    static RealmBuildInfo const PreBcAcceptedClientBuilds[] =
    {
        {6141,  1, 12, 3, ' ', {{}}, {{}}},
        {6005,  1, 12, 2, ' ', {{}}, {{}}},
        {5875,  1, 12, 1, ' ',
            {{}},
            {{ 0x8D, 0x17, 0x3C, 0xC3, 0x81, 0x96, 0x1E, 0xEB, 0xAB, 0xF3, 0x36, 0xF5, 0xE6, 0x67, 0x5B, 0x10, 0x1B, 0xB5, 0x13, 0xE5 }},
        },
        {0,     0, 0, 0, ' ', {{}}, {{}}}                                   // terminator
    };

    bool IsPreBCAcceptedClientBuild(int build)
    {
        for (int i = 0; PreBcAcceptedClientBuilds[i].Build; ++i)
            if (PreBcAcceptedClientBuilds[i].Build == build)
                return true;

        return false;
    }

    bool IsPostBCAcceptedClientBuild(int build)
    {
        for (int i = 0; PostBcAcceptedClientBuilds[i].Build; ++i)
            if (PostBcAcceptedClientBuilds[i].Build == build)
                return true;

        return false;
    }

    bool IsAcceptedClientBuild(int build)
    {
        return (IsPostBCAcceptedClientBuild(build) || IsPreBCAcceptedClientBuild(build));
    }

    RealmBuildInfo const* GetBuildInfo(int build)
    {
        for (int i = 0; PostBcAcceptedClientBuilds[i].Build; ++i)
            if (PostBcAcceptedClientBuilds[i].Build == build)
                return &PostBcAcceptedClientBuilds[i];

        for (int i = 0; PreBcAcceptedClientBuilds[i].Build; ++i)
            if (PreBcAcceptedClientBuilds[i].Build == build)
                return &PreBcAcceptedClientBuilds[i];

        return nullptr;
    }
}
