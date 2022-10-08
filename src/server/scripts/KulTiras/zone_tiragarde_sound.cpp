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

#include "Conversation.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptedEscortAI.h"
#include "ScriptedFollowerAI.h"
#include "ScriptedGossip.h"
#include "ScriptMgr.h"
#include "TemporarySummon.h"
#include "Vehicle.h"
#include "PhasingHandler.h"

enum eTiragardeQuests
{
    QUEST_DAUGHTER_OF_THE_SEA = 51341,

    QUEST_OUT_LIKE_FLYNN = 47098,
    KILL_CREDIT_GET_DRESSED = 138554,
    KILL_CREDIT_PULL_LEVER = 138553,
    KILL_CREDIT_CELL_BLOCK_DOOR = 137923,

    QUEST_GET_YOUR_BEARINGS = 47099,
    QUEST_THE_OLD_KNIGHT = 46729,
    QUEST_NATION_DIVIDED = 47189,
    QUEST_NATION_UNITED = 52151,
};

enum Intro
{
    SPELL_PROUDMOORE_KEEP_ESCORT        = 269772,
    SPELL_LADY_KATHERINE_MOVIE          = 241525,

    SPELL_TELEPORT_TO_TOL_DAGOR         = 241526,
    SPELL_PRISONER                      = 272512,
    SPELL_TOL_DAGOR_WAKE_UP             = 270081,

    SPELL_PUNCH_FLYNN                   = 264918,
    SPELL_FLYNN_KNOCKOUT_JAILER         = 246555,
    SPELL_SUMMON_FLYNN_ESCORT           = 246931,

    SPELL_SCENE_FLYNN_JAILBREAK         = 246821,
    SPELL_SCENE_GETAWAY_BOAT_TRIGGER    = 281331,
    SPELL_SCENE_NATION_DIVIDED          = 269191,

    SPELL_GETAWAY_CONVERSATION_1        = 247230,
    SPELL_GETAWAY_CONVERSATION_2        = 247275,

    SPELL_MAINTAIN_TAELIA_SUMMON        = 247532,
    SPELL_SCENE_OLD_KNIGHT              = 271234,

    NPC_FLYNN_BEGIN                     = 121239,
    NPC_FLYNN_ESCORT                    = 124311,
    NPC_FLYNN_ESCAPE                    = 124363,
    NPC_ASHVANE_JAILER_EVENT            = 124022,
    NPC_TAELIA                          = 124356,
    NPC_GETAWAY_BOAT_BOARDED            = 124030,
    NPC_TAELIA_GET_YOUR_BEARINGS        = 124630,
    NPC_CYRUS_CRESTFALL                 = 122370,

    GOB_PRISON_BARS                     = 281878,
    GOB_PRISON_GATE                     = 301088,
    GOB_CELL_BLOCK_GATE                 = 281902,

    MOVIE_LADY_KATHERINE                = 859,
};

// 120922 - Lady Jaina Proudmoore
struct npc_jaina_boralus_intro : public ScriptedAI
{
    npc_jaina_boralus_intro(Creature* creature) : ScriptedAI(creature) { }

    void sQuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->ID == QUEST_DAUGHTER_OF_THE_SEA)
            player->CastSpell(player, SPELL_PROUDMOORE_KEEP_ESCORT, true);
    }
};

// 1954
class scene_jaina_to_proudmoore_keep : public SceneScript
{
public:
    scene_jaina_to_proudmoore_keep() : SceneScript("scene_jaina_to_proudmoore_keep") { }

    void OnSceneEnd(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/) override
    {
        player->AddMovieDelayedAction(MOVIE_LADY_KATHERINE, [player]()
        {
            player->CastSpell(player, SPELL_TELEPORT_TO_TOL_DAGOR, true);
            player->CastSpell(player, SPELL_PRISONER, true);
            player->CastSpell(player, SPELL_TOL_DAGOR_WAKE_UP, true);
        });

        player->CastSpell(player, SPELL_LADY_KATHERINE_MOVIE, true);
    }
};

// Prisoner - 272512
class aura_tol_dagor_intro_prisoner : public AuraScript
{
    PrepareAuraScript(aura_tol_dagor_intro_prisoner);

    void HandleApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->RemoveGameObjectByEntry(GOB_PRISON_BARS);
        GetTarget()->RemoveGameObjectByEntry(GOB_PRISON_GATE);

        GetTarget()->SummonGameObject(GOB_PRISON_BARS, 145.772995f, -2707.709961f, 28.818899f, 0.942667f, QuaternionData(0.f, 0.f, 0.454075f, 0.890964f), 0, true);
        GetTarget()->SummonGameObject(GOB_PRISON_GATE, 146.242996f, -2699.399902f, 28.877800f, 5.663670f, QuaternionData(0.f, 0.f, -0.304828f, 0.952407f), 0, true);
    }

    void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->RemoveGameObjectByEntry(GOB_PRISON_BARS);
        GetTarget()->RemoveGameObjectByEntry(GOB_PRISON_GATE);
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(aura_tol_dagor_intro_prisoner::HandleApply, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_DONE, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
        OnEffectRemove += AuraEffectRemoveFn(aura_tol_dagor_intro_prisoner::HandleRemove, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_DONE, AURA_EFFECT_HANDLE_REAL);
    }
};

// 47098
struct quest_out_like_flynn : public QuestScript
{
    quest_out_like_flynn() : QuestScript("quest_out_like_flynn") { }

    // Called when a quest objective data change
    void OnQuestObjectiveChange(Player* player, Quest const* /*quest*/, QuestObjective const& objective, int32 /*oldAmount*/, int32 /*newAmount*/) override
    {
        if (objective.ObjectID == KILL_CREDIT_GET_DRESSED)
            player->RemoveAurasDueToSpell(SPELL_PRISONER);
        else if (objective.ObjectID == KILL_CREDIT_PULL_LEVER)
        {
            player->RemoveGameObjectByEntry(GOB_PRISON_BARS);
            player->RemoveGameObjectByEntry(GOB_PRISON_GATE);
        }
    }
};

