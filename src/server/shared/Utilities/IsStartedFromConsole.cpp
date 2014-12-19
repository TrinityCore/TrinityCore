/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com>
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

#include "Utilities/IsStartedFromConsole.h"

#include <CompilerDefs.h>

#if PLATFORM == PLATFORM_WINDOWS
#include <windows.h>
#endif

bool IsStartedFromConsole()
{
#if PLATFORM == PLATFORM_WINDOWS
    //! \note see http://support.microsoft.com/kb/99115, method 1
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    return GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
        && csbi.dwCursorPosition.X == 0 && csbi.dwCursorPosition.Y == 0;
#else
    return true;
#endif
}
