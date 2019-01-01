/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

#include "SpellHistory.h"
#include "DatabaseEnv.h"
#include "DB2Stores.h"
#include "Item.h"
#include "ObjectMgr.h"
#include "Pet.h"
#include "PetPackets.h"
#include "Player.h"
#include "Spell.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include "SpellPackets.h"
#include "World.h"

SpellHistory::Clock::duration const SpellHistory::InfinityCooldownDelay = std::chrono::duration_cast<SpellHistory::Clock::duration>(std::chrono::seconds(MONTH));

template<>
struct SpellHistory::PersistenceHelper<Player>
{
    static CharacterDatabaseStatements const CooldownsDeleteStatement = CHAR_DEL_CHAR_SPELL_COOLDOWNS;
    static CharacterDatabaseStatements const CooldownsInsertStatement = CHAR_INS_CHAR_SPELL_COOLDOWN;
    static CharacterDatabaseStatements const ChargesDeleteStatement = CHAR_DEL_CHAR_SPELL_CHARGES;
    static CharacterDatabaseStatements const ChargesInsertStatement = CHAR_INS_CHAR_SPELL_CHARGES;

    static void SetIdentifier(PreparedStatement* stmt, uint8 index, Unit* owner) { stmt->setUInt64(index, owner->GetGUID().GetCounter()); }

    static bool ReadCooldown(Field* fields, uint32* spellId, CooldownEntry* cooldownEntry)
    {
        *spellId = fields[0].GetUInt32();
        if (!sSpellMgr->GetSpellInfo(*spellId))
            return false;

        cooldownEntry->SpellId = *spellId;
        cooldownEntry->CooldownEnd = Clock::from_time_t(time_t(fields[2].GetUInt32()));
        cooldownEntry->ItemId = fields[1].GetUInt32();
        cooldownEntry->CategoryId = fields[3].GetUInt32();
        cooldownEntry->CategoryEnd = Clock::from_time_t(time_t(fields[4].GetUInt32()));
        return true;
    }

    static bool ReadCharge(Field* fields, uint32* categoryId, ChargeEntry* chargeEntry)
    {
        *categoryId = fields[0].GetUInt32();
        if (!sSpellCategoryStore.LookupEntry(*categoryId))
            return false;

        chargeEntry->RechargeStart = Clock::from_time_t(time_t(fields[1].GetUInt32()));
        chargeEntry->RechargeEnd = Clock::from_time_t(time_t(fields[2].GetUInt32()));
        return true;
    }

    static void WriteCooldown(PreparedStatement* stmt, uint8& index, CooldownStorageType::value_type const& cooldown)
    {
        stmt->setUInt32(index++, cooldown.first);
        stmt->setUInt32(index++, cooldown.second.ItemId);
        stmt->setUInt32(index++, uint32(Clock::to_time_t(cooldown.second.CooldownEnd)));
        stmt->setUInt32(index++, cooldown.second.CategoryId);
        stmt->setUInt32(index++, uint32(Clock::to_time_t(cooldown.second.CategoryEnd)));
    }

    static void WriteCharge(PreparedStatement* stmt, uint8& index, uint32 chargeCategory, ChargeEntry const& charge)
    {
        stmt->setUInt32(index++, chargeCategory);
        stmt->setUInt32(index++, uint32(Clock::to_time_t(charge.RechargeStart)));
        stmt->setUInt32(index++, uint32(Clock::to_time_t(charge.RechargeEnd)));
    }
};

template<>
struct SpellHistory::PersistenceHelper<Pet>
{
    static CharacterDatabaseStatements const CooldownsDeleteStatement = CHAR_DEL_PET_SPELL_COOLDOWNS;
    static CharacterDatabaseStatements const CooldownsInsertStatement = CHAR_INS_PET_SPELL_COOLDOWN;
    static CharacterDatabaseStatements const ChargesDeleteStatement = CHAR_DEL_PET_SPELL_CHARGES;
    static CharacterDatabaseStatements const ChargesInsertStatement = CHAR_INS_PET_SPELL_CHARGES;

    static void SetIdentifier(PreparedStatement* stmt, uint8 index, Unit* owner) { stmt->setUInt32(index, owner->GetCharmInfo()->GetPetNumber()); }

    static bool ReadCooldown(Field* fields, uint32* spellId, CooldownEntry* cooldownEntry)
    {
        *spellId = fields[0].GetUInt32();
        if (!sSpellMgr->GetSpellInfo(*spellId))
            return false;

        cooldownEntry->SpellId = *spellId;
        cooldownEntry->CooldownEnd = Clock::from_time_t(time_t(fields[1].GetUInt32()));
        cooldownEntry->ItemId = 0;
        cooldownEntry->CategoryId = fields[2].GetUInt32();
        cooldownEntry->CategoryEnd = Clock::from_time_t(time_t(fields[3].GetUInt32()));
        return true;
    }

