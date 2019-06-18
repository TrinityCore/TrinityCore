/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

#include "SmartAI.h"
#include "DB2Structure.h"
#include "Creature.h"
#include "GameObject.h"
#include "Group.h"
#include "Log.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "PetDefines.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "WaypointMovementGenerator.h"

SmartAI::SmartAI(Creature* c) : CreatureAI(c)
{
    mIsCharmed = false;
    // copy script to local (protection for table reload)

    mEscortState = SMART_ESCORT_NONE;
    mCurrentWPID = 0;//first wp id is 1 !!
    mWPReached = false;
    mWPPauseTimer = 0;
    mOOCReached = false;
    mEscortNPCFlags = 0;

    mCanRepeatPath = false;

    // Spawn in run mode
    mRun = true;
    m_Ended = false;
    mEvadeDisabled = false;

    mCanAutoAttack = true;
    mCanCombatMove = true;

    mForcedPaused = false;

    mEscortQuestID = 0;

    mDespawnTime = 0;
    mDespawnState = 0;

    mEscortInvokerCheckTimer = 1000;
    mFollowGuid.Clear();
    mFollowDist = 0;
    mFollowAngle = 0;
    mFollowCredit = 0;
    mFollowArrivedEntry = 0;
    mFollowCreditType = 0;
    mFollowArrivedTimer = 0;
    mInvincibilityHpLevel = 0;

    mJustReset = false;
}

SmartAI::~SmartAI()
{
}

bool SmartAI::IsAIControlled() const
{
    return !mIsCharmed;
}

void SmartAI::UpdateDespawn(const uint32 diff)
{
    if (mDespawnState <= 1 || mDespawnState > 3)
        return;

    if (mDespawnTime < diff)
    {
        if (mDespawnState == 2)
        {
            me->SetVisible(false);
            mDespawnTime = 5000;
            mDespawnState++;
        }
        else
            me->DespawnOrUnsummon(0, Seconds(mRespawnTime));
    } else mDespawnTime -= diff;
}

void SmartAI::StartPath(bool run, uint32 path, bool repeat, Unit* invoker)
{
    if (me->IsInCombat())// no wp movement in combat
    {
        TC_LOG_ERROR("misc", "SmartAI::StartPath: Creature entry %u wanted to start waypoint movement while in combat, ignoring.", me->GetEntry());
        return;
    }

    if (HasEscortState(SMART_ESCORT_ESCORTING))
        StopPath();

    SetRun(run);

    if (path)
        if (!LoadPath(path))
            return;

    if (_path.nodes.empty())
        return;

    mCurrentWPID = 1;
    m_Ended = false;

    // Do not use AddEscortState, removing everything from previous cycle
    mEscortState = SMART_ESCORT_ESCORTING;
    mCanRepeatPath = repeat;

    if (invoker && invoker->GetTypeId() == TYPEID_PLAYER)
    {
        mEscortNPCFlags = me->m_unitData->NpcFlags[0];
        me->SetNpcFlags(UNIT_NPC_FLAG_NONE);
    }

    GetScript()->ProcessEventsFor(SMART_EVENT_WAYPOINT_START, nullptr, mCurrentWPID, GetScript()->GetPathId());

    me->GetMotionMaster()->MovePath(_path, mCanRepeatPath);
}

bool SmartAI::LoadPath(uint32 entry)
{
    if (HasEscortState(SMART_ESCORT_ESCORTING))
        return false;

    WPPath const* path = sSmartWaypointMgr->GetPath(entry);
    if (!path || path->empty())
    {
        GetScript()->SetPathId(0);
        return false;
    }

    for (WayPoint const &waypoint : *path)
    {
        float x = waypoint.x;
        float y = waypoint.y;
        float z = waypoint.z;

        Trinity::NormalizeMapCoord(x);
        Trinity::NormalizeMapCoord(y);

        WaypointNode wp;
        wp.id = waypoint.id;
        wp.x = x;
        wp.y = y;
        wp.z = z;
        wp.orientation = 0.f;
        wp.moveType = mRun ? WAYPOINT_MOVE_TYPE_RUN : WAYPOINT_MOVE_TYPE_WALK;
        wp.delay = 0;
        wp.eventId = 0;
        wp.eventChance = 100;

        _path.nodes.push_back(std::move(wp));
    }

    GetScript()->SetPathId(entry);
    return true;
}

