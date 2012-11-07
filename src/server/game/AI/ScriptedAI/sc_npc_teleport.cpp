#include "ScriptPCH.h"

#define EM 500201 // EM id
#define mount_100 20 // 100% mount
#define mount_280 30 // 280% mount
#define mount_310 40 // 310% mount
#define mount_other 50 // zelva atp.
#define mount_legend 60 // celestial atp.
#define noncmbt_pet 20 // non-combat pet
#define cena_rename 1 // cena rename
#define cena_custom 5 // cena char. customizeru
#define cena_race_change 10 // Cena race change-u

// 5 emblemu za em ..
// cena = 10 => 5 emblemu za 10 EM ..

#define cena_valor 10 // cena EoV
#define cena_heroism 5 // cena EoH

#define cena_honory 5 // Cena honorù



class EM_trader : public CreatureScript
{
public:
    EM_trader() : CreatureScript("EM_trader") { }

    bool OnGossipHello(Player *player, Creature *_creature)
    {
        if (player->isInCombat())
        {
            player->CLOSE_GOSSIP_MENU();
            _creature->MonsterWhisper("Jsi v combatu, vrat se pozdeji!", player->GetGUID());
            return true;
        }
        else
        {
            player->ADD_GOSSIP_ITEM( 7, "Account Manager", GOSSIP_SENDER_MAIN, 1);
            player->ADD_GOSSIP_ITEM( 7, "Mounti", GOSSIP_SENDER_MAIN, 2);
            player->ADD_GOSSIP_ITEM( 7, "Non-combat peti", GOSSIP_SENDER_MAIN, 3);
            player->ADD_GOSSIP_ITEM( 7, "Emblemy", GOSSIP_SENDER_MAIN, 4);
        }

        player->SEND_GOSSIP_MENU(50000, _creature->GetGUID());
        return true;
    }

    bool AddMount(Player *player, Creature *_creature, int EM_pocet, int ID)
    {
        
        if (player->HasItemCount(EM, EM_pocet,false))
            {
                player->AddItem(ID,1);
                player->DestroyItemCount(EM,EM_pocet,true, false);
                player->SaveToDB();
                _creature->MonsterWhisper("Gratuluji k novemu mountovi!", player->GetGUID());
                return true;
            }
            else
            {
                _creature->MonsterWhisper("Nemas dostatek event marek!", player->GetGUID());
                return false;
            }
            
        player->SEND_GOSSIP_MENU(50007, _creature->GetGUID());
        player->ADD_GOSSIP_ITEM(4, "<< Zpet na hl. menu", GOSSIP_SENDER_MAIN, 0);
        player->ADD_GOSSIP_ITEM(4, "<< Zpet do vyberu mountu", GOSSIP_SENDER_MAIN, 2);

    }




bool AddEmbl(Player *player, Creature *_creature, int EM_pocet, int ID)
    {
        
        if (player->HasItemCount(EM, EM_pocet,false))
            {
                player->AddItem(ID,5);
                player->DestroyItemCount(EM,EM_pocet,true, false);
                player->SaveToDB();
                _creature->MonsterWhisper("Diky! Dobre se s tebou obchoduje!", player->GetGUID());
                return true;
            }
            else
            {
                _creature->MonsterWhisper("Nemas dostatek event marek!", player->GetGUID());
                return false;
            }
            
        player->SEND_GOSSIP_MENU(50008, _creature->GetGUID());
        player->ADD_GOSSIP_ITEM(4, "<< Zpet na hl. menu", GOSSIP_SENDER_MAIN, 0);
        player->ADD_GOSSIP_ITEM(4, "<< Zpet do vyberu emblemu", GOSSIP_SENDER_MAIN, 4);

    }

bool AddBravery(Player *player, Creature *_creature, int EM_pocet, int ID)
    {
        
        if (player->HasItemCount(EM, EM_pocet,false))
            {
                player->AddItem(ID,1);
                player->DestroyItemCount(EM,EM_pocet,true, false);
                player->SaveToDB();
                _creature->MonsterWhisper("Diky! Dobre se s tebou obchoduje!", player->GetGUID());
                return true;
            }
            else
            {
                _creature->MonsterWhisper("Nemas dostatek event marek!", player->GetGUID());
                return false;
            }
            
        player->SEND_GOSSIP_MENU(50008, _creature->GetGUID());
        player->ADD_GOSSIP_ITEM(4, "<< Zpet na hl. menu", GOSSIP_SENDER_MAIN, 0);
        player->ADD_GOSSIP_ITEM(4, "<< Zpet do vyberu emblemu", GOSSIP_SENDER_MAIN, 4);

    }



