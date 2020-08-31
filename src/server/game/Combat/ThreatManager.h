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

#ifndef _THREATMANAGER
#define _THREATMANAGER

#include "Common.h"
#include "SharedDefines.h"
#include "LinkedReference/Reference.h"
#include "UnitEvents.h"
#include "ObjectGuid.h"
#include "IteratorPair.h"

#include <list>

//==============================================================

class Unit;
class Creature;
class ThreatManager;
class SpellInfo;

#define THREAT_UPDATE_INTERVAL 1 * IN_MILLISECONDS    // Server should send threat update to client periodically each second

//==============================================================
// Class to calculate the real threat based

struct TC_GAME_API ThreatCalcHelper
{
    static float calcThreat(Unit* hatedUnit, Unit* hatingUnit, float threat, SpellSchoolMask schoolMask = SPELL_SCHOOL_MASK_NORMAL, SpellInfo const* threatSpell = nullptr);
    static bool isValidProcess(Unit* hatedUnit, Unit* hatingUnit, SpellInfo const* threatSpell = nullptr);
};

//==============================================================
class TC_GAME_API HostileReference : public Reference<Unit, ThreatManager>
{
    public:
        HostileReference(Unit* refUnit, ThreatManager* threatManager, float threat);

        // -- compatibility layer for combat rewrite (PR #19930)
        Unit* GetOwner() const;
        Unit* GetVictim() const { return getTarget(); }
        void AddThreat(float amt) { addThreat(amt); }
        void SetThreat(float amt) { setThreat(amt); }
        void ModifyThreatByPercent(int32 pct) { addThreatPercent(pct); }
        void ScaleThreat(float factor) { setThreat(iThreat*factor); }
        bool IsOnline() const { return iOnline; }
        bool IsAvailable() const { return iOnline; }
        bool IsOffline() const { return !iOnline; }
        float GetThreat() const { return getThreat(); }
        void ClearThreat() { removeReference(); }

        //=================================================
        void addThreat(float modThreat);

        void setThreat(float threat) { addThreat(threat - iThreat); }

        void addThreatPercent(int32 percent);

        float getThreat() const { return iThreat + iTempThreatModifier; }

        bool isOnline() const { return iOnline; }

        // The Unit might be in water and the creature can not enter the water, but has range attack
        // in this case online = true, but accessible = false
        bool isAccessible() const { return iAccessible; }

        // used for temporary setting a threat and reducing it later again.
        // the threat modification is stored
        void setTempThreat(float threat)
        {
            addTempThreat(threat - iTempThreatModifier);
        }

        void addTempThreat(float threat)
        {
            if (!threat)
                return;

            iTempThreatModifier += threat;

            ThreatRefStatusChangeEvent event(UEV_THREAT_REF_THREAT_CHANGE, this, threat);
            fireStatusChanged(event);
        }

        void resetTempThreat()
        {
            addTempThreat(-iTempThreatModifier);
        }

        float getTempThreatModifier() { return iTempThreatModifier; }

        //=================================================
        // check, if source can reach target and set the status
        void updateOnlineStatus();

        void setOnlineOfflineState(bool isOnline);

        void setAccessibleState(bool isAccessible);
        //=================================================

        bool operator==(HostileReference const& hostileRef) const { return hostileRef.getUnitGuid() == getUnitGuid(); }

        //=================================================

        ObjectGuid getUnitGuid() const { return iUnitGuid; }

        //=================================================
        // reference is not needed anymore. realy delete it !

        void removeReference();

        //=================================================

        HostileReference* next() { return static_cast<HostileReference*>(Reference<Unit, ThreatManager>::next()); }

        //=================================================

        // Tell our refTo (target) object that we have a link
        void targetObjectBuildLink() override;

        // Tell our refTo (taget) object, that the link is cut
        void targetObjectDestroyLink() override;

        // Tell our refFrom (source) object, that the link is cut (Target destroyed)
        void sourceObjectDestroyLink() override;

    private:
        // Inform the source, that the status of that reference was changed
        void fireStatusChanged(ThreatRefStatusChangeEvent& threatRefStatusChangeEvent);

        Unit* GetSourceUnit();

    private:
        float iThreat;
        float iTempThreatModifier;                          // used for SPELL_AURA_MOD_TOTAL_THREAT

        ObjectGuid iUnitGuid;
        bool iOnline;
        bool iAccessible;
};

//==============================================================
class ThreatManager;

class TC_GAME_API ThreatContainer
{
        friend class ThreatManager;

    public:
        typedef std::list<HostileReference*> StorageType;

        ThreatContainer(): iDirty(false) { }

        ~ThreatContainer() { clearReferences(); }

        HostileReference* addThreat(Unit* victim, float threat);

        void ModifyThreatByPercent(Unit* victim, int32 percent);

        HostileReference* selectNextVictim(Creature* attacker, HostileReference* currentVictim) const;

        void setDirty(bool isDirty) { iDirty = isDirty; }

        bool isDirty() const { return iDirty; }

        bool empty() const
        {
            return iThreatList.empty();
        }

        HostileReference* getMostHated() const
        {
            return iThreatList.empty() ? nullptr : iThreatList.front();
        }

        HostileReference* getReferenceByTarget(Unit const* victim) const;

        StorageType const & getThreatList() const { return iThreatList; }

