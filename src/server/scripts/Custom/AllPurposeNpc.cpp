// -=/PryDevCore\=-
// Development For The Community 2011
// 
// Main Site- http://prydevserver.com/
// Community Forum- http://prydevserver.com/forum/
// Main Repository- http://sf.net/projects/prydevserver/
//
//
// Last Updated: August 8th 2011 by Pryd

#include "ScriptPCH.h"
#include "../../shared/Configuration/Config.h"
#ifndef _TRINITY_CORE_CONFIG
# define _TRINITY_CORE_CONFIG  "UC-World.conf"   // <-- If using trinity switch UC-World.conf to worldserver.conf
#endif _TRINITY_CORE_CONFIG

// Menus
#define REQUESTER_MENU_REQUEST_ITEM "Request an item"
#define REQUESTER_MENU_REQUEST_CONFIRMATION "Enter Item Id Or Name"
#define REQUESTER_MENU_EXIT	"[Exit]"

// Errors
#define REQUESTER_ERROR_INVALID_ITEM "Invalid Item entered"
#define REQUESTER_ERROR_QUALITY_TOO_HIGH "Requested Item Quality is too high."
#define REQUESTER_ERROR_REQUIREMENTS_NOT_MET "Item cannot be requested, you do not meet the requirements."
#define REQUESTER_ERROR_ITEM_CREATION_FAILED "Item creation failed"

// Mail
#define REQUESTER_DEFAULT_MAIL_SUBJECT "ItemRequester: Your item has arrived"
#define REQUESTER_DEFAULT_MAIL_BODY ""
#define REQUESTER_MAIL_SUCCESS "Item has been mailed"

// Level Requirements
enum REQUESTER_QUALITY_LEVEL_REQUIRED
{
	REQUESTER_QUALITY_LEVEL_PNU		= 61,	// ITEM_QUALITY_POOR / ITEM_QUALITY_NORMAL / ITEM_QUALITY_UNCOMMON
	REQUESTER_QUALITY_LEVEL_RARE	= 62,	// ITEM_QUALITY_RARE
	REQUESTER_QUALITY_LEVEL_EPIC	= 63	// ITEM_QUALITY_EPIC
};

enum ITEM_REQUESTER_MENUS
{
	ITEM_REQUESTER_MENU_SELECT_ITEM	= 64,
	ITEM_REQUESTER_MENU_EXIT,
};

class pryds_telenpc : public CreatureScript
{
    public:

        pryds_telenpc()
            : CreatureScript("pryds_telenpc")
        {
        }

        struct pryds_telenpcAI : public ScriptedAI
        {
	    //*** HANDLED FUNCTION ***
        //This is the constructor, called only once when the Creature is first created
            pryds_telenpcAI(Creature *c) : ScriptedAI(c) {}   
        }; 

        
void CreatePet(Player *player, Creature * pCreature, uint32 entry) {

        if(player->getClass() != CLASS_HUNTER) {
            pCreature->MonsterWhisper("You are not a Hunter!", player->GetGUID());
            player->PlayerTalkClass->SendCloseGossip();
            return;
        }
 
        if(player->GetPet()) {
            pCreature->MonsterWhisper("First you must drop your Pet!", player->GetGUID());
            player->PlayerTalkClass->SendCloseGossip();
            return;
        }
 
        Creature *creatureTarget = pCreature->SummonCreature(entry, player->GetPositionX(), player->GetPositionY()+2, player->GetPositionZ(), player->GetOrientation(), TEMPSUMMON_CORPSE_TIMED_DESPAWN, 500);
        if(!creatureTarget) return;
        
        Pet* pet = player->CreateTamedPetFrom(creatureTarget, 0);
        if(!pet) return;
 
        // kill original creature
        creatureTarget->setDeathState(JUST_DIED);
        creatureTarget->RemoveCorpse();
        creatureTarget->SetHealth(0);                       // just for nice GM-mode view
 
        pet->SetPower(POWER_HAPPINESS, 1048000);
 
        //pet->SetUInt32Value(UNIT_FIELD_PETEXPERIENCE,0);
        //pet->SetUInt32Value(UNIT_FIELD_PETNEXTLEVELEXP, uint32((Trinity::XP::xp_to_level(70))/4));
 
        // prepare visual effect for levelup
            pet->SetUInt32Value(UNIT_FIELD_LEVEL, player->getLevel() - 1);
        pet->GetMap()->Add((Creature*)pet);
        // visual effect for levelup
        pet->SetUInt32Value(UNIT_FIELD_LEVEL, player->getLevel());
 
        
        if(!pet->InitStatsForLevel(player->getLevel()))
            sLog->outError ("Pet Create fail: no init stats for entry %u", entry);
 
        pet->UpdateAllStats();
        
        // caster have pet now
        player->SetMinion(pet, true);
 
        pet->SavePetToDB(PET_SAVE_AS_CURRENT);
        pet->InitTalentForLevel();
        player->PetSpellInitialize();
        
        //end
        player->PlayerTalkClass->SendCloseGossip();
        pCreature->MonsterWhisper("Pet added. You might want to feed it and name it somehow.", player->GetGUID());
    }
         
        
        
bool OnGossipHello(Player *player, Creature* pCreature)
{
  //Config sConfig;

  if(!sConfig->SetSource(_TRINITY_CORE_CONFIG))
    sLog->outError("UC-Script: Unable to open configuration file");

  if(sConfig->GetBoolDefault("pryds_telenpc.OnlyGMs", false)) // If pryds_telenpc.OnlyGMs is enabled in trinitycore.conf
    if(player->GetSession()->GetSecurity() == SEC_PLAYER)
    {
      pCreature->MonsterWhisper("Sorry, I am only allowed to teleport game masters.", player->GetGUID());
      return true;
    }

    bool EnableFactionMalls = sConfig->GetBoolDefault("pryds_telenpc.EnableFactionMalls", true);
    bool EnableShoppingMall = sConfig->GetBoolDefault("pryds_telenpc.EnableShoppingMall", true);

  // First Main Menu System  
  // Main Menu for Alliance
    if ( player->GetTeam() == ALLIANCE )
  {
    player->ADD_GOSSIP_ITEM( 3, "[ Item Requester ] ->"             , GOSSIP_SENDER_MAIN, 60);
	player->ADD_GOSSIP_ITEM( 9, "[ Explore Azeroth ] ->"             , GOSSIP_SENDER_MAIN, 1098);
    player->ADD_GOSSIP_ITEM( 7, "[ Choose Your Morph! ] ->"          , GOSSIP_SENDER_MAIN, 700);
    player->ADD_GOSSIP_ITEM( 2, "[ Buffs, Heals, Food & Gold ] ->"            , GOSSIP_SENDER_MAIN, 2100);
    player->ADD_GOSSIP_ITEM( 3, "[ Profession & Class Trainers ] ->"             , GOSSIP_SENDER_MAIN, 300);
    
  }
  else // Main Menu for Horde
  {
    player->ADD_GOSSIP_ITEM( 3, "[ Item Requester  ] ->"             , GOSSIP_SENDER_MAIN, 60);
	player->ADD_GOSSIP_ITEM( 9, "[ Explore Azeroth ] ->"                , GOSSIP_SENDER_MAIN, 1099);
    player->ADD_GOSSIP_ITEM( 7, "[ Choose Your Morph! ] ->"             , GOSSIP_SENDER_MAIN, 700);
    player->ADD_GOSSIP_ITEM( 2, "[ Buffs, Heals, Food & Gold ] ->"            , GOSSIP_SENDER_MAIN, 2100);
    player->ADD_GOSSIP_ITEM( 3, "[ Profession & Class Trainers ] ->"             , GOSSIP_SENDER_MAIN, 300);
    
  }

  if(player->getClass() == CLASS_HUNTER)
        player->ADD_GOSSIP_ITEM(4, "Get a New Pet.", GOSSIP_SENDER_MAIN, 30);
        if (player->CanTameExoticPets())
        {
            player->ADD_GOSSIP_ITEM(4, "Get a New Exotic Pet.", GOSSIP_SENDER_MAIN, 50);
        }
     
  // Check config file if "Remove res sickness" option is enabled or not
  //if(EnableResSickness)
  //if(EnableFactionMalls)  
    //player->ADD_GOSSIP_ITEM( 1, "PryDevCore Faction Malls", GOSSIP_SENDER_MAIN, 2002 );
    
  // Check config if shopping mall is enabled
  //if(EnableShoppingMall)
    //player->ADD_GOSSIP_ITEM( 4, "PryDevCore FFA Mall", GOSSIP_SENDER_MAIN, 2003);
    player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,pCreature->GetGUID());

return true;
}


void SendDefaultMenu_pryds_telenpc(Player *player, Creature *pCreature, uint32 action )
{

// Not allow in combat
if(!player->getAttackers().empty())
{
    player->CLOSE_GOSSIP_MENU();
    pCreature->MonsterSay("You are in combat!", LANG_UNIVERSAL, NULL);
  return;
}

//Config sConfig;
if(!sConfig->SetSource(_TRINITY_CORE_CONFIG))
    sLog->outError("TScript: Unable to open configuration file");
    
bool EnableResSickness = sConfig->GetBoolDefault("pryds_telenpc.EnableFactionMalls", false);

switch(action)
{
	//  All Menu Categories besides Main Go Here
	case 60:
	
			if (player->GetSession()->GetSecurity() == SEC_PLAYER)
		{
			pCreature->MonsterWhisper("Sorry, I am set only for Game Masters.", player->GetGUID());
			
		}
		else
		{
		    // Pryd - Updated to reflect new standards in Ultra Core G4
		    player->PlayerTalkClass->GetGossipMenu().AddMenuItem(-1, 8, REQUESTER_MENU_REQUEST_ITEM, ITEM_REQUESTER_MENU_SELECT_ITEM, GOSSIP_ACTION_INFO_DEF + 1, REQUESTER_MENU_REQUEST_CONFIRMATION, 0, true);
			player->SEND_GOSSIP_MENU(player->GetGossipTextId(pCreature), pCreature->GetGUID());
		}	
     break;
	
// Pryd: Cata Cities Categorized to make room for 80-85 Cata instances / raids / etc

        case 30:
            player->ADD_GOSSIP_ITEM(2, "<- Back to Pet Menu.", GOSSIP_SENDER_MAIN, 100);
            player->ADD_GOSSIP_ITEM(4, "Next Page. ->", GOSSIP_SENDER_MAIN, 31);
            player->ADD_GOSSIP_ITEM(6, "Bear.", GOSSIP_SENDER_MAIN, 1);
            player->ADD_GOSSIP_ITEM(6, "Boar.", GOSSIP_SENDER_MAIN, 2);
            player->ADD_GOSSIP_ITEM(6, "Wasp.", GOSSIP_SENDER_MAIN, 3);
            player->ADD_GOSSIP_ITEM(6, "Cat.", GOSSIP_SENDER_MAIN, 4);
            player->ADD_GOSSIP_ITEM(6, "Carrion Bird.", GOSSIP_SENDER_MAIN, 5);
            player->ADD_GOSSIP_ITEM(6, "Crab.", GOSSIP_SENDER_MAIN, 6);
            player->ADD_GOSSIP_ITEM(6, "Crocolisk.", GOSSIP_SENDER_MAIN, 7);
            player->ADD_GOSSIP_ITEM(6, "Dragonhawk.", GOSSIP_SENDER_MAIN, 17);
            player->ADD_GOSSIP_ITEM(6, "Gorilla.", GOSSIP_SENDER_MAIN, 8);
            player->ADD_GOSSIP_ITEM(6, "Hound.", GOSSIP_SENDER_MAIN, 9);
            player->ADD_GOSSIP_ITEM(6, "Hyena.", GOSSIP_SENDER_MAIN, 10);
            player->ADD_GOSSIP_ITEM(7, "<- [Main Menu]"                          , GOSSIP_SENDER_MAIN, 2000);
            player->SEND_GOSSIP_MENU(1, pCreature->GetGUID());
                break;
        
        case 31:  
            player->ADD_GOSSIP_ITEM(2, "<- Back to Pet Menu.", GOSSIP_SENDER_MAIN, 30);
            player->ADD_GOSSIP_ITEM(6, "Moth.", GOSSIP_SENDER_MAIN, 11);
            player->ADD_GOSSIP_ITEM(6, "Owl.", GOSSIP_SENDER_MAIN, 12);
            player->ADD_GOSSIP_ITEM(6, "Strider.", GOSSIP_SENDER_MAIN, 13);
            player->ADD_GOSSIP_ITEM(6, "Scorpid.", GOSSIP_SENDER_MAIN, 14);
            player->ADD_GOSSIP_ITEM(6, "Turtle.", GOSSIP_SENDER_MAIN, 15);
            player->ADD_GOSSIP_ITEM(6, "Spider.", GOSSIP_SENDER_MAIN, 16);
            player->ADD_GOSSIP_ITEM(6, "Bat.", GOSSIP_SENDER_MAIN, 18);
            player->ADD_GOSSIP_ITEM(6, "Ravager.", GOSSIP_SENDER_MAIN, 19);
            player->ADD_GOSSIP_ITEM(6, "Raptor.", GOSSIP_SENDER_MAIN, 20);
            player->ADD_GOSSIP_ITEM(6, "Serpent.", GOSSIP_SENDER_MAIN, 21);
            player->ADD_GOSSIP_ITEM(7, "<- [Main Menu]"                          , GOSSIP_SENDER_MAIN, 2000);
            player->SEND_GOSSIP_MENU(1, pCreature->GetGUID());
                break;
        
        case 50:  
            player->ADD_GOSSIP_ITEM(2, "<- Back to Pet Menu.", GOSSIP_SENDER_MAIN, 100);
            player->ADD_GOSSIP_ITEM(6, "Chimaera.", GOSSIP_SENDER_MAIN, 51);
            player->ADD_GOSSIP_ITEM(6, "Core Hound.", GOSSIP_SENDER_MAIN, 52);
            player->ADD_GOSSIP_ITEM(6, "Devilsaur.", GOSSIP_SENDER_MAIN, 53);
            player->ADD_GOSSIP_ITEM(6, "Rhino.", GOSSIP_SENDER_MAIN, 54);
            player->ADD_GOSSIP_ITEM(6, "Silithid.", GOSSIP_SENDER_MAIN, 55);
            player->ADD_GOSSIP_ITEM(6, "Worm.", GOSSIP_SENDER_MAIN, 56);  
            player->ADD_GOSSIP_ITEM(6, "Loque'nahak.", GOSSIP_SENDER_MAIN, 57);
            player->ADD_GOSSIP_ITEM(6, "Skoll.", GOSSIP_SENDER_MAIN, 58);
            player->ADD_GOSSIP_ITEM(6, "Gondria.", GOSSIP_SENDER_MAIN, 59);
            player->ADD_GOSSIP_ITEM(7, "<- [Main Menu]"                          , GOSSIP_SENDER_MAIN, 2000);
            player->SEND_GOSSIP_MENU(1, pCreature->GetGUID());
                break;

case 100:
            player->ADD_GOSSIP_ITEM(4, "Get a New Pet.", GOSSIP_SENDER_MAIN, 30);
            if (player->CanTameExoticPets())
            {
                player->ADD_GOSSIP_ITEM(4, "Get a New Exotic Pet.", GOSSIP_SENDER_MAIN, 50);
            }
            player->ADD_GOSSIP_ITEM(7, "<- [Main Menu]"                          , GOSSIP_SENDER_MAIN, 2000);
            player->SEND_GOSSIP_MENU(1, pCreature->GetGUID());
break;
      


case 200: //Professions SkillUp Category
		player->ADD_GOSSIP_ITEM(3, "[Professions] ->"       				   , GOSSIP_SENDER_MAIN, 2500);
		player->ADD_GOSSIP_ITEM(3, "[Secondary Skills] ->"  				   , GOSSIP_SENDER_MAIN, 2550);
		player->ADD_GOSSIP_ITEM(7, "<- [Main Menu]"                          , GOSSIP_SENDER_MAIN, 2000);

	player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,pCreature->GetGUID());
break;

case 300: //Trainers
		player->ADD_GOSSIP_ITEM(4, "Riding Trainer"       					   , GOSSIP_SENDER_MAIN, 301);
		player->ADD_GOSSIP_ITEM(4, "Stable Master"  				           , GOSSIP_SENDER_MAIN, 302);
		player->ADD_GOSSIP_ITEM(4, "Weapon Master"  				           , GOSSIP_SENDER_MAIN, 303);
		player->ADD_GOSSIP_ITEM(3, "[Class Trainers] ->"       			       , GOSSIP_SENDER_MAIN, 400);
		player->ADD_GOSSIP_ITEM(3, "[Professions Trainers] ->" 				   , GOSSIP_SENDER_MAIN, 500);
		player->ADD_GOSSIP_ITEM(3, "[Professions SkillUp] ->"  				   , GOSSIP_SENDER_MAIN, 200);
		player->ADD_GOSSIP_ITEM(7, "<- [Main Menu]"                	           , GOSSIP_SENDER_MAIN, 2000);

	player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,pCreature->GetGUID());
