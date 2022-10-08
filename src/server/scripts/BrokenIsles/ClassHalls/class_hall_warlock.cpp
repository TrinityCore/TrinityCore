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
#include "PhasingHandler.h"
#include "ScriptedGossip.h"
#include "SceneHelper.h"
#include "GameObject.h"
#include "ObjectMgr.h"
#include "Log.h"
#include "Spell.h"

enum
{
    SPELL_PLAYER_CHOICE_WARLOCK = 199411,
    PLAYER_CHOICE_WARLOCK_AFFLICTION = 523,
    PLAYER_CHOICE_WARLOCK_DEMONOLOGY = 524,
    PLAYER_CHOICE_WARLOCK_DESTRUCTION = 525,
    PLAYER_CHOICE_WARLOCK_SELECTION = 245,

    QUEST_AFFLICTION_CHOSEN = 40686,
    QUEST_DESTRUCTION_CHOSEN = 40687,
    QUEST_DEMONOLOGY_CHOSEN = 40688,

    ///WARLOCK Quest 
    NPC_RITSSYN_FLAMESCOWL_103506 = 103506,
    QUEST_THE_SIXTH = 40716,
    QUEST_THE_NEW_BLOOD = 40729,

    QUEST_THE_TOME_OF_BLIGHTED_IMPLEMENTS = 40684,
    QUEST_THE_TOME_OPENS_AGAIN = 43984,
    QUEST_A_GREATER_ARSENAL = 44089,
    ///AFFLICTION
    QUEST_TRACKING_DOWN_UTHALESH = 42939,
    QUEST_ULTHALESH_THE_DEADWIND_HARVESTER = 40495,
    ///DEMONOLOGY
    QUEST_RITUAL_REAGENTS = 42128,
    QUEST_LOOKING_INTO_THE_DARKNESS = 42168,
    QUEST_DARK_WHISPERS = 42125,
    ///DESTRUCTION
    QUEST_FINDING_THE_SCEPTER = 43100,
    QUEST_AN_EYE_FOR_A_SCEPTER = 43153,
    QUEST_RITUAL_RUINATION = 43254,

    QUEST_THE_HEART_OF_THE_DREADSCAR = 40731,
    QUEST_REBUILDING_THE_COUNCIL = 40823,
};

struct npc_ritssyn_flamescowl_103506 : public ScriptedAI
{
    npc_ritssyn_flamescowl_103506(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        ObjectGuid charmerOrOwnerGuid = me->GetCharmerOrOwnerGUID();

        if (!charmerOrOwnerGuid)
            if (TempSummon* tempSummon = me->ToTempSummon())
                if (Unit* summoner = tempSummon->GetSummoner())
                    charmerOrOwnerGuid = summoner->GetGUID();

        if (!charmerOrOwnerGuid)
            charmerOrOwnerGuid = me->GetCreatorGUID();

        if (Unit* owner = ObjectAccessor::GetUnit(*me, charmerOrOwnerGuid))
        {
            me->GetMotionMaster()->MoveFollow(owner, PET_FOLLOW_DIST, me->GetFollowAngle());
            Talk(0, owner);
        }
    }

    void sQuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_THE_SIXTH)
        {
            me->Say(104179, player);
            me->DespawnOrUnsummon(5000);
        }
    }
};

class quest_phase_for_warlock : public PlayerScript {
public:
    quest_phase_for_warlock() : PlayerScript("quest_phase_for_warlock") { }
    /*
    void OnMapChanged(Player* player)
    {
        OnCheckPhase(player);
    }
    void OnUpdateArea(Player* player, Area* newArea, Area* oldArea)
    {
        OnCheckPhase(player);
    }
    */
    void OnQuestStatusChange(Player* player, uint32 /*questId*/)
    {
        if (player->getClass() == CLASS_WARLOCK || player->getLevel() >= 98)
            OnCheckPhase(player);
    }

    void OnCheckPhase(Player* player)
    {
        if (player->getClass() != CLASS_WARLOCK)
            return;
        if (player->HasQuest(QUEST_THE_SIXTH) && player->GetAreaId() == 7594)
            PhasingHandler::AddPhase(player, 5646, true);

        if (player->HasQuest(QUEST_THE_NEW_BLOOD) && player->GetQuestStatus(QUEST_THE_NEW_BLOOD) == QUEST_STATUS_INCOMPLETE && player->GetAreaId() == 7594)
            PhasingHandler::AddPhase(player, 5646, true);

        if ((player->GetQuestStatus(QUEST_THE_NEW_BLOOD) == QUEST_STATUS_COMPLETE || player->GetQuestStatus(QUEST_THE_NEW_BLOOD) == QUEST_STATUS_REWARDED) && player->GetAreaId() == 7594)
            PhasingHandler::AddPhase(player, 6230, true);

        if (player->HasQuest(QUEST_FINDING_THE_SCEPTER) && player->GetAreaId() == 2298)
        {
            PhasingHandler::AddPhase(player, 6936, true);
            player->KilledMonsterCredit(102394);
            player->KilledMonsterCredit(109659);
        }
        if (player->HasQuest(QUEST_AN_EYE_FOR_A_SCEPTER) && player->GetAreaId() == 2298)
        {
            PhasingHandler::AddPhase(player, 6936, true);
            PhasingHandler::AddPhase(player, 6938, true);
        }
    }

