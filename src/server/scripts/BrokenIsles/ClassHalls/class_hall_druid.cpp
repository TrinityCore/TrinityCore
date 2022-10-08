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
#include "ScriptedCreature.h"
#include "Player.h"
#include "Creature.h"
#include "GameObject.h"
#include "SceneMgr.h"
#include "SceneHelper.h"
#include "ScriptedGossip.h"
#include "PhasingHandler.h"
#include "Log.h"
#include "ObjectMgr.h"
#include "Spell.h"
#include "GarrisonPackets.h"
#include "WorldSession.h"
#include "Garrison.h"
#include "LootMgr.h"

enum
{
    SPELL_TELEPORT_MOONGLADE = 18960,
    SPELL_WEAPONS_OF_LEGEND_PLAYER_CHOICE = 199653,
    PLAYER_CHOICE_DRUID_SELECTION = 247,
    PLAYER_CHOICE_DRUID_BALANCE = 529,
    PLAYER_CHOICE_DRUID_FERAL = 530,
    PLAYER_CHOICE_DRUID_GUARDIAN = 531,
    PLAYER_CHOICE_DRUID_RESTORATION = 545,

    QUEST_GUARDIAN_CHOSEN = 40702,
    QUEST_RESTORATION_CHOSEN = 40703,
    QUEST_FERAL_CHOSEN = 40701,
    QUEST_BALANCE_CHOSEN = 40781,

    KILLED_MONSTER_CREDIT_40643 = 103346,
    QUEST_A_SUMMONS_FROM_MOONGLADE = 40643,
    QUEST_CALL_OF_THE_WILDS = 41106,
    QUEST_THE_DREAMWAY = 40644,
    QUEST_TO_THE_DREAMGROVE = 40645,
    QUEST_WEAPONS_OF_LEGEND = 40646,
    QUEST_ANOTHER_WEAPON_OF_OLD = 43980,
    QUEST_MORE_WEAPONS_OF_OLD = 44431,
    QUEST_WEAPONS_OF_THE_ANCIENTS = 44443,
    QUEST_SOWING_THE_SEED = 41255,
    QUEST_SOWING_THE_SEED_PHASE = 5685,
    QUEST_ASCENDING_THE_CIRCLE = 41332,
    QUEST_A_HEROS_WEAPON = 43409,
    ///GUARDIAN
    QUEST_MISTRESS_OF_THE_CLAW = 41468,
    QUEST_TO_THE_HILLS = 41782,
    QUEST_FALLEN_OFFERINGS = 41783,
    ///FERAL
    QUEST_THE_SHRINE_OF_ASHAMANE = 42428,
    NPC_DELANDROS_SHIMMERMOON_107392 = 107392,
    NPC_VERSTOK_DARKBOUGH_107520 = 107520,
    QUEST_AID_FOR_THE_ASHEN = 42439,
    QUEST_THE_SHRINE_IN_PERIL = 42440,
    NPC_ALGROMON_107593 = 107593,
    ///BALANCE
    QUEST_THE_SCYTHE_OF_ELUNE = 40783,
    QUEST_ITS_RIGHTFUL_PLACE = 40784,
    QUEST_A_FOE_OF_THE_DARK = 40785,
    QUEST_FOLLOWING_THE_CURSE = 40834,
    QUEST_DISTURBING_THE_PAST = 40835,
    QUEST_THE_DEADWIND_HUNT = 40837,
    QUEST_THE_DARK_RIDERS = 40838,
    NPC_NARALEX_103778 = 103778,
    ///RESTORATION
    QUEST_MEET_WITH_MYLUNE = 40649,
    QUEST_NECESSARY_PREPARATIONS = 41422,
    QUEST_JOIN_THE_DREAMER = 41449,
    QUEST_IN_DEEP_SLUMBER = 41436,
    PHASE_IN_DEEP_SLUMBER = 6053, //7541,
    QUEST_RECONVENE = 41690,
    QUEST_CLEANSING_THE_MOTHER_TREE = 41689,
    NPC_NARALEX_104349 = 104349,

    NPC_ARCHDRUID_HAMUUL_RUNETOTEM_101064 = 101064,
    NPC_KEEPER_REMULOS_101065 = 101065,

    NPC_KEEPER_REMULOS_103488 = 103488,
    NPC_KEEPER_REMULOS_103832 = 103832,

    SPELL_FADE = 206809,
};



class npc_class_hall_druid_gatewarden : public CreatureScript
{
public:
    npc_class_hall_druid_gatewarden(const char* name, uint32 teleportSpell) : CreatureScript(name), _teleportSpell(teleportSpell) { }

    struct npc_class_hall_druid_gatewardenAI : public ScriptedAI
    {
        npc_class_hall_druid_gatewardenAI(Creature* creature, uint32 teleportSpell) : ScriptedAI(creature), _teleportSpell(teleportSpell)
        {
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (!who->ToPlayer() || who->ToPlayer()->IsGameMaster())
                return;

            if (me->isInBackInMap(who, 12.0f))   // In my line of sight, "outdoors", and behind me
            {
                if (who->ToPlayer()->HasQuest(QUEST_TO_THE_DREAMGROVE) && me->GetEntry() == 107265)
                {
                    if (!who->ToPlayer()->GetQuestObjectiveData(QUEST_TO_THE_DREAMGROVE, 1))
                    {
                        who->ToPlayer()->KilledMonsterCredit(101215);
                        who->ToPlayer()->TeleportTo(1220, 3756.379395f, 7132.707520f, 23.856869f, 0.401426f);
                    }
                }
                else if (who->ToPlayer()->HasQuest(QUEST_TO_THE_HILLS) && me->GetEntry() == 107263)
                {
                    if (!who->ToPlayer()->GetQuestObjectiveData(QUEST_TO_THE_HILLS, 1))
                    {
                        who->ToPlayer()->KilledMonsterCredit(104392);
                        who->ToPlayer()->KilledMonsterCredit(135563);
                        who->ToPlayer()->TeleportTo(571, 4475.52f, -3757.94f, 217.14f, 3.56309f);
                    }
                }
                else if (who->ToPlayer()->HasQuest(QUEST_CLEANSING_THE_MOTHER_TREE) && me->GetEntry() == 107262)
                {
                    who->ToPlayer()->TeleportTo(1599, 5465.67f, -3447.32f, 1559.12f, 4.987278f);
                }
                else if (who->ToPlayer()->HasQuest(QUEST_THE_SCYTHE_OF_ELUNE) && me->GetEntry() == 107260)
                {
                    if (!who->ToPlayer()->GetQuestObjectiveData(QUEST_THE_SCYTHE_OF_ELUNE, 0))
                    {
                        who->ToPlayer()->KilledMonsterCredit(103585);
                        who->CastSpell(who, _teleportSpell, true);
                    }

                }
                else
                    who->CastSpell(who, _teleportSpell, true);
            }

        }

        uint32 _teleportSpell;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_class_hall_druid_gatewardenAI(creature, _teleportSpell);
    }

    uint32 _teleportSpell;
};



enum
{///ID - 204544 ????????
    SPELL_DRUID_ORDER_FORMATION = 204538,
    SPELL_ASSIGN_DRUID_SPELL_BAR = 204543,
    KILLED_MONSTER_CREDIT_40644 = 103346,

};
// 101061 NPC_ARCHDRUID_HAMUUL_RUNETOTEM 
struct npc_archdruid_hamuul_runetotem_101061 : public ScriptedAI
{
    npc_archdruid_hamuul_runetotem_101061(Creature* creature) : ScriptedAI(creature) { }

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
        if (quest->GetQuestId() == QUEST_A_SUMMONS_FROM_MOONGLADE)
        {
            Talk(1, player);
            player->CastSpell(player, SPELL_TELEPORT_MOONGLADE, true);
            me->DespawnOrUnsummon(5000);
        }
    }
};
///ID - 210908 Create Garrison and Confirm Solo Experience Package QUEST_A_SUMMONS_FROM_MOONGLADE reward

struct npc_archdruid_hamuul_runetotem_101064 : public ScriptedAI
{
    npc_archdruid_hamuul_runetotem_101064(Creature* creature) : ScriptedAI(creature) {  }

    void DoAction(int32 param)
    {
        switch (param)
        {
        case 1:
            if (Player* player = ObjectAccessor::GetPlayer(*me, m_playerGUID))
            {
                player->CastSpell(player, 199439, true);
              //  _sceneHelper.Clear();
             //   _sceneHelper.SetDefaultActorGuid(me->GetGUID());
           //     _sceneHelper.SetDefaultPlayerGuid(player->GetGUID());
           //     _sceneHelper.AddSceneActionSay(103487, 500);
            //    _sceneHelper.AddSceneActionSay(103485, 5000);
             //   _sceneHelper.AddSceneActionSay(103486, 5000);
            //    _sceneHelper.AddSceneActionSay(103489, 5000);
            //    _sceneHelper.Activate();
            }
            break;
        case 2:
            if (Player* player = ObjectAccessor::GetPlayer(*me, m_playerGUID))
            {
                player->CastSpell(me, 204662, true);
                player->KilledMonsterCredit(101064);
                me->DespawnOrUnsummon(19000);
            }
            break;
        }
    }

    void MovementInform(uint32 /*type*/, uint32 id) override
    {
        switch (id)
        {
        case 1:
            DoAction(1);
            break;
        case 2:
            DoAction(2);
            break;
        default:
            break;
        }
    }

    void sQuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_CALL_OF_THE_WILDS)
            Talk(0, player);

        if (quest->GetQuestId() == QUEST_THE_DREAMWAY)
        {
            //DoCastSelf(204663);
            Talk(1, player);
            me->SetCanFly(true);
            me->SetDisableGravity(true);
            m_playerGUID = player->GetGUID();
            me->GetMotionMaster()->MovePoint(1, Position(8001.76f, -2680.266f, 516.2501f), true);///reched point cast 199439 ->conversation 927

            me->GetScheduler().Schedule(Milliseconds(15000), [this](TaskContext context)
            {
                me->GetMotionMaster()->MovePoint(2, Position(7558.831f, -2879.167f, 460.8212f), true);
            });

            ///185506 ? 192190 ?
        }
    }

    void sQuestReward(Player* player, Quest const* quest, uint32 /*opt*/)  override
    {
        if (quest->GetQuestId() == QUEST_CALL_OF_THE_WILDS)
            player->CastSpell(player, 204250, true);
    }
private:
    ObjectGuid   m_playerGUID;
};

enum
{
    NPC_ZENTABRA_103135 = 103135,
    NPC_ZENTABRA_103136 = 103136,
    POINT_1 = 2,
    POINT_HOME = 1,
    DB_PHASE_1 = 5899,
    DB_PHASE_2 = 5900,
    DB_PHASE_3 = 5935,

    NPC_NARALEX_103133 = 103133,
};
///DB_PHASE_1 = 5899,  ID - 203979 ??????
///ID - 203984 ????? Triggered by spell: (203987) ??????? Triggered by spell : (204250) ??????
struct npc_zentabra_103135 : public ScriptedAI
{
    npc_zentabra_103135(Creature* creature) : ScriptedAI(creature) { Initialize(); }

    void DoAction(int32 param)
    {
        switch (param)
        {
        case POINT_1:
            me->GetMotionMaster()->MovePoint(POINT_1, Position(7673.544f, -2387.757f, 456.4582f, 4.519598f), true);
            break;
        case POINT_HOME:
            me->GetMotionMaster()->MovePoint(POINT_HOME, Position(7683.905f, -2410.326f, 455.3737f, 2.185425f), true);
            break;

        }
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

    void sGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId)
    {
        CloseGossipMenuFor(player);
        if (player->HasQuest(QUEST_CALL_OF_THE_WILDS))
        {
            player->KilledMonsterCredit(103136);
            Talk(1, player);
            DoCast(player, 203984, true);

            _scheduler.Schedule(1250ms, [this, player](TaskContext /*context*/)
            {
                Talk(2, player);
            });

            _scheduler.Schedule(5000ms, [this, player](TaskContext /*context*/)
            {
                Talk(3, player);
            });

            _scheduler.Schedule(10000ms, [this, player](TaskContext /*context*/)
            {
                me->RemoveAurasDueToSpell(203979);
                DoAction(POINT_HOME);
            });
        }
    }

    void MovementInform(uint32 /*type*/, uint32 id) override
    {
        switch (id)
        {
        case POINT_1:
            //???
            DoCastSelf(203979);
            Talk(0);
            //

            if (Player* player = ObjectAccessor::GetPlayer(*me, m_playerGUID))
            {
                me->SetFacingToObject(player, true);
                _scheduler.Schedule(250ms, [this, player](TaskContext /*context*/)
                {
                    PhasingHandler::AddPhase(me, DB_PHASE_1, true);
                    PhasingHandler::AddPhase(player, DB_PHASE_2, true);
                    PhasingHandler::RemovePhase(player, DB_PHASE_1, true);
                });
            }
            break;
        case POINT_HOME:
            RemovePlayer();
            break;
        default:
            break;
        }
    }