break;

case 400: //Class Trainers
		player->ADD_GOSSIP_ITEM(3, "Death Knight"               			   , GOSSIP_SENDER_MAIN, 401);
		player->ADD_GOSSIP_ITEM(3, "Druid"                        		   , GOSSIP_SENDER_MAIN, 402);
		player->ADD_GOSSIP_ITEM(3, "Hunter"                 				   , GOSSIP_SENDER_MAIN, 403);
		player->ADD_GOSSIP_ITEM(3, "Mage"                 				   , GOSSIP_SENDER_MAIN, 404);
		player->ADD_GOSSIP_ITEM(3, "Paladin"              				   , GOSSIP_SENDER_MAIN, 405);
		player->ADD_GOSSIP_ITEM(3, "Priest"    	         			       , GOSSIP_SENDER_MAIN, 406);
		player->ADD_GOSSIP_ITEM(3, "Rogue"               	 				   , GOSSIP_SENDER_MAIN, 407);
		player->ADD_GOSSIP_ITEM(3, "Shaman"            					   , GOSSIP_SENDER_MAIN, 408);
		player->ADD_GOSSIP_ITEM(3, "Warlock"         						   , GOSSIP_SENDER_MAIN, 409);
		player->ADD_GOSSIP_ITEM(3, "Warrior"          				       , GOSSIP_SENDER_MAIN, 410);
		player->ADD_GOSSIP_ITEM(3, "Hunter Pet"    					       , GOSSIP_SENDER_MAIN, 411);
		player->ADD_GOSSIP_ITEM(7, "<- [Back]"       		                   , GOSSIP_SENDER_MAIN, 300);
		player->ADD_GOSSIP_ITEM(7, "<- [Main Menu]"                            , GOSSIP_SENDER_MAIN, 2000);

	player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,pCreature->GetGUID());
break;

case 500: //Profession Trainers
		player->ADD_GOSSIP_ITEM(3, "Alchemy"      				           , GOSSIP_SENDER_MAIN, 501);
		player->ADD_GOSSIP_ITEM(3, "Blacksmithing"                           , GOSSIP_SENDER_MAIN, 502);
		player->ADD_GOSSIP_ITEM(3, "Enchanter"         			           , GOSSIP_SENDER_MAIN, 503);
		player->ADD_GOSSIP_ITEM(3, "Engineering"           				   , GOSSIP_SENDER_MAIN, 504);
		player->ADD_GOSSIP_ITEM(3, "Herbalism"             				   , GOSSIP_SENDER_MAIN, 505);
		player->ADD_GOSSIP_ITEM(3, "Inscription"             			       , GOSSIP_SENDER_MAIN, 506);
		player->ADD_GOSSIP_ITEM(3, "Jewelcrafting"            			   , GOSSIP_SENDER_MAIN, 507);
		player->ADD_GOSSIP_ITEM(3, "Leatherworking"            			   , GOSSIP_SENDER_MAIN, 508);
		player->ADD_GOSSIP_ITEM(3, "Mining"             					   , GOSSIP_SENDER_MAIN, 509);
		player->ADD_GOSSIP_ITEM(3, "Skinning"                 			   , GOSSIP_SENDER_MAIN, 510);
		player->ADD_GOSSIP_ITEM(3, "Tailoring"           					   , GOSSIP_SENDER_MAIN, 511);
		player->ADD_GOSSIP_ITEM(3, "Cooking"               				   , GOSSIP_SENDER_MAIN, 512);
		player->ADD_GOSSIP_ITEM(3, "First Aid"             				   , GOSSIP_SENDER_MAIN, 513);
		player->ADD_GOSSIP_ITEM(3, "Fishing"               				   , GOSSIP_SENDER_MAIN, 514);
		player->ADD_GOSSIP_ITEM(7, "<- [Back]"       		                   , GOSSIP_SENDER_MAIN, 300);
		player->ADD_GOSSIP_ITEM(7, "<- [Main Menu]"                            , GOSSIP_SENDER_MAIN, 2000);

	player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,pCreature->GetGUID());
break;

case 700: // Morph Category Menu
		player->ADD_GOSSIP_ITEM(7, "[Famous Morphs] ->" 						   , GOSSIP_SENDER_MAIN, 710);
        player->ADD_GOSSIP_ITEM(7, "[Funny Morphs] ->" 							   , GOSSIP_SENDER_MAIN, 750);
		player->ADD_GOSSIP_ITEM(2, "Give me a Drink "   						       , GOSSIP_SENDER_MAIN, 769);
		player->ADD_GOSSIP_ITEM(2, "Make me sober "   						       , GOSSIP_SENDER_MAIN, 770);
        player->ADD_GOSSIP_ITEM(2, "Make me Bigger +" 					           , GOSSIP_SENDER_MAIN, 771);
		player->ADD_GOSSIP_ITEM(2, "Make me Smaller -"     					       , GOSSIP_SENDER_MAIN, 772);
        //player->ADD_GOSSIP_ITEM(4, "Boss Morphs ->" 							   , GOSSIP_SENDER_MAIN, 753);
        //player->ADD_GOSSIP_ITEM(4, "Cataclysm Morphs ->" 						   , GOSSIP_SENDER_MAIN, 754);
		player->ADD_GOSSIP_ITEM(4, "- [DeMorph]" 							           , GOSSIP_SENDER_MAIN, 799);
		player->ADD_GOSSIP_ITEM(7, "<- [Main Menu]"                	               , GOSSIP_SENDER_MAIN, 2000);

	player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,pCreature->GetGUID());
break;

case 710: //Morph Famous
		player->ADD_GOSSIP_ITEM(4, "Algalon"  		    			           , GOSSIP_SENDER_MAIN, 711);
		player->ADD_GOSSIP_ITEM(4, "Doomwalker" 						       , GOSSIP_SENDER_MAIN, 712);
		player->ADD_GOSSIP_ITEM(4, "Doomlord kazzak" 					       , GOSSIP_SENDER_MAIN, 713);
		player->ADD_GOSSIP_ITEM(4, "Onyxia" 							       , GOSSIP_SENDER_MAIN, 714);
		player->ADD_GOSSIP_ITEM(4, "Thaddius" 							       , GOSSIP_SENDER_MAIN, 715);
		player->ADD_GOSSIP_ITEM(4, "Gluth" 							           , GOSSIP_SENDER_MAIN, 716);
		player->ADD_GOSSIP_ITEM(4, "Maexxna" 							       , GOSSIP_SENDER_MAIN, 717);
		player->ADD_GOSSIP_ITEM(4, "Sapphiron" 							       , GOSSIP_SENDER_MAIN, 718);
		player->ADD_GOSSIP_ITEM(4, "Noth The Plaguebringer"				       , GOSSIP_SENDER_MAIN, 719);
		player->ADD_GOSSIP_ITEM(4, "Kel'Thuzad" 						       , GOSSIP_SENDER_MAIN, 720);
		player->ADD_GOSSIP_ITEM(4, "Kael'thas Sunstrider" 				       , GOSSIP_SENDER_MAIN, 721);
		player->ADD_GOSSIP_ITEM(4, "C'thun" 							       , GOSSIP_SENDER_MAIN, 722);
		player->ADD_GOSSIP_ITEM(4, "Thrall" 							       , GOSSIP_SENDER_MAIN, 723);
		player->ADD_GOSSIP_ITEM(4, "- [DeMorph]" 							   , GOSSIP_SENDER_MAIN, 799);
		player->ADD_GOSSIP_ITEM(7, "<- [Back]"       		                   , GOSSIP_SENDER_MAIN, 700);
		player->ADD_GOSSIP_ITEM(7, "<- [Main Menu]"                	           , GOSSIP_SENDER_MAIN, 2000);

	player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,pCreature->GetGUID());
break;

case 750: //Morph Funny
		player->ADD_GOSSIP_ITEM(4, "Gerky ->"   	 		   			       , GOSSIP_SENDER_MAIN, 751);
		player->ADD_GOSSIP_ITEM(4, "Fire elemental ->" 					       , GOSSIP_SENDER_MAIN, 752);
		player->ADD_GOSSIP_ITEM(4, "Pandaren Monk ->" 					       , GOSSIP_SENDER_MAIN, 753);
		player->ADD_GOSSIP_ITEM(4, "Lil' K.T ->" 					 		   , GOSSIP_SENDER_MAIN, 754);
		player->ADD_GOSSIP_ITEM(4, "The Weapon you're Wearing ->"	 	       , GOSSIP_SENDER_MAIN, 755);
		player->ADD_GOSSIP_ITEM(4, "Red Bubbles ->" 					       , GOSSIP_SENDER_MAIN, 756);
		player->ADD_GOSSIP_ITEM(4, "A Shark ->"    		   			           , GOSSIP_SENDER_MAIN, 757);
		player->ADD_GOSSIP_ITEM(4, "A Fel cannon ->"   	   			           , GOSSIP_SENDER_MAIN, 758);
		player->ADD_GOSSIP_ITEM(4, "Human Female  ->" 	   			           , GOSSIP_SENDER_MAIN, 759);
		player->ADD_GOSSIP_ITEM(4, "A Fat Human ->" 		   			       , GOSSIP_SENDER_MAIN, 760);
		player->ADD_GOSSIP_ITEM(4, "A Rabbit ->" 	 		   			       , GOSSIP_SENDER_MAIN, 761);
		player->ADD_GOSSIP_ITEM(4, "A Cool looking Bug ->"   			       , GOSSIP_SENDER_MAIN, 762);
		player->ADD_GOSSIP_ITEM(4, "Eye Of C'thun ->"   	   			       , GOSSIP_SENDER_MAIN, 763);
		player->ADD_GOSSIP_ITEM(4, "- [DeMorph]" 							   , GOSSIP_SENDER_MAIN, 799);
		player->ADD_GOSSIP_ITEM(7, "<- [Back]"       		                       , GOSSIP_SENDER_MAIN, 700);
		player->ADD_GOSSIP_ITEM(7, "<- [Main Menu]"                	           , GOSSIP_SENDER_MAIN, 2000);

	player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,pCreature->GetGUID());
