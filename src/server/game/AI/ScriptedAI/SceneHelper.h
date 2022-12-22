#ifndef SCENE_HELPER_H
#define SCENE_HELPER_H

#include "CreatureAI.h"
#include "Creature.h"
#include "TaskScheduler.h"
#include "CreatureAIImpl.h"

enum ActionTypesScenehelperAction
{
    ACTION_TALK_SCENEHELPER_ACTIONS,
    ACTION_WHISPER_SCENEHELPER_ACTIONS,
    ACTION_MOVE_SCENEHELPER_ACTIONS,
    ACTION_SUMMON_SCENEHELPER_ACTIONS,
    ACTION_CAST_SCENEHELPER_ACTIONS,
    ACTION_AI_SCENEHELPER_ACTIONS,
    ACTION_MOVE_POS_SCENEHELPER_ACTIONS,
};

class TC_GAME_API SceneAction
{
public:

    SceneAction(ObjectGuid actorGuid, Map* actionMap, ActionTypesScenehelperAction actionType, uint32 actionTimer) :
        actorGuid(actorGuid), actionMap(actionMap), actionType(actionType), actionTimer(actionTimer) { }
    virtual ~SceneAction() { };

    ActionTypesScenehelperAction GetActionType() const { return actionType; }
    uint32 GetActionTimer() const { return actionTimer; }
    virtual void DoAction() {};

protected:

    Creature* GetActor()
    {
        return actionMap->GetCreature(actorGuid);
    }

    ObjectGuid GetActorGuid()
    {
        return actorGuid;
    }

    Map* GetActionMap()
    {
        return actionMap;
    }

protected:

    ObjectGuid actorGuid;
    Map* actionMap;
    ActionTypesScenehelperAction actionType;
    uint32 actionTimer;
};

class TC_GAME_API SceneActionTalk : public SceneAction
{
public:

    SceneActionTalk(ObjectGuid actorGuid, Map* actionMap, uint32 talkIndex, uint32 actionTimer) :
        SceneAction(actorGuid, actionMap, ACTION_TALK_SCENEHELPER_ACTIONS, actionTimer), talkIndex(talkIndex)
    {
    }

    void DoAction();

private:

    uint32 talkIndex;

};

class TC_GAME_API SceneActionWhisper : public SceneAction
{
public:

    SceneActionWhisper(ObjectGuid actorGuid, Map* actionMap, uint32 talkIndex, ObjectGuid whisperGuid, uint32 actionTimer) :
        SceneAction(actorGuid, actionMap, ACTION_WHISPER_SCENEHELPER_ACTIONS, actionTimer), talkIndex(talkIndex), whisperGuid(whisperGuid)
    {

    }

    void DoAction();

private:

    uint32 talkIndex;
    ObjectGuid whisperGuid;

};

class TC_GAME_API SceneActionSummon : public SceneAction
{
public:

    SceneActionSummon(ObjectGuid actorGuid, Map* actionMap, uint32 summonEntry, const Position& summonPosition, uint32 actionTimer) :
        SceneAction(actorGuid, actionMap, ACTION_SUMMON_SCENEHELPER_ACTIONS, actionTimer), summonEntry(summonEntry), summonPosition(summonPosition) {}

    void DoAction();

private:

    uint32 summonEntry;
    Position summonPosition;
};

class TC_GAME_API SceneActionCast : public SceneAction
{
public:

    SceneActionCast(ObjectGuid actorGuid, Map* actionMap, uint32 spellEntry, uint32 actionTimer) :
        SceneAction(actorGuid, actionMap, ACTION_CAST_SCENEHELPER_ACTIONS, actionTimer), spellEntry(spellEntry)
    {

    }

    void DoAction();

private:

    uint32 spellEntry;
};

class TC_GAME_API SceneActionMovePos : public SceneAction
{
public:

