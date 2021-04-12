/*
 * This file is part of tswow (https://github.com/tswow/).
 * Copyright (C) 2021 tswow <https://github.com/tswow/>
 * 
 * This program is free software: you can redistribute it and/or 
 * modify it under the terms of the GNU General Public License as 
 * published by the Free Software Foundation, version 3.
 * 
 * This program is distributed in the hope that it will be useful, 
 * but WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License 
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */
#include "TSCreatureTemplate.h"
#include "ObjectMgr.h"
#include "CreatureData.h"

TSCreatureTemplate::TSCreatureTemplate(CreatureTemplate * ct)
{
    this->ct = ct;
}

uint32 TSCreatureTemplate::GetEntry()
{
    return ct->Entry;
}

uint32 TSCreatureTemplate::GetDifficultyEntryA()
{
    return ct->DifficultyEntry[0];
}

uint32 TSCreatureTemplate::GetDifficultyEntryB()
{
    return ct->DifficultyEntry[1];
}

uint32 TSCreatureTemplate::GetDifficultyEntryC()
{
    return ct->DifficultyEntry[2];
}

uint32 TSCreatureTemplate::GetKillCreditA()
{
    return ct->KillCredit[0];
}

uint32 TSCreatureTemplate::GetKillCreditB()
{
    return ct->KillCredit[1];
}

uint32 TSCreatureTemplate::GetModelID1()
{
    return ct->Modelid1;
}

uint32 TSCreatureTemplate::GetModelID2()
{
    return ct->Modelid2;
}

uint32 TSCreatureTemplate::GetModelID3()
{
    return ct->Modelid3;
}

uint32 TSCreatureTemplate::GetModelID4()
{
    return ct->Modelid4;
}

TSString TSCreatureTemplate::GetName()
{
    return JSTR(ct->Name);
}

TSString TSCreatureTemplate::GetTitle()
{
    return JSTR(ct->Title);
}

TSString TSCreatureTemplate::GetIconName()
{
    return JSTR(ct->IconName);
}
uint32 TSCreatureTemplate::GetGossipMenuID()
{
    return ct->GossipMenuId;
}

