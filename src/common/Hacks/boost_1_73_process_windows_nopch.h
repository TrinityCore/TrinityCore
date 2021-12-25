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

#ifndef boost_1_73_process_windows_nopch_h__
#define boost_1_73_process_windows_nopch_h__

#include "CompilerDefs.h"
#include <boost/version.hpp>

#if TRINITY_PLATFORM == TRINITY_PLATFORM_WINDOWS && BOOST_VERSION >= 107300 && BOOST_VERSION < 107800
// __kernel_entry for boost/process/detail/windows/handle_workaround.hpp
// DWORD for boost/process/detail/windows/handles.hpp
#include <windows.h>
#endif

#endif // boost_1_73_process_windows_nopch_h__
