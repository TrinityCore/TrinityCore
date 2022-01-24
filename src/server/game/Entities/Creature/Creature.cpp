/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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
#include "DB2Stores.h"
#include "Formulas.h"
#include "GameEventMgr.h"
#include "GameTime.h"
#include "GossipDef.h"
#include "GridNotifiersImpl.h"
#include "Group.h"
#include "GroupMgr.h"
#include "InstanceScript.h"
#include "Log.h"
#include "LootMgr.h"
#include "MapManager.h"
#include "MiscPackets.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "PhasingHandler.h"
#include "Player.h"
#include "PoolMgr.h"
#include "QueryPackets.h"
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
#include <sstream>

std::string CreatureMovementData::ToString() const
{
    char const* const GroundStates[] = { "None", "Run", "Hover" };
    char const* const FlightStates[] = { "None", "DisableGravity", "CanFly" };
    char const* const ChaseStates[]  = { "Run", "CanWalk", "AlwaysWalk" };
    char const* const RandomStates[] = { "Walk", "CanRun", "AlwaysRun" };

    std::ostringstream str;
    str << std::boolalpha
        << "Ground: " << GroundStates[AsUnderlyingType(Ground)]
        << ", Swim: " << Swim
        << ", Flight: " << FlightStates[AsUnderlyingType(Flight)]
        << ", Chase: " << ChaseStates[AsUnderlyingType(Chase)]
        << ", Random: " << RandomStates[AsUnderlyingType(Random)];
    if (Rooted)
        str << ", Rooted";

    return str.str();
}

VendorItemCount::VendorItemCount(uint32 _item, uint32 _count)
    : itemId(_item), count(_count), lastIncrementTime(GameTime::GetGameTime()) { }

bool VendorItem::IsGoldRequired(ItemTemplate const* pProto) const
{
    return pProto->HasFlag(ITEM_FLAG2_DONT_IGNORE_BUY_PRICE) || !ExtendedCost;
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

CreatureModel const CreatureModel::DefaultInvisibleModel(11686, 1.0f, 1.0f);
CreatureModel const CreatureModel::DefaultVisibleModel(17519, 1.0f, 1.0f);

CreatureModel const* CreatureTemplate::GetModelByIdx(uint32 idx) const
{
    return idx < Models.size() ? &Models[idx] : nullptr;
}

CreatureModel const* CreatureTemplate::GetRandomValidModel() const
{
    if (!Models.size())
        return nullptr;

    // If only one element, ignore the Probability (even if 0)
    if (Models.size() == 1)
        return &Models[0];

    auto selectedItr = Trinity::Containers::SelectRandomWeightedContainerElement(Models, [](CreatureModel const& model)
    {
        return model.Probability;
    });

    return &(*selectedItr);
}

CreatureModel const* CreatureTemplate::GetFirstValidModel() const
{
    for (CreatureModel const& model : Models)
        if (model.CreatureDisplayID)
            return &model;

    return nullptr;
}

CreatureModel const* CreatureTemplate::GetModelWithDisplayId(uint32 displayId) const
{
    for (CreatureModel const& model : Models)
        if (displayId == model.CreatureDisplayID)
            return &model;

    return nullptr;
}

CreatureModel const* CreatureTemplate::GetFirstInvisibleModel() const
{
    for (CreatureModel const& model : Models)
        if (CreatureModelInfo const* modelInfo = sObjectMgr->GetCreatureModelInfo(model.CreatureDisplayID))
            if (modelInfo && modelInfo->is_trigger)
                return &model;

    return &CreatureModel::DefaultInvisibleModel;
}

CreatureModel const* CreatureTemplate::GetFirstVisibleModel() const
{
    for (CreatureModel const& model : Models)
        if (CreatureModelInfo const* modelInfo = sObjectMgr->GetCreatureModelInfo(model.CreatureDisplayID))
            if (modelInfo && !modelInfo->is_trigger)
                return &model;

    return &CreatureModel::DefaultVisibleModel;
}

std::pair<int16, int16> CreatureTemplate::GetMinMaxLevel() const
{
    return
    {
        HealthScalingExpansion != EXPANSION_LEVEL_CURRENT ? minlevel : minlevel + MAX_LEVEL,
        HealthScalingExpansion != EXPANSION_LEVEL_CURRENT ? maxlevel : maxlevel + MAX_LEVEL
    };
}

int32 CreatureTemplate::GetHealthScalingExpansion() const
{
    return HealthScalingExpansion == EXPANSION_LEVEL_CURRENT ? CURRENT_EXPANSION : HealthScalingExpansion;
}

void CreatureTemplate::InitializeQueryData()
{
    for (uint8 loc = LOCALE_enUS; loc < TOTAL_LOCALES; ++loc)
        QueryData[loc] = BuildQueryData(static_cast<LocaleConstant>(loc));
}

WorldPacket CreatureTemplate::BuildQueryData(LocaleConstant loc) const
{
    WorldPackets::Query::QueryCreatureResponse queryTemp;

    queryTemp.CreatureID = Entry;

    queryTemp.Allow = true;

    WorldPackets::Query::CreatureStats& stats = queryTemp.Stats;

    stats.Leader = RacialLeader;

    stats.Name[0] = Name;
    stats.NameAlt[0] = FemaleName;

    stats.Flags[0] = type_flags;
    stats.Flags[1] = type_flags2;

    stats.CreatureType = type;
    stats.CreatureFamily = family;
    stats.Classification = rank;

    for (uint32 i = 0; i < MAX_KILL_CREDIT; ++i)
        stats.ProxyCreatureID[i] = KillCredit[i];

    std::transform(Models.begin(), Models.end(), std::back_inserter(stats.Display.CreatureDisplay),
        [&stats](CreatureModel const& model) -> WorldPackets::Query::CreatureXDisplay
    {
        stats.Display.TotalProbability += model.Probability;
        return { model.CreatureDisplayID, model.DisplayScale, model.Probability };
    });

    stats.HpMulti = ModHealth;
    stats.EnergyMulti = ModMana;

    stats.CreatureMovementInfoID = movementId;
    stats.RequiredExpansion = RequiredExpansion;
    stats.HealthScalingExpansion = HealthScalingExpansion;
    stats.VignetteID = VignetteID;
    stats.Class = unit_class;
    stats.CreatureDifficultyID = CreatureDifficultyID;
    stats.WidgetSetID = WidgetSetID;
    stats.WidgetSetUnitConditionID = WidgetSetUnitConditionID;

    stats.Title = SubName;
    stats.TitleAlt = TitleAlt;
    stats.CursorName = IconName;

    if (std::vector<uint32> const* items = sObjectMgr->GetCreatureQuestItemList(Entry))
        stats.QuestItems.insert(stats.QuestItems.begin(), items->begin(), items->end());

    if (loc != LOCALE_enUS)
        if (CreatureLocale const* creatureLocale = sObjectMgr->GetCreatureLocale(Entry))
        {
            ObjectMgr::GetLocaleString(creatureLocale->Name, loc, stats.Name[0]);
            ObjectMgr::GetLocaleString(creatureLocale->NameAlt, loc, stats.NameAlt[0]);
            ObjectMgr::GetLocaleString(creatureLocale->Title, loc, stats.Title);
            ObjectMgr::GetLocaleString(creatureLocale->TitleAlt, loc, stats.TitleAlt);
        }

    queryTemp.Write();
    queryTemp.ShrinkToFit();
    return queryTemp.Move();
}

CreatureLevelScaling const* CreatureTemplate::GetLevelScaling(Difficulty difficulty) const
{
    auto it = scalingStore.find(difficulty);
    if (it != scalingStore.end())
        return &it->second;

    struct DefaultCreatureLevelScaling : public CreatureLevelScaling
    {
        DefaultCreatureLevelScaling()
        {
            DeltaLevelMin = 0;
            DeltaLevelMax = 0;
            ContentTuningID = 0;
        }
    };
    static const DefaultCreatureLevelScaling defScaling;
    return &defScaling;
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
                assistant->EngageWithTarget(victim);
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
    m_owner.DespawnOrUnsummon(0s, m_respawnTimer);    // since we are here, we are not TempSummon as object type cannot change during runtime
    return true;
}

Creature::Creature(bool isWorldObject): Unit(isWorldObject), MapObject(), m_groupLootTimer(0), m_PlayerDamageReq(0), _pickpocketLootRestore(0),
    m_corpseRemoveTime(0), m_respawnTime(0), m_respawnDelay(300), m_corpseDelay(60), m_wanderDistance(0.0f), m_boundaryCheckTime(2500), m_combatPulseTime(0), m_combatPulseDelay(0), m_reactState(REACT_AGGRESSIVE),
    m_defaultMovementType(IDLE_MOTION_TYPE), m_spawnId(UI64LIT(0)), m_equipmentId(0), m_originalEquipmentId(0), m_AlreadyCallAssistance(false), m_AlreadySearchedAssistance(false), m_cannotReachTarget(false), m_cannotReachTimer(0),
    m_meleeDamageSchoolMask(SPELL_SCHOOL_MASK_NORMAL), m_originalEntry(0), m_homePosition(), m_transportHomePosition(), m_creatureInfo(nullptr), m_creatureData(nullptr), _waypointPathId(0), _currentWaypointNodeInfo(0, 0),
    m_formation(nullptr), m_triggerJustAppeared(true), m_respawnCompatibilityMode(false), _lastDamagedTime(0),
    _regenerateHealth(true), _regenerateHealthLock(false)
{
    m_regenTimer = CREATURE_REGEN_INTERVAL;

    for (uint8 i = 0; i < MAX_CREATURE_SPELLS; ++i)
        m_spells[i] = 0;

    DisableReputationGain = false;

    m_SightDistance = sWorld->getFloatConfig(CONFIG_SIGHT_MONSTER);
    m_CombatDistance = 0;//MELEE_RANGE;

    ResetLootMode(); // restore default loot mode
    m_isTempWorldObject = false;
}

void Creature::AddToWorld()
{
    ///- Register the creature for guid lookup
    if (!IsInWorld())
    {
        GetMap()->GetObjectsStore().Insert<Creature>(GetGUID(), this);
        if (m_spawnId)
            GetMap()->GetCreatureBySpawnIdStore().insert(std::make_pair(m_spawnId, this));

        Unit::AddToWorld();
        SearchFormation();
        AIM_Initialize();
        if (IsVehicle())
            GetVehicleKit()->Install();

        if (GetZoneScript())
            GetZoneScript()->OnCreatureCreate(this);
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

bool Creature::IsReturningHome() const
{
    if (GetMotionMaster()->GetCurrentMovementGeneratorType() == HOME_MOTION_TYPE)
        return true;

    return false;
}

void Creature::SearchFormation()
{
    if (IsSummon())
        return;

    ObjectGuid::LowType lowguid = GetSpawnId();
    if (!lowguid)
        return;

    if (FormationInfo const* formationInfo = sFormationMgr->GetFormationInfo(lowguid))
        sFormationMgr->AddCreatureToGroup(formationInfo->LeaderSpawnId, this);
}

bool Creature::IsFormationLeader() const
{
    if (!m_formation)
        return false;

    return m_formation->IsLeader(this);
}

void Creature::SignalFormationMovement()
{
    if (!m_formation)
        return;

    if (!m_formation->IsLeader(this))
        return;

    m_formation->LeaderStartedMoving();
}

bool Creature::IsFormationLeaderMoveAllowed() const
{
    if (!m_formation)
        return false;

    return m_formation->CanLeaderStartMoving();
}

void Creature::RemoveCorpse(bool setSpawnTime, bool destroyForNearbyPlayers)
{
    if (getDeathState() != CORPSE)
        return;

    if (m_respawnCompatibilityMode)
    {
        m_corpseRemoveTime = GameTime::GetGameTime();
        setDeathState(DEAD);
        RemoveAllAuras();
        loot.clear();
        uint32 respawnDelay = m_respawnDelay;
        if (CreatureAI* ai = AI())
            ai->CorpseRemoved(respawnDelay);

        if (destroyForNearbyPlayers)
            DestroyForNearbyPlayers();

        // Should get removed later, just keep "compatibility" with scripts
        if (setSpawnTime)
            m_respawnTime = std::max<time_t>(GameTime::GetGameTime() + respawnDelay, m_respawnTime);

        // if corpse was removed during falling, the falling will continue and override relocation to respawn position
        if (IsFalling())
            StopMoving();

        float x, y, z, o;
        GetRespawnPosition(x, y, z, &o);

        // We were spawned on transport, calculate real position
        if (IsSpawnedOnTransport())
        {
            Position& pos = m_movementInfo.transport.pos;
            pos.m_positionX = x;
            pos.m_positionY = y;
            pos.m_positionZ = z;
            pos.SetOrientation(o);

            if (TransportBase* transport = GetDirectTransport())
                transport->CalculatePassengerPosition(x, y, z, &o);
        }

        UpdateAllowedPositionZ(x, y, z);
        SetHomePosition(x, y, z, o);
        GetMap()->CreatureRelocation(this, x, y, z, o);
    }
    else
    {
        // In case this is called directly and normal respawn timer not set
        // Since this timer will be longer than the already present time it
        // will be ignored if the correct place added a respawn timer
        if (setSpawnTime)
        {
            uint32 respawnDelay = m_respawnDelay;
            m_respawnTime = std::max<time_t>(GameTime::GetGameTime() + respawnDelay, m_respawnTime);

            SaveRespawnTime();
        }

        if (TempSummon* summon = ToTempSummon())
            summon->UnSummon();
        else
            AddObjectToRemoveList();
    }
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
    DifficultyEntry const* difficultyEntry = sDifficultyStore.LookupEntry(GetMap()->GetDifficultyID());
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
    SetRace(RACE_NONE);

    // known valid are: CLASS_WARRIOR, CLASS_PALADIN, CLASS_ROGUE, CLASS_MAGE
    SetClass(uint8(cinfo->unit_class));

    // Cancel load if no model defined
    if (!(cinfo->GetFirstValidModel()))
    {
        TC_LOG_ERROR("sql.sql", "Creature (Entry: %u) has no model defined in table `creature_template`, can't load. ", entry);
        return false;
    }

    CreatureModel model = *ObjectMgr::ChooseDisplayId(cinfo, data);
    CreatureModelInfo const* minfo = sObjectMgr->GetCreatureModelRandomGender(&model, cinfo);
    if (!minfo)                                             // Cancel load if no model defined
    {
        TC_LOG_ERROR("sql.sql", "Creature (Entry: %u) has invalid model %u defined in table `creature_template`, can't load.", entry, model.CreatureDisplayID);
        return false;
    }

    SetDisplayId(model.CreatureDisplayID, model.DisplayScale);
    SetNativeDisplayId(model.CreatureDisplayID, model.DisplayScale);

    // Load creature equipment
    if (!data)
        LoadEquipment();  // use default equipment (if available) for summons
    else if (data->equipmentId == 0)
        LoadEquipment(0); // 0 means no equipment for creature table
    else
    {
        m_originalEquipmentId = data->equipmentId;
        LoadEquipment(data->equipmentId);
    }

    SetName(normalInfo->Name);                              // at normal entry always

    SetModCastingSpeed(1.0f);
    SetModSpellHaste(1.0f);
    SetModHaste(1.0f);
    SetModRangedHaste(1.0f);
    SetModHasteRegen(1.0f);
    SetModTimeRate(1.0f);

    SetSpeedRate(MOVE_WALK,   cinfo->speed_walk);
    SetSpeedRate(MOVE_RUN,    cinfo->speed_run);
    SetSpeedRate(MOVE_SWIM,   1.0f); // using 1.0 rate
    SetSpeedRate(MOVE_FLIGHT, 1.0f); // using 1.0 rate

    // Will set UNIT_FIELD_BOUNDINGRADIUS, UNIT_FIELD_COMBATREACH and UNIT_FIELD_DISPLAYSCALE
    SetObjectScale(GetNativeObjectScale());

    SetHoverHeight(cinfo->HoverHeight);

    SetCanDualWield(cinfo->flags_extra & CREATURE_FLAG_EXTRA_USE_OFFHAND_ATTACK);

    // checked at loading
    m_defaultMovementType = MovementGeneratorType(data ? data->movementType : cinfo->MovementType);
    if (!m_wanderDistance && m_defaultMovementType == RANDOM_MOTION_TYPE)
        m_defaultMovementType = IDLE_MOTION_TYPE;

    for (uint8 i = 0; i < MAX_CREATURE_SPELLS; ++i)
        m_spells[i] = GetCreatureTemplate()->spells[i];

    return true;
}

bool Creature::UpdateEntry(uint32 entry, CreatureData const* data /*= nullptr*/, bool updateLevel /* = true */)
{
    if (!InitEntry(entry, data))
        return false;

    CreatureTemplate const* cInfo = GetCreatureTemplate();

    _regenerateHealth = cInfo->RegenHealth;

    // creatures always have melee weapon ready if any unless specified otherwise
    if (!GetCreatureAddon())
        SetSheath(SHEATH_STATE_MELEE);

    SetFaction(cInfo->faction);

    uint64 npcFlags;
    uint32 unitFlags, unitFlags2, unitFlags3, dynamicFlags;
    ObjectMgr::ChooseCreatureFlags(cInfo, npcFlags, unitFlags, unitFlags2, unitFlags3, dynamicFlags, data);

    if (cInfo->flags_extra & CREATURE_FLAG_EXTRA_WORLDEVENT)
        npcFlags |= sGameEventMgr->GetNPCFlag(this);

    SetNpcFlags(NPCFlags(npcFlags & 0xFFFFFFFF));
    SetNpcFlags2(NPCFlags2(npcFlags >> 32));

    // if unit is in combat, keep this flag
    unitFlags &= ~UNIT_FLAG_IN_COMBAT;
    if (IsInCombat())
        unitFlags |= UNIT_FLAG_IN_COMBAT;

    SetUnitFlags(UnitFlags(unitFlags));
    SetUnitFlags2(UnitFlags2(unitFlags2));
    SetUnitFlags3(UnitFlags3(unitFlags3));

    SetDynamicFlags(dynamicFlags);

    SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::StateAnimID), sDB2Manager.GetEmptyAnimStateID());

    SetCanDualWield(cInfo->flags_extra & CREATURE_FLAG_EXTRA_USE_OFFHAND_ATTACK);

    SetBaseAttackTime(BASE_ATTACK,   cInfo->BaseAttackTime);
    SetBaseAttackTime(OFF_ATTACK,    cInfo->BaseAttackTime);
    SetBaseAttackTime(RANGED_ATTACK, cInfo->RangeAttackTime);

    if (updateLevel)
        SelectLevel();
    else if (!IsGuardian())
    {
        uint32 previousHealth = GetHealth();
        UpdateLevelDependantStats(); // We still re-initialize level dependant stats on entry update
        if (previousHealth > 0)
            SetHealth(previousHealth);
    }

    // Do not update guardian stats here - they are handled in Guardian::InitStatsForLevel()
    if (!IsGuardian())
    {
        SetMeleeDamageSchool(SpellSchools(cInfo->dmgschool));
        SetStatFlatModifier(UNIT_MOD_RESISTANCE_HOLY,   BASE_VALUE, float(cInfo->resistance[SPELL_SCHOOL_HOLY]));
        SetStatFlatModifier(UNIT_MOD_RESISTANCE_FIRE,   BASE_VALUE, float(cInfo->resistance[SPELL_SCHOOL_FIRE]));
        SetStatFlatModifier(UNIT_MOD_RESISTANCE_NATURE, BASE_VALUE, float(cInfo->resistance[SPELL_SCHOOL_NATURE]));
        SetStatFlatModifier(UNIT_MOD_RESISTANCE_FROST,  BASE_VALUE, float(cInfo->resistance[SPELL_SCHOOL_FROST]));
        SetStatFlatModifier(UNIT_MOD_RESISTANCE_SHADOW, BASE_VALUE, float(cInfo->resistance[SPELL_SCHOOL_SHADOW]));
        SetStatFlatModifier(UNIT_MOD_RESISTANCE_ARCANE, BASE_VALUE, float(cInfo->resistance[SPELL_SCHOOL_ARCANE]));

        SetCanModifyStats(true);
        UpdateAllStats();
    }

    // checked and error show at loading templates
    if (FactionTemplateEntry const* factionTemplate = sFactionTemplateStore.LookupEntry(cInfo->faction))
        SetPvP((factionTemplate->Flags & FACTION_TEMPLATE_FLAG_PVP) != 0);

    // updates spell bars for vehicles and set player's faction - should be called here, to overwrite faction that is set from the new template
    if (IsVehicle())
    {
        if (Player* owner = Creature::GetCharmerOrOwnerPlayerOrPlayerItself()) // this check comes in case we don't have a player
        {
            SetFaction(owner->GetFaction()); // vehicles should have same as owner faction
            owner->VehicleSpellInitialize();
        }
    }

    // trigger creature is always not selectable and can not be attacked
    if (IsTrigger())
        AddUnitFlag(UNIT_FLAG_NOT_SELECTABLE);

    InitializeReactState();

    if (cInfo->flags_extra & CREATURE_FLAG_EXTRA_NO_TAUNT)
    {
        ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, true);
        ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_ATTACK_ME, true);
    }

    LoadTemplateRoot();
    InitializeMovementFlags();

    LoadCreaturesAddon();
    LoadTemplateImmunities();

    GetThreatManager().EvaluateSuppressed();

    //We must update last scriptId or it looks like we reloaded a script, breaking some things such as gossip temporarily
    LastUsedScriptID = GetScriptId();

    return true;
}

