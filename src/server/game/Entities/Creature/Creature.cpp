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

#include "Common.h"
#include "DatabaseEnv.h"
#include "WorldPacket.h"
#include "World.h"
#include "ObjectMgr.h"
#include "SpellMgr.h"
#include "Creature.h"
#include "QuestDef.h"
#include "GossipDef.h"
#include "Player.h"
#include "PoolMgr.h"
#include "Opcodes.h"
#include "Log.h"
#include "LootMgr.h"
#include "MapManager.h"
#include "CreatureAI.h"
#include "CreatureAISelector.h"
#include "Formulas.h"
#include "WaypointMovementGenerator.h"
#include "InstanceScript.h"
#include "BattlegroundMgr.h"
#include "Util.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "CellImpl.h"
#include "OutdoorPvPMgr.h"
#include "GameEventMgr.h"
#include "CreatureGroups.h"
#include "Vehicle.h"
#include "SpellAuraEffects.h"
// apply implementation of the singletons


TrainerSpell const* TrainerSpellData::Find(uint32 spell_id) const
{
    TrainerSpellMap::const_iterator itr = spellList.find(spell_id);
    if (itr != spellList.end())
        return &itr->second;

    return NULL;
}

bool VendorItemData::RemoveItem(uint32 item_id)
{
    bool found = false;
    for (VendorItemList::iterator i = m_items.begin(); i != m_items.end();)
    {
        if ((*i)->item == item_id)
        {
            i = m_items.erase(i++);
            found = true;
        }
        else
            ++i;
    }
    return found;
}

VendorItem const* VendorItemData::FindItemCostPair(uint32 item_id, uint32 extendedCost) const
{
    for (VendorItemList::const_iterator i = m_items.begin(); i != m_items.end(); ++i)
        if((*i)->item == item_id && (*i)->ExtendedCost == extendedCost)
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
    if (Modelid1) return Modelid1;
    if (Modelid2) return Modelid2;
    if (Modelid3) return Modelid3;
    if (Modelid4) return Modelid4;
    return 0;
}

bool AssistDelayEvent::Execute(uint64 /*e_time*/, uint32 /*p_time*/)
{
    if (Unit* victim = Unit::GetUnit(m_owner, m_victim))
    {
        while (!m_assistants.empty())
        {
            Creature* assistant = Unit::GetCreature(m_owner, *m_assistants.begin());
            m_assistants.pop_front();

            if (assistant && assistant->CanAssistTo(&m_owner, victim))
            {
                assistant->SetNoCallAssistance(true);
                assistant->CombatStart(victim);
                if (assistant->IsAIEnabled)
                    assistant->AI()->AttackStart(victim);
            }
        }
    }
    return true;
}

CreatureBaseStats const* CreatureBaseStats::GetBaseStats(uint8 level, uint8 unitClass)
{
    return sObjectMgr.GetCreatureBaseStats(level, unitClass);
}

bool ForcedDespawnDelayEvent::Execute(uint64 /*e_time*/, uint32 /*p_time*/)
{
    m_owner.ForcedDespawn();
    return true;
}

Creature::Creature(): Unit(),
lootForPickPocketed(false), lootForBody(false), m_groupLootTimer(0), lootingGroupLowGUID(0),
m_PlayerDamageReq(0), m_lootMoney(0), m_lootRecipient(0), m_lootRecipientGroup(0), m_corpseRemoveTime(0), m_respawnTime(0),
m_respawnDelay(300), m_corpseDelay(60), m_respawnradius(0.0f), m_reactState(REACT_AGGRESSIVE),
m_defaultMovementType(IDLE_MOTION_TYPE), m_DBTableGuid(0), m_equipmentId(0), m_AlreadyCallAssistance(false),
m_AlreadySearchedAssistance(false), m_regenHealth(true), m_AI_locked(false), m_isDeadByDefault(false),
m_meleeDamageSchoolMask(SPELL_SCHOOL_MASK_NORMAL), m_creatureInfo(NULL), m_creatureData(NULL),
m_formation(NULL)
{
    m_regenTimer = CREATURE_REGEN_INTERVAL;
    m_valuesCount = UNIT_END;

    for (uint8 i = 0; i < CREATURE_MAX_SPELLS; ++i)
        m_spells[i] = 0;

    m_CreatureSpellCooldowns.clear();
    m_CreatureCategoryCooldowns.clear();
    m_GlobalCooldown = 0;
    DisableReputationGain = false;
    //m_unit_movement_flags = MONSTER_MOVE_WALK;

    m_SightDistance = sWorld.getFloatConfig(CONFIG_SIGHT_MONSTER);
    m_CombatDistance = 0;//MELEE_RANGE;

    ResetLootMode(); // restore default loot mode
}

Creature::~Creature()
{
    m_vendorItemCounts.clear();

    delete i_AI;
    i_AI = NULL;

    //if (m_uint32Values)
    //    sLog.outError("Deconstruct Creature Entry = %u", GetEntry());
}

void Creature::AddToWorld()
{
    ///- Register the creature for guid lookup
    if (!IsInWorld())
    {
        if (m_zoneScript)
            m_zoneScript->OnCreatureCreate(this, true);
        sObjectAccessor.AddObject(this);
        Unit::AddToWorld();
        SearchFormation();
        AIM_Initialize();
        if (IsVehicle())
            GetVehicleKit()->Install();
    }
}

void Creature::RemoveFromWorld()
{
    if (IsInWorld())
    {
        if (m_zoneScript)
            m_zoneScript->OnCreatureCreate(this, false);
        if (m_formation)
            formation_mgr.RemoveCreatureFromGroup(m_formation, this);
        Unit::RemoveFromWorld();
        sObjectAccessor.RemoveObject(this);
    }
}

void Creature::DisappearAndDie()
{
    DestroyForNearbyPlayers();
    //SetVisibility(VISIBILITY_OFF);
    //ObjectAccessor::UpdateObjectVisibility(this);
    if (isAlive())
        setDeathState(JUST_DIED);
    RemoveCorpse(false);
}

void Creature::SearchFormation()
{
    if (isSummon())
        return;

    uint32 lowguid = GetDBTableGUIDLow();
    if (!lowguid)
        return;

    CreatureGroupInfoType::iterator frmdata = CreatureGroupMap.find(lowguid);
    if (frmdata != CreatureGroupMap.end())
        formation_mgr.AddCreatureToGroup(frmdata->second->leaderGUID, this);
}

void Creature::RemoveCorpse(bool setSpawnTime)
{
    if ((getDeathState() != CORPSE && !m_isDeadByDefault) || (getDeathState() != ALIVE && m_isDeadByDefault))
        return;

    m_corpseRemoveTime = time(NULL);
    setDeathState(DEAD);
    UpdateObjectVisibility();
    loot.clear();
    uint32 respawnDelay = m_respawnDelay;
    if (IsAIEnabled)
        AI()->CorpseRemoved(respawnDelay);

    // Should get removed later, just keep "compatibility" with scripts
    if(setSpawnTime)
        m_respawnTime = time(NULL) + respawnDelay;

    float x,y,z,o;
    GetRespawnCoord(x, y, z, &o);
    SetHomePosition(x,y,z,o);
    GetMap()->CreatureRelocation(this,x,y,z,o);
}

/**
 * change the entry of creature until respawn
 */
