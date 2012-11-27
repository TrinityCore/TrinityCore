/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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

int PetAI::Permissible(const Creature* creature)
{
    if (creature->isPet())
        return PERMIT_BASE_SPECIAL;

    return PERMIT_BASE_NO;
}

PetAI::PetAI(Creature* c) : CreatureAI(c), i_tracker(TIME_INTERVAL_LOOK)
{
    m_AllySet.clear();
    UpdateAllies();
}

void PetAI::EnterEvadeMode()
{
}

bool PetAI::_needToStop()
{
    // This is needed for charmed creatures, as once their target was reset other effects can trigger threat
    if (me->isCharmed() && me->getVictim() == me->GetCharmer())
        return true;

    return !me->IsValidAttackTarget(me->getVictim());
}

void PetAI::_stopAttack()
{
    if (!me->isAlive())
    {
        sLog->outDebug(LOG_FILTER_GENERAL, "Creature stoped attacking cuz his dead [guid=%u]", me->GetGUIDLow());
        me->GetMotionMaster()->Clear();
        me->GetMotionMaster()->MoveIdle();
        me->CombatStop();
        me->getHostileRefManager().deleteReferences();

        return;
    }

    me->AttackStop();
    me->InterruptNonMeleeSpells(false);
    me->SendMeleeAttackStop(); // Should stop pet's attack button from flashing
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

    if (me->getVictim() && me->getVictim()->isAlive())
    {
        // is only necessary to stop casting, the pet must not exit combat
        if (me->getVictim()->HasBreakableByDamageCrowdControlAura(me))
        {
            me->InterruptNonMeleeSpells(false);
            return;
        }

        if (_needToStop())
        {
            sLog->outDebug(LOG_FILTER_GENERAL, "Pet AI stopped attacking [guid=%u]", me->GetGUIDLow());
            _stopAttack();
            return;
        }

        // Check before attacking to prevent pets from leaving stay position
        if (CanAttack(me->getVictim()))
            DoMeleeAttackIfReady();
    }
    else if (owner && me->GetCharmInfo()) //no victim
    {
        // Only aggressive pets do target search every update.
        // Defensive pets do target search only in these cases:
        //  * Owner attacks something - handled by OwnerAttacked()
        //  * Owner receives damage - handled by OwnerDamagedBy()
        //  * Pet is in combat and current target dies - handled by KilledUnit()
        if (me->HasReactState(REACT_AGGRESSIVE))
        {
            Unit* nextTarget = SelectNextTarget();

            if (nextTarget)
                AttackStart(nextTarget);
            else
            {
                me->GetCharmInfo()->SetIsCommandAttack(false);
                HandleReturnMovement();
            }
        }
        else
        {
            me->GetCharmInfo()->SetIsCommandAttack(false);
            HandleReturnMovement();
        }
    }
    else if (owner && !me->HasUnitState(UNIT_STATE_FOLLOW)) // no charm info and no victim
        HandleReturnMovement();

    if (!me->GetCharmInfo())
        return;

    // Autocast (casted only in combat or persistent spells in any state)
    if (!me->HasUnitState(UNIT_STATE_CASTING))
    {
        typedef std::vector<std::pair<Unit*, Spell*> > TargetSpellList;
        TargetSpellList targetSpellStore;

        for (uint8 i = 0; i < me->GetPetAutoSpellSize(); ++i)
        {
            uint32 spellID = me->GetPetAutoSpellOnPos(i);
            if (!spellID)
                continue;

            SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellID);
            if (!spellInfo)
                continue;

            if (me->GetCharmInfo() && me->GetCharmInfo()->GetGlobalCooldownMgr().HasGlobalCooldown(spellInfo))
                continue;

            if (spellInfo->IsPositive())
            {
                if (spellInfo->CanBeUsedInCombat())
                {
                    // check spell cooldown
                    if (me->HasSpellCooldown(spellInfo->Id))
                        continue;

                    // Check if we're in combat or commanded to attack
                    if (!me->isInCombat() && !me->GetCharmInfo()->IsCommandAttack())
                        continue;
                }

                Spell* spell = new Spell(me, spellInfo, TRIGGERED_NONE, 0);
                bool spellUsed = false;

                // Some spells can target enemy or friendly (DK Ghoul's Leap)
                // Check for enemy first (pet then owner)
                Unit* target = me->getAttackerForHelper();
                if (!target && owner)
                    target = owner->getAttackerForHelper();

                if (target)
                {
                    if (CanAttack(target) && spell->CanAutoCast(target))
                    {
                        targetSpellStore.push_back(std::make_pair(target, spell));
                        spellUsed = true;
                    }
                }

                // No enemy, check friendly
                if (!spellUsed)
                {
                    for (std::set<uint64>::const_iterator tar = m_AllySet.begin(); tar != m_AllySet.end(); ++tar)
                    {
                        Unit* ally = ObjectAccessor::GetUnit(*me, *tar);

                        //only buff targets that are in combat, unless the spell can only be cast while out of combat
                        if (!ally)
                            continue;

                        if (spell->CanAutoCast(ally))
                        {
                            targetSpellStore.push_back(std::make_pair(ally, spell));
                            spellUsed = true;
                            break;
                        }
                    }
                }

                // No valid targets at all
                if (!spellUsed)
                    delete spell;
            }
            else if (me->getVictim() && CanAttack(me->getVictim()) && spellInfo->CanBeUsedInCombat())
            {
                Spell* spell = new Spell(me, spellInfo, TRIGGERED_NONE, 0);
                if (spell->CanAutoCast(me->getVictim()))
                    targetSpellStore.push_back(std::make_pair(me->getVictim(), spell));
                else
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
    Group* group = NULL;

    m_updateAlliesTimer = 10*IN_MILLISECONDS;                //update friendly targets every 10 seconds, lesser checks increase performance

    if (!owner)
        return;
    else if (owner->GetTypeId() == TYPEID_PLAYER)
        group = owner->ToPlayer()->GetGroup();

    //only pet and owner/not in group->ok
    if (m_AllySet.size() == 2 && !group)
        return;
    //owner is in group; group members filled in already (no raid -> subgroupcount = whole count)
    if (group && !group->isRaidGroup() && m_AllySet.size() == (group->GetMembersCount() + 2))
        return;

    m_AllySet.clear();
    m_AllySet.insert(me->GetGUID());
    if (group)                                              //add group
    {
        for (GroupReference* itr = group->GetFirstMember(); itr != NULL; itr = itr->next())
        {
            Player* Target = itr->getSource();
            if (!Target || !group->SameSubGroup((Player*)owner, Target))
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
    me->InterruptNonMeleeSpells(false);
    me->SendMeleeAttackStop();  // Stops the pet's 'Attack' button from flashing

    Unit* nextTarget = SelectNextTarget();

    if (nextTarget)
        AttackStart(nextTarget);
    else
    {
        me->GetCharmInfo()->SetIsCommandAttack(false);
        HandleReturnMovement(); // Return
    }
}

void PetAI::AttackStart(Unit* target)
{
    // Overrides Unit::AttackStart to correctly evaluate Pet states

    // Check all pet states to decide if we can attack this target
    if (!CanAttack(target))
        return;

    if (Unit* owner = me->GetOwner())
        owner->SetInCombatWith(target);

    // Only chase if not commanded to stay or if stay but commanded to attack
    DoAttack(target, (!me->GetCharmInfo()->HasCommandState(COMMAND_STAY) || me->GetCharmInfo()->IsCommandAttack()));
}

void PetAI::OwnerDamagedBy(Unit* attacker)
{
    // Called when owner takes damage. Allows defensive pets to know
    //  that their owner might need help

    if (!attacker)
        return;

    // Passive pets don't do anything
    if (me->HasReactState(REACT_PASSIVE))
        return;

    // Prevent pet from disengaging from current target
    if (me->getVictim() && me->getVictim()->isAlive())
        return;

    // Continue to evaluate and attack if necessary
    AttackStart(attacker);
}

void PetAI::OwnerAttacked(Unit* target)
{
    // Called when owner attacks something. Allows defensive pets to know
    //  that they need to assist

    // Target might be NULL if called from spell with invalid cast targets
    if (!target)
        return;

    // Passive pets don't do anything
    if (me->HasReactState(REACT_PASSIVE))
        return;

    // Prevent pet from disengaging from current target
    if (me->getVictim() && me->getVictim()->isAlive())
        return;

    // Continue to evaluate and attack if necessary
    AttackStart(target);
}

Unit* PetAI::SelectNextTarget()
{
    // Provides next target selection after current target death
    // Targets are not evaluated here for being valid attack targets

    // Passive pets don't do next target selection
    if (me->HasReactState(REACT_PASSIVE))
        return NULL;

    // Check pet attackers first so we don't drag a bunch of targets to the owner
    if (Unit* myAttacker = me->getAttackerForHelper())
        if (!myAttacker->HasBreakableByDamageCrowdControlAura())
            return myAttacker;

    // Not sure why we wouldn't have an owner but just in case...
    if (!me->GetCharmerOrOwner())
        return NULL;

    // Check owner attackers
    if (Unit* ownerAttacker = me->GetCharmerOrOwner()->getAttackerForHelper())
        if (!ownerAttacker->HasBreakableByDamageCrowdControlAura())
            return ownerAttacker;

    // Check owner victim
    // 3.0.2 - Pets now start attacking their owners victim in defensive mode as soon as the hunter does
    if (Unit* ownerVictim = me->GetCharmerOrOwner()->getVictim())
        if (!ownerVictim->HasBreakableByDamageCrowdControlAura())
            return ownerVictim;

    // Neither pet or owner had a target and aggressive pets can pick any target
    // Note: Creature::SelectNearestTarget() If no distance is supplied it uses MAX_VISIBILITY_DISTANCE
    // We also want to lock this to LOS so pet doesn't go running through walls and stuff
    if (me->HasReactState(REACT_AGGRESSIVE))
        if (Unit* nearTarget = me->ToCreature()->SelectNearestTarget())
            if (nearTarget->IsHostileTo(me) && !nearTarget->HasBreakableByDamageCrowdControlAura())
                if (nearTarget->IsWithinLOS(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ()))
                    return nearTarget;

    // Default - no valid targets
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
            break;
        }
        case FOLLOW_MOTION_TYPE:
        {
            // If data is owner's GUIDLow then we've reached follow point,
            // otherwise we're probably chasing a creature
            if (me->GetCharmerOrOwner() && me->GetCharmInfo() && data == me->GetCharmerOrOwner()->GetGUIDLow() && me->GetCharmInfo()->IsReturning())
            {
                me->GetCharmInfo()->SetIsAtStay(false);
                me->GetCharmInfo()->SetIsReturning(false);
                me->GetCharmInfo()->SetIsFollowing(true);
                me->GetCharmInfo()->SetIsCommandAttack(false);
            }
            break;
        }
        default:
            break;
    }
}

bool PetAI::CanAttack(Unit* target)
{
    // Evaluates wether a pet can attack a specific
    // target based on CommandState, ReactState and other flags

    // Can't attack dead targets...
    if (!target->isAlive())
        return false;

    // Returning - check first since pets returning ignore attacks
    if (me->GetCharmInfo()->IsReturning())
        return false;

    // Passive - check now so we don't have to worry about passive in later checks
    if (me->HasReactState(REACT_PASSIVE))
        return me->GetCharmInfo()->IsCommandAttack();

    // Follow
    if (me->GetCharmInfo()->HasCommandState(COMMAND_FOLLOW))
        return true;

    // Stay - can attack if target is within range or commanded to
    if (me->GetCharmInfo()->HasCommandState(COMMAND_STAY))
        return (me->IsWithinMeleeRange(target) || me->GetCharmInfo()->IsCommandAttack());

    //  Pets commanded to attack should not stop their approach if attacked by another creature
    if (me->getVictim() && (me->getVictim() != target))
        return !me->GetCharmInfo()->IsCommandAttack();

    // default, though we shouldn't ever get here
    return false;
}

void PetAI::ReceiveEmote(Player* player, uint32 emote)
{
    if (me->GetOwnerGUID() && me->GetOwnerGUID() == player->GetGUID())
        switch (emote)
        {
            case TEXT_EMOTE_COWER:
                if (me->isPet() && me->ToPet()->IsPetGhoul())
                    me->HandleEmoteCommand(EMOTE_ONESHOT_ROAR);
                break;
            case TEXT_EMOTE_ANGRY:
                if (me->isPet() && me->ToPet()->IsPetGhoul())
                    me->HandleEmoteCommand(EMOTE_ONESHOT_COWER);
                break;
        }
}