void Creature::Update(uint32 diff)
{
    if (IsAIEnabled() && m_triggerJustAppeared && m_deathState != DEAD)
    {
        if (m_respawnCompatibilityMode && m_vehicleKit)
            m_vehicleKit->Reset();
        m_triggerJustAppeared = false;
        AI()->JustAppeared();
    }

    UpdateMovementFlags();

    switch (m_deathState)
    {
        case JUST_RESPAWNED:
            // Must not be called, see Creature::setDeathState JUST_RESPAWNED -> ALIVE promoting.
            TC_LOG_ERROR("entities.unit", "Creature %s in wrong state: JUST_RESPAWNED (4)", GetGUID().ToString().c_str());
            break;
        case JUST_DIED:
            // Must not be called, see Creature::setDeathState JUST_DIED -> CORPSE promoting.
            TC_LOG_ERROR("entities.unit", "Creature %s in wrong state: JUST_DIED (1)", GetGUID().ToString().c_str());
            break;
        case DEAD:
        {
            if (!m_respawnCompatibilityMode)
            {
                TC_LOG_ERROR("entities.unit", "Creature %s in wrong state: DEAD (3)", GetGUID().ToString().c_str());
                break;
            }
            time_t now = GameTime::GetGameTime();
            if (m_respawnTime <= now)
            {
                // Delay respawn if spawn group is not active
                if (m_creatureData && !GetMap()->IsSpawnGroupActive(m_creatureData->spawnGroupData->groupId))
                {
                    m_respawnTime = now + urand(4,7);
                    break; // Will be rechecked on next Update call after delay expires
                }

                ObjectGuid dbtableHighGuid = ObjectGuid::Create<HighGuid::Creature>(GetMapId(), GetEntry(), m_spawnId);
                time_t linkedRespawnTime = GetMap()->GetLinkedRespawnTime(dbtableHighGuid);
                if (!linkedRespawnTime)             // Can respawn
                    Respawn();
                else                                // the master is dead
                {
                    ObjectGuid targetGuid = sObjectMgr->GetLinkedRespawnGuid(dbtableHighGuid);
                    if (targetGuid == dbtableHighGuid) // if linking self, never respawn
                        SetRespawnTime(WEEK);
                    else
                    {
                        // else copy time from master and add a little
                        time_t baseRespawnTime = std::max(linkedRespawnTime, now);
                        time_t const offset = urand(5, MINUTE);

                        // linked guid can be a boss, uses std::numeric_limits<time_t>::max to never respawn in that instance
                        // we shall inherit it instead of adding and causing an overflow
                        if (baseRespawnTime <= std::numeric_limits<time_t>::max() - offset)
                            m_respawnTime = baseRespawnTime + offset;
                        else
                            m_respawnTime = std::numeric_limits<time_t>::max();
                    }
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

            if (IsEngaged())
                Unit::AIUpdateTick(diff);

            if (m_groupLootTimer && !lootingGroupLowGUID.IsEmpty())
            {
                if (m_groupLootTimer <= diff)
                {
                    if (Group* group = sGroupMgr->GetGroupByGUID(lootingGroupLowGUID))
                        group->EndRoll(&loot, GetMap());

                    m_groupLootTimer = 0;
                    lootingGroupLowGUID.Clear();
                }
                else
                    m_groupLootTimer -= diff;
            }
            else if (m_corpseRemoveTime <= GameTime::GetGameTime())
            {
                RemoveCorpse(false);
                TC_LOG_DEBUG("entities.unit", "Removing corpse... %u ", GetEntry());
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

            GetThreatManager().Update(diff);
            if (_spellFocusInfo.Delay)
            {
                if (_spellFocusInfo.Delay <= diff)
                    ReacquireSpellFocusTarget();
                else
                    _spellFocusInfo.Delay -= diff;
            }

            // periodic check to see if the creature has passed an evade boundary
            if (IsAIEnabled() && !IsInEvadeMode() && IsEngaged())
            {
                if (diff >= m_boundaryCheckTime)
                {
                    AI()->CheckInRoom();
                    m_boundaryCheckTime = 2500;
                } else
                    m_boundaryCheckTime -= diff;
            }

            // if periodic combat pulse is enabled and we are both in combat and in a dungeon, do this now
            if (m_combatPulseDelay > 0 && IsEngaged() && GetMap()->IsDungeon())
            {
                if (diff > m_combatPulseTime)
                    m_combatPulseTime = 0;
                else
                    m_combatPulseTime -= diff;

                if (m_combatPulseTime == 0)
                {
                    Map::PlayerList const& players = GetMap()->GetPlayers();
                    if (!players.isEmpty())
                        for (Map::PlayerList::const_iterator it = players.begin(); it != players.end(); ++it)
                        {
                            if (Player* player = it->GetSource())
                            {
                                if (player->IsGameMaster())
                                    continue;

                                if (player->IsAlive() && IsHostileTo(player))
                                    EngageWithTarget(player);
                            }
                        }

                    m_combatPulseTime = m_combatPulseDelay * IN_MILLISECONDS;
                }
            }

            Unit::AIUpdateTick(diff);

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
                if (!IsInEvadeMode())
                {
                    // regenerate health if not in combat or if polymorphed)
                    if (!IsEngaged() || IsPolymorphed())
                        RegenerateHealth();
                    else if (CanNotReachTarget())
                    {
                        // regenerate health if cannot reach the target and the setting is set to do so.
                        // this allows to disable the health regen of raid bosses if pathfinding has issues for whatever reason
                        if (sWorld->getBoolConfig(CONFIG_REGEN_HP_CANNOT_REACH_TARGET_IN_RAID) || !GetMap()->IsRaid())
                        {
                            RegenerateHealth();
                            TC_LOG_DEBUG("entities.unit.chase", "RegenerateHealth() enabled because Creature cannot reach the target. Detail: %s", GetDebugInfo().c_str());
                        }
                        else
                            TC_LOG_DEBUG("entities.unit.chase", "RegenerateHealth() disabled even if the Creature cannot reach the target. Detail: %s", GetDebugInfo().c_str());
                    }
                }

                if (GetPowerType() == POWER_ENERGY)
                    Regenerate(POWER_ENERGY);
                else
                    Regenerate(POWER_MANA);

                m_regenTimer = CREATURE_REGEN_INTERVAL;
            }

            if (CanNotReachTarget() && !IsInEvadeMode() && !GetMap()->IsRaid())
            {
                m_cannotReachTimer += diff;
                if (m_cannotReachTimer >= CREATURE_NOPATH_EVADE_TIME)
                    if (CreatureAI* ai = AI())
                        ai->EnterEvadeMode(CreatureAI::EVADE_REASON_NO_PATH);
            }
            break;
        }
        default:
            break;
    }
}

void Creature::Regenerate(Powers power)
{
    uint32 curValue = GetPower(power);
    uint32 maxValue = GetMaxPower(power);

    if (!HasUnitFlag2(UNIT_FLAG2_REGENERATE_POWER))
        return;

    if (curValue >= maxValue)
        return;

    float addvalue = 0.0f;

    switch (power)
    {
    case POWER_FOCUS:
    {
        // For hunter pets.
        addvalue = 24 * sWorld->getRate(RATE_POWER_FOCUS);
        break;
    }
    case POWER_ENERGY:
    {
        // For deathknight's ghoul.
        addvalue = 20;
        break;
    }
    case POWER_MANA:
    {
        // Combat and any controlled creature
        if (IsInCombat() || GetCharmerOrOwnerGUID().IsEmpty())
        {
            float ManaIncreaseRate = sWorld->getRate(RATE_POWER_MANA);

            addvalue = uint32((27.0f / 5.0f + 17.0f) * ManaIncreaseRate);
        }
        else
            addvalue = maxValue / 3;

        break;
    }
    default:
        return;
    }

    // Apply modifiers (if any).
    addvalue *= GetTotalAuraMultiplierByMiscValue(SPELL_AURA_MOD_POWER_REGEN_PERCENT, power);

    addvalue += GetTotalAuraModifierByMiscValue(SPELL_AURA_MOD_POWER_REGEN, power) * (IsHunterPet() ? PET_FOCUS_REGEN_INTERVAL : CREATURE_REGEN_INTERVAL) / (5 * IN_MILLISECONDS);

    ModifyPower(power, int32(addvalue));
}

void Creature::RegenerateHealth()
{
    if (!CanRegenerateHealth())
        return;

    uint32 curValue = GetHealth();
    uint32 maxValue = GetMaxHealth();

    if (curValue >= maxValue)
        return;

    uint32 addvalue = 0;

    // Not only pet, but any controlled creature (and not polymorphed)
    if (!GetCharmerOrOwnerGUID().IsEmpty() && !IsPolymorphed())
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

        if (!creature)
            /// @todo use 31365
            SetControlled(true, UNIT_STATE_FLEEING);
        else
            GetMotionMaster()->MoveSeekAssistance(creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ());
    }
}

bool Creature::AIM_Destroy()
{
    PopAI();
    RefreshAI();
    return true;
}

bool Creature::AIM_Create(CreatureAI* ai /*= nullptr*/)
{
    Motion_Initialize();

    SetAI(ai ? ai : FactorySelector::SelectAI(this));

    return true;
}

bool Creature::AIM_Initialize(CreatureAI* ai)
{
    if (!AIM_Create(ai))
        return false;

    AI()->InitializeAI();
    if (GetVehicleKit())
        GetVehicleKit()->Reset();
    return true;
}

void Creature::Motion_Initialize()
{
    if (m_formation)
    {
        if (m_formation->GetLeader() == this)
            m_formation->FormationReset(false);
        else if (m_formation->IsFormed())
        {
            GetMotionMaster()->MoveIdle(); // wait the order of leader
            return;
        }
    }

    GetMotionMaster()->Initialize();
}

bool Creature::Create(ObjectGuid::LowType guidlow, Map* map, uint32 entry, Position const& pos, CreatureData const* data /*= nullptr*/, uint32 vehId /*= 0*/, bool dynamic)
{
    ASSERT(map);
    SetMap(map);

    if (data)
    {
        PhasingHandler::InitDbPhaseShift(GetPhaseShift(), data->phaseUseFlags, data->phaseId, data->phaseGroup);
        PhasingHandler::InitDbVisibleMapId(GetPhaseShift(), data->terrainSwapMap);
    }

    // Set if this creature can handle dynamic spawns
    if (!dynamic)
        SetRespawnCompatibilityMode();

    CreatureTemplate const* cinfo = sObjectMgr->GetCreatureTemplate(entry);
    if (!cinfo)
    {
        TC_LOG_ERROR("sql.sql", "Creature::Create(): creature template (guidlow: " UI64FMTD ", entry: %u) does not exist.", guidlow, entry);
        return false;
    }

    //! Relocate before CreateFromProto, to initialize coords and allow
    //! returning correct zone id for selecting OutdoorPvP/Battlefield script
    Relocate(pos);

    // Check if the position is valid before calling CreateFromProto(), otherwise we might add Auras to Creatures at
    // invalid position, triggering a crash about Auras not removed in the destructor
    if (!IsPositionValid())
    {
        TC_LOG_ERROR("entities.unit", "Creature::Create(): given coordinates for creature (guidlow " UI64FMTD ", entry %d) are not valid (X: %f, Y: %f, Z: %f, O: %f)", guidlow, entry, pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), pos.GetOrientation());
        return false;
    }
    {
        // area/zone id is needed immediately for ZoneScript::GetCreatureEntry hook before it is known which creature template to load (no model/scale available yet)
        PositionFullTerrainStatus data;
        GetMap()->GetFullTerrainStatusForPosition(GetPhaseShift(), GetPositionX(), GetPositionY(), GetPositionZ(), data, map_liquidHeaderTypeFlags::AllLiquids, DEFAULT_COLLISION_HEIGHT);
        ProcessPositionDataChanged(data);
    }

    // Allow players to see those units while dead, do it here (mayby altered by addon auras)
    if (cinfo->type_flags & CREATURE_TYPE_FLAG_GHOST_VISIBLE)
        m_serverSideVisibility.SetValue(SERVERSIDE_VISIBILITY_GHOST, GHOST_VISIBILITY_ALIVE | GHOST_VISIBILITY_GHOST);

    if (!CreateFromProto(guidlow, entry, data, vehId))
        return false;

    cinfo = GetCreatureTemplate(); // might be different than initially requested
    if (cinfo->flags_extra & CREATURE_FLAG_EXTRA_DUNGEON_BOSS && map->IsDungeon())
        m_respawnDelay = 0; // special value, prevents respawn for dungeon bosses unless overridden

    switch (cinfo->rank)
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
    m_positionZ += GetHoverOffset();

    LastUsedScriptID = GetScriptId();

    if (IsSpiritHealer() || IsSpiritGuide() || (GetCreatureTemplate()->flags_extra & CREATURE_FLAG_EXTRA_GHOST_VISIBILITY))
    {
        m_serverSideVisibility.SetValue(SERVERSIDE_VISIBILITY_GHOST, GHOST_VISIBILITY_GHOST);
        m_serverSideVisibilityDetect.SetValue(SERVERSIDE_VISIBILITY_GHOST, GHOST_VISIBILITY_GHOST);
    }

    if (cinfo->flags_extra & CREATURE_FLAG_EXTRA_IGNORE_PATHFINDING)
        AddUnitState(UNIT_STATE_IGNORE_PATHFINDING);

    if (cinfo->flags_extra & CREATURE_FLAG_EXTRA_IMMUNITY_KNOCKBACK)
    {
        ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
        ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK_DEST, true);
    }

    GetThreatManager().Initialize();

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
    if (!creature->Create(lowGuid, map, entry, pos, nullptr, vehId))
    {
        delete creature;
        return nullptr;
    }

    return creature;
}

