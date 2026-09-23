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

#ifndef TRINITYCORE_AI_GROUP_SCRIPT_H
#define TRINITYCORE_AI_GROUP_SCRIPT_H

#include "AIGroupMgr.h"
#include "Creature.h"
#include "Object.h"

class Creature;

class TC_GAME_API AIGroupScript
{
    public:
        AIGroupScript();
        ~AIGroupScript();

        void OnInitialize(WorldObject* object);
        void GetScript();
        void FillScript(AIGroupEventList eventList);
        static void RecalcTimer(ActionTriggersHolder& holder);
        void UpdateTimer(ActionTriggersHolder& holder, uint32 const diff);
        void OnUpdate(const uint32 diff);
        void MovementInform(uint32 type, uint32 id);
        void StartActionSet(uint32 actionSetId, ObjectGuid invokerGuid = ObjectGuid::Empty);
        void TerminateActionSets();
        AIGroupActiveActionSetList const& GetActiveActionSets() const { return mActionSets; }
        void ReplaceActionTriggers();
        void ProcessEvent(ActionTriggersHolder& holder, Unit* unit = nullptr, uint32 triggerParam1 = 0, uint32 triggerParam2 = 0, GameObject* gob = nullptr);
        void ProcessEventsFor(UnitActionTriggers holder, Unit* unit = nullptr, uint32 triggerParam1 = 0, uint32 triggerParam2 = 0, GameObject* gob = nullptr);

        void GetActionTargets(AIGroupObjectVector& targets, ActionSetEventHolder const& action, WorldObject* invoker = nullptr) const;
        GameObject* FindGameObjectNear(WorldObject* searchObject, ObjectGuid::LowType guid) const;
        Creature* FindCreatureNear(WorldObject* searchObject, ObjectGuid::LowType guid) const;

        WorldObject* GetBaseObject() const;
        void GetWorldObjectsInDist(AIGroupObjectVector& objects, float distance) const;

    private:
        void InstallEvents();
        void UpdateActionSets(uint32 diff);
        bool ExecuteAction(ActionSetEventHolder const& action, ObjectGuid const& invokerGuid);
        void FinishActionSet(AIGroupActiveActionSet& actionSet);
        bool CanActionBeInfinite(uint16 action);
        bool ShouldStopMovementForAction(uint16 action);
        bool IsActionWaitable(uint16 action);
        uint32 GetActionDuration(ActionSetEventHolder const& action) const;
        float GetStringIdSearchRadius(ActionSetEventHolder const& action) const;

        AIGroupEventList mInstallEvents;
        AIGroupEventList mEvents;
        AIGroupActiveActionSetList mActionSets;

        Creature* me;
        GameObject* go;
};

#endif
