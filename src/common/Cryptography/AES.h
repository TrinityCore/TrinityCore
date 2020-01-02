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
#include <openssl/evp.h>

namespace Trinity
{
namespace Crypto
{
class TC_COMMON_API AES
{
public:
    AES(bool encrypting);
    ~AES();

    void Init(uint8 const* key);

    bool Process(uint8 const* iv, uint8* data, std::size_t length, uint8(&tag)[12]);

private:
    EVP_CIPHER_CTX* _ctx;
    bool _encrypting;
};
}
}

#endif // Trinity_AES_h__
