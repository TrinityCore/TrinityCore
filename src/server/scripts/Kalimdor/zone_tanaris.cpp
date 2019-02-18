/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

/* ScriptData
SDName: Tanaris
SD%Complete: 80
SDComment: Quest support: 648, 10277
SDCategory: Tanaris
EndScriptData */

/* ContentData
npc_custodian_of_time
npc_OOX17
EndContentData */

#include "ScriptMgr.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedEscortAI.h"
#include "ScriptedFollowerAI.h"
#include "ScriptedGossip.h"

/*######
## npc_aquementas
######*/

enum Aquementas
{
    AGGRO_YELL_AQUE     = 0,

    SPELL_AQUA_JET      = 13586,
    SPELL_FROST_SHOCK   = 15089,

    ITEM_BOOK_OF_AQUOR  = 11169,
    ITEM_SILVERY_CLAWS  = 11172,
    ITEM_IRONTREE_HEART = 11173,
    ITEM_SILVER_TOTEM   = 11522
};

class npc_aquementas : public CreatureScript
{
public:
    npc_aquementas() : CreatureScript("npc_aquementas") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_aquementasAI (creature);
    }

    struct npc_aquementasAI : public ScriptedAI
    {
        npc_aquementasAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            SendItemTimer = 0;
            SwitchFactionTimer = 10000;

            isFriendly = true;

            AquaJetTimer = 5000;
            FrostShockTimer = 1000;
        }

        uint32 SendItemTimer;
        uint32 SwitchFactionTimer;
        bool isFriendly;

        uint32 FrostShockTimer;
        uint32 AquaJetTimer;

        void Reset() override
        {
            Initialize();
            me->setFaction(35);
        }

        void SendItem(Unit* receiver)
        {
            Player* player = receiver->ToPlayer();

            if (player && player->HasItemCount(ITEM_BOOK_OF_AQUOR, 1, false) &&
                player->HasItemCount(ITEM_SILVERY_CLAWS, 11, false) &&
                player->HasItemCount(ITEM_IRONTREE_HEART, 1, false) &&
                !player->HasItemCount(ITEM_SILVER_TOTEM, 1, true))
            {
                ItemPosCountVec dest;
                uint8 msg = player->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, 11522, 1, NULL);
                if (msg == EQUIP_ERR_OK)
                    player->StoreNewItem(dest, ITEM_SILVER_TOTEM, true);
            }
        }

        void EnterCombat(Unit* who) override
        {
            Talk(AGGRO_YELL_AQUE, who);
        }

        void UpdateAI(uint32 diff) override
        {
            if (isFriendly)
            {
                if (SwitchFactionTimer <= diff)
                {
                    me->setFaction(91);
                    isFriendly = false;
                } else SwitchFactionTimer -= diff;
            }

            if (!UpdateVictim())
                return;

            if (!isFriendly)
            {
                if (SendItemTimer <= diff)
                {
                    if (me->GetVictim() && me->EnsureVictim()->GetTypeId() == TYPEID_PLAYER)
                        SendItem(me->GetVictim());
                    SendItemTimer = 5000;
                } else SendItemTimer -= diff;
            }

            if (FrostShockTimer <= diff)
            {
                DoCastVictim(SPELL_FROST_SHOCK);
                FrostShockTimer = 15000;
            } else FrostShockTimer -= diff;

            if (AquaJetTimer <= diff)
            {
                DoCast(me, SPELL_AQUA_JET);
                AquaJetTimer = 15000;
            } else AquaJetTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};

/*######
## npc_custodian_of_time
######*/

enum CustodianOfTime
{
    WHISPER_CUSTODIAN_1     = 0,
    WHISPER_CUSTODIAN_2     = 1,
    WHISPER_CUSTODIAN_3     = 2,
    WHISPER_CUSTODIAN_4     = 3,
    WHISPER_CUSTODIAN_5     = 4,
    WHISPER_CUSTODIAN_6     = 5,
    WHISPER_CUSTODIAN_7     = 6,
    WHISPER_CUSTODIAN_8     = 7,
    WHISPER_CUSTODIAN_9     = 8,
    WHISPER_CUSTODIAN_10    = 9,
    WHISPER_CUSTODIAN_11    = 10,
    WHISPER_CUSTODIAN_12    = 11,
    WHISPER_CUSTODIAN_13    = 12,
    WHISPER_CUSTODIAN_14    = 13,

    QUEST_CAVERNS_OF_TIME   = 10277,
    SPELL_QID_10277         = 34883
};