bool Creature::InitEntry(uint32 Entry, uint32 /*team*/, const CreatureData *data)
{
    CreatureInfo const *normalInfo = sObjectMgr.GetCreatureTemplate(Entry);
    if (!normalInfo)
    {
        sLog.outErrorDb("Creature::InitEntry creature entry %u does not exist.", Entry);
        return false;
    }

    // get difficulty 1 mode entry
    uint32 actualEntry = Entry;
    CreatureInfo const *cinfo = normalInfo;
    // TODO correctly implement spawnmodes for non-bg maps
    for (uint32 diff = 0; diff < MAX_DIFFICULTY - 1; ++diff)
    {
        if (normalInfo->DifficultyEntry[diff])
        {
            // we already have valid Map pointer for current creature!
            if (GetMap()->GetSpawnMode() > diff)
            {
                cinfo = sObjectMgr.GetCreatureTemplate(normalInfo->DifficultyEntry[diff]);
                if (!cinfo)
                {
                    // maybe check such things already at startup
                    sLog.outErrorDb("Creature::UpdateEntry creature difficulty %u entry %u does not exist.", diff + 1, actualEntry);
                    return false;
                }
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

    uint32 display_id = sObjectMgr.ChooseDisplayId(0, GetCreatureInfo(), data);
    CreatureModelInfo const *minfo = sObjectMgr.GetCreatureModelRandomGender(display_id);
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
    if (!data || data->equipmentId == 0)
    {                                                       // use default from the template
        LoadEquipment(cinfo->equipmentId);
    }
    else if (data && data->equipmentId != -1)
    {                                                       // override, -1 means no equipment
        LoadEquipment(data->equipmentId);
    }

    SetName(normalInfo->Name);                              // at normal entry always

    SetFloatValue(UNIT_FIELD_BOUNDINGRADIUS,minfo->bounding_radius);
    SetFloatValue(UNIT_FIELD_COMBATREACH,minfo->combat_reach);

    SetFloatValue(UNIT_MOD_CAST_SPEED, 1.0f);

    SetSpeed(MOVE_WALK,     cinfo->speed_walk);
    SetSpeed(MOVE_RUN,      cinfo->speed_run);
    SetSpeed(MOVE_SWIM, 1.0f);      // using 1.0 rate
    SetSpeed(MOVE_FLIGHT, 1.0f);    // using 1.0 rate

    SetFloatValue(OBJECT_FIELD_SCALE_X, cinfo->scale);

    // checked at loading
    m_defaultMovementType = MovementGeneratorType(cinfo->MovementType);
    if (!m_respawnradius && m_defaultMovementType == RANDOM_MOTION_TYPE)
        m_defaultMovementType = IDLE_MOTION_TYPE;

    for (uint8 i=0; i < CREATURE_MAX_SPELLS; ++i)
        m_spells[i] = GetCreatureInfo()->spells[i];

    return true;
}

bool Creature::UpdateEntry(uint32 Entry, uint32 team, const CreatureData *data)
{
    if (!InitEntry(Entry,team,data))
        return false;

    CreatureInfo const* cInfo = GetCreatureInfo();

    m_regenHealth = cInfo->RegenHealth;

    // creatures always have melee weapon ready if any
    SetSheath(SHEATH_STATE_MELEE);

    SelectLevel(GetCreatureInfo());
    if (team == HORDE)
        setFaction(cInfo->faction_H);
    else
        setFaction(cInfo->faction_A);

    uint32 npcflag, unit_flags, dynamicflags;
    ObjectMgr::ChooseCreatureFlags(cInfo, npcflag, unit_flags, dynamicflags, data);

    if (cInfo->flags_extra & CREATURE_FLAG_EXTRA_WORLDEVENT)
        SetUInt32Value(UNIT_NPC_FLAGS, npcflag | sGameEventMgr.GetNPCFlag(this));
    else
        SetUInt32Value(UNIT_NPC_FLAGS, npcflag);

    SetAttackTime(BASE_ATTACK,  cInfo->baseattacktime);
    SetAttackTime(OFF_ATTACK,   cInfo->baseattacktime);
    SetAttackTime(RANGED_ATTACK,cInfo->rangeattacktime);

    SetUInt32Value(UNIT_FIELD_FLAGS, unit_flags);

    SetUInt32Value(UNIT_DYNAMIC_FLAGS, dynamicflags);

    RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IN_COMBAT);

    SetMeleeDamageSchool(SpellSchools(cInfo->dmgschool));
    CreatureBaseStats const* stats = sObjectMgr.GetCreatureBaseStats(getLevel(), cInfo->unit_class);
    float armor = (float)stats->GenerateArmor(cInfo); // TODO: Why is this treated as uint32 when it's a float?
    SetModifierValue(UNIT_MOD_ARMOR,             BASE_VALUE, armor);
    SetModifierValue(UNIT_MOD_RESISTANCE_HOLY,   BASE_VALUE, float(cInfo->resistance1));
    SetModifierValue(UNIT_MOD_RESISTANCE_FIRE,   BASE_VALUE, float(cInfo->resistance2));
    SetModifierValue(UNIT_MOD_RESISTANCE_NATURE, BASE_VALUE, float(cInfo->resistance3));
    SetModifierValue(UNIT_MOD_RESISTANCE_FROST,  BASE_VALUE, float(cInfo->resistance4));
    SetModifierValue(UNIT_MOD_RESISTANCE_SHADOW, BASE_VALUE, float(cInfo->resistance5));
    SetModifierValue(UNIT_MOD_RESISTANCE_ARCANE, BASE_VALUE, float(cInfo->resistance6));

    SetCanModifyStats(true);
    UpdateAllStats();

    // checked and error show at loading templates
    if (FactionTemplateEntry const* factionTemplate = sFactionTemplateStore.LookupEntry(cInfo->faction_A))
    {
        if (factionTemplate->factionFlags & FACTION_TEMPLATE_FLAG_PVP)
            SetPvP(true);
        else
            SetPvP(false);
    }

    // trigger creature is always not selectable and can not be attacked
    if (isTrigger())
        SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

    InitializeReactState();

    if (cInfo->flags_extra & CREATURE_FLAG_EXTRA_NO_TAUNT)
    {
        ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, true);
        ApplySpellImmune(0, IMMUNITY_EFFECT,SPELL_EFFECT_ATTACK_ME, true);
    }

    // TODO: In fact monster move flags should be set - not movement flags.
    if (cInfo->InhabitType & INHABIT_AIR)
        AddUnitMovementFlag(MOVEMENTFLAG_CAN_FLY | MOVEMENTFLAG_FLYING);

    if (cInfo->InhabitType & INHABIT_WATER)
        AddUnitMovementFlag(MOVEMENTFLAG_SWIMMING);

    return true;
}

void Creature::Update(uint32 diff)
{
    if (m_GlobalCooldown <= diff)
        m_GlobalCooldown = 0;
    else
        m_GlobalCooldown -= diff;

    switch(m_deathState)
    {
        case JUST_ALIVED:
            // Don't must be called, see Creature::setDeathState JUST_ALIVED -> ALIVE promoting.
            sLog.outError("Creature (GUID: %u Entry: %u) in wrong state: JUST_ALIVED (4)",GetGUIDLow(),GetEntry());
            break;
        case JUST_DIED:
            // Don't must be called, see Creature::setDeathState JUST_DIED -> CORPSE promoting.
            sLog.outError("Creature (GUID: %u Entry: %u) in wrong state: JUST_DEAD (1)",GetGUIDLow(),GetEntry());
            break;
        case DEAD:
        {
            if (m_respawnTime <= time(NULL))
            {
                if (!GetLinkedCreatureRespawnTime()) // Can respawn
                    Respawn();
                else // the master is dead
                {
                    if (uint32 targetGuid = sObjectMgr.GetLinkedRespawnGuid(m_DBTableGuid))
                    {
                        if (targetGuid == m_DBTableGuid) // if linking self, never respawn (check delayed to next day)
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

            if (m_groupLootTimer && lootingGroupLowGUID)
            {
                // for delayed spells
                m_Events.Update(diff);

                if (m_groupLootTimer <= diff)
                {
                    Group* group = sObjectMgr.GetGroupByGUID(lootingGroupLowGUID);
                    if (group)
                        group->EndRoll(&loot);
                    m_groupLootTimer = 0;
                    lootingGroupLowGUID = 0;
                }
                else m_groupLootTimer -= diff;
            }
            else if (m_corpseRemoveTime <= time(NULL))
            {
                RemoveCorpse(false);
                sLog.outStaticDebug("Removing corpse... %u ", GetUInt32Value(OBJECT_FIELD_ENTRY));
            }
            else
            {
                // for delayed spells
                m_Events.Update(diff);
            }

            break;
        }
        case ALIVE:
        {
            if (m_isDeadByDefault)
            {
                if (m_corpseRemoveTime <= time(NULL))
                {
                    RemoveCorpse(false);
                    sLog.outStaticDebug("Removing alive corpse... %u ", GetUInt32Value(OBJECT_FIELD_ENTRY));
                }
            }

            Unit::Update(diff);

            // creature can be dead after Unit::Update call
            // CORPSE/DEAD state will processed at next tick (in other case death timer will be updated unexpectedly)
            if (!isAlive())
                break;

            // if creature is charmed, switch to charmed AI
            if (NeedChangeAI)
            {
                UpdateCharmAI();
                NeedChangeAI = false;
                IsAIEnabled = true;
            }

            if (!IsInEvadeMode() && IsAIEnabled)
            {
                // do not allow the AI to be changed during update
                m_AI_locked = true;
                i_AI->UpdateAI(diff);
                m_AI_locked = false;
            }

            // creature can be dead after UpdateAI call
            // CORPSE/DEAD state will processed at next tick (in other case death timer will be updated unexpectedly)
            if (!isAlive())
                break;

            if (m_regenTimer > 0)
            {
                if (diff >= m_regenTimer)
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

            /*if (m_regenTimer <= diff)
            {*/
            if (!bInCombat || bIsPolymorphed) // regenerate health if not in combat or if polymorphed
                RegenerateHealth();

            if (getPowerType() == POWER_ENERGY)
            {
                if (!IsVehicle() || GetVehicleKit()->GetVehicleInfo()->m_powerType != POWER_PYRITE)
                    Regenerate(POWER_ENERGY);
            }
            else
                RegenerateMana();

            /*if (!bIsPolymorphed) // only increase the timer if not polymorphed
                    m_regenTimer += CREATURE_REGEN_INTERVAL - diff;
            }
            else
                if (!bIsPolymorphed) // if polymorphed, skip the timer
                    m_regenTimer -= diff;*/
            m_regenTimer = CREATURE_REGEN_INTERVAL;
            break;
        }
        case DEAD_FALLING:
            GetMotionMaster()->UpdateMotion(diff);
            break;
        default:
            break;
    }

    sScriptMgr.OnCreatureUpdate(this, diff);
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
        if (!IsUnderLastManaUseEffect())
        {
            float ManaIncreaseRate = sWorld.getRate(RATE_POWER_MANA);
            float Spirit = GetStat(STAT_SPIRIT);

            addvalue = uint32((Spirit/5.0f + 17.0f) * ManaIncreaseRate);
        }
    }
    else
        addvalue = maxValue/3;

    // Apply modifiers (if any).
    AuraEffectList const& ModPowerRegenPCTAuras = GetAuraEffectsByType(SPELL_AURA_MOD_POWER_REGEN_PERCENT);
    for (AuraEffectList::const_iterator i = ModPowerRegenPCTAuras.begin(); i != ModPowerRegenPCTAuras.end(); ++i)
        if ((*i)->GetMiscValue() == POWER_MANA)
            addvalue = uint32(addvalue * ((*i)->GetAmount() + 100) / 100.0f);

    addvalue += GetTotalAuraModifierByMiscValue(SPELL_AURA_MOD_POWER_REGEN, POWER_MANA) * CREATURE_REGEN_INTERVAL / (5 * IN_MILLISECONDS);

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
    if (GetCharmerOrOwnerGUID())
    {
        float HealthIncreaseRate = sWorld.getRate(RATE_HEALTH);
        float Spirit = GetStat(STAT_SPIRIT);

        if (GetPower(POWER_MANA) > 0)
            addvalue = uint32(Spirit * 0.25 * HealthIncreaseRate);
        else
            addvalue = uint32(Spirit * 0.80 * HealthIncreaseRate);
    }
    else
        addvalue = maxValue/3;

    // Apply modifiers (if any).
    AuraEffectList const& ModPowerRegenPCTAuras = GetAuraEffectsByType(SPELL_AURA_MOD_HEALTH_REGEN_PERCENT);
    for (AuraEffectList::const_iterator i = ModPowerRegenPCTAuras.begin(); i != ModPowerRegenPCTAuras.end(); ++i)
        addvalue = uint32(addvalue * ((*i)->GetAmount() + 100) / 100.0f);

    addvalue += GetTotalAuraModifier(SPELL_AURA_MOD_REGEN) * CREATURE_REGEN_INTERVAL  / (5 * IN_MILLISECONDS);

    ModifyHealth(addvalue);
}

void Creature::DoFleeToGetAssistance()
{
    if (!getVictim())
        return;

    if (HasAuraType(SPELL_AURA_PREVENTS_FLEEING))
        return;

    float radius = sWorld.getFloatConfig(CONFIG_CREATURE_FAMILY_FLEE_ASSISTANCE_RADIUS);
    if (radius >0)
    {
        Creature* pCreature = NULL;

        CellPair p(Trinity::ComputeCellPair(GetPositionX(), GetPositionY()));
        Cell cell(p);
        cell.data.Part.reserved = ALL_DISTRICT;
        cell.SetNoCreate();
        Trinity::NearestAssistCreatureInCreatureRangeCheck u_check(this, getVictim(), radius);
        Trinity::CreatureLastSearcher<Trinity::NearestAssistCreatureInCreatureRangeCheck> searcher(this, pCreature, u_check);

        TypeContainerVisitor<Trinity::CreatureLastSearcher<Trinity::NearestAssistCreatureInCreatureRangeCheck>, GridTypeMapContainer > grid_creature_searcher(searcher);

        cell.Visit(p, grid_creature_searcher, *GetMap(), *this, radius);

        SetNoSearchAssistance(true);
        UpdateSpeed(MOVE_RUN, false);

        if (!pCreature)
            //SetFeared(true, getVictim()->GetGUID(), 0 ,sWorld.getIntConfig(CONFIG_CREATURE_FAMILY_FLEE_DELAY));
            //TODO: use 31365
            SetControlled(true, UNIT_STAT_FLEEING);
        else
            GetMotionMaster()->MoveSeekAssistance(pCreature->GetPositionX(), pCreature->GetPositionY(), pCreature->GetPositionZ());
    }
}

bool Creature::AIM_Initialize(CreatureAI* ai)
{
    // make sure nothing can change the AI during AI update
    if (m_AI_locked)
    {
        sLog.outDebug("AIM_Initialize: failed to init, locked.");
        return false;
    }

    UnitAI *oldAI = i_AI;

    Motion_Initialize();

    i_AI = ai ? ai : FactorySelector::selectAI(this);
    delete oldAI;
    IsAIEnabled = true;
    i_AI->InitializeAI();
    return true;
}

void Creature::Motion_Initialize()
{
    if (!m_formation)
        i_motionMaster.Initialize();
    else if (m_formation->getLeader() == this)
    {
        m_formation->FormationReset(false);
        i_motionMaster.Initialize();
    }
    else if (m_formation->isFormed())
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

    if (!IsPositionValid())
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
                m_corpseDelay = sWorld.getIntConfig(CONFIG_CORPSE_DECAY_RARE);
                break;
            case CREATURE_ELITE_ELITE:
                m_corpseDelay = sWorld.getIntConfig(CONFIG_CORPSE_DECAY_ELITE);
                break;
            case CREATURE_ELITE_RAREELITE:
                m_corpseDelay = sWorld.getIntConfig(CONFIG_CORPSE_DECAY_RAREELITE);
                break;
            case CREATURE_ELITE_WORLDBOSS:
                m_corpseDelay = sWorld.getIntConfig(CONFIG_CORPSE_DECAY_WORLDBOSS);
                break;
            default:
                m_corpseDelay = sWorld.getIntConfig(CONFIG_CORPSE_DECAY_NORMAL);
                break;
        }
        LoadCreaturesAddon();
        CreatureModelInfo const *minfo = sObjectMgr.GetCreatureModelRandomGender(GetNativeDisplayId());
        if (minfo && !isTotem())                               // Cancel load if no model defined or if totem
        {
            uint32 display_id = minfo->modelid;                // it can be different (for another gender)

            SetDisplayId(display_id);
            SetNativeDisplayId(display_id);
            SetByteValue(UNIT_FIELD_BYTES_0, 2, minfo->gender);
        }

        if (GetCreatureInfo()->InhabitType & INHABIT_AIR)
        {
            if (GetDefaultMovementType() == IDLE_MOTION_TYPE)
                AddUnitMovementFlag(MOVEMENTFLAG_CAN_FLY);
            else
                SetFlying(true);
        }

        if (GetCreatureInfo()->InhabitType & INHABIT_WATER)
        {
            AddUnitMovementFlag(MOVEMENTFLAG_SWIMMING);
        }
        LastUsedScriptID = GetCreatureInfo()->ScriptID;
    }

    return bResult;
}

bool Creature::isCanTrainingOf(Player* pPlayer, bool msg) const
{
    if (!isTrainer())
        return false;

    TrainerSpellData const* trainer_spells = GetTrainerSpells();

    if ((!trainer_spells || trainer_spells->spellList.empty()) && GetCreatureInfo()->trainer_type != TRAINER_TYPE_PETS)
    {
        sLog.outErrorDb("Creature %u (Entry: %u) have UNIT_NPC_FLAG_TRAINER but have empty trainer spell list.",
            GetGUIDLow(),GetEntry());
        return false;
    }

    switch(GetCreatureInfo()->trainer_type)
    {
        case TRAINER_TYPE_CLASS:
            if (pPlayer->getClass() != GetCreatureInfo()->trainer_class)
            {
                if (msg)
                {
                    pPlayer->PlayerTalkClass->ClearMenus();
                    switch(GetCreatureInfo()->trainer_class)
                    {
                        case CLASS_DRUID:  pPlayer->PlayerTalkClass->SendGossipMenu(4913,GetGUID()); break;
                        case CLASS_HUNTER: pPlayer->PlayerTalkClass->SendGossipMenu(10090,GetGUID()); break;
                        case CLASS_MAGE:   pPlayer->PlayerTalkClass->SendGossipMenu(328,GetGUID()); break;
                        case CLASS_PALADIN:pPlayer->PlayerTalkClass->SendGossipMenu(1635,GetGUID()); break;
                        case CLASS_PRIEST: pPlayer->PlayerTalkClass->SendGossipMenu(4436,GetGUID()); break;
                        case CLASS_ROGUE:  pPlayer->PlayerTalkClass->SendGossipMenu(4797,GetGUID()); break;
                        case CLASS_SHAMAN: pPlayer->PlayerTalkClass->SendGossipMenu(5003,GetGUID()); break;
                        case CLASS_WARLOCK:pPlayer->PlayerTalkClass->SendGossipMenu(5836,GetGUID()); break;
                        case CLASS_WARRIOR:pPlayer->PlayerTalkClass->SendGossipMenu(4985,GetGUID()); break;
                    }
                }
                return false;
            }
            break;
        case TRAINER_TYPE_PETS:
            if (pPlayer->getClass() != CLASS_HUNTER)
            {
                pPlayer->PlayerTalkClass->ClearMenus();
                pPlayer->PlayerTalkClass->SendGossipMenu(3620,GetGUID());
                return false;
            }
            break;
        case TRAINER_TYPE_MOUNTS:
            if (GetCreatureInfo()->trainer_race && pPlayer->getRace() != GetCreatureInfo()->trainer_race)
            {
                if (msg)
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
                        case RACE_UNDEAD_PLAYER:pPlayer->PlayerTalkClass->SendGossipMenu(624,GetGUID()); break;
                        case RACE_BLOODELF:     pPlayer->PlayerTalkClass->SendGossipMenu(5862,GetGUID()); break;
                        case RACE_DRAENEI:      pPlayer->PlayerTalkClass->SendGossipMenu(5864,GetGUID()); break;
                    }
                }
                return false;
            }
            break;
        case TRAINER_TYPE_TRADESKILLS:
            if (GetCreatureInfo()->trainer_spell && !pPlayer->HasSpell(GetCreatureInfo()->trainer_spell))
            {
                if (msg)
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
    if (!isBattleMaster())
        return false;

    BattlegroundTypeId bgTypeId = sBattlegroundMgr.GetBattleMasterBG(GetEntry());
    if (!msg)
        return pPlayer->GetBGAccessByLevel(bgTypeId);

    if (!pPlayer->GetBGAccessByLevel(bgTypeId))
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

void Creature::AI_SendMoveToPacket(float x, float y, float z, uint32 time, uint32 /*MovementFlags*/, uint8 /*type*/)
{
    /*    uint32 timeElap = getMSTime();
        if ((timeElap - m_startMove) < m_moveTime)
        {
            oX = (dX - oX) * ((timeElap - m_startMove) / m_moveTime);
            oY = (dY - oY) * ((timeElap - m_startMove) / m_moveTime);
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
    if (!m_lootRecipient)
        return NULL;
    return ObjectAccessor::FindPlayer(m_lootRecipient);
}

Group *Creature::GetLootRecipientGroup() const
{
    if (!m_lootRecipientGroup)
        return NULL;
    return sObjectMgr.GetGroupByGUID(m_lootRecipientGroup);
}

void Creature::SetLootRecipient(Unit *unit)
{
    // set the player whose group should receive the right
    // to loot the creature after it dies
    // should be set to NULL after the loot disappears

    if (!unit)
    {
        m_lootRecipient = 0;
        m_lootRecipientGroup = 0;
        RemoveFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_LOOTABLE|UNIT_DYNFLAG_TAPPED);
        return;
    }

    if (unit->GetTypeId() != TYPEID_PLAYER && !unit->IsVehicle())
        return;

    Player* player = unit->GetCharmerOrOwnerPlayerOrPlayerItself();
    if (!player)                                             // normal creature, no player involved
        return;

    m_lootRecipient = player->GetGUID();
    if (Group *group = player->GetGroup())
        m_lootRecipientGroup = group->GetLowGUID();

    SetFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_TAPPED);
}

// return true if this creature is tapped by the player or by a member of his group.
bool Creature::isTappedBy(Player *player) const
{
    if (player->GetGUID() == m_lootRecipient)
        return true;

    Group* playerGroup = player->GetGroup();
    if (!playerGroup || playerGroup != GetLootRecipientGroup()) // if we dont have a group we arent the recipient
        return false;                                           // if creature doesnt have group bound it means it was solo killed by someone else

    return true;
}

void Creature::SaveToDB()
{
    // this should only be used when the creature has already been loaded
    // preferably after adding to map, because mapid may not be valid otherwise
    CreatureData const *data = sObjectMgr.GetCreatureData(m_DBTableGuid);
    if (!data)
    {
        sLog.outError("Creature::SaveToDB failed, cannot get creature data!");
        return;
    }

    SaveToDB(GetMapId(), data->spawnMask, GetPhaseMask());
}

void Creature::SaveToDB(uint32 mapid, uint8 spawnMask, uint32 phaseMask)
{
    // update in loaded data
    if (!m_DBTableGuid)
        m_DBTableGuid = GetGUIDLow();
    CreatureData& data = sObjectMgr.NewOrExistCreatureData(m_DBTableGuid);

    uint32 displayId = GetNativeDisplayId();
    uint32 npcflag = GetUInt32Value(UNIT_NPC_FLAGS);
    uint32 unit_flags = GetUInt32Value(UNIT_FIELD_FLAGS);
    uint32 dynamicflags = GetUInt32Value(UNIT_DYNAMIC_FLAGS);

    // check if it's a custom model and if not, use 0 for displayId
    CreatureInfo const *cinfo = GetCreatureInfo();
    if (cinfo)
    {
        if (displayId == cinfo->Modelid1 || displayId == cinfo->Modelid2 ||
            displayId == cinfo->Modelid3 || displayId == cinfo->Modelid4)
            displayId = 0;

        if (npcflag == cinfo->npcflag)
            npcflag = 0;

        if (unit_flags == cinfo->unit_flags)
            unit_flags = 0;

        if (dynamicflags == cinfo->dynamicflags)
            dynamicflags = 0;
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
    data.spawndist = GetDefaultMovementType() == IDLE_MOTION_TYPE ? 0 : m_respawnradius;
    data.currentwaypoint = 0;
    data.curhealth = GetHealth();
    data.curmana = GetPower(POWER_MANA);
    data.is_dead = m_isDeadByDefault;
    // prevent add data integrity problems
    data.movementType = !m_respawnradius && GetDefaultMovementType() == RANDOM_MOTION_TYPE
        ? IDLE_MOTION_TYPE : GetDefaultMovementType();
    data.spawnMask = spawnMask;
    data.npcflag = npcflag;
    data.unit_flags = unit_flags;
    data.dynamicflags = dynamicflags;

    // updated in DB
    SQLTransaction trans = WorldDatabase.BeginTransaction();

    trans->PAppend("DELETE FROM creature WHERE guid = '%u'", m_DBTableGuid);

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
        << GetDefaultMovementType() << ","                  //default movement generator type
        << npcflag << ","
        << unit_flags << ","
        << dynamicflags << ")";

    trans->Append(ss.str().c_str());

    WorldDatabase.CommitTransaction(trans);
}

void Creature::SelectLevel(const CreatureInfo *cinfo)
{
    uint32 rank = isPet()? 0 : cinfo->rank;

    // level
    uint8 minlevel = std::min(cinfo->maxlevel, cinfo->minlevel);
    uint8 maxlevel = std::max(cinfo->maxlevel, cinfo->minlevel);
    uint8 level = minlevel == maxlevel ? minlevel : urand(minlevel, maxlevel);
    SetLevel(level);

    CreatureBaseStats const* stats = sObjectMgr.GetCreatureBaseStats(level, cinfo->unit_class);

    // health
    float healthmod = _GetHealthMod(rank);

    uint32 basehp = stats->GenerateHealth(cinfo);
    uint32 health = uint32(basehp * healthmod);

    SetCreateHealth(health);
    SetMaxHealth(health);
    SetHealth(health);
    ResetPlayerDamageReq();

    // mana
    uint32 mana = stats->GenerateMana(cinfo);

    SetCreateMana(mana);
    SetMaxPower(POWER_MANA, mana);                          //MAX Mana
    SetPower(POWER_MANA, mana);

    // TODO: set UNIT_FIELD_POWER*, for some creature class case (energy, etc)

    SetModifierValue(UNIT_MOD_HEALTH, BASE_VALUE, (float)health);
    SetModifierValue(UNIT_MOD_MANA, BASE_VALUE, (float)mana);

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
    if (m_zoneScript && data)
    {
        Entry = m_zoneScript->GetCreatureEntry(guidlow, data);
        if (!Entry)
            return false;
    }

    CreatureInfo const *cinfo = sObjectMgr.GetCreatureTemplate(Entry);
    if (!cinfo)
    {
        sLog.outErrorDb("Creature entry %u does not exist.", Entry);
        return false;
    }

    SetOriginalEntry(Entry);

    if (!vehId)
        vehId = cinfo->VehicleId;

    if (vehId && !CreateVehicleKit(vehId))
        vehId = 0;

    Object::_Create(guidlow, Entry, vehId ? HIGHGUID_VEHICLE : HIGHGUID_UNIT);

    if (!UpdateEntry(Entry, team, data))
        return false;

    return true;
}

bool Creature::LoadFromDB(uint32 guid, Map *map)
{
    CreatureData const* data = sObjectMgr.GetCreatureData(guid);

    if (!data)
    {
        sLog.outErrorDb("Creature (GUID: %u) not found in table `creature`, can't load. ",guid);
        return false;
    }

    m_DBTableGuid = guid;
    if (map->GetInstanceId() == 0)
    {
        if (map->GetCreature(MAKE_NEW_GUID(guid,data->id,HIGHGUID_UNIT)))
            return false;
    }
    else
        guid = sObjectMgr.GenerateLowGuid(HIGHGUID_UNIT);

    uint16 team = 0;
    if (!Create(guid,map,data->phaseMask,data->id,0,team,data->posX,data->posY,data->posZ,data->orientation,data))
        return false;

    //We should set first home position, because then AI calls home movement
    SetHomePosition(data->posX,data->posY,data->posZ,data->orientation);

    m_respawnradius = data->spawndist;

    m_respawnDelay = data->spawntimesecs;
    m_isDeadByDefault = data->is_dead;
    m_deathState = m_isDeadByDefault ? DEAD : ALIVE;

    m_respawnTime  = sObjectMgr.GetCreatureRespawnTime(m_DBTableGuid,GetInstanceId());
    if (m_respawnTime)                          // respawn on Update
    {
        m_deathState = DEAD;
        if (canFly())
        {
            float tz = map->GetHeight(data->posX,data->posY,data->posZ,false);
            if (data->posZ - tz > 0.1)
                Relocate(data->posX,data->posY,tz);
        }
    }

    uint32 curhealth;

    if (!m_regenHealth)
    {
        curhealth = data->curhealth;
        if (curhealth)
        {
            curhealth = uint32(curhealth*_GetHealthMod(GetCreatureInfo()->rank));
            if (curhealth < 1)
                curhealth = 1;
        }
        SetPower(POWER_MANA,data->curmana);
    }
    else
    {
        curhealth = GetMaxHealth();
        SetPower(POWER_MANA,GetMaxPower(POWER_MANA));
    }

    SetHealth(m_deathState == ALIVE ? curhealth : 0);

    // checked at creature_template loading
    m_defaultMovementType = MovementGeneratorType(data->movementType);

    m_creatureData = data;

    return true;
}

void Creature::LoadEquipment(uint32 equip_entry, bool force)
{
    if (equip_entry == 0)
    {
        if (force)
        {
            for (uint8 i = 0; i < 3; ++i)
                SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + i, 0);
            m_equipmentId = 0;
        }
        return;
    }

    EquipmentInfo const *einfo = sObjectMgr.GetEquipmentInfo(equip_entry);
    if (!einfo)
        return;

    m_equipmentId = equip_entry;
    for (uint8 i = 0; i < 3; ++i)
        SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + i, einfo->equipentry[i]);
}

bool Creature::hasQuest(uint32 quest_id) const
{
    QuestRelationBounds qr = sObjectMgr.GetCreatureQuestRelationBounds(GetEntry());
    for (QuestRelations::const_iterator itr = qr.first; itr != qr.second; ++itr)
    {
        if (itr->second == quest_id)
            return true;
    }
    return false;
}

bool Creature::hasInvolvedQuest(uint32 quest_id) const
{
    QuestRelationBounds qir = sObjectMgr.GetCreatureQuestInvolvedRelationBounds(GetEntry());
    for (QuestRelations::const_iterator itr = qir.first; itr != qir.second; ++itr)
    {
        if (itr->second == quest_id)
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

    sObjectMgr.SaveCreatureRespawnTime(m_DBTableGuid,GetInstanceId(),0);
    sObjectMgr.DeleteCreatureData(m_DBTableGuid);

    SQLTransaction trans = WorldDatabase.BeginTransaction();
    trans->PAppend("DELETE FROM creature WHERE guid = '%u'", m_DBTableGuid);
    trans->PAppend("DELETE FROM creature_addon WHERE guid = '%u'", m_DBTableGuid);
    trans->PAppend("DELETE FROM game_event_creature WHERE guid = '%u'", m_DBTableGuid);
    trans->PAppend("DELETE FROM game_event_model_equip WHERE guid = '%u'", m_DBTableGuid);
    WorldDatabase.CommitTransaction(trans);
}

bool Creature::canSeeOrDetect(Unit const* u, bool detect, bool /*inVisibleList*/, bool /*is3dDistance*/) const
{
    // not in world
    if (!IsInWorld() || !u->IsInWorld())
        return false;

    // all dead creatures/players not visible for any creatures
    if (!u->isAlive() || !isAlive())
        return false;

    // Always can see self
    if (u == this)
        return true;

    // phased visibility (both must phased in same way)
    if (!InSamePhase(u))
        return false;

    // always seen by owner
    if (GetGUID() == u->GetCharmerOrOwnerGUID())
        return true;

    if (u->GetVisibility() == VISIBILITY_OFF) //GM
        return false;

    // invisible aura
    if ((m_invisibilityMask || u->m_invisibilityMask) && !canDetectInvisibilityOf(u))
        return false;

    // unit got in stealth in this moment and must ignore old detected state
    //if (m_Visibility == VISIBILITY_GROUP_NO_DETECT)
    //    return false;

    // GM invisibility checks early, invisibility if any detectable, so if not stealth then visible
    if (u->GetVisibility() == VISIBILITY_GROUP_STEALTH)
    {
        //do not know what is the use of this detect
        if (!detect || !canDetectStealthOf(u, GetDistance(u)))
            return false;
    }

    // Now check is target visible with LoS
    //return u->IsWithinLOS(GetPositionX(),GetPositionY(),GetPositionZ());
    return true;
}

bool Creature::canStartAttack(Unit const* who, bool force) const
{
    if (isCivilian())
        return false;

    if (!canFly() && (GetDistanceZ(who) > CREATURE_Z_ATTACK_RANGE + m_CombatDistance))
        //|| who->IsControlledByPlayer() && who->IsFlying()))
        // we cannot check flying for other creatures, too much map/vmap calculation
        // TODO: should switch to range attack
        return false;

    if (!force)
    {
        if (!_IsTargetAcceptable(who))
            return false;

        if (who->isInCombat())
            if (Unit *victim = who->getAttackerForHelper())
                if (IsWithinDistInMap(victim, sWorld.getFloatConfig(CONFIG_CREATURE_FAMILY_ASSISTANCE_RADIUS)))
                    force = true;

        if (!force && (IsNeutralToAll() || !IsWithinDistInMap(who, GetAttackDistance(who) + m_CombatDistance)))
            return false;
    }

    if (!canCreatureAttack(who, force))
        return false;

    return IsWithinLOSInMap(who);
}

float Creature::GetAttackDistance(Unit const* pl) const
{
    float aggroRate = sWorld.getRate(RATE_CREATURE_AGGRO);
    if (aggroRate == 0)
        return 0.0f;

    uint32 playerlevel   = pl->getLevelForTarget(this);
    uint32 creaturelevel = getLevelForTarget(pl);

    int32 leveldif       = int32(playerlevel) - int32(creaturelevel);

    // "The maximum Aggro Radius has a cap of 25 levels under. Example: A level 30 char has the same Aggro Radius of a level 5 char on a level 60 mob."
    if (leveldif < - 25)
        leveldif = -25;

    // "The aggro radius of a mob having the same level as the player is roughly 20 yards"
    float RetDistance = 20;

    // "Aggro Radius varies with level difference at a rate of roughly 1 yard/level"
    // radius grow if playlevel < creaturelevel
    RetDistance -= (float)leveldif;

    if (creaturelevel+5 <= sWorld.getIntConfig(CONFIG_MAX_PLAYER_LEVEL))
    {
        // detect range auras
        RetDistance += GetTotalAuraModifier(SPELL_AURA_MOD_DETECT_RANGE);

        // detected range auras
        RetDistance += pl->GetTotalAuraModifier(SPELL_AURA_MOD_DETECTED_RANGE);
    }

    // "Minimum Aggro Radius for a mob seems to be combat range (5 yards)"
    if (RetDistance < 5)
        RetDistance = 5;

    return (RetDistance*aggroRate);
}

void Creature::setDeathState(DeathState s)
{
    if ((s == JUST_DIED && !m_isDeadByDefault)||(s == JUST_ALIVED && m_isDeadByDefault))
    {
        m_corpseRemoveTime = time(NULL) + m_corpseDelay;
        m_respawnTime = time(NULL) + m_respawnDelay + m_corpseDelay;

        // always save boss respawn time at death to prevent crash cheating
        if (sWorld.getBoolConfig(CONFIG_SAVE_RESPAWN_TIME_IMMEDIATELY) || isWorldBoss())
            SaveRespawnTime();
    }
    Unit::setDeathState(s);

    if (s == JUST_DIED)
    {
        SetUInt64Value(UNIT_FIELD_TARGET,0);                // remove target selection in any cases (can be set at aura remove in Unit::setDeathState)
        SetUInt32Value(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_NONE);

        setActive(false);

        if (!isPet() && GetCreatureInfo()->SkinLootId)
            if (LootTemplates_Skinning.HaveLootFor(GetCreatureInfo()->SkinLootId))
                if (hasLootRecipient())
                    SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_SKINNABLE);

        if (HasSearchedAssistance())
        {
            SetNoSearchAssistance(false);
            UpdateSpeed(MOVE_RUN, false);
        }

        //Dismiss group if is leader
        if (m_formation && m_formation->getLeader() == this)
            m_formation->FormationReset(true);

        if ((canFly() || IsFlying()) && FallGround())
            return;

        Unit::setDeathState(CORPSE);
    }
    else if (s == JUST_ALIVED)
    {
        //if (isPet())
        //    setActive(true);
        SetFullHealth();
        SetLootRecipient(NULL);
        ResetPlayerDamageReq();
        CreatureInfo const *cinfo = GetCreatureInfo();
        AddUnitMovementFlag(MOVEMENTFLAG_WALKING);
        if (GetCreatureInfo()->InhabitType & INHABIT_AIR)
            AddUnitMovementFlag(MOVEMENTFLAG_CAN_FLY | MOVEMENTFLAG_FLYING);
        if (GetCreatureInfo()->InhabitType & INHABIT_WATER)
            AddUnitMovementFlag(MOVEMENTFLAG_SWIMMING);
        SetUInt32Value(UNIT_NPC_FLAGS, cinfo->npcflag);
        clearUnitState(UNIT_STAT_ALL_STATE);
        SetMeleeDamageSchool(SpellSchools(cinfo->dmgschool));
        LoadCreaturesAddon(true);
        Motion_Initialize();
        if (GetCreatureData() && GetPhaseMask() != GetCreatureData()->phaseMask)
            SetPhaseMask(GetCreatureData()->phaseMask, false);
        if (m_vehicleKit) m_vehicleKit->Reset();
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
    // use larger distance for vmap height search than in most other cases
    float ground_Z = GetMap()->GetHeight(x, y, z, true, MAX_FALL_DISTANCE);
    if (fabs(ground_Z - z) < 0.1f)
        return false;

    GetMotionMaster()->MoveFall(ground_Z, EVENT_FALL_GROUND);
    Unit::setDeathState(DEAD_FALLING);
    return true;
}

void Creature::Respawn(bool force)
{
    DestroyForNearbyPlayers();

    if (force)
    {
        if (isAlive())
            setDeathState(JUST_DIED);
        else if (getDeathState() != CORPSE)
            setDeathState(CORPSE);
    }

    RemoveCorpse(false);

    if (getDeathState() == DEAD)
    {
        if (m_DBTableGuid)
            sObjectMgr.SaveCreatureRespawnTime(m_DBTableGuid,GetInstanceId(),0);

        sLog.outStaticDebug("Respawning...");
        m_respawnTime = 0;
        lootForPickPocketed = false;
        lootForBody         = false;

        if (m_originalEntry != GetEntry())
            UpdateEntry(m_originalEntry);

        CreatureInfo const *cinfo = GetCreatureInfo();
        SelectLevel(cinfo);

        if (m_isDeadByDefault)
        {
            setDeathState(JUST_DIED);
            i_motionMaster.Clear();
            clearUnitState(UNIT_STAT_ALL_STATE);
            LoadCreaturesAddon(true);
        }
        else
            setDeathState(JUST_ALIVED);

        CreatureModelInfo const *minfo = sObjectMgr.GetCreatureModelRandomGender(GetNativeDisplayId());
        if (minfo)                                             // Cancel load if no model defined
        {
            uint32 display_id = minfo->modelid;                // it can be different (for another gender)

            SetDisplayId(display_id);
            SetNativeDisplayId(display_id);
            SetByteValue(UNIT_FIELD_BYTES_0, 2, minfo->gender);
        }

        GetMotionMaster()->InitDefault();

        //Call AI respawn virtual function
        if (IsAIEnabled)
            AI()->JustRespawned();

        uint32 poolid = GetDBTableGUIDLow() ? sPoolMgr.IsPartOfAPool<Creature>(GetDBTableGUIDLow()) : 0;
        if (poolid)
            sPoolMgr.UpdatePool<Creature>(poolid, GetDBTableGUIDLow());

        //Re-initialize reactstate that could be altered by movementgenerators
        InitializeReactState();
    }

    UpdateObjectVisibility();
}

void Creature::ForcedDespawn(uint32 timeMSToDespawn)
{
    if (timeMSToDespawn)
    {
        ForcedDespawnDelayEvent *pEvent = new ForcedDespawnDelayEvent(*this);

        m_Events.AddEvent(pEvent, m_Events.CalculateTime(timeMSToDespawn));
        return;
    }

    if (isAlive())
        setDeathState(JUST_DIED);

    RemoveCorpse(false);
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

    if (GetCreatureInfo()->type == CREATURE_TYPE_MECHANICAL && spellInfo->Effect[index] == SPELL_EFFECT_HEAL)
        return true;

    return Unit::IsImmunedToSpellEffect(spellInfo, index);
}

SpellEntry const *Creature::reachWithSpellAttack(Unit *pVictim)
{
    if (!pVictim)
        return NULL;

    for (uint32 i=0; i < CREATURE_MAX_SPELLS; ++i)
    {
        if (!m_spells[i])
            continue;
        SpellEntry const *spellInfo = sSpellStore.LookupEntry(m_spells[i]);
        if (!spellInfo)
        {
            sLog.outError("WORLD: unknown spell id %i", m_spells[i]);
            continue;
        }

        bool bcontinue = true;
        for (uint32 j = 0; j < MAX_SPELL_EFFECTS; j++)
        {
            if ((spellInfo->Effect[j] == SPELL_EFFECT_SCHOOL_DAMAGE)       ||
                (spellInfo->Effect[j] == SPELL_EFFECT_INSTAKILL)            ||
                (spellInfo->Effect[j] == SPELL_EFFECT_ENVIRONMENTAL_DAMAGE) ||
                (spellInfo->Effect[j] == SPELL_EFFECT_HEALTH_LEECH)
)
            {
                bcontinue = false;
                break;
            }
        }
        if (bcontinue) continue;

        if (spellInfo->manaCost > GetPower(POWER_MANA))
            continue;
        SpellRangeEntry const* srange = sSpellRangeStore.LookupEntry(spellInfo->rangeIndex);
        float range = GetSpellMaxRangeForHostile(srange);
        float minrange = GetSpellMinRangeForHostile(srange);
        float dist = GetDistance(pVictim);
        //if (!isInFront(pVictim, range) && spellInfo->AttributesEx)
        //    continue;
        if (dist > range || dist < minrange)
            continue;
        if (spellInfo->PreventionType == SPELL_PREVENTION_TYPE_SILENCE && HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_SILENCED))
            continue;
        if (spellInfo->PreventionType == SPELL_PREVENTION_TYPE_PACIFY && HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PACIFIED))
            continue;
        return spellInfo;
    }
    return NULL;
}

SpellEntry const *Creature::reachWithSpellCure(Unit *pVictim)
{
    if (!pVictim)
        return NULL;

    for (uint32 i=0; i < CREATURE_MAX_SPELLS; ++i)
    {
        if (!m_spells[i])
            continue;
        SpellEntry const *spellInfo = sSpellStore.LookupEntry(m_spells[i]);
        if (!spellInfo)
        {
            sLog.outError("WORLD: unknown spell id %i", m_spells[i]);
            continue;
        }

        bool bcontinue = true;
        for (uint32 j = 0; j < MAX_SPELL_EFFECTS; j++)
        {
            if ((spellInfo->Effect[j] == SPELL_EFFECT_HEAL))
            {
                bcontinue = false;
                break;
            }
        }
        if (bcontinue) continue;

        if (spellInfo->manaCost > GetPower(POWER_MANA))
            continue;
        SpellRangeEntry const* srange = sSpellRangeStore.LookupEntry(spellInfo->rangeIndex);
        float range = GetSpellMaxRangeForFriend(srange);
        float minrange = GetSpellMinRangeForFriend(srange);
        float dist = GetDistance(pVictim);
        //if (!isInFront(pVictim, range) && spellInfo->AttributesEx)
        //    continue;
        if (dist > range || dist < minrange)
            continue;
        if (spellInfo->PreventionType == SPELL_PREVENTION_TYPE_SILENCE && HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_SILENCED))
            continue;
        if (spellInfo->PreventionType == SPELL_PREVENTION_TYPE_PACIFY && HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PACIFIED))
            continue;
        return spellInfo;
    }
    return NULL;
}

