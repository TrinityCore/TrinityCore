/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
 * Copyright (C) 2005-2011 MaNGOS <http://getmangos.com/>
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

#ifndef SessionKeyGeneration_h__
#define SessionKeyGeneration_h__

#include "Define.h"
#include <cstring>

template<class Hash>
class SessionKeyGenerator
{
public:
    SessionKeyGenerator(uint8* buff, uint32 size)
    {
        uint32 halfSize = size / 2;

        sh.Initialize();
        sh.UpdateData(buff, halfSize);
        sh.Finalize();

        memcpy(o1, sh.GetDigest(), Hash::DigestLength::value);

        sh.Initialize();
        sh.UpdateData(buff + halfSize, size - halfSize);
        sh.Finalize();

        memcpy(o2, sh.GetDigest(), Hash::DigestLength::value);

        memset(o0, 0x00, Hash::DigestLength::value);

        FillUp();
    }

    void Generate(uint8* buf, uint32 sz)
    {
        for (uint32 i = 0; i < sz; ++i)
        {
            if (taken == Hash::DigestLength::value)
                FillUp();

            buf[i] = o0[taken];
            taken++;
        }
    }

private:
    void FillUp()
    {
        sh.Initialize();
        sh.UpdateData(o1, Hash::DigestLength::value);
        sh.UpdateData(o0, Hash::DigestLength::value);
        sh.UpdateData(o2, Hash::DigestLength::value);
        sh.Finalize();

        memcpy(o0, sh.GetDigest(), Hash::DigestLength::value);

        taken = 0;
    }

    Hash sh;
    uint32 taken;
    uint8 o0[Hash::DigestLength::value];
    uint8 o1[Hash::DigestLength::value];
    uint8 o2[Hash::DigestLength::value];
};

#endif // SessionKeyGeneration_h__
