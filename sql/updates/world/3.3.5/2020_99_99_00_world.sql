-- Creature Sneed 643 SAI - Add Set instance data line
SET @ENTRY := 643;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 2, 7900, 17600, 62000, 86200, 11, 6713, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Every 62 - 86.2 secs (7.9 - 17.6s initially) [IC] - Self: Cast spell 6713 on Victim // Sneed - In Combat - Cast 'Disarm' (No Repeat) (Normal Dungeon)"),
(@ENTRY, 0, 1, 0, 6, 0, 100, 0, 0, 0, 0, 0, 34, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "On death - Set instance data #2 to 3 // Sneed - On Just Died - Set Instance Data #2 to 3 (DONE)");

-- Creature Gilnid 1763 SAI - Add Set instance data line
SET @ENTRY := 1763;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 2, 120000, 120000, 120000, 120000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 120000 and 120000 ms (and later repeats every 120000 and 120000 ms) - Self: Talk 0 // Gilnid - Out of Combat - Say Line 0 (No Repeat) (Normal Dungeon)"),
(@ENTRY, 0, 1, 0, 0, 0, 100, 2, 2100, 4800, 23300, 44900, 11, 5213, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Every 23.3 - 44.9 secs (2.1 - 4.8s initially) [IC] - Self: Cast spell 5213 on Victim // Gilnid - In Combat - Cast 'Molten Metal' (No Repeat) (Normal Dungeon)"),
(@ENTRY, 0, 2, 0, 6, 0, 100, 0, 0, 0, 0, 0, 34, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "On death - Set instance data #3 to 3 // On just died - Set instance data #3 to 3 (DONE)");

-- Gameobject Door Lever 101832 SAI and change door entry
SET @ENTRY := 101832;
SET @GUID := (SELECT `guid` FROM `gameobject` WHERE `id` = 17153 AND `map` = 36 AND `position_x` > -295 AND `position_x` < -285 AND `position_y` > -540 AND `position_y` < -530 AND `position_z` > 45 AND `position_z` < 55);
SET @DOORENTRY := 16400;
UPDATE gameobject SET `id` = @DOORENTRY WHERE guid = @GUID AND `id` = 17153;
UPDATE `gameobject_template` SET `AIName`="SmartGameObjectAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 1, 0, 0, 70, 0, 100, 0, 2, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 14, @GUID, @DOORENTRY, 0, 0, 0, 0, 0, "On loot state changed to GO_ACTIVATED - Gameobject 26185: Activate (only gameobject; sets loot state to GO_READY) // Door Lever - On Gameobject State Changed - Activate Gameobject");

-- Gameobject Door Lever 101834 SAI and change door entry
SET @ENTRY := 101834;
SET @GUID := (SELECT `guid` FROM `gameobject` WHERE `id` = 17153 AND `map` = 36 AND `position_x` > -175 AND `position_x` < -160 AND `position_y` > -585 AND `position_y` < -575 AND `position_z` > 10 AND `position_z` < 20);
SET @DOORENTRY := 16399;
UPDATE gameobject SET `id` = @DOORENTRY WHERE guid = @GUID AND `id` = 17153;
UPDATE `gameobject_template` SET `AIName`="SmartGameObjectAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 1, 0, 0, 70, 0, 100, 0, 2, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 14, @GUID, @DOORENTRY, 0, 0, 0, 0, 0, "On loot state changed to GO_ACTIVATED - Gameobject 26182: Activate (only gameobject; sets loot state to GO_READY) // Door Lever - On Gameobject State Changed - Activate Gameobject");
