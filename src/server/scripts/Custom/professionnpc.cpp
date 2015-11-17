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
 */

#include "Config.h"

class professionnpc : public CreatureScript
{
public:
    professionnpc() : CreatureScript("professionnpc") {}


bool OnGossipHello(Player* pPlayer, Creature* pCreature)
{
    if(sConfigMgr->GetBoolDefault("ProfessionNPC.OnlyGMs", false)) // If ProfessionNPC.OnlyGMs is enabled in trinitycore.conf
        if (pPlayer->GetSession()->GetSecurity() == SEC_PLAYER)
        {
            pCreature->Whisper("Sorry, I can only trade to game masters.", LANG_UNIVERSAL, pPlayer);
            return true;
        }

    bool EnableProfessions = sConfigMgr->GetBoolDefault("ProfessionNPC.EnableProfessions", true);
    bool EnableSecondarySkills = sConfigMgr->GetBoolDefault("ProfessionNPC.EnableSecondarySkills", true);

    // Main Menu for Alliance
    if (pPlayer->GetTeam() == ALLIANCE)
    {
    // Check config if "Professions" is enabled or not
    if(EnableProfessions)
        pPlayer->ADD_GOSSIP_ITEM( 7, "Professions ->"        , GOSSIP_SENDER_MAIN, 1000);
    // Check config if "Secondary Skills" is enabled or not
    if(EnableSecondarySkills)
        pPlayer->ADD_GOSSIP_ITEM( 7, "Secondary Skills ->"   , GOSSIP_SENDER_MAIN, 2000);
    }
    else // Main Menu for Horde
    {
    // Check config if "Professions" is enabled or not
    if(EnableProfessions)
        pPlayer->ADD_GOSSIP_ITEM( 7, "Professions ->"        , GOSSIP_SENDER_MAIN, 1000);
    // Check config if "Secondary Skills" is enabled or not
    if(EnableSecondarySkills)
        pPlayer->ADD_GOSSIP_ITEM( 7, "Secondary Skills ->"   , GOSSIP_SENDER_MAIN, 2000);
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

    bool EnableProfessions = sConfigMgr->GetBoolDefault("ProfessionNPC.EnableProfessions", true);
    bool EnableSecondarySkills = sConfigMgr->GetBoolDefault("ProfessionNPC.EnableSecondarySkills", true);

//Mony Check
if(sConfigMgr->GetBoolDefault("ProfessionNPC.UseTokens", true))
{
if (!pPlayer->HasItemCount((sConfigMgr->GetIntDefault("ProfessionNPC.ItemEntryNum",0)), 1))
{
    pPlayer->CLOSE_GOSSIP_MENU();
    pCreature->Whisper("You ain't gots no darn chips.", LANG_UNIVERSAL, pPlayer);
    return;
}
else if(pPlayer->GetMoney() < (sConfigMgr->GetIntDefault("SkillGoldCost",0)))
{
    pPlayer->CLOSE_GOSSIP_MENU();
    pCreature->Whisper("You don't have enough money.", LANG_UNIVERSAL, pPlayer);
    return;
}
}
switch(uiAction)
{

case 1000: //Profession
            pPlayer->ADD_GOSSIP_ITEM( 5, "10 points in Alchemy."              , GOSSIP_SENDER_MAIN, 1001);
            pPlayer->ADD_GOSSIP_ITEM( 5, "10 points in Blacksmithing."        , GOSSIP_SENDER_MAIN, 1002);
            pPlayer->ADD_GOSSIP_ITEM( 5, "10 points in Enchanting."           , GOSSIP_SENDER_MAIN, 1003);
            pPlayer->ADD_GOSSIP_ITEM( 5, "10 points in Engineering."          , GOSSIP_SENDER_MAIN, 1004);
            pPlayer->ADD_GOSSIP_ITEM( 5, "10 points in Herbalism."            , GOSSIP_SENDER_MAIN, 1005);
            pPlayer->ADD_GOSSIP_ITEM( 5, "10 points in Inscription."          , GOSSIP_SENDER_MAIN, 1006);
            pPlayer->ADD_GOSSIP_ITEM( 5, "10 points in Jewelcrafting."        , GOSSIP_SENDER_MAIN, 1007);
            pPlayer->ADD_GOSSIP_ITEM( 5, "10 points in Leatherworking."       , GOSSIP_SENDER_MAIN, 1008);
            pPlayer->ADD_GOSSIP_ITEM( 5, "10 points in Mining."               , GOSSIP_SENDER_MAIN, 1009);
            pPlayer->ADD_GOSSIP_ITEM( 5, "10 points in Skinning."             , GOSSIP_SENDER_MAIN, 1010);
            pPlayer->ADD_GOSSIP_ITEM( 5, "10 points in Tailoring."            , GOSSIP_SENDER_MAIN, 1011);
            pPlayer->ADD_GOSSIP_ITEM( 7, "<- Main Menu"          , GOSSIP_SENDER_MAIN, 3000);

    pPlayer->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,pCreature->GetGUID());
break;

case 2000: //Secondary Skills
            pPlayer->ADD_GOSSIP_ITEM( 5, "Cooking."              , GOSSIP_SENDER_MAIN, 2001);
            pPlayer->ADD_GOSSIP_ITEM( 5, "First Aid."            , GOSSIP_SENDER_MAIN, 2002);
            pPlayer->ADD_GOSSIP_ITEM( 5, "Fishing."              , GOSSIP_SENDER_MAIN, 2003);
            pPlayer->ADD_GOSSIP_ITEM( 7, "<- Main Menu"          , GOSSIP_SENDER_MAIN, 3000);

    pPlayer->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,pCreature->GetGUID());
break;

case 3000: //Back To Main Menu
    // Main Menu for Alliance
    if (pPlayer->GetTeam() == ALLIANCE)
    {
    // Check config if "Professions" is enabled or not
    if(EnableProfessions)
        pPlayer->ADD_GOSSIP_ITEM( 7, "Professions ->"        , GOSSIP_SENDER_MAIN, 1000);
    // Check config if "Secondary Skills" is enabled or not
    if(EnableSecondarySkills)
        pPlayer->ADD_GOSSIP_ITEM( 7, "Secondary Skills ->"   , GOSSIP_SENDER_MAIN, 2000);
    }
    else // Main Menu for Horde
    {
    // Check config if "Professions" is enabled or not
    if(EnableProfessions)
        pPlayer->ADD_GOSSIP_ITEM( 7, "Professions ->"        , GOSSIP_SENDER_MAIN, 1000);
    // Check config if "Secondary Skills" is enabled or not
    if(EnableSecondarySkills)
        pPlayer->ADD_GOSSIP_ITEM( 7, "Secondary Skills ->"   , GOSSIP_SENDER_MAIN, 2000);
    }

    pPlayer->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,pCreature->GetGUID());
break;

//////////////////////////////////////////////////Professions///////////////////////////////////////////////////////////////

case 1001: // Alchemy
    if(!pPlayer->UpdateSkill(171,0))
      {
        pCreature->Whisper("You don't have this skill or you already have the maximum skill value $C.", LANG_UNIVERSAL, pPlayer);
        OnGossipHello(pPlayer, pCreature);
        return;
    }

