/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
 *
 * Created by LordPsyan for Flaminglegion.net
 *
 */

#include "Config.h"

#define GOSSIP_SENDER_MAIN      1000
#define SPELL_RESURRECTION_SICKNESS_15007  15007

class levelnpc : public CreatureScript
{
public:
    levelnpc() : CreatureScript("levelnpc") {}


bool OnGossipHello(Player* pPlayer, Creature* pCreature)
{
    if(sConfigMgr->GetBoolDefault("LevelNPC.OnlyGMs", false)) // If LevelNPC.OnlyGMs is enabled in trinitycore.conf
        if (pPlayer->GetSession()->GetSecurity() == SEC_PLAYER)
        {
            pCreature->Whisper("Sorry, I can only add levels to Platinum Members.", LANG_UNIVERSAL, pPlayer);
            return true;
        }

    bool EnableLevel80 = sConfigMgr->GetBoolDefault("LevelNPC.EnableLevel80", true);
    bool EnableLevel100 = sConfigMgr->GetBoolDefault("LevelNPC.EnableLevel100", true);
    bool EnableLevel150 = sConfigMgr->GetBoolDefault("LevelNPC.EnableLevel150", true);
    bool EnableLevel200 = sConfigMgr->GetBoolDefault("LevelNPC.EnableLevel200", true);
    bool EnableLevel255 = sConfigMgr->GetBoolDefault("LevelNPC.EnableLevel255", true);
    if (pPlayer->GetTeam() == ALLIANCE)
    {
        pPlayer->ADD_GOSSIP_ITEM( 7, "Instant Levels ->"        , GOSSIP_SENDER_MAIN, 1000);
        pPlayer->ADD_GOSSIP_ITEM( 10, "Remove Resurrect Sickness" , GOSSIP_SENDER_MAIN, 5000);
    }
    else
    {
        pPlayer->ADD_GOSSIP_ITEM( 7, "Instant Levels ->"        , GOSSIP_SENDER_MAIN, 1000);
        pPlayer->ADD_GOSSIP_ITEM( 10, "Remove Resurrect Sickness" , GOSSIP_SENDER_MAIN, 5000);
    }
    pPlayer->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,pCreature->GetGUID());

return true;
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

    bool EnableLevel80 = sConfigMgr->GetBoolDefault("LevelNPC.EnableLevel80", true);
    bool EnableLevel100 = sConfigMgr->GetBoolDefault("LevelNPC.EnableLevel100", true);
    bool EnableLevel150 = sConfigMgr->GetBoolDefault("LevelNPC.EnableLevel150", true);
    bool EnableLevel200 = sConfigMgr->GetBoolDefault("LevelNPC.EnableLevel200", true);
    bool EnableLevel255 = sConfigMgr->GetBoolDefault("LevelNPC.EnableLevel255", true);

//Mony Check
if(sConfigMgr->GetBoolDefault("LevelNPC.UseTokens", true))
{
if (!pPlayer->HasItemCount((sConfigMgr->GetIntDefault("LevelNPC.ItemEntryNum",0)), 0))
{
    pPlayer->CLOSE_GOSSIP_MENU();
    pCreature->Whisper("You ain't gots no darn chips.", LANG_UNIVERSAL, pPlayer);
    return;
}
}
else if(pPlayer->GetMoney() < (sConfigMgr->GetIntDefault("LevelNPC.SkillGoldCost",0)))
{
    pPlayer->CLOSE_GOSSIP_MENU();
    pCreature->Whisper("You don't have enough money.", LANG_UNIVERSAL, pPlayer);
    return;
}

switch(uiAction)
{

//////////////////////////////////////////////////Leveling///////////////////////////////////////////////////////////////
case 1000: //Leveling
    if(EnableLevel80 && pPlayer->getLevel() < 80)
        pPlayer->ADD_GOSSIP_ITEM( 7, "(1 Donation Chip) Instant 80 ->"         , GOSSIP_SENDER_MAIN, 1001);
    if(EnableLevel100 && pPlayer->getLevel() < 100 && pPlayer->getLevel() >= 80)
        pPlayer->ADD_GOSSIP_ITEM( 7, "(2 Donation Chips) Instant 100 ->"        , GOSSIP_SENDER_MAIN, 1002);
    if(EnableLevel150 && pPlayer->getLevel() < 150 && pPlayer->getLevel() >= 100)
        pPlayer->ADD_GOSSIP_ITEM( 7, "(5 Donation Chips) Instant 150 ->"        , GOSSIP_SENDER_MAIN, 1003);
    if(EnableLevel200 && pPlayer->getLevel() < 200 && pPlayer->getLevel() >= 150)
        pPlayer->ADD_GOSSIP_ITEM( 7, "(10 Donation Chips) Instant 200 ->"       , GOSSIP_SENDER_MAIN, 1004);
    if(EnableLevel255 && pPlayer->getLevel() < 255 && pPlayer->getLevel() >= 200)
        pPlayer->ADD_GOSSIP_ITEM( 7, "(20 Donation Chips) Instant 255 ->"       , GOSSIP_SENDER_MAIN, 1005);
        pPlayer->ADD_GOSSIP_ITEM( 7, "<- Main Menu"                       , GOSSIP_SENDER_MAIN, 3000);
    pPlayer->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,pCreature->GetGUID());
break;
case 3000: //Leveling
    if(EnableLevel80)
        pPlayer->ADD_GOSSIP_ITEM( 7, "Instant Levels ->"        , GOSSIP_SENDER_MAIN, 1000);
    pPlayer->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,pCreature->GetGUID());
