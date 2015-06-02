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

#include "WorldPacket.h"
#include "SpellHistory.h"
#include "Pet.h"
#include "Player.h"
#include "SpellInfo.h"
#include "Spell.h"
#include "World.h"
#include "Opcodes.h"

SpellHistory::Clock::duration const SpellHistory::InfinityCooldownDelay = std::chrono::duration_cast<SpellHistory::Clock::duration>(std::chrono::seconds(MONTH));
SpellHistory::Clock::duration const SpellHistory::InfinityCooldownDelayCheck = std::chrono::duration_cast<SpellHistory::Clock::duration>(std::chrono::seconds(MONTH / 2));

template<>
struct SpellHistory::PersistenceHelper<Player>
{
    static CharacterDatabaseStatements const CooldownsDeleteStatement = CHAR_DEL_CHAR_SPELL_COOLDOWNS;
    static CharacterDatabaseStatements const CooldownsInsertStatement = CHAR_INS_CHAR_SPELL_COOLDOWN;

    static void SetIdentifier(PreparedStatement* stmt, uint8 index, Unit* owner) { stmt->setUInt32(index, owner->GetGUID().GetCounter()); }

    static bool ReadCooldown(Field* fields, uint32* spellId, CooldownEntry* cooldownEntry)
    {
        *spellId = fields[0].GetUInt32();
        if (!sSpellMgr->GetSpellInfo(*spellId))
            return false;

        cooldownEntry->CooldownEnd = Clock::from_time_t(time_t(fields[2].GetUInt32()));
        cooldownEntry->ItemId = fields[1].GetUInt32();
        return true;
    }

    static void WriteCooldown(PreparedStatement* stmt, uint8& index, CooldownStorageType::value_type const& cooldown)
    {
        stmt->setUInt32(index++, cooldown.first);
        stmt->setUInt32(index++, cooldown.second.ItemId);
        stmt->setUInt32(index++, uint32(Clock::to_time_t(cooldown.second.CooldownEnd)));
    }
};

template<>
struct SpellHistory::PersistenceHelper<Pet>
{
    static CharacterDatabaseStatements const CooldownsDeleteStatement = CHAR_DEL_PET_SPELL_COOLDOWNS;
    static CharacterDatabaseStatements const CooldownsInsertStatement = CHAR_INS_PET_SPELL_COOLDOWN;

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

    static void WriteCooldown(PreparedStatement* stmt, uint8& index, CooldownStorageType::value_type const& cooldown)
    {
        stmt->setUInt32(index++, cooldown.first);
        stmt->setUInt32(index++, uint32(Clock::to_time_t(cooldown.second.CooldownEnd)));
    }
};

template<class OwnerType>
void SpellHistory::LoadFromDB(PreparedQueryResult cooldownsResult)
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
}

void SpellHistory::HandleCooldowns(SpellInfo const* spellInfo, Item const* item, Spell* spell /*= nullptr*/)
{
    if (Player* player = _owner->ToPlayer())
    {
        // potions start cooldown until exiting combat
        if (item && (item->IsPotion() || spellInfo->IsCooldownStartedOnEvent()))
        {
            player->SetLastPotionId(item->GetEntry());
            return;
        }
    }

    if (spellInfo->IsCooldownStartedOnEvent() || spellInfo->IsPassive() || (spell && spell->IsIgnoringCooldowns()))
        return;

    StartCooldown(spellInfo, item ? item->GetEntry() : 0, spell);
}

bool SpellHistory::IsReady(SpellInfo const* spellInfo) const
{
    if (spellInfo->PreventionType == SPELL_PREVENTION_TYPE_SILENCE)
        if (IsSchoolLocked(spellInfo->GetSchoolMask()))
            return false;

    if (HasCooldown(spellInfo->Id))
        return false;

    return true;
}

template<>
void SpellHistory::WritePacket<Pet>(WorldPacket& packet) const
{
    Clock::time_point now = Clock::now();
    
    uint8 cooldownsCount = _spellCooldowns.size();
    packet << uint8(cooldownsCount);

    for (auto const& spellCooldown : _spellCooldowns)
    {
        SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellCooldown.first);
        if (!spellInfo)
        {
            packet << uint32(0);
            packet << uint16(0);
            packet << uint32(0);
            packet << uint32(0);
            continue;
        }

        packet << uint32(spellCooldown.first);       // spell ID
        packet << uint16(spellInfo->GetCategory());  // spell category
        if (!spellCooldown.second.OnHold)
        {
            uint32 cooldownDuration = spellCooldown.second.CooldownEnd > now ? std::chrono::duration_cast<std::chrono::milliseconds>(spellCooldown.second.CooldownEnd - now).count() : 0;
            if (cooldownDuration <= 0)
            {
                packet << uint32(0);
                packet << uint32(0);
                continue;
            }

            if (spellInfo->GetCategory())
            {
                packet << uint32(0);
                packet << uint32(cooldownDuration);
            }
            else
            {
                packet << uint32(cooldownDuration);
                packet << uint32(0);
            }
        }
    }
}