Creature* Creature::CreateCreatureFromDB(ObjectGuid::LowType spawnId, Map* map, bool addToMap /*= true*/, bool allowDuplicate /*= false*/)
{
    Creature* creature = new Creature();
    if (!creature->LoadFromDB(spawnId, map, addToMap, allowDuplicate))
    {
        delete creature;
        return nullptr;
    }

    return creature;
}

Unit* Creature::SelectVictim()
{
    Unit* target = nullptr;

    if (CanHaveThreatList())
        target = GetThreatManager().GetCurrentVictim();
    else if (!HasReactState(REACT_PASSIVE))
    {
        // We're a player pet, probably
        target = getAttackerForHelper();
        if (!target && IsSummon())
        {
            if (Unit* owner = ToTempSummon()->GetOwner())
            {
                if (owner->IsInCombat())
                    target = owner->getAttackerForHelper();
                if (!target)
                {
                    for (ControlList::const_iterator itr = owner->m_Controlled.begin(); itr != owner->m_Controlled.end(); ++itr)
                    {
                        if ((*itr)->IsInCombat())
                        {
                            target = (*itr)->getAttackerForHelper();
                            if (target)
                                break;
                        }
                    }
                }
            }
        }
    }
    else
        return nullptr;

    if (target && _IsTargetAcceptable(target) && CanCreatureAttack(target))
    {
        if (!HasSpellFocus())
            SetInFront(target);
        return target;
    }

    /// @todo a vehicle may eat some mob, so mob should not evade
    if (GetVehicle())
        return nullptr;

    Unit::AuraEffectList const& iAuras = GetAuraEffectsByType(SPELL_AURA_MOD_INVISIBILITY);
    if (!iAuras.empty())
    {
        for (Unit::AuraEffectList::const_iterator itr = iAuras.begin(); itr != iAuras.end(); ++itr)
        {
            if ((*itr)->GetBase()->IsPermanent())
            {
                AI()->EnterEvadeMode(CreatureAI::EVADE_REASON_OTHER);
                break;
            }
        }
        return nullptr;
    }

    // enter in evade mode in other case
    AI()->EnterEvadeMode(CreatureAI::EVADE_REASON_NO_HOSTILES);

    return nullptr;
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
    return player->GetLevel() >= 15
        && player->GetClass() == GetCreatureTemplate()->trainer_class;
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

void Creature::SetLootRecipient(Unit* unit, bool withGroup)
{
    // set the player whose group should receive the right
    // to loot the creature after it dies
    // should be set to nullptr after the loot disappears

    if (!unit)
    {
        m_lootRecipient.Clear();
        m_lootRecipientGroup.Clear();
        RemoveDynamicFlag(UNIT_DYNFLAG_LOOTABLE | UNIT_DYNFLAG_TAPPED);
        return;
    }

    if (unit->GetTypeId() != TYPEID_PLAYER && !unit->IsVehicle())
        return;

    Player* player = unit->GetCharmerOrOwnerPlayerOrPlayerItself();
    if (!player)                                             // normal creature, no player involved
        return;

    m_lootRecipient = player->GetGUID();
    if (withGroup)
    {
        if (Group* group = player->GetGroup())
            m_lootRecipientGroup = group->GetGUID();
    }
    else
        m_lootRecipientGroup = ObjectGuid::Empty;

    AddDynamicFlag(UNIT_DYNFLAG_TAPPED);
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
    SaveToDB(mapId, data->spawnDifficulties);
}

void Creature::SaveToDB(uint32 mapid, std::vector<Difficulty> const& spawnDifficulties)
{
    // update in loaded data
    if (!m_spawnId)
        m_spawnId = sObjectMgr->GenerateCreatureSpawnId();

    CreatureData& data = sObjectMgr->NewOrExistCreatureData(m_spawnId);

    uint32 displayId = GetNativeDisplayId();
    uint64 npcflag = (uint64(m_unitData->NpcFlags[1]) << 32) | m_unitData->NpcFlags[0];
    uint32 unitFlags = m_unitData->Flags;
    uint32 unitFlags2 = m_unitData->Flags2;
    uint32 unitFlags3 = m_unitData->Flags3;
    uint32 dynamicflags = m_objectData->DynamicFlags;

    // check if it's a custom model and if not, use 0 for displayId
    CreatureTemplate const* cinfo = GetCreatureTemplate();
    if (cinfo)
    {
        for (CreatureModel model : cinfo->Models)
            if (displayId && displayId == model.CreatureDisplayID)
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

    if (!data.spawnId)
        data.spawnId = m_spawnId;
    ASSERT(data.spawnId == m_spawnId);
    data.id = GetEntry();
    data.displayid = displayId;
    data.equipmentId = GetCurrentEquipmentId();
    if (!GetTransport())
    {
        data.mapId = GetMapId();
        data.spawnPoint.Relocate(this);
    }
    else
    {
        data.mapId = mapid;
        data.spawnPoint.Relocate(GetTransOffsetX(), GetTransOffsetY(), GetTransOffsetZ(), GetTransOffsetO());
    }
    data.spawntimesecs = m_respawnDelay;
    // prevent add data integrity problems
    data.wander_distance = GetDefaultMovementType() == IDLE_MOTION_TYPE ? 0.0f : m_wanderDistance;
    data.currentwaypoint = 0;
    data.curhealth = GetHealth();
    data.curmana = GetPower(POWER_MANA);
    // prevent add data integrity problems
    data.movementType = !m_wanderDistance && GetDefaultMovementType() == RANDOM_MOTION_TYPE
        ? IDLE_MOTION_TYPE : GetDefaultMovementType();
    data.spawnDifficulties = spawnDifficulties;
    data.npcflag = npcflag;
    data.unit_flags = unitFlags;
    data.unit_flags2 = unitFlags2;
    data.unit_flags3 = unitFlags3;
    data.dynamicflags = dynamicflags;
    if (!data.spawnGroupData)
        data.spawnGroupData = sObjectMgr->GetDefaultSpawnGroup();

    data.phaseId = GetDBPhase() > 0 ? GetDBPhase() : data.phaseId;
    data.phaseGroup = GetDBPhase() < 0 ? -GetDBPhase() : data.phaseGroup;

    // update in DB
    WorldDatabaseTransaction trans = WorldDatabase.BeginTransaction();

    WorldDatabasePreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_DEL_CREATURE);
    stmt->setUInt64(0, m_spawnId);
    trans->Append(stmt);

    uint8 index = 0;

    stmt = WorldDatabase.GetPreparedStatement(WORLD_INS_CREATURE);
    stmt->setUInt64(index++, m_spawnId);
    stmt->setUInt32(index++, GetEntry());
    stmt->setUInt16(index++, uint16(mapid));
    stmt->setString(index++, [&data]() -> std::string
    {
        if (data.spawnDifficulties.empty())
            return "";

        std::ostringstream os;
        auto itr = data.spawnDifficulties.begin();
        os << int32(*itr++);

        for (; itr != data.spawnDifficulties.end(); ++itr)
            os << ',' << int32(*itr);

        return os.str();
    }());
    stmt->setUInt32(index++, data.phaseId);
    stmt->setUInt32(index++, data.phaseGroup);
    stmt->setUInt32(index++, displayId);
    stmt->setUInt8(index++, GetCurrentEquipmentId());
    stmt->setFloat(index++, GetPositionX());
    stmt->setFloat(index++, GetPositionY());
    stmt->setFloat(index++, GetPositionZ());
    stmt->setFloat(index++, GetOrientation());
    stmt->setUInt32(index++, m_respawnDelay);
    stmt->setFloat(index++, m_wanderDistance);
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

    // level
    std::pair<int16, int16> levels = cInfo->GetMinMaxLevel();
    uint8 minlevel = std::min(levels.first, levels.second);
    uint8 maxlevel = std::max(levels.first, levels.second);
    uint8 level = minlevel == maxlevel ? minlevel : urand(minlevel, maxlevel);
    SetLevel(level);

    CreatureLevelScaling const* scaling = cInfo->GetLevelScaling(GetMap()->GetDifficultyID());

    if (Optional<ContentTuningLevels> levels = sDB2Manager.GetContentTuningData(scaling->ContentTuningID, 0))
    {
        SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::ScalingLevelMin), levels->MinLevel);
        SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::ScalingLevelMax), levels->MaxLevel);
    }

    int32 mindelta = std::min(scaling->DeltaLevelMax, scaling->DeltaLevelMin);
    int32 maxdelta = std::max(scaling->DeltaLevelMax, scaling->DeltaLevelMin);
    int32 delta = mindelta == maxdelta ? mindelta : irand(mindelta, maxdelta);

    SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::ScalingLevelDelta), delta);
    SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::ContentTuningID), scaling->ContentTuningID);

    UpdateLevelDependantStats();
}

