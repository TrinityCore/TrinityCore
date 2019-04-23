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

#ifndef DEF_SHADOWFANG_H
#define DEF_SHADOWFANG_H

enum ShadowfangKeepBoss
{
   BOSS_BARON_ASHBURY             = 46962,
   BOSS_BARON_SILVERLAINE         =  3887,
   BOSS_COMMANDER_SPRINGVALE      =  4278,
   BOSS_LORD_GODFREY              = 46964,
   BOSS_LORD_WALDEN               = 46963,
};

enum Npcs
{
   NPC_TORMENTED_OFFICER          = 50615,
   NPC_WAILING_GUARDSMAN          = 50613,
   NPC_DREAD_SCRYER               = 47141,
   NPC_DESECRATION_TR             = 50503,
   NPC_TOXIN_TRIGGER              = 50439
//   NPC_HORDE_QUESTGIVER
//   NPC_ALLIANCE_QUESTGIVER
};

enum Achievements
{
   ACHIEVEMENT_TO_THE_GROUND      = 5504,
};

enum GameObjectIds
{
   GO_BARON_ASHBURY_DOOR          = 18895,
   GO_LORD_GODFREY_DOOR           = 18971,
   GO_LORD_WALDEN_DOOR            = 18972
};

enum Data
{
    DATA_BARON_ASHBURY_EVENT,
    DATA_BARON_SILVERLAINE_EVENT,
    DATA_COMMANDER_SPRINGVALE_EVENT,
    DATA_LORD_GODFREY_EVENT,
    DATA_LORD_WALDEN_EVENT,
    MAX_ENCOUNTER,

    TEAM_IN_INSTANCE
};

enum Data64
{
    DATA_BARON_ASHBURY,
    DATA_BARON_SILVERLAINE,
    DATA_COMMANDER_SPRINGVALE,
    DATA_LORD_GODFREY,
    DATA_LORD_WALDEN
};

#endif
