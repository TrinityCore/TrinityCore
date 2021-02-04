//########################################################################################################################
//Stitch Fevrier 2021 - npc_gossip_menu_option_new - version 1.0 , wow 9.0.2.37142 
// Remplacement des gossip_menu_option des Maitres des professions
//########################################################################################################################

/*
UPDATE `creature_template` SET `gossip_menu_id` = 10351,`npcflag` = `npcflag`|81,`ScriptName` = "npc_gossip_menu_option_new"  WHERE `subname`="Mining Trainer";
UPDATE `creature_template` SET `gossip_menu_id` = 10351,`npcflag` = `npcflag`|209,`ScriptName` = "npc_gossip_menu_option_new"  WHERE `subname`="Mining Trainer & Supplies";
UPDATE `creature_trainer` SET `MenuId` = '10351' WHERE `creature_trainer`.`Trainerid` = 91;
UPDATE `creature_template` SET `gossip_menu_id` = 7842,`npcflag` = `npcflag`|81,`ScriptName` = "npc_gossip_menu_option_new"  WHERE `subname`="Skinning Trainer";
UPDATE `creature_trainer` SET `MenuId` = '7842' WHERE `creature_trainer`.`Trainerid` = 196;
UPDATE `creature_template` SET `gossip_menu_id` = 7459,`npcflag` = `npcflag`|81,`ScriptName` = "npc_gossip_menu_option_new"  WHERE `subname`="Master Herbalist" OR `subname`="Herbalism Trainer";
UPDATE `creature_trainer` SET `MenuId` = '7459' WHERE `creature_trainer`.`Trainerid` = 5000;
UPDATE `creature_template` SET `gossip_menu_id` = 9879,`npcflag` = `npcflag`|81,`ScriptName` = "npc_gossip_menu_option_new"  WHERE `subname`="Inscription Trainer";
UPDATE `creature_template` SET `gossip_menu_id` = 9879,`npcflag` = `npcflag`|209,`ScriptName` = "npc_gossip_menu_option_new"  WHERE `subname`="Inscription Trainer & Supplies";
UPDATE `creature_trainer` SET `MenuId` = '9879' WHERE `creature_trainer`.`Trainerid` = 63;
UPDATE `creature_template` SET `gossip_menu_id` = 11821, `npcflag` = `npcflag`|81, `ScriptName` = "npc_gossip_menu_option_new"  WHERE `subname`="Archaeology Trainer";
UPDATE `creature_trainer` SET `MenuId` = '11821' WHERE `creature_trainer`.`Trainerid` = 373;
UPDATE `creature_template` SET `gossip_menu_id` = 11821,`npcflag` = `npcflag`|81,`ScriptName` = "npc_gossip_menu_option_new"  WHERE `subname`="Archaeology Trainer";
UPDATE `creature_trainer` SET `MenuId` = '11821' WHERE `creature_trainer`.`Trainerid` = 373;
UPDATE `creature_template` SET `gossip_menu_id` = 5853,`npcflag` = `npcflag`|81,`ScriptName` = "npc_gossip_menu_option_new"  WHERE `subname`="Cooking Trainer";
UPDATE `creature_template` SET `gossip_menu_id` = 5853,`npcflag` = `npcflag`|209,`ScriptName` = "npc_gossip_menu_option_new"  WHERE `subname`="Cooking Trainer & Supplies" OR `subname`="Master of Cooking";
UPDATE `creature_trainer` SET `MenuId` = '5853' WHERE `creature_trainer`.`Trainerid` = 373;
UPDATE `creature_template` SET `gossip_menu_id` = 10364,`npcflag` = `npcflag`|81,`ScriptName` = "npc_gossip_menu_option_new"  WHERE `subname`="Tailoring Trainer" OR `subname`="Tailoring Trainer & Dreamcloth Trader";
UPDATE `creature_trainer` SET `MenuId` = '10364' WHERE `creature_trainer`.`Trainerid` = 163;
UPDATE `creature_template` SET `gossip_menu_id` = 10363,`npcflag` = `npcflag`|81,`ScriptName` = "npc_gossip_menu_option_new"  WHERE `subname`="Engineering Trainer" OR `subname`="Gnomish Engineering Trainer" OR `subname`="Goblin Engineering Trainer";
UPDATE `creature_trainer` SET `MenuId` = '10363' WHERE `creature_trainer`.`Trainerid` = 407;
UPDATE `creature_template` SET `gossip_menu_id` = 10361,`npcflag` = `npcflag`|81,`ScriptName` = "npc_gossip_menu_option_new"  WHERE `subname`="Leatherworking Trainer";
UPDATE `creature_trainer` SET `MenuId` = '10361' WHERE `creature_trainer`.`Trainerid` = 56;
UPDATE `creature_template` SET `gossip_menu_id` = 10627,`npcflag` = `npcflag`|81,`ScriptName` = "npc_gossip_menu_option_new"  WHERE `subname`="Alchemy Trainer";
UPDATE `creature_trainer` SET `MenuId` = '10627' WHERE `creature_trainer`.`Trainerid` = 122;
UPDATE `creature_template` SET `gossip_menu_id` = 2784,`npcflag` = `npcflag`|81,`ScriptName` = "npc_gossip_menu_option_new"  WHERE `subname`="Blacksmithing Trainer";
UPDATE `creature_template` SET `gossip_menu_id` = 2784,`npcflag` = `npcflag`|4305,`ScriptName` = "npc_gossip_menu_option_new"  WHERE `subname`="Blacksmithing Trainer & Supplies";
UPDATE `creature_trainer` SET `MenuId` = '2784' WHERE `creature_trainer`.`Trainerid` = 27;
UPDATE `creature_template` SET `gossip_menu_id` = 7361,`npcflag` = `npcflag`|81,`ScriptName` = "npc_gossip_menu_option_new"  WHERE `subname`="Fishing Trainer";
UPDATE `creature_template` SET `gossip_menu_id` = 7361,`npcflag` = `npcflag`|209,`ScriptName` = "npc_gossip_menu_option_new"  WHERE `subname`="Fishing Trainer & Supplies";
UPDATE `creature_trainer` SET `MenuId` = '7361' WHERE `creature_trainer`.`Trainerid` = 10;
UPDATE `creature_template` SET `gossip_menu_id` = 12843,`npcflag` = `npcflag`|81,`ScriptName` = "npc_gossip_menu_option_new"  WHERE `subname`="Enchanting Trainer";
UPDATE `creature_template` SET `gossip_menu_id` = 12843,`npcflag` = `npcflag`|209,`ScriptName` = "npc_gossip_menu_option_new"  WHERE `subname`="Enchanting Trainer & Supplies";
UPDATE `creature_trainer` SET `MenuId` = '12843' WHERE `creature_trainer`.`Trainerid` = 62;
UPDATE `creature_template` SET `gossip_menu_id` = 12843,`npcflag` = `npcflag`|81,`ScriptName` = "npc_gossip_menu_option_new"  WHERE `subname`="Jewelcrafting Trainer" ;
UPDATE `creature_template` SET `gossip_menu_id` = 12843,`npcflag` = `npcflag`|209,`ScriptName` = "npc_gossip_menu_option_new"  WHERE `subname`="Jewelcrafting Trainer & Supplies";
UPDATE `creature_trainer` SET `MenuId` = '12843' WHERE `creature_trainer`.`Trainerid` = 29;
UPDATE `creature_template` SET `gossip_menu_id` = 10723,`npcflag` = `npcflag`|17,`ScriptName` = "npc_gossip_menu_option_new"  WHERE `subname`="Riding Trainer" OR `subname`="Flying Trainer" OR `subname`="Cold Weather Flying Trainer";
UPDATE `creature_trainer` SET `MenuId` = '10723' WHERE `creature_trainer`.`Trainerid` = 46;
REPLACE INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `incrtime`, `ExtendedCost`, `type`, `VerifiedBuild`) VALUES
(31238, 0, 49177, 0, 0, 0, 1, 0);
*/


