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

#ifndef TRINITY_HMAC_H
#define TRINITY_HMAC_H

#include "Define.h"
#include "Errors.h"
#include <array>
#include <string>
#include <string_view>
#include <openssl/hmac.h>

class BigNumber;

namespace Trinity {
    namespace Impl {
        struct HMACImpl
        {
            typedef EVP_MD const* (*HashCreator)();

#if defined(OPENSSL_VERSION_NUMBER) && OPENSSL_VERSION_NUMBER < 0x10100000L
            static HMAC_CTX* MakeCTX()
            {
                HMAC_CTX* ctx = new HMAC_CTX();
                HMAC_CTX_init(ctx);
                return ctx;
            }
            static void DestroyCTX(HMAC_CTX* ctx)
            {
                HMAC_CTX_cleanup(ctx);
                delete ctx;
            }
#else
            static HMAC_CTX* MakeCTX() { return HMAC_CTX_new(); }
            static void DestroyCTX(HMAC_CTX* ctx) { HMAC_CTX_free(ctx); }
#endif
        };
    }

    namespace Crypto
    {
        template <Trinity::Impl::HMACImpl::HashCreator HashCreator, size_t DigestLength>
        class HMAC
        {
            public:
                static constexpr size_t DIGEST_LENGTH = DigestLength;
                using Digest = std::array<uint8, DIGEST_LENGTH>;

                static Digest GetDigestOf(uint8 const* seed, size_t seedlen, uint8 const* data, size_t datalen)
                {
                    HMAC hash(seed, seedlen);
                    hash.UpdateData(data, datalen);
                    hash.Finalize();
                    return hash.GetDigest();
                }

                template <typename C>
                static Digest GetDigestOf(C const& seed, uint8 const* data, size_t len)
                {
                    HMAC hash(seed);
                    hash.UpdateData(data, len);
                    hash.Finalize();
                    return hash.GetDigest();
                }

                template <typename... Ts>
                static auto GetDigestOf(uint8 const* seed, size_t len, Ts&&... pack) -> std::enable_if_t<!(std::is_integral_v<std::decay_t<Ts>> || ...), Digest>
                {
                    HMAC hash(seed, len);
                    (hash.UpdateData(std::forward<Ts>(pack)), ...);
                    hash.Finalize();
                    return hash.GetDigest();
                }

                template <typename C, typename... Ts>
                static auto GetDigestOf(C const& seed, Ts&&... pack) -> std::enable_if_t<!(std::is_integral_v<std::decay_t<Ts>> || ...), Digest>
                {
                    HMAC hash(seed);
                    (hash.UpdateData(std::forward<Ts>(pack)), ...);
                    hash.Finalize();
                    return hash.GetDigest();
                }

                HMAC(uint8 const* seed, size_t len)
                {
                    _ctx = Trinity::Impl::HMACImpl::MakeCTX();
                    int result = HMAC_Init_ex(_ctx, seed, len, HashCreator(), nullptr);
                    ASSERT(result == 1);
                }
                template <typename C>
                HMAC(C const& container) : HMAC(std::data(container), std::size(container)) {}

                ~HMAC()
                {
                    Trinity::Impl::HMACImpl::DestroyCTX(_ctx);
                }

                void UpdateData(uint8 const* data, size_t len)
                {
                    int result = HMAC_Update(_ctx, data, len);
                    ASSERT(result == 1);
                }
                void UpdateData(std::string_view const& str) { UpdateData(reinterpret_cast<uint8 const*>(str.data()), str.size()); }
                void UpdateData(std::string const& str) { UpdateData(std::string_view(str)); } /* explicit overload to avoid using the container template */
                void UpdateData(char const* str) { UpdateData(std::string_view(str)); } /* explicit overload to avoid using the container template */
                template <typename Container> void UpdateData(Container const& c) { UpdateData(std::data(c), std::size(c)); }

                void Finalize()
                {
                    uint32 length = 0;
                    int result = HMAC_Final(_ctx, _digest.data(), &length);
                    ASSERT(result == 1);
                    ASSERT(length == DIGEST_LENGTH);
                }

                Digest const& GetDigest() const { return _digest; }
            private:
                HMAC_CTX* _ctx;
                Digest _digest;
        };
    }
}
#endif
