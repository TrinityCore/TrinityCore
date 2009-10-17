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
/* ScriptData
SDName: Example_Gossip_Codebox
SD%Complete: 100
SDComment: Show a codebox in gossip option
SDCategory: Script Examples
EndScriptData */
#include "precompiled.h"
#include <cstring>
enum eEnums
{
    SPELL_POLYMORPH         = 12826,
    SPELL_MARK_OF_THE_WILD  = 26990,
    SAY_NOT_INTERESTED      = -1999922,
    SAY_WRONG               = -1999923,
    SAY_CORRECT             = -1999924
};
#define GOSSIP_ITEM_1       "A quiz: what's your name?"
#define GOSSIP_ITEM_2       "I'm not interested"
//This function is called when the player opens the gossip menubool
bool GossipHello_example_gossip_codebox(Player* pPlayer, Creature* pCreature)
{
    pPlayer->ADD_GOSSIP_ITEM_EXTENDED(0, GOSSIP_ITEM_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1, "", 0, true);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
    pPlayer->PlayerTalkClass->SendGossipMenu(907, pCreature->GetGUID());
    return true;
}
//This function is called when the player clicks an option on the gossip menubool
bool GossipSelect_example_gossip_codebox(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    if (uiAction == GOSSIP_ACTION_INFO_DEF+2)
    {
        DoScriptText(SAY_NOT_INTERESTED, pCreature);
        pPlayer->CLOSE_GOSSIP_MENU();
    }
    return true;
}
bool GossipSelectWithCode_example_gossip_codebox(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction, const char* sCode)
{
    if (uiSender == GOSSIP_SENDER_MAIN)
    {
        switch (uiAction)
        {
        case GOSSIP_ACTION_INFO_DEF+1:
            if (std::strcmp(sCode, pPlayer->GetName())!=0)
            {
                DoScriptText(SAY_WRONG, pCreature);
                pCreature->CastSpell(pPlayer, SPELL_POLYMORPH, true);
            }
            else
            {
                DoScriptText(SAY_CORRECT, pCreature);
                pCreature->CastSpell(pPlayer, SPELL_MARK_OF_THE_WILD, true);
            }
            pPlayer->CLOSE_GOSSIP_MENU();
            return true;
        }
    }
    return false;
}
void AddSC_example_gossip_codebox()
{
    Script* newscript;
    newscript = new Script;
    newscript->Name = "example_gossip_codebox";
    newscript->pGossipHello = &GossipHello_example_gossip_codebox;
    newscript->pGossipSelect = &GossipSelect_example_gossip_codebox;
    newscript->pGossipSelectWithCode = &GossipSelectWithCode_example_gossip_codebox;
    newscript->RegisterSelf();
}
