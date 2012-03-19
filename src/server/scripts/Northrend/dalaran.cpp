/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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

/* Script Data Start
SDName: Dalaran
SDAuthor: WarHead, MaXiMiUS
SD%Complete: 99%
SDComment: For what is 63990+63991? Same function but don't work correct...
SDCategory: Dalaran
Script Data End */

#include "ScriptPCH.h"

/*******************************************************
 * npc_mageguard_dalaran
 *******************************************************/

enum Spells
{
    SPELL_TRESPASSER_A = 54028,
    SPELL_TRESPASSER_H = 54029,

    SPELL_SUNREAVER_DISGUISE_FEMALE        = 70973,
    SPELL_SUNREAVER_DISGUISE_MALE          = 70974,
    SPELL_SILVER_COVENANT_DISGUISE_FEMALE  = 70971,
    SPELL_SILVER_COVENANT_DISGUISE_MALE    = 70972,
};

enum NPCs // All outdoor guards are within 35.0f of these NPCs
{
    NPC_APPLEBOUGH_A = 29547,
    NPC_SWEETBERRY_H = 29715,
};

class npc_mageguard_dalaran : public CreatureScript
{
public:
    npc_mageguard_dalaran() : CreatureScript("npc_mageguard_dalaran") { }

    struct npc_mageguard_dalaranAI : public Scripted_NoMovementAI
    {
        npc_mageguard_dalaranAI(Creature* creature) : Scripted_NoMovementAI(creature)
        {
            creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            creature->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_NORMAL, true);
            creature->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_MAGIC, true);
        }

        void Reset(){}

        void EnterCombat(Unit* /*who*/){}

        void AttackStart(Unit* /*who*/){}

        void MoveInLineOfSight(Unit* who)
        {
            if (!who || !who->IsInWorld() || who->GetZoneId() != 4395)
                return;

            if (!me->IsWithinDist(who, 65.0f, false))
                return;

            Player* player = who->GetCharmerOrOwnerPlayerOrPlayerItself();

            if (!player || player->isGameMaster() || player->IsBeingTeleported() ||
                // If player has Disguise aura for quest A Meeting With The Magister or An Audience With The Arcanist, do not teleport it away but let it pass
                player->HasAura(SPELL_SUNREAVER_DISGUISE_FEMALE) || player->HasAura(SPELL_SUNREAVER_DISGUISE_MALE) ||
                player->HasAura(SPELL_SILVER_COVENANT_DISGUISE_FEMALE) || player->HasAura(SPELL_SILVER_COVENANT_DISGUISE_MALE))
                return;

            switch (me->GetEntry())
            {
                case 29254:
                    if (player->GetTeam() == HORDE && !(player->HasAura(SPELL_SILVER_COVENANT_DISGUISE_MALE) || player->HasAura(SPELL_SILVER_COVENANT_DISGUISE_FEMALE)))      // Horde unit found in Alliance area
                    {
                        if (GetClosestCreatureWithEntry(me, NPC_APPLEBOUGH_A, 32.0f))
                        {
                            if (me->isInBackInMap(who, 12.0f))   // In my line of sight, "outdoors", and behind me
                                DoCast(who, SPELL_TRESPASSER_A); // Teleport the Horde unit out
                        }
                        else                                      // In my line of sight, and "indoors"
                            DoCast(who, SPELL_TRESPASSER_A);     // Teleport the Horde unit out
                    }
                    break;
                case 29255:
                    if (player->GetTeam() == ALLIANCE && !(player->HasAura(SPELL_SUNREAVER_DISGUISE_MALE) || player->HasAura(SPELL_SUNREAVER_DISGUISE_FEMALE)))  // Alliance unit found in Horde area
                    {
                        if (GetClosestCreatureWithEntry(me, NPC_SWEETBERRY_H, 32.0f))
                        {
                            if (me->isInBackInMap(who, 12.0f))   // In my line of sight, "outdoors", and behind me
                                DoCast(who, SPELL_TRESPASSER_H); // Teleport the Alliance unit out
                        }
                        else                                      // In my line of sight, and "indoors"
                            DoCast(who, SPELL_TRESPASSER_H);     // Teleport the Alliance unit out
                    }
                    break;
            }
            me->SetOrientation(me->GetHomePosition().GetOrientation());
            return;
        }

        void UpdateAI(const uint32 /*diff*/){}
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_mageguard_dalaranAI(creature);
    }
};

/*######
## npc_hira_snowdawn
######*/

enum eHiraSnowdawn
{
    SPELL_COLD_WEATHER_FLYING                   = 54197
};

#define GOSSIP_TEXT_TRAIN_HIRA "I seek training to ride a steed."

class npc_hira_snowdawn : public CreatureScript
{
public:
    npc_hira_snowdawn() : CreatureScript("npc_hira_snowdawn") { }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (!creature->isVendor() || !creature->isTrainer())
            return false;

        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, GOSSIP_TEXT_TRAIN_HIRA, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRAIN);

        if (player->getLevel() >= 80 && player->HasSpell(SPELL_COLD_WEATHER_FLYING))
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, GOSSIP_TEXT_BROWSE_GOODS, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRADE);

        player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());

        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();
        if (action == GOSSIP_ACTION_TRAIN)
            player->GetSession()->SendTrainerList(creature->GetGUID());

        if (action == GOSSIP_ACTION_TRADE)
            player->GetSession()->SendListInventory(creature->GetGUID());

        return true;
    }
};

