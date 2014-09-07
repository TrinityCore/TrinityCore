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

#ifndef SETHEKK_HALLS_H_
#define SETHEKK_HALLS_H_

#define SHScriptName "instance_sethekk_halls"
#define DataHeader "SH"

uint32 const EncounterCount             = 3;

enum DataTypes
{
    // Encounter States/Boss GUIDs
    DATA_DARKWEAVER_SYTH                = 0,
    DATA_TALON_KING_IKISS               = 1,
    DATA_ANZU                           = 2
};

enum CreatureIds
{
    NPC_ANZU                            = 23035,
    NPC_BROOD_OF_ANZU                   = 23132
};

enum GameObjectIds
{
    GO_IKISS_DOOR                       = 177203
};

template<class AI>
AI* GetSethekkHallsAI(Creature* creature)
{
    return GetInstanceAI<AI>(creature, SHScriptName);
}

#endif // SETHEKK_HALLS_H_