    SceneActionMovePos(ObjectGuid actorGuid, Map* actionMap, const Position position, uint32 actionTimer) :
        SceneAction(actorGuid, actionMap, ACTION_MOVE_POS_SCENEHELPER_ACTIONS, actionTimer), position(position)
    {

    }

    void DoAction();

private:

    const Position position;
};

class TC_GAME_API SceneActionMovePath : public SceneAction
{
public:

    SceneActionMovePath(ObjectGuid actorGuid, Map* actionMap, int pathId, uint32 actionTimer) :
        SceneAction(actorGuid, actionMap, ACTION_MOVE_POS_SCENEHELPER_ACTIONS, actionTimer), pathId(pathId)
    {

    }

    void DoAction();

private:

    int pathId;
};

class TC_GAME_API SceneActionAI : public SceneAction
{
public:

    SceneActionAI(ObjectGuid actorGuid, Map* actionMap, int32 m_actionId, uint32 actionTimer) :
        SceneAction(actorGuid, actionMap, ACTION_AI_SCENEHELPER_ACTIONS, actionTimer), actionId(m_actionId)
    {

    }

    void DoAction();

private:

    int32 actionId;
};

class TC_GAME_API SceneActionCastTarget : public SceneAction
{
public:

    SceneActionCastTarget(ObjectGuid actorGuid, Map* actionMap, uint32 spellEntry, bool triggered, Unit* target, uint32 actionTimer) :
        SceneAction(actorGuid, actionMap, ACTION_CAST_SCENEHELPER_ACTIONS, actionTimer), spellEntry(spellEntry), target(target), triggered(triggered)
    {

    }

    void DoAction();

private:

    uint32 spellEntry;
    Unit* target;
    bool triggered;
};

class TC_GAME_API SceneActionKillCreditMonster : public SceneAction
{
public:

    SceneActionKillCreditMonster(ObjectGuid actorGuid, Map* actionMap, uint32 creditEntry, Unit* target, uint32 amount, uint32 actionTimer) :
        SceneAction(actorGuid, actionMap, ACTION_CAST_SCENEHELPER_ACTIONS, actionTimer), creditEntry(creditEntry), target(target), amount(amount)
    {

    }

    void DoAction();

private:

    uint32 creditEntry;
    Unit* target;
    uint32 amount;
};

class TC_GAME_API SceneActionForceCast : public SceneAction
{
public:

    SceneActionForceCast(ObjectGuid actorGuid, Map* actionMap, Unit* caster, uint32 spellEntry, bool triggered, Unit* target, uint32 actionTimer) :
        SceneAction(actorGuid, actionMap, ACTION_CAST_SCENEHELPER_ACTIONS, actionTimer), caster(caster), spellEntry(spellEntry), target(target), triggered(triggered)
    {

    }

    void DoAction();

private:

    Unit* caster;
    uint32 spellEntry;
    Unit* target;
    bool triggered;
};

class TC_GAME_API SceneActionEmote : public SceneAction
{
public:

    SceneActionEmote(ObjectGuid actorGuid, Map* actionMap, int32 emoteId, uint32 actionTimer) :
        SceneAction(actorGuid, actionMap, ACTION_AI_SCENEHELPER_ACTIONS, actionTimer), emoteId(emoteId)
    {

    }

    void DoAction();

private:

    int32 emoteId;
};

class TC_GAME_API SceneActionDespawn : public SceneAction
{
public:

    SceneActionDespawn(ObjectGuid actorGuid, Map* actionMap, int32 despawnTime, uint32 actionTimer) :
        SceneAction(actorGuid, actionMap, ACTION_AI_SCENEHELPER_ACTIONS, actionTimer), despawnTime(despawnTime)
    {

    }

    void DoAction();

private:

    int32 despawnTime;
};

class TC_GAME_API SceneActionFace : public SceneAction
{
public:

    SceneActionFace(ObjectGuid actorGuid, Map* actionMap, Unit* target, uint32 actionTimer) :
        SceneAction(actorGuid, actionMap, ACTION_AI_SCENEHELPER_ACTIONS, actionTimer), target(target)
    {

    }

    void DoAction();

private:

    Unit* target;
};

/*class TC_GAME_API SceneActionSetFlag : public SceneAction
{
public:

    SceneActionSetFlag(ObjectGuid actorGuid, Map* actionMap, uint8 index, uint16 newFlag, uint32 actionTimer) :
        SceneAction(actorGuid, actionMap, ACTION_AI_SCENEHELPER_ACTIONS, actionTimer), index(index), newFlag(newFlag)
    {

    }

    void DoAction();

private:

    uint8 index;
    uint16 newFlag;
};

class TC_GAME_API SceneActionRemoveFlag : public SceneAction
{
public:

    SceneActionRemoveFlag(ObjectGuid actorGuid, Map* actionMap, uint8 index, uint16 oldFlag, uint32 actionTimer) :
        SceneAction(actorGuid, actionMap, ACTION_AI_SCENEHELPER_ACTIONS, actionTimer), index(index), oldFlag(oldFlag)
    {

    }

    void DoAction();

private:

    uint8 index;
    uint16 oldFlag;
};*/

class TC_GAME_API SceneHelper
{
public:

    SceneHelper(ObjectGuid actorGuid, Map* actionMap) : defaultActorGuid(actorGuid), actionMap(actionMap),
        isActive(false), sceneTimer(1000)
    {
    }

    SceneHelper(Map* actionMap) : defaultActorGuid(ObjectGuid::Empty), actionMap(actionMap),
        isActive(false), sceneTimer(1000)
    {
    }

    ~SceneHelper()
    {
        Clear();
    }

    void SetDefaultActorGuid(ObjectGuid actorGuid) { defaultActorGuid = actorGuid; }

    bool IsActive() const { return isActive; }
    bool IsStopped() const { return !isActive; }
    bool IsEmpty() const { return sceneActionList.empty(); }

    void Activate()
    {
        if (IsEmpty())
            return;

        sceneTimer = GetCurrentAction()->GetActionTimer();

        isActive = true;
    }

    void UpdateSceneHelper(uint32 diff)
    {
        if (IsStopped())
            return;

        if (sceneActionList.empty())
        {
            Stop();
            return;
        }

        if (sceneTimer <= diff)
        {
            if (SceneAction* action = this->GetCurrentAction())
            {
                action->DoAction();

                //sceneActionList.remove(action);
                delete action;
                sceneActionList.pop_front();
            }

            if (SceneAction* nextAction = this->GetCurrentAction())
            {
                sceneTimer = nextAction->GetActionTimer();
            }
            else
            {
                Stop();
                return;
            }
        }
        else
        {
            sceneTimer -= diff;
        }
    }

    void Stop() { isActive = false; }

    void AddSceneActionTalk(uint32 talkIndex, uint32 actionTimer = 1000)
    {
        sceneActionList.push_back(new SceneActionTalk(defaultActorGuid, actionMap, talkIndex, actionTimer));
    }

    void AddSceneActionTalkByActor(ObjectGuid actorGuid, uint32 talkIndex, uint32 actionTimer = 1000)
    {
        sceneActionList.push_back(new SceneActionTalk(actorGuid, actionMap, talkIndex, actionTimer));
    }

    void AddSceneActionWhisper(uint32 talkIndex, ObjectGuid whisperGuid, uint32 actionTimer = 1000)
    {
        sceneActionList.push_back(new SceneActionWhisper(defaultActorGuid, actionMap, talkIndex, whisperGuid, actionTimer));
    }

    void AddSceneSummonCreature(uint32 summonEntry, const Position& summonPosition, uint32 actionTimer = 1000)
    {
        sceneActionList.push_back(new SceneActionSummon(defaultActorGuid, actionMap, summonEntry, summonPosition, actionTimer));
    }

