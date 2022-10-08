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

#include "ScriptMgr.h"
#include "ObjectMgr.h"
#include "PhasingHandler.h"
#include "GameObject.h"
#include "ScriptedGossip.h"
#include "Log.h"

enum RogueClassHall
{
    // Creatures
    NPC_RAVENHOLDT_COURIER_102018 = 102018,
    NPC_LORD_JORACH_RAVENHOLDT_101513 = 101513,
    NPC_VALEERA_SANGUINAR_98102 = 98102,
    NPC_FLEET_ADMIRAL_TETHYS_94159 = 94159,
    NPC_PRINCESS_TESS_GREYMANE_94138 = 94138,
    NPC_KILL_CREDIT_ENTER_THE_HALL_OF_SHADOWS = 102086,
    NPC_KILL_CREDIT_PASSWORD_SPOKEN = 105907,
    NPC_KILL_CREDIT_LETTER_READ = 102041,
    NPC_KILL_CREDIT_FIND_THE_UNCROWNED = 102098,
    NPC_KILL_CREDIT_ARTIFACT_WEAPON_CHOSEN = 105953,
    NPC_KILL_CREDIT_TAKE_YOUR_SEAT_01 = 102498,
    NPC_KILL_CREDIT_TAKE_YOUR_SEAT_02 = 102502,

    // Spells
    SPELL_DONT_KILL_THE_MESSENGER = 201212,
    SPELL_DELIVER_MESSAGE = 201234,
    SPELL_SEALED_LETTER = 201253,

    // Actions
    ACTION_QUEST_THE_FINAL_SHADOW_TALK_1 = 1,

    // Texts
    RAVENHOLDT_COURIER_TEXT_00 = 0,
    RAVENHOLDT_COURIER_TEXT_01 = 1,
    RED_JACK_FINDLE_TEXT_00 = 0,
    VALEERA_SANGUINAR_BCT_00 = 104737,
    VALEERA_SANGUINAR_BCT_01 = 108901,
    LORD_JORACH_RAVENHOLDT_BCT_00 = 104757,
    LORD_JORACH_RAVENHOLDT_BCT_01 = 104648,
    LORD_JORACH_RAVENHOLDT_BCT_02 = 108892,
    FLEET_ADMIRAL_TETHYS_BCT_00 = 108898,

    // Quests
    QUEST_CALL_OF_THE_UNCROWNED = 40832,
    QUEST_THE_FINAL_SHADOW = 40839,
    QUEST_A_WORTHY_BLADE = 40840,

    // Misc
    RED_JACK_FINDLE_GOSSIP_MENU = 19540,
    PLAYER_CHOICE_ROGE_SELECTION = 262
};

/// 102018
struct npc_ravenholdt_courier_102018 : public ScriptedAI
{
    npc_ravenholdt_courier_102018(Creature* creature) : ScriptedAI(creature)
    {
        sayHello = false;
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);

        if (!sayHello)
            DoCastSelf(SPELL_DONT_KILL_THE_MESSENGER);
    }

    void sQuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_CALL_OF_THE_UNCROWNED)
        {
            me->RemoveAurasDueToSpell(SPELL_DELIVER_MESSAGE);
            Talk(RAVENHOLDT_COURIER_TEXT_01, player);

            _scheduler.Schedule(Milliseconds(1000), [this](TaskContext context)
            {
                me->DisappearAndDie();
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

        me->GetMotionMaster()->MoveFollow(player, PET_FOLLOW_DIST, me->GetFollowAngle());

        if (!sayHello)
        {
            sayHello = true;
            Talk(RAVENHOLDT_COURIER_TEXT_00, player);
        }
    }

private:

    TaskScheduler _scheduler;
    bool sayHello;
};

/// 251033
class go_facade_251033 : public GameObjectScript
{
public:
    go_facade_251033() : GameObjectScript("go_facade_251033") { }

    bool OnGossipHello(Player* player, GameObject* /*go*/) override
    {
        player->KilledMonsterCredit(NPC_KILL_CREDIT_ENTER_THE_HALL_OF_SHADOWS);
        return false;
    }
};

struct npc_enter_the_hall_of_shadows_102086 : public ScriptedAI
{
    npc_enter_the_hall_of_shadows_102086(Creature* creature) : ScriptedAI(creature) { }

    void MoveInLineOfSight(Unit* who) override
    {
        if (!who || !who->IsInWorld())
            return;

        if (!me->IsWithinDist(who, 15.0f, false))
            return;

        Player* player = who->GetCharmerOrOwnerPlayerOrPlayerItself();

        if (!player)
            return;

        if (player->HasQuest(QUEST_CALL_OF_THE_UNCROWNED))
            player->KilledMonsterCredit(me->GetEntry());

        if (player->getClass() != CLASS_ROGUE)
        {
            /// @ToDo TeleTo
        }
    }
};

struct npc_red_jack_findle_97004 : public ScriptedAI
{
    npc_red_jack_findle_97004(Creature* creature) : ScriptedAI(creature) { }

    void sGossipHello(Player* player)
    {
        ClearGossipMenuFor(player);
        player->PrepareGossipMenu(me, RED_JACK_FINDLE_GOSSIP_MENU);
        SendGossipMenuFor(player, player->GetGossipTextId(me), me->GetGUID());
    }

    void sGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId)
    {
        if (player->HasQuest(QUEST_CALL_OF_THE_UNCROWNED))
        {
            if (gossipListId == 0)
            {
                Talk(RED_JACK_FINDLE_TEXT_00, player);
                player->KilledMonsterCredit(NPC_KILL_CREDIT_PASSWORD_SPOKEN);
                CloseGossipMenuFor(player);
            }
        }
    }
};

