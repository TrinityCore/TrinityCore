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

#include "BattlefieldMgr.h"
#include "BattlefieldWG.h"
#include "Battlefield.h"
#include "ScriptSystem.h"
#include "WorldSession.h"
#include "ObjectMgr.h"
#include "Vehicle.h"

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

enum WGscriptdata
{
    // engineer spells
    SPELL_BUILD_CATAPULT                = 56663,
    SPELL_BUILD_DEMOLISHER              = 56575,
    SPELL_BUILD_SIEGE_ENGINE            = 61408,
    SPELL_BUILD_SIEGE_ENGINE2           = 56661, // does it's really needed here?
    SPELL_ACTIVATE_ROBOTIC_ARMS         = 49899,

    // teleporter spells
    SPELL_VEHICLE_TELEPORT              = 49759,

    // npcs
    NPC_ROBOTIC_ARMS                    = 27852,
    NPC_WORLD_TRIGGER_WG                = 23472,
};

class npc_wg_demolisher_engineer : public CreatureScript
{
  public:
    npc_wg_demolisher_engineer() : CreatureScript("npc_wg_demolisher_engineer")
    {
    }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (creature->isQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());

        Battlefield* BfWG = sBattlefieldMgr->GetBattlefieldByBattleId(BATTLEFIELD_BATTLEID_WG);

        if (!BfWG)
            return true;

        if (BfWG->GetData(creature->GetEntry() == 30400 ? BATTLEFIELD_WG_DATA_MAX_VEHICLE_H : BATTLEFIELD_WG_DATA_MAX_VEHICLE_A) >
            BfWG->GetData(creature->GetEntry() == 30400 ? BATTLEFIELD_WG_DATA_VEHICLE_H : BATTLEFIELD_WG_DATA_VEHICLE_A))
        {
            if (player->HasAura(SPELL_CORPORAL))
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HELLO_DEMO1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
            else if (player->HasAura(SPELL_LIEUTENANT))
            {
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HELLO_DEMO1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HELLO_DEMO2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HELLO_DEMO3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
            }
        }
        else
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HELLO_DEMO4, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 9);

        player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender */ , uint32 action)
    {
        player->CLOSE_GOSSIP_MENU();

        Battlefield* BfWG = sBattlefieldMgr->GetBattlefieldByBattleId(BATTLEFIELD_BATTLEID_WG);

        if (!BfWG)
            return true;

        if (BfWG->GetData(creature->GetEntry() == 30400 ? BATTLEFIELD_WG_DATA_MAX_VEHICLE_H : BATTLEFIELD_WG_DATA_MAX_VEHICLE_A) >
            BfWG->GetData(creature->GetEntry() == 30400 ? BATTLEFIELD_WG_DATA_VEHICLE_H : BATTLEFIELD_WG_DATA_VEHICLE_A))
        {
            switch (action - GOSSIP_ACTION_INFO_DEF)
            {
                case 0:
                    player->CastSpell(player, SPELL_BUILD_CATAPULT, false, NULL, NULL, creature->GetGUID());
                    break;
                case 1:
                    player->CastSpell(player, SPELL_BUILD_DEMOLISHER, false, NULL, NULL, creature->GetGUID());
                    break;
                case 2:
                    player->CastSpell(player, player->GetTeamId() ? SPELL_BUILD_SIEGE_ENGINE : SPELL_BUILD_SIEGE_ENGINE2, false, NULL, NULL, creature->GetGUID());
                    break;
            }
            //spell 49899 Emote : 406 from sniff
            //INSERT INTO `spell_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES ('49899', '0', '1', '406', '0', '0', '0', '0', '0', '0');
            if (Creature* mechCreature = creature->FindNearestCreature(NPC_ROBOTIC_ARMS, 30.0f, true))
                creature->CastSpell(mechCreature, SPELL_ACTIVATE_ROBOTIC_ARMS, true);
        }
        return true;
    }
};

class npc_wg_spirit_guide : public CreatureScript
{
  public:
    npc_wg_spirit_guide() : CreatureScript("npc_wg_spirit_guide")
    {
    }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (creature->isQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());

