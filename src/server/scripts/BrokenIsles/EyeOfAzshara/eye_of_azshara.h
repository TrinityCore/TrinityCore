/*
* Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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

#ifndef DEF_EYE_OF_AZSHARA_H
#define DEF_EYE_OF_AZSHARA_H

#define EoAScriptName "instance_eye_of_azshara"
#define DataHeader    "EOA"

uint32 const EncounterCount = 5;

enum EOADataTypes
{
    DATA_SERPENTRIX       = 0,
    DATA_WARLORD_PARJESH  = 1,
    DATA_LADY_HATECOIL    = 2,
    DATA_KING_DEEPBEARD   = 3,
    DATA_WRATH_OF_AZSHARA = 4
};

enum EOACreatureIds
{
    NPC_SERPENTRIX       = 91808,
    NPC_WARLORD_PARJESH  = 91784,
    NPC_LADY_HATECOIL    = 91789,
    NPC_KING_DEEPBEARD   = 91797,
    NPC_WRATH_OF_AZSHARA = 96028
};

template<class AI>
AI* GetEyeOfAzsharaAI(Creature* creature)
{
    return GetInstanceAI<AI>(creature, EoAScriptName);
}

#endif // EYE_OF_AZSHARA_H_
