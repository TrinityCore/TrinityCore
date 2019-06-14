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

#include "ScriptedFollowerAI.h"
#include "Creature.h"
#include "Group.h"
#include "Log.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"

float constexpr MAX_PLAYER_DISTANCE = 100.0f;

enum Points
{
    POINT_COMBAT_START = 0xFFFFFF
};

FollowerAI::FollowerAI(Creature* creature) : ScriptedAI(creature), _updateFollowTimer(2500), _followState(STATE_FOLLOW_NONE), _questForFollow(nullptr) { }

void FollowerAI::MovementInform(uint32 type, uint32 id)
{
    if (type != POINT_MOTION_TYPE || !HasFollowState(STATE_FOLLOW_INPROGRESS))
        return;

    if (id == POINT_COMBAT_START)
    {
        if (GetLeaderForFollower())
        {
            if (!HasFollowState(STATE_FOLLOW_PAUSED))
                AddFollowState(STATE_FOLLOW_RETURNING);
        }
        else
            me->DespawnOrUnsummon();
    }
}

void FollowerAI::AttackStart(Unit* who)
{
    ScriptedAI::AttackStart(who);
}

void FollowerAI::MoveInLineOfSight(Unit* who)
{
    // TODO: what in the world is this?
    if (me->HasReactState(REACT_AGGRESSIVE) && !me->HasUnitState(UNIT_STATE_STUNNED) && who->isTargetableForAttack() && who->isInAccessiblePlaceFor(me))
        return;

    if (HasFollowState(STATE_FOLLOW_INPROGRESS) && AssistPlayerInCombatAgainst(who))
        return;

    ScriptedAI::MoveInLineOfSight(who);
}

