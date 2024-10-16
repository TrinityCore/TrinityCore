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

#include "CriteriaHandler.h"
#include "ArenaTeamMgr.h"
#include "AzeriteItem.h"
#include "Battleground.h"
#include "BattlePetMgr.h"
#include "CollectionMgr.h"
#include "Containers.h"
#include "Creature.h"
#include "DatabaseEnv.h"
#include "DB2Stores.h"
#include "DisableMgr.h"
#include "GameEventMgr.h"
#include "GameTime.h"
#include "Garrison.h"
#include "Group.h"
#include "InstanceScript.h"
#include "Item.h"
#include "ItemBonusMgr.h"
#include "LanguageMgr.h"
#include "Log.h"
#include "Map.h"
#include "MapManager.h"
#include "ObjectMgr.h"
#include "PhasingHandler.h"
#include "Player.h"
#include "RBAC.h"
#include "RealmList.h"
#include "ReputationMgr.h"
#include "Scenario.h"
#include "ScriptMgr.h"
#include "SpellAuras.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include "World.h"
#include "WorldSession.h"
#include "WorldStateMgr.h"
#include "WowTime.h"

bool CriteriaData::IsValid(Criteria const* criteria)
{
    if (DataType >= MAX_CRITERIA_DATA_TYPE)
    {
        TC_LOG_ERROR("sql.sql", "Table `criteria_data` for criteria (Entry: {}) contains a wrong data type ({}), ignored.", criteria->ID, DataType);
        return false;
    }
    switch (CriteriaType(criteria->Entry->Type))
    {
        case CriteriaType::KillCreature:
        case CriteriaType::KillAnyCreature:
        case CriteriaType::WinBattleground:
        case CriteriaType::MaxDistFallenWithoutDying:
        case CriteriaType::CompleteQuest:              // only hardcoded list
        case CriteriaType::CastSpell:
        case CriteriaType::WinAnyRankedArena:
        case CriteriaType::DoEmote:
        case CriteriaType::KillPlayer:
        case CriteriaType::WinDuel:
        case CriteriaType::GetLootByType:
        case CriteriaType::LandTargetedSpellOnTarget:
        case CriteriaType::BeSpellTarget:
        case CriteriaType::GainAura:
        case CriteriaType::EquipItemInSlot:
        case CriteriaType::RollNeed:
        case CriteriaType::RollGreed:
        case CriteriaType::TrackedWorldStateUIModified:
        case CriteriaType::EarnHonorableKill:
        case CriteriaType::CompleteDailyQuest:         // only Children's Week achievements
        case CriteriaType::UseItem:                    // only Children's Week achievements
        case CriteriaType::DeliveredKillingBlow:
        case CriteriaType::ReachLevel:
        case CriteriaType::Login:
        case CriteriaType::LootAnyItem:
        case CriteriaType::ObtainAnyItem:
            break;
        default:
            if (DataType != CRITERIA_DATA_TYPE_SCRIPT)
            {
                TC_LOG_ERROR("sql.sql", "Table `criteria_data` contains data for a non-supported criteria type (Entry: {} Type: {}), ignored.", criteria->ID, criteria->Entry->Type);
                return false;
            }
            break;
    }

    switch (DataType)
    {
        case CRITERIA_DATA_TYPE_NONE:
        case CRITERIA_DATA_TYPE_INSTANCE_SCRIPT:
            return true;
        case CRITERIA_DATA_TYPE_T_CREATURE:
            if (!Creature.Id || !sObjectMgr->GetCreatureTemplate(Creature.Id))
            {
                TC_LOG_ERROR("sql.sql", "Table `criteria_data` (Entry: {} Type: {}) for data type CRITERIA_DATA_TYPE_CREATURE ({}) contains a non-existing creature id in value1 ({}), ignored.",
                    criteria->ID, criteria->Entry->Type, DataType, Creature.Id);
                return false;
            }
            return true;
        case CRITERIA_DATA_TYPE_T_PLAYER_CLASS_RACE:
            if (!ClassRace.Class && !ClassRace.Race)
            {
                TC_LOG_ERROR("sql.sql", "Table `criteria_data` (Entry: {} Type: {}) for data type CRITERIA_DATA_TYPE_T_PLAYER_CLASS_RACE ({}) must not have 0 in either value field, ignored.",
                    criteria->ID, criteria->Entry->Type, DataType);
                return false;
            }
            if (ClassRace.Class && ((1 << (ClassRace.Class-1)) & CLASSMASK_ALL_PLAYABLE) == 0)
            {
                TC_LOG_ERROR("sql.sql", "Table `criteria_data` (Entry: {} Type: {}) for data type CRITERIA_DATA_TYPE_T_PLAYER_CLASS_RACE ({}) contains a non-existing class in value1 ({}), ignored.",
                    criteria->ID, criteria->Entry->Type, DataType, ClassRace.Class);
                return false;
            }
            if (!Trinity::RaceMask<uint64>{ RACEMASK_ALL_PLAYABLE }.HasRace(ClassRace.Race))
            {
                TC_LOG_ERROR("sql.sql", "Table `criteria_data` (Entry: {} Type: {}) for data type CRITERIA_DATA_TYPE_T_PLAYER_CLASS_RACE ({}) contains a non-existing race in value2 ({}), ignored.",
                    criteria->ID, criteria->Entry->Type, DataType, ClassRace.Race);
                return false;
            }
            return true;
        case CRITERIA_DATA_TYPE_T_PLAYER_LESS_HEALTH:
            if (Health.Percent < 1 || Health.Percent > 100)
            {
                TC_LOG_ERROR("sql.sql", "Table `criteria_data` (Entry: {} Type: {}) for data type CRITERIA_DATA_TYPE_PLAYER_LESS_HEALTH ({}) contains a wrong percent value in value1 ({}), ignored.",
                    criteria->ID, criteria->Entry->Type, DataType, Health.Percent);
                return false;
            }
            return true;
        case CRITERIA_DATA_TYPE_S_AURA:
        case CRITERIA_DATA_TYPE_T_AURA:
        {
            SpellInfo const* spellEntry = sSpellMgr->GetSpellInfo(Aura.SpellId, DIFFICULTY_NONE);
            if (!spellEntry)
            {
                TC_LOG_ERROR("sql.sql", "Table `criteria_data` (Entry: {} Type: {}) for data type {} ({}) contains a wrong spell id in value1 ({}), ignored.",
                    criteria->ID, criteria->Entry->Type, (DataType == CRITERIA_DATA_TYPE_S_AURA ? "CRITERIA_DATA_TYPE_S_AURA" : "CRITERIA_DATA_TYPE_T_AURA"), DataType, Aura.SpellId);
                return false;
            }
            if (spellEntry->GetEffects().size() <= Aura.EffectIndex)
            {
                TC_LOG_ERROR("sql.sql", "Table `criteria_data` (Entry: {} Type: {}) for data type {} ({}) contains a wrong spell effect index in value2 ({}), ignored.",
                    criteria->ID, criteria->Entry->Type, (DataType == CRITERIA_DATA_TYPE_S_AURA ? "CRITERIA_DATA_TYPE_S_AURA" : "CRITERIA_DATA_TYPE_T_AURA"), DataType, Aura.EffectIndex);
                return false;
            }
            if (!spellEntry->GetEffect(SpellEffIndex(Aura.EffectIndex)).ApplyAuraName)
            {
                TC_LOG_ERROR("sql.sql", "Table `criteria_data` (Entry: {} Type: {}) for data type {} ({}) contains a non-aura spell effect (ID: {} Effect: {}), ignored.",
                    criteria->ID, criteria->Entry->Type, (DataType == CRITERIA_DATA_TYPE_S_AURA ? "CRITERIA_DATA_TYPE_S_AURA" : "CRITERIA_DATA_TYPE_T_AURA"), DataType, Aura.SpellId, Aura.EffectIndex);
                return false;
            }
            return true;
        }
        case CRITERIA_DATA_TYPE_VALUE:
            if (Value.ComparisonType >= COMP_TYPE_MAX)
            {
                TC_LOG_ERROR("sql.sql", "Table `criteria_data` (Entry: {} Type: {}) for data type CRITERIA_DATA_TYPE_VALUE ({}) contains a wrong ComparisionType in value2 ({}), ignored.",
                    criteria->ID, criteria->Entry->Type, DataType, Value.ComparisonType);
                return false;
            }
            return true;
        case CRITERIA_DATA_TYPE_T_LEVEL:
            if (Level.Min > STRONG_MAX_LEVEL)
            {
                TC_LOG_ERROR("sql.sql", "Table `CRITERIA_DATA` (Entry: {} Type: {}) for data type CRITERIA_DATA_TYPE_T_LEVEL ({}) contains a wrong minlevel in value1 ({}), ignored.",
                    criteria->ID, criteria->Entry->Type, DataType, Level.Min);
                return false;
            }
            return true;
        case CRITERIA_DATA_TYPE_T_GENDER:
            if (Gender.Gender > GENDER_NONE)
            {
                TC_LOG_ERROR("sql.sql", "Table `criteria_data` (Entry: {} Type: {}) for data type CRITERIA_DATA_TYPE_T_GENDER ({}) contains a wrong gender value in value1 ({}), ignored.",
                    criteria->ID, criteria->Entry->Type, DataType, Gender.Gender);
                return false;
            }
            return true;
        case CRITERIA_DATA_TYPE_SCRIPT:
            if (!ScriptId)
            {
                TC_LOG_ERROR("sql.sql", "Table `criteria_data` (Entry: {} Type: {}) for data type CRITERIA_DATA_TYPE_SCRIPT ({}) does not have a ScriptName set, ignored.",
                    criteria->ID, criteria->Entry->Type, DataType);
                return false;
            }
            return true;
        case CRITERIA_DATA_TYPE_MAP_PLAYER_COUNT:
            if (MapPlayers.MaxCount <= 0)
            {
                TC_LOG_ERROR("sql.sql", "Table `criteria_data` (Entry: {} Type: {}) for data type CRITERIA_DATA_TYPE_MAP_PLAYER_COUNT ({}) contains a wrong max players count in value1 ({}), ignored.",
                    criteria->ID, criteria->Entry->Type, DataType, MapPlayers.MaxCount);
                return false;
            }
            return true;
        case CRITERIA_DATA_TYPE_T_TEAM:
            if (Team.Team != ALLIANCE && Team.Team != HORDE)
            {
                TC_LOG_ERROR("sql.sql", "Table `criteria_data` (Entry: {} Type: {}) for data type CRITERIA_DATA_TYPE_T_TEAM ({}) contains an unknown team value in value1 ({}), ignored.",
                    criteria->ID, criteria->Entry->Type, DataType, Team.Team);
                return false;
            }
            return true;
        case CRITERIA_DATA_TYPE_S_DRUNK:
            if (Drunk.State >= MAX_DRUNKEN)
            {
                TC_LOG_ERROR("sql.sql", "Table `criteria_data` (Entry: {} Type: {}) for data type CRITERIA_DATA_TYPE_S_DRUNK ({}) contains an unknown drunken state value in value1 ({}), ignored.",
                    criteria->ID, criteria->Entry->Type, DataType, Drunk.State);
                return false;
            }
            return true;
        case CRITERIA_DATA_TYPE_HOLIDAY:
            if (!sHolidaysStore.LookupEntry(Holiday.Id))
            {
                TC_LOG_ERROR("sql.sql", "Table `criteria_data` (Entry: {} Type: {}) for data type CRITERIA_DATA_TYPE_HOLIDAY ({}) contains an unknown holiday entry in value1 ({}), ignored.",
                    criteria->ID, criteria->Entry->Type, DataType, Holiday.Id);
                return false;
            }
            return true;
        case CRITERIA_DATA_TYPE_GAME_EVENT:
        {
            GameEventMgr::GameEventDataMap const& events = sGameEventMgr->GetEventMap();
            if (GameEvent.Id < 1 || GameEvent.Id >= events.size())
            {
                TC_LOG_ERROR("sql.sql", "Table `criteria_data` (Entry: {} Type: {}) for data type CRITERIA_DATA_TYPE_GAME_EVENT ({}) has unknown game_event in value1 ({}), ignored.",
                    criteria->ID, criteria->Entry->Type, DataType, GameEvent.Id);
                return false;
            }
            return true;
        }
        case CRITERIA_DATA_TYPE_BG_LOSS_TEAM_SCORE:
            return true;                                    // not check correctness node indexes
        case CRITERIA_DATA_TYPE_S_EQUIPPED_ITEM:
            if (EquippedItem.Quality >= MAX_ITEM_QUALITY)
            {
                TC_LOG_ERROR("sql.sql", "Table `criteria_data` (Entry: {} Type: {}) for data type CRITERIA_DATA_TYPE_S_EQUIPPED_ITEM ({}) contains an unknown quality state value in value2 ({}), ignored.",
                    criteria->ID, criteria->Entry->Type, DataType, EquippedItem.Quality);
                return false;
            }
            return true;
        case CRITERIA_DATA_TYPE_MAP_ID:
            if (!sMapStore.LookupEntry(Map.Id))
            {
                TC_LOG_ERROR("sql.sql", "Table `criteria_data` (Entry: {} Type: {}) for data type CRITERIA_DATA_TYPE_MAP_ID ({}) contains an unknown map entry in value1 ({}), ignored.",
                    criteria->ID, criteria->Entry->Type, DataType, Map.Id);
            }
            return true;
        case CRITERIA_DATA_TYPE_S_PLAYER_CLASS_RACE:
            if (!ClassRace.Class && !ClassRace.Race)
            {
                TC_LOG_ERROR("sql.sql", "Table `criteria_data` (Entry: {} Type: {}) for data type CRITERIA_DATA_TYPE_S_PLAYER_CLASS_RACE ({}) should not have 0 in either value field. Ignored.",
                    criteria->ID, criteria->Entry->Type, DataType);
                return false;
            }
            if (ClassRace.Class && ((1 << (ClassRace.Class-1)) & CLASSMASK_ALL_PLAYABLE) == 0)
            {
                TC_LOG_ERROR("sql.sql", "Table `criteria_data` (Entry: {} Type: {}) for data type CRITERIA_DATA_TYPE_S_PLAYER_CLASS_RACE ({}) contains a non-existing class entry in value1 ({}), ignored.",
                    criteria->ID, criteria->Entry->Type, DataType, ClassRace.Class);
                return false;
            }
            if (ClassRace.Race && !RACEMASK_ALL_PLAYABLE.HasRace(ClassRace.Race))
            {
                TC_LOG_ERROR("sql.sql", "Table `criteria_data` (Entry: {} Type: {}) for data type CRITERIA_DATA_TYPE_S_PLAYER_CLASS_RACE ({}) contains a non-existing race entry in value2 ({}), ignored.",
                    criteria->ID, criteria->Entry->Type, DataType, ClassRace.Race);
                return false;
            }
            return true;
        case CRITERIA_DATA_TYPE_S_KNOWN_TITLE:
            if (!sCharTitlesStore.LookupEntry(KnownTitle.Id))
            {
                TC_LOG_ERROR("sql.sql", "Table `criteria_data` (Entry: {} Type: {}) for data type CRITERIA_DATA_TYPE_S_KNOWN_TITLE ({}) contains an unknown title_id in value1 ({}), ignore.",
                    criteria->ID, criteria->Entry->Type, DataType, KnownTitle.Id);
                return false;
            }
            return true;
        case CRITERIA_DATA_TYPE_S_ITEM_QUALITY:
            if (ItemQuality.Quality >= MAX_ITEM_QUALITY)
            {
                TC_LOG_ERROR("sql.sql", "Table `criteria_data` (Entry: {} Type: {}) for data type CRITERIA_DATA_TYPE_S_ITEM_QUALITY ({}) contains an unknown quality state value in value1 ({}), ignored.",
                    criteria->ID, criteria->Entry->Type, DataType, ItemQuality.Quality);
                return false;
            }
            return true;
        default:
            TC_LOG_ERROR("sql.sql", "Table `criteria_data` (Entry: {} Type: {}) contains data of a non-supported data type ({}), ignored.", criteria->ID, criteria->Entry->Type, DataType);
            return false;
    }
}

bool CriteriaData::Meets(uint32 criteriaId, Player const* source, WorldObject const* target, uint32 miscValue1 /*= 0*/, uint32 miscValue2 /*= 0*/) const
{
    switch (DataType)
    {
        case CRITERIA_DATA_TYPE_NONE:
            return true;
        case CRITERIA_DATA_TYPE_T_CREATURE:
            if (!target || target->GetTypeId() != TYPEID_UNIT)
                return false;
            return target->GetEntry() == Creature.Id;
        case CRITERIA_DATA_TYPE_T_PLAYER_CLASS_RACE:
            if (!target || target->GetTypeId() != TYPEID_PLAYER)
                return false;
            if (ClassRace.Class && ClassRace.Class != target->ToPlayer()->GetClass())
                return false;
            if (ClassRace.Race && ClassRace.Race != target->ToPlayer()->GetRace())
                return false;
            return true;
        case CRITERIA_DATA_TYPE_S_PLAYER_CLASS_RACE:
            if (source->GetTypeId() != TYPEID_PLAYER)
                return false;
            if (ClassRace.Class && ClassRace.Class != source->ToPlayer()->GetClass())
                return false;
            if (ClassRace.Race && ClassRace.Race != source->ToPlayer()->GetRace())
                return false;
            return true;
        case CRITERIA_DATA_TYPE_T_PLAYER_LESS_HEALTH:
            if (!target || target->GetTypeId() != TYPEID_PLAYER)
                return false;
            return !target->ToPlayer()->HealthAbovePct(Health.Percent);
        case CRITERIA_DATA_TYPE_S_AURA:
            return source->HasAuraEffect(Aura.SpellId, uint8(Aura.EffectIndex));
        case CRITERIA_DATA_TYPE_T_AURA:
        {
            if (!target)
                return false;
            Unit const* unitTarget = target->ToUnit();
            if (!unitTarget)
                return false;
            return unitTarget->HasAuraEffect(Aura.SpellId, uint8(Aura.EffectIndex));
        }
        case CRITERIA_DATA_TYPE_VALUE:
            return CompareValues(ComparisionType(Value.ComparisonType), miscValue1, Value.Value);
        case CRITERIA_DATA_TYPE_T_LEVEL:
            if (!target)
                return false;
            return target->GetLevelForTarget(source) >= Level.Min;
        case CRITERIA_DATA_TYPE_T_GENDER:
        {
            if (!target)
                return false;
            Unit const* unitTarget = target->ToUnit();
            if (!unitTarget)
                return false;
            return unitTarget->GetGender() == static_cast<::Gender>(Gender.Gender);
        }
        case CRITERIA_DATA_TYPE_SCRIPT:
        {
            Unit const* unitTarget = nullptr;
            if (target)
                unitTarget = target->ToUnit();
            return sScriptMgr->OnCriteriaCheck(ScriptId, const_cast<Player*>(source), const_cast<Unit*>(unitTarget));
        }
        case CRITERIA_DATA_TYPE_MAP_PLAYER_COUNT:
            return source->GetMap()->GetPlayersCountExceptGMs() <= MapPlayers.MaxCount;
        case CRITERIA_DATA_TYPE_T_TEAM:
            if (!target || target->GetTypeId() != TYPEID_PLAYER)
                return false;
            return target->ToPlayer()->GetTeam() == ::Team(Team.Team);
        case CRITERIA_DATA_TYPE_S_DRUNK:
            return Player::GetDrunkenstateByValue(source->GetDrunkValue()) >= DrunkenState(Drunk.State);
        case CRITERIA_DATA_TYPE_HOLIDAY:
            return IsHolidayActive(HolidayIds(Holiday.Id));
        case CRITERIA_DATA_TYPE_GAME_EVENT:
            return IsEventActive(uint16(GameEvent.Id));
        case CRITERIA_DATA_TYPE_BG_LOSS_TEAM_SCORE:
        {
            Battleground* bg = source->GetBattleground();
            if (!bg)
                return false;

            uint32 score = bg->GetTeamScore(bg->GetPlayerTeam(source->GetGUID()) == ALLIANCE ? TEAM_HORDE : TEAM_ALLIANCE);
            return score >= BattlegroundScore.Min && score <= BattlegroundScore.Max;
        }
        case CRITERIA_DATA_TYPE_INSTANCE_SCRIPT:
        {
            if (!source->IsInWorld())
                return false;
            class Map* map = source->GetMap();
            if (!map->IsDungeon())
            {
                TC_LOG_ERROR("criteria", "Criteria system call CRITERIA_DATA_TYPE_INSTANCE_SCRIPT ({}) for criteria {} in a non-dungeon/non-raid map {}",
                    DataType, criteriaId, map->GetId());
                return false;
            }
            InstanceScript* instance = map->ToInstanceMap()->GetInstanceScript();
            if (!instance)
            {
                TC_LOG_ERROR("criteria", "Criteria system call CRITERIA_DATA_TYPE_INSTANCE_SCRIPT ({}) for criteria {} in map {}, but the map does not have an instance script.",
                    DataType, criteriaId, map->GetId());
                return false;
            }

            Unit const* unitTarget = nullptr;
            if (target)
                unitTarget = target->ToUnit();
            return instance->CheckAchievementCriteriaMeet(criteriaId, source, unitTarget, miscValue1);
        }
        case CRITERIA_DATA_TYPE_S_EQUIPPED_ITEM:
        {
            Criteria const* entry = ASSERT_NOTNULL(sCriteriaMgr->GetCriteria(criteriaId));

            uint32 itemId = (CriteriaType(entry->Entry->Type) == CriteriaType::EquipItemInSlot ? miscValue2 : miscValue1);
            ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(itemId);
            if (!itemTemplate)
                return false;
            return itemTemplate->GetBaseItemLevel() >= EquippedItem.ItemLevel && itemTemplate->GetQuality() >= EquippedItem.Quality;
        }
        case CRITERIA_DATA_TYPE_MAP_ID:
            return source->GetMapId() == Map.Id;
        case CRITERIA_DATA_TYPE_S_KNOWN_TITLE:
        {
            if (CharTitlesEntry const* titleInfo = sCharTitlesStore.LookupEntry(KnownTitle.Id))
                return source && source->HasTitle(titleInfo->MaskID);

            return false;
        }
        case CRITERIA_DATA_TYPE_S_ITEM_QUALITY:
        {
            ItemTemplate const* pProto = sObjectMgr->GetItemTemplate(miscValue1);
            if (!pProto)
                return false;
            return pProto->GetQuality() == ItemQuality.Quality;
        }
        default:
            break;
    }
    return false;
}

bool CriteriaDataSet::Meets(Player const* source, WorldObject const* target, uint32 miscValue1 /*= 0*/, uint32 miscValue2 /*= 0*/) const
{
    for (CriteriaData const& criteriadata : _storage)
        if (!criteriadata.Meets(_criteriaId, source, target, miscValue1, miscValue2))
            return false;

    return true;
}

CriteriaHandler::CriteriaHandler() { }

CriteriaHandler::~CriteriaHandler() { }

void CriteriaHandler::Reset()
{
    for (std::pair<uint32 const, CriteriaProgress> const& criteriaprogress : _criteriaProgress)
        SendCriteriaProgressRemoved(criteriaprogress.first);

    _criteriaProgress.clear();
}

/**
 * this function will be called whenever the user might have done a criteria relevant action
 */
