-- Creature Temple Fireshaper 48143 SAI
SET @ENTRY := 48143;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
SET @ENTRY := -322519;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 1, 1000, 1000, 0, 0, 11, 89547, 64, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 1000 and 1000 ms (and later repeats every 0 and 0 ms) - Self: Cast spell Blazing Eruption (89547) on Self // "),
(@ENTRY, 0, 1, 0, 0, 0, 100, 0, 10000, 10000, 30000, 30000, 11, 89542, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 10000 and 10000 ms (and later repeats every 30000 and 30000 ms) - Self: Cast spell Molten Barrier (89542) on Self // "),
(@ENTRY, 0, 2, 0, 0, 0, 100, 0, 13500, 13500, 22000, 26000, 11, 84032, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 13500 and 13500 ms (and later repeats every 22000 and 26000 ms) - Self: Cast spell Meteor (84032) on Random hostile // "),
(@ENTRY, 0, 3, 0, 0, 0, 100, 0, 13500, 13500, 1200, 1200, 11, 89538, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 13500 and 13500 ms (and later repeats every 1200 and 1200 ms) - Self: Cast spell Fireball (89538) on Victim // ");

-- Creature Temple Fireshaper 48143 SAI
SET @ENTRY := 48143;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 1, 1, 1600, 1600, 11, 89854, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 1 and 1 ms (and later repeats every 1600 and 1600 ms) - Self: Cast spell Fireball (89854) on Victim // "),
(@ENTRY, 0, 1, 0, 0, 0, 100, 0, 9000, 9000, 30000, 31000, 11, 89542, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 9000 and 9000 ms (and later repeats every 30000 and 31000 ms) - Self: Cast spell Molten Barrier (89542) on Self // "),
(@ENTRY, 0, 2, 0, 0, 0, 100, 0, 15000, 15000, 25000, 26000, 11, 90023, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 15000 and 15000 ms (and later repeats every 25000 and 26000 ms) - Self: Cast spell Meteor (90023) on Random hostile // ");


-- Creature Temple Swiftstalker 48139 SAI
SET @ENTRY := 48139;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 1000, 1000, 2400, 2400, 11, 83877, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 1000 and 1000 ms (and later repeats every 2400 and 2400 ms) - Self: Cast spell Shoot (83877) on Victim // "),
(@ENTRY, 0, 1, 2, 0, 0, 100, 0, 6000, 6000, 26000, 26000, 64, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 6000 and 6000 ms (and later repeats every 26000 and 26000 ms) - Self: Target_0 = Random hostile // "),
(@ENTRY, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 11, 89574, 0, 0, 0, 0, 0, 12, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Cast spell Charged Shot (89574) on storedTarget[0] // "),
(@ENTRY, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 11, 89571, 0, 0, 0, 0, 0, 12, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Cast spell Charged Shot (89571) on storedTarget[0] // "),
(@ENTRY, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 12, 0, 0, 0, 0, 0, 0, 0, " Linked - storedTarget[0]: Talk 0 // ");

DELETE FROM `creature_text` WHERE `CreatureID`= 48139;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(48139, 0, 0, '%s begins to aim a charged shot at $n!', 16, 0, 100, 0, 0, 0, 48402, 'Temple Swiftstalker - Charged Shot');

-- Creature Temple Shadowlancer 48141 SAI
SET @ENTRY := 48141;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 7000, 8000, 18000, 22000, 11, 89555, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 7000 and 8000 ms (and later repeats every 18000 and 22000 ms) - Self: Cast spell Shadowlance (89555) on Self // "),
(@ENTRY, 0, 1, 0, 0, 0, 100, 0, 8000, 10000, 22000, 26000, 11, 89560, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 8000 and 10000 ms (and later repeats every 22000 and 26000 ms) - Self: Cast spell Pact of Darkness (89560) on Self // ");

-- Creature Temple Runecaster 48140 SAI
SET @ENTRY := 48140;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 5000, 7000, 10000, 10000, 11, 91806, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 5000 and 7000 ms (and later repeats every 10000 and 10000 ms) - Self: Cast spell Runic Cleave (91806) on Victim // "),
(@ENTRY, 0, 1, 0, 0, 0, 100, 0, 9000, 11000, 32000, 36000, 11, 95181, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 9000 and 11000 ms (and later repeats every 32000 and 36000 ms) - Self: Cast spell Curse of the Runecaster (95181) on Random hostile // "),
(@ENTRY, 0, 2, 0, 0, 0, 100, 0, 13000, 13000, 33000, 35000, 11, 89549, 0, 0, 0, 0, 0, 26, 30, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 13000 and 13000 ms (and later repeats every 33000 and 35000 ms) - Self: Cast spell Rune of Healing (89549) on Closest friendly creature in 30 yards // ");


UPDATE `creature_template` SET `unit_flags`= 34080832, `flags_extra`= 128, `AIName`= 'NullCreatureAI' WHERE `entry`= 39258;
DELETE FROM `creature_template_addon` WHERE `entry`= 39258;
INSERT INTO `creature_template_addon` (`entry`, `auras`) VALUES
(39258, 73695);

UPDATE `gameobject_template_addon` SET `flags`=1 WHERE `entry`=207219; -- Beacon of Light
UPDATE `gameobject_template_addon` SET `flags`=1 WHERE `entry`=207218; -- Beacon of Light

UPDATE `gameobject_template` SET `ScriptName`= 'go_anhuur_beacon_of_light' WHERE `entry` IN (207219, 207218, 203136, 203133);
DELETE FROM `achievement_criteria_data` WHERE `ScriptName`= 'achievement_i_hate_that_song';
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `ScriptName`) VALUES
(15988, 11, 'achievement_i_hate_that_song');

