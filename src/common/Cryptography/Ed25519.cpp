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

#include "Ed25519.h"
#include "CryptoHash.h"
#include "Memory.h"
#include <ed25519/ed25519.h>
#include <openssl/pem.h>
#include <memory>

namespace Trinity::Crypto
{
Ed25519::Ed25519() = default;

Ed25519::Ed25519(Ed25519 const& right)
{
    *this = right;
}

Ed25519::Ed25519(Ed25519&& right) noexcept
{
    *this = std::move(right);
}

Ed25519::~Ed25519()
{
    EVP_PKEY_free(_key);
}

Ed25519& Ed25519::operator=(Ed25519 const& right)
{
    if (this == &right)
        return *this;

    _key = right._key;                      // EVP_PKEY uses reference counting internally, just copy the pointer
    EVP_PKEY_up_ref(_key);                  // Bump reference count for PKEY, as every instance of this class holds two references to PKEY and destructor decrements it twice
    return *this;
}

Ed25519& Ed25519::operator=(Ed25519&& right) noexcept
{
    if (this == &right)
        return *this;

    _key = std::exchange(right._key, EVP_PKEY_new());
    return *this;
}

bool Ed25519::LoadFromFile(std::string const& fileName)
{
    if (_key)
    {
        EVP_PKEY_free(_key);
        _key = nullptr;
    }

    auto keyBIO = make_unique_ptr_with_deleter<&BIO_free>(BIO_new_file(fileName.c_str(), "r"));
    if (!keyBIO)
        return false;

    _key = EVP_PKEY_new();
    if (!PEM_read_bio_PrivateKey(keyBIO.get(), &_key, nullptr, nullptr))
        return false;

    return true;
}

bool Ed25519::LoadFromString(std::string const& keyPem)
{
    if (_key)
    {
        EVP_PKEY_free(_key);
        _key = nullptr;
    }

    auto keyBIO = make_unique_ptr_with_deleter<&BIO_free>(BIO_new_mem_buf(
        const_cast<char*>(keyPem.c_str()) /*api hack - this function assumes memory is readonly but lacks const modifier*/,
        keyPem.length() + 1));
    if (!keyBIO)
        return false;

    _key = EVP_PKEY_new();
    if (!PEM_read_bio_PrivateKey(keyBIO.get(), &_key, nullptr, nullptr))
        return false;

    return true;
}

bool Ed25519::LoadFromByteArray(std::array<uint8, 32> const& keyBytes)
{
    if (_key)
    {
        EVP_PKEY_free(_key);
        _key = nullptr;
    }

    _key = EVP_PKEY_new_raw_private_key(EVP_PKEY_ED25519, nullptr, keyBytes.data(), keyBytes.size());
    if (!_key)
        return false;

    return true;
}

bool Ed25519::Sign(uint8 const* message, std::size_t messageLength, std::vector<uint8>& output)
{
    constexpr size_t KeySize = 32;

    uint8 publicKey[KeySize] = {};
    std::size_t keyLength = KeySize;
    EVP_PKEY_get_raw_public_key(_key, publicKey, &keyLength);

    uint8 privateKey[KeySize] = {};
    keyLength = KeySize;
    EVP_PKEY_get_raw_private_key(_key, privateKey, &keyLength);

    output.resize(64);
    int result = ED25519_sign(output.data(), message, messageLength, publicKey, privateKey);
    return result != 0;
}

bool Ed25519::SignWithContext(uint8 const* message, std::size_t messageLength, std::vector<uint8> const& context, std::vector<uint8>& output)
{
    constexpr size_t KeySize = 32;

    uint8 publicKey[KeySize] = {};
    std::size_t keyLength = KeySize;
    EVP_PKEY_get_raw_public_key(_key, publicKey, &keyLength);

    uint8 privateKey[KeySize] = {};
    keyLength = KeySize;
    EVP_PKEY_get_raw_private_key(_key, privateKey, &keyLength);

    output.resize(64);
    int result = ED25519_sign_ctx(output.data(), message, messageLength, publicKey, privateKey, context.data(), context.size());
    return result != 0;
}
}