bool Creature::IsVisibleInGridForPlayer(Player const* pl) const
{
    // gamemaster in GM mode see all, including ghosts
    if (pl->isGameMaster())
        return true;

    // Trigger shouldn't be visible for players
    //if (isTrigger())
    //    return false;
    // Rat: this makes no sense, triggers are always sent to players, but with invisible model and can not be attacked or targeted!

    // Live player (or with not release body see live creatures or death creatures with corpse disappearing time > 0
    if (pl->isAlive() || pl->GetDeathTimer() > 0)
    {
        if (GetEntry() == VISUAL_WAYPOINT)
            return false;
        return (isAlive() || m_corpseRemoveTime > time(NULL) || (m_isDeadByDefault && m_deathState == CORPSE));
    }

    // Dead player see creatures near own corpse
    Corpse *corpse = pl->GetCorpse();
    if (corpse)
    {
        // 20 - aggro distance for same level, 25 - max additional distance if player level less that creature level
        if (corpse->IsWithinDistInMap(this,(20+25)*sWorld.getRate(RATE_CREATURE_AGGRO)))
            return true;
    }

    // Dead player see Spirit Healer or Spirit Guide
    if (isSpiritService())
        return true;

    // and not see any other
    return false;
}


// select nearest hostile unit within the given distance (regardless of threat list).
Unit* Creature::SelectNearestTarget(float dist) const
{
    CellPair p(Trinity::ComputeCellPair(GetPositionX(), GetPositionY()));
    Cell cell(p);
    cell.data.Part.reserved = ALL_DISTRICT;
    cell.SetNoCreate();

    Unit *target = NULL;

    {
        if (dist == 0.0f || dist > MAX_VISIBILITY_DISTANCE)
            dist = MAX_VISIBILITY_DISTANCE;

        Trinity::NearestHostileUnitCheck u_check(this, dist);
        Trinity::UnitLastSearcher<Trinity::NearestHostileUnitCheck> searcher(this, target, u_check);

        TypeContainerVisitor<Trinity::UnitLastSearcher<Trinity::NearestHostileUnitCheck>, WorldTypeMapContainer > world_unit_searcher(searcher);
        TypeContainerVisitor<Trinity::UnitLastSearcher<Trinity::NearestHostileUnitCheck>, GridTypeMapContainer >  grid_unit_searcher(searcher);

        cell.Visit(p, world_unit_searcher, *GetMap(), *this, dist);
        cell.Visit(p, grid_unit_searcher, *GetMap(), *this, dist);
    }

    return target;
}