#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "Player.h"
#include "WorldSession.h"
#include "GameEventMgr.h"
#include "Trainer.h"
#include "ObjectMgr.h"

#define LOCALE_VENDOR_0 "Let me browse your goods."
#define LOCALE_VENDOR_2 "Permettez-moi de regarder vos marchandises."
#define LOCALE_TRAINER_0 "Train me"
#define LOCALE_TRAINER_2 "Je souhaiterais une formation"



uint32 Npc_Emotes_A[4] = { 604, 273, 66, 1 };       // QUESTION , OUI , SALUER , PARLER
uint32 Npc_Emotes_B[2] = { 4, 401 };                // CONTANT , DANCES_PECIAL
uint32 SPELL_POUR_VISUEL_GOSSIP = 14867;

// GOSSIP_ICON_CHAT         GOSSIP_ICON_VENDOR      GOSSIP_ICON_TAXI        GOSSIP_ICON_TRAINER     GOSSIP_ICON_INTERACT_1   GOSSIP_ICON_INTERACT_2
// GOSSIP_ICON_MONEY_BAG    GOSSIP_ICON_TALK        GOSSIP_ICON_TABARD      GOSSIP_ICON_BATTLE      GOSSIP_ICON_DOT

class npc_gossip_menu_option_new : public CreatureScript
{
public:
    npc_gossip_menu_option_new() : CreatureScript("npc_gossip_menu_option_new") {}
    struct npc_gossip_menu_option_newAI : public ScriptedAI
    {
        npc_gossip_menu_option_newAI(Creature* creature) : ScriptedAI(creature) { }