void SmartAI::PausePath(uint32 delay, bool forced)
{
    if (!HasEscortState(SMART_ESCORT_ESCORTING))
        return;

    if (HasEscortState(SMART_ESCORT_PAUSED))
    {
        TC_LOG_ERROR("misc", "SmartAI::PausePath: Creature entry %u wanted to pause waypoint (current waypoint: %u) movement while already paused, ignoring.", me->GetEntry(), mCurrentWPID);
        return;
    }

    AddEscortState(SMART_ESCORT_PAUSED);
    mWPPauseTimer = delay;
    if (forced && !mWPReached)
    {
        mForcedPaused = forced;
        SetRun(mRun);
        me->StopMoving();
    }
    GetScript()->ProcessEventsFor(SMART_EVENT_WAYPOINT_PAUSED, nullptr, mCurrentWPID, GetScript()->GetPathId());
}

void SmartAI::StopPath(uint32 DespawnTime, uint32 quest, bool fail)
{
    if (!HasEscortState(SMART_ESCORT_ESCORTING))
        return;

    if (quest)
        mEscortQuestID = quest;

    if (mDespawnState != 2)
        SetDespawnTime(DespawnTime);

    me->StopMoving();
    me->GetMotionMaster()->MovementExpired(false);
    me->GetMotionMaster()->MoveIdle();
    GetScript()->ProcessEventsFor(SMART_EVENT_WAYPOINT_STOPPED, nullptr, mCurrentWPID, GetScript()->GetPathId());
    EndPath(fail);
}