void Creature::UpdateLevelDependantStats()
{
    CreatureTemplate const* cInfo = GetCreatureTemplate();
    uint32 rank = IsPet() ? 0 : cInfo->rank;
    uint8 level = GetLevel();
    CreatureBaseStats const* stats = sObjectMgr->GetCreatureBaseStats(level, cInfo->unit_class);

    // health
    float healthmod = _GetHealthMod(rank);

    uint32 basehp = GetMaxHealthByLevel(level);
    uint32 health = uint32(basehp * healthmod);

    SetCreateHealth(health);
    SetMaxHealth(health);
    SetHealth(health);
    ResetPlayerDamageReq();

    // mana
    uint32 mana = stats->GenerateMana(cInfo);
    SetCreateMana(mana);

    switch (GetClass())
    {
        case CLASS_PALADIN:
        case CLASS_MAGE:
            SetMaxPower(POWER_MANA, mana);
            SetFullPower(POWER_MANA);
            break;
        default: // We don't set max power here, 0 makes power bar hidden
            break;
    }

    SetStatFlatModifier(UNIT_MOD_HEALTH, BASE_VALUE, (float)health);

    // damage
    float basedamage = GetBaseDamageForLevel(level);

    float weaponBaseMinDamage = basedamage;
    float weaponBaseMaxDamage = basedamage * 1.5f;

    SetBaseWeaponDamage(BASE_ATTACK, MINDAMAGE, weaponBaseMinDamage);
    SetBaseWeaponDamage(BASE_ATTACK, MAXDAMAGE, weaponBaseMaxDamage);

    SetBaseWeaponDamage(OFF_ATTACK, MINDAMAGE, weaponBaseMinDamage);
    SetBaseWeaponDamage(OFF_ATTACK, MAXDAMAGE, weaponBaseMaxDamage);

    SetBaseWeaponDamage(RANGED_ATTACK, MINDAMAGE, weaponBaseMinDamage);
    SetBaseWeaponDamage(RANGED_ATTACK, MAXDAMAGE, weaponBaseMaxDamage);

    SetStatFlatModifier(UNIT_MOD_ATTACK_POWER, BASE_VALUE, stats->AttackPower);
    SetStatFlatModifier(UNIT_MOD_ATTACK_POWER_RANGED, BASE_VALUE, stats->RangedAttackPower);

    float armor = GetBaseArmorForLevel(level); /// @todo Why is this treated as uint32 when it's a float?
    SetStatFlatModifier(UNIT_MOD_ARMOR, BASE_VALUE, armor);
}

void Creature::SelectWildBattlePetLevel()
{
    if (IsWildBattlePet())
    {
        uint8 wildBattlePetLevel = WILD_BATTLE_PET_DEFAULT_LEVEL;

        if (AreaTableEntry const* areaTable = sAreaTableStore.LookupEntry(GetZoneId()))
            if (areaTable->WildBattlePetLevelMin > 0)
                wildBattlePetLevel = urand(areaTable->WildBattlePetLevelMin, areaTable->WildBattlePetLevelMax);

        SetWildBattlePetLevel(wildBattlePetLevel);
    }
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
        if (CreateVehicleKit(vehId, entry, true))
            UpdateDisplayPower();

    return true;
}

bool Creature::LoadFromDB(ObjectGuid::LowType spawnId, Map* map, bool addToMap, bool allowDuplicate)
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
        TC_LOG_ERROR("sql.sql", "Creature (SpawnID " UI64FMTD ") not found in table `creature`, can't load. ", spawnId);
        return false;
    }

    m_spawnId = spawnId;

    m_respawnCompatibilityMode = ((data->spawnGroupData->flags & SPAWNGROUP_FLAG_COMPATIBILITY_MODE) != 0);
    m_creatureData = data;
    m_wanderDistance = data->wander_distance;
    m_respawnDelay = data->spawntimesecs;

    if (!Create(map->GenerateLowGuid<HighGuid::Creature>(), map, data->id, data->spawnPoint, data, 0U , !m_respawnCompatibilityMode))
        return false;

    //We should set first home position, because then AI calls home movement
    SetHomePosition(*this);

    m_deathState = ALIVE;

    m_respawnTime = GetMap()->GetCreatureRespawnTime(m_spawnId);

    if (!m_respawnTime && !map->IsSpawnGroupActive(data->spawnGroupData->groupId))
    {
        if (!m_respawnCompatibilityMode)
        {
            // @todo pools need fixing! this is just a temporary thing, but they violate dynspawn principles
            if (!sPoolMgr->IsPartOfAPool<Creature>(spawnId))
            {
                TC_LOG_ERROR("entities.unit", "Creature (SpawnID " UI64FMTD ") trying to load in inactive spawn group '%s':\n%s", spawnId, data->spawnGroupData->name.c_str(), GetDebugInfo().c_str());
                return false;
            }
        }

        m_respawnTime = GameTime::GetGameTime() + urand(4, 7);
    }

    if (m_respawnTime)
    {
        if (!m_respawnCompatibilityMode)
        {
            // @todo same as above
            if (!sPoolMgr->IsPartOfAPool<Creature>(spawnId))
            {
                TC_LOG_ERROR("entities.unit", "Creature (SpawnID " UI64FMTD ") trying to load despite a respawn timer in progress:\n%s", spawnId, GetDebugInfo().c_str());
                return false;
            }
        }

        // compatibility mode creatures will be respawned in ::Update()
        m_deathState = DEAD;
        if (CanFly())
        {
            float tz = map->GetHeight(GetPhaseShift(), data->spawnPoint, true, MAX_FALL_DISTANCE);
            if (data->spawnPoint.GetPositionZ() - tz > 0.1f && Trinity::IsValidMapCoord(tz))
                Relocate(data->spawnPoint.GetPositionX(), data->spawnPoint.GetPositionY(), tz);
        }
    }

    SetSpawnHealth();

    SelectWildBattlePetLevel();

    // checked at creature_template loading
    m_defaultMovementType = MovementGeneratorType(data->movementType);

    loot.SetGUID(ObjectGuid::Create<HighGuid::LootObject>(GetMapId(), data->id, GetMap()->GenerateLowGuid<HighGuid::LootObject>()));

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
    if (_regenerateHealthLock)
        return;

    uint32 curhealth;
    if (m_creatureData && !_regenerateHealth)
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

