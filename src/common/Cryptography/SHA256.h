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

#ifndef SHA256_h__
#define SHA256_h__

#include "Define.h"
#include <string>
#include <type_traits>
#include <openssl/sha.h>

class BigNumber;

class TC_COMMON_API SHA256Hash
{
    public:
        typedef std::integral_constant<uint32, SHA256_DIGEST_LENGTH> DigestLength;

        SHA256Hash();
        ~SHA256Hash();

        void UpdateBigNumbers(BigNumber* bn0, ...);

        void UpdateData(uint8 const* data, size_t len);
        void UpdateData(std::string const& str);

        void Initialize();
        void Finalize();

        uint8 *GetDigest() { return mDigest; }
        uint32 GetLength() const { return SHA256_DIGEST_LENGTH; }

    private:
        SHA256_CTX mC;
        uint8 mDigest[SHA256_DIGEST_LENGTH];
};

#endif // SHA256_h__