break;


case 1098:  // Teleport Category Menu
    player->ADD_GOSSIP_ITEM( 7, "[Alliance] Main Cities ->"                    , GOSSIP_SENDER_MAIN, 1000);
    player->ADD_GOSSIP_ITEM( 7, "[Classic WoW] L1-60 Dungeons] ->"      , GOSSIP_SENDER_MAIN, 1200);
    player->ADD_GOSSIP_ITEM( 7, "[TBC & WOTLK] L60-79 Dungeons] ->"      , GOSSIP_SENDER_MAIN, 1300);
    player->ADD_GOSSIP_ITEM( 7, "[WOTLK] Lvl 80 Dungeons] ->"               , GOSSIP_SENDER_MAIN, 1400);
    player->ADD_GOSSIP_ITEM( 7, "[WOTLK] Lvl 80 Raids] ->"                  , GOSSIP_SENDER_MAIN, 1500);
    //player->ADD_GOSSIP_ITEM( 7, "[Cataclysm] Dungeons & Raids] ->"          , GOSSIP_SENDER_MAIN, 1600);
    player->ADD_GOSSIP_ITEM( 7, "[Battlegrounds and Arenas] ->"                , GOSSIP_SENDER_MAIN, 1700);
    //player->ADD_GOSSIP_ITEM( 7, "[Testing & Development] ->"                   , GOSSIP_SENDER_MAIN, 1800);
    player->ADD_GOSSIP_ITEM( 1, "PDS-UC Faction Mall"                  , GOSSIP_SENDER_MAIN, 2002);
    player->ADD_GOSSIP_ITEM( 4, "PDS-UC FFA Mall"                       , GOSSIP_SENDER_MAIN, 2003);
    player->ADD_GOSSIP_ITEM( 7, "<- [Back]"                                 , GOSSIP_SENDER_MAIN, 2000);

  player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,pCreature->GetGUID());
break;

case 1099:  // Teleport Category Menu
    player->ADD_GOSSIP_ITEM( 7, "[Horde] Main Cities ->"                       , GOSSIP_SENDER_MAIN, 1100);
    player->ADD_GOSSIP_ITEM( 7, "[Classic WoW] L1-60 Dungeons] ->"      , GOSSIP_SENDER_MAIN, 1200);
    player->ADD_GOSSIP_ITEM( 7, "[TBC & WOTLK] L60-79 Dungeons] ->"      , GOSSIP_SENDER_MAIN, 1300);
    player->ADD_GOSSIP_ITEM( 7, "[WOTLK] Lvl 80 Dungeons] ->"               , GOSSIP_SENDER_MAIN, 1400);
    player->ADD_GOSSIP_ITEM( 7, "[WOTLK] Lvl 80 Raids] ->"                  , GOSSIP_SENDER_MAIN, 1500);
    //player->ADD_GOSSIP_ITEM( 7, "[Cataclysm] Dungeons & Raids] ->"          , GOSSIP_SENDER_MAIN, 1600);
    player->ADD_GOSSIP_ITEM( 7, "[Battlegrounds and Arenas] ->"                , GOSSIP_SENDER_MAIN, 1700);
    //player->ADD_GOSSIP_ITEM( 7, "[Testing & Development] ->"                   , GOSSIP_SENDER_MAIN, 1800);
    player->ADD_GOSSIP_ITEM( 1, "PDS-UC Faction Malls"                  , GOSSIP_SENDER_MAIN, 2002);
    player->ADD_GOSSIP_ITEM( 4, "PDS-UC FFA Mall"                       , GOSSIP_SENDER_MAIN, 2003);
    player->ADD_GOSSIP_ITEM( 7, "<- [Back]"                                 , GOSSIP_SENDER_MAIN, 2000);

  player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,pCreature->GetGUID());
break;
    
case 1000: //Ally Cities

  player->ADD_GOSSIP_ITEM( 5, "Dalaran"                      , GOSSIP_SENDER_MAIN, 1001);
  player->ADD_GOSSIP_ITEM( 5, "Darnassus"                    , GOSSIP_SENDER_MAIN, 1002);
  player->ADD_GOSSIP_ITEM( 5, "Exodar"                       , GOSSIP_SENDER_MAIN, 1003);
  //player->ADD_GOSSIP_ITEM( 5, "Gilneas"                      , GOSSIP_SENDER_MAIN, 1004);
  player->ADD_GOSSIP_ITEM( 5, "Ironforge"                    , GOSSIP_SENDER_MAIN, 1005);
  player->ADD_GOSSIP_ITEM( 5, "Shattrath City"               , GOSSIP_SENDER_MAIN, 1006);
  player->ADD_GOSSIP_ITEM( 5, "Stormwind"                    , GOSSIP_SENDER_MAIN, 1007);
  player->ADD_GOSSIP_ITEM( 5, "Razor Hill(Orgrimmar)"        , GOSSIP_SENDER_MAIN, 1008);
  player->ADD_GOSSIP_ITEM( 7, "<- [Back]"                    , GOSSIP_SENDER_MAIN, 1098);
  player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"               , GOSSIP_SENDER_MAIN, 2000);

  player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,pCreature->GetGUID());
break;

case 1100: //Horde Cities
  
  player->ADD_GOSSIP_ITEM( 5, "Dalaran"                      , GOSSIP_SENDER_MAIN, 1001);
  //player->ADD_GOSSIP_ITEM( 5, "Kezan"                        , GOSSIP_SENDER_MAIN, 1101);
  player->ADD_GOSSIP_ITEM( 5, "Orgrimmar"                    , GOSSIP_SENDER_MAIN, 1102);
  player->ADD_GOSSIP_ITEM( 5, "Silvermoon"                   , GOSSIP_SENDER_MAIN, 1103);
  player->ADD_GOSSIP_ITEM( 5, "Shattrath City"               , GOSSIP_SENDER_MAIN, 1006);
  player->ADD_GOSSIP_ITEM( 5, "Thunder Bluff"                , GOSSIP_SENDER_MAIN, 1104);
  player->ADD_GOSSIP_ITEM( 5, "Undercity"                    , GOSSIP_SENDER_MAIN, 1105);
  player->ADD_GOSSIP_ITEM( 5, "Goldshire (Stormwind)"        , GOSSIP_SENDER_MAIN, 1106);
  player->ADD_GOSSIP_ITEM( 7, "<- [Back]"                    , GOSSIP_SENDER_MAIN, 1099);
  player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"               , GOSSIP_SENDER_MAIN, 2000);

  player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,pCreature->GetGUID());
break;			

case 1200: //Instances 1-60
  player->ADD_GOSSIP_ITEM( 5, "The Wailing Caverns"     , GOSSIP_SENDER_MAIN, 1201);
  player->ADD_GOSSIP_ITEM( 5, "Deadmines"               , GOSSIP_SENDER_MAIN, 1202);
  player->ADD_GOSSIP_ITEM( 5, "Shadowfang Keep"         , GOSSIP_SENDER_MAIN, 1203);
  player->ADD_GOSSIP_ITEM( 5, "Blackfathom Deeps"       , GOSSIP_SENDER_MAIN, 1204);
  player->ADD_GOSSIP_ITEM( 5, "Razorfen Kraul"          , GOSSIP_SENDER_MAIN, 1205);
  player->ADD_GOSSIP_ITEM( 5, "Razorfen Downs"          , GOSSIP_SENDER_MAIN, 1206);
  player->ADD_GOSSIP_ITEM( 5, "Scarlet Monastery"       , GOSSIP_SENDER_MAIN, 1207);
  player->ADD_GOSSIP_ITEM( 5, "Uldaman"                 , GOSSIP_SENDER_MAIN, 1208);
  player->ADD_GOSSIP_ITEM( 7, "[More Instances] ->"     , GOSSIP_SENDER_MAIN, 2001);
  player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"          , GOSSIP_SENDER_MAIN, 2000);

  player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,pCreature->GetGUID());
break;

case 2001: //More Instances 1-60
  player->ADD_GOSSIP_ITEM( 5, "Zul'Farrak"                , GOSSIP_SENDER_MAIN, 1209);
  player->ADD_GOSSIP_ITEM( 5, "Maraudon"                  , GOSSIP_SENDER_MAIN, 1210);
  player->ADD_GOSSIP_ITEM( 5, "The Sunken Temple"         , GOSSIP_SENDER_MAIN, 1211);
  player->ADD_GOSSIP_ITEM( 5, "Blackrock Depths"          , GOSSIP_SENDER_MAIN, 1212);
  player->ADD_GOSSIP_ITEM( 5, "Dire Maul"                 , GOSSIP_SENDER_MAIN, 1213);
  player->ADD_GOSSIP_ITEM( 5, "Blackrock Spire"           , GOSSIP_SENDER_MAIN, 1214);
  player->ADD_GOSSIP_ITEM( 5, "Stratholme"                , GOSSIP_SENDER_MAIN, 1215);
  player->ADD_GOSSIP_ITEM( 5, "Scholomance"               , GOSSIP_SENDER_MAIN, 1216);
  player->ADD_GOSSIP_ITEM( 7, "<- [Back]"                 , GOSSIP_SENDER_MAIN, 1200);
  player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"            , GOSSIP_SENDER_MAIN, 2000);

  player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,pCreature->GetGUID());
break;

case 1300: // Instances 60-70
  player->ADD_GOSSIP_ITEM( 5, "Zul'Gurub"               , GOSSIP_SENDER_MAIN, 1301);
  player->ADD_GOSSIP_ITEM( 5, "Onyxia's Lair"           , GOSSIP_SENDER_MAIN, 1302);
  player->ADD_GOSSIP_ITEM( 5, "Molten Core"             , GOSSIP_SENDER_MAIN, 1303);
  player->ADD_GOSSIP_ITEM( 5, "Blackwing Lair"          , GOSSIP_SENDER_MAIN, 1304);
  player->ADD_GOSSIP_ITEM( 5, "Ruins of Ahn'Qiraj"      , GOSSIP_SENDER_MAIN, 1305);
  player->ADD_GOSSIP_ITEM( 5, "Temple of Ahn'Qiraj"     , GOSSIP_SENDER_MAIN, 1306);
  player->ADD_GOSSIP_ITEM( 5, "Naxxramas"               , GOSSIP_SENDER_MAIN, 1307);
  player->ADD_GOSSIP_ITEM( 5, "Karazhan"                , GOSSIP_SENDER_MAIN, 1308);
  player->ADD_GOSSIP_ITEM( 5, "Gruul's Lair"            , GOSSIP_SENDER_MAIN, 1309);
  player->ADD_GOSSIP_ITEM( 5, "Hellfire Citadel"        , GOSSIP_SENDER_MAIN, 1310);
  player->ADD_GOSSIP_ITEM( 5, "Coilfang Reservoir"      , GOSSIP_SENDER_MAIN, 1311);
  player->ADD_GOSSIP_ITEM( 5, "Tempest Keep"            , GOSSIP_SENDER_MAIN, 1312);
  player->ADD_GOSSIP_ITEM( 5, "Caverns of Time"         , GOSSIP_SENDER_MAIN, 1313);
  player->ADD_GOSSIP_ITEM( 5, "Zul'Aman"                , GOSSIP_SENDER_MAIN, 1314);
  player->ADD_GOSSIP_ITEM( 5, "Black Temple"            , GOSSIP_SENDER_MAIN, 1315);
  player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"          , GOSSIP_SENDER_MAIN, 2000);
  
player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,pCreature->GetGUID());
break;

case 1400: // Instances 80+
  player->ADD_GOSSIP_ITEM( 5, "The Culling"             , GOSSIP_SENDER_MAIN, 1401);
  player->ADD_GOSSIP_ITEM( 5, "The Oculus"              , GOSSIP_SENDER_MAIN, 1402);
  player->ADD_GOSSIP_ITEM( 5, "Halls of Lightning"      , GOSSIP_SENDER_MAIN, 1403);
  player->ADD_GOSSIP_ITEM( 5, "Utgarde Pinnacle"        , GOSSIP_SENDER_MAIN, 1404);
  player->ADD_GOSSIP_ITEM( 5, "Halls of Stone"          , GOSSIP_SENDER_MAIN, 1405);
  player->ADD_GOSSIP_ITEM( 5, "Gundrak"                 , GOSSIP_SENDER_MAIN, 1406);
  player->ADD_GOSSIP_ITEM( 5, "The Violet Hold"         , GOSSIP_SENDER_MAIN, 1407);
  player->ADD_GOSSIP_ITEM( 5, "DrakTharon Keep"         , GOSSIP_SENDER_MAIN, 1408);
  player->ADD_GOSSIP_ITEM( 5, "Old Kingdom"             , GOSSIP_SENDER_MAIN, 1409);
  player->ADD_GOSSIP_ITEM( 5, "Azjol Nerub"             , GOSSIP_SENDER_MAIN, 1410);
  player->ADD_GOSSIP_ITEM( 5, "The Nexus"               , GOSSIP_SENDER_MAIN, 1411);
  player->ADD_GOSSIP_ITEM( 5, "Utgarde Keep"            , GOSSIP_SENDER_MAIN, 1412);
  player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"          , GOSSIP_SENDER_MAIN, 2000);

  player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,pCreature->GetGUID());