void CriteriaHandler::UpdateCriteria(CriteriaType type, uint64 miscValue1 /*= 0*/, uint64 miscValue2 /*= 0*/, uint64 miscValue3 /*= 0*/, WorldObject const* ref /*= nullptr*/, Player* referencePlayer /*= nullptr*/)
{
    if (type >= CriteriaType::Count)
    {
        TC_LOG_DEBUG("criteria", "CriteriaHandler::UpdateCriteria: Wrong criteria type {}", uint32(type));
        return;
    }

    if (!referencePlayer)
    {
        TC_LOG_DEBUG("criteria", "CriteriaHandler::UpdateCriteria: Player is NULL! Cant update criteria");
        return;
    }

    // Disable for GameMasters with GM-mode enabled or for players that don't have the related RBAC permission
    if (referencePlayer->IsGameMaster() || referencePlayer->GetSession()->HasPermission(rbac::RBAC_PERM_CANNOT_EARN_ACHIEVEMENTS))
    {
        TC_LOG_DEBUG("criteria", "CriteriaHandler::UpdateCriteria: [Player {} {}] {}, {} ({}), {}, {}, {}",
            referencePlayer->GetName(), referencePlayer->IsGameMaster() ? "GM mode on" : "disallowed by RBAC",
            GetOwnerInfo(), CriteriaMgr::GetCriteriaTypeString(type), uint32(type), miscValue1, miscValue2, miscValue3);
        return;
    }

    TC_LOG_DEBUG("criteria", "CriteriaHandler::UpdateCriteria({}, {}, {}, {}, {}) {}",
        CriteriaMgr::GetCriteriaTypeString(type), uint32(type), miscValue1, miscValue2, miscValue3, GetOwnerInfo());

    CriteriaList const& criteriaList = GetCriteriaByType(type, uint32(miscValue1));
    for (Criteria const* criteria : criteriaList)
    {
        CriteriaTreeList const* trees = sCriteriaMgr->GetCriteriaTreesByCriteria(criteria->ID);
        if (!CanUpdateCriteria(criteria, trees, miscValue1, miscValue2, miscValue3, ref, referencePlayer))
            continue;

        // requirements not found in the dbc
        if (CriteriaDataSet const* data = sCriteriaMgr->GetCriteriaDataSet(criteria))
            if (!data->Meets(referencePlayer, ref, uint32(miscValue1), uint32(miscValue2)))
                continue;

        switch (type)
        {
            // std. case: increment at 1
            case CriteriaType::WinBattleground:
            case CriteriaType::TotalRespecs:
            case CriteriaType::LoseDuel:
            case CriteriaType::ItemsPostedAtAuction:
            case CriteriaType::AuctionsWon:    /* FIXME: for online player only currently */
            case CriteriaType::RollAnyNeed:
            case CriteriaType::RollAnyGreed:
            case CriteriaType::AbandonAnyQuest:
            case CriteriaType::BuyTaxi:
            case CriteriaType::AcceptSummon:
            case CriteriaType::LootAnyItem:
            case CriteriaType::ObtainAnyItem:
            case CriteriaType::DieAnywhere:
            case CriteriaType::CompleteDailyQuest:
            case CriteriaType::ParticipateInBattleground:
            case CriteriaType::DieOnMap:
            case CriteriaType::DieInInstance:
            case CriteriaType::KilledByCreature:
            case CriteriaType::KilledByPlayer:
            case CriteriaType::DieFromEnviromentalDamage:
            case CriteriaType::BeSpellTarget:
            case CriteriaType::GainAura:
            case CriteriaType::CastSpell:
            case CriteriaType::LandTargetedSpellOnTarget:
            case CriteriaType::WinAnyRankedArena:
            case CriteriaType::UseItem:
            case CriteriaType::RollNeed:
            case CriteriaType::RollGreed:
            case CriteriaType::DoEmote:
            case CriteriaType::UseGameobject:
            case CriteriaType::CatchFishInFishingHole:
            case CriteriaType::WinDuel:
            case CriteriaType::DeliverKillingBlowToClass:
            case CriteriaType::DeliverKillingBlowToRace:
            case CriteriaType::TrackedWorldStateUIModified:
            case CriteriaType::EarnHonorableKill:
            case CriteriaType::KillPlayer:
            case CriteriaType::DeliveredKillingBlow:
            case CriteriaType::PVPKillInArea:
            case CriteriaType::WinArena: // This also behaves like CriteriaType::WinAnyRankedArena
            case CriteriaType::ParticipateInArena:
            case CriteriaType::PlayerTriggerGameEvent:
            case CriteriaType::Login:
            case CriteriaType::AnyoneTriggerGameEventScenario:
            case CriteriaType::DefeatDungeonEncounterWhileElegibleForLoot:
            case CriteriaType::CompleteAnyScenario:
            case CriteriaType::CompleteScenario:
            case CriteriaType::BattlePetReachLevel:
            case CriteriaType::ActivelyEarnPetLevel:
            case CriteriaType::DefeatDungeonEncounter:
            case CriteriaType::PlaceGarrisonBuilding:
            case CriteriaType::ActivateAnyGarrisonBuilding:
            case CriteriaType::LearnAnyHeirloom:
            case CriteriaType::LearnAnyTransmog:
            case CriteriaType::HonorLevelIncrease:
            case CriteriaType::PrestigeLevelIncrease:
            case CriteriaType::LearnAnyTransmogInSlot:
            case CriteriaType::CompleteAnyReplayQuest:
            case CriteriaType::BuyItemsFromVendors:
            case CriteriaType::SellItemsToVendors:
                SetCriteriaProgress(criteria, 1, referencePlayer, PROGRESS_ACCUMULATE);
                break;
            // std case: increment at miscValue1
            case CriteriaType::MoneyEarnedFromSales:
            case CriteriaType::MoneySpentOnRespecs:
            case CriteriaType::MoneyEarnedFromQuesting:
            case CriteriaType::MoneySpentOnTaxis:
            case CriteriaType::MoneySpentAtBarberShop:
            case CriteriaType::MoneySpentOnPostage:
            case CriteriaType::MoneyLootedFromCreatures:
            case CriteriaType::MoneyEarnedFromAuctions:/* FIXME: for online player only currently */
            case CriteriaType::TotalDamageTaken:
            case CriteriaType::TotalHealReceived:
            case CriteriaType::CompletedLFGDungeon:
            case CriteriaType::CompletedLFGDungeonWithStrangers:
            case CriteriaType::DamageDealt:
            case CriteriaType::HealingDone:
            case CriteriaType::EarnArtifactXPForAzeriteItem:
            case CriteriaType::GainLevels:
            case CriteriaType::EarnArtifactXP:
                SetCriteriaProgress(criteria, miscValue1, referencePlayer, PROGRESS_ACCUMULATE);
                break;
            case CriteriaType::KillCreature:
            case CriteriaType::KillAnyCreature:
            case CriteriaType::GetLootByType:
            case CriteriaType::AcquireItem:
            case CriteriaType::LootItem:
            case CriteriaType::CurrencyGained:
                SetCriteriaProgress(criteria, miscValue2, referencePlayer, PROGRESS_ACCUMULATE);
                break;
            // std case: high value at miscValue1
            case CriteriaType::HighestAuctionBid:
            case CriteriaType::HighestAuctionSale: /* FIXME: for online player only currently */
            case CriteriaType::HighestDamageDone:
            case CriteriaType::HighestDamageTaken:
            case CriteriaType::HighestHealCast:
            case CriteriaType::HighestHealReceived:
            case CriteriaType::AnyArtifactPowerRankPurchased:
            case CriteriaType::AzeriteLevelReached:
            case CriteriaType::ReachRenownLevel:
                SetCriteriaProgress(criteria, miscValue1, referencePlayer, PROGRESS_HIGHEST);
                break;
            case CriteriaType::ReachLevel:
                SetCriteriaProgress(criteria, referencePlayer->GetLevel(), referencePlayer);
                break;
            case CriteriaType::SkillRaised:
                if (uint32 skillvalue = referencePlayer->GetBaseSkillValue(criteria->Entry->Asset.SkillID))
                    SetCriteriaProgress(criteria, skillvalue, referencePlayer);
                break;
            case CriteriaType::AchieveSkillStep:
                if (uint32 maxSkillvalue = referencePlayer->GetPureMaxSkillValue(criteria->Entry->Asset.SkillID))
                    SetCriteriaProgress(criteria, maxSkillvalue, referencePlayer);
                break;
            case CriteriaType::CompleteQuestsCount:
                SetCriteriaProgress(criteria, referencePlayer->GetRewardedQuestCount(), referencePlayer);
                break;
            case CriteriaType::CompleteAnyDailyQuestPerDay:
            {
                time_t nextDailyResetTime = sWorld->GetNextDailyQuestsResetTime();
                CriteriaProgress *progress = GetCriteriaProgress(criteria);

                if (!miscValue1) // Login case.
                {
                    // reset if player missed one day.
                    if (progress && progress->Date < (nextDailyResetTime - 2 * DAY))
                        SetCriteriaProgress(criteria, 0, referencePlayer, PROGRESS_SET);
                    continue;
                }

                ProgressType progressType;
                if (!progress)
                    // 1st time. Start count.
                    progressType = PROGRESS_SET;
                else if (progress->Date < (nextDailyResetTime - 2 * DAY))
                    // last progress is older than 2 days. Player missed 1 day => Restart count.
                    progressType = PROGRESS_SET;
                else if (progress->Date < (nextDailyResetTime - DAY))
                    // last progress is between 1 and 2 days. => 1st time of the day.
                    progressType = PROGRESS_ACCUMULATE;
                else
                    // last progress is within the day before the reset => Already counted today.
                    continue;

                SetCriteriaProgress(criteria, 1, referencePlayer, progressType);
                break;
            }
            case CriteriaType::CompleteQuestsInZone:
            {
                if (miscValue1)
                {
                    SetCriteriaProgress(criteria, 1, referencePlayer, PROGRESS_ACCUMULATE);
                }
                else // login case
                {
                    uint32 counter = 0;

                    RewardedQuestSet const& rewQuests = referencePlayer->getRewardedQuests();
                    for (uint32 rewQuest : rewQuests)
                    {
                        Quest const* quest = sObjectMgr->GetQuestTemplate(rewQuest);
                        if (quest && quest->GetZoneOrSort() >= 0 && quest->GetZoneOrSort() == criteria->Entry->Asset.ZoneID)
                            ++counter;
                    }
                    SetCriteriaProgress(criteria, counter, referencePlayer, PROGRESS_HIGHEST);
                }
                break;
            }
            case CriteriaType::MaxDistFallenWithoutDying:
                // miscValue1 is the ingame fallheight*100 as stored in dbc
                SetCriteriaProgress(criteria, miscValue1, referencePlayer);
                break;
            case CriteriaType::EarnAchievement:
            case CriteriaType::CompleteQuest:
            case CriteriaType::LearnOrKnowSpell:
            case CriteriaType::RevealWorldMapOverlay:
            case CriteriaType::GotHaircut:
            case CriteriaType::EquipItemInSlot:
            case CriteriaType::EquipItem:
            case CriteriaType::EnterAreaTriggerWithActionSet:
            case CriteriaType::LeaveAreaTriggerWithActionSet:
            case CriteriaType::LearnedNewPet:
            case CriteriaType::EnterArea:
            case CriteriaType::LeaveArea:
            case CriteriaType::RecruitGarrisonFollower:
            case CriteriaType::LearnHeirloom:
            case CriteriaType::ActivelyReachLevel:
            case CriteriaType::CollectTransmogSetFromGroup:
            case CriteriaType::EnterTopLevelArea:
            case CriteriaType::LeaveTopLevelArea:
                SetCriteriaProgress(criteria, 1, referencePlayer);
                break;
            case CriteriaType::BankSlotsPurchased:
                SetCriteriaProgress(criteria, referencePlayer->GetBankBagSlotCount(), referencePlayer);
                break;
            case CriteriaType::ReputationGained:
            {
                int32 reputation = referencePlayer->GetReputationMgr().GetReputation(criteria->Entry->Asset.FactionID);
                if (reputation > 0)
                    SetCriteriaProgress(criteria, reputation, referencePlayer);
                break;
            }
            case CriteriaType::TotalExaltedFactions:
                SetCriteriaProgress(criteria, referencePlayer->GetReputationMgr().GetExaltedFactionCount(), referencePlayer);
                break;
            case CriteriaType::LearnSpellFromSkillLine:
            case CriteriaType::LearnTradeskillSkillLine:
            {
                uint32 spellCount = 0;
                for (auto& [spellId, _] : referencePlayer->GetSpellMap())
                {
                    SkillLineAbilityMapBounds bounds = sSpellMgr->GetSkillLineAbilityMapBounds(spellId);
                    for (SkillLineAbilityMap::const_iterator skillIter = bounds.first; skillIter != bounds.second; ++skillIter)
                    {
                        if (skillIter->second->SkillLine == uint32(criteria->Entry->Asset.SkillID))
                        {
                            // do not add couter twice if by any chance skill is listed twice in dbc (eg. skill 777 and spell 22717)
                            ++spellCount;
                            break;
                        }
                    }
                }
                SetCriteriaProgress(criteria, spellCount, referencePlayer);
                break;
            }
            case CriteriaType::TotalReveredFactions:
                SetCriteriaProgress(criteria, referencePlayer->GetReputationMgr().GetReveredFactionCount(), referencePlayer);
                break;
            case CriteriaType::TotalHonoredFactions:
                SetCriteriaProgress(criteria, referencePlayer->GetReputationMgr().GetHonoredFactionCount(), referencePlayer);
                break;
            case CriteriaType::TotalFactionsEncountered:
                SetCriteriaProgress(criteria, referencePlayer->GetReputationMgr().GetVisibleFactionCount(), referencePlayer);
                break;
            case CriteriaType::HonorableKills:
                SetCriteriaProgress(criteria, referencePlayer->m_activePlayerData->LifetimeHonorableKills, referencePlayer);
                break;
            case CriteriaType::MostMoneyOwned:
                SetCriteriaProgress(criteria, referencePlayer->GetMoney(), referencePlayer, PROGRESS_HIGHEST);
                break;
            case CriteriaType::EarnAchievementPoints:
                if (!miscValue1)
                    continue;
                SetCriteriaProgress(criteria, miscValue1, referencePlayer, PROGRESS_ACCUMULATE);
                break;
            case CriteriaType::EarnPersonalArenaRating:
            {
                uint32 reqTeamType = criteria->Entry->Asset.TeamType;

                if (miscValue1)
                {
                    if (miscValue2 != reqTeamType)
                        continue;

                    SetCriteriaProgress(criteria, miscValue1, referencePlayer, PROGRESS_HIGHEST);
                }
                else // login case
                {
                    for (uint8 arena_slot = 0; arena_slot < MAX_ARENA_SLOT; ++arena_slot)
                    {
                        uint32 teamId = referencePlayer->GetArenaTeamId(arena_slot);
                        if (!teamId)
                            continue;

                        ArenaTeam* team = sArenaTeamMgr->GetArenaTeamById(teamId);
                        if (!team || team->GetType() != reqTeamType)
                            continue;

                        if (ArenaTeamMember const* member = team->GetMember(referencePlayer->GetGUID()))
                        {
                            SetCriteriaProgress(criteria, member->PersonalRating, referencePlayer, PROGRESS_HIGHEST);
                            break;
                        }
                    }
                }
                break;
            }
            case CriteriaType::UniquePetsOwned:
                SetCriteriaProgress(criteria, referencePlayer->GetSession()->GetBattlePetMgr()->GetPetUniqueSpeciesCount(), referencePlayer);
                break;
            case CriteriaType::GuildAttainedLevel:
                SetCriteriaProgress(criteria, miscValue1, referencePlayer);
                break;
            // FIXME: not triggered in code as result, need to implement
            case CriteriaType::RunInstance:
            case CriteriaType::EarnTeamArenaRating:
            case CriteriaType::EarnTitle:
            case CriteriaType::MoneySpentOnGuildRepair:
            case CriteriaType::CreatedItemsByCastingSpell:
            case CriteriaType::FishInAnyPool:
            case CriteriaType::GuildBankTabsPurchased:
            case CriteriaType::EarnGuildAchievementPoints:
            case CriteriaType::WinAnyBattleground:
            case CriteriaType::EarnBattlegroundRating:
            case CriteriaType::GuildTabardCreated:
            case CriteriaType::CompleteQuestsCountForGuild:
            case CriteriaType::HonorableKillsForGuild:
            case CriteriaType::KillAnyCreatureForGuild:
            case CriteriaType::CompleteAnyResearchProject:
            case CriteriaType::CompleteGuildChallenge:
            case CriteriaType::CompleteAnyGuildChallenge:
            case CriteriaType::CompletedLFRDungeon:
            case CriteriaType::AbandonedLFRDungeon:
            case CriteriaType::KickInitiatorInLFRDungeon:
            case CriteriaType::KickVoterInLFRDungeon:
            case CriteriaType::KickTargetInLFRDungeon:
            case CriteriaType::GroupedTankLeftEarlyInLFRDungeon:
            case CriteriaType::AccountObtainPetThroughBattle:
            case CriteriaType::WinPetBattle:
            case CriteriaType::PlayerObtainPetThroughBattle:
            case CriteriaType::ActivateGarrisonBuilding:
            case CriteriaType::UpgradeGarrison:
            case CriteriaType::StartAnyGarrisonMissionWithFollowerType:
            case CriteriaType::SucceedAnyGarrisonMissionWithFollowerType:
            case CriteriaType::SucceedGarrisonMission:
            case CriteriaType::RecruitAnyGarrisonFollower:
            case CriteriaType::LearnAnyGarrisonBlueprint:
            case CriteriaType::CollectGarrisonShipment:
            case CriteriaType::ItemLevelChangedForGarrisonFollower:
            case CriteriaType::LevelChangedForGarrisonFollower:
            case CriteriaType::LearnToy:
            case CriteriaType::LearnAnyToy:
            case CriteriaType::FindResearchObject:
            case CriteriaType::ExhaustAnyResearchSite:
            case CriteriaType::CompleteInternalCriteria:
            case CriteriaType::CompleteAnyChallengeMode:
            case CriteriaType::KilledAllUnitsInSpawnRegion:
            case CriteriaType::CompleteChallengeMode:
            case CriteriaType::CreatedItemsByCastingSpellWithLimit:
            case CriteriaType::BattlePetAchievementPointsEarned:
            case CriteriaType::ReleasedSpirit:
            case CriteriaType::AccountKnownPet:
            case CriteriaType::KickInitiatorInLFGDungeon:
            case CriteriaType::KickVoterInLFGDungeon:
            case CriteriaType::KickTargetInLFGDungeon:
            case CriteriaType::AbandonedLFGDungeon:
            case CriteriaType::GroupedTankLeftEarlyInLFGDungeon:
            case CriteriaType::StartGarrisonMission:
            case CriteriaType::QualityUpgradedForGarrisonFollower:
            case CriteriaType::CompleteResearchGarrisonTalent:
            case CriteriaType::RecruitAnyGarrisonTroop:
            case CriteriaType::CompleteAnyWorldQuest:
            case CriteriaType::ParagonLevelIncreaseWithFaction:
            case CriteriaType::PlayerHasEarnedHonor:
            case CriteriaType::ChooseRelicTalent:
            case CriteriaType::AccountHonorLevelReached:
            case CriteriaType::MythicPlusCompleted:
            case CriteriaType::SocketAnySoulbindConduit:
            case CriteriaType::ObtainAnyItemWithCurrencyValue:
            case CriteriaType::EarnExpansionLevel:
            case CriteriaType::LearnTransmog:
            default:
                break;                          // Not implemented yet :(
        }

        for (CriteriaTree const* tree : *trees)
        {
            if (IsCompletedCriteriaTree(tree))
                CompletedCriteriaTree(tree, referencePlayer);

            AfterCriteriaTreeUpdate(tree, referencePlayer);
        }
    }
}

void CriteriaHandler::UpdateTimedCriteria(Milliseconds timeDiff)
{
    for (auto itr = _startedCriteria.begin(); itr != _startedCriteria.end();)
    {
        // Time is up, remove timer and reset progress
        if (itr->second <= timeDiff)
        {
            RemoveCriteriaProgress(sCriteriaMgr->GetCriteria(itr->first));

            itr = _startedCriteria.erase(itr);
        }
        else
        {
            itr->second -= timeDiff;
            ++itr;
        }
    }
}

void CriteriaHandler::StartCriteria(CriteriaStartEvent startEvent, uint32 entry, Milliseconds timeLost /*= Milliseconds::zero()*/)
{
    CriteriaList const* criteriaList = sCriteriaMgr->GetCriteriaByStartEvent(startEvent, entry);
    if (!criteriaList)
        return;

    for (Criteria const* criteria : *criteriaList)
    {
        Milliseconds timeLimit = Milliseconds::max(); // this value is for criteria that have a start event requirement but no time limit
        if (criteria->Entry->StartTimer)
            timeLimit = Seconds(criteria->Entry->StartTimer);

        timeLimit -= timeLost;

        if (timeLimit <= Milliseconds::zero())
            continue;

        CriteriaTreeList const* trees = sCriteriaMgr->GetCriteriaTreesByCriteria(criteria->ID);
        bool canStart = std::any_of(trees->begin(), trees->end(), [&](CriteriaTree const* tree)
        {
            return !IsCompletedCriteriaTree(tree);
        });

        if (!canStart)
            continue;

        auto [itr, isNew] = _startedCriteria.try_emplace(criteria->ID, timeLimit);
        if (!isNew)
        {
            if (!criteria->Entry->GetFlags().HasFlag(CriteriaFlags::ResetOnStart))
                continue;

            itr->second = timeLimit;
        }

        // and at client too
        SetCriteriaProgress(criteria, 0, nullptr, PROGRESS_SET);
    }
}

void CriteriaHandler::FailCriteria(CriteriaFailEvent failEvent, uint32 asset)
{
    CriteriaList const* criteriaList = sCriteriaMgr->GetCriteriaByFailEvent(failEvent, asset);
    if (!criteriaList)
        return;

    for (Criteria const* criteria : *criteriaList)
    {
        _startedCriteria.erase(criteria->ID);

        CriteriaTreeList const* trees = sCriteriaMgr->GetCriteriaTreesByCriteria(criteria->ID);
        bool allTreesFullyComplete = std::all_of(trees->begin(), trees->end(), [&](CriteriaTree const* tree)
        {
            CriteriaTree const* root = tree;
            if (CriteriaTree const* parent = sCriteriaMgr->GetCriteriaTree(root->Entry->Parent))
            {
                do
                {
                    root = parent;
                    parent = sCriteriaMgr->GetCriteriaTree(root->Entry->Parent);
                } while (parent);
            }

            return IsCompletedCriteriaTree(root);
        });

        if (allTreesFullyComplete)
            continue;

        RemoveCriteriaProgress(criteria);
    }
}

CriteriaProgress* CriteriaHandler::GetCriteriaProgress(Criteria const* entry)
{
    auto iter = _criteriaProgress.find(entry->ID);
    if (iter == _criteriaProgress.end())
        return nullptr;

    return &iter->second;
}

void CriteriaHandler::SetCriteriaProgress(Criteria const* criteria, uint64 changeValue, Player* referencePlayer, ProgressType progressType)
{
    TC_LOG_DEBUG("criteria", "CriteriaHandler::SetCriteriaProgress({}, {}) for {}", criteria->ID, changeValue, GetOwnerInfo());

    CriteriaProgress* progress = GetCriteriaProgress(criteria);
    if (!progress)
    {
        // not create record for 0 counter but allow it for timed criteria
        // we will need to send 0 progress to client to start the timer
        if (changeValue == 0 && !criteria->Entry->StartTimer)
            return;

        progress = &_criteriaProgress[criteria->ID];
        progress->Counter = changeValue;
    }
    else
    {
        uint64 newValue = 0;
        switch (progressType)
        {
            case PROGRESS_SET:
                newValue = changeValue;
                break;
            case PROGRESS_ACCUMULATE:
            {
                // avoid overflow
                uint64 max_value = std::numeric_limits<uint64>::max();
                newValue = max_value - progress->Counter > changeValue ? progress->Counter + changeValue : max_value;
                break;
            }
            case PROGRESS_HIGHEST:
                newValue = progress->Counter < changeValue ? changeValue : progress->Counter;
                break;
        }

        // not update (not mark as changed) if counter will have same value
        if (progress->Counter == newValue && !criteria->Entry->StartTimer)
            return;

        progress->Counter = newValue;
    }

    progress->Changed = true;
    progress->Date = GameTime::GetGameTime(); // set the date to the latest update.
    progress->PlayerGUID = referencePlayer ? referencePlayer->GetGUID() : ObjectGuid::Empty;

    Seconds timeElapsed = Seconds::zero();

    if (criteria->Entry->StartTimer)
    {
        auto startedItr = _startedCriteria.find(criteria->ID);
        if (startedItr != _startedCriteria.end())
        {
            // Client expects this in packet
            timeElapsed = duration_cast<Seconds>(Seconds(criteria->Entry->StartTimer) - startedItr->second);

            // Remove the timer, we wont need it anymore
            CriteriaTreeList const* trees = sCriteriaMgr->GetCriteriaTreesByCriteria(criteria->ID);

            bool allTreesCompleted = std::all_of(trees->begin(), trees->end(), [&](CriteriaTree const* tree)
            {
                return IsCompletedCriteriaTree(tree);
            });

            if (allTreesCompleted)
                _startedCriteria.erase(startedItr);
        }
    }

    SendCriteriaUpdate(criteria, progress, timeElapsed, true);
}

void CriteriaHandler::RemoveCriteriaProgress(Criteria const* criteria)
{
    if (!criteria)
        return;

    auto criteriaProgress = _criteriaProgress.find(criteria->ID);
    if (criteriaProgress == _criteriaProgress.end())
        return;

    SendCriteriaProgressRemoved(criteria->ID);

    criteriaProgress->second.Counter = 0;
    criteriaProgress->second.Changed = true;
}

bool CriteriaHandler::IsCompletedCriteriaTree(CriteriaTree const* tree)
{
    if (!CanCompleteCriteriaTree(tree))
        return false;

    uint64 requiredCount = tree->Entry->Amount;
    switch (CriteriaTreeOperator(tree->Entry->Operator))
    {
        case CriteriaTreeOperator::Complete:
            return tree->Criteria && IsCompletedCriteria(tree->Criteria, requiredCount);
        case CriteriaTreeOperator::NotComplete:
            return !tree->Criteria || !IsCompletedCriteria(tree->Criteria, requiredCount);
        case CriteriaTreeOperator::CompleteAll:
            for (CriteriaTree const* node : tree->Children)
                if (!IsCompletedCriteriaTree(node))
                    return false;
            return true;
        case CriteriaTreeOperator::Sum:
        {
            uint64 progress = 0;
            CriteriaMgr::WalkCriteriaTree(tree, [this, &progress](CriteriaTree const* criteriaTree)
            {
                if (criteriaTree->Criteria)
                    if (CriteriaProgress const* criteriaProgress = GetCriteriaProgress(criteriaTree->Criteria))
                        progress += criteriaProgress->Counter;
            });
            return progress >= requiredCount;
        }
        case CriteriaTreeOperator::Highest:
        {
            uint64 progress = 0;
            CriteriaMgr::WalkCriteriaTree(tree, [this, &progress](CriteriaTree const* criteriaTree)
            {
                if (criteriaTree->Criteria)
                    if (CriteriaProgress const* criteriaProgress = GetCriteriaProgress(criteriaTree->Criteria))
                        if (criteriaProgress->Counter > progress)
                            progress = criteriaProgress->Counter;
            });
            return progress >= requiredCount;
        }
        case CriteriaTreeOperator::StartedAtLeast:
        {
            uint64 progress = 0;
            for (CriteriaTree const* node : tree->Children)
                if (node->Criteria)
                    if (CriteriaProgress const* criteriaProgress = GetCriteriaProgress(node->Criteria))
                        if (criteriaProgress->Counter >= 1)
                            if (++progress >= requiredCount)
                                return true;

            return false;
        }
        case CriteriaTreeOperator::CompleteAtLeast:
        {
            uint64 progress = 0;
            for (CriteriaTree const* node : tree->Children)
                if (IsCompletedCriteriaTree(node))
                    if (++progress >= requiredCount)
                        return true;

            return false;
        }
        case CriteriaTreeOperator::ProgressBar:
        {
            uint64 progress = 0;
            CriteriaMgr::WalkCriteriaTree(tree, [this, &progress](CriteriaTree const* criteriaTree)
            {
                if (criteriaTree->Criteria)
                    if (CriteriaProgress const* criteriaProgress = GetCriteriaProgress(criteriaTree->Criteria))
                        progress += criteriaProgress->Counter * criteriaTree->Entry->Amount;
            });
            return progress >= requiredCount;
        }
        default:
            break;
    }

    return false;
}

bool CriteriaHandler::CanUpdateCriteriaTree(Criteria const* criteria, CriteriaTree const* tree, Player* referencePlayer) const
{
    if ((tree->Entry->GetFlags().HasFlag(CriteriaTreeFlags::HordeOnly) && referencePlayer->GetTeam() != HORDE) ||
        (tree->Entry->GetFlags().HasFlag(CriteriaTreeFlags::AllianceOnly) && referencePlayer->GetTeam() != ALLIANCE))
    {
        TC_LOG_TRACE("criteria", "CriteriaHandler::CanUpdateCriteriaTree: (Id: {} Type {} CriteriaTree {}) Wrong faction",
            criteria->ID, CriteriaMgr::GetCriteriaTypeString(criteria->Entry->Type), tree->Entry->ID);
        return false;
    }

    return true;
}

bool CriteriaHandler::CanCompleteCriteriaTree(CriteriaTree const* /*tree*/)
{
    return true;
}

