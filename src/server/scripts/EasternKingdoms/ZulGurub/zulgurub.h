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

#ifndef DEF_ZULGURUB_H
#define DEF_ZULGURUB_H

uint32 const EncounterCount = 13;

#define ZGScriptName "instance_zulgurub"

enum DataTypes
{
    DATA_JEKLIK             = 0,  // Main boss
    DATA_VENOXIS            = 1,  // Main boss
    DATA_MARLI              = 2,  // Main boss
    DATA_ARLOKK             = 3,  // Main boss
    DATA_THEKAL             = 4,  // Main boss
    DATA_HAKKAR             = 5,  // End boss
    DATA_MANDOKIR           = 6,  // Optional boss
    DATA_JINDO              = 7,  // Optional boss
    DATA_GAHZRANKA          = 8,  // Optional boss
    DATA_EDGE_OF_MADNESS    = 9,  // Optional Event Edge of Madness - one of: Gri'lek, Renataki, Hazza'rah, or Wushoolay
    DATA_LORKHAN            = 10, // Zealot Lor'Khan add to High priest Thekal!
    DATA_ZATH               = 11, // Zealot Zath add to High priest Thekal!
    DATA_OHGAN              = 12  // Bloodlord Mandokir's raptor mount
};

enum CreatureIds
{
    NPC_ZEALOT_LORKHAN      = 11347,
    NPC_ZEALOT_ZATH         = 11348,
    NPC_HIGH_PRIEST_THEKAL  = 14509,
    NPC_JINDO_THE_HEXXER    = 11380,
    NPC_NIGHTMARE_ILLUSION  = 15163,
    NPC_ZULIAN_PROWLER      = 15101,
    NPC_VILEBRANCH_SPEAKER  = 11391,
    NPC_SHADE_OF_JINDO      = 14986,
    NPC_SACRIFICED_TROLL    = 14826,
    NPC_OHGAN               = 14988,
    NPC_CHAINED_SPIRT       = 15117,
    NPC_MANDOKIR            = 11382
};

template<class AI>
CreatureAI* GetZulGurubAI(Creature* creature)
{
    if (InstanceMap* instance = creature->GetMap()->ToInstanceMap())
        if (instance->GetInstanceScript())
            if (instance->GetScriptId() == sObjectMgr->GetScriptId(ZGScriptName))
                return new AI(creature);
    return NULL;
}

#endif
