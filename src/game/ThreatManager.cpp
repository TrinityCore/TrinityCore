/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2009 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */
#include "ThreatManager.h"
#include "Unit.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "Map.h"
#include "Player.h"
#include "ObjectAccessor.h"
#include "UnitEvents.h"
//==============================================================
//================= ThreatCalcHelper ===========================
//==============================================================
// The pHatingUnit is not used yet
float ThreatCalcHelper::calcThreat(Unit* pHatedUnit, Unit* pHatingUnit, float pThreat, SpellSchoolMask schoolMask, SpellEntry const *pThreatSpell)
{
    if (pThreatSpell)
        if (Player* modOwner = pHatedUnit->GetSpellModOwner())
            modOwner->ApplySpellMod(pThreatSpell->Id, SPELLMOD_THREAT, pThreat);
    float threat = pHatedUnit->ApplyTotalThreatModifier(pThreat, schoolMask);
    return threat;
}
//============================================================
//================= HostilReference ==========================
//============================================================
HostilReference::HostilReference(Unit* pUnit, ThreatManager *pThreatManager, float pThreat)
{
    iThreat = pThreat;
    iTempThreatModifyer = 0.0f;
    link(pUnit, pThreatManager);
    iUnitGuid = pUnit->GetGUID();
    iOnline = true;
    iAccessible = true;
}
//============================================================
// Tell our refTo (target) object that we have a link
void HostilReference::targetObjectBuildLink()
{
    getTarget()->addHatedBy(this);
}
//============================================================
// Tell our refTo (taget) object, that the link is cut
void HostilReference::targetObjectDestroyLink()
{
    getTarget()->removeHatedBy(this);
}
//============================================================
// Tell our refFrom (source) object, that the link is cut (Target destroyed)
void HostilReference::sourceObjectDestroyLink()
{
    setOnlineOfflineState(false);
}
//============================================================
// Inform the source, that the status of the reference changed
void HostilReference::fireStatusChanged(ThreatRefStatusChangeEvent& pThreatRefStatusChangeEvent)
{
    if(getSource())
        getSource()->processThreatEvent(&pThreatRefStatusChangeEvent);
}
//============================================================
void HostilReference::addThreat(float pMod)
{
    iThreat += pMod;
    // the threat is changed. Source and target unit have to be availabe
    // if the link was cut before relink it again
    if(!isOnline())
        updateOnlineStatus();
    if(pMod != 0.0f)
    {
        ThreatRefStatusChangeEvent event(UEV_THREAT_REF_THREAT_CHANGE, this, pMod);
        fireStatusChanged(event);
    }
    if(isValid() && pMod >= 0)
    {
        Unit* victim_owner = getTarget()->GetCharmerOrOwner();
        if(victim_owner && victim_owner->isAlive())
            getSource()->addThreat(victim_owner, 0.0f);     // create a threat to the owner of a pet, if the pet attacks
    }
}
//============================================================
// check, if source can reach target and set the status
void HostilReference::updateOnlineStatus()
{
    bool online = false;
    bool accessible = false;
    if(!isValid())
    {
        Unit* target = ObjectAccessor::GetUnit(*getSourceUnit(), getUnitGuid());
        if(target)
            link(target, getSource());
    }
    // only check for online status if
    // ref is valid
    // target is no player or not gamemaster
    // target is not in flight
    if(isValid() &&
        ((getTarget()->GetTypeId() != TYPEID_PLAYER || !((Player*)getTarget())->isGameMaster()) ||
        !getTarget()->hasUnitState(UNIT_STAT_IN_FLIGHT)))
    {
        Creature* creature = (Creature* ) getSourceUnit();
        online = getTarget()->isInAccessiblePlaceFor(creature);
        if(!online)
        {
            if(creature->IsWithinCombatRange(getTarget(), creature->m_CombatDistance))
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
void HostilReference::setOnlineOfflineState(bool pIsOnline)
{
    if(iOnline != pIsOnline)
    {
        iOnline = pIsOnline;
        if(!iOnline)
            setAccessibleState(false);                      // if not online that not accessable as well
        ThreatRefStatusChangeEvent event(UEV_THREAT_REF_ONLINE_STATUS, this);
        fireStatusChanged(event);
    }
}
//============================================================
void HostilReference::setAccessibleState(bool pIsAccessible)
{
    if(iAccessible != pIsAccessible)
    {
        iAccessible = pIsAccessible;
        ThreatRefStatusChangeEvent event(UEV_THREAT_REF_ASSECCIBLE_STATUS, this);
        fireStatusChanged(event);
    }
}
//============================================================
// prepare the reference for deleting
// this is called be the target
void HostilReference::removeReference()
{
    invalidate();
    ThreatRefStatusChangeEvent event(UEV_THREAT_REF_REMOVE_FROM_LIST, this);
    fireStatusChanged(event);
}
//============================================================
Unit* HostilReference::getSourceUnit()
{
    return (getSource()->getOwner());
}
//============================================================
//================ ThreatContainer ===========================
//============================================================
void ThreatContainer::clearReferences()
{
    for(std::list<HostilReference*>::const_iterator i = iThreatList.begin(); i != iThreatList.end(); ++i)
    {
        (*i)->unlink();
        delete (*i);
    }
    iThreatList.clear();
}
//============================================================
// Return the HostilReference of NULL, if not found
HostilReference* ThreatContainer::getReferenceByTarget(Unit* pVictim)
{
    HostilReference* result = NULL;
    uint64 guid = pVictim->GetGUID();
    for(std::list<HostilReference*>::const_iterator i = iThreatList.begin(); i != iThreatList.end(); ++i)
    {
        if((*i)->getUnitGuid() == guid)
        {
            result = (*i);
            break;
        }
    }
    return result;
}
//============================================================
// Add the threat, if we find the reference
HostilReference* ThreatContainer::addThreat(Unit* pVictim, float pThreat)
{
    HostilReference* ref = getReferenceByTarget(pVictim);
    if(ref)
        ref->addThreat(pThreat);
    return ref;
}
//============================================================
void ThreatContainer::modifyThreatPercent(Unit *pVictim, int32 pPercent)
{
    if(HostilReference* ref = getReferenceByTarget(pVictim))
        ref->addThreatPercent(pPercent);
}
//============================================================
bool HostilReferenceSortPredicate(const HostilReference* lhs, const HostilReference* rhs)
{
    // std::list::sort ordering predicate must be: (Pred(x,y)&&Pred(y,x))==false
    return lhs->getThreat() > rhs->getThreat();             // reverse sorting
}
//============================================================
// Check if the list is dirty and sort if necessary
void ThreatContainer::update()
{
    if(iDirty && iThreatList.size() >1)
    {
        iThreatList.sort(HostilReferenceSortPredicate);
    }
    iDirty = false;
}
//============================================================
// return the next best victim
// could be the current victim
HostilReference* ThreatContainer::selectNextVictim(Creature* pAttacker, HostilReference* pCurrentVictim)
{
    HostilReference* currentRef = NULL;
    bool found = false;
    bool noPriorityTargetFound = false;
    std::list<HostilReference*>::const_iterator lastRef = iThreatList.end();
    lastRef--;
    for(std::list<HostilReference*>::const_iterator iter = iThreatList.begin(); iter != iThreatList.end() && !found;)
    {
        currentRef = (*iter);
        Unit* target = currentRef->getTarget();
        assert(target);                                     // if the ref has status online the target must be there !
        // some units are prefered in comparison to others
        if(!noPriorityTargetFound && (target->IsImmunedToDamage(pAttacker->GetMeleeDamageSchoolMask()) || target->hasNegativeAuraWithInterruptFlag(AURA_INTERRUPT_FLAG_TAKE_DAMAGE)) )
        {
            if(iter != lastRef)
            {
                // current victim is a second choice target, so don't compare threat with it below
                if(currentRef == pCurrentVictim)
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
        if(pAttacker->canCreatureAttack(target))           // skip non attackable currently targets
        {
            if(pCurrentVictim)                              // select 1.3/1.1 better target in comparison current target
            {
                // list sorted and and we check current target, then this is best case
                if(pCurrentVictim == currentRef || currentRef->getThreat() <= 1.1f * pCurrentVictim->getThreat() )
                {
                    currentRef = pCurrentVictim;            // for second case
                    found = true;
                    break;
                }
                if (currentRef->getThreat() > 1.3f * pCurrentVictim->getThreat() ||
                    currentRef->getThreat() > 1.1f * pCurrentVictim->getThreat() &&
                    pAttacker->IsWithinMeleeRange(target))
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
    if(!found)
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
void ThreatManager::addThreat(Unit* pVictim, float pThreat, SpellSchoolMask schoolMask, SpellEntry const *pThreatSpell)
{
    //function deals with adding threat and adding players and pets into ThreatList
    //mobs, NPCs, guards have ThreatList and HateOfflineList
    //players and pets have only InHateListOf
    //HateOfflineList is used co contain unattackable victims (in-flight, in-water, GM etc.)
    // not to self
    if (pVictim == getOwner())
        return;
    // not to GM
    if(!pVictim || (pVictim->GetTypeId() == TYPEID_PLAYER && ((Player*)pVictim)->isGameMaster()) )
        return;
    // not to dead and not for dead
    if(!pVictim->isAlive() || !getOwner()->isAlive() )
        return;
    assert(getOwner()->GetTypeId()== TYPEID_UNIT);
    float threat = ThreatCalcHelper::calcThreat(pVictim, iOwner, pThreat, schoolMask, pThreatSpell);
    // must check > 0.0f, otherwise dead loop
    if(threat > 0.0f && pVictim->GetReducedThreatPercent())
    {
        float reducedThreat = threat * pVictim->GetReducedThreatPercent() / 100;
        threat -= reducedThreat;
        if(Unit *unit = pVictim->GetMisdirectionTarget())
            _addThreat(unit, reducedThreat);
    }
    _addThreat(pVictim, threat);
}
void ThreatManager::_addThreat(Unit *pVictim, float threat)
{
    HostilReference* ref = iThreatContainer.addThreat(pVictim, threat);
    // Ref is not in the online refs, search the offline refs next
    if(!ref)
        ref = iThreatOfflineContainer.addThreat(pVictim, threat);
    if(!ref)                                                // there was no ref => create a new one
    {
                                                            // threat has to be 0 here
        HostilReference* hostilReference = new HostilReference(pVictim, this, 0);
        iThreatContainer.addReference(hostilReference);
        hostilReference->addThreat(threat);                 // now we add the real threat
        if(pVictim->GetTypeId() == TYPEID_PLAYER && ((Player*)pVictim)->isGameMaster())
            hostilReference->setOnlineOfflineState(false);  // GM is always offline
    }
}
//============================================================
void ThreatManager::modifyThreatPercent(Unit *pVictim, int32 pPercent)
{
    iThreatContainer.modifyThreatPercent(pVictim, pPercent);
}
//============================================================
Unit* ThreatManager::getHostilTarget()
{
    iThreatContainer.update();
    HostilReference* nextVictim = iThreatContainer.selectNextVictim((Creature*) getOwner(), getCurrentVictim());
    setCurrentVictim(nextVictim);
    return getCurrentVictim() != NULL ? getCurrentVictim()->getTarget() : NULL;
}
//============================================================
float ThreatManager::getThreat(Unit *pVictim, bool pAlsoSearchOfflineList)
{
    float threat = 0.0f;
    HostilReference* ref = iThreatContainer.getReferenceByTarget(pVictim);
    if(!ref && pAlsoSearchOfflineList)
        ref = iThreatOfflineContainer.getReferenceByTarget(pVictim);
    if(ref)
        threat = ref->getThreat();
    return threat;
}
//============================================================
void ThreatManager::tauntApply(Unit* pTaunter)
{
    HostilReference* ref = iThreatContainer.getReferenceByTarget(pTaunter);
    if(getCurrentVictim() && ref && (ref->getThreat() < getCurrentVictim()->getThreat()))
    {
        if(ref->getTempThreatModifyer() == 0.0f)
                                                            // Ok, temp threat is unused
            ref->setTempThreat(getCurrentVictim()->getThreat());
    }
}
//============================================================
void ThreatManager::tauntFadeOut(Unit *pTaunter)
{
    HostilReference* ref = iThreatContainer.getReferenceByTarget(pTaunter);
    if(ref)
        ref->resetTempThreat();
}
//============================================================
void ThreatManager::setCurrentVictim(HostilReference* pHostilReference)
{
    if (pHostilReference && pHostilReference != iCurrentVictim)
    {
        iOwner->SendChangeCurrentVictimOpcode(pHostilReference);
    }
    iCurrentVictim = pHostilReference;
}
//============================================================
// The hated unit is gone, dead or deleted
// return true, if the event is consumed
void ThreatManager::processThreatEvent(ThreatRefStatusChangeEvent* threatRefStatusChangeEvent)
{
    threatRefStatusChangeEvent->setThreatManager(this);     // now we can set the threat manager
    HostilReference* hostilReference = threatRefStatusChangeEvent->getReference();
    switch(threatRefStatusChangeEvent->getType())
    {
        case UEV_THREAT_REF_THREAT_CHANGE:
            if((getCurrentVictim() == hostilReference && threatRefStatusChangeEvent->getFValue()<0.0f) ||
                (getCurrentVictim() != hostilReference && threatRefStatusChangeEvent->getFValue()>0.0f))
                setDirty(true);                             // the order in the threat list might have changed
            break;
        case UEV_THREAT_REF_ONLINE_STATUS:
            if(!hostilReference->isOnline())
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
                if(getCurrentVictim() && hostilReference->getThreat() > (1.1f * getCurrentVictim()->getThreat()))
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
            if(hostilReference->isOnline())
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