bool CriteriaHandler::IsCompletedCriteria(Criteria const* criteria, uint64 requiredAmount)
{
    CriteriaProgress const* progress = GetCriteriaProgress(criteria);
    if (!progress)
        return false;

    switch (CriteriaType(criteria->Entry->Type))
    {
        case CriteriaType::WinBattleground:
        case CriteriaType::KillCreature:
        case CriteriaType::ReachLevel:
        case CriteriaType::GuildAttainedLevel:
        case CriteriaType::SkillRaised:
        case CriteriaType::CompleteQuestsCount:
        case CriteriaType::CompleteAnyDailyQuestPerDay:
        case CriteriaType::CompleteQuestsInZone:
        case CriteriaType::DamageDealt:
        case CriteriaType::HealingDone:
        case CriteriaType::CompleteDailyQuest:
        case CriteriaType::MaxDistFallenWithoutDying:
        case CriteriaType::BeSpellTarget:
        case CriteriaType::GainAura:
        case CriteriaType::CastSpell:
        case CriteriaType::LandTargetedSpellOnTarget:
        case CriteriaType::TrackedWorldStateUIModified:
        case CriteriaType::PVPKillInArea:
        case CriteriaType::EarnHonorableKill:
        case CriteriaType::HonorableKills:
        case CriteriaType::AcquireItem:
        case CriteriaType::WinAnyRankedArena:
        case CriteriaType::EarnPersonalArenaRating:
        case CriteriaType::UseItem:
        case CriteriaType::LootItem:
        case CriteriaType::BankSlotsPurchased:
        case CriteriaType::ReputationGained:
        case CriteriaType::TotalExaltedFactions:
        case CriteriaType::RollNeed:
        case CriteriaType::RollGreed:
        case CriteriaType::DeliverKillingBlowToClass:
        case CriteriaType::DeliverKillingBlowToRace:
        case CriteriaType::DoEmote:
        case CriteriaType::MoneyEarnedFromQuesting:
        case CriteriaType::MoneyLootedFromCreatures:
        case CriteriaType::UseGameobject:
        case CriteriaType::KillPlayer:
        case CriteriaType::CatchFishInFishingHole:
        case CriteriaType::LearnSpellFromSkillLine:
        case CriteriaType::WinDuel:
        case CriteriaType::DefeatDungeonEncounterWhileElegibleForLoot:
        case CriteriaType::GetLootByType:
        case CriteriaType::LearnTradeskillSkillLine:
        case CriteriaType::CompletedLFGDungeon:
        case CriteriaType::CompletedLFGDungeonWithStrangers:
        case CriteriaType::DeliveredKillingBlow:
        case CriteriaType::CurrencyGained:
        case CriteriaType::CompleteAnyScenario:
        case CriteriaType::CompleteScenario:
        case CriteriaType::UniquePetsOwned:
        case CriteriaType::BattlePetReachLevel:
        case CriteriaType::ActivelyEarnPetLevel:
        case CriteriaType::DefeatDungeonEncounter:
        case CriteriaType::PlaceGarrisonBuilding:
        case CriteriaType::LearnHeirloom:
        case CriteriaType::LearnAnyHeirloom:
        case CriteriaType::EarnArtifactXP:
        case CriteriaType::AnyArtifactPowerRankPurchased:
        case CriteriaType::LearnAnyTransmogInSlot:
        case CriteriaType::ParagonLevelIncreaseWithFaction:
        case CriteriaType::PlayerHasEarnedHonor:
        case CriteriaType::ChooseRelicTalent:
        case CriteriaType::AccountHonorLevelReached:
        case CriteriaType::EarnArtifactXPForAzeriteItem:
        case CriteriaType::AzeriteLevelReached:
        case CriteriaType::CompleteAnyReplayQuest:
        case CriteriaType::BuyItemsFromVendors:
        case CriteriaType::SellItemsToVendors:
        case CriteriaType::GainLevels:
            return progress->Counter >= requiredAmount;
        case CriteriaType::EarnAchievement:
        case CriteriaType::CompleteQuest:
        case CriteriaType::LearnOrKnowSpell:
        case CriteriaType::RevealWorldMapOverlay:
        case CriteriaType::GotHaircut:
        case CriteriaType::EquipItemInSlot:
        case CriteriaType::EquipItem:
        case CriteriaType::EnterAreaTriggerWithActionSet:
        case CriteriaType::LeaveAreaTriggerWithActionSet:
        case CriteriaType::LearnedNewPet:
        case CriteriaType::EnterArea:
        case CriteriaType::LeaveArea:
        case CriteriaType::RecruitGarrisonFollower:
        case CriteriaType::HonorLevelIncrease:
        case CriteriaType::PrestigeLevelIncrease:
        case CriteriaType::ActivelyReachLevel:
        case CriteriaType::CollectTransmogSetFromGroup:
        case CriteriaType::EnterTopLevelArea:
        case CriteriaType::LeaveTopLevelArea:
            return progress->Counter >= 1;
        case CriteriaType::AchieveSkillStep:
            return progress->Counter >= (requiredAmount * 75);
        case CriteriaType::EarnAchievementPoints:
            return progress->Counter >= 9000;
        case CriteriaType::WinArena:
            return requiredAmount && progress->Counter >= requiredAmount;
        case CriteriaType::Login:
            return true;
        // handle all statistic-only criteria here
        case CriteriaType::ParticipateInBattleground:
        case CriteriaType::DieOnMap:
        case CriteriaType::DieAnywhere:
        case CriteriaType::DieInInstance:
        case CriteriaType::KilledByCreature:
        case CriteriaType::KilledByPlayer:
        case CriteriaType::DieFromEnviromentalDamage:
        case CriteriaType::ParticipateInArena:
        case CriteriaType::EarnTeamArenaRating:
        case CriteriaType::MoneyEarnedFromSales:
        case CriteriaType::MoneySpentOnRespecs:
        case CriteriaType::TotalRespecs:
        case CriteriaType::MoneySpentAtBarberShop:
        case CriteriaType::MoneySpentOnPostage:
        case CriteriaType::LoseDuel:
        case CriteriaType::KillAnyCreature:
        case CriteriaType::MoneyEarnedFromAuctions:
        case CriteriaType::ItemsPostedAtAuction:
        case CriteriaType::HighestAuctionBid:
        case CriteriaType::HighestAuctionSale:
        case CriteriaType::MostMoneyOwned:
        case CriteriaType::AuctionsWon:
        case CriteriaType::TotalReveredFactions:
        case CriteriaType::TotalHonoredFactions:
        case CriteriaType::TotalFactionsEncountered:
        case CriteriaType::LootAnyItem:
        case CriteriaType::ObtainAnyItem:
        case CriteriaType::RollAnyNeed:
        case CriteriaType::RollAnyGreed:
        case CriteriaType::AbandonAnyQuest:
        case CriteriaType::BuyTaxi:
        case CriteriaType::AcceptSummon:
        case CriteriaType::LearnAnyTransmog:
        default:
            break;
    }

    return false;
}

bool CriteriaHandler::CanUpdateCriteria(Criteria const* criteria, CriteriaTreeList const* trees, uint64 miscValue1, uint64 miscValue2, uint64 miscValue3, WorldObject const* ref, Player* referencePlayer)
{
    if (DisableMgr::IsDisabledFor(DISABLE_TYPE_CRITERIA, criteria->ID, nullptr))
    {
        TC_LOG_TRACE("criteria", "CriteriaHandler::CanUpdateCriteria: (Id: {} Type {}) Disabled", criteria->ID, CriteriaMgr::GetCriteriaTypeString(criteria->Entry->Type));
        return false;
    }

    bool treeRequirementPassed = false;
    for (CriteriaTree const* tree : *trees)
    {
        if (!CanUpdateCriteriaTree(criteria, tree, referencePlayer))
            continue;

        treeRequirementPassed = true;
        break;
    }

    if (!treeRequirementPassed)
        return false;

    if (!RequirementsSatisfied(criteria, miscValue1, miscValue2, miscValue3, ref, referencePlayer))
    {
        TC_LOG_TRACE("criteria", "CriteriaHandler::CanUpdateCriteria: (Id: {} Type {}) Requirements not satisfied", criteria->ID, CriteriaMgr::GetCriteriaTypeString(criteria->Entry->Type));
        return false;
    }

    if (criteria->Modifier && !ModifierTreeSatisfied(criteria->Modifier, miscValue1, miscValue2, ref, referencePlayer))
    {
        TC_LOG_TRACE("criteria", "CriteriaHandler::CanUpdateCriteria: (Id: {} Type {}) Requirements have not been satisfied", criteria->ID, CriteriaMgr::GetCriteriaTypeString(criteria->Entry->Type));
        return false;
    }

    if (!ConditionsSatisfied(criteria, referencePlayer))
    {
        TC_LOG_TRACE("criteria", "CriteriaHandler::CanUpdateCriteria: (Id: {} Type {}) Conditions have not been satisfied", criteria->ID, CriteriaMgr::GetCriteriaTypeString(criteria->Entry->Type));
        return false;
    }

    if (criteria->Entry->EligibilityWorldStateID != 0)
        if (sWorldStateMgr->GetValue(criteria->Entry->EligibilityWorldStateID, referencePlayer->GetMap()) != criteria->Entry->EligibilityWorldStateValue)
            return false;

    return true;
}

bool CriteriaHandler::ConditionsSatisfied(Criteria const* criteria, Player* /*referencePlayer*/) const
{
    if (criteria->Entry->StartEvent && !_startedCriteria.contains(criteria->ID))
        return false;

    return true;
}

bool CriteriaHandler::RequirementsSatisfied(Criteria const* criteria, uint64 miscValue1, uint64 miscValue2, uint64 miscValue3, WorldObject const* ref, Player* referencePlayer) const
{
    switch (CriteriaType(criteria->Entry->Type))
    {
        case CriteriaType::AcceptSummon:
        case CriteriaType::CompleteDailyQuest:
        case CriteriaType::ItemsPostedAtAuction:
        case CriteriaType::MaxDistFallenWithoutDying:
        case CriteriaType::BuyTaxi:
        case CriteriaType::DeliveredKillingBlow:
        case CriteriaType::MoneyEarnedFromAuctions:
        case CriteriaType::MoneySpentAtBarberShop:
        case CriteriaType::MoneySpentOnPostage:
        case CriteriaType::MoneySpentOnRespecs:
        case CriteriaType::MoneySpentOnTaxis:
        case CriteriaType::HighestAuctionBid:
        case CriteriaType::HighestAuctionSale:
        case CriteriaType::HighestHealReceived:
        case CriteriaType::HighestHealCast:
        case CriteriaType::HighestDamageDone:
        case CriteriaType::HighestDamageTaken:
        case CriteriaType::EarnHonorableKill:
        case CriteriaType::LootAnyItem:
        case CriteriaType::MoneyLootedFromCreatures:
        case CriteriaType::LoseDuel:
        case CriteriaType::MoneyEarnedFromQuesting:
        case CriteriaType::MoneyEarnedFromSales:
        case CriteriaType::TotalRespecs:
        case CriteriaType::ObtainAnyItem:
        case CriteriaType::AbandonAnyQuest:
        case CriteriaType::GuildAttainedLevel:
        case CriteriaType::RollAnyGreed:
        case CriteriaType::RollAnyNeed:
        case CriteriaType::KillPlayer:
        case CriteriaType::TotalDamageTaken:
        case CriteriaType::TotalHealReceived:
        case CriteriaType::CompletedLFGDungeon:
        case CriteriaType::CompletedLFGDungeonWithStrangers:
        case CriteriaType::GotHaircut:
        case CriteriaType::WinDuel:
        case CriteriaType::WinAnyRankedArena:
        case CriteriaType::AuctionsWon:
        case CriteriaType::CompleteAnyReplayQuest:
        case CriteriaType::BuyItemsFromVendors:
        case CriteriaType::SellItemsToVendors:
        case CriteriaType::GainLevels:
        case CriteriaType::LearnAnyTransmog:
        case CriteriaType::CompleteAnyScenario:
            if (!miscValue1)
                return false;
            break;
        case CriteriaType::BankSlotsPurchased:
        case CriteriaType::CompleteAnyDailyQuestPerDay:
        case CriteriaType::CompleteQuestsCount:
        case CriteriaType::EarnAchievementPoints:
        case CriteriaType::TotalExaltedFactions:
        case CriteriaType::TotalHonoredFactions:
        case CriteriaType::TotalReveredFactions:
        case CriteriaType::MostMoneyOwned:
        case CriteriaType::EarnPersonalArenaRating:
        case CriteriaType::TotalFactionsEncountered:
        case CriteriaType::ReachLevel:
        case CriteriaType::Login:
        case CriteriaType::UniquePetsOwned:
            break;
        case CriteriaType::EarnAchievement:
            if (!RequiredAchievementSatisfied(criteria->Entry->Asset.AchievementID))
                return false;
            break;
        case CriteriaType::WinBattleground:
        case CriteriaType::ParticipateInBattleground:
        case CriteriaType::DieOnMap:
            if (!miscValue1 || uint32(criteria->Entry->Asset.MapID) != referencePlayer->GetMapId())
                return false;
            break;
        case CriteriaType::KillCreature:
        case CriteriaType::KilledByCreature:
            if (!miscValue1 || uint32(criteria->Entry->Asset.CreatureID) != miscValue1)
                return false;
            break;
        case CriteriaType::SkillRaised:
        case CriteriaType::AchieveSkillStep:
            // update at loading or specific skill update
            if (miscValue1 && miscValue1 != uint32(criteria->Entry->Asset.SkillID))
                return false;
            break;
        case CriteriaType::CompleteQuestsInZone:
            if (miscValue1)
            {
                Quest const* quest = sObjectMgr->GetQuestTemplate(miscValue1);
                if (!quest ||  quest->GetZoneOrSort() != criteria->Entry->Asset.ZoneID)
                    return false;
            }
            break;
        case CriteriaType::DieAnywhere:
        {
            if (!miscValue1)
                return false;
            break;
        }
        case CriteriaType::DieInInstance:
        {
            if (!miscValue1)
                return false;

            Map const* map = referencePlayer->IsInWorld() ? referencePlayer->GetMap() : sMapMgr->FindMap(referencePlayer->GetMapId(), referencePlayer->GetInstanceId());
            if (!map || !map->IsDungeon())
                return false;

            //FIXME: work only for instances where max == min for players
            if (map->ToInstanceMap()->GetMaxPlayers() != uint32(criteria->Entry->Asset.GroupSize))
                return false;
            break;
        }
        case CriteriaType::KilledByPlayer:
            if (!miscValue1 || !ref || ref->GetTypeId() != TYPEID_PLAYER)
                return false;
            break;
        case CriteriaType::DieFromEnviromentalDamage:
            if (!miscValue1 || miscValue2 != uint32(criteria->Entry->Asset.EnviromentalDamageType))
                return false;
            break;
        case CriteriaType::CompleteQuest:
        {
            // if miscValues != 0, it contains the questID.
            if (miscValue1)
            {
                if (miscValue1 != uint32(criteria->Entry->Asset.QuestID))
                    return false;
            }
            else
            {
                // login case.
                if (!referencePlayer->GetQuestRewardStatus(criteria->Entry->Asset.QuestID))
                    return false;
            }

            if (CriteriaDataSet const* data = sCriteriaMgr->GetCriteriaDataSet(criteria))
                if (!data->Meets(referencePlayer, ref))
                    return false;
            break;
        }
        case CriteriaType::BeSpellTarget:
        case CriteriaType::GainAura:
        case CriteriaType::CastSpell:
        case CriteriaType::LandTargetedSpellOnTarget:
            if (!miscValue1 || miscValue1 != uint32(criteria->Entry->Asset.SpellID))
                return false;
            break;
        case CriteriaType::LearnOrKnowSpell:
            if (miscValue1 && miscValue1 != uint32(criteria->Entry->Asset.SpellID))
                return false;

            if (!referencePlayer->HasSpell(criteria->Entry->Asset.SpellID))
                return false;
            break;
        case CriteriaType::GetLootByType:
            // miscValue1 = itemId - miscValue2 = count of item loot
            // miscValue3 = loot_type (note: 0 = LOOT_CORPSE and then it ignored)
            if (!miscValue1 || !miscValue2 || !miscValue3 || miscValue3 != uint32(criteria->Entry->Asset.LootType))
                return false;
            break;
        case CriteriaType::AcquireItem:
            if (miscValue1 && uint32(criteria->Entry->Asset.ItemID) != miscValue1)
                return false;
            break;
        case CriteriaType::UseItem:
        case CriteriaType::LootItem:
        case CriteriaType::EquipItem:
        case CriteriaType::LearnHeirloom:
            if (!miscValue1 || uint32(criteria->Entry->Asset.ItemID )!= miscValue1)
                return false;
            break;
        case CriteriaType::RevealWorldMapOverlay:
        {
            WorldMapOverlayEntry const* worldOverlayEntry = sWorldMapOverlayStore.LookupEntry(criteria->Entry->Asset.WorldMapOverlayID);
            if (!worldOverlayEntry)
                break;

            bool matchFound = false;
            for (uint32 j : worldOverlayEntry->AreaID)
            {
                if (referencePlayer->HasExploredZone(j))
                {
                    matchFound = true;
                    break;
                }
            }

            if (!matchFound)
                return false;
            break;
        }
        case CriteriaType::ReputationGained:
            if (miscValue1 && miscValue1 != uint32(criteria->Entry->Asset.FactionID))
                return false;
            break;
        case CriteriaType::EquipItemInSlot:
        case CriteriaType::LearnAnyTransmogInSlot:
            // miscValue1 = EquipmentSlot miscValue2 = itemid | itemModifiedAppearanceId
            if (!miscValue2 || miscValue1 != uint32(criteria->Entry->Asset.EquipmentSlot))
                return false;
            break;
        case CriteriaType::RollNeed:
        case CriteriaType::RollGreed:
        {
            // miscValue1 = itemid miscValue2 = diced value
            if (!miscValue1 || miscValue2 != uint32(criteria->Entry->Asset.RollValue))
                return false;

            ItemTemplate const* proto = sObjectMgr->GetItemTemplate(uint32(miscValue1));
            if (!proto)
                return false;
            break;
        }
        case CriteriaType::DoEmote:
            if (!miscValue1 || miscValue1 != uint32(criteria->Entry->Asset.EmoteID))
                return false;
            break;
        case CriteriaType::DamageDealt:
        case CriteriaType::HealingDone:
            if (!miscValue1)
                return false;

            if (CriteriaFailEvent(criteria->Entry->FailEvent) == CriteriaFailEvent::LeaveBattleground)
            {
                if (!referencePlayer->InBattleground())
                    return false;

                // map specific case (BG in fact) expected player targeted damage/heal
                if (!ref || ref->GetTypeId() != TYPEID_PLAYER)
                    return false;
            }
            break;
        case CriteriaType::UseGameobject:
        case CriteriaType::CatchFishInFishingHole:
            if (!miscValue1 || miscValue1 != uint32(criteria->Entry->Asset.GameObjectID))
                return false;
            break;
        case CriteriaType::LearnSpellFromSkillLine:
        case CriteriaType::LearnTradeskillSkillLine:
            if (miscValue1 && miscValue1 != uint32(criteria->Entry->Asset.SkillID))
                return false;
            break;
        case CriteriaType::DeliverKillingBlowToClass:
            if (!miscValue1 || miscValue1 != uint32(criteria->Entry->Asset.ClassID))
                return false;
            break;
        case CriteriaType::DeliverKillingBlowToRace:
            if (!miscValue1 || miscValue1 != uint32(criteria->Entry->Asset.RaceID))
                return false;
            break;
        case CriteriaType::TrackedWorldStateUIModified:
            if (!miscValue1 || miscValue1 != uint32(criteria->Entry->Asset.WorldStateUIID))
                return false;
            break;
        case CriteriaType::PVPKillInArea:
        case CriteriaType::EnterArea:
            if (!miscValue1 || !DB2Manager::IsInArea(uint32(miscValue1), uint32(criteria->Entry->Asset.AreaID)))
                return false;
            break;
        case CriteriaType::LeaveArea:
            if (!miscValue1 || DB2Manager::IsInArea(uint32(miscValue1), uint32(criteria->Entry->Asset.AreaID)))
                return false;
            break;
        case CriteriaType::CurrencyGained:
            if (!miscValue1 || !miscValue2 || int64(miscValue2) < 0
                || miscValue1 != uint32(criteria->Entry->Asset.CurrencyID))
                return false;
            break;
        case CriteriaType::WinArena:
        case CriteriaType::ParticipateInArena:
            if (miscValue1 != uint32(criteria->Entry->Asset.MapID))
                return false;
            break;
        case CriteriaType::EarnTeamArenaRating:
            return false;
        case CriteriaType::DefeatDungeonEncounterWhileElegibleForLoot:
        case CriteriaType::DefeatDungeonEncounter:
            if (!miscValue1 || miscValue1 != uint32(criteria->Entry->Asset.DungeonEncounterID))
                return false;
            break;
        case CriteriaType::PlaceGarrisonBuilding:
        case CriteriaType::ActivateGarrisonBuilding:
            if (miscValue1 != uint32(criteria->Entry->Asset.GarrBuildingID))
                return false;
            break;
        case CriteriaType::RecruitGarrisonFollower:
            if (miscValue1 != uint32(criteria->Entry->Asset.GarrFollowerID))
                return false;
            break;
        case CriteriaType::CollectTransmogSetFromGroup:
            if (miscValue1 != uint32(criteria->Entry->Asset.TransmogSetGroupID))
                return false;
            break;
        case CriteriaType::BattlePetReachLevel:
        case CriteriaType::ActivelyEarnPetLevel:
            if (!miscValue1 || !miscValue2 || miscValue2 != uint32(criteria->Entry->Asset.PetLevel))
                return false;
            break;
        case CriteriaType::ActivelyReachLevel:
            if (!miscValue1 || miscValue1 != uint32(criteria->Entry->Asset.PlayerLevel))
                return false;
            break;
        case CriteriaType::EnterTopLevelArea:
        case CriteriaType::LeaveTopLevelArea:
            if (!miscValue1 || miscValue1 != uint32(criteria->Entry->Asset.ZoneID))
                return false;
            break;
        case CriteriaType::PlayerTriggerGameEvent:
        case CriteriaType::AnyoneTriggerGameEventScenario:
            if (!miscValue1 || miscValue1 != uint32(criteria->Entry->Asset.EventID))
                return false;
            break;
        case CriteriaType::CompleteScenario:
            if (miscValue1 != uint32(criteria->Entry->Asset.ScenarioID))
                return false;
            break;
        case CriteriaType::EnterAreaTriggerWithActionSet:
        case CriteriaType::LeaveAreaTriggerWithActionSet:
            if (!miscValue1 || miscValue1 != uint32(criteria->Entry->Asset.AreaTriggerActionSetID))
                return false;
            break;
        default:
            break;
    }
    return true;
}

bool CriteriaHandler::ModifierTreeSatisfied(ModifierTreeNode const* tree, uint64 miscValue1, uint64 miscValue2, WorldObject const* ref, Player* referencePlayer) const
{
    switch (ModifierTreeOperator(tree->Entry->Operator))
    {
        case ModifierTreeOperator::SingleTrue:
            return tree->Entry->Type && ModifierSatisfied(tree->Entry, miscValue1, miscValue2, ref, referencePlayer);
        case ModifierTreeOperator::SingleFalse:
            return tree->Entry->Type && !ModifierSatisfied(tree->Entry, miscValue1, miscValue2, ref, referencePlayer);
        case ModifierTreeOperator::All:
            for (ModifierTreeNode const* node : tree->Children)
                if (!ModifierTreeSatisfied(node, miscValue1, miscValue2, ref, referencePlayer))
                    return false;
            return true;
        case ModifierTreeOperator::Some:
        {
            int8 requiredAmount = std::max<int8>(tree->Entry->Amount, 1);
            for (ModifierTreeNode const* node : tree->Children)
                if (ModifierTreeSatisfied(node, miscValue1, miscValue2, ref, referencePlayer))
                    if (!--requiredAmount)
                        return true;

            return false;
        }
        default:
            break;
    }

    return false;
}

