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
#include "LFGMgr.h"
enum
{
    PLAYER_CHOICE_PRIEST_HOLY = 532,
    PLAYER_CHOICE_PRIEST_SHADOW = 533,
    PLAYER_CHOICE_PRIEST_DISCIPLINE = 534,
    SPELL_WEAPONS_OF_LEGEND_PLAYER_CHOICE = 199700,
    PLAYER_CHOICE_PRIEST_SELECTION = 248,

    QUEST_HOLY_CHOSEN = 40708,
    QUEST_SHADOW_CHOSEN = 40707,
    QUEST_DISCIPLINE_CHOSEN = 40709,

    QUEST_WEAPONS_OF_LEGEND = 40706,
    QUEST_ONE_MORE_LEGEND = 43935,
    QUEST_MORE_WEAPONS_OF_LEGEND = 44407,

    ///Priest Quest
    QUEST_PRIESTLY_MATTERS = 40705,

    //HOLY
    QUEST_THE_VINDICATORS_PLEA = 41957,
    QUEST_HOUSE_CALL = 41966,
    QUEST_OUT_OF_THE_DARKNESS = 41967,
    QUEST_SALVATION_FROM_ON_HIGH = 41993,
    QUEST_RETURN_OF_THE_LIGHT = 42074,
    LFG_DUNGEON_SCENARIO_RETURN_OF_THE_LIGHT = 1243,
    SPELL_SALVATION_FROM_ON_HIGH = 210016,
    //SHADOW
    QUEST_BLADE_IN_TWILIGHT = 40710,
    //DISCIPLINE
    QUEST_THE_LIGHTS_WRATH = 41625,
    QUEST_A_GIFT_OF_TIME = 41632,

    QUEST_THE_LIGHT_AND_THE_VOID = 40938,
};

struct npc_hooded_priestess : public ScriptedAI
{
    npc_hooded_priestess(Creature* creature) : ScriptedAI(creature) { }

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
            me->Say(103668, owner);
        }
    }

    void sQuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_PRIESTLY_MATTERS)
        {
            me->Say(103669, player);
            me->DespawnOrUnsummon(5000);
        }
    }
};
//101314 110564 
struct npc_alonsus_faol_101314 : public ScriptedAI
{
    npc_alonsus_faol_101314(Creature* creature) : ScriptedAI(creature) { }

    void sQuestAccept(Player* player, Quest const* quest) override
    {
        if ((quest->GetQuestId() == QUEST_WEAPONS_OF_LEGEND) || (quest->GetQuestId() == QUEST_ONE_MORE_LEGEND) || (quest->GetQuestId() == QUEST_MORE_WEAPONS_OF_LEGEND))
        {
            player->CastSpell(player, SPELL_WEAPONS_OF_LEGEND_PLAYER_CHOICE, true);
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
            if (me->IsWithinDist(player, 15.0f, false))
            {
                if (!IsLock && player->HasQuest(QUEST_THE_LIGHT_AND_THE_VOID) && !player->GetQuestObjectiveData(QUEST_THE_LIGHT_AND_THE_VOID, 2))
                {
                    IsLock = true;
                    me->Say(104902);
                    me->GetScheduler().Schedule(Milliseconds(8000), [](TaskContext context)
                    {
                        GetContextCreature()->Say(104904);
                    }).Schedule(Milliseconds(16000), [player](TaskContext context)
                    {
                        GetContextCreature()->Say(104905);
                        player->KilledMonsterCredit(102652);
                    }).Schedule(Milliseconds(24000), [](TaskContext context)
                    {
                        GetContextCreature()->Say(104908);
                    }).Schedule(Milliseconds(28000), [player](TaskContext context)
                    {
                        GetContextCreature()->Say(104990);
                        player->KilledMonsterCredit(102653);
                    }).Schedule(Milliseconds(32000), [](TaskContext context)
                    {
                        GetContextCreature()->Say(105019);
                    }).Schedule(Milliseconds(42000), [](TaskContext context)
                    {
                        GetContextCreature()->Say(105022);
                    }).Schedule(Milliseconds(50000), [](TaskContext context)
                    {
                        GetContextCreature()->Say(105023);
                    }).Schedule(Milliseconds(60000), [player](TaskContext context)
                    {
                        GetContextCreature()->Say(105025);
                        player->KilledMonsterCredit(102654);
                    }).Schedule(Milliseconds(65000), [player](TaskContext context)
                    {
                        GetContextCreature()->Say(105027);
                    });
                    SetUnlock(180000);
                }
            }
        }
    }
};


