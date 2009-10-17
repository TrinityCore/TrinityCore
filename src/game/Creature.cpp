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
#include "Database/DatabaseEnv.h"
#include "WorldPacket.h"
#include "World.h"
#include "ObjectMgr.h"
#include "SpellMgr.h"
#include "Creature.h"
#include "QuestDef.h"
#include "GossipDef.h"
#include "Player.h"
#include "PoolHandler.h"
#include "Opcodes.h"
#include "Log.h"
#include "LootMgr.h"
#include "MapManager.h"
#include "CreatureAI.h"
#include "CreatureAISelector.h"
#include "Formulas.h"
#include "WaypointMovementGenerator.h"
#include "InstanceData.h"
#include "BattleGroundMgr.h"
#include "Util.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "CellImpl.h"
#include "OutdoorPvPMgr.h"
#include "GameEventMgr.h"
#include "CreatureGroups.h"
#include "Vehicle.h"
// apply implementation of the singletons
#include "Policies/SingletonImp.h"

TrainerSpell const* TrainerSpellData::Find(uint32 spell_id) const
{
    TrainerSpellMap::const_iterator itr = spellList.find(spell_id);
    if (itr != spellList.end())
        return &itr->second;

    return NULL;
}

bool VendorItemData::RemoveItem( uint32 item_id )
{
    for (VendorItemList::iterator i = m_items.begin(); i != m_items.end(); ++i )
    {
        if((*i)->item==item_id)
        {
            m_items.erase(i);
            return true;
        }
    }
    return false;
}

size_t VendorItemData::FindItemSlot(uint32 item_id) const
{
    for (size_t i = 0; i < m_items.size(); ++i )
        if(m_items[i]->item==item_id)
            return i;
    return m_items.size();
}

VendorItem const* VendorItemData::FindItem(uint32 item_id) const
{
    for (VendorItemList::const_iterator i = m_items.begin(); i != m_items.end(); ++i )
        if((*i)->item==item_id)
            return *i;
    return NULL;
}

uint32 CreatureInfo::GetRandomValidModelId() const
{
    uint8 c = 0;
    uint32 modelIDs[4];

    if (Modelid1) modelIDs[c++] = Modelid1;
    if (Modelid2) modelIDs[c++] = Modelid2;
    if (Modelid3) modelIDs[c++] = Modelid3;
    if (Modelid4) modelIDs[c++] = Modelid4;

    return ((c>0) ? modelIDs[urand(0,c-1)] : 0);
}

uint32 CreatureInfo::GetFirstValidModelId() const
{
    if(Modelid1) return Modelid1;
    if(Modelid2) return Modelid2;
    if(Modelid3) return Modelid3;
    if(Modelid4) return Modelid4;
    return 0;
}

bool AssistDelayEvent::Execute(uint64 /*e_time*/, uint32 /*p_time*/)
{
    if(Unit* victim = Unit::GetUnit(m_owner, m_victim))
    {
        while (!m_assistants.empty())
        {
            Creature* assistant = Unit::GetCreature(m_owner, *m_assistants.begin());
            m_assistants.pop_front();

            if (assistant && assistant->CanAssistTo(&m_owner, victim))
            {
                assistant->SetNoCallAssistance(true);
                assistant->CombatStart(victim);
                if(assistant->IsAIEnabled)
                    assistant->AI()->AttackStart(victim);
            }
        }
    }
    return true;
}

Creature::Creature() :
Unit(),
lootForPickPocketed(false), lootForBody(false), m_groupLootTimer(0), lootingGroupLeaderGUID(0),
m_lootMoney(0), m_lootRecipient(0),
m_deathTimer(0), m_respawnTime(0), m_respawnDelay(25), m_corpseDelay(60), m_respawnradius(0.0f),
m_gossipOptionLoaded(false),
m_defaultMovementType(IDLE_MOTION_TYPE), m_DBTableGuid(0), m_equipmentId(0), m_AlreadyCallAssistance(false),
m_regenHealth(true), m_AI_locked(false), m_isDeadByDefault(false), m_meleeDamageSchoolMask(SPELL_SCHOOL_MASK_NORMAL),
m_creatureInfo(NULL), m_reactState(REACT_AGGRESSIVE), m_formation(NULL)
, m_AlreadySearchedAssistance(false)
, m_creatureData(NULL), m_PlayerDamageReq(0)
{
    m_regenTimer = 200;
    m_valuesCount = UNIT_END;

    for (uint8 i =0; i<CREATURE_MAX_SPELLS; ++i)
        m_spells[i] = 0;

    m_CreatureSpellCooldowns.clear();
    m_CreatureCategoryCooldowns.clear();
    m_GlobalCooldown = 0;
    DisableReputationGain = false;
    //m_unit_movement_flags = MONSTER_MOVE_WALK;

    m_SightDistance = sWorld.getConfig(CONFIG_SIGHT_MONSTER);
    m_CombatDistance = 0;//MELEE_RANGE;
}

Creature::~Creature()
{
    m_vendorItemCounts.clear();

    if(i_AI)
    {
        delete i_AI;
        i_AI = NULL;
    }

    //if(m_uint32Values)
    //    sLog.outError("Deconstruct Creature Entry = %u", GetEntry());
}

void Creature::AddToWorld()
{
    ///- Register the creature for guid lookup
    if(!IsInWorld())
    {
        if(m_zoneScript)
            m_zoneScript->OnCreatureCreate(this, true);
        ObjectAccessor::Instance().AddObject(this);
        Unit::AddToWorld();
        SearchFormation();
        AIM_Initialize();
        if(IsVehicle())
            GetVehicleKit()->Install();
    }
}

void Creature::RemoveFromWorld()
{
    if(IsInWorld())
    {
        if(m_zoneScript)
            m_zoneScript->OnCreatureCreate(this, false);
        if(m_formation)
            formation_mgr.RemoveCreatureFromGroup(m_formation, this);
        Unit::RemoveFromWorld();
        ObjectAccessor::Instance().RemoveObject(this);
    }
}

void Creature::DisappearAndDie()
{
    DestroyForNearbyPlayers();
    //SetVisibility(VISIBILITY_OFF);
    //ObjectAccessor::UpdateObjectVisibility(this);
    if(isAlive())
        setDeathState(JUST_DIED);
    RemoveCorpse();
}

void Creature::SearchFormation()
{
    if(isSummon())
        return;

    uint32 lowguid = GetDBTableGUIDLow();
    if(!lowguid)
        return;

    CreatureGroupInfoType::iterator frmdata = CreatureGroupMap.find(lowguid);
    if(frmdata != CreatureGroupMap.end())
        formation_mgr.AddCreatureToGroup(frmdata->second->leaderGUID, this);
}

void Creature::RemoveCorpse()
{
    if ((getDeathState()!=CORPSE && !m_isDeadByDefault) || (getDeathState()!=ALIVE && m_isDeadByDefault))
        return;

    m_deathTimer = 0;
    setDeathState(DEAD);
    ObjectAccessor::UpdateObjectVisibility(this);
    loot.clear();
    uint32 respawnDelay = m_respawnDelay;
    if (AI())
        AI()->CorpseRemoved(respawnDelay);

    m_respawnTime = time(NULL) + m_respawnDelay;

    float x,y,z,o;
    GetRespawnCoord(x, y, z, &o);
    SetHomePosition(x,y,z,o);
    GetMap()->CreatureRelocation(this,x,y,z,o);
}

/**
 * change the entry of creature until respawn
 */
bool Creature::InitEntry(uint32 Entry, uint32 team, const CreatureData *data )
{
    CreatureInfo const *normalInfo = objmgr.GetCreatureTemplate(Entry);
    if(!normalInfo)
    {
        sLog.outErrorDb("Creature::UpdateEntry creature entry %u does not exist.", Entry);
        return false;
    }

    // get heroic mode entry
    uint32 actualEntry = Entry;
    CreatureInfo const *cinfo = normalInfo;
    if(normalInfo->HeroicEntry)
    {
        //we already have valid Map pointer for current creature!
        if(GetMap()->IsHeroic())
        {
            cinfo = objmgr.GetCreatureTemplate(normalInfo->HeroicEntry);
            if(!cinfo)
            {
                sLog.outErrorDb("Creature::UpdateEntry creature heroic entry %u does not exist.", actualEntry);
                return false;
            }
        }
    }

    SetEntry(Entry);                                        // normal entry always
    m_creatureInfo = cinfo;                                 // map mode related always

    // equal to player Race field, but creature does not have race
    SetByteValue(UNIT_FIELD_BYTES_0, 0, 0);

    // known valid are: CLASS_WARRIOR,CLASS_PALADIN,CLASS_ROGUE,CLASS_MAGE
    SetByteValue(UNIT_FIELD_BYTES_0, 1, uint8(cinfo->unit_class));

    // Cancel load if no model defined
    if (!(cinfo->GetFirstValidModelId()))
    {
        sLog.outErrorDb("Creature (Entry: %u) has no model defined in table `creature_template`, can't load. ",Entry);
        return false;
    }

    uint32 display_id = objmgr.ChooseDisplayId(0, GetCreatureInfo(), data);
    CreatureModelInfo const *minfo = objmgr.GetCreatureModelRandomGender(display_id);
    if (!minfo)                                             // Cancel load if no model defined
    {
        sLog.outErrorDb("Creature (Entry: %u) has no model defined in table `creature_template`, can't load. ",Entry);
        return false;
    }

    display_id = minfo->modelid;                            // it can be different (for another gender)

    SetDisplayId(display_id);
    SetNativeDisplayId(display_id);
    SetByteValue(UNIT_FIELD_BYTES_0, 2, minfo->gender);

    // Load creature equipment
    if(!data || data->equipmentId == 0)
    {                                                       // use default from the template
        LoadEquipment(cinfo->equipmentId);
    }
    else if(data && data->equipmentId != -1)
    {                                                       // override, -1 means no equipment
        LoadEquipment(data->equipmentId);
    }

    SetName(normalInfo->Name);                              // at normal entry always

    SetFloatValue(UNIT_FIELD_BOUNDINGRADIUS,minfo->bounding_radius);
    SetFloatValue(UNIT_FIELD_COMBATREACH,minfo->combat_reach );

    SetFloatValue(UNIT_MOD_CAST_SPEED, 1.0f);

    SetSpeed(MOVE_WALK,     cinfo->speed );
    SetSpeed(MOVE_RUN,      cinfo->speed );
    SetSpeed(MOVE_SWIM,     cinfo->speed );

    SetFloatValue(OBJECT_FIELD_SCALE_X, cinfo->scale);

    // checked at loading
    m_defaultMovementType = MovementGeneratorType(cinfo->MovementType);
    if(!m_respawnradius && m_defaultMovementType==RANDOM_MOTION_TYPE)
        m_defaultMovementType = IDLE_MOTION_TYPE;

    for (uint8 i=0; i < CREATURE_MAX_SPELLS; ++i)
        m_spells[i] = GetCreatureInfo()->spells[i];

    return true;
}

