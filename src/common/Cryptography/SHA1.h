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
#include <string_view>
#include <openssl/sha.h>

class BigNumber;

namespace Trinity
{
namespace Crypto
{
class TC_COMMON_API SHA1
{
    public:
        static constexpr size_t DIGEST_LENGTH = SHA_DIGEST_LENGTH;
        using Digest = std::array<uint8, DIGEST_LENGTH>;

        static Digest GetDigestOf(uint8 const* dta, int len)
        {
            SHA1 hash;
            hash.UpdateData(dta, len);
            hash.Finalize();
            return hash.GetDigest();
        }
        template <typename... Ts>
        static auto GetDigestOf(Ts&&... pack) -> std::enable_if_t<!(std::is_integral_v<std::decay_t<Ts>> || ...), Digest>
        {
            SHA1 hash;
            (hash.UpdateData(std::forward<Ts>(pack)), ...);
            hash.Finalize();
            return hash.GetDigest();
        }

        SHA1();

        void UpdateData(uint8 const* dta, int len);
        void UpdateData(std::string_view const& str) { UpdateData(reinterpret_cast<uint8 const*>(str.data()), str.size()); }
        void UpdateData(std::string const& str) { UpdateData(std::string_view(str)); } /* explicit overload to avoid using the container template */
        void UpdateData(char const* str) { UpdateData(std::string_view(str)); } /* explicit overload to avoid using the container template */
        template <typename Container> void UpdateData(Container const& c) { UpdateData(std::data(c), std::size(c)); }

        void Initialize();
        void Finalize();

        Digest const& GetDigest() const { return _digest; }

    private:
        SHA_CTX _ctx;
        Digest _digest;
};
}
}

#endif
