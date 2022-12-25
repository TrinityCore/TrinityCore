/*
 * Copyright 2023 AzgathCore
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

#include "GameObject.h"

#ifndef DEF_UNCHARTED_ISLAND_H
#define DEF_UNCHARTED_ISLAND_H

enum Data
{
    DATA_CAPTAIN_REZ = 1,
};

enum Npcs
{
    NPC_CAPTAIN_REZ = 138937,
};

enum ScenarioSteps
{
    STEP_INVESTIGATE            = 3823, // 66693 //relationship 1570 // CriteriaID: 40461 (40461)
    STEP_MINE                   = 3824, // Criteria  40465 Criteria 40467
    STEP_INVESTIGATE_SECOND     = 3825,
    STEP_KILL                   = 3826,
    STEP_INVESTIGATE_THIRD      = 3827,
    STEP_TAKE_FROM_KUNZEN_HOZEN = 3828,
    STEP_ESCAPE                 = 3829,
};

enum ScenarioEvents
{

};

enum Spells
{

};

enum GameObjects
{

};

enum Events
{

};

enum CriteriaTrees
{
    CRITERA_INVESTIGATE            = 66693, // 66693 //relationship 1570 // CriteriaID: 40461 (40461)
    CRITERIA_TREE_MINE             = 66694,
    CRITERA_INVESTIGATE_SECOND     = 66695,
    CRITERA_KILL                   = 66696,
    CRITERA_INVESTIGATE_THIRD      = 66697,
    CRITERA_TAKE_FROM_KUNZEN_HOZEN = 66698,
    CRITERA_ESCAPE                 = 66699,
};

enum SummonGroups
{

};

enum Conversations
{

};

#endif
