/* Copyright (C) 2008 - 2009 Trinity <http://www.trinitycore.org/>
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

#include "ScriptPCH.h"
#include "OutdoorPvPMgr.h"
#include "OutdoorPvPWG.h"
#include "WorldSession.h"
#include "ObjectMgr.h"
#include "Vehicle.h"

#define GOSSIP_HELLO_DEMO1  "Build catapult."
#define GOSSIP_HELLO_DEMO2  "Build demolisher."
#define GOSSIP_HELLO_DEMO3  "Build siege engine."
#define GOSSIP_HELLO_DEMO4  "I cannot build more!"
#define GOSSIP_HELLO_SPIRIT1  "Guide me to the Fortress Graveyard."
#define GOSSIP_HELLO_SPIRIT2  "Guide me to the Sunken Ring Graveyard."
#define GOSSIP_HELLO_SPIRIT3  "Guide me to the Broken Temple Graveyard."
#define GOSSIP_HELLO_SPIRIT4  "Guide me to the Westspark Graveyard."
#define GOSSIP_HELLO_SPIRIT5  "Guide me to the Eastspark Graveyard."
#define GOSSIP_HELLO_SPIRIT6  "Guide me back to the Horde landing camp."
#define GOSSIP_HELLO_SPIRIT7  "Guide me back to the Alliance landing camp."

enum eWGdata
{
    // engineer spells
    SPELL_BUILD_CATAPULT                = 56663,
    SPELL_BUILD_DEMOLISHER              = 56575,
    SPELL_BUILD_SIEGE_ENGINE            = 61408,
    SPELL_BUILD_SIEGE_ENGINE2           = 56661,
    SPELL_ACTIVATE_ROBOTIC_ARMS         = 49899,

    // teleporter spells
    SPELL_VEHICLE_TELEPORT              = 49759,
};

enum eWGqueuenpctext
{
   WG_NPCQUEUE_TEXT_H_NOWAR    = 14775,
   WG_NPCQUEUE_TEXT_H_QUEUE    = 14790,
   WG_NPCQUEUE_TEXT_H_WAR      = 14777,
   WG_NPCQUEUE_TEXT_A_NOWAR    = 14782,
   WG_NPCQUEUE_TEXT_A_QUEUE    = 14791,
   WG_NPCQUEUE_TEXT_A_WAR      = 14781,
   WG_NPCQUEUE_TEXTOPTION_JOIN = -1850507,
};

class npc_demolisher_engineerer : public CreatureScript
{
public:
   npc_demolisher_engineerer() : CreatureScript("npc_demolisher_engineerer") { }


bool OnGossipHello(Player* pPlayer, Creature* pCreature)
{
   if (pCreature->isQuestGiver())
       pPlayer->PrepareQuestMenu(pCreature->GetGUID());

   if(pPlayer->isGameMaster() || pCreature->GetZoneScript() && pCreature->GetZoneScript()->GetData(pCreature->GetDBTableGUIDLow()))
   {
       if (pPlayer->HasAura(SPELL_CORPORAL))
           pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HELLO_DEMO1, GOSSIP_SENDER_MAIN,   GOSSIP_ACTION_INFO_DEF);
       else if (pPlayer->HasAura(SPELL_LIEUTENANT))
       {
           pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HELLO_DEMO1, GOSSIP_SENDER_MAIN,   GOSSIP_ACTION_INFO_DEF);
           pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HELLO_DEMO2, GOSSIP_SENDER_MAIN,   GOSSIP_ACTION_INFO_DEF+1);
           pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HELLO_DEMO3, GOSSIP_SENDER_MAIN,   GOSSIP_ACTION_INFO_DEF+2);
       }
   }
   else
       pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HELLO_DEMO4, GOSSIP_SENDER_MAIN,   GOSSIP_ACTION_INFO_DEF+9);

   pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
   return true;
}

bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
   pPlayer->CLOSE_GOSSIP_MENU();
   if(pPlayer->isGameMaster() || pCreature->GetZoneScript() && pCreature->GetZoneScript()->GetData(pCreature->GetDBTableGUIDLow()))
   {
       switch(uiAction - GOSSIP_ACTION_INFO_DEF)
       {
           case 0:
               pPlayer->CastSpell(pPlayer, 56663, false, NULL, NULL, pCreature->GetGUID());
               break;
           case 1:
               pPlayer->CastSpell(pPlayer, 56575, false, NULL, NULL, pCreature->GetGUID());
               break;
           case 2:
               pPlayer->CastSpell(pPlayer, pPlayer->GetTeamId() ? 61408 : 56661, false, NULL, NULL, pCreature->GetGUID());
               break;
       }
       if (Creature* creature = pCreature->FindNearestCreature(27852, 30.0f, true))
           creature->CastSpell(creature, SPELL_ACTIVATE_ROBOTIC_ARMS, true);
   }

   return true;
}

   CreatureAI* GetAI(Creature* pCreature) const
   {
       return new npc_demolisher_engineererAI(pCreature);
   }

   struct npc_demolisher_engineererAI : public ScriptedAI
   {
       npc_demolisher_engineererAI(Creature* pCreature) : ScriptedAI(pCreature)
       {
           me->SetReactState(REACT_PASSIVE);
       }
   };

};

class npc_wg_spirit_guide : public CreatureScript
{
public:
   npc_wg_spirit_guide() : CreatureScript("npc_wg_spirit_guide") { }
   
   CreatureAI *GetAI(Creature *creature) const
   {
       return new npc_wg_spirit_guideAI(creature);
   }

   bool OnGossipHello(Player* pPlayer, Creature* pCreature)
   {
       if (pCreature->isQuestGiver())
           pPlayer->PrepareQuestMenu(pCreature->GetGUID());

       if (OutdoorPvPWG *pvpWG = (OutdoorPvPWG*)sOutdoorPvPMgr->GetOutdoorPvPToZoneId(4197))
	   {
           if (pvpWG->isWarTime())
           {
                   if (pvpWG->getDefenderTeam() == TEAM_HORDE)
                   {
                       if (pPlayer->GetTeam() == TEAM_ALLIANCE)
                       {
                           pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HELLO_SPIRIT4, GOSSIP_SENDER_MAIN,   GOSSIP_ACTION_INFO_DEF+3);
                           pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HELLO_SPIRIT5, GOSSIP_SENDER_MAIN,   GOSSIP_ACTION_INFO_DEF+4);
                           pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HELLO_SPIRIT7, GOSSIP_SENDER_MAIN,   GOSSIP_ACTION_INFO_DEF+6);
                       }
					   else
                       {
                           pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HELLO_SPIRIT1, GOSSIP_SENDER_MAIN,   GOSSIP_ACTION_INFO_DEF);
                           pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HELLO_SPIRIT2, GOSSIP_SENDER_MAIN,   GOSSIP_ACTION_INFO_DEF+1);
                           pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HELLO_SPIRIT3, GOSSIP_SENDER_MAIN,   GOSSIP_ACTION_INFO_DEF+2);
                           pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HELLO_SPIRIT6, GOSSIP_SENDER_MAIN,   GOSSIP_ACTION_INFO_DEF+5);
                       }
                   }
                   else
                   {
                       if (pPlayer->GetTeam() == TEAM_ALLIANCE)
                       {
                           pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HELLO_SPIRIT1, GOSSIP_SENDER_MAIN,   GOSSIP_ACTION_INFO_DEF);
                           pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HELLO_SPIRIT2, GOSSIP_SENDER_MAIN,   GOSSIP_ACTION_INFO_DEF+1);
                           pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HELLO_SPIRIT3, GOSSIP_SENDER_MAIN,   GOSSIP_ACTION_INFO_DEF+2);
                           pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HELLO_SPIRIT7, GOSSIP_SENDER_MAIN,   GOSSIP_ACTION_INFO_DEF+6);
                       }
					   else
                       {
                           pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HELLO_SPIRIT4, GOSSIP_SENDER_MAIN,   GOSSIP_ACTION_INFO_DEF+3);
                           pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HELLO_SPIRIT5, GOSSIP_SENDER_MAIN,   GOSSIP_ACTION_INFO_DEF+4);
                           pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HELLO_SPIRIT6, GOSSIP_SENDER_MAIN,   GOSSIP_ACTION_INFO_DEF+5);
                       }
                   }
           }
       }

       pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
       return true;
   }

   bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
   {
       pPlayer->CLOSE_GOSSIP_MENU();
       if (pPlayer->isGameMaster() || pCreature->GetZoneScript() && pCreature->GetZoneScript()->GetData(pCreature->GetDBTableGUIDLow()))
       {
           switch (uiAction - GOSSIP_ACTION_INFO_DEF)
           {
                   case 0:
                       pPlayer->CastSpell(pPlayer, 59760, false, NULL, NULL, pCreature->GetGUID());	//Fortress teleport
                   break;	
                   case 1:
                       pPlayer->CastSpell(pPlayer, 59762, false, NULL, NULL, pCreature->GetGUID());	//sunken ring teleport
                   break;	
                   case 2:
                       pPlayer->CastSpell(pPlayer, 59763, false, NULL, NULL, pCreature->GetGUID());	//broken temple teleport
                   break;	
                   case 3:
                       pPlayer->CastSpell(pPlayer, 59766, false, NULL, NULL, pCreature->GetGUID());	//westpark teleport 
                   break;	
                   case 4:
                       pPlayer->CastSpell(pPlayer, 59767, false, NULL, NULL, pCreature->GetGUID());	//eastpark teleport
                   break;	
                   case 5:
                       pPlayer->CastSpell(pPlayer, 59765, false, NULL, NULL, pCreature->GetGUID());	//horde landing teleport
                   break;	
                   case 6:
                       pPlayer->CastSpell(pPlayer, 59769, false, NULL, NULL, pCreature->GetGUID());	//alliance landing teleport
                   break;	
           }
       }

       return true;
   }
   
   struct npc_wg_spirit_guideAI : public ScriptedAI
   {
       npc_wg_spirit_guideAI(Creature* pCreature) : ScriptedAI(pCreature)
       {
           me->SetReactState(REACT_PASSIVE);
       }
   };
};


class npc_wg_dalaran_queue : public CreatureScript
{
public:
   npc_wg_dalaran_queue() : CreatureScript("npc_wg_dalaran_queue") { }

   bool OnGossipHello(Player* pPlayer, Creature* pCreature)
   {
       if (pCreature->isQuestGiver())
           pPlayer->PrepareQuestMenu(pCreature->GetGUID());

       OutdoorPvPWG *BfWG =  (OutdoorPvPWG*)sOutdoorPvPMgr->GetOutdoorPvPToZoneId(4197);

       if (BfWG && pPlayer->getLevel() > sWorld->getIntConfig(CONFIG_CONFIG_OUTDOORPVP_WINTERGRASP_MINLEVEL))
       {

           if(BfWG->isWarTime())
           {
               if (!BfWG->isWarForTeamFull(pPlayer))
               {
                   pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT,sObjectMgr->GetTrinityStringForDBCLocale(WG_NPCQUEUE_TEXTOPTION_JOIN), GOSSIP_SENDER_MAIN,   GOSSIP_ACTION_INFO_DEF);
                   pPlayer->SEND_GOSSIP_MENU(BfWG->getDefenderTeam()?WG_NPCQUEUE_TEXT_H_WAR:WG_NPCQUEUE_TEXT_A_WAR, pCreature->GetGUID());
               }
               else
               {
                   pPlayer->SEND_GOSSIP_MENU(BfWG->getDefenderTeam()?WG_NPCQUEUE_TEXT_H_NOWAR:WG_NPCQUEUE_TEXT_A_NOWAR, pCreature->GetGUID());
               }
           }
           else
           {
               uint32 uiTime=BfWG->GetTimer();
               pPlayer->SendUpdateWorldState(4354,time(NULL)+uiTime);
               if(uiTime<15*MINUTE)
               {
                   pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT,sObjectMgr->GetTrinityStringForDBCLocale(WG_NPCQUEUE_TEXTOPTION_JOIN), GOSSIP_SENDER_MAIN,   GOSSIP_ACTION_INFO_DEF);
                   pPlayer->SEND_GOSSIP_MENU(BfWG->getDefenderTeam()?WG_NPCQUEUE_TEXT_H_QUEUE:WG_NPCQUEUE_TEXT_A_QUEUE, pCreature->GetGUID());
               }
               else
               {
                   pPlayer->SEND_GOSSIP_MENU(BfWG->getDefenderTeam()?WG_NPCQUEUE_TEXT_H_NOWAR:WG_NPCQUEUE_TEXT_A_NOWAR, pCreature->GetGUID());
               }
           }
       }
       return true;
   }

   bool OnGossipSelect(Player* pPlayer, Creature* /*pCreature*/, uint32 /*uiSender*/, uint32 /*uiAction*/)
   {
       pPlayer->CLOSE_GOSSIP_MENU();

       OutdoorPvPWG *BfWG =  (OutdoorPvPWG*)sOutdoorPvPMgr->GetOutdoorPvPToZoneId(4197);

       if (BfWG && pPlayer->getLevel() > sWorld->getIntConfig(CONFIG_CONFIG_OUTDOORPVP_WINTERGRASP_MINLEVEL))
       {
           if(BfWG->isWarTime())
           {   if(!BfWG->isWarForTeamFull(pPlayer))
                   BfWG->InvitePlayerToWar(pPlayer);
           }
           else
           {
               uint32 uiTime=BfWG->GetTimer();
               if(uiTime<15*MINUTE)
                   BfWG->InvitePlayerToQueue(pPlayer);
           }
       }
       return true;
   }
};

class go_wg_veh_teleporter : public GameObjectScript
{
public:
   go_wg_veh_teleporter() : GameObjectScript("go_wg_veh_teleporter") { }

   bool OnGossipHello(Player* player, GameObject* go)
   {
       if (GameObject* trigger = go->FindNearestGameObject(190375, 500)) // Wintergrasp Fortress Gate
       {
           if (Vehicle* vehicle = player->GetVehicle())
           {
               Position triggerPos;
               trigger->GetPosition(&triggerPos);
               triggerPos.m_positionX -= 30;
               vehicle->Relocate(triggerPos);
           }
       }
       return true;
   }
};


void AddSC_wintergrasp()
{
   new npc_demolisher_engineerer();
   new npc_wg_dalaran_queue();
   new npc_wg_spirit_guide();
   new go_wg_veh_teleporter();
}