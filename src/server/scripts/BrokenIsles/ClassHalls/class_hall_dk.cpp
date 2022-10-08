/*
* Copyright (C) 2021 BfaCore Reforged
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
#include "PhasingHandler.h"
#include "ScriptedGossip.h"
#include "GameObject.h"
#include "ObjectMgr.h"
#include "Spell.h"
#include "Log.h"

enum
{
    PLAYER_CHOICE_DK_BLOOD = 541,
    PLAYER_CHOICE_DK_FROST = 542,
    PLAYER_CHOICE_DK_UNHOLY = 543,
    SPELL_WEAPONS_OF_LEGEND_PLAYER_CHOICE = 199985,
    PLAYER_CHOICE_DK_SELECTION = 253,

    QUEST_BLOOD_CHOSEN = 40722,
    QUEST_FROST_CHOSEN = 40723,
    QUEST_UNHOLY_CHOSEN = 40724,

    QUEST_WEAPONS_OF_LEGEND = 40715,
    QUEST_ONE_MORE_LEGEND = 43973,
    QUEST_MORE_WEAPONS_OF_LEGEND = 44424,

    ///DK Quest 

    ///Blood
    QUEST_THE_DEAD_AND_THE_DAMNED = 40740,
    ///Frost
    QUEST_THE_CALL_OF_ICECROWN = 38990,
    ///Unholy   
    QUEST_APOCALYPSE = 40930,
    QUEST_FOLLOWING_THE_CURSE = 40931,
    QUEST_DISTURBING_THE_PAST = 40932,
    QUEST_A_GRISLY_TASK = 40933,
    QUEST_THE_DARK_RIDERS = 40934,
    QUEST_THE_CALL_OF_VENGEANCE = 40935,
};

struct npc_duke_lankral_101441 : public ScriptedAI
{
    npc_duke_lankral_101441(Creature* creature) : ScriptedAI(creature) { }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

    void sGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId)
    {
        CloseGossipMenuFor(player);
        player->CastSpell(player, SPELL_WEAPONS_OF_LEGEND_PLAYER_CHOICE, true);
    }

    void sQuestAccept(Player* player, Quest const* quest) override
    {
        if ((quest->GetQuestId() == QUEST_WEAPONS_OF_LEGEND) || (quest->GetQuestId() == QUEST_ONE_MORE_LEGEND) || (quest->GetQuestId() == QUEST_MORE_WEAPONS_OF_LEGEND))
        {
            player->CastSpell(player, SPELL_WEAPONS_OF_LEGEND_PLAYER_CHOICE, true);
        }
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Player* player = who->ToPlayer())
        {
            if (me->IsWithinDist(player, 15.0f, false))
                if (player->HasQuest(40714))
                    player->ForceCompleteQuest(40714);
        }
    }

private:
    TaskScheduler _scheduler;
};

class dk_playerchoice : public PlayerScript
{
public:
    dk_playerchoice() : PlayerScript("dk_playerchoice") { }

    void OnQuestStatusChange(Player* player, uint32 /*questId*/)
    {
        //if (player->getClass() == CLASS_DEATH_KNIGHT || player->getLevel() >= 98)
           // OnCheckPhase(player);
    }

    void OnPlayerChoiceResponse(Player* player, uint32 choiceId, uint32 responseId)
    {
        if (choiceId != PLAYER_CHOICE_DK_SELECTION)
            return;

        if (player->HasQuest(QUEST_WEAPONS_OF_LEGEND))
            player->KilledMonsterCredit(101441);
        if (player->HasQuest(QUEST_ONE_MORE_LEGEND))
            player->KilledMonsterCredit(112077);
        if (player->HasQuest(QUEST_MORE_WEAPONS_OF_LEGEND))
            player->KilledMonsterCredit(113814);

        switch (responseId)
        {
        case PLAYER_CHOICE_DK_BLOOD:
            if (player->GetQuestStatus(QUEST_THE_DEAD_AND_THE_DAMNED) == QUEST_STATUS_NONE)
                if (const Quest* quest_1 = sObjectMgr->GetQuestTemplate(QUEST_THE_DEAD_AND_THE_DAMNED))
                    player->AddQuest(quest_1, nullptr);
            if (Creature* duke = player->FindNearestCreature(101441, 50.0f))
                duke->Say(105157);
            break;
        case PLAYER_CHOICE_DK_FROST:
            if (player->GetQuestStatus(QUEST_THE_CALL_OF_ICECROWN) == QUEST_STATUS_NONE)
                if (const Quest* quest_2 = sObjectMgr->GetQuestTemplate(QUEST_THE_CALL_OF_ICECROWN))
                    player->AddQuest(quest_2, nullptr);
            player->SummonGameObject(246733, player->GetPositionWithDistInFront(5.0f), QuaternionData(), 60000, true);
            break;
        case PLAYER_CHOICE_DK_UNHOLY:
            if (player->GetQuestStatus(QUEST_APOCALYPSE) == QUEST_STATUS_NONE)
                if (const Quest* quest_2 = sObjectMgr->GetQuestTemplate(QUEST_APOCALYPSE))
                    player->AddQuest(quest_2, nullptr);
            break;
        default:
            break;
        }
    }

    void OnSpellCast(Player* player, Spell* spell, bool /*skipCheck*/)
    {
        if (spell->GetSpellInfo()->Id == 225224)
        {
            if (player->HasQuest(QUEST_THE_CALL_OF_ICECROWN) && player->GetQuestStatus(QUEST_THE_CALL_OF_ICECROWN) == QUEST_STATUS_INCOMPLETE)
            {
                player->CastStop();
                player->KilledMonsterCredit(93970);
                player->TeleportTo(1480, Position(-737.07f, 2204.7f, 535.67f, 0.07347836f));
            }
            if (player->HasQuest(QUEST_THE_CALL_OF_VENGEANCE) && player->GetQuestStatus(QUEST_THE_CALL_OF_VENGEANCE) == QUEST_STATUS_INCOMPLETE)
            {
                player->CastStop();
                player->KilledMonsterCredit(111886);
                player->KilledMonsterCredit(102598);
                player->KilledMonsterCredit(96125);
                player->TeleportTo(1480, Position(504.0677f, -2124.243f, 840.9485f, 5.730907f));
            }
        }
    }
};

