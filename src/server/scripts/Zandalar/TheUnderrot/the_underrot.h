/*
 * Copyright (C) 2022 BfaCore Reforged
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

#ifndef THE_UNDERROT_H
#define THE_UNDERROT_H

#define DataHeader "TU"

uint32 const EncounterCount = 8;

enum EncounterData
{
    DATA_ELDER_LEAXA = 1,
    DATA_CRAGMAW_THE_INFESTED,
    DATA_SPORECALLER_ZANCHA,
    DATA_UNBOUND_ABOMINATION,
    DATA_FACELESS_CORRUPTOR_1,
    DATA_FACELESS_CORRUPTOR_2,
    DATA_EVENT_HERZEL,
    DATA_BOSS_HERZEL,
};

enum CreatureIds
{
    NPC_ELDER_LEAXA                 = 131318,
    NPC_CRAGMAW_THE_INFESTED        = 131817,
    NPC_BLOODSWORN_DEFILER          = 144306,
    NPC_SPORECALLER_ZANCHA          = 131383,
    NPC_VOLATILE_POD                = 139127,
    NPC_UNBOUND_ABOMINATION         = 133007,
    NPC_TITAN_KEEPER_HEZREL         = 134419,
    NPC_BLOOD_VISAGE                = 137103,
    NPC_ROTTING_SPORE               = 137458,
    SUMMON_GROUP_BLOODSWORN_DEFILER = 1
};

enum GameObjectIds
{
    GOB_PYRAMID_WEB             = 296384,
    GOB_PYRAMID_DOOR            = 296385,
};

#endif // THE_UNDERROT_H
