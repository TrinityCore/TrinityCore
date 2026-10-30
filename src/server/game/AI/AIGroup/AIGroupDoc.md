* [What is... Action Triggers](#what-is-action-triggers)
* [What is... Action Triggers Name](#what-is-action-triggers-name)

--------------

* [Creating a New Action Trigger](#creating-a-new-action-trigger)
* [Creating a New Action](#creating-a-new-action)

## What is... Action Triggers

Action triggers is the base of AIGroup script, it is linked to creature using `TriggersId` in `creature_template` database table. Triggers are configured in the `action_triggers` database table and can respond to events such as spawning, entering combat, being hit by a spell, or reaching a health range. Each trigger links to an action set and can optionally filter on trigger parameters or control its chance and repeat behavior. When its condition is met, the AIGroup runs the linked action set.

## What is... Action Triggers Name

`action_triggers_name` is only used to store action triggers names. Currently active action triggers can be displayed by the .npc_info command if `action_triggers_name` is populated.

## Creating a New Action Trigger

To create a new action trigger, follow these steps:

1. Add a new action trigger starting with 'On' to the `ActionTriggers` enum, placing it at the end of the enum (e.g., `OnQuestTaken`).
2. If your trigger is not repeatable, add it to `IsTriggerNotRepeatable`.
3. Add your trigger to `IsTriggerAllowed`.
4. Add your trigger to `AIGroupMgr::ActionTriggerTypeInfo`. The first parameter is the name of your trigger. If your trigger uses TriggerParam1, set the second parameter to 'true', otherwise 'false'. If your trigger uses TriggerParam2, set the third parameter to 'true', otherwise 'false'.
5. Add the appropriate callback in `AIGroup.cpp` and call `GetScript()->ProcessEventsFor(...)`.
6. Implement trigger behavior in `AIGroupScript::ProcessEvent`.
7. If parameters need validation, add the checks to the `AIGroupMgr::LoadActionTriggersFromDB`.

## Creating a New Action

To create a new action, follow these steps:

1. Add a new action to the `AI_GROUP_ACTION` enum using the last available AI_GROUP_CU_ slot (retain the CU_ prefix). Follow the standard naming conventions:
   - Unit-specific actions: Add the `UNIT_` prefix (e.g., `AI_GROUP_CU_UNIT_DISPLAYID`).
   - Object-specific actions: Add the `OBJECT_` prefix (e.g., `AI_GROUP_CU_OBJECT_DISPLAYID`).
   - Groupwide or main actor actions: Do not add a `UNIT_` or `OBJECT_` prefix (e.g., `AI_GROUP_CU_DISPLAYID`).
2. Add a short description explaining what your action does:
   - Unit actions: Mention that it applies to units (e.g. `Change display for unit(s)`).
   - Object actions: Mention that it applies to objects (e.g. `Change display for object(s)`).
   - Groupwide or main actor actions: Do not include a target mention (e.g. `Change display`).
3. Add your action to `AIGroupMgr::GetObjectTypeMask`. If the action is used by units only, specify `ObjectTypeMaskUnit`; if by objects only, specify `ObjectTypeMaskObject`; if by both units and objects, specify `ObjectTypeMaskAll`. This is needed for runtime validation to prevent game objects from executing unit-only actions and units from executing object-only actions.<br>
**IMPORTANT:** Skipping this step will cause AIGroup to throw an error during action execution, as executing an action without a type mask or with the wrong type mask may lead to unexpected behavior or crashes.
4. Add your action to the end of `AIGroupMgr::StaticActionSetTypeData` and specify which parameters it uses. The full list of parameters is specified in the `ActionTypeField` enum. This is required to throw an error if fields unused by the action are populated.<br>
**IMPORTANT:** If your action uses no fields, it requires an empty row, like the one below:

```cpp
    { "AI_GROUP_FALL_TO_THE_GROUND", {  } },
```

5. If needed, validate `extra` parameters in `IsActionTypeValid`. All other parameters are validated automatically and do not require any changes.
6. Implement the action behavior in `AIGroupScript::ExecuteActionForActor`. If your action uses the `StringId` field, ensure you also add your action to the section where `StringId` target selection is handled. Additionally, add your action to `AIGroupScript::GetStringIdSearchRadius`.<br>
**IMPORTANT:** By default, the action targets both creatures and game objects with the specified `StringId` within a 100-yard range.
