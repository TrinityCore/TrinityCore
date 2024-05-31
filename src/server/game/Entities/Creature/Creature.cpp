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
#include "CharmInfo.h"
#include "CombatPackets.h"
#include "Containers.h"
#include "CreatureAI.h"
#include "CreatureAISelector.h"
#include "CreatureGroups.h"
#include "DatabaseEnv.h"
#include "DB2Stores.h"
#include "Formulas.h"
#include "GameEventMgr.h"
#include "GameTime.h"
#include "GridNotifiersImpl.h"
#include "Group.h"
#include "ItemTemplate.h"
#include "Log.h"
#include "Loot.h"
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
#include "ScriptedGossip.h"
#include "Spell.h"
#include "SpellAuraEffects.h"
#include "SpellMgr.h"
#include "TemporarySummon.h"
#include "Vehicle.h"
#include "World.h"
#include "ZoneScript.h"
#include <G3D/g3dmath.h>
#include <sstream>

CreatureMovementData::CreatureMovementData() : HoverInitiallyEnabled(false), Chase(CreatureChaseMovementType::Run),
Random(CreatureRandomMovementType::Walk), InteractionPauseTimer(sWorld->getIntConfig(CONFIG_CREATURE_STOP_FOR_PLAYER)) { }

std::string CreatureMovementData::ToString() const
{
    char const* const ChaseStates[] = { "Run", "CanWalk", "AlwaysWalk" };
    char const* const RandomStates[] = { "Walk", "CanRun", "AlwaysRun" };

    std::ostringstream str;
    str << std::boolalpha
        << ", HoverInitiallyEnabled: " << HoverInitiallyEnabled
        << ", Chase: " << ChaseStates[AsUnderlyingType(Chase)]
        << ", Random: " << RandomStates[AsUnderlyingType(Random)];
    str << ", InteractionPauseTimer: " << InteractionPauseTimer;

    return str.str();
}

VendorItemCount::VendorItemCount(uint32 _item, uint32 _count)
    : itemId(_item), count(_count), lastIncrementTime(GameTime::GetGameTime()) { }

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

void CreatureTemplate::InitializeQueryData()
{
    for (uint8 loc = LOCALE_enUS; loc < TOTAL_LOCALES; ++loc)
        QueryData[loc] = BuildQueryData(static_cast<LocaleConstant>(loc), DIFFICULTY_NONE);
}