// select nearest hostile unit within the given attack distance (i.e. distance is ignored if > than ATTACK_DISTANCE), regardless of threat list.
Unit* Creature::SelectNearestTargetInAttackDistance(float dist) const
{
    CellPair p(Trinity::ComputeCellPair(GetPositionX(), GetPositionY()));
    Cell cell(p);
    cell.data.Part.reserved = ALL_DISTRICT;
    cell.SetNoCreate();

    Unit *target = NULL;

    if (dist > ATTACK_DISTANCE)
        sLog.outError("Creature (GUID: %u Entry: %u) SelectNearestTargetInAttackDistance called with dist > ATTACK_DISTANCE. Extra distance ignored.",GetGUIDLow(),GetEntry());

    {
        Trinity::NearestHostileUnitInAttackDistanceCheck u_check(this, dist);
        Trinity::UnitLastSearcher<Trinity::NearestHostileUnitInAttackDistanceCheck> searcher(this, target, u_check);

        TypeContainerVisitor<Trinity::UnitLastSearcher<Trinity::NearestHostileUnitInAttackDistanceCheck>, WorldTypeMapContainer > world_unit_searcher(searcher);
        TypeContainerVisitor<Trinity::UnitLastSearcher<Trinity::NearestHostileUnitInAttackDistanceCheck>, GridTypeMapContainer >  grid_unit_searcher(searcher);

        cell.Visit(p, world_unit_searcher, *GetMap(), *this, ATTACK_DISTANCE);
        cell.Visit(p, grid_unit_searcher, *GetMap(), *this, ATTACK_DISTANCE);
    }

    return target;
}

