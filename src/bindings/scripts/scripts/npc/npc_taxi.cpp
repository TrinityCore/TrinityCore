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
SDName: Npc_Taxi
SD%Complete: 0%
SDComment: To be used for taxi NPCs that are located globally.
SDCategory: NPCs
EndScriptData
*/

#include "precompiled.h"

bool GossipHello_npc_taxi(Player *player, Creature *_Creature)
{
    if (_Creature->isQuestGiver())
        player->PrepareQuestMenu( _Creature->GetGUID() );

    switch(_Creature->GetEntry()) {
    case 17435: // Azuremyst Isle - Susurrus
        if (player->HasItemCount(23843,1,true))
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "I am ready.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
        break;
    case 20903: // Netherstorm - Protectorate Nether Drake
        if(player->GetQuestStatus(10438) == QUEST_STATUS_INCOMPLETE && player->HasItemCount(29778,1))
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "I'm ready to fly! Take me up, dragon!", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
        break;
    case 18725: // Old Hillsbrad Foothills - Brazen
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "I am ready to go to Durnholde Keep.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
        break;
    case 29154: // Stormwind City - Thargold Ironwing
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "I'd like to take a flight around Stormwind Harbor.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
        break;
    case 19409: // Hellfire Peninsula - Wing Commander Dabir'ee
        //Mission: The Murketh and Shaadraz Gateways
        if (player->GetQuestStatus(10146) == QUEST_STATUS_INCOMPLETE)
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Fly me to Murketh and Shaadraz Gateways", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);

        //Shatter Point
        if (!player->GetQuestRewardStatus(10340))
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Fly me to Shatter Point", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
        break;
    case 20235: // Hellfire Peninsula - Gryphoneer Windbellow
        //Mission: The Abyssal Shelf || Return to the Abyssal Shelf
        if (player->GetQuestStatus(10163) == QUEST_STATUS_INCOMPLETE || player->GetQuestStatus(10346) == QUEST_STATUS_INCOMPLETE)
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Fly me to The Abyssal Shelf", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 6);

        //Go to the Front
        if (player->GetQuestStatus(10382) != QUEST_STATUS_NONE && !player->GetQuestRewardStatus(10382))
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Fly me to Honor Point", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 7);
        break;
    case 19401: // Hellfire Peninsula - Wing Commander Brack
        //Mission: The Murketh and Shaadraz Gateways
        if (player->GetQuestStatus(10129) == QUEST_STATUS_INCOMPLETE)
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Fly me to Murketh and Shaadraz Gateways", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 8);

        //Mission: The Abyssal Shelf || Return to the Abyssal Shelf
        if (player->GetQuestStatus(10162) == QUEST_STATUS_INCOMPLETE || player->GetQuestStatus(10347) == QUEST_STATUS_INCOMPLETE)
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Fly me to The Abyssal Shelf", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 9);

        //Spinebreaker Post
        if (player->GetQuestStatus(10242) == QUEST_STATUS_COMPLETE && !player->GetQuestRewardStatus(10242))
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Fly me to Spinebreaker Post", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 10);
        break;
    case 23413: // Blade's Edge Mountains - Skyguard Handler Irena
        if (player->GetReputationRank(1031) >= REP_HONORED)
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Fly me to Skettis please", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 11);
        break;
    case 25059: // Isle of Quel'Danas - Ayren Cloudbreaker
        if (player->GetQuestStatus(11532) == QUEST_STATUS_INCOMPLETE || player->GetQuestStatus(11533) == QUEST_STATUS_INCOMPLETE)
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Speaking of action, I've been ordered to undertake an air strike.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 12);

        if (player->GetQuestStatus(11542) == QUEST_STATUS_INCOMPLETE || player->GetQuestStatus(11543) == QUEST_STATUS_INCOMPLETE)
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "I need to intercept the Dawnblade reinforcements.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 13);
        break;
    case 25236: // Isle of Quel'Danas - Unrestrained Dragonhawk
        if (player->GetQuestStatus(11542) == QUEST_STATUS_COMPLETE || player->GetQuestStatus(11543) == QUEST_STATUS_COMPLETE)
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "<Ride the dragonhawk to Sun's Reach>", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 14);
        break;
    case 20162: // Netherstorm - Veronia
        //Behind Enemy Lines
        if (player->GetQuestStatus(10652) && !player->GetQuestRewardStatus(10652))
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Fly me to Manaforge Coruu please", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 15);
        break;
    case 23415: // Terokkar Forest - Skyguard Handler Deesak
        if (player->GetReputationRank(1031) >= REP_HONORED)
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Fly me to Ogri'la please", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 16);
        break;
    case 27575: // Dragonblight - Lord Afrasastrasz
        // middle -> ground
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "I would like to take a flight to the ground, Lord Of Afrasastrasz.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 17);
        // middle -> top
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "My Lord, I must go to the upper floor of the temple.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 18);
        break;
    case 26443: // Dragonblight - Tariolstrasz //need to check if quests are required before gossip available (12123, 12124)
        // ground -> top
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "My Lord, I must go to the upper floor of the temple.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 19);
        // ground -> middle
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Can you spare a drake to travel to Lord Of Afrasastrasz, in the middle of the temple?", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 20);
        break;
    case 26949: // Dragonblight - Torastrasza
        // top -> middle
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "I would like to see Lord Of Afrasastrasz, in the middle of the temple.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 21);
        // top -> ground
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Yes, Please. I would like to return to the ground floor of the temple.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 22);
        break;
    case 23816: // Howling Fjord - Bat Handler Camille
        if (!player->GetQuestRewardStatus(11229))
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "I need to fly to the Windrunner Official business!", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 23);
        if (player->GetQuestStatus(11170) == QUEST_STATUS_INCOMPLETE)
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "I need to commandeer a riding bat for special assignment for us.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 24);
        break;
    case 23704: // Dustwallow Marsh - Cassa Crimsonwing
        if (player->GetQuestStatus(11142) == QUEST_STATUS_INCOMPLETE)
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT,"<Ride the gryphons to Survey Alcaz Island>",GOSSIP_SENDER_MAIN,GOSSIP_ACTION_INFO_DEF+25);
        break;
    }

    player->SEND_GOSSIP_MENU(_Creature->GetNpcTextId(), _Creature->GetGUID());
    return true;
}

