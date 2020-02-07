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
 
#ifndef TRINITY_CRYPTO_GENERICS_HPP
#define TRINITY_CRYPTO_GENERICS_HPP

#include "advstd.h"
#include "BigNumber.h"
#include "Define.h"
#include "Errors.h"
#include <vector>
#include <openssl/rand.h>

namespace Trinity
{
    namespace Impl
    {
        struct CryptoGenericsImpl
        {
            template <typename Cipher>
            static typename Cipher::IV GenerateRandomIV()
            {
                typename Cipher::IV iv;
                int status = RAND_bytes(advstd::data(iv), advstd::size(iv));
                ASSERT(status);
                return iv;
            }

            template <typename C>
            static void AppendToBack(std::vector<uint8>& data, C const& tail)
            {
                data.insert(data.end(), std::begin(tail), std::end(tail));
            }

            template <typename C>
            static void SplitFromBack(std::vector<uint8>& data, C& tail)
            {
                ASSERT(data.size() >= advstd::size(tail));
                for (size_t i = 1, N = advstd::size(tail); i <= N; ++i)
                {
                    tail[N - i] = data.back();
                    data.pop_back();
                }
            }
        };
    }

    namespace Crypto
    {
        template <typename Cipher>
        void AEEncryptWithRandomIV(std::vector<uint8>& data, typename Cipher::Key const& key)
        {
            using IV = typename Cipher::IV;
            using Tag = typename Cipher::Tag;
            // select random IV
            IV iv = Trinity::Impl::CryptoGenericsImpl::GenerateRandomIV<Cipher>();
            Tag tag;

            // encrypt data
            Cipher cipher(true);
            cipher.Init(key);
            bool success = cipher.Process(iv, data.data(), data.size(), tag);
            ASSERT(success);

            // append trailing IV and tag
            Trinity::Impl::CryptoGenericsImpl::AppendToBack(data, iv);
            Trinity::Impl::CryptoGenericsImpl::AppendToBack(data, tag);
        }

        template <typename Cipher>
        void AEEncryptWithRandomIV(std::vector<uint8>& data, BigNumber const& key)
        {
            AEEncryptWithRandomIV<Cipher>(data, key.AsByteArray<Cipher::KEY_SIZE_BYTES>());
        }

        template <typename Cipher>
        bool AEDecrypt(std::vector<uint8>& data, typename Cipher::Key const& key)
        {
            using IV = typename Cipher::IV;
            using Tag = typename Cipher::Tag;
            // extract trailing IV and tag
            IV iv;
            Tag tag;
            Trinity::Impl::CryptoGenericsImpl::SplitFromBack(data, tag);
            Trinity::Impl::CryptoGenericsImpl::SplitFromBack(data, iv);

            // decrypt data
            Cipher cipher(false);
            cipher.Init(key);
            return cipher.Process(iv, data.data(), data.size(), tag);
        }

        template <typename Cipher>
        bool AEDecrypt(std::vector<uint8>& data, BigNumber const& key)
        {
            return AEDecrypt<Cipher>(data, key.AsByteArray<Cipher::KEY_SIZE_BYTES>());
        }
    }
}

#endif