    void OnSuccessfulSpellCast(Player* player, Spell* spell)
    {
        if (spell->GetSpellInfo()->Id == 219920)
        {
            if (GameObject* go = player->FindNearestGameObject(252046, 20.0f))
                go->Delete();
            if (Creature* weapon = player->FindNearestCreature(110561, 20.0f))
                weapon->DespawnOrUnsummon();
        }

    }
};

struct npc_ritssyn_flamescowl_101456 : public ScriptedAI
{
    npc_ritssyn_flamescowl_101456(Creature* creature) : ScriptedAI(creature) { Initialize(); }

    void DoAction(int32 param)
    {
        switch (param)
        {
        case 1:
            break;
        }
    }

    void UpdateAI(uint32 diff) override
    {

        if (Player* player = ObjectAccessor::GetPlayer(*me, m_playerGUID))
        {
            me->GetScheduler().Schedule(Milliseconds(1000), [player](TaskContext context)
            {
                GetContextCreature()->Say(105438, player);
            });
        }
        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }

    void sQuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_THE_NEW_BLOOD)
        {
            //101456 FaceDirection: 3.508112
            me->Say(103743);
            me->GetMotionMaster()->MovePoint(1, Position(-851.656f, 4448.82f, 696.0333f), true);
            me->GetScheduler().Schedule(Milliseconds(3000), [](TaskContext context)
            {
                GetContextCreature()->Say(103744);
            });
            //101457 
            if (Creature* npc = me->FindNearestCreature(101457, 50.0f, true))
                npc->GetMotionMaster()->MovePoint(1, Position(-867.946f, 4456.87f, 696.0369f), true);
            //101454 
            if (Creature* npc = me->FindNearestCreature(101454, 20.0f, true))
                npc->GetMotionMaster()->MovePoint(1, Position(-851.984f, 4443.61f, 696.0237f), true);
            //98797 ->summon 111468 X: -834.566 Y: 4414.436 Z: 716.7865
            if (Creature* npc = me->FindNearestCreature(98797, 20.0f, true))
            {
                npc->GetMotionMaster()->MovePoint(1, Position(-853.74f, 4452.87f, 696.0456f), true);
                npc->GetScheduler().Schedule(Milliseconds(5000), [](TaskContext context)
                {
                    GetContextCreature()->Say(103745);
                });
                npc->GetScheduler().Schedule(Milliseconds(7000), [](TaskContext context)
                {
                    GetContextCreature()->Say(103746);
                    GetContextCreature()->CastSpell(GetContextCreature(), 199952, true);

                });
                npc->GetScheduler().Schedule(Milliseconds(9000), [player](TaskContext context)
                {
                    if (Creature* door = player->GetSummonedCreatureByEntry(101433))
                        door->DespawnOrUnsummon();
                    player->SummonCreature(101433, Position(-868.9045f, 4438.607f, 696.7223f, 0.8927315f));
                    GetContextCreature()->Say(103747);

                    ///summon door //door 101433 delay 9000 cast 222203
                    if (Creature* door = player->GetSummonedCreatureByEntry(101433))
                    {
                        ///door->CastSpell(door, 222203, true);
                        door->CastSpell(player, 187114, true);
                        if (!door->HasNpcFlag(UNIT_NPC_FLAG_SPELLCLICK))
                            door->AddNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
                    }

                });

            }

            //101455 ->summon 111466
            if (Creature* npc = me->FindNearestCreature(101455, 50.0f, true))
            {
                npc->GetMotionMaster()->MovePoint(1, Position(-862.42f, 4457.42f, 696.0723f), true);
                npc->GetScheduler().Schedule(Milliseconds(11000), [](TaskContext context)
                {
                    GetContextCreature()->Say(103748);
                });
                npc->GetScheduler().Schedule(Milliseconds(13000), [player](TaskContext context)
                {
                    GetContextCreature()->Say(103749);
                    if (Creature* door = player->GetSummonedCreatureByEntry(101433))
                        if (door->HasUnitFlag(UNIT_FLAG_NOT_SELECTABLE))
                            door->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                });
                //underbelly-guard 111458 cast 217977
            }

            //101433 cast 187114 on player
        //after player cast 101433 SPELL_CLICK 199967

        }
    }

    void sQuestReward(Player* player, Quest const* quest, uint32 /*opt*/)  override
    {
        // if (quest->GetQuestId() == QUEST_WITNESS_TO_THE_WOUND)
        // {

        // }
    }
    void Initialize()
    {

    }


    void MoveInLineOfSight(Unit* who) override
    {
        if (!who || !who->IsInWorld())
            return;
        if (!me->IsWithinDist(who, 15.0f, false))
        {

            return;
        }
        Player* player = who->GetCharmerOrOwnerPlayerOrPlayerItself();
        if (!player)
            return;

    }
