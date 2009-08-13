/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SD%Complete: 50
SDComment: This script are currently not in use. EventSystem cannot be used on Windows build of SD2
SDCategory: NPCs
EndScriptData */

#include "precompiled.h"

#define HALLOWEEN_EVENTID       12
#define SPELL_TRICK_OR_TREATED  24755
#define SPELL_TREAT             24715

#define LOCALE_TRICK_OR_TREAT_0 "Trick or Treat!"
#define LOCALE_TRICK_OR_TREAT_2 "Des bonbons ou des blagues!"
#define LOCALE_TRICK_OR_TREAT_3 "Süßes oder Saures!"
#define LOCALE_TRICK_OR_TREAT_6 "¡Truco o trato!"

bool isEventActive()
{
    /*
     const GameEvent::ActiveEvents *ActiveEventsList = gameeventmgr.GetActiveEventList();
     GameEvent::ActiveEvents::const_iterator itr;
     for (itr = ActiveEventsList->begin(); itr != ActiveEventsList->end(); ++itr)
     {
         if (*itr==HALLOWEEN_EVENTID)
         {
             return true;
         }
     }*/
    return false;
}

bool GossipHello_npc_innkeeper(Player* pPlayer, Creature* pCreature)
{
    if (pCreature->isQuestGiver())
        pPlayer->PrepareQuestMenu(pCreature->GetGUID());

    if (isEventActive()&& !pPlayer->GetAura(SPELL_TRICK_OR_TREATED, pPlayer->GetGUID()))
    {
        char* localizedEntry;
        switch (pPlayer->GetSession()->GetSessionDbLocaleIndex())
        {
            case 0:
                localizedEntry=LOCALE_TRICK_OR_TREAT_0;
                break;
            case 2:
                localizedEntry=LOCALE_TRICK_OR_TREAT_2;
                break;
            case 3:
                localizedEntry=LOCALE_TRICK_OR_TREAT_3;
                break;
            case 6:
                localizedEntry=LOCALE_TRICK_OR_TREAT_6;
                break;
            default:
                localizedEntry=LOCALE_TRICK_OR_TREAT_0;
        }

        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, localizedEntry, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+HALLOWEEN_EVENTID);
    }

    pPlayer->TalkedToCreature(pCreature->GetEntry(), pCreature->GetGUID());
    pPlayer->SEND_GOSSIP_MENU(pCreature->GetNpcTextId(), pCreature->GetGUID());
    return true;
}

bool GossipSelect_npc_innkeeper(Player* pPlayer, Creature* pCreature, uint32 sender, uint32 action)
{
    if (action == GOSSIP_ACTION_INFO_DEF+HALLOWEEN_EVENTID && isEventActive() && !pPlayer->GetAura(SPELL_TRICK_OR_TREATED, pPlayer->GetGUID()))
    {
        pPlayer->CLOSE_GOSSIP_MENU();
        pPlayer->CastSpell(pPlayer, SPELL_TRICK_OR_TREATED, true);

        // either trick or treat, 50% chance
        if (rand()%2)
        {
            pPlayer->CastSpell(pPlayer, SPELL_TREAT, true);
        }
        else
        {
            int32 trickspell=0;
            switch (rand()%9)                               // note that female characters can get male costumes and vice versa
            {
                case 0:
                    trickspell=24753;                       // cannot cast, random 30sec
                    break;
                case 1:
                    trickspell=24713;                       // lepper gnome costume
                    break;
                case 2:
                    trickspell=24735;                       // male ghost costume
                    break;
                case 3:
                    trickspell=24736;                       // female ghostcostume
                    break;
                case 4:
                    trickspell=24710;                       // male ninja costume
                    break;
                case 5:
                    trickspell=24711;                       // female ninja costume
                    break;
                case 6:
                    trickspell=24708;                       // male pirate costume
                    break;
                case 7:
                    trickspell=24709;                       // female pirate costume
                    break;
                case 8:
                    trickspell=24723;                       // skeleton costume
                    break;
            }
            pPlayer->CastSpell(pPlayer, trickspell, true);
        }
        return true;                                        // prevent Trinity core handling
    }
    return false;                                           // the player didn't select "trick or treat" or cheated, normal core handling
}

void AddSC_npc_innkeeper()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="npc_innkeeper";
    newscript->pGossipHello = &GossipHello_npc_innkeeper;
    newscript->pGossipSelect = &GossipSelect_npc_innkeeper;
    newscript->RegisterSelf();
}

