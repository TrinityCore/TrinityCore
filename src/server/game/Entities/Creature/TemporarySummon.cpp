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

#include "TemporarySummon.h"
#include "CellImpl.h"
#include "CharmInfo.h"
#include "CreatureAI.h"
#include "DB2Stores.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "GridNotifiers.h"
#include "Log.h"
#include "Map.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Pet.h"
#include "Player.h"
#include "SmoothPhasing.h"
#include "SpellMgr.h"
#include <boost/container/small_vector.hpp>
#include <sstream>

TempSummon::TempSummon(SummonPropertiesEntry const* properties, WorldObject* owner, bool isWorldObject) :
Creature(isWorldObject), m_Properties(properties), m_type(TEMPSUMMON_MANUAL_DESPAWN),
m_timer(0ms), m_lifetime(0ms), m_canFollowOwner(true)
{
    if (owner)
        m_summonerGUID = owner->GetGUID();

    m_unitTypeMask |= UNIT_MASK_SUMMON;
}

TempSummon::~TempSummon() = default;

WorldObject* TempSummon::GetSummoner() const
{
    return !m_summonerGUID.IsEmpty() ? ObjectAccessor::GetWorldObject(*this, m_summonerGUID) : nullptr;
}

Unit* TempSummon::GetSummonerUnit() const
{
    if (WorldObject* summoner = GetSummoner())
        return summoner->ToUnit();
    return nullptr;
}

Creature* TempSummon::GetSummonerCreatureBase() const
{
    return !m_summonerGUID.IsEmpty() ? ObjectAccessor::GetCreature(*this, m_summonerGUID) : nullptr;
}

GameObject* TempSummon::GetSummonerGameObject() const
{
    if (WorldObject* summoner = GetSummoner())
        return summoner->ToGameObject();
    return nullptr;
}

void TempSummon::Update(uint32 diff)
{
    Creature::Update(diff);

    if (m_deathState == DEAD)
    {
        UnSummon();
        return;
    }

    Milliseconds msDiff = Milliseconds(diff);
    switch (m_type)
    {
        case TEMPSUMMON_MANUAL_DESPAWN:
        case TEMPSUMMON_DEAD_DESPAWN:
            break;
        case TEMPSUMMON_TIMED_DESPAWN:
        {
            if (m_timer <= msDiff)
            {
                UnSummon();
                return;
            }

            m_timer -= msDiff;
            break;
        }
        case TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT:
        {
            if (!IsInCombat())
            {
                if (m_timer <= msDiff)
                {
                    UnSummon();
                    return;
                }

                m_timer -= msDiff;
            }
            else if (m_timer != m_lifetime)
                m_timer = m_lifetime;

            break;
        }

        case TEMPSUMMON_CORPSE_TIMED_DESPAWN:
        {
            if (m_deathState == CORPSE)
            {
                if (m_timer <= msDiff)
                {
                    UnSummon();
                    return;
                }

                m_timer -= msDiff;
            }
            break;
        }
        case TEMPSUMMON_CORPSE_DESPAWN:
        {
            // if m_deathState is DEAD, CORPSE was skipped
            if (m_deathState == CORPSE)
            {
                UnSummon();
                return;
            }

            break;
        }
        case TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN:
        {
            if (m_deathState == CORPSE)
            {
                UnSummon();
                return;
            }

            if (!IsInCombat())
            {
                if (m_timer <= msDiff)
                {
                    UnSummon();
                    return;
                }
                else
                    m_timer -= msDiff;
            }
            else if (m_timer != m_lifetime)
                m_timer = m_lifetime;
            break;
        }
        case TEMPSUMMON_TIMED_OR_DEAD_DESPAWN:
        {
            if (!IsInCombat() && IsAlive())
            {
                if (m_timer <= msDiff)
                {
                    UnSummon();
                    return;
                }
                else
                    m_timer -= msDiff;
            }
            else if (m_timer != m_lifetime)
                m_timer = m_lifetime;
            break;
        }
        default:
            UnSummon();
            TC_LOG_ERROR("entities.unit", "Temporary summoned creature (entry: {}) have unknown type {} of ", GetEntry(), m_type);
            break;
    }
}