bool Creature::UpdateEntry(uint32 Entry, uint32 team, const CreatureData *data )
{
    if(!InitEntry(Entry,team,data))
        return false;

    m_regenHealth = GetCreatureInfo()->RegenHealth;

    // creatures always have melee weapon ready if any
    SetSheath(SHEATH_STATE_MELEE);

    SelectLevel(GetCreatureInfo());
    if (team == HORDE)
        setFaction(GetCreatureInfo()->faction_H);
    else
        setFaction(GetCreatureInfo()->faction_A);

    if(GetCreatureInfo()->flags_extra & CREATURE_FLAG_EXTRA_WORLDEVENT)
        SetUInt32Value(UNIT_NPC_FLAGS,GetCreatureInfo()->npcflag | gameeventmgr.GetNPCFlag(this));
    else
        SetUInt32Value(UNIT_NPC_FLAGS,GetCreatureInfo()->npcflag);

    SetAttackTime(BASE_ATTACK,  GetCreatureInfo()->baseattacktime);
    SetAttackTime(OFF_ATTACK,   GetCreatureInfo()->baseattacktime);
    SetAttackTime(RANGED_ATTACK,GetCreatureInfo()->rangeattacktime);

    SetUInt32Value(UNIT_FIELD_FLAGS,GetCreatureInfo()->unit_flags);
    SetUInt32Value(UNIT_DYNAMIC_FLAGS,GetCreatureInfo()->dynamicflags);

    RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IN_COMBAT);

    SetMeleeDamageSchool(SpellSchools(GetCreatureInfo()->dmgschool));
    SetModifierValue(UNIT_MOD_ARMOR,             BASE_VALUE, float(GetCreatureInfo()->armor));
    SetModifierValue(UNIT_MOD_RESISTANCE_HOLY,   BASE_VALUE, float(GetCreatureInfo()->resistance1));
    SetModifierValue(UNIT_MOD_RESISTANCE_FIRE,   BASE_VALUE, float(GetCreatureInfo()->resistance2));
    SetModifierValue(UNIT_MOD_RESISTANCE_NATURE, BASE_VALUE, float(GetCreatureInfo()->resistance3));
    SetModifierValue(UNIT_MOD_RESISTANCE_FROST,  BASE_VALUE, float(GetCreatureInfo()->resistance4));
    SetModifierValue(UNIT_MOD_RESISTANCE_SHADOW, BASE_VALUE, float(GetCreatureInfo()->resistance5));
    SetModifierValue(UNIT_MOD_RESISTANCE_ARCANE, BASE_VALUE, float(GetCreatureInfo()->resistance6));

    SetCanModifyStats(true);
    UpdateAllStats();

    FactionTemplateEntry const* factionTemplate = sFactionTemplateStore.LookupEntry(GetCreatureInfo()->faction_A);
    if (factionTemplate)                                    // check and error show at loading templates
    {
        FactionEntry const* factionEntry = sFactionStore.LookupEntry(factionTemplate->faction);
        if (factionEntry)
            if( !(GetCreatureInfo()->flags_extra & CREATURE_FLAG_EXTRA_CIVILIAN) &&
                (factionEntry->team == ALLIANCE || factionEntry->team == HORDE) )
                SetPvP(true);
    }

    // HACK: trigger creature is always not selectable
    if(isTrigger())
        SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

    if(isTotem() || isTrigger()
        || GetCreatureType() == CREATURE_TYPE_CRITTER)
        SetReactState(REACT_PASSIVE);
    /*else if(isCivilian())
        SetReactState(REACT_DEFENSIVE);*/
    else
        SetReactState(REACT_AGGRESSIVE);

    if(GetCreatureInfo()->flags_extra & CREATURE_FLAG_EXTRA_NO_TAUNT)
    {
        ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, true);
        ApplySpellImmune(0, IMMUNITY_EFFECT,SPELL_EFFECT_ATTACK_ME, true);
    }

    if(GetCreatureInfo()->InhabitType & INHABIT_AIR)
        AddUnitMovementFlag(MOVEMENTFLAG_FLY_MODE + MOVEMENTFLAG_FLYING);

    return true;
}

void Creature::Update(uint32 diff)
{
    if(m_GlobalCooldown <= diff)
        m_GlobalCooldown = 0;
    else
        m_GlobalCooldown -= diff;

    switch( m_deathState )
    {
        case JUST_ALIVED:
            // Don't must be called, see Creature::setDeathState JUST_ALIVED -> ALIVE promoting.
            sLog.outError("Creature (GUID: %u Entry: %u ) in wrong state: JUST_ALIVED (4)",GetGUIDLow(),GetEntry());
            break;
        case JUST_DIED:
            // Don't must be called, see Creature::setDeathState JUST_DIED -> CORPSE promoting.
            sLog.outError("Creature (GUID: %u Entry: %u ) in wrong state: JUST_DEAD (1)",GetGUIDLow(),GetEntry());
            break;
        case DEAD:
        {
            if( m_respawnTime <= time(NULL) )
            {
                if(!GetLinkedCreatureRespawnTime()) // Can respawn
                    Respawn();
                else // the master is dead
                {
                    if(uint32 targetGuid = objmgr.GetLinkedRespawnGuid(m_DBTableGuid))
                    {
                        if(targetGuid == m_DBTableGuid) // if linking self, never respawn (check delayed to next day)
                            SetRespawnTime(DAY);
                        else
                            m_respawnTime = (time(NULL)>GetLinkedCreatureRespawnTime()? time(NULL):GetLinkedCreatureRespawnTime())+urand(5,MINUTE); // else copy time from master and add a little
                        SaveRespawnTime(); // also save to DB immediately
                    }
                    else
                        Respawn();
                }
            }
            break;
        }
        case CORPSE:
        {
            if (m_isDeadByDefault)
                break;

            if( m_deathTimer <= diff )
            {
                RemoveCorpse();
                DEBUG_LOG("Removing corpse... %u ", GetUInt32Value(OBJECT_FIELD_ENTRY));
            }
            else
            {
                // for delayed spells
                m_Events.Update( diff );

                m_deathTimer -= diff;
                if (m_groupLootTimer && lootingGroupLeaderGUID)
                {
                    if(diff <= m_groupLootTimer)
                    {
                        m_groupLootTimer -= diff;
                    }
                    else
                    {
                        Group* group = objmgr.GetGroupByLeader(lootingGroupLeaderGUID);
                        if (group)
                            group->EndRoll();
                        m_groupLootTimer = 0;
                        lootingGroupLeaderGUID = 0;
                    }
                }
            }

            break;
        }
        case ALIVE:
        {
            if (m_isDeadByDefault)
            {
                if( m_deathTimer <= diff )
                {
                    RemoveCorpse();
                    DEBUG_LOG("Removing alive corpse... %u ", GetUInt32Value(OBJECT_FIELD_ENTRY));
                }
                else
                {
                    m_deathTimer -= diff;
                }
            }

            Unit::Update( diff );

            // creature can be dead after Unit::Update call
            // CORPSE/DEAD state will processed at next tick (in other case death timer will be updated unexpectedly)
            if(!isAlive())
                break;

            // if creature is charmed, switch to charmed AI
            if(NeedChangeAI)
            {
                UpdateCharmAI();
                NeedChangeAI = false;
                IsAIEnabled = true;
            }

            if(!IsInEvadeMode() && IsAIEnabled)
            {
                // do not allow the AI to be changed during update
                m_AI_locked = true;
                i_AI->UpdateAI(diff);
                m_AI_locked = false;
            }

            // creature can be dead after UpdateAI call
            // CORPSE/DEAD state will processed at next tick (in other case death timer will be updated unexpectedly)
            if(!isAlive())
                break;

            if(m_regenTimer > 0)
            {
                if(diff >= m_regenTimer)
                    m_regenTimer = 0;
                else
                    m_regenTimer -= diff;
            }

            if (m_regenTimer != 0)
               break;

            bool bIsPolymorphed = IsPolymorphed();
            bool bInCombat = isInCombat() && (!getVictim() ||                                        // if isInCombat() is true and this has no victim
                             !getVictim()->GetCharmerOrOwnerPlayerOrPlayerItself() ||                // or the victim/owner/charmer is not a player
                             !getVictim()->GetCharmerOrOwnerPlayerOrPlayerItself()->isGameMaster()); // or the victim/owner/charmer is not a GameMaster

            /*if(m_regenTimer <= diff)
            {*/
            if(!bInCombat || bIsPolymorphed) // regenerate health if not in combat or if polymorphed
                RegenerateHealth();

            if(getPowerType() == POWER_ENERGY)
            {
                if(!IsVehicle() || GetVehicleKit()->GetVehicleInfo()->m_powerType != POWER_PYRITE)
                    Regenerate(POWER_ENERGY);
            }
            else
                RegenerateMana();

            /*if(!bIsPolymorphed) // only increase the timer if not polymorphed
                    m_regenTimer += 2000 - diff;
            }
            else
                if(!bIsPolymorphed) // if polymorphed, skip the timer
                    m_regenTimer -= diff;*/
            break;
        }
        case DEAD_FALLING:
            GetMotionMaster()->UpdateMotion(diff);
            break;
        default:
            break;
    }
}

void Creature::RegenerateMana()
{
    uint32 curValue = GetPower(POWER_MANA);
    uint32 maxValue = GetMaxPower(POWER_MANA);

    if (curValue >= maxValue)
        return;

    uint32 addvalue = 0;

    // Combat and any controlled creature
    if (isInCombat() || GetCharmerOrOwnerGUID())
    {
        if(!IsUnderLastManaUseEffect())
        {
            float ManaIncreaseRate = sWorld.getRate(RATE_POWER_MANA);
            float Spirit = GetStat(STAT_SPIRIT);

            addvalue = uint32((Spirit/5.0f + 17.0f) * ManaIncreaseRate);
        }
    }
    else
        addvalue = maxValue/3;

    ModifyPower(POWER_MANA, addvalue);
}

void Creature::RegenerateHealth()
{
    if (!isRegeneratingHealth())
        return;

    uint32 curValue = GetHealth();
    uint32 maxValue = GetMaxHealth();

    if (curValue >= maxValue)
        return;

    uint32 addvalue = 0;

    // Not only pet, but any controlled creature
    if(GetCharmerOrOwnerGUID())
    {
        float HealthIncreaseRate = sWorld.getRate(RATE_HEALTH);
        float Spirit = GetStat(STAT_SPIRIT);

        if( GetPower(POWER_MANA) > 0 )
            addvalue = uint32(Spirit * 0.25 * HealthIncreaseRate);
        else
            addvalue = uint32(Spirit * 0.80 * HealthIncreaseRate);
    }
    else
        addvalue = maxValue/3;

    ModifyHealth(addvalue);
}

void Creature::DoFleeToGetAssistance()
{
    if (!getVictim())
        return;

    if(HasAuraType(SPELL_AURA_PREVENTS_FLEEING))
        return;

    float radius = sWorld.getConfig(CONFIG_CREATURE_FAMILY_FLEE_ASSISTANCE_RADIUS);
    if (radius >0)
    {
        Creature* pCreature = NULL;

        CellPair p(MaNGOS::ComputeCellPair(GetPositionX(), GetPositionY()));
        Cell cell(p);
        cell.data.Part.reserved = ALL_DISTRICT;
        cell.SetNoCreate();
        MaNGOS::NearestAssistCreatureInCreatureRangeCheck u_check(this, getVictim(), radius);
        MaNGOS::CreatureLastSearcher<MaNGOS::NearestAssistCreatureInCreatureRangeCheck> searcher(this, pCreature, u_check);

        TypeContainerVisitor<MaNGOS::CreatureLastSearcher<MaNGOS::NearestAssistCreatureInCreatureRangeCheck>, GridTypeMapContainer > grid_creature_searcher(searcher);

        CellLock<GridReadGuard> cell_lock(cell, p);
        cell_lock->Visit(cell_lock, grid_creature_searcher, *GetMap(), *this, radius);

        SetNoSearchAssistance(true);
        if(!pCreature)
            //SetFeared(true, getVictim()->GetGUID(), 0 ,sWorld.getConfig(CONFIG_CREATURE_FAMILY_FLEE_DELAY));
            //TODO: use 31365
            SetControlled(true, UNIT_STAT_FLEEING);
        else
            GetMotionMaster()->MoveSeekAssistance(pCreature->GetPositionX(), pCreature->GetPositionY(), pCreature->GetPositionZ());
    }
}

bool Creature::AIM_Initialize(CreatureAI* ai)
{
    // make sure nothing can change the AI during AI update
    if(m_AI_locked)
    {
        sLog.outDebug("AIM_Initialize: failed to init, locked.");
        return false;
    }

    UnitAI *oldAI = i_AI;

    Motion_Initialize();

    i_AI = ai ? ai : FactorySelector::selectAI(this);
    if(oldAI) delete oldAI;
    IsAIEnabled = true;
    i_AI->InitializeAI();
    return true;
}

void Creature::Motion_Initialize()
{
    if(!m_formation)
        i_motionMaster.Initialize();
    else if(m_formation->getLeader() == this)
    {
        m_formation->FormationReset(false);
        i_motionMaster.Initialize();
    }
    else if(m_formation->isFormed())
        i_motionMaster.MoveIdle(MOTION_SLOT_IDLE); //wait the order of leader
    else
        i_motionMaster.Initialize();
}

