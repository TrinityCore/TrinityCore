/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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

#include <openssl/rsa.h>

namespace Trinity
{
namespace Crypto
{
class RSA
{
public:
    struct NoPadding : std::integral_constant<int32, RSA_NO_PADDING> {};
    struct PKCS1Padding : std::integral_constant<int32, RSA_PKCS1_PADDING> {};

    struct PrivateKey {};
    struct PublicKey {};

    RSA();
    RSA(RSA&& rsa);
    ~RSA();

    template <typename KeyTag>
    bool LoadFromFile(std::string const& fileName, KeyTag);

    template <typename KeyTag>
    bool LoadFromString(std::string const& keyPem, KeyTag);

    uint32 GetOutputSize() const { return uint32(RSA_size(_rsa)); }

    template <typename KeyTag, typename PaddingTag>
    bool Encrypt(uint8 const* data, std::size_t dataLength, uint8* output, KeyTag, PaddingTag)
    {
        return Encrypt<KeyTag>(data, dataLength, output, PaddingTag::value);
    }

private:
    template <typename KeyTag>
    bool Encrypt(uint8 const* data, std::size_t dataLength, uint8* output, int32 paddingType);

    RSA(RSA const& rsa) = delete;
    RSA& operator=(RSA const& rsa) = delete;

    ::RSA* _rsa;
};
}
}