void TempSummon::InitStats(WorldObject* summoner, Milliseconds duration)
{
    ASSERT(!IsPet());

    m_timer = duration;
    m_lifetime = duration;

    if (m_type == TEMPSUMMON_MANUAL_DESPAWN)
        m_type = (duration <= 0ms) ? TEMPSUMMON_DEAD_DESPAWN : TEMPSUMMON_TIMED_DESPAWN;

    if (summoner && summoner->IsPlayer())
    {
        if (IsTrigger() && m_spells[0])
            m_ControlledByPlayer = true;

        if (CreatureSummonedData const* summonedData = sObjectMgr->GetCreatureSummonedData(GetEntry()))
        {
            m_creatureIdVisibleToSummoner = summonedData->CreatureIDVisibleToSummoner;
            if (summonedData->CreatureIDVisibleToSummoner)
            {
                CreatureTemplate const* creatureTemplateVisibleToSummoner = ASSERT_NOTNULL(sObjectMgr->GetCreatureTemplate(*summonedData->CreatureIDVisibleToSummoner));
                m_displayIdVisibleToSummoner = ObjectMgr::ChooseDisplayId(creatureTemplateVisibleToSummoner, nullptr)->CreatureDisplayID;
            }
        }
    }

    if (!m_Properties)
        return;

    if (Unit* unitSummoner = ToUnit(summoner))
    {
        std::ptrdiff_t slot = m_Properties->Slot;
        if (slot == SUMMON_SLOT_ANY_TOTEM)
            slot = FindUsableTotemSlot(unitSummoner);

        if (slot != 0)
        {
            if (!unitSummoner->m_SummonSlot[slot].IsEmpty() && unitSummoner->m_SummonSlot[slot] != GetGUID())
            {
                Creature* oldSummon = GetMap()->GetCreature(unitSummoner->m_SummonSlot[slot]);
                if (oldSummon && oldSummon->IsSummon())
                    oldSummon->ToTempSummon()->UnSummon();
            }
            unitSummoner->m_SummonSlot[slot] = GetGUID();
        }

        if (!m_Properties->GetFlags().HasFlag(SummonPropertiesFlags::UseCreatureLevel))
            SetLevel(unitSummoner->GetLevel());
    }

    uint32 faction = m_Properties->Faction;
    if (summoner && m_Properties->GetFlags().HasFlag(SummonPropertiesFlags::UseSummonerFaction)) // TODO: Determine priority between faction and flag
        faction = summoner->GetFaction();

    if (faction)
        SetFaction(faction);

    if (m_Properties->GetFlags().HasFlag(SummonPropertiesFlags::SummonFromBattlePetJournal))
        RemoveNpcFlag(UNIT_NPC_FLAG_WILD_BATTLE_PET);
}

void TempSummon::InitSummon(WorldObject* summoner)
{
    if (summoner)
    {
        if (summoner->GetTypeId() == TYPEID_UNIT)
        {
            if (summoner->ToCreature()->IsAIEnabled())
                summoner->ToCreature()->AI()->JustSummoned(this);
        }
        else if (summoner->GetTypeId() == TYPEID_GAMEOBJECT)
        {
            if (summoner->ToGameObject()->AI())
                summoner->ToGameObject()->AI()->JustSummoned(this);
        }
        if (IsAIEnabled())
            AI()->IsSummonedBy(summoner);
    }
}