bool Creature::Create(uint32 guidlow, Map *map, uint32 phaseMask, uint32 Entry, uint32 vehId, uint32 team, float x, float y, float z, float ang, const CreatureData *data)
{
    ASSERT(map);
    SetMap(map);
    SetPhaseMask(phaseMask,false);

    Relocate(x, y, z, ang);

    if(!IsPositionValid())
    {
        sLog.outError("Creature (guidlow %d, entry %d) not loaded. Suggested coordinates isn't valid (X: %f Y: %f)",guidlow,Entry,x,y);
        return false;
    }

    //oX = x;     oY = y;    dX = x;    dY = y;    m_moveTime = 0;    m_startMove = 0;
    const bool bResult = CreateFromProto(guidlow, Entry, vehId, team, data);

    if (bResult)
    {
        switch (GetCreatureInfo()->rank)
        {
            case CREATURE_ELITE_RARE:
                m_corpseDelay = sWorld.getConfig(CONFIG_CORPSE_DECAY_RARE);
                break;
            case CREATURE_ELITE_ELITE:
                m_corpseDelay = sWorld.getConfig(CONFIG_CORPSE_DECAY_ELITE);
                break;
            case CREATURE_ELITE_RAREELITE:
                m_corpseDelay = sWorld.getConfig(CONFIG_CORPSE_DECAY_RAREELITE);
                break;
            case CREATURE_ELITE_WORLDBOSS:
                m_corpseDelay = sWorld.getConfig(CONFIG_CORPSE_DECAY_WORLDBOSS);
                break;
            default:
                m_corpseDelay = sWorld.getConfig(CONFIG_CORPSE_DECAY_NORMAL);
                break;
        }
        LoadCreaturesAddon();
        CreatureModelInfo const *minfo = objmgr.GetCreatureModelRandomGender(GetNativeDisplayId());
        if (minfo && !isTotem())                               // Cancel load if no model defined or if totem
        {
            uint32 display_id = minfo->modelid;                // it can be different (for another gender)

            SetDisplayId(display_id);
            SetNativeDisplayId(display_id);
            SetByteValue(UNIT_FIELD_BYTES_0, 2, minfo->gender);
        }
    }
    return bResult;
}

bool Creature::isCanTrainingOf(Player* pPlayer, bool msg) const
{
    if(!isTrainer())
        return false;

    TrainerSpellData const* trainer_spells = GetTrainerSpells();

    if(!trainer_spells || trainer_spells->spellList.empty())
    {
        sLog.outErrorDb("Creature %u (Entry: %u) have UNIT_NPC_FLAG_TRAINER but have empty trainer spell list.",
            GetGUIDLow(),GetEntry());
        return false;
    }

    switch(GetCreatureInfo()->trainer_type)
    {
        case TRAINER_TYPE_CLASS:
            if(pPlayer->getClass()!=GetCreatureInfo()->trainer_class)
            {
                if(msg)
                {
                    pPlayer->PlayerTalkClass->ClearMenus();
                    switch(GetCreatureInfo()->trainer_class)
                    {
                        case CLASS_DRUID:  pPlayer->PlayerTalkClass->SendGossipMenu( 4913,GetGUID()); break;
                        case CLASS_HUNTER: pPlayer->PlayerTalkClass->SendGossipMenu(10090,GetGUID()); break;
                        case CLASS_MAGE:   pPlayer->PlayerTalkClass->SendGossipMenu(  328,GetGUID()); break;
                        case CLASS_PALADIN:pPlayer->PlayerTalkClass->SendGossipMenu( 1635,GetGUID()); break;
                        case CLASS_PRIEST: pPlayer->PlayerTalkClass->SendGossipMenu( 4436,GetGUID()); break;
                        case CLASS_ROGUE:  pPlayer->PlayerTalkClass->SendGossipMenu( 4797,GetGUID()); break;
                        case CLASS_SHAMAN: pPlayer->PlayerTalkClass->SendGossipMenu( 5003,GetGUID()); break;
                        case CLASS_WARLOCK:pPlayer->PlayerTalkClass->SendGossipMenu( 5836,GetGUID()); break;
                        case CLASS_WARRIOR:pPlayer->PlayerTalkClass->SendGossipMenu( 4985,GetGUID()); break;
                    }
                }
                return false;
            }
            break;
        case TRAINER_TYPE_PETS:
            if(pPlayer->getClass()!=CLASS_HUNTER)
            {
                pPlayer->PlayerTalkClass->ClearMenus();
                pPlayer->PlayerTalkClass->SendGossipMenu(3620,GetGUID());
                return false;
            }
            break;
        case TRAINER_TYPE_MOUNTS:
            if(GetCreatureInfo()->trainer_race && pPlayer->getRace() != GetCreatureInfo()->trainer_race)
            {
                if(msg)
                {
                    pPlayer->PlayerTalkClass->ClearMenus();
                    switch(GetCreatureInfo()->trainer_class)
                    {
                        case RACE_DWARF:        pPlayer->PlayerTalkClass->SendGossipMenu(5865,GetGUID()); break;
                        case RACE_GNOME:        pPlayer->PlayerTalkClass->SendGossipMenu(4881,GetGUID()); break;
                        case RACE_HUMAN:        pPlayer->PlayerTalkClass->SendGossipMenu(5861,GetGUID()); break;
                        case RACE_NIGHTELF:     pPlayer->PlayerTalkClass->SendGossipMenu(5862,GetGUID()); break;
                        case RACE_ORC:          pPlayer->PlayerTalkClass->SendGossipMenu(5863,GetGUID()); break;
                        case RACE_TAUREN:       pPlayer->PlayerTalkClass->SendGossipMenu(5864,GetGUID()); break;
                        case RACE_TROLL:        pPlayer->PlayerTalkClass->SendGossipMenu(5816,GetGUID()); break;
                        case RACE_UNDEAD_PLAYER:pPlayer->PlayerTalkClass->SendGossipMenu( 624,GetGUID()); break;
                        case RACE_BLOODELF:     pPlayer->PlayerTalkClass->SendGossipMenu(5862,GetGUID()); break;
                        case RACE_DRAENEI:      pPlayer->PlayerTalkClass->SendGossipMenu(5864,GetGUID()); break;
                    }
                }
                return false;
            }
            break;
        case TRAINER_TYPE_TRADESKILLS:
            if(GetCreatureInfo()->trainer_spell && !pPlayer->HasSpell(GetCreatureInfo()->trainer_spell))
            {
                if(msg)
                {
                    pPlayer->PlayerTalkClass->ClearMenus();
                    pPlayer->PlayerTalkClass->SendGossipMenu(11031,GetGUID());
                }
                return false;
            }
            break;
        default:
            return false;                                   // checked and error output at creature_template loading
    }
    return true;
}

bool Creature::isCanInteractWithBattleMaster(Player* pPlayer, bool msg) const
{
    if(!isBattleMaster())
        return false;

    BattleGroundTypeId bgTypeId = sBattleGroundMgr.GetBattleMasterBG(GetEntry());
    if(!msg)
        return pPlayer->GetBGAccessByLevel(bgTypeId);

    if(!pPlayer->GetBGAccessByLevel(bgTypeId))
    {
        pPlayer->PlayerTalkClass->ClearMenus();
        switch(bgTypeId)
        {
            case BATTLEGROUND_AV:  pPlayer->PlayerTalkClass->SendGossipMenu(7616,GetGUID()); break;
            case BATTLEGROUND_WS:  pPlayer->PlayerTalkClass->SendGossipMenu(7599,GetGUID()); break;
            case BATTLEGROUND_AB:  pPlayer->PlayerTalkClass->SendGossipMenu(7642,GetGUID()); break;
            case BATTLEGROUND_EY:
            case BATTLEGROUND_NA:
            case BATTLEGROUND_BE:
            case BATTLEGROUND_AA:
            case BATTLEGROUND_RL:
            case BATTLEGROUND_SA:
            case BATTLEGROUND_DS:
            case BATTLEGROUND_RV: pPlayer->PlayerTalkClass->SendGossipMenu(10024,GetGUID()); break;
            default: break;
        }
        return false;
    }
    return true;
}

bool Creature::isCanTrainingAndResetTalentsOf(Player* pPlayer) const
{
    return pPlayer->getLevel() >= 10
        && GetCreatureInfo()->trainer_type == TRAINER_TYPE_CLASS
        && pPlayer->getClass() == GetCreatureInfo()->trainer_class;
}

void Creature::prepareGossipMenu( Player *pPlayer,uint32 gossipid )
{
    //Prevent gossip from NPCs that are possessed.
    Unit* Charmed = Unit::GetCharmer();
    if (Charmed)
        return;

    PlayerMenu* pm=pPlayer->PlayerTalkClass;
    pm->ClearMenus();

    // lazy loading single time at use
    LoadGossipOptions();

    for (GossipOptionList::iterator i = m_goptions.begin( ); i != m_goptions.end( ); ++i )
    {
        GossipOption* gso=&*i;
        if(gso->GossipId == gossipid)
        {
            bool cantalking=true;
            if(gso->Id==1)
            {
                uint32 textid=GetNpcTextId();
                GossipText const* gossiptext=objmgr.GetGossipText(textid);
                if(!gossiptext)
                    cantalking=false;
            }
            else
            {
                switch (gso->Action)
                {
                    case GOSSIP_OPTION_QUESTGIVER:
                        pPlayer->PrepareQuestMenu(GetGUID());
                        //if (pm->GetQuestMenu()->MenuItemCount() == 0)
                        cantalking=false;
                        //pm->GetQuestMenu()->ClearMenu();
                        break;
                    case GOSSIP_OPTION_ARMORER:
                        cantalking=false;                   // added in special mode
                        break;
                    case GOSSIP_OPTION_SPIRITHEALER:
                        if( !pPlayer->isDead() )
                            cantalking=false;
                        break;
                    case GOSSIP_OPTION_VENDOR:
                    {
                        VendorItemData const* vItems = GetVendorItems();
                        if(!vItems || vItems->Empty())
                        {
                            sLog.outErrorDb("Creature %u (Entry: %u) have UNIT_NPC_FLAG_VENDOR but have empty trading item list.",
                                GetGUIDLow(),GetEntry());
                            cantalking=false;
                        }
                        break;
                    }
                    case GOSSIP_OPTION_TRAINER:
                        if(!isCanTrainingOf(pPlayer,false))
                            cantalking=false;
                        break;
                    case GOSSIP_OPTION_LEARNDUALSPEC:
                        if(!(pPlayer->GetSpecsCount() == 1 && isCanTrainingAndResetTalentsOf(pPlayer) && !(pPlayer->getLevel() < sWorld.getConfig(CONFIG_MIN_DUALSPEC_LEVEL))))
                            cantalking=false;
                        break;
                    case GOSSIP_OPTION_UNLEARNTALENTS:
                        if(!isCanTrainingAndResetTalentsOf(pPlayer))
                            cantalking=false;
                        break;
                    case GOSSIP_OPTION_UNLEARNPETSKILLS:
                        if(!pPlayer->GetPet() || pPlayer->GetPet()->getPetType() != HUNTER_PET || pPlayer->GetPet()->m_spells.size() <= 1 || GetCreatureInfo()->trainer_type != TRAINER_TYPE_PETS || GetCreatureInfo()->trainer_class != CLASS_HUNTER)
                            cantalking=false;
                        break;
                    case GOSSIP_OPTION_TAXIVENDOR:
                        if ( pPlayer->GetSession()->SendLearnNewTaxiNode(this) )
                            return;
                        break;
                    case GOSSIP_OPTION_BATTLEFIELD:
                        if(!isCanInteractWithBattleMaster(pPlayer,false))
                            cantalking=false;
                        break;
                    case GOSSIP_OPTION_SPIRITGUIDE:
                    case GOSSIP_OPTION_INNKEEPER:
                    case GOSSIP_OPTION_BANKER:
                    case GOSSIP_OPTION_PETITIONER:
                    case GOSSIP_OPTION_STABLEPET:
                    case GOSSIP_OPTION_TABARDDESIGNER:
                    case GOSSIP_OPTION_AUCTIONEER:
                        break;                              // no checks
                    case GOSSIP_OPTION_OUTDOORPVP:
                        if ( !sOutdoorPvPMgr.CanTalkTo(pPlayer,this,(*gso)) )
                            cantalking = false;
                        break;
                    default:
                        sLog.outErrorDb("Creature %u (entry: %u) have unknown gossip option %u",GetDBTableGUIDLow(),GetEntry(),gso->Action);
                        break;
                }
            }

            //note for future dev: should have database fields for BoxMessage & BoxMoney
            if(!gso->OptionText.empty() && cantalking)
            {
                std::string OptionText = gso->OptionText;
                std::string BoxText = gso->BoxText;
                int loc_idx = pPlayer->GetSession()->GetSessionDbLocaleIndex();
                if (loc_idx >= 0)
                {
                    NpcOptionLocale const *no = objmgr.GetNpcOptionLocale(gso->Id);
                    if (no)
                    {
                        if (no->OptionText.size() > loc_idx && !no->OptionText[loc_idx].empty())
                            OptionText=no->OptionText[loc_idx];
                        if (no->BoxText.size() > loc_idx && !no->BoxText[loc_idx].empty())
                            BoxText=no->BoxText[loc_idx];
                    }
                }
                pm->GetGossipMenu().AddMenuItem((uint8)gso->Icon,OptionText, gossipid,gso->Action,BoxText,gso->BoxMoney,gso->Coded);
            }
        }
    }

    ///some gossips aren't handled in normal way ... so we need to do it this way .. TODO: handle it in normal way ;-)
    if(pm->Empty())
    {
        if(HasFlag(UNIT_NPC_FLAGS,UNIT_NPC_FLAG_TRAINER))
        {
            isCanTrainingOf(pPlayer,true);                  // output error message if need
        }
        if(HasFlag(UNIT_NPC_FLAGS,UNIT_NPC_FLAG_BATTLEMASTER))
        {
            isCanInteractWithBattleMaster(pPlayer,true);     // output error message if need
        }
    }
}