    private:
        void remove(HostileReference* hostileRef)
        {
            iThreatList.remove(hostileRef);
        }

        void addReference(HostileReference* hostileRef)
        {
            iThreatList.push_back(hostileRef);
        }

        void clearReferences();

        // Sort the list if necessary
        void update();

        StorageType iThreatList;
        bool iDirty;
};

//=================================================

typedef HostileReference ThreatReference;
class TC_GAME_API ThreatManager
{
    public:
        // -- compatibility layer for combat rewrite (PR #19930)
        Trinity::IteratorPair<std::list<ThreatReference*>::const_iterator> GetSortedThreatList() const { auto& list = iThreatContainer.getThreatList(); return { list.cbegin(), list.cend() }; }
        Trinity::IteratorPair<std::list<ThreatReference*>::const_iterator> GetUnsortedThreatList() const { return GetSortedThreatList(); }
        std::list<ThreatReference*> GetModifiableThreatList() const { return iThreatContainer.getThreatList(); }
        Unit* SelectVictim() { return getHostilTarget(); }
        Unit* GetCurrentVictim() const { if (ThreatReference* ref = getCurrentVictim()) return ref->GetVictim(); else return nullptr; }
        bool IsThreatListEmpty(bool includeOffline = false) const { return includeOffline ? areThreatListsEmpty() : isThreatListEmpty(); }
        bool IsThreatenedBy(Unit const* who, bool includeOffline = false) const { return (FindReference(who, includeOffline) != nullptr); }
        size_t GetThreatListSize() const { return iThreatContainer.iThreatList.size(); }
        void ForwardThreatForAssistingMe(Unit* victim, float amount, SpellInfo const* spell, bool ignoreModifiers = false, bool ignoreRedirection = false);
        Unit* GetAnyTarget() const { auto const& list = getThreatList(); if (!list.empty()) return list.front()->getTarget(); return nullptr; }
        void ResetThreat(Unit const* who) { if (auto* ref = FindReference(who, true)) ref->setThreat(0.0f); }
        void ResetAllThreat() { resetAllAggro(); }
        float GetThreat(Unit const* who, bool includeOffline = false) const { if (auto* ref = FindReference(who, includeOffline)) return ref->GetThreat(); return 0.0f; }
        void ClearThreat(Unit const* who) { if (auto* ref = FindReference(who, true)) ref->removeReference(); }
        void ClearAllThreat();
        void AddThreat(Unit* victim, float amount, SpellInfo const* spell = nullptr, bool ignoreModifiers = false, bool ignoreRedirection = false);
    private:
        HostileReference* FindReference(Unit const* who, bool includeOffline) const { if (auto* ref = iThreatContainer.getReferenceByTarget(who)) return ref; if (includeOffline) if (auto* ref = iThreatOfflineContainer.getReferenceByTarget(who)) return ref; return nullptr; }

    public:

        friend class HostileReference;

        explicit ThreatManager(Unit* owner);

        ~ThreatManager() { clearReferences(); }

        void clearReferences();

        void addThreat(Unit* victim, float threat, SpellSchoolMask schoolMask = SPELL_SCHOOL_MASK_NORMAL, SpellInfo const* threatSpell = nullptr);

        void doAddThreat(Unit* victim, float threat);

        void ModifyThreatByPercent(Unit* victim, int32 percent);

        float getThreat(Unit* victim, bool alsoSearchOfflineList = false);

        bool isThreatListEmpty() const { return iThreatContainer.empty(); }
        bool areThreatListsEmpty() const { return iThreatContainer.empty() && iThreatOfflineContainer.empty(); }

        void processThreatEvent(ThreatRefStatusChangeEvent* threatRefStatusChangeEvent);

        bool isNeedUpdateToClient(uint32 time);

        HostileReference* getCurrentVictim() const { return iCurrentVictim; }

        Unit* GetOwner() const { return iOwner; }

        Unit* getHostilTarget();

        void tauntApply(Unit* taunter);
        void tauntFadeOut(Unit* taunter);

        void setCurrentVictim(HostileReference* hostileRef);

        void setDirty(bool isDirty) { iThreatContainer.setDirty(isDirty); }

        // Reset all aggro without modifying the threadlist.
        void resetAllAggro();

        // Reset all aggro of unit in threadlist satisfying the predicate.
        template<class PREDICATE> void resetAggro(PREDICATE predicate)
        {
            ThreatContainer::StorageType &threatList = iThreatContainer.iThreatList;
            if (threatList.empty())
                return;

            for (ThreatContainer::StorageType::iterator itr = threatList.begin(); itr != threatList.end(); ++itr)
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
        ThreatContainer::StorageType const & getThreatList() const { return iThreatContainer.getThreatList(); }
        ThreatContainer::StorageType const & getOfflineThreatList() const { return iThreatOfflineContainer.getThreatList(); }
        ThreatContainer& getOnlineContainer() { return iThreatContainer; }
        ThreatContainer& getOfflineContainer() { return iThreatOfflineContainer; }
    private:
        void _addThreat(Unit* victim, float threat);

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
            ThreatOrderPred(bool ascending = false) : m_ascending(ascending) { }
            bool operator() (HostileReference const* a, HostileReference const* b) const
            {
                return m_ascending ? a->getThreat() < b->getThreat() : a->getThreat() > b->getThreat();
            }
        private:
            const bool m_ascending;
    };
}
#endif
