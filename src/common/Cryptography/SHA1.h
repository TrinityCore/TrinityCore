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
#include "Errors.h"
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

        template <size_t SIZE, size_t... SIZES, typename... Ts> void UpdateBigNumbers(BigNumber const& bn, Ts&&... tail)
        {
            static_assert(sizeof...(SIZES) == sizeof...(Ts));
            UpdateBigNumber<SIZE>(bn);
            if constexpr (sizeof...(Ts) > 0)
                UpdateBigNumbers<SIZES...>(std::forward<Ts>(tail)...);
        }

        void Initialize();
        void Finalize();

        uint8 const* GetDigest(void) const { return _mDigest; }
        int GetLength(void) const { return HASH_LEN; }

    private:
        template <size_t SIZE> void UpdateBigNumber(BigNumber const& bn)
        {
            std::array<uint8, SIZE> arena;
            bool success = bn.AsByteArray(arena.data(), SIZE);
            ASSERT(success, "UpdateBigNumber size %d too small for %d bytes in bn", SIZE, bn.GetNumBytes());
            UpdateData(arena.data(), SIZE);
        }

        SHA_CTX _mC;
        uint8 _mDigest[SHA_DIGEST_LENGTH];
};

/// Returns the SHA1 hash of the given content as hex string.
TC_COMMON_API std::string CalculateSHA1Hash(std::string const& content);

#endif