    static bool ReadCharge(Field* fields, uint32* categoryId, ChargeEntry* chargeEntry)
    {
        *categoryId = fields[0].GetUInt32();
        if (!sSpellCategoryStore.LookupEntry(*categoryId))
            return false;

        chargeEntry->RechargeStart = Clock::from_time_t(time_t(fields[1].GetUInt32()));
        chargeEntry->RechargeEnd = Clock::from_time_t(time_t(fields[2].GetUInt32()));
        return true;
    }

    static void WriteCooldown(PreparedStatement* stmt, uint8& index, CooldownStorageType::value_type const& cooldown)
    {
        stmt->setUInt32(index++, cooldown.first);
        stmt->setUInt32(index++, uint32(Clock::to_time_t(cooldown.second.CooldownEnd)));
        stmt->setUInt32(index++, cooldown.second.CategoryId);
        stmt->setUInt32(index++, uint32(Clock::to_time_t(cooldown.second.CategoryEnd)));
    }

    static void WriteCharge(PreparedStatement* stmt, uint8& index, uint32 chargeCategory, ChargeEntry const& charge)
    {
        stmt->setUInt32(index++, chargeCategory);
        stmt->setUInt32(index++, uint32(Clock::to_time_t(charge.RechargeStart)));
        stmt->setUInt32(index++, uint32(Clock::to_time_t(charge.RechargeEnd)));
    }
};

template<class OwnerType>
void SpellHistory::LoadFromDB(PreparedQueryResult cooldownsResult, PreparedQueryResult chargesResult)
{
    typedef PersistenceHelper<OwnerType> StatementInfo;

    if (cooldownsResult)
    {
        do
        {
            uint32 spellId;
            CooldownEntry cooldown;
            if (StatementInfo::ReadCooldown(cooldownsResult->Fetch(), &spellId, &cooldown))
            {
                _spellCooldowns[spellId] = cooldown;
                if (cooldown.CategoryId)
                    _categoryCooldowns[cooldown.CategoryId] = &_spellCooldowns[spellId];
            }

        } while (cooldownsResult->NextRow());
    }

    if (chargesResult)
    {
        do
        {
            Field* fields = chargesResult->Fetch();
            uint32 categoryId = 0;
            ChargeEntry charges;
            if (StatementInfo::ReadCharge(fields, &categoryId, &charges))
                _categoryCharges[categoryId].push_back(charges);

        } while (chargesResult->NextRow());
    }
}

template<class OwnerType>
void SpellHistory::SaveToDB(SQLTransaction& trans)
{
    typedef PersistenceHelper<OwnerType> StatementInfo;

    uint8 index = 0;
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(StatementInfo::CooldownsDeleteStatement);
    StatementInfo::SetIdentifier(stmt, index++, _owner);
    trans->Append(stmt);

    for (auto const& p : _spellCooldowns)
    {
        if (!p.second.OnHold)
        {
            index = 0;
            stmt = CharacterDatabase.GetPreparedStatement(StatementInfo::CooldownsInsertStatement);
            StatementInfo::SetIdentifier(stmt, index++, _owner);
            StatementInfo::WriteCooldown(stmt, index, p);
            trans->Append(stmt);
        }
    }

    stmt = CharacterDatabase.GetPreparedStatement(StatementInfo::ChargesDeleteStatement);
    StatementInfo::SetIdentifier(stmt, 0, _owner);
    trans->Append(stmt);

    for (auto const& p : _categoryCharges)
    {
        for (ChargeEntry const& charge : p.second)
        {
            index = 0;
            stmt = CharacterDatabase.GetPreparedStatement(StatementInfo::ChargesInsertStatement);
            StatementInfo::SetIdentifier(stmt, index++, _owner);
            StatementInfo::WriteCharge(stmt, index, p.first, charge);
            trans->Append(stmt);
        }
    }
}

void SpellHistory::Update()
{
    Clock::time_point now = Clock::now();
    for (auto itr = _categoryCooldowns.begin(); itr != _categoryCooldowns.end();)
    {
        if (itr->second->CategoryEnd < now)
            itr = _categoryCooldowns.erase(itr);
        else
            ++itr;
    }

    for (auto itr = _spellCooldowns.begin(); itr != _spellCooldowns.end();)
    {
        if (itr->second.CooldownEnd < now)
            itr = EraseCooldown(itr);
        else
            ++itr;
    }

    for (auto& p : _categoryCharges)
    {
        std::deque<ChargeEntry>& chargeRefreshTimes = p.second;
        while (!chargeRefreshTimes.empty() && chargeRefreshTimes.front().RechargeEnd <= now)
            chargeRefreshTimes.pop_front();
    }
}

void SpellHistory::HandleCooldowns(SpellInfo const* spellInfo, Item const* item, Spell* spell /*= nullptr*/)
{
    HandleCooldowns(spellInfo, item ? item->GetEntry() : 0, spell);
}

