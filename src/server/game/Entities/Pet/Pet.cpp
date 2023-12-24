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

#include "Pet.h"
#include "Common.h"
#include "DatabaseEnv.h"
#include "DB2Stores.h"
#include "Group.h"
#include "InstanceScript.h"
#include "Log.h"
#include "Map.h"
#include "ObjectMgr.h"
#include "PetPackets.h"
#include "PhasingHandler.h"
#include "Player.h"
#include "QueryHolder.h"
#include "Spell.h"
#include "SpellAuraEffects.h"
#include "SpellAuras.h"
#include "SpellHistory.h"
#include "SpellMgr.h"
#include "SpellPackets.h"
#include "Unit.h"
#include "Util.h"
#include "World.h"
#include "WorldSession.h"
#include <sstream>

#define PET_XP_FACTOR 0.05f

Pet::Pet(Player* owner, PetType type) :
    Guardian(nullptr, owner, true), m_removed(false),
    m_petType(type), m_duration(0), m_loading(false), m_groupUpdateMask(0),
    m_petSpecialization(0)
{
    ASSERT(GetOwner());

    m_unitTypeMask |= UNIT_MASK_PET;
    if (type == HUNTER_PET)
        m_unitTypeMask |= UNIT_MASK_HUNTER_PET;

    if (!(m_unitTypeMask & UNIT_MASK_CONTROLABLE_GUARDIAN))
    {
        m_unitTypeMask |= UNIT_MASK_CONTROLABLE_GUARDIAN;
        InitCharmInfo();
    }

    m_name = "Pet";
    m_focusRegenTimer = PET_FOCUS_REGEN_INTERVAL;
}

Pet::~Pet() = default;

void Pet::AddToWorld()
{
    ///- Register the pet for guid lookup
    if (!IsInWorld())
    {
        ///- Register the pet for guid lookup
        GetMap()->GetObjectsStore().Insert<Pet>(GetGUID(), this);
        Unit::AddToWorld();
        AIM_Initialize();
        if (ZoneScript* zoneScript = GetZoneScript() ? GetZoneScript() : GetInstanceScript())
            zoneScript->OnCreatureCreate(this);
    }

    // Prevent stuck pets when zoning. Pets default to "follow" when added to world
    // so we'll reset flags and let the AI handle things
    if (GetCharmInfo() && GetCharmInfo()->HasCommandState(COMMAND_FOLLOW))
    {
        GetCharmInfo()->SetIsCommandAttack(false);
        GetCharmInfo()->SetIsCommandFollow(false);
        GetCharmInfo()->SetIsAtStay(false);
        GetCharmInfo()->SetIsFollowing(false);
        GetCharmInfo()->SetIsReturning(false);
    }
}

void Pet::RemoveFromWorld()
{
    ///- Remove the pet from the accessor
    if (IsInWorld())
    {
        ///- Don't call the function for Creature, normal mobs + totems go in a different storage
        Unit::RemoveFromWorld();
        GetMap()->GetObjectsStore().Remove<Pet>(GetGUID());
    }
}

std::pair<PetStable::PetInfo const*, PetSaveMode> Pet::GetLoadPetInfo(PetStable const& stable, uint32 petEntry, uint32 petnumber, Optional<PetSaveMode> slot)
{
    if (petnumber)
    {
        // Known petnumber entry
        for (std::size_t activeSlot = 0; activeSlot < stable.ActivePets.size(); ++activeSlot)
            if (stable.ActivePets[activeSlot] && stable.ActivePets[activeSlot]->PetNumber == petnumber)
                return { &stable.ActivePets[activeSlot].value(), PetSaveMode(PET_SAVE_FIRST_ACTIVE_SLOT + activeSlot) };

        for (std::size_t stableSlot = 0; stableSlot < stable.StabledPets.size(); ++stableSlot)
            if (stable.StabledPets[stableSlot] && stable.StabledPets[stableSlot]->PetNumber == petnumber)
                return { &stable.StabledPets[stableSlot].value(), PetSaveMode(PET_SAVE_FIRST_STABLE_SLOT + stableSlot) };

        for (PetStable::PetInfo const& pet : stable.UnslottedPets)
            if (pet.PetNumber == petnumber)
                return { &pet, PET_SAVE_NOT_IN_SLOT };
    }
    else if (slot)
    {
        // Current pet
        if (slot == PET_SAVE_AS_CURRENT)
            if (stable.GetCurrentActivePetIndex() && stable.ActivePets[*stable.GetCurrentActivePetIndex()])
                return { &stable.ActivePets[*stable.GetCurrentActivePetIndex()].value(), PetSaveMode(*stable.GetCurrentActivePetIndex()) };

        if (slot >= PET_SAVE_FIRST_ACTIVE_SLOT && slot < PET_SAVE_LAST_ACTIVE_SLOT)
            if (stable.ActivePets[*slot])
                return { &stable.ActivePets[*slot].value(), *slot };

        if (slot >= PET_SAVE_FIRST_STABLE_SLOT && slot < PET_SAVE_LAST_STABLE_SLOT)
            if (stable.StabledPets[*slot])
                return { &stable.StabledPets[*slot].value(), *slot };
    }
    else if (petEntry)
    {
        // known petEntry entry (unique for summoned pet, but non unique for hunter pet (only from current or not stabled pets)
        for (PetStable::PetInfo const& pet : stable.UnslottedPets)
            if (pet.CreatureId == petEntry)
                return { &pet, PET_SAVE_NOT_IN_SLOT };
    }
    else
    {
        // Any current or other non-stabled pet (for hunter "call pet")
        if (stable.ActivePets[0])
            return { &stable.ActivePets[0].value(), PET_SAVE_FIRST_ACTIVE_SLOT };

        if (!stable.UnslottedPets.empty())
            return { &stable.UnslottedPets.front(), PET_SAVE_NOT_IN_SLOT };
    }

    return { nullptr, PET_SAVE_AS_DELETED };
}

class PetLoadQueryHolder : public CharacterDatabaseQueryHolder
{
public:
    enum
    {
        DECLINED_NAMES,
        AURAS,
        AURA_EFFECTS,
        SPELLS,
        COOLDOWNS,
        CHARGES,

        MAX
    };

    PetLoadQueryHolder(ObjectGuid::LowType ownerGuid, uint32 petNumber)
    {
        SetSize(MAX);

        CharacterDatabasePreparedStatement* stmt;

        stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_PET_DECLINED_NAME);
        stmt->setUInt64(0, ownerGuid);
        stmt->setUInt32(1, petNumber);
        SetPreparedQuery(DECLINED_NAMES, stmt);

        stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_PET_AURA);
        stmt->setUInt32(0, petNumber);
        SetPreparedQuery(AURAS, stmt);

        stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_PET_AURA_EFFECT);
        stmt->setUInt32(0, petNumber);
        SetPreparedQuery(AURA_EFFECTS, stmt);

        stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_PET_SPELL);
        stmt->setUInt32(0, petNumber);
        SetPreparedQuery(SPELLS, stmt);

        stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_PET_SPELL_COOLDOWN);
        stmt->setUInt32(0, petNumber);
        SetPreparedQuery(COOLDOWNS, stmt);

        stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_PET_SPELL_CHARGES);
        stmt->setUInt32(0, petNumber);
        SetPreparedQuery(CHARGES, stmt);
    }
};

