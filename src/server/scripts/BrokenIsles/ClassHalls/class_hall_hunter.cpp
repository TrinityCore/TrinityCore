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

#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "GameObject.h"
#include "PhasingHandler.h"

enum
{
    ///Hunter Quest
    NPC_SNOWFEATHER_100786 = 100786,
    QUEST_NEEDS_OF_THE_HUNTERS = 40384,
    QUEST_THE_HUNTERS_CALL = 41415,
    QUEST_WEAPONS_OF_LEGEND = 40618,
    QUEST_ONE_MORE_LEGEND = 44043,
    QUEST_MORE_WEAPONS_OF_LEGEND = 44366,

    SPELL_WEAPONS_OF_LEGEND_PLAYER_CHOICE = 198430,
    PLAYER_CHOICE_HUNTER_SELECTION = 240,

    ACTION_RESPONSEID_1 = 504, //Beast Mastery
    ACTION_RESPONSEID_2 = 506, //Marksmanship
    ACTION_RESPONSEID_3 = 505, //Survival
    //Beast Mastery
    QUEST_A_BEASTLY_EXPEDITION = 41541,
    QUEST_STOLEN_THUNDER = 41574,
    QUEST_HUNTER_TO_HUNTER = 41009,
    QUEST_ON_EAGLES_WINGS = 40953,
    QUEST_THE_UNSEEN_PATH = 40954,
    QUEST_OATH_OF_SERVICE = 40955,
    //Marksmanship
    QUEST_RENDEZVOUS_WITH_THE_COURIER = 41540,
    QUEST_CALL_OF_THE_MARKSMAN = 40392,
    QUEST_CLANDESTINE_OPERATION = 40400,
    QUEST_RESCUE_MISSION = 40419,
    //Survival
    QUEST_PREPARATION_FOR_THE_HUNT = 41542,
    QUEST_THE_EAGLE_SPIRIT_S_BLESSING = 39427,
    QUEST_THE_SPEAR_IN_THE_SHADOW = 40385,
};

struct npc_snowfeather_100786 : public ScriptedAI
{
    npc_snowfeather_100786(Creature* creature) : ScriptedAI(creature) { }

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
        if (quest->GetQuestId() == QUEST_NEEDS_OF_THE_HUNTERS)
        {
            Talk(1, player);
            me->DespawnOrUnsummon(5000);
        }
    }
};
//107317 ,102478
struct npc_emmarel_shadewarden_102478 : public ScriptedAI
{
    npc_emmarel_shadewarden_102478(Creature* creature) : ScriptedAI(creature) { }

    void sQuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_A_BEASTLY_EXPEDITION)
            Talk(0, player); // me->Say(105574, player);
    }

    void sQuestReward(Player* player, Quest const* quest, uint32 /*opt*/)  override
    {
        if (quest->GetQuestId() == QUEST_NEEDS_OF_THE_HUNTERS)
            if (const Quest* quest_1 = sObjectMgr->GetQuestTemplate(QUEST_THE_HUNTERS_CALL))
                player->AddQuest(quest_1, me);
        if (quest->GetQuestId() == QUEST_THE_HUNTERS_CALL)
            if (player->GetQuestStatus(QUEST_WEAPONS_OF_LEGEND) == QUEST_STATUS_NONE)
                if (const Quest* quest_1 = sObjectMgr->GetQuestTemplate(QUEST_WEAPONS_OF_LEGEND))
                    player->AddQuest(quest_1, me);

        if (quest->GetQuestId() == QUEST_WEAPONS_OF_LEGEND || quest->GetQuestId() == QUEST_ONE_MORE_LEGEND || quest->GetQuestId() == QUEST_MORE_WEAPONS_OF_LEGEND)
        {

        }
    }

    void sGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId)
    {
        CloseGossipMenuFor(player);
        player->CastSpell(player, SPELL_WEAPONS_OF_LEGEND_PLAYER_CHOICE, true);
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Player* player = who->ToPlayer())
        {
            if (me->IsWithinDist(who, 15.0f, false) && player->HasQuest(QUEST_HUNTER_TO_HUNTER) && !IsLock)
            {
                IsLock = true;
                me->Say(103492);
                SetUnlock(60000);
            }
        }
    }
};

