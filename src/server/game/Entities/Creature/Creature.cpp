/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#include "Creature.h"
#include "BattlegroundMgr.h"
#include "CellImpl.h"
#include "CombatPackets.h"
#include "Common.h"
#include "CreatureAI.h"
#include "CreatureAISelector.h"
#include "CreatureGroups.h"
#include "DatabaseEnv.h"
#include "Formulas.h"
#include "GameEventMgr.h"
#include "GossipDef.h"
#include "GridNotifiersImpl.h"
#include "Group.h"
#include "GroupMgr.h"
#include "InstanceScript.h"
#include "Log.h"
#include "LootMgr.h"
#include "MiscPackets.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "PhasingHandler.h"
#include "Player.h"
#include "PoolMgr.h"
#include "QuestDef.h"
#include "ScriptedGossip.h"
#include "SpellAuraEffects.h"
#include "SpellMgr.h"
#include "TemporarySummon.h"
#include "Transport.h"
#include "Util.h"
#include "Vehicle.h"
#include "World.h"
#include "WorldPacket.h"
#include <G3D/g3dmath.h>

bool VendorItem::IsGoldRequired(ItemTemplate const* pProto) const
{
    return pProto->GetFlags2() & ITEM_FLAG2_DONT_IGNORE_BUY_PRICE || !ExtendedCost;
}

bool VendorItemData::RemoveItem(uint32 item_id, uint8 type)
{
    auto newEnd = std::remove_if(m_items.begin(), m_items.end(), [=](VendorItem const& vendorItem)
    {
        return vendorItem.item == item_id && vendorItem.Type == type;
    });
    bool found = newEnd != m_items.end();
    m_items.erase(newEnd, m_items.end());
    return found;
}

VendorItem const* VendorItemData::FindItemCostPair(uint32 item_id, uint32 extendedCost, uint8 type) const
{
    for (VendorItem const& vendorItem : m_items)
        if (vendorItem.item == item_id && vendorItem.ExtendedCost == extendedCost && vendorItem.Type == type)
            return &vendorItem;
    return nullptr;
}

uint32 CreatureTemplate::GetRandomValidModelId() const
{
    uint8 c = 0;
    uint32 modelIDs[4];

    if (Modelid1) modelIDs[c++] = Modelid1;
    if (Modelid2) modelIDs[c++] = Modelid2;
    if (Modelid3) modelIDs[c++] = Modelid3;
    if (Modelid4) modelIDs[c++] = Modelid4;

    return ((c>0) ? modelIDs[urand(0, c-1)] : 0);
}

uint32 CreatureTemplate::GetFirstValidModelId() const
{
    if (Modelid1) return Modelid1;
    if (Modelid2) return Modelid2;
    if (Modelid3) return Modelid3;
    if (Modelid4) return Modelid4;
    return 0;
}

uint32 CreatureTemplate::GetFirstInvisibleModel() const
{
    CreatureModelInfo const* modelInfo = sObjectMgr->GetCreatureModelInfo(Modelid1);
    if (modelInfo && modelInfo->is_trigger)
        return Modelid1;

    modelInfo = sObjectMgr->GetCreatureModelInfo(Modelid2);
    if (modelInfo && modelInfo->is_trigger)
        return Modelid2;

    modelInfo = sObjectMgr->GetCreatureModelInfo(Modelid3);
    if (modelInfo && modelInfo->is_trigger)
        return Modelid3;

    modelInfo = sObjectMgr->GetCreatureModelInfo(Modelid4);
    if (modelInfo && modelInfo->is_trigger)
        return Modelid4;

    return 11686;
}

uint32 CreatureTemplate::GetFirstVisibleModel() const
{
    CreatureModelInfo const* modelInfo = sObjectMgr->GetCreatureModelInfo(Modelid1);
    if (modelInfo && !modelInfo->is_trigger)
        return Modelid1;

    modelInfo = sObjectMgr->GetCreatureModelInfo(Modelid2);
    if (modelInfo && !modelInfo->is_trigger)
        return Modelid2;

    modelInfo = sObjectMgr->GetCreatureModelInfo(Modelid3);
    if (modelInfo && !modelInfo->is_trigger)
        return Modelid3;

    modelInfo = sObjectMgr->GetCreatureModelInfo(Modelid4);
    if (modelInfo && !modelInfo->is_trigger)
        return Modelid4;

    return 17519;
}

bool AssistDelayEvent::Execute(uint64 /*e_time*/, uint32 /*p_time*/)
{
    if (Unit* victim = ObjectAccessor::GetUnit(m_owner, m_victim))
    {
        while (!m_assistants.empty())
        {
            Creature* assistant = ObjectAccessor::GetCreature(m_owner, *m_assistants.begin());
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
    return sObjectMgr->GetCreatureBaseStats(level, unitClass);
}

bool ForcedDespawnDelayEvent::Execute(uint64 /*e_time*/, uint32 /*p_time*/)
{
    m_owner.DespawnOrUnsummon(0, m_respawnTimer);    // since we are here, we are not TempSummon as object type cannot change during runtime
    return true;
}

Creature::Creature(bool isWorldObject): Unit(isWorldObject), MapObject(),
m_groupLootTimer(0), m_PlayerDamageReq(0),
_pickpocketLootRestore(0), m_corpseRemoveTime(0), m_respawnTime(0),
m_respawnDelay(300), m_corpseDelay(60), m_respawnradius(0.0f), m_boundaryCheckTime(2500), m_combatPulseTime(0), m_combatPulseDelay(0), m_reactState(REACT_AGGRESSIVE),
m_defaultMovementType(IDLE_MOTION_TYPE), m_spawnId(UI64LIT(0)), m_equipmentId(0), m_originalEquipmentId(0), m_AlreadyCallAssistance(false),
m_AlreadySearchedAssistance(false), m_regenHealth(true), m_cannotReachTarget(false), m_cannotReachTimer(0), m_AI_locked(false), m_meleeDamageSchoolMask(SPELL_SCHOOL_MASK_NORMAL),
m_originalEntry(0), m_homePosition(), m_transportHomePosition(), m_creatureInfo(nullptr), m_creatureData(nullptr), m_waypointID(0), m_path_id(0), m_formation(nullptr), m_focusSpell(nullptr), m_focusDelay(0), m_shouldReacquireTarget(false), m_suppressedOrientation(0.0f)
{
    m_regenTimer = CREATURE_REGEN_INTERVAL;
    m_valuesCount = UNIT_END;
    _dynamicValuesCount = UNIT_DYNAMIC_END;

    for (uint8 i = 0; i < MAX_CREATURE_SPELLS; ++i)
        m_spells[i] = 0;

    DisableReputationGain = false;

    m_SightDistance = sWorld->getFloatConfig(CONFIG_SIGHT_MONSTER);
    m_CombatDistance = 0;//MELEE_RANGE;

    ResetLootMode(); // restore default loot mode
    m_TriggerJustRespawned = false;
    m_isTempWorldObject = false;
}

Creature::~Creature()
{
    delete i_AI;
    i_AI = nullptr;

    //if (m_uint32Values)
    //    TC_LOG_ERROR("entities.unit", "Deconstruct Creature Entry = %u", GetEntry());
}

void Creature::AddToWorld()
{
    ///- Register the creature for guid lookup
    if (!IsInWorld())
    {
        if (GetZoneScript())
            GetZoneScript()->OnCreatureCreate(this);

        GetMap()->GetObjectsStore().Insert<Creature>(GetGUID(), this);
        if (m_spawnId)
            GetMap()->GetCreatureBySpawnIdStore().insert(std::make_pair(m_spawnId, this));

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
        if (GetZoneScript())
            GetZoneScript()->OnCreatureRemove(this);

        if (m_formation)
            sFormationMgr->RemoveCreatureFromGroup(m_formation, this);

        Unit::RemoveFromWorld();

        if (m_spawnId)
            Trinity::Containers::MultimapErasePair(GetMap()->GetCreatureBySpawnIdStore(), m_spawnId, this);
        GetMap()->GetObjectsStore().Remove<Creature>(GetGUID());
    }
}

void Creature::DisappearAndDie()
{
    DestroyForNearbyPlayers();
    //SetVisibility(VISIBILITY_OFF);
    //ObjectAccessor::UpdateObjectVisibility(this);
    if (IsAlive())
        setDeathState(JUST_DIED);
    RemoveCorpse(false);
}

void Creature::SearchFormation()
{
    if (IsSummon())
        return;

    ObjectGuid::LowType lowguid = GetSpawnId();
    if (!lowguid)
        return;

    CreatureGroupInfoType::iterator frmdata = sFormationMgr->CreatureGroupMap.find(lowguid);
    if (frmdata != sFormationMgr->CreatureGroupMap.end())
        sFormationMgr->AddCreatureToGroup(frmdata->second->leaderGUID, this);
}

void Creature::RemoveCorpse(bool setSpawnTime)
{
    if (getDeathState() != CORPSE)
        return;

    m_corpseRemoveTime = time(NULL);
    setDeathState(DEAD);
    RemoveAllAuras();
    UpdateObjectVisibility();
    loot.clear();
    uint32 respawnDelay = m_respawnDelay;
    if (IsAIEnabled)
        AI()->CorpseRemoved(respawnDelay);

    // Should get removed later, just keep "compatibility" with scripts
    if (setSpawnTime)
        m_respawnTime = time(NULL) + respawnDelay;

    float x, y, z, o;
    GetRespawnPosition(x, y, z, &o);
    SetHomePosition(x, y, z, o);
    GetMap()->CreatureRelocation(this, x, y, z, o);
}

/**
 * change the entry of creature until respawn
 */
bool Creature::InitEntry(uint32 entry, CreatureData const* data /*= nullptr*/)
{
    CreatureTemplate const* normalInfo = sObjectMgr->GetCreatureTemplate(entry);
    if (!normalInfo)
    {
        TC_LOG_ERROR("sql.sql", "Creature::InitEntry creature entry %u does not exist.", entry);
        return false;
    }

    // get difficulty 1 mode entry
    CreatureTemplate const* cinfo = nullptr;
    DifficultyEntry const* difficultyEntry = sDifficultyStore.LookupEntry(GetMap()->GetSpawnMode());
    while (!cinfo && difficultyEntry)
    {
        int32 idx = CreatureTemplate::DifficultyIDToDifficultyEntryIndex(difficultyEntry->ID);
        if (idx == -1)
            break;

        if (normalInfo->DifficultyEntry[idx])
        {
            cinfo = sObjectMgr->GetCreatureTemplate(normalInfo->DifficultyEntry[idx]);
            break;
        }

        if (!difficultyEntry->FallbackDifficultyID)
            break;

        difficultyEntry = sDifficultyStore.LookupEntry(difficultyEntry->FallbackDifficultyID);
    }

    if (!cinfo)
        cinfo = normalInfo;

    // Initialize loot duplicate count depending on raid difficulty
    if (GetMap()->Is25ManRaid())
        loot.maxDuplicates = 3;

    SetEntry(entry);                                        // normal entry always
    m_creatureInfo = cinfo;                                 // map mode related always

    // equal to player Race field, but creature does not have race
    SetByteValue(UNIT_FIELD_BYTES_0, UNIT_BYTES_0_OFFSET_RACE, 0);

    // known valid are: CLASS_WARRIOR, CLASS_PALADIN, CLASS_ROGUE, CLASS_MAGE
    SetByteValue(UNIT_FIELD_BYTES_0, UNIT_BYTES_0_OFFSET_CLASS, uint8(cinfo->unit_class));

    // Cancel load if no model defined
    if (!(cinfo->GetFirstValidModelId()))
    {
        TC_LOG_ERROR("sql.sql", "Creature (Entry: %u) has no model defined in table `creature_template`, can't load. ", entry);
        return false;
    }

    uint32 displayID = ObjectMgr::ChooseDisplayId(GetCreatureTemplate(), data);
    CreatureModelInfo const* minfo = sObjectMgr->GetCreatureModelRandomGender(&displayID);
    if (!minfo)                                             // Cancel load if no model defined
    {
        TC_LOG_ERROR("sql.sql", "Creature (Entry: %u) has invalid model %u defined in table `creature_template`, can't load.", entry, displayID);
        return false;
    }

    SetDisplayId(displayID);
    SetNativeDisplayId(displayID);
    SetByteValue(UNIT_FIELD_BYTES_0, UNIT_BYTES_0_OFFSET_GENDER, minfo->gender);

    // Load creature equipment
    if (!data || data->equipmentId == 0)
        LoadEquipment(); // use default equipment (if available)
    else if (data && data->equipmentId != 0)                // override, 0 means no equipment
    {
        m_originalEquipmentId = data->equipmentId;
        LoadEquipment(data->equipmentId);
    }

    SetName(normalInfo->Name);                              // at normal entry always

    SetFloatValue(UNIT_MOD_CAST_SPEED, 1.0f);
    SetFloatValue(UNIT_MOD_CAST_HASTE, 1.0f);
    SetFloatValue(UNIT_FIELD_MOD_HASTE, 1.0f);
    SetFloatValue(UNIT_FIELD_MOD_RANGED_HASTE, 1.0f);
    SetFloatValue(UNIT_FIELD_MOD_HASTE_REGEN, 1.0f);
    SetFloatValue(UNIT_FIELD_MOD_TIME_RATE, 1.0f);

    SetSpeedRate(MOVE_WALK,   cinfo->speed_walk);
    SetSpeedRate(MOVE_RUN,    cinfo->speed_run);
    SetSpeedRate(MOVE_SWIM,   1.0f); // using 1.0 rate
    SetSpeedRate(MOVE_FLIGHT, 1.0f); // using 1.0 rate

    // Will set UNIT_FIELD_BOUNDINGRADIUS and UNIT_FIELD_COMBATREACH
    SetObjectScale(cinfo->scale);

    SetFloatValue(UNIT_FIELD_HOVERHEIGHT, cinfo->HoverHeight);

    // checked at loading
    m_defaultMovementType = MovementGeneratorType(cinfo->MovementType);
    if (!m_respawnradius && m_defaultMovementType == RANDOM_MOTION_TYPE)
        m_defaultMovementType = IDLE_MOTION_TYPE;

    for (uint8 i=0; i < MAX_CREATURE_SPELLS; ++i)
        m_spells[i] = GetCreatureTemplate()->spells[i];

    return true;
}

bool Creature::UpdateEntry(uint32 entry, CreatureData const* data /*= nullptr*/, bool updateLevel /* = true */)
{
    if (!InitEntry(entry, data))
        return false;

    CreatureTemplate const* cInfo = GetCreatureTemplate();

    m_regenHealth = cInfo->RegenHealth;

    // creatures always have melee weapon ready if any unless specified otherwise
    if (!GetCreatureAddon())
        SetSheath(SHEATH_STATE_MELEE);

    setFaction(cInfo->faction);

    uint64 npcFlags;
    uint32 unitFlags, unitFlags2, unitFlags3, dynamicFlags;
    ObjectMgr::ChooseCreatureFlags(cInfo, npcFlags, unitFlags, unitFlags2, unitFlags3, dynamicFlags, data);

    if (cInfo->flags_extra & CREATURE_FLAG_EXTRA_WORLDEVENT)
        SetUInt64Value(UNIT_NPC_FLAGS, npcFlags | sGameEventMgr->GetNPCFlag(this));
    else
        SetUInt64Value(UNIT_NPC_FLAGS, npcFlags);

    SetUInt32Value(UNIT_FIELD_FLAGS, unitFlags);
    SetUInt32Value(UNIT_FIELD_FLAGS_2, unitFlags2);
    SetUInt32Value(UNIT_FIELD_FLAGS_3, unitFlags3);

    SetUInt32Value(OBJECT_DYNAMIC_FLAGS, dynamicFlags);

    RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IN_COMBAT);

    SetBaseAttackTime(BASE_ATTACK,   cInfo->BaseAttackTime);
    SetBaseAttackTime(OFF_ATTACK,    cInfo->BaseAttackTime);
    SetBaseAttackTime(RANGED_ATTACK, cInfo->RangeAttackTime);

    if (updateLevel)
        SelectLevel();
    else
        UpdateLevelDependantStats(); // We still re-initialize level dependant stats on entry update

    SetMeleeDamageSchool(SpellSchools(cInfo->dmgschool));
    SetModifierValue(UNIT_MOD_RESISTANCE_HOLY,   BASE_VALUE, float(cInfo->resistance[SPELL_SCHOOL_HOLY]));
    SetModifierValue(UNIT_MOD_RESISTANCE_FIRE,   BASE_VALUE, float(cInfo->resistance[SPELL_SCHOOL_FIRE]));
    SetModifierValue(UNIT_MOD_RESISTANCE_NATURE, BASE_VALUE, float(cInfo->resistance[SPELL_SCHOOL_NATURE]));
    SetModifierValue(UNIT_MOD_RESISTANCE_FROST,  BASE_VALUE, float(cInfo->resistance[SPELL_SCHOOL_FROST]));
    SetModifierValue(UNIT_MOD_RESISTANCE_SHADOW, BASE_VALUE, float(cInfo->resistance[SPELL_SCHOOL_SHADOW]));
    SetModifierValue(UNIT_MOD_RESISTANCE_ARCANE, BASE_VALUE, float(cInfo->resistance[SPELL_SCHOOL_ARCANE]));

    SetCanModifyStats(true);
    UpdateAllStats();

    // checked and error show at loading templates
    if (FactionTemplateEntry const* factionTemplate = sFactionTemplateStore.LookupEntry(cInfo->faction))
    {
        if (factionTemplate->Flags & FACTION_TEMPLATE_FLAG_PVP)
            SetPvP(true);
        else
            SetPvP(false);
    }

    // updates spell bars for vehicles and set player's faction - should be called here, to overwrite faction that is set from the new template
    if (IsVehicle())
    {
        if (Player* owner = Creature::GetCharmerOrOwnerPlayerOrPlayerItself()) // this check comes in case we don't have a player
        {
            setFaction(owner->getFaction()); // vehicles should have same as owner faction
            owner->VehicleSpellInitialize();
        }
    }

    // trigger creature is always not selectable and can not be attacked
    if (IsTrigger())
        SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

    InitializeReactState();

    if (cInfo->flags_extra & CREATURE_FLAG_EXTRA_NO_TAUNT)
    {
        ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, true);
        ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_ATTACK_ME, true);
    }

    if (cInfo->InhabitType & INHABIT_ROOT)
        SetControlled(true, UNIT_STATE_ROOT);

    UpdateMovementFlags();
    LoadCreaturesAddon();
    return true;
}

