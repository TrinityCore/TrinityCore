-- Creature Glubtok 42492 SAI
SET @ENTRY := 42492;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When just created - Self: Set react state to REACT_PASSIVE // "),
(@ENTRY, 0, 1, 0, 60, 0, 100, 1, 1, 1, 0, 0, 11, 64195, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 0 and 0 ms (for the first time, timer between 1 and 1 ms) - Self: Cast spell Simple Teleport (64195) on Self // "),
(@ENTRY, 0, 2, 0, 8, 0, 100, 0, 79273, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell Despawn Jangolode Actors (79273) hit  - Self: Despawn instantly // "),
(@ENTRY, 0, 3, 0, 8, 0, 100, 0, 79290, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell General Trigger 1: Glubtok (79290) hit  - Self: Talk 0 // "),
(@ENTRY, 0, 4, 0, 8, 0, 100, 0, 79292, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell General Trigger 2: Glubtok (79292) hit  - Self: Talk 1 // "),
(@ENTRY, 0, 5, 0, 8, 0, 100, 0, 79294, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell General Trigger 3: Glubtok (79294) hit  - Self: Talk 2 // "),
(@ENTRY, 0, 6, 0, 8, 0, 100, 0, 79297, 0, 0, 0, 80, 4249200, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell General Trigger 4: Glubtok (79297) hit  - Start timed action list id #4249200 // ");