void TempSummon::UpdateObjectVisibilityOnCreate()
{
    boost::container::small_vector<WorldObject*, 2> objectsToUpdate;
    objectsToUpdate.push_back(this);

    if (SmoothPhasing const* smoothPhasing = GetSmoothPhasing())
    {
        SmoothPhasingInfo const* infoForSeer = smoothPhasing->GetInfoForSeer(GetDemonCreatorGUID());
        if (infoForSeer && infoForSeer->ReplaceObject && smoothPhasing->IsReplacing(*infoForSeer->ReplaceObject))
            if (WorldObject* original = ObjectAccessor::GetWorldObject(*this, *infoForSeer->ReplaceObject))
                objectsToUpdate.push_back(original);
    }

    Trinity::VisibleChangesNotifier notifier({ objectsToUpdate.data(), objectsToUpdate.data() + objectsToUpdate.size() });
    Cell::VisitWorldObjects(this, notifier, GetVisibilityRange());
}

void TempSummon::UpdateObjectVisibilityOnDestroy()
{
    boost::container::small_vector<WorldObject*, 2> objectsToUpdate;
    objectsToUpdate.push_back(this);

    WorldObject* original = nullptr;
    if (SmoothPhasing const* smoothPhasing = GetSmoothPhasing())
    {
        SmoothPhasingInfo const* infoForSeer = smoothPhasing->GetInfoForSeer(GetDemonCreatorGUID());
        if (infoForSeer && infoForSeer->ReplaceObject && smoothPhasing->IsReplacing(*infoForSeer->ReplaceObject))
            original = ObjectAccessor::GetWorldObject(*this, *infoForSeer->ReplaceObject);

        if (original)
        {
            objectsToUpdate.push_back(original);

            // disable replacement without removing - it is still needed for next step (visibility update)
            if (SmoothPhasing* originalSmoothPhasing = original->GetSmoothPhasing())
                originalSmoothPhasing->DisableReplacementForSeer(GetDemonCreatorGUID());
        }
    }

    Trinity::VisibleChangesNotifier notifier({ objectsToUpdate.data(), objectsToUpdate.data() + objectsToUpdate.size() });
    Cell::VisitWorldObjects(this, notifier, GetVisibilityRange());

    if (original) // original is only != nullptr when it was replaced
        if (SmoothPhasing* originalSmoothPhasing = original->GetSmoothPhasing())
            originalSmoothPhasing->ClearViewerDependentInfo(GetDemonCreatorGUID());
}

void TempSummon::SetTempSummonType(TempSummonType type)
{
    m_type = type;
}

void TempSummon::UnSummon(uint32 msTime)
{
    if (msTime)
    {
        ForcedUnsummonDelayEvent* pEvent = new ForcedUnsummonDelayEvent(*this);

        m_Events.AddEvent(pEvent, m_Events.CalculateTime(Milliseconds(msTime)));
        return;
    }

    //ASSERT(!IsPet());
    if (IsPet())
    {
        ToPet()->Remove(PET_SAVE_NOT_IN_SLOT);
        ASSERT(!IsInWorld());
        return;
    }

    if (WorldObject * owner = GetSummoner())
    {
        if (owner->GetTypeId() == TYPEID_UNIT && owner->ToCreature()->IsAIEnabled())
            owner->ToCreature()->AI()->SummonedCreatureDespawn(this);
        else if (owner->GetTypeId() == TYPEID_GAMEOBJECT && owner->ToGameObject()->AI())
            owner->ToGameObject()->AI()->SummonedCreatureDespawn(this);
    }

    AddObjectToRemoveList();
}

bool ForcedUnsummonDelayEvent::Execute(uint64 /*e_time*/, uint32 /*p_time*/)
{
    m_owner.UnSummon();
    return true;
}

void TempSummon::RemoveFromWorld()
{
    if (!IsInWorld())
        return;

    if (m_Properties && m_Properties->Slot != 0)
        if (Unit* owner = GetSummonerUnit())
            for (ObjectGuid& summonSlot : owner->m_SummonSlot)
                if (summonSlot == GetGUID())
                    summonSlot.Clear();

    //if (GetOwnerGUID())
    //    TC_LOG_ERROR("entities.unit", "Unit {} has owner guid when removed from world", GetEntry());

    Creature::RemoveFromWorld();
}