bool Pet::LoadPetFromDB(Player* owner, uint32 petEntry, uint32 petnumber, bool current, Optional<PetSaveMode> forcedSlot /*= {}*/)
{
    m_loading = true;

    PetStable* petStable = ASSERT_NOTNULL(owner->GetPetStable());

    ObjectGuid::LowType ownerid = owner->GetGUID().GetCounter();
    std::pair<PetStable::PetInfo const*, PetSaveMode> info = GetLoadPetInfo(*petStable, petEntry, petnumber, forcedSlot);
    PetStable::PetInfo const* petInfo = info.first;
    PetSaveMode slot = info.second;
    if (!petInfo || (slot >= PET_SAVE_FIRST_STABLE_SLOT && slot < PET_SAVE_LAST_STABLE_SLOT))
    {
        m_loading = false;
        return false;
    }

    // Don't try to reload the current pet
    if (petStable->GetCurrentPet() && owner->GetPet() && petStable->GetCurrentPet()->PetNumber == petInfo->PetNumber)
        return false;

    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(petInfo->CreatedBySpellId, owner->GetMap()->GetDifficultyID());

    bool isTemporarySummon = spellInfo && spellInfo->GetDuration() > 0;
    if (current && isTemporarySummon)
        return false;

    if (petInfo->Type == HUNTER_PET)
    {
        CreatureTemplate const* creatureInfo = sObjectMgr->GetCreatureTemplate(petInfo->CreatureId);
        if (!creatureInfo)
            return false;

        CreatureDifficulty const* creatureDifficulty = creatureInfo->GetDifficulty(DIFFICULTY_NONE);
        if (!creatureDifficulty || !creatureInfo->IsTameable(owner->CanTameExoticPets(), creatureDifficulty))
            return false;
    }

    if (current && owner->IsPetNeedBeTemporaryUnsummoned())
    {
        owner->SetTemporaryUnsummonedPetNumber(petInfo->PetNumber);
        return false;
    }

    owner->SetTemporaryUnsummonedPetNumber(0);

    Map* map = owner->GetMap();
    ObjectGuid::LowType guid = map->GenerateLowGuid<HighGuid::Pet>();

    if (!Create(guid, map, petInfo->CreatureId, petInfo->PetNumber))
        return false;

    PhasingHandler::InheritPhaseShift(this, owner);

    setPetType(petInfo->Type);
    SetFaction(owner->GetFaction());
    SetCreatedBySpell(petInfo->CreatedBySpellId);

    if (IsCritter())
    {
        float px, py, pz;
        owner->GetClosePoint(px, py, pz, GetCombatReach(), PET_FOLLOW_DIST, GetFollowAngle());
        Relocate(px, py, pz, owner->GetOrientation());

        if (!IsPositionValid())
        {
            TC_LOG_ERROR("entities.pet", "Pet{} not loaded. Suggested coordinates isn't valid (X: {} Y: {})",
                GetGUID().ToString(), GetPositionX(), GetPositionY());
            return false;
        }

        map->AddToMap(ToCreature());
        return true;
    }

    m_charmInfo->SetPetNumber(petInfo->PetNumber, IsPermanentPetFor(owner));

    SetDisplayId(petInfo->DisplayId, true);
    uint8 petlevel = petInfo->Level;
    ReplaceAllNpcFlags(UNIT_NPC_FLAG_NONE);
    ReplaceAllNpcFlags2(UNIT_NPC_FLAG_2_NONE);
    SetName(petInfo->Name);

    switch (getPetType())
    {
        case SUMMON_PET:
            petlevel = owner->GetLevel();
            SetClass(CLASS_MAGE);
            ReplaceAllUnitFlags(UNIT_FLAG_PLAYER_CONTROLLED); // this enables popup window (pet dismiss, cancel)
            break;
        case HUNTER_PET:
            SetClass(CLASS_WARRIOR);
            SetGender(GENDER_NONE);
            SetSheath(SHEATH_STATE_MELEE);
            ReplaceAllPetFlags(petInfo->WasRenamed ? UNIT_PET_FLAG_CAN_BE_ABANDONED : (UNIT_PET_FLAG_CAN_BE_RENAMED | UNIT_PET_FLAG_CAN_BE_ABANDONED));
            ReplaceAllUnitFlags(UNIT_FLAG_PLAYER_CONTROLLED); // this enables popup window (pet abandon, cancel)
            break;
        default:
            if (!IsPetGhoul())
                TC_LOG_ERROR("entities.pet", "Pet have incorrect type ({}) for pet loading.", getPetType());
            break;
    }

    SetPetNameTimestamp(uint32(GameTime::GetGameTime()));
    SetCreatorGUID(owner->GetGUID());

    InitStatsForLevel(petlevel);
    SetPetExperience(petInfo->Experience);

    SynchronizeLevelWithOwner();

    // Set pet's position after setting level, its size depends on it
    float px, py, pz;
    owner->GetClosePoint(px, py, pz, GetCombatReach(), PET_FOLLOW_DIST, GetFollowAngle());
    Relocate(px, py, pz, owner->GetOrientation());
    if (!IsPositionValid())
    {
        TC_LOG_ERROR("entities.pet", "Pet {} not loaded. Suggested coordinates isn't valid (X: {} Y: {})",
            GetGUID().ToString(), GetPositionX(), GetPositionY());
        return false;
    }

    SetReactState(petInfo->ReactState);
    SetCanModifyStats(true);

    if (getPetType() == SUMMON_PET && !current)              //all (?) summon pets come with full health when called, but not when they are current
        SetFullPower(POWER_MANA);
    else
    {
        uint32 savedhealth = petInfo->Health;
        uint32 savedmana = petInfo->Mana;
        if (!savedhealth && getPetType() == HUNTER_PET)
            setDeathState(JUST_DIED);
        else
        {
            SetHealth(savedhealth);
            SetPower(POWER_MANA, savedmana);
        }
    }

    // set current pet as current
    // 0-4=current
    // PET_SAVE_NOT_IN_SLOT(-1) = not stable slot (summoning))
    if (slot == PET_SAVE_NOT_IN_SLOT)
    {
        uint32 petInfoNumber = petInfo->PetNumber;
        if (petStable->CurrentPetIndex)
            owner->RemovePet(nullptr, PET_SAVE_NOT_IN_SLOT);

        auto unslottedPetItr = std::find_if(petStable->UnslottedPets.begin(), petStable->UnslottedPets.end(), [&](PetStable::PetInfo const& unslottedPet)
        {
            return unslottedPet.PetNumber == petInfoNumber;
        });
        ASSERT(!petStable->CurrentPetIndex);
        ASSERT(unslottedPetItr != petStable->UnslottedPets.end());

        petStable->SetCurrentUnslottedPetIndex(std::distance(petStable->UnslottedPets.begin(), unslottedPetItr));
    }
    else if (PET_SAVE_FIRST_ACTIVE_SLOT <= slot && slot <= PET_SAVE_LAST_ACTIVE_SLOT)
    {
        auto activePetItr = std::find_if(petStable->ActivePets.begin(), petStable->ActivePets.end(), [&](Optional<PetStable::PetInfo> const& pet)
        {
            return pet && pet->PetNumber == petInfo->PetNumber;
        });
        ASSERT(activePetItr != petStable->ActivePets.end());

        uint32 newPetIndex = std::distance(petStable->ActivePets.begin(), activePetItr);

        petStable->SetCurrentActivePetIndex(newPetIndex);
    }

    owner->SetMinion(this, true);

    if (!isTemporarySummon)
        m_charmInfo->LoadPetActionBar(petInfo->ActionBar);

    map->AddToMap(ToCreature());

    //set last used pet number (for use in BG's)
    if (owner->GetTypeId() == TYPEID_PLAYER && isControlled() && !isTemporarySummoned() && (getPetType() == SUMMON_PET || getPetType() == HUNTER_PET))
        owner->ToPlayer()->SetLastPetNumber(petInfo->PetNumber);

    owner->GetSession()->AddQueryHolderCallback(CharacterDatabase.DelayQueryHolder(std::make_shared<PetLoadQueryHolder>(ownerid, petInfo->PetNumber)))
        .AfterComplete([this, owner, session = owner->GetSession(), isTemporarySummon, current, lastSaveTime = petInfo->LastSaveTime, specializationId = petInfo->SpecializationId](SQLQueryHolderBase const& holder)
    {
        if (session->GetPlayer() != owner || owner->GetPet() != this)
            return;

        // passing previous checks ensure that 'this' is still valid
        if (m_removed)
            return;

        uint32 timediff = uint32(GameTime::GetGameTime() - lastSaveTime);
        _LoadAuras(holder.GetPreparedResult(PetLoadQueryHolder::AURAS), holder.GetPreparedResult(PetLoadQueryHolder::AURA_EFFECTS), timediff);

        // load action bar, if data broken will fill later by default spells.
        if (!isTemporarySummon)
        {
            _LoadSpells(holder.GetPreparedResult(PetLoadQueryHolder::SPELLS));
            GetSpellHistory()->LoadFromDB<Pet>(holder.GetPreparedResult(PetLoadQueryHolder::COOLDOWNS), holder.GetPreparedResult(PetLoadQueryHolder::CHARGES));
            LearnPetPassives();
            InitLevelupSpellsForLevel();
            if (GetMap()->IsBattleArena())
                RemoveArenaAuras();

            CastPetAuras(current);
        }

        TC_LOG_DEBUG("entities.pet", "New Pet has {}", GetGUID().ToString());

        uint16 specId = specializationId;
        if (ChrSpecializationEntry const* petSpec = sChrSpecializationStore.LookupEntry(specId))
            specId = sDB2Manager.GetChrSpecializationByIndex(owner->HasAuraType(SPELL_AURA_OVERRIDE_PET_SPECS) ? PET_SPEC_OVERRIDE_CLASS_INDEX : 0, petSpec->OrderIndex)->ID;

        SetSpecialization(specId);

        // The SetSpecialization function will run these functions if the pet's spec is not 0
        if (!GetSpecialization())
        {
            CleanupActionBar();                                     // remove unknown spells from action bar after load

            owner->PetSpellInitialize();
        }

        SetGroupUpdateFlag(GROUP_UPDATE_PET_FULL);

        if (getPetType() == HUNTER_PET)
        {
            if (PreparedQueryResult result = holder.GetPreparedResult(PetLoadQueryHolder::DECLINED_NAMES))
            {
                m_declinedname = std::make_unique<DeclinedName>();
                Field* fields = result->Fetch();
                for (uint8 i = 0; i < MAX_DECLINED_NAME_CASES; ++i)
                    m_declinedname->name[i] = fields[i].GetString();
            }
        }

        if (owner->IsMounted())
            owner->DisablePetControlsOnMount(REACT_PASSIVE, COMMAND_FOLLOW);

        // must be after SetMinion (owner guid check)
        LoadTemplateImmunities();
        m_loading = false;
    });

    return true;
}