private:

    std::set<ObjectGuid> pList;
    ObjectGuid   m_playerGUID;
};

struct npc_summoning_portal_101433 : public ScriptedAI
{
    npc_summoning_portal_101433(Creature* creature) : ScriptedAI(creature) { }


    void DoAction(int32 param)
    {
        switch (param)
        {
        case 1:



            break;
        }
    }

    void OnSpellClick(Unit* clicker, bool& /*result*/)
    {
        if (Player* player = clicker->ToPlayer())
        {
            //199966 199967
            //199989->199967,199971
            //212062->199967,204833    
            player->CastSpell(player, 199966, true);

            //delay player->CastSpell(player, 199966, true);
            //101455,101456,101457,98797 cast 199971
            //101454  199971
            /*
            if (Creature* npc = player->FindNearestCreature(101455, 50.0f, true))
                npc->CastSpell(me, 199971, true);
            if (Creature* npc = player->FindNearestCreature(101456, 50.0f, true))
                npc->CastSpell(me, 199971, true);
            if (Creature* npc = player->FindNearestCreature(101457, 50.0f, true))
                npc->CastSpell(npc, 199971, true);
            if (Creature* npc = player->FindNearestCreature(98797, 50.0f, true))
                npc->CastSpell(npc, 199971, true);
            if (Creature* npc = player->FindNearestCreature(101454, 50.0f, true))
                npc->CastSpell(npc, 199971, true);
                */

            if (Creature* npc = player->FindNearestCreature(98797, 50.0f, true))
            {
                npc->Say(103750);
                //go 245958
                npc->GetScheduler().Schedule(Milliseconds(2000), [](TaskContext context)
                {
                    GetContextCreature()->Say(103764);
                });
                npc->GetScheduler().Schedule(Milliseconds(6000), [](TaskContext context)
                {
                    GetContextCreature()->Say(103752);
                });
                npc->GetScheduler().Schedule(Milliseconds(10000), [](TaskContext context)
                {
                    GetContextCreature()->Say(103754);
                });
                npc->GetScheduler().Schedule(Milliseconds(14000), [player](TaskContext context)
                {
                    GetContextCreature()->Say(103756);
                    //fire 35845 cast 181569
                    //fire 35845 cast aura 199994
                    //99561 cast 199990 stopcast summon
                    player->CastSpell(player, 199990, true);

                });

                npc->GetScheduler().Schedule(Milliseconds(20000), [](TaskContext context)
                {
                    //GetContextCreature()->Say(103754);
                    /*98797 Points: X: -859.495 Y: 4449.82 Z: 696.0513
            98797 103759
            98797 cast 199952*/
                    GetContextCreature()->RemoveAura(204833);
                    GetContextCreature()->GetMotionMaster()->MovePoint(2, Position(-859.495f, 4449.82f, 696.0513f), true);
                    GetContextCreature()->Say(103759);
                });
                npc->GetScheduler().Schedule(Milliseconds(20000), [](TaskContext context)
                {
                    GetContextCreature()->CastSpell(GetContextCreature(), 199952, true);
                });
                /*
            98831 cast 200016 catch 98797
            98831 say 103760
            98797  say 103761
            98831 say 103762
            98831 cast 200038 call trigger 200039->player
            player cast 200032 to 101460*/
                npc->GetScheduler().Schedule(Milliseconds(22000), [npc, player](TaskContext context)
                {
                    if (Creature* boss = player->GetSummonedCreatureByEntry(98831))
                    {
                        boss->CastSpell(npc, 200016, true);
                        boss->Say(103760);
                    }
                });
                npc->GetScheduler().Schedule(Milliseconds(24000), [](TaskContext context)
                {
                    GetContextCreature()->Say(103761);
                });
                npc->GetScheduler().Schedule(Milliseconds(26000), [npc, player](TaskContext context)
                {
                    if (Creature* boss = player->GetSummonedCreatureByEntry(98831))
                    {
                        boss->Say(103762);
                        boss->CastSpell(player, 200038, true);

                    }
                });

                /*
                101460 cast 196229
                101460 cast 200033 to all

                98831 say 103763
                player cast 199362
                player cast 194854
                (DstLocation) Location: X: 2964.78 Y: 1128.12 Z: 206.71
                (Cast) (Target) Orientation: 3.600265
                (Cast) (Target) MapID: 1522
                */

                npc->GetScheduler().Schedule(Milliseconds(30000), [npc, player](TaskContext context)
                {
                    if (Creature* boss = player->GetSummonedCreatureByEntry(98831))
                        boss->Say(103763);
                });
                npc->GetScheduler().Schedule(Milliseconds(31000), [npc, player](TaskContext context)
                {
                    player->CastSpell(player, 199362, true);
                });
                npc->GetScheduler().Schedule(Milliseconds(32000), [npc, player](TaskContext context)
                {
                    player->CastSpell(player, 194854, true);
                    player->RemoveAura(204833);
                    /*
                    ServerToClient: SMSG_NEW_WORLD (0x25A9) Length: 36 ConnIdx: 1 Time: 09/19/2016 20:35:43.164 Number: 6065
                    Map: 1522 (-Unknown-)
                    Position: X: 2964.78 Y: 1128.12 Z: 206.71 O: 3.600265
                    */
                    //to do teleport
                    player->TeleportTo(1522, Position(2964.78f, 1128.12f, 206.71f, 3.600265f));
                });

            }
            if (Creature* npc = player->FindNearestCreature(101457, 50.0f, true))
            {
                npc->GetScheduler().Schedule(Milliseconds(4000), [](TaskContext context)
                {
                    GetContextCreature()->Say(103751);
                });
                npc->GetScheduler().Schedule(Milliseconds(16000), [player](TaskContext context)
                {
                    GetContextCreature()->Say(103757);
                    //player cast 199989
                    //all fire despawn 35845
                    if (Creature* door = player->GetSummonedCreatureByEntry(98831))
                        door->DespawnOrUnsummon();
                    player->SummonCreature(98831, Position(-867.6754f, 4439.961f, 696.7425f, 0.7974676f));
                    //GetContextCreature()->Say(103747);

                    ///summon door //door 101433 delay 9000 cast 222203
                    if (Creature* boss = player->GetSummonedCreatureByEntry(98831))
                    {
                        boss->Say(103758);
                        boss->CastSpell(boss, 200011, true);
                        /*
                        98797 move Points: X: -846.1344 Y: 4459.916 Z: 696.0439
                        101454 Points: X: -841.886 Y: 4445.958 Z: 696.023
                        101455 Points: X: -859.4317 Y: 4467.347 Z: 696.0369
                        101456 Points: X: -842.5834 Y: 4453.837 Z: 696.0247
                        101457 Points: X: -868.1119 Y: 4467.236 Z: 696.6078

                        98797 ,101454,101455,101456,101457,player cast 204833
                        */
                        player->CastSpell(player, 204833, true);
                        //98797 ,101454,101455,101456,101457
                        if (Creature* npc1 = player->FindNearestCreature(98797, 50.0f, true))
                            npc1->CastSpell(npc1, 204833, true);
                        if (Creature* npc1 = player->FindNearestCreature(101454, 50.0f, true))
                            npc1->CastSpell(npc1, 204833, true);
                        if (Creature* npc1 = player->FindNearestCreature(101455, 50.0f, true))
                            npc1->CastSpell(npc1, 204833, true);
                        if (Creature* npc1 = player->FindNearestCreature(101456, 50.0f, true))
                            npc1->CastSpell(npc1, 204833, true);
                        if (Creature* npc1 = player->FindNearestCreature(1014567, 50.0f, true))
                            npc1->CastSpell(npc1, 204833, true);
                    }

                });
            }
            if (Creature* npc = player->FindNearestCreature(101456, 50.0f, true))
            {
                npc->GetScheduler().Schedule(Milliseconds(8000), [](TaskContext context)
                {
                    GetContextCreature()->Say(103753);
                });
                npc->GetScheduler().Schedule(Milliseconds(12000), [](TaskContext context)
                {
                    GetContextCreature()->Say(103755);
                });
            }



        }
    }
private:
};

