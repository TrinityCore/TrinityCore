/*
 * Copyright (C) 2008 - 2009 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

/* ScriptData
SDName: Npc_Innkeeper
SDAuthor: WarHead
SD%Complete: 99%
SDComment: Complete
SDCategory: NPCs
EndScriptData */

#include "ScriptedPch.h"

#define HALLOWEEN_EVENTID       12
#define SPELL_TRICK_OR_TREATED  24755
#define SPELL_TREAT             24715

#define LOCALE_TRICK_OR_TREAT_0 "Trick or Treat!"
#define LOCALE_TRICK_OR_TREAT_2 "Des bonbons ou des blagues!"
#define LOCALE_TRICK_OR_TREAT_3 "Süßes oder Saures!"
#define LOCALE_TRICK_OR_TREAT_6 "¡Truco o trato!"

#define LOCALE_INNKEEPER_0 "Make this inn my home."
#define LOCALE_INNKEEPER_3 "Ich möchte dieses Gasthaus zu meinem Heimatort machen."
 
bool GossipHello_npc_innkeeper(Player *pPlayer, Creature *pCreature)
{
    if (IsEventActive(HALLOWEEN_EVENTID) && !pPlayer->HasAura(SPELL_TRICK_OR_TREATED))
    {
        char* localizedEntry;
        switch (pPlayer->GetSession()->GetSessionDbcLocale())
        {
            case LOCALE_frFR: localizedEntry = LOCALE_TRICK_OR_TREAT_2; break;
            case LOCALE_deDE: localizedEntry = LOCALE_TRICK_OR_TREAT_3; break;
            case LOCALE_esES: localizedEntry = LOCALE_TRICK_OR_TREAT_6; break;
            case LOCALE_enUS: default: localizedEntry = LOCALE_TRICK_OR_TREAT_0;
        }
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, localizedEntry, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+HALLOWEEN_EVENTID);
    }

    if (pCreature->isQuestGiver())
        pPlayer->PrepareQuestMenu(pCreature->GetGUID());

    if (pCreature->isVendor())
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, GOSSIP_TEXT_BROWSE_GOODS, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRADE);

    if (pCreature->isInnkeeper())
    {
        char* localizedEntry;
        switch (pPlayer->GetSession()->GetSessionDbcLocale())
        {
            case LOCALE_deDE: localizedEntry = LOCALE_INNKEEPER_3; break;
            case LOCALE_enUS: default: localizedEntry = LOCALE_INNKEEPER_0;
        }
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, localizedEntry, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INN);
    }

    pPlayer->TalkedToCreature(pCreature->GetEntry(), pCreature->GetGUID());
    pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
    return true;
}

bool GossipSelect_npc_innkeeper(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    if (uiAction == GOSSIP_ACTION_INFO_DEF+HALLOWEEN_EVENTID && IsEventActive(HALLOWEEN_EVENTID) && !pPlayer->HasAura(SPELL_TRICK_OR_TREATED))
    {
        pPlayer->CastSpell(pPlayer, SPELL_TRICK_OR_TREATED, true);
 
        if (urand(0, 1))
            pPlayer->CastSpell(pPlayer, SPELL_TREAT, true);
        else
        {
            uint32 trickspell = 0;
            switch (urand(0, 13))
            {
                case 0: trickspell = 24753; break; // cannot cast, random 30sec
                case 1: trickspell = 24713; break; // lepper gnome costume
                case 2: trickspell = 24735; break; // male ghost costume
                case 3: trickspell = 24736; break; // female ghostcostume
                case 4: trickspell = 24710; break; // male ninja costume
                case 5: trickspell = 24711; break; // female ninja costume
                case 6: trickspell = 24708; break; // male pirate costume
                case 7: trickspell = 24709; break; // female pirate costume
                case 8: trickspell = 24723; break; // skeleton costume
                case 9: trickspell = 24753; break; // Trick
                case 10: trickspell = 24924; break; // Hallow's End Candy
                case 11: trickspell = 24925; break; // Hallow's End Candy
                case 12: trickspell = 24926; break; // Hallow's End Candy
                case 13: trickspell = 24927; break; // Hallow's End Candy
            }
            pPlayer->CastSpell(pPlayer, trickspell, true);
        }
        pPlayer->CLOSE_GOSSIP_MENU();
        return true;
    }

    pPlayer->CLOSE_GOSSIP_MENU();

    switch (uiAction)
    {
        case GOSSIP_ACTION_TRADE: pPlayer->SEND_VENDORLIST(pCreature->GetGUID()); break;
        case GOSSIP_ACTION_INN: pPlayer->SetBindPoint(pCreature->GetGUID()); break;
    }
    return true;
}

void AddSC_npc_innkeeper()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "npc_innkeeper";
    newscript->pGossipHello = &GossipHello_npc_innkeeper;
    newscript->pGossipSelect = &GossipSelect_npc_innkeeper;
    newscript->RegisterSelf();
}

