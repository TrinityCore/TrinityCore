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

#include "Common.h"
#include "DatabaseEnv.h"
#include "Log.h"
#include "WorldPacket.h"
#include "ObjectMgr.h"
#include "PhasingHandler.h"
#include "SpellMgr.h"
#include "Pet.h"
#include "Formulas.h"
#include "SpellHistory.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "Transport.h"
#include "Unit.h"
#include "Util.h"
#include "Group.h"
#include "Opcodes.h"
#include "WorldSession.h"

#define PET_XP_FACTOR 0.05f

Pet::Pet(Player* owner, PetType type) :
    Guardian(nullptr, owner, true), m_usedTalentCount(0), m_removed(false),
    m_petType(type), m_duration(0), m_auraRaidUpdateMask(0), m_loading(false),
    m_declinedname(nullptr)
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
}

Pet::~Pet()
{
    delete m_declinedname;
}

void Pet::AddToWorld()
{
    ///- Register the pet for guid lookup
    if (!IsInWorld())
    {
        ///- Register the pet for guid lookup
        GetMap()->GetObjectsStore().Insert<Pet>(GetGUID(), this);
        Unit::AddToWorld();
        AIM_Initialize();
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

bool Pet::LoadPetData(Player* owner, uint32 petEntry, uint32 petnumber, bool current)
{
    m_loading = true;

    PlayerPetData* playerPetData;

    if (petnumber)
    {
        playerPetData = owner->GetPlayerPetDataById(petnumber);
    }
    else if ((getPetType() == SUMMON_PET) && petEntry)
    {
        playerPetData = owner->GetPlayerPetDataByCreatureId(petEntry);
    }
    else if (getPetType() == HUNTER_PET)
    {
        playerPetData = owner->GetPlayerPetDataBySlot(petEntry);
    }
    else
    {
        playerPetData = owner->GetPlayerPetDataCurrent();
    }

    if (!playerPetData)
    {
        m_loading = false;
        return false;
    }

    petEntry = playerPetData->CreatureId;
    if (!petEntry)
        return false;

    uint32 summonSpellId = playerPetData->SummonSpellId;
    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(summonSpellId);

    bool isTemporarySummon = spellInfo && spellInfo->GetDuration() > 0;
    if (current && isTemporarySummon)
        return false;

    PetType petType = playerPetData->Type;
    if (petType == HUNTER_PET)
    {
        CreatureTemplate const* creatureInfo = sObjectMgr->GetCreatureTemplate(petEntry);
        if (!creatureInfo)
        {
            owner->GetSession()->SendStableResult(STABLE_ERR_STABLE);
            return false;
        }

        if (!creatureInfo->IsTameable(owner->CanTameExoticPets()))
        {
            owner->GetSession()->SendStableResult(STABLE_ERR_EXOTIC);
            return false;
        }
    }

    uint32 petId = playerPetData->PetId;

    if (current && owner->IsPetNeedBeTemporaryUnsummoned())
    {
        owner->SetTemporaryUnsummonedPetNumber(petId);
        return false;
    }

    Map* map = owner->GetMap();
    ObjectGuid::LowType guid = map->GenerateLowGuid<HighGuid::Pet>();
    if (!Create(guid, map, petEntry, petId))
        return false;

    PhasingHandler::InheritPhaseShift(this, owner);

    setPetType(petType);
    SetFaction(owner->GetFaction());
    SetUInt32Value(UNIT_CREATED_BY_SPELL, summonSpellId);

    if (IsCritter())
    {
        Position pos = owner->GetPosition();
        owner->MovePositionToFirstCollision(pos, DEFAULT_FOLLOW_DISTANCE_PET, DEFAULT_FOLLOW_ANGLE);
        Relocate(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), owner->GetOrientation());

        if (!IsPositionValid())
        {
            TC_LOG_ERROR("entities.pet", "Pet (guidlow %d, entry %d) not loaded. Suggested coordinates isn't valid (X: %f Y: %f)",
                GetGUID().GetCounter(), GetEntry(), GetPositionX(), GetPositionY());
            return false;
        }

        Transport* transport = GetTransGUID().IsEmpty() ? owner->GetTransport() : nullptr;
        if (transport)
        {
            float x, y, z, o;
            GetPosition(x, y, z, o);
            transport->CalculatePassengerOffset(x, y, z, &o);
            m_movementInfo.transport.pos.Relocate(x, y, z, o);

            transport->AddPassenger(this);
        }

        map->AddToMap(this->ToCreature());
        return true;
    }

    m_charmInfo->SetPetNumber(petId, IsPermanentPetFor(owner));

    SetDisplayId(playerPetData->DisplayId);
    SetNativeDisplayId(playerPetData->DisplayId);
    uint32 petlevel = playerPetData->Petlevel;
    SetUInt32Value(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_NONE);
    SetName(playerPetData->Name);

    switch (getPetType())
    {
        case SUMMON_PET:
            petlevel = owner->getLevel();
            SetByteValue(UNIT_FIELD_BYTES_0, UNIT_BYTES_0_OFFSET_CLASS, uint8(CLASS_MAGE));
            SetUInt32Value(UNIT_FIELD_FLAGS, UNIT_FLAG_PLAYER_CONTROLLED);
            break;
        case HUNTER_PET:
            SetByteValue(UNIT_FIELD_BYTES_0, UNIT_BYTES_0_OFFSET_CLASS, CLASS_WARRIOR);
            SetByteValue(UNIT_FIELD_BYTES_0, UNIT_BYTES_0_OFFSET_GENDER, GENDER_NONE);
            SetSheath(SHEATH_STATE_MELEE);
            SetByteFlag(UNIT_FIELD_BYTES_2, UNIT_BYTES_2_OFFSET_PET_FLAGS, playerPetData->Renamed ? UNIT_CAN_BE_ABANDONED : UNIT_CAN_BE_RENAMED | UNIT_CAN_BE_ABANDONED);
            SetUInt32Value(UNIT_FIELD_FLAGS, UNIT_FLAG_PLAYER_CONTROLLED);
            break;
        default:
            if (!IsPetGhoul())
                TC_LOG_ERROR("entities.pet", "Pet have incorrect type (%u) for pet loading.", getPetType());
            break;
    }

    SetUInt32Value(UNIT_FIELD_PET_NAME_TIMESTAMP, uint32(GameTime::GetGameTime())); // cast can't be helped here
    SetCreatorGUID(owner->GetGUID());

    InitStatsForLevel(petlevel);
    SetUInt32Value(UNIT_FIELD_PETEXPERIENCE, playerPetData->PetExp);

    SynchronizeLevelWithOwner();

    Position pos = owner->GetPosition();
    owner->MovePositionToFirstCollision(pos, DEFAULT_FOLLOW_DISTANCE_PET, float(M_PI_2));
    Relocate(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), owner->GetOrientation());

    if (!IsPositionValid())
    {
        TC_LOG_ERROR("entities.pet", "Pet (guidlow %d, entry %d) not loaded. Suggested coordinates isn't valid (X: %f Y: %f)",
            GetGUID().GetCounter(), GetEntry(), GetPositionX(), GetPositionY());
        return false;
    }

    SetReactState(ReactStates(playerPetData->Reactstate));
    SetCanModifyStats(true);

    if (getPetType() == SUMMON_PET && !current)              //all (?) summon pets come with full health when called, but not when they are current
        SetPower(POWER_MANA, GetMaxPower(POWER_MANA));
    else
    {
        uint32 savedhealth = playerPetData->SavedHealth;
        uint32 savedmana = playerPetData->SavedMana;
        if (!savedhealth && getPetType() == HUNTER_PET)
            setDeathState(JUST_DIED);
        else
        {
            SetHealth(savedhealth > GetMaxHealth() ? GetMaxHealth() : savedhealth);
            SetPower(POWER_MANA, savedmana > uint32(GetMaxPower(POWER_MANA)) ? GetMaxPower(POWER_MANA) : savedmana);
        }
    }

    SetSlot(playerPetData->Slot);

    // Send fake summon spell cast - this is needed for correct cooldown application for spells
    // Example: 46584 - without this cooldown (which should be set always when pet is loaded) isn't set clientside
    /// @todo pets should be summoned from real cast instead of just faking it?
    if (summonSpellId)
    {
        WorldPacket data(SMSG_SPELL_GO, (8+8+4+4+2));
        data << owner->GetPackGUID();
        data << owner->GetPackGUID();
        data << uint8(0);
        data << uint32(summonSpellId);
        data << uint32(256); // CAST_FLAG_UNKNOWN3
        data << uint32(0);
        data << uint32(getMSTime());
        owner->SendMessageToSet(&data, true);
    }

    Transport* transport = GetTransGUID().IsEmpty() ? owner->GetTransport() : nullptr;
    if (transport)
    {
        float x, y, z, o;
        GetPosition(x, y, z, o);
        transport->CalculatePassengerOffset(x, y, z, &o);
        m_movementInfo.transport.pos.Relocate(x, y, z, o);

        transport->AddPassenger(this);
    }

    owner->SetMinion(this, true);
    map->AddToMap(ToCreature());

    InitTalentForLevel();                                   // set original talents points before spell loading

    uint32 timediff = uint32(GameTime::GetGameTime() - playerPetData->Timediff);
    _LoadAuras(timediff);

    // load action bar, if data broken will fill later by default spells.
    if (!isTemporarySummon)
    {
        m_charmInfo->LoadPetActionBar(playerPetData->Actionbar);

        _LoadSpells();
        InitTalentForLevel();                               // re-init to check talent count
        _LoadSpellCooldowns();
        LearnPetPassives();
        InitLevelupSpellsForLevel();
        if (map->IsBattleArena())
            RemoveArenaAuras();

        CastPetAuras(current);
        CastPetScalingAuras();
    }

    CleanupActionBar();                                     // remove unknown spells from action bar after load
    UpdateAllStats();
    SetFullHealth();                                        // Set full health and mana after pet scaling auras has been applied

    if (IsHunterPet())
        CastSpell(this, SPELL_PET_ENERGIZE, true);
    else
        SetPower(POWER_MANA, GetMaxPower(POWER_MANA));

    if (IsPetGhoul())
    {
        CastSpell(this, SPELL_PET_RISEN_GHOUL_SPAWN_IN, true);
        CastSpell(this, SPELL_PET_RISEN_GHOUL_SELF_STUN, true);
    }

    TC_LOG_DEBUG("entities.pet", "New Pet has guid %u", GetGUID().GetCounter());

    owner->PetSpellInitialize();

    if (owner->GetGroup())
        owner->SetGroupUpdateFlag(GROUP_UPDATE_PET);

    owner->SendTalentsInfoData(true);

    if (getPetType() == HUNTER_PET)
    {
        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_PET_DECLINED_NAME);
        stmt->setUInt32(0, owner->GetGUID().GetCounter());
        stmt->setUInt32(1, GetCharmInfo()->GetPetNumber());
        PreparedQueryResult result = CharacterDatabase.Query(stmt);

        if (result)
        {
            delete m_declinedname;
            m_declinedname = new DeclinedName;
            Field* fields2 = result->Fetch();
            for (uint8 i = 0; i < MAX_DECLINED_NAME_CASES; ++i)
            {
                m_declinedname->name[i] = fields2[i].GetString();
            }
        }
    }

    //set last used pet number (for use in BG's)
    if (owner->GetTypeId() == TYPEID_PLAYER && isControlled() && !isTemporarySummoned() && (getPetType() == SUMMON_PET || getPetType() == HUNTER_PET))
        owner->ToPlayer()->SetLastPetNumber(petId);

    // must be after SetMinion (owner guid check)
    LoadTemplateImmunities();
    m_loading = false;

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
    if (!GetOwnerOrCreatorGUID().IsPlayer())
        return;

    uint32 curhealth = GetHealth();
    uint32 curmana = GetPower(POWER_MANA);

    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
    // save auras before possibly removing them
    _SaveAuras(trans);

    _SaveSpells(trans);
    GetSpellHistory()->SaveToDB<Pet>(trans);
    CharacterDatabase.CommitTransaction(trans);

    PlayerPetData* playerPetData = GetOwner()->GetPlayerPetDataById(m_charmInfo->GetPetNumber());

    // save as new if no data for Pet in PlayerPetDataStore
    if (mode < PET_SAVE_NEW_PET && !playerPetData)
        mode = PET_SAVE_NEW_PET;

    if (mode == PET_SAVE_NEW_PET)
    {
        Optional<uint8> slot = IsHunterPet() ? GetOwner()->GetFirstUnusedActivePetSlot() : GetOwner()->GetFirstUnusedPetSlot();

        if (slot)
        {
            SetSlot(*slot);
            playerPetData = new PlayerPetData();
        }
        else
            mode = PET_SAVE_AS_DELETED;
    }

    if (mode == PET_SAVE_DISMISS || mode == PET_SAVE_LOGOUT)
        RemoveAllAuras();

    // whole pet is saved to DB
    if (mode >= PET_SAVE_CURRENT_STATE)
    {
        ObjectGuid::LowType ownerLowGUID = GetOwnerOrCreatorGUID().GetCounter();
        std::string name = m_name;
        CharacterDatabase.EscapeString(name);
        trans = CharacterDatabase.BeginTransaction();
        // remove current data

        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_PET_BY_ID);
        stmt->setUInt32(0, m_charmInfo->GetPetNumber());
        trans->Append(stmt);

        uint32 petId = m_charmInfo->GetPetNumber();

        // save pet
        stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_PET);
        stmt->setUInt32(0, petId);
        stmt->setUInt32(1, GetEntry());
        stmt->setUInt64(2, ownerLowGUID);
        stmt->setUInt32(3, GetNativeDisplayId());
        stmt->setUInt8(4, getLevel());
        stmt->setUInt32(5, GetUInt32Value(UNIT_FIELD_PETEXPERIENCE));
        stmt->setUInt8(6, GetReactState());
        stmt->setInt16(7, m_petSlot);
        stmt->setString(8, m_name);
        stmt->setUInt8(9, HasByteFlag(UNIT_FIELD_BYTES_2, UNIT_BYTES_2_OFFSET_PET_FLAGS, UNIT_CAN_BE_RENAMED) ? 0 : 1);
        stmt->setUInt8(10, mode == PET_SAVE_DISMISS ? 0 : 1);
        stmt->setUInt32(11, curhealth);
        stmt->setUInt32(12, curmana);

        stmt->setString(13, GenerateActionBarData());

        stmt->setUInt32(14, GameTime::GetGameTime()); // unsure about this
        stmt->setUInt32(15, GetUInt32Value(UNIT_CREATED_BY_SPELL));
        stmt->setUInt8(16, getPetType());
        trans->Append(stmt);

        CharacterDatabase.CommitTransaction(trans);

        if (m_petSlot > PET_SLOT_LAST)
            TC_LOG_ERROR("sql.sql", "Pet::SavePetToDB: bad slot %u for pet %u!", m_petSlot, petId);

        playerPetData->PetId = petId;
        playerPetData->CreatureId = GetEntry();
        playerPetData->Owner = ownerLowGUID;
        playerPetData->DisplayId = GetNativeDisplayId();
        playerPetData->Petlevel = getLevel();
        playerPetData->PetExp = GetUInt32Value(UNIT_FIELD_PETEXPERIENCE);
        playerPetData->Reactstate = GetReactState();
        playerPetData->Slot = m_petSlot;
        playerPetData->Name = m_name;
        playerPetData->Renamed = HasByteFlag(UNIT_FIELD_BYTES_2, UNIT_BYTES_2_OFFSET_PET_FLAGS, UNIT_CAN_BE_RENAMED) ? 0 : 1;
        playerPetData->Active = mode == PET_SAVE_DISMISS ? 0 : 1;
        playerPetData->SavedHealth = curhealth;
        playerPetData->SavedMana = curmana;
        playerPetData->Actionbar = GenerateActionBarData();
        playerPetData->Timediff = GameTime::GetGameTime();
        playerPetData->SummonSpellId = GetUInt32Value(UNIT_CREATED_BY_SPELL);
        playerPetData->Type = getPetType();

        if (mode == PET_SAVE_NEW_PET)
            GetOwner()->AddToPlayerPetDataStore(playerPetData);

    }
    // delete
    else
    {
        RemoveAllAuras();
        DeleteFromDB(m_charmInfo->GetPetNumber());

        GetOwner()->DeleteFromPlayerPetDataStore(m_charmInfo->GetPetNumber());
        GetOwner()->GetSession()->SendStablePet(ObjectGuid::Empty);
    }
}