void Creature::LoadTemplateRoot()
{
    if (GetMovementTemplate().IsRooted())
        SetControlled(true, UNIT_STATE_ROOT);
}

bool Creature::hasQuest(uint32 quest_id) const
{
    return sObjectMgr->GetCreatureQuestRelations(GetEntry()).HasQuest(quest_id);
}

bool Creature::hasInvolvedQuest(uint32 quest_id) const
{
    return sObjectMgr->GetCreatureQuestInvolvedRelations(GetEntry()).HasQuest(quest_id);
}

/*static*/ bool Creature::DeleteFromDB(ObjectGuid::LowType spawnId)
{
    CreatureData const* data = sObjectMgr->GetCreatureData(spawnId);
    if (!data)
        return false;

    CharacterDatabaseTransaction charTrans = CharacterDatabase.BeginTransaction();

    sMapMgr->DoForAllMapsWithMapId(data->mapId,
        [spawnId, charTrans](Map* map) -> void
        {
            // despawn all active creatures, and remove their respawns
            std::vector<Creature*> toUnload;
            for (auto const& pair : Trinity::Containers::MapEqualRange(map->GetCreatureBySpawnIdStore(), spawnId))
                toUnload.push_back(pair.second);
            for (Creature* creature : toUnload)
                map->AddObjectToRemoveList(creature);
            map->RemoveRespawnTime(SPAWN_TYPE_CREATURE, spawnId, charTrans);
        }
    );

    // delete data from memory ...
    sObjectMgr->DeleteCreatureData(spawnId);

    CharacterDatabase.CommitTransaction(charTrans);

    WorldDatabaseTransaction trans = WorldDatabase.BeginTransaction();

    // ... and the database
    WorldDatabasePreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_DEL_CREATURE);
    stmt->setUInt64(0, spawnId);
    trans->Append(stmt);

    stmt = WorldDatabase.GetPreparedStatement(WORLD_DEL_SPAWNGROUP_MEMBER);
    stmt->setUInt8(0, uint8(SPAWN_TYPE_CREATURE));
    stmt->setUInt64(1, spawnId);
    trans->Append(stmt);

    stmt = WorldDatabase.GetPreparedStatement(WORLD_DEL_CREATURE_ADDON);
    stmt->setUInt64(0, spawnId);
    trans->Append(stmt);

    stmt = WorldDatabase.GetPreparedStatement(WORLD_DEL_GAME_EVENT_CREATURE);
    stmt->setUInt64(0, spawnId);
    trans->Append(stmt);

    stmt = WorldDatabase.GetPreparedStatement(WORLD_DEL_GAME_EVENT_MODEL_EQUIP);
    stmt->setUInt64(0, spawnId);
    trans->Append(stmt);

    stmt = WorldDatabase.GetPreparedStatement(WORLD_DEL_LINKED_RESPAWN);
    stmt->setUInt64(0, spawnId);
    stmt->setUInt32(1, LINKED_RESPAWN_CREATURE_TO_CREATURE);
    trans->Append(stmt);

    stmt = WorldDatabase.GetPreparedStatement(WORLD_DEL_LINKED_RESPAWN);
    stmt->setUInt64(0, spawnId);
    stmt->setUInt32(1, LINKED_RESPAWN_CREATURE_TO_GO);
    trans->Append(stmt);

    stmt = WorldDatabase.GetPreparedStatement(WORLD_DEL_LINKED_RESPAWN_MASTER);
    stmt->setUInt64(0, spawnId);
    stmt->setUInt32(1, LINKED_RESPAWN_CREATURE_TO_CREATURE);
    trans->Append(stmt);

    stmt = WorldDatabase.GetPreparedStatement(WORLD_DEL_LINKED_RESPAWN_MASTER);
    stmt->setUInt64(0, spawnId);
    stmt->setUInt32(1, LINKED_RESPAWN_GO_TO_CREATURE);
    trans->Append(stmt);

    WorldDatabase.CommitTransaction(trans);

    return true;
}

bool Creature::IsInvisibleDueToDespawn() const
{
    if (Unit::IsInvisibleDueToDespawn())
        return true;

    if (IsAlive() || isDying() || m_corpseRemoveTime > GameTime::GetGameTime())
        return false;

    return true;
}

bool Creature::CanAlwaysSee(WorldObject const* obj) const
{
    if (IsAIEnabled() && AI()->CanSeeAlways(obj))
        return true;

    return false;
}

bool Creature::CanStartAttack(Unit const* who, bool force) const
{
    if (IsCivilian())
        return false;

    // This set of checks is should be done only for creatures
    if ((IsImmuneToNPC() && !who->HasUnitFlag(UNIT_FLAG_PLAYER_CONTROLLED))
        || (IsImmuneToPC() && who->HasUnitFlag(UNIT_FLAG_PLAYER_CONTROLLED)))
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
    float aggroRate = sWorld->getRate(RATE_CREATURE_AGGRO);
    if (aggroRate == 0)
        return 0.0f;

    // WoW Wiki: the minimum radius seems to be 5 yards, while the maximum range is 45 yards
    float maxRadius = 45.0f * aggroRate;
    float minRadius = 5.0f * aggroRate;

    int32 expansionMaxLevel = int32(GetMaxLevelForExpansion(GetCreatureTemplate()->RequiredExpansion));
    int32 playerLevel = player->GetLevelForTarget(this);
    int32 creatureLevel = GetLevelForTarget(player);
    int32 levelDifference = creatureLevel - playerLevel;

    // The aggro radius for creatures with equal level as the player is 20 yards.
    // The combatreach should not get taken into account for the distance so we drop it from the range (see Supremus as expample)
    float baseAggroDistance = 20.0f - GetCombatReach();

    // + - 1 yard for each level difference between player and creature
    float aggroRadius = baseAggroDistance + float(levelDifference);

    // detect range auras
    if (uint32(creatureLevel + 5) <= sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL))
    {
        aggroRadius += GetTotalAuraModifier(SPELL_AURA_MOD_DETECT_RANGE);
        aggroRadius += player->GetTotalAuraModifier(SPELL_AURA_MOD_DETECTED_RANGE);
    }

    // The aggro range of creatures with higher levels than the total player level for the expansion should get the maxlevel treatment
    // This makes sure that creatures such as bosses wont have a bigger aggro range than the rest of the npc's
    // The following code is used for blizzlike behaviour such as skippable bosses
    if (creatureLevel > expansionMaxLevel)
        aggroRadius = baseAggroDistance + float(expansionMaxLevel - playerLevel);

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
        m_corpseRemoveTime = GameTime::GetGameTime() + m_corpseDelay;

        uint32 respawnDelay = m_respawnDelay;
        if (uint32 scalingMode = sWorld->getIntConfig(CONFIG_RESPAWN_DYNAMICMODE))
            GetMap()->ApplyDynamicModeRespawnScaling(this, m_spawnId, respawnDelay, scalingMode);
        // @todo remove the boss respawn time hack in a dynspawn follow-up once we have creature groups in instances
        if (m_respawnCompatibilityMode)
        {
            if (IsDungeonBoss() && !m_respawnDelay)
                m_respawnTime = std::numeric_limits<time_t>::max(); // never respawn in this instance
            else
                m_respawnTime = GameTime::GetGameTime() + respawnDelay + m_corpseDelay;
        }
        else
        {
            if (IsDungeonBoss() && !m_respawnDelay)
                m_respawnTime = std::numeric_limits<time_t>::max(); // never respawn in this instance
            else
                m_respawnTime = GameTime::GetGameTime() + respawnDelay;
        }

        SaveRespawnTime();

        ReleaseSpellFocus(nullptr, false); // remove spellcast focus
        DoNotReacquireSpellFocusTarget();  // cancel delayed re-target
        SetTarget(ObjectGuid::Empty);      // drop target - dead mobs shouldn't ever target things

        SetNpcFlags(UNIT_NPC_FLAG_NONE);
        SetNpcFlags2(UNIT_NPC_FLAG_2_NONE);

        SetMountDisplayId(0); // if creature is mounted on a virtual mount, remove it at death

        setActive(false);

        SetNoSearchAssistance(false);

        //Dismiss group if is leader
        if (m_formation && m_formation->GetLeader() == this)
            m_formation->FormationReset(true);

        bool needsFalling = IsFlying() || IsHovering();
        SetHover(false);

        if (needsFalling)
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

        ClearUnitState(UNIT_STATE_ALL_ERASABLE);

        if (!IsPet())
        {
            CreatureData const* creatureData = GetCreatureData();
            CreatureTemplate const* cInfo = GetCreatureTemplate();

            uint64 npcFlags;
            uint32 unitFlags, unitFlags2, unitFlags3, dynamicFlags;
            ObjectMgr::ChooseCreatureFlags(cInfo, npcFlags, unitFlags, unitFlags2, unitFlags3, dynamicFlags, creatureData);

            if (cInfo->flags_extra & CREATURE_FLAG_EXTRA_WORLDEVENT)
                npcFlags |= sGameEventMgr->GetNPCFlag(this);

            SetNpcFlags(NPCFlags(npcFlags & 0xFFFFFFFF));
            SetNpcFlags2(NPCFlags2(npcFlags >> 32));

            SetUnitFlags(UnitFlags(unitFlags));
            SetUnitFlags2(UnitFlags2(unitFlags2));
            SetUnitFlags3(UnitFlags3(unitFlags3));
            SetDynamicFlags(dynamicFlags);

            RemoveUnitFlag(UNIT_FLAG_IN_COMBAT);

            SetMeleeDamageSchool(SpellSchools(cInfo->dmgschool));
        }

        Motion_Initialize();
        Unit::setDeathState(ALIVE);
        LoadCreaturesAddon();
    }
}

void Creature::Respawn(bool force)
{
    if (force)
    {
        if (IsAlive())
            setDeathState(JUST_DIED);
        else if (getDeathState() != CORPSE)
            setDeathState(CORPSE);
    }

    if (m_respawnCompatibilityMode)
    {
        DestroyForNearbyPlayers();
        RemoveCorpse(false, false);

        if (getDeathState() == DEAD)
        {
            TC_LOG_DEBUG("entities.unit", "Respawning creature %s (%s)", GetName().c_str(), GetGUID().ToString().c_str());
            m_respawnTime = 0;
            ResetPickPocketRefillTimer();
            loot.clear();

            if (m_originalEntry != GetEntry())
                UpdateEntry(m_originalEntry);

            SelectLevel();

            setDeathState(JUST_RESPAWNED);

            CreatureModel display(GetNativeDisplayId(), GetNativeDisplayScale(), 1.0f);
            if (sObjectMgr->GetCreatureModelRandomGender(&display, GetCreatureTemplate()))
            {
                SetDisplayId(display.CreatureDisplayID, display.DisplayScale);
                SetNativeDisplayId(display.CreatureDisplayID, display.DisplayScale);
            }

            GetMotionMaster()->InitializeDefault();

            // Re-initialize reactstate that could be altered by movementgenerators
            InitializeReactState();

            if (UnitAI* ai = AI()) // reset the AI to be sure no dirty or uninitialized values will be used till next tick
                ai->Reset();

            m_triggerJustAppeared = true;

            uint32 poolid = GetSpawnId() ? sPoolMgr->IsPartOfAPool<Creature>(GetSpawnId()) : 0;
            if (poolid)
                sPoolMgr->UpdatePool<Creature>(poolid, GetSpawnId());
        }
        UpdateObjectVisibility();
    }
    else
    {
        if (m_spawnId)
            GetMap()->Respawn(SPAWN_TYPE_CREATURE, m_spawnId);
    }

    TC_LOG_DEBUG("entities.unit", "Respawning creature %s (%s)",
        GetName().c_str(), GetGUID().ToString().c_str());

}