// 121239 - Flynn Fairwind
struct npc_flynn_fairwind : public ScriptedAI
{
    npc_flynn_fairwind(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        if (me->GetAreaId() != 8978)
            me->AddNpcFlag(UNIT_NPC_FLAG_GOSSIP);
        me->SetReactState(REACT_PASSIVE);
        me->AddUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
    };

    enum FlynnTalks
    {
        TALK_HERES_PLAN = 6,
        TALK_HIT_ME = 7,
        TALK_COME_ON_HIT_ME = 8,
        TALK_DONT_SHY_HIT_ME = 9,
        TALK_YOU_BRUTE = 10,
        TALK_GUARD = 11,
        TALK_HIT_THAT_LEVER = 12,
    };

    enum GuardTalks
    {
        TALK_WHATS_GOING_ON = 0,
        TALK_STOP_RIGHT_HERE = 1,
        TALK_WHAT = 2,
        TALK_NO = 3,
    };

    void sQuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->ID == QUEST_OUT_LIKE_FLYNN)
        {
            if (Creature* flynn = player->SummonCreature(me->GetEntry(), me->GetPosition(), TEMPSUMMON_CORPSE_DESPAWN, 0, 0, true))
            {
                flynn->AI()->SetGUID(player->GetGUID());
                me->DestroyForPlayer(player);
            }
        }
    }

    void SetGUID(ObjectGuid guid, int32 /*action*/) override
    {
        m_playerGUID = guid;
        me->RemoveNpcFlag(UNIT_NPC_FLAG_QUESTGIVER);
        me->SetAIAnimKitId(0);

        if (Creature* ashvaneJailer = me->SummonCreature(NPC_ASHVANE_JAILER_EVENT, 144.839996f, -2702.790039f, 28.961100f, 0.799371f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 2000, true))
            m_ashvaneJailerGUID = ashvaneJailer->GetGUID();

        me->GetScheduler().Schedule(1s, [this](TaskContext /*context*/)
        {
            me->GetMotionMaster()->MoveJump(142.033f, -2715.19f, 29.1884f, 0.0f, 19.2911f, 19.2911f);
        })
            .Schedule(2s, [this](TaskContext /*context*/)
        {
            me->GetMotionMaster()->MovePoint(2, 145.070679f, -2710.949463f, 29.187674f);
        })
            .Schedule(3s, [this](TaskContext /*context*/)
        {
            me->SetFacingToObject(GetPlayer());
            Talk(TALK_HERES_PLAN, GetPlayer());
        })
            .Schedule(5s, [this](TaskContext /*context*/)
        {
            Talk(TALK_HIT_ME, GetPlayer());
            me->AddNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
        });
    }

    void SpellHit(Unit* caster, SpellInfo const* spell) override
    {
        if (spell->Id != SPELL_PUNCH_FLYNN)
            return;

        me->RemoveNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
        me->HandleEmoteCommand(EMOTE_ONESHOT_BEG);
        Talk(TALK_YOU_BRUTE);

        caster->ToPlayer()->KilledMonsterCredit(me->GetEntry());

        if (Creature* ashvaneJailer = GetAshvaneJailer())
        {
            me->GetScheduler().Schedule(2s, [this](TaskContext /*context*/)
            {
                Talk(TALK_GUARD);
                me->SetStandState(UNIT_STAND_STATE_DEAD);
            });

            ashvaneJailer->GetScheduler().Schedule(3s, [](TaskContext context)
            {
                GetContextUnit()->GetMotionMaster()->MovePoint(1, 147.070480f, -2705.972412f, 29.189432f);
            })
                .Schedule(4s, [](TaskContext context)
            {
                GetContextUnit()->SetFacingTo(4.111071f);
            })
                .Schedule(5s, [](TaskContext context)
            {
                GetContextCreature()->AI()->Talk(TALK_WHATS_GOING_ON);
                GetContextUnit()->HandleEmoteCommand(EMOTE_ONESHOT_EXCLAMATION);
            })
                .Schedule(6s, [](TaskContext context)
            {
                GetContextUnit()->HandleEmoteCommand(EMOTE_ONESHOT_USE_STANDING);
            })
                .Schedule(7s, [](TaskContext context)
            {
                if (GameObject* gob = GetContextUnit()->GetGameObjectByEntry(GOB_PRISON_BARS))
                    gob->UseDoorOrButton();
            })
                .Schedule(8s, [](TaskContext context)
            {
                GetContextCreature()->AI()->Talk(TALK_STOP_RIGHT_HERE);
                GetContextUnit()->GetMotionMaster()->MovePoint(2, 143.408783f, -2710.396240f, 29.187752f);
                // Set hostile
            });

            me->GetScheduler().Schedule(9s, [this, ashvaneJailer](TaskContext /*context*/)
            {
                me->SetStandState(UNIT_STAND_STATE_STAND);
                ashvaneJailer->AI()->Talk(TALK_WHAT);
            })
                .Schedule(10s, [this, ashvaneJailer](TaskContext /*context*/)
            {
                me->CastSpell(nullptr, SPELL_FLYNN_KNOCKOUT_JAILER, false);
                ashvaneJailer->AI()->Talk(TALK_NO);
            })
                .Schedule(11s, [this](TaskContext /*context*/)
            {
                me->GetMotionMaster()->MovePoint(3, 165.596573f, -2707.874756f, 28.877989f);
            })
                .Schedule(14s, [this, ashvaneJailer, caster](TaskContext /*context*/)
            {
                me->SetFacingTo(2.540090f);
                Talk(TALK_HIT_THAT_LEVER);
                caster->RemoveAura(SPELL_PRISONER);
            });
        }
    }

private:
    Player* GetPlayer() { return ObjectAccessor::GetPlayer(*me, m_playerGUID); }
    Creature* GetAshvaneJailer() { return ObjectAccessor::GetCreature(*me, m_ashvaneJailerGUID); }

    ObjectGuid m_playerGUID;
    ObjectGuid m_ashvaneJailerGUID;
};