break;

case 1500: //Raids 80+
  player->ADD_GOSSIP_ITEM( 5, "Naxxaramas"                , GOSSIP_SENDER_MAIN, 1307);
  player->ADD_GOSSIP_ITEM( 5, "Eye of Eternity"           , GOSSIP_SENDER_MAIN, 1501);
  player->ADD_GOSSIP_ITEM( 5, "Obsidian Sanctum"          , GOSSIP_SENDER_MAIN, 1502);
  player->ADD_GOSSIP_ITEM( 5, "Vault of Archavon"         , GOSSIP_SENDER_MAIN, 1503);
  player->ADD_GOSSIP_ITEM( 5, "Gates of Ulduar"           , GOSSIP_SENDER_MAIN, 1504);
  player->ADD_GOSSIP_ITEM( 5, "The Frozen Halls"          , GOSSIP_SENDER_MAIN, 1505);
  player->ADD_GOSSIP_ITEM( 5, "Trial of the Champion"     , GOSSIP_SENDER_MAIN, 1507);
  player->ADD_GOSSIP_ITEM( 5, "Trial of the Crusader"     , GOSSIP_SENDER_MAIN, 1507);
  player->ADD_GOSSIP_ITEM( 5, "Icecrown Citadel"          , GOSSIP_SENDER_MAIN, 1506);
  player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"            , GOSSIP_SENDER_MAIN, 2000);

  player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,pCreature->GetGUID());
break;

case 1600: // Cata Dungeons & Raids
  player->ADD_GOSSIP_ITEM( 5, "Throne of the Tides"          , GOSSIP_SENDER_MAIN, 1601);
  player->ADD_GOSSIP_ITEM( 5, "Blackrock Caverns"            , GOSSIP_SENDER_MAIN, 1602);
  player->ADD_GOSSIP_ITEM( 5, "Grim batol"                   , GOSSIP_SENDER_MAIN, 1603);
  player->ADD_GOSSIP_ITEM( 5, "Halls of Origination"         , GOSSIP_SENDER_MAIN, 1604);
  player->ADD_GOSSIP_ITEM( 5, "Stonecore"                    , GOSSIP_SENDER_MAIN, 1605);
  player->ADD_GOSSIP_ITEM( 5, "The Vortex Pinnacle"          , GOSSIP_SENDER_MAIN, 1606);
  //player->ADD_GOSSIP_ITEM( 5, "Lost City of the Tol'vir"   , GOSSIP_SENDER_MAIN, 1607);
  player->ADD_GOSSIP_ITEM( 5, "The Bastion of Twilight"      , GOSSIP_SENDER_MAIN, 1620);
  player->ADD_GOSSIP_ITEM( 5, "Blackwing Descent"            , GOSSIP_SENDER_MAIN, 1621);
  //player->ADD_GOSSIP_ITEM( 5, "Baradin"           , GOSSIP_SENDER_MAIN, 1622);
  //player->ADD_GOSSIP_ITEM( 5, "Throne"           , GOSSIP_SENDER_MAIN, 1623); 
  player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"               , GOSSIP_SENDER_MAIN, 2000);      

  player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,pCreature->GetGUID());
break;

case 1700: // Battlegrounds and Arenas
  player->ADD_GOSSIP_ITEM( 5, "Warsong Gulch"                 , GOSSIP_SENDER_MAIN, 1701);
  player->ADD_GOSSIP_ITEM( 5, "Arathi Basin"                  , GOSSIP_SENDER_MAIN, 1702);
  player->ADD_GOSSIP_ITEM( 5, "Alterac Valley"                , GOSSIP_SENDER_MAIN, 1703);
  player->ADD_GOSSIP_ITEM( 5, "Eye of the Storm"              , GOSSIP_SENDER_MAIN, 1704);
  player->ADD_GOSSIP_ITEM( 5, "Gurubashi Arena"               , GOSSIP_SENDER_MAIN, 1705);
  player->ADD_GOSSIP_ITEM( 5, "Circle of Blood Arena"         , GOSSIP_SENDER_MAIN, 1706);
  player->ADD_GOSSIP_ITEM( 5, "Ring of Trials"                , GOSSIP_SENDER_MAIN, 1707);
  player->ADD_GOSSIP_ITEM( 5, "The Maul"                      , GOSSIP_SENDER_MAIN, 1708);
  player->ADD_GOSSIP_ITEM( 5, "Wintergrasp"                   , GOSSIP_SENDER_MAIN, 1709);
  player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"                , GOSSIP_SENDER_MAIN, 2000);

  player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,pCreature->GetGUID());
break;

case 1800: // Testing and Development / Unused Areas
  player->ADD_GOSSIP_ITEM( 5, "Lost Isles of Maelstorm"              , GOSSIP_SENDER_MAIN, 1801);
  player->ADD_GOSSIP_ITEM( 5, "Deepholm"                             , GOSSIP_SENDER_MAIN, 1802);
  player->ADD_GOSSIP_ITEM( 5, "Stonetalon Bomb"                      , GOSSIP_SENDER_MAIN, 1803);
  player->ADD_GOSSIP_ITEM( 5, "Twilight Highlands Dragonmaw Phase"   , GOSSIP_SENDER_MAIN, 1804);
  player->ADD_GOSSIP_ITEM( 5, "Lost Isle: Town in a box"             , GOSSIP_SENDER_MAIN, 1805);
  player->ADD_GOSSIP_ITEM( 5, "Lost Isle: Volcanoe Eruption"         , GOSSIP_SENDER_MAIN, 1806);
  player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"                       , GOSSIP_SENDER_MAIN, 2000);

  player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,pCreature->GetGUID());
break;   

case 2000: //Back To Main Menu

	 player->PlayerTalkClass->ClearMenus();    /* 11/05/2010 niteowl57:  For 3.3.5a, fix menu functionality  */
    if ( player->GetTeam() == ALLIANCE ) // Main menu for Alliance
  {
    player->ADD_GOSSIP_ITEM( 3, "[ Item Requester  ] ->"             , GOSSIP_SENDER_MAIN, 60);
	player->ADD_GOSSIP_ITEM( 9, "[ Explore Azeroth ] ->"                       , GOSSIP_SENDER_MAIN, 1098);
    player->ADD_GOSSIP_ITEM( 7, "[ Choose Your Morph! ] ->"                    , GOSSIP_SENDER_MAIN, 700);
    player->ADD_GOSSIP_ITEM( 2, "[ Buffs, Heals, Food & Gold ] ->"             , GOSSIP_SENDER_MAIN, 2100);
    player->ADD_GOSSIP_ITEM( 3, "[ Profession & Class Trainers ] ->"           , GOSSIP_SENDER_MAIN, 300);
    }
  else // Main menu for Horde
  {
    player->ADD_GOSSIP_ITEM( 3, "[ Item Requester  ] ->"             , GOSSIP_SENDER_MAIN, 60);
	player->ADD_GOSSIP_ITEM( 9, "[ Explore Azeroth ] ->"                       , GOSSIP_SENDER_MAIN, 1099);
    player->ADD_GOSSIP_ITEM( 7, "[ Choose Your Morph! ] ->"                    , GOSSIP_SENDER_MAIN, 700);
    player->ADD_GOSSIP_ITEM( 2, "[ Buffs, Heals & Food ] ->"                   , GOSSIP_SENDER_MAIN, 2100);
    player->ADD_GOSSIP_ITEM( 3, "[ Profession & Class Trainers ] ->"           , GOSSIP_SENDER_MAIN, 300);
  }
if(player->getClass() == CLASS_HUNTER)
        player->ADD_GOSSIP_ITEM(4, "Get a New Pet.", GOSSIP_SENDER_MAIN, 30);
        if (player->CanTameExoticPets())
        {
            player->ADD_GOSSIP_ITEM(4, "Get a New Exotic Pet.", GOSSIP_SENDER_MAIN, 50);
        }
  player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,pCreature->GetGUID());

break;

case 2100: // Npc Buff Menu
        player->ADD_GOSSIP_ITEM( 7, "Low Level Buffs"                        , GOSSIP_SENDER_MAIN, 2150);
		player->ADD_GOSSIP_ITEM( 7, "High Level Buffs"                       , GOSSIP_SENDER_MAIN, 2200);
		player->ADD_GOSSIP_ITEM( 7, "Game Master Buffs"                      , GOSSIP_SENDER_MAIN, 2300);
		player->ADD_GOSSIP_ITEM( 7, "Gold, Shards, Healing"                  , GOSSIP_SENDER_MAIN, 2400);
		player->ADD_GOSSIP_ITEM( 7, "<- [Back]"                                , GOSSIP_SENDER_MAIN, 2000);
		
		player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,pCreature->GetGUID());
break; 

case 2150: //Small  Buff
		player->ADD_GOSSIP_ITEM( 5, "Buff me Mark of the Wild"                , GOSSIP_SENDER_MAIN, 2101);
		player->ADD_GOSSIP_ITEM( 5, "Buff me Thorns"                          , GOSSIP_SENDER_MAIN, 2102);
		player->ADD_GOSSIP_ITEM( 5, "Buff me Amplify Magic"                   , GOSSIP_SENDER_MAIN, 2103);
		player->ADD_GOSSIP_ITEM( 5, "Buff me Arcane Intellect"                , GOSSIP_SENDER_MAIN, 2104);
		player->ADD_GOSSIP_ITEM( 5, "Buff me Dalaran Intellect"               , GOSSIP_SENDER_MAIN, 2105);
		player->ADD_GOSSIP_ITEM( 5, "Buff me Dampen Magic"                    , GOSSIP_SENDER_MAIN, 2106);
		player->ADD_GOSSIP_ITEM( 5, "Buff me Blessing of Kings"               , GOSSIP_SENDER_MAIN, 2107);
		player->ADD_GOSSIP_ITEM( 5, "Buff me Blessing of Might"               , GOSSIP_SENDER_MAIN, 2108);
		player->ADD_GOSSIP_ITEM( 5, "Buff me Blessing of Wisdom"              , GOSSIP_SENDER_MAIN, 2109);
		player->ADD_GOSSIP_ITEM( 5, "Buff me Divine Spirit"                   , GOSSIP_SENDER_MAIN, 2110);
		player->ADD_GOSSIP_ITEM( 5, "Buff me Power Word: Fortitude"           , GOSSIP_SENDER_MAIN, 2111);
    	player->ADD_GOSSIP_ITEM( 5, "Buff me Shadow Protection"               , GOSSIP_SENDER_MAIN, 2112);
		player->ADD_GOSSIP_ITEM( 7, "<- [Buff Menu]"                          , GOSSIP_SENDER_MAIN, 2100);
		player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"                          , GOSSIP_SENDER_MAIN, 2000);

	player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,pCreature->GetGUID());
break;

case 2200: //Great Buff
		player->ADD_GOSSIP_ITEM( 5, "Buff me Mark of the Wild"                , GOSSIP_SENDER_MAIN, 2201);
		player->ADD_GOSSIP_ITEM( 5, "Buff me Arcane Brilliance"               , GOSSIP_SENDER_MAIN, 2202);
		player->ADD_GOSSIP_ITEM( 5, "Buff me Dalaran Brilliance"              , GOSSIP_SENDER_MAIN, 2203);
		player->ADD_GOSSIP_ITEM( 5, "Buff me Greater Blessing of Kings"       , GOSSIP_SENDER_MAIN, 2204);
		player->ADD_GOSSIP_ITEM( 5, "Buff me Greater Blessing of Might"       , GOSSIP_SENDER_MAIN, 2205);
		player->ADD_GOSSIP_ITEM( 5, "Buff me Greater Blessing of Sanctuary"   , GOSSIP_SENDER_MAIN, 2206);
		player->ADD_GOSSIP_ITEM( 5, "Buff me Greater Blessing of Wisdom"      , GOSSIP_SENDER_MAIN, 2207);
		player->ADD_GOSSIP_ITEM( 5, "Buff me Prayer of Fortitude"             , GOSSIP_SENDER_MAIN, 2208);
		player->ADD_GOSSIP_ITEM( 5, "Buff me Prayer of Shadow Protection"     , GOSSIP_SENDER_MAIN, 2209);
		player->ADD_GOSSIP_ITEM( 5, "Buff me Prayer of Spirit"                , GOSSIP_SENDER_MAIN, 2210);
		player->ADD_GOSSIP_ITEM( 7, "<- [Buff Menu]"                            , GOSSIP_SENDER_MAIN, 2100);
		player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"                        , GOSSIP_SENDER_MAIN, 2000);

	player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,pCreature->GetGUID());