    void Initialize()
    {
        m_playerGUID = ObjectGuid::Empty;
        me->RemoveAurasDueToSpell(203979);
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

    void MoveInLineOfSight(Unit* who) override
    {
        if (!who || !who->IsInWorld())
            return;
        if (!me->IsWithinDist(who, 25.0f, false))
        {
            //RemovePlayer();
            return;
        }
        Player* player = who->GetCharmerOrOwnerPlayerOrPlayerItself();
        if (!player)
            return;
        if (!HasPlayer(player->GetGUID()) && player->HasQuest(QUEST_CALL_OF_THE_WILDS) && !player->GetQuestObjectiveData(QUEST_CALL_OF_THE_WILDS, 0))
        {
            m_playerGUID = player->GetGUID();
            AddPlayer();
            DoAction(POINT_1); ///Move to
        }
    }
private:
    TaskScheduler _scheduler;
    std::set<ObjectGuid> pList;
    ObjectGuid   m_playerGUID;
};

struct npc_zentabra_103136 : public ScriptedAI
{
    npc_zentabra_103136(Creature* creature) : ScriptedAI(creature) { Initialize(); }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }


    void sGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId)
    {
        CloseGossipMenuFor(player);
        if (player->HasQuest(QUEST_CALL_OF_THE_WILDS))
        {
            player->KilledMonsterCredit(me->GetEntry());
            Talk(0, player);
        }
    }
    void Initialize()
    {

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

    void MoveInLineOfSight(Unit* who) override
    {
        if (!who || !who->IsInWorld())
            return;
        if (!me->IsWithinDist(who, 15.0f, false))
        {
            RemovePlayer();
            return;
        }
        Player* player = who->GetCharmerOrOwnerPlayerOrPlayerItself();
        if (!player)
            return;
        /*
        if (!HasPlayer(player->GetGUID()) && (player->HasQuest(QUEST_CALL_OF_THE_WILDS)) )
        {
            m_playerGUID = player->GetGUID();
            AddPlayer();
            player->KilledMonsterCredit(me->GetEntry());
            m_playerGUID = ObjectGuid::Empty;
        }*/
    }
private:

    TaskScheduler _scheduler;
    std::set<ObjectGuid> pList;
    ObjectGuid   m_playerGUID;
};
//204250 spell
struct npc_naralex_103133 : public ScriptedAI
{
    npc_naralex_103133(Creature* creature) : ScriptedAI(creature) { Initialize(); }


    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

    void Initialize()
    {
        me->RemoveAurasDueToSpell(204270);
        DoCastSelf(204637, true);
    }

    void sGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId)
    {
        player->CastSpell(player, 204250, true);
        CloseGossipMenuFor(player);
        if (player->HasQuest(QUEST_CALL_OF_THE_WILDS) && gossipListId == 1)
        {
            me->RemoveAurasDueToSpell(204637);
            player->KilledMonsterCredit(me->GetEntry());
            Talk(0, player);
            _scheduler.Schedule(Milliseconds(2000), [this, player](TaskContext context)
            {
                Talk(1);
                DoCastSelf(204270, true);
                ///ID - 105318 Update Zone Auras and Phase Shift
                DoCast(player, 105318, true);
                DoCastSelf(105318, true);
                ///X: 7392.571 Y: -2316.646 Z: 493.6733
                me->GetMotionMaster()->MovePoint(1, Position(7392.571f, -2316.646f, 493.6733f), true);
            });

            _scheduler.Schedule(Milliseconds(4000), [this, player](TaskContext context)
            {
                me->GetMotionMaster()->MovePoint(2, Position(7387.746f, -2320.948f, 491.073f), true);
            });

            _scheduler.Schedule(Milliseconds(7000), [this, player](TaskContext context)
            {
                me->GetMotionMaster()->MovePoint(3, Position(7385.798f, -2327.387f, 486.7766f), true);
            });
            _scheduler.Schedule(Milliseconds(9000), [this, player](TaskContext context)
            {
                me->GetMotionMaster()->MovePoint(4, Position(7388.854f, -2331.33f, 484.655f), true);
            });

            _scheduler.Schedule(Milliseconds(12000), [this, player](TaskContext context)
            {
                me->GetMotionMaster()->MovePoint(5, Position(7391.678f, -2343.4f, 478.5645f), true);
            });
            _scheduler.Schedule(Milliseconds(14000), [this, player](TaskContext context)
            {
                me->GetMotionMaster()->MovePoint(6, Position(7391.092f, -2353.993f, 476.7569f), true);
            });

            _scheduler.Schedule(Milliseconds(16000), [this, player](TaskContext context)
            {
                me->GetMotionMaster()->MovePoint(7, Position(7387.592f, -2364.859f, 475.9466f), true);
            });
            _scheduler.Schedule(Milliseconds(18000), [this, player](TaskContext context)
            {
                me->GetMotionMaster()->MovePoint(8, Position(7388.452f, -2371.531f, 474.5436f), true);
            });

            _scheduler.Schedule(Milliseconds(25000), [this, player](TaskContext context)
            {
                me->GetMotionMaster()->MoveTargetedHome();
                Initialize();
            });
        }
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
        if (player->HasQuest(QUEST_CALL_OF_THE_WILDS))
        {

            //player->KilledMonsterCredit(me->GetEntry());

        }
    }
private:
    TaskScheduler _scheduler;
};
///GO Entry: 247052 (Pillow) SPELL 204230
///ID - 204538 Druid Order Formation play scence 1206  kill add credit 40644
///40644 SMSG_QUEST_UPDATE_ADD_CREDIT 101064

// 103875 Malfurion Stormrage
struct npc_malfurion_stormrage_103875 : public ScriptedAI
{
    npc_malfurion_stormrage_103875(Creature* creature) : ScriptedAI(creature) {}

    void MoveInLineOfSight(Unit* who) override
    {
        if (Player* player = who->ToPlayer())
        {
            if (me->IsWithinDist(player, 15.0f, false))
            {
                if (player->HasQuest(QUEST_THE_DREAMWAY) && player->GetQuestStatus(QUEST_THE_DREAMWAY) == QUEST_STATUS_INCOMPLETE)
                {
                    if (!player->GetQuestObjectiveData(QUEST_THE_DREAMWAY, 1))
                    {

                        player->CastSpell(player, SPELL_DRUID_ORDER_FORMATION, true);
                        me->GetScheduler().Schedule(Milliseconds(5000), [this, player](TaskContext context)
                        {
                            player->CastSpell(player, SPELL_ASSIGN_DRUID_SPELL_BAR, true);
                            player->KilledMonsterCredit(KILLED_MONSTER_CREDIT_40644);
                        });

                    }
                    else if (!player->GetQuestObjectiveData(QUEST_THE_DREAMWAY, 2))
                    {
                        player->KilledMonsterCredit(KILLED_MONSTER_CREDIT_40644); // QUEST_THE_DREAMWAY storageIndex 2 KillCredit
                    }
                }
                if (player->GetQuestStatus(QUEST_THE_DREAMWAY) == QUEST_STATUS_COMPLETE || player->GetQuestStatus(QUEST_THE_DREAMWAY) == QUEST_STATUS_REWARDED)
                    player->RemoveAurasDueToSpell(SPELL_ASSIGN_DRUID_SPELL_BAR);
            }
        }
    }

    void sQuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_TO_THE_DREAMGROVE)
            if (Creature* keeper_remulos = me->FindNearestCreature(NPC_KEEPER_REMULOS_101065, 25.0f, true))
                keeper_remulos->AI()->Talk(0);
    }

    void sQuestReward(Player* player, Quest const* quest, uint32 /*opt*/)  override
    {
        if (quest->GetQuestId() == QUEST_THE_DREAMWAY)
            player->RemoveAurasDueToSpell(SPELL_ASSIGN_DRUID_SPELL_BAR);
    }

};
///GUID 448291
struct npc_generic_bunny_quest_to_the_dreamgrove_59115 : public ScriptedAI
{
    npc_generic_bunny_quest_to_the_dreamgrove_59115(Creature* creature) : ScriptedAI(creature) {  }

    void MoveInLineOfSight(Unit* who) override
    {
        if (!who || !who->IsInWorld())
            return;
        if (!me->IsWithinDist(who, 5.0f, false))
            return;

        Player* player = who->GetCharmerOrOwnerPlayerOrPlayerItself();
        if (!player)
            return;
        if (player->HasQuest(QUEST_TO_THE_DREAMGROVE))
        {
            player->CastSpell(player, 200083, true);
            player->TeleportTo(1540, 1508.42f, 1650.51f, 31.54f, 5.910209f);
        }
    }
};

/*
--  .go xyz 1695.939 1545.063 2.556631 1540
1700.725 1547.835  2.549316
 Position: X: 1700.725 Y: 1547.835 Z: 2.549316
 [10] Position: X: 1496.786 Y: 1650.879 Z: 30.98652   1496.786 1650.879 30.98652
 [10] Orientation: 5.588914
 npc_keeper_remulos_103489 talk 3
 cast ID - 204836 ??????  => Entry: 103488 (Keeper Remulos) spell 204842
 */

class quest_to_the_dreamgrove : public PlayerScript {
public:
    quest_to_the_dreamgrove() : PlayerScript("quest_to_the_dreamgrove") {}

    void OnMapChanged(Player* player) override {
        if (player->HasQuest(QUEST_TO_THE_DREAMGROVE) && player->GetMapId() == 1540)
        {
            PhasingHandler::AddPhase(player, 6122, true);
            ///summon keeper_remulos_103489
            if (!player->GetQuestObjectiveData(QUEST_TO_THE_DREAMGROVE, 4))
            {
                player->CastSpell(player, 204836, true);
                PhasingHandler::AddPhase(player, 6122, true);
            }
            else if (!player->GetQuestObjectiveData(QUEST_TO_THE_DREAMGROVE, 3))
            {
                PhasingHandler::AddPhase(player, 5953, true);
                PhasingHandler::AddPhase(player, 6122, true);
            }

            if (player->GetQuestObjectiveData(QUEST_TO_THE_DREAMGROVE, 3) || player->GetQuestStatus(QUEST_TO_THE_DREAMGROVE) == QUEST_STATUS_COMPLETE || player->GetQuestStatus(QUEST_TO_THE_DREAMGROVE) == QUEST_STATUS_REWARDED)
            {
                PhasingHandler::RemovePhase(player, 6122, true);
            }
        }
    }
};

///phase 5924 - 5953 - 6122
///ID - 204836 ??????
struct npc_keeper_remulos_103489 : public ScriptedAI
{
    npc_keeper_remulos_103489(Creature* creature) : ScriptedAI(creature) { Initialize(); }

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
        _scheduler.Update(diff);
    }

    void MovementInform(uint32 /*type*/, uint32 id) override
    {
        switch (id)
        {
        case 3:
            if (Player* player = ObjectAccessor::GetPlayer(*me, m_playerGUID))
            {
                player->KilledMonsterCredit(me->GetEntry());
                Talk(3);
                me->GetMotionMaster()->MovePoint(4, Position(1695.87f, 1545.05f, 2.6423f, 5.735f), true);
                PhasingHandler::AddPhase(player, 5953, true);
                //PhasingHandler::RemovePhase(player, 5954, true);
            }
        case 4:
            me->DespawnOrUnsummon(2000);
            break;
        default:
            break;
        }
    }
    void Initialize()
    {
        m_playerGUID = ObjectGuid::Empty;
        SayFirst = false;
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (!who || !who->IsInWorld())
            return;
        if (!me->IsWithinDist(who, 15.0f, false))
        {
            //RemovePlayer();
            return;
        }
        Player* player = who->GetCharmerOrOwnerPlayerOrPlayerItself();
        if (!player)
            return;
        if (!SayFirst && (player->HasQuest(QUEST_TO_THE_DREAMGROVE)))// to do
        {
            player->KilledMonsterCredit(73451);
            m_playerGUID = player->GetGUID();
            SayFirst = true;
            Talk(0);
            me->SetWalk(false);
            me->GetMotionMaster()->MovePoint(1, Position(7391.678f, -2343.4f, 478.5645f), true);
            DoAction(1);
            _scheduler.Schedule(Milliseconds(1000), [this, player](TaskContext context)
            {
                me->GetMotionMaster()->MovePoint(1, Position(1536.2015f, 1622.9069f, 25.22f, 6.209f), true);
            });
            _scheduler.Schedule(Milliseconds(6000), [this, player](TaskContext context)
            {
                Talk(1);
                me->GetMotionMaster()->MovePoint(2, Position(1582.712646f, 1618.0842f, 15.145f, 5.721f), true);
            });
            _scheduler.Schedule(Milliseconds(11000), [this, player](TaskContext context)
            {
                Talk(2);
            });
            _scheduler.Schedule(Milliseconds(20000), [this, player](TaskContext context)
            {
                me->GetMotionMaster()->MovePoint(3, Position(1700.725f, 1547.835f, 2.549316f, 5.72f), true);
            });
        }
    }
