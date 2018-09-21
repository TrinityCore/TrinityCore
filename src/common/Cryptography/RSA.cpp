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

#include "RSA.h"
#include "BigNumber.h"
#include <openssl/bn.h>
#include <openssl/pem.h>
#include <algorithm>
#include <iterator>
#include <memory>
#include <vector>

#define CHECK_AND_DECLARE_FUNCTION_TYPE(name, publicKey, privateKey)                                        \
    static_assert(std::is_same<decltype(&publicKey), decltype(&privateKey)>::value,                         \
        "Public key and private key functions must have the same signature");                               \
    using name ## _t = decltype(&publicKey);                                                                \
    template <typename KeyTag> inline name ## _t get_ ## name () { return nullptr; }                        \
    template <> inline name ## _t get_ ## name<Trinity::Crypto::RSA::PublicKey>() { return &publicKey; }    \
    template <> inline name ## _t get_ ## name<Trinity::Crypto::RSA::PrivateKey>() { return &privateKey; }

namespace
{
struct BIODeleter
{
    void operator()(BIO* bio)
    {
        BIO_free(bio);
    }
};

CHECK_AND_DECLARE_FUNCTION_TYPE(PEM_read, PEM_read_bio_RSAPublicKey, PEM_read_bio_RSAPrivateKey);
CHECK_AND_DECLARE_FUNCTION_TYPE(RSA_encrypt, RSA_public_encrypt, RSA_private_encrypt);
}

Trinity::Crypto::RSA::RSA()
{
    _rsa = RSA_new();
}

Trinity::Crypto::RSA::RSA(RSA&& rsa)
{
    _rsa = rsa._rsa;
    rsa._rsa = RSA_new();
}

Trinity::Crypto::RSA::~RSA()
{
    RSA_free(_rsa);
}

template <typename KeyTag>
bool Trinity::Crypto::RSA::LoadFromFile(std::string const& fileName, KeyTag)
{
    std::unique_ptr<BIO, BIODeleter> keyBIO(BIO_new_file(fileName.c_str(), "r"));
    if (!keyBIO)
        return false;

    if (!get_PEM_read<KeyTag>()(keyBIO.get(), &_rsa, nullptr, nullptr))
        return false;

    return true;
}

template <typename KeyTag>
bool Trinity::Crypto::RSA::LoadFromString(std::string const& keyPem, KeyTag)
{
    std::unique_ptr<BIO, BIODeleter> keyBIO(BIO_new_mem_buf(
        const_cast<char*>(keyPem.c_str()) /*api hack - this function assumes memory is readonly but lacks const modifier*/,
        keyPem.length() + 1));
    if (!keyBIO)
        return false;

    if (!get_PEM_read<KeyTag>()(keyBIO.get(), &_rsa, nullptr, nullptr))
        return false;

    return true;
}

BigNumber Trinity::Crypto::RSA::GetModulus() const
{
    BigNumber bn;
#if defined(OPENSSL_VERSION_NUMBER) && OPENSSL_VERSION_NUMBER >= 0x10100000L
    const BIGNUM* rsa_n;
    RSA_get0_key(_rsa, &rsa_n, nullptr, nullptr);
    BN_copy(bn.BN(), rsa_n);
#else
    BN_copy(bn.BN(), _rsa->n);
#endif
    return bn;
}

template <typename KeyTag>
bool Trinity::Crypto::RSA::Encrypt(uint8 const* data, std::size_t dataLength, uint8* output, int32 paddingType)
{
    std::vector<uint8> inputData(std::make_reverse_iterator(data + dataLength), std::make_reverse_iterator(data));
    int result = get_RSA_encrypt<KeyTag>()(inputData.size(), inputData.data(), output, _rsa, paddingType);
    std::reverse(output, output + GetOutputSize());
    return result != -1;
}

bool Trinity::Crypto::RSA::Sign(int32 hashType, uint8 const* dataHash, std::size_t dataHashLength, uint8* output)
{
    uint32 signatureLength = 0;
    int result = RSA_sign(hashType, dataHash, dataHashLength, output, &signatureLength, _rsa);
    std::reverse(output, output + GetOutputSize());
    return result != -1;
}

namespace Trinity
{
namespace Crypto
{
    template TC_COMMON_API bool RSA::LoadFromFile(std::string const& fileName, RSA::PublicKey);
    template TC_COMMON_API bool RSA::LoadFromFile(std::string const& fileName, RSA::PrivateKey);
    template TC_COMMON_API bool RSA::LoadFromString(std::string const& keyPem, RSA::PublicKey);
    template TC_COMMON_API bool RSA::LoadFromString(std::string const& keyPem, RSA::PrivateKey);
    template TC_COMMON_API bool RSA::Encrypt<RSA::PublicKey>(uint8 const* data, std::size_t dataLength, uint8* output, int32 paddingType);
    template TC_COMMON_API bool RSA::Encrypt<RSA::PrivateKey>(uint8 const* data, std::size_t dataLength, uint8* output, int32 paddingType);
}
}