WorldPacket CreatureTemplate::BuildQueryData(LocaleConstant loc, Difficulty difficulty) const
{
    CreatureDifficulty const* creatureDifficulty = GetDifficulty(difficulty);

    WorldPackets::Query::QueryCreatureResponse queryTemp;

    queryTemp.CreatureID = Entry;

    queryTemp.Allow = true;

    WorldPackets::Query::CreatureStats& stats = queryTemp.Stats;

    stats.Leader = RacialLeader;

    stats.Name[0] = Name;
    stats.NameAlt[0] = FemaleName;

    stats.Flags[0] = creatureDifficulty->TypeFlags;
    stats.Flags[1] = creatureDifficulty->TypeFlags2;

    stats.CreatureType = type;
    stats.CreatureFamily = family;
    stats.Classification = uint32(Classification);

    for (uint32 i = 0; i < MAX_KILL_CREDIT; ++i)
        stats.ProxyCreatureID[i] = KillCredit[i];

    std::transform(Models.begin(), Models.end(), std::back_inserter(stats.Display.CreatureDisplay),
        [&stats](CreatureModel const& model) -> WorldPackets::Query::CreatureXDisplay
    {
        stats.Display.TotalProbability += model.Probability;
        return { model.CreatureDisplayID, model.DisplayScale, model.Probability };
    });

    stats.HpMulti = creatureDifficulty->HealthModifier;
    stats.EnergyMulti = creatureDifficulty->ManaModifier;

    stats.CreatureMovementInfoID = movementId;
    stats.RequiredExpansion = RequiredExpansion;
    stats.HealthScalingExpansion = creatureDifficulty->HealthScalingExpansion;
    stats.VignetteID = VignetteID;
    stats.Class = unit_class;
    stats.CreatureDifficultyID = creatureDifficulty->CreatureDifficultyID;
    stats.WidgetSetID = WidgetSetID;
    stats.WidgetSetUnitConditionID = WidgetSetUnitConditionID;

    stats.Title = SubName;
    stats.TitleAlt = TitleAlt;
    stats.CursorName = IconName;

    if (std::vector<uint32> const* items = sObjectMgr->GetCreatureQuestItemList(Entry, difficulty))
        stats.QuestItems.assign(items->begin(), items->end());

    if (std::vector<int32> const* currencies = sObjectMgr->GetCreatureQuestCurrencyList(Entry))
        stats.QuestCurrencies.assign(currencies->begin(), currencies->end());

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

CreatureDifficulty const* CreatureTemplate::GetDifficulty(Difficulty difficulty) const
{
    auto it = difficultyStore.find(difficulty);
    if (it != difficultyStore.end())
        return &it->second;

    // If there is no data for the difficulty, try to get data for the fallback difficulty
    DifficultyEntry const* difficultyEntry = sDifficultyStore.LookupEntry(difficulty);
    if (difficultyEntry)
        return GetDifficulty(Difficulty(difficultyEntry->FallbackDifficultyID));

    // No data for DIFFICULTY_NONE (0)
    struct DefaultCreatureDifficulty : public CreatureDifficulty
    {
        DefaultCreatureDifficulty()
        {
            DeltaLevelMin = 0;
            DeltaLevelMax = 0;
            ContentTuningID = 0;
            HealthScalingExpansion = 0;
            HealthModifier = 1.f;
            ManaModifier = 1.f;
            ArmorModifier = 1.f;
            DamageModifier = 1.f;
            CreatureDifficultyID = 0;
            TypeFlags = 0;
            TypeFlags2 = 0;
            LootID = 0;
            PickPocketLootID = 0;
            SkinLootID = 0;
            GoldMin = 0;
            GoldMax = 0;
        }
    };
    static const DefaultCreatureDifficulty defDifficulty;
    return &defDifficulty;
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

Creature::Creature(bool isWorldObject) : Unit(isWorldObject), MapObject(), m_PlayerDamageReq(0), m_dontClearTapListOnEvade(false), _pickpocketLootRestore(0),
    m_corpseRemoveTime(0), m_respawnTime(0), m_respawnDelay(300), m_corpseDelay(60), m_ignoreCorpseDecayRatio(false), m_wanderDistance(0.0f),
    m_boundaryCheckTime(2500), m_reactState(REACT_AGGRESSIVE),
    m_defaultMovementType(IDLE_MOTION_TYPE), m_spawnId(UI64LIT(0)), m_equipmentId(0), m_originalEquipmentId(0),
    m_AlreadyCallAssistance(false), m_AlreadySearchedAssistance(false), m_cannotReachTarget(false), m_cannotReachTimer(0),
    m_meleeDamageSchoolMask(SPELL_SCHOOL_MASK_NORMAL), m_originalEntry(0), m_homePosition(), m_transportHomePosition(),
    m_creatureInfo(nullptr), m_creatureData(nullptr), m_creatureDifficulty(nullptr), m_stringIds(), _waypointPathId(0), _currentWaypointNodeInfo(0, 0),
    m_formation(nullptr), m_triggerJustAppeared(true), m_respawnCompatibilityMode(false), _lastDamagedTime(0),
    _regenerateHealth(true), _creatureImmunitiesId(0), _gossipMenuId(0), _sparringHealthPct(0)
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

Creature::~Creature() = default;

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
        m_loot = nullptr;
        uint32 respawnDelay = m_respawnDelay;
        if (CreatureAI* ai = AI())
            ai->CorpseRemoved(respawnDelay);

        if (destroyForNearbyPlayers)
            UpdateObjectVisibilityOnDestroy();

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
        if (CreatureAI* ai = AI())
            ai->CorpseRemoved(m_respawnDelay);

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
    CreatureTemplate const* creatureInfo = sObjectMgr->GetCreatureTemplate(entry);
    if (!creatureInfo)
    {
        TC_LOG_ERROR("sql.sql", "Creature::InitEntry creature entry {} does not exist.", entry);
        return false;
    }

    m_creatureInfo = creatureInfo;
    SetEntry(entry);
    m_creatureDifficulty = creatureInfo->GetDifficulty(!IsPet() ? GetMap()->GetDifficultyID() : DIFFICULTY_NONE);

    // equal to player Race field, but creature does not have race
    SetRace(RACE_NONE);

    // known valid are: CLASS_WARRIOR, CLASS_PALADIN, CLASS_ROGUE, CLASS_MAGE
    SetClass(uint8(creatureInfo->unit_class));

    // Cancel load if no model defined
    if (!(creatureInfo->GetFirstValidModel()))
    {
        TC_LOG_ERROR("sql.sql", "Creature (Entry: {}) has no model defined in table `creature_template`, can't load. ", entry);
        return false;
    }

    CreatureModel model = *ObjectMgr::ChooseDisplayId(creatureInfo, data);
    CreatureModelInfo const* minfo = sObjectMgr->GetCreatureModelRandomGender(&model, creatureInfo);
    if (!minfo)                                             // Cancel load if no model defined
    {
        TC_LOG_ERROR("sql.sql", "Creature (Entry: {}) has invalid model {} defined in table `creature_template`, can't load.", entry, model.CreatureDisplayID);
        return false;
    }

    SetDisplayId(model.CreatureDisplayID, true);

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

    SetName(creatureInfo->Name);                              // at normal entry always

    SetModCastingSpeed(1.0f);
    SetModSpellHaste(1.0f);
    SetModHaste(1.0f);
    SetModRangedHaste(1.0f);
    SetModHasteRegen(1.0f);
    SetModTimeRate(1.0f);
    SetSpellEmpowerStage(-1);

    SetSpeedRate(MOVE_WALK,   creatureInfo->speed_walk);
    SetSpeedRate(MOVE_RUN,    creatureInfo->speed_run);
    SetSpeedRate(MOVE_SWIM,   1.0f); // using 1.0 rate
    SetSpeedRate(MOVE_FLIGHT, 1.0f); // using 1.0 rate

    // Will set UNIT_FIELD_BOUNDINGRADIUS, UNIT_FIELD_COMBATREACH and UNIT_FIELD_DISPLAYSCALE
    SetObjectScale(GetNativeObjectScale());

    SetCanDualWield(creatureInfo->flags_extra & CREATURE_FLAG_EXTRA_USE_OFFHAND_ATTACK);

    // checked at loading
    m_defaultMovementType = MovementGeneratorType(data ? data->movementType : creatureInfo->MovementType);
    if (!m_wanderDistance && m_defaultMovementType == RANDOM_MOTION_TYPE)
        m_defaultMovementType = IDLE_MOTION_TYPE;

    for (uint8 i = 0; i < MAX_CREATURE_SPELLS; ++i)
        m_spells[i] = GetCreatureTemplate()->spells[i];

    CreatureStaticFlagsHolder staticFlags = GenerateStaticFlags(m_creatureDifficulty, GetSpawnId(), GetMap()->GetDifficultyID());
    ApplyAllStaticFlags(staticFlags);

    _staticFlags.ApplyFlag(CREATURE_STATIC_FLAG_NO_XP, creatureInfo->type == CREATURE_TYPE_CRITTER
        || IsPet()
        || IsTotem()
        || creatureInfo->flags_extra & CREATURE_FLAG_EXTRA_NO_XP);

    // TODO: migrate these in DB
    _staticFlags.ApplyFlag(CREATURE_STATIC_FLAG_2_ALLOW_MOUNTED_COMBAT, (GetCreatureDifficulty()->TypeFlags & CREATURE_TYPE_FLAG_ALLOW_MOUNTED_COMBAT) != 0);
    SetIgnoreFeignDeath((creatureInfo->flags_extra & CREATURE_FLAG_EXTRA_IGNORE_FEIGN_DEATH) != 0);
    SetInteractionAllowedInCombat((GetCreatureDifficulty()->TypeFlags & CREATURE_TYPE_FLAG_ALLOW_INTERACTION_WHILE_IN_COMBAT) != 0);
    SetTreatAsRaidUnit((GetCreatureDifficulty()->TypeFlags & CREATURE_TYPE_FLAG_TREAT_AS_RAID_UNIT) != 0);

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
    uint32 unitFlags, unitFlags2, unitFlags3;
    ObjectMgr::ChooseCreatureFlags(cInfo, &npcFlags, &unitFlags, &unitFlags2, &unitFlags3, _staticFlags, data);

    if (cInfo->flags_extra & CREATURE_FLAG_EXTRA_WORLDEVENT)
        npcFlags |= sGameEventMgr->GetNPCFlag(this);

    ReplaceAllNpcFlags(NPCFlags(npcFlags & 0xFFFFFFFF));
    ReplaceAllNpcFlags2(NPCFlags2(npcFlags >> 32));

    // if unit is in combat, keep this flag
    unitFlags &= ~UNIT_FLAG_IN_COMBAT;
    if (IsInCombat())
        unitFlags |= UNIT_FLAG_IN_COMBAT;

    ReplaceAllUnitFlags(UnitFlags(unitFlags));
    ReplaceAllUnitFlags2(UnitFlags2(unitFlags2));
    ReplaceAllUnitFlags3(UnitFlags3(unitFlags3));

    ReplaceAllDynamicFlags(UNIT_DYNFLAG_NONE);

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
    {
        SetPvP((factionTemplate->Flags & FACTION_TEMPLATE_FLAG_PVP) != 0);
        if (IsTaxi())
        {
            uint32 taxiNodesId = sObjectMgr->GetNearestTaxiNode(GetPositionX(), GetPositionY(), GetPositionZ(), GetMapId(),
                factionTemplate->FactionGroup & FACTION_MASK_ALLIANCE ? ALLIANCE : HORDE);
            SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::TaxiNodesID), taxiNodesId);
        }
    }

    // updates spell bars for vehicles and set player's faction - should be called here, to overwrite faction that is set from the new template
    if (IsVehicle())
    {
        if (Player* owner = Creature::GetCharmerOrOwnerPlayerOrPlayerItself()) // this check comes in case we don't have a player
        {
            SetFaction(owner->GetFaction()); // vehicles should have same as owner faction
            owner->VehicleSpellInitialize();
        }
    }

    // trigger creature is always uninteractible and can not be attacked
    if (IsTrigger())
        SetUninteractible(true);

    if (HasNpcFlag(UNIT_NPC_FLAG_SPELLCLICK))
        InitializeInteractSpellId();

    InitializeReactState();

    if (cInfo->flags_extra & CREATURE_FLAG_EXTRA_NO_TAUNT)
    {
        ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, true);
        ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_ATTACK_ME, true);
    }

    SetIsCombatDisallowed((cInfo->flags_extra & CREATURE_FLAG_EXTRA_CANNOT_ENTER_COMBAT) != 0);

    InitializeMovementCapabilities();

    LoadCreaturesAddon();
    LoadCreaturesSparringHealth(true);
    LoadTemplateImmunities(cInfo->CreatureImmunitiesId);

    GetThreatManager().EvaluateSuppressed();

    //We must update last scriptId or it looks like we reloaded a script, breaking some things such as gossip temporarily
    LastUsedScriptID = GetScriptId();

    m_stringIds[AsUnderlyingType(StringIdType::Template)] = &cInfo->StringId;

    return true;
}

CreatureStaticFlagsHolder Creature::GenerateStaticFlags(CreatureDifficulty const* creatureDifficulty, ObjectGuid::LowType spawnId, Difficulty difficultyId) const
{
    CreatureStaticFlagsOverride const* staticFlagsOverride = sObjectMgr->GetCreatureStaticFlagsOverride(spawnId, difficultyId);
    if (!staticFlagsOverride)
        return creatureDifficulty->StaticFlags;

    return CreatureStaticFlagsHolder(
        staticFlagsOverride->StaticFlags1.value_or(creatureDifficulty->StaticFlags.GetFlags()),
        staticFlagsOverride->StaticFlags2.value_or(creatureDifficulty->StaticFlags.GetFlags2()),
        staticFlagsOverride->StaticFlags3.value_or(creatureDifficulty->StaticFlags.GetFlags3()),
        staticFlagsOverride->StaticFlags4.value_or(creatureDifficulty->StaticFlags.GetFlags4()),
        staticFlagsOverride->StaticFlags5.value_or(creatureDifficulty->StaticFlags.GetFlags5()),
        staticFlagsOverride->StaticFlags6.value_or(creatureDifficulty->StaticFlags.GetFlags6()),
        staticFlagsOverride->StaticFlags7.value_or(creatureDifficulty->StaticFlags.GetFlags7()),
        staticFlagsOverride->StaticFlags8.value_or(creatureDifficulty->StaticFlags.GetFlags8()));
}

void Creature::ApplyAllStaticFlags(CreatureStaticFlagsHolder const& flags)
{
    _staticFlags = flags;

    // Apply all other side effects of flag changes
    m_updateFlag.NoBirthAnim = flags.HasFlag(CREATURE_STATIC_FLAG_4_NO_BIRTH_ANIM);
}