// 271938 - Cell Block Lever
struct go_toldagor_cell_block_lever : public GameObjectAI
{
    go_toldagor_cell_block_lever(GameObject* go) : GameObjectAI(go) { }

    bool GossipHello(Player* player, bool /*isUse*/) override
    {
        player->CastSpell(player, SPELL_SCENE_FLYNN_JAILBREAK, true);
        player->UnsummonCreatureByEntry(NPC_FLYNN_BEGIN);
        return false;
    }
};

// 1735
class scene_flynn_jailbreak : public SceneScript
{
public:
    scene_flynn_jailbreak() : SceneScript("scene_flynn_jailbreak") { }

    void OnSceneEnd(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/) override
    {
        player->CastSpell(player, SPELL_SUMMON_FLYNN_ESCORT, true);
    }
};

// 124311 - Flynn Fairwind (Quest follower)
struct npc_flynn_fairwind_follower : public FollowerAI
{
    npc_flynn_fairwind_follower(Creature* creature) : FollowerAI(creature) { }

    void Reset() override
    {
        me->SetReactState(REACT_PASSIVE);
        me->SetLevel(120);
        me->AddUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
        me->GetScheduler().Schedule(1s, [this](TaskContext context)
        {
            if (me->FindNearestGameObject(GOB_CELL_BLOCK_GATE, 10.f))
            {
                SetFollowPaused(true);
                GetContextUnit()->GetMotionMaster()->MovePoint(1, 184.875366f, -2684.565918f, 29.504234f);
            }
            else
                context.Repeat();
        });

        me->GetScheduler().Schedule(2s, [this](TaskContext context)
        {
            if (me->FindNearestCreature(NPC_TAELIA, 40.f))
            {
                if (TempSummon* tempMe = me->ToTempSummon())
                    if (Unit* summoner = tempMe->GetSummoner())
                        if (Player* playerSummoner = summoner->ToPlayer())
                            playerSummoner->PlayConversation(8334);
            }
            else
                context.Repeat();
        });
    }

    void MovementInform(uint32 type, uint32 pointId) override
    {
        if (type != POINT_MOTION_TYPE || pointId != 1)
            return;

        me->SetFacingTo(5.698150f);

        me->GetScheduler().Schedule(1s, [this](TaskContext /*context*/)
        {
            me->HandleEmoteCommand(EMOTE_ONESHOT_USE_STANDING);
        })
            .Schedule(2s, [this](TaskContext /*context*/)
        {
            if (GameObject* door = me->FindNearestGameObject(GOB_CELL_BLOCK_GATE, 10.f))
            {
                door->UseDoorOrButton();
                door->DestroyForPlayer(GetLeaderForFollower());
            }
        })
            .Schedule(4s, [this](TaskContext /*context*/)
        {
            SetFollowPaused(false);

            if (GameObject* door = me->FindNearestGameObject(GOB_CELL_BLOCK_GATE, 10.f))
                door->UseDoorOrButton();

            if (Player* player = GetLeaderForFollower())
                player->KilledMonsterCredit(KILL_CREDIT_CELL_BLOCK_DOOR);
        });
    }
};

// 134922 - Kill Credit Enter Sewers
struct npc_tol_dagor_enter_sewer_credit : public ScriptedAI
{
    npc_tol_dagor_enter_sewer_credit(Creature* creature) : ScriptedAI(creature) { }

    void MoveInLineOfSight(Unit* unit) override
    {
        if (Player* player = unit->ToPlayer())
            if (player->GetDistance(me) < 5.0f)
                player->KilledMonsterCredit(me->GetEntry());
    }
};

// 8330
// 8333
// 8334
struct conversation_tol_dagor_inmate : public ConversationScript
{
    conversation_tol_dagor_inmate() : ConversationScript("conversation_tol_dagor_inmate") { }

    void OnConversationCreate(Conversation* conversation, Unit* creator) override
    {
        if (conversation->GetEntry() == 8334)
            if (Unit* taelia = creator->FindNearestCreature(NPC_TAELIA, 50.f))
                conversation->AddActor(taelia->GetGUID(), 0);

        if (Unit* flynn = creator->GetSummonedCreatureByEntry(NPC_FLYNN_ESCORT))
            conversation->AddActor(flynn->GetGUID(), conversation->GetEntry() == 8334 ? 1 : 0);
    }
};

// 124357 - Getaway Boat
struct npc_tol_dagor_getaway_boat : public ScriptedAI
{
    npc_tol_dagor_getaway_boat(Creature* creature) : ScriptedAI(creature) { }

    Position boatPath[6] = {
        { 240.6500f, -2812.950f, -0.052747f },
    { 245.9427f, -2807.717f,  0.052747f },
    { 272.6615f, -2792.370f, -0.052747f },
    { 353.6458f, -2743.795f,  0.052747f },
    { 366.6493f, -2540.583f, -0.052747f },
    { 396.1441f, -2403.012f, -0.052747f },
    };

    void IsSummonedBy(Unit* unit) override
    {
        if (Player* player = unit->ToPlayer())
        {
            me->SetReactState(REACT_PASSIVE);
            player->EnterVehicle(me, 1);
            player->KilledMonsterCredit(NPC_GETAWAY_BOAT_BOARDED);

            player->GetScheduler().Schedule(1s, [this, player](TaskContext /*context*/)
            {
                player->PlayConversation(5336);
                me->GetMotionMaster()->MoveSmoothPath(1, boatPath, 6, false, true);
            })
                .Schedule(36s, [player](TaskContext /*context*/)
            {
                // This specific scene is spawned at 0 0 0
                Position scenePos = Position();
                player->GetSceneMgr().PlayScene(1746, &scenePos, &ObjectGuid::Empty);
            });
        }
    }
};

// 5336
// 5340
struct conversation_tol_dagor_escape : public ConversationScript
{
    conversation_tol_dagor_escape() : ConversationScript("conversation_tol_dagor_escape") { }

