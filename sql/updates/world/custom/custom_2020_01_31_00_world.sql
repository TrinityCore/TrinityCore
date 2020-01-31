UPDATE `creature_template` SET `VehicleId`= 899 WHERE `entry`= 42500;
DELETE FROM `creature_template_movement` WHERE `CreatureId`= 42500;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Flight`, `Rooted`) VALUES
(42500, 0, 1, 1);

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`= 42500;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(42500, 46598, 1, 0);

-- Creature Two-Shoed Lou's Old House 42500 SAI
SET @ENTRY := 42500;
UPDATE `creature_template` SET `AIName`="SmartAI", `unit_flags`= 520 WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 80, 4250000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When just created - Start timed action list id #4250000 // "),
(@ENTRY, 0, 1, 0, 28, 0, 100, 0, 0, 0, 0, 0, 11, 79274, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "On passenger removed (vehicle) - Self: Cast spell Force Despawn Jangolode Actors (79274) on Action invoker // ");

-- TimedActionList  4250000 SAI
SET @ENTRY := 4250000;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 9300, 9300, 0, 0, 11, 79290, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 9300 and 9300 ms (and later repeats every 0 and 0 ms) - Self: Cast spell General Trigger 1: Glubtok (79290) on Self // "),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 6500, 6500, 0, 0, 11, 79279, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 6500 and 6500 ms (and later repeats every 0 and 0 ms) - Self: Cast spell General Trigger 1: Figure (79279) on Self // "),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 11, 79292, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 8000 and 8000 ms (and later repeats every 0 and 0 ms) - Self: Cast spell General Trigger 2: Glubtok (79292) on Self // "),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 11, 79283, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 4000 and 4000 ms (and later repeats every 0 and 0 ms) - Self: Cast spell General Trigger 2: Figure (79283) on Self // "),
(@ENTRY, 9, 4, 0, 0, 0, 100, 0, 16000, 16000, 0, 0, 11, 79294, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 16000 and 16000 ms (and later repeats every 0 and 0 ms) - Self: Cast spell General Trigger 3: Glubtok (79294) on Self // "),
(@ENTRY, 9, 5, 0, 0, 0, 100, 0, 4100, 4100, 0, 0, 11, 79284, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 4100 and 4100 ms (and later repeats every 0 and 0 ms) - Self: Cast spell General Trigger 3: Figure (79284) on Self // "),
(@ENTRY, 9, 6, 0, 0, 0, 100, 0, 6400, 6400, 0, 0, 11, 79297, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 6400 and 6400 ms (and later repeats every 0 and 0 ms) - Self: Cast spell General Trigger 4: Glubtok (79297) on Self // "),
(@ENTRY, 9, 7, 0, 0, 0, 100, 0, 11400, 11400, 0, 0, 11, 79287, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 11400 and 11400 ms (and later repeats every 0 and 0 ms) - Self: Cast spell General Trigger 4: Figure (79287) on Self // ");

-- Creature Shadowy Figure 42515 SAI
SET @ENTRY := 42515;
UPDATE `creature_template` SET `AIName`="SmartAI", `unit_flags`= 33587976 WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 63, 0, 100, 0, 0, 0, 0, 0, 59, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When just created - Self: Set walk // "),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -9841.68, 1400.04, 37.1295, 0, " Linked - Self: Move to position (-9841.68, 1400.04, 37.1295, 0) (point id 0) // "),
(@ENTRY, 0, 2, 0, 8, 0, 100, 0, 79273, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell Despawn Jangolode Actors (79273) hit  - Self: Despawn instantly // "),
(@ENTRY, 0, 3, 4, 8, 0, 100, 0, 79279, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell General Trigger 1: Figure (79279) hit  - Self: Talk 0 // "),
(@ENTRY, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 128, 610, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Plays Anim with ID 610 // "),
(@ENTRY, 0, 5, 0, 8, 0, 100, 0, 79283, 0, 0, 0, 80, 4251500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell General Trigger 2: Figure (79283) hit  - Start timed action list id #4251500 // "),
(@ENTRY, 0, 6, 0, 8, 0, 100, 0, 79284, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell General Trigger 3: Figure (79284) hit  - Self: Talk 3 // "),
(@ENTRY, 0, 7, 0, 8, 0, 100, 0, 79287, 0, 0, 0, 80, 4251501, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell General Trigger 4: Figure (79287) hit  - Start timed action list id #4251501 // ");

-- TimedActionList  4251500 SAI
SET @ENTRY := 4251500;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 9, 0, 1, 0, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 0 and 0 ms (and later repeats every 0 and 0 ms) - Self: Talk 1 // "),
(@ENTRY, 9, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 128, 593, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Plays Anim with ID 593 // "),
(@ENTRY, 9, 2, 3, 0, 0, 100, 0, 8000, 8000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 8000 and 8000 ms (and later repeats every 0 and 0 ms) - Self: Talk 2 // "),
(@ENTRY, 9, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 128, 606, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Plays Anim with ID 606 // ");

-- TimedActionList  4251501 SAI
SET @ENTRY := 4251501;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 0 and 0 ms (and later repeats every 0 and 0 ms) - Self: Talk 4 // "),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 8000 and 8000 ms (and later repeats every 0 and 0 ms) - Self: Talk 5 // "),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 2500, 2500, 0, 0, 11, 79275, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 2500 and 2500 ms (and later repeats every 0 and 0 ms) - Self: Cast spell Quest Credit: Jangolode Event (79275) on Self // "),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 24222, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 0 and 0 ms (and later repeats every 0 and 0 ms) - Self: Cast spell Vanish Visual (24222) on Self // ");

-- Creature Glubtok 42492 SAI
SET @ENTRY := 42492;
UPDATE `creature_template` SET `AIName`="SmartAI", `unit_flags`= 72 WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 60, 0, 100, 1, 1, 1, 0, 0, 11, 64195, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 0 and 0 ms (for the first time, timer between 1 and 1 ms) - Self: Cast spell Simple Teleport (64195) on Self // "),
(@ENTRY, 0, 1, 0, 8, 0, 100, 0, 79273, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell Despawn Jangolode Actors (79273) hit  - Self: Despawn instantly // "),
(@ENTRY, 0, 2, 0, 8, 0, 100, 0, 79290, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell General Trigger 1: Glubtok (79290) hit  - Self: Talk 0 // "),
(@ENTRY, 0, 3, 0, 8, 0, 100, 0, 79292, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell General Trigger 2: Glubtok (79292) hit  - Self: Talk 1 // "),
(@ENTRY, 0, 4, 0, 8, 0, 100, 0, 79294, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell General Trigger 3: Glubtok (79294) hit  - Self: Talk 2 // "),
(@ENTRY, 0, 5, 0, 8, 0, 100, 0, 79297, 0, 0, 0, 80, 4249200, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell General Trigger 4: Glubtok (79297) hit  - Start timed action list id #4249200 // ");

-- TimedActionList  4249200 SAI
SET @ENTRY := 4249200;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 0 and 0 ms (and later repeats every 0 and 0 ms) - Self: Talk 3 // "),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 8000 and 8000 ms (and later repeats every 0 and 0 ms) - Self: Talk 4 // ");


DELETE FROM `spell_scripts` WHERE `id`= 79262;
INSERT INTO `spell_scripts` (`id`, `effIndex`, `command`, `datalong`) VALUES
(79262, 1, 15, 79265),
(79262, 1, 15, 79263);

DELETE FROM `conditions` WHERE `SourceEntry` IN (79273, 79290, 79292, 79294, 79297, 79279, 79283, 79284, 79287) AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 79273, 0, 0, 31, 0, 3, 42515, 0, 0, 0, '', 'Despawn Jangolode Actors - Target Shadowy Figure'),
(13, 1, 79273, 0, 1, 31, 0, 3, 42492, 0, 0, 0, '', 'Despawn Jangolode Actors - Target Glubtok'),
(13, 1, 79290, 0, 0, 31, 0, 3, 42492, 0, 0, 0, '', 'General Trigger 1: Glubtok - Target Glubtok'),
(13, 1, 79292, 0, 0, 31, 0, 3, 42492, 0, 0, 0, '', 'General Trigger 2: Glubtok - Target Glubtok'),
(13, 1, 79294, 0, 0, 31, 0, 3, 42492, 0, 0, 0, '', 'General Trigger 3: Glubtok - Target Glubtok'),
(13, 1, 79297, 0, 0, 31, 0, 3, 42492, 0, 0, 0, '', 'General Trigger 4: Glubtok - Target Glubtok'),
(13, 1, 79279, 0, 0, 31, 0, 3, 42515, 0, 0, 0, '', 'General Trigger 1: Figure - Shadowy Figure'),
(13, 1, 79283, 0, 0, 31, 0, 3, 42515, 0, 0, 0, '', 'General Trigger 2: Figure - Shadowy Figure'),
(13, 1, 79284, 0, 0, 31, 0, 3, 42515, 0, 0, 0, '', 'General Trigger 3: Figure - Shadowy Figure'),
(13, 1, 79287, 0, 0, 31, 0, 3, 42515, 0, 0, 0, '', 'General Trigger 4: Figure - Shadowy Figure');

DELETE FROM `creature_text` WHERE `CreatureID` IN (42492, 42515);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `Comment`) VALUES
(42492, 0, 0, 'What little humie want? Why you call Glubtok?', 12, 0, 100, 396, 0, 0, 42418, 'Glubtok to Player'),
(42492, 1, 0, 'Glubtok crush you!', 12, 0, 100, 15, 0, 0, 42420, 'Glubtok to Player'),
(42492, 2, 0, 'What option two?', 12, 0, 100, 396, 0, 0, 42422, 'Glubtok to Player'),
(42492, 3, 0, 'So Glubtok have two choices: die or be rich and powerful?', 12, 0, 100, 396, 0, 0, 42425, 'Glubtok to Player'),
(42492, 4, 0, 'Glubtok take choice two.', 12, 0, 100, 396, 0, 0, 42427, 'Glubtok to Player'),
(42515, 0, 0, 'Sad... Is this the life that you had hoped for, Glubtok? Running two-bit extortion operations out of a cave?', 12, 0, 100, 0, 0, 0, 42419, 'Shadowy Figure to Player'),
(42515, 1, 0, 'Oh will you? Do you dare cross that line and risk your life?', 12, 0, 100, 0, 0, 0, 42421, 'Shadowy Figure to Player'),
(42515, 2, 0, 'You may attempt to kill me - and fail - or you may take option two.', 12, 0, 100, 0, 0, 0, 42423, 'Shadowy Figure to Player'),
(42515, 3, 0, 'You join me and I shower wealth and power upon you.', 12, 0, 100, 396, 0, 0, 42424, 'Shadowy Figure to Player'),
(42515, 4, 0, 'I thought you\'d see it my way.', 12, 0, 100, 153, 0, 0, 42428, 'Shadowy Figure to Player'),
(42515, 5, 0, 'I will call for you when the dawning is upon us.', 12, 0, 100, 397, 0, 0, 42429, 'Shadowy Figure to Player');

DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_westfall_quest_credit_jangolode_event';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(79275, 'spell_westfall_quest_credit_jangolode_event');

DELETE FROM `spawn_group` WHERE `spawnType`= 0 AND `spawnId` IN (275809, 280400, 308009);