bool GossipSelect_npc_taxi(Player *player, Creature *_Creature, uint32 sender, uint32 action )
{
    switch(action) {
    case GOSSIP_ACTION_INFO_DEF:
        //spellId is correct, however it gives flight a somewhat funny effect //TaxiPath 506.
        player->CLOSE_GOSSIP_MENU();
        player->CastSpell(player,32474,true);
        break;
    case GOSSIP_ACTION_INFO_DEF + 1:
        player->CLOSE_GOSSIP_MENU();
        player->ActivateTaxiPathTo(627);                  //TaxiPath 627 (possibly 627+628(152->153->154->155) )
        break;
    case GOSSIP_ACTION_INFO_DEF + 2:
        if( !player->HasItemCount(25853,1) ) {
            player->SEND_GOSSIP_MENU(9780, _Creature->GetGUID());
        } else {
            player->CLOSE_GOSSIP_MENU();
            player->ActivateTaxiPathTo(534);              //TaxiPath 534
        }
        break;
    case GOSSIP_ACTION_INFO_DEF + 3:
        player->CLOSE_GOSSIP_MENU();
        player->GetSession()->SendDoFlight(1149, 1041);
        break;
    case GOSSIP_ACTION_INFO_DEF + 4:
        player->CLOSE_GOSSIP_MENU();
        player->CastSpell(player,33768,true);               //TaxiPath 585 (Gateways Murket and Shaadraz)
        break;
    case GOSSIP_ACTION_INFO_DEF + 5:
        player->CLOSE_GOSSIP_MENU();
        player->CastSpell(player,35069,true);               //TaxiPath 612 (Taxi - Hellfire Peninsula - Expedition Point to Shatter Point)
        break;
    case GOSSIP_ACTION_INFO_DEF + 6:
        player->CLOSE_GOSSIP_MENU();
        player->CastSpell(player,33899,true);               //TaxiPath 589 (Aerial Assault Flight (Alliance))
        break;
    case GOSSIP_ACTION_INFO_DEF + 7:
        player->CLOSE_GOSSIP_MENU();
        player->CastSpell(player,35065,true);               //TaxiPath 607 (Taxi - Hellfire Peninsula - Shatter Point to Beach Head)
        break;
    case GOSSIP_ACTION_INFO_DEF + 8:
        player->CLOSE_GOSSIP_MENU();
        player->CastSpell(player,33659,true);               //TaxiPath 584 (Gateways Murket and Shaadraz)
        break;
    case GOSSIP_ACTION_INFO_DEF + 9:
        player->CLOSE_GOSSIP_MENU();
        player->CastSpell(player,33825,true);               //TaxiPath 587 (Aerial Assault Flight (Horde))
        break;
    case GOSSIP_ACTION_INFO_DEF + 10:
        player->CLOSE_GOSSIP_MENU();
        player->CastSpell(player,34578,true);               //TaxiPath 604 (Taxi - Reaver's Fall to Spinebreaker Ridge)
        break;
    case GOSSIP_ACTION_INFO_DEF + 11:
        player->CLOSE_GOSSIP_MENU();
        player->CastSpell(player,41278,true);               //TaxiPath 706
        break;
    case GOSSIP_ACTION_INFO_DEF + 12:
        player->CLOSE_GOSSIP_MENU();
        player->CastSpell(player,45071,true);               //TaxiPath 779
        break;
    case GOSSIP_ACTION_INFO_DEF + 13:
        player->CLOSE_GOSSIP_MENU();
        player->CastSpell(player,45113,true);               //TaxiPath 784
        break;
    case GOSSIP_ACTION_INFO_DEF + 14:
        player->CLOSE_GOSSIP_MENU();
        player->CastSpell(player,45353,true);               //TaxiPath 788
        break;
    case GOSSIP_ACTION_INFO_DEF + 15:
        player->CLOSE_GOSSIP_MENU();
        player->CastSpell(player,34905,true);               //TaxiPath 606
        break;
    case GOSSIP_ACTION_INFO_DEF + 16:
        player->CLOSE_GOSSIP_MENU();
        player->CastSpell(player,41279,true);               //TaxiPath 705 (Taxi - Skettis to Skyguard Outpost)
        break;
    case GOSSIP_ACTION_INFO_DEF + 17:
        player->CLOSE_GOSSIP_MENU();
        player->ActivateTaxiPathTo(882);
        break;
    case GOSSIP_ACTION_INFO_DEF + 18:
        player->CLOSE_GOSSIP_MENU();
        player->ActivateTaxiPathTo(881);
        break;
    case GOSSIP_ACTION_INFO_DEF + 19:
        player->CLOSE_GOSSIP_MENU();
        player->ActivateTaxiPathTo(878);
        break;
    case GOSSIP_ACTION_INFO_DEF + 20:
        player->CLOSE_GOSSIP_MENU();
        player->ActivateTaxiPathTo(883);
        break;
    case GOSSIP_ACTION_INFO_DEF + 21:
        player->CLOSE_GOSSIP_MENU();
        player->ActivateTaxiPathTo(880);
        break;
    case GOSSIP_ACTION_INFO_DEF + 22:
        player->CLOSE_GOSSIP_MENU();
        player->ActivateTaxiPathTo(879);
        break;
    case GOSSIP_ACTION_INFO_DEF + 23:
        player->CLOSE_GOSSIP_MENU();
        player->CastSpell(player,43074,true);               //TaxiPath 736
        break;
    case GOSSIP_ACTION_INFO_DEF + 24:
        player->CLOSE_GOSSIP_MENU();
        player->ActivateTaxiPathTo(738);
        break;
    case GOSSIP_ACTION_INFO_DEF + 25:
        player->CLOSE_GOSSIP_MENU();
        player->CastSpell(player,42295,true);
        break;
    }

    return true;
}

void AddSC_npc_taxi()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="npc_taxi";
    newscript->pGossipHello = &GossipHello_npc_taxi;
    newscript->pGossipSelect = &GossipSelect_npc_taxi;
    newscript->RegisterSelf();
}