    pPlayer->UpdateSkill(171,(sConfigMgr->GetIntDefault("SkillPoints",0)));
    if(sConfigMgr->GetBoolDefault("ProfessionNPC.UseTokens", true))
    pPlayer->DestroyItemCount(99999, 1, true);
    else
    pPlayer->ModifyMoney(-(sConfigMgr->GetIntDefault("SkillGoldCost",0)));
    pPlayer->CLOSE_GOSSIP_MENU();
break;

case 1002: // Blacksmithing
    if(!pPlayer->UpdateSkill(164,0))
      {
        pCreature->Whisper("You don't have this skill or you already have the maximum skill value $C.", LANG_UNIVERSAL, pPlayer);
        OnGossipHello(pPlayer, pCreature);
        return;
    }

    pPlayer->UpdateSkill(164,(sConfigMgr->GetIntDefault("SkillPoints",0)));
    if(sConfigMgr->GetBoolDefault("ProfessionNPC.UseTokens", true))
    pPlayer->DestroyItemCount(99999, 1, true);
    else
    pPlayer->ModifyMoney(-(sConfigMgr->GetIntDefault("SkillGoldCost",0)));
    pPlayer->CLOSE_GOSSIP_MENU();
break;

case 1003: // Enchanting
    if(!pPlayer->UpdateSkill(333,0))
      {
        pCreature->Whisper("You don't have this skill or you already have the maximum skill value $C.", LANG_UNIVERSAL, pPlayer);
        OnGossipHello(pPlayer, pCreature);
        return;
    }