struct npc_calydus_101097 : public ScriptedAI
{
    npc_calydus_101097(Creature* creature) : ScriptedAI(creature) { Initialize(); }

    void DoAction(int32 param)
    {
        switch (param)
        {
        case 1:
            break;
        case 2:
          //  _sceneHelper.Clear();
           // _sceneHelper.SetDefaultActorGuid(me->GetGUID());
         //   _sceneHelper.AddSceneActionSay(114574, 5000);
        //    _sceneHelper.Activate();
            break;
        }
    }

    void sQuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_THE_TOME_OF_BLIGHTED_IMPLEMENTS)
        {
            me->GetScheduler().Schedule(1s, 2s, [player](TaskContext context)
            {
                player->CastSpell(player, SPELL_PLAYER_CHOICE_WARLOCK, true);
            });
        }
        if (quest->GetQuestId() == QUEST_THE_HEART_OF_THE_DREADSCAR)
            player->TeleportTo(1522, Position(3091.9f, 856.533f, 243.376f, 1.5836f));
    }

    void sQuestReward(Player* player, Quest const* quest, uint32 /*opt*/)  override
    {
        if (quest->GetQuestId() == QUEST_THE_NEW_BLOOD)
        {
            if (const Quest* quest = sObjectMgr->GetQuestTemplate(QUEST_THE_TOME_OF_BLIGHTED_IMPLEMENTS))
                player->AddQuest(quest, me);
        }
    }

    void Initialize()
    {
        IsLock = false;
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (!who || !who->IsInWorld())
            return;
        if (!me->IsWithinDist(who, 15.0f, false))
            return;
        Player* player = who->GetCharmerOrOwnerPlayerOrPlayerItself();
        if (!player)
            return;
        if (!IsLock && player->HasQuest(QUEST_THE_NEW_BLOOD))
        {
            IsLock = true;
            player->KilledMonsterCredit(101150);
            me->Say(103567);
            //103568
            me->GetScheduler().Schedule(Milliseconds(4000), [](TaskContext context)
            {
                GetContextCreature()->Say(103567);
            });
        }
    }

    void sGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId)
    {
        CloseGossipMenuFor(player);
        player->CastSpell(player, SPELL_PLAYER_CHOICE_WARLOCK, true);
    }
};