bool CriteriaHandler::ModifierSatisfied(ModifierTreeEntry const* modifier, uint64 miscValue1, uint64 miscValue2, WorldObject const* ref, Player* referencePlayer) const
{
    uint32 reqValue = modifier->Asset;
    uint32 secondaryAsset = modifier->SecondaryAsset;
    int32 tertiaryAsset = modifier->TertiaryAsset;

    switch (ModifierTreeType(modifier->Type))
    {
        case ModifierTreeType::PlayerInebriationLevelEqualOrGreaterThan: // 1
        {
            uint32 inebriation = std::min(std::max<uint32>(referencePlayer->GetDrunkValue(), *referencePlayer->m_playerData->FakeInebriation), 100u);
            if (inebriation < reqValue)
                return false;
            break;
        }
        case ModifierTreeType::PlayerMeetsCondition: // 2
        {
            if (!ConditionMgr::IsPlayerMeetingCondition(referencePlayer, reqValue))
                return false;
            break;
        }
        case ModifierTreeType::MinimumItemLevel: // 3
        {
            // miscValue1 is itemid
            ItemTemplate const* const item = sObjectMgr->GetItemTemplate(uint32(miscValue1));
            if (!item || item->GetBaseItemLevel() < reqValue)
                return false;
            break;
        }
        case ModifierTreeType::TargetCreatureId: // 4
            if (!ref || ref->GetEntry() != reqValue)
                return false;
            break;
        case ModifierTreeType::TargetIsPlayer: // 5
            if (!ref || ref->GetTypeId() != TYPEID_PLAYER)
                return false;
            break;
        case ModifierTreeType::TargetIsDead: // 6
            if (!ref || !ref->IsUnit() || ref->ToUnit()->IsAlive())
                return false;
            break;
        case ModifierTreeType::TargetIsOppositeFaction: // 7
            if (!ref || !referencePlayer->IsHostileTo(ref))
                return false;
            break;
        case ModifierTreeType::PlayerHasAura: // 8
            if (!referencePlayer->HasAura(reqValue))
                return false;
            break;
        case ModifierTreeType::PlayerHasAuraEffect: // 9
            if (!referencePlayer->HasAuraType(AuraType(reqValue)))
                return false;
            break;
        case ModifierTreeType::TargetHasAura: // 10
            if (!ref || !ref->IsUnit() || !ref->ToUnit()->HasAura(reqValue))
                return false;
            break;
        case ModifierTreeType::TargetHasAuraEffect: // 11
            if (!ref || !ref->IsUnit() || !ref->ToUnit()->HasAuraType(AuraType(reqValue)))
                return false;
            break;
        case ModifierTreeType::TargetHasAuraState: // 12
            if (!ref || !ref->IsUnit() || !ref->ToUnit()->HasAuraState(AuraStateType(reqValue)))
                return false;
            break;
        case ModifierTreeType::PlayerHasAuraState: // 13
            if (!referencePlayer->HasAuraState(AuraStateType(reqValue)))
                return false;
            break;
        case ModifierTreeType::ItemQualityIsAtLeast: // 14
        {
            // miscValue1 is itemid
            ItemTemplate const* const item = sObjectMgr->GetItemTemplate(uint32(miscValue1));
            if (!item || item->GetQuality() < reqValue)
                return false;
            break;
        }
        case ModifierTreeType::ItemQualityIsExactly: // 15
        {
            // miscValue1 is itemid
            ItemTemplate const* const item = sObjectMgr->GetItemTemplate(uint32(miscValue1));
            if (!item || item->GetQuality() != reqValue)
                return false;
            break;
        }
        case ModifierTreeType::PlayerIsAlive: // 16
            if (referencePlayer->isDead())
                return false;
            break;
        case ModifierTreeType::PlayerIsInArea: // 17
        {
            if (!DB2Manager::IsInArea(referencePlayer->GetAreaId(), reqValue))
                return false;
            break;
        }
        case ModifierTreeType::TargetIsInArea: // 18
        {
            if (!ref)
                return false;
            if (!DB2Manager::IsInArea(ref->GetAreaId(), reqValue))
                return false;
            break;
        }
        case ModifierTreeType::ItemId: // 19
            if (miscValue1 != reqValue)
                return false;
            break;
        case ModifierTreeType::LegacyDungeonDifficulty: // 20
        {
            DifficultyEntry const* difficulty = sDifficultyStore.LookupEntry(referencePlayer->GetMap()->GetDifficultyID());
            if (!difficulty || difficulty->OldEnumValue == -1 || uint32(difficulty->OldEnumValue) != reqValue)
                return false;
            break;
        }
        case ModifierTreeType::PlayerToTargetLevelDeltaGreaterThan: // 21
            if (!ref || !ref->IsUnit() || referencePlayer->GetLevel() < ref->ToUnit()->GetLevel() + reqValue)
                return false;
            break;
        case ModifierTreeType::TargetToPlayerLevelDeltaGreaterThan: // 22
            if (!ref || !ref->IsUnit() || referencePlayer->GetLevel() + reqValue < ref->ToUnit()->GetLevel())
                return false;
            break;
        case ModifierTreeType::PlayerLevelEqualTargetLevel: // 23
            if (!ref || !ref->IsUnit() || referencePlayer->GetLevel() != ref->ToUnit()->GetLevel())
                return false;
            break;
        case ModifierTreeType::PlayerInArenaWithTeamSize: // 24
        {
            Battleground* bg = referencePlayer->GetBattleground();
            if (!bg || !bg->isArena() || bg->GetArenaType() != reqValue)
                return false;
            break;
        }
        case ModifierTreeType::PlayerRace: // 25
            if (referencePlayer->GetRace() != reqValue)
                return false;
            break;
        case ModifierTreeType::PlayerClass: // 26
            if (referencePlayer->GetClass() != reqValue)
                return false;
            break;
        case ModifierTreeType::TargetRace: // 27
            if (!ref || !ref->IsUnit() || ref->ToUnit()->GetRace() != reqValue)
                return false;
            break;
        case ModifierTreeType::TargetClass: // 28
            if (!ref || !ref->IsUnit() || ref->ToUnit()->GetClass() != reqValue)
                return false;
            break;
        case ModifierTreeType::LessThanTappers: // 29
            if (referencePlayer->GetGroup() && referencePlayer->GetGroup()->GetMembersCount() >= reqValue)
                return false;
            break;
        case ModifierTreeType::CreatureType: // 30
        {
            if (!ref)
                return false;
            if (!ref->IsUnit() || ref->ToUnit()->GetCreatureType() != reqValue)
                return false;
            break;
        }
        case ModifierTreeType::CreatureFamily: // 31
        {
            if (!ref)
                return false;
            if (!ref->IsCreature() || ref->ToCreature()->GetCreatureTemplate()->family != CreatureFamily(reqValue))
                return false;
            break;
        }
        case ModifierTreeType::PlayerMap: // 32
            if (referencePlayer->GetMapId() != reqValue)
                return false;
            break;
        case ModifierTreeType::ClientVersionEqualOrLessThan: // 33
        {
            std::shared_ptr<Realm const> currentRealm = sRealmList->GetCurrentRealm();
            if (!currentRealm)
                return false;
            if (reqValue < ClientBuild::GetMinorMajorBugfixVersionForBuild(currentRealm->Build))
                return false;
            break;
        }
        case ModifierTreeType::BattlePetTeamLevel: // 34
            for (WorldPackets::BattlePet::BattlePetSlot const& slot : referencePlayer->GetSession()->GetBattlePetMgr()->GetSlots())
                if (slot.Pet.Level < reqValue)
                    return false;
            break;
        case ModifierTreeType::PlayerIsNotInParty: // 35
            if (referencePlayer->GetGroup())
                return false;
            break;
        case ModifierTreeType::PlayerIsInParty: // 36
            if (!referencePlayer->GetGroup())
                return false;
            break;
        case ModifierTreeType::HasPersonalRatingEqualOrGreaterThan: // 37
            if (referencePlayer->GetMaxPersonalArenaRatingRequirement(0) < reqValue)
                return false;
            break;
        case ModifierTreeType::HasTitle: // 38
            if (!referencePlayer->HasTitle(reqValue))
                return false;
            break;
        case ModifierTreeType::PlayerLevelEqual: // 39
            if (referencePlayer->GetLevel() != reqValue)
                return false;
            break;
        case ModifierTreeType::TargetLevelEqual: // 40
            if (!ref || ref->GetLevelForTarget(referencePlayer) != reqValue)
                return false;
            break;
        case ModifierTreeType::PlayerIsInZone: // 41
        {
            uint32 zoneId = referencePlayer->GetAreaId();
            if (AreaTableEntry const* areaEntry = sAreaTableStore.LookupEntry(zoneId))
                if (areaEntry->GetFlags().HasFlag(AreaFlags::IsSubzone))
                    zoneId = areaEntry->ParentAreaID;
            if (zoneId != reqValue)
                return false;
            break;
        }
        case ModifierTreeType::TargetIsInZone: // 42
        {
            if (!ref)
                return false;
            uint32 zoneId = ref->GetAreaId();
            if (AreaTableEntry const* areaEntry = sAreaTableStore.LookupEntry(zoneId))
                if (areaEntry->GetFlags().HasFlag(AreaFlags::IsSubzone))
                    zoneId = areaEntry->ParentAreaID;
            if (zoneId != reqValue)
                return false;
            break;
        }
        case ModifierTreeType::PlayerHealthBelowPercent: // 43
            if (referencePlayer->GetHealthPct() > float(reqValue))
                return false;
            break;
        case ModifierTreeType::PlayerHealthAbovePercent: // 44
            if (referencePlayer->GetHealthPct() < float(reqValue))
                return false;
            break;
        case ModifierTreeType::PlayerHealthEqualsPercent: // 45
            if (referencePlayer->GetHealthPct() != float(reqValue))
                return false;
            break;
        case ModifierTreeType::TargetHealthBelowPercent: // 46
            if (!ref || !ref->IsUnit() || ref->ToUnit()->GetHealthPct() > float(reqValue))
                return false;
            break;
        case ModifierTreeType::TargetHealthAbovePercent: // 47
            if (!ref || !ref->IsUnit() || ref->ToUnit()->GetHealthPct() < float(reqValue))
                return false;
            break;
        case ModifierTreeType::TargetHealthEqualsPercent: // 48
            if (!ref || !ref->IsUnit() || ref->ToUnit()->GetHealthPct() != float(reqValue))
                return false;
            break;
        case ModifierTreeType::PlayerHealthBelowValue: // 49
            if (referencePlayer->GetHealth() > reqValue)
                return false;
            break;
        case ModifierTreeType::PlayerHealthAboveValue: // 50
            if (referencePlayer->GetHealth() < reqValue)
                return false;
            break;
        case ModifierTreeType::PlayerHealthEqualsValue: // 51
            if (referencePlayer->GetHealth() != reqValue)
                return false;
            break;
        case ModifierTreeType::TargetHealthBelowValue: // 52
            if (!ref || !ref->IsUnit() || ref->ToUnit()->GetHealth() > reqValue)
                return false;
            break;
        case ModifierTreeType::TargetHealthAboveValue: // 53
            if (!ref || !ref->IsUnit() || ref->ToUnit()->GetHealth() < reqValue)
                return false;
            break;
        case ModifierTreeType::TargetHealthEqualsValue: // 54
            if (!ref || !ref->IsUnit() || ref->ToUnit()->GetHealth() != reqValue)
                return false;
            break;
        case ModifierTreeType::TargetIsPlayerAndMeetsCondition: // 55
        {
            if (!ref || !ref->IsPlayer())
                return false;

            if (!ConditionMgr::IsPlayerMeetingCondition(ref->ToPlayer(), reqValue))
                return false;
            break;
        }
        case ModifierTreeType::PlayerHasMoreThanAchievementPoints: // 56
            if (referencePlayer->GetAchievementPoints() <= reqValue)
                return false;
            break;
        case ModifierTreeType::PlayerInLfgDungeon: // 57
            if (!ConditionMgr::GetPlayerConditionLfgValue(referencePlayer, PlayerConditionLfgStatus::InLFGDungeon))
                return false;
            break;
        case ModifierTreeType::PlayerInRandomLfgDungeon: // 58
            if (!ConditionMgr::GetPlayerConditionLfgValue(referencePlayer, PlayerConditionLfgStatus::InLFGRandomDungeon))
                return false;
            break;
        case ModifierTreeType::PlayerInFirstRandomLfgDungeon: // 59
            if (!ConditionMgr::GetPlayerConditionLfgValue(referencePlayer, PlayerConditionLfgStatus::InLFGFirstRandomDungeon))
                return false;
            break;
        case ModifierTreeType::PlayerInRankedArenaMatch: // 60
        {
            Battleground const* bg = referencePlayer->GetBattleground();
            if (!bg || !bg->isArena() || !bg->isRated())
                return false;
            break;
        }
        case ModifierTreeType::PlayerInGuildParty: // 61 NYI
            return false;
        case ModifierTreeType::PlayerGuildReputationEqualOrGreaterThan: // 62
            if (referencePlayer->GetReputationMgr().GetReputation(1168) < int32(reqValue))
                return false;
            break;
        case ModifierTreeType::PlayerInRatedBattleground: // 63
        {
            Battleground const* bg = referencePlayer->GetBattleground();
            if (!bg || !bg->isBattleground() || !bg->isRated())
                return false;
            break;
        }
        case ModifierTreeType::PlayerBattlegroundRatingEqualOrGreaterThan: // 64
            if (referencePlayer->GetRBGPersonalRating() < reqValue)
                return false;
            break;
        case ModifierTreeType::ResearchProjectRarity: // 65 NYI
        case ModifierTreeType::ResearchProjectBranch: // 66 NYI
            return false;
        case ModifierTreeType::WorldStateExpression: // 67
            if (WorldStateExpressionEntry const* worldStateExpression = sWorldStateExpressionStore.LookupEntry(reqValue))
                return ConditionMgr::IsMeetingWorldStateExpression(referencePlayer->GetMap(), worldStateExpression);
            return false;
        case ModifierTreeType::DungeonDifficulty: // 68
            if (referencePlayer->GetMap()->GetDifficultyID() != reqValue)
                return false;
            break;
        case ModifierTreeType::PlayerLevelEqualOrGreaterThan: // 69
            if (referencePlayer->GetLevel() < reqValue)
                return false;
            break;
        case ModifierTreeType::TargetLevelEqualOrGreaterThan: // 70
            if (!ref || !ref->IsUnit() || ref->ToUnit()->GetLevel() < reqValue)
                return false;
            break;
        case ModifierTreeType::PlayerLevelEqualOrLessThan: // 71
            if (referencePlayer->GetLevel() > reqValue)
                return false;
            break;
        case ModifierTreeType::TargetLevelEqualOrLessThan: // 72
            if (!ref || !ref->IsUnit() || ref->ToUnit()->GetLevel() > reqValue)
                return false;
            break;
        case ModifierTreeType::ModifierTree: // 73
            if (ModifierTreeNode const* nextModifierTree = sCriteriaMgr->GetModifierTree(reqValue))
                return ModifierTreeSatisfied(nextModifierTree, miscValue1, miscValue2, ref, referencePlayer);
            return false;
        case ModifierTreeType::PlayerScenario: // 74
        {
            Scenario const* scenario = referencePlayer->GetScenario();
            if (!scenario || scenario->GetEntry()->ID != reqValue)
                return false;
            break;
        }
        case ModifierTreeType::TillersReputationGreaterThan: // 75
            if (referencePlayer->GetReputationMgr().GetReputation(1272) < int32(reqValue))
                return false;
            break;
        case ModifierTreeType::BattlePetAchievementPointsEqualOrGreaterThan: // 76
        {
            auto getRootAchievementCategory = [](AchievementEntry const* achievement)
            {
                int16 category = achievement->Category;
                do
                {
                    Achievement_CategoryEntry const* categoryEntry = sAchievementCategoryStore.LookupEntry(category);
                    if (!categoryEntry || categoryEntry->Parent == -1)
                        break;

                    category = categoryEntry->Parent;
                } while (true);

                return category;
            };

            uint32 petAchievementPoints = 0;
            for (uint32 achievementId : referencePlayer->GetCompletedAchievementIds())
            {
                AchievementEntry const* achievement = sAchievementStore.AssertEntry(achievementId);
                if (getRootAchievementCategory(achievement) == ACHIVEMENT_CATEGORY_PET_BATTLES)
                    petAchievementPoints += uint32(achievement->Points);
            }

            if (petAchievementPoints < reqValue)
                return false;
            break;
        }
        case ModifierTreeType::UniqueBattlePetsEqualOrGreaterThan: // 77
            if (referencePlayer->GetSession()->GetBattlePetMgr()->GetPetUniqueSpeciesCount() < reqValue)
                return false;
            break;
        case ModifierTreeType::BattlePetType: // 78
        {
            BattlePetSpeciesEntry const* speciesEntry = sBattlePetSpeciesStore.LookupEntry(miscValue1);
            if (!speciesEntry || speciesEntry->PetTypeEnum != int32(reqValue))
                return false;
            break;
        }
        case ModifierTreeType::BattlePetHealthPercentLessThan: // 79 NYI - use target battle pet here, the one we were just battling
            return false;
        case ModifierTreeType::GuildGroupMemberCountEqualOrGreaterThan: // 80
        {
            uint32 guildMemberCount = 0;
            if (Group const* group = referencePlayer->GetGroup())
                for (GroupReference const* itr = group->GetFirstMember(); itr != nullptr; itr = itr->next())
                    if (itr->GetSource()->GetGuildId() == referencePlayer->GetGuildId())
                        ++guildMemberCount;

            if (guildMemberCount < reqValue)
                return false;
            break;
        }
        case ModifierTreeType::BattlePetOpponentCreatureId: // 81 NYI
            return false;
        case ModifierTreeType::PlayerScenarioStep: // 82
        {
            Scenario const* scenario = referencePlayer->GetScenario();
            if (!scenario)
                return false;
            if (scenario->GetStep()->OrderIndex != (reqValue - 1))
                return false;
            break;
        }
        case ModifierTreeType::ChallengeModeMedal: // 83
            return false; // OBSOLETE
        case ModifierTreeType::PlayerOnQuest: // 84
            if (referencePlayer->FindQuestSlot(reqValue) == MAX_QUEST_LOG_SIZE)
                return false;
            break;
        case ModifierTreeType::ExaltedWithFaction: // 85
            if (referencePlayer->GetReputationMgr().GetReputation(reqValue) < 42000)
                return false;
            break;
        case ModifierTreeType::EarnedAchievementOnAccount: // 86
        case ModifierTreeType::EarnedAchievementOnPlayer: // 87
            if (!referencePlayer->HasAchieved(reqValue))
                return false;
            break;
        case ModifierTreeType::OrderOfTheCloudSerpentReputationGreaterThan: // 88
            if (referencePlayer->GetReputationMgr().GetReputation(1271) < int32(reqValue))
                return false;
            break;
        case ModifierTreeType::BattlePetQuality: // 89 NYI
        case ModifierTreeType::BattlePetFightWasPVP: // 90 NYI
            return false;
        case ModifierTreeType::BattlePetSpecies: // 91
            if (miscValue1 != reqValue)
                return false;
            break;
        case ModifierTreeType::ServerExpansionEqualOrGreaterThan: // 92
            if (sWorld->getIntConfig(CONFIG_EXPANSION) < reqValue)
                return false;
            break;
        case ModifierTreeType::PlayerHasBattlePetJournalLock: // 93
            if (!referencePlayer->GetSession()->GetBattlePetMgr()->HasJournalLock())
                return false;
            break;
        case ModifierTreeType::FriendshipRepReactionIsMet: // 94
        {
            FriendshipRepReactionEntry const* friendshipRepReaction = sFriendshipRepReactionStore.LookupEntry(reqValue);
            if (!friendshipRepReaction)
                return false;
            FriendshipReputationEntry const* friendshipReputation = sFriendshipReputationStore.LookupEntry(friendshipRepReaction->FriendshipRepID);
            if (!friendshipReputation)
                return false;
            if (referencePlayer->GetReputation(friendshipReputation->FactionID) < int32(friendshipRepReaction->ReactionThreshold))
                return false;
            break;
        }
        case ModifierTreeType::ReputationWithFactionIsEqualOrGreaterThan: // 95
            if (referencePlayer->GetReputationMgr().GetReputation(reqValue) < int32(secondaryAsset))
                return false;
            break;
        case ModifierTreeType::ItemClassAndSubclass: // 96
        {
            ItemTemplate const* item = sObjectMgr->GetItemTemplate(miscValue1);
            if (!item || item->GetClass() != reqValue || item->GetSubClass() != secondaryAsset)
                return false;
            break;
        }
        case ModifierTreeType::PlayerGender: // 97
            if (referencePlayer->GetGender() != uint8(reqValue))
                return false;
            break;
        case ModifierTreeType::PlayerNativeGender: // 98
            if (referencePlayer->GetNativeGender() != uint8(reqValue))
                return false;
            break;
        case ModifierTreeType::PlayerSkillEqualOrGreaterThan: // 99
            if (referencePlayer->GetPureSkillValue(reqValue) < uint16(secondaryAsset))
                return false;
            break;
        case ModifierTreeType::PlayerLanguageSkillEqualOrGreaterThan: // 100
        {
            auto languageDescs = sLanguageMgr->GetLanguageDescById(Language(reqValue));
            bool hasLanguageSkil = std::any_of(languageDescs.begin(), languageDescs.end(), [&](std::pair<uint32 const, LanguageDesc> const& desc)
            {
                return referencePlayer->GetSkillValue(desc.second.SkillId) >= secondaryAsset;
            });
            if (!hasLanguageSkil)
                return false;
            break;
        }
        case ModifierTreeType::PlayerIsInNormalPhase: // 101
            if (!PhasingHandler::InDbPhaseShift(referencePlayer, 0, 0, 0))
                return false;
            break;
        case ModifierTreeType::PlayerIsInPhase: // 102
            if (!PhasingHandler::InDbPhaseShift(referencePlayer, 0, reqValue, 0))
                return false;
            break;
        case ModifierTreeType::PlayerIsInPhaseGroup: // 103
            if (!PhasingHandler::InDbPhaseShift(referencePlayer, 0, 0, reqValue))
                return false;
            break;
        case ModifierTreeType::PlayerKnowsSpell: // 104
            if (!referencePlayer->HasSpell(reqValue))
                return false;
            break;
        case ModifierTreeType::PlayerHasItemQuantity: // 105
            if (referencePlayer->GetItemCount(reqValue, false) < secondaryAsset)
                return false;
            break;
        case ModifierTreeType::PlayerExpansionLevelEqualOrGreaterThan: // 106
            if (referencePlayer->GetSession()->GetExpansion() < reqValue)
                return false;
            break;
        case ModifierTreeType::PlayerHasAuraWithLabel: // 107
            if (!referencePlayer->HasAura([labelId = reqValue](Aura const* aura) { return aura->GetSpellInfo()->HasLabel(labelId); }))
                return false;
            break;
        case ModifierTreeType::PlayersRealmWorldState: // 108
            if (sWorldStateMgr->GetValue(reqValue, referencePlayer->GetMap()) != int32(secondaryAsset))
                return false;
            break;
        case ModifierTreeType::TimeBetween: // 109
        {
            WowTime from;
            from.SetPackedTime(reqValue);
            WowTime to;
            to.SetPackedTime(secondaryAsset);

            if (!GameTime::GetWowTime()->IsInRange(from, to))
                return false;
            break;
        }
        case ModifierTreeType::PlayerHasCompletedQuest: // 110
            if (uint32 questBit = sDB2Manager.GetQuestUniqueBitFlag(reqValue))
                if (!(referencePlayer->m_activePlayerData->QuestCompleted[((questBit - 1) >> 6)] & (UI64LIT(1) << ((questBit - 1) & 63))))
                    return false;
            break;
        case ModifierTreeType::PlayerIsReadyToTurnInQuest: // 111
            if (referencePlayer->GetQuestStatus(reqValue) != QUEST_STATUS_COMPLETE)
                return false;
            break;
        case ModifierTreeType::PlayerHasCompletedQuestObjective: // 112
        {
            QuestObjective const* objective = sObjectMgr->GetQuestObjective(reqValue);
            if (!objective)
                return false;
            Quest const* quest = sObjectMgr->GetQuestTemplate(objective->QuestID);
            if (!quest)
                return false;
            uint16 slot = referencePlayer->FindQuestSlot(objective->QuestID);
            if (slot >= MAX_QUEST_LOG_SIZE || referencePlayer->GetQuestRewardStatus(objective->QuestID) || !referencePlayer->IsQuestObjectiveComplete(slot, quest, *objective))
                return false;
            break;
        }
        case ModifierTreeType::PlayerHasExploredArea: // 113
        {
            if (!referencePlayer->HasExploredZone(reqValue))
                return false;
            break;
        }
        case ModifierTreeType::PlayerHasItemQuantityIncludingBank: // 114
            if (referencePlayer->GetItemCount(reqValue, true) < secondaryAsset)
                return false;
            break;
        case ModifierTreeType::Weather: // 115
            if (referencePlayer->GetMap()->GetZoneWeather(referencePlayer->GetZoneId()) != WeatherState(reqValue))
                return false;
            break;
        case ModifierTreeType::PlayerFaction: // 116
        {
            ChrRacesEntry const* race = sChrRacesStore.LookupEntry(referencePlayer->GetRace());
            if (!race)
                return false;
            FactionTemplateEntry const* faction = sFactionTemplateStore.LookupEntry(race->FactionID);
            if (!faction)
                return false;
            int32 factionIndex = -1;
            if (faction->FactionGroup & FACTION_MASK_HORDE)
                factionIndex = 0;
            else if (faction->FactionGroup & FACTION_MASK_ALLIANCE)
                factionIndex = 1;
            else if (faction->FactionGroup & FACTION_MASK_PLAYER)
                factionIndex = 0;
            if (factionIndex != int32(reqValue))
                return false;
            break;
        }
        case ModifierTreeType::LfgStatusEqual: // 117
            if (ConditionMgr::GetPlayerConditionLfgValue(referencePlayer, PlayerConditionLfgStatus(reqValue)) != secondaryAsset)
                return false;
            break;
        case ModifierTreeType::LFgStatusEqualOrGreaterThan: // 118
            if (ConditionMgr::GetPlayerConditionLfgValue(referencePlayer, PlayerConditionLfgStatus(reqValue)) < secondaryAsset)
                return false;
            break;
        case ModifierTreeType::PlayerHasCurrencyEqualOrGreaterThan: // 119
            if (!referencePlayer->HasCurrency(reqValue, secondaryAsset))
                return false;
            break;
        case ModifierTreeType::TargetThreatListSizeLessThan: // 120
        {
            if (!ref)
                return false;
            Unit const* unitRef = ref->ToUnit();
            if (!unitRef || !unitRef->CanHaveThreatList())
                return false;
            if (unitRef->GetThreatManager().GetThreatListSize() >= reqValue)
                return false;
            break;
        }
        case ModifierTreeType::PlayerHasTrackedCurrencyEqualOrGreaterThan: // 121
            if (referencePlayer->GetCurrencyTrackedQuantity(reqValue) < secondaryAsset)
                return false;
            break;
        case ModifierTreeType::PlayerMapInstanceType: // 122
            if (referencePlayer->GetMap()->GetEntry()->InstanceType != int8(reqValue))
                return false;
            break;
        case ModifierTreeType::PlayerInTimeWalkerInstance: // 123
            if (!referencePlayer->HasPlayerFlag(PLAYER_FLAGS_TIMEWALKING))
                return false;
            break;
        case ModifierTreeType::PvpSeasonIsActive: // 124
            if (!sWorld->getBoolConfig(CONFIG_ARENA_SEASON_IN_PROGRESS))
                return false;
            break;
        case ModifierTreeType::PvpSeason: // 125
            if (sWorld->getIntConfig(CONFIG_ARENA_SEASON_ID) != reqValue)
                return false;
            break;
        case ModifierTreeType::GarrisonTierEqualOrGreaterThan: // 126
        {
            Garrison const* garrison = referencePlayer->GetGarrison();
            if (!garrison || garrison->GetType() != GarrisonType(secondaryAsset) || garrison->GetSiteLevel()->GarrLevel < reqValue)
                return false;
            break;
        }
        case ModifierTreeType::GarrisonFollowersWithLevelEqualOrGreaterThan: // 127
        {
            Garrison const* garrison = referencePlayer->GetGarrison();
            if (!garrison)
                return false;
            uint32 followerCount = garrison->CountFollowers([secondaryAsset, tertiaryAsset](Garrison::Follower const& follower)
            {
                GarrFollowerEntry const* garrFollower = sGarrFollowerStore.AssertEntry(follower.PacketInfo.GarrFollowerID);
                return garrFollower->GarrFollowerTypeID == tertiaryAsset && follower.PacketInfo.FollowerLevel >= secondaryAsset;
            });
            if (followerCount < reqValue)
                return false;
            break;
        }
        case ModifierTreeType::GarrisonFollowersWithQualityEqualOrGreaterThan: // 128
        {
            Garrison const* garrison = referencePlayer->GetGarrison();
            if (!garrison)
                return false;
            uint32 followerCount = garrison->CountFollowers([secondaryAsset, tertiaryAsset](Garrison::Follower const& follower)
            {
                GarrFollowerEntry const* garrFollower = sGarrFollowerStore.AssertEntry(follower.PacketInfo.GarrFollowerID);
                return garrFollower->GarrFollowerTypeID == tertiaryAsset && follower.PacketInfo.Quality >= secondaryAsset;
            });
            if (followerCount < reqValue)
                return false;
            break;
        }
        case ModifierTreeType::GarrisonFollowerWithAbilityAtLevelEqualOrGreaterThan: // 129
        {
            Garrison const* garrison = referencePlayer->GetGarrison();
            if (!garrison)
                return false;
            uint32 followerCount = garrison->CountFollowers([reqValue, secondaryAsset, tertiaryAsset](Garrison::Follower const& follower)
            {
                GarrFollowerEntry const* garrFollower = sGarrFollowerStore.AssertEntry(follower.PacketInfo.GarrFollowerID);
                return garrFollower->GarrFollowerTypeID == tertiaryAsset && follower.PacketInfo.FollowerLevel >= reqValue && follower.HasAbility(secondaryAsset);
            });
            if (followerCount < 1)
                return false;
            break;
        }
        case ModifierTreeType::GarrisonFollowerWithTraitAtLevelEqualOrGreaterThan: // 130
        {
            Garrison const* garrison = referencePlayer->GetGarrison();
            if (!garrison)
                return false;
            GarrAbilityEntry const* traitEntry = sGarrAbilityStore.LookupEntry(secondaryAsset);
            if (!traitEntry || !(traitEntry->Flags & GARRISON_ABILITY_FLAG_TRAIT))
                return false;
            uint32 followerCount = garrison->CountFollowers([reqValue, secondaryAsset, tertiaryAsset](Garrison::Follower const& follower)
            {
                GarrFollowerEntry const* garrFollower = sGarrFollowerStore.AssertEntry(follower.PacketInfo.GarrFollowerID);
                return garrFollower->GarrFollowerTypeID == tertiaryAsset && follower.PacketInfo.FollowerLevel >= reqValue && follower.HasAbility(secondaryAsset);
            });
            if (followerCount < 1)
                return false;
            break;
        }
        case ModifierTreeType::GarrisonFollowerWithAbilityAssignedToBuilding: // 131
        {
            Garrison const* garrison = referencePlayer->GetGarrison();
            if (!garrison || garrison->GetType() != GarrisonType(tertiaryAsset))
                return false;
            uint32 followerCount = garrison->CountFollowers([reqValue, secondaryAsset](Garrison::Follower const& follower)
            {
                GarrBuildingEntry const* followerBuilding = sGarrBuildingStore.LookupEntry(follower.PacketInfo.CurrentBuildingID);
                if (!followerBuilding)
                    return false;
                return followerBuilding->BuildingType == secondaryAsset && follower.HasAbility(reqValue);;
            });
            if (followerCount < 1)
                return false;
            break;
        }
        case ModifierTreeType::GarrisonFollowerWithTraitAssignedToBuilding: // 132
        {
            Garrison const* garrison = referencePlayer->GetGarrison();
            if (!garrison || garrison->GetType() != GarrisonType(tertiaryAsset))
                return false;
            GarrAbilityEntry const* traitEntry = sGarrAbilityStore.LookupEntry(reqValue);
            if (!traitEntry || !(traitEntry->Flags & GARRISON_ABILITY_FLAG_TRAIT))
                return false;
            uint32 followerCount = garrison->CountFollowers([reqValue, secondaryAsset](Garrison::Follower const& follower)
            {
                GarrBuildingEntry const* followerBuilding = sGarrBuildingStore.LookupEntry(follower.PacketInfo.CurrentBuildingID);
                if (!followerBuilding)
                    return false;
                return followerBuilding->BuildingType == secondaryAsset && follower.HasAbility(reqValue);;
            });
            if (followerCount < 1)
                return false;
            break;
        }
        case ModifierTreeType::GarrisonFollowerWithLevelAssignedToBuilding: // 133
        {
            Garrison const* garrison = referencePlayer->GetGarrison();
            if (!garrison || garrison->GetType() != GarrisonType(tertiaryAsset))
                return false;
            uint32 followerCount = garrison->CountFollowers([reqValue, secondaryAsset](Garrison::Follower const& follower)
            {
                if (follower.PacketInfo.FollowerLevel < reqValue)
                    return false;
                GarrBuildingEntry const* followerBuilding = sGarrBuildingStore.LookupEntry(follower.PacketInfo.CurrentBuildingID);
                if (!followerBuilding)
                    return false;
                return followerBuilding->BuildingType == secondaryAsset;
            });
            if (followerCount < 1)
                return false;
            break;
        }
        case ModifierTreeType::GarrisonBuildingWithLevelEqualOrGreaterThan: // 134
        {
            Garrison* garrison = referencePlayer->GetGarrison();
            if (!garrison || garrison->GetType() != GarrisonType(tertiaryAsset))
                return false;
            for (Garrison::Plot const* plot : garrison->GetPlots())
            {
                if (!plot->BuildingInfo.PacketInfo)
                    continue;

                GarrBuildingEntry const* building = sGarrBuildingStore.LookupEntry(plot->BuildingInfo.PacketInfo->GarrBuildingID);
                if (!building || building->UpgradeLevel < reqValue || building->BuildingType != secondaryAsset)
                    continue;

                return true;
            }
            return false;
        }
        case ModifierTreeType::HasBlueprintForGarrisonBuilding: // 135
        {
            Garrison const* garrison = referencePlayer->GetGarrison();
            if (!garrison || garrison->GetType() != GarrisonType(secondaryAsset))
                return false;
            if (!garrison->HasBlueprint(reqValue))
                return false;
            break;
        }
        case ModifierTreeType::HasGarrisonBuildingSpecialization: // 136
            return false; // OBSOLETE
        case ModifierTreeType::AllGarrisonPlotsAreFull: // 137
        {
            Garrison* garrison = referencePlayer->GetGarrison();
            if (!garrison || garrison->GetType() != GarrisonType(reqValue))
                return false;
            for (Garrison::Plot const* plot : garrison->GetPlots())
                if (!plot->BuildingInfo.PacketInfo)
                    return false;
            break;
        }
        case ModifierTreeType::PlayerIsInOwnGarrison: // 138
            if (!referencePlayer->GetMap()->IsGarrison() || referencePlayer->GetMap()->GetInstanceId() != referencePlayer->GetGUID().GetCounter())
                return false;
            break;
        case ModifierTreeType::GarrisonShipmentOfTypeIsPending: // 139 NYI
            return false;
        case ModifierTreeType::GarrisonBuildingIsUnderConstruction: // 140
        {
            GarrBuildingEntry const* building = sGarrBuildingStore.LookupEntry(reqValue);
            if (!building)
                return false;
            Garrison* garrison = referencePlayer->GetGarrison();
            if (!garrison || garrison->GetType() != GarrisonType(tertiaryAsset))
                return false;
            for (Garrison::Plot const* plot : garrison->GetPlots())
            {
                if (!plot->BuildingInfo.PacketInfo || plot->BuildingInfo.PacketInfo->GarrBuildingID != reqValue)
                    continue;

                return !plot->BuildingInfo.PacketInfo->Active;
            }
            return false;
        }
        case ModifierTreeType::GarrisonMissionHasBeenCompleted: // 141 NYI
            return false;
        case ModifierTreeType::GarrisonBuildingLevelEqual: // 142
        {
            Garrison* garrison = referencePlayer->GetGarrison();
            if (!garrison || garrison->GetType() != GarrisonType(tertiaryAsset))
                return false;
            for (Garrison::Plot const* plot : garrison->GetPlots())
            {
                if (!plot->BuildingInfo.PacketInfo)
                    continue;

                GarrBuildingEntry const* building = sGarrBuildingStore.LookupEntry(plot->BuildingInfo.PacketInfo->GarrBuildingID);
                if (!building || building->UpgradeLevel != secondaryAsset || building->BuildingType != reqValue)
                    continue;

                return true;
            }
            return false;
        }
        case ModifierTreeType::GarrisonFollowerHasAbility: // 143
        {
            Garrison const* garrison = referencePlayer->GetGarrison();
            if (!garrison || garrison->GetType() != GarrisonType(secondaryAsset))
                return false;
            if (miscValue1)
            {
                Garrison::Follower const* follower = garrison->GetFollower(miscValue1);
                if (!follower)
                    return false;
                if (!follower->HasAbility(reqValue))
                    return false;
            }
            else
            {
                uint32 followerCount = garrison->CountFollowers([reqValue](Garrison::Follower const& follower)
                {
                    return follower.HasAbility(reqValue);
                });
                if (followerCount < 1)
                    return false;
            }
            break;
        }
        case ModifierTreeType::GarrisonFollowerHasTrait: // 144
        {
            GarrAbilityEntry const* traitEntry = sGarrAbilityStore.LookupEntry(reqValue);
            if (!traitEntry || !(traitEntry->Flags & GARRISON_ABILITY_FLAG_TRAIT))
                return false;
            Garrison const* garrison = referencePlayer->GetGarrison();
            if (!garrison || garrison->GetType() != GarrisonType(secondaryAsset))
                return false;
            if (miscValue1)
            {
                Garrison::Follower const* follower = garrison->GetFollower(miscValue1);
                if (!follower || !follower->HasAbility(reqValue))
                    return false;
            }
            else
            {
                uint32 followerCount = garrison->CountFollowers([reqValue](Garrison::Follower const& follower)
                {
                    return follower.HasAbility(reqValue);
                });
                if (followerCount < 1)
                    return false;
            }
            break;
        }
        case ModifierTreeType::GarrisonFollowerQualityEqual: // 145
        {
            Garrison const* garrison = referencePlayer->GetGarrison();
            if (!garrison || garrison->GetType() != GARRISON_TYPE_GARRISON)
                return false;
            if (miscValue1)
            {
                Garrison::Follower const* follower = garrison->GetFollower(miscValue1);
                if (!follower || follower->PacketInfo.Quality < reqValue)
                    return false;
            }
            else
            {
                uint32 followerCount = garrison->CountFollowers([reqValue](Garrison::Follower const& follower)
                {
                    return follower.PacketInfo.Quality >= reqValue;
                });
                if (followerCount < 1)
                    return false;
            }
            break;
        }
        case ModifierTreeType::GarrisonFollowerLevelEqual: // 146
        {
            Garrison const* garrison = referencePlayer->GetGarrison();
            if (!garrison || garrison->GetType() != GarrisonType(secondaryAsset))
                return false;
            if (miscValue1)
            {
                Garrison::Follower const* follower = garrison->GetFollower(miscValue1);
                if (!follower || follower->PacketInfo.FollowerLevel != reqValue)
                    return false;
            }
            else
            {
                uint32 followerCount = garrison->CountFollowers([reqValue](Garrison::Follower const& follower)
                {
                    return follower.PacketInfo.FollowerLevel == reqValue;
                });
                if (followerCount < 1)
                    return false;
            }
            break;
        }
        case ModifierTreeType::GarrisonMissionIsRare: // 147 NYI
        case ModifierTreeType::GarrisonMissionIsElite: // 148 NYI
            return false;
        case ModifierTreeType::CurrentGarrisonBuildingLevelEqual: // 149
        {
            if (!miscValue1)
                return false;
            Garrison* garrison = referencePlayer->GetGarrison();
            if (!garrison)
                return false;
            for (Garrison::Plot const* plot : garrison->GetPlots())
            {
                if (!plot->BuildingInfo.PacketInfo || plot->BuildingInfo.PacketInfo->GarrBuildingID != miscValue1)
                    continue;

                GarrBuildingEntry const* building = sGarrBuildingStore.LookupEntry(plot->BuildingInfo.PacketInfo->GarrBuildingID);
                if (!building || building->UpgradeLevel != reqValue)
                    continue;

                return true;
            }
            break;
        }
        case ModifierTreeType::GarrisonPlotInstanceHasBuildingThatIsReadyToActivate: // 150
        {
            Garrison* garrison = referencePlayer->GetGarrison();
            if (!garrison)
                return false;
            Garrison::Plot const* plot = garrison->GetPlot(reqValue);
            if (!plot)
                return false;
            if (!plot->BuildingInfo.CanActivate() || !plot->BuildingInfo.PacketInfo || plot->BuildingInfo.PacketInfo->Active)
                return false;
            break;
        }
        case ModifierTreeType::BattlePetTeamWithSpeciesEqualOrGreaterThan: // 151
        {
            uint32 count = 0;
            for (WorldPackets::BattlePet::BattlePetSlot const& slot : referencePlayer->GetSession()->GetBattlePetMgr()->GetSlots())
                if (slot.Pet.Species == secondaryAsset)
                    ++count;
            if (count < reqValue)
                return false;
            break;
        }
        case ModifierTreeType::BattlePetTeamWithTypeEqualOrGreaterThan: // 152
        {
            uint32 count = 0;
            for (WorldPackets::BattlePet::BattlePetSlot const& slot : referencePlayer->GetSession()->GetBattlePetMgr()->GetSlots())
                if (BattlePetSpeciesEntry const* species = sBattlePetSpeciesStore.LookupEntry(slot.Pet.Species))
                    if (species->PetTypeEnum == int32(secondaryAsset))
                        ++count;
            if (count < reqValue)
                return false;
            break;
        }
        case ModifierTreeType::PetBattleLastAbility: // 153 NYI
        case ModifierTreeType::PetBattleLastAbilityType: // 154 NYI
            return false;
        case ModifierTreeType::BattlePetTeamWithAliveEqualOrGreaterThan: // 155
        {
            uint32 count = 0;
            for (WorldPackets::BattlePet::BattlePetSlot const& slot : referencePlayer->GetSession()->GetBattlePetMgr()->GetSlots())
                if (slot.Pet.Health > 0)
                    ++count;
            if (count < reqValue)
                return false;
            break;
        }
        case ModifierTreeType::HasGarrisonBuildingActiveSpecialization: // 156
            return false; // OBSOLETE
        case ModifierTreeType::HasGarrisonFollower: // 157
        {
            Garrison const* garrison = referencePlayer->GetGarrison();
            if (!garrison)
                return false;
            uint32 followerCount = garrison->CountFollowers([reqValue](Garrison::Follower const& follower)
            {
                return follower.PacketInfo.GarrFollowerID == reqValue;
            });
            if (followerCount < 1)
                return false;
            break;
        }
        case ModifierTreeType::PlayerQuestObjectiveProgressEqual: // 158
        {
            QuestObjective const* objective = sObjectMgr->GetQuestObjective(reqValue);
            if (!objective)
                return false;
            if (referencePlayer->GetQuestObjectiveData(*objective) != int32(secondaryAsset))
                return false;
            break;
        }
        case ModifierTreeType::PlayerQuestObjectiveProgressEqualOrGreaterThan: // 159
        {
            QuestObjective const* objective = sObjectMgr->GetQuestObjective(reqValue);
            if (!objective)
                return false;
            if (referencePlayer->GetQuestObjectiveData(*objective) < int32(secondaryAsset))
                return false;
            break;
        }
        case ModifierTreeType::IsPTRRealm: // 160
        case ModifierTreeType::IsBetaRealm: // 161
        case ModifierTreeType::IsQARealm: // 162
            return false; // always false
        case ModifierTreeType::GarrisonShipmentContainerIsFull: // 163
            return false;
        case ModifierTreeType::PlayerCountIsValidToStartGarrisonInvasion: // 164
            return true; // Only 1 player is required and referencePlayer->GetMap() will ALWAYS have at least the referencePlayer on it
        case ModifierTreeType::InstancePlayerCountEqualOrLessThan: // 165
            if (referencePlayer->GetMap()->GetPlayersCountExceptGMs() > reqValue)
                return false;
            break;
        case ModifierTreeType::AllGarrisonPlotsFilledWithBuildingsWithLevelEqualOrGreater: // 166
        {
            Garrison* garrison = referencePlayer->GetGarrison();
            if (!garrison || garrison->GetType() != GarrisonType(reqValue))
                return false;
            for (Garrison::Plot const* plot : garrison->GetPlots())
            {
                if (!plot->BuildingInfo.PacketInfo)
                    return false;
                GarrBuildingEntry const* building = sGarrBuildingStore.LookupEntry(plot->BuildingInfo.PacketInfo->GarrBuildingID);
                if (!building || building->UpgradeLevel != reqValue)
                    return false;
            }
            break;
        }
        case ModifierTreeType::GarrisonMissionType: // 167 NYI
            return false;
        case ModifierTreeType::GarrisonFollowerItemLevelEqualOrGreaterThan: // 168
        {
            if (!miscValue1)
                return false;
            Garrison const* garrison = referencePlayer->GetGarrison();
            if (!garrison)
                return false;
            uint32 followerCount = garrison->CountFollowers([miscValue1, reqValue](Garrison::Follower const& follower)
            {
                return follower.PacketInfo.GarrFollowerID == miscValue1 && follower.GetItemLevel() >= reqValue;
            });
            if (followerCount < 1)
                return false;
            break;
        }
        case ModifierTreeType::GarrisonFollowerCountWithItemLevelEqualOrGreaterThan: // 169
        {
            Garrison const* garrison = referencePlayer->GetGarrison();
            if (!garrison)
                return false;
            uint32 followerCount = garrison->CountFollowers([secondaryAsset, tertiaryAsset](Garrison::Follower const& follower)
            {
                GarrFollowerEntry const* garrFollower = sGarrFollowerStore.AssertEntry(follower.PacketInfo.GarrFollowerID);
                return garrFollower->GarrFollowerTypeID == tertiaryAsset && follower.GetItemLevel() >= secondaryAsset;
            });
            if (followerCount < reqValue)
                return false;
            break;
        }
        case ModifierTreeType::GarrisonTierEqual: // 170
        {
            Garrison const* garrison = referencePlayer->GetGarrison();
            if (!garrison || garrison->GetType() != GarrisonType(secondaryAsset) || garrison->GetSiteLevel()->GarrLevel != reqValue)
                return false;
            break;
        }
        case ModifierTreeType::InstancePlayerCountEqual: // 171
            if (referencePlayer->GetMap()->GetPlayers().getSize() != reqValue)
                return false;
            break;
        case ModifierTreeType::CurrencyId: // 172
            if (miscValue1 != reqValue)
                return false;
            break;
        case ModifierTreeType::SelectionIsPlayerCorpse: // 173
            if (referencePlayer->GetTarget().GetHigh() != HighGuid::Corpse)
                return false;
            break;
        case ModifierTreeType::PlayerCanAcceptQuest: // 174
        {
            Quest const* quest = sObjectMgr->GetQuestTemplate(reqValue);
            if (!quest)
                return false;
            if (!referencePlayer->CanTakeQuest(quest, false))
                return false;
            break;
        }
        case ModifierTreeType::GarrisonFollowerCountWithLevelEqualOrGreaterThan: // 175
        {
            Garrison const* garrison = referencePlayer->GetGarrison();
            if (!garrison || garrison->GetType() != GarrisonType(tertiaryAsset))
                return false;
            uint32 followerCount = garrison->CountFollowers([secondaryAsset, tertiaryAsset](Garrison::Follower const& follower)
            {
                GarrFollowerEntry const* garrFollower = sGarrFollowerStore.AssertEntry(follower.PacketInfo.GarrFollowerID);
                return garrFollower->GarrFollowerTypeID == tertiaryAsset && follower.PacketInfo.FollowerLevel == secondaryAsset;
            });
            if (followerCount < reqValue)
                return false;
            break;
        }
        case ModifierTreeType::GarrisonFollowerIsInBuilding: // 176
        {
            Garrison const* garrison = referencePlayer->GetGarrison();
            if (!garrison)
                return false;
            uint32 followerCount = garrison->CountFollowers([reqValue, secondaryAsset](Garrison::Follower const& follower)
            {
                return follower.PacketInfo.GarrFollowerID == reqValue && follower.PacketInfo.CurrentBuildingID == secondaryAsset;
            });
            if (followerCount < 1)
                return false;
            break;
        }
        case ModifierTreeType::GarrisonMissionCountLessThan: // 177 NYI
            return false;
        case ModifierTreeType::GarrisonPlotInstanceCountEqualOrGreaterThan: // 178
        {
            Garrison* garrison = referencePlayer->GetGarrison();
            if (!garrison || garrison->GetType() != GarrisonType(reqValue))
                return false;
            uint32 plotCount = 0;
            for (Garrison::Plot const* plot : garrison->GetPlots())
            {
                GarrPlotInstanceEntry const* garrPlotInstance = sGarrPlotInstanceStore.LookupEntry(plot->PacketInfo.GarrPlotInstanceID);
                if (!garrPlotInstance || garrPlotInstance->GarrPlotID != secondaryAsset)
                    continue;
                ++plotCount;
            }
            if (plotCount < reqValue)
                return false;
            break;
        }
        case ModifierTreeType::CurrencySource: // 179 NYI
            return false;
        case ModifierTreeType::PlayerIsInNotOwnGarrison: // 180
            if (!referencePlayer->GetMap()->IsGarrison() || referencePlayer->GetMap()->GetInstanceId() == referencePlayer->GetGUID().GetCounter())
                return false;
            break;
        case ModifierTreeType::HasActiveGarrisonFollower: // 181
        {
            Garrison const* garrison = referencePlayer->GetGarrison();
            if (!garrison)
                return false;
            uint32 followerCount = garrison->CountFollowers([reqValue](Garrison::Follower const& follower)
            {
                return follower.PacketInfo.GarrFollowerID == reqValue && !(follower.PacketInfo.FollowerStatus & FOLLOWER_STATUS_INACTIVE);
            });
            if (followerCount < 1)
                return false;
            break;
        }
        case ModifierTreeType::PlayerDailyRandomValueMod_X_Equals: // 182 NYI
            return false;
        case ModifierTreeType::PlayerHasMount: // 183
        {
            for (auto&& p : referencePlayer->GetSession()->GetCollectionMgr()->GetAccountMounts())
            {
                MountEntry const* mount = sDB2Manager.GetMount(p.first);
                if (!mount)
                    continue;

                if (mount->ID == reqValue)
                    return true;
            }
            return false;
        }
        case ModifierTreeType::GarrisonFollowerCountWithInactiveWithItemLevelEqualOrGreaterThan: // 184
        {
            Garrison const* garrison = referencePlayer->GetGarrison();
            if (!garrison)
                return false;
            uint32 followerCount = garrison->CountFollowers([secondaryAsset, tertiaryAsset](Garrison::Follower const& follower)
            {
                GarrFollowerEntry const* garrFollower = sGarrFollowerStore.LookupEntry(follower.PacketInfo.GarrFollowerID);
                if (!garrFollower)
                    return false;
                return follower.GetItemLevel() >= secondaryAsset && garrFollower->GarrFollowerTypeID == tertiaryAsset;
            });
            if (followerCount < reqValue)
                return false;
            break;
        }
        case ModifierTreeType::GarrisonFollowerIsOnAMission: // 185
        {
            Garrison const* garrison = referencePlayer->GetGarrison();
            if (!garrison)
                return false;
            uint32 followerCount = garrison->CountFollowers([reqValue](Garrison::Follower const& follower)
            {
                return follower.PacketInfo.GarrFollowerID == reqValue && follower.PacketInfo.CurrentMissionID != 0;
            });
            if (followerCount < 1)
                return false;
            break;
        }
        case ModifierTreeType::GarrisonMissionCountInSetLessThan: // 186 NYI
            return false;
        case ModifierTreeType::GarrisonFollowerType: // 187
        {
            GarrFollowerEntry const* garrFollower = sGarrFollowerStore.LookupEntry(miscValue1);
            if (!garrFollower || garrFollower->GarrFollowerTypeID != int32(reqValue))
                return false;
            break;
        }
        case ModifierTreeType::PlayerUsedBoostLessThanHoursAgoRealTime: // 188 NYI
        case ModifierTreeType::PlayerUsedBoostLessThanHoursAgoGameTime: // 189 NYI
            return false;
        case ModifierTreeType::PlayerIsMercenary: // 190
            if (!referencePlayer->HasPlayerFlagEx(PLAYER_FLAGS_EX_MERCENARY_MODE))
                return false;
            break;
        case ModifierTreeType::PlayerEffectiveRace: // 191 NYI
        case ModifierTreeType::TargetEffectiveRace: // 192 NYI
            return false;
        case ModifierTreeType::HonorLevelEqualOrGreaterThan: // 193
            if (referencePlayer->GetHonorLevel() < reqValue)
                return false;
            break;
        case ModifierTreeType::PrestigeLevelEqualOrGreaterThan: // 194
            return false; // OBSOLOTE
        case ModifierTreeType::GarrisonMissionIsReadyToCollect: // 195 NYI
        case ModifierTreeType::PlayerIsInstanceOwner: // 196 NYI
            return false;
        case ModifierTreeType::PlayerHasHeirloom: // 197
            if (!Trinity::Containers::MapGetValuePtr(referencePlayer->GetSession()->GetCollectionMgr()->GetAccountHeirlooms(), reqValue))
                return false;
            break;
        case ModifierTreeType::TeamPoints: // 198 NYI
            return false;
        case ModifierTreeType::PlayerHasToy: // 199
            if (!referencePlayer->GetSession()->GetCollectionMgr()->HasToy(reqValue))
                return false;
            break;
        case ModifierTreeType::PlayerHasTransmog: // 200
        {
            std::pair<bool, bool> hasAppearance = referencePlayer->GetSession()->GetCollectionMgr()->HasItemAppearance(reqValue);
            if (!hasAppearance.first || hasAppearance.second)
                return false;
            break;
        }
        case ModifierTreeType::GarrisonTalentSelected: // 201 NYI
        case ModifierTreeType::GarrisonTalentResearched: // 202 NYI
            return false;
        case ModifierTreeType::PlayerHasRestriction: // 203
        {
            int32 restrictionIndex = referencePlayer->m_activePlayerData->CharacterRestrictions.FindIndexIf([reqValue](UF::CharacterRestriction const& restriction)
            {
                return restriction.Type == reqValue;
            });
            if (restrictionIndex < 0)
                return false;
            break;
        }
        case ModifierTreeType::PlayerCreatedCharacterLessThanHoursAgoRealTime: // 204 NYI
            return false;
        case ModifierTreeType::PlayerCreatedCharacterLessThanHoursAgoGameTime: // 205
            if (Hours(reqValue) >= Seconds(referencePlayer->GetTotalPlayedTime()))
                return false;
            break;
        case ModifierTreeType::QuestHasQuestInfoId: // 206
        {
            Quest const* quest = sObjectMgr->GetQuestTemplate(miscValue1);
            if (!quest || quest->GetQuestInfoID() != reqValue)
                return false;
            break;
        }
        case ModifierTreeType::GarrisonTalentResearchInProgress: // 207 NYI
            return false;
        case ModifierTreeType::PlayerEquippedArtifactAppearanceSet: // 208
        {
            if (Aura const* artifactAura = referencePlayer->GetAura(ARTIFACTS_ALL_WEAPONS_GENERAL_WEAPON_EQUIPPED_PASSIVE))
                if (Item* artifact = referencePlayer->GetItemByGuid(artifactAura->GetCastItemGUID()))
                    if (ArtifactAppearanceEntry const* artifactAppearance = sArtifactAppearanceStore.LookupEntry(artifact->GetModifier(ITEM_MODIFIER_ARTIFACT_APPEARANCE_ID)))
                        if (artifactAppearance->ArtifactAppearanceSetID == reqValue)
                            break;
            return false;
        }
        case ModifierTreeType::PlayerHasCurrencyEqual: // 209
            if (referencePlayer->GetCurrencyQuantity(reqValue) != secondaryAsset)
                return false;
            break;
        case ModifierTreeType::MinimumAverageItemHighWaterMarkForSpec: // 210 NYI
            return false;
        case ModifierTreeType::PlayerScenarioType: // 211
        {
            Scenario const* scenario = referencePlayer->GetScenario();
            if (!scenario)
                return false;
            if (scenario->GetEntry()->Type != reqValue)
                return false;
            break;
        }
        case ModifierTreeType::PlayersAuthExpansionLevelEqualOrGreaterThan: // 212
            if (referencePlayer->GetSession()->GetAccountExpansion() < reqValue)
                return false;
            break;
        case ModifierTreeType::PlayerLastWeek2v2Rating: // 213 NYI
        case ModifierTreeType::PlayerLastWeek3v3Rating: // 214 NYI
        case ModifierTreeType::PlayerLastWeekRBGRating: // 215 NYI
            return false;
        case ModifierTreeType::GroupMemberCountFromConnectedRealmEqualOrGreaterThan: // 216
        {
            uint32 memberCount = 0;
            if (Group const* group = referencePlayer->GetGroup())
                for (GroupReference const* itr = group->GetFirstMember(); itr != nullptr; itr = itr->next())
                    if (itr->GetSource() != referencePlayer && *referencePlayer->m_playerData->VirtualPlayerRealm == *itr->GetSource()->m_playerData->VirtualPlayerRealm)
                        ++memberCount;
            if (memberCount < reqValue)
                return false;
            break;
        }
        case ModifierTreeType::ArtifactTraitUnlockedCountEqualOrGreaterThan: // 217
        {
            Item const* artifact = referencePlayer->GetItemByEntry(secondaryAsset, ItemSearchLocation::Everywhere);
            if (!artifact)
                return false;
            if (artifact->GetTotalUnlockedArtifactPowers() < reqValue)
                return false;
            break;
        }
        case ModifierTreeType::ParagonReputationLevelEqualOrGreaterThan: // 218
            if (referencePlayer->GetReputationMgr().GetParagonLevel(miscValue1) < int32(reqValue))
                return false;
            return false;
        case ModifierTreeType::GarrisonShipmentIsReady: // 219 NYI
            return false;
        case ModifierTreeType::PlayerIsInPvpBrawl: // 220
        {
            BattlemasterListEntry const* bg = sBattlemasterListStore.LookupEntry(referencePlayer->GetBattlegroundTypeId());
            if (!bg || !(bg->GetFlags().HasFlag(BattlemasterListFlags::IsBrawl)))
                return false;
            break;
        }
        case ModifierTreeType::ParagonReputationLevelWithFactionEqualOrGreaterThan: // 221
        {
            FactionEntry const* faction = sFactionStore.LookupEntry(secondaryAsset);
            if (!faction)
                return false;
            if (referencePlayer->GetReputationMgr().GetParagonLevel(faction->ParagonFactionID) < int32(reqValue))
                return false;
            break;
        }
        case ModifierTreeType::PlayerHasItemWithBonusListFromTreeAndQuality: // 222
        {
            std::vector<int32> bonusListIDs = ItemBonusMgr::GetAllBonusListsForTree(reqValue);
            if (bonusListIDs.empty())
                return false;

            bool bagScanReachedEnd = referencePlayer->ForEachItem(ItemSearchLocation::Everywhere, [&bonusListIDs](Item const* item)
            {
                bool hasBonus = std::any_of(item->GetBonusListIDs().begin(), item->GetBonusListIDs().end(), [&bonusListIDs](int32 bonusListID)
                {
                    return std::find(bonusListIDs.begin(), bonusListIDs.end(), bonusListID) != bonusListIDs.end();
                });
                return hasBonus ? ItemSearchCallbackResult::Stop : ItemSearchCallbackResult::Continue;
            });
            if (bagScanReachedEnd)
                return false;
            break;
        }
        case ModifierTreeType::PlayerHasEmptyInventorySlotCountEqualOrGreaterThan: // 223
            if (referencePlayer->GetFreeInventorySlotCount(ItemSearchLocation::Inventory) < reqValue)
                return false;
            break;
        case ModifierTreeType::PlayerHasItemInHistoryOfProgressiveEvent: // 224 NYI
            return false;
        case ModifierTreeType::PlayerHasArtifactPowerRankCountPurchasedEqualOrGreaterThan: // 225
        {
            Aura const* artifactAura = referencePlayer->GetAura(ARTIFACTS_ALL_WEAPONS_GENERAL_WEAPON_EQUIPPED_PASSIVE);
            if (!artifactAura)
                return false;
            Item const* artifact = referencePlayer->GetItemByGuid(artifactAura->GetCastItemGUID());
            if (!artifact)
                return false;
            UF::ArtifactPower const* artifactPower = artifact->GetArtifactPower(secondaryAsset);
            if (!artifactPower)
                return false;
            if (artifactPower->PurchasedRank < reqValue)
                return false;
            break;
        }
        case ModifierTreeType::PlayerHasBoosted: // 226
            if (referencePlayer->HasLevelBoosted())
                return false;
            break;
        case ModifierTreeType::PlayerHasRaceChanged: // 227
            if (referencePlayer->HasRaceChanged())
                return false;
            break;
        case ModifierTreeType::PlayerHasBeenGrantedLevelsFromRaF: // 228
            if (referencePlayer->HasBeenGrantedLevelsFromRaF())
                return false;
            break;
        case ModifierTreeType::IsTournamentRealm: // 229
            return false;
        case ModifierTreeType::PlayerCanAccessAlliedRaces: // 230
            if (!referencePlayer->GetSession()->CanAccessAlliedRaces())
                return false;
            break;
        case ModifierTreeType::GroupMemberCountWithAchievementEqualOrLessThan: // 231
        {
            if (Group const* group = referencePlayer->GetGroup())
            {
                uint32 membersWithAchievement = 0;
                for (GroupReference const* itr = group->GetFirstMember(); itr != nullptr; itr = itr->next())
                    if (itr->GetSource()->HasAchieved(secondaryAsset))
                        ++membersWithAchievement;

                if (membersWithAchievement > reqValue)
                    return false;
            }
            // true if no group
            break;
        }
        case ModifierTreeType::PlayerMainhandWeaponType: // 232
        {
            UF::VisibleItem const& visibleItem = referencePlayer->m_playerData->VisibleItems[EQUIPMENT_SLOT_MAINHAND];
            uint32 itemSubclass = ITEM_SUBCLASS_WEAPON_FIST_WEAPON;
            if (ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(visibleItem.ItemID))
            {
                if (itemTemplate->GetClass() == ITEM_CLASS_WEAPON)
                {
                    itemSubclass = itemTemplate->GetSubClass();

                    if (ItemModifiedAppearanceEntry const* itemModifiedAppearance = sDB2Manager.GetItemModifiedAppearance(visibleItem.ItemID, visibleItem.ItemAppearanceModID))
                        if (ItemModifiedAppearanceExtraEntry const* itemModifiedAppearaceExtra = sItemModifiedAppearanceExtraStore.LookupEntry(itemModifiedAppearance->ID))
                            if (itemModifiedAppearaceExtra->DisplayWeaponSubclassID > 0)
                                itemSubclass = itemModifiedAppearaceExtra->DisplayWeaponSubclassID;
                }
            }
            if (itemSubclass != reqValue)
                return false;
            break;
        }
        case ModifierTreeType::PlayerOffhandWeaponType: // 233
        {
            UF::VisibleItem const& visibleItem = referencePlayer->m_playerData->VisibleItems[EQUIPMENT_SLOT_OFFHAND];
            uint32 itemSubclass = ITEM_SUBCLASS_WEAPON_FIST_WEAPON;
            if (ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(visibleItem.ItemID))
            {
                if (itemTemplate->GetClass() == ITEM_CLASS_WEAPON)
                {
                    itemSubclass = itemTemplate->GetSubClass();

                    if (ItemModifiedAppearanceEntry const* itemModifiedAppearance = sDB2Manager.GetItemModifiedAppearance(visibleItem.ItemID, visibleItem.ItemAppearanceModID))
                        if (ItemModifiedAppearanceExtraEntry const* itemModifiedAppearaceExtra = sItemModifiedAppearanceExtraStore.LookupEntry(itemModifiedAppearance->ID))
                            if (itemModifiedAppearaceExtra->DisplayWeaponSubclassID > 0)
                                itemSubclass = itemModifiedAppearaceExtra->DisplayWeaponSubclassID;
                }
            }
            if (itemSubclass != reqValue)
                return false;
            break;
        }
        case ModifierTreeType::PlayerPvpTier: // 234
        {
            PvpTierEntry const* pvpTier = sPvpTierStore.LookupEntry(reqValue);
            if (!pvpTier)
                return false;
            UF::PVPInfo const* pvpInfo = referencePlayer->GetPvpInfoForBracket(pvpTier->BracketID);
            if (!pvpInfo)
                return false;
            if (pvpTier->ID != pvpInfo->PvpTierID)
                return false;
            break;
        }
        case ModifierTreeType::PlayerAzeriteLevelEqualOrGreaterThan: // 235
        {
            Item const* heartOfAzeroth = referencePlayer->GetItemByEntry(ITEM_ID_HEART_OF_AZEROTH, ItemSearchLocation::Everywhere);
            if (!heartOfAzeroth || heartOfAzeroth->ToAzeriteItem()->GetLevel() < reqValue)
                return false;
            break;
        }
        case ModifierTreeType::PlayerIsOnQuestInQuestline: // 236
        {
            bool isOnQuest = false;
            if (std::vector<QuestLineXQuestEntry const*> const* questLineQuests = sDB2Manager.GetQuestsForQuestLine(reqValue))
            {
                isOnQuest = std::any_of(questLineQuests->begin(), questLineQuests->end(), [referencePlayer](QuestLineXQuestEntry const* questLineQuest)
                {
                    return referencePlayer->FindQuestSlot(questLineQuest->QuestID) < MAX_QUEST_LOG_SIZE;
                });
            }
            if (!isOnQuest)
                return false;
            break;
        }
        case ModifierTreeType::PlayerIsQnQuestLinkedToScheduledWorldStateGroup: // 237
            return false; // OBSOLETE (db2 removed)
        case ModifierTreeType::PlayerIsInRaidGroup: // 238
        {
            Group const* group = referencePlayer->GetGroup();
            if (!group || !group->isRaidGroup())
                return false;
            break;
        }
        case ModifierTreeType::PlayerPvpTierInBracketEqualOrGreaterThan: // 239
        {
            UF::PVPInfo const* pvpInfo = referencePlayer->GetPvpInfoForBracket(secondaryAsset);
            if (!pvpInfo)
                return false;
            PvpTierEntry const* pvpTier = sPvpTierStore.LookupEntry(pvpInfo->PvpTierID);
            if (!pvpTier)
                return false;
            if (pvpTier->Rank < int32(reqValue))
                return false;
            break;
        }
        case ModifierTreeType::PlayerCanAcceptQuestInQuestline: // 240
        {
            std::vector<QuestLineXQuestEntry const*> const* questLineQuests = sDB2Manager.GetQuestsForQuestLine(reqValue);
            if (!questLineQuests)
                return false;
            bool canTakeQuest = std::any_of(questLineQuests->begin(), questLineQuests->end(), [referencePlayer](QuestLineXQuestEntry const* questLineQuest)
            {
                if (Quest const* quest = sObjectMgr->GetQuestTemplate(questLineQuest->QuestID))
                    return referencePlayer->CanTakeQuest(quest, false);
                return false;
            });
            if (!canTakeQuest)
                return false;
            break;
        }
        case ModifierTreeType::PlayerHasCompletedQuestline: // 241
        {
            std::vector<QuestLineXQuestEntry const*> const* questLineQuests = sDB2Manager.GetQuestsForQuestLine(reqValue);
            if (!questLineQuests)
                return false;
            for (QuestLineXQuestEntry const* questLineQuest : *questLineQuests)
                if (!referencePlayer->GetQuestRewardStatus(questLineQuest->QuestID))
                    return false;
            break;
        }
        case ModifierTreeType::PlayerHasCompletedQuestlineQuestCount: // 242
        {
            std::vector<QuestLineXQuestEntry const*> const* questLineQuests = sDB2Manager.GetQuestsForQuestLine(reqValue);
            if (!questLineQuests)
                return false;
            uint32 completedQuests = 0;
            for (QuestLineXQuestEntry const* questLineQuest : *questLineQuests)
                if (referencePlayer->GetQuestRewardStatus(questLineQuest->QuestID))
                    ++completedQuests;
            if (completedQuests < reqValue)
                return false;
            break;
        }
        case ModifierTreeType::PlayerHasCompletedPercentageOfQuestline: // 243
        {
            std::vector<QuestLineXQuestEntry const*> const* questLineQuests = sDB2Manager.GetQuestsForQuestLine(reqValue);
            if (!questLineQuests || questLineQuests->empty())
                return false;
            std::size_t completedQuests = 0;
            for (QuestLineXQuestEntry const* questLineQuest : *questLineQuests)
                if (referencePlayer->GetQuestRewardStatus(questLineQuest->QuestID))
                    ++completedQuests;
            if (GetPctOf(completedQuests, questLineQuests->size()) < reqValue)
                return false;
            break;
        }
        case ModifierTreeType::PlayerHasWarModeEnabled: // 244
            if (!referencePlayer->HasPlayerLocalFlag(PLAYER_LOCAL_FLAG_WAR_MODE))
                return false;
            break;
        case ModifierTreeType::PlayerIsOnWarModeShard: // 245
            if (!referencePlayer->HasPlayerFlag(PLAYER_FLAGS_WAR_MODE_ACTIVE))
                return false;
            break;
        case ModifierTreeType::PlayerIsAllowedToToggleWarModeInArea: // 246
            if (!referencePlayer->CanEnableWarModeInArea())
                return false;
            break;
        case ModifierTreeType::MythicPlusKeystoneLevelEqualOrGreaterThan: // 247 NYI
        case ModifierTreeType::MythicPlusCompletedInTime: // 248 NYI
        case ModifierTreeType::MythicPlusMapChallengeMode: // 249 NYI
        case ModifierTreeType::MythicPlusDisplaySeason: // 250 NYI
        case ModifierTreeType::MythicPlusMilestoneSeason: // 251 NYI
            return false;
        case ModifierTreeType::PlayerVisibleRace: // 252
        {
            CreatureDisplayInfoEntry const* creatureDisplayInfo = sCreatureDisplayInfoStore.LookupEntry(referencePlayer->GetDisplayId());
            if (!creatureDisplayInfo)
                return false;
            CreatureDisplayInfoExtraEntry const* creatureDisplayInfoExtra = sCreatureDisplayInfoExtraStore.LookupEntry(creatureDisplayInfo->ExtendedDisplayInfoID);
            if (!creatureDisplayInfoExtra)
                return false;
            if (uint32(creatureDisplayInfoExtra->DisplayRaceID) != reqValue)
                return false;
            break;
        }
        case ModifierTreeType::TargetVisibleRace: // 253
        {
            if (!ref || !ref->IsUnit())
                return false;
            CreatureDisplayInfoEntry const* creatureDisplayInfo = sCreatureDisplayInfoStore.LookupEntry(ref->ToUnit()->GetDisplayId());
            if (!creatureDisplayInfo)
                return false;
            CreatureDisplayInfoExtraEntry const* creatureDisplayInfoExtra = sCreatureDisplayInfoExtraStore.LookupEntry(creatureDisplayInfo->ExtendedDisplayInfoID);
            if (!creatureDisplayInfoExtra)
                return false;
            if (uint32(creatureDisplayInfoExtra->DisplayRaceID) != reqValue)
                return false;
            break;
        }
        case ModifierTreeType::FriendshipRepReactionEqual: // 254
        {
            FriendshipRepReactionEntry const* friendshipRepReaction = sFriendshipRepReactionStore.LookupEntry(reqValue);
            if (!friendshipRepReaction)
                return false;
            FriendshipReputationEntry const* friendshipReputation = sFriendshipReputationStore.LookupEntry(friendshipRepReaction->FriendshipRepID);
            if (!friendshipReputation)
                return false;
            DB2Manager::FriendshipRepReactionSet const* friendshipReactions = sDB2Manager.GetFriendshipRepReactions(reqValue);
            if (!friendshipReactions)
                return false;
            uint32 rank = referencePlayer->GetReputationRank(friendshipReputation->FactionID);
            if (rank >= friendshipReactions->size())
                return false;
            auto itr = friendshipReactions->begin();
            std::advance(itr, rank);
            if ((*itr)->ID != reqValue)
                return false;
            break;
        }
        case ModifierTreeType::PlayerAuraStackCountEqual: // 255
            if (referencePlayer->GetAuraCount(secondaryAsset) != reqValue)
                return false;
            break;
        case ModifierTreeType::TargetAuraStackCountEqual: // 256
            if (!ref || !ref->IsUnit() || ref->ToUnit()->GetAuraCount(secondaryAsset) != reqValue)
                return false;
            break;
        case ModifierTreeType::PlayerAuraStackCountEqualOrGreaterThan: // 257
            if (referencePlayer->GetAuraCount(secondaryAsset) < reqValue)
                return false;
            break;
        case ModifierTreeType::TargetAuraStackCountEqualOrGreaterThan: // 258
            if (!ref || !ref->IsUnit() || ref->ToUnit()->GetAuraCount(secondaryAsset) < reqValue)
                return false;
            break;
        case ModifierTreeType::PlayerHasAzeriteEssenceRankLessThan: // 259
        {
            if (Item const* heartOfAzeroth = referencePlayer->GetItemByEntry(ITEM_ID_HEART_OF_AZEROTH, ItemSearchLocation::Everywhere))
                if (AzeriteItem const* azeriteItem = heartOfAzeroth->ToAzeriteItem())
                    for (UF::UnlockedAzeriteEssence const& essence : azeriteItem->m_azeriteItemData->UnlockedEssences)
                        if (essence.AzeriteEssenceID == reqValue && essence.Rank < secondaryAsset)
                            return true;
            return false;
        }
        case ModifierTreeType::PlayerHasAzeriteEssenceRankEqual: // 260
        {
            if (Item const* heartOfAzeroth = referencePlayer->GetItemByEntry(ITEM_ID_HEART_OF_AZEROTH, ItemSearchLocation::Everywhere))
                if (AzeriteItem const* azeriteItem = heartOfAzeroth->ToAzeriteItem())
                    for (UF::UnlockedAzeriteEssence const& essence : azeriteItem->m_azeriteItemData->UnlockedEssences)
                        if (essence.AzeriteEssenceID == reqValue && essence.Rank == secondaryAsset)
                            return true;
            return false;
        }
        case ModifierTreeType::PlayerHasAzeriteEssenceRankGreaterThan: // 261
        {
            if (Item const* heartOfAzeroth = referencePlayer->GetItemByEntry(ITEM_ID_HEART_OF_AZEROTH, ItemSearchLocation::Everywhere))
                if (AzeriteItem const* azeriteItem = heartOfAzeroth->ToAzeriteItem())
                    for (UF::UnlockedAzeriteEssence const& essence : azeriteItem->m_azeriteItemData->UnlockedEssences)
                        if (essence.AzeriteEssenceID == reqValue && essence.Rank > secondaryAsset)
                            return true;
            return false;
        }
        case ModifierTreeType::PlayerHasAuraWithEffectIndex: // 262
            if (!referencePlayer->GetAuraEffect(reqValue, secondaryAsset))
                return false;
            break;
        case ModifierTreeType::PlayerLootSpecializationMatchesRole: // 263
        {
            ChrSpecializationEntry const* spec = referencePlayer->GetPrimarySpecializationEntry();
            if (!spec || spec->Role != int32(reqValue))
                return false;
            break;
        }
        case ModifierTreeType::PlayerIsAtMaxExpansionLevel: // 264
            if (!referencePlayer->IsMaxLevel())
                return false;
            break;
        case ModifierTreeType::TransmogSource: // 265
        {
            ItemModifiedAppearanceEntry const* itemModifiedAppearance = sItemModifiedAppearanceStore.LookupEntry(miscValue2);
            if (!itemModifiedAppearance)
                return false;
            if (itemModifiedAppearance->TransmogSourceTypeEnum != int32(reqValue))
                return false;
            break;
        }
        case ModifierTreeType::PlayerHasAzeriteEssenceInSlotAtRankLessThan: // 266
            if (Item const* heartOfAzeroth = referencePlayer->GetItemByEntry(ITEM_ID_HEART_OF_AZEROTH, ItemSearchLocation::Everywhere))
                if (AzeriteItem const* azeriteItem = heartOfAzeroth->ToAzeriteItem())
                    if (UF::SelectedAzeriteEssences const* selectedEssences = azeriteItem->GetSelectedAzeriteEssences())
                        for (UF::UnlockedAzeriteEssence const& essence : azeriteItem->m_azeriteItemData->UnlockedEssences)
                            if (essence.AzeriteEssenceID == selectedEssences->AzeriteEssenceID[reqValue] && essence.Rank < secondaryAsset)
                                return true;
            return false;
        case ModifierTreeType::PlayerHasAzeriteEssenceInSlotAtRankGreaterThan: // 267
            if (Item const* heartOfAzeroth = referencePlayer->GetItemByEntry(ITEM_ID_HEART_OF_AZEROTH, ItemSearchLocation::Everywhere))
                if (AzeriteItem const* azeriteItem = heartOfAzeroth->ToAzeriteItem())
                    if (UF::SelectedAzeriteEssences const* selectedEssences = azeriteItem->GetSelectedAzeriteEssences())
                        for (UF::UnlockedAzeriteEssence const& essence : azeriteItem->m_azeriteItemData->UnlockedEssences)
                            if (essence.AzeriteEssenceID == selectedEssences->AzeriteEssenceID[reqValue] && essence.Rank > secondaryAsset)
                                return true;
            return false;
        case ModifierTreeType::PlayerLevelWithinContentTuning: // 268
        {
            uint8 level = referencePlayer->GetLevel();
            if (Optional<ContentTuningLevels> levels = sDB2Manager.GetContentTuningData(reqValue, 0))
            {
                if (secondaryAsset)
                    return level >= levels->MinLevelWithDelta && level <= levels->MaxLevelWithDelta;
                return level >= levels->MinLevel && level <= levels->MaxLevel;
            }
            return false;
        }
        case ModifierTreeType::TargetLevelWithinContentTuning: // 269
        {
            if (!ref || !ref->IsUnit())
                return false;
            uint8 level = ref->ToUnit()->GetLevel();
            if (Optional<ContentTuningLevels> levels = sDB2Manager.GetContentTuningData(reqValue, 0))
            {
                if (secondaryAsset)
                    return level >= levels->MinLevelWithDelta && level <= levels->MaxLevelWithDelta;
                return level >= levels->MinLevel && level <= levels->MaxLevel;
            }
            return false;
        }
        case ModifierTreeType::PlayerIsScenarioInitiator: // 270 NYI
            return false;
        case ModifierTreeType::PlayerHasCompletedQuestOrIsOnQuest: // 271
        {
            QuestStatus status = referencePlayer->GetQuestStatus(reqValue);
            if (status == QUEST_STATUS_NONE || status == QUEST_STATUS_FAILED)
                return false;
            break;
        }
        case ModifierTreeType::PlayerLevelWithinOrAboveContentTuning: // 272
        {
            uint8 level = referencePlayer->GetLevel();
            if (Optional<ContentTuningLevels> levels = sDB2Manager.GetContentTuningData(reqValue, 0))
                return secondaryAsset ? level >= levels->MinLevelWithDelta : level >= levels->MinLevel;
            return false;
        }
        case ModifierTreeType::TargetLevelWithinOrAboveContentTuning: // 273
        {
            if (!ref || !ref->IsUnit())
                return false;
            uint8 level = ref->ToUnit()->GetLevel();
            if (Optional<ContentTuningLevels> levels = sDB2Manager.GetContentTuningData(reqValue, 0))
                return secondaryAsset ? level >= levels->MinLevelWithDelta : level >= levels->MinLevel;
            return false;
        }
        case ModifierTreeType::PlayerLevelWithinOrAboveLevelRange: // 274 NYI
        case ModifierTreeType::TargetLevelWithinOrAboveLevelRange: // 275 NYI
            return false;
        case ModifierTreeType::MaxJailersTowerLevelEqualOrGreaterThan: // 276
            if (referencePlayer->m_activePlayerData->JailersTowerLevelMax < int32(reqValue))
                return false;
            break;
        case ModifierTreeType::GroupedWithRaFRecruit: // 277
        {
            Group const* group = referencePlayer->GetGroup();
            if (!group)
                return false;
            for (GroupReference const* itr = group->GetFirstMember(); itr != nullptr; itr = itr->next())
                if (itr->GetSource()->GetSession()->GetRecruiterId() == referencePlayer->GetSession()->GetAccountId())
                    return true;
            return false;
        }
        case ModifierTreeType::GroupedWithRaFRecruiter: // 278
        {
            Group const* group = referencePlayer->GetGroup();
            if (!group)
                return false;
            for (GroupReference const* itr = group->GetFirstMember(); itr != nullptr; itr = itr->next())
                if (itr->GetSource()->GetSession()->GetAccountId() == referencePlayer->GetSession()->GetRecruiterId())
                    return true;
            return false;
        }
        case ModifierTreeType::PlayerSpecialization: // 279
            if (referencePlayer->GetPrimarySpecialization() != ChrSpecialization(reqValue))
                return false;
            break;
        case ModifierTreeType::PlayerMapOrCosmeticChildMap: // 280
        {
            MapEntry const* map = referencePlayer->GetMap()->GetEntry();
            if (map->ID != reqValue && map->CosmeticParentMapID != int32(reqValue))
                return false;
            break;
        }
        case ModifierTreeType::PlayerCanAccessShadowlandsPrepurchaseContent: // 281
            if (referencePlayer->GetSession()->GetAccountExpansion() < EXPANSION_SHADOWLANDS)
                return false;
            break;
        case ModifierTreeType::PlayerHasEntitlement: // 282 NYI
        case ModifierTreeType::PlayerIsInPartySyncGroup: // 283 NYI
        case ModifierTreeType::QuestHasPartySyncRewards: // 284 NYI
        case ModifierTreeType::HonorGainSource: // 285 NYI
        case ModifierTreeType::JailersTowerActiveFloorIndexEqualOrGreaterThan: // 286 NYI
        case ModifierTreeType::JailersTowerActiveFloorDifficultyEqualOrGreaterThan: // 287 NYI
            return false;
        case ModifierTreeType::PlayerCovenant: // 288
            if (referencePlayer->m_playerData->CovenantID != int32(reqValue))
                return false;
            break;
        case ModifierTreeType::HasTimeEventPassed: // 289
        {
            time_t eventTimestamp = GameTime::GetGameTime();
            switch (reqValue)
            {
                case 111: // Battle for Azeroth Season 4 Start
                    eventTimestamp = time_t(1579618800); // January 21, 2020 8:00
                    break;
                case 120: // Patch 9.0.1
                    eventTimestamp = time_t(1602601200); // October 13, 2020 8:00
                    break;
                case 121: // Shadowlands Season 1 Start
                    eventTimestamp = time_t(1607439600); // December 8, 2020 8:00
                    break;
                case 123: // Shadowlands Season 1 End
                    // timestamp = unknown
                    break;
                case 149: // Shadowlands Season 2 End
                    // timestamp = unknown
                    break;
                case 349: // Dragonflight Season 3 Start (pre-season)
                    eventTimestamp = time_t(1699340400); // November 7, 2023 8:00
                    break;
                case 350: // Dragonflight Season 3 Start
                    eventTimestamp = time_t(1699945200); // November 14, 2023 8:00
                    break;
                case 352: // Dragonflight Season 3 End
                    // eventTimestamp = time_t(); unknown
                    break;
                default:
                    break;
            }
            if (GameTime::GetGameTime() < eventTimestamp)
                return false;
            break;
        }
        case ModifierTreeType::GarrisonHasPermanentTalent: // 290 NYI
            return false;
        case ModifierTreeType::HasActiveSoulbind: // 291
            if (referencePlayer->m_playerData->SoulbindID != int32(reqValue))
                return false;
            break;
        case ModifierTreeType::HasMemorizedSpell: // 292 NYI
            return false;
        case ModifierTreeType::PlayerHasAPACSubscriptionReward_2020: // 293
        case ModifierTreeType::PlayerHasTBCCDEWarpStalker_Mount: // 294
        case ModifierTreeType::PlayerHasTBCCDEDarkPortal_Toy: // 295
        case ModifierTreeType::PlayerHasTBCCDEPathOfIllidan_Toy: // 296
        case ModifierTreeType::PlayerHasImpInABallToySubscriptionReward: // 297
            return false;
        case ModifierTreeType::PlayerIsInAreaGroup: // 298
        {
            std::vector<uint32> areas = sDB2Manager.GetAreasForGroup(reqValue);
            for (uint32 areaInGroup : areas)
                if (DB2Manager::IsInArea(referencePlayer->GetAreaId(), areaInGroup))
                    return true;
            return false;
        }
        case ModifierTreeType::TargetIsInAreaGroup: // 299
        {
            if (!ref)
                return false;
            std::vector<uint32> areas = sDB2Manager.GetAreasForGroup(reqValue);
            for (uint32 areaInGroup : areas)
                if (DB2Manager::IsInArea(ref->GetAreaId(), areaInGroup))
                    return true;
            return false;
        }
        case ModifierTreeType::PlayerIsInChromieTime: // 300
            if (referencePlayer->m_activePlayerData->UiChromieTimeExpansionID != int32(reqValue))
                return false;
            break;
        case ModifierTreeType::PlayerIsInAnyChromieTime: // 301
            if (referencePlayer->m_activePlayerData->UiChromieTimeExpansionID == 0)
                return false;
            break;
        case ModifierTreeType::ItemIsAzeriteArmor: // 302
            if (!sDB2Manager.GetAzeriteEmpoweredItem(miscValue1))
                return false;
            break;
        case ModifierTreeType::PlayerHasRuneforgePower: // 303
        {
            uint32 block = reqValue / 32;
            if (block >= referencePlayer->m_activePlayerData->RuneforgePowers.size())
                return false;

            uint32 bit = reqValue % 32;
            return referencePlayer->m_activePlayerData->RuneforgePowers[block] & (1 << bit);
        }
        case ModifierTreeType::PlayerInChromieTimeForScaling: // 304
            if (!(referencePlayer->m_playerData->CtrOptions->ContentTuningConditionMask & 1))
                return false;
            break;
        case ModifierTreeType::IsRaFRecruit: // 305
            if (!referencePlayer->GetSession()->GetRecruiterId())
                return false;
            break;
        case ModifierTreeType::AllPlayersInGroupHaveAchievement: // 306
        {
            if (Group const* group = referencePlayer->GetGroup())
            {
                for (GroupReference const* itr = group->GetFirstMember(); itr != nullptr; itr = itr->next())
                    if (!itr->GetSource()->HasAchieved(reqValue))
                        return false;
            }
            else if (!referencePlayer->HasAchieved(reqValue))
                return false;
            break;
        }
        case ModifierTreeType::PlayerHasSoulbindConduitRankEqualOrGreaterThan: // 307 NYI
            return false;
        case ModifierTreeType::PlayerSpellShapeshiftFormCreatureDisplayInfoSelection: // 308
        {
            ShapeshiftFormModelData const* formModelData = sDB2Manager.GetShapeshiftFormModelData(referencePlayer->GetRace(), referencePlayer->GetNativeGender(), secondaryAsset);
            if (!formModelData)
                return false;
            uint32 formChoice = referencePlayer->GetCustomizationChoice(formModelData->OptionID);
            auto choiceItr = std::find_if(formModelData->Choices->begin(), formModelData->Choices->end(), [formChoice](ChrCustomizationChoiceEntry const* choice)
            {
                return choice->ID == formChoice;
            });
            if (choiceItr == formModelData->Choices->end())
                return false;
            if (int32(reqValue) != formModelData->Displays[std::distance(formModelData->Choices->begin(), choiceItr)]->DisplayID)
                return false;
            break;
        }
        case ModifierTreeType::PlayerSoulbindConduitCountAtRankEqualOrGreaterThan: // 309 NYI
            return false;
        case ModifierTreeType::PlayerIsRestrictedAccount: // 310
            return false;
        case ModifierTreeType::PlayerIsFlying: // 311
            if (!referencePlayer->IsFlying())
                return false;
            break;
        case ModifierTreeType::PlayerScenarioIsLastStep: // 312
        {
            Scenario const* scenario = referencePlayer->GetScenario();
            if (!scenario)
                return false;
            if (scenario->GetStep() != scenario->GetLastStep())
                return false;
            break;
        }
        case ModifierTreeType::PlayerHasWeeklyRewardsAvailable: // 313
            if (!*referencePlayer->m_activePlayerData->WeeklyRewardsPeriodSinceOrigin)
                return false;
            break;
        case ModifierTreeType::TargetCovenant: // 314
            if (!ref || !ref->IsPlayer())
                return false;
            if (ref->ToPlayer()->m_playerData->CovenantID != int32(reqValue))
                return false;
            break;
        case ModifierTreeType::PlayerHasTBCCollectorsEdition: // 315
        case ModifierTreeType::PlayerHasWrathCollectorsEdition: // 316
            return false;
        case ModifierTreeType::GarrisonTalentResearchedAndAtRankEqualOrGreaterThan: // 317 NYI
        case ModifierTreeType::CurrencySpentOnGarrisonTalentResearchEqualOrGreaterThan: // 318 NYI
        case ModifierTreeType::RenownCatchupActive: // 319 NYI
        case ModifierTreeType::RapidRenownCatchupActive: // 320 NYI
        case ModifierTreeType::PlayerMythicPlusRatingEqualOrGreaterThan: // 321 NYI
        case ModifierTreeType::PlayerMythicPlusRunCountInCurrentExpansionEqualOrGreaterThan: // 322 NYI
            return false;
        case ModifierTreeType::PlayerHasCustomizationChoice: // 323
        {
            int32 customizationChoiceIndex = referencePlayer->m_playerData->Customizations.FindIndexIf([reqValue](UF::ChrCustomizationChoice const& choice)
            {
                return choice.ChrCustomizationChoiceID == reqValue;
            });
            if (customizationChoiceIndex < 0)
                return false;
            break;
        }
        case ModifierTreeType::PlayerBestWeeklyWinPvpTier: // 324
        {
            PvpTierEntry const* pvpTier = sPvpTierStore.LookupEntry(reqValue);
            if (!pvpTier)
                return false;
            UF::PVPInfo const* pvpInfo = referencePlayer->GetPvpInfoForBracket(pvpTier->BracketID);
            if (!pvpInfo)
                return false;
            if (pvpTier->ID != pvpInfo->WeeklyBestWinPvpTierID)
                return false;
            break;
        }
        case ModifierTreeType::PlayerBestWeeklyWinPvpTierInBracketEqualOrGreaterThan: // 325
        {
            UF::PVPInfo const* pvpInfo = referencePlayer->GetPvpInfoForBracket(secondaryAsset);
            if (!pvpInfo)
                return false;
            PvpTierEntry const* pvpTier = sPvpTierStore.LookupEntry(pvpInfo->WeeklyBestWinPvpTierID);
            if (!pvpTier)
                return false;
            if (pvpTier->Rank < int32(reqValue))
                return false;
            break;
        }
        case ModifierTreeType::PlayerHasVanillaCollectorsEdition: // 326
            return false;
        case ModifierTreeType::PlayerHasItemWithKeystoneLevelModifierEqualOrGreaterThan: // 327
        {
            bool bagScanReachedEnd = referencePlayer->ForEachItem(ItemSearchLocation::Inventory, [reqValue, secondaryAsset](Item const* item)
            {
                if (item->GetEntry() != reqValue)
                    return ItemSearchCallbackResult::Continue;

                if (item->GetModifier(ITEM_MODIFIER_CHALLENGE_KEYSTONE_LEVEL) < secondaryAsset)
                    return ItemSearchCallbackResult::Continue;

                return ItemSearchCallbackResult::Stop;
            });
            if (bagScanReachedEnd)
                return false;
            break;
        }
        case ModifierTreeType::PlayerAuraWithLabelStackCountEqualOrGreaterThan: // 335
        {
            uint32 count = 0;
            referencePlayer->HasAura([secondaryAsset, &count](Aura const* aura)
            {
                if (aura->GetSpellInfo()->HasLabel(secondaryAsset))
                    count += aura->GetStackAmount();
                return false;
            });
            if (count < reqValue)
                return false;
            break;
        }
        case ModifierTreeType::PlayerAuraWithLabelStackCountEqual: // 336
        {
            uint32 count = 0;
            referencePlayer->HasAura([secondaryAsset, &count](Aura const* aura)
            {
                if (aura->GetSpellInfo()->HasLabel(secondaryAsset))
                    count += aura->GetStackAmount();
                return false;
            });
            if (count != reqValue)
                return false;
            break;
        }
        case ModifierTreeType::PlayerAuraWithLabelStackCountEqualOrLessThan: // 337
        {
            uint32 count = 0;
            referencePlayer->HasAura([secondaryAsset, &count](Aura const* aura)
            {
                if (aura->GetSpellInfo()->HasLabel(secondaryAsset))
                    count += aura->GetStackAmount();
                return false;
            });
            if (count > reqValue)
                return false;
            break;
        }
        case ModifierTreeType::PlayerIsInCrossFactionGroup: // 338
        {
            Group const* group = referencePlayer->GetGroup();
            if (!(group->GetGroupFlags() & GROUP_FLAG_CROSS_FACTION))
                return false;
            break;
        }
        case ModifierTreeType::PlayerHasTraitNodeEntryInActiveConfig: // 340
        {
            auto hasTraitNodeEntry = [referencePlayer, reqValue]()
            {
                for (UF::TraitConfig const& traitConfig : referencePlayer->m_activePlayerData->TraitConfigs)
                {
                    if (TraitConfigType(*traitConfig.Type) == TraitConfigType::Combat)
                    {
                        if (int32(*referencePlayer->m_activePlayerData->ActiveCombatTraitConfigID) != traitConfig.ID
                            || !EnumFlag(TraitCombatConfigFlags(*traitConfig.CombatConfigFlags)).HasFlag(TraitCombatConfigFlags::ActiveForSpec))
                            continue;
                    }

                    for (UF::TraitEntry const& traitEntry : traitConfig.Entries)
                        if (traitEntry.TraitNodeEntryID == int32(reqValue))
                            return true;
                }
                return false;
            }();
            if (!hasTraitNodeEntry)
                return false;
            break;
        }
        case ModifierTreeType::PlayerHasTraitNodeEntryInActiveConfigRankGreaterOrEqualThan: // 341
        {
            auto traitNodeEntryRank = [referencePlayer, secondaryAsset]() -> Optional<uint16>
            {
                for (UF::TraitConfig const& traitConfig : referencePlayer->m_activePlayerData->TraitConfigs)
                {
                    if (TraitConfigType(*traitConfig.Type) == TraitConfigType::Combat)
                    {
                        if (int32(*referencePlayer->m_activePlayerData->ActiveCombatTraitConfigID) != traitConfig.ID
                            || !EnumFlag(TraitCombatConfigFlags(*traitConfig.CombatConfigFlags)).HasFlag(TraitCombatConfigFlags::ActiveForSpec))
                            continue;
                    }

                    for (UF::TraitEntry const& traitEntry : traitConfig.Entries)
                        if (traitEntry.TraitNodeEntryID == int32(secondaryAsset))
                            return traitEntry.Rank;
                }
                return {};
            }();
            if (!traitNodeEntryRank || traitNodeEntryRank < int32(reqValue))
                return false;
            break;
        }
        case ModifierTreeType::PlayerDaysSinceLogout: // 344
            if (GameTime::GetGameTime() - referencePlayer->m_playerData->LogoutTime < int64(reqValue) * DAY)
                return false;
            break;
        case ModifierTreeType::PlayerHasPerksProgramPendingReward: // 350
            if (!referencePlayer->m_activePlayerData->HasPerksProgramPendingReward)
                return false;
            break;
        case ModifierTreeType::PlayerCanUseItem: // 351
        {
            ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(reqValue);
            if (!itemTemplate || !referencePlayer->CanUseItem(itemTemplate))
                return false;
            break;
        }
        case ModifierTreeType::PlayerSummonedBattlePetSpecies: // 352
            if (referencePlayer->m_playerData->CurrentBattlePetSpeciesID != int32(reqValue))
                return false;
            break;
        case ModifierTreeType::PlayerSummonedBattlePetIsMaxLevel: // 353
            if (referencePlayer->m_unitData->WildBattlePetLevel != BattlePets::MAX_BATTLE_PET_LEVEL)
                return false;
            break;
        case ModifierTreeType::PlayerHasAtLeastProfPathRanks: // 355
        {
            auto traitNodeEntryRankCount = [referencePlayer, secondaryAsset]()
            {
                uint32 ranks = 0;
                for (UF::TraitConfig const& traitConfig : referencePlayer->m_activePlayerData->TraitConfigs)
                {
                    if (TraitConfigType(*traitConfig.Type) != TraitConfigType::Profession)
                        continue;

                    if (*traitConfig.SkillLineID != int32(secondaryAsset))
                        continue;

                    for (UF::TraitEntry const& traitEntry : traitConfig.Entries)
                        if (sTraitNodeEntryStore.AssertEntry(traitEntry.TraitNodeEntryID)->GetNodeEntryType() == TraitNodeEntryType::ProfPath)
                            ranks += traitEntry.Rank + traitEntry.GrantedRanks;
                }
                return ranks;
            }();
            if (traitNodeEntryRankCount < reqValue)
                return false;
            break;
        }
        case ModifierTreeType::PlayerHasItemTransmogrifiedToItemModifiedAppearance: // 358
        {
            ItemModifiedAppearanceEntry const* itemModifiedAppearance = sItemModifiedAppearanceStore.LookupEntry(reqValue);

            bool bagScanReachedEnd = referencePlayer->ForEachItem(ItemSearchLocation::Inventory, [referencePlayer, itemModifiedAppearance](Item const* item)
            {
                if (item->GetVisibleAppearanceModId(referencePlayer) == itemModifiedAppearance->ID)
                    return ItemSearchCallbackResult::Stop;

                if (item->GetEntry() == itemModifiedAppearance->ItemID)
                    return ItemSearchCallbackResult::Stop;

                return ItemSearchCallbackResult::Continue;
            });
            if (bagScanReachedEnd)
                return false;
            break;
        }
        case ModifierTreeType::PlayerHasCompletedDungeonEncounterInDifficulty: // 366
            if (!referencePlayer->IsLockedToDungeonEncounter(reqValue, Difficulty(secondaryAsset)))
                return false;
            break;
        case ModifierTreeType::PlayerIsBetweenQuests: // 369
        {
            QuestStatus status = referencePlayer->GetQuestStatus(reqValue);
            if (status == QUEST_STATUS_NONE || status == QUEST_STATUS_FAILED)
                return false;
            if (referencePlayer->IsQuestRewarded(secondaryAsset))
                return false;
            break;
        }
        case ModifierTreeType::PlayerScenarioStepID: // 371
        {
            Scenario const* scenario = referencePlayer->GetScenario();
            if (!scenario)
                return false;
            if (scenario->GetStep()->ID != reqValue)
                return false;
            break;
        }
        case ModifierTreeType::PlayerZPositionBelow: // 374
            if (referencePlayer->GetPositionZ() >= reqValue)
                return false;
            break;
        case ModifierTreeType::PlayerIsOnMapWithExpansion: // 380
        {
            MapEntry const* mapEntry = referencePlayer->GetMap()->GetEntry();
            if (mapEntry->ExpansionID != reqValue)
                return false;
            break;
        }
        case ModifierTreeType::PlayerHasActiveTraitSubTree: // 385
        {
            int32 traitConfigWithSubtree = referencePlayer->m_activePlayerData->TraitConfigs.FindIndexIf([referencePlayer, reqValue](UF::TraitConfig const& traitConfig)
            {
                if (TraitConfigType(*traitConfig.Type) == TraitConfigType::Combat
                    && (int32(*referencePlayer->m_activePlayerData->ActiveCombatTraitConfigID) != traitConfig.ID
                        || !EnumFlag(TraitCombatConfigFlags(*traitConfig.CombatConfigFlags)).HasFlag(TraitCombatConfigFlags::ActiveForSpec)))
                    return false;

                return traitConfig.SubTrees.FindIndexIf([reqValue](UF::TraitSubTreeCache const& traitSubTree)
                {
                    return traitSubTree.TraitSubTreeID == int32(reqValue) && traitSubTree.Active;
                }) >= 0;
            });
            if (traitConfigWithSubtree < 0)
                return false;
            break;
        }
        case ModifierTreeType::TargetCreatureClassificationEqual: // 389
        {
            Creature const* targetCreature = Object::ToCreature(ref);
            if (!targetCreature)
                return false;
            if (targetCreature->GetCreatureClassification() != CreatureClassifications(reqValue))
                return false;
            break;
        }
        case ModifierTreeType::PlayerHasCompletedQuestOrIsReadyToTurnIn: // 392
        {
            QuestStatus status = referencePlayer->GetQuestStatus(reqValue);
            if (status != QUEST_STATUS_COMPLETE && status != QUEST_STATUS_REWARDED)
                return false;
            break;
        }
        default:
            return false;
    }
    return true;
}