struct npc_zeomus_102403 : public ScriptedAI
{
    npc_zeomus_102403(Creature* creature) : ScriptedAI(creature) { }

    void OnSpellClick(Unit* clicker, bool& /*result*/)
    {
        if (Player* player = clicker->ToPlayer())
        {
            if (player->HasQuest(QUEST_THE_DEAD_AND_THE_DAMNED))
            {
                player->KilledMonsterCredit(me->GetEntry());
                player->TeleportTo(1220, Position(-859.84f, 3604.6445f, 1.941741f, 1.406331f));
            }
        }
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Player* player = who->ToPlayer())
        {
            if (me->IsWithinDist(player, 15.0f, false))
                if (player->HasQuest(QUEST_THE_DEAD_AND_THE_DAMNED))
                    me->AddNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
        }
    }

};

struct npc_legion_portal_102414 : public ScriptedAI
{
    npc_legion_portal_102414(Creature* creature) : ScriptedAI(creature) { }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Player* player = who->ToPlayer())
        {
            if (me->IsWithinDist(player, 3.0f, false))
            {
                if (!IsLock && player->HasQuest(QUEST_THE_DEAD_AND_THE_DAMNED))
                {
                    IsLock = true;
                    player->KilledMonsterCredit(102414);
                    player->TeleportTo(1489, Position(234.68f, 1950.91f, -55.89f, 0.2827434f));
                }
            }
        }
    }
};

struct npc_vanessa_fairgraves_102973 : public ScriptedAI
{
    npc_vanessa_fairgraves_102973(Creature* creature) : ScriptedAI(creature) { }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Player* player = who->ToPlayer())
        {
            if (me->IsWithinDist(player, 15.0f, false) && !IsLock && player->HasQuest(QUEST_THE_DEAD_AND_THE_DAMNED))
            {
                IsLock = true;
                Talk(0);
            }
        }
    }
};

