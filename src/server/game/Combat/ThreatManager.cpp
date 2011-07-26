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

#include "ThreatManager.h"
#include "Unit.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "Map.h"
#include "Player.h"
#include "ObjectAccessor.h"
#include "UnitEvents.h"
#include "SpellAuras.h"
#include "SpellMgr.h"

//==============================================================
//================= ThreatCalcHelper ===========================
//==============================================================

// The pHatingUnit is not used yet
float ThreatCalcHelper::calcThreat(Unit* pHatedUnit, Unit* /*pHatingUnit*/, float fThreat, SpellSchoolMask schoolMask, SpellInfo const *pThreatSpell)
{
    if (pThreatSpell)
    {
        if (pThreatSpell->AttributesEx & SPELL_ATTR1_NO_THREAT)
            return 0.0f;

        if (Player* modOwner = pHatedUnit->GetSpellModOwner())
            modOwner->ApplySpellMod(pThreatSpell->Id, SPELLMOD_THREAT, fThreat);
    }

    return pHatedUnit->ApplyTotalThreatModifier(fThreat, schoolMask);
}

//============================================================
//================= HostileReference ==========================
//============================================================

HostileReference::HostileReference(Unit* pUnit, ThreatManager *pThreatManager, float fThreat)
{
    iThreat = fThreat;
    iTempThreatModifier = 0.0f;
    link(pUnit, pThreatManager);
    iUnitGuid = pUnit->GetGUID();
    iOnline = true;
    iAccessible = true;
}

//============================================================
// Tell our refTo (target) object that we have a link
void HostileReference::targetObjectBuildLink()
{
    getTarget()->addHatedBy(this);
}

//============================================================
// Tell our refTo (taget) object, that the link is cut
void HostileReference::targetObjectDestroyLink()
{
    getTarget()->removeHatedBy(this);
}

//============================================================
// Tell our refFrom (source) object, that the link is cut (Target destroyed)

void HostileReference::sourceObjectDestroyLink()
{
    setOnlineOfflineState(false);
}

//============================================================
// Inform the source, that the status of the reference changed

void HostileReference::fireStatusChanged(ThreatRefStatusChangeEvent& pThreatRefStatusChangeEvent)
{
    if (getSource())
        getSource()->processThreatEvent(&pThreatRefStatusChangeEvent);
}

//============================================================

void HostileReference::addThreat(float fModThreat)
{
    iThreat += fModThreat;
    // the threat is changed. Source and target unit have to be available
    // if the link was cut before relink it again
    if (!isOnline())
        updateOnlineStatus();
    if (fModThreat != 0.0f)
    {
        ThreatRefStatusChangeEvent event(UEV_THREAT_REF_THREAT_CHANGE, this, fModThreat);
        fireStatusChanged(event);
    }

    if (isValid() && fModThreat >= 0.0f)
    {
        Unit* victim_owner = getTarget()->GetCharmerOrOwner();
        if (victim_owner && victim_owner->isAlive())
            getSource()->addThreat(victim_owner, 0.0f);     // create a threat to the owner of a pet, if the pet attacks
    }
}

//============================================================
// check, if source can reach target and set the status

void HostileReference::updateOnlineStatus()
{
    bool online = false;
    bool accessible = false;

    if (!isValid())
        if (Unit* target = ObjectAccessor::GetUnit(*getSourceUnit(), getUnitGuid()))
            link(target, getSource());

    // only check for online status if
    // ref is valid
    // target is no player or not gamemaster
    // target is not in flight
    if (isValid() &&
        ((getTarget()->GetTypeId() != TYPEID_PLAYER || !((Player*)getTarget())->isGameMaster()) ||
        !getTarget()->HasUnitState(UNIT_STAT_IN_FLIGHT)))
    {
      Creature* creature = getSourceUnit()->ToCreature();
        online = getTarget()->isInAccessiblePlaceFor(creature);
        if (!online)
        {
            if (creature->IsWithinCombatRange(getTarget(), creature->m_CombatDistance))
                online = true;                              // not accessible but stays online
        }
        else
            accessible = true;

    }
    setAccessibleState(accessible);
    setOnlineOfflineState(online);
}

//============================================================
// set the status and fire the event on status change