void Creature::ForcedDespawn(uint32 timeMSToDespawn, Seconds forceRespawnTimer)
{
    if (timeMSToDespawn)
    {
        m_Events.AddEvent(new ForcedDespawnDelayEvent(*this, forceRespawnTimer), m_Events.CalculateTime(Milliseconds(timeMSToDespawn)));
        return;
    }

    if (m_respawnCompatibilityMode)
    {
        uint32 corpseDelay = GetCorpseDelay();
        uint32 respawnDelay = GetRespawnDelay();

        // do it before killing creature
        DestroyForNearbyPlayers();

        bool overrideRespawnTime = false;
        if (IsAlive())
        {
            if (forceRespawnTimer > Seconds::zero())
            {
                SetCorpseDelay(0);
                SetRespawnDelay(forceRespawnTimer.count());
                overrideRespawnTime = true;
            }

            setDeathState(JUST_DIED);
        }

        // Skip corpse decay time
        RemoveCorpse(!overrideRespawnTime, false);

        SetCorpseDelay(corpseDelay);
        SetRespawnDelay(respawnDelay);
    }
    else
    {
        if (forceRespawnTimer > Seconds::zero())
            SaveRespawnTime(forceRespawnTimer.count());
        else
        {
            uint32 respawnDelay = m_respawnDelay;
            if (uint32 scalingMode = sWorld->getIntConfig(CONFIG_RESPAWN_DYNAMICMODE))
                GetMap()->ApplyDynamicModeRespawnScaling(this, m_spawnId, respawnDelay, scalingMode);
            m_respawnTime = GameTime::GetGameTime() + respawnDelay;
            SaveRespawnTime();
        }

        AddObjectToRemoveList();
    }
}

void Creature::DespawnOrUnsummon(Milliseconds timeToDespawn /*= 0s*/, Seconds forceRespawnTimer /*= 0s*/)
{
    if (TempSummon* summon = ToTempSummon())
        summon->UnSummon(timeToDespawn.count());
    else
        ForcedDespawn(timeToDespawn.count(), forceRespawnTimer);
}

void Creature::LoadTemplateImmunities()
{
    // uint32 max used for "spell id", the immunity system will not perform SpellInfo checks against invalid spells
    // used so we know which immunities were loaded from template
    static uint32 const placeholderSpellId = std::numeric_limits<uint32>::max();

    // unapply template immunities (in case we're updating entry)
    for (uint32 i = MECHANIC_NONE + 1; i < MAX_MECHANIC; ++i)
        ApplySpellImmune(placeholderSpellId, IMMUNITY_MECHANIC, i, false);

    for (uint32 i = SPELL_SCHOOL_NORMAL; i < MAX_SPELL_SCHOOL; ++i)
        ApplySpellImmune(placeholderSpellId, IMMUNITY_SCHOOL, 1 << i, false);

    // don't inherit immunities for hunter pets
    if (GetOwnerGUID().IsPlayer() && IsHunterPet())
        return;

    if (uint32 mask = GetCreatureTemplate()->MechanicImmuneMask)
    {
        for (uint32 i = MECHANIC_NONE + 1; i < MAX_MECHANIC; ++i)
        {
            if (mask & (1 << (i - 1)))
                ApplySpellImmune(placeholderSpellId, IMMUNITY_MECHANIC, i, true);
        }
    }

    if (uint32 mask = GetCreatureTemplate()->SpellSchoolImmuneMask)
    {
        for (uint8 i = SPELL_SCHOOL_NORMAL; i < MAX_SPELL_SCHOOL; ++i)
        {
            if (mask & (1 << i))
                ApplySpellImmune(placeholderSpellId, IMMUNITY_SCHOOL, 1 << i, true);
        }
    }
}

bool Creature::IsImmunedToSpell(SpellInfo const* spellInfo, WorldObject const* caster) const
{
    if (!spellInfo)
        return false;

    bool immunedToAllEffects = true;
    for (SpellEffectInfo const& spellEffectInfo : spellInfo->GetEffects())
    {
        if (spellEffectInfo.IsEffect() && !IsImmunedToSpellEffect(spellInfo, spellEffectInfo, caster))
        {
            immunedToAllEffects = false;
            break;
        }
    }

    if (immunedToAllEffects)
        return true;

    return Unit::IsImmunedToSpell(spellInfo, caster);
}

bool Creature::IsImmunedToSpellEffect(SpellInfo const* spellInfo, SpellEffectInfo const& spellEffectInfo, WorldObject const* caster) const
{
    if (GetCreatureTemplate()->type == CREATURE_TYPE_MECHANICAL && spellEffectInfo.IsEffect(SPELL_EFFECT_HEAL))
        return true;

    return Unit::IsImmunedToSpellEffect(spellInfo, spellEffectInfo, caster);
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
        TC_LOG_ERROR("entities.unit", "Creature %s SelectNearestTargetInAttackDistance called with dist > MAX_VISIBILITY_DISTANCE. Distance set to ATTACK_DISTANCE.", GetGUID().ToString().c_str());
        dist = ATTACK_DISTANCE;
    }

    Unit* target = nullptr;
    Trinity::NearestHostileUnitInAttackDistanceCheck u_check(this, dist);
    Trinity::UnitLastSearcher<Trinity::NearestHostileUnitInAttackDistanceCheck> searcher(this, target, u_check);
    Cell::VisitAllObjects(this, searcher, std::max(dist, ATTACK_DISTANCE));
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
                m_Events.AddEvent(e, m_Events.CalculateTime(Milliseconds(sWorld->getIntConfig(CONFIG_CREATURE_FAMILY_ASSISTANCE_DELAY))));
            }
        }
    }
}

void Creature::CallForHelp(float radius)
{
    if (radius <= 0.0f || !IsEngaged() || !IsAlive() || IsPet() || IsCharmed())
        return;

    Unit* target = GetThreatManager().GetCurrentVictim();
    if (!target)
        target = GetThreatManager().GetAnyTarget();
    if (!target)
        target = GetCombatManager().GetAnyTarget();

    if (!target)
    {
        TC_LOG_ERROR("entities.unit", "Creature %u (%s) trying to call for help without being in combat.", GetEntry(), GetName().c_str());
        return;
    }

    Trinity::CallOfHelpCreatureInRangeDo u_do(this, target, radius);
    Trinity::CreatureWorker<Trinity::CallOfHelpCreatureInRangeDo> worker(this, u_do);
    Cell::VisitGridObjects(this, worker, radius);
}

bool Creature::CanAssistTo(Unit const* u, Unit const* enemy, bool checkfaction /*= true*/) const
{
    // is it true?
    if (!HasReactState(REACT_AGGRESSIVE))
        return false;

    // we don't need help from zombies :)
    if (!IsAlive())
        return false;

    // we cannot assist in evade mode
    if (IsInEvadeMode())
        return false;

    // or if enemy is in evade mode
    if (enemy->GetTypeId() == TYPEID_UNIT && enemy->ToCreature()->IsInEvadeMode())
        return false;

    // we don't need help from non-combatant ;)
    if (IsCivilian())
        return false;

    if (HasUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE)) || IsImmuneToNPC())
        return false;

    // skip fighting creature
    if (IsEngaged())
        return false;

    // only free creature
    if (!GetCharmerOrOwnerGUID().IsEmpty())
        return false;

    // only from same creature faction
    if (checkfaction)
    {
        if (GetFaction() != u->GetFaction())
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
bool Creature::_IsTargetAcceptable(Unit const* target) const
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
        if (IsGuard() && target->HasUnitFlag2(UNIT_FLAG2_FEIGN_DEATH))
            return true;
        else
            return false;
    }

    // if I'm already fighting target, or I'm hostile towards the target, the target is acceptable
    if (IsEngagedBy(target) || IsHostileTo(target))
        return true;

    // if the target's victim is not friendly, or the target is friendly, the target is not acceptable
    return false;
}