class priest_playerchoice : public PlayerScript
{
public:
    priest_playerchoice() : PlayerScript("priest_playerchoice") { }

    void OnQuestStatusChange(Player* player, uint32 /*questId*/)
    {
        if (player->getClass() == CLASS_PRIEST || player->getLevel() >= 98)
            OnCheckPhase(player);
    }

    void OnCheckPhase(Player* player)
    {
        if (player->GetAreaId() == 4183)
        {
         //   if (player->CheckQuestStatus(41626, CHECK_QUEST_TAKEN_AND_COMPLETE_AND_REWARDED))
                PhasingHandler::AddPhase(player, 6068);
        }
    }

    void OnPlayerChoiceResponse(Player* player, uint32 choiceId, uint32 responseId)
    {
        if (choiceId != PLAYER_CHOICE_PRIEST_SELECTION)
            return;

        if (player->HasQuest(QUEST_WEAPONS_OF_LEGEND))
            player->KilledMonsterCredit(100583);
        if (player->HasQuest(QUEST_ONE_MORE_LEGEND))
            player->KilledMonsterCredit(111919);
        if (player->HasQuest(QUEST_MORE_WEAPONS_OF_LEGEND))
            player->KilledMonsterCredit(113817);

        switch (responseId)
        {
        case PLAYER_CHOICE_PRIEST_HOLY:
            if (player->GetQuestStatus(QUEST_THE_VINDICATORS_PLEA) == QUEST_STATUS_NONE)
                if (const Quest* quest_1 = sObjectMgr->GetQuestTemplate(QUEST_THE_VINDICATORS_PLEA))
                    player->AddQuest(quest_1, nullptr);
            break;
        case PLAYER_CHOICE_PRIEST_SHADOW:
            if (player->GetQuestStatus(QUEST_BLADE_IN_TWILIGHT) == QUEST_STATUS_NONE)
                if (const Quest* quest_2 = sObjectMgr->GetQuestTemplate(QUEST_BLADE_IN_TWILIGHT))
                    player->AddQuest(quest_2, nullptr);
            player->TeleportTo(1539, Position(2039.677f, 2395.495f, 127.467f, 0.9153f));
            break;
        case PLAYER_CHOICE_PRIEST_DISCIPLINE:
            if (player->GetQuestStatus(QUEST_THE_LIGHTS_WRATH) == QUEST_STATUS_NONE)
                if (const Quest* quest_2 = sObjectMgr->GetQuestTemplate(QUEST_THE_LIGHTS_WRATH))
                    player->AddQuest(quest_2, nullptr);
            break;
        default:
            break;
        }
    }
};

struct npc_calia_102343 : public ScriptedAI
{
    npc_calia_102343(Creature* creature) : ScriptedAI(creature) { }

    void sGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId)
    {
        CloseGossipMenuFor(player);
        if (player->HasQuest(QUEST_PRIESTLY_MATTERS) && !IsLock)
        {
            IsLock = true;
            if (Creature* faol = me->FindNearestCreature(101314, 50.0f))
            {
                player->KilledMonsterCredit(102340);
                faol->Say(104642);
                me->GetScheduler().Schedule(5s, [this, faol](TaskContext /*context*/)
                {
                    faol->Say(104643);
                }).Schedule(10s, [this, faol, player](TaskContext /*context*/)
                {
                    faol->Say(104644, player);
                    player->KilledMonsterCredit(102341);
                });
            }
            SetUnlock(60000);
        }
    }
};

struct npc_brother_larry_105769 : public ScriptedAI
{
    npc_brother_larry_105769(Creature* creature) : ScriptedAI(creature) { }

    void sGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId)
    {
        CloseGossipMenuFor(player);
        player->AddDelayedTeleport(4000, 1220, -835.32f, 4276.66f, 746.252f, 1.05569f);
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Player* player = who->ToPlayer())
        {
            if (me->IsWithinDist(player, 25.0f, false) && !IsLock)
            {
                IsLock = true;
                me->Say(122599);
                SetUnlock(60000);
            }
        }
    }