    void OnConversationCreate(Conversation* conversation, Unit* creator) override
    {
        if (Vehicle* boat = creator->GetVehicle())
        {
            if (Unit* taelia = boat->GetPassenger(0))
                conversation->AddActor(taelia->GetGUID(), 0);

            // Flynn only speak during the first conversation
            if (conversation->GetEntry() == 5336)
                if (Unit* flynn = boat->GetPassenger(2))
                    conversation->AddActor(flynn->GetGUID(), 1);
        }
    }
};

// 1746
class scene_tol_dagor_getaway_boat : public SceneScript
{
public:
    scene_tol_dagor_getaway_boat() : SceneScript("scene_tol_dagor_getaway_boat") { }

    Position boatPath[4] =
    {
        { 880.6389f, -585.5486f, -0.02336364f },
    { 998.2083f, -575.0087f, -0.03875812f },
    { 1025.792f, -619.1180f, -0.03875812f },
    { 1040.462f, -631.7864f, -0.03875812f },
    };

    void OnSceneTriggerEvent(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/, std::string const& triggerName) override
    {
        if (triggerName == "TeleportToMarket")
        {
            if (Creature* vehicleBase = player->GetVehicleCreatureBase())
            {
                vehicleBase->NearTeleportTo(867.132f, -602.811f, -0.117634f, 1.536673f);
                vehicleBase->GetScheduler().Schedule(2s, [this, vehicleBase, player](TaskContext /*context*/)
                {
                    vehicleBase->GetMotionMaster()->MoveSmoothPath(2, boatPath, 4, false, true);

                    player->CastSpell(player, SPELL_GETAWAY_CONVERSATION_2, true);
                })
                    .Schedule(25s, [player, vehicleBase](TaskContext /*context*/)
                {
                    DespawnAndTeleportPlayer(player, vehicleBase);
                });
            }
        }
    }

    void OnSceneCancel(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/) override
    {
        if (Creature* vehicleBase = player->GetVehicleCreatureBase())
        {
            vehicleBase->GetScheduler().CancelAll();
            DespawnAndTeleportPlayer(player, vehicleBase);
        }
    }

private:
    static void DespawnAndTeleportPlayer(Player* player, Creature* vehicleBase)
    {
        player->ExitVehicle();
        player->NearTeleportTo(1053.48f, -627.64f, 0.54f, 2.523746f);
        vehicleBase->DespawnOrUnsummon();
    }
};

// 5360 Intro
// 5362 ferry
// 5365 bank
// 5366 fly
// 5375 tavern
// 9556 end
// 7605 harbormaster office
struct conversation_boralus_get_your_bearings : public ConversationScript
{
    conversation_boralus_get_your_bearings() : ConversationScript("conversation_boralus_get_your_bearings") { }

    void OnConversationCreate(Conversation* conversation, Unit* creator) override
    {
        if (Unit* taelia = creator->GetSummonedCreatureByEntry(NPC_TAELIA_GET_YOUR_BEARINGS))
            conversation->AddActor(taelia->GetGUID(), 0);
    }
};

// 124630 - Taelia (Get your bearings)
struct npc_taelia_get_your_bearings : public FollowerAI
{
    npc_taelia_get_your_bearings(Creature* creature) : FollowerAI(creature) { }

    struct ConvByKillStruct
    {
        ConvByKillStruct(uint8 objectiveIndex, uint32 killCreditID, uint32 conversationID) :
            ObjectiveIndex(objectiveIndex), KillCreditID(killCreditID), ConversationID(conversationID) { }

        uint8 ObjectiveIndex = 0;
        uint32 KillCreditID = 0;
        uint32 ConversationID = 0;
    };

    std::map<uint32, ConvByKillStruct> convByKillCredit =
    {
        { 124720, ConvByKillStruct(0, 124586, 5365) },
        { 124725, ConvByKillStruct(1, 124587, 5366) },
        { 135064, ConvByKillStruct(2, 124588, 5362) },
        { 135153, ConvByKillStruct(3, 124768, 5375) },
    };

    void IsSummonedBy(Unit* unit) override
    {
        me->AddNpcFlag(UNIT_NPC_FLAG_QUESTGIVER);

        if (Player* player = unit->ToPlayer())
        {
            player->PlayConversation(5360);
            ObjectGuid playerGuid = player->GetGUID();

            me->GetScheduler().Schedule(1s, [this, playerGuid](TaskContext context)
            {
                Player* player = ObjectAccessor::GetPlayer(*me, playerGuid);
                if (!player)
                    return;

                if (player->GetQuestStatus(QUEST_GET_YOUR_BEARINGS) == QUEST_STATUS_INCOMPLETE)
                {
                    bool justCompletedObjective = false;
                    for (auto itr : convByKillCredit)
                        if (player->FindNearestCreature(itr.first, 10.f))
                            if (!player->GetQuestObjectiveData(QUEST_GET_YOUR_BEARINGS, itr.second.ObjectiveIndex))
                            {
                                player->KilledMonsterCredit(itr.second.KillCreditID);
                                player->PlayConversation(itr.second.ConversationID);
                                justCompletedObjective = true;
                            }

                    if (justCompletedObjective && player->GetQuestStatus(QUEST_GET_YOUR_BEARINGS) == QUEST_STATUS_COMPLETE)
                    {
                        player->PlayConversation(9556);
                        me->AddNpcFlag(UNIT_NPC_FLAG_QUESTGIVER);
                    }
                }

                if (player->GetQuestStatus(QUEST_THE_OLD_KNIGHT) == QUEST_STATUS_INCOMPLETE)
                    if (!player->GetQuestObjectiveData(QUEST_THE_OLD_KNIGHT, 0))
                        if (player->FindNearestCreature(NPC_CYRUS_CRESTFALL, 20.f))
                        {
                            player->CastSpell(player, SPELL_SCENE_OLD_KNIGHT, true);
                            player->KilledMonsterCredit(NPC_CYRUS_CRESTFALL);
                            player->RemoveAurasDueToSpell(SPELL_MAINTAIN_TAELIA_SUMMON);
                            return;
                        }

                context.Repeat();
            });
        }
    }
};