class hunter_playerchoice : public PlayerScript
{
public:
    hunter_playerchoice() : PlayerScript("hunter_playerchoice") { }

    void OnQuestStatusChange(Player* player, uint32 /*questId*/)
    {
        //if (player->getClass() == CLASS_HUNTER || player->getLevel() >= 98)
           // OnCheckPhase(player);
    }

    void OnPlayerChoiceResponse(Player* player, uint32 choiceId, uint32 responseId)
    {
        if (choiceId != PLAYER_CHOICE_HUNTER_SELECTION)
            return;

        if (player->HasQuest(QUEST_WEAPONS_OF_LEGEND))
            player->KilledMonsterCredit(104634);
        if (player->HasQuest(QUEST_ONE_MORE_LEGEND))
            player->KilledMonsterCredit(112362);
        if (player->HasQuest(QUEST_MORE_WEAPONS_OF_LEGEND))
            player->KilledMonsterCredit(113746);

        switch (responseId)
        {
        case ACTION_RESPONSEID_1: //Beast Mastery
            if (const Quest* quest_1 = sObjectMgr->GetQuestTemplate(QUEST_A_BEASTLY_EXPEDITION))
                player->AddQuest(quest_1, nullptr);
            break;
        case ACTION_RESPONSEID_2://Marksmanship
            if (const Quest* quest_2 = sObjectMgr->GetQuestTemplate(QUEST_RENDEZVOUS_WITH_THE_COURIER))
                player->AddQuest(quest_2, nullptr);
            break;
        case ACTION_RESPONSEID_3://Survival
            if (const Quest* quest_3 = sObjectMgr->GetQuestTemplate(QUEST_PREPARATION_FOR_THE_HUNT))
                player->AddQuest(quest_3, nullptr);
            break;
        default:
            break;
        }
    }
};

struct npc_grif_wildheart_104381 : public ScriptedAI
{
    npc_grif_wildheart_104381(Creature* creature) : ScriptedAI(creature) { }

    void sQuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_STOLEN_THUNDER)
        {
            me->Say(109176);
            if (Creature* bird = me->FindNearestCreature(106235, 50.0f))
                bird->AddNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
        }
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Player* player = who->ToPlayer())
        {
            if ((player->getClass() == CLASS_HUNTER) && me->IsWithinDist(who, 25.0f, false))
            {
                if (!IsLock && player->HasQuest(QUEST_A_BEASTLY_EXPEDITION))
                {
                    IsLock = true;
                    me->Say(111033);
                }
            }
        }
    }
};

struct npc_huey_106235 : public ScriptedAI
{
    npc_huey_106235(Creature* creature) : ScriptedAI(creature) { }

    void OnSpellClick(Unit* clicker, bool& /*result*/)
    {
        if (Player* player = clicker->ToPlayer())
        {
            if (player->GetQuestStatus(QUEST_STOLEN_THUNDER) == QUEST_STATUS_INCOMPLETE)
            {
                if (Creature* grif = me->FindNearestCreature(104381, 50.0f))
                {
                    grif->Say(109182);

                    AddTimedDelayedOperation(2500, [this, grif]() -> void
                        {
                            grif->Say(109183);
                        });

                    AddTimedDelayedOperation(4500, [this, grif]() -> void
                        {
                            grif->Say(109187);
                        });
                    AddTimedDelayedOperation(6500, [this, player]() -> void
                        {
                            player->TeleportTo(1495, Position(4762.8178f, 62.2226f, -0.83612f, 1.0966f));
                        });
                }

            }
        }
    }
};

struct npc_emmarel_shadewarden_102578 : public ScriptedAI
{
    npc_emmarel_shadewarden_102578(Creature* creature) : ScriptedAI(creature) { }

