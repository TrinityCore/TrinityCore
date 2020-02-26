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

#ifndef DEF_ZULAMAN_H
#define DEF_ZULAMAN_H

#include "CreatureAIImpl.h"

#define ZulamanScriptName "instance_zulaman"
#define DataHeader "ZA"

enum ZADataTypes
{
    BOSS_NALORAKK                       = 0,
    BOSS_AKILZON                        = 1,
    BOSS_JANALAI                        = 2,
    BOSS_HALAZZI                        = 3,
    BOSS_HEXLORD                        = 4,
    BOSS_ZULJIN                         = 5,
    MAX_ENCOUNTER,

    DATA_GONGEVENT,
    DATA_CHESTLOOTED,
    TYPE_RAND_VENDOR_1,
    TYPE_RAND_VENDOR_2
};

enum ZACreatureIds
{
    NPC_HARRISON_JONES                  = 24358,
    NPC_NALORAKK                        = 23576,
    NPC_AKILZON                         = 23574,
    NPC_JANALAI                         = 23578,
    NPC_HALAZZI                         = 23577,
    NPC_HEXLORD                         = 24239,
    NPC_ZULJIN                          = 23863
};

enum ZAGameObjectIds
{
    GO_LYNX_TEMPLE_EXIT                 = 186303,
    GO_LYNX_TEMPLE_ENTRANCE             = 186304,
    GO_HEXLORD_ENTRANCE                 = 186305,
    GO_WOODEN_DOOR                      = 186306,
    GO_MASSIVE_GATE                     = 186728,
    GO_DOOR_AKILZON                     = 186858,
    GO_DOOR_ZULJIN                      = 186859,
    GO_HARKORS_SATCHEL                  = 187021,
    GO_TANZARS_TRUNK                    = 186648,
    GO_ASHLIS_BAG                       = 186672,
    GO_KRAZS_PACKAGE                    = 186667,
    GO_STRANGE_GONG                     = 187359
};

template <class AI, class T>
inline AI* GetZulAmanAI(T* obj)
{
    return GetInstanceAI<AI>(obj, ZulamanScriptName);
}

#endif