class warlock_weapons_of_legend_player_choice : public PlayerScript {
public:
    warlock_weapons_of_legend_player_choice() : PlayerScript("warlock_weapons_of_legend_player_choice") {}

    void OnPlayerChoiceResponse(Player* player, uint32 choiceId, uint32 responseId)
    {
        if (player->getClass() != CLASS_WARLOCK)
            return;
        if (choiceId != PLAYER_CHOICE_WARLOCK_SELECTION)
            return;

        TC_LOG_ERROR("server.worldserver", "warlock_playerchoice %u, %u", choiceId, responseId);
        if (player->HasQuest(QUEST_THE_TOME_OF_BLIGHTED_IMPLEMENTS))
            player->KilledMonsterCredit(101095);
        if (player->HasQuest(QUEST_THE_TOME_OPENS_AGAIN))
            player->KilledMonsterCredit(112077);
        if (player->HasQuest(QUEST_A_GREATER_ARSENAL))
            player->KilledMonsterCredit(113792);

        switch (responseId)
        {
        case PLAYER_CHOICE_WARLOCK_AFFLICTION:
            if (player->GetQuestStatus(QUEST_ULTHALESH_THE_DEADWIND_HARVESTER) == QUEST_STATUS_NONE)
                if (const Quest* quest = sObjectMgr->GetQuestTemplate(QUEST_ULTHALESH_THE_DEADWIND_HARVESTER))
                    player->AddQuest(quest, nullptr);
            break;
        case PLAYER_CHOICE_WARLOCK_DEMONOLOGY:
            if (player->GetQuestStatus(QUEST_RITUAL_REAGENTS) == QUEST_STATUS_NONE)
                if (const Quest* quest = sObjectMgr->GetQuestTemplate(QUEST_RITUAL_REAGENTS))
                    player->AddQuest(quest, nullptr);
            break;
        case PLAYER_CHOICE_WARLOCK_DESTRUCTION:
            if (player->GetQuestStatus(QUEST_FINDING_THE_SCEPTER) == QUEST_STATUS_NONE)
                if (const Quest* quest = sObjectMgr->GetQuestTemplate(QUEST_FINDING_THE_SCEPTER))
                    player->AddQuest(quest, nullptr);
            break;
        default:
            break;
        }

    }

    void OnUpdateArea(Player* player, uint32 /*newArea*/, uint32 /*oldArea*/)
    {
        if (player->HasQuest(40611) && player->GetZoneId() == 41)
            player->CastSpell(player, 198333, true);
        else
            player->RemoveAurasDueToSpell(198333);
    }

    void OnSuccessfulSpellCast(Player* player, Spell* spell)
    {
        if (spell->GetSpellInfo()->Id == 198335)
        {
            if (player->HasQuest(40611))
            {
                //bridge
                if (player->GetPositionX() <= -10888.9f && player->GetPositionX() >= -10918.9f)
                    if (player->GetPositionY() <= -1995.68f && player->GetPositionY() >= -2025.68f)
                        player->KilledMonsterCredit(100757);
                //church
                if (player->GetPositionX() <= -11155.14f && player->GetPositionX() >= -11185.14f)
                    if (player->GetPositionY() <= -1837.13f && player->GetPositionY() >= -1867.13f)
                        player->KilledMonsterCredit(100756);
                //Deadman's Crossing
                if (player->GetPositionX() <= -10440.64f && player->GetPositionX() >= -10470.64f)
                    if (player->GetPositionY() <= -1705.75f && player->GetPositionY() >= -1735.75f)
                        player->KilledMonsterCredit(100755);
            }
        }
    }