void SpellHistory::HandleCooldowns(SpellInfo const* spellInfo, uint32 itemID, Spell* spell /*= nullptr*/)
{
    if (ConsumeCharge(spellInfo->ChargeCategoryId))
        return;

    if (Player* player = _owner->ToPlayer())
    {
        // potions start cooldown until exiting combat
        if (ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(itemID))
        {
            if (itemTemplate->IsPotion() || spellInfo->IsCooldownStartedOnEvent())
            {
                player->SetLastPotionId(itemID);
                return;
            }
        }
    }

    if (spellInfo->IsCooldownStartedOnEvent() || spellInfo->IsPassive() || (spell && spell->IsIgnoringCooldowns()))
        return;

    StartCooldown(spellInfo, itemID, spell);
}

bool SpellHistory::IsReady(SpellInfo const* spellInfo, uint32 itemId /*= 0*/, bool ignoreCategoryCooldown /*= false*/) const
{
    if (spellInfo->PreventionType & SPELL_PREVENTION_TYPE_SILENCE)
        if (IsSchoolLocked(spellInfo->GetSchoolMask()))
            return false;

    if (HasCooldown(spellInfo->Id, itemId, ignoreCategoryCooldown))
        return false;

    if (!HasCharge(spellInfo->ChargeCategoryId))
        return false;

    return true;
}

template<class PacketType>
void SpellHistory::WritePacket(PacketType* /*packet*/) const
{
    static_assert(!std::is_same<PacketType, PacketType>::value /*static_assert(false)*/, "This packet is not supported.");
}

template<>
void SpellHistory::WritePacket(WorldPackets::Spells::SendSpellHistory* sendSpellHistory) const
{
    sendSpellHistory->Entries.reserve(_spellCooldowns.size());

    Clock::time_point now = Clock::now();
    for (auto const& p : _spellCooldowns)
    {
        WorldPackets::Spells::SpellHistoryEntry historyEntry;
        historyEntry.SpellID = p.first;
        historyEntry.ItemID = p.second.ItemId;

        if (p.second.OnHold)
            historyEntry.OnHold = true;
        else
        {
            std::chrono::milliseconds cooldownDuration = std::chrono::duration_cast<std::chrono::milliseconds>(p.second.CooldownEnd - now);
            if (cooldownDuration.count() <= 0)
                continue;

            historyEntry.RecoveryTime = uint32(cooldownDuration.count());
            std::chrono::milliseconds categoryDuration = std::chrono::duration_cast<std::chrono::milliseconds>(p.second.CategoryEnd - now);
            if (categoryDuration.count() > 0)
            {
                historyEntry.Category = p.second.CategoryId;
                historyEntry.CategoryRecoveryTime = uint32(categoryDuration.count());
            }
        }

        sendSpellHistory->Entries.push_back(historyEntry);
    }
}

template<>
void SpellHistory::WritePacket(WorldPackets::Spells::SendSpellCharges* sendSpellCharges) const
{
    sendSpellCharges->Entries.reserve(_categoryCharges.size());

    Clock::time_point now = Clock::now();
    for (auto const& p : _categoryCharges)
    {
        if (!p.second.empty())
        {
            std::chrono::milliseconds cooldownDuration = std::chrono::duration_cast<std::chrono::milliseconds>(p.second.front().RechargeEnd - now);
            if (cooldownDuration.count() <= 0)
                continue;

            WorldPackets::Spells::SpellChargeEntry chargeEntry;
            chargeEntry.Category = p.first;
            chargeEntry.NextRecoveryTime = uint32(cooldownDuration.count());
            chargeEntry.ConsumedCharges = uint8(p.second.size());
            sendSpellCharges->Entries.push_back(chargeEntry);
        }
    }
}

template<>
void SpellHistory::WritePacket(WorldPackets::Pet::PetSpells* petSpells) const
{
    Clock::time_point now = Clock::now();

    petSpells->Cooldowns.reserve(_spellCooldowns.size());
    for (auto const& p : _spellCooldowns)
    {
        WorldPackets::Pet::PetSpellCooldown petSpellCooldown;
        petSpellCooldown.SpellID = p.first;
        petSpellCooldown.Category = p.second.CategoryId;

        if (!p.second.OnHold)
        {
            std::chrono::milliseconds cooldownDuration = std::chrono::duration_cast<std::chrono::milliseconds>(p.second.CooldownEnd - now);
            if (cooldownDuration.count() <= 0)
                continue;

            petSpellCooldown.Duration = uint32(cooldownDuration.count());
            std::chrono::milliseconds categoryDuration = std::chrono::duration_cast<std::chrono::milliseconds>(p.second.CategoryEnd - now);
            if (categoryDuration.count() > 0)
                petSpellCooldown.CategoryDuration = uint32(categoryDuration.count());
        }
        else
            petSpellCooldown.CategoryDuration = 0x80000000;

        petSpells->Cooldowns.push_back(petSpellCooldown);
    }

    petSpells->SpellHistory.reserve(_categoryCharges.size());
    for (auto const& p : _categoryCharges)
    {
        if (!p.second.empty())
        {
            std::chrono::milliseconds cooldownDuration = std::chrono::duration_cast<std::chrono::milliseconds>(p.second.front().RechargeEnd - now);
            if (cooldownDuration.count() <= 0)
                continue;

            WorldPackets::Pet::PetSpellHistory petChargeEntry;
            petChargeEntry.CategoryID = p.first;
            petChargeEntry.RecoveryTime = uint32(cooldownDuration.count());
            petChargeEntry.ConsumedCharges = int8(p.second.size());

            petSpells->SpellHistory.push_back(petChargeEntry);
        }
    }
}

