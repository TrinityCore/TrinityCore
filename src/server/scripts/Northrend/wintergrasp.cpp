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
#include "BattlefieldMgr.h"
#include "BattlefieldWG.h"
#include "Battlefield.h"
#include "ScriptSystem.h"
#include "WorldSession.h"
#include "ObjectMgr.h"

#define GOSSIP_HELLO_DEMO1  "Build catapult."
#define GOSSIP_HELLO_DEMO2  "Build demolisher."
#define GOSSIP_HELLO_DEMO3  "Build siege engine."
#define GOSSIP_HELLO_DEMO4  "I cannot build more!"

enum eWGqueuenpctext
{
    WG_NPCQUEUE_TEXT_H_NOWAR            = 14775,
    WG_NPCQUEUE_TEXT_H_QUEUE            = 14790,
    WG_NPCQUEUE_TEXT_H_WAR              = 14777,
    WG_NPCQUEUE_TEXT_A_NOWAR            = 14782,
    WG_NPCQUEUE_TEXT_A_QUEUE            = 14791,
    WG_NPCQUEUE_TEXT_A_WAR              = 14781,
    WG_NPCQUEUE_TEXTOPTION_JOIN         = -1850507,
};

enum eWGdata
{
    // engineer spells
    SPELL_BUILD_CATAPULT                = 56663,
    SPELL_BUILD_DEMOLISHER              = 56575,
    SPELL_BUILD_SIEGE_ENGINE            = 61408,
    SPELL_BUILD_SIEGE_ENGINE2           = 56661, // does it's really needed here?
    SPELL_ACTIVATE_ROBOTIC_ARMS         = 49899,

    // teleporter spells
    SPELL_VEHICLE_TELEPORT              = 49759,
}

class npc_demolisher_engineerer : public CreatureScript
{
  public:
    npc_demolisher_engineerer() : CreatureScript("npc_demolisher_engineerer")
    {
    }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        if (pCreature->isQuestGiver())
            pPlayer->PrepareQuestMenu(pCreature->GetGUID());

        BattlefieldWG* BfWG = (BattlefieldWG *) sBattlefieldMgr.GetBattlefieldByBattleId(1);

        if (!BfWG)
            return true;

        if (BfWG->GetData(pCreature->GetEntry() == 30400 ? BATTLEFIELD_WG_DATA_MAX_VEHICLE_H : BATTLEFIELD_WG_DATA_MAX_VEHICLE_A) >
            BfWG->GetData(pCreature->GetEntry() == 30400 ? BATTLEFIELD_WG_DATA_VEHICLE_H : BATTLEFIELD_WG_DATA_VEHICLE_A))
        {
            if (pPlayer->HasAura(SPELL_CORPORAL))
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HELLO_DEMO1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
            else if (pPlayer->HasAura(SPELL_LIEUTENANT))
            {
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HELLO_DEMO1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HELLO_DEMO2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HELLO_DEMO3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
            }
        }
        else
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HELLO_DEMO4, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 9);

        pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 /*uiSender */ , uint32 uiAction)
    {
        pPlayer->CLOSE_GOSSIP_MENU();

        BattlefieldWG* BfWG = (BattlefieldWG *) sBattlefieldMgr.GetBattlefieldByBattleId(1);

        if (!BfWG)
            return true;

        if (BfWG->GetData(pCreature->GetEntry() == 30400 ? BATTLEFIELD_WG_DATA_MAX_VEHICLE_H : BATTLEFIELD_WG_DATA_MAX_VEHICLE_A) >
            BfWG->GetData(pCreature->GetEntry() == 30400 ? BATTLEFIELD_WG_DATA_VEHICLE_H : BATTLEFIELD_WG_DATA_VEHICLE_A))
        {
            switch (uiAction - GOSSIP_ACTION_INFO_DEF)
            {
                case 0:
                    pPlayer->CastSpell(pPlayer, SPELL_BUILD_CATAPULT, false, NULL, NULL, pCreature->GetGUID());
                    break;
                case 1:
                    pPlayer->CastSpell(pPlayer, SPELL_BUILD_DEMOLISHER, false, NULL, NULL, pCreature->GetGUID());
                    break;
                case 2:
                    pPlayer->CastSpell(pPlayer, pPlayer->GetTeamId() ? SPELL_BUILD_SIEGE_ENGINE : SPELL_BUILD_SIEGE_ENGINE2, false, NULL, NULL, pCreature->GetGUID());
                    break;
            }
            //spell 49899 Emote : 406 from sniff
            //INSERT INTO `spell_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES ('49899', '0', '1', '406', '0', '0', '0', '0', '0', '0');
            if (Creature* creature = pCreature->FindNearestCreature(27852, 30.0f, true))
                creature->CastSpell(creature, SPELL_ACTIVATE_ROBOTIC_ARMS, true);
        }
        return true;
    }
};

