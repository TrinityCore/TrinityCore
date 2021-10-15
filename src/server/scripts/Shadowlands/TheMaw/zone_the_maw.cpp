/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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
#include "GameObject.h"
#include "Player.h"
#include "ObjectAccessor.h"
#include "PassiveAI.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "TaskScheduler.h"
#include "TemporarySummon.h"
#include "GameObjectAI.h"
#include "Common.h"

enum TheMaw
{
	QUEST_A_FRACTURED_BLADE = 59752,
    QUEST_RUINERS_END = 59753,
    QUEST_FEAR_TO_TREAD = 59914,
    QUEST_ON_BLACKENED_WINGS = 59754,
    QUEST_SPEAKING_TO_THE_DEAD = 59758,
    SPELL_DOMINATING = 345180,
    QUEST_THE_LIONS_CAGE = 59759,
    QUEST_FIELD_SEANCE = 59757,
    QUEST_THE_AFFLICTORS_KEY = 59760,
    QUEST_AN_UNDESERVED_FATE = 59761,
};

//166963
struct npc_knight_of_the_ebon_blade_166963 : public ScriptedAI
{
    npc_knight_of_the_ebon_blade_166963(Creature* creature) : ScriptedAI(creature) { }

    void OnSpellClick(Unit* clicker, bool& /*result*/)
    {
        if (Player* player = clicker->ToPlayer())
        {
            if (player->GetQuestStatus(QUEST_A_FRACTURED_BLADE) == QUEST_STATUS_INCOMPLETE)
            {
                clicker->ToPlayer()->KilledMonsterCredit(166605);
               // me->RemoveNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
                _scheduler.Schedule(1500ms, [this, player](TaskContext /*context*/)
                {
                    if (me && player)
                    {
                        me->ForcedDespawn(100, 15s);
                        player->KilledMonsterCredit(166605);
                    }
                });
            }
        }
    }
private:
    TaskScheduler _scheduler;
    std::unordered_set<uint32> _randomEmotes;
};


//165918
struct npc_highlord_darion_mograine_165918 : public ScriptedAI
{
    npc_highlord_darion_mograine_165918(Creature* creature) : ScriptedAI(creature) { }

    void MoveInLineOfSight(Unit* target) override
    {
        if (!target->IsPlayer())
            return;

        if (target->GetDistance2d(me) <= 5.0f) 
            if (Player* player = target->ToPlayer())
                if (player->GetQuestStatus(QUEST_RUINERS_END) == QUEST_STATUS_INCOMPLETE)
                    player->KilledMonsterCredit(165918);
    }
};

//171423
struct npc_dnt_credit_first_clue : public ScriptedAI
{
    npc_dnt_credit_first_clue(Creature* creature) : ScriptedAI(creature) { }

    void MoveInLineOfSight(Unit* target) override
    {
        if (!target->IsPlayer())
            return;

        if (target->GetDistance2d(me) <= 10.0f) 
            if (Player* player = target->ToPlayer())
              //  if (!player->GetQuestObjectiveData(QUEST_FEAR_TO_TREAD, 5))
                    player->KilledMonsterCredit(171423);
    }
};

//171424
struct npc_dnt_credit_second_clue : public ScriptedAI
{
    npc_dnt_credit_second_clue(Creature* creature) : ScriptedAI(creature) { }

    void MoveInLineOfSight(Unit* target) override
    {
        if (!target->IsPlayer())
            return;

        if (target->GetDistance2d(me) <= 10.0f) 
            if (Player* player = target->ToPlayer())
              //  if (!player->GetQuestObjectiveData(QUEST_FEAR_TO_TREAD, 6))
                    player->KilledMonsterCredit(171424);
    }
};

//171425
struct npc_dnt_credit_third_clue : public ScriptedAI
{
    npc_dnt_credit_third_clue(Creature* creature) : ScriptedAI(creature) { }

    void MoveInLineOfSight(Unit* target) override
    {
        if (!target->IsPlayer())
            return;

        if (target->GetDistance2d(me) <= 15.0f) 
            if (Player* player = target->ToPlayer())
                //if (!player->GetQuestObjectiveData(QUEST_FEAR_TO_TREAD, 7))
                    player->KilledMonsterCredit(171425);
    }
};

//166980
struct npc_lady_jaina_proudmoore_166980 : public ScriptedAI
{
    npc_lady_jaina_proudmoore_166980(Creature* creature) : ScriptedAI(creature) { }

    void MoveInLineOfSight(Unit* target) override
    {
        if (!target->IsPlayer())
            return;

        if (target->GetDistance2d(me) <= 15.0f) 
            if (Player* player = target->ToPlayer())
               // if (!player->GetQuestObjectiveData(QUEST_FEAR_TO_TREAD, 0))
                    player->KilledMonsterCredit(166980);

        if (target->GetDistance2d(me) <= 15.0f) 
            if (Player* player = target->ToPlayer())
               // if (!player->GetQuestObjectiveData(QUEST_THE_LIONS_CAGE, 0))            
                    player->KilledMonsterCredit(167833);
    }

    bool GossipSelect(Player* player, uint32 /*menuId*/, uint32 /*gossipListId*/) override
    {
        //if (!player->GetQuestObjectiveData(QUEST_THE_LIONS_CAGE, 2))
            player->KilledMonsterCredit(166980);

        return true;
    }