private:

    TaskScheduler _scheduler;
    std::set<ObjectGuid> pList;
    ObjectGuid   m_playerGUID;
    bool SayFirst;
};

struct npc_keeper_remulos_103488 : public ScriptedAI
{
    npc_keeper_remulos_103488(Creature* creature) : ScriptedAI(creature) { action = 0; }

    enum
    {
        SPELL_ATTARK = 204842,
        ACTION_1 = 1,
        ACTION_2 = 2,
        ACTION_3 = 3,
    };

    void DoAction(int32 param)
    {
        switch (param)
        {
        case ACTION_1:
            PhasingHandler::AddPhase(me, 6122, true);
            _scheduler.Schedule(2s, 3s, [this](TaskContext context)
            {
                if (GameObject* go = me->FindNearestGameObject(250363, 20.0f))
                    me->CastSpell(go, SPELL_ATTARK, false);
                context.Repeat(4s);
            });
            break;
        case ACTION_2:
            PhasingHandler::RemovePhase(me, 6122, true);
            break;
        case ACTION_3:
            Talk(1);
            me->SetWalk(false);
            me->GetMotionMaster()->MovePoint(1, Position(1734.642456f, 1381.86731f, 4.024f, 1.6092f), true);
            _scheduler.Schedule(Milliseconds(5000), [this](TaskContext context)
            {
                me->GetMotionMaster()->MovePoint(2, Position(1728.859741f, 1431.163208f, 10.0241f, 1.412877f), true);
            });
            _scheduler.Schedule(Milliseconds(10000), [this](TaskContext context)
            {
                me->GetMotionMaster()->MovePoint(3, Position(1738.126709f, 1474.335815f, 10.189967f, 1.090864f), true);
            });
            _scheduler.Schedule(Milliseconds(18000), [this](TaskContext context)
            {
                me->GetMotionMaster()->MovePoint(4, Position(1758.78125f, 1508.856445f, 6.571756f, 6.237577f), true);
            });
            _scheduler.Schedule(Milliseconds(25000), [this](TaskContext context)
            {
                me->GetMotionMaster()->MovePoint(4, Position(1781.30957f, 1504.709f, 9.361588f, 5.992398f), true);
            });
            _scheduler.Schedule(Milliseconds(30000), [this](TaskContext context)
            {
                me->DespawnOrUnsummon(1000);
            });
            break;
        }
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
        if (!action && player->HasQuest(QUEST_TO_THE_DREAMGROVE))
        {
            if (!player->GetQuestObjectiveData(QUEST_TO_THE_DREAMGROVE, 3))
            {
                action = true;
                DoAction(ACTION_1);
                _scheduler.Schedule(30s, 31s, [this](TaskContext context)
                {
                    DoAction(ACTION_2);
                });
            }
            if (player->GetQuestObjectiveData(QUEST_TO_THE_DREAMGROVE, 3))
            {
                PhasingHandler::RemovePhase(player, 6122, true);
                action = true;
                Talk(0);
                _scheduler.Schedule(2s, 3s, [this](TaskContext context)
                {
                    DoAction(ACTION_3);
                });
            }

        }
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
    uint32 action;
};


struct npc_nightmare_blight_103246 : public ScriptedAI
{
    npc_nightmare_blight_103246(Creature* creature) : ScriptedAI(creature) { }

    void JustDied(Unit* killer) override
    {
        if (killer->IsPlayer())
        {
            killer->ToPlayer()->KilledMonsterCredit(me->GetEntry());
            PhasingHandler::AddPhase(killer, 5954, true);
            PhasingHandler::RemovePhase(killer, 5953, true);
            killer->ToPlayer()->SummonCreature(NPC_KEEPER_REMULOS_103488, Position(1720.639f, 1347.214f, 2.08268f, 4.830286f), TEMPSUMMON_TIMED_DESPAWN, 60000, 0, true);

            //PhasingHandler::RemovePhase(killer, 6122, true);
        }

    }

    void EnterCombat(Unit* victim)
    {
        ///
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);

        if (!UpdateVictim())
            return;
        DoSpellAttackIfReady(208292);
        if (!DoSpellAttackIfReady(208292))
        {
            DoMeleeAttackIfReady();
        }


    }

private:
    TaskScheduler _scheduler;
};


enum
{
    AURA_ARCHDRUIDS_LUNARWING_FORM = 231437,
    QUEST_YOU_CANT_TAKE_THE_SKY_FROM_ME = 46319,
    SPELL_UNLEARN_ARCHDRUIDS_LUNARWING_FORM = 243612,
    SPELL_LEARN_ARCHDRUIDS_LUNARWING_FORM = 243616,
    ACTION_UNLEARN_ARCHDRUIDS_LUNARWING_FORM = 1,
    ACTION_LEARN_ARCHDRUIDS_LUNARWING_FORM = 2,
};
struct npc_skycaller_faeb_122095 : public ScriptedAI
{
    npc_skycaller_faeb_122095(Creature* creature) : ScriptedAI(creature) { }


    void sGossipHello(Player* player)
    {
        QuestStatus status = player->GetQuestStatus(QUEST_YOU_CANT_TAKE_THE_SKY_FROM_ME);

        if (status == QUEST_STATUS_REWARDED || player->IsGameMaster())
        {
            CanSwitch = true;
            ClearGossipMenuFor(player);
            if (player->HasAura(AURA_ARCHDRUIDS_LUNARWING_FORM))
            {
                Action = ACTION_UNLEARN_ARCHDRUIDS_LUNARWING_FORM;
                AddGossipItemFor(player, 21079, 1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                SendGossipMenuFor(player, player->GetGossipTextId(me), me->GetGUID());///31949
            }
            else
            {
                Action = ACTION_LEARN_ARCHDRUIDS_LUNARWING_FORM;
                AddGossipItemFor(player, 21079, 0, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
                SendGossipMenuFor(player, player->GetGossipTextId(me), me->GetGUID());///31949
            }
        }
        else
        {
            CanSwitch = false;
            ClearGossipMenuFor(player);
            if (me->IsQuestGiver())
                player->PrepareQuestMenu(me->GetGUID()); /* return true*/
            SendGossipMenuFor(player, player->GetGossipTextId(me), me->GetGUID());
        }
    }

    void sGossipSelect(Player* player, uint32 menuId, uint32 gossipListId)
    {
        CloseGossipMenuFor(player);
        if (CanSwitch)
        {
            switch (Action)
            {
            case ACTION_UNLEARN_ARCHDRUIDS_LUNARWING_FORM:
                me->CastSpell(player, SPELL_UNLEARN_ARCHDRUIDS_LUNARWING_FORM, true);
                player->RemoveAurasDueToSpell(AURA_ARCHDRUIDS_LUNARWING_FORM);
                break;
            case ACTION_LEARN_ARCHDRUIDS_LUNARWING_FORM:
                me->CastSpell(player, SPELL_LEARN_ARCHDRUIDS_LUNARWING_FORM, true);
                player->LearnSpell(AURA_ARCHDRUIDS_LUNARWING_FORM, true);
                break;
            default:
                break;
            }
        }

    }
    bool CanSwitch;
    uint32 Action;
};

struct npc_grove_tender_98029 : public ScriptedAI
{
    npc_grove_tender_98029(Creature* creature) : ScriptedAI(creature) { Initialize(); }

    void Initialize()
    {
        isCast = false;
    }
    void MoveInLineOfSight(Unit* who) override
    {
        if (!who || !who->IsInWorld())
            return;
        if (!me->IsWithinDist(who, 15.0f, false))
            return;
        if (!isCast && who->GetEntry() == 98307)
        {
            isCast = true;
            _scheduler.Schedule(2s, 3s, [this, who](TaskContext context)
            {
                me->SetTarget(who->GetGUID());
                DoCast(who, 194361);
                context.Repeat(4s);
            });
        }
    }
    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }
private:
    bool isCast;
    TaskScheduler _scheduler;
};

struct npc_laughing_sister_98027 : public ScriptedAI
{
    npc_laughing_sister_98027(Creature* creature) : ScriptedAI(creature) { Initialize(); }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }
    void Initialize()
    {
        m_playerGUID = ObjectGuid::Empty;
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

    void MoveInLineOfSight(Unit* who) override
    {
        if (!who || !who->IsInWorld())
            return;
        if (!me->IsWithinDist(who, 15.0f, false))
            return;
        Player* player = who->GetCharmerOrOwnerPlayerOrPlayerItself();
        if (!player)
            return;
        if (!HasPlayer(player->GetGUID()))
        {
            if (roll_chance_i(5))
            {
                m_playerGUID = player->GetGUID();
                AddPlayer();
                Talk(0, player);
            }
        }
    }
private:
    TaskScheduler _scheduler;
    std::set<ObjectGuid> pList;
    ObjectGuid   m_playerGUID;
};


struct npc_rensar_greathoof_101195 : public ScriptedAI
{
    npc_rensar_greathoof_101195(Creature* creature) : ScriptedAI(creature) { }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Player* player = who->ToPlayer())
        {
            if (me->IsWithinDist(player, 15.0f, false))
            {
                if (!IsLock && player->GetQuestStatus(QUEST_TO_THE_DREAMGROVE) == QUEST_STATUS_INCOMPLETE && !player->GetQuestObjectiveData(QUEST_TO_THE_DREAMGROVE, 2))
                {
                    IsLock = true;
                    if (Creature* remulos = me->FindNearestCreature(NPC_KEEPER_REMULOS_103832, 15.0f))
                    {
                        remulos->Say(103622, me);
                        me->GetScheduler().Schedule(5s, [this, remulos](TaskContext context)
                        {
                            me->Say("Ishnu-alah, son of Cenarius. I'm well aware of what brings you. I've heard the screams of the land as it is defiled by the Legion.", LANG_UNIVERSAL, remulos);
                        });
                        me->GetScheduler().Schedule(10s, [this, remulos](TaskContext context)
                        {
                            remulos->Say("We must act swiftly and prepare the weapons of old for war once again.", LANG_UNIVERSAL, me);
                        });
                        me->GetScheduler().Schedule(15s, [this, remulos](TaskContext context)
                        {
                            me->Say("The weapons of the first druids can surely turn the tide in our favor, but is there anyone with the strength to wield them?", LANG_UNIVERSAL, remulos);
                        });
                        me->GetScheduler().Schedule(20s, [this, remulos, player](TaskContext context)
                        {
                            remulos->Say(103626, player);
                        });
                        me->GetScheduler().Schedule(25s, [this, remulos, player](TaskContext context)
                        {
                            me->Say("Very well, your task will not be easy but I shall do all that I can to aid you.", LANG_UNIVERSAL, player);
                            player->KilledMonsterCredit(101246);
                            IsLock = false;
                        });
                        ///Ishnu-alah, son of Cenarius. I'm well aware of what brings you. I've heard the screams of the land as it is defiled by the Legion.
                        ///We must act swiftly and prepare the weapons of old for war once again.
                        ///The weapons of the first druids can surely turn the tide in our favor, but is there anyone with the strength to wield them?
                        ///103626 There is no one better suited for this task than $n.
                        ///Very well, your task will not be easy but I shall do all that I can to aid you.
                    }
                }
                if (!IsLock && player->GetQuestStatus(QUEST_RECONVENE) == QUEST_STATUS_COMPLETE)
                {
                    IsLock = true;
                    if (Creature* remulos = me->FindNearestCreature(NPC_KEEPER_REMULOS_103832, 15.0f))
                    {
                        me->Say("g'hanir will not last much longer.It must be cleansed.", LANG_UNIVERSAL, remulos);
                        me->GetScheduler().Schedule(4s, [remulos, player](TaskContext context)
                        {
                            remulos->Say("We must aid Bashana in clearing out the remaining nightmare here. G'Hanir's fate rests with Lyessa and $n.", LANG_UNIVERSAL, player);
                        });
                    }
                    SetUnlock(120000);
                }
            }
        }
    }

    void sQuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_WEAPONS_OF_LEGEND || quest->GetQuestId() == QUEST_ANOTHER_WEAPON_OF_OLD || quest->GetQuestId() == QUEST_MORE_WEAPONS_OF_OLD || quest->GetQuestId() == QUEST_WEAPONS_OF_THE_ANCIENTS)
        {
            me->GetScheduler().Schedule(2s, [player](TaskContext context)
            {
                player->CastSpell(player, SPELL_WEAPONS_OF_LEGEND_PLAYER_CHOICE, true);
            });
        }
        if (quest->GetQuestId() == QUEST_SOWING_THE_SEED)
            Talk(1);
    }

    void sQuestReward(Player* player, Quest const* quest, uint32 /*opt*/)  override
    {
        ///https://www.wowhead.com/achievement=11063/hidden-tracking-1-acquision-line-completed
        ///https://www.wowhead.com/achievement=11174/hidden-tracking-2-acquision-line-completed
        if (quest->GetQuestId() == 40900 || quest->GetQuestId() == 41918 || quest->GetQuestId() == 42430 || quest->GetQuestId() == 40647 || quest->GetQuestId() == 41689)
        {
            if (!player->HasAchieved(11063))
                player->CompletedAchievement(11063);
            else if (!player->HasAchieved(11174))
                player->CompletedAchievement(11174);
            if (player->GetQuestStatus(QUEST_SOWING_THE_SEED) == QUEST_STATE_NONE)
                if (const Quest* quest = sObjectMgr->GetQuestTemplate(QUEST_SOWING_THE_SEED))
                    player->AddQuest(quest, me);
        }
        if (quest->GetQuestId() == 43409)
        {
            player->CompletedAchievement(10994);
            player->CompletedAchievement(10746);
        }
    }
    /*
    void sGossipHello(Player* player)
    {
        QuestStatus status = player->GetQuestStatus(QUEST_TO_THE_DREAMGROVE);
        if (status == QUEST_STATUS_INCOMPLETE || status == QUEST_STATUS_COMPLETE || status == QUEST_STATUS_REWARDED)
        {
        }
        if (player->GetQuestStatus(QUEST_TO_THE_DREAMGROVE) == QUEST_STATUS_INCOMPLETE)
        {
            ClearGossipMenuFor(player);
            //AddGossipItemFor(player, GOSSIP_ICON_CHAT, string_To_UTF8(GOSSIP_NATHANOS_BLIGHTCALLER), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
            SendGossipMenuFor(player, player->GetGossipTextId(me), me->GetGUID());
        }
        else
            if (player->GetQuestStatus(QUEST_TO_THE_DREAMGROVE) == QUEST_STATUS_INCOMPLETE)
            {
                ClearGossipMenuFor(player);
                if (me->IsQuestGiver())
                    player->PrepareQuestMenu(me->GetGUID());
                SendGossipMenuFor(player, player->GetGossipTextId(me), me->GetGUID());
            }
    }
    */
    void sGossipSelect(Player* player, uint32 menuId, uint32 gossipListId)
    {
        CloseGossipMenuFor(player);
        player->CastSpell(player, SPELL_WEAPONS_OF_LEGEND_PLAYER_CHOICE, true);
    }