void Creature::Update(uint32 diff)
{
    if (IsAIEnabled() && m_triggerJustAppeared && m_deathState != DEAD)
    {
        if (IsAreaSpiritHealer() && !IsAreaSpiritHealerIndividual())
            CastSpell(nullptr, SPELL_SPIRIT_HEAL_CHANNEL_AOE, false);

        if (m_respawnCompatibilityMode && m_vehicleKit)
            m_vehicleKit->Reset();
        m_triggerJustAppeared = false;
        AI()->JustAppeared();
    }

    UpdateMovementCapabilities();

    GetThreatManager().Update(diff);

    switch (m_deathState)
    {
        case JUST_RESPAWNED:
            // Must not be called, see Creature::setDeathState JUST_RESPAWNED -> ALIVE promoting.
            TC_LOG_ERROR("entities.unit", "Creature {} in wrong state: JUST_RESPAWNED (4)", GetGUID().ToString());
            break;
        case JUST_DIED:
            // Must not be called, see Creature::setDeathState JUST_DIED -> CORPSE promoting.
            TC_LOG_ERROR("entities.unit", "Creature {} in wrong state: JUST_DIED (1)", GetGUID().ToString());
            break;
        case DEAD:
        {
            if (!m_respawnCompatibilityMode)
            {
                TC_LOG_ERROR("entities.unit", "Creature {} in wrong state: DEAD (3)", GetGUID().ToString());
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

            if (m_loot)
                m_loot->Update();

            for (auto&& [playerOwner, loot] : m_personalLoot)
                loot->Update();

            if (m_corpseRemoveTime <= GameTime::GetGameTime())
            {
                RemoveCorpse(false);
                TC_LOG_DEBUG("entities.unit", "Removing corpse... {} ", GetEntry());
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

            Unit::AIUpdateTick(diff);

            DoMeleeAttackIfReady();

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
                            TC_LOG_DEBUG("entities.unit.chase", "RegenerateHealth() enabled because Creature cannot reach the target. Detail: {}", GetDebugInfo());
                        }
                        else
                            TC_LOG_DEBUG("entities.unit.chase", "RegenerateHealth() disabled even if the Creature cannot reach the target. Detail: {}", GetDebugInfo());
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
                        ai->EnterEvadeMode(EvadeReason::NoPath);
            }
            break;
        }
        default:
            break;
    }
}

void Creature::Heartbeat()
{
    Unit::Heartbeat();

    // Creatures with CREATURE_STATIC_FLAG_2_FORCE_PARTY_MEMBERS_INTO_COMBAT periodically force party members into combat
    ForcePartyMembersIntoCombat();
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
        TC_LOG_ERROR("sql.sql", "Creature::Create(): creature template (guidlow: {}, entry: {}) does not exist.", guidlow, entry);
        return false;
    }

    CreatureDifficulty const* creatureDifficulty = cinfo->GetDifficulty(GetMap()->GetDifficultyID());

    //! Relocate before CreateFromProto, to initialize coords and allow
    //! returning correct zone id for selecting OutdoorPvP/Battlefield script
    Relocate(pos);

    // Check if the position is valid before calling CreateFromProto(), otherwise we might add Auras to Creatures at
    // invalid position, triggering a crash about Auras not removed in the destructor
    if (!IsPositionValid())
    {
        TC_LOG_ERROR("entities.unit", "Creature::Create(): given coordinates for creature (guidlow {}, entry {}) are not valid (X: {}, Y: {}, Z: {}, O: {})", guidlow, entry, pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), pos.GetOrientation());
        return false;
    }
    {
        // area/zone id is needed immediately for ZoneScript::GetCreatureEntry hook before it is known which creature template to load (no model/scale available yet)
        PositionFullTerrainStatus terrainStatus;
        GetMap()->GetFullTerrainStatusForPosition(GetPhaseShift(), GetPositionX(), GetPositionY(), GetPositionZ(), terrainStatus);
        ProcessPositionDataChanged(terrainStatus);
    }

    // Allow players to see those units while dead, do it here (mayby altered by addon auras)
    if (creatureDifficulty->TypeFlags & CREATURE_TYPE_FLAG_VISIBLE_TO_GHOSTS)
        m_serverSideVisibility.SetValue(SERVERSIDE_VISIBILITY_GHOST, GHOST_VISIBILITY_ALIVE | GHOST_VISIBILITY_GHOST);

    if (!CreateFromProto(guidlow, entry, data, vehId))
        return false;

    cinfo = GetCreatureTemplate(); // might be different than initially requested
    if (cinfo->flags_extra & CREATURE_FLAG_EXTRA_DUNGEON_BOSS && map->IsDungeon())
        m_respawnDelay = 0; // special value, prevents respawn for dungeon bosses unless overridden

    switch (GetCreatureClassification())
    {
        case CreatureClassifications::Elite:
            m_corpseDelay = sWorld->getIntConfig(CONFIG_CORPSE_DECAY_ELITE);
            break;
        case CreatureClassifications::RareElite:
            m_corpseDelay = sWorld->getIntConfig(CONFIG_CORPSE_DECAY_RAREELITE);
            break;
        case CreatureClassifications::Obsolete:
            m_corpseDelay = sWorld->getIntConfig(CONFIG_CORPSE_DECAY_OBSOLETE);
            break;
        case CreatureClassifications::Rare:
            m_corpseDelay = sWorld->getIntConfig(CONFIG_CORPSE_DECAY_RARE);
            break;
        case CreatureClassifications::Trivial:
            m_corpseDelay = sWorld->getIntConfig(CONFIG_CORPSE_DECAY_TRIVIAL);
            break;
        case CreatureClassifications::MinusMob:
            m_corpseDelay = sWorld->getIntConfig(CONFIG_CORPSE_DECAY_MINUSMOB);
            break;
        default:
            m_corpseDelay = sWorld->getIntConfig(CONFIG_CORPSE_DECAY_NORMAL);
            break;
    }

    LoadCreaturesAddon();
    LoadCreaturesSparringHealth(true);

    //! Need to be called after LoadCreaturesAddon - MOVEMENTFLAG_HOVER is set there
    m_positionZ += GetHoverOffset();

    LastUsedScriptID = GetScriptId();

    if (IsSpiritHealer() || IsAreaSpiritHealer() || (GetCreatureTemplate()->flags_extra & CREATURE_FLAG_EXTRA_GHOST_VISIBILITY))
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
                AI()->EnterEvadeMode(EvadeReason::Other);
                break;
            }
        }
        return nullptr;
    }

    // enter in evade mode in other case
    AI()->EnterEvadeMode(EvadeReason::NoHostiles);

    return nullptr;
}

