/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information

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

#ifndef TRINITYCORE_LOCALE_H
#define TRINITYCORE_LOCALE_H

#include "Define.h"
#include <locale>

namespace Trinity::Locale
{
TC_COMMON_API void Init();
TC_COMMON_API std::locale const& GetGlobalLocale();
TC_COMMON_API std::locale const& GetCalendarLocale();
}

#endif // TRINITYCORE_LOCALE_H