void Pet::DeleteFromDB(ObjectGuid::LowType guidlow)
{
    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_PET_BY_ID);
    stmt->setUInt32(0, guidlow);
    trans->Append(stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_PET_DECLINEDNAME);
    stmt->setUInt32(0, guidlow);
    trans->Append(stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_PET_AURAS);
    stmt->setUInt32(0, guidlow);
    trans->Append(stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_PET_SPELLS);
    stmt->setUInt32(0, guidlow);
    trans->Append(stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_PET_SPELL_COOLDOWNS);
    stmt->setUInt32(0, guidlow);
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
            SetUInt32Value(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_NONE);
            RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_SKINNABLE);

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
            if (!IsHunterPet() || m_corpseRemoveTime <= GameTime::GetGameTime())
            {
                Remove(PET_SAVE_DISMISS);               //hunters' pets never get removed because of death, NEVER!
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
                Remove(PET_SAVE_DISMISS, true);
                return;
            }

            if (isControlled())
            {
                if (owner->GetPetGUID() != GetGUID())
                {
                    TC_LOG_ERROR("entities.pet", "Pet %u is not pet of owner %s, removed", GetEntry(), GetOwner()->GetName().c_str());
                    Remove(IsHunterPet() ? PET_SAVE_AS_DELETED : PET_SAVE_DISMISS);
                    return;
                }
            }

            if (m_duration > 0)
            {
                if (uint32(m_duration) > diff)
                    m_duration -= diff;
                else
                {
                    Remove(getPetType() != SUMMON_PET ? PET_SAVE_AS_DELETED : PET_SAVE_DISMISS);
                    return;
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
    if (!IsHunterPet())
        return;

    if (xp < 1)
        return;

    if (!IsAlive())
        return;

    uint8 maxlevel = std::min((uint8)sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL), GetOwner()->getLevel());
    uint8 petlevel = getLevel();

    // If pet is detected to be at, or above(?) the players level, don't hand out XP
    if (petlevel >= maxlevel)
       return;

    uint32 nextLvlXP = GetUInt32Value(UNIT_FIELD_PETNEXTLEVELEXP);
    uint32 curXP = GetUInt32Value(UNIT_FIELD_PETEXPERIENCE);
    uint32 newXP = curXP + xp;

    // Check how much XP the pet should receive, and hand off have any left from previous levelups
    while (newXP >= nextLvlXP && petlevel < maxlevel)
    {
        // Subtract newXP from amount needed for nextlevel, and give pet the level
        newXP -= nextLvlXP;
        ++petlevel;

        GivePetLevel(petlevel);

        nextLvlXP = GetUInt32Value(UNIT_FIELD_PETNEXTLEVELEXP);
    }
    // Not affected by special conditions - give it new XP
    SetUInt32Value(UNIT_FIELD_PETEXPERIENCE, petlevel < maxlevel ? newXP : 0);
}

