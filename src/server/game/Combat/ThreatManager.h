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

#ifndef _THREATMANAGER
#define _THREATMANAGER

#include "Common.h"
#include "SharedDefines.h"
#include "LinkedReference/Reference.h"
#include "UnitEvents.h"

#include <list>

//==============================================================

class Unit;
class Creature;
class ThreatManager;
struct SpellEntry;

#define THREAT_UPDATE_INTERVAL 1 * IN_MILLISECONDS    // Server should send threat update to client periodically each second

//==============================================================
// Class to calculate the real threat based

class ThreatCalcHelper
{
    public:
        static float calcThreat(Unit* pHatedUnit, Unit* pHatingUnit, float fThreat, SpellSchoolMask schoolMask = SPELL_SCHOOL_MASK_NORMAL, SpellEntry const *threatSpell = NULL);
};

//==============================================================
class HostileReference : public Reference<Unit, ThreatManager>
{
    public:
        HostileReference(Unit* pUnit, ThreatManager *pThreatManager, float fThreat);

        //=================================================
        void addThreat(float fModThreat);

        void setThreat(float fThreat) { addThreat(fThreat - getThreat()); }

        void addThreatPercent(int32 pPercent)
        {
            float tmpThreat = iThreat;
            AddPctN(tmpThreat, pPercent);
            addThreat(tmpThreat - iThreat);
        }

        float getThreat() const { return iThreat; }

        bool isOnline() const { return iOnline; }

        // The Unit might be in water and the creature can not enter the water, but has range attack
        // in this case online = true, but accessible = false
        bool isAccessible() const { return iAccessible; }

        // used for temporary setting a threat and reducting it later again.
        // the threat modification is stored
        void setTempThreat(float fThreat)
        {
            addTempThreat(fThreat - getThreat());
        }

        void addTempThreat(float fThreat)
        {
            iTempThreatModifier = fThreat;
            if (iTempThreatModifier != 0.0f)
                addThreat(iTempThreatModifier);
        }

        void resetTempThreat()
        {
            if (iTempThreatModifier != 0.0f)
            {
                addThreat(-iTempThreatModifier);
                iTempThreatModifier = 0.0f;
            }
        }

        float getTempThreatModifier() { return iTempThreatModifier; }

        //=================================================
        // check, if source can reach target and set the status
        void updateOnlineStatus();

        void setOnlineOfflineState(bool pIsOnline);

        void setAccessibleState(bool pIsAccessible);
        //=================================================

        bool operator == (const HostileReference& pHostileReference) const { return pHostileReference.getUnitGuid() == getUnitGuid(); }

        //=================================================

        uint64 getUnitGuid() const { return iUnitGuid; }

        //=================================================
        // reference is not needed anymore. realy delete it !

        void removeReference();

        //=================================================

        HostileReference* next() { return ((HostileReference*) Reference<Unit, ThreatManager>::next()); }

        //=================================================

        // Tell our refTo (target) object that we have a link
        void targetObjectBuildLink();

        // Tell our refTo (taget) object, that the link is cut
        void targetObjectDestroyLink();

        // Tell our refFrom (source) object, that the link is cut (Target destroyed)
        void sourceObjectDestroyLink();
    private:
        // Inform the source, that the status of that reference was changed
        void fireStatusChanged(ThreatRefStatusChangeEvent& pThreatRefStatusChangeEvent);

        Unit* getSourceUnit();
    private:
        float iThreat;
        float iTempThreatModifier;                          // used for taunt
        uint64 iUnitGuid;
        bool iOnline;
        bool iAccessible;
};

//==============================================================
class ThreatManager;

class ThreatContainer
{
    private:
        std::list<HostileReference*> iThreatList;
        bool iDirty;
    protected:
        friend class ThreatManager;