void Creature::Update(uint32 diff)
{
    if (IsAIEnabled && m_TriggerJustRespawned)
    {
        m_TriggerJustRespawned = false;
        AI()->JustRespawned();
        if (m_vehicleKit)
            m_vehicleKit->Reset();
    }

    UpdateMovementFlags();

    switch (m_deathState)
    {
        case JUST_RESPAWNED:
            // Must not be called, see Creature::setDeathState JUST_RESPAWNED -> ALIVE promoting.
            TC_LOG_ERROR("entities.unit", "Creature (%s) in wrong state: JUST_RESPAWNED (4)", GetGUID().ToString().c_str());
            break;
        case JUST_DIED:
            // Must not be called, see Creature::setDeathState JUST_DIED -> CORPSE promoting.
            TC_LOG_ERROR("entities.unit", "Creature (%s) in wrong state: JUST_DEAD (1)", GetGUID().ToString().c_str());
            break;
        case DEAD:
        {
            time_t now = time(NULL);
            if (m_respawnTime <= now)
            {
                // First check if there are any scripts that object to us respawning
                if (!sScriptMgr->CanSpawn(GetSpawnId(), GetEntry(), GetCreatureTemplate(), GetCreatureData(), GetMap()))
                    break; // Will be rechecked on next Update call

                ObjectGuid dbtableHighGuid = ObjectGuid::Create<HighGuid::Creature>(GetMapId(), GetEntry(), m_spawnId);
                time_t linkedRespawntime = GetMap()->GetLinkedRespawnTime(dbtableHighGuid);
                if (!linkedRespawntime)             // Can respawn
                    Respawn();
                else                                // the master is dead
                {
                    ObjectGuid targetGuid = sObjectMgr->GetLinkedRespawnGuid(dbtableHighGuid);
                    if (targetGuid == dbtableHighGuid) // if linking self, never respawn (check delayed to next day)
                        SetRespawnTime(DAY);
                    else
                        m_respawnTime = (now > linkedRespawntime ? now : linkedRespawntime) + urand(5, MINUTE); // else copy time from master and add a little
                    SaveRespawnTime(); // also save to DB immediately
                }
            }
            break;
        }
        case CORPSE:
        {
            Unit::Update(diff);
            // deathstate changed on spells update, prevent problems
            if (m_deathState != CORPSE)
                break;

            if (m_groupLootTimer && !lootingGroupLowGUID.IsEmpty())
            {
                if (m_groupLootTimer <= diff)
                {
                    if (Group* group = sGroupMgr->GetGroupByGUID(lootingGroupLowGUID))
                        group->EndRoll(&loot);

                    m_groupLootTimer = 0;
                    lootingGroupLowGUID.Clear();
                }
                else
                    m_groupLootTimer -= diff;
            }
            else if (m_corpseRemoveTime <= time(NULL))
            {
                RemoveCorpse(false);
                TC_LOG_DEBUG("entities.unit", "Removing corpse... %u ", GetUInt32Value(OBJECT_FIELD_ENTRY));
            }
            break;
        }
        case ALIVE:
        {
            Unit::Update(diff);

            // creature can be dead after Unit::Update call
            // CORPSE/DEAD state will processed at next tick (in other case death timer will be updated unexpectedly)
            if (!IsAlive())
                break;

            if (m_shouldReacquireTarget && !IsFocusing(nullptr, true))
            {
                SetTarget(m_suppressedTarget);
                if (!m_suppressedTarget.IsEmpty())
                {
                    if (WorldObject const* objTarget = ObjectAccessor::GetWorldObject(*this, m_suppressedTarget))
                        SetFacingToObject(objTarget);
                }
                else
                    SetFacingTo(m_suppressedOrientation);
                m_shouldReacquireTarget = false;
            }

            // if creature is charmed, switch to charmed AI (and back)
            if (NeedChangeAI)
            {
                UpdateCharmAI();
                NeedChangeAI = false;
                IsAIEnabled = true;
                if (!IsInEvadeMode() && !LastCharmerGUID.IsEmpty())
                    if (Unit* charmer = ObjectAccessor::GetUnit(*this, LastCharmerGUID))
                        if (CanStartAttack(charmer, true))
                            i_AI->AttackStart(charmer);

                LastCharmerGUID.Clear();
            }

            // periodic check to see if the creature has passed an evade boundary
            if (IsAIEnabled && !IsInEvadeMode() && IsInCombat())
            {
                if (diff >= m_boundaryCheckTime)
                {
                    AI()->CheckInRoom();
                    m_boundaryCheckTime = 2500;
                } else
                    m_boundaryCheckTime -= diff;
            }

            // if periodic combat pulse is enabled and we are both in combat and in a dungeon, do this now
            if (m_combatPulseDelay > 0 && IsInCombat() && GetMap()->IsDungeon())
            {
                if (diff > m_combatPulseTime)
                    m_combatPulseTime = 0;
                else
                    m_combatPulseTime -= diff;

                if (m_combatPulseTime == 0)
                {
                    Map::PlayerList const &players = GetMap()->GetPlayers();
                    if (!players.isEmpty())
                        for (Map::PlayerList::const_iterator it = players.begin(); it != players.end(); ++it)
                        {
                            if (Player* player = it->GetSource())
                            {
                                if (player->IsGameMaster())
                                    continue;

                                if (player->IsAlive() && this->IsHostileTo(player))
                                {
                                    if (CanHaveThreatList())
                                        AddThreat(player, 0.0f);
                                    this->SetInCombatWith(player);
                                    player->SetInCombatWith(this);
                                }
                            }
                        }

                    m_combatPulseTime = m_combatPulseDelay * IN_MILLISECONDS;
                }
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
            if (!IsAlive())
                break;

            if (m_regenTimer > 0)
            {
                if (diff >= m_regenTimer)
                    m_regenTimer = 0;
                else
                    m_regenTimer -= diff;
            }

            if (m_regenTimer == 0)
            {
                bool bInCombat = IsInCombat() && (!GetVictim() ||                                        // if IsInCombat() is true and this has no victim
                                                  !EnsureVictim()->GetCharmerOrOwnerPlayerOrPlayerItself() ||                // or the victim/owner/charmer is not a player
                                                  !EnsureVictim()->GetCharmerOrOwnerPlayerOrPlayerItself()->IsGameMaster()); // or the victim/owner/charmer is not a GameMaster

                if (!IsInEvadeMode() && (!bInCombat || IsPolymorphed() || CanNotReachTarget())) // regenerate health if not in combat or if polymorphed
                    RegenerateHealth();

                if (HasFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_REGENERATE_POWER))
                {
                    if (GetPowerType() == POWER_ENERGY)
                        Regenerate(POWER_ENERGY);
                    else
                        RegenerateMana();
                }
                m_regenTimer = CREATURE_REGEN_INTERVAL;
            }

            if (CanNotReachTarget() && !IsInEvadeMode() && !GetMap()->IsRaid())
            {
                m_cannotReachTimer += diff;
                if (m_cannotReachTimer >= CREATURE_NOPATH_EVADE_TIME)
                    if (IsAIEnabled)
                        AI()->EnterEvadeMode(CreatureAI::EVADE_REASON_NO_PATH);
            }
            break;
        }
        default:
            break;
    }

    sScriptMgr->OnCreatureUpdate(this, diff);
}

void Creature::RegenerateMana()
{
    uint32 curValue = GetPower(POWER_MANA);
    uint32 maxValue = GetMaxPower(POWER_MANA);

    if (curValue >= maxValue)
        return;

    uint32 addvalue = 0;

    // Combat and any controlled creature
    if (IsInCombat() || !GetCharmerOrOwnerGUID().IsEmpty())
    {
        float ManaIncreaseRate = sWorld->getRate(RATE_POWER_MANA);

        addvalue = uint32((27.0f / 5.0f + 17.0f) * ManaIncreaseRate);
    }
    else
        addvalue = maxValue / 3;

    // Apply modifiers (if any).
    addvalue *= GetTotalAuraMultiplierByMiscValue(SPELL_AURA_MOD_POWER_REGEN_PERCENT, POWER_MANA);

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
    if (!GetCharmerOrOwnerGUID().IsEmpty())
    {
        float HealthIncreaseRate = sWorld->getRate(RATE_HEALTH);

        addvalue = 0.015f * ((float)GetMaxHealth()) * HealthIncreaseRate;
    }
    else
        addvalue = maxValue/3;

    // Apply modifiers (if any).
    addvalue *= GetTotalAuraMultiplier(SPELL_AURA_MOD_HEALTH_REGEN_PERCENT);

    addvalue += GetTotalAuraModifier(SPELL_AURA_MOD_REGEN) * CREATURE_REGEN_INTERVAL  / (5 * IN_MILLISECONDS);

    ModifyHealth(addvalue);
}