void Creature::InitializeReactState()
{
    if (IsTotem() || IsTrigger() || IsCritter() || IsSpiritService() || _staticFlags.HasFlag(CREATURE_STATIC_FLAG_IGNORE_COMBAT))
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

uint32 Creature::GetLootId() const
{
    if (m_lootId)
        return *m_lootId;

    return GetCreatureDifficulty()->LootID;
}

void Creature::SetLootId(Optional<uint32> lootId)
{
    m_lootId = lootId;
}

void Creature::SetTappedBy(Unit const* unit, bool withGroup)
{
    // set the player whose group should receive the right
    // to loot the creature after it dies
    // should be set to nullptr after the loot disappears

    if (!unit)
    {
        m_tapList.clear();
        RemoveDynamicFlag(UNIT_DYNFLAG_LOOTABLE | UNIT_DYNFLAG_TAPPED);
        return;
    }

    if (m_tapList.size() >= CREATURE_TAPPERS_SOFT_CAP)
        return;

    if (unit->GetTypeId() != TYPEID_PLAYER && !unit->IsVehicle())
        return;

    Player* player = unit->GetCharmerOrOwnerPlayerOrPlayerItself();
    if (!player)                                             // normal creature, no player involved
        return;

    m_tapList.insert(player->GetGUID());
    if (withGroup)
        if (Group const* group = player->GetGroup())
            for (auto const* itr = group->GetFirstMember(); itr != nullptr; itr = itr->next())
                if (GetMap()->IsRaid() || group->SameSubGroup(player, itr->GetSource()))
                    m_tapList.insert(itr->GetSource()->GetGUID());

    if (m_tapList.size() >= CREATURE_TAPPERS_SOFT_CAP)
        SetDynamicFlag(UNIT_DYNFLAG_TAPPED);
}

void Creature::SetDontClearTapListOnEvade(bool dontClear)
{
    // only temporary summons are allowed to not clear their tap list
    if (!m_spawnId)
        m_dontClearTapListOnEvade = dontClear;
}

// return true if this creature is tapped by the player or by a member of his group.
bool Creature::isTappedBy(Player const* player) const
{
    return m_tapList.find(player->GetGUID()) != m_tapList.end();
}

Loot* Creature::GetLootForPlayer(Player const* player) const
{
    if (m_personalLoot.empty())
        return m_loot.get();

    if (std::unique_ptr<Loot> const* loot = Trinity::Containers::MapGetValuePtr(m_personalLoot, player->GetGUID()))
        return loot->get();

    return nullptr;
}

bool Creature::IsFullyLooted() const
{
    if (m_loot && !m_loot->isLooted())
        return false;

    for (auto const& [_, loot] : m_personalLoot)
        if (!loot->isLooted())
            return false;

    return true;
}

bool Creature::IsSkinnedBy(Player const* player) const
{
    if (Loot* loot = GetLootForPlayer(player))
        return loot->loot_type == LOOT_SKINNING;

    return false;
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

    uint32 mapId = GetMapId();
    if (TransportBase* transport = GetTransport())
        if (transport->GetMapIdForSpawning() >= 0)
            mapId = transport->GetMapIdForSpawning();

    SaveToDB(mapId, data->spawnDifficulties);
}

void Creature::SaveToDB(uint32 mapid, std::vector<Difficulty> const& spawnDifficulties)
{
    // update in loaded data
    if (!m_spawnId)
        m_spawnId = sObjectMgr->GenerateCreatureSpawnId();

    CreatureData& data = sObjectMgr->NewOrExistCreatureData(m_spawnId);

    uint32 displayId = GetNativeDisplayId();
    uint64 spawnNpcFlags = (uint64(m_unitData->NpcFlags[1]) << 32) | m_unitData->NpcFlags[0];
    Optional<uint64> npcflag;
    Optional<uint32> unitFlags;
    Optional<uint32> unitFlags2;
    Optional<uint32> unitFlags3;

    // check if it's a custom model and if not, use 0 for displayId
    CreatureTemplate const* cinfo = GetCreatureTemplate();
    if (cinfo)
    {
        for (CreatureModel const& model : cinfo->Models)
            if (displayId && displayId == model.CreatureDisplayID)
                displayId = 0;

        if (spawnNpcFlags != cinfo->npcflag)
            npcflag = spawnNpcFlags;

        if (m_unitData->Flags != cinfo->unit_flags)
            unitFlags = m_unitData->Flags;

        if (m_unitData->Flags2 != cinfo->unit_flags2)
            unitFlags2 = m_unitData->Flags2;

        if (m_unitData->Flags3 != cinfo->unit_flags3)
            unitFlags3 = m_unitData->Flags3;
    }

    if (!data.spawnId)
        data.spawnId = m_spawnId;
    ASSERT(data.spawnId == m_spawnId);
    data.id = GetEntry();
    if (displayId)
        data.display.emplace(displayId, DEFAULT_PLAYER_DISPLAY_SCALE, 1.0f);
    else
        data.display.reset();
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
    data.curHealthPct = uint32(GetHealthPct());
    // prevent add data integrity problems
    data.movementType = !m_wanderDistance && GetDefaultMovementType() == RANDOM_MOTION_TYPE
        ? IDLE_MOTION_TYPE : GetDefaultMovementType();
    data.spawnDifficulties = spawnDifficulties;
    data.npcflag = npcflag;
    data.unit_flags = unitFlags;
    data.unit_flags2 = unitFlags2;
    data.unit_flags3 = unitFlags3;
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
    stmt->setUInt32(index++, uint32(GetHealthPct()));
    stmt->setUInt8(index++, uint8(GetDefaultMovementType()));
    if (npcflag.has_value())
        stmt->setUInt64(index++, *npcflag);
    else
        stmt->setNull(index++);

    if (unitFlags.has_value())
        stmt->setUInt32(index++, *unitFlags);
    else
        stmt->setNull(index++);

    if (unitFlags2.has_value())
        stmt->setUInt32(index++, *unitFlags2);
    else
        stmt->setNull(index++);

    if (unitFlags3.has_value())
        stmt->setUInt32(index++, *unitFlags3);
    else
        stmt->setNull(index++);
    trans->Append(stmt);

    WorldDatabase.CommitTransaction(trans);
}

void Creature::SelectLevel()
{
    // Level
    ApplyLevelScaling();
    int32 levelWithDelta = m_unitData->ScalingLevelMax + m_unitData->ScalingLevelDelta;
    uint8 level = RoundToInterval<int32>(levelWithDelta, 1, STRONG_MAX_LEVEL);
    SetLevel(level);

    UpdateLevelDependantStats();
}

void Creature::UpdateLevelDependantStats()
{
    CreatureTemplate const* cInfo = GetCreatureTemplate();
    CreatureClassifications classification = IsPet() ? CreatureClassifications::Normal : cInfo->Classification;
    uint8 level = GetLevel();
    CreatureBaseStats const* stats = sObjectMgr->GetCreatureBaseStats(level, cInfo->unit_class);

    // health
    float healthmod = GetHealthMod(classification);

    uint32 basehp = GetMaxHealthByLevel(level);
    uint32 health = uint32(basehp * healthmod);

    SetCreateHealth(health);
    SetMaxHealth(health);
    SetHealth(health);
    ResetPlayerDamageReq();

    SetStatFlatModifier(UNIT_MOD_HEALTH, BASE_VALUE, (float)health);

    // mana
    Powers powerType = CalculateDisplayPowerType();
    SetCreateMana(stats->BaseMana);
    SetStatPctModifier(UnitMods(UNIT_MOD_POWER_START + AsUnderlyingType(powerType)), BASE_PCT, GetCreatureDifficulty()->ManaModifier);
    SetPowerType(powerType, true, true);

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

    float armor = GetBaseArmorForLevel(level);
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

float Creature::GetHealthMod(CreatureClassifications classification)
{
    switch (classification)
    {
        case CreatureClassifications::Normal:
            return sWorld->getRate(RATE_CREATURE_HP_NORMAL);
        case CreatureClassifications::Elite:
            return sWorld->getRate(RATE_CREATURE_HP_ELITE);
        case CreatureClassifications::RareElite:
            return sWorld->getRate(RATE_CREATURE_HP_RAREELITE);
        case CreatureClassifications::Obsolete:
            return sWorld->getRate(RATE_CREATURE_HP_OBSOLETE);
        case CreatureClassifications::Rare:
            return sWorld->getRate(RATE_CREATURE_HP_RARE);
        case CreatureClassifications::Trivial:
            return sWorld->getRate(RATE_CREATURE_HP_TRIVIAL);
        case CreatureClassifications::MinusMob:
            return sWorld->getRate(RATE_CREATURE_HP_MINUSMOB);
        default:
            return sWorld->getRate(RATE_CREATURE_HP_ELITE);
    }
}

void Creature::LowerPlayerDamageReq(uint64 unDamage)
{
    if (m_PlayerDamageReq)
        m_PlayerDamageReq > unDamage ? m_PlayerDamageReq -= unDamage : m_PlayerDamageReq = 0;
}

float Creature::GetDamageMod(CreatureClassifications classification)
{
    switch (classification)
    {
        case CreatureClassifications::Normal:
            return sWorld->getRate(RATE_CREATURE_DAMAGE_NORMAL);
        case CreatureClassifications::Elite:
            return sWorld->getRate(RATE_CREATURE_DAMAGE_ELITE);
        case CreatureClassifications::RareElite:
            return sWorld->getRate(RATE_CREATURE_DAMAGE_RAREELITE);
        case CreatureClassifications::Obsolete:
            return sWorld->getRate(RATE_CREATURE_DAMAGE_OBSOLETE);
        case CreatureClassifications::Rare:
            return sWorld->getRate(RATE_CREATURE_DAMAGE_RARE);
        case CreatureClassifications::Trivial:
            return sWorld->getRate(RATE_CREATURE_DAMAGE_TRIVIAL);
        case CreatureClassifications::MinusMob:
            return sWorld->getRate(RATE_CREATURE_DAMAGE_MINUSMOB);
        default:
            return sWorld->getRate(RATE_CREATURE_DAMAGE_ELITE);
    }
}

float Creature::GetSpellDamageMod(CreatureClassifications classification) const
{
    switch (classification)
    {
        case CreatureClassifications::Normal:
            return sWorld->getRate(RATE_CREATURE_SPELLDAMAGE_NORMAL);
        case CreatureClassifications::Elite:
            return sWorld->getRate(RATE_CREATURE_SPELLDAMAGE_ELITE);
        case CreatureClassifications::RareElite:
            return sWorld->getRate(RATE_CREATURE_SPELLDAMAGE_RAREELITE);
        case CreatureClassifications::Obsolete:
            return sWorld->getRate(RATE_CREATURE_SPELLDAMAGE_OBSOLETE);
        case CreatureClassifications::Rare:
            return sWorld->getRate(RATE_CREATURE_SPELLDAMAGE_RARE);
        case CreatureClassifications::Trivial:
            return sWorld->getRate(RATE_CREATURE_SPELLDAMAGE_TRIVIAL);
        case CreatureClassifications::MinusMob:
            return sWorld->getRate(RATE_CREATURE_SPELLDAMAGE_MINUSMOB);
        default:
            return sWorld->getRate(RATE_CREATURE_SPELLDAMAGE_ELITE);
    }
}

void Creature::OverrideSparringHealthPct(std::vector<float> const& healthPct)
{
    _sparringHealthPct = Trinity::Containers::SelectRandomContainerElement(healthPct);
}

uint32 Creature::CalculateDamageForSparring(Unit* attacker, uint32 damage)
{
    if (GetSparringHealthPct() == 0)
        return damage;

    if (!attacker)
        return damage;

    if (!attacker->IsCreature() || attacker->IsCharmedOwnedByPlayerOrPlayer() || IsCharmedOwnedByPlayerOrPlayer())
        return damage;

    if (GetHealthPct() <= GetSparringHealthPct())
        return 0;

    uint32 sparringHealth = GetMaxHealth() * GetSparringHealthPct() / 100;
    if (GetHealth() - damage <= sparringHealth)
        return GetHealth() - sparringHealth;

    if (damage >= GetHealth())
        return GetHealth() - 1;

    return damage;
}

bool Creature::ShouldFakeDamageFrom(Unit* attacker)
{
    if (!GetSparringHealthPct())
        return false;

    if (!attacker)
        return false;

    if (!attacker->IsCreature())
        return false;

    if (attacker->IsCharmedOwnedByPlayerOrPlayer() || IsCharmedOwnedByPlayerOrPlayer())
        return false;

    if (GetHealthPct() > GetSparringHealthPct())
        return false;

    return true;
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
        TC_LOG_ERROR("sql.sql", "Creature::CreateFromProto(): creature template (guidlow: {}, entry: {}) does not exist.", guidlow, entry);
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

    if (!IsPet())
        if (uint32 vignetteId = GetCreatureTemplate()->VignetteID)
            SetVignette(vignetteId);

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
                    TC_LOG_DEBUG("maps", "Would have spawned {} but {} already exists", spawnId, creatureBounds.first->second->GetGUID().ToString());
                    return false;
                }
                else
                {
                    despawnList.push_back(itr->second);
                    TC_LOG_DEBUG("maps", "Despawned dead instance of spawn {} ({})", spawnId, itr->second->GetGUID().ToString());
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
        TC_LOG_ERROR("sql.sql", "Creature (SpawnID {}) not found in table `creature`, can't load. ", spawnId);
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
            if (!data->poolId)
            {
                TC_LOG_ERROR("entities.unit", "Creature (SpawnID {}) trying to load in inactive spawn group '{}':\n{}", spawnId, data->spawnGroupData->name, GetDebugInfo());
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
            if (!data->poolId)
            {
                TC_LOG_ERROR("entities.unit", "Creature (SpawnID {}) trying to load despite a respawn timer in progress:\n{}", spawnId, GetDebugInfo());
                return false;
            }
        }
        else
        {
            // compatibility mode creatures will be respawned in ::Update()
            m_deathState = DEAD;
        }

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

    m_stringIds[AsUnderlyingType(StringIdType::Spawn)] = &data->StringId;

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
    SetHealth(CountPctFromMaxHealth(m_creatureData ? m_creatureData->curHealthPct : 100));
    SetInitialPowerValue(GetPowerType());
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

bool Creature::IsInvisibleDueToDespawn(WorldObject const* seer) const
{
    if (Unit::IsInvisibleDueToDespawn(seer))
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

        if (IsNeutralToAll() || !IsWithinDistInMap(who, GetAttackDistance(who) + m_CombatDistance))
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

        ReplaceAllNpcFlags(UNIT_NPC_FLAG_NONE);
        ReplaceAllNpcFlags2(UNIT_NPC_FLAG_2_NONE);

        SetMountDisplayId(0); // if creature is mounted on a virtual mount, remove it at death

        setActive(false);

        SetNoSearchAssistance(false);

        //Dismiss group if is leader
        if (m_formation && m_formation->GetLeader() == this)
            m_formation->FormationReset(true);

        bool needsFalling = (IsFlying() || IsHovering()) && !IsUnderWater() && !HasUnitState(UNIT_STATE_ROOT);
        SetHover(false, false);
        SetDisableGravity(false, false);

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

        SetTappedBy(nullptr);
        ResetPlayerDamageReq();

        SetCannotReachTarget(false);
        UpdateMovementCapabilities();

        ClearUnitState(UNIT_STATE_ALL_ERASABLE);

        if (!IsPet())
        {
            CreatureData const* creatureData = GetCreatureData();
            CreatureTemplate const* cInfo = GetCreatureTemplate();

            uint64 npcFlags;
            uint32 unitFlags, unitFlags2, unitFlags3;
            ObjectMgr::ChooseCreatureFlags(cInfo, &npcFlags, &unitFlags, &unitFlags2, &unitFlags3, _staticFlags, creatureData);

            if (cInfo->flags_extra & CREATURE_FLAG_EXTRA_WORLDEVENT)
                npcFlags |= sGameEventMgr->GetNPCFlag(this);

            ReplaceAllNpcFlags(NPCFlags(npcFlags & 0xFFFFFFFF));
            ReplaceAllNpcFlags2(NPCFlags2(npcFlags >> 32));

            ReplaceAllUnitFlags(UnitFlags(unitFlags));
            ReplaceAllUnitFlags2(UnitFlags2(unitFlags2));
            ReplaceAllUnitFlags3(UnitFlags3(unitFlags3));
            ReplaceAllDynamicFlags(UNIT_DYNFLAG_NONE);

            RemoveUnitFlag(UNIT_FLAG_IN_COMBAT);

            SetMeleeDamageSchool(SpellSchools(cInfo->dmgschool));

            if (uint32 vignetteId = cInfo->VignetteID)
                SetVignette(vignetteId);
        }

        Motion_Initialize();
        Unit::setDeathState(ALIVE);
        LoadCreaturesAddon();
        LoadCreaturesSparringHealth();
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
        UpdateObjectVisibilityOnDestroy();
        RemoveCorpse(false, false);

        if (getDeathState() == DEAD)
        {
            TC_LOG_DEBUG("entities.unit", "Respawning creature {} ({})", GetName(), GetGUID().ToString());
            m_respawnTime = 0;
            ResetPickPocketRefillTimer();
            m_loot = nullptr;

            if (m_originalEntry != GetEntry())
                UpdateEntry(m_originalEntry);

            SelectLevel();

            setDeathState(JUST_RESPAWNED);

            CreatureModel display(GetNativeDisplayId(), GetNativeDisplayScale(), 1.0f);
            if (sObjectMgr->GetCreatureModelRandomGender(&display, GetCreatureTemplate()))
                SetDisplayId(display.CreatureDisplayID, true);

            GetMotionMaster()->InitializeDefault();

            // Re-initialize reactstate that could be altered by movementgenerators
            InitializeReactState();

            if (UnitAI* ai = AI()) // reset the AI to be sure no dirty or uninitialized values will be used till next tick
                ai->Reset();

            m_triggerJustAppeared = true;

            uint32 poolid = GetCreatureData() ? GetCreatureData()->poolId : 0;
            if (poolid)
                sPoolMgr->UpdatePool<Creature>(GetMap()->GetPoolData(), poolid, GetSpawnId());
        }
        UpdateObjectVisibility();
    }
    else
    {
        if (m_spawnId)
            GetMap()->Respawn(SPAWN_TYPE_CREATURE, m_spawnId);
    }

    TC_LOG_DEBUG("entities.unit", "Respawning creature {} ({})",
        GetName(), GetGUID().ToString());

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
        UpdateObjectVisibilityOnDestroy();

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

void Creature::LoadTemplateImmunities(int32 creatureImmunitiesId)
{
    // uint32 max used for "spell id", the immunity system will not perform SpellInfo checks against invalid spells
    // used so we know which immunities were loaded from template
    static uint32 constexpr placeholderSpellId = std::numeric_limits<uint32>::max();

    auto applyCreatureImmunities = [this](CreatureImmunities const* immunities, bool apply)
    {
        for (std::size_t i = 0; i < immunities->School.size(); ++i)
            if (immunities->School[i])
                ApplySpellImmune(placeholderSpellId, IMMUNITY_SCHOOL, 1 << i, apply);

        for (std::size_t i = 0; i < immunities->DispelType.size(); ++i)
            if (immunities->DispelType[i])
                ApplySpellImmune(placeholderSpellId, IMMUNITY_DISPEL, i, apply);

        for (std::size_t i = 0; i < immunities->Mechanic.size(); ++i)
            if (immunities->Mechanic[i])
                ApplySpellImmune(placeholderSpellId, IMMUNITY_MECHANIC, i, apply);

        for (SpellEffectName effect : immunities->Effect)
            ApplySpellImmune(placeholderSpellId, IMMUNITY_EFFECT, effect, apply);

        for (AuraType aura : immunities->Aura)
            ApplySpellImmune(placeholderSpellId, IMMUNITY_STATE, aura, apply);

        if (immunities->Other != SpellOtherImmunity::None)
            ApplySpellImmune(placeholderSpellId, IMMUNITY_OTHER, immunities->Other.AsUnderlyingType(), apply);
    };

    // unapply template immunities (in case we're updating entry)
    if (CreatureImmunities const* immunities = SpellMgr::GetCreatureImmunities(_creatureImmunitiesId))
        applyCreatureImmunities(immunities, false);

    // apply new immunities
    if (CreatureImmunities const* immunities = SpellMgr::GetCreatureImmunities(creatureImmunitiesId))
    {
        _creatureImmunitiesId = creatureImmunitiesId;
        applyCreatureImmunities(immunities, true);
    }
    else
        _creatureImmunitiesId = 0;
}

bool Creature::IsImmunedToSpellEffect(SpellInfo const* spellInfo, SpellEffectInfo const& spellEffectInfo, WorldObject const* caster,
    bool requireImmunityPurgesEffectAttribute /*= false*/) const
{
    if (GetCreatureTemplate()->type == CREATURE_TYPE_MECHANICAL && spellEffectInfo.IsEffect(SPELL_EFFECT_HEAL))
        return true;

    return Unit::IsImmunedToSpellEffect(spellInfo, spellEffectInfo, caster, requireImmunityPurgesEffectAttribute);
}

bool Creature::IsElite() const
{
    if (IsPet())
        return false;

    return HasClassification(CreatureClassifications::Elite) || HasClassification(CreatureClassifications::RareElite);
}

bool Creature::isWorldBoss() const
{
    if (IsPet())
        return false;

    return (GetCreatureDifficulty()->TypeFlags & CREATURE_TYPE_FLAG_BOSS_MOB) != 0;
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
        TC_LOG_ERROR("entities.unit", "Creature {} SelectNearestTargetInAttackDistance called with dist > MAX_VISIBILITY_DISTANCE. Distance set to ATTACK_DISTANCE.", GetGUID().ToString());
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

    TC_LOG_DEBUG("network", "WORLD: Sent SMSG_AI_REACTION, type {}.", reactionType);
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
        TC_LOG_ERROR("entities.unit", "Creature {} ({}) trying to call for help without being in combat.", GetEntry(), GetName());
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

    if (HasUnitFlag(UNIT_FLAG_NON_ATTACKABLE) || IsImmuneToNPC() || IsUninteractible())
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
        // some creatures can detect fake death
        if (IsIgnoringFeignDeath() && target->HasUnitFlag2(UNIT_FLAG2_FEIGN_DEATH))
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
        if (CanFly())
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

    return sObjectMgr->GetCreatureTemplateAddon(GetEntry());
}

//creature_addon table
bool Creature::LoadCreaturesAddon()
{
    CreatureAddon const* creatureAddon = GetCreatureAddon();
    if (!creatureAddon)
        return false;

    if (uint32 mountDisplayId = _defaultMountDisplayIdOverride.value_or(creatureAddon->mount); mountDisplayId != 0)
        Mount(mountDisplayId);

    SetStandState(UnitStandStateType(creatureAddon->standState));
    ReplaceAllVisFlags(UnitVisFlags(creatureAddon->visFlags));
    SetAnimTier(AnimTier(creatureAddon->animTier), false);

    SetSheath(SheathState(creatureAddon->sheathState));
    ReplaceAllPvpFlags(UnitPVPStateFlags(creatureAddon->pvpFlags));

    // These fields must only be handled by core internals and must not be modified via scripts/DB dat
    ReplaceAllPetFlags(UNIT_PET_FLAG_NONE);
    SetShapeshiftForm(FORM_NONE);

    if (creatureAddon->emote != 0)
        SetEmoteState(Emote(creatureAddon->emote));

    SetAIAnimKitId(creatureAddon->aiAnimKit);
    SetMovementAnimKitId(creatureAddon->movementAnimKit);
    SetMeleeAnimKitId(creatureAddon->meleeAnimKit);

    // Check if visibility distance different
    if (creatureAddon->visibilityDistanceType != VisibilityDistanceType::Normal)
        SetVisibilityDistanceOverride(creatureAddon->visibilityDistanceType);

    // Load Path
    if (creatureAddon->PathId != 0)
        _waypointPathId = creatureAddon->PathId;

    if (!creatureAddon->auras.empty())
    {
        for (std::vector<uint32>::const_iterator itr = creatureAddon->auras.begin(); itr != creatureAddon->auras.end(); ++itr)
        {
            SpellInfo const* AdditionalSpellInfo = sSpellMgr->GetSpellInfo(*itr, GetMap()->GetDifficultyID());
            if (!AdditionalSpellInfo)
            {
                TC_LOG_ERROR("sql.sql", "Creature {} has wrong spell {} defined in `auras` field.", GetGUID().ToString(), *itr);
                continue;
            }

            // skip already applied aura
            if (HasAura(*itr))
                continue;

            AddAura(*itr, this);
            TC_LOG_DEBUG("entities.unit", "Spell: {} added to creature {}", *itr, GetGUID().ToString());
        }
    }
    return true;
}

void Creature::LoadCreaturesSparringHealth(bool force /*= false*/)
{
    if (std::vector<float> const* templateValues = sObjectMgr->GetCreatureTemplateSparringValues(GetCreatureTemplate()->Entry))
        if (force || std::find(templateValues->begin(), templateValues->end(), _sparringHealthPct) != templateValues->end()) // only re-randomize sparring value if it was loaded from template (not when set to custom value from script)
            _sparringHealthPct = Trinity::Containers::SelectRandomContainerElement(*templateValues);
}

/// Send a message to LocalDefense channel for players opposition team in the zone
void Creature::SendZoneUnderAttackMessage(Player* attacker)
{
    WorldPackets::Misc::ZoneUnderAttack packet;
    packet.AreaID = GetAreaId();
    packet.Write();

    Team enemyTeam = attacker->GetTeam();
    if (enemyTeam != ALLIANCE)
        sWorld->SendGlobalMessage(packet.GetRawPacket(), nullptr, ALLIANCE);
    if (enemyTeam != HORDE)
        sWorld->SendGlobalMessage(packet.GetRawPacket(), nullptr, HORDE);
}

void Creature::SetCanMelee(bool canMelee, bool fleeFromMelee /*= false*/)
{
    bool wasFleeingFromMelee = HasFlag(CREATURE_STATIC_FLAG_NO_MELEE_FLEE);

    _staticFlags.ApplyFlag(CREATURE_STATIC_FLAG_NO_MELEE_FLEE, !canMelee && fleeFromMelee);
    _staticFlags.ApplyFlag(CREATURE_STATIC_FLAG_4_NO_MELEE_APPROACH, !canMelee && !fleeFromMelee);

    if (wasFleeingFromMelee == HasFlag(CREATURE_STATIC_FLAG_NO_MELEE_FLEE))
        return;

    Unit* victim = GetVictim();
    if (!victim)
        return;

    MovementGenerator* currentMovement = GetMotionMaster()->GetCurrentMovementGenerator();
    if (!currentMovement)
        return;

    bool canChangeMovement = [&]
    {
        if (wasFleeingFromMelee)
            return currentMovement->GetMovementGeneratorType() == FLEEING_MOTION_TYPE && !HasUnitFlag(UNIT_FLAG_FLEEING);

        return currentMovement->GetMovementGeneratorType() == CHASE_MOTION_TYPE;
    }();

    if (!canChangeMovement)
        return;

    GetMotionMaster()->Remove(currentMovement);
    StartDefaultCombatMovement(victim);
}

void Creature::StartDefaultCombatMovement(Unit* victim, Optional<float> range /*= {}*/, Optional<float> angle /*= {}*/)
{
    if (!HasFlag(CREATURE_STATIC_FLAG_NO_MELEE_FLEE) || IsSummon())
        GetMotionMaster()->MoveChase(victim, range, angle);
    else
        GetMotionMaster()->MoveFleeing(victim);
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

void Creature::InitializeMovementCapabilities()
{
    SetHover(GetMovementTemplate().IsHoverInitiallyEnabled());
    SetDisableGravity(IsFloating());
    SetControlled(IsSessile(), UNIT_STATE_ROOT);

    // If an amphibious creatures was swimming while engaged, disable swimming again
    if (IsAmphibious() && !_staticFlags.HasFlag(CREATURE_STATIC_FLAG_CAN_SWIM))
        RemoveUnitFlag(UNIT_FLAG_CAN_SWIM);

    UpdateMovementCapabilities();
}

void Creature::UpdateMovementCapabilities()
{
    // Do not update movement flags if creature is controlled by a player (charm/vehicle)
    if (m_playerMovingMe)
        return;

    // Set the movement flags if the creature is in that mode. (Only fly if actually in air, only swim if in water, etc)
    float ground = GetFloorZ();
    bool isInAir = (G3D::fuzzyGt(GetPositionZ(), ground + GetHoverOffset() + GROUND_HEIGHT_TOLERANCE) || G3D::fuzzyLt(GetPositionZ(), ground - GROUND_HEIGHT_TOLERANCE)); // Can be underground too, prevent the falling
    if (!isInAir)
        RemoveUnitMovementFlag(MOVEMENTFLAG_FALLING);

    // Some Amphibious creatures toggle swimming while engaged
    if (IsAmphibious() && !HasUnitFlag(UNIT_FLAG_CANT_SWIM) && !HasUnitFlag(UNIT_FLAG_CAN_SWIM) && IsEngaged())
        if (!IsSwimPrevented() || (GetVictim() && !GetVictim()->IsOnOceanFloor()))
            SetUnitFlag(UNIT_FLAG_CAN_SWIM);

    SetSwim(IsInWater() && CanSwim());
}

CreatureMovementData const& Creature::GetMovementTemplate() const
{
    if (CreatureMovementData const* movementOverride = sObjectMgr->GetCreatureMovementOverride(m_spawnId))
        return *movementOverride;

    return GetCreatureTemplate()->Movement;
}

bool Creature::CanSwim() const
{
    if (Unit::CanSwim())
        return true;

    if (IsPet())
        return true;

    return false;
}

void Creature::AllLootRemovedFromCorpse()
{
    time_t now = GameTime::GetGameTime();
    // Do not reset corpse remove time if corpse is already removed
    if (m_corpseRemoveTime <= now)
        return;

    // Scripts can choose to ignore RATE_CORPSE_DECAY_LOOTED by calling SetCorpseDelay(timer, true)
    float decayRate = m_ignoreCorpseDecayRatio ? 1.f : sWorld->getRate(RATE_CORPSE_DECAY_LOOTED);

    // corpse skinnable, but without skinning flag, and then skinned, corpse will despawn next update
    bool isFullySkinned = [&]() -> bool
    {
        if (m_loot && m_loot->loot_type == LOOT_SKINNING && m_loot->isLooted())
            return true;

        bool hasSkinningLoot = false;
        for (auto const& [_, loot] : m_personalLoot)
        {
            if (loot->loot_type == LOOT_SKINNING)
            {
                if (!loot->isLooted())
                    return false;

                hasSkinningLoot = true;
            }
        }

        return hasSkinningLoot;
    }();

    if (isFullySkinned)
        m_corpseRemoveTime = now;
    else
        m_corpseRemoveTime = now + uint32(m_corpseDelay * decayRate);

    m_respawnTime = std::max<time_t>(m_corpseRemoveTime + m_respawnDelay, m_respawnTime);
}

void Creature::SetInteractionAllowedWhileHostile(bool interactionAllowed)
{
    _staticFlags.ApplyFlag(CREATURE_STATIC_FLAG_5_INTERACT_WHILE_HOSTILE, interactionAllowed);
    Unit::SetInteractionAllowedWhileHostile(interactionAllowed);
}

void Creature::SetInteractionAllowedInCombat(bool interactionAllowed)
{
    _staticFlags.ApplyFlag(CREATURE_STATIC_FLAG_3_ALLOW_INTERACTION_WHILE_IN_COMBAT, interactionAllowed);
    Unit::SetInteractionAllowedInCombat(interactionAllowed);
}

void Creature::UpdateNearbyPlayersInteractions()
{
    Unit::UpdateNearbyPlayersInteractions();

    // If as a result of npcflag updates we stop seeing UNIT_NPC_FLAG_QUESTGIVER then
    // we must also send SMSG_QUEST_GIVER_STATUS_MULTIPLE because client will not request it automatically
    if (IsQuestGiver())
    {
        auto sender = [&](Player const* receiver)
        {
            receiver->PlayerTalkClass->SendQuestGiverStatus(receiver->GetQuestDialogStatus(this), GetGUID());
        };
        Trinity::MessageDistDeliverer notifier(this, sender, GetVisibilityRange());
        Cell::VisitWorldObjects(this, notifier, GetVisibilityRange());
    }
}

bool Creature::HasScalableLevels() const
{
    return m_unitData->ContentTuningID != 0;
}

void Creature::ApplyLevelScaling()
{
    CreatureDifficulty const* creatureDifficulty = GetCreatureDifficulty();

    if (Optional<ContentTuningLevels> levels = sDB2Manager.GetContentTuningData(creatureDifficulty->ContentTuningID, 0))
    {
        SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::ScalingLevelMin), levels->MinLevel);
        SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::ScalingLevelMax), levels->MaxLevel);
    }

    int32 mindelta = std::min(creatureDifficulty->DeltaLevelMax, creatureDifficulty->DeltaLevelMin);
    int32 maxdelta = std::max(creatureDifficulty->DeltaLevelMax, creatureDifficulty->DeltaLevelMin);
    int32 delta = mindelta == maxdelta ? mindelta : irand(mindelta, maxdelta);

    SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::ScalingLevelDelta), delta);
    SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::ContentTuningID), creatureDifficulty->ContentTuningID);
}

