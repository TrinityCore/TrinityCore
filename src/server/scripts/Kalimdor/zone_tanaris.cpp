///*
// * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
// *
// * This program is free software; you can redistribute it and/or modify it
// * under the terms of the GNU General Public License as published by the
// * Free Software Foundation; either version 2 of the License, or (at your
// * option) any later version.
// *
// * This program is distributed in the hope that it will be useful, but WITHOUT
// * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
// * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
// * more details.
// *
// * You should have received a copy of the GNU General Public License along
// * with this program. If not, see <http://www.gnu.org/licenses/>.
// */
//
///* ScriptData
//SDName: Tanaris
//SD%Complete: 80
//SDComment: Quest support:
//SDCategory: Tanaris
//EndScriptData */
//
///* ContentData
//EndContentData */
//
//#include "ScriptMgr.h"
//#include "MotionMaster.h"
//#include "ObjectAccessor.h"
//#include "Player.h"
//#include "ScriptedFollowerAI.h"
//#include "ScriptedGossip.h"
//
///*
// * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
// *
// * This program is free software; you can redistribute it and/or modify it
// * under the terms of the GNU General Public License as published by the
// * Free Software Foundation; either version 2 of the License, or (at your
// * option) any later version.
// *
// * This program is distributed in the hope that it will be useful, but WITHOUT
// * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
// * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
// * more details.
// *
// * You should have received a copy of the GNU General Public License along
// * with this program. If not, see <http://www.gnu.org/licenses/>.
// */
//
//#include "ScriptMgr.h"
//#include "MotionMaster.h"
//#include "ObjectAccessor.h"
//#include "Player.h"
//#include "ScriptedEscortAI.h"
//#include "ScriptedFollowerAI.h"
//#include "ScriptedGossip.h"
//
//// 9453
//class npc_aquementas_9453 : public CreatureScript
//{
//public:
//    npc_aquementas_9453() : CreatureScript("npc_aquementas_9453") { }
//
//    enum Aquementas
//    {
//        AGGRO_YELL_AQUE = 0,
//
//        SPELL_AQUA_JET = 13586,
//        SPELL_FROST_SHOCK = 15089
//    };
//
//    struct npc_aquementas_9453AI : public ScriptedAI
//    {
//        npc_aquementas_9453AI(Creature* creature) : ScriptedAI(creature) { }
//
//        uint32 SendItemTimer;
//        uint32 SwitchFactionTimer;
//        bool isFriendly;
//
//        uint32 FrostShockTimer;
//        uint32 AquaJetTimer;
//
//        void Reset() override
//        {
//            SendItemTimer = 0;
//            SwitchFactionTimer = 10000;
//            me->setFaction(35);
//            isFriendly = true;
//
//            AquaJetTimer = 5000;
//            FrostShockTimer = 1000;
//        }
//
//        void SendItem(Unit* receiver)
//        {
//            Player* player = receiver->ToPlayer();
//
//            if (player && player->HasItemCount(11169, 1, false) &&
//                player->HasItemCount(11172, 11, false) &&
//                player->HasItemCount(11173, 1, false) &&
//                !player->HasItemCount(11522, 1, true))
//            {
//                ItemPosCountVec dest;
//                uint8 msg = player->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, 11522, 1, NULL);
//                if (msg == EQUIP_ERR_OK)
//                    player->StoreNewItem(dest, 11522, 1, true);
//            }
//        }
//
//        void EnterCombat(Unit* who)
//        {
//            Talk(AGGRO_YELL_AQUE, who);
//        }
//
//        void UpdateAI(uint32 diff) override
//        {
//            if (isFriendly)
//            {
//                if (SwitchFactionTimer <= diff)
//                {
//                    me->setFaction(91);
//                    isFriendly = false;
//                } else SwitchFactionTimer -= diff;
//            }
//
//            if (!UpdateVictim())
//                return;
//
//            if (!isFriendly)
//            {
//                if (SendItemTimer <= diff)
//                {
//                    if (me->GetVictim() && me->EnsureVictim()->GetTypeId() == TYPEID_PLAYER)
//                        SendItem(me->GetVictim());
//                    SendItemTimer = 5000;
//                } else SendItemTimer -= diff;
//            }
//
//            if (FrostShockTimer <= diff)
//            {
//                DoCastVictim(SPELL_FROST_SHOCK);
//                FrostShockTimer = 15000;
//            } else FrostShockTimer -= diff;
//
//            if (AquaJetTimer <= diff)
//            {
//                DoCast(me, SPELL_AQUA_JET);
//                AquaJetTimer = 15000;
//            } else AquaJetTimer -= diff;
//
//            DoMeleeAttackIfReady();
//        }
//    };
//
//    CreatureAI* GetAI(Creature* creature) const override
//    {
//        return new npc_aquementas_9453AI(creature);
//    }
//};
//
//// 19950
//class npc_custodian_of_time_19950 : public CreatureScript
//{
//public:
//    npc_custodian_of_time_19950() : CreatureScript("npc_custodian_of_time_19950") { }
//
//    enum CustodianOfTime
//    {
//        WHISPER_CUSTODIAN_1 = 0,
//        WHISPER_CUSTODIAN_2 = 1,
//        WHISPER_CUSTODIAN_3 = 2,
//        WHISPER_CUSTODIAN_4 = 3,
//        WHISPER_CUSTODIAN_5 = 4,
//        WHISPER_CUSTODIAN_6 = 5,
//        WHISPER_CUSTODIAN_7 = 6,
//        WHISPER_CUSTODIAN_8 = 7,
//        WHISPER_CUSTODIAN_9 = 8,
//        WHISPER_CUSTODIAN_10 = 9,
//        WHISPER_CUSTODIAN_11 = 10,
//        WHISPER_CUSTODIAN_12 = 11,
//        WHISPER_CUSTODIAN_13 = 12,
//        WHISPER_CUSTODIAN_14 = 13
//    };
//
//    struct npc_custodian_of_time_19950AI : public npc_escortAI
//    {
//        npc_custodian_of_time_19950AI(Creature* creature) : npc_escortAI(creature) { }
//
//        void WaypointReached(uint32 waypointId)
//        {
//            if (Player* player = GetPlayerForEscort())
//            {
//                switch (waypointId)
//                {
//                    case 0:
//                        Talk(WHISPER_CUSTODIAN_1, player);
//                        break;
//                    case 1:
//                        Talk(WHISPER_CUSTODIAN_2, player);
//                        break;
//                    case 2:
//                        Talk(WHISPER_CUSTODIAN_3, player);
//                        break;
//                    case 3:
//                        Talk(WHISPER_CUSTODIAN_4, player);
//                        break;
//                    case 5:
//                        Talk(WHISPER_CUSTODIAN_5, player);
//                        break;
//                    case 6:
//                        Talk(WHISPER_CUSTODIAN_6, player);
//                        break;
//                    case 7:
//                        Talk(WHISPER_CUSTODIAN_7, player);
//                        break;
//                    case 8:
//                        Talk(WHISPER_CUSTODIAN_8, player);
//                        break;
//                    case 9:
//                        Talk(WHISPER_CUSTODIAN_9, player);
//                        break;
//                    case 10:
//                        Talk(WHISPER_CUSTODIAN_4, player);
//                        break;
//                    case 13:
//                        Talk(WHISPER_CUSTODIAN_10, player);
//                        break;
//                    case 14:
//                        Talk(WHISPER_CUSTODIAN_4, player);
//                        break;
//                    case 16:
//                        Talk(WHISPER_CUSTODIAN_11, player);
//                        break;
//                    case 17:
//                        Talk(WHISPER_CUSTODIAN_12, player);
//                        break;
//                    case 18:
//                        Talk(WHISPER_CUSTODIAN_4, player);
//                        break;
//                    case 22:
//                        Talk(WHISPER_CUSTODIAN_13, player);
//                        break;
//                    case 23:
//                        Talk(WHISPER_CUSTODIAN_4, player);
//                        break;
//                    case 24:
//                        Talk(WHISPER_CUSTODIAN_14, player);
//                        DoCast(player, 34883);
//                        // below here is temporary workaround, to be removed when spell works properly
//                        player->AreaExploredOrEventHappens(10277);
//                        break;
//                }
//            }
//        }
//
//        void MoveInLineOfSight(Unit* who)
//        {
//            if (HasEscortState(STATE_ESCORT_ESCORTING))
//                return;
//
//            if (Player* player = who->ToPlayer())
//            {
//                if (who->HasAura(34877) && player->GetQuestStatus(10277) == QUEST_STATUS_INCOMPLETE)
//                {
//                    float Radius = 10.0f;
//                    if (me->IsWithinDistInMap(who, Radius))
//                    {
//                        Start(false, false, who->GetGUID());
//                    }
//                }
//            }
//        }
//
//        void EnterCombat(Unit* /*who*/) override { }
//        void Reset() override { }
//
//        void UpdateAI(uint32 diff) override
//        {
//            npc_escortAI::UpdateAI(diff);
//        }
//    };
//
//    CreatureAI* GetAI(Creature* creature) const override
//    {
//        return new npc_custodian_of_time_19950AI(creature);
//    }
//};
//
//// 20142
//class npc_steward_of_time_20142 : public CreatureScript
//{
//public:
//    npc_steward_of_time_20142() : CreatureScript("npc_steward_of_time_20142") { }
//
//    bool OnQuestAccept(Player* player, Creature* /*creature*/, Quest const* quest)
//    {
//        if (quest->GetQuestId() == 10279)                      //Quest: To The Master's Lair
//            player->CastSpell(player, 34891, true);               //(Flight through Caverns)
//
//        return false;
//    }
//
//    bool OnGossipSelect(Player* player, Creature* /*creature*/, uint32 /*sender*/, uint32 action)
//    {
//        player->PlayerTalkClass->ClearMenus();
//        if (action == GOSSIP_ACTION_INFO_DEF + 1)
//            player->CastSpell(player, 34891, true);               //(Flight through Caverns)
//
//        return true;
//    }
//
//    bool OnGossipHello(Player* player, Creature* creature)
//    {
//        if (creature->IsQuestGiver())
//            player->PrepareQuestMenu(creature->GetGUID());
//
//        if (player->GetQuestStatus(10279) == QUEST_STATUS_INCOMPLETE || player->GetQuestRewardStatus(10279))
//        {
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Please take me to the master's lair.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
//            player->SEND_GOSSIP_MENU(9978, creature->GetGUID());
//        }
//        else
//            player->SEND_GOSSIP_MENU(9977, creature->GetGUID());
//
//        return true;
//    }
//};
//
//// 7784
//class npc_OOX17_7784 : public CreatureScript
//{
//public:
//    npc_OOX17_7784() : CreatureScript("npc_OOX17_7784") { }
//
//    enum Npc00X17
//    {
//        SAY_OOX_START = 0,
//        SAY_OOX_AGGRO = 1,
//        SAY_OOX_AMBUSH = 2,
//        SAY_OOX17_AMBUSH_REPLY = 0,
//        SAY_OOX_END = 3,
//
//        Q_OOX17 = 648,
//        SPAWN_FIRST = 7803,
//        SPAWN_SECOND_1 = 5617,
//        SPAWN_SECOND_2 = 7805
//    };
//
//    bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest)
//    {
//        if (quest->GetQuestId() == Q_OOX17)
//        {
//            creature->setFaction(113);
//            creature->SetFullHealth();
//            creature->SetUInt32Value(UNIT_FIELD_BYTES_1, 0);
//            creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
//            creature->AI()->Talk(SAY_OOX_START);
//
//            if (npc_escortAI* pEscortAI = CAST_AI(npc_OOX17_7784::npc_OOX17_7784AI, creature->AI()))
//                pEscortAI->Start(true, false, player->GetGUID());
//        }
//        return true;
//    }
//
//    struct npc_OOX17_7784AI : public npc_escortAI
//    {
//        npc_OOX17_7784AI(Creature* creature) : npc_escortAI(creature) { }
//
//        void WaypointReached(uint32 waypointId)
//        {
//            if (Player* player = GetPlayerForEscort())
//            {
//                switch (waypointId)
//                {
//                    case 23:
//                        me->SummonCreature(SPAWN_FIRST, -8350.96f, -4445.79f, 10.10f, 6.20f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
//                        me->SummonCreature(SPAWN_FIRST, -8355.96f, -4447.79f, 10.10f, 6.27f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
//                        me->SummonCreature(SPAWN_FIRST, -8353.96f, -4442.79f, 10.10f, 6.08f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
//                        Talk(SAY_OOX_AMBUSH);
//                        break;
//                    case 56:
//                        me->SummonCreature(SPAWN_SECOND_1, -7510.07f, -4795.50f, 9.35f, 6.06f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
//                        me->SummonCreature(SPAWN_SECOND_2, -7515.07f, -4797.50f, 9.35f, 6.22f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
//                        me->SummonCreature(SPAWN_SECOND_2, -7518.07f, -4792.50f, 9.35f, 6.22f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
//                        Talk(SAY_OOX_AMBUSH);
//                        if (Creature* scoff = me->FindNearestCreature(SPAWN_SECOND_2, 30))
//                            scoff->AI()->Talk(SAY_OOX17_AMBUSH_REPLY);
//                        break;
//                    case 86:
//                        Talk(SAY_OOX_END);
//                        player->GroupEventHappens(Q_OOX17, me);
//                        break;
//                }
//            }
//        }
//
//        void Reset() override { }
//
//        void EnterCombat(Unit* /*who*/) override
//        {
//            Talk(SAY_OOX_AGGRO);
//        }
//
//        void JustSummoned(Creature* summoned) override
//        {
//            summoned->AI()->AttackStart(me);
//        }
//    };
//    
//    CreatureAI* GetAI(Creature* creature) const override
//    {
//        return new npc_OOX17_7784AI(creature);
//    }
//};
//
//// 5955
//class npc_tooga_5955 : public CreatureScript
//{
//public:
//    npc_tooga_5955() : CreatureScript("npc_tooga_5955") { }
//
//    enum Tooga
//    {
//        SAY_TOOG_WORRIED = 0,
//        SAY_TOOG_POST_1 = 1,
//        SAY_TORT_POST_2 = 0,
//        SAY_TOOG_POST_3 = 2,
//        SAY_TORT_POST_4 = 1,
//        SAY_TOOG_POST_5 = 3,
//        SAY_TORT_POST_6 = 2,
//
//        QUEST_TOOGA = 1560,
//        NPC_TORTA = 6015,
//
//        POINT_ID_TO_WATER = 1,
//        FACTION_TOOG_ESCORTEE = 113
//    };
//
//    bool OnQuestAccept(Player* player, Creature* creature, const Quest* quest)
//    {
//        if (quest->GetQuestId() == QUEST_TOOGA)
//        {
//            if (npc_tooga_5955AI* pToogaAI = CAST_AI(npc_tooga_5955::npc_tooga_5955AI, creature->AI()))
//                pToogaAI->StartFollow(player, FACTION_TOOG_ESCORTEE, quest);
//        }
//
//        return true;
//    }
//    
//    struct npc_tooga_5955AI : public FollowerAI
//    {
//        npc_tooga_5955AI(Creature* creature) : FollowerAI(creature) { }
//
//        uint32 CheckSpeechTimer;
//        uint32 PostEventTimer;
//        uint32 PhasePostEvent;
//
//        uint64 TortaGUID;
//
//        void Reset() override
//        {
//            CheckSpeechTimer = 2500;
//            PostEventTimer = 1000;
//            PhasePostEvent = 0;
//
//            TortaGUID = 0;
//        }
//
//        void MoveInLineOfSight(Unit* who)
//        {
//            FollowerAI::MoveInLineOfSight(who);
//
//            if (!me->GetVictim() && !HasFollowState(STATE_FOLLOW_COMPLETE | STATE_FOLLOW_POSTEVENT) && who->GetEntry() == NPC_TORTA)
//            {
//                if (me->IsWithinDistInMap(who, INTERACTION_DISTANCE))
//                {
//                    Player* player = GetLeaderForFollower();
//                    if (player)
//                        player->GroupEventHappens(QUEST_TOOGA, me);
//
//                    TortaGUID = who->GetTortaGUID();
//                    SetFollowComplete(true);
//                }
//            }
//        }
//
//        void MovementInform(uint32 MotionType, uint32 PointId)
//        {
//            FollowerAI::MovementInform(MotionType, PointId);
//
//            if ((MotionType == POINT_MOTION_TYPE) && (PointId == POINT_ID_TO_WATER))
//                SetFollowComplete();
//        }
//
//        void UpdateFollowerAI(uint32 Diff)
//        {
//            if (!UpdateVictim())
//            {
//                //we are doing the post-event, or...
//                if (HasFollowState(STATE_FOLLOW_POSTEVENT))
//                {
//                    if (PostEventTimer <= Diff)
//                    {
//                        PostEventTimer = 5000;
//
//                        Creature* torta = ObjectAccessor::GetCreature(*me, TortaGUID);
//                        if (!torta || !torta->IsAlive())
//                        {
//                            //something happened, so just complete
//                            SetFollowComplete();
//                            return;
//                        }
//
//                        switch (PhasePostEvent)
//                        {
//                            case 1:
//                                Talk(SAY_TOOG_POST_1);
//                                break;
//                            case 2:
//                                torta->AI()->Talk(SAY_TORT_POST_2);
//                                break;
//                            case 3:
//                                Talk(SAY_TOOG_POST_3);
//                                break;
//                            case 4:
//                                torta->AI()->Talk(SAY_TORT_POST_4);
//                                break;
//                            case 5:
//                                Talk(SAY_TOOG_POST_5);
//                                break;
//                            case 6:
//                                torta->AI()->Talk(SAY_TORT_POST_6);
//                                me->GetMotionMaster()->MovePoint(POINT_ID_TO_WATER, -7032.664551f, -4906.199219f, -1.606446f);
//                                break;
//                        }
//
//                        ++PhasePostEvent;
//                    }
//                    else
//                        PostEventTimer -= Diff;
//                }
//                //...we are doing regular speech check
//                else if (HasFollowState(STATE_FOLLOW_INPROGRESS))
//                {
//                    if (CheckSpeechTimer <= Diff)
//                    {
//                        CheckSpeechTimer = 5000;
//
//                        if (urand(0, 9) > 8)
//                            Talk(SAY_TOOG_WORRIED);
//                    }
//                    else
//                        CheckSpeechTimer -= Diff;
//                }
//
//                return;
//            }
//
//            DoMeleeAttackIfReady();
//        }
//    };
//
//    CreatureAI* GetAI(Creature* creature) const override
//    {
//        return new npc_tooga_5955AI(creature);
//    }
//};
//
//// ##########  Vision 1: expedition to uldum
//
//enum eQuest27003
//{
//    QUEST_EASY_MONEY = 27003,
//
//    SPELL_DETECT_QUEST_INVIS_ZONE_5 = 86749,
//    SPELL_DETECT_QUEST_INVIS_ZONE_1 = 89270,
//    SPELL_SUMMON_BEAM_TARGET_BUNNY = 86942,
//    SPELL_CHAINS_OF_BONDAGE_1 = 73447,
//    SPELL_CHAINS_OF_BONDAGE_2 = 73448,
//    SPELL_CHAINS_OF_BONDAGE_3 = 73449,
//    SPELL_PLAYER_SUMMON_CAMERA = 95747,
//    SPELL_SUMMON_CAMERA_BUNNY = 86792,
//    SPELL_PING_CAMERA_00 = 86815,
//    SPELL_PERMANENT_FEIGN_DEATH = 29266,
//    SPELL_IMPRISONED = 89318,
//
//    SPELL_SUMMON_ADARRAH = 86751,
//    SPELL_SUMMON_CARAVAN = 86752,
//    SPELL_SUMMON_LADY_HUMPS = 86753,
//    SPELL_SUMMON_PACK_MULE = 86754,
//    SPELL_SUMMON_BUDDS_CAMEL = 86755,
//    SPELL_SUMMON_SAMIRS_CAMEL = 86756,
//    SPELL_SUMMON_MACKS_CAMEL = 86757,
//    SPELL_SUMMON_ADARRAHS_CAMEL = 86758,
//    
//    NPC_ADARRAH = 46533,
//    NPC_LADY_HUMPS = 46536,
//    NPC_PACK_MULE = 46537,
//    NPC_BUDDS_CAMEL = 46538,
//    NPC_SAMIRS_CAMEL = 46540,
//    NPC_MACKS_CAMEL = 46543,
//    NPC_ADARRAHS_CAMEL = 46546,
//    NPC_CLONED_IMAGE = 46554,
//    NPC_HARNISH = 46596,
//    NPC_KODO_2 = 46534,
//    NPC_KURZEL_2 = 46548,
//    NPC_TURGORE_2 = 46544,
//    NPC_TANZAR_2 = 46547,
//    NPC_HARKOR_2 = 46545,
//    NPC_PLAYER_GUID = 99999,
//    NPC_SAND_PUGMY = 47326,
//
//    EVENT_CHECK_PLAYER_IS_PRESENT = 1,
//    EVENT_ADARRAH_TALK_VIDEO,
//    EVENT_ADARRAH_TALK_0,
//    EVENT_ADARRAH_TALK_1,
//    EVENT_MOVE_ADARRAH_AROUND_PLAYER,
//    EVENT_MOVE_ADARRAH_TO_CAMEL,
//    EVENT_ADARRAH_MOUNT_CAMEL,
//    EVENT_STARTING_CARAVAN,
//    EVENT_PLAYER_MOUNT_HARNISH,
//    EVENT_BUDD_SAY_AHOJ,
//    EVENT_TELEPORT_TO_VIDEO2,
//    EVENT_SUMMON_ACTORS_VIDEO2,
//    EVENT_STARTING_VIDEO2,
//    EVENT_PUGMY_TALK1,
//    EVENT_IMPRISONED,
//    EVENT_REMOVE_IMPRISONED,
//    EVENT_PUGMY_TALK2,
//    EVENT_PUGMY_GO_AWAY,
//
//    ACTION_START_ADARRAH_TALK_VIDEO = 101,
//    ACTION_MOVE_ADARRAH_TO_PLAYER,
//    ACTION_STARTING_CARAVAN,
//
//    MOVE_ADARRAH_TO_PLAYER = 201,
//    MOVE_ADARRAH_AROUND_PLAYER,
//    MOVE_ADARRAH_TO_CAMEL,
//
//    // the blizz video create a clone of player, and let this clone do some emotes
//    // maybe someone can fix this spells.
//    SPELL_INITIALIZE_ULDRUM_INTRO = 86748,
//    SPELL_PLAYER_PREP = 86750,
//    SPELL_SUMMON_CLONED_IMAGE = 86782, // create a empty player clone.
//    SPELL_REVERSE_CAST_MIRROR_IMAGE = 86783, // Script Effect Value: 86784
//    SPELL_MIRROR_IMAGE_AURA = 86784, // Script Effect Value: 41055  Value : 45206
//    SPELL_COPY_WEAPON_ACK = 41054,
//    SPELL_COPY_WEAPON = 41055,
//    SPELL_COPY_OFF_HAND_WEAPON_ACK = 45205,
//    SPELL_COPY_OFF_HAND_WEAPON = 45206,
//};
//
//// 44833
//class npc_adarrah_44833 : public CreatureScript
//{
//public:
//    npc_adarrah_44833() : CreatureScript("npc_adarrah_44833") { }
//
//    bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest) 
//    { 
//        if (quest->GetQuestId() == QUEST_EASY_MONEY)
//        {
//            //player->RemoveAura(SPELL_DETECT_QUEST_INVIS_ZONE_5);
//            //player->AddAura(SPELL_DETECT_QUEST_INVIS_ZONE_1, player);
//            player->CastSpell(player, SPELL_SUMMON_BEAM_TARGET_BUNNY);
//        }
//
//        return false; 
//    }
//};
//
//// 46661
//class npc_beam_target_bunny_46661 : public CreatureScript
//{
//public:
//    npc_beam_target_bunny_46661() : CreatureScript("npc_beam_target_bunny_46661") { }
//     
//    struct npc_beam_target_bunny_46661AI : public ScriptedAI
//    {
//        npc_beam_target_bunny_46661AI(Creature* creature) : ScriptedAI(creature) { }
//
//        EventMap m_events;
//        uint64 playerGUID;
//        uint64 adarrahGUID;
//        uint64 harnishGUID;
//        uint64 lady_humpsGUID;
//        uint64 pack_muleGUID;
//        uint64 budds_camelGUID;
//        uint64 samirs_camelGUID;
//        uint64 macks_camelGUID;
//        uint64 adarrahs_camelGUID;
//        uint64 sandPugmy[5];
//        uint32 sandPugmyCount;
//        bool   isVideo2;
//
//        void Reset() override
//        {
//            m_events.Reset();
//            playerGUID = 0;
//            adarrahGUID = 0;
//            harnishGUID = 0;
//            lady_humpsGUID = 0;
//            pack_muleGUID = 0;
//            budds_camelGUID = 0;
//            samirs_camelGUID = 0;
//            macks_camelGUID = 0;
//            adarrahs_camelGUID = 0;
//
//            for (uint32 i = 0; i < 6; i++)
//                sandPugmy[i] = 0;
//            sandPugmyCount = 0;
//
//            isVideo2 = false;
//        }
//
//        void IsSummonedBy(Unit* summoner) override
//        {
//            if (Player* player = summoner->ToPlayer())
//            {
//                playerGUID = player->GetplayerGUID();
//                me->CastSpell(player, SPELL_SUMMON_ADARRAH);
//                me->CastSpell(player, SPELL_SUMMON_CARAVAN);
//                me->CastSpell(player, SPELL_SUMMON_LADY_HUMPS);
//                me->CastSpell(player, SPELL_SUMMON_PACK_MULE);
//                me->CastSpell(player, SPELL_SUMMON_BUDDS_CAMEL);
//                me->CastSpell(player, SPELL_SUMMON_SAMIRS_CAMEL);
//                me->CastSpell(player, SPELL_SUMMON_MACKS_CAMEL);
//                me->CastSpell(player, SPELL_SUMMON_ADARRAHS_CAMEL);
//                m_events.ScheduleEvent(EVENT_CHECK_PLAYER_IS_PRESENT, 10000);
//            }
//        }
//
//        void JustSummoned(Creature* summon) override
//        {
//            switch (summon->GetEntry())
//            {
//                case NPC_ADARRAH:
//                    AdarrahGUID = summon->GetGUID();
//                    if (Player* player = sObjectAccessor->GetPlayer(*me, playerGUID))
//                        summon->SetFacingToObject(player);
//                    break;
//                case NPC_HARNISH:
//                    HarnishGUID = summon->GetGUID();
//                    summon->SetWalk(true);
//                    summon->SetSpeed(MOVE_WALK, 0.4f);
//                    summon->SetFacingToObject(me);
//                    break;
//                case NPC_LADY_HUMPS:
//                    Lady_humpsGUID = summon->GetGUID();
//                    summon->SetWalk(true);
//                    summon->SetSpeed(MOVE_WALK, 0.4f);
//                    summon->SetFacingToObject(me);
//                    break;
//                case NPC_PACK_MULE:
//                    Pack_muleGUID = summon->GetGUID();
//                    summon->SetWalk(true);
//                    summon->SetSpeed(MOVE_WALK, 0.4f);
//                    summon->SetFacingToObject(me);
//                    break;
//                case NPC_BUDDS_CAMEL:
//                    Budds_camelGUID = summon->GetGUID();
//                    summon->SetWalk(true);
//                    summon->SetSpeed(MOVE_WALK, 0.4f);
//                    summon->SetFacingToObject(me);
//                    break;
//                case NPC_SAMIRS_CAMEL:
//                    Samirs_camelGUID = summon->GetGUID();
//                    summon->SetWalk(true);
//                    summon->SetSpeed(MOVE_WALK, 0.4f);
//                    summon->SetFacingToObject(me);
//                    break;
//                case NPC_MACKS_CAMEL:
//                    Macks_camelGUID = summon->GetGUID();
//                    summon->SetWalk(true);
//                    summon->SetSpeed(MOVE_WALK, 0.4f);
//                    summon->SetFacingToObject(me);
//                    break;
//                case NPC_ADARRAHS_CAMEL:
//                    Adarrahs_camelGUID = summon->GetGUID();
//                    summon->SetWalk(true);
//                    summon->SetSpeed(MOVE_WALK, 0.4f);
//                    summon->SetFacingToObject(me);
//                    break;
//                case NPC_SAND_PUGMY:
//                    summon->RemoveAura(SPELL_PERMANENT_FEIGN_DEATH);
//                    summon->setFaction(7);
//                    summon->SetUInt32Value(UNIT_FIELD_FLAGS, 0);
//                    summon->SetUInt32Value(UNIT_FIELD_FLAGS_2, 2048);
//                    summon->SetUInt32Value(UNIT_DYNAMIC_FLAGS, 0);                    
//                    sandPugmy[sandPugmyCount] = summon->GetGUID();
//                    sandPugmyCount += 1;
//                    break;
//            }
//            if (isVideo2)
//            {
//                summon->SetPhaseMask(2, true);
//            }
//        }
//
//        void DoAction(int32 param) override
//        { 
//            switch (param)
//            {
//                case ACTION_STARTING_CARAVAN:
//                {                    
//                    m_events.ScheduleEvent(EVENT_STARTING_CARAVAN, 1000);
//                }
//            }
//        }
//
//        uint64 GetGUID(int32 id = 0) const 
//        { 
//            switch (id)
//            {
//                case NPC_ADARRAH:
//                    return adarrahGUID;
//                case NPC_LADY_HUMPS:
//                    return lady_humpsGUID;
//                case NPC_PACK_MULE:
//                    return pack_muleGUID;
//                case NPC_BUDDS_CAMEL:
//                    return budds_camelGUID;
//                case NPC_SAMIRS_CAMEL:
//                    return samirs_camelGUID;
//                case NPC_MACKS_CAMEL:
//                    return macks_camelGUID;
//                case NPC_HARNISH:
//                    return harnishGUID;
//                case NPC_ADARRAHS_CAMEL:
//                    return adarrahs_camelGUID;
//                case NPC_PLAYER_GUID:
//                    return playerGUID;
//            }
//            return 0; 
//        }
//
//        void UpdateAI(uint32 diff) override
//        {
//            m_events.Update(diff);
//
//            while (uint32 eventId = m_events.ExecuteEvent())
//            {
//                switch (eventId)
//                {
//                    case EVENT_CHECK_PLAYER_IS_PRESENT:
//                    {
//                        bool ok = false;
//                        if (Player* player = sObjectAccessor->GetPlayer(*me, playerGUID))
//                            if (player->IsAlive() && player->GetDistance2d(me) < 500.0f)
//                                if (player->GetQuestStatus(QUEST_EASY_MONEY) == QUEST_STATUS_INCOMPLETE)
//                                    ok = true;
//
//                        if (ok)
//                            m_events.ScheduleEvent(EVENT_CHECK_PLAYER_IS_PRESENT, 5000);
//                        else
//                            DespawnCaravan();
//                       
//                        break;
//                    } 
//                    case EVENT_STARTING_CARAVAN:
//                    {
//                        StartMovingCaravan();
//                        m_events.ScheduleEvent(EVENT_PLAYER_MOUNT_HARNISH, 3000);
//                        m_events.ScheduleEvent(EVENT_BUDD_SAY_AHOJ, 6000);
//                        m_events.ScheduleEvent(EVENT_TELEPORT_TO_VIDEO2, 11000);
//                        m_events.ScheduleEvent(EVENT_SUMMON_ACTORS_VIDEO2, 12000);
//                        m_events.ScheduleEvent(EVENT_STARTING_VIDEO2, 16000);
//                        break;
//                    }
//                    case EVENT_PLAYER_MOUNT_HARNISH:
//                    {
//                        Player* player = sObjectAccessor->GetPlayer(*me, playerGUID);
//                        Creature* npc = sObjectAccessor->GetCreature(*me, harnishGUID);
//                        if (player)
//                        {
//                            if (isVideo2)
//                            {
//                                player->AddAura(59073, player);
//                                player->AddAura(49416, player);
//                            }
//
//                            if (npc)
//                                player->EnterVehicle(npc, -1);
//                            else
//                                m_events.ScheduleEvent(EVENT_PLAYER_MOUNT_HARNISH, 500);
//                        }
//
//                        break;
//                    }                   
//                    case EVENT_BUDD_SAY_AHOJ:
//                    {
//                        if (Creature* budd = sObjectAccessor->GetCreature(*me, budds_camelGUID))
//                            budd->AI()->Talk(0);
//                        break;
//                    }
//                    case EVENT_TELEPORT_TO_VIDEO2:
//                    {
//                        StartTeleport();
//                        break;
//                    }
//                    case EVENT_SUMMON_ACTORS_VIDEO2:
//                    {
//                        SummonActorsVideo2();
//                        break;
//                    }
//                    case EVENT_STARTING_VIDEO2:
//                    {
//                        if (Creature* npc = sObjectAccessor->GetCreature(*me, sandPugmy[2]))
//                            npc->AI()->Talk(0);
//
//                        m_events.ScheduleEvent(EVENT_PUGMY_TALK1, 5000);
//                        break;
//                    }                   
//                    case EVENT_PUGMY_TALK1:
//                    {
//                        if (Creature* npc = sObjectAccessor->GetCreature(*me, sandPugmy[4]))
//                            npc->AI()->Talk(1);
//
//                        m_events.ScheduleEvent(EVENT_IMPRISONED, 5000);
//                        break;
//                    }
//                    case EVENT_IMPRISONED:
//                    {
//                        if (Player* player = sObjectAccessor->GetPlayer(*me, playerGUID))
//                        {
//                            DespawnCaravan();
//                            player->CastSpell(player, SPELL_IMPRISONED);
//                            m_events.ScheduleEvent(EVENT_REMOVE_IMPRISONED, 5000);
//                        }
//                        break;
//                    }
//                }
//            }
//        }
//
//        void DespawnCaravan()
//        {
//            if (Creature* npc = sObjectAccessor->GetCreature(*me, adarrahGUID))
//                npc->DespawnOrUnsummon();
//            if (Creature* npc = sObjectAccessor->GetCreature(*me, harnishGUID))
//                npc->DespawnOrUnsummon();
//            if (Creature* npc = sObjectAccessor->GetCreature(*me, lady_humpsGUID))
//                npc->DespawnOrUnsummon();
//            if (Creature* npc = sObjectAccessor->GetCreature(*me, pack_muleGUID))
//                npc->DespawnOrUnsummon();
//            if (Creature* npc = sObjectAccessor->GetCreature(*me, budds_camelGUID))
//                npc->DespawnOrUnsummon();
//            if (Creature* npc = sObjectAccessor->GetCreature(*me, samirs_camelGUID))
//                npc->DespawnOrUnsummon();
//            if (Creature* npc = sObjectAccessor->GetCreature(*me, macks_camelGUID))
//                npc->DespawnOrUnsummon();
//            if (Creature* npc = sObjectAccessor->GetCreature(*me, adarrahs_camelGUID))
//                npc->DespawnOrUnsummon();
//
//            adarrahGUID = 0;
//            harnishGUID = 0;
//            lady_humpsGUID = 0;
//            pack_muleGUID = 0;
//            budds_camelGUID = 0;
//            samirs_camelGUID = 0;
//            macks_camelGUID = 0;
//            adarrahs_camelGUID = 0;
//
//            for (uint32 i = 0; i < 6; i++)
//                if (Creature* npc = sObjectAccessor->GetCreature(*me, sandPugmy[i]))
//                {
//                    npc->DespawnOrUnsummon();
//                    sandPugmy[i] = 0;
//                }
//            sandPugmyCount = 0;
//        }
//
//        void StartMovingCaravan()
//        {
//            if (Creature* npc = sObjectAccessor->GetCreature(*me, harnishGUID))
//                npc->GetMotionMaster()->MovePoint(24, me->GetPosition());
//            if (Creature* npc = sObjectAccessor->GetCreature(*me, lady_humpsGUID))
//                npc->GetMotionMaster()->MovePoint(24, me->GetPosition());
//            if (Creature* npc = sObjectAccessor->GetCreature(*me, pack_muleGUID))
//                npc->GetMotionMaster()->MovePoint(24, me->GetPosition());
//            if (Creature* npc = sObjectAccessor->GetCreature(*me, budds_camelGUID))
//                npc->GetMotionMaster()->MovePoint(24, me->GetPosition());
//            if (Creature* npc = sObjectAccessor->GetCreature(*me, samirs_camelGUID))
//                npc->GetMotionMaster()->MovePoint(24, me->GetPosition());
//            if (Creature* npc = sObjectAccessor->GetCreature(*me, macks_camelGUID))
//                npc->GetMotionMaster()->MovePoint(24, me->GetPosition());
//            if (Creature* npc = sObjectAccessor->GetCreature(*me, adarrahs_camelGUID))
//                npc->GetMotionMaster()->MovePoint(24, me->GetPosition());
//        }
//
//        void StartTeleport()
//        {
//            isVideo2 = true;
//            me->NearTeleportTo(-8958.0f, -1610.0f, 94.5f, 4.73f);           
//            DespawnCaravan();
//            if (Player* player = sObjectAccessor->GetPlayer(*me, playerGUID))
//                player->NearTeleportTo(-8958.0f, -1697.0f, 94.46f, 1.57f);
//        }
//
//        void SummonActorsVideo2()
//        {
//            me->SetPhaseMask(2, true);
//            me->SummonCreature(NPC_LADY_HUMPS, -8958.0f, -1671.0f, 94.46f, 1.57f, TEMPSUMMON_TIMED_DESPAWN, 120000);
//            me->SummonCreature(NPC_HARNISH, -8958.0f, -1697.0f, 94.46f, 1.57f, TEMPSUMMON_TIMED_DESPAWN, 120000);
//            me->SummonCreature(NPC_PACK_MULE, -8948.0f, -1695.0f, 94.46f, 1.57f, TEMPSUMMON_TIMED_DESPAWN, 120000);
//            me->SummonCreature(NPC_MACKS_CAMEL, -8948.0f, -1700.0f, 94.46f, 1.57f, TEMPSUMMON_TIMED_DESPAWN, 120000);
//            me->SummonCreature(NPC_SAMIRS_CAMEL, -8948.0f, -1705.0f, 94.46f, 1.57f, TEMPSUMMON_TIMED_DESPAWN, 120000);
//            me->SummonCreature(NPC_ADARRAHS_CAMEL, -8968.0f, -1697.0f, 94.46f, 1.57f, TEMPSUMMON_TIMED_DESPAWN, 120000);
//            me->SummonCreature(NPC_ADARRAH, -8968.0f, -1697.0f, 94.46f, 1.57f, TEMPSUMMON_TIMED_DESPAWN, 120000);
//            me->SummonCreature(NPC_BUDDS_CAMEL, -8968.0f, -1690.0f, 94.46f, 1.57f, TEMPSUMMON_TIMED_DESPAWN, 120000);
//
//            me->SummonCreature(NPC_SAND_PUGMY, -8961.2f, -1669.1f, 94.46f, 4.57f, TEMPSUMMON_TIMED_DESPAWN, 120000);
//            me->SummonCreature(NPC_SAND_PUGMY, -8955.9f, -1669.2f, 94.46f, 4.57f, TEMPSUMMON_TIMED_DESPAWN, 120000);
//            me->SummonCreature(NPC_SAND_PUGMY, -8955.1f, -1707.6f, 94.46f, 1.57f, TEMPSUMMON_TIMED_DESPAWN, 120000);
//            me->SummonCreature(NPC_SAND_PUGMY, -8960.0f, -1708.0f, 94.46f, 1.57f, TEMPSUMMON_TIMED_DESPAWN, 120000);
//            me->SummonCreature(NPC_SAND_PUGMY, -8965.3f, -1707.3f, 94.46f, 1.57f, TEMPSUMMON_TIMED_DESPAWN, 120000);
//            me->SummonCreature(NPC_SAND_PUGMY, -8963.3f, -1707.0f, 94.46f, 1.57f, TEMPSUMMON_TIMED_DESPAWN, 120000);
//
//            m_events.ScheduleEvent(EVENT_PLAYER_MOUNT_HARNISH, 200);
//        }
//
//    };
//
//    CreatureAI* GetAI(Creature* creature) const override
//    {
//        return new npc_beam_target_bunny_46661AI(creature);
//    }
//};
//
//// 46533
//class npc_adarrah_46533 : public CreatureScript
//{
//public:
//    npc_adarrah_46533() : CreatureScript("npc_adarrah_46533") { }
//
//    struct npc_adarrah_46533AI : public ScriptedAI
//    {
//        npc_adarrah_46533AI(Creature* creature) : ScriptedAI(creature) { }
//
//        EventMap m_events;
//        uint64 target_bunnyGUID;
//        float angle;
//
//        void Reset() override
//        {
//            target_bunnyGUID = 0;
//            angle = 0;
//            m_events.Reset();
//        }
//
//        void IsSummonedBy(Unit* summoner) override
//        {
//            target_bunnyGUID = summoner->GetGUID();
//        }
//
//        void OnQuestAccept(Player* player, Quest const* quest) override
//        {
//            if (quest->GetQuestId() == QUEST_TOOGA)
//                StartFollow(player, FACTION_ESCORTEE_N_NEUTRAL_PASSIVE, QUEST_TOOGA);
//        
//
//    CreatureAI* GetAI(Creature* creature) const override
//    {
//        return new npc_adarrah_46533AI(creature);
//    }
//};
//
//        void MovementInform(uint32 type, uint32 id)
//        {
//            if (type != 8)
//                return;
//
//            switch (id)
//            {
//            case MOVE_ADARRAH_TO_PLAYER:
//            {
//                m_events.ScheduleEvent(EVENT_ADARRAH_TALK_0, 25);
//                break;
//            }
//            case MOVE_ADARRAH_AROUND_PLAYER:
//            {
//                m_events.ScheduleEvent(EVENT_MOVE_ADARRAH_TO_CAMEL, 25);
//                break;
//            }
//            case MOVE_ADARRAH_TO_CAMEL:
//            {
//                m_events.ScheduleEvent(EVENT_ADARRAH_MOUNT_CAMEL, 25);
//                break;
//            }
//            }
//        }
//
//        void DoAction(int32 param) override
//        {
//            switch (param)
//            {
//            case ACTION_START_ADARRAH_TALK_VIDEO:
//            {
//                if (Creature* bunny = sObjectAccessor->GetCreature(*me, target_bunnyGUID))
//                    if (Player* player = sObjectAccessor->GetPlayer(*me, bunny->GetAI()->GetGUID(NPC_PLAYER_GUID)))
//                    {
//                        angle = me->GetAngle(player->GetPositionX(), player->GetPositionY());
//                        Position pos = player->GetNearPosition(2.0f, angle);
//                        me->GetMotionMaster()->MovePoint(MOVE_ADARRAH_TO_PLAYER, pos);
//                    }
//                break;
//            }
//            }
//        }
//
//        void UpdateAI(uint32 diff) override
//        {
//            m_events.Update(diff);
//
//            while (uint32 eventId = m_events.ExecuteEvent())
//            {
//                switch (eventId)
//                {
//                case EVENT_ADARRAH_TALK_0:
//                {
//                    Talk(0);
//                    if (Creature* bunny = sObjectAccessor->GetCreature(*me, target_bunnyGUID))
//                        if (Player* player = sObjectAccessor->GetPlayer(*me, bunny->GetAI()->GetGUID(NPC_PLAYER_GUID)))
//                            me->SetFacingToObject(player);
//                    m_events.ScheduleEvent(EVENT_ADARRAH_TALK_1, 5000);
//                    break;
//                }
//                case EVENT_ADARRAH_TALK_1:
//                {
//                    Talk(1);
//                    m_events.ScheduleEvent(EVENT_MOVE_ADARRAH_AROUND_PLAYER, 5000);
//                    break;
//                }
//                case EVENT_MOVE_ADARRAH_AROUND_PLAYER:
//                {
//                    if (Creature* bunny = sObjectAccessor->GetCreature(*me, target_bunnyGUID))
//                        if (Player* player = sObjectAccessor->GetPlayer(*me, bunny->GetAI()->GetGUID(NPC_PLAYER_GUID)))
//                        {
//                            float d1 = me->GetDistance2d(-8929.17f, -2262.24f);
//                            float d2 = me->GetDistance2d(-8928.21f, -2267.25f);
//                            if (d1 < d2)
//                                me->GetMotionMaster()->MovePoint(MOVE_ADARRAH_AROUND_PLAYER, -8929.17f, -2262.24f, 8.877f);
//                            else
//                                me->GetMotionMaster()->MovePoint(MOVE_ADARRAH_AROUND_PLAYER, -8929.17f, -2262.24f, 8.877f);
//                        }
//                    break;
//                }
//                case EVENT_MOVE_ADARRAH_TO_CAMEL:
//                {
//                    if (Creature* bunny = sObjectAccessor->GetCreature(*me, target_bunnyGUID))
//                        if (Creature* camel = sObjectAccessor->GetCreature(*me, bunny->GetAI()->GetGUID(NPC_ADARRAHS_CAMEL)))
//                        {
//                            float angle = camel->GetAngle(me->GetPositionX(), me->GetPositionY());
//                            Position pos = camel->GetNearPosition(2.0f, angle);
//                            me->GetMotionMaster()->MovePoint(MOVE_ADARRAH_TO_CAMEL, pos);
//                        }
//                    break;
//                }
//                case EVENT_ADARRAH_MOUNT_CAMEL:
//                {
//                    if (Creature* bunny = sObjectAccessor->GetCreature(*me, target_bunnyGUID))
//                        if (Creature* camel = sObjectAccessor->GetCreature(*me, bunny->GetAI()->GetGUID(NPC_ADARRAHS_CAMEL)))
//                        {
//                            me->EnterVehicle(camel, 0);
//                            bunny->GetAI()->DoAction(ACTION_STARTING_CARAVAN);
//                        }
//                    break;
//                }
//                }
//            }
//        }
//    };
//
//// 46536
//class npc_lady_humps_46536 : public CreatureScript
//{
//public:
//    npc_lady_humps_46536() : CreatureScript("npc_lady_humps_46536") { }
//
//    struct npc_lady_humps_46536AI : public ScriptedAI
//    {
//        npc_lady_humps_46536AI(Creature* creature) : ScriptedAI(creature) { isStarted = false; }
//
//        uint64 target_bunnyGUID;
//        bool isStarted;
//
//        void Reset() override
//        {
//            target_bunnyGUID = 0;            
//        }
//
//        void IsSummonedBy(Unit* summoner) override
//        {
//            target_bunnyGUID = summoner->GetGUID();
//        }
//
//        void OnSpellClick(Unit* clicker, bool& result) override
//        {
//            if (!isStarted)
//            if (Player* player = clicker->ToPlayer())
//                if (player->GetQuestStatus(QUEST_EASY_MONEY) == QUEST_STATUS_INCOMPLETE)
//                    if (Creature* bunny = sObjectAccessor->GetCreature(*me, target_bunnyGUID))
//                        if (Creature* adarrah = sObjectAccessor->GetCreature(*me, bunny->GetAI()->GetGUID(NPC_ADARRAH)))
//                        {
//                            adarrah->GetAI()->DoAction(ACTION_START_ADARRAH_TALK_VIDEO);
//                            isStarted = true;
//                        }
//        }
//    };
//
//    CreatureAI* GetAI(Creature* creature) const override
//    {
//        return new npc_lady_humps_46536AI(creature);
//    }
//};
//
//// 46596
//class npc_uldum_caravan_harness_46596 : public CreatureScript
//{
//public:
//    npc_uldum_caravan_harness_46596() : CreatureScript("npc_uldum_caravan_harness_46596") { }
//
//    struct npc_uldum_caravan_harness_46596AI : public ScriptedAI
//    {
//        npc_uldum_caravan_harness_46596AI(Creature* creature) : ScriptedAI(creature) { }
//
//        EventMap m_events;
//        uint64 bunnyGUID;
//        uint64 kodoGUID;
//        uint64 kurzelGUID;
//        uint64 turgoreGUID;
//        uint64 tanzarGUID;
//        uint64 harkorGUID;
//        bool   hasChains;
//
//        void Reset() override
//        {
//            m_events.Reset();
//            bunnyGUID = 0;
//            kodoGUID = 0;
//            kurzelGUID = 0;
//            turgoreGUID = 0;
//            tanzarGUID = 0;
//            harkorGUID = 0;
//            hasChains = false;
//        }
//
//        void IsSummonedBy(Unit* summoner) override
//        {
//            bunnyGUID = summoner->GetGUID();
//        }
//
//        void JustSummoned(Creature* summon) override
//        {
//            switch (summon->GetEntry())
//            {
//                case NPC_KODO_2:
//                {
//                    kodoGUID = summon->GetGUID();
//                    break;
//                }
//                case NPC_KURZEL_2:
//                {
//                    kurzelGUID = summon->GetGUID();
//                    break;
//                }
//                case NPC_TURGORE_2:
//                {
//                    turgoreGUID = summon->GetGUID();
//                    break;
//                }
//                case NPC_TANZAR_2:
//                {
//                    tanzarGUID = summon->GetGUID();
//                    break;
//                }
//                case NPC_HARKOR_2:
//                {
//                    harkorGUID = summon->GetGUID();
//                    break;
//                }
//            }
//            CreateChains();
//        }
//
//        // maybe better to disable??? chains are visible in different phases and uses wrong start/end data..
//        void CreateChains()
//        {
//            if (!hasChains)
//                if (Creature* kodo = sObjectAccessor->GetCreature(*me, kodoGUID))
//                    if (Creature* turgore = sObjectAccessor->GetCreature(*me, turgoreGUID))
//                    {
//                        hasChains = true;
//                        kodo->CastSpell(turgore, SPELL_CHAINS_OF_BONDAGE_1, true);
//                        //turgore->CastSpell(kodo, SPELL_CHAINS_OF_BONDAGE_2, true);
//                        //turgore->CastSpell(kodo, SPELL_CHAINS_OF_BONDAGE_3, true);
//                    }
//        }
//        
//    };
//
//    CreatureAI* GetAI(Creature* creature) const override
//    {
//        return new npc_uldum_caravan_harness_46596AI(creature);
//    }
//};
//
//// ##########  Vision 2: has same actors as in video 1..
//
//// ##########  Vision 3: 
//
//// 46873
//class npc_adarrah_46873 : public CreatureScript
//{
//public:
//    npc_adarrah_46873() : CreatureScript("npc_adarrah_46873") { }
//
//    struct npc_adarrah_46873AI : public ScriptedAI
//    {
//        npc_adarrah_46873AI(Creature* creature) : ScriptedAI(creature) { }
//
//        EventMap m_events;
//       
//        void Reset() override
//        {
//            m_events.Reset();
//        }
//
//        void UpdateAI(uint32 diff) override
//        {
//            m_events.Update(diff);
//
//            while (uint32 eventId = m_events.ExecuteEvent())
//            {
//                switch (eventId)
//                {
//                case EVENT_ADARRAH_TALK_0:
//                {
//                   
//                }                
//                }
//            }
//        }
//    };
//
//    CreatureAI* GetAI(Creature* creature) const override
//    {
//        return new npc_adarrah_46873AI(creature);
//    }
//};
//
//void AddSC_tanaris()
//{
//    new npc_aquementas_9453();
//    new npc_custodian_of_time_19950();
//    new npc_steward_of_time_20142();
//    new npc_OOX17_7784();
//    new npc_tooga_5955();
//    new npc_adarrah_44833();
//    new npc_beam_target_bunny_46661();
//    new npc_adarrah_46533();
//    new npc_lady_humps_46536();
//    new npc_uldum_caravan_harness_46596();
//    new npc_adarrah_46873();