        Battlefield* BfWG = sBattlefieldMgr->GetBattlefieldByBattleId(BATTLEFIELD_BATTLEID_WG);
        if (BfWG)
        {
            GraveYardVect gy = BfWG->GetGraveYardVect();
            for (uint8 i = 0; i < gy.size(); i++)
            {
                if (gy[i]->GetControlTeamId() == player->GetTeamId())
                {
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, sObjectMgr->GetTrinityStringForDBCLocale(((BfGraveYardWG *) gy[i])->GetTextId()), GOSSIP_SENDER_MAIN,
                                             GOSSIP_ACTION_INFO_DEF + i);
                }
            }
        }

        player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* /*creature */ , uint32 /*sender */ , uint32 action)
    {
        player->CLOSE_GOSSIP_MENU();

        Battlefield* BfWG = sBattlefieldMgr->GetBattlefieldByBattleId(BATTLEFIELD_BATTLEID_WG);
        if (BfWG)
        {
            GraveYardVect gy = BfWG->GetGraveYardVect();
            for (uint8 i = 0; i < gy.size(); i++)
            {
                if (action - GOSSIP_ACTION_INFO_DEF == i && gy[i]->GetControlTeamId() == player->GetTeamId())
                {
                    WorldSafeLocsEntry const* ws = sWorldSafeLocsStore.LookupEntry(gy[i]->GetGraveYardId());
                    player->TeleportTo(ws->map_id, ws->x, ws->y, ws->z, 0);
                }
            }
        }
        return true;
    }
};

class npc_wg_queue : public CreatureScript
{
  public:
    npc_wg_queue() : CreatureScript("npc_wg_queue")
    {
    }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (creature->isQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());

        Battlefield* BfWG = sBattlefieldMgr->GetBattlefieldByBattleId(BATTLEFIELD_BATTLEID_WG);
        if (BfWG)
        {

            if (BfWG->IsWarTime())
            {
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, sObjectMgr->GetTrinityStringForDBCLocale(WG_NPCQUEUE_TEXTOPTION_JOIN), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
                player->SEND_GOSSIP_MENU(BfWG->GetDefenderTeam()? WG_NPCQUEUE_TEXT_H_WAR : WG_NPCQUEUE_TEXT_A_WAR, creature->GetGUID());
            }
            else
            {
                uint32 uiTime = BfWG->GetTimer() / 1000;
                player->SendUpdateWorldState(4354, time(NULL) + uiTime);
                if (uiTime < 15 * MINUTE)
                {
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, sObjectMgr->GetTrinityStringForDBCLocale(WG_NPCQUEUE_TEXTOPTION_JOIN), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
                    player->SEND_GOSSIP_MENU(BfWG->GetDefenderTeam() ? WG_NPCQUEUE_TEXT_H_QUEUE : WG_NPCQUEUE_TEXT_A_QUEUE, creature->GetGUID());
                }
                else
                {
                    player->SEND_GOSSIP_MENU(BfWG->GetDefenderTeam() ? WG_NPCQUEUE_TEXT_H_NOWAR : WG_NPCQUEUE_TEXT_A_NOWAR, creature->GetGUID());
                }
            }
        }
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* /*creature */ , uint32 /*sender */ , uint32 /*action */ )
    {
        player->CLOSE_GOSSIP_MENU();

        Battlefield* BfWG = sBattlefieldMgr->GetBattlefieldByBattleId(BATTLEFIELD_BATTLEID_WG);
        if (BfWG)
        {
            if (BfWG->IsWarTime())
            {
                BfWG->InvitePlayerToWar(player);
            }
            else
            {
                uint32 uiTime = BfWG->GetTimer() / 1000;
                if (uiTime < 15 * MINUTE)
                    BfWG->InvitePlayerToQueue(player);
            }
        }
        return true;
    }
};

const uint32 Vehicules[4] = { 32627, 28312, 28094, 27881 };

class go_wg_vehicle_teleporter : public GameObjectScript
{
  public:
    go_wg_vehicle_teleporter() : GameObjectScript("go_wg_vehicle_teleporter")
    {
    }

    struct go_wg_vehicle_teleporterAI : public GameObjectAI
    {
        go_wg_vehicle_teleporterAI(GameObject* g) : GameObjectAI(g)
        {
            uiCheckTimer = 1000;
        }