// 1960
class scene_boralus_old_knight : public SceneScript
{
public:
    scene_boralus_old_knight() : SceneScript("scene_boralus_old_knight") { }

    void OnSceneEnd(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/) override
    {
        player->PlayConversation(8062);
    }
};

// 122370
class npc_cyrus_crestfall : public ScriptedAI
{
public:
    npc_cyrus_crestfall(Creature* creature) : ScriptedAI(creature) { }

    void sGossipSelect(Player* plr, uint32 /*menuId*/, uint32 /*gossipListId*/) override
    {
		if (plr->HasQuest(QUEST_THE_OLD_KNIGHT))
		{
            plr->KilledMonsterCredit(122370);
			plr->KilledMonsterCredit(137009);
			plr->PlayConversation(7653);
			CloseGossipMenuFor(plr);
		}

        /* quest - Send the Fleet 56043 */
        if (plr->HasQuest(56043))
        {
            CloseGossipMenuFor(plr);
            plr->ForceCompleteQuest(56043);
            Talk(0);

            plr->GetScheduler().Schedule(Seconds(3), [plr](TaskContext context)
            {
                // tele to nazjatar
                WorldLocation location(1718, 166.361f, -476.148f, -29.146f, 6.267f);
                plr->TeleportTo(location);

                // boat ride movie
                plr->SendMovieStart(883);
            });
        }
    }
};

// 7653
struct conversation_cyrus_story : public ConversationScript
{
    conversation_cyrus_story() : ConversationScript("conversation_cyrus_story") { }

    void OnConversationRemove(Conversation* /*conversation*/, Unit* creator) override
    {
        if (creator)
            if (Player* player = creator->ToPlayer())
                player->KilledMonsterCredit(137877);
    }
};

// 137066
class npc_boralus_portal_maga : public ScriptedAI
{
public:
    npc_boralus_portal_maga(Creature* creature) : ScriptedAI(creature) { }

    void sGossipSelect(Player* player, uint32 /*menuId*/, uint32 /*gossipListId*/) override
    {
        KillCreditMe(player);
    }
};

// 121235
class npc_taelia_harbormaster : public ScriptedAI
{
public:
    npc_taelia_harbormaster(Creature* creature) : ScriptedAI(creature) { }

    void sQuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->ID == QUEST_NATION_DIVIDED)
            player->CastSpell(player, SPELL_SCENE_NATION_DIVIDED, true);
        else if (quest->ID == 47099)
            player->CastSpell(player, 247528, true);   
    }

    void sGossipSelect(Player* player, uint32 /*menuId*/, uint32 /*gossipListId*/) override
    {
        player->CastSpell(player, SPELL_SCENE_NATION_DIVIDED, true);
    }
};

// 139522
class npc_boralus_adventure_map : public ScriptedAI
{
public:
    npc_boralus_adventure_map(Creature* creature) : ScriptedAI(creature) { }

    void sGossipHello(Player* player) override
    {
        KillCreditMe(player);
    }
};

// 126158
class npc_flynn_allured : public ScriptedAI
{
public:
    npc_flynn_allured(Creature* creature) : ScriptedAI(creature) { }

    enum
    {
        QUEST_ALLURED_ID = 48419,
        QUEST_LOVESICK_ID = 48505,
        SPELL_SUMMON_FLYNN_ESCORT_ID = 251037
    };

    void MoveInLineOfSight(Unit* unit) override
    {
        if (Player* player = unit->ToPlayer())
            if (player->GetQuestStatus(QUEST_ALLURED_ID) == QUEST_STATUS_INCOMPLETE)
                KillCreditMe(player);
    }

    void sQuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->ID == QUEST_LOVESICK_ID)
        {
            me->DestroyForPlayer(player);
            player->CastSpell(player, SPELL_SUMMON_FLYNN_ESCORT_ID, true);
        }
    }
};

// 126157
class npc_lugeia : public ScriptedAI
{
public:
    npc_lugeia(Creature* creature) : ScriptedAI(creature) { }

    enum
    {
        NPC_FLYNN_ENTRY    = 126158,
        SPELL_LOVESTRUCK   = 245526,
        SPELL_BROKEN_HEART = 250911
    };

    void JustDied(Unit* /*killer*/) override
    {
        if (Creature* flynn = me->FindNearestCreature(NPC_FLYNN_ENTRY, 20.f))
        {
            flynn->RemoveAura(SPELL_LOVESTRUCK);
            flynn->CastSpell(flynn, SPELL_BROKEN_HEART, true);
            flynn->GetMotionMaster()->MovePoint(0, -1386.29f, -1663.99f, 0.111337f);
            flynn->ForcedDespawn(4500);
        }
    }
};

/// TODO Make Flynn wait for player
/// TODO Cast the good spells at the right time
// 126490
class npc_flynn_lovesick_escort : public npc_escortAI
{
public:
    npc_flynn_lovesick_escort(Creature* creature) : npc_escortAI(creature) { }

    enum
    {
        SPELL_LOVESICK = 250911,
        SPELL_FLYNN_FLASK = 251027,
        SPELL_DRUNK = 251260,
        SPELL_THROW_FLASK = 251065
    };

    void IsSummonedBy(Unit* summoner) override
    {
        Start(false, true, summoner->GetGUID());
        SetEscortPaused(true);
        me->GetScheduler().Schedule(5s, [this](TaskContext /*context*/)
        {
            me->CastSpell(me, SPELL_LOVESICK, true);
        }).Schedule(8s, [this](TaskContext /*context*/)
        {
            TalkToEscortPlayer(0);
        }).Schedule(10s, [this](TaskContext /*context*/)
        {
            me->CastSpell(me, SPELL_FLYNN_FLASK, true);
        }).Schedule(17s, [this](TaskContext /*context*/)
        {
            SetEscortPaused(false);
        });
    }