void SpellHistory::StartCooldown(SpellInfo const* spellInfo, uint32 itemId, Spell* spell /*= nullptr*/, bool onHold /*= false*/)
{
    // init cooldown values
    uint32 categoryId = 0;
    int32 cooldown = -1;
    int32 categoryCooldown = -1;

    GetCooldownDurations(spellInfo, itemId, &cooldown, &categoryId, &categoryCooldown);

    Clock::time_point curTime = Clock::now();
    Clock::time_point catrecTime;
    Clock::time_point recTime;
    bool needsCooldownPacket = false;

    // overwrite time for selected category
    if (onHold)
    {
        // use +MONTH as infinite cooldown marker
        catrecTime = categoryCooldown > 0 ? (curTime + InfinityCooldownDelay) : curTime;
        recTime = cooldown > 0 ? (curTime + InfinityCooldownDelay) : catrecTime;
    }
    else
    {
        // shoot spells used equipped item cooldown values already assigned in SetBaseAttackTime(RANGED_ATTACK)
        // prevent 0 cooldowns set by another way
        if (cooldown <= 0 && categoryCooldown <= 0 && (categoryId == 76 || (spellInfo->IsAutoRepeatRangedSpell() && spellInfo->Id != 75)))
            cooldown = _owner->GetUInt32Value(UNIT_FIELD_RANGEDATTACKTIME);

        // Now we have cooldown data (if found any), time to apply mods
        if (Player* modOwner = _owner->GetSpellModOwner())
        {
            if (cooldown > 0)
                modOwner->ApplySpellMod(spellInfo->Id, SPELLMOD_COOLDOWN, cooldown, spell);

            if (categoryCooldown > 0 && !spellInfo->HasAttribute(SPELL_ATTR6_IGNORE_CATEGORY_COOLDOWN_MODS))
                modOwner->ApplySpellMod(spellInfo->Id, SPELLMOD_COOLDOWN, categoryCooldown, spell);
        }

        if (_owner->HasAuraTypeWithAffectMask(SPELL_AURA_MOD_SPELL_COOLDOWN_BY_HASTE, spellInfo))
        {
            cooldown = int32(cooldown * _owner->GetFloatValue(UNIT_MOD_CAST_HASTE));
            categoryCooldown = int32(categoryCooldown * _owner->GetFloatValue(UNIT_MOD_CAST_HASTE));
        }

        if (_owner->HasAuraTypeWithAffectMask(SPELL_AURA_MOD_COOLDOWN_BY_HASTE_REGEN, spellInfo))
        {
            cooldown = int32(cooldown * _owner->GetFloatValue(UNIT_FIELD_MOD_HASTE_REGEN));
            categoryCooldown = int32(categoryCooldown * _owner->GetFloatValue(UNIT_FIELD_MOD_HASTE_REGEN));
        }

        if (int32 cooldownMod = _owner->GetTotalAuraModifier(SPELL_AURA_MOD_COOLDOWN))
        {
            // Apply SPELL_AURA_MOD_COOLDOWN only to own spells
            Player* playerOwner = GetPlayerOwner();
            if (!playerOwner || playerOwner->HasSpell(spellInfo->Id))
            {
                needsCooldownPacket = true;
                cooldown += cooldownMod * IN_MILLISECONDS;   // SPELL_AURA_MOD_COOLDOWN does not affect category cooldows, verified with shaman shocks
            }
        }

        // Apply SPELL_AURA_MOD_SPELL_CATEGORY_COOLDOWN modifiers
        // Note: This aura applies its modifiers to all cooldowns of spells with set category, not to category cooldown only
        if (categoryId)
        {
            if (int32 categoryModifier = _owner->GetTotalAuraModifierByMiscValue(SPELL_AURA_MOD_SPELL_CATEGORY_COOLDOWN, categoryId))
            {
                if (cooldown > 0)
                    cooldown += categoryModifier;

                if (categoryCooldown > 0)
                    categoryCooldown += categoryModifier;
            }

            SpellCategoryEntry const* categoryEntry = sSpellCategoryStore.AssertEntry(categoryId);
            if (categoryEntry->Flags & SPELL_CATEGORY_FLAG_COOLDOWN_EXPIRES_AT_DAILY_RESET)
                categoryCooldown = int32(std::chrono::duration_cast<std::chrono::milliseconds>(Clock::from_time_t(sWorld->GetNextDailyQuestsResetTime()) - Clock::now()).count());
        }

        // replace negative cooldowns by 0
        if (cooldown < 0)
            cooldown = 0;

        if (categoryCooldown < 0)
            categoryCooldown = 0;

        // no cooldown after applying spell mods
        if (cooldown == 0 && categoryCooldown == 0)
            return;

        catrecTime = categoryCooldown ? curTime + std::chrono::duration_cast<Clock::duration>(std::chrono::milliseconds(categoryCooldown)) : curTime;
        recTime = cooldown ? curTime + std::chrono::duration_cast<Clock::duration>(std::chrono::milliseconds(cooldown)) : catrecTime;
    }

    // self spell cooldown
    if (recTime != curTime)
    {
        AddCooldown(spellInfo->Id, itemId, recTime, categoryId, catrecTime, onHold);

        if (needsCooldownPacket)
        {
            if (Player* playerOwner = GetPlayerOwner())
            {
                WorldPackets::Spells::SpellCooldown spellCooldown;
                spellCooldown.Caster = _owner->GetGUID();
                spellCooldown.Flags = SPELL_COOLDOWN_FLAG_NONE;
                spellCooldown.SpellCooldowns.emplace_back(spellInfo->Id, uint32(cooldown));
                playerOwner->SendDirectMessage(spellCooldown.Write());
            }
        }
    }
}