void Pet::SavePetToDB(PetSaveMode mode)
{
    if (!GetEntry())
        return;

    // save only fully controlled creature
    if (!isControlled())
        return;

    // not save not player pets
    if (!GetOwnerGUID().IsPlayer())
        return;

    Player* owner = GetOwner();

    // not save pet as current if another pet temporary unsummoned
    if (mode == PET_SAVE_AS_CURRENT && owner->GetTemporaryUnsummonedPetNumber() &&
        owner->GetTemporaryUnsummonedPetNumber() != m_charmInfo->GetPetNumber())
    {
        // pet will lost anyway at restore temporary unsummoned
        if (getPetType() == HUNTER_PET)
            return;

        // for warlock case
        mode = PET_SAVE_NOT_IN_SLOT;
    }

    uint32 curhealth = GetHealth();
    uint32 curmana = GetPower(POWER_MANA);

    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
    // save auras before possibly removing them
    _SaveAuras(trans);

    if (mode == PET_SAVE_AS_CURRENT)
        if (Optional<uint32> activeSlot = owner->GetPetStable()->GetCurrentActivePetIndex())
            mode = PetSaveMode(*activeSlot);

    // stable and not in slot saves
    if (mode < PET_SAVE_FIRST_ACTIVE_SLOT || mode >= PET_SAVE_LAST_ACTIVE_SLOT)
        RemoveAllAuras();

    _SaveSpells(trans);
    GetSpellHistory()->SaveToDB<Pet>(trans);
    CharacterDatabase.CommitTransaction(trans);

    // current/stable/not_in_slot
    if (mode != PET_SAVE_AS_DELETED)
    {
        ObjectGuid::LowType ownerLowGUID = GetOwnerGUID().GetCounter();
        trans = CharacterDatabase.BeginTransaction();
        // remove current data

        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_PET_BY_ID);
        stmt->setUInt32(0, m_charmInfo->GetPetNumber());
        trans->Append(stmt);

        // save pet
        std::string actionBar = GenerateActionBarData();

        ASSERT(owner->GetPetStable()->GetCurrentPet() && owner->GetPetStable()->GetCurrentPet()->PetNumber == m_charmInfo->GetPetNumber());
        FillPetInfo(owner->GetPetStable()->GetCurrentPet(), owner->GetTemporaryPetReactState());

        stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_PET);
        stmt->setUInt32(0, m_charmInfo->GetPetNumber());
        stmt->setUInt32(1, GetEntry());
        stmt->setUInt64(2, ownerLowGUID);
        stmt->setUInt32(3, GetNativeDisplayId());
        stmt->setUInt8(4, GetLevel());
        stmt->setUInt32(5, m_unitData->PetExperience);
        stmt->setUInt8(6, owner->GetTemporaryPetReactState().value_or(GetReactState()));
        stmt->setInt16(7, owner->GetPetStable()->GetCurrentActivePetIndex().value_or(PET_SAVE_NOT_IN_SLOT));
        stmt->setString(8, m_name);
        stmt->setUInt8(9, HasPetFlag(UNIT_PET_FLAG_CAN_BE_RENAMED) ? 0 : 1);
        stmt->setUInt32(10, curhealth);
        stmt->setUInt32(11, curmana);
        stmt->setString(12, actionBar);
        stmt->setUInt32(13, GameTime::GetGameTime());
        stmt->setUInt32(14, m_unitData->CreatedBySpell);
        stmt->setUInt8(15, getPetType());
        stmt->setUInt16(16, GetSpecialization());
        trans->Append(stmt);

        CharacterDatabase.CommitTransaction(trans);
    }
    // delete
    else
    {
        RemoveAllAuras();
        DeleteFromDB(m_charmInfo->GetPetNumber());
    }
}

void Pet::FillPetInfo(PetStable::PetInfo* petInfo, Optional<ReactStates> forcedReactState /*= {}*/) const
{
    petInfo->PetNumber = m_charmInfo->GetPetNumber();
    petInfo->CreatureId = GetEntry();
    petInfo->DisplayId = GetNativeDisplayId();
    petInfo->Level = GetLevel();
    petInfo->Experience = m_unitData->PetExperience;
    petInfo->ReactState = forcedReactState.value_or(GetReactState());
    petInfo->Name = GetName();
    petInfo->WasRenamed = !HasPetFlag(UNIT_PET_FLAG_CAN_BE_RENAMED);
    petInfo->Health = GetHealth();
    petInfo->Mana = GetPower(POWER_MANA);
    petInfo->ActionBar = GenerateActionBarData();
    petInfo->LastSaveTime = GameTime::GetGameTime();
    petInfo->CreatedBySpellId = m_unitData->CreatedBySpell;
    petInfo->Type = getPetType();
    petInfo->SpecializationId = GetSpecialization();
}

void Pet::DeleteFromDB(uint32 petNumber)
{
    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_PET_BY_ID);
    stmt->setUInt32(0, petNumber);
    trans->Append(stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_PET_DECLINEDNAME);
    stmt->setUInt32(0, petNumber);
    trans->Append(stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_PET_AURA_EFFECTS);
    stmt->setUInt32(0, petNumber);
    trans->Append(stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_PET_AURAS);
    stmt->setUInt32(0, petNumber);
    trans->Append(stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_PET_SPELLS);
    stmt->setUInt32(0, petNumber);
    trans->Append(stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_PET_SPELL_COOLDOWNS);
    stmt->setUInt32(0, petNumber);
    trans->Append(stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_PET_SPELL_CHARGES);
    stmt->setUInt32(0, petNumber);
    trans->Append(stmt);

    CharacterDatabase.CommitTransaction(trans);
}

void Pet::setDeathState(DeathState s)                       // overwrite virtual Creature::setDeathState and Unit::setDeathState
{
    Creature::setDeathState(s);
    if (getDeathState() == CORPSE)
    {
        if (getPetType() == HUNTER_PET)
        {
            // pet corpse non lootable and non skinnable
            ReplaceAllDynamicFlags(UNIT_DYNFLAG_NONE);
            RemoveUnitFlag(UNIT_FLAG_SKINNABLE);

            //SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED);
        }
    }
    else if (getDeathState() == ALIVE)
    {
        //RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED);
        CastPetAuras(true);
    }
}

void Pet::Update(uint32 diff)
{
    if (m_removed)                                           // pet already removed, just wait in remove queue, no updates
        return;

    if (m_loading)
        return;

    switch (m_deathState)
    {
        case CORPSE:
        {
            if (getPetType() != HUNTER_PET || m_corpseRemoveTime <= GameTime::GetGameTime())
            {
                Remove(PET_SAVE_NOT_IN_SLOT);               //hunters' pets never get removed because of death, NEVER!
                return;
            }
            break;
        }
        case ALIVE:
        {
            // unsummon pet that lost owner
            Player* owner = GetOwner();
            if ((!IsWithinDistInMap(owner, GetMap()->GetVisibilityRange()) && !isPossessed()) || (isControlled() && !owner->GetPetGUID()))
            //if (!owner || (!IsWithinDistInMap(owner, GetMap()->GetVisibilityDistance()) && (owner->GetCharmGUID() && (owner->GetCharmGUID() != GetGUID()))) || (isControlled() && !owner->GetPetGUID()))
            {
                Remove(PET_SAVE_NOT_IN_SLOT, true);
                return;
            }

            if (isControlled())
            {
                if (owner->GetPetGUID() != GetGUID())
                {
                    TC_LOG_ERROR("entities.pet", "Pet {} is not pet of owner {}, removed", GetEntry(), GetOwner()->GetName());
                    ASSERT(getPetType() != HUNTER_PET, "Unexpected unlinked pet found for owner %s", owner->GetSession()->GetPlayerInfo().c_str());
                    Remove(PET_SAVE_NOT_IN_SLOT);
                    return;
                }
            }

            if (m_duration > 0)
            {
                if (uint32(m_duration) > diff)
                    m_duration -= diff;
                else
                {
                    Remove(getPetType() != SUMMON_PET ? PET_SAVE_AS_DELETED : PET_SAVE_NOT_IN_SLOT);
                    return;
                }
            }

            //regenerate focus for hunter pets or energy for deathknight's ghoul
            if (m_focusRegenTimer)
            {
                if (m_focusRegenTimer > diff)
                    m_focusRegenTimer -= diff;
                else
                {
                    switch (GetPowerType())
                    {
                        case POWER_FOCUS:
                            Regenerate(POWER_FOCUS);
                            m_focusRegenTimer += PET_FOCUS_REGEN_INTERVAL - diff;
                            if (!m_focusRegenTimer) ++m_focusRegenTimer;

                            // Reset if large diff (lag) causes focus to get 'stuck'
                            if (m_focusRegenTimer > PET_FOCUS_REGEN_INTERVAL)
                                m_focusRegenTimer = PET_FOCUS_REGEN_INTERVAL;

                            break;

                        // in creature::update
                        //case POWER_ENERGY:
                        //    Regenerate(POWER_ENERGY);
                        //    m_regenTimer += CREATURE_REGEN_INTERVAL - diff;
                        //    if (!m_regenTimer) ++m_regenTimer;
                        //    break;
                        default:
                            m_focusRegenTimer = 0;
                            break;
                    }
                }
            }
            break;
        }
        default:
            break;
    }
    Creature::Update(diff);
}

