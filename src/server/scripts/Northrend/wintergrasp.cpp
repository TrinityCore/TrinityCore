/* Copyright (C) 2008 - 2009 Trinity <http://www.trinitycore.org/>
*
 * Patch supported by ChaosUA & TCRU community http://trinity-core.ru/
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

#include "ScriptPCH.h"
#include "OutdoorPvPWG.h"
#include "OutdoorPvPMgr.h"

#define GOSSIP_HELLO_DEMO1  "Build catapult."
#define GOSSIP_HELLO_DEMO2  "Build demolisher."
#define GOSSIP_HELLO_DEMO3  "Build siege engine."
#define GOSSIP_HELLO_DEMO4  "I cannot build more!"

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
            case 0: pPlayer->CastSpell(pPlayer, 56663, false, NULL, NULL, pCreature->GetGUID()); break;
            case 1: pPlayer->CastSpell(pPlayer, 56575, false, NULL, NULL, pCreature->GetGUID()); break;
            case 2: pPlayer->CastSpell(pPlayer, pPlayer->GetTeamId() ? 61408 : 56661, false, NULL, NULL, pCreature->GetGUID()); break;
        }
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

enum eWintergraspBattleMage
{
    SPELL_PORTAL_VISUAL        = 60223,
    GO_WINTERGRASP_PORTAL    = 193772
};

class npc_wg_ally_battle_mage : public CreatureScript
{
public:
    npc_wg_ally_battle_mage() : CreatureScript("npc_wg_ally_battle_mage") { }

    CreatureAI *GetAI(Creature *creature) const
    {
        return new npc_wg_ally_battle_mageAI(creature);
    }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        if (!sWorld->getBoolConfig(CONFIG_OUTDOORPVP_WINTERGRASP_ENABLED))
            return false;

        if (OutdoorPvPWG *pvpWG = (OutdoorPvPWG*)sOutdoorPvPMgr->GetOutdoorPvPToZoneId(4197))
        {
            if (pvpWG->isWarTime())
            {
                if (pvpWG->getDefenderTeam() == TEAM_HORDE)
                    pPlayer->SEND_GOSSIP_MENU(14777, pCreature->GetGUID());
                else
                    pPlayer->SEND_GOSSIP_MENU(14781, pCreature->GetGUID());
            }
            else
            {
                if (pvpWG->getDefenderTeam() == TEAM_HORDE)
                    pPlayer->SEND_GOSSIP_MENU(14775, pCreature->GetGUID());
                else
                    pPlayer->SEND_GOSSIP_MENU(14782, pCreature->GetGUID());
            }
        }
        return true;
    }

    struct npc_wg_ally_battle_mageAI : public ScriptedAI
    {
        npc_wg_ally_battle_mageAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            uiPortalTimer = 0;
            uiPortalPhase = 0;
            Check = true;
        }

        uint32 uiPortalTimer;
        uint8 uiPortalPhase;
        GameObject* WintergraspPortal;
        bool Player;
        bool Check;
        bool Check2;

        void UpdateAI(const uint32 diff)
        {
            // If WG is disabled, don't do anything.
            if (!sWorld->getBoolConfig(CONFIG_OUTDOORPVP_WINTERGRASP_ENABLED))
                return;

            if (OutdoorPvPWG *pvpWG = (OutdoorPvPWG*)sOutdoorPvPMgr->GetOutdoorPvPToZoneId(4197))
            {
                // Get playerlist if there is.
                if (pvpWG->isWarTime() && Check == true)
                {
                    Map::PlayerList const &PlayerList = me->GetMap()->GetPlayers();
                    for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                    {
                        if (!PlayerList.isEmpty())
                        {
                            if (i->getSource()->GetDistance2d(me) <= 75)
                            {
                                Player = true;
                                Check = false;
                            }
                            else
                            {
                                Player = false;
                                Check = false;
                                Check2 = true;
                            }
                        }
                        else
                        {
                            Player = false;
                            Check = false;
                            Check2 = true;
                        }
                    }
                }

                if (pvpWG->m_changeAlly != true) // If wg is switching (.wg switch)
                {
                    if (pvpWG->isWarTime())
                    {
                        if (Player == true) //(false) If there isn't any player, then, don't cast the portal spell. Just summon gameobject.
                        {
                            if (uiPortalTimer <= diff)
                            {
                                switch (uiPortalPhase)
                                {
                                case 0:
                                    me->SetOrientation(4.037271f);
                                    me->SendMovementFlagUpdate();
                                    ++uiPortalPhase;
                                    uiPortalTimer = 100;
                                    break;
                                case 1:
                                    me->AI()->DoCast(SPELL_PORTAL_VISUAL);
                                    ++uiPortalPhase;
                                    uiPortalTimer = 900;
                                    break;
                                case 2:
                                    WintergraspPortal = me->SummonGameObject(GO_WINTERGRASP_PORTAL, 5686.974609f, 773.303711f, 647.753235f, 5.572729f, 0, 0, 0.324484f, -0.945891f, 0);
                                    me->SetOrientation(5.515240f);
                                    me->SendMovementFlagUpdate();
                                    me->MonsterYell("Reinforcements are needed on the Wintergrasp battlefield! I have opened a portal for quick travel to the battle at The Silver Enclave.", LANG_UNIVERSAL, 0);
                                    ++uiPortalPhase;
                                    uiPortalTimer = 1000;
                                    break;
                                }
                            }else uiPortalTimer -= diff;
                        }
                        else
                        {
                            if (Check2 == true) // If the portal isn't exist
                            {
                                WintergraspPortal = me->SummonGameObject(GO_WINTERGRASP_PORTAL, 5686.974609f, 773.303711f, 647.753235f, 5.572729f, 0, 0, 0.324484f, -0.945891f, 0);
                                Check2 = false;
                            }
                        }
                    }
                    else
                    {
                        if (pvpWG->getDefenderTeam() == TEAM_ALLIANCE)
                        {
                            if (pvpWG->m_timer <= 3600000) // An hour before battle begin, the portal will disappear.
                            {
                                uiPortalTimer = 0;
                                uiPortalPhase = 0;
                                Check = true;
                                Check2 = false;
                                if (GameObject* WintergraspPortal = me->FindNearestGameObject(GO_WINTERGRASP_PORTAL, 5.0f)) // If the portal is exist
                                    WintergraspPortal->RemoveFromWorld();
                            }
                        }
                        else
                        {
                            uiPortalTimer = 0;
                            uiPortalPhase = 0;
                            Check = true;
                            Check2 = false;
                            if (GameObject* WintergraspPortal = me->FindNearestGameObject(GO_WINTERGRASP_PORTAL, 5.0f)) // If the portal is exist
                                WintergraspPortal->RemoveFromWorld();
                        }
                    }
                }
            }
        }
    };
};

class npc_wg_horde_battle_mage : public CreatureScript
{
public:
    npc_wg_horde_battle_mage() : CreatureScript("npc_wg_horde_battle_mage") { }

    CreatureAI *GetAI(Creature *creature) const
    {
        return new npc_wg_horde_battle_mageAI(creature);
    }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        if (!sWorld->getBoolConfig(CONFIG_OUTDOORPVP_WINTERGRASP_ENABLED))
            return false;

        if (OutdoorPvPWG *pvpWG = (OutdoorPvPWG*)sOutdoorPvPMgr->GetOutdoorPvPToZoneId(4197))
        {
            if (pvpWG->isWarTime())
            {
                if (pvpWG->getDefenderTeam() == TEAM_HORDE)
                    pPlayer->SEND_GOSSIP_MENU(14777, pCreature->GetGUID());
                else
                    pPlayer->SEND_GOSSIP_MENU(14781, pCreature->GetGUID());
            }
            else
            {
                if (pvpWG->getDefenderTeam() == TEAM_HORDE)
                    pPlayer->SEND_GOSSIP_MENU(14775, pCreature->GetGUID());
                else
                    pPlayer->SEND_GOSSIP_MENU(14782, pCreature->GetGUID());
            }
        }
        return true;
    }

    struct npc_wg_horde_battle_mageAI : public ScriptedAI
    {
        npc_wg_horde_battle_mageAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            uiPortalTimer = 0;
            uiPortalPhase = 0;
            Check = true;
        }

        uint32 uiPortalTimer;
        uint8 uiPortalPhase;
        GameObject* WintergraspPortal;
        bool Player;
        bool Check;
        bool Check2;

        void UpdateAI(const uint32 diff)
        {
            // If WG is disabled, don't do anything.
            if (!sWorld->getBoolConfig(CONFIG_OUTDOORPVP_WINTERGRASP_ENABLED))
                return;

            if (OutdoorPvPWG *pvpWG = (OutdoorPvPWG*)sOutdoorPvPMgr->GetOutdoorPvPToZoneId(4197))
            {
                // Get playerlist if there is.
                if (pvpWG->isWarTime() && Check == true)
                {
                    Map::PlayerList const &PlayerList = me->GetMap()->GetPlayers();
                    for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                    {
                        if (!PlayerList.isEmpty())
                        {
                            if (i->getSource()->GetDistance2d(me) <= 75)
                            {
                                Player = true;
                                Check = false;
                            }
                            else
                            {
                                Player = false;
                                Check = false;
                                Check2 = true;
                            }
                        }
                        else
                        {
                            Player = false;
                            Check = false;
                            Check2 = true;
                        }
                    }
                }

                if (pvpWG->m_changeHorde != true) // If wg is switching (.wg switch)
                {
                    if (pvpWG->isWarTime())
                    {
                        if (Player == true) //(false) If there isn't any player, then, don't cast the portal spell. Just summon gameobject.
                        {
                            if (uiPortalTimer <= diff)
                            {
                                switch (uiPortalPhase)
                                {
                                case 0:
                                    me->SetOrientation(4.356160f);
                                    me->SendMovementFlagUpdate();
                                    ++uiPortalPhase;
                                    uiPortalTimer = 100;
                                    break;
                                case 1:
                                    me->AI()->DoCast(SPELL_PORTAL_VISUAL);
                                    ++uiPortalPhase;
                                    uiPortalTimer = 900;
                                    break;
                                case 2:
                                    WintergraspPortal = me->SummonGameObject(GO_WINTERGRASP_PORTAL, 5924.042969f, 570.354492f, 661.087280f, 5.930885f, 0, 0, 0.324484f, -0.945891f, 0);
                                    me->SetOrientation(6.003930f);
                                    me->SendMovementFlagUpdate();
                                    ++uiPortalPhase;
                                    uiPortalTimer = 1000;
                                    break;
                                }
                            }else uiPortalTimer -= diff;
                        }
                        else
                        {
                            if (Check2 == true) // If the portal isn't exist
                            {
                                WintergraspPortal = me->SummonGameObject(GO_WINTERGRASP_PORTAL, 5686.974609f, 773.303711f, 647.753235f, 5.572729f, 0, 0, 0.324484f, -0.945891f, 0);
                                Check2 = false;
                            }
                        }
                    }
                    else
                    {
                        if (pvpWG->getDefenderTeam() == TEAM_HORDE)
                        {
                            if (pvpWG->m_timer <= 3600000) // An hour before battle begin, the portal will disappear.
                            {
                                uiPortalTimer = 0;
                                uiPortalPhase = 0;
                                Check = true;
                                Check2 = false;
                                if (GameObject* WintergraspPortal = me->FindNearestGameObject(GO_WINTERGRASP_PORTAL, 5.0f)) // If the portal is exist
                                    WintergraspPortal->RemoveFromWorld();
                            }
                        }
                        else
                        {
                            uiPortalTimer = 0;
                            uiPortalPhase = 0;
                            Check = true;
                            Check2 = false;
                            if (GameObject* WintergraspPortal = me->FindNearestGameObject(GO_WINTERGRASP_PORTAL, 5.0f)) // If the portal is exist
                                WintergraspPortal->RemoveFromWorld();
                        }
                    }
                }
            }
        }
    };
};

class go_wg_veh_teleporter : public GameObjectScript
{
public:
    go_wg_veh_teleporter() : GameObjectScript("go_wg_veh_teleporter") { }

    bool OnGossipHello(Player *pPlayer, GameObject * pGO)
    {
        if (GameObject* trigger = pGO->FindNearestGameObject(190375, 500)) // Wintergrasp Fortress Gate
            if (Vehicle * veh = pPlayer->GetVehicle())
            {
                Position triggerPos;
                trigger->GetPosition(&triggerPos);
                triggerPos.m_positionX -= 30;
                veh->Relocate(triggerPos);
            }
        
        return true;
    }
};

void AddSC_wintergrasp()
{
    new npc_demolisher_engineerer();
    new npc_wg_ally_battle_mage();
    new npc_wg_horde_battle_mage();
    new go_wg_veh_teleporter();
}