void Pet::GivePetLevel(uint8 level)
{
    if (!level || level == getLevel())
        return;

    if (!IsHunterPet())
    {
        SetUInt32Value(UNIT_FIELD_PETEXPERIENCE, 0);
        SetUInt32Value(UNIT_FIELD_PETNEXTLEVELEXP, uint32(sObjectMgr->GetXPForLevel(level)*PET_XP_FACTOR));
    }

    InitStatsForLevel(level);
    InitLevelupSpellsForLevel();
    InitTalentForLevel();
}

bool Pet::CreateBaseAtCreature(Creature* creature)
{
    ASSERT(creature);

    if (!CreateBaseAtTamed(creature->GetCreatureTemplate(), creature->GetMap()))
        return false;

    Relocate(creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation());

    if (!IsPositionValid())
    {
        TC_LOG_ERROR("entities.pet", "Pet (guidlow %d, entry %d) not created base at creature. Suggested coordinates isn't valid (X: %f Y: %f)",
            GetGUID().GetCounter(), GetEntry(), GetPositionX(), GetPositionY());
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
        SetName(cFamily->Name);
    else
        SetName(creature->GetNameForLocaleIdx(sObjectMgr->GetDBCLocaleIndex()));

    Transport* transport = GetTransGUID().IsEmpty() ? creature->GetTransport() : nullptr;
    if (transport)
    {
        float x, y, z, o;
        GetPosition(x, y, z, o);
        transport->CalculatePassengerOffset(x, y, z, &o);
        m_movementInfo.transport.pos.Relocate(x, y, z, o);

        transport->AddPassenger(this);
    }

    return true;
}

bool Pet::CreateBaseAtCreatureInfo(CreatureTemplate const* cinfo, Unit* owner)
{
    if (!CreateBaseAtTamed(cinfo, owner->GetMap()))
        return false;

    if (CreatureFamilyEntry const* cFamily = sCreatureFamilyStore.LookupEntry(cinfo->family))
        SetName(cFamily->Name);

    Relocate(owner->GetPositionX(), owner->GetPositionY(), owner->GetPositionZ(), owner->GetOrientation());

    Transport* transport = GetTransGUID().IsEmpty() ? owner->GetTransport() : nullptr;
    if (transport)
    {
        float x, y, z, o;
        GetPosition(x, y, z, o);
        transport->CalculatePassengerOffset(x, y, z, &o);
        m_movementInfo.transport.pos.Relocate(x, y, z, o);

        transport->AddPassenger(this);
    }

    return true;
}

bool Pet::CreateBaseAtTamed(CreatureTemplate const* cinfo, Map* map)
{
    TC_LOG_DEBUG("entities.pet", "Pet::CreateBaseForTamed");
    ObjectGuid::LowType guid = map->GenerateLowGuid<HighGuid::Pet>();
    uint32 petId = sObjectMgr->GeneratePetNumber();
    if (!Create(guid, map, cinfo->Entry, petId))
        return false;

    SetUInt32Value(UNIT_FIELD_PET_NAME_TIMESTAMP, 0);
    SetUInt32Value(UNIT_FIELD_PETEXPERIENCE, 0);
    SetUInt32Value(UNIT_FIELD_PETNEXTLEVELEXP, uint32(sObjectMgr->GetXPForLevel(getLevel()+1)*PET_XP_FACTOR));
    SetUInt32Value(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_NONE);

    if (cinfo->type == CREATURE_TYPE_BEAST)
    {
        SetUInt32Value(UNIT_FIELD_BYTES_0, 0x02020100);
        SetByteValue(UNIT_FIELD_BYTES_0, UNIT_BYTES_0_OFFSET_CLASS, CLASS_WARRIOR);
        SetByteValue(UNIT_FIELD_BYTES_0, UNIT_BYTES_0_OFFSET_GENDER, GENDER_NONE);
        SetSheath(SHEATH_STATE_MELEE);
        SetByteFlag(UNIT_FIELD_BYTES_2, UNIT_BYTES_2_OFFSET_PET_FLAGS, UNIT_CAN_BE_RENAMED | UNIT_CAN_BE_ABANDONED);
    }

    return true;
}

bool Guardian::InitStatsForLevel(uint8 petlevel)
{
    CreatureTemplate const* cinfo = GetCreatureTemplate();
    ASSERT(cinfo);

    SetLevel(petlevel);

    //Determine pet type
    PetType petType = MAX_PET_TYPE;
    if (IsPet() && GetOwner()->GetTypeId() == TYPEID_PLAYER)
    {
        switch (m_owner->getClass())
        {
            case CLASS_WARLOCK:
            case CLASS_SHAMAN:
            case CLASS_DEATH_KNIGHT:
            case CLASS_MAGE:
            case CLASS_PRIEST:
                petType = SUMMON_PET;
                break;
            case CLASS_HUNTER:
                petType = HUNTER_PET;
                m_unitTypeMask |= UNIT_MASK_HUNTER_PET;
                break;
            default:
                TC_LOG_ERROR("entities.pet", "Unknown type pet %u is summoned by player class %u",
                    GetEntry(), GetOwner()->getClass());
                break;
        }
    }

    uint32 creature_ID = (petType == HUNTER_PET) ? 1 : cinfo->Entry;

    SetMeleeDamageSchool(SpellSchools(cinfo->dmgschool));

    SetAttackTime(BASE_ATTACK, BASE_ATTACK_TIME);
    SetAttackTime(OFF_ATTACK, BASE_ATTACK_TIME);
    SetAttackTime(RANGED_ATTACK, BASE_ATTACK_TIME);

    SetFloatValue(UNIT_MOD_CAST_SPEED, 1.0f);
    SetFloatValue(UNIT_MOD_CAST_HASTE, 1.0f);

    //scale
    SetObjectScale(GetNativeObjectScale());

    // Resistance
    // Hunters pets should not inherit resistances from creature_template, they have separate auras for that
    if (!IsHunterPet())
        for (uint8 i = SPELL_SCHOOL_HOLY; i < MAX_SPELL_SCHOOL; ++i)
            SetModifierValue(UnitMods(UNIT_MOD_RESISTANCE_START + i), BASE_VALUE, float(cinfo->resistance[i]));

    // Health, mana, armor and resistance
    PetLevelInfo const* pInfo = sObjectMgr->GetPetLevelInfo(creature_ID, petlevel);
    if (pInfo)                                      // exist in DB
    {
        SetCreateHealth(pInfo->health);
        SetCreateMana(pInfo->mana);

        if (pInfo->armor > 0)
            SetModifierValue(UNIT_MOD_ARMOR, BASE_VALUE, float(pInfo->armor));

        for (uint8 stat = 0; stat < MAX_STATS; ++stat)
            SetCreateStat(Stats(stat), float(pInfo->stats[stat]));
    }
    else                                            // not exist in DB, use some default fake data
    {
        // remove elite bonuses included in DB values
        // remove elite bonuses included in DB values
        CreatureBaseStats const* stats = sObjectMgr->GetCreatureBaseStats(petlevel, cinfo->unit_class);
        float healthmod = _GetHealthMod(cinfo->rank);
        uint32 basehp = stats->GenerateHealth(cinfo);
        uint32 health = uint32(basehp * healthmod);
        uint32 mana = stats->GenerateMana(cinfo);

        SetCreateHealth(health);
        SetCreateMana(mana);
        SetCreateStat(STAT_STRENGTH, 22);
        SetCreateStat(STAT_AGILITY, 22);
        SetCreateStat(STAT_STAMINA, 25);
        SetCreateStat(STAT_INTELLECT, 28);
        SetCreateStat(STAT_SPIRIT, 27);

        SetBaseWeaponDamage(BASE_ATTACK, MINDAMAGE, float(petlevel - (petlevel / 4)));
        SetBaseWeaponDamage(BASE_ATTACK, MAXDAMAGE, float(petlevel + (petlevel / 4)));
    }

    // Power
    if (petType == HUNTER_PET) // Hunter pets have focus
        SetPowerType(POWER_FOCUS);
    else if (IsPetGhoul() || IsRisenAlly()) // DK pets have energy
    {
        SetPowerType(POWER_ENERGY);
        SetFullPower(POWER_ENERGY);
    }
    else
        SetPowerType(POWER_MANA);

    // Damage
    SetBonusDamage(0);
    switch (petType)
    {
        case SUMMON_PET:
        {
            SetBaseWeaponDamage(BASE_ATTACK, MINDAMAGE, float(petlevel - (petlevel / 4)));
            SetBaseWeaponDamage(BASE_ATTACK, MAXDAMAGE, float(petlevel + (petlevel / 4)));
            break;
        }
        case HUNTER_PET:
        {
            SetUInt32Value(UNIT_FIELD_PETNEXTLEVELEXP, uint32(sObjectMgr->GetXPForLevel(petlevel) * PET_XP_FACTOR));
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
                case ENTRY_TREANT:
                {
                    float bonusDmg = GetOwner()->SpellBaseDamageBonusDone(SPELL_SCHOOL_MASK_NATURE) * 0.15f;
                    SetBaseWeaponDamage(BASE_ATTACK, MINDAMAGE, float(petlevel * 2.5f - (petlevel / 2) + bonusDmg));
                    SetBaseWeaponDamage(BASE_ATTACK, MAXDAMAGE, float(petlevel * 2.5f + (petlevel / 2) + bonusDmg));
                    SetCreateHealth(m_owner->CountPctFromMaxHealth(10));
                    break;
                }
                case ENTRY_EARTH_ELEMENTAL:
                {
                    if (Unit* owner = m_owner->GetOwner())
                        SetCreateHealth(owner->CountPctFromMaxHealth(75));

                    SetBaseWeaponDamage(BASE_ATTACK, MINDAMAGE, float(petlevel * 4 - petlevel));
                    SetBaseWeaponDamage(BASE_ATTACK, MAXDAMAGE, float(petlevel * 4 + petlevel));
                    break;
                }
                case ENTRY_FIRE_ELEMENTAL:
                {
                    if (Unit* owner = m_owner->GetOwner())
                    {
                        SetCreateHealth(owner->CountPctFromMaxHealth(75));
                        SetBonusDamage(int32(owner->SpellBaseDamageBonusDone(SPELL_SCHOOL_MASK_FIRE) * 0.5f));
                    }

                    SetCreateMana(28 + 10 * petlevel);
                    SetBaseWeaponDamage(BASE_ATTACK, MINDAMAGE, float(petlevel * 4 - petlevel));
                    SetBaseWeaponDamage(BASE_ATTACK, MAXDAMAGE, float(petlevel * 4 + petlevel));
                    break;
                }
                case ENTRY_SHADOWFIEND:
                {
                    SetCreateMana(28 + 10 * petlevel);
                    SetCreateHealth(28 + 30 * petlevel);
                    int32 bonus_dmg = int32(GetOwner()->SpellBaseDamageBonusDone(SPELL_SCHOOL_MASK_SHADOW)* 0.375f);
                    SetBaseWeaponDamage(BASE_ATTACK, MINDAMAGE, float((petlevel * 4 - petlevel) + bonus_dmg));
                    SetBaseWeaponDamage(BASE_ATTACK, MAXDAMAGE, float((petlevel * 4 + petlevel) + bonus_dmg));

                    break;
                }
                case ENTRY_VENOMOUS_SNAKE:
                {
                    SetBaseWeaponDamage(BASE_ATTACK, MINDAMAGE, float((petlevel / 2) - 25));
                    SetBaseWeaponDamage(BASE_ATTACK, MAXDAMAGE, float((petlevel / 2) - 18));
                    break;
                }
                case ENTRY_VIPER:
                {
                    SetBaseWeaponDamage(BASE_ATTACK, MINDAMAGE, float(petlevel / 2 - 10));
                    SetBaseWeaponDamage(BASE_ATTACK, MAXDAMAGE, float(petlevel / 2));
                    break;
                }
                case ENTRY_SPIRIT_WOLF:
                {
                    SetCreateHealth(30 * petlevel);
                    float dmg_multiplier = 0.50f;
                    if (m_owner->GetAuraEffect(63271, 0)) // Glyph of Feral Spirit
                        dmg_multiplier = 0.80f;

                    SetBonusDamage(int32(m_owner->GetTotalAttackPowerValue(BASE_ATTACK) * dmg_multiplier));

                    // wolf attack speed is 1.5s
                    SetAttackTime(BASE_ATTACK, cinfo->BaseAttackTime);

                    SetBaseWeaponDamage(BASE_ATTACK, MINDAMAGE, float((petlevel * 4 - petlevel)));
                    SetBaseWeaponDamage(BASE_ATTACK, MAXDAMAGE, float((petlevel * 4 + petlevel)));

                    // 14AP == 1dps, wolf's strike speed == 1.5s so dmg = AP / 14 * 1.5
                    SetBaseWeaponDamage(BASE_ATTACK, MINDAMAGE, m_owner->GetTotalAttackPowerValue(BASE_ATTACK) * dmg_multiplier / 14);
                    SetBaseWeaponDamage(BASE_ATTACK, MAXDAMAGE, m_owner->GetTotalAttackPowerValue(BASE_ATTACK) * dmg_multiplier / 14);

                    SetModifierValue(UNIT_MOD_ARMOR, BASE_VALUE, float(GetOwner()->GetArmor()) * 0.35f);  // Bonus Armor (35% of player armor)
                    SetModifierValue(UNIT_MOD_STAT_STAMINA, BASE_VALUE, float(GetOwner()->GetStat(STAT_STAMINA)) * 0.3f);  // Bonus Stamina (30% of player stamina)
                    if (!HasAura(58877))        // Spirit Hunt
                        AddAura(58877, this);
                    if (!HasAura(61783))        // Feral Pet Scaling
                        AddAura(61783, this);
                    break;
                }
                case ENTRY_GARGOYLE:
                {
                    SetCreateHealth(m_owner->CountPctFromMaxHealth(70));
                    if (Player* owner = m_owner->ToPlayer())
                    {
                        float bonus = owner->GetRatingBonusValue(CR_HASTE_MELEE);
                        bonus += owner->GetTotalAuraModifier(SPELL_AURA_MOD_MELEE_HASTE_3) +
                            owner->GetTotalAuraModifier(SPELL_AURA_MOD_MELEE_RANGED_HASTE);
                        ApplyCastTimePercentMod(bonus, true);
                    }

                    SetBonusDamage(int32(GetOwner()->GetTotalAttackPowerValue(BASE_ATTACK) * 0.5f));
                    SetBaseWeaponDamage(BASE_ATTACK, MINDAMAGE, float(petlevel - (petlevel / 4)));
                    SetBaseWeaponDamage(BASE_ATTACK, MAXDAMAGE, float(petlevel + (petlevel / 4)));
                    break;
                }
                case ENTRY_BLOODWORM:
                {
                    SetCreateHealth(m_owner->CountPctFromMaxHealth(18));
                    SetAttackTime(BASE_ATTACK, 1400);
                    SetBonusDamage(int32(m_owner->GetTotalAttackPowerValue(BASE_ATTACK) * 0.006f));
                    float minDamage = m_owner->GetTotalAttackPowerValue(BASE_ATTACK) * 0.05f;
                    float maxDamage = m_owner->GetTotalAttackPowerValue(BASE_ATTACK) * 0.05f;
                    SetBaseWeaponDamage(BASE_ATTACK, MINDAMAGE, minDamage);
                    SetBaseWeaponDamage(BASE_ATTACK, MAXDAMAGE, maxDamage);
                    if (!HasAura(50453))        // Blood Siphon
                        CastSpell(this, 50453, true);
                    break;
                }
                case ENTRY_INFERNAL:
                {
                    if (m_owner->GetTypeId() == TYPEID_PLAYER) // Infernal get 100% of owners spell, Immolation has his own coef.
                        SetBonusDamage(int32(m_owner->SpellBaseDamageBonusDone(SPELL_SCHOOL_MASK_SPELL)));

                    float mod = 1;
                    if (petlevel < 60)
                        mod = 5 + (petlevel - 50) / 4;
                    if (petlevel < 70)
                        mod = 10 + (petlevel - 70) / 4;
                    else if (petlevel <= 80)
                        mod = 15 + (petlevel - 80) / 2;
                    else
                        mod = 20 + (petlevel - 85) / 2;
                    if (mod < 0)
                        mod = 0;
                    float minDamage = (petlevel - (petlevel / 4)) * mod;
                    float maxDamage = (petlevel + (petlevel / 4)) * mod;
                    float attackPower = ((minDamage + maxDamage) /4) * 7;
                    SetBaseWeaponDamage(BASE_ATTACK, MINDAMAGE, minDamage);
                    SetBaseWeaponDamage(BASE_ATTACK, MAXDAMAGE, maxDamage);
                    SetModifierValue(UNIT_MOD_ATTACK_POWER, BASE_VALUE, attackPower);
                    SetCreateHealth(m_owner->CountPctFromMaxHealth(40));
                    break;
                }
                case ENTRY_EBON_IMP:
                    SetBonusDamage(m_owner->SpellBaseDamageBonusDone(SPELL_SCHOOL_MASK_FIRE));
                    break;
                case ENTRY_ARMY_OF_THE_DEAD_GHOUL:
                {
                    SetCreateHealth(m_owner->CountPctFromMaxHealth(30));
                    SetBonusDamage(int32(GetOwner()->GetTotalAttackPowerValue(BASE_ATTACK) * 0.5f));
                    float minDamage = m_owner->GetTotalAttackPowerValue(BASE_ATTACK) * 0.05f;
                    float maxDamage = m_owner->GetTotalAttackPowerValue(BASE_ATTACK) * 0.05f;
                    SetBaseWeaponDamage(BASE_ATTACK, MINDAMAGE, minDamage);
                    SetBaseWeaponDamage(BASE_ATTACK, MAXDAMAGE, maxDamage);
                    if (!HasAura(62137))        // Avoidance
                        CastSpell(this, 62137, true);
                    break;
                }
                case ENTRY_GHOUL:
                    if (!HasAura(62137))        // Avoidance
                        CastSpell(this, 62137, true);
                    break;
                default:
                {
                    /* ToDo: Check what 5f5d2028 broke/fixed and how much of Creature::UpdateLevelDependantStats()
                     * should be copied here (or moved to another method or if that function should be called here
                     * or not just for this default case)
                     */
                    CreatureBaseStats const* stats = sObjectMgr->GetCreatureBaseStats(petlevel, cinfo->unit_class);
                    float basedamage = stats->GenerateBaseDamage(cinfo);

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
    SetPower(POWER_MANA, GetMaxPower(POWER_MANA));
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

uint32 Pet::GetCurrentFoodBenefitLevel(uint32 itemlevel) const
{
    // -10 or greater food level
    if (getLevel() <= itemlevel + 10)                         // possible to feed level 85 pet with ilevel 75 level food for full effect
        return 50;
    // -10 to -20
    else if (getLevel() <= itemlevel + 20)
        return 25;
    // -20 to -30
    else if (getLevel() <= itemlevel + 30)
        return 13;
    // -30 or more difference
    else
        return 0;                                           //food too low level
}

void Pet::_LoadSpellCooldowns()
{
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_PET_SPELL_COOLDOWN);
    stmt->setUInt32(0, m_charmInfo->GetPetNumber());
    PreparedQueryResult cooldownsResult = CharacterDatabase.Query(stmt);

    GetSpellHistory()->LoadFromDB<Pet>(cooldownsResult);
}

void Pet::_LoadSpells()
{
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_PET_SPELL);
    stmt->setUInt32(0, m_charmInfo->GetPetNumber());
    PreparedQueryResult result = CharacterDatabase.Query(stmt);

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

void Pet::_SaveSpells(CharacterDatabaseTransaction& trans)
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

void Pet::_LoadAuras(uint32 timediff)
{
    TC_LOG_DEBUG("entities.pet", "Loading auras for pet %u", GetGUID().GetCounter());

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_PET_AURA);
    stmt->setUInt32(0, m_charmInfo->GetPetNumber());
    PreparedQueryResult result = CharacterDatabase.Query(stmt);

    if (result)
    {
        do
        {
            int32 damage[3];
            int32 baseDamage[3];
            Field* fields = result->Fetch();
            ObjectGuid caster_guid(fields[0].GetUInt64());
            // nullptr guid stored - pet is the caster of the spell - see Pet::_SaveAuras
            if (!caster_guid)
                caster_guid = GetGUID();
            uint32 spellid = fields[1].GetUInt32();
            uint8 effmask = fields[2].GetUInt8();
            uint8 recalculatemask = fields[3].GetUInt8();
            uint8 stackcount = fields[4].GetUInt8();
            damage[0] = fields[5].GetInt32();
            damage[1] = fields[6].GetInt32();
            damage[2] = fields[7].GetInt32();
            baseDamage[0] = fields[8].GetInt32();
            baseDamage[1] = fields[9].GetInt32();
            baseDamage[2] = fields[10].GetInt32();
            int32 maxduration = fields[11].GetInt32();
            int32 remaintime = fields[12].GetInt32();
            uint8 remaincharges = fields[13].GetUInt8();

            SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellid);
            if (!spellInfo)
            {
                TC_LOG_ERROR("entities.pet", "Unknown aura (spellid %u), ignore.", spellid);
                continue;
            }

            // negative effects should continue counting down after logout
            if (remaintime != -1 && (!spellInfo->IsPositive() || spellInfo->HasAttribute(SPELL_ATTR4_FADES_WHILE_LOGGED_OUT)))
            {
                if (remaintime/IN_MILLISECONDS <= int32(timediff))
                    continue;

                remaintime -= timediff*IN_MILLISECONDS;
            }

            // prevent wrong values of remaincharges
            if (spellInfo->ProcCharges)
            {
                if (remaincharges <= 0 || remaincharges > spellInfo->ProcCharges)
                    remaincharges = spellInfo->ProcCharges;
            }
            else
                remaincharges = 0;

            if (Aura* aura = Aura::TryCreate(spellInfo, effmask, this, nullptr, &baseDamage[0], nullptr, caster_guid))
            {
                if (!aura->CanBeSaved())
                {
                    aura->Remove();
                    continue;
                }
                aura->SetLoadedState(maxduration, remaintime, remaincharges, stackcount, recalculatemask, &damage[0]);
                aura->ApplyForTargets();
                TC_LOG_DEBUG("entities.pet", "Added aura spellid %u, effectmask %u", spellInfo->Id, effmask);
            }
        }
        while (result->NextRow());
    }
}

void Pet::_SaveAuras(CharacterDatabaseTransaction& trans)
{
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_PET_AURAS);
    stmt->setUInt32(0, m_charmInfo->GetPetNumber());
    trans->Append(stmt);

    for (AuraMap::const_iterator itr = m_ownedAuras.begin(); itr != m_ownedAuras.end(); ++itr)
    {
        // check if the aura has to be saved
        if (!itr->second->CanBeSaved() || IsPetAura(itr->second))
            continue;

        Aura* aura = itr->second;

        int32 damage[MAX_SPELL_EFFECTS];
        int32 baseDamage[MAX_SPELL_EFFECTS];
        uint8 effMask = 0;
        uint8 recalculateMask = 0;
        for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
        {
            if (aura->GetEffect(i))
            {
                baseDamage[i] = aura->GetEffect(i)->GetBaseAmount();
                damage[i] = aura->GetEffect(i)->GetAmount();
                effMask |= (1<<i);
                if (aura->GetEffect(i)->CanBeRecalculated())
                    recalculateMask |= (1<<i);
            }
            else
            {
                baseDamage[i] = 0;
                damage[i] = 0;
            }
        }

        // don't save guid of caster in case we are caster of the spell - guid for pet is generated every pet load, so it won't match saved guid anyways
        ObjectGuid casterGUID = (itr->second->GetCasterGUID() == GetGUID()) ? ObjectGuid::Empty : itr->second->GetCasterGUID();

        uint8 index = 0;

        stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_PET_AURA);
        stmt->setUInt32(index++, m_charmInfo->GetPetNumber());
        stmt->setUInt64(index++, casterGUID.GetRawValue());
        stmt->setUInt32(index++, itr->second->GetId());
        stmt->setUInt8(index++, effMask);
        stmt->setUInt8(index++, recalculateMask);
        stmt->setUInt8(index++, itr->second->GetStackAmount());
        stmt->setInt32(index++, damage[0]);
        stmt->setInt32(index++, damage[1]);
        stmt->setInt32(index++, damage[2]);
        stmt->setInt32(index++, baseDamage[0]);
        stmt->setInt32(index++, baseDamage[1]);
        stmt->setInt32(index++, baseDamage[2]);
        stmt->setInt32(index++, itr->second->GetMaxDuration());
        stmt->setInt32(index++, itr->second->GetDuration());
        stmt->setUInt8(index++, itr->second->GetCharges());

        trans->Append(stmt);
    }
}