void Pet::Remove(PetSaveMode mode, bool returnreagent)
{
    GetOwner()->RemovePet(this, mode, returnreagent);
}

void Pet::GivePetXP(uint32 xp)
{
    if (getPetType() != HUNTER_PET)
        return;

    if (xp < 1)
        return;

    if (!IsAlive())
        return;

    uint8 maxlevel = std::min((uint8)sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL), GetOwner()->GetLevel());
    uint8 petlevel = GetLevel();

    // If pet is detected to be at, or above(?) the players level, don't hand out XP
    if (petlevel >= maxlevel)
       return;

    uint32 nextLvlXP = m_unitData->PetNextLevelExperience;
    uint32 curXP = m_unitData->PetExperience;
    uint32 newXP = curXP + xp;

    // Check how much XP the pet should receive, and hand off have any left from previous levelups
    while (newXP >= nextLvlXP && petlevel < maxlevel)
    {
        // Subtract newXP from amount needed for nextlevel, and give pet the level
        newXP -= nextLvlXP;
        ++petlevel;

        GivePetLevel(petlevel);

        nextLvlXP = m_unitData->PetNextLevelExperience;
    }
    // Not affected by special conditions - give it new XP
    SetPetExperience(petlevel < maxlevel ? newXP : 0);
}

void Pet::GivePetLevel(uint8 level)
{
    if (!level || level == GetLevel())
        return;

    if (getPetType() == HUNTER_PET)
    {
        SetPetExperience(0);
        SetPetNextLevelExperience(uint32(sObjectMgr->GetXPForLevel(level)*PET_XP_FACTOR));
    }

    InitStatsForLevel(level);
    InitLevelupSpellsForLevel();
}

bool Pet::CreateBaseAtCreature(Creature* creature)
{
    ASSERT(creature);

    if (!CreateBaseAtTamed(creature->GetCreatureTemplate(), creature->GetMap()))
        return false;

    Relocate(creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation());

    if (!IsPositionValid())
    {
        TC_LOG_ERROR("entities.pet", "Pet {} not created base at creature. Suggested coordinates isn't valid (X: {} Y: {})",
            GetGUID().ToString(), GetPositionX(), GetPositionY());
        return false;
    }

    CreatureTemplate const* cinfo = GetCreatureTemplate();
    if (!cinfo)
    {
        TC_LOG_ERROR("entities.pet", "CreateBaseAtCreature() failed, creatureInfo is missing!");
        return false;
    }

    SetDisplayId(creature->GetDisplayId());

    if (CreatureFamilyEntry const* cFamily = sCreatureFamilyStore.LookupEntry(cinfo->family))
        SetName(cFamily->Name[GetOwner()->GetSession()->GetSessionDbcLocale()]);
    else
        SetName(creature->GetNameForLocaleIdx(sObjectMgr->GetDBCLocaleIndex()));

    return true;
}

bool Pet::CreateBaseAtCreatureInfo(CreatureTemplate const* cinfo, Unit* owner)
{
    if (!CreateBaseAtTamed(cinfo, owner->GetMap()))
        return false;

    if (CreatureFamilyEntry const* cFamily = sCreatureFamilyStore.LookupEntry(cinfo->family))
        SetName(cFamily->Name[GetOwner()->GetSession()->GetSessionDbcLocale()]);

    Relocate(owner->GetPositionX(), owner->GetPositionY(), owner->GetPositionZ(), owner->GetOrientation());

    return true;
}

bool Pet::CreateBaseAtTamed(CreatureTemplate const* cinfo, Map* map)
{
    TC_LOG_DEBUG("entities.pet", "Pet::CreateBaseForTamed");
    if (!Create(map->GenerateLowGuid<HighGuid::Pet>(), map, cinfo->Entry, sObjectMgr->GeneratePetNumber()))
        return false;

    SetPetNameTimestamp(0);
    SetPetExperience(0);
    SetPetNextLevelExperience(uint32(sObjectMgr->GetXPForLevel(GetLevel() + 1) * PET_XP_FACTOR));
    ReplaceAllNpcFlags(UNIT_NPC_FLAG_NONE);
    ReplaceAllNpcFlags2(UNIT_NPC_FLAG_2_NONE);

    if (cinfo->type == CREATURE_TYPE_BEAST)
    {
        SetClass(CLASS_WARRIOR);
        SetGender(GENDER_NONE);
        SetPowerType(POWER_FOCUS);
        SetSheath(SHEATH_STATE_MELEE);
        ReplaceAllPetFlags(UNIT_PET_FLAG_CAN_BE_RENAMED | UNIT_PET_FLAG_CAN_BE_ABANDONED);
    }

    return true;
}

