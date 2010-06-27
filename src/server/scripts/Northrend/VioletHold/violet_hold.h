/*
 * Copyright (C) 2009 - 2010 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#ifndef DEF_VIOLET_HOLD_H
#define DEF_VIOLET_HOLD_H

enum Creatures
{
    CREATURE_TELEPORTATION_PORTAL                   = 31011,
    CREATURE_PORTAL_GUARDIAN                        = 30660,
    CREATURE_PORTAL_KEEPER                          = 30695,
    CREATURE_XEVOZZ                                 = 29266,
    CREATURE_LAVANTHOR                              = 29312,
    CREATURE_ICHORON                                = 29313,
    CREATURE_ZURAMAT                                = 29314,
    CREATURE_EREKEM                                 = 29315,
    CREATURE_EREKEM_GUARD                           = 29395,
    CREATURE_MORAGG                                 = 29316,
    CREATURE_CYANIGOSA                              = 31134,
    CREATURE_SINCLARI                               = 30658,
    CREATURE_SABOTEOUR                              = 31079,
    NPC_VIOLET_HOLD_GUARD                           = 30659
};

enum Data
{
    DATA_1ST_BOSS_EVENT,
    DATA_2ND_BOSS_EVENT,
    DATA_CYANIGOSA_EVENT,
    DATA_WAVE_COUNT,
    DATA_REMOVE_NPC,
    DATA_PORTAL_LOCATION,
    DATA_DOOR_INTEGRITY,
    DATA_NPC_PRESENCE_AT_DOOR,
    DATA_NPC_PRESENCE_AT_DOOR_ADD,
    DATA_NPC_PRESENCE_AT_DOOR_REMOVE,
    DATA_START_BOSS_ENCOUNTER,
    DATA_FIRST_BOSS,
    DATA_SECOND_BOSS,
    DATA_ACTIVATE_CRYSTAL
};

enum Data64
{
    DATA_MORAGG,
    DATA_EREKEM,
    DATA_EREKEM_GUARD_1,
    DATA_EREKEM_GUARD_2,
    DATA_ICHORON,
    DATA_LAVANTHOR,
    DATA_XEVOZZ,
    DATA_ZURAMAT,
    DATA_CYANIGOSA,
    DATA_MORAGG_CELL,
    DATA_EREKEM_CELL,
    DATA_EREKEM_LEFT_GUARD_CELL,
    DATA_EREKEM_RIGHT_GUARD_CELL,
    DATA_ICHORON_CELL,
    DATA_LAVANTHOR_CELL,
    DATA_XEVOZZ_CELL,
    DATA_ZURAMAT_CELL,
    DATA_MAIN_DOOR,
    DATA_SINCLARI,
    DATA_TELEPORTATION_PORTAL,
    DATA_SABOTEUR_PORTAL,
    DATA_ADD_TRASH_MOB,
    DATA_DEL_TRASH_MOB
};

enum Bosses
{
    BOSS_NONE,              // 0 used as marker for not yet randomized
    BOSS_MORAGG,
    BOSS_EREKEM,
    BOSS_ICHORON,
    BOSS_LAVANTHOR,
    BOSS_XEVOZZ,
    BOSS_ZURAMAT,
    BOSS_CYANIGOSA
};

enum VHWorldStates
{
    WORLD_STATE_VH              = 3816,
    WORLD_STATE_VH_PRISON_STATE = 3815,
    WORLD_STATE_VH_WAVE_COUNT   = 3810,
};

#endif
