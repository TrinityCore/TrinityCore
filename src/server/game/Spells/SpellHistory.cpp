/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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
#include "Pet.h"
#include "Player.h"
#include "SpellInfo.h"
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

        cooldownEntry->CooldownEnd = Clock::from_time_t(time_t(fields[2].GetUInt32()));
        cooldownEntry->ItemId = fields[1].GetUInt32();
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

        cooldownEntry->CooldownEnd = Clock::from_time_t(time_t(fields[1].GetUInt32()));
        cooldownEntry->ItemId = 0;
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
                _spellCooldowns[spellId] = cooldown;

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
    SQLTransaction t;
    Clock::time_point now = Clock::now();
    for (auto itr = _spellCooldowns.begin(); itr != _spellCooldowns.end();)
    {
        if (itr->second.CooldownEnd < now)
            itr = _spellCooldowns.erase(itr);
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

void SpellHistory::HandleCooldowns(SpellInfo const* spellInfo, uint32 ItemID, Spell* spell /*= nullptr*/)
{
    if (ConsumeCharge(spellInfo->ChargeCategoryEntry))
        return;

    if (Player* player = _owner->ToPlayer())
    {
        // potions start cooldown until exiting combat
        if (ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(ItemID))
        {
            if (itemTemplate->IsPotion() || spellInfo->IsCooldownStartedOnEvent())
            {
                player->SetLastPotionId(ItemID);
                return;
            }
        }
    }

    if (spellInfo->IsCooldownStartedOnEvent() || spellInfo->IsPassive() || (spell && spell->IsIgnoringCooldowns()))
        return;

    StartCooldown(spellInfo, ItemID, spell);
}

bool SpellHistory::IsReady(SpellInfo const* spellInfo) const
{
    if (spellInfo->PreventionType == SPELL_PREVENTION_TYPE_SILENCE)
        if (IsSchoolLocked(spellInfo->GetSchoolMask()))
            return false;

    if (HasCooldown(spellInfo->Id))
        return false;

    if (!HasCharge(spellInfo->ChargeCategoryEntry))
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
        SpellInfo const* spellInfo = sSpellMgr->AssertSpellInfo(p.first);
        WorldPackets::Spells::SpellHistoryEntry historyEntry;
        historyEntry.SpellID = p.first;
        historyEntry.ItemID = p.second.ItemId;
        historyEntry.Category = spellInfo->GetCategory();

        if (p.second.OnHold)
            historyEntry.OnHold = true;
        else
        {
            std::chrono::milliseconds cooldownDuration = std::chrono::duration_cast<std::chrono::milliseconds>(p.second.CooldownEnd - now);
            if (cooldownDuration.count() <= 0)
                continue;

            if (spellInfo->GetCategory())
                historyEntry.CategoryRecoveryTime = uint32(cooldownDuration.count());
            else
                historyEntry.RecoveryTime = uint32(cooldownDuration.count());
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
            chargeEntry.ConsumedCharges = p.second.size();
            sendSpellCharges->Entries.push_back(chargeEntry);
        }
    }
}

/*
template<>
void SpellHistory::WritePacket(WorldPackets::Pet::PetSpells* petSpells)
{
    Clock::time_point now = Clock::now();

    petSpells->Cooldowns.reserve(_spellCooldowns.size());
    for (auto const& p : _spellCooldowns)
    {
        SpellInfo const* spellInfo = sSpellMgr->AssertSpellInfo(p.first);
        WorldPackets::Pet::PetSpellCooldown petSpellCooldown;
        petSpellCooldown.SpellID = p.first;
        petSpellCooldown.Category = spellInfo->GetCategory();

        if (!p.second.OnHold)
        {
            std::chrono::milliseconds cooldownDuration = std::chrono::duration_cast<std::chrono::milliseconds>(p.second.CooldownEnd - now);
            if (cooldownDuration.count() <= 0)
                continue;

            if (spellInfo->GetCategory())
                petSpellCooldown.CategoryDuration = uint32(cooldownDuration.count());
            else
                petSpellCooldown.Duration = uint32(cooldownDuration.count());
        }

        petSpells->Cooldowns.push_back(historyEntry);
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
            petChargeEntry.ConsumedCharges = p.second.size();

            petSpells->SpellHistory.push_back(petChargeEntry);
        }
    }
}
*/

