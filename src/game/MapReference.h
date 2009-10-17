/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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
#ifndef _MAPREFERENCE_H
#define _MAPREFERENCE_H
#include "Utilities/LinkedReference/Reference.h"
#include "Map.h"
class TRINITY_DLL_SPEC MapReference : public Reference<Map, Player>
{
    protected:
        void targetObjectBuildLink()
        {
            // called from link()
            getTarget()->m_mapRefManager.insertFirst(this);
            getTarget()->m_mapRefManager.incSize();
        }
        void targetObjectDestroyLink()
        {
            // called from unlink()
            if(isValid()) getTarget()->m_mapRefManager.decSize();
        }
        void sourceObjectDestroyLink()
        {
            // called from invalidate()
            getTarget()->m_mapRefManager.decSize();
        }
    public:
        MapReference() : Reference<Map, Player>() {}
        ~MapReference() { unlink(); }
        MapReference *next() { return (MapReference*)Reference<Map, Player>::next(); }
        MapReference const *next() const { return (MapReference const*)Reference<Map, Player>::next(); }
        MapReference *nockeck_prev() { return (MapReference*)Reference<Map, Player>::nocheck_prev(); }
        MapReference const *nocheck_prev() const { return (MapReference const*)Reference<Map, Player>::nocheck_prev(); }
};
#endif