CriteriaList const CriteriaMgr::EmptyCriteriaList;

char const* CriteriaMgr::GetCriteriaTypeString(uint32 type)
{
    return GetCriteriaTypeString(CriteriaType(type));
}

char const* CriteriaMgr::GetCriteriaTypeString(CriteriaType type)
{
    switch (type)
    {
        case CriteriaType::KillCreature:
            return "KillCreature";
        case CriteriaType::WinBattleground:
            return "WinBattleground";
        case CriteriaType::CompleteResearchProject:
            return "CompleteResearchProject";
        case CriteriaType::CompleteAnyResearchProject:
            return "CompleteAnyResearchProject";
        case CriteriaType::FindResearchObject:
            return "FindResearchObject";
        case CriteriaType::ReachLevel:
            return "ReachLevel";
        case CriteriaType::ExhaustAnyResearchSite:
            return "ExhaustAnyResearchSite";
        case CriteriaType::SkillRaised:
            return "SkillRaised";
        case CriteriaType::EarnAchievement:
            return "EarnAchievement";
        case CriteriaType::CompleteQuestsCount:
            return "CompleteQuestsCount";
        case CriteriaType::CompleteAnyDailyQuestPerDay:
            return "CompleteAnyDailyQuestPerDay";
        case CriteriaType::CompleteQuestsInZone:
            return "CompleteQuestsInZone";
        case CriteriaType::CurrencyGained:
            return "CurrencyGained";
        case CriteriaType::DamageDealt:
            return "DamageDealt";
        case CriteriaType::CompleteDailyQuest:
            return "CompleteDailyQuest";
        case CriteriaType::ParticipateInBattleground:
            return "ParticipateInBattleground";
        case CriteriaType::DieOnMap:
            return "DieOnMap";
        case CriteriaType::DieAnywhere:
            return "DieAnywhere";
        case CriteriaType::DieInInstance:
            return "DieInInstance";
        case CriteriaType::RunInstance:
            return "RunInstance";
        case CriteriaType::KilledByCreature:
            return "KilledByCreature";
        case CriteriaType::CompleteInternalCriteria:
            return "CompleteInternalCriteria";
        case CriteriaType::CompleteAnyChallengeMode:
            return "CompleteAnyChallengeMode";
        case CriteriaType::KilledByPlayer:
            return "KilledByPlayer";
        case CriteriaType::MaxDistFallenWithoutDying:
            return "MaxDistFallenWithoutDying";
        case CriteriaType::EarnChallengeModeMedal:
            return "EarnChallengeModeMedal";
        case CriteriaType::DieFromEnviromentalDamage:
            return "DieFromEnviromentalDamage";
        case CriteriaType::CompleteQuest:
            return "CompleteQuest";
        case CriteriaType::BeSpellTarget:
            return "BeSpellTarget";
        case CriteriaType::CastSpell:
            return "CastSpell";
        case CriteriaType::TrackedWorldStateUIModified:
            return "TrackedWorldStateUIModified";
        case CriteriaType::PVPKillInArea:
            return "PVPKillInArea";
        case CriteriaType::WinArena:
            return "WinArena";
        case CriteriaType::ParticipateInArena:
            return "ParticipateInArena";
        case CriteriaType::LearnOrKnowSpell:
            return "LearnOrKnowSpell";
        case CriteriaType::EarnHonorableKill:
            return "EarnHonorableKill";
        case CriteriaType::AcquireItem:
            return "AcquireItem";
        case CriteriaType::WinAnyRankedArena:
            return "WinAnyRankedArena";
        case CriteriaType::EarnTeamArenaRating:
            return "EarnTeamArenaRating";
        case CriteriaType::EarnPersonalArenaRating:
            return "EarnPersonalArenaRating";
        case CriteriaType::AchieveSkillStep:
            return "AchieveSkillStep";
        case CriteriaType::UseItem:
            return "UseItem";
        case CriteriaType::LootItem:
            return "LootItem";
        case CriteriaType::RevealWorldMapOverlay:
            return "RevealWorldMapOverlay";
        case CriteriaType::EarnTitle:
            return "EarnTitle";
        case CriteriaType::BankSlotsPurchased:
            return "BankSlotsPurchased";
        case CriteriaType::ReputationGained:
            return "ReputationGained";
        case CriteriaType::TotalExaltedFactions:
            return "TotalExaltedFactions";
        case CriteriaType::GotHaircut:
            return "GotHaircut";
        case CriteriaType::EquipItemInSlot:
            return "EquipItemInSlot";
        case CriteriaType::RollNeed:
            return "RollNeed";
        case CriteriaType::RollGreed:
            return "RollGreed";
        case CriteriaType::DeliverKillingBlowToClass:
            return "DeliverKillingBlowToClass";
        case CriteriaType::DeliverKillingBlowToRace:
            return "DeliverKillingBlowToRace";
        case CriteriaType::DoEmote:
            return "DoEmote";
        case CriteriaType::HealingDone:
            return "HealingDone";
        case CriteriaType::DeliveredKillingBlow:
            return "DeliveredKillingBlow";
        case CriteriaType::EquipItem:
            return "EquipItem";
        case CriteriaType::CompleteQuestsInSort:
            return "CompleteQuestsInSort";
        case CriteriaType::MoneyEarnedFromSales:
            return "MoneyEarnedFromSales";
        case CriteriaType::MoneySpentOnRespecs:
            return "MoneySpentOnRespecs";
        case CriteriaType::TotalRespecs:
            return "TotalRespecs";
        case CriteriaType::MoneyEarnedFromQuesting:
            return "MoneyEarnedFromQuesting";
        case CriteriaType::MoneySpentOnTaxis:
            return "MoneySpentOnTaxis";
        case CriteriaType::KilledAllUnitsInSpawnRegion:
            return "KilledAllUnitsInSpawnRegion";
        case CriteriaType::MoneySpentAtBarberShop:
            return "MoneySpentAtBarberShop";
        case CriteriaType::MoneySpentOnPostage:
            return "MoneySpentOnPostage";
        case CriteriaType::MoneyLootedFromCreatures:
            return "MoneyLootedFromCreatures";
        case CriteriaType::UseGameobject:
            return "UseGameobject";
        case CriteriaType::GainAura:
            return "GainAura";
        case CriteriaType::KillPlayer:
            return "KillPlayer";
        case CriteriaType::CompleteChallengeMode:
            return "CompleteChallengeMode";
        case CriteriaType::CatchFishInFishingHole:
            return "CatchFishInFishingHole";
        case CriteriaType::PlayerTriggerGameEvent:
            return "PlayerTriggerGameEvent";
        case CriteriaType::Login:
            return "Login";
        case CriteriaType::LearnSpellFromSkillLine:
            return "LearnSpellFromSkillLine";
        case CriteriaType::WinDuel:
            return "WinDuel";
        case CriteriaType::LoseDuel:
            return "LoseDuel";
        case CriteriaType::KillAnyCreature:
            return "KillAnyCreature";
        case CriteriaType::CreatedItemsByCastingSpellWithLimit:
            return "CreatedItemsByCastingSpellWithLimit";
        case CriteriaType::MoneyEarnedFromAuctions:
            return "MoneyEarnedFromAuctions";
        case CriteriaType::BattlePetAchievementPointsEarned:
            return "BattlePetAchievementPointsEarned";
        case CriteriaType::ItemsPostedAtAuction:
            return "ItemsPostedAtAuction";
        case CriteriaType::HighestAuctionBid:
            return "HighestAuctionBid";
        case CriteriaType::AuctionsWon:
            return "AuctionsWon";
        case CriteriaType::HighestAuctionSale:
            return "HighestAuctionSale";
        case CriteriaType::MostMoneyOwned:
            return "MostMoneyOwned";
        case CriteriaType::TotalReveredFactions:
            return "TotalReveredFactions";
        case CriteriaType::TotalHonoredFactions:
            return "TotalHonoredFactions";
        case CriteriaType::TotalFactionsEncountered:
            return "TotalFactionsEncountered";
        case CriteriaType::LootAnyItem:
            return "LootAnyItem";
        case CriteriaType::ObtainAnyItem:
            return "ObtainAnyItem";
        case CriteriaType::AnyoneTriggerGameEventScenario:
            return "AnyoneTriggerGameEventScenario";
        case CriteriaType::RollAnyNeed:
            return "RollAnyNeed";
        case CriteriaType::RollAnyGreed:
            return "RollAnyGreed";
        case CriteriaType::ReleasedSpirit:
            return "ReleasedSpirit";
        case CriteriaType::AccountKnownPet:
            return "AccountKnownPet";
        case CriteriaType::DefeatDungeonEncounterWhileElegibleForLoot:
            return "DefeatDungeonEncounterWhileElegibleForLoot";
        case CriteriaType::HighestDamageDone:
            return "HighestDamageDone";
        case CriteriaType::HighestDamageTaken:
            return "HighestDamageTaken";
        case CriteriaType::TotalDamageTaken:
            return "TotalDamageTaken";
        case CriteriaType::HighestHealCast:
            return "HighestHealCast";
        case CriteriaType::TotalHealReceived:
            return "TotalHealReceived";
        case CriteriaType::HighestHealReceived:
            return "HighestHealReceived";
        case CriteriaType::AbandonAnyQuest:
            return "AbandonAnyQuest";
        case CriteriaType::BuyTaxi:
            return "BuyTaxi";
        case CriteriaType::GetLootByType:
            return "GetLootByType";
        case CriteriaType::LandTargetedSpellOnTarget:
            return "LandTargetedSpellOnTarget";
        case CriteriaType::LearnTradeskillSkillLine:
            return "LearnTradeskillSkillLine";
        case CriteriaType::HonorableKills:
            return "HonorableKills";
        case CriteriaType::AcceptSummon:
            return "AcceptSummon";
        case CriteriaType::EarnAchievementPoints:
            return "EarnAchievementPoints";
        case CriteriaType::RollDisenchant:
            return "RollDisenchant";
        case CriteriaType::RollAnyDisenchant:
            return "RollAnyDisenchant";
        case CriteriaType::CompletedLFGDungeon:
            return "CompletedLFGDungeon";
        case CriteriaType::CompletedLFGDungeonWithStrangers:
            return "CompletedLFGDungeonWithStrangers";
        case CriteriaType::KickInitiatorInLFGDungeon:
            return "KickInitiatorInLFGDungeon";
        case CriteriaType::KickVoterInLFGDungeon:
            return "KickVoterInLFGDungeon";
        case CriteriaType::KickTargetInLFGDungeon:
            return "KickTargetInLFGDungeon";
        case CriteriaType::AbandonedLFGDungeon:
            return "AbandonedLFGDungeon";
        case CriteriaType::MoneySpentOnGuildRepair:
            return "MoneySpentOnGuildRepair";
        case CriteriaType::GuildAttainedLevel:
            return "GuildAttainedLevel";
        case CriteriaType::CreatedItemsByCastingSpell:
            return "CreatedItemsByCastingSpell";
        case CriteriaType::FishInAnyPool:
            return "FishInAnyPool";
        case CriteriaType::GuildBankTabsPurchased:
            return "GuildBankTabsPurchased";
        case CriteriaType::EarnGuildAchievementPoints:
            return "EarnGuildAchievementPoints";
        case CriteriaType::WinAnyBattleground:
            return "WinAnyBattleground";
        case CriteriaType::ParticipateInAnyBattleground:
            return "ParticipateInAnyBattleground";
        case CriteriaType::EarnBattlegroundRating:
            return "EarnBattlegroundRating";
        case CriteriaType::GuildTabardCreated:
            return "GuildTabardCreated";
        case CriteriaType::CompleteQuestsCountForGuild:
            return "CompleteQuestsCountForGuild";
        case CriteriaType::HonorableKillsForGuild:
            return "HonorableKillsForGuild";
        case CriteriaType::KillAnyCreatureForGuild:
            return "KillAnyCreatureForGuild";
        case CriteriaType::GroupedTankLeftEarlyInLFGDungeon:
            return "GroupedTankLeftEarlyInLFGDungeon";
        case CriteriaType::CompleteGuildChallenge:
            return "CompleteGuildChallenge";
        case CriteriaType::CompleteAnyGuildChallenge:
            return "CompleteAnyGuildChallenge";
        case CriteriaType::MarkedAFKInBattleground:
            return "MarkedAFKInBattleground";
        case CriteriaType::RemovedAFKInBattleground:
            return "RemovedAFKInBattleground";
        case CriteriaType::StartAnyBattleground:
            return "StartAnyBattleground";
        case CriteriaType::CompleteAnyBattleground:
            return "CompleteAnyBattleground";
        case CriteriaType::MarkedSomeoneAFKInBattleground:
            return "MarkedSomeoneAFKInBattleground";
        case CriteriaType::CompletedLFRDungeon:
            return "CompletedLFRDungeon";
        case CriteriaType::AbandonedLFRDungeon:
            return "AbandonedLFRDungeon";
        case CriteriaType::KickInitiatorInLFRDungeon:
            return "KickInitiatorInLFRDungeon";
        case CriteriaType::KickVoterInLFRDungeon:
            return "KickVoterInLFRDungeon";
        case CriteriaType::KickTargetInLFRDungeon:
            return "KickTargetInLFRDungeon";
        case CriteriaType::GroupedTankLeftEarlyInLFRDungeon:
            return "GroupedTankLeftEarlyInLFRDungeon";
        case CriteriaType::CompleteAnyScenario:
            return "CompleteAnyScenario";
        case CriteriaType::CompleteScenario:
            return "CompleteScenario";
        case CriteriaType::EnterAreaTriggerWithActionSet:
            return "EnterAreaTriggerWithActionSet";
        case CriteriaType::LeaveAreaTriggerWithActionSet:
            return "LeaveAreaTriggerWithActionSet";
        case CriteriaType::LearnedNewPet:
            return "LearnedNewPet";
        case CriteriaType::UniquePetsOwned:
            return "UniquePetsOwned";
        case CriteriaType::AccountObtainPetThroughBattle:
            return "AccountObtainPetThroughBattle";
        case CriteriaType::WinPetBattle:
            return "WinPetBattle";
        case CriteriaType::LosePetBattle:
            return "LosePetBattle";
        case CriteriaType::BattlePetReachLevel:
            return "BattlePetReachLevel";
        case CriteriaType::PlayerObtainPetThroughBattle:
            return "PlayerObtainPetThroughBattle";
        case CriteriaType::ActivelyEarnPetLevel:
            return "ActivelyEarnPetLevel";
        case CriteriaType::EnterArea:
            return "EnterArea";
        case CriteriaType::LeaveArea:
            return "LeaveArea";
        case CriteriaType::DefeatDungeonEncounter:
            return "DefeatDungeonEncounter";
        case CriteriaType::PlaceAnyGarrisonBuilding:
            return "PlaceAnyGarrisonBuilding";
        case CriteriaType::PlaceGarrisonBuilding:
            return "PlaceGarrisonBuilding";
        case CriteriaType::ActivateAnyGarrisonBuilding:
            return "ActivateAnyGarrisonBuilding";
        case CriteriaType::ActivateGarrisonBuilding:
            return "ActivateGarrisonBuilding";
        case CriteriaType::UpgradeGarrison:
            return "UpgradeGarrison";
        case CriteriaType::StartAnyGarrisonMissionWithFollowerType:
            return "StartAnyGarrisonMissionWithFollowerType";
        case CriteriaType::StartGarrisonMission:
            return "StartGarrisonMission";
        case CriteriaType::SucceedAnyGarrisonMissionWithFollowerType:
            return "SucceedAnyGarrisonMissionWithFollowerType";
        case CriteriaType::SucceedGarrisonMission:
            return "SucceedGarrisonMission";
        case CriteriaType::RecruitAnyGarrisonFollower:
            return "RecruitAnyGarrisonFollower";
        case CriteriaType::RecruitGarrisonFollower:
            return "RecruitGarrisonFollower";
        case CriteriaType::AcquireGarrison:
            return "AcquireGarrison";
        case CriteriaType::LearnAnyGarrisonBlueprint:
            return "LearnAnyGarrisonBlueprint";
        case CriteriaType::LearnGarrisonBlueprint:
            return "LearnGarrisonBlueprint";
        case CriteriaType::LearnAnyGarrisonSpecialization:
            return "LearnAnyGarrisonSpecialization";
        case CriteriaType::LearnGarrisonSpecialization:
            return "LearnGarrisonSpecialization";
        case CriteriaType::CollectGarrisonShipment:
            return "CollectGarrisonShipment";
        case CriteriaType::ItemLevelChangedForGarrisonFollower:
            return "ItemLevelChangedForGarrisonFollower";
        case CriteriaType::LevelChangedForGarrisonFollower:
            return "LevelChangedForGarrisonFollower";
        case CriteriaType::LearnToy:
            return "LearnToy";
        case CriteriaType::LearnAnyToy:
            return "LearnAnyToy";
        case CriteriaType::QualityUpgradedForGarrisonFollower:
            return "QualityUpgradedForGarrisonFollower";
        case CriteriaType::LearnHeirloom:
            return "LearnHeirloom";
        case CriteriaType::LearnAnyHeirloom:
            return "LearnAnyHeirloom";
        case CriteriaType::EarnArtifactXP:
            return "EarnArtifactXP";
        case CriteriaType::AnyArtifactPowerRankPurchased:
            return "AnyArtifactPowerRankPurchased";
        case CriteriaType::LearnTransmog:
            return "LearnTransmog";
        case CriteriaType::LearnAnyTransmog:
            return "LearnAnyTransmog";
        case CriteriaType::HonorLevelIncrease:
            return "HonorLevelIncrease";
        case CriteriaType::PrestigeLevelIncrease:
            return "PrestigeLevelIncrease";
        case CriteriaType::ActivelyReachLevel:
            return "ActivelyReachLevel";
        case CriteriaType::CompleteResearchAnyGarrisonTalent:
            return "CompleteResearchAnyGarrisonTalent";
        case CriteriaType::CompleteResearchGarrisonTalent:
            return "CompleteResearchGarrisonTalent";
        case CriteriaType::LearnAnyTransmogInSlot:
            return "LearnAnyTransmogInSlot";
        case CriteriaType::RecruitAnyGarrisonTroop:
            return "RecruitAnyGarrisonTroop";
        case CriteriaType::StartResearchAnyGarrisonTalent:
            return "StartResearchAnyGarrisonTalent";
        case CriteriaType::StartResearchGarrisonTalent:
            return "StartResearchGarrisonTalent";
        case CriteriaType::CompleteAnyWorldQuest:
            return "CompleteAnyWorldQuest";
        case CriteriaType::EarnLicense:
            return "EarnLicense";
        case CriteriaType::CollectTransmogSetFromGroup:
            return "CollectTransmogSetFromGroup";
        case CriteriaType::ParagonLevelIncreaseWithFaction:
            return "ParagonLevelIncreaseWithFaction";
        case CriteriaType::PlayerHasEarnedHonor:
            return "PlayerHasEarnedHonor";
        case CriteriaType::KillCreatureScenario:
            return "KillCreatureScenario";
        case CriteriaType::ArtifactPowerRankPurchased:
            return "ArtifactPowerRankPurchased";
        case CriteriaType::ChooseAnyRelicTalent:
            return "ChooseAnyRelicTalent";
        case CriteriaType::ChooseRelicTalent:
            return "ChooseRelicTalent";
        case CriteriaType::EarnExpansionLevel:
            return "EarnExpansionLevel";
        case CriteriaType::AccountHonorLevelReached:
            return "AccountHonorLevelReached";
        case CriteriaType::EarnArtifactXPForAzeriteItem:
            return "EarnArtifactXPForAzeriteItem";
        case CriteriaType::AzeriteLevelReached:
            return "AzeriteLevelReached";
        case CriteriaType::MythicPlusCompleted:
            return "MythicPlusCompleted";
        case CriteriaType::ScenarioGroupCompleted:
            return "ScenarioGroupCompleted";
        case CriteriaType::CompleteAnyReplayQuest:
            return "CompleteAnyReplayQuest";
        case CriteriaType::BuyItemsFromVendors:
            return "BuyItemsFromVendors";
        case CriteriaType::SellItemsToVendors:
            return "SellItemsToVendors";
        case CriteriaType::ReachMaxLevel:
            return "ReachMaxLevel";
        case CriteriaType::MemorizeSpell:
            return "MemorizeSpell";
        case CriteriaType::LearnTransmogIllusion:
            return "LearnTransmogIllusion";
        case CriteriaType::LearnAnyTransmogIllusion:
            return "LearnAnyTransmogIllusion";
        case CriteriaType::EnterTopLevelArea:
            return "EnterTopLevelArea";
        case CriteriaType::LeaveTopLevelArea:
            return "LeaveTopLevelArea";
        case CriteriaType::SocketGarrisonTalent:
            return "SocketGarrisonTalent";
        case CriteriaType::SocketAnySoulbindConduit:
            return "SocketAnySoulbindConduit";
        case CriteriaType::ObtainAnyItemWithCurrencyValue:
            return "ObtainAnyItemWithCurrencyValue";
        case CriteriaType::MythicPlusRatingAttained:
            return "MythicPlusRatingAttained";
        case CriteriaType::SpentTalentPoint:
            return "SpentTalentPoint";
        case CriteriaType::MythicPlusDisplaySeasonEnded:
            return "MythicPlusDisplaySeasonEnded";
        case CriteriaType::WinRatedSoloShuffleRound:
            return "WinRatedSoloShuffleRound";
        case CriteriaType::ParticipateInRatedSoloShuffleRound:
            return "ParticipateInRatedSoloShuffleRound";
        case CriteriaType::ReputationAmountGained:
            return "ReputationAmountGained";
        case CriteriaType::FulfillAnyCraftingOrder:
            return "FulfillAnyCraftingOrder";
        case CriteriaType::FulfillCraftingOrderType:
            return "FulfillCraftingOrderType";
        case CriteriaType::PerksProgramMonthComplete:
            return "PerksProgramMonthComplete";
        case CriteriaType::CompleteTrackingQuest:
            return "CompleteTrackingQuest";
        case CriteriaType::GainLevels:
            return "GainLevels";
        default:
            return "MissingType";
    }
}