private:

    TaskScheduler _scheduler;
};

struct npc_archmage_kalec_105081 : public ScriptedAI
{
    npc_archmage_kalec_105081(Creature* creature) : ScriptedAI(creature) { }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Player* player = who->ToPlayer())
        {
            if (me->IsWithinDist(player, 15.0f, false))
            {
                if (player->HasQuest(41625))
                    player->ForceCompleteQuest(41625);
                if (player->HasQuest(42001))
                    player->ForceCompleteQuest(42001);
            }
        }
    }
};

struct npc_alonsus_faol_102363 : public ScriptedAI
{
    npc_alonsus_faol_102363(Creature* creature) : ScriptedAI(creature) {  }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Player* player = who->ToPlayer())
        {
            if (!IsLock && player->HasQuest(QUEST_A_GIFT_OF_TIME) && me->IsWithinDist(player, 15.0f, false))
            {
                IsLock = true;
                me->Say(104645);

                me->GetScheduler().Schedule(Milliseconds(1000), [this](TaskContext context)
                {
                    if (Creature* target = me->FindNearestCreature(109776, 50.0f))
                        target->Say(104646);
                });
                me->GetScheduler().Schedule(Milliseconds(3000), [this](TaskContext context)
                {
                    if (Creature* target = me->FindNearestCreature(101313, 50.0f))//110557
                        target->Say(104647);
                });
                SetUnlock(180000);
            }
        }
    }
};


struct npc_prophet_velen_101313 : public ScriptedAI
{
    npc_prophet_velen_101313(Creature* creature) : ScriptedAI(creature) { }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

    void MovementInform(uint32 /*type*/, uint32 id) override
    {
        switch (id)
        {
        case 1:
            _scheduler.Schedule(250ms, [this](TaskContext /*context*/)
            {
                me->GetMotionMaster()->MovePoint(2, Position(-718.97f, 4479.5449f, 731.7789f, 3.30242f), true);
            });
            break;
        case 2:
            me->Say(104674);
            _scheduler.Schedule(250ms, [this](TaskContext /*context*/)
            {
                me->GetMotionMaster()->MovePoint(3, Position(-737.7f, 4474.815f, 731.8628f, 3.388814f), true);
            });
            break;
        case 3:
            _scheduler.Schedule(250ms, [this](TaskContext /*context*/)
            {
                me->GetMotionMaster()->MovePoint(4, Position(-756.683f, 4471.609f, 733.161f, 3.369179f), true);
            });
            break;
        case 4:
            me->Say(104675);
            _scheduler.Schedule(250ms, [this](TaskContext /*context*/)
            {
                me->GetMotionMaster()->MovePoint(5, Position(-771.4f, 4468.2f, 733.935f, 3.799578f), true);
            });
            break;
        case 5:
            me->Say(104676);
            _scheduler.Schedule(250ms, [this](TaskContext /*context*/)
            {
                me->GetMotionMaster()->MovePoint(6, Position(-805.247f, 4437.453f, 738.229f, 3.882045f), true);
            });
            break;
        case 6:
            if (Player* player = ObjectAccessor::GetPlayer(*me, mPlayerGUID))
            {
                player->KilledMonsterCredit(102466);
                player->KilledMonsterCredit(102465);
                player->TeleportTo(1629, Position(1249.25f, 1344.14f, 185.0f, 0.009250244f));
            }
            me->NearTeleportTo(me->GetHomePosition());
            break;
        default:
            break;
        }
    }

    void sQuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_THE_LIGHT_AND_THE_VOID)
        {
            mPlayerGUID = player->GetGUID();
            me->Say(104673);
            me->GetMotionMaster()->MovePoint(1, Position(-701.413f, 4482.1918f, 729.861f, 4.4726f), true);
        }
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Player* player = who->ToPlayer())
        {
            if (me->IsWithinDist(player, 15.0f, false))
            {
                //if (!IsLock && player->HasQuest(QUEST_H_THE_SPEAKERS_PERSPECTIVE))
                //{
                //    IsLock = true;

                //}
            }
        }
    }
