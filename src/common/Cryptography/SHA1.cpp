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

SHA1Hash::SHA1Hash()
{
    SHA1_Init(&mC);
    memset(mDigest, 0, SHA_DIGEST_LENGTH * sizeof(uint8));
}

SHA1Hash::~SHA1Hash()
{
    SHA1_Init(&mC);
}

void SHA1Hash::UpdateData(const uint8 *dta, int len)
{
    SHA1_Update(&mC, dta, len);
}

void SHA1Hash::UpdateData(BigNumber const& bn)
{
    UpdateData(bn.AsByteArray().get(), bn.GetNumBytes());
}

void SHA1Hash::UpdateData(const std::string& str)
{
    UpdateData((uint8 const*)str.c_str(), str.length());
}

void SHA1Hash::Initialize()
{
    SHA1_Init(&mC);
}

void SHA1Hash::Finalize(void)
{
    SHA1_Final(mDigest, &mC);
}

std::string CalculateSHA1Hash(std::string const& content)
{
    SHA1Hash hash;
    hash.UpdateData(content);
    hash.Finalize();
    return ByteArrayToHexStr(hash.GetDigest(), SHA1Hash::HASH_LEN);
}