void SpellHistory::SendCooldownEvent(SpellInfo const* spellInfo, uint32 itemId /*= 0*/, Spell* spell /*= nullptr*/, bool startCooldown /*= true*/)
{
    // Send activate cooldown timer (possible 0) at client side
    if (Player* player = GetPlayerOwner())
    {
        uint32 category = spellInfo->GetCategory();
        GetCooldownDurations(spellInfo, itemId, nullptr, &category, nullptr);

        auto categoryItr = _categoryCooldowns.find(category);
        if (categoryItr != _categoryCooldowns.end() && categoryItr->second->SpellId != spellInfo->Id)
        {
            player->SendDirectMessage(WorldPackets::Spells::CooldownEvent(player != _owner, categoryItr->second->SpellId).Write());

            if (startCooldown)
                StartCooldown(sSpellMgr->AssertSpellInfo(categoryItr->second->SpellId), itemId, spell);
        }

        player->SendDirectMessage(WorldPackets::Spells::CooldownEvent(player != _owner, spellInfo->Id).Write());
    }

    // start cooldowns at server side, if any
    if (startCooldown)
        StartCooldown(spellInfo, itemId, spell);
}

void SpellHistory::AddCooldown(uint32 spellId, uint32 itemId, Clock::time_point cooldownEnd, uint32 categoryId, Clock::time_point categoryEnd, bool onHold /*= false*/)
{
    CooldownEntry& cooldownEntry = _spellCooldowns[spellId];
    cooldownEntry.SpellId = spellId;
    cooldownEntry.CooldownEnd = cooldownEnd;
    cooldownEntry.ItemId = itemId;
    cooldownEntry.CategoryId = categoryId;
    cooldownEntry.CategoryEnd = categoryEnd;
    cooldownEntry.OnHold = onHold;

    if (categoryId)
        _categoryCooldowns[categoryId] = &cooldownEntry;
}

void SpellHistory::ModifyCooldown(uint32 spellId, int32 cooldownModMs)
{
    Clock::duration offset = std::chrono::duration_cast<Clock::duration>(std::chrono::milliseconds(cooldownModMs));
    ModifyCooldown(spellId, offset);
}

void SpellHistory::ModifyCooldown(uint32 spellId, Clock::duration offset)
{
    auto itr = _spellCooldowns.find(spellId);
    if (!offset.count() || itr == _spellCooldowns.end())
        return;

    Clock::time_point now = Clock::now();

    if (itr->second.CooldownEnd + offset > now)
        itr->second.CooldownEnd += offset;
    else
        EraseCooldown(itr);

    if (Player* playerOwner = GetPlayerOwner())
    {
        WorldPackets::Spells::ModifyCooldown modifyCooldown;
        modifyCooldown.IsPet = _owner != playerOwner;
        modifyCooldown.SpellID = spellId;
        modifyCooldown.DeltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(offset).count();
        playerOwner->SendDirectMessage(modifyCooldown.Write());
    }
}

void SpellHistory::ResetCooldown(uint32 spellId, bool update /*= false*/)
{
    auto itr = _spellCooldowns.find(spellId);
    if (itr == _spellCooldowns.end())
        return;

    ResetCooldown(itr, update);
}

void SpellHistory::ResetCooldown(CooldownStorageType::iterator& itr, bool update /*= false*/)
{
    if (update)
    {
        if (Player* playerOwner = GetPlayerOwner())
        {
            WorldPackets::Spells::ClearCooldown clearCooldown;
            clearCooldown.IsPet = _owner != playerOwner;
            clearCooldown.SpellID = itr->first;
            clearCooldown.ClearOnHold = false;
            playerOwner->SendDirectMessage(clearCooldown.Write());
        }
    }

    itr = EraseCooldown(itr);
}

