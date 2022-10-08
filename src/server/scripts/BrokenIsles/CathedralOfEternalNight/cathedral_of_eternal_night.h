/*
 * Copyright (C) 2017-2019 AshamaneProject <https://github.com/AshamaneProject>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 *  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef DEF_CATHEDRAL_OF_ETERNAL_NIGHT_H
#define DEF_CATHEDRAL_OF_ETERNAL_NIGHT_H
#define DataHeader "CATHEDRAL_OF_ETERNAL_NIGHT"

enum DataTypes
{
    DATA_AGRONOX = 0,
    DATA_THRASHBITE_THE_SCORNFUL = 1,
    DATA_DOMATRAX = 2,
    DATA_MEPHISTROTH = 3,

    DATA_MAX_ENCOUNTERS          = 4
};

enum CreatureIds
{
    NPC_AGRONOX = 117193,
    NPC_THRASHBITE_THE_SCORNFUL = 117194,
    NPC_DOMATRAX = 118804,
    NPC_MEPHISTROTH = 116944,
    NPC_MEPHISTROTH_INTRO = 120793,

};

enum GameObjectIds
{
    GO_BOSS1_DOOR_1 = 269221,
    GO_BOSS1_DOOR_2 = 268710,
    GO_BOSS1_DOOR_3 = 269122,
    GO_BOSS1_DOOR_4 = 269121,
    GO_BOSS1_POST_BOSS_DOOR = 247407,
    GO_PORTCULLIS_001 = 245079,
    GO_PORTCULLIS_002 = 245080,
    GO_PORTCULLIS_003 = 245105,
    GO_KOBOLD_SACKSMALL_001 = 246669,

    GO_BOSS2_DOOR_1 = 247399,
    GO_BOSS2_DOOR_2 = 247401,
    GO_BOSS2_DOOR_3 = 247400,
    GO_BOSS3_POST_BOSS_DOOR = 245104,
    GO_BOSS3_DOOR = 247402,
    GO_BOSS4_DOOR = 247498,
};
#endif