private:
    TaskScheduler _scheduler;
    std::set<ObjectGuid> pList;
    ObjectGuid   m_playerGUID;
};

class druid_weapons_of_legend_player_choice : public PlayerScript {
public:
    druid_weapons_of_legend_player_choice() : PlayerScript("druid_weapons_of_legend_player_choice") {}

    void OnQuestStatusChange(Player* player, uint32 /*questId*/)
    {
       // if (player->getClass() == CLASS_DRUID || player->getLevel() >= 98)
      //      OnCheckPhase(player);
    }

    void OnPlayerChoiceResponse(Player* player, uint32 choiceId, uint32 responseId)
    {
        if (player->getClass() != CLASS_DRUID)
            return;
        if (choiceId != PLAYER_CHOICE_DRUID_SELECTION)
            return;

        TC_LOG_DEBUG("server.worldserver", "druid_playerchoice %u, %u", choiceId, responseId);
        if (player->HasQuest(QUEST_WEAPONS_OF_LEGEND))
            player->KilledMonsterCredit(101296);
        if (player->HasQuest(QUEST_ANOTHER_WEAPON_OF_OLD))
            player->KilledMonsterCredit(112077);
        if (player->HasQuest(QUEST_MORE_WEAPONS_OF_OLD) || player->HasQuest(QUEST_WEAPONS_OF_THE_ANCIENTS))
            player->KilledMonsterCredit(113814);
        switch (responseId)
        {
        case PLAYER_CHOICE_DRUID_BALANCE:
            if (player->GetQuestStatus(QUEST_THE_SCYTHE_OF_ELUNE) == QUEST_STATUS_NONE)
                if (Creature* naralex = player->FindNearestCreature(NPC_NARALEX_103778, 15.0f, true))
                {
                    naralex->Say(106125, player);
                    if (const Quest* quest = sObjectMgr->GetQuestTemplate(QUEST_THE_SCYTHE_OF_ELUNE))
                        player->AddQuest(quest, naralex);
                    naralex->GetScheduler().Schedule(Milliseconds(2000), [player](TaskContext context)
                    {
                        GetContextCreature()->Say(106128, player);
                    });
                }
            break;
        case PLAYER_CHOICE_DRUID_FERAL:
            if (player->GetQuestStatus(QUEST_THE_SHRINE_OF_ASHAMANE) == QUEST_STATUS_NONE)
                if (const Quest* quest = sObjectMgr->GetQuestTemplate(QUEST_THE_SHRINE_OF_ASHAMANE))
                    player->AddQuest(quest, nullptr);
            break;
        case PLAYER_CHOICE_DRUID_GUARDIAN:
            if (player->GetQuestStatus(QUEST_MISTRESS_OF_THE_CLAW) == QUEST_STATUS_NONE)
                if (const Quest* quest = sObjectMgr->GetQuestTemplate(QUEST_MISTRESS_OF_THE_CLAW))
                    player->AddQuest(quest, nullptr);
            break;
        case PLAYER_CHOICE_DRUID_RESTORATION:
            if (player->GetQuestStatus(QUEST_MEET_WITH_MYLUNE) == QUEST_STATUS_NONE)
                if (const Quest* quest = sObjectMgr->GetQuestTemplate(QUEST_MEET_WITH_MYLUNE))
                    player->AddQuest(quest, nullptr);
            break;
        default:
            break;
        }

        //DATA0 68479 DATA1  33135
        if (GameObject* bounty = player->FindNearestGameObjectOfType(GAMEOBJECT_TYPE_CHALLENGE_MODE_REWARD, 500.0f))
        {
            bounty->SetGoState(GO_STATE_READY);//GO_STATE_ACTIVE  GO_STATE_ACTIVE_ALTERNATIVE GO_STATE_READY
            printf("FindNearestGameObjectOfType2\n");

            bounty->loot.clear();
            bounty->loot.FillLoot(153123, LootTemplates_Gameobject, player, true);

        //    bounty->SetLootRecipient(player);
            bounty->SetLootState(LootState::GO_READY);// if ((GetGoState() != GO_STATE_READY && (state == GO_ACTIVATED || state == GO_JUST_DEACTIVATED)) || state == GO_READY)

            bounty->setActive(true);
            //GO_FLAG_LOCKED
            bounty->AddDynamicFlag(GO_DYNFLAG_LO_ACTIVATE);
            bounty->RemoveFlag(GO_FLAG_LOCKED);
            bounty->RemoveFlag(GO_FLAG_NOT_SELECTABLE);

        }

    }

    /*void OnCheckPhase(Player* player) 
    {
        if (player->getClass() == CLASS_DRUID || player->getLevel() >= 98)
        {
            if (player->GetAreaId() == 2363)
            {
                if (player->CheckQuestStatus(QUEST_THE_DREAMWAY, CHECK_QUEST_COMPLETE_AND_REWARDED))
                    PhasingHandler::AddPhase(player, 1526);
                if (player->CheckQuestStatus(QUEST_TO_THE_DREAMGROVE, CHECK_QUEST_COMPLETE_AND_REWARDED))
                    PhasingHandler::RemovePhase(player, 1526);
            }
            if (player->GetAreaId() == 7846 || player->GetZoneId() == 7846)
            {
                if (player->CheckQuestStatus(QUEST_IN_DEEP_SLUMBER, CHECK_QUEST_TAKEN_AND_COMPLETE_AND_REWARDED))
                {
                    PhasingHandler::AddPhase(player, PHASE_IN_DEEP_SLUMBER);
                    PhasingHandler::AddPhase(player, 6356);
                }
                if (player->CheckQuestStatus(QUEST_RECONVENE, CHECK_QUEST_TAKEN_AND_COMPLETE_AND_REWARDED))
                {
                    PhasingHandler::RemovePhase(player, PHASE_IN_DEEP_SLUMBER);
                    PhasingHandler::RemovePhase(player, 6356);

                    PhasingHandler::AddPhase(player, 5980);
                }
                if (player->CheckQuestStatus(QUEST_CLEANSING_THE_MOTHER_TREE, CHECK_QUEST_REWARDED))
                    PhasingHandler::RemovePhase(player, 5980);
            }*/
    //    }
   // }
};

struct npc_keeper_remulos_103832 : public ScriptedAI
{
    npc_keeper_remulos_103832(Creature* creature) : ScriptedAI(creature) { }

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
        _scheduler.Update(diff);
    }

    void sQuestAccept(Player* player, Quest const* quest) override
    {
        //if (quest->GetQuestId() == QUEST_WITNESS_TO_THE_WOUND)
       // {   }
    }

    void sQuestReward(Player* player, Quest const* quest, uint32 /*opt*/)  override
    {
        //if (quest->GetQuestId() == QUEST_WITNESS_TO_THE_WOUND)
        //{ }
    }

private:
    TaskScheduler _scheduler;
};

struct npc_lea_stonepaw_101259 : public ScriptedAI
{
    npc_lea_stonepaw_101259(Creature* creature) : ScriptedAI(creature) { isSayHi = false; }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
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
        if (!isSayHi && player->HasQuest(QUEST_MISTRESS_OF_THE_CLAW))
        {
            isSayHi = true;
            Talk(0);
            player->ForceCompleteQuest(QUEST_MISTRESS_OF_THE_CLAW);
        }
    }

    void sQuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_TO_THE_HILLS)
            Talk(1);
    }
private:
    TaskScheduler _scheduler;
    bool isSayHi;
};

enum
{
    NPC_LEA_STONEPAW_104535 = 104535,
    QUEST_WHEN_DREAMS_BECOME_NIGHTMARES = 40647,
};

struct npc_lea_stonepaw_104535 : public ScriptedAI
{
    npc_lea_stonepaw_104535(Creature* creature) : ScriptedAI(creature) {  }

    void DoAction(int32 param)
    {
        switch (param)
        {
        case 1:
            //me->Say(107662);
            break;
        }
    }
    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (!who || !who->IsInWorld())
            return;
        if (!me->IsWithinDist(who, 15.0f, true))
            return;

        Player* player = who->GetCharmerOrOwnerPlayerOrPlayerItself();
        if (!player)
            return;
        if (player->HasQuest(QUEST_TO_THE_HILLS) && !player->GetQuestObjectiveData(QUEST_TO_THE_HILLS, 2))
        {
            me->Say(106956, player);
            player->KilledMonsterCredit(104410);
        }
    }

    void sQuestReward(Player* player, Quest const* quest, uint32 /*opt*/)  override
    {
        if (quest->GetQuestId() == QUEST_FALLEN_OFFERINGS)
        {
            ///call ursol
            me->Say(107322, player);
            me->TextEmote(107346, player);

            _scheduler.Schedule(1s, 2s, [this, player](TaskContext context)
            {
                me->TextEmote(107346, player);
            });
            if (Creature* ursol = me->FindNearestCreature(NPC_KEEPER_REMULOS_103832, 15.0f))
            {
                _scheduler.Schedule(3s, 4s, [this, ursol, player](TaskContext context)
                {
                    ursol->Yell(107080, player);
                });
            }

            _scheduler.Schedule(5s, 6s, [this, player](TaskContext context)
            {
                me->Say(107402, player);
            });
        }
    }

    void sQuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_WHEN_DREAMS_BECOME_NIGHTMARES)
        {
            me->Say(106957, player);
        }
    }

    TaskScheduler _scheduler;
};

enum
{
    NPC_URSOL_104385 = 104385,
    QUEST_THE_FIRST_TRIAL_OF_URSOL = 41790, //104714
    QUEST_THE_SECOND_TRIAL_OF_URSOL = 41791,
    QUEST_THE_THIRD_TRIAL_OF_URSOL = 41792,
    NPC_ANCESTRAL_CHAMPION_104714 = 104714,
    NPC_ANCESTRAL_WARRIOR_104936 = 104936,
    NPC_ANCESTRAL_SHAMAN_104937 = 104937,
    NPC_ANCESTRAL_SHAMAN_105110 = 105110,

    ACTION_TRIAL_OF_URSOL_1 = 1,
    ACTION_TRIAL_OF_URSOL_2 = 2,
    ACTION_TRIAL_OF_URSOL_3 = 3,
    ACTION_TRIAL_OF_URSOL_KILL = 4,
};

struct npc_ursol_104385 : public ScriptedAI
{
    npc_ursol_104385(Creature* creature) : ScriptedAI(creature) { }