void Creature::sendPreparedGossip(Player* player)
{
    if(!player)
        return;

    if(GetCreatureInfo()->flags_extra & CREATURE_FLAG_EXTRA_WORLDEVENT) // if world event npc then
        gameeventmgr.HandleWorldEventGossip(player, this);      // update world state with progress

    // in case no gossip flag and quest menu not empty, open quest menu (client expect gossip menu with this flag)
    if (!HasFlag(UNIT_NPC_FLAGS,UNIT_NPC_FLAG_GOSSIP) && !player->PlayerTalkClass->GetQuestMenu().Empty())
    {
        player->SendPreparedQuest(GetGUID());
        return;
    }

    // in case non empty gossip menu (that not included quests list size) show it
    // (quest entries from quest menu will be included in list)
    player->PlayerTalkClass->SendGossipMenu(GetNpcTextId(), GetGUID());
}

void Creature::OnGossipSelect(Player* player, uint32 option)
{
    GossipMenu& gossipmenu = player->PlayerTalkClass->GetGossipMenu();

    if(option >= gossipmenu.MenuItemCount())
        return;

    uint32 action=gossipmenu.GetItem(option).m_gAction;
    uint32 zoneid=GetZoneId();
    uint64 guid=GetGUID();

    GossipOption const *gossip=GetGossipOption( action );
    if(!gossip)
    {
        zoneid=0;
        gossip=GetGossipOption( action );
        if(!gossip)
            return;
    }

    switch (gossip->Action)
    {
        case GOSSIP_OPTION_GOSSIP:
        {
            uint32 textid = GetGossipTextId(action, zoneid);
            if (textid == 0)
                textid=GetNpcTextId();

            player->PlayerTalkClass->CloseGossip();
            player->PlayerTalkClass->SendTalking(textid);
            break;
        }
        case GOSSIP_OPTION_OUTDOORPVP:
            sOutdoorPvPMgr.HandleGossipOption(player, GetGUID(), option);
            break;
        case GOSSIP_OPTION_SPIRITHEALER:
            if (player->isDead())
                CastSpell(this,17251,true,NULL,NULL,player->GetGUID());
            break;
        case GOSSIP_OPTION_QUESTGIVER:
            player->PrepareQuestMenu( guid );
            player->SendPreparedQuest( guid );
            break;
        case GOSSIP_OPTION_VENDOR:
        case GOSSIP_OPTION_ARMORER:
            player->GetSession()->SendListInventory(guid);
            break;
        case GOSSIP_OPTION_STABLEPET:
            player->GetSession()->SendStablePet(guid);
            break;
        case GOSSIP_OPTION_TRAINER:
            player->GetSession()->SendTrainerList(guid);
            break;
        case GOSSIP_OPTION_UNLEARNTALENTS:
            player->PlayerTalkClass->CloseGossip();
            player->SendTalentWipeConfirm(guid);
            break;
        case GOSSIP_OPTION_LEARNDUALSPEC:
            if(player->GetSpecsCount() == 1 && !(player->getLevel() < sWorld.getConfig(CONFIG_MIN_DUALSPEC_LEVEL)))
            {
                if (player->GetMoney() < 10000000)
                {
                    player->SendBuyError( BUY_ERR_NOT_ENOUGHT_MONEY, 0, 0, 0);
                    player->PlayerTalkClass->CloseGossip();
                    break;
                }
                else
                {
                    player->ModifyMoney(-10000000);

                    // Cast spells that teach dual spec
                    // Both are also ImplicitTarget self and must be cast by player
                    player->CastSpell(player,63680,true,NULL,NULL,player->GetGUID());
                    player->CastSpell(player,63624,true,NULL,NULL,player->GetGUID());

                    // Should show another Gossip text with "Congratulations..."
                    player->PlayerTalkClass->CloseGossip();
                }
            }
            break;
        case GOSSIP_OPTION_UNLEARNPETSKILLS:
            player->PlayerTalkClass->CloseGossip();
            player->SendPetSkillWipeConfirm();
            break;
        case GOSSIP_OPTION_TAXIVENDOR:
            player->GetSession()->SendTaxiMenu(this);
            break;
        case GOSSIP_OPTION_INNKEEPER:
            player->PlayerTalkClass->CloseGossip();
            player->SetBindPoint( guid );
            break;
        case GOSSIP_OPTION_BANKER:
            player->GetSession()->SendShowBank( guid );
            break;
        case GOSSIP_OPTION_PETITIONER:
            player->PlayerTalkClass->CloseGossip();
            player->GetSession()->SendPetitionShowList( guid );
            break;
        case GOSSIP_OPTION_TABARDDESIGNER:
            player->PlayerTalkClass->CloseGossip();
            player->GetSession()->SendTabardVendorActivate( guid );
            break;
        case GOSSIP_OPTION_AUCTIONEER:
            player->GetSession()->SendAuctionHello( guid, this );
            break;
        case GOSSIP_OPTION_SPIRITGUIDE:
        case GOSSIP_GUARD_SPELLTRAINER:
        case GOSSIP_GUARD_SKILLTRAINER:
            prepareGossipMenu( player,gossip->Id );
            sendPreparedGossip( player );
            break;
        case GOSSIP_OPTION_BATTLEFIELD:
        {
            BattleGroundTypeId bgTypeId = sBattleGroundMgr.GetBattleMasterBG(GetEntry());
            player->GetSession()->SendBattlegGroundList( GetGUID(), bgTypeId );
            break;
        }
        default:
            OnPoiSelect( player, gossip );
            break;
    }

}

void Creature::OnPoiSelect(Player* player, GossipOption const *gossip)
{
    if(gossip->GossipId==GOSSIP_GUARD_SPELLTRAINER || gossip->GossipId==GOSSIP_GUARD_SKILLTRAINER)
    {
        Poi_Icon icon = ICON_POI_BLANK;
        //need add more case.
        switch(gossip->Action)
        {
            case GOSSIP_GUARD_BANK:
                icon=ICON_POI_SMALL_HOUSE;
                break;
            case GOSSIP_GUARD_RIDE:
                icon=ICON_POI_RWHORSE;
                break;
            case GOSSIP_GUARD_GUILD:
                icon=ICON_POI_BLUETOWER;
                break;
            default:
                icon=ICON_POI_GREYTOWER;
                break;
        }
        uint32 textid = GetGossipTextId( gossip->Action, GetZoneId() );
        player->PlayerTalkClass->SendTalking(textid);
        // std::string areaname= gossip->OptionText;
        // how this could worked player->PlayerTalkClass->SendPointOfInterest( x, y, icon, 2, 15, areaname.c_str() );
    }
}

uint32 Creature::GetGossipTextId(uint32 action, uint32 zoneid)
{
    QueryResult *result= WorldDatabase.PQuery("SELECT textid FROM npc_gossip_textid WHERE action = '%u' AND zoneid ='%u'", action, zoneid );

    if(!result)
        return 0;

    Field *fields = result->Fetch();
    uint32 id = fields[0].GetUInt32();

    delete result;

    return id;
}

uint32 Creature::GetNpcTextId()
{
    // don't cache / use cache in case it's a world event announcer
    if(GetCreatureInfo()->flags_extra & CREATURE_FLAG_EXTRA_WORLDEVENT)
        if(uint32 textid = gameeventmgr.GetNpcTextId(m_DBTableGuid))
            return textid;

    if (!m_DBTableGuid)
        return DEFAULT_GOSSIP_MESSAGE;

    if(uint32 pos = objmgr.GetNpcGossip(m_DBTableGuid))
        return pos;

    return DEFAULT_GOSSIP_MESSAGE;
}

GossipOption const* Creature::GetGossipOption( uint32 id ) const
{
    for (GossipOptionList::const_iterator i = m_goptions.begin( ); i != m_goptions.end( ); ++i )
    {
        if(i->Action==id )
            return &*i;
    }
    return NULL;
}

void Creature::ResetGossipOptions()
{
    m_gossipOptionLoaded = false;
    m_goptions.clear();
}

void Creature::LoadGossipOptions()
{
    if(m_gossipOptionLoaded)
        return;

    uint32 npcflags=GetUInt32Value(UNIT_NPC_FLAGS);

    CacheNpcOptionList const& noList = objmgr.GetNpcOptions ();
    for (CacheNpcOptionList::const_iterator i = noList.begin (); i != noList.end (); ++i)
        if(i->NpcFlag & npcflags)
            addGossipOption(*i);

    m_gossipOptionLoaded = true;
}

void Creature::AI_SendMoveToPacket(float x, float y, float z, uint32 time, uint32 MovementFlags, uint8 type)
{
    /*    uint32 timeElap = getMSTime();
        if ((timeElap - m_startMove) < m_moveTime)
        {
            oX = (dX - oX) * ( (timeElap - m_startMove) / m_moveTime );
            oY = (dY - oY) * ( (timeElap - m_startMove) / m_moveTime );
        }
        else
        {
            oX = dX;
            oY = dY;
        }

        dX = x;
        dY = y;
        m_orientation = atan2((oY - dY), (oX - dX));

        m_startMove = getMSTime();
        m_moveTime = time;*/
    SendMonsterMove(x, y, z, time);
}

Player *Creature::GetLootRecipient() const
{
    if (!m_lootRecipient) return NULL;
    else return ObjectAccessor::FindPlayer(m_lootRecipient);
}

void Creature::SetLootRecipient(Unit *unit)
{
    // set the player whose group should receive the right
    // to loot the creature after it dies
    // should be set to NULL after the loot disappears

    if (!unit)
    {
        m_lootRecipient = 0;
        RemoveFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_LOOTABLE);
        RemoveFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_OTHER_TAGGER);
        return;
    }

    Player* player = unit->GetCharmerOrOwnerPlayerOrPlayerItself();
    if(!player)                                             // normal creature, no player involved
        return;

    m_lootRecipient = player->GetGUID();
    SetFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_OTHER_TAGGER);
}

void Creature::SaveToDB()
{
    // this should only be used when the creature has already been loaded
    // preferably after adding to map, because mapid may not be valid otherwise
    CreatureData const *data = objmgr.GetCreatureData(m_DBTableGuid);
    if(!data)
    {
        sLog.outError("Creature::SaveToDB failed, cannot get creature data!");
        return;
    }

    SaveToDB(GetMapId(), data->spawnMask,GetPhaseMask());
}