void Creature::DoFleeToGetAssistance()
{
    if (!GetVictim())
        return;

    if (HasAuraType(SPELL_AURA_PREVENTS_FLEEING))
        return;

    float radius = sWorld->getFloatConfig(CONFIG_CREATURE_FAMILY_FLEE_ASSISTANCE_RADIUS);
    if (radius >0)
    {
        Creature* creature = nullptr;
        Trinity::NearestAssistCreatureInCreatureRangeCheck u_check(this, GetVictim(), radius);
        Trinity::CreatureLastSearcher<Trinity::NearestAssistCreatureInCreatureRangeCheck> searcher(this, creature, u_check);
        Cell::VisitGridObjects(this, searcher, radius);

        SetNoSearchAssistance(true);
        UpdateSpeed(MOVE_RUN);

        if (!creature)
            //SetFeared(true, EnsureVictim()->GetGUID(), 0, sWorld->getIntConfig(CONFIG_CREATURE_FAMILY_FLEE_DELAY));
            /// @todo use 31365
            SetControlled(true, UNIT_STATE_FLEEING);
        else
            GetMotionMaster()->MoveSeekAssistance(creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ());
    }
}

bool Creature::AIM_Destroy()
{
    if (m_AI_locked)
    {
        TC_LOG_DEBUG("scripts", "AIM_Destroy: failed to destroy, locked.");
        return false;
    }

    ASSERT(!i_disabledAI,
           "The disabled AI wasn't cleared!");

    delete i_AI;
    i_AI = nullptr;

    IsAIEnabled = false;
    return true;
}

bool Creature::AIM_Create(CreatureAI* ai /*= nullptr*/)
{
    // make sure nothing can change the AI during AI update
    if (m_AI_locked)
    {
        TC_LOG_DEBUG("scripts", "AIM_Initialize: failed to init, locked.");
        return false;
    }

    AIM_Destroy();

    Motion_Initialize();

    i_AI = ai ? ai : FactorySelector::selectAI(this);
    return true;
}

void Creature::AI_InitializeAndEnable()
{
    IsAIEnabled = true;
    i_AI->InitializeAI();
    // Initialize vehicle
    if (GetVehicleKit())
        GetVehicleKit()->Reset();
}

bool Creature::AIM_Initialize(CreatureAI* ai)
{
    if (!AIM_Create(ai))
        return false;

    AI_InitializeAndEnable();
    return true;
}

void Creature::Motion_Initialize()
{
    if (!m_formation)
        GetMotionMaster()->Initialize();
    else if (m_formation->getLeader() == this)
    {
        m_formation->FormationReset(false);
        GetMotionMaster()->Initialize();
    }
    else if (m_formation->isFormed())
        GetMotionMaster()->MoveIdle(); //wait the order of leader
    else
        GetMotionMaster()->Initialize();
}

bool Creature::Create(ObjectGuid::LowType guidlow, Map* map, uint32 entry, float x, float y, float z, float ang, CreatureData const* data /*= nullptr*/, uint32 vehId /*= 0*/)
{
    ASSERT(map);
    SetMap(map);

    if (data)
    {
        PhasingHandler::InitDbPhaseShift(GetPhaseShift(), data->phaseUseFlags, data->phaseId, data->phaseGroup);
        PhasingHandler::InitDbVisibleMapId(GetPhaseShift(), data->terrainSwapMap);
    }

    CreatureTemplate const* cinfo = sObjectMgr->GetCreatureTemplate(entry);
    if (!cinfo)
    {
        TC_LOG_ERROR("sql.sql", "Creature::Create(): creature template (guidlow: " UI64FMTD ", entry: %u) does not exist.", guidlow, entry);
        return false;
    }

    //! Relocate before CreateFromProto, to initialize coords and allow
    //! returning correct zone id for selecting OutdoorPvP/Battlefield script
    Relocate(x, y, z, ang);

    // Check if the position is valid before calling CreateFromProto(), otherwise we might add Auras to Creatures at
    // invalid position, triggering a crash about Auras not removed in the destructor
    if (!IsPositionValid())
    {
        TC_LOG_ERROR("entities.unit", "Creature::Create(): given coordinates for creature (guidlow " UI64FMTD ", entry %d) are not valid (X: %f, Y: %f, Z: %f, O: %f)", guidlow, entry, x, y, z, ang);
        return false;
    }

    if (!CreateFromProto(guidlow, entry, data, vehId))
        return false;

    switch (GetCreatureTemplate()->rank)
    {
        case CREATURE_ELITE_RARE:
            m_corpseDelay = sWorld->getIntConfig(CONFIG_CORPSE_DECAY_RARE);
            break;
        case CREATURE_ELITE_ELITE:
            m_corpseDelay = sWorld->getIntConfig(CONFIG_CORPSE_DECAY_ELITE);
            break;
        case CREATURE_ELITE_RAREELITE:
            m_corpseDelay = sWorld->getIntConfig(CONFIG_CORPSE_DECAY_RAREELITE);
            break;
        case CREATURE_ELITE_WORLDBOSS:
            m_corpseDelay = sWorld->getIntConfig(CONFIG_CORPSE_DECAY_WORLDBOSS);
            break;
        default:
            m_corpseDelay = sWorld->getIntConfig(CONFIG_CORPSE_DECAY_NORMAL);
            break;
    }

    LoadCreaturesAddon();

    //! Need to be called after LoadCreaturesAddon - MOVEMENTFLAG_HOVER is set there
    if (HasUnitMovementFlag(MOVEMENTFLAG_HOVER))
    {
        z += GetFloatValue(UNIT_FIELD_HOVERHEIGHT);

        //! Relocate again with updated Z coord
        Relocate(x, y, z, ang);
    }

    uint32 displayID = GetNativeDisplayId();
    CreatureModelInfo const* minfo = sObjectMgr->GetCreatureModelRandomGender(&displayID);
    if (minfo && !IsTotem())                               // Cancel load if no model defined or if totem
    {
        SetDisplayId(displayID);
        SetNativeDisplayId(displayID);
        SetByteValue(UNIT_FIELD_BYTES_0, UNIT_BYTES_0_OFFSET_GENDER, minfo->gender);
    }

    LastUsedScriptID = GetScriptId();

    /// @todo Replace with spell, handle from DB
    if (IsSpiritHealer() || IsSpiritGuide())
    {
        m_serverSideVisibility.SetValue(SERVERSIDE_VISIBILITY_GHOST, GHOST_VISIBILITY_GHOST);
        m_serverSideVisibilityDetect.SetValue(SERVERSIDE_VISIBILITY_GHOST, GHOST_VISIBILITY_GHOST);
    }

    if (GetCreatureTemplate()->flags_extra & CREATURE_FLAG_EXTRA_IGNORE_PATHFINDING)
        AddUnitState(UNIT_STATE_IGNORE_PATHFINDING);

    if (GetCreatureTemplate()->flags_extra & CREATURE_FLAG_EXTRA_IMMUNITY_KNOCKBACK)
    {
        ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
        ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK_DEST, true);
    }

    return true;
}

Creature* Creature::CreateCreature(uint32 entry, Map* map, Position const& pos, uint32 vehId /*= 0*/)
{
    CreatureTemplate const* cInfo = sObjectMgr->GetCreatureTemplate(entry);
    if (!cInfo)
        return nullptr;

    ObjectGuid::LowType lowGuid;
    if (vehId || cInfo->VehicleId)
        lowGuid = map->GenerateLowGuid<HighGuid::Vehicle>();
    else
        lowGuid = map->GenerateLowGuid<HighGuid::Creature>();

    Creature* creature = new Creature();
    if (!creature->Create(lowGuid, map, entry, pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), pos.GetOrientation(), nullptr, vehId))
    {
        delete creature;
        return nullptr;
    }

    return creature;
}

Creature* Creature::CreateCreatureFromDB(ObjectGuid::LowType spawnId, Map* map, bool addToMap /*= true*/, bool allowDuplicate /*= false*/)
{
    Creature* creature = new Creature();
    if (!creature->LoadCreatureFromDB(spawnId, map, addToMap, allowDuplicate))
    {
        delete creature;
        return nullptr;
    }

    return creature;
}

void Creature::InitializeReactState()
{
    if (IsTotem() || IsTrigger() || IsCritter() || IsSpiritService())
        SetReactState(REACT_PASSIVE);
    /*
    else if (IsCivilian())
        SetReactState(REACT_DEFENSIVE);
    */
    else
        SetReactState(REACT_AGGRESSIVE);
}

bool Creature::isCanInteractWithBattleMaster(Player* player, bool msg) const
{
    if (!IsBattleMaster())
        return false;

    BattlegroundTypeId bgTypeId = sBattlegroundMgr->GetBattleMasterBG(GetEntry());
    if (!msg)
        return player->GetBGAccessByLevel(bgTypeId);

    if (!player->GetBGAccessByLevel(bgTypeId))
    {
        ClearGossipMenuFor(player);
        switch (bgTypeId)
        {
            case BATTLEGROUND_AV:  SendGossipMenuFor(player, 7616, this); break;
            case BATTLEGROUND_WS:  SendGossipMenuFor(player, 7599, this); break;
            case BATTLEGROUND_AB:  SendGossipMenuFor(player, 7642, this); break;
            case BATTLEGROUND_EY:
            case BATTLEGROUND_NA:
            case BATTLEGROUND_BE:
            case BATTLEGROUND_AA:
            case BATTLEGROUND_RL:
            case BATTLEGROUND_SA:
            case BATTLEGROUND_DS:
            case BATTLEGROUND_RV:  SendGossipMenuFor(player, 10024, this); break;
            default: break;
        }
        return false;
    }
    return true;
}

bool Creature::CanResetTalents(Player* player) const
{
    return player->getLevel() >= 15
        && player->getClass() == GetCreatureTemplate()->trainer_class;
}

Player* Creature::GetLootRecipient() const
{
    if (!m_lootRecipient)
        return nullptr;

    return ObjectAccessor::FindConnectedPlayer(m_lootRecipient);
}

Group* Creature::GetLootRecipientGroup() const
{
    if (m_lootRecipientGroup.IsEmpty())
        return nullptr;

    return sGroupMgr->GetGroupByGUID(m_lootRecipientGroup);
}

void Creature::SetLootRecipient(Unit* unit)
{
    // set the player whose group should receive the right
    // to loot the creature after it dies
    // should be set to nullptr after the loot disappears

    if (!unit)
    {
        m_lootRecipient.Clear();
        m_lootRecipientGroup.Clear();
        RemoveFlag(OBJECT_DYNAMIC_FLAGS, UNIT_DYNFLAG_LOOTABLE | UNIT_DYNFLAG_TAPPED);
        return;
    }

    if (unit->GetTypeId() != TYPEID_PLAYER && !unit->IsVehicle())
        return;

    Player* player = unit->GetCharmerOrOwnerPlayerOrPlayerItself();
    if (!player)                                             // normal creature, no player involved
        return;

    m_lootRecipient = player->GetGUID();
    if (Group* group = player->GetGroup())
        m_lootRecipientGroup = group->GetGUID();

    SetFlag(OBJECT_DYNAMIC_FLAGS, UNIT_DYNFLAG_TAPPED);
}

// return true if this creature is tapped by the player or by a member of his group.
bool Creature::isTappedBy(Player const* player) const
{
    if (player->GetGUID() == m_lootRecipient)
        return true;

    Group const* playerGroup = player->GetGroup();
    if (!playerGroup || playerGroup != GetLootRecipientGroup()) // if we dont have a group we arent the recipient
        return false;                                           // if creature doesnt have group bound it means it was solo killed by someone else

    return true;
}

void Creature::SaveToDB()
{
    // this should only be used when the creature has already been loaded
    // preferably after adding to map, because mapid may not be valid otherwise
    CreatureData const* data = sObjectMgr->GetCreatureData(m_spawnId);
    if (!data)
    {
        TC_LOG_ERROR("entities.unit", "Creature::SaveToDB failed, cannot get creature data!");
        return;
    }

    uint32 mapId = GetTransport() ? GetTransport()->GetGOInfo()->moTransport.SpawnMap : GetMapId();
    SaveToDB(mapId, data->spawnMask);
}

