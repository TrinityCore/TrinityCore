/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

#ifndef ARCATRAZ_H
#define ARCATRAZ_H

uint32 const EncounterCount               = 13;

#define AScriptName "instance_arcatraz"

enum DataTypes
{
    DATA_ZEREKETH                         = 1,
    DATA_DALLIAH                          = 2,
    DATA_SOCCOTHRATES                     = 3,
    DATA_HARBINGERSKYRISS                 = 4,
    DATA_WARDEN_1                         = 5,
    DATA_WARDEN_2                         = 6,
    DATA_WARDEN_3                         = 7,
    DATA_WARDEN_4                         = 8,
    DATA_WARDEN_5                         = 9,
    DATA_MELLICHAR                        = 10,
    DATA_SHIELD_OPEN                      = 11,
    DATA_SPHERE_SHIELD                    = 12,
    DATA_CONVERSATION                     = 13
};

enum CreaturesIds
{
    NPC_MELLICHAR                         = 20904, //skyriss will kill this unit
    NPC_ALPHA_POD_TARGET                  = 21436,
    NPC_DALLIAH                           = 20885,
    NPC_SOCCOTHRATES                      = 20886
};

enum GameObjectsIds
{
    CONTAINMENT_CORE_SECURITY_FIELD_ALPHA = 184318, //door opened when Wrath-Scryer Soccothrates dies
    CONTAINMENT_CORE_SECURITY_FIELD_BETA  = 184319, //door opened when Dalliah the Doomsayer dies
    POD_ALPHA                             = 183961, //pod first boss wave
    POD_BETA                              = 183963, //pod second boss wave
    POD_DELTA                             = 183964, //pod third boss wave
    POD_GAMMA                             = 183962, //pod fourth boss wave
    POD_OMEGA                             = 183965, //pod fifth boss wave
    WARDENS_SHIELD                        = 184802, // warden shield
    SEAL_SPHERE                           = 184802  //shield 'protecting' mellichar
};

#endif // ARCATRAZ_H