void Creature::SaveToDB(uint32 mapid, uint8 spawnMask, uint32 phaseMask)
{
    // update in loaded data
    if (!m_DBTableGuid)
        m_DBTableGuid = GetGUIDLow();
    CreatureData& data = objmgr.NewOrExistCreatureData(m_DBTableGuid);

    uint32 displayId = GetNativeDisplayId();

    // check if it's a custom model and if not, use 0 for displayId
    CreatureInfo const *cinfo = GetCreatureInfo();
    if (cinfo)
    {
        if (displayId == cinfo->Modelid1 || displayId == cinfo->Modelid2 ||
            displayId == cinfo->Modelid3 || displayId == cinfo->Modelid4)
            displayId = 0;
    }

    // data->guid = guid don't must be update at save
    data.id = GetEntry();
    data.mapid = mapid;
    data.phaseMask = phaseMask;
    data.displayid = displayId;
    data.equipmentId = GetEquipmentId();
    data.posX = GetPositionX();
    data.posY = GetPositionY();
    data.posZ = GetPositionZ();
    data.orientation = GetOrientation();
    data.spawntimesecs = m_respawnDelay;
    // prevent add data integrity problems
    data.spawndist = GetDefaultMovementType()==IDLE_MOTION_TYPE ? 0 : m_respawnradius;
    data.currentwaypoint = 0;
    data.curhealth = GetHealth();
    data.curmana = GetPower(POWER_MANA);
    data.is_dead = m_isDeadByDefault;
    // prevent add data integrity problems
    data.movementType = !m_respawnradius && GetDefaultMovementType()==RANDOM_MOTION_TYPE
        ? IDLE_MOTION_TYPE : GetDefaultMovementType();
    data.spawnMask = spawnMask;

    // updated in DB
    WorldDatabase.BeginTransaction();

    WorldDatabase.PExecuteLog("DELETE FROM creature WHERE guid = '%u'", m_DBTableGuid);

    std::ostringstream ss;
    ss << "INSERT INTO creature VALUES ("
        << m_DBTableGuid << ","
        << GetEntry() << ","
        << mapid <<","
        << uint32(spawnMask) << ","                         // cast to prevent save as symbol
        << uint16(GetPhaseMask()) << ","                    // prevent out of range error
        << displayId <<","
        << GetEquipmentId() <<","
        << GetPositionX() << ","
        << GetPositionY() << ","
        << GetPositionZ() << ","
        << GetOrientation() << ","
        << m_respawnDelay << ","                            //respawn time
        << (float) m_respawnradius << ","                   //spawn distance (float)
        << (uint32) (0) << ","                              //currentwaypoint
        << GetHealth() << ","                               //curhealth
        << GetPower(POWER_MANA) << ","                      //curmana
        << (m_isDeadByDefault ? 1 : 0) << ","               //is_dead
        << GetDefaultMovementType() << ")";                 //default movement generator type

    WorldDatabase.PExecuteLog( ss.str( ).c_str( ) );

    WorldDatabase.CommitTransaction();
}

void Creature::SelectLevel(const CreatureInfo *cinfo)
{
    uint32 rank = isPet()? 0 : cinfo->rank;

    // level
    uint32 minlevel = std::min(cinfo->maxlevel, cinfo->minlevel);
    uint32 maxlevel = std::max(cinfo->maxlevel, cinfo->minlevel);
    uint32 level = minlevel == maxlevel ? minlevel : urand(minlevel, maxlevel);
    SetLevel(level);

    float rellevel = maxlevel == minlevel ? 0 : (float(level - minlevel))/(maxlevel - minlevel);

    // health
    float healthmod = _GetHealthMod(rank);

    uint32 minhealth = std::min(cinfo->maxhealth, cinfo->minhealth);
    uint32 maxhealth = std::max(cinfo->maxhealth, cinfo->minhealth);
    uint32 health = uint32(healthmod * (minhealth + uint32(rellevel*(maxhealth - minhealth))));

    SetCreateHealth(health);
    SetMaxHealth(health);
    SetHealth(health);
    ResetPlayerDamageReq();

    // mana
    uint32 minmana = std::min(cinfo->maxmana, cinfo->minmana);
    uint32 maxmana = std::max(cinfo->maxmana, cinfo->minmana);
    uint32 mana = minmana + uint32(rellevel*(maxmana - minmana));

    SetCreateMana(mana);
    SetMaxPower(POWER_MANA, mana);                          //MAX Mana
    SetPower(POWER_MANA, mana);

    // TODO: set UNIT_FIELD_POWER*, for some creature class case (energy, etc)

    SetModifierValue(UNIT_MOD_HEALTH, BASE_VALUE, health);
    SetModifierValue(UNIT_MOD_MANA, BASE_VALUE, mana);

    //damage
    float damagemod = 1.0f;//_GetDamageMod(rank);

    SetBaseWeaponDamage(BASE_ATTACK, MINDAMAGE, cinfo->mindmg * damagemod);
    SetBaseWeaponDamage(BASE_ATTACK, MAXDAMAGE, cinfo->maxdmg * damagemod);

    SetFloatValue(UNIT_FIELD_MINRANGEDDAMAGE,cinfo->minrangedmg * damagemod);
    SetFloatValue(UNIT_FIELD_MAXRANGEDDAMAGE,cinfo->maxrangedmg * damagemod);

    SetModifierValue(UNIT_MOD_ATTACK_POWER, BASE_VALUE, cinfo->attackpower * damagemod);

}

float Creature::_GetHealthMod(int32 Rank)
{
    switch (Rank)                                           // define rates for each elite rank
    {
        case CREATURE_ELITE_NORMAL:
            return sWorld.getRate(RATE_CREATURE_NORMAL_HP);
        case CREATURE_ELITE_ELITE:
            return sWorld.getRate(RATE_CREATURE_ELITE_ELITE_HP);
        case CREATURE_ELITE_RAREELITE:
            return sWorld.getRate(RATE_CREATURE_ELITE_RAREELITE_HP);
        case CREATURE_ELITE_WORLDBOSS:
            return sWorld.getRate(RATE_CREATURE_ELITE_WORLDBOSS_HP);
        case CREATURE_ELITE_RARE:
            return sWorld.getRate(RATE_CREATURE_ELITE_RARE_HP);
        default:
            return sWorld.getRate(RATE_CREATURE_ELITE_ELITE_HP);
    }
}

float Creature::_GetDamageMod(int32 Rank)
{
    switch (Rank)                                           // define rates for each elite rank
    {
        case CREATURE_ELITE_NORMAL:
            return sWorld.getRate(RATE_CREATURE_NORMAL_DAMAGE);
        case CREATURE_ELITE_ELITE:
            return sWorld.getRate(RATE_CREATURE_ELITE_ELITE_DAMAGE);
        case CREATURE_ELITE_RAREELITE:
            return sWorld.getRate(RATE_CREATURE_ELITE_RAREELITE_DAMAGE);
        case CREATURE_ELITE_WORLDBOSS:
            return sWorld.getRate(RATE_CREATURE_ELITE_WORLDBOSS_DAMAGE);
        case CREATURE_ELITE_RARE:
            return sWorld.getRate(RATE_CREATURE_ELITE_RARE_DAMAGE);
        default:
            return sWorld.getRate(RATE_CREATURE_ELITE_ELITE_DAMAGE);
    }
}

float Creature::GetSpellDamageMod(int32 Rank)
{
    switch (Rank)                                           // define rates for each elite rank
    {
        case CREATURE_ELITE_NORMAL:
            return sWorld.getRate(RATE_CREATURE_NORMAL_SPELLDAMAGE);
        case CREATURE_ELITE_ELITE:
            return sWorld.getRate(RATE_CREATURE_ELITE_ELITE_SPELLDAMAGE);
        case CREATURE_ELITE_RAREELITE:
            return sWorld.getRate(RATE_CREATURE_ELITE_RAREELITE_SPELLDAMAGE);
        case CREATURE_ELITE_WORLDBOSS:
            return sWorld.getRate(RATE_CREATURE_ELITE_WORLDBOSS_SPELLDAMAGE);
        case CREATURE_ELITE_RARE:
            return sWorld.getRate(RATE_CREATURE_ELITE_RARE_SPELLDAMAGE);
        default:
            return sWorld.getRate(RATE_CREATURE_ELITE_ELITE_SPELLDAMAGE);
    }
}

bool Creature::CreateFromProto(uint32 guidlow, uint32 Entry, uint32 vehId, uint32 team, const CreatureData *data)
{
    SetZoneScript();
    if(m_zoneScript && data)
    {
        Entry = m_zoneScript->GetCreatureEntry(guidlow, data);
        if(!Entry)
            return false;
    }

    CreatureInfo const *cinfo = objmgr.GetCreatureTemplate(Entry);
    if(!cinfo)
    {
        sLog.outErrorDb("Creature entry %u does not exist.", Entry);
        return false;
    }

    SetOriginalEntry(Entry);

    if(!vehId)
        vehId = cinfo->VehicleId;

    if(vehId && !CreateVehicleKit(vehId))
        vehId = 0;

    Object::_Create(guidlow, Entry, vehId ? HIGHGUID_VEHICLE : HIGHGUID_UNIT);

    if(!UpdateEntry(Entry, team, data))
        return false;

    return true;
}

bool Creature::LoadFromDB(uint32 guid, Map *map)
{
    CreatureData const* data = objmgr.GetCreatureData(guid);

    if(!data)
    {
        sLog.outErrorDb("Creature (GUID: %u) not found in table `creature`, can't load. ",guid);
        return false;
    }

    m_DBTableGuid = guid;
    if (map->GetInstanceId() != 0) guid = objmgr.GenerateLowGuid(HIGHGUID_UNIT);

    uint16 team = 0;
    if(!Create(guid,map,data->phaseMask,data->id,0,team,data->posX,data->posY,data->posZ,data->orientation,data))
        return false;

    //We should set first home position, because then AI calls home movement
    SetHomePosition(data->posX,data->posY,data->posZ,data->orientation);

    m_respawnradius = data->spawndist;

    m_respawnDelay = data->spawntimesecs;
    m_isDeadByDefault = data->is_dead;
    m_deathState = m_isDeadByDefault ? DEAD : ALIVE;

    m_respawnTime  = objmgr.GetCreatureRespawnTime(m_DBTableGuid,GetInstanceId());
    if(m_respawnTime)                          // respawn on Update
    {
        m_deathState = DEAD;
        if(canFly())
        {
            float tz = GetMap()->GetHeight(data->posX,data->posY,data->posZ,false);
            if(data->posZ - tz > 0.1)
                Relocate(data->posX,data->posY,tz);
        }
    }

    uint32 curhealth = data->curhealth;
    if(curhealth)
    {
        curhealth = uint32(curhealth*_GetHealthMod(GetCreatureInfo()->rank));
        if(curhealth < 1)
            curhealth = 1;
    }

    SetHealth(m_deathState == ALIVE ? curhealth : 0);
    SetPower(POWER_MANA,data->curmana);

    // checked at creature_template loading
    m_defaultMovementType = MovementGeneratorType(data->movementType);

    m_creatureData = data;

    return true;
}

void Creature::LoadEquipment(uint32 equip_entry, bool force)
{
    if(equip_entry == 0)
    {
        if (force)
        {
            for (uint8 i = 0; i < 3; ++i)
                SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + i, 0);
            m_equipmentId = 0;
        }
        return;
    }

    EquipmentInfo const *einfo = objmgr.GetEquipmentInfo(equip_entry);
    if (!einfo)
        return;

    m_equipmentId = equip_entry;
    for (uint8 i = 0; i < 3; ++i)
        SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + i, einfo->equipentry[i]);
}

bool Creature::hasQuest(uint32 quest_id) const
{
    QuestRelations const& qr = objmgr.mCreatureQuestRelations;
    for (QuestRelations::const_iterator itr = qr.lower_bound(GetEntry()); itr != qr.upper_bound(GetEntry()); ++itr)
    {
        if(itr->second==quest_id)
            return true;
    }
    return false;
}

bool Creature::hasInvolvedQuest(uint32 quest_id) const
{
    QuestRelations const& qr = objmgr.mCreatureQuestInvolvedRelations;
    for (QuestRelations::const_iterator itr = qr.lower_bound(GetEntry()); itr != qr.upper_bound(GetEntry()); ++itr)
    {
        if(itr->second==quest_id)
            return true;
    }
    return false;
}