void Creature::SaveToDB(uint32 mapid, uint64 spawnMask)
{
    // update in loaded data
    if (!m_spawnId)
        m_spawnId = sObjectMgr->GenerateCreatureSpawnId();

    CreatureData& data = sObjectMgr->NewOrExistCreatureData(m_spawnId);

    uint32 displayId = GetNativeDisplayId();
    uint64 npcflag = GetUInt64Value(UNIT_NPC_FLAGS);
    uint32 unitFlags = GetUInt32Value(UNIT_FIELD_FLAGS);
    uint32 unitFlags2 = GetUInt32Value(UNIT_FIELD_FLAGS_2);
    uint32 unitFlags3 = GetUInt32Value(UNIT_FIELD_FLAGS_3);
    uint32 dynamicflags = GetUInt32Value(OBJECT_DYNAMIC_FLAGS);

    // check if it's a custom model and if not, use 0 for displayId
    CreatureTemplate const* cinfo = GetCreatureTemplate();
    if (cinfo)
    {
        if (displayId == cinfo->Modelid1 || displayId == cinfo->Modelid2 ||
            displayId == cinfo->Modelid3 || displayId == cinfo->Modelid4)
            displayId = 0;

        if (npcflag == cinfo->npcflag)
            npcflag = 0;

        if (unitFlags == cinfo->unit_flags)
            unitFlags = 0;

        if (unitFlags2 == cinfo->unit_flags2)
            unitFlags2 = 0;

        if (unitFlags3 == cinfo->unit_flags3)
            unitFlags3 = 0;

        if (dynamicflags == cinfo->dynamicflags)
            dynamicflags = 0;
    }

    // data->guid = guid must not be updated at save
    data.id = GetEntry();
    data.mapid = mapid;
    data.displayid = displayId;
    data.equipmentId = GetCurrentEquipmentId();
    if (!GetTransport())
    {
        data.posX = GetPositionX();
        data.posY = GetPositionY();
        data.posZ = GetPositionZMinusOffset();
        data.orientation = GetOrientation();
    }
    else
    {
        data.posX = GetTransOffsetX();
        data.posY = GetTransOffsetY();
        data.posZ = GetTransOffsetZ();
        data.orientation = GetTransOffsetO();
    }

    data.spawntimesecs = m_respawnDelay;
    // prevent add data integrity problems
    data.spawndist = GetDefaultMovementType() == IDLE_MOTION_TYPE ? 0.0f : m_respawnradius;
    data.currentwaypoint = 0;
    data.curhealth = GetHealth();
    data.curmana = GetPower(POWER_MANA);
    // prevent add data integrity problems
    data.movementType = !m_respawnradius && GetDefaultMovementType() == RANDOM_MOTION_TYPE
        ? IDLE_MOTION_TYPE : GetDefaultMovementType();
    data.spawnMask = spawnMask;
    data.npcflag = npcflag;
    data.unit_flags = unitFlags;
    data.unit_flags2 = unitFlags2;
    data.unit_flags3 = unitFlags3;
    data.dynamicflags = dynamicflags;

    data.phaseId = GetDBPhase() > 0 ? GetDBPhase() : data.phaseId;
    data.phaseGroup = GetDBPhase() < 0 ? -GetDBPhase() : data.phaseGroup;

    // update in DB
    SQLTransaction trans = WorldDatabase.BeginTransaction();

    PreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_DEL_CREATURE);
    stmt->setUInt64(0, m_spawnId);
    trans->Append(stmt);

    uint8 index = 0;

    stmt = WorldDatabase.GetPreparedStatement(WORLD_INS_CREATURE);
    stmt->setUInt64(index++, m_spawnId);
    stmt->setUInt32(index++, GetEntry());
    stmt->setUInt16(index++, uint16(mapid));
    stmt->setUInt64(index++, spawnMask);
    stmt->setUInt32(index++, data.phaseId);
    stmt->setUInt32(index++, data.phaseGroup);
    stmt->setUInt32(index++, displayId);
    stmt->setUInt8(index++, GetCurrentEquipmentId());
    stmt->setFloat(index++, GetPositionX());
    stmt->setFloat(index++, GetPositionY());
    stmt->setFloat(index++, GetPositionZ());
    stmt->setFloat(index++, GetOrientation());
    stmt->setUInt32(index++, m_respawnDelay);
    stmt->setFloat(index++, m_respawnradius);
    stmt->setUInt32(index++, 0);
    stmt->setUInt32(index++, GetHealth());
    stmt->setUInt32(index++, GetPower(POWER_MANA));
    stmt->setUInt8(index++, uint8(GetDefaultMovementType()));
    stmt->setUInt64(index++, npcflag);
    stmt->setUInt32(index++, unitFlags);
    stmt->setUInt32(index++, unitFlags2);
    stmt->setUInt32(index++, unitFlags3);
    stmt->setUInt32(index++, dynamicflags);
    trans->Append(stmt);

    WorldDatabase.CommitTransaction(trans);
}

void Creature::SelectLevel()
{
    CreatureTemplate const* cInfo = GetCreatureTemplate();

    if (!HasScalableLevels())
    {
        // level
        uint8 minlevel = std::min(cInfo->maxlevel, cInfo->minlevel);
        uint8 maxlevel = std::max(cInfo->maxlevel, cInfo->minlevel);
        uint8 level = minlevel == maxlevel ? minlevel : urand(minlevel, maxlevel);
        SetLevel(level);
    }
    else
    {
        SetLevel(cInfo->levelScaling->MaxLevel);
        SetUInt32Value(UNIT_FIELD_SCALING_LEVEL_MIN, cInfo->levelScaling->MinLevel);
        SetUInt32Value(UNIT_FIELD_SCALING_LEVEL_MAX, cInfo->levelScaling->MaxLevel);
        SetUInt32Value(UNIT_FIELD_SCALING_LEVEL_DELTA, cInfo->levelScaling->DeltaLevel);
    }

    UpdateLevelDependantStats();
}

void Creature::UpdateLevelDependantStats()
{
    CreatureTemplate const* cInfo = GetCreatureTemplate();
    uint32 rank = IsPet() ? 0 : cInfo->rank;
    CreatureBaseStats const* stats = sObjectMgr->GetCreatureBaseStats(getLevel(), cInfo->unit_class);

    // health
    float healthmod = _GetHealthMod(rank);

    uint32 basehp = stats->GenerateHealth(cInfo);
    uint32 health = uint32(basehp * healthmod);

    SetCreateHealth(health);
    SetMaxHealth(health);
    SetHealth(health);
    ResetPlayerDamageReq();

    // mana
    uint32 mana = stats->GenerateMana(cInfo);
    SetCreateMana(mana);

    switch (getClass())
    {
        case CLASS_PALADIN:
        case CLASS_MAGE:
            SetMaxPower(POWER_MANA, mana);
            SetFullPower(POWER_MANA);
            break;
        default: // We don't set max power here, 0 makes power bar hidden
            break;
    }

    SetModifierValue(UNIT_MOD_HEALTH, BASE_VALUE, (float)health);

    // damage
    float basedamage = stats->GenerateBaseDamage(cInfo);

    float weaponBaseMinDamage = basedamage;
    float weaponBaseMaxDamage = basedamage * 1.5f;

    SetBaseWeaponDamage(BASE_ATTACK, MINDAMAGE, weaponBaseMinDamage);
    SetBaseWeaponDamage(BASE_ATTACK, MAXDAMAGE, weaponBaseMaxDamage);

    SetBaseWeaponDamage(OFF_ATTACK, MINDAMAGE, weaponBaseMinDamage);
    SetBaseWeaponDamage(OFF_ATTACK, MAXDAMAGE, weaponBaseMaxDamage);

    SetBaseWeaponDamage(RANGED_ATTACK, MINDAMAGE, weaponBaseMinDamage);
    SetBaseWeaponDamage(RANGED_ATTACK, MAXDAMAGE, weaponBaseMaxDamage);

    SetModifierValue(UNIT_MOD_ATTACK_POWER, BASE_VALUE, stats->AttackPower);
    SetModifierValue(UNIT_MOD_ATTACK_POWER_RANGED, BASE_VALUE, stats->RangedAttackPower);

    float armor = (float)stats->GenerateArmor(cInfo); /// @todo Why is this treated as uint32 when it's a float?
    SetModifierValue(UNIT_MOD_ARMOR, BASE_VALUE, armor);
}

float Creature::_GetHealthMod(int32 Rank)
{
    switch (Rank)                                           // define rates for each elite rank
    {
        case CREATURE_ELITE_NORMAL:
            return sWorld->getRate(RATE_CREATURE_NORMAL_HP);
        case CREATURE_ELITE_ELITE:
            return sWorld->getRate(RATE_CREATURE_ELITE_ELITE_HP);
        case CREATURE_ELITE_RAREELITE:
            return sWorld->getRate(RATE_CREATURE_ELITE_RAREELITE_HP);
        case CREATURE_ELITE_WORLDBOSS:
            return sWorld->getRate(RATE_CREATURE_ELITE_WORLDBOSS_HP);
        case CREATURE_ELITE_RARE:
            return sWorld->getRate(RATE_CREATURE_ELITE_RARE_HP);
        default:
            return sWorld->getRate(RATE_CREATURE_ELITE_ELITE_HP);
    }
}

void Creature::LowerPlayerDamageReq(uint64 unDamage)
{
    if (m_PlayerDamageReq)
        m_PlayerDamageReq > unDamage ? m_PlayerDamageReq -= unDamage : m_PlayerDamageReq = 0;
}

float Creature::_GetDamageMod(int32 Rank)
{
    switch (Rank)                                           // define rates for each elite rank
    {
        case CREATURE_ELITE_NORMAL:
            return sWorld->getRate(RATE_CREATURE_NORMAL_DAMAGE);
        case CREATURE_ELITE_ELITE:
            return sWorld->getRate(RATE_CREATURE_ELITE_ELITE_DAMAGE);
        case CREATURE_ELITE_RAREELITE:
            return sWorld->getRate(RATE_CREATURE_ELITE_RAREELITE_DAMAGE);
        case CREATURE_ELITE_WORLDBOSS:
            return sWorld->getRate(RATE_CREATURE_ELITE_WORLDBOSS_DAMAGE);
        case CREATURE_ELITE_RARE:
            return sWorld->getRate(RATE_CREATURE_ELITE_RARE_DAMAGE);
        default:
            return sWorld->getRate(RATE_CREATURE_ELITE_ELITE_DAMAGE);
    }
}

float Creature::GetSpellDamageMod(int32 Rank) const
{
    switch (Rank)                                           // define rates for each elite rank
    {
        case CREATURE_ELITE_NORMAL:
            return sWorld->getRate(RATE_CREATURE_NORMAL_SPELLDAMAGE);
        case CREATURE_ELITE_ELITE:
            return sWorld->getRate(RATE_CREATURE_ELITE_ELITE_SPELLDAMAGE);
        case CREATURE_ELITE_RAREELITE:
            return sWorld->getRate(RATE_CREATURE_ELITE_RAREELITE_SPELLDAMAGE);
        case CREATURE_ELITE_WORLDBOSS:
            return sWorld->getRate(RATE_CREATURE_ELITE_WORLDBOSS_SPELLDAMAGE);
        case CREATURE_ELITE_RARE:
            return sWorld->getRate(RATE_CREATURE_ELITE_RARE_SPELLDAMAGE);
        default:
            return sWorld->getRate(RATE_CREATURE_ELITE_ELITE_SPELLDAMAGE);
    }
}

bool Creature::CreateFromProto(ObjectGuid::LowType guidlow, uint32 entry, CreatureData const* data /*= nullptr*/, uint32 vehId /*= 0*/)
{
    SetZoneScript();
    if (GetZoneScript() && data)
    {
        entry = GetZoneScript()->GetCreatureEntry(guidlow, data);
        if (!entry)
            return false;
    }

    CreatureTemplate const* cinfo = sObjectMgr->GetCreatureTemplate(entry);
    if (!cinfo)
    {
        TC_LOG_ERROR("sql.sql", "Creature::CreateFromProto(): creature template (guidlow: " UI64FMTD ", entry: %u) does not exist.", guidlow, entry);
        return false;
    }

    SetOriginalEntry(entry);

    if (vehId || cinfo->VehicleId)
        Object::_Create(ObjectGuid::Create<HighGuid::Vehicle>(GetMapId(), entry, guidlow));
    else
        Object::_Create(ObjectGuid::Create<HighGuid::Creature>(GetMapId(), entry, guidlow));

    if (!UpdateEntry(entry, data))
        return false;

    if (!vehId)
    {
        if (GetCreatureTemplate()->VehicleId)
        {
            vehId = GetCreatureTemplate()->VehicleId;
            entry = GetCreatureTemplate()->Entry;
        }
        else
            vehId = cinfo->VehicleId;
    }

    if (vehId)
        CreateVehicleKit(vehId, entry, true);

    return true;
}

bool Creature::LoadCreatureFromDB(ObjectGuid::LowType spawnId, Map* map, bool addToMap, bool allowDuplicate)
{
    if (!allowDuplicate)
    {
        // If an alive instance of this spawnId is already found, skip creation
        // If only dead instance(s) exist, despawn them and spawn a new (maybe also dead) version
        const auto creatureBounds = map->GetCreatureBySpawnIdStore().equal_range(spawnId);
        std::vector <Creature*> despawnList;

        if (creatureBounds.first != creatureBounds.second)
        {
            for (auto itr = creatureBounds.first; itr != creatureBounds.second; ++itr)
            {
                if (itr->second->IsAlive())
                {
                    TC_LOG_DEBUG("maps", "Would have spawned " UI64FMTD " but %s already exists", spawnId, creatureBounds.first->second->GetGUID().ToString().c_str());
                    return false;
                }
                else
                {
                    despawnList.push_back(itr->second);
                    TC_LOG_DEBUG("maps", "Despawned dead instance of spawn " UI64FMTD " (%s)", spawnId, itr->second->GetGUID().ToString().c_str());
                }
            }

            for (Creature* despawnCreature : despawnList)
            {
                despawnCreature->AddObjectToRemoveList();
            }
        }
    }

    CreatureData const* data = sObjectMgr->GetCreatureData(spawnId);
    if (!data)
    {
        TC_LOG_ERROR("sql.sql", "Creature (GUID: " UI64FMTD ") not found in table `creature`, can't load. ", spawnId);
        return false;
    }

    m_spawnId = spawnId;
    m_creatureData = data;
    if (!Create(map->GenerateLowGuid<HighGuid::Creature>(), map, data->id, data->posX, data->posY, data->posZ, data->orientation, data, 0))
        return false;

    //We should set first home position, because then AI calls home movement
    SetHomePosition(data->posX, data->posY, data->posZ, data->orientation);

    m_respawnradius = data->spawndist;

    m_respawnDelay = data->spawntimesecs;
    m_deathState = ALIVE;

    m_respawnTime  = GetMap()->GetCreatureRespawnTime(m_spawnId);

    // Is the creature script objecting to us spawning? If yes, delay by one second (then re-check in ::Update)
    if (!m_respawnTime && !sScriptMgr->CanSpawn(spawnId, GetEntry(), GetCreatureTemplate(), GetCreatureData(), map))
        m_respawnTime = time(NULL)+1;

    if (m_respawnTime)                          // respawn on Update
    {
        m_deathState = DEAD;
        if (CanFly())
        {
            float tz = map->GetHeight(GetPhaseShift(), data->posX, data->posY, data->posZ, true, MAX_FALL_DISTANCE);
            if (data->posZ - tz > 0.1f && Trinity::IsValidMapCoord(tz))
                Relocate(data->posX, data->posY, tz);
        }
    }

    SetSpawnHealth();

    // checked at creature_template loading
    m_defaultMovementType = MovementGeneratorType(data->movementType);

    loot.SetGUID(ObjectGuid::Create<HighGuid::LootObject>(data->mapid, data->id, GetMap()->GenerateLowGuid<HighGuid::LootObject>()));

    if (addToMap && !GetMap()->AddToMap(this))
        return false;
    return true;
}

