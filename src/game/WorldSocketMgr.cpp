/*
 * Copyright (C) 2005-2008,2007 MaNGOS <http://www.mangosproject.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/** \file
    \ingroup u2w
*/

#include "Common.h"
#include "WorldSocket.h"
#include "WorldSocketMgr.h"
#include "Policies/SingletonImp.h"

INSTANTIATE_SINGLETON_1( WorldSocketMgr );

/// WorldSocketMgr constructor
WorldSocketMgr::WorldSocketMgr()
{
}

/// Add a WorldSocket to the set
void WorldSocketMgr::AddSocket(WorldSocket *s)
{
    m_sockets.insert(s);
}

/// Remove a WorldSocket to the set
void WorldSocketMgr::RemoveSocket(WorldSocket *s)
{
    m_sockets.erase(s);
}

/// Triggers an 'update' to all sockets in the set
void WorldSocketMgr::Update(time_t diff)
{
    SocketSet::iterator i;
    for(i = m_sockets.begin(); i != m_sockets.end(); i++)
    {
        (*i)->Update(diff);
    }
}