void Creature::DeleteFromDB()
{
    if (!m_DBTableGuid)
    {
        sLog.outDebug("Trying to delete not saved creature!");
        return;
    }

    objmgr.SaveCreatureRespawnTime(m_DBTableGuid,GetInstanceId(),0);
    objmgr.DeleteCreatureData(m_DBTableGuid);

    WorldDatabase.BeginTransaction();
    WorldDatabase.PExecuteLog("DELETE FROM creature WHERE guid = '%u'", m_DBTableGuid);
    WorldDatabase.PExecuteLog("DELETE FROM creature_addon WHERE guid = '%u'", m_DBTableGuid);
    WorldDatabase.PExecuteLog("DELETE FROM game_event_creature WHERE guid = '%u'", m_DBTableGuid);
    WorldDatabase.PExecuteLog("DELETE FROM game_event_model_equip WHERE guid = '%u'", m_DBTableGuid);
    WorldDatabase.CommitTransaction();
}

bool Creature::canSeeOrDetect(Unit const* u, bool detect, bool inVisibleList, bool is3dDistance) const
{
    // not in world
    if(!IsInWorld() || !u->IsInWorld())
        return false;

    // all dead creatures/players not visible for any creatures
    if(!u->isAlive() || !isAlive())
        return false;

    // Always can see self
    if (u == this)
        return true;

    // phased visibility (both must phased in same way)
    if(!InSamePhase(u))
        return false;

    // always seen by owner
    if(GetGUID() == u->GetCharmerOrOwnerGUID())
        return true;

    if(u->GetVisibility() == VISIBILITY_OFF) //GM
        return false;

    // invisible aura
    if((m_invisibilityMask || u->m_invisibilityMask) && !canDetectInvisibilityOf(u))
        return false;

    // unit got in stealth in this moment and must ignore old detected state
    //if (m_Visibility == VISIBILITY_GROUP_NO_DETECT)
    //    return false;

    // GM invisibility checks early, invisibility if any detectable, so if not stealth then visible
    if(u->GetVisibility() == VISIBILITY_GROUP_STEALTH)
    {
        //do not know what is the use of this detect
        if(!detect || !canDetectStealthOf(u, GetDistance(u)))
            return false;
    }

    // Now check is target visible with LoS
    //return u->IsWithinLOS(GetPositionX(),GetPositionY(),GetPositionZ());
    return true;
}

bool Creature::canStartAttack(Unit const* who, bool force) const
{
    if(isCivilian())
        return false;

    if(!canFly() && (GetDistanceZ(who) > CREATURE_Z_ATTACK_RANGE + m_CombatDistance))
        //|| who->IsControlledByPlayer() && who->IsFlying()))
        // we cannot check flying for other creatures, too much map/vmap calculation
        // TODO: should switch to range attack
        return false;

    if(!force)
    {
        if(!_IsTargetAcceptable(who))
            return false;

        if(who->isInCombat())
            if(Unit *victim = who->getAttackerForHelper())
                if(IsWithinDistInMap(victim, sWorld.getConfig(CONFIG_CREATURE_FAMILY_ASSISTANCE_RADIUS)))
                    force = true;

        if(!force && (IsNeutralToAll() || !IsWithinDistInMap(who, GetAttackDistance(who) + m_CombatDistance)))
            return false;
    }

    if(!canCreatureAttack(who, force))
        return false;

    return IsWithinLOSInMap(who);
}

float Creature::GetAttackDistance(Unit const* pl) const
{
    float aggroRate = sWorld.getRate(RATE_CREATURE_AGGRO);
    if(aggroRate==0)
        return 0.0f;

    uint32 playerlevel   = pl->getLevelForTarget(this);
    uint32 creaturelevel = getLevelForTarget(pl);

    int32 leveldif       = int32(playerlevel) - int32(creaturelevel);

    // "The maximum Aggro Radius has a cap of 25 levels under. Example: A level 30 char has the same Aggro Radius of a level 5 char on a level 60 mob."
    if ( leveldif < - 25)
        leveldif = -25;

    // "The aggro radius of a mob having the same level as the player is roughly 20 yards"
    float RetDistance = 20;

    // "Aggro Radius varies with level difference at a rate of roughly 1 yard/level"
    // radius grow if playlevel < creaturelevel
    RetDistance -= (float)leveldif;

    if(creaturelevel+5 <= sWorld.getConfig(CONFIG_MAX_PLAYER_LEVEL))
    {
        // detect range auras
        RetDistance += GetTotalAuraModifier(SPELL_AURA_MOD_DETECT_RANGE);

        // detected range auras
        RetDistance += pl->GetTotalAuraModifier(SPELL_AURA_MOD_DETECTED_RANGE);
    }

    // "Minimum Aggro Radius for a mob seems to be combat range (5 yards)"
    if(RetDistance < 5)
        RetDistance = 5;

    return (RetDistance*aggroRate);
}

void Creature::setDeathState(DeathState s)
{
    if((s == JUST_DIED && !m_isDeadByDefault)||(s == JUST_ALIVED && m_isDeadByDefault))
    {
        m_deathTimer = m_corpseDelay*IN_MILISECONDS;

        // always save boss respawn time at death to prevent crash cheating
        if(sWorld.getConfig(CONFIG_SAVE_RESPAWN_TIME_IMMEDIATELY) || isWorldBoss())
            SaveRespawnTime();
    }
    Unit::setDeathState(s);

    if(s == JUST_DIED)
    {
        SetUInt64Value(UNIT_FIELD_TARGET,0);                // remove target selection in any cases (can be set at aura remove in Unit::setDeathState)
        SetUInt32Value(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_NONE);

        setActive(false);

        if(!isPet() && GetCreatureInfo()->SkinLootId)
            if ( LootTemplates_Skinning.HaveLootFor(GetCreatureInfo()->SkinLootId) )
                SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_SKINNABLE);

        SetNoSearchAssistance(false);

        //Dismiss group if is leader
        if(m_formation && m_formation->getLeader() == this)
            m_formation->FormationReset(true);

        if ((canFly() || IsFlying()) && FallGround())
            return;

        Unit::setDeathState(CORPSE);
    }
    else if(s == JUST_ALIVED)
    {
        //if(isPet())
        //    setActive(true);
        SetHealth(GetMaxHealth());
        SetLootRecipient(NULL);
        ResetPlayerDamageReq();
        CreatureInfo const *cinfo = GetCreatureInfo();
        AddUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
        if(GetCreatureInfo()->InhabitType & INHABIT_AIR)
            AddUnitMovementFlag(MOVEMENTFLAG_FLY_MODE + MOVEMENTFLAG_FLYING);
        SetUInt32Value(UNIT_NPC_FLAGS, cinfo->npcflag);
        clearUnitState(UNIT_STAT_ALL_STATE);
        SetMeleeDamageSchool(SpellSchools(cinfo->dmgschool));
        LoadCreaturesAddon(true);
        Motion_Initialize();
        if(GetCreatureData() && GetPhaseMask() != GetCreatureData()->phaseMask)
            SetPhaseMask(GetCreatureData()->phaseMask, false);
        if(m_vehicleKit) m_vehicleKit->Reset();
        Unit::setDeathState(ALIVE);
    }
}

bool Creature::FallGround()
{
    // Let's abort after we called this function one time
    if (getDeathState() == DEAD_FALLING)
        return false;

    float x, y, z;
    GetPosition(x, y, z);
    float ground_Z = GetMap()->GetVmapHeight(x, y, z, true);
    if (fabs(ground_Z - z) < 0.1f)
        return false;

    GetMotionMaster()->MoveFall(ground_Z, EVENT_FALL_GROUND);
    Unit::setDeathState(DEAD_FALLING);
    return true;
}

void Creature::Respawn(bool force)
{
    DestroyForNearbyPlayers();

    if(force)
    {
        if(isAlive())
            setDeathState(JUST_DIED);
        else if(getDeathState() != CORPSE)
            setDeathState(CORPSE);
    }

    RemoveCorpse();

    if(getDeathState()==DEAD)
    {
        if (m_DBTableGuid)
            objmgr.SaveCreatureRespawnTime(m_DBTableGuid,GetInstanceId(),0);

        DEBUG_LOG("Respawning...");
        m_respawnTime = 0;
        lootForPickPocketed = false;
        lootForBody         = false;

        if(m_originalEntry != GetEntry())
            UpdateEntry(m_originalEntry);

        CreatureInfo const *cinfo = GetCreatureInfo();
        SelectLevel(cinfo);

        if (m_isDeadByDefault)
        {
            setDeathState(JUST_DIED);
            SetHealth(0);
            i_motionMaster.Clear();
            clearUnitState(UNIT_STAT_ALL_STATE);
            LoadCreaturesAddon(true);
        }
        else
            setDeathState( JUST_ALIVED );

        CreatureModelInfo const *minfo = objmgr.GetCreatureModelRandomGender(GetNativeDisplayId());
        if (minfo)                                             // Cancel load if no model defined
        {
            uint32 display_id = minfo->modelid;                // it can be different (for another gender)

            SetDisplayId(display_id);
            SetNativeDisplayId(display_id);
            SetByteValue(UNIT_FIELD_BYTES_0, 2, minfo->gender);
        }

        //Call AI respawn virtual function
        AI()->JustRespawned();

        uint16 poolid = poolhandler.IsPartOfAPool(GetGUIDLow(), GetTypeId());
        if (poolid)
            poolhandler.UpdatePool(poolid, GetGUIDLow(), GetTypeId());
    }

    SetToNotify();
}

void Creature::ForcedDespawn()
{
    setDeathState(JUST_DIED);
    RemoveCorpse();
    SetHealth(0);                                           // just for nice GM-mode view
}

bool Creature::IsImmunedToSpell(SpellEntry const* spellInfo)
{
    if (!spellInfo)
        return false;

    if (GetCreatureInfo()->MechanicImmuneMask & (1 << (spellInfo->Mechanic - 1)))
        return true;

    return Unit::IsImmunedToSpell(spellInfo);
}

bool Creature::IsImmunedToSpellEffect(SpellEntry const* spellInfo, uint32 index) const
{
    if (GetCreatureInfo()->MechanicImmuneMask & (1 << (spellInfo->EffectMechanic[index] - 1)))
        return true;

    return Unit::IsImmunedToSpellEffect(spellInfo, index);
}

SpellEntry const *Creature::reachWithSpellAttack(Unit *pVictim)
{
    if(!pVictim)
        return NULL;

    for (uint32 i=0; i < CREATURE_MAX_SPELLS; ++i)
    {
        if(!m_spells[i])
            continue;
        SpellEntry const *spellInfo = sSpellStore.LookupEntry(m_spells[i] );
        if(!spellInfo)
        {
            sLog.outError("WORLD: unknown spell id %i", m_spells[i]);
            continue;
        }

        bool bcontinue = true;
        for (uint32 j=0; j<3; j++)
        {
            if( (spellInfo->Effect[j] == SPELL_EFFECT_SCHOOL_DAMAGE )       ||
                (spellInfo->Effect[j] == SPELL_EFFECT_INSTAKILL)            ||
                (spellInfo->Effect[j] == SPELL_EFFECT_ENVIRONMENTAL_DAMAGE) ||
                (spellInfo->Effect[j] == SPELL_EFFECT_HEALTH_LEECH )
                )
            {
                bcontinue = false;
                break;
            }
        }
        if(bcontinue) continue;

        if(spellInfo->manaCost > GetPower(POWER_MANA))
            continue;
        SpellRangeEntry const* srange = sSpellRangeStore.LookupEntry(spellInfo->rangeIndex);
        float range = GetSpellMaxRangeForHostile(srange);
        float minrange = GetSpellMinRangeForHostile(srange);
        float dist = GetDistance(pVictim);
        //if(!isInFront( pVictim, range ) && spellInfo->AttributesEx )
        //    continue;
        if( dist > range || dist < minrange )
            continue;
        if(spellInfo->PreventionType == SPELL_PREVENTION_TYPE_SILENCE && HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_SILENCED))
            continue;
        if(spellInfo->PreventionType == SPELL_PREVENTION_TYPE_PACIFY && HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PACIFIED))
            continue;
        return spellInfo;
    }
    return NULL;
}

