* [TO-DO List](#to-do-list)
* [What is... Action Triggers](#what-is-action-triggers)
* [What is... Action Triggers Name](#what-is-action-triggers-name)

--------------

* [Creating a New Action Trigger](#creating-a-new-action-trigger)
* [Creating a New Action](#creating-a-new-action)
* [Actions, Fields](#actions-fields)

## TO-DO List

* 'debug named point' command. It should spawn visible only to GM creatures on every named point within a given radius(by default 100)

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

5. If needed, validate `extra` parameters in `IsActionTypeValid`. All other parameters are validated automatically and do not require any changes.<br>
**IMPORTANT:** If your `extra` parameter uses an integer, always use `IsIntegerDouble` or `IsNonNegativeWholeNumberInRange` or `IsPositiveWholeNumberInRange`.
6. Implement the action behavior in `AIGroupScript::ExecuteActionForActor`. If your action uses the `StringId` field, ensure you also add your action to the section where `StringId` target selection is handled. Additionally, add your action to `AIGroupScript::GetStringIdSearchRadius`.<br>
**IMPORTANT:** By default, the action targets both creatures and game objects with the specified `StringId` within a 100-yard range.

## Actions, Fields

* **0 - AI_GROUP_SPAWN - (Spawn)**

`TimeA`

`Extra2`

* **1 - AI_GROUP_IDLE - (Idle)**

`TimeA`

`TimeB`

* **2 - AI_GROUP_MOVETO - (Move within distance of a point)**

`Point`

`MoveSpeed`

`StringId`

`Extra0`

`Extra1`

`Extra2`

`Extra3`

* **3 - AI_GROUP_TELEPORT - (Teleport to a point in the world)**

`Point`

`StringId`

`Extra0`

* **4 - AI_GROUP_WANDER - (Wander)**

`Point`

`TimeA`

`StringId`

`Extra0`

`Extra1`

`Extra2`

* **5 - AI_GROUP_ATTACK_ALL - (Attack all players within a given radius; old AI_GROUP_WANDER_SPAWNRELATIVE_OBSOLETE)**

`Extra0`

* **6 - AI_GROUP_WANDER_AREA - (Wander a convex poly area (not yet implemented))**

*No parameters*

* **7 - AI_GROUP_FOLLOW_GUID - (Follow a unit)**

`TimeA`

`StringId`

`Extra0`

`Extra1`

* **8 - AI_GROUP_FOLLOW_PATH - (Follow a path)**

`Path`

`MoveSpeed`

`LinearPath`

`Extra3`

* **9 - AI_GROUP_PATROL_LINE - (Patrol back and forth along a path)**

`Path`

`TimeA`

`MoveSpeed`

`LinearPath`

`Extra0`

`Extra1`

`Extra2`

`Extra3`

`Extra4`

* **10 - AI_GROUP_PATROL_CIRCLE - (Patrol in a circular path)**

`Path`

`TimeA`

`MoveSpeed`

`CircularPath`

`Extra3`

* **11 - AI_GROUP_GUARD_GUID - (Guard a unit)**

`TimeA`

`StringId`

`Extra0`

`Extra1`

`Extra3`

* **12 - AI_GROUP_GUARD_AREA - (Guard an area (not yet implemented))**

*No parameters*

* **13 - AI_GROUP_SET_FORMATION - (Set a specific formation and spread)**

`Extra0`

`Extra1`

`Extra2`

`Extra4`

* **14 - AI_GROUP_UNIT_CHANGE_MODE_OBSOLETE - (Change mode on unit(s) in the group (obsolete))**

*No parameters*

* **15 - AI_GROUP_UNIT_SAY - (Unit(s) say something)**

`Unit`

`Extra0`

`Extra2`

`Extra4`

* **16 - AI_GROUP_UNIT_CAST - (Unit(s) cast a spell)**

`Unit`

`StringId`

`Extra0`

`Extra2`

* **17 - AI_GROUP_UNIT_ACTIVATE_OBJECT - (Unit(s) activate a game object)**

`Unit`

`StringId`

`Extra0`

`Extra2`

`Extra4`

* **18 - AI_GROUP_GENERATE_EVENT - (Generate an event)**

`Extra2`

* **19 - AI_GROUP_DESPAWN - (Despawn)**

*No parameters*

* **20 - AI_GROUP_SET_RADIUS_OBSOLETE - (Unit(s) start a conversation (public unless target is a player))**

`Unit`

`Extra2`

* **21 - AI_GROUP_SET_FACTION_OBSOLETE - (Unit(s) cancel a conversation (public unless target is a player))**

`Unit`

`Extra2`

* **22 - AI_GROUP_UNIT_SET_FACING - (Unit(s) face a particular angle)**

`Unit`

`Extra2`

* **23 - AI_GROUP_UNIT_FACE_GUID - (Unit(s) face a unit or game object or point)**

`Unit`

`StringId`

`Extra0`

* **24 - AI_GROUP_UNIT_EMOTE - (Emote State - Set and Forget (formerly perform an emote))**

`Unit`

`Extra2`

* **25 - AI_GROUP_MOVETO_GUID - (Move within distance of a unit or game object)**

`TimeA`

`MoveSpeed`

`StringId`

`Extra0`

`Extra1`

`Extra2`

`Extra3`

* **26 - AI_GROUP_ATTACK_GUID - (Attack unit)**

`StringId`

`Extra0`

`Extra2`

* **27 - AI_GROUP_UNIT_MOUNT - (Unit(s) mount a creature)**

`Unit`

`Extra2`

* **28 - AI_GROUP_UNIT_DISMOUNT - (Unit(s) dismount)**

`Unit`

* **29 - AI_GROUP_UNIT_UNINTERACTIBLE - (Set "Uninteractible" flag for unit(s); old AI_GROUP_BEASTMASTER_ON)**

`Unit`

`Extra2`

* **30 - AI_GROUP_UNIT_UNINTERACTIBLE_RESET - (Reset "Uninteractible" flag for unit(s); old AI_GROUP_BEASTMASTER_OFF)**

`Unit`

* **31 - AI_GROUP_UNIT_MODE - (Change mode for unit(s))**

`Unit`

`Extra2`

`Extra4`

* **32 - AI_GROUP_UNIT_MODE_RESET - (Reset mode for unit(s))**

`Unit`

* **33 - AI_GROUP_UNIT_FACTION - (Change faction template for unit(s))**

`Unit`

`Extra2`

* **34 - AI_GROUP_UNIT_FACTION_RESET - (Reset faction template for unit(s))**

`Unit`

* **35 - AI_GROUP_UNIT_RADIUS - (Change radius record for unit(s))**

`Unit`

`Extra2`

* **36 - AI_GROUP_UNIT_RADIUS_RESET - (Reset radius record for unit(s))**

`Unit`

* **37 - AI_GROUP_QUEST_COMPLETE - (Escort quest actions completed)**

*No parameters*

* **38 - AI_GROUP_UNIT_QUESTGIVER - (Unit(s) become a quest giver)**

`Unit`

`Extra2`

* **39 - AI_GROUP_UNIT_TRAINER - (Unit(s) become a trainer)**

`Unit`

`Extra2`

* **40 - AI_GROUP_SPLINE_PATH - (Follow a short path exactly (no pathing))**

`Path`

`MoveSpeed`

`LinearPath`

`Extra3`

* **41 - AI_GROUP_PLAYER_ACTION - (Player performs an action (Programmer -Internal Use Only))**

`Extra2`

* **42 - AI_GROUP_RETURN_HOME - (Move everybody back to spawn positions)**

`TimeA`

`MoveSpeed`

* **43 - AI_GROUP_UNIT_SAY_RANDOM - (Unit(s) say something random)**

`Unit`

`Extra0`

`Extra2`

`Extra4`

* **44 - AI_GROUP_UNIT_YELL - (Unit(s) yell something)**

`Unit`

`Extra0`

`Extra2`

`Extra4`

* **45 - AI_GROUP_UNIT_YELL_RANDOM - (Unit(s) yell something random)**

`Unit`

`Extra0`

`Extra2`

`Extra4`

* **46 - AI_GROUP_UNIT_SET_ITEM_MAINHAND - (Set the item in the mainhand slot for unit(s))**

`Unit`

`Extra2`

`Extra3`

* **47 - AI_GROUP_UNIT_RESET_ITEM_MAINHAND - (Reset the item in the mainhand slot for unit(s))**

`Unit`

* **48 - AI_GROUP_UNIT_CHAT_EMOTE - (Unit(s) chat emote something)**

`Unit`

`Extra0`

`Extra2`

* **49 - AI_GROUP_UNIT_CHAT_EMOTE_RANDOM - (Unit(s) chat emote something random)**

`Unit`

`Extra0`

`Extra2`

* **50 - AI_GROUP_UNIT_GENERATE_EVENT - (Unit(s) in the group generates an event)**

`Unit`

`Extra2`

* **51 - AI_GROUP_VENDOR_IDLE_OBSOLETE - (Vendor wander + face + idle action sequence (obsolete))**

*No parameters*

* **52 - AI_GROUP_QUEST_FAILED - (Escort quest actions failed)**

*No parameters*

* **53 - AI_GROUP_UNIT_TRIGGERS - (Change action triggers for unit(s))**

`Unit`

`Extra2`

`Extra4`

* **54 - AI_GROUP_UNIT_TRIGGERS_RESET - (Reset action triggers for unit(s))**

`Unit`

* **55 - AI_GROUP_UNIT_LEAVE_COMBAT - (Leave combat (combat action only))**

`Extra2`

* **56 - AI_GROUP_IDLE_COMBAT_START - (Idle until group goes into combat)**

`TimeA`

`TimeB`

* **57 - AI_GROUP_IDLE_COMBAT_STOP - (Idle until group returns from combat)**

`TimeA`

`TimeB`

* **58 - AI_GROUP_UNIT_IMMUNEPC - (Set "ImmunePC" flag for unit(s))**

`Unit`

`Extra2`

* **59 - AI_GROUP_UNIT_IMMUNEPC_RESET - (Reset "ImmunePC" flag for unit(s))**

`Unit`

* **60 - AI_GROUP_UNIT_IMMUNENPC - (Set "ImmuneNPC" flag for unit(s))**

`Unit`

`Extra2`

* **61 - AI_GROUP_UNIT_IMMUNENPC_RESET - (Reset "ImmuneNPC" flag for unit(s))**

`Unit`

* **62 - AI_GROUP_UNIT_UNKILLABLE - (Set "Unkillable" flag for unit(s))**

`Unit`

`Extra2`

* **63 - AI_GROUP_UNIT_UNKILLABLE_RESET - (Reset "Unkillable" flag for unit(s))**

`Unit`

* **64 - AI_GROUP_UNIT_SPELLS - (Set the spells record for unit(s))**

`Unit`

`Extra2`

* **65 - AI_GROUP_UNIT_SPELLS_RESET - (Reset the spells record for unit(s))**

`Unit`

* **66 - AI_GROUP_ATTACK_ALL_INSTANCE - (Attack everybody in the instance)**

*No parameters*

* **67 - AI_GROUP_UNIT_SEND_LOCAL_EVENT - (Unit(s) send a local event)**

`Unit`

`StringId`

`Extra0`

`Extra2`

* **68 - AI_GROUP_UNIT_BROADCAST_LOCAL_EVENT - (Unit(s) broadcast a local event)**

`Unit`

`StringId`

`Extra0`

`Extra2`

`Extra4`

* **69 - AI_GROUP_UNIT_FLEE - (Flee combat (combat action only))**

`TimeA`

* **70 - AI_GROUP_UNIT_RETREAT - (Retreat (combat action only))**

`TimeA`

* **71 - AI_GROUP_OBJECT_CHAT_EMOTE - (Object(s) chat emote something)**

`Unit`

`Extra0`

`Extra2`

* **72 - AI_GROUP_OBJECT_CHAT_EMOTE_RANDOM - (Object(s) chat emote something random)**

`Unit`

`Extra0`

`Extra2`

* **73 - AI_GROUP_AVOID - (Move outside a certain distance of a point)**

`Point`

`MoveSpeed`

`StringId`

`Extra0`

`Extra1`

`Extra3`

* **74 - AI_GROUP_AVOID_GUID - (Move outside a certain distance of a unit or game object)**

`TimeA`

`MoveSpeed`

`StringId`

`Extra0`

`Extra1`

`Extra3`

* **75 - AI_GROUP_OBJECT_ACTIVATE - (Activate object(s) in the group)**

`Unit`

`Extra2`

* **76 - AI_GROUP_UNIT_ACTIVATE_OBJECTS - (Unit(s) activate nearby game objects)**

`Unit`

`StringId`

`Extra0`

`Extra2`

* **77 - AI_GROUP_UNIT_STRINGID - (Set the string ID for unit(s))**

`Unit`

`StringId`

`Extra2`

* **78 - AI_GROUP_UNIT_STRINGID_RESET - (Reset the string ID for unit(s))**

`Unit`

`Extra2`

* **79 - AI_GROUP_PERIODIC_EVENT - (Set a periodic event for the group)**

`TimeA`

`Extra2`

* **80 - AI_GROUP_UNIT_SET_ITEM_OFFHAND - (Set the item in the offhand slot for unit(s))**

`Unit`

`Extra2`

`Extra3`

* **81 - AI_GROUP_UNIT_RESET_ITEM_OFFHAND - (Reset the item in the offhand slot for unit(s))**

`Unit`

* **82 - AI_GROUP_UNIT_SET_ITEM_RANGED - (Set the item in the ranged slot for unit(s))**

`Unit`

`Extra2`

`Extra3`

* **83 - AI_GROUP_UNIT_RESET_ITEM_RANGED - (Reset the item in the ranged slot for unit(s))**

`Unit`

* **84 - AI_GROUP_UNIT_SHEATHE - (Unit(s) sheathe their weapons)**

`Unit`

* **85 - AI_GROUP_UNIT_UNSHEATHE - (Unit(s) unsheathe their melee weapons)**

`Unit`

* **86 - AI_GROUP_UNIT_CANCEL_CAST - (Unit(s) cancel casting a spell)**

`Unit`

`Extra2`

* **87 - AI_GROUP_UNIT_CANCEL_AURA - (Unit(s) cancel an aura on themselves)**

`Unit`

`Extra2`

* **88 - AI_GROUP_UNIT_FINISH_CAST - (Unit(s) wait until they finish casting)**

`Unit`

`TimeA`

`TimeB`

* **89 - AI_GROUP_EMOTE_STATE - (Emote State with Idle (formerly continually emote))**

`TimeA`

`TimeB`

`Extra2`

* **90 - AI_GROUP_UNIT_CALL_FOR_HELP - (Call for help (combat action only))**

`StringId`

`Extra0`

* **91 - AI_GROUP_FLIGHT_PATH - (Follow a flight spline path exactly)**

`Path`

`MoveSpeed`

`LinearPath`

`FlightPath`

`Extra3`

* **92 - AI_GROUP_UNIT_COMBAT_TRIGGER - (Trigger actions on units in combat)**

`Unit`

`StringId`

`Extra0`

`Extra2`

* **93 - AI_GROUP_UNIT_GOSSIP - (Unit(s) become a gossip)**

`Unit`

`Extra2`

* **94 - AI_GROUP_UNIT_KILL_CREDIT - (Unit(s) assign kill credit)**

`Unit`

`Extra2`

* **95 - AI_GROUP_UNIT_WHISPER - (Unit(s) whisper to a player)**

`Unit`

`Extra2`

* **96 - AI_GROUP_UNIT_WHISPER_RANDOM - (Unit(s) whisper to a player something random)**

`Unit`

`Extra2`

* **97 - AI_GROUP_UNIT_NO_LOOT - (Set "No Loot" flag for unit(s) in the group)**

`Unit`

`Extra2`

* **98 - AI_GROUP_UNIT_NO_LOOT_RESET - (Reset "No Loot" flag for unit(s) in the group)**

`Unit`

* **99 - AI_GROUP_UNIT_NO_XP - (Set "No XP" flag for unit(s) in the group)**

`Unit`

`Extra2`

* **100 - AI_GROUP_UNIT_NO_XP_RESET - (Reset "No XP" flag for unit(s) in the group)**

`Unit`

* **101 - AI_GROUP_UNIT_PVP_ENABLING - (Set "PVP" flag for unit(s) in the group)**

`Unit`

`Extra2`

* **102 - AI_GROUP_UNIT_PVP_ENABLING_RESET - (Reset "PVP" flag for unit(s) in the group)**

`Unit`

* **103 - AI_GROUP_UNIT_PLAY_MUSIC - (Unit(s) play music)**

`Unit`

`Extra0`

`Extra2`

* **104 - AI_GROUP_UNIT_PLAY_SOUND - (Unit(s) play a sound)**

`Unit`

`Extra0`

`Extra2`

* **105 - AI_GROUP_UNIT_SET_LOOT - (Set the loot for a unit)**

`Unit`

`Extra2`

* **106 - AI_GROUP_UNIT_FLOATING - (Set "Floating" flag for unit(s) in the group)**

`Unit`

`Extra2`

* **107 - AI_GROUP_UNIT_FLOATING_RESET - (Reset "Floating" flag for unit(s) in the group)**

`Unit`

* **108 - AI_GROUP_OBJECT_PLAY_MUSIC - (Object(s) play music)**

`Unit`

`Extra0`

`Extra2`

* **109 - AI_GROUP_OBJECT_PLAY_SOUND - (Object(s) play a sound)**

`Unit`

`Extra0`

`Extra2`

* **110 - AI_GROUP_SPAWN_FORCED - (Spawn (forced))**

`TimeA`

`Extra2`

* **111 - AI_GROUP_UNIT_UNSHEATHE_RANGE - (Unit(s) unsheathe their range weapons)**

`Unit`

* **112 - AI_GROUP_UNIT_CHAT_EMOTE_ZONE - (Unit(s) chat emote something to the zone)**

`Unit`

`Extra2`

`Extra4`

* **113 - AI_GROUP_UNIT_CHAT_EMOTE_ZONE_RANDOM - (Unit(s) chat emote something random to the zone)**

`Unit`

`Extra2`

`Extra4`

* **114 - AI_GROUP_UNIT_YELL_ZONE - (Unit(s) yell something to the zone)**

`Unit`

`Extra2`

`Extra4`

* **115 - AI_GROUP_UNIT_YELL_ZONE_RANDOM - (Unit(s) yell something random to the zone)**

`Unit`

`Extra2`

`Extra4`

* **116 - AI_GROUP_UNIT_PLAY_MUSIC_ZONE - (Unit(s) play music to the zone)**

`Unit`

`Extra2`

`Extra4`

* **117 - AI_GROUP_UNIT_PLAY_SOUND_ZONE - (Unit(s) play a sound to the zone)**

`Unit`

`Extra2`

`Extra4`

* **118 - AI_GROUP_OBJECT_CHAT_EMOTE_ZONE - (Object(s) chat emote something to the zone)**

`Unit`

`Extra2`

* **119 - AI_GROUP_OBJECT_CHAT_EMOTE_ZONE_RANDOM - (Object(s) chat emote something random to the zone)**

`Unit`

`Extra2`

* **120 - AI_GROUP_OBJECT_PLAY_MUSIC_ZONE - (Object(s) play music to the zone)**

`Unit`

`Extra2`

`Extra4`

* **121 - AI_GROUP_OBJECT_PLAY_SOUND_ZONE - (Object(s) play a sound to the zone)**

`Unit`

`Extra2`

`Extra4`

* **122 - AI_GROUP_UNIT_IGNORE_COMBAT - (Set "Ignore combat" flag for unit(s))**

`Unit`

`Extra2`

* **123 - AI_GROUP_UNIT_IGNORE_COMBAT_RESET - (Reset "Ignore combat" flag for unit(s))**

`Unit`

* **124 - AI_GROUP_RANDOM_ACTION_SET - (Perform a random set of actions)**

`Extra2`

* **125 - AI_GROUP_RESTART_ACTIONS_WSE - (Restart the current actions if world state expression is true)**

`Extra2`

* **126 - AI_GROUP_ABORT_ACTION_SET_WSE - (Abort action set if world state expression is true)**

`Extra2`

* **127 - AI_GROUP_UNIT_BOSS_EMOTE - (Unit(s) boss emote something)**

`Unit`

`Extra0`

`Extra2`

`Extra3`

* **128 - AI_GROUP_UNIT_BOSS_EMOTE_ZONE - (Unit(s) boss emote something to the zone)**

`Unit`

`Extra2`

`Extra3`

`Extra4`

* **129 - AI_GROUP_TRIGGER_ACTIONS_NEAREST_UNIT_IC - (Trigger actions on nearest unit in combat)**

`Unit`

`StringId`

`Extra0`

`Extra2`

* **130 - AI_GROUP_UNIT_CAST_FAILURE - (Unit(s) cast a spell and report failure to owner)**

`Unit`

`StringId`

`Extra0`

`Extra2`

* **131 - AI_GROUP_UNIT_NO_REPUTATION - (Set "No Reputation" flag for unit(s) in the group)**

`Unit`

`Extra2`

* **132 - AI_GROUP_UNIT_NO_REPUTATION_RESET - (Reset "No Reputation" flag for unit(s) in the group)**

`Unit`

* **133 - AI_GROUP_SPLINE_PATH_LOOP - (Follow a flight spline path exactly, and loop forever)**

`Path`

`MoveSpeed`

`LinearPath`

`FlightPath`

`Extra3`

* **134 - AI_GROUP_UNIT_VENDOR - (Unit(s) become a vendor)**

`Unit`

`Extra2`

* **135 - AI_GROUP_UNIT_RESET_VENDOR_LISTS - (Reset vendor lists for unit(s) in the group)**

`Unit`

* **136 - AI_GROUP_TRIGGER_ACTIONS_UNITS - (Trigger actions on units)**

`Unit`

`StringId`

`Extra0`

`Extra2`

* **137 - AI_GROUP_TRIGGER_ACTIONS_NEAREST_UNIT - (Trigger actions on nearest unit)**

`Unit`

`StringId`

`Extra0`

`Extra2`

* **138 - AI_GROUP_UNIT_SAY_ZONE - (Unit(s) say something to the zone)**

`Unit`

`Extra2`

`Extra4`

* **139 - AI_GROUP_UNIT_SAY_ZONE_RANDOM - (Unit(s) say something random to the zone)**

`Unit`

`Extra2`

`Extra4`

* **140 - AI_GROUP_UNIT_SEND_LOCAL_EVENT_SELF - (Unit(s) send a local event to self (if outside of combat))**

`Unit`

`Extra2`

* **141 - AI_GROUP_UNIT_SESSILE - (Set "Sessile" flag for unit(s))**

`Unit`

`Extra2`

* **142 - AI_GROUP_UNIT_SESSILE_RESET - (Reset "Sessile" flag for unit(s))**

`Unit`

* **143 - AI_GROUP_UNIT_RAID_LOCK - (Set "RAID_LOCK_ON_DEATH" flag for unit(s))**

`Unit`

`Extra2`

* **144 - AI_GROUP_UNIT_RAID_LOCK_RESET - (Reset "RAID_LOCK_ON_DEATH" flag for unit(s))**

`Unit`

* **145 - AI_GROUP_QUEST_COMPLETE_TRIGGERING_PLAYER - (Quest complete for triggering player)**

`Extra2`

* **146 - AI_GROUP_QUEST_CLEARED_TRIGGERING_PLAYER - (Quest cleared for triggering player)**

`Extra2`

* **147 - AI_GROUP_UNIT_CHAT_PARTY - (Unit(s) chat to a player's party)**

`Unit`

`Extra2`

* **148 - AI_GROUP_UNIT_CLEAR_COOLDOWNS - (Unit(s) clear cooldowns)**

`Unit`

* **149 - AI_GROUP_UNIT_PLAY_TARGETED_SOUND - (Unit(s) play a targeted sound)**

`Unit`

`Extra2`

* **150 - AI_GROUP_UNIT_PLAY_TARGETED_MUSIC - (Unit(s) play targeted music)**

`Unit`

`Extra2`

* **151 - AI_GROUP_UNIT_RESET_INITIAL_SPELL_COOLDOWNS - (Unit(s) reset initial spell cooldowns)**

`Unit`

* **152 - AI_GROUP_UNIT_NO_MELEE - (Set "No Melee" flag for unit(s) in the group)**

`Unit`

`Extra2`

* **153 - AI_GROUP_UNIT_NO_MELEE_RESET - (Reset "No Melee" flag for unit(s) in the group)**

`Unit`

* **154 - AI_GROUP_FALL_TO_THE_GROUND - (Fall to the ground)**

*No parameters*

* **155 - AI_GROUP_UNIT_UPDATE_INTERACTION - (Unit(s) update interaction)**

`Unit`

* **156 - AI_GROUP_UNIT_BOSS_WHISPER - (Unit(s) boss whispers someone)**

`Unit`

`Extra2`

`Extra3`

* **157 - AI_GROUP_UNIT_BOSS_WHISPER_RANDOM - (Unit(s) boss whispers someone randomly)**

`Unit`

`Extra2`

`Extra3`

* **158 - AI_GROUP_MOVE_RELATIVE_CURRENT_FACING - (Move relative to current facing)**

`TimeA`

`MoveSpeed`

`Extra0` (Pitch / Elevation): Controls the vertical angle (up/down) in degrees:

```txt
0 = Flat/Horizontal (ground level)
> 0 (Positive) = Aimed upward
< 0 (Negative) = Aimed downward
```

`Extra1` (Yards to Move): The total length/magnitude of the movement in yards.

`Extra2` (Move Angle / Direction): Controls the horizontal heading in degrees. The angle is relative to the creature's current facing direction:

```txt
0 = Directly ahead (forward)
180 = Directly behind (backward)
90 = Directly to the creature's left
270 = Directly to the creature's right
```

`Extra3`

`Extra4`

Reference Table for Common Behaviors:

| Movement Scenario | Extra0 (Pitch) | Extra2 (Move Angle) |
| :--- | :---: | :---: |
| **Straight Forward** | 0 | 0 |
| **Straight Backward** | 0 | 180 |
| **Strafe Left** | 0 | 90 |
| **Strafe Right** | 0 | 270 |
| **Diagonal Forward-Left** | 0 | 45 |
| **Diagonal Forward-Right** | 0 | 315 |
| **Diagonal Backward-Left** | 0 | 135 |
| **Diagonal Backward-Right** | 0 | 225 |
| **Straight Up** | 90 | 0 |
| **Straight Down** | -90 | 0 |
| **Backward Up** | 45 | 180 |
| **Strafe Left Up** | 45 | 90 |
| **Strafe Right Up** | 45 | 270 |
| **Diagonal Forward-Left Up** | 45 | 45 |
| **Diagonal Forward-Right Up** | 45 | 315 |
| **Backward-Left Up** | 45 | 135 |
| **Backward-Right Up** | 45 | 225 |
| **Backward Down** | -45 | 180 |
| **Strafe Left Down** | -45 | 90 |
| **Strafe Right Down** | -45 | 270 |
| **Diagonal Forward-Left Down** | -45 | 45 |
| **Diagonal Forward-Right Down** | -45 | 315 |
| **Backward-Left Down** | -45 | 135 |
| **Backward-Right Down** | -45 | 225 |

* **159 - AI_GROUP_UNIT_DONT_CLEAR_TAP - (Unit(s) don't clear tap when leaving combat)**

`Unit`

* **160 - AI_GROUP_UNIT_KILL_CREDIT_TAP - (Unit(s) assign kill credit to tap list)**

`Unit`

`Extra2`

* **161 - AI_GROUP_UNIT_CAST_WITH_POINTS - (Unit(s) cast a spell with points)**

`Unit`

`StringId`

`Extra0`

`Extra2`

`Extra3`

* **162 - AI_GROUP_UNIT_RIDE_VEHICLE - (Unit(s) ride a vehicle)**

`Unit`

`StringId`

`Extra0`

`Extra2`

`Extra3`

* **163 - AI_GROUP_UNIT_ABANDON_VEHICLE - (Unit(s) abandon their vehicles)**

`Unit`

* **164 - AI_GROUP_VEHICLE_RECALL_OR_RESPAWN_PASSENGERS - (Vehicle(s) recall or respawn each passenger)**

`Unit`

`MoveSpeed`

`StringId`

`Extra0`

`Extra1`

`Extra3`

* **165 - AI_GROUP_PLAY_MOVIE - (Target player plays a movie file)**

`Unit`

`Extra2`

* **166 - AI_GROUP_JUMP_POINT - (Jump to a point)**

`Point`

`MoveSpeed`

`StringId`

`Extra0`

`Extra1`

`Extra2`

`Extra3`

* **167 - AI_GROUP_JUMP_GUID - (Jump to an object or unit)**

`MoveSpeed`

`StringId`

`Extra0`

`Extra1`

`Extra2`

`Extra3`

* **168 - AI_GROUP_MOVETO_THEN_JUMP - (Move to a point, then jump to end of path)**

`Path`

`MoveSpeed`

`LinearPath`

`Extra0`

`Extra1`

`Extra3`

* **169 - AI_GROUP_VEHICLE_RECALL_LIVING_PASSENGERS - (Vehicle(s) recall each living passenger)**

`Unit`

`MoveSpeed`

`StringId`

`Extra0`

`Extra1`

`Extra3`

* **170 - AI_GROUP_VEHICLE_RESPAWN_ALL_PASSENGERS - (Vehicle(s) respawn all passengers)**

`Unit`

`StringId`

`Extra0`

`Extra3`

* **171 - AI_GROUP_UNIT_FATAL_FALL_DISTANCE - (Unit(s) Set fatal fall distance)**

`Unit`

`Extra1`

* **172 - AI_GROUP_UNIT_FATAL_FALL_DISTANCE_RESET - (Unit(s) Reset fatal fall distance)**

`Unit`

* **173 - AI_GROUP_UNIT_SET_ANIMATION_TIER - (Unit(s) Set Animation/Movement Tier)**

`Unit`

`Extra2`

* **174 - AI_GROUP_UNIT_SEND_TAP_LIST - (Unit(s) send their tap list to another unit)**

`Unit`

`StringId`

`Extra0`

* **175 - AI_GROUP_UNIT_GET_TAP_LIST - (Unit(s) get their tap list from another unit)**

`Unit`

`StringId`

`Extra0`

* **176 - AI_GROUP_UNIT_HOVER_HEIGHT - (Unit(s) set their hover height)**

`Unit`

`Extra1`

* **177 - AI_GROUP_UNIT_HOVER_HEIGHT_RESET - (Unit(s) Reset their hover height)**

`Unit`

* **178 - AI_GROUP_TIER_TRANSITION_LAND - (Tier Transition Land)**

`MoveSpeed`

`Extra2`

`Extra3`

* **179 - AI_GROUP_TIER_TRANSITION_TAKE_OFF - (Tier Transition Take off)**

`MoveSpeed`

`Extra1`

`Extra2`

`Extra3`

* **180 - AI_GROUP_TIER_TRANSITION_MOVETO - (Tier Transition Move To)**

`Point`

`MoveSpeed`

`StringId`

`FlightPath`

`Extra0`

`Extra2`

`Extra3`

* **181 - AI_GROUP_TIER_TRANSITION_MOVETO_GUID - (Tier Transition Move To a Unit or Game Object)**

`MoveSpeed`

`StringId`

`FlightPath`

`Extra0`

`Extra1`

`Extra2`

`Extra3`

* **182 - AI_GROUP_TIER_TRANSITION_FOLLOW_PATH - (Tier Transition Follow Path)**

`Path`

`MoveSpeed`

`LinearPath`

`FlightPath`

`Extra2`

`Extra3`

* **183 - AI_GROUP_UNIT_KILL_CREDIT_PLAYER - (Unit(s) assign kill credit to player)**

`Unit`

`Extra2`

* **184 - AI_GROUP_SUSPEND_TRIGGER_ACTION - (Suspend Trigger action (creature action only))**

`TimeA`

`TimeB`

* **185 - AI_GROUP_UNIT_VEHICLE_RECORD - (Unit(s) change their vehicle record ID)**

`Unit`

`Extra2`

* **186 - AI_GROUP_UNIT_VEHICLE_RECORD_RESET - (Unit(s) reset their vehicle record ID)**

`Unit`

* **187 - AI_GROUP_UNIT_IMMUNITIES - (Unit(s) change their creature immunity template ID)**

`Unit`

`Extra2`

* **188 - AI_GROUP_UNIT_IMMUNITIES_RESET - (Unit(s) reset their creature immunity template ID)**

`Unit`

* **189 - AI_GROUP_SEND_CONTENT_ALERT - (Send a content alert)**

`Unit`

* **190 - AI_GROUP_UNIT_SAY_PLAYER - (Unit(s) says something only to a player)**

`Unit`

`Extra2`

`Extra4`

* **191 - AI_GROUP_UNIT_YELL_PLAYER - (Unit(s) yells something only to a player)**

`Unit`

`Extra2`

`Extra4`

* **192 - AI_GROUP_UNIT_START_QUEST - (Unit(s) starts a quest)**

`Unit`

`Extra2`

* **193 - AI_GROUP_UNIT_SAY_PLAYER_RANDOM - (Unit(s) says something random only to a player)**

`Unit`

`Extra2`

* **194 - AI_GROUP_UNIT_YELL_PLAYER_RANDOM - (Unit(s) yells something random only to a player)**

`Unit`

`Extra2`

* **195 - AI_GROUP_UNIT_START_LOOPING_ANIM_KIT - (Unit(s) start a looping anim kit)**

`Unit`

`Extra2`

* **196 - AI_GROUP_UNIT_STOP_LOOPING_ANIM_KIT - (Unit(s) stop their looping anim kit)**

`Unit`

* **197 - AI_GROUP_UNIT_PLAY_ONESHOT_ANIM_KIT - (Unit(s) play a one-shot anim kit)**

`Unit`

`Extra2`

* **198 - AI_GROUP_UNIT_SET_MOVEMENT_ANIM_KIT - (Unit(s) set their movement anim kit)**

`Unit`

`Extra2`

* **199 - AI_GROUP_UNIT_SET_MELEE_ANIM_KIT - (Unit(s) set their melee anim kit)**

`Unit`

`Extra2`

* **200 - AI_GROUP_UNIT_INTERACT_SPELL - (Set InteractSpell for unit(s) in the group)**

`Unit`

`Extra2`

* **201 - AI_GROUP_UNIT_INTERACT_SPELL_RESET - (Reset InteractSpell for unit(s) in the group)**

`Unit`

* **202 - AI_GROUP_UNIT_INTERACT_SPELL_CONDITION - (Set InteractSpellCondition for unit(s) in the group)**

`Unit`

`Extra2`

* **203 - AI_GROUP_UNIT_INTERACT_SPELL_CONDITION_RESET - (Reset InteractSpellCondition for unit(s) in the group)**

`Unit`

* **204 - AI_GROUP_UNIT_NO_NPC_DAMAGE_BELOW_85_PTC - (Set "No NPC damage below 85%" flag for unit(s))**

`Unit`

`Extra2`

* **205 - AI_GROUP_UNIT_NO_NPC_DAMAGE_BELOW_85_PTC_RESET - (Reset "No NPC damage below 85%" flag for unit(s))**

`Unit`

* **206 - AI_GROUP_UNIT_FACE_ANGLE_RELATIVE - (Unit(s) face angle relative to current)**

`Unit`

`Extra2`

* **207 - AI_GROUP_UNIT_BOSS_UNIT_FRAMES_PRIORITY - (Unit(s) sets his boss unit frames priority)**

`Unit`

`Extra2`

* **208 - AI_GROUP_UNIT_BOSS_UNIT_FRAMES_PRIORITY_RESET - (Unit(s) resets his boss unit frames priority)**

`Unit`

* **209 - AI_GROUP_UNIT_NO_THREAT_FEEDBACK - (Set "No Threat Feedback" flag for unit(s))**

`Unit`

`Extra2`

* **210 - AI_GROUP_UNIT_NO_THREAT_FEEDBACK_RESET - (Reset "No Threat Feedback" flag for unit(s))**

`Unit`

* **211 - AI_GROUP_UNIT_CHAT_EMOTE_PLAYER - (Unit(s) chat emote something to a player)**

`Unit`

`Extra2`

* **212 - AI_GROUP_UNIT_CHAT_EMOTE_PLAYER_RANDOM - (Unit(s) chat emote something random to a player)**

`Unit`

`Extra2`

* **213 - AI_GROUP_UNIT_EMOTE_PLAYER - (Unit(s) perform an emote to a player)**

`Unit`

`Extra2`

* **214 - AI_GROUP_UNIT_SET_QUEST_LOOT - (Set the quest loot for a unit)**

`Unit`

`Extra2`

* **215 - AI_GROUP_UNIT_CAST_RANDOM_UNIT - (Unit(s) cast a spell on a random unit)**

`Unit`

`StringId`

`Extra0`

`Extra2`

* **216 - AI_GROUP_UNIT_CAST_RANDOM_PLAYER - (Unit(s) cast a spell on a random player)**

`Unit`

`StringId`

`Extra0`

`Extra2`

* **217 - AI_GROUP_UNIT_CAST_OTHER_UNIT - (Unit(s) tell some other unit to cast a spell)**

`Unit`

`StringId`

`Extra0`

`Extra2`

`Extra4`

* **218 - AI_GROUP_MOVE_CIRCLE_RELATIVE - (Move in a circle relative to position)**

`TimeA`

`MoveSpeed`

`Extra0`

`Extra1`

`Extra2`

`Extra3`

`Extra4`

* **219 - AI_GROUP_RETURN_HOME_INSTANTLY - (Move everybody back to spawn positions instantly)**

*No parameters*

* **220 - AI_GROUP_ABORT_ACTION_SET_NO_STRINGID - (Abort action set if stringID is not found)**

`StringId`

`Extra0`

* **221 - AI_GROUP_ABORT_ACTION_SET_COMBAT_CONDITION_TRUE - (Abort action set if combat condition is true)**

`Extra2`

* **222 - AI_GROUP_FORCE_COMBAT - (Force combat with a unit)**

`StringId`

`Extra0`

`Extra1`

`Extra2`

`Extra3`

`Extra4`

* **223 - AI_GROUP_STOP_FORCE_COMBAT - (Stop Force combat)**

*No parameters*

* **224 - AI_GROUP_UNIT_UNTARGETABLE_BY_CLIENT - (Unit(s) Set Untargetable By Client)**

`Unit`

`Extra2`

* **225 - AI_GROUP_UNIT_UNTARGETABLE_BY_CLIENT_RESET - (Unit(s) Reset Untargetable By Client)**

`Unit`

* **226 - AI_GROUP_UNIT_NO_MELEE_APPROACH - (Set "No Melee Approach" flag for unit(s) in the group)**

`Unit`

`Extra2`

* **227 - AI_GROUP_UNIT_NO_MELEE_APPROACH_RESET - (Reset "No Melee Approach" flag for unit(s) in the group)**

`Unit`

* **228 - AI_GROUP_UNIT_RAID_LOCK_TAP_LIST - (Unit(s) Raid Lock everyone on their tap list)**

`Unit`

`Extra2`

* **229 - AI_GROUP_UNIT_CANNOT_TURN - (Set "Cannot Turn" flag for unit(s) in the group)**

`Unit`

`Extra2`

* **230 - AI_GROUP_UNIT_CANNOT_TURN_RESET - (Reset "Cannot Turn" flag for unit(s) in the group)**

`Unit`

* **231 - AI_GROUP_UNIT_PREFER_NPCS_ENEMIES - (Set "Prefer NPCs When Searching For Enemies" flag for unit(s) in the group)**

`Unit`

`Extra2`

* **232 - AI_GROUP_UNIT_PREFER_NPCS_ENEMIES_RESET - (Reset "Prefer NPCs When Searching For Enemies" flag for unit(s) in the group)**

`Unit`

* **233 - AI_GROUP_OBJECT_FACTION - (Change faction template for object(s))**

`Unit`

`Extra2`

* **234 - AI_GROUP_OBJECT_FACTION_RESET - (Reset faction template for object(s))**

`Unit`

* **235 - AI_GROUP_UNIT_PERFORM_SPELL_VISUAL_KIT - (Unit(s) perform spell visual kit on self)**

`Unit`

`TimeA`

`TimeB`

`Extra0`

`Extra2`

* **236 - AI_GROUP_UNIT_PERFORM_SPELL_VISUAL - (Unit(s) perform spell visual)**

`Unit`

`StringId`

`Extra0`

`Extra2`

`Extra3`

* **237 - AI_GROUP_UNIT_PERFORM_SPELL_VISUAL_ACTIONS - (Unit(s) perform spell visual and trigger actions)**

`Unit`

`StringId`

`Extra0`

`Extra2`

`Extra3`

`Extra4`

* **238 - AI_GROUP_UNIT_NO_LEAVECOMBAT_STATE_RESTORE - (Unit(s) Set "No LeaveCombat State Restore" flag)**

`Unit`

`Extra2`

* **239 - AI_GROUP_OBJECT_STRINGID - (Set the string ID for object(s))**

`Unit`

`StringId`

`Extra2`

* **240 - AI_GROUP_OBJECT_STRINGID_RESET - (Reset the string ID for object(s))**

`Unit`

`Extra2`

* **241 - AI_GROUP_UNIT_DESPAWN_PERSISTENT_AURA_OBJECTS - (Unit(s) despawn persistent area aura objects)**

`Unit`

`Extra0`

* **242 - AI_GROUP_UNIT_DEFAULT_MOUNT - (Unit(s) set the default mount)**

`Unit`

`Extra2`

* **243 - AI_GROUP_UNIT_DEFAULT_MOUNT_RESET - (Unit(s) reset the default mount)**

`Unit`

* **244 - AI_GROUP_ABORT_ACTION_SET_FOUND_STRINGID - (Abort action set if stringID is found)**

`StringId`

`Extra0`

* **245 - AI_GROUP_UNSUPPRESS_NPC_GREETINGS - (NPC Greetings - Un-Suppress them)**

*No parameters*

* **246 - AI_GROUP_SUPPRESS_NPC_GREETINGS - (NPC Greetings - Suppress Them)**

*No parameters*

* **247 - AI_GROUP_UNIT_CLEAR_BOSS_EMOTES - (Unit(s) clears boss emotes)**

`Unit`

`Extra0`

* **248 - AI_GROUP_UNIT_CLEAR_BOSS_EMOTES_ZONE - (Unit(s) clears boss emotes for the zone)**

`Unit`

`Extra4`

* **249 - AI_GROUP_UNIT_CLEAR_BOSS_EMOTES_PLAYER - (Unit(s) clears boss emotes for a player)**

`Unit`

* **250 - AI_GROUP_UNIT_INTERACT_WHILE_HOSTILE - (Unit(s) Set Interact While Hostile)**

`Unit`

`Extra2`

* **251 - AI_GROUP_UNIT_INTERACT_WHILE_HOSTILE_RESET - (Unit(s) Reset Interact While Hostile)**

`Unit`

* **252 - AI_GROUP_UNIT_MODEL_HIGHLIGHT_SUPPRESSION - (Unit(s) set the model highlight suppression)**

`Unit`

`Extra2`

* **253 - AI_GROUP_UNIT_MODEL_HIGHLIGHT_SUPPRESSION_RESET - (Unit(s) reset the model highlight suppression)**

`Unit`

* **254 - AI_GROUP_FOLLOW_TAXI_PATH - (Follow a taxi path)**

`MoveSpeed`

`LinearPath`

`Extra2`

`Extra3`

`Extra4`

* **255 - AI_GROUP_FOLLOW_TAXI_PATH_RELATIVE - (Follow a taxi path relative)**

`MoveSpeed`

`LinearPath`

`Extra0`

`Extra1`

`Extra2`

`Extra3`

`Extra4`

* **256 - AI_GROUP_START_DUNGEON_ENCOUNTER - (Start a Dungeon Encounter)**

`Extra2`

* **257 - AI_GROUP_END_DUNGEON_ENCOUNTER - (End a Dungeon Encounter)**

`Extra2`

`Extra4`

* **258 - AI_GROUP_UNIT_WILD_BATTLEPET_LEVEL - (Unit(s) set Wild BattlePet Level)**

`Unit`

`Extra2`

* **259 - AI_GROUP_UNIT_WILD_BATTLEPET_LEVEL_RESET - (Unit(s) reset Wild BattlePet Level)**

`Unit`

* **260 - AI_GROUP_UNIT_TRACK_PLAYER_STAT - (Unit(s) track player stat)**

`Unit`

`Extra2`

`Extra4`

* **261 - AI_GROUP_UNIT_CANNOT_PENETRATE_WATER - (Set "Cannot Penetrate Water" flag for unit(s) in the group)**

`Unit`

`Extra2`

* **262 - AI_GROUP_UNIT_CANNOT_PENETRATE_WATER_RESET - (Reset "Cannot Penetrate Water" flag for unit(s) in the group)**

`Unit`

* **263 - AI_GROUP_UNIT_DESPAWN_STRINGID - (Unit(s) Despawn units/objects matching string ID)**

`Unit`

`StringId`

`Extra0`

* **264 - AI_GROUP_UNIT_SET_SAFE_LOCATION - (Unit(s) Set Safe Location)**

`StringId`

* **265 - AI_GROUP_UNIT_TREAT_UNIT_AS_RAID_UNIT - (Set "Treat Unit As Raid Unit" flag for unit(s))**

`Unit`

`Extra2`

* **266 - AI_GROUP_UNIT_TREAT_UNIT_AS_RAID_UNIT_RESET - (Reset "Treat Unit As Raid Unit" flag for unit(s))**

`Unit`

* **267 - AI_GROUP_UNIT_DESPAWN_SUMMONED_AREA_TRIGGERS - (Unit(s) Despawn all summoned area triggers)**

`Unit`

`Extra0`

* **268 - AI_GROUP_UNIT_ADD_PERMANENT_WORLD_EFFECT - (Add permanent World Effect to unit(s))**

`Unit`

`Extra2`

* **269 - AI_GROUP_UNIT_REMOVE_PERMANENT_WORLD_EFFECT - (Remove permanent World Effect from unit(s))**

`Unit`

`Extra2`

* **270 - AI_GROUP_UNIT_CAST_WITH_POINTS_OTHER_UNIT - (Unit(s) tell some other unit to cast a spell with points)**

`Unit`

`StringId`

`Extra0`

`Extra2`

`Extra3`

`Extra4`

* **271 - AI_GROUP_UNIT_SET_ANCHOR_POINT - (Unit(s) Set Anchor Point)**

`Unit`

* **272 - AI_GROUP_CIRCLE_UNIT - (Circle a Unit)**

`TimeA`

`MoveSpeed`

`StringId`

`Extra0`

`Extra1`

`Extra2`

`Extra3`

`Extra4`

* **273 - AI_GROUP_RUN_SPELL_SCRIPT - (Run a spell script)**

`Point`

`StringId`

`Extra2`

`Extra3`

* **274 - AI_GROUP_TURN_IN_PLACE_DEGREES - (Turn in Place(Degrees))**

`Unit`

`Extra2`

`Extra3`

`Extra4`

* **275 - AI_GROUP_TURN_IN_PLACE_TIMED - (Turn in Place(Timed))**

`Unit`

`TimeA`

`TimeB`

`Extra2`

`Extra3`

* **276 - AI_GROUP_UNIT_PREFER_UNENGAGED_TARGETS - (Set "Prefer Unengaged Targets" flag for unit(s) in the group)**

`Unit`

`Extra2`

* **277 - AI_GROUP_UNIT_GENERATE_SPAWNGROUP_EVENT - (Unit(s) in the group generates a spawngroup event)**

`Unit`

`StringId`

`Extra0`

`Extra2`

* **278 - AI_GROUP_PUSH_ACTIONSET - (Push Actionset)**

`StringId`

`Extra0`

`Extra2`

* **279 - AI_GROUP_MOVE_ON_PATH_GRAPH_TO_POINT - (Move on path graph to point)**

`Point`

`MoveSpeed`

`StringId`

`Extra0`

`Extra1`

`Extra2`

`Extra3`

`Extra4`

* **280 - AI_GROUP_TRIGGER_ACTIONS_ON_SELF - (Trigger actions on self)**

`Unit`

`Extra2`

* **281 - AI_GROUP_UNIT_EJECT_PASSENGER - (Unit(s) eject passenger)**

`Unit`

`Extra2`

* **282 - AI_GROUP_PERFORM_ACTIONSET - (Perform actionset)**

`Extra2`

`Extra4`

* **283 - AI_GROUP_UNIT_PAUSE_SPELL_COOLDOWNS - (Unit(s) Pause Spell Cooldowns)**

`Unit`

* **284 - AI_GROUP_UNIT_RESUME_SPELL_COOLDOWNS - (Unit(s) Resume Spell Cooldowns)**

`Unit`

* **285 - AI_GROUP_UNIT_TRIGGER_SPELL_CATEGORY_COOLDOWN - (Unit(s) Trigger a Spell Category Cooldown)**

`Unit`

`Extra2`

`Extra3`

* **286 - AI_GROUP_UNIT_PLAY_SOUND_ON_ITSELF_SPEAKERBOT - (Unit(s) Plays a sound on itself [Speakerbot])**

`Unit`

`Extra0`

`Extra2`

* **287 - AI_GROUP_UNIT_STOP_SPEAKERBOT_SOUND - (Unit(s) Stops the [Speakerbot] sound it is playing)**

`Unit`

`Extra0`

* **288 - AI_GROUP_UNIT_BECOME_PERSONAL_INVIS_CLONE - (Unit(s) Becomes a personal invis clone for triggering player)**

`Unit`

* **289 - AI_GROUP_MOVE_ON_PATH_GRAPH_TO_GUID - (Move on path graph to unit or game object)**

`TimeA`

`MoveSpeed`

`StringId`

`Extra0`

`Extra1`

`Extra2`

`Extra3`

`Extra4`

* **290 - AI_GROUP_MOVE_ON_PATH_GRAPH_MULTIPLE_POINTS - (Move on path graph - multiple points)**

`Path`

`MoveSpeed`

`LinearPath`

`Extra2`

`Extra3`

`Extra4`

* **291 - AI_GROUP_UNIT_NEVER_EVADE - (Unit(s) "Never Evade" flag)**

`Unit`

`Extra2`

* **292 - AI_GROUP_UNIT_NEVER_EVADE_RESET - (Reset Unit(s) "Never Evade" flag)**

`Unit`

* **293 - AI_GROUP_UNIT_DONT_LEAVE_COMBAT - (Unit(s) Set "Don't leave combat" flag)**

`Unit`

`Extra2`

* **294 - AI_GROUP_UNIT_CANCEL_CURRENT_SPELL - (Unit(s) Cancel Current Spell)**

`Unit`

* **295 - AI_GROUP_UNIT_SAY_GAME_REGION - (Unit(s) say something to the entire game region)**

`Unit`

`Extra2`

* **296 - AI_GROUP_UNIT_SAY_GAME_REGION_RANDOM - (Unit(s) say something random to the entire game region)**

`Unit`

`Extra2`

* **297 - AI_GROUP_UNIT_YELL_GAME_REGION - (Unit(s) yell something to the entire game region)**

`Unit`

`Extra2`

* **298 - AI_GROUP_UNIT_YELL_GAME_REGION_RANDOM - (Unit(s) yell something random to the entire game region)**

`Unit`

`Extra2`

* **299 - AI_GROUP_COMBAT_POSITION - (Combat Position)**

`StringId`

`Extra0`

`Extra1`

`Extra2`

`Extra4`

* **300 - AI_GROUP_COMBAT_CHASE - (Combat Chase)**

`StringId`

`Extra0`

`Extra1`

`Extra2`

* **301 - AI_GROUP_UNIT_DONT_DISMISS_ON_FLYING_MOUNT - (Set "Don't Dismiss On Flying Mount" for unit(s))**

`Unit`

`Extra2`

* **302 - AI_GROUP_UNIT_DONT_DISMISS_ON_FLYING_MOUNT_RES - (Reset "Don't Dismiss On Flying Mount" for unit(s))**

`Unit`
