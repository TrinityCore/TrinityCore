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

#include "SpellHistory.h"
#include "CharmInfo.h"
#include "DB2Stores.h"
#include "DatabaseEnv.h"
#include "Duration.h"
#include "Item.h"
#include "Map.h"
#include "ObjectMgr.h"
#include "Pet.h"
#include "PetPackets.h"
#include "Player.h"
#include "Spell.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include "SpellPackets.h"
#include "World.h"

SpellHistory::Duration const SpellHistory::InfinityCooldownDelay = Seconds(MONTH);

template<>
struct SpellHistory::PersistenceHelper<Player>
{
    static CharacterDatabaseStatements const CooldownsDeleteStatement = CHAR_DEL_CHAR_SPELL_COOLDOWNS;
    static CharacterDatabaseStatements const CooldownsInsertStatement = CHAR_INS_CHAR_SPELL_COOLDOWN;
    static CharacterDatabaseStatements const ChargesDeleteStatement = CHAR_DEL_CHAR_SPELL_CHARGES;
    static CharacterDatabaseStatements const ChargesInsertStatement = CHAR_INS_CHAR_SPELL_CHARGES;

    static void SetIdentifier(PreparedStatementBase* stmt, uint8 index, Unit* owner) { stmt->setUInt64(index, owner->GetGUID().GetCounter()); }

    static bool ReadCooldown(Field* fields, uint32* spellId, CooldownEntry* cooldownEntry)
    {
        *spellId = fields[0].GetUInt32();
        if (!sSpellMgr->GetSpellInfo(*spellId, DIFFICULTY_NONE))
            return false;

        cooldownEntry->SpellId = *spellId;
        cooldownEntry->CooldownEnd = time_point_cast<Duration>(Clock::from_time_t(fields[2].GetInt64()));
        cooldownEntry->ItemId = fields[1].GetUInt32();
        cooldownEntry->CategoryId = fields[3].GetUInt32();
        cooldownEntry->CategoryEnd = time_point_cast<Duration>(Clock::from_time_t(fields[4].GetInt64()));
        return true;
    }

    static bool ReadCharge(Field* fields, uint32* categoryId, ChargeEntry* chargeEntry)
    {
        *categoryId = fields[0].GetUInt32();
        if (!sSpellCategoryStore.LookupEntry(*categoryId))
            return false;

        chargeEntry->RechargeStart = time_point_cast<Duration>(Clock::from_time_t(fields[1].GetInt64()));
        chargeEntry->RechargeEnd = time_point_cast<Duration>(Clock::from_time_t(fields[2].GetInt64()));
        return true;
    }

    static void WriteCooldown(PreparedStatementBase* stmt, uint8& index, CooldownStorageType::value_type const& cooldown)
    {
        stmt->setUInt32(index++, cooldown.first);
        stmt->setUInt32(index++, cooldown.second.ItemId);
        stmt->setInt64(index++, Clock::to_time_t(cooldown.second.CooldownEnd));
        stmt->setUInt32(index++, cooldown.second.CategoryId);
        stmt->setInt64(index++, Clock::to_time_t(cooldown.second.CategoryEnd));
    }

    static void WriteCharge(PreparedStatementBase* stmt, uint8& index, uint32 chargeCategory, ChargeEntry const& charge)
    {
        stmt->setUInt32(index++, chargeCategory);
        stmt->setInt64(index++, Clock::to_time_t(charge.RechargeStart));
        stmt->setInt64(index++, Clock::to_time_t(charge.RechargeEnd));
    }
};

template<>
struct SpellHistory::PersistenceHelper<Pet>
{
    static CharacterDatabaseStatements const CooldownsDeleteStatement = CHAR_DEL_PET_SPELL_COOLDOWNS;
    static CharacterDatabaseStatements const CooldownsInsertStatement = CHAR_INS_PET_SPELL_COOLDOWN;
    static CharacterDatabaseStatements const ChargesDeleteStatement = CHAR_DEL_PET_SPELL_CHARGES;
    static CharacterDatabaseStatements const ChargesInsertStatement = CHAR_INS_PET_SPELL_CHARGES;

