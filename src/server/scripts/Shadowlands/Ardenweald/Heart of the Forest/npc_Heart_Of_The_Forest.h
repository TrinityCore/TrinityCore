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
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "NpcObject.h"
#include "NpcObjectAI.h"
#include "SpellAuraEffects.h"


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
  NPC_Gertie_Jr                   = 167661,
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

void OnCreatureCreate(Creature* creature) override
{
        switch (creature->GetEntry())
        {
        case NPC_Aithlyn:
            Aithlyn = creature->GetGUID();
            break;
void CreatureLoot(Creature* loot) override
{
        creatureData            
        }
        case NPC_Anaris_Windwood:
            Anaris Windwood = creature->GetGUID();
            break;
        }
        case NPC_Aralon:
            Aralon = creature->GetGUID();
            break;
        }
        case NPC_Astarii_Starseeker:
            Astarii_Starseeker = creature->GetGUID();
            break;
        }
        case NPC_Attendant_Sparkledew:
            Attendant_Sparkledew = creature->GetGUID();
            break;
        }
        case NPC_Blodwyn:
            Blodwyn = creature->GetGUID();
            break;
        }
        case NPC_Boles:
            Boles = creature->GetGUID();
            break;
        }
        case NPC_Ceridwyn:
            Ceridwyn = creature->GetGUID();
            break;
        }
        case NPC_Cleave_Training_Dummy:
            Cleave_Training_Dummy = creature->GetGUID();
            break;
        }
        case NPC_Craftsmaster_Lamda:
            Craftsmaster_Lamda = creature->GetGUID();
            break;
        }
        case NPC_Curious_Squirrel:
            Curious_Squirrel = creature->GetGUID();
            break;
        }
        case NPC_Denalan:
            Denalan = creature->GetGUID();
            break;
        }    
        case NPC_Dor_levgoren:
            Dor_levgoren = creature->GetGUID();
            break;
        }
        case NPC_Dreamweaver:
            Dreamweaver = creature->GetGUID();
            break;
        }    
        case NPC_Droman_Aliothe:
            Droman_Aliothe = creature->GetGUID();
            break;
        }
        case NPC_Dungeoneers_Tanking_Dummy:
            Dungeoneers_Tanking_Dummy = creature->GetGUID();
            break;
        }
        case NPC_Elwyn:
            Elwyn = creature->GetGUID();
            break;
        }
        case NPC_Fae_Courtier:
            Fae_Courtier = creature->GetGUID();
            break;
        }    
        case NPC_Featherlight:
            Featherlight = creature->GetGUID();
            break;
        }
        case NPC_Ferryn:
            Ferryn = creature->GetGUID();
            break;
        }
        case NPC_Fleeting_Memory:
            Fleeting_Memory = creature->GetGUID();
            break;
        }
        case NPC_Flutterby:
            Flutterby = creature->GetGUID();
            break;
        }
        case NPC_Gertie_Jr:
            Gertie_Jr = creature->GetGUID();
            break;
        }
        case NPC_Gormling:
            Gormling = creature->GetGUID();
            break;
        }
        case NPC_Gravid_Devourer_Mite:
            Gravid_Devourer_Mite = creature->GetGUID();
            break;
        }
        case NPC_Guardian:
            Guardian = creature->GetGUID();
            break;
        }
        case NPC_Huln_Highmountain:
            Huln_Highmountain = creature->GetGUID();
            break;
        }
        case NPC_Hunt_Captain_Korayn:
            Hunt_Captain_Korayn = creature->GetGUID();
            break;
        }    
        case NPC_Ilthalaine:
            Ilthalaine = creature->GetGUID();
            break;
        }
        case NPC_Jandria:
            Jandria = creature->GetGUID();
            break;
        }
        case NPC_Karuth:
            Karuth = creature->GetGUID();
            break;
        }
        case NPC_Kewarin:
            Kewarin = creature->GetGUID();
            break;
        }
        case NPC_Lady_Moonberry:
            Lady_Moonberry = creature->GetGUID();
            break;
        }
        case NPC_Lady_Muunn:
            Lady_Muunn = creature->GetGUID();
            break;
        }
        case NPC_Lafwyn:
            Lafwyn = creature->GetGUID();
            break;
        }
        case NPC_Laurel:
            Laurel = creature->GetGUID();
            break;
        }
        case NPC_Lillyensthoom:
            Lillyensthoom = creature->GetGUID();
            break;
        }
        case NPC_Lord_Herne:
            Lord_Herne - creature->GetGUID();
            break;
        }
        case NPC_MCan:
            MCan = creature->GetGUID();
            break;
        }
        case NPC_Marlan:
            Marlan = creature->GetGUID();
            break;
        }
        case NPC_Niya:
            Niya = creature->GetGUID();
            break;
        }
        case NPC_Ofer:
            NPC_Ofer = creature->GetGUID();
            break;
        }
        case NPC_Rchll:
            Rchll = creature->GetGUID();
            break;
        }
        case NPC_Rahad:
            Rahad = creature->GetGUID();
            break;
        }
        case NPC_Raiders_Tanking_Dummy:
            Raiders_Tanking_Dummy = creature->GetGUID();
            break;
        }
        case NPC_Rescued_Soul:
            Rescued_Soul = creature->GetGUID();
            break;
        }
        case NPC_Samngo:
            Samngo = creature->GetGUID();
            break;
        }
        case NPC_Shandris_Feathermoon:
            Shandris_Feathermoon = creature->GetGUID();
            break;
        }
        case NPC_Sparkle:
            Sparkle = creature->GetGUID();
            break;
        }
        case NPC_Swarm_Training_Dummy:
            Swarm_Training_Dummy = creature->GetGUID();
            break;
        }
        case NPC_Thiernax:
            Thiernax = creature->GetGUID();
            break;
        }
        case NPC_Training_Dummy:
            Training_Dummy = creature->GetGUID();
            break;
        }
        case NPC_Vulpera_Caravan:
            Vulpera_Caravan = creature->GetGUID();
            break;
        }
        case NPC_Wheelbarrow_Racer:
            Wheelbarrow_Racer = creature->GetGUID();
            break;
        }
        case NPC_Yanlar:
            Yanlar = creature->GetGUID();
            break;
        }
        case NPC_Ysera:
            Ysera = creature->GetGUID();
            break;
        }
        case NPC_Zaki:
            Zaki = creature->GetGUID();
            break;
        }
        case NPC_Zayhad_The_Builder:
            Zayhad_The_Builder = creature->GetGUID();
            break;
        }                                                                                                                                                           
};