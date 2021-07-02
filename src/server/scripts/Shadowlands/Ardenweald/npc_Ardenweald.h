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
#include "AddSC_npc_Data_Ardenweald.h"

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
  NPC_Artisan_Rees = "Artisan Rees"
  NPC_Astarii_Starseeker = "Astarii Starseeker"
  NPC_Astra_As_Azshara = "Astra, As Azshara <An Infamous Queen>"
  NPC_Astra_As_Sylvanas = "Astra, As Sylvanas <A Warchief with Questionable Motives>"
  NPC_Attendant_Sparkledew = "Attendant Sparkledew <Queen's Audience Chamber Staff>"
  NPC_Audience_Member = "Audience Member"
  NPC_Audri_Shadowrose = "Audri Shadowrose <Bloom Tender>"
  NPC_Awool = "Awool"
  NPC_Aynnstykny = "Aynnstykny"
  NPC_Azelor = "Azelor <The Wild Hunt>"
  NPC_Azeroths_Demise = "Azeroth's Demise"
  NPC_Bagoom = "Bagoom"
  NPC_Barrier = "Barrier"
  NPC_Bartender = "Bartender"
  NPC_Basin_Kit = "Basin Kit"
  NPC_Basin_Vulpin = "Basin Vulpin"
  NPC_Baslat = "Baslat"
  NPC_Benyona = "Benyona"
  NPC_Betsy = "Betsy <Silkstrider>"
  NPC_Bitterfly = "Bitterfly"
  NPC_Blackthorn_Ambusher = "Blackthorn Ambusher"
  NPC_Blackthorn_Assailant = "Blackthorn Assailant"
  NPC_Blackthorn_Barbslinger = "Blackthorn Barbslinger"
  NPC_Blackthorn_Bully = "Blackthorn Bully"
  NPC_Blackthorn_Lurker = "Blackthorn Lurker"
  NPC_Blackthorn_Needler = "Blackthorn Needler"
  NPC_Blackthorn_Subjugator = "Blackthorn Subjugator"
  NPC_Blackthorn_Witch_Doctor = "Blackthorn Witch Doctor"
  NPC_Blighted_Beast = "Blighted Beast"
  NPC_Blighted_Brute = "Blighted Brute"
  NPC_Blighted_Carver = "Blighted Carver"
  NPC_Blighted_Conqueror = "Blighted Conqueror"
  NPC_Blighted_Creeper = "Blighted Creeper"
  NPC_Blighted_Darkcaster = "Blighted Darkcaster"
};

 enum Creatures
{
  NPC_Oranomonos_the_Everbranching                    = 167527,
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
  NPC_Aralon                                          = 160963,161378,161492,169935,170290,170485,170705,161603,162979,165250,169649,170463,170522,171641,172133, 
  NPC_Archivist_Dreyden                               = 165867,
  NPC_Ardenmoth                                       = 174201,174248,
  NPC_Ardent_Pacifier                                 = 172493,
  NPC_Arkelios                                        = 173939,
  NPC_Artisan_Rees                                    = 167047,
  NPC_Astarii_Starseeker                              = 174515,
  NPC_Astra_As_Azshara                                = 161161,166135,
  NPC_Astra_As_Sylvanas                               = 161159,
  NPC_Attendant_Sparkledew                            = 158543,
  NPC_Audience_Member                                 = 160508,170081,170117,170119,170120,
  NPC_Audri_Shadowrose                                = 160534,
  NPC_Awool                                           = 159644,159661,160813,161022,167981,169319,
  NPC_Aynnstykny                                      = 174776,
  NPC_Azelor                                          = 170959,
  NPC_Azeroths_Demise                                 = 161802,
  NPC_Bagoom                                          = 174131,
  NPC_Barrier                                         = 166222,
  NPC_Bartender                                       = 175535,
  NPC_Basin_Kit                                       = 169388,
  NPC_Basin_Vulpin                                    = 163093,
  NPC_Baslat                                          = 176334,
  NPC_Benyona                                         = 174838,
  NPC_Betsy                                           = 168090,
  NPC_Bitterfly                                       = 160442,
  NPC_Blackthorn_Ambusher                             = 170263,170286,
  NPC_Blackthorn_Assailant                            = 174692,
  NPC_Blackthorn_Barbslinger                          = 167049,169338,
  NPC_Blackthorn_Bully                                = 169297,
  NPC_Blackthorn_Lurker                               = 170873,
  NPC_Blackthorn_Needler                              = 167050,169339,
  NPC_Blackthorn_Subjugator                           = 170872,
  NPC_Blackthorn_Witch_Doctor                         = 167088,169340,
  NPC_Blighted_Beast                                  = 170087,
  NPC_Blighted_Brute                                  = 169630,169630,176176,
  NPC_Blighted_Carver                                 = 172193,
  NPC_Blighted_Conqueror                              = 174729,
  NPC_Blighted_Creeper                                = 169629,176179,
  NPC_Blighted_Darkcaster                             = 169631, 
};

enum AuraScript
{
  void aura();
};
 
enum SpellScript
{
  void Spell();
};

enum EffectScript
{
  void Effect();
};

enum ModeScript
{
  void Mode();
};

enum SpawnScript
{
  void Spawn();
};

enum NpcLootScript
{
  void NpcLoot();
};

enum NpcDataScript
{
  void NpcData();
};

enum QuestDataScript
{
  void QuestData();
};

