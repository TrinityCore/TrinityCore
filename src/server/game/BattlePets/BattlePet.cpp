/*
 * Copyright 2021 DekkCore
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

#include "BattlePet.h"
#include "PetBattle.h"
#include "PetBattleAbilityEffect.h"
#include "DB2Stores.h"
#include "Containers.h"
#include "Creature.h"
#include "DatabaseEnv.h"
#include "Item.h"
#include "Log.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "GameTables.h"
#include "WorldSession.h"
#include "CharacterDatabase.h"

void BattlePet::Load(Field* fields)
{
    JournalID = ObjectGuid::Create<HighGuid::BattlePet>(fields[0].GetUInt64());
    Slot = fields[1].GetInt32();
    Name = fields[2].GetString();
    NameTimeStamp = fields[3].GetUInt32();
    Species = fields[4].GetUInt32();
    Quality = fields[5].GetUInt32();
    Breed = fields[6].GetUInt32();
    Level = fields[7].GetUInt32();
    XP = fields[8].GetUInt32();
    DisplayModelID = fields[9].GetUInt32();
    Health = fields[10].GetInt32();
    Flags = fields[11].GetUInt32();
    InfoPower = fields[12].GetInt32();
    InfoMaxHealth = fields[13].GetInt32();
    InfoSpeed = fields[14].GetInt32();
    InfoGender = fields[15].GetInt32();
    AccountID = fields[16].GetInt32();
    DeclinedNames[0] = fields[17].GetString();
    DeclinedNames[1] = fields[18].GetString();
    DeclinedNames[2] = fields[19].GetString();
    DeclinedNames[3] = fields[20].GetString();
    DeclinedNames[4] = fields[21].GetString();

    UpdateAbilities();

    needSave = false;
    needDelete = false;
}

void BattlePet::CloneFrom(std::shared_ptr<BattlePet>& battlePet)
{
    JournalID = battlePet->JournalID;
    Slot = battlePet->Slot;
    Name = battlePet->Name;
    NameTimeStamp = battlePet->NameTimeStamp;
    Species = battlePet->Species;
    Quality = battlePet->Quality;
    Breed = battlePet->Breed;
    Level = battlePet->Level;
    XP = battlePet->XP;
    DisplayModelID = battlePet->DisplayModelID;
    Health = battlePet->Health;
    Flags = battlePet->Flags;
    InfoPower = battlePet->InfoPower;
    InfoMaxHealth = battlePet->InfoMaxHealth;
    InfoSpeed = battlePet->InfoSpeed;
    InfoGender = battlePet->InfoGender;
    AccountID = battlePet->AccountID;
    DeclinedNames[0] = battlePet->DeclinedNames[0];
    DeclinedNames[1] = battlePet->DeclinedNames[1];
    DeclinedNames[2] = battlePet->DeclinedNames[2];
    DeclinedNames[3] = battlePet->DeclinedNames[3];
    DeclinedNames[4] = battlePet->DeclinedNames[4];


    for (uint8 i = 0; i < MAX_PET_BATTLE_ABILITIES; ++i)
        Abilities[i] = battlePet->Abilities[i];

}

void BattlePet::Save(CharacterDatabaseTransaction& trans)
{
    if (!needSave || needDelete)
        return;

    CharacterDatabasePreparedStatement* statement = CharacterDatabase.GetPreparedStatement(CHAR_REP_PETBATTLE);
    statement->setUInt64(0, JournalID.GetCounter());
    statement->setInt32(1, Slot);
    statement->setString(2, Name);
    statement->setUInt32(3, NameTimeStamp);
    statement->setUInt32(4, Species);
    statement->setUInt32(5, Quality);
    statement->setUInt32(6, Breed);
    statement->setUInt32(7, Level);
    statement->setUInt32(8, XP);
    statement->setUInt32(9, DisplayModelID);
    statement->setInt32(10, Health);
    statement->setUInt32(11, Flags);
    statement->setInt32(12, InfoPower);
    statement->setInt32(13, InfoMaxHealth);
    statement->setInt32(14, InfoSpeed);
    statement->setInt32(15, InfoGender);
    statement->setInt32(16, AccountID);
    statement->setString(17, DeclinedNames[0]);
    statement->setString(18, DeclinedNames[1]);
    statement->setString(19, DeclinedNames[2]);
    statement->setString(20, DeclinedNames[3]);
    statement->setString(21, DeclinedNames[4]);
    trans->Append(statement);

    needSave = false;
}

void BattlePet::AddToPlayer(Player* player, CharacterDatabaseTransaction& trans)
{
    AccountID = player->GetSession()->GetAccountId();
    ObjectGuid::LowType guidlow = sObjectMgr->GetGenerator<HighGuid::PetBattle>().Generate();
    JournalID = ObjectGuid::Create<HighGuid::BattlePet>(guidlow);


    CharacterDatabasePreparedStatement* statement = CharacterDatabase.GetPreparedStatement(CHAR_REP_PETBATTLE);
    statement->setUInt64(0, guidlow);
    statement->setInt32(1, Slot);
    statement->setString(2, Name);
    statement->setUInt32(3, NameTimeStamp);
    statement->setUInt32(4, Species);
    statement->setUInt32(5, Quality);
    statement->setUInt32(6, Breed);
    statement->setUInt32(7, Level);
    statement->setUInt32(8, XP);
    statement->setUInt32(9, DisplayModelID);
    statement->setInt32(10, Health);
    statement->setUInt32(11, Flags);
    statement->setInt32(12, InfoPower);
    statement->setInt32(13, InfoMaxHealth);
    statement->setInt32(14, InfoSpeed);
    statement->setInt32(15, InfoGender);
    statement->setInt32(16, AccountID);
    statement->setString(17, DeclinedNames[0]);
    statement->setString(18, DeclinedNames[1]);
    statement->setString(19, DeclinedNames[2]);
    statement->setString(20, DeclinedNames[3]);
    statement->setString(21, DeclinedNames[4]);
    trans->Append(statement);

    needSave = false;
}

void BattlePet::Remove(Player* /*player*/)
{
    CharacterDatabasePreparedStatement* statement = CharacterDatabase.GetPreparedStatement(CHAR_DEL_PETBATTLE);
    statement->setUInt64(0, JournalID.GetCounter());
    CharacterDatabase.Execute(statement);

    needDelete = true;
}