void Creature::SetCanDualWield(bool value)
{
    Unit::SetCanDualWield(value);
    UpdateDamagePhysical(OFF_ATTACK);
}

void Creature::LoadEquipment(int8 id, bool force /*= true*/)
{
    if (id == 0)
    {
        if (force)
        {
            for (uint8 i = 0; i < MAX_EQUIPMENT_ITEMS; ++i)
                SetVirtualItem(i, 0);
            m_equipmentId = 0;
        }

        return;
    }

    EquipmentInfo const* einfo = sObjectMgr->GetEquipmentInfo(GetEntry(), id);
    if (!einfo)
        return;

    m_equipmentId = id;
    for (uint8 i = 0; i < MAX_EQUIPMENT_ITEMS; ++i)
        SetVirtualItem(i, einfo->Items[i].ItemId, einfo->Items[i].AppearanceModId, einfo->Items[i].ItemVisual);
}

void Creature::SetSpawnHealth()
{
    if (!m_creatureData)
        return;

    uint32 curhealth;

    if (!m_regenHealth)
    {
        curhealth = m_creatureData->curhealth;
        if (curhealth)
        {
            curhealth = uint32(curhealth*_GetHealthMod(GetCreatureTemplate()->rank));
            if (curhealth < 1)
                curhealth = 1;
        }
        SetPower(POWER_MANA, m_creatureData->curmana);
    }
    else
    {
        curhealth = GetMaxHealth();
        SetFullPower(POWER_MANA);
    }

    SetHealth((m_deathState == ALIVE || m_deathState == JUST_RESPAWNED) ? curhealth : 0);
}

bool Creature::hasQuest(uint32 quest_id) const
{
    QuestRelationBounds qr = sObjectMgr->GetCreatureQuestRelationBounds(GetEntry());
    for (QuestRelations::const_iterator itr = qr.first; itr != qr.second; ++itr)
    {
        if (itr->second == quest_id)
            return true;
    }
    return false;
}

bool Creature::hasInvolvedQuest(uint32 quest_id) const
{
    QuestRelationBounds qir = sObjectMgr->GetCreatureQuestInvolvedRelationBounds(GetEntry());
    for (QuestRelations::const_iterator itr = qir.first; itr != qir.second; ++itr)
    {
        if (itr->second == quest_id)
            return true;
    }
    return false;
}

void Creature::DeleteFromDB()
{
    if (!m_spawnId)
    {
        TC_LOG_ERROR("entities.unit", "Trying to delete not saved %s!", GetGUID().ToString().c_str());
        return;
    }

    GetMap()->RemoveCreatureRespawnTime(m_spawnId);
    sObjectMgr->DeleteCreatureData(m_spawnId);

    SQLTransaction trans = WorldDatabase.BeginTransaction();

    PreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_DEL_CREATURE);
    stmt->setUInt64(0, m_spawnId);
    trans->Append(stmt);

    stmt = WorldDatabase.GetPreparedStatement(WORLD_DEL_CREATURE_ADDON);
    stmt->setUInt64(0, m_spawnId);
    trans->Append(stmt);

    stmt = WorldDatabase.GetPreparedStatement(WORLD_DEL_GAME_EVENT_CREATURE);
    stmt->setUInt64(0, m_spawnId);
    trans->Append(stmt);

    stmt = WorldDatabase.GetPreparedStatement(WORLD_DEL_GAME_EVENT_MODEL_EQUIP);
    stmt->setUInt64(0, m_spawnId);
    trans->Append(stmt);

    WorldDatabase.CommitTransaction(trans);
}

bool Creature::IsInvisibleDueToDespawn() const
{
    if (Unit::IsInvisibleDueToDespawn())
        return true;

    if (IsAlive() || isDying() || m_corpseRemoveTime > time(NULL))
        return false;

    return true;
}

bool Creature::CanAlwaysSee(WorldObject const* obj) const
{
    if (IsAIEnabled && AI()->CanSeeAlways(obj))
        return true;

    return false;
}

bool Creature::CanStartAttack(Unit const* who, bool force) const
{
    if (IsCivilian())
        return false;

    // This set of checks is should be done only for creatures
    if ((HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC) && who->GetTypeId() != TYPEID_PLAYER)                                   // flag is valid only for non player characters
        || (HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC) && who->GetTypeId() == TYPEID_PLAYER)                                 // immune to PC and target is a player, return false
        || (who->GetOwner() && who->GetOwner()->GetTypeId() == TYPEID_PLAYER && HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC))) // player pets are immune to pc as well
        return false;

    // Do not attack non-combat pets
    if (who->GetTypeId() == TYPEID_UNIT && who->GetCreatureType() == CREATURE_TYPE_NON_COMBAT_PET)
        return false;

    if (!CanFly() && (GetDistanceZ(who) > CREATURE_Z_ATTACK_RANGE + m_CombatDistance))
        //|| who->IsControlledByPlayer() && who->IsFlying()))
        // we cannot check flying for other creatures, too much map/vmap calculation
        /// @todo should switch to range attack
        return false;

    if (!force)
    {
        if (!_IsTargetAcceptable(who))
            return false;

        if (who->IsInCombat() && IsWithinDist(who, ATTACK_DISTANCE))
            if (Unit* victim = who->getAttackerForHelper())
                if (IsWithinDistInMap(victim, sWorld->getFloatConfig(CONFIG_CREATURE_FAMILY_ASSISTANCE_RADIUS)))
                    force = true;

        if (!force && (IsNeutralToAll() || !IsWithinDistInMap(who, GetAttackDistance(who) + m_CombatDistance)))
            return false;
    }

    if (!CanCreatureAttack(who, force))
        return false;

    // No aggro from gray creatures
    if (CheckNoGrayAggroConfig(who->GetLevelForTarget(this), GetLevelForTarget(who)))
        return false;

    return IsWithinLOSInMap(who);
}


bool Creature::CheckNoGrayAggroConfig(uint32 playerLevel, uint32 creatureLevel) const
{
    if (Trinity::XP::GetColorCode(playerLevel, creatureLevel) != XP_GRAY)
        return false;

    uint32 notAbove = sWorld->getIntConfig(CONFIG_NO_GRAY_AGGRO_ABOVE);
    uint32 notBelow = sWorld->getIntConfig(CONFIG_NO_GRAY_AGGRO_BELOW);
    if (notAbove == 0 && notBelow == 0)
        return false;

    if (playerLevel <= notBelow || (playerLevel >= notAbove && notAbove > 0))
        return true;
    return false;
}

float Creature::GetAttackDistance(Unit const* player) const
{
    // WoW Wiki: the minimum radius seems to be 5 yards, while the maximum range is 45 yards
    float maxRadius = (45.0f * sWorld->getRate(RATE_CREATURE_AGGRO));
    float minRadius = (5.0f * sWorld->getRate(RATE_CREATURE_AGGRO));
    float aggroRate = sWorld->getRate(RATE_CREATURE_AGGRO);
    uint8 expansionMaxLevel = uint8(GetMaxLevelForExpansion(GetCreatureTemplate()->RequiredExpansion));

    uint32 playerLevel = player->GetLevelForTarget(this);
    uint32 creatureLevel = GetLevelForTarget(player);

    if (aggroRate == 0.0f)
        return 0.0f;

    // The aggro radius for creatures with equal level as the player is 20 yards.
    // The combatreach should not get taken into account for the distance so we drop it from the range (see Supremus as expample)
    float baseAggroDistance = 20.0f - GetCombatReach();
    float aggroRadius = baseAggroDistance;

    // detect range auras
    if ((creatureLevel + 5) <= sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL))
    {
        aggroRadius += GetTotalAuraModifier(SPELL_AURA_MOD_DETECT_RANGE);

        aggroRadius += player->GetTotalAuraModifier(SPELL_AURA_MOD_DETECTED_RANGE);
    }

    // The aggro range of creatures with higher levels than the total player level for the expansion should get the maxlevel treatment
    // This makes sure that creatures such as bosses wont have a bigger aggro range than the rest of the npc's
    // The following code is used for blizzlike behavior such as skipable bosses (e.g. Commander Springvale at level 85)
    if (creatureLevel > expansionMaxLevel)
        aggroRadius += float(expansionMaxLevel) - float(playerLevel);
    // + - 1 yard for each level difference between player and creature
    else
        aggroRadius += float(creatureLevel) - float(playerLevel);

    // Make sure that we wont go over the total range limits
    if (aggroRadius > maxRadius)
        aggroRadius = maxRadius;
    else if (aggroRadius < minRadius)
        aggroRadius = minRadius;

    return (aggroRadius * aggroRate);
}

void Creature::setDeathState(DeathState s)
{
    Unit::setDeathState(s);

    if (s == JUST_DIED)
    {
        m_corpseRemoveTime = time(NULL) + m_corpseDelay;
        m_respawnTime = time(NULL) + m_respawnDelay + m_corpseDelay;

        // always save boss respawn time at death to prevent crash cheating
        if (sWorld->getBoolConfig(CONFIG_SAVE_RESPAWN_TIME_IMMEDIATELY) || isWorldBoss())
            SaveRespawnTime();

        ReleaseFocus(nullptr, false); // remove spellcast focus
        DoNotReacquireTarget(); // cancel delayed re-target
        SetTarget(ObjectGuid::Empty); // drop target - dead mobs shouldn't ever target things

        SetUInt64Value(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_NONE);

        SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, 0); // if creature is mounted on a virtual mount, remove it at death

        setActive(false);

        if (HasSearchedAssistance())
        {
            SetNoSearchAssistance(false);
            UpdateSpeed(MOVE_RUN);
        }

        //Dismiss group if is leader
        if (m_formation && m_formation->getLeader() == this)
            m_formation->FormationReset(true);

        if ((CanFly() || IsFlying()))
            GetMotionMaster()->MoveFall();

        Unit::setDeathState(CORPSE);
    }
    else if (s == JUST_RESPAWNED)
    {
        if (IsPet())
            SetFullHealth();
        else
            SetSpawnHealth();

        SetLootRecipient(nullptr);
        ResetPlayerDamageReq();

        SetCannotReachTarget(false);
        UpdateMovementFlags();

        ClearUnitState(uint32(UNIT_STATE_ALL_STATE & ~UNIT_STATE_IGNORE_PATHFINDING));

        if (!IsPet())
        {
            CreatureData const* creatureData = GetCreatureData();
            CreatureTemplate const* cInfo = GetCreatureTemplate();

            uint64 npcFlags;
            uint32 unitFlags, unitFlags2, unitFlags3, dynamicFlags;
            ObjectMgr::ChooseCreatureFlags(cInfo, npcFlags, unitFlags, unitFlags2, unitFlags3, dynamicFlags, creatureData);

            if (cInfo->flags_extra & CREATURE_FLAG_EXTRA_WORLDEVENT)
                SetUInt64Value(UNIT_NPC_FLAGS, npcFlags | sGameEventMgr->GetNPCFlag(this));
            else
                SetUInt64Value(UNIT_NPC_FLAGS, npcFlags);

            SetUInt32Value(UNIT_FIELD_FLAGS, unitFlags);
            SetUInt32Value(UNIT_FIELD_FLAGS_2, unitFlags2);
            SetUInt32Value(UNIT_FIELD_FLAGS_3, unitFlags3);
            SetUInt32Value(OBJECT_DYNAMIC_FLAGS, dynamicFlags);

            RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IN_COMBAT);

            SetMeleeDamageSchool(SpellSchools(cInfo->dmgschool));
        }

        Motion_Initialize();
        Unit::setDeathState(ALIVE);
        LoadCreaturesAddon();
    }
}