void Creature::SendAIReaction(AiReaction reactionType)
{
    WorldPacket data(SMSG_AI_REACTION, 12);

    data << uint64(GetGUID());
    data << uint32(reactionType);

    ((WorldObject*)this)->SendMessageToSet(&data, true);

    sLog.outDebug("WORLD: Sent SMSG_AI_REACTION, type %u.", reactionType);
}

void Creature::CallAssistance()
{
    if (!m_AlreadyCallAssistance && getVictim() && !isPet() && !isCharmed())
    {
        SetNoCallAssistance(true);

        float radius = sWorld.getFloatConfig(CONFIG_CREATURE_FAMILY_ASSISTANCE_RADIUS);

        if (radius > 0)
        {
            std::list<Creature*> assistList;

            {
                CellPair p(Trinity::ComputeCellPair(GetPositionX(), GetPositionY()));
                Cell cell(p);
                cell.data.Part.reserved = ALL_DISTRICT;
                cell.SetNoCreate();

                Trinity::AnyAssistCreatureInRangeCheck u_check(this, getVictim(), radius);
                Trinity::CreatureListSearcher<Trinity::AnyAssistCreatureInRangeCheck> searcher(this, assistList, u_check);

                TypeContainerVisitor<Trinity::CreatureListSearcher<Trinity::AnyAssistCreatureInRangeCheck>, GridTypeMapContainer >  grid_creature_searcher(searcher);

                cell.Visit(p, grid_creature_searcher, *GetMap(), *this, radius);
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
                m_Events.AddEvent(e, m_Events.CalculateTime(sWorld.getIntConfig(CONFIG_CREATURE_FAMILY_ASSISTANCE_DELAY)));
            }
        }
    }
}

