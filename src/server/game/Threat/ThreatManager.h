/*
 * Copyright (C) 2005-2011 MaNGOS <http://getmangos.com/>
 * Copyright (C) 2009-2011 MaNGOSZero <https://github.com/mangos/zero>
 * Copyright (C) 2011-2016 Nostalrius <https://nostalrius.org>
 * Copyright (C) 2016-2017 Elysium Project <https://github.com/elysium-project>
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

#ifndef _THREATMANAGER
#define _THREATMANAGER

#include "Common.h"
#include "SharedDefines.h"
#include "Utilities/LinkedReference/Reference.h"
#include "UnitEvents.h"
#include "ObjectGuid.h"
#include "SpellDefines.h"
#include <list>

//==============================================================

class Unit;
class Creature;
class ThreatManager;
class SpellEntry;

//==============================================================
// Class to calculate the real threat based

class ThreatCalcHelper
{
    public:
        static float CalcThreat(Unit* pHatedUnit, Unit* pHatingUnit, float threat, bool crit, SpellSchoolMask schoolMask, SpellEntry const* threatSpell);
};

//==============================================================
class HostileReference : public Reference<Unit, ThreatManager>
{
    public:
        HostileReference(Unit* pUnit, ThreatManager *pThreatManager, float pThreat);

        //=================================================
        void addThreat(float pMod);

        void setThreat(float pThreat) { addThreat(pThreat - getThreat()); }

        void addThreatPercent(int32 pPercent)
        {
            // for special -100 case avoid rounding
            addThreat(pPercent == -100 ? -iThreat : iThreat * pPercent / 100.0f);
        }

        float getThreat() const { return iThreat; }

        bool isOnline() const { return iOnline; }

        // The Unit might be in water and the creature can not enter the water, but has range attack
        // in this case online = true, but accessable = false
        bool isAccessable() const { return iAccessible; }

        // used for temporary setting a threat and reducting it later again.
        // the threat modification is stored
        void setTempThreat(float pThreat) { iTempThreatModifyer = pThreat - getThreat(); if (iTempThreatModifyer != 0.0f) addThreat(iTempThreatModifyer);  }
        void setTempThreatModifier(float thread) { iTempThreatModifyer = thread; addThreat(iTempThreatModifyer); }

        void resetTempThreat()
        {
            if (iTempThreatModifyer != 0.0f)
            {
                addThreat(-iTempThreatModifyer);  iTempThreatModifyer = 0.0f;
            }
        }

        float getTempThreatModifyer() const { return iTempThreatModifyer; }

        //=================================================
        // check, if source can reach target and set the status
        void updateOnlineStatus();

        void setOnlineOfflineState(bool pIsOnline);

        void setAccessibleState(bool pIsAccessible);
        //=================================================

        bool operator ==(HostileReference const& pHostileReference) const { return pHostileReference.getUnitGuid() == getUnitGuid(); }

        //=================================================

        ObjectGuid const& getUnitGuid() const { return iUnitGuid; }

        Unit* getSourceUnit();

        //=================================================
        // reference is not needed anymore. realy delete it !

        void removeReference();

        //=================================================

        HostileReference* next() { return ((HostileReference*) Reference<Unit, ThreatManager>::next()); }

        //=================================================

        // Tell our refTo (target) object that we have a link
        void targetObjectBuildLink() override;

        // Tell our refTo (taget) object, that the link is cut
        void targetObjectDestroyLink() override;

        // Tell our refFrom (source) object, that the link is cut (Target destroyed)
        void sourceObjectDestroyLink() override;
    private:
        // Inform the source, that the status of that reference was changed
        void fireStatusChanged(ThreatRefStatusChangeEvent& pThreatRefStatusChangeEvent);

        float iThreat;
        float iTempThreatModifyer;                          // used for taunt
        ObjectGuid iUnitGuid;
        bool iOnline;
        bool iAccessible;
};

//==============================================================
class ThreatManager;

typedef std::list<HostileReference*> ThreatList;

class ThreatContainer
{
    ThreatList iThreatList;
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

    HostileReference* addThreat(Unit* pVictim, float pThreat);

    void modifyThreatPercent(Unit* pVictim, int32 percent);

    HostileReference* selectNextVictim(Creature* pAttacker, HostileReference* pCurrentVictim);

    void setDirty(bool pDirty) { iDirty = pDirty; }

    bool isDirty() const { return iDirty; }

    bool empty() const { return iThreatList.empty(); }

    HostileReference* getMostHated() { return iThreatList.empty() ? nullptr : iThreatList.front(); }

    HostileReference* getReferenceByTarget(Unit* pVictim);

    ThreatList const& getThreatList() const { return iThreatList; }
};

//=================================================

class ThreatManager
{
public:
    friend class HostileReference;

    explicit ThreatManager(Unit* pOwner);

    ~ThreatManager() { clearReferences(); }

    void clearReferences();

    void addThreat(Unit* pVictim, float threat, bool crit, SpellSchoolMask schoolMask, SpellEntry const* threatSpell, bool isAssistThreat);
    void addThreat(Unit* pVictim, float threat) { addThreat(pVictim, threat, false, SPELL_SCHOOL_MASK_NONE, nullptr, false); }

    // add threat as raw value (ignore redirections and expection all mods applied already to it
    void addThreatDirectly(Unit* pVictim, float threat);

    void modifyThreatPercent(Unit* pVictim, int32 pPercent);

    float getThreat(Unit* pVictim, bool pAlsoSearchOfflineList = false);

    bool isThreatListEmpty() const { return iThreatContainer.empty(); }

    void processThreatEvent(ThreatRefStatusChangeEvent* threatRefStatusChangeEvent);

    HostileReference* getCurrentVictim() const { return iCurrentVictim; }
    void setCurrentVictimIfCan(Unit* pVictim);

    Unit*  getOwner() const { return iOwner; }

    Unit* getHostileTarget();

    void tauntApply(Unit* pTaunter);
    void tauntFadeOut(Unit* pTaunter);

    void setCurrentVictim(HostileReference* pHostileReference);

    void setDirty(bool pDirty) { iThreatContainer.setDirty(pDirty); }

    // Don't must be used for explicit modify threat values in iterator return pointers
    ThreatList const& getThreatList() const { return iThreatContainer.getThreatList(); }
private:
    HostileReference* iCurrentVictim;
    Unit* iOwner;
    ThreatContainer iThreatContainer;
    ThreatContainer iThreatOfflineContainer;
};

//=================================================
#endif
