/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

#ifndef UTGARDE_PINNACLE_H_
#define UTGARDE_PINNACLE_H_

#define UPScriptName "instance_utgarde_pinnacle"

uint32 const EncounterCount = 4;

enum DataTypes
{
    // Encounter States/Boss GUIDs
    DATA_SVALA_SORROWGRAVE          = 0,
    DATA_GORTOK_PALEHOOF            = 1,
    DATA_SKADI_THE_RUTHLESS         = 2,
    DATA_KING_YMIRON                = 3,

    // Additional Data
    DATA_UTGARDE_MIRROR             = 4,
    DATA_SVALA                      = 5,
    DATA_SACRIFICED_PLAYER          = 6,

    DATA_FRENZIED_WORGEN            = 7,
    DATA_RAVENOUS_FURBOLG           = 8,
    DATA_MASSIVE_JORMUNGAR          = 9,
    DATA_FEROCIOUS_RHINO            = 10,
    DATA_GORTOK_ORB                 = 11,
    DATA_GORTOK_PALEHOOF_SPHERE     = 12
};

enum CreatureIds
{
    NPC_SVALA_SORROWGRAVE           = 26668,
    NPC_GORTOK_PALEHOOF             = 26687,
    NPC_SKADI_THE_RUTHLESS          = 26693,
    NPC_KING_YMIRON                 = 26861,

    // Svala
    NPC_SVALA                       = 29281,

    // Gortok Palehoof
    NPC_FRENZIED_WORGEN             = 26683,
    NPC_RAVENOUS_FURBOLG            = 26684,
    NPC_MASSIVE_JORMUNGAR           = 26685,
    NPC_FEROCIOUS_RHINO             = 26686,
    NPC_PALEHOOF_ORB                = 26688
};

enum GameObjectIds
{
    GO_GORTOK_PALEHOOF_SPHERE       = 188593,
    GO_UTGARDE_MIRROR               = 191745,
    GO_SKADI_THE_RUTHLESS_DOOR      = 192173,
    GO_KING_YMIRON_DOOR             = 192174
};

template<class AI>
AI* GetUtgardePinnacleAI(Creature* creature)
{
    return GetInstanceAI<AI>(creature, UPScriptName);
}

#endif // UTGARDE_PINNACLE_H_