    void sQuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_THE_UNSEEN_PATH)
            me->GetMotionMaster()->MovePoint(1, Position(4637.946f, 5330.555f, 849.253f, 5.48159f), true);
        if (quest->GetQuestId() == QUEST_OATH_OF_SERVICE)
        {
            me->GetMotionMaster()->MovePoint(10, Position(4642.029f, 5285.06f, 840.703f), true);
            _scheduler.Schedule(10s, [this, player](TaskContext /*context*/)
                {
                    player->KilledMonsterCredit(102794);
                });
        }

    }

    void MovementInform(uint32 /*type*/, uint32 id) override
    {
        switch (id)
        {
        case 1:
            me->Say(105028);
            _scheduler.Schedule(250ms, [this](TaskContext /*context*/)
                {
                    me->GetMotionMaster()->MovePoint(2, Position(4651.6459f, 5316.006f, 845.719f, 5.4226f), true);
                });
            break;
        case 2:

            _scheduler.Schedule(250ms, [this](TaskContext /*context*/)
                {
                    me->GetMotionMaster()->MovePoint(3, Position(4651.6459f, 5316.006f, 845.719f, 5.4226f), true);
                });
            break;
        case 3:
            me->Say(105029);
            _scheduler.Schedule(250ms, [this](TaskContext /*context*/)
                {
                    me->GetMotionMaster()->MovePoint(4, Position(4656.732f, 5303.397f, 842.082f, 4.68678f), true);
                });
            break;
        case 4:
            _scheduler.Schedule(250ms, [this](TaskContext /*context*/)
                {
                    me->GetMotionMaster()->MovePoint(5, Position(4647.679f, 5289.325f, 840.782f, 4.7f), true);
                });
            break;
        case 5:
            me->Say(105032);
            _scheduler.Schedule(250ms, [this](TaskContext /*context*/)
                {
                    me->GetMotionMaster()->MovePoint(6, Position(4650.709f, 5284.169f, 840.857f, 5.096f), true);
                });
            break;
        case 6:
            if (Creature* wenleisi = me->FindNearestCreature(98740, 50.0f, true))
                wenleisi->Say(105216);
            _scheduler.Schedule(2s, [this](TaskContext /*context*/)
                {
                    if (Creature* hadulun = me->FindNearestCreature(98739, 50.0f, true))
                        hadulun->Say(105217);
                });
            _scheduler.Schedule(4s, [this](TaskContext /*context*/)
                {
                    //me->Say(105217);
                    if (Player* player = me->SelectNearestPlayer(15.0f))
                        player->KilledMonsterCredit(102688);
                });
        case 10:
            me->Say(105146);
            _scheduler.Schedule(2s, [this](TaskContext /*context*/)
                {
                    me->Say(105147);
                });
            _scheduler.Schedule(4s, [this](TaskContext /*context*/)
                {
                    me->Say(105148);
                });
            _scheduler.Schedule(6s, [this](TaskContext /*context*/)
                {
                    me->Say(105149);
                });
            _scheduler.Schedule(8s, [this](TaskContext /*context*/)
                {
                    me->Say(105184);
                    me->GetMotionMaster()->MovePoint(11, Position(4650.709f, 5284.169f, 840.857f, 5.096f), true);
                });
            break;
        default:
            break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Player* player = who->ToPlayer())
        {
            if (me->IsWithinDist(who, 15.0f, false))
            {
                if (player->HasQuest(QUEST_ON_EAGLES_WINGS))
                    player->KilledMonsterCredit(102626);
            }
        }
    }
private:
    TaskScheduler _scheduler;
};
//
struct npc_emmarel_shadewarden_102574 : public ScriptedAI
{
    npc_emmarel_shadewarden_102574(Creature* creature) : ScriptedAI(creature) {  }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

    void MovementInform(uint32 /*type*/, uint32 id) override
    {
        switch (id)
        {
        case 10:
            me->Say(105146);
            _scheduler.Schedule(2s, [this](TaskContext /*context*/)
                {
                    me->Say(105147);
                });
            _scheduler.Schedule(4s, [this](TaskContext /*context*/)
                {
                    me->Say(105148);
                });
            _scheduler.Schedule(6s, [this](TaskContext /*context*/)
                {
                    me->Say(105149);
                });
            _scheduler.Schedule(8s, [this](TaskContext /*context*/)
                {
                    me->Say(105184);
                    me->GetMotionMaster()->MovePoint(11, Position(4650.709f, 5284.169f, 840.857f, 5.096f), true);
                });
            break;

        default:
            break;
        }
    }