bool Pet::addSpell(uint32 spellId, ActiveStates active /*= ACT_DECIDE*/, PetSpellState state /*= PETSPELL_NEW*/, PetSpellType type /*= PETSPELL_NORMAL*/)
{
    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellId);
    if (!spellInfo)
    {
        // do pet spell book cleanup
        if (state == PETSPELL_UNCHANGED)                    // spell load case
        {
            TC_LOG_ERROR("entities.pet", "Pet::addSpell: Non-existed in SpellStore spell #%u request, deleting for all pets in `pet_spell`.", spellId);

            CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_INVALID_PET_SPELL);

            stmt->setUInt32(0, spellId);

            CharacterDatabase.Execute(stmt);
        }
        else
            TC_LOG_ERROR("entities.pet", "Pet::addSpell: Non-existed in SpellStore spell #%u request.", spellId);

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
            newspell.active = ACT_ENABLED;
        else
            newspell.active = ACT_PASSIVE;
    }
    else
        newspell.active = active;

    // talent: unlearn all other talent ranks (high and low)
    if (TalentSpellPos const* talentPos = sDBCManager.GetTalentSpellPos(spellId))
    {
        if (TalentEntry const* talentInfo = sTalentStore.LookupEntry(talentPos->talent_id))
        {
            for (uint8 i = 0; i < MAX_TALENT_RANK; ++i)
            {
                // skip learning spell and no rank spell case
                uint32 rankSpellId = talentInfo->SpellRank[i];
                if (!rankSpellId || rankSpellId == spellId)
                    continue;

                // skip unknown ranks
                if (!HasSpell(rankSpellId))
                    continue;
                removeSpell(rankSpellId, false, false);
            }
        }
    }
    else if (spellInfo->IsRanked())
    {
        for (PetSpellMap::const_iterator itr2 = m_spells.begin(); itr2 != m_spells.end(); ++itr2)
        {
            if (itr2->second.state == PETSPELL_REMOVED)
                continue;

            SpellInfo const* oldRankSpellInfo = sSpellMgr->GetSpellInfo(itr2->first);

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

    // Store pet scaling auras in a own vector to handle the updating more efficient
    if (spellInfo->HasAttribute(SPELL_ATTR4_IS_PET_SCALING))
    {
        m_petScalingAuras.push_back(spellInfo->Id);
        return true;
    }

    m_spells[spellId] = newspell;

    // Do not go further if this Attribute exists
    if (spellInfo->HasAttribute(SPELL_ATTR4_UNK15) && !IsWarlockMinion())
         return true;

    if (spellInfo->IsPassive() && (!spellInfo->CasterAuraState || HasAuraState(AuraStateType(spellInfo->CasterAuraState))))
        CastSpell(this, spellId, true);
    else
        m_charmInfo->AddSpellToActionBar(spellInfo);

    if (newspell.active == ACT_ENABLED)
        ToggleAutocast(spellInfo, true);

    uint32 talentCost = sDBCManager.GetTalentSpellCost(spellId);
    if (talentCost)
    {
        int32 free_points = GetMaxTalentPointsForLevel(getLevel());
        m_usedTalentCount += talentCost;
        // update free talent points
        free_points-=m_usedTalentCount;
        SetFreeTalentPoints(free_points > 0 ? free_points : 0);
    }
    return true;
}

bool Pet::learnSpell(uint32 spell_id)
{
    // prevent duplicated entires in spell book
    if (!addSpell(spell_id))
        return false;

    if (!m_loading && getPetType() != SUMMON_PET)
    {
        WorldPacket data(SMSG_PET_LEARNED_SPELL, 4);
        data << uint32(spell_id);
        GetOwner()->SendDirectMessage(&data);
        GetOwner()->PetSpellInitialize();
    }
    return true;
}

void Pet::InitLevelupSpellsForLevel()
{
    uint8 level = getLevel();

    if (PetLevelupSpellSet const* levelupSpells = GetCreatureTemplate()->family ? sSpellMgr->GetPetLevelupSpellList(GetCreatureTemplate()->family) : nullptr)
    {
        // PetLevelupSpellSet ordered by levels
        for (PetLevelupSpellSet::const_iterator itr = levelupSpells->begin(); itr != levelupSpells->end(); ++itr)
        {
            // will called first if level down
            if (itr->first > level)
                unlearnSpell(itr->second, true);                 // will learn prev rank if any
            // will called if level up
            else
                learnSpell(itr->second);                        // will unlearn prev rank if any
        }
    }

    int32 petSpellsId = GetCreatureTemplate()->PetSpellDataId ? -(int32)GetCreatureTemplate()->PetSpellDataId : GetEntry();

    // default spells (can be not learned if pet level (as owner level decrease result for example) less first possible in normal game)
    if (PetDefaultSpellsEntry const* defSpells = sSpellMgr->GetPetDefaultSpellsEntry(petSpellsId))
    {
        for (uint8 i = 0; i < MAX_CREATURE_SPELL_DATA_SLOT; ++i)
        {
            SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(defSpells->spellid[i]);
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
        if (!m_loading && getPetType() != SUMMON_PET)
        {
            WorldPacket data(SMSG_PET_REMOVED_SPELL, 4);
            data << uint32(spell_id);
            GetOwner()->SendDirectMessage(&data);
        }
        return true;
    }
    return false;
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

    uint32 talentCost = sDBCManager.GetTalentSpellCost(spell_id);
    if (talentCost > 0)
    {
        if (m_usedTalentCount > talentCost)
            m_usedTalentCount -= talentCost;
        else
            m_usedTalentCount = 0;
        // update free talent points
        int32 free_points = GetMaxTalentPointsForLevel(getLevel()) - m_usedTalentCount;
        SetFreeTalentPoints(free_points > 0 ? free_points : 0);
    }

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
                    if (SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(ab->GetAction()))
                        ToggleAutocast(spellInfo, true);
                }
            }
}

