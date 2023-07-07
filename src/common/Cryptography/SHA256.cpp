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

#include "SHA256.h"
#include "BigNumber.h"
#include "Errors.h"
#include <cstring>
#include <stdarg.h>

SHA256Hash::SHA256Hash() : _ctx(EVP_MD_CTX_create())
{
    EVP_DigestInit_ex(_ctx, EVP_sha256(), nullptr);
    memset(mDigest, 0, SHA256_DIGEST_LENGTH * sizeof(uint8));
}

SHA256Hash::~SHA256Hash()
{
    EVP_MD_CTX_destroy(_ctx);
    _ctx = nullptr;
}

void SHA256Hash::UpdateData(const uint8 *dta, int len)
{
    EVP_DigestUpdate(_ctx, dta, len);
}

void SHA256Hash::UpdateData(const std::string &str)
{
    UpdateData((uint8 const*)str.c_str(), str.length());
}

void SHA256Hash::UpdateBigNumbers(BigNumber* bn0, ...)
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

void SHA256Hash::Initialize()
{
    EVP_DigestInit_ex(_ctx, EVP_sha256(), nullptr);
}

void SHA256Hash::Finalize(void)
{
    uint32 length = SHA256_DIGEST_LENGTH;
    EVP_DigestFinal_ex(_ctx, mDigest, &length);
    ASSERT(length == SHA256_DIGEST_LENGTH);
}
