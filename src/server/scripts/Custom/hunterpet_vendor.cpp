// -- BeastmasterNPC by LORDofDOOM 
// -- Modified from old scripting and tweaked
// -- Thanks to MCWoW (FreeCry) for 3.3 Script

#include "ScriptPCH.h"
 
enum Creatures
{
        //CREATURE_FELSHETZER                                   = 19350,
        CREATURE_FLEDERMAUS                                     = 3866,
        CREATURE_NETHERROCHEN                           = 18131,
        CREATURE_RAUBVOGELROT                           = 21804,
        CREATURE_RAUBVOGELSCHWARZ                       = 25817,
        CREATURE_RAUBVOGELWEISS                         = 26369,
        //CREATURE_SCHLANGE                                     = 5224,
        CREATURE_SPINNE                                         = 20714,
        CREATURE_GORILLASCHWARZ                         = 2521,
        CREATURE_GORILLAWEISS                           = 6516,
        CREATURE_KREBS                                          = 23929,
        //CREATURE_KROKOLISK                            = 20773,
        //CREATURE_AASVOGEL                                     = 16972,
        CREATURE_HYAENE                                         = 27294,
        CREATURE_KATZETIGER                                     = 7434,
        CREATURE_KATZELOEWE                                     = 28097,
        //CREATURE_KATZELUCHS                                   = 24043,
        CREATURE_RAPTORGRUEN                                    = 21124,
        CREATURE_RAPTORROT                                      = 4352,
        CREATURE_WEITSCHREITER                          = 3246,
        CREATURE_WESPEROT                                       = 18283,
        CREATURE_WESPEBLAU                                      = 28086,
        CREATURE_WOLFRUESTUNG                           = 17280,
        //CREATURE_WOLFGRAU                                     = 24128,
        //CREATURE_WOLFWEI?                                     = 26672,
       
        CREATURE_SCHIMAERE                                      = 20932,
        CREATURE_SILITHIDGELB                           = 15230,
        CREATURE_SILITHIDROT                            = 5460,
        CREATURE_RHINOZEROS                                     = 25488,
        //CREATURE_WURMBRAUN                                    = 34920,
        CREATURE_WURMGELB                                       = 14237,
        CREATURE_KERNHUNDWEISS                          = 17447,
        CREATURE_KERNHUNDROT                            = 11671,
        CREATURE_TEUFELSSAURIERWEISS            = 6498,
        CREATURE_TEUFELSSAURIERSCHWARZ          = 20931,
        CREATURE_SKOLL                                          = 35189,
        CREATURE_LOQUE                                          = 32517,
        CREATURE_GONDRIA                                        = 33776,
        CREATURE_ARCTURIS                                       = 38453,
};
 
#define main    100
#define pets    200
#define exotic  300
// Pets
#define felshetzer 201
#define fledermaus 202
#define netherrochen 203
#define raubvogelrot 204
#define raubvogelschwarz 205
#define raubvogelweiss 206
#define schlange 207
#define spinne 208
#define gorillaschwarz 209
#define gorillaweiss 210
#define krebs 211
#define krokolisk 212
#define aasvogel 213
#define hyaene 214
#define katzetiger 215
#define katzeloewe 216
#define katzeluchs 217
#define raptorgruen 218
#define raptorrot 219  
#define weitschreiter 220
#define wesperot 221
#define wespeblau 222
#define wolfruestung 223
#define wolfgrau 224
#define wolfweiss 225
// Exotic
#define schimaere 326
#define silithidgelb 327
#define silithidrot 328
#define rhinozeros 329
#define wurmbraun 330
#define wurmgelb 331
#define kernhundweiss 332
#define kernhundrot 333
#define teufelssaurierweiss 334
#define teufelssaurierschwarz 335
#define skoll 336
#define loque 337
#define gondria 338
#define arcturis 339 
 
 
 //Preise
#define PRICE_PET_TYP_1    250000
#define PRICE_PET_TYP_2    5000000
#define MSG_NOT_MONEY "You have not enough gold!"
#define MSG_PET_SUMMON "The creature will be summoned"
 
