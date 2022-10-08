/*
 * Copyright (C) 2022 BfaCore Reforged
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "Conversation.h"
#include "ScriptMgr.h"
#include "ObjectMgr.h"
#include "PhasingHandler.h"
#include "GameObject.h"
#include "ScriptedGossip.h"
#include "Log.h"

enum
{
    PLAYER_CHOICE_MAGE_SELECTION = 265,

    NPC_MERYL_FELSTORM_102700 = 102700,
    NPC_ALODI_102846 = 102846,

    QUEST_FELSTORMS_PLEA = 41035, /// after quest 44184 In the Blink of an Eye complete
    QUEST_THE_DREADLORDS_PRIZE = 41036,
    QUEST_A_MAGES_WEAPON = 41085,
    QUEST_FINDING_BONCHILL = 42452,
    PHASE_2 = 5985,
    PHASE_3 = 6543,

    CONVERSATION_FELSTORMS_PLEA = 1264,
    CONVERSATION_THE_DREADLORDS_PRIZE = 3364,
    CONVERSATION_THE_DREADLORDS_PRIZE_THIRD = 1281,
    PATH_THE_DREADLORDS_PRIZE = 4471540,
    MOVE_TO_POSITION = 15,
    SPELL_TELE_TO_THE_DREADLORDS_PRIZE = 203241, ///ID - 203241 TELEPORT_TO_LFG_DUNGEON EffectMiscValueA = 1276 EffectMiscValueB = 1187 Location: X: 1276.16 Y: -263.27 Z: 44.36 Orientation: 6.275331 MapID: 1494

    EVENT_TALK_1 = 1,
    EVENET_TELE_TO_LFG_DUNGENON = 2,
    EVENT_BACK_HOME_1 = 3,
    EVENT_THE_DREADLORDS_PRIZE_LAST_TALK = 4,

    ACTION_RESPONSEID_1 = 584, //Arcane
    ACTION_RESPONSEID_2 = 585, //Fire
    ACTION_RESPONSEID_3 = 586, //Frost
};

struct npc_meryl_felstorm_102700 : public ScriptedAI
{
    npc_meryl_felstorm_102700(Creature* creature) : ScriptedAI(creature) { Initialize(); }

    void Initialize()
    {
        m_playerGUID = ObjectGuid::Empty;
        playerChoiceID = 0;
    }

    void AddPlayer()
    {
        if (!HasPlayer(m_playerGUID))
            pList.insert(m_playerGUID);
    }

    bool HasPlayer(ObjectGuid guid)
    {
        return (pList.find(guid) != pList.end());
    }

    void RemovePlayer()
    {
        if (HasPlayer(m_playerGUID))
            pList.erase(m_playerGUID);
        m_playerGUID = ObjectGuid::Empty;
    }

    ///107589
    void sGossipHello(Player* player)
    {

        if (player->HasQuest(QUEST_FINDING_BONCHILL) && (player->GetQuestObjectiveData(QUEST_FINDING_BONCHILL, 0)) && !player->GetQuestObjectiveData(QUEST_FINDING_BONCHILL, 6))
        {

            //menu (19321, 0, 0, 'Tell Merrill about the information you found.', 0),
            ClearGossipMenuFor(player);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Tell Merrill about the information you found.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
            SendGossipMenuFor(player, player->GetGossipTextId(me), me->GetGUID());
        }
        else
        {
            ClearGossipMenuFor(player);
            if (me->IsQuestGiver())
                player->PrepareQuestMenu(me->GetGUID()); /* return true*/
            SendGossipMenuFor(player, player->GetGossipTextId(me), me->GetGUID());
        }
    }

    void sGossipSelect(Player* player, uint32 /*menuId*/, uint32 /*gossipListId*/)
    {
        CloseGossipMenuFor(player);
        if (player->HasQuest(QUEST_FINDING_BONCHILL) && (player->GetQuestObjectiveData(QUEST_FINDING_BONCHILL, 0)) && !player->GetQuestObjectiveData(QUEST_FINDING_BONCHILL, 6))
        {
            me->Say(112317, player);

            if (Creature* alodi = me->FindNearestCreature(NPC_ALODI_102846, 15.0f))
            {
                alodi->GetScheduler().Schedule(Milliseconds(2000), [player](TaskContext context)
                {
                    GetContextCreature()->Say(112318, player);
                });
                alodi->GetScheduler().Schedule(Milliseconds(11000), [player](TaskContext context)
                {
                    GetContextCreature()->Say(112328, player);
                    player->KilledMonsterCredit(107589);
                });
            }
            me->GetScheduler().Schedule(Milliseconds(5000), [player](TaskContext context)
            {
                GetContextCreature()->Say(112326, player);
            });
            me->GetScheduler().Schedule(Milliseconds(9000), [player](TaskContext context)
            {
                GetContextCreature()->Say(112327, player);
            });
        }
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (!who || !who->IsInWorld())
            return;
        Player* player = who->GetCharmerOrOwnerPlayerOrPlayerItself();
        if (!player)
            return;

        if (!me->IsWithinDist(who, 20.0f, false))
        {
            RemovePlayer();
            return;
        }

        if (!HasPlayer(player->GetGUID()) && (player->HasQuest(QUEST_FELSTORMS_PLEA)))
        {
            m_playerGUID = player->GetGUID();
            AddPlayer();
            Conversation::CreateConversation(CONVERSATION_FELSTORMS_PLEA, player, player->GetPosition(), { player->GetGUID() });
            player->ForceCompleteQuest(QUEST_FELSTORMS_PLEA);
        }

        if (!HasPlayer(player->GetGUID()) && (player->HasQuest(QUEST_THE_DREADLORDS_PRIZE)) && (!player->GetQuestObjectiveData(QUEST_THE_DREADLORDS_PRIZE, 0)))
        {
            m_playerGUID = player->GetGUID();
            AddPlayer();
            Conversation::CreateConversation(CONVERSATION_THE_DREADLORDS_PRIZE, player, player->GetPosition(), { player->GetGUID() });
        }
        ///conversation 1281 ?????!???? ?????
        if (!HasPlayer(player->GetGUID()) && (player->HasQuest(QUEST_THE_DREADLORDS_PRIZE)) && (player->GetQuestObjectiveData(QUEST_THE_DREADLORDS_PRIZE, 0)) && (!player->GetQuestObjectiveData(QUEST_THE_DREADLORDS_PRIZE, 2)))
        {
            TC_LOG_ERROR("server.worldserver", "conversation 1281 ");
            m_playerGUID = player->GetGUID();
            AddPlayer();

            events.ScheduleEvent(EVENT_THE_DREADLORDS_PRIZE_LAST_TALK, 1000);
        }

    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type == POINT_MOTION_TYPE)
            switch (id)
            {
            case MOVE_TO_POSITION:
            {
                events.ScheduleEvent(EVENT_TALK_1, 500);
                break;
            }

            }
    }

    void sQuestAccept(Player* player, Quest const* quest)
    {
        if (quest->GetQuestId() == QUEST_THE_DREADLORDS_PRIZE)
        {
            m_playerGUID = player->GetGUID();
            Conversation::CreateConversation(CONVERSATION_THE_DREADLORDS_PRIZE, player, player->GetPosition(), { player->GetGUID() });
            //PATH
            me->SetSpeed(MOVE_RUN, 1.8f);
            me->GetMotionMaster()->MovePath(PATH_THE_DREADLORDS_PRIZE, false);

            events.ScheduleEvent(EVENT_TALK_1, 10000);
            player->AddConversationDelayedTeleport(14000, CONVERSATION_THE_DREADLORDS_PRIZE, 1494, 1276.16f, -263.27f, 44.36f, 6.275331f);
            ///X: 1276.16 Y: -263.27 Z: 44.36 Orientation: 6.275331 MapID: 1494
        }
        if (quest->GetQuestId() == QUEST_FINDING_BONCHILL)
        {
            Talk(1, player);
            DoCastSelf(226016, true);
            PhasingHandler::AddPhase(player, PHASE_2);
            PhasingHandler::AddPhase(player, PHASE_3);
        }
    }

    void sQuestReward(Player* player, Quest const* quest, uint32 /*opt*/)
    {
        if (quest->GetQuestId() == QUEST_A_MAGES_WEAPON)
        {
            if (playerChoiceID)
            {
                switch (playerChoiceID)
                {
                case ACTION_RESPONSEID_1:
                    break;
                case ACTION_RESPONSEID_2:
                    break;
                case ACTION_RESPONSEID_3:
                    if (const Quest* quest_3 = sObjectMgr->GetQuestTemplate(QUEST_FINDING_BONCHILL))
                    {
                        player->AddQuest(quest_3, me);
                        Talk(1, player);
                        DoCastSelf(226016, true);
                        PhasingHandler::AddPhase(player, PHASE_2);
                        PhasingHandler::AddPhase(player, PHASE_3);
                    }
                    break;
                default:
                    break;
                }
            }
        }
    }

    ///ACTION_RESPONSEID_1
    void DoAction(int32 param)
    {
        switch (param)
        {
        case ACTION_RESPONSEID_1:
        case ACTION_RESPONSEID_2:
        case ACTION_RESPONSEID_3:
            playerChoiceID = param;
            break;
        default:
            break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        events.Update(diff);

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_TALK_1:
            {
                TC_LOG_ERROR("server.worldserver", "EVENT_TALK_1");
                Talk(0);
                events.ScheduleEvent(EVENET_TELE_TO_LFG_DUNGENON, 2000);
                break;
            }
            case EVENET_TELE_TO_LFG_DUNGENON:
            {
                TC_LOG_ERROR("server.worldserver", "EVENET_TELE_TO_LFG_DUNGENON");
                if (Player* player = ObjectAccessor::GetPlayer(*me, m_playerGUID))
                    DoCast(player, 130, true);///SPELL_TELE_TO_THE_DREADLORDS_PRIZE
            }
            case EVENT_BACK_HOME_1:
            {
                TC_LOG_ERROR("server.worldserver", "EVENT_BACK_HOME_1");
                me->NearTeleportTo(me->GetHomePosition(), false);
                me->KillSelf();
                me->Respawn();
                me->GetMotionMaster()->MoveTargetedHome();
                break;
            }
            case EVENT_THE_DREADLORDS_PRIZE_LAST_TALK:

                if (Player* player = ObjectAccessor::GetPlayer(*me, m_playerGUID))
                {
                    if (Creature* alodi = me->FindNearestCreature(NPC_ALODI_102846, 25.0f))
                    {
                        alodi->Say(105437, player);
                        alodi->GetScheduler().Schedule(Milliseconds(5000), [player](TaskContext context)
                        {
                            GetContextCreature()->Say(105440, player);
                        });
                    }
                    me->GetScheduler().Schedule(Milliseconds(1000), [player](TaskContext context)
                    {
                        GetContextCreature()->Say(105438, player);
                    });
                    me->GetScheduler().Schedule(Milliseconds(3000), [player](TaskContext context)
                    {
                        GetContextCreature()->Say(105439, player);
                        GetContextCreature()->CastSpell(GetContextCreature(), 133464, true);
                    });

                    me->GetScheduler().Schedule(Milliseconds(7000), [player](TaskContext context)
                    {
                        GetContextCreature()->Say(105441, player);
                    });
                    me->GetScheduler().Schedule(Milliseconds(9000), [player](TaskContext context)
                    {
                        GetContextCreature()->Say(105442, player);
                        player->KilledMonsterCredit(103032);
                    });
                }


                break;
            }
        }
    }