/// READ 201253
/// SPELL_CONVERSATION_QUEST_CALL_OF_THE_UNCROWNED = 201254 (1101)
class spell_provided_for_201253 : public PlayerScript
{
public:
    spell_provided_for_201253() : PlayerScript("spell_provided_for_201253") { }

    void OnUpdate(Player* player, uint32 /*diff*/)
    {
        if (player->HasAura(SPELL_SEALED_LETTER) && player->HasQuest(QUEST_CALL_OF_THE_UNCROWNED))
            player->KilledMonsterCredit(NPC_KILL_CREDIT_LETTER_READ);
    }
};

/// 246387
class go_torch_246387 : public GameObjectScript
{
public:
    go_torch_246387() : GameObjectScript("go_torch_246387") { }

    bool OnGossipHello(Player* player, GameObject* /*go*/) override
    {
        player->KilledMonsterCredit(NPC_KILL_CREDIT_FIND_THE_UNCROWNED);
        return false;
    }
};

struct npc_lord_jorach_ravenholdt_101513 : public ScriptedAI
{
    npc_lord_jorach_ravenholdt_101513(Creature* creature) : ScriptedAI(creature) { }

    void DoAction(int32 param)
    {
        switch (param)
        {
        case ACTION_QUEST_THE_FINAL_SHADOW_TALK_1:
            if (Creature* valeera_sanguinar = me->FindNearestCreature(NPC_VALEERA_SANGUINAR_98102, 15.0f))
            {
                _scheduler.Schedule(Milliseconds(1000), [valeera_sanguinar](TaskContext context)
                {
                    valeera_sanguinar->Say(VALEERA_SANGUINAR_BCT_00);
                });
            }

            _scheduler.Schedule(Milliseconds(3000), [this](TaskContext context)
            {
                me->Say(LORD_JORACH_RAVENHOLDT_BCT_00);
            });

            break; // NPC_FLEET_ADMIRAL_TETHYS_94159
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

    void sQuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_THE_FINAL_SHADOW)
        {
            /// SPELL_CONVERSATION_ 202389 ???? (1191)
            me->Say(LORD_JORACH_RAVENHOLDT_BCT_01, player);
        }

        if (quest->GetQuestId() == QUEST_A_WORTHY_BLADE)
        {
            me->Say(LORD_JORACH_RAVENHOLDT_BCT_02, player);

            if (Creature* fleet_admiral_tethys = me->FindNearestCreature(NPC_FLEET_ADMIRAL_TETHYS_94159, 25.0f))
            {
                _scheduler.Schedule(Milliseconds(2000), [fleet_admiral_tethys, player](TaskContext context)
                {
                    fleet_admiral_tethys->Say(FLEET_ADMIRAL_TETHYS_BCT_00, player);
                });
            }

            if (Creature* valeera_sanguinar = me->FindNearestCreature(NPC_VALEERA_SANGUINAR_98102, 15.0f))
            {
                _scheduler.Schedule(Milliseconds(4000), [valeera_sanguinar, player](TaskContext context)
                {
                    valeera_sanguinar->Say(VALEERA_SANGUINAR_BCT_01, player);
                });
            }
        }
    }

    void sQuestReward(Player* player, Quest const* quest, uint32 /*opt*/)  override
    {
        if (quest->GetQuestId() == QUEST_THE_FINAL_SHADOW) {}
    }

private:

    TaskScheduler _scheduler;
};

class roge_playerchoice : public PlayerScript
{
public:
    roge_playerchoice() : PlayerScript("roge_playerchoice") { }

    void OnPlayerChoiceResponse(Player* player, uint32 choiceId, uint32 responseId)
    {
        if (choiceId != PLAYER_CHOICE_ROGE_SELECTION)
            return;

        TC_LOG_ERROR("server.worldserver", "roge_playerchoice %u, %u", choiceId, responseId);

        if (player->HasQuest(QUEST_A_WORTHY_BLADE))
        {
            player->KilledMonsterCredit(NPC_KILL_CREDIT_ARTIFACT_WEAPON_CHOSEN);
        }
    }
};