void Creature::Respawn(bool force)
{
    DestroyForNearbyPlayers();

    if (force)
    {
        if (IsAlive())
            setDeathState(JUST_DIED);
        else if (getDeathState() != CORPSE)
            setDeathState(CORPSE);
    }

    RemoveCorpse(false);

    if (getDeathState() == DEAD)
    {
        if (m_spawnId)
            GetMap()->RemoveCreatureRespawnTime(m_spawnId);

        TC_LOG_DEBUG("entities.unit", "Respawning creature %s (%s)",
            GetName().c_str(), GetGUID().ToString().c_str());
        m_respawnTime = 0;
        ResetPickPocketRefillTimer();
        loot.clear();
        if (m_originalEntry != GetEntry())
            UpdateEntry(m_originalEntry);
        else
            SelectLevel();

        setDeathState(JUST_RESPAWNED);

        uint32 displayID = GetNativeDisplayId();
        CreatureModelInfo const* minfo = sObjectMgr->GetCreatureModelRandomGender(&displayID);
        if (minfo)                                             // Cancel load if no model defined
        {
            SetDisplayId(displayID);
            SetNativeDisplayId(displayID);
            SetByteValue(UNIT_FIELD_BYTES_0, UNIT_BYTES_0_OFFSET_GENDER, minfo->gender);
        }

        GetMotionMaster()->InitDefault();
        //Re-initialize reactstate that could be altered by movementgenerators
        InitializeReactState();

        //Call AI respawn virtual function
        if (IsAIEnabled)
        {
            //reset the AI to be sure no dirty or uninitialized values will be used till next tick
            AI()->Reset();
            m_TriggerJustRespawned = true;//delay event to next tick so all creatures are created on the map before processing
        }

        uint32 poolid = GetSpawnId() ? sPoolMgr->IsPartOfAPool<Creature>(GetSpawnId()) : 0;
        if (poolid)
            sPoolMgr->UpdatePool<Creature>(poolid, GetSpawnId());
    }

    UpdateObjectVisibility();
}

void Creature::ForcedDespawn(uint32 timeMSToDespawn, Seconds const& forceRespawnTimer)
{
    if (timeMSToDespawn)
    {
        ForcedDespawnDelayEvent* pEvent = new ForcedDespawnDelayEvent(*this, forceRespawnTimer);

        m_Events.AddEvent(pEvent, m_Events.CalculateTime(timeMSToDespawn));
        return;
    }

    if (forceRespawnTimer > Seconds::zero())
    {
        if (IsAlive())
        {
            uint32 respawnDelay = m_respawnDelay;
            uint32 corpseDelay = m_corpseDelay;
            m_respawnDelay = forceRespawnTimer.count();
            m_corpseDelay = 0;
            setDeathState(JUST_DIED);
            m_respawnDelay = respawnDelay;
            m_corpseDelay = corpseDelay;
        }
        else
        {
            m_corpseRemoveTime = time(NULL);
            m_respawnTime = time(NULL) + forceRespawnTimer.count();
        }
    }
    else
        if (IsAlive())
            setDeathState(JUST_DIED);

    RemoveCorpse(false);
}

void Creature::DespawnOrUnsummon(uint32 msTimeToDespawn /*= 0*/, Seconds const& forceRespawnTimer /*= 0*/)
{
    if (TempSummon* summon = this->ToTempSummon())
        summon->UnSummon(msTimeToDespawn);
    else
        ForcedDespawn(msTimeToDespawn, forceRespawnTimer);
}

bool Creature::IsImmunedToSpell(SpellInfo const* spellInfo, Unit* caster) const
{
    if (!spellInfo)
        return false;

    // Creature is immune to main mechanic of the spell
    if (GetCreatureTemplate()->MechanicImmuneMask & (1 << (spellInfo->Mechanic - 1)))
        return true;

    // This check must be done instead of 'if (GetCreatureTemplate()->MechanicImmuneMask & (1 << (spellInfo->Mechanic - 1)))' for not break
    // the check of mechanic immunity on DB (tested) because GetCreatureTemplate()->MechanicImmuneMask and m_spellImmune[IMMUNITY_MECHANIC] don't have same data.
    bool immunedToAllEffects = true;
    for (SpellEffectInfo const* effect : spellInfo->GetEffectsForDifficulty(GetMap()->GetDifficultyID()))
    {
        if (!effect || !effect->IsEffect())
            continue;
        if (!IsImmunedToSpellEffect(spellInfo, effect->EffectIndex, caster))
        {
            immunedToAllEffects = false;
            break;
        }
    }
    if (immunedToAllEffects)
        return true;

    return Unit::IsImmunedToSpell(spellInfo, caster);
}

bool Creature::IsImmunedToSpellEffect(SpellInfo const* spellInfo, uint32 index, Unit* caster) const
{
    SpellEffectInfo const* effect = spellInfo->GetEffect(GetMap()->GetDifficultyID(), index);
    if (!effect)
        return true;
    if (GetCreatureTemplate()->MechanicImmuneMask & (1 << (effect->Mechanic - 1)))
        return true;

    if (GetCreatureTemplate()->type == CREATURE_TYPE_MECHANICAL && effect->Effect == SPELL_EFFECT_HEAL)
        return true;

    return Unit::IsImmunedToSpellEffect(spellInfo, index, caster);
}

bool Creature::isElite() const
{
    if (IsPet())
        return false;

    uint32 rank = GetCreatureTemplate()->rank;
    return rank != CREATURE_ELITE_NORMAL && rank != CREATURE_ELITE_RARE;
}

bool Creature::isWorldBoss() const
{
    if (IsPet())
        return false;

    return (GetCreatureTemplate()->type_flags & CREATURE_TYPE_FLAG_BOSS_MOB) != 0;
}

SpellInfo const* Creature::reachWithSpellAttack(Unit* victim)
{
    if (!victim)
        return nullptr;

    for (uint32 i=0; i < MAX_CREATURE_SPELLS; ++i)
    {
        if (!m_spells[i])
            continue;
        SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(m_spells[i]);
        if (!spellInfo)
        {
            TC_LOG_ERROR("entities.unit", "WORLD: unknown spell id %i", m_spells[i]);
            continue;
        }

        bool bcontinue = true;
        for (SpellEffectInfo const* effect : spellInfo->GetEffectsForDifficulty(GetMap()->GetDifficultyID()))
        {
            if (effect && ((effect->Effect == SPELL_EFFECT_SCHOOL_DAMAGE)       ||
                (effect->Effect == SPELL_EFFECT_INSTAKILL)            ||
                (effect->Effect == SPELL_EFFECT_ENVIRONMENTAL_DAMAGE) ||
                (effect->Effect == SPELL_EFFECT_HEALTH_LEECH)
                ))
            {
                bcontinue = false;
                break;
            }
        }
        if (bcontinue)
            continue;

        std::vector<SpellPowerCost> costs = spellInfo->CalcPowerCost(this, SpellSchoolMask(spellInfo->SchoolMask));
        auto m = std::find_if(costs.begin(), costs.end(), [](SpellPowerCost const& cost) { return cost.Power == POWER_MANA; });
        if (m != costs.end())
            if (m->Amount > GetPower(POWER_MANA))
                continue;

        float range = spellInfo->GetMaxRange(false);
        float minrange = spellInfo->GetMinRange(false);
        float dist = GetDistance(victim);
        if (dist > range || dist < minrange)
            continue;
        if (spellInfo->PreventionType & SPELL_PREVENTION_TYPE_SILENCE && HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_SILENCED))
            continue;
        if (spellInfo->PreventionType & SPELL_PREVENTION_TYPE_PACIFY && HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PACIFIED))
            continue;
        return spellInfo;
    }
    return nullptr;
}

SpellInfo const* Creature::reachWithSpellCure(Unit* victim)
{
    if (!victim)
        return nullptr;

    for (uint32 i=0; i < MAX_CREATURE_SPELLS; ++i)
    {
        if (!m_spells[i])
            continue;
        SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(m_spells[i]);
        if (!spellInfo)
        {
            TC_LOG_ERROR("entities.unit", "WORLD: unknown spell id %i", m_spells[i]);
            continue;
        }

        bool bcontinue = true;
        for (SpellEffectInfo const* effect : spellInfo->GetEffectsForDifficulty(GetMap()->GetDifficultyID()))
        {
            if (effect && (effect->Effect == SPELL_EFFECT_HEAL))
            {
                bcontinue = false;
                break;
            }
        }
        if (bcontinue)
            continue;

        std::vector<SpellPowerCost> costs = spellInfo->CalcPowerCost(this, SpellSchoolMask(spellInfo->SchoolMask));
        auto m = std::find_if(costs.begin(), costs.end(), [](SpellPowerCost const& cost) { return cost.Power == POWER_MANA; });
        if (m != costs.end())
            if (m->Amount > GetPower(POWER_MANA))
                continue;

        float range = spellInfo->GetMaxRange(true);
        float minrange = spellInfo->GetMinRange(true);
        float dist = GetDistance(victim);
        //if (!isInFront(victim, range) && spellInfo->AttributesEx)
        //    continue;
        if (dist > range || dist < minrange)
            continue;
        if (spellInfo->PreventionType & SPELL_PREVENTION_TYPE_SILENCE && HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_SILENCED))
            continue;
        if (spellInfo->PreventionType & SPELL_PREVENTION_TYPE_PACIFY && HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PACIFIED))
            continue;
        return spellInfo;
    }
    return nullptr;
}

// select nearest hostile unit within the given distance (regardless of threat list).
Unit* Creature::SelectNearestTarget(float dist, bool playerOnly /* = false */) const
{
    if (dist == 0.0f)
        dist = MAX_VISIBILITY_DISTANCE;

    Unit* target = nullptr;
    Trinity::NearestHostileUnitCheck u_check(this, dist, playerOnly);
    Trinity::UnitLastSearcher<Trinity::NearestHostileUnitCheck> searcher(this, target, u_check);
    Cell::VisitAllObjects(this, searcher, dist);
    return target;
}

// select nearest hostile unit within the given attack distance (i.e. distance is ignored if > than ATTACK_DISTANCE), regardless of threat list.
Unit* Creature::SelectNearestTargetInAttackDistance(float dist) const
{
    if (dist > MAX_VISIBILITY_DISTANCE)
    {
        TC_LOG_ERROR("entities.unit", "Creature (%s) SelectNearestTargetInAttackDistance called with dist > MAX_VISIBILITY_DISTANCE. Distance set to ATTACK_DISTANCE.", GetGUID().ToString().c_str());
        dist = ATTACK_DISTANCE;
    }

    Unit* target = nullptr;
    Trinity::NearestHostileUnitInAttackDistanceCheck u_check(this, dist);
    Trinity::UnitLastSearcher<Trinity::NearestHostileUnitInAttackDistanceCheck> searcher(this, target, u_check);
    Cell::VisitAllObjects(this, searcher, std::max(dist, ATTACK_DISTANCE));
    return target;
}

Player* Creature::SelectNearestPlayer(float distance) const
{
    Player* target = nullptr;

    Trinity::NearestPlayerInObjectRangeCheck checker(this, distance);
    Trinity::PlayerLastSearcher<Trinity::NearestPlayerInObjectRangeCheck> searcher(this, target, checker);
    Cell::VisitAllObjects(this, searcher, distance);

    return target;
}

void Creature::SendAIReaction(AiReaction reactionType)
{
    WorldPackets::Combat::AIReaction packet;

    packet.UnitGUID = GetGUID();
    packet.Reaction = reactionType;

    SendMessageToSet(packet.Write(), true);

    TC_LOG_DEBUG("network", "WORLD: Sent SMSG_AI_REACTION, type %u.", reactionType);
}

void Creature::CallAssistance()
{
    if (!m_AlreadyCallAssistance && GetVictim() && !IsPet() && !IsCharmed())
    {
        SetNoCallAssistance(true);

        float radius = sWorld->getFloatConfig(CONFIG_CREATURE_FAMILY_ASSISTANCE_RADIUS);

        if (radius > 0)
        {
            std::list<Creature*> assistList;
            Trinity::AnyAssistCreatureInRangeCheck u_check(this, GetVictim(), radius);
            Trinity::CreatureListSearcher<Trinity::AnyAssistCreatureInRangeCheck> searcher(this, assistList, u_check);
            Cell::VisitGridObjects(this, searcher, radius);

            if (!assistList.empty())
            {
                AssistDelayEvent* e = new AssistDelayEvent(EnsureVictim()->GetGUID(), *this);
                while (!assistList.empty())
                {
                    // Pushing guids because in delay can happen some creature gets despawned => invalid pointer
                    e->AddAssistant((*assistList.begin())->GetGUID());
                    assistList.pop_front();
                }
                m_Events.AddEvent(e, m_Events.CalculateTime(sWorld->getIntConfig(CONFIG_CREATURE_FAMILY_ASSISTANCE_DELAY)));
            }
        }
    }
}

void Creature::CallForHelp(float radius)
{
    if (radius <= 0.0f || !GetVictim() || IsPet() || IsCharmed())
        return;

    Trinity::CallOfHelpCreatureInRangeDo u_do(this, GetVictim(), radius);
    Trinity::CreatureWorker<Trinity::CallOfHelpCreatureInRangeDo> worker(this, u_do);
    Cell::VisitGridObjects(this, worker, radius);
}

bool Creature::CanAssistTo(const Unit* u, const Unit* enemy, bool checkfaction /*= true*/) const
{
    if (IsInEvadeMode())
        return false;

    // is it true?
    if (!HasReactState(REACT_AGGRESSIVE))
        return false;

    // we don't need help from zombies :)
    if (!IsAlive())
        return false;

    // we don't need help from non-combatant ;)
    if (IsCivilian())
        return false;

    if (HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_NPC))
        return false;

    // skip fighting creature
    if (IsInCombat())
        return false;

    // only free creature
    if (!GetCharmerOrOwnerGUID().IsEmpty())
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
bool Creature::_IsTargetAcceptable(const Unit* target) const
{
    ASSERT(target);

    // if the target cannot be attacked, the target is not acceptable
    if (IsFriendlyTo(target)
        || !target->isTargetableForAttack(false)
        || (m_vehicle && (IsOnVehicle(target) || m_vehicle->GetBase()->IsOnVehicle(target))))
        return false;

    if (target->HasUnitState(UNIT_STATE_DIED))
    {
        // guards can detect fake death
        if (IsGuard() && target->HasFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_FEIGN_DEATH))
            return true;
        else
            return false;
    }

    const Unit* myVictim = getAttackerForHelper();
    const Unit* targetVictim = target->getAttackerForHelper();

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
    if (IsSummon() || !m_spawnId || (m_creatureData && !m_creatureData->dbData))
        return;

    GetMap()->SaveCreatureRespawnTime(m_spawnId, m_respawnTime);
}