private:
    EventMap events;
    std::set<ObjectGuid> pList;
    ObjectGuid   m_playerGUID;
    uint32 playerChoiceID;
};

class mage_playerchoice : public PlayerScript
{
public:
    mage_playerchoice() : PlayerScript("mage_playerchoice") { }

    void OnPlayerChoiceResponse(Player* player, uint32 choiceId, uint32 responseId)
    {
        if (choiceId != PLAYER_CHOICE_MAGE_SELECTION)
            return;

        TC_LOG_ERROR("server.worldserver", "mage_playerchoice %u, %u", choiceId, responseId);
        if (player->HasQuest(QUEST_A_MAGES_WEAPON))
        {

            player->KilledMonsterCredit(103037);
            if (Creature* meryl = player->FindNearestCreature(NPC_MERYL_FELSTORM_102700, 100.0f))
            {
                meryl->AI()->DoAction(responseId);
            }
        }

    }
};

/*QUEST_FINDING_BONCHILL*/
class go_finding_bonchill_note : public GameObjectScript
{
public:
    go_finding_bonchill_note() : GameObjectScript("go_finding_bonchill_note") { }

    bool OnGossipHello(Player* player, GameObject* go) override
    {
        ///TC_LOG_ERROR("server.worldserver", "go_finding_bonchill_note %u", go->GetEntry());
        if (!player->GetQuestObjectiveData(QUEST_FINDING_BONCHILL, 0))
        {
            switch (go->GetEntry())
            {
            case 250549:
            case 250545:
            case 250542:
                player->KilledMonsterCredit(107586); // QUEST_FINDING_BONCHILL storageIndex 0 KillCredit
                break;
            default:
                break;
            }
            player->KilledMonsterCredit(go->GetEntry()); // QUEST_FINDING_BONCHILL storageIndex 1 KillCredit
        }
        return false;
    }
};

void AddSC_class_hall_mage()
{
    RegisterCreatureAI(npc_meryl_felstorm_102700);
    new mage_playerchoice();
    new go_finding_bonchill_note();
}