void FollowerAI::JustDied(Unit* /*killer*/)
{
    if (!HasFollowState(STATE_FOLLOW_INPROGRESS) || !_leaderGUID || !_questForFollow)
        return;

    /// @todo need a better check for quests with time limit.
    if (Player* player = GetLeaderForFollower())
    {
        if (Group* group = player->GetGroup())
        {
            for (GroupReference* groupRef = group->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
                if (Player* member = groupRef->GetSource())
                    if (member->IsInMap(player))
                        member->FailQuest(_questForFollow->GetQuestId());
        }
        else
            player->FailQuest(_questForFollow->GetQuestId());
    }
}

void FollowerAI::JustAppeared()
{
    _followState = STATE_FOLLOW_NONE;

    if (!IsCombatMovementAllowed())
        SetCombatMovement(true);

    if (me->GetFaction() != me->GetCreatureTemplate()->faction)
        me->SetFaction(me->GetCreatureTemplate()->faction);

    Reset();
}

void FollowerAI::EnterEvadeMode(EvadeReason /*why*/)
{
    if (!me->IsAlive())
        return;

    me->RemoveAllAuras();
    me->GetThreatManager().ClearAllThreat();
    me->CombatStop(true);
    me->SetLootRecipient(nullptr);
    me->SetCannotReachTarget(false);
    me->DoNotReacquireTarget();

    if (HasFollowState(STATE_FOLLOW_INPROGRESS))
    {
        TC_LOG_DEBUG("scripts.ai.followerai", "FollowerAI::EnterEvadeMode: left combat, returning to CombatStartPosition. (%s)", me->GetGUID().ToString().c_str());

        if (me->HasUnitState(UNIT_STATE_CHASE))
            me->GetMotionMaster()->Remove(CHASE_MOTION_TYPE);
    }
    else
        me->GetMotionMaster()->MoveTargetedHome();

    Reset();
}

void FollowerAI::UpdateAI(uint32 uiDiff)
{
    if (HasFollowState(STATE_FOLLOW_INPROGRESS) && !me->IsEngaged())
    {
        if (_updateFollowTimer <= uiDiff)
        {
            if (HasFollowState(STATE_FOLLOW_COMPLETE) && !HasFollowState(STATE_FOLLOW_POSTEVENT))
            {
                TC_LOG_DEBUG("scripts.ai.followerai", "FollowerAI::UpdateAI: is set completed, despawns. (%s)", me->GetGUID().ToString().c_str());
                me->DespawnOrUnsummon();
                return;
            }

            bool maxRangeExceeded = true;

            if (Player* player = GetLeaderForFollower())
            {
                if (HasFollowState(STATE_FOLLOW_RETURNING))
                {
                    TC_LOG_DEBUG("scripts.ai.followerai", "FollowerAI::UpdateAI: is returning to leader. (%s)", me->GetGUID().ToString().c_str());

                    RemoveFollowState(STATE_FOLLOW_RETURNING);
                    me->GetMotionMaster()->MoveFollow(player, PET_FOLLOW_DIST, PET_FOLLOW_ANGLE);
                    return;
                }

                if (Group* group = player->GetGroup())
                {
                    for (GroupReference* groupRef = group->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
                    {
                        Player* member = groupRef->GetSource();
                        if (member && me->IsWithinDistInMap(member, MAX_PLAYER_DISTANCE))
                        {
                            maxRangeExceeded = false;
                            break;
                        }
                    }
                }
                else
                {
                    if (me->IsWithinDistInMap(player, MAX_PLAYER_DISTANCE))
                        maxRangeExceeded = false;
                }
            }

            if (maxRangeExceeded)
            {
                TC_LOG_DEBUG("scripts.ai.followerai", "FollowerAI::UpdateAI: failed because player/group was to far away or not found (%s)", me->GetGUID().ToString().c_str());
                me->DespawnOrUnsummon();
                return;
            }

            _updateFollowTimer = 1000;
        }
        else
            _updateFollowTimer -= uiDiff;
    }

    UpdateFollowerAI(uiDiff);
}

void FollowerAI::UpdateFollowerAI(uint32 /*uiDiff*/)
{
    if (!UpdateVictim())
        return;

    DoMeleeAttackIfReady();
}

void FollowerAI::StartFollow(Player* player, uint32 factionForFollower, Quest const* quest)
{
    if (me->IsEngaged())
    {
        TC_LOG_DEBUG("scripts.ai.followerai", "FollowerAI::StartFollow: attempt to StartFollow while in combat. (%s)", me->GetGUID().ToString().c_str());
        return;
    }

    if (HasFollowState(STATE_FOLLOW_INPROGRESS))
    {
        TC_LOG_ERROR("scripts.ai.followerai", "FollowerAI::StartFollow: attempt to StartFollow while already following. (%s)", me->GetGUID().ToString().c_str());
        return;
    }

    // set variables
    _leaderGUID = player->GetGUID();

    if (factionForFollower)
        me->SetFaction(factionForFollower);

    _questForFollow = quest;

    me->GetMotionMaster()->Clear(MOTION_PRIORITY_NORMAL);
    me->PauseMovement();

    me->SetUInt32Value(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_NONE);

    AddFollowState(STATE_FOLLOW_INPROGRESS);

    me->GetMotionMaster()->MoveFollow(player, PET_FOLLOW_DIST, PET_FOLLOW_ANGLE);

    TC_LOG_DEBUG("scripts.ai.followerai", "FollowerAI::StartFollow: start follow %s - %s (%s)", player->GetName().c_str(), _leaderGUID.ToString().c_str(), me->GetGUID().ToString().c_str());
}

void FollowerAI::SetFollowPaused(bool paused)
{
    if (!HasFollowState(STATE_FOLLOW_INPROGRESS) || HasFollowState(STATE_FOLLOW_COMPLETE))
        return;

    if (paused)
    {
        AddFollowState(STATE_FOLLOW_PAUSED);

        if (me->HasUnitState(UNIT_STATE_FOLLOW))
            me->GetMotionMaster()->Remove(FOLLOW_MOTION_TYPE);
    }
    else
    {
        RemoveFollowState(STATE_FOLLOW_PAUSED);

        if (Player* leader = GetLeaderForFollower())
            me->GetMotionMaster()->MoveFollow(leader, PET_FOLLOW_DIST, PET_FOLLOW_ANGLE);
    }
}

void FollowerAI::SetFollowComplete(bool withEndEvent)
{
    if (me->HasUnitState(UNIT_STATE_FOLLOW))
        me->GetMotionMaster()->Remove(FOLLOW_MOTION_TYPE);

    if (withEndEvent)
        AddFollowState(STATE_FOLLOW_POSTEVENT);
    else
    {
        if (HasFollowState(STATE_FOLLOW_POSTEVENT))
            RemoveFollowState(STATE_FOLLOW_POSTEVENT);
    }

    AddFollowState(STATE_FOLLOW_COMPLETE);
}

Player* FollowerAI::GetLeaderForFollower()
{
    if (Player* player = ObjectAccessor::GetPlayer(*me, _leaderGUID))
    {
        if (player->IsAlive())
            return player;
        else
        {
            if (Group* group = player->GetGroup())
            {
                for (GroupReference* groupRef = group->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
                {
                    Player* member = groupRef->GetSource();
                    if (member && me->IsWithinDistInMap(member, MAX_PLAYER_DISTANCE) && member->IsAlive())
                    {
                        TC_LOG_DEBUG("scripts.ai.followerai", "FollowerAI::GetLeaderForFollower: GetLeader changed and returned new leader. (%s)", me->GetGUID().ToString().c_str());
                        _leaderGUID = member->GetGUID();
                        return member;
                    }
                }
            }
        }
    }

    TC_LOG_DEBUG("scripts.ai.followerai", "FollowerAI::GetLeaderForFollower: GetLeader can not find suitable leader. (%s)", me->GetGUID().ToString().c_str());
    return nullptr;
}

// This part provides assistance to a player that are attacked by who, even if out of normal aggro range
// It will cause me to attack who that are attacking _any_ player (which has been confirmed may happen also on offi)
// The flag (type_flag) is unconfirmed, but used here for further research and is a good candidate.
bool FollowerAI::AssistPlayerInCombatAgainst(Unit* who)
{
    if (!who || !who->GetVictim())
        return false;

    if (me->HasReactState(REACT_PASSIVE))
        return false;

    // experimental (unknown) flag not present
    if (!(me->GetCreatureTemplate()->type_flags & CREATURE_TYPE_FLAG_CAN_ASSIST))
        return false;

    // not a player
    if (!who->EnsureVictim()->GetCharmerOrOwnerPlayerOrPlayerItself())
        return false;

    if (!who->isInAccessiblePlaceFor(me))
        return false;

    if (!CanAIAttack(who))
        return false;

    // we cannot attack in evade mode
    if (me->IsInEvadeMode())
        return false;

    // or if enemy is in evade mode
    if (who->GetTypeId() == TYPEID_UNIT && who->ToCreature()->IsInEvadeMode())
        return false;

    // never attack friendly
    if (me->IsFriendlyTo(who))
        return false;

    // too far away and no free sight
    if (me->IsWithinDistInMap(who, MAX_PLAYER_DISTANCE) && me->IsWithinLOSInMap(who))
    {
        me->EngageWithTarget(who);
        return true;
    }

    return false;
}
