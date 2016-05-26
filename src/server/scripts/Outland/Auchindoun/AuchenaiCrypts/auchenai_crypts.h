/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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

#ifndef AUCHENAI_CRYPTS_H_
#define AUCHENAI_CRYPTS_H_

#define ACScriptName "instance_auchenai_crypts"
#define DataHeader   "AC"

uint32 const EncounterCount = 2;

enum DataTypes
{
    // Encounter States/Boss GUIDs
    DATA_SHIRRAK_THE_DEAD_WATCHER   = 0,
    DATA_EXARCH_MALADAAR            = 1
};

enum CreatureIds
{
};

enum GameObjectIds
{
};

template<class AI>
AI* GetAuchenaiCryptsAI(Creature* creature)
{
    return GetInstanceAI<AI>(creature, ACScriptName);
}

#endif // AUCHENAI_CRYPTS_H_