// this should not be called by petAI or
bool Creature::CanCreatureAttack(Unit const* victim, bool /*force*/) const
{
    if (!victim->IsInMap(this))
        return false;

    if (!IsValidAttackTarget(victim))
        return false;

    if (!victim->isInAccessiblePlaceFor(this))
        return false;

    if (IsAIEnabled && !AI()->CanAIAttack(victim))
        return false;

    if (GetMap()->IsDungeon())
        return true;

    // if the mob is actively being damaged, do not reset due to distance unless it's a world boss
    if (!isWorldBoss())
        if (time(NULL) - GetLastDamagedTime() <= MAX_AGGRO_RESET_TIME)
            return true;

    //Use AttackDistance in distance check if threat radius is lower. This prevents creature bounce in and out of combat every update tick.
    float dist = std::max(GetAttackDistance(victim), sWorld->getFloatConfig(CONFIG_THREAT_RADIUS)) + m_CombatDistance;

    if (Unit* unit = GetCharmerOrOwner())
        return victim->IsWithinDist(unit, dist);
    else
        return victim->IsInDist(&m_homePosition, dist);
}

CreatureAddon const* Creature::GetCreatureAddon() const
{
    if (m_spawnId)
    {
        if (CreatureAddon const* addon = sObjectMgr->GetCreatureAddon(m_spawnId))
            return addon;
    }

    // dependent from difficulty mode entry
    return sObjectMgr->GetCreatureTemplateAddon(GetCreatureTemplate()->Entry);
}

//creature_addon table
bool Creature::LoadCreaturesAddon()
{
    CreatureAddon const* cainfo = GetCreatureAddon();
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

        SetByteValue(UNIT_FIELD_BYTES_1, UNIT_BYTES_1_OFFSET_STAND_STATE, uint8(cainfo->bytes1 & 0xFF));
        //SetByteValue(UNIT_FIELD_BYTES_1, UNIT_BYTES_1_OFFSET_PET_TALENTS, uint8((cainfo->bytes1 >> 8) & 0xFF));
        SetByteValue(UNIT_FIELD_BYTES_1, UNIT_BYTES_1_OFFSET_PET_TALENTS, 0);
        SetByteValue(UNIT_FIELD_BYTES_1, UNIT_BYTES_1_OFFSET_VIS_FLAG, uint8((cainfo->bytes1 >> 16) & 0xFF));
        SetByteValue(UNIT_FIELD_BYTES_1, UNIT_BYTES_1_OFFSET_ANIM_TIER, uint8((cainfo->bytes1 >> 24) & 0xFF));

        //! Suspected correlation between UNIT_FIELD_BYTES_1, offset 3, value 0x2:
        //! If no inhabittype_fly (if no MovementFlag_DisableGravity or MovementFlag_CanFly flag found in sniffs)
        //! Check using InhabitType as movement flags are assigned dynamically
        //! basing on whether the creature is in air or not
        //! Set MovementFlag_Hover. Otherwise do nothing.
        if (GetByteValue(UNIT_FIELD_BYTES_1, UNIT_BYTES_1_OFFSET_ANIM_TIER) & UNIT_BYTE1_FLAG_HOVER && !(GetCreatureTemplate()->InhabitType & INHABIT_AIR))
            AddUnitMovementFlag(MOVEMENTFLAG_HOVER);
    }

    if (cainfo->bytes2 != 0)
    {
        // 0 SheathState
        // 1 PvpFlags
        // 2 PetFlags           Pet only, so always 0 for default creature
        // 3 ShapeshiftForm     Must be determined/set by shapeshift spell/aura

        SetByteValue(UNIT_FIELD_BYTES_2, UNIT_BYTES_2_OFFSET_SHEATH_STATE, uint8(cainfo->bytes2 & 0xFF));
        //SetByteValue(UNIT_FIELD_BYTES_2, UNIT_BYTES_2_OFFSET_PVP_FLAG, uint8((cainfo->bytes2 >> 8) & 0xFF));
        //SetByteValue(UNIT_FIELD_BYTES_2, UNIT_BYTES_2_OFFSET_PET_FLAGS, uint8((cainfo->bytes2 >> 16) & 0xFF));
        SetByteValue(UNIT_FIELD_BYTES_2, UNIT_BYTES_2_OFFSET_PET_FLAGS, 0);
        //SetByteValue(UNIT_FIELD_BYTES_2, UNIT_BYTES_2_OFFSET_SHAPESHIFT_FORM, uint8((cainfo->bytes2 >> 24) & 0xFF));
        SetByteValue(UNIT_FIELD_BYTES_2, UNIT_BYTES_2_OFFSET_SHAPESHIFT_FORM, 0);
    }

    if (cainfo->emote != 0)
        SetUInt32Value(UNIT_NPC_EMOTESTATE, cainfo->emote);

    SetAIAnimKitId(cainfo->aiAnimKit);
    SetMovementAnimKitId(cainfo->movementAnimKit);
    SetMeleeAnimKitId(cainfo->meleeAnimKit);

    //Load Path
    if (cainfo->path_id != 0)
        m_path_id = cainfo->path_id;

    if (!cainfo->auras.empty())
    {
        for (std::vector<uint32>::const_iterator itr = cainfo->auras.begin(); itr != cainfo->auras.end(); ++itr)
        {
            SpellInfo const* AdditionalSpellInfo = sSpellMgr->GetSpellInfo(*itr);
            if (!AdditionalSpellInfo)
            {
                TC_LOG_ERROR("sql.sql", "Creature (%s) has wrong spell %u defined in `auras` field.", GetGUID().ToString().c_str(), *itr);
                continue;
            }

            // skip already applied aura
            if (HasAura(*itr))
                continue;

            AddAura(*itr, this);
            TC_LOG_DEBUG("entities.unit", "Spell: %u added to creature (%s)", *itr, GetGUID().ToString().c_str());
        }
    }

    return true;
}

/// Send a message to LocalDefense channel for players opposition team in the zone
void Creature::SendZoneUnderAttackMessage(Player* attacker)
{
    uint32 enemy_team = attacker->GetTeam();
    WorldPackets::Misc::ZoneUnderAttack packet;
    packet.AreaID = GetAreaId();
    sWorld->SendGlobalMessage(packet.Write(), nullptr, (enemy_team == ALLIANCE ? HORDE : ALLIANCE));
}

void Creature::SetInCombatWithZone()
{
    if (!CanHaveThreatList())
    {
        TC_LOG_ERROR("entities.unit", "Creature entry %u call SetInCombatWithZone but creature cannot have threat list.", GetEntry());
        return;
    }

    Map* map = GetMap();

    if (!map->IsDungeon())
    {
        TC_LOG_ERROR("entities.unit", "Creature entry %u call SetInCombatWithZone for map (id: %u) that isn't an instance.", GetEntry(), map->GetId());
        return;
    }

    Map::PlayerList const &PlList = map->GetPlayers();

    if (PlList.isEmpty())
        return;

    for (Map::PlayerList::const_iterator i = PlList.begin(); i != PlList.end(); ++i)
    {
        if (Player* player = i->GetSource())
        {
            if (player->IsGameMaster())
                continue;

            if (player->IsAlive())
            {
                this->SetInCombatWith(player);
                player->SetInCombatWith(this);
                AddThreat(player, 0.0f);
            }
        }
    }
}

bool Creature::HasSpell(uint32 spellID) const
{
    for (uint8 i = 0; i < MAX_CREATURE_SPELLS; ++i)
        if (spellID == m_spells[i])
            return true;

    return false;
}

time_t Creature::GetRespawnTimeEx() const
{
    time_t now = time(NULL);
    if (m_respawnTime > now)
        return m_respawnTime;
    else
        return now;
}

void Creature::GetRespawnPosition(float &x, float &y, float &z, float* ori, float* dist) const
{
    if (m_spawnId)
    {
        if (CreatureData const* data = sObjectMgr->GetCreatureData(GetSpawnId()))
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
    if (loot.loot_type != LOOT_SKINNING && !IsPet() && GetCreatureTemplate()->SkinLootId && hasLootRecipient())
        if (LootTemplates_Skinning.HaveLootFor(GetCreatureTemplate()->SkinLootId))
            SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_SKINNABLE);

    time_t now = time(NULL);
    // Do not reset corpse remove time if corpse is already removed
    if (m_corpseRemoveTime <= now)
        return;

    float decayRate = sWorld->getRate(RATE_CORPSE_DECAY_LOOTED);

    // corpse skinnable, but without skinning flag, and then skinned, corpse will despawn next update
    if (loot.loot_type == LOOT_SKINNING)
        m_corpseRemoveTime = now;
    else
        m_corpseRemoveTime = now + uint32(m_corpseDelay * decayRate);

    m_respawnTime = m_corpseRemoveTime + m_respawnDelay;
}

bool Creature::HasScalableLevels() const
{
    CreatureTemplate const* cinfo = GetCreatureTemplate();
    return cinfo->levelScaling.is_initialized();
}

uint64 Creature::GetMaxHealthByLevel(uint8 level) const
{
    CreatureTemplate const* cInfo = GetCreatureTemplate();
    CreatureBaseStats const* stats = sObjectMgr->GetCreatureBaseStats(level, cInfo->unit_class);
    return stats->GenerateHealth(cInfo);
}

float Creature::GetHealthMultiplierForTarget(WorldObject const* target) const
{
    if (!HasScalableLevels())
        return 1.0f;

    uint8 levelForTarget = GetLevelForTarget(target);
    if (getLevel() < levelForTarget)
        return 1.0f;

    return double(GetMaxHealthByLevel(levelForTarget)) / double(GetCreateHealth());
}

float Creature::GetBaseDamageForLevel(uint8 level) const
{
    CreatureTemplate const* cInfo = GetCreatureTemplate();
    CreatureBaseStats const* stats = sObjectMgr->GetCreatureBaseStats(level, cInfo->unit_class);
    return stats->GenerateBaseDamage(cInfo);
}

float Creature::GetDamageMultiplierForTarget(WorldObject const* target) const
{
    if (!HasScalableLevels())
        return 1.0f;

    uint8 levelForTarget = GetLevelForTarget(target);

    return GetBaseDamageForLevel(levelForTarget) / GetBaseDamageForLevel(getLevel());
}

float Creature::GetBaseArmorForLevel(uint8 level) const
{
    CreatureTemplate const* cInfo = GetCreatureTemplate();
    CreatureBaseStats const* stats = sObjectMgr->GetCreatureBaseStats(level, cInfo->unit_class);
    return stats->GenerateArmor(cInfo);
}

float Creature::GetArmorMultiplierForTarget(WorldObject const* target) const
{
    if (!HasScalableLevels())
        return 1.0f;

    uint8 levelForTarget = GetLevelForTarget(target);

    return GetBaseArmorForLevel(levelForTarget) / GetBaseArmorForLevel(getLevel());
}

uint8 Creature::GetLevelForTarget(WorldObject const* target) const
{
    if (Unit const* unitTarget = target->ToUnit())
    {
        if (isWorldBoss())
        {
            uint8 level = unitTarget->getLevel() + sWorld->getIntConfig(CONFIG_WORLD_BOSS_LEVEL_DIFF);
            return RoundToInterval<uint8>(level, 1u, 255u);
        }

        // If this creature should scale level, adapt level depending of target level
        // between UNIT_FIELD_SCALING_LEVEL_MIN and UNIT_FIELD_SCALING_LEVEL_MAX
        if (HasScalableLevels())
        {
            uint8 targetLevelWithDelta = unitTarget->getLevel() + GetCreatureTemplate()->levelScaling->DeltaLevel;

            if (target->IsPlayer())
                targetLevelWithDelta += target->GetUInt32Value(PLAYER_FIELD_SCALING_PLAYER_LEVEL_DELTA);

            return RoundToInterval<uint8>(targetLevelWithDelta, GetUInt32Value(UNIT_FIELD_SCALING_LEVEL_MIN), GetUInt32Value(UNIT_FIELD_SCALING_LEVEL_MAX));
        }
    }

    return Unit::GetLevelForTarget(target);
}

std::string Creature::GetAIName() const
{
    return sObjectMgr->GetCreatureTemplate(GetEntry())->AIName;
}

std::string Creature::GetScriptName() const
{
    return sObjectMgr->GetScriptName(GetScriptId());
}

uint32 Creature::GetScriptId() const
{
    if (CreatureData const* creatureData = GetCreatureData())
        return creatureData->ScriptId;

    return sObjectMgr->GetCreatureTemplate(GetEntry())->ScriptID;
}