void Pet::InitPetCreateSpells()
{
    m_charmInfo->InitPetActionBar();
    m_spells.clear();
    m_petScalingAuras.clear();

    LearnPetPassives();
    InitLevelupSpellsForLevel();
    CastPetAuras(false);
    CastPetScalingAuras();
}

bool Pet::resetTalents()
{
    Player* player = GetOwner();

    // not need after this call
    if (player->HasAtLoginFlag(AT_LOGIN_RESET_PET_TALENTS))
        player->RemoveAtLoginFlag(AT_LOGIN_RESET_PET_TALENTS, true);

    CreatureTemplate const* ci = GetCreatureTemplate();
    if (!ci)
        return false;
    // Check pet talent type
    CreatureFamilyEntry const* pet_family = sCreatureFamilyStore.LookupEntry(ci->family);
    if (!pet_family || pet_family->PetTalentType < 0)
        return false;

    uint8 level = getLevel();
    uint32 talentPointsForLevel = GetMaxTalentPointsForLevel(level);

    if (m_usedTalentCount == 0)
    {
        SetFreeTalentPoints(talentPointsForLevel);
        return false;
    }

    for (uint32 i = 0; i < sTalentStore.GetNumRows(); ++i)
    {
        TalentEntry const* talentInfo = sTalentStore.LookupEntry(i);

        if (!talentInfo)
            continue;

        TalentTabEntry const* talentTabInfo = sTalentTabStore.LookupEntry(talentInfo->TabID);

        if (!talentTabInfo)
            continue;

        // unlearn only talents for pets family talent type
        if (!((1 << pet_family->PetTalentType) & talentTabInfo->CategoryEnumID))
            continue;

        for (uint8 j = 0; j < MAX_TALENT_RANK; ++j)
        {
            for (PetSpellMap::const_iterator itr = m_spells.begin(); itr != m_spells.end();)
            {
                if (itr->second.state == PETSPELL_REMOVED)
                {
                    ++itr;
                    continue;
                }
                // remove learned spells (all ranks)
                uint32 itrFirstId = sSpellMgr->GetFirstSpellInChain(itr->first);

                // unlearn if first rank is talent or learned by talent
                if (itrFirstId == talentInfo->SpellRank[j] || sSpellMgr->IsSpellLearnToSpell(talentInfo->SpellRank[j], itrFirstId))
                {
                    unlearnSpell(itr->first, false);
                    itr = m_spells.begin();
                    continue;
                }
                else
                    ++itr;
            }
        }
    }

    SetFreeTalentPoints(talentPointsForLevel);

    if (!m_loading)
        player->PetSpellInitialize();
    return true;
}

