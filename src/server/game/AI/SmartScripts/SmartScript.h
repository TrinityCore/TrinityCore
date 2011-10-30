/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

#ifndef TRINITY_SMARTSCRIPT_H
#define TRINITY_SMARTSCRIPT_H

#include "Common.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "Unit.h"
#include "ConditionMgr.h"
#include "CreatureTextMgr.h"
#include "Spell.h"
#include "GridNotifiers.h"

#include "SmartScriptMgr.h"
//#include "SmartAI.h"

class SmartScript
{
    public:
        SmartScript();
        ~SmartScript();

        void OnInitialize(WorldObject* obj, AreaTriggerEntry const* at = NULL);
        void GetScript();
        void FillScript(SmartAIEventList e, WorldObject* obj, AreaTriggerEntry const* at);

        void ProcessEventsFor(SMART_EVENT e, Unit* unit = NULL, uint32 var0 = 0, uint32 var1 = 0, bool bvar = false, const SpellInfo* spell = NULL, GameObject* gob = NULL);
        void ProcessEvent(SmartScriptHolder& e, Unit* unit = NULL, uint32 var0 = 0, uint32 var1 = 0, bool bvar = false, const SpellInfo* spell = NULL, GameObject* gob = NULL);
        bool CheckTimer(SmartScriptHolder const& e) const;
        void RecalcTimer(SmartScriptHolder& e, uint32 min, uint32 max);
        void UpdateTimer(SmartScriptHolder& e, uint32 const diff);
        void InitTimer(SmartScriptHolder& e);
        void ProcessAction(SmartScriptHolder& e, Unit* unit = NULL, uint32 var0 = 0, uint32 var1 = 0, bool bvar = false, const SpellInfo* spell = NULL, GameObject* gob = NULL);
        ObjectList* GetTargets(SmartScriptHolder const& e, Unit* invoker = NULL);
        ObjectList* GetWorldObjectsInDist(float dist);
        void InstallTemplate(SmartScriptHolder const& e);
        SmartScriptHolder CreateEvent(SMART_EVENT e, uint32 event_flags, uint32 event_param1, uint32 event_param2, uint32 event_param3, uint32 event_param4, SMART_ACTION action, uint32 action_param1, uint32 action_param2, uint32 action_param3, uint32 action_param4, uint32 action_param5, uint32 action_param6, SMARTAI_TARGETS t, uint32 target_param1, uint32 target_param2, uint32 target_param3, uint32 phaseMask = 0);
        void AddEvent(SMART_EVENT e, uint32 event_flags, uint32 event_param1, uint32 event_param2, uint32 event_param3, uint32 event_param4, SMART_ACTION action, uint32 action_param1, uint32 action_param2, uint32 action_param3, uint32 action_param4, uint32 action_param5, uint32 action_param6, SMARTAI_TARGETS t, uint32 target_param1, uint32 target_param2, uint32 target_param3, uint32 phaseMask = 0);
        void SetPathId(uint32 id) { mPathId = id; }
        uint32 GetPathId() const { return mPathId; }
        WorldObject* GetBaseObject()
        {
            WorldObject* obj = NULL;
            if (me)
                obj = me;
            else if (go)
                obj = go;
            return obj;
        }

        bool IsUnit(WorldObject* obj)
        {
            return obj && (obj->GetTypeId() == TYPEID_UNIT || obj->GetTypeId() == TYPEID_PLAYER);
        }

        bool IsPlayer(WorldObject* obj)
        {
            return obj && obj->GetTypeId() == TYPEID_PLAYER;
        }

        bool IsCreature(WorldObject* obj)
        {
            return obj && obj->GetTypeId() == TYPEID_UNIT;
        }

        bool IsGameObject(WorldObject* obj)
        {
            return obj && obj->GetTypeId() == TYPEID_GAMEOBJECT;
        }

        bool ConditionValid(Unit* u, int32 c, int32 v1, int32 v2, int32 v3)
        {
            if (c == 0) return true;
            if (!u || !u->ToPlayer()) return false;
            Condition cond;
            cond.mConditionType = ConditionType(uint32(c));
            cond.mConditionValue1 = uint32(v1);
            cond.mConditionValue1 = uint32(v2);
            cond.mConditionValue1 = uint32(v3);
            return cond.Meets(u->ToPlayer());
        }

        void OnUpdate(const uint32 diff);
        void OnMoveInLineOfSight(Unit* who);

        Unit* DoSelectLowestHpFriendly(float range, uint32 MinHPDiff);
        void DoFindFriendlyCC(std::list<Creature*>& _list, float range);
        void DoFindFriendlyMissingBuff(std::list<Creature*>& list, float range, uint32 spellid);

        void StoreTargetList(ObjectList* targets, uint32 id)
        {
            if (!targets)
                return;

            if (mTargetStorage->find(id) != mTargetStorage->end())
                delete (*mTargetStorage)[id];

            (*mTargetStorage)[id] = targets;
        }

        bool IsSmart(Creature* c = NULL)
        {
            bool smart = true;
            if (c && c->GetAIName() != "SmartAI")
                smart = false;

            if (!me || me->GetAIName() != "SmartAI")
                smart = false;

            if (!smart)
                sLog->outErrorDb("SmartScript: Action target Creature(entry: %u) is not using SmartAI, action skipped to prevent crash.", c ? c->GetEntry() : (me ? me->GetEntry() : 0));

            return smart;
        }