        bool GossipHello(Player* player) override
        {
            if (player->GetGossipTextId(me) != 0)
            {
                SendGossipMenuFor(player, player->GetGossipTextId(me), me->GetGUID());  // NPC_txt pointant sur BroadcastText
            }
            //-------------------------------------------------------------------------------- QUETE
            if (me->IsQuestGiver())
            {
                player->PrepareQuestMenu(me->GetGUID());
            }
            //-------------------------------------------------------------------------------- VENDEUR
            if (me->IsVendor())
            {
                char const* localizedEntry;
                switch (player->GetSession()->GetSessionDbcLocale())
                {
                case LOCALE_frFR: localizedEntry = LOCALE_VENDOR_2; break;
                case LOCALE_enUS: default: localizedEntry = LOCALE_VENDOR_0;
                }
                AddGossipItemFor(player, GOSSIP_ICON_VENDOR, localizedEntry, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            }
            //-------------------------------------------------------------------------------- TRAINER PROFESSION
            if (me->HasNpcFlag(UNIT_NPC_FLAG_TRAINER_PROFESSION))
            {
                char const* localizedEntry;
                switch (player->GetSession()->GetSessionDbcLocale())
                {
                case LOCALE_frFR: localizedEntry = LOCALE_TRAINER_2; break;
                case LOCALE_enUS: default: localizedEntry = LOCALE_TRAINER_0;
                }
                AddGossipItemFor(player, GOSSIP_ICON_TRAINER, localizedEntry, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
            }

            //--------------------------------------------------------------------------------




            uint32 NPC_EMOTE_A = Npc_Emotes_A[urand(0, 3)];
            me->HandleEmoteCommand(NPC_EMOTE_A);                                            // QUESTION , OUI , SALUER , PARLER

            if (player->GetGossipTextId(me) != 0)
            {
                SendGossipMenuFor(player, player->GetGossipTextId(me), me->GetGUID());  // NPC_txt pointant sur BroadcastText
            }
            return true;
        }

        bool GossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
        {
            uint32 const action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
            uint32 trainerId;
            ClearGossipMenuFor(player);

            switch (action)
            {
            case GOSSIP_ACTION_INFO_DEF + 1: //----------------------------------------------- VENDEUR
            {
                player->GetSession()->SendListInventory(me->GetGUID());
                break;
            }
            case GOSSIP_ACTION_INFO_DEF + 2: //----------------------------------------------- TRAINER PROFESSION
            {
                std::string _SubName = sObjectMgr->GetCreatureTemplate(me->GetEntry())->SubName;


                //###########################################################################################
                //      PROFESSIONS
                //###########################################################################################
                // --- MINING ------------------- Minage : (Trainer vendeur 91 - 10351 - 0)
                if (_SubName == "Mining Trainer" || _SubName == "Mining Trainer & Supplies")
                { trainerId = 91; }

                // --- SKINNING ----------------- Dépeçage: (Trainer 196 - 7842 - 0)
                if (_SubName == "Skinning Trainer")
                { trainerId = 196; }

                // --- HERBALISM ---------------- Herboristerie : (Trainer 5000/133 - 7459 - 0)
                if (_SubName == "Master Herbalist" || _SubName == "Herbalism Trainer")
                { trainerId = 5000; } // trainerId Custom

                // --- INSCRIPTION -------------- Calligraphie: (Trainer vendeur 63 - 9879 - 0)
                if (_SubName == "Inscription Trainer" || _SubName == "Inscription Trainer & Supplies")
                { trainerId = 63; }

                // --- ARCHAEOLOGY -------------- Archéologie: (Trainer quete 373 - 11821 - 0)
                if (_SubName == "Archaeology Trainer")
                { trainerId = 373; }

                // --- COOKING ------------------ Cuisine: (Trainer vendeur quete 136 - 5853 - 0)
                if (_SubName == "Cooking Trainer" || _SubName == "Cooking Trainer & Supplies" || (_SubName == "Master of Cooking"))
                { trainerId = 136; }

                // --- TAILORING ---------------- Couture : (Trainer vendeur 163 - 10364 - 0)
                if (_SubName == "Tailoring Trainer" )
                { trainerId = 163; }

                // --- ENGINEERING -------------- Ingénierie : (Trainer vendeur 407 - 10363 - 0)
                if (_SubName == "Engineering Trainer" || _SubName == "Gnomish Engineering Trainer" || _SubName == "Goblin Engineering Trainer")
                { trainerId = 407; }

                // --- LEATHERWORKING ----------- Travail du cuir : (Trainer 56 - 10361 - 0)  (Trainer vendeur 56 - 12852 - 0) (Trainer quete 56 7430 0)
                if (_SubName == "Leatherworking Trainer")
                { trainerId = 56; }

                // --- ALCHEMY ------------------ Alchimie : (Trainer quete 122 - 10627 - 0) Alchemy Trainer
                if (_SubName == "Alchemy Trainer")
                { trainerId = 122; }

                // --- BLACKSMITHING ------------ Forge: (Trainer 29 - 0) (+vendeur 27 - 10362 - 0) (+vendeur reparateur 27 - 2784 - 0)
                if (_SubName == "Blacksmithing Trainer" || _SubName == "Blacksmithing Trainer & Supplies")
                { trainerId = 27; }

                // --- FISHING ------------------ Pêche : (Trainer 10 - 7361 - 0)
                if (_SubName == "Fishing Trainer" || _SubName == "Fishing Trainer & Supplies")
                { trainerId = 10; }

                // --- ENCHANTING --------------- Enchantement: (Trainer vendeur 62 - 12843 - 0) 
                if (_SubName == "Enchanting Trainer" || _SubName == "Enchanting Trainer & Supplies")
                { trainerId = 62; }

                // --- JEWELCRAFTING ----------- Joaillerie : (Trainer 29-11861-0) (Trainer vendeur 29-8646-0) (Trainer quete 29-9894-0) (Trainer vendeur quete 29-12848-0)
                if (_SubName == "Jewelcrafting Trainer" || _SubName == "Jewelcrafting Trainer & Supplies")
                { trainerId = 29; }

                //###########################################################################################

                // --- RIDING ------------------ Competences de Monte : (Trainer  46 - 0 - 0)
                if (_SubName == "Riding Trainer" || _SubName == "Flying Trainer" || _SubName == "Cold Weather Flying Trainer")
                { trainerId = 46; }



                
                if (trainerId != 0)
                {
                    player->GetSession()->SendTrainerList(me, trainerId);
                }

                break;
            }


            default:
                break;

            //--------------------------------------------------------------------------------


            if (player->GetGossipTextId(me) !=0)
            {
                SendGossipMenuFor(player, player->GetGossipTextId(me), me->GetGUID());
            }

            uint32 NPC_EMOTE_B = Npc_Emotes_B[urand(0, 1)];
            me->HandleEmoteCommand(NPC_EMOTE_B);                                    // CONTANT , DANCES_PECIAL

            //CloseGossipMenuFor(player); //
            //player->SaveToDB();
            return true;
            }
        }



    };



        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_gossip_menu_option_newAI(creature);
        }
    };
    void AddSC_npc_gossip_menu_option_new()
    {
        new npc_gossip_menu_option_new();
    }