/// @todo Move stat mods code to pet passive auras
bool Guardian::InitStatsForLevel(uint8 petlevel)
{
    CreatureTemplate const* cinfo = GetCreatureTemplate();
    ASSERT(cinfo);

    SetLevel(petlevel);

    //Determine pet type
    PetType petType = MAX_PET_TYPE;
    if (IsPet() && GetOwner()->GetTypeId() == TYPEID_PLAYER)
    {
        if (GetOwner()->GetClass() == CLASS_WARLOCK
            || GetOwner()->GetClass() == CLASS_SHAMAN        // Fire Elemental
            || GetOwner()->GetClass() == CLASS_DEATH_KNIGHT) // Risen Ghoul
        {
            petType = SUMMON_PET;
        }
        else if (GetOwner()->GetClass() == CLASS_HUNTER)
        {
            petType = HUNTER_PET;
            m_unitTypeMask |= UNIT_MASK_HUNTER_PET;
        }
        else
        {
            TC_LOG_ERROR("entities.pet", "Unknown type pet {} is summoned by player class {}",
                           GetEntry(), GetOwner()->GetClass());
        }
    }

    uint32 creature_ID = (petType == HUNTER_PET) ? 1 : cinfo->Entry;

    SetMeleeDamageSchool(SpellSchools(cinfo->dmgschool));

    SetStatFlatModifier(UNIT_MOD_ARMOR, BASE_VALUE, float(petlevel * 50));

    SetBaseAttackTime(BASE_ATTACK, BASE_ATTACK_TIME);
    SetBaseAttackTime(OFF_ATTACK, BASE_ATTACK_TIME);
    SetBaseAttackTime(RANGED_ATTACK, BASE_ATTACK_TIME);

    //scale
    SetObjectScale(GetNativeObjectScale());

    // Resistance
    // Hunters pet should not inherit resistances from creature_template, they have separate auras for that
    if (!IsHunterPet())
        for (uint8 i = SPELL_SCHOOL_HOLY; i < MAX_SPELL_SCHOOL; ++i)
            SetStatFlatModifier(UnitMods(UNIT_MOD_RESISTANCE_START + i), BASE_VALUE, float(cinfo->resistance[i]));

    Powers powerType = CalculateDisplayPowerType();

    // Health, Mana or Power, Armor
    PetLevelInfo const* pInfo = sObjectMgr->GetPetLevelInfo(creature_ID, petlevel);
    if (pInfo)                                      // exist in DB
    {
        SetCreateHealth(pInfo->health);
        SetCreateMana(pInfo->mana);

        SetStatPctModifier(UnitMods(UNIT_MOD_POWER_START + AsUnderlyingType(powerType)), BASE_PCT, 1.0f);

        if (pInfo->armor > 0)
            SetStatFlatModifier(UNIT_MOD_ARMOR, BASE_VALUE, float(pInfo->armor));

        for (uint8 stat = 0; stat < MAX_STATS; ++stat)
            SetCreateStat(Stats(stat), float(pInfo->stats[stat]));
    }
    else                                            // not exist in DB, use some default fake data
    {
        // remove elite bonuses included in DB values
        CreatureBaseStats const* stats = sObjectMgr->GetCreatureBaseStats(petlevel, cinfo->unit_class);
        ApplyLevelScaling();

        CreatureDifficulty const* creatureDifficulty = GetCreatureDifficulty();
        SetCreateHealth(std::max(sDB2Manager.EvaluateExpectedStat(ExpectedStatType::CreatureHealth, petlevel, creatureDifficulty->GetHealthScalingExpansion(), m_unitData->ContentTuningID, Classes(cinfo->unit_class), 0) * creatureDifficulty->HealthModifier * GetHealthMod(cinfo->Classification), 1.0f));
        SetCreateMana(stats->BaseMana);
        SetCreateStat(STAT_STRENGTH, 22);
        SetCreateStat(STAT_AGILITY, 22);
        SetCreateStat(STAT_STAMINA, 25);
        SetCreateStat(STAT_INTELLECT, 28);
    }

    // Power
    SetPowerType(powerType);

    // Damage
    SetBonusDamage(0);
    switch (petType)
    {
        case SUMMON_PET:
        {
            // the damage bonus used for pets is either fire or shadow damage, whatever is higher
            int32 fire = GetOwner()->ToPlayer()->m_activePlayerData->ModDamageDonePos[SPELL_SCHOOL_FIRE];
            int32 shadow = GetOwner()->ToPlayer()->m_activePlayerData->ModDamageDonePos[SPELL_SCHOOL_SHADOW];
            int32 val = (fire > shadow) ? fire : shadow;
            if (val < 0)
                val = 0;

            SetBonusDamage(val * 0.15f);

            SetBaseWeaponDamage(BASE_ATTACK, MINDAMAGE, float(petlevel - (petlevel / 4)));
            SetBaseWeaponDamage(BASE_ATTACK, MAXDAMAGE, float(petlevel + (petlevel / 4)));

            //SetStatFlatModifier(UNIT_MOD_ATTACK_POWER, BASE_VALUE, float(cinfo->attackpower));
            break;
        }
        case HUNTER_PET:
        {
            ToPet()->SetPetNextLevelExperience(uint32(sObjectMgr->GetXPForLevel(petlevel)*PET_XP_FACTOR));
            //these formula may not be correct; however, it is designed to be close to what it should be
            //this makes dps 0.5 of pets level
            SetBaseWeaponDamage(BASE_ATTACK, MINDAMAGE, float(petlevel - (petlevel / 4)));
            //damage range is then petlevel / 2
            SetBaseWeaponDamage(BASE_ATTACK, MAXDAMAGE, float(petlevel + (petlevel / 4)));
            //damage is increased afterwards as strength and pet scaling modify attack power
            break;
        }
        default:
        {
            switch (GetEntry())
            {
                case 510: // mage Water Elemental
                {
                    SetBonusDamage(int32(GetOwner()->SpellBaseDamageBonusDone(SPELL_SCHOOL_MASK_FROST) * 0.33f));
                    break;
                }
                case 1964: //force of nature
                {
                    if (!pInfo)
                        SetCreateHealth(30 + 30*petlevel);
                    float bonusDmg = GetOwner()->SpellBaseDamageBonusDone(SPELL_SCHOOL_MASK_NATURE) * 0.15f;
                    SetBaseWeaponDamage(BASE_ATTACK, MINDAMAGE, float(petlevel * 2.5f - (petlevel / 2) + bonusDmg));
                    SetBaseWeaponDamage(BASE_ATTACK, MAXDAMAGE, float(petlevel * 2.5f + (petlevel / 2) + bonusDmg));
                    break;
                }
                case 15352: //earth elemental 36213
                {
                    if (!pInfo)
                        SetCreateHealth(100 + 120*petlevel);
                    SetBaseWeaponDamage(BASE_ATTACK, MINDAMAGE, float(petlevel - (petlevel / 4)));
                    SetBaseWeaponDamage(BASE_ATTACK, MAXDAMAGE, float(petlevel + (petlevel / 4)));
                    break;
                }
                case 15438: //fire elemental
                {
                    if (!pInfo)
                    {
                        SetCreateHealth(40*petlevel);
                        SetCreateMana(28 + 10*petlevel);
                    }
                    SetBonusDamage(int32(GetOwner()->SpellBaseDamageBonusDone(SPELL_SCHOOL_MASK_FIRE) * 0.5f));
                    SetBaseWeaponDamage(BASE_ATTACK, MINDAMAGE, float(petlevel * 4 - petlevel));
                    SetBaseWeaponDamage(BASE_ATTACK, MAXDAMAGE, float(petlevel * 4 + petlevel));
                    break;
                }
                case 19668: // Shadowfiend
                {
                    if (!pInfo)
                    {
                        SetCreateMana(28 + 10*petlevel);
                        SetCreateHealth(28 + 30*petlevel);
                    }
                    int32 bonus_dmg = int32(GetOwner()->SpellBaseDamageBonusDone(SPELL_SCHOOL_MASK_SHADOW)* 0.3f);
                    SetBaseWeaponDamage(BASE_ATTACK, MINDAMAGE, float((petlevel * 4 - petlevel) + bonus_dmg));
                    SetBaseWeaponDamage(BASE_ATTACK, MAXDAMAGE, float((petlevel * 4 + petlevel) + bonus_dmg));

                    break;
                }
                case 19833: //Snake Trap - Venomous Snake
                {
                    SetBaseWeaponDamage(BASE_ATTACK, MINDAMAGE, float((petlevel / 2) - 25));
                    SetBaseWeaponDamage(BASE_ATTACK, MAXDAMAGE, float((petlevel / 2) - 18));
                    break;
                }
                case 19921: //Snake Trap - Viper
                {
                    SetBaseWeaponDamage(BASE_ATTACK, MINDAMAGE, float(petlevel / 2 - 10));
                    SetBaseWeaponDamage(BASE_ATTACK, MAXDAMAGE, float(petlevel / 2));
                    break;
                }
                case 29264: // Feral Spirit
                {
                    if (!pInfo)
                        SetCreateHealth(30*petlevel);

                    // wolf attack speed is 1.5s
                    SetBaseAttackTime(BASE_ATTACK, cinfo->BaseAttackTime);

                    SetBaseWeaponDamage(BASE_ATTACK, MINDAMAGE, float((petlevel * 4 - petlevel)));
                    SetBaseWeaponDamage(BASE_ATTACK, MAXDAMAGE, float((petlevel * 4 + petlevel)));

                    SetStatFlatModifier(UNIT_MOD_ARMOR, BASE_VALUE, float(GetOwner()->GetArmor()) * 0.35f);  // Bonus Armor (35% of player armor)
                    SetStatFlatModifier(UNIT_MOD_STAT_STAMINA, BASE_VALUE, float(GetOwner()->GetStat(STAT_STAMINA)) * 0.3f);  // Bonus Stamina (30% of player stamina)
                    if (!HasAura(58877))//prevent apply twice for the 2 wolves
                        AddAura(58877, this);//Spirit Hunt, passive, Spirit Wolves' attacks heal them and their master for 150% of damage done.
                    break;
                }
                case 31216: // Mirror Image
                {
                    SetBonusDamage(int32(GetOwner()->SpellBaseDamageBonusDone(SPELL_SCHOOL_MASK_FROST) * 0.33f));
                    SetDisplayId(GetOwner()->GetDisplayId());
                    if (!pInfo)
                    {
                        SetCreateMana(28 + 30*petlevel);
                        SetCreateHealth(28 + 10*petlevel);
                    }
                    break;
                }
                case 27829: // Ebon Gargoyle
                {
                    if (!pInfo)
                    {
                        SetCreateMana(28 + 10*petlevel);
                        SetCreateHealth(28 + 30*petlevel);
                    }
                    SetBonusDamage(int32(GetOwner()->GetTotalAttackPowerValue(BASE_ATTACK) * 0.5f));
                    SetBaseWeaponDamage(BASE_ATTACK, MINDAMAGE, float(petlevel - (petlevel / 4)));
                    SetBaseWeaponDamage(BASE_ATTACK, MAXDAMAGE, float(petlevel + (petlevel / 4)));
                    break;
                }
                case 28017: // Bloodworms
                {
                    SetCreateHealth(4 * petlevel);
                    SetBonusDamage(int32(GetOwner()->GetTotalAttackPowerValue(BASE_ATTACK) * 0.006f));
                    SetBaseWeaponDamage(BASE_ATTACK, MINDAMAGE, float(petlevel - 30 - (petlevel / 4)));
                    SetBaseWeaponDamage(BASE_ATTACK, MAXDAMAGE, float(petlevel - 30 + (petlevel / 4)));
                    break;
                }
                default:
                {
                    /* ToDo: Check what 5f5d2028 broke/fixed and how much of Creature::UpdateLevelDependantStats()
                     * should be copied here (or moved to another method or if that function should be called here
                     * or not just for this default case)
                     */
                    float basedamage = GetBaseDamageForLevel(petlevel);

                    float weaponBaseMinDamage = basedamage;
                    float weaponBaseMaxDamage = basedamage * 1.5f;

                    SetBaseWeaponDamage(BASE_ATTACK, MINDAMAGE, weaponBaseMinDamage);
                    SetBaseWeaponDamage(BASE_ATTACK, MAXDAMAGE, weaponBaseMaxDamage);
                    break;
                }
            }
            break;
        }
    }

    UpdateAllStats();

    SetFullHealth();
    SetFullPower(POWER_MANA);
    return true;
}

bool Pet::HaveInDiet(ItemTemplate const* item) const
{
    if (!item->FoodType)
        return false;

    CreatureTemplate const* cInfo = GetCreatureTemplate();
    if (!cInfo)
        return false;

    CreatureFamilyEntry const* cFamily = sCreatureFamilyStore.LookupEntry(cInfo->family);
    if (!cFamily)
        return false;

    uint32 diet = cFamily->PetFoodMask;
    uint32 FoodMask = 1 << (item->FoodType-1);
    return (diet & FoodMask) != 0;
}

void Pet::_LoadSpells(PreparedQueryResult result)
{
    if (result)
    {
        do
        {
            Field* fields = result->Fetch();

            addSpell(fields[0].GetUInt32(), ActiveStates(fields[1].GetUInt8()), PETSPELL_UNCHANGED);
        }
        while (result->NextRow());
    }
}

