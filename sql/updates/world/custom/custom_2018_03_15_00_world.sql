-- Creature Lord Darius Crowley 35077 SAI
SET @ENTRY := 35077;
UPDATE `creature_template` SET `InhabitType`= 9 WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 19, 0, 100, 0, 14154, 0, 0, 0, 11, 66914, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "When player accepts quest 14154 - Self: Cast spell 66914 on Action invoker // "),
(@ENTRY, 0, 1, 0, 0, 0, 100, 0, 6000, 6000, 15000, 17000, 11, 67825, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 6000 and 6000 ms (and later repeats every 15000 and 17000 ms) - Self: Cast spell 67825 on Victim // ");

-- Creature Gilnean Royal Guard 35232 SAI
SET @ENTRY := 35232;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 0, 0, 1000, 1000, 49, 0, 0, 0, 0, 0, 0, 11, 35118, 7, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 0 and 0 ms (and later repeats every 1000 and 1000 ms) - Self: Attack Creature Bloodfang Worgen (35118) in 7 yd // ");

-- Creature Prince Liam Greymane 34913 SAI
SET @ENTRY := 34913;
UPDATE `creature_template` SET `AIName`="SmartAI", `InhabitType`= 9 WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 4, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On aggro - Self: Talk 0 // "),
(@ENTRY, 0, 1, 0, 9, 0, 100, 0, 5, 50, 2000, 2000, 11, 50092, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When victim in range 5 - 50 yards (check every 2000 - 2000 ms) - Self: Cast spell 50092 on Victim // ");