    void QuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_ON_BLACKENED_WINGS)
        {
            _scheduler.Schedule(15s, [this, player](TaskContext /*context*/)
            {
                if (me && player)
                {
                    player->KilledMonsterCredit(166980);
                    //player->GetSceneMgr().PlaySceneByPackageId2(2814);
                }                
            });
        }
    };
private:
    TaskScheduler _scheduler;
    std::unordered_set<uint32> _randomEmotes;
};

//326260
struct spell_dominating : public SpellScript
{
    PrepareSpellScript(spell_dominating);

    void HandleAfterCast()
    {
        if (!GetCaster())
            return;

        if (Player* player = GetCaster()->ToPlayer())
            if (player->GetQuestStatus(QUEST_FIELD_SEANCE) == QUEST_STATUS_INCOMPLETE)
                if (Unit* GetTarget = player->GetSelectedUnit())                    
                    if (Creature* creTarget = GetTarget->ToCreature())
                        if (creTarget->GetEntry() == 165909)
                        {
                            creTarget->ForcedDespawn(100, 15s);
                            player->KilledMonsterCredit(168009);
                        }
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_dominating::HandleAfterCast);
    }
};

//345180
struct spell_dominating_2 : public SpellScript
{
    PrepareSpellScript(spell_dominating_2);

    void HandleAfterCast()
    {
        if (!GetCaster())
            return;

        if (Player* player = GetCaster()->ToPlayer())
            if (player->GetQuestStatus(QUEST_SPEAKING_TO_THE_DEAD) == QUEST_STATUS_INCOMPLETE)
                if (Unit* GetTarget = player->GetSelectedUnit())                    
                    if (Creature* creTarget = GetTarget->ToCreature())
                        if (creTarget->GetEntry() == 165976 && creTarget->HealthBelowPct(20))
                            player->KilledMonsterCredit(168009);
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_dominating_2::HandleAfterCast);
    }
};

//167961
struct npc_dnt_credit_tremaculum : public ScriptedAI
{
    npc_dnt_credit_tremaculum(Creature* creature) : ScriptedAI(creature) { }

    void MoveInLineOfSight(Unit* target) override
    {
        if (!target->IsPlayer())
            return;

        if (target->GetDistance2d(me) <= 5.0f)
            if (Player* player = target->ToPlayer())
                //if (!player->GetQuestObjectiveData(QUEST_THE_LIONS_CAGE, 1))
                {
                    player->KilledMonsterCredit(167961);
                    player->NearTeleportTo(5214.227f, 7500.833f, 4895.500f, 0.741f, false);
                }
    }
};

//364374
struct go_portal_to_torghast : public GameObjectAI
{
    go_portal_to_torghast(GameObject* go) : GameObjectAI(go) { }

    void Reset() override
    {
       // me->GetScheduler().CancelAll();
        _scheduler.Schedule(1s, [this](TaskContext context)
        {
            std::list<Player*> playerList;
            me->GetPlayerListInGrid(playerList, 3.0f);
            if (playerList.empty())
                return;

            for (Player* players : playerList)
            {
                if (players->getLevel() == 60)
                    players->TeleportTo(2162, 1646.942f, 2315.244f, 383.060f, 4.733f);
            }

            if (me->IsInWorld())
                context.Repeat(3s);
        });
    }
private:
    TaskScheduler _scheduler;
    std::unordered_set<uint32> _randomEmotes;
};

//Mawforged Lock  351722
struct go_mawforged_lock : public GameObjectAI
{
    go_mawforged_lock(GameObject* go) : GameObjectAI(go) { }

    bool GossipHello(Player* player) override
    {
        if (player->GetQuestStatus(QUEST_THE_AFFLICTORS_KEY) == QUEST_STATUS_INCOMPLETE)
            player->ForceCompleteQuest(QUEST_THE_AFFLICTORS_KEY);

        return true;
    }
};

//Mawsteel cage 351761
struct go_mawsteel_cage : public GameObjectAI
{
    go_mawsteel_cage(GameObject* go) : GameObjectAI(go) { }

    bool GossipHello(Player* player) override
    {
        if (player->GetQuestStatus(QUEST_AN_UNDESERVED_FATE) == QUEST_STATUS_INCOMPLETE)
            player->ForceCompleteQuest(QUEST_AN_UNDESERVED_FATE);

        return true;
    }
};

void AddSC_zone_the_maw()
{
    RegisterCreatureAI(npc_knight_of_the_ebon_blade_166963);
    RegisterCreatureAI(npc_highlord_darion_mograine_165918);
    RegisterCreatureAI(npc_dnt_credit_first_clue);
    RegisterCreatureAI(npc_dnt_credit_second_clue);
    RegisterCreatureAI(npc_dnt_credit_third_clue);
    RegisterCreatureAI(npc_lady_jaina_proudmoore_166980);
    RegisterSpellScript(spell_dominating);
    RegisterCreatureAI(npc_dnt_credit_tremaculum);
    RegisterGameObjectAI(go_portal_to_torghast);
    RegisterGameObjectAI(go_mawforged_lock);
    RegisterGameObjectAI(go_mawsteel_cage);
}