void Creature::CallForHelp(float fRadius)
{
    if (fRadius <= 0.0f || !getVictim() || isPet() || isCharmed())
        return;

    CellPair p(Trinity::ComputeCellPair(GetPositionX(), GetPositionY()));
    Cell cell(p);
    cell.data.Part.reserved = ALL_DISTRICT;
    cell.SetNoCreate();

    Trinity::CallOfHelpCreatureInRangeDo u_do(this, getVictim(), fRadius);
    Trinity::CreatureWorker<Trinity::CallOfHelpCreatureInRangeDo> worker(this, u_do);

    TypeContainerVisitor<Trinity::CreatureWorker<Trinity::CallOfHelpCreatureInRangeDo>, GridTypeMapContainer >  grid_creature_searcher(worker);

    cell.Visit(p, grid_creature_searcher, *GetMap(), *this, fRadius);
}

bool Creature::CanAssistTo(const Unit* u, const Unit* enemy, bool checkfaction /*= true*/) const
{
    // is it true?
    if (!HasReactState(REACT_AGGRESSIVE))
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
    ASSERT(target);

    // if the target cannot be attacked, the target is not acceptable
    if (IsFriendlyTo(target)
        || !target->isAttackableByAOE()
        || target->hasUnitState(UNIT_STAT_DIED)
        || (m_vehicle && (IsOnVehicle(target) || m_vehicle->GetBase()->IsOnVehicle(target))))
        return false;

    const Unit *myVictim = getAttackerForHelper();
    const Unit *targetVictim = target->getAttackerForHelper();

    // if I'm already fighting target, or I'm hostile towards the target, the target is acceptable
    if (myVictim == target || targetVictim == this || IsHostileTo(target))
        return true;

    // if the target's victim is friendly, and the target is neutral, the target is acceptable
    if (targetVictim && IsFriendlyTo(targetVictim))
        return true;

    // if the target's victim is not friendly, or the target is friendly, the target is not acceptable
    return false;
}