    void OnQuestReward(Player* player, Quest const* quest)
    {
        if (quest->GetQuestId() == 40611)
            player->RemoveAurasDueToSpell(198333);
    }
};
///251696,251697,251698
class go_finding_the_scepter_obj : public GameObjectScript
{
public:
    go_finding_the_scepter_obj() : GameObjectScript("go_finding_the_scepter_obj") { }

    bool OnGossipHello(Player* player, GameObject* go) override
    {
        player->KilledMonsterCredit(go->GetEntry());
        player->KilledMonsterCredit(109693);
        return false;
    }
};


//on 3 page open  2851
//?? 115699 ???????????!?????????????,?????????!
//??? 115700 ????,???!???????????????????????
//?? 115701 ?!??..?????!

//ondeath npc_calydus_109698 115809 Calydus is here, friend! Council flees! Haha!
//phase
//115703 ????????!
struct npc_calydus_109698 : public ScriptedAI
{
    npc_calydus_109698(Creature* creature) : ScriptedAI(creature) { Initialize(); }

    void sQuestAccept(Player* player, Quest const* quest) override
    {

    }

    void DoAction(int32 param)
    {
        switch (param)
        {
        case 1:
            me->GetScheduler().Schedule(Milliseconds(1000), [](TaskContext context)
            {
                GetContextCreature()->Say(115809);
            });
            me->GetScheduler().Schedule(Milliseconds(3000), [](TaskContext context)
            {
                GetContextCreature()->Say(115703);
            });
            break;
        }
    }

    void sGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId)
    {
        CloseGossipMenuFor(player);
        Talk(0);
        me->GetScheduler().Schedule(Milliseconds(4000), [this](TaskContext context)
        {
            Talk(1);
        });
        me->GetScheduler().Schedule(Milliseconds(8000), [player](TaskContext context)
        {
            player->KilledMonsterCredit(109696);
        });
    }

    void Initialize()
    {
        IsLock = false;
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (!who || !who->IsInWorld() || !me->IsWithinDist(who, 15.0f, false))
            return;

        Player* player = who->GetCharmerOrOwnerPlayerOrPlayerItself();
        if (!player)
            return;
        if (!IsLock && player->HasQuest(QUEST_FINDING_THE_SCEPTER))
        {
            IsLock = true;
           // Conversation::CreateConversation(2851, player, player->GetPosition(), { player->GetGUID() });
        }
    }
};

struct npc_jergosh_the_invoker_109608 : public ScriptedAI
{
    npc_jergosh_the_invoker_109608(Creature* creature) : ScriptedAI(creature) { Initialize(); }

    void Initialize()
    {

    }

    void JustDied(Unit* killer) override
    {
        if (Player* player = killer->GetCharmerOrOwnerPlayerOrPlayerItself())
        {
            PhasingHandler::AddPhase(player, 6938, true);
            if (Creature* npc = me->FindNearestCreature(109698, 1000.0f, true))
                npc->AI()->DoAction(1);
        }
    }


};

//go 251699 Portal to Tol Barad
class go_portal_to_tol_barad : public GameObjectScript
{
public:
    go_portal_to_tol_barad() : GameObjectScript("go_portal_to_tol_barad") { }

    bool OnGossipHello(Player* player, GameObject* /*go*/) override
    {
        if (!player->GetQuestObjectiveData(QUEST_AN_EYE_FOR_A_SCEPTER, 7))
            player->KilledMonsterCredit(109835);

        //player->CastSpell(player, 218595, true);
        player->TeleportTo(1630, Position(-854.89f, 1188.86f, 114.29f, 3.168296f));
        return false;
    }
};

struct npc_fel_bat_110479 : public ScriptedAI
{
    npc_fel_bat_110479(Creature* creature) : ScriptedAI(creature) { }

    void OnSpellClick(Unit* clicker, bool& /*result*/)
    {
        if (Player* player = clicker->ToPlayer())
        {
            if (player->GetQuestStatus(QUEST_RITUAL_RUINATION) == QUEST_STATUS_INCOMPLETE)
            {
                player->KilledMonsterCredit(110523);
                player->TeleportTo(1220, Position(-666.047f, 2613.08f, 81.0715f, 5.32719f));
            }
        }
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Player* player = who->ToPlayer())
        {
            if (me->IsWithinDist(player, 15.0f, false))
                if (player->HasQuest(QUEST_RITUAL_RUINATION))
                    me->AddNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
        }
    }
};

struct npc_gul_dan_110533 : public ScriptedAI
{
    npc_gul_dan_110533(Creature* creature) : ScriptedAI(creature) {}