uint8 TSCreatureTemplate::GetMinLevel()
{
    return ct->minlevel;
}
uint8 TSCreatureTemplate::GetMaxLevel()
{
    return ct->maxlevel;
}
uint32 TSCreatureTemplate::GetExpansion()
{
    return ct->expansion;
}
uint32 TSCreatureTemplate::GetFaction()
{
    return ct->faction;
}
uint32 TSCreatureTemplate::GetNPCFlag()
{
    return ct->npcflag;
}
float TSCreatureTemplate::GetSpeedWalk()
{
    return ct->speed_walk;
}
float TSCreatureTemplate::GetSpeedRun()
{
    return ct->speed_run;
}
float TSCreatureTemplate::GetScale()
{
    return ct->scale;
}
uint32 TSCreatureTemplate::GetRank()
{
    return ct->rank;
}
uint32 TSCreatureTemplate::GetDamageSchool()
{
    return ct->dmgschool;
}
uint32 TSCreatureTemplate::GetBaseAttackTime()
{
    return ct->BaseAttackTime;
}
uint32 TSCreatureTemplate::GetRangeAttackTime()
{
    return ct->RangeAttackTime;
}
float TSCreatureTemplate::GetBaseVariance()
{
    return ct->BaseVariance;
}
float TSCreatureTemplate::GetRangeVariance()
{
    return ct->RangeVariance;
}
uint32 TSCreatureTemplate::GetUnitClass()
{
    return ct->unit_class;
}
uint32 TSCreatureTemplate::GetUnitFlags()
{
    return ct->unit_flags;
}
uint32 TSCreatureTemplate::GetUnitFlags2()
{
    return ct->unit_flags2;
}
uint32 TSCreatureTemplate::GetDynamicFlags()
{
    return ct->dynamicflags;
}
uint32 TSCreatureTemplate::GetFamily()
{
    return ct->family;
}
uint32 TSCreatureTemplate::GetType()
{
    return ct->type;
}
uint32 TSCreatureTemplate::GetTypeFlags()
{
    return ct->type_flags;
}
uint32 TSCreatureTemplate::GetLootID()
{
    return ct->lootid;
}
uint32 TSCreatureTemplate::GetPickpocketLootID()
{
    return ct->pickpocketLootId;
}
uint32 TSCreatureTemplate::GetSkinLootID()
{
    return ct->SkinLootId;
}
int32 TSCreatureTemplate::GetNormalResistance()
{
    return ct->SkinLootId;
}
int32 TSCreatureTemplate::GetHolyResistance()
{
    return ct->resistance[0];
}
int32 TSCreatureTemplate::GetFireResistance()
{
    return ct->resistance[1];
}
int32 TSCreatureTemplate::GetNatureResistance()
{
    return ct->resistance[2];
}
int32 TSCreatureTemplate::GetFrostResistance()
{
    return ct->resistance[3];
}
int32 TSCreatureTemplate::GetShadowResistance()
{
    return ct->resistance[4];
}
int32 TSCreatureTemplate::GetArcaneResistance()
{
    return ct->resistance[5];
}
uint32 TSCreatureTemplate::GetSpellA()
{
    return ct->spells[0];
}
uint32 TSCreatureTemplate::GetSpellB()
{
    return ct->spells[1];
}
uint32 TSCreatureTemplate::GetSpellC()
{
    return ct->spells[2];
}
uint32 TSCreatureTemplate::GetSpellD()
{
    return ct->spells[3];
}
uint32 TSCreatureTemplate::GetSpellE()
{
    return ct->spells[4];
}
uint32 TSCreatureTemplate::GetSpellF()
{
    return ct->spells[5];
}
uint32 TSCreatureTemplate::GetSpellG()
{
    return ct->spells[6];
}
uint32 TSCreatureTemplate::GetSpellH()
{
    return ct->spells[7];
}
uint32 TSCreatureTemplate::GetPetSpellDataID()
{
    return ct->PetSpellDataId;
}
uint32 TSCreatureTemplate::GetVehicleID()
{
    return ct->VehicleId;
}
uint32 TSCreatureTemplate::GetMinGold()
{
    return ct->mingold;
}
uint32 TSCreatureTemplate::GetMaxGold()
{
    return ct->maxgold;
}
TSString TSCreatureTemplate::GetAIName()
{
    return ct->AIName;
}
uint32 TSCreatureTemplate::GetMovementType()
{
    return ct->MovementType;
}
float TSCreatureTemplate::GetHoverHeight()
{
    return ct->HoverHeight;
}
float TSCreatureTemplate::GetModHealth()
{
    return ct->ModHealth;
}
float TSCreatureTemplate::GetModMana()
{
    return ct->ModMana;
}
float TSCreatureTemplate::GetModArmor()
{
    return ct->ModArmor;
}
float TSCreatureTemplate::GetModDamage()
{
    return ct->ModDamage;
}
float TSCreatureTemplate::GetModExperience()
{
    return ct->ModExperience;
}
bool TSCreatureTemplate::GetRacialLeader()
{
    return ct->RacialLeader;
}
uint32 TSCreatureTemplate::GetMovementID()
{
    return ct->movementId;
}
bool TSCreatureTemplate::GetRegenHealth()
{
    return ct->RegenHealth;
}
uint32 TSCreatureTemplate::GetMechanicImmuneMask()
{
    return ct->MechanicImmuneMask;
}
uint32 TSCreatureTemplate::GetSpellSchoolImmuneMask()
{
    return ct->SpellSchoolImmuneMask;
}
uint32 TSCreatureTemplate::GetFlagsExtra()
{
    return ct->flags_extra;
}
uint32 TSCreatureTemplate::GetScriptID()
{
    return ct->ScriptID;
}
uint32 TSCreatureTemplate::GetRandomValidModelID() const
{
    return ct->GetRandomValidModelId();
}
uint32 TSCreatureTemplate::GetFirstValidModelID() const
{
    return ct->GetFirstValidModelId();
}
uint32 TSCreatureTemplate::GetFirstInvisibleModel() const
{
    return ct->GetFirstInvisibleModel();
}
uint32 TSCreatureTemplate::GetFirstVisibleModel() const
{
    return ct->GetFirstVisibleModel();
}
TSStorage * TSCreatureTemplate::GetData()
{
    return &ct->storage;
}
uint32 TSCreatureTemplate::GetRequiredLootSkill() const
{
    return ct->GetRequiredLootSkill();
}
bool TSCreatureTemplate::GetIsExotic() const
{
    return ct->IsExotic();
}
bool TSCreatureTemplate::GetIsTameable(bool canTameExotic) const
{
    return ct->IsTameable(canTameExotic);
}


// CreatureMovementData
uint32 TSCreatureTemplate::GetGroundMovement()
{
    return static_cast<uint32>(ct->Movement.Ground);
}
uint32 TSCreatureTemplate::GetFlightMovement()
{
    return static_cast<uint32>(ct->Movement.Flight);
}
bool TSCreatureTemplate::GetSwims()
{
    return ct->Movement.Swim;
}
bool TSCreatureTemplate::GetRooted()
{
    return ct->Movement.Rooted;
}
uint32 TSCreatureTemplate::GetChaseMovement()
{
    return static_cast<uint32>(ct->Movement.Chase);
}
uint32 TSCreatureTemplate::GetRandomMovement()
{
    return static_cast<uint32>(ct->Movement.Random);
}
uint32 TSCreatureTemplate::GetInteractionPauseTimer()
{
    return ct->Movement.InteractionPauseTimer;
}
bool TSCreatureTemplate::GetIsGroundAllowed()
{
    return ct->Movement.IsGroundAllowed();
}
bool TSCreatureTemplate::GetIsSwimAllowed()
{
    return ct->Movement.IsSwimAllowed();
}
bool TSCreatureTemplate::GetIsFlightAllowed()
{
    return ct->Movement.IsFlightAllowed();
}
bool TSCreatureTemplate::GetIsRooted()
{
    return ct->Movement.IsRooted();
}

TSCreatureTemplate GetCreatureTemplate(uint32 entry)
{
    return TSCreatureTemplate(
        const_cast<CreatureTemplate*>(sObjectMgr->GetCreatureTemplate(entry)));
}

TS_ENTITY_DATA_IMPL(TSCreatureTemplate)