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

#include "PetAI.h"
#include "Errors.h"
#include "Pet.h"
#include "Player.h"
#include "DBCStores.h"
#include "Spell.h"
#include "ObjectAccessor.h"
#include "SpellMgr.h"
#include "Creature.h"
#include "World.h"
#include "Util.h"
#include "Group.h"
#include "SpellInfo.h"

int PetAI::Permissible(const Creature *creature)
{
    if (creature->isPet())
        return PERMIT_BASE_SPECIAL;

    return PERMIT_BASE_NO;
}

PetAI::PetAI(Creature *c) : CreatureAI(c), i_tracker(TIME_INTERVAL_LOOK)
{
    m_AllySet.clear();
    UpdateAllies();
    targetHasCC = false;
}

void PetAI::EnterEvadeMode()
{
}

bool PetAI::_needToStop()
{
    // This is needed for charmed creatures, as once their target was reset other effects can trigger threat
    if (me->isCharmed() && me->getVictim() == me->GetCharmer())
        return true;

    if (_CheckTargetCC(me->getVictim()) && !targetHasCC)
        return true;

    return !me->canAttack(me->getVictim());
}

void PetAI::_stopAttack()
{
    if (!me->isAlive())
    {
        sLog->outStaticDebug("Creature stoped attacking cuz his dead [guid=%u]", me->GetGUIDLow());
        me->GetMotionMaster()->Clear();
        me->GetMotionMaster()->MoveIdle();
        me->CombatStop();
        me->getHostileRefManager().deleteReferences();

        return;
    }

    me->AttackStop();
    me->GetCharmInfo()->SetIsCommandAttack(false);
    HandleReturnMovement();
}