VendorItemData const* Creature::GetVendorItems() const
{
    return sObjectMgr->GetNpcVendorItemList(GetEntry());
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
        if (ItemTemplate const* pProto = sObjectMgr->GetItemTemplate(vItem->item))
        {
            uint32 diff = uint32((ptime - vCount->lastIncrementTime)/vItem->incrtime);
            if ((vCount->count + diff * pProto->GetBuyCount()) >= vItem->maxcount)
            {
                m_vendorItemCounts.erase(itr);
                return vItem->maxcount;
            }

            vCount->count += diff * pProto->GetBuyCount();
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
        m_vendorItemCounts.push_back(VendorItemCount(vItem->item, new_count));
        return new_count;
    }

    VendorItemCount* vCount = &*itr;

    time_t ptime = time(NULL);

    if (time_t(vCount->lastIncrementTime + vItem->incrtime) <= ptime)
        if (ItemTemplate const* pProto = sObjectMgr->GetItemTemplate(vItem->item))
        {
            uint32 diff = uint32((ptime - vCount->lastIncrementTime)/vItem->incrtime);
            if ((vCount->count + diff * pProto->GetBuyCount()) < vItem->maxcount)
                vCount->count += diff * pProto->GetBuyCount();
            else
                vCount->count = vItem->maxcount;
        }

    vCount->count = vCount->count > used_count ? vCount->count-used_count : 0;
    vCount->lastIncrementTime = ptime;
    return vCount->count;
}

// overwrite WorldObject function for proper name localization
std::string const & Creature::GetNameForLocaleIdx(LocaleConstant loc_idx) const
{
    if (loc_idx != DEFAULT_LOCALE)
    {
        uint8 uloc_idx = uint8(loc_idx);
        CreatureLocale const* cl = sObjectMgr->GetCreatureLocale(GetEntry());
        if (cl)
        {
            if (cl->Name.size() > uloc_idx && !cl->Name[uloc_idx].empty())
                return cl->Name[uloc_idx];
        }
    }

    return GetName();
}

uint32 Creature::GetPetAutoSpellOnPos(uint8 pos) const
{
    if (pos >= MAX_SPELL_CHARM || m_charmInfo->GetCharmSpell(pos)->GetType() != ACT_ENABLED)
        return 0;
    else
        return m_charmInfo->GetCharmSpell(pos)->GetAction();
}

float Creature::GetPetChaseDistance() const
{
    float range = MELEE_RANGE;

    for (uint8 i = 0; i < GetPetAutoSpellSize(); ++i)
    {
        uint32 spellID = GetPetAutoSpellOnPos(i);
        if (!spellID)
            continue;

        if (SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellID))
        {
            if (spellInfo->GetRecoveryTime() == 0 &&  // No cooldown
                    spellInfo->RangeEntry->ID != 1 /*Self*/ && spellInfo->RangeEntry->ID != 2 /*Combat Range*/ &&
                        spellInfo->GetMinRange() > range)
                range = spellInfo->GetMinRange();
        }
    }

    return range;
}

void Creature::SetPosition(float x, float y, float z, float o)
{
    // prevent crash when a bad coord is sent by the client
    if (!Trinity::IsValidMapCoord(x, y, z, o))
    {
        TC_LOG_DEBUG("entities.unit", "Creature::SetPosition(%f, %f, %f) .. bad coordinates!", x, y, z);
        return;
    }

    GetMap()->CreatureRelocation(this, x, y, z, o);
    if (IsVehicle())
        GetVehicleKit()->RelocatePassengers();
}

bool Creature::IsDungeonBoss() const
{
    CreatureTemplate const* cinfo = sObjectMgr->GetCreatureTemplate(GetEntry());
    return cinfo && (cinfo->flags_extra & CREATURE_FLAG_EXTRA_DUNGEON_BOSS);
}

float Creature::GetAggroRange(Unit const* target) const
{
    // Determines the aggro range for creatures (usually pets), used mainly for aggressive pet target selection.
    // Based on data from wowwiki due to lack of 3.3.5a data

    if (target && this->IsPet())
    {
        uint32 targetLevel = 0;

        if (target->GetTypeId() == TYPEID_PLAYER)
            targetLevel = target->GetLevelForTarget(this);
        else if (target->GetTypeId() == TYPEID_UNIT)
            targetLevel = target->ToCreature()->GetLevelForTarget(this);

        uint32 myLevel = GetLevelForTarget(target);
        int32 levelDiff = int32(targetLevel) - int32(myLevel);

        // The maximum Aggro Radius is capped at 45 yards (25 level difference)
        if (levelDiff < -25)
            levelDiff = -25;

        // The base aggro radius for mob of same level
        float aggroRadius = 20;

        // Aggro Radius varies with level difference at a rate of roughly 1 yard/level
        aggroRadius -= (float)levelDiff;

        // detect range auras
        aggroRadius += GetTotalAuraModifier(SPELL_AURA_MOD_DETECT_RANGE);

        // detected range auras
        aggroRadius += target->GetTotalAuraModifier(SPELL_AURA_MOD_DETECTED_RANGE);

        // Just in case, we don't want pets running all over the map
        if (aggroRadius > MAX_AGGRO_RADIUS)
            aggroRadius = MAX_AGGRO_RADIUS;

        // Minimum Aggro Radius for a mob seems to be combat range (5 yards)
        //  hunter pets seem to ignore minimum aggro radius so we'll default it a little higher
        if (aggroRadius < 10)
            aggroRadius = 10;

        return (aggroRadius);
    }

    // Default
    return 0.0f;
}

Unit* Creature::SelectNearestHostileUnitInAggroRange(bool useLOS) const
{
    // Selects nearest hostile target within creature's aggro range. Used primarily by
    //  pets set to aggressive. Will not return neutral or friendly targets.

    Unit* target = NULL;

    Trinity::NearestHostileUnitInAggroRangeCheck u_check(this, useLOS);
    Trinity::UnitSearcher<Trinity::NearestHostileUnitInAggroRangeCheck> searcher(this, target, u_check);

    Cell::VisitGridObjects(this, searcher, MAX_AGGRO_RADIUS);

    return target;
}

void Creature::UpdateMovementFlags()
{
    // Do not update movement flags if creature is controlled by a player (charm/vehicle)
    if (m_playerMovingMe)
        return;

    // Set the movement flags if the creature is in that mode. (Only fly if actually in air, only swim if in water, etc)
    float ground = GetMap()->GetHeight(GetPhaseShift(), GetPositionX(), GetPositionY(), GetPositionZMinusOffset());

    bool isInAir = (G3D::fuzzyGt(GetPositionZMinusOffset(), ground + 0.05f) || G3D::fuzzyLt(GetPositionZMinusOffset(), ground - 0.05f)); // Can be underground too, prevent the falling

    if (GetCreatureTemplate()->InhabitType & INHABIT_AIR && isInAir && !IsFalling())
    {
        if (GetCreatureTemplate()->InhabitType & INHABIT_GROUND)
            SetCanFly(true);
        else
            SetDisableGravity(true);
    }
    else
    {
        SetCanFly(false);
        SetDisableGravity(false);
    }

    if (!isInAir)
        SetFall(false);

    SetSwim(GetCreatureTemplate()->InhabitType & INHABIT_WATER && IsInWater());
}

void Creature::SetObjectScale(float scale)
{
    Unit::SetObjectScale(scale);

    if (CreatureModelInfo const* minfo = sObjectMgr->GetCreatureModelInfo(GetDisplayId()))
    {
        SetFloatValue(UNIT_FIELD_BOUNDINGRADIUS, minfo->bounding_radius * scale);
        SetFloatValue(UNIT_FIELD_COMBATREACH, minfo->combat_reach * scale);
    }
}

void Creature::SetDisplayId(uint32 modelId)
{
    Unit::SetDisplayId(modelId);

    if (CreatureModelInfo const* minfo = sObjectMgr->GetCreatureModelInfo(modelId))
    {
        SetFloatValue(UNIT_FIELD_BOUNDINGRADIUS, minfo->bounding_radius * GetObjectScale());
        SetFloatValue(UNIT_FIELD_COMBATREACH, minfo->combat_reach * GetObjectScale());
    }
}

void Creature::SetTarget(ObjectGuid const& guid)
{
    if (IsFocusing(nullptr, true))
        m_suppressedTarget = guid;
    else
        SetGuidValue(UNIT_FIELD_TARGET, guid);
}

void Creature::FocusTarget(Spell const* focusSpell, WorldObject const* target)
{
    // already focused
    if (m_focusSpell)
        return;

    // don't use spell focus for vehicle spells
    if (focusSpell->GetSpellInfo()->HasAura(DIFFICULTY_NONE, SPELL_AURA_CONTROL_VEHICLE))
        return;

    if ((!target || target == this) && !focusSpell->GetCastTime()) // instant cast, untargeted (or self-targeted) spell doesn't need any facing updates
        return;

    // store pre-cast values for target and orientation (used to later restore)
    if (!IsFocusing(nullptr, true))
    { // only overwrite these fields if we aren't transitioning from one spell focus to another
        m_suppressedTarget = GetGuidValue(UNIT_FIELD_TARGET);
        m_suppressedOrientation = GetOrientation();
    }

    m_focusSpell = focusSpell;

    // set target, then force send update packet to players if it changed to provide appropriate facing
    ObjectGuid newTarget = target ? target->GetGUID() : ObjectGuid::Empty;
    if (GetGuidValue(UNIT_FIELD_TARGET) != newTarget)
    {
        SetGuidValue(UNIT_FIELD_TARGET, newTarget);

        if ( // here we determine if the (relatively expensive) forced update is worth it, or whether we can afford to wait until the scheduled update tick
            ( // only require instant update for spells that actually have a visual
                focusSpell->GetSpellInfo()->GetSpellVisual()
            ) && (
                !focusSpell->GetCastTime() || // if the spell is instant cast
                focusSpell->GetSpellInfo()->HasAttribute(SPELL_ATTR5_DONT_TURN_DURING_CAST) // client gets confused if we attempt to turn at the regularly scheduled update packet
            )
        )
        {
            std::list<Player*> playersNearby;
            GetPlayerListInGrid(playersNearby, GetVisibilityRange());
            for (Player* player : playersNearby)
            {
                // only update players that are known to the client (have already been created)
                if (player->HaveAtClient(this))
                    SendUpdateToPlayer(player);
            }
        }
    }

    bool canTurnDuringCast = !focusSpell->GetSpellInfo()->HasAttribute(SPELL_ATTR5_DONT_TURN_DURING_CAST);
    // Face the target - we need to do this before the unit state is modified for no-turn spells
    if (target)
        SetFacingToObject(target);
    else if (!canTurnDuringCast)
        if (Unit* victim = GetVictim())
            SetFacingToObject(victim); // ensure orientation is correct at beginning of cast

    if (!canTurnDuringCast)
        AddUnitState(UNIT_STATE_CANNOT_TURN);
}

bool Creature::IsFocusing(Spell const* focusSpell, bool withDelay)
{
    if (!IsAlive()) // dead creatures cannot focus
    {
        ReleaseFocus(nullptr, false);
        return false;
    }

    if (focusSpell && (focusSpell != m_focusSpell))
        return false;

    if (!m_focusSpell)
    {
        if (!withDelay || !m_focusDelay)
            return false;
        if (GetMSTimeDiffToNow(m_focusDelay) > 1000) // @todo figure out if we can get rid of this magic number somehow
        {
            m_focusDelay = 0; // save checks in the future
            return false;
        }
    }

    return true;
}

void Creature::ReleaseFocus(Spell const* focusSpell, bool withDelay)
{
    if (!m_focusSpell)
        return;

    // focused to something else
    if (focusSpell && focusSpell != m_focusSpell)
        return;

    if (IsPet()) // player pets do not use delay system
    {
        SetGuidValue(UNIT_FIELD_TARGET, m_suppressedTarget);
        if (!m_suppressedTarget.IsEmpty())
        {
            if (WorldObject const* objTarget = ObjectAccessor::GetWorldObject(*this, m_suppressedTarget))
                SetFacingToObject(objTarget);
        }
        else
            SetFacingTo(m_suppressedOrientation);
    }
    else
        // tell the creature that it should reacquire its actual target after the delay expires (this is handled in ::Update)
        // player pets don't need to do this, as they automatically reacquire their target on focus release
        MustReacquireTarget();

    if (m_focusSpell->GetSpellInfo()->HasAttribute(SPELL_ATTR5_DONT_TURN_DURING_CAST))
        ClearUnitState(UNIT_STATE_CANNOT_TURN);

    m_focusSpell = nullptr;
    m_focusDelay = (!IsPet() && withDelay) ? getMSTime() : 0; // don't allow re-target right away to prevent visual bugs
}

void Creature::StartPickPocketRefillTimer()
{
    _pickpocketLootRestore = time(NULL) + sWorld->getIntConfig(CONFIG_CREATURE_PICKPOCKET_REFILL);
}

void Creature::SetTextRepeatId(uint8 textGroup, uint8 id)
{
    CreatureTextRepeatIds& repeats = m_textRepeat[textGroup];
    if (std::find(repeats.begin(), repeats.end(), id) == repeats.end())
        repeats.push_back(id);
    else
        TC_LOG_ERROR("sql.sql", "CreatureTextMgr: TextGroup %u for Creature (%s) %s, id %u already added", uint32(textGroup), GetName().c_str(), GetGUID().ToString().c_str(), uint32(id));
}

CreatureTextRepeatIds Creature::GetTextRepeatGroup(uint8 textGroup)
{
    CreatureTextRepeatIds ids;

    CreatureTextRepeatGroup::const_iterator groupItr = m_textRepeat.find(textGroup);
    if (groupItr != m_textRepeat.end())
        ids = groupItr->second;

    return ids;
}

void Creature::ClearTextRepeatGroup(uint8 textGroup)
{
    CreatureTextRepeatGroup::iterator groupItr = m_textRepeat.find(textGroup);
    if (groupItr != m_textRepeat.end())
        groupItr->second.clear();
}

bool Creature::CanGiveExperience() const
{
    return !IsCritter()
        && !IsPet()
        && !IsTotem()
        && !(GetCreatureTemplate()->flags_extra & CREATURE_FLAG_EXTRA_NO_XP_AT_KILL);
}