ObjectGuid::LowType BattlePet::AddToPlayer(Player* player)
{
    AccountID = player->GetSession()->GetAccountId();
    auto guidlow = sObjectMgr->GetGenerator<HighGuid::BattlePet>().Generate();
    JournalID = ObjectGuid::Create<HighGuid::BattlePet>(guidlow);



    CharacterDatabasePreparedStatement* statement = CharacterDatabase.GetPreparedStatement(CHAR_REP_PETBATTLE);
    statement->setUInt64(0, guidlow);
    statement->setInt32(1, Slot);
    statement->setString(2, Name);
    statement->setUInt32(3, NameTimeStamp);
    statement->setUInt32(4, Species);
    statement->setUInt32(5, Quality);
    statement->setUInt32(6, Breed);
    statement->setUInt32(7, Level);
    statement->setUInt32(8, XP);
    statement->setUInt32(9, DisplayModelID);
    statement->setInt32(10, Health);
    statement->setUInt32(11, Flags);
    statement->setInt32(12, InfoPower);
    statement->setInt32(13, InfoMaxHealth);
    statement->setInt32(14, InfoSpeed);
    statement->setInt32(15, InfoGender);
    statement->setInt32(16, AccountID);
    statement->setString(17, DeclinedNames[0]);
    statement->setString(18, DeclinedNames[1]);
    statement->setString(19, DeclinedNames[2]);
    statement->setString(20, DeclinedNames[3]);
    statement->setString(21, DeclinedNames[4]);
    CharacterDatabase.Execute(statement);

    player->UpdateCriteria(CriteriaType::AccountObtainPetThroughBattle, 1);//CriteriaType::AccountObtainPetThroughBattle-->CRITERIA_TYPE_OWN_BATTLE_PET_COUNT

    needSave = false;
    return guidlow;
}
/*
uint32 BattlePet::GetPetUniqueSpeciesCount() const
{
    std::set<uint32> speciesIds;
    std::transform(_pets.begin(), _pets.end(), std::inserter(speciesIds, speciesIds.end()), [](std::pair<uint64 const, BattlePet> const& pet)
        {
            return pet.second.PacketInfo.Species;
        });
    return speciesIds.size();
}*/

