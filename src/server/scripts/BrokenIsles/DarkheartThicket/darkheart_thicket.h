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

#ifndef DARKHEART_THICKET_H_
#define DARKHEART_THICKET_H_

enum eData
{
    DATA_GLAIDALIS = 0,
    DATA_OAKHEART = 1,
    DATA_DRESARON = 2,
    DATA_XAVIUS = 3,
    MAX_ENCOUNTER,
};

enum eCreatures
{
    //Xavius summons
    NPC_NIGHTMARE_BINDINGS = 101329, //Malfurion cage
    NPC_MALFURION_STORMRAGE = 100652,

    //Pre-event Glaydalis
    NPC_DRUIDIC_PRESERVER = 100403,
    //dresaron
    NPC_DRESARON = 99200,

    //Dresaron summons
    NPC_CORRUPTED_DRAGON_EGG = 101072,
    NPC_HATESPAWN_WHELPLING = 101074,
    //Dresaron achieve npc
    NPC_HATESPAWN_ABOMINATION = 111008,
    NPC_EMERALD_EGG = 541898, //custom id but the same npc
};

enum eGameObjects
{
    GO_GLAIDALIS_FIRE_DOOR = 246910,
    GO_GLAIDALIS_INVIS_DOOR = 246905,
    GO_DRESARON_FIRE_DOOR = 247039,
    GO_OAKHEART_DOOR = 246939,

    //Mythic cache
    GO_XAVIUS_CHALLENGER_CACHE = 252668,
    GO_XAVIUS_SUPERIOR_CHALLENGER_CACHE = 252669,
    GO_XAVIUS_PEERLESS_CHALLENGER_CACHE = 252670,
};

#endif