    void DoAction(int32 param)
    {
        switch (param)
        {
        case ACTION_TRIAL_OF_URSOL_1:
            killedCount = 0;
            restSummonCount = 1;
            me->GetScheduler().Schedule(1s, 2s, [this](TaskContext context)
            {
                Position pos;
                GetRandPosFromCenterInDist(me, 30.f, pos);
                pos.m_positionZ = 127.383f;
                if (TempSummon* temp = me->SummonCreature(NPC_ANCESTRAL_CHAMPION_104714, pos))
                {
                    if (Player* player = ObjectAccessor::GetPlayer(*me, m_playerGUID))
                        temp->GetMotionMaster()->MovePoint(1, player->GetPosition(), true);
                    temp->Say("That creature unworthy of you, great Ursol! I crush it in your name!", LANG_UNIVERSAL);
                }
            });
            break;
        case ACTION_TRIAL_OF_URSOL_KILL:
            ++killedCount;
            if (killedCount == restSummonCount)
            {
                if (Player* player = ObjectAccessor::GetPlayer(*me, m_playerGUID))
                {
                    //player->KilledMonsterCredit(104714);
                    if (player->HasQuest(QUEST_THE_SECOND_TRIAL_OF_URSOL))
                        player->KilledMonsterCredit(104545);

                    if (player->HasQuest(QUEST_THE_THIRD_TRIAL_OF_URSOL))
                    {
                        me->Say(107516, player);
                        player->KilledMonsterCredit(104535);
                    }
                }
            }
            break;
        case ACTION_TRIAL_OF_URSOL_2:
            killedCount = 0;
            restSummonCount = 9;
            _scheduler.Schedule(1s, 2s, [this](TaskContext context)
            {
                sSummonCreature(NPC_ANCESTRAL_WARRIOR_104936);
                sSummonCreature(NPC_ANCESTRAL_WARRIOR_104936);
            });
            _scheduler.Schedule(11s, 12s, [this](TaskContext context)
            {
                sSummonCreature(NPC_ANCESTRAL_WARRIOR_104936);
                sSummonCreature(NPC_ANCESTRAL_WARRIOR_104936);
                sSummonCreature(NPC_ANCESTRAL_SHAMAN_104937);
            });
            _scheduler.Schedule(22s, 23s, [this](TaskContext context)
            {
                sSummonCreature(NPC_ANCESTRAL_WARRIOR_104936);
                sSummonCreature(NPC_ANCESTRAL_WARRIOR_104936);
                sSummonCreature(NPC_ANCESTRAL_SHAMAN_104937);
                sSummonCreature(NPC_ANCESTRAL_SHAMAN_104937);
            });
            break;
        case ACTION_TRIAL_OF_URSOL_3:
            killedCount = 0;
            restSummonCount = 8;
            _scheduler.Schedule(3s, 4s, [this](TaskContext context)
            {
                me->Say("Is there anyone who would fight at your side, druid?", LANG_UNIVERSAL);
            });
            _scheduler.Schedule(5s, 6s, [this](TaskContext context)
            {
                if (Creature* lea = me->FindNearestCreature(NPC_LEA_STONEPAW_104535, 50.0f))
                    lea->Say(107513);
            });
            _scheduler.Schedule(8s, 10s, [this](TaskContext context)
            {
                me->Say(107157);
            });
            _scheduler.Schedule(10s, 12s, [this](TaskContext context)
            {
                me->Say(107158);
            });
            _scheduler.Schedule(12s, 13s, [this](TaskContext context)
            {
                me->Say(107160);
            });
            _scheduler.Schedule(15s, 16s, [this](TaskContext context)
            {
                sSummonCreature(NPC_ANCESTRAL_WARRIOR_104936);
                sSummonCreature(NPC_ANCESTRAL_WARRIOR_104936);
            });
            _scheduler.Schedule(20s, 21s, [this](TaskContext context)
            {
                sSummonCreature(NPC_ANCESTRAL_SHAMAN_104937);
                sSummonCreature(NPC_ANCESTRAL_WARRIOR_104936);
            });
            _scheduler.Schedule(25s, 26s, [this](TaskContext context)
            {
                sSummonCreature(NPC_ANCESTRAL_WARRIOR_104936);
                sSummonCreature(NPC_ANCESTRAL_WARRIOR_104936);
            });
            _scheduler.Schedule(30s, 31s, [this](TaskContext context)
            {
                sSummonCreature(NPC_ANCESTRAL_SHAMAN_104937);
                sSummonCreature(NPC_ANCESTRAL_WARRIOR_104936);
            });
            break;
        }
    }

    void sSummonCreature(uint32 creatureid)
    {
        if (Player* player = ObjectAccessor::GetPlayer(*me, m_playerGUID))
        {
            if (player->IsAlive())
            {
                Position pos;
                GetRandPosFromCenterInDist(me, 30.f, pos);
                pos.m_positionZ = 127.383f;
                if (TempSummon* temp = me->SummonCreature(creatureid, pos))
                    temp->GetMotionMaster()->MovePoint(1, player->GetPosition(), true);
            }
            else
                _scheduler.CancelAll();
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

    void sQuestAccept(Player* player, Quest const* quest) override
    {
        if (player->HasQuest(QUEST_THE_FIRST_TRIAL_OF_URSOL))
        {
            me->Say(107141, player);
            DoAction(ACTION_TRIAL_OF_URSOL_1);
        }
        if (player->HasQuest(QUEST_THE_SECOND_TRIAL_OF_URSOL))
        {
            me->Say(107154, player);
            DoAction(ACTION_TRIAL_OF_URSOL_2);
        }
        if (player->HasQuest(QUEST_THE_THIRD_TRIAL_OF_URSOL))
            me->Say(107508, player);

    }

    void sQuestReward(Player* player, Quest const* quest, uint32 /*opt*/)  override
    {
        if (quest->GetQuestId() == QUEST_THE_SECOND_TRIAL_OF_URSOL)
        {
            me->Say(107155, player);
            _scheduler.Schedule(3s, 4s, [this](TaskContext context)
            {
                if (Creature* lea = me->FindNearestCreature(NPC_LEA_STONEPAW_104535, 50.0f))
                    lea->Say(107662);
            });
        }
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

        m_playerGUID = player->GetGUID();
    }

    void sGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId)
    {
        CloseGossipMenuFor(player);
        if (player->HasQuest(QUEST_THE_THIRD_TRIAL_OF_URSOL))
        {
            player->KilledMonsterCredit(104981);
            me->Say(107156, player);
            DoAction(ACTION_TRIAL_OF_URSOL_3);
        }
    }
private:
    uint8 restSummonCount;
    uint8 killedCount;
    TaskScheduler _scheduler;
    ObjectGuid   m_playerGUID;
};
///104714
///me->Say("That creature unworthy of you, great Ursol! I crush it in your name!", LANG_UNIVERSAL, player);
struct npc_ancestral_champion_104714 : public ScriptedAI
{
    npc_ancestral_champion_104714(Creature* creature) : ScriptedAI(creature) { }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);

        if (!UpdateVictim())
            return;
        DoMeleeAttackIfReady();
    }

    void DamageTaken(Unit* attacker, uint32& damage) override
    {
        if (me->HealthWillBeBelowPctDamaged(10, damage))
        {
            Player* player = attacker->GetCharmerOrOwnerPlayerOrPlayerItself();
            me->Yell(107150, player);
            if (Creature* ursol = me->FindNearestCreature(NPC_URSOL_104385, 25.0f))
            {
                ursol->Say(107151);
            }
        }
    }

    void JustDied(Unit* killer) override
    {
        Player* player = killer->GetCharmerOrOwnerPlayerOrPlayerItself();
        player->KilledMonsterCredit(me->GetEntry());
        me->DespawnOrUnsummon(1000);
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (!who || !who->IsInWorld())
            return;
        if (!me->IsWithinDist(who, 25.0f, false))
            return;
        Player* player = who->GetCharmerOrOwnerPlayerOrPlayerItself();
        if (!player)
            return;
        AttackStart(player);
    }
private:
    TaskScheduler _scheduler;
};

struct npc_ancestral_warrior_104936 : public ScriptedAI
{
    npc_ancestral_warrior_104936(Creature* creature) : ScriptedAI(creature) { }

    void JustDied(Unit* /*killer*/) override
    {
        if (Creature* ursol = me->FindNearestCreature(NPC_URSOL_104385, 50.0f, true))
        {
            ursol->AI()->DoAction(ACTION_TRIAL_OF_URSOL_KILL);
        }
    }
    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
        if (!UpdateVictim())
            return;
        /*
        if (uiTimerEyeGouge <= uiDiff)
        {
            if (Unit* victim = me->GetVictim())
            {
                me->CastSpell(victim, IsHeroic() ? SPELL_EYE_GOUGE_H : SPELL_EYE_GOUGE);
            }
            uiTimerEyeGouge = urand(9000, 12000);
            return;
        }
        else uiTimerEyeGouge -= uiDiff;*/
        DoMeleeAttackIfReady();
    }


    void MoveInLineOfSight(Unit* who) override
    {
        if (!who || !who->IsInWorld())
            return;
        if (!me->IsWithinDist(who, 25.0f, false))
            return;
        Player* player = who->GetCharmerOrOwnerPlayerOrPlayerItself();
        if (!player)
            return;
        AttackStart(player);
    }
private:
    TaskScheduler _scheduler;
};


/// 105110  104937
struct npc_ancestral_shaman_104937 : public ScriptedAI
{
    npc_ancestral_shaman_104937(Creature* creature) : ScriptedAI(creature) {}

    void JustDied(Unit* /*killer*/) override
    {
        if (Creature* ursol = me->FindNearestCreature(NPC_URSOL_104385, 50.0f, true))
        {
            ursol->AI()->DoAction(ACTION_TRIAL_OF_URSOL_KILL);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;
        else
            DoSpellAttackIfReady(12058);
    }


    void MoveInLineOfSight(Unit* who) override
    {
        if (!who || !who->IsInWorld())
            return;
        if (!me->IsWithinDist(who, 25.0f, false))
        {
            return;
        }
        Player* player = who->GetCharmerOrOwnerPlayerOrPlayerItself();
        if (!player)
            return;

    }
private:
    TaskScheduler _scheduler;
    uint32 attTime;
};


class playerscript_flask_of_moonwell_water : public PlayerScript {
public:
    playerscript_flask_of_moonwell_water() : PlayerScript("playerscript_flask_of_moonwell_water") {}

    void OnSuccessfulSpellCast(Player* player, Spell* spell)
    {
        if (spell->GetSpellInfo()->Id == 206807)
        {
            player->CastSpell(player, SPELL_FADE, true);
            player->AddDelayedTeleport(2000, 1536, -12408.0f, -12955.2f, 320.26f, 4.427202f);
        }
    }
};



///guid 20545289
struct npc_generic_bunny_103560 : public ScriptedAI
{
    npc_generic_bunny_103560(Creature* creature) : ScriptedAI(creature) {}

    void MoveInLineOfSight(Unit* who) override
    {
        if (!who || !who->IsInWorld() || !me->IsWithinDist(who, 10.0f, false))
            return;

        Player* player = who->GetCharmerOrOwnerPlayerOrPlayerItself();
        if (!player)
            return;
        if (player->HasQuest(QUEST_CLEANSING_THE_MOTHER_TREE))
            player->KilledMonsterCredit(104608);
        player->TeleportTo(1540, 1756.753174f, 1509.99231f, 6.278654f, 2.640337f);
    }
};

struct npc_mylune_113525 : public ScriptedAI
{
    npc_mylune_113525(Creature* creature) : ScriptedAI(creature) {  }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Player* player = who->ToPlayer())
        {
            if (me->IsWithinDist(player, 15.0f, false))
            {
                if (!IsLock && player->HasQuest(QUEST_MEET_WITH_MYLUNE) && player->GetQuestStatus(QUEST_MEET_WITH_MYLUNE) == QUEST_STATUS_INCOMPLETE)
                {
                    IsLock = true;
                    me->Say("Oh, frends. I don't know what to do!", LANG_UNIVERSAL, player);
                    player->ForceCompleteQuest(QUEST_MEET_WITH_MYLUNE);
                }
                if (!IsLock && player->HasQuest(QUEST_NECESSARY_PREPARATIONS) && player->GetQuestStatus(QUEST_NECESSARY_PREPARATIONS) == QUEST_STATUS_COMPLETE)
                {
                    IsLock = true;
                    me->Say("Don't worry - $n is going to fix this, just you wait!", LANG_UNIVERSAL, player);
                    SetUnlock(120000);
                }
            }
        }
    }

    void sQuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_NECESSARY_PREPARATIONS)
        {
            IsLock = false;
            Talk(0, player);
            me->GetScheduler().Schedule(Milliseconds(1000), [player](TaskContext context)
            {
                GetContextCreature()->AI()->Talk(1, player);
            });
        }

        if (quest->GetQuestId() == QUEST_NECESSARY_PREPARATIONS)
        {
            me->Say("Be careful - it isn't safe in the Dream right now", LANG_UNIVERSAL, player);
        }
    }
};