    pPlayer->UpdateSkill(333,(sConfigMgr->GetIntDefault("SkillPoints",0)));
    if(sConfigMgr->GetBoolDefault("ProfessionNPC.UseTokens", true))
    pPlayer->DestroyItemCount(99999, 1, true);
    else
    pPlayer->ModifyMoney(-(sConfigMgr->GetIntDefault("SkillGoldCost",0)));
    pPlayer->CLOSE_GOSSIP_MENU();
break;

case 1004: // Engineering
    if(!pPlayer->UpdateSkill(202,0))
      {
        pCreature->Whisper("You don't have this skill or you already have the maximum skill value $C.", LANG_UNIVERSAL, pPlayer);
        OnGossipHello(pPlayer, pCreature);
        return;
    }

    pPlayer->UpdateSkill(202,(sConfigMgr->GetIntDefault("SkillPoints",0)));
    if(sConfigMgr->GetBoolDefault("ProfessionNPC.UseTokens", true))
    pPlayer->DestroyItemCount(99999, 1, true);
    else
    pPlayer->ModifyMoney(-(sConfigMgr->GetIntDefault("SkillGoldCost",0)));
    pPlayer->CLOSE_GOSSIP_MENU();
break;

case 1005: // Herbalism
    if(!pPlayer->UpdateSkill(182,0))
      {
        pCreature->Whisper("You don't have this skill or you already have the maximum skill value $C.", LANG_UNIVERSAL, pPlayer);
        OnGossipHello(pPlayer, pCreature);
        return;
    }

    pPlayer->UpdateSkill(182,(sConfigMgr->GetIntDefault("SkillPoints",0)));
    if(sConfigMgr->GetBoolDefault("ProfessionNPC.UseTokens", true))
    pPlayer->DestroyItemCount(99999, 1, true);
    else
    pPlayer->ModifyMoney(-(sConfigMgr->GetIntDefault("SkillGoldCost",0)));
    pPlayer->CLOSE_GOSSIP_MENU();
break;

case 1006: // Inscription
    if(!pPlayer->UpdateSkill(773,0))
      {
        pCreature->Whisper("You don't have this skill or you already have the maximum skill value $C.", LANG_UNIVERSAL, pPlayer);
        OnGossipHello(pPlayer, pCreature);
        return;
    }

    pPlayer->UpdateSkill(773,(sConfigMgr->GetIntDefault("SkillPoints",0)));
    if(sConfigMgr->GetBoolDefault("ProfessionNPC.UseTokens", true))
    pPlayer->DestroyItemCount(99999, 1, true);
    else
    pPlayer->ModifyMoney(-(sConfigMgr->GetIntDefault("SkillGoldCost",0)));
    pPlayer->CLOSE_GOSSIP_MENU();
break;

case 1007: // Jewelcrafting
    if(!pPlayer->UpdateSkill(755,0))
      {
        pCreature->Whisper("You don't have this skill or you already have the maximum skill value $C.", LANG_UNIVERSAL, pPlayer);
        OnGossipHello(pPlayer, pCreature);
        return;
    }

    pPlayer->UpdateSkill(755,(sConfigMgr->GetIntDefault("SkillPoints",0)));
    if(sConfigMgr->GetBoolDefault("ProfessionNPC.UseTokens", true))
    pPlayer->DestroyItemCount(99999, 1, true);
    else
    pPlayer->ModifyMoney(-(sConfigMgr->GetIntDefault("SkillGoldCost",0)));
    pPlayer->CLOSE_GOSSIP_MENU();
break;

case 1008: // Leatherworking
    if(!pPlayer->UpdateSkill(165,0))
      {
        pCreature->Whisper("You don't have this skill or you already have the maximum skill value $C.", LANG_UNIVERSAL, pPlayer);
        OnGossipHello(pPlayer, pCreature);
        return;
    }

    pPlayer->UpdateSkill(165,(sConfigMgr->GetIntDefault("SkillPoints",0)));
    if(sConfigMgr->GetBoolDefault("ProfessionNPC.UseTokens", true))
    pPlayer->DestroyItemCount(99999, 1, true);
    else
    pPlayer->ModifyMoney(-(sConfigMgr->GetIntDefault("SkillGoldCost",0)));
    pPlayer->CLOSE_GOSSIP_MENU();
break;

case 1009: // Mining
    if(!pPlayer->UpdateSkill(186,0))
      {
        pCreature->Whisper("You don't have this skill or you already have the maximum skill value $C.", LANG_UNIVERSAL, pPlayer);
        OnGossipHello(pPlayer, pCreature);
        return;
    }

