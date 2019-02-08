-- Creature Pride of Bethekk 52345 SAI
SET @ENTRY := 52345;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 8000, 10000, 8000, 10000, 11, 97355, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 8000 and 10000 ms (and later repeats every 8000 and 10000 ms) - Self: Cast spell 97355 on Random hostile // ");

-- Creature Gurubashi Shadow Hunter 52327 SAI
SET @ENTRY := 52327;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 400, 400, 2500, 2500, 11, 97239, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 400 and 400 ms (and later repeats every 2500 and 2500 ms) - Self: Cast spell 97239 on Victim // "),
(@ENTRY, 0, 1, 0, 0, 0, 100, 0, 7000, 7000, 8000, 9000, 11, 96951, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 7000 and 7000 ms (and later repeats every 8000 and 9000 ms) - Self: Cast spell 96951 on Random hostile // ");

-- Creature Lesser Priest of Bethekk 52339 SAI
SET @ENTRY := 52339;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 100, 100, 2500, 2500, 11, 96956, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 100 and 100 ms (and later repeats every 2500 and 2500 ms) - Self: Cast spell 96956 on Victim // "),
(@ENTRY, 0, 1, 0, 0, 0, 100, 0, 10000, 12000, 32000, 33000, 11, 96790, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 10000 and 12000 ms (and later repeats every 32000 and 33000 ms) - Self: Cast spell 96790 on Self // "),
(@ENTRY, 0, 2, 0, 0, 0, 100, 0, 9000, 10000, 30000, 31000, 11, 96849, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 9000 and 10000 ms (and later repeats every 30000 and 31000 ms) - Self: Cast spell 96849 on Self // ");

-- Creature Gurubashi Blood Drinker 52325 SAI
SET @ENTRY := 52325;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 7000, 8000, 17000, 18000, 11, 13737, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 7000 and 8000 ms (and later repeats every 17000 and 18000 ms) - Self: Cast spell 13737 on Victim // "),
(@ENTRY, 0, 1, 0, 0, 0, 100, 0, 9000, 10000, 31000, 33000, 11, 96764, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 9000 and 10000 ms (and later repeats every 31000 and 33000 ms) - Self: Cast spell 96764 on Self // ");

DELETE FROM `creature_template_addon` WHERE `entry` IN (52395, 52612);
INSERT INTO `creature_template_addon` (`entry`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(52395, 0, 1, 0, '97332'),
(52612, 0, 1, 0, '96456');

UPDATE `creature_template` SET `ScriptName`= 'npc_zulgurub_gurubashi_berserker' WHERE `entry`= 52077;

DELETE FROM `creature_text` WHERE `CreatureID` IN (52077);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(52077, 0, 0, '%s is chasing you. Run!', 42, 0, 100, 0, 0, 0, 36529, 'Gurubashi Berserker - Whisper Pursuit'),
(52077, 1, 0, '%s is chasing $n.', 16, 0, 100, 0, 0, 0, 36530, 'Gurubashi Berserker - Announce Pursuit');

-- Creature Gurubashi Cauldron-Mixer 52082 SAI
SET @ENTRY := 52082;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 4, 0, 100, 0, 0, 0, 0, 0, 11, 96487, 64, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On aggro - Self: Cast spell 96487 on Self // "),
(@ENTRY, 0, 1, 0, 0, 0, 100, 0, 5000, 6000, 2500, 2500, 11, 96804, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 5000 and 6000 ms (and later repeats every 2500 and 2500 ms) - Self: Cast spell 96804 on Victim // "),
(@ENTRY, 0, 2, 0, 0, 0, 100, 0, 10000, 10500, 20000, 20500, 11, 97387, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 10000 and 10500 ms (and later repeats every 20000 and 20500 ms) - Self: Cast spell 97387 on Self // "),
(@ENTRY, 0, 3, 0, 0, 0, 100, 0, 21000, 21000, 20000, 20500, 11, 96413, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 21000 and 21000 ms (and later repeats every 20000 and 20500 ms) - Self: Cast spell 96413 on Random hostile // ");

-- Creature Gurubashi Soul-Eater 52598 SAI
SET @ENTRY := 52598;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 6000, 6000, 15000, 16000, 11, 97248, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 6000 and 6000 ms (and later repeats every 15000 and 16000 ms) - Self: Cast spell 97248 on Random hostile // "),
(@ENTRY, 0, 1, 0, 0, 0, 100, 0, 10000, 11000, 20000, 21000, 11, 97250, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 10000 and 11000 ms (and later repeats every 20000 and 21000 ms) - Self: Cast spell 97250 on Self // ");

-- Creature Razzashi Adder 52085 SAI
SET @ENTRY := 52085;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 100, 100, 11000, 14000, 11, 97599, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 100 and 100 ms (and later repeats every 11000 and 14000 ms) - Self: Cast spell 97599 on Random hostile // "),
(@ENTRY, 0, 1, 0, 0, 0, 100, 1, 9000, 15000, 0, 0, 11, 3391, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 9000 and 15000 ms (and later repeats every 0 and 0 ms) - Self: Cast spell 3391 on Victim // ");

-- Creature Hakkari Witch Doctor 52086 SAI
SET @ENTRY := 52086;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 11, 45104, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On reset (e.g. after reaching home) - Self: Cast spell 45104 on Self // "),
(@ENTRY, 0, 1, 0, 0, 0, 100, 0, 400, 400, 2500, 2500, 11, 96416, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 400 and 400 ms (and later repeats every 2500 and 2500 ms) - Self: Cast spell 96416 on Victim // "),
(@ENTRY, 0, 2, 3, 0, 0, 100, 0, 18000, 19000, 30000, 31000, 11, 97398, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 18000 and 19000 ms (and later repeats every 30000 and 31000 ms) - Self: Cast spell 97398 on Self // "),
(@ENTRY, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 67, 0, 4000, 4000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Trigger timed event #0 in 4000 - 4000 ms // "),
(@ENTRY, 0, 4, 0, 6, 0, 100, 0, 0, 0, 0, 0, 11, 96418, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On death - Self: Cast spell 96418 on Self // "),
(@ENTRY, 0, 5, 0, 59, 0, 100, 1, 0, 0, 0, 0, 11, 24065, 3, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On timed event 0 triggered - Self: Cast spell 24065 on Self // "),
(@ENTRY, 0, 6, 0, 0, 0, 100, 0, 28000, 30000, 30000, 32000, 11, 97397, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 28000 and 30000 ms (and later repeats every 30000 and 32000 ms) - Self: Cast spell 97397 on Random hostile // ");

UPDATE `creature_template` SET `difficulty_entry_1`= 52145, `unit_flags`= 33587200, `speed_run`= 0.285 WHERE `entry`= 52137;
UPDATE `creature_template` SET `minlevel`= 85, `maxlevel`= 85, `exp`= 3, `faction`= 28, `unit_flags`= 33587200, `DamageModifier`= 60, `speed_run`= 0.285 WHERE `entry`= 52145;

DELETE FROM `conditions` WHERE `SourceEntry` IN (96487, 24062) AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 96487, 0, 0, 31, 0, 5, 208315, 0, 0, 0, '', 'Drain Cauldron - Target Zanzil''s Cauldron of Toxic Torment'),
(13, 1, 24062, 0, 0, 31, 0, 3, 15010, 0, 0, 0, '', 'Toad Explode - Target Toad');

DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_zulgurub_toad_explode');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(24062, 'spell_zulgurub_toad_explode');

-- Creature Jungle Toad 15010 SAI
SET @ENTRY := 15010;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 89, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When just created - Self: Move in radius 5 yards // ");