class npc_wg_spiritguide : public CreatureScript
{
  public:
    npc_wg_spiritguide() : CreatureScript("npc_wg_spiritguide")
    {
    }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        if (pCreature->isQuestGiver())
            pPlayer->PrepareQuestMenu(pCreature->GetGUID());

        BattlefieldWG* BfWG = (BattlefieldWG *) sBattlefieldMgr.GetBattlefieldByBattleId(BATTLEFIELD_BATTLEID_WG);
        if (BfWG)
        {
            GraveYardVect gy = BfWG->GetGraveYardVect();
            for (uint8 i = 0; i < gy.size(); i++)
            {
                if (gy[i]->GetControlTeamId() == pPlayer->GetTeamId())
                {
                    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, sObjectMgr->GetTrinityStringForDBCLocale(((BfGraveYardWG *) gy[i])->GetTextId()), GOSSIP_SENDER_MAIN,
                                             GOSSIP_ACTION_INFO_DEF + i);
                }
            }
        }

        pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* pPlayer, Creature* /*pCreature */ , uint32 /*uiSender */ , uint32 uiAction)
    {
        pPlayer->CLOSE_GOSSIP_MENU();

        BattlefieldWG* BfWG = (BattlefieldWG *) sBattlefieldMgr.GetBattlefieldByBattleId(BATTLEFIELD_BATTLEID_WG);
        if (BfWG)
        {
            GraveYardVect gy = BfWG->GetGraveYardVect();
            for (uint8 i = 0; i < gy.size(); i++)
            {
                if (uiAction - GOSSIP_ACTION_INFO_DEF == i && gy[i]->GetControlTeamId() == pPlayer->GetTeamId())
                {
                    WorldSafeLocsEntry const* ws = sWorldSafeLocsStore.LookupEntry(gy[i]->GetGraveYardId());
                    pPlayer->TeleportTo(ws->map_id, ws->x, ws->y, ws->z, 0);
                }
            }
        }
        return true;
    }
};

class npc_wg_dalaran_queue : public CreatureScript
{
  public:
    npc_wg_dalaran_queue() : CreatureScript("npc_wg_dalaran_queue")
    {
    }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        if (pCreature->isQuestGiver())
            pPlayer->PrepareQuestMenu(pCreature->GetGUID());

        BattlefieldWG* BfWG = (BattlefieldWG *) sBattlefieldMgr.GetBattlefieldByBattleId(BATTLEFIELD_BATTLEID_WG);
        if (BfWG)
        {

            if (BfWG->IsWarTime())
            {
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, sObjectMgr->GetTrinityStringForDBCLocale(WG_NPCQUEUE_TEXTOPTION_JOIN), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
                pPlayer->SEND_GOSSIP_MENU(BfWG->GetDefenderTeam()? WG_NPCQUEUE_TEXT_H_WAR : WG_NPCQUEUE_TEXT_A_WAR, pCreature->GetGUID());
            }
            else
            {
                uint32 uiTime = BfWG->GetTimer() / 1000;
                pPlayer->SendUpdateWorldState(4354, time(NULL) + uiTime);
                if (uiTime < 15 * MINUTE)
                {
                    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, sObjectMgr->GetTrinityStringForDBCLocale(WG_NPCQUEUE_TEXTOPTION_JOIN), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
                    pPlayer->SEND_GOSSIP_MENU(BfWG->GetDefenderTeam() ? WG_NPCQUEUE_TEXT_H_QUEUE : WG_NPCQUEUE_TEXT_A_QUEUE, pCreature->GetGUID());
                }
                else
                {
                    pPlayer->SEND_GOSSIP_MENU(BfWG->GetDefenderTeam() ? WG_NPCQUEUE_TEXT_H_NOWAR : WG_NPCQUEUE_TEXT_A_NOWAR, pCreature->GetGUID());
                }
            }
        }
        return true;
    }

    bool OnGossipSelect(Player* pPlayer, Creature* /*pCreature */ , uint32 /*uiSender */ , uint32 /*uiAction */ )
    {
        pPlayer->CLOSE_GOSSIP_MENU();

        BattlefieldWG* BfWG = (BattlefieldWG *) sBattlefieldMgr.GetBattlefieldByBattleId(BATTLEFIELD_BATTLEID_WG);
        if (BfWG)
        {
            if (BfWG->IsWarTime())
            {
                BfWG->InvitePlayerToWar(pPlayer);
            }
            else
            {
                uint32 uiTime = BfWG->GetTimer() / 1000;
                if (uiTime < 15 * MINUTE)
                    BfWG->InvitePlayerToQueue(pPlayer);
            }
        }
        return true;
    }
};

