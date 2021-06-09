/*
 * Copyright 2021 
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
#include "ScriptMgr.h"
#include "Player.h"
#include "InstanceScript.h"
#include "instance_mists_of_tirna_scithe.cpp"
#include "zone_mists_of_tirna_scithe.cpp"
#include "zone_mists_of_tirna_scithe.h"
#include "Objects_Mist_Of_Tirna_Scithe.h"
#include "npc_Mist_Of_Tirna_Scthithe.h"
#include "Ardenweald.cpp"

std::list<uint64> Boss_Ingra_Maloch /*164567*/;
std::list<uint64> Mistcaller /*170217*/;
std::list<uint64> Tredova /*164517*/;
std::list<uint64> Ancient_Swoop /*151846*/;
std::list<uint64> Cocoon_of_Lakali /*165512*/;
std::list<uint64> Doomguard <Condemned Demon> /*168932*/;
std::list<uint64> Droman_Oulfarran /*164804*/;

 enum Creatures
{
  NPC_Droman_Oulfarran = 170229;
  NPC_Ingra_Maloch     = 164567;
  NPC_Mistcaller       = 170217;
  NPC_Tred_ova         = 164517;
  NPC_Ascient_Swoop    = 151846;
  NPC_Cocoon_of_Lakali = 165512;
  NPC_Doomguard        = 168932;
  NPC_Droman_Oulfarran = 164804;
};
