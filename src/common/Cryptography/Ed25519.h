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

#ifndef TRINITYCORE_ED25519_H
#define TRINITYCORE_ED25519_H

#include "Define.h"
#include <array>
#include <string>
#include <vector>
#include <openssl/evp.h>

class BigNumber;

namespace Trinity::Crypto
{
class TC_COMMON_API Ed25519
{
public:
    Ed25519();
    Ed25519(Ed25519 const& right);
    Ed25519(Ed25519&& right) noexcept;
    ~Ed25519();

    Ed25519& operator=(Ed25519 const& right);
    Ed25519& operator=(Ed25519&& right) noexcept;

    bool LoadFromFile(std::string const& fileName);

    bool LoadFromString(std::string const& keyPem);

    bool LoadFromByteArray(std::array<uint8, 32> const& keyBytes);

    template <std::size_t N>
    bool Sign(std::array<uint8, N> const& message, std::vector<uint8>& output)
    {
        return this->Sign(message.data(), message.size(), output);
    }

    bool Sign(uint8 const* message, std::size_t messageLength, std::vector<uint8>& output);

    template <std::size_t N>
    bool SignWithContext(std::array<uint8, N> const& message, std::vector<uint8> const& context, std::vector<uint8>& output)
    {
        return this->SignWithContext(message.data(), message.size(), context, output);
    }

    bool SignWithContext(uint8 const* message, std::size_t messageLength, std::vector<uint8> const& context, std::vector<uint8>& output);

private:
    EVP_PKEY* _key = nullptr;
};
}

#endif // TRINITYCORE_ED25519_H