    void WaypointReached(uint32 pointId) override
    {
        switch (pointId)
        {
        case 0:
            TalkToEscortPlayer(1);
            break;
        case 1:
            TalkToEscortPlayer(2);
            SetEscortPaused(true);
            me->GetScheduler().Schedule(7s, [this](TaskContext /*context*/)
            {
                TalkToEscortPlayer(3);
                SetEscortPaused(false);
            });
            break;
        case 6:
            TalkToEscortPlayer(4);
            SetRun(false);
            break;
        case 12:
            TalkToEscortPlayer(5);
            SetEscortPaused(true);
            me->GetScheduler().Schedule(7s, [this](TaskContext /*context*/)
            {
                SetEscortPaused(false);
                TalkToEscortPlayer(6);
            });
            me->CastSpell(me, SPELL_DRUNK, true);
            break;
        case 16:
            TalkToEscortPlayer(7);
            break;
        case 31:
            TalkToEscortPlayer(9);
            break;
        case 40:
            TalkToEscortPlayer(10);
            break;
        case 45:
            TalkToEscortPlayer(11);
            break;
        case 46:
            TalkToEscortPlayer(12);
            KillCreditMe(GetPlayerForEscort());
            break;
        default:
            break;
        }
    }

    void LastWaypointReached() override
    {
        if (Player* player = GetPlayerForEscort())
        {
            KillCreditMe(player);
        }
    }
};

//128349 Hilde Firebreaker
class npc_hilde_firebreaker_queststarter : public ScriptedAI
{
public:
    enum
    {
        QUEST_BACKUP_WILL_I_PACK = 49260,
        NPC_DEFEND_FIREBREAKER_KILLCREDIT = 128709
    };

    npc_hilde_firebreaker_queststarter(Creature* creature) : ScriptedAI(creature) { }

    void sQuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->ID != QUEST_BACKUP_WILL_I_PACK)
            return;

        players.push_back(player);

        if (_ongoing)
            return;

        players.clear();
        players.push_back(player);

        me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_NPC);
        me->SummonCreature(129841, me->GetPosition(), TEMPSUMMON_CORPSE_DESPAWN);

        _ongoing = true;
    }

    void SummonedCreatureDespawn(Creature* /*creature*/) override
    {
        // killcredit
        for (Player* player : players)
            if (player && player->IsInWorld() && player->IsInRange2d(me->GetPositionX(), me->GetPositionY(), 0, 50))
                player->KilledMonsterCredit(NPC_DEFEND_FIREBREAKER_KILLCREDIT);

        _ongoing = false;
    }

    void SummonedCreatureDies(Creature* /*creature*/, Unit* /*unit*/) override
    {
        // Fail the quest
        for (Player* player : players)
            if (player && player->IsInWorld())
                player->FailQuest(QUEST_BACKUP_WILL_I_PACK);

        _ongoing = false;
    }

private:
    bool _ongoing = false;
    std::vector<Player*> players;
};

//129841 Hilde Firebreaker
class npc_hilde_firebreaker_protect : public npc_escortAI
{
public:
    enum
    {
        QUEST_BACKUP_WILL_I_PACK = 49260,
        NPC_LIVING_ARTEFACT = 128405,
        NPC_ANGERED_REVENANT = 128591,
        NPC_FALLEN_KEEPER = 128608
    };

    npc_hilde_firebreaker_protect(Creature* creature) : npc_escortAI(creature)
    {
        pos[0] = Position(1108.739990f, 261.151001f, 17.821600f, 1.603710f); // 128405
        pos[1] = Position(1115.000000f, 261.557007f, 18.138300f, 1.946000f); // 128591
        pos[2] = Position(1123.180054f, 269.458008f, 17.009701f, 1.762220f); // 128405
        pos[3] = Position(1123.770020f, 275.671997f, 17.066000f, 3.344580f); // 128591
        pos[4] = Position(1123.689941f, 278.740997f, 18.338100f, 3.654940f); // 128405
        pos[5] = Position(1119.719971f, 265.915009f, 17.663000f, 2.204700f); // 128608
    }

    void IsSummonedBy(Unit* /*summoner*/) override
    {
        _numberOfSummonsAlive = 2;
        if (TempSummon* ts = me->SummonCreature(NPC_LIVING_ARTEFACT, pos[0], TEMPSUMMON_CORPSE_DESPAWN)) ts->AI()->AttackStart(me);
        if (TempSummon* ts = me->SummonCreature(NPC_ANGERED_REVENANT, pos[1], TEMPSUMMON_CORPSE_DESPAWN)) ts->AI()->AttackStart(me);
        SetCanAttack(false);
        //Start(false, false, summoner->GetGUID(), NULL, false, false, true);
    }

    void SummonedCreatureDies(Creature* /*creature*/, Unit* /*unit*/) override
    {
        _numberOfSummonsAlive--;
        if (_numberOfSummonsAlive == 0)
        {
            // Next wave or despawn if finished
            _numberOfWaveCleaned++;

            switch (_numberOfWaveCleaned)
            {
            case 1:
                _numberOfSummonsAlive = 3;
                if (TempSummon* ts = me->SummonCreature(NPC_LIVING_ARTEFACT, pos[2], TEMPSUMMON_CORPSE_DESPAWN)) ts->AI()->AttackStart(me);
                if (TempSummon* ts = me->SummonCreature(NPC_ANGERED_REVENANT, pos[3], TEMPSUMMON_CORPSE_DESPAWN)) ts->AI()->AttackStart(me);
                if (TempSummon* ts = me->SummonCreature(NPC_LIVING_ARTEFACT, pos[4], TEMPSUMMON_CORPSE_DESPAWN)) ts->AI()->AttackStart(me);
                break;
            case 2:
                _numberOfSummonsAlive = 1;
                if (TempSummon* ts = me->SummonCreature(NPC_FALLEN_KEEPER, pos[5], TEMPSUMMON_CORPSE_DESPAWN)) ts->AI()->AttackStart(me);
                break;
            case 3:
                me->ForcedDespawn();
                break;
            default:
                break;
            }
        }
    }
    /*
    void WaypointReached(uint32 pointId) override
    {
        if (pointId == 1)
        {
            _numberOfSummonsAlive = 2;
            if (TempSummon* ts = me->SummonCreature(NPC_LIVING_ARTEFACT, pos[0], TEMPSUMMON_DEAD_DESPAWN)) ts->AI()->AttackStart(me);
            if (TempSummon* ts = me->SummonCreature(NPC_ANGERED_REVENANT, pos[1], TEMPSUMMON_DEAD_DESPAWN)) ts->AI()->AttackStart(me);
        }
    }*/

private:
    int _numberOfWaveCleaned = 0;
    int _numberOfSummonsAlive = 0;
    Position pos[6];
};