const uint32 Vehicules[4] = { 32627, 28312, 28094, 27881 };

class go_wintergrasp_teleporter : public GameObjectScript
{
  public:
    go_wintergrasp_teleporter() : GameObjectScript("go_wintergrasp_teleporter")
    {
    }

    struct go_wintergrasp_teleporterAI : public GameObjectAI
    {
        go_wintergrasp_teleporterAI(GameObject* g) : GameObjectAI(g)
        {
            uiCheckTimer = 1000;
        }

        void UpdateAI(const uint32 diff)
        {
            if (uiCheckTimer <= diff)
            {
                for (uint8 i = 0; i < 4; i++)
                    if (Creature* pVehicle = go->FindNearestCreature(Vehicules[i], 3.0f, true))
                        if (!pVehicle->HasAura(SPELL_VEHICLE_TELEPORT))
                        {
                            if (pVehicle->GetVehicle())
                            {
                                if (Unit* player = pVehicle->GetVehicle()->GetPassenger(0))
                                {
                                    uint32 gofaction = go->GetUInt32Value(GAMEOBJECT_FACTION);
                                    uint32 plfaction = player->getFaction();
                                    if (gofaction == plfaction)
                                    {
                                        pVehicle->CastSpell(pVehicle, SPELL_VEHICLE_TELEPORT, true);
                                        if (Creature* TargetTeleport = pVehicle->FindNearestCreature(23472, 100.0f, true))
                                        {
                                            float x, y, z, o;
                                            TargetTeleport->GetPosition(x, y, z, o);
                                            pVehicle->GetVehicle()->TeleportVehicle(x, y, z, o);
                                        }
                                    }
                                }
                            }
                        }
                uiCheckTimer = 1000;
            }
            else
                uiCheckTimer -= diff;
        }
      private:
          uint32 uiCheckTimer;
    };

    GameObjectAI *GetAI(GameObject* go) const
    {
        return new go_wintergrasp_teleporterAI(go);
    }
};

class npc_wintergrasp_quest_giver : public CreatureScript
{
  public:
    npc_wintergrasp_quest_giver() : CreatureScript("npc_wintergrasp_quest_giver")
    {
    }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        if (pCreature->isQuestGiver())
            pPlayer->PrepareQuestMenu(pCreature->GetGUID());