        void remove(HostileReference* pRef) { iThreatList.remove(pRef); }
        void addReference(HostileReference* pHostileReference) { iThreatList.push_back(pHostileReference); }
        void clearReferences();
        // Sort the list if necessary
        void update();
    public:
        ThreatContainer() { iDirty = false; }
        ~ThreatContainer() { clearReferences(); }

        HostileReference* addThreat(Unit* pVictim, float fThreat);

        void modifyThreatPercent(Unit *pVictim, int32 iPercent);

        HostileReference* selectNextVictim(Creature* pAttacker, HostileReference* pCurrentVictim);

        void setDirty(bool pDirty) { iDirty = pDirty; }

        bool isDirty() const { return iDirty; }

        bool empty() const { return(iThreatList.empty()); }

        HostileReference* getMostHated() { return iThreatList.empty() ? NULL : iThreatList.front(); }

        HostileReference* getReferenceByTarget(Unit* pVictim);

        std::list<HostileReference*>& getThreatList() { return iThreatList; }
};

//=================================================

class ThreatManager
{
    public:
        friend class HostileReference;

        explicit ThreatManager(Unit *pOwner);

        ~ThreatManager() { clearReferences(); }

        void clearReferences();

        void addThreat(Unit* pVictim, float fThreat, SpellSchoolMask schoolMask = SPELL_SCHOOL_MASK_NORMAL, SpellEntry const *threatSpell = NULL);
        void modifyThreatPercent(Unit *pVictim, int32 iPercent);

        float getThreat(Unit *pVictim, bool pAlsoSearchOfflineList = false);

        bool isThreatListEmpty() { return iThreatContainer.empty(); }

        void processThreatEvent(ThreatRefStatusChangeEvent* threatRefStatusChangeEvent);

        bool isNeedUpdateToClient(uint32 time);

        HostileReference* getCurrentVictim() { return iCurrentVictim; }

        Unit* getOwner() { return iOwner; }

        Unit* getHostilTarget();

        void tauntApply(Unit* pTaunter);
        void tauntFadeOut(Unit *pTaunter);

        void setCurrentVictim(HostileReference* pHostileReference);

        void setDirty(bool bDirty) { iThreatContainer.setDirty(bDirty); }

        // Reset all aggro without modifying the threadlist.
        void resetAllAggro();

        // Reset all aggro of unit in threadlist satisfying the predicate.
        template<class PREDICATE> void resetAggro(PREDICATE predicate)
        {
            std::list<HostileReference*> &threatlist = getThreatList();
            if (threatlist.empty())
                return;

            for (std::list<HostileReference*>::iterator itr = threatlist.begin(); itr != threatlist.end(); ++itr)
            {
                HostileReference* ref = (*itr);

                if (predicate(ref->getTarget()))
                {
                    ref->setThreat(0);
                    setDirty(true);
                }
            }
        }

        // methods to access the lists from the outside to do some dirty manipulation (scriping and such)
        // I hope they are used as little as possible.
        std::list<HostileReference*>& getThreatList() { return iThreatContainer.getThreatList(); }
        std::list<HostileReference*>& getOfflieThreatList() { return iThreatOfflineContainer.getThreatList(); }
        ThreatContainer& getOnlineContainer() { return iThreatContainer; }
        ThreatContainer& getOfflineContainer() { return iThreatOfflineContainer; }
    private:
        void _addThreat(Unit *pVictim, float fThreat);

        HostileReference* iCurrentVictim;
        Unit* iOwner;
        uint32 iUpdateTimer;
        ThreatContainer iThreatContainer;
        ThreatContainer iThreatOfflineContainer;
};

//=================================================

namespace Trinity
{
    // Binary predicate for sorting HostileReferences based on threat value
    class ThreatOrderPred
    {
        public:
            ThreatOrderPred(bool ascending = false) : m_ascending(ascending) {}
            bool operator() (const HostileReference *a, const HostileReference *b) const
            {
                return m_ascending ? a->getThreat() < b->getThreat() : a->getThreat() > b->getThreat();
            }
        private:
            const bool m_ascending;
    };
}
#endif