void Pet::resetTalentsForAllPetsOf(Player* /*owner*/, Pet* /*onlinePet*/ /*= nullptr*/)
{
    /*
    // not need after this call
    if (owner->HasAtLoginFlag(AT_LOGIN_RESET_PET_TALENTS))
        owner->RemoveAtLoginFlag(AT_LOGIN_RESET_PET_TALENTS, true);

    // reset for online
    if (onlinePet)
        onlinePet->resetTalents();

    // now need only reset for offline pets (all pets except online case)
    uint32 exceptPetNumber = onlinePet ? onlinePet->GetCharmInfo()->GetPetNumber() : 0;

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHAR_PET);
    stmt->setUInt32(0, owner->GetGUID().GetCounter());
    stmt->setUInt32(1, exceptPetNumber);
    PreparedQueryResult resultPets = CharacterDatabase.Query(stmt);

    // no offline pets
    if (!resultPets)
        return;

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_PET_SPELL_LIST);
    stmt->setUInt32(0, owner->GetGUID().GetCounter());
    stmt->setUInt32(1, exceptPetNumber);
    PreparedQueryResult result = CharacterDatabase.Query(stmt);

    if (!result)
        return;

    bool need_comma = false;
    std::ostringstream ss;
    ss << "DELETE FROM pet_spell WHERE guid IN (";

    do
    {
        Field* fields = resultPets->Fetch();

        uint32 id = fields[0].GetUInt32();

        if (need_comma)
            ss << ',';

        ss << id;

        need_comma = true;
    } while (resultPets->NextRow());

    ss << ") AND spell IN (";

    bool need_execute = false;
    do
    {
        Field* fields = result->Fetch();

        uint32 spell = fields[0].GetUInt32();

        if (!GetTalentSpellCost(spell))
            continue;

        if (need_execute)
            ss << ',';

        ss << spell;

        need_execute = true;
    }
    while (result->NextRow());

    if (!need_execute)
        return;

    ss << ')';

    CharacterDatabase.Execute(ss.str().c_str());
    */
}

