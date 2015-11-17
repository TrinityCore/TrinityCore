/* Copyright (C) 2010 SAMCC Studios <http://www.samccstudios.com/>
 * Written by LordPsyan
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

 /*
Script Name: npc_buff v1.1
Complete: 100%
Comment: Database Driven Buff Master
*/

#include "Config.h"

#define GOSSIP_SENDER_MAIN      1000
#define GOSSIP_SMALLBUFF        2000
#define GOSSIP_LARGEBUFF        3000
#define GOSSIP_GMBUFF           4000
#define GOSSIP_PLAYERTOOLS      5000

#define SPELL_RESURRECTION_SICKNESS_15007  15007

#define NB_BUFF_PAGE            10
#define MSG_TYPE                100002
#define MSG_BUFF                100003

#define NEXT_PAGE               "-> [Next Page]"
#define PREV_PAGE               "<- [Previous Page]"
#define MAIN_MENU               "<= [Main Menu]"

class npc_buff : public CreatureScript
{
public:
    npc_buff() : CreatureScript("npc_buff") {}

bool OnGossipHello(Player* pPlayer, Creature* pCreature)
{
    if(sConfigMgr->GetBoolDefault("Npc_Buff.OnlyGMs", false)) // If Npc_Buff.OnlyGMs is enabled in worldserver.conf
        if (pPlayer->GetSession()->GetSecurity() == SEC_PLAYER)
        {
            pCreature->Whisper("Sorry, I can only Buff Platinum Members.", LANG_UNIVERSAL, pPlayer);
            return true;
        }

    bool EnableSmallBuff = sConfigMgr->GetBoolDefault("Npc_Buff.EnableSmallBuff", true);
    bool EnableGreatBuff = sConfigMgr->GetBoolDefault("Npc_Buff.EnableGreatBuff", true);
    bool EnableGMBuff = sConfigMgr->GetBoolDefault("Npc_Buff.EnableGMBuff", true);
    bool EnablePlayerTools = sConfigMgr->GetBoolDefault("Npc_Buff.EnablePlayerTools", true);
    bool EnableResSickness = sConfigMgr->GetBoolDefault("Npc_Buff.EnableRemoveResSickness", true);
    bool EnableGivemeGold = sConfigMgr->GetBoolDefault("Npc_Buff.EnableGivemeGold", false);

    // Main Menu

    // Check config if "Small  Buff " is enabled or not
    if(EnableSmallBuff)
        pPlayer->ADD_GOSSIP_ITEM( 7, "Small Buff ->"              , GOSSIP_SENDER_MAIN, 1000);
    // Check config if "Great Buff" is enabled or not
    if(EnableGreatBuff)
        pPlayer->ADD_GOSSIP_ITEM( 7, "Great Buff ->"              , GOSSIP_SENDER_MAIN, 2000);
    // Check config if "GM Buff" is enabled or not
    if(EnableGMBuff)
    {
    if (pPlayer->GetSession()->GetSecurity() > SEC_PLAYER)
        {
        pPlayer->ADD_GOSSIP_ITEM( 7, "Platinum Members Buff ->"                 , GOSSIP_SENDER_MAIN, 3000);
        }
    }
    // Check config if "Player Tools" is enabled or not
    if(EnablePlayerTools)
        pPlayer->ADD_GOSSIP_ITEM( 7, "Player Tools ->"            , GOSSIP_SENDER_MAIN, 4000);

    // Check config file if "Remove res sickness" option is enabled or not
    if(EnableResSickness)
        pPlayer->ADD_GOSSIP_ITEM( 10, "Remove Resurrect Sickness" , GOSSIP_SENDER_MAIN, 5000);

    pPlayer->SEND_GOSSIP_MENU(MSG_TYPE, pCreature->GetGUID());

return true;
}

bool showSmallBuff(Player *pPlayer, Creature *pCreature, uint32 showFromId = 0)
{


 QueryResult result;
 result = WorldDatabase.PQuery("SELECT `name`, `cat_number` FROM `npc_buff_spells` WHERE `cat_number` < 2000 ORDER BY `cat_number` ASC");

 if (result)
 {
 std::string name = "";
 uint32 catNumber = 0;
  do
 {
 Field *fields = result->Fetch();
 name = fields[0].GetString();
 catNumber = fields[1].GetInt32();

    pPlayer->ADD_GOSSIP_ITEM(9, name, GOSSIP_SENDER_MAIN, catNumber);
}
 while (result->NextRow());

    pPlayer->SEND_GOSSIP_MENU(MSG_BUFF, pCreature->GetGUID());
 return true;
 }
 else
 {
 if (showFromId = 0)
 {
 //you are too poor
 pCreature->Whisper("You don't have enough money.", LANG_UNIVERSAL, pPlayer);
 pPlayer->CLOSE_GOSSIP_MENU();
 }
 else
 {

 //show Spells from beginning
 showSmallBuff(pPlayer, pCreature, 0);
 }
 }

 return false;
}

bool showGreatBuff(Player *pPlayer, Creature *pCreature, uint32 showFromId = 0)
{


 QueryResult result;
 result = WorldDatabase.PQuery("SELECT `name`, `cat_number` FROM `npc_buff_spells` WHERE `cat_number` < 3000 AND `cat_number` > 2000 ORDER BY `cat_number` ASC");

 if (result)
 {
 std::string name = "";
 uint32 catNumber = 0;
  do
 {
 Field *fields = result->Fetch();
 name = fields[0].GetString();
 catNumber = fields[1].GetInt32();

    pPlayer->ADD_GOSSIP_ITEM(9, name, GOSSIP_SENDER_MAIN, catNumber);
}
 while (result->NextRow());

    pPlayer->SEND_GOSSIP_MENU(MSG_BUFF, pCreature->GetGUID());
 return true;
 }
 else
 {
 if (showFromId = 0)
 {
 //you are too poor
 pCreature->Whisper("You don't have enough money.", LANG_UNIVERSAL, pPlayer);
 pPlayer->CLOSE_GOSSIP_MENU();
 }
 else
 {

 //show Spells from beginning
 showGreatBuff(pPlayer, pCreature, 0);
 }
 }

 return false;
}

bool showGmBuff(Player *pPlayer, Creature *pCreature, uint32 showFromId = 0)
{


 QueryResult result;
 result = WorldDatabase.PQuery("SELECT `name`, `cat_number` FROM `npc_buff_spells` WHERE `cat_number` < 4000 AND `cat_number` > 3000 ORDER BY `cat_number` ASC");

 if (result)
 {
 std::string name = "";
 uint32 catNumber = 0;
  do
 {
 Field *fields = result->Fetch();
 name = fields[0].GetString();
 catNumber = fields[1].GetInt32();

    pPlayer->ADD_GOSSIP_ITEM(9, name, GOSSIP_SENDER_MAIN, catNumber);
}
 while (result->NextRow());

    pPlayer->SEND_GOSSIP_MENU(MSG_BUFF, pCreature->GetGUID());
 return true;
 }
 else
 {
 if (showFromId = 0)
 {
 //you are too poor
 pCreature->Whisper("You don't have enough money.", LANG_UNIVERSAL, pPlayer);
 pPlayer->CLOSE_GOSSIP_MENU();
 }
 else
 {

 //show Spells from beginning
 showGmBuff(pPlayer, pCreature, 0);
 }
 }

 return false;
}

bool showPlayerTools(Player *pPlayer, Creature *pCreature, uint32 showFromId = 0)
{


 QueryResult result;
 result = WorldDatabase.PQuery("SELECT `name`, `cat_number` FROM `npc_buff_spells` WHERE `cat_number` < 5000 AND `cat_number` > 4000 ORDER BY `cat_number` ASC");

 if (result)
 {
 std::string name = "";
 uint32 catNumber = 0;
  do
 {
 Field *fields = result->Fetch();
 name = fields[0].GetString();
 catNumber = fields[1].GetInt32();

    pPlayer->ADD_GOSSIP_ITEM(9, name, GOSSIP_SENDER_MAIN, catNumber);
}
 while (result->NextRow());

    pPlayer->SEND_GOSSIP_MENU(MSG_BUFF, pCreature->GetGUID());
 return true;
 }
 else
 {
 if (showFromId = 0)
 {
 //you are too poor
 pCreature->Whisper("You don't have enough money.", LANG_UNIVERSAL, pPlayer);
 pPlayer->CLOSE_GOSSIP_MENU();
 }
 else
 {

 //show Spells from beginning
 showPlayerTools(pPlayer, pCreature, 0);
 }
 }

 return false;
}

void SendDefaultMenu(Player* pPlayer, Creature* pCreature, uint32 uiAction)
{

// Not allow in combat
if (pPlayer->IsInCombat())
{
    pPlayer->CLOSE_GOSSIP_MENU();
    pCreature->Say("You are in combat!", LANG_UNIVERSAL);
    return;
}

    bool EnableSmallBuff = sConfigMgr->GetBoolDefault("Npc_Buff.EnableSmallBuff", true);
    bool EnableGreatBuff = sConfigMgr->GetBoolDefault("Npc_Buff.EnableGreatBuff", true);
    bool EnableGMBuff = sConfigMgr->GetBoolDefault("Npc_Buff.EnableGMBuff", true);
    bool EnablePlayerTools = sConfigMgr->GetBoolDefault("Npc_Buff.EnablePlayerTools", true);
    bool EnableResSickness = sConfigMgr->GetBoolDefault("Npc_Buff.EnableRemoveResSickness", true);
    bool EnableGivemeGold = sConfigMgr->GetBoolDefault("Npc_Buff.EnableGivemeGold", false);

//Money Check
if (pPlayer->GetMoney() < (sConfigMgr->GetFloatDefault("BuffGoldCost",0)))
{
    pPlayer->CLOSE_GOSSIP_MENU();
    pCreature->Whisper("You don't have enough money.", LANG_UNIVERSAL, pPlayer);
    return;
}


  // send name as gossip item


       QueryResult result;
        uint32 spellId = 0;
        uint32 catNumber = 0;
        uint32 goldCost = 0;
        std::string spellName = "";

        result = WorldDatabase.PQuery("SELECT `spell_id`, `cat_number`, `cost`, `name` FROM `npc_buff_spells` WHERE `cat_number` = %u LIMIT 1", uiAction);

        if (result)
        {

            do {

            Field *fields = result->Fetch();
            spellId = fields[0].GetInt32();
            catNumber = fields[1].GetInt32();
            goldCost = fields[2].GetInt32();
            spellName = fields[3].GetString();

            if (pPlayer->GetMoney() < goldCost)
            {
                pCreature->Whisper("You dont have enough money!", LANG_UNIVERSAL, pPlayer);
                pPlayer->CLOSE_GOSSIP_MENU();
                return;
            }
            else if (uiAction < 5000 && uiAction != 1000 && uiAction != 2000 && uiAction != 3000 && uiAction != 4000 && uiAction != 5005)
            {
    pPlayer->CLOSE_GOSSIP_MENU();
    pPlayer->CastSpell(pPlayer,spellId,false);
    pPlayer->ModifyMoney(-goldCost);

            }

            } while (result->NextRow());
        } else {
            //pPlayer->ADD_GOSSIP_ITEM( 7, MAIN_MENU, GOSSIP_SENDER_MAIN, 5005);
        }

 switch(uiAction)
{

case 1000: //Small  Buff
         showSmallBuff(pPlayer, pCreature, 0);
        //pPlayer->ADD_GOSSIP_ITEM( 7, "<- Main Menu"                            , GOSSIP_SENDER_MAIN, 5005);

    pPlayer->SEND_GOSSIP_MENU(MSG_BUFF, pCreature->GetGUID());
break;

case 2000: //Great Buff


        showGreatBuff(pPlayer, pCreature, 0);
        //pPlayer->ADD_GOSSIP_ITEM( 7, "<- Main Menu"                            , GOSSIP_SENDER_MAIN, 5005);

    pPlayer->SEND_GOSSIP_MENU(MSG_BUFF, pCreature->GetGUID());
break;

case 3000: //GM  Buff

        showGmBuff(pPlayer, pCreature, 0);
        //pPlayer->ADD_GOSSIP_ITEM( 7, "<- Main Menu"                            , GOSSIP_SENDER_MAIN, 5005);

    pPlayer->SEND_GOSSIP_MENU(MSG_BUFF,pCreature->GetGUID());
break;

case 4000: //Player Tools
    // Check config if "Give me Gold" is enabled or not

        showPlayerTools(pPlayer, pCreature, 0);
        //pPlayer->ADD_GOSSIP_ITEM( 7, "<- Main Menu"                            , GOSSIP_SENDER_MAIN, 5005);

    pPlayer->SEND_GOSSIP_MENU(MSG_BUFF,pCreature->GetGUID());
break;

case 5005: //Back To Main Menu
    // Main Menu
    // Check config if "Small  Buff " is enabled or not
    if(EnableSmallBuff)
        pPlayer->ADD_GOSSIP_ITEM( 7, "Small Buff ->"              , GOSSIP_SMALLBUFF, 1000);
    // Check config if "Great Buff" is enabled or not
    if(EnableGreatBuff)
        pPlayer->ADD_GOSSIP_ITEM( 7, "Great Buff ->"              , GOSSIP_LARGEBUFF, 2000);
    // Check config if "GM Buff" is enabled or not
    if(EnableGMBuff)
    {
    if (pPlayer->GetSession()->GetSecurity() > SEC_PLAYER)
        {
        pPlayer->ADD_GOSSIP_ITEM( 7, "Platinum Members Buff ->"                 , GOSSIP_SENDER_MAIN, 3000);
        }
    }
    // Check config if "Player Tools" is enabled or not
    if(EnablePlayerTools)
        pPlayer->ADD_GOSSIP_ITEM( 7, "Player Tools ->"            , GOSSIP_PLAYERTOOLS, 4000);
    // Check if Ress Sickness option is enabled
    if(EnableResSickness)
        pPlayer->ADD_GOSSIP_ITEM( 10, "Remove Resurrect Sickness" , GOSSIP_SENDER_MAIN, 5000);

    pPlayer->SEND_GOSSIP_MENU(MSG_TYPE, pCreature->GetGUID());
break;

case 5000://Remove Res Sickness
    if(!pPlayer->HasAura(SPELL_RESURRECTION_SICKNESS_15007))
    {
        pCreature->Whisper("You don't have resurrection sickness.", LANG_UNIVERSAL, pPlayer);
        OnGossipHello(pPlayer, pCreature);
        return;
    }

    pCreature->CastSpell(pPlayer,38588,false); // Healing effect
    pPlayer->RemoveAurasDueToSpell(SPELL_RESURRECTION_SICKNESS_15007);
    pPlayer->CLOSE_GOSSIP_MENU();
break;
 pPlayer->CLOSE_GOSSIP_MENU();
 }

} //end of function

bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    // Main menu
    pPlayer->PlayerTalkClass->ClearMenus();
    if (uiSender == GOSSIP_SENDER_MAIN)
    SendDefaultMenu(pPlayer, pCreature, uiAction);

return true;
}
};
void AddSC_Npc_Buff()
{
    new npc_buff();
}