    static void SetIdentifier(PreparedStatementBase* stmt, uint8 index, Unit* owner) { stmt->setUInt32(index, owner->GetCharmInfo()->GetPetNumber()); }

    static bool ReadCooldown(Field* fields, uint32* spellId, CooldownEntry* cooldownEntry)
    {
        *spellId = fields[0].GetUInt32();
        if (!sSpellMgr->GetSpellInfo(*spellId, DIFFICULTY_NONE))
            return false;

        cooldownEntry->SpellId = *spellId;
        cooldownEntry->CooldownEnd = time_point_cast<Duration>(Clock::from_time_t(fields[1].GetInt64()));
        cooldownEntry->ItemId = 0;
        cooldownEntry->CategoryId = fields[2].GetUInt32();
        cooldownEntry->CategoryEnd = time_point_cast<Duration>(Clock::from_time_t(fields[3].GetInt64()));
        return true;
    }

    static bool ReadCharge(Field* fields, uint32* categoryId, ChargeEntry* chargeEntry)
    {
        *categoryId = fields[0].GetUInt32();
        if (!sSpellCategoryStore.LookupEntry(*categoryId))
            return false;

        chargeEntry->RechargeStart = time_point_cast<Duration>(Clock::from_time_t(fields[1].GetInt64()));
        chargeEntry->RechargeEnd = time_point_cast<Duration>(Clock::from_time_t(fields[2].GetInt64()));
        return true;
    }

    static void WriteCooldown(PreparedStatementBase* stmt, uint8& index, CooldownStorageType::value_type const& cooldown)
    {
        stmt->setUInt32(index++, cooldown.first);
        stmt->setInt64(index++, Clock::to_time_t(cooldown.second.CooldownEnd));
        stmt->setUInt32(index++, cooldown.second.CategoryId);
        stmt->setInt64(index++, Clock::to_time_t(cooldown.second.CategoryEnd));
    }

    static void WriteCharge(PreparedStatementBase* stmt, uint8& index, uint32 chargeCategory, ChargeEntry const& charge)
    {
        stmt->setUInt32(index++, chargeCategory);
        stmt->setInt64(index++, Clock::to_time_t(charge.RechargeStart));
        stmt->setInt64(index++, Clock::to_time_t(charge.RechargeEnd));
    }
};

SpellHistory::SpellHistory(Unit* owner) : _owner(owner), _schoolLockouts()
{
}

SpellHistory::~SpellHistory() = default;