    void MoveInLineOfSight(Unit* who) override
    {
        if (Player* player = who->ToPlayer())
        {
            if (me->IsWithinDist(player, 15.0f, false))
            {
                if (!IsLock && player->HasQuest(QUEST_RITUAL_RUINATION))
                {
                    IsLock = true;
                    if (Creature* target = me->FindNearestCreature(110568, 50.0f))
                        target->SetDisplayId(71354);
                    me->Yell(117564);
                    me->GetScheduler().Schedule(4s, [this](TaskContext /*context*/)
                    {
                        me->Say(117565);
                    });
                    me->GetScheduler().Schedule(8s, [this](TaskContext /*context*/)
                    {
                        me->Yell(117566);
                    });
                    me->GetScheduler().Schedule(12s, [this](TaskContext /*context*/)
                    {
                        me->Yell(117567);
                    });

                    me->GetScheduler().Schedule(16s, [this](TaskContext /*context*/)
                    {
                        if (Creature* target = me->FindNearestCreature(110556, 50.0f))
                            target->Yell(117568);
                    });
                    me->GetScheduler().Schedule(20s, [this, player](TaskContext /*context*/)
                    {
                        me->Yell(117576);
                        player->KilledMonsterCredit(110581);
                    });
                    me->GetScheduler().Schedule(22s, [this, player](TaskContext /*context*/)
                    {
                        if (Creature* target = me->FindNearestCreature(110556, 50.0f))
                            target->GetMotionMaster()->MovePoint(1, Position(-636.737f, 2575.58f, 82.386f, 2.238932f), true);
                        me->GetMotionMaster()->MoveAwayAndDespawn(-30.0f, 30000);
                    });
                }
            }
        }
    }
};

struct npc_image_of_guldan_110548 : public ScriptedAI
{
    npc_image_of_guldan_110548(Creature* creature) : ScriptedAI(creature) { }

    void DoAction(int32 param)
    {
        switch (param)
        {
        case 1:
            me->Say(117590);
            me->GetScheduler().Schedule(Milliseconds(4000), [this](TaskContext context)
            {
                me->Say(120133);
            });
        case 2:
            me->Yell(117591);
            me->SummonCreature(110476, Position(-667.751f, 2614.76f, 80.7247f, 2.34035f), TEMPSUMMON_TIMED_DESPAWN, 180000);
            me->GetScheduler().Schedule(Milliseconds(10000), [this](TaskContext context)
            {
                me->Yell(117611);
            });
            break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }


private:
    TaskScheduler _scheduler;
};

struct npc_allaris_narassin_110556 : public ScriptedAI
{
    npc_allaris_narassin_110556(Creature* creature) : ScriptedAI(creature) { }

    enum Spells
    {
        SPELL_DRAIN_LIFE = 221309,
        SPELL_SHADOW_BOLT = 79932,
        SPELL_SUMMON_PHANTOMFLAME_INFERNAL = 221323,
    };

    void MovementInform(uint32 /*type*/, uint32 id) override
    {
        switch (id)
        {
        case 1:
            me->SetOrientation(2.238932f);
            me->Yell(117582);
            me->GetScheduler().Schedule(250ms, [this](TaskContext /*context*/)
            {
                me->SetFaction(16);
            });
            break;

        default:
            break;
        }
    }

    void JustDied(Unit* killer) override
    {
        me->Say(117588);
        std::list<Player*> _list = me->SelectNearestPlayers(50.f, true);
        if (!_list.empty())
        {
            for (Player* player : _list)
                if (player->HasQuest(QUEST_RITUAL_RUINATION))
                    player->KilledMonsterCredit(114337);
        }

        me->SummonGameObject(252054, Position(-656.67f, 2600.33f, 82.5702f), QuaternionData(), WEEK);
        if (Creature* guldan = me->FindNearestCreature(110548, 50.0f, true))
            guldan->AI()->DoAction(1);
    }

    void EnterCombat(Unit* /*attacker*/) override
    {
        events.ScheduleEvent(SPELL_DRAIN_LIFE, 15s);
        events.ScheduleEvent(SPELL_SHADOW_BOLT, 5s);
        events.ScheduleEvent(SPELL_SUMMON_PHANTOMFLAME_INFERNAL, 25s);
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
        case SPELL_DRAIN_LIFE:
        {
            DoCast(SPELL_DRAIN_LIFE);
            events.Repeat(15s);
            break;
        }
        case SPELL_SHADOW_BOLT:
        {
            DoCast(SPELL_SHADOW_BOLT);
            events.Repeat(5s);
            break;
        }
        case SPELL_SUMMON_PHANTOMFLAME_INFERNAL:
        {
            DoCast(SPELL_SUMMON_PHANTOMFLAME_INFERNAL);
            events.Repeat(25s);
            break;
        }
        }
        DoMeleeAttackIfReady();
    }
};
//252054/scepter-of-sargeras
class go_scepter_of_sargeras_252054 : public GameObjectScript
{
public:
    go_scepter_of_sargeras_252054() : GameObjectScript("go_scepter_of_sargeras_252054")
    {
        isloot = false;
    }