void Pet::_SaveSpells(CharacterDatabaseTransaction trans)
{
    for (PetSpellMap::iterator itr = m_spells.begin(), next = m_spells.begin(); itr != m_spells.end(); itr = next)
    {
        ++next;

        // prevent saving family passives to DB
        if (itr->second.type == PETSPELL_FAMILY)
            continue;

        CharacterDatabasePreparedStatement* stmt;

        switch (itr->second.state)
        {
            case PETSPELL_REMOVED:
                stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_PET_SPELL_BY_SPELL);
                stmt->setUInt32(0, m_charmInfo->GetPetNumber());
                stmt->setUInt32(1, itr->first);
                trans->Append(stmt);

                m_spells.erase(itr);
                continue;
            case PETSPELL_CHANGED:
                stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_PET_SPELL_BY_SPELL);
                stmt->setUInt32(0, m_charmInfo->GetPetNumber());
                stmt->setUInt32(1, itr->first);
                trans->Append(stmt);

                stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_PET_SPELL);
                stmt->setUInt32(0, m_charmInfo->GetPetNumber());
                stmt->setUInt32(1, itr->first);
                stmt->setUInt8(2, itr->second.active);
                trans->Append(stmt);

                break;
            case PETSPELL_NEW:
                stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_PET_SPELL);
                stmt->setUInt32(0, m_charmInfo->GetPetNumber());
                stmt->setUInt32(1, itr->first);
                stmt->setUInt8(2, itr->second.active);
                trans->Append(stmt);
                break;
            case PETSPELL_UNCHANGED:
                continue;
        }
        itr->second.state = PETSPELL_UNCHANGED;
    }
}

void Pet::_LoadAuras(PreparedQueryResult auraResult, PreparedQueryResult effectResult, uint32 timediff)
{
    TC_LOG_DEBUG("entities.pet", "Loading auras for pet {}", GetGUID().ToString());

    ObjectGuid casterGuid, itemGuid;
    std::map<AuraKey, AuraLoadEffectInfo> effectInfo;

    /*
                    0      1           2            3       4           5
    SELECT casterGuid, spell, effectMask, effectIndex, amount, baseAmount FROM pet_aura_effect WHERE guid = ?
    */
    if (effectResult)
    {
        do
        {
            Field* fields = effectResult->Fetch();
            uint32 effectIndex = fields[3].GetUInt8();
            if (effectIndex < MAX_SPELL_EFFECTS)
            {
                casterGuid.SetRawValue(fields[0].GetBinary());
                if (casterGuid.IsEmpty())
                    casterGuid = GetGUID();

                AuraKey key{ casterGuid, itemGuid, fields[1].GetUInt32(), fields[2].GetUInt32() };
                AuraLoadEffectInfo& info = effectInfo[key];
                info.Amounts[effectIndex] = fields[4].GetInt32();
                info.BaseAmounts[effectIndex] = fields[5].GetInt32();
            }
        } while (effectResult->NextRow());
    }

    /*
                    0      1           2                3           4           5            6           7              8
    SELECT casterGuid, spell, effectMask, recalculateMask, difficulty, stackCount, maxDuration, remainTime, remainCharges FROM pet_aura WHERE guid = ?
    */
    if (auraResult)
    {
        do
        {
            Field* fields = auraResult->Fetch();
            // NULL guid stored - pet is the caster of the spell - see Pet::_SaveAuras
            casterGuid.SetRawValue(fields[0].GetBinary());
            if (casterGuid.IsEmpty())
                casterGuid = GetGUID();

            AuraKey key{ casterGuid, itemGuid, fields[1].GetUInt32(), fields[2].GetUInt32() };
            uint32 recalculateMask = fields[3].GetUInt32();
            Difficulty difficulty = Difficulty(fields[4].GetUInt8());
            uint8 stackCount = fields[5].GetUInt8();
            int32 maxDuration = fields[6].GetInt32();
            int32 remainTime = fields[7].GetInt32();
            uint8 remainCharges = fields[8].GetUInt8();

            SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(key.SpellId, difficulty);
            if (!spellInfo)
            {
                TC_LOG_ERROR("entities.pet", "Pet::_LoadAuras: Unknown aura (spellid {}), ignore.", key.SpellId);
                continue;
            }

            if (difficulty != DIFFICULTY_NONE && !sDifficultyStore.LookupEntry(difficulty))
            {
                TC_LOG_ERROR("entities.pet", "Pet::_LoadAuras: Unknown difficulty {} (spellid {}), ignore.", uint32(difficulty), key.SpellId);
                continue;
            }

            // negative effects should continue counting down after logout
            if (remainTime != -1 && (!spellInfo->IsPositive() || spellInfo->HasAttribute(SPELL_ATTR4_AURA_EXPIRES_OFFLINE)))
            {
                if (remainTime/IN_MILLISECONDS <= int32(timediff))
                    continue;

                remainTime -= timediff*IN_MILLISECONDS;
            }

            // prevent wrong values of remainCharges
            if (spellInfo->ProcCharges)
            {
                // we have no control over the order of applying auras and modifiers allow auras
                // to have more charges than value in SpellInfo
                if (remainCharges <= 0/* || remainCharges > spellproto->procCharges*/)
                    remainCharges = spellInfo->ProcCharges;
            }
            else
                remainCharges = 0;

            AuraLoadEffectInfo& info = effectInfo[key];
            ObjectGuid castId = ObjectGuid::Create<HighGuid::Cast>(SPELL_CAST_SOURCE_NORMAL, GetMapId(), spellInfo->Id, GetMap()->GenerateLowGuid<HighGuid::Cast>());
            AuraCreateInfo createInfo(castId, spellInfo, difficulty, key.EffectMask, this);
            createInfo
                .SetCasterGUID(casterGuid)
                .SetBaseAmount(info.BaseAmounts.data());

            if (Aura* aura = Aura::TryCreate(createInfo))
            {
                if (!aura->CanBeSaved())
                {
                    aura->Remove();
                    continue;
                }

                aura->SetLoadedState(maxDuration, remainTime, remainCharges, stackCount, recalculateMask, info.Amounts.data());
                aura->ApplyForTargets();
                TC_LOG_DEBUG("entities.pet", "Added aura spellid {}, effectmask {}", spellInfo->Id, key.EffectMask);
            }
        }
        while (auraResult->NextRow());
    }
}

void Pet::_SaveAuras(CharacterDatabaseTransaction trans)
{
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_PET_AURA_EFFECTS);
    stmt->setUInt32(0, m_charmInfo->GetPetNumber());
    trans->Append(stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_PET_AURAS);
    stmt->setUInt32(0, m_charmInfo->GetPetNumber());
    trans->Append(stmt);

    uint8 index;
    for (AuraMap::const_iterator itr = m_ownedAuras.begin(); itr != m_ownedAuras.end(); ++itr)
    {
        // check if the aura has to be saved
        if (!itr->second->CanBeSaved() || IsPetAura(itr->second))
            continue;

        Aura* aura = itr->second;
        uint32 recalculateMask = 0;
        AuraKey key = aura->GenerateKey(recalculateMask);

        // don't save guid of caster in case we are caster of the spell - guid for pet is generated every pet load, so it won't match saved guid anyways
        if (key.Caster == GetGUID())
            key.Caster.Clear();

        index = 0;
        stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_PET_AURA);
        stmt->setUInt32(index++, m_charmInfo->GetPetNumber());
        stmt->setBinary(index++, key.Caster.GetRawValue());
        stmt->setUInt32(index++, key.SpellId);
        stmt->setUInt32(index++, key.EffectMask);
        stmt->setUInt32(index++, recalculateMask);
        stmt->setUInt8(index++, aura->GetCastDifficulty());
        stmt->setUInt8(index++, aura->GetStackAmount());
        stmt->setInt32(index++, aura->GetMaxDuration());
        stmt->setInt32(index++, aura->GetDuration());
        stmt->setUInt8(index++, aura->GetCharges());
        trans->Append(stmt);

        for (AuraEffect const* effect : aura->GetAuraEffects())
        {
            if (effect)
            {
                index = 0;
                stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_PET_AURA_EFFECT);
                stmt->setUInt32(index++, m_charmInfo->GetPetNumber());
                stmt->setBinary(index++, key.Caster.GetRawValue());
                stmt->setUInt32(index++, key.SpellId);
                stmt->setUInt32(index++, key.EffectMask);
                stmt->setUInt8(index++, effect->GetEffIndex());
                stmt->setInt32(index++, effect->GetAmount());
                stmt->setInt32(index++, effect->GetBaseAmount());
                trans->Append(stmt);
            }
        }
    }
}