uint64 Creature::GetMaxHealthByLevel(uint8 level) const
{
    CreatureTemplate const* cInfo = GetCreatureTemplate();
    CreatureDifficulty const* creatureDifficulty = GetCreatureDifficulty();
    float baseHealth = sDB2Manager.EvaluateExpectedStat(ExpectedStatType::CreatureHealth, level, creatureDifficulty->GetHealthScalingExpansion(), creatureDifficulty->ContentTuningID, Classes(cInfo->unit_class), 0);
    return std::max(baseHealth * creatureDifficulty->HealthModifier, 1.0f);
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
    CreatureDifficulty const* creatureDifficulty = GetCreatureDifficulty();
    return sDB2Manager.EvaluateExpectedStat(ExpectedStatType::CreatureAutoAttackDps, level, creatureDifficulty->GetHealthScalingExpansion(), creatureDifficulty->ContentTuningID, Classes(cInfo->unit_class), 0);
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
    CreatureDifficulty const* creatureDifficulty = GetCreatureDifficulty();
    float baseArmor = sDB2Manager.EvaluateExpectedStat(ExpectedStatType::CreatureArmor, level, creatureDifficulty->GetHealthScalingExpansion(), creatureDifficulty->ContentTuningID, Classes(cInfo->unit_class), 0);
    return baseArmor * creatureDifficulty->ArmorModifier;
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

    return ASSERT_NOTNULL(sObjectMgr->GetCreatureTemplate(GetEntry()))->ScriptID;
}

