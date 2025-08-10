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

/* ScriptData
SDName: Tanaris
SD%Complete: 80
SDComment: Quest support:
SDCategory: Tanaris
EndScriptData */

/* ContentData
EndContentData */

#include "ScriptMgr.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedFollowerAI.h"

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

    POINT_ID_TO_WATER           = 1
};

Position const ToWaterLoc = {-7032.664551f, -4906.199219f, -1.606446f, 0.0f};

class npc_tooga : public CreatureScript
{
public:
    npc_tooga() : CreatureScript("npc_tooga") { }

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
                    if (player)
                        player->GroupEventHappens(QUEST_TOOGA, me);

                    TortaGUID = who->GetGUID();
                    SetFollowComplete(true);
                }
            }
        }

        void MovementInform(uint32 MotionType, uint32 PointId) override
        {
            FollowerAI::MovementInform(MotionType, PointId);

            if ((MotionType == POINT_MOTION_TYPE) && (PointId == POINT_ID_TO_WATER))
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
        }

        void OnQuestAccept(Player* player, Quest const* quest) override
        {
            if (quest->GetQuestId() == QUEST_TOOGA)
                StartFollow(player, FACTION_ESCORTEE_N_NEUTRAL_PASSIVE, QUEST_TOOGA);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_toogaAI(creature);
    }
};

void AddSC_tanaris()
{
}
