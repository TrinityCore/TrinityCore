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

#ifndef HALLS_OF_VALOR_H_
#define HALLS_OF_VALOR_H_

enum eData
{
    DATA_HYMDALL = 0,
    DATA_HYRJA = 1,
    DATA_FENRYR = 2,
    DATA_SKOVALD = 3,
    DATA_ODYN = 4,
    MAX_ENCOUNTER,

    DATA_HYRJA_EVENT_COMPLETE,
    DATA_HYRJA_LIGHT_STACK,
    DATA_FENRYR_EVENT,
    DATA_RUNES_ACTIVATED,
    DATA_RUNES_DEACTIVATED,
    DATA_SKOVALD_EVENT,

    DATA_KING_RANULF,
    DATA_KING_HALDOR,
    DATA_KING_BJORN,
    DATA_KING_TOR,

};

enum eCreatures
{
    //Hymdall
    NPC_HYMDALL = 94960,
    NPC_STORM_DRAKE = 97788,
    NPC_STATIC_FIELD = 97795,
    NPC_DANCING_BLADE = 97960,

    //Hyrja
    NPC_HYRJA = 95833,
    NPC_OLMYR_THE_ENLIGHTENED = 97202,
    NPC_SOLSTEN = 97219,

    //Fenryr
    NPC_BOSS_FENRYR = 99868,
    NPC_FENRYR = 95674,

    //Skovald
    NPC_GOD_KING_SKOVALD = 95675,
    NPC_KING_HALDOR = 95843,
    NPC_KING_BJORN = 97081,
    NPC_KING_RANULF = 97083,
    NPC_KING_TOR = 97084,
    NPC_AEGIS_OF_AGGRAMAR = 98364,

    //Odyn
    NPC_ODYN = 95676,
    NPC_SPEAR_OF_LIGHT = 100575,
    NPC_SPOILS_CHEST_VISUAL = 101459,
};

enum eGameObjects
{
    GO_HYMDALL_ENTER_DOOR = 245700,
    GO_HYMDALL_EXIT_DOOR = 245701,
    GO_HYRJA_DOOR = 245702,
    GO_TRACES_OF_FENRIR = 246272,
    GO_GATES_OF_GLORY_DOOR = 244664,
    GO_BRIDGE_OF_GLORY = 246144,
    GO_HYMDALL_CHEST = 258968,
    GO_ODYN_CHEST = 245847,

    GO_ODYN_AND_SKOVALD_DOOR = 246145,

    GO_RUNIC_BRAND_PURE = 245698,
    GO_RUNIC_BRAND_RED = 245697,
    GO_RUNIC_BRAND_YELLOW = 245695,
    GO_RUNIC_BRAND_BLUE = 245696,
    GO_RUNIC_BRAND_GREEN = 245699,
};

Position const spoilsPos = { 2429.50f, 528.97f, 749.08f };
#endif