std::ptrdiff_t TempSummon::FindUsableTotemSlot(Unit const* summoner) const
{
    auto totemBegin = summoner->m_SummonSlot.begin() + SUMMON_SLOT_TOTEM;
    auto totemEnd = summoner->m_SummonSlot.begin() + MAX_TOTEM_SLOT;

    // first try exact guid match
    auto totemSlot = std::find_if(totemBegin, totemEnd, [&](ObjectGuid const& otherTotemGuid)
    {
        return otherTotemGuid == GetGUID();
    });

    // then a slot that shares totem category with this new summon
    if (totemSlot == totemEnd)
        totemSlot = std::find_if(totemBegin, totemEnd, [&](ObjectGuid const& otherTotemGuid) { return IsSharingTotemSlotWith(otherTotemGuid); });

    // any empty slot...?
    if (totemSlot == totemEnd)
        totemSlot = std::find_if(totemBegin, totemEnd, [](ObjectGuid const& otherTotemGuid) { return otherTotemGuid.IsEmpty(); });

    // if no usable slot was found, try used slot by a summon with the same creature id
    // we must not despawn unrelated summons
    if (totemSlot == totemEnd)
        totemSlot = std::find_if(totemBegin, totemEnd, [&](ObjectGuid const& otherTotemGuid) { return GetEntry() == otherTotemGuid.GetEntry(); });

    // if no slot was found, this summon gets no slot and will not be stored in m_SummonSlot
    if (totemSlot == totemEnd)
        return 0;

    return totemSlot - summoner->m_SummonSlot.begin();
}

bool TempSummon::IsSharingTotemSlotWith(ObjectGuid objectGuid) const
{
    Creature const* otherSummon = GetMap()->GetCreature(objectGuid);
    if (!otherSummon)
        return false;

    SpellInfo const* mySummonSpell = sSpellMgr->GetSpellInfo(m_unitData->CreatedBySpell, DIFFICULTY_NONE);
    if (!mySummonSpell)
        return false;

    SpellInfo const* otherSummonSpell = sSpellMgr->GetSpellInfo(otherSummon->m_unitData->CreatedBySpell, DIFFICULTY_NONE);
    if (!otherSummonSpell)
        return false;

    for (uint16 myTotemCategory : mySummonSpell->TotemCategory)
        if (myTotemCategory)
            for (uint16 otherTotemCategory : otherSummonSpell->TotemCategory)
                if (otherTotemCategory && DB2Manager::IsTotemCategoryCompatibleWith(myTotemCategory, otherTotemCategory, false))
                    return true;

    for (int32 myTotemId : mySummonSpell->Totem)
        if (myTotemId)
            for (int32 otherTotemId : otherSummonSpell->Totem)
                if (otherTotemId && myTotemId == otherTotemId)
                    return true;

    return false;
}

std::string TempSummon::GetDebugInfo() const
{
    std::stringstream sstr;
    sstr << Creature::GetDebugInfo() << "\n"
        << std::boolalpha
        << "TempSummonType: " << std::to_string(GetSummonType()) << " Summoner: " << GetSummonerGUID().ToString()
        << "Timer: " << GetTimer().count() << "ms";
    return sstr.str();
}

Minion::Minion(SummonPropertiesEntry const* properties, Unit* owner, bool isWorldObject)
    : TempSummon(properties, owner, isWorldObject), m_owner(owner)
{
    ASSERT(m_owner);
    m_unitTypeMask |= UNIT_MASK_MINION;
    m_followAngle = PET_FOLLOW_ANGLE;
    /// @todo: Find correct way
    InitCharmInfo();
}

void Minion::InitStats(WorldObject* summoner, Milliseconds duration)
{
    TempSummon::InitStats(summoner, duration);

    SetReactState(REACT_PASSIVE);

    SetCreatorGUID(GetOwner()->GetGUID());
    SetFaction(GetOwner()->GetFaction()); // TODO: Is this correct? Overwrite the use of SummonPropertiesFlags::UseSummonerFaction

    GetOwner()->SetMinion(this, true);
}