break;

case 2300: //GM  Buff
		player->ADD_GOSSIP_ITEM( 5, "Buff me Agamaggan's Agility"             , GOSSIP_SENDER_MAIN, 2301);
		player->ADD_GOSSIP_ITEM( 5, "Buff me Agamaggan's Strength"            , GOSSIP_SENDER_MAIN, 2302);
		player->ADD_GOSSIP_ITEM( 5, "Buff me Armor Magic"                     , GOSSIP_SENDER_MAIN, 2303);
		player->ADD_GOSSIP_ITEM( 5, "Buff me Armor Penetration"               , GOSSIP_SENDER_MAIN, 2304);
		player->ADD_GOSSIP_ITEM( 5, "Buff me Increased Stamina"               , GOSSIP_SENDER_MAIN, 2305);
		player->ADD_GOSSIP_ITEM( 5, "Buff me Razorhide"                       , GOSSIP_SENDER_MAIN, 2306);
		player->ADD_GOSSIP_ITEM( 5, "Buff me Rising Spirit"                   , GOSSIP_SENDER_MAIN, 2307);
		player->ADD_GOSSIP_ITEM( 5, "Buff me Spirit of the Wind"              , GOSSIP_SENDER_MAIN, 2308);
    	player->ADD_GOSSIP_ITEM( 5, "Buff me Wisdom of Agamaggan"             , GOSSIP_SENDER_MAIN, 2309);
		player->ADD_GOSSIP_ITEM( 7, "<- [Buff Menu]"                            , GOSSIP_SENDER_MAIN, 2100);
		player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"                        , GOSSIP_SENDER_MAIN, 2000);

	player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,pCreature->GetGUID());
break;

case 2400: //Player Tools
		player->ADD_GOSSIP_ITEM( 5, "Give me Gold"                            , GOSSIP_SENDER_MAIN, 2401);
		player->ADD_GOSSIP_ITEM( 5, "Give me Soul Shards"                     , GOSSIP_SENDER_MAIN, 2402);
		player->ADD_GOSSIP_ITEM( 5, "Heal me Please"                          , GOSSIP_SENDER_MAIN, 2403);
		player->ADD_GOSSIP_ITEM( 5, "Heal me and party members Please"        , GOSSIP_SENDER_MAIN, 2404);
		player->ADD_GOSSIP_ITEM( 5, "Conjure Refreshment"                     , GOSSIP_SENDER_MAIN, 2405);
		player->ADD_GOSSIP_ITEM( 5, "Conjure Mana Gem"                        , GOSSIP_SENDER_MAIN, 2406);
		player->ADD_GOSSIP_ITEM( 9, "Remove Resurrect Sickness" 				  , GOSSIP_SENDER_MAIN, 2407);
		player->ADD_GOSSIP_ITEM( 7, "<- [Buff Menu]"                            , GOSSIP_SENDER_MAIN, 2100);
		player->ADD_GOSSIP_ITEM( 7, "<- [Main Menu]"                        , GOSSIP_SENDER_MAIN, 2000);

	player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,pCreature->GetGUID());
break;

case 2500: //Profession
            player->ADD_GOSSIP_ITEM(3, "Alchemy."              , GOSSIP_SENDER_MAIN, 2501);
            player->ADD_GOSSIP_ITEM(3, "Blacksmithing."        , GOSSIP_SENDER_MAIN, 2502);
            player->ADD_GOSSIP_ITEM(3, "Enchanting."           , GOSSIP_SENDER_MAIN, 2503);
            player->ADD_GOSSIP_ITEM(3, "Engineering."          , GOSSIP_SENDER_MAIN, 2504);
            player->ADD_GOSSIP_ITEM(3, "Herbalism."            , GOSSIP_SENDER_MAIN, 2505);
            player->ADD_GOSSIP_ITEM(3, "Inscription."          , GOSSIP_SENDER_MAIN, 2506);
            player->ADD_GOSSIP_ITEM(3, "Jewelcrafting."        , GOSSIP_SENDER_MAIN, 2507);
            player->ADD_GOSSIP_ITEM(3, "Leatherworking."       , GOSSIP_SENDER_MAIN, 2508);
            player->ADD_GOSSIP_ITEM(3, "Mining."               , GOSSIP_SENDER_MAIN, 2509);
            player->ADD_GOSSIP_ITEM(3, "Skinning."             , GOSSIP_SENDER_MAIN, 2510);
            player->ADD_GOSSIP_ITEM(3, "Tailoring."            , GOSSIP_SENDER_MAIN, 2511);
			player->ADD_GOSSIP_ITEM(7, "<- Back"               , GOSSIP_SENDER_MAIN, 200);
            player->ADD_GOSSIP_ITEM(7, "<- Main Menu"          , GOSSIP_SENDER_MAIN, 2000);

	player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,pCreature->GetGUID());
break;

case 2550: //Secondary Skills
            player->ADD_GOSSIP_ITEM(3, "Cooking."              , GOSSIP_SENDER_MAIN, 2551);
            player->ADD_GOSSIP_ITEM(3, "First Aid."            , GOSSIP_SENDER_MAIN, 2552);
            player->ADD_GOSSIP_ITEM(3, "Fishing."              , GOSSIP_SENDER_MAIN, 2553);
          //player->ADD_GOSSIP_ITEM(3, "Riding."               , GOSSIP_SENDER_MAIN, 2554);
			player->ADD_GOSSIP_ITEM(7, "<- Back"               , GOSSIP_SENDER_MAIN, 200);
            player->ADD_GOSSIP_ITEM(7, "<- Main Menu"          , GOSSIP_SENDER_MAIN, 2000);

	player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,pCreature->GetGUID());
break;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

 
            
            case 1: //bear
                CreatePet(player, pCreature, 29319);
            break;
            case 2: //Boar
                CreatePet(player, pCreature, 29996);
            break;
            case 3: //Bug
                CreatePet(player, pCreature, 28085);
                        break;
            case 4: //cat
                CreatePet(player, pCreature, 28097);
                        break;
            case 5: //carrion
                CreatePet(player, pCreature, 26838);
                        break;
            case 6: //crab
                CreatePet(player, pCreature, 24478);
                        break;   
            case 7: //crocolisk
                CreatePet(player, pCreature, 1417);
                        break;  
            case 8: //gorila
                CreatePet(player, pCreature, 28213);
                        break;
            case 9: //hound
                CreatePet(player, pCreature, 29452);
                        break;
            case 10: //hynea
                CreatePet(player, pCreature, 13036);
                        break;
            case 11: //Moth
                CreatePet(player, pCreature, 27421);
                        break;
            case 12: //owl
                CreatePet(player, pCreature, 23136);
                        break;
            case 13: //strider
                CreatePet(player, pCreature, 22807);
                        break;
            case 14: //scorpid
                CreatePet(player, pCreature, 9698);
                        break;
            case 15: //turtle
                CreatePet(player, pCreature, 25482);
                        break;
                        
            case 16: //Spider
                CreatePet(player, pCreature, 2349);
            break;
            case 17: //Dragonhawk
                CreatePet(player, pCreature, 27946);
            break;
            case 18: //Bat
                CreatePet(player, pCreature, 28233);
            break;
            case 19: //Ravager
                CreatePet(player, pCreature, 17199);
            break;
            case 20: //Raptor
                CreatePet(player, pCreature, 14821);
            break;
            case 21: //Serpent
                CreatePet(player, pCreature, 28358);
            break;           

			case 51: //chimera
                CreatePet(player, pCreature, 21879);
            break;
            case 52: //core hound
                CreatePet(player, pCreature, 21108);
            break;
            case 53: //Devilsaur
                CreatePet(player, pCreature, 20931);
            break;
            case 54: //rhino
                CreatePet(player, pCreature, 30445);
            break;
            case 55: //silithid
                CreatePet(player, pCreature, 5460);
            break;
            case 56: //Worm
                CreatePet(player, pCreature, 30148);
            break;
            case 57: //Loque'nahak
                CreatePet(player, pCreature, 32517);
            break;
            case 58: //Skoll
                CreatePet(player, pCreature, 35189);
            break;
            case 59: //Gondria
                CreatePet(player, pCreature, 33776);
            break;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//  Misc Trainers

case 301: // Riding Trainer
    player->CLOSE_GOSSIP_MENU();
	player->SummonCreature(31238,player->GetPositionX() ,player->GetPositionY(), player->GetPositionZ(), 0,TEMPSUMMON_TIMED_DESPAWN,120000);
break;

case 302: // Stable Master
    player->CLOSE_GOSSIP_MENU();
	player->SummonCreature(28690,player->GetPositionX() ,player->GetPositionY(), player->GetPositionZ(), 0,TEMPSUMMON_TIMED_DESPAWN,120000);
break;

case 303: // Weapon Master
    player->CLOSE_GOSSIP_MENU();
	player->SummonCreature(12704,player->GetPositionX() ,player->GetPositionY(), player->GetPositionZ(), 0,TEMPSUMMON_TIMED_DESPAWN,120000);
break;



//////////////////////////////////////////////////Trainers ///////////////////////////////////////////////////////////////

//////////////////////////////////////////////////Class ///////////////////////////////////////////////////////////////
case 401: // Death Knight
    player->CLOSE_GOSSIP_MENU();
	player->SummonCreature(28474,player->GetPositionX() ,player->GetPositionY(), player->GetPositionZ(), 0,TEMPSUMMON_TIMED_DESPAWN,120000);
break;

case 402: // Druid
    player->CLOSE_GOSSIP_MENU();
	player->SummonCreature(4217,player->GetPositionX() ,player->GetPositionY(), player->GetPositionZ(), 0,TEMPSUMMON_TIMED_DESPAWN,120000);
break;

case 403: // Hunter
    player->CLOSE_GOSSIP_MENU();
	player->SummonCreature(5116,player->GetPositionX() ,player->GetPositionY(), player->GetPositionZ(), 0,TEMPSUMMON_TIMED_DESPAWN,120000);
break;

case 404: // Mage
    player->CLOSE_GOSSIP_MENU();
	player->SummonCreature(7312,player->GetPositionX() ,player->GetPositionY(), player->GetPositionZ(), 0,TEMPSUMMON_TIMED_DESPAWN,120000);
break;

case 405: // Paladin
    player->CLOSE_GOSSIP_MENU();
	player->SummonCreature(5149,player->GetPositionX() ,player->GetPositionY(), player->GetPositionZ(), 0,TEMPSUMMON_TIMED_DESPAWN,120000);
break;

case 406: // Priest
    player->CLOSE_GOSSIP_MENU();
	player->SummonCreature(4090,player->GetPositionX() ,player->GetPositionY(), player->GetPositionZ(), 0,TEMPSUMMON_TIMED_DESPAWN,120000);
break;

case 407: // Rogue
    player->CLOSE_GOSSIP_MENU();
	player->SummonCreature(5167,player->GetPositionX() ,player->GetPositionY(), player->GetPositionZ(), 0,TEMPSUMMON_TIMED_DESPAWN,120000);
break;

case 408: // Shaman
    player->CLOSE_GOSSIP_MENU();
	player->SummonCreature(23127,player->GetPositionX() ,player->GetPositionY(), player->GetPositionZ(), 0,TEMPSUMMON_TIMED_DESPAWN,120000);
break;

case 409: // Warlock
    player->CLOSE_GOSSIP_MENU();
	player->SummonCreature(5172,player->GetPositionX() ,player->GetPositionY(), player->GetPositionZ(), 0,TEMPSUMMON_TIMED_DESPAWN,120000);
break;

case 410: // Warrior
    player->CLOSE_GOSSIP_MENU();
	player->SummonCreature(5114,player->GetPositionX() ,player->GetPositionY(), player->GetPositionZ(), 0,TEMPSUMMON_TIMED_DESPAWN,120000);
break;

//////////////////////////////////////////////////Profession and Extras ///////////////////////////////////////////////////////////////

case 501: // Alchemy
    player->CLOSE_GOSSIP_MENU();
	player->SummonCreature(33630,player->GetPositionX() ,player->GetPositionY(), player->GetPositionZ(), 0,TEMPSUMMON_TIMED_DESPAWN,120000);
	player->SummonCreature(28703,player->GetPositionX() ,player->GetPositionY(), player->GetPositionZ(), 0,TEMPSUMMON_TIMED_DESPAWN,120000);
break;

case 502: // Blacksmithing
    player->CLOSE_GOSSIP_MENU();
	player->SummonCreature(28694,player->GetPositionX() ,player->GetPositionY(), player->GetPositionZ(), 0,TEMPSUMMON_TIMED_DESPAWN,120000);
break;

case 503: // Enchanting
    player->CLOSE_GOSSIP_MENU();
	player->SummonCreature(28693,player->GetPositionX() ,player->GetPositionY(), player->GetPositionZ(), 0,TEMPSUMMON_TIMED_DESPAWN,120000);
	player->SummonCreature(33633,player->GetPositionX() ,player->GetPositionY(), player->GetPositionZ(), 0,TEMPSUMMON_TIMED_DESPAWN,120000);
