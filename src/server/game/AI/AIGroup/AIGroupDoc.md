* [What is... Action Triggers](#what-is-action-triggers)

* [Creating a New Action Trigger](#creating-a-new-action-trigger)

## What is... Action Triggers

Action triggers is the base of AIGroup script, it is linked to creature using `TriggersId` in `creature_template` database table. Triggers are configured in the `action_triggers` database table and can respond to events such as spawning, entering combat, being hit by a spell, or reaching a health range. Each trigger links to an action set and can optionally filter on trigger parameters or control its chance and repeat behavior. When its condition is met, the AIGroup runs the linked action set.

## Creating a New Action Trigger

To create a new action trigger, follow these steps:

1. Add a new action trigger to the `ActionTriggers` enum, starting with 'On'.
2. If your trigger is not repeatable, add it to `IsTriggerNotRepeatable`.
3. Add your trigger to `AIGroupMgr::ActionTriggerTypeInfo`. The first parameter is the name of your trigger. If your trigger uses TriggerParam1, set the second parameter to 'true', otherwise 'false'. If your trigger uses TriggerParam2, set the third parameter to 'true', otherwise 'false'.
4. Add the appropriate callback in `AIGroup.cpp` and call `GetScript()->ProcessEventsFor(...)`.
5. Implement trigger behavior in `AIGroupScript::ProcessEvent`.
6. If parameters need validation, add the checks to the `AIGroupMgr::LoadActionTriggersFromDB`.