// 131684
class npc_penny_hardwick : public ScriptedAI
{
public:
    npc_penny_hardwick(Creature* creature) : ScriptedAI(creature) { }

    enum
    {
        QUEST_A_VERY_PRECIOUS_CARGO = 50002,
        QUEST_HOLD_MY_HAND = 50005,
        NPC_PENNY_KILLCREDIT = 132725,
        SPELL_CANCEL_ESCORT_PENNY = 259926,
        SPELL_ESCORTING_PENNY_HARDWICK = 259909
    };

    void MoveInLineOfSight(Unit* unit) override
    {
        if (Player* player = unit->ToPlayer())
        {
            float x = me->GetPositionX();
            float y = me->GetPositionY();
            float z = me->GetPositionZ();

            if (fabs(x - 534.932007f) < .1 && fabs(y - 870.984009f) < .1 && fabs(z - 7.821800f) < .1f) // ensuring we don't take the quest form ending npc
                if (player->GetQuestStatus(QUEST_A_VERY_PRECIOUS_CARGO) == QUEST_STATUS_INCOMPLETE)
                    player->KilledMonsterCredit(NPC_PENNY_KILLCREDIT);
        }
    }

    void sQuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->ID == QUEST_HOLD_MY_HAND)
        {
            player->CastSpell(player, SPELL_CANCEL_ESCORT_PENNY);
            player->CastSpell(player, SPELL_ESCORTING_PENNY_HARDWICK);
        }
    }
};

///TODO Make Penny wait at far
// 131748
class npc_penny_hardwick_escort : public npc_escortAI
{
public:
    npc_penny_hardwick_escort(Creature* creature) : npc_escortAI(creature) { }

    enum
    {
        SPELL_CANCEL_ESCORT_PENNY = 259926,
        QUEST_HOLD_MY_HAND = 50005
    };

    void IsSummonedBy(Unit* summoner) override
    {
        Start(false, false, summoner->GetGUID(), NULL, true);
        SetDespawnAtFar(true);
        SetDespawnAtEnd(true);
    }

    void LastWaypointReached() override
    {
        if (Player* player = GetPlayerForEscort())
        {
            KillCreditMe(player);
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (Player* player = GetPlayerForEscort())
        {
            if (player->GetQuestStatus(QUEST_HOLD_MY_HAND) != QUEST_STATUS_COMPLETE)
                player->FailQuest(QUEST_HOLD_MY_HAND);
            player->CastSpell(player, SPELL_CANCEL_ESCORT_PENNY);
        }
    }

    void JustRespawned() override
    {
        if (Player* player = GetPlayerForEscort())
        {
            player->FailQuest(QUEST_HOLD_MY_HAND);
            player->CastSpell(player, SPELL_CANCEL_ESCORT_PENNY);
        }
    }
};

// 143096
class npc_riding_macaw_patrol : public npc_escortAI
{
public:
    enum
    {
        SPELL_SUMMON_RIDING_MACAW = 279049,
        QUEST_RODRIGO_REVENGE = 49403
    };

    npc_riding_macaw_patrol(Creature* creature) : npc_escortAI(creature)
    {
        me->SetCanFly(true);
    }

    void OnCharmed(bool /*apply*/) override
    {
        // Make sure the basic cleanup of OnCharmed is done to avoid looping problems
        if (me->NeedChangeAI)
            me->NeedChangeAI = false;
    }

    void EnterEvadeMode(EvadeReason /*why*/) override { }

    void IsSummonedBy(Unit* summoner) override
    {
        if (summoner)
        {
            me->AddAura(SPELL_SUMMON_RIDING_MACAW, me); // Add the phase shift aura
            me->GetScheduler().Schedule(1s, [this, summoner](TaskContext /*context*/)
            {
                summoner->CastSpell(me, VEHICLE_SPELL_RIDE_HARDCODED);
            }).Schedule(2s, [this, summoner](TaskContext /*context*/)
            {
                Start(false, true, summoner->GetGUID(), (const Quest *)0, false, false, true);
            });
        }
    }

    void PassengerBoarded(Unit* passenger, int8 /*seatId*/, bool apply) override
    {
        if (!apply)
        {
            if (passenger)
            {
                passenger->RemoveAurasDueToSpell(SPELL_SUMMON_RIDING_MACAW);
                me->ForcedDespawn();
            }
        }
    }
};

// 142721 - Ralston Karn 
class npc_ralston_karn  : public ScriptedAI
{
public:
    enum
    {
        QUEST_TO_THE_FRONT            = 53194,
        NPC_YVERA_DAWNWING_KILLCREDIT = 143380,
        SPELL_TELEPORT_TO_STROMGARDE  = 279518
    };

    npc_ralston_karn(Creature* creature) : ScriptedAI(creature) { }

    void sQuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->ID == QUEST_TO_THE_FRONT)
		{
            player->KilledMonsterCredit(NPC_YVERA_DAWNWING_KILLCREDIT);
            player->CastSpell(player, SPELL_TELEPORT_TO_STROMGARDE);
        }
    }
};

class boralus_harbor : public PlayerScript
{
public:
    boralus_harbor() : PlayerScript("boralus_harbor") { }

    uint32 timer = 100;