break;
case 1001: // Leveling
    pPlayer->GiveLevel(80);
    if(sConfigMgr->GetBoolDefault("LevelNPC.UseTokens", true))
    pPlayer->DestroyItemCount(99998, 1, true);
    else
    pPlayer->ModifyMoney(-(sConfigMgr->GetIntDefault("LevelNPC.SkillGoldCost",0)));
    pPlayer->CLOSE_GOSSIP_MENU();
break;
case 1002: // Leveling
    pPlayer->GiveLevel(100);
    if(sConfigMgr->GetBoolDefault("LevelNPC.UseTokens", true))
    pPlayer->DestroyItemCount(99998, 2, true);
    else
    pPlayer->ModifyMoney(-(sConfigMgr->GetIntDefault("LevelNPC.SkillGoldCost",0)));
    pPlayer->CLOSE_GOSSIP_MENU();
break;
case 1003: // Leveling
    pPlayer->GiveLevel(150);
    if(sConfigMgr->GetBoolDefault("LevelNPC.UseTokens", true))
    pPlayer->DestroyItemCount(99998, 5, true);
    else
    pPlayer->ModifyMoney(-(sConfigMgr->GetIntDefault("LevelNPC.SkillGoldCost",0)));
    pPlayer->CLOSE_GOSSIP_MENU();
break;
case 1004: // Leveling
    pPlayer->GiveLevel(200);
    if(sConfigMgr->GetBoolDefault("LevelNPC.UseTokens", true))
    pPlayer->DestroyItemCount(99998, 10, true);
    else
    pPlayer->ModifyMoney(-(sConfigMgr->GetIntDefault("LevelNPC.SkillGoldCost",0)));
    pPlayer->CLOSE_GOSSIP_MENU();
break;
case 1005: // Leveling
    pPlayer->GiveLevel(255);
    if(sConfigMgr->GetBoolDefault("LevelNPC.UseTokens", true))
    pPlayer->DestroyItemCount(99998, 20, true);
    else
    pPlayer->ModifyMoney(-(sConfigMgr->GetIntDefault("LevelNPC.SkillGoldCost",0)));
    pPlayer->CLOSE_GOSSIP_MENU();
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

} // end of switch
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

void AddSC_levelnpc()
{

new levelnpc();

}