bool Pet::addSpell(uint32 spellId, ActiveStates active /*= ACT_DECIDE*/, PetSpellState state /*= PETSPELL_NEW*/, PetSpellType type /*= PETSPELL_NORMAL*/)
{
    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellId, DIFFICULTY_NONE);
    if (!spellInfo)
    {
        // do pet spell book cleanup
        if (state == PETSPELL_UNCHANGED)                    // spell load case
        {
            TC_LOG_ERROR("entities.pet", "Pet::addSpell: Non-existed in SpellStore spell #{} request, deleting for all pets in `pet_spell`.", spellId);

            CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_INVALID_PET_SPELL);

            stmt->setUInt32(0, spellId);

            CharacterDatabase.Execute(stmt);
        }
        else
            TC_LOG_ERROR("entities.pet", "Pet::addSpell: Non-existed in SpellStore spell #{} request.", spellId);

        return false;
    }

    PetSpellMap::iterator itr = m_spells.find(spellId);
    if (itr != m_spells.end())
    {
        if (itr->second.state == PETSPELL_REMOVED)
            state = PETSPELL_CHANGED;
        else
        {
            if (state == PETSPELL_UNCHANGED && itr->second.state != PETSPELL_UNCHANGED)
            {
                // can be in case spell loading but learned at some previous spell loading
                itr->second.state = PETSPELL_UNCHANGED;

                if (active == ACT_ENABLED)
                    ToggleAutocast(spellInfo, true);
                else if (active == ACT_DISABLED)
                    ToggleAutocast(spellInfo, false);
            }

            return false;
        }
    }

    PetSpell newspell;
    newspell.state = state;
    newspell.type = type;

    if (active == ACT_DECIDE)                               // active was not used before, so we save it's autocast/passive state here
    {
        if (spellInfo->IsAutocastable())
            newspell.active = ACT_DISABLED;
        else
            newspell.active = ACT_PASSIVE;
    }
    else
        newspell.active = active;

    // talent: unlearn all other talent ranks (high and low)
    if (spellInfo->IsRanked())
    {
        for (PetSpellMap::const_iterator itr2 = m_spells.begin(); itr2 != m_spells.end(); ++itr2)
        {
            if (itr2->second.state == PETSPELL_REMOVED)
                continue;

            SpellInfo const* oldRankSpellInfo = sSpellMgr->GetSpellInfo(itr2->first, DIFFICULTY_NONE);

            if (!oldRankSpellInfo)
                continue;

            if (spellInfo->IsDifferentRankOf(oldRankSpellInfo))
            {
                // replace by new high rank
                if (spellInfo->IsHighRankOf(oldRankSpellInfo))
                {
                    newspell.active = itr2->second.active;

                    if (newspell.active == ACT_ENABLED)
                        ToggleAutocast(oldRankSpellInfo, false);

                    unlearnSpell(itr2->first, false, false);
                    break;
                }
                // ignore new lesser rank
                else
                    return false;
            }
        }
    }

    m_spells[spellId] = newspell;

    if (spellInfo->IsPassive() && (!spellInfo->CasterAuraState || HasAuraState(AuraStateType(spellInfo->CasterAuraState))))
        CastSpell(this, spellId, true);
    else
        m_charmInfo->AddSpellToActionBar(spellInfo);

    if (newspell.active == ACT_ENABLED)
        ToggleAutocast(spellInfo, true);

    return true;
}

bool Pet::learnSpell(uint32 spell_id)
{
    // prevent duplicated entires in spell book
    if (!addSpell(spell_id))
        return false;

    if (!m_loading)
    {
        WorldPackets::Pet::PetLearnedSpells packet;
        packet.Spells.push_back(spell_id);
        GetOwner()->SendDirectMessage(packet.Write());
        GetOwner()->PetSpellInitialize();
    }
    return true;
}

void Pet::learnSpells(std::vector<uint32> const& spellIds)
{
    WorldPackets::Pet::PetLearnedSpells packet;

    for (uint32 spell : spellIds)
    {
        if (!addSpell(spell))
            continue;

        packet.Spells.push_back(spell);
    }

    if (!m_loading)
        GetOwner()->GetSession()->SendPacket(packet.Write());
}

void Pet::InitLevelupSpellsForLevel()
{
    uint8 level = GetLevel();

    if (PetLevelupSpellSet const* levelupSpells = GetCreatureTemplate()->family ? sSpellMgr->GetPetLevelupSpellList(GetCreatureTemplate()->family) : nullptr)
    {
        // PetLevelupSpellSet ordered by levels, process in reversed order
        for (PetLevelupSpellSet::const_reverse_iterator itr = levelupSpells->rbegin(); itr != levelupSpells->rend(); ++itr)
        {
            // will called first if level down
            if (itr->first > level)
                unlearnSpell(itr->second, true);                 // will learn prev rank if any
            // will called if level up
            else
                learnSpell(itr->second);                        // will unlearn prev rank if any
        }
    }

    // default spells (can be not learned if pet level (as owner level decrease result for example) less first possible in normal game)
    if (PetDefaultSpellsEntry const* defSpells = sSpellMgr->GetPetDefaultSpellsEntry(int32(GetEntry())))
    {
        for (uint32 spellId : defSpells->spellid)
        {
            SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellId, DIFFICULTY_NONE);
            if (!spellInfo)
                continue;

            // will called first if level down
            if (spellInfo->SpellLevel > level)
                unlearnSpell(spellInfo->Id, true);
            // will called if level up
            else
                learnSpell(spellInfo->Id);
        }
    }
}

bool Pet::unlearnSpell(uint32 spell_id, bool learn_prev, bool clear_ab)
{
    if (removeSpell(spell_id, learn_prev, clear_ab))
    {
        if (!m_loading)
        {
            WorldPackets::Pet::PetUnlearnedSpells packet;
            packet.Spells.push_back(spell_id);
            GetOwner()->SendDirectMessage(packet.Write());
        }
        return true;
    }
    return false;
}

void Pet::unlearnSpells(std::vector<uint32> const& spellIds, bool learn_prev, bool clear_ab)
{
    WorldPackets::Pet::PetUnlearnedSpells packet;

    for (uint32 spell : spellIds)
    {
        if (!removeSpell(spell, learn_prev, clear_ab))
            continue;

        packet.Spells.push_back(spell);
    }

    if (!m_loading)
        GetOwner()->GetSession()->SendPacket(packet.Write());
}

bool Pet::removeSpell(uint32 spell_id, bool learn_prev, bool clear_ab)
{
    PetSpellMap::iterator itr = m_spells.find(spell_id);
    if (itr == m_spells.end())
        return false;

    if (itr->second.state == PETSPELL_REMOVED)
        return false;

    if (itr->second.state == PETSPELL_NEW)
        m_spells.erase(itr);
    else
        itr->second.state = PETSPELL_REMOVED;

    RemoveAurasDueToSpell(spell_id);

    if (learn_prev)
    {
        if (uint32 prev_id = sSpellMgr->GetPrevSpellInChain (spell_id))
            learnSpell(prev_id);
        else
            learn_prev = false;
    }

    // if remove last rank or non-ranked then update action bar at server and client if need
    if (clear_ab && !learn_prev && m_charmInfo->RemoveSpellFromActionBar(spell_id))
    {
        if (!m_loading)
            GetOwner()->PetSpellInitialize(); // need update action bar for last removed rank
    }

    return true;
}

void Pet::CleanupActionBar()
{
    for (uint8 i = 0; i < MAX_UNIT_ACTION_BAR_INDEX; ++i)
        if (UnitActionBarEntry const* ab = m_charmInfo->GetActionBarEntry(i))
            if (ab->GetAction() && ab->IsActionBarForSpell())
            {
                if (!HasSpell(ab->GetAction()))
                    m_charmInfo->SetActionBar(i, 0, ACT_PASSIVE);
                else if (ab->GetType() == ACT_ENABLED)
                {
                    if (SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(ab->GetAction(), DIFFICULTY_NONE))
                        ToggleAutocast(spellInfo, true);
                }
            }
}

void Pet::InitPetCreateSpells()
{
    m_charmInfo->InitPetActionBar();
    m_spells.clear();

    LearnPetPassives();
    InitLevelupSpellsForLevel();

    CastPetAuras(false);
}

void Pet::ToggleAutocast(SpellInfo const* spellInfo, bool apply)
{
    ASSERT(spellInfo);

    if (!spellInfo->IsAutocastable())
        return;

    PetSpellMap::iterator itr = m_spells.find(spellInfo->Id);
    if (itr == m_spells.end())
        return;

    auto autospellItr = std::find(m_autospells.begin(), m_autospells.end(), spellInfo->Id);

    if (apply)
    {
        if (autospellItr == m_autospells.end())
        {
            m_autospells.push_back(spellInfo->Id);

            if (itr->second.active != ACT_ENABLED)
            {
                itr->second.active = ACT_ENABLED;
                if (itr->second.state != PETSPELL_NEW)
                    itr->second.state = PETSPELL_CHANGED;
            }
        }
    }
    else
    {
        if (autospellItr != m_autospells.end())
        {
            m_autospells.erase(autospellItr);

            if (itr->second.active != ACT_DISABLED)
            {
                itr->second.active = ACT_DISABLED;
                if (itr->second.state != PETSPELL_NEW)
                    itr->second.state = PETSPELL_CHANGED;
            }
        }
    }
}

bool Pet::IsPermanentPetFor(Player* owner) const
{
    switch (getPetType())
    {
        case SUMMON_PET:
            switch (owner->GetClass())
            {
                case CLASS_WARLOCK:
                    return GetCreatureTemplate()->type == CREATURE_TYPE_DEMON;
                case CLASS_DEATH_KNIGHT:
                    return GetCreatureTemplate()->type == CREATURE_TYPE_UNDEAD;
                case CLASS_MAGE:
                    return GetCreatureTemplate()->type == CREATURE_TYPE_ELEMENTAL;
                default:
                    return false;
            }
        case HUNTER_PET:
            return true;
        default:
            return false;
    }
}