    void OnUpdate(Player* plr, uint32 diff) override
    {
        if (timer <= diff && plr->GetZoneId() == 8717 || plr->GetZoneId() == 8567 && plr->GetPhaseShift().HasPhase(180))
        {            
            PhasingHandler::RemovePhase(plr, 180, true);
            if (plr->HasAura(78517))
                plr->RemoveAura(78517);
        }
        else
            timer -= diff;
    }
};

class old_knight_check : public PlayerScript
{
public:
    old_knight_check() : PlayerScript("old_knight_check") { }

    void OnLogin(Player* plr, bool /*firstLogin*/)
    {        
        if (plr->GetZoneId() == 8717 || plr->GetZoneId() == 8567 && plr->GetQuestStatus(QUEST_THE_OLD_KNIGHT) != QUEST_STATUS_REWARDED && plr->getLevel() >= 110 && plr->GetTeam() == ALLIANCE && plr->GetQuestStatus(QUEST_GET_YOUR_BEARINGS) == QUEST_STATUS_REWARDED)
        {
            if (const Quest* qu = sObjectMgr->GetQuestTemplate(QUEST_THE_OLD_KNIGHT))
                plr->AddQuest(qu, nullptr);
        }
    }
};

//121144
class npc_katherine_proudmoore_121144 : public ScriptedAI
{
public:
	npc_katherine_proudmoore_121144(Creature* c) : ScriptedAI(c) { }

	void MoveInLineOfSight(Unit* u) override
	{
        if (u->IsPlayer())
            if (Player* plr = u->ToPlayer())
                if (plr->GetQuestStatus(QUEST_NATION_UNITED) == QUEST_STATUS_INCOMPLETE)
                    plr->ForceCompleteQuest(QUEST_NATION_UNITED);
	}
};

enum WarCampaign80
{
    //Alliance
    QUEST_HEART_OF_DARKNESS = 51088, //Nazmir
    QUEST_VOYAGE_TO_THE_WEST = 51283, //Voldun
    QUEST_THE_ABYSSAL_SCEPTER = 54171, //Zuldazar
    QUEST_OVERSEAS_ASSASINATION = 52026, //Voldun
};

//135681
class npc_grand_admiral_jes_tereth_135681 : public CreatureScript
{
public:
    npc_grand_admiral_jes_tereth_135681() : CreatureScript("npc_grand_admiral_jes_tereth_135681") { }

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Set sail for Vol'dun.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 0);
        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Set sail for Nazmir.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Set sail for Zuldazar.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);

        SendGossipMenuFor(player, 34711, creature->GetGUID());

        player->PrepareQuestMenu(creature->GetGUID());

        return true;
    }

    bool OnGossipSelect(Player* player, Creature* /*creature*/, uint32 /*sender*/, uint32 action) override
    {
        if (action == GOSSIP_ACTION_INFO_DEF + 0)//Set sail for Vol'dun.
        {
            player->TeleportTo(1642, 2831.0f, 4264.0f, 7.5f, 4.77f);

            if (player->HasQuest(QUEST_OVERSEAS_ASSASINATION))
                player->ForceCompleteQuest(QUEST_OVERSEAS_ASSASINATION);

            if (player->HasQuest(QUEST_VOYAGE_TO_THE_WEST))
                player->ForceCompleteQuest(QUEST_VOYAGE_TO_THE_WEST);
        }
        if (action == GOSSIP_ACTION_INFO_DEF + 1)//Set sail for Nazmir.
        {
            player->TeleportTo(1642, 2130.0f, 193.0f, 0.19f, 2.48f);

            if (player->HasQuest(QUEST_HEART_OF_DARKNESS))
                player->KilledMonsterCredit(136433);
        }
        if (action == GOSSIP_ACTION_INFO_DEF + 2)//Set sail for Zuldazar.
        {
            player->TeleportTo(1642, -2618.0f, 2269.0f, 12.9f, 4.98f);
        }

        return true;
    }
};

void AddSC_zone_tiragarde_sound()
{
    RegisterCreatureAI(npc_jaina_boralus_intro);
    RegisterSceneScript(scene_jaina_to_proudmoore_keep);
    RegisterAuraScript(aura_tol_dagor_intro_prisoner);
    RegisterQuestScript(quest_out_like_flynn);
    RegisterCreatureAI(npc_flynn_fairwind);
    RegisterGameObjectAI(go_toldagor_cell_block_lever);
    RegisterSceneScript(scene_flynn_jailbreak);
    RegisterCreatureAI(npc_flynn_fairwind_follower);
    RegisterCreatureAI(npc_tol_dagor_enter_sewer_credit);
    RegisterCreatureAI(npc_tol_dagor_getaway_boat);
    RegisterConversationScript(conversation_tol_dagor_inmate);
    RegisterConversationScript(conversation_tol_dagor_escape);
    RegisterSceneScript(scene_tol_dagor_getaway_boat);
    RegisterConversationScript(conversation_boralus_get_your_bearings);
    RegisterCreatureAI(npc_taelia_get_your_bearings);
    RegisterSceneScript(scene_boralus_old_knight);
    RegisterCreatureAI(npc_cyrus_crestfall);
    RegisterConversationScript(conversation_cyrus_story);
    RegisterCreatureAI(npc_boralus_portal_maga);
    RegisterCreatureAI(npc_taelia_harbormaster);
    RegisterCreatureAI(npc_boralus_adventure_map);
    RegisterCreatureAI(npc_flynn_allured);
    RegisterCreatureAI(npc_lugeia);
    RegisterCreatureAI(npc_flynn_lovesick_escort);
    RegisterCreatureAI(npc_hilde_firebreaker_queststarter);
    RegisterCreatureAI(npc_hilde_firebreaker_protect);
    RegisterCreatureAI(npc_penny_hardwick);
    RegisterCreatureAI(npc_penny_hardwick_escort);
    RegisterCreatureAI(npc_riding_macaw_patrol);
    RegisterCreatureAI(npc_ralston_karn);
    RegisterPlayerScript(boralus_harbor);
    RegisterPlayerScript(old_knight_check);
    RegisterCreatureAI(npc_katherine_proudmoore_121144);
    new npc_grand_admiral_jes_tereth_135681();
}