void PetAI::UpdateAI(const uint32 diff)
{
    if (!me->isAlive())
        return;

    Unit* owner = me->GetCharmerOrOwner();

    if (m_updateAlliesTimer <= diff)
        // UpdateAllies self set update timer
        UpdateAllies();
    else
        m_updateAlliesTimer -= diff;

    // me->getVictim() can't be used for check in case stop fighting, me->getVictim() clear at Unit death etc.
    if (me->getVictim())
    {
        if (_needToStop())
        {
            sLog->outStaticDebug("Pet AI stopped attacking [guid=%u]", me->GetGUIDLow());
            _stopAttack();
            return;
        }
        targetHasCC = _CheckTargetCC(me->getVictim());

        DoMeleeAttackIfReady();
    }
    else if (owner && me->GetCharmInfo()) //no victim
    {
        Unit *nextTarget = SelectNextTarget();

        if (me->HasReactState(REACT_PASSIVE))
            _stopAttack();
        else if (nextTarget)
            AttackStart(nextTarget);
        else
            HandleReturnMovement();
    }
    else if (owner && !me->HasUnitState(UNIT_STAT_FOLLOW)) // no charm info and no victim
        me->GetMotionMaster()->MoveFollow(owner, PET_FOLLOW_DIST, me->GetFollowAngle());

    if (!me->GetCharmInfo())
        return;

    // Autocast (casted only in combat or persistent spells in any state)
    if (!me->HasUnitState(UNIT_STAT_CASTING))
    {
        typedef std::vector<std::pair<Unit*, Spell*> > TargetSpellList;
        TargetSpellList targetSpellStore;

        for (uint8 i = 0; i < me->GetPetAutoSpellSize(); ++i)
        {
            uint32 spellID = me->GetPetAutoSpellOnPos(i);
            if (!spellID)
                continue;

            SpellInfo const *spellInfo = sSpellMgr->GetSpellInfo(spellID);
            if (!spellInfo)
                continue;

            if (me->GetCharmInfo() && me->GetCharmInfo()->GetGlobalCooldownMgr().HasGlobalCooldown(spellInfo))
                continue;

            // ignore some combinations of combat state and combat/noncombat spells
            if (!me->getVictim())
            {
                // ignore attacking spells, and allow only self/around spells
                if (!spellInfo->IsPositive())
                    continue;

                // non combat spells allowed
                // only pet spells have IsNonCombatSpell and not fit this reqs:
                // Consume Shadows, Lesser Invisibility, so ignore checks for its
                if (spellInfo->CanBeUsedInCombat())
                {
                    // allow only spell without spell cost or with spell cost but not duration limit
                    int32 duration = spellInfo->GetDuration();
                    if ((spellInfo->ManaCost || spellInfo->ManaCostPercentage || spellInfo->ManaPerSecond) && duration > 0)
                        continue;

                    // allow only spell without cooldown > duration
                    int32 cooldown = spellInfo->GetRecoveryTime();
                    if (cooldown >= 0 && duration >= 0 && cooldown > duration)
                        continue;
                }
            }
            else
            {
                // just ignore non-combat spells
                if (!spellInfo->CanBeUsedInCombat())
                    continue;
            }

            Spell* spell = new Spell(me, spellInfo, TRIGGERED_NONE, 0);

            // Fix to allow pets on STAY to autocast
            if (me->getVictim() && _CanAttack(me->getVictim()) && spell->CanAutoCast(me->getVictim()))
            {
                targetSpellStore.push_back(std::make_pair<Unit*, Spell*>(me->getVictim(), spell));
                continue;
            }
            else
            {
                bool spellUsed = false;
                for (std::set<uint64>::const_iterator tar = m_AllySet.begin(); tar != m_AllySet.end(); ++tar)
                {
                    Unit* Target = ObjectAccessor::GetUnit(*me, *tar);

                    //only buff targets that are in combat, unless the spell can only be cast while out of combat
                    if (!Target)
                        continue;

                    if (spell->CanAutoCast(Target))
                    {
                        targetSpellStore.push_back(std::make_pair<Unit*, Spell*>(Target, spell));
                        spellUsed = true;
                        break;
                    }
                }
                if (!spellUsed)
                    delete spell;
            }
        }

        //found units to cast on to
        if (!targetSpellStore.empty())
        {
            uint32 index = urand(0, targetSpellStore.size() - 1);

            Spell* spell  = targetSpellStore[index].second;
            Unit*  target = targetSpellStore[index].first;

            targetSpellStore.erase(targetSpellStore.begin() + index);

            SpellCastTargets targets;
            targets.SetUnitTarget(target);

            if (!me->HasInArc(M_PI, target))
            {
                me->SetInFront(target);
                if (target && target->GetTypeId() == TYPEID_PLAYER)
                    me->SendUpdateToPlayer(target->ToPlayer());

                if (owner && owner->GetTypeId() == TYPEID_PLAYER)
                    me->SendUpdateToPlayer(owner->ToPlayer());
            }

            me->AddCreatureSpellCooldown(spell->m_spellInfo->Id);

            spell->prepare(&targets);
        }

        // deleted cached Spell objects
        for (TargetSpellList::const_iterator itr = targetSpellStore.begin(); itr != targetSpellStore.end(); ++itr)
            delete itr->second;
    }
}

void PetAI::UpdateAllies()
{
    Unit* owner = me->GetCharmerOrOwner();
    Group *pGroup = NULL;

    m_updateAlliesTimer = 10*IN_MILLISECONDS;                //update friendly targets every 10 seconds, lesser checks increase performance

    if (!owner)
        return;
    else if (owner->GetTypeId() == TYPEID_PLAYER)
        pGroup = owner->ToPlayer()->GetGroup();

    //only pet and owner/not in group->ok
    if (m_AllySet.size() == 2 && !pGroup)
        return;
    //owner is in group; group members filled in already (no raid -> subgroupcount = whole count)
    if (pGroup && !pGroup->isRaidGroup() && m_AllySet.size() == (pGroup->GetMembersCount() + 2))
        return;

    m_AllySet.clear();
    m_AllySet.insert(me->GetGUID());
    if (pGroup)                                              //add group
    {
        for (GroupReference *itr = pGroup->GetFirstMember(); itr != NULL; itr = itr->next())
        {
            Player* Target = itr->getSource();
            if (!Target || !pGroup->SameSubGroup((Player*)owner, Target))
                continue;

            if (Target->GetGUID() == owner->GetGUID())
                continue;

            m_AllySet.insert(Target->GetGUID());
        }
    }
    else                                                    //remove group
        m_AllySet.insert(owner->GetGUID());
}