void SpellHistory::StartCooldown(SpellInfo const* spellInfo, uint32 itemId, Spell* spell /*= nullptr*/, bool onHold /*= false*/)
{
    // init cooldown values
    uint32 categoryId = 0;
    int32 cooldown = -1;
    int32 categoryCooldown = -1;

    // some special item spells without correct cooldown in SpellInfo
    // cooldown information stored in item prototype
    if (itemId)
    {
        if (ItemTemplate const* proto = sObjectMgr->GetItemTemplate(itemId))
        {
            for (ItemEffectEntry const* itemEffect : proto->Effects)
            {
                if (itemEffect->SpellID == spellInfo->Id)
                {
                    categoryId = itemEffect->Category;
                    cooldown = itemEffect->Cooldown;
                    categoryCooldown = itemEffect->CategoryCooldown;
                    break;
                }
            }
        }
    }

    // if no cooldown found above then base at DBC data
    if (cooldown < 0 && categoryCooldown < 0)
    {
        categoryId = spellInfo->GetCategory();
        cooldown = spellInfo->RecoveryTime;
        categoryCooldown = spellInfo->CategoryRecoveryTime;
    }

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
        // shoot spells used equipped item cooldown values already assigned in GetAttackTime(RANGED_ATTACK)
        // prevent 0 cooldowns set by another way
        if (cooldown <= 0 && categoryCooldown <= 0 && (categoryId == 76 || (spellInfo->IsAutoRepeatRangedSpell() && spellInfo->Id != 75)))
            cooldown = _owner->GetAttackTime(RANGED_ATTACK);

        // Now we have cooldown data (if found any), time to apply mods
        if (Player* modOwner = _owner->GetSpellModOwner())
        {
            if (cooldown > 0)
                modOwner->ApplySpellMod(spellInfo->Id, SPELLMOD_COOLDOWN, cooldown, spell);

            if (categoryCooldown > 0 && !spellInfo->HasAttribute(SPELL_ATTR6_IGNORE_CATEGORY_COOLDOWN_MODS))
                modOwner->ApplySpellMod(spellInfo->Id, SPELLMOD_COOLDOWN, categoryCooldown, spell);
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
        AddCooldown(spellInfo->Id, itemId, recTime, onHold);

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

    // category spells
    if (categoryId && catrecTime != curTime)
    {
        SpellCategoryStore::const_iterator i_scstore = sSpellsByCategoryStore.find(categoryId);
        if (i_scstore != sSpellsByCategoryStore.end())
        {
            for (SpellCategorySet::const_iterator i_scset = i_scstore->second.begin(); i_scset != i_scstore->second.end(); ++i_scset)
            {
                if (*i_scset == spellInfo->Id)                    // skip main spell, already handled above
                    continue;

                AddCooldown(*i_scset, itemId, catrecTime, onHold);
            }
        }
    }
}

void SpellHistory::SendCooldownEvent(SpellInfo const* spellInfo, uint32 itemId /*= 0*/, Spell* spell /*= nullptr*/, bool startCooldown /*= true*/)
{
    // start cooldowns at server side, if any
    if (startCooldown)
        StartCooldown(spellInfo, itemId, spell);

    if (Player* player = GetPlayerOwner())
    {
        // Send activate cooldown timer (possible 0) at client side
        player->SendDirectMessage(WorldPackets::Spells::CooldownEvent(player != _owner, spellInfo->Id).Write());

        uint32 category = spellInfo->GetCategory();
        if (category && spellInfo->CategoryRecoveryTime)
        {
            SpellCategoryStore::const_iterator ct = sSpellsByCategoryStore.find(category);
            if (ct != sSpellsByCategoryStore.end())
            {
                for (auto const& cooldownPair : _spellCooldowns)
                {
                    uint32 categorySpell = cooldownPair.first;
                    if (!ct->second.count(categorySpell))
                        continue;

                    if (categorySpell == spellInfo->Id) // skip main spell, already handled above
                        continue;

                    SpellInfo const* spellInfo2 = sSpellMgr->AssertSpellInfo(categorySpell);
                    if (!spellInfo2->IsCooldownStartedOnEvent())
                        continue;

                    player->SendDirectMessage(WorldPackets::Spells::CooldownEvent(player != _owner, categorySpell).Write());
                }
            }
        }
    }
}

void SpellHistory::AddCooldown(uint32 spellId, uint32 itemId, Clock::time_point cooldownEnd, bool onHold /*= false*/)
{
    CooldownEntry& cooldownEntry = _spellCooldowns[spellId];
    cooldownEntry.CooldownEnd = cooldownEnd;
    cooldownEntry.ItemId = itemId;
    cooldownEntry.OnHold = onHold;
}

void SpellHistory::ModifyCooldown(uint32 spellId, int32 cooldownModMs)
{
    auto itr = _spellCooldowns.find(spellId);
    if (!cooldownModMs || itr == _spellCooldowns.end())
        return;

    Clock::time_point now = Clock::now();
    Clock::duration offset = std::chrono::duration_cast<Clock::duration>(std::chrono::milliseconds(cooldownModMs));
    if (itr->second.CooldownEnd + offset > now)
        itr->second.CooldownEnd += offset;
    else
        _spellCooldowns.erase(itr);

    if (Player* playerOwner = GetPlayerOwner())
    {
        WorldPackets::Spells::ModifyCooldown modifyCooldown;
        modifyCooldown.IsPet = _owner != playerOwner;
        modifyCooldown.SpellID = spellId;
        modifyCooldown.DeltaTime = cooldownModMs;
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

    itr = _spellCooldowns.erase(itr);
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

    _spellCooldowns.clear();
}

bool SpellHistory::HasCooldown(uint32 spellId) const
{
    return _spellCooldowns.count(spellId) != 0;
}

uint32 SpellHistory::GetRemainingCooldown(uint32 spellId) const
{
    auto itr = _spellCooldowns.find(spellId);
    if (itr == _spellCooldowns.end())
        return 0;

    Clock::time_point now = Clock::now();
    if (itr->second.CooldownEnd < now)
        return 0;

    Clock::duration remaining = itr->second.CooldownEnd - now;
    return uint32(std::chrono::duration_cast<std::chrono::milliseconds>(remaining).count());
}

void SpellHistory::LockSpellSchool(SpellSchoolMask schoolMask, uint32 lockoutTime)
{
    Clock::time_point lockoutEnd = Clock::now() + std::chrono::duration_cast<Clock::duration>(std::chrono::milliseconds(lockoutTime));
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
        for (uint8 i = 0; i < CREATURE_MAX_SPELLS; ++i)
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

        if (spellInfo->PreventionType != SPELL_PREVENTION_TYPE_SILENCE)
            continue;

        if ((schoolMask & spellInfo->GetSchoolMask()) && GetRemainingCooldown(spellId) < lockoutTime)
        {
            spellCooldown.SpellCooldowns.emplace_back(spellId, lockoutTime);
            AddCooldown(spellId, 0, lockoutEnd);
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

bool SpellHistory::ConsumeCharge(SpellCategoryEntry const* chargeCategoryEntry)
{
    if (!chargeCategoryEntry)
        return false;

    int32 chargeRecovery = GetChargeRecoveryTime(chargeCategoryEntry);
    if (chargeRecovery > 0 && GetMaxCharges(chargeCategoryEntry) > 0)
    {
        Clock::time_point recoveryStart;
        std::deque<ChargeEntry>& charges = _categoryCharges[chargeCategoryEntry->ID];
        if (charges.empty())
            recoveryStart = Clock::now();
        else
            recoveryStart = charges.back().RechargeEnd;

        charges.emplace_back(recoveryStart, std::chrono::milliseconds(chargeRecovery));
        return true;
    }

    return false;
}

void SpellHistory::RestoreCharge(SpellCategoryEntry const* chargeCategoryEntry)
{
    if (!chargeCategoryEntry)
        return;

    auto itr = _categoryCharges.find(chargeCategoryEntry->ID);
    if (itr != _categoryCharges.end() && !itr->second.empty())
    {
        itr->second.pop_back();

        if (Player* player = GetPlayerOwner())
        {
            WorldPackets::Spells::SetSpellCharges setSpellCharges;
            setSpellCharges.Category = chargeCategoryEntry->ID;
            if (!itr->second.empty())
                setSpellCharges.NextRecoveryTime = uint32(std::chrono::duration_cast<std::chrono::milliseconds>(itr->second.front().RechargeEnd - Clock::now()).count());
            setSpellCharges.ConsumedCharges = itr->second.size();
            setSpellCharges.IsPet = player == _owner;

            player->SendDirectMessage(setSpellCharges.Write());
        }
    }
}

void SpellHistory::ResetCharges(SpellCategoryEntry const* chargeCategoryEntry)
{
    if (!chargeCategoryEntry)
        return;

    auto itr = _categoryCharges.find(chargeCategoryEntry->ID);
    if (itr != _categoryCharges.end())
    {
        _categoryCharges.erase(itr);

        if (Player* player = GetPlayerOwner())
        {
            WorldPackets::Spells::ClearSpellCharges clearSpellCharges;
            clearSpellCharges.IsPet = _owner != player;
            clearSpellCharges.Category = chargeCategoryEntry->ID;
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

bool SpellHistory::HasCharge(SpellCategoryEntry const* chargeCategoryEntry) const
{
    if (!chargeCategoryEntry)
        return true;

    // Check if the spell is currently using charges (untalented warlock Dark Soul)
    int32 maxCharges = GetMaxCharges(chargeCategoryEntry);
    if (maxCharges <= 0)
        return true;

    auto itr = _categoryCharges.find(chargeCategoryEntry->ID);
    return itr == _categoryCharges.end() || int32(itr->second.size()) < maxCharges;
}

int32 SpellHistory::GetMaxCharges(SpellCategoryEntry const* chargeCategoryEntry) const
{
    if (!chargeCategoryEntry)
        return 0;

    uint32 charges = chargeCategoryEntry->MaxCharges;
    charges += _owner->GetTotalAuraModifierByMiscValue(SPELL_AURA_MOD_MAX_CHARGES, chargeCategoryEntry->ID);
    return charges;
}

int32 SpellHistory::GetChargeRecoveryTime(SpellCategoryEntry const* chargeCategoryEntry) const
{
    if (!chargeCategoryEntry)
        return 0;

    int32 recoveryTime = chargeCategoryEntry->ChargeRecoveryTime;
    recoveryTime += _owner->GetTotalAuraModifierByMiscValue(SPELL_AURA_CHARGE_RECOVERY_MOD, chargeCategoryEntry->ID);

    float recoveryTimeF = recoveryTime;
    recoveryTimeF *= _owner->GetTotalAuraMultiplierByMiscValue(SPELL_AURA_CHARGE_RECOVERY_MULTIPLIER, chargeCategoryEntry->ID);

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

template void SpellHistory::LoadFromDB<Player>(PreparedQueryResult cooldownsResult, PreparedQueryResult chargesResult);
template void SpellHistory::LoadFromDB<Pet>(PreparedQueryResult cooldownsResult, PreparedQueryResult chargesResult);
template void SpellHistory::SaveToDB<Player>(SQLTransaction& trans);
template void SpellHistory::SaveToDB<Pet>(SQLTransaction& trans);
