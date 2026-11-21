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

#ifndef _Plaguefall_h__
#define _Plaguefall_h__

#include "CreatureAIImpl.h"

#define DataHeader "PF"
#define PFScriptName "instance_plaguefall"

uint32 const EncounterCount = 4;

enum PFDataTypes
{
    // Encounters
    DATA_GLOBGROG = 0,
    DATA_DOCTOR_ICKUS,
    DATA_DOMINA_VENOMBLADE,
    DATA_MARGRAVE_STRADAMA
};

enum PFCreatureIds
{
    // Bosses
    BOSS_GLOBGROG          = 164255,
    BOSS_DOCTOR_ICKUS      = 164967,
    BOSS_DOMINA_VENOMBLADE = 164266,
    BOSS_MARGRAVE_STRADAMA = 164267
};

template <class AI, class T>
inline AI* GetPlaguefallAI(T* obj)
{
    return GetInstanceAI<AI>(obj, PFScriptName);
}

#define RegisterPlaguefallCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetPlaguefallAI)

#endif // _Plaguefall_h__