SpellEntry const *Creature::reachWithSpellCure(Unit *pVictim)
{
    if(!pVictim)
        return NULL;

    for (uint32 i=0; i < CREATURE_MAX_SPELLS; ++i)
    {
        if(!m_spells[i])
            continue;
        SpellEntry const *spellInfo = sSpellStore.LookupEntry(m_spells[i] );
        if(!spellInfo)
        {
            sLog.outError("WORLD: unknown spell id %i", m_spells[i]);
            continue;
        }

        bool bcontinue = true;
        for (uint32 j=0; j<3; j++)
        {
            if( (spellInfo->Effect[j] == SPELL_EFFECT_HEAL ) )
            {
                bcontinue = false;
                break;
            }
        }
        if(bcontinue) continue;

        if(spellInfo->manaCost > GetPower(POWER_MANA))
            continue;
        SpellRangeEntry const* srange = sSpellRangeStore.LookupEntry(spellInfo->rangeIndex);
        float range = GetSpellMaxRangeForFriend(srange);
        float minrange = GetSpellMinRangeForFriend( srange);
        float dist = GetDistance(pVictim);
        //if(!isInFront( pVictim, range ) && spellInfo->AttributesEx )
        //    continue;
        if( dist > range || dist < minrange )
            continue;
        if(spellInfo->PreventionType == SPELL_PREVENTION_TYPE_SILENCE && HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_SILENCED))
            continue;
        if(spellInfo->PreventionType == SPELL_PREVENTION_TYPE_PACIFY && HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PACIFIED))
            continue;
        return spellInfo;
    }
    return NULL;
}

bool Creature::IsVisibleInGridForPlayer(Player const* pl) const
{
    // gamemaster in GM mode see all, including ghosts
    if(pl->isGameMaster())
        return true;

    // Trigger shouldn't be visible for players
    if(isTrigger())
        return false;

    // Live player (or with not release body see live creatures or death creatures with corpse disappearing time > 0
    if(pl->isAlive() || pl->GetDeathTimer() > 0)
    {
        if( GetEntry() == VISUAL_WAYPOINT )
            return false;
        return (isAlive() || m_deathTimer > 0 || (m_isDeadByDefault && m_deathState==CORPSE));
    }

    // Dead player see live creatures near own corpse
    if(isAlive())
    {
        Corpse *corpse = pl->GetCorpse();
        if(corpse)
        {
            // 20 - aggro distance for same level, 25 - max additional distance if player level less that creature level
            if(corpse->IsWithinDistInMap(this,(20+25)*sWorld.getRate(RATE_CREATURE_AGGRO)))
                return true;
        }
    }

    // Dead player see Spirit Healer or Spirit Guide
    if(isSpiritService())
        return true;

    // and not see any other
    return false;
}

Unit* Creature::SelectNearestTarget(float dist) const
{
    CellPair p(Trinity::ComputeCellPair(GetPositionX(), GetPositionY()));
    Cell cell(p);
    cell.data.Part.reserved = ALL_DISTRICT;
    cell.SetNoCreate();

    Unit *target = NULL;

    {
        Trinity::NearestHostileUnitInAttackDistanceCheck u_check(this, dist);
        Trinity::UnitLastSearcher<Trinity::NearestHostileUnitInAttackDistanceCheck> searcher(this, target, u_check);

        TypeContainerVisitor<Trinity::UnitLastSearcher<Trinity::NearestHostileUnitInAttackDistanceCheck>, WorldTypeMapContainer > world_unit_searcher(searcher);
        TypeContainerVisitor<Trinity::UnitLastSearcher<Trinity::NearestHostileUnitInAttackDistanceCheck>, GridTypeMapContainer >  grid_unit_searcher(searcher);

        CellLock<GridReadGuard> cell_lock(cell, p);
        cell_lock->Visit(cell_lock, world_unit_searcher, *GetMap(), *this, ATTACK_DISTANCE);
        cell_lock->Visit(cell_lock, grid_unit_searcher, *GetMap(), *this, ATTACK_DISTANCE);
    }

    return target;
}

void Creature::CallAssistance()
{
    if( !m_AlreadyCallAssistance && getVictim() && !isPet() && !isCharmed())
    {
        SetNoCallAssistance(true);

        float radius = sWorld.getConfig(CONFIG_CREATURE_FAMILY_ASSISTANCE_RADIUS);

        if(radius > 0)
        {
            std::list<Creature*> assistList;

            {
                CellPair p(Trinity::ComputeCellPair(GetPositionX(), GetPositionY()));
                Cell cell(p);
                cell.data.Part.reserved = ALL_DISTRICT;
                cell.SetNoCreate();

                MaNGOS::AnyAssistCreatureInRangeCheck u_check(this, getVictim(), radius);
                MaNGOS::CreatureListSearcher<MaNGOS::AnyAssistCreatureInRangeCheck> searcher(this, assistList, u_check);

                TypeContainerVisitor<Trinity::CreatureListSearcher<Trinity::AnyAssistCreatureInRangeCheck>, GridTypeMapContainer >  grid_creature_searcher(searcher);

                CellLock<GridReadGuard> cell_lock(cell, p);
                cell_lock->Visit(cell_lock, grid_creature_searcher, *GetMap(), *this, radius);
            }

            if (!assistList.empty())
            {
                AssistDelayEvent *e = new AssistDelayEvent(getVictim()->GetGUID(), *this);
                while (!assistList.empty())
                {
                    // Pushing guids because in delay can happen some creature gets despawned => invalid pointer
                    e->AddAssistant((*assistList.begin())->GetGUID());
                    assistList.pop_front();
                }
                m_Events.AddEvent(e, m_Events.CalculateTime(sWorld.getConfig(CONFIG_CREATURE_FAMILY_ASSISTANCE_DELAY)));
            }
        }
    }
}

void Creature::CallForHelp(float fRadius)
{
    if (fRadius <= 0.0f || !getVictim() || isPet() || isCharmed())
        return;

    CellPair p(MaNGOS::ComputeCellPair(GetPositionX(), GetPositionY()));
    Cell cell(p);
    cell.data.Part.reserved = ALL_DISTRICT;
    cell.SetNoCreate();

    MaNGOS::CallOfHelpCreatureInRangeDo u_do(this, getVictim(), fRadius);
    MaNGOS::CreatureWorker<MaNGOS::CallOfHelpCreatureInRangeDo> worker(this, u_do);

    TypeContainerVisitor<MaNGOS::CreatureWorker<MaNGOS::CallOfHelpCreatureInRangeDo>, GridTypeMapContainer >  grid_creature_searcher(worker);

    CellLock<GridReadGuard> cell_lock(cell, p);
    cell_lock->Visit(cell_lock, grid_creature_searcher, *GetMap(), *this, fRadius);
}

bool Creature::CanAssistTo(const Unit* u, const Unit* enemy, bool checkfaction /*= true*/) const
{
    // is it true?
    if(!HasReactState(REACT_AGGRESSIVE))
        return false;

    // we don't need help from zombies :)
    if (!isAlive())
        return false;

    // we don't need help from non-combatant ;)
    if (isCivilian())
        return false;

    // skip fighting creature
    if (isInCombat())
        return false;

    // only free creature
    if (GetCharmerOrOwnerGUID())
        return false;

    // only from same creature faction
    if (checkfaction)
    {
        if (getFaction() != u->getFaction())
            return false;
    }
    else
    {
        if (!IsFriendlyTo(u))
            return false;
    }

    // skip non hostile to caster enemy creatures
    if (!IsHostileTo(enemy))
        return false;

    return true;
}

// use this function to avoid having hostile creatures attack
// friendlies and other mobs they shouldn't attack
bool Creature::_IsTargetAcceptable(const Unit *target) const
{
    const Unit *myVictim = getAttackerForHelper();

    // if I'm already fighting target, the target is acceptable
    if (myVictim == target || target->getVictim() == this)
        return true;

    // if I'm hostile towards the target, the target is acceptable
    if (IsHostileTo(target))
        return true;

    const Unit *targetVictim = target->getAttackerForHelper();

    // if the target does not have a victim, the target is not acceptable
    if (!targetVictim)
        return false;

    // if the target's victim is friendly, and the target is neutral, the target is acceptable
    if (IsFriendlyTo(targetVictim) && !IsFriendlyTo(target))
        return true;

    // if the target's victim is not friendly, or the target is friendly, the target is not acceptable
    return false;
}

void Creature::SaveRespawnTime()
{
    if(isSummon() || !m_DBTableGuid || m_creatureData && !m_creatureData->dbData)
        return;

    if(m_respawnTime > time(NULL))                          // dead (no corpse)
        objmgr.SaveCreatureRespawnTime(m_DBTableGuid,GetInstanceId(),m_respawnTime);
    else if(m_deathTimer > 0)                               // dead (corpse)
        objmgr.SaveCreatureRespawnTime(m_DBTableGuid,GetInstanceId(),time(NULL)+m_respawnDelay+m_deathTimer/IN_MILISECONDS);
}

// this should not be called by petAI or
bool Creature::canCreatureAttack(Unit const *pVictim, bool force) const
{
    if(!pVictim->IsInMap(this))
        return false;

    if(!canAttack(pVictim, force))
        return false;

    if(!pVictim->isInAccessiblePlaceFor(this))
        return false;

    if(IsAIEnabled && !AI()->CanAIAttack(pVictim))
        return false;

    if(sMapStore.LookupEntry(GetMapId())->IsDungeon())
        return true;

    //Use AttackDistance in distance check if threat radius is lower. This prevents creature bounce in and out of combat every update tick.
    float dist = std::max(GetAttackDistance(pVictim), (float)sWorld.getConfig(CONFIG_THREAT_RADIUS)) + m_CombatDistance;

    if(Unit *unit = GetCharmerOrOwner())
        return pVictim->IsWithinDist(unit, dist);
    else
        return pVictim->IsInDist(&m_homePosition, dist);
}

CreatureDataAddon const* Creature::GetCreatureAddon() const
{
    if (m_DBTableGuid)
    {
        if(CreatureDataAddon const* addon = ObjectMgr::GetCreatureAddon(m_DBTableGuid))
            return addon;
    }

    // dependent from heroic mode entry
    return ObjectMgr::GetCreatureTemplateAddon(GetCreatureInfo()->Entry);
}

//creature_addon table
bool Creature::LoadCreaturesAddon(bool reload)
{
    CreatureDataAddon const *cainfo = GetCreatureAddon();
    if(!cainfo)
        return false;

    if (cainfo->mount != 0)
        Mount(cainfo->mount);

    if (cainfo->bytes1 != 0)
    {
        // 0 StandState
        // 1 FreeTalentPoints   Pet only, so always 0 for default creature
        // 2 StandFlags
        // 3 StandMiscFlags

        SetByteValue(UNIT_FIELD_BYTES_1, 0, uint8(cainfo->bytes1 & 0xFF));
        //SetByteValue(UNIT_FIELD_BYTES_1, 1, uint8((cainfo->bytes1 >> 8) & 0xFF));
        SetByteValue(UNIT_FIELD_BYTES_1, 1, 0);
        SetByteValue(UNIT_FIELD_BYTES_1, 2, uint8((cainfo->bytes1 >> 16) & 0xFF));
        SetByteValue(UNIT_FIELD_BYTES_1, 3, uint8((cainfo->bytes1 >> 24) & 0xFF));
    }

    if (cainfo->bytes2 != 0)
    {
        // 0 SheathState
        // 1 Bytes2Flags
        // 2 UnitRename         Pet only, so always 0 for default creature
        // 3 ShapeshiftForm     Must be determined/set by shapeshift spell/aura

        SetByteValue(UNIT_FIELD_BYTES_2, 0, uint8(cainfo->bytes2 & 0xFF));
        SetByteValue(UNIT_FIELD_BYTES_2, 1, uint8((cainfo->bytes2 >> 8) & 0xFF));
        //SetByteValue(UNIT_FIELD_BYTES_2, 2, uint8((cainfo->bytes2 >> 16) & 0xFF));
        SetByteValue(UNIT_FIELD_BYTES_2, 2, 0);
        //SetByteValue(UNIT_FIELD_BYTES_2, 3, uint8((cainfo->bytes2 >> 24) & 0xFF));
        SetByteValue(UNIT_FIELD_BYTES_2, 3, 0);
    }

    if (cainfo->emote != 0)
        SetUInt32Value(UNIT_NPC_EMOTESTATE, cainfo->emote);

    if (cainfo->move_flags != 0)
        SetUnitMovementFlags(cainfo->move_flags);

    if (cainfo->move_flags & (MOVEMENTFLAG_FLY_MODE | MOVEMENTFLAG_FLYING))
        sLog.outErrorDb("Creature (GUID: %u Entry: %u) has improper `moveflags` value in `creature_template_addon`. Use `InhabitType` = 4 (Flying) in `creature_template`, not MOVEMENTFLAG_FLY_MODE or MOVEMENTFLAG_FLYING in `creature_template_addon`.",GetGUIDLow(),GetEntry());

    //Load Path
    if (cainfo->path_id != 0)
        m_path_id = cainfo->path_id;

    if(cainfo->auras)
    {
        for (CreatureDataAddonAura const* cAura = cainfo->auras; cAura->spell_id; ++cAura)
        {
            SpellEntry const *AdditionalSpellInfo = sSpellStore.LookupEntry(cAura->spell_id);
            if (!AdditionalSpellInfo)
            {
                sLog.outErrorDb("Creature (GUID: %u Entry: %u) has wrong spell %u defined in `auras` field.",GetGUIDLow(),GetEntry(),cAura->spell_id);
                continue;
            }

            // skip already applied aura
            if(HasAuraEffect(cAura->spell_id,cAura->effect_idx))
            {
                if(!reload)
                    sLog.outErrorDb("Creature (GUID: %u Entry: %u) has duplicate aura (spell %u effect %u) in `auras` field.",GetGUIDLow(),GetEntry(),cAura->spell_id,cAura->effect_idx);

                continue;
            }

            AddAuraEffect(AdditionalSpellInfo, cAura->effect_idx, this, this);
            sLog.outDebug("Spell: %u with Aura %u added to creature (GUID: %u Entry: %u)", cAura->spell_id, AdditionalSpellInfo->EffectApplyAuraName[cAura->effect_idx],GetGUIDLow(),GetEntry());
        }
    }
    return true;
}