struct npc_valeera_sanguinar_98102 : public ScriptedAI
{
    npc_valeera_sanguinar_98102(Creature* creature) : ScriptedAI(creature) { }

    void DoAction(int32 param)
    {
        /*switch (param)
        {
            case ACTION_RESPONSEID_1:
                break;
        }*/
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

    void sGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId)
    {
        if (player->HasQuest(QUEST_A_WORTHY_BLADE))
        {
            if (gossipListId == 0)
            {
                player->KilledMonsterCredit(NPC_VALEERA_SANGUINAR_98102);
                CloseGossipMenuFor(player);
            }
        }
    }

    void sQuestAccept(Player* player, Quest const* quest) override { }

    void sQuestReward(Player* player, Quest const* quest, uint32 /*opt*/) override { }

private:

    TaskScheduler _scheduler;
};

/// SPELL_CONVERSATION_ 202417 1192
/// 246670 chair
class go_chair_246670 : public GameObjectScript
{
public:
    go_chair_246670() : GameObjectScript("go_chair_246670") { }

    bool OnGossipHello(Player* player, GameObject* go) override
    {
        if (player->HasQuest(QUEST_THE_FINAL_SHADOW) && (!player->GetQuestObjectiveData(QUEST_THE_FINAL_SHADOW, 0)))
        {
            player->KilledMonsterCredit(NPC_KILL_CREDIT_TAKE_YOUR_SEAT_01);

            if (Creature* lord_jorach = go->FindNearestCreature(NPC_LORD_JORACH_RAVENHOLDT_101513, 15.0f))
            {
                lord_jorach->AI()->DoAction(ACTION_QUEST_THE_FINAL_SHADOW_TALK_1);
            }
        }
        else if (player->HasQuest(QUEST_THE_FINAL_SHADOW) && (player->GetQuestObjectiveData(QUEST_THE_FINAL_SHADOW, 0)))
        {
            player->KilledMonsterCredit(NPC_KILL_CREDIT_TAKE_YOUR_SEAT_02);
        }

        return false;
    }
};

struct npc_fleet_admiral_tethys_94159 : public ScriptedAI
{
    npc_fleet_admiral_tethys_94159(Creature* creature) : ScriptedAI(creature) { }

    void DoAction(int32 param)
    {
        /*switch (param)
        {
            case ACTION_RESPONSEID_1:
                break;
        }*/
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

    void sGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId)
    {
        if (player->HasQuest(QUEST_A_WORTHY_BLADE))
        {
            if (gossipListId == 0)
            {
                player->KilledMonsterCredit(NPC_FLEET_ADMIRAL_TETHYS_94159);
                CloseGossipMenuFor(player);
            }
        }
    }

    void sQuestAccept(Player* player, Quest const* quest) override { }

    void sQuestReward(Player* player, Quest const* quest, uint32 /*opt*/) override { }

private:

    TaskScheduler _scheduler;
};

struct npc_princess_tess_greymane_94138 : public ScriptedAI
{
    npc_princess_tess_greymane_94138(Creature* creature) : ScriptedAI(creature) {  }

    void DoAction(int32 param)
    {
        /*switch (param)
        {
            case ACTION_RESPONSEID_1:
                break;
        }*/
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

    void sQuestAccept(Player* player, Quest const* quest) override { }

    void sQuestReward(Player* player, Quest const* quest, uint32 /*opt*/) override { }

    void sGossipSelect(Player* player, uint32 menuId, uint32 gossipListId)
    {
        TC_LOG_ERROR("server.worldserver", "sGossipSelect %u, %u", menuId, gossipListId);

        if (player->HasQuest(QUEST_A_WORTHY_BLADE))
        {
            if (gossipListId == 0)
            {
                player->KilledMonsterCredit(NPC_PRINCESS_TESS_GREYMANE_94138);
                CloseGossipMenuFor(player);
            }
        }
    }

private:

    TaskScheduler _scheduler;
};

void AddSC_class_hall_rogue()
{
    RegisterCreatureAI(npc_ravenholdt_courier_102018);
    new go_facade_251033();
    RegisterCreatureAI(npc_enter_the_hall_of_shadows_102086);
    RegisterCreatureAI(npc_red_jack_findle_97004);
    new spell_provided_for_201253();
    new go_torch_246387();
    RegisterCreatureAI(npc_lord_jorach_ravenholdt_101513);
    RegisterCreatureAI(npc_valeera_sanguinar_98102);
    new go_chair_246670();
    RegisterCreatureAI(npc_fleet_admiral_tethys_94159);
    RegisterCreatureAI(npc_princess_tess_greymane_94138);
    new roge_playerchoice();
}
