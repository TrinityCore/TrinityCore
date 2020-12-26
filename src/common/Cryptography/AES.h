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

#ifndef Trinity_AES_h__
#define Trinity_AES_h__

#include "Define.h"
#include <array>
#include <openssl/evp.h>

namespace Trinity
{
namespace Crypto
{
    class TC_COMMON_API AES
    {
    public:
        static constexpr size_t IV_SIZE_BYTES = 12;
        static constexpr size_t KEY_SIZE_BYTES = 16;
        static constexpr size_t TAG_SIZE_BYTES = 12;

        using IV = std::array<uint8, IV_SIZE_BYTES>;
        using Key = std::array<uint8, KEY_SIZE_BYTES>;
        using Tag = uint8[TAG_SIZE_BYTES];

        AES(bool encrypting);
        ~AES();

        void Init(Key const& key);

        bool Process(IV const& iv, uint8* data, size_t length, Tag& tag);

    private:
        EVP_CIPHER_CTX* _ctx;
        bool _encrypting;
    };
}
}

#endif // Trinity_AES_h__