    void sQuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_OATH_OF_SERVICE)
        {
            me->GetMotionMaster()->MovePoint(10, Position(4642.029f, 5285.06f, 840.703f), true);
            _scheduler.Schedule(10s, [this, player](TaskContext /*context*/)
                {
                    player->KilledMonsterCredit(102794);
                });
        }

    }
private:
    TaskScheduler _scheduler;
};

struct npc_courier_larkspur_103741 : public ScriptedAI
{
    npc_courier_larkspur_103741(Creature* creature) : ScriptedAI(creature) {}

    void sQuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_CALL_OF_THE_MARKSMAN)
        {
            if (Creature* bird = me->FindNearestCreature(102177, 25.0f))
                bird->AddNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
        }
    }
};
//KILL 102173
struct npc_silver_covenant_hippogryph_102177 : public ScriptedAI
{
    npc_silver_covenant_hippogryph_102177(Creature* creature) : ScriptedAI(creature) { }

    void OnSpellClick(Unit* clicker, bool& /*result*/)
    {
        if (Player* player = clicker->ToPlayer())
        {
            if (player->GetQuestStatus(QUEST_CALL_OF_THE_MARKSMAN) == QUEST_STATUS_INCOMPLETE)
            {
                player->KilledMonsterCredit(102173);
                player->TeleportTo(1220, Position(-859.84f, 3604.6445f, 1.941741f, 1.406331f));
            }
        }
    }
};

struct npc_ranger_adronis_102007 : public ScriptedAI
{
    npc_ranger_adronis_102007(Creature* creature) : ScriptedAI(creature) { }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Player* player = who->ToPlayer())
        {
            if (me->IsWithinDist(player, 15.0f, false) && !IsLock && player->HasQuest(QUEST_CALL_OF_THE_MARKSMAN))
            {
                IsLock = true;
                Talk(0);
            }
        }
    }
};

struct npc_vereesa_windrunner_100190 : public ScriptedAI
{
    npc_vereesa_windrunner_100190(Creature* creature) : ScriptedAI(creature) { }

    void sQuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_CLANDESTINE_OPERATION)
        {
            Talk(0);
            me->GetScheduler().Schedule(Milliseconds(4000), [this](TaskContext context)
                {
                    me->Say(101867);
                });
            me->GetScheduler().Schedule(Milliseconds(10000), [this](TaskContext context)
                {
                    if (Creature* eruisi = me->FindNearestCreature(100193, 25.0f))
                        eruisi->Say(101870);
                });
            me->GetScheduler().Schedule(Milliseconds(14000), [this](TaskContext context)
                {
                    me->Say(101869);
                });
            me->GetScheduler().Schedule(Milliseconds(18000), [this](TaskContext context)
                {
                    if (Creature* eruisi = me->FindNearestCreature(100193, 25.0f))
                        eruisi->Say(101876);
                });
            me->GetScheduler().Schedule(Milliseconds(22000), [this, player](TaskContext context)
                {
                    me->Say(101877);
                    player->KilledMonsterCredit(100229);
                });
        }
    }

    void sGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId)
    {
        CloseGossipMenuFor(player);
        player->TalkedToCreature(me->GetEntry(), me->GetGUID());
        if (player->HasQuest(QUEST_RESCUE_MISSION))
        {
            Talk(1);
            me->GetScheduler().Schedule(Milliseconds(4000), [this](TaskContext context)
                {
                    if (Creature* target = me->FindNearestCreature(100172, 25.0f))
                        target->AI()->Talk(0);
                });
            me->GetScheduler().Schedule(Milliseconds(8000), [this, player](TaskContext context)
                {
                    player->KilledMonsterCredit(103481);
                    PhasingHandler::AddPhase(player, 5951);
                });
        }
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Player* player = who->ToPlayer())
        {
            if (me->IsWithinDist(player, 15.0f, false))
            {
                if (!IsLock && player->HasQuest(QUEST_CALL_OF_THE_MARKSMAN))
                {
                    IsLock = true;
                    if (Creature* eruisi = me->FindNearestCreature(100193, 25.0f))
                        eruisi->AI()->Talk(0);
                    player->KilledMonsterCredit(103602);
                    me->AddNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                }
            }
        }
    }
};