void Creature::InheritStringIds(Creature const* parent)
{
    // copy references to stringIds from template and spawn
    m_stringIds = parent->m_stringIds;

    // then copy script stringId, not just its reference
    SetScriptStringId(std::string(parent->GetStringId(StringIdType::Script)));
}

bool Creature::HasStringId(std::string_view id) const
{
    return std::ranges::any_of(m_stringIds, [id](std::string const* stringId) { return stringId && *stringId == id; });
}

void Creature::SetScriptStringId(std::string id)
{
    if (!id.empty())
    {
        m_scriptStringId.emplace(std::move(id));
        m_stringIds[AsUnderlyingType(StringIdType::Script)] = &*m_scriptStringId;
    }
    else
    {
        m_scriptStringId.reset();
        m_stringIds[AsUnderlyingType(StringIdType::Script)] = nullptr;
    }
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

uint8 Creature::GetPetAutoSpellSize() const
{
    return MAX_SPELL_CHARM;
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
            if (spellInfo->GetRecoveryTime() == 0 && spellInfo->RangeEntry && spellInfo->RangeEntry->ID != 1 /*Self*/ && spellInfo->RangeEntry->ID != 2 /*Combat Range*/ && spellInfo->GetMaxRange() > range)
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
        TC_LOG_DEBUG("entities.unit.chase", "Creature::SetCannotReachTarget() called with true. Details: {}", GetDebugInfo());
}

void Creature::SetDefaultMount(Optional<uint32> mountCreatureDisplayId)
{
    if (mountCreatureDisplayId && !sCreatureDisplayInfoStore.HasRecord(*mountCreatureDisplayId))
        mountCreatureDisplayId.reset();

    _defaultMountDisplayIdOverride = mountCreatureDisplayId;
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
        SetBoundingRadius((IsPet() ? 1.0f : minfo->bounding_radius) * scale * GetDisplayScale());
        SetCombatReach((IsPet() ? DEFAULT_PLAYER_COMBAT_REACH : minfo->combat_reach) * scale * GetDisplayScale());
    }
}