void PetAI::KilledUnit(Unit* victim)
{
    // Called from Unit::Kill() in case where pet or owner kills something
    // if owner killed this victim, pet may still be attacking something else
    if (me->getVictim() && me->getVictim() != victim)
        return;

    // Clear target just in case. May help problem where health / focus / mana
    // regen gets stuck. Also resets attack command.
    // Can't use _stopAttack() because that activates movement handlers and ignores
    // next target selection
    me->AttackStop();
    me->GetCharmInfo()->SetIsCommandAttack(false);

    Unit *nextTarget = SelectNextTarget();

    if (nextTarget)
        AttackStart(nextTarget);
    else
        HandleReturnMovement(); // Return
}

void PetAI::AttackStart(Unit* target)
{
    // Overrides Unit::AttackStart to correctly evaluate Pet states

    // Check all pet states to decide if we can attack this target
    if (!_CanAttack(target))
        return;

    targetHasCC = _CheckTargetCC(target);

    DoAttack(target, true);
}

Unit *PetAI::SelectNextTarget()
{
    // Provides next target selection after current target death

    // Passive pets don't do next target selection
    if (me->HasReactState(REACT_PASSIVE))
        return NULL;

    Unit* target = me->getAttackerForHelper();
    targetHasCC = false;

    // Check pet's attackers first to prevent dragging mobs back to owner
    if (target && !_CheckTargetCC(target))
        return target;

    if (me->GetCharmerOrOwner())
    {
        // Check owner's attackers if pet didn't have any
        target = me->GetCharmerOrOwner()->getAttackerForHelper();
        if (target && !_CheckTargetCC(target))
            return target;

        // 3.0.2 - Pets now start attacking their owners target in defensive mode as soon as the hunter does
        target = me->GetCharmerOrOwner()->getVictim();
        if (target && !_CheckTargetCC(target))
            return target;
    }

    // Default
    return NULL;
}

void PetAI::HandleReturnMovement()
{
    // Handles moving the pet back to stay or owner

    if (me->GetCharmInfo()->HasCommandState(COMMAND_STAY))
    {
        if (!me->GetCharmInfo()->IsAtStay() && !me->GetCharmInfo()->IsReturning())
        {
            // Return to previous position where stay was clicked
            if (!me->GetCharmInfo()->IsCommandAttack())
            {
                float x, y, z;

                me->GetCharmInfo()->GetStayPosition(x, y, z);
                me->GetCharmInfo()->SetIsReturning(true);
                me->GetMotionMaster()->Clear();
                me->GetMotionMaster()->MovePoint(me->GetGUIDLow(), x, y, z);
            }
        }
    }
    else // COMMAND_FOLLOW
    {
        if (!me->GetCharmInfo()->IsFollowing() && !me->GetCharmInfo()->IsReturning())
        {
            if (!me->GetCharmInfo()->IsCommandAttack())
            {
                me->GetCharmInfo()->SetIsReturning(true);
                me->GetMotionMaster()->Clear();
                me->GetMotionMaster()->MoveFollow(me->GetCharmerOrOwner(), PET_FOLLOW_DIST, me->GetFollowAngle());
            }
        }
    }

}