class npc_custodian_of_time : public CreatureScript
{
public:
    npc_custodian_of_time() : CreatureScript("npc_custodian_of_time") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_custodian_of_timeAI(creature);
    }

    struct npc_custodian_of_timeAI : public npc_escortAI
    {
        npc_custodian_of_timeAI(Creature* creature) : npc_escortAI(creature) { }

        void WaypointReached(uint32 waypointId) override
        {
            if (Player* player = GetPlayerForEscort())
            {
                switch (waypointId)
                {
                    case 0:
                        Talk(WHISPER_CUSTODIAN_1, player);
                        break;
                    case 1:
                        Talk(WHISPER_CUSTODIAN_2, player);
                        break;
                    case 2:
                        Talk(WHISPER_CUSTODIAN_3, player);
                        break;
                    case 3:
                        Talk(WHISPER_CUSTODIAN_4, player);
                        break;
                    case 5:
                        Talk(WHISPER_CUSTODIAN_5, player);
                        break;
                    case 6:
                        Talk(WHISPER_CUSTODIAN_6, player);
                        break;
                    case 7:
                        Talk(WHISPER_CUSTODIAN_7, player);
                        break;
                    case 8:
                        Talk(WHISPER_CUSTODIAN_8, player);
                        break;
                    case 9:
                        Talk(WHISPER_CUSTODIAN_9, player);
                        break;
                    case 10:
                        Talk(WHISPER_CUSTODIAN_4, player);
                        break;
                    case 13:
                        Talk(WHISPER_CUSTODIAN_10, player);
                        break;
                    case 14:
                        Talk(WHISPER_CUSTODIAN_4, player);
                        break;
                    case 16:
                        Talk(WHISPER_CUSTODIAN_11, player);
                        break;
                    case 17:
                        Talk(WHISPER_CUSTODIAN_12, player);
                        break;
                    case 18:
                        Talk(WHISPER_CUSTODIAN_4, player);
                        break;
                    case 22:
                        Talk(WHISPER_CUSTODIAN_13, player);
                        break;
                    case 23:
                        Talk(WHISPER_CUSTODIAN_4, player);
                        break;
                    case 24:
                        Talk(WHISPER_CUSTODIAN_14, player);
                        DoCast(player, SPELL_QID_10277);
                        // below here is temporary workaround, to be removed when spell works properly
                        player->AreaExploredOrEventHappens(QUEST_CAVERNS_OF_TIME);
                        break;
                }
            }
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (HasEscortState(STATE_ESCORT_ESCORTING))
                return;

            if (Player* player = who->ToPlayer())
            {
                if (who->HasAura(34877) && player->GetQuestStatus(10277) == QUEST_STATUS_INCOMPLETE)
                {
                    float Radius = 10.0f;
                    if (me->IsWithinDistInMap(who, Radius))
                    {
                        Start(false, false, who->GetGUID());
                    }
                }
            }
        }

        void EnterCombat(Unit* /*who*/) override { }
        void Reset() override { }

        void UpdateAI(uint32 diff) override
        {
            npc_escortAI::UpdateAI(diff);
        }
    };

};

/*######
## npc_OOX17
######*/

enum Npc00X17
{
    SAY_OOX_START           = 0,
    SAY_OOX_AGGRO           = 1,
    SAY_OOX_AMBUSH          = 2,
    SAY_OOX17_AMBUSH_REPLY  = 0,
    SAY_OOX_END             = 3,

    Q_OOX17                 = 648,
    SPAWN_FIRST             = 7803,
    SPAWN_SECOND_1          = 5617,
    SPAWN_SECOND_2          = 7805
};

class npc_OOX17 : public CreatureScript
{
public:
    npc_OOX17() : CreatureScript("npc_OOX17") { }

    bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest) override
    {
        if (quest->GetQuestId() == Q_OOX17)
        {
            creature->setFaction(113);
            creature->SetFullHealth();
            creature->SetUInt32Value(UNIT_FIELD_BYTES_1, 0);
            creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
            creature->AI()->Talk(SAY_OOX_START);

            if (npc_escortAI* pEscortAI = CAST_AI(npc_OOX17::npc_OOX17AI, creature->AI()))
                pEscortAI->Start(true, false, player->GetGUID());
        }
        return true;
    }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_OOX17AI(creature);
    }

    struct npc_OOX17AI : public npc_escortAI
    {
        npc_OOX17AI(Creature* creature) : npc_escortAI(creature) { }

        void WaypointReached(uint32 waypointId) override
        {
            if (Player* player = GetPlayerForEscort())
            {
                switch (waypointId)
                {
                    case 23:
                        me->SummonCreature(SPAWN_FIRST, -8350.96f, -4445.79f, 10.10f, 6.20f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
                        me->SummonCreature(SPAWN_FIRST, -8355.96f, -4447.79f, 10.10f, 6.27f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
                        me->SummonCreature(SPAWN_FIRST, -8353.96f, -4442.79f, 10.10f, 6.08f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
                        Talk(SAY_OOX_AMBUSH);
                        break;
                    case 56:
                        me->SummonCreature(SPAWN_SECOND_1, -7510.07f, -4795.50f, 9.35f, 6.06f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
                        me->SummonCreature(SPAWN_SECOND_2, -7515.07f, -4797.50f, 9.35f, 6.22f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
                        me->SummonCreature(SPAWN_SECOND_2, -7518.07f, -4792.50f, 9.35f, 6.22f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
                        Talk(SAY_OOX_AMBUSH);
                        if (Creature* scoff = me->FindNearestCreature(SPAWN_SECOND_2, 30))
                            scoff->AI()->Talk(SAY_OOX17_AMBUSH_REPLY);
                        break;
                    case 86:
                        Talk(SAY_OOX_END);
                        player->GroupEventHappens(Q_OOX17, me);
                        break;
                }
            }
        }

        void Reset() override { }

        void EnterCombat(Unit* /*who*/) override
        {
            Talk(SAY_OOX_AGGRO);
        }

        void JustSummoned(Creature* summoned) override
        {
            summoned->AI()->AttackStart(me);
        }
    };
};

/*####
# npc_tooga
####*/

enum Tooga
{
    SAY_TOOG_WORRIED            = 0,
    SAY_TOOG_POST_1             = 1,
    SAY_TORT_POST_2             = 0,
    SAY_TOOG_POST_3             = 2,
    SAY_TORT_POST_4             = 1,
    SAY_TOOG_POST_5             = 3,
    SAY_TORT_POST_6             = 2,

    QUEST_TOOGA                 = 1560,
    NPC_TORTA                   = 6015,

    POINT_ID_TO_WATER           = 1,
    FACTION_TOOG_ESCORTEE       = 113
};

Position const ToWaterLoc = {-7032.664551f, -4906.199219f, -1.606446f, 0.0f};

class npc_tooga : public CreatureScript
{
public:
    npc_tooga() : CreatureScript("npc_tooga") { }

    bool OnQuestAccept(Player* player, Creature* creature, const Quest* quest) override
    {
        if (quest->GetQuestId() == QUEST_TOOGA)
        {
            if (npc_toogaAI* pToogaAI = CAST_AI(npc_tooga::npc_toogaAI, creature->AI()))
                pToogaAI->StartFollow(player, FACTION_TOOG_ESCORTEE, quest);
        }

        return true;
    }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_toogaAI(creature);
    }

    struct npc_toogaAI : public FollowerAI
    {
        npc_toogaAI(Creature* creature) : FollowerAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            CheckSpeechTimer = 2500;
            PostEventTimer = 1000;
            PhasePostEvent = 0;

            TortaGUID.Clear();
        }

        uint32 CheckSpeechTimer;
        uint32 PostEventTimer;
        uint32 PhasePostEvent;

        ObjectGuid TortaGUID;

        void Reset() override
        {
            Initialize();
        }

        void MoveInLineOfSight(Unit* who) override
        {
            FollowerAI::MoveInLineOfSight(who);

            if (!me->GetVictim() && !HasFollowState(STATE_FOLLOW_COMPLETE | STATE_FOLLOW_POSTEVENT) && who->GetEntry() == NPC_TORTA)
            {
                if (me->IsWithinDistInMap(who, INTERACTION_DISTANCE))
                {
                    Player* player = GetLeaderForFollower();
                    if (player && player->GetQuestStatus(QUEST_TOOGA) == QUEST_STATUS_INCOMPLETE)
                        player->GroupEventHappens(QUEST_TOOGA, me);

                    TortaGUID = who->GetGUID();
                    SetFollowComplete(true);
                }
            }
        }

        void MovementInform(uint32 MotionType, uint32 PointId) override
        {
            FollowerAI::MovementInform(MotionType, PointId);

            if (MotionType != POINT_MOTION_TYPE)
                return;

            if (PointId == POINT_ID_TO_WATER)
                SetFollowComplete();
        }

        void UpdateFollowerAI(uint32 Diff) override
        {
            if (!UpdateVictim())
            {
                //we are doing the post-event, or...
                if (HasFollowState(STATE_FOLLOW_POSTEVENT))
                {
                    if (PostEventTimer <= Diff)
                    {
                        PostEventTimer = 5000;

                        Creature* torta = ObjectAccessor::GetCreature(*me, TortaGUID);
                        if (!torta || !torta->IsAlive())
                        {
                            //something happened, so just complete
                            SetFollowComplete();
                            return;
                        }

                        switch (PhasePostEvent)
                        {
                            case 1:
                                Talk(SAY_TOOG_POST_1);
                                break;
                            case 2:
                                torta->AI()->Talk(SAY_TORT_POST_2);
                                break;
                            case 3:
                                Talk(SAY_TOOG_POST_3);
                                break;
                            case 4:
                                torta->AI()->Talk(SAY_TORT_POST_4);
                                break;
                            case 5:
                                Talk(SAY_TOOG_POST_5);
                                break;
                            case 6:
                                torta->AI()->Talk(SAY_TORT_POST_6);
                                me->GetMotionMaster()->MovePoint(POINT_ID_TO_WATER, ToWaterLoc);
                                break;
                        }

                        ++PhasePostEvent;
                    }
                    else
                        PostEventTimer -= Diff;
                }
                //...we are doing regular speech check
                else if (HasFollowState(STATE_FOLLOW_INPROGRESS))
                {
                    if (CheckSpeechTimer <= Diff)
                    {
                        CheckSpeechTimer = 5000;

                        if (urand(0, 9) > 8)
                            Talk(SAY_TOOG_WORRIED);
                    }
                    else
                        CheckSpeechTimer -= Diff;
                }

                return;
            }

            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_tanaris()
{
    new npc_custodian_of_time();
    new npc_OOX17();
}