private:
    TaskScheduler _scheduler;
    ObjectGuid mPlayerGUID = ObjectGuid::Empty;
};
//105697 209441 npc_spellclick_spells quest 41967
//QUEST_THE_VINDICATORS_PLEA QUEST_HOUSE_CALL 
struct npc_vindicator_boros_105602 : public ScriptedAI
{
    npc_vindicator_boros_105602(Creature* creature) : ScriptedAI(creature) { }

    void sQuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_HOUSE_CALL)
        {
            me->Say(108645);
            IsLock = false;
        }
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Player* player = who->ToPlayer())
        {
            if (me->IsWithinDist(player, 15.0f, false))
            {
                if (!IsLock && player->HasQuest(QUEST_THE_VINDICATORS_PLEA))
                {
                    IsLock = true;
                    player->TalkedToCreature(105769, me->GetGUID());
                    me->Say(108556);
                    SetUnlock(120000);
                }
            }
        }
    }
};

struct npc_defender_barrem_105586 : public ScriptedAI
{
    npc_defender_barrem_105586(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        DoCastSelf(209190, true);
        me->DisableHealthRegen();
        me->SetHealth(uint64(me->GetHealth() * 0.45f));
        IsLock = false;
    }

    void sQuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_OUT_OF_THE_DARKNESS)
        {
            if (Creature* boros = me->FindNearestCreature(105602, 25.f, true))
            {
                boros->Say(108657, player);
                boros->GetScheduler().Schedule(Milliseconds(1000), [boros](TaskContext context)
                {
                    boros->Say(108658);
                });
            }
        }
    }

    void DoAction(int32 param)
    {
        me->RemoveAurasDueToSpell(209190);
        me->ReenableHealthRegen();
        if (Creature* boros = me->FindNearestCreature(105602, 25.f, true))
            boros->Say(108597);
    }

    void SpellHit(Unit* caster, SpellInfo const* /*spell*/) override
    {
        if (me->GetHealthPct() > 50.f)
        {
            if (Player* player = caster->ToPlayer())
            {
                if (!IsLock && player->HasQuest(QUEST_HOUSE_CALL))
                {
                    IsLock = true;

               /*     _sceneHelper.Clear();
                    _sceneHelper.SetDefaultActorGuid(me->GetGUID());
                    _sceneHelper.SetDefaultPlayerGuid(player->GetGUID());
                    _sceneHelper.AddSceneActionTalk(0);
                    _sceneHelper.AddSceneActionTalk(1, 5000);
                    _sceneHelper.AddSceneActionTalk(2, 5000);
                    _sceneHelper.AddSceneActionTalk(3, 5000);
                    _sceneHelper.AddSceneActionTalk(4, 5000);
                    _sceneHelper.AddSceneActionKillCreditMonster(105586, 1, 500);
                    _sceneHelper.AddSceneActionAI(1);

                    _sceneHelper.Activate();*/
                    SetUnlock(120000);
                }
            }
        }
    }
};
//QUEST_OUT_OF_THE_DARKNESS
struct npc_vindicator_boros_105795 : public ScriptedAI
{
    npc_vindicator_boros_105795(Creature* creature) : ScriptedAI(creature) { }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Player* player = who->ToPlayer())
        {
            if (me->IsWithinDist(player, 15.0f, false))
            {
                if (!IsLock && player->HasQuest(QUEST_OUT_OF_THE_DARKNESS))
                {
                    IsLock = true;
                    me->Say(108730, player);
                    SetUnlock(120000);
                }
            }
        }
    }
};
//QUEST_SALVATION_FROM_ON_HIGH
struct npc_vindicator_boros_105873 : public ScriptedAI
{
    npc_vindicator_boros_105873(Creature* creature) : ScriptedAI(creature) { }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Player* player = who->ToPlayer())
        {
            if (me->IsWithinDist(player, 15.0f, false))
            {
                if (!IsLock && player->HasQuest(QUEST_OUT_OF_THE_DARKNESS))
                {
                    IsLock = true;
                    me->Say(108775, player);
                    SetUnlock(120000);
                }
            }
        }
    }
};