void PetAI::DoAttack(Unit* target, bool chase)
{
    // Handles attack with or without chase and also resets all
    // PetAI flags for next update / creature kill

    // me->GetCharmInfo()->SetIsCommandAttack(false);

    // The following conditions are true if chase == true
    // (Follow && (Aggressive || Defensive))
    // ((Stay || Follow) && (Passive && player clicked attack))

    if (chase)
    {
        if (me->Attack(target, true))
        {
            me->GetCharmInfo()->SetIsAtStay(false);
            me->GetCharmInfo()->SetIsFollowing(false);
            me->GetCharmInfo()->SetIsReturning(false);
            me->GetMotionMaster()->Clear();
            me->GetMotionMaster()->MoveChase(target);
        }
    }
    else // (Stay && ((Aggressive || Defensive) && In Melee Range)))
    {
        me->GetCharmInfo()->SetIsAtStay(true);
        me->GetCharmInfo()->SetIsFollowing(false);
        me->GetCharmInfo()->SetIsReturning(false);
        me->Attack(target, true);
    }
}

void PetAI::MovementInform(uint32 moveType, uint32 data)
{
    // Receives notification when pet reaches stay or follow owner
    switch (moveType)
    {
        case POINT_MOTION_TYPE:
        {
            // Pet is returning to where stay was clicked. data should be
            // pet's GUIDLow since we set that as the waypoint ID
            if (data == me->GetGUIDLow() && me->GetCharmInfo()->IsReturning())
            {
                me->GetCharmInfo()->SetIsAtStay(true);
                me->GetCharmInfo()->SetIsReturning(false);
                me->GetCharmInfo()->SetIsFollowing(false);
                me->GetCharmInfo()->SetIsCommandAttack(false);
                me->GetMotionMaster()->Clear();
                me->GetMotionMaster()->MoveIdle();
            }
        }
        break;

        case TARGETED_MOTION_TYPE:
        {
            // If data is owner's GUIDLow then we've reached follow point,
            // otherwise we're probably chasing a creature
            if (me->GetCharmerOrOwner() && me->GetCharmInfo() && data == me->GetCharmerOrOwner()->GetGUIDLow() && me->GetCharmInfo()->IsReturning())
            {
                me->GetCharmInfo()->SetIsAtStay(false);
                me->GetCharmInfo()->SetIsReturning(false);
                me->GetCharmInfo()->SetIsFollowing(true);
                me->GetCharmInfo()->SetIsCommandAttack(false);
                me->AddUnitState(UNIT_STAT_FOLLOW);
            }
        }
        break;

        default:
            break;
    }
}

bool PetAI::_CanAttack(Unit* target)
{
    // Evaluates wether a pet can attack a specific
    // target based on CommandState, ReactState and other flags

    // Returning - check first since pets returning ignore attacks
    if (me->GetCharmInfo()->IsReturning())
        return false;

    // Passive - check now so we don't have to worry about passive in later checks
    if (me->HasReactState(REACT_PASSIVE))
        return me->GetCharmInfo()->IsCommandAttack();

    //  Pets commanded to attack should not stop their approach if attacked by another creature
    if (me->getVictim() && (me->getVictim() != target))
        return !me->GetCharmInfo()->IsCommandAttack();

    // From this point on, pet will always be either aggressive or defensive

    // Stay - can attack if target is within range or commanded to
    if (me->GetCharmInfo()->HasCommandState(COMMAND_STAY))
        return (me->IsWithinMeleeRange(target, MIN_MELEE_REACH) || me->GetCharmInfo()->IsCommandAttack());

    // Follow
    if (me->GetCharmInfo()->HasCommandState(COMMAND_FOLLOW))
        return true;

    // default, though we shouldn't ever get here
    return false;
}

bool PetAI::_CheckTargetCC(Unit* target)
{
    if (me->GetCharmerOrOwnerGUID() && target->HasNegativeAuraWithAttribute(SPELL_ATTR0_BREAKABLE_BY_DAMAGE, me->GetCharmerOrOwnerGUID()))
        return true;

    return false;
}
