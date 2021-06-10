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
#include "instance_Heart_Of_The_Forest.cpp"
#include "zone_Heart_Of_The_Forest.h"
#include "Objects_Heart_Of_The_Forest.h"
#include "npc_Heart_Of_The_Forest.h"

 enum Creatures
{
  NPC_Aithlyn                     = 158556,
  NPC_Anaris_Windwood             = 174532,
  NPC_Aralon                      = 162979,
  NPC_Astarii_Starseeker          = 174515,
  NPC_Attendant_Sparkledew        = 158543,
  NPC_Blodwyn                     = 167195,
  NPC_Boles                       = 174611,
  NPC_Ceridwyn                    = 165701,
  NPC_Cleave_Training_Dummy       = 174571,
  NPC_Craftsmaster_Lamda          = 175419,
  NPC_Curious_Squirrel            = 93997,
  NPC_Denalan                     = 174517,
  NPC_Dor_levgoren                = 173682,
  NPC_Dreamweaver                 = 160482,162976,
  NPC_Droman_Aliothe              = 162973,
  NPC_Dungeoneers_Tanking_Dummy   = 174566,174568,
  NPC_Elwyn                       = 174914,
  NPC_Fae_Courtier                = 168100,168116,
  NPC_Featherlight                = 167193,
  NPC_Ferryn                      = 174522,174548,174549,
  NPC_Fleeting_Memory             = 175581,
  NPC_Flutterby                   = 158553,
  NPC_Gertie Jr                   = 167661,
  NPC_Gormling                    = 175665,
  NPC_Gravid_Devourer_Mite        = 175692,
  NPC_Guardian                    = 158547,165751,
  NPC_Huln_Highmountain           = 161352,
  NPC_Hunt_Captain_Korayn         = 165659,162980,
  NPC_Ilthalaine                  = 174518,
  NPC_Jandria                     = 174516,
  NPC_Karuth                      = 174614,
  NPC_Kewarin                     = 160292,
  NPC_Lady_Moonberry              = 161509,
  NPC_Lady_Muunn                  = 174209,
  NPC_Lafwyn                      = 158554,
  NPC_Laurel                      = 176096,
  NPC_Lillyensthoom               = 174572,
  NPC_Lord_Herne                  = 158544,
  NPC_MCan                        = 174613,
  NPC_Marlan                      = 175418,
  NPC_Niya                        = 172677,160481,162978,
  NPC_Ofer                        = 174775,
  NPC_Rchll                       = 174610,
  NPC_Rahad                       = 174774,
  NPC_Raiders_Tanking_Dummy       = 174565,174567,
  NPC_Rescued_Soul                = 174579,
  NPC_Samngo                      = 173681,
  NPC_Shandris_Feathermoon        = 161900,
  NPC_Sparkle                     = 174608,
  NPC_Swarm_Training_Dummy        = 174570,
  NPC_Thiernax                    = 161336,
  NPC_Training_Dummy              = 174569,
  NPC_Vulpera_Caravan             = 162008,
  NPC_Wheelbarrow_Racer           = 175145,
  NPC_Yanlar                      = 167206,
  NPC_Ysera                       = 160262,171138,160501,163116,
  NPC_Zaki                        = 174609,
  NPC_Zayhad_The_Builder          = 165702,
};