template<>
void SpellHistory::WritePacket<Player>(WorldPacket& packet) const
{
    Clock::time_point now = Clock::now();
    Clock::time_point infTime = now + InfinityCooldownDelayCheck;

    uint16 cooldownsCount = _spellCooldowns.size();
    size_t dataPos = packet.wpos();
    packet << uint16(cooldownsCount);

    for (auto const& spellCooldown : _spellCooldowns)
    {
        SpellInfo const* sEntry = sSpellMgr->GetSpellInfo(spellCooldown.first);
        if (!sEntry)
        {
            --cooldownsCount;
            continue;
        }

        packet << uint32(spellCooldown.first);

        packet << uint16(spellCooldown.second.ItemId);        // cast item id
        packet << uint16(sEntry->GetCategory());              // spell category

        // send infinity cooldown in special format
        if (spellCooldown.second.CooldownEnd >= infTime)
        {
            packet << uint32(1);                              // cooldown
            packet << uint32(0x80000000);                     // category cooldown
            continue;
        }

        uint32 cooldownDuration = spellCooldown.second.CooldownEnd > now ? std::chrono::duration_cast<std::chrono::milliseconds>(spellCooldown.second.CooldownEnd - now).count() : 0;

        if (sEntry->GetCategory())                             // may be wrong, but anyway better than nothing...
        {
            packet << uint32(0);                              // cooldown
            packet << uint32(cooldownDuration);               // category cooldown
        }
        else
        {
            packet << uint32(cooldownDuration);               // cooldown
            packet << uint32(0);                              // category cooldown
        }
    }

    packet.put<uint16>(dataPos, cooldownsCount);
}

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
            for (uint8 idx = 0; idx < MAX_ITEM_PROTO_SPELLS; ++idx)
            {
                if (uint32(proto->Spells[idx].SpellId) == spellInfo->Id)
                {
                    categoryId = proto->Spells[idx].SpellCategory;
                    cooldown = proto->Spells[idx].SpellCooldown;
                    categoryCooldown = proto->Spells[idx].SpellCategoryCooldown;
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
                WorldPacket spellCooldown;
                BuildCooldownPacket(spellCooldown, SPELL_COOLDOWN_FLAG_NONE, spellInfo->Id, cooldown);
                playerOwner->SendDirectMessage(&spellCooldown);
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
        WorldPacket data(SMSG_COOLDOWN_EVENT, 4 + 8);
        data << uint32(spellInfo->Id);
        data << uint64(_owner->GetGUID());
        player->SendDirectMessage(&data);

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

                    SpellInfo const* spellInfo2 = sSpellMgr->EnsureSpellInfo(categorySpell);
                    if (!spellInfo2->IsCooldownStartedOnEvent())
                        continue;

                    data.Initialize(SMSG_COOLDOWN_EVENT, 4 + 8);
                    data << uint32(categorySpell);
                    data << uint64(_owner->GetGUID());
                    player->SendDirectMessage(&data);
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
        WorldPacket modifyCooldown(SMSG_MODIFY_COOLDOWN, 4 + 8 + 4);
        modifyCooldown << uint32(spellId);
        modifyCooldown << uint64(_owner->GetGUID());
        modifyCooldown << int32(cooldownModMs);
        playerOwner->SendDirectMessage(&modifyCooldown);
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
            WorldPacket data(SMSG_CLEAR_COOLDOWN, 4 + 8);
            data << uint32(itr->first);
            data << uint64(_owner->GetGUID());
            playerOwner->SendDirectMessage(&data);
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

    PacketCooldowns cooldowns;
    WorldPacket spellCooldowns;
    for (uint32 spellId : knownSpells)
    {
        SpellInfo const* spellInfo = sSpellMgr->EnsureSpellInfo(spellId);
        if (spellInfo->IsCooldownStartedOnEvent())
            continue;

        if (spellInfo->PreventionType != SPELL_PREVENTION_TYPE_SILENCE)
            continue;

        if ((schoolMask & spellInfo->GetSchoolMask()) && GetRemainingCooldown(spellId) < lockoutTime)
        {
            cooldowns[spellId] = lockoutTime;
            AddCooldown(spellId, 0, lockoutEnd);
        }
    }

    if (Player* player = GetPlayerOwner())
    {
        if (!cooldowns.empty())
        {
            BuildCooldownPacket(spellCooldowns, SPELL_COOLDOWN_FLAG_NONE, cooldowns);
            player->SendDirectMessage(&spellCooldowns);
        }
    }
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
    if (Player* playerOwner = GetPlayerOwner())
    {
        for (int32 spell : cooldowns)
        {
            WorldPacket data(SMSG_CLEAR_COOLDOWN, 4 + 8);
            data << uint32(spell);
            data << uint64(_owner->GetGUID());
            playerOwner->SendDirectMessage(&data);
        }
    }
}

void SpellHistory::BuildCooldownPacket(WorldPacket& data, uint8 flags, uint32 spellId, uint32 cooldown) const
{
    data.Initialize(SMSG_SPELL_COOLDOWN, 8 + 1 + 4 + 4);
    data << uint64(_owner->GetGUID());
    data << uint8(flags);
    data << uint32(spellId);
    data << uint32(cooldown);
}

void SpellHistory::BuildCooldownPacket(WorldPacket& data, uint8 flags, PacketCooldowns const& cooldowns) const
{
    data.Initialize(SMSG_SPELL_COOLDOWN, 8 + 1 + (4 + 4) * cooldowns.size());
    data << uint64(_owner->GetGUID());
    data << uint8(flags);
    for (auto const& cooldown : cooldowns)
    {
        data << cooldown.first;
        data << cooldown.second;
    }
}

template void SpellHistory::LoadFromDB<Player>(PreparedQueryResult cooldownsResult);
template void SpellHistory::LoadFromDB<Pet>(PreparedQueryResult cooldownsResult);
template void SpellHistory::SaveToDB<Player>(SQLTransaction& trans);
template void SpellHistory::SaveToDB<Pet>(SQLTransaction& trans);