void HostileReference::setOnlineOfflineState(bool pIsOnline)
{
    if (iOnline != pIsOnline)
    {
        iOnline = pIsOnline;
        if (!iOnline)
            setAccessibleState(false);                      // if not online that not accessable as well

        ThreatRefStatusChangeEvent event(UEV_THREAT_REF_ONLINE_STATUS, this);
        fireStatusChanged(event);
    }
}

//============================================================

void HostileReference::setAccessibleState(bool pIsAccessible)
{
    if (iAccessible != pIsAccessible)
    {
        iAccessible = pIsAccessible;

        ThreatRefStatusChangeEvent event(UEV_THREAT_REF_ASSECCIBLE_STATUS, this);
        fireStatusChanged(event);
    }
}

//============================================================
// prepare the reference for deleting
// this is called be the target

void HostileReference::removeReference()
{
    invalidate();

    ThreatRefStatusChangeEvent event(UEV_THREAT_REF_REMOVE_FROM_LIST, this);
    fireStatusChanged(event);
}

//============================================================

Unit* HostileReference::getSourceUnit()
{
    return (getSource()->getOwner());
}

//============================================================
//================ ThreatContainer ===========================
//============================================================

void ThreatContainer::clearReferences()
{
    for (std::list<HostileReference*>::const_iterator i = iThreatList.begin(); i != iThreatList.end(); ++i)
    {
        (*i)->unlink();
        delete (*i);
    }
    iThreatList.clear();
}

//============================================================
// Return the HostileReference of NULL, if not found
HostileReference* ThreatContainer::getReferenceByTarget(Unit* pVictim)
{
    HostileReference* result = NULL;

    uint64 guid = pVictim->GetGUID();
    for (std::list<HostileReference*>::const_iterator i = iThreatList.begin(); i != iThreatList.end(); ++i)
    {
        if ((*i)->getUnitGuid() == guid)
        {
            result = (*i);
            break;
        }
    }

    return result;
}

//============================================================
// Add the threat, if we find the reference

HostileReference* ThreatContainer::addThreat(Unit* pVictim, float fThreat)
{
    HostileReference* ref = getReferenceByTarget(pVictim);
    if (ref)
        ref->addThreat(fThreat);
    return ref;
}

//============================================================

void ThreatContainer::modifyThreatPercent(Unit *pVictim, int32 iPercent)
{
    if (HostileReference* ref = getReferenceByTarget(pVictim))
        ref->addThreatPercent(iPercent);
}

//============================================================
// Check if the list is dirty and sort if necessary

void ThreatContainer::update()
{
    if (iDirty && iThreatList.size() >1)
    {
        iThreatList.sort(Trinity::ThreatOrderPred());
    }
    iDirty = false;
}

//============================================================
// return the next best victim
// could be the current victim

HostileReference* ThreatContainer::selectNextVictim(Creature* pAttacker, HostileReference* pCurrentVictim)
{
    HostileReference* currentRef = NULL;
    bool found = false;
    bool noPriorityTargetFound = false;

    std::list<HostileReference*>::const_iterator lastRef = iThreatList.end();
    lastRef--;

    for (std::list<HostileReference*>::const_iterator iter = iThreatList.begin(); iter != iThreatList.end() && !found;)
    {
        currentRef = (*iter);

        Unit* target = currentRef->getTarget();
        ASSERT(target);                                     // if the ref has status online the target must be there !

        // some units are prefered in comparison to others
        if (!noPriorityTargetFound && (target->IsImmunedToDamage(pAttacker->GetMeleeDamageSchoolMask()) || target->HasNegativeAuraWithInterruptFlag(AURA_INTERRUPT_FLAG_TAKE_DAMAGE)))
        {
            if (iter != lastRef)
            {
                // current victim is a second choice target, so don't compare threat with it below
                if (currentRef == pCurrentVictim)
                    pCurrentVictim = NULL;
                ++iter;
                continue;
            }
            else
            {
                // if we reached to this point, everyone in the threatlist is a second choice target. In such a situation the target with the highest threat should be attacked.
                noPriorityTargetFound = true;
                iter = iThreatList.begin();
                continue;
            }
        }

        if (pAttacker->canCreatureAttack(target))           // skip non attackable currently targets
        {
            if (pCurrentVictim)                              // select 1.3/1.1 better target in comparison current target
            {
                // list sorted and and we check current target, then this is best case
                if (pCurrentVictim == currentRef || currentRef->getThreat() <= 1.1f * pCurrentVictim->getThreat())
                {
                    currentRef = pCurrentVictim;            // for second case
                    found = true;
                    break;
                }

                if (currentRef->getThreat() > 1.3f * pCurrentVictim->getThreat() ||
                    (currentRef->getThreat() > 1.1f * pCurrentVictim->getThreat() &&
                    pAttacker->IsWithinMeleeRange(target)))
                {                                           //implement 110% threat rule for targets in melee range
                    found = true;                           //and 130% rule for targets in ranged distances
                    break;                                  //for selecting alive targets
                }
            }
            else                                            // select any
            {
                found = true;
                break;
            }
        }
        ++iter;
    }
    if (!found)
        currentRef = NULL;

    return currentRef;
}