class npc_hunterpetvendor : public CreatureScript
{
public:
        npc_hunterpetvendor() : CreatureScript("npc_hunterpetvendor") { }
 
bool OnGossipHello(Player* player, Creature* creature)
{
        if ((player->getClass() == CLASS_HUNTER))
        {
        player->ADD_GOSSIP_ITEM(0, "Normal Creatures (Cost 25 Gold)", GOSSIP_SENDER_MAIN, pets);
        player->ADD_GOSSIP_ITEM(0, "Exotic Creatures (Cost 500 Gold)", GOSSIP_SENDER_MAIN, exotic);
        player->SEND_GOSSIP_MENU(40009, creature->GetGUID());
    return true;
        }
        else
        {
                player->SEND_GOSSIP_MENU(40010, creature->GetGUID());
                return true;
        }
}
 
bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
{
player->PlayerTalkClass->ClearMenus();
    switch(action)
    {
                case pets:
                        //player->ADD_GOSSIP_ITEM(2, "Felshetzer", GOSSIP_SENDER_MAIN, felshetzer);
                        player->ADD_GOSSIP_ITEM(2, "Vile Bat", GOSSIP_SENDER_MAIN, fledermaus);
                        player->ADD_GOSSIP_ITEM(2, "Marshfang Slicer", GOSSIP_SENDER_MAIN, netherrochen);
                        player->ADD_GOSSIP_ITEM(2, "Skettis Kaliri", GOSSIP_SENDER_MAIN, raubvogelrot);
                        player->ADD_GOSSIP_ITEM(2, "Oiled Fledgeling", GOSSIP_SENDER_MAIN, raubvogelschwarz);
                        player->ADD_GOSSIP_ITEM(2, "Imperial Eagle", GOSSIP_SENDER_MAIN, raubvogelweiss);
                        //player->ADD_GOSSIP_ITEM(2, "Schlange", GOSSIP_SENDER_MAIN, schlange);
                        player->ADD_GOSSIP_ITEM(2, "Ridgespine Stalker", GOSSIP_SENDER_MAIN, spinne);
                        player->ADD_GOSSIP_ITEM(2, "Skymane Gorilla", GOSSIP_SENDER_MAIN, gorillaschwarz);
                        player->ADD_GOSSIP_ITEM(2, "Un'Goro Thunderer", GOSSIP_SENDER_MAIN, gorillaweiss);
                        player->ADD_GOSSIP_ITEM(2, "Giant Tidecrawler", GOSSIP_SENDER_MAIN, krebs);
                        //player->ADD_GOSSIP_ITEM(2, "Krokodil", GOSSIP_SENDER_MAIN, krokolisk);
                        //player->ADD_GOSSIP_ITEM(2, "Aasvogel", GOSSIP_SENDER_MAIN, aasvogel);
                        player->ADD_GOSSIP_ITEM(2, "Tundra Scavenger", GOSSIP_SENDER_MAIN, hyaene);
                        player->ADD_GOSSIP_ITEM(2, "Frostsaber Pride Watcher", GOSSIP_SENDER_MAIN, katzetiger);
                        player->ADD_GOSSIP_ITEM(2, "Pitch", GOSSIP_SENDER_MAIN, katzeloewe);
                        //player->ADD_GOSSIP_ITEM(2, "Katze (Luchs)", GOSSIP_SENDER_MAIN, katzeluchs);
                        player->ADD_GOSSIP_ITEM(2, "Felsworn Daggermaw", GOSSIP_SENDER_MAIN, raptorgruen);
                        player->ADD_GOSSIP_ITEM(2, "Bloodfen Screecher", GOSSIP_SENDER_MAIN, raptorrot);
                        player->ADD_GOSSIP_ITEM(2, "Fleeting Plainstrider", GOSSIP_SENDER_MAIN, weitschreiter);
                        player->ADD_GOSSIP_ITEM(2, "Blacksting", GOSSIP_SENDER_MAIN, wesperot);
                        player->ADD_GOSSIP_ITEM(2, "Sapphire Hive Wasp", GOSSIP_SENDER_MAIN, wespeblau);
                        player->ADD_GOSSIP_ITEM(2, "Shattered Hand Warhound", GOSSIP_SENDER_MAIN, wolfruestung);
                        //player->ADD_GOSSIP_ITEM(2, "Wolf (Wilder Worg)", GOSSIP_SENDER_MAIN, wolfgrau);
                        //player->ADD_GOSSIP_ITEM(2, "Wolf (Blutdurstiger Tundrawolf)", GOSSIP_SENDER_MAIN, wolfwei?);
                        //player->ADD_GOSSIP_ITEM(0, "I would prefer a exotic list...", GOSSIP_SENDER_MAIN, exotic);
 
                        player->SEND_GOSSIP_MENU(40011, creature->GetGUID());
                break;
               
                case exotic:
                        player->ADD_GOSSIP_ITEM(2, "Nuramoc", GOSSIP_SENDER_MAIN, schimaere);
                        player->ADD_GOSSIP_ITEM(2, "Vekniss Warrior", GOSSIP_SENDER_MAIN, silithidgelb);
                        player->ADD_GOSSIP_ITEM(2, "Centipaar Sandreaver", GOSSIP_SENDER_MAIN, silithidrot);
                        player->ADD_GOSSIP_ITEM(2, "Wooly Rhino Calf", GOSSIP_SENDER_MAIN, rhinozeros);
                        player->ADD_GOSSIP_ITEM(2, "Oozeworm", GOSSIP_SENDER_MAIN, wurmgelb);
                        player->ADD_GOSSIP_ITEM(2, "The Kurken", GOSSIP_SENDER_MAIN, kernhundweiss);
                        player->ADD_GOSSIP_ITEM(2, "Core Hound", GOSSIP_SENDER_MAIN, kernhundrot);
                        player->ADD_GOSSIP_ITEM(2, "Devilsaur", GOSSIP_SENDER_MAIN, teufelssaurierweiss);
                        player->ADD_GOSSIP_ITEM(2, "Tyrantus", GOSSIP_SENDER_MAIN, teufelssaurierschwarz);
                        player->ADD_GOSSIP_ITEM(2, "Skoll", GOSSIP_SENDER_MAIN, skoll);
                        player->ADD_GOSSIP_ITEM(2, "Loque'nahak", GOSSIP_SENDER_MAIN, loque);
                        player->ADD_GOSSIP_ITEM(2, "Gondria", GOSSIP_SENDER_MAIN, gondria);
                        player->ADD_GOSSIP_ITEM(2, "Arcturis", GOSSIP_SENDER_MAIN, arcturis);
                        //player->ADD_GOSSIP_ITEM(0, "I would prefer a non-exotic list...", GOSSIP_SENDER_MAIN, pets);
                       
                        player->SEND_GOSSIP_MENU(40011, creature->GetGUID());
                break;
                /*
                case felshetzer:
                        creature->SummonCreature(CREATURE_FELSHETZER, creature->GetPositionX()+4, creature->GetPositionY(), creature->GetPositionZ()+2, 0, TEMPSUMMON_TIMED_DESPAWN, 60000);
                        player->CLOSE_GOSSIP_MENU(); break;
                */
                case fledermaus:
					if (player->GetMoney() < PRICE_PET_TYP_1)
					{
						creature->MonsterWhisper(MSG_NOT_MONEY, player->GetGUID());
					}else{
						creature->MonsterWhisper(MSG_PET_SUMMON, player->GetGUID());
						player->ModifyMoney(-PRICE_PET_TYP_1);
						creature->SummonCreature(CREATURE_FLEDERMAUS, creature->GetPositionX()+4, creature->GetPositionY(), creature->GetPositionZ()+2, 0, TEMPSUMMON_TIMED_DESPAWN, 60000);
					}
					player->CLOSE_GOSSIP_MENU();
					break;				

				case netherrochen:
					if (player->GetMoney() < PRICE_PET_TYP_1)
					{
						creature->MonsterWhisper(MSG_NOT_MONEY, player->GetGUID());
					}else{
						creature->MonsterWhisper(MSG_PET_SUMMON, player->GetGUID());
						player->ModifyMoney(-PRICE_PET_TYP_1);
                        creature->SummonCreature(CREATURE_NETHERROCHEN, creature->GetPositionX()+4, creature->GetPositionY(), creature->GetPositionZ()+2, 0, TEMPSUMMON_TIMED_DESPAWN, 60000);
					}
					player->CLOSE_GOSSIP_MENU();
					break;				

                case raubvogelrot:
					if (player->GetMoney() < PRICE_PET_TYP_1)
					{
						creature->MonsterWhisper(MSG_NOT_MONEY, player->GetGUID());
					}else{
						creature->MonsterWhisper(MSG_PET_SUMMON, player->GetGUID());
						player->ModifyMoney(-PRICE_PET_TYP_1);
                        creature->SummonCreature(CREATURE_RAUBVOGELROT, creature->GetPositionX()+4, creature->GetPositionY(), creature->GetPositionZ()+2, 0, TEMPSUMMON_TIMED_DESPAWN, 60000);
					}
					player->CLOSE_GOSSIP_MENU();
					break;				

                case raubvogelschwarz:
					if (player->GetMoney() < PRICE_PET_TYP_1)
					{
						creature->MonsterWhisper(MSG_NOT_MONEY, player->GetGUID());
					}else{
						creature->MonsterWhisper(MSG_PET_SUMMON, player->GetGUID());
						player->ModifyMoney(-PRICE_PET_TYP_1);
                        creature->SummonCreature(CREATURE_RAUBVOGELSCHWARZ, creature->GetPositionX()+4, creature->GetPositionY(), creature->GetPositionZ()+2, 0, TEMPSUMMON_TIMED_DESPAWN, 60000);
					}
					player->CLOSE_GOSSIP_MENU();
					break;						
                       
                case raubvogelweiss:
					if (player->GetMoney() < PRICE_PET_TYP_1)
					{
						creature->MonsterWhisper(MSG_NOT_MONEY, player->GetGUID());
					}else{
						creature->MonsterWhisper(MSG_PET_SUMMON, player->GetGUID());
						player->ModifyMoney(-PRICE_PET_TYP_1);
                        creature->SummonCreature(CREATURE_RAUBVOGELWEISS, creature->GetPositionX()+4, creature->GetPositionY(), creature->GetPositionZ()+2, 0, TEMPSUMMON_TIMED_DESPAWN, 60000);
					}
					player->CLOSE_GOSSIP_MENU();
					break;					
                /*      
                case schlange:
					if (player->GetMoney() < PRICE_PET_TYP_1)
					{
						creature->MonsterWhisper(MSG_NOT_MONEY, player->GetGUID());
					}else{
						creature->MonsterWhisper(MSG_PET_SUMMON, player->GetGUID());
						player->ModifyMoney(-PRICE_PET_TYP_1);
                        creature->SummonCreature(CREATURE_SCHLANGE, creature->GetPositionX()+4, creature->GetPositionY(), creature->GetPositionZ()+2, 0, TEMPSUMMON_TIMED_DESPAWN, 60000);
					}
					player->CLOSE_GOSSIP_MENU();
					break;						
                */      
                case spinne:
					if (player->GetMoney() < PRICE_PET_TYP_1)
					{
						creature->MonsterWhisper(MSG_NOT_MONEY, player->GetGUID());
					}else{
						creature->MonsterWhisper(MSG_PET_SUMMON, player->GetGUID());
						player->ModifyMoney(-PRICE_PET_TYP_1);
                        creature->SummonCreature(CREATURE_SPINNE, creature->GetPositionX()+4, creature->GetPositionY(), creature->GetPositionZ()+2, 0, TEMPSUMMON_TIMED_DESPAWN, 60000);
					}
					player->CLOSE_GOSSIP_MENU();
					break;				
                       
                case gorillaschwarz:
					if (player->GetMoney() < PRICE_PET_TYP_1)
					{
						creature->MonsterWhisper(MSG_NOT_MONEY, player->GetGUID());
					}else{
						creature->MonsterWhisper(MSG_PET_SUMMON, player->GetGUID());
						player->ModifyMoney(-PRICE_PET_TYP_1);
                        creature->SummonCreature(CREATURE_GORILLASCHWARZ, creature->GetPositionX()+4, creature->GetPositionY(), creature->GetPositionZ()+2, 0, TEMPSUMMON_TIMED_DESPAWN, 60000);
					}
					player->CLOSE_GOSSIP_MENU();
					break;							
                       
                case gorillaweiss:
					if (player->GetMoney() < PRICE_PET_TYP_1)
					{
						creature->MonsterWhisper(MSG_NOT_MONEY, player->GetGUID());
					}else{
						creature->MonsterWhisper(MSG_PET_SUMMON, player->GetGUID());
						player->ModifyMoney(-PRICE_PET_TYP_1);
                        creature->SummonCreature(CREATURE_GORILLAWEISS, creature->GetPositionX()+4, creature->GetPositionY(), creature->GetPositionZ()+2, 0, TEMPSUMMON_TIMED_DESPAWN, 60000);
					}
					player->CLOSE_GOSSIP_MENU();
					break;					
                       
                case krebs:
					if (player->GetMoney() < PRICE_PET_TYP_1)
					{
						creature->MonsterWhisper(MSG_NOT_MONEY, player->GetGUID());
					}else{
						creature->MonsterWhisper(MSG_PET_SUMMON, player->GetGUID());
						player->ModifyMoney(-PRICE_PET_TYP_1);
                        creature->SummonCreature(CREATURE_KREBS, creature->GetPositionX()+4, creature->GetPositionY(), creature->GetPositionZ()+2, 0, TEMPSUMMON_TIMED_DESPAWN, 60000);
					}
					player->CLOSE_GOSSIP_MENU();
					break;						
                       
                case hyaene:
					if (player->GetMoney() < PRICE_PET_TYP_1)
					{
						creature->MonsterWhisper(MSG_NOT_MONEY, player->GetGUID());
					}else{
						creature->MonsterWhisper(MSG_PET_SUMMON, player->GetGUID());
						player->ModifyMoney(-PRICE_PET_TYP_1);
                        creature->SummonCreature(CREATURE_HYAENE, creature->GetPositionX()+4, creature->GetPositionY(), creature->GetPositionZ()+2, 0, TEMPSUMMON_TIMED_DESPAWN, 60000);
					}
					player->CLOSE_GOSSIP_MENU();
					break;						
                       
                case katzetiger:
					if (player->GetMoney() < PRICE_PET_TYP_1)
					{
						creature->MonsterWhisper(MSG_NOT_MONEY, player->GetGUID());
					}else{
						creature->MonsterWhisper(MSG_PET_SUMMON, player->GetGUID());
						player->ModifyMoney(-PRICE_PET_TYP_1);
                        creature->SummonCreature(CREATURE_KATZETIGER, creature->GetPositionX()+4, creature->GetPositionY(), creature->GetPositionZ()+2, 0, TEMPSUMMON_TIMED_DESPAWN, 60000);
					}
					player->CLOSE_GOSSIP_MENU();
					break;						
                       
                case katzeloewe:
					if (player->GetMoney() < PRICE_PET_TYP_1)
					{
						creature->MonsterWhisper(MSG_NOT_MONEY, player->GetGUID());
					}else{
						creature->MonsterWhisper(MSG_PET_SUMMON, player->GetGUID());
						player->ModifyMoney(-PRICE_PET_TYP_1);
                        creature->SummonCreature(CREATURE_KATZELOEWE, creature->GetPositionX()+4, creature->GetPositionY(), creature->GetPositionZ()+2, 0, TEMPSUMMON_TIMED_DESPAWN, 60000);
					}
					player->CLOSE_GOSSIP_MENU();
					break;						
                        /*
                case katzeluchs:
					if (player->GetMoney() < PRICE_PET_TYP_1)
					{
						creature->MonsterWhisper(MSG_NOT_MONEY, player->GetGUID());
					}else{
						creature->MonsterWhisper(MSG_PET_SUMMON, player->GetGUID());
						player->ModifyMoney(-PRICE_PET_TYP_1);
                        creature->SummonCreature(CREATURE_KATZELUCHS, creature->GetPositionX()+4, creature->GetPositionY(), creature->GetPositionZ()+2, 0, TEMPSUMMON_TIMED_DESPAWN, 60000);
					}
					player->CLOSE_GOSSIP_MENU();
					break;						
                        */
                case raptorgruen:
					if (player->GetMoney() < PRICE_PET_TYP_1)
					{
						creature->MonsterWhisper(MSG_NOT_MONEY, player->GetGUID());
					}else{
						creature->MonsterWhisper(MSG_PET_SUMMON, player->GetGUID());
						player->ModifyMoney(-PRICE_PET_TYP_1);
                        creature->SummonCreature(CREATURE_RAPTORGRUEN, creature->GetPositionX()+4, creature->GetPositionY(), creature->GetPositionZ()+2, 0, TEMPSUMMON_TIMED_DESPAWN, 60000);
					}
					player->CLOSE_GOSSIP_MENU();
					break;							
                       
                case raptorrot:
					if (player->GetMoney() < PRICE_PET_TYP_1)
					{
						creature->MonsterWhisper(MSG_NOT_MONEY, player->GetGUID());
					}else{
						creature->MonsterWhisper(MSG_PET_SUMMON, player->GetGUID());
						player->ModifyMoney(-PRICE_PET_TYP_1);
                        creature->SummonCreature(CREATURE_RAPTORROT, creature->GetPositionX()+4, creature->GetPositionY(), creature->GetPositionZ()+2, 0, TEMPSUMMON_TIMED_DESPAWN, 60000);
					}
					player->CLOSE_GOSSIP_MENU();
					break;							
                       
                case weitschreiter:
					if (player->GetMoney() < PRICE_PET_TYP_1)
					{
						creature->MonsterWhisper(MSG_NOT_MONEY, player->GetGUID());
					}else{
						creature->MonsterWhisper(MSG_PET_SUMMON, player->GetGUID());
						player->ModifyMoney(-PRICE_PET_TYP_1);
                        creature->SummonCreature(CREATURE_WEITSCHREITER, creature->GetPositionX()+4, creature->GetPositionY(), creature->GetPositionZ()+2, 0, TEMPSUMMON_TIMED_DESPAWN, 60000);
					}
					player->CLOSE_GOSSIP_MENU();
					break;						
                       
                case wesperot:
					if (player->GetMoney() < PRICE_PET_TYP_1)
					{
						creature->MonsterWhisper(MSG_NOT_MONEY, player->GetGUID());
					}else{
						creature->MonsterWhisper(MSG_PET_SUMMON, player->GetGUID());
						player->ModifyMoney(-PRICE_PET_TYP_1);
                        creature->SummonCreature(CREATURE_WESPEROT, creature->GetPositionX()+4, creature->GetPositionY(), creature->GetPositionZ()+2, 0, TEMPSUMMON_TIMED_DESPAWN, 60000);
					}
					player->CLOSE_GOSSIP_MENU();
					break;						
                       
                case wespeblau:
					if (player->GetMoney() < PRICE_PET_TYP_1)
					{
						creature->MonsterWhisper(MSG_NOT_MONEY, player->GetGUID());
					}else{
						creature->MonsterWhisper(MSG_PET_SUMMON, player->GetGUID());
						player->ModifyMoney(-PRICE_PET_TYP_1);
                        creature->SummonCreature(CREATURE_WESPEBLAU, creature->GetPositionX()+4, creature->GetPositionY(), creature->GetPositionZ()+2, 0, TEMPSUMMON_TIMED_DESPAWN, 60000);
					}
					player->CLOSE_GOSSIP_MENU();
					break;						
                       
                case wolfruestung:
					if (player->GetMoney() < PRICE_PET_TYP_1)
					{
						creature->MonsterWhisper(MSG_NOT_MONEY, player->GetGUID());
					}else{
						creature->MonsterWhisper(MSG_PET_SUMMON, player->GetGUID());
						player->ModifyMoney(-PRICE_PET_TYP_1);
                        creature->SummonCreature(CREATURE_WOLFRUESTUNG, creature->GetPositionX()+4, creature->GetPositionY(), creature->GetPositionZ()+2, 0, TEMPSUMMON_TIMED_DESPAWN, 60000);
					}
					player->CLOSE_GOSSIP_MENU();
					break;					
                       
                        // -- Exotics -- //
                       
                case schimaere:
					if (player->GetMoney() < PRICE_PET_TYP_2)
					{
						creature->MonsterWhisper(MSG_NOT_MONEY, player->GetGUID());
					}else{
						creature->MonsterWhisper(MSG_PET_SUMMON, player->GetGUID());
						player->ModifyMoney(-PRICE_PET_TYP_2);
                        creature->SummonCreature(CREATURE_SCHIMAERE, creature->GetPositionX()+4, creature->GetPositionY(), creature->GetPositionZ()+2, 0, TEMPSUMMON_TIMED_DESPAWN, 60000);
					}
					player->CLOSE_GOSSIP_MENU();
					break;						
                       
                case silithidgelb:
					if (player->GetMoney() < PRICE_PET_TYP_2)
					{
						creature->MonsterWhisper(MSG_NOT_MONEY, player->GetGUID());
					}else{
						creature->MonsterWhisper(MSG_PET_SUMMON, player->GetGUID());
						player->ModifyMoney(-PRICE_PET_TYP_2);
                        creature->SummonCreature(CREATURE_SILITHIDGELB, creature->GetPositionX()+4, creature->GetPositionY(), creature->GetPositionZ()+2, 0, TEMPSUMMON_TIMED_DESPAWN, 60000);
					}
					player->CLOSE_GOSSIP_MENU();
					break;							
                       
                case silithidrot:
					if (player->GetMoney() < PRICE_PET_TYP_2)
					{
						creature->MonsterWhisper(MSG_NOT_MONEY, player->GetGUID());
					}else{
						creature->MonsterWhisper(MSG_PET_SUMMON, player->GetGUID());
						player->ModifyMoney(-PRICE_PET_TYP_2);
                        creature->SummonCreature(CREATURE_SILITHIDROT, creature->GetPositionX()+4, creature->GetPositionY(), creature->GetPositionZ()+2, 0, TEMPSUMMON_TIMED_DESPAWN, 60000);
					}
					player->CLOSE_GOSSIP_MENU();
					break;						
                       
                case rhinozeros:
					if (player->GetMoney() < PRICE_PET_TYP_2)
					{
						creature->MonsterWhisper(MSG_NOT_MONEY, player->GetGUID());
					}else{
						creature->MonsterWhisper(MSG_PET_SUMMON, player->GetGUID());
						player->ModifyMoney(-PRICE_PET_TYP_2);
                        creature->SummonCreature(CREATURE_RHINOZEROS, creature->GetPositionX()+4, creature->GetPositionY(), creature->GetPositionZ()+2, 0, TEMPSUMMON_TIMED_DESPAWN, 60000);
					}
					player->CLOSE_GOSSIP_MENU();
					break;								
       
                case wurmgelb:
					if (player->GetMoney() < PRICE_PET_TYP_2)
					{
						creature->MonsterWhisper(MSG_NOT_MONEY, player->GetGUID());
					}else{
						creature->MonsterWhisper(MSG_PET_SUMMON, player->GetGUID());
						player->ModifyMoney(-PRICE_PET_TYP_2);
                        creature->SummonCreature(CREATURE_WURMGELB, creature->GetPositionX()+4, creature->GetPositionY(), creature->GetPositionZ()+2, 0, TEMPSUMMON_TIMED_DESPAWN, 60000);
					}
					player->CLOSE_GOSSIP_MENU();
					break;								
                       
                case kernhundweiss:
					if (player->GetMoney() < PRICE_PET_TYP_2)
					{
						creature->MonsterWhisper(MSG_NOT_MONEY, player->GetGUID());
					}else{
						creature->MonsterWhisper(MSG_PET_SUMMON, player->GetGUID());
						player->ModifyMoney(-PRICE_PET_TYP_2);
                        creature->SummonCreature(CREATURE_KERNHUNDWEISS, creature->GetPositionX()+4, creature->GetPositionY(), creature->GetPositionZ()+2, 0, TEMPSUMMON_TIMED_DESPAWN, 60000);
					}
					player->CLOSE_GOSSIP_MENU();
					break;						
                       
                case kernhundrot:
					if (player->GetMoney() < PRICE_PET_TYP_2)
					{
						creature->MonsterWhisper(MSG_NOT_MONEY, player->GetGUID());
					}else{
						creature->MonsterWhisper(MSG_PET_SUMMON, player->GetGUID());
						player->ModifyMoney(-PRICE_PET_TYP_2);
                        creature->SummonCreature(CREATURE_KERNHUNDROT, creature->GetPositionX()+4, creature->GetPositionY(), creature->GetPositionZ()+2, 0, TEMPSUMMON_TIMED_DESPAWN, 60000);
					}
					player->CLOSE_GOSSIP_MENU();
					break;						
                       
                case teufelssaurierweiss:
					if (player->GetMoney() < PRICE_PET_TYP_2)
					{
						creature->MonsterWhisper(MSG_NOT_MONEY, player->GetGUID());
					}else{
						creature->MonsterWhisper(MSG_PET_SUMMON, player->GetGUID());
						player->ModifyMoney(-PRICE_PET_TYP_2);
                        creature->SummonCreature(CREATURE_TEUFELSSAURIERWEISS, creature->GetPositionX()+4, creature->GetPositionY(), creature->GetPositionZ()+2, 0, TEMPSUMMON_TIMED_DESPAWN, 60000);
					}
					player->CLOSE_GOSSIP_MENU();
					break;							
                       
                case teufelssaurierschwarz:
					if (player->GetMoney() < PRICE_PET_TYP_2)
					{
						creature->MonsterWhisper(MSG_NOT_MONEY, player->GetGUID());
					}else{
						creature->MonsterWhisper(MSG_PET_SUMMON, player->GetGUID());
						player->ModifyMoney(-PRICE_PET_TYP_2);
                        creature->SummonCreature(CREATURE_TEUFELSSAURIERSCHWARZ, creature->GetPositionX()+4, creature->GetPositionY(), creature->GetPositionZ()+2, 0, TEMPSUMMON_TIMED_DESPAWN, 60000);
					}
					player->CLOSE_GOSSIP_MENU();
					break;					
                       
                case skoll:
					if (player->GetMoney() < PRICE_PET_TYP_2)
					{
						creature->MonsterWhisper(MSG_NOT_MONEY, player->GetGUID());
					}else{
						creature->MonsterWhisper(MSG_PET_SUMMON, player->GetGUID());
						player->ModifyMoney(-PRICE_PET_TYP_2);
                        creature->SummonCreature(CREATURE_SKOLL, creature->GetPositionX()+4, creature->GetPositionY(), creature->GetPositionZ()+2, 0, TEMPSUMMON_TIMED_DESPAWN, 60000);
					}
					player->CLOSE_GOSSIP_MENU();
					break;						
                       
                case loque:
					if (player->GetMoney() < PRICE_PET_TYP_2)
					{
						creature->MonsterWhisper(MSG_NOT_MONEY, player->GetGUID());
					}else{
						creature->MonsterWhisper(MSG_PET_SUMMON, player->GetGUID());
						player->ModifyMoney(-PRICE_PET_TYP_2);
                        creature->SummonCreature(CREATURE_LOQUE, creature->GetPositionX()+4, creature->GetPositionY(), creature->GetPositionZ()+2, 0, TEMPSUMMON_TIMED_DESPAWN, 60000);
					}
					player->CLOSE_GOSSIP_MENU();
					break;					
                       
                case gondria:
					if (player->GetMoney() < PRICE_PET_TYP_2)
					{
						creature->MonsterWhisper(MSG_NOT_MONEY, player->GetGUID());
					}else{
						creature->MonsterWhisper(MSG_PET_SUMMON, player->GetGUID());
						player->ModifyMoney(-PRICE_PET_TYP_2);
                        creature->SummonCreature(CREATURE_GONDRIA, creature->GetPositionX()+4, creature->GetPositionY(), creature->GetPositionZ()+2, 0, TEMPSUMMON_TIMED_DESPAWN, 60000);
					}
					player->CLOSE_GOSSIP_MENU();
					break;							
                       
                case arcturis:
					if (player->GetMoney() < PRICE_PET_TYP_2)
					{
						creature->MonsterWhisper(MSG_NOT_MONEY, player->GetGUID());
					}else{
						creature->MonsterWhisper(MSG_PET_SUMMON, player->GetGUID());
						player->ModifyMoney(-PRICE_PET_TYP_2);
                        creature->SummonCreature(CREATURE_ARCTURIS, creature->GetPositionX()+4, creature->GetPositionY(), creature->GetPositionZ()+2, 0, TEMPSUMMON_TIMED_DESPAWN, 60000);
					}
					player->CLOSE_GOSSIP_MENU();
					break;						
    }
 
    return true;
}
};
void AddSC_npc_hunterpetvendor()
{
        new npc_hunterpetvendor;
}