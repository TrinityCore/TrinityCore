/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

#ifndef TRINITYCORE_CREATURETEMPLATE_H
#define TRINITYCORE_CREATURETEMPLATE_H

#include "DBCEnums.h"
#include "Common.h"
#include "SharedDefines.h"

class WorldPacket;
namespace WorldPackets {
    namespace Query {
        class QueryCreatureResponse;
    }
}

enum class CreatureGroundMovementType : uint8
{
    None,
    Run,
    Hover,

    Max
};

enum class CreatureFlightMovementType : uint8
{
    None,
    DisableGravity,
    CanFly,

    Max
};

#pragma pack(push, 1)

struct CreatureMovementData
{
public:
    CreatureMovementData() : Ground(CreatureGroundMovementType::Run), Flight(CreatureFlightMovementType::None), Swim(true), Rooted(false) { }

    CreatureGroundMovementType Ground;
    CreatureFlightMovementType Flight;
    bool Swim;
    bool Rooted;

    bool IsGroundAllowed() const { return Ground != CreatureGroundMovementType::None; }
    bool IsSwimAllowed() const { return Swim; }
    bool IsFlightAllowed() const { return Flight != CreatureFlightMovementType::None; }
    bool IsRooted() const { return Rooted; }

    std::string ToString() const;
};

#pragma pack(pop)

// from `creature_template` table
struct CreatureTemplate
{
public:
	uint32  Entry;
	uint32  DifficultyEntry[MAX_DIFFICULTY - 1];
	uint32  KillCredit[MAX_KILL_CREDIT];
	uint32  Modelid1;
	uint32  Modelid2;
	uint32  Modelid3;
	uint32  Modelid4;
	std::string  Name;
	std::string  Title;
	std::string  IconName;
	uint32  GossipMenuId;
	uint8   minlevel;
	uint8   maxlevel;
	uint32  expansion;
	uint32  faction;
	uint32  npcflag;
	float   speed_walk;
	float   speed_run;
	float   scale;
	uint32  rank;
	uint32  dmgschool;
	uint32  BaseAttackTime;
	uint32  RangeAttackTime;
	float   BaseVariance;
	float   RangeVariance;
	uint32  unit_class;                                     // enum Classes. Note only 4 classes are known for creatures.
	uint32  unit_flags;                                     // enum UnitFlags mask values
	uint32  unit_flags2;                                    // enum UnitFlags2 mask values
	uint32  dynamicflags;
	CreatureFamily  family;                                 // enum CreatureFamily values (optional)
	uint32  trainer_type;
	uint32  trainer_spell;
	uint32  trainer_class;
	uint32  trainer_race;
	uint32  type;                                           // enum CreatureType values
	uint32  type_flags;                                     // enum CreatureTypeFlags mask values
	uint32  lootid;
	uint32  pickpocketLootId;
	uint32  SkinLootId;
	int32   resistance[MAX_SPELL_SCHOOL];
	uint32  spells[MAX_CREATURE_SPELLS];
	uint32  PetSpellDataId;
	uint32  VehicleId;
	uint32  mingold;
	uint32  maxgold;
	std::string AIName;
	uint32  MovementType;
	CreatureMovementData Movement;
	float   HoverHeight;
	float   ModHealth;
	float   ModMana;
	float   ModArmor;
	float   ModDamage;
	float   ModExperience;
	bool    RacialLeader;
	uint32  movementId;
	bool    RegenHealth;
	uint32  MechanicImmuneMask;
	uint32  SpellSchoolImmuneMask;
	uint32  flags_extra;
	uint32  ScriptID;

	uint32  GetRandomValidModelId() const;
	uint32  GetFirstValidModelId() const;
	uint32  GetFirstInvisibleModel() const;
	uint32  GetFirstVisibleModel() const;

	// helpers
	SkillType GetRequiredLootSkill() const
	{
		if (type_flags & CREATURE_TYPE_FLAG_HERB_SKINNING_SKILL)
			return SKILL_HERBALISM;
		else if (type_flags & CREATURE_TYPE_FLAG_MINING_SKINNING_SKILL)
			return SKILL_MINING;
		else if (type_flags & CREATURE_TYPE_FLAG_ENGINEERING_SKINNING_SKILL)
			return SKILL_ENGINEERING;
		else
			return SKILL_SKINNING;                          // normal case
	}

	bool IsExotic() const
	{
		return (type_flags & CREATURE_TYPE_FLAG_EXOTIC_PET) != 0;
	}

	bool IsTameable(bool canTameExotic) const
	{
		if (type != CREATURE_TYPE_BEAST || family == CREATURE_FAMILY_NONE || (type_flags & CREATURE_TYPE_FLAG_TAMEABLE_PET) == 0)
			return false;

		// if can tame exotic then can tame any tameable
		return canTameExotic || !IsExotic();
	}

	WorldPackets::Query::QueryCreatureResponse* _response[TOTAL_LOCALES];

    void InitializeQueryData();
	void InitializeQueryData(LocaleConstant lc);
	void BuildQueryData(LocaleConstant lc) const;
	WorldPacket* GetQueryDataRef(LocaleConstant lc);
	WorldPacket GetQueryData(LocaleConstant lc);
};

#endif