void BattlePet::UpdateAbilities()
{
    for (auto& Abilitie : Abilities)
        Abilitie = 0;

    for (auto const& speciesXAbilityInfo : sBattlePetSpeciesXAbilityStore)
    {
        if (speciesXAbilityInfo->BattlePetSpeciesID != Species || speciesXAbilityInfo->RequiredLevel > Level || speciesXAbilityInfo->SlotEnum < 0 || speciesXAbilityInfo->SlotEnum >= MAX_PET_BATTLE_ABILITIES)
            continue;

        if (speciesXAbilityInfo->RequiredLevel < 5)
            Abilities[speciesXAbilityInfo->SlotEnum] = speciesXAbilityInfo->BattlePetAbilityID;
        else
        {
            switch (speciesXAbilityInfo->SlotEnum)
            {
            case 0:
                if (Flags & BATTLE_PET_FLAG_ABILITY_1)
                    Abilities[speciesXAbilityInfo->SlotEnum] = speciesXAbilityInfo->BattlePetAbilityID;
                break;
            case 1:
                if (Flags & BATTLE_PET_FLAG_ABILITY_2)
                    Abilities[speciesXAbilityInfo->SlotEnum] = speciesXAbilityInfo->BattlePetAbilityID;
                break;
            case 2:
                if (Flags & BATTLE_PET_FLAG_ABILITY_3)
                    Abilities[speciesXAbilityInfo->SlotEnum] = speciesXAbilityInfo->BattlePetAbilityID;
                break;
            default:
                break;
            }
        }
    }
}

void BattlePet::UpdateStats()
{
    int32 _InfoGender = InfoGender;
    int32 _InfoPower = InfoPower;
    int32 _InfoSpeed = InfoSpeed;
    int32 _InfoMaxHealth = InfoMaxHealth;

    int32* stats = &InfoPower;
    InfoGender = 0;

    for (size_t i = 0; i < 3; ++i)
        stats[i] = 1000;

    for (auto const& v : sBattlePetBreedStateStore)
    {
        if (v->BattlePetBreedID != Breed)
            continue;

        switch (v->BattlePetStateID)
        {
        case BATTLE_PET_STATE_Stat_Power:
        case BATTLE_PET_STATE_Stat_Stamina:
        case BATTLE_PET_STATE_Stat_Speed:
            stats[v->BattlePetStateID - BATTLE_PET_STATE_Stat_Power] = v->Value;
            break;
        case BATTLE_PET_STATE_Stat_Gender:
            InfoGender = v->Value;
            break;
        default:
            break;
        }
    }

    for (auto const& v : sBattlePetSpeciesStateStore)
    {
        if (v->BattlePetSpeciesID != Species)
            continue;

        switch (v->BattlePetStateID)
        {
        case BATTLE_PET_STATE_Stat_Power:
        case BATTLE_PET_STATE_Stat_Stamina:
        case BATTLE_PET_STATE_Stat_Speed:
            stats[v->BattlePetStateID - BATTLE_PET_STATE_Stat_Power] += v->Value;
            break;
        default:
            break;
        }
    }

    float qualityFactor = 1.0f;
    //    if (auto aualityInfo = sBattlePetBreedQualityStore[7 + Quality]) 
    //       qualityFactor = aualityInfo->StateMultiplier;


    for (size_t i = 0; i < 3; ++i)
        stats[i] = stats[i] * Level * qualityFactor;

    InfoPower = InfoPower / 100;
    InfoSpeed = InfoSpeed / 100;
    InfoMaxHealth = int32(floor((10000.0f + InfoMaxHealth * 5.0f) / 100.0f + 0.5));

    if (_InfoGender != InfoGender || _InfoPower != InfoPower || _InfoSpeed != InfoSpeed || _InfoMaxHealth != InfoMaxHealth || Health != InfoMaxHealth)
        needSave = true;

    Health = InfoMaxHealth;
}

BattlePetInstance::BattlePetInstance() : TeamID(0), ID(0), Cooldowns{}, Lockdowns{}, States{}, PetBattleInstance(nullptr), OldLevel(0), OldXP(0)
{
    OriginalBattlePet = std::shared_ptr<BattlePet>();
    OriginalCreature.Clear();
}