break;

case 504: // Engineering
    player->CLOSE_GOSSIP_MENU();
	player->SummonCreature(28697,player->GetPositionX() ,player->GetPositionY(), player->GetPositionZ(), 0,TEMPSUMMON_TIMED_DESPAWN,120000);
break;

case 505: // Herbalism
    player->CLOSE_GOSSIP_MENU();
	player->SummonCreature(28704,player->GetPositionX() ,player->GetPositionY(), player->GetPositionZ(), 0,TEMPSUMMON_TIMED_DESPAWN,120000);
break;

case 506: // Inscription
    player->CLOSE_GOSSIP_MENU();
	player->SummonCreature(28702,player->GetPositionX() ,player->GetPositionY(), player->GetPositionZ(), 0,TEMPSUMMON_TIMED_DESPAWN,120000);
break;

case 507: // Jewelcrafting
    player->CLOSE_GOSSIP_MENU();
	player->SummonCreature(28701,player->GetPositionX() ,player->GetPositionY(), player->GetPositionZ(), 0,TEMPSUMMON_TIMED_DESPAWN,120000);
break;

case 508: // Leatherworking
    player->CLOSE_GOSSIP_MENU();
	player->SummonCreature(28700,player->GetPositionX() ,player->GetPositionY(), player->GetPositionZ(), 0,TEMPSUMMON_TIMED_DESPAWN,120000);
break;

case 509: // Mining
    player->CLOSE_GOSSIP_MENU();
	player->SummonCreature(28698,player->GetPositionX() ,player->GetPositionY(), player->GetPositionZ(), 0,TEMPSUMMON_TIMED_DESPAWN,120000);
break;

case 510: // Skinning
    player->CLOSE_GOSSIP_MENU();
	player->SummonCreature(28696,player->GetPositionX() ,player->GetPositionY(), player->GetPositionZ(), 0,TEMPSUMMON_TIMED_DESPAWN,120000);
break;

case 511: // Tailoring
    player->CLOSE_GOSSIP_MENU();
	player->SummonCreature(28699,player->GetPositionX() ,player->GetPositionY(), player->GetPositionZ(), 0,TEMPSUMMON_TIMED_DESPAWN,120000);
break;

case 512: // Cooking
    player->CLOSE_GOSSIP_MENU();
	player->SummonCreature(28705,player->GetPositionX() ,player->GetPositionY(), player->GetPositionZ(), 0,TEMPSUMMON_TIMED_DESPAWN,120000);
break;

case 513: // First Aid
    player->CLOSE_GOSSIP_MENU();
	player->SummonCreature(28706,player->GetPositionX() ,player->GetPositionY(), player->GetPositionZ(), 0,TEMPSUMMON_TIMED_DESPAWN,120000);;
break;

case 514: // Fishing
    player->CLOSE_GOSSIP_MENU();
	player->SummonCreature(28742,player->GetPositionX() ,player->GetPositionY(), player->GetPositionZ(), 0,TEMPSUMMON_TIMED_DESPAWN,120000);
break;


//////////////////////////////////////////////////Morph ///////////////////////////////////////////////////////////////

//////////////////////////////////////////////////Famous ///////////////////////////////////////////////////////////////

case 711: // Algalon
    player->CLOSE_GOSSIP_MENU();
	player->SetDisplayId(28641);
	player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.2f);
break;

case 712: // Doomwalker
    player->CLOSE_GOSSIP_MENU();
	player->SetDisplayId(16630);
	player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.1f);
break;

case 713: // Doomlord kazzak
    player->CLOSE_GOSSIP_MENU();
	player->SetDisplayId(17887);
	player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.10f);
break;

case 714: // Onyxia
    player->CLOSE_GOSSIP_MENU();
	player->SetDisplayId(8570);
	player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.1f);
break;

case 715: // Thaddius
    player->CLOSE_GOSSIP_MENU();
	player->SetDisplayId(16137);
	player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.2f);
break;

case 716: // Gluth
    player->CLOSE_GOSSIP_MENU();
	player->SetDisplayId(16064);
	player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.2f);
break;

case 717: // Maexxna
    player->CLOSE_GOSSIP_MENU();
	player->SetDisplayId(15928);
	player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.15f);
break;

case 718: // Sapphiron
    player->CLOSE_GOSSIP_MENU();
	player->SetDisplayId(16033);
	player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.1f);
break;

case 719: // Noth The Plaguebringer
    player->CLOSE_GOSSIP_MENU();
	player->SetDisplayId(16590);
	player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.7f);
break;

case 720: // Kel'Thuzad
    player->CLOSE_GOSSIP_MENU();
	player->SetDisplayId(15945);
	player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.2f);
break;

case 721: // Kael'thas Sunstrider
    player->CLOSE_GOSSIP_MENU();
	player->SetDisplayId(20023);
	player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.5f);
break;

case 722: // C'thun
    player->CLOSE_GOSSIP_MENU();
	player->SetDisplayId(15786);
	player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.1f);
break;

case 723: // Thrall
    player->CLOSE_GOSSIP_MENU();
	player->SetDisplayId(4527);
	player->SetFloatValue(OBJECT_FIELD_SCALE_X, 1.0f);
break;

//////////////////////////////////////////////////Funny ///////////////////////////////////////////////////////////////

case 751: // Gerky
    player->CLOSE_GOSSIP_MENU();
	player->SetDisplayId(29348);
	player->SetFloatValue(OBJECT_FIELD_SCALE_X, 1.5f);
break;

case 752: // Water elemental
    player->CLOSE_GOSSIP_MENU();
	player->SetDisplayId(12129);
		player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.3f);
break;

case 753: // Pandaren Monk
    player->CLOSE_GOSSIP_MENU();
	player->SetDisplayId(30414);
	player->SetFloatValue(OBJECT_FIELD_SCALE_X, 1.5f);
break;

case 754: // Lil' K.T
	player->CLOSE_GOSSIP_MENU();
	player->DeMorph();
    player->SetDisplayId(30507);
	player->SetFloatValue(OBJECT_FIELD_SCALE_X, 1.5f);
break;

case 755: // The Weapon you're Wearing
    player->CLOSE_GOSSIP_MENU();
	player->SetDisplayId(15880);
	player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.4f);
break;

case 756: // Red Bubbles
    player->CLOSE_GOSSIP_MENU();
	player->SetDisplayId(20262);
	player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.5f);
break;

case 757: // A Shark
    player->CLOSE_GOSSIP_MENU();
	player->SetDisplayId(15555);
	player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.2f);
break;

case 758: // A Fel cannon
    player->CLOSE_GOSSIP_MENU();
	player->SetDisplayId(18505);
	player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.5f);
break;

case 759: // Human Female
    player->CLOSE_GOSSIP_MENU();
	player->SetDisplayId(100);
	player->SetFloatValue(OBJECT_FIELD_SCALE_X, 1.5f);
break;

case 760: // A Fat Human
    player->CLOSE_GOSSIP_MENU();
	player->SetDisplayId(103);
	player->SetFloatValue(OBJECT_FIELD_SCALE_X, 1.5f);
break;

case 761: // A Rabbit
    player->CLOSE_GOSSIP_MENU();
	player->SetDisplayId(328);
	player->SetFloatValue(OBJECT_FIELD_SCALE_X, 3.0f);
break;

case 762: // A Cool looking Bug
    player->CLOSE_GOSSIP_MENU();
	player->SetDisplayId(15695);
	player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.1f);
break;

case 763: // Eye Of C'thun
    player->CLOSE_GOSSIP_MENU();
	player->SetDisplayId(15556);
	player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.1f);
break;

case 769: // Drunk
    player->CLOSE_GOSSIP_MENU();
    player->CastSpell(player,46876,false);
    pCreature->MonsterSay("Mother always said, Don't Drink and Hunt!", LANG_UNIVERSAL, NULL);
break;

case 770: // Sober
    player->CLOSE_GOSSIP_MENU();
    player->SetDrunkValue(0, 9);
    pCreature->MonsterSay("How about some coffee to sober you up!", LANG_UNIVERSAL, NULL);

case 771: // Make me Bigger
    player->CLOSE_GOSSIP_MENU();
	player->SetFloatValue(OBJECT_FIELD_SCALE_X, 1.5f);
break;

case 772: // Make me Smaller
    player->CLOSE_GOSSIP_MENU();
	player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.5f);
break;

case 799: // DeMorph
    player->CLOSE_GOSSIP_MENU();
	player->DeMorph();
	player->SetFloatValue(OBJECT_FIELD_SCALE_X, 1.0f);
break;

           // Alliance Main Cities
case 1001:// Teleport to Dalaran
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(571, 5804.585f,624.726f,647.780f,1.820647f);
break;

case 1002: // Teleport to Darnassus
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(1, 9947.52f, 2482.73f, 1316.21f, 0.0f);
break;

// Teleport to Exodar
case 1003:
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(530, -4073.03f, -12020.4f, -1.47f, 0.0f);
break;

case 1004: //Cata Alliance City ( Gilneas Destroyed ) Worgen After Final Quest Phase
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(654, -1442.369f,1429.45f,36.52f,0.88095f);
  break;

// Teleport to Ironforge
case 1005:
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(0, -4924.07f, -951.95f, 501.55f, 5.40f);
break;

case 1006:// Shattrath City
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(530, -1850.209961f, 5435.821777f, -10.961435f, 3.403913f);
break;

// Teleport to Stormwind
case 1007:
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(0, -8960.14f, 516.266f, 96.3568f, 0.0f);
break;

case 1008:// Razor Hill  Ally Pvp
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(1, 315.721f, -4743.4f, 10.4867f, 0.0f);
break;

            // Horde Main Cities
             
case 1101: //Cata Horde City ( Kezan ) Goblin After Final Quest Phase
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(648, -8423.541f,1362.861f,105.6f,1.57705f);
  break;  

// Teleport to Orgrimmar
case 1102:
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(1, 1552.5f, -4420.66f, 8.94802f, 0.0f);
break;

// Teleport to Silvermoon
case 1103:
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(530, 9338.74f, -7277.27f, 13.7895f, 0.0f);
break;

// Teleport to Thunder Bluff
case 1104:
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(1, -1290.0f, 147.033997f, 129.682007f, 4.919000f);
break;

// Teleport to Undercity
case 1105:
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(0, 1819.71f, 238.79f, 60.5321f, 0.0f);
break;

case 1106:// Goldshire Horde Pvp 
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(0, -9464.0f, 62.0f, 56.0f, 0.0f);
break;

           // Classic Wow Instances Lvl 1 - 60

case 1201://teleport player to the Wailing Caverns
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(1, -722.53f,-2226.30f,16.94f,2.71f);
break;

case 1202://teleport player to the Deadmines
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(0, -11212.04f,1658.58f,25.67f,1.45f);
break;

case 1203://teleport player to Shadowfang Keep
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(0, -254.47f,1524.68f,76.89f,1.56f);
break;

case 1204://teleport player to Blackfathom Deeps
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(1, 4254.58f,664.74f,-29.04f,1.97f);
break;

case 1205://teleport player to Razorfen Kraul
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(1, -4484.04f,-1739.40f,86.47f,1.23f);
break;

case 1206://teleport player to Razorfen Downs
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(1, -4645.08f,-2470.85f,85.53f,4.39f);
break;

case 1207://teleport player to the Scarlet Monastery
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(0, 2843.89f,-693.74f,139.32f,5.11f);
break;

case 1208://teleport player to Uldaman
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(0, -6119.70f,-2957.30f,204.11f,0.03f);
break;

case 1209://teleport player to Zul'Farrak
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(1, -6839.39f,-2911.03f,8.87f,0.41f);
break;

case 1210://teleport player to Maraudon
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(1, -1433.33f,2955.34f,96.21f,4.82f);
break;

case 1211://teleport player to the Sunken Temple
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(0, -10346.92f,-3851.90f,-43.41f,6.09f);
break;

case 1212://teleport player to Blackrock Depths
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(0, -7301.03f,-913.19f,165.37f,0.08f);
break;

case 1213://teleport player to Dire Maul
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(1, -3982.47f,1127.79f,161.02f,0.05f);
break;

case 1214://teleport player to Blackrock Spire
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(0, -7535.43f,-1212.04f,285.45f,5.29f);
break;

case 1215://teleport player to Stratholme
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(0, 3263.54f,-3379.46f,143.59f,0.00f);
break;

case 1216://teleport player to Scholomance
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(0, 1219.01f,-2604.66f,85.61f,0.50f);
break;

          // TBC & Wotlk Level 60-79

case 1301:// Teleport to Zul'Gurub
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(0, -11916.7f, -1212.82f, 92.2868f, 4.6095f);
break;

case 1302:// Teleport to Onyxia's Lair
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(1, -4707.44f, -3726.82f, 54.6723f, 3.8f);
break;

case 1303:// Teleport to Molten Core
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(230, 1121.451172f, -454.316772f, -101.329536f, 3.5f);
break;

case 1304:// Teleport to Blackwing Lair
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(469, -7665.55f, -1102.49f, 400.679f, 0.0f);
break;

