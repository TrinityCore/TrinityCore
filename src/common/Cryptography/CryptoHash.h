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

#ifndef TRINITY_CRYPTOHASH_H
#define TRINITY_CRYPTOHASH_H

#include "CryptoConstants.h"
#include "Define.h"
#include "Errors.h"
#include <array>
#include <string>
//#include <string_view>
#include <openssl/evp.h>
#include <cstring>
#include "advstd.h" // data/size

class BigNumber;

namespace Trinity
{
namespace Impl
{
    struct GenericHashImpl
    {
        typedef EVP_MD const* (*HashCreator)();

#if defined(OPENSSL_VERSION_NUMBER) && OPENSSL_VERSION_NUMBER < 0x10100000L
        static EVP_MD_CTX* MakeCTX() { return EVP_MD_CTX_create(); }
        static void DestroyCTX(EVP_MD_CTX* ctx) { EVP_MD_CTX_destroy(ctx); }
#else
        static EVP_MD_CTX* MakeCTX() { return EVP_MD_CTX_new(); }
        static void DestroyCTX(EVP_MD_CTX* ctx) { EVP_MD_CTX_free(ctx); }
#endif
    };

    template <GenericHashImpl::HashCreator HashCreator, size_t DigestLength>
    class GenericHash
    {
        public:
            static constexpr size_t DIGEST_LENGTH = DigestLength;
            using Digest = std::array<uint8, DIGEST_LENGTH>;

            static Digest GetDigestOf(uint8 const* data, size_t len)
            {
                GenericHash hash;
                hash.UpdateData(data, len);
                hash.Finalize();
                return hash.GetDigest();
            }

        private: // c++17
            template <typename T>
            static void UpdateData_OLDCPP(GenericHash& hash, T const& data)
            {
                hash.UpdateData(data);
            }

            template <typename T, typename... TRest>
            static void UpdateData_OLDCPP(GenericHash& hash, T const& data, TRest&&... rest)
            {
                hash.UpdateData(data);
                UpdateData_OLDCPP(hash, std::forward<TRest>(rest)...);
            }

        public:
            template <typename... Ts>
            static auto GetDigestOf(Ts&&... pack) -> std::enable_if_t<advstd::conjunction<advstd::negation<std::is_integral<Ts>>...>::value, Digest>
            {
                GenericHash hash;
                UpdateData_OLDCPP(hash, std::forward<Ts>(pack)...);
                hash.Finalize();
                return hash.GetDigest();
            }

            GenericHash() : _ctx(GenericHashImpl::MakeCTX())
            {
                int result = EVP_DigestInit_ex(_ctx, HashCreator(), nullptr);
                ASSERT(result == 1);
            }

            ~GenericHash()
            {
                if (!_ctx)
                    return;
                GenericHashImpl::DestroyCTX(_ctx);
                _ctx = nullptr;
            }

            void UpdateData(uint8 const* data, size_t len)
            {
                int result = EVP_DigestUpdate(_ctx, data, len);
                ASSERT(result == 1);
            }
            // c++17 void UpdateData(std::string_view str) { UpdateData(reinterpret_cast<uint8 const*>(str.data()), str.size()); }
            void UpdateData(std::string const& str) { UpdateData(str.c_str()); } /* explicit overload to avoid using the container template */
            void UpdateData(char const* str) { UpdateData(reinterpret_cast<uint8 const*>(str), strlen(str)); } /* explicit overload to avoid using the container template */
            template <typename Container>
            void UpdateData(Container const& c) { UpdateData(advstd::data(c), advstd::size(c)); }

            void Finalize()
            {
                uint32 length;
                int result = EVP_DigestFinal_ex(_ctx, _digest.data(), &length);
                ASSERT(result == 1);
                ASSERT(length == DIGEST_LENGTH);
                GenericHashImpl::DestroyCTX(_ctx);
                _ctx = nullptr;
            }

            Digest const& GetDigest() const { return _digest; }

        private:
            EVP_MD_CTX* _ctx;
            Digest _digest = { };
    };
}
}

namespace Trinity
{
namespace Crypto
{
    using SHA1 = Trinity::Impl::GenericHash<EVP_sha1, Constants::SHA1_DIGEST_LENGTH_BYTES>;
    using SHA256 = Trinity::Impl::GenericHash<EVP_sha256, Constants::SHA256_DIGEST_LENGTH_BYTES>;
}
}

#endif