/*######
## npc_archmage_vargoth
######*/

enum eArchmageVargoth
{
    ZONE_DALARAN                                = 4395,
    ITEM_ACANE_MAGIC_MASTERY                    = 43824,
    SPELL_CREATE_FAMILAR                        = 61457,
    SPELL_FAMILAR_PET                           = 61472,
    ITEM_FAMILAR_PET                            = 44738
};

#define GOSSIP_TEXT_FAMILIAR_WELCOME "I have a book that might interest you. Would you like to take a look?"
#define GOSSIP_TEXT_FAMILIAR_THANKS  "Thank you! I will be sure to notify you if I find anything else."

class npc_archmage_vargoth : public CreatureScript
{
    public:
        npc_archmage_vargoth() : CreatureScript("npc_archmage_vargoth") { }

        bool OnGossipHello(Player* player, Creature* creature)
        {
            if (creature->isQuestGiver() && creature->GetZoneId() != ZONE_DALARAN)
                player->PrepareQuestMenu(creature->GetGUID());

            if (player->HasItemCount(ITEM_ACANE_MAGIC_MASTERY, 1, false))
            {
                if (!player->HasSpell(SPELL_FAMILAR_PET) && !player->HasItemCount(ITEM_FAMILAR_PET, 1, true))
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_FAMILIAR_WELCOME, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            }

            player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());

            return true;
        }

        bool OnGossipSelect (Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
        {
            switch (action)
            {
                case GOSSIP_ACTION_INFO_DEF + 1:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_FAMILIAR_THANKS, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
                    player->SEND_GOSSIP_MENU(40006, creature->GetGUID());
                    break;
                case GOSSIP_ACTION_INFO_DEF + 2:
                    creature->CastSpell(player, SPELL_CREATE_FAMILAR, false);
                    player->CLOSE_GOSSIP_MENU();
                    break;
            }

            return true;
        }
};

/*######
## npc_rhonin
######*/

enum npcRhonin
{
    ACHIEVEMENT_HIGHER_LEARNING             = 1956,
    ITEM_THE_SCHOOLS_OF_ARCANE_MAGIC        = 43824,
    SPELL_THE_SCHOOLS_OF_ARCANE_MAGIC       = 59983,
    //QUEST_ALL_IS_WELL_THAT_ENDS_WELL        = 13631,
    //QUEST_HEROIC_ALL_IS_WELL_THAT_ENDS_WELL = 13819
};

#define GOSSIP_TEXT_RESTORE_ITEM       "[PH] Please give me a new <The Schools of Arcane Magic - Mastery>"

class npc_rhonin : public CreatureScript
{
    public:
        npc_rhonin() : CreatureScript("npc_rhonin") { }

        bool OnGossipHello(Player* player, Creature* creature)
        {
            if (creature->isQuestGiver())
                player->PrepareQuestMenu(creature->GetGUID());

            if (player->HasAchieved(ACHIEVEMENT_HIGHER_LEARNING) && !player->HasItemCount(ITEM_THE_SCHOOLS_OF_ARCANE_MAGIC, 1, true))
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_RESTORE_ITEM, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

            player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
            return true;
        }

        bool OnGossipSelect(Player* player, Creature* /*creature*/, uint32 /*sender*/, uint32 action)
        {
            player->PlayerTalkClass->ClearMenus();

            if (action == GOSSIP_ACTION_INFO_DEF + 1)
            {
                player->CastSpell(player, SPELL_THE_SCHOOLS_OF_ARCANE_MAGIC, false);
                player->CLOSE_GOSSIP_MENU();
            }

            return true;
        }

        // FIXME: add Quest 13631, 13819 Event

        //bool OnQuestComplete(Player* /*player*/, Creature* /*creature*/, Quest const* /*quest*/)
        //{
        //    return true;
        //}
};

/*######

## go_memorial_plaque_play_movie

######*/

enum GOSSIPS

{
        FALL_OF_THE_LICH_KING,
};

#define GOSSIP_TEXT_SEE_FALL_OF_THE_LICH_KING "See Fall of the Lich King."
#define GOSSIP_MESSAGE_MEMORIAL 15921

class go_memorial_plaque_play_movie : public GameObjectScript
{
public:
        go_memorial_plaque_play_movie() : GameObjectScript("go_memorial_plaque_play_movie") { }
        
        bool OnGossipHello(Player *player, GameObject *go)
        {
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_SEE_FALL_OF_THE_LICH_KING, GOSSIP_SENDER_MAIN, FALL_OF_THE_LICH_KING);
                player->SEND_GOSSIP_MENU(GOSSIP_MESSAGE_MEMORIAL, go->GetGUID());
                return true;
        }

        bool OnGossipSelect(Player *player, GameObject *go, uint32 /*uiSender*/, uint32 uiAction)
        {
                player->PlayerTalkClass->ClearMenus();
                switch(uiAction)
                {
                        case FALL_OF_THE_LICH_KING:
                                player->SendMovieStart(16);
                                player->CLOSE_GOSSIP_MENU();
                                break;

                }
                return true;
        }

};

void AddSC_dalaran()
{
    new npc_mageguard_dalaran();
    new npc_hira_snowdawn();
    new npc_archmage_vargoth();
    new npc_rhonin();
    new go_memorial_plaque_play_movie;
}