std::shared_ptr<BattlePetInstance> BattlePetInstance::CloneForBattle(std::shared_ptr<BattlePetInstance> const& battlePet)
{
    auto battlePetInstance = std::make_shared<BattlePetInstance>();
    battlePetInstance->JournalID = battlePet->JournalID;
    battlePetInstance->Slot = battlePet->Slot;
    battlePetInstance->Name = battlePet->Name;
    battlePetInstance->NameTimeStamp = battlePet->NameTimeStamp;
    battlePetInstance->Species = battlePet->Species;
    battlePetInstance->Quality = battlePet->Quality;
    battlePetInstance->Breed = battlePet->Breed;
    battlePetInstance->Level = battlePet->Level;
    battlePetInstance->XP = battlePet->XP;
    battlePetInstance->DisplayModelID = battlePet->DisplayModelID;
    battlePetInstance->Health = battlePet->Health;
    battlePetInstance->Flags = battlePet->Flags;
    battlePetInstance->InfoPower = battlePet->InfoPower;
    battlePetInstance->InfoMaxHealth = battlePet->InfoMaxHealth;
    battlePetInstance->InfoSpeed = battlePet->InfoSpeed;
    battlePetInstance->InfoGender = battlePet->InfoGender;
    battlePetInstance->AccountID = battlePet->AccountID;
    battlePetInstance->DeclinedNames[0] = battlePet->DeclinedNames[0];
    battlePetInstance->DeclinedNames[1] = battlePet->DeclinedNames[1];
    battlePetInstance->DeclinedNames[2] = battlePet->DeclinedNames[2];
    battlePetInstance->DeclinedNames[3] = battlePet->DeclinedNames[3];
    battlePetInstance->DeclinedNames[4] = battlePet->DeclinedNames[4];
    for (uint8 i = 0; i < MAX_PET_BATTLE_ABILITIES; ++i)
        battlePetInstance->Abilities[i] = battlePet->Abilities[i];
    return battlePetInstance;
}

bool BattlePetInstance::IsAlive()
{
    return States[BATTLE_PET_STATE_Is_Dead] == 0;
}

bool BattlePetInstance::CanAttack()
{
    return !States[BATTLE_PET_STATE_turnLock] && !States[BATTLE_PET_STATE_Mechanic_IsStunned];
}

int32 BattlePetInstance::GetMaxHealth()
{
    return int32(floor((10000.0f + 5.0f * States[BATTLE_PET_STATE_Stat_Stamina] + States[BATTLE_PET_STATE_maxHealthBonus] * States[BATTLE_PET_STATE_Internal_InitialLevel]) / 100.0f + 0.5));
}

int32 BattlePetInstance::GetSpeed()
{
    int32 modPercent = States[BATTLE_PET_STATE_Mod_SpeedPercent];

    // Passive: flying
    if (States[BATTLE_PET_STATE_Passive_Flying])
        modPercent += 50;

    return (States[BATTLE_PET_STATE_Stat_Speed] + CalculatePct(States[BATTLE_PET_STATE_Stat_Speed], modPercent)) / 100;
}

uint32 BattlePetInstance::GetMaxXPForCurrentLevel()
{
    if (auto xpTable = sBattlePetXPTable.GetRow(Level))
        return xpTable->Xp * xpTable->Wins;
    else
        return 0;
}

uint32 BattlePetInstance::GetXPEarn(uint32 targetPetID)
{
    auto targetPet = PetBattleInstance->Pets[targetPetID];
    int32 levelDiff = targetPet->Level - Level;
    if (levelDiff < -4 || levelDiff > 2)
        return 0;

    return (Level + 9) * (levelDiff + 5);
}

void BattlePetInstance::UpdateOriginalInstance(Player* player)
{
    if (!OriginalBattlePet)
        return;

    bool sendUpdate = OriginalBattlePet->Level != Level || OriginalBattlePet->XP != XP;
    OriginalBattlePet->JournalID = JournalID;
    OriginalBattlePet->Slot = Slot;
    OriginalBattlePet->Species = Species;
    OriginalBattlePet->Quality = Quality;
    OriginalBattlePet->Breed = Breed;
    OriginalBattlePet->Level = Level;
    OriginalBattlePet->XP = XP;
    OriginalBattlePet->DisplayModelID = DisplayModelID;
    OriginalBattlePet->Health = Health;
    OriginalBattlePet->Flags = Flags;
    OriginalBattlePet->InfoPower = InfoPower;
    OriginalBattlePet->InfoMaxHealth = InfoMaxHealth;
    OriginalBattlePet->InfoSpeed = InfoSpeed;
    OriginalBattlePet->InfoGender = InfoGender;
    OriginalBattlePet->AccountID = AccountID;
    OriginalBattlePet->needSave = true;

    if (sendUpdate)
        player->GetSession()->SendBattlePetUpdates(OriginalBattlePet.get());
}