struct npc_leafbeard_the_storied_97989 : public ScriptedAI
{
    npc_leafbeard_the_storied_97989(Creature* creature) : ScriptedAI(creature) { Intr = false; }

    void sGossipHello(Player* player)
    {
        if (player->GetQuestStatus(QUEST_NECESSARY_PREPARATIONS) == QUEST_STATUS_INCOMPLETE)
        {
            ClearGossipMenuFor(player);
            if (!Intr)
            {
                AddGossipItemFor(player, 20015, 0, 0, 0);
                SendGossipMenuFor(player, 27432, me->GetGUID());
            }
            else
            {
                AddGossipItemFor(player, 19400, 0, 0, 0);
                SendGossipMenuFor(player, 28594, me->GetGUID());
            }
        }
        else
        {
            CloseGossipMenuFor(player);
            player->GetGarrisonOpenTalentNpc(me->GetGUID());
          //  if (Garrison* garrison = player->GetGarrison(GarrisonType::GARRISON_TYPE_CLASS_HALL))
            //    garrison->StartClassHallUpgrade(347);

            /*
            WorldPackets::Garrison::GarrisonTalent talentData;
            talentData.GarrTalentID = 347;
            talentData.ResearchStartTime = time(nullptr);
            talentData.Flags = ClassHallTalentFlag::CLASS_HALL_TALENT_CHANGE;
            talentData.DbState = DB_STATE_NEW;
            */
        }
    }

    void sGossipSelect(Player* player, uint32 menuId, uint32 gossipListId)
    {
        CloseGossipMenuFor(player);
        if (player->HasQuest(QUEST_NECESSARY_PREPARATIONS) && !Intr)
        {
            Intr = true;
        }
        else if (player->HasQuest(QUEST_NECESSARY_PREPARATIONS) && Intr)
        {
            Talk(0);
            me->CastSpell(player, 206492, true);
            player->KilledMonsterCredit(104342);
            Intr = false;
        }
        printf("sGossipSelect %d %d\n", menuId, gossipListId);
    }
    bool Intr;
};

struct npc_naralex_104349 : public ScriptedAI
{
    npc_naralex_104349(Creature* creature) : ScriptedAI(creature) { }

    void sQuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_IN_DEEP_SLUMBER)
        {
            IsLock = false;
            me->Say("You still have the moonwater, yes? Good, good, then you are ready.", LANG_UNIVERSAL, player);
        }
        if (quest->GetQuestId() == QUEST_RECONVENE)
        {
            me->Say("G'Hanir grows more corrupt with each passing moment - may your feet carry you swiftly.", LANG_UNIVERSAL, player);
        }
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Player* player = who->ToPlayer())
        {
            if (me->IsWithinDist(player, 15.0f, false))
            {
                if (!IsLock && player->HasQuest(QUEST_JOIN_THE_DREAMER))
                {
                    IsLock = true;
                    Talk(0);
                    player->ForceCompleteQuest(QUEST_JOIN_THE_DREAMER);
                    SetUnlock(120000);
                }
                if (!IsLock && player->HasQuest(QUEST_IN_DEEP_SLUMBER) && (player->GetQuestStatus(QUEST_IN_DEEP_SLUMBER) == QUEST_STATUS_COMPLETE || player->GetQuestStatus(QUEST_IN_DEEP_SLUMBER) == QUEST_STATUS_REWARDED))
                {
                    IsLock = true;
                    me->Say("By the Ancients. you have it! You have G'Hanir!", LANG_UNIVERSAL, player);
                    player->RemoveAurasDueToSpell(206552);
                    player->RemoveAurasDueToSpell(206553);
                    player->RemoveAurasDueToSpell(206571);
                    player->RemoveAurasDueToSpell(206566);
                    SetUnlock(120000);
                }
            }
        }
    }
};

class QuestInDeepSlumberUseItem : public PlayerScript
{
public:
    QuestInDeepSlumberUseItem() : PlayerScript("QuestInDeepSlumberUseItem") { }

    void OnSuccessfulSpellCast(Player* player, Spell* spell)
    {
        if (spell->GetSpellInfo()->Id == 206548)
        {
            if (player->HasQuest(QUEST_IN_DEEP_SLUMBER))
            {
                if (Creature* npc = player->FindNearestCreature(NPC_NARALEX_104349, 25.0f, true))
                    npc->AI()->Talk(1);
                //add phase cast spell
                player->CastSpell(player, 206552, true);
                //killcredit
                player->CastSpell(player, 206553, true);
                PhasingHandler::AddPhase(player, PHASE_IN_DEEP_SLUMBER, true);

                player->CastSpell(player, 206571, true);
                player->CastSpell(player, 206566, true);
            }
        }
    }
};
/// spell 206637  conversation NPC 104398

struct npc_bashana_runetotem_104398 : public ScriptedAI
{
    npc_bashana_runetotem_104398(Creature* creature) : ScriptedAI(creature) { Initialize(); }

    void Reset() override
    {
        Initialize();
    }

    void UpdateAI(uint32 diff) override
    {
        if (IsYellHelp && !me->HasAura(206625) && IsHaveAura)
        {
            IsHaveAura = false;
            Talk(0);
            me->GetScheduler().Schedule(Milliseconds(1000), [](TaskContext context)
            {
                GetContextCreature()->AI()->Talk(1);
            });
        }
    }

    void Initialize()
    {
        IsYellHelp = false;
        IsHaveAura = true;
        me->CastSpell(me, 206625, true);
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (!who || !who->IsInWorld() || !me->IsWithinDist(who, 25.0f, false))
            return;

        Player* player = who->GetCharmerOrOwnerPlayerOrPlayerItself();
        if (!player)
            return;
        if (!IsYellHelp && player->HasQuest(QUEST_IN_DEEP_SLUMBER))
        {
            IsYellHelp = true;
            me->Yell("Anyone...someone! I can't escape these roots!", LANG_UNIVERSAL, player);
        }
    }
private:
    bool IsYellHelp;
    bool IsHaveAura;
};

struct npc_lyessa_bloomwatcher_104573 : public ScriptedAI
{
    npc_lyessa_bloomwatcher_104573(Creature* creature) : ScriptedAI(creature) { Initialize(); }

    void DoAction(int32 param)
    {
        switch (param)
        {
        case 1:
            isComplete = true;
            Talk(0);
            me->GetScheduler().Schedule(Milliseconds(2000), [](TaskContext context)
            {
                GetContextCreature()->AI()->Talk(1);
                //GetContextCreature()->CastSpell(GetContextCreature(), 206863, true);
            });
            break;
        }
    }

    void UpdateAI(uint32 diff) override
    {

    }

    void Initialize()
    {
        isHelp = false;
        isComplete = false;
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (!who || !who->IsInWorld() || !me->IsWithinDist(who, 15.0f, false))
            return;

        Player* player = who->GetCharmerOrOwnerPlayerOrPlayerItself();
        if (!player)
            return;
        if (player->HasQuest(QUEST_IN_DEEP_SLUMBER))
        {

            player->KilledMonsterCredit(me->GetEntry());

        }
    }
private:
    bool isComplete;
    bool isHelp;
};

///248098
class go_g_hanir : public GameObjectScript
{
public:
    go_g_hanir() : GameObjectScript("go_g_hanir") { }

    void OnLootStateChanged(GameObject* go, uint32 state, Unit* unit)
    {
        if (state == GO_ACTIVATED && unit)
        {
            if (Creature* lyessa = go->FindNearestCreature(104573, 15.0f, true))
            {
                lyessa->AI()->DoAction(1);
            }
            if (Player* player = unit->ToPlayer())
            {
                player->KilledMonsterCredit(113098);
                go->GetScheduler().Schedule(Milliseconds(5000), [player](TaskContext context)
                {
                    player->TeleportTo(1220, Position(4299.72f, 7422.46f, -17.13f, 2.535614f));
                });
            }

        }

    }
};

struct npc_lyessa_bloomwatcher_104577 : public ScriptedAI
{
    npc_lyessa_bloomwatcher_104577(Creature* creature) : ScriptedAI(creature) { }

    void sQuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_CLEANSING_THE_MOTHER_TREE)
        {
            Talk(0);
            me->GetScheduler().Schedule(Milliseconds(5000), [this, player](TaskContext context)
            {
                me->Say(107059, player);
            });
        }
    }
};

struct npc_delandros_shimmermoon_107392 : public ScriptedAI
{
    npc_delandros_shimmermoon_107392(Creature* creature) : ScriptedAI(creature) { Initialize(); }

    void Reset() override
    {
        Initialize();
    }

    void Initialize()
    {
        issay = false;
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (!who || !who->IsInWorld() || !me->IsWithinDist(who, 15.0f, false))
            return;

        Player* player = who->GetCharmerOrOwnerPlayerOrPlayerItself();
        if (!player)
            return;
        if (!issay && player->HasQuest(QUEST_THE_SHRINE_OF_ASHAMANE))
        {
            issay = true;
            if (Creature* verstok = me->FindNearestCreature(NPC_VERSTOK_DARKBOUGH_107520, 15.0f, true))
            {
                verstok->Say(111906, me);

                me->GetScheduler().Schedule(Milliseconds(2000), [verstok](TaskContext context)
                {
                    GetContextCreature()->Say(111926, verstok);
                });

                verstok->GetScheduler().Schedule(Milliseconds(4000), [this](TaskContext context)
                {
                    GetContextCreature()->Say(112269, me);
                });
            }

            me->GetScheduler().Schedule(Milliseconds(30000), [this](TaskContext context)
            {
                issay = false;
            });
        }

        if (!issay && player->GetQuestStatus(QUEST_THE_SHRINE_IN_PERIL) == QUEST_STATUS_COMPLETE)
        {
            issay = true;
            Talk(1);
            me->GetScheduler().Schedule(Milliseconds(3000), [this](TaskContext context)
            {
                Talk(2);
            });
            me->GetScheduler().Schedule(Milliseconds(30000), [this](TaskContext context)
            {
                issay = false;
            });
        }
    }

    void sQuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_THE_SHRINE_IN_PERIL)
        {
            player->GetSceneMgr().PlayScene(1285);
            me->GetScheduler().Schedule(Milliseconds(4000), [this](TaskContext context)
            {
                Talk(0);
            });
        }

    }
private:
    bool issay;
};

struct npc_eredar_soul_lasher_107535 : public ScriptedAI
{
    npc_eredar_soul_lasher_107535(Creature* creature) : ScriptedAI(creature) { Initialize(); }

    enum Spells
    {
        SPELL_TORMENT_1 = 213527,
        SPELL_TORMENT_2 = 213528,
        SPELL_LASH_OF_PAIN = 176185,
        SPELL_CURSE_OF_TORMENT = 180395
    };

    void Reset() override
    {
        Initialize();
    }

    void Initialize()
    {
        if (Creature* druid = me->FindNearestCreature(107389, 15.0f, true))
            me->CastSpell(druid, SPELL_TORMENT_1, true);
    }

    void EnterCombat(Unit*) override
    {
        me->GetScheduler().Schedule(Milliseconds(2500), [this](TaskContext context)
        {
            me->CastSpell(me->GetVictim(), SPELL_LASH_OF_PAIN, true);

            context.Repeat(Milliseconds(3000));
        });

        me->GetScheduler().Schedule(Seconds(5), [this](TaskContext context)
        {
            me->CastSpell(me->GetVictim(), SPELL_CURSE_OF_TORMENT, true);
            context.Repeat(Seconds(15));
        });
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (Creature* druid = me->FindNearestCreature(107389, 15.0f, true))
        {
            druid->RemoveAura(SPELL_TORMENT_2);
            druid->AI()->Talk(urand(0, 2));
            druid->GetMotionMaster()->MoveAwayAndDespawn(10.0f, 2000);
        }
    }
};

struct npc_investigate_shrine_kill_credit_107607 : public ScriptedAI
{
    npc_investigate_shrine_kill_credit_107607(Creature* creature) : ScriptedAI(creature) {  }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Player* player = who->ToPlayer())
            if (player->GetDistance(me) < 5.0f)
                if (!player->GetQuestObjectiveData(QUEST_THE_SHRINE_IN_PERIL, 0))
                {
                    player->KilledMonsterCredit(me->GetEntry());
                    player->GetSceneMgr().PlayScene(1286);
                }
    }
};

///scene 1286
class scene_druid_feral_investigate : public SceneScript
{
public:
    scene_druid_feral_investigate() : SceneScript("scene_druid_feral_investigate") { }

