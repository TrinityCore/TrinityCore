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
#include "instance_de_other_side.cpp"
#include "zone_De_Other_Side.cpp"
#include "zone_De_Other_Side.h"
#include "npc_De_Other_Side.h"
#include "Objects_De_Other_Side.h"
#include "De_Other_Side.h"
#include "boss_dealer_xyexa.cpp"
#include "boss_hakkar_the_soulflayer_os.cpp"
#include "boss_muehzala.cpp"
#include "boss_the_manastorms.cpp"
#include "Heart_Of_The_Forest.cpp"
#include "zone_Heart_Of_The_Forest.cpp"
#include "zone_Heart_Of_The_Forest.h"
#include "npc_Heart_Of_The_Forest.h"
#include "Objects_Heart_Of_The_Forest.h"
#include "instance_mists_of_tirna_scithe.cpp"
#include "zone_mists_of_tirna_scithe.cpp"
#include "zone_mists_of_tirna_scithe.h"
#include "Objects_Mist_Of_Tirna_Scithe.h"
#include "npc_Mist_Of_Tirna_Scthithe.h"
#include "Boss_Ingra _Maloch.cpp"
#include "Boss_Mistcaller.cpp"
#include "Boss_Tred_ova.cpp"
#include "Ardenweald.cpp"
#include "zone_Ardenweald.cpp"
#include "zone_Ardenweald.h" 
#include "Objects_Ardenweald.h"


enum NPC
{
  NPC_Oranomonos the Everbranching = "Oranomonos the Everbranching"                  
  NPC_Granny = ""Granny""                                         
  NPC_A_Naughty_Story = "A Naughty Story"                                
  NPC_Amun = "A'mun"                                           
  NPC_Abandoned_Whelp = "Abandoned Whelp"                                
  NPC_Adopted_Son = "Adopted Son"                                    
  NPC_Aerto = "Aerto <Grove Ranger>"                                          
  NPC_Agitated_Mistfeather = "Agitated Mistfeather"                           
  NPC_Aithlyn = "Aithlyn <Wild Hunt Quartermaster>"                                        
  NPC_Alascene = "Alascene"                                       
  NPC_Aldas = "Aldas <General Goods>"                                          
  NPC_Alderyn = "Alderyn <The Wild Hunt>"                                      
  NPC_Alice = "Alice"                                          
  NPC_Amberfoot = "Amberfoot"                                      
  NPC_Ammi = "Ammi"                                           
  NPC_Amphitheater_Musician = "Amphitheater Musician"                          
  NPC_Anaris_Windwood = "Anaris Windwood"                                
  NPC_Anaya_Dawnrunner = "Anaya Dawnrunner"                               
  NPC_Ancient_Gazelle = "Ancient Gazelle"                                
  NPC_Angelia = "Angelia <Food & Drink>"                                        
  NPC_Angry_Egg_Tender = "Angry Egg Tender"                               
  NPC_Angwyrdmn = "Angwyrdmn <Innkeeper>"                                      
  NPC_Anima_Starved_Matriarch = "Anima Starved Matriarch"                        
  NPC_Anima_Starved_Patriarch = "Anima Starved Patriarch"                        
  NPC_Anima_Starved_Shrieker = "Anima Starved Shrieker"                         
  NPC_Anima_Starved_Stalker = "Anima Starved Stalker"
  NPC_Anir = "Anir <Trade Goods & Repairs>"                           
  NPC_Aralon = "Ara'lon <The Wild Hunt>"
  NPC_Archivist Dreyden = "Archivist Dreyden"
  NPC_Ardenmoth = "Ardenmoth"
  NPC_Ardent_Pacifier = "Ardent Pacifier"
  NPC_Arkelios = "Arkelios <Wandering Spirit>"
  NPC_
  NPC_
  NPC_
}

 enum Creatures
{
  NPC_Oranomonos the Everbranching                    = 167527,
  NPC_Granny                                          = 169331,
  NPC_A_Naughty_Story                                 = 174726,
  NPC_Amun                                            = 175337,
  NPC_Abandoned_Whelp                                 = 161788,
  NPC_Adopted_Son                                     = 165519,
  NPC_Aerto                                           = 171156,
  NPC_Agitated_Mistfeather                            = 167439,
  NPC_Aithlyn                                         = 158556,
  NPC_Alascene                                        = 166328,
  NPC_Aldas                                           = 170549,
  NPC_Alderyn                                         = 173402,
  NPC_Alice                                           = 173653,
  NPC_Amberfoot                                       = 170928,
  NPC_Ammi                                            = 167048,
  NPC_Amphitheater_Musician                           = 175598,
  NPC_Anaris_Windwood                                 = 174532,
  NPC_Anaya_Dawnrunner                                = 174477,
  NPC_Ancient_Gazelle                                 = 151847,
  NPC_Angelia                                         = 170552,
  NPC_Angry_Egg_Tender                                = 171827,
  NPC_Angwyrdmn                                       = 171162,
  NPC_Anima_Starved_Matriarch                         = 169052,
  NPC_Anima_Starved_Patriarch                         = 169051,
  NPC_Anima_Starved_Shrieker                          = 169050,
  NPC_Anima_Starved_Stalker                           = 169049,169228,
  NPC_Anir                                            = 158494,169152,
  NPC_Aralon                                          = 160963,161378,161492,169935,170290,170485,170705,
                                                        161603,162979,165250,169649,170463,170522,171641,172133, 
  NPC_Archivist_Dreyden                               = 165867,
  NPC_Ardenmoth                                       = 174201,174248,
  NPC_Ardent_Pacifier                                 = 172493,
  NPC_Arkelios                                        = 173939,
};
