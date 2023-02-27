//#include "ScriptMgr.h"
//#include "Player.h"
//#include "Creature.h"
//#include "CreatureAI.h"
//#include "GameObject.h"
//#include "GameObjectAI.h"
//#include "AreaTrigger.h"
//#include "AreaTriggerAI.h"
//#include "SpellAuraEffects.h"
//#include "Map.h"
//#include "InstanceScript.h"
//#include "Transport.h"
//#include "TransportMgr.h"
//#include "AreaTrigger.h"
//#include "AreaTriggerAI.h"
//#include "zone_the_maw.cpp"
//#include "objects_Sanctum_of_Domination.h"
//#include "npc_Sanctum_of_Domination.h"
//#include "Sanctum_of_Domination.h"
//#include "zone_Sanctum_of_Domination.cpp"
//#include "zone_Sanctum_of_Domination.h"
//#include "instance_Sanctum_of_Domination.cpp"
//
//enum Creatures
//{
//	NPC_THE_TARRAGRUE                                          = 152253,
//  NPC_INFUSED_GOLIATH                                        = 176535,176537,176538,176539,
//};
//
//enum Spells
//{
//  Spell_Frostbite Wand                                             = 315293,
//  Spell_Shattered Psyche                                           = 344663,
//  Spell_The Jailers Directive                                      = 329628,
//  Spell_The Jailers Fury                                           = 329338,
//  Spell_The Jailers Vigil                                          = 345312,
//  Spell_Unnatural Power                                            = 299150,
//}
//
//enum achievements
//{
//  Name A Better Duo, Ill Wait                                      = 14998,
//}
//
//enum Raid_mode
//{
//	mode_LFR;
//	mode_N;
//	mode_HC;
//	mode_Mythic;
//}
//                                                               
//enum Loot_mode                                                 
//{                                                              
//  void The_Tarragrue()
//  void Infused_Goliath()                                 
//  mode_LFR()                                                   
//  {                                                            
//   	item_Carnivorous Stalkers                                       = 182750,
//    item_Ferocious Appetite                                         = 182610,
//    item_Fleeting Wind                                              = 182113,
//    item_Fueled by Violence                                         = 180932,
//    item_Incessant Hunter                                           = 183481,
//    item_Inner Fury                                                 = 181376,
//    item_Lost in Darkness                                           = 182344,
//    item_Natures Focus                                              = 182144,
//    item_Rabid Shadows                                              = 182139,
//    item_Well_Placed Steel                                          = 183504,
//    item_Wrench Evil                                                = 182456,
//    item_Cavalier Oathbreakers Grasps                               = 186311,
//    item_Champions Gruesome Greaves                                 = 186318,
//    item_Clasps of the Unfortunate Troubadour                       = 186297,
//    item_Colossus Slayers Hauberk                                   = 186303,
//    item_Elethium-Bladed Glaive                                     = 186381,
//    item_Mistwrap Manacles                                          = 186302,
//    item_Moriazs Spare Targe                                        = 186415,
//    item_Periapt of Pristine Preservation                           = 186291,
//    item_Phantasma-Forged Striders                                  = 186281,
//    item_Smugglers Plundered Pauldrons                              = 186298,
//    item_Sorcerers Headlong Legwraps                                = 186285,
//    item_Tome of Monstrous Constructions                            = 186422,
//  };                                                           
//  mode_N()                                                     
//  {                                                          
//    item_Carnivorous Stalkers                                       = 182750,
//    item_Ferocious Appetite                                         = 182610,
//    item_Fleeting Wind                                              = 182113,
//    item_Fueled by Violence                                         = 180932,
//    item_Incessant Hunter                                           = 183481,
//    item_Inner Fury                                                 = 181376,
//    item_Lost in Darkness                                           = 182344,
//    item_Natures Focus                                              = 182144,
//    item_Rabid Shadows                                              = 182139,
//    item_Well_Placed Steel                                          = 183504,
//    item_Wrench Evil                                                = 182456,
//    item_Cavalier Oathbreakers Grasps                               = 186311,
//    item_Champions Gruesome Greaves                                 = 186318,
//    item_Clasps of the Unfortunate Troubadour                       = 186297,
//    item_Colossus Slayers Hauberk                                   = 186303,
//    item_Elethium-Bladed Glaive                                     = 186381,
//    item_Mistwrap Manacles                                          = 186302,
//    item_Moriazs Spare Targe                                        = 186415,
//    item_Periapt of Pristine Preservation                           = 186291,
//    item_Phantasma-Forged Striders                                  = 186281,
//    item_Smugglers Plundered Pauldrons                              = 186298,
//    item_Sorcerers Headlong Legwraps                                = 186285,
//    item_Tome of Monstrous Constructions                            = 186422,
//  };
//  mode_HC()
//  {                                                          
//    item_Carnivorous Stalkers                                       = 182750,
//    item_Ferocious Appetite                                         = 182610,
//    item_Fleeting Wind                                              = 182113,
//    item_Fueled by Violence                                         = 180932,
//    item_Incessant Hunter                                           = 183481,
//    item_Inner Fury                                                 = 181376,
//    item_Lost in Darkness                                           = 182344,
//    item_Natures Focus                                              = 182144,
//    item_Rabid Shadows                                              = 182139,
//    item_Well_Placed Steel                                          = 183504,
//    item_Wrench Evil                                                = 182456,
//    item_Cavalier Oathbreakers Grasps                               = 186311,
//    item_Champions Gruesome Greaves                                 = 186318,
//    item_Clasps of the Unfortunate Troubadour                       = 186297,
//    item_Colossus Slayers Hauberk                                   = 186303,
//    item_Elethium-Bladed Glaive                                     = 186381,
//    item_Mistwrap Manacles                                          = 186302,
//    item_Moriazs Spare Targe                                        = 186415,
//    item_Periapt of Pristine Preservation                           = 186291,
//    item_Phantasma-Forged Striders                                  = 186281,
//    item_Smugglers Plundered Pauldrons                              = 186298,
//    item_Sorcerers Headlong Legwraps                                = 186285,
//    item_Tome of Monstrous Constructions                            = 186422,
//  };
//  mode_Mythic()
//  {
//    item_Carnivorous Stalkers                                       = 182750,
//    item_Ferocious Appetite                                         = 182610,
//    item_Fleeting Wind                                              = 182113,
//    item_Fueled by Violence                                         = 180932,
//    item_Incessant Hunter                                           = 183481,
//    item_Inner Fury                                                 = 181376,
//    item_Lost in Darkness                                           = 182344,
//    item_Natures Focus                                              = 182144,
//    item_Rabid Shadows                                              = 182139,
//    item_Well_Placed Steel                                          = 183504,
//    item_Wrench Evil                                                = 182456,
//    item_Cavalier Oathbreakers Grasps                               = 186311,
//    item_Champions Gruesome Greaves                                 = 186318,
//    item_Clasps of the Unfortunate Troubadour                       = 186297,
//    item_Colossus Slayers Hauberk                                   = 186303,
//    item_Elethium-Bladed Glaive                                     = 186381,
//    item_Mistwrap Manacles                                          = 186302,
//    item_Moriazs Spare Targe                                        = 186415,
//    item_Periapt of Pristine Preservation                           = 186291,
//    item_Phantasma-Forged Striders                                  = 186281,
//    item_Smugglers Plundered Pauldrons                              = 186298,
//    item_Sorcerers Headlong Legwraps                                = 186285,
//    item_Tome of Monstrous Constructions                            = 186422,
//  };
//};
//
//	