    void OnLootStateChanged(GameObject* go, uint32 state, Unit* unit)
    {
        if (state == GO_ACTIVATED && unit && !isloot)
        {
            isloot = true;
            if (Player* player = unit->ToPlayer())
            {
                player->GetScheduler().Schedule(Milliseconds(4000), [player](TaskContext context)
                {
                    player->KilledMonsterCredit(110603);
                    player->GetSceneMgr().PlaySceneByPackageId(1681);
                });
            }

            if (Creature* guldan = go->FindNearestCreature(110548, 50.0f, true))
                guldan->AI()->DoAction(2);
        }
    }
    bool isloot;
};

struct npc_demonic_portal_110476 : public ScriptedAI
{
    npc_demonic_portal_110476(Creature* creature) : ScriptedAI(creature) {  }

    void OnSpellClick(Unit* clicker, bool& /*result*/)
    {
        if (Player* player = clicker->ToPlayer())
        {
            if (player->GetQuestStatus(QUEST_RITUAL_RUINATION) == QUEST_STATUS_INCOMPLETE)
            {
                player->KilledMonsterCredit(110607);
                player->TeleportTo(1502, Position(-856.202f, 4471.12f, 696.024f, 2.17694f));
            }
        }
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Player* player = who->ToPlayer())
        {
            if (me->IsWithinDist(player, 15.0f, false))
                if (player->HasQuest(QUEST_RITUAL_RUINATION))
                    me->AddNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
        }
    }
private:
    TaskScheduler _scheduler;
};

class go_calyduss_demonic_portal_249813 : public GameObjectScript
{
public:
    go_calyduss_demonic_portal_249813() : GameObjectScript("go_calyduss_demonic_portal_249813") { }

    bool OnGossipHello(Player* player, GameObject* /*go*/)
    {
        player->TeleportTo(1498, Position(1263.69f, 5236.659f, 93.531f));
        return false;
    }
};

struct npc_docile_stag_106581 : public ScriptedAI
{
    npc_docile_stag_106581(Creature* creature) : ScriptedAI(creature) { }

    void sGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId)
    {
        CloseGossipMenuFor(player);
        if (player->HasQuest(QUEST_RITUAL_REAGENTS))
            player->AddItem(136986, 1);
    }
};

struct npc_thal_kiel_106749 : public ScriptedAI
{
    npc_thal_kiel_106749(Creature* creature) : ScriptedAI(creature) { }

    void sGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId)
    {
        CloseGossipMenuFor(player);
        if (player->HasQuest(QUEST_LOOKING_INTO_THE_DARKNESS))
            player->KilledMonsterCredit(106746);
    }
};

struct npc_calydus_106610 : public ScriptedAI
{
    npc_calydus_106610(Creature* creature) : ScriptedAI(creature) { }

    enum calydusSpells
    {
        SPELL_ASSIGN_WARLOCK_SPELL_BAR = 211718,
    };

    void sQuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_LOOKING_INTO_THE_DARKNESS)
            player->CastSpell(player, SPELL_ASSIGN_WARLOCK_SPELL_BAR, true);
        if (quest->GetQuestId() == QUEST_DARK_WHISPERS)
            player->SummonGameObject(249813, Position(-842.875f, 4431.096f, 742.5369f, 5.074315f), QuaternionData(0.0f, 0.0f, -0.5682974f, 0.8228232f), 300000, true);
    }

    void sQuestReward(Player* player, Quest const* quest, uint32 /*opt*/)  override
    {
        if (quest->GetQuestId() == QUEST_LOOKING_INTO_THE_DARKNESS)
            player->RemoveAurasDueToSpell(SPELL_ASSIGN_WARLOCK_SPELL_BAR);
    }
};

void AddSC_class_hall_warlock()
{
    RegisterCreatureAI(npc_ritssyn_flamescowl_103506);
    new quest_phase_for_warlock();
    RegisterCreatureAI(npc_ritssyn_flamescowl_101456);
    RegisterCreatureAI(npc_summoning_portal_101433);
    RegisterCreatureAI(npc_calydus_101097);
    new warlock_weapons_of_legend_player_choice();
    new go_finding_the_scepter_obj();
    RegisterCreatureAI(npc_calydus_109698);
    RegisterCreatureAI(npc_jergosh_the_invoker_109608);
    new go_portal_to_tol_barad();
    RegisterCreatureAI(npc_fel_bat_110479);
    RegisterCreatureAI(npc_gul_dan_110533);
    RegisterCreatureAI(npc_image_of_guldan_110548);
    RegisterCreatureAI(npc_allaris_narassin_110556);
    RegisterCreatureAI(npc_demonic_portal_110476);
    new go_scepter_of_sargeras_252054();
    new go_calyduss_demonic_portal_249813();
    RegisterCreatureAI(npc_docile_stag_106581);
    RegisterCreatureAI(npc_thal_kiel_106749);
    RegisterCreatureAI(npc_calydus_106610);
}
