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

#include <cstring>
#include "SHA1.h"

#ifndef TRINITY_SESSIONKEYGENERATOR_HPP
#define TRINITY_SESSIONKEYGENERATOR_HPP

template <typename Hash>
class SessionKeyGenerator
{
    public:
        template <typename C>
        SessionKeyGenerator(C const& buf)
        {
            uint8 const* data = std::data(buf);
            size_t const len = std::size(buf);
            size_t const halflen = (len / 2);

            o1 = Hash::GetDigestOf(buf.data(), halflen);
            o2 = Hash::GetDigestOf(buf.data() + halflen, halflen);

            FillUp();
        }

        void Generate(uint8* buf, uint32 sz)
        {
            for (uint32 i = 0; i < sz; ++i)
            {
                if (o0it == o0.end())
                    FillUp();

                buf[i] = *(o0it++);
            }
        }

    private:
        void FillUp()
        {
            sh.Initialize();
            sh.UpdateData(o1);
            sh.UpdateData(o0);
            sh.UpdateData(o2);
            sh.Finalize();

            o0 = sh.GetDigest();
            o0it = o0.begin();
        }

        Hash sh;
        typename Hash::Digest o0, o1, o2;
        typename Hash::Digest::const_iterator o0it;
    };

#endif