void Creature::SaveRespawnTime(uint32 forceDelay)
{
    if (IsSummon() || !m_spawnId || (m_creatureData && !m_creatureData->dbData))
        return;

    if (m_respawnCompatibilityMode)
    {
        RespawnInfo ri;
        ri.type = SPAWN_TYPE_CREATURE;
        ri.spawnId = m_spawnId;
        ri.respawnTime = m_respawnTime;
        GetMap()->SaveRespawnInfoDB(ri);
        return;
    }

    time_t thisRespawnTime = forceDelay ? GameTime::GetGameTime() + forceDelay : m_respawnTime;
    GetMap()->SaveRespawnTime(SPAWN_TYPE_CREATURE, m_spawnId, GetEntry(), thisRespawnTime, Trinity::ComputeGridCoord(GetHomePosition().GetPositionX(), GetHomePosition().GetPositionY()).GetId());
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

    if (CreatureAI* ai = AI())
        if (!ai->CanAIAttack(victim))
            return false;

    // we cannot attack in evade mode
    if (IsInEvadeMode())
        return false;

    // or if enemy is in evade mode
    if (victim->GetTypeId() == TYPEID_UNIT && victim->ToCreature()->IsInEvadeMode())
        return false;

    if (!GetCharmerOrOwnerGUID().IsPlayer())
    {
        if (GetMap()->IsDungeon())
            return true;

        // don't check distance to home position if recently damaged, this should include taunt auras
        if (!isWorldBoss() && (GetLastDamagedTime() > GameTime::GetGameTime() || HasAuraType(SPELL_AURA_MOD_TAUNT)))
            return true;
    }

    // Map visibility range, but no more than 2*cell size
    float dist = std::min<float>(GetMap()->GetVisibilityRange(), SIZE_OF_GRID_CELL * 2);

    if (Unit* unit = GetCharmerOrOwner())
        return victim->IsWithinDist(unit, dist);
    else
    {
        // include sizes for huge npcs
        dist += GetCombatReach() + victim->GetCombatReach();

        // to prevent creatures in air ignore attacks because distance is already too high...
        if (GetMovementTemplate().IsFlightAllowed())
            return victim->IsInDist2d(&m_homePosition, dist);
        else
            return victim->IsInDist(&m_homePosition, dist);
    }
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

        SetStandState(UnitStandStateType(cainfo->bytes1 & 0xFF));
        SetVisFlags(UnitVisFlags((cainfo->bytes1 >> 16) & 0xFF));
        SetAnimTier(UnitBytes1_Flags((cainfo->bytes1 >> 24) & 0xFF), false);

        //! Suspected correlation between UNIT_FIELD_BYTES_1, offset 3, value 0x2:
        //! If no inhabittype_fly (if no MovementFlag_DisableGravity or MovementFlag_CanFly flag found in sniffs)
        //! Check using InhabitType as movement flags are assigned dynamically
        //! basing on whether the creature is in air or not
        //! Set MovementFlag_Hover. Otherwise do nothing.
        if (CanHover())
            AddUnitMovementFlag(MOVEMENTFLAG_HOVER);
    }

    if (cainfo->bytes2 != 0)
    {
        // 0 SheathState
        // 1 PvpFlags
        // 2 PetFlags           Pet only, so always 0 for default creature
        // 3 ShapeshiftForm     Must be determined/set by shapeshift spell/aura

        SetSheath(SheathState(cainfo->bytes2 & 0xFF));
        SetPvpFlags(UNIT_BYTE2_FLAG_NONE);
        SetPetFlags(UNIT_PET_FLAG_NONE);
        SetShapeshiftForm(FORM_NONE);
    }

    if (cainfo->emote != 0)
        SetEmoteState(Emote(cainfo->emote));

    SetAIAnimKitId(cainfo->aiAnimKit);
    SetMovementAnimKitId(cainfo->movementAnimKit);
    SetMeleeAnimKitId(cainfo->meleeAnimKit);

    // Check if visibility distance different
    if (cainfo->visibilityDistanceType != VisibilityDistanceType::Normal)
        SetVisibilityDistanceOverride(cainfo->visibilityDistanceType);

    // Load Path
    if (cainfo->path_id != 0)
        _waypointPathId = cainfo->path_id;

    if (!cainfo->auras.empty())
    {
        for (std::vector<uint32>::const_iterator itr = cainfo->auras.begin(); itr != cainfo->auras.end(); ++itr)
        {
            SpellInfo const* AdditionalSpellInfo = sSpellMgr->GetSpellInfo(*itr, GetMap()->GetDifficultyID());
            if (!AdditionalSpellInfo)
            {
                TC_LOG_ERROR("sql.sql", "Creature %s has wrong spell %u defined in `auras` field.", GetGUID().ToString().c_str(), *itr);
                continue;
            }

            // skip already applied aura
            if (HasAura(*itr))
                continue;

            AddAura(*itr, this);
            TC_LOG_DEBUG("entities.unit", "Spell: %u added to creature %s", *itr, GetGUID().ToString().c_str());
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

bool Creature::HasSpell(uint32 spellID) const
{
    return std::find(std::begin(m_spells), std::end(m_spells), spellID) != std::end(m_spells);
}

time_t Creature::GetRespawnTimeEx() const
{
    time_t now = GameTime::GetGameTime();
    if (m_respawnTime > now)
        return m_respawnTime;
    else
        return now;
}

void Creature::SetRespawnTime(uint32 respawn)
{
    m_respawnTime = respawn ? GameTime::GetGameTime() + respawn : 0;
}

void Creature::GetRespawnPosition(float &x, float &y, float &z, float* ori, float* dist) const
{
    if (m_creatureData)
    {
        if (ori)
            m_creatureData->spawnPoint.GetPosition(x, y, z, *ori);
        else
            m_creatureData->spawnPoint.GetPosition(x, y, z);

        if (dist)
            *dist = m_creatureData->wander_distance;
    }
    else
    {
        Position const& homePos = GetHomePosition();
        if (ori)
            homePos.GetPosition(x, y, z, *ori);
        else
            homePos.GetPosition(x, y, z);
        if (dist)
            *dist = 0;
    }
}

void Creature::InitializeMovementFlags()
{
    // It does the same, for now
    UpdateMovementFlags();
}

void Creature::UpdateMovementFlags()
{
    // Do not update movement flags if creature is controlled by a player (charm/vehicle)
    if (m_playerMovingMe)
        return;

    // Creatures with CREATURE_FLAG_EXTRA_NO_MOVE_FLAGS_UPDATE should control MovementFlags in your own scripts
    if (GetCreatureTemplate()->flags_extra & CREATURE_FLAG_EXTRA_NO_MOVE_FLAGS_UPDATE)
        return;

    // Set the movement flags if the creature is in that mode. (Only fly if actually in air, only swim if in water, etc)
    float ground = GetFloorZ();

    bool canHover = CanHover();
    bool isInAir = (G3D::fuzzyGt(GetPositionZ(), ground + (canHover ? *m_unitData->HoverHeight : 0.0f) + GROUND_HEIGHT_TOLERANCE) || G3D::fuzzyLt(GetPositionZ(), ground - GROUND_HEIGHT_TOLERANCE)); // Can be underground too, prevent the falling

    if (GetMovementTemplate().IsFlightAllowed() && isInAir && !IsFalling())
    {
        if (GetMovementTemplate().Flight == CreatureFlightMovementType::CanFly)
            SetCanFly(true);
        else
            SetDisableGravity(true);

        if (!HasAuraType(SPELL_AURA_HOVER))
            SetHover(false);
    }
    else
    {
        SetCanFly(false);
        SetDisableGravity(false);
        if (IsAlive() && (CanHover() || HasAuraType(SPELL_AURA_HOVER)))
            SetHover(true);
    }

    if (!isInAir)
        RemoveUnitMovementFlag(MOVEMENTFLAG_FALLING);

    SetSwim(GetMovementTemplate().IsSwimAllowed() && IsInWater());
}

CreatureMovementData const& Creature::GetMovementTemplate() const
{
    if (CreatureMovementData const* movementOverride = sObjectMgr->GetCreatureMovementOverride(m_spawnId))
        return *movementOverride;

    return GetCreatureTemplate()->Movement;
}

void Creature::AllLootRemovedFromCorpse()
{
    if (loot.loot_type != LOOT_SKINNING && !IsPet() && GetCreatureTemplate()->SkinLootId && hasLootRecipient())
        if (LootTemplates_Skinning.HaveLootFor(GetCreatureTemplate()->SkinLootId))
            AddUnitFlag(UNIT_FLAG_SKINNABLE);

    time_t now = GameTime::GetGameTime();
    // Do not reset corpse remove time if corpse is already removed
    if (m_corpseRemoveTime <= now)
        return;

    float decayRate = sWorld->getRate(RATE_CORPSE_DECAY_LOOTED);

    // corpse skinnable, but without skinning flag, and then skinned, corpse will despawn next update
    if (loot.loot_type == LOOT_SKINNING)
        m_corpseRemoveTime = now;
    else
        m_corpseRemoveTime = now + uint32(m_corpseDelay * decayRate);

    m_respawnTime = std::max<time_t>(m_corpseRemoveTime + m_respawnDelay, m_respawnTime);
}

bool Creature::HasScalableLevels() const
{
    CreatureTemplate const* cinfo = GetCreatureTemplate();
    CreatureLevelScaling const* scaling = cinfo->GetLevelScaling(GetMap()->GetDifficultyID());

    return scaling->ContentTuningID != 0;
}

uint64 Creature::GetMaxHealthByLevel(uint8 level) const
{
    CreatureTemplate const* cInfo = GetCreatureTemplate();
    CreatureLevelScaling const* scaling = cInfo->GetLevelScaling(GetMap()->GetDifficultyID());
    float baseHealth = sDB2Manager.EvaluateExpectedStat(ExpectedStatType::CreatureHealth, level, cInfo->GetHealthScalingExpansion(), scaling->ContentTuningID, Classes(cInfo->unit_class));
    return baseHealth * cInfo->ModHealth * cInfo->ModHealthExtra;
}

float Creature::GetHealthMultiplierForTarget(WorldObject const* target) const
{
    if (!HasScalableLevels())
        return 1.0f;

    uint8 levelForTarget = GetLevelForTarget(target);
    if (GetLevel() < levelForTarget)
        return 1.0f;

    return double(GetMaxHealthByLevel(levelForTarget)) / double(GetCreateHealth());
}

float Creature::GetBaseDamageForLevel(uint8 level) const
{
    CreatureTemplate const* cInfo = GetCreatureTemplate();
    CreatureLevelScaling const* scaling = cInfo->GetLevelScaling(GetMap()->GetDifficultyID());
    return sDB2Manager.EvaluateExpectedStat(ExpectedStatType::CreatureAutoAttackDps, level, cInfo->GetHealthScalingExpansion(), scaling->ContentTuningID, Classes(cInfo->unit_class));
}

float Creature::GetDamageMultiplierForTarget(WorldObject const* target) const
{
    if (!HasScalableLevels())
        return 1.0f;

    uint8 levelForTarget = GetLevelForTarget(target);

    return GetBaseDamageForLevel(levelForTarget) / GetBaseDamageForLevel(GetLevel());
}

float Creature::GetBaseArmorForLevel(uint8 level) const
{
    CreatureTemplate const* cInfo = GetCreatureTemplate();
    CreatureLevelScaling const* scaling = cInfo->GetLevelScaling(GetMap()->GetDifficultyID());
    float baseArmor = sDB2Manager.EvaluateExpectedStat(ExpectedStatType::CreatureArmor, level, cInfo->GetHealthScalingExpansion(), scaling->ContentTuningID, Classes(cInfo->unit_class));
    return baseArmor * cInfo->ModArmor;
}

float Creature::GetArmorMultiplierForTarget(WorldObject const* target) const
{
    if (!HasScalableLevels())
        return 1.0f;

    uint8 levelForTarget = GetLevelForTarget(target);

    return GetBaseArmorForLevel(levelForTarget) / GetBaseArmorForLevel(GetLevel());
}

uint8 Creature::GetLevelForTarget(WorldObject const* target) const
{
    if (Unit const* unitTarget = target->ToUnit())
    {
        if (isWorldBoss())
        {
            uint8 level = unitTarget->GetLevel() + sWorld->getIntConfig(CONFIG_WORLD_BOSS_LEVEL_DIFF);
            return RoundToInterval<uint8>(level, 1u, 255u);
        }

        // If this creature should scale level, adapt level depending of target level
        // between UNIT_FIELD_SCALING_LEVEL_MIN and UNIT_FIELD_SCALING_LEVEL_MAX
        if (HasScalableLevels())
        {
            int32 scalingLevelMin = m_unitData->ScalingLevelMin;
            int32 scalingLevelMax = m_unitData->ScalingLevelMax;
            int32 scalingLevelDelta = m_unitData->ScalingLevelDelta;
            int32 scalingFactionGroup = m_unitData->ScalingFactionGroup;
            int32 targetLevel = unitTarget->m_unitData->EffectiveLevel;
            if (!targetLevel)
                targetLevel = unitTarget->GetLevel();

            int32 targetLevelDelta = 0;

            if (Player const* playerTarget = target->ToPlayer())
            {
                if (scalingFactionGroup && sFactionTemplateStore.AssertEntry(sChrRacesStore.AssertEntry(playerTarget->GetRace())->FactionID)->FactionGroup != scalingFactionGroup)
                    scalingLevelMin = scalingLevelMax;

                int32 maxCreatureScalingLevel = playerTarget->m_activePlayerData->MaxCreatureScalingLevel;
                targetLevelDelta = std::min(maxCreatureScalingLevel > 0 ? maxCreatureScalingLevel - targetLevel : 0, *playerTarget->m_activePlayerData->ScalingPlayerLevelDelta);
            }

            int32 levelWithDelta = targetLevel + targetLevelDelta;
            int32 level = RoundToInterval(levelWithDelta, scalingLevelMin, scalingLevelMax) + scalingLevelDelta;
            return RoundToInterval(level, 1, MAX_LEVEL + 3);
        }
    }

    return Unit::GetLevelForTarget(target);
}

std::string const& Creature::GetAIName() const
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
        if (uint32 scriptId = creatureData->scriptId)
            return scriptId;

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

    time_t ptime = GameTime::GetGameTime();

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

    time_t ptime = GameTime::GetGameTime();

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
std::string Creature::GetNameForLocaleIdx(LocaleConstant locale) const
{
    if (locale != DEFAULT_LOCALE)
        if (CreatureLocale const* cl = sObjectMgr->GetCreatureLocale(GetEntry()))
            if (cl->Name.size() > locale && !cl->Name[locale].empty())
                return cl->Name[locale];

    return GetName();
}

uint32 Creature::GetPetAutoSpellOnPos(uint8 pos) const
{
    if (pos >= MAX_SPELL_CHARM || !m_charmInfo || m_charmInfo->GetCharmSpell(pos)->GetType() != ACT_ENABLED)
        return 0;
    else
        return m_charmInfo->GetCharmSpell(pos)->GetAction();
}

float Creature::GetPetChaseDistance() const
{
    float range = 0.f;

    for (uint8 i = 0; i < GetPetAutoSpellSize(); ++i)
    {
        uint32 spellID = GetPetAutoSpellOnPos(i);
        if (!spellID)
            continue;

        if (SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellID, GetMap()->GetDifficultyID()))
        {
            if (spellInfo->GetRecoveryTime() == 0 && spellInfo->RangeEntry->ID != 1 /*Self*/ && spellInfo->RangeEntry->ID != 2 /*Combat Range*/ && spellInfo->GetMaxRange() > range)
                range = spellInfo->GetMaxRange();
        }
    }

    return range;
}

void Creature::SetCannotReachTarget(bool cannotReach)
{
    if (cannotReach == m_cannotReachTarget)
        return;
    m_cannotReachTarget = cannotReach;
    m_cannotReachTimer = 0;

    if (cannotReach)
        TC_LOG_DEBUG("entities.unit.chase", "Creature::SetCannotReachTarget() called with true. Details: %s", GetDebugInfo().c_str());
}

float Creature::GetAggroRange(Unit const* target) const
{
    // Determines the aggro range for creatures (usually pets), used mainly for aggressive pet target selection.
    // Based on data from wowwiki due to lack of 3.3.5a data

    if (target && IsPet())
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

Unit* Creature::SelectNearestHostileUnitInAggroRange(bool useLOS, bool ignoreCivilians) const
{
    // Selects nearest hostile target within creature's aggro range. Used primarily by
    //  pets set to aggressive. Will not return neutral or friendly targets.

    Unit* target = nullptr;

    Trinity::NearestHostileUnitInAggroRangeCheck u_check(this, useLOS, ignoreCivilians);
    Trinity::UnitSearcher<Trinity::NearestHostileUnitInAggroRangeCheck> searcher(this, target, u_check);

    Cell::VisitGridObjects(this, searcher, MAX_AGGRO_RADIUS);

    return target;
}

float Creature::GetNativeObjectScale() const
{
    return GetCreatureTemplate()->scale;
}

void Creature::SetObjectScale(float scale)
{
    Unit::SetObjectScale(scale);

    if (CreatureModelInfo const* minfo = sObjectMgr->GetCreatureModelInfo(GetDisplayId()))
    {
        SetBoundingRadius((IsPet() ? 1.0f : minfo->bounding_radius) * scale);
        SetCombatReach((IsPet() ? DEFAULT_PLAYER_COMBAT_REACH : minfo->combat_reach) * scale);
    }
}

void Creature::SetDisplayId(uint32 modelId, float displayScale /*= 1.f*/)
{
    Unit::SetDisplayId(modelId, displayScale);

    if (CreatureModelInfo const* minfo = sObjectMgr->GetCreatureModelInfo(modelId))
    {
        SetBoundingRadius((IsPet() ? 1.0f : minfo->bounding_radius) * GetObjectScale());
        SetCombatReach((IsPet() ? DEFAULT_PLAYER_COMBAT_REACH : minfo->combat_reach) * GetObjectScale());
    }
}

void Creature::SetDisplayFromModel(uint32 modelIdx)
{
    if (CreatureModel const* model = GetCreatureTemplate()->GetModelByIdx(modelIdx))
        SetDisplayId(model->CreatureDisplayID, model->DisplayScale);
}

void Creature::SetTarget(ObjectGuid const& guid)
{
    if (HasSpellFocus())
        _spellFocusInfo.Target = guid;
    else
        SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::Target), guid);
}

