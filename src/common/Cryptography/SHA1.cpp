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

Trinity::Crypto::SHA1::SHA1()
{
    SHA1_Init(&_ctx);
}

void Trinity::Crypto::SHA1::UpdateData(const uint8 *dta, int len)
{
    SHA1_Update(&_ctx, dta, len);
}

void Trinity::Crypto::SHA1::Finalize(void)
{
    SHA1_Final(_digest.data(), &_ctx);
}