struct npc_portal_to_niskara_104835 : public ScriptedAI
{
    npc_portal_to_niskara_104835(Creature* creature) : ScriptedAI(creature) { }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Player* player = who->ToPlayer())
        {
            if (me->IsWithinDist(player, 2.0f, false))
            {
                if (!IsLock && player->HasQuest(QUEST_RESCUE_MISSION))
                {
                    IsLock = true;
                    player->KilledMonsterCredit(102129);
                    player->TeleportTo(1489, Position(234.68f, 1950.91f, -55.89f, 0.2827434f));
                }
            }
        }
    }
};

//Survival
struct npc_apata_highmountain_104382 : public ScriptedAI
 {
    npc_apata_highmountain_104382(Creature * creature) : ScriptedAI(creature) { }
    
        void sQuestAccept(Player * player, Quest const* quest) override
         {
        if (quest->GetQuestId() == QUEST_THE_EAGLE_SPIRIT_S_BLESSING)
             {
            if (Creature* bird = player->SummonCreature(100967, Position(-861.094f, 4276.1f, 746.284f, 0.365586f), TEMPSUMMON_MANUAL_DESPAWN, 300000, 0, true))
                 bird->AddNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
            player->SummonCreature(100990, Position(-861.094f, 4276.1f, 746.284f, 0.365586f), TEMPSUMMON_MANUAL_DESPAWN, 300000, 0, true);
            }
         }
    
        void MoveInLineOfSight(Unit * who) override
         {
        if (Player* player = who->ToPlayer())
             {
            if (me->IsWithinDist(player, 15.0f, false))
                 {
                if (!IsLock && player->HasQuest(QUEST_PREPARATION_FOR_THE_HUNT))
                     {
                    IsLock = true;
                    me->Say(101748);
                    player->ForceCompleteQuest(QUEST_PREPARATION_FOR_THE_HUNT);
                    }
                 }
             }
         }
     };
//QUEST_THE_EAGLE_SPIRIT_S_BLESSING
struct npc_highmountain_hippogryph_100967 : public ScriptedAI
 {
    npc_highmountain_hippogryph_100967(Creature * creature) : ScriptedAI(creature) { }
    
        void OnSpellClick(Unit * clicker, bool& /*result*/)
         {
        if (Player* player = clicker->ToPlayer())
             {
            if (player->GetQuestStatus(QUEST_THE_EAGLE_SPIRIT_S_BLESSING) == QUEST_STATUS_INCOMPLETE)
                 {
                player->KilledMonsterCredit(110936);
                player->CastSpell(me, 52391, true);
                player->AddDelayedTeleport(14000, 1220, Position(3486.392f, 3533.4429f, 821.548f, 3.4357f));
                                //ID - 52391 ????
                                    //100990
                                    //ID - 218564 ??????
                                    //ID - 198941 ??????
                                    //ID - 217343 ???????????????
                    
                    
                    }
             }
         }
     };

struct npc_apata_highmountain_100990 : public ScriptedAI
 {
    npc_apata_highmountain_100990(Creature * creature) : ScriptedAI(creature) {  }
    
        void Reset() override
         {
        me->Say(114943);
        if (Player* player = me->SelectNearestPlayer())
             {
            player->AddDelayedConversation(2000, 2674);
            player->AddDelayedConversation(12000, 2676);
            player->AddDelayedConversation(10000, 2677);
            }
         me->DespawnOrUnsummon(30000);
        }
     };