void Creature::SetSpellFocus(Spell const* focusSpell, WorldObject const* target)
{
    // Pointer validation and checking for a already existing focus
    if (_spellFocusInfo.Spell || !focusSpell)
        return;

    // Prevent dead / feign death creatures from setting a focus target
    if (!IsAlive() || HasUnitFlag2(UNIT_FLAG2_FEIGN_DEATH) || HasAuraType(SPELL_AURA_FEIGN_DEATH))
        return;

    // Don't allow stunned creatures to set a focus target
    if (HasUnitFlag(UNIT_FLAG_STUNNED))
        return;

    // some spells shouldn't track targets
    if (focusSpell->IsFocusDisabled())
        return;

    SpellInfo const* spellInfo = focusSpell->GetSpellInfo();

    // don't use spell focus for vehicle spells
    if (spellInfo->HasAura(SPELL_AURA_CONTROL_VEHICLE))
        return;

    // instant non-channeled casts and non-target spells don't need facing updates
    if (!target && (!focusSpell->GetCastTime() && !spellInfo->IsChanneled()))
        return;

    // store pre-cast values for target and orientation (used to later restore)
    if (!_spellFocusInfo.Delay)
    { // only overwrite these fields if we aren't transitioning from one spell focus to another
        _spellFocusInfo.Target = GetTarget();
        _spellFocusInfo.Orientation = GetOrientation();
    }
    else // don't automatically reacquire target for the previous spellcast
        _spellFocusInfo.Delay = 0;

    _spellFocusInfo.Spell = focusSpell;

    bool const noTurnDuringCast = spellInfo->HasAttribute(SPELL_ATTR5_DONT_TURN_DURING_CAST);
    // set target, then force send update packet to players if it changed to provide appropriate facing
    ObjectGuid newTarget = target ? target->GetGUID() : ObjectGuid::Empty;
    if (GetTarget() != newTarget)
    {
        SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::Target), newTarget);

        if ( // here we determine if the (relatively expensive) forced update is worth it, or whether we can afford to wait until the scheduled update tick
            ( // only require instant update for spells that actually have a visual
                spellInfo->GetSpellVisual()
            ) && (
                !focusSpell->GetCastTime() || // if the spell is instant cast
                noTurnDuringCast // client gets confused if we attempt to turn at the regularly scheduled update packet
            )
        )
        {
            std::vector<Player*> playersNearby;
            GetPlayerListInGrid(playersNearby, GetVisibilityRange());
            for (Player* player : playersNearby)
            {
                // only update players that are known to the client (have already been created)
                if (player->HaveAtClient(this))
                    SendUpdateToPlayer(player);
            }
        }
    }

    if (!HasUnitFlag2(UNIT_FLAG2_CANNOT_TURN))
    {
        // Face the target - we need to do this before the unit state is modified for no-turn spells
        if (target)
            SetFacingToObject(target, false);
        else if (noTurnDuringCast)
            if (Unit* victim = GetVictim())
                SetFacingToObject(victim, false); // ensure orientation is correct at beginning of cast
    }

    if (noTurnDuringCast)
        AddUnitState(UNIT_STATE_FOCUSING);
}

bool Creature::HasSpellFocus(Spell const* focusSpell) const
{
    if (isDead()) // dead creatures cannot focus
    {
        if (_spellFocusInfo.Spell || _spellFocusInfo.Delay)
        {
            TC_LOG_WARN("entities.unit", "Creature '%s' (entry %u) has spell focus (spell id %u, delay %ums) despite being dead.",
                        GetName().c_str(), GetEntry(), _spellFocusInfo.Spell ? _spellFocusInfo.Spell->GetSpellInfo()->Id : 0, _spellFocusInfo.Delay);
        }
        return false;
    }

    if (focusSpell)
        return (focusSpell == _spellFocusInfo.Spell);
    else
        return (_spellFocusInfo.Spell || _spellFocusInfo.Delay);
}

void Creature::ReleaseSpellFocus(Spell const* focusSpell, bool withDelay)
{
    if (!_spellFocusInfo.Spell)
        return;

    // focused to something else
    if (focusSpell && focusSpell != _spellFocusInfo.Spell)
        return;

    if (_spellFocusInfo.Spell->GetSpellInfo()->HasAttribute(SPELL_ATTR5_DONT_TURN_DURING_CAST))
        ClearUnitState(UNIT_STATE_FOCUSING);

    if (IsPet()) // player pets do not use delay system
    {
        if (!HasUnitFlag2(UNIT_FLAG2_CANNOT_TURN))
            ReacquireSpellFocusTarget();
    }
    else // don't allow re-target right away to prevent visual bugs
        _spellFocusInfo.Delay = withDelay ? 1000 : 1;

    _spellFocusInfo.Spell = nullptr;
}

void Creature::ReacquireSpellFocusTarget()
{
    if (!HasSpellFocus())
    {
        TC_LOG_ERROR("entities.unit", "Creature::ReacquireSpellFocusTarget() being called with HasSpellFocus() returning false. %s", GetDebugInfo().c_str());
        return;
    }

    SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::Target), _spellFocusInfo.Target);

    if (!HasUnitFlag2(UNIT_FLAG2_CANNOT_TURN))
    {
        if (!_spellFocusInfo.Target.IsEmpty())
        {
            if (WorldObject const* objTarget = ObjectAccessor::GetWorldObject(*this, _spellFocusInfo.Target))
                SetFacingToObject(objTarget, false);
        }
        else
            SetFacingTo(_spellFocusInfo.Orientation, false);
    }
    _spellFocusInfo.Delay = 0;
}

void Creature::DoNotReacquireSpellFocusTarget()
{
    _spellFocusInfo.Delay = 0;
    _spellFocusInfo.Spell = nullptr;
}

bool Creature::IsMovementPreventedByCasting() const
{
    // first check if currently a movement allowed channel is active and we're not casting
    if (Spell* spell = m_currentSpells[CURRENT_CHANNELED_SPELL])
    {
        if (spell->getState() != SPELL_STATE_FINISHED && spell->IsChannelActive())
            if (spell->GetSpellInfo()->IsMoveAllowedChannel())
                return false;
    }

    if (HasSpellFocus())
        return true;

    if (HasUnitState(UNIT_STATE_CASTING))
        return true;

    return false;
}

void Creature::StartPickPocketRefillTimer()
{
    _pickpocketLootRestore = GameTime::GetGameTime() + sWorld->getIntConfig(CONFIG_CREATURE_PICKPOCKET_REFILL);
}

bool Creature::CanGeneratePickPocketLoot() const
{
    return _pickpocketLootRestore <= GameTime::GetGameTime();
}

void Creature::SetTextRepeatId(uint8 textGroup, uint8 id)
{
    CreatureTextRepeatIds& repeats = m_textRepeat[textGroup];
    if (std::find(repeats.begin(), repeats.end(), id) == repeats.end())
        repeats.push_back(id);
    else
        TC_LOG_ERROR("sql.sql", "CreatureTextMgr: TextGroup %u for Creature(%s) %s, id %u already added", uint32(textGroup), GetName().c_str(), GetGUID().ToString().c_str(), uint32(id));
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

bool Creature::IsEngaged() const
{
    if (CreatureAI const* ai = AI())
        return ai->IsEngaged();
    return false;
}

void Creature::AtEngage(Unit* target)
{
    Unit::AtEngage(target);

    if (!(GetCreatureTemplate()->type_flags & CREATURE_TYPE_FLAG_MOUNTED_COMBAT_ALLOWED))
        Dismount();

    if (IsPet() || IsGuardian()) // update pets' speed for catchup OOC speed
    {
        UpdateSpeed(MOVE_RUN);
        UpdateSpeed(MOVE_SWIM);
        UpdateSpeed(MOVE_FLIGHT);
    }

    MovementGeneratorType const movetype = GetMotionMaster()->GetCurrentMovementGeneratorType();
    if (movetype == WAYPOINT_MOTION_TYPE || movetype == POINT_MOTION_TYPE || (IsAIEnabled() && AI()->IsEscorted()))
        SetHomePosition(GetPosition());

    if (CreatureAI* ai = AI())
        ai->JustEngagedWith(target);
    if (CreatureGroup* formation = GetFormation())
        formation->MemberEngagingTarget(this, target);
}

void Creature::AtDisengage()
{
    Unit::AtDisengage();

    ClearUnitState(UNIT_STATE_ATTACK_PLAYER);
    if (IsAlive() && HasDynamicFlag(UNIT_DYNFLAG_TAPPED))
        SetDynamicFlags(GetCreatureTemplate()->dynamicflags);

    if (IsPet() || IsGuardian()) // update pets' speed for catchup OOC speed
    {
        UpdateSpeed(MOVE_RUN);
        UpdateSpeed(MOVE_SWIM);
        UpdateSpeed(MOVE_FLIGHT);
    }
}

bool Creature::IsEscorted() const
{
    if (CreatureAI const* ai = AI())
        return ai->IsEscorted();
    return false;
}

std::string Creature::GetDebugInfo() const
{
    std::stringstream sstr;
    sstr << Unit::GetDebugInfo() << "\n"
        << "AIName: " << GetAIName() << " ScriptName: " << GetScriptName()
        << " WaypointPath: " << GetWaypointPath() << " SpawnId: " << GetSpawnId();
    return sstr.str();
}