CriteriaMgr* CriteriaMgr::Instance()
{
    static CriteriaMgr instance;
    return &instance;
}

namespace
{
inline bool IsCriteriaTypeStoredByAsset(CriteriaType type)
{
    switch (type)
    {
        case CriteriaType::KillCreature:
        case CriteriaType::WinBattleground:
        case CriteriaType::SkillRaised:
        case CriteriaType::EarnAchievement:
        case CriteriaType::CompleteQuestsInZone:
        case CriteriaType::ParticipateInBattleground:
        case CriteriaType::KilledByCreature:
        case CriteriaType::CompleteQuest:
        case CriteriaType::BeSpellTarget:
        case CriteriaType::CastSpell:
        case CriteriaType::TrackedWorldStateUIModified:
        case CriteriaType::PVPKillInArea:
        case CriteriaType::LearnOrKnowSpell:
        case CriteriaType::AcquireItem:
        case CriteriaType::AchieveSkillStep:
        case CriteriaType::UseItem:
        case CriteriaType::LootItem:
        case CriteriaType::RevealWorldMapOverlay:
        case CriteriaType::ReputationGained:
        case CriteriaType::EquipItemInSlot:
        case CriteriaType::DeliverKillingBlowToClass:
        case CriteriaType::DeliverKillingBlowToRace:
        case CriteriaType::DoEmote:
        case CriteriaType::EquipItem:
        case CriteriaType::UseGameobject:
        case CriteriaType::GainAura:
        case CriteriaType::CatchFishInFishingHole:
        case CriteriaType::LearnSpellFromSkillLine:
        case CriteriaType::DefeatDungeonEncounterWhileElegibleForLoot:
        case CriteriaType::GetLootByType:
        case CriteriaType::LandTargetedSpellOnTarget:
        case CriteriaType::LearnTradeskillSkillLine:
        case CriteriaType::DefeatDungeonEncounter:
            return true;
        default:
            break;
    }
    return false;
}
}