    void AddSceneCast(uint32 spellEntry, uint32 actionTimer = 1000)
    {
        sceneActionList.push_back(new SceneActionCast(defaultActorGuid, actionMap, spellEntry, actionTimer));
    }

    void AddSceneActionAI(int32 actionId, uint32 actionTimer = 1000)
    {
        sceneActionList.push_back(new SceneActionAI(defaultActorGuid, actionMap, actionId, actionTimer));
    }

    void AddSceneActionMovePos(const Position pos, uint32 actionTimer = 1000)
    {
        sceneActionList.push_back(new SceneActionMovePos(defaultActorGuid, actionMap, pos, actionTimer));
    }

    void AddSceneActionMovePath(int pathId, uint32 actionTimer = 1000)
    {
        sceneActionList.push_back(new SceneActionMovePath(defaultActorGuid, actionMap, pathId, actionTimer));
    }

    void AddSceneActionCastTarget(uint32 spellEntry, bool triggered, Unit* target, uint32 actionTimer = 1000)
    {
        sceneActionList.push_back(new SceneActionCastTarget(defaultActorGuid, actionMap, spellEntry, triggered, target, actionTimer));
    }

    void AddSceneActionForceCast(Unit* caster, uint32 spellEntry, bool triggered, Unit* target, uint32 actionTimer = 1000)
    {
        sceneActionList.push_back(new SceneActionForceCast(defaultActorGuid, actionMap, caster, spellEntry, triggered, target, actionTimer));
    }

    void AddSceneActionKillCreditMonster(uint32 creditEntry, Unit* target, uint32 amount = 1, uint32 actionTimer = 1000)
    {
        sceneActionList.push_back(new SceneActionKillCreditMonster(defaultActorGuid, actionMap, creditEntry, target, amount, actionTimer));
    }

    void AddSceneActionKillCreditMonster(uint32 creditEntry, Unit* target, uint32 actionTimer = 1000)
    {
        sceneActionList.push_back(new SceneActionKillCreditMonster(defaultActorGuid, actionMap, creditEntry, target, 1, actionTimer));
    }

    void AddSceneActionEmote(uint32 emoteId, uint32 actionTimer = 1000)
    {
        sceneActionList.push_back(new SceneActionEmote(defaultActorGuid, actionMap, emoteId, actionTimer));
    }

    void AddSceneActionDespawn(uint32 despawnTime = 0, uint32 actionTimer = 1000)
    {
        sceneActionList.push_back(new SceneActionDespawn(defaultActorGuid, actionMap, despawnTime, actionTimer));
    }

    void AddSceneActionFace(Unit* target, uint32 actionTimer = 1000)
    {
        sceneActionList.push_back(new SceneActionFace(defaultActorGuid, actionMap, target, actionTimer));
    }

    /*void AddSceneActionSetFlag(uint8 index, uint16 newFlag, uint32 actionTimer = 1000)
    {
        sceneActionList.push_back(new SceneActionSetFlag(defaultActorGuid, actionMap, index, newFlag, actionTimer));
    }

    void AddSceneActionRemoveFlag(uint8 index, uint16 oldFlag, uint32 actionTimer = 1000)
    {
        sceneActionList.push_back(new SceneActionRemoveFlag(defaultActorGuid, actionMap, index, oldFlag, actionTimer));
    }*/

    void Clear()
    {
        Stop();

        while (!sceneActionList.empty())
        {
            delete sceneActionList.front();
            sceneActionList.pop_front();
        }
    }

private:

    SceneAction* GetCurrentAction()
    {
        if (sceneActionList.empty())
            return NULL;

        return sceneActionList.front();
    }

private:

    bool isActive;
    ObjectGuid defaultActorGuid;
    Map* actionMap;
    uint32 sceneTimer;
    std::list<SceneAction*> sceneActionList;
};

#endif
