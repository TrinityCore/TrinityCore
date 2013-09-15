/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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

#ifndef MANA_TOMBS_H_
#define MANA_TOMBS_H_

#define MTScriptName "instance_mana_tombs"

uint32 const EncounterCount = 4;

enum DataTypes
{
    // Encounter States/Boss GUIDs
    DATA_PANDEMONIUS            = 0,
    DATA_TAVAROK                = 1,
    DATA_NEXUSPRINCE_SHAFFAR    = 2,
    DATA_YOR                    = 3
};

enum CreatureIds
{
};

enum GameObjectIds
{
};

template<class AI>
AI* GetManaTombsAI(Creature* creature)
{
    return GetInstanceAI<AI>(creature, MTScriptName);
}

#endif // MANA_TOMBS_H_