void Creature::SaveRespawnTime()
{
    if (isSummon() || !m_DBTableGuid || (m_creatureData && !m_creatureData->dbData))
        return;

    sObjectMgr.SaveCreatureRespawnTime(m_DBTableGuid,GetInstanceId(),m_respawnTime);
}

// this should not be called by petAI or
bool Creature::canCreatureAttack(Unit const *pVictim, bool force) const
{
    if (!pVictim->IsInMap(this))
        return false;

    if (!canAttack(pVictim, force))
        return false;

    if (!pVictim->isInAccessiblePlaceFor(this))
        return false;

    if (IsAIEnabled && !AI()->CanAIAttack(pVictim))
        return false;

    if (sMapStore.LookupEntry(GetMapId())->IsDungeon())
        return true;

    //Use AttackDistance in distance check if threat radius is lower. This prevents creature bounce in and out of combat every update tick.
    float dist = std::max(GetAttackDistance(pVictim), sWorld.getFloatConfig(CONFIG_THREAT_RADIUS)) + m_CombatDistance;

    if (Unit *unit = GetCharmerOrOwner())
        return pVictim->IsWithinDist(unit, dist);
    else
        return pVictim->IsInDist(&m_homePosition, dist);
}

CreatureDataAddon const* Creature::GetCreatureAddon() const
{
    if (m_DBTableGuid)
    {
        if (CreatureDataAddon const* addon = ObjectMgr::GetCreatureAddon(m_DBTableGuid))
            return addon;
    }

    // dependent from difficulty mode entry
    return ObjectMgr::GetCreatureTemplateAddon(GetCreatureInfo()->Entry);
}

