/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

#ifndef GRUULS_LAIR_H_
#define GRUULS_LAIR_H_

#define GLScriptName "instance_gruuls_lair"
#define DataHeader   "GL"

uint32 const EncounterCount = 2;

enum DataTypes
{
    // Encounter States/Boss GUIDs
    DATA_MAULGAR                = 0,
    DATA_GRUUL                  = 1
};

enum CreatureIds
{
    NPC_MAULGAR                 = 18831,
    NPC_KROSH_FIREHAND          = 18832,
    NPC_OLM_THE_SUMMONER        = 18834,
    NPC_KIGGLER_THE_CRAZED      = 18835,
    NPC_BLINDEYE_THE_SEER       = 18836
};

enum GameObjectIds
{
    GO_MAULGAR_DOOR             = 184468,
    GO_GRUUL_DOOR               = 184662
};

template<class AI>
AI* GetGruulsLairAI(Creature* creature)
{
    return GetInstanceAI<AI>(creature, GLScriptName);
}

#endif // GRUULS_LAIR_H_
