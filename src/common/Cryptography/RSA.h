/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#include "Define.h"
#include <openssl/objects.h>
#include <openssl/rsa.h>
#include <string>
#include <type_traits>

class BigNumber;

namespace Trinity
{
namespace Crypto
{
class TC_COMMON_API RSA
{
public:
    struct PublicKey {};
    struct PrivateKey {};

    struct NoPadding : std::integral_constant<int32, RSA_NO_PADDING> {};
    struct PKCS1Padding : std::integral_constant<int32, RSA_PKCS1_PADDING> {};

    struct SHA256 : std::integral_constant<int32, NID_sha256> {};

    RSA();
    RSA(RSA&& rsa);
    ~RSA();

    template <typename KeyTag>
    bool LoadFromFile(std::string const& fileName, KeyTag);

    template <typename KeyTag>
    bool LoadFromString(std::string const& keyPem, KeyTag);

    uint32 GetOutputSize() const { return uint32(RSA_size(_rsa)); }
    BigNumber GetModulus() const;

    template <typename KeyTag, typename PaddingTag>
    bool Encrypt(uint8 const* data, std::size_t dataLength, uint8* output, KeyTag, PaddingTag)
    {
        return Encrypt<KeyTag>(data, dataLength, output, PaddingTag::value);
    }

    template <typename HashTag>
    bool Sign(uint8 const* dataHash, std::size_t dataHashLength, uint8* output, HashTag)
    {
        return Sign(HashTag::value, dataHash, dataHashLength, output);
    }

private:
    template <typename KeyTag>
    bool Encrypt(uint8 const* data, std::size_t dataLength, uint8* output, int32 paddingType);

    bool Sign(int32 hashType, uint8 const* dataHash, std::size_t dataHashLength, uint8* output);

    RSA(RSA const& rsa) = delete;
    RSA& operator=(RSA const& rsa) = delete;

    ::RSA* _rsa;
};
}
}