void SpellHistory::ResetAllCooldowns()
{
    if (GetPlayerOwner())
    {
        std::vector<int32> cooldowns;
        cooldowns.reserve(_spellCooldowns.size());
        for (auto const& p : _spellCooldowns)
            cooldowns.push_back(p.first);

        SendClearCooldowns(cooldowns);
    }

    _categoryCooldowns.clear();
    _spellCooldowns.clear();
}

bool SpellHistory::HasCooldown(SpellInfo const* spellInfo, uint32 itemId /*= 0*/, bool ignoreCategoryCooldown /*= false*/) const
{
    if (_spellCooldowns.count(spellInfo->Id) != 0)
        return true;

    if (ignoreCategoryCooldown)
        return false;

    uint32 category = 0;
    GetCooldownDurations(spellInfo, itemId, nullptr, &category, nullptr);
    if (!category)
        return false;

    return _categoryCooldowns.count(category) != 0;
}

bool SpellHistory::HasCooldown(uint32 spellId, uint32 itemId /*= 0*/, bool ignoreCategoryCooldown /*= false*/) const
{
    return HasCooldown(sSpellMgr->AssertSpellInfo(spellId), itemId, ignoreCategoryCooldown);
}

uint32 SpellHistory::GetRemainingCooldown(SpellInfo const* spellInfo) const
{
    Clock::time_point end;
    auto itr = _spellCooldowns.find(spellInfo->Id);
    if (itr != _spellCooldowns.end())
        end = itr->second.CooldownEnd;
    else
    {
        auto catItr = _categoryCooldowns.find(spellInfo->GetCategory());
        if (catItr == _categoryCooldowns.end())
            return 0;

        end = catItr->second->CategoryEnd;
    }

    Clock::time_point now = Clock::now();
    if (end < now)
        return 0;

    Clock::duration remaining = end - now;
    return uint32(std::chrono::duration_cast<std::chrono::milliseconds>(remaining).count());
}

void SpellHistory::LockSpellSchool(SpellSchoolMask schoolMask, uint32 lockoutTime)
{
    Clock::time_point now = Clock::now();
    Clock::time_point lockoutEnd = now + std::chrono::duration_cast<Clock::duration>(std::chrono::milliseconds(lockoutTime));
    for (uint32 i = 0; i < MAX_SPELL_SCHOOL; ++i)
        if (SpellSchoolMask(1 << i) & schoolMask)
            _schoolLockouts[i] = lockoutEnd;

    std::set<uint32> knownSpells;
    if (Player* plrOwner = _owner->ToPlayer())
    {
        for (auto const& p : plrOwner->GetSpellMap())
            if (p.second->state != PLAYERSPELL_REMOVED)
                knownSpells.insert(p.first);
    }
    else if (Pet* petOwner = _owner->ToPet())
    {
        for (auto const& p : petOwner->m_spells)
            if (p.second.state != PETSPELL_REMOVED)
                knownSpells.insert(p.first);
    }
    else
    {
        Creature* creatureOwner = _owner->ToCreature();
        for (uint8 i = 0; i < MAX_CREATURE_SPELLS; ++i)
            if (creatureOwner->m_spells[i])
                knownSpells.insert(creatureOwner->m_spells[i]);
    }

    WorldPackets::Spells::SpellCooldown spellCooldown;
    spellCooldown.Caster = _owner->GetGUID();
    spellCooldown.Flags = SPELL_COOLDOWN_FLAG_NONE;
    for (uint32 spellId : knownSpells)
    {
        SpellInfo const* spellInfo = sSpellMgr->AssertSpellInfo(spellId);
        if (spellInfo->IsCooldownStartedOnEvent())
            continue;

        if (!(spellInfo->PreventionType & SPELL_PREVENTION_TYPE_SILENCE))
            continue;

        if ((schoolMask & spellInfo->GetSchoolMask()) && GetRemainingCooldown(spellInfo) < lockoutTime)
        {
            spellCooldown.SpellCooldowns.emplace_back(spellId, lockoutTime);
            AddCooldown(spellId, 0, lockoutEnd, 0, now);
        }
    }

    if (Player* player = GetPlayerOwner())
        if (!spellCooldown.SpellCooldowns.empty())
            player->SendDirectMessage(spellCooldown.Write());
}

bool SpellHistory::IsSchoolLocked(SpellSchoolMask schoolMask) const
{
    Clock::time_point now = Clock::now();
    for (uint32 i = 0; i < MAX_SPELL_SCHOOL; ++i)
        if (SpellSchoolMask(1 << i) & schoolMask)
            if (_schoolLockouts[i] > now)
                return true;

    return false;
}

bool SpellHistory::ConsumeCharge(uint32 chargeCategoryId)
{
    if (!sSpellCategoryStore.LookupEntry(chargeCategoryId))
        return false;

    int32 chargeRecovery = GetChargeRecoveryTime(chargeCategoryId);
    if (chargeRecovery > 0 && GetMaxCharges(chargeCategoryId) > 0)
    {
        Clock::time_point recoveryStart;
        std::deque<ChargeEntry>& charges = _categoryCharges[chargeCategoryId];
        if (charges.empty())
            recoveryStart = Clock::now();
        else
            recoveryStart = charges.back().RechargeEnd;

        charges.emplace_back(recoveryStart, std::chrono::milliseconds(chargeRecovery));
        return true;
    }

    return false;
}