        bool AddPet(Player *player, Creature *_creature, int EM_pocet, int ID)
        {
        
         if (player->HasItemCount(EM, EM_pocet,false))
            {
                player->AddItem(ID,1);
                player->DestroyItemCount(EM,EM_pocet,true, false);
                player->SaveToDB();
                _creature->MonsterWhisper("Gratuluji k novemu non-combat petovi!", player->GetGUID());
                return true;
            }
            else
            {
                _creature->MonsterWhisper("Nemas dostatek event marek!", player->GetGUID());
                return false;
            }
            
        player->SEND_GOSSIP_MENU(50009, _creature->GetGUID());
        player->ADD_GOSSIP_ITEM(4, "<< Zpet na hl. menu", GOSSIP_SENDER_MAIN, 0);
        player->ADD_GOSSIP_ITEM(4, "<< Zpet na vyber peta", GOSSIP_SENDER_MAIN, 3);

    }




        bool rename(Player *player, Creature *_creature)
        {
            if (player->HasItemCount(EM, cena_rename,false))
            {
                player->SetAtLoginFlag(AT_LOGIN_RENAME);
                player->DestroyItemCount(EM,cena_rename,true, false);
                player->SaveToDB();
                player->CLOSE_GOSSIP_MENU();
                _creature->MonsterWhisper("Pri dalsim prihlaseni na tvuj account budes mit k dispozici moznost zmenit si jmeno.", player->GetGUID());
                return true;
            }
            else
            {
                _creature->MonsterWhisper("Nemas dostatek event marek!", player->GetGUID());
                player->CLOSE_GOSSIP_MENU();
                return false;
            }
        

    }


// Zmena race
bool race_change(Player *player, Creature *_creature)
        {
            if (player->HasItemCount(EM, cena_race_change,false))
            {
                player->SetAtLoginFlag(AT_LOGIN_CHANGE_RACE);
                player->DestroyItemCount(EM,cena_race_change,true, false);
                player->SaveToDB();
                player->CLOSE_GOSSIP_MENU();
                _creature->MonsterWhisper("Pri dalsim prihlaseni na tvuj account budes mit k dispozici moznost zmenit si rasu.", player->GetGUID());
                return true;
            }
            else
            {
                _creature->MonsterWhisper("Nemas dostatek event marek!", player->GetGUID());
                player->CLOSE_GOSSIP_MENU();
                return false;
            }
        

    }

       bool char_customizer(Player *player, Creature *_creature)
         {
        
            if (player->HasItemCount(EM, cena_custom,false))
            {
                player->SetAtLoginFlag(AT_LOGIN_CUSTOMIZE);
                player->DestroyItemCount(EM,cena_custom,true, false);
                player->SaveToDB();
                player->CLOSE_GOSSIP_MENU();
                _creature->MonsterWhisper("Pri dalsim prihlaseni na tvuj account budes mit k dispozici caracter customizer.", player->GetGUID());
                return true;
            }
            else
            {
                _creature->MonsterWhisper("Nemas dostatek event marek!", player->GetGUID());
                player->CLOSE_GOSSIP_MENU();
                return false;
            }
        

    }