void Pet::InitTalentForLevel()
{
    uint8 level = getLevel();
    uint32 talentPointsForLevel = GetMaxTalentPointsForLevel(level);
    // Reset talents in case low level (on level down) or wrong points for level (hunter can unlearn TP increase talent)
    if (talentPointsForLevel == 0 || m_usedTalentCount > talentPointsForLevel)
        resetTalents(); // Remove all talent points

    SetFreeTalentPoints(talentPointsForLevel - m_usedTalentCount);

    if (!m_loading)
        GetOwner()->SendTalentsInfoData(true);
}

uint8 Pet::GetMaxTalentPointsForLevel(uint8 level) const
{
    uint8 points = (level >= 20) ? ((level - 16) / 4) : 0;
    // Mod points from owner SPELL_AURA_MOD_PET_TALENT_POINTS
    points += GetOwner()->GetTotalAuraModifier(SPELL_AURA_MOD_PET_TALENT_POINTS);
    return points;
}

void Pet::ToggleAutocast(SpellInfo const* spellInfo, bool apply)
{
    if (!spellInfo->IsAutocastable())
        return;

    uint32 spellid = spellInfo->Id;

    PetSpellMap::iterator itr = m_spells.find(spellid);
    if (itr == m_spells.end())
        return;

    uint32 i;

    if (apply)
    {
        for (i = 0; i < m_autospells.size() && m_autospells[i] != spellid; ++i)
            ;                                               // just search

        if (i == m_autospells.size())
        {
            m_autospells.push_back(spellid);

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
        AutoSpellList::iterator itr2 = m_autospells.begin();
        for (i = 0; i < m_autospells.size() && m_autospells[i] != spellid; ++i, ++itr2)
            ;                                               // just search

        if (i < m_autospells.size())
        {
            m_autospells.erase(itr2);
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
            switch (owner->getClass())
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

bool Pet::Create(ObjectGuid::LowType guidlow, Map* map, uint32 Entry, uint32 petId)
{
    ASSERT(map);
    SetMap(map);

    Object::_Create(guidlow, petId, HighGuid::Pet);

    m_spawnId = guidlow;
    m_originalEntry = Entry;

    if (!InitEntry(Entry))
        return false;

    // Force regen flag for player pets, just like we do for players themselves
    SetFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_REGENERATE_POWER);
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

    PetFamilySpellsStore::const_iterator petStore = sPetFamilySpellsStore.find(cFamily->ID);
    if (petStore != sPetFamilySpellsStore.end())
    {
        for (PetFamilySpellsSet::const_iterator petSet = petStore->second.begin(); petSet != petStore->second.end(); ++petSet)
            addSpell(*petSet, ACT_DECIDE, PETSPELL_NEW, PETSPELL_FAMILY);
    }
}

void Pet::CastPetScalingAuras()
{
    for (uint32 spellId : m_petScalingAuras)
    {
        if (!HasAura(spellId))
            CastSpell(this, spellId, true);
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
        args.SpellValueOverrides.AddMod(SPELLVALUE_BASE_POINT0, CalculatePct(aura->GetDamage(), GetStat(STAT_STAMINA) + GetStat(STAT_INTELLECT)));

    CastSpell(this, auraId, args);
}

bool Pet::IsPetAura(Aura const* aura)
{
    Player* owner = GetOwner();

    // if the owner has that pet aura, return true
    for (auto itr = owner->m_petAuras.begin(); itr != owner->m_petAuras.end(); ++itr)
    {
        if ((*itr)->GetAura(GetEntry()) == aura->GetId())
            return true;
    }
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
            GivePetLevel(owner->getLevel());
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
    CreatureDisplayInfoEntry const* displayInfo = sCreatureDisplayInfoStore.LookupEntry(GetNativeDisplayId());

    if (creatureFamily && displayInfo && creatureFamily->MinScale > 0.0f && getPetType() == HUNTER_PET)
    {
        if (CreatureModelDataEntry const* modelData = sCreatureModelDataStore.LookupEntry(displayInfo->ModelID))
        {
            float scale = displayInfo->CreatureModelScale * modelData->ModelScale;
            if (scale <= 0.f)
                scale = 1.f;

            float minScaleLevel = creatureFamily->MinScaleLevel;
            uint8 level = getLevel();

            float minLevelScaleMod = level >= minScaleLevel ? level - minScaleLevel : 0.f;
            float maxScaleMod = creatureFamily->MaxScaleLevel - minScaleLevel;

            if (minLevelScaleMod > maxScaleMod)
                minLevelScaleMod = maxScaleMod;

            float scaleMod = creatureFamily->MaxScaleLevel != minScaleLevel ? minLevelScaleMod / maxScaleMod : 0.f;

            scale = (creatureFamily->MaxScale - creatureFamily->MinScale) * scaleMod + creatureFamily->MinScale;
            if (modelData->TamedPetBaseScale > 0.f)
                scale *= modelData->TamedPetBaseScale;

            return scale;
        }
    }

    return Guardian::GetNativeObjectScale();
}

void Pet::SetDisplayId(uint32 modelId)
{
    Guardian::SetDisplayId(modelId);

    if (!isControlled())
        return;

    if (GetOwner()->GetGroup())
        GetOwner()->SetGroupUpdateFlag(GROUP_UPDATE_FLAG_PET_MODEL_ID);
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

void Pet::UpdatePetScalingAuras()
{
    for (uint32 spellId : m_petScalingAuras)
    {
        if (Aura* aura = GetAura(spellId))
            aura->RecalculateAmountOfEffects();
    }
}
