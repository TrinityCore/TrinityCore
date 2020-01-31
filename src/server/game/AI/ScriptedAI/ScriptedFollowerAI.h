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

#ifndef SC_FOLLOWERAI_H
#define SC_FOLLOWERAI_H

#include "ScriptedCreature.h"
#include "ScriptSystem.h"
#include "World.h"

class Quest;

enum FollowerState : uint32
{
    STATE_FOLLOW_NONE       = 0x000,
    STATE_FOLLOW_INPROGRESS = 0x001, // must always have this state for any follow
    STATE_FOLLOW_PAUSED     = 0x002, // disables following
    STATE_FOLLOW_COMPLETE   = 0x004, // follow is completed and may end
    STATE_FOLLOW_PREEVENT   = 0x008, // not implemented (allow pre event to run, before follow is initiated)
    STATE_FOLLOW_POSTEVENT  = 0x010  // can be set at complete and allow post event to run
};

class TC_GAME_API FollowerAI : public ScriptedAI
{
    public:
        explicit FollowerAI(Creature* creature);
        ~FollowerAI() { }

        void MoveInLineOfSight(Unit*) override;
        void JustDied(Unit*) override;
        void JustReachedHome() override;
        void OwnerAttackedBy(Unit* other) override;

        //the "internal" update, calls UpdateFollowerAI()
        void UpdateAI(uint32) override;

        //used when it's needed to add code in update (abilities, scripted events, etc)
        virtual void UpdateFollowerAI(uint32);

        void StartFollow(Player* player, uint32 factionForFollower = 0, uint32 quest = 0);

        //if special event require follow mode to hold/resume during the follow
        void SetFollowPaused(bool paused);
        void SetFollowComplete(bool withEndEvent = false);

        bool IsEscorted() const override { return HasFollowState(STATE_FOLLOW_INPROGRESS); }
        bool HasFollowState(uint32 followState) const { return (_followState & followState) != 0; }

    protected:
        Player* GetLeaderForFollower();

    private:
        void AddFollowState(uint32 followState) { _followState |= followState; }
        void RemoveFollowState(uint32 followState) { _followState &= ~followState; }
        bool ShouldAssistPlayerInCombatAgainst(Unit* who) const;

        ObjectGuid _leaderGUID;
        uint32 _updateFollowTimer;
        uint32 _followState;
        uint32 _questForFollow;
};

#endif