//============================================================
//=================== ThreatManager ==========================
//============================================================

ThreatManager::ThreatManager(Unit* owner) : iCurrentVictim(NULL), iOwner(owner), iUpdateTimer(THREAT_UPDATE_INTERVAL)
{
}

//============================================================

void ThreatManager::clearReferences()
{
    iThreatContainer.clearReferences();
    iThreatOfflineContainer.clearReferences();
    iCurrentVictim = NULL;
    iUpdateTimer = THREAT_UPDATE_INTERVAL;
}

//============================================================

void ThreatManager::addThreat(Unit* pVictim, float fThreat, SpellSchoolMask schoolMask, SpellInfo const *pThreatSpell)
{
    //function deals with adding threat and adding players and pets into ThreatList
    //mobs, NPCs, guards have ThreatList and HateOfflineList
    //players and pets have only InHateListOf
    //HateOfflineList is used co contain unattackable victims (in-flight, in-water, GM etc.)

    // not to self
    if (pVictim == getOwner())
        return;

    // not to GM
    if (!pVictim || (pVictim->GetTypeId() == TYPEID_PLAYER && pVictim->ToPlayer()->isGameMaster()))
        return;

    // not to dead and not for dead
    if (!pVictim->isAlive() || !getOwner()->isAlive())
        return;

    ASSERT(getOwner()->GetTypeId() == TYPEID_UNIT);

    float threat = ThreatCalcHelper::calcThreat(pVictim, iOwner, fThreat, schoolMask, pThreatSpell);

    // must check > 0.0f, otherwise dead loop
    if (threat > 0.0f && pVictim->GetReducedThreatPercent())
    {
        uint32 reducedThreadPercent = pVictim->GetReducedThreatPercent();

        Unit *unit = pVictim->GetMisdirectionTarget();
        if (unit)
            if (Aura* pAura = unit->GetAura(63326)) // Glyph of Vigilance
                reducedThreadPercent += pAura->GetSpellInfo()->Effects[0].CalcValue();

        float reducedThreat = threat * reducedThreadPercent / 100;
        threat -= reducedThreat;
        if (unit)
            _addThreat(unit, reducedThreat);
    }

    _addThreat(pVictim, threat);
}

void ThreatManager::_addThreat(Unit *pVictim, float fThreat)
{
    HostileReference* ref = iThreatContainer.addThreat(pVictim, fThreat);
    // Ref is not in the online refs, search the offline refs next
    if (!ref)
        ref = iThreatOfflineContainer.addThreat(pVictim, fThreat);

    if (!ref)                                               // there was no ref => create a new one
    {
                                                            // threat has to be 0 here
        HostileReference* hostilReference = new HostileReference(pVictim, this, 0);
        iThreatContainer.addReference(hostilReference);
        hostilReference->addThreat(fThreat);                // now we add the real threat
        if (pVictim->GetTypeId() == TYPEID_PLAYER && pVictim->ToPlayer()->isGameMaster())
            hostilReference->setOnlineOfflineState(false);  // GM is always offline
    }
}

//============================================================

void ThreatManager::modifyThreatPercent(Unit *pVictim, int32 iPercent)
{
    iThreatContainer.modifyThreatPercent(pVictim, iPercent);
}

//============================================================