    bool OnGossipSelect(Player *player, Creature *_creature, uint32 sender, uint32 uiAction)
    {
        if (sender == GOSSIP_SENDER_MAIN)
        {
            player->PlayerTalkClass->ClearMenus();
            switch(uiAction)
            {
            case 0: //Hlavni menu
                 player->ADD_GOSSIP_ITEM( 7, "Account Manager", GOSSIP_SENDER_MAIN, 1);
                 player->ADD_GOSSIP_ITEM( 7, "Mounti", GOSSIP_SENDER_MAIN, 2);
                 player->ADD_GOSSIP_ITEM( 7, "Non-combat peti", GOSSIP_SENDER_MAIN, 3);
                 player->ADD_GOSSIP_ITEM( 7, "PVE a PVP", GOSSIP_SENDER_MAIN, 4);
                 player->SEND_GOSSIP_MENU(50000, _creature->GetGUID());
                 break;

            case 1: // acc manager
                 player->ADD_GOSSIP_ITEM(10, "Rename 1 EM", GOSSIP_SENDER_MAIN, 10);
				 player->ADD_GOSSIP_ITEM(10, "Zmena rasy 5 EM", GOSSIP_SENDER_MAIN, 654);
                 player->ADD_GOSSIP_ITEM(10, "Character customizer 10 EM", GOSSIP_SENDER_MAIN, 11);
                 player->ADD_GOSSIP_ITEM(4, "<< Zpet", GOSSIP_SENDER_MAIN, 0);
                 player->SEND_GOSSIP_MENU(50001, _creature->GetGUID());
                 break;


            case 2: //Mounts
                 player->ADD_GOSSIP_ITEM(7, "Celestial Steed 60 EM", GOSSIP_SENDER_MAIN, 12);
                 player->ADD_GOSSIP_ITEM(7, "Swift Zulian Tiger 20 EM", GOSSIP_SENDER_MAIN, 13);
                 player->ADD_GOSSIP_ITEM(7, "Deathcharger 20 EM", GOSSIP_SENDER_MAIN, 14);
                 player->ADD_GOSSIP_ITEM(7, "Mimiron's Head 60 EM", GOSSIP_SENDER_MAIN, 15);
                 player->ADD_GOSSIP_ITEM(7, "Brutal Nether Drake 40 EM", GOSSIP_SENDER_MAIN, 16);
                 player->ADD_GOSSIP_ITEM(7, "Invincible 60 EM", GOSSIP_SENDER_MAIN, 17);
                 player->ADD_GOSSIP_ITEM(7, "Magic Broom 40 EM", GOSSIP_SENDER_MAIN, 18);
                 player->ADD_GOSSIP_ITEM(7, "Swift Spectral Tiger 20 EM", GOSSIP_SENDER_MAIN, 19);
                 player->ADD_GOSSIP_ITEM(7, "White Polar Bear 20 EM", GOSSIP_SENDER_MAIN, 20);
                 player->ADD_GOSSIP_ITEM(7, "Teal Kodo 20 EM", GOSSIP_SENDER_MAIN, 21);
                 player->ADD_GOSSIP_ITEM(7, "Raven Lord 20 EM", GOSSIP_SENDER_MAIN, 22);
                 player->ADD_GOSSIP_ITEM(7, "Black Qiraji Battle Tank 20 EM", GOSSIP_SENDER_MAIN, 23);
                 player->ADD_GOSSIP_ITEM(7, "Green Proto-Drake 30 EM", GOSSIP_SENDER_MAIN, 24);
                 player->ADD_GOSSIP_ITEM(7, "Red Proto-Drake 30 EM", GOSSIP_SENDER_MAIN, 25);
                 player->ADD_GOSSIP_ITEM(7, "Riding Turtle 50 EM", GOSSIP_SENDER_MAIN, 26);
                 player->ADD_GOSSIP_ITEM(7, "Sea Turtle 50 EM", GOSSIP_SENDER_MAIN, 27);
                 player->ADD_GOSSIP_ITEM(7, "Swift White Hawkstrider 20 EM", GOSSIP_SENDER_MAIN, 28);
                 player->ADD_GOSSIP_ITEM(7, "Wooly White Rhino 20 EM", GOSSIP_SENDER_MAIN, 29);
                 player->ADD_GOSSIP_ITEM(4, "<< Zpet", GOSSIP_SENDER_MAIN, 0);
                 player->SEND_GOSSIP_MENU(50002, _creature->GetGUID());
                 break;

            case 3: //Non-combat peti
                 player->ADD_GOSSIP_ITEM(7, "Dragon Kite 20 EM" , GOSSIP_SENDER_MAIN, 30);
                 player->ADD_GOSSIP_ITEM(7, "Hippogryph Hatchling 20 EM", GOSSIP_SENDER_MAIN, 31);
                 player->ADD_GOSSIP_ITEM(7, "Tuskarr Kite 20 EM", GOSSIP_SENDER_MAIN, 32);
                 player->ADD_GOSSIP_ITEM(7, "White Tiger Cub 20 EM", GOSSIP_SENDER_MAIN, 33);
                 player->ADD_GOSSIP_ITEM(7, "Parrot Cage (Hyacinth Macaw) 20 EM", GOSSIP_SENDER_MAIN, 34);
                 player->ADD_GOSSIP_ITEM(7, "Goblin Weather Machine - Prototype 01-B 20 EM", GOSSIP_SENDER_MAIN, 35);
                 player->ADD_GOSSIP_ITEM(7, "Banana Charm 20 EM", GOSSIP_SENDER_MAIN, 36);
               //player->ADD_GOSSIP_ITEM(7, "Armadillo Pup 20 EM", GOSSIP_SENDER_MAIN, 37);
                 player->ADD_GOSSIP_ITEM(7, "Frosty's Collar 20 EM", GOSSIP_SENDER_MAIN, 38);
                 player->ADD_GOSSIP_ITEM(7, "Blue Clockwork Rocket Bot 20 EM", GOSSIP_SENDER_MAIN, 39);
                 player->ADD_GOSSIP_ITEM(7, "Core Hound Pup 20 EM", GOSSIP_SENDER_MAIN, 40);
                 player->ADD_GOSSIP_ITEM(7, "Elwynn Lamb 20 EM", GOSSIP_SENDER_MAIN, 41);
                 player->ADD_GOSSIP_ITEM(4, "<< Zpet", GOSSIP_SENDER_MAIN, 0);
                 player->SEND_GOSSIP_MENU(50003, _creature->GetGUID());
                 break;

            case 4: //PVE a PVP
				player->ADD_GOSSIP_ITEM(7, "Commendation of Bravery, Cena 12 000 honoru: 5 EM", GOSSIP_SENDER_MAIN, 45);
                player->ADD_GOSSIP_ITEM(7, "Emblem of Valor, Cena 5 emblemu: 10 EM", GOSSIP_SENDER_MAIN, 201);
                player->ADD_GOSSIP_ITEM(7, "Emblem of Heroism, Cena 5 emblemu: 5 EM", GOSSIP_SENDER_MAIN, 202);
               // player->ADD_GOSSIP_ITEM(7, "Emblem of Conquest, Cena 5 emblemu: 1 EM", GOSSIP_SENDER_MAIN, 42);
                player->ADD_GOSSIP_ITEM(4, "<< Zpet", GOSSIP_SENDER_MAIN, 0);
                player->SEND_GOSSIP_MENU(50004, _creature->GetGUID());
                break;


            case 10: //Rename
                player->ADD_GOSSIP_ITEM(10, "Ano, chci si koupit rename za 1 EM.", GOSSIP_SENDER_MAIN, 101);
                player->ADD_GOSSIP_ITEM(4, "<< Zpet do hlavniho menu", GOSSIP_SENDER_MAIN, 0);
                player->ADD_GOSSIP_ITEM(4, "<< Zpet do Account Manageru", GOSSIP_SENDER_MAIN, 1);
                player->SEND_GOSSIP_MENU(50005, _creature->GetGUID());
                break;

            case 11: //Char custom
                player->ADD_GOSSIP_ITEM(10, "Ano, chci si koupit character customize za 5 EM.", GOSSIP_SENDER_MAIN, 102);
                player->ADD_GOSSIP_ITEM(4, "<< Zpet do hlavniho menu", GOSSIP_SENDER_MAIN, 0);
                player->ADD_GOSSIP_ITEM(4, "<< Zpet do Account Manageru", GOSSIP_SENDER_MAIN, 1);
                player->SEND_GOSSIP_MENU(50006, _creature->GetGUID());
                break;

            case 654: //Race change
                player->ADD_GOSSIP_ITEM(10, "Ano, chci si koupit zmenu rasy za 10 EM.", GOSSIP_SENDER_MAIN, 655);
                player->ADD_GOSSIP_ITEM(4, "<< Zpet do hlavniho menu", GOSSIP_SENDER_MAIN, 0);
                player->ADD_GOSSIP_ITEM(4, "<< Zpet do Account Manageru", GOSSIP_SENDER_MAIN, 1);
                player->SEND_GOSSIP_MENU(50006, _creature->GetGUID());
                break;

            case 101:
                if(!rename(player, _creature))
                    return false;
                break;

            case 102:
                if(!char_customizer(player, _creature))
                    return false;
                break;
            case 655:
                if(!race_change(player, _creature))
                    return false;
                break;




            case 12: //Celestial Steed
             if(!AddMount(player, _creature, mount_legend, 54811))
                    return false;
                break;

            case 13: //Swift Zulian Tiger
             if(!AddMount(player, _creature, mount_100, 19902))
                    return false;
                break;

            case 14: //Deathcharger
             if(!AddMount(player, _creature, mount_100, 13335))
                    return false;
                break;

            case 15: //Mimiron's Head
             if(!AddMount(player, _creature, mount_legend, 45693))
                    return false;
                break;

            case 16: //Brutal Nether Drake
             if(!AddMount(player, _creature, mount_310, 43516))
                    return false;
                break;

            case 17: //Invincible
             if(!AddMount(player, _creature, mount_legend, 50818))
                    return false;
                break;

            case 18: //Magic Broom
             if(!AddMount(player, _creature, mount_310, 37011))
                    return false;
                break;

            case 19: //Swift Spectral Tiger
             if(!AddMount(player, _creature, mount_100, 49284))
                    return false;
                break;

            case 20: //White Polar Bear
             if(!AddMount(player, _creature, mount_100, 43962))
                    return false;
                break;

            case 21: //Teal Kodo
             if(!AddMount(player, _creature, mount_100, 15293))
                    return false;
                break;

            case 22: //Raven Lord
             if(!AddMount(player, _creature, mount_100, 32768))
                    return false;
                break;

            case 23: //Black Qiraji Battle Tank
             if(!AddMount(player, _creature, mount_100, 21176))
                    return false;
                break;

            case 24: //Green Proto-Drake
              if(!AddMount(player, _creature, mount_280, 44707))
                    return false;
                break;

            case 25: //Red Proto-Drake
             if(!AddMount(player, _creature, mount_280, 44160))
                    return false;
                break;
            case 26: //Riding Turtle
             if(!AddMount(player, _creature, mount_other, 23720))
                    return false;
                break;

            case 27: //Sea turtle
             if(!AddMount(player, _creature, mount_other, 46109))
                    return false;
                break;

            case 28: //Swift White Hawkstrider
             if(!AddMount(player, _creature, mount_100, 35513))
                    return false;
                break;

            case 29: //Wooly White Rhino
             if(!AddMount(player, _creature, mount_100, 54068))
                    return false;
                break;







            case 30: //Dragon Kite
             if(!AddPet(player, _creature, noncmbt_pet, 34493))
                    return false;
                break;

            case 31: //Hippogryph Hatchling
             if(!AddPet(player, _creature, noncmbt_pet, 23713))
                    return false;
                break;

            case 32: //Tuskarr Kite
             if(!AddPet(player, _creature, noncmbt_pet, 49287))
                    return false;
                break;

            case 33: //White Tiger Cub
             if(!AddPet(player, _creature, noncmbt_pet, 23712))
                    return false;
                break;

            case 34: //Parrot Cage (Hyacinth Macaw)
             if(!AddPet(player, _creature, noncmbt_pet, 8494))
                    return false;
                break;

            case 35: //Goblin Weather Machine - Prototype 01-B
             if(!AddPet(player, _creature, noncmbt_pet, 35227))
                    return false;
                break;

            case 36: //Banana Charm
             if(!AddPet(player, _creature, noncmbt_pet, 32588))
                    return false;
                break;



            case 38: //Frosty's Collar
             if(!AddPet(player, _creature, noncmbt_pet, 39286))
                    return false;
                break;

            case 39: //Blue Clockwork Rocket Bot
             if(!AddPet(player, _creature, noncmbt_pet, 54436))
                    return false;
                break;

            case 40: //Core Hound Pup
             if(!AddPet(player, _creature, noncmbt_pet, 49646))
                    return false;
                break;

            case 41: //Elwynn Lamb
             if(!AddPet(player, _creature, noncmbt_pet, 44974))
                    return false;
                break;

            /*case 42: //EoC
             if(!AddEmbl(player, _creature, cena_conq, 45624))
                    return false;
                break;

            case 43: //EoT
             if(!AddEmbl(player, _creature, cena_triumph, 47241))
                    return false;
                break;

            case 44: //EoF 45624
             if(!AddEmbl(player, _creature, cena_frost, 49426))
                    return false;
                break;
*/

			case 201: //EoV 40753
             if(!AddEmbl(player, _creature, cena_valor, 40753))
                    return false;
                break;
				
			case 202: //EoH 40752
             if(!AddEmbl(player, _creature, cena_heroism, 40752))
                    return false;
                break;
			case 45: //bravery 45706
             if(!AddBravery(player, _creature, cena_honory, 45706))
                    return false;
                break;


            default:
                break;
            }
        }
        return true;
    }
};

void AddSC_EM_trader()
{
    new EM_trader();
}