//creature_addon table
bool Creature::LoadCreaturesAddon(bool reload)
{
    CreatureDataAddon const *cainfo = GetCreatureAddon();
    if (!cainfo)
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
        //SetByteValue(UNIT_FIELD_BYTES_2, 1, uint8((cainfo->bytes2 >> 8) & 0xFF));
        //SetByteValue(UNIT_FIELD_BYTES_2, 2, uint8((cainfo->bytes2 >> 16) & 0xFF));
        SetByteValue(UNIT_FIELD_BYTES_2, 2, 0);
        //SetByteValue(UNIT_FIELD_BYTES_2, 3, uint8((cainfo->bytes2 >> 24) & 0xFF));
        SetByteValue(UNIT_FIELD_BYTES_2, 3, 0);
    }

    if (cainfo->emote != 0)
        SetUInt32Value(UNIT_NPC_EMOTESTATE, cainfo->emote);

    //Load Path
    if (cainfo->path_id != 0)
        m_path_id = cainfo->path_id;

    if (cainfo->auras)
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
            if (HasAura(cAura->spell_id))
            {
                if (!reload)
                    sLog.outErrorDb("Creature (GUID: %u Entry: %u) has duplicate aura (spell %u) in `auras` field.",GetGUIDLow(),GetEntry(),cAura->spell_id);

                continue;
            }

            AddAura(AdditionalSpellInfo, cAura->effectMask, this);
            sLog.outDebug("Spell: %u with AuraEffectMask %u added to creature (GUID: %u Entry: %u)", cAura->spell_id, cAura->effectMask,GetGUIDLow(),GetEntry());
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
    sWorld.SendGlobalMessage(&data,NULL,(enemy_team == ALLIANCE ? HORDE : ALLIANCE));
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
                this->SetInCombatWith(pPlayer);
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
    if (!spellInfo)
        return;

    uint32 cooldown = GetSpellRecoveryTime(spellInfo);
    if (Player *modOwner = GetSpellModOwner())
        modOwner->ApplySpellMod(spellid, SPELLMOD_COOLDOWN, cooldown);

    if (cooldown)
        _AddCreatureSpellCooldown(spellid, time(NULL) + cooldown/IN_MILLISECONDS);

    if (spellInfo->Category)
        _AddCreatureCategoryCooldown(spellInfo->Category, time(NULL));

    m_GlobalCooldown = spellInfo->StartRecoveryTime;
}

bool Creature::HasCategoryCooldown(uint32 spell_id) const
{
    SpellEntry const *spellInfo = sSpellStore.LookupEntry(spell_id);
    if (!spellInfo)
        return false;

    // check global cooldown if spell affected by it
    if (spellInfo->StartRecoveryCategory > 0 && m_GlobalCooldown > 0)
        return true;

    CreatureSpellCooldowns::const_iterator itr = m_CreatureCategoryCooldowns.find(spellInfo->Category);
    return(itr != m_CreatureCategoryCooldowns.end() && time_t(itr->second + (spellInfo->CategoryRecoveryTime / IN_MILLISECONDS)) > time(NULL));
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
        if (spellID == m_spells[i])
            break;
    return i < CREATURE_MAX_SPELLS;                         //broke before end of iteration of known spells
}

time_t Creature::GetRespawnTimeEx() const
{
    time_t now = time(NULL);
    if (m_respawnTime > now)
        return m_respawnTime;
    else
        return now;
}

void Creature::GetRespawnCoord(float &x, float &y, float &z, float* ori, float* dist) const
{
    if (m_DBTableGuid)
    {
        if (CreatureData const* data = sObjectMgr.GetCreatureData(GetDBTableGUIDLow()))
        {
            x = data->posX;
            y = data->posY;
            z = data->posZ;
            if (ori)
                *ori = data->orientation;
            if (dist)
                *dist = data->spawndist;

            return;
        }
    }

    x = GetPositionX();
    y = GetPositionY();
    z = GetPositionZ();
    if (ori)
        *ori = GetOrientation();
    if (dist)
        *dist = 0;
}

void Creature::AllLootRemovedFromCorpse()
{
    if (!HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_SKINNABLE))
    {
        time_t now = time(NULL);
        if(m_corpseRemoveTime <= now)
            return;

        float decayRate;
        CreatureInfo const *cinfo = GetCreatureInfo();

        decayRate = sWorld.getRate(RATE_CORPSE_DECAY_LOOTED);
        uint32 diff = uint32((m_corpseRemoveTime - now) * decayRate);

        m_respawnTime -= diff;

        // corpse skinnable, but without skinning flag, and then skinned, corpse will despawn next update
        if (cinfo && cinfo->SkinLootId)
            m_corpseRemoveTime = time(NULL);
        else
            m_corpseRemoveTime -= diff;
    }
}

uint8 Creature::getLevelForTarget(Unit const* target) const
{
    if (!isWorldBoss())
        return Unit::getLevelForTarget(target);

    uint16 level = target->getLevel() + sWorld.getIntConfig(CONFIG_WORLD_BOSS_LEVEL_DIFF);
    if (level < 1)
        return 1;
    if (level > 255)
        return 255;
    return uint8(level);
}

std::string Creature::GetAIName() const
{
    return ObjectMgr::GetCreatureTemplate(GetEntry())->AIName;
}

std::string Creature::GetScriptName() const
{
    return sObjectMgr.GetScriptName(GetScriptId());
}

uint32 Creature::GetScriptId() const
{
    return ObjectMgr::GetCreatureTemplate(GetEntry())->ScriptID;
}

VendorItemData const* Creature::GetVendorItems() const
{
    return sObjectMgr.GetNpcVendorItemList(GetEntry());
}

uint32 Creature::GetVendorItemCurrentCount(VendorItem const* vItem)
{
    if (!vItem->maxcount)
        return vItem->maxcount;

    VendorItemCounts::iterator itr = m_vendorItemCounts.begin();
    for (; itr != m_vendorItemCounts.end(); ++itr)
        if (itr->itemId == vItem->item)
            break;

    if (itr == m_vendorItemCounts.end())
        return vItem->maxcount;

    VendorItemCount* vCount = &*itr;

    time_t ptime = time(NULL);

    if (time_t(vCount->lastIncrementTime + vItem->incrtime) <= ptime)
    {
        ItemPrototype const* pProto = sObjectMgr.GetItemPrototype(vItem->item);

        uint32 diff = uint32((ptime - vCount->lastIncrementTime)/vItem->incrtime);
        if ((vCount->count + diff * pProto->BuyCount) >= vItem->maxcount)
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
    if (!vItem->maxcount)
        return 0;

    VendorItemCounts::iterator itr = m_vendorItemCounts.begin();
    for (; itr != m_vendorItemCounts.end(); ++itr)
        if (itr->itemId == vItem->item)
            break;

    if (itr == m_vendorItemCounts.end())
    {
        uint32 new_count = vItem->maxcount > used_count ? vItem->maxcount-used_count : 0;
        m_vendorItemCounts.push_back(VendorItemCount(vItem->item,new_count));
        return new_count;
    }

    VendorItemCount* vCount = &*itr;

    time_t ptime = time(NULL);

    if (time_t(vCount->lastIncrementTime + vItem->incrtime) <= ptime)
    {
        ItemPrototype const* pProto = sObjectMgr.GetItemPrototype(vItem->item);

        uint32 diff = uint32((ptime - vCount->lastIncrementTime)/vItem->incrtime);
        if ((vCount->count + diff * pProto->BuyCount) < vItem->maxcount)
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
    return sObjectMgr.GetNpcTrainerSpells(GetEntry());
}

// overwrite WorldObject function for proper name localization
const char* Creature::GetNameForLocaleIdx(LocaleConstant loc_idx) const
{
    if (loc_idx != DEFAULT_LOCALE)
    {
        uint8 uloc_idx = uint8(loc_idx);
        CreatureLocale const *cl = sObjectMgr.GetCreatureLocale(GetEntry());
        if (cl)
        {
            if (cl->Name.size() > uloc_idx && !cl->Name[uloc_idx].empty())
                return cl->Name[uloc_idx].c_str();
        }
    }

    return GetName();
}

const CreatureData* Creature::GetLinkedRespawnCreatureData() const
{
    if (!m_DBTableGuid) // only hard-spawned creatures from DB can have a linked master
        return NULL;

    if (uint32 targetGuid = sObjectMgr.GetLinkedRespawnGuid(m_DBTableGuid))
        return sObjectMgr.GetCreatureData(targetGuid);

    return NULL;
}

// returns master's remaining respawn time if any
time_t Creature::GetLinkedCreatureRespawnTime() const
{
    if (!m_DBTableGuid) // only hard-spawned creatures from DB can have a linked master
        return 0;

    if (uint32 targetGuid = sObjectMgr.GetLinkedRespawnGuid(m_DBTableGuid))
    {
        Map* targetMap = NULL;
        if (const CreatureData* data = sObjectMgr.GetCreatureData(targetGuid))
        {
            if (data->mapid == GetMapId())   // look up on the same map
                targetMap = GetMap();
            else                            // it shouldn't be instanceable map here
                targetMap = sMapMgr.FindMap(data->mapid);
        }
        if (targetMap)
            return sObjectMgr.GetCreatureRespawnTime(targetGuid,targetMap->GetInstanceId());
    }

    return 0;
}

void Creature::FarTeleportTo(Map* map, float X, float Y, float Z, float O)
{
    InterruptNonMeleeSpells(true);
    CombatStop();
    ClearComboPointHolders();
    DeleteThreatList();
    GetMotionMaster()->Clear(false);
    DestroyForNearbyPlayers();

    RemoveFromWorld();
    ResetMap();
    SetMap(map);
    AddToWorld();
    
    SetPosition(X, Y, Z, O, true);
}