        void UpdateAI(const uint32 diff)
        {
            if (uiCheckTimer <= diff)
            {
                for (uint8 i = 0; i < 4; i++)
                    if (Creature* vehicleCreature = go->FindNearestCreature(Vehicules[i], 3.0f, true))
                        if (!vehicleCreature->HasAura(SPELL_VEHICLE_TELEPORT))
                            if (Vehicle* vehicle = vehicleCreature->GetVehicle())
                                if (Unit* passenger = vehicle->GetPassenger(0))
                                {
                                    uint32 gofaction = go->GetUInt32Value(GAMEOBJECT_FACTION);
                                    uint32 plfaction = passenger->getFaction();
                                    if (gofaction == plfaction)
                                    {
                                        if (Creature* teleportTrigger = vehicleCreature->FindNearestCreature(NPC_WORLD_TRIGGER_WG,100.0f,true))
                                            teleportTrigger->CastSpell(vehicleCreature, SPELL_VEHICLE_TELEPORT, true);
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
        return new go_wg_vehicle_teleporterAI(go);
    }
};

class npc_wg_quest_giver : public CreatureScript
{
  public:
    npc_wg_quest_giver() : CreatureScript("npc_wg_quest_giver")
    {
    }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (creature->isQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());

        Battlefield* BfWG = sBattlefieldMgr->GetBattlefieldByBattleId(BATTLEFIELD_BATTLEID_WG);
        if (BfWG)
        {
            if (creature->isQuestGiver())
            {
                Object* object = (Object *) creature;
                QuestRelations* objectQR = sObjectMgr->GetCreatureQuestRelationMap();
                QuestRelations* objectQIR = sObjectMgr->GetCreatureQuestInvolvedRelation();

                QuestMenu & qm = player->PlayerTalkClass->GetQuestMenu();
                qm.ClearMenu();

                for (QuestRelations::const_iterator i = objectQIR->lower_bound(object->GetEntry()); i != objectQIR->upper_bound(object->GetEntry()); ++i)
                {
                    uint32 quest_id = i->second;
                    QuestStatus status = player->GetQuestStatus(quest_id);
                    if (status == QUEST_STATUS_COMPLETE && !player->GetQuestRewardStatus(quest_id))
                        qm.AddMenuItem(quest_id, 4);
                    else if (status == QUEST_STATUS_INCOMPLETE)
                        qm.AddMenuItem(quest_id, 4);
                }

                for (QuestRelations::const_iterator i = objectQR->lower_bound(object->GetEntry()); i != objectQR->upper_bound(object->GetEntry()); ++i)
                {
                    uint32 quest_id = i->second;
                    Quest const* quest = sObjectMgr->GetQuestTemplate(quest_id);
                    if (!quest)
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
                                QuestStatus status = player->GetQuestStatus(quest_id);

                                if (quest->IsAutoComplete() && player->CanTakeQuest(quest, false))
                                    qm.AddMenuItem(quest_id, 4);
                                else if (status == QUEST_STATUS_NONE && player->CanTakeQuest(quest, false))
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
                                QuestStatus status = player->GetQuestStatus(quest_id);

                                if (quest->IsAutoComplete() && player->CanTakeQuest(quest, false))
                                    qm.AddMenuItem(quest_id, 4);
                                else if (status == QUEST_STATUS_NONE && player->CanTakeQuest(quest, false))
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
                                QuestStatus status = player->GetQuestStatus(quest_id);

                                if (quest->IsAutoComplete() && player->CanTakeQuest(quest, false))
                                    qm.AddMenuItem(quest_id, 4);
                                else if (status == QUEST_STATUS_NONE && player->CanTakeQuest(quest, false))
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
                                QuestStatus status = player->GetQuestStatus(quest_id);

                                if (quest->IsAutoComplete() && player->CanTakeQuest(quest, false))
                                    qm.AddMenuItem(quest_id, 4);
                                else if (status == QUEST_STATUS_NONE && player->CanTakeQuest(quest, false))
                                    qm.AddMenuItem(quest_id, 2);
                            }
                            break;
                        default:
                            QuestStatus status = player->GetQuestStatus(quest_id);

                            if (quest->IsAutoComplete() && player->CanTakeQuest(quest, false))
                                qm.AddMenuItem(quest_id, 4);
                            else if (status == QUEST_STATUS_NONE && player->CanTakeQuest(quest, false))
                                qm.AddMenuItem(quest_id, 2);
                            break;
                    }
                }
            }
            player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
            return true;
        }
        return true;
    }
};

class achievement_wg_didnt_stand_a_chance : public AchievementCriteriaScript
{
public:
    achievement_wg_didnt_stand_a_chance() : AchievementCriteriaScript("achievement_wg_didnt_stand_a_chance") { }

    bool OnCheck(Player* source, Unit* target)
    {
        if (!target)
            return false;

        if (Player* victim = target->ToPlayer())
        {
            if (!victim->IsMounted())
                return false;

            if (Vehicle* vehicle = source->GetVehicle())
                if (vehicle->GetVehicleInfo()->m_ID == 244) // Wintergrasp Tower Cannon
                    return true;
        }

        return false;
    }
};

void AddSC_wintergrasp()
{
    new npc_wg_queue();
    new npc_wg_spirit_guide();
    new npc_wg_demolisher_engineer();
    new go_wg_vehicle_teleporter();
    new npc_wg_quest_giver();
    new achievement_wg_didnt_stand_a_chance();
}