/// Send a message to LocalDefense channel for players opposition team in the zone
void Creature::SendZoneUnderAttackMessage(Player* attacker)
{
    uint32 enemy_team = attacker->GetTeam();

    WorldPacket data(SMSG_ZONE_UNDER_ATTACK,4);
    data << (uint32)GetAreaId();
    sWorld.SendGlobalMessage(&data,NULL,(enemy_team==ALLIANCE ? HORDE : ALLIANCE));
}

void Creature::SetInCombatWithZone()
{
    if (!CanHaveThreatList())
    {
        sLog.outError("Creature entry %u call SetInCombatWithZone but creature cannot have threat list.", GetEntry());
        return;
    }

    Map* pMap = GetMap();

    if (!pMap->IsDungeon())
    {
        sLog.outError("Creature entry %u call SetInCombatWithZone for map (id: %u) that isn't an instance.", GetEntry(), pMap->GetId());
        return;
    }

    Map::PlayerList const &PlList = pMap->GetPlayers();

    if (PlList.isEmpty())
        return;

    for (Map::PlayerList::const_iterator i = PlList.begin(); i != PlList.end(); ++i)
    {
        if (Player* pPlayer = i->getSource())
        {
            if (pPlayer->isGameMaster())
                continue;

            if (pPlayer->isAlive())
            {
                pPlayer->SetInCombatWith(this);
                AddThreat(pPlayer, 0.0f);
            }
        }
    }
}

void Creature::_AddCreatureSpellCooldown(uint32 spell_id, time_t end_time)
{
    m_CreatureSpellCooldowns[spell_id] = end_time;
}

void Creature::_AddCreatureCategoryCooldown(uint32 category, time_t apply_time)
{
    m_CreatureCategoryCooldowns[category] = apply_time;
}

void Creature::AddCreatureSpellCooldown(uint32 spellid)
{
    SpellEntry const *spellInfo = sSpellStore.LookupEntry(spellid);
    if(!spellInfo)
        return;

    uint32 cooldown = GetSpellRecoveryTime(spellInfo);
    if(Player *modOwner = GetSpellModOwner())
        modOwner->ApplySpellMod(spellid, SPELLMOD_COOLDOWN, cooldown);

    if(cooldown)
        _AddCreatureSpellCooldown(spellid, time(NULL) + cooldown/IN_MILISECONDS);

    if(spellInfo->Category)
        _AddCreatureCategoryCooldown(spellInfo->Category, time(NULL));

    m_GlobalCooldown = spellInfo->StartRecoveryTime;
}

bool Creature::HasCategoryCooldown(uint32 spell_id) const
{
    SpellEntry const *spellInfo = sSpellStore.LookupEntry(spell_id);
    if(!spellInfo)
        return false;

    // check global cooldown if spell affected by it
    if (spellInfo->StartRecoveryCategory > 0 && m_GlobalCooldown > 0)
        return true;

    CreatureSpellCooldowns::const_iterator itr = m_CreatureCategoryCooldowns.find(spellInfo->Category);
    return(itr != m_CreatureCategoryCooldowns.end() && time_t(itr->second + (spellInfo->CategoryRecoveryTime / IN_MILISECONDS)) > time(NULL));
}

bool Creature::HasSpellCooldown(uint32 spell_id) const
{
    CreatureSpellCooldowns::const_iterator itr = m_CreatureSpellCooldowns.find(spell_id);
    return (itr != m_CreatureSpellCooldowns.end() && itr->second > time(NULL)) || HasCategoryCooldown(spell_id);
}

bool Creature::HasSpell(uint32 spellID) const
{
    uint8 i;
    for (i = 0; i < CREATURE_MAX_SPELLS; ++i)
        if(spellID == m_spells[i])
            break;
    return i < CREATURE_MAX_SPELLS;                         //broke before end of iteration of known spells
}

time_t Creature::GetRespawnTimeEx() const
{
    time_t now = time(NULL);
    if(m_respawnTime > now)                                 // dead (no corpse)
        return m_respawnTime;
    else if(m_deathTimer > 0)                               // dead (corpse)
        return now+m_respawnDelay+m_deathTimer/IN_MILISECONDS;
    else
        return now;
}

void Creature::GetRespawnCoord( float &x, float &y, float &z, float* ori, float* dist ) const
{
    if (m_DBTableGuid)
    {
        if (CreatureData const* data = objmgr.GetCreatureData(GetDBTableGUIDLow()))
        {
            x = data->posX;
            y = data->posY;
            z = data->posZ;
            if(ori)
                *ori = data->orientation;
            if(dist)
                *dist = data->spawndist;

            return;
        }
    }

    x = GetPositionX();
    y = GetPositionY();
    z = GetPositionZ();
    if(ori)
        *ori = GetOrientation();
    if(dist)
        *dist = 0;
}

void Creature::AllLootRemovedFromCorpse()
{
    if (!HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_SKINNABLE))
    {
        uint32 nDeathTimer;

        CreatureInfo const *cinfo = GetCreatureInfo();

        // corpse was not skinnable -> apply corpse looted timer
        if (!cinfo || !cinfo->SkinLootId)
            nDeathTimer = (uint32)((m_corpseDelay * IN_MILISECONDS) * sWorld.getRate(RATE_CORPSE_DECAY_LOOTED));
        // corpse skinnable, but without skinning flag, and then skinned, corpse will despawn next update
        else
            nDeathTimer = 0;

        // update death timer only if looted timer is shorter
        if (m_deathTimer > nDeathTimer)
            m_deathTimer = nDeathTimer;
    }
}

uint32 Creature::getLevelForTarget( Unit const* target ) const
{
    if(!isWorldBoss())
        return Unit::getLevelForTarget(target);

    uint32 level = target->getLevel()+sWorld.getConfig(CONFIG_WORLD_BOSS_LEVEL_DIFF);
    if(level < 1)
        return 1;
    if(level > 255)
        return 255;
    return level;
}

std::string Creature::GetAIName() const
{
    return ObjectMgr::GetCreatureTemplate(GetEntry())->AIName;
}

std::string Creature::GetScriptName() const
{
    return objmgr.GetScriptName(GetScriptId());
}

uint32 Creature::GetScriptId() const
{
    return ObjectMgr::GetCreatureTemplate(GetEntry())->ScriptID;
}

VendorItemData const* Creature::GetVendorItems() const
{
    return objmgr.GetNpcVendorItemList(GetEntry());
}

uint32 Creature::GetVendorItemCurrentCount(VendorItem const* vItem)
{
    if(!vItem->maxcount)
        return vItem->maxcount;

    VendorItemCounts::iterator itr = m_vendorItemCounts.begin();
    for (; itr != m_vendorItemCounts.end(); ++itr)
        if(itr->itemId==vItem->item)
            break;

    if(itr == m_vendorItemCounts.end())
        return vItem->maxcount;

    VendorItemCount* vCount = &*itr;

    time_t ptime = time(NULL);

    if( vCount->lastIncrementTime + vItem->incrtime <= ptime )
    {
        ItemPrototype const* pProto = objmgr.GetItemPrototype(vItem->item);

        uint32 diff = uint32((ptime - vCount->lastIncrementTime)/vItem->incrtime);
        if((vCount->count + diff * pProto->BuyCount) >= vItem->maxcount )
        {
            m_vendorItemCounts.erase(itr);
            return vItem->maxcount;
        }

        vCount->count += diff * pProto->BuyCount;
        vCount->lastIncrementTime = ptime;
    }

    return vCount->count;
}

uint32 Creature::UpdateVendorItemCurrentCount(VendorItem const* vItem, uint32 used_count)
{
    if(!vItem->maxcount)
        return 0;

    VendorItemCounts::iterator itr = m_vendorItemCounts.begin();
    for (; itr != m_vendorItemCounts.end(); ++itr)
        if(itr->itemId==vItem->item)
            break;

    if(itr == m_vendorItemCounts.end())
    {
        uint32 new_count = vItem->maxcount > used_count ? vItem->maxcount-used_count : 0;
        m_vendorItemCounts.push_back(VendorItemCount(vItem->item,new_count));
        return new_count;
    }

    VendorItemCount* vCount = &*itr;

    time_t ptime = time(NULL);

    if( vCount->lastIncrementTime + vItem->incrtime <= ptime )
    {
        ItemPrototype const* pProto = objmgr.GetItemPrototype(vItem->item);

        uint32 diff = uint32((ptime - vCount->lastIncrementTime)/vItem->incrtime);
        if((vCount->count + diff * pProto->BuyCount) < vItem->maxcount )
            vCount->count += diff * pProto->BuyCount;
        else
            vCount->count = vItem->maxcount;
    }

    vCount->count = vCount->count > used_count ? vCount->count-used_count : 0;
    vCount->lastIncrementTime = ptime;
    return vCount->count;
}

TrainerSpellData const* Creature::GetTrainerSpells() const
{
    return objmgr.GetNpcTrainerSpells(GetEntry());
}

// overwrite WorldObject function for proper name localization
const char* Creature::GetNameForLocaleIdx(int32 loc_idx) const
{
    if (loc_idx >= 0)
    {
        CreatureLocale const *cl = objmgr.GetCreatureLocale(GetEntry());
        if (cl)
        {
            if (cl->Name.size() > loc_idx && !cl->Name[loc_idx].empty())
                return cl->Name[loc_idx].c_str();
        }
    }

    return GetName();
}

const CreatureData* Creature::GetLinkedRespawnCreatureData() const
{
    if(!m_DBTableGuid) // only hard-spawned creatures from DB can have a linked master
        return NULL;

    if(uint32 targetGuid = objmgr.GetLinkedRespawnGuid(m_DBTableGuid))
        return objmgr.GetCreatureData(targetGuid);

    return NULL;
}

// returns master's remaining respawn time if any
time_t Creature::GetLinkedCreatureRespawnTime() const
{
    if(!m_DBTableGuid) // only hard-spawned creatures from DB can have a linked master
        return 0;

    if(uint32 targetGuid = objmgr.GetLinkedRespawnGuid(m_DBTableGuid))
    {
        Map* targetMap = NULL;
        if(const CreatureData* data = objmgr.GetCreatureData(targetGuid))
        {
            if(data->mapid == GetMapId())   // look up on the same map
                targetMap = GetMap();
            else                            // it shouldn't be instanceable map here
                targetMap = MapManager::Instance().FindMap(data->mapid);
        }
        if(targetMap)
            return objmgr.GetCreatureRespawnTime(targetGuid,targetMap->GetInstanceId());
    }

    return 0;
}

