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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "Common.h"
#include "Log.h"
#include "Opcodes.h"
#include "WorldPacket.h"
#include "WorldSession.h"
#include "World.h"
#include "ObjectMgr.h"
#include "SpellMgr.h"
#include "Unit.h"
#include "QuestDef.h"
#include "Player.h"
#include "Creature.h"
#include "Spell.h"
#include "Group.h"
#include "SpellAuras.h"
#include "MapManager.h"
#include "ObjectAccessor.h"
#include "CreatureAI.h"
#include "Formulas.h"
#include "Pet.h"
#include "Util.h"
#include "Totem.h"
#include "BattleGround.h"
#include "OutdoorPvP.h"
#include "InstanceSaveMgr.h"
#include "GridNotifiersImpl.h"
#include "CellImpl.h"
#include "Path.h"
#include "CreatureGroups.h"
#include "PetAI.h"
#include "NullCreatureAI.h"
#include "Traveller.h"
#include "TemporarySummon.h"
#include "Vehicle.h"
#include "Transports.h"

#include <math.h>

float baseMoveSpeed[MAX_MOVE_TYPE] =
{
    2.5f,                                                   // MOVE_WALK
    7.0f,                                                   // MOVE_RUN
    1.25f,                                                  // MOVE_RUN_BACK
    4.722222f,                                              // MOVE_SWIM
    4.5f,                                                   // MOVE_SWIM_BACK
    3.141594f,                                              // MOVE_TURN_RATE
    7.0f,                                                   // MOVE_FLIGHT
    4.5f,                                                   // MOVE_FLIGHT_BACK
    3.14f                                                   // MOVE_PITCH_RATE
};

// Used for prepare can/can`t triggr aura
static bool InitTriggerAuraData();
// Define can trigger auras
static bool isTriggerAura[TOTAL_AURAS];
// Define can`t trigger auras (need for disable second trigger)
static bool isNonTriggerAura[TOTAL_AURAS];
// Prepare lists
static bool procPrepared = InitTriggerAuraData();

Unit::Unit()
: WorldObject(), i_motionMaster(this), m_ThreatManager(this), m_HostilRefManager(this)
, m_IsInNotifyList(false), m_Notified(false), IsAIEnabled(false), NeedChangeAI(false)
, i_AI(NULL), i_disabledAI(NULL), m_removedAurasCount(0), m_Vehicle(NULL), m_transport(NULL)
, m_ControlledByPlayer(false)
{
    m_objectType |= TYPEMASK_UNIT;
    m_objectTypeId = TYPEID_UNIT;
                                                            // 2.3.2 - 0x70
    m_updateFlag = (UPDATEFLAG_LOWGUID | UPDATEFLAG_HIGHGUID | UPDATEFLAG_LIVING | UPDATEFLAG_HAS_POSITION);

    m_attackTimer[BASE_ATTACK]   = 0;
    m_attackTimer[OFF_ATTACK]    = 0;
    m_attackTimer[RANGED_ATTACK] = 0;
    m_modAttackSpeedPct[BASE_ATTACK] = 1.0f;
    m_modAttackSpeedPct[OFF_ATTACK] = 1.0f;
    m_modAttackSpeedPct[RANGED_ATTACK] = 1.0f;

    m_extraAttacks = 0;
    m_canDualWield = false;

    m_state = 0;
    m_form = FORM_NONE;
    m_deathState = ALIVE;

    for (uint32 i = 0; i < CURRENT_MAX_SPELL; i++)
        m_currentSpells[i] = NULL;

    m_addDmgOnce = 0;

    for(int i = 0; i < MAX_SUMMON_SLOT; ++i)
        m_SummonSlot[i] = 0;

    m_ObjectSlot[0] = m_ObjectSlot[1] = m_ObjectSlot[2] = m_ObjectSlot[3] = 0;
    //m_Aura = NULL;
    //m_AurasCheck = 2000;
    //m_removeAuraTimer = 4;
    //tmpAura = NULL;

    m_Visibility = VISIBILITY_ON;

    m_interruptMask = 0;
    m_detectInvisibilityMask = 0;
    m_invisibilityMask = 0;
    m_transform = 0;
    m_ShapeShiftFormSpellId = 0;
    m_canModifyStats = false;

    for (int i = 0; i < MAX_SPELL_IMMUNITY; ++i)
        m_spellImmune[i].clear();
    for (int i = 0; i < UNIT_MOD_END; ++i)
    {
        m_auraModifiersGroup[i][BASE_VALUE] = 0.0f;
        m_auraModifiersGroup[i][BASE_PCT] = 1.0f;
        m_auraModifiersGroup[i][TOTAL_VALUE] = 0.0f;
        m_auraModifiersGroup[i][TOTAL_PCT] = 1.0f;
    }
                                                            // implement 50% base damage from offhand
    m_auraModifiersGroup[UNIT_MOD_DAMAGE_OFFHAND][TOTAL_PCT] = 0.5f;

    for (int i = 0; i < MAX_ATTACK; ++i)
    {
        m_weaponDamage[i][MINDAMAGE] = BASE_MINDAMAGE;
        m_weaponDamage[i][MAXDAMAGE] = BASE_MAXDAMAGE;
    }
    for (int i = 0; i < MAX_STATS; ++i)
        m_createStats[i] = 0.0f;

    m_attacking = NULL;
    m_modMeleeHitChance = 0.0f;
    m_modRangedHitChance = 0.0f;
    m_modSpellHitChance = 0.0f;
    m_baseSpellCritChance = 5;

    m_CombatTimer = 0;
    m_lastManaUse = 0;

    //m_victimThreat = 0.0f;
    for (int i = 0; i < MAX_SPELL_SCHOOL; ++i)
        m_threatModifier[i] = 1.0f;
    m_isSorted = true;
    for (int i = 0; i < MAX_MOVE_TYPE; ++i)
        m_speed_rate[i] = 1.0f;

    m_charmInfo = NULL;
    m_unit_movement_flags = 0;
    m_reducedThreatPercent = 0;
    m_misdirectionTargetGUID = 0;

    // remove aurastates allowing special moves
    for(int i=0; i < MAX_REACTIVE; ++i)
        m_reactiveTimer[i] = 0;
}

Unit::~Unit()
{
    // set current spells as deletable
    for (uint32 i = 0; i < CURRENT_MAX_SPELL; i++)
    {
        if (m_currentSpells[i])
        {
            m_currentSpells[i]->SetReferencedFromCurrent(false);
            m_currentSpells[i] = NULL;
        }
    }

    RemoveAllGameObjects();
    RemoveAllDynObjects();

    if(m_charmInfo) delete m_charmInfo;

    assert(!m_attacking);
    assert(m_attackers.empty());
    assert(m_sharedVision.empty());
    assert(m_Controlled.empty());
}

void Unit::Update( uint32 p_time )
{
    /*if(p_time > m_AurasCheck)
    {
    m_AurasCheck = 2000;
    _UpdateAura();
    }else
    m_AurasCheck -= p_time;*/

    // WARNING! Order of execution here is important, do not change.
    // Spells must be processed with event system BEFORE they go to _UpdateSpells.
    // Or else we may have some SPELL_STATE_FINISHED spells stalled in pointers, that is bad.
    m_Events.Update( p_time );
    _UpdateSpells( p_time );

    // update combat timer only for players and pets
    if (isInCombat() && (GetTypeId() == TYPEID_PLAYER || ((Creature*)this)->isPet() || ((Creature*)this)->isCharmed()))
    {
        // Check UNIT_STAT_MELEE_ATTACKING or UNIT_STAT_CHASE (without UNIT_STAT_FOLLOW in this case) so pets can reach far away
        // targets without stopping half way there and running off.
        // These flags are reset after target dies or another command is given.
        if( m_HostilRefManager.isEmpty() )
        {
            // m_CombatTimer set at aura start and it will be freeze until aura removing
            if ( m_CombatTimer <= p_time )
                ClearInCombat();
            else
                m_CombatTimer -= p_time;
        }
    }

    //not implemented before 3.0.2
    //if(!hasUnitState(UNIT_STAT_CASTING))
    {
        if(uint32 base_att = getAttackTimer(BASE_ATTACK))
            setAttackTimer(BASE_ATTACK, (p_time >= base_att ? 0 : base_att - p_time) );
        if(uint32 ranged_att = getAttackTimer(RANGED_ATTACK))
            setAttackTimer(RANGED_ATTACK, (p_time >= ranged_att ? 0 : ranged_att - p_time) );
        if(uint32 off_att = getAttackTimer(OFF_ATTACK))
            setAttackTimer(OFF_ATTACK, (p_time >= off_att ? 0 : off_att - p_time) );
    }

    // update abilities available only for fraction of time
    UpdateReactives( p_time );

    ModifyAuraState(AURA_STATE_HEALTHLESS_20_PERCENT, GetHealth() < GetMaxHealth()*0.20f);
    ModifyAuraState(AURA_STATE_HEALTHLESS_35_PERCENT, GetHealth() < GetMaxHealth()*0.35f);
    ModifyAuraState(AURA_STATE_HEALTH_ABOVE_75_PERCENT, GetHealth() > GetMaxHealth()*0.75f);

    i_motionMaster.UpdateMotion(p_time);
}

bool Unit::haveOffhandWeapon() const
{
    if(GetTypeId() == TYPEID_PLAYER)
        return ((Player*)this)->GetWeaponForAttack(OFF_ATTACK,true);
    else
        return m_canDualWield;
}

void Unit::SendMonsterMoveWithSpeedToCurrentDestination(Player* player)
{
    float x, y, z;
    if(GetMotionMaster()->GetDestination(x, y, z))
        SendMonsterMoveWithSpeed(x, y, z, 0, player);
}

void Unit::SendMonsterMoveWithSpeed(float x, float y, float z, uint32 transitTime, Player* player)
{
    if (!transitTime)
    {
        if(GetTypeId()==TYPEID_PLAYER)
        {
            Traveller<Player> traveller(*(Player*)this);
            transitTime = traveller.GetTotalTrevelTimeTo(x,y,z);
        }
        else
        {
            Traveller<Creature> traveller(*(Creature*)this);
            transitTime = traveller.GetTotalTrevelTimeTo(x,y,z);
        }
    }
    //float orientation = (float)atan2((double)dy, (double)dx);
    SendMonsterMove(x, y, z, transitTime, player);
}

void Unit::SendMonsterStop()
{
    WorldPacket data( SMSG_MONSTER_MOVE, (17 + GetPackGUID().size()) );
    data.append(GetPackGUID());
    data << GetPositionX() << GetPositionY() << GetPositionZ();
    data << getMSTime();
    data << uint8(1);
    SendMessageToSet(&data, true);

    clearUnitState(UNIT_STAT_MOVE);
}

void Unit::SendMonsterMove(float NewPosX, float NewPosY, float NewPosZ, uint32 Time, Player* player)
{
    WorldPacket data( SMSG_MONSTER_MOVE, 12+4+1+4+4+4+12+GetPackGUID().size());
    data.append(GetPackGUID());

    data << GetPositionX() << GetPositionY() << GetPositionZ();
    data << getMSTime();

    data << uint8(0);
    data << uint32((GetUnitMovementFlags() & MOVEMENTFLAG_LEVITATING) ? MOVEFLAG_FLY : MOVEFLAG_WALK);

    data << Time;                                           // Time in between points
    data << uint32(1);                                      // 1 single waypoint
    data << NewPosX << NewPosY << NewPosZ;                  // the single waypoint Point B

    if(player)
        player->GetSession()->SendPacket(&data);
    else
        SendMessageToSet( &data, true );

    addUnitState(UNIT_STAT_MOVE);
}

void Unit::SendMonsterMove(float NewPosX, float NewPosY, float NewPosZ, uint32 MoveFlags, uint32 time, float speedZ, Player *player)
{
    WorldPacket data( SMSG_MONSTER_MOVE, 12+4+1+4+4+4+12+GetPackGUID().size());
    data.append(GetPackGUID());

    data << GetPositionX() << GetPositionY() << GetPositionZ();
    data << getMSTime();

    data << uint8(0);
    data << MoveFlags;

    if(MoveFlags & MOVEFLAG_JUMP)
    {
        data << time;
        data << speedZ;
        data << (uint32)0; // walk time after jump
    }
    else
        data << time;

    data << uint32(1);                                      // 1 single waypoint
    data << NewPosX << NewPosY << NewPosZ;                  // the single waypoint Point B

    if(player)
        player->GetSession()->SendPacket(&data);
    else
        SendMessageToSet( &data, true );
}

/*void Unit::SendMonsterMove(float NewPosX, float NewPosY, float NewPosZ, uint8 type, uint32 MovementFlags, uint32 Time, Player* player)
{
    WorldPacket data( SMSG_MONSTER_MOVE, (41 + GetPackGUID().size()) );
    data.append(GetPackGUID());

    data << GetPositionX() << GetPositionY() << GetPositionZ();
    data << uint32(getMSTime());

    data << uint8(type);                                    // unknown
    switch(type)
    {
        case 0:                                             // normal packet
            break;
        case 1:                                             // stop packet (raw pos?)
            SendMessageToSet( &data, true );
            return;
        case 2:                                             // facing spot, not used currently
            data << float(0);
            data << float(0);
            data << float(0);
            break;
        case 3:                                             // not used currently
            data << uint64(0);                              // probably target guid (facing target?)
            break;
        case 4:                                             // not used currently
            data << float(0);                               // facing angle
            break;
    }

    data << uint32(MovementFlags);
    data << uint32(Time);                                   // Time in between points
    data << uint32(1);                                      // 1 single waypoint
    data << NewPosX << NewPosY << NewPosZ;                  // the single waypoint Point B

    if(player)
        player->GetSession()->SendPacket(&data);
    else
        SendMessageToSet( &data, true );
}*/

void Unit::SendMonsterMoveByPath(Path const& path, uint32 start, uint32 end)
{
    uint32 traveltime = uint32(path.GetTotalLength(start, end) * 32);

    uint32 pathSize = end-start;

    WorldPacket data( SMSG_MONSTER_MOVE, (GetPackGUID().size()+4+4+4+4+1+4+4+4+pathSize*4*3) );
    data.append(GetPackGUID());
    data << GetPositionX();
    data << GetPositionY();
    data << GetPositionZ();
    data << getMSTime();
    data << uint8( 0 );
    data << uint32(((GetUnitMovementFlags() & MOVEMENTFLAG_LEVITATING) || isInFlight())? (MOVEFLAG_FLY|MOVEFLAG_WALK) : MOVEFLAG_WALK);
    data << uint32( traveltime );
    data << uint32( pathSize );
    data.append( (char*)path.GetNodes(start), pathSize * 4 * 3 );
    SendMessageToSet(&data, true);

    addUnitState(UNIT_STAT_MOVE);
}

void Unit::resetAttackTimer(WeaponAttackType type)
{
    m_attackTimer[type] = uint32(GetAttackTime(type) * m_modAttackSpeedPct[type]);
}

bool Unit::IsWithinCombatRange(Unit *obj, float dist2compare) const
{
    if (!obj || !IsInMap(obj)) return false;

    float dx = GetPositionX() - obj->GetPositionX();
    float dy = GetPositionY() - obj->GetPositionY();
    float dz = GetPositionZ() - obj->GetPositionZ();
    float distsq = dx*dx + dy*dy + dz*dz;

    float sizefactor = GetCombatReach() + obj->GetCombatReach();
    float maxdist = dist2compare + sizefactor;

    return distsq < maxdist * maxdist;
}

bool Unit::IsWithinMeleeRange(Unit *obj, float dist) const
{
    if (!obj || !IsInMap(obj)) return false;

    float dx = GetPositionX() - obj->GetPositionX();
    float dy = GetPositionY() - obj->GetPositionY();
    float dz = GetPositionZ() - obj->GetPositionZ();
    float distsq = dx*dx + dy*dy + dz*dz;

    float sizefactor = GetMeleeReach() + obj->GetMeleeReach();
    float maxdist = dist + sizefactor;

    return distsq < maxdist * maxdist;
}

void Unit::GetRandomContactPoint( const Unit* obj, float &x, float &y, float &z, float distance2dMin, float distance2dMax ) const
{
    float combat_reach = GetCombatReach();
    if(combat_reach < 0.1) // sometimes bugged for players
    {
        //sLog.outError("Unit %u (Type: %u) has invalid combat_reach %f",GetGUIDLow(),GetTypeId(),combat_reach);
       // if(GetTypeId() ==  TYPEID_UNIT)
          //  sLog.outError("Creature entry %u has invalid combat_reach", ((Creature*)this)->GetEntry());
        combat_reach = DEFAULT_COMBAT_REACH;
    }
    uint32 attacker_number = getAttackers().size();
    if(attacker_number > 0) --attacker_number;
    GetNearPoint(obj,x,y,z,obj->GetCombatReach(), distance2dMin+(distance2dMax-distance2dMin)*rand_norm()
        , GetAngle(obj) + (attacker_number ? (M_PI/2 - M_PI * rand_norm()) * (float)attacker_number / combat_reach / 3 : 0));
}

void Unit::RemoveMovementImpairingAuras()
{
    for(AuraMap::iterator iter = m_Auras.begin(); iter != m_Auras.end();)
    {
        if(spellmgr.GetSpellCustomAttr(iter->second->GetId()) & SPELL_ATTR_CU_MOVEMENT_IMPAIR)
            RemoveAura(iter);
        else
            ++iter;
    }
}

void Unit::RemoveAurasWithInterruptFlags(uint32 flag, uint32 except)
{
    if(!(m_interruptMask & flag))
        return;

    // interrupt auras
    for (AuraList::iterator iter = m_interruptableAuras.begin(); iter != m_interruptableAuras.end();)
    {
        Aura * aur = *iter;
        ++iter;
        if ((aur->GetSpellProto()->AuraInterruptFlags & flag) && (!except || aur->GetId() != except))
        {
            uint32 removedAuras = m_removedAurasCount;
            RemoveAura(aur, AURA_REMOVE_BY_ENEMY_SPELL);
            if (removedAuras+1 < m_removedAurasCount)
                iter=m_interruptableAuras.begin();
        }
    }

    // interrupt channeled spell
    if(Spell* spell = m_currentSpells[CURRENT_CHANNELED_SPELL])
        if(spell->getState() == SPELL_STATE_CASTING
            && (spell->m_spellInfo->ChannelInterruptFlags & flag)
            && spell->m_spellInfo->Id != except)
            InterruptNonMeleeSpells(false);

    UpdateInterruptMask();
}

void Unit::UpdateInterruptMask()
{
    m_interruptMask = 0;
    for(AuraList::iterator i = m_interruptableAuras.begin(); i != m_interruptableAuras.end(); ++i)
    {
        if(*i)
            m_interruptMask |= (*i)->GetSpellProto()->AuraInterruptFlags;
    }
    if(Spell* spell = m_currentSpells[CURRENT_CHANNELED_SPELL])
        if(spell->getState() == SPELL_STATE_CASTING)
            m_interruptMask |= spell->m_spellInfo->ChannelInterruptFlags;
}

/* Called by DealDamage for auras that have a chance to be dispelled on damage taken. */
void Unit::RemoveSpellbyDamageTaken(uint32 damage, uint32 spell)
{
    // The chance to dispel an aura depends on the damage taken with respect to the casters level.
    uint32 max_dmg = getLevel() > 8 ? 25 * getLevel() - 150 : 50;
    float chance = float(damage) / max_dmg * 100.0f;

    std::queue < std::pair < uint32, uint64 > > remove_list;

    for (AuraList::iterator iter = m_ccAuras.begin(); iter != m_ccAuras.end();++iter)
    {
       if((!spell || (*iter)->GetId() != spell) && roll_chance_f(chance))
       {
           remove_list.push(std::make_pair((*iter)->GetId(), (*iter)->GetCasterGUID() ) );
       }
    }

    for(;remove_list.size();remove_list.pop())
    {
        RemoveAura(remove_list.front().first, remove_list.front().second, AURA_REMOVE_BY_ENEMY_SPELL);
    }
}

uint32 Unit::DealDamage(Unit *pVictim, uint32 damage, CleanDamage const* cleanDamage, DamageEffectType damagetype, SpellSchoolMask damageSchoolMask, SpellEntry const *spellProto, bool durabilityLoss)
{
    if (!pVictim->isAlive() || pVictim->hasUnitState(UNIT_STAT_UNATTACKABLE) || pVictim->GetTypeId() == TYPEID_UNIT && ((Creature*)pVictim)->IsInEvadeMode())
        return 0;

    //You don't lose health from damage taken from another player while in a sanctuary
    //You still see it in the combat log though
    if(pVictim != this && GetTypeId() == TYPEID_PLAYER && pVictim->GetTypeId() == TYPEID_PLAYER)
    {
        const AreaTableEntry *area = GetAreaEntryByAreaID(pVictim->GetAreaId());
        if(area && area->flags & AREA_FLAG_SANCTUARY)       //sanctuary
            return 0;
    }

    //Script Event damage taken
    if( pVictim->GetTypeId()== TYPEID_UNIT && ((Creature *)pVictim)->IsAIEnabled )
    {
        ((Creature *)pVictim)->AI()->DamageTaken(this, damage);

        // Set tagging
        if(!pVictim->HasFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_OTHER_TAGGER) && !((Creature*)pVictim)->isPet())
        {
            //Set Loot
            switch(GetTypeId())
            {
                case TYPEID_PLAYER:
                {
                    ((Creature *)pVictim)->SetLootRecipient(this);
                    //Set tagged
                    ((Creature *)pVictim)->SetFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_OTHER_TAGGER);
                    break;
                }
                case TYPEID_UNIT:
                {
                    if(((Creature*)this)->isPet())
                    {
                        ((Creature *)pVictim)->SetLootRecipient(this->GetOwner());
                        ((Creature *)pVictim)->SetFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_OTHER_TAGGER);
                    }
                    break;
                }
            }
        }
    }

    if (damagetype != NODAMAGE)
    {
       // interrupting auras with AURA_INTERRUPT_FLAG_DAMAGE before checking !damage (absorbed damage breaks that type of auras)
       pVictim->RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_DAMAGE, spellProto ? spellProto->Id : 0);
       pVictim->RemoveSpellbyDamageTaken(damage, spellProto ? spellProto->Id : 0);
    }

    if(!damage)
    {
        // Rage from physical damage received .
        if(cleanDamage && cleanDamage->damage && (damageSchoolMask & SPELL_SCHOOL_MASK_NORMAL) && pVictim->GetTypeId() == TYPEID_PLAYER && (pVictim->getPowerType() == POWER_RAGE))
            ((Player*)pVictim)->RewardRage(cleanDamage->damage, 0, false);

        return 0;
    }

    // no xp,health if type 8 /critters/
    if(pVictim->GetTypeId() != TYPEID_PLAYER && pVictim->GetCreatureType() == CREATURE_TYPE_CRITTER)
    {
        // allow loot only if has loot_id in creature_template
        if(damage >= pVictim->GetHealth())
        {
            pVictim->setDeathState(JUST_DIED);
            pVictim->SetHealth(0);

            CreatureInfo const* cInfo = ((Creature*)pVictim)->GetCreatureInfo();
            if(cInfo && cInfo->lootid)
                pVictim->SetFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_LOOTABLE);

            // some critters required for quests
            if(GetTypeId() == TYPEID_PLAYER)
                ((Player*)this)->KilledMonster(pVictim->GetEntry(),pVictim->GetGUID());
        }
        else
            pVictim->ModifyHealth(- (int32)damage);

        return damage;
    }

    DEBUG_LOG("DealDamageStart");

    uint32 health = pVictim->GetHealth();
    sLog.outDetail("deal dmg:%d to health:%d ",damage,health);

    // duel ends when player has 1 or less hp
    bool duel_hasEnded = false;
    if(pVictim->GetTypeId() == TYPEID_PLAYER && ((Player*)pVictim)->duel && damage >= (health-1))
    {
        // prevent kill only if killed in duel and killed by opponent or opponent controlled creature
        if(((Player*)pVictim)->duel->opponent==this || ((Player*)pVictim)->duel->opponent->GetGUID() == GetOwnerGUID())
            damage = health-1;

        duel_hasEnded = true;
    }

    // Rage from Damage made (only from direct weapon damage)
    if( cleanDamage && damagetype==DIRECT_DAMAGE && this != pVictim && GetTypeId() == TYPEID_PLAYER && (getPowerType() == POWER_RAGE))
    {
        uint32 weaponSpeedHitFactor;

        switch(cleanDamage->attackType)
        {
            case BASE_ATTACK:
            {
                if(cleanDamage->hitOutCome == MELEE_HIT_CRIT)
                    weaponSpeedHitFactor = uint32(GetAttackTime(cleanDamage->attackType)/1000.0f * 7);
                else
                    weaponSpeedHitFactor = uint32(GetAttackTime(cleanDamage->attackType)/1000.0f * 3.5f);

                ((Player*)this)->RewardRage(damage, weaponSpeedHitFactor, true);

                break;
            }
            case OFF_ATTACK:
            {
                if(cleanDamage->hitOutCome == MELEE_HIT_CRIT)
                    weaponSpeedHitFactor = uint32(GetAttackTime(cleanDamage->attackType)/1000.0f * 3.5f);
                else
                    weaponSpeedHitFactor = uint32(GetAttackTime(cleanDamage->attackType)/1000.0f * 1.75f);

                ((Player*)this)->RewardRage(damage, weaponSpeedHitFactor, true);

                break;
            }
            case RANGED_ATTACK:
                break;
        }
    }

    if (GetTypeId() == TYPEID_PLAYER && this != pVictim)
    {
        Player *killer = ((Player*)this);

        // in bg, count dmg if victim is also a player
        if (pVictim->GetTypeId()==TYPEID_PLAYER)
        {
            if (BattleGround *bg = killer->GetBattleGround())
            {
                // FIXME: kept by compatibility. don't know in BG if the restriction apply.
                bg->UpdatePlayerScore(killer, SCORE_DAMAGE_DONE, damage);
            }
        }

        killer->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_DAMAGE_DONE, damage, 0, pVictim);
        killer->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_HIT_DEALT, damage);
    }

    if (pVictim->GetTypeId() == TYPEID_PLAYER)
        ((Player*)pVictim)->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_HIT_RECEIVED, damage);

    if (pVictim->GetTypeId() == TYPEID_UNIT && !((Creature*)pVictim)->isPet() && !((Creature*)pVictim)->hasLootRecipient())
        ((Creature*)pVictim)->SetLootRecipient(this);
    if (health <= damage)
    {
        DEBUG_LOG("DealDamage: victim just died");

        if (pVictim->GetTypeId() == TYPEID_PLAYER)
            ((Player*)pVictim)->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_TOTAL_DAMAGE_RECEIVED, health);

        Kill(pVictim, durabilityLoss);

        /*// find player: owner of controlled `this` or `this` itself maybe
        Player *player = GetCharmerOrOwnerPlayerOrPlayerItself();

        if(pVictim->GetTypeId() == TYPEID_UNIT && ((Creature*)pVictim)->GetLootRecipient())
            player = ((Creature*)pVictim)->GetLootRecipient();
        // Reward player, his pets, and group/raid members
        // call kill spell proc event (before real die and combat stop to triggering auras removed at death/combat stop)
        if(player && player!=pVictim)
        {
            player->RewardPlayerAndGroupAtKill(pVictim);
            player->ProcDamageAndSpell(pVictim, PROC_FLAG_KILL, PROC_FLAG_KILLED, PROC_EX_NONE, 0);
        }

        DEBUG_LOG("DealDamageAttackStop");

        // stop combat
        pVictim->CombatStop();
        pVictim->getHostilRefManager().deleteReferences();

        bool damageFromSpiritOfRedemtionTalent = spellProto && spellProto->Id == 27795;

        // if talent known but not triggered (check priest class for speedup check)
        Aura* spiritOfRedemtionTalentReady = NULL;
        if( !damageFromSpiritOfRedemtionTalent &&           // not called from SPELL_AURA_SPIRIT_OF_REDEMPTION
            pVictim->GetTypeId()==TYPEID_PLAYER && pVictim->getClass()==CLASS_PRIEST )
        {
            AuraList const& vDummyAuras = pVictim->GetAurasByType(SPELL_AURA_DUMMY);
            for(AuraList::const_iterator itr = vDummyAuras.begin(); itr != vDummyAuras.end(); ++itr)
            {
                if((*itr)->GetSpellProto()->SpellIconID==1654)
                {
                    spiritOfRedemtionTalentReady = *itr;
                    break;
                }
            }
        }

        DEBUG_LOG("SET JUST_DIED");
        if(!spiritOfRedemtionTalentReady)
            pVictim->setDeathState(JUST_DIED);

        DEBUG_LOG("DealDamageHealth1");

        if(spiritOfRedemtionTalentReady)
        {
            // save value before aura remove
            uint32 ressSpellId = pVictim->GetUInt32Value(PLAYER_SELF_RES_SPELL);
            if(!ressSpellId)
                ressSpellId = ((Player*)pVictim)->GetResurrectionSpellId();

            //Remove all expected to remove at death auras (most important negative case like DoT or periodic triggers)
            pVictim->RemoveAllAurasOnDeath();

            // restore for use at real death
            pVictim->SetUInt32Value(PLAYER_SELF_RES_SPELL,ressSpellId);

            // FORM_SPIRITOFREDEMPTION and related auras
            pVictim->CastSpell(pVictim,27827,true,NULL,spiritOfRedemtionTalentReady);
        }
        else
            pVictim->SetHealth(0);

        // remember victim PvP death for corpse type and corpse reclaim delay
        // at original death (not at SpiritOfRedemtionTalent timeout)
        if( pVictim->GetTypeId()==TYPEID_PLAYER && !damageFromSpiritOfRedemtionTalent )
            ((Player*)pVictim)->SetPvPDeath(player!=NULL);

        // Call KilledUnit for creatures
        if (GetTypeId() == TYPEID_UNIT && ((Creature*)this)->AI())
            ((Creature*)this)->AI()->KilledUnit(pVictim);

        // achievement stuff
        if (pVictim->GetTypeId() == TYPEID_PLAYER)
        {
            if (GetTypeId() == TYPEID_UNIT)
                ((Player*)pVictim)->GetAchievementMgr().UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_KILLED_BY_CREATURE, GetEntry());
            else if(GetTypeId() == TYPEID_PLAYER && pVictim != this)
                ((Player*)pVictim)->GetAchievementMgr().UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_KILLED_BY_PLAYER, 1, ((Player*)this)->GetTeam());
        }

        // 10% durability loss on death
        // clean InHateListOf
        if (pVictim->GetTypeId() == TYPEID_PLAYER)
        {
            // only if not player and not controlled by player pet. And not at BG
            if (durabilityLoss && !player && !((Player*)pVictim)->InBattleGround())
            {
                DEBUG_LOG("We are dead, loosing 10 percents durability");
                ((Player*)pVictim)->DurabilityLossAll(0.10f,false);
                // durability lost message
                WorldPacket data(SMSG_DURABILITY_DAMAGE_DEATH, 0);
                ((Player*)pVictim)->GetSession()->SendPacket(&data);
            }
        }
        else                                                // creature died
        {
            DEBUG_LOG("DealDamageNotPlayer");
            Creature *cVictim = (Creature*)pVictim;

            if(!cVictim->isPet())
            {
                cVictim->DeleteThreatList();
                cVictim->SetUInt32Value(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_LOOTABLE);
            }
            // Call creature just died function
            if (cVictim->AI())
                cVictim->AI()->JustDied(this);

            // Dungeon specific stuff, only applies to players killing creatures
            if(cVictim->GetInstanceId())
            {
                Map *m = cVictim->GetMap();
                Player *creditedPlayer = GetCharmerOrOwnerPlayerOrPlayerItself();
                // TODO: do instance binding anyway if the charmer/owner is offline

                if(m->IsDungeon() && creditedPlayer)
                {
                    if(m->IsRaid() || m->IsHeroic())
                    {
                        if(cVictim->GetCreatureInfo()->flags_extra & CREATURE_FLAG_EXTRA_INSTANCE_BIND)
                            ((InstanceMap *)m)->PermBindAllPlayers(creditedPlayer);
                    }
                    else
                    {
                        // the reset time is set but not added to the scheduler
                        // until the players leave the instance
                        time_t resettime = cVictim->GetRespawnTimeEx() + 2 * HOUR;
                        if(InstanceSave *save = sInstanceSaveManager.GetInstanceSave(cVictim->GetInstanceId()))
                            if(save->GetResetTime() < resettime) save->SetResetTime(resettime);
                    }
                }
            }
        }

        // last damage from non duel opponent or opponent controlled creature
        if(duel_hasEnded)
        {
            assert(pVictim->GetTypeId()==TYPEID_PLAYER);
            Player *he = (Player*)pVictim;

            assert(he->duel);

            he->duel->opponent->CombatStopWithPets(true);
            he->CombatStopWithPets(true);

            he->DuelComplete(DUEL_INTERUPTED);
        }

        // battleground things (do this at the end, so the death state flag will be properly set to handle in the bg->handlekill)
        if(pVictim->GetTypeId() == TYPEID_PLAYER && ((Player*)pVictim)->InBattleGround())
        {
            Player *killed = ((Player*)pVictim);
            if(BattleGround *bg = killed->GetBattleGround())
                if(player)
                    bg->HandleKillPlayer(killed, player);
                //later we can add support for creature->player kills here i'm
                //not sure, but i guess those kills also get counted in av
                //else if(GetTypeId() == TYPEID_UNIT)
                //    bg->HandleKillPlayer(killed,(Creature*)this);
        }*/
    }
    else                                                    // if (health <= damage)
    {
        DEBUG_LOG("DealDamageAlive");

        if (pVictim->GetTypeId() == TYPEID_PLAYER)
            ((Player*)pVictim)->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_TOTAL_DAMAGE_RECEIVED, damage);

        pVictim->ModifyHealth(- (int32)damage);

        if(damagetype == DIRECT_DAMAGE || damagetype == SPELL_DIRECT_DAMAGE)
        {
            //TODO: This is from procflag, I do not know which spell needs this
            //Maim?
            //if (!spellProto || !(spellProto->AuraInterruptFlags&AURA_INTERRUPT_FLAG_DIRECT_DAMAGE))
                pVictim->RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_DIRECT_DAMAGE, spellProto ? spellProto->Id : 0);
        }
        if (pVictim->GetTypeId() != TYPEID_PLAYER)
        {
            if(spellProto && IsDamageToThreatSpell(spellProto))
                pVictim->AddThreat(this, damage*2, damageSchoolMask, spellProto);
            else
                pVictim->AddThreat(this, damage, damageSchoolMask, spellProto);
        }
        else                                                // victim is a player
        {
            // Rage from damage received
            if(this != pVictim && pVictim->getPowerType() == POWER_RAGE)
            {
                uint32 rage_damage = damage + (cleanDamage ? cleanDamage->damage : 0);
                ((Player*)pVictim)->RewardRage(rage_damage, 0, false);
            }

            // random durability for items (HIT TAKEN)
            if (roll_chance_f(sWorld.getRate(RATE_DURABILITY_LOSS_DAMAGE)))
            {
                EquipmentSlots slot = EquipmentSlots(urand(0,EQUIPMENT_SLOT_END-1));
                ((Player*)pVictim)->DurabilityPointLossForEquipSlot(slot);
            }
        }

        if(GetTypeId()==TYPEID_PLAYER)
        {
            // random durability for items (HIT DONE)
            if (roll_chance_f(sWorld.getRate(RATE_DURABILITY_LOSS_DAMAGE)))
            {
                EquipmentSlots slot = EquipmentSlots(urand(0,EQUIPMENT_SLOT_END-1));
                ((Player*)this)->DurabilityPointLossForEquipSlot(slot);
            }
        }

        if (damagetype != NODAMAGE && damage)// && pVictim->GetTypeId() == TYPEID_PLAYER)
        {
            /*const SpellEntry *se = i->second->GetSpellProto();
            next = i; ++next;
            if (spellProto && spellProto->Id == se->Id) // Not drop auras added by self
                continue;
            if( se->AuraInterruptFlags & AURA_INTERRUPT_FLAG_DAMAGE )
            {
                bool remove = true;
                if (se->procFlags & (1<<3))
                {
                    if (!roll_chance_i(se->procChance))
                        remove = false;
                }
                if (remove)
                {
                    pVictim->RemoveAurasDueToSpell(i->second->GetId());
                    // FIXME: this may cause the auras with proc chance to be rerolled several times
                    next = vAuras.begin();
                }
            }
        }*/

            if(pVictim != this && pVictim->GetTypeId() == TYPEID_PLAYER) // does not support creature push_back
            {
                if(damagetype != DOT)
                {
                    if(Spell* spell = pVictim->m_currentSpells[CURRENT_GENERIC_SPELL])
                    {
                        if(spell->getState() == SPELL_STATE_PREPARING)
                        {
                            uint32 interruptFlags = spell->m_spellInfo->InterruptFlags;
                            if(interruptFlags & SPELL_INTERRUPT_FLAG_ABORT_ON_DMG)
                                pVictim->InterruptNonMeleeSpells(false);
                            else if(interruptFlags & SPELL_INTERRUPT_FLAG_PUSH_BACK)
                                spell->Delayed();
                        }
                    }
                }

                if(Spell* spell = pVictim->m_currentSpells[CURRENT_CHANNELED_SPELL])
                {
                    if(spell->getState() == SPELL_STATE_CASTING)
                    {
                        uint32 channelInterruptFlags = spell->m_spellInfo->ChannelInterruptFlags;
                        if( channelInterruptFlags & CHANNEL_FLAG_DELAY )
                            spell->DelayedChannel();
                    }
                }
            }
        }

        // last damage from duel opponent
        if(duel_hasEnded)
        {
            assert(pVictim->GetTypeId()==TYPEID_PLAYER);
            Player *he = (Player*)pVictim;

            assert(he->duel);

            he->SetHealth(1);

            he->duel->opponent->CombatStopWithPets(true);
            he->CombatStopWithPets(true);

            he->CastSpell(he, 7267, true);                  // beg
            he->DuelComplete(DUEL_WON);
        }
    }

    DEBUG_LOG("DealDamageEnd returned %d damage", damage);

    return damage;
}

void Unit::CastStop(uint32 except_spellid)
{
    for (uint32 i = CURRENT_FIRST_NON_MELEE_SPELL; i < CURRENT_MAX_SPELL; i++)
        if (m_currentSpells[i] && m_currentSpells[i]->m_spellInfo->Id!=except_spellid)
            InterruptSpell(i,false);
}

void Unit::CastSpell(Unit* Victim, uint32 spellId, bool triggered, Item *castItem, AuraEffect* triggeredByAura, uint64 originalCaster)
{
    SpellEntry const *spellInfo = sSpellStore.LookupEntry(spellId );

    if(!spellInfo)
    {
        sLog.outError("CastSpell: unknown spell id %i by caster: %s %u)", spellId,(GetTypeId()==TYPEID_PLAYER ? "player (GUID:" : "creature (Entry:"),(GetTypeId()==TYPEID_PLAYER ? GetGUIDLow() : GetEntry()));
        return;
    }

    CastSpell(Victim,spellInfo,triggered,castItem,triggeredByAura, originalCaster);
}

void Unit::CastSpell(Unit* Victim,SpellEntry const *spellInfo, bool triggered, Item *castItem, AuraEffect* triggeredByAura, uint64 originalCaster)
{
    if(!spellInfo)
    {
        sLog.outError("CastSpell: unknown spell by caster: %s %u)", (GetTypeId()==TYPEID_PLAYER ? "player (GUID:" : "creature (Entry:"),(GetTypeId()==TYPEID_PLAYER ? GetGUIDLow() : GetEntry()));
        return;
    }

    if (!originalCaster && GetTypeId()==TYPEID_UNIT && ((Creature*)this)->isTotem())
        if (Unit * owner = GetOwner())
            originalCaster=owner->GetGUID();

    SpellCastTargets targets;
    uint32 targetMask = spellInfo->Targets;
    //if(targetMask & (TARGET_FLAG_UNIT|TARGET_FLAG_UNK2))
    for(int i = 0; i < 3; ++i)
    {
        if(spellmgr.SpellTargetType[spellInfo->EffectImplicitTargetA[i]] == TARGET_TYPE_UNIT_TARGET)
        {
            /*SpellRangeEntry const* srange = sSpellRangeStore.LookupEntry(spellInfo->rangeIndex);
            if(srange && GetSpellMaxRange(srange) == 0.0f)
            {
                Victim = this;
                break;
            }
            else */if(!Victim)
            {
                sLog.outError("CastSpell: spell id %i by caster: %s %u) does not have unit target", spellInfo->Id,(GetTypeId()==TYPEID_PLAYER ? "player (GUID:" : "creature (Entry:"),(GetTypeId()==TYPEID_PLAYER ? GetGUIDLow() : GetEntry()));
                return;
            }
            else
                break;
        }
    }
    targets.setUnitTarget(Victim);

    if(targetMask & (TARGET_FLAG_SOURCE_LOCATION|TARGET_FLAG_DEST_LOCATION))
    {
        if(!Victim)
        {
            sLog.outError("CastSpell: spell id %i by caster: %s %u) does not have destination", spellInfo->Id,(GetTypeId()==TYPEID_PLAYER ? "player (GUID:" : "creature (Entry:"),(GetTypeId()==TYPEID_PLAYER ? GetGUIDLow() : GetEntry()));
            return;
        }
        targets.setDestination(Victim);
    }

    if (castItem)
        DEBUG_LOG("WORLD: cast Item spellId - %i", spellInfo->Id);

    if(!originalCaster && triggeredByAura)
        originalCaster = triggeredByAura->GetCasterGUID();

    Spell *spell = new Spell(this, spellInfo, triggered, originalCaster );

    spell->m_CastItem = castItem;
    spell->prepare(&targets, triggeredByAura);
}

void Unit::CastCustomSpell(Unit* target, uint32 spellId, int32 const* bp0, int32 const* bp1, int32 const* bp2, bool triggered, Item *castItem, AuraEffect* triggeredByAura, uint64 originalCaster)
{
    CustomSpellValues values;
    if(bp0) values.AddSpellMod(SPELLVALUE_BASE_POINT0, *bp0);
    if(bp1) values.AddSpellMod(SPELLVALUE_BASE_POINT1, *bp1);
    if(bp2) values.AddSpellMod(SPELLVALUE_BASE_POINT2, *bp2);
    CastCustomSpell(spellId, values, target, triggered, castItem, triggeredByAura, originalCaster);
}

void Unit::CastCustomSpell(uint32 spellId, SpellValueMod mod, uint32 value, Unit* target, bool triggered, Item *castItem, AuraEffect* triggeredByAura, uint64 originalCaster)
{
    CustomSpellValues values;
    values.AddSpellMod(mod, value);
    CastCustomSpell(spellId, values, target, triggered, castItem, triggeredByAura, originalCaster);
}

void Unit::CastCustomSpell(uint32 spellId, CustomSpellValues const &value, Unit* Victim, bool triggered, Item *castItem, AuraEffect* triggeredByAura, uint64 originalCaster)
{
    SpellEntry const *spellInfo = sSpellStore.LookupEntry(spellId );
    if(!spellInfo)
    {
        sLog.outError("CastSpell: unknown spell id %i by caster: %s %u)", spellId,(GetTypeId()==TYPEID_PLAYER ? "player (GUID:" : "creature (Entry:"),(GetTypeId()==TYPEID_PLAYER ? GetGUIDLow() : GetEntry()));
        return;
    }

    SpellCastTargets targets;
    uint32 targetMask = spellInfo->Targets;

    //check unit target
    for(int i = 0; i < 3; ++i)
    {
        if(spellmgr.SpellTargetType[spellInfo->EffectImplicitTargetA[i]] == TARGET_TYPE_UNIT_TARGET)
        {
            if(!Victim)
            {
                sLog.outError("CastSpell: spell id %i by caster: %s %u) does not have unit target", spellInfo->Id,(GetTypeId()==TYPEID_PLAYER ? "player (GUID:" : "creature (Entry:"),(GetTypeId()==TYPEID_PLAYER ? GetGUIDLow() : GetEntry()));
                return;
            }
            else
                break;
        }
    }
    targets.setUnitTarget(Victim);

    //check destination
    if(targetMask & (TARGET_FLAG_SOURCE_LOCATION|TARGET_FLAG_DEST_LOCATION))
    {
        if(!Victim)
        {
            sLog.outError("CastSpell: spell id %i by caster: %s %u) does not have destination", spellInfo->Id,(GetTypeId()==TYPEID_PLAYER ? "player (GUID:" : "creature (Entry:"),(GetTypeId()==TYPEID_PLAYER ? GetGUIDLow() : GetEntry()));
            return;
        }
        targets.setDestination(Victim);
    }

    if(!originalCaster && triggeredByAura)
        originalCaster = triggeredByAura->GetCasterGUID();

    Spell *spell = new Spell(this, spellInfo, triggered, originalCaster );

    if(castItem)
    {
        DEBUG_LOG("WORLD: cast Item spellId - %i", spellInfo->Id);
        spell->m_CastItem = castItem;
    }

    for(CustomSpellValues::const_iterator itr = value.begin(); itr != value.end(); ++itr)
        spell->SetSpellValue(itr->first, itr->second);

    spell->prepare(&targets, triggeredByAura);
}

// used for scripting
void Unit::CastSpell(float x, float y, float z, uint32 spellId, bool triggered, Item *castItem, AuraEffect* triggeredByAura, uint64 originalCaster)
{
    SpellEntry const *spellInfo = sSpellStore.LookupEntry(spellId );

    if(!spellInfo)
    {
        sLog.outError("CastSpell(x,y,z): unknown spell id %i by caster: %s %u)", spellId,(GetTypeId()==TYPEID_PLAYER ? "player (GUID:" : "creature (Entry:"),(GetTypeId()==TYPEID_PLAYER ? GetGUIDLow() : GetEntry()));
        return;
    }

    if (castItem)
        DEBUG_LOG("WORLD: cast Item spellId - %i", spellInfo->Id);

    if(!originalCaster && triggeredByAura)
        originalCaster = triggeredByAura->GetCasterGUID();

    Spell *spell = new Spell(this, spellInfo, triggered, originalCaster );

    SpellCastTargets targets;
    targets.setDestination(x, y, z);
    spell->m_CastItem = castItem;
    spell->prepare(&targets, triggeredByAura);
}

// used for scripting
void Unit::CastSpell(GameObject *go, uint32 spellId, bool triggered, Item *castItem, AuraEffect* triggeredByAura, uint64 originalCaster)
{
    if(!go)
        return;

    SpellEntry const *spellInfo = sSpellStore.LookupEntry(spellId );

    if(!spellInfo)
    {
        sLog.outError("CastSpell(x,y,z): unknown spell id %i by caster: %s %u)", spellId,(GetTypeId()==TYPEID_PLAYER ? "player (GUID:" : "creature (Entry:"),(GetTypeId()==TYPEID_PLAYER ? GetGUIDLow() : GetEntry()));
        return;
    }

    if(!(spellInfo->Targets & ( TARGET_FLAG_OBJECT | TARGET_FLAG_OBJECT_UNK)))
    {
        sLog.outError("CastSpell: spell id %i by caster: %s %u) is not gameobject spell", spellId,(GetTypeId()==TYPEID_PLAYER ? "player (GUID:" : "creature (Entry:"),(GetTypeId()==TYPEID_PLAYER ? GetGUIDLow() : GetEntry()));
        return;
    }

    if (castItem)
        DEBUG_LOG("WORLD: cast Item spellId - %i", spellInfo->Id);

    if(!originalCaster && triggeredByAura)
        originalCaster = triggeredByAura->GetCasterGUID();

    Spell *spell = new Spell(this, spellInfo, triggered, originalCaster );

    SpellCastTargets targets;
    targets.setGOTarget(go);
    spell->m_CastItem = castItem;
    spell->prepare(&targets, triggeredByAura);
}

// Obsolete func need remove, here only for comotability vs another patches
uint32 Unit::SpellNonMeleeDamageLog(Unit *pVictim, uint32 spellID, uint32 damage, bool isTriggeredSpell, bool useSpellDamage)
{
    SpellEntry const *spellInfo = sSpellStore.LookupEntry(spellID);
    SpellNonMeleeDamage damageInfo(this, pVictim, spellInfo->Id, spellInfo->SchoolMask);
    damage = SpellDamageBonus(pVictim, spellInfo, damage, SPELL_DIRECT_DAMAGE);
    CalculateSpellDamageTaken(&damageInfo, damage, spellInfo);
    SendSpellNonMeleeDamageLog(&damageInfo);
    DealSpellDamage(&damageInfo, true);
    return damageInfo.damage;
}

void Unit::CalculateSpellDamageTaken(SpellNonMeleeDamage *damageInfo, int32 damage, SpellEntry const *spellInfo, WeaponAttackType attackType)
{
    if (damage < 0)
        return;

    Unit *pVictim = damageInfo->target;
    if(!pVictim || !pVictim->isAlive())
        return;

    SpellSchoolMask damageSchoolMask = SpellSchoolMask(damageInfo->schoolMask);
    uint32 crTypeMask = pVictim->GetCreatureTypeMask();
    // Check spell crit chance
    bool crit = isSpellCrit(pVictim, spellInfo, damageSchoolMask, attackType);
    bool blocked = false;
    // Per-school calc
    switch (spellInfo->DmgClass)
    {
        // Melee and Ranged Spells
        case SPELL_DAMAGE_CLASS_RANGED:
        case SPELL_DAMAGE_CLASS_MELEE:
        {
            // Physical Damage
            if ( damageSchoolMask & SPELL_SCHOOL_MASK_NORMAL )
            {
                // Get blocked status
                blocked = isSpellBlocked(pVictim, spellInfo, attackType);
            }

            if (crit)
            {
                damageInfo->HitInfo|= SPELL_HIT_TYPE_CRIT;

                // Calculate crit bonus
                uint32 crit_bonus = damage;
                // Apply crit_damage bonus for melee spells
                if(Player* modOwner = GetSpellModOwner())
                    modOwner->ApplySpellMod(spellInfo->Id, SPELLMOD_CRIT_DAMAGE_BONUS, crit_bonus);
                damage += crit_bonus;

                // Apply SPELL_AURA_MOD_ATTACKER_RANGED_CRIT_DAMAGE or SPELL_AURA_MOD_ATTACKER_MELEE_CRIT_DAMAGE
                int32 critPctDamageMod=0;
                if(attackType == RANGED_ATTACK)
                    critPctDamageMod += pVictim->GetTotalAuraModifier(SPELL_AURA_MOD_ATTACKER_RANGED_CRIT_DAMAGE);
                else
                {
                    critPctDamageMod += pVictim->GetTotalAuraModifier(SPELL_AURA_MOD_ATTACKER_MELEE_CRIT_DAMAGE);
                    critPctDamageMod += GetTotalAuraModifier(SPELL_AURA_MOD_CRIT_DAMAGE_BONUS_MELEE);
                }
                // Increase crit damage from SPELL_AURA_MOD_CRIT_PERCENT_VERSUS
                critPctDamageMod += GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_CRIT_PERCENT_VERSUS, crTypeMask);

                if (critPctDamageMod!=0)
                    damage = int32((damage) * float((100.0f + critPctDamageMod)/100.0f));

                // Resilience - reduce crit damage
                if (pVictim->GetTypeId()==TYPEID_PLAYER)
                    damage -= ((Player*)pVictim)->GetMeleeCritDamageReduction(damage);
            }
            // Spell weapon based damage CAN BE crit & blocked at same time
            if (blocked)
            {
                damageInfo->blocked = uint32(pVictim->GetShieldBlockValue());
                //double blocked amount if block is critical
                if (isBlockCritical())
                    damageInfo->blocked+=damageInfo->blocked;
                if (damage < damageInfo->blocked)
                    damageInfo->blocked = damage;
                damage-=damageInfo->blocked;
            }
        }
        break;
        // Magical Attacks
        case SPELL_DAMAGE_CLASS_NONE:
        case SPELL_DAMAGE_CLASS_MAGIC:
        {
            // If crit add critical bonus
            if (crit)
            {
                damageInfo->HitInfo|= SPELL_HIT_TYPE_CRIT;
                damage = SpellCriticalDamageBonus(spellInfo, damage, pVictim);
                // Resilience - reduce crit damage
                if (pVictim->GetTypeId()==TYPEID_PLAYER)
                    damage -= ((Player*)pVictim)->GetSpellCritDamageReduction(damage);
            }
        }
        break;
    }

    if( damageSchoolMask & SPELL_SCHOOL_MASK_NORMAL )
        damage = CalcArmorReducedDamage(pVictim, damage, spellInfo, attackType);

    // Calculate absorb resist
    if(damage > 0)
    {
        CalcAbsorbResist(pVictim, damageSchoolMask, SPELL_DIRECT_DAMAGE, damage, &damageInfo->absorb, &damageInfo->resist, spellInfo);
        damage-= damageInfo->absorb + damageInfo->resist;
    }
    else
        damage = 0;
    damageInfo->damage = damage;
}

int32 Unit::GetIgnoredArmorMultiplier(SpellEntry const *spellInfo, WeaponAttackType attackType)
{
    if (GetTypeId() != TYPEID_PLAYER)
        return 0;
    //check if spell uses weapon
    if (!spellInfo || spellInfo->EquippedItemClass!=ITEM_CLASS_WEAPON)
        return 0;
    Item *item = NULL;
    if(attackType == BASE_ATTACK)
        item = ((Player*)this)->GetUseableItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);
    else if (attackType == OFF_ATTACK)
        item = ((Player*)this)->GetUseableItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND);
    else if (attackType == RANGED_ATTACK)
        item = ((Player*)this)->GetUseableItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_RANGED);
    if (!item)
        return 0;

    AuraEffectList const& armAuras = GetAurasByType(SPELL_AURA_MOD_WEAPONTYPE_IGNORE_TARGET_RESISTANCE);
    int32 armorIgnored = 0;
    for(AuraEffectList::const_iterator i = armAuras.begin();i != armAuras.end(); ++i)
    {
        if (!((*i)->GetSpellProto()->EquippedItemClass==item->GetProto()->Class
            && (*i)->GetSpellProto()->EquippedItemSubClassMask & (1<<item->GetProto()->SubClass)))
            continue;

        if((*i)->GetAmount())
            armorIgnored += (*i)->GetAmount();
    }
    return (-armorIgnored);
}

void Unit::DealSpellDamage(SpellNonMeleeDamage *damageInfo, bool durabilityLoss)
{
    if (damageInfo==0)
        return;

    Unit *pVictim = damageInfo->target;

    if(!this || !pVictim)
        return;

    if (!pVictim->isAlive() || pVictim->hasUnitState(UNIT_STAT_UNATTACKABLE) || pVictim->GetTypeId() == TYPEID_UNIT && ((Creature*)pVictim)->IsInEvadeMode())
        return;

    SpellEntry const *spellProto = sSpellStore.LookupEntry(damageInfo->SpellID);
    if (spellProto == NULL)
    {
        sLog.outDebug("Unit::DealSpellDamage have wrong damageInfo->SpellID: %u", damageInfo->SpellID);
        return;
    }

    //You don't lose health from damage taken from another player while in a sanctuary
    //You still see it in the combat log though
    if(pVictim != this && GetTypeId() == TYPEID_PLAYER && pVictim->GetTypeId() == TYPEID_PLAYER)
    {
        const AreaTableEntry *area = GetAreaEntryByAreaID(pVictim->GetAreaId());
        if(area && area->flags & 0x800)                     //sanctuary
            return;
    }

    // Call default DealDamage
    CleanDamage cleanDamage(damageInfo->cleanDamage, BASE_ATTACK, MELEE_HIT_NORMAL);
    DealDamage(pVictim, damageInfo->damage, &cleanDamage, SPELL_DIRECT_DAMAGE, SpellSchoolMask(damageInfo->schoolMask), spellProto, durabilityLoss);
}

//TODO for melee need create structure as in
void Unit::CalculateMeleeDamage(Unit *pVictim, uint32 damage, CalcDamageInfo *damageInfo, WeaponAttackType attackType)
{
    damageInfo->attacker         = this;
    damageInfo->target           = pVictim;
    damageInfo->damageSchoolMask = GetMeleeDamageSchoolMask();
    damageInfo->attackType       = attackType;
    damageInfo->damage           = 0;
    damageInfo->cleanDamage      = 0;
    damageInfo->absorb           = 0;
    damageInfo->resist           = 0;
    damageInfo->blocked_amount   = 0;

    damageInfo->TargetState      = 0;
    damageInfo->HitInfo          = 0;
    damageInfo->procAttacker     = PROC_FLAG_NONE;
    damageInfo->procVictim       = PROC_FLAG_NONE;
    damageInfo->procEx           = PROC_EX_NONE;
    damageInfo->hitOutCome       = MELEE_HIT_EVADE;

    if(!this || !pVictim)
        return;
    if(!this->isAlive() || !pVictim->isAlive())
        return;

    // Select HitInfo/procAttacker/procVictim flag based on attack type
    switch (attackType)
    {
        case BASE_ATTACK:
            damageInfo->procAttacker = PROC_FLAG_SUCCESSFUL_MILEE_HIT;
            damageInfo->procVictim   = PROC_FLAG_TAKEN_MELEE_HIT;
            damageInfo->HitInfo      = HITINFO_NORMALSWING2;
            break;
        case OFF_ATTACK:
            damageInfo->procAttacker = PROC_FLAG_SUCCESSFUL_MILEE_HIT | PROC_FLAG_SUCCESSFUL_OFFHAND_HIT;
            damageInfo->procVictim   = PROC_FLAG_TAKEN_MELEE_HIT;//|PROC_FLAG_TAKEN_OFFHAND_HIT // not used
            damageInfo->HitInfo = HITINFO_LEFTSWING;
            break;
        case RANGED_ATTACK:
            damageInfo->procAttacker = PROC_FLAG_SUCCESSFUL_RANGED_HIT;
            damageInfo->procVictim   = PROC_FLAG_TAKEN_RANGED_HIT;
            damageInfo->HitInfo = 0x08;// test
            break;
        default:
            break;
    }

    // Physical Immune check
    if(damageInfo->target->IsImmunedToDamage(SpellSchoolMask(damageInfo->damageSchoolMask)))
    {
       damageInfo->HitInfo       |= HITINFO_NORMALSWING;
       damageInfo->TargetState    = VICTIMSTATE_IS_IMMUNE;

       damageInfo->procEx |=PROC_EX_IMMUNE;
       damageInfo->damage         = 0;
       damageInfo->cleanDamage    = 0;
       return;
    }
    damage += CalculateDamage (damageInfo->attackType, false);
    // Add melee damage bonus
    MeleeDamageBonus(damageInfo->target, &damage, damageInfo->attackType);
    // Calculate armor reduction
    damageInfo->damage = CalcArmorReducedDamage(damageInfo->target, damage, NULL , damageInfo->attackType);
    damageInfo->cleanDamage += damage - damageInfo->damage;

    damageInfo->hitOutCome = RollMeleeOutcomeAgainst(damageInfo->target, damageInfo->attackType);

    // Disable parry or dodge for ranged attack
    if(damageInfo->attackType == RANGED_ATTACK)
    {
        if (damageInfo->hitOutCome == MELEE_HIT_PARRY) damageInfo->hitOutCome = MELEE_HIT_NORMAL;
        if (damageInfo->hitOutCome == MELEE_HIT_DODGE) damageInfo->hitOutCome = MELEE_HIT_MISS;
    }

    switch(damageInfo->hitOutCome)
    {
        case MELEE_HIT_EVADE:
        {
            damageInfo->HitInfo    |= HITINFO_MISS|HITINFO_SWINGNOHITSOUND;
            damageInfo->TargetState = VICTIMSTATE_EVADES;

            damageInfo->procEx|=PROC_EX_EVADE;
            damageInfo->damage = 0;
            damageInfo->cleanDamage = 0;
            return;
        }
        case MELEE_HIT_MISS:
        {
            damageInfo->HitInfo    |= HITINFO_MISS;
            damageInfo->TargetState = VICTIMSTATE_NORMAL;

            damageInfo->procEx|=PROC_EX_MISS;
            damageInfo->damage = 0;
            damageInfo->cleanDamage = 0;
            break;
        }
        case MELEE_HIT_NORMAL:
            damageInfo->TargetState = VICTIMSTATE_NORMAL;
            damageInfo->procEx|=PROC_EX_NORMAL_HIT;
            break;
        case MELEE_HIT_CRIT:
        {
            damageInfo->HitInfo     |= HITINFO_CRITICALHIT;
            damageInfo->TargetState  = VICTIMSTATE_NORMAL;

            damageInfo->procEx|=PROC_EX_CRITICAL_HIT;
            // Crit bonus calc
            damageInfo->damage += damageInfo->damage;
            int32 mod=0;
            // Apply SPELL_AURA_MOD_ATTACKER_RANGED_CRIT_DAMAGE or SPELL_AURA_MOD_ATTACKER_MELEE_CRIT_DAMAGE
            if(damageInfo->attackType == RANGED_ATTACK)
                mod += damageInfo->target->GetTotalAuraModifier(SPELL_AURA_MOD_ATTACKER_RANGED_CRIT_DAMAGE);
            else
            {
                mod += damageInfo->target->GetTotalAuraModifier(SPELL_AURA_MOD_ATTACKER_MELEE_CRIT_DAMAGE);
                mod += GetTotalAuraModifier(SPELL_AURA_MOD_CRIT_DAMAGE_BONUS_MELEE);
            }

            uint32 crTypeMask = damageInfo->target->GetCreatureTypeMask();

            // Increase crit damage from SPELL_AURA_MOD_CRIT_PERCENT_VERSUS
            mod += GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_CRIT_PERCENT_VERSUS, crTypeMask);
            if (mod!=0)
                damageInfo->damage = int32((damageInfo->damage) * float((100.0f + mod)/100.0f));

            // Resilience - reduce crit damage
            if (pVictim->GetTypeId()==TYPEID_PLAYER)
            {
                uint32 resilienceReduction = ((Player*)pVictim)->GetMeleeCritDamageReduction(damageInfo->damage);
                damageInfo->damage      -= resilienceReduction;
                damageInfo->cleanDamage += resilienceReduction;
            }
            break;
        }
        case MELEE_HIT_PARRY:
            damageInfo->TargetState  = VICTIMSTATE_PARRY;
            damageInfo->procEx|=PROC_EX_PARRY;
            damageInfo->cleanDamage += damageInfo->damage;
            damageInfo->damage = 0;
            break;

        case MELEE_HIT_DODGE:
            damageInfo->TargetState  = VICTIMSTATE_DODGE;
            damageInfo->procEx|=PROC_EX_DODGE;
            damageInfo->cleanDamage += damageInfo->damage;
            damageInfo->damage = 0;
            break;
        case MELEE_HIT_BLOCK:
        {
            damageInfo->TargetState = VICTIMSTATE_NORMAL;
            damageInfo->HitInfo |= HITINFO_BLOCK;
            damageInfo->procEx|=PROC_EX_BLOCK;
            damageInfo->blocked_amount = damageInfo->target->GetShieldBlockValue();
            //double blocked amount if block is critical
            if (isBlockCritical())
                damageInfo->blocked_amount+=damageInfo->blocked_amount;
            if (damageInfo->blocked_amount >= damageInfo->damage)
            {
                damageInfo->TargetState = VICTIMSTATE_BLOCKS;
                damageInfo->blocked_amount = damageInfo->damage;
            }
            damageInfo->damage      -= damageInfo->blocked_amount;
            damageInfo->cleanDamage += damageInfo->blocked_amount;
            break;
        }
        case MELEE_HIT_GLANCING:
        {
            damageInfo->HitInfo     |= HITINFO_GLANCING;
            damageInfo->TargetState  = VICTIMSTATE_NORMAL;
            damageInfo->procEx|=PROC_EX_NORMAL_HIT;
            int32 leveldif = int32(pVictim->getLevel()) - int32(getLevel());
            if (leveldif > 3) leveldif = 3;
            float reducePercent = 1 - leveldif * 0.1f;
            damageInfo->cleanDamage += damageInfo->damage-uint32(reducePercent *  damageInfo->damage);
            damageInfo->damage   = uint32(reducePercent *  damageInfo->damage);
            break;
        }
        case MELEE_HIT_CRUSHING:
        {
            damageInfo->HitInfo     |= HITINFO_CRUSHING;
            damageInfo->TargetState  = VICTIMSTATE_NORMAL;
            damageInfo->procEx|=PROC_EX_NORMAL_HIT;
            // 150% normal damage
            damageInfo->damage += (damageInfo->damage / 2);
            break;
        }
        default:

            break;
    }

    // Calculate absorb resist
    if(int32(damageInfo->damage) > 0)
    {
        damageInfo->procVictim |= PROC_FLAG_TAKEN_ANY_DAMAGE;
        // Calculate absorb & resists
        CalcAbsorbResist(damageInfo->target, SpellSchoolMask(damageInfo->damageSchoolMask), DIRECT_DAMAGE, damageInfo->damage, &damageInfo->absorb, &damageInfo->resist);
        damageInfo->damage-=damageInfo->absorb + damageInfo->resist;
        if (damageInfo->absorb)
        {
            damageInfo->HitInfo|=HITINFO_ABSORB;
            damageInfo->procEx|=PROC_EX_ABSORB;
        }
        if (damageInfo->resist)
            damageInfo->HitInfo|=HITINFO_RESIST;

    }
    else // Umpossible get negative result but....
        damageInfo->damage = 0;
}

void Unit::DealMeleeDamage(CalcDamageInfo *damageInfo, bool durabilityLoss)
{
    if (damageInfo==0) return;
    Unit *pVictim = damageInfo->target;

    if(!this || !pVictim)
        return;

    if (!pVictim->isAlive() || pVictim->hasUnitState(UNIT_STAT_UNATTACKABLE) || pVictim->GetTypeId() == TYPEID_UNIT && ((Creature*)pVictim)->IsInEvadeMode())
        return;

    //You don't lose health from damage taken from another player while in a sanctuary
    //You still see it in the combat log though
    if(pVictim != this && GetTypeId() == TYPEID_PLAYER && pVictim->GetTypeId() == TYPEID_PLAYER)
    {
        const AreaTableEntry *area = GetAreaEntryByAreaID(pVictim->GetAreaId());
        if(area && area->flags & 0x800)                     //sanctuary
            return;
    }

    // Hmmmm dont like this emotes cloent must by self do all animations
    if (damageInfo->HitInfo&HITINFO_CRITICALHIT)
        pVictim->HandleEmoteCommand(EMOTE_ONESHOT_WOUNDCRITICAL);
    if(damageInfo->blocked_amount && damageInfo->TargetState!=VICTIMSTATE_BLOCKS)
        pVictim->HandleEmoteCommand(EMOTE_ONESHOT_PARRYSHIELD);

    if(damageInfo->TargetState == VICTIMSTATE_PARRY)
    {
        // Get attack timers
        float offtime  = float(pVictim->getAttackTimer(OFF_ATTACK));
        float basetime = float(pVictim->getAttackTimer(BASE_ATTACK));
        // Reduce attack time
        if (pVictim->haveOffhandWeapon() && offtime < basetime)
        {
            float percent20 = pVictim->GetAttackTime(OFF_ATTACK) * 0.20f;
            float percent60 = 3.0f * percent20;
            if(offtime > percent20 && offtime <= percent60)
            {
                pVictim->setAttackTimer(OFF_ATTACK, uint32(percent20));
            }
            else if(offtime > percent60)
            {
                offtime -= 2.0f * percent20;
                pVictim->setAttackTimer(OFF_ATTACK, uint32(offtime));
            }
        }
        else
        {
            float percent20 = pVictim->GetAttackTime(BASE_ATTACK) * 0.20;
            float percent60 = 3.0f * percent20;
            if(basetime > percent20 && basetime <= percent60)
            {
                pVictim->setAttackTimer(BASE_ATTACK, uint32(percent20));
            }
            else if(basetime > percent60)
            {
                basetime -= 2.0f * percent20;
                pVictim->setAttackTimer(BASE_ATTACK, uint32(basetime));
            }
        }
    }

    // Call default DealDamage
    CleanDamage cleanDamage(damageInfo->cleanDamage,damageInfo->attackType,damageInfo->hitOutCome);
    DealDamage(pVictim, damageInfo->damage, &cleanDamage, DIRECT_DAMAGE, SpellSchoolMask(damageInfo->damageSchoolMask), NULL, durabilityLoss);

    // If this is a creature and it attacks from behind it has a probability to daze it's victim
    if( (damageInfo->hitOutCome==MELEE_HIT_CRIT || damageInfo->hitOutCome==MELEE_HIT_CRUSHING || damageInfo->hitOutCome==MELEE_HIT_NORMAL || damageInfo->hitOutCome==MELEE_HIT_GLANCING) &&
        GetTypeId() != TYPEID_PLAYER && !((Creature*)this)->IsControlledByPlayer() && !pVictim->HasInArc(M_PI, this)
        && (pVictim->GetTypeId() == TYPEID_PLAYER || !((Creature*)pVictim)->isWorldBoss()))
    {
        // -probability is between 0% and 40%
        // 20% base chance
        float Probability = 20.0f;

        //there is a newbie protection, at level 10 just 7% base chance; assuming linear function
        if( pVictim->getLevel() < 30 )
            Probability = 0.65f*pVictim->getLevel()+0.5f;

        uint32 VictimDefense=pVictim->GetDefenseSkillValue();
        uint32 AttackerMeleeSkill=GetUnitMeleeSkill();

        Probability *= AttackerMeleeSkill/(float)VictimDefense;

        if(Probability > 40.0f)
            Probability = 40.0f;

        if(roll_chance_f(Probability))
            CastSpell(pVictim, 1604, true);
    }

    // If not miss
    if (!(damageInfo->HitInfo & HITINFO_MISS))
    {
        if(GetTypeId() == TYPEID_PLAYER && pVictim->isAlive())
        {
            for(int i = EQUIPMENT_SLOT_START; i < EQUIPMENT_SLOT_END; i++)
                ((Player*)this)->CastItemCombatSpell(((Player*)this)->GetUseableItemByPos(INVENTORY_SLOT_BAG_0,i), pVictim, damageInfo->attackType);
        }

        // victim's damage shield
        std::set<AuraEffect*> alreadyDone;
        uint32 removedAuras = pVictim->m_removedAurasCount;
        AuraEffectList const& vDamageShields = pVictim->GetAurasByType(SPELL_AURA_DAMAGE_SHIELD);
        for(AuraEffectList::const_iterator i = vDamageShields.begin(), next = vDamageShields.begin(); i != vDamageShields.end(); i = next)
        {
           next++;
           if (alreadyDone.find(*i) == alreadyDone.end())
           {
               alreadyDone.insert(*i);
               uint32 damage=(*i)->GetAmount();
               SpellEntry const *spellProto = sSpellStore.LookupEntry((*i)->GetId());
               if(!spellProto)
                   continue;
               //Calculate absorb resist ??? no data in opcode for this possibly unable to absorb or resist?
               //uint32 absorb;
               //uint32 resist;
               //CalcAbsorbResist(pVictim, SpellSchools(spellProto->School), SPELL_DIRECT_DAMAGE, damage, &absorb, &resist);
               //damage-=absorb + resist;

               WorldPacket data(SMSG_SPELLDAMAGESHIELD,(8+8+4+4+4+4));
               data << uint64(pVictim->GetGUID());
               data << uint64(GetGUID());
               data << uint32(spellProto->Id);
               data << uint32(damage);                  // Damage
               data << uint32(0);                       // Overkill
               data << uint32(spellProto->SchoolMask);
               pVictim->SendMessageToSet(&data, true );

               pVictim->DealDamage(this, damage, 0, SPELL_DIRECT_DAMAGE, GetSpellSchoolMask(spellProto), spellProto, true);

               if (pVictim->m_removedAurasCount > removedAuras)
               {
                   removedAuras = pVictim->m_removedAurasCount;
                   next = vDamageShields.begin();
               }
           }
        }
    }
}


void Unit::HandleEmoteCommand(uint32 anim_id)
{
    WorldPacket data( SMSG_EMOTE, 12 );
    data << uint32(anim_id);
    data << uint64(GetGUID());
    SendMessageToSet(&data, true);
}

uint32 Unit::CalcArmorReducedDamage(Unit* pVictim, const uint32 damage, SpellEntry const *spellInfo, WeaponAttackType attackType)
{
    uint32 newdamage = 0;
    float armor = pVictim->GetArmor();
    // Ignore enemy armor by SPELL_AURA_MOD_TARGET_RESISTANCE aura
    armor += GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_TARGET_RESISTANCE, SPELL_SCHOOL_MASK_NORMAL);

    armor *= float((GetIgnoredArmorMultiplier(spellInfo, attackType)+100.0f)/100.0f);
    if(spellInfo)
        if(Player *modOwner = GetSpellModOwner())
            modOwner->ApplySpellMod(spellInfo->Id, SPELLMOD_IGNORE_ARMOR, armor);

    AuraEffectList const& ResIgnoreAurasAb = GetAurasByType(SPELL_AURA_MOD_ABILITY_IGNORE_TARGET_RESIST);
    for(AuraEffectList::const_iterator j = ResIgnoreAurasAb.begin();j != ResIgnoreAurasAb.end(); ++j)
    {
        if( (*j)->GetMiscValue() & SPELL_SCHOOL_MASK_NORMAL
            && (*j)->isAffectedOnSpell(spellInfo))
            armor= int32(float(armor) * (float(100-(*j)->GetAmount())/100.0f));
    }

    AuraEffectList const& ResIgnoreAuras = GetAurasByType(SPELL_AURA_MOD_IGNORE_TARGET_RESIST);
    for(AuraEffectList::const_iterator j = ResIgnoreAuras.begin();j != ResIgnoreAuras.end(); ++j)
    {
        if( (*j)->GetMiscValue() & SPELL_SCHOOL_MASK_NORMAL)
            armor= int32(float(armor) * (float(100-(*j)->GetAmount())/100.0f));
    }

    // Apply Player CR_ARMOR_PENETRATION rating
    if (GetTypeId()==TYPEID_PLAYER)
        armor *= 1.0f - ((Player*)this)->GetRatingBonusValue(CR_ARMOR_PENETRATION) / 100.0f;

    if (armor < 0.0f) armor=0.0f;

    float levelModifier = getLevel();
    if ( levelModifier > 59 )
        levelModifier = levelModifier + (4.5f * (levelModifier-59));

    float tmpvalue = 0.1f * armor / (8.5f * levelModifier + 40);
    tmpvalue = tmpvalue/(1.0f + tmpvalue);

    if(tmpvalue < 0.0f)
        tmpvalue = 0.0f;
    if(tmpvalue > 0.75f)
        tmpvalue = 0.75f;
    newdamage = uint32(damage - (damage * tmpvalue));

    return (newdamage > 1) ? newdamage : 1;
}

void Unit::CalcAbsorbResist(Unit *pVictim,SpellSchoolMask schoolMask, DamageEffectType damagetype, const uint32 damage, uint32 *absorb, uint32 *resist, SpellEntry const *spellInfo)
{
    if(!pVictim || !pVictim->isAlive() || !damage)
        return;

    // Magic damage, check for resists
    if ((schoolMask & SPELL_SCHOOL_MASK_NORMAL)==0)
    {
        // Get base victim resistance for school
        float tmpvalue2 = (float)pVictim->GetResistance(GetFirstSchoolInMask(schoolMask));
        // Ignore resistance by self SPELL_AURA_MOD_TARGET_RESISTANCE aura
        tmpvalue2 += (float)GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_TARGET_RESISTANCE, schoolMask);

        tmpvalue2 *= (float)(0.15f / getLevel());
        if (tmpvalue2 < 0.0f)
            tmpvalue2 = 0.0f;
        if (tmpvalue2 > 0.75f)
            tmpvalue2 = 0.75f;
        uint32 ran = urand(0, 100);
        uint32 faq[4] = {24,6,4,6};
        uint8 m = 0;
        float Binom = 0.0f;
        for (uint8 i = 0; i < 4; i++)
        {
            Binom += 2400 *( powf(tmpvalue2, i) * powf( (1-tmpvalue2), (4-i)))/faq[i];
            if (ran > Binom )
                ++m;
            else
                break;
        }
        if (damagetype == DOT && m == 4)
            *resist += uint32(damage - 1);
        else
            *resist += uint32(damage * m / 4);
        if(*resist > damage)
            *resist = damage;

        AuraEffectList const& ResIgnoreAurasAb = GetAurasByType(SPELL_AURA_MOD_ABILITY_IGNORE_TARGET_RESIST);
        for(AuraEffectList::const_iterator j = ResIgnoreAurasAb.begin();j != ResIgnoreAurasAb.end(); ++j)
        {
            if( (*j)->GetMiscValue() & schoolMask
                && (*j)->isAffectedOnSpell(spellInfo))
                *resist= int32(float(*resist) * (float(100-(*j)->GetAmount())/100.0f));
        }

        AuraEffectList const& ResIgnoreAuras = GetAurasByType(SPELL_AURA_MOD_IGNORE_TARGET_RESIST);
        for(AuraEffectList::const_iterator j = ResIgnoreAuras.begin();j != ResIgnoreAuras.end(); ++j)
        {
            if( (*j)->GetMiscValue() & schoolMask)
                *resist= int32(float(*resist) * (float(100-(*j)->GetAmount())/100.0f));
        }
    }
    else
        *resist = 0;

    int32 RemainingDamage = damage - *resist;
    int32 TotalAbsorb = RemainingDamage;
    // Get unit state (need for some absorb check)
    uint32 unitflag = pVictim->GetUInt32Value(UNIT_FIELD_FLAGS);
    // Reflect damage spells (not cast any damage spell in aura lookup)
    uint32 reflectSpell = 0;
    int32  reflectDamage = 0;
    uint32 healSpell = 0;
    int32  healAmount = 0;
    Unit * healCaster = NULL;
    // Need remove expired auras after
    bool existExpired = false;
    // absorb without mana cost
    AuraEffectList const& vSchoolAbsorb = pVictim->GetAurasByType(SPELL_AURA_SCHOOL_ABSORB);
    for(AuraEffectList::const_iterator i = vSchoolAbsorb.begin(); i != vSchoolAbsorb.end() && RemainingDamage > 0; ++i)
    {
        if (!((*i)->GetMiscValue() & schoolMask))
            continue;

        SpellEntry const* spellProto = (*i)->GetSpellProto();

        // Max Amount can be absorbed by this aura
        int32  currentAbsorb = (*i)->GetAmount();

        // Found empty aura (impossible but..)
        if (currentAbsorb <=0)
        {
            existExpired = true;
            continue;
        }
        // Handle custom absorb auras
        // TODO: try find better way
        switch(spellProto->SpellFamilyName)
        {
            case SPELLFAMILY_GENERIC:
            {
                // Astral Shift
                if (spellProto->SpellIconID == 3066)
                {
                    //reduces all damage taken while stun, fear or silence
                    if (unitflag & (UNIT_FLAG_STUNNED|UNIT_FLAG_FLEEING|UNIT_FLAG_SILENCED))
                        RemainingDamage -= RemainingDamage * currentAbsorb / 100;
                    continue;
                }
                // Nerves of Steel
                if (spellProto->SpellIconID == 2115)
                {
                    // while affected by Stun and Fear
                    if (unitflag&(UNIT_FLAG_STUNNED|UNIT_FLAG_FLEEING))
                        RemainingDamage -= RemainingDamage * currentAbsorb / 100;
                    continue;
                }
                // Spell Deflection
                if (spellProto->SpellIconID == 3006)
                {
                    // You have a chance equal to your Parry chance
                    if (damagetype == DIRECT_DAMAGE &&                   // Only for direct damage
                        roll_chance_f(pVictim->GetUnitParryChance()))    // Roll chance
                        RemainingDamage -= RemainingDamage * currentAbsorb / 100;
                    continue;
                }
                // Reflective Shield (Lady Malande boss)
                if (spellProto->Id == 41475)
                {
                    if(RemainingDamage < currentAbsorb)
                        reflectDamage = RemainingDamage / 2;
                    else
                        reflectDamage = currentAbsorb / 2;
                    reflectSpell = 33619;
                    break;
                }
                if (spellProto->Id == 39228 || // Argussian Compass
                    spellProto->Id == 60218)   // Essence of Gossamer
                {
                    // Max absorb stored in 1 dummy effect
                    if (spellProto->EffectBasePoints[1] < currentAbsorb)
                        currentAbsorb = spellProto->EffectBasePoints[1];
                    break;
                }
                break;
            }
            case SPELLFAMILY_DRUID:
            {
                // Primal Tenacity
                if (spellProto->SpellIconID == 2253)
                {
                    //reduces all damage taken while Stunned
                    if (unitflag & UNIT_FLAG_STUNNED)
                        RemainingDamage -= RemainingDamage * currentAbsorb / 100;
                    continue;
                }
                break;
            }
            case SPELLFAMILY_ROGUE:
            {
                // Cheat Death
                if(spellProto->SpellIconID == 2109)
                {
                    if (pVictim->GetTypeId()==TYPEID_PLAYER &&            // Only players
                        pVictim->GetHealth() <= RemainingDamage &&        // Only if damage kill
                        !((Player*)pVictim)->HasSpellCooldown(31231) &&   // Only if no cooldown
                        roll_chance_i(currentAbsorb))                     // Only if roll
                    {
                        pVictim->CastSpell(pVictim,31231,true);
                        ((Player*)pVictim)->AddSpellCooldown(31231,0,time(NULL)+60);
                        // with health > 10% lost health until health==10%, in other case no losses
                        uint32 health10 = pVictim->GetMaxHealth()/10;
                        RemainingDamage = pVictim->GetHealth() > health10 ? pVictim->GetHealth() - health10 : 0;
                    }
                    continue;
                }
                break;
            }
            case SPELLFAMILY_PRIEST:
            {
                // Guardian Spirit
                if (spellProto->Id==47788)
                {
                    if (pVictim->GetHealth() <= RemainingDamage)        // Killing Blow
                    {
                        healAmount = pVictim->GetMaxHealth()/2;
                        healCaster = pVictim;
                        healSpell = 48153;
                        (*i)->SetAmount(0);
                        RemainingDamage=0;
                    }
                        continue;
                }

                // Reflective Shield
                if (spellProto->SpellFamilyFlags.IsEqual(0x1, 0, 0x400))
                {
                    if (pVictim == this)
                        break;
                    Unit* caster = (*i)->GetCaster();
                    if (!caster)
                        break;
                    AuraEffectList const& vOverRideCS = caster->GetAurasByType(SPELL_AURA_DUMMY);
                    for(AuraEffectList::const_iterator k = vOverRideCS.begin(); k != vOverRideCS.end(); ++k)
                    {
                        if((*k)->GetSpellProto()->SpellFamilyName != SPELLFAMILY_PRIEST)
                            continue;
                        switch((*k)->GetMiscValue())
                        {
                            case 5065:                          // Rank 1
                            case 5064:                          // Rank 2
                            case 5063:                          // Rank 3
                            {
                                if(RemainingDamage >= currentAbsorb)
                                    reflectDamage = (*k)->GetAmount() * currentAbsorb/100;
                                else
                                    reflectDamage = (*k)->GetAmount() * RemainingDamage/100;
                                reflectSpell = 33619;
                            } break;
                        }
                    }
                }
                // no break here, rapture can proc with reflective shield
                // Rapture
                if (spellProto->SpellFamilyFlags.HasFlag(0x1, 0x1000000))
                {
                    if (pVictim == this)
                        break;
                    healCaster = (*i)->GetCaster();
                    if (!healCaster)
                        break;

                    AuraEffectList const& lOverRideCS = pVictim->GetAurasByType(SPELL_AURA_OVERRIDE_CLASS_SCRIPTS);
                    for(AuraEffectList::const_iterator k = lOverRideCS.begin(); k != lOverRideCS.end(); ++k)
                    {
                        switch((*k)->GetMiscValue())
                        {
                                case 7556:                          // Rank 1
                                case 7555:                          // Rank 2
                                case 7554:                          // Rank 3
                                case 7553:                          // Rank 4
                                case 7552:                          // Rank 5
                                {
                                     healSpell = 47755;
                                     healAmount += ((pVictim->getLevel() * (-0.2) + 18) / 1000000) * currentAbsorb * pVictim->GetMaxPower(POWER_MANA);
                                     // limitation based on aura amount
                                     if(healAmount > pVictim->GetMaxPower(POWER_MANA) * (*k)->GetAmount() / 1000)
                                        healAmount = pVictim->GetMaxPower(POWER_MANA) * (*k)->GetAmount() / 1000;
                                } break;
                        }
                    }
                }
                break;
            }
            case SPELLFAMILY_SHAMAN:
            {
                // Astral Shift
                if (spellProto->SpellIconID == 3066)
                {
                    //reduces all damage taken while stun, fear or silence
                    if (unitflag & (UNIT_FLAG_STUNNED|UNIT_FLAG_FLEEING|UNIT_FLAG_SILENCED))
                        RemainingDamage -= RemainingDamage * currentAbsorb / 100;
                    continue;
                }
                break;
            }
            case SPELLFAMILY_DEATHKNIGHT:
            {
                // Shadow of Death
                if (spellProto->SpellIconID == 1958)
                {
                    // TODO: absorb only while transform
                    continue;
                }
                // Anti-Magic Shell (on self)
                if (spellProto->Id == 48707)
                {
                    // damage absorbed by Anti-Magic Shell energizes the DK with additional runic power.
                    // This, if I'm not mistaken, shows that we get back ~2% of the absorbed damage as runic power.
                    int32 absorbed = RemainingDamage * currentAbsorb / 100;
                    int32 regen = absorbed * 2 / 10;
                    pVictim->CastCustomSpell(pVictim, 49088, &regen, 0, 0, true, 0, (*i));
                    RemainingDamage -= absorbed;
                    continue;
                }
                // Anti-Magic Shell (on single party/raid member)
                if (spellProto->Id == 50462)
                {
                    RemainingDamage -= RemainingDamage * currentAbsorb / 100;
                    continue;
                }
                // Anti-Magic Zone
                if (spellProto->Id == 50461)
                {
                    Unit* caster = (*i)->GetCaster();
                    if (!caster)
                        continue;
                    int32 absorbed = RemainingDamage * currentAbsorb / 100;
                    int32 canabsorb = caster->GetHealth();
                    if (canabsorb < absorbed)
                        absorbed = canabsorb;
                    DealDamage(caster, absorbed, NULL, damagetype, schoolMask, 0, false);
                    RemainingDamage -= absorbed;
                    continue;
                }
                break;
            }
            default:
                break;
        }

        // currentAbsorb - damage can be absorbed by shield
        // If need absorb less damage
        if (RemainingDamage < currentAbsorb)
            currentAbsorb = RemainingDamage;

        RemainingDamage -= currentAbsorb;

        // Reduce shield amount
        (*i)->SetAmount((*i)->GetAmount() -currentAbsorb);
        // Need remove it later
        if ((*i)->GetAmount()<=0)
            existExpired = true;
    }
    if(healSpell && healCaster)
       healCaster->CastCustomSpell(healCaster, healSpell, &healAmount, NULL, NULL, true);

    // Remove all expired absorb auras
    if (existExpired)
    {
        for(AuraEffectList::const_iterator i = vSchoolAbsorb.begin(); i != vSchoolAbsorb.end();)
        {
            Aura *aura=(*i)->GetParentAura();
            AuraEffect *auraeff =(*i);
            ++i;
            if (auraeff->GetAmount()<=0)
            {
                uint32 removedAuras = pVictim->m_removedAurasCount;
                pVictim->RemoveAura(aura, AURA_REMOVE_BY_ENEMY_SPELL);
                if (removedAuras+1<pVictim->m_removedAurasCount)
                    i=vSchoolAbsorb.begin();
            }
        }
    }
    // Cast back reflect damage spell
    if (reflectSpell)
        pVictim->CastCustomSpell(this,  reflectSpell, &reflectDamage, NULL, NULL, true);

    // absorb by mana cost
    AuraEffectList const& vManaShield = pVictim->GetAurasByType(SPELL_AURA_MANA_SHIELD);
    for(AuraEffectList::const_iterator i = vManaShield.begin(), next; i != vManaShield.end() && RemainingDamage > 0; i = next)
    {
        next = i; ++next;

        // check damage school mask
        if(((*i)->GetMiscValue() & schoolMask)==0)
            continue;

        int32 currentAbsorb;
        if (RemainingDamage >= (*i)->GetAmount())
            currentAbsorb = (*i)->GetAmount();
        else
            currentAbsorb = RemainingDamage;

        float manaMultiplier = (*i)->GetSpellProto()->EffectMultipleValue[(*i)->GetEffIndex()];
        if(Player *modOwner = pVictim->GetSpellModOwner())
            modOwner->ApplySpellMod((*i)->GetId(), SPELLMOD_MULTIPLE_VALUE, manaMultiplier);

        int32 maxAbsorb = int32(pVictim->GetPower(POWER_MANA) / manaMultiplier);
        if (currentAbsorb > maxAbsorb)
            currentAbsorb = maxAbsorb;

        (*i)->SetAmount((*i)->GetAmount()-currentAbsorb);
        if((*i)->GetAmount() <= 0)
        {
            pVictim->RemoveAura((*i)->GetParentAura(), AURA_REMOVE_BY_ENEMY_SPELL);
            next = vManaShield.begin();
        }

        int32 manaReduction = int32(currentAbsorb * manaMultiplier);
        pVictim->ApplyPowerMod(POWER_MANA, manaReduction, false);

        RemainingDamage -= currentAbsorb;
    }

    // only split damage if not damaging yourself
    if(pVictim != this)
    {
        AuraEffectList const& vSplitDamageFlat = pVictim->GetAurasByType(SPELL_AURA_SPLIT_DAMAGE_FLAT);
        for(AuraEffectList::const_iterator i = vSplitDamageFlat.begin(), next; i != vSplitDamageFlat.end() && RemainingDamage >= 0; i = next)
        {
            next = i; ++next;

            // check damage school mask
            if(((*i)->GetMiscValue() & schoolMask)==0)
                continue;

            // Damage can be splitted only if aura has an alive caster
            Unit *caster = (*i)->GetCaster();
            if(!caster || caster == pVictim || !caster->IsInWorld() || !caster->isAlive())
                continue;

            int32 currentAbsorb;
            if (RemainingDamage >= (*i)->GetAmount())
                currentAbsorb = (*i)->GetAmount();
            else
                currentAbsorb = RemainingDamage;

            RemainingDamage -= currentAbsorb;

            SendSpellNonMeleeDamageLog(caster, (*i)->GetSpellProto()->Id, currentAbsorb, schoolMask, 0, 0, false, 0, false);

            CleanDamage cleanDamage = CleanDamage(currentAbsorb, BASE_ATTACK, MELEE_HIT_NORMAL);
            DealDamage(caster, currentAbsorb, &cleanDamage, DIRECT_DAMAGE, schoolMask, (*i)->GetSpellProto(), false);
        }

        AuraEffectList const& vSplitDamagePct = pVictim->GetAurasByType(SPELL_AURA_SPLIT_DAMAGE_PCT);
        for(AuraEffectList::const_iterator i = vSplitDamagePct.begin(), next; i != vSplitDamagePct.end() && RemainingDamage >= 0; i = next)
        {
            next = i; ++next;

            // check damage school mask
            if(((*i)->GetMiscValue() & schoolMask)==0)
                continue;

            // Damage can be splitted only if aura has an alive caster
            Unit *caster = (*i)->GetCaster();
            if(!caster || caster == pVictim || !caster->IsInWorld() || !caster->isAlive())
                continue;

            int32 splitted = int32(RemainingDamage * (*i)->GetAmount() / 100.0f);

            RemainingDamage -= splitted;

            SendSpellNonMeleeDamageLog(caster, (*i)->GetSpellProto()->Id, splitted, schoolMask, 0, 0, false, 0, false);

            CleanDamage cleanDamage = CleanDamage(splitted, BASE_ATTACK, MELEE_HIT_NORMAL);
            DealDamage(caster, splitted, &cleanDamage, DIRECT_DAMAGE, schoolMask, (*i)->GetSpellProto(), false);
        }
    }

    TotalAbsorb = (TotalAbsorb - RemainingDamage > 0) ? TotalAbsorb - RemainingDamage : 0;
    // TODO: School should be checked for absorbing auras or for attacks?
    int32 auraAbsorbMod = GetMaxPositiveAuraModifier(SPELL_AURA_MOD_TARGET_ABSORB_SCHOOL);
    AuraEffectList const& AbsIgnoreAurasAb = GetAurasByType(SPELL_AURA_MOD_TARGET_ABILITY_ABSORB_SCHOOL);
    for(AuraEffectList::const_iterator i = AbsIgnoreAurasAb.begin();i != AbsIgnoreAurasAb.end(); ++i)
    {
        if ((*i)->GetAmount() > auraAbsorbMod
            && (*i)->isAffectedOnSpell(spellInfo))
            auraAbsorbMod = (*i)->GetAmount();
    }

    // Ignore absorb - add reduced amount again to damage
    RemainingDamage += auraAbsorbMod * TotalAbsorb / 100;

    *absorb = damage - RemainingDamage - *resist;

    if (*absorb)
    {
        bool found = false;
        int32 spell_dmg=0;
        // Incanter's Absorption
        AuraEffectList const& DummmyAuras = pVictim->GetAurasByType(SPELL_AURA_DUMMY);
        for(AuraEffectList::const_iterator i = DummmyAuras.begin(); i != DummmyAuras.end(); ++i)
        {
            SpellEntry const* spellInfo = (*i)->GetSpellProto();
            if (spellmgr.GetFirstSpellInChain(spellInfo->Id) == 44394)
            {
                int32 total_dmg=0;
                // Get total bonus from auras
                AuraEffectList const& BonusAuras = pVictim->GetAurasByType(SPELL_AURA_MOD_DAMAGE_DONE);
                for(AuraEffectList::const_iterator itr = BonusAuras.begin(); itr != BonusAuras.end(); ++itr)
                {
                    if ((*itr)->GetId()==44413)
                        total_dmg += (*itr)->GetMiscValue();
                }
                spell_dmg = int32(*absorb * (*i)->GetAmount() / 100);
                // Do not apply more auras if more than 5% hp
                if(total_dmg+spell_dmg > int32(GetMaxHealth() * 5 / 100))
                    break;
                found=true;
                break;
             }
        }
        if (found)
            pVictim->CastCustomSpell(pVictim, 44413, &spell_dmg, NULL, NULL, false);
    }
}

void Unit::AttackerStateUpdate (Unit *pVictim, WeaponAttackType attType, bool extra )
{
    if(hasUnitState(UNIT_STAT_CANNOT_AUTOATTACK) || HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PACIFIED) )
        return;

    if (!pVictim->isAlive())
        return;

    CombatStart(pVictim);
    RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_ATTACK);

    uint32 hitInfo;
    if (attType == BASE_ATTACK)
        hitInfo = HITINFO_NORMALSWING2;
    else if (attType == OFF_ATTACK)
        hitInfo = HITINFO_LEFTSWING;
    else
        return;                                             // ignore ranged case

    uint32 extraAttacks = m_extraAttacks;

    // melee attack spell casted at main hand attack only
    if (attType == BASE_ATTACK && m_currentSpells[CURRENT_MELEE_SPELL])
    {
        m_currentSpells[CURRENT_MELEE_SPELL]->cast();

        // not recent extra attack only at any non extra attack (melee spell case)
        if(!extra && extraAttacks)
        {
            while(m_extraAttacks)
            {
                AttackerStateUpdate(pVictim, BASE_ATTACK, true);
                if(m_extraAttacks > 0)
                    --m_extraAttacks;
            }
        }
        return;
    }

    // attack can be redirected to another target
    pVictim = SelectMagnetTarget(pVictim);

    CalcDamageInfo damageInfo;
    CalculateMeleeDamage(pVictim, 0, &damageInfo, attType);
    // Send log damage message to client
    SendAttackStateUpdate(&damageInfo);
    ProcDamageAndSpell(damageInfo.target, damageInfo.procAttacker, damageInfo.procVictim, damageInfo.procEx, damageInfo.damage, damageInfo.attackType);
    DealMeleeDamage(&damageInfo,true);

    if (GetTypeId() == TYPEID_PLAYER)
        DEBUG_LOG("AttackerStateUpdate: (Player) %u attacked %u (TypeId: %u) for %u dmg, absorbed %u, blocked %u, resisted %u.",
            GetGUIDLow(), pVictim->GetGUIDLow(), pVictim->GetTypeId(), damageInfo.damage, damageInfo.absorb, damageInfo.blocked_amount, damageInfo.resist);
    else
        DEBUG_LOG("AttackerStateUpdate: (NPC)    %u attacked %u (TypeId: %u) for %u dmg, absorbed %u, blocked %u, resisted %u.",
            GetGUIDLow(), pVictim->GetGUIDLow(), pVictim->GetTypeId(), damageInfo.damage, damageInfo.absorb, damageInfo.blocked_amount, damageInfo.resist);

    // if damage pVictim call AI reaction
    //if(pVictim->GetTypeId()==TYPEID_UNIT && ((Creature*)pVictim)->AI())
    //    ((Creature*)pVictim)->AI()->AttackedBy(this);

    // extra attack only at any non extra attack (normal case)
    if(!extra && extraAttacks)
    {
        while(m_extraAttacks)
        {
            AttackerStateUpdate(pVictim, BASE_ATTACK, true);
            if(m_extraAttacks > 0)
                --m_extraAttacks;
        }
    }
}

MeleeHitOutcome Unit::RollMeleeOutcomeAgainst(const Unit *pVictim, WeaponAttackType attType) const
{
    // This is only wrapper

    // Miss chance based on melee
    //float miss_chance = MeleeMissChanceCalc(pVictim, attType);
    float miss_chance = MeleeSpellMissChance(pVictim, attType, int32(GetWeaponSkillValue(attType,pVictim)) - int32(pVictim->GetDefenseSkillValue(this)), 0);

    // Critical hit chance
    float crit_chance = GetUnitCriticalChance(attType, pVictim);

    // stunned target cannot dodge and this is check in GetUnitDodgeChance() (returned 0 in this case)
    float dodge_chance = pVictim->GetUnitDodgeChance();
    float block_chance = pVictim->GetUnitBlockChance();
    float parry_chance = pVictim->GetUnitParryChance();

    // Useful if want to specify crit & miss chances for melee, else it could be removed
    DEBUG_LOG("MELEE OUTCOME: miss %f crit %f dodge %f parry %f block %f", miss_chance,crit_chance,dodge_chance,parry_chance,block_chance);

    return RollMeleeOutcomeAgainst(pVictim, attType, int32(crit_chance*100), int32(miss_chance*100), int32(dodge_chance*100),int32(parry_chance*100),int32(block_chance*100));
}

MeleeHitOutcome Unit::RollMeleeOutcomeAgainst (const Unit *pVictim, WeaponAttackType attType, int32 crit_chance, int32 miss_chance, int32 dodge_chance, int32 parry_chance, int32 block_chance) const
{
    if(pVictim->GetTypeId()==TYPEID_UNIT && ((Creature*)pVictim)->IsInEvadeMode())
        return MELEE_HIT_EVADE;

    int32 attackerMaxSkillValueForLevel = GetMaxSkillValueForLevel(pVictim);
    int32 victimMaxSkillValueForLevel = pVictim->GetMaxSkillValueForLevel(this);

    int32 attackerWeaponSkill = GetWeaponSkillValue(attType,pVictim);
    int32 victimDefenseSkill = pVictim->GetDefenseSkillValue(this);

    // bonus from skills is 0.04%
    int32    skillBonus  = 4 * ( attackerWeaponSkill - victimMaxSkillValueForLevel );
    int32    sum = 0, tmp = 0;
    int32    roll = urand (0, 10000);

    DEBUG_LOG ("RollMeleeOutcomeAgainst: skill bonus of %d for attacker", skillBonus);
    DEBUG_LOG ("RollMeleeOutcomeAgainst: rolled %d, miss %d, dodge %d, parry %d, block %d, crit %d",
        roll, miss_chance, dodge_chance, parry_chance, block_chance, crit_chance);

    tmp = miss_chance;

    if (tmp > 0 && roll < (sum += tmp ))
    {
        DEBUG_LOG ("RollMeleeOutcomeAgainst: MISS");
        return MELEE_HIT_MISS;
    }

    // always crit against a sitting target (except 0 crit chance)
    if( pVictim->GetTypeId() == TYPEID_PLAYER && crit_chance > 0 && !pVictim->IsStandState() )
    {
        DEBUG_LOG ("RollMeleeOutcomeAgainst: CRIT (sitting victim)");
        return MELEE_HIT_CRIT;
    }

    // Dodge chance

    // only players can't dodge if attacker is behind
    if (pVictim->GetTypeId() == TYPEID_PLAYER && !pVictim->HasInArc(M_PI,this))
    {
        DEBUG_LOG ("RollMeleeOutcomeAgainst: attack came from behind and victim was a player.");
    }
    else
    {
        // Reduce dodge chance by attacker expertise rating
        if (GetTypeId() == TYPEID_PLAYER)
            dodge_chance -= int32(((Player*)this)->GetExpertiseDodgeOrParryReduction(attType)*100);

        // Modify dodge chance by attacker SPELL_AURA_MOD_COMBAT_RESULT_CHANCE
        dodge_chance+= GetTotalAuraModifierByMiscValue(SPELL_AURA_MOD_COMBAT_RESULT_CHANCE, VICTIMSTATE_DODGE);
        dodge_chance = int32 (float (dodge_chance) * GetTotalAuraMultiplier(SPELL_AURA_MOD_ENEMY_DODGE));

        tmp = dodge_chance;
        if (   (tmp > 0)                                        // check if unit _can_ dodge
            && ((tmp -= skillBonus) > 0)
            && roll < (sum += tmp))
        {
            DEBUG_LOG ("RollMeleeOutcomeAgainst: DODGE <%d, %d)", sum-tmp, sum);
            return MELEE_HIT_DODGE;
        }
    }

    // parry & block chances

    // check if attack comes from behind, nobody can parry or block if attacker is behind
    if (!pVictim->HasInArc(M_PI,this))
    {
        DEBUG_LOG ("RollMeleeOutcomeAgainst: attack came from behind.");
    }
    else
    {
        // Reduce parry chance by attacker expertise rating
        if (GetTypeId() == TYPEID_PLAYER)
            parry_chance-= int32(((Player*)this)->GetExpertiseDodgeOrParryReduction(attType)*100);

        if(pVictim->GetTypeId()==TYPEID_PLAYER || !(((Creature*)pVictim)->GetCreatureInfo()->flags_extra & CREATURE_FLAG_EXTRA_NO_PARRY) )
        {
            int32 tmp2 = int32(parry_chance);
            if (   (tmp2 > 0)                                   // check if unit _can_ parry
                && ((tmp2 -= skillBonus) > 0)
                && (roll < (sum += tmp2)))
            {
                DEBUG_LOG ("RollMeleeOutcomeAgainst: PARRY <%d, %d)", sum-tmp2, sum);
                return MELEE_HIT_PARRY;
            }
        }

        if(pVictim->GetTypeId()==TYPEID_PLAYER || !(((Creature*)pVictim)->GetCreatureInfo()->flags_extra & CREATURE_FLAG_EXTRA_NO_BLOCK) )
        {
            tmp = block_chance;
            if (   (tmp > 0)                                    // check if unit _can_ block
                && ((tmp -= skillBonus) > 0)
                && (roll < (sum += tmp)))
            {
                DEBUG_LOG ("RollMeleeOutcomeAgainst: BLOCK <%d, %d)", sum-tmp, sum);
                return MELEE_HIT_BLOCK;
            }
        }
    }

    // Critical chance
    tmp = crit_chance;

    if (tmp > 0 && roll < (sum += tmp))
    {
        DEBUG_LOG ("RollMeleeOutcomeAgainst: CRIT <%d, %d)", sum-tmp, sum);
        if(GetTypeId() == TYPEID_UNIT && (((Creature*)this)->GetCreatureInfo()->flags_extra & CREATURE_FLAG_EXTRA_NO_CRIT))
            DEBUG_LOG ("RollMeleeOutcomeAgainst: CRIT DISABLED)");
        else
            return MELEE_HIT_CRIT;
    }

    // Max 40% chance to score a glancing blow against mobs that are higher level (can do only players and pets and not with ranged weapon)
    if( attType != RANGED_ATTACK &&
        (GetTypeId() == TYPEID_PLAYER || ((Creature*)this)->isPet()) &&
        pVictim->GetTypeId() != TYPEID_PLAYER && !((Creature*)pVictim)->isPet() &&
        getLevel() < pVictim->getLevelForTarget(this) )
    {
        // cap possible value (with bonuses > max skill)
        int32 skill = attackerWeaponSkill;
        int32 maxskill = attackerMaxSkillValueForLevel;
        skill = (skill > maxskill) ? maxskill : skill;

        tmp = (10 + (victimDefenseSkill - skill)) * 100;
        tmp = tmp > 4000 ? 4000 : tmp;
        if (roll < (sum += tmp))
        {
            DEBUG_LOG ("RollMeleeOutcomeAgainst: GLANCING <%d, %d)", sum-4000, sum);
            return MELEE_HIT_GLANCING;
        }
    }

    // mobs can score crushing blows if they're 4 or more levels above victim
    if (getLevelForTarget(pVictim) >= pVictim->getLevelForTarget(this) + 4 &&
        // can be from by creature (if can) or from controlled player that considered as creature
        !IsControlledByPlayer() &&
        !(GetTypeId() == TYPEID_UNIT && ((Creature*)this)->GetCreatureInfo()->flags_extra & CREATURE_FLAG_EXTRA_NO_CRUSH))
    {
        // when their weapon skill is 15 or more above victim's defense skill
        tmp = victimDefenseSkill;
        int32 tmpmax = victimMaxSkillValueForLevel;
        // having defense above your maximum (from items, talents etc.) has no effect
        tmp = tmp > tmpmax ? tmpmax : tmp;
        // tmp = mob's level * 5 - player's current defense skill
        tmp = attackerMaxSkillValueForLevel - tmp;
        if(tmp >= 15)
        {
            // add 2% chance per lacking skill point, min. is 15%
            tmp = tmp * 200 - 1500;
            if (roll < (sum += tmp))
            {
                DEBUG_LOG ("RollMeleeOutcomeAgainst: CRUSHING <%d, %d)", sum-tmp, sum);
                return MELEE_HIT_CRUSHING;
            }
        }
    }

    DEBUG_LOG ("RollMeleeOutcomeAgainst: NORMAL");
    return MELEE_HIT_NORMAL;
}

uint32 Unit::CalculateDamage (WeaponAttackType attType, bool normalized)
{
    float min_damage, max_damage;

    if (normalized && GetTypeId()==TYPEID_PLAYER)
        ((Player*)this)->CalculateMinMaxDamage(attType,normalized,min_damage, max_damage);
    else
    {
        switch (attType)
        {
            case RANGED_ATTACK:
                min_damage = GetFloatValue(UNIT_FIELD_MINRANGEDDAMAGE);
                max_damage = GetFloatValue(UNIT_FIELD_MAXRANGEDDAMAGE);
                break;
            case BASE_ATTACK:
                min_damage = GetFloatValue(UNIT_FIELD_MINDAMAGE);
                max_damage = GetFloatValue(UNIT_FIELD_MAXDAMAGE);
                break;
            case OFF_ATTACK:
                min_damage = GetFloatValue(UNIT_FIELD_MINOFFHANDDAMAGE);
                max_damage = GetFloatValue(UNIT_FIELD_MAXOFFHANDDAMAGE);
                break;
                // Just for good manner
            default:
                min_damage = 0.0f;
                max_damage = 0.0f;
                break;
        }
    }

    if (min_damage > max_damage)
    {
        std::swap(min_damage,max_damage);
    }

    if(max_damage == 0.0f)
        max_damage = 5.0f;

    return urand((uint32)min_damage, (uint32)max_damage);
}

float Unit::CalculateLevelPenalty(SpellEntry const* spellProto) const
{
    if(spellProto->spellLevel <= 0)
        return 1.0f;

    float LvlPenalty = 0.0f;

    if(spellProto->spellLevel < 20)
        LvlPenalty = 20.0f - spellProto->spellLevel * 3.75f;
    float LvlFactor = (float(spellProto->spellLevel) + 6.0f) / float(getLevel());
    if(LvlFactor > 1.0f)
        LvlFactor = 1.0f;

    return (100.0f - LvlPenalty) * LvlFactor / 100.0f;
}

void Unit::SendAttackStart(Unit* pVictim)
{
    WorldPacket data( SMSG_ATTACKSTART, 16 );
    data << uint64(GetGUID());
    data << uint64(pVictim->GetGUID());

    SendMessageToSet(&data, true);
    DEBUG_LOG( "WORLD: Sent SMSG_ATTACKSTART" );
}

void Unit::SendAttackStop(Unit* victim)
{
    if(!victim)
        return;

    WorldPacket data( SMSG_ATTACKSTOP, (4+16) );            // we guess size
    data.append(GetPackGUID());
    data.append(victim->GetPackGUID());                     // can be 0x00...
    data << uint32(0);                                      // can be 0x1
    SendMessageToSet(&data, true);
    sLog.outDetail("%s %u stopped attacking %s %u", (GetTypeId()==TYPEID_PLAYER ? "player" : "creature"), GetGUIDLow(), (victim->GetTypeId()==TYPEID_PLAYER ? "player" : "creature"),victim->GetGUIDLow());

    /*if(victim->GetTypeId() == TYPEID_UNIT)
    ((Creature*)victim)->AI().EnterEvadeMode(this);*/
}

bool Unit::isSpellBlocked(Unit *pVictim, SpellEntry const *spellProto, WeaponAttackType attackType)
{
    if (pVictim->HasInArc(M_PI,this))
    {
        /* Currently not exist spells with ignore block
        // Ignore combat result aura (parry/dodge check on prepare)
        AuraList const& ignore = GetAurasByType(SPELL_AURA_IGNORE_COMBAT_RESULT);
        for(AuraList::const_iterator i = ignore.begin(); i != ignore.end(); ++i)
        {
            if (!(*i)->isAffectedOnSpell(spellProto))
                continue;
            if ((*i)->GetMiscValue() == )
                return false;
        }
        */

        // Check creatures flags_extra for disable block
        if(pVictim->GetTypeId()==TYPEID_UNIT &&
           ((Creature*)pVictim)->GetCreatureInfo()->flags_extra & CREATURE_FLAG_EXTRA_NO_BLOCK )
                return false;

        float blockChance = pVictim->GetUnitBlockChance();
        blockChance += (int32(GetWeaponSkillValue(attackType)) - int32(pVictim->GetMaxSkillValueForLevel()))*0.04f;
        if (roll_chance_f(blockChance))
            return true;
    }
    return false;
}

bool Unit::isBlockCritical()
{
    if (roll_chance_i(GetTotalAuraModifier(SPELL_AURA_MOD_BLOCK_CRIT_CHANCE)))
        return true;
    return false;
}

// Melee based spells can be miss, parry or dodge on this step
// Crit or block - determined on damage calculation phase! (and can be both in some time)
/*float Unit::MeleeSpellMissChance(Unit *pVictim, WeaponAttackType attType, int32 skillDiff, SpellEntry const *spell)
{
    // Calculate hit chance (more correct for chance mod)
    int32 HitChance;

    // PvP - PvE melee chances
    int32 lchance = pVictim->GetTypeId() == TYPEID_PLAYER ? 5 : 7;
    int32 leveldif = pVictim->getLevelForTarget(this) - getLevelForTarget(pVictim);
    if(leveldif < 3)
        HitChance = 95 - leveldif;
    else
        HitChance = 93 - (leveldif - 2) * lchance;

    // Hit chance depends from victim auras
    if(attType == RANGED_ATTACK)
        HitChance += pVictim->GetTotalAuraModifier(SPELL_AURA_MOD_ATTACKER_RANGED_HIT_CHANCE);
    else
        HitChance += pVictim->GetTotalAuraModifier(SPELL_AURA_MOD_ATTACKER_MELEE_HIT_CHANCE);

    // Spellmod from SPELLMOD_RESIST_MISS_CHANCE
    if(Player *modOwner = GetSpellModOwner())
        modOwner->ApplySpellMod(spell->Id, SPELLMOD_RESIST_MISS_CHANCE, HitChance);

    // Miss = 100 - hit
    float miss_chance= 100.0f - HitChance;

    // Bonuses from attacker aura and ratings
    if (attType == RANGED_ATTACK)
        miss_chance -= m_modRangedHitChance;
    else
        miss_chance -= m_modMeleeHitChance;

    // bonus from skills is 0.04%
    miss_chance -= skillDiff * 0.04f;

    // Limit miss chance from 0 to 60%
    if (miss_chance < 0.0f)
        return 0.0f;
    if (miss_chance > 60.0f)
        return 60.0f;
    return miss_chance;
}*/

// Melee based spells hit result calculations
SpellMissInfo Unit::MeleeSpellHitResult(Unit *pVictim, SpellEntry const *spell)
{
    WeaponAttackType attType = BASE_ATTACK;

    if (spell->DmgClass == SPELL_DAMAGE_CLASS_RANGED)
        attType = RANGED_ATTACK;

    // bonus from skills is 0.04% per skill Diff
    int32 attackerWeaponSkill = int32(GetWeaponSkillValue(attType,pVictim));
    int32 skillDiff = attackerWeaponSkill - int32(pVictim->GetMaxSkillValueForLevel(this));
    int32 fullSkillDiff = attackerWeaponSkill - int32(pVictim->GetDefenseSkillValue(this));

    uint32 roll = urand (0, 10000);

    uint32 missChance = uint32(MeleeSpellMissChance(pVictim, attType, fullSkillDiff, spell->Id)*100.0f);
    // Roll miss
    uint32 tmp = missChance;
    if (roll < tmp)
        return SPELL_MISS_MISS;

    // Chance resist mechanic (select max value from every mechanic spell effect)
    int32 resist_mech = 0;
    // Get effects mechanic and chance
    for(int eff = 0; eff < 3; ++eff)
    {
        int32 effect_mech = GetEffectMechanic(spell, eff);
        if (effect_mech)
        {
            int32 temp = pVictim->GetTotalAuraModifierByMiscValue(SPELL_AURA_MOD_MECHANIC_RESISTANCE, effect_mech);
            if (resist_mech < temp*100)
                resist_mech = temp*100;
        }
    }
    // Roll chance
    tmp += resist_mech;
    if (roll < tmp)
        return SPELL_MISS_RESIST;

    bool canDodge = true;
    bool canParry = true;

    // Same spells cannot be parry/dodge
    if (spell->Attributes & SPELL_ATTR_IMPOSSIBLE_DODGE_PARRY_BLOCK)
        return SPELL_MISS_NONE;

    // Ranged attack cannot be parry/dodge only deflect
    if (attType == RANGED_ATTACK)
    {
        // only if in front
        if (pVictim->HasInArc(M_PI,this))
        {
            int32 deflect_chance = pVictim->GetTotalAuraModifier(SPELL_AURA_DEFLECT_SPELLS)*100;
            tmp+=deflect_chance;
            if (roll < tmp)
                return SPELL_MISS_DEFLECT;
        }
        return SPELL_MISS_NONE;
    }

    // Check for attack from behind
    if (!pVictim->HasInArc(M_PI,this))
    {
        // Can`t dodge from behind in PvP (but its possible in PvE)
        if (GetTypeId() == TYPEID_PLAYER && pVictim->GetTypeId() == TYPEID_PLAYER)
            canDodge = false;
        // Can`t parry
        canParry = false;
    }
    // Check creatures flags_extra for disable parry
    if(pVictim->GetTypeId()==TYPEID_UNIT)
    {
        uint32 flagEx = ((Creature*)pVictim)->GetCreatureInfo()->flags_extra;
        if( flagEx & CREATURE_FLAG_EXTRA_NO_PARRY )
            canParry = false;
    }
    // Ignore combat result aura
    AuraEffectList const& ignore = GetAurasByType(SPELL_AURA_IGNORE_COMBAT_RESULT);
    for(AuraEffectList::const_iterator i = ignore.begin(); i != ignore.end(); ++i)
    {
        if (!(*i)->isAffectedOnSpell(spell))
            continue;
        switch((*i)->GetMiscValue())
        {
            case MELEE_HIT_DODGE: canDodge = false; break;
            case MELEE_HIT_BLOCK: break; // Block check in hit step
            case MELEE_HIT_PARRY: canParry = false; break;
            default:
                DEBUG_LOG("Spell %u SPELL_AURA_IGNORE_COMBAT_RESULT have unhandled state %d", (*i)->GetId(), (*i)->GetMiscValue());
                break;
        }
    }

    if (canDodge)
    {
        // Roll dodge
        int32 dodgeChance = int32(pVictim->GetUnitDodgeChance()*100.0f) - skillDiff * 4;
        // Reduce enemy dodge chance by SPELL_AURA_MOD_COMBAT_RESULT_CHANCE
        dodgeChance+= GetTotalAuraModifierByMiscValue(SPELL_AURA_MOD_COMBAT_RESULT_CHANCE, VICTIMSTATE_DODGE)*100;
        dodgeChance = int32 (float (dodgeChance) * GetTotalAuraMultiplier(SPELL_AURA_MOD_ENEMY_DODGE));
        // Reduce dodge chance by attacker expertise rating
        if (GetTypeId() == TYPEID_PLAYER)
            dodgeChance-=int32(((Player*)this)->GetExpertiseDodgeOrParryReduction(attType) * 100.0f);
        if (dodgeChance < 0)
            dodgeChance = 0;

        tmp += dodgeChance;
        if (roll < tmp)
            return SPELL_MISS_DODGE;
    }

    if (canParry)
    {
        // Roll parry
        int32 parryChance = int32(pVictim->GetUnitParryChance()*100.0f)  - skillDiff * 4;
        // Reduce parry chance by attacker expertise rating
        if (GetTypeId() == TYPEID_PLAYER)
            parryChance-=int32(((Player*)this)->GetExpertiseDodgeOrParryReduction(attType) * 100.0f);
        if (parryChance < 0)
            parryChance = 0;

        tmp += parryChance;
        if (roll < tmp)
            return SPELL_MISS_PARRY;
    }

    return SPELL_MISS_NONE;
}

// TODO need use unit spell resistances in calculations
SpellMissInfo Unit::MagicSpellHitResult(Unit *pVictim, SpellEntry const *spell)
{
    // Can`t miss on dead target (on skinning for example)
    if (!pVictim->isAlive())
        return SPELL_MISS_NONE;

    SpellSchoolMask schoolMask = GetSpellSchoolMask(spell);
    // PvP - PvE spell misschances per leveldif > 2
    int32 lchance = pVictim->GetTypeId() == TYPEID_PLAYER ? 7 : 11;
    int32 leveldif = int32(pVictim->getLevelForTarget(this)) - int32(getLevelForTarget(pVictim));

    // Base hit chance from attacker and victim levels
    int32 modHitChance;
    if(leveldif < 3)
        modHitChance = 96 - leveldif;
    else
        modHitChance = 94 - (leveldif - 2) * lchance;

    // Spellmod from SPELLMOD_RESIST_MISS_CHANCE
    if(Player *modOwner = GetSpellModOwner())
        modOwner->ApplySpellMod(spell->Id, SPELLMOD_RESIST_MISS_CHANCE, modHitChance);
    // Increase from attacker SPELL_AURA_MOD_INCREASES_SPELL_PCT_TO_HIT auras
    modHitChance+=GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_INCREASES_SPELL_PCT_TO_HIT, schoolMask);
    // Chance hit from victim SPELL_AURA_MOD_ATTACKER_SPELL_HIT_CHANCE auras
    modHitChance+= pVictim->GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_ATTACKER_SPELL_HIT_CHANCE, schoolMask);
    // Reduce spell hit chance for Area of effect spells from victim SPELL_AURA_MOD_AOE_AVOIDANCE aura
    if (IsAreaOfEffectSpell(spell))
        modHitChance-=pVictim->GetTotalAuraModifier(SPELL_AURA_MOD_AOE_AVOIDANCE);
    // Reduce spell hit chance for dispel mechanic spells from victim SPELL_AURA_MOD_DISPEL_RESIST
    if (IsDispelSpell(spell))
        modHitChance-=pVictim->GetTotalAuraModifier(SPELL_AURA_MOD_DISPEL_RESIST);
    // Chance resist mechanic (select max value from every mechanic spell effect)
    int32 resist_mech = 0;
    // Get effects mechanic and chance
    for(int eff = 0; eff < 3; ++eff)
    {
        int32 effect_mech = GetEffectMechanic(spell, eff);
        if (effect_mech)
        {
            int32 temp = pVictim->GetTotalAuraModifierByMiscValue(SPELL_AURA_MOD_MECHANIC_RESISTANCE, effect_mech);
            if (resist_mech < temp)
                resist_mech = temp;
        }
    }
    // Apply mod
    modHitChance-=resist_mech;

    // Chance resist debuff
    modHitChance-=pVictim->GetTotalAuraModifierByMiscValue(SPELL_AURA_MOD_DEBUFF_RESISTANCE, int32(spell->Dispel));

    int32 HitChance = modHitChance * 100;
    // Increase hit chance from attacker SPELL_AURA_MOD_SPELL_HIT_CHANCE and attacker ratings
    HitChance += int32(m_modSpellHitChance*100.0f);

    // Decrease hit chance from victim rating bonus
    if (pVictim->GetTypeId()==TYPEID_PLAYER)
        HitChance -= int32(((Player*)pVictim)->GetRatingBonusValue(CR_HIT_TAKEN_SPELL)*100.0f);

    if (HitChance <  100) HitChance =  100;
    if (HitChance > 10000) HitChance = 10000;

    int32 tmp = 10000 - HitChance;

    uint32 rand = urand(0,10000);

    if (rand < tmp)
        return SPELL_MISS_RESIST;

    // cast by caster in front of victim
    if (pVictim->HasInArc(M_PI,this))
    {
        int32 deflect_chance = pVictim->GetTotalAuraModifier(SPELL_AURA_DEFLECT_SPELLS)*100;
        tmp+=deflect_chance;
        if (rand < tmp)
            return SPELL_MISS_DEFLECT;
    }

    return SPELL_MISS_NONE;
}

// Calculate spell hit result can be:
// Every spell can: Evade/Immune/Reflect/Sucesful hit
// For melee based spells:
//   Miss
//   Dodge
//   Parry
// For spells
//   Resist
SpellMissInfo Unit::SpellHitResult(Unit *pVictim, SpellEntry const *spell, bool CanReflect)
{
    // Return evade for units in evade mode
    if (pVictim->GetTypeId()==TYPEID_UNIT && ((Creature*)pVictim)->IsInEvadeMode())
        return SPELL_MISS_EVADE;

    // Check for immune
    if (pVictim->IsImmunedToSpell(spell))
        return SPELL_MISS_IMMUNE;

    // All positive spells can`t miss
    // TODO: client not show miss log for this spells - so need find info for this in dbc and use it!
    if (IsPositiveSpell(spell->Id)
        &&(!IsHostileTo(pVictim)))  //prevent from affecting enemy by "positive" spell
        return SPELL_MISS_NONE;
    // Check for immune
    if (pVictim->IsImmunedToDamage(spell))
        return SPELL_MISS_IMMUNE;

    if(this == pVictim)
        return SPELL_MISS_NONE;

    // Try victim reflect spell
    if (CanReflect)
    {
        int32 reflectchance = pVictim->GetTotalAuraModifier(SPELL_AURA_REFLECT_SPELLS);
        Unit::AuraEffectList const& mReflectSpellsSchool = pVictim->GetAurasByType(SPELL_AURA_REFLECT_SPELLS_SCHOOL);
        for(Unit::AuraEffectList::const_iterator i = mReflectSpellsSchool.begin(); i != mReflectSpellsSchool.end(); ++i)
            if((*i)->GetMiscValue() & GetSpellSchoolMask(spell))
                reflectchance += (*i)->GetAmount();
        if (reflectchance > 0 && roll_chance_i(reflectchance))
        {
            // Start triggers for remove charges if need (trigger only for victim, and mark as active spell)
            ProcDamageAndSpell(pVictim, PROC_FLAG_NONE, PROC_FLAG_TAKEN_NEGATIVE_SPELL_HIT, PROC_EX_REFLECT, 1, BASE_ATTACK, spell);
            return SPELL_MISS_REFLECT;
        }
    }

    switch (spell->DmgClass)
    {
        case SPELL_DAMAGE_CLASS_RANGED:
        case SPELL_DAMAGE_CLASS_MELEE:
            return MeleeSpellHitResult(pVictim, spell);
        case SPELL_DAMAGE_CLASS_NONE:
            return SPELL_MISS_NONE;
        case SPELL_DAMAGE_CLASS_MAGIC:
            return MagicSpellHitResult(pVictim, spell);
    }
    return SPELL_MISS_NONE;
}

/*float Unit::MeleeMissChanceCalc(const Unit *pVictim, WeaponAttackType attType) const
{
    if(!pVictim)
        return 0.0f;

    // Base misschance 5%
    float misschance = 5.0f;

    // DualWield - Melee spells and physical dmg spells - 5% , white damage 24%
    if (haveOffhandWeapon() && attType != RANGED_ATTACK)
    {
        bool isNormal = false;
        for (uint32 i = CURRENT_FIRST_NON_MELEE_SPELL; i < CURRENT_MAX_SPELL; i++)
        {
            if( m_currentSpells[i] && (GetSpellSchoolMask(m_currentSpells[i]->m_spellInfo) & SPELL_SCHOOL_MASK_NORMAL) )
            {
                isNormal = true;
                break;
            }
        }
        if (isNormal || m_currentSpells[CURRENT_MELEE_SPELL])
        {
            misschance = 5.0f;
        }
        else
        {
            misschance = 24.0f;
        }
    }

    // PvP : PvE melee misschances per leveldif > 2
    int32 chance = pVictim->GetTypeId() == TYPEID_PLAYER ? 5 : 7;

    int32 leveldif = int32(pVictim->getLevelForTarget(this)) - int32(getLevelForTarget(pVictim));
    if(leveldif < 0)
        leveldif = 0;

    // Hit chance from attacker based on ratings and auras
    float m_modHitChance;
    if (attType == RANGED_ATTACK)
        m_modHitChance = m_modRangedHitChance;
    else
        m_modHitChance = m_modMeleeHitChance;

    if(leveldif < 3)
        misschance += (leveldif - m_modHitChance);
    else
        misschance += ((leveldif - 2) * chance - m_modHitChance);

    // Hit chance for victim based on ratings
    if (pVictim->GetTypeId()==TYPEID_PLAYER)
    {
        if (attType == RANGED_ATTACK)
            misschance += ((Player*)pVictim)->GetRatingBonusValue(CR_HIT_TAKEN_RANGED);
        else
            misschance += ((Player*)pVictim)->GetRatingBonusValue(CR_HIT_TAKEN_MELEE);
    }

    // Modify miss chance by victim auras
    if(attType == RANGED_ATTACK)
        misschance -= pVictim->GetTotalAuraModifier(SPELL_AURA_MOD_ATTACKER_RANGED_HIT_CHANCE);
    else
        misschance -= pVictim->GetTotalAuraModifier(SPELL_AURA_MOD_ATTACKER_MELEE_HIT_CHANCE);

    // Modify miss chance from skill difference ( bonus from skills is 0.04% )
    int32 skillBonus = int32(GetWeaponSkillValue(attType,pVictim)) - int32(pVictim->GetDefenseSkillValue(this));
    misschance -= skillBonus * 0.04f;

    // Limit miss chance from 0 to 60%
    if ( misschance < 0.0f)
        return 0.0f;
    if ( misschance > 60.0f)
        return 60.0f;

    return misschance;
}*/

uint32 Unit::GetDefenseSkillValue(Unit const* target) const
{
    if(GetTypeId() == TYPEID_PLAYER)
    {
        // in PvP use full skill instead current skill value
        uint32 value = (target && target->GetTypeId() == TYPEID_PLAYER)
            ? ((Player*)this)->GetMaxSkillValue(SKILL_DEFENSE)
            : ((Player*)this)->GetSkillValue(SKILL_DEFENSE);
        value += uint32(((Player*)this)->GetRatingBonusValue(CR_DEFENSE_SKILL));
        return value;
    }
    else
        return GetUnitMeleeSkill(target);
}

float Unit::GetUnitDodgeChance() const
{
    if(hasUnitState(UNIT_STAT_STUNNED))
        return 0.0f;
    if( GetTypeId() == TYPEID_PLAYER )
        return GetFloatValue(PLAYER_DODGE_PERCENTAGE);
    else
    {
        if(((Creature const*)this)->isTotem())
            return 0.0f;
        else
        {
            float dodge = 5.0f;
            dodge += GetTotalAuraModifier(SPELL_AURA_MOD_DODGE_PERCENT);
            return dodge > 0.0f ? dodge : 0.0f;
        }
    }
}

float Unit::GetUnitParryChance() const
{
    if ( IsNonMeleeSpellCasted(false) || hasUnitState(UNIT_STAT_STUNNED))
        return 0.0f;

    float chance = 0.0f;

    if(GetTypeId() == TYPEID_PLAYER)
    {
        Player const* player = (Player const*)this;
        if(player->CanParry() )
        {
            Item *tmpitem = player->GetWeaponForAttack(BASE_ATTACK,true);
            if(!tmpitem)
                tmpitem = player->GetWeaponForAttack(OFF_ATTACK,true);

            if(tmpitem)
                chance = GetFloatValue(PLAYER_PARRY_PERCENTAGE);
        }
    }
    else if(GetTypeId() == TYPEID_UNIT)
    {
        if(GetCreatureType() == CREATURE_TYPE_HUMANOID)
        {
            chance = 5.0f;
            chance += GetTotalAuraModifier(SPELL_AURA_MOD_PARRY_PERCENT);
        }
    }

    return chance > 0.0f ? chance : 0.0f;
}

float Unit::GetUnitBlockChance() const
{
    if ( IsNonMeleeSpellCasted(false) || hasUnitState(UNIT_STAT_STUNNED))
        return 0.0f;

    if(GetTypeId() == TYPEID_PLAYER)
    {
        Player const* player = (Player const*)this;
        if(player->CanBlock() )
        {
            Item *tmpitem = player->GetUseableItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND);
            if(tmpitem && !tmpitem->IsBroken() && tmpitem->GetProto()->Block)
                return GetFloatValue(PLAYER_BLOCK_PERCENTAGE);
        }
        // is player but has no block ability or no not broken shield equipped
        return 0.0f;
    }
    else
    {
        if(((Creature const*)this)->isTotem())
            return 0.0f;
        else
        {
            float block = 5.0f;
            block += GetTotalAuraModifier(SPELL_AURA_MOD_BLOCK_PERCENT);
            return block > 0.0f ? block : 0.0f;
        }
    }
}

float Unit::GetUnitCriticalChance(WeaponAttackType attackType, const Unit *pVictim) const
{
    float crit;

    if(GetTypeId() == TYPEID_PLAYER)
    {
        switch(attackType)
        {
            case BASE_ATTACK:
                crit = GetFloatValue( PLAYER_CRIT_PERCENTAGE );
                break;
            case OFF_ATTACK:
                crit = GetFloatValue( PLAYER_OFFHAND_CRIT_PERCENTAGE );
                break;
            case RANGED_ATTACK:
                crit = GetFloatValue( PLAYER_RANGED_CRIT_PERCENTAGE );
                break;
                // Just for good manner
            default:
                crit = 0.0f;
                break;
        }
    }
    else
    {
        crit = 5.0f;
        crit += GetTotalAuraModifier(SPELL_AURA_MOD_CRIT_PERCENT);
    }

    // flat aura mods
    if(attackType == RANGED_ATTACK)
        crit += pVictim->GetTotalAuraModifier(SPELL_AURA_MOD_ATTACKER_RANGED_CRIT_CHANCE);
    else
        crit += pVictim->GetTotalAuraModifier(SPELL_AURA_MOD_ATTACKER_MELEE_CRIT_CHANCE);

    crit += pVictim->GetTotalAuraModifier(SPELL_AURA_MOD_ATTACKER_SPELL_AND_WEAPON_CRIT_CHANCE);

    // reduce crit chance from Rating for players
    if (pVictim->GetTypeId()==TYPEID_PLAYER)
    {
        if (attackType==RANGED_ATTACK)
            crit -= ((Player*)pVictim)->GetRatingBonusValue(CR_CRIT_TAKEN_RANGED);
        else
            crit -= ((Player*)pVictim)->GetRatingBonusValue(CR_CRIT_TAKEN_MELEE);
    }

    // Apply crit chance from defence skill
    crit += (int32(GetMaxSkillValueForLevel(pVictim)) - int32(pVictim->GetDefenseSkillValue(this))) * 0.04f;

    if (crit < 0.0f)
        crit = 0.0f;
    return crit;
}

uint32 Unit::GetWeaponSkillValue (WeaponAttackType attType, Unit const* target) const
{
    uint32 value = 0;
    if(GetTypeId() == TYPEID_PLAYER)
    {
        Item* item = ((Player*)this)->GetWeaponForAttack(attType,true);

        // feral or unarmed skill only for base attack
        if(attType != BASE_ATTACK && !item )
        {
            if(attType == RANGED_ATTACK && getClass() == CLASS_PALADIN) //hammer
                return GetMaxSkillValueForLevel();
            return 0;
        }

        if(IsInFeralForm())
            return GetMaxSkillValueForLevel();              // always maximized SKILL_FERAL_COMBAT in fact

        // weapon skill or (unarmed for base attack)
        uint32  skill = item ? item->GetSkill() : SKILL_UNARMED;

        // in PvP use full skill instead current skill value
        value = (target && target->GetTypeId() == TYPEID_PLAYER)
            ? ((Player*)this)->GetMaxSkillValue(skill)
            : ((Player*)this)->GetSkillValue(skill);
        // Modify value from ratings
        value += uint32(((Player*)this)->GetRatingBonusValue(CR_WEAPON_SKILL));
        switch (attType)
        {
            case BASE_ATTACK:   value+=uint32(((Player*)this)->GetRatingBonusValue(CR_WEAPON_SKILL_MAINHAND));break;
            case OFF_ATTACK:    value+=uint32(((Player*)this)->GetRatingBonusValue(CR_WEAPON_SKILL_OFFHAND));break;
            case RANGED_ATTACK: value+=uint32(((Player*)this)->GetRatingBonusValue(CR_WEAPON_SKILL_RANGED));break;
        }
    }
    else
        value = GetUnitMeleeSkill(target);
   return value;
}

void Unit::_DeleteAuras()
{
    for (AuraList::iterator i = m_removedAuras.begin(); i != m_removedAuras.end();i = m_removedAuras.begin())
    {
        Aura * Aur = *i;
        sLog.outDebug("Aura %d is deleted from unit %d", Aur->GetId(), GetGUIDLow());
        m_removedAuras.pop_front();
        delete (Aur);
    }
}

void Unit::_UpdateSpells( uint32 time )
{
    if(m_currentSpells[CURRENT_AUTOREPEAT_SPELL])
        _UpdateAutoRepeatSpell();

    // remove finished spells from current pointers
    for (uint32 i = 0; i < CURRENT_MAX_SPELL; i++)
    {
        if (m_currentSpells[i] && m_currentSpells[i]->getState() == SPELL_STATE_FINISHED)
        {
            m_currentSpells[i]->SetReferencedFromCurrent(false);
            m_currentSpells[i] = NULL;                      // remove pointer
        }
    }

    // TODO: Find a better way to prevent crash when multiple auras are removed.
    for (AuraMap::iterator i = m_Auras.begin(); i != m_Auras.end(); ++i)
        i->second->SetUpdated(false);

    for(AuraMap::iterator i = m_Auras.begin(); i != m_Auras.end();)
    {
        Aura *aur = i->second;

        // prevent double update
        if(aur->IsUpdated())
        {
            ++i;
            continue;
        }

        aur->SetUpdated(true);

        m_removedAurasCount = 0;
        aur->Update( time );

        // several auras can be deleted due to update
        if(m_removedAurasCount)
        {
            m_removedAurasCount = 0;
            i = m_Auras.begin();
        }
        else
            ++i;
    }

    for(AuraMap::iterator i = m_Auras.begin(); i != m_Auras.end();)
    {
        if(i->second->IsExpired())
            RemoveAura(i, AURA_REMOVE_BY_EXPIRE);
        else
            ++i;
    }

    _DeleteAuras();

    if(!m_gameObj.empty())
    {
        GameObjectList::iterator ite1, dnext1;
        for (ite1 = m_gameObj.begin(); ite1 != m_gameObj.end(); ite1 = dnext1)
        {
            dnext1 = ite1;
            //(*i)->Update( difftime );
            if( !(*ite1)->isSpawned() )
            {
                (*ite1)->SetOwnerGUID(0);
                (*ite1)->SetRespawnTime(0);
                (*ite1)->Delete();
                dnext1 = m_gameObj.erase(ite1);
            }
            else
                ++dnext1;
        }
    }
}

void Unit::_UpdateAutoRepeatSpell()
{
    //check "realtime" interrupts
    if ( (GetTypeId() == TYPEID_PLAYER && ((Player*)this)->isMoving()) || IsNonMeleeSpellCasted(false,false,true) )
    {
        // cancel wand shoot
        if(m_currentSpells[CURRENT_AUTOREPEAT_SPELL]->m_spellInfo->Id != SPELL_ID_AUTOSHOT)
            InterruptSpell(CURRENT_AUTOREPEAT_SPELL);
        m_AutoRepeatFirstCast = true;
        return;
    }

    //apply delay
    if ( m_AutoRepeatFirstCast && getAttackTimer(RANGED_ATTACK) < 500 )
        setAttackTimer(RANGED_ATTACK,500);
    m_AutoRepeatFirstCast = false;

    //castroutine
    if (isAttackReady(RANGED_ATTACK))
    {
        // Check if able to cast
        if(m_currentSpells[CURRENT_AUTOREPEAT_SPELL]->CheckCast(true) != SPELL_CAST_OK)
        {
            InterruptSpell(CURRENT_AUTOREPEAT_SPELL);
            return;
        }

        // we want to shoot
        Spell* spell = new Spell(this, m_currentSpells[CURRENT_AUTOREPEAT_SPELL]->m_spellInfo, true, 0);
        spell->prepare(&(m_currentSpells[CURRENT_AUTOREPEAT_SPELL]->m_targets));

        // all went good, reset attack
        resetAttackTimer(RANGED_ATTACK);
    }
}

void Unit::SetCurrentCastedSpell( Spell * pSpell )
{
    assert(pSpell);                                         // NULL may be never passed here, use InterruptSpell or InterruptNonMeleeSpells

    CurrentSpellTypes CSpellType = pSpell->GetCurrentContainer();

    if (pSpell == m_currentSpells[CSpellType]) return;      // avoid breaking self

    // break same type spell if it is not delayed
    InterruptSpell(CSpellType,false);

    // special breakage effects:
    switch (CSpellType)
    {
        case CURRENT_GENERIC_SPELL:
        {
            // generic spells always break channeled not delayed spells
            InterruptSpell(CURRENT_CHANNELED_SPELL,false);

            // autorepeat breaking
            if ( m_currentSpells[CURRENT_AUTOREPEAT_SPELL] )
            {
                // break autorepeat if not Auto Shot
                if (m_currentSpells[CURRENT_AUTOREPEAT_SPELL]->m_spellInfo->Id != SPELL_ID_AUTOSHOT)
                    InterruptSpell(CURRENT_AUTOREPEAT_SPELL);
                m_AutoRepeatFirstCast = true;
            }
            addUnitState(UNIT_STAT_CASTING);
        } break;

        case CURRENT_CHANNELED_SPELL:
        {
            // channel spells always break generic non-delayed and any channeled spells
            InterruptSpell(CURRENT_GENERIC_SPELL,false);
            InterruptSpell(CURRENT_CHANNELED_SPELL);

            // it also does break autorepeat if not Auto Shot
            if ( m_currentSpells[CURRENT_AUTOREPEAT_SPELL] &&
                m_currentSpells[CURRENT_AUTOREPEAT_SPELL]->m_spellInfo->Id != SPELL_ID_AUTOSHOT )
                InterruptSpell(CURRENT_AUTOREPEAT_SPELL);
            addUnitState(UNIT_STAT_CASTING);
        } break;

        case CURRENT_AUTOREPEAT_SPELL:
        {
            // only Auto Shoot does not break anything
            if (pSpell->m_spellInfo->Id != SPELL_ID_AUTOSHOT)
            {
                // generic autorepeats break generic non-delayed and channeled non-delayed spells
                InterruptSpell(CURRENT_GENERIC_SPELL,false);
                InterruptSpell(CURRENT_CHANNELED_SPELL,false);
            }
            // special action: set first cast flag
            m_AutoRepeatFirstCast = true;
        } break;

        default:
        {
            // other spell types don't break anything now
        } break;
    }

    // current spell (if it is still here) may be safely deleted now
    if (m_currentSpells[CSpellType])
        m_currentSpells[CSpellType]->SetReferencedFromCurrent(false);

    // set new current spell
    m_currentSpells[CSpellType] = pSpell;
    pSpell->SetReferencedFromCurrent(true);
}

void Unit::InterruptSpell(uint32 spellType, bool withDelayed, bool withInstant)
{
    assert(spellType < CURRENT_MAX_SPELL);

    Spell *spell = m_currentSpells[spellType];
    if(spell
        && (withDelayed || spell->getState() != SPELL_STATE_DELAYED)
        && (withInstant || spell->GetCastTime() > 0))
    {
        // for example, do not let self-stun aura interrupt itself
        if(!spell->IsInterruptable())
            return;

        m_currentSpells[spellType] = NULL;

        // send autorepeat cancel message for autorepeat spells
        if (spellType == CURRENT_AUTOREPEAT_SPELL)
        {
            if(GetTypeId()==TYPEID_PLAYER)
                ((Player*)this)->SendAutoRepeatCancel();
        }

        if (spell->getState() != SPELL_STATE_FINISHED)
            spell->cancel();
        spell->SetReferencedFromCurrent(false);
    }
}

bool Unit::IsNonMeleeSpellCasted(bool withDelayed, bool skipChanneled, bool skipAutorepeat) const
{
    // We don't do loop here to explicitly show that melee spell is excluded.
    // Maybe later some special spells will be excluded too.

    // generic spells are casted when they are not finished and not delayed
    if ( m_currentSpells[CURRENT_GENERIC_SPELL] &&
        (m_currentSpells[CURRENT_GENERIC_SPELL]->getState() != SPELL_STATE_FINISHED) &&
        (withDelayed || m_currentSpells[CURRENT_GENERIC_SPELL]->getState() != SPELL_STATE_DELAYED) )
        return(true);

    // channeled spells may be delayed, but they are still considered casted
    else if ( !skipChanneled && m_currentSpells[CURRENT_CHANNELED_SPELL] &&
        (m_currentSpells[CURRENT_CHANNELED_SPELL]->getState() != SPELL_STATE_FINISHED) )
        return(true);

    // autorepeat spells may be finished or delayed, but they are still considered casted
    else if ( !skipAutorepeat && m_currentSpells[CURRENT_AUTOREPEAT_SPELL] )
        return(true);

    return(false);
}

void Unit::InterruptNonMeleeSpells(bool withDelayed, uint32 spell_id, bool withInstant)
{
    // generic spells are interrupted if they are not finished or delayed
    if (m_currentSpells[CURRENT_GENERIC_SPELL] && (!spell_id || m_currentSpells[CURRENT_GENERIC_SPELL]->m_spellInfo->Id==spell_id))
        InterruptSpell(CURRENT_GENERIC_SPELL,withDelayed,withInstant);

    // autorepeat spells are interrupted if they are not finished or delayed
    if (m_currentSpells[CURRENT_AUTOREPEAT_SPELL] && (!spell_id || m_currentSpells[CURRENT_AUTOREPEAT_SPELL]->m_spellInfo->Id==spell_id))
        InterruptSpell(CURRENT_AUTOREPEAT_SPELL,withDelayed,withInstant);

    // channeled spells are interrupted if they are not finished, even if they are delayed
    if (m_currentSpells[CURRENT_CHANNELED_SPELL] && (!spell_id || m_currentSpells[CURRENT_CHANNELED_SPELL]->m_spellInfo->Id==spell_id))
        InterruptSpell(CURRENT_CHANNELED_SPELL,true,true);
}

Spell* Unit::FindCurrentSpellBySpellId(uint32 spell_id) const
{
    for (uint32 i = 0; i < CURRENT_MAX_SPELL; i++)
        if(m_currentSpells[i] && m_currentSpells[i]->m_spellInfo->Id==spell_id)
            return m_currentSpells[i];
    return NULL;
}

bool Unit::isInFront(Unit const* target, float distance,  float arc) const
{
    return IsWithinDistInMap(target, distance) && HasInArc( arc, target );
}

void Unit::SetInFront(Unit const* target)
{
    SetOrientation(GetAngle(target));
}

bool Unit::isInBack(Unit const* target, float distance, float arc) const
{
    return IsWithinDistInMap(target, distance) && !HasInArc( 2 * M_PI - arc, target );
}

bool Unit::isInLine(Unit const* target, float distance) const
{
    if(!HasInArc(M_PI, target) || !IsWithinDistInMap(target, distance)) return false;
    float width = GetObjectSize() + target->GetObjectSize() * 0.5f;
    float angle = GetAngle(target) - GetOrientation();
    return abs(sin(angle)) * GetExactDistance2d(target->GetPositionX(), target->GetPositionY()) < width;
}

bool Unit::isInAccessiblePlaceFor(Creature const* c) const
{
    if(IsInWater())
        return c->canSwim();
    else
        return c->canWalk() || c->canFly();
}

bool Unit::IsInWater() const
{
    return MapManager::Instance().GetBaseMap(GetMapId())->IsInWater(GetPositionX(),GetPositionY(), GetPositionZ());
}

bool Unit::IsUnderWater() const
{
    return MapManager::Instance().GetBaseMap(GetMapId())->IsUnderWater(GetPositionX(),GetPositionY(),GetPositionZ());
}

void Unit::DeMorph()
{
    SetDisplayId(GetNativeDisplayId());
}

int32 Unit::GetTotalAuraModifier(AuraType auratype) const
{
    int32 modifier = 0;

    AuraEffectList const& mTotalAuraList = GetAurasByType(auratype);
    for(AuraEffectList::const_iterator i = mTotalAuraList.begin();i != mTotalAuraList.end(); ++i)
        modifier += (*i)->GetAmount();

    return modifier;
}

float Unit::GetTotalAuraMultiplier(AuraType auratype) const
{
    float multiplier = 1.0f;

    AuraEffectList const& mTotalAuraList = GetAurasByType(auratype);
    for(AuraEffectList::const_iterator i = mTotalAuraList.begin();i != mTotalAuraList.end(); ++i)
        multiplier *= (100.0f + (*i)->GetAmount())/100.0f;

    return multiplier;
}

int32 Unit::GetMaxPositiveAuraModifier(AuraType auratype)
{
    int32 modifier = 0;

    AuraEffectList const& mTotalAuraList = GetAurasByType(auratype);
    for(AuraEffectList::const_iterator i = mTotalAuraList.begin();i != mTotalAuraList.end(); ++i)
    {
        if ((*i)->GetAmount() > modifier)
            modifier = (*i)->GetAmount();
    }

    return modifier;
}

int32 Unit::GetMaxNegativeAuraModifier(AuraType auratype) const
{
    int32 modifier = 0;

    AuraEffectList const& mTotalAuraList = GetAurasByType(auratype);
    for(AuraEffectList::const_iterator i = mTotalAuraList.begin();i != mTotalAuraList.end(); ++i)
        if ((*i)->GetAmount() < modifier)
            modifier = (*i)->GetAmount();

    return modifier;
}

int32 Unit::GetTotalAuraModifierByMiscMask(AuraType auratype, uint32 misc_mask) const
{
    int32 modifier = 0;

    AuraEffectList const& mTotalAuraList = GetAurasByType(auratype);
    for(AuraEffectList::const_iterator i = mTotalAuraList.begin();i != mTotalAuraList.end(); ++i)
    {
        if ((*i)->GetMiscValue()& misc_mask)
            modifier += (*i)->GetAmount();
    }
    return modifier;
}

float Unit::GetTotalAuraMultiplierByMiscMask(AuraType auratype, uint32 misc_mask) const
{
    float multiplier = 1.0f;

    AuraEffectList const& mTotalAuraList = GetAurasByType(auratype);
    for(AuraEffectList::const_iterator i = mTotalAuraList.begin();i != mTotalAuraList.end(); ++i)
    {
        if ((*i)->GetMiscValue()& misc_mask)
            multiplier *= (100.0f + (*i)->GetAmount())/100.0f;
    }
    return multiplier;
}

int32 Unit::GetMaxPositiveAuraModifierByMiscMask(AuraType auratype, uint32 misc_mask) const
{
    int32 modifier = 0;

    AuraEffectList const& mTotalAuraList = GetAurasByType(auratype);
    for(AuraEffectList::const_iterator i = mTotalAuraList.begin();i != mTotalAuraList.end(); ++i)
    {
        if ((*i)->GetMiscValue()& misc_mask && (*i)->GetAmount() > modifier)
            modifier = (*i)->GetAmount();
    }

    return modifier;
}

int32 Unit::GetMaxNegativeAuraModifierByMiscMask(AuraType auratype, uint32 misc_mask) const
{
    int32 modifier = 0;

    AuraEffectList const& mTotalAuraList = GetAurasByType(auratype);
    for(AuraEffectList::const_iterator i = mTotalAuraList.begin();i != mTotalAuraList.end(); ++i)
    {
        if ((*i)->GetMiscValue()& misc_mask && (*i)->GetAmount() < modifier)
            modifier = (*i)->GetAmount();
    }

    return modifier;
}

int32 Unit::GetTotalAuraModifierByMiscValue(AuraType auratype, int32 misc_value) const
{
    int32 modifier = 0;

    AuraEffectList const& mTotalAuraList = GetAurasByType(auratype);
    for(AuraEffectList::const_iterator i = mTotalAuraList.begin();i != mTotalAuraList.end(); ++i)
    {
        if ((*i)->GetMiscValue()== misc_value)
            modifier += (*i)->GetAmount();
    }
    return modifier;
}

float Unit::GetTotalAuraMultiplierByMiscValue(AuraType auratype, int32 misc_value) const
{
    float multiplier = 1.0f;

    AuraEffectList const& mTotalAuraList = GetAurasByType(auratype);
    for(AuraEffectList::const_iterator i = mTotalAuraList.begin();i != mTotalAuraList.end(); ++i)
    {
        if ((*i)->GetMiscValue()== misc_value)
            multiplier *= (100.0f + (*i)->GetAmount())/100.0f;
    }
    return multiplier;
}

int32 Unit::GetMaxPositiveAuraModifierByMiscValue(AuraType auratype, int32 misc_value) const
{
    int32 modifier = 0;

    AuraEffectList const& mTotalAuraList = GetAurasByType(auratype);
    for(AuraEffectList::const_iterator i = mTotalAuraList.begin();i != mTotalAuraList.end(); ++i)
    {
        if ((*i)->GetMiscValue()== misc_value && (*i)->GetAmount() > modifier)
            modifier = (*i)->GetAmount();
    }

    return modifier;
}

int32 Unit::GetMaxNegativeAuraModifierByMiscValue(AuraType auratype, int32 misc_value) const
{
    int32 modifier = 0;

    AuraEffectList const& mTotalAuraList = GetAurasByType(auratype);
    for(AuraEffectList::const_iterator i = mTotalAuraList.begin();i != mTotalAuraList.end(); ++i)
    {
        if ((*i)->GetMiscValue()== misc_value && (*i)->GetAmount() < modifier)
            modifier = (*i)->GetAmount();
    }

    return modifier;
}

bool Unit::AddAura(Aura *Aur, bool handleEffects)
{
    // aura doesn't apply effects-return
    if (!Aur->GetEffectMask() || Aur->IsExpired())
    {
        delete Aur;
        return false;
    }

    // ghost spell check, allow apply any auras at player loading in ghost mode (will be cleanup after load)
    if( !isAlive() && Aur->GetId() != 20584 && Aur->GetId() != 8326 && Aur->GetId() != 2584 &&
        (GetTypeId()!=TYPEID_PLAYER || !((Player*)this)->GetSession()->PlayerLoading()) )
    {
        delete Aur;
        return false;
    }

    if(Aur->GetTarget() != this)
    {
        sLog.outError("Aura (spell %u) add to aura list of %s (lowguid: %u) but Aura target is %s (lowguid: %u)",
            Aur->GetId(),(GetTypeId()==TYPEID_PLAYER?"player":"creature"),GetGUIDLow(),
            (Aur->GetTarget()->GetTypeId()==TYPEID_PLAYER?"player":"creature"),Aur->GetTarget()->GetGUIDLow());
        delete Aur;
        return false;
    }

    SpellEntry const* aurSpellInfo = Aur->GetSpellProto();

    // passive and persistent auras can stack with themselves any number of times
    if (!Aur->IsPassive() && !Aur->IsPersistent() && aurSpellInfo->StackAmount>1)
    {
        // find current aura from spell and change it's stackamount
        if (Aura * foundAura = GetAura(aurSpellInfo->Id,Aur->GetCasterGUID()))
        {
            if(foundAura->GetStackAmount() < aurSpellInfo->StackAmount)
                foundAura->SetStackAmount(foundAura->GetStackAmount()+1);
            else
                foundAura->RefreshAura();
            delete Aur;
            return false;
        }
    }

    // passive auras not stacable with other ranks
    if (!RemoveNoStackAurasDueToAura(Aur))
    {
        delete Aur;
        return false;                                   // couldn't remove conflicting aura with higher rank
    }

    // update single target auras list (before aura add to aura list, to prevent unexpected remove recently added aura)
    if (Aur->IsSingleTarget() && Aur->GetTarget())
    {
        // caster pointer can be deleted in time aura remove, find it by guid at each iteration
        for(;;)
        {
            Unit* caster = Aur->GetCaster();
            if(!caster)                                     // caster deleted and not required adding scAura
                break;

            bool restart = false;
            AuraList& scAuras = caster->GetSingleCastAuras();
            for(AuraList::iterator itr = scAuras.begin(); itr != scAuras.end(); ++itr)
            {
                if( (*itr)->GetTarget() != Aur->GetTarget() &&
                    IsSingleTargetSpells((*itr)->GetSpellProto(),aurSpellInfo) )
                {
                    (*itr)->GetTarget()->RemoveAurasDueToSpell((*itr)->GetId(), caster->GetGUID(), AURA_REMOVE_BY_STACK);
                    restart = true;
                    break;
                }
            }

            if(!restart)
            {
                // done
                scAuras.push_back(Aur);
                break;
            }
        }
    }

    // add aura, register in lists and arrays
    Aur->_AddAura();
    m_Auras.insert(AuraMap::value_type(Aur->GetId(), Aur));

    if(Aur->GetSpellProto()->AuraInterruptFlags)
    {
        m_interruptableAuras.push_back(Aur);
        AddInterruptMask(Aur->GetSpellProto()->AuraInterruptFlags);
    }
    if((Aur->GetSpellProto()->Attributes & SPELL_ATTR_BREAKABLE_BY_DAMAGE
        && !Aur->IsAuraType(SPELL_AURA_MOD_POSSESS)) //only dummy aura is breakable
        || ((GetAllSpellMechanicMask(Aur->GetSpellProto()) & 1<<MECHANIC_KNOCKOUT) && Aur->IsAuraType(SPELL_AURA_MOD_STUN)))
    {
        m_ccAuras.push_back(Aur);
    }

    if (handleEffects)
        Aur->HandleEffects(true);

    sLog.outDebug("Aura %u now is in use", Aur->GetId());
    return true;
}

bool Unit::RemoveNoStackAurasDueToAura(Aura *Aur)
{
    if (!Aur)
        return false;

    SpellEntry const* spellProto = Aur->GetSpellProto();

    uint32 spellId = Aur->GetId();

    // passive spell special case (only non stackable with ranks)
    if(IsPassiveSpell(spellId))
    {
        if(IsPassiveSpellStackableWithRanks(spellProto))
            return true;
    }

    SpellSpecific spellId_spec = GetSpellSpecific(spellId);

    //bool linked = spellmgr.GetSpellCustomAttr(spellId) & SPELL_ATTR_CU_LINK_AURA? true : false;

    AuraMap::iterator i,next;
    for (i = m_Auras.begin(); i != m_Auras.end(); i = next)
    {
        next = i;
        ++next;

        SpellEntry const* i_spellProto = (*i).second->GetSpellProto();

        uint32 i_spellId = i_spellProto->Id;

        if(IsPassiveSpell(i_spellId))
        {
            // passive non-stackable spells not stackable only for same caster
            if(Aur->GetCasterGUID()!=i->second->GetCasterGUID())
                continue;

            // passive non-stackable spells not stackable only with another rank of same spell
            if (!spellmgr.IsRankSpellDueToSpell(spellProto, i_spellId))
                continue;
        }

        bool is_triggered_by_spell = false;
        // prevent triggered aura of removing aura that triggered it
        for(int j = 0; j < 3; ++j)
            if (i_spellProto->EffectTriggerSpell[j] == spellProto->Id)
                is_triggered_by_spell = true;

        // check if they can stack
        bool sameCaster = Aur->GetCasterGUID() == (*i).second->GetCasterGUID();

        /*// Dont remove by stack with linked auras
        // Not needed for now
        if(sameCaster && linked)
        {
            if(const std::vector<int32> *spell_triggered = spellmgr.GetSpellLinked(spellId + SPELL_LINK_AURA))
                for(std::vector<int32>::const_iterator itr = spell_triggered->begin(); itr != spell_triggered->end(); ++itr)
                    if(*itr>0 && *itr==i_spellId)
                    {
                        is_triggered_by_spell=true;
                        break;
                    }
        }*/

        if (is_triggered_by_spell)
            continue;

        if(!spellmgr.IsNoStackSpellDueToSpell(spellId, i_spellId, sameCaster))
            continue;

        //some spells should be not removed by lower rank of them (totem, paladin aura)
        if (!sameCaster
            &&(Aur->IsAreaAura())
            &&(spellProto->DurationIndex==21)
            &&(spellmgr.IsRankSpellDueToSpell(spellProto, i_spellId))
            &&(IsHigherHankOfSpell(spellId,i_spellId)))
            return false;

        // Remove all auras by aura caster
        RemoveAura(i, AURA_REMOVE_BY_STACK);
        next=i;
    }
    return true;
}

void Unit::RemoveAura(uint32 spellId, uint64 caster ,AuraRemoveMode removeMode)
{
    for(AuraMap::iterator iter = m_Auras.lower_bound(spellId); iter != m_Auras.upper_bound(spellId);)
    {
        if (!caster || iter->second->GetCasterGUID()==caster)
        {
            RemoveAura(iter, removeMode);
            return;
        }
        else
            ++iter;
    }
}

void Unit::RemoveAura(Aura * aur ,AuraRemoveMode mode)
{
    // no need to remove
    if (!aur || aur->IsRemoved())
        return;
    for(AuraMap::iterator iter = m_Auras.lower_bound(aur->GetId()); iter != m_Auras.upper_bound(aur->GetId());)
    {
        if (aur == iter->second)
        {
            RemoveAura(iter, mode);
            return;
        }
        else
            ++iter;
    }
}

void Unit::RemoveAurasDueToSpell(uint32 spellId, uint64 caster ,AuraRemoveMode removeMode)
{
    for(AuraMap::iterator iter = m_Auras.lower_bound(spellId); iter != m_Auras.upper_bound(spellId);)
    {
        if (!caster || iter->second->GetCasterGUID()==caster)
        {
            RemoveAura(iter, removeMode);
            iter = m_Auras.lower_bound(spellId);
        }
        else
            ++iter;
    }
}

void Unit::RemoveAuraFromStack(uint32 spellId, uint64 caster ,AuraRemoveMode removeMode)
{
    for(AuraMap::iterator iter = m_Auras.lower_bound(spellId); iter != m_Auras.upper_bound(spellId);)
    {
        if (!caster || iter->second->GetCasterGUID()==caster)
        {
            RemoveAuraFromStack(iter, removeMode);
            return;
        }
        else
            ++iter;
    }
}

inline void Unit::RemoveAuraFromStack(AuraMap::iterator &iter,AuraRemoveMode removeMode)
{
    if (iter->second->modStackAmount(-1))
        RemoveAura(iter, removeMode);
}

void Unit::RemoveAurasDueToSpellByDispel(uint32 spellId, uint64 casterGUID, Unit *dispeler)
{
    for(AuraMap::iterator iter = m_Auras.lower_bound(spellId); iter != m_Auras.upper_bound(spellId);)
    {
        Aura * aur= iter->second;
        if (casterGUID == aur->GetCasterGUID())
        {
            // Unstable Affliction
            if (aur->GetSpellProto()->SpellFamilyName == SPELLFAMILY_WARLOCK && (aur->GetSpellProto()->SpellFamilyFlags[1] & 0x0100))
            {
                int32 damage = aur->GetPartAura(0)->GetAmount()*9;
                RemoveAuraFromStack(iter, AURA_REMOVE_BY_ENEMY_SPELL);
                // backfire damage and silence
                dispeler->CastCustomSpell(dispeler, 31117, &damage, NULL, NULL, true, NULL, NULL,GetGUID());
                return;
            }
            RemoveAuraFromStack(iter, AURA_REMOVE_BY_ENEMY_SPELL);
            return;
        }
        else
            ++iter;
    }
}

void Unit::RemoveAurasDueToSpellBySteal(uint32 spellId, uint64 casterGUID, Unit *stealer)
{
    if (casterGUID == stealer->GetGUID())
        return;

    for(AuraMap::iterator iter = m_Auras.lower_bound(spellId); iter != m_Auras.upper_bound(spellId);)
    {
        Aura * aur= iter->second;
        if (casterGUID == aur->GetCasterGUID())
        {
            int32 damage[3];
            for (uint8 i=0;i<3;++i)
            {
                if (aur->GetPartAura(i))
                    damage[i]=aur->GetPartAura(i)->GetAmount();
                else
                    damage[i]=NULL;
            }
            int32 dur = 2*MINUTE*IN_MILISECONDS < aur->GetAuraDuration() ? 2*MINUTE*IN_MILISECONDS : aur->GetAuraDuration();
            Aura * new_aur = new Aura(aur->GetSpellProto(),aur->GetEffectMask(), NULL, stealer, stealer, NULL);
            new_aur->SetLoadedState(aur->GetCasterGUID(), dur, dur, aur->GetAuraCharges(), aur->GetStackAmount(), &damage[0]);

            // Unregister _before_ adding to stealer
            aur->UnregisterSingleCastAura();
            // strange but intended behaviour: Stolen single target auras won't be treated as single targeted
            new_aur->SetIsSingleTarget(false);
            stealer->AddAura(new_aur);
            RemoveAuraFromStack(iter, AURA_REMOVE_BY_ENEMY_SPELL);
            return;
        }
        else
            ++iter;
    }
}

void Unit::RemoveAurasDueToItemSpell(Item* castItem,uint32 spellId)
{
    for (AuraMap::iterator iter = m_Auras.lower_bound(spellId); iter != m_Auras.upper_bound(spellId);)
    {
        if (!castItem || iter->second->GetCastItemGUID()==castItem->GetGUID())
        {
            RemoveAura(iter);
            iter = m_Auras.upper_bound(spellId);          // overwrite by more appropriate
        }
        else
            ++iter;
    }
}

void Unit::RemoveAurasByType(AuraType auraType, uint64 casterGUID, Aura * except)
{
    if (auraType >= TOTAL_AURAS) return;
    for (AuraEffectList::iterator iter = m_modAuras[auraType].begin(); iter != m_modAuras[auraType].end();)
    {
        Aura * aur = (*iter)->GetParentAura();
        ++iter;
        if (aur != except && (!casterGUID || aur->GetCasterGUID()==casterGUID))
        {
            uint32 removedAuras = m_removedAurasCount;
            RemoveAura(aur);
            if (removedAuras+1< m_removedAurasCount)
                iter=m_modAuras[auraType].begin();
        }
    }
}

void Unit::RemoveAurasByTypeWithDispel(AuraType auraType, Spell * spell)
{
    if (auraType >= TOTAL_AURAS) return;
    std::queue < std::pair < uint32, uint64 > > remove_list;

    for (AuraEffectList::iterator iter = m_modAuras[auraType].begin(); iter != m_modAuras[auraType].end();++iter)
    {
       if(GetDispelChance((*iter)->GetCaster(), (*iter)->GetId()))
       {
           remove_list.push(std::make_pair((*iter)->GetId(), (*iter)->GetCasterGUID() ) );
       }
    }

    for(;remove_list.size();remove_list.pop())
    {
        RemoveAura(remove_list.front().first, remove_list.front().second, AURA_REMOVE_BY_ENEMY_SPELL);
    }
}

void Unit::RemoveNotOwnSingleTargetAuras()
{
    // single target auras from other casters
    for (AuraMap::iterator iter = m_Auras.begin(); iter != m_Auras.end(); )
    {
        if (iter->second->GetCasterGUID()!=GetGUID() && IsSingleTargetSpell(iter->second->GetSpellProto()))
            RemoveAura(iter);
        else
            ++iter;
    }

    // single target auras at other targets
    AuraList& scAuras = GetSingleCastAuras();
    for (AuraList::iterator iter = scAuras.begin(); iter != scAuras.end();)
    {
        Aura * aur=*iter;
        ++iter;
        if (aur->GetTarget()!=this)
        {
            uint32 removedAuras = m_removedAurasCount;
            aur->GetTarget()->RemoveAura(aur->GetId(),aur->GetCasterGUID());
            if (removedAuras+1<m_removedAurasCount)
                iter=scAuras.begin();
        }
    }
}

void Unit::RemoveAura(AuraMap::iterator &i, AuraRemoveMode mode)
{
    Aura* Aur = i->second;

    // some ShapeshiftBoosts at remove trigger removing other auras including parent Shapeshift aura
    // remove aura from list before to prevent deleting it before
    m_Auras.erase(i);
    m_removedAurasCount += 1;

    Aur->UnregisterSingleCastAura();

    if(Aur->GetSpellProto()->AuraInterruptFlags)
    {
        m_interruptableAuras.remove(Aur);
        UpdateInterruptMask();
    }

    if((Aur->GetSpellProto()->Attributes & SPELL_ATTR_BREAKABLE_BY_DAMAGE
        && !Aur->IsAuraType(SPELL_AURA_MOD_POSSESS)) //only dummy aura is breakable
        || ((GetAllSpellMechanicMask(Aur->GetSpellProto()) & 1<<MECHANIC_KNOCKOUT) && Aur->IsAuraType(SPELL_AURA_MOD_STUN)))
    {
        m_ccAuras.remove(Aur);
    }

    Aur->SetRemoveMode(mode);

    sLog.outDebug("Aura %u now is remove mode %d", Aur->GetId(), mode);
    Aur->HandleEffects(false);

    // set aura to be removed during unit::_updatespells
    m_removedAuras.push_back(Aur);

    Aur->_RemoveAura();

    // Remove totem at next update if totem looses its aura
    if (GetTypeId()==TYPEID_UNIT && ((Creature*)this)->isTotem()&& ((TempSummon*)this)->GetSummonerGUID()==Aur->GetCasterGUID())
    {
        if (((Totem*)this)->GetSpell()==Aur->GetId())
            ((Totem*)this)->setDeathState(JUST_DIED);
    }

    // only way correctly remove all auras from list
    i = m_Auras.begin();
}

void Unit::RemoveAllAuras()
{
    AuraMap::iterator iter = m_Auras.begin();
    while (!m_Auras.empty())
        RemoveAura(iter);
}

void Unit::RemoveArenaAuras(bool onleave)
{
    // in join, remove positive buffs, on end, remove negative
    // used to remove positive visible auras in arenas
    for(AuraMap::iterator iter = m_Auras.begin(); iter != m_Auras.end();)
    {
        if ( !(iter->second->GetSpellProto()->AttributesEx4 & (1<<21)) // don't remove stances, shadowform, pally/hunter auras
            && !iter->second->IsPassive()                               // don't remove passive auras
            && (!(iter->second->GetSpellProto()->Attributes & SPELL_ATTR_UNAFFECTED_BY_INVULNERABILITY) || !(iter->second->GetSpellProto()->Attributes & SPELL_ATTR_UNK8))   // not unaffected by invulnerability auras or not having that unknown flag (that seemed the most probable)
            && (iter->second->IsPositive() ^ onleave))                   // remove positive buffs on enter, negative buffs on leave
            RemoveAura(iter);
        else
            ++iter;
    }
}

void Unit::RemoveAllAurasOnDeath()
{
    // used just after dieing to remove all visible auras
    // and disable the mods for the passive ones
    for(AuraMap::iterator iter = m_Auras.begin(); iter != m_Auras.end();)
    {
        if (!iter->second->IsPassive() && !iter->second->IsDeathPersistent())
            RemoveAura(iter, AURA_REMOVE_BY_DEATH);
        else
            ++iter;
    }
}

void Unit::DelayAura(uint32 spellId, uint64 caster, int32 delaytime)
{
    if (Aura * aur = GetAura(spellId, caster))
    {
        if (aur->GetAuraDuration() < delaytime)
            aur->SetAuraDuration(0);
        else
            aur->SetAuraDuration(aur->GetAuraDuration() - delaytime);
        // update for out of range group members (on 1 slot use)
        UpdateAuraForGroup(aur->GetAuraSlot());
        sLog.outDebug("Aura %u partially interrupted on unit %u, new duration: %u ms",aur->GetId(), GetGUIDLow(), aur->GetAuraDuration());
    }
}

void Unit::_RemoveAllAuraMods()
{
    for (AuraMap::iterator i = m_Auras.begin(); i != m_Auras.end(); ++i)
    {
        (*i).second->ApplyAllModifiers(false);
    }
}

void Unit::_ApplyAllAuraMods()
{
    for (AuraMap::iterator i = m_Auras.begin(); i != m_Auras.end(); ++i)
    {
        (*i).second->ApplyAllModifiers(true);
    }
}

bool Unit::HasAuraTypeWithMiscvalue(AuraType auratype, uint32 miscvalue) const
{
    AuraEffectList const& mTotalAuraList = GetAurasByType(auratype);
    for(AuraEffectList::const_iterator i = mTotalAuraList.begin();i != mTotalAuraList.end(); ++i)
        if (miscvalue == (*i)->GetMiscValue())
            return true;
    return false;
}

bool Unit::HasAuraType(AuraType auraType) const
{
    return (!m_modAuras[auraType].empty());
}

bool Unit::HasAura(uint32 spellId, uint64 caster) const
{
    //Special case for non existing spell
    if (spellId==61988)
        return HasAura(61987, caster) || HasAura(25771, caster);

    if (Aura * aur = GetAura(spellId, caster))
        return true;
    return false;
}

bool Unit::HasAura(Aura * aur) const
{
    // no need to find aura
    if (!aur || aur->IsRemoved())
        return false;
    for(AuraMap::const_iterator iter = m_Auras.lower_bound(aur->GetId()); iter != m_Auras.upper_bound(aur->GetId());)
    {
        if (aur == iter->second)
            return true;
        else
            ++iter;
    }
    return false;
}

bool Unit::HasAuraEffect(uint32 spellId, uint8 effIndex, uint64 caster) const
{
    if (Aura * aur = GetAura(spellId, caster))
        return bool(aur->HasEffect(effIndex));
    return false;
}

Aura * Unit::GetAura(uint32 spellId, uint64 caster) const
{
    if (!caster)
    {
        AuraMap::const_iterator itr = m_Auras.find(spellId);
        return itr != m_Auras.end() ? itr->second : NULL;
    }
    else
    {
        AuraMap const& auras = GetAuras();
        for(AuraMap::const_iterator itr = auras.lower_bound(spellId); itr != auras.upper_bound(spellId); ++itr)
            if(itr->second->GetCasterGUID()==caster)
                return itr->second;
        return NULL;
    }
}

AuraEffect * Unit::GetAuraEffect(uint32 spellId, uint8 effIndex, uint64 caster) const
{
    if (Aura * aur = GetAura(spellId, caster))
        return aur->GetPartAura(effIndex);
    return false;
}

AuraEffect* Unit::GetAura(AuraType type, uint32 family, uint32 familyFlag1, uint32 familyFlag2, uint32 familyFlag3, uint64 casterGUID)
{
    AuraEffectList const& auras = GetAurasByType(type);
    for(AuraEffectList::const_iterator i = auras.begin();i != auras.end(); ++i)
    {
        SpellEntry const *spell = (*i)->GetSpellProto();
        if (spell->SpellFamilyName == family && spell->SpellFamilyFlags.HasFlag(familyFlag1, familyFlag2, familyFlag3))
        {
            if (casterGUID && (*i)->GetCasterGUID()!=casterGUID)
                continue;
            return (*i);
        }
    }
    return NULL;
}

void Unit::AddDynObject(DynamicObject* dynObj)
{
    m_dynObjGUIDs.push_back(dynObj->GetGUID());
}

void Unit::RemoveDynObject(uint32 spellid)
{
    if(m_dynObjGUIDs.empty())
        return;
    for (DynObjectGUIDs::iterator i = m_dynObjGUIDs.begin(); i != m_dynObjGUIDs.end();)
    {
        DynamicObject* dynObj = GetMap()->GetDynamicObject(*i);
        if(!dynObj) // may happen if a dynobj is removed when grid unload
        {
            i = m_dynObjGUIDs.erase(i);
        }
        else if(spellid == 0 || dynObj->GetSpellId() == spellid)
        {
            dynObj->Delete();
            i = m_dynObjGUIDs.erase(i);
        }
        else
            ++i;
    }
}

void Unit::RemoveAllDynObjects()
{
    while(!m_dynObjGUIDs.empty())
    {
        DynamicObject* dynObj = GetMap()->GetDynamicObject(*m_dynObjGUIDs.begin());
        if(dynObj)
            dynObj->Delete();
        m_dynObjGUIDs.erase(m_dynObjGUIDs.begin());
    }
}

DynamicObject * Unit::GetDynObject(uint32 spellId, uint32 effIndex)
{
    for (DynObjectGUIDs::iterator i = m_dynObjGUIDs.begin(); i != m_dynObjGUIDs.end();)
    {
        DynamicObject* dynObj = GetMap()->GetDynamicObject(*i);
        if(!dynObj)
        {
            i = m_dynObjGUIDs.erase(i);
            continue;
        }

        if (dynObj->GetSpellId() == spellId && dynObj->GetEffIndex() == effIndex)
            return dynObj;
        ++i;
    }
    return NULL;
}

DynamicObject * Unit::GetDynObject(uint32 spellId)
{
    for (DynObjectGUIDs::iterator i = m_dynObjGUIDs.begin(); i != m_dynObjGUIDs.end();)
    {
        DynamicObject* dynObj = GetMap()->GetDynamicObject(*i);
        if(!dynObj)
        {
            i = m_dynObjGUIDs.erase(i);
            continue;
        }

        if (dynObj->GetSpellId() == spellId)
            return dynObj;
        ++i;
    }
    return NULL;
}

GameObject* Unit::GetGameObject(uint32 spellId) const
{
    for (GameObjectList::const_iterator i = m_gameObj.begin(); i != m_gameObj.end();)
        if ((*i)->GetSpellId() == spellId)
            return *i;

    return NULL;
}

void Unit::AddGameObject(GameObject* gameObj)
{
    assert(gameObj && gameObj->GetOwnerGUID()==0);
    m_gameObj.push_back(gameObj);
    gameObj->SetOwnerGUID(GetGUID());

    if ( GetTypeId()==TYPEID_PLAYER && gameObj->GetSpellId() )
    {
        SpellEntry const* createBySpell = sSpellStore.LookupEntry(gameObj->GetSpellId());
        // Need disable spell use for owner
        if (createBySpell && createBySpell->Attributes & SPELL_ATTR_DISABLED_WHILE_ACTIVE)
            // note: item based cooldowns and cooldown spell mods with charges ignored (unknown existed cases)
            ((Player*)this)->AddSpellAndCategoryCooldowns(createBySpell,0,NULL,true);
    }
}

void Unit::RemoveGameObject(GameObject* gameObj, bool del)
{
    assert(gameObj && gameObj->GetOwnerGUID()==GetGUID());

    gameObj->SetOwnerGUID(0);

    // GO created by some spell
    if (uint32 spellid = gameObj->GetSpellId())
    {
        RemoveAurasDueToSpell(spellid);

        if (GetTypeId()==TYPEID_PLAYER)
        {
            SpellEntry const* createBySpell = sSpellStore.LookupEntry(spellid );
            // Need activate spell use for owner
            if (createBySpell && createBySpell->Attributes & SPELL_ATTR_DISABLED_WHILE_ACTIVE)
                // note: item based cooldowns and cooldown spell mods with charges ignored (unknown existed cases)
                ((Player*)this)->SendCooldownEvent(createBySpell);
        }
    }

    m_gameObj.remove(gameObj);

    if(del)
    {
        gameObj->SetRespawnTime(0);
        gameObj->Delete();
    }
}

void Unit::RemoveGameObject(uint32 spellid, bool del)
{
    if(m_gameObj.empty())
        return;
    GameObjectList::iterator i, next;
    for (i = m_gameObj.begin(); i != m_gameObj.end(); i = next)
    {
        next = i;
        if(spellid == 0 || (*i)->GetSpellId() == spellid)
        {
            (*i)->SetOwnerGUID(0);
            if(del)
            {
                (*i)->SetRespawnTime(0);
                (*i)->Delete();
            }

            next = m_gameObj.erase(i);
        }
        else
            ++next;
    }
}

void Unit::RemoveAllGameObjects()
{
    // remove references to unit
    for(GameObjectList::iterator i = m_gameObj.begin(); i != m_gameObj.end();)
    {
        (*i)->SetOwnerGUID(0);
        (*i)->SetRespawnTime(0);
        (*i)->Delete();
        i = m_gameObj.erase(i);
    }
}

void Unit::SendSpellNonMeleeDamageLog(SpellNonMeleeDamage *log)
{
    WorldPacket data(SMSG_SPELLNONMELEEDAMAGELOG, (16+4+4+1+4+4+1+1+4+4+1)); // we guess size
    data.append(log->target->GetPackGUID());
    data.append(log->attacker->GetPackGUID());
    data << uint32(log->SpellID);
    data << uint32(log->damage);                             //damage amount
    data << uint32(int32 (log->target->GetHealth()-log->damage ) >0 ? 0 : log->damage - log->target->GetHealth());
    data << uint8 (log->schoolMask);                         //damage school
    data << uint32(log->absorb);                             //AbsorbedDamage
    data << uint32(log->resist);                             //resist
    data << uint8 (log->phusicalLog);                        // damsge type? flag
    data << uint8 (log->unused);                             //unused
    data << uint32(log->blocked);                            //blocked
    data << uint32(log->HitInfo);
    data << uint8 (0);                                       // flag to use extend data
    SendMessageToSet( &data, true );
}

void Unit::SendSpellNonMeleeDamageLog(Unit *target,uint32 SpellID,uint32 Damage, SpellSchoolMask damageSchoolMask,uint32 AbsorbedDamage, uint32 Resist,bool PhysicalDamage, uint32 Blocked, bool CriticalHit)
{
    sLog.outDebug("Sending: SMSG_SPELLNONMELEEDAMAGELOG");
    WorldPacket data(SMSG_SPELLNONMELEEDAMAGELOG, (16+4+4+1+4+4+1+1+4+4+1)); // we guess size
    data.append(target->GetPackGUID());
    data.append(GetPackGUID());
    data << uint32(SpellID);
    int32 damageDone = Damage-AbsorbedDamage-Resist-Blocked;
    data << uint32(damageDone);
    data << uint32(int32 (target->GetHealth()-damageDone ) >0 ? 0 : damageDone - target->GetHealth());// wotlk
    data << uint8(damageSchoolMask);                        // spell school
    data << uint32(AbsorbedDamage);                         // AbsorbedDamage
    data << uint32(Resist);                                 // resist
    data << uint8(PhysicalDamage);                          // if 1, then client show spell name (example: %s's ranged shot hit %s for %u school or %s suffers %u school damage from %s's spell_name
    data << uint8(0);                                       // unk isFromAura
    data << uint32(Blocked);                                // blocked
    data << uint32(CriticalHit ? 0x27 : 0x25);              // hitType, flags: 0x2 - SPELL_HIT_TYPE_CRIT, 0x10 - replace caster?
    data << uint8(0);                                       // isDebug?
    SendMessageToSet( &data, true );
}

void Unit::ProcDamageAndSpell(Unit *pVictim, uint32 procAttacker, uint32 procVictim, uint32 procExtra, uint32 amount, WeaponAttackType attType, SpellEntry const *procSpell)
{
     // Not much to do if no flags are set.
    if (procAttacker)
        ProcDamageAndSpellFor(false,pVictim,procAttacker, procExtra,attType, procSpell, amount);
    // Now go on with a victim's events'n'auras
    // Not much to do if no flags are set or there is no victim
    if(pVictim && pVictim->isAlive() && procVictim)
        pVictim->ProcDamageAndSpellFor(true,this,procVictim, procExtra, attType, procSpell, amount);
}

void Unit::SendSpellMiss(Unit *target, uint32 spellID, SpellMissInfo missInfo)
{
    WorldPacket data(SMSG_SPELLLOGMISS, (4+8+1+4+8+1));
    data << uint32(spellID);
    data << uint64(GetGUID());
    data << uint8(0);                                       // can be 0 or 1
    data << uint32(1);                                      // target count
    // for(i = 0; i < target count; ++i)
    data << uint64(target->GetGUID());                      // target GUID
    data << uint8(missInfo);
    // end loop
    SendMessageToSet(&data, true);
}

void Unit::SendAttackStateUpdate(CalcDamageInfo *damageInfo)
{
    uint32 count = 1;
    WorldPacket data(SMSG_ATTACKERSTATEUPDATE, (16+45));    // we guess size
    data << (uint32)damageInfo->HitInfo;
    data.append(GetPackGUID());
    data.append(damageInfo->target->GetPackGUID());
    data << (uint32)(damageInfo->damage);     // Full damage
    data << uint32(int32 (damageInfo->target->GetHealth()-damageInfo->damage ) >0 ? 0 : damageInfo->damage - damageInfo->target->GetHealth()); // Overkill

    data << (uint8)count;                     // Sub damage count

    for(int i = 0; i < count; ++i)
    {
        data << (uint32)(damageInfo->damageSchoolMask); // School of sub damage
        data << (float)damageInfo->damage;        // sub damage
        data << (uint32)damageInfo->damage;       // Sub Damage
    }

    if(damageInfo->HitInfo & (HITINFO_ABSORB | HITINFO_ABSORB2))
    {
        for(int i = 0; i < count; ++i)
            data << (uint32)damageInfo->absorb;       // Absorb
    }

    if(damageInfo->HitInfo & (HITINFO_RESIST | HITINFO_RESIST2))
    {
        for(int i = 0; i < count; ++i)
            data << (uint32)damageInfo->resist;       // Resist
    }

    data << (uint8)damageInfo->TargetState;
    data << (uint32)0;
    data << (uint32)0;

    if(damageInfo->HitInfo & HITINFO_BLOCK)
        data << (uint32)damageInfo->blocked_amount;

    if(damageInfo->HitInfo & HITINFO_UNK3)
        data << uint32(0);

    if(damageInfo->HitInfo & HITINFO_UNK1)
    {
        data << uint32(0);
        data << float(0);
        data << float(0);
        data << float(0);
        data << float(0);
        data << float(0);
        data << float(0);
        data << float(0);
        data << float(0);
        for(uint8 i = 0; i < 5; ++i)
        {
            data << float(0);
            data << float(0);
        }
        data << uint32(0);
    }

    SendMessageToSet( &data, true );
}

void Unit::SendAttackStateUpdate(uint32 HitInfo, Unit *target, uint8 SwingType, SpellSchoolMask damageSchoolMask, uint32 Damage, uint32 AbsorbDamage, uint32 Resist, VictimState TargetState, uint32 BlockedAmount)
{
    sLog.outDebug("WORLD: Sending SMSG_ATTACKERSTATEUPDATE");

    WorldPacket data(SMSG_ATTACKERSTATEUPDATE, (16+45));    // we guess size
    data << uint32(HitInfo);                                // flags
    data.append(GetPackGUID());
    data.append(target->GetPackGUID());
    int32 damageDone = Damage-AbsorbDamage-Resist-BlockedAmount;
    data << uint32(damageDone);// damage
    data << uint32(int32 (target->GetHealth()-damageDone ) >0 ? 0 : damageDone - target->GetHealth()); // Overkill

    data << (uint8)SwingType;                               // count?

    // for(i = 0; i < SwingType; ++i)
    data << (uint32)damageSchoolMask;
    data << (float)(damageDone);
    data << (uint32)(damageDone);
    // end loop

    if(HitInfo & (HITINFO_ABSORB | HITINFO_ABSORB2))
    {
        // for(i = 0; i < SwingType; ++i)
        data << uint32(AbsorbDamage);
        // end loop
    }

    if(HitInfo & (HITINFO_RESIST | HITINFO_RESIST2))
    {
        // for(i = 0; i < SwingType; ++i)
        data << uint32(Resist);
        // end loop
    }

    data << (uint8)TargetState;
    data << (uint32)0;
    data << (uint32)0;

    if(HitInfo & HITINFO_BLOCK)
    {
        data << uint32(BlockedAmount);
    }

    if(HitInfo & HITINFO_UNK3)
    {
        data << uint32(0);
    }

    if(HitInfo & HITINFO_UNK1)
    {
        data << uint32(0);
        data << float(0);
        data << float(0);
        data << float(0);
        data << float(0);
        data << float(0);
        data << float(0);
        data << float(0);
        data << float(0);
        for(uint8 i = 0; i < 5; ++i)
        {
            data << float(0);
            data << float(0);
        }
        data << uint32(0);
    }

    SendMessageToSet( &data, true );
}

bool Unit::HandleHasteAuraProc(Unit *pVictim, uint32 damage, AuraEffect* triggeredByAura, SpellEntry const * procSpell, uint32 /*procFlag*/, uint32 /*procEx*/, uint32 cooldown)
{
    SpellEntry const *hasteSpell = triggeredByAura->GetSpellProto();

    Item* castItem = triggeredByAura->GetParentAura()->GetCastItemGUID() && GetTypeId()==TYPEID_PLAYER
        ? ((Player*)this)->GetItemByGuid(triggeredByAura->GetParentAura()->GetCastItemGUID()) : NULL;

    uint32 triggered_spell_id = 0;
    Unit* target = pVictim;
    int32 basepoints0 = 0;

    switch(hasteSpell->SpellFamilyName)
    {
        case SPELLFAMILY_ROGUE:
        {
            switch(hasteSpell->Id)
            {
                // Blade Flurry
                case 13877:
                case 33735:
                {
                    target = SelectNearbyTarget();
                    if(!target)
                        return false;
                    basepoints0 = damage;
                    triggered_spell_id = 22482;
                    break;
                }
            }
            break;
        }
    }

    // processed charge only counting case
    if(!triggered_spell_id)
        return true;

    SpellEntry const* triggerEntry = sSpellStore.LookupEntry(triggered_spell_id);

    if(!triggerEntry)
    {
        sLog.outError("Unit::HandleHasteAuraProc: Spell %u have not existed triggered spell %u",hasteSpell->Id,triggered_spell_id);
        return false;
    }

    // default case
    if(!target || target!=this && !target->isAlive())
        return false;

    if( cooldown && GetTypeId()==TYPEID_PLAYER && ((Player*)this)->HasSpellCooldown(triggered_spell_id))
        return false;

    if(basepoints0)
        CastCustomSpell(target,triggered_spell_id,&basepoints0,NULL,NULL,true,castItem,triggeredByAura);
    else
        CastSpell(target,triggered_spell_id,true,castItem,triggeredByAura);

    if( cooldown && GetTypeId()==TYPEID_PLAYER )
        ((Player*)this)->AddSpellCooldown(triggered_spell_id,0,time(NULL) + cooldown);

    return true;
}

bool Unit::HandleDummyAuraProc(Unit *pVictim, uint32 damage, AuraEffect* triggeredByAura, SpellEntry const * procSpell, uint32 procFlag, uint32 procEx, uint32 cooldown)
{
    SpellEntry const *dummySpell = triggeredByAura->GetSpellProto ();
    uint32 effIndex = triggeredByAura->GetEffIndex();
    int32  triggerAmount = triggeredByAura->GetAmount();

    Item* castItem = triggeredByAura->GetParentAura()->GetCastItemGUID() && GetTypeId()==TYPEID_PLAYER
        ? ((Player*)this)->GetItemByGuid(triggeredByAura->GetParentAura()->GetCastItemGUID()) : NULL;

    uint32 triggered_spell_id = 0;
    Unit* target = pVictim;
    int32 basepoints0 = 0;

    // Master of subtlety (checked here because ranks have different spellfamilynames)
    if (dummySpell->Id == 31223 || dummySpell->Id == 31221 || dummySpell->Id == 31222)
    {
        if (procEx & AURA_REMOVE_PROC_EX_MASK)
            triggered_spell_id = 31666;
        else
        {
            triggered_spell_id = 31665;
            basepoints0 = triggerAmount;
        }
    }
    switch(dummySpell->SpellFamilyName)
    {
        case SPELLFAMILY_GENERIC:
        {
            switch (dummySpell->Id)
            {
                // Improved Divine Spirit
                case 33174:
                case 33182:
                {
                    // Tricky thing here, we find current aura from spell by caster and change its modifier value
                    int32 spelldmg = CalculateSpellDamage(procSpell, 0, procSpell->EffectBasePoints[0],pVictim);
                    if (AuraEffect * Aur = pVictim->GetAuraEffect(procSpell->Id, effIndex+1, triggeredByAura->GetCasterGUID()))
                    {
                        // Remove aura mods
                        Aur->ApplyModifier(false);
                        Aur->SetAmount(Aur->GetAmount() + spelldmg * triggerAmount / 100);
                        // Apply extended aura mods
                        Aur->ApplyModifier(true);
                        return true;
                    }
                    return false;
                }
                // Eye for an Eye
                case 9799:
                case 25988:
                {
                    // return damage % to attacker but < 50% own total health
                    basepoints0 = triggerAmount*int32(damage)/100;
                    if(basepoints0 > GetMaxHealth()/2)
                        basepoints0 = GetMaxHealth()/2;

                    triggered_spell_id = 25997;
                    break;
                }
                // Sweeping Strikes
                case 12328:
                case 18765:
                case 35429:
                {
                    // prevent chain of triggered spell from same triggered spell
                    if(procSpell && procSpell->Id==26654)
                        return false;

                    target = SelectNearbyTarget();
                    if(!target)
                        return false;

                    triggered_spell_id = 26654;
                    break;
                }
                // Unstable Power
                case 24658:
                {
                    if (!procSpell || procSpell->Id == 24659)
                        return false;
                    // Need remove one 24659 aura
                    RemoveAuraFromStack(24659);
                    return true;
                }
                // Restless Strength
                case 24661:
                {
                    // Need remove one 24662 aura
                    RemoveAuraFromStack(24662);
                    return true;
                }
                // Adaptive Warding (Frostfire Regalia set)
                case 28764:
                {
                    if(!procSpell)
                        return false;

                    // find Mage Armor
                    bool found = false;
                    AuraEffectList const& mRegenInterupt = GetAurasByType(SPELL_AURA_MOD_MANA_REGEN_INTERRUPT);
                    for(AuraEffectList::const_iterator iter = mRegenInterupt.begin(); iter != mRegenInterupt.end(); ++iter)
                    {
                        if(SpellEntry const* iterSpellProto = (*iter)->GetSpellProto())
                        {
                            if(iterSpellProto->SpellFamilyName==SPELLFAMILY_MAGE && (iterSpellProto->SpellFamilyFlags[0] & 0x10000000))
                            {
                                found=true;
                                break;
                            }
                        }
                    }
                    if(!found)
                        return false;

                    switch(GetFirstSchoolInMask(GetSpellSchoolMask(procSpell)))
                    {
                        case SPELL_SCHOOL_NORMAL:
                        case SPELL_SCHOOL_HOLY:
                            return false;                   // ignored
                        case SPELL_SCHOOL_FIRE:   triggered_spell_id = 28765; break;
                        case SPELL_SCHOOL_NATURE: triggered_spell_id = 28768; break;
                        case SPELL_SCHOOL_FROST:  triggered_spell_id = 28766; break;
                        case SPELL_SCHOOL_SHADOW: triggered_spell_id = 28769; break;
                        case SPELL_SCHOOL_ARCANE: triggered_spell_id = 28770; break;
                        default:
                            return false;
                    }

                    target = this;
                    break;
                }
                // Obsidian Armor (Justice Bearer`s Pauldrons shoulder)
                case 27539:
                {
                    if(!procSpell)
                        return false;

                    switch(GetFirstSchoolInMask(GetSpellSchoolMask(procSpell)))
                    {
                        case SPELL_SCHOOL_NORMAL:
                            return false;                   // ignore
                        case SPELL_SCHOOL_HOLY:   triggered_spell_id = 27536; break;
                        case SPELL_SCHOOL_FIRE:   triggered_spell_id = 27533; break;
                        case SPELL_SCHOOL_NATURE: triggered_spell_id = 27538; break;
                        case SPELL_SCHOOL_FROST:  triggered_spell_id = 27534; break;
                        case SPELL_SCHOOL_SHADOW: triggered_spell_id = 27535; break;
                        case SPELL_SCHOOL_ARCANE: triggered_spell_id = 27540; break;
                        default:
                            return false;
                    }

                    target = this;
                    break;
                }
                // Mana Leech (Passive) (Priest Pet Aura)
                case 28305:
                {
                    // Cast on owner
                    target = GetOwner();
                    if(!target)
                        return false;

                    triggered_spell_id = 34650;
                    break;
                }
                // Overkill
                case 58426:
                {
                    if (procEx & AURA_REMOVE_PROC_EX_MASK)
                        triggered_spell_id = 58428;
                    else
                    {
                        basepoints0 = -triggerAmount;
                        triggered_spell_id = 58427;
                    }
                    break;
                }
                // Mark of Malice
                case 33493:
                {
                    // Cast finish spell at last charge
                    if (triggeredByAura->GetParentAura()->GetAuraCharges() > 1)
                        return false;

                    target = this;
                    triggered_spell_id = 33494;
                    break;
                }
                // Twisted Reflection (boss spell)
                case 21063:
                    triggered_spell_id = 21064;
                    break;
                // Vampiric Aura (boss spell)
                case 38196:
                {
                    basepoints0 = 3 * damage;               // 300%
                    if (basepoints0 < 0)
                        return false;

                    triggered_spell_id = 31285;
                    target = this;
                    break;
                }
                // Aura of Madness (Darkmoon Card: Madness trinket)
                //=====================================================
                // 39511 Sociopath: +35 strength (Paladin, Rogue, Druid, Warrior)
                // 40997 Delusional: +70 attack power (Rogue, Hunter, Paladin, Warrior, Druid)
                // 40998 Kleptomania: +35 agility (Warrior, Rogue, Paladin, Hunter, Druid)
                // 40999 Megalomania: +41 damage/healing (Druid, Shaman, Priest, Warlock, Mage, Paladin)
                // 41002 Paranoia: +35 spell/melee/ranged crit strike rating (All classes)
                // 41005 Manic: +35 haste (spell, melee and ranged) (All classes)
                // 41009 Narcissism: +35 intellect (Druid, Shaman, Priest, Warlock, Mage, Paladin, Hunter)
                // 41011 Martyr Complex: +35 stamina (All classes)
                // 41406 Dementia: Every 5 seconds either gives you +5% damage/healing. (Druid, Shaman, Priest, Warlock, Mage, Paladin)
                // 41409 Dementia: Every 5 seconds either gives you -5% damage/healing. (Druid, Shaman, Priest, Warlock, Mage, Paladin)
                case 39446:
                {
                    if(GetTypeId() != TYPEID_PLAYER || !this->isAlive())
                        return false;

                    // Select class defined buff
                    switch (getClass())
                    {
                        case CLASS_PALADIN:                 // 39511,40997,40998,40999,41002,41005,41009,41011,41409
                        case CLASS_DRUID:                   // 39511,40997,40998,40999,41002,41005,41009,41011,41409
                        {
                            uint32 RandomSpell[]={39511,40997,40998,40999,41002,41005,41009,41011,41409};
                            triggered_spell_id = RandomSpell[ irand(0, sizeof(RandomSpell)/sizeof(uint32) - 1) ];
                            break;
                        }
                        case CLASS_ROGUE:                   // 39511,40997,40998,41002,41005,41011
                        case CLASS_WARRIOR:                 // 39511,40997,40998,41002,41005,41011
                        {
                            uint32 RandomSpell[]={39511,40997,40998,41002,41005,41011};
                            triggered_spell_id = RandomSpell[ irand(0, sizeof(RandomSpell)/sizeof(uint32) - 1) ];
                            break;
                        }
                        case CLASS_PRIEST:                  // 40999,41002,41005,41009,41011,41406,41409
                        case CLASS_SHAMAN:                  // 40999,41002,41005,41009,41011,41406,41409
                        case CLASS_MAGE:                    // 40999,41002,41005,41009,41011,41406,41409
                        case CLASS_WARLOCK:                 // 40999,41002,41005,41009,41011,41406,41409
                        {
                            uint32 RandomSpell[]={40999,41002,41005,41009,41011,41406,41409};
                            triggered_spell_id = RandomSpell[ irand(0, sizeof(RandomSpell)/sizeof(uint32) - 1) ];
                            break;
                        }
                        case CLASS_HUNTER:                  // 40997,40999,41002,41005,41009,41011,41406,41409
                        {
                            uint32 RandomSpell[]={40997,40999,41002,41005,41009,41011,41406,41409};
                            triggered_spell_id = RandomSpell[ irand(0, sizeof(RandomSpell)/sizeof(uint32) - 1) ];
                            break;
                        }
                        default:
                            return false;
                    }

                    target = this;
                    if (roll_chance_i(10))
                        ((Player*)this)->Say("This is Madness!", LANG_UNIVERSAL);
                    break;
                }
                /*
                // TODO: need find item for aura and triggered spells
                // Sunwell Exalted Caster Neck (??? neck)
                // cast ??? Light's Wrath if Exalted by Aldor
                // cast ??? Arcane Bolt if Exalted by Scryers*/
                case 46569:
                    return false;                           // disable for while
                /*
                {
                    if(GetTypeId() != TYPEID_PLAYER)
                        return false;

                    // Get Aldor reputation rank
                    if (((Player *)this)->GetReputationRank(932) == REP_EXALTED)
                    {
                        target = this;
                        triggered_spell_id = ???
                        break;
                    }
                    // Get Scryers reputation rank
                    if (((Player *)this)->GetReputationRank(934) == REP_EXALTED)
                    {
                        triggered_spell_id = ???
                        break;
                    }
                    return false;
                }/**/
                // Sunwell Exalted Caster Neck (Shattered Sun Pendant of Acumen neck)
                // cast 45479 Light's Wrath if Exalted by Aldor
                // cast 45429 Arcane Bolt if Exalted by Scryers
                case 45481:
                {
                    if(GetTypeId() != TYPEID_PLAYER)
                        return false;

                    // Get Aldor reputation rank
                    if (((Player *)this)->GetReputationRank(932) == REP_EXALTED)
                    {
                        target = this;
                        triggered_spell_id = 45479;
                        break;
                    }
                    // Get Scryers reputation rank
                    if (((Player *)this)->GetReputationRank(934) == REP_EXALTED)
                    {
                        if(this->IsFriendlyTo(target))
                            return false;

                        triggered_spell_id = 45429;
                        break;
                    }
                    return false;
                }
                // Sunwell Exalted Melee Neck (Shattered Sun Pendant of Might neck)
                // cast 45480 Light's Strength if Exalted by Aldor
                // cast 45428 Arcane Strike if Exalted by Scryers
                case 45482:
                {
                    if(GetTypeId() != TYPEID_PLAYER)
                        return false;

                    // Get Aldor reputation rank
                    if (((Player *)this)->GetReputationRank(932) == REP_EXALTED)
                    {
                        target = this;
                        triggered_spell_id = 45480;
                        break;
                    }
                    // Get Scryers reputation rank
                    if (((Player *)this)->GetReputationRank(934) == REP_EXALTED)
                    {
                        triggered_spell_id = 45428;
                        break;
                    }
                    return false;
                }
                // Sunwell Exalted Tank Neck (Shattered Sun Pendant of Resolve neck)
                // cast 45431 Arcane Insight if Exalted by Aldor
                // cast 45432 Light's Ward if Exalted by Scryers
                case 45483:
                {
                    if(GetTypeId() != TYPEID_PLAYER)
                        return false;

                    // Get Aldor reputation rank
                    if (((Player *)this)->GetReputationRank(932) == REP_EXALTED)
                    {
                        target = this;
                        triggered_spell_id = 45432;
                        break;
                    }
                    // Get Scryers reputation rank
                    if (((Player *)this)->GetReputationRank(934) == REP_EXALTED)
                    {
                        target = this;
                        triggered_spell_id = 45431;
                        break;
                    }
                    return false;
                }
                // Sunwell Exalted Healer Neck (Shattered Sun Pendant of Restoration neck)
                // cast 45478 Light's Salvation if Exalted by Aldor
                // cast 45430 Arcane Surge if Exalted by Scryers
                case 45484:
                {
                    if(GetTypeId() != TYPEID_PLAYER)
                        return false;

                    // Get Aldor reputation rank
                    if (((Player *)this)->GetReputationRank(932) == REP_EXALTED)
                    {
                        target = this;
                        triggered_spell_id = 45478;
                        break;
                    }
                    // Get Scryers reputation rank
                    if (((Player *)this)->GetReputationRank(934) == REP_EXALTED)
                    {
                        triggered_spell_id = 45430;
                        break;
                    }
                    return false;
                }
                // Living Seed
                case 48504:
                {
                    triggered_spell_id = 48503;
                    basepoints0 = triggerAmount;
                    target = this;
                    break;
                }
                // Kill command
                case 58914:
                {
                    // Remove aura stack from pet
                    RemoveAuraFromStack(58914);
                    Unit* owner = GetOwner();
                    if(!owner)
                        return true;
                    // reduce the owner's aura stack
                    owner->RemoveAuraFromStack(34027);
                    return true;
                }
                // Vampiric Touch (generic, used by some boss)
                case 52723:
                case 60501:
                {
                    triggered_spell_id = 52724;
                    basepoints0 = damage / 2;
                    target = this;
                    break;
                }
                // Divine purpose
                case 31871:
                case 31872:
                {
                    // Roll chane
                    if (!roll_chance_i(triggerAmount))
                        return false;

                    // Remove any stun effect on target
                    AuraMap& Auras = pVictim->GetAuras();
                    for(AuraMap::iterator iter = Auras.begin(); iter != Auras.end();)
                    {
                        SpellEntry const *spell = iter->second->GetSpellProto();
                        if( GetAllSpellMechanicMask(spell) & 1<<(MECHANIC_STUN))
                        {
                            pVictim->RemoveAura(iter);
                        }
                        else
                            ++iter;
                    }
                    return true;
                }
            }
            break;
        }
        case SPELLFAMILY_MAGE:
        {
            // Magic Absorption
            if (dummySpell->SpellIconID == 459)             // only this spell have SpellIconID == 459 and dummy aura
            {
                if (getPowerType() != POWER_MANA)
                    return false;

                // mana reward
                basepoints0 = (triggerAmount * GetMaxPower(POWER_MANA) / 100);
                target = this;
                triggered_spell_id = 29442;
                break;
            }
            // Master of Elements
            if (dummySpell->SpellIconID == 1920)
            {
                if(!procSpell)
                    return false;

                // mana cost save
                int32 cost = procSpell->manaCost + procSpell->ManaCostPercentage * GetCreateMana() / 100;
                basepoints0 = cost * triggerAmount/100;
                if( basepoints0 <=0 )
                    return false;

                target = this;
                triggered_spell_id = 29077;
                break;
            }
            // Shattered Barrier
            if (dummySpell->SpellIconID == 2945)
            {
                // only on dispel/remove aura by destroy
                target = NULL;
                triggered_spell_id = 55080;
                CastSpell(target, triggered_spell_id, true);
                return true;
            }
            // Hot Streak
            if (dummySpell->SpellIconID == 2999)
            {
                if (effIndex!=0)
                    return false;
                AuraEffect *counter = GetAuraEffect(triggeredByAura->GetId(), 1);
                if (!counter)
                    return true;

                // Count spell criticals in a row in second aura
                if (procEx & PROC_EX_CRITICAL_HIT)
                {
                    counter->SetAmount(counter->GetAmount()*2);
                    if (counter->GetAmount() < 100) // not enough
                        return true;
                    // Crititcal counted -> roll chance
                    if (roll_chance_i(triggerAmount))
                       CastSpell(this, 48108, true, castItem, triggeredByAura);
                }
                counter->SetAmount(25);
                return true;
            }
            // Burnout
            if (dummySpell->SpellIconID == 2998)
            {
                if(!procSpell)
                    return false;

                int32 cost = procSpell->manaCost + procSpell->ManaCostPercentage * GetCreateMana() / 100;
                basepoints0 = cost * triggerAmount/100;
                if( basepoints0 <=0 )
                    return false;
                triggered_spell_id = 44450;
                target = this;
                break;
            }
            // Incanter's Regalia set (add trigger chance to Mana Shield)
            if (dummySpell->SpellFamilyFlags[0] & 0x8000)
            {
                if(GetTypeId() != TYPEID_PLAYER)
                    return false;

                target = this;
                triggered_spell_id = 37436;
                break;
            }
            switch(dummySpell->Id)
            {
                // Ignite
                case 11119:
                case 11120:
                case 12846:
                case 12847:
                case 12848:
                {
                    switch (dummySpell->Id)
                    {
                        case 11119: basepoints0 = int32(0.04f*damage); break;
                        case 11120: basepoints0 = int32(0.08f*damage); break;
                        case 12846: basepoints0 = int32(0.12f*damage); break;
                        case 12847: basepoints0 = int32(0.16f*damage); break;
                        case 12848: basepoints0 = int32(0.20f*damage); break;
                        default:
                            sLog.outError("Unit::HandleDummyAuraProc: non handled spell id: %u (IG)",dummySpell->Id);
                            return false;
                    }

                    triggered_spell_id = 12654;
                    break;
                }
                // Combustion
                case 11129:
                {
                    //last charge and crit
                    if (triggeredByAura->GetParentAura()->GetAuraCharges() <= 1 && (procEx & PROC_EX_CRITICAL_HIT) )
                    {
                        RemoveAurasDueToSpell(28682);       //-> remove Combustion auras
                        return true;                        // charge counting (will removed)
                    }

                    CastSpell(this, 28682, true, castItem, triggeredByAura);
                    return (procEx & PROC_EX_CRITICAL_HIT);// charge update only at crit hits, no hidden cooldowns
                }
            }
            break;
        }
        case SPELLFAMILY_WARRIOR:
        {
            // Retaliation
            if(dummySpell->SpellFamilyFlags.IsEqual(0, 0x8, 0))
            {
                // check attack comes not from behind
                if (!HasInArc(M_PI, pVictim))
                    return false;

                triggered_spell_id = 22858;
                break;
            }
            // Glyph of Devastate
            if(dummySpell->Id==58388)
            {
                // get highest rank of the Sunder Armor spell
                if (GetTypeId()!=TYPEID_PLAYER)
                    return false;
                const PlayerSpellMap& sp_list = ((Player*)this)->GetSpellMap();
                for (PlayerSpellMap::const_iterator itr = sp_list.begin(); itr != sp_list.end(); ++itr)
                {
                    // only highest rank is shown in spell book, so simply check if shown in spell book
                    if(!itr->second->active || itr->second->disabled || itr->second->state == PLAYERSPELL_REMOVED)
                        continue;

                    SpellEntry const *spellInfo = sSpellStore.LookupEntry(itr->first);
                    if (!spellInfo)
                        continue;

                    if (spellInfo->SpellFamilyFlags.IsEqual(SPELLFAMILYFLAG_WARRIOR_SUNDERARMOR)
                        && spellInfo->SpellFamilyName == SPELLFAMILY_WARRIOR)
                    {
                        triggered_spell_id = spellInfo->Id;
                        break;
                    }
                }
                if (!triggered_spell_id)
                    return false;
                for (int32 value = CalculateSpellDamage(dummySpell, 0 , dummySpell->EffectBasePoints[0], pVictim);value>0;value--)
                    CastSpell(target,triggered_spell_id,true);
                return true;
            }
            // Second Wind
            if (dummySpell->SpellIconID == 1697)
            {
                // only for spells and hit/crit (trigger start always) and not start from self casted spells (5530 Mace Stun Effect for example)
                if (procSpell == 0 || !(procEx & (PROC_EX_NORMAL_HIT|PROC_EX_CRITICAL_HIT)) || this == pVictim)
                    return false;
                // Need stun or root mechanic
                if (!(GetAllSpellMechanicMask(procSpell) & ((1<<MECHANIC_ROOT)|(1<<MECHANIC_STUN))))
                    return false;

                switch (dummySpell->Id)
                {
                    case 29838: triggered_spell_id=29842; break;
                    case 29834: triggered_spell_id=29841; break;
                    case 42770: triggered_spell_id=42771; break;
                    default:
                        sLog.outError("Unit::HandleDummyAuraProc: non handled spell id: %u (SW)",dummySpell->Id);
                    return false;
                }

                target = this;
                break;
            }
            // Damage Shield
            if (dummySpell->SpellIconID == 3214)
            {
                triggered_spell_id = 59653;
                // % of amount blocked
                basepoints0 = GetShieldBlockValue() * triggerAmount / 100;
                break;
            }
            break;
        }
        case SPELLFAMILY_WARLOCK:
        {
            // Seed of Corruption
            if (dummySpell->SpellFamilyFlags[1] & 0x00000010)
            {
                // if damage is more than need or target die from damage deal finish spell
                if( triggeredByAura->GetAmount() <= damage || GetHealth() <= damage )
                {
                    // remember guid before aura delete
                    uint64 casterGuid = triggeredByAura->GetCasterGUID();

                    // Remove aura (before cast for prevent infinite loop handlers)
                    RemoveAurasDueToSpell(triggeredByAura->GetId());

                    // Cast finish spell (triggeredByAura already not exist!)
                    if(Unit* caster = GetUnit(*this, casterGuid))
                        caster->CastSpell(this, 27285, true, castItem);
                    return true;                            // no hidden cooldown
                }

                // Damage counting
                triggeredByAura->SetAmount(triggeredByAura->GetAmount() - damage);
                return true;
            }
            // Seed of Corruption (Mobs cast) - no die req
            if (dummySpell->SpellFamilyFlags.IsEqual(0,0,0) && dummySpell->SpellIconID == 1932)
            {
                // if damage is more than need deal finish spell
                if( triggeredByAura->GetAmount() <= damage )
                {
                    // remember guid before aura delete
                    uint64 casterGuid = triggeredByAura->GetCasterGUID();

                    // Remove aura (before cast for prevent infinite loop handlers)
                    RemoveAurasDueToSpell(triggeredByAura->GetId());

                    // Cast finish spell (triggeredByAura already not exist!)
                    if(Unit* caster = GetUnit(*this, casterGuid))
                        caster->CastSpell(this, 32865, true, castItem);
                    return true;                            // no hidden cooldown
                }
                // Damage counting
                triggeredByAura->SetAmount(triggeredByAura->GetAmount() - damage);
                return true;
            }
            // Fel Synergy
            if (dummySpell->SpellIconID == 3222)
            {
                target = GetGuardianPet();
                if (!target)
                    return false;
                triggered_spell_id = 54181;
                basepoints0 = damage * 15 / 100;
                break;
            }
            switch(dummySpell->Id)
            {
                // Nightfall
                case 18094:
                case 18095:
                {
                    target = this;
                    triggered_spell_id = 17941;
                    break;
                }
                //Soul Leech
                case 30293:
                case 30295:
                case 30296:
                {
                    // Improved Soul Leech
                    AuraEffectList const& SoulLeechAuras = GetAurasByType(SPELL_AURA_DUMMY);
                    for(Unit::AuraEffectList::const_iterator i = SoulLeechAuras.begin();i != SoulLeechAuras.end(); ++i)
                    {
                        if ((*i)->GetId()==54117 || (*i)->GetId()==54118)
                        {
                            basepoints0 = int32((*i)->GetAmount());
                            if (target = GetGuardianPet())
                            {
                                // regen mana for pet
                                CastCustomSpell(target,54607,&basepoints0,NULL,NULL,true,castItem,triggeredByAura);
                            }
                            // regen mana for caster
                            CastCustomSpell(this,59117,&basepoints0,NULL,NULL,true,castItem,triggeredByAura);
                            break;
                        }
                    }
                    // health
                    basepoints0 = int32(damage*triggerAmount/100);
                    target = this;
                    triggered_spell_id = 30294;
                    break;
                }
                // Improved Fear
                case 53754:
                {
                    if(!pVictim || !pVictim->isAlive())
                        return false;
                    pVictim->CastSpell(pVictim, 60946,true);
                    return true;
                }
                // Improved Fear (Rank 2)
                case 53759:
                {
                    if(!pVictim || !pVictim->isAlive())
                        return false;
                    pVictim->CastSpell(pVictim, 60947,true);
                    return true;
                }
                // Shadowflame (Voidheart Raiment set bonus)
                case 37377:
                {
                    triggered_spell_id = 37379;
                    break;
                }
                // Pet Healing (Corruptor Raiment or Rift Stalker Armor)
                case 37381:
                {
                    target = GetGuardianPet();
                    if(!target)
                        return false;

                    // heal amount
                    basepoints0 = damage * triggerAmount/100;
                    triggered_spell_id = 37382;
                    break;
                }
                // Shadowflame Hellfire (Voidheart Raiment set bonus)
                case 39437:
                {
                    triggered_spell_id = 37378;
                    break;
                }
            }
            break;
        }
        case SPELLFAMILY_PRIEST:
        {
            // Vampiric Touch
            if( dummySpell->SpellFamilyFlags[1] & 0x00000400 )
            {
                if(!pVictim || !pVictim->isAlive())
                    return false;

                // pVictim is caster of aura
                if(triggeredByAura->GetCasterGUID() != pVictim->GetGUID())
                    return false;

                // energize amount
                basepoints0 = triggerAmount*damage/100;
                pVictim->CastCustomSpell(pVictim,34919,&basepoints0,NULL,NULL,true,castItem,triggeredByAura);
                return true;                                // no hidden cooldown
            }
            // Divine Aegis
            if (dummySpell->SpellIconID == 2820)
            {
                basepoints0 = damage * triggerAmount/100;
                triggered_spell_id = 47753;
                break;
            }
            switch(dummySpell->Id)
            {
                // Vampiric Embrace
                case 15286:
                {
                    if(!pVictim || !pVictim->isAlive())
                        return false;

                    // pVictim is caster of aura
                    if(triggeredByAura->GetCasterGUID() != pVictim->GetGUID())
                        return false;

                    // heal amount
                    int32 team = triggerAmount*damage/500;
                    int32 self = triggerAmount*damage/100 - team;
                    pVictim->CastCustomSpell(pVictim,15290,&team,&self,NULL,true,castItem,triggeredByAura);
                    return true;                                // no hidden cooldown
                }
                // Priest Tier 6 Trinket (Ashtongue Talisman of Acumen)
                case 40438:
                {
                    // Shadow Word: Pain
                    if( procSpell->SpellFamilyFlags[0] & 0x8000 )
                        triggered_spell_id = 40441;
                    // Renew
                    else if( procSpell->SpellFamilyFlags[0] & 0x10 )
                        triggered_spell_id = 40440;
                    else
                        return false;

                    target = this;
                    break;
                }
                // Glyph of Power Word: Shield
                case 55672:
                {
                    basepoints0 = damage * triggerAmount/100;
                    triggered_spell_id = 56160;
                    break;
                }
                // Improved Shadowform
                case 47570:
                case 47569:
                {
                    RemoveAurasByTypeWithDispel(SPELL_AURA_MOD_ROOT);
                    RemoveAurasByTypeWithDispel(SPELL_AURA_MOD_DECREASE_SPEED);
                    break;
                }
                // Psychic Horror
                case 47571:
                {
                    if(!pVictim || !pVictim->isAlive())
                        return false;
                    pVictim->CastSpell(pVictim, 59980,true);
                    return true;
                }
                // Psychic Horror (Rank 2)
                case 47572:
                {
                    if(!pVictim || !pVictim->isAlive())
                        return false;
                    pVictim->CastSpell(pVictim, 59981,true);
                    return true;
                }
                // Glyph of Dispel Magic
                case 55677:
                {
                    // Dispel Magic shares spellfamilyflag with abolish disease
                    if (procSpell->SpellIconID!=74)
                        return false;
                    if(!target->IsFriendlyTo(this))
                        return false;

                    basepoints0 = int32(target->GetMaxHealth() * triggerAmount / 100);
                    triggered_spell_id = 56131;
                    break;
                }
                // Oracle Healing Bonus ("Garments of the Oracle" set)
                case 26169:
                {
                    // heal amount
                    basepoints0 = int32(damage * 10/100);
                    target = this;
                    triggered_spell_id = 26170;
                    break;
                }
                // Frozen Shadoweave (Shadow's Embrace set) warning! its not only priest set
                case 39372:
                {
                    if(!procSpell || (GetSpellSchoolMask(procSpell) & (SPELL_SCHOOL_MASK_FROST | SPELL_SCHOOL_MASK_SHADOW))==0 )
                        return false;

                    // heal amount
                    basepoints0 = damage * triggerAmount/100;
                    target = this;
                    triggered_spell_id = 39373;
                    break;
                }
                // Greater Heal (Vestments of Faith (Priest Tier 3) - 4 pieces bonus)
                case 28809:
                {
                    triggered_spell_id = 28810;
                    break;
                }
            }
            break;
        }
        case SPELLFAMILY_DRUID:
        {
            switch(dummySpell->Id)
            {
                // Leader of the Pack
                case 24932:
                {
                   if (triggerAmount <= 0)
                        return false;
                    basepoints0 = triggerAmount * GetMaxHealth() / 100;
                    target = this;
                    triggered_spell_id = 34299;
                    if (triggeredByAura->GetCaster() != this)
                        break;
                    int32 basepoints1 = triggerAmount * 2;
                    CastCustomSpell(this,60889,&basepoints1,0,0,true,0,triggeredByAura);
                    break;
                }
                // Healing Touch (Dreamwalker Raiment set)
                case 28719:
                {
                    // mana back
                    basepoints0 = int32(procSpell->manaCost * 30 / 100);
                    target = this;
                    triggered_spell_id = 28742;
                    break;
                }
                // Glyph of Rejuvenation
                case 54754:
                {
                    if (pVictim->GetHealth() >= triggerAmount * pVictim->GetMaxHealth()/100)
                        return false;
                    basepoints0 = int32(triggerAmount * damage / 100);
                    triggered_spell_id = 54755;
                    break;
                }
                // Healing Touch Refund (Idol of Longevity trinket)
                case 28847:
                {
                    target = this;
                    triggered_spell_id = 28848;
                    break;
                }
                // Mana Restore (Malorne Raiment set / Malorne Regalia set)
                case 37288:
                case 37295:
                {
                    target = this;
                    triggered_spell_id = 37238;
                    break;
                }
                // Druid Tier 6 Trinket
                case 40442:
                {
                    float  chance;

                    // Starfire
                    if( procSpell->SpellFamilyFlags[0] & 0x4 )
                    {
                        triggered_spell_id = 40445;
                        chance = 25.f;
                    }
                    // Rejuvenation
                    else if( procSpell->SpellFamilyFlags[0] & 0x10 )
                    {
                        triggered_spell_id = 40446;
                        chance = 25.f;
                    }
                    // Mangle (cat/bear)
                    else if( procSpell->SpellFamilyFlags[1] & 0x00000440)
                    {
                        triggered_spell_id = 40452;
                        chance = 40.f;
                    }
                    else
                        return false;

                    if (!roll_chance_f(chance))
                        return false;

                    target = this;
                    break;
                }
                // Maim Interrupt
                case 44835:
                {
                    // Deadly Interrupt Effect
                    triggered_spell_id = 32747;
                    break;
                }
            }
            // Eclipse
            if (dummySpell->SpellIconID == 2856)
            {
                if (!procSpell)
                    return false;
                // Only 0 aura can proc
                if (effIndex!=0)
                    return false;
                // Wrath crit
                if (procSpell->SpellFamilyFlags[0] & 0x1)
                {
                    if (!roll_chance_i(60))
                        return false;
                    triggered_spell_id = 48518;
                    target = this;
                    break;
                }
                // Starfire crit
                if (procSpell->SpellFamilyFlags[0] & 0x4)
                {
                    triggered_spell_id = 48517;
                    target = this;
                    break;
                }
                return false;
            }
            // Living Seed
            else if (dummySpell->SpellIconID == 2860)
            {
                triggered_spell_id = 48504;
                basepoints0 = triggerAmount * damage / 100;
                break;
            }
            break;
        }
        case SPELLFAMILY_ROGUE:
        {
            switch(dummySpell->Id)
            {
                // Deadly Throw Interrupt
                case 32748:
                {
                    // Prevent cast Deadly Throw Interrupt on self from last effect (apply dummy) of Deadly Throw
                    if(this == pVictim)
                        return false;

                    triggered_spell_id = 32747;
                    break;
                }
            }
            // Cut to the Chase
            if( dummySpell->SpellIconID == 2909 )
            {
                // "refresh your Slice and Dice duration to its 5 combo point maximum"
                // lookup Slice and Dice
                if (AuraEffect * aur = GetAura(SPELL_AURA_MOD_HASTE, SPELLFAMILY_ROGUE,0x40000, 0, 0))
                {
                    aur->GetParentAura()->SetAuraDuration(GetSpellMaxDuration(aur->GetSpellProto()));
                    return true;
                }
                return false;
            }
            // Deadly Brew
            else if( dummySpell->SpellIconID == 2963 )
            {
                triggered_spell_id = 3409;
                break;
            }
            // Quick Recovery
            else if( dummySpell->SpellIconID == 2116 )
            {
                if(!procSpell)
                    return false;

                // energy cost save
                basepoints0 = procSpell->manaCost * triggerAmount/100;
                if(basepoints0 <= 0)
                    return false;

                target = this;
                triggered_spell_id = 31663;
                break;
            }
            break;
        }
        case SPELLFAMILY_HUNTER:
        {
            // Thrill of the Hunt
            if ( dummySpell->SpellIconID == 2236 )
            {
                if(!procSpell)
                    return false;

                // mana cost save
                int32 mana = procSpell->manaCost + procSpell->ManaCostPercentage * GetCreateMana() / 100;
                basepoints0 = mana * 40/100;
                if(basepoints0 <= 0)
                    return false;

                target = this;
                triggered_spell_id = 34720;
                break;
            }
            // Hunting Party
            if ( dummySpell->SpellIconID == 3406 )
            {
                triggered_spell_id = 57669;
                target = this;
                break;
            }
            // Lock and Load
            if ( dummySpell->SpellIconID == 3579 )
            {
                // Proc only from periodic (from trap activation proc another aura of this spell)
                if (!(procFlag & PROC_FLAG_ON_DO_PERIODIC) || !roll_chance_i(triggerAmount))
                    return false;
                triggered_spell_id = 56453;
                target = this;
                break;
            }
            // Rapid Recuperation
            if ( dummySpell->SpellIconID == 3560 )
            {
                // This effect only from Rapid Killing (mana regen)
                if (!(procSpell->SpellFamilyFlags[1] & 0x01000000))
                    return false;
                triggered_spell_id = 56654;
                target = this;
                break;
            }
            break;
        }
        case SPELLFAMILY_PALADIN:
        {
            // Seal of Righteousness - melee proc dummy (addition ${$MWS*(0.022*$AP+0.044*$SPH)} damage)
            if (dummySpell->SpellFamilyFlags[0]&0x8000000)
            {
                if (effIndex!=0)
                    return false;
                triggered_spell_id = 25742;
                float ap = GetTotalAttackPowerValue(BASE_ATTACK);
                int32 holy = SpellBaseDamageBonus(SPELL_SCHOOL_MASK_HOLY) +
                             SpellBaseDamageBonusForVictim(SPELL_SCHOOL_MASK_HOLY, pVictim);
                basepoints0 = GetAttackTime(BASE_ATTACK) * int32(ap*0.022f + 0.044f * holy) / 1000;
                break;
            }
            // Light's Beacon - Beacon of Light
            if ( dummySpell->Id == 53651 )
            {
                if (Unit * caster = triggeredByAura->GetCaster())
                {
                    // do not proc when target of beacon of light is healed
                    if (caster == pVictim)
                        return false;
                    if (Aura * aur = caster->GetAura(53563))
                    {
                        if (Unit * paladin = aur->GetCaster())
                        {
                            if (paladin != this)
                                return false;
                            basepoints0 = damage;
                            triggered_spell_id = 53654;
                            target = caster;
                            break;
                        }
                        else
                        {
                            pVictim->RemoveAura(triggeredByAura->GetParentAura());
                            return false;
                        }
                    }
                }
                else return false;
            }
            // Judgements of the Wise
            if (dummySpell->SpellIconID == 3017)
            {
                // hardcoded amount
                basepoints0 = 15 * GetCreatePowers(POWER_MANA)/100;
                target = this;
                triggered_spell_id = 31930;
                // replenishment
                CastSpell(this,57669,true);
                break;
            }
            // Sanctified Wrath
            if (dummySpell->SpellIconID == 3029)
            {
                triggered_spell_id = 57318;
                target = this;
                basepoints0 = triggerAmount;
                CastCustomSpell(target,triggered_spell_id,&basepoints0,&basepoints0,NULL,true,castItem,triggeredByAura);
                return true;
            }
            // Sacred Shield
            if (dummySpell->SpellFamilyFlags[1]&0x00080000)
            {
                triggered_spell_id = 58597;
                target = this;
                break;
            }
            // Righteous Vengeance
            if (dummySpell->SpellIconID == 3025)
            {
                // 4 damage tick
                basepoints0 = triggerAmount*damage/400;
                triggered_spell_id = 61840;
                break;
            }
            // Sheath of Light
            if (dummySpell->SpellIconID == 3030)
            {
                // 4 healing tick
                basepoints0 = triggerAmount*damage/400;
                triggered_spell_id = 54203;
                break;
            }
            switch(dummySpell->Id)
            {
                // Judgement of Light
                case 20185:
                {
                    // Get judgement caster
                    Unit *caster = triggeredByAura->GetCaster();
                    if (!caster)
                        return false;
                    float ap   = caster->GetTotalAttackPowerValue(BASE_ATTACK);
                    int32 holy = caster->SpellBaseDamageBonus(SPELL_SCHOOL_MASK_HOLY) +
                                 caster->SpellBaseDamageBonusForVictim(SPELL_SCHOOL_MASK_HOLY, this);
                    basepoints0 = int32(ap*0.10f + 0.10f*holy);
                    pVictim->CastCustomSpell(pVictim, 20267, &basepoints0, 0, 0, true, 0, triggeredByAura);
                    return true;
                }
                // Judgement of Wisdom
                case 20186:
                {
                    pVictim->CastSpell(pVictim, 20268, true, NULL, triggeredByAura);
                    return true;
                }
                // Holy Power (Redemption Armor set)
                case 28789:
                {
                    if(!pVictim)
                        return false;

                    // Set class defined buff
                    switch (pVictim->getClass())
                    {
                        case CLASS_PALADIN:
                        case CLASS_PRIEST:
                        case CLASS_SHAMAN:
                        case CLASS_DRUID:
                            triggered_spell_id = 28795;     // Increases the friendly target's mana regeneration by $s1 per 5 sec. for $d.
                            break;
                        case CLASS_MAGE:
                        case CLASS_WARLOCK:
                            triggered_spell_id = 28793;     // Increases the friendly target's spell damage and healing by up to $s1 for $d.
                            break;
                        case CLASS_HUNTER:
                        case CLASS_ROGUE:
                            triggered_spell_id = 28791;     // Increases the friendly target's attack power by $s1 for $d.
                            break;
                        case CLASS_WARRIOR:
                            triggered_spell_id = 28790;     // Increases the friendly target's armor
                            break;
                        default:
                            return false;
                    }
                    break;
                }
                // Seal of Vengeance (damage calc on apply aura)
                case 31801:
                {
                    if(effIndex != 0)                       // effect 1,2 used by seal unleashing code
                        return false;

                    triggered_spell_id = 31803;
                    break;
                }
                // Seal of Corruption
                case 53736:
                {
                    if(effIndex != 0)                       // effect 1,2 used by seal unleashing code
                        return false;

                    triggered_spell_id = 53742;
                    break;
                }
                // Spiritual Attunement
                case 31785:
                case 33776:
                {
                    // if healed by another unit (pVictim)
                    if(this == pVictim)
                        return false;

                    // heal amount
                    basepoints0 = triggerAmount*damage/100;
                    target = this;
                    triggered_spell_id = 31786;
                    break;
                }
                // Seal of Blood do damage trigger
                case 31892:
                {
                    if (effIndex == 0)       // 0 effect - is proc on enemy
                        triggered_spell_id = 31893;
                    else if (effIndex == 1)  // 1 effect - is proc on self
                    {
                        // add spell damage from prev effect (27%)
                        damage += CalculateDamage(BASE_ATTACK, false) * 27 / 100;
                        basepoints0 =  triggerAmount * damage / 100;
                        target = this;
                        triggered_spell_id = 32221;
                    }
                    else
                        return false;
                    break;
                }
                // Seal of the Martyr do damage trigger
                case 53720:
                {
                    if (effIndex == 0)      // 0 effect - is proc on enemy
                        triggered_spell_id = 53719;
                    else if (effIndex == 1) // 1 effect - is proc on self
                    {
                        // add spell damage from prev effect (27%)
                        damage += CalculateDamage(BASE_ATTACK, false) * 27 / 100;
                        basepoints0 =  triggerAmount * damage / 100;
                        target = this;
                        triggered_spell_id = 53718;
                    }
                    else
                        return false;
                    break;
                }
                // Paladin Tier 6 Trinket (Ashtongue Talisman of Zeal)
                case 40470:
                {
                    if( !procSpell )
                        return false;

                    float  chance;

                    // Flash of light/Holy light
                    if( procSpell->SpellFamilyFlags[0] & 0xC0000000)
                    {
                        triggered_spell_id = 40471;
                        chance = 15.f;
                    }
                    // Judgement
                    else if( procSpell->SpellFamilyFlags[0] & 0x800000 )
                    {
                        triggered_spell_id = 40472;
                        chance = 50.f;
                    }
                    else
                        return false;

                    if (!roll_chance_f(chance))
                        return false;

                    break;
                }
                // Glyph of Divinity
                case 54939:
                {
                    // Lookup base amount mana restore
                    for (int i=0; i<3;i++)
                        if (procSpell->Effect[i] == SPELL_EFFECT_ENERGIZE)
                        {
                            int32 mana = procSpell->EffectBasePoints[i];
                            CastCustomSpell(this, 54986, 0, &mana, 0, true, castItem, triggeredByAura);
                            break;
                        }
                    return true;
                }
                // Glyph of Flash of Light
                case 54936:
                {
                    triggered_spell_id = 54957;
                    basepoints0 = triggerAmount*damage/100;
                    break;
                }
                // Glyph of Holy Light
                case 54937:
                {
                    triggered_spell_id = 54968;
                    basepoints0 = triggerAmount*damage/100;
                    break;
                }
            }
            break;
        }
        case SPELLFAMILY_SHAMAN:
        {
            switch(dummySpell->Id)
            {
                // Improved fire nova totem
                case 16544:
                {
                    triggered_spell_id = 51880;
                    break;
                }
                // Tidal Force
                case 55198:
                {
                    // Remove aura stack from  caster
                    RemoveAuraFromStack(55166);
                    // drop charges
                    return false;
                }
                // Totemic Power (The Earthshatterer set)
                case 28823:
                {
                    if( !pVictim )
                        return false;

                    // Set class defined buff
                    switch (pVictim->getClass())
                    {
                        case CLASS_PALADIN:
                        case CLASS_PRIEST:
                        case CLASS_SHAMAN:
                        case CLASS_DRUID:
                            triggered_spell_id = 28824;     // Increases the friendly target's mana regeneration by $s1 per 5 sec. for $d.
                            break;
                        case CLASS_MAGE:
                        case CLASS_WARLOCK:
                            triggered_spell_id = 28825;     // Increases the friendly target's spell damage and healing by up to $s1 for $d.
                            break;
                        case CLASS_HUNTER:
                        case CLASS_ROGUE:
                            triggered_spell_id = 28826;     // Increases the friendly target's attack power by $s1 for $d.
                            break;
                        case CLASS_WARRIOR:
                            triggered_spell_id = 28827;     // Increases the friendly target's armor
                            break;
                        default:
                            return false;
                    }
                    break;
                }
                // Lesser Healing Wave (Totem of Flowing Water Relic)
                case 28849:
                {
                    target = this;
                    triggered_spell_id = 28850;
                    break;
                }
                // Windfury Weapon (Passive) 1-5 Ranks
                case 33757:
                {
                    if(GetTypeId()!=TYPEID_PLAYER)
                        return false;

                    if(!castItem || !castItem->IsEquipped())
                        return false;

                    // custom cooldown processing case
                    if( cooldown && ((Player*)this)->HasSpellCooldown(dummySpell->Id))
                        return false;

                    // Now amount of extra power stored in 1 effect of Enchant spell
                    // Get it by item enchant id
                    uint32 spellId;
                    switch (castItem->GetEnchantmentId(EnchantmentSlot(TEMP_ENCHANTMENT_SLOT)))
                    {
                        case 283: spellId =  8232; break;   // 1 Rank
                        case 284: spellId =  8235; break;   // 2 Rank
                        case 525: spellId = 10486; break;   // 3 Rank
                        case 1669:spellId = 16362; break;   // 4 Rank
                        case 2636:spellId = 25505; break;   // 5 Rank
                        case 3785:spellId = 58801; break;   // 6 Rank
                        case 3786:spellId = 58803; break;   // 7 Rank
                        case 3787:spellId = 58804; break;   // 8 Rank
                        default:
                        {
                            sLog.outError("Unit::HandleDummyAuraProc: non handled item enchantment (rank?) %u for spell id: %u (Windfury)",
                                castItem->GetEnchantmentId(EnchantmentSlot(TEMP_ENCHANTMENT_SLOT)),dummySpell->Id);
                            return false;
                        }
                    }

                    SpellEntry const* windfurySpellEntry = sSpellStore.LookupEntry(spellId);
                    if(!windfurySpellEntry)
                    {
                        sLog.outError("Unit::HandleDummyAuraProc: non existed spell id: %u (Windfury)",spellId);
                        return false;
                    }

                    int32 extra_attack_power = CalculateSpellDamage(windfurySpellEntry, 1, windfurySpellEntry->EffectBasePoints[1], pVictim);

                    // Off-Hand case
                    if ( castItem->GetSlot() == EQUIPMENT_SLOT_OFFHAND )
                    {
                        // Value gained from additional AP
                        basepoints0 = int32(extra_attack_power/14.0f * GetAttackTime(OFF_ATTACK)/1000/2);
                        triggered_spell_id = 33750;
                    }
                    // Main-Hand case
                    else
                    {
                        // Value gained from additional AP
                        basepoints0 = int32(extra_attack_power/14.0f * GetAttackTime(BASE_ATTACK)/1000);
                        triggered_spell_id = 25504;
                    }

                    // apply cooldown before cast to prevent processing itself
                    if( cooldown )
                        ((Player*)this)->AddSpellCooldown(dummySpell->Id,0,time(NULL) + cooldown);

                    // Attack Twice
                    for ( uint32 i = 0; i<2; ++i )
                        CastCustomSpell(pVictim,triggered_spell_id,&basepoints0,NULL,NULL,true,castItem,triggeredByAura);

                    return true;
                }
                // Shaman Tier 6 Trinket
                case 40463:
                {
                    if( !procSpell )
                        return false;

                    float  chance;
                    if (procSpell->SpellFamilyFlags[0] & 0x1)
                    {
                        triggered_spell_id = 40465;         // Lightning Bolt
                        chance = 15.f;
                    }
                    else if (procSpell->SpellFamilyFlags[0] & 0x80)
                    {
                        triggered_spell_id = 40465;         // Lesser Healing Wave
                        chance = 10.f;
                    }
                    else if (procSpell->SpellFamilyFlags[1] & 0x00000010)
                    {
                        triggered_spell_id = 40466;         // Stormstrike
                        chance = 50.f;
                    }
                    else
                        return false;

                    if (!roll_chance_f(chance))
                        return false;

                    target = this;
                    break;
                }
                // Glyph of Healing Wave
                case 55440:
                {
                    // Not proc from self heals
                    if (this==pVictim)
                        return false;
                    basepoints0 = triggerAmount * damage / 100;
                    target = this;
                    triggered_spell_id = 55533;
                    break;
                }
                // Spirit Hunt
                case 58877:
                {
                    // Cast on owner
                    target = GetOwner();
                    if(!target)
                        return false;
                    basepoints0 = triggerAmount * damage / 100;
                    triggered_spell_id = 58879;
                    break;
                }
            }
            // Ancestral Awakening
            if (dummySpell->SpellIconID == 3065)
            {
                // TODO: frite dummy fot triggered spell
                triggered_spell_id = 52759;
                basepoints0 = triggerAmount * damage / 100;
                target = this;
                break;
            }
            // Earth Shield
            if(dummySpell->SpellFamilyFlags[1] & 0x00000400)
            {
                basepoints0 = triggerAmount;
                target = this;
                triggered_spell_id = 379;
                break;
            }
            // Improved Water Shield
            if (dummySpell->SpellIconID == 2287)
            {
                // Lesser Healing Wave need aditional 60% roll
                if (procSpell->SpellFamilyFlags[0] & 0x80 && !roll_chance_i(60))
                    return false;
                // lookup water shield
                AuraEffectList const& vs = GetAurasByType(SPELL_AURA_PROC_TRIGGER_SPELL);
                for(AuraEffectList::const_iterator itr = vs.begin(); itr != vs.end(); ++itr)
                {
                    if( (*itr)->GetSpellProto()->SpellFamilyName == SPELLFAMILY_SHAMAN &&
                        (*itr)->GetSpellProto()->SpellFamilyFlags[1] & 0x00000020)
                    {
                        uint32 spell = (*itr)->GetSpellProto()->EffectTriggerSpell[(*itr)->GetEffIndex()];
                        CastSpell(this, spell, true, castItem, triggeredByAura);
                        (*itr)->GetParentAura()->DropAuraCharge();
                        return true;
                    }
                }
                return false;
                break;
            }
            // Lightning Overload
            if (dummySpell->SpellIconID == 2018)            // only this spell have SpellFamily Shaman SpellIconID == 2018 and dummy aura
            {
                if(!procSpell || GetTypeId() != TYPEID_PLAYER || !pVictim )
                    return false;

                // custom cooldown processing case
                if( cooldown && GetTypeId()==TYPEID_PLAYER && ((Player*)this)->HasSpellCooldown(dummySpell->Id))
                    return false;

                uint32 spellId = 0;
                // Every Lightning Bolt and Chain Lightning spell have duplicate vs half damage and zero cost
                switch (procSpell->Id)
                {
                    // Lightning Bolt
                    case   403: spellId = 45284; break;     // Rank  1
                    case   529: spellId = 45286; break;     // Rank  2
                    case   548: spellId = 45287; break;     // Rank  3
                    case   915: spellId = 45288; break;     // Rank  4
                    case   943: spellId = 45289; break;     // Rank  5
                    case  6041: spellId = 45290; break;     // Rank  6
                    case 10391: spellId = 45291; break;     // Rank  7
                    case 10392: spellId = 45292; break;     // Rank  8
                    case 15207: spellId = 45293; break;     // Rank  9
                    case 15208: spellId = 45294; break;     // Rank 10
                    case 25448: spellId = 45295; break;     // Rank 11
                    case 25449: spellId = 45296; break;     // Rank 12
                    case 49237: spellId = 49239; break;     // Rank 13
                    case 49238: spellId = 49240; break;     // Rank 14
                    // Chain Lightning
                    case   421: spellId = 45297; break;     // Rank  1
                    case   930: spellId = 45298; break;     // Rank  2
                    case  2860: spellId = 45299; break;     // Rank  3
                    case 10605: spellId = 45300; break;     // Rank  4
                    case 25439: spellId = 45301; break;     // Rank  5
                    case 25442: spellId = 45302; break;     // Rank  6
                    case 49268: spellId = 49270; break;     // Rank  7
                    case 49269: spellId = 49271; break;     // Rank  8
                    default:
                        sLog.outError("Unit::HandleDummyAuraProc: non handled spell id: %u (LO)", procSpell->Id);
                        return false;
                }
                // Remove cooldown (Chain Lightning - have Category Recovery time)
                if (procSpell->SpellFamilyFlags[0] & 0x2)
                    ((Player*)this)->RemoveSpellCooldown(spellId);

                // do not reduce damage-spells have correct basepoints
                int32 mod = 0;

                // Apply spellmod
                CastCustomSpell(this, 39805, NULL, &mod, NULL, true, castItem, triggeredByAura);

                CastSpell(pVictim, spellId, true, castItem, triggeredByAura);

                if( cooldown && GetTypeId()==TYPEID_PLAYER )
                    ((Player*)this)->AddSpellCooldown(dummySpell->Id,0,time(NULL) + cooldown);

                return true;
            }
            // Static Shock
            if(dummySpell->SpellIconID == 3059)
            {
                // lookup Lightning Shield
                AuraEffectList const& vs = GetAurasByType(SPELL_AURA_PROC_TRIGGER_SPELL);
                for(AuraEffectList::const_iterator itr = vs.begin(); itr != vs.end(); ++itr)
                {
                    if( (*itr)->GetSpellProto()->SpellFamilyName == SPELLFAMILY_SHAMAN &&
                        (*itr)->GetSpellProto()->SpellFamilyFlags[0] & 0x400)
                    {
                        uint32 spell = 0;
                        switch ((*itr)->GetId())
                        {
                            case   324: spell = 26364; break;
                            case   325: spell = 26365; break;
                            case   905: spell = 26366; break;
                            case   945: spell = 26367; break;
                            case  8134: spell = 26369; break;
                            case 10431: spell = 26370; break;
                            case 10432: spell = 26363; break;
                            case 25469: spell = 26371; break;
                            case 25472: spell = 26372; break;
                            case 49280: spell = 49278; break;
                            case 49281: spell = 49279; break;
                            default:
                                return false;
                        }
                        CastSpell(this, spell, true, castItem, triggeredByAura);
                        (*itr)->GetParentAura()->DropAuraCharge();
                        return true;
                    }
                }
                return false;
                break;
            }
            break;
        }
        case SPELLFAMILY_DEATHKNIGHT:
        {
            // Blood Aura
            if (dummySpell->SpellIconID == 2636)
            {
                if (GetTypeId() != TYPEID_PLAYER || !((Player*)this)->isHonorOrXPTarget(pVictim))
                    return false;
                basepoints0 = triggerAmount * damage / 100;
                triggered_spell_id = 53168;
                break;
            }
            // Butchery
            if (dummySpell->SpellIconID == 2664)
            {
                basepoints0 = triggerAmount;
                triggered_spell_id = 50163;
                target = this;
                break;
            }
            // Dancing Rune Weapon
            if (dummySpell->Id == 49028)
            {
                // 1 dummy aura for dismiss rune blade
                if (effIndex!=2)
                    return false;
                // TODO: wite script for this "fights on its own, doing the same attacks"
                // NOTE: Trigger here on every attack and spell cast
                return false;
            }
            // Mark of Blood
            if (dummySpell->Id == 49005)
            {
                // TODO: need more info (cooldowns/PPM)
                triggered_spell_id = 50424;
                break;
            }
            // Vendetta
            if (dummySpell->SpellFamilyFlags[0] & 0x10000)
            {
                basepoints0 = triggerAmount * GetMaxHealth() / 100;
                triggered_spell_id = 50181;
                target = this;
                break;
            }
            // Necrosis
            if (dummySpell->SpellIconID == 2709)
            {
                basepoints0 = triggerAmount * damage / 100;
                triggered_spell_id = 51460;
                break;
            }
            // Runic Power Back on Snare/Root
            if (dummySpell->Id == 61257)
            {
                // only for spells and hit/crit (trigger start always) and not start from self casted spells
                if (procSpell == 0 || !(procEx & (PROC_EX_NORMAL_HIT|PROC_EX_CRITICAL_HIT)) || this == pVictim)
                    return false;
                // Need snare or root mechanic
                if (!(GetAllSpellMechanicMask(procSpell) & ((1<<MECHANIC_ROOT)|(1<<MECHANIC_SNARE))))
                    return false;
                triggered_spell_id = 61258;
                target = this;
                break;
            }
            // Wandering Plague
            if (dummySpell->SpellIconID == 1614)
            {
                if (!roll_chance_f(GetUnitCriticalChance(BASE_ATTACK, pVictim)))
                    return false;
                basepoints0 = triggerAmount * damage / 100;
                triggered_spell_id = 50526;
                break;
            }
            // Death Strike healing effect
            if (dummySpell->Id == 45469)
            {
                uint8 n=0;
                Unit::AuraEffectList const& decSpeedList = pVictim->GetAurasByType(SPELL_AURA_PERIODIC_DAMAGE);
                for(Unit::AuraEffectList::const_iterator iter = decSpeedList.begin(); iter != decSpeedList.end(); ++iter)
                {
                    if((*iter)->GetSpellProto()->SpellFamilyName==SPELLFAMILY_DEATHKNIGHT
                        && (*iter)->GetCasterGUID() == GetGUID()
                        && (*iter)->GetSpellProto()->Dispel == DISPEL_DISEASE)
                    {
                       n++;
                    }
                }
                int32 heal=0.5f*n*damage+damage;
                CastCustomSpell(this,45470,&heal,NULL,NULL,true);
                return true;
            }
            break;
        }
        case SPELLFAMILY_POTION:
        {
            // alchemist's stone
            if (dummySpell->Id == 17619)
            {
                if (procSpell->SpellFamilyName == SPELLFAMILY_POTION)
                {
                    for (uint8 i=0;i<3;i++)
                    {
                        if (procSpell->Effect[i]==SPELL_EFFECT_HEAL)
                        {
                            triggered_spell_id = 21399;
                        }
                        else if (procSpell->Effect[i]==SPELL_EFFECT_ENERGIZE)
                        {
                            triggered_spell_id = 21400;
                        }
                        else
                            continue;

                        basepoints0 = CalculateSpellDamage(procSpell,i,procSpell->EffectBasePoints[i],this) * 0.4f;
                        CastCustomSpell(this,triggered_spell_id,&basepoints0,NULL,NULL,true,NULL,triggeredByAura);
                    }
                    return true;
                }
            }
            break;
        }
         case SPELLFAMILY_PET:
        {
            // improved cower
            if (dummySpell->SpellIconID == 958 && procSpell->SpellIconID == 958)
            {
                triggered_spell_id = dummySpell->Id == 53180 ? 54200 : 54201;
                target = this;
                break;
            }
            // guard dog
            if (dummySpell->SpellIconID == 201 && procSpell->SpellIconID == 201)
            {
                triggered_spell_id = 54445;
                target = this;
                pVictim->AddThreat(this,procSpell->EffectBasePoints[0]*triggerAmount/100);
                break;
            }
            break;
        }
        default:
            break;
    }

    // processed charge only counting case
    if(!triggered_spell_id)
        return true;

    SpellEntry const* triggerEntry = sSpellStore.LookupEntry(triggered_spell_id);

    if(!triggerEntry)
    {
        sLog.outError("Unit::HandleDummyAuraProc: Spell %u have not existed triggered spell %u",dummySpell->Id,triggered_spell_id);
        return false;
    }

    // default case
    if(!target || target!=this && !target->isAlive())
        return false;

    if( cooldown && GetTypeId()==TYPEID_PLAYER && ((Player*)this)->HasSpellCooldown(triggered_spell_id))
        return false;

    if(basepoints0)
        CastCustomSpell(target,triggered_spell_id,&basepoints0,NULL,NULL,true,castItem,triggeredByAura);
    else
        CastSpell(target,triggered_spell_id,true,castItem,triggeredByAura);

    if( cooldown && GetTypeId()==TYPEID_PLAYER )
        ((Player*)this)->AddSpellCooldown(triggered_spell_id,0,time(NULL) + cooldown);

    return true;
}

bool Unit::HandleObsModEnergyAuraProc(Unit *pVictim, uint32 damage, AuraEffect* triggeredByAura, SpellEntry const * procSpell, uint32 procFlag, uint32 procEx, uint32 cooldown)
{
    SpellEntry const *dummySpell = triggeredByAura->GetSpellProto ();
    uint32 effIndex = triggeredByAura->GetEffIndex();
    int32  triggerAmount = triggeredByAura->GetAmount();

    Item* castItem = triggeredByAura->GetParentAura()->GetCastItemGUID() && GetTypeId()==TYPEID_PLAYER
        ? ((Player*)this)->GetItemByGuid(triggeredByAura->GetParentAura()->GetCastItemGUID()) : NULL;

    uint32 triggered_spell_id = 0;
    Unit* target = pVictim;
    int32 basepoints0 = 0;

    switch(dummySpell->SpellFamilyName)
    {
        case SPELLFAMILY_HUNTER:
        {
            // Aspect of the Viper
            if ( dummySpell->SpellFamilyFlags[1] & 0x40000 )
            {
                uint32 maxmana = GetMaxPower(POWER_MANA);
                basepoints0 = maxmana* GetAttackTime(RANGED_ATTACK)/1000.0f/100.0f;

                target = this;
                triggered_spell_id = 34075;
                break;
            }
            break;
        }
    }
    // processed charge only counting case
    if(!triggered_spell_id)
        return true;

    SpellEntry const* triggerEntry = sSpellStore.LookupEntry(triggered_spell_id);

    if(!triggerEntry)
    {
        sLog.outError("Unit::HandleObsModEnergyAuraProc: Spell %u have not existed triggered spell %u",dummySpell->Id,triggered_spell_id);
        return false;
    }

    // default case
    if(!target || target!=this && !target->isAlive())
        return false;

    if( cooldown && GetTypeId()==TYPEID_PLAYER && ((Player*)this)->HasSpellCooldown(triggered_spell_id))
        return false;

    if(basepoints0)
        CastCustomSpell(target,triggered_spell_id,&basepoints0,NULL,NULL,true,castItem,triggeredByAura);
    else
        CastSpell(target,triggered_spell_id,true,castItem,triggeredByAura);

    if( cooldown && GetTypeId()==TYPEID_PLAYER )
        ((Player*)this)->AddSpellCooldown(triggered_spell_id,0,time(NULL) + cooldown);

    return true;
}

bool Unit::HandleModDamagePctTakenAuraProc(Unit *pVictim, uint32 damage, AuraEffect* triggeredByAura, SpellEntry const * procSpell, uint32 procFlag, uint32 procEx, uint32 cooldown)
{
    SpellEntry const *dummySpell = triggeredByAura->GetSpellProto ();
    uint32 effIndex = triggeredByAura->GetEffIndex();
    int32  triggerAmount = triggeredByAura->GetAmount();

    Item* castItem = triggeredByAura->GetParentAura()->GetCastItemGUID() && GetTypeId()==TYPEID_PLAYER
        ? ((Player*)this)->GetItemByGuid(triggeredByAura->GetParentAura()->GetCastItemGUID()) : NULL;

    uint32 triggered_spell_id = 0;
    Unit* target = pVictim;
    int32 basepoints0 = 0;

    switch(dummySpell->SpellFamilyName)
    {
        case SPELLFAMILY_PALADIN:
        {
            // Blessing of Sanctuary
            if ( dummySpell->SpellFamilyFlags[0] & 0x10000000 )
            {
                switch (getPowerType())
                {
                    case POWER_MANA:   triggered_spell_id = 57319; break;
                    case POWER_RAGE:   triggered_spell_id = 57320; break;
                    case POWER_RUNIC_POWER: triggered_spell_id = 57321; break;
                    default:
                        return false;
                }
            }
            break;
        }
    }
    // processed charge only counting case
    if(!triggered_spell_id)
        return true;

    SpellEntry const* triggerEntry = sSpellStore.LookupEntry(triggered_spell_id);

    if(!triggerEntry)
    {
        sLog.outError("Unit::HandleModDamagePctTakenAuraProc: Spell %u have not existed triggered spell %u",dummySpell->Id,triggered_spell_id);
        return false;
    }

    // default case
    if(!target || target!=this && !target->isAlive())
        return false;

    if( cooldown && GetTypeId()==TYPEID_PLAYER && ((Player*)this)->HasSpellCooldown(triggered_spell_id))
        return false;

    if(basepoints0)
        CastCustomSpell(target,triggered_spell_id,&basepoints0,NULL,NULL,true,castItem,triggeredByAura);
    else
        CastSpell(target,triggered_spell_id,true,castItem,triggeredByAura);

    if( cooldown && GetTypeId()==TYPEID_PLAYER )
        ((Player*)this)->AddSpellCooldown(triggered_spell_id,0,time(NULL) + cooldown);

    return true;
}

bool Unit::HandleProcTriggerSpell(Unit *pVictim, uint32 damage, AuraEffect* triggeredByAura, SpellEntry const *procSpell, uint32 procFlags, uint32 procEx, uint32 cooldown)
{
    // Get triggered aura spell info
    SpellEntry const* auraSpellInfo = triggeredByAura->GetSpellProto();

    // Basepoints of trigger aura
    int32 triggerAmount = triggeredByAura->GetAmount();

    // Set trigger spell id, target, custom basepoints
    uint32 trigger_spell_id = auraSpellInfo->EffectTriggerSpell[triggeredByAura->GetEffIndex()];
    Unit*  target = NULL;
    int32  basepoints0 = 0;

    if(triggeredByAura->GetAuraName() == SPELL_AURA_PROC_TRIGGER_SPELL_WITH_VALUE)
        basepoints0 = triggerAmount;

    Item* castItem = triggeredByAura->GetParentAura()->GetCastItemGUID() && GetTypeId()==TYPEID_PLAYER
        ? ((Player*)this)->GetItemByGuid(triggeredByAura->GetParentAura()->GetCastItemGUID()) : NULL;

    // Try handle unknown trigger spells
    if (sSpellStore.LookupEntry(trigger_spell_id)==NULL)
    {
        switch (auraSpellInfo->SpellFamilyName)
        {
            case SPELLFAMILY_GENERIC:
                //if (auraSpellInfo->Id==59532)             // Abandon Passengers on Poly
                //if (auraSpellInfo->Id==54775)             // Abandon Vehicle on Poly
                //if (auraSpellInfo->Id==34082)             // Advantaged State (DND)
                if (auraSpellInfo->Id == 23780)             // Aegis of Preservation (Aegis of Preservation trinket)
                    trigger_spell_id = 23781;
                //else if (auraSpellInfo->Id==43504)        // Alterac Valley OnKill Proc Aura
                //else if (auraSpellInfo->Id == 48876)      // Beast's Mark
                //{
                //    trigger_spell_id = 48877;
                //}
                //else if (auraSpellInfo->Id == 59237)      // Beast's Mark
                //{
                //    trigger_spell_id = 59233;
                //}
                //else if (auraSpellInfo->Id==46939)        // Black Bow of the Betrayer
                //{
                //    trigger_spell_id = 29471;             // gain mana
                //                       27526;             // drain mana if possible
                //}
                //else if (auraSpellInfo->Id==50844)        // Blood Mirror
                //else if (auraSpellInfo->Id==54476)        // Blood Presence
                //else if (auraSpellInfo->Id==50689)        // Blood Presence (Rank 1)
                //else if (auraSpellInfo->Id==37030)        // Chaotic Temperament
                //else if (auraSpellInfo->Id==52856)        // Charge
                else if (auraSpellInfo->Id==43820)          // Charm of the Witch Doctor (Amani Charm of the Witch Doctor trinket)
                {
                    // Pct value stored in dummy
                    basepoints0 = pVictim->GetCreateHealth() * auraSpellInfo->EffectBasePoints[1] / 100;
                    target = pVictim;
                    break;
                }
                //else if (auraSpellInfo->Id==41248)        // Consuming Strikes
                //    trigger_spell_id = 41249;
                //else if (auraSpellInfo->Id==45205)        // Copy Offhand Weapon
                //else if (auraSpellInfo->Id==57594)        // Copy Ranged Weapon
                //else if (auraSpellInfo->Id==41054)        // Copy Weapon
                //    trigger_spell_id = 41055;
                //else if (auraSpellInfo->Id==45343)        // Dark Flame Aura
                //else if (auraSpellInfo->Id==47300)        // Dark Flame Aura
                else if (auraSpellInfo->Id==57345)          // Darkmoon Card: Greatness
                {
                    float stat = 0.0f;
                    // strength
                    if (GetStat(STAT_STRENGTH) > stat) { trigger_spell_id = 60229;stat = GetStat(STAT_STRENGTH); }
                    // agility
                    if (GetStat(STAT_AGILITY)  > stat) { trigger_spell_id = 60233;stat = GetStat(STAT_AGILITY);  }
                    // intellect
                    if (GetStat(STAT_INTELLECT)> stat) { trigger_spell_id = 60234;stat = GetStat(STAT_INTELLECT);}
                    // spirit
                    if (GetStat(STAT_SPIRIT)   > stat) { trigger_spell_id = 60235;stat = GetStat(STAT_SPIRIT);   }
                }
                //else if (auraSpellInfo->Id==31255)        // Deadly Swiftness (Rank 1)
                //else if (auraSpellInfo->Id==5301)         // Defensive State (DND)
                //else if (auraSpellInfo->Id==13358)        // Defensive State (DND)
                //else if (auraSpellInfo->Id==16092)        // Defensive State (DND)
                //else if (auraSpellInfo->Id==24949)        // Defensive State 2 (DND)
                //else if (auraSpellInfo->Id==40329)        // Demo Shout Sensor
                else if (auraSpellInfo->Id == 33896)        // Desperate Defense (Stonescythe Whelp, Stonescythe Alpha, Stonescythe Ambusher)
                    trigger_spell_id = 33898;
                //else if (auraSpellInfo->Id==18943)        // Double Attack
                //else if (auraSpellInfo->Id==19194)        // Double Attack
                //else if (auraSpellInfo->Id==19817)        // Double Attack
                //else if (auraSpellInfo->Id==19818)        // Double Attack
                //else if (auraSpellInfo->Id==22835)        // Drunken Rage
                //    trigger_spell_id = 14822;
                /*
                else if (auraSpellInfo->SpellIconID==191)   // Elemental Response
                {
                    switch (auraSpellInfo->Id && auraSpellInfo->AttributesEx==0)
                    {
                        case 34191:
                        case 34329:
                        case 34524:
                        case 34582:
                        case 36733:
                            break;
                         default:
                            sLog.outError("Unit::HandleProcTriggerSpell: Spell %u miss posibly Elemental Response",auraSpellInfo->Id);
                            return false;
                    }
                    //This generic aura self-triggers a different spell for each school of magic that lands on the wearer:
                    switch (procSpell->School)
                    {
                        case SPELL_SCHOOL_FIRE:  trigger_spell_id = 34192; break;
                        case SPELL_SCHOOL_FROST: trigger_spell_id = 34193; break;
                        case SPELL_SCHOOL_ARCANE:trigger_spell_id = 34194; break;
                        case SPELL_SCHOOL_NATURE:trigger_spell_id = 34195; break;
                        case SPELL_SCHOOL_SHADOW:trigger_spell_id = 34196; break;
                        case SPELL_SCHOOL_HOLY:  trigger_spell_id = 34197; break;
                        case SPELL_SCHOOL_NORMAL:trigger_spell_id = 34198; break;
                        default:
                            sLog.outError("Unit::HandleProcTriggerSpell: Spell %u Elemental Response wrong school",auraSpellInfo->Id);
                            return false;
                    }
                }
                */
                //else if (auraSpellInfo->Id==40364)        // Entangling Roots Sensor
                //else if (auraSpellInfo->Id==33207)        // Gossip NPC Periodic - Fidget
                //else if (auraSpellInfo->Id==50051)        // Ethereal Pet Aura
                //else if (auraSpellInfo->Id==35321)        // Gushing Wound
                //else if (auraSpellInfo->Id==38363)        // Gushing Wound
                //else if (auraSpellInfo->Id==39215)        // Gushing Wound
                //else if (auraSpellInfo->Id==44527)        // Hate Monster (Spar Buddy) (30 sec)
                //else if (auraSpellInfo->Id==44819)        // Hate Monster (Spar Buddy) (>30% Health)
                //else if (auraSpellInfo->Id==44526)        // Hate Monster (Spar) (30 sec)
                //else if (auraSpellInfo->Id==44820)        // Hate Monster (Spar) (<30%)
                //else if (auraSpellInfo->Id==49059)        // Horde, Hate Monster (Spar Buddy) (>30% Health)
                //else if (auraSpellInfo->Id==40250)        // Improved Duration
                //else if (auraSpellInfo->Id==59288)        // Infra-Green Shield
                //else if (auraSpellInfo->Id==54072)        // Knockback Ball Passive
                else if (auraSpellInfo->Id==27522 || auraSpellInfo->Id==40336)
                                                            // Mana Drain Trigger
                {
                    // On successful melee or ranged attack gain $29471s1 mana and if possible drain $27526s1 mana from the target.
                    if (this && this->isAlive())
                        CastSpell(this, 29471, true, castItem, triggeredByAura);
                    if (pVictim && pVictim->isAlive())
                        CastSpell(pVictim, 27526, true, castItem, triggeredByAura);
                    return true;
                }
                //else if (auraSpellInfo->Id==55580)        // Mana Link
                //else if (auraSpellInfo->Id==45903)        // Offensive State
                //else if (auraSpellInfo->Id==44326)        // Pure Energy Passive
                //else if (auraSpellInfo->Id==43453)        // Rune Ward
                //else if (auraSpellInfo->Id== 7137)        // Shadow Charge (Rank 1)
                //else if (auraSpellInfo->Id==36576)        // Shaleskin (Shaleskin Flayer, Shaleskin Ripper) 30023 trigger
                //else if (auraSpellInfo->Id==34783)        // Spell Reflection
                //else if (auraSpellInfo->Id==36096)        // Spell Reflection
                //else if (auraSpellInfo->Id==57587)        // Steal Ranged ()
                //else if (auraSpellInfo->Id==36207)        // Steal Weapon
                //else if (auraSpellInfo->Id== 7377)        // Take Immune Periodic Damage <Not Working>
                //else if (auraSpellInfo->Id==35205)        // Vanish
                //else if (auraSpellInfo->Id==42730)        // Woe Strike
                //else if (auraSpellInfo->Id==59735)        // Woe Strike
                //else if (auraSpellInfo->Id==46146)        // [PH] Ahune  Spanky Hands
                break;
            case SPELLFAMILY_MAGE:
                if (auraSpellInfo->SpellIconID == 2127)     // Blazing Speed
                {
                    switch (auraSpellInfo->Id)
                    {
                        case 31641:  // Rank 1
                        case 31642:  // Rank 2
                            trigger_spell_id = 31643;
                            break;
                        default:
                            sLog.outError("Unit::HandleProcTriggerSpell: Spell %u miss posibly Blazing Speed",auraSpellInfo->Id);
                            return false;
                    }
                }
                break;
            case SPELLFAMILY_WARRIOR:
                if (auraSpellInfo->Id == 50421)             // Scent of Blood
                    trigger_spell_id = 50422;
                break;
            case SPELLFAMILY_WARLOCK:
            {
                // Pyroclasm
                if (auraSpellInfo->SpellIconID == 1137)
                {
                    if(!pVictim || !pVictim->isAlive() || pVictim == this || procSpell == NULL)
                        return false;
                    // Calculate spell tick count for spells
                    uint32 tick = 1; // Default tick = 1

                    // Hellfire have 15 tick
                    if (procSpell->SpellFamilyFlags[0]&0x40)
                        tick = 15;
                    // Rain of Fire have 4 tick
                    else if (procSpell->SpellFamilyFlags[0]&0x20)
                        tick = 4;
                    else
                        return false;

                    // Calculate chance = baseChance / tick
                    float chance = 0;
                    switch (auraSpellInfo->Id)
                    {
                        case 18096: chance = 13.0f / tick; break;
                        case 18073: chance = 26.0f / tick; break;
                    }
                    // Roll chance
                    if (!roll_chance_f(chance))
                        return false;

                    trigger_spell_id = 18093;
                }
                // Drain Soul
                else if (auraSpellInfo->SpellFamilyFlags[0] & 0x4000)
                {
                    Unit::AuraEffectList const& mAddFlatModifier = GetAurasByType(SPELL_AURA_ADD_FLAT_MODIFIER);
                    for(Unit::AuraEffectList::const_iterator i = mAddFlatModifier.begin(); i != mAddFlatModifier.end(); ++i)
                    {
                        if ((*i)->GetMiscValue() == SPELLMOD_CHANCE_OF_SUCCESS && (*i)->GetSpellProto()->SpellIconID == 113)
                        {
                            int32 value2 = CalculateSpellDamage((*i)->GetSpellProto(),2,(*i)->GetSpellProto()->EffectBasePoints[2],this);
                            // Drain Soul
                            CastCustomSpell(this, 18371, &basepoints0, NULL, NULL, true, castItem, triggeredByAura);
                            break;
                        }
                    }
                    // Not remove charge (aura removed on death in any cases)
                    // Need for correct work Drain Soul SPELL_AURA_CHANNEL_DEATH_ITEM aura
                    return false;
                }
                // Nether Protection
                else if (auraSpellInfo->SpellIconID == 1985)
                {
                    if (!procSpell)
                        return false;
                    switch(GetFirstSchoolInMask(GetSpellSchoolMask(procSpell)))
                    {
                        case SPELL_SCHOOL_NORMAL:
                        case SPELL_SCHOOL_HOLY:
                            return false;                   // ignore
                        case SPELL_SCHOOL_FIRE:   trigger_spell_id = 54371; break;
                        case SPELL_SCHOOL_NATURE: trigger_spell_id = 54375; break;
                        case SPELL_SCHOOL_FROST:  trigger_spell_id = 54372; break;
                        case SPELL_SCHOOL_SHADOW: trigger_spell_id = 54374; break;
                        case SPELL_SCHOOL_ARCANE: trigger_spell_id = 54373; break;
                        default:
                            return false;
                    }
                }
                break;
            }
            case SPELLFAMILY_PRIEST:
            {
                // Greater Heal Refund
                if (auraSpellInfo->Id==37594)
                    trigger_spell_id = 37595;
                // Blessed Recovery
                else if (auraSpellInfo->SpellIconID == 1875)
                {
                    switch (auraSpellInfo->Id)
                    {
                        case 27811: trigger_spell_id = 27813; break;
                        case 27815: trigger_spell_id = 27817; break;
                        case 27816: trigger_spell_id = 27818; break;
                        default:
                            sLog.outError("Unit::HandleProcTriggerSpell: Spell %u not handled in BR", auraSpellInfo->Id);
                        return false;
                    }
                    basepoints0 = damage * triggerAmount / 100 / 3;
                    target = this;
                }
                break;
            }
            case SPELLFAMILY_DRUID:
            {
                // Druid Forms Trinket
                if (auraSpellInfo->Id==37336)
                {
                    switch(m_form)
                    {
                        case FORM_NONE:     trigger_spell_id = 37344;break;
                        case FORM_CAT:      trigger_spell_id = 37341;break;
                        case FORM_BEAR:
                        case FORM_DIREBEAR: trigger_spell_id = 37340;break;
                        case FORM_TREE:     trigger_spell_id = 37342;break;
                        case FORM_MOONKIN:  trigger_spell_id = 37343;break;
                        default:
                            return false;
                    }
                }
                //else if (auraSpellInfo->Id==40363)// Entangling Roots ()
                //    trigger_spell_id = ????;
                break;
            }
            case SPELLFAMILY_HUNTER:
                break;
            case SPELLFAMILY_PALADIN:
            {
                /*
                // Blessed Life
                if (auraSpellInfo->SpellIconID == 2137)
                {
                    switch (auraSpellInfo->Id)
                    {
                        case 31828:                         // Rank 1
                        case 31829:                         // Rank 2
                        case 31830:                         // Rank 3
                            break;
                        default:
                            sLog.outError("Unit::HandleProcTriggerSpell: Spell %u miss posibly Blessed Life", auraSpellInfo->Id);
                            return false;
                    }
                }
                */
                // Healing Discount
                if (auraSpellInfo->Id==37705)
                {
                    trigger_spell_id = 37706;
                    target = this;
                }
                // Soul Preserver
                if (auraSpellInfo->Id==60510)
                {
                    trigger_spell_id = 60515;
                    target = this;
                }
                // Illumination
                else if (auraSpellInfo->SpellIconID==241)
                {
                    if(!procSpell)
                        return false;
                    // procspell is triggered spell but we need mana cost of original casted spell
                    uint32 originalSpellId = procSpell->Id;
                    // Holy Shock heal
                    if(procSpell->SpellFamilyFlags[1] & 0x00010000)
                    {
                        switch(procSpell->Id)
                        {
                            case 25914: originalSpellId = 20473; break;
                            case 25913: originalSpellId = 20929; break;
                            case 25903: originalSpellId = 20930; break;
                            case 27175: originalSpellId = 27174; break;
                            case 33074: originalSpellId = 33072; break;
                            case 48820: originalSpellId = 48824; break;
                            case 48821: originalSpellId = 48825; break;
                            default:
                                sLog.outError("Unit::HandleProcTriggerSpell: Spell %u not handled in HShock",procSpell->Id);
                               return false;
                        }
                    }
                    SpellEntry const *originalSpell = sSpellStore.LookupEntry(originalSpellId);
                    if(!originalSpell)
                    {
                        sLog.outError("Unit::HandleProcTriggerSpell: Spell %u unknown but selected as original in Illu",originalSpellId);
                        return false;
                    }
                    // percent stored in effect 1 (class scripts) base points
                    int32 cost = originalSpell->manaCost + originalSpell->ManaCostPercentage * GetCreateMana() / 100;
                    basepoints0 = cost*auraSpellInfo->CalculateSimpleValue(1)/100;
                    trigger_spell_id = 20272;
                    target = this;
                }
                // Lightning Capacitor
                else if (auraSpellInfo->Id==37657)
                {
                    if(!pVictim || !pVictim->isAlive())
                        return false;
                    // stacking
                    CastSpell(this, 37658, true, NULL, triggeredByAura);

                    AuraEffect * dummy = GetDummyAura(37658);
                    // release at 3 aura in stack (cont contain in basepoint of trigger aura)
                    if(!dummy || dummy->GetParentAura()->GetStackAmount() < triggerAmount)
                        return false;

                    RemoveAurasDueToSpell(37658);
                    trigger_spell_id = 37661;
                    target = pVictim;
                }
                // Thunder Capacitor
                else if (auraSpellInfo->Id == 54841)
                {
                    if(!pVictim || !pVictim->isAlive())
                        return false;
                    // stacking
                    CastSpell(this, 54842, true, NULL, triggeredByAura);

                    // counting
                    AuraEffect * dummy = GetDummyAura(54842);
                    // release at 3 aura in stack (cont contain in basepoint of trigger aura)
                    if(!dummy || dummy->GetParentAura()->GetStackAmount() < triggerAmount)
                        return false;

                    RemoveAurasDueToSpell(54842);
                    trigger_spell_id = 54843;
                    target = pVictim;
                }
                break;
            }
            case SPELLFAMILY_SHAMAN:
            {
                // Lightning Shield (overwrite non existing triggered spell call in spell.dbc
                if(auraSpellInfo->SpellFamilyFlags[0] & 0x400)
                {
                    switch(auraSpellInfo->Id)
                    {
                        case 324:                           // Rank 1
                            trigger_spell_id = 26364; break;
                        case 325:                           // Rank 2
                            trigger_spell_id = 26365; break;
                        case 905:                           // Rank 3
                            trigger_spell_id = 26366; break;
                        case 945:                           // Rank 4
                            trigger_spell_id = 26367; break;
                        case 8134:                          // Rank 5
                            trigger_spell_id = 26369; break;
                        case 10431:                         // Rank 6
                            trigger_spell_id = 26370; break;
                        case 10432:                         // Rank 7
                            trigger_spell_id = 26363; break;
                        case 25469:                         // Rank 8
                            trigger_spell_id = 26371; break;
                        case 25472:                         // Rank 9
                            trigger_spell_id = 26372; break;
                        case 49280:                         // Rank 10
                            trigger_spell_id = 49278; break;
                        case 49281:                         // Rank 11
                            trigger_spell_id = 49279; break;
                        default:
                            sLog.outError("Unit::HandleProcTriggerSpell: Spell %u not handled in LShield", auraSpellInfo->Id);
                        return false;
                    }
                }
                // Lightning Shield (The Ten Storms set)
                else if (auraSpellInfo->Id == 23551)
                {
                    trigger_spell_id = 23552;
                    target = pVictim;
                }
                // Damage from Lightning Shield (The Ten Storms set)
                else if (auraSpellInfo->Id == 23552)
                    trigger_spell_id = 27635;
                // Mana Surge (The Earthfury set)
                else if (auraSpellInfo->Id == 23572)
                {
                    if(!procSpell)
                        return false;
                    basepoints0 = procSpell->manaCost * 35 / 100;
                    trigger_spell_id = 23571;
                    target = this;
                }
                // Nature's Guardian
                else if (auraSpellInfo->SpellIconID == 2013)
                {
                    // Check health condition - should drop to less 30% (damage deal after this!)
                    if (!(10*(int32(GetHealth() - damage)) < 3 * GetMaxHealth()))
                        return false;

                     if(pVictim && pVictim->isAlive())
                         pVictim->getThreatManager().modifyThreatPercent(this,-10);

                    basepoints0 = triggerAmount * GetMaxHealth() / 100;
                    trigger_spell_id = 31616;
                    target = this;
                }
                break;
            }
            case SPELLFAMILY_DEATHKNIGHT:
            {
                // Acclimation
                if (auraSpellInfo->SpellIconID == 1930)
                {
                    if (!procSpell)
                        return false;
                    switch(GetFirstSchoolInMask(GetSpellSchoolMask(procSpell)))
                    {
                        case SPELL_SCHOOL_NORMAL:
                            return false;                   // ignore
                        case SPELL_SCHOOL_HOLY:   trigger_spell_id = 50490; break;
                        case SPELL_SCHOOL_FIRE:   trigger_spell_id = 50362; break;
                        case SPELL_SCHOOL_NATURE: trigger_spell_id = 50488; break;
                        case SPELL_SCHOOL_FROST:  trigger_spell_id = 50485; break;
                        case SPELL_SCHOOL_SHADOW: trigger_spell_id = 50489; break;
                        case SPELL_SCHOOL_ARCANE: trigger_spell_id = 54373; break;
                        default:
                            return false;
                    }
                }
                // Blood Presence
                else if (auraSpellInfo->Id == 48266)
                {
                    if (GetTypeId() != TYPEID_PLAYER)
                        return false;
                    if (!((Player*)this)->isHonorOrXPTarget(pVictim))
                        return false;
                    trigger_spell_id = 50475;
                    basepoints0 = damage * triggerAmount / 100;
                }
                break;
            }
            default:
                 break;
        }
    }

    // All ok. Check current trigger spell
    SpellEntry const* triggerEntry = sSpellStore.LookupEntry(trigger_spell_id);
    if ( triggerEntry == NULL )
    {
        // Not cast unknown spell
        // sLog.outError("Unit::HandleProcTriggerSpell: Spell %u have 0 in EffectTriggered[%d], not handled custom case?",auraSpellInfo->Id,triggeredByAura->GetEffIndex());
        return false;
    }

    // not allow proc extra attack spell at extra attack
    if( m_extraAttacks && IsSpellHaveEffect(triggerEntry, SPELL_EFFECT_ADD_EXTRA_ATTACKS) )
        return false;

    // Costum requirements (not listed in procEx) Warning! damage dealing after this
    // Custom triggered spells
    switch (auraSpellInfo->Id)
    {
        // Persistent Shield (Scarab Brooch trinket)
        // This spell originally trigger 13567 - Dummy Trigger (vs dummy efect)
        case 26467:
        {
            basepoints0 = damage * 15 / 100;
            target = pVictim;
            trigger_spell_id = 26470;
            break;
        }
        // Cheat Death
        case 28845:
        {
            // When your health drops below 20% ....
            if (GetHealth() - damage > GetMaxHealth() / 5 || GetHealth() < GetMaxHealth() / 5)
                return false;
            break;
        }
        // Deadly Swiftness (Rank 1)
        case 31255:
        {
            // whenever you deal damage to a target who is below 20% health.
            if (pVictim->GetHealth() > pVictim->GetMaxHealth() / 5)
                return false;

            target = this;
            trigger_spell_id = 22588;
        }
        // Greater Heal Refund (Avatar Raiment set)
        case 37594:
        {
            // Not give if target alredy have full health
            if (pVictim->GetHealth() == pVictim->GetMaxHealth())
                return false;
            // If your Greater Heal brings the target to full health, you gain $37595s1 mana.
            if (pVictim->GetHealth() + damage < pVictim->GetMaxHealth())
                return false;
            break;
        }
        // Bonus Healing (Crystal Spire of Karabor mace)
        case 40971:
        {
            // If your target is below $s1% health
            if (pVictim->GetHealth() > pVictim->GetMaxHealth() * triggerAmount / 100)
                return false;
            break;
        }
        // Evasive Maneuvers (Commendation of Kael`thas trinket)
        case 45057:
        {
            // reduce you below $s1% health
            if (GetHealth() - damage > GetMaxHealth() * triggerAmount / 100)
                return false;
            break;
        }
        // Rapid Recuperation
        case 53228:
        case 53232:
        {
            // This effect only from Rapid Fire (ability cast)
            if (!(procSpell->SpellFamilyFlags[0] & 0x20))
                return false;
            break;
        }
    }

    // Costum basepoints/target for exist spell
    // dummy basepoints or other customs
    switch(trigger_spell_id)
    {
        // Cast positive spell on enemy target
        case 7099:  // Curse of Mending
        case 39647: // Curse of Mending
        case 29494: // Temptation
        case 20233: // Improved Lay on Hands (cast on target)
        {
            target = pVictim;
            break;
        }
        // Combo points add triggers (need add combopoint only for main tatget, and after possible combopoints reset)
        case 15250: // Rogue Setup
        {
            if(!pVictim || pVictim != getVictim())   // applied only for main target
                return false;
            break;                                   // continue normal case
        }
        // Finish movies that add combo
        case 14189: // Seal Fate (Netherblade set)
        case 14157: // Ruthlessness
        {
            // Need add combopoint AFTER finish movie (or they dropped in finish phase)
            break;
        }
        // Bloodthirst (($m/100)% of max health)
        case 23880:
        {
            basepoints0 = int32(GetMaxHealth() * triggerAmount / 100);
            break;
        }
        // Shamanistic Rage triggered spell
        case 30824:
        {
            basepoints0 = int32(GetTotalAttackPowerValue(BASE_ATTACK) * triggerAmount / 100);
            break;
        }
        // Enlightenment (trigger only from mana cost spells)
        case 35095:
        {
            if(!procSpell || procSpell->powerType!=POWER_MANA || procSpell->manaCost==0 && procSpell->ManaCostPercentage==0 && procSpell->manaCostPerlevel==0)
                return false;
            break;
        }
        // Brain Freeze
        case 57761:
        {
            if(!procSpell)
                return false;
            // For trigger from Blizzard need exist Improved Blizzard
            if (procSpell->SpellFamilyName==SPELLFAMILY_MAGE && procSpell->SpellFamilyFlags[0] & 0x80)
            {
                bool found = false;
                AuraEffectList const& mOverrideClassScript = GetAurasByType(SPELL_AURA_OVERRIDE_CLASS_SCRIPTS);
                for(AuraEffectList::const_iterator i = mOverrideClassScript.begin(); i != mOverrideClassScript.end(); ++i)
                {
                    int32 script = (*i)->GetMiscValue();
                    if(script==836 || script==988 || script==989)
                    {
                        found=true;
                        break;
                    }
                }
                if(!found)
                    return false;
            }
            break;
        }
        // Astral Shift
        case 52179:
        {
            if (procSpell == 0 || !(procEx & (PROC_EX_NORMAL_HIT|PROC_EX_CRITICAL_HIT)) || this == pVictim)
                return false;

            // Need stun, fear or silence mechanic
            if (!(GetAllSpellMechanicMask(procSpell) & ((1<<MECHANIC_SILENCE)|(1<<MECHANIC_STUN)|(1<<MECHANIC_FEAR))))
                return false;
            break;
        }
        // Burning Determination
        case 54748:
        {
            if(!procSpell)
                return false;
            // Need Interrupt or Silenced mechanic
            if (!(GetAllSpellMechanicMask(procSpell) & ((1<<MECHANIC_INTERRUPT)|(1<<MECHANIC_SILENCE))))
                return false;
            break;
        }
        // Lock and Load
        case 56453:
        {
            // Proc only from trap activation (from periodic proc another aura of this spell)
            if (!(procFlags & PROC_FLAG_ON_TRAP_ACTIVATION) || !roll_chance_i(triggerAmount))
                return false;
            break;
        }
    }

    if( cooldown && GetTypeId()==TYPEID_PLAYER && ((Player*)this)->HasSpellCooldown(trigger_spell_id))
        return false;

    // try detect target manually if not set
    if ( target == NULL )
       target = !(procFlags & PROC_FLAG_SUCCESSFUL_POSITIVE_SPELL) && IsPositiveSpell(trigger_spell_id) ? this : pVictim;

    // default case
    if(!target || target!=this && !target->isAlive())
        return false;

    if(basepoints0)
        CastCustomSpell(target,trigger_spell_id,&basepoints0,NULL,NULL,true,castItem,triggeredByAura);
    //else if(spellmgr.GetSpellCustomAttr(trigger_spell_id) & SPELL_ATTR_CU_AURA_SPELL)
    //    AddAura(trigger_spell_id, target);
    else
        CastSpell(target,trigger_spell_id,true,castItem,triggeredByAura);

    if( cooldown && GetTypeId()==TYPEID_PLAYER )
        ((Player*)this)->AddSpellCooldown(trigger_spell_id,0,time(NULL) + cooldown);

    return true;
}

bool Unit::HandleOverrideClassScriptAuraProc(Unit *pVictim, uint32 damage, AuraEffect *triggeredByAura, SpellEntry const *procSpell, uint32 cooldown)
{
    int32 scriptId = triggeredByAura->GetMiscValue();

    if(!pVictim || !pVictim->isAlive())
        return false;

    Item* castItem = triggeredByAura->GetParentAura()->GetCastItemGUID() && GetTypeId()==TYPEID_PLAYER
        ? ((Player*)this)->GetItemByGuid(triggeredByAura->GetParentAura()->GetCastItemGUID()) : NULL;

    uint32 triggered_spell_id = 0;

    switch(scriptId)
    {
        case 836:                                           // Improved Blizzard (Rank 1)
        {
            if (!procSpell || procSpell->SpellVisual[0]!=9487)
                return false;
            triggered_spell_id = 12484;
            break;
        }
        case 988:                                           // Improved Blizzard (Rank 2)
        {
            if (!procSpell || procSpell->SpellVisual[0]!=9487)
                return false;
            triggered_spell_id = 12485;
            break;
        }
        case 989:                                           // Improved Blizzard (Rank 3)
        {
            if (!procSpell || procSpell->SpellVisual[0]!=9487)
                return false;
            triggered_spell_id = 12486;
            break;
        }
        case 4086:                                          // Improved Mend Pet (Rank 1)
        case 4087:                                          // Improved Mend Pet (Rank 2)
        {
            int32 chance = triggeredByAura->GetSpellProto()->EffectBasePoints[triggeredByAura->GetEffIndex()];
            if(!roll_chance_i(chance))
                return false;

            triggered_spell_id = 24406;
            break;
        }
        case 4533:                                          // Dreamwalker Raiment 2 pieces bonus
        {
            // Chance 50%
            if (!roll_chance_i(50))
                return false;

            switch (pVictim->getPowerType())
            {
                case POWER_MANA:   triggered_spell_id = 28722; break;
                case POWER_RAGE:   triggered_spell_id = 28723; break;
                case POWER_ENERGY: triggered_spell_id = 28724; break;
                default:
                    return false;
            }
            break;
        }
        case 4537:                                          // Dreamwalker Raiment 6 pieces bonus
            triggered_spell_id = 28750;                     // Blessing of the Claw
            break;
        case 5497:                                          // Improved Mana Gems (Serpent-Coil Braid)
            triggered_spell_id = 37445;                     // Mana Surge
            break;
        case 8152:                                          // Serendipity
        {
            // if heal your target over maximum health
            if (pVictim->GetHealth() + damage < pVictim->GetMaxHealth())
                return false;
            int32 cost = procSpell->manaCost + procSpell->ManaCostPercentage * GetCreateMana() / 100;
            int32 basepoints0 = cost * triggeredByAura->GetAmount()/100;
            CastCustomSpell(this, 47762, &basepoints0, 0, 0, true, 0, triggeredByAura);
            return true;
        }
        // Rapture
        case 7556:                          // Rank 1
        case 7555:                          // Rank 2
        case 7554:                          // Rank 3
        case 7553:                          // Rank 4
        case 7552:                          // Rank 5
        {
            int32 basepoints0 = ((getLevel() * (-0.2) + 18) / 1000000) * damage * GetMaxPower(POWER_MANA);
            if(basepoints0 > (GetMaxPower(POWER_MANA) / 100) * (triggeredByAura->GetAmount() / 10))
               basepoints0 = (GetMaxPower(POWER_MANA) / 100) * (triggeredByAura->GetAmount() / 10);
            CastCustomSpell(this, 47755, &basepoints0, 0, 0, true, 0, triggeredByAura);
            return true;
        }
    }

    // not processed
    if(!triggered_spell_id)
        return false;

    // standard non-dummy case
    SpellEntry const* triggerEntry = sSpellStore.LookupEntry(triggered_spell_id);

    if(!triggerEntry)
    {
        sLog.outError("Unit::HandleOverrideClassScriptAuraProc: Spell %u triggering for class script id %u",triggered_spell_id,scriptId);
        return false;
    }

    if( cooldown && GetTypeId()==TYPEID_PLAYER && ((Player*)this)->HasSpellCooldown(triggered_spell_id))
        return false;

    CastSpell(pVictim, triggered_spell_id, true, castItem, triggeredByAura);

    if( cooldown && GetTypeId()==TYPEID_PLAYER )
        ((Player*)this)->AddSpellCooldown(triggered_spell_id,0,time(NULL) + cooldown);

    return true;
}

void Unit::setPowerType(Powers new_powertype)
{
    SetByteValue(UNIT_FIELD_BYTES_0, 3, new_powertype);

    if(GetTypeId() == TYPEID_PLAYER)
    {
        if(((Player*)this)->GetGroup())
            ((Player*)this)->SetGroupUpdateFlag(GROUP_UPDATE_FLAG_POWER_TYPE);
    }
    else if(((Creature*)this)->isPet())
    {
        Pet *pet = ((Pet*)this);
        if(pet->isControlled())
        {
            Unit *owner = GetOwner();
            if(owner && (owner->GetTypeId() == TYPEID_PLAYER) && ((Player*)owner)->GetGroup())
                ((Player*)owner)->SetGroupUpdateFlag(GROUP_UPDATE_FLAG_PET_POWER_TYPE);
        }
    }

    switch(new_powertype)
    {
        default:
        case POWER_MANA:
            break;
        case POWER_RAGE:
            SetMaxPower(POWER_RAGE,GetCreatePowers(POWER_RAGE));
            SetPower(   POWER_RAGE,0);
            break;
        case POWER_FOCUS:
            SetMaxPower(POWER_FOCUS,GetCreatePowers(POWER_FOCUS));
            SetPower(   POWER_FOCUS,GetCreatePowers(POWER_FOCUS));
            break;
        case POWER_ENERGY:
            SetMaxPower(POWER_ENERGY,GetCreatePowers(POWER_ENERGY));
            SetPower(   POWER_ENERGY,0);
            break;
        case POWER_HAPPINESS:
            SetMaxPower(POWER_HAPPINESS,GetCreatePowers(POWER_HAPPINESS));
            SetPower(POWER_HAPPINESS,GetCreatePowers(POWER_HAPPINESS));
            break;
    }
}

FactionTemplateEntry const* Unit::getFactionTemplateEntry() const
{
    FactionTemplateEntry const* entry = sFactionTemplateStore.LookupEntry(getFaction());
    if(!entry)
    {
        static uint64 guid = 0;                             // prevent repeating spam same faction problem

        if(GetGUID() != guid)
        {
            if(GetTypeId() == TYPEID_PLAYER)
                sLog.outError("Player %s have invalid faction (faction template id) #%u", ((Player*)this)->GetName(), getFaction());
            else
                sLog.outError("Creature (template id: %u) have invalid faction (faction template id) #%u", ((Creature*)this)->GetCreatureInfo()->Entry, getFaction());
            guid = GetGUID();
        }
    }
    return entry;
}

bool Unit::IsHostileTo(Unit const* unit) const
{
    if(!unit)
        return false;
    // always non-hostile to self
    if(unit==this)
        return false;

    // always non-hostile to GM in GM mode
    if(unit->GetTypeId()==TYPEID_PLAYER && ((Player const*)unit)->isGameMaster())
        return false;

    // always hostile to enemy
    if(getVictim()==unit || unit->getVictim()==this)
        return true;

    // test pet/charm masters instead pers/charmeds
    Unit const* testerOwner = GetCharmerOrOwner();
    Unit const* targetOwner = unit->GetCharmerOrOwner();

    // always hostile to owner's enemy
    if(testerOwner && (testerOwner->getVictim()==unit || unit->getVictim()==testerOwner))
        return true;

    // always hostile to enemy owner
    if(targetOwner && (getVictim()==targetOwner || targetOwner->getVictim()==this))
        return true;

    // always hostile to owner of owner's enemy
    if(testerOwner && targetOwner && (testerOwner->getVictim()==targetOwner || targetOwner->getVictim()==testerOwner))
        return true;

    Unit const* tester = testerOwner ? testerOwner : this;
    Unit const* target = targetOwner ? targetOwner : unit;

    // always non-hostile to target with common owner, or to owner/pet
    if(tester==target)
        return false;

    // special cases (Duel, etc)
    if(tester->GetTypeId()==TYPEID_PLAYER && target->GetTypeId()==TYPEID_PLAYER)
    {
        Player const* pTester = (Player const*)tester;
        Player const* pTarget = (Player const*)target;

        // Duel
        if(pTester->duel && pTester->duel->opponent == pTarget && pTester->duel->startTime != 0)
            return true;

        // Group
        if(pTester->GetGroup() && pTester->GetGroup()==pTarget->GetGroup())
            return false;

        // Sanctuary
        if(pTarget->HasByteFlag(UNIT_FIELD_BYTES_2, 1, UNIT_BYTE2_FLAG_SANCTUARY) && pTester->HasByteFlag(UNIT_FIELD_BYTES_2, 1, UNIT_BYTE2_FLAG_SANCTUARY))
            return false;

        // PvP FFA state
        if(pTester->HasByteFlag(UNIT_FIELD_BYTES_2, 1, UNIT_BYTE2_FLAG_FFA_PVP) && pTarget->HasByteFlag(UNIT_FIELD_BYTES_2, 1, UNIT_BYTE2_FLAG_FFA_PVP))
            return true;

        //= PvP states
        // Green/Blue (can't attack)
        if(pTester->GetTeam()==pTarget->GetTeam())
            return false;

        // Red (can attack) if true, Blue/Yellow (can't attack) in another case
        return pTester->IsPvP() && pTarget->IsPvP();
    }

    // faction base cases
    FactionTemplateEntry const*tester_faction = tester->getFactionTemplateEntry();
    FactionTemplateEntry const*target_faction = target->getFactionTemplateEntry();
    if(!tester_faction || !target_faction)
        return false;

    if(target->isAttackingPlayer() && tester->IsContestedGuard())
        return true;

    // PvC forced reaction and reputation case
    if(tester->GetTypeId()==TYPEID_PLAYER)
    {
        // forced reaction
        if(target_faction->faction)
        {
            if(ReputationRank const* force =((Player*)tester)->GetReputationMgr().GetForcedRankIfAny(target_faction))
                return *force <= REP_HOSTILE;

            // if faction have reputation then hostile state for tester at 100% dependent from at_war state
            if(FactionEntry const* raw_target_faction = sFactionStore.LookupEntry(target_faction->faction))
                if(FactionState const* factionState = ((Player*)tester)->GetReputationMgr().GetState(raw_target_faction))
                    return (factionState->Flags & FACTION_FLAG_AT_WAR);
        }
    }
    // CvP forced reaction and reputation case
    else if(target->GetTypeId()==TYPEID_PLAYER)
    {
        // forced reaction
        if(tester_faction->faction)
        {
            if(ReputationRank const* force = ((Player*)target)->GetReputationMgr().GetForcedRankIfAny(tester_faction))
                return *force <= REP_HOSTILE;

            // apply reputation state
            FactionEntry const* raw_tester_faction = sFactionStore.LookupEntry(tester_faction->faction);
            if(raw_tester_faction && raw_tester_faction->reputationListID >=0 )
                return ((Player const*)target)->GetReputationMgr().GetRank(raw_tester_faction) <= REP_HOSTILE;
        }
    }

    // common faction based case (CvC,PvC,CvP)
    return tester_faction->IsHostileTo(*target_faction);
}

bool Unit::IsFriendlyTo(Unit const* unit) const
{
    // always friendly to self
    if(unit==this)
        return true;

    // always friendly to GM in GM mode
    if(unit->GetTypeId()==TYPEID_PLAYER && ((Player const*)unit)->isGameMaster())
        return true;

    // always non-friendly to enemy
    if(getVictim()==unit || unit->getVictim()==this)
        return false;

    // test pet/charm masters instead pers/charmeds
    Unit const* testerOwner = GetCharmerOrOwner();
    Unit const* targetOwner = unit->GetCharmerOrOwner();

    // always non-friendly to owner's enemy
    if(testerOwner && (testerOwner->getVictim()==unit || unit->getVictim()==testerOwner))
        return false;

    // always non-friendly to enemy owner
    if(targetOwner && (getVictim()==targetOwner || targetOwner->getVictim()==this))
        return false;

    // always non-friendly to owner of owner's enemy
    if(testerOwner && targetOwner && (testerOwner->getVictim()==targetOwner || targetOwner->getVictim()==testerOwner))
        return false;

    Unit const* tester = testerOwner ? testerOwner : this;
    Unit const* target = targetOwner ? targetOwner : unit;

    // always friendly to target with common owner, or to owner/pet
    if(tester==target)
        return true;

    // special cases (Duel)
    if(tester->GetTypeId()==TYPEID_PLAYER && target->GetTypeId()==TYPEID_PLAYER)
    {
        Player const* pTester = (Player const*)tester;
        Player const* pTarget = (Player const*)target;

        // Duel
        if(pTester->duel && pTester->duel->opponent == target && pTester->duel->startTime != 0)
            return false;

        // Group
        if(pTester->GetGroup() && pTester->GetGroup()==pTarget->GetGroup())
            return true;

        // Sanctuary
        if(pTarget->HasByteFlag(UNIT_FIELD_BYTES_2, 1, UNIT_BYTE2_FLAG_SANCTUARY) && pTester->HasByteFlag(UNIT_FIELD_BYTES_2, 1, UNIT_BYTE2_FLAG_SANCTUARY))
            return true;

        // PvP FFA state
        if(pTester->HasByteFlag(UNIT_FIELD_BYTES_2, 1, UNIT_BYTE2_FLAG_FFA_PVP) && pTarget->HasByteFlag(UNIT_FIELD_BYTES_2, 1, UNIT_BYTE2_FLAG_FFA_PVP))
            return false;

        //= PvP states
        // Green/Blue (non-attackable)
        if(pTester->GetTeam()==pTarget->GetTeam())
            return true;

        // Blue (friendly/non-attackable) if not PVP, or Yellow/Red in another case (attackable)
        return !pTarget->IsPvP();
    }

    // faction base cases
    FactionTemplateEntry const*tester_faction = tester->getFactionTemplateEntry();
    FactionTemplateEntry const*target_faction = target->getFactionTemplateEntry();
    if(!tester_faction || !target_faction)
        return false;

    if(target->isAttackingPlayer() && tester->IsContestedGuard())
        return false;

    // PvC forced reaction and reputation case
    if(tester->GetTypeId()==TYPEID_PLAYER)
    {
        // forced reaction
        if(target_faction->faction)
        {
            if(ReputationRank const* force =((Player*)tester)->GetReputationMgr().GetForcedRankIfAny(target_faction))
                return *force >= REP_FRIENDLY;

            // if faction have reputation then friendly state for tester at 100% dependent from at_war state
            if(FactionEntry const* raw_target_faction = sFactionStore.LookupEntry(target_faction->faction))
                if(FactionState const* factionState = ((Player*)tester)->GetReputationMgr().GetState(raw_target_faction))
                    return !(factionState->Flags & FACTION_FLAG_AT_WAR);
        }
    }
    // CvP forced reaction and reputation case
    else if(target->GetTypeId()==TYPEID_PLAYER)
    {
        // forced reaction
        if(tester_faction->faction)
        {
            if(ReputationRank const* force =((Player*)target)->GetReputationMgr().GetForcedRankIfAny(tester_faction))
                return *force >= REP_FRIENDLY;

            // apply reputation state
            if(FactionEntry const* raw_tester_faction = sFactionStore.LookupEntry(tester_faction->faction))
                if(raw_tester_faction->reputationListID >=0 )
                    return ((Player const*)target)->GetReputationMgr().GetRank(raw_tester_faction) >= REP_FRIENDLY;
        }
    }

    // common faction based case (CvC,PvC,CvP)
    return tester_faction->IsFriendlyTo(*target_faction);
}

bool Unit::IsHostileToPlayers() const
{
    FactionTemplateEntry const* my_faction = getFactionTemplateEntry();
    if(!my_faction || !my_faction->faction)
        return false;

    FactionEntry const* raw_faction = sFactionStore.LookupEntry(my_faction->faction);
    if(raw_faction && raw_faction->reputationListID >=0 )
        return false;

    return my_faction->IsHostileToPlayers();
}

bool Unit::IsNeutralToAll() const
{
    FactionTemplateEntry const* my_faction = getFactionTemplateEntry();
    if(!my_faction || !my_faction->faction)
        return true;

    FactionEntry const* raw_faction = sFactionStore.LookupEntry(my_faction->faction);
    if(raw_faction && raw_faction->reputationListID >=0 )
        return false;

    return my_faction->IsNeutralToAll();
}

bool Unit::Attack(Unit *victim, bool meleeAttack)
{
    if(!victim || victim == this)
        return false;

    // dead units can neither attack nor be attacked
    if(!isAlive() || !victim->isAlive())
        return false;

    // player cannot attack in mount state
    if(GetTypeId()==TYPEID_PLAYER && IsMounted())
        return false;

    // nobody can attack GM in GM-mode
    if(victim->GetTypeId()==TYPEID_PLAYER)
    {
        if(((Player*)victim)->isGameMaster())
            return false;
    }
    else
    {
        if(((Creature*)victim)->IsInEvadeMode())
            return false;
    }

    // remove SPELL_AURA_MOD_UNATTACKABLE at attack (in case non-interruptible spells stun aura applied also that not let attack)
    if(HasAuraType(SPELL_AURA_MOD_UNATTACKABLE))
        RemoveAurasByType(SPELL_AURA_MOD_UNATTACKABLE);

    if (m_attacking)
    {
        if (m_attacking == victim)
        {
            // switch to melee attack from ranged/magic
            if( meleeAttack && !hasUnitState(UNIT_STAT_MELEE_ATTACKING) )
            {
                addUnitState(UNIT_STAT_MELEE_ATTACKING);
                SendAttackStart(victim);
                return true;
            }
            return false;
        }

        //switch target
        InterruptSpell(CURRENT_MELEE_SPELL);
        if(!meleeAttack)
            clearUnitState(UNIT_STAT_MELEE_ATTACKING);
    }

    if(m_attacking)
        m_attacking->_removeAttacker(this);

    m_attacking = victim;
    m_attacking->_addAttacker(this);

    //Set our target
    SetUInt64Value(UNIT_FIELD_TARGET, victim->GetGUID());

    if(meleeAttack)
        addUnitState(UNIT_STAT_MELEE_ATTACKING);

    // set position before any AI calls/assistance
    //if(GetTypeId()==TYPEID_UNIT)
    //    ((Creature*)this)->SetCombatStartPosition(GetPositionX(), GetPositionY(), GetPositionZ());

    if(GetTypeId()==TYPEID_UNIT && !IsControlledByPlayer())
    {
        // should not let player enter combat by right clicking target
        SetInCombatWith(victim);
        if(victim->GetTypeId() == TYPEID_PLAYER)
            victim->SetInCombatWith(this);
        AddThreat(victim, 0.0f);

        WorldPacket data(SMSG_AI_REACTION, 12);
        data << uint64(GetGUID());
        data << uint32(AI_REACTION_AGGRO);                  // Aggro sound
        ((WorldObject*)this)->SendMessageToSet(&data, true);

        ((Creature*)this)->CallAssistance();
    }

    // delay offhand weapon attack to next attack time
    if(haveOffhandWeapon())
        resetAttackTimer(OFF_ATTACK);

    if(meleeAttack)
        SendAttackStart(victim);

    return true;
}

bool Unit::AttackStop()
{
    if (!m_attacking)
        return false;

    Unit* victim = m_attacking;

    m_attacking->_removeAttacker(this);
    m_attacking = NULL;

    //Clear our target
    SetUInt64Value(UNIT_FIELD_TARGET, 0);

    clearUnitState(UNIT_STAT_MELEE_ATTACKING);

    InterruptSpell(CURRENT_MELEE_SPELL);

    if( GetTypeId()==TYPEID_UNIT )
    {
        // reset call assistance
        ((Creature*)this)->SetNoCallAssistance(false);
    }

    SendAttackStop(victim);

    return true;
}

void Unit::CombatStop(bool includingCast)
{
    if (includingCast && IsNonMeleeSpellCasted(false))
        InterruptNonMeleeSpells(false);

    AttackStop();
    RemoveAllAttackers();
    if( GetTypeId()==TYPEID_PLAYER )
        ((Player*)this)->SendAttackSwingCancelAttack();     // melee and ranged forced attack cancel
    ClearInCombat();
}

void Unit::CombatStopWithPets(bool includingCast)
{
    CombatStop(includingCast);

    for(ControlList::const_iterator itr = m_Controlled.begin(); itr != m_Controlled.end(); ++itr)
        (*itr)->CombatStop(includingCast);
}

bool Unit::isAttackingPlayer() const
{
    if(hasUnitState(UNIT_STAT_ATTACK_PLAYER))
        return true;

    for(ControlList::const_iterator itr = m_Controlled.begin(); itr != m_Controlled.end(); ++itr)
        if((*itr)->isAttackingPlayer())
            return true;

    for(int8 i = 0; i < MAX_SUMMON_SLOT; ++i)
        if(m_SummonSlot[i])
            if(Creature *summon = GetMap()->GetCreature(m_SummonSlot[i]))
                if(summon->isAttackingPlayer())
                    return true;

    return false;
}

void Unit::RemoveAllAttackers()
{
    while (!m_attackers.empty())
    {
        AttackerSet::iterator iter = m_attackers.begin();
        if(!(*iter)->AttackStop())
        {
            sLog.outError("WORLD: Unit has an attacker that isn't attacking it!");
            m_attackers.erase(iter);
        }
    }
}

void Unit::ModifyAuraState(AuraState flag, bool apply)
{
    if (apply)
    {
        if (!HasFlag(UNIT_FIELD_AURASTATE, 1<<(flag-1)))
        {
            SetFlag(UNIT_FIELD_AURASTATE, 1<<(flag-1));
            if(GetTypeId() == TYPEID_PLAYER)
            {
                const PlayerSpellMap& sp_list = ((Player*)this)->GetSpellMap();
                for (PlayerSpellMap::const_iterator itr = sp_list.begin(); itr != sp_list.end(); ++itr)
                {
                    if(itr->second->state == PLAYERSPELL_REMOVED) continue;
                    SpellEntry const *spellInfo = sSpellStore.LookupEntry(itr->first);
                    if (!spellInfo || !IsPassiveSpell(itr->first)) continue;
                    if (spellInfo->CasterAuraState == flag)
                        CastSpell(this, itr->first, true, NULL);
                }
            }
        }
    }
    else
    {
        if (HasFlag(UNIT_FIELD_AURASTATE,1<<(flag-1)))
        {
            RemoveFlag(UNIT_FIELD_AURASTATE, 1<<(flag-1));
            Unit::AuraMap& tAuras = GetAuras();
            for (Unit::AuraMap::iterator itr = tAuras.begin(); itr != tAuras.end();)
            {
                SpellEntry const* spellProto = (*itr).second->GetSpellProto();
                if (spellProto->CasterAuraState == flag)
                {
                    // exceptions (applied at state but not removed at state change)
                    // Rampage
                    if(spellProto->SpellIconID==2006 && spellProto->SpellFamilyName==SPELLFAMILY_WARRIOR && spellProto->SpellFamilyFlags[0]==0x100000)
                    {
                        ++itr;
                        continue;
                    }

                    RemoveAura(itr);
                }
                else
                    ++itr;
            }
        }
    }
}

bool Unit::HasAuraState(AuraState flag, SpellEntry const *spellProto, Unit * Caster) const
{
    if (Caster && spellProto)
    {
        AuraEffectList const& stateAuras = Caster->GetAurasByType(SPELL_AURA_ABILITY_IGNORE_AURASTATE);
        for(AuraEffectList::const_iterator j = stateAuras.begin();j != stateAuras.end(); ++j)
            if((*j)->isAffectedOnSpell(spellProto))
                return true;
    }
    return HasFlag(UNIT_FIELD_AURASTATE, 1<<(flag-1));
}

Unit *Unit::GetOwner() const
{
    uint64 ownerid = GetOwnerGUID();
    if(!ownerid)
        return NULL;
    return ObjectAccessor::GetUnit(*this, ownerid);
}

Unit *Unit::GetCharmer() const
{
    if(uint64 charmerid = GetCharmerGUID())
        return ObjectAccessor::GetUnit(*this, charmerid);
    return NULL;
}

Player* Unit::GetCharmerOrOwnerPlayerOrPlayerItself() const
{
    uint64 guid = GetCharmerOrOwnerGUID();
    if(IS_PLAYER_GUID(guid))
        return ObjectAccessor::GetPlayer(*this, guid);

    return GetTypeId()==TYPEID_PLAYER ? (Player*)this : NULL;
}

Minion *Unit::GetFirstMinion() const
{
    if(uint64 pet_guid = GetMinionGUID())
    {
        if(Creature* pet = ObjectAccessor::GetCreatureOrPetOrVehicle(*this, pet_guid))
            if(pet->HasSummonMask(SUMMON_MASK_MINION))
                return (Minion*)pet;

        sLog.outError("Unit::GetFirstMinion: Minion %u not exist.",GUID_LOPART(pet_guid));
        const_cast<Unit*>(this)->SetMinionGUID(0);
    }

    return NULL;
}

Guardian* Unit::GetGuardianPet() const
{
    if(uint64 pet_guid = GetPetGUID())
    {
        if(Creature* pet = ObjectAccessor::GetCreatureOrPetOrVehicle(*this, pet_guid))
            if(pet->HasSummonMask(SUMMON_MASK_GUARDIAN))
                return (Guardian*)pet;

        sLog.outError("Unit::GetGuardianPet: Guardian %u not exist.",GUID_LOPART(pet_guid));
        const_cast<Unit*>(this)->SetPetGUID(0);
    }

    return NULL;
}

Unit* Unit::GetCharm() const
{
    if(uint64 charm_guid = GetCharmGUID())
    {
        if(Unit* pet = ObjectAccessor::GetUnit(*this, charm_guid))
            return pet;

        sLog.outError("Unit::GetCharm: Charmed creature %u not exist.",GUID_LOPART(charm_guid));
        const_cast<Unit*>(this)->SetUInt64Value(UNIT_FIELD_CHARM, 0);
    }

    return NULL;
}

void Unit::SetMinion(Minion *minion, bool apply)
{
    sLog.outDebug("SetMinion %u for %u, apply %u", minion->GetEntry(), GetEntry(), apply);
    if(minion->GetOwnerGUID() != GetGUID())
    {
        sLog.outCrash("SetMinion: Minion %u is not the minion of owner %u", minion->GetEntry(), GetEntry());
        return;
    }

    if(apply)
    {
        m_Controlled.insert(minion);

        // Can only have one pet. If a new one is summoned, dismiss the old one.
        if(minion->isPet() || minion->m_Properties && minion->m_Properties->Category == SUMMON_CATEGORY_PET)
        {
            if(Guardian* oldPet = GetGuardianPet())
            {
                if(oldPet != minion && (oldPet->isPet() || minion->isPet() || oldPet->GetEntry() != minion->GetEntry()))
                {
                    // remove existing minion pet
                    if(oldPet->isPet())
                        ((Pet*)oldPet)->Remove(PET_SAVE_AS_CURRENT);
                    else
                        oldPet->UnSummon();
                    SetPetGUID(minion->GetGUID());
                    SetMinionGUID(0);
                }
            }
            else
            {
                SetPetGUID(minion->GetGUID());
                SetMinionGUID(0);
            }
        }

        // Check priority.
        if(Minion *oldMinion = GetFirstMinion())
        {
            if(minion->HasSummonMask(SUMMON_MASK_GUARDIAN)
                && !oldMinion->HasSummonMask(SUMMON_MASK_GUARDIAN))
                SetMinionGUID(0);
        }                

        // Set first minion
        if(AddUInt64Value(UNIT_FIELD_SUMMON, minion->GetGUID()))
        {
            if(GetTypeId() == TYPEID_PLAYER && !GetCharmGUID() && minion->HasSummonMask(SUMMON_MASK_GUARDIAN))
            {
                if(minion->isPet())
                    ((Player*)this)->PetSpellInitialize();
                else
                    ((Player*)this)->CharmSpellInitialize();
            }
        }

        // FIXME: hack, speed must be set only at follow
        if(HasByteFlag(UNIT_FIELD_BYTES_2, 1, UNIT_BYTE2_FLAG_FFA_PVP))
            minion->SetByteFlag(UNIT_FIELD_BYTES_2, 1, UNIT_BYTE2_FLAG_FFA_PVP);

        if(GetTypeId() == TYPEID_PLAYER && minion->HasSummonMask(SUMMON_MASK_PET))
            for(int i = 0; i < MAX_MOVE_TYPE; ++i)
                minion->SetSpeed(UnitMoveType(i), m_speed_rate[i], true);
    }
    else
    {
        m_Controlled.erase(minion);

        if(minion->isPet() || minion->m_Properties && minion->m_Properties->Category == SUMMON_CATEGORY_PET)
        {
            if(GetPetGUID() == minion->GetGUID())
                SetPetGUID(0);
        }

        if(RemoveUInt64Value(UNIT_FIELD_SUMMON, minion->GetGUID()))
        {
            //Check if there is another minion
            for(ControlList::iterator itr = m_Controlled.begin(); itr != m_Controlled.end(); ++itr)
            {
                if(GetCharmGUID() == (*itr)->GetGUID())
                    continue;

                assert((*itr)->GetOwnerGUID() == GetGUID());
                assert((*itr)->GetTypeId() == TYPEID_UNIT);
                if(AddUInt64Value(UNIT_FIELD_SUMMON, (*itr)->GetGUID()))
                {
                    //show another pet bar if there is no charm bar
                    if(GetTypeId() == TYPEID_PLAYER && !GetCharmGUID() && ((Creature*)(*itr))->HasSummonMask(SUMMON_MASK_GUARDIAN))
                    {
                        if(((Creature*)(*itr))->isPet())
                            ((Player*)this)->PetSpellInitialize();
                        else
                            ((Player*)this)->CharmSpellInitialize();
                    }
                }
                break;
            }
        }
    }
}

void Unit::SetCharm(Unit* charm, bool apply)
{
    if(apply)
    {
        if(GetTypeId() == TYPEID_PLAYER)
        {
            if(!AddUInt64Value(UNIT_FIELD_CHARM, charm->GetGUID()))
                sLog.outCrash("Player %s is trying to charm unit %u, but it already has a charmed unit %u", GetName(), charm->GetEntry(), GetCharmGUID());

            charm->m_ControlledByPlayer = true;
        }
        else
            charm->m_ControlledByPlayer = false;

        if(!charm->AddUInt64Value(UNIT_FIELD_CHARMEDBY, GetGUID()))
            sLog.outCrash("Unit %u is being charmed, but it already has a charmer %u", charm->GetEntry(), charm->GetCharmerGUID());

        m_Controlled.insert(charm);
    }
    else
    {
        if(GetTypeId() == TYPEID_PLAYER)
        {
            if(!RemoveUInt64Value(UNIT_FIELD_CHARM, charm->GetGUID()))
                sLog.outCrash("Player %s is trying to uncharm unit %u, but it has another charmed unit %u", GetName(), charm->GetEntry(), GetCharmGUID());
        }

        if(charm->GetTypeId() == TYPEID_PLAYER || IS_PLAYER_GUID(charm->GetOwnerGUID()))
            charm->m_ControlledByPlayer = true;
        else
            charm->m_ControlledByPlayer = false;

        if(!charm->RemoveUInt64Value(UNIT_FIELD_CHARMEDBY, GetGUID()))
            sLog.outCrash("Unit %u is being uncharmed, but it has another charmer %u", charm->GetEntry(), charm->GetCharmerGUID());

        m_Controlled.erase(charm);
    }
}

int32 Unit::DealHeal(Unit *pVictim, uint32 addhealth, SpellEntry const *spellProto, bool critical)
{
    int32 gain = pVictim->ModifyHealth(int32(addhealth));

    if (GetTypeId()==TYPEID_PLAYER)
    {
        SendHealSpellLog(pVictim, spellProto->Id, addhealth, critical, gain);

        if (BattleGround *bg = ((Player*)this)->GetBattleGround())
            bg->UpdatePlayerScore((Player*)this, SCORE_HEALING_DONE, gain);

        // use the actual gain, as the overheal shall not be counted, skip gain 0 (it ignored anyway in to criteria)
        if (gain)
            ((Player*)this)->GetAchievementMgr().UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_HEALING_DONE, gain, 0, pVictim);

        ((Player*)this)->GetAchievementMgr().UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_HEAL_CASTED, addhealth);
    }

    if (pVictim->GetTypeId()==TYPEID_PLAYER)
    {
        ((Player*)pVictim)->GetAchievementMgr().UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_TOTAL_HEALING_RECEIVED, gain);
        ((Player*)pVictim)->GetAchievementMgr().UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_HEALING_RECEIVED, addhealth);
    }

    return gain;
}

Unit* Unit::SelectMagnetTarget(Unit *victim, SpellEntry const *spellInfo)
{
    if(!victim)
        return NULL;

    // Magic case
    if(spellInfo && (spellInfo->DmgClass == SPELL_DAMAGE_CLASS_NONE || spellInfo->DmgClass == SPELL_DAMAGE_CLASS_MAGIC))
    {
        //I am not sure if this should be redirected.
        if(spellInfo->DmgClass == SPELL_DAMAGE_CLASS_NONE)
            return victim;

        Unit::AuraEffectList const& magnetAuras = victim->GetAurasByType(SPELL_AURA_SPELL_MAGNET);
        for(Unit::AuraEffectList::const_iterator itr = magnetAuras.begin(); itr != magnetAuras.end(); ++itr)
                if(Unit* magnet = (*itr)->IsAreaAura() ? ((AreaAuraEffect*)(*itr))->GetFormalCaster():(*itr)->GetCaster() )
                    if(magnet->isAlive())
                    {
                        if (Aura * aur = magnet->GetAura((*itr)->GetId(),(*itr)->GetCasterGUID()))
                            aur->DropAuraCharge();
                        return magnet;
                    }
    }
    // Melee && ranged case
    else
    {
        AuraEffectList const& hitTriggerAuras = victim->GetAurasByType(SPELL_AURA_ADD_CASTER_HIT_TRIGGER);
        for(AuraEffectList::const_iterator i = hitTriggerAuras.begin(); i != hitTriggerAuras.end(); ++i)
            if(Unit* magnet = (*i)->IsAreaAura() ? ((AreaAuraEffect*)(*i))->GetFormalCaster():(*i)->GetCaster() )
                if(magnet->isAlive() && magnet->IsWithinLOSInMap(this))
                    if(roll_chance_i((*i)->GetAmount()))
                    {
                        (*i)->GetParentAura()->DropAuraCharge();
                        return magnet;
                    }
    }

    return victim;
}

Unit* Unit::GetFirstControlled() const
{
    //Sequence: charmed, pet, other guardians
    Unit *unit = GetCharm();
    if(!unit)
    {
        if(uint64 guid = GetUInt64Value(UNIT_FIELD_SUMMON))
            unit = ObjectAccessor::GetUnit(*this, guid);
    }
    return unit;
}

void Unit::RemoveAllControlled()
{
    //possessed pet and vehicle
    if(GetTypeId() == TYPEID_PLAYER)
        ((Player*)this)->StopCastingCharm();

    while(!m_Controlled.empty())
    {
        Unit *target = *m_Controlled.begin();
        m_Controlled.erase(m_Controlled.begin());
        if(target->GetCharmerGUID() == GetGUID())
        {
            target->RemoveCharmAuras();
        }
        else if(target->GetOwnerGUID() == GetGUID()
            && target->GetTypeId() == TYPEID_UNIT
            && ((Creature*)target)->HasSummonMask(SUMMON_MASK_SUMMON))
        {

            if(!((TempSummon*)target)->isPet())
                ((TempSummon*)target)->UnSummon();
        }
        else
        {
            sLog.outError("Unit %u is trying to release unit %u which is neither charmed nor owned by it", GetEntry(), target->GetEntry());
        }
    }
    if(GetPetGUID() != GetUInt64Value(UNIT_FIELD_SUMMON))
        sLog.outCrash("Unit %u is not able to release its summon %u", GetEntry(), GetPetGUID());
    if(GetCharmGUID())
        sLog.outCrash("Unit %u is not able to release its charm %u", GetEntry(), GetCharmGUID());
}

Unit* Unit::GetNextRandomRaidMemberOrPet(float radius)
{
    Player* player = NULL;
    if(GetTypeId() == TYPEID_PLAYER)
        player = (Player*)this;
    // Should we enable this also for charmed units?
    else if (GetTypeId() == TYPEID_UNIT && ((Creature*)this)->isPet())
        player=(Player*)GetOwner();

    if (!player)
        return NULL;
    Group *pGroup = player->GetGroup();
    //When there is no group check pet presence
    if (!pGroup)
    {
        // We are pet now, return owner
        if(player!=this)
            return IsWithinDistInMap(player, radius) ? player : NULL;
        Unit * pet = GetGuardianPet();
        //No pet, no group, nothing to return
        if (!pet)
            return NULL;
        // We are owner now, return pet
        return IsWithinDistInMap(pet, radius) ? pet : NULL;
    }

    std::vector<Unit*> nearMembers;
    //reserve place for players and pets because resizing vector every unit push is unefficient (vector is reallocated then)
    nearMembers.reserve(pGroup->GetMembersCount()*2);

    for(GroupReference *itr = pGroup->GetFirstMember(); itr != NULL; itr = itr->next())
    {
        Player* Target = itr->getSource();

        // IsHostileTo check duel and controlled by enemy
        if( Target && Target !=this && Target->isAlive() && IsWithinDistInMap(Target, radius) &&
            !IsHostileTo(Target) )
            nearMembers.push_back(Target);

        // Push player's pet to vector
        Unit * pet = Target->GetGuardianPet();
        if (pet && pet !=this &&  pet->isAlive() && IsWithinDistInMap(pet, radius) &&
            !IsHostileTo(pet) )
            nearMembers.push_back(pet);
    }

    if (nearMembers.empty())
        return NULL;

    uint32 randTarget = urand(0,nearMembers.size()-1);
    return nearMembers[randTarget];
}

//only called in Player::SetSeer
void Unit::AddPlayerToVision(Player* plr)
{
    if(m_sharedVision.empty())
    {
        setActive(true);
        SetWorldObject(true);
    }
    m_sharedVision.push_back(plr);
}

//only called in Player::SetSeer
void Unit::RemovePlayerFromVision(Player* plr)
{
    m_sharedVision.remove(plr);
    if(m_sharedVision.empty())
    {
        setActive(false);
        SetWorldObject(false);
    }
}

void Unit::RemoveBindSightAuras()
{
    RemoveAurasByType(SPELL_AURA_BIND_SIGHT);
}

void Unit::RemoveCharmAuras()
{
    RemoveAurasByType(SPELL_AURA_MOD_CHARM);
    RemoveAurasByType(SPELL_AURA_MOD_POSSESS_PET);
    RemoveAurasByType(SPELL_AURA_MOD_POSSESS);
}

void Unit::UnsummonAllTotems()
{
    for (int8 i = 0; i < MAX_SUMMON_SLOT; ++i)
    {
        if(!m_SummonSlot[i])
            continue;

        Creature *OldTotem = GetMap()->GetCreature(m_SummonSlot[i]);
        if(OldTotem && OldTotem->isSummon())
            ((TempSummon*)OldTotem)->UnSummon();
    }
}

void Unit::SendHealSpellLog(Unit *pVictim, uint32 SpellID, uint32 Damage, bool critical, int32 gain)
{
    // we guess size
    WorldPacket data(SMSG_SPELLHEALLOG, (8+8+4+4+1));
    data.append(pVictim->GetPackGUID());
    data.append(GetPackGUID());
    data << uint32(SpellID);
    data << uint32(Damage);
    data << uint32((int32)Damage > gain ? (int32)Damage - gain : 0);       // overheal
    data << uint8(critical ? 1 : 0);
    data << uint8(0);                                       // unused in client?
    SendMessageToSet(&data, true);
}

void Unit::SendEnergizeSpellLog(Unit *pVictim, uint32 SpellID, uint32 Damage, Powers powertype)
{
    WorldPacket data(SMSG_SPELLENERGIZELOG, (8+8+4+4+4+1));
    data.append(pVictim->GetPackGUID());
    data.append(GetPackGUID());
    data << uint32(SpellID);
    data << uint32(powertype);
    data << uint32(Damage);
    SendMessageToSet(&data, true);
}

uint32 Unit::SpellDamageBonus(Unit *pVictim, SpellEntry const *spellProto, uint32 pdamage, DamageEffectType damagetype, uint32 stack)
{
    if(!spellProto || !pVictim || damagetype==DIRECT_DAMAGE )
        return pdamage;

    // For totems get damage bonus from owner (statue isn't totem in fact)
    if( GetTypeId()==TYPEID_UNIT && ((Creature*)this)->isTotem())
    {
        if(Unit* owner = GetOwner())
            return owner->SpellDamageBonus(pVictim, spellProto, pdamage, damagetype);
    }

    // Taken/Done total percent damage auras
    float DoneTotalMod = 1.0f;
    float TakenTotalMod = 1.0f;
    int32 DoneTotal = 0;
    int32 TakenTotal = 0;

    // ..done
    // Pet damage
    if( GetTypeId() == TYPEID_UNIT && !((Creature*)this)->isPet() )
        DoneTotalMod *= ((Creature*)this)->GetSpellDamageMod(((Creature*)this)->GetCreatureInfo()->rank);

    AuraEffectList const& mModDamagePercentDone = GetAurasByType(SPELL_AURA_MOD_DAMAGE_PERCENT_DONE);
    for(AuraEffectList::const_iterator i = mModDamagePercentDone.begin(); i != mModDamagePercentDone.end(); ++i)
    {
        if( ((*i)->GetMiscValue() & GetSpellSchoolMask(spellProto)) &&
            (*i)->GetSpellProto()->EquippedItemClass == -1 &&
                                                            // -1 == any item class (not wand then)
            (*i)->GetSpellProto()->EquippedItemInventoryTypeMask == 0 )
                                                            // 0 == any inventory type (not wand then)
        {
            DoneTotalMod *= ((*i)->GetAmount()+100.0f)/100.0f;
        }
    }

    uint32 creatureTypeMask = pVictim->GetCreatureTypeMask();
    // Add flat bonus from spell damage versus
    DoneTotal += GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_FLAT_SPELL_DAMAGE_VERSUS, creatureTypeMask);
    AuraEffectList const& mDamageDoneVersus = GetAurasByType(SPELL_AURA_MOD_DAMAGE_DONE_VERSUS);
    for(AuraEffectList::const_iterator i = mDamageDoneVersus.begin();i != mDamageDoneVersus.end(); ++i)
        if(creatureTypeMask & uint32((*i)->GetMiscValue()))
            DoneTotalMod *= ((*i)->GetAmount()+100.0f)/100.0f;

    // done scripted mod (take it from owner)
    Unit *owner = GetOwner();
    if (!owner) owner = this;
    AuraEffectList const& mOverrideClassScript= owner->GetAurasByType(SPELL_AURA_OVERRIDE_CLASS_SCRIPTS);
    for(AuraEffectList::const_iterator i = mOverrideClassScript.begin(); i != mOverrideClassScript.end(); ++i)
    {
        if (!(*i)->isAffectedOnSpell(spellProto))
            continue;
        switch((*i)->GetMiscValue())
        {
            case 4920: // Molten Fury
            case 4919:
            case 6917: // Death's Embrace
            case 6926:
            case 6928:
            {
                if(pVictim->HasAuraState(AURA_STATE_HEALTHLESS_35_PERCENT, spellProto, this))
                    DoneTotalMod *= (100.0f+(*i)->GetAmount())/100.0f;
                break;
            }
            // Soul Siphon
            case 4992:
            case 4993:
            {
                // effect 1 m_amount
                int32 maxPercent = (*i)->GetAmount();
                // effect 0 m_amount
                int32 stepPercent = CalculateSpellDamage((*i)->GetSpellProto(), 0, (*i)->GetSpellProto()->EffectBasePoints[0], this);
                // count affliction effects and calc additional damage in percentage
                int32 modPercent = 0;
                AuraMap const& victimAuras = pVictim->GetAuras();
                for (AuraMap::const_iterator itr = victimAuras.begin(); itr != victimAuras.end(); ++itr)
                {
                    SpellEntry const* m_spell = itr->second->GetSpellProto();
                    if (m_spell->SpellFamilyName != SPELLFAMILY_WARLOCK || !(m_spell->SpellFamilyFlags[1] & 0x0004071B || m_spell->SpellFamilyFlags[0] & 0x8044C402))
                        continue;
                    modPercent += stepPercent * itr->second->GetStackAmount();
                    if (modPercent >= maxPercent)
                    {
                        modPercent = maxPercent;
                        break;
                    }
                }
                DoneTotalMod *= (modPercent+100.0f)/100.0f;
                break;
            }
            case 6916: // Death's Embrace
            case 6925:
            case 6927:
                if (HasAuraState(AURA_STATE_HEALTHLESS_20_PERCENT, spellProto, this))
                    DoneTotalMod *= (100.0f+(*i)->GetAmount())/100.0f;
                break;
            case 5481: // Starfire Bonus
            {
                if (pVictim->GetAura(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_DRUID, 0x200002, 0))
                    DoneTotalMod *= ((*i)->GetAmount()+100.0f)/100.0f;
                break;
            }
            case 4418: // Increased Shock Damage
            case 4554: // Increased Lightning Damage
            case 4555: // Improved Moonfire
            case 5142: // Increased Lightning Damage
            case 5147: // Improved Consecration / Libram of Resurgence
            case 5148: // Idol of the Shooting Star
            case 6008: // Increased Lightning Damage / Totem of Hex
            {
                DoneTotal+=(*i)->GetAmount();
                break;
            }
            // Tundra Stalker
            // Merciless Combat
            case 7277:
            {
                // Merciless Combat
                if ((*i)->GetSpellProto()->SpellIconID == 2656)
                {
                    if(pVictim->HasAuraState(AURA_STATE_HEALTHLESS_35_PERCENT, spellProto, this))
                        DoneTotalMod *= (100.0f+(*i)->GetAmount())/100.0f;
                }
                else // Tundra Stalker
                {
                    if (pVictim->GetAura(SPELL_AURA_DUMMY, SPELLFAMILY_DEATHKNIGHT,0, 0x04000000,0))
                        DoneTotalMod *= ((*i)->GetAmount()+100.0f)/100.0f;
                    break;
                }
                break;
            }
            case 7293: // Rage of Rivendare
            {
                if (pVictim->GetAura(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_DEATHKNIGHT, 0,0x02000000,0))
                    DoneTotalMod *= ((*i)->GetAmount()+100.0f)/100.0f;
                break;
            }
            // Twisted Faith
            case 7377:
            {
                if (pVictim->GetAura(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_PRIEST, 0x8000, 0,0, GetGUID()))
                    DoneTotalMod *= ((*i)->GetAmount()+100.0f)/100.0f;
                break;
            }
            // Marked for Death
            case 7598:
            case 7599:
            case 7600:
            case 7601:
            case 7602:
            {
                if (pVictim->GetAura(SPELL_AURA_MOD_STALKED, SPELLFAMILY_HUNTER, 0x400, 0))
                    DoneTotalMod *= ((*i)->GetAmount()+100.0f)/100.0f;
                break;
            }
        }
    }

    // Custom scripted damage
    // Ice Lance
    if (spellProto->SpellFamilyName == SPELLFAMILY_MAGE && spellProto->SpellIconID == 186)
    {
        if (pVictim->HasAuraState(AURA_STATE_FROZEN, spellProto, this))
            DoneTotalMod *= 3.0f;
    }

    // Torment the weak
    if (spellProto->SpellFamilyName== SPELLFAMILY_MAGE && (spellProto->SpellFamilyFlags[0]&0x20200021 || spellProto->SpellFamilyFlags[1]& 0x9000))
    {
        if(pVictim->HasAuraType(SPELL_AURA_MOD_DECREASE_SPEED))
        {
            AuraEffectList const& mDumyAuras = GetAurasByType(SPELL_AURA_DUMMY);
            for(AuraEffectList::const_iterator i = mDumyAuras.begin(); i != mDumyAuras.end(); ++i)
            {
                if ((*i)->GetSpellProto()->SpellIconID == 3263)
                {
                    DoneTotalMod *=float((*i)->GetAmount() + 100.f) / 100.f;
                    break;
                }
            }
        }
    }

    // ..taken
    AuraEffectList const& mModDamagePercentTaken = pVictim->GetAurasByType(SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN);
    for(AuraEffectList::const_iterator i = mModDamagePercentTaken.begin(); i != mModDamagePercentTaken.end(); ++i)
        if( (*i)->GetMiscValue() & GetSpellSchoolMask(spellProto) )
            TakenTotalMod *= ((*i)->GetAmount()+100.0f)/100.0f;

    // .. taken pct: dummy auras
    if (pVictim->GetTypeId() == TYPEID_PLAYER)
    {
        //Cheat Death
        if (AuraEffect *dummy = pVictim->GetDummyAura(45182))
        {
            float mod = -((Player*)pVictim)->GetRatingBonusValue(CR_CRIT_TAKEN_SPELL)*2*4;
            if (mod < dummy->GetAmount())
                mod = dummy->GetAmount();
            TakenTotalMod *= (mod+100.0f)/100.0f;
        }
    }

    // From caster spells
    AuraEffectList const& mOwnerTaken = pVictim->GetAurasByType(SPELL_AURA_MOD_DAMAGE_FROM_CASTER);
    for(AuraEffectList::const_iterator i = mOwnerTaken.begin(); i != mOwnerTaken.end(); ++i)
        if( (*i)->GetCasterGUID() == GetGUID() && (*i)->isAffectedOnSpell(spellProto))
            TakenTotalMod *= ((*i)->GetAmount()+100.0f)/100.0f;

    // Mod damage from spell mechanic
    uint32 mechanicMask = GetAllSpellMechanicMask(spellProto);
    if (mechanicMask)
    {
        AuraEffectList const& mDamageDoneMechanic = pVictim->GetAurasByType(SPELL_AURA_MOD_MECHANIC_DAMAGE_TAKEN_PERCENT);
        for(AuraEffectList::const_iterator i = mDamageDoneMechanic.begin();i != mDamageDoneMechanic.end(); ++i)
            if(mechanicMask & uint32(1<<((*i)->GetMiscValue())))
                TakenTotalMod *= ((*i)->GetAmount()+100.0f)/100.0f;
    }

    // Taken/Done fixed damage bonus auras
    int32 DoneAdvertisedBenefit  = SpellBaseDamageBonus(GetSpellSchoolMask(spellProto));
    int32 TakenAdvertisedBenefit = SpellBaseDamageBonusForVictim(GetSpellSchoolMask(spellProto), pVictim);
    // Pets just add their bonus damage to their spell damage
    // note that their spell damage is just gain of their own auras
    if (GetTypeId() == TYPEID_UNIT && ((Creature*)this)->HasSummonMask(SUMMON_MASK_GUARDIAN))
        DoneAdvertisedBenefit += ((Guardian*)this)->GetBonusDamage();

    // Check for table values
    float coeff;
    SpellBonusEntry const* bonus = spellmgr.GetSpellBonusData(spellProto->Id);
    if (bonus)
    {
        if (damagetype == DOT)
            coeff = bonus->dot_damage;
        else
            coeff = bonus->direct_damage;
        if (bonus->ap_bonus)
            DoneTotal+=bonus->ap_bonus * GetTotalAttackPowerValue(BASE_ATTACK) * stack;
    }
    // Default calculation
    if (DoneAdvertisedBenefit || TakenAdvertisedBenefit)
    {
        if(!bonus)
        {
        // Damage Done from spell damage bonus
        int32 CastingTime = !IsChanneledSpell(spellProto) ? GetSpellCastTime(spellProto) : GetSpellDuration(spellProto);
        // Damage over Time spells bonus calculation
        float DotFactor = 1.0f;
        if(damagetype == DOT)
        {
            int32 DotDuration = GetSpellDuration(spellProto);
            // 200% limit
            if(DotDuration > 0)
            {
                if(DotDuration > 30000) DotDuration = 30000;
                if(!IsChanneledSpell(spellProto)) DotFactor = DotDuration / 15000.0f;
                int x = 0;
                for(int j = 0; j < 3; j++)
                {
                    if( spellProto->Effect[j] == SPELL_EFFECT_APPLY_AURA && (
                        spellProto->EffectApplyAuraName[j] == SPELL_AURA_PERIODIC_DAMAGE ||
                        spellProto->EffectApplyAuraName[j] == SPELL_AURA_PERIODIC_LEECH) )
                    {
                        x = j;
                        break;
                    }
                }
                int32 DotTicks = 6;
                if(spellProto->EffectAmplitude[x] != 0)
                    DotTicks = DotDuration / spellProto->EffectAmplitude[x];
                if(DotTicks)
                {
                    DoneAdvertisedBenefit /= DotTicks;
                    TakenAdvertisedBenefit /= DotTicks;
                }
            }
        }
        // Distribute Damage over multiple effects, reduce by AoE
        CastingTime = GetCastingTimeForBonus( spellProto, damagetype, CastingTime );

        // 50% for damage and healing spells for leech spells from damage bonus and 0% from healing
        for(int j = 0; j < 3; ++j)
        {
            if( spellProto->Effect[j] == SPELL_EFFECT_HEALTH_LEECH ||
                spellProto->Effect[j] == SPELL_EFFECT_APPLY_AURA && spellProto->EffectApplyAuraName[j] == SPELL_AURA_PERIODIC_LEECH )
            {
                CastingTime /= 2;
                break;
            }
        }
        if(spellProto->SchoolMask != SPELL_SCHOOL_MASK_NORMAL)
            coeff = (CastingTime / 3500.0f) * DotFactor;
        else
            coeff = DotFactor;
        }

        float coeff2 = CalculateLevelPenalty(spellProto) * stack;
        if(spellProto->SpellFamilyName) //TODO: fix this
            TakenTotal+= TakenAdvertisedBenefit * coeff * coeff2;
        if(Player* modOwner = GetSpellModOwner())
        {
            coeff *= 100.0f;
            modOwner->ApplySpellMod(spellProto->Id, SPELLMOD_SPELL_BONUS_DAMAGE, coeff);
            coeff /= 100.0f;
        }
        DoneTotal += DoneAdvertisedBenefit * coeff * coeff2;
    }

    float tmpDamage = (pdamage + DoneTotal) * DoneTotalMod;
    // apply spellmod to Done damage (flat and pct)
    if(Player* modOwner = GetSpellModOwner())
        modOwner->ApplySpellMod(spellProto->Id, damagetype == DOT ? SPELLMOD_DOT : SPELLMOD_DAMAGE, tmpDamage);

    tmpDamage = (tmpDamage + TakenTotal) * TakenTotalMod;

    return tmpDamage > 0 ? uint32(tmpDamage) : 0;
}

int32 Unit::SpellBaseDamageBonus(SpellSchoolMask schoolMask)
{
    int32 DoneAdvertisedBenefit = 0;

    // ..done
    AuraEffectList const& mDamageDone = GetAurasByType(SPELL_AURA_MOD_DAMAGE_DONE);
    for(AuraEffectList::const_iterator i = mDamageDone.begin();i != mDamageDone.end(); ++i)
        if(((*i)->GetMiscValue() & schoolMask) != 0 &&
        (*i)->GetSpellProto()->EquippedItemClass == -1 &&
                                                            // -1 == any item class (not wand then)
        (*i)->GetSpellProto()->EquippedItemInventoryTypeMask == 0 )
                                                            // 0 == any inventory type (not wand then)
            DoneAdvertisedBenefit += (*i)->GetAmount();

    if (GetTypeId() == TYPEID_PLAYER)
    {
        // Base value
        DoneAdvertisedBenefit +=((Player*)this)->GetBaseSpellDamageBonus();

        // Damage bonus from stats
        AuraEffectList const& mDamageDoneOfStatPercent = GetAurasByType(SPELL_AURA_MOD_SPELL_DAMAGE_OF_STAT_PERCENT);
        for(AuraEffectList::const_iterator i = mDamageDoneOfStatPercent.begin();i != mDamageDoneOfStatPercent.end(); ++i)
        {
            if((*i)->GetMiscValue() & schoolMask)
            {
                // stat used stored in miscValueB for this aura
                Stats usedStat = Stats((*i)->GetMiscBValue());
                DoneAdvertisedBenefit += int32(GetStat(usedStat) * (*i)->GetAmount() / 100.0f);
            }
        }
        // ... and attack power
        AuraEffectList const& mDamageDonebyAP = GetAurasByType(SPELL_AURA_MOD_SPELL_DAMAGE_OF_ATTACK_POWER);
        for(AuraEffectList::const_iterator i =mDamageDonebyAP.begin();i != mDamageDonebyAP.end(); ++i)
            if ((*i)->GetMiscValue() & schoolMask)
                DoneAdvertisedBenefit += int32(GetTotalAttackPowerValue(BASE_ATTACK) * (*i)->GetAmount() / 100.0f);

    }
    return DoneAdvertisedBenefit;
}

int32 Unit::SpellBaseDamageBonusForVictim(SpellSchoolMask schoolMask, Unit *pVictim)
{
    uint32 creatureTypeMask = pVictim->GetCreatureTypeMask();

    int32 TakenAdvertisedBenefit = 0;
    // ..done (for creature type by mask) in taken
    AuraEffectList const& mDamageDoneCreature = GetAurasByType(SPELL_AURA_MOD_DAMAGE_DONE_CREATURE);
    for(AuraEffectList::const_iterator i = mDamageDoneCreature.begin();i != mDamageDoneCreature.end(); ++i)
        if(creatureTypeMask & uint32((*i)->GetMiscValue()))
            TakenAdvertisedBenefit += (*i)->GetAmount();

    // ..taken
    AuraEffectList const& mDamageTaken = pVictim->GetAurasByType(SPELL_AURA_MOD_DAMAGE_TAKEN);
    for(AuraEffectList::const_iterator i = mDamageTaken.begin();i != mDamageTaken.end(); ++i)
        if(((*i)->GetMiscValue() & schoolMask) != 0)
            TakenAdvertisedBenefit += (*i)->GetAmount();

    return TakenAdvertisedBenefit;
}

bool Unit::isSpellCrit(Unit *pVictim, SpellEntry const *spellProto, SpellSchoolMask schoolMask, WeaponAttackType attackType)
{
    // not critting spell
    if((spellProto->AttributesEx2 & SPELL_ATTR_EX2_CANT_CRIT))
        return false;

    float crit_chance = 0.0f;
    switch(spellProto->DmgClass)
    {
        case SPELL_DAMAGE_CLASS_NONE:
            return false;
        case SPELL_DAMAGE_CLASS_MAGIC:
        {
            if (schoolMask & SPELL_SCHOOL_MASK_NORMAL)
                crit_chance = 0.0f;
            // For other schools
            else if (GetTypeId() == TYPEID_PLAYER)
                crit_chance = GetFloatValue( PLAYER_SPELL_CRIT_PERCENTAGE1 + GetFirstSchoolInMask(schoolMask));
            else
            {
                crit_chance = m_baseSpellCritChance;
                crit_chance += GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_SPELL_CRIT_CHANCE_SCHOOL, schoolMask);
            }
            // taken
            if (pVictim)
            {
                if (!IsPositiveSpell(spellProto->Id))
                {
                    // Modify critical chance by victim SPELL_AURA_MOD_ATTACKER_SPELL_CRIT_CHANCE
                    crit_chance += pVictim->GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_ATTACKER_SPELL_CRIT_CHANCE, schoolMask);
                    // Modify critical chance by victim SPELL_AURA_MOD_ATTACKER_SPELL_AND_WEAPON_CRIT_CHANCE
                    crit_chance += pVictim->GetTotalAuraModifier(SPELL_AURA_MOD_ATTACKER_SPELL_AND_WEAPON_CRIT_CHANCE);
                    // Modify by player victim resilience
                    if (pVictim->GetTypeId() == TYPEID_PLAYER)
                        crit_chance -= ((Player*)pVictim)->GetRatingBonusValue(CR_CRIT_TAKEN_SPELL);
                }
                // scripted (increase crit chance ... against ... target by x%
                AuraEffectList const& mOverrideClassScript = GetAurasByType(SPELL_AURA_OVERRIDE_CLASS_SCRIPTS);
                for(AuraEffectList::const_iterator i = mOverrideClassScript.begin(); i != mOverrideClassScript.end(); ++i)
                {
                    if (!((*i)->isAffectedOnSpell(spellProto)))
                        continue;
                    int32 modChance=0;
                    switch((*i)->GetMiscValue())
                    {
                        // Shatter
                        case  911: modChance+= 16.0f;
                        case  910: modChance+= 17.0f;
                        case  849: modChance+= 17.0f;
                            if (!pVictim->HasAuraState(AURA_STATE_FROZEN, spellProto, this))
                                break;
                            crit_chance+=modChance;
                            // Fingers of Frost
                            // TODO: Change this code to less hacky
                            if (Aura * aur = GetAura(44544))
                                aur->DropAuraCharge();
                            break;
                        case 7917: // Glyph of Shadowburn
                            if (pVictim->HasAuraState(AURA_STATE_HEALTHLESS_35_PERCENT, spellProto, this))
                                crit_chance+=(*i)->GetAmount();
                            break;
                        case 7997: // Renewed Hope
                        case 7998:
                            if (pVictim->HasAura(6788))
                                crit_chance+=(*i)->GetAmount();
                            break;
                        case   21: // Test of Faith
                        case 6935:
                        case 6918:
                            if (pVictim->GetHealth() < pVictim->GetMaxHealth()/2)
                                crit_chance+=(*i)->GetAmount();
                            break;
                        default:
                            break;
                    }
                }
                // Custom crit by class
                switch(spellProto->SpellFamilyName)
                {
                    case SPELLFAMILY_PALADIN:
                        // Sacred Shield
                        if (spellProto->SpellFamilyFlags[0] & 0x40000000)
                        {
                            AuraEffect *aura = pVictim->GetDummyAura(58597);
                            if (aura && aura->GetCasterGUID() == GetGUID())
                            crit_chance+=aura->GetAmount();
                            break;
                        }
                    break;
                    case SPELLFAMILY_SHAMAN:
                        // Lava Burst
                        if (spellProto->SpellFamilyFlags[1] & 0x00001000)
                        {
                            if (AuraEffect *flameShock = pVictim->GetAura(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_SHAMAN, 10000000, 0,0, GetGUID()))
                            {
                                // Consume shock aura if not have Glyph of Flame Shock
                                if (!GetAuraEffect(55447, 0))
                                    pVictim->RemoveAurasDueToSpell(flameShock->GetId(), GetGUID());
                                return true;
                            }
                            break;
                        }
                    break;

                }
            }
            break;
        }
        case SPELL_DAMAGE_CLASS_MELEE:
        case SPELL_DAMAGE_CLASS_RANGED:
        {
            if (pVictim)
            {
                crit_chance = GetUnitCriticalChance(attackType, pVictim);
                crit_chance+= GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_SPELL_CRIT_CHANCE_SCHOOL, schoolMask);
            }
            break;
        }
        default:
            return false;
    }
    // percent done
    // only players use intelligence for critical chance computations
    if(Player* modOwner = GetSpellModOwner())
        modOwner->ApplySpellMod(spellProto->Id, SPELLMOD_CRITICAL_CHANCE, crit_chance);

    crit_chance = crit_chance > 0.0f ? crit_chance : 0.0f;
    if (roll_chance_f(crit_chance))
        return true;
    return false;
}

uint32 Unit::SpellCriticalDamageBonus(SpellEntry const *spellProto, uint32 damage, Unit *pVictim)
{
    // Calculate critical bonus
    int32 crit_bonus;
    switch(spellProto->DmgClass)
    {
        case SPELL_DAMAGE_CLASS_MELEE:                      // for melee based spells is 100%
        case SPELL_DAMAGE_CLASS_RANGED:
            // TODO: write here full calculation for melee/ranged spells
            crit_bonus = damage;
            break;
        default:
            crit_bonus = damage / 2;                        // for spells is 50%
            break;
    }

    // adds additional damage to crit_bonus (from talents)
    if(Player* modOwner = GetSpellModOwner())
        modOwner->ApplySpellMod(spellProto->Id, SPELLMOD_CRIT_DAMAGE_BONUS, crit_bonus);

    if(pVictim)
    {
        uint32 creatureTypeMask = pVictim->GetCreatureTypeMask();
        crit_bonus = int32(crit_bonus * GetTotalAuraMultiplierByMiscMask(SPELL_AURA_MOD_CRIT_PERCENT_VERSUS, creatureTypeMask));
    }

    if(crit_bonus > 0)
        damage += crit_bonus;

    return damage;
}

uint32 Unit::SpellCriticalHealingBonus(SpellEntry const *spellProto, uint32 damage, Unit *pVictim)
{
    // Calculate critical bonus
    int32 crit_bonus;
    switch(spellProto->DmgClass)
    {
        case SPELL_DAMAGE_CLASS_MELEE:                      // for melee based spells is 100%
        case SPELL_DAMAGE_CLASS_RANGED:
            // TODO: write here full calculation for melee/ranged spells
            crit_bonus = damage;
            break;
        default:
            crit_bonus = damage / 2;                        // for spells is 50%
            break;
    }


    if(pVictim)
    {
        uint32 creatureTypeMask = pVictim->GetCreatureTypeMask();
        crit_bonus = int32(crit_bonus * GetTotalAuraMultiplierByMiscMask(SPELL_AURA_MOD_CRIT_PERCENT_VERSUS, creatureTypeMask));
    }

    if(crit_bonus > 0)
        damage += crit_bonus;

    damage = int32(float(damage) * GetTotalAuraMultiplier(SPELL_AURA_MOD_CRITICAL_HEALING_AMOUNT));

    return damage;
}

uint32 Unit::SpellHealingBonus(Unit *pVictim, SpellEntry const *spellProto, uint32 healamount, DamageEffectType damagetype, uint32 stack)
{
    // No heal amount for this class spells
    if (spellProto->DmgClass == SPELL_DAMAGE_CLASS_NONE)
        return healamount;

    // For totems get healing bonus from owner (statue isn't totem in fact)
    if( GetTypeId()==TYPEID_UNIT && ((Creature*)this)->isTotem())
        if(Unit* owner = GetOwner())
            return owner->SpellHealingBonus(pVictim, spellProto, healamount, damagetype, stack);

    // Healing Done
    // Taken/Done total percent damage auras
    float  DoneTotalMod = 1.0f;
    float  TakenTotalMod = 1.0f;
    int32  DoneTotal = 0;
    int32  TakenTotal = 0;

    // Healing done percent
    AuraEffectList const& mHealingDonePct = GetAurasByType(SPELL_AURA_MOD_HEALING_DONE_PERCENT);
    for(AuraEffectList::const_iterator i = mHealingDonePct.begin();i != mHealingDonePct.end(); ++i)
        DoneTotalMod *= (100.0f + (*i)->GetAmount()) / 100.0f;

    // done scripted mod (take it from owner)
    Unit *owner = GetOwner();
    if (!owner) owner = this;
    AuraEffectList const& mOverrideClassScript= owner->GetAurasByType(SPELL_AURA_OVERRIDE_CLASS_SCRIPTS);
    for(AuraEffectList::const_iterator i = mOverrideClassScript.begin(); i != mOverrideClassScript.end(); ++i)
    {
        if (!(*i)->isAffectedOnSpell(spellProto))
            continue;
        switch((*i)->GetMiscValue())
        {
            case 4415: // Increased Rejuvenation Healing
            case 4953:
            case 3736: // Hateful Totem of the Third Wind / Increased Lesser Healing Wave / LK Arena (4/5/6) Totem of the Third Wind / Savage Totem of the Third Wind
                DoneTotal+=(*i)->GetAmount();
                break;
            case 7997: // Renewed Hope
            case 7998:
                if (pVictim->HasAura(6788))
                    DoneTotalMod *=((*i)->GetAmount() + 100.0f)/100.0f;
                break;
            case   21: // Test of Faith
            case 6935:
            case 6918:
                if (pVictim->GetHealth() < pVictim->GetMaxHealth()/2)
                    DoneTotalMod *=((*i)->GetAmount() + 100.0f)/100.0f;
                break;
            case 7798: // Glyph of Regrowth
            {
                if (pVictim->GetAura(SPELL_AURA_PERIODIC_HEAL, SPELLFAMILY_DRUID, 0x40, 0))
                    DoneTotalMod *= ((*i)->GetAmount()+100.0f)/100.0f;
                break;
            }
            case 8477: // Nourish Heal Boost
            {
                int32 stepPercent = (*i)->GetAmount();
                int32 modPercent = 0;
                AuraMap const& victimAuras = pVictim->GetAuras();
                for (AuraMap::const_iterator itr = victimAuras.begin(); itr != victimAuras.end(); ++itr)
                {
                    if (itr->second->GetCasterGUID()!=GetGUID())
                        continue;
                    SpellEntry const* m_spell = itr->second->GetSpellProto();
                    if ( m_spell->SpellFamilyName != SPELLFAMILY_DRUID ||
                        !(m_spell->SpellFamilyFlags[1] & 0x00000010 || m_spell->SpellFamilyFlags[0] & 0x50))
                        continue;
                    modPercent += stepPercent * itr->second->GetStackAmount();
                }
                DoneTotalMod *= (modPercent+100.0f)/100.0f;
                break;
            }
            case 7871: // Glyph of Lesser Healing Wave
            {
                if (pVictim->GetAura(SPELL_AURA_DUMMY, SPELLFAMILY_SHAMAN, 0 , 0x00000400, 0, GetGUID()))
                    DoneTotalMod *= ((*i)->GetAmount()+100.0f)/100.0f;
                break;
            }
            default:
                break;
        }
    }

    // Taken/Done fixed damage bonus auras
    int32 DoneAdvertisedBenefit  = SpellBaseHealingBonus(GetSpellSchoolMask(spellProto));
    int32 TakenAdvertisedBenefit = SpellBaseHealingBonusForVictim(GetSpellSchoolMask(spellProto), pVictim);

    // Check for table values
    SpellBonusEntry const* bonus = spellmgr.GetSpellBonusData(spellProto->Id);
    float coeff;
    float factorMod = 1.0f;
    bool scripted = false;
    if (bonus)
    {
        if (damagetype == DOT)
            coeff = bonus->dot_damage;
        else
            coeff = bonus->direct_damage;
        if (bonus->ap_bonus)
            DoneTotal+=bonus->ap_bonus * GetTotalAttackPowerValue(BASE_ATTACK) * stack;
    }
    else // scripted bonus
    {
        // Gift of the Naaru
        if (spellProto->Id==59547)
        {
            scripted = true;
            uint32 apBonus = GetTotalAttackPowerValue(BASE_ATTACK);
            if (apBonus > DoneAdvertisedBenefit)
            {
                DoneTotal+=apBonus * stack;
                coeff = 0.0f;
            }
            else
                coeff = 1.0f;
        }
        // Earthliving - 0.45% of normal hot coeff
        else if (spellProto->SpellFamilyName==SPELLFAMILY_SHAMAN && spellProto->SpellFamilyFlags[1] & 0x80000)
        {
            factorMod *= 0.45f;
        }
    }

    // Default calculation
    if (DoneAdvertisedBenefit || TakenAdvertisedBenefit)
    {
        if(!bonus && !scripted)
        {
            // Damage Done from spell damage bonus
            int32 CastingTime = !IsChanneledSpell(spellProto) ? GetSpellCastTime(spellProto) : GetSpellDuration(spellProto);
            // Damage over Time spells bonus calculation
            float DotFactor = 1.0f;
            if(damagetype == DOT)
            {
                int32 DotDuration = GetSpellDuration(spellProto);
                // 200% limit
                if(DotDuration > 0)
                {
                    if(DotDuration > 30000) DotDuration = 30000;
                    if(!IsChanneledSpell(spellProto)) DotFactor = DotDuration / 15000.0f;
                    int x = 0;
                    for(int j = 0; j < 3; j++)
                    {
                        if( spellProto->Effect[j] == SPELL_EFFECT_APPLY_AURA && (
                            spellProto->EffectApplyAuraName[j] == SPELL_AURA_PERIODIC_DAMAGE ||
                            spellProto->EffectApplyAuraName[j] == SPELL_AURA_PERIODIC_LEECH) )
                        {
                            x = j;
                            break;
                        }
                    }
                    int32 DotTicks = 6;
                    if(spellProto->EffectAmplitude[x] != 0)
                        DotTicks = DotDuration / spellProto->EffectAmplitude[x];
                    if(DotTicks)
                    {
                        DoneAdvertisedBenefit = DoneAdvertisedBenefit * int32(stack) / DotTicks;
                        TakenAdvertisedBenefit = TakenAdvertisedBenefit * int32(stack) / DotTicks;
                    }
                }
            }
            // Distribute Damage over multiple effects, reduce by AoE
            CastingTime = GetCastingTimeForBonus( spellProto, damagetype, CastingTime );
            // 50% for damage and healing spells for leech spells from damage bonus and 0% from healing
            for(int j = 0; j < 3; ++j)
            {
                if( spellProto->Effect[j] == SPELL_EFFECT_HEALTH_LEECH ||
                    spellProto->Effect[j] == SPELL_EFFECT_APPLY_AURA && spellProto->EffectApplyAuraName[j] == SPELL_AURA_PERIODIC_LEECH )
                {
                    CastingTime /= 2;
                    break;
                }
            }
            // As wowwiki says: C = (Cast Time / 3.5) * 1.88 (for healing spells)
            coeff = (CastingTime / 3500.0f) * DotFactor * 1.88f;
        }

        factorMod *= CalculateLevelPenalty(spellProto)* stack;
        TakenTotal += TakenAdvertisedBenefit * coeff * factorMod;
        if(Player* modOwner = GetSpellModOwner())
        {
            coeff *= 100.0f;
            modOwner->ApplySpellMod(spellProto->Id, SPELLMOD_SPELL_BONUS_DAMAGE, coeff);
            coeff /= 100.0f;
        }
        DoneTotal += DoneAdvertisedBenefit * coeff * factorMod;
    }

    // use float as more appropriate for negative values and percent applying
    float heal = (healamount + DoneTotal)*DoneTotalMod;
    // apply spellmod to Done amount
    if(Player* modOwner = GetSpellModOwner())
        modOwner->ApplySpellMod(spellProto->Id, damagetype == DOT ? SPELLMOD_DOT : SPELLMOD_DAMAGE, heal);

    // Nourish cast
    if (spellProto->SpellFamilyName == SPELLFAMILY_DRUID && spellProto->SpellFamilyFlags[1] & 0x2000000)
    {
        // Rejuvenation, Regrowth, Lifebloom, or Wild Growth
        if (pVictim->GetAura(SPELL_AURA_PERIODIC_HEAL, SPELLFAMILY_DRUID, 0x50, 0x4000010, 0))
            //increase healing by 20%
            TakenTotalMod *= 1.2f;
    }

    // Taken mods
    // Healing Wave cast
    if (spellProto->SpellFamilyName == SPELLFAMILY_SHAMAN && spellProto->SpellFamilyFlags[0] & 0x40)
    {
        // Search for Healing Way on Victim
        Unit::AuraEffectList const& auraDummy = pVictim->GetAurasByType(SPELL_AURA_DUMMY);
        for(Unit::AuraEffectList::const_iterator itr = auraDummy.begin(); itr!=auraDummy.end(); ++itr)
            if((*itr)->GetId() == 29203)
                TakenTotalMod *= ((*itr)->GetAmount()+100.0f) / 100.0f;
    }

    // Healing taken percent
    float minval = pVictim->GetMaxNegativeAuraModifier(SPELL_AURA_MOD_HEALING_PCT);
    if(minval)
        TakenTotalMod *= (100.0f + minval) / 100.0f;

    float maxval = pVictim->GetMaxPositiveAuraModifier(SPELL_AURA_MOD_HEALING_PCT);
    if(maxval)
        TakenTotalMod *= (100.0f + maxval) / 100.0f;

    if(damagetype==DOT)
    {
        // Healing over time taken percent
        float minval_hot = pVictim->GetMaxNegativeAuraModifier(SPELL_AURA_MOD_HOT_PCT);
        if(minval_hot)
            TakenTotalMod *= (100.0f + minval_hot) / 100.0f;

        float maxval_hot = pVictim->GetMaxPositiveAuraModifier(SPELL_AURA_MOD_HOT_PCT);
        if(maxval_hot)
            TakenTotalMod *= (100.0f + maxval_hot) / 100.0f;
    }

    AuraEffectList const& mHealingGet= pVictim->GetAurasByType(SPELL_AURA_MOD_HEALING_RECEIVED);
    for(AuraEffectList::const_iterator i = mHealingGet.begin(); i != mHealingGet.end(); ++i)
        if (GetGUID()==(*i)->GetCasterGUID() && (*i)->isAffectedOnSpell(spellProto) )
            TakenTotalMod *= ((*i)->GetAmount() + 100.0f) / 100.0f;

    heal = (heal + TakenTotal) * TakenTotalMod;

    return heal < 0 ? 0 : uint32(heal);
}

int32 Unit::SpellBaseHealingBonus(SpellSchoolMask schoolMask)
{
    int32 AdvertisedBenefit = 0;

    AuraEffectList const& mHealingDone = GetAurasByType(SPELL_AURA_MOD_HEALING_DONE);
    for(AuraEffectList::const_iterator i = mHealingDone.begin();i != mHealingDone.end(); ++i)
        if(((*i)->GetMiscValue() & schoolMask) != 0)
            AdvertisedBenefit += (*i)->GetAmount();

    // Healing bonus of spirit, intellect and strength
    if (GetTypeId() == TYPEID_PLAYER)
    {
        // Base value
        AdvertisedBenefit +=((Player*)this)->GetBaseSpellHealingBonus();

        // Healing bonus from stats
        AuraEffectList const& mHealingDoneOfStatPercent = GetAurasByType(SPELL_AURA_MOD_SPELL_HEALING_OF_STAT_PERCENT);
        for(AuraEffectList::const_iterator i = mHealingDoneOfStatPercent.begin();i != mHealingDoneOfStatPercent.end(); ++i)
        {
            // stat used dependent from misc value (stat index)
            Stats usedStat = Stats((*i)->GetSpellProto()->EffectMiscValue[(*i)->GetEffIndex()]);
            AdvertisedBenefit += int32(GetStat(usedStat) * (*i)->GetAmount() / 100.0f);
        }

        // ... and attack power
        AuraEffectList const& mHealingDonebyAP = GetAurasByType(SPELL_AURA_MOD_SPELL_HEALING_OF_ATTACK_POWER);
        for(AuraEffectList::const_iterator i = mHealingDonebyAP.begin();i != mHealingDonebyAP.end(); ++i)
            if ((*i)->GetMiscValue() & schoolMask)
                AdvertisedBenefit += int32(GetTotalAttackPowerValue(BASE_ATTACK) * (*i)->GetAmount() / 100.0f);
    }
    return AdvertisedBenefit;
}

int32 Unit::SpellBaseHealingBonusForVictim(SpellSchoolMask schoolMask, Unit *pVictim)
{
    int32 AdvertisedBenefit = 0;
    AuraEffectList const& mDamageTaken = pVictim->GetAurasByType(SPELL_AURA_MOD_HEALING);
    for(AuraEffectList::const_iterator i = mDamageTaken.begin();i != mDamageTaken.end(); ++i)
        if(((*i)->GetMiscValue() & schoolMask) != 0)
            AdvertisedBenefit += (*i)->GetAmount();
    return AdvertisedBenefit;
}

bool Unit::IsImmunedToDamage(SpellSchoolMask shoolMask)
{
    //If m_immuneToSchool type contain this school type, IMMUNE damage.
    SpellImmuneList const& schoolList = m_spellImmune[IMMUNITY_SCHOOL];
    for (SpellImmuneList::const_iterator itr = schoolList.begin(); itr != schoolList.end(); ++itr)
        if(itr->type & shoolMask)
            return true;

    //If m_immuneToDamage type contain magic, IMMUNE damage.
    SpellImmuneList const& damageList = m_spellImmune[IMMUNITY_DAMAGE];
    for (SpellImmuneList::const_iterator itr = damageList.begin(); itr != damageList.end(); ++itr)
        if(itr->type & shoolMask)
            return true;

    return false;
}

bool Unit::IsImmunedToDamage(SpellEntry const* spellInfo)
{
    if(spellInfo->Attributes & SPELL_ATTR_UNAFFECTED_BY_INVULNERABILITY)
        return false;

    uint32 shoolMask = GetSpellSchoolMask(spellInfo);
    if(!(spellInfo->AttributesEx &
        (SPELL_ATTR_EX_UNAFFECTED_BY_SCHOOL_IMMUNE | SPELL_ATTR_EX_DISPEL_AURAS_ON_IMMUNITY))               // can remove immune (by dispell or immune it)
        && spellInfo->Id != 42292)
    {
        //If m_immuneToSchool type contain this school type, IMMUNE damage.
        SpellImmuneList const& schoolList = m_spellImmune[IMMUNITY_SCHOOL];
        for (SpellImmuneList::const_iterator itr = schoolList.begin(); itr != schoolList.end(); ++itr)
            if(itr->type & shoolMask &&!IsDispelableBySpell(spellInfo, itr->spellId))
                return true;
    }

    //If m_immuneToDamage type contain magic, IMMUNE damage.
    SpellImmuneList const& damageList = m_spellImmune[IMMUNITY_DAMAGE];
    for (SpellImmuneList::const_iterator itr = damageList.begin(); itr != damageList.end(); ++itr)
        if(itr->type & shoolMask)
            return true;

    return false;
}

bool Unit::IsImmunedToSpell(SpellEntry const* spellInfo)
{
    if (!spellInfo)
        return false;

    // Single spell immunity.
    SpellImmuneList const& idList = m_spellImmune[IMMUNITY_ID];
    for(SpellImmuneList::const_iterator itr = idList.begin(); itr != idList.end(); ++itr)
        if(itr->type == spellInfo->Id)
            return true;

    if(spellInfo->Attributes & SPELL_ATTR_UNAFFECTED_BY_INVULNERABILITY)
        return false;

    SpellImmuneList const& dispelList = m_spellImmune[IMMUNITY_DISPEL];
    for(SpellImmuneList::const_iterator itr = dispelList.begin(); itr != dispelList.end(); ++itr)
        if(itr->type == spellInfo->Dispel)
            return true;

    if(!(spellInfo->AttributesEx &
        (SPELL_ATTR_EX_UNAFFECTED_BY_SCHOOL_IMMUNE | SPELL_ATTR_EX_DISPEL_AURAS_ON_IMMUNITY))               // can remove immune (by dispell or immune it)
        && spellInfo->Id != 42292)
    {
        SpellImmuneList const& schoolList = m_spellImmune[IMMUNITY_SCHOOL];
        for(SpellImmuneList::const_iterator itr = schoolList.begin(); itr != schoolList.end(); ++itr)
            if( !(IsPositiveSpell(itr->spellId) && IsPositiveSpell(spellInfo->Id)) &&
                (itr->type & GetSpellSchoolMask(spellInfo)) && !IsDispelableBySpell(spellInfo, itr->spellId))
                return true;
    }

    if (spellInfo->Mechanic)
    {
        SpellImmuneList const& mechanicList = m_spellImmune[IMMUNITY_MECHANIC];
        for(SpellImmuneList::const_iterator itr = mechanicList.begin(); itr != mechanicList.end(); ++itr)
        {
            if(itr->type == spellInfo->Mechanic)
            {
                return true;
            }
        }
    }

    return false;
}

bool Unit::IsImmunedToSpellEffect(SpellEntry const* spellInfo, uint32 index) const
{
    if (!spellInfo)
        return false;
    //If m_immuneToEffect type contain this effect type, IMMUNE effect.
    uint32 effect = spellInfo->Effect[index];
    SpellImmuneList const& effectList = m_spellImmune[IMMUNITY_EFFECT];
    for (SpellImmuneList::const_iterator itr = effectList.begin(); itr != effectList.end(); ++itr)
        if(itr->type == effect)
            return true;

    if(uint32 mechanic = spellInfo->EffectMechanic[index])
    {
        SpellImmuneList const& mechanicList = m_spellImmune[IMMUNITY_MECHANIC];
        for (SpellImmuneList::const_iterator itr = mechanicList.begin(); itr != mechanicList.end(); ++itr)
            if(itr->type == spellInfo->EffectMechanic[index])
                return true;
    }

    if(uint32 aura = spellInfo->EffectApplyAuraName[index])
    {
        SpellImmuneList const& list = m_spellImmune[IMMUNITY_STATE];
        for(SpellImmuneList::const_iterator itr = list.begin(); itr != list.end(); ++itr)
            if(itr->type == aura)
                return true;
        // Check for immune to application of harmful magical effects
        AuraEffectList const& immuneAuraApply = GetAurasByType(SPELL_AURA_MOD_IMMUNE_AURA_APPLY_SCHOOL);
        for(AuraEffectList::const_iterator iter = immuneAuraApply.begin(); iter != immuneAuraApply.end(); ++iter)
            if (spellInfo->Dispel == DISPEL_MAGIC &&                                      // Magic debuff
                ((*iter)->GetMiscValue() & GetSpellSchoolMask(spellInfo)) &&  // Check school
                !IsPositiveEffect(spellInfo->Id, index))                                  // Harmful
                return true;
    }

    return false;
}

bool Unit::IsDamageToThreatSpell(SpellEntry const * spellInfo) const
{
    if(!spellInfo)
        return false;

    uint32 family = spellInfo->SpellFamilyName;
    uint64 flags = spellInfo->SpellFamilyFlags;

    if((family == 5 && flags == 256) ||                     //Searing Pain
        (family == SPELLFAMILY_SHAMAN && flags == SPELLFAMILYFLAG_SHAMAN_FROST_SHOCK))
        return true;

    return false;
}

void Unit::MeleeDamageBonus(Unit *pVictim, uint32 *pdamage,WeaponAttackType attType, SpellEntry const *spellProto)
{
    if(!pVictim)
        return;

    if(*pdamage == 0)
        return;

    uint32 creatureTypeMask = pVictim->GetCreatureTypeMask();

    // Taken/Done fixed damage bonus auras
    int32 DoneFlatBenefit = 0;
    int32 TakenFlatBenefit = 0;

    // ..done (for creature type by mask) in taken
    AuraEffectList const& mDamageDoneCreature = GetAurasByType(SPELL_AURA_MOD_DAMAGE_DONE_CREATURE);
    for(AuraEffectList::const_iterator i = mDamageDoneCreature.begin();i != mDamageDoneCreature.end(); ++i)
        if(creatureTypeMask & uint32((*i)->GetMiscValue()))
            DoneFlatBenefit += (*i)->GetAmount();

    // ..done
    // SPELL_AURA_MOD_DAMAGE_DONE included in weapon damage

    // ..done (base at attack power for marked target and base at attack power for creature type)
    int32 APbonus = 0;
    if(attType == RANGED_ATTACK)
    {
        APbonus += pVictim->GetTotalAuraModifier(SPELL_AURA_RANGED_ATTACK_POWER_ATTACKER_BONUS);

        // ..done (base at attack power and creature type)
        AuraEffectList const& mCreatureAttackPower = GetAurasByType(SPELL_AURA_MOD_RANGED_ATTACK_POWER_VERSUS);
        for(AuraEffectList::const_iterator i = mCreatureAttackPower.begin();i != mCreatureAttackPower.end(); ++i)
            if(creatureTypeMask & uint32((*i)->GetMiscValue()))
                APbonus += (*i)->GetAmount();
    }
    else
    {
        APbonus += pVictim->GetTotalAuraModifier(SPELL_AURA_MELEE_ATTACK_POWER_ATTACKER_BONUS);

        // ..done (base at attack power and creature type)
        AuraEffectList const& mCreatureAttackPower = GetAurasByType(SPELL_AURA_MOD_MELEE_ATTACK_POWER_VERSUS);
        for(AuraEffectList::const_iterator i = mCreatureAttackPower.begin();i != mCreatureAttackPower.end(); ++i)
            if(creatureTypeMask & uint32((*i)->GetMiscValue()))
                APbonus += (*i)->GetAmount();
    }

    if (APbonus!=0)                                         // Can be negative
    {
        bool normalized = false;
        if(spellProto)
        {
            for (uint8 i = 0; i<3;i++)
            {
                if (spellProto->Effect[i] == SPELL_EFFECT_NORMALIZED_WEAPON_DMG)
                {
                    normalized = true;
                    break;
                }
            }
        }

        DoneFlatBenefit += int32(APbonus/14.0f * GetAPMultiplier(attType,normalized));
    }

    // ..taken
    AuraEffectList const& mDamageTaken = pVictim->GetAurasByType(SPELL_AURA_MOD_DAMAGE_TAKEN);
    for(AuraEffectList::const_iterator i = mDamageTaken.begin();i != mDamageTaken.end(); ++i)
        if((*i)->GetMiscValue() & GetMeleeDamageSchoolMask())
            TakenFlatBenefit += (*i)->GetAmount();

    if(attType!=RANGED_ATTACK)
        TakenFlatBenefit += pVictim->GetTotalAuraModifier(SPELL_AURA_MOD_MELEE_DAMAGE_TAKEN);
    else
        TakenFlatBenefit += pVictim->GetTotalAuraModifier(SPELL_AURA_MOD_RANGED_DAMAGE_TAKEN);

    // Done/Taken total percent damage auras
    float DoneTotalMod = 1.0f;
    float TakenTotalMod = 1.0f;

    // ..done
    // SPELL_AURA_MOD_DAMAGE_PERCENT_DONE included in weapon damage
    // SPELL_AURA_MOD_OFFHAND_DAMAGE_PCT  included in weapon damage

    AuraEffectList const& mDamageDoneVersus = GetAurasByType(SPELL_AURA_MOD_DAMAGE_DONE_VERSUS);
    for(AuraEffectList::const_iterator i = mDamageDoneVersus.begin();i != mDamageDoneVersus.end(); ++i)
        if(creatureTypeMask & uint32((*i)->GetMiscValue()))
            DoneTotalMod *= ((*i)->GetAmount()+100.0f)/100.0f;

    // ..taken
    AuraEffectList const& mModDamagePercentTaken = pVictim->GetAurasByType(SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN);
    for(AuraEffectList::const_iterator i = mModDamagePercentTaken.begin(); i != mModDamagePercentTaken.end(); ++i)
        if((*i)->GetMiscValue() & GetMeleeDamageSchoolMask())
            TakenTotalMod *= ((*i)->GetAmount()+100.0f)/100.0f;

    // .. taken pct: dummy auras
    AuraEffectList const& mDummyAuras = pVictim->GetAurasByType(SPELL_AURA_DUMMY);
    for(AuraEffectList::const_iterator i = mDummyAuras.begin(); i != mDummyAuras.end(); ++i)
    {
        switch((*i)->GetSpellProto()->SpellIconID)
        {
            //Cheat Death
            case 2109:
                if((*i)->GetMiscValue() & SPELL_SCHOOL_MASK_NORMAL)
                {
                    if(pVictim->GetTypeId() != TYPEID_PLAYER)
                        continue;
                    float mod = ((Player*)pVictim)->GetRatingBonusValue(CR_CRIT_TAKEN_MELEE)*(-8.0f);
                    if (mod < (*i)->GetAmount())
                        mod = (*i)->GetAmount();
                    TakenTotalMod *= (mod+100.0f)/100.0f;
                }
                break;
            //Mangle
            case 2312:
                if(spellProto==NULL)
                    break;
                // Should increase Shred (initial Damage of Lacerate and Rake handled in Spell::EffectSchoolDMG)
                if(spellProto->SpellFamilyName==SPELLFAMILY_DRUID && spellProto->SpellFamilyFlags.IsEqual (0x00008000,0,0))
                    TakenTotalMod *= (100.0f+(*i)->GetAmount())/100.0f;
                break;
        }
    }

    // .. taken pct: class scripts
    AuraEffectList const& mclassScritAuras = GetAurasByType(SPELL_AURA_OVERRIDE_CLASS_SCRIPTS);
    for(AuraEffectList::const_iterator i = mclassScritAuras.begin(); i != mclassScritAuras.end(); ++i)
    {
        switch((*i)->GetMiscValue())
        {
            case 6427: case 6428:                           // Dirty Deeds
                if(pVictim->HasAuraState(AURA_STATE_HEALTHLESS_35_PERCENT, spellProto, this))
                {
                    AuraEffect* eff0 = GetAuraEffect((*i)->GetId(),0,GetGUID());
                    if(!eff0 || (*i)->GetEffIndex()!=1)
                    {
                        sLog.outError("Spell structure of DD (%u) changed.",(*i)->GetId());
                        continue;
                    }

                    // effect 0 have expected value but in negative state
                    TakenTotalMod *= (-eff0->GetAmount()+100.0f)/100.0f;
                }
                break;
        }
    }

    if(attType != RANGED_ATTACK)
    {
        AuraEffectList const& mModMeleeDamageTakenPercent = pVictim->GetAurasByType(SPELL_AURA_MOD_MELEE_DAMAGE_TAKEN_PCT);
        for(AuraEffectList::const_iterator i = mModMeleeDamageTakenPercent.begin(); i != mModMeleeDamageTakenPercent.end(); ++i)
            TakenTotalMod *= ((*i)->GetAmount()+100.0f)/100.0f;
    }
    else
    {
        AuraEffectList const& mModRangedDamageTakenPercent = pVictim->GetAurasByType(SPELL_AURA_MOD_RANGED_DAMAGE_TAKEN_PCT);
        for(AuraEffectList::const_iterator i = mModRangedDamageTakenPercent.begin(); i != mModRangedDamageTakenPercent.end(); ++i)
            TakenTotalMod *= ((*i)->GetAmount()+100.0f)/100.0f;
    }

    float tmpDamage = float(int32(*pdamage) + DoneFlatBenefit) * DoneTotalMod;

    // apply spellmod to Done damage
    if(spellProto)
    {
        if(Player* modOwner = GetSpellModOwner())
            modOwner->ApplySpellMod(spellProto->Id, SPELLMOD_DAMAGE, tmpDamage);
    }

    tmpDamage = (tmpDamage + TakenFlatBenefit)*TakenTotalMod;

    // bonus result can be negative
    *pdamage =  tmpDamage > 0 ? uint32(tmpDamage) : 0;
}

void Unit::ApplySpellImmune(uint32 spellId, uint32 op, uint32 type, bool apply)
{
    if (apply)
    {
        for (SpellImmuneList::iterator itr = m_spellImmune[op].begin(), next; itr != m_spellImmune[op].end(); itr = next)
        {
            next = itr; ++next;
            if(itr->type == type)
            {
                m_spellImmune[op].erase(itr);
                next = m_spellImmune[op].begin();
            }
        }
        SpellImmune Immune;
        Immune.spellId = spellId;
        Immune.type = type;
        m_spellImmune[op].push_back(Immune);
    }
    else
    {
        for (SpellImmuneList::iterator itr = m_spellImmune[op].begin(); itr != m_spellImmune[op].end(); ++itr)
        {
            if(itr->spellId == spellId)
            {
                m_spellImmune[op].erase(itr);
                break;
            }
        }
    }

}

void Unit::ApplySpellDispelImmunity(const SpellEntry * spellProto, DispelType type, bool apply)
{
    ApplySpellImmune(spellProto->Id,IMMUNITY_DISPEL, type, apply);

    if (apply && spellProto->AttributesEx & SPELL_ATTR_EX_DISPEL_AURAS_ON_IMMUNITY)
    {
        // Create dispel mask by dispel type
        uint32 dispelMask = GetDispellMask(type);
        // Dispel all existing auras vs current dispel type
        AuraMap& auras = GetAuras();
        for(AuraMap::iterator itr = auras.begin(); itr != auras.end(); )
        {
            SpellEntry const* spell = itr->second->GetSpellProto();
            if( (1<<spell->Dispel) & dispelMask )
            {
                // Dispel aura
                RemoveAura(itr);
            }
            else
                ++itr;
        }
    }
}

float Unit::GetWeaponProcChance() const
{
    // normalized proc chance for weapon attack speed
    // (odd formula...)
    if(isAttackReady(BASE_ATTACK))
        return (GetAttackTime(BASE_ATTACK) * 1.8f / 1000.0f);
    else if (haveOffhandWeapon() && isAttackReady(OFF_ATTACK))
        return (GetAttackTime(OFF_ATTACK) * 1.6f / 1000.0f);
    return 0;
}

float Unit::GetPPMProcChance(uint32 WeaponSpeed, float PPM, const SpellEntry * spellProto) const
{
    // proc per minute chance calculation
    if (PPM <= 0) return 0.0f;
    // Apply chance modifer aura
    if (spellProto)
        if(Player* modOwner = GetSpellModOwner())
            modOwner->ApplySpellMod(spellProto->Id,SPELLMOD_PROC_PER_MINUTE,PPM);

    uint32 result = uint32((WeaponSpeed * PPM) / 600.0f);   // result is chance in percents (probability = Speed_in_sec * (PPM / 60))
    return result;
}

void Unit::Mount(uint32 mount)
{
    RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_MOUNT);

    if(mount)
        SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, mount);

    SetFlag( UNIT_FIELD_FLAGS, UNIT_FLAG_MOUNT );

    // unsummon pet
    if(GetTypeId() == TYPEID_PLAYER)
        ((Player*)this)->UnsummonPetTemporaryIfAny();
}

void Unit::Unmount()
{
    if(!IsMounted())
        return;

    RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_NOT_MOUNTED);

    SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, 0);
    RemoveFlag( UNIT_FIELD_FLAGS, UNIT_FLAG_MOUNT );

    // only resummon old pet if the player is already added to a map
    // this prevents adding a pet to a not created map which would otherwise cause a crash
    // (it could probably happen when logging in after a previous crash)
    if(GetTypeId() == TYPEID_PLAYER)
        ((Player*)this)->ResummonPetTemporaryUnSummonedIfAny();
}

void Unit::SetInCombatWith(Unit* enemy)
{
    Unit* eOwner = enemy->GetCharmerOrOwnerOrSelf();
    if(eOwner->IsPvP())
    {
        SetInCombatState(true,enemy);
        return;
    }

    //check for duel
    if(eOwner->GetTypeId() == TYPEID_PLAYER && ((Player*)eOwner)->duel)
    {
        Unit const* myOwner = GetCharmerOrOwnerOrSelf();
        if(((Player const*)eOwner)->duel->opponent == myOwner)
        {
            SetInCombatState(true,enemy);
            return;
        }
    }
    SetInCombatState(false,enemy);
}

void Unit::CombatStart(Unit* target)
{
    if(!target->IsStandState()/* && !target->hasUnitState(UNIT_STAT_STUNNED)*/)
        target->SetStandState(UNIT_STAND_STATE_STAND);

    if(!target->isInCombat() && target->GetTypeId() != TYPEID_PLAYER
        && !((Creature*)target)->HasReactState(REACT_PASSIVE) && ((Creature*)target)->IsAIEnabled)
    {
        ((Creature*)target)->AI()->AttackStart(this);
    }

    SetInCombatWith(target);
    target->SetInCombatWith(this);

    Unit *who = target->GetCharmerOrOwnerOrSelf();
    if(who->GetTypeId() == TYPEID_PLAYER)
        SetContestedPvP((Player*)who);

    Player *me = GetCharmerOrOwnerPlayerOrPlayerItself();
    if(me && who->IsPvP()
        && (who->GetTypeId() != TYPEID_PLAYER
        || !me->duel || me->duel->opponent != who))
    {
        me->UpdatePvP(true);
        me->RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_ENTER_PVP_COMBAT);
    }
}

void Unit::SetInCombatState(bool PvP, Unit* enemy)
{
    // only alive units can be in combat
    if(!isAlive())
        return;

    if(PvP)
        m_CombatTimer = 5000;

    if(isInCombat())
        return;

    SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IN_COMBAT);

    if(GetTypeId() != TYPEID_PLAYER)
    {
        if(GetMotionMaster()->GetMotionSlotType(MOTION_SLOT_IDLE) != IDLE_MOTION_TYPE)
            ((Creature*)this)->SetHomePosition(GetPositionX(), GetPositionY(), GetPositionZ(), GetOrientation());
        if(enemy)
        {
            if(!((Creature*)this)->HasReactState(REACT_PASSIVE) && ((Creature*)this)->IsAIEnabled)
                ((Creature*)this)->AI()->EnterCombat(enemy);
            if(((Creature*)this)->GetFormation())
                ((Creature*)this)->GetFormation()->MemberAttackStart((Creature*)this, enemy);
        }
    }

    if(GetTypeId() != TYPEID_PLAYER && ((Creature*)this)->isPet())
    {
        UpdateSpeed(MOVE_RUN, true);
        UpdateSpeed(MOVE_SWIM, true);
        UpdateSpeed(MOVE_FLIGHT, true);
    }
    else if(!isCharmed())
        return;

    SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PET_IN_COMBAT);
}

void Unit::ClearInCombat()
{
    m_CombatTimer = 0;
    RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IN_COMBAT);

    // Player's state will be cleared in Player::UpdateContestedPvP
    if(GetTypeId()!=TYPEID_PLAYER)
        clearUnitState(UNIT_STAT_ATTACK_PLAYER);
    else
        ((Player*)this)->UpdatePotionCooldown();

    if(GetTypeId() != TYPEID_PLAYER && ((Creature*)this)->isPet())
    {
        if(Unit *owner = GetOwner())
        {
            for(int i = 0; i < MAX_MOVE_TYPE; ++i)
                SetSpeed(UnitMoveType(i), owner->GetSpeedRate(UnitMoveType(i)), true);
        }
    }
    else if(!isCharmed())
        return;

    RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PET_IN_COMBAT);
}

//TODO: remove this function
bool Unit::isTargetableForAttack() const
{
    return isAttackableByAOE() && !hasUnitState(UNIT_STAT_DIED);
}

bool Unit::canAttack(Unit const* target, bool force) const
{
    assert(target);

    if(force)
    {
        if(IsFriendlyTo(target))
            return false;
    }
    else if(!IsHostileTo(target))
        return false;

    if(!target->isAttackableByAOE() || target->hasUnitState(UNIT_STAT_DIED))
        return false;

    if((m_invisibilityMask || target->m_invisibilityMask) && !canDetectInvisibilityOf(target))
        return false;

    if(target->GetVisibility() == VISIBILITY_GROUP_STEALTH && !canDetectStealthOf(target, GetDistance(target)))
        return false;

    return true;
}

bool Unit::isAttackableByAOE() const
{
    if(!isAlive())
        return false;

    if(HasFlag(UNIT_FIELD_FLAGS,
        UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NOT_ATTACKABLE_2))
        return false;

    if(GetTypeId()==TYPEID_PLAYER && ((Player *)this)->isGameMaster())
        return false;

    return !hasUnitState(UNIT_STAT_UNATTACKABLE);
}

int32 Unit::ModifyHealth(int32 dVal)
{
    int32 gain = 0;

    if(dVal==0)
        return 0;

    int32 curHealth = (int32)GetHealth();

    int32 val = dVal + curHealth;
    if(val <= 0)
    {
        SetHealth(0);
        return -curHealth;
    }

    int32 maxHealth = (int32)GetMaxHealth();

    if(val < maxHealth)
    {
        SetHealth(val);
        gain = val - curHealth;
    }
    else if(curHealth != maxHealth)
    {
        SetHealth(maxHealth);
        gain = maxHealth - curHealth;
    }

    return gain;
}

int32 Unit::GetHealthGain(int32 dVal)
{
    int32 gain = 0;

    if(dVal==0)
        return 0;

    int32 curHealth = (int32)GetHealth();

    int32 val = dVal + curHealth;
    if(val <= 0)
    {
        return -curHealth;
    }

    int32 maxHealth = (int32)GetMaxHealth();

    if(val < maxHealth)
    {
        gain = dVal;
    }
    else if(curHealth != maxHealth)
    {
        gain = maxHealth - curHealth;
    }

    return gain;
}

int32 Unit::ModifyPower(Powers power, int32 dVal)
{
    int32 gain = 0;

    if(dVal==0)
        return 0;

    int32 curPower = (int32)GetPower(power);

    int32 val = dVal + curPower;
    if(val <= 0)
    {
        SetPower(power,0);
        return -curPower;
    }

    int32 maxPower = (int32)GetMaxPower(power);

    if(val < maxPower)
    {
        SetPower(power,val);
        gain = val - curPower;
    }
    else if(curPower != maxPower)
    {
        SetPower(power,maxPower);
        gain = maxPower - curPower;
    }

    return gain;
}

bool Unit::isVisibleForOrDetect(Unit const* u, bool detect, bool inVisibleList, bool is3dDistance) const
{
    if(!u)
        return false;

    return u->canSeeOrDetect(this, detect, inVisibleList, is3dDistance);
}

bool Unit::canSeeOrDetect(Unit const* u, bool detect, bool inVisibleList, bool is3dDistance) const
{
    return true;
}

bool Unit::canDetectInvisibilityOf(Unit const* u) const
{
    if(m_invisibilityMask & u->m_invisibilityMask) // same group
        return true;
    AuraEffectList const& auras = u->GetAurasByType(SPELL_AURA_MOD_STALKED); // Hunter mark
    for(AuraEffectList::const_iterator iter = auras.begin(); iter != auras.end(); ++iter)
        if((*iter)->GetCasterGUID()==GetGUID())
            return true;

    if(uint32 mask = (m_detectInvisibilityMask & u->m_invisibilityMask))
    {
        for(uint32 i = 0; i < 10; ++i)
        {
            if(((1 << i) & mask)==0)
                continue;

            // find invisibility level
            uint32 invLevel = 0;
            Unit::AuraEffectList const& iAuras = u->GetAurasByType(SPELL_AURA_MOD_INVISIBILITY);
            for(Unit::AuraEffectList::const_iterator itr = iAuras.begin(); itr != iAuras.end(); ++itr)
                if(((*itr)->GetMiscValue())==i && invLevel < (*itr)->GetAmount())
                    invLevel = (*itr)->GetAmount();

            // find invisibility detect level
            uint32 detectLevel = 0;
            if(i==6 && GetTypeId()==TYPEID_PLAYER)          // special drunk detection case
            {
                detectLevel = ((Player*)this)->GetDrunkValue();
            }
            else
            {
                Unit::AuraEffectList const& dAuras = GetAurasByType(SPELL_AURA_MOD_INVISIBILITY_DETECTION);
                for(Unit::AuraEffectList::const_iterator itr = dAuras.begin(); itr != dAuras.end(); ++itr)
                    if(((*itr)->GetMiscValue())==i && detectLevel < (*itr)->GetAmount())
                        detectLevel = (*itr)->GetAmount();
            }

            if(invLevel <= detectLevel)
                return true;
        }
    }

    return false;
}

bool Unit::canDetectStealthOf(Unit const* target, float distance) const
{
    if(hasUnitState(UNIT_STAT_STUNNED))
        return false;
    if(distance < 0.24f) //collision
        return true;
    if(!HasInArc(M_PI, target)) //behind
        return false;
    if(HasAuraType(SPELL_AURA_DETECT_STEALTH))
        return true;

    AuraEffectList const& auras = target->GetAurasByType(SPELL_AURA_MOD_STALKED); // Hunter mark
    for(AuraEffectList::const_iterator iter = auras.begin(); iter != auras.end(); ++iter)
        if((*iter)->GetCasterGUID()==GetGUID())
            return true;

    //Visible distance based on stealth value (stealth rank 4 300MOD, 10.5 - 3 = 7.5)
    float visibleDistance = 10.5f - target->GetTotalAuraModifier(SPELL_AURA_MOD_STEALTH) / 100.0f;
    //Visible distance is modified by -Level Diff (every level diff = 1.0f in visible distance)
    visibleDistance += int32(getLevelForTarget(target)) - int32(target->getLevelForTarget(this));
    //-Stealth Mod(positive like Master of Deception) and Stealth Detection(negative like paranoia)
    //based on wowwiki every 5 mod we have 1 more level diff in calculation
    visibleDistance += (float)(GetTotalAuraModifier(SPELL_AURA_MOD_DETECT) - target->GetTotalAuraModifier(SPELL_AURA_MOD_STEALTH_LEVEL)) / 5.0f;

    return distance < visibleDistance;
}

void Unit::DestroyForNearbyPlayers()
{
    if(!IsInWorld())
        return;

    std::list<Unit*> targets;
    Trinity::AnyUnitInObjectRangeCheck check(this, World::GetMaxVisibleDistance());
    Trinity::UnitListSearcher<Trinity::AnyUnitInObjectRangeCheck> searcher(this, targets, check);
    VisitNearbyWorldObject(World::GetMaxVisibleDistance(), searcher);
    for(std::list<Unit*>::iterator iter = targets.begin(); iter != targets.end(); ++iter)
        if(*iter != this && (*iter)->GetTypeId() == TYPEID_PLAYER
            && ((Player*)(*iter))->HaveAtClient(this))
        {
            DestroyForPlayer((Player*)(*iter));
            ((Player*)(*iter))->m_clientGUIDs.erase(GetGUID());
        }
}

void Unit::SetVisibility(UnitVisibility x)
{
    m_Visibility = x;

    if(IsInWorld())
        SetToNotify();

    if(x == VISIBILITY_GROUP_STEALTH)
        DestroyForNearbyPlayers();
}

void Unit::UpdateSpeed(UnitMoveType mtype, bool forced)
{
    int32 main_speed_mod  = 0;
    float stack_bonus     = 1.0f;
    float non_stack_bonus = 1.0f;

    switch(mtype)
    {
        case MOVE_WALK:
            return;
        case MOVE_RUN:
        {
            if (IsMounted()) // Use on mount auras
            {
                main_speed_mod  = GetMaxPositiveAuraModifier(SPELL_AURA_MOD_INCREASE_MOUNTED_SPEED);
                stack_bonus     = GetTotalAuraMultiplier(SPELL_AURA_MOD_MOUNTED_SPEED_ALWAYS);
                non_stack_bonus = (100.0f + GetMaxPositiveAuraModifier(SPELL_AURA_MOD_MOUNTED_SPEED_NOT_STACK))/100.0f;
            }
            else
            {
                main_speed_mod  = GetMaxPositiveAuraModifier(SPELL_AURA_MOD_INCREASE_SPEED);
                stack_bonus     = GetTotalAuraMultiplier(SPELL_AURA_MOD_SPEED_ALWAYS);
                non_stack_bonus = (100.0f + GetMaxPositiveAuraModifier(SPELL_AURA_MOD_SPEED_NOT_STACK))/100.0f;
            }
            break;
        }
        case MOVE_RUN_BACK:
            return;
        case MOVE_SWIM:
        {
            main_speed_mod  = GetMaxPositiveAuraModifier(SPELL_AURA_MOD_INCREASE_SWIM_SPEED);
            break;
        }
        case MOVE_SWIM_BACK:
            return;
        case MOVE_FLIGHT:
        {
            if (GetTypeId()==TYPEID_UNIT && ((Creature*)this)->isVehicle())
            {
                main_speed_mod  = GetMaxPositiveAuraModifier(SPELL_AURA_MOD_INCREASE_VEHICLE_FLIGHT_SPEED);
                stack_bonus     = GetTotalAuraMultiplier(SPELL_AURA_MOD_VEHICLE_SPEED_ALWAYS);

                // for some spells this mod is applied on vehicle owner
                uint32 owner_speed_mod  = ((Vehicle*)this)->GetOwner()->GetMaxPositiveAuraModifier(SPELL_AURA_MOD_INCREASE_VEHICLE_FLIGHT_SPEED);

                main_speed_mod = main_speed_mod>owner_speed_mod ? main_speed_mod : owner_speed_mod;
            }
            else if (IsMounted())
            {
                main_speed_mod  = GetMaxPositiveAuraModifier(SPELL_AURA_MOD_INCREASE_MOUNTED_FLIGHT_SPEED);
                stack_bonus     = GetTotalAuraMultiplier(SPELL_AURA_MOD_MOUNTED_FLIGHT_SPEED_ALWAYS);
            }
            else             // Use not mount (shapeshift for example) auras (should stack)
                main_speed_mod  = GetTotalAuraModifier(SPELL_AURA_MOD_INCREASE_FLIGHT_SPEED);

            non_stack_bonus = (100.0 + GetMaxPositiveAuraModifier(SPELL_AURA_MOD_FLIGHT_SPEED_NOT_STACK))/100.0f;

            // Update speed for vehicle if avalible
            if (GetTypeId()==TYPEID_PLAYER)
                if (Unit * vehicle = ((Player*)this)->m_Vehicle)
                    vehicle->UpdateSpeed(MOVE_FLIGHT, true);
            break;
        }
        case MOVE_FLIGHT_BACK:
            return;
        default:
            sLog.outError("Unit::UpdateSpeed: Unsupported move type (%d)", mtype);
            return;
    }

    float bonus = non_stack_bonus > stack_bonus ? non_stack_bonus : stack_bonus;
    // now we ready for speed calculation
    float speed  = main_speed_mod ? bonus*(100.0f + main_speed_mod)/100.0f : bonus;

    switch(mtype)
    {
        case MOVE_RUN:
        case MOVE_SWIM:
        case MOVE_FLIGHT:
        {
            // Normalize speed by 191 aura SPELL_AURA_USE_NORMAL_MOVEMENT_SPEED if need
            // TODO: possible affect only on MOVE_RUN
            if(int32 normalization = GetMaxPositiveAuraModifier(SPELL_AURA_USE_NORMAL_MOVEMENT_SPEED))
            {
                // Use speed from aura
                float max_speed = normalization / baseMoveSpeed[mtype];
                if (speed > max_speed)
                    speed = max_speed;
            }
            break;
        }
        default:
            break;
    }

    // Apply strongest slow aura mod to speed
    int32 slow = GetMaxNegativeAuraModifier(SPELL_AURA_MOD_DECREASE_SPEED);
    if (slow)
        speed *=(100.0f + slow)/100.0f;
    SetSpeed(mtype, speed, forced);
}

float Unit::GetSpeed( UnitMoveType mtype ) const
{
    return m_speed_rate[mtype]*baseMoveSpeed[mtype];
}

void Unit::SetSpeed(UnitMoveType mtype, float rate, bool forced)
{
    if (rate < 0)
        rate = 0.0f;

    // Update speed only on change
    if (m_speed_rate[mtype] == rate)
        return;

    m_speed_rate[mtype] = rate;

    propagateSpeedChange();

    WorldPacket data;
    if(!forced)
    {
        switch(mtype)
        {
            case MOVE_WALK:
                data.Initialize(MSG_MOVE_SET_WALK_SPEED, 8+4+2+4+4+4+4+4+4+4);
                break;
            case MOVE_RUN:
                data.Initialize(MSG_MOVE_SET_RUN_SPEED, 8+4+2+4+4+4+4+4+4+4);
                break;
            case MOVE_RUN_BACK:
                data.Initialize(MSG_MOVE_SET_RUN_BACK_SPEED, 8+4+2+4+4+4+4+4+4+4);
                break;
            case MOVE_SWIM:
                data.Initialize(MSG_MOVE_SET_SWIM_SPEED, 8+4+2+4+4+4+4+4+4+4);
                break;
            case MOVE_SWIM_BACK:
                data.Initialize(MSG_MOVE_SET_SWIM_BACK_SPEED, 8+4+2+4+4+4+4+4+4+4);
                break;
            case MOVE_TURN_RATE:
                data.Initialize(MSG_MOVE_SET_TURN_RATE, 8+4+2+4+4+4+4+4+4+4);
                break;
            case MOVE_FLIGHT:
                data.Initialize(MSG_MOVE_SET_FLIGHT_SPEED, 8+4+2+4+4+4+4+4+4+4);
                break;
            case MOVE_FLIGHT_BACK:
                data.Initialize(MSG_MOVE_SET_FLIGHT_BACK_SPEED, 8+4+2+4+4+4+4+4+4+4);
                break;
            case MOVE_PITCH_RATE:
                data.Initialize(MSG_MOVE_SET_PITCH_RATE, 8+4+2+4+4+4+4+4+4+4);
                break;
            default:
                sLog.outError("Unit::SetSpeed: Unsupported move type (%d), data not sent to client.",mtype);
                return;
        }

        data.append(GetPackGUID());
        data << uint32(0);                                  // movement flags
        data << uint16(0);                                  // unk flags
        data << uint32(getMSTime());
        data << float(GetPositionX());
        data << float(GetPositionY());
        data << float(GetPositionZ());
        data << float(GetOrientation());
        data << uint32(0);                                  // fall time
        data << float(GetSpeed(mtype));
        SendMessageToSet( &data, true );
    }
    else
    {
        if(GetTypeId() == TYPEID_PLAYER)
        {
            // register forced speed changes for WorldSession::HandleForceSpeedChangeAck
            // and do it only for real sent packets and use run for run/mounted as client expected
            ++((Player*)this)->m_forced_speed_changes[mtype];

            if(!isInCombat())
                if(Pet* pet = ((Player*)this)->GetPet())
                    pet->SetSpeed(mtype, m_speed_rate[mtype], forced);
        }

        switch(mtype)
        {
            case MOVE_WALK:
                data.Initialize(SMSG_FORCE_WALK_SPEED_CHANGE, 16);
                break;
            case MOVE_RUN:
                data.Initialize(SMSG_FORCE_RUN_SPEED_CHANGE, 17);
                break;
            case MOVE_RUN_BACK:
                data.Initialize(SMSG_FORCE_RUN_BACK_SPEED_CHANGE, 16);
                break;
            case MOVE_SWIM:
                data.Initialize(SMSG_FORCE_SWIM_SPEED_CHANGE, 16);
                break;
            case MOVE_SWIM_BACK:
                data.Initialize(SMSG_FORCE_SWIM_BACK_SPEED_CHANGE, 16);
                break;
            case MOVE_TURN_RATE:
                data.Initialize(SMSG_FORCE_TURN_RATE_CHANGE, 16);
                break;
            case MOVE_FLIGHT:
                data.Initialize(SMSG_FORCE_FLIGHT_SPEED_CHANGE, 16);
                break;
            case MOVE_FLIGHT_BACK:
                data.Initialize(SMSG_FORCE_FLIGHT_BACK_SPEED_CHANGE, 16);
                break;
            case MOVE_PITCH_RATE:
                data.Initialize(SMSG_FORCE_PITCH_RATE_CHANGE, 16);
                break;
            default:
                sLog.outError("Unit::SetSpeed: Unsupported move type (%d), data not sent to client.",mtype);
                return;
        }
        data.append(GetPackGUID());
        data << (uint32)0;                                  // moveEvent, NUM_PMOVE_EVTS = 0x39
        if (mtype == MOVE_RUN)
            data << uint8(0);                               // new 2.1.0
        data << float(GetSpeed(mtype));
        SendMessageToSet( &data, true );
    }
}

void Unit::SetHover(bool on)
{
    if(on)
        CastSpell(this,11010,true);
    else
        RemoveAurasDueToSpell(11010);
}

void Unit::setDeathState(DeathState s)
{
    if (s != ALIVE && s!= JUST_ALIVED)
    {
        CombatStop();
        DeleteThreatList();
        getHostilRefManager().deleteReferences();
        ClearComboPointHolders();                           // any combo points pointed to unit lost at it death

        if(IsNonMeleeSpellCasted(false))
            InterruptNonMeleeSpells(false);
    }

    if (s == JUST_DIED)
    {
        UnsummonAllTotems();
        RemoveAllControlled();
        RemoveAllAurasOnDeath();
        ExitVehicle();

        ModifyAuraState(AURA_STATE_HEALTHLESS_20_PERCENT, false);
        ModifyAuraState(AURA_STATE_HEALTHLESS_35_PERCENT, false);
        // remove aurastates allowing special moves
        ClearAllReactives();
        ClearDiminishings();
        GetMotionMaster()->Clear(false);
        GetMotionMaster()->MoveIdle();
        //without this when removing IncreaseMaxHealth aura player may stuck with 1 hp
        //do not why since in IncreaseMaxHealth currenthealth is checked
        SetHealth(0);
    }
    else if(s == JUST_ALIVED)
    {
        RemoveFlag (UNIT_FIELD_FLAGS, UNIT_FLAG_SKINNABLE); // clear skinnable for creature and player (at battleground)
    }

    if (m_deathState != ALIVE && s == ALIVE)
    {
        //_ApplyAllAuraMods();
    }
    m_deathState = s;
}

/*########################################
########                          ########
########       AGGRO SYSTEM       ########
########                          ########
########################################*/
bool Unit::CanHaveThreatList() const
{
    // only creatures can have threat list
    if( GetTypeId() != TYPEID_UNIT )
        return false;

    // only alive units can have threat list
    if( !isAlive() )
        return false;

    // totems can not have threat list
    if( ((Creature*)this)->isTotem() )
        return false;

    // vehicles can not have threat list
    if( ((Creature*)this)->isVehicle() )
        return false;

    // pets can not have a threat list, unless they are controlled by a creature
    if( ((Creature*)this)->isPet() && IS_PLAYER_GUID(((Pet*)this)->GetOwnerGUID()) )
        return false;

    return true;
}

//======================================================================

float Unit::ApplyTotalThreatModifier(float threat, SpellSchoolMask schoolMask)
{
    if(!HasAuraType(SPELL_AURA_MOD_THREAT))
        return threat;

    SpellSchools school = GetFirstSchoolInMask(schoolMask);

    return threat * m_threatModifier[school];
}

//======================================================================

void Unit::AddThreat(Unit* pVictim, float threat, SpellSchoolMask schoolMask, SpellEntry const *threatSpell)
{
    // Only mobs can manage threat lists
    if(CanHaveThreatList())
        m_ThreatManager.addThreat(pVictim, threat, schoolMask, threatSpell);
}

//======================================================================

void Unit::DeleteThreatList()
{
    m_ThreatManager.clearReferences();
}

//======================================================================

void Unit::TauntApply(Unit* taunter)
{
    assert(GetTypeId()== TYPEID_UNIT);

    if(!taunter || (taunter->GetTypeId() == TYPEID_PLAYER && ((Player*)taunter)->isGameMaster()))
        return;

    if(!CanHaveThreatList())
        return;

    Unit *target = getVictim();
    if(target && target == taunter)
        return;

    SetInFront(taunter);
    if (((Creature*)this)->IsAIEnabled)
        ((Creature*)this)->AI()->AttackStart(taunter);

    //m_ThreatManager.tauntApply(taunter);
}

//======================================================================

void Unit::TauntFadeOut(Unit *taunter)
{
    assert(GetTypeId()== TYPEID_UNIT);

    if(!taunter || (taunter->GetTypeId() == TYPEID_PLAYER && ((Player*)taunter)->isGameMaster()))
        return;

    if(!CanHaveThreatList())
        return;

    Unit *target = getVictim();
    if(!target || target != taunter)
        return;

    if(m_ThreatManager.isThreatListEmpty())
    {
        if(((Creature*)this)->IsAIEnabled)
            ((Creature*)this)->AI()->EnterEvadeMode();
        return;
    }

    //m_ThreatManager.tauntFadeOut(taunter);
    target = m_ThreatManager.getHostilTarget();

    if (target && target != taunter)
    {
        SetInFront(target);
        if (((Creature*)this)->IsAIEnabled)
            ((Creature*)this)->AI()->AttackStart(target);
    }
}

//======================================================================

Unit* Creature::SelectVictim()
{
    //function provides main threat functionality
    //next-victim-selection algorithm and evade mode are called
    //threat list sorting etc.

    //This should not be called by unit who does not have a threatlist
    //or who does not have threat (totem/pet/critter)
    //otherwise enterevademode every update

    Unit* target = NULL;
    // First checking if we have some taunt on us
    const AuraEffectList& tauntAuras = GetAurasByType(SPELL_AURA_MOD_TAUNT);
    if ( !tauntAuras.empty() )
    {
        Unit* caster;

        // The last taunt aura caster is alive an we are happy to attack him
        if ( (caster = tauntAuras.back()->GetCaster()) && caster->isAlive() )
            return getVictim();
        else if (tauntAuras.size() > 1)
        {
            // We do not have last taunt aura caster but we have more taunt auras,
            // so find first available target

            // Auras are pushed_back, last caster will be on the end
            AuraEffectList::const_iterator aura = --tauntAuras.end();
            do
            {
                --aura;
                if ( (caster = (*aura)->GetCaster()) &&
                     caster->IsInMap(this) && canAttack(caster) && caster->isInAccessiblePlaceFor((Creature*)this) )
                {
                    target = caster;
                    break;
                }
            }while (aura != tauntAuras.begin());
        }
        else
            target = getVictim();
    }

    if ( !target && !m_ThreatManager.isThreatListEmpty() )
        // No taunt aura or taunt aura caster is dead standart target selection
        target = m_ThreatManager.getHostilTarget();

    if(target)
    {
        if(!hasUnitState(UNIT_STAT_STUNNED))
            SetInFront(target);
        return target;
    }

    // last case when creature don't must go to evade mode:
    // it in combat but attacker not make any damage and not enter to aggro radius to have record in threat list
    // for example at owner command to pet attack some far away creature
    // Note: creature not have targeted movement generator but have attacker in this case
    if(m_attackers.size())
        return NULL;
    /*if( GetMotionMaster()->GetCurrentMovementGeneratorType() != TARGETED_MOTION_TYPE )
    {
        for(AttackerSet::const_iterator itr = m_attackers.begin(); itr != m_attackers.end(); ++itr)
        {
            if( (*itr)->IsInMap(this) && canAttack(*itr) && (*itr)->isInAccessiblePlaceFor((Creature*)this) )
                return NULL;
        }
    }*/

    // search nearby enemy before enter evade mode
    if(HasReactState(REACT_AGGRESSIVE))
    {
        target = SelectNearestTarget();
        if(target && !IsOutOfThreatArea(target))
            return target;
    }

    if(m_invisibilityMask)
    {
        Unit::AuraEffectList const& iAuras = GetAurasByType(SPELL_AURA_MOD_INVISIBILITY);
        for(Unit::AuraEffectList::const_iterator itr = iAuras.begin(); itr != iAuras.end(); ++itr)
            if((*itr)->GetParentAura()->IsPermanent())
            {
                AI()->EnterEvadeMode();
                break;
            }
        return NULL;
    }

    // enter in evade mode in other case
    AI()->EnterEvadeMode();

    return NULL;
}

//======================================================================
//======================================================================
//======================================================================

int32 Unit::CalculateSpellDamage(SpellEntry const* spellProto, uint8 effect_index, int32 effBasePoints, Unit const* /*target*/)
{
    Player* unitPlayer = (GetTypeId() == TYPEID_PLAYER) ? (Player*)this : NULL;

    uint8 comboPoints = unitPlayer ? unitPlayer->GetComboPoints() : 0;

    int32 level = int32(getLevel());
    if (level > (int32)spellProto->maxLevel && spellProto->maxLevel > 0)
        level = (int32)spellProto->maxLevel;
    else if (level < (int32)spellProto->baseLevel)
        level = (int32)spellProto->baseLevel;
    level-= (int32)spellProto->spellLevel;

    float basePointsPerLevel = spellProto->EffectRealPointsPerLevel[effect_index];
    float randomPointsPerLevel = spellProto->EffectDicePerLevel[effect_index];
    int32 basePoints = int32(effBasePoints + level * basePointsPerLevel);
    int32 randomPoints = int32(spellProto->EffectDieSides[effect_index] + level * randomPointsPerLevel);
    float comboDamage = spellProto->EffectPointsPerComboPoint[effect_index];

    // range can have possitive and negative values, so order its for irand
    int32 randvalue = int32(spellProto->EffectBaseDice[effect_index]) >= randomPoints
        ? irand(randomPoints, int32(spellProto->EffectBaseDice[effect_index]))
        : irand(int32(spellProto->EffectBaseDice[effect_index]), randomPoints);

    int32 value = basePoints + randvalue;
    //random damage
    if(comboDamage != 0 && unitPlayer /*&& target && (target->GetGUID() == unitPlayer->GetComboTarget())*/)
        value += (int32)(comboDamage * comboPoints);

    if(Player* modOwner = GetSpellModOwner())
    {
        modOwner->ApplySpellMod(spellProto->Id,SPELLMOD_ALL_EFFECTS, value);
        switch(effect_index)
        {
            case 0:
                modOwner->ApplySpellMod(spellProto->Id,SPELLMOD_EFFECT1, value);
                break;
            case 1:
                modOwner->ApplySpellMod(spellProto->Id,SPELLMOD_EFFECT2, value);
                break;
            case 2:
                modOwner->ApplySpellMod(spellProto->Id,SPELLMOD_EFFECT3, value);
                break;
        }
    }

    if(!basePointsPerLevel && (spellProto->Attributes & SPELL_ATTR_LEVEL_DAMAGE_CALCULATION && spellProto->spellLevel) &&
            spellProto->Effect[effect_index] != SPELL_EFFECT_WEAPON_PERCENT_DAMAGE &&
            spellProto->Effect[effect_index] != SPELL_EFFECT_KNOCK_BACK)
            //there are many more: slow speed, -healing pct
        //value = int32(value*0.25f*exp(getLevel()*(70-spellProto->spellLevel)/1000.0f));
        value = int32(value * (int32)getLevel() / (int32)(spellProto->spellLevel ? spellProto->spellLevel : 1));

    return value;
}

int32 Unit::CalcSpellDuration(SpellEntry const* spellProto)
{
    Player* unitPlayer = (GetTypeId() == TYPEID_PLAYER) ? (Player*)this : NULL;

    uint8 comboPoints = unitPlayer ? unitPlayer->GetComboPoints() : 0;

    int32 minduration = GetSpellDuration(spellProto);
    int32 maxduration = GetSpellMaxDuration(spellProto);

    int32 duration;

    if( minduration != -1 && minduration != maxduration )
        duration = minduration + int32((maxduration - minduration) * comboPoints / 5);
    else
        duration = minduration;

    return duration;
}

int32 Unit::ModSpellDuration(SpellEntry const* spellProto, Unit const* target, int32 duration, bool positive)
{
    //don't mod permament auras duration
    if (duration<0)
        return duration;

    //cut duration only of negative effects
    if (!positive)
    {
        int32 mechanic = spellProto->Mechanic;

        // Find total mod value (negative bonus)
        int32 durationMod_always = target->GetTotalAuraModifierByMiscValue(SPELL_AURA_MECHANIC_DURATION_MOD, mechanic);
        // Find max mod (negative bonus)
        int32 durationMod_not_stack = target->GetMaxNegativeAuraModifierByMiscValue(SPELL_AURA_MECHANIC_DURATION_MOD_NOT_STACK, mechanic);
        int32 durationMod = 0;
        // Select strongest negative mod
        if (durationMod_always > durationMod_not_stack)
            durationMod = durationMod_not_stack;
        else
            durationMod = durationMod_always;

        if (durationMod != 0)
            duration = int32( float (duration) * float(100.0f+durationMod) /100.0f);

        // there are only negative mods currently
        durationMod_always =target->GetTotalAuraModifierByMiscValue(SPELL_AURA_MOD_AURA_DURATION_BY_DISPEL, spellProto->Dispel);
        durationMod_not_stack=target->GetMaxNegativeAuraModifierByMiscValue(SPELL_AURA_MOD_AURA_DURATION_BY_DISPEL_NOT_STACK, spellProto->Dispel);

        durationMod=0;
        if (durationMod_always > durationMod_not_stack)
            durationMod += durationMod_not_stack;
        else
            durationMod += durationMod_always;

        if (durationMod != 0)
            duration = int32( float (duration) * float(100.0f+durationMod) /100.0f);
    }
    //else positive mods here, there are no currently
    //when there will be, change GetTotalAuraModifierByMiscValue to GetTotalPositiveAuraModifierByMiscValue
    return duration>0 ? duration : 0;
}

void Unit::ModSpellCastTime(SpellEntry const* spellProto, int32 & castTime, Spell const * spell)
{
    if (!spellProto || castTime<0)
        return;
    //called from caster
    if(Player* modOwner = GetSpellModOwner())
        modOwner->ApplySpellMod(spellProto->Id, SPELLMOD_CASTING_TIME, castTime, spell);

    if( !(spellProto->Attributes & (SPELL_ATTR_UNK4|SPELL_ATTR_UNK5)) && spellProto->DmgClass == SPELL_DAMAGE_CLASS_MAGIC && spellProto->SpellFamilyName)
        castTime = int32( float(castTime) * GetFloatValue(UNIT_MOD_CAST_SPEED));
    else
    {
        if (spellProto->Attributes & SPELL_ATTR_RANGED && !(spellProto->AttributesEx2 & SPELL_ATTR_EX2_AUTOREPEAT_FLAG))
            castTime = int32 (float(castTime) * m_modAttackSpeedPct[RANGED_ATTACK]);
    }
}

DiminishingLevels Unit::GetDiminishing(DiminishingGroup group)
{
    for(Diminishing::iterator i = m_Diminishing.begin(); i != m_Diminishing.end(); ++i)
    {
        if(i->DRGroup != group)
            continue;

        if(!i->hitCount)
            return DIMINISHING_LEVEL_1;

        if(!i->hitTime)
            return DIMINISHING_LEVEL_1;

        // If last spell was casted more than 15 seconds ago - reset the count.
        if(i->stack==0 && getMSTimeDiff(i->hitTime,getMSTime()) > 15000)
        {
            i->hitCount = DIMINISHING_LEVEL_1;
            return DIMINISHING_LEVEL_1;
        }
        // or else increase the count.
        else
        {
            return DiminishingLevels(i->hitCount);
        }
    }
    return DIMINISHING_LEVEL_1;
}

void Unit::IncrDiminishing(DiminishingGroup group)
{
    // Checking for existing in the table
    for(Diminishing::iterator i = m_Diminishing.begin(); i != m_Diminishing.end(); ++i)
    {
        if(i->DRGroup != group)
            continue;
        if(i->hitCount < DIMINISHING_LEVEL_IMMUNE)
            i->hitCount += 1;
        return;
    }
    m_Diminishing.push_back(DiminishingReturn(group,getMSTime(),DIMINISHING_LEVEL_2));
}

void Unit::ApplyDiminishingToDuration(DiminishingGroup group, int32 &duration,Unit* caster,DiminishingLevels Level)
{
    if(duration == -1 || group == DIMINISHING_NONE || caster->IsFriendlyTo(this) )
        return;

        // test pet/charm masters instead pets/charmeds
    Unit const* targetOwner = GetCharmerOrOwner();
    Unit const* casterOwner = caster->GetCharmerOrOwner();

    // Duration of crowd control abilities on pvp target is limited by 10 sec. (2.2.0)
    if(duration > 10000 && IsDiminishingReturnsGroupDurationLimited(group))
    {
        Unit const* target = targetOwner ? targetOwner : this;
        Unit const* source = casterOwner ? casterOwner : caster;

        if(target->GetTypeId() == TYPEID_PLAYER && source->GetTypeId() == TYPEID_PLAYER)
            duration = 10000;
    }

    float mod = 1.0f;

    // Some diminishings applies to mobs too (for example, Stun)
    if((GetDiminishingReturnsGroupType(group) == DRTYPE_PLAYER && (targetOwner ? targetOwner->GetTypeId():GetTypeId())  == TYPEID_PLAYER) || GetDiminishingReturnsGroupType(group) == DRTYPE_ALL)
    {
        DiminishingLevels diminish = Level;
        switch(diminish)
        {
            case DIMINISHING_LEVEL_1: break;
            case DIMINISHING_LEVEL_2: mod = 0.5f; break;
            case DIMINISHING_LEVEL_3: mod = 0.25f; break;
            case DIMINISHING_LEVEL_IMMUNE: mod = 0.0f;break;
            default: break;
        }
    }

    duration = int32(duration * mod);
}

void Unit::ApplyDiminishingAura( DiminishingGroup group, bool apply )
{
    // Checking for existing in the table
    for(Diminishing::iterator i = m_Diminishing.begin(); i != m_Diminishing.end(); ++i)
    {
        if(i->DRGroup != group)
            continue;

        if(apply)
            i->stack += 1;
        else if(i->stack)
        {
            i->stack -= 1;
            // Remember time after last aura from group removed
            if (i->stack == 0)
                i->hitTime = getMSTime();
        }
        break;
    }
}

uint32 Unit::GetSpellMaxRangeForTarget(Unit* target,const SpellRangeEntry * rangeEntry)
{
    if (!rangeEntry)
        return 0;
    if (rangeEntry->maxRangeHostile == rangeEntry->maxRangeFriend)
        return rangeEntry->maxRangeFriend;
    if (IsHostileTo(target))
        return rangeEntry->maxRangeHostile;
    return rangeEntry->maxRangeFriend;
};
uint32 Unit::GetSpellMinRangeForTarget(Unit* target,const SpellRangeEntry * rangeEntry)
{
    if (!rangeEntry)
        return 0;
    if (rangeEntry->minRangeHostile == rangeEntry->minRangeFriend)
        return rangeEntry->minRangeFriend;
    if (IsHostileTo(target))
        return rangeEntry->minRangeHostile;
    return rangeEntry->minRangeFriend;
};
uint32 Unit::GetSpellRadiusForTarget(Unit* target,const SpellRadiusEntry * radiusEntry)
{
    if (!radiusEntry)
        return 0;
    if (radiusEntry->radiusHostile == radiusEntry->radiusFriend)
        return radiusEntry->radiusFriend;
    if (IsHostileTo(target))
        return radiusEntry->radiusHostile;
    return radiusEntry->radiusFriend;
};

Unit* Unit::GetUnit(WorldObject& object, uint64 guid)
{
    return ObjectAccessor::GetUnit(object,guid);
}

Player* Unit::GetPlayer(uint64 guid)
{
    return ObjectAccessor::FindPlayer(guid);
}

Creature* Unit::GetCreature(WorldObject& object, uint64 guid)
{
    return object.GetMap()->GetCreature(guid);
}

bool Unit::isVisibleForInState( Player const* u, bool inVisibleList ) const
{
    return u->canSeeOrDetect(this, false, inVisibleList, false);
}

uint32 Unit::GetCreatureType() const
{
    if(GetTypeId() == TYPEID_PLAYER)
    {
        SpellShapeshiftEntry const* ssEntry = sSpellShapeshiftStore.LookupEntry(m_form);
        if(ssEntry && ssEntry->creatureType > 0)
            return ssEntry->creatureType;
        else
            return CREATURE_TYPE_HUMANOID;
    }
    else
        return ((Creature*)this)->GetCreatureInfo()->type;
}

/*#######################################
########                         ########
########       STAT SYSTEM       ########
########                         ########
#######################################*/

bool Unit::HandleStatModifier(UnitMods unitMod, UnitModifierType modifierType, float amount, bool apply)
{
    if(unitMod >= UNIT_MOD_END || modifierType >= MODIFIER_TYPE_END)
    {
        sLog.outError("ERROR in HandleStatModifier(): non existed UnitMods or wrong UnitModifierType!");
        return false;
    }

    float val = 1.0f;

    switch(modifierType)
    {
        case BASE_VALUE:
        case TOTAL_VALUE:
            m_auraModifiersGroup[unitMod][modifierType] += apply ? amount : -amount;
            break;
        case BASE_PCT:
        case TOTAL_PCT:
            if(amount <= -100.0f)                           //small hack-fix for -100% modifiers
                amount = -200.0f;

            val = (100.0f + amount) / 100.0f;
            m_auraModifiersGroup[unitMod][modifierType] *= apply ? val : (1.0f/val);
            break;

        default:
            break;
    }

    if(!CanModifyStats())
        return false;

    switch(unitMod)
    {
        case UNIT_MOD_STAT_STRENGTH:
        case UNIT_MOD_STAT_AGILITY:
        case UNIT_MOD_STAT_STAMINA:
        case UNIT_MOD_STAT_INTELLECT:
        case UNIT_MOD_STAT_SPIRIT:         UpdateStats(GetStatByAuraGroup(unitMod));  break;

        case UNIT_MOD_ARMOR:               UpdateArmor();           break;
        case UNIT_MOD_HEALTH:              UpdateMaxHealth();       break;

        case UNIT_MOD_MANA:
        case UNIT_MOD_RAGE:
        case UNIT_MOD_FOCUS:
        case UNIT_MOD_ENERGY:
        case UNIT_MOD_HAPPINESS:
        case UNIT_MOD_RUNE:
        case UNIT_MOD_RUNIC_POWER:          UpdateMaxPower(GetPowerTypeByAuraGroup(unitMod));          break;

        case UNIT_MOD_RESISTANCE_HOLY:
        case UNIT_MOD_RESISTANCE_FIRE:
        case UNIT_MOD_RESISTANCE_NATURE:
        case UNIT_MOD_RESISTANCE_FROST:
        case UNIT_MOD_RESISTANCE_SHADOW:
        case UNIT_MOD_RESISTANCE_ARCANE:   UpdateResistances(GetSpellSchoolByAuraGroup(unitMod));      break;

        case UNIT_MOD_ATTACK_POWER:        UpdateAttackPowerAndDamage();         break;
        case UNIT_MOD_ATTACK_POWER_RANGED: UpdateAttackPowerAndDamage(true);     break;

        case UNIT_MOD_DAMAGE_MAINHAND:     UpdateDamagePhysical(BASE_ATTACK);    break;
        case UNIT_MOD_DAMAGE_OFFHAND:      UpdateDamagePhysical(OFF_ATTACK);     break;
        case UNIT_MOD_DAMAGE_RANGED:       UpdateDamagePhysical(RANGED_ATTACK);  break;

        default:
            break;
    }

    return true;
}

float Unit::GetModifierValue(UnitMods unitMod, UnitModifierType modifierType) const
{
    if( unitMod >= UNIT_MOD_END || modifierType >= MODIFIER_TYPE_END)
    {
        sLog.outError("trial to access non existed modifier value from UnitMods!");
        return 0.0f;
    }

    if(modifierType == TOTAL_PCT && m_auraModifiersGroup[unitMod][modifierType] <= 0.0f)
        return 0.0f;

    return m_auraModifiersGroup[unitMod][modifierType];
}

float Unit::GetTotalStatValue(Stats stat) const
{
    UnitMods unitMod = UnitMods(UNIT_MOD_STAT_START + stat);

    if(m_auraModifiersGroup[unitMod][TOTAL_PCT] <= 0.0f)
        return 0.0f;

    // value = ((base_value * base_pct) + total_value) * total_pct
    float value  = m_auraModifiersGroup[unitMod][BASE_VALUE] + GetCreateStat(stat);
    value *= m_auraModifiersGroup[unitMod][BASE_PCT];
    value += m_auraModifiersGroup[unitMod][TOTAL_VALUE];
    value *= m_auraModifiersGroup[unitMod][TOTAL_PCT];

    return value;
}

float Unit::GetTotalAuraModValue(UnitMods unitMod) const
{
    if(unitMod >= UNIT_MOD_END)
    {
        sLog.outError("trial to access non existed UnitMods in GetTotalAuraModValue()!");
        return 0.0f;
    }

    if(m_auraModifiersGroup[unitMod][TOTAL_PCT] <= 0.0f)
        return 0.0f;

    float value  = m_auraModifiersGroup[unitMod][BASE_VALUE];
    value *= m_auraModifiersGroup[unitMod][BASE_PCT];
    value += m_auraModifiersGroup[unitMod][TOTAL_VALUE];
    value *= m_auraModifiersGroup[unitMod][TOTAL_PCT];

    return value;
}

SpellSchools Unit::GetSpellSchoolByAuraGroup(UnitMods unitMod) const
{
    SpellSchools school = SPELL_SCHOOL_NORMAL;

    switch(unitMod)
    {
        case UNIT_MOD_RESISTANCE_HOLY:     school = SPELL_SCHOOL_HOLY;          break;
        case UNIT_MOD_RESISTANCE_FIRE:     school = SPELL_SCHOOL_FIRE;          break;
        case UNIT_MOD_RESISTANCE_NATURE:   school = SPELL_SCHOOL_NATURE;        break;
        case UNIT_MOD_RESISTANCE_FROST:    school = SPELL_SCHOOL_FROST;         break;
        case UNIT_MOD_RESISTANCE_SHADOW:   school = SPELL_SCHOOL_SHADOW;        break;
        case UNIT_MOD_RESISTANCE_ARCANE:   school = SPELL_SCHOOL_ARCANE;        break;

        default:
            break;
    }

    return school;
}

Stats Unit::GetStatByAuraGroup(UnitMods unitMod) const
{
    Stats stat = STAT_STRENGTH;

    switch(unitMod)
    {
        case UNIT_MOD_STAT_STRENGTH:    stat = STAT_STRENGTH;      break;
        case UNIT_MOD_STAT_AGILITY:     stat = STAT_AGILITY;       break;
        case UNIT_MOD_STAT_STAMINA:     stat = STAT_STAMINA;       break;
        case UNIT_MOD_STAT_INTELLECT:   stat = STAT_INTELLECT;     break;
        case UNIT_MOD_STAT_SPIRIT:      stat = STAT_SPIRIT;        break;

        default:
            break;
    }

    return stat;
}

Powers Unit::GetPowerTypeByAuraGroup(UnitMods unitMod) const
{
    switch(unitMod)
    {
        case UNIT_MOD_MANA:       return POWER_MANA;
        case UNIT_MOD_RAGE:       return POWER_RAGE;
        case UNIT_MOD_FOCUS:      return POWER_FOCUS;
        case UNIT_MOD_ENERGY:     return POWER_ENERGY;
        case UNIT_MOD_HAPPINESS:  return POWER_HAPPINESS;
        case UNIT_MOD_RUNE:       return POWER_RUNE;
        case UNIT_MOD_RUNIC_POWER:return POWER_RUNIC_POWER;
    }

    return POWER_MANA;
}

float Unit::GetTotalAttackPowerValue(WeaponAttackType attType) const
{
    if (attType == RANGED_ATTACK)
    {
        int32 ap = GetInt32Value(UNIT_FIELD_RANGED_ATTACK_POWER) + GetInt32Value(UNIT_FIELD_RANGED_ATTACK_POWER_MODS);
        if (ap < 0)
            return 0.0f;
        return ap * (1.0f + GetFloatValue(UNIT_FIELD_RANGED_ATTACK_POWER_MULTIPLIER));
    }
    else
    {
        int32 ap = GetInt32Value(UNIT_FIELD_ATTACK_POWER) + GetInt32Value(UNIT_FIELD_ATTACK_POWER_MODS);
        if (ap < 0)
            return 0.0f;
        return ap * (1.0f + GetFloatValue(UNIT_FIELD_ATTACK_POWER_MULTIPLIER));
    }
}

float Unit::GetWeaponDamageRange(WeaponAttackType attType ,WeaponDamageRange type) const
{
    if (attType == OFF_ATTACK && !haveOffhandWeapon())
        return 0.0f;

    return m_weaponDamage[attType][type];
}

void Unit::SetLevel(uint32 lvl)
{
    SetUInt32Value(UNIT_FIELD_LEVEL, lvl);

    // group update
    if ((GetTypeId() == TYPEID_PLAYER) && ((Player*)this)->GetGroup())
        ((Player*)this)->SetGroupUpdateFlag(GROUP_UPDATE_FLAG_LEVEL);
}

void Unit::SetHealth(uint32 val)
{
    if(getDeathState() == JUST_DIED)
        val = 0;
    else
    {
        uint32 maxHealth = GetMaxHealth();
        if(maxHealth < val)
            val = maxHealth;
    }

    SetUInt32Value(UNIT_FIELD_HEALTH, val);

    // group update
    if(GetTypeId() == TYPEID_PLAYER)
    {
        if(((Player*)this)->GetGroup())
            ((Player*)this)->SetGroupUpdateFlag(GROUP_UPDATE_FLAG_CUR_HP);
    }
    else if(((Creature*)this)->isPet())
    {
        Pet *pet = ((Pet*)this);
        if(pet->isControlled())
        {
            Unit *owner = GetOwner();
            if(owner && (owner->GetTypeId() == TYPEID_PLAYER) && ((Player*)owner)->GetGroup())
                ((Player*)owner)->SetGroupUpdateFlag(GROUP_UPDATE_FLAG_PET_CUR_HP);
        }
    }
}

void Unit::SetMaxHealth(uint32 val)
{
    uint32 health = GetHealth();
    SetUInt32Value(UNIT_FIELD_MAXHEALTH, val);

    // group update
    if(GetTypeId() == TYPEID_PLAYER)
    {
        if(((Player*)this)->GetGroup())
            ((Player*)this)->SetGroupUpdateFlag(GROUP_UPDATE_FLAG_MAX_HP);
    }
    else if(((Creature*)this)->isPet())
    {
        Pet *pet = ((Pet*)this);
        if(pet->isControlled())
        {
            Unit *owner = GetOwner();
            if(owner && (owner->GetTypeId() == TYPEID_PLAYER) && ((Player*)owner)->GetGroup())
                ((Player*)owner)->SetGroupUpdateFlag(GROUP_UPDATE_FLAG_PET_MAX_HP);
        }
    }

    if(val < health)
        SetHealth(val);
}

void Unit::SetPower(Powers power, uint32 val)
{
    if(GetPower(power) == val)
        return;

    uint32 maxPower = GetMaxPower(power);
    if(maxPower < val)
        val = maxPower;

    SetStatInt32Value(UNIT_FIELD_POWER1 + power, val);

    WorldPacket data(SMSG_POWER_UPDATE);
    data.append(GetPackGUID());
    data << uint8(power);
    data << uint32(val);
    SendMessageToSet(&data, GetTypeId() == TYPEID_PLAYER ? true : false);

    // group update
    if(GetTypeId() == TYPEID_PLAYER)
    {
        if(((Player*)this)->GetGroup())
            ((Player*)this)->SetGroupUpdateFlag(GROUP_UPDATE_FLAG_CUR_POWER);
    }
    else if(((Creature*)this)->isPet())
    {
        Pet *pet = ((Pet*)this);
        if(pet->isControlled())
        {
            Unit *owner = GetOwner();
            if(owner && (owner->GetTypeId() == TYPEID_PLAYER) && ((Player*)owner)->GetGroup())
                ((Player*)owner)->SetGroupUpdateFlag(GROUP_UPDATE_FLAG_PET_CUR_POWER);
        }

        // Update the pet's character sheet with happiness damage bonus
        if(pet->getPetType() == HUNTER_PET && power == POWER_HAPPINESS)
        {
            pet->UpdateDamagePhysical(BASE_ATTACK);
        }
    }
}

void Unit::SetMaxPower(Powers power, uint32 val)
{
    uint32 cur_power = GetPower(power);
    SetStatInt32Value(UNIT_FIELD_MAXPOWER1 + power, val);

    // group update
    if(GetTypeId() == TYPEID_PLAYER)
    {
        if(((Player*)this)->GetGroup())
            ((Player*)this)->SetGroupUpdateFlag(GROUP_UPDATE_FLAG_MAX_POWER);
    }
    else if(((Creature*)this)->isPet())
    {
        Pet *pet = ((Pet*)this);
        if(pet->isControlled())
        {
            Unit *owner = GetOwner();
            if(owner && (owner->GetTypeId() == TYPEID_PLAYER) && ((Player*)owner)->GetGroup())
                ((Player*)owner)->SetGroupUpdateFlag(GROUP_UPDATE_FLAG_PET_MAX_POWER);
        }
    }

    if(val < cur_power)
        SetPower(power, val);
}

void Unit::ApplyPowerMod(Powers power, uint32 val, bool apply)
{
    ApplyModUInt32Value(UNIT_FIELD_POWER1+power, val, apply);

    // group update
    if(GetTypeId() == TYPEID_PLAYER)
    {
        if(((Player*)this)->GetGroup())
            ((Player*)this)->SetGroupUpdateFlag(GROUP_UPDATE_FLAG_CUR_POWER);
    }
    else if(((Creature*)this)->isPet())
    {
        Pet *pet = ((Pet*)this);
        if(pet->isControlled())
        {
            Unit *owner = GetOwner();
            if(owner && (owner->GetTypeId() == TYPEID_PLAYER) && ((Player*)owner)->GetGroup())
                ((Player*)owner)->SetGroupUpdateFlag(GROUP_UPDATE_FLAG_PET_CUR_POWER);
        }
    }
}

void Unit::ApplyMaxPowerMod(Powers power, uint32 val, bool apply)
{
    ApplyModUInt32Value(UNIT_FIELD_MAXPOWER1+power, val, apply);

    // group update
    if(GetTypeId() == TYPEID_PLAYER)
    {
        if(((Player*)this)->GetGroup())
            ((Player*)this)->SetGroupUpdateFlag(GROUP_UPDATE_FLAG_MAX_POWER);
    }
    else if(((Creature*)this)->isPet())
    {
        Pet *pet = ((Pet*)this);
        if(pet->isControlled())
        {
            Unit *owner = GetOwner();
            if(owner && (owner->GetTypeId() == TYPEID_PLAYER) && ((Player*)owner)->GetGroup())
                ((Player*)owner)->SetGroupUpdateFlag(GROUP_UPDATE_FLAG_PET_MAX_POWER);
        }
    }
}

uint32 Unit::GetCreatePowers( Powers power ) const
{
    // POWER_FOCUS and POWER_HAPPINESS only have hunter pet
    switch(power)
    {
        case POWER_MANA:      return GetCreateMana();
        case POWER_RAGE:      return 1000;
        case POWER_FOCUS:     return (GetTypeId()==TYPEID_PLAYER || !((Creature const*)this)->isPet() || ((Pet const*)this)->getPetType()!=HUNTER_PET ? 0 : 100);
        case POWER_ENERGY:    return 100;
        case POWER_HAPPINESS: return (GetTypeId()==TYPEID_PLAYER || !((Creature const*)this)->isPet() || ((Pet const*)this)->getPetType()!=HUNTER_PET ? 0 : 1050000);
        case POWER_RUNIC_POWER: return 1000;
    }

    return 0;
}

void Unit::AddToWorld()
{
    if(!IsInWorld())
    {
        WorldObject::AddToWorld();
        m_Notified = false;
        m_IsInNotifyList = false;
        SetToNotify();
    }
}

void Unit::RemoveFromWorld()
{
    // cleanup
    assert(GetGUID());

    if(IsInWorld())
    {
        UnsummonAllTotems();
        RemoveAllControlled();
        RemoveCharmAuras();
        RemoveBindSightAuras();
        RemoveNotOwnSingleTargetAuras();
        ExitVehicle();

        if(GetCharmerGUID())
            sLog.outCrash("Unit %u has charmer guid when removed from world", GetEntry());

        WorldObject::RemoveFromWorld();
    }
}

void Unit::CleanupsBeforeDelete()
{
    assert(GetGUID());

    //A unit may be in removelist and not in world, but it is still in grid
    //and may have some references during delete
    RemoveAllAuras();
    _DeleteAuras();
    InterruptNonMeleeSpells(true);
    m_Events.KillAllEvents(false);                      // non-delatable (currently casted spells) will not deleted now but it will deleted at call in Map::RemoveAllObjectsInRemoveList
    CombatStop();
    ClearComboPointHolders();
    DeleteThreatList();
    getHostilRefManager().setOnlineOfflineState(false);
    RemoveAllGameObjects();
    RemoveAllDynObjects();
    GetMotionMaster()->Clear(false);                    // remove different non-standard movement generators.

    if(IsInWorld())
        RemoveFromWorld();
}

void Unit::UpdateCharmAI()
{
    if(GetTypeId() == TYPEID_PLAYER)
        return;

    if(i_disabledAI) // disabled AI must be primary AI
    {
        if(!isCharmed())
        {
            if(i_AI) delete i_AI;
            i_AI = i_disabledAI;
            i_disabledAI = NULL;
        }
    }
    else
    {
        if(isCharmed())
        {
            i_disabledAI = i_AI;
            if(isPossessed())
                i_AI = new PossessedAI((Creature*)this);
            else
                i_AI = new PetAI((Creature*)this);
        }
    }
}

CharmInfo* Unit::InitCharmInfo()
{
    if(!m_charmInfo)
        m_charmInfo = new CharmInfo(this);

    return m_charmInfo;
}

void Unit::DeleteCharmInfo()
{
    if(!m_charmInfo)
        return;

    delete m_charmInfo;
    m_charmInfo = NULL;
}

CharmInfo::CharmInfo(Unit* unit)
: m_unit(unit), m_CommandState(COMMAND_FOLLOW), m_petnumber(0), m_barInit(false)
{
    for(int i =0; i<4; ++i)
    {
        m_charmspells[i].spellId = 0;
        m_charmspells[i].active = ACT_DISABLED;
    }
    if(m_unit->GetTypeId() == TYPEID_UNIT)
    {
        m_oldReactState = ((Creature*)m_unit)->GetReactState();
        ((Creature*)m_unit)->SetReactState(REACT_PASSIVE);
    }
}

CharmInfo::~CharmInfo()
{
    if(m_unit->GetTypeId() == TYPEID_UNIT)
    {
        ((Creature*)m_unit)->SetReactState(m_oldReactState);
    }
}

void CharmInfo::InitPetActionBar()
{
    if (m_barInit)
        return;

    // the first 3 SpellOrActions are attack, follow and stay
    for(uint32 i = 0; i < 3; i++)
    {
        PetActionBar[i].Type = ACT_COMMAND;
        PetActionBar[i].SpellOrAction = COMMAND_ATTACK - i;

        PetActionBar[i + 7].Type = ACT_REACTION;
        PetActionBar[i + 7].SpellOrAction = COMMAND_ATTACK - i;
    }
    for(uint32 i=0; i < 4; i++)
    {
        PetActionBar[i + 3].Type = ACT_DISABLED;
        PetActionBar[i + 3].SpellOrAction = 0;
    }
    m_barInit = true;
}

void CharmInfo::InitEmptyActionBar(bool withAttack)
{
    if (m_barInit)
        return;

    for(uint32 x = 0; x < 10; ++x)
    {
        PetActionBar[x].Type = ACT_PASSIVE;
        PetActionBar[x].SpellOrAction = 0;
    }
    if (withAttack)
    {
        PetActionBar[0].Type = ACT_COMMAND;
        PetActionBar[0].SpellOrAction = COMMAND_ATTACK;
    }
    m_barInit = true;
}

void CharmInfo::InitPossessCreateSpells()
{
    InitEmptyActionBar();
    if(m_unit->GetTypeId() == TYPEID_UNIT)
    {
        for(uint32 i = 0; i < CREATURE_MAX_SPELLS; ++i)
        {
            uint32 spellid = ((Creature*)m_unit)->m_spells[i];
            if(IsPassiveSpell(spellid))
                m_unit->CastSpell(m_unit, spellid, true);
            else
                AddSpellToAB(0, spellid, ACT_DISABLED);
        }
    }
}

void CharmInfo::InitCharmCreateSpells()
{
    if(m_unit->GetTypeId() == TYPEID_PLAYER)                //charmed players don't have spells
    {
        InitEmptyActionBar();
        return;
    }

    InitPetActionBar();

    for(uint32 x = 0; x < MAX_SPELL_CHARM; ++x)
    {
        uint32 spellId = ((Creature*)m_unit)->m_spells[x];
        m_charmspells[x].spellId = spellId;

        if(!spellId)
            continue;

        if (IsPassiveSpell(spellId))
        {
            m_unit->CastSpell(m_unit, spellId, true);
            m_charmspells[x].active = ACT_PASSIVE;
        }
        else
        {
            ActiveStates newstate;
            bool onlyselfcast = true;
            SpellEntry const *spellInfo = sSpellStore.LookupEntry(spellId);

            if(!spellInfo) onlyselfcast = false;
            for(uint32 i = 0;i<3 && onlyselfcast;++i)       //non existent spell will not make any problems as onlyselfcast would be false -> break right away
            {
                if(spellInfo->EffectImplicitTargetA[i] != TARGET_UNIT_CASTER && spellInfo->EffectImplicitTargetA[i] != 0)
                    onlyselfcast = false;
            }

            if(onlyselfcast || !IsPositiveSpell(spellId))   //only self cast and spells versus enemies are autocastable
                newstate = ACT_DISABLED;
            else
                newstate = ACT_PASSIVE;

            AddSpellToAB(0, spellId, newstate);
        }
    }
}

bool CharmInfo::AddSpellToAB(uint32 oldid, uint32 newid, ActiveStates newstate)
{
    for(uint8 i = 0; i < 10; i++)
    {
        if((PetActionBar[i].Type == ACT_DISABLED || PetActionBar[i].Type == ACT_ENABLED || PetActionBar[i].Type == ACT_PASSIVE) && PetActionBar[i].SpellOrAction == oldid)
        {
            PetActionBar[i].SpellOrAction = newid;
            if(!oldid)
            {
                if(newstate == ACT_DECIDE)
                    PetActionBar[i].Type = ACT_DISABLED;
                else
                    PetActionBar[i].Type = newstate;
            }

            return true;
        }
    }
    return false;
}

void CharmInfo::ToggleCreatureAutocast(uint32 spellid, bool apply)
{
    if(IsPassiveSpell(spellid))
        return;

    for(uint32 x = 0; x < MAX_SPELL_CHARM; ++x)
    {
        if(spellid == m_charmspells[x].spellId)
        {
            m_charmspells[x].active = apply ? ACT_ENABLED : ACT_DISABLED;
        }
    }
}

void CharmInfo::SetPetNumber(uint32 petnumber, bool statwindow)
{
    m_petnumber = petnumber;
    if(statwindow)
        m_unit->SetUInt32Value(UNIT_FIELD_PETNUMBER, m_petnumber);
    else
        m_unit->SetUInt32Value(UNIT_FIELD_PETNUMBER, 0);
}

bool Unit::isFrozen() const
{
    return HasAuraState(AURA_STATE_FROZEN);
}

struct ProcTriggeredData
{
    ProcTriggeredData(Aura* _aura)
        : aura(_aura)
    {
        effMask = 0;
        spellProcEvent = NULL;
    }
    SpellProcEventEntry const *spellProcEvent;
    Aura * aura;
    uint32 effMask;
};

typedef std::list< ProcTriggeredData > ProcTriggeredList;

// List of auras that CAN be trigger but may not exist in spell_proc_event
// in most case need for drop charges
// in some types of aura need do additional check
// for example SPELL_AURA_MECHANIC_IMMUNITY - need check for mechanic
bool InitTriggerAuraData()
{
    for (int i=0;i<TOTAL_AURAS;i++)
    {
      isTriggerAura[i]=false;
      isNonTriggerAura[i] = false;
    }
    isTriggerAura[SPELL_AURA_DUMMY] = true;
    isTriggerAura[SPELL_AURA_MOD_CONFUSE] = true;
    isTriggerAura[SPELL_AURA_MOD_THREAT] = true;
    isTriggerAura[SPELL_AURA_MOD_STUN] = true; // Aura not have charges but need remove him on trigger
    isTriggerAura[SPELL_AURA_MOD_DAMAGE_DONE] = true;
    isTriggerAura[SPELL_AURA_MOD_DAMAGE_TAKEN] = true;
    isTriggerAura[SPELL_AURA_MOD_RESISTANCE] = true;
    isTriggerAura[SPELL_AURA_MOD_STEALTH] = true; // Aura not have charges but need remove him on trigger
    isTriggerAura[SPELL_AURA_MOD_ROOT] = true;
    isTriggerAura[SPELL_AURA_REFLECT_SPELLS] = true;
    isTriggerAura[SPELL_AURA_DAMAGE_IMMUNITY] = true;
    isTriggerAura[SPELL_AURA_PROC_TRIGGER_SPELL] = true;
    isTriggerAura[SPELL_AURA_PROC_TRIGGER_DAMAGE] = true;
    isTriggerAura[SPELL_AURA_MOD_CASTING_SPEED_NOT_STACK] = true;
    isTriggerAura[SPELL_AURA_MOD_POWER_COST_SCHOOL_PCT] = true;
    isTriggerAura[SPELL_AURA_MOD_POWER_COST_SCHOOL] = true;
    isTriggerAura[SPELL_AURA_REFLECT_SPELLS_SCHOOL] = true;
    isTriggerAura[SPELL_AURA_MECHANIC_IMMUNITY] = true;
    isTriggerAura[SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN] = true;
    isTriggerAura[SPELL_AURA_SPELL_MAGNET] = true;
    isTriggerAura[SPELL_AURA_MOD_ATTACK_POWER] = true;
    isTriggerAura[SPELL_AURA_ADD_CASTER_HIT_TRIGGER] = true;
    isTriggerAura[SPELL_AURA_OVERRIDE_CLASS_SCRIPTS] = true;
    isTriggerAura[SPELL_AURA_MOD_MECHANIC_RESISTANCE] = true;
    isTriggerAura[SPELL_AURA_RANGED_ATTACK_POWER_ATTACKER_BONUS] = true;
    isTriggerAura[SPELL_AURA_MOD_HASTE] = true;
    isTriggerAura[SPELL_AURA_MOD_ATTACKER_MELEE_HIT_CHANCE]=true;
    isTriggerAura[SPELL_AURA_RAID_PROC_FROM_CHARGE] = true;
    isTriggerAura[SPELL_AURA_RAID_PROC_FROM_CHARGE_WITH_VALUE] = true;
    isTriggerAura[SPELL_AURA_PROC_TRIGGER_SPELL_WITH_VALUE] = true;
    isTriggerAura[SPELL_AURA_MOD_DAMAGE_FROM_CASTER] = true;
    isTriggerAura[SPELL_AURA_ABILITY_IGNORE_AURASTATE] = true;

    isNonTriggerAura[SPELL_AURA_MOD_POWER_REGEN]=true;
    isNonTriggerAura[SPELL_AURA_REDUCE_PUSHBACK]=true;

    return true;
}

uint32 createProcExtendMask(SpellNonMeleeDamage *damageInfo, SpellMissInfo missCondition)
{
    uint32 procEx = PROC_EX_NONE;
    // Check victim state
    if (missCondition!=SPELL_MISS_NONE)
    switch (missCondition)
    {
        case SPELL_MISS_MISS:    procEx|=PROC_EX_MISS;   break;
        case SPELL_MISS_RESIST:  procEx|=PROC_EX_RESIST; break;
        case SPELL_MISS_DODGE:   procEx|=PROC_EX_DODGE;  break;
        case SPELL_MISS_PARRY:   procEx|=PROC_EX_PARRY;  break;
        case SPELL_MISS_BLOCK:   procEx|=PROC_EX_BLOCK;  break;
        case SPELL_MISS_EVADE:   procEx|=PROC_EX_EVADE;  break;
        case SPELL_MISS_IMMUNE:  procEx|=PROC_EX_IMMUNE; break;
        case SPELL_MISS_IMMUNE2: procEx|=PROC_EX_IMMUNE; break;
        case SPELL_MISS_DEFLECT: procEx|=PROC_EX_DEFLECT;break;
        case SPELL_MISS_ABSORB:  procEx|=PROC_EX_ABSORB; break;
        case SPELL_MISS_REFLECT: procEx|=PROC_EX_REFLECT;break;
        default:
            break;
    }
    else
    {
        // On block
        if (damageInfo->blocked)
            procEx|=PROC_EX_BLOCK;
        // On absorb
        if (damageInfo->absorb)
            procEx|=PROC_EX_ABSORB;
        // On crit
        if (damageInfo->HitInfo & SPELL_HIT_TYPE_CRIT)
            procEx|=PROC_EX_CRITICAL_HIT;
        else
            procEx|=PROC_EX_NORMAL_HIT;
    }
    return procEx;
}

void Unit::ProcDamageAndSpellFor( bool isVictim, Unit * pTarget, uint32 procFlag, uint32 procExtra, WeaponAttackType attType, SpellEntry const * procSpell, uint32 damage )
{
    // For melee/ranged based attack need update skills and set some Aura states
    if (procFlag & MELEE_BASED_TRIGGER_MASK)
    {
        // Update skills here for players
        if (GetTypeId() == TYPEID_PLAYER)
        {
            // On melee based hit/miss/resist need update skill (for victim and attacker)
            if (procExtra&(PROC_EX_NORMAL_HIT|PROC_EX_MISS|PROC_EX_RESIST))
            {
                if (pTarget->GetTypeId() != TYPEID_PLAYER && pTarget->GetCreatureType() != CREATURE_TYPE_CRITTER)
                    ((Player*)this)->UpdateCombatSkills(pTarget, attType, isVictim);
            }
            // Update defence if player is victim and parry/dodge/block
            if (isVictim && procExtra&(PROC_EX_DODGE|PROC_EX_PARRY|PROC_EX_BLOCK))
                ((Player*)this)->UpdateDefense();
        }
        // If exist crit/parry/dodge/block need update aura state (for victim and attacker)
        if (procExtra & (PROC_EX_CRITICAL_HIT|PROC_EX_PARRY|PROC_EX_DODGE|PROC_EX_BLOCK))
        {
            // for victim
            if (isVictim)
            {
                // if victim and dodge attack
                if (procExtra&PROC_EX_DODGE)
                {
                    //Update AURA_STATE on dodge
                    if (getClass() != CLASS_ROGUE) // skip Rogue Riposte
                    {
                        ModifyAuraState(AURA_STATE_DEFENSE, true);
                        StartReactiveTimer( REACTIVE_DEFENSE );
                    }
                }
                // if victim and parry attack
                if (procExtra & PROC_EX_PARRY)
                {
                    // For Hunters only Counterattack (skip Mongoose bite)
                    if (getClass() == CLASS_HUNTER)
                    {
                        ModifyAuraState(AURA_STATE_HUNTER_PARRY, true);
                        StartReactiveTimer( REACTIVE_HUNTER_PARRY );
                    }
                    else
                    {
                        ModifyAuraState(AURA_STATE_DEFENSE, true);
                        StartReactiveTimer( REACTIVE_DEFENSE );
                    }
                }
                // if and victim block attack
                if (procExtra & PROC_EX_BLOCK)
                {
                    ModifyAuraState(AURA_STATE_DEFENSE,true);
                    StartReactiveTimer( REACTIVE_DEFENSE );
                }
            }
            else //For attacker
            {
                // Overpower on victim dodge
                if (procExtra&PROC_EX_DODGE && GetTypeId() == TYPEID_PLAYER && getClass() == CLASS_WARRIOR)
                {
                    ((Player*)this)->AddComboPoints(pTarget, 1);
                    StartReactiveTimer( REACTIVE_OVERPOWER );
                }
            }
        }
    }

    ProcTriggeredList procTriggered;
    // Fill procTriggered list
    for(AuraMap::const_iterator itr = GetAuras().begin(); itr!= GetAuras().end(); ++itr)
    {
        ProcTriggeredData triggerData(itr->second);

        if(!IsTriggeredAtSpellProcEvent(pTarget, triggerData.aura, procSpell, procFlag, procExtra, attType, isVictim, (damage > 0), triggerData.spellProcEvent))
            continue;
        for (uint8 i=0; i<MAX_SPELL_EFFECTS;++i)
        {
            if (AuraEffect * aurEff = itr->second->GetPartAura(i))
            {
                // Skip this auras
                if (isNonTriggerAura[aurEff->GetAuraName()])
                    continue;
                // If not trigger by default and spellProcEvent==NULL - skip
                if (!isTriggerAura[aurEff->GetAuraName()] && triggerData.spellProcEvent==NULL)
                    continue;
                triggerData.effMask |= 1<<i;
            }
        }
        if (triggerData.effMask)
            procTriggered.push_front(triggerData);
    }

    // Nothing found
    if (procTriggered.empty())
        return;
    // Handle effects proceed this time
    for(ProcTriggeredList::iterator i = procTriggered.begin(); i != procTriggered.end(); ++i)
    {
        // look for aura in auras list, it may be removed while proc event processing
        if (!HasAura(i->aura))
            continue;

        bool useCharges= i->aura->GetAuraCharges()>0;
        bool takeCharges = false;
        SpellEntry const *spellInfo = i->aura->GetSpellProto();
        uint32 Id=i->aura->GetId();

        // For players set spell cooldown if need
        uint32 cooldown = 0;
        if (GetTypeId() == TYPEID_PLAYER && i->spellProcEvent && i->spellProcEvent->cooldown)
            cooldown = i->spellProcEvent->cooldown;

        uint32 procDebug = 0;

        for (uint8 effIndex = 0; effIndex<MAX_SPELL_EFFECTS;++effIndex)
        {
            if (!(i->effMask & (1<<effIndex)))
                continue;

            AuraEffect *triggeredByAura = i->aura->GetPartAura(effIndex);
            assert(triggeredByAura);

            switch(triggeredByAura->GetAuraName())
            {
                case SPELL_AURA_PROC_TRIGGER_SPELL:
                {
                    sLog.outDebug("ProcDamageAndSpell: casting spell %u (triggered by %s aura of spell %u)", spellInfo->Id,(isVictim?"a victim's":"an attacker's"), triggeredByAura->GetId());
                    // Don`t drop charge or add cooldown for not started trigger
                    if (!HandleProcTriggerSpell(pTarget, damage, triggeredByAura, procSpell, procFlag, procExtra, cooldown))
                        continue;
                    break;
                }
                case SPELL_AURA_PROC_TRIGGER_DAMAGE:
                {
                    sLog.outDebug("ProcDamageAndSpell: doing %u damage from spell id %u (triggered by %s aura of spell %u)", triggeredByAura->GetAmount() , spellInfo->Id, (isVictim?"a victim's":"an attacker's"), triggeredByAura->GetId());
                    SpellNonMeleeDamage damageInfo(this, pTarget, spellInfo->Id, spellInfo->SchoolMask);
                    uint32 damage = SpellDamageBonus(pTarget, spellInfo, triggeredByAura->GetAmount(), SPELL_DIRECT_DAMAGE);
                    CalculateSpellDamageTaken(&damageInfo, damage, spellInfo);
                    SendSpellNonMeleeDamageLog(&damageInfo);
                    DealSpellDamage(&damageInfo, true);
                    break;
                }
                case SPELL_AURA_MANA_SHIELD:
                case SPELL_AURA_DUMMY:
                {
                    sLog.outDebug("ProcDamageAndSpell: casting spell id %u (triggered by %s dummy aura of spell %u)", spellInfo->Id,(isVictim?"a victim's":"an attacker's"), triggeredByAura->GetId());
                    if (!HandleDummyAuraProc(pTarget, damage, triggeredByAura, procSpell, procFlag, procExtra, cooldown))
                        continue;
                    if (procDebug & 1)
                        sLog.outError("Dummy aura of spell %d procs twice from one effect!",spellInfo->Id);
                    procDebug |= 1;
                    break;
                }
                case SPELL_AURA_OBS_MOD_ENERGY:
                    sLog.outDebug("ProcDamageAndSpell: casting spell id %u (triggered by %s aura of spell %u)", spellInfo->Id,(isVictim?"a victim's":"an attacker's"), triggeredByAura->GetId());
                    if (!HandleObsModEnergyAuraProc(pTarget, damage, triggeredByAura, procSpell, procFlag, procExtra, cooldown))
                        continue;
                    if (procDebug & 2)
                        sLog.outError("ObsModEnergy aura of spell %d procs twice from one effect!",spellInfo->Id);
                    procDebug |= 2;
                    break;
                case SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN:
                    sLog.outDebug("ProcDamageAndSpell: casting spell id %u (triggered by %s aura of spell %u)", spellInfo->Id,(isVictim?"a victim's":"an attacker's"), triggeredByAura->GetId());
                    if (!HandleModDamagePctTakenAuraProc(pTarget, damage, triggeredByAura, procSpell, procFlag, procExtra, cooldown))
                        continue;
                    if (procDebug & 16)
                        sLog.outError("ModDamagePctTaken aura of spell %d procs twice from one effect!",spellInfo->Id);
                    procDebug |= 16;
                    break;
                case SPELL_AURA_MOD_HASTE:
                {
                    sLog.outDebug("ProcDamageAndSpell: casting spell id %u (triggered by %s haste aura of spell %u)", spellInfo->Id,(isVictim?"a victim's":"an attacker's"), triggeredByAura->GetId());
                    if (!HandleHasteAuraProc(pTarget, damage, triggeredByAura, procSpell, procFlag, procExtra, cooldown))
                        continue;
                    if (procDebug & 4)
                        sLog.outError("Haste aura of spell %d procs twice from one effect!",spellInfo->Id);
                    procDebug |= 4;
                    break;
                }
                case SPELL_AURA_OVERRIDE_CLASS_SCRIPTS:
                {
                    sLog.outDebug("ProcDamageAndSpell: casting spell id %u (triggered by %s aura of spell %u)", spellInfo->Id,(isVictim?"a victim's":"an attacker's"), triggeredByAura->GetId());
                    if (!HandleOverrideClassScriptAuraProc(pTarget, damage, triggeredByAura, procSpell, cooldown))
                        continue;
                    if (procDebug & 8)
                        sLog.outError("OverrideClassScripts aura of spell %d procs twice from one effect!",spellInfo->Id);
                    procDebug |= 8;
                    break;
                }
                case SPELL_AURA_RAID_PROC_FROM_CHARGE_WITH_VALUE:
                {
                    sLog.outDebug("ProcDamageAndSpell: casting mending (triggered by %s dummy aura of spell %u)",
                        (isVictim?"a victim's":"an attacker's"),triggeredByAura->GetId());

                    HandleAuraRaidProcFromChargeWithValue(triggeredByAura);
                    break;
                }
                case SPELL_AURA_RAID_PROC_FROM_CHARGE:
                {
                    sLog.outDebug("ProcDamageAndSpell: casting mending (triggered by %s dummy aura of spell %u)",
                        (isVictim?"a victim's":"an attacker's"),triggeredByAura->GetId());

                    HandleAuraRaidProcFromCharge(triggeredByAura);
                    break;
                }
                case SPELL_AURA_PROC_TRIGGER_SPELL_WITH_VALUE:
                {
                    sLog.outDebug("ProcDamageAndSpell: casting spell %u (triggered with value by %s aura of spell %u)", spellInfo->Id,(isVictim?"a victim's":"an attacker's"), triggeredByAura->GetId());

                    if (!HandleProcTriggerSpell(pTarget, damage, triggeredByAura, procSpell, procFlag, procExtra, cooldown))
                        continue;
                    break;
                }
                case SPELL_AURA_MOD_CASTING_SPEED_NOT_STACK:
                    // Skip melee hits or instant cast spells
                    if (procSpell == NULL || GetSpellCastTime(procSpell) == 0)
                        continue;
                    break;
                case SPELL_AURA_REFLECT_SPELLS_SCHOOL:
                    // Skip Melee hits and spells ws wrong school
                    if (procSpell == NULL || (triggeredByAura->GetMiscValue() & procSpell->SchoolMask) == 0)
                        continue;
                    break;
                case SPELL_AURA_MOD_POWER_COST_SCHOOL_PCT:
                case SPELL_AURA_MOD_POWER_COST_SCHOOL:
                    // Skip melee hits and spells ws wrong school or zero cost
                    if (procSpell == NULL ||
                        (procSpell->manaCost == 0 && procSpell->ManaCostPercentage == 0) || // Cost check
                        (triggeredByAura->GetMiscValue() & procSpell->SchoolMask) == 0)         // School check
                        continue;
                    break;
                case SPELL_AURA_MECHANIC_IMMUNITY:
                    // Compare mechanic
                    if (procSpell==NULL || procSpell->Mechanic != triggeredByAura->GetMiscValue())
                        continue;
                    break;
                case SPELL_AURA_MOD_MECHANIC_RESISTANCE:
                    // Compare mechanic
                    if (procSpell==NULL || procSpell->Mechanic != triggeredByAura->GetMiscValue())
                        continue;
                    break;
                case SPELL_AURA_MOD_DAMAGE_FROM_CASTER:
                    // Compare casters
                    if (triggeredByAura->GetCasterGUID() != pTarget->GetGUID())
                        continue;
                    break;
                default:
                    // nothing do, just charges counter
                    break;
            }
            takeCharges=true;
        }
        // Remove charge (aura can be removed by triggers)
        if(useCharges && takeCharges)
        {
            i->aura->DropAuraCharge();
        }
    }
}

SpellSchoolMask Unit::GetMeleeDamageSchoolMask() const
{
    return SPELL_SCHOOL_MASK_NORMAL;
}

Player* Unit::GetSpellModOwner() const
{
    if(GetTypeId()==TYPEID_PLAYER)
        return (Player*)this;
    if(((Creature*)this)->isPet() || ((Creature*)this)->isTotem())
    {
        Unit* owner = GetOwner();
        if(owner && owner->GetTypeId()==TYPEID_PLAYER)
            return (Player*)owner;
    }
    return NULL;
}

///----------Pet responses methods-----------------
void Unit::SendPetCastFail(uint32 spellid, SpellCastResult msg)
{
    if(msg == SPELL_CAST_OK)
        return;

    Unit *owner = GetCharmerOrOwner();
    if(!owner || owner->GetTypeId() != TYPEID_PLAYER)
        return;

    WorldPacket data(SMSG_PET_CAST_FAILED, (4+1));
    data << uint8(0);                                       // cast count?
    data << uint32(spellid);
    data << uint8(msg);
    // uint32 for some reason
    // uint32 for some reason
    ((Player*)owner)->GetSession()->SendPacket(&data);
}

void Unit::SendPetActionFeedback (uint8 msg)
{
    Unit* owner = GetOwner();
    if(!owner || owner->GetTypeId() != TYPEID_PLAYER)
        return;

    WorldPacket data(SMSG_PET_ACTION_FEEDBACK, 1);
    data << uint8(msg);
    ((Player*)owner)->GetSession()->SendPacket(&data);
}

void Unit::SendPetTalk (uint32 pettalk)
{
    Unit* owner = GetOwner();
    if(!owner || owner->GetTypeId() != TYPEID_PLAYER)
        return;

    WorldPacket data(SMSG_PET_ACTION_SOUND, 8+4);
    data << uint64(GetGUID());
    data << uint32(pettalk);
    ((Player*)owner)->GetSession()->SendPacket(&data);
}

void Unit::SendPetSpellCooldown (uint32 spellid, time_t cooltime)
{
    Unit* owner = GetOwner();
    if(!owner || owner->GetTypeId() != TYPEID_PLAYER)
        return;

    WorldPacket data(SMSG_SPELL_COOLDOWN, 8+1+4+4);
    data << uint64(GetGUID());
    data << uint8(0x0);                                     // flags (0x1, 0x2)
    data << uint32(spellid);
    data << uint32(cooltime);

    ((Player*)owner)->GetSession()->SendPacket(&data);
}

void Unit::SendPetClearCooldown (uint32 spellid)
{
    Unit* owner = GetOwner();
    if(!owner || owner->GetTypeId() != TYPEID_PLAYER)
        return;

    WorldPacket data(SMSG_CLEAR_COOLDOWN, (4+8));
    data << uint32(spellid);
    data << uint64(GetGUID());
    ((Player*)owner)->GetSession()->SendPacket(&data);
}

void Unit::SendPetAIReaction(uint64 guid)
{
    Unit* owner = GetOwner();
    if(!owner || owner->GetTypeId() != TYPEID_PLAYER)
        return;

    WorldPacket data(SMSG_AI_REACTION, 12);
    data << uint64(guid) << uint32(00000002);
    ((Player*)owner)->GetSession()->SendPacket(&data);
}

///----------End of Pet responses methods----------

void Unit::StopMoving()
{
    clearUnitState(UNIT_STAT_MOVING);

    // send explicit stop packet
    // rely on vmaps here because for example stormwind is in air
    //float z = MapManager::Instance().GetBaseMap(GetMapId())->GetHeight(GetPositionX(), GetPositionY(), GetPositionZ(), true);
    //if (fabs(GetPositionZ() - z) < 2.0f)
    //    Relocate(GetPositionX(), GetPositionY(), z);
    Relocate(GetPositionX(), GetPositionY(),GetPositionZ());

    SendMonsterStop();

    // update position and orientation;
    WorldPacket data;
    BuildHeartBeatMsg(&data);
    SendMessageToSet(&data,false);
}

/*
void Unit::SetFeared(bool apply, uint64 casterGUID, uint32 spellID)
{
    if( apply )
    {
        if(HasAuraType(SPELL_AURA_PREVENTS_FLEEING))
            return;

        SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_FLEEING);

        GetMotionMaster()->MovementExpired(false);
        CastStop(GetGUID()==casterGUID ? spellID : 0);

        Unit* caster = ObjectAccessor::GetUnit(*this,casterGUID);

        GetMotionMaster()->MoveFleeing(caster);             // caster==NULL processed in MoveFleeing
    }
    else
    {
        RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_FLEEING);

        GetMotionMaster()->MovementExpired(false);

        if( GetTypeId() != TYPEID_PLAYER && isAlive() )
        {
            // restore appropriate movement generator
            if(getVictim())
                GetMotionMaster()->MoveChase(getVictim());
            else
                GetMotionMaster()->Initialize();

            // attack caster if can
            Unit* caster = ObjectAccessor::GetObjectInWorld(casterGUID, (Unit*)NULL);
            if(caster && ((Creature*)this)->AI())
                ((Creature*)this)->AI()->AttackedBy(caster);
        }
    }

    if (GetTypeId() == TYPEID_PLAYER)
        ((Player*)this)->SetClientControl(this, !apply);
}

void Unit::SetConfused(bool apply, uint64 casterGUID, uint32 spellID)
{
    if( apply )
    {
        SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_CONFUSED);

        CastStop(GetGUID()==casterGUID ? spellID : 0);

        GetMotionMaster()->MoveConfused();
    }
    else
    {
        RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_CONFUSED);

        GetMotionMaster()->MovementExpired(false);

        if (GetTypeId() == TYPEID_UNIT)
        {
            // if in combat restore movement generator
            if(getVictim())
                GetMotionMaster()->MoveChase(getVictim());
        }
    }

    if(GetTypeId() == TYPEID_PLAYER)
        ((Player*)this)->SetClientControl(this, !apply);
}
*/

bool Unit::IsSitState() const
{
    uint8 s = getStandState();
    return
        s == UNIT_STAND_STATE_SIT_CHAIR        || s == UNIT_STAND_STATE_SIT_LOW_CHAIR  ||
        s == UNIT_STAND_STATE_SIT_MEDIUM_CHAIR || s == UNIT_STAND_STATE_SIT_HIGH_CHAIR ||
        s == UNIT_STAND_STATE_SIT;
}

bool Unit::IsStandState() const
{
    uint8 s = getStandState();
    return !IsSitState() && s != UNIT_STAND_STATE_SLEEP && s != UNIT_STAND_STATE_KNEEL;
}

void Unit::SetStandState(uint8 state)
{
    SetByteValue(UNIT_FIELD_BYTES_1, 0, state);

    if (IsStandState())
       RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_NOT_SEATED);

    if(GetTypeId()==TYPEID_PLAYER)
    {
        WorldPacket data(SMSG_STANDSTATE_UPDATE, 1);
        data << (uint8)state;
        ((Player*)this)->GetSession()->SendPacket(&data);
    }
}

bool Unit::IsPolymorphed() const
{
    return GetSpellSpecific(getTransForm())==SPELL_MAGE_POLYMORPH;
}

void Unit::SetDisplayId(uint32 modelId)
{
    SetUInt32Value(UNIT_FIELD_DISPLAYID, modelId);

    if(GetTypeId() == TYPEID_UNIT && ((Creature*)this)->isPet())
    {
        Pet *pet = ((Pet*)this);
        if(!pet->isControlled())
            return;
        Unit *owner = GetOwner();
        if(owner && (owner->GetTypeId() == TYPEID_PLAYER) && ((Player*)owner)->GetGroup())
            ((Player*)owner)->SetGroupUpdateFlag(GROUP_UPDATE_FLAG_PET_MODEL_ID);
    }
}

void Unit::ClearComboPointHolders()
{
    while(!m_ComboPointHolders.empty())
    {
        uint32 lowguid = *m_ComboPointHolders.begin();

        Player* plr = objmgr.GetPlayer(MAKE_NEW_GUID(lowguid, 0, HIGHGUID_PLAYER));
        if(plr && plr->GetComboTarget()==GetGUID())         // recheck for safe
            plr->ClearComboPoints();                        // remove also guid from m_ComboPointHolders;
        else
            m_ComboPointHolders.erase(lowguid);             // or remove manually
    }
}

void Unit::ClearAllReactives()
{
    for(int i=0; i < MAX_REACTIVE; ++i)
        m_reactiveTimer[i] = 0;

    if (HasAuraState( AURA_STATE_DEFENSE))
        ModifyAuraState(AURA_STATE_DEFENSE, false);
    if (getClass() == CLASS_HUNTER && HasAuraState( AURA_STATE_HUNTER_PARRY))
        ModifyAuraState(AURA_STATE_HUNTER_PARRY, false);
    if(getClass() == CLASS_WARRIOR && GetTypeId() == TYPEID_PLAYER)
        ((Player*)this)->ClearComboPoints();
}

void Unit::UpdateReactives( uint32 p_time )
{
    for(int i = 0; i < MAX_REACTIVE; ++i)
    {
        ReactiveType reactive = ReactiveType(i);

        if(!m_reactiveTimer[reactive])
            continue;

        if ( m_reactiveTimer[reactive] <= p_time)
        {
            m_reactiveTimer[reactive] = 0;

            switch ( reactive )
            {
                case REACTIVE_DEFENSE:
                    if (HasAuraState(AURA_STATE_DEFENSE))
                        ModifyAuraState(AURA_STATE_DEFENSE, false);
                    break;
                case REACTIVE_HUNTER_PARRY:
                    if ( getClass() == CLASS_HUNTER && HasAuraState(AURA_STATE_HUNTER_PARRY))
                        ModifyAuraState(AURA_STATE_HUNTER_PARRY, false);
                    break;
                case REACTIVE_OVERPOWER:
                    if(getClass() == CLASS_WARRIOR && GetTypeId() == TYPEID_PLAYER)
                        ((Player*)this)->ClearComboPoints();
                    break;
                default:
                    break;
            }
        }
        else
        {
            m_reactiveTimer[reactive] -= p_time;
        }
    }
}

Unit* Unit::SelectNearbyTarget(float dist) const
{
    std::list<Unit *> targets;
    Trinity::AnyUnfriendlyUnitInObjectRangeCheck u_check(this, this, dist);
    Trinity::UnitListSearcher<Trinity::AnyUnfriendlyUnitInObjectRangeCheck> searcher(this, targets, u_check);
    VisitNearbyObject(dist, searcher);

    // remove current target
    if(getVictim())
        targets.remove(getVictim());

    // remove not LoS targets
    for(std::list<Unit *>::iterator tIter = targets.begin(); tIter != targets.end();)
    {
        if(!IsWithinLOSInMap(*tIter))
        {
            std::list<Unit *>::iterator tIter2 = tIter;
            ++tIter;
            targets.erase(tIter2);
        }
        else
            ++tIter;
    }

    // no appropriate targets
    if(targets.empty())
        return NULL;

    // select random
    uint32 rIdx = urand(0,targets.size()-1);
    std::list<Unit *>::const_iterator tcIter = targets.begin();
    for(uint32 i = 0; i < rIdx; ++i)
        ++tcIter;

    return *tcIter;
}

bool Unit::hasNegativeAuraWithInterruptFlag(uint32 flag)
{
    for (AuraMap::iterator iter = m_Auras.begin(); iter != m_Auras.end(); ++iter)
    {
        if (!iter->second->IsPositive() && iter->second->GetSpellProto()->AuraInterruptFlags & flag)
            return true;
    }
    return false;
}

void Unit::ApplyAttackTimePercentMod( WeaponAttackType att,float val, bool apply )
{
    float remainingTimePct = (float)m_attackTimer[att] / (GetAttackTime(att) * m_modAttackSpeedPct[att]);
    if(val > 0)
    {
        ApplyPercentModFloatVar(m_modAttackSpeedPct[att], val, !apply);
        ApplyPercentModFloatValue(UNIT_FIELD_BASEATTACKTIME+att,val,!apply);
    }
    else
    {
        ApplyPercentModFloatVar(m_modAttackSpeedPct[att], -val, apply);
        ApplyPercentModFloatValue(UNIT_FIELD_BASEATTACKTIME+att,-val,apply);
    }
    m_attackTimer[att] = uint32(GetAttackTime(att) * m_modAttackSpeedPct[att] * remainingTimePct);
}

void Unit::ApplyCastTimePercentMod(float val, bool apply )
{
    if(val > 0)
        ApplyPercentModFloatValue(UNIT_MOD_CAST_SPEED,val,!apply);
    else
        ApplyPercentModFloatValue(UNIT_MOD_CAST_SPEED,-val,apply);
}

uint32 Unit::GetCastingTimeForBonus( SpellEntry const *spellProto, DamageEffectType damagetype, uint32 CastingTime )
{
    // Not apply this to creature casted spells with casttime==0
    if(CastingTime==0 && GetTypeId()==TYPEID_UNIT && !((Creature*)this)->isPet())
        return 3500;

    if (CastingTime > 7000) CastingTime = 7000;
    if (CastingTime < 1500) CastingTime = 1500;

    if(damagetype == DOT && !IsChanneledSpell(spellProto))
        CastingTime = 3500;

    int32 overTime    = 0;
    uint8 effects     = 0;
    bool DirectDamage = false;
    bool AreaEffect   = false;

    for ( uint32 i=0; i<3;i++)
    {
        switch ( spellProto->Effect[i] )
        {
            case SPELL_EFFECT_SCHOOL_DAMAGE:
            case SPELL_EFFECT_POWER_DRAIN:
            case SPELL_EFFECT_HEALTH_LEECH:
            case SPELL_EFFECT_ENVIRONMENTAL_DAMAGE:
            case SPELL_EFFECT_POWER_BURN:
            case SPELL_EFFECT_HEAL:
                DirectDamage = true;
                break;
            case SPELL_EFFECT_APPLY_AURA:
                switch ( spellProto->EffectApplyAuraName[i] )
                {
                    case SPELL_AURA_PERIODIC_DAMAGE:
                    case SPELL_AURA_PERIODIC_HEAL:
                    case SPELL_AURA_PERIODIC_LEECH:
                        if ( GetSpellDuration(spellProto) )
                            overTime = GetSpellDuration(spellProto);
                        break;
                    default:
                        // -5% per additional effect
                        ++effects;
                        break;
                }
            default:
                break;
        }

        if(IsAreaEffectTarget[spellProto->EffectImplicitTargetA[i]] || IsAreaEffectTarget[spellProto->EffectImplicitTargetB[i]])
            AreaEffect = true;
    }

    // Combined Spells with Both Over Time and Direct Damage
    if ( overTime > 0 && CastingTime > 0 && DirectDamage )
    {
        // mainly for DoTs which are 3500 here otherwise
        uint32 OriginalCastTime = GetSpellCastTime(spellProto);
        if (OriginalCastTime > 7000) OriginalCastTime = 7000;
        if (OriginalCastTime < 1500) OriginalCastTime = 1500;
        // Portion to Over Time
        float PtOT = (overTime / 15000.f) / ((overTime / 15000.f) + (OriginalCastTime / 3500.f));

        if ( damagetype == DOT )
            CastingTime = uint32(CastingTime * PtOT);
        else if ( PtOT < 1.0f )
            CastingTime  = uint32(CastingTime * (1 - PtOT));
        else
            CastingTime = 0;
    }

    // Area Effect Spells receive only half of bonus
    if ( AreaEffect )
        CastingTime /= 2;

    // -5% of total per any additional effect
    for ( uint8 i=0; i<effects; ++i)
    {
        if ( CastingTime > 175 )
        {
            CastingTime -= 175;
        }
        else
        {
            CastingTime = 0;
            break;
        }
    }

    return CastingTime;
}

void Unit::UpdateAuraForGroup(uint8 slot)
{
    if(slot >= MAX_AURAS)                        // slot not found, return
        return;
    if(GetTypeId() == TYPEID_PLAYER)
    {
        Player* player = (Player*)this;
        if(player->GetGroup())
        {
            player->SetGroupUpdateFlag(GROUP_UPDATE_FLAG_AURAS);
            player->SetAuraUpdateMaskForRaid(slot);
        }
    }
    else if(GetTypeId() == TYPEID_UNIT && ((Creature*)this)->isPet())
    {
        Pet *pet = ((Pet*)this);
        if(pet->isControlled())
        {
            Unit *owner = GetOwner();
            if(owner && (owner->GetTypeId() == TYPEID_PLAYER) && ((Player*)owner)->GetGroup())
            {
                ((Player*)owner)->SetGroupUpdateFlag(GROUP_UPDATE_FLAG_PET_AURAS);
                pet->SetAuraUpdateMaskForRaid(slot);
            }
        }
    }
}

float Unit::GetAPMultiplier(WeaponAttackType attType, bool normalized)
{
    if (!normalized || GetTypeId() != TYPEID_PLAYER)
        return float(GetAttackTime(attType))/1000.0f;

    Item *Weapon = ((Player*)this)->GetWeaponForAttack(attType);
    if (!Weapon)
        return 2.4;                                         // fist attack

    switch (Weapon->GetProto()->InventoryType)
    {
        case INVTYPE_2HWEAPON:
            return 3.3;
        case INVTYPE_RANGED:
        case INVTYPE_RANGEDRIGHT:
        case INVTYPE_THROWN:
            return 2.8;
        case INVTYPE_WEAPON:
        case INVTYPE_WEAPONMAINHAND:
        case INVTYPE_WEAPONOFFHAND:
        default:
            return Weapon->GetProto()->SubClass==ITEM_SUBCLASS_WEAPON_DAGGER ? 1.7 : 2.4;
    }
}

AuraEffect* Unit::GetDummyAura( uint32 spell_id ) const
{
    Unit::AuraEffectList const& mDummy = GetAurasByType(SPELL_AURA_DUMMY);
    for(Unit::AuraEffectList::const_iterator itr = mDummy.begin(); itr != mDummy.end(); ++itr)
        if ((*itr)->GetId() == spell_id)
            return *itr;

    return NULL;
}

bool Unit::IsUnderLastManaUseEffect() const
{
    return  getMSTimeDiff(m_lastManaUse,getMSTime()) < 5000;
}

void Unit::SetContestedPvP(Player *attackedPlayer)
{
    Player* player = GetCharmerOrOwnerPlayerOrPlayerItself();

    if(!player || attackedPlayer && (attackedPlayer == player || player->duel && player->duel->opponent == attackedPlayer))
        return;

    player->SetContestedPvPTimer(30000);
    if(!player->hasUnitState(UNIT_STAT_ATTACK_PLAYER))
    {
        player->addUnitState(UNIT_STAT_ATTACK_PLAYER);
        player->SetFlag(PLAYER_FLAGS, PLAYER_FLAGS_CONTESTED_PVP);
        // call MoveInLineOfSight for nearby contested guards
        player->SetVisibility(GetVisibility());
    }
    if(!hasUnitState(UNIT_STAT_ATTACK_PLAYER))
    {
        addUnitState(UNIT_STAT_ATTACK_PLAYER);
        // call MoveInLineOfSight for nearby contested guards
        SetVisibility(GetVisibility());
    }
}

void Unit::AddPetAura(PetAura const* petSpell)
{
    if(GetTypeId() != TYPEID_PLAYER)
        return;

    m_petAuras.insert(petSpell);
    if(Pet* pet = ((Player*)this)->GetPet())
        pet->CastPetAura(petSpell);
}

void Unit::RemovePetAura(PetAura const* petSpell)
{
    if(GetTypeId() != TYPEID_PLAYER)
        return;

    m_petAuras.erase(petSpell);
    if(Pet* pet = ((Player*)this)->GetPet())
        pet->RemoveAurasDueToSpell(petSpell->GetAura(pet->GetEntry()));
}

Pet* Unit::CreateTamedPetFrom(Creature* creatureTarget,uint32 spell_id)
{
    if(GetTypeId()!=TYPEID_PLAYER)
        return NULL;

    Pet* pet = new Pet((Player*)this, HUNTER_PET);

    if(!pet->CreateBaseAtCreature(creatureTarget))
    {
        delete pet;
        return NULL;
    }

    pet->SetCreatorGUID(GetGUID());
    pet->SetUInt32Value(UNIT_FIELD_FACTIONTEMPLATE, getFaction());
    pet->SetUInt32Value(UNIT_CREATED_BY_SPELL, spell_id);

    if(GetTypeId()==TYPEID_PLAYER)
        pet->SetUInt32Value(UNIT_FIELD_FLAGS, UNIT_FLAG_PVP_ATTACKABLE);

    uint32 level = (creatureTarget->getLevel() < (getLevel() - 5)) ? (getLevel() - 5) : creatureTarget->getLevel();

    if(!pet->InitStatsForLevel(level))
    {
        sLog.outError("Pet::InitStatsForLevel() failed for creature (Entry: %u)!",creatureTarget->GetEntry());
        delete pet;
        return NULL;
    }

    pet->GetCharmInfo()->SetPetNumber(objmgr.GeneratePetNumber(), true);
    // this enables pet details window (Shift+P)
    pet->InitPetCreateSpells();
    pet->InitTalentForLevel();
    pet->SetHealth(pet->GetMaxHealth());

    return pet;
}

bool Unit::IsTriggeredAtSpellProcEvent(Unit *pVictim, Aura * aura, SpellEntry const* procSpell, uint32 procFlag, uint32 procExtra, WeaponAttackType attType, bool isVictim, bool active, SpellProcEventEntry const *& spellProcEvent )
{
    SpellEntry const* spellProto = aura->GetSpellProto ();

    // Get proc Event Entry
    spellProcEvent = spellmgr.GetSpellProcEvent(spellProto->Id);

    // Get EventProcFlag
    uint32 EventProcFlag;
    if (spellProcEvent && spellProcEvent->procFlags) // if exist get custom spellProcEvent->procFlags
        EventProcFlag = spellProcEvent->procFlags;
    else
        EventProcFlag = spellProto->procFlags;       // else get from spell proto
    // Continue if no trigger exist
    if (!EventProcFlag)
        return false;

    // Additional checks for triggered spells
    if (procExtra & PROC_EX_INTERNAL_TRIGGERED)
    {
        if (!(spellProto->AttributesEx3 & SPELL_ATTR_EX3_CAN_PROC_TRIGGERED))
            return false;
    }

    // Check spellProcEvent data requirements
    if(!spellmgr.IsSpellProcEventCanTriggeredBy(spellProcEvent, EventProcFlag, procSpell, procFlag, procExtra, active))
        return false;
    // In most cases req get honor or XP from kill
    if (EventProcFlag & PROC_FLAG_KILL && GetTypeId() == TYPEID_PLAYER)
    {
        bool allow = ((Player*)this)->isHonorOrXPTarget(pVictim);
        // Shadow Word: Death - can trigger from every kill
        if (aura->GetId() == 32409)
            allow = true;
        if (!allow)
            return false;
    }
    // Aura added by spell can`t trogger from self (prevent drop charges/do triggers)
    // But except periodic triggers (can triggered from self)
    if(procSpell && procSpell->Id == spellProto->Id && !(spellProto->procFlags&PROC_FLAG_ON_TAKE_PERIODIC))
        return false;

    // Check if current equipment allows aura to proc
    if(!isVictim && GetTypeId() == TYPEID_PLAYER)
    {
        if(spellProto->EquippedItemClass == ITEM_CLASS_WEAPON)
        {
            Item *item = NULL;
            if(attType == BASE_ATTACK)
                item = ((Player*)this)->GetUseableItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);
            else if (attType == OFF_ATTACK)
                item = ((Player*)this)->GetUseableItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND);
            else
                item = ((Player*)this)->GetUseableItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_RANGED);

            if (((Player*)this)->IsInFeralForm())
                return false;

            if(!item || item->IsBroken() || item->GetProto()->Class != ITEM_CLASS_WEAPON || !((1<<item->GetProto()->SubClass) & spellProto->EquippedItemSubClassMask))
                return false;
        }
        else if(spellProto->EquippedItemClass == ITEM_CLASS_ARMOR)
        {
            // Check if player is wearing shield
            Item *item = ((Player*)this)->GetUseableItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND);
            if(!item || item->IsBroken() || item->GetProto()->Class != ITEM_CLASS_ARMOR || !((1<<item->GetProto()->SubClass) & spellProto->EquippedItemSubClassMask))
                return false;
        }
    }
    // Get chance from spell
    float chance = (float)spellProto->procChance;
    // If in spellProcEvent exist custom chance, chance = spellProcEvent->customChance;
    if(spellProcEvent && spellProcEvent->customChance)
        chance = spellProcEvent->customChance;
    // If PPM exist calculate chance from PPM
    if(!isVictim && spellProcEvent && spellProcEvent->ppmRate != 0)
    {
        uint32 WeaponSpeed = GetAttackTime(attType);
        chance = GetPPMProcChance(WeaponSpeed, spellProcEvent->ppmRate, spellProto);
    }
    // Apply chance modifer aura
    if(Player* modOwner = GetSpellModOwner())
    {
        modOwner->ApplySpellMod(spellProto->Id,SPELLMOD_CHANCE_OF_SUCCESS,chance);
    }

    return roll_chance_f(chance);
}

bool Unit::HandleAuraRaidProcFromChargeWithValue( AuraEffect* triggeredByAura )
{
    // aura can be deleted at casts
    SpellEntry const* spellProto = triggeredByAura->GetSpellProto();
    uint32 effIdx = triggeredByAura->GetEffIndex();
    int32 heal = triggeredByAura->GetAmount();
    uint64 caster_guid = triggeredByAura->GetCasterGUID();

    //Currently only Prayer Of Mending
    if (!(spellProto->SpellFamilyName==SPELLFAMILY_PRIEST && spellProto->SpellFamilyFlags[1] & 0x20))
    {
        sLog.outDebug("Unit::HandleAuraRaidProcFromChargeWithValue, received not handled spell: %u", spellProto->Id);
        return false;
    }
    // jumps
    int32 jumps = triggeredByAura->GetParentAura()->GetAuraCharges()-1;

    // current aura expire
    triggeredByAura->GetParentAura()->SetAuraCharges(1);             // will removed at next charges decrease

    // next target selection
    if(jumps > 0 && IS_PLAYER_GUID(caster_guid))
    {
        float radius;
        if (spellProto->EffectRadiusIndex[effIdx])
            radius = GetSpellRadiusForTarget(triggeredByAura->GetCaster(), sSpellRadiusStore.LookupEntry(spellProto->EffectRadiusIndex[effIdx]));
        else
            radius = GetSpellMaxRangeForTarget(triggeredByAura->GetCaster() ,sSpellRangeStore.LookupEntry(spellProto->rangeIndex));

        if(Player* caster = ((Player*)triggeredByAura->GetCaster()))
        {
            caster->ApplySpellMod(spellProto->Id, SPELLMOD_RADIUS, radius,NULL);

            if (Unit* target= GetNextRandomRaidMemberOrPet(radius))
            {
                CastCustomSpell(target,spellProto->Id,&heal,NULL,NULL,true,NULL,triggeredByAura,caster->GetGUID());
                if (Aura * aur = target->GetAura(spellProto->Id, caster->GetGUID()))
                    aur->SetAuraCharges(jumps);

                //bonus must be applied after aura cast on target
                heal = caster->SpellHealingBonus(this, spellProto, heal, HEAL);
            }
        }
    }

    // heal
    CastCustomSpell(this,33110,&heal,NULL,NULL,true,NULL,NULL,caster_guid);
    return true;
}
bool Unit::HandleAuraRaidProcFromCharge( AuraEffect* triggeredByAura )
{
    // aura can be deleted at casts
    SpellEntry const* spellProto = triggeredByAura->GetSpellProto();

    uint32 damageSpellId;
    switch(spellProto->Id)
    {
    case 57949:            //shiver
        damageSpellId=57952;
//       animationSpellId=57951; dummy effects for jump spell have unknown use (see also 41637)
        break;
    case 59978:            //shiver
        damageSpellId=59979;
        break;
    case 43593:            //Cold Stare
        damageSpellId=43594;
        break;
    default:
        sLog.outDebug("Unit::HandleAuraRaidProcFromCharge, received not handled spell: %u", spellProto->Id);
        return false;
    }

    uint64 caster_guid = triggeredByAura->GetCasterGUID();
    uint32 effIdx = triggeredByAura->GetEffIndex();

    // jumps
    int32 jumps = triggeredByAura->GetParentAura()->GetAuraCharges()-1;

    // current aura expire
    triggeredByAura->GetParentAura()->SetAuraCharges(1);             // will removed at next charges decrease

    // next target selection
    if(jumps > 0 && IS_PLAYER_GUID(caster_guid))
    {
        float radius;
        if (spellProto->EffectRadiusIndex[effIdx])
            radius = GetSpellRadiusForTarget(triggeredByAura->GetCaster(), sSpellRadiusStore.LookupEntry(spellProto->EffectRadiusIndex[effIdx]));
        else
            radius = GetSpellMaxRangeForTarget(triggeredByAura->GetCaster() ,sSpellRangeStore.LookupEntry(spellProto->rangeIndex));

        if(Player* caster = ((Player*)triggeredByAura->GetCaster()))
        {
            caster->ApplySpellMod(spellProto->Id, SPELLMOD_RADIUS, radius,NULL);

            if (Unit* target= GetNextRandomRaidMemberOrPet(radius))
            {
                CastSpell(target, spellProto, true,NULL,triggeredByAura,caster_guid);
                if (Aura * aur = target->GetAura(spellProto->Id, caster->GetGUID()))
                    aur->SetAuraCharges(jumps);
            }
        }
    }

    CastSpell(this, damageSpellId, true,NULL,triggeredByAura,caster_guid);

    return true;
}
/*-----------------------TRINITY-----------------------------*/

void Unit::SetToNotify()
{
    if(m_IsInNotifyList)
        return;

    if(Map *map = GetMap())
        map->AddUnitToNotify(this);
}

void Unit::Kill(Unit *pVictim, bool durabilityLoss)
{
    // Prevent killing unit twice (and giving reward from kill twice)
    if (!pVictim->isAlive())
        return;
    pVictim->SetHealth(0);

    // find player: owner of controlled `this` or `this` itself maybe
    Player *player = GetCharmerOrOwnerPlayerOrPlayerItself();

    if(pVictim->GetTypeId() == TYPEID_UNIT && ((Creature*)pVictim)->GetLootRecipient())
        player = ((Creature*)pVictim)->GetLootRecipient();
    // Reward player, his pets, and group/raid members
    // call kill spell proc event (before real die and combat stop to triggering auras removed at death/combat stop)
    if(player && player!=pVictim)
    {
        if(player->RewardPlayerAndGroupAtKill(pVictim))
            player->ProcDamageAndSpell(pVictim, PROC_FLAG_KILL, PROC_FLAG_KILLED, PROC_EX_NONE, 0);
        else
            player->ProcDamageAndSpell(pVictim, PROC_FLAG_NONE, PROC_FLAG_KILLED,PROC_EX_NONE, 0);
    }

    // if talent known but not triggered (check priest class for speedup check)
    bool SpiritOfRedemption = false;
    if(pVictim->GetTypeId()==TYPEID_PLAYER && pVictim->getClass()==CLASS_PRIEST )
    {
        AuraEffectList const& vDummyAuras = pVictim->GetAurasByType(SPELL_AURA_DUMMY);
        for(AuraEffectList::const_iterator itr = vDummyAuras.begin(); itr != vDummyAuras.end(); ++itr)
        {
            if((*itr)->GetSpellProto()->SpellIconID==1654)
            {
                // save value before aura remove
                uint32 ressSpellId = pVictim->GetUInt32Value(PLAYER_SELF_RES_SPELL);
                if(!ressSpellId)
                    ressSpellId = ((Player*)pVictim)->GetResurrectionSpellId();
                //Remove all expected to remove at death auras (most important negative case like DoT or periodic triggers)
                pVictim->RemoveAllAurasOnDeath();
                // restore for use at real death
                pVictim->SetUInt32Value(PLAYER_SELF_RES_SPELL,ressSpellId);

                // FORM_SPIRITOFREDEMPTION and related auras
                pVictim->CastSpell(pVictim,27827,true,NULL,*itr);
                SpiritOfRedemption = true;
                break;
            }
        }
    }

    if(!SpiritOfRedemption)
    {
        DEBUG_LOG("SET JUST_DIED");
        pVictim->setDeathState(JUST_DIED);
    }

    // 10% durability loss on death
    // clean InHateListOf
    if (pVictim->GetTypeId() == TYPEID_PLAYER)
    {
        // remember victim PvP death for corpse type and corpse reclaim delay
        // at original death (not at SpiritOfRedemtionTalent timeout)
        ((Player*)pVictim)->SetPvPDeath(player!=NULL);

        // only if not player and not controlled by player pet. And not at BG
        if (durabilityLoss && !player && !((Player*)pVictim)->InBattleGround())
        {
            DEBUG_LOG("We are dead, loosing 10 percents durability");
            ((Player*)pVictim)->DurabilityLossAll(0.10f,false);
            // durability lost message
            WorldPacket data(SMSG_DURABILITY_DAMAGE_DEATH, 0);
            ((Player*)pVictim)->GetSession()->SendPacket(&data);
        }
        // Call KilledUnit for creatures
        if (GetTypeId() == TYPEID_UNIT && ((Creature*)this)->IsAIEnabled)
            ((Creature*)this)->AI()->KilledUnit(pVictim);

        // last damage from non duel opponent or opponent controlled creature
        if(((Player*)pVictim)->duel)
        {
            ((Player*)pVictim)->duel->opponent->CombatStopWithPets(true);
            ((Player*)pVictim)->CombatStopWithPets(true);
            ((Player*)pVictim)->DuelComplete(DUEL_INTERUPTED);
        }
    }
    else                                                // creature died
    {
        DEBUG_LOG("DealDamageNotPlayer");
        Creature *cVictim = (Creature*)pVictim;

        if(!cVictim->isPet())
        {
            cVictim->DeleteThreatList();
            cVictim->SetFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_LOOTABLE);
        }

        // Call KilledUnit for creatures, this needs to be called after the lootable flag is set
        if (GetTypeId() == TYPEID_UNIT && ((Creature*)this)->IsAIEnabled)
            ((Creature*)this)->AI()->KilledUnit(pVictim);

        // Call creature just died function
        if (cVictim->IsAIEnabled)
            cVictim->AI()->JustDied(this);

        // Dungeon specific stuff, only applies to players killing creatures
        if(cVictim->GetInstanceId())
        {
            Map *m = cVictim->GetMap();
            Player *creditedPlayer = GetCharmerOrOwnerPlayerOrPlayerItself();
            // TODO: do instance binding anyway if the charmer/owner is offline

            if(m->IsDungeon() && creditedPlayer)
            {
                if(m->IsRaid() || m->IsHeroic())
                {
                    if(cVictim->GetCreatureInfo()->flags_extra & CREATURE_FLAG_EXTRA_INSTANCE_BIND)
                        ((InstanceMap *)m)->PermBindAllPlayers(creditedPlayer);
                }
                else
                {
                    // the reset time is set but not added to the scheduler
                    // until the players leave the instance
                    time_t resettime = cVictim->GetRespawnTimeEx() + 2 * HOUR;
                    if(InstanceSave *save = sInstanceSaveManager.GetInstanceSave(cVictim->GetInstanceId()))
                        if(save->GetResetTime() < resettime) save->SetResetTime(resettime);
                }
            }
        }
    }

    // outdoor pvp things, do these after setting the death state, else the player activity notify won't work... doh...
    // handle player kill only if not suicide (spirit of redemption for example)
    if(player && this != pVictim)
        if(OutdoorPvP * pvp = player->GetOutdoorPvP())
            pvp->HandleKill(player, pVictim);

    if(pVictim->GetTypeId() == TYPEID_PLAYER)
        if(OutdoorPvP * pvp = ((Player*)pVictim)->GetOutdoorPvP())
            pvp->HandlePlayerActivityChanged((Player*)pVictim);

    // battleground things (do this at the end, so the death state flag will be properly set to handle in the bg->handlekill)
    if(player && player->InBattleGround())
    {
        if(BattleGround *bg = player->GetBattleGround())
        {
            if(pVictim->GetTypeId() == TYPEID_PLAYER)
                bg->HandleKillPlayer((Player*)pVictim, player);
            else
                bg->HandleKillUnit((Creature*)pVictim, player);
        }
    }

    // achievement stuff
    if (pVictim->GetTypeId() == TYPEID_PLAYER)
    {
        if (GetTypeId() == TYPEID_UNIT)
            ((Player*)pVictim)->GetAchievementMgr().UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_KILLED_BY_CREATURE, GetEntry());
        else if(GetTypeId() == TYPEID_PLAYER && pVictim != this)
            ((Player*)pVictim)->GetAchievementMgr().UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_KILLED_BY_PLAYER, 1, ((Player*)this)->GetTeam());
    }
}

void Unit::SetControlled(bool apply, UnitState state)
{
    if(apply)
    {
        if(hasUnitState(state))
            return;

        addUnitState(state);

        switch(state)
        {
        case UNIT_STAT_STUNNED:
            SetStunned(true);
            break;
        case UNIT_STAT_ROOT:
            if(!hasUnitState(UNIT_STAT_STUNNED))
                SetRooted(true);
            break;
        case UNIT_STAT_CONFUSED:
            if(!hasUnitState(UNIT_STAT_STUNNED))
                SetConfused(true);
            break;
        case UNIT_STAT_FLEEING:
            if(!hasUnitState(UNIT_STAT_STUNNED | UNIT_STAT_CONFUSED))
                SetFeared(true);
            break;
        default:
            break;
        }
    }
    else
    {
        switch(state)
        {
            case UNIT_STAT_STUNNED: if(HasAuraType(SPELL_AURA_MOD_STUN))    return;
                                    else    SetStunned(false);    break;
            case UNIT_STAT_ROOT:    if(HasAuraType(SPELL_AURA_MOD_ROOT))    return;
                                    else    SetRooted(false);     break;
            case UNIT_STAT_CONFUSED:if(HasAuraType(SPELL_AURA_MOD_CONFUSE)) return;
                                    else    SetConfused(false);   break;
            case UNIT_STAT_FLEEING: if(HasAuraType(SPELL_AURA_MOD_FEAR))    return;
                                    else    SetFeared(false);     break;
            default: return;
        }

        clearUnitState(state);

        if(hasUnitState(UNIT_STAT_STUNNED))
            SetStunned(true);
        else
        {
            if(hasUnitState(UNIT_STAT_ROOT))
                SetRooted(true);

            if(hasUnitState(UNIT_STAT_CONFUSED))
                SetConfused(true);
            else if(hasUnitState(UNIT_STAT_FLEEING))
                SetFeared(true);
        }
    }
}

void Unit::SetStunned(bool apply)
{
    if(apply)
    {
        SetUInt64Value(UNIT_FIELD_TARGET, 0);
        SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED);
        CastStop();

        // Creature specific
        if(GetTypeId() != TYPEID_PLAYER)
            ((Creature*)this)->StopMoving();
        else
            SetUnitMovementFlags(0);    //Clear movement flags

        WorldPacket data(SMSG_FORCE_MOVE_ROOT, 8);
        data.append(GetPackGUID());
        data << uint32(0);
        SendMessageToSet(&data,true);
    }
    else
    {
        if(isAlive() && getVictim())
            SetUInt64Value(UNIT_FIELD_TARGET, getVictim()->GetGUID());
        RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED);

        if(!hasUnitState(UNIT_STAT_ROOT))         // prevent allow move if have also root effect
        {
            WorldPacket data(SMSG_FORCE_MOVE_UNROOT, 8+4);
            data.append(GetPackGUID());
            data << uint32(0);
            SendMessageToSet(&data,true);
        }
    }
}

void Unit::SetRooted(bool apply)
{
    uint32 apply_stat = UNIT_STAT_ROOT;
    if(apply)
    {
        SetFlag(UNIT_FIELD_FLAGS,(apply_stat<<16)); // probably wrong

        if(GetTypeId() == TYPEID_PLAYER)
        {
            SetUnitMovementFlags(0);

            WorldPacket data(SMSG_FORCE_MOVE_ROOT, 10);
            data.append(GetPackGUID());
            data << (uint32)2;
            SendMessageToSet(&data,true);
        }
        else
            ((Creature *)this)->StopMoving();
    }
    else
    {
        RemoveFlag(UNIT_FIELD_FLAGS,(apply_stat<<16)); // probably wrong

        if(!hasUnitState(UNIT_STAT_STUNNED))      // prevent allow move if have also stun effect
        {
            if(GetTypeId() == TYPEID_PLAYER)
            {
                WorldPacket data(SMSG_FORCE_MOVE_UNROOT, 10);
                data.append(GetPackGUID());
                data << (uint32)2;
                SendMessageToSet(&data,true);
            }
        }
    }
}

void Unit::SetFeared(bool apply)
{
    if(apply)
    {
        Unit *caster = NULL;
        Unit::AuraEffectList const& fearAuras = GetAurasByType(SPELL_AURA_MOD_FEAR);
        if(!fearAuras.empty())
            caster = ObjectAccessor::GetUnit(*this, fearAuras.front()->GetCasterGUID());
        if(!caster)
            caster = getAttackerForHelper();
        GetMotionMaster()->MoveFleeing(caster);             // caster==NULL processed in MoveFleeing
    }
    else
    {
        if(isAlive() && GetMotionMaster()->GetCurrentMovementGeneratorType() == FLEEING_MOTION_TYPE)
            GetMotionMaster()->MovementExpired();
    }

    if (GetTypeId() == TYPEID_PLAYER)
        ((Player*)this)->SetClientControl(this, !apply);
}

void Unit::SetConfused(bool apply)
{
    if(apply)
    {
        GetMotionMaster()->MoveConfused();
    }
    else
    {
        if(isAlive() && GetMotionMaster()->GetCurrentMovementGeneratorType() == CONFUSED_MOTION_TYPE)
            GetMotionMaster()->MovementExpired();
    }

    if(GetTypeId() == TYPEID_PLAYER)
        ((Player*)this)->SetClientControl(this, !apply);
}

void Unit::SetCharmedOrPossessedBy(Unit* charmer, bool possess)
{
    if(!charmer)
        return;

    assert(!possess || charmer->GetTypeId() == TYPEID_PLAYER);

    if(this == charmer)
        return;

    if(hasUnitState(UNIT_STAT_UNATTACKABLE))
        return;

    if(GetTypeId() == TYPEID_PLAYER && ((Player*)this)->GetTransport())
        return;

    RemoveUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
    CastStop();
    CombatStop(); //TODO: CombatStop(true) may cause crash (interrupt spells)
    DeleteThreatList();

    // Charmer stop charming
    if(charmer->GetTypeId() == TYPEID_PLAYER)
    {
        ((Player*)charmer)->StopCastingCharm();
        ((Player*)charmer)->StopCastingBindSight();
    }

    // Charmed stop charming
    if(GetTypeId() == TYPEID_PLAYER)
    {
        ((Player*)this)->StopCastingCharm();
        ((Player*)this)->StopCastingBindSight();
    }

    // StopCastingCharm may remove a possessed pet?
    if(!IsInWorld())
        return;

    // Set charmed
    setFaction(charmer->getFaction());
    SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PVP_ATTACKABLE);
    charmer->SetCharm(this, true);

    if(GetTypeId() == TYPEID_UNIT)
    {
        ((Creature*)this)->AI()->OnCharmed(true);
        GetMotionMaster()->Clear(false);
        GetMotionMaster()->MoveIdle();
    }
    else
    {
        if(((Player*)this)->isAFK())
            ((Player*)this)->ToggleAFK();
        ((Player*)this)->SetClientControl(this, 0);
    }

    // Pets already have a properly initialized CharmInfo, don't overwrite it.
    if(GetTypeId() == TYPEID_PLAYER || GetTypeId() == TYPEID_UNIT
        && !((Creature*)this)->HasSummonMask(SUMMON_MASK_GUARDIAN))
    {
        CharmInfo *charmInfo = InitCharmInfo();
        if(possess)
            charmInfo->InitPossessCreateSpells();
        else
            charmInfo->InitCharmCreateSpells();
    }

    //Set possessed
    if(possess)
    {
        addUnitState(UNIT_STAT_POSSESSED);
        SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_UNK_24);
        ((Player*)charmer)->SetClientControl(this, 1);
        ((Player*)charmer)->SetViewpoint(this, true);
        charmer->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
    }
    // Charm demon
    else if(GetTypeId() == TYPEID_UNIT && charmer->GetTypeId() == TYPEID_PLAYER && charmer->getClass() == CLASS_WARLOCK)
    {
        CreatureInfo const *cinfo = ((Creature*)this)->GetCreatureInfo();
        if(cinfo && cinfo->type == CREATURE_TYPE_DEMON)
        {
            //to prevent client crash
            SetFlag(UNIT_FIELD_BYTES_0, 2048);

            //just to enable stat window
            if(GetCharmInfo())
                GetCharmInfo()->SetPetNumber(objmgr.GeneratePetNumber(), true);

            //if charmed two demons the same session, the 2nd gets the 1st one's name
            SetUInt32Value(UNIT_FIELD_PET_NAME_TIMESTAMP, time(NULL));
        }
    }

    if(possess)
        ((Player*)charmer)->PossessSpellInitialize();
    else if(charmer->GetTypeId() == TYPEID_PLAYER)
        ((Player*)charmer)->CharmSpellInitialize();
}

void Unit::RemoveCharmedOrPossessedBy(Unit *charmer)
{
    if(!isCharmed())
        return;

    if(!charmer)
        charmer = GetCharmer();
    else if(charmer != GetCharmer()) // one aura overrides another?
        return;

    bool possess = hasUnitState(UNIT_STAT_POSSESSED);

    CastStop();
    CombatStop(); //TODO: CombatStop(true) may cause crash (interrupt spells)
    getHostilRefManager().deleteReferences();
    DeleteThreatList();
    RestoreFaction();
    GetMotionMaster()->InitDefault();

    if(possess)
    {
        clearUnitState(UNIT_STAT_POSSESSED);
        RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_UNK_24);
    }

    if(GetTypeId() == TYPEID_UNIT)
    {
        if(!((Creature*)this)->isPet())
            RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PVP_ATTACKABLE);

        ((Creature*)this)->AI()->OnCharmed(false);
        if(isAlive() && ((Creature*)this)->IsAIEnabled)
        {
            if(charmer && !IsFriendlyTo(charmer))
            {
                ((Creature*)this)->AddThreat(charmer, 10000.0f);
                ((Creature*)this)->AI()->AttackStart(charmer);
            }
            else
                ((Creature*)this)->AI()->EnterEvadeMode();
        }
    }
    else
        ((Player*)this)->SetClientControl(this, 1);

    // If charmer still exists
    if(!charmer)
        return;

    assert(!possess || charmer->GetTypeId() == TYPEID_PLAYER);

    charmer->SetCharm(this, false);
    if(possess)
    {
        ((Player*)charmer)->SetClientControl(charmer, 1);
        ((Player*)charmer)->SetViewpoint(this, false);
        charmer->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
    }
    // restore UNIT_FIELD_BYTES_0
    else if(GetTypeId() == TYPEID_UNIT && charmer->GetTypeId() == TYPEID_PLAYER && charmer->getClass() == CLASS_WARLOCK)
    {
        CreatureInfo const *cinfo = ((Creature*)this)->GetCreatureInfo();
        if(cinfo && cinfo->type == CREATURE_TYPE_DEMON)
        {
            CreatureDataAddon const *cainfo = ((Creature*)this)->GetCreatureAddon();
            if(cainfo && cainfo->bytes0 != 0)
                SetUInt32Value(UNIT_FIELD_BYTES_0, cainfo->bytes0);
            else
                RemoveFlag(UNIT_FIELD_BYTES_0, 2048);

            if(GetCharmInfo())
                GetCharmInfo()->SetPetNumber(0, true);
            else
                sLog.outError("Aura::HandleModCharm: target="I64FMTD" with typeid=%d has a charm aura but no charm info!", GetGUID(), GetTypeId());
        }
    }

    //a guardian should always have charminfo
    if(GetTypeId() == TYPEID_PLAYER || GetTypeId() == TYPEID_UNIT
        && !((Creature*)this)->HasSummonMask(SUMMON_MASK_GUARDIAN))
    {
        DeleteCharmInfo();
    }

    if(possess || charmer->GetTypeId() == TYPEID_PLAYER)
    {
        // Remove pet spell action bar
        WorldPacket data(SMSG_PET_SPELLS, 8);
        data << uint64(0);
        ((Player*)charmer)->GetSession()->SendPacket(&data);
    }
}

void Unit::RestoreFaction()
{
    if(GetTypeId() == TYPEID_PLAYER)
        ((Player*)this)->setFactionForRace(getRace());
    else
    {
        CreatureInfo const *cinfo = ((Creature*)this)->GetCreatureInfo();

        if(((Creature*)this)->isPet())
        {
            if(Unit* owner = GetOwner())
                setFaction(owner->getFaction());
            else if(cinfo)
                setFaction(cinfo->faction_A);
        }
        else if(cinfo)  // normal creature
            setFaction(cinfo->faction_A);
    }
}

bool Unit::IsInPartyWith(Unit const *unit) const
{
    if(this == unit)
        return true;

    const Unit *u1 = GetCharmerOrOwnerOrSelf();
    const Unit *u2 = unit->GetCharmerOrOwnerOrSelf();
    if(u1 == u2)
        return true;

    if(u1->GetTypeId() == TYPEID_PLAYER && u2->GetTypeId() == TYPEID_PLAYER)
        return ((Player*)u1)->IsInSameGroupWith((Player*)u2);
    else
        return false;
}

bool Unit::IsInRaidWith(Unit const *unit) const
{
    if(this == unit)
        return true;

    const Unit *u1 = GetCharmerOrOwnerOrSelf();
    const Unit *u2 = unit->GetCharmerOrOwnerOrSelf();
    if(u1 == u2)
        return true;

    if(u1->GetTypeId() == TYPEID_PLAYER && u2->GetTypeId() == TYPEID_PLAYER)
        return ((Player*)u1)->IsInSameRaidWith((Player*)u2);
    else
        return false;
}

void Unit::GetRaidMember(std::list<Unit*> &nearMembers, float radius)
{
    Player *owner = GetCharmerOrOwnerPlayerOrPlayerItself();
    if(!owner)
        return;

    Group *pGroup = owner->GetGroup();
    if(pGroup)
    {
        for(GroupReference *itr = pGroup->GetFirstMember(); itr != NULL; itr = itr->next())
        {
            Player* Target = itr->getSource();

            if( Target && !IsHostileTo(Target) )
            {
                if(Target->isAlive() && IsWithinDistInMap(Target, radius) )
                    nearMembers.push_back(Target);

                if(Guardian* pet = Target->GetGuardianPet())
                    if(pet->isAlive() &&  IsWithinDistInMap(pet, radius) )
                        nearMembers.push_back(pet);
            }
        }
    }
    else
    {
        if(owner->isAlive() && (owner == this || IsWithinDistInMap(owner, radius)))
            nearMembers.push_back(owner);
        if(Guardian* pet = owner->GetGuardianPet())
            if(pet->isAlive() && (pet == this && IsWithinDistInMap(pet, radius)))
                nearMembers.push_back(pet);
    }
}

void Unit::GetPartyMember(std::list<Unit*> &TagUnitMap, float radius)
{
    Unit *owner = GetCharmerOrOwnerOrSelf();
    Group *pGroup = NULL;
    if (owner->GetTypeId() == TYPEID_PLAYER)
        pGroup = ((Player*)owner)->GetGroup();

    if(pGroup)
    {
        uint8 subgroup = ((Player*)owner)->GetSubGroup();

        for(GroupReference *itr = pGroup->GetFirstMember(); itr != NULL; itr = itr->next())
        {
            Player* Target = itr->getSource();

            // IsHostileTo check duel and controlled by enemy
            if( Target && Target->GetSubGroup()==subgroup && !IsHostileTo(Target) )
            {
                if(Target->isAlive() && IsWithinDistInMap(Target, radius) )
                    TagUnitMap.push_back(Target);

                if(Guardian* pet = Target->GetGuardianPet())
                    if(pet->isAlive() &&  IsWithinDistInMap(pet, radius) )
                        TagUnitMap.push_back(pet);
            }
        }
    }
    else
    {
        if(owner->isAlive() && (owner == this || IsWithinDistInMap(owner, radius)))
            TagUnitMap.push_back(owner);
        if(Guardian* pet = owner->GetGuardianPet())
            if(pet->isAlive() && (pet == this && IsWithinDistInMap(pet, radius)))
                TagUnitMap.push_back(pet);
    }
}

void Unit::HandleAuraEffect(AuraEffect * aureff, bool apply)
{
    if (aureff->GetParentAura()->IsRemoved())
        return;
    if (apply)
    {
        m_modAuras[aureff->GetAuraName()].push_back(aureff);
        aureff->ApplyModifier(true, true);
    }
    else
    {
        // remove from list before mods removing (prevent cyclic calls, mods added before including to aura list - use reverse order)
        m_modAuras[aureff->GetAuraName()].remove(aureff);
        aureff->ApplyModifier(false, true);
        Unit * caster = aureff->GetParentAura()->GetCaster();
        if(caster && aureff->IsPersistent())
        {
            DynamicObject *dynObj = caster->GetDynObject(aureff->GetId(), aureff->GetEffIndex());
            if (dynObj)
                dynObj->RemoveAffected(this);
        }
        // Remove all triggered by aura spells vs unlimited duration
        aureff->CleanupTriggeredSpells();
    }
}

void Unit::AddAura(uint32 spellId, Unit* target)
{
    if(!target || !target->isAlive())
        return;

    SpellEntry const *spellInfo = sSpellStore.LookupEntry(spellId);
    if(!spellInfo)
        return;

    if (target->IsImmunedToSpell(spellInfo))
        return;

    uint8 eff_mask=0;

    for(uint32 i = 0; i < 3; ++i)
    {
        if(spellInfo->Effect[i] == SPELL_EFFECT_APPLY_AURA || IsAreaAuraEffect(spellInfo->Effect[i]))
        {
            if(target->IsImmunedToSpellEffect(spellInfo, i))
                continue;
            eff_mask|=1<<i;
        }
    }

    if (!eff_mask)
        return;

    Aura *Aur = new Aura(spellInfo, eff_mask, NULL, target, this);
    target->AddAura(Aur);
}

Aura * Unit::AddAuraEffect(uint32 spellId, uint8 effIndex, Unit* caster)
{
    SpellEntry const *spellInfo = sSpellStore.LookupEntry(spellId);
    if(!spellInfo || !caster)
        return NULL;

    // can't do that for passive auras - they stack from same caster so there is no way to get exact aura which should get effect
    //assert (!IsPassiveSpell(spellInfo));

    Aura * aur = GetAura(spellId, caster->GetGUID());

    if (aur)
    {
        AuraEffect *aurEffect = CreateAuraEffect(aur, effIndex, NULL, caster);
        if (!aurEffect)
            return aur;
        if (!aur->SetPartAura(aurEffect, effIndex))
            delete aurEffect;
    }
    else
    {
        aur = new Aura(spellInfo, 1<<effIndex, NULL, this ,caster);
        AddAura(aur);
    }
    return aur;
}

// Melee based spells can be miss, parry or dodge on this step
// Crit or block - determined on damage calculation phase! (and can be both in some time)
float Unit::MeleeSpellMissChance(const Unit *pVictim, WeaponAttackType attType, int32 skillDiff, uint32 spellId) const
{
    // Calculate hit chance (more correct for chance mod)
    int32 HitChance;

    // PvP - PvE melee chances
    /*int32 lchance = pVictim->GetTypeId() == TYPEID_PLAYER ? 5 : 7;
    int32 leveldif = pVictim->getLevelForTarget(this) - getLevelForTarget(pVictim);
    if(leveldif < 3)
        HitChance = 95 - leveldif;
    else
        HitChance = 93 - (leveldif - 2) * lchance;*/
    if (spellId || attType == RANGED_ATTACK || !haveOffhandWeapon())
        HitChance = 95.0f;
    else
        HitChance = 76.0f;

    // Hit chance depends from victim auras
    if(attType == RANGED_ATTACK)
        HitChance += pVictim->GetTotalAuraModifier(SPELL_AURA_MOD_ATTACKER_RANGED_HIT_CHANCE);
    else
        HitChance += pVictim->GetTotalAuraModifier(SPELL_AURA_MOD_ATTACKER_MELEE_HIT_CHANCE);

    // Spellmod from SPELLMOD_RESIST_MISS_CHANCE
    if(spellId)
    {
        if(Player *modOwner = GetSpellModOwner())
            modOwner->ApplySpellMod(spellId, SPELLMOD_RESIST_MISS_CHANCE, HitChance);
    }

    // Miss = 100 - hit
    float miss_chance= 100.0f - HitChance;

    // Bonuses from attacker aura and ratings
    if (attType == RANGED_ATTACK)
        miss_chance -= m_modRangedHitChance;
    else
        miss_chance -= m_modMeleeHitChance;

    // bonus from skills is 0.04%
    //miss_chance -= skillDiff * 0.04f;
    int32 diff = -skillDiff;
    if(pVictim->GetTypeId()==TYPEID_PLAYER)
        miss_chance += diff > 0 ? diff * 0.04 : diff * 0.02;
    else
        miss_chance += diff > 10 ? 2 + (diff - 10) * 0.4 : diff * 0.1;

    // Limit miss chance from 0 to 60%
    if (miss_chance < 0.0f)
        return 0.0f;
    if (miss_chance > 60.0f)
        return 60.0f;
    return miss_chance;
}

void Unit::SetPhaseMask(uint32 newPhaseMask, bool update)
{
    WorldObject::SetPhaseMask(newPhaseMask,update);

    if(!IsInWorld())
        return;

    for(ControlList::const_iterator itr = m_Controlled.begin(); itr != m_Controlled.end(); ++itr)
        if((*itr)->GetOwnerGUID() == GetGUID())
            (*itr)->SetPhaseMask(newPhaseMask,true);

    for(int8 i = 0; i < MAX_SUMMON_SLOT; ++i)
        if(m_SummonSlot[i])
            if(Creature *summon = GetMap()->GetCreature(m_SummonSlot[i]))
                summon->SetPhaseMask(newPhaseMask,true);
}

void Unit::KnockbackFrom(float x, float y, float speedXY, float speedZ)
{
    if(GetTypeId() == TYPEID_UNIT)
    {
        GetMotionMaster()->MoveKnockbackFrom(x, y, speedXY, speedZ);
    }
    else
    {
        float vcos, vsin;
        GetSinCos(x, y, vsin, vcos);

        WorldPacket data(SMSG_MOVE_KNOCK_BACK, (8+4+4+4+4+4));
        data.append(GetPackGUID());
        data << uint32(0);                                      // Sequence
        data << float(vcos);                                    // x direction
        data << float(vsin);                                    // y direction
        data << float(speedXY);                                 // Horizontal speed
        data << float(-speedZ);                                 // Z Movement speed (vertical)

        ((Player*)this)->GetSession()->SendPacket(&data);
    }
}

void Unit::JumpTo(float speedXY, float speedZ, bool forward)
{
    float angle = forward ? 0 : M_PI;
    if(GetTypeId() == TYPEID_UNIT)
    {
        GetMotionMaster()->MoveJumpTo(angle, speedXY, speedZ);
    }
    else
    {
        float vcos = cos(angle+GetOrientation());
        float vsin = sin(angle+GetOrientation());

        WorldPacket data(SMSG_MOVE_KNOCK_BACK, (8+4+4+4+4+4));
        data.append(GetPackGUID());
        data << uint32(0);                                      // Sequence
        data << float(vcos);                                    // x direction
        data << float(vsin);                                    // y direction
        data << float(speedXY);                                 // Horizontal speed
        data << float(-speedZ);                                 // Z Movement speed (vertical)

        ((Player*)this)->GetSession()->SendPacket(&data);
    }
}

void Unit::JumpTo(WorldObject *obj, float speedZ)
{
    float x, y, z;
    obj->GetContactPoint(this, x, y, z);
    float speedXY = GetExactDistance2d(x, y) * 10.0f / speedZ;
    GetMotionMaster()->MoveJump(x, y, z, speedXY, speedZ);
}

void Unit::EnterVehicle(Vehicle *vehicle, int8 seatId)
{
    if(m_Vehicle)
    {
        if(m_Vehicle == vehicle)
        {
            if(seatId >= 0)
                ChangeSeat(seatId);
            return;
        }
        else
            ExitVehicle();
    }

    if(GetTypeId() == TYPEID_PLAYER)
    {
        ((Player*)this)->StopCastingCharm();
        ((Player*)this)->StopCastingBindSight();
    }

    assert(!m_Vehicle);
    m_Vehicle = vehicle;
    if(!m_Vehicle->AddPassenger(this, seatId))
    {
        m_Vehicle = NULL;
        return;
    }

    m_Vehicle->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_UNK_24);
    m_Vehicle->setFaction(getFaction());

    addUnitState(UNIT_STAT_ONVEHICLE);
    //movementInfo is set in AddPassenger
    //packets are sent in AddPassenger

    if(GetTypeId() == TYPEID_PLAYER)
    {
        ((Player*)this)->SetClientControl(vehicle, 1);
        WorldPacket data(SMSG_ON_CANCEL_EXPECTED_RIDE_VEHICLE_AURA, 0);
        ((Player*)this)->GetSession()->SendPacket(&data);
    }
}

void Unit::ChangeSeat(int8 seatId, bool next)
{
    if(!m_Vehicle)
        return;

    if(seatId < 0)
    {
        seatId = m_Vehicle->GetNextEmptySeat(GetTransSeat(), next);
        if(seatId < 0)
            return;
    }
    else if(seatId == GetTransSeat() || !m_Vehicle->HasEmptySeat(seatId))
        return;

    m_Vehicle->RemovePassenger(this);
    if(!m_Vehicle->AddPassenger(this, seatId))
        assert(false);
}

void Unit::ExitVehicle()
{
    if(!m_Vehicle)
        return;

    m_Vehicle->RemovePassenger(this);

    m_Vehicle->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_UNK_24);
    //setFaction((GetTeam() == ALLIANCE) ? GetCreatureInfo()->faction_A : GetCreatureInfo()->faction_H);

    clearUnitState(UNIT_STAT_ONVEHICLE);
    RemoveUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT);

    m_movementInfo.t_x = 0;
    m_movementInfo.t_y = 0;
    m_movementInfo.t_z = 0;
    m_movementInfo.t_o = 0;
    m_movementInfo.t_time = 0;
    m_movementInfo.t_seat = 0;

    //Send leave vehicle
    WorldPacket data;
    if(GetTypeId() == TYPEID_PLAYER)
    {
        ((Player*)this)->SetClientControl(this, 1);
        ((Player*)this)->BuildTeleportAckMsg(&data, GetPositionX(), GetPositionY(), GetPositionZ(), GetOrientation());
        ((Player*)this)->GetSession()->SendPacket(&data);
    }

    BuildHeartBeatMsg(&data);
    SendMessageToSet(&data, false);

    if(m_Vehicle->GetOwnerGUID() == GetGUID())
        m_Vehicle->Dismiss();

    m_Vehicle = NULL;
}

void Unit::BuildMovementPacket(ByteBuffer *data) const
{
    // 0x00000200
    if(GetUnitMovementFlags() & MOVEMENTFLAG_ONTRANSPORT)
    {
        if(m_Vehicle)
            *data << (uint64)m_Vehicle->GetGUID();
        else if(GetTransport())
            *data << (uint64)GetTransport()->GetGUID();
        else
            *data << (uint64)0; //This will cause client crash
        *data << float (GetTransOffsetX());
        *data << float (GetTransOffsetY());
        *data << float (GetTransOffsetZ());
        *data << float (GetTransOffsetO());
        *data << uint32(GetTransTime());
        *data << uint8 (GetTransSeat());
    }

    // 0x02200000
    if((GetUnitMovementFlags() & (MOVEMENTFLAG_SWIMMING | MOVEMENTFLAG_FLYING2))
        || (m_movementInfo.unk1 & 0x20))
        *data << (float)m_movementInfo.s_pitch;

    *data << (uint32)m_movementInfo.fallTime;

    // 0x00001000
    if(GetUnitMovementFlags() & MOVEMENTFLAG_JUMPING)
    {
        *data << (float)m_movementInfo.j_zspeed;
        *data << (float)m_movementInfo.j_sinAngle;
        *data << (float)m_movementInfo.j_cosAngle;
        *data << (float)m_movementInfo.j_xyspeed;
    }

    // 0x04000000
    if(GetUnitMovementFlags() & MOVEMENTFLAG_SPLINE)
        *data << (float)m_movementInfo.u_unk1;
}

void Unit::NearTeleportTo( float x, float y, float z, float orientation, bool casting /*= false*/ )
{
    if(GetTypeId() == TYPEID_PLAYER)
        ((Player*)this)->TeleportTo(GetMapId(), x, y, z, orientation, TELE_TO_NOT_LEAVE_TRANSPORT | TELE_TO_NOT_LEAVE_COMBAT | TELE_TO_NOT_UNSUMMON_PET | (casting ? TELE_TO_SPELL : 0));
    else
    {
        WorldPacket data;
        /*data.Initialize(MSG_MOVE_TELEPORT, 30);
        data.append(GetPackGUID());
        data << uint32(GetUnitMovementFlags());
        data << uint16(0);  // Probably walk flags here
        data << getMSTime(); // time
        data << x; // destination coords
        data << y;
        data << z;
        data << orientation;
        data << uint32 (0);
        // Other information here: jumping angle etc
        SendMessageToSet(&data, false);*/

        // FIXME: this interrupts spell visual
        DestroyForNearbyPlayers();

        GetMap()->CreatureRelocation((Creature*)this, x, y, z, orientation);

        //WorldPacket data;
        // Work strange for many spells: triggered active mover set for targeted player to creature
        //BuildTeleportAckMsg(&data, x, y, z, orientation);
        BuildHeartBeatMsg(&data);
        SendMessageToSet(&data, false);
    }
}