CriteriaList const& CriteriaMgr::GetPlayerCriteriaByType(CriteriaType type, uint32 asset) const
{
    if (asset && IsCriteriaTypeStoredByAsset(type))
    {
        auto itr = _criteriasByAsset[size_t(type)].find(asset);
        if (itr != _criteriasByAsset[size_t(type)].end())
            return itr->second;

        return EmptyCriteriaList;
    }

    return _criteriasByType[size_t(type)];
}

CriteriaList const& CriteriaMgr::GetScenarioCriteriaByTypeAndScenario(CriteriaType type, uint32 scenarioId) const
{
    if (CriteriaList const* criteriaList = Trinity::Containers::MapGetValuePtr(_scenarioCriteriasByTypeAndScenarioId[size_t(type)], scenarioId))
        return *criteriaList;

    return EmptyCriteriaList;
}

std::unordered_map<int32, CriteriaList> const& CriteriaMgr::GetCriteriaByStartEvent(CriteriaStartEvent startEvent) const
{
    return _criteriasByStartEvent[size_t(startEvent)];
}

CriteriaList const* CriteriaMgr::GetCriteriaByStartEvent(CriteriaStartEvent startEvent, int32 asset) const
{
    return Trinity::Containers::MapGetValuePtr(_criteriasByStartEvent[size_t(startEvent)], asset);
}