struct npc_apata_highmountain_110821 : public ScriptedAI
 {
    npc_apata_highmountain_110821(Creature * creature) : ScriptedAI(creature) { }
    
        void sQuestAccept(Player * player, Quest const* quest) override
         {
        if (quest->GetQuestId() == QUEST_THE_SPEAR_IN_THE_SHADOW)
             {
            me->Say(119330);
            player->KilledMonsterCredit(100111);
            player->AddDelayedTeleport(2000, 1511, Position(3364.687f, 1919.254f, 0.0919f, 5.644843f));
            }
         }
    
        void MoveInLineOfSight(Unit * who) override
         {
        if (Player* player = who->ToPlayer())
             if (me->IsWithinDist(player, 15.0f, false) && player->HasQuest(QUEST_THE_EAGLE_SPIRIT_S_BLESSING))
             player->KilledMonsterCredit(110937);
        }
     };

struct npc_degar_bloodtotem_110685 : public ScriptedAI
 {
    npc_degar_bloodtotem_110685(Creature * creature) : ScriptedAI(creature) { }
    
        void Reset() override
         {
        if (Creature* apata = me->FindNearestCreature(110821, 100.f))
             apata->AddAura(220554);
        
            if (Creature* ohnahra = me->FindNearestCreature(110901, 100.f))
             ohnahra->AddAura(220557);
        }
    
        enum degar_Spells
         {
        SPELL_WRATH = 9739,
            SPELL_CALL_WEIRD_GROWTH = 223019,
            };
    
        void JustDied(Unit* /*killer*/) override
         {
        if (Creature* apata = me->FindNearestCreature(110821, 100.f))
             {
            apata->RemoveAurasDueToSpell(220554);
            apata->SetStandState(UnitStandStateType::UNIT_STAND_STATE_STAND);
            apata->Say(119324);
            
                me->GetScheduler().Schedule(Milliseconds(6000), [apata](TaskContext context)
                     {
                if (!apata->SelectNearestPlayers(25.f, true).empty())
                     for (auto player : apata->SelectNearestPlayers(25.f, true))
                     player->CastSpell(player, 220791, true);
                apata->Say(119328);
                });
            }
         if (Creature* ohnahra = me->FindNearestCreature(110901, 100.f))
             {
            ohnahra->RemoveAurasDueToSpell(220557);
            ohnahra->SetStandState(UnitStandStateType::UNIT_STAND_STATE_STAND);
            ohnahra->AddNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
            }
         }
    
        void EnterCombat(Unit* /*attacker*/) override
         {
        me->Yell(119073);
        events.ScheduleEvent(SPELL_WRATH, 5s);
        events.ScheduleEvent(SPELL_CALL_WEIRD_GROWTH, 15s);
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
        case SPELL_WRATH:
            {
                DoCast(SPELL_WRATH);
                events.Repeat(5s);
                break;
                }
         case SPELL_CALL_WEIRD_GROWTH:
            {
                DoCast(SPELL_CALL_WEIRD_GROWTH);
                events.Repeat(30s);
                break;
                }
             }
         DoMeleeAttackIfReady();
        }
     };

void AddSC_class_hall_hunter()
{
    RegisterCreatureAI(npc_snowfeather_100786);
    RegisterCreatureAI(npc_emmarel_shadewarden_102478);
    new hunter_playerchoice();
    RegisterCreatureAI(npc_grif_wildheart_104381);
    RegisterCreatureAI(npc_huey_106235);
    RegisterCreatureAI(npc_emmarel_shadewarden_102578);
    RegisterCreatureAI(npc_emmarel_shadewarden_102574);
    RegisterCreatureAI(npc_courier_larkspur_103741);
    RegisterCreatureAI(npc_silver_covenant_hippogryph_102177);
    RegisterCreatureAI(npc_ranger_adronis_102007);
    RegisterCreatureAI(npc_vereesa_windrunner_100190);
    RegisterCreatureAI(npc_portal_to_niskara_104835);
    
    RegisterCreatureAI(npc_apata_highmountain_104382);
    RegisterCreatureAI(npc_highmountain_hippogryph_100967);
    RegisterCreatureAI(npc_apata_highmountain_100990);
    RegisterCreatureAI(npc_apata_highmountain_110821);
    RegisterCreatureAI(npc_degar_bloodtotem_110685);
}
