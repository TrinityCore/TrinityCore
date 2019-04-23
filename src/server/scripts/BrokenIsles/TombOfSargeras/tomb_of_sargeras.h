/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
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

#ifndef TOMB_OF_SARGERAS_H
#define TOMB_OF_SARGERAS_H

enum DataTypes
{
    DATA_GOROTH                 = 0,
    DATA_DEMONIC_INQUISITION    = 1,
    DATA_HARJATAN               = 2,
    DATA_SISTERS_OF_THE_MOON    = 3,
    DATA_SASSZINE               = 4,
    DATA_DESOLATE_HOST          = 5,
    DATA_MAIDEN_OF_VIGILANCE    = 6,
    DATA_FALLEN_AVATAR          = 7,
    DATA_KILJAEDEN              = 8,

    DATA_MAX_ENCOUNTERS
};

enum Creatures
{
    NPC_GOROTH                      = 115844,
    NPC_ATRIGAN                     = 120996,

    // Demonic Inquisition
    NPC_BELAC                       = 116691,
    NPC_HARJATAN                    = 116407,

    // Sisters of the Moon
    NPC_HUNTRESS_KASPARIAN          = 118523,
    NPC_CAPTAIN_YATHAE_MOONSTRIKE   = 118374,
    NPC_PRIESTESS_LUNASPYRE         = 118518,

    NPC_SASSZINE                    = 115767,

    // Desolate Host
    NPC_ENGINE_OF_SOULS             = 118460,
    NPC_SOUL_QUEEN_DEJAHNA          = 118462,
    NPC_DESOLATE_HOST               = 119072,

    NPC_MAIDEN_OF_VIGILANCE         = 118289,
    NPC_FALLEN_AVATAR               = 120436,
    NPC_KILJAEDEN                   = 117269,
};

enum CosmeticSpells
{
    SPELL_COSMETIC_TELEPORT         = 240923,   // Used by Kil'jaeden after Fallen Avatar activation
    SPELL_AWAKEN                    = 240897,   // Kil'jaeden activate Fallen Avatar spell.
    SPELL_FEL_INFUSION              = 236682,   // Used by Maiden of Valor.
};

enum Gameobjects
{
    GO_MOON_CHAMBER_WINDOW          = 269842,
    GO_MOON_CHAMBER_MISSILE         = 269839,
    GO_MOON_CHAMBER_HOLE            = 269838,

    GO_DOOR_ROOM_GOROTH_S           = 269974,
    GO_DOOR_ROOM_GOROTH_N           = 269975,
    GO_DOOR_ROOM_GOROTH_E           = 269973,
};

#endif // TOMB_OF_SARGERAS_H
