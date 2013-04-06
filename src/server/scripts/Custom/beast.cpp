    //Fixed by Ac-Web Community
    //Modified by Marcus
    //original script created by ??
     
    #include "ScriptPCH.h"
    #include "Language.h"
    #include "Pet.h"
     
    #define GOSSIP_ITEM_STABLE "Stable"
    #define GOSSIP_ITEM_NEWPET "New Pet"
    #define GOSSIP_ITEM_BOAR "Boar"
    #define GOSSIP_ITEM_SERPENT "Serpent"
    #define GOSSIP_ITEM_SCRAB "Scrab"
    #define GOSSIP_ITEM_LION "Lion"
    #define GOSSIP_ITEM_WOLF "Wolf"
    #define GOSSIP_ITEM_RAVAGER "Ravenger"
     
    #define GOSSIP_ITEM_UNTRAINEPET "Restart Pet"
     
    class Npc_Beastmaster : public CreatureScript
    {
    public:
            Npc_Beastmaster() : CreatureScript("Npc_Beastmaster") { }
     
    void CreatePet(Player *player, Creature * m_creature, uint32 entry) {
     
            if(player->getClass() != CLASS_HUNTER) {
                m_creature->MonsterWhisper("You are not a Hunter!", player->GetGUID());
                player->PlayerTalkClass->SendCloseGossip();
                return;
            }
     
            if(player->GetPet()) {
                m_creature->MonsterWhisper("First you must drop your Pet!", player->GetGUID());
                player->PlayerTalkClass->SendCloseGossip();
                return;
            }
     
            Creature *creatureTarget = m_creature->SummonCreature(entry, player->GetPositionX(), player->GetPositionY()+2, player->GetPositionZ(), player->GetOrientation(), TEMPSUMMON_CORPSE_TIMED_DESPAWN, 500);
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
                pet->GetMap()->AddToMap((Creature*)pet);
                   
            // visual effect for levelup
            pet->SetUInt32Value(UNIT_FIELD_LEVEL, player->getLevel());
     
           
            if(!pet->InitStatsForLevel(player->getLevel()))
                // sLog->outError("Pet Create fail: no init stats for entry %u", entry);
     
            pet->UpdateAllStats();
           
            // caster have pet now
            player->SetMinion(pet, true);
     
            pet->SavePetToDB(PET_SAVE_AS_CURRENT);
            pet->InitTalentForLevel();
            player->PetSpellInitialize();
           
            //end
            player->PlayerTalkClass->SendCloseGossip();
            m_creature->MonsterWhisper("Pet added. You might want to feed it and name it somehow.", player->GetGUID());
        }
     
     
        bool OnGossipHello(Player *player, Creature * m_creature)
        {
     
            if(player->getClass() != CLASS_HUNTER)
            {
                m_creature->MonsterWhisper("You are not a Hunter!", player->GetGUID());
                return true;
            }
            player->ADD_GOSSIP_ITEM(4, "Get a New Pet.", GOSSIP_SENDER_MAIN, 30);
            if (player->CanTameExoticPets())
            {
                player->ADD_GOSSIP_ITEM(4, "Get a New Exotic Pet.", GOSSIP_SENDER_MAIN, 50);
            }
            player->ADD_GOSSIP_ITEM(2, "Take me to the Stable.", GOSSIP_SENDER_MAIN, GOSSIP_OPTION_STABLEPET);
            player->ADD_GOSSIP_ITEM(6, "Sell me some Food for my Pet.", GOSSIP_SENDER_MAIN, GOSSIP_OPTION_VENDOR);
                    player->ADD_GOSSIP_ITEM(5, "Close Beastmaster Window.", GOSSIP_SENDER_MAIN, 150);
            player->SEND_GOSSIP_MENU(1, m_creature->GetGUID());
            return true;
        }
     
        bool OnGossipSelect(Player *player, Creature * m_creature, uint32 sender, uint32 action)
        {
                    player->PlayerTalkClass->ClearMenus();
            switch (action)
            {
           
            case 100:
                player->ADD_GOSSIP_ITEM(4, "Get a New Pet.", GOSSIP_SENDER_MAIN, 30);
                if (player->CanTameExoticPets())
                {
                    player->ADD_GOSSIP_ITEM(4, "Get a New Exotic Pet.", GOSSIP_SENDER_MAIN, 50);
                }
                player->ADD_GOSSIP_ITEM(2, "Take me to the Stable.", GOSSIP_SENDER_MAIN, GOSSIP_OPTION_STABLEPET);
                // player->ADD_GOSSIP_ITEM(6, "Sell me some Food for my Pet.", GOSSIP_SENDER_MAIN, GOSSIP_OPTION_VENDOR);
                            player->ADD_GOSSIP_ITEM(5, "Close Beastmaster Window.", GOSSIP_SENDER_MAIN, 150);
                player->SEND_GOSSIP_MENU(1, m_creature->GetGUID());
                    break;
     
                    case 150:
                            player->CLOSE_GOSSIP_MENU();
                    break;
            case 30:
                player->ADD_GOSSIP_ITEM(2, "<- Back to Main Menu.", GOSSIP_SENDER_MAIN, 100);
                player->ADD_GOSSIP_ITEM(4, "Next Page. ->", GOSSIP_SENDER_MAIN, 31);
                player->ADD_GOSSIP_ITEM(6, "Bat.", GOSSIP_SENDER_MAIN, 18);
                player->ADD_GOSSIP_ITEM(6, "Bear.", GOSSIP_SENDER_MAIN, 1);
                player->ADD_GOSSIP_ITEM(6, "Boar.", GOSSIP_SENDER_MAIN, 2);
                player->ADD_GOSSIP_ITEM(6, "Cat.", GOSSIP_SENDER_MAIN, 4);
                player->ADD_GOSSIP_ITEM(6, "Carrion Bird.", GOSSIP_SENDER_MAIN, 5);
                player->ADD_GOSSIP_ITEM(6, "Crab.", GOSSIP_SENDER_MAIN, 6);
                player->ADD_GOSSIP_ITEM(6, "Crocolisk.", GOSSIP_SENDER_MAIN, 7);
                player->ADD_GOSSIP_ITEM(6, "Dragonhawk.", GOSSIP_SENDER_MAIN, 17);
                player->ADD_GOSSIP_ITEM(6, "Gorilla.", GOSSIP_SENDER_MAIN, 8);
                player->ADD_GOSSIP_ITEM(6, "Hound.", GOSSIP_SENDER_MAIN, 9);
                player->ADD_GOSSIP_ITEM(6, "Hyena.", GOSSIP_SENDER_MAIN, 10);
                player->ADD_GOSSIP_ITEM(6, "Moth.", GOSSIP_SENDER_MAIN, 11);
                player->ADD_GOSSIP_ITEM(6, "Owl.", GOSSIP_SENDER_MAIN, 12);
                player->SEND_GOSSIP_MENU(1, m_creature->GetGUID());
                    break;
           
            case 31:  
                player->ADD_GOSSIP_ITEM(2, "<- Back to Main Menu.", GOSSIP_SENDER_MAIN, 30);
                player->ADD_GOSSIP_ITEM(4, "<- Previous Page.", GOSSIP_SENDER_MAIN, 30);
                player->ADD_GOSSIP_ITEM(6, "Raptor.", GOSSIP_SENDER_MAIN, 20);
                player->ADD_GOSSIP_ITEM(6, "Ravager.", GOSSIP_SENDER_MAIN, 19);
                player->ADD_GOSSIP_ITEM(6, "Strider.", GOSSIP_SENDER_MAIN, 13);
                player->ADD_GOSSIP_ITEM(6, "Scorpid.", GOSSIP_SENDER_MAIN, 414);
                player->ADD_GOSSIP_ITEM(6, "Spider.", GOSSIP_SENDER_MAIN, 16);
                player->ADD_GOSSIP_ITEM(6, "Serpent.", GOSSIP_SENDER_MAIN, 21);  
                player->ADD_GOSSIP_ITEM(6, "Turtle.", GOSSIP_SENDER_MAIN, 15);
                player->ADD_GOSSIP_ITEM(6, "Wasp.", GOSSIP_SENDER_MAIN, 93);
                player->SEND_GOSSIP_MENU(1, m_creature->GetGUID());
                    break;
           
            case 50:  
                player->ADD_GOSSIP_ITEM(2, "<- Back to Main Menu.", GOSSIP_SENDER_MAIN, 100);
                            player->ADD_GOSSIP_ITEM(2, "<- Get a New Normal Pet.", GOSSIP_SENDER_MAIN, 100);
                player->ADD_GOSSIP_ITEM(6, "Chimaera.", GOSSIP_SENDER_MAIN, 51);
                player->ADD_GOSSIP_ITEM(6, "Core Hound.", GOSSIP_SENDER_MAIN, 52);
                player->ADD_GOSSIP_ITEM(6, "Devilsaur.", GOSSIP_SENDER_MAIN, 53);
                player->ADD_GOSSIP_ITEM(6, "Rhino.", GOSSIP_SENDER_MAIN, 54);
                player->ADD_GOSSIP_ITEM(6, "Silithid.", GOSSIP_SENDER_MAIN, 55);
                player->ADD_GOSSIP_ITEM(6, "Worm.", GOSSIP_SENDER_MAIN, 56);  
                player->ADD_GOSSIP_ITEM(6, "Loque'nahak.", GOSSIP_SENDER_MAIN, 57);
                player->ADD_GOSSIP_ITEM(6, "Skoll.", GOSSIP_SENDER_MAIN, 58);
                player->ADD_GOSSIP_ITEM(6, "Gondria.", GOSSIP_SENDER_MAIN, 59);
                player->SEND_GOSSIP_MENU(1, m_creature->GetGUID());
                    break;
         
                case GOSSIP_OPTION_STABLEPET:
                    player->GetSession()->SendStablePet(m_creature->GetGUID());
                break;
                case GOSSIP_OPTION_VENDOR:
                   player->GetSession()->SendListInventory(m_creature->GetGUID());
                break;
                case 51: //chimera
                    CreatePet(player, m_creature, 21879);
                break;
                case 52: //core hound
                    CreatePet(player, m_creature, 21108);
                break;
                case 53: //Devilsaur
                    CreatePet(player, m_creature, 20931);
                break;
                case 54: //rhino
                    CreatePet(player, m_creature, 30445);
                break;
                case 55: //silithid
                    CreatePet(player, m_creature, 5460);
                break;
                case 56: //Worm
                    CreatePet(player, m_creature, 30148);
                break;
                case 57: //Loque'nahak
                    CreatePet(player, m_creature, 32517);
                break;
                case 58: //Skoll
                    CreatePet(player, m_creature, 35189);
                break;
                case 59: //Gondria
                    CreatePet(player, m_creature, 33776);
                break;
                case 16: //Spider
                    CreatePet(player, m_creature, 2349);
                break;
                case 17: //Dragonhawk
                    CreatePet(player, m_creature, 27946);
                break;
                case 18: //Bat
                    CreatePet(player, m_creature, 28233);
                break;
                case 19: //Ravager
                    CreatePet(player, m_creature, 17199);
                break;
                case 20: //Raptor
                    CreatePet(player, m_creature, 14821);
                break;
                case 21: //Serpent
                    CreatePet(player, m_creature, 28358);
                break;
                case 1: //bear
                    CreatePet(player, m_creature, 29319);
                break;
                case 2: //Boar
                    CreatePet(player, m_creature, 29996);
                break;
                case 93: //Bug
                    CreatePet(player, m_creature, 28085);
                            break;
                case 4: //cat
                    CreatePet(player, m_creature, 28097);
                            break;
                case 5: //carrion
                    CreatePet(player, m_creature, 26838);
                            break;
                case 6: //crab
                    CreatePet(player, m_creature, 24478);
                            break;  
                case 7: //crocolisk
                    CreatePet(player, m_creature, 1417);
                            break;  
                case 8: //gorila
                    CreatePet(player, m_creature, 28213);
                            break;
                case 9: //hound
                    CreatePet(player, m_creature, 29452);
                            break;
                case 10: //hynea
                    CreatePet(player, m_creature, 13036);
                            break;
                case 11: //Moth
                    CreatePet(player, m_creature, 27421);
                            break;
                case 12: //owl
                    CreatePet(player, m_creature, 23136);
                            break;
                case 13: //strider
                    CreatePet(player, m_creature, 22807);
                            break;
                case 414: //scorpid
                    CreatePet(player, m_creature, 9698);
                            break;
                case 15: //turtle
                    CreatePet(player, m_creature, 25482);
                            break;
            }
            return true;
        }
    };
     
    void AddSC_Npc_Beastmaster()
    {
        new Npc_Beastmaster();
    }
