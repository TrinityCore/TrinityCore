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

#ifndef _AUTH_SHA1_H
#define _AUTH_SHA1_H

#include "Define.h"
#include <array>
#include <string>
#include <openssl/sha.h>

class BigNumber;

class TC_COMMON_API SHA1Hash
{
    public:
        SHA1Hash();
        ~SHA1Hash();
        static constexpr size_t HASH_LEN = SHA_DIGEST_LENGTH;


        void UpdateData(const uint8 *dta, int len);
        void UpdateData(const std::string &str);

        template <size_t... SIZES, typename... Ts> auto UpdateBigNumbers(Ts&&... ts) -> std::enable_if_t<(std::is_same_v<BigNumber, std::decay_t<Ts>>&& ...)>
        {
            static_assert(sizeof...(SIZES) == sizeof...(Ts), "Size count needs to equal argument count");
            (UpdateBigNumber<SIZES>(std::forward<Ts>(ts)), ...);
        }

        void Initialize();
        void Finalize();

        uint8 const* GetDigest(void) const { return _digest; }

    private:
        static void _CheckedBNToBytes(BigNumber const& bn, uint8* arena, size_t sz);
        template <size_t SIZE> void UpdateBigNumber(BigNumber const& bn)
        {
            std::array<uint8, SIZE> arena;
            _CheckedBNToBytes(bn, arena.data(), SIZE);
            UpdateData(arena.data(), SIZE);
        }

        SHA_CTX _ctx;
        uint8 _digest[SHA_DIGEST_LENGTH];
};

/// Returns the SHA1 hash of the given content as hex string.
TC_COMMON_API std::string CalculateSHA1Hash(std::string const& content);

#endif