case 1305:// Ruins of Ahn'Qiraj
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(1, -8409.032227f, 1498.830933f, 27.361542f, 2.497567f);
break;

case 1306:// Temple of Ahn'Qiraj
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(1, -8245.837891f, 1983.736206f, 129.071686f, 0.936195f);
break;

case 1307:// Naxxramas
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(0, 3125.184814f, -3748.024658f, 136.049393f, 0.0f);
break;

case 1308:// Karazhan
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(0, -11118.8f, -2010.84f, 47.0807f, 0.0f);
break;

case 1309:// Gruul's Lair
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(530, 3539.007568f, 5082.357910f, 1.691071f, 0.0f);
break;

case 1310:// Hellfire Citadel
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(530, -305.816223f, 3056.401611f, -2.473183f, 2.01f);
break;

case 1311:// Coilfang Reservoir
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(530, 517.288025f, 6976.279785f, 32.007198f, 0.0f);
break;

case 1312:// Tempest Keep
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(530, 3089.579346f, 1399.046509f, 187.653458f, 4.794070f);
break;

case 1313:// Caverns of Time
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(1, -8173.66f, -4746.36f, 33.8423f, 4.93989f);
break;

case 1314:// Zul'Aman
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(530, 6846.95f, -7954.5f, 170.028f, 4.61501f);
break;

case 1315:// Black Temple
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(530, -3610.719482f, 324.987579f, 37.400028f, 3.282981f);
break;


           //  Level 80 Wotlk Dungeons
           
case 1401:// Culling
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(1, -8648.95f,-4387.76f,-207.95f,3.5049f);
break;

case 1402:// Oculus
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(571, 3780.6f,6955.63f,104.89f,0.3676f);
break;

case 1403:// Halls of Lightning
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(571, 9105.72f,-1319.86f,1058.39f,5.6502f);
break;

case 1404:// Utgarde Pinnacle
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(571, 1256.96f,-4852.94f,215.55f,3.447f);
break;

case 1405:// Halls of Stone
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(571, 8922.45f,-1012.96f,1039.59f,1.563f);
break;

case 1406:// Gundrak
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(571, 6936.08f,-4436.54f,450.51f,0.7698f);
break;

case 1407:// Violet Hold
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(571, 5705.19f,517.96f,649.78f,4.0307f);
break;

case 1408:// DrakTharon Keep
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(571, 4774.32f,-2036.68f,229.38f,1.567f);
break;

case 1409:// Old Kingdom
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(571, 3700.87f,2152.58f,36.044f,3.5956f);
break;

case 1410:// Azjol Nerub
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(571, 3700.87f,2152.58f,36.044f,3.5956f);
break;

case 1411:// Nexus
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(571, 3780.6f,6955.63f,104.89f,0.3676f);
break;

case 1412:// Utgarde Keep
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(571, 1206.94f,-4868.05f,41.249f,0.2804f);
break;


           // Level 80 Wotlk Raids 
           
case 1501:// Eye of Eternity
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(571, 3860.62f,6989.15f,152.042f,5.74598f);
break;

case 1502:// Obsidian Sanctum
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(571, 3483.54f,265.605f,-120.144f,3.23879f);
break;

case 1503:// Vault of Archavon
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(571, 5406.72f,2816.98f,418.675f,1.06982f);
break;

case 1504:// Gates of Ulduar
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(571, 9019.79f,-1111.28f,1165.28f,6.26597f);
break;

case 1505:// The Frozen Halls
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(571, 5693.37f,2167.4f,798.125f,4.63304f);
break;

case 1506:// Icecrown Citadel
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(571, 6255.38f,2286.08f,486.399f,3.52562f);
break;

case 1507://teleport player to ToC / ToCr / Argent Tournament
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(571, 8385.92f,793.193f,547.293f,1.820647f);
break;
  

            //-- Cataclysm Dungeons
            
case 1601: //Throne of the Tides - Cata Dungeon    - .go xyz  -589.89 809.07 245.33 643
  player->CLOSE_GOSSIP_MENU(); 
  player->TeleportTo(643, -589.89f,809.07f,245.33f,6.19825f);
  break;
  
case 1602: //Blackrock Caverns - Cata Dungeon 			- .go 210.4436 1104.602 209.12 645  
  player->CLOSE_GOSSIP_MENU(); 
  player->TeleportTo(645, -210.443f,1104.602f,209.33f,4.70425f);
  break;
  
case 1603: //Grim batol - Cata Dungeon			.go -627.52 -175.76 272.13 670  
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(670, -627.52f,-175.76f,272.13f,5.0055f);
  break; 

case 1604: //Halls of Origination - Cata Dungeon			  
  player->CLOSE_GOSSIP_MENU(); 
  player->TeleportTo(644, -954.231f,460.996f,52.102f,1.5431f);
  break;
  
case 1605: //Stonecore - Cata Dungeon			  
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(725, 841.204f,986.810f,318.402f,6.2722f);
  break;
  
case 1606: //The Vortex Pinnacle - Cata Dungeon			  
  player->CLOSE_GOSSIP_MENU(); 
  player->TeleportTo(657, -358.1034f,-4.9814f,632.780f,3.9323f);
  break;
  
//case 1607: //Lost City of the Tol'vir	Placeholder		  
  //player->CLOSE_GOSSIP_MENU();
  //player->TeleportTo(643, -616.585f,807.242f,245.166f,0.006f);
  //break;           
  
//-- Cataclysm Raids 
case 1620: //The Bastion of Twilight  - Cata Raid			.go -560.879 -531.356 891.012 671  
  player->CLOSE_GOSSIP_MENU(); 
  player->TeleportTo(671, -560.879f,-531.356f,891.012f,6.24425f);
  break;        
  
case 1621: //Blackwing Descent  - Cata Raid			
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(669, -355.479f,-225.590f,192.113f,0.00725f);
  break;
  
//case 1622: //Baradin Hold Placeholder  - Cata Raid			
  //player->CLOSE_GOSSIP_MENU();
  //player->TeleportTo(669, -355.479f,-225.590f,192.113f,0.00725f);
  //break;
  
//case 1623: //Throne Raid Placeholder  - Cata Raid			
  //player->CLOSE_GOSSIP_MENU();
  //player->TeleportTo(669, -355.479f,-225.590f,192.113f,0.00725f);
  //break;    

           // PvP & Arenas
case 1701://teleport player to Warsong Gulch
  player->CLOSE_GOSSIP_MENU();
    if ( player->GetTeam() == ALLIANCE )
    player->TeleportTo(489, 1525.95f,1481.66f,352.001f,3.20756f);
  else // horde
    player->TeleportTo(489, 930.851f,1431.57f,345.537f,0.015704f);
break;

case 1702://teleport player to Arathi Basin
  player->CLOSE_GOSSIP_MENU();
    if ( player->GetTeam() == ALLIANCE )
    player->TeleportTo(529, 1308.681f,1306.03f,-9.0107f,3.91285f);
  else // horde
    player->TeleportTo(529, 686.053f,683.165f,-12.9149f,0.18f);
break;

case 1703://teleport player to Alterac Valley
  player->CLOSE_GOSSIP_MENU();
    if ( player->GetTeam() == ALLIANCE )
    player->TeleportTo(30, 883.187f,-489.375f,96.7618f,3.06932f);
  else // horde
    player->TeleportTo(30, -818.155f,-623.043f,54.0884f,2.1f);
break;

case 1704://teleport player to Eye of the Storm
  player->CLOSE_GOSSIP_MENU();
    if ( player->GetTeam() == ALLIANCE )
    player->TeleportTo(566, 2487.72f,1609.12f,1224.64f,3.35671f);
  else // horde
    player->TeleportTo(566, 1843.73f,1529.77f,1224.43f,0.297579f);
break;

case 1705:// Gurubashi Arena
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(0, -13261.3f, 168.294f, 35.0792f, 1.00688f);
break;


case 1706://teleport player to Circle of Blood
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(530, 2839.44f,5930.17f,11.1002f,3.16284f);
break;

case 1707://teleport player to Ring of Trials
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(530, -1999.94f,6581.71f,11.32f,2.3f);
break;

case 1708://teleport player to The Maul
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(1, -3761.49f,1133.43f,132.083f,4.57259f);
break;

case 1709://teleport player to Wintergrasp
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(571, 4984.89f,2864.16f,386.797f,2.56767f);
break;
  
            //-- Testing & Unused Zones

case 1801: // Lost Isles of Maelstorm   
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(648, 993.349f,3848.937f,15.420f,4.3245f);
  break;
    
case 1802: // Deepholm
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(646, 1077.855f,538.074f,-44.87f,3.3607f);
  break;
  
case 1803: // Stonetalon Bomb
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(731, 2095.110f,1578.965f,343.391f,5.539f);
  break;
  
case 1804: // Twilight Highlands Dragonmaw Phase
  player->CLOSE_GOSSIP_MENU(); 
  player->TeleportTo(736, -4105.810f,-6412.682f,37.699f,0.5496f);
  break;
  
case 1805: // Town in a box
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(661, 941.95f,2313.61f,5.779f,0.5496f);
  break;                  

case 1806: // Lost Isles Volcanoe Eruption
  player->CLOSE_GOSSIP_MENU();
  player->TeleportTo(659, 1850.752f,1908.192f,173.12f,2.5956f);
  break;
  
           // Specials  
  
case 2002://Faction Safe Mall Ports 
 player->CLOSE_GOSSIP_MENU();
    if ( player->GetTeam() == ALLIANCE )
    player->TeleportTo(0, -4827.55f,-981.444f,464.709f,3.86023f);
  else // horde
    player->TeleportTo(0, 3536.28f,-3388.83f,132.376f,3.01593f);
break;

case 2003: //Free For All Shopping mall (if enabled in conf)
  player->CLOSE_GOSSIP_MENU(); 
  player->TeleportTo(1, -8673.19f,1956.45f,109.12f,0.28995f);
  break;
   
////////////////////////////Low Level Buffs ////////////////////////////////

case 2101: // Buff me Mark of the Wild
    player->CLOSE_GOSSIP_MENU();
    pCreature->CastSpell(player,48469,false);
     
break;

case 2102: // Buff me Thorns
    player->CLOSE_GOSSIP_MENU();
    pCreature->CastSpell(player,53307,false);
     
break;

case 2103: // Buff me Amplify Magic
    player->CLOSE_GOSSIP_MENU();
    pCreature->CastSpell(player,43017,false);
     
break;

case 2104: // Buff me Arcane Intellect
    player->CLOSE_GOSSIP_MENU();
    pCreature->CastSpell(player,42995,false);
     
break;

case 2105: // Buff me Dalaran Intellect
    player->CLOSE_GOSSIP_MENU();
    pCreature->CastSpell(player,61024,false);
     
break;

case 2106: // Buff me Dampen Magic
    player->CLOSE_GOSSIP_MENU();
    pCreature->CastSpell(player,43015,false);
     
break;

case 2107: // Buff me Blessing of Kings
    player->CLOSE_GOSSIP_MENU();
    pCreature->CastSpell(player,20217,false);
     
break;

case 2108: // Buff me Blessing of Might
    player->CLOSE_GOSSIP_MENU();
    pCreature->CastSpell(player,48932,false);
     
break;

case 2109: // Buff me Blessing of Wisdom
    player->CLOSE_GOSSIP_MENU();
    pCreature->CastSpell(player,48936,false);
     
break;

case 2110: // Buff me Divine Spirit
    player->CLOSE_GOSSIP_MENU();
    pCreature->CastSpell(player,48073,false);
     
break;

case 2111: // Buff me Power Word: Fortitude
    player->CLOSE_GOSSIP_MENU();
    pCreature->CastSpell(player,48161,false);
     
break;

case 2112: // Buff me Shadow Protection
    player->CLOSE_GOSSIP_MENU();
    pCreature->CastSpell(player,48169,false);
     
break;

//////////////////////////////////Great Buff///////////////////////////////

case 2201: // Buff me Mark of the Wild
    player->CLOSE_GOSSIP_MENU();
    player->CastSpell(player,48470,true);
     
break;

case 2202: // Buff me Arcane Brilliance
    player->CLOSE_GOSSIP_MENU();
    player->CastSpell(player,43002,true);
     
break;

case 2203: // Buff me Dalaran Brilliance
    player->CLOSE_GOSSIP_MENU();
    player->CastSpell(player,61316,true);
     
break;

case 2204: // Buff me Greater Blessing of Kings
    player->CLOSE_GOSSIP_MENU();
    pCreature->CastSpell(player,25898,false);
     
break;

case 2205: // Buff me Greater Blessing of Might
    player->CLOSE_GOSSIP_MENU();
    pCreature->CastSpell(player,48934,false);
     
break;

case 2206: // Buff me Greater Blessing of Sanctuary
    player->CLOSE_GOSSIP_MENU();
    pCreature->CastSpell(player,25899,false);
     
break;

case 2207: // Buff me Greater Blessing of Wisdom
    player->CLOSE_GOSSIP_MENU();
    pCreature->CastSpell(player,48938,false);
     
break;

case 2208: // Buff me Prayer of Fortitude
    player->CLOSE_GOSSIP_MENU();
    player->CastSpell(player,48162,true);
     
break;

