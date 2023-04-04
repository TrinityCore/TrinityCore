/*
<<<<<<<< HEAD:src/server/scripts/DarkmoonIsland/darkmoon_island_script_loader.cpp
 * Copyright 2021 ShadowCore
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
========
 * Copyright (C) 2022 BfaCore Reforged
>>>>>>>> 00c8b4918beff3f29ba8b4eb8d50c9fd67076687:src/server/scripts/Kalimdor/zone_ungoro_crater.cpp
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

// This is where scripts' loading functions should be declared:
void AddSC_darkmoon_canon();
void AddSC_darkmoon_island();
void AddSC_darkmoon_rabbit();//暗月兔子?
void AddSC_darkmoon_tonk();
void AddSC_darkmoon_whack_gnoll();


// The name of this function should match:
// void Add${NameOfDirectory}Scripts()
void AddDarkmoonIslandScripts()
{
    AddSC_darkmoon_canon();
    AddSC_darkmoon_island();
    AddSC_darkmoon_rabbit();//暗月兔子?
    AddSC_darkmoon_tonk();
    AddSC_darkmoon_whack_gnoll();
}
 //Missing scripts

//void AddSC_ungoro_crater()
//{
//
//}
