-- Creature Forgotten Ghoul 46569 SAI
SET @ENTRY := 46569;
UPDATE `creature_template` SET `AIName`="SmartAI", `DamageModifier`= 8 WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 6000, 6000, 30000, 30000, 11, 7102, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 6000 and 6000 ms (and later repeats every 30000 and 30000 ms) - Self: Cast spell Contagion of Rot (7102) on Victim // "),
(@ENTRY, 0, 1, 0, 6, 0, 100, 0, 0, 0, 0, 0, 11, 85236, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On death - Self: Cast spell Corpse Rot (85236) on Self // ");

-- Creature Wandering Soul 46586 SAI
SET @ENTRY := 46586;
UPDATE `creature_template` SET `AIName`="SmartAI", `DamageModifier`= 8 WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 1, 1, 12000, 18000, 11, 49861, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 1 and 1 ms (and later repeats every 12000 and 18000 ms) - Self: Cast spell Infected Bite (49861) on Victim // ");

-- Creature Hungry Ghoul 46582 SAI
SET @ENTRY := 46582;
UPDATE `creature_template` SET `AIName`="SmartAI", `DamageModifier`= 8 WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 5000, 6000, 10000, 11000, 11, 85234, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 5000 and 6000 ms (and later repeats every 10000 and 11000 ms) - Self: Cast spell Fetid Breath (85234) on Victim // "),
(@ENTRY, 0, 1, 0, 6, 0, 100, 0, 0, 0, 0, 0, 11, 85236, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On death - Self: Cast spell Corpse Rot (85236) on Self // ");

UPDATE `creature_template` SET `DamageModifier`= 8 WHERE `entry` IN (46597, 46570);
UPDATE `creature_template` SET `DamageModifier`= 10 WHERE `entry`= 46571;
