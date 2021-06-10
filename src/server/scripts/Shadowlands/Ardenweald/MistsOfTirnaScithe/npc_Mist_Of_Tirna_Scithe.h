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
#include "Boss_Ingra _Maloch.cpp"
#include "Boss_Mistcaller.cpp"
#include "Boss_Tred_ova.cpp"

 enum Creatures
{
  NPC_Droman_Oulfarran             = 170229;
  NPC_Ingra_Maloch                 = 164567;
  NPC_Mistcaller                   = 170217;164501;166885;
  NPC_Tred_ova                     = 164517;
  NPC_Ancient_Swoop                = 151846;
  NPC_Cocoon_of_Lakali             = 165512;
  NPC_Doomguard                    = 168932;
  NPC_Droman_Oulfarran             = 164804;170218;170229;
  NPC_Drust_Boughbreaker           = 164926;
  NPC_Drust_Harvester              = 164921;
  NPC_Drust_Soulcleaver            = 164920;172991;
  NPC_Drust_Spiteclaw              = 165111;
  NPC_Ethereal_Transmorpher        = 149596;
  NPC_Felguard                     = 169421;
  NPC_Felhound                     = 169425;
  NPC_Fleeting_Memory              = 175581;
  MPC_Generic_Hunter_Pet           = 165189;
  NPC_Gormling_Larva               = 165560;
  NPC_Greater_Earth_Elemental      = 95072;
  NPC_Hydra_Seed                   = 172995;
  NPC_Illusionary_Clone            = 165108;
  NPC_Illusionary Vulpin           = 165251;
  NPC_Infernal                     = 169426;
  NPC_Manifestation_of_Pride       = 173729;
  NPC_Merchant_Maku                = 142668;
  NPC_Mistveil_Defender            = 163058;171772;
  NPC_Mistveil_Gorgegullet         = 173720;
  NPC_Mistveil_Guardian            = 166276;
  NPC_Mistveil_Matriarch           = 173655;
  NPC_Mistveil_Nightblossom        = 173714;
  NPC_Mistveil_Shaper              = 166275;
  NPC_Mistveil_Stalker             = 166301;
  NPC_Mistveil_Stinger             = 166304;
  NPC_Mistveil_Tender              = 166299;
  NPC_Nathrian_Inquisitor          = 175513;
  NPC_Overgrown_Hydra              = 172992;
  NPC_Overgrowth                   = 168988;
  NPC_Parasitic_Infestor           = 172647;
  NPC_Savory_Statshroom            = 173680;
  NPC_Shadowlands_Wormhole         = 169501;
  NPC_Shivarra                     = 169429;
  NPC_Spinemaw_Acidgullet          = 167113;
  NPC_Spinemaw_Gorger              = 172312;
  NPC_Spinemaw_Larva               = 167117;
  NPC_Spinemaw_Reaver              = 167116;
  NPC_Spinemaw_Staghorn            = 167111;
  NPC_Spiteful_Shade               = 174773;
  NPC_Tasty_Toughshroom            = 173679;
  NPC_Tirnenn_Sapling              = 167707;
  NPC_Tirnenn_Villager             = 164929;165120;
  NPC_Turnip_Punching_Bag          = 65310;
  NPC_Urzul                        = 169430;
  NPC_Wrathguard                   = 169428;
  NPC_Xolartios                    = 158635;
};