bool Pet::Create(ObjectGuid::LowType guidlow, Map* map, uint32 Entry, uint32 /*petId*/)
{
    ASSERT(map);
    SetMap(map);

    // TODO: counter should be constructed as (summon_count << 32) | petNumber
    Object::_Create(ObjectGuid::Create<HighGuid::Pet>(map->GetId(), Entry, guidlow));

    m_spawnId = guidlow;
    m_originalEntry = Entry;

    if (!InitEntry(Entry))
        return false;

    // Force regen flag for player pets, just like we do for players themselves
    SetUnitFlag2(UNIT_FLAG2_REGENERATE_POWER);
    SetSheath(SHEATH_STATE_MELEE);

    GetThreatManager().Initialize();

    return true;
}

bool Pet::HasSpell(uint32 spell) const
{
    PetSpellMap::const_iterator itr = m_spells.find(spell);
    return itr != m_spells.end() && itr->second.state != PETSPELL_REMOVED;
}

// Get all passive spells in our skill line
void Pet::LearnPetPassives()
{
    CreatureTemplate const* cInfo = GetCreatureTemplate();
    if (!cInfo)
        return;

    CreatureFamilyEntry const* cFamily = sCreatureFamilyStore.LookupEntry(cInfo->family);
    if (!cFamily)
        return;

    PetFamilySpellsStore::const_iterator petStore = sPetFamilySpellsStore.find(cInfo->family);
    if (petStore != sPetFamilySpellsStore.end())
    {
        // For general hunter pets skill 270
        // Passive 01~10, Passive 00 (20782, not used), Ferocious Inspiration (34457)
        // Scale 01~03 (34902~34904, bonus from owner, not used)
        for (uint32 spellId : petStore->second)
            addSpell(spellId, ACT_DECIDE, PETSPELL_NEW, PETSPELL_FAMILY);
    }
}

void Pet::CastPetAuras(bool current)
{
    Player* owner = GetOwner();

    if (!IsPermanentPetFor(owner))
        return;

    for (auto itr = owner->m_petAuras.begin(); itr != owner->m_petAuras.end();)
    {
        PetAura const* pa = *itr;
        ++itr;

        if (!current && pa->IsRemovedOnChangePet())
            owner->RemovePetAura(pa);
        else
            CastPetAura(pa);
    }
}

void Pet::CastPetAura(PetAura const* aura)
{
    uint32 auraId = aura->GetAura(GetEntry());
    if (!auraId)
        return;

    CastSpellExtraArgs args;
    args.TriggerFlags = TRIGGERED_FULL_MASK;

    if (auraId == 35696)                                      // Demonic Knowledge
        args.AddSpellMod(SPELLVALUE_BASE_POINT0, CalculatePct(aura->GetDamage(), GetStat(STAT_STAMINA) + GetStat(STAT_INTELLECT)));

    CastSpell(this, auraId, args);
}

bool Pet::IsPetAura(Aura const* aura)
{
    Player* owner = GetOwner();

    // if the owner has that pet aura, return true
    for (PetAura const* petAura : owner->m_petAuras)
        if (petAura->GetAura(GetEntry()) == aura->GetId())
            return true;

    return false;
}

void Pet::learnSpellHighRank(uint32 spellid)
{
    learnSpell(spellid);

    if (uint32 next = sSpellMgr->GetNextSpellInChain(spellid))
        learnSpellHighRank(next);
}

void Pet::SynchronizeLevelWithOwner()
{
    Player* owner = GetOwner();

    switch (getPetType())
    {
        // always same level
        case SUMMON_PET:
        case HUNTER_PET:
            GivePetLevel(owner->GetLevel());
            break;
        default:
            break;
    }
}

Player* Pet::GetOwner() const
{
    return Minion::GetOwner()->ToPlayer();
}

float Pet::GetNativeObjectScale() const
{
    CreatureFamilyEntry const* creatureFamily = sCreatureFamilyStore.LookupEntry(GetCreatureTemplate()->family);
    if (creatureFamily && creatureFamily->MinScale > 0.0f && getPetType() == HUNTER_PET)
    {
        float scale;
        if (GetLevel() >= creatureFamily->MaxScaleLevel)
            scale = creatureFamily->MaxScale;
        else if (GetLevel() <= creatureFamily->MinScaleLevel)
            scale = creatureFamily->MinScale;
        else
            scale = creatureFamily->MinScale + float(GetLevel() - creatureFamily->MinScaleLevel) / creatureFamily->MaxScaleLevel * (creatureFamily->MaxScale - creatureFamily->MinScale);

        return scale;
    }

    return Guardian::GetNativeObjectScale();
}

void Pet::SetDisplayId(uint32 modelId, bool setNative /*= false*/)
{
    Guardian::SetDisplayId(modelId, setNative);

    if (!isControlled())
        return;

    SetGroupUpdateFlag(GROUP_UPDATE_FLAG_PET_MODEL_ID);
}

void Pet::SetGroupUpdateFlag(uint32 flag)
{
    if (GetOwner()->GetGroup())
    {
        m_groupUpdateMask |= flag;
        GetOwner()->SetGroupUpdateFlag(GROUP_UPDATE_FLAG_PET);
    }
}

void Pet::ResetGroupUpdateFlag()
{
    m_groupUpdateMask = GROUP_UPDATE_FLAG_PET_NONE;
    if (GetOwner()->GetGroup())
        GetOwner()->RemoveGroupUpdateFlag(GROUP_UPDATE_FLAG_PET);
}

void Pet::LearnSpecializationSpells()
{
    std::vector<uint32> learnedSpells;

    if (std::vector<SpecializationSpellsEntry const*> const* specSpells = sDB2Manager.GetSpecializationSpells(m_petSpecialization))
    {
        for (size_t j = 0; j < specSpells->size(); ++j)
        {
            SpecializationSpellsEntry const* specSpell = specSpells->at(j);
            SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(specSpell->SpellID, DIFFICULTY_NONE);
            if (!spellInfo || spellInfo->SpellLevel > GetLevel())
                continue;

            learnedSpells.push_back(specSpell->SpellID);
        }
    }

    learnSpells(learnedSpells);
}

void Pet::RemoveSpecializationSpells(bool clearActionBar)
{
    std::vector<uint32> unlearnedSpells;

    for (uint32 i = 0; i < MAX_SPECIALIZATIONS; ++i)
    {
        if (ChrSpecializationEntry const* specialization = sDB2Manager.GetChrSpecializationByIndex(0, i))
        {
            if (std::vector<SpecializationSpellsEntry const*> const* specSpells = sDB2Manager.GetSpecializationSpells(specialization->ID))
            {
                for (size_t j = 0; j < specSpells->size(); ++j)
                {
                    SpecializationSpellsEntry const* specSpell = specSpells->at(j);
                    unlearnedSpells.push_back(specSpell->SpellID);
                }
            }
        }

        if (ChrSpecializationEntry const* specialization = sDB2Manager.GetChrSpecializationByIndex(PET_SPEC_OVERRIDE_CLASS_INDEX, i))
        {
            if (std::vector<SpecializationSpellsEntry const*> const* specSpells = sDB2Manager.GetSpecializationSpells(specialization->ID))
            {
                for (size_t j = 0; j < specSpells->size(); ++j)
                {
                    SpecializationSpellsEntry const* specSpell = specSpells->at(j);
                    unlearnedSpells.push_back(specSpell->SpellID);
                }
            }
        }
    }

    unlearnSpells(unlearnedSpells, true, clearActionBar);
}

void Pet::SetSpecialization(uint16 spec)
{
    if (m_petSpecialization == spec)
        return;

    // remove all the old spec's specalization spells, set the new spec, then add the new spec's spells
    // clearActionBars is false because we'll be updating the pet actionbar later so we don't have to do it now
    RemoveSpecializationSpells(false);
    if (!sChrSpecializationStore.LookupEntry(spec))
    {
        m_petSpecialization = 0;
        return;
    }

    m_petSpecialization = spec;
    LearnSpecializationSpells();

    // resend SMSG_PET_SPELLS_MESSAGE to remove old specialization spells from the pet action bar
    CleanupActionBar();
    GetOwner()->PetSpellInitialize();

    WorldPackets::Pet::SetPetSpecialization setPetSpecialization;
    setPetSpecialization.SpecID = m_petSpecialization;
    GetOwner()->GetSession()->SendPacket(setPetSpecialization.Write());
}

std::string Pet::GenerateActionBarData() const
{
    std::ostringstream ss;

    for (uint32 i = ACTION_BAR_INDEX_START; i < ACTION_BAR_INDEX_END; ++i)
    {
        ss << uint32(m_charmInfo->GetActionBarEntry(i)->GetType()) << ' '
           << uint32(m_charmInfo->GetActionBarEntry(i)->GetAction()) << ' ';
    }

    return ss.str();
}

std::string Pet::GetDebugInfo() const
{
    std::stringstream sstr;
    sstr << Guardian::GetDebugInfo() << "\n"
        << std::boolalpha
        << "PetType: " << std::to_string(getPetType()) << " "
        << "PetNumber: " << m_charmInfo->GetPetNumber();
    return sstr.str();
}