struct npc_highlord_darion_mograine_93437 : public ScriptedAI
{
    npc_highlord_darion_mograine_93437(Creature* creature) : ScriptedAI(creature) { }

    void sQuestReward(Player* player, Quest const* quest, uint32 /*opt*/)  override
    {
        if (quest->GetQuestId() == QUEST_THE_DEAD_AND_THE_DAMNED)
            player->GetSceneMgr().PlaySceneByPackageId(1472);
    }
};
//QUEST_A_GRISLY_TASK
struct npc_a_shallow_grave_102473 : public ScriptedAI
{
    npc_a_shallow_grave_102473(Creature* creature) : ScriptedAI(creature) {  }

    void Reset() override
    {
        SetCombatMovement(false);
        me->SetReactState(REACT_PASSIVE);
        me->AddUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
        me->AddUnitState(UNIT_STATE_CANNOT_TURN);
        me->SetDisplayId(328);
        DoCastSelf(202363);
        me->AddNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
    }

    void OnSpellClick(Unit* clicker, bool& /*result*/)
    {
        if (Player* player = clicker->ToPlayer())
        {
            if (player->GetQuestStatus(QUEST_A_GRISLY_TASK) == QUEST_STATUS_INCOMPLETE)
            {
                me->RemoveNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
                if (roll_chance_i(30))
                {
                    player->ForceCompleteQuest(QUEST_A_GRISLY_TASK);
                    player->SummonCreature(102459, me->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN, 0, 0, true);
                }
                else
                {
                    if (Creature* mob = player->SummonCreature(102459, me->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN, 0, 0, true))
                        mob->Say(104853);
                }

                me->DespawnOrUnsummon(1000);
            }
        }
    }
};

struct npc_laith_sha_ol_102459 : public ScriptedAI
{
    npc_laith_sha_ol_102459(Creature* creature) : ScriptedAI(creature) { }

    void JustDied(Unit* /*killer*/) override
    {
        me->Say(104739);
        me->SummonCreature(102522, me->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN);
    }

    enum laith_sha_ol_Spells
    {
        SPELL_ARCANE_BURST = 204933,
        SPELL_ARCANE_FURY = 204935,
    };

    void EnterCombat(Unit* /*attacker*/) override
    {
        me->Say(104738);
        events.ScheduleEvent(SPELL_ARCANE_BURST, 5s);
        events.ScheduleEvent(SPELL_ARCANE_FURY, 10s);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;
        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;
        events.Update(diff);
        switch (events.ExecuteEvent())
        {
        case SPELL_ARCANE_BURST:
        {
            DoCast(SPELL_ARCANE_BURST);
            events.Repeat(5s);
            break;
        }
        case SPELL_ARCANE_FURY:
        {
            DoCast(SPELL_ARCANE_FURY);
            events.Repeat(10s);
            break;
        }
        }
        DoMeleeAttackIfReady();
    }
};

struct npc_laith_sha_ol_102522 : public ScriptedAI
{
    npc_laith_sha_ol_102522(Creature* creature) : ScriptedAI(creature) {  }

    void Reset() override
    {
        SetCombatMovement(false);
        me->SetReactState(REACT_PASSIVE);
        me->SetDisableGravity(true);

       /* _sceneHelper.Clear();
        _sceneHelper.SetDefaultActorGuid(me->GetGUID());
        _sceneHelper.AddSceneActionSay(104740, 500);
        _sceneHelper.AddSceneActionSay(104741, 5000);
        _sceneHelper.AddSceneActionDespawn(1000);
        _sceneHelper.Activate();*/
    }
};
void AddSC_class_hall_dk()
{
    RegisterCreatureAI(npc_duke_lankral_101441);
    new dk_playerchoice();
    RegisterCreatureAI(npc_zeomus_102403);
    RegisterCreatureAI(npc_legion_portal_102414);
    RegisterCreatureAI(npc_vanessa_fairgraves_102973);
    RegisterCreatureAI(npc_highlord_darion_mograine_93437);
    RegisterCreatureAI(npc_a_shallow_grave_102473);
    RegisterCreatureAI(npc_laith_sha_ol_102459);
    RegisterCreatureAI(npc_laith_sha_ol_102522);
}