    void OnSceneEnd(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/)
    {
        TempSummon* algromon = player->SummonCreature(NPC_ALGROMON_107593, Position(3531.1899f, 5538.5698f, 323.411f, 3.1076f));
        algromon->RemoveAura(213626);

        Position pos;
        GetRandPosFromCenterInDist(algromon, 5.0f, pos);

        TempSummon* ashendruid1 = algromon->SummonCreature(107390, Position(3486.39917f, 5544.291f, 323.558136f, 6.208363f));
        ashendruid1->AI()->Talk(0);
        ashendruid1->GetMotionMaster()->MovePoint(1, pos, true);
        ashendruid1->Attack(algromon, true);
        GetRandPosFromCenterInDist(algromon, 10.f, pos);
        TempSummon* ashendruid2 = algromon->SummonCreature(107390, Position(3486.743652f, 5537.70459f, 323.189392f, 6.208362f));
        ashendruid2->GetMotionMaster()->MovePoint(1, pos, true);
        ashendruid2->Attack(algromon, true);

        algromon->Attack(ashendruid1, true);
    }
};

enum
{
    SPELL_CLEAVE = 207942,
    SPELL_FEL_FIRESTORM = 197818,
    SPELL_TREMBLING_STOMP = 197816,
    PHASE_AFTER_KILL_ALGROMON = 6511,
};

struct npc_algromon_107593 : public BossAI
{
    npc_algromon_107593(Creature* creature) : BossAI(creature, 0) { }

    void JustDied(Unit* killer) override
    {
        BossAI::JustDied(killer);

        std::list<Player*> players;
        me->GetPlayerListInGrid(players, 50.0f);

        for (Player* player : players)
            PhasingHandler::AddPhase(player, PHASE_AFTER_KILL_ALGROMON, true);
    }

    void ScheduleTasks() override
    {
        events.ScheduleEvent(SPELL_CLEAVE, 10s);
        events.ScheduleEvent(SPELL_FEL_FIRESTORM, 10s, 20s);
        events.ScheduleEvent(SPELL_TREMBLING_STOMP, 12s);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case SPELL_CLEAVE:
        {
            DoCast(SPELL_CLEAVE);
            events.Repeat(10s);
            break;
        }
        case SPELL_FEL_FIRESTORM:
        {
            DoCast(SPELL_FEL_FIRESTORM);
            events.Repeat(10s, 20s);
            break;
        }
        case SPELL_TREMBLING_STOMP:
        {
            DoCast(SPELL_TREMBLING_STOMP);
            events.Repeat(12s);
            break;
        }
        default:
            break;
        }
    }
};

struct npc_ebonfang_107729 : public ScriptedAI
{
    npc_ebonfang_107729(Creature* creature) : ScriptedAI(creature) { }

    void OnSpellClick(Unit* clicker, bool& /*result*/)
    {
        if (Player* player = clicker->ToPlayer())
            if (player->HasQuest(42430))
            {
                player->KilledMonsterCredit(me->GetEntry());
                player->TeleportTo(1612, Position(1940.97f, 5558.38f, 60.66f, 4.746947f));
            }
    }
};

struct npc_naralex_103778 : public ScriptedAI
{
    npc_naralex_103778(Creature* creature) : ScriptedAI(creature) {}

    void sQuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_THE_SCYTHE_OF_ELUNE)
        {
            me->Say(106125, player);
            me->GetScheduler().Schedule(Milliseconds(2000), [player](TaskContext context)
            {
                GetContextCreature()->Say(106128, player);
            });
        }
    }
};

enum PHASES
{
    QUEST_THE_SCYTHE_OF_ELUNE_PHASE = 5677,
    QUEST_ITS_RIGHTFUL_PLACE_PHASE_1 = 5678,
    QUEST_ITS_RIGHTFUL_PLACE_PHASE_2 = 5679,

    ACTION_QUEST_ITS_RIGHTFUL_PLACE = 1,
};
struct npc_valorn_stillbough_101656 : public ScriptedAI
{
    npc_valorn_stillbough_101656(Creature* creature) : ScriptedAI(creature) { Initialize(); }

    void DoAction(int32 param)
    {
        switch (param)
        {
        case ACTION_QUEST_ITS_RIGHTFUL_PLACE:
            if (Player* player = ObjectAccessor::GetPlayer(*me, m_playerGUID))
            {
                if (!issay && !player->GetQuestObjectiveData(QUEST_ITS_RIGHTFUL_PLACE, 0))
                {
                    issay = true;
                    PhasingHandler::RemovePhase(player, QUEST_THE_SCYTHE_OF_ELUNE_PHASE);
                    PhasingHandler::AddPhase(player, QUEST_ITS_RIGHTFUL_PLACE_PHASE_1);
                    //summon 101657
                    TempSummon* ariden = player->SummonCreature(107390, Position(-10330.9f, -488.30899f, 50.445f, 2.81726f));
                    PhasingHandler::InheritPhaseShift(ariden, player);
                    //cast something
                    ariden->Yell(104055);

                    player->KilledMonsterCredit(101702);
                    if (Creature* belysra = me->FindNearestCreature(101651, 15.0f, true))
                    {
                        belysra->Yell(104056);

                        belysra->GetScheduler().Schedule(Milliseconds(2000), [belysra](TaskContext context)
                        {
                            belysra->Say(104059);
                        });
                    }

                    me->GetScheduler().Schedule(Milliseconds(3000), [player, ariden](TaskContext context)
                    {
                        PhasingHandler::AddPhase(player, QUEST_ITS_RIGHTFUL_PLACE_PHASE_2);
                        PhasingHandler::RemovePhase(player, QUEST_ITS_RIGHTFUL_PLACE_PHASE_1);
                        PhasingHandler::InheritPhaseShift(ariden, player);
                    });

                    ariden->GetMotionMaster()->MoveAwayAndDespawn(50.0f, 5000);
                    me->GetScheduler().Schedule(Milliseconds(4000), [this](TaskContext context)
                    {
                        issay = false;
                    });
                }
            }
            break;
        }
    }

    void sQuestAccept(Player* player, Quest const* quest) override
    {
        m_playerGUID = player->GetGUID();
        if (quest->GetQuestId() == QUEST_ITS_RIGHTFUL_PLACE)
            DoAction(ACTION_QUEST_ITS_RIGHTFUL_PLACE);
    }

    void Initialize()
    {
        issay = false;
        m_playerGUID = ObjectGuid::Empty;
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (!who || !who->IsInWorld() || !me->IsWithinDist(who, 15.0f, false))
            return;

        Player* player = who->GetCharmerOrOwnerPlayerOrPlayerItself();
        if (!player)
            return;
        m_playerGUID = player->GetGUID();

        if (player->HasQuest(QUEST_THE_SCYTHE_OF_ELUNE) && player->GetQuestStatus(QUEST_THE_SCYTHE_OF_ELUNE) == QUEST_STATUS_INCOMPLETE && !player->GetQuestObjectiveData(QUEST_THE_SCYTHE_OF_ELUNE, 1))
        {
            me->Say(104053);
            player->KilledMonsterCredit(101701);
            me->GetScheduler().Schedule(Milliseconds(2000), [player](TaskContext context)
            {
                GetContextCreature()->Say(104054, player);
            });
        }
        if (player->HasQuest(QUEST_ITS_RIGHTFUL_PLACE) && player->GetQuestStatus(QUEST_ITS_RIGHTFUL_PLACE) == QUEST_STATUS_INCOMPLETE && !player->GetQuestObjectiveData(QUEST_ITS_RIGHTFUL_PLACE, 0))
            DoAction(ACTION_QUEST_ITS_RIGHTFUL_PLACE);
    }
private:
    bool issay;
    ObjectGuid   m_playerGUID;
};

///
struct npc_revil_kost_100323 : public ScriptedAI
{
    npc_revil_kost_100323(Creature* creature) : ScriptedAI(creature) { Initialize(); }

    void sQuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_FOLLOWING_THE_CURSE || quest->GetQuestId() == 40588 || quest->GetQuestId() == 40931)
        {
            Creature* revil = player->SummonCreature(100578, me->GetPosition());
            PhasingHandler::InheritPhaseShift(revil, player);
            revil->SetOwnerGUID(player->GetGUID());
            revil->AI()->DoAction(1);
            //revil->GetMotionMaster()->MovePoint(1, revil->GetPositionWithDistInFront(25.0f), true);
            //WP START
        }
    }
    void Initialize()
    {
        m_playerGUID = ObjectGuid::Empty;
        IsLock = false;
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (!who || !who->IsInWorld() || !me->IsWithinDist(who, 15.0f, false))
            return;

        Player* player = who->GetCharmerOrOwnerPlayerOrPlayerItself();
        if (!player)
            return;
        m_playerGUID = player->GetGUID();
        if (!IsLock && player->HasQuest(QUEST_A_FOE_OF_THE_DARK))// druid 40834
        {
            IsLock = true;
          /*  _sceneHelper.Clear();
            _sceneHelper.SetDefaultActorGuid(me->GetGUID());
            _sceneHelper.SetDefaultPlayerGuid(player->GetGUID());
            _sceneHelper.AddSceneActionSay(104555);
            _sceneHelper.AddSceneActionSay(104556, 5000);
            _sceneHelper.AddSceneActionSay(104557, 5000);
            _sceneHelper.AddSceneActionKillCreditMonster(102291, 1, 500);
            _sceneHelper.Activate();*/
            SetUnlock(30000);
        }
        if (!IsLock && player->HasQuest(40495))//QUEST_A_FOE_OF_THE_DARK SS 40588
        {
            IsLock = true;
          /*  _sceneHelper.Clear();
            _sceneHelper.SetDefaultActorGuid(me->GetGUID());
            _sceneHelper.SetDefaultPlayerGuid(player->GetGUID());
            _sceneHelper.AddSceneActionSay(104650);
            _sceneHelper.AddSceneActionSay(104651, 5000);
            _sceneHelper.AddSceneActionSay(102051, 5000);
            _sceneHelper.AddSceneActionKillCreditMonster(102580, 1, 500);
            _sceneHelper.AddSceneActionKillCreditMonster(100821, 1, 500);
            _sceneHelper.AddSceneActionKillCreditMonster(100368, 1, 500);
            _sceneHelper.Activate();*/
            SetUnlock(30000);
        }
        if (!IsLock && player->HasQuest(40930))//QUEST_A_FOE_OF_THE_DARK DK 40931
        {
            IsLock = true;
          /*  _sceneHelper.Clear();
            _sceneHelper.SetDefaultActorGuid(me->GetGUID());
            _sceneHelper.SetDefaultPlayerGuid(player->GetGUID());
            _sceneHelper.AddSceneActionSay(104650);
            _sceneHelper.AddSceneActionSay(104651, 5000);
            _sceneHelper.AddSceneActionSay(102051, 5000);
            _sceneHelper.AddSceneActionKillCreditMonster(102580, 1, 500);
            _sceneHelper.AddSceneActionKillCreditMonster(100821, 1, 500);
            _sceneHelper.AddSceneActionKillCreditMonster(100368, 1, 500);
            _sceneHelper.Activate();*/
            SetUnlock(30000);
        }
    }
private:
    ObjectGuid   m_playerGUID;
};

struct npc_revil_kost_100578 : public ScriptedAI
{
    npc_revil_kost_100578(Creature* creature) : ScriptedAI(creature) { }

    void DoAction(int32 param)
    {

      //  _sceneHelper.Clear();
     //   _sceneHelper.SetDefaultActorGuid(me->GetGUID());
        if (Player* player = me->GetCharmerOrOwnerPlayerOrPlayerItself())
         //   _sceneHelper.SetDefaultPlayerGuid(player->GetGUID());
        printf("111\n");

     //   _sceneHelper.AddSceneActionMovePos(me->GetPositionWithDistInFront(25.0f), 5000);
    /*    _sceneHelper.AddSceneActionTalk(0, 5000);
        _sceneHelper.AddSceneActionMovePos(Position(-10311.97f, -1332.03f, 52.737f, 4.6612f), 5000);
        _sceneHelper.AddSceneActionTalk(1, 5000);
        _sceneHelper.AddSceneActionMovePos(Position(-10328.143f, -1387.99f, 67.445f, 4.292f), 5000);
        _sceneHelper.AddSceneActionTalk(2, 5000);
        _sceneHelper.AddSceneActionMovePos(Position(-10361.626f, -1440.236f, 82.542f, 4.064f), 5000);
        _sceneHelper.AddSceneActionTalk(3, 5000);
        _sceneHelper.AddSceneActionMovePos(Position(-10406.25f, -1440.057f, 83.8496f, 2.945f), 5000);
        _sceneHelper.AddSceneActionMovePos(Position(-10439.009f, -1430.06f, 71.47f, 3.475f), 5000);
        _sceneHelper.AddSceneActionMovePos(Position(-10463.04f, -1441.829f, 67.46f, 3.67f), 5000);
        _sceneHelper.AddSceneActionTalk(4, 5000);
        _sceneHelper.AddSceneActionMovePos(Position(-10449.08f, -1476.25f, 72.86f, 4.767f), 5000);
        _sceneHelper.AddSceneActionTalk(5, 5000);
        _sceneHelper.AddSceneActionMovePos(Position(-10458.322f, -1646.73f, 75.931f, 4.526f), 10000);
        _sceneHelper.AddSceneActionMovePos(Position(-10459.341f, -1737.5f, 87.227f, 4.888f), 10000);
        _sceneHelper.AddSceneActionMovePos(Position(-10429.8f, -1796.99f, 97.565f, 4.61f), 10000);
        _sceneHelper.AddSceneActionMovePos(Position(-10444.88f, -1870.788f, 104.86f, 4.787f), 10000);
        _sceneHelper.AddSceneActionTalk(6, 5000);
        _sceneHelper.AddSceneActionMovePos(Position(-10437.356f, -1936.838f, 104.357f, 4.834f), 5000);
        _sceneHelper.AddSceneActionTalk(7, 5000);
        _sceneHelper.AddSceneActionMovePos(Position(-10438.63f, -1977.693f, 101.462f, 4.779f), 10000);
        _sceneHelper.AddSceneActionMovePos(Position(-10430.898f, -2034.155f, 94.873f, 4.57f), 10000);
        _sceneHelper.AddSceneActionMovePos(Position(-10504.867f, -2047.418f, 92.593f, 4.068f), 10000);
        _sceneHelper.AddSceneActionTalk(8, 5000);
        _sceneHelper.AddSceneActionMovePos(Position(-10544.92f, -2100.605f, 91.87f, 5.489f), 10000);
        _sceneHelper.AddSceneActionTalk(9, 5000);

        _sceneHelper.AddSceneActionKillCreditMonster(100655, 1, 500);
        _sceneHelper.AddSceneActionKillCreditMonster(100716, 1, 500);
        _sceneHelper.AddSceneActionDespawn(1000);
        _sceneHelper.Activate();*/
    }
};