struct npc_alora_105649 : public ScriptedAI
{
    npc_alora_105649(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        me->DisableHealthRegen();
        me->SetHealth(uint64(me->GetHealth() * 0.45f));
        me->RemoveAurasDueToSpell(96733);
        me->SetStandState(UnitStandStateType::UNIT_STAND_STATE_SLEEP);
    }

    void OnSpellClick(Unit* clicker, bool& /*result*/)
    {
        if (Player* player = clicker->ToPlayer())
        {
            if (!IsLock && player->HasQuest(QUEST_OUT_OF_THE_DARKNESS))
            {
                IsLock = true;
                me->SetStandState(UnitStandStateType::UNIT_STAND_STATE_STAND);
                me->Say(108465);
                player->KilledMonsterCredit(me->GetEntry());
                me->ReenableHealthRegen();
                SetUnlock(120000);
            }
        }
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Player* player = who->ToPlayer())
            if (me->IsWithinDist(player, 15.0f, false))
                if (player->HasQuest(QUEST_OUT_OF_THE_DARKNESS))
                    me->AddNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
    }
};

struct npc_alora_105684 : public ScriptedAI
{
    npc_alora_105684(Creature* creature) : ScriptedAI(creature) { }

    void sQuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_SALVATION_FROM_ON_HIGH)
            player->CastSpell(player, SPELL_SALVATION_FROM_ON_HIGH, true);
    }
};

struct npc_jace_darkweaver_105890 : public ScriptedAI
{
    npc_jace_darkweaver_105890(Creature* creature) : ScriptedAI(creature) { }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Player* player = who->ToPlayer())
        {
            if (me->IsWithinDist(player, 15.0f, false))
            {
                if (player->HasQuest(QUEST_SALVATION_FROM_ON_HIGH))
                {
                    player->KilledMonsterCredit(me->GetEntry());
                    if (!IsLock)
                    {
                        IsLock = true;
                        Talk(0);
                        me->GetScheduler().Schedule(Milliseconds(5000), [this](TaskContext context)
                        {
                            Talk(1);
                        });
                    }
                }
            }
        }
    }
};

//QUEST_RETURN_OF_THE_LIGHT
struct npc_jace_darkweaver_106011 : public ScriptedAI
{
    npc_jace_darkweaver_106011(Creature* creature) : ScriptedAI(creature) { }

    void sQuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_RETURN_OF_THE_LIGHT)
        {
            me->Say(108952);
            //move to change phase
        }
    }
};

struct npc_legion_portal_106065 : public ScriptedAI
{
    npc_legion_portal_106065(Creature* creature) : ScriptedAI(creature) { }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Player* player = who->ToPlayer())
        {
            if (me->IsWithinDist(player, 15.0f, false) && player->HasQuest(QUEST_RETURN_OF_THE_LIGHT))
            {
                player->KilledMonsterCredit(106033);
                sLFGMgr->JoinLfg(player, LFG_DUNGEON_SCENARIO_RETURN_OF_THE_LIGHT);//1243
                //player->TeleportTo(1489, Position(-37.06f, 1163.48f, -74.35f, 0.4761258f));
            }
        }
    }
};
void AddSC_class_hall_priest()
{
    RegisterCreatureAI(npc_hooded_priestess);
    RegisterCreatureAI(npc_alonsus_faol_101314);
    RegisterCreatureAI(npc_calia_102343);
    new priest_playerchoice();
    RegisterCreatureAI(npc_brother_larry_105769);
    RegisterCreatureAI(npc_archmage_kalec_105081);
    RegisterCreatureAI(npc_alonsus_faol_102363);
    RegisterCreatureAI(npc_prophet_velen_101313);

    RegisterCreatureAI(npc_vindicator_boros_105602);
    RegisterCreatureAI(npc_defender_barrem_105586);
    RegisterCreatureAI(npc_vindicator_boros_105795);
    RegisterCreatureAI(npc_vindicator_boros_105873);
    RegisterCreatureAI(npc_alora_105649);
    RegisterCreatureAI(npc_jace_darkweaver_106011);
    RegisterCreatureAI(npc_alora_105684);
    RegisterCreatureAI(npc_jace_darkweaver_105890);
    RegisterCreatureAI(npc_legion_portal_106065);
}