void SmartAI::EndPath(bool fail)
{
    RemoveEscortState(SMART_ESCORT_ESCORTING | SMART_ESCORT_PAUSED | SMART_ESCORT_RETURNING);
    _path.nodes.clear();
    mWPPauseTimer = 0;

    if (mEscortNPCFlags)
    {
        me->SetNpcFlags(NPCFlags(mEscortNPCFlags));
        mEscortNPCFlags = 0;
    }

    ObjectList* targets = GetScript()->GetTargetList(SMART_ESCORT_TARGETS);
    if (targets && mEscortQuestID)
    {
        if (targets->size() == 1 && GetScript()->IsPlayer((*targets->begin())))
        {
            Player* player = (*targets->begin())->ToPlayer();
            if (!fail && player->IsAtGroupRewardDistance(me) && !player->HasCorpse())
                player->GroupEventHappens(mEscortQuestID, me);

            if (fail)
                player->FailQuest(mEscortQuestID);

            if (Group* group = player->GetGroup())
            {
                for (GroupReference* groupRef = group->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
                {
                    Player* groupGuy = groupRef->GetSource();

                    if (!fail && groupGuy->IsAtGroupRewardDistance(me) && !groupGuy->HasCorpse())
                        groupGuy->AreaExploredOrEventHappens(mEscortQuestID);
                    else if (fail)
                        groupGuy->FailQuest(mEscortQuestID);
                }
            }
        }
        else
        {
            for (ObjectList::iterator iter = targets->begin(); iter != targets->end(); ++iter)
            {
                if (GetScript()->IsPlayer((*iter)))
                {
                    Player* player = (*iter)->ToPlayer();
                    if (!fail && player->IsAtGroupRewardDistance(me) && !player->HasCorpse())
                        player->AreaExploredOrEventHappens(mEscortQuestID);
                    else if (fail)
                        player->FailQuest(mEscortQuestID);
                }
            }
        }
    }

    // End Path events should be only processed if it was SUCCESSFUL stop or stop called by SMART_ACTION_WAYPOINT_STOP
    if (fail)
        return;

    GetScript()->ProcessEventsFor(SMART_EVENT_WAYPOINT_ENDED, nullptr, mCurrentWPID, GetScript()->GetPathId());

    if (mCanRepeatPath)
    {
        if (IsAIControlled())
            StartPath(mRun, GetScript()->GetPathId(), mCanRepeatPath);
    }
    else
        GetScript()->SetPathId(0);

    if (mDespawnState == 1)
        StartDespawn();
}

void SmartAI::ResumePath()
{
    GetScript()->ProcessEventsFor(SMART_EVENT_WAYPOINT_RESUMED, NULL, mCurrentWPID, GetScript()->GetPathId());
    RemoveEscortState(SMART_ESCORT_PAUSED);
    mForcedPaused = false;
    mWPReached = false;
    mWPPauseTimer = 0;
    SetRun(mRun);

    if (WaypointMovementGenerator<Creature>* move = dynamic_cast<WaypointMovementGenerator<Creature>*>(me->GetMotionMaster()->top()))
        move->GetTrackerTimer().Reset(1);
}

void SmartAI::ReturnToLastOOCPos()
{
    if (!IsAIControlled())
        return;

    me->SetWalk(false);
    float x, y, z, o;
    me->GetHomePosition(x, y, z, o);
    me->GetMotionMaster()->MovePoint(SMART_ESCORT_LAST_OOC_POINT, x, y, z);
}

void SmartAI::UpdatePath(const uint32 diff)
{
    if (!HasEscortState(SMART_ESCORT_ESCORTING))
        return;

    if (mEscortInvokerCheckTimer < diff)
    {
        if (!IsEscortInvokerInRange())
        {
            StopPath(0, mEscortQuestID, true);

            // allow to properly hook out of range despawn action, which in most cases should perform the same operation as dying
            GetScript()->ProcessEventsFor(SMART_EVENT_DEATH, me);
            me->DespawnOrUnsummon(1);
            return;
        }
        mEscortInvokerCheckTimer = 1000;
    }
    else
        mEscortInvokerCheckTimer -= diff;

    // handle pause
    if (HasEscortState(SMART_ESCORT_PAUSED))
    {
        if (mWPPauseTimer <= diff)
        {
            if (!me->IsInCombat() && !HasEscortState(SMART_ESCORT_RETURNING) && (mWPReached || mForcedPaused))
            {
                ResumePath();
            }
        }
        else
            mWPPauseTimer -= diff;
    }
    else if (m_Ended) // end path
    {
        m_Ended = false;
        StopPath();
        return;
    }

    if (HasEscortState(SMART_ESCORT_RETURNING))
    {
        if (mOOCReached)//reached OOC WP
        {
            mOOCReached = false;
            RemoveEscortState(SMART_ESCORT_RETURNING);
            if (!HasEscortState(SMART_ESCORT_PAUSED))
                ResumePath();
        }
    }
}

void SmartAI::UpdateAI(uint32 diff)
{
    GetScript()->OnUpdate(diff);
    UpdatePath(diff);
    UpdateDespawn(diff);

    /// @todo move to void
    if (!mFollowGuid.IsEmpty())
    {
        if (mFollowArrivedTimer < diff)
        {
            if (me->FindNearestCreature(mFollowArrivedEntry, INTERACTION_DISTANCE, true))
            {
                StopFollow();
                return;
            }

            mFollowArrivedTimer = 1000;
        }
        else
            mFollowArrivedTimer -= diff;
    }

    if (!IsAIControlled())
        return;

    if (!UpdateVictim())
        return;

    if (mCanAutoAttack)
        DoMeleeAttackIfReady();
}

bool SmartAI::IsEscortInvokerInRange()
{
    ObjectList* targets = GetScript()->GetTargetList(SMART_ESCORT_TARGETS);
    if (targets)
    {
        if (targets->size() == 1 && GetScript()->IsPlayer((*targets->begin())))
        {
            Player* player = (*targets->begin())->ToPlayer();
            if (me->GetDistance(player) <= SMART_ESCORT_MAX_PLAYER_DIST)
                        return true;

            if (Group* group = player->GetGroup())
            {
                for (GroupReference* groupRef = group->GetFirstMember(); groupRef != nullptr; groupRef = groupRef->next())
                {
                    Player* groupGuy = groupRef->GetSource();

                    if (me->GetDistance(groupGuy) <= SMART_ESCORT_MAX_PLAYER_DIST)
                        return true;
                }
            }
        }
        else
        {
            for (ObjectList::iterator iter = targets->begin(); iter != targets->end(); ++iter)
            {
                if (GetScript()->IsPlayer((*iter)))
                {
                    if (me->GetDistance((*iter)->ToPlayer()) <= SMART_ESCORT_MAX_PLAYER_DIST)
                        return true;
                }
            }
        }
    }
    return true;//escort targets were not set, ignore range check
}

void SmartAI::MovepointReached(uint32 id)
{
    // override the id, path can be resumed any time and counter will reset
    // mCurrentWPID holds proper id

    // both point movement and escort generator can enter this function
    if (id == SMART_ESCORT_LAST_OOC_POINT)
    {
        mOOCReached = true;
        return;
    }

    mCurrentWPID = id + 1; // in SmartAI increase by 1

    mWPReached = true;
    GetScript()->ProcessEventsFor(SMART_EVENT_WAYPOINT_REACHED, nullptr, mCurrentWPID, GetScript()->GetPathId());

    if (HasEscortState(SMART_ESCORT_PAUSED))
        me->StopMoving();
    else if (HasEscortState(SMART_ESCORT_ESCORTING) && me->GetMotionMaster()->GetCurrentMovementGeneratorType() == WAYPOINT_MOTION_TYPE)
    {
        mWPReached = false;
        if (mCurrentWPID == _path.nodes.size())
            m_Ended = true;
        else
            SetRun(mRun);
    }
}

void SmartAI::MovementInform(uint32 MovementType, uint32 Data)
{
    if (MovementType == POINT_MOTION_TYPE && Data == SMART_ESCORT_LAST_OOC_POINT)
        me->ClearUnitState(UNIT_STATE_EVADE);

    GetScript()->ProcessEventsFor(SMART_EVENT_MOVEMENTINFORM, nullptr, MovementType, Data);
    if (!HasEscortState(SMART_ESCORT_ESCORTING))
        return;

    if (MovementType == WAYPOINT_MOTION_TYPE || (MovementType == POINT_MOTION_TYPE && Data == SMART_ESCORT_LAST_OOC_POINT))
        MovepointReached(Data);
}

void SmartAI::EnterEvadeMode(EvadeReason /*why*/)
{
    if (mEvadeDisabled)
    {
        GetScript()->ProcessEventsFor(SMART_EVENT_EVADE);
        return;
    }

    if (!_EnterEvadeMode())
        return;
    me->AddUnitState(UNIT_STATE_EVADE);

    GetScript()->ProcessEventsFor(SMART_EVENT_EVADE);//must be after aura clear so we can cast spells from db

    SetRun(mRun);
    if (HasEscortState(SMART_ESCORT_ESCORTING))
    {
        AddEscortState(SMART_ESCORT_RETURNING);
        ReturnToLastOOCPos();
    }
    else if (Unit* target = !mFollowGuid.IsEmpty() ? ObjectAccessor::GetUnit(*me, mFollowGuid) : nullptr)
    {
        me->GetMotionMaster()->MoveFollow(target, mFollowDist, mFollowAngle);
        // evade is not cleared in MoveFollow, so we can't keep it
        me->ClearUnitState(UNIT_STATE_EVADE);
        GetScript()->OnReset();
    }
    else if (Unit* owner = me->GetCharmerOrOwner())
    {
        me->GetMotionMaster()->MoveFollow(owner, PET_FOLLOW_DIST, PET_FOLLOW_ANGLE);
        me->ClearUnitState(UNIT_STATE_EVADE);
    }
    else
        me->GetMotionMaster()->MoveTargetedHome();

    if (!me->HasUnitState(UNIT_STATE_EVADE))
        GetScript()->OnReset();
}

void SmartAI::MoveInLineOfSight(Unit* who)
{
    if (!who)
        return;

    GetScript()->OnMoveInLineOfSight(who);

    if (!IsAIControlled())
        return;

    if (AssistPlayerInCombatAgainst(who))
        return;

    CreatureAI::MoveInLineOfSight(who);
}

bool SmartAI::CanAIAttack(const Unit* /*who*/) const
{
    return !(me->HasReactState(REACT_PASSIVE));
}

bool SmartAI::AssistPlayerInCombatAgainst(Unit* who)
{
    if (me->HasReactState(REACT_PASSIVE) || !IsAIControlled())
        return false;

    if (!who || !who->GetVictim())
        return false;

    //experimental (unknown) flag not present
    if (!(me->GetCreatureTemplate()->type_flags & CREATURE_TYPE_FLAG_CAN_ASSIST))
        return false;

    //not a player
    if (!who->EnsureVictim()->GetCharmerOrOwnerPlayerOrPlayerItself())
        return false;

    //never attack friendly
    if (me->IsFriendlyTo(who))
        return false;

    //too far away and no free sight?
    if (me->IsWithinDistInMap(who, SMART_MAX_AID_DIST) && me->IsWithinLOSInMap(who))
    {
        //already fighting someone?
        if (!me->GetVictim())
        {
            AttackStart(who);
            return true;
        }
        else
        {
            who->SetInCombatWith(me);
            me->AddThreat(who, 0.0f);
            return true;
        }
    }

    return false;
}

void SmartAI::JustRespawned()
{
    mDespawnTime = 0;
    mRespawnTime = 0;
    mDespawnState = 0;
    mEscortState = SMART_ESCORT_NONE;
    me->SetVisible(true);
    if (me->getFaction() != me->GetCreatureTemplate()->faction)
        me->RestoreFaction();
    mJustReset = true;
    JustReachedHome();
    GetScript()->ProcessEventsFor(SMART_EVENT_RESPAWN);
    mFollowGuid.Clear();//do not reset follower on Reset(), we need it after combat evade
    mFollowDist = 0;
    mFollowAngle = 0;
    mFollowCredit = 0;
    mFollowArrivedTimer = 1000;
    mFollowArrivedEntry = 0;
    mFollowCreditType = 0;
}

int SmartAI::Permissible(const Creature* creature)
{
    if (creature->GetAIName() == "SmartAI")
        return PERMIT_BASE_SPECIAL;
    return PERMIT_BASE_NO;
}

void SmartAI::JustReachedHome()
{
    GetScript()->OnReset();

    if (!mJustReset)
    {
        GetScript()->ProcessEventsFor(SMART_EVENT_REACHED_HOME);

        if (!UpdateVictim() && me->GetMotionMaster()->GetCurrentMovementGeneratorType() == IDLE_MOTION_TYPE && me->GetWaypointPath())
            me->GetMotionMaster()->MovePath(me->GetWaypointPath(), true);
    }

    mJustReset = false;
}

void SmartAI::EnterCombat(Unit* enemy)
{
    if (IsAIControlled())
        me->InterruptNonMeleeSpells(false); // must be before ProcessEvents

    GetScript()->ProcessEventsFor(SMART_EVENT_AGGRO, enemy);
}

void SmartAI::JustDied(Unit* killer)
{
    GetScript()->ProcessEventsFor(SMART_EVENT_DEATH, killer);
    if (HasEscortState(SMART_ESCORT_ESCORTING))
        EndPath(true);
}

void SmartAI::KilledUnit(Unit* victim)
{
    GetScript()->ProcessEventsFor(SMART_EVENT_KILL, victim);
}

void SmartAI::JustSummoned(Creature* creature)
{
    GetScript()->ProcessEventsFor(SMART_EVENT_SUMMONED_UNIT, creature);
}

void SmartAI::AttackStart(Unit* who)
{
    // dont allow charmed npcs to act on their own
    if (me->HasUnitFlag(UNIT_FLAG_PLAYER_CONTROLLED))
    {
        if (who && mCanAutoAttack)
            me->Attack(who, true);
        return;
    }

    if (who && me->Attack(who, me->IsWithinMeleeRange(who)))
    {
        if (mCanCombatMove)
        {
            SetRun(mRun);

            MovementGeneratorType type = me->GetMotionMaster()->GetMotionSlotType(MOTION_SLOT_ACTIVE);
            if (type == WAYPOINT_MOTION_TYPE || type == POINT_MOTION_TYPE)
                me->StopMoving();

            me->GetMotionMaster()->MoveChase(who);
        }
    }
}

void SmartAI::SpellHit(Unit* unit, const SpellInfo* spellInfo)
{
    GetScript()->ProcessEventsFor(SMART_EVENT_SPELLHIT, unit, 0, 0, false, spellInfo);
}

void SmartAI::SpellHitTarget(Unit* target, const SpellInfo* spellInfo)
{
    GetScript()->ProcessEventsFor(SMART_EVENT_SPELLHIT_TARGET, target, 0, 0, false, spellInfo);
}

void SmartAI::DamageTaken(Unit* doneBy, uint32& damage)
{
    GetScript()->ProcessEventsFor(SMART_EVENT_DAMAGED, doneBy, damage);

    if (!IsAIControlled()) // don't allow players to use unkillable units
        return;

    if (mInvincibilityHpLevel && (damage >= me->GetHealth() - mInvincibilityHpLevel))
        damage = me->GetHealth() - mInvincibilityHpLevel; // damage should not be nullified, because of player damage req.
}

void SmartAI::HealReceived(Unit* doneBy, uint32& addhealth)
{
    GetScript()->ProcessEventsFor(SMART_EVENT_RECEIVE_HEAL, doneBy, addhealth);
}

void SmartAI::ReceiveEmote(Player* player, uint32 textEmote)
{
    GetScript()->ProcessEventsFor(SMART_EVENT_RECEIVE_EMOTE, player, textEmote);
}

void SmartAI::IsSummonedBy(Unit* summoner)
{
    GetScript()->ProcessEventsFor(SMART_EVENT_JUST_SUMMONED, summoner);
}

void SmartAI::DamageDealt(Unit* doneTo, uint32& damage, DamageEffectType /*damagetype*/)
{
    GetScript()->ProcessEventsFor(SMART_EVENT_DAMAGED_TARGET, doneTo, damage);
}

void SmartAI::SummonedCreatureDespawn(Creature* unit)
{
    GetScript()->ProcessEventsFor(SMART_EVENT_SUMMON_DESPAWNED, unit);
}

void SmartAI::CorpseRemoved(uint32& respawnDelay)
{
    GetScript()->ProcessEventsFor(SMART_EVENT_CORPSE_REMOVED, nullptr, respawnDelay);
}

void SmartAI::PassengerBoarded(Unit* who, int8 seatId, bool apply)
{
    GetScript()->ProcessEventsFor(apply ? SMART_EVENT_PASSENGER_BOARDED : SMART_EVENT_PASSENGER_REMOVED, who, uint32(seatId), 0, apply);
}

void SmartAI::InitializeAI()
{
    GetScript()->OnInitialize(me);
    if (!me->isDead())
    mJustReset = true;
    JustReachedHome();
    GetScript()->ProcessEventsFor(SMART_EVENT_RESPAWN);
}

void SmartAI::OnCharmed(bool apply)
{
    if (apply) // do this before we change charmed state, as charmed state might prevent these things from processing
    {
        if (HasEscortState(SMART_ESCORT_ESCORTING | SMART_ESCORT_PAUSED | SMART_ESCORT_RETURNING))
            EndPath(true);
        me->StopMoving();
    }
    mIsCharmed = apply;

    if (!apply && !me->IsInEvadeMode())
    {
        if (mCanRepeatPath)
            StartPath(mRun, GetScript()->GetPathId(), true);
        else
            me->SetWalk(!mRun);

        if (Unit* charmer = me->GetCharmer())
            AttackStart(charmer);
    }

    GetScript()->ProcessEventsFor(SMART_EVENT_CHARMED, nullptr, 0, 0, apply);
}

void SmartAI::DoAction(int32 param)
{
    GetScript()->ProcessEventsFor(SMART_EVENT_ACTION_DONE, nullptr, param);
}

uint32 SmartAI::GetData(uint32 /*id*/) const
{
    return 0;
}

void SmartAI::SetData(uint32 id, uint32 value)
{
    GetScript()->ProcessEventsFor(SMART_EVENT_DATA_SET, nullptr, id, value);
}

void SmartAI::SetGUID(ObjectGuid /*guid*/, int32 /*id*/) { }

ObjectGuid SmartAI::GetGUID(int32 /*id*/) const
{
    return ObjectGuid::Empty;
}

void SmartAI::SetRun(bool run)
{
    me->SetWalk(!run);
    mRun = run;
}

void SmartAI::SetFly(bool fly)
{
    me->SetDisableGravity(fly);
}

void SmartAI::SetSwim(bool swim)
{
    me->SetSwim(swim);
}

void SmartAI::SetEvadeDisabled(bool disable)
{
    mEvadeDisabled = disable;
}

void SmartAI::sGossipHello(Player* player)
{
    GetScript()->ProcessEventsFor(SMART_EVENT_GOSSIP_HELLO, player);
}

void SmartAI::sGossipSelect(Player* player, uint32 menuId, uint32 gossipListId)
{
    GetScript()->ProcessEventsFor(SMART_EVENT_GOSSIP_SELECT, player, menuId, gossipListId);
}

void SmartAI::sGossipSelectCode(Player* /*player*/, uint32 /*menuId*/, uint32 /*gossipListId*/, const char* /*code*/) { }

void SmartAI::sQuestAccept(Player* player, Quest const* quest)
{
    GetScript()->ProcessEventsFor(SMART_EVENT_ACCEPTED_QUEST, player, quest->GetQuestId());
}

void SmartAI::sQuestReward(Player* player, Quest const* quest, uint32 opt)
{
    GetScript()->ProcessEventsFor(SMART_EVENT_REWARD_QUEST, player, quest->GetQuestId(), opt);
}

bool SmartAI::sOnDummyEffect(Unit* caster, uint32 spellId, SpellEffIndex effIndex)
{
    GetScript()->ProcessEventsFor(SMART_EVENT_DUMMY_EFFECT, caster, spellId, (uint32)effIndex);
    return true;
}

void SmartAI::SetCombatMove(bool on)
{
    if (mCanCombatMove == on)
        return;

    mCanCombatMove = on;
    if (!IsAIControlled())
        return;
    if (!HasEscortState(SMART_ESCORT_ESCORTING))
    {
        if (on && me->GetVictim())
        {
            if (me->GetMotionMaster()->GetCurrentMovementGeneratorType() == IDLE_MOTION_TYPE)
            {
                SetRun(mRun);
                me->GetMotionMaster()->MoveChase(me->GetVictim());
                me->CastStop();
            }
        }
        else
        {
            me->StopMoving();
            if (me->GetMotionMaster()->GetCurrentMovementGeneratorType() == CHASE_MOTION_TYPE)
                me->GetMotionMaster()->Clear(false);
            me->GetMotionMaster()->MoveIdle();
        }
    }
}

void SmartAI::SetFollow(Unit* target, float dist, float angle, uint32 credit, uint32 end, uint32 creditType)
{
    if (!target)
    {
        StopFollow();
        return;
    }

    mFollowGuid = target->GetGUID();
    mFollowDist = dist >= 0.0f ? dist : PET_FOLLOW_DIST;
    mFollowAngle = angle >= 0.0f ? angle : me->GetFollowAngle();
    mFollowArrivedTimer = 1000;
    mFollowCredit = credit;
    mFollowArrivedEntry = end;
    mFollowCreditType = creditType;
    SetRun(mRun);
    me->GetMotionMaster()->MoveFollow(target, mFollowDist, mFollowAngle);
}

void SmartAI::StopFollow()
{
    if (Player* player = ObjectAccessor::GetPlayer(*me, mFollowGuid))
    {
        if (!mFollowCreditType)
            player->RewardPlayerAndGroupAtEvent(mFollowCredit, me);
        else
            player->GroupEventHappens(mFollowCredit, me);
    }

    mFollowGuid.Clear();
    mFollowDist = 0;
    mFollowAngle = 0;
    mFollowCredit = 0;
    mFollowArrivedTimer = 1000;
    mFollowArrivedEntry = 0;
    mFollowCreditType = 0;
    SetDespawnTime(5000);
    me->StopMoving();
    me->GetMotionMaster()->MoveIdle();
    StartDespawn();
    GetScript()->ProcessEventsFor(SMART_EVENT_FOLLOW_COMPLETED);
}
void SmartAI::SetScript9(SmartScriptHolder& e, uint32 entry, Unit* invoker)
{
    if (invoker)
        GetScript()->mLastInvoker = invoker->GetGUID();
    GetScript()->SetScript9(e, entry);
}

void SmartAI::sOnGameEvent(bool start, uint16 eventId)
{
    GetScript()->ProcessEventsFor(start ? SMART_EVENT_GAME_EVENT_START : SMART_EVENT_GAME_EVENT_END, nullptr, eventId);
}

void SmartAI::OnSpellClick(Unit* clicker, bool& result)
{
    if (!result)
        return;

    GetScript()->ProcessEventsFor(SMART_EVENT_ON_SPELLCLICK, clicker);
}

int SmartGameObjectAI::Permissible(const GameObject* g)
{
    if (g->GetAIName() == "SmartGameObjectAI")
        return PERMIT_BASE_SPECIAL;
    return PERMIT_BASE_NO;
}

void SmartGameObjectAI::UpdateAI(uint32 diff)
{
    GetScript()->OnUpdate(diff);
}

void SmartGameObjectAI::InitializeAI()
{
    GetScript()->OnInitialize(go);
    GetScript()->ProcessEventsFor(SMART_EVENT_RESPAWN);
    //Reset();
}

void SmartGameObjectAI::Reset()
{
    GetScript()->OnReset();
}

// Called when a player opens a gossip dialog with the gameobject.
bool SmartGameObjectAI::GossipHello(Player* player, bool /*isUse*/)
{
    TC_LOG_DEBUG("scripts.ai", "SmartGameObjectAI::GossipHello");
    GetScript()->ProcessEventsFor(SMART_EVENT_GOSSIP_HELLO, player, 0, 0, false, nullptr, go);
    return false;
}

// Called when a player selects a gossip item in the gameobject's gossip menu.
bool SmartGameObjectAI::GossipSelect(Player* player, uint32 sender, uint32 action)
{
    GetScript()->ProcessEventsFor(SMART_EVENT_GOSSIP_SELECT, player, sender, action, false, nullptr, go);
    return false;
}

// Called when a player selects a gossip with a code in the gameobject's gossip menu.
bool SmartGameObjectAI::GossipSelectCode(Player* /*player*/, uint32 /*sender*/, uint32 /*action*/, const char* /*code*/)
{
    return false;
}

// Called when a player accepts a quest from the gameobject.
bool SmartGameObjectAI::QuestAccept(Player* player, Quest const* quest)
{
    GetScript()->ProcessEventsFor(SMART_EVENT_ACCEPTED_QUEST, player, quest->GetQuestId(), 0, false, nullptr, go);
    return false;
}

// Called when a player selects a quest reward.
bool SmartGameObjectAI::QuestReward(Player* player, Quest const* quest, uint32 opt)
{
    GetScript()->ProcessEventsFor(SMART_EVENT_REWARD_QUEST, player, quest->GetQuestId(), opt, false, nullptr, go);
    return false;
}

// Called when the gameobject is destroyed (destructible buildings only).
void SmartGameObjectAI::Destroyed(Player* player, uint32 eventId)
{
    GetScript()->ProcessEventsFor(SMART_EVENT_DEATH, player, eventId, 0, false, nullptr, go);
}

void SmartGameObjectAI::SetData(uint32 id, uint32 value)
{
    GetScript()->ProcessEventsFor(SMART_EVENT_DATA_SET, nullptr, id, value);
}

void SmartGameObjectAI::SetScript9(SmartScriptHolder& e, uint32 entry, Unit* invoker)
{
    if (invoker)
        GetScript()->mLastInvoker = invoker->GetGUID();
    GetScript()->SetScript9(e, entry);
}

void SmartGameObjectAI::OnGameEvent(bool start, uint16 eventId)
{
    GetScript()->ProcessEventsFor(start ? SMART_EVENT_GAME_EVENT_START : SMART_EVENT_GAME_EVENT_END, nullptr, eventId);
}

void SmartGameObjectAI::OnStateChanged(uint32 state, Unit* unit)
{
    GetScript()->ProcessEventsFor(SMART_EVENT_GO_STATE_CHANGED, unit, state);
}

void SmartGameObjectAI::EventInform(uint32 eventId)
{
    GetScript()->ProcessEventsFor(SMART_EVENT_GO_EVENT_INFORM, nullptr, eventId);
}

class SmartTrigger : public AreaTriggerScript
{
    public:

        SmartTrigger() : AreaTriggerScript("SmartTrigger") { }

        bool OnTrigger(Player* player, AreaTriggerEntry const* trigger, bool /*entered*/) override
        {
            if (!player->IsAlive())
                return false;

            TC_LOG_DEBUG("scripts.ai", "AreaTrigger %u is using SmartTrigger script", trigger->ID);
            SmartScript script;
            script.OnInitialize(nullptr, trigger);
            script.ProcessEventsFor(SMART_EVENT_AREATRIGGER_ONTRIGGER, player, trigger->ID);
            return true;
        }
};

class SmartScene : public SceneScript
{
public:
    SmartScene() : SceneScript("SmartScene") { }

    void OnSceneStart(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* sceneTemplate) override
    {
        SmartScript smartScript;
        smartScript.OnInitialize(nullptr, nullptr, sceneTemplate);
        smartScript.ProcessEventsFor(SMART_EVENT_SCENE_START, player);
    }

    void OnSceneTriggerEvent(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* sceneTemplate, std::string const& triggerName) override
    {
        SmartScript smartScript;
        smartScript.OnInitialize(nullptr, nullptr, sceneTemplate);
        smartScript.ProcessEventsFor(SMART_EVENT_SCENE_TRIGGER, player, 0, 0, false, nullptr, nullptr, triggerName);
    }

    void OnSceneCancel(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* sceneTemplate) override
    {
        SmartScript smartScript;
        smartScript.OnInitialize(nullptr, nullptr, sceneTemplate);
        smartScript.ProcessEventsFor(SMART_EVENT_SCENE_CANCEL, player);
    }

    void OnSceneComplete(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* sceneTemplate) override
    {
        SmartScript smartScript;
        smartScript.OnInitialize(nullptr, nullptr, sceneTemplate);
        smartScript.ProcessEventsFor(SMART_EVENT_SCENE_COMPLETE, player);
    }
};

void AddSC_SmartScripts()
{
    new SmartTrigger();
    new SmartScene();
}