///QUEST_DISTURBING_THE_PAST
struct npc_revil_kost_100729 : public ScriptedAI
{
    npc_revil_kost_100729(Creature* creature) : ScriptedAI(creature) { Initialize(); }

    void sQuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_DISTURBING_THE_PAST)
        {
            //PhasingHandler::AddPhase(player, PHASE_2
            player->CastSpell(player, 198271, true);

            player->SendMoveKnockBack(player, 2.1f, 2.1f, 0.0f, 0.0f);
            player->CastSpell(player, 200233, true);///conversation 1038

            player->KilledMonsterCredit(245789);
            player->KilledMonsterCredit(100732);

            me->GetScheduler().Schedule(Milliseconds(2000), [player](TaskContext context)
            {
                GetContextCreature()->Say(103911, player);
            });
        }
    }

    void sQuestReward(Player* player, Quest const* quest, uint32 /*opt*/)  override
    {
        if (quest->GetQuestId() == QUEST_DISTURBING_THE_PAST)
        {

        }
    }
    void Initialize()
    {
        m_playerGUID = ObjectGuid::Empty;
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (!who || !who->IsInWorld() || !me->IsWithinDist(who, 15.0f, false))
            return;

        Player* player = who->GetCharmerOrOwnerPlayerOrPlayerItself();
        if (!player)
            return;
    }
private:
    ObjectGuid   m_playerGUID;
};
///go 245789 ->198271
///157902 summon ss

///QUEST_THE_DEADWIND_HUNT 102162, 102163, 102164, 102165
struct npc_credit_worgen_chased : public ScriptedAI
{
    npc_credit_worgen_chased(Creature* creature) : ScriptedAI(creature) {}

    void MoveInLineOfSight(Unit* who) override
    {
        if (Player* player = who->ToPlayer())
        {
            if (me->IsWithinDist(player, 15.0f, false))
            {
                player->KilledMonsterCredit(me->GetEntry());

                if (player->HasQuest(40611) && player->GetZoneId() == 41)
                    player->CastSpell(player, 198333, true);
                else
                    player->RemoveAurasDueToSpell(198333);
            }
        }
    }
};
///QUEST_THE_DARK_RIDERS
struct npc_revil_kost_100812 : public ScriptedAI
{
    npc_revil_kost_100812(Creature* creature) : ScriptedAI(creature) { Initialize(); }

    void sQuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_THE_DARK_RIDERS || quest->GetQuestId() == 40623 || quest->GetQuestId() == 40934)
        {
            me->Say(106323);
            ///https://cn.wowhead.com/spell=205426/warm-up-scythe-scenario
            ///complete quest
            ///player->CastSpell(player, 205426, true);
            //tele to scenario
            //ScenarioID: 1014
            //.go -11018.37f -2002.739f 24.99422 1533
            player->TeleportTo(1533, Position(-11018.37f, -2002.739f, 24.99422f, 1.369567f));
            ///https://cn.wowhead.com/spell=222599/revil-spawned
            ///https://cn.wowhead.com/spell=199631/ping-revil
            //PhasingHandler::AddPhase(player, 169);
        }
    }
    void Initialize()
    {
        m_playerGUID = ObjectGuid::Empty;
        IsLock = false;
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
        m_playerGUID = player->GetGUID();
        if (!IsLock && player->HasQuest(QUEST_THE_DEADWIND_HUNT) && player->GetQuestStatus(QUEST_THE_DEADWIND_HUNT) == QUEST_STATUS_COMPLETE && player->GetQuestStatus(QUEST_THE_DEADWIND_HUNT) != QUEST_STATUS_REWARDED)
        {
            IsLock = true;
            me->Say(104436, player);
            SetUnlock(15000);
        }
    }
private:
    ObjectGuid   m_playerGUID;
};

struct npc_rensar_greathoof_97923 : public ScriptedAI
{
    npc_rensar_greathoof_97923(Creature* creature) : ScriptedAI(creature) { }

    void MoveInLineOfSight(Unit* who) override
    {
        if (who->ToPlayer() && me->IsWithinDist(who, 25.0f, false))
            if (who->ToPlayer()->HasQuest(QUEST_A_HEROS_WEAPON))
            {
                who->ToPlayer()->KilledMonsterCredit(113627);
                who->ToPlayer()->KilledMonsterCredit(110366);
            }
    }
};

struct npc_yaris_darkclaw_106442 : public ScriptedAI
{
    npc_yaris_darkclaw_106442(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
   //     me->SetShipmentContainerID(141);
    }

    void sGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId)
    {
        //CloseGossipMenuFor(player);
      //  player->SendShipmentCrafterUI(me->GetGUID(), me->GetShipmentContainerID());
    }
};

struct npc_sister_lilith_108393 : public ScriptedAI
{
    npc_sister_lilith_108393(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
     //   me->SetShipmentContainerID(140);
    }

    void sGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId)
    {
        //CloseGossipMenuFor(player);
     //   player->SendShipmentCrafterUI(me->GetGUID(), me->GetShipmentContainerID());
    }
};

//250886,250872
class go_dru_training_troops : public GameObjectScript
{
public:
    go_dru_training_troops() : GameObjectScript("go_dru_training_troops") { }

    bool OnGossipHello(Player* player, GameObject* go)
    {
        if (Garrison* garrison = player->GetGarrison(GARRISON_TYPE_CLASS_HALL))
        {
            switch (go->GetEntry())
            {
            case 250886:
             //   garrison->RewardWorkOrder(141);
                break;
            case 250872:
            //    garrison->RewardWorkOrder(140);
                break;
            default:
                break;
            }
            std::list<GameObject*> golist = player->FindNearestGameObjects(go->GetEntry(), 15.f);
            for (auto gos : golist)
            {
                gos->DestroyForNearbyPlayers();
                gos->AddObjectToRemoveList();
            }
        }

        return false;
    }
};

class go_fur_blanket_245788 : public GameObjectScript
{
public:
    go_fur_blanket_245788() : GameObjectScript("go_fur_blanket_245788") { }

    bool OnReportUse(Player* player, GameObject* /*go*/) 
    {
        player->KillCreditGO(245789);
        player->KilledMonsterCredit(100736);
        player->KilledMonsterCredit(100732);
        if (player->HasQuest(40604) || player->HasQuest(40835) || player->HasQuest(40932))
            player->CastSpell(player, 198271, true);
        return false;
    }
};

enum Lunarwing
{
    QUEST_DEFENSE_OF_AVIANA = 46318,
};

//106299
struct npc_thisalee_crow_106299 : public ScriptedAI
{
    npc_thisalee_crow_106299(Creature* creature) : ScriptedAI(creature) { }

    void sQuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->ID == QUEST_DEFENSE_OF_AVIANA)
            player->ForceCompleteQuest(QUEST_DEFENSE_OF_AVIANA);

        if (quest->ID == QUEST_YOU_CANT_TAKE_THE_SKY_FROM_ME)
        {
            player->ForceCompleteQuest(QUEST_DEFENSE_OF_AVIANA);
            player->AddItem(146798, 1);
            player->NearTeleportTo(4250.738f, 7523.942f, 78.70f, 2.23f, false);
            player->GetScheduler().Schedule(1s, [this, player] (TaskContext context)
            {
                player->GetSceneMgr().PlaySceneByPackageId(1821);
            }); 
        }
    }
};

void AddSC_class_hall_druid()
{
    new npc_class_hall_druid_gatewarden("npc_class_hall_druid_gatewarden_dreamgrove", 204983);
    new npc_class_hall_druid_gatewarden("npc_class_hall_druid_gatewarden_hyjal", 0);
    new npc_class_hall_druid_gatewarden("npc_class_hall_druid_gatewarden_feralas", 0);
    new npc_class_hall_druid_gatewarden("npc_class_hall_druid_gatewarden_moonglade", 200082);
    new npc_class_hall_druid_gatewarden("npc_class_hall_druid_gatewarden_duskwood", 205013);
    new npc_class_hall_druid_gatewarden("npc_class_hall_druid_gatewarden_hinterlands", 210066);
    new npc_class_hall_druid_gatewarden("npc_class_hall_druid_gatewarden_grizzlyhills", 200117);
    RegisterCreatureAI(npc_archdruid_hamuul_runetotem_101061);
    RegisterCreatureAI(npc_archdruid_hamuul_runetotem_101064);
    RegisterCreatureAI(npc_zentabra_103135);
    RegisterCreatureAI(npc_zentabra_103136);
    RegisterCreatureAI(npc_naralex_103133);
    RegisterCreatureAI(npc_malfurion_stormrage_103875);
    RegisterCreatureAI(npc_generic_bunny_quest_to_the_dreamgrove_59115);
    new quest_to_the_dreamgrove();
    RegisterCreatureAI(npc_keeper_remulos_103489);
    RegisterCreatureAI(npc_keeper_remulos_103488);
    RegisterCreatureAI(npc_nightmare_blight_103246);
    RegisterCreatureAI(npc_skycaller_faeb_122095);
    RegisterCreatureAI(npc_grove_tender_98029);
    RegisterCreatureAI(npc_laughing_sister_98027);
    RegisterCreatureAI(npc_rensar_greathoof_101195);
    new druid_weapons_of_legend_player_choice();
    RegisterCreatureAI(npc_keeper_remulos_103832);
    RegisterCreatureAI(npc_lea_stonepaw_101259);
    RegisterCreatureAI(npc_lea_stonepaw_104535);
    RegisterCreatureAI(npc_ursol_104385);
    RegisterCreatureAI(npc_ancestral_champion_104714);
    RegisterCreatureAI(npc_ancestral_warrior_104936);
    RegisterCreatureAI(npc_ancestral_shaman_104937);
    new playerscript_flask_of_moonwell_water();
    RegisterCreatureAI(npc_generic_bunny_103560);
    RegisterCreatureAI(npc_mylune_113525);
    RegisterCreatureAI(npc_leafbeard_the_storied_97989);
    RegisterCreatureAI(npc_naralex_104349);
    new QuestInDeepSlumberUseItem();
    RegisterCreatureAI(npc_bashana_runetotem_104398);
    RegisterCreatureAI(npc_lyessa_bloomwatcher_104573);
    new go_g_hanir();
    RegisterCreatureAI(npc_lyessa_bloomwatcher_104577);
    RegisterCreatureAI(npc_delandros_shimmermoon_107392);
    RegisterCreatureAI(npc_eredar_soul_lasher_107535);
    RegisterCreatureAI(npc_investigate_shrine_kill_credit_107607);
    new scene_druid_feral_investigate();
    RegisterCreatureAI(npc_algromon_107593);
    RegisterCreatureAI(npc_ebonfang_107729);
    RegisterCreatureAI(npc_naralex_103778);
    RegisterCreatureAI(npc_valorn_stillbough_101656);
    RegisterCreatureAI(npc_revil_kost_100323);
    RegisterCreatureAI(npc_revil_kost_100578);
    RegisterCreatureAI(npc_revil_kost_100729);
    RegisterCreatureAI(npc_credit_worgen_chased);
    RegisterCreatureAI(npc_revil_kost_100812);
    RegisterCreatureAI(npc_rensar_greathoof_97923);
    RegisterCreatureAI(npc_yaris_darkclaw_106442);
    RegisterCreatureAI(npc_sister_lilith_108393);
    new go_dru_training_troops();
    new go_fur_blanket_245788();
    RegisterCreatureAI(npc_thisalee_crow_106299);
}