        bool IsSmartGO(GameObject* g = NULL)
        {
            bool smart = true;
            if (g && g->GetAIName() != "SmartGameObjectAI")
                smart = false;

            if (!go || go->GetAIName() != "SmartGameObjectAI")
                smart = false;
            if (!smart)
                sLog->outErrorDb("SmartScript: Action target GameObject(entry: %u) is not using SmartGameObjectAI, action skipped to prevent crash.", g ? g->GetEntry() : (go ? go->GetEntry() : 0));

            return smart;
        }

        ObjectList* GetTargetList(uint32 id)
        {
            ObjectListMap::iterator itr = mTargetStorage->find(id);
            if (itr != mTargetStorage->end())
                return (*itr).second;
            return NULL;
        }

        GameObject* FindGameObjectNear(WorldObject* searchObject, uint32 guid) const
        {
            GameObject* gameObject = NULL;

            CellCoord p(Trinity::ComputeCellCoord(searchObject->GetPositionX(), searchObject->GetPositionY()));
            Cell cell(p);

            Trinity::GameObjectWithDbGUIDCheck goCheck(*searchObject, guid);
            Trinity::GameObjectSearcher<Trinity::GameObjectWithDbGUIDCheck> checker(searchObject, gameObject, goCheck);

            TypeContainerVisitor<Trinity::GameObjectSearcher<Trinity::GameObjectWithDbGUIDCheck>, GridTypeMapContainer > objectChecker(checker);
            cell.Visit(p, objectChecker, *searchObject->GetMap(), *searchObject, searchObject->GetGridActivationRange());

            return gameObject;
        }

        Creature* FindCreatureNear(WorldObject* searchObject, uint32 guid) const
        {
            Creature* creature = NULL;
            CellCoord p(Trinity::ComputeCellCoord(searchObject->GetPositionX(), searchObject->GetPositionY()));
            Cell cell(p);

            Trinity::CreatureWithDbGUIDCheck target_check(searchObject, guid);
            Trinity::CreatureSearcher<Trinity::CreatureWithDbGUIDCheck> checker(searchObject, creature, target_check);

            TypeContainerVisitor<Trinity::CreatureSearcher <Trinity::CreatureWithDbGUIDCheck>, GridTypeMapContainer > unit_checker(checker);
            cell.Visit(p, unit_checker, *searchObject->GetMap(), *searchObject, searchObject->GetGridActivationRange());

            return creature;
        }

        ObjectListMap* mTargetStorage;

        void OnReset();
        void ResetBaseObject()
        {
            if (meOrigGUID)
            {
                if (Creature* m = HashMapHolder<Creature>::Find(meOrigGUID))
                {
                    me = m;
                    go = NULL;
                }
            }
            if (goOrigGUID)
            {
                if (GameObject* o = HashMapHolder<GameObject>::Find(goOrigGUID))
                {
                    me = NULL;
                    go = o;
                }
            }
            goOrigGUID = 0;
            meOrigGUID = 0;
        }

        //TIMED_ACTIONLIST (script type 9 aka script9)
        void SetScript9(SmartScriptHolder& e, uint32 entry);
        Unit* GetLastInvoker();
        uint64 mLastInvoker;

    private:
        void IncPhase(int32 p = 1)
        {
            if (p >= 0)
                mEventPhase += (uint32)p;
            else
                DecPhase(abs(p));
        }

        void DecPhase(int32 p = 1) { mEventPhase  -= (mEventPhase < (uint32)p ? (uint32)p - mEventPhase : (uint32)p); }
        bool IsInPhase(uint32 p) const { return (1 << (mEventPhase - 1)) & p; }
        void SetPhase(uint32 p = 0) { mEventPhase = p; }

        SmartAIEventList mEvents;
        SmartAIEventList mInstallEvents;
        SmartAIEventList mTimedActionList;
        bool mResumeActionList;
        Creature* me;
        uint64 meOrigGUID;
        GameObject* go;
        uint64 goOrigGUID;
        AreaTriggerEntry const* trigger;
        SmartScriptType mScriptType;
        uint32 mEventPhase;

        uint32 mInvinceabilityHpLevel;
        UNORDERED_MAP<int32, int32> mStoredDecimals;
        uint32 mPathId;
        SmartAIEventList mStoredEvents;
        std::list<uint32>mRemIDs;

        uint32 mTextTimer;
        uint32 mLastTextID;
        uint64 mTextGUID;
        uint32 mTalkerEntry;
        bool mUseTextTimer;

        SMARTAI_TEMPLATE mTemplate;
        void InstallEvents();

        void RemoveStoredEvent (uint32 id)
        {
            if (!mStoredEvents.empty())
            {
                for (SmartAIEventList::iterator i = mStoredEvents.begin(); i != mStoredEvents.end(); ++i)
                {
                    if (i->event_id == id)
                    {
                        mStoredEvents.erase(i);
                        return;
                    }

                }
            }
        }
        SmartScriptHolder FindLinkedEvent (uint32 link)
        {
            if (!mEvents.empty())
            {
                for (SmartAIEventList::iterator i = mEvents.begin(); i != mEvents.end(); ++i)
                {
                    if (i->event_id == link)
                    {
                        return (*i);
                    }

                }
            }
            SmartScriptHolder s;
            return s;
        }
};

#endif
