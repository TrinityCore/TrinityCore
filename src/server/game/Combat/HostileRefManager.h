/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

#ifndef _HOSTILEREFMANAGER
#define _HOSTILEREFMANAGER

#include "Common.h"
#include "RefManager.h"

class Unit;
class ThreatManager;
class HostileReference;
class SpellInfo;

//=================================================

class HostileRefManager : public RefManager<Unit, ThreatManager>
{
    private:
        Unit *iOwner;
    public:
        explicit HostileRefManager(Unit *pOwner) { iOwner = pOwner; }
        ~HostileRefManager();

        Unit* getOwner() { return iOwner; }

        // send threat to all my hateres for the pVictim
        // The pVictim is hated than by them as well
        // use for buffs and healing threat functionality
        void threatAssist(Unit *pVictim, float fThreat, SpellInfo const *threatSpell = 0, bool pSingleTarget = false);

        void addTempThreat(float fThreat, bool apply);

        void addThreatPercent(int32 iPercent);

        // The references are not needed anymore
        // tell the source to remove them from the list and free the mem
        void deleteReferences();

        // Remove specific faction references
        void deleteReferencesForFaction(uint32 faction);

        HostileReference* getFirst() { return ((HostileReference*) RefManager<Unit, ThreatManager>::getFirst()); }

        void updateThreatTables();

        void setOnlineOfflineState(bool bIsOnline);

        // set state for one reference, defined by Unit
        void setOnlineOfflineState(Unit *pCreature, bool bIsOnline);

        // delete one reference, defined by Unit
        void deleteReference(Unit *pCreature);

        void UpdateVisibility();
};
//=================================================
#endif

