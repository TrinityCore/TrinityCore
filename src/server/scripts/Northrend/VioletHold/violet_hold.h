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

#ifndef VIOLET_HOLD_H_
#define VIOLET_HOLD_H_

#define VioletHoldScriptName "instance_violet_hold"
#define DataHeader "VH"

uint32 const EncounterCount = 3 + 6;

// Defined in instance_violet_hold.cpp
extern Position const DefenseSystemLocation;
uint8 const PortalIntroCount = 3;
extern Position const PortalIntroPositions[];

/*
 * Violet hold bosses:
 *
 * 1 - Moragg
 * 2 - Erekem
 * 3 - Ichoron
 * 4 - Lavanthor
 * 5 - Xevozz
 * 6 - Zuramat
 * 7 - Cyanigosa
 */

enum Data
{
    // Main encounters
    DATA_1ST_BOSS       = 0,
    DATA_2ND_BOSS       = 1,
    DATA_CYANIGOSA      = 2,
    // Bosses
    DATA_MORAGG         = 3,
    DATA_EREKEM         = 4,
    DATA_ICHORON        = 5,
    DATA_LAVANTHOR      = 6,
    DATA_XEVOZZ         = 7,
    DATA_ZURAMAT        = 8,

    // Misc
    DATA_MAIN_EVENT_STATE,
    DATA_WAVE_COUNT,
    DATA_DOOR_INTEGRITY,
    DATA_PORTAL_LOCATION,
    DATA_START_BOSS_ENCOUNTER,
    DATA_DEFENSELESS,

    // Bosses
    DATA_EREKEM_GUARD_1,
    DATA_EREKEM_GUARD_2,

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
    DATA_SINCLARI_TRIGGER,
    DATA_HANDLE_CELLS
};

enum CreaturesIds
{
    NPC_TELEPORTATION_PORTAL                    = 30679,
    NPC_TELEPORTATION_PORTAL_ELITE              = 32174,
    NPC_TELEPORTATION_PORTAL_INTRO              = 31011,
    NPC_PORTAL_GUARDIAN                         = 30660,
    NPC_PORTAL_KEEPER                           = 30695,
    NPC_XEVOZZ                                  = 29266,
    NPC_LAVANTHOR                               = 29312,
    NPC_ICHORON                                 = 29313,
    NPC_ICHOR_GLOBULE                           = 29321,
    NPC_ICHORON_SUMMON_TARGET                   = 29326,
    NPC_ZURAMAT                                 = 29314,
    NPC_VOID_SENTRY                             = 29364,
    NPC_VOID_SENTRY_BALL                        = 29365,
    NPC_EREKEM                                  = 29315,
    NPC_EREKEM_GUARD                            = 29395,
    NPC_MORAGG                                  = 29316,

    NPC_DUMMY_XEVOZZ                            = 32231,
    NPC_DUMMY_LAVANTHOR                         = 32237,
    NPC_DUMMY_ICHORON                           = 32234,
    NPC_DUMMY_ZURAMAT                           = 32230,
    NPC_DUMMY_EREKEM                            = 32226,
    NPC_DUMMY_EREKEM_GUARD                      = 32228,
    NPC_DUMMY_MORAGG                            = 32235,

    NPC_CYANIGOSA                               = 31134,
    NPC_SINCLARI                                = 30658,
    NPC_SINCLARI_TRIGGER                        = 32204,
    NPC_SABOTEOUR                               = 31079,
    NPC_VIOLET_HOLD_GUARD                       = 30659,
    NPC_DEFENSE_SYSTEM                          = 30837
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
    GO_ACTIVATION_CRYSTAL                       = 193611,
    GO_INTRO_ACTIVATION_CRYSTAL                 = 193615
};

enum WorldStateIds
{
    WORLD_STATE_VH_SHOW                         = 3816,
    WORLD_STATE_VH_PRISON_STATE                 = 3815,
    WORLD_STATE_VH_WAVE_COUNT                   = 3810,
};

enum Events
{
    EVENT_ACTIVATE_CRYSTAL                      = 20001
};

enum InstanceMisc
{
    ACTION_SINCLARI_OUTRO                       = 1,
    POINT_INTRO                                 = 1
};

template<class AI>
inline AI* GetVioletHoldAI(Creature* creature)
{
    return GetInstanceAI<AI>(creature, VioletHoldScriptName);
}

#endif // VIOLET_HOLD_H_
