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

#ifndef DEF_PINNACLE_H
#define DEF_PINNACLE_H

uint32 const EncounterCount = 4;

enum DataTypes
{
    DATA_SVALA                  = 0,
    DATA_GORTOK_PALEHOOF        = 1,
    DATA_SKADI_THE_RUTHLESS     = 2,
    DATA_KING_YMIRON            = 3,  

    DATA_SVALA_SORROWGRAVE      = 4,
    DATA_SACRIFICED_PLAYER      = 5,

    DATA_NPC_FRENZIED_WORGEN    = 6,
    DATA_NPC_RAVENOUS_FURBOLG   = 7,
    DATA_NPC_MASSIVE_JORMUNGAR  = 8,
    DATA_NPC_FEROCIOUS_RHINO    = 9,
    DATA_NPC_ORB                = 10,
    DATA_GORTOK_PALEHOOF_SPHERE = 11,

    DATA_NPC_GRAUF              = 12
};


enum CreatureID
{
    BOSS_SVALA_SORROWGRAVE   = 26668,
    BOSS_GORTOK_PALEHOOF     = 26687,
    BOSS_SKADI_RUTHLESS      = 26693,
    BOSS_KING_YMIRON         = 26861,
    NPC_FRENZIED_WORGEN      = 26683,
    NPC_RAVENOUS_FURBOLG     = 26684,
    NPC_MASSIVE_JORMUNGAR    = 26685,
    NPC_FEROCIOUS_RHINO      = 26686,
    NPC_SVALA                = 29281,
    NPC_PALEHOOF_ORB         = 26688,
    NPC_GRAUF                = 26893
};

enum GameObjects
{
    GO_SKADI_THE_RUTHLESS_DOOR            = 192173,
    GO_KING_YMIRON_DOOR                   = 192174,
    GO_PALEHOOF_SPHERE                    = 188593,
    GO_UTGARDE_MIRROR                     = 191745
};

#endif