void Creature::SetDisplayId(uint32 displayId, bool setNative /*= false*/)
{
    Unit::SetDisplayId(displayId, setNative);

    if (CreatureModelInfo const* modelInfo = sObjectMgr->GetCreatureModelInfo(displayId))
    {
        SetBoundingRadius((IsPet() ? 1.0f : modelInfo->bounding_radius) * GetObjectScale() * GetDisplayScale());
        SetCombatReach((IsPet() ? DEFAULT_PLAYER_COMBAT_REACH : modelInfo->combat_reach) * GetObjectScale() * GetDisplayScale());
    }
}

void Creature::SetDisplayFromModel(uint32 modelIdx)
{
    if (CreatureModel const* model = GetCreatureTemplate()->GetModelByIdx(modelIdx))
        SetDisplayId(model->CreatureDisplayID);
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

    bool const noTurnDuringCast = spellInfo->HasAttribute(SPELL_ATTR5_AI_DOESNT_FACE_TARGET);
    bool const turnDisabled = CannotTurn();
    // set target, then force send update packet to players if it changed to provide appropriate facing
    ObjectGuid newTarget = (target && !noTurnDuringCast && !turnDisabled) ? target->GetGUID() : ObjectGuid::Empty;
    if (GetTarget() != newTarget)
        SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::Target), newTarget);

    // If we are not allowed to turn during cast but have a focus target, face the target
    if (!turnDisabled && noTurnDuringCast && target)
        SetFacingToObject(target, false);

    if (noTurnDuringCast)
        AddUnitState(UNIT_STATE_FOCUSING);
}