void Minion::RemoveFromWorld()
{
    if (!IsInWorld())
        return;

    GetOwner()->SetMinion(this, false);
    TempSummon::RemoveFromWorld();
}

void Minion::setDeathState(DeathState s)
{
    Creature::setDeathState(s);
    if (s != JUST_DIED || !IsGuardianPet())
        return;

    Unit* owner = GetOwner();
    if (!owner || owner->GetTypeId() != TYPEID_PLAYER || owner->GetMinionGUID() != GetGUID())
        return;

    for (Unit* controlled : owner->m_Controlled)
    {
        if (controlled->GetEntry() == GetEntry() && controlled->IsAlive())
        {
            owner->SetMinionGUID(controlled->GetGUID());
            owner->SetPetGUID(controlled->GetGUID());
            owner->ToPlayer()->CharmSpellInitialize();
            break;
        }
    }
}

bool Minion::IsGuardianPet() const
{
    return IsPet() || (m_Properties && m_Properties->Control == SUMMON_CATEGORY_PET);
}

std::string Minion::GetDebugInfo() const
{
    std::stringstream sstr;
    sstr << TempSummon::GetDebugInfo() << "\n"
        << std::boolalpha
        << "Owner: " << (GetOwner() ? GetOwner()->GetGUID().ToString() : "");
    return sstr.str();
}

Guardian::Guardian(SummonPropertiesEntry const* properties, Unit* owner, bool isWorldObject) : Minion(properties, owner, isWorldObject)
, m_bonusSpellDamage(0)
{
    memset(m_statFromOwner, 0, sizeof(float)*MAX_STATS);
    m_unitTypeMask |= UNIT_MASK_GUARDIAN;
    if (properties && (SummonTitle(properties->Title) == SummonTitle::Pet || properties->Control == SUMMON_CATEGORY_PET))
    {
        m_unitTypeMask |= UNIT_MASK_CONTROLABLE_GUARDIAN;
        InitCharmInfo();
    }
}

void Guardian::InitStats(WorldObject* summoner, Milliseconds duration)
{
    Minion::InitStats(summoner, duration);

    InitStatsForLevel(GetLevel()); // level is already initialized in TempSummon::InitStats, so use that

    if (GetOwner()->GetTypeId() == TYPEID_PLAYER && HasUnitTypeMask(UNIT_MASK_CONTROLABLE_GUARDIAN))
        m_charmInfo->InitCharmCreateSpells();

    SetReactState(REACT_AGGRESSIVE);
}

void Guardian::InitSummon(WorldObject* summoner)
{
    TempSummon::InitSummon(summoner);

    if (GetOwner()->GetTypeId() == TYPEID_PLAYER
            && GetOwner()->GetMinionGUID() == GetGUID()
            && !GetOwner()->GetCharmedGUID())
    {
        GetOwner()->ToPlayer()->CharmSpellInitialize();
    }
}

std::string Guardian::GetDebugInfo() const
{
    std::stringstream sstr;
    sstr << Minion::GetDebugInfo();
    return sstr.str();
}

Puppet::Puppet(SummonPropertiesEntry const* properties, Unit* owner)
    : Minion(properties, owner, false) //maybe true?
{
    ASSERT(m_owner->GetTypeId() == TYPEID_PLAYER);
    m_unitTypeMask |= UNIT_MASK_PUPPET;
}

void Puppet::InitStats(WorldObject* summoner, Milliseconds duration)
{
    Minion::InitStats(summoner, duration);
    SetReactState(REACT_PASSIVE);
}

void Puppet::InitSummon(WorldObject* summoner)
{
    Minion::InitSummon(summoner);
    if (!SetCharmedBy(GetOwner(), CHARM_TYPE_POSSESS))
        ABORT();
}

void Puppet::Update(uint32 time)
{
    Minion::Update(time);
    //check if caster is channelling?
    if (IsInWorld())
    {
        if (!IsAlive())
        {
            UnSummon();
            /// @todo why long distance .die does not remove it
        }
    }
}