case 2209: // Buff me Prayer of Shadow Protection
    player->CLOSE_GOSSIP_MENU();
    player->CastSpell(player,48170,true);
     
break;

case 2210: // Buff me Prayer of Spirit
    player->CLOSE_GOSSIP_MENU();
    player->CastSpell(player,48074,true);
     
break;

//////////////////////////////GM Buff////////////////////////////////

case 2301: // Buff me Agamaggan's Agility
    player->CLOSE_GOSSIP_MENU();
    pCreature->CastSpell(player,17013,false);
     
break;

case 2302: // Buff me Agamaggan's Strength
    player->CLOSE_GOSSIP_MENU();
    pCreature->CastSpell(player,16612,false);
     
break;

case 2303: // Buff me Armor Magic
    player->CLOSE_GOSSIP_MENU();
    pCreature->CastSpell(player,58453,false);
     
break;

case 2304: // Buff me Armor Penetration
    player->CLOSE_GOSSIP_MENU();
    player->CastSpell(player,34106,false);
     
break;

case 2305: // Buff me Increased Stamina
    player->CLOSE_GOSSIP_MENU();
    player->CastSpell(player,25661,false);
     
break;

case 2306: // Buff me Razorhide
    player->CLOSE_GOSSIP_MENU();
    pCreature->CastSpell(player,16610,false);
     
break;

case 2307: // Buff me Rising Spirit
    player->CLOSE_GOSSIP_MENU();
    pCreature->CastSpell(player,10767,false);
     
break;

case 2308: // Buff me Spirit of the Wind
    player->CLOSE_GOSSIP_MENU();
    pCreature->CastSpell(player,16618,false);
     
break;

case 2309: // Buff me Wisdom of Agamaggan
    player->CLOSE_GOSSIP_MENU();
    pCreature->CastSpell(player,7764,false);
     
break;

//////////////////////////////////////////////////Player Tools///////////////////////////////////////////////////////////////

case 2401://Give me Gold
    player->CLOSE_GOSSIP_MENU();
    pCreature->CastSpell(player,46642,false); // 5000 gold
break;

case 2402://Give me Soul Shards
    player->CLOSE_GOSSIP_MENU();
    player->CastSpell(player,24827,false);
     
break;

case 2403: // Heal me please
    player->CLOSE_GOSSIP_MENU();
    pCreature->CastSpell(player,38588,false);
     
break;

case 2404: // Heal me and party members Please
    player->CLOSE_GOSSIP_MENU();
    player->CastSpell(player,53251,false);
     
break;

case 2405: // Conjure Refreshment
    player->CLOSE_GOSSIP_MENU();
    player->CastSpell(player,42956,false);
     
break;

case 2406: // Conjure Mana Gem
    player->CLOSE_GOSSIP_MENU();
    player->CastSpell(player,42985,false);
     
break;

case 2407://Remove Res Sickness
	if (!player->HasAura(15007,0))
	{
		pCreature->MonsterWhisper("You don't have resurrection sickness.", player->GetGUID());
		OnGossipHello(player, pCreature);
		return;
	}

	pCreature->CastSpell(player,38588,false); // Healing effect
	player->RemoveAurasDueToSpell(15007,0);
	player->CLOSE_GOSSIP_MENU();
break;


//////////////////////////////////////////////////Professions///////////////////////////////////////////////////////////////

case 2501: // Alchemy
	if (!player->UpdateSkill(171,0))
      {
		pCreature->MonsterWhisper("You don't have this skill or you allready have the maximum skill value $C.", player->GetGUID());
		OnGossipHello(player, pCreature);
		return;
	}

	player->UpdateSkill(171,(sConfig->GetFloatDefault("pryds_allinoneSkillPoints",0)));
	player->CLOSE_GOSSIP_MENU();
break;

case 2502: // Blacksmithing
	if (!player->UpdateSkill(164,0))
      {
		pCreature->MonsterWhisper("You don't have this skill or you allready have the maximum skill value $C.", player->GetGUID());
		OnGossipHello(player, pCreature);
		return;
	}

	player->UpdateSkill(164,(sConfig->GetFloatDefault("pryds_allinoneSkillPoints",0)));
	player->CLOSE_GOSSIP_MENU();
break;

case 2503: // Enchanting
	if (!player->UpdateSkill(333,0))
      {
		pCreature->MonsterWhisper("You don't have this skill or you allready have the maximum skill value $C.", player->GetGUID());
		OnGossipHello(player, pCreature);
		return;
	}

	player->UpdateSkill(333,(sConfig->GetFloatDefault("pryds_allinoneSkillPoints",0)));
	player->CLOSE_GOSSIP_MENU();
break;

case 2504: // Engineering
	if (!player->UpdateSkill(202,0))
      {
		pCreature->MonsterWhisper("You don't have this skill or you allready have the maximum skill value $C.", player->GetGUID());
		OnGossipHello(player, pCreature);
		return;
	}

	player->UpdateSkill(202,(sConfig->GetFloatDefault("pryds_allinoneSkillPoints",0)));
	player->CLOSE_GOSSIP_MENU();
break;

case 2505: // Herbalism
	if (!player->UpdateSkill(182,0))
      {
		pCreature->MonsterWhisper("You don't have this skill or you allready have the maximum skill value $C.", player->GetGUID());
		OnGossipHello(player, pCreature);
		return;
	}

	player->UpdateSkill(182,(sConfig->GetFloatDefault("pryds_allinoneSkillPoints",0)));
	player->CLOSE_GOSSIP_MENU();
break;

case 2506: // Inscription
	if (!player->UpdateSkill(773,0))
      {
		pCreature->MonsterWhisper("You don't have this skill or you allready have the maximum skill value $C.", player->GetGUID());
		OnGossipHello(player, pCreature);
		return;
	}

	player->UpdateSkill(773,(sConfig->GetFloatDefault("pryds_allinoneSkillPoints",0)));
	player->CLOSE_GOSSIP_MENU();
break;

case 2507: // Jewelcrafting
	if (!player->UpdateSkill(755,0))
      {
		pCreature->MonsterWhisper("You don't have this skill or you allready have the maximum skill value $C.", player->GetGUID());
		OnGossipHello(player, pCreature);
		return;
	}

	player->UpdateSkill(755,(sConfig->GetFloatDefault("pryds_allinoneSkillPoints",0)));
	player->CLOSE_GOSSIP_MENU();
break;

case 2508: // Leatherworking
	if (!player->UpdateSkill(165,0))
      {
		pCreature->MonsterWhisper("You don't have this skill or you allready have the maximum skill value $C.", player->GetGUID());
		OnGossipHello(player, pCreature);
		return;
	}

	player->UpdateSkill(165,(sConfig->GetFloatDefault("pryds_allinoneSkillPoints",0)));
	player->CLOSE_GOSSIP_MENU();
break;

case 2509: // Mining
	if (!player->UpdateSkill(186,0))
      {
		pCreature->MonsterWhisper("You don't have this skill or you allready have the maximum skill value $C.", player->GetGUID());
		OnGossipHello(player, pCreature);
		return;
	}

	player->UpdateSkill(186,(sConfig->GetFloatDefault("pryds_allinoneSkillPoints",0)));
	player->CLOSE_GOSSIP_MENU();
break;

case 2510: // Skinning
	if (!player->UpdateSkill(393,0))
      {
		pCreature->MonsterWhisper("You don't have this skill or you allready have the maximum skill value $C.", player->GetGUID());
		OnGossipHello(player, pCreature);
		return;
	}

	player->UpdateSkill(393,(sConfig->GetFloatDefault("pryds_allinoneSkillPoints",0)));
	player->CLOSE_GOSSIP_MENU();
break;

case 2511: // Tailoring
	if (!player->UpdateSkill(197,0))
      {
		pCreature->MonsterWhisper("You don't have this skill or you allready have the maximum skill value $C.", player->GetGUID());
		OnGossipHello(player, pCreature);
		return;
	}

	player->UpdateSkill(197,(sConfig->GetFloatDefault("pryds_allinoneSkillPoints",0)));
	player->CLOSE_GOSSIP_MENU();
break;

//////////////////////////////////////////////////Secondary Skills///////////////////////////////////////////////////////////////

case 2551: // Cooking
	if (!player->UpdateSkill(185,0))
      {
		pCreature->MonsterWhisper("You don't have this skill or you allready have the maximum skill value $C.", player->GetGUID());
		OnGossipHello(player, pCreature);
		return;
	}

	player->UpdateSkill(185,(sConfig->GetFloatDefault("pryds_allinoneSkillPoints",0)));
	player->CLOSE_GOSSIP_MENU();
break;

case 2552: // First Aid
	if (!player->UpdateSkill(129,0))
      {
		pCreature->MonsterWhisper("You don't have this skill or you allready have the maximum skill value $C.", player->GetGUID());
		OnGossipHello(player, pCreature);
		return;
	}

	player->UpdateSkill(129,(sConfig->GetFloatDefault("pryds_allinoneSkillPoints",0)));
	player->CLOSE_GOSSIP_MENU();
break;

case 2553: // Fishing
	if (!player->UpdateSkill(356,0))
      {
		pCreature->MonsterWhisper("You don't have this skill or you allready have the maximum skill value $C.", player->GetGUID());
		OnGossipHello(player, pCreature);
		return;
	}

	player->UpdateSkill(356,(sConfig->GetFloatDefault("pryds_allinoneSkillPoints",0)));
	player->CLOSE_GOSSIP_MENU();
break;  
  
          
  
  
}   // end of switch
}   //end of function



bool OnGossipSelect(Player *player, Creature* pCreature, uint32 sender, uint32 action)
{
  // Main menu
  if (sender == GOSSIP_SENDER_MAIN)
  {
	player->PlayerTalkClass->ClearMenus();            /* 11/05/2010 niteowl57:  For 3.3.5a, fix menu functionality  */
  SendDefaultMenu_pryds_telenpc( player, pCreature, action );
	}
return true;
}

		bool OnGossipSelectCode(Player *player, Creature *pCreature, uint32 sender, uint32 action, const char *pCode)
		{
			switch(sender)
			{
				case ITEM_REQUESTER_MENU_SELECT_ITEM:
				{
					player->CLOSE_GOSSIP_MENU();
					uint32 itemId = atol(pCode);
					if(itemId == 0)
					{
						std::string escapedCode = pCode;
						WorldDatabase.EscapeString(escapedCode);
						if(QueryResult queryResult = WorldDatabase.PQuery("SELECT `entry` FROM `item_template` WHERE `name` = '%s'", escapedCode.c_str()))
							itemId = queryResult->Fetch()[0].GetUInt32();
					}

					const ItemTemplate *ItemTemplate = sObjectMgr->GetItemTemplate(itemId);
					if(ItemTemplate == NULL)
					{
						ChatHandler(player).PSendSysMessage(REQUESTER_ERROR_INVALID_ITEM);
						return true;
					}

					//if(CheckQualityRequirements(player, itemProto->Quality) == false)
					//{
					//	ChatHandler(player).PSendSysMessage(REQUESTER_ERROR_REQUIREMENTS_NOT_MET);
					//	return true;
					//}
					if(CreateItemAndMailToPlayer(player, itemId) == true)
						ChatHandler(player).PSendSysMessage(REQUESTER_MAIL_SUCCESS);
					else
						ChatHandler(player).PSendSysMessage(REQUESTER_ERROR_ITEM_CREATION_FAILED );
				}break;
			}
			return true;
		}

		bool CheckQualityRequirements(Player *player, uint32 qualityType)
		{
			switch(qualityType)
			{
				case ITEM_QUALITY_POOR:
				case ITEM_QUALITY_NORMAL:
				case ITEM_QUALITY_UNCOMMON:
				{
					if(player->getLevel() >= REQUESTER_QUALITY_LEVEL_PNU)
						return true;

				}break;

				case ITEM_QUALITY_RARE:
				{
					if(player->getLevel() >= REQUESTER_QUALITY_LEVEL_RARE)
						return true;
				}break;

				case ITEM_QUALITY_EPIC:
				{
					if(player->getLevel() >= REQUESTER_QUALITY_LEVEL_EPIC)
						return true;
				}break;

				default:
				{
					ChatHandler(player).PSendSysMessage(REQUESTER_ERROR_QUALITY_TOO_HIGH);
				}break;
			}
			return false;
		}

		bool CreateItemAndMailToPlayer(Player *player, uint32 itemId)
		{
			Item *pItem = new Item();
			if(pItem->Create(sObjectMgr->GenerateLowGuid(HIGHGUID_ITEM), itemId, player) == false)
				return false;

			MailSender toSend(MAIL_NORMAL, player->GetGUIDLow(), MAIL_STATIONERY_GM);
			SQLTransaction trans = CharacterDatabase.BeginTransaction();
			pItem->SaveToDB(trans);

			MailDraft mailDraft(REQUESTER_DEFAULT_MAIL_SUBJECT, REQUESTER_DEFAULT_MAIL_BODY);
			mailDraft.AddItem(pItem);
			mailDraft.SendMailTo(trans, MailReceiver(player), toSend);
			CharacterDatabase.CommitTransaction(trans);
			return true;
		}

};

void AddSC_pryds_telenpc()
{
  new pryds_telenpc();
}