bool Creature::HasSpellFocus(Spell const* focusSpell) const
{
    if (isDead()) // dead creatures cannot focus
    {
        if (_spellFocusInfo.Spell || _spellFocusInfo.Delay)
        {
            TC_LOG_WARN("entities.unit", "Creature '{}' (entry {}) has spell focus (spell id {}, delay {}ms) despite being dead.",
                        GetName(), GetEntry(), _spellFocusInfo.Spell ? _spellFocusInfo.Spell->GetSpellInfo()->Id : 0, _spellFocusInfo.Delay);
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

    if (_spellFocusInfo.Spell->GetSpellInfo()->HasAttribute(SPELL_ATTR5_AI_DOESNT_FACE_TARGET))
        ClearUnitState(UNIT_STATE_FOCUSING);

    if (IsPet()) // player pets do not use delay system
    {
        if (!CannotTurn())
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
        TC_LOG_ERROR("entities.unit", "Creature::ReacquireSpellFocusTarget() being called with HasSpellFocus() returning false. {}", GetDebugInfo());
        return;
    }

    SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::Target), _spellFocusInfo.Target);

    if (!CannotTurn())
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
    if (!Unit::IsMovementPreventedByCasting() && !HasSpellFocus())
        return false;

    return true;
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
        TC_LOG_ERROR("sql.sql", "CreatureTextMgr: TextGroup {} for Creature({}) {}, id {} already added", uint32(textGroup), GetName(), GetGUID().ToString(), uint32(id));
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
    return !_staticFlags.HasFlag(CREATURE_STATIC_FLAG_NO_XP);
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

    GetThreatManager().ResetUpdateTimer();

    if (!HasFlag(CREATURE_STATIC_FLAG_2_ALLOW_MOUNTED_COMBAT))
        Dismount();

    if (IsPet() || IsGuardian()) // update pets' speed for catchup OOC speed
    {
        UpdateSpeed(MOVE_RUN);
        UpdateSpeed(MOVE_SWIM);
        UpdateSpeed(MOVE_FLIGHT);
    }

    MovementGeneratorType const movetype = GetMotionMaster()->GetCurrentMovementGeneratorType();
    if (movetype == WAYPOINT_MOTION_TYPE || movetype == POINT_MOTION_TYPE || (IsAIEnabled() && AI()->IsEscorted()))
    {
        SetHomePosition(GetPosition());

        // if its a vehicle, set the home positon of every creature passenger at engage
        // so that they are in combat range if hostile
        if (Vehicle* vehicle = GetVehicleKit())
        {
            for (auto seat = vehicle->Seats.begin(); seat != vehicle->Seats.end(); ++seat)
                if (Unit* passenger = ObjectAccessor::GetUnit(*this, seat->second.Passenger.Guid))
                    if (Creature* creature = passenger->ToCreature())
                        creature->SetHomePosition(GetPosition());
        }
    }

    if (CreatureAI* ai = AI())
        ai->JustEngagedWith(target);
    if (CreatureGroup* formation = GetFormation())
        formation->MemberEngagingTarget(this, target);

    // Creatures with CREATURE_STATIC_FLAG_2_FORCE_PARTY_MEMBERS_INTO_COMBAT periodically force party members into combat
    ForcePartyMembersIntoCombat();
}

void Creature::AtDisengage()
{
    Unit::AtDisengage();

    ClearUnitState(UNIT_STATE_ATTACK_PLAYER);
    if (IsAlive() && HasDynamicFlag(UNIT_DYNFLAG_TAPPED))
        RemoveDynamicFlag(UNIT_DYNFLAG_TAPPED);

    if (IsPet() || IsGuardian()) // update pets' speed for catchup OOC speed
    {
        UpdateSpeed(MOVE_RUN);
        UpdateSpeed(MOVE_SWIM);
        UpdateSpeed(MOVE_FLIGHT);
    }
}

void Creature::ForcePartyMembersIntoCombat()
{
    if (!_staticFlags.HasFlag(CREATURE_STATIC_FLAG_2_FORCE_PARTY_MEMBERS_INTO_COMBAT) || !IsEngaged())
        return;

    Trinity::Containers::FlatSet<Group const*> partiesToForceIntoCombat;
    for (auto const& [_, combatReference] : GetCombatManager().GetPvECombatRefs())
    {
        if (combatReference->IsSuppressedFor(this))
            continue;

        Player* player = Object::ToPlayer(combatReference->GetOther(this));
        if (!player || player->IsGameMaster())
            continue;

        if (Group const* group = player->GetGroup())
            partiesToForceIntoCombat.insert(group);
    }

    for (Group const* partyToForceIntoCombat : partiesToForceIntoCombat)
    {
        for (GroupReference const* ref = partyToForceIntoCombat->GetFirstMember(); ref != nullptr; ref = ref->next())
        {
            Player* player = ref->GetSource();
            if (!player || !player->IsInWorld() || player->GetMap() != GetMap() || player->IsGameMaster())
                continue;

            EngageWithTarget(player);
        }
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
        << " WaypointPath: " << GetWaypointPathId() << " SpawnId: " << GetSpawnId();
    return sstr.str();
}

void Creature::ExitVehicle(Position const* /*exitPosition*/)
{
    Unit::ExitVehicle();

    // if the creature exits a vehicle, set it's home position to the
    // exited position so it won't run away (home) and evade if it's hostile
    SetHomePosition(GetPosition());
}

uint32 Creature::GetGossipMenuId() const
{
    return _gossipMenuId;
}

void Creature::SetGossipMenuId(uint32 gossipMenuId)
{
    _gossipMenuId = gossipMenuId;
}

uint32 Creature::GetTrainerId() const
{
    if (_trainerId)
        return *_trainerId;

    return sObjectMgr->GetCreatureDefaultTrainer(GetEntry());
}

void Creature::SetTrainerId(Optional<uint32> trainerId)
{
    _trainerId = trainerId;
}

enum AreaSpiritHealerData
{
    NPC_ALLIANCE_GRAVEYARD_TELEPORT     = 26350,
    NPC_HORDE_GRAVEYARD_TELEPORT        = 26351
};

void Creature::SummonGraveyardTeleporter()
{
    if (!IsAreaSpiritHealer())
        return;

    uint32 npcEntry = GetFaction() == FACTION_ALLIANCE_GENERIC ? NPC_ALLIANCE_GRAVEYARD_TELEPORT : NPC_HORDE_GRAVEYARD_TELEPORT;

    // maybe NPC is summoned with these spells:
    // ID - 24237 Summon Alliance Graveyard Teleporter (SERVERSIDE)
    // ID - 46894 Summon Horde Graveyard Teleporter (SERVERSIDE)
    SummonCreature(npcEntry, GetPosition(), TEMPSUMMON_TIMED_DESPAWN, 1s, 0, 0);
}

void Creature::InitializeInteractSpellId()
{
    auto clickBounds = sObjectMgr->GetSpellClickInfoMapBounds(GetEntry());
    auto itr = clickBounds.begin();
    // Set InteractSpellID if there is only one row in npc_spellclick_spells in db for this creature
    if (itr != clickBounds.end() && ++itr == clickBounds.end())
        SetInteractSpellId(clickBounds.begin()->second.spellId);
    else
        SetInteractSpellId(0);
}