    pPlayer->UpdateSkill(186,(sConfigMgr->GetIntDefault("SkillPoints",0)));
    if(sConfigMgr->GetBoolDefault("ProfessionNPC.UseTokens", true))
    pPlayer->DestroyItemCount(99999, 1, true);
    else
    pPlayer->ModifyMoney(-(sConfigMgr->GetIntDefault("SkillGoldCost",0)));
    pPlayer->CLOSE_GOSSIP_MENU();
break;

case 1010: // Skinning
    if(!pPlayer->UpdateSkill(393,0))
      {
        pCreature->Whisper("You don't have this skill or you already have the maximum skill value $C.", LANG_UNIVERSAL, pPlayer);
        OnGossipHello(pPlayer, pCreature);
        return;
    }

    pPlayer->UpdateSkill(393,(sConfigMgr->GetIntDefault("SkillPoints",0)));
    if(sConfigMgr->GetBoolDefault("ProfessionNPC.UseTokens", true))
    pPlayer->DestroyItemCount(99999, 1, true);
    else
    pPlayer->ModifyMoney(-(sConfigMgr->GetIntDefault("SkillGoldCost",0)));
    pPlayer->CLOSE_GOSSIP_MENU();
break;

case 1011: // Tailoring
    if(!pPlayer->UpdateSkill(197,0))
      {
        pCreature->Whisper("You don't have this skill or you already have the maximum skill value $C.", LANG_UNIVERSAL, pPlayer);
        OnGossipHello(pPlayer, pCreature);
        return;
    }

    pPlayer->UpdateSkill(197,(sConfigMgr->GetIntDefault("SkillPoints",0)));
    if(sConfigMgr->GetBoolDefault("ProfessionNPC.UseTokens", true))
    pPlayer->DestroyItemCount(99999, 1, true);
    else
    pPlayer->ModifyMoney(-(sConfigMgr->GetIntDefault("SkillGoldCost",0)));
    pPlayer->CLOSE_GOSSIP_MENU();
break;

//////////////////////////////////////////////////Secondary Skills///////////////////////////////////////////////////////////////

case 2001: // Cooking
    if(!pPlayer->UpdateSkill(185,0))
      {
        pCreature->Whisper("You don't have this skill or you already have the maximum skill value $C.", LANG_UNIVERSAL, pPlayer);
        OnGossipHello(pPlayer, pCreature);
        return;
    }

    pPlayer->UpdateSkill(185,(sConfigMgr->GetIntDefault("SkillPoints",0)));
    if(sConfigMgr->GetBoolDefault("ProfessionNPC.UseTokens", true))
    pPlayer->DestroyItemCount(99999, 1, true);
    else
    pPlayer->ModifyMoney(-(sConfigMgr->GetIntDefault("SkillGoldCost",0)));
    pPlayer->CLOSE_GOSSIP_MENU();
break;

case 2002: // First Aid
    if(!pPlayer->UpdateSkill(129,0))
      {
        pCreature->Whisper("You don't have this skill or you already have the maximum skill value $C.", LANG_UNIVERSAL, pPlayer);
        OnGossipHello(pPlayer, pCreature);
        return;
    }

    pPlayer->UpdateSkill(129,(sConfigMgr->GetIntDefault("SkillPoints",0)));
    if(sConfigMgr->GetBoolDefault("ProfessionNPC.UseTokens", true))
    pPlayer->DestroyItemCount(99999, 1, true);
    else
    pPlayer->ModifyMoney(-(sConfigMgr->GetIntDefault("SkillGoldCost",0)));
    pPlayer->CLOSE_GOSSIP_MENU();
break;

case 2003: // Fishing
    if(!pPlayer->UpdateSkill(356,0))
      {
        pCreature->Whisper("You don't have this skill or you already have the maximum skill value $C.", LANG_UNIVERSAL, pPlayer);
        OnGossipHello(pPlayer, pCreature);
        return;
    }

    pPlayer->UpdateSkill(356,(sConfigMgr->GetIntDefault("SkillPoints",0)));
    if(sConfigMgr->GetBoolDefault("ProfessionNPC.UseTokens", true))
    pPlayer->DestroyItemCount(99999, 1, true);
    else
    pPlayer->ModifyMoney(-(sConfigMgr->GetIntDefault("SkillGoldCost",0)));
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

void AddSC_professionnpc()
{

new professionnpc();

}