std::unordered_map<int32, CriteriaList> const& CriteriaMgr::GetCriteriaByFailEvent(CriteriaFailEvent failEvent) const
{
    return _criteriasByFailEvent[size_t(failEvent)];
}

CriteriaList const* CriteriaMgr::GetCriteriaByFailEvent(CriteriaFailEvent failEvent, int32 asset) const
{
    return Trinity::Containers::MapGetValuePtr(_criteriasByFailEvent[size_t(failEvent)], asset);
}

CriteriaMgr::CriteriaMgr() = default;

//==========================================================
CriteriaMgr::~CriteriaMgr()
{
    for (std::pair<uint32 const, CriteriaTree*>& criteriaTree : _criteriaTrees)
        delete criteriaTree.second;

    for (std::pair<uint32 const, Criteria*>& criteria : _criteria)
        delete criteria.second;

    for (std::pair<uint32 const, ModifierTreeNode*>& criteriaModifier : _criteriaModifiers)
        delete criteriaModifier.second;
}

void CriteriaMgr::LoadCriteriaModifiersTree()
{
    uint32 oldMSTime = getMSTime();

    if (sModifierTreeStore.GetNumRows() == 0)
    {
        TC_LOG_ERROR("server.loading", ">> Loaded 0 criteria modifiers.");
        return;
    }

    // Load modifier tree nodes
    for (uint32 i = 0; i < sModifierTreeStore.GetNumRows(); ++i)
    {
        ModifierTreeEntry const* tree = sModifierTreeStore.LookupEntry(i);
        if (!tree)
            continue;

        ModifierTreeNode* node = new ModifierTreeNode();
        node->Entry = tree;
        _criteriaModifiers[node->Entry->ID] = node;
    }

    // Build tree
    for (std::pair<uint32 const, ModifierTreeNode*>& criteriaModifier : _criteriaModifiers)
        if (ModifierTreeNode* parentNode = Trinity::Containers::MapGetValuePtr(_criteriaModifiers, criteriaModifier.second->Entry->Parent))
            parentNode->Children.push_back(criteriaModifier.second);

    TC_LOG_INFO("server.loading", ">> Loaded {} criteria modifiers in {} ms", uint32(_criteriaModifiers.size()), GetMSTimeDiffToNow(oldMSTime));
}

template<typename T>
T GetEntry(std::unordered_map<uint32, T> const& map, CriteriaTreeEntry const* tree)
{
    CriteriaTreeEntry const* cur = tree;
    auto itr = map.find(tree->ID);
    while (itr == map.end())
    {
        if (!cur->Parent)
            break;

        cur = sCriteriaTreeStore.LookupEntry(cur->Parent);
        if (!cur)
            break;

        itr = map.find(cur->ID);
    }

    if (itr == map.end())
        return nullptr;

    return itr->second;
};

void CriteriaMgr::LoadCriteriaList()
{
    uint32 oldMSTime = getMSTime();

    std::unordered_map<uint32 /*criteriaTreeID*/, AchievementEntry const*> achievementCriteriaTreeIds;
    for (AchievementEntry const* achievement : sAchievementStore)
        if (achievement->CriteriaTree)
            achievementCriteriaTreeIds[achievement->CriteriaTree] = achievement;

    std::unordered_map<uint32 /*criteriaTreeID*/, ScenarioStepEntry const*> scenarioCriteriaTreeIds;
    for (ScenarioStepEntry const* scenarioStep : sScenarioStepStore)
        if (scenarioStep->Criteriatreeid)
            scenarioCriteriaTreeIds[scenarioStep->Criteriatreeid] = scenarioStep;

    std::unordered_map<uint32 /*criteriaTreeID*/, QuestObjective const*> questObjectiveCriteriaTreeIds;
    for (auto const& [questId, quest] : sObjectMgr->GetQuestTemplates())
    {
        for (QuestObjective const& objective : quest->Objectives)
        {
            if (objective.Type != QUEST_OBJECTIVE_CRITERIA_TREE)
                continue;

            if (objective.ObjectID)
                questObjectiveCriteriaTreeIds[objective.ObjectID] = &objective;
        }
    }

    // Load criteria tree nodes
    for (CriteriaTreeEntry const* tree : sCriteriaTreeStore)
    {
        // Find linked achievement
        AchievementEntry const* achievement = GetEntry(achievementCriteriaTreeIds, tree);
        ScenarioStepEntry const* scenarioStep = GetEntry(scenarioCriteriaTreeIds, tree);
        QuestObjective const* questObjective = GetEntry(questObjectiveCriteriaTreeIds, tree);
        if (!achievement && !scenarioStep && !questObjective)
            continue;

        CriteriaTree* criteriaTree = new CriteriaTree();
        criteriaTree->ID = tree->ID;
        criteriaTree->Achievement = achievement;
        criteriaTree->ScenarioStep = scenarioStep;
        criteriaTree->QuestObjective = questObjective;
        criteriaTree->Entry = tree;

        _criteriaTrees[criteriaTree->Entry->ID] = criteriaTree;
    }

    // Build tree
    for (std::pair<uint32 const, CriteriaTree*> const& criteriaTree : _criteriaTrees)
    {
        if (CriteriaTree* parent = Trinity::Containers::MapGetValuePtr(_criteriaTrees, criteriaTree.second->Entry->Parent))
            parent->Children.push_back(criteriaTree.second);

        if (sCriteriaStore.HasRecord(criteriaTree.second->Entry->CriteriaID))
            _criteriaTreeByCriteria[criteriaTree.second->Entry->CriteriaID].push_back(criteriaTree.second);
    }

    // Load criteria
    uint32 criterias = 0;
    uint32 guildCriterias = 0;
    uint32 scenarioCriterias = 0;
    uint32 questObjectiveCriterias = 0;
    for (CriteriaEntry const* criteriaEntry : sCriteriaStore)
    {
        ASSERT(criteriaEntry->Type < AsUnderlyingType(CriteriaType::Count), "CriteriaType::Count must be greater than or equal to %u but is currently equal to %u",
            criteriaEntry->Type + 1, uint32(CriteriaType::Count));
        ASSERT(criteriaEntry->StartEvent < AsUnderlyingType(CriteriaStartEvent::Count), "CriteriaStartEvent::Count must be greater than or equal to %u but is currently equal to %u",
            criteriaEntry->StartEvent + 1, uint32(CriteriaStartEvent::Count));
        ASSERT(criteriaEntry->FailEvent < AsUnderlyingType(CriteriaFailEvent::Count), "CriteriaFailEvent::Count must be greater than or equal to %u but is currently equal to %u",
            criteriaEntry->FailEvent + 1, uint32(CriteriaFailEvent::Count));

        auto treeItr = _criteriaTreeByCriteria.find(criteriaEntry->ID);
        if (treeItr == _criteriaTreeByCriteria.end())
            continue;

        Criteria* criteria = new Criteria();
        criteria->ID = criteriaEntry->ID;
        criteria->Entry = criteriaEntry;
        criteria->Modifier = Trinity::Containers::MapGetValuePtr(_criteriaModifiers, criteriaEntry->ModifierTreeId);

        _criteria[criteria->ID] = criteria;

        std::vector<uint32> scenarioIds;

        for (CriteriaTree const* tree : treeItr->second)
        {
            const_cast<CriteriaTree*>(tree)->Criteria = criteria;

            if (AchievementEntry const* achievement = tree->Achievement)
            {
                if (achievement->Flags & ACHIEVEMENT_FLAG_GUILD)
                    criteria->FlagsCu |= CRITERIA_FLAG_CU_GUILD;
                else if (achievement->Flags & ACHIEVEMENT_FLAG_ACCOUNT)
                    criteria->FlagsCu |= CRITERIA_FLAG_CU_ACCOUNT;
                else
                    criteria->FlagsCu |= CRITERIA_FLAG_CU_PLAYER;
            }
            else if (tree->ScenarioStep)
            {
                criteria->FlagsCu |= CRITERIA_FLAG_CU_SCENARIO;
                scenarioIds.push_back(tree->ScenarioStep->ScenarioID);
            }
            else if (tree->QuestObjective)
                criteria->FlagsCu |= CRITERIA_FLAG_CU_QUEST_OBJECTIVE;
        }

        if (criteria->FlagsCu & (CRITERIA_FLAG_CU_PLAYER | CRITERIA_FLAG_CU_ACCOUNT))
        {
            ++criterias;
            _criteriasByType[criteriaEntry->Type].push_back(criteria);
            if (IsCriteriaTypeStoredByAsset(CriteriaType(criteriaEntry->Type)))
            {
                if (CriteriaType(criteriaEntry->Type) != CriteriaType::RevealWorldMapOverlay)
                    _criteriasByAsset[criteriaEntry->Type][criteriaEntry->Asset.ID].push_back(criteria);
                else
                {
                    WorldMapOverlayEntry const* worldOverlayEntry = sWorldMapOverlayStore.LookupEntry(criteriaEntry->Asset.WorldMapOverlayID);
                    if (!worldOverlayEntry)
                        break;

                    for (uint8 j = 0; j < MAX_WORLD_MAP_OVERLAY_AREA_IDX; ++j)
                    {
                        if (worldOverlayEntry->AreaID[j])
                        {
                            bool valid = true;
                            for (uint8 i = 0; i < j; ++i)
                                if (worldOverlayEntry->AreaID[j] == worldOverlayEntry->AreaID[i])
                                    valid = false;
                            if (valid)
                                _criteriasByAsset[criteriaEntry->Type][worldOverlayEntry->AreaID[j]].push_back(criteria);
                        }
                    }
                }
            }
        }

        if (criteria->FlagsCu & CRITERIA_FLAG_CU_GUILD)
        {
            ++guildCriterias;
            _guildCriteriasByType[criteriaEntry->Type].push_back(criteria);
        }

        if (criteria->FlagsCu & CRITERIA_FLAG_CU_SCENARIO)
        {
            ++scenarioCriterias;
            for (uint32 scenarioId : scenarioIds)
                _scenarioCriteriasByTypeAndScenarioId[criteriaEntry->Type][scenarioId].push_back(criteria);
        }

        if (criteria->FlagsCu & CRITERIA_FLAG_CU_QUEST_OBJECTIVE)
        {
            ++questObjectiveCriterias;
            _questObjectiveCriteriasByType[criteriaEntry->Type].push_back(criteria);
        }

        if (criteriaEntry->StartEvent)
            _criteriasByStartEvent[criteriaEntry->StartEvent][criteriaEntry->StartAsset].push_back(criteria);

        if (criteriaEntry->FailEvent)
            _criteriasByFailEvent[criteriaEntry->FailEvent][criteriaEntry->FailAsset].push_back(criteria);
    }

    TC_LOG_INFO("server.loading", ">> Loaded {} criteria, {} guild criteria, {} scenario criteria and {} quest objective criteria in {} ms.", criterias, guildCriterias, scenarioCriterias, questObjectiveCriterias, GetMSTimeDiffToNow(oldMSTime));
}

void CriteriaMgr::LoadCriteriaData()
{
    uint32 oldMSTime = getMSTime();

    _criteriaDataMap.clear();                              // need for reload case

    QueryResult result = WorldDatabase.Query("SELECT criteria_id, type, value1, value2, ScriptName FROM criteria_data");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 additional criteria data. DB table `criteria_data` is empty.");
        return;
    }

    uint32 count = 0;

    do
    {
        Field* fields = result->Fetch();
        uint32 criteria_id = fields[0].GetUInt32();

        Criteria const* criteria = GetCriteria(criteria_id);

        if (!criteria)
        {
            TC_LOG_ERROR("sql.sql", "Table `criteria_data` contains data for non-existing criteria (Entry: {}). Ignored.", criteria_id);
            continue;
        }

        uint32 dataType = fields[1].GetUInt8();
        std::string scriptName = fields[4].GetString();
        uint32 scriptId = 0;
        if (!scriptName.empty())
        {
            if (dataType != CRITERIA_DATA_TYPE_SCRIPT)
                TC_LOG_ERROR("sql.sql", "Table `criteria_data` contains a ScriptName for non-scripted data type (Entry: {}, type {}), useless data.", criteria_id, dataType);
            else
                scriptId = sObjectMgr->GetScriptId(scriptName);
        }

        CriteriaData data(dataType, fields[2].GetUInt32(), fields[3].GetUInt32(), scriptId);

        if (!data.IsValid(criteria))
            continue;

        // this will allocate empty data set storage
        CriteriaDataSet& dataSet = _criteriaDataMap[criteria_id];
        dataSet.SetCriteriaId(criteria_id);

        // add real data only for not NONE data types
        if (data.DataType != CRITERIA_DATA_TYPE_NONE)
            dataSet.Add(data);

        // counting data by and data types
        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} additional criteria data in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

CriteriaTree const* CriteriaMgr::GetCriteriaTree(uint32 criteriaTreeId) const
{
    auto itr = _criteriaTrees.find(criteriaTreeId);
    if (itr == _criteriaTrees.end())
        return nullptr;

    return itr->second;
}

Criteria const* CriteriaMgr::GetCriteria(uint32 criteriaId) const
{
    auto itr = _criteria.find(criteriaId);
    if (itr == _criteria.end())
        return nullptr;

    return itr->second;
}

ModifierTreeNode const* CriteriaMgr::GetModifierTree(uint32 modifierTreeId) const
{
    auto itr = _criteriaModifiers.find(modifierTreeId);
    if (itr != _criteriaModifiers.end())
        return itr->second;

    return nullptr;
}