void SpellHistory::RestoreCharge(uint32 chargeCategoryId)
{
    auto itr = _categoryCharges.find(chargeCategoryId);
    if (itr != _categoryCharges.end() && !itr->second.empty())
    {
        itr->second.pop_back();

        if (Player* player = GetPlayerOwner())
        {
            WorldPackets::Spells::SetSpellCharges setSpellCharges;
            setSpellCharges.Category = chargeCategoryId;
            if (!itr->second.empty())
                setSpellCharges.NextRecoveryTime = uint32(std::chrono::duration_cast<std::chrono::milliseconds>(itr->second.front().RechargeEnd - Clock::now()).count());
            setSpellCharges.ConsumedCharges = uint8(itr->second.size());
            setSpellCharges.IsPet = player != _owner;

            player->SendDirectMessage(setSpellCharges.Write());
        }
    }
}

void SpellHistory::ResetCharges(uint32 chargeCategoryId)
{
    auto itr = _categoryCharges.find(chargeCategoryId);
    if (itr != _categoryCharges.end())
    {
        _categoryCharges.erase(itr);

        if (Player* player = GetPlayerOwner())
        {
            WorldPackets::Spells::ClearSpellCharges clearSpellCharges;
            clearSpellCharges.IsPet = _owner != player;
            clearSpellCharges.Category = chargeCategoryId;
            player->SendDirectMessage(clearSpellCharges.Write());
        }
    }
}

void SpellHistory::ResetAllCharges()
{
    _categoryCharges.clear();

    if (Player* player = GetPlayerOwner())
    {
        WorldPackets::Spells::ClearAllSpellCharges clearAllSpellCharges;
        clearAllSpellCharges.IsPet = _owner != player;
        player->SendDirectMessage(clearAllSpellCharges.Write());
    }
}

bool SpellHistory::HasCharge(uint32 chargeCategoryId) const
{
    if (!sSpellCategoryStore.LookupEntry(chargeCategoryId))
        return true;

    // Check if the spell is currently using charges (untalented warlock Dark Soul)
    int32 maxCharges = GetMaxCharges(chargeCategoryId);
    if (maxCharges <= 0)
        return true;

    auto itr = _categoryCharges.find(chargeCategoryId);
    return itr == _categoryCharges.end() || int32(itr->second.size()) < maxCharges;
}

int32 SpellHistory::GetMaxCharges(uint32 chargeCategoryId) const
{
    SpellCategoryEntry const* chargeCategoryEntry = sSpellCategoryStore.LookupEntry(chargeCategoryId);
    if (!chargeCategoryEntry)
        return 0;

    uint32 charges = chargeCategoryEntry->MaxCharges;
    charges += _owner->GetTotalAuraModifierByMiscValue(SPELL_AURA_MOD_MAX_CHARGES, chargeCategoryId);
    return charges;
}

int32 SpellHistory::GetChargeRecoveryTime(uint32 chargeCategoryId) const
{
    SpellCategoryEntry const* chargeCategoryEntry = sSpellCategoryStore.LookupEntry(chargeCategoryId);
    if (!chargeCategoryEntry)
        return 0;

    int32 recoveryTime = chargeCategoryEntry->ChargeRecoveryTime;
    recoveryTime += _owner->GetTotalAuraModifierByMiscValue(SPELL_AURA_CHARGE_RECOVERY_MOD, chargeCategoryId);

    float recoveryTimeF = float(recoveryTime);
    recoveryTimeF *= _owner->GetTotalAuraMultiplierByMiscValue(SPELL_AURA_CHARGE_RECOVERY_MULTIPLIER, chargeCategoryId);

    if (_owner->HasAuraType(SPELL_AURA_CHARGE_RECOVERY_AFFECTED_BY_HASTE))
        recoveryTimeF *= _owner->GetFloatValue(UNIT_MOD_CAST_HASTE);

    if (_owner->HasAuraType(SPELL_AURA_CHARGE_RECOVERY_AFFECTED_BY_HASTE_REGEN))
        recoveryTimeF *= _owner->GetFloatValue(UNIT_FIELD_MOD_HASTE_REGEN);

    return int32(std::floor(recoveryTimeF));
}

bool SpellHistory::HasGlobalCooldown(SpellInfo const* spellInfo) const
{
    auto itr = _globalCooldowns.find(spellInfo->StartRecoveryCategory);
    return itr != _globalCooldowns.end() && itr->second > Clock::now();
}

void SpellHistory::AddGlobalCooldown(SpellInfo const* spellInfo, uint32 duration)
{
    _globalCooldowns[spellInfo->StartRecoveryCategory] = Clock::now() + std::chrono::duration_cast<Clock::duration>(std::chrono::milliseconds(duration));
}