template<class OwnerType>
void SpellHistory::LoadFromDB(PreparedQueryResult cooldownsResult, PreparedQueryResult chargesResult)
{
    using StatementInfo = PersistenceHelper<OwnerType>;

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
void SpellHistory::SaveToDB(CharacterDatabaseTransaction trans)
{
    using StatementInfo = PersistenceHelper<OwnerType>;

    uint8 index = 0;
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(StatementInfo::CooldownsDeleteStatement);
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
    TimePoint now = time_point_cast<Duration>(GameTime::GetTime<Clock>());
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

void SpellHistory::HandleCooldowns(SpellInfo const* spellInfo, uint32 itemId, Spell* spell /*= nullptr*/)
{
    if (spell && spell->IsIgnoringCooldowns())
        return;

    if (ConsumeCharge(spellInfo->ChargeCategoryId))
        return;

    if (Player* player = _owner->ToPlayer())
    {
        // potions start cooldown until exiting combat
        if (ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(itemId))
        {
            if (itemTemplate->IsPotion() || spellInfo->IsCooldownStartedOnEvent())
            {
                player->SetLastPotionId(itemId);
                return;
            }
        }
    }

    if (spellInfo->IsCooldownStartedOnEvent() || spellInfo->IsPassive())
        return;

    StartCooldown(spellInfo, itemId, spell);
}

bool SpellHistory::IsReady(SpellInfo const* spellInfo, uint32 itemId /*= 0*/) const
{
    if (spellInfo->PreventionType & SPELL_PREVENTION_TYPE_SILENCE)
        if (IsSchoolLocked(spellInfo->GetSchoolMask()))
            return false;

    if (HasCooldown(spellInfo, itemId))
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

    TimePoint now = time_point_cast<Duration>(GameTime::GetTime<Clock>());
    for (auto const& p : _spellCooldowns)
    {
        WorldPackets::Spells::SpellHistoryEntry historyEntry;
        historyEntry.SpellID = p.first;
        historyEntry.ItemID = p.second.ItemId;

        if (p.second.OnHold)
            historyEntry.OnHold = true;
        else
        {
            Milliseconds cooldownDuration = duration_cast<Milliseconds>(p.second.CooldownEnd - now);
            if (cooldownDuration.count() <= 0)
                continue;

            Milliseconds categoryDuration = duration_cast<Milliseconds>(p.second.CategoryEnd - now);
            if (categoryDuration.count() > 0)
            {
                historyEntry.Category = p.second.CategoryId;
                historyEntry.CategoryRecoveryTime = uint32(categoryDuration.count());
            }

            if (cooldownDuration.count() > categoryDuration.count())
                historyEntry.RecoveryTime = uint32(cooldownDuration.count());
        }

        sendSpellHistory->Entries.push_back(historyEntry);
    }
}

template<>
void SpellHistory::WritePacket(WorldPackets::Spells::SendSpellCharges* sendSpellCharges) const
{
    sendSpellCharges->Entries.reserve(_categoryCharges.size());

    TimePoint now = time_point_cast<Duration>(GameTime::GetTime<Clock>());
    for (auto const& p : _categoryCharges)
    {
        if (!p.second.empty())
        {
            Milliseconds cooldownDuration = duration_cast<Milliseconds>(p.second.front().RechargeEnd - now);
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
    TimePoint now = time_point_cast<Duration>(GameTime::GetTime<Clock>());

    petSpells->Cooldowns.reserve(_spellCooldowns.size());
    for (auto const& p : _spellCooldowns)
    {
        WorldPackets::Pet::PetSpellCooldown petSpellCooldown;
        petSpellCooldown.SpellID = p.first;
        petSpellCooldown.Category = p.second.CategoryId;

        if (!p.second.OnHold)
        {
            Milliseconds cooldownDuration = duration_cast<Milliseconds>(p.second.CooldownEnd - now);
            if (cooldownDuration.count() <= 0)
                continue;

            petSpellCooldown.Duration = uint32(cooldownDuration.count());
            Milliseconds categoryDuration = duration_cast<Milliseconds>(p.second.CategoryEnd - now);
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
            Milliseconds cooldownDuration = duration_cast<Milliseconds>(p.second.front().RechargeEnd - now);
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

void SpellHistory::StartCooldown(SpellInfo const* spellInfo, uint32 itemId, Spell* spell /*= nullptr*/, bool onHold /*= false*/, Optional<Duration> forcedCooldown /*= {}*/)
{
    // init cooldown values
    uint32 categoryId = 0;
    Duration cooldown = Duration::zero();
    Duration categoryCooldown = Duration::zero();

    TimePoint curTime = time_point_cast<Duration>(GameTime::GetTime<Clock>());
    TimePoint catrecTime;
    TimePoint recTime;
    bool needsCooldownPacket = false;

    if (!forcedCooldown)
        GetCooldownDurations(spellInfo, itemId, &cooldown, &categoryId, &categoryCooldown);
    else
        cooldown = *forcedCooldown;

    // overwrite time for selected category
    if (onHold)
    {
        // use +MONTH as infinite cooldown marker
        catrecTime = categoryCooldown > Duration::zero() ? (curTime + InfinityCooldownDelay) : curTime;
        recTime = cooldown > Duration::zero() ? (curTime + InfinityCooldownDelay) : catrecTime;
    }
    else
    {
        if (!forcedCooldown)
        {
            // Now we have cooldown data (if found any), time to apply mods
            if (Player* modOwner = _owner->GetSpellModOwner())
            {
                auto applySpellMod = [&](Milliseconds& value)
                {
                    int32 intValue = value.count();
                    modOwner->ApplySpellMod(spellInfo, SpellModOp::Cooldown, intValue, spell);
                    value = Milliseconds(intValue);
                };

                if (cooldown >= Duration::zero())
                    applySpellMod(cooldown);

                if (categoryCooldown >= Clock::duration::zero() && !spellInfo->HasAttribute(SPELL_ATTR6_NO_CATEGORY_COOLDOWN_MODS))
                    applySpellMod(categoryCooldown);
            }

            if (_owner->HasAuraTypeWithAffectMask(SPELL_AURA_MOD_SPELL_COOLDOWN_BY_HASTE, spellInfo))
            {
                cooldown = Duration(int64(cooldown.count() * _owner->m_unitData->ModSpellHaste));
                categoryCooldown = Duration(int64(categoryCooldown.count() * _owner->m_unitData->ModSpellHaste));
            }

            if (_owner->HasAuraTypeWithAffectMask(SPELL_AURA_MOD_COOLDOWN_BY_HASTE_REGEN, spellInfo))
            {
                cooldown = Duration(int64(cooldown.count() * _owner->m_unitData->ModHasteRegen));
                categoryCooldown = Duration(int64(categoryCooldown.count() * _owner->m_unitData->ModHasteRegen));
            }

            if (int32 cooldownMod = _owner->GetTotalAuraModifier(SPELL_AURA_MOD_COOLDOWN))
            {
                // Apply SPELL_AURA_MOD_COOLDOWN only to own spells
                Player* playerOwner = GetPlayerOwner();
                if (!playerOwner || playerOwner->HasSpell(spellInfo->Id))
                {
                    needsCooldownPacket = true;
                    cooldown += Milliseconds(cooldownMod);   // SPELL_AURA_MOD_COOLDOWN does not affect category cooldows, verified with shaman shocks
                }
            }

            // Apply SPELL_AURA_MOD_SPELL_CATEGORY_COOLDOWN modifiers
            // Note: This aura applies its modifiers to all cooldowns of spells with set category, not to category cooldown only
            if (categoryId)
            {
                if (int32 categoryModifier = _owner->GetTotalAuraModifierByMiscValue(SPELL_AURA_MOD_SPELL_CATEGORY_COOLDOWN, categoryId))
                {
                    if (cooldown > Duration::zero())
                        cooldown += Milliseconds(categoryModifier);

                    if (categoryCooldown > Duration::zero())
                        categoryCooldown += Milliseconds(categoryModifier);
                }

                SpellCategoryEntry const* categoryEntry = sSpellCategoryStore.AssertEntry(categoryId);
                if (categoryEntry->Flags & SPELL_CATEGORY_FLAG_COOLDOWN_EXPIRES_AT_DAILY_RESET)
                    categoryCooldown = duration_cast<Milliseconds>(Clock::from_time_t(sWorld->GetNextDailyQuestsResetTime()) - GameTime::GetTime<Clock>());
            }
        }
        else
            needsCooldownPacket = true;

        // replace negative cooldowns by 0
        if (cooldown < Duration::zero())
            cooldown = Duration::zero();

        if (categoryCooldown < Duration::zero())
            categoryCooldown = Duration::zero();

        // no cooldown after applying spell mods
        if (cooldown == Duration::zero() && categoryCooldown == Duration::zero())
            return;

        catrecTime = categoryCooldown != Duration::zero() ? curTime + categoryCooldown : curTime;
        recTime = cooldown != Duration::zero() ? curTime + cooldown : catrecTime;
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
                spellCooldown.SpellCooldowns.emplace_back(spellInfo->Id, uint32(cooldown.count()));
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
                StartCooldown(sSpellMgr->AssertSpellInfo(categoryItr->second->SpellId, _owner->GetMap()->GetDifficultyID()), itemId, spell);
        }

        player->SendDirectMessage(WorldPackets::Spells::CooldownEvent(player != _owner, spellInfo->Id).Write());
    }

    // start cooldowns at server side, if any
    if (startCooldown)
        StartCooldown(spellInfo, itemId, spell);
}

void SpellHistory::AddCooldown(uint32 spellId, uint32 itemId, TimePoint cooldownEnd, uint32 categoryId, TimePoint categoryEnd, bool onHold /*= false*/)
{
    CooldownEntry& cooldownEntry = _spellCooldowns[spellId];
    // scripts can start multiple cooldowns for a given spell, only store the longest one
    if (cooldownEnd > cooldownEntry.CooldownEnd || categoryEnd > cooldownEntry.CategoryEnd || onHold)
    {
        cooldownEntry.SpellId = spellId;
        cooldownEntry.CooldownEnd = cooldownEnd;
        cooldownEntry.ItemId = itemId;
        cooldownEntry.CategoryId = categoryId;
        cooldownEntry.CategoryEnd = categoryEnd;
        cooldownEntry.OnHold = onHold;

        if (categoryId)
            _categoryCooldowns[categoryId] = &cooldownEntry;
    }
}

void SpellHistory::ModifySpellCooldown(uint32 spellId, Duration cooldownMod, bool withoutCategoryCooldown)
{
    auto itr = _spellCooldowns.find(spellId);
    if (!cooldownMod.count() || itr == _spellCooldowns.end())
        return;

    ModifySpellCooldown(itr, cooldownMod, withoutCategoryCooldown);
}

void SpellHistory::ModifySpellCooldown(CooldownStorageType::iterator& itr, Duration cooldownMod, bool withoutCategoryCooldown)
{
    TimePoint now = time_point_cast<Duration>(GameTime::GetTime<Clock>());

    itr->second.CooldownEnd += cooldownMod;

    if (itr->second.CategoryId)
    {
        if (!withoutCategoryCooldown)
            itr->second.CategoryEnd += cooldownMod;

        // Because category cooldown existence is tied to regular cooldown, we cannot allow a situation where regular cooldown is shorter than category
        if (itr->second.CooldownEnd < itr->second.CategoryEnd)
            itr->second.CooldownEnd = itr->second.CategoryEnd;
    }

    if (Player* playerOwner = GetPlayerOwner())
    {
        WorldPackets::Spells::ModifyCooldown modifyCooldown;
        modifyCooldown.IsPet = _owner != playerOwner;
        modifyCooldown.SpellID = itr->second.SpellId;
        modifyCooldown.DeltaTime = duration_cast<Milliseconds>(cooldownMod).count();
        modifyCooldown.WithoutCategoryCooldown = withoutCategoryCooldown;
        playerOwner->SendDirectMessage(modifyCooldown.Write());
    }

    if (itr->second.CooldownEnd <= now)
        itr = EraseCooldown(itr);
}

void SpellHistory::ModifyCooldown(uint32 spellId, Duration cooldownMod, bool withoutCategoryCooldown)
{
    if (SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellId, _owner->GetMap()->GetDifficultyID()))
        ModifyCooldown(spellInfo, cooldownMod, withoutCategoryCooldown);
}

void SpellHistory::ModifyCooldown(SpellInfo const* spellInfo, Duration cooldownMod, bool withoutCategoryCooldown)
{
    if (!cooldownMod.count())
        return;

    if (GetChargeRecoveryTime(spellInfo->ChargeCategoryId) > 0 && GetMaxCharges(spellInfo->ChargeCategoryId) > 0)
        ModifyChargeRecoveryTime(spellInfo->ChargeCategoryId, cooldownMod);
    else
        ModifySpellCooldown(spellInfo->Id, cooldownMod, withoutCategoryCooldown);
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

bool SpellHistory::HasCooldown(SpellInfo const* spellInfo, uint32 itemId /*= 0*/) const
{
    if (_owner->HasAuraTypeWithAffectMask(SPELL_AURA_IGNORE_SPELL_COOLDOWN, spellInfo))
        return false;

    if (_spellCooldowns.count(spellInfo->Id) != 0)
        return true;

    if (spellInfo->CooldownAuraSpellId && _owner->HasAura(spellInfo->CooldownAuraSpellId))
        return true;

    uint32 category = 0;
    GetCooldownDurations(spellInfo, itemId, nullptr, &category, nullptr);
    if (!category)
        return false;

    return _categoryCooldowns.count(category) != 0;
}

bool SpellHistory::HasCooldown(uint32 spellId, uint32 itemId /*= 0*/) const
{
    return HasCooldown(sSpellMgr->AssertSpellInfo(spellId, _owner->GetMap()->GetDifficultyID()), itemId);
}

SpellHistory::Duration SpellHistory::GetRemainingCooldown(SpellInfo const* spellInfo) const
{
    TimePoint end;
    auto itr = _spellCooldowns.find(spellInfo->Id);
    if (itr != _spellCooldowns.end())
        end = itr->second.CooldownEnd;
    else
    {
        auto catItr = _categoryCooldowns.find(spellInfo->GetCategory());
        if (catItr == _categoryCooldowns.end())
            return Duration::zero();

        end = catItr->second->CategoryEnd;
    }

    TimePoint now = time_point_cast<Duration>(GameTime::GetTime<Clock>());
    if (end < now)
        return Duration::zero();

    Clock::duration remaining = end - now;
    return duration_cast<Milliseconds>(remaining);
}

SpellHistory::Duration SpellHistory::GetRemainingCategoryCooldown(uint32 categoryId) const
{
    TimePoint end;
    auto catItr = _categoryCooldowns.find(categoryId);
    if (catItr == _categoryCooldowns.end())
        return Duration::zero();

    end = catItr->second->CategoryEnd;

    TimePoint now = time_point_cast<Duration>(GameTime::GetTime<Clock>());
    if (end < now)
        return Duration::zero();

    Clock::duration remaining = end - now;
    return duration_cast<Milliseconds>(remaining);
}

SpellHistory::Duration SpellHistory::GetRemainingCategoryCooldown(SpellInfo const* spellInfo) const
{
    return GetRemainingCategoryCooldown(spellInfo->GetCategory());
}

void SpellHistory::LockSpellSchool(SpellSchoolMask schoolMask, Duration lockoutTime)
{
    TimePoint now = time_point_cast<Duration>(GameTime::GetTime<Clock>());
    TimePoint lockoutEnd = now + lockoutTime;
    for (uint32 i = 0; i < MAX_SPELL_SCHOOL; ++i)
        if (SpellSchoolMask(1 << i) & schoolMask)
            _schoolLockouts[i] = lockoutEnd;

    std::set<uint32> knownSpells;
    if (Player* plrOwner = _owner->ToPlayer())
    {
        for (auto const& p : plrOwner->GetSpellMap())
            if (p.second.state != PLAYERSPELL_REMOVED)
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
        for (uint32 spell : creatureOwner->m_spells)
            if (spell)
                knownSpells.insert(spell);
    }

    WorldPackets::Spells::SpellCooldown spellCooldown;
    spellCooldown.Caster = _owner->GetGUID();
    spellCooldown.Flags = SPELL_COOLDOWN_FLAG_LOSS_OF_CONTROL_UI;
    for (uint32 spellId : knownSpells)
    {
        SpellInfo const* spellInfo = sSpellMgr->AssertSpellInfo(spellId, _owner->GetMap()->GetDifficultyID());
        if (spellInfo->IsCooldownStartedOnEvent())
            continue;

        if (!(spellInfo->PreventionType & SPELL_PREVENTION_TYPE_SILENCE))
            continue;

        if (!(schoolMask & spellInfo->GetSchoolMask()))
            continue;

        if (GetRemainingCooldown(spellInfo) < lockoutTime)
            AddCooldown(spellId, 0, lockoutEnd, 0, now);

        // always send cooldown, even if it will be shorter than already existing cooldown for LossOfControl UI
        spellCooldown.SpellCooldowns.emplace_back(spellId, lockoutTime.count());
    }

    if (Player* player = GetPlayerOwner())
        if (!spellCooldown.SpellCooldowns.empty())
            player->SendDirectMessage(spellCooldown.Write());
}

bool SpellHistory::IsSchoolLocked(SpellSchoolMask schoolMask) const
{
    TimePoint now = time_point_cast<Duration>(GameTime::GetTime<Clock>());
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
        TimePoint recoveryStart;
        std::deque<ChargeEntry>& charges = _categoryCharges[chargeCategoryId];
        if (charges.empty())
            recoveryStart = time_point_cast<Duration>(GameTime::GetTime<Clock>());
        else
            recoveryStart = charges.back().RechargeEnd;

        charges.emplace_back(recoveryStart, Milliseconds(chargeRecovery));
        return true;
    }

    return false;
}

void SpellHistory::ModifyChargeRecoveryTime(uint32 chargeCategoryId, Duration cooldownMod)
{
    SpellCategoryEntry const* chargeCategoryEntry = sSpellCategoryStore.LookupEntry(chargeCategoryId);
    if (!chargeCategoryEntry)
        return;

    auto itr = _categoryCharges.find(chargeCategoryId);
    if (itr == _categoryCharges.end() || itr->second.empty())
        return;

    TimePoint now = time_point_cast<Duration>(GameTime::GetTime<Clock>());

    for (ChargeEntry& entry : itr->second)
    {
        entry.RechargeStart += cooldownMod;
        entry.RechargeEnd += cooldownMod;
    }

    while (!itr->second.empty() && itr->second.front().RechargeEnd < now)
        itr->second.pop_front();

    SendSetSpellCharges(chargeCategoryId, itr->second);
}

void SpellHistory::RestoreCharge(uint32 chargeCategoryId)
{
    auto itr = _categoryCharges.find(chargeCategoryId);
    if (itr != _categoryCharges.end() && !itr->second.empty())
    {
        itr->second.pop_back();

        SendSetSpellCharges(chargeCategoryId, itr->second);
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
        recoveryTimeF *= _owner->m_unitData->ModSpellHaste;

    if (_owner->HasAuraTypeWithMiscvalue(SPELL_AURA_CHARGE_RECOVERY_AFFECTED_BY_HASTE_REGEN, chargeCategoryId))
        recoveryTimeF *= _owner->m_unitData->ModHasteRegen;

    return int32(std::floor(recoveryTimeF));
}

bool SpellHistory::HasGlobalCooldown(SpellInfo const* spellInfo) const
{
    auto itr = _globalCooldowns.find(spellInfo->StartRecoveryCategory);
    return itr != _globalCooldowns.end() && itr->second > Clock::now();
}

void SpellHistory::AddGlobalCooldown(SpellInfo const* spellInfo, Duration duration)
{
    _globalCooldowns[spellInfo->StartRecoveryCategory] = time_point_cast<Duration>(Clock::now() + duration);
}

void SpellHistory::CancelGlobalCooldown(SpellInfo const* spellInfo)
{
    _globalCooldowns[spellInfo->StartRecoveryCategory] = TimePoint(Duration(0));
}

SpellHistory::Duration SpellHistory::GetRemainingGlobalCooldown(SpellInfo const* spellInfo) const
{
    TimePoint end;
    auto cdItr = _globalCooldowns.find(spellInfo->StartRecoveryCategory);
    if (cdItr == _globalCooldowns.end())
        return Duration::zero();

    end = cdItr->second;
    TimePoint now = time_point_cast<Duration>(GameTime::GetTime<Clock>());
    if (end < now)
        return Duration::zero();

    Clock::duration remaining = end - now;
    return duration_cast<Milliseconds>(remaining);
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

void SpellHistory::SendSetSpellCharges(uint32 chargeCategoryId, ChargeEntryCollection const& chargeCollection)
{
    if (Player* player = GetPlayerOwner())
    {
        WorldPackets::Spells::SetSpellCharges setSpellCharges;
        setSpellCharges.Category = chargeCategoryId;
        if (!chargeCollection.empty())
            setSpellCharges.NextRecoveryTime = uint32(duration_cast<Milliseconds>(chargeCollection.front().RechargeEnd - GameTime::GetTime<Clock>()).count());
        setSpellCharges.ConsumedCharges = uint8(chargeCollection.size());
        setSpellCharges.IsPet = player != _owner;
        player->SendDirectMessage(setSpellCharges.Write());
    }
}

void SpellHistory::GetCooldownDurations(SpellInfo const* spellInfo, uint32 itemId, Duration* cooldown, uint32* categoryId, Duration* categoryCooldown)
{
    ASSERT(cooldown || categoryId || categoryCooldown);
    Duration tmpCooldown = Duration::min();
    uint32 tmpCategoryId = 0;
    Duration tmpCategoryCooldown = Duration::min();

    // cooldown information stored in ItemEffect.db2, overriding normal cooldown and category
    if (itemId)
    {
        if (ItemTemplate const* proto = sObjectMgr->GetItemTemplate(itemId))
        {
            for (ItemEffectEntry const* itemEffect : proto->Effects)
            {
                if (uint32(itemEffect->SpellID) == spellInfo->Id)
                {
                    tmpCooldown = Milliseconds(itemEffect->CoolDownMSec);
                    tmpCategoryId = itemEffect->SpellCategoryID;
                    tmpCategoryCooldown = Milliseconds(itemEffect->CategoryCoolDownMSec);
                    break;
                }
            }
        }
    }

    // if no cooldown found above then base at DBC data
    if (tmpCooldown < Duration::zero() && tmpCategoryCooldown < Duration::zero())
    {
        tmpCooldown = Milliseconds(spellInfo->RecoveryTime);
        tmpCategoryId = spellInfo->GetCategory();
        tmpCategoryCooldown = Milliseconds(spellInfo->CategoryRecoveryTime);
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
            SpellInfo const* spellInfo = sSpellMgr->AssertSpellInfo(c.first, DIFFICULTY_NONE);

            if (spellInfo->RecoveryTime > 10 * MINUTE * IN_MILLISECONDS ||
                spellInfo->CategoryRecoveryTime > 10 * MINUTE * IN_MILLISECONDS)
                _spellCooldownsBeforeDuel[c.first] = _spellCooldowns[c.first];
        }

        // check for spell with onHold active before and during the duel
        for (CooldownStorageType::value_type const& pair : _spellCooldownsBeforeDuel)
        {
            if (!pair.second.OnHold &&
                _spellCooldowns.find(pair.first) != _spellCooldowns.end() &&
                !_spellCooldowns[pair.first].OnHold)
                _spellCooldowns[pair.first] = _spellCooldownsBeforeDuel[pair.first];
        }

        // update the client: restore old cooldowns
        WorldPackets::Spells::SpellCooldown spellCooldown;
        spellCooldown.Caster = _owner->GetGUID();
        spellCooldown.Flags = SPELL_COOLDOWN_FLAG_INCLUDE_EVENT_COOLDOWNS;

        for (auto const& c : _spellCooldowns)
        {
            TimePoint now = time_point_cast<Duration>(GameTime::GetTime<Clock>());
            uint32 cooldownDuration = uint32(c.second.CooldownEnd > now ? duration_cast<Milliseconds>(c.second.CooldownEnd - now).count() : 0);

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
template void SpellHistory::SaveToDB<Player>(CharacterDatabaseTransaction trans);
template void SpellHistory::SaveToDB<Pet>(CharacterDatabaseTransaction trans);