enum QuestRewardsScript
{
  void QuestRewards();
};

enum FishingScripts
{
  void Fishing();
};

enum StartsQuestScript
{
  void StartsQuest();
};

enum QuestScript
{
  void Quest();
}; 

void AddSC_npc_Ardenweald() 
{
  RegisterCreatureAI(NPC_Oranomonos the Everbranching);                  
  RegisterCreatureAI(NPC_Granny);                                          
  RegisterCreatureAI(NPC_A_Naughty_Story);                                
  RegisterCreatureAI(NPC_Amun);                                          
  RegisterCreatureAI(NPC_Abandoned_Whelp);                                
  RegisterCreatureAI(NPC_Adopted_Son);                                    
  RegisterCreatureAI(NPC_Aerto);                                          
  RegisterCreatureAI(NPC_Agitated_Mistfeather);                           
  RegisterCreatureAI(NPC_Aithlyn);                                         
  RegisterCreatureAI(NPC_Alascene);                                       
  RegisterCreatureAI(NPC_Aldas);                                           
  RegisterCreatureAI(NPC_Alderyn);                                       
  RegisterCreatureAI(NPC_Alice);                                           
  RegisterCreatureAI(NPC_Amberfoot);                                      
  RegisterCreatureAI(NPC_Ammi);                                            
  RegisterCreatureAI(NPC_Amphitheater_Musician);                           
  RegisterCreatureAI(NPC_Anaris_Windwood);                                 
  RegisterCreatureAI(NPC_Anaya_Dawnrunner);                                
  RegisterCreatureAI(NPC_Ancient_Gazelle);                                 
  RegisterCreatureAI(NPC_Angelia);                                        
  RegisterCreatureAI(NPC_Angry_Egg_Tender);                                
  RegisterCreatureAI(NPC_Angwyrdmn);                                       
  RegisterCreatureAI(NPC_Anima_Starved_Matriarch);                         
  RegisterCreatureAI(NPC_Anima_Starved_Patriarch);                         
  RegisterCreatureAI(NPC_Anima_Starved_Shrieker);                          
  RegisterCreatureAI(NPC_Anima_Starved_Stalker); 
  RegisterCreatureAI(NPC_Anir);                           
  RegisterCreatureAI(NPC_Aralon);
  RegisterCreatureAI(NPC_Archivist Dreyden);
  RegisterCreatureAI(NPC_Ardenmoth);
  RegisterCreatureAI(NPC_Ardent_Pacifier);
  RegisterCreatureAI(NPC_Arkelios);
  RegisterCreatureAI(NPC_Artisan_Rees);
  RegisterCreatureAI(NPC_Astarii_Starseeker);
  RegisterCreatureAI(NPC_Astra_As_Azshara);
  RegisterCreatureAI(NPC_Astra_As_Sylvanas);
  RegisterCreatureAI(NPC_Attendant_Sparkledew);
  RegisterCreatureAI(NPC_Audience_Member);
  RegisterCreatureAI(NPC_Audri_Shadowrose);
  RegisterCreatureAI(NPC_Awool);
  RegisterCreatureAI(NPC_Aynnstykny);
  RegisterCreatureAI(NPC_Azelor);
  RegisterCreatureAI(NPC_Azeroths_Demise);
  RegisterCreatureAI(NPC_Bagoom);
  RegisterCreatureAI(NPC_Barrier);
  RegisterCreatureAI(NPC_Bartender);
  RegisterCreatureAI(NPC_Basin_Kit);
  RegisterCreatureAI(NPC_Basin_Vulpin);
  RegisterCreatureAI(NPC_Baslat);
  RegisterCreatureAI(NPC_Benyona);
  RegisterCreatureAI(NPC_Betsy);
  RegisterCreatureAI(NPC_Bitterfly);
  RegisterCreatureAI(NPC_Blackthorn_Ambusher);
  RegisterCreatureAI(NPC_Blackthorn_Assailant);
  RegisterCreatureAI(NPC_Blackthorn_Barbslinger);
  RegisterCreatureAI(NPC_Blackthorn_Bully);
  RegisterCreatureAI(NPC_Blackthorn_Lurker);
  RegisterCreatureAI(NPC_Blackthorn_Needler);
  RegisterCreatureAI(NPC_Blackthorn_Subjugator);
  RegisterCreatureAI(NPC_Blackthorn_Witch_Doctor);
  RegisterCreatureAI(NPC_Blighted_Beast);
  RegisterCreatureAI(NPC_Blighted_Brute);
  RegisterCreatureAI(NPC_Blighted_Carver);
  RegisterCreatureAI(NPC_Blighted_Conqueror);
  RegisterCreatureAI(NPC_Blighted_Creeper);
  RegisterCreatureAI(NPC_Blighted_Darkcaster); 
};

void AddSC_npc_Data_Ardenweald()
{
  RegisterAuraScript(aura);
  RegisterSpellScript(spell);
  RegisterEffectScript(efect);
  RegisterModeScript(mode);
  RegisterSpawnScript(Spawn);
  RegisterNpcLootScript(NpcLoot);
  RegisterNpcDataScript(NpcData);
  RegisterQuestDataScript(QuestData);
  RegisterQuestRewardsScript(QuestRewards);
  RegisterFishingScripts(Fishing);
  RegisterQuestScript(Quest);
  RegisterStartsQuestScript(StartsQuest);
  RegisterFishingScripts(Fishing);
};