Unit* ThreatManager::getHostilTarget()
{
    iThreatContainer.update();
    HostileReference* nextVictim = iThreatContainer.selectNextVictim(getOwner()->ToCreature(), getCurrentVictim());
    setCurrentVictim(nextVictim);
    return getCurrentVictim() != NULL ? getCurrentVictim()->getTarget() : NULL;
}

//============================================================

float ThreatManager::getThreat(Unit *pVictim, bool pAlsoSearchOfflineList)
{
    float threat = 0.0f;
    HostileReference* ref = iThreatContainer.getReferenceByTarget(pVictim);
    if (!ref && pAlsoSearchOfflineList)
        ref = iThreatOfflineContainer.getReferenceByTarget(pVictim);
    if (ref)
        threat = ref->getThreat();
    return threat;
}

//============================================================

void ThreatManager::tauntApply(Unit* pTaunter)
{
    HostileReference* ref = iThreatContainer.getReferenceByTarget(pTaunter);
    if (getCurrentVictim() && ref && (ref->getThreat() < getCurrentVictim()->getThreat()))
    {
        if (ref->getTempThreatModifier() == 0.0f) // Ok, temp threat is unused
            ref->setTempThreat(getCurrentVictim()->getThreat());
    }
}

//============================================================

void ThreatManager::tauntFadeOut(Unit *pTaunter)
{
    HostileReference* ref = iThreatContainer.getReferenceByTarget(pTaunter);
    if (ref)
        ref->resetTempThreat();
}

//============================================================

void ThreatManager::setCurrentVictim(HostileReference* pHostileReference)
{
    if (pHostileReference && pHostileReference != iCurrentVictim)
    {
        iOwner->SendChangeCurrentVictimOpcode(pHostileReference);
    }
    iCurrentVictim = pHostileReference;
}

//============================================================
// The hated unit is gone, dead or deleted
// return true, if the event is consumed

void ThreatManager::processThreatEvent(ThreatRefStatusChangeEvent* threatRefStatusChangeEvent)
{
    threatRefStatusChangeEvent->setThreatManager(this);     // now we can set the threat manager

    HostileReference* hostilReference = threatRefStatusChangeEvent->getReference();

    switch(threatRefStatusChangeEvent->getType())
    {
        case UEV_THREAT_REF_THREAT_CHANGE:
            if ((getCurrentVictim() == hostilReference && threatRefStatusChangeEvent->getFValue()<0.0f) ||
                (getCurrentVictim() != hostilReference && threatRefStatusChangeEvent->getFValue()>0.0f))
                setDirty(true);                             // the order in the threat list might have changed
            break;
        case UEV_THREAT_REF_ONLINE_STATUS:
            if (!hostilReference->isOnline())
            {
                if (hostilReference == getCurrentVictim())
                {
                    setCurrentVictim(NULL);
                    setDirty(true);
                }
                iThreatContainer.remove(hostilReference);
                iThreatOfflineContainer.addReference(hostilReference);
            }
            else
            {
                if (getCurrentVictim() && hostilReference->getThreat() > (1.1f * getCurrentVictim()->getThreat()))
                    setDirty(true);
                iThreatContainer.addReference(hostilReference);
                iThreatOfflineContainer.remove(hostilReference);
            }
            break;
        case UEV_THREAT_REF_REMOVE_FROM_LIST:
            if (hostilReference == getCurrentVictim())
            {
                setCurrentVictim(NULL);
                setDirty(true);
            }
            iOwner->SendRemoveFromThreatListOpcode(hostilReference);
            if (hostilReference->isOnline())
                iThreatContainer.remove(hostilReference);
            else
                iThreatOfflineContainer.remove(hostilReference);
            break;
    }
}

bool ThreatManager::isNeedUpdateToClient(uint32 time)
{
    if (isThreatListEmpty())
        return false;
    if (time >= iUpdateTimer)
    {
        iUpdateTimer = THREAT_UPDATE_INTERVAL;
        return true;
    }
    iUpdateTimer -= time;
    return false;
}

// Reset all aggro without modifying the threadlist.
void ThreatManager::resetAllAggro()
{
    std::list<HostileReference*> &threatlist = getThreatList();
    if (threatlist.empty())
        return;

    for (std::list<HostileReference*>::iterator itr = threatlist.begin(); itr != threatlist.end(); ++itr)
    {
        (*itr)->setThreat(0);
    }

    setDirty(true);
}
