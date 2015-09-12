/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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

#ifndef DEF_VIOLET_HOLD_H
#define DEF_VIOLET_HOLD_H

#define DataHeader "VH"

uint32 const EncounterCount = 3;

enum Data
{
    // Main encounters
    DATA_1ST_BOSS_EVENT,
    DATA_2ND_BOSS_EVENT,
    DATA_CYANIGOSA,

    // Misc
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
    DATA_ACTIVATE_CRYSTAL,
    DATA_MAIN_EVENT_PHASE,
    DATA_DEFENSELESS,

    // Bosses
    DATA_MORAGG,
    DATA_EREKEM,
    DATA_EREKEM_GUARD_1,
    DATA_EREKEM_GUARD_2,
    DATA_ICHORON,
    DATA_LAVANTHOR,
    DATA_XEVOZZ,
    DATA_ZURAMAT,

    // Cells
    DATA_MORAGG_CELL,
    DATA_EREKEM_CELL,
    DATA_EREKEM_LEFT_GUARD_CELL,
    DATA_EREKEM_RIGHT_GUARD_CELL,
    DATA_ICHORON_CELL,
    DATA_LAVANTHOR_CELL,
    DATA_XEVOZZ_CELL,
    DATA_ZURAMAT_CELL,

    // Misc
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

enum CreaturesIds
{
    NPC_TELEPORTATION_PORTAL                    = 31011,
    NPC_PORTAL_GUARDIAN                         = 30660,
    NPC_PORTAL_KEEPER                           = 30695,
    NPC_XEVOZZ                                  = 29266,
    NPC_LAVANTHOR                               = 29312,
    NPC_ICHORON                                 = 29313,
    NPC_ZURAMAT                                 = 29314,
    NPC_EREKEM                                  = 29315,
    NPC_EREKEM_GUARD                            = 29395,
    NPC_MORAGG                                  = 29316,
    NPC_CYANIGOSA                               = 31134,
    NPC_SINCLARI                                = 30658,
    NPC_SABOTEOUR                               = 31079,
    NPC_VIOLET_HOLD_GUARD                       = 30659,
    NPC_DEFENSE_SYSTEM                          = 30837,
    NPC_VOID_SENTRY                             = 29364,
    NPC_VOID_SENTRY_BALL                        = 29365
};

enum GameObjectIds
{
    GO_MAIN_DOOR                                = 191723,
    GO_XEVOZZ_DOOR                              = 191556,
    GO_LAVANTHOR_DOOR                           = 191566,
    GO_ICHORON_DOOR                             = 191722,
    GO_ZURAMAT_DOOR                             = 191565,
    GO_EREKEM_DOOR                              = 191564,
    GO_EREKEM_GUARD_1_DOOR                      = 191563,
    GO_EREKEM_GUARD_2_DOOR                      = 191562,
    GO_MORAGG_DOOR                              = 191606,
    GO_INTRO_ACTIVATION_CRYSTAL                 = 193615,
    GO_ACTIVATION_CRYSTAL                       = 193611
};

enum WorldStateIds
{
    WORLD_STATE_VH                              = 3816,
    WORLD_STATE_VH_PRISON_STATE                 = 3815,
    WORLD_STATE_VH_WAVE_COUNT                   = 3810,
};

enum Events
{
    EVENT_ACTIVATE_CRYSTAL                      = 20001
};

#endif
