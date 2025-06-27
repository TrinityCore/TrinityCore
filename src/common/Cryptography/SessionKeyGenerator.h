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

#ifndef TRINITY_SESSIONKEYGENERATOR_HPP
#define TRINITY_SESSIONKEYGENERATOR_HPP

#include <cstring>
#include "CryptoHash.h"

template <typename Hash>
class SessionKeyGenerator
{
    public:
        template <typename C>
        SessionKeyGenerator(C const& buf) :
            o0it(o0.begin())
        {
            uint8 const* data = std::data(buf);
            size_t const len = std::size(buf);
            size_t const halflen = (len / 2);

            o1 = Hash::GetDigestOf(data, halflen);
            o2 = Hash::GetDigestOf(data + halflen, len - halflen);
            o0 = Hash::GetDigestOf(o1, o0, o2);
        }

        void Generate(uint8* buf, uint32 sz)
        {
            for (uint32 i = 0; i < sz; ++i)
            {
                if (o0it == o0.end())
                {
                    o0 = Hash::GetDigestOf(o1, o0, o2);
                    o0it = o0.begin();
                }

                buf[i] = *(o0it++);
            }
        }

    private:
        typename Hash::Digest o0 = { };
        typename Hash::Digest o1 = { };
        typename Hash::Digest o2 = { };
        typename Hash::Digest::const_iterator o0it;
    };

#endif