void SpellHistory::CancelGlobalCooldown(SpellInfo const* spellInfo)
{
    _globalCooldowns[spellInfo->StartRecoveryCategory] = Clock::time_point(Clock::duration(0));
}

Player* SpellHistory::GetPlayerOwner() const
{
    return _owner->GetCharmerOrOwnerPlayerOrPlayerItself();
}

void SpellHistory::SendClearCooldowns(std::vector<int32> const& cooldowns) const
{
    if (Player const* playerOwner = GetPlayerOwner())
    {
        WorldPackets::Spells::ClearCooldowns clearCooldowns;
        clearCooldowns.IsPet = _owner != playerOwner;
        clearCooldowns.SpellID = cooldowns;
        playerOwner->SendDirectMessage(clearCooldowns.Write());
    }
}

void SpellHistory::GetCooldownDurations(SpellInfo const* spellInfo, uint32 itemId, int32* cooldown, uint32* categoryId, int32* categoryCooldown)
{
    ASSERT(cooldown || categoryId || categoryCooldown);
    int32 tmpCooldown = -1;
    uint32 tmpCategoryId = 0;
    int32 tmpCategoryCooldown = -1;

    // cooldown information stored in ItemEffect.db2, overriding normal cooldown and category
    if (itemId)
    {
        if (ItemTemplate const* proto = sObjectMgr->GetItemTemplate(itemId))
        {
            for (ItemEffectEntry const* itemEffect : proto->Effects)
            {
                if (uint32(itemEffect->SpellID) == spellInfo->Id)
                {
                    tmpCooldown = itemEffect->CoolDownMSec;
                    tmpCategoryId = itemEffect->SpellCategoryID;
                    tmpCategoryCooldown = itemEffect->CategoryCoolDownMSec;
                    break;
                }
            }
        }
    }

    // if no cooldown found above then base at DBC data
    if (tmpCooldown < 0 && tmpCategoryCooldown < 0)
    {
        tmpCooldown = spellInfo->RecoveryTime;
        tmpCategoryId = spellInfo->GetCategory();
        tmpCategoryCooldown = spellInfo->CategoryRecoveryTime;
    }

    if (cooldown)
        *cooldown = tmpCooldown;
    if (categoryId)
        *categoryId = tmpCategoryId;
    if (categoryCooldown)
        *categoryCooldown = tmpCategoryCooldown;
}

void SpellHistory::SaveCooldownStateBeforeDuel()
{
    _spellCooldownsBeforeDuel = _spellCooldowns;
}

void SpellHistory::RestoreCooldownStateAfterDuel()
{
    if (Player* player = _owner->ToPlayer())
    {
        // add all profession CDs created while in duel (if any)
        for (auto const& c : _spellCooldowns)
        {
            SpellInfo const* spellInfo = sSpellMgr->AssertSpellInfo(c.first);

            if (spellInfo->RecoveryTime > 10 * MINUTE * IN_MILLISECONDS ||
                spellInfo->CategoryRecoveryTime > 10 * MINUTE * IN_MILLISECONDS)
                _spellCooldownsBeforeDuel[c.first] = _spellCooldowns[c.first];
        }

        // check for spell with onHold active before and during the duel
        for (auto itr = _spellCooldownsBeforeDuel.begin(); itr != _spellCooldownsBeforeDuel.end(); ++itr)
        {
            if (!itr->second.OnHold &&
                _spellCooldowns.find(itr->first) != _spellCooldowns.end() &&
                !_spellCooldowns[itr->first].OnHold)
                _spellCooldowns[itr->first] = _spellCooldownsBeforeDuel[itr->first];
        }

        // update the client: restore old cooldowns
        WorldPackets::Spells::SpellCooldown spellCooldown;
        spellCooldown.Caster = _owner->GetGUID();
        spellCooldown.Flags = SPELL_COOLDOWN_FLAG_INCLUDE_EVENT_COOLDOWNS;

        for (auto const& c : _spellCooldowns)
        {
            Clock::time_point now = Clock::now();
            uint32 cooldownDuration = uint32(c.second.CooldownEnd > now ? std::chrono::duration_cast<std::chrono::milliseconds>(c.second.CooldownEnd - now).count() : 0);

            // cooldownDuration must be between 0 and 10 minutes in order to avoid any visual bugs
            if (cooldownDuration <= 0 || cooldownDuration > 10 * MINUTE * IN_MILLISECONDS || c.second.OnHold)
                continue;

            spellCooldown.SpellCooldowns.emplace_back(c.first, cooldownDuration);
        }

        player->SendDirectMessage(spellCooldown.Write());
    }
}

template void SpellHistory::LoadFromDB<Player>(PreparedQueryResult cooldownsResult, PreparedQueryResult chargesResult);
template void SpellHistory::LoadFromDB<Pet>(PreparedQueryResult cooldownsResult, PreparedQueryResult chargesResult);
template void SpellHistory::SaveToDB<Player>(SQLTransaction& trans);
template void SpellHistory::SaveToDB<Pet>(SQLTransaction& trans);
