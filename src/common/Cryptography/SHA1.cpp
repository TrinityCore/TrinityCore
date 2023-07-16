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

#include "SHA1.h"
#include "BigNumber.h"
#include "Util.h"
#include <cstring>
#include <stdarg.h>
#include <openssl/evp.h>

SHA1Hash::SHA1Hash() noexcept
{
    m_ctx = EVP_MD_CTX_new();
    EVP_DigestInit_ex(m_ctx, EVP_sha1(), nullptr);
}

SHA1Hash::SHA1Hash(const SHA1Hash &other) : SHA1Hash() // copy
{
    EVP_MD_CTX_copy_ex(m_ctx, other.m_ctx);
    std::memcpy(m_digest, other.m_digest, SHA_DIGEST_LENGTH);
}

SHA1Hash::SHA1Hash(SHA1Hash &&other) noexcept : SHA1Hash() // move
{
    Swap(other);
}

SHA1Hash &SHA1Hash::operator=(SHA1Hash other) // assign
{
    Swap(other);
    return *this;
}

SHA1Hash::~SHA1Hash()
{
    EVP_MD_CTX_free(m_ctx);
}

void SHA1Hash::Swap(SHA1Hash &other) throw()
{
    std::swap(m_ctx, other.m_ctx);
    std::swap(m_digest, other.m_digest);
}

void SHA1Hash::UpdateData(const uint8 *dta, int len)
{
    EVP_DigestUpdate(m_ctx, dta, len);
}

void SHA1Hash::UpdateData(const std::string &str)
{
    UpdateData((uint8 const*)str.c_str(), str.length());
}

void SHA1Hash::UpdateBigNumbers(BigNumber* bn0, ...)
{
    va_list v;
    BigNumber* bn;

    va_start(v, bn0);
    bn = bn0;
    while (bn)
    {
        UpdateData(bn->AsByteArray().get(), bn->GetNumBytes());
        bn = va_arg(v, BigNumber*);
    }
    va_end(v);
}

void SHA1Hash::Initialize()
{
    EVP_DigestInit(m_ctx, EVP_sha1());
}

void SHA1Hash::Finalize(void)
{
    uint32 length = SHA_DIGEST_LENGTH;
    EVP_DigestFinal_ex(m_ctx, m_digest, &length);
}

std::string CalculateSHA1Hash(std::string const& content)
{
    EVP_MD_CTX* mdctx = EVP_MD_CTX_new();
    EVP_DigestInit_ex(mdctx, EVP_sha1(), nullptr);
    EVP_DigestUpdate(mdctx, content.c_str(), content.size());
    uint8 digest[SHA_DIGEST_LENGTH];
    uint32 shaDigestLength = SHA_DIGEST_LENGTH;
    EVP_DigestFinal_ex(mdctx, digest, &shaDigestLength);
    EVP_MD_CTX_free(mdctx);

    return ByteArrayToHexStr(digest, SHA_DIGEST_LENGTH);
}
