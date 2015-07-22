/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

#ifndef DEF_SHATTERED_H
#define DEF_SHATTERED_H

#define DataHeader "SH"

uint32 const EncounterCount          = 4;
uint32 const VictimCount             = 3;

enum DataTypes
{
    DATA_NETHEKURSE                  = 0,
    DATA_OMROGG                      = 1,
    DATA_KARGATH                     = 2,

    DATA_SHATTERED_EXECUTIONER       = 3,
    DATA_PRISONERS_EXECUTED          = 4,

    DATA_TEAM_IN_INSTANCE            = 5,

    DATA_FIRST_PRISONER,
    DATA_SECOND_PRISONER,
    DATA_THIRD_PRISONER
};

enum CreatureIds
{
    NPC_GRAND_WARLOCK_NETHEKURSE     = 16807,
    NPC_KARGATH_BLADEFIST            = 16808,

    NPC_SHATTERED_EXECUTIONER        = 17301,

    // Alliance Ids
    NPC_RANDY_WHIZZLESPROCKET        = 17288,

    NPC_CAPTAIN_ALINA                = 17290,
    NPC_ALLIANCE_VICTIM_1            = 17289,
    NPC_ALLIANCE_VICTIM_2            = 17292,

    // Horde Ids
    NPC_DRISELLA                     = 17294,

    NPC_CAPTAIN_BONESHATTER          = 17296,
    NPC_HORDE_VICTIM_1               = 17295,
    NPC_HORDE_VICTIM_2               = 17297
};

enum GameobjectIds
{
    GO_GRAND_WARLOCK_CHAMBER_DOOR_1  = 182539,
    GO_GRAND_WARLOCK_CHAMBER_DOOR_2  = 182540
};

enum QuestIds
{
    QUEST_IMPRISONED_A               = 9524,
    QUEST_IMPRISONED_H               = 9525
};

enum InstanceSpells
{
    SPELL_KARGATH_EXECUTIONER_1      = 39288,
    SPELL_KARGATH_EXECUTIONER_2      = 39289,
    SPELL_KARGATH_EXECUTIONER_3      = 39290,

    SPELL_REMOVE_KARGATH_EXECUTIONER = 39291
};

enum Actions
{
    ACTION_EXECUTIONER_TAUNT = 1
};

const Position Executioner = { 152.8524f, -83.63912f, 2.021005f, 0.06981317f };

struct FactionSpawnerHelper
{
    FactionSpawnerHelper(uint32 allianceEntry, uint32 hordeEntry, const Position& pos) : _allianceNPC(allianceEntry), _hordeNPC(hordeEntry), _spawnPos(pos) { }

    inline uint32 operator()(uint32 teamID) const { return teamID == ALLIANCE ? _allianceNPC : _hordeNPC; }
    inline Position const& GetPos() const { return _spawnPos; }

private:
    const uint32 _allianceNPC;
    const uint32 _hordeNPC;
    const Position _spawnPos;
};

const FactionSpawnerHelper executionerVictims[VictimCount] =
{
    { NPC_CAPTAIN_ALINA,     NPC_CAPTAIN_BONESHATTER, { 138.8807f, -84.22707f, 1.992269f, 0.06981317f } },
    { NPC_ALLIANCE_VICTIM_1, NPC_HORDE_VICTIM_1,      { 151.2411f, -91.02930f, 2.019741f, 1.57079600f } },
    { NPC_ALLIANCE_VICTIM_2, NPC_HORDE_VICTIM_2,      { 151.0459f, -77.51981f, 2.021008f, 4.74729500f } }
};


#endif
