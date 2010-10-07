/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

#ifndef __ADDONHANDLER_H
#define __ADDONHANDLER_H

#include "Common.h"
#include "Config.h"
#include <ace/Singleton.h>
#include "WorldPacket.h"

class AddonHandler
{
    /* Construction */
    friend class ACE_Singleton<AddonHandler, ACE_Null_Mutex>;
    AddonHandler();

    public:
        ~AddonHandler();
                                                            //build addon packet
        bool BuildAddonPacket(WorldPacket* Source, WorldPacket* Target);
};
#define sAddOnHandler ACE_Singleton<AddonHandler, ACE_Null_Mutex>::instance()
#endif