        BattlefieldWG* BfWG = (BattlefieldWG *) sBattlefieldMgr.GetBattlefieldByBattleId(BATTLEFIELD_BATTLEID_WG);
        if (BfWG)
        {
            if (pCreature->isQuestGiver())
            {
                Object* pObject = (Object *) pCreature;
                QuestRelations* pObjectQR = sObjectMgr->GetCreatureQuestRelationMap();
                QuestRelations* pObjectQIR = sObjectMgr->GetCreatureQuestInvolvedRelation();

                QuestMenu & qm = pPlayer->PlayerTalkClass->GetQuestMenu();
                qm.ClearMenu();

                for (QuestRelations::const_iterator i = pObjectQIR->lower_bound(pObject->GetEntry()); i != pObjectQIR->upper_bound(pObject->GetEntry()); ++i)
                {
                    uint32 quest_id = i->second;
                    QuestStatus status = pPlayer->GetQuestStatus(quest_id);
                    if (status == QUEST_STATUS_COMPLETE && !pPlayer->GetQuestRewardStatus(quest_id))
                        qm.AddMenuItem(quest_id, 4);
                    else if (status == QUEST_STATUS_INCOMPLETE)
                        qm.AddMenuItem(quest_id, 4);
                }

                for (QuestRelations::const_iterator i = pObjectQR->lower_bound(pObject->GetEntry()); i != pObjectQR->upper_bound(pObject->GetEntry()); ++i)
                {
                    uint32 quest_id = i->second;
                    Quest const* pQuest = sObjectMgr->GetQuestTemplate(quest_id);
                    if (!pQuest)
                        continue;

                    switch (quest_id)
                    {
                        // Horde attacker
                        case 13193:
                        case 13202:
                        case 13180:
                        case 13200:
                        case 13201:
                        case 13223:
                            if (BfWG->GetAttackerTeam() == TEAM_HORDE)
                            {
                                QuestStatus status = pPlayer->GetQuestStatus(quest_id);

                                if (pQuest->IsAutoComplete() && pPlayer->CanTakeQuest(pQuest, false))
                                    qm.AddMenuItem(quest_id, 4);
                                else if (status == QUEST_STATUS_NONE && pPlayer->CanTakeQuest(pQuest, false))
                                    qm.AddMenuItem(quest_id, 2);
                            }
                            break;
                        // Horde defender
                        case 13199:
                        case 13192:
                        case 13178:
                        case 13191:
                        case 13194:
                        case 13539:
                        case 13185:
                            if (BfWG->GetDefenderTeam() == TEAM_HORDE)
                            {
                                QuestStatus status = pPlayer->GetQuestStatus(quest_id);

                                if (pQuest->IsAutoComplete() && pPlayer->CanTakeQuest(pQuest, false))
                                    qm.AddMenuItem(quest_id, 4);
                                else if (status == QUEST_STATUS_NONE && pPlayer->CanTakeQuest(pQuest, false))
                                    qm.AddMenuItem(quest_id, 2);
                            }
                            break;
                        // Alliance attacker
                        case 13196:
                        case 13198:
                        case 13179:
                        case 13222:
                        case 13195:
                            if (BfWG->GetAttackerTeam() == TEAM_ALLIANCE)
                            {
                                QuestStatus status = pPlayer->GetQuestStatus(quest_id);

                                if (pQuest->IsAutoComplete() && pPlayer->CanTakeQuest(pQuest, false))
                                    qm.AddMenuItem(quest_id, 4);
                                else if (status == QUEST_STATUS_NONE && pPlayer->CanTakeQuest(pQuest, false))
                                    qm.AddMenuItem(quest_id, 2);
                            }
                            break;
                        // Alliance defender
                        case 13154:
                        case 13153:
                        case 13177:
                        case 13538:
                        case 13186:
                        case 13156:
                            if (BfWG->GetDefenderTeam() == TEAM_ALLIANCE)
                            {
                                QuestStatus status = pPlayer->GetQuestStatus(quest_id);

                                if (pQuest->IsAutoComplete() && pPlayer->CanTakeQuest(pQuest, false))
                                    qm.AddMenuItem(quest_id, 4);
                                else if (status == QUEST_STATUS_NONE && pPlayer->CanTakeQuest(pQuest, false))
                                    qm.AddMenuItem(quest_id, 2);
                            }
                            break;
                        default:
                            QuestStatus status = pPlayer->GetQuestStatus(quest_id);

                            if (pQuest->IsAutoComplete() && pPlayer->CanTakeQuest(pQuest, false))
                                qm.AddMenuItem(quest_id, 4);
                            else if (status == QUEST_STATUS_NONE && pPlayer->CanTakeQuest(pQuest, false))
                                qm.AddMenuItem(quest_id, 2);
                            break;
                    }
                }
            }
            pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
            return true;
        }
        return true;
    }
};

void AddSC_wintergrasp()
{
    new npc_wg_dalaran_queue();
    new npc_wg_spiritguide();
    new npc_demolisher_engineerer();
    new go_wintergrasp_teleporter();
    new npc_wintergrasp_quest_giver();
}
