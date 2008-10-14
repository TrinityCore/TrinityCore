/*
 * Copyright (C) 2008 Trinity <http://www.trinitycore.org/>
 *
 * Thanks to the original authors: MaNGOS <http://www.mangosproject.org/>
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

#include "PetAI.h"
#include "Errors.h"
#include "Pet.h"
#include "Player.h"
#include "Database/DBCStores.h"
#include "Spell.h"
#include "ObjectAccessor.h"
#include "SpellMgr.h"
#include "Creature.h"
#include "World.h"
#include "Util.h"

int PetAI::Permissible(const Creature *creature)
{
    if( creature->isPet())
        return PERMIT_BASE_SPECIAL;

    return PERMIT_BASE_NO;
}

PetAI::PetAI(Creature &c) : i_pet(c), i_victimGuid(0), i_tracker(TIME_INTERVAL_LOOK)
{
    m_AllySet.clear();
    UpdateAllies();
}

void PetAI::MoveInLineOfSight(Unit *u)
{
    if( !i_pet.getVictim() && i_pet.GetCharmInfo() &&
        i_pet.GetCharmInfo()->HasReactState(REACT_AGGRESSIVE) &&
        u->isTargetableForAttack() && i_pet.IsHostileTo( u ) &&
        u->isInAccessablePlaceFor(&i_pet))
    {
        float attackRadius = i_pet.GetAttackDistance(u);
        if(i_pet.IsWithinDistInMap(u, attackRadius) && i_pet.GetDistanceZ(u) <= CREATURE_Z_ATTACK_RANGE)
        {
            if(i_pet.IsWithinLOSInMap(u))
            {
                AttackStart(u);
                u->RemoveSpellsCausingAura(SPELL_AURA_MOD_STEALTH);
            }
        }
    }
}

void PetAI::AttackStart(Unit *u)
{
    if( i_pet.getVictim() || !u || i_pet.isPet() && ((Pet&)i_pet).getPetType()==MINI_PET )
        return;

    if(i_pet.Attack(u,true))
    {
        i_pet.clearUnitState(UNIT_STAT_FOLLOW);
        // TMGs call CreatureRelocation which via MoveInLineOfSight can call this function
        // thus with the following clear the original TMG gets invalidated and crash, doh
        // hope it doesn't start to leak memory without this :-/
        //i_pet->Clear();
        i_victimGuid = u->GetGUID();
        i_pet.GetMotionMaster()->MoveChase(u);
    }
}

void PetAI::EnterEvadeMode()
{
}

bool PetAI::IsVisible(Unit *pl) const
{
    return _isVisible(pl);
}

bool PetAI::_needToStop() const
{
    if(!i_pet.getVictim() || !i_pet.isAlive())
        return true;

    // This is needed for charmed creatures, as once their target was reset other effects can trigger threat
    if(i_pet.isCharmed() && i_pet.getVictim() == i_pet.GetCharmer())
        return true;

    return !i_pet.getVictim()->isTargetableForAttack();
}

void PetAI::_stopAttack()
{
    if( !i_victimGuid )
        return;

    Unit* victim = ObjectAccessor::GetUnit(i_pet, i_victimGuid );

    if ( !victim )
        return;

    assert(!i_pet.getVictim() || i_pet.getVictim() == victim);

    if( !i_pet.isAlive() )
    {
        DEBUG_LOG("Creature stoped attacking cuz his dead [guid=%u]", i_pet.GetGUIDLow());
        i_pet.StopMoving();
        i_pet.GetMotionMaster()->Clear();
        i_pet.GetMotionMaster()->MoveIdle();
        i_victimGuid = 0;
        i_pet.CombatStop();
        i_pet.getHostilRefManager().deleteReferences();

        return;
    }
    else if( !victim  )
    {
        DEBUG_LOG("Creature stopped attacking because victim is non exist [guid=%u]", i_pet.GetGUIDLow());
    }
    else if( !victim->isAlive() )
    {
        DEBUG_LOG("Creature stopped attacking cuz his victim is dead [guid=%u]", i_pet.GetGUIDLow());
    }
    else if( victim->HasStealthAura() )
    {
        DEBUG_LOG("Creature stopped attacking cuz his victim is stealth [guid=%u]", i_pet.GetGUIDLow());
    }
    else if( victim->isInFlight() )
    {
        DEBUG_LOG("Creature stopped attacking cuz his victim is fly away [guid=%u]", i_pet.GetGUIDLow());
    }
    else
    {
        DEBUG_LOG("Creature stopped attacking due to target out run him [guid=%u]", i_pet.GetGUIDLow());
    }

    Unit* owner = i_pet.GetCharmerOrOwner();

    if(owner && i_pet.GetCharmInfo() && i_pet.GetCharmInfo()->HasCommandState(COMMAND_FOLLOW))
    {
        i_pet.GetMotionMaster()->MoveFollow(owner,PET_FOLLOW_DIST,PET_FOLLOW_ANGLE);
    }
    else
    {
        i_pet.clearUnitState(UNIT_STAT_FOLLOW);
        i_pet.GetMotionMaster()->Clear();
        i_pet.GetMotionMaster()->MoveIdle();
    }
    i_victimGuid = 0;
    i_pet.AttackStop();
}

void PetAI::UpdateAI(const uint32 diff)
{
    // update i_victimGuid if i_pet.getVictim() !=0 and changed
    if(i_pet.getVictim())
        i_victimGuid = i_pet.getVictim()->GetGUID();

    Unit* owner = i_pet.GetCharmerOrOwner();

    if(m_updateAlliesTimer <= diff)
        // UpdateAllies self set update timer
        UpdateAllies();
    else
        m_updateAlliesTimer -= diff;

    // i_pet.getVictim() can't be used for check in case stop fighting, i_pet.getVictim() clear at Unit death etc.
    if( i_victimGuid )
    {
        if( _needToStop() )
        {
            DEBUG_LOG("Pet AI stoped attacking [guid=%u]", i_pet.GetGUIDLow());
            _stopAttack();                                  // i_victimGuid == 0 && i_pet.getVictim() == NULL now
            return;
        }
        else if( i_pet.IsStopped() || i_pet.IsWithinDistInMap(i_pet.getVictim(), ATTACK_DISTANCE))
        {
            // required to be stopped cases
            if ( i_pet.IsStopped() && i_pet.IsNonMeleeSpellCasted(false) )
            {
                if( i_pet.hasUnitState(UNIT_STAT_FOLLOW) )
                    i_pet.InterruptNonMeleeSpells(false);
                else
                    return;
            }
            // not required to be stopped case
            else if( i_pet.isAttackReady() && i_pet.canReachWithAttack(i_pet.getVictim()) )
            {
                i_pet.AttackerStateUpdate(i_pet.getVictim());

                i_pet.resetAttackTimer();

                if ( !i_pet.getVictim() )
                    return;

                //if pet misses its target, it will also be the first in threat list
                i_pet.getVictim()->AddThreat(&i_pet,0.0f);

                if( _needToStop() )
                    _stopAttack();
            }
        }
    }
    else if(owner && i_pet.GetCharmInfo())
    {
        if(owner->isInCombat() && !(i_pet.GetCharmInfo()->HasReactState(REACT_PASSIVE) || i_pet.GetCharmInfo()->HasCommandState(COMMAND_STAY)))
        {
            AttackStart(owner->getAttackerForHelper());
        }
        else if(i_pet.GetCharmInfo()->HasCommandState(COMMAND_FOLLOW))
        {
            if (!i_pet.hasUnitState(UNIT_STAT_FOLLOW) )
            {
                i_pet.GetMotionMaster()->MoveFollow(owner,PET_FOLLOW_DIST,PET_FOLLOW_ANGLE);
            }
        }
    }

    //Autocast
    HM_NAMESPACE::hash_map<uint32, Unit*> targetMap;
    targetMap.clear();
    SpellCastTargets NULLtargets;

    for (uint8 i = 0; i < i_pet.GetPetAutoSpellSize(); i++)
    {
        uint32 spellID = i_pet.GetPetAutoSpellOnPos(i);
        if (!spellID)
            continue;

        SpellEntry const *spellInfo = sSpellStore.LookupEntry(spellID);
        if (!spellInfo)
            continue;

        Spell *spell = new Spell(&i_pet, spellInfo, false, 0);

        if(!IsPositiveSpell(spellInfo->Id) && i_pet.getVictim() && !_needToStop() && !i_pet.hasUnitState(UNIT_STAT_FOLLOW) && spell->CanAutoCast(i_pet.getVictim()))
            targetMap[spellID] = i_pet.getVictim();
        else
        {
            spell->m_targets = NULLtargets;
            for(std::set<uint64>::iterator tar = m_AllySet.begin(); tar != m_AllySet.end(); ++tar)
            {
                Unit* Target = ObjectAccessor::GetUnit(i_pet,*tar);

                //only buff targets that are in combat, unless the spell can only be cast while out of combat
                if(!Target || (!Target->isInCombat() && !IsNonCombatSpell(spellInfo)))
                    continue;
                if(spell->CanAutoCast(Target))
                    targetMap[spellID] = Target;
            }
        }

        delete spell;
    }

    //found units to cast on to
    if(!targetMap.empty())
    {
        uint32 index = urand(1, targetMap.size());
        HM_NAMESPACE::hash_map<uint32, Unit*>::iterator itr;
        uint32 i;
        for(itr = targetMap.begin(), i = 1; i < index; ++itr, ++i);

        SpellEntry const *spellInfo = sSpellStore.LookupEntry(itr->first);

        Spell *spell = new Spell(&i_pet, spellInfo, false);

        SpellCastTargets targets;
        targets.setUnitTarget( itr->second );

        if(!i_pet.HasInArc(M_PI, itr->second))
        {
            i_pet.SetInFront(itr->second);
            if( itr->second->GetTypeId() == TYPEID_PLAYER )
                i_pet.SendUpdateToPlayer( (Player*)itr->second );

            if(owner && owner->GetTypeId() == TYPEID_PLAYER)
                i_pet.SendUpdateToPlayer( (Player*)owner );
        }

        i_pet.AddCreatureSpellCooldown(itr->first);
        if(i_pet.isPet())
            ((Pet*)&i_pet)->CheckLearning(itr->first);

        spell->prepare(&targets);
    }
    targetMap.clear();
}

bool PetAI::_isVisible(Unit *u) const
{
    //return false;                                           //( ((Creature*)&i_pet)->GetDistanceSq(u) * 1.0<= sWorld.getConfig(CONFIG_SIGHT_GUARDER) && !u->m_stealth && u->isAlive());
    return i_pet.GetDistance(u) < sWorld.getConfig(CONFIG_SIGHT_GUARDER)
        && u->isVisibleForOrDetect(&i_pet,true);
}

void PetAI::UpdateAllies()
{
    Unit* owner = i_pet.GetCharmerOrOwner();
    Group *pGroup = NULL;

    m_updateAlliesTimer = 10000;                            //update friendly targets every 10 seconds, lesser checks increase performance

    if(!owner)
        return;
    else if(owner->GetTypeId() == TYPEID_PLAYER)
        pGroup = ((Player*)owner)->GetGroup();

    //only pet and owner/not in group->ok
    if(m_AllySet.size() == 2 && !pGroup)
        return;
    //owner is in group; group members filled in already (no raid -> subgroupcount = whole count)
    if(pGroup && !pGroup->isRaidGroup() && m_AllySet.size() == (pGroup->GetMembersCount() + 2))
        return;

    m_AllySet.clear();
    m_AllySet.insert(i_pet.GetGUID());
    if(pGroup)                                              //add group
    {
        for(GroupReference *itr = pGroup->GetFirstMember(); itr != NULL; itr = itr->next())
        {
            Player* Target = itr->getSource();
            if(!Target || !pGroup->SameSubGroup((Player*)owner, Target))
                continue;

            if(Target->GetGUID() == owner->GetGUID())
                continue;

            m_AllySet.insert(Target->GetGUID());
        }
    }
    else                                                    //remove group
        m_AllySet.insert(owner->GetGUID());
}

void PetAI::AttackedBy(Unit *attacker)
{
    //when attacked, fight back in case 1)no victim already AND 2)not set to passive AND 3)not set to stay, unless can it can reach attacker with melee attack anyway
    if(!i_pet.getVictim() && i_pet.GetCharmInfo() && !i_pet.GetCharmInfo()->HasReactState(REACT_PASSIVE) &&
        (!i_pet.GetCharmInfo()->HasCommandState(COMMAND_STAY) || i_pet.canReachWithAttack(attacker)))
        AttackStart(attacker);
}
