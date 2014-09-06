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

#ifndef DEF_GNOMEREGAN_H
#define DEF_GNOMEREGAN_H

#define DataHeader "GNO"

enum GameObjectIds
{
    GO_CAVE_IN_LEFT     = 146085,
    GO_CAVE_IN_RIGHT    = 146086,
    GO_RED_ROCKET       = 103820
};

enum CreatureIds
{
    NPC_BLASTMASTER_EMI_SHORTFUSE   = 7998,
    NPC_CAVERNDEEP_AMBUSHER         = 6207,
    NPC_GRUBBIS                     = 7361,
    NPC_CHOMPER                     = 6215
};

enum Data
{
    TYPE_EVENT = 1
};

enum Data64
{
    DATA_GO_CAVE_IN_LEFT,
    DATA_GO_CAVE_IN_RIGHT,
    DATA_NPC_BASTMASTER_EMI_SHORTFUSE
};

#endif
