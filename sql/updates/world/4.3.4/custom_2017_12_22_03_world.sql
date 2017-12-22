-- Creature Oathsworn Axemaster 44922 SAI
SET @ENTRY := 44922;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 6000, 6500, 13000, 13000, 11, 84256, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 6000 and 6500 ms (and later repeats every 13000 and 13000 ms) - Self: Cast spell 84256 on Victim // "),
(@ENTRY, 0, 1, 0, 0, 0, 100, 0, 7200, 7700, 11000, 11000, 11, 82763, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 7200 and 7700 ms (and later repeats every 11000 and 11000 ms) - Self: Cast spell 82763 on Victim // ");

-- Creature Oathsworn Skinner 44981 SAI
SET @ENTRY := 44981;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 5000, 5000, 15500, 15700, 11, 82789, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 5000 and 5000 ms (and later repeats every 15500 and 15700 ms) - Self: Cast spell 82789 on Self // "),
(@ENTRY, 0, 1, 0, 0, 0, 100, 0, 10000, 10000, 7000, 7000, 11, 84031, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 10000 and 10000 ms (and later repeats every 7000 and 7000 ms) - Self: Cast spell 84031 on Victim // ");

-- Creature Oathsworn Wanderer 44926 SAI
SET @ENTRY := 44926;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 1, 1, 2000, 2000, 11, 83877, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 1 and 1 ms (and later repeats every 2000 and 2000 ms) - Self: Cast spell 83877 on Victim // "),
(@ENTRY, 0, 1, 0, 0, 0, 100, 0, 7000, 7000, 16000, 16500, 11, 82794, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 7000 and 7000 ms (and later repeats every 16000 and 16500 ms) - Self: Cast spell 82794 on Victim // ");

-- Creature Oathsworn Myrmidon 44924 SAI
SET @ENTRY := 44924;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 6400, 6500, 16000, 17000, 11, 82673, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 6400 and 6500 ms (and later repeats every 16000 and 17000 ms) - Self: Cast spell 82673 on Self // ");

-- Creature Neferset Plaguebringer 44976 SAI
SET @ENTRY := 44976;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 6800, 7000, 23000, 23000, 11, 73976, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 6800 and 7000 ms (and later repeats every 23000 and 23000 ms) - Self: Cast spell 73976 on Self // "),
(@ENTRY, 0, 1, 0, 0, 0, 100, 0, 8000, 8000, 15500, 16000, 11, 82768, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 8000 and 8000 ms (and later repeats every 15500 and 16000 ms) - Self: Cast spell 82768 on Random hostile (not top) // ");

-- Creature Neferset Torturer 44977 SAI
SET @ENTRY := 44977;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 5500, 5500, 30000, 31000, 11, 82750, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 5500 and 5500 ms (and later repeats every 30000 and 31000 ms) - Self: Cast spell 82750 on Random hostile (not top) // "),
(@ENTRY, 0, 1, 0, 0, 0, 100, 0, 7000, 7000, 25000, 25000, 11, 82744, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 7000 and 7000 ms (and later repeats every 25000 and 25000 ms) - Self: Cast spell 82744 on Victim // ");

-- Creature Oathsworn Pathfinder 44932 SAI
SET @ENTRY := 44932;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 1, 1, 2000, 2000, 11, 83877, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 1 and 1 ms (and later repeats every 2000 and 2000 ms) - Self: Cast spell 83877 on Victim // "),
(@ENTRY, 0, 1, 0, 0, 0, 100, 0, 9000, 9000, 12000, 12000, 11, 82764, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 9000 and 9000 ms (and later repeats every 12000 and 12000 ms) - Self: Cast spell 82764 on Victim // ");

-- Creature Pygmy Scout 314811 SAI
SET @ENTRY := -314811;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 1, 1, 12000, 12000, 5, 53, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 1 and 1 ms (and later repeats every 12000 and 12000 ms) - Self: Play emote 53 // "),
(@ENTRY, 0, 1, 0, 1, 0, 100, 0, 1000, 1000, 12000, 12000, 69, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -10968.2, -1477.91, 6.766029, 0, "When out of combat and timer at the begining between 1000 and 1000 ms (and later repeats every 12000 and 12000 ms) - Self: Move to None (point id 0) // "),
(@ENTRY, 0, 2, 0, 1, 0, 100, 0, 3500, 3500, 12000, 12000, 5, 53, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 3500 and 3500 ms (and later repeats every 12000 and 12000 ms) - Self: Play emote 53 // "),
(@ENTRY, 0, 3, 0, 1, 0, 100, 0, 5000, 5000, 12000, 12000, 69, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -10960.85, -1496.215, 6.935548, 0, "When out of combat and timer at the begining between 5000 and 5000 ms (and later repeats every 12000 and 12000 ms) - Self: Move to None (point id 0) // "),
(@ENTRY, 0, 4, 0, 1, 0, 100, 0, 7000, 7000, 12000, 12000, 5, 53, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 7000 and 7000 ms (and later repeats every 12000 and 12000 ms) - Self: Play emote 53 // "),
(@ENTRY, 0, 5, 0, 1, 0, 100, 0, 9500, 9500, 12000, 12000, 69, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -10957.5, 1485.63, 6.767189, 0, "When out of combat and timer at the begining between 9500 and 9500 ms (and later repeats every 12000 and 12000 ms) - Self: Move to None (point id 0) // "),
(@ENTRY, 0, 6, 0, 0, 0, 100, 0, 1, 1, 2700, 3000, 11, 83780, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 1 and 1 ms (and later repeats every 2700 and 3000 ms) - Self: Cast spell 83780 on Self // ");

-- Creature Pygmy Scout 44897 SAI
SET @ENTRY := 44897;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 54, 0, 100, 1, 0, 0, 0, 0, 67, 0, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "On just summoned - Trigger timed event #0 in 100 - 100 ms // "),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 12, 44898, 8, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Summon creature Pygmy Firebreather (44898) at Self, moved by offset (0, 0, 0, 0) // "),
(@ENTRY, 0, 2, 0, 59, 0, 100, 1, 0, 0, 0, 0, 11, 46598, 0, 0, 0, 0, 0, 11, 44896, 5, 0, 0, 0, 0, 0, "On timed event 0 triggered - Self: Cast spell 46598 on Creature Pygmy Brute (44896) in 5 yd // "),
(@ENTRY, 0, 3, 0, 0, 0, 100, 0, 1, 1, 2700, 3000, 11, 83780, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 1 and 1 ms (and later repeats every 2700 and 3000 ms) - Self: Cast spell 83780 on Self // ");

-- Creature Pygmy Firebreather 44898 SAI
SET @ENTRY := 44898;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 67, 0, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "On just summoned - Trigger timed event #0 in 100 - 100 ms // "),
(@ENTRY, 0, 1, 0, 59, 0, 100, 1, 0, 0, 0, 0, 11, 47020, 0, 0, 0, 0, 0, 11, 44897, 5, 0, 0, 0, 0, 0, "On timed event 0 triggered - Self: Cast spell 47020 on Creature Pygmy Scout (44897) in 5 yd // "),
(@ENTRY, 0, 2, 0, 0, 0, 100, 0, 5000, 6000, 18000, 18000, 11, 83776, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 5000 and 6000 ms (and later repeats every 18000 and 18000 ms) - Self: Cast spell 83776 on Self // "),
(@ENTRY, 0, 3, 0, 0, 0, 100, 0, 6000, 6500, 6000, 10000, 11, 83778, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 6000 and 6500 ms (and later repeats every 6000 and 10000 ms) - Self: Cast spell 83778 on Random hostile // ");

-- Creature Oathsworn Scorpid Keeper 45062 SAI
SET @ENTRY := 45062;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 25, 0, 100, 1, 0, 0, 0, 0, 11, 84126, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On reset (e.g. after reaching home) - Self: Cast spell 84126 on Self // "),
(@ENTRY, 0, 1, 0, 0, 0, 100, 0, 8000, 8000, 17000, 17000, 11, 84123, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 8000 and 8000 ms (and later repeats every 17000 and 17000 ms) - Self: Cast spell 84123 on Self // "),
(@ENTRY, 0, 2, 0, 0, 0, 100, 0, 11000, 11000, 17000, 17000, 11, 84122, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 11000 and 11000 ms (and later repeats every 17000 and 17000 ms) - Self: Cast spell 84122 on Self // ");

-- Creature Neferset Darkcaster 44982 SAI
SET @ENTRY := 44982;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 1, 1, 2400, 2400, 11, 82765, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 1 and 1 ms (and later repeats every 2400 and 2400 ms) - Self: Cast spell 82765 on Victim // "),
(@ENTRY, 0, 1, 0, 0, 0, 100, 0, 7000, 7000, 16000, 16000, 11, 84032, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 7000 and 7000 ms (and later repeats every 16000 and 16000 ms) - Self: Cast spell 84032 on Random hostile // "),
(@ENTRY, 0, 2, 0, 0, 0, 100, 0, 17000, 17000, 16000, 16000, 11, 82760, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 17000 and 17000 ms (and later repeats every 16000 and 16000 ms) - Self: Cast spell 82760 on Random hostile // ");

-- Creature Neferset Theurgist 44980 SAI
SET @ENTRY := 44980;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 6000, 7000, 16000, 16000, 11, 82753, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 6000 and 7000 ms (and later repeats every 16000 and 16000 ms) - Self: Cast spell 82753 on Victim // "),
(@ENTRY, 0, 1, 0, 0, 0, 100, 0, 14000, 15000, 16000, 16000, 11, 82757, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 14000 and 15000 ms (and later repeats every 16000 and 16000 ms) - Self: Cast spell 82757 on Self // "),
(@ENTRY, 0, 2, 0, 0, 0, 100, 0, 23000, 24000, 16000, 16000, 11, 82759, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 23000 and 24000 ms (and later repeats every 16000 and 16000 ms) - Self: Cast spell 82759 on Self // ");

-- Creature Tol'vir Merchant 45065 SAI
SET @ENTRY := 45065;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 1, 1, 1000, 1000, 11, 84144, 64, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 1 and 1 ms (and later repeats every 1000 and 1000 ms) - Self: Cast spell 84144 on Random hostile // ");

-- Trash Generic Update
-- Sharptalon Eagle
UPDATE `creature_template` SET `unit_flags`= 0, `minlevel`= 84, `maxlevel`= 84 WHERE `entry`= 44261;
-- Oasis Moth
UPDATE `creature` SET `MovementType`= 1, `spawndist`= 7 WHERE `id`= 50496;
-- Tol'Vir merchant
UPDATE `creature_template` SET `mingold`= 2300, `maxgold`= 2500 WHERE `entry`= 45065;
-- Oathsworn Captain
UPDATE `creature_template` SET `minlevel`= 85, `maxlevel`= 85, `mingold`= 11100, `maxgold`= 12000 WHERE `entry`= 45122;
UPDATE `creature_template` SET `minlevel`= 86, `maxlevel`= 86, `mingold`= 11100, `maxgold`= 12000 WHERE `entry`= 49334;
-- Oathsworn Tamer
UPDATE `creature_template` SET `difficulty_entry_1`= 49333, `mingold`= 11100, `maxgold`= 12000 WHERE `entry`= 45097;
UPDATE `creature_template` SET `minlevel`= 85, `maxlevel`= 85, `faction`= 16, `exp`= 3, `mingold`= 11100, `maxgold`= 12000, `speed_walk`= 0.666668 WHERE `entry`= 49333;
-- Oathsworn Wanderer
UPDATE `creature_template` SET `difficulty_entry_1`= 49322, `mingold`= 11100, `maxgold`= 12000 WHERE `entry`= 44926;
UPDATE `creature_template` SET `minlevel`= 85, `maxlevel`= 85, `faction`= 16, `exp`= 3, `mingold`= 11100, `maxgold`= 12000, `speed_walk`= 0.666668 WHERE `entry`= 49322;
-- Oathsworn Skinner
UPDATE `creature_template` SET `difficulty_entry_1`= 49327, `mingold`= 11100, `maxgold`= 12000 WHERE `entry`= 44981;
UPDATE `creature_template` SET `minlevel`= 85, `maxlevel`= 85, `faction`= 16, `exp`= 3, `mingold`= 11100, `maxgold`= 12000, `speed_walk`= 0.666668 WHERE `entry`= 49327;
-- Oathsworn Myrmidon
UPDATE `creature_template` SET `difficulty_entry_1`= 49321, `mingold`= 11100, `maxgold`= 12000 WHERE `entry`= 44924;
UPDATE `creature_template` SET `minlevel`= 85, `maxlevel`= 85, `faction`= 16, `exp`= 3, `mingold`= 11100, `maxgold`= 12000, `speed_walk`= 0.666668 WHERE `entry`= 49321;
-- Oathsworn Axemaster
UPDATE `creature_template` SET `difficulty_entry_1`= 49319, `mingold`= 11000, `maxgold`= 12000 WHERE `entry`= 44922;
UPDATE `creature_template` SET `minlevel`= 85, `maxlevel`= 85, `faction`= 16, `exp`= 3, `mingold`= 11100, `maxgold`= 12000, `speed_walk`= 0.666668 WHERE `entry`= 49319;
-- Oathsworn Pathfinder
UPDATE `creature_template` SET `difficulty_entry_1`= 49323, `mingold`= 11100, `maxgold`= 12000 WHERE `entry`= 44932;
UPDATE `creature_template` SET `minlevel`= 85, `maxlevel`= 85, `faction`= 16, `exp`= 3, `mingold`= 11100, `maxgold`= 12000, `speed_walk`= 0.666668 WHERE `entry`= 49323;
-- Neferset Plaguebringer
UPDATE `creature_template` SET `difficulty_entry_1`= 49324, `mingold`= 11100, `maxgold`= 12000 WHERE `entry`= 44976;
UPDATE `creature_template` SET `minlevel`= 85, `maxlevel`= 85, `faction`= 16, `exp`= 3, `mingold`= 11100, `maxgold`= 12000, `speed_walk`= 0.666668 WHERE `entry`= 49324;
-- Neferset Torturer
UPDATE `creature_template` SET `difficulty_entry_1`= 49325, `mingold`= 11100, `maxgold`= 12000 WHERE `entry`= 44977;
UPDATE `creature_template` SET `minlevel`= 85, `maxlevel`= 85, `faction`= 16, `exp`= 3, `mingold`= 11100, `maxgold`= 12000, `speed_walk`= 0.666668 WHERE `entry`= 49325;
-- Neferset Darkcaster
UPDATE `creature_template` SET `difficulty_entry_1`= 49328, `mingold`= 11100, `maxgold`= 12000 WHERE `entry`= 44982;
UPDATE `creature_template` SET `minlevel`= 85, `maxlevel`= 85, `faction`= 16, `exp`= 3, `mingold`= 11100, `maxgold`= 12000, `speed_walk`= 0.666668 WHERE `entry`= 49328;
-- Oathsworn Scorpid Keeper
UPDATE `creature_template` SET `difficulty_entry_1`= 49330, `mingold`= 11100, `maxgold`= 12000 WHERE `entry`= 45062;
UPDATE `creature_template` SET `minlevel`= 85, `maxlevel`= 85, `faction`= 16, `exp`= 3, `mingold`= 11100, `maxgold`= 12000, `speed_walk`= 0.666668 WHERE `entry`= 49330;
-- Neferset Theurgist
UPDATE `creature_template` SET `difficulty_entry_1`= 49326, `mingold`= 11100, `maxgold`= 12000 WHERE `entry`= 44980;
UPDATE `creature_template` SET `minlevel`= 85, `maxlevel`= 85, `faction`= 16, `exp`= 3, `mingold`= 11100, `maxgold`= 12000, `speed_walk`= 0.666668 WHERE `entry`= 49326;
-- Pygmy Scout
UPDATE `creature_template` SET `difficulty_entry_1`= 49318, `mingold`= 11100, `maxgold`= 12000 WHERE `entry`= 44897;
UPDATE `creature_template` SET `minlevel`= 85, `maxlevel`= 85, `faction`= 16, `exp`= 3, `mingold`= 11100, `maxgold`= 12000, `vehicleId`= 1058 WHERE `entry`= 49318;
-- Pygmy Brute
UPDATE `creature_template` SET `difficulty_entry_1`= 49317, `mingold`= 11100, `maxgold`= 12000 WHERE `entry`= 44896;
UPDATE `creature_template` SET `minlevel`= 85, `maxlevel`= 85, `faction`= 16, `exp`= 3, `mingold`= 11100, `maxgold`= 12000, `vehicleId`= 1056 WHERE `entry`= 49317;
-- Pygmy Firebreather
UPDATE `creature_template` SET `difficulty_entry_1`= 49320, `mingold`= 11100, `maxgold`= 12000 WHERE `entry`= 44898;
UPDATE `creature_template` SET `minlevel`= 85, `maxlevel`= 85, `faction`= 16, `exp`= 3, `mingold`= 11100, `maxgold`= 12000 WHERE `entry`= 49320;
-- Add dual wield flag to multiple npc's
UPDATE `creature_template` SET `flags_extra`= `flags_extra`| 2048 WHERE `entry` IN (44981, 49327, 44977, 49325, 45007, 45062, 49330);

-- Loot
-- Lockmaw
UPDATE `creature_template` SET `lootid` = 43614 WHERE `entry` = 43614;
DELETE FROM `creature_loot_template` WHERE `entry` IN (43614, 49043, 49045);
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
(43614, 55866, 0, 1, 1, 1, 1),
(43614, 55867, 0, 1, 1, 1, 1),
(43614, 55869, 0, 1, 1, 1, 1),
(43614, 55868, 0, 1, 1, 1, 1),
(43614, 55870, 0, 1, 1, 1, 1);

-- Augh (Heroic Mode)
UPDATE `creature_template` SET `lootid` = 49045 WHERE `entry` = 49045;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
(49045, 56389, 0, 1, 1, 1, 1),
(49045, 56392, 0, 1, 1, 1, 1),
(49045, 56391, 0, 1, 1, 1, 1),
(49045, 56393, 0, 1, 1, 1, 1),
(49045, 56390, 0, 1, 1, 1, 1);

DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_gen_blink',
'spell_gen_toxic_blow_dart',
'spell_gen_projectile_goods');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(84123, 'spell_gen_blink'),
(83780, 'spell_gen_toxic_blow_dart'),
(89991, 'spell_gen_toxic_blow_dart'),
(84144, 'spell_gen_projectile_goods');
