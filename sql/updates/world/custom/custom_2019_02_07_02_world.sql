-- Chosen of Hethiss
UPDATE `creature_template` SET `flags_extra`= 0, `mechanic_immune_mask`= 0 WHERE `entry`= 52323;
UPDATE `creature_template` SET `flags_extra`= 0, `mechanic_immune_mask`= 0 WHERE `entry`= 52513;

DELETE FROM `creature_formations` WHERE `leaderGUID`= 294911;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(294911, 294911, 0, 0, 3, 0, 0),
(294911, 294910, 0, 0, 3, 0, 0),
(294911, 294926, 0, 0, 3, 0, 0),
(294911, 294927, 0, 0, 3, 0, 0),
(294911, 294928, 0, 0, 3, 0, 0),
(294911, 294929, 0, 0, 3, 0, 0),
(294911, 294930, 0, 0, 3, 0, 0),
(294911, 294931, 0, 0, 3, 0, 0),
(294911, 294932, 0, 0, 3, 0, 0),
(294911, 294933, 0, 0, 3, 0, 0),
(294911, 294934, 0, 0, 3, 0, 0),
(294911, 294935, 0, 0, 3, 0, 0);

DELETE FROM `creature_template_addon` WHERE `entry` IN (52512);
INSERT INTO `creature_template_addon` (`entry`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(52512, 0, 1, 10, '96759');

DELETE FROM `creature_text` WHERE `CreatureID` IN (52322, 52956);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(52322, 0, 0, 'Sacrifice yo'' bodies ta Hethiss mah bruddahs, da voodoo will protect you!', 14, 0, 100, 0, 0, 0, 51266, 'Witch Doctor Qu''in - Aggro'),
(52956, 0, 0, 'Ancestors be beside me, let \'dem hear yo\' voice!', 14, 14, 100, 0, 0, 0, 51625, 'Zandalari Juggernaut - Glory of the Zandalari');

-- Creature Witch Doctor Qu'in 52322 SAI
SET @ENTRY := 52322;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 4, 0, 100, 0, 0, 0, 0, 0, 11, 97016, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On aggro - Self: Cast spell 97016 on Self // "),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Talk 0 // ");

-- Creature Chosen of Hethiss 52323 SAI
SET @ENTRY := 52323;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 4, 0, 100, 1, 0, 0, 0, 0, 11, 97019, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On aggro - Self: Cast spell 97019 on Self // "),
(@ENTRY, 0, 1, 2, 8, 0, 100, 0, 97019, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "On spell 97019 hit  - Self: Attack Victim // "),
(@ENTRY, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Set event phase to 2 // "),
(@ENTRY, 0, 3, 0, 0, 2, 100, 0, 200, 200, 6300, 6500, 11, 97018, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 200 and 200 ms (and later repeats every 6300 and 6500 ms) - Self: Cast spell 97018 on Self // ");

-- Creature Zandalari Juggernaut 52956 SAI
SET @ENTRY := 52956;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 11, 97987, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On reset (e.g. after reaching home) - Self: Cast spell 97987 on Self // "),
(@ENTRY, 0, 1, 2, 0, 0, 100, 1, 22000, 22000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 22000 and 22000 ms (and later repeats every 0 and 0 ms) - Self: Talk 0 // "),
(@ENTRY, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 11, 97977, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Cast spell 97977 on Self // "),
(@ENTRY, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 97970, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Cast spell 97970 on Self // "),
(@ENTRY, 0, 4, 0, 0, 2, 100, 0, 500, 500, 6000, 6000, 11, 98000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 500 and 500 ms (and later repeats every 6000 and 6000 ms) - Self: Cast spell 98000 on Self // "),
(@ENTRY, 0, 5, 0, 8, 0, 100, 0, 97970, 0, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell 97970 hit  - Self: Set event phase to 2 // ");

-- Creature Gurubashi Warmonger 52606 SAI
SET @ENTRY := 52606;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 2, 0, 100, 1, 0, 30, 0, 0, 11, 59697, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When health between 0% and 30% (check every 0 - 0 ms) - Self: Cast spell 59697 on Self // ");

-- Creature Gurubashi Cauldron-Mixer 52076 SAI
SET @ENTRY := 52076;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 4, 0, 100, 0, 0, 0, 0, 0, 11, 96488, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On aggro - Self: Cast spell 96488 on Self // "),
(@ENTRY, 0, 1, 0, 0, 0, 100, 1, 5000, 5000, 0, 0, 11, 96449, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 5000 and 5000 ms (and later repeats every 0 and 0 ms) - Self: Cast spell 96449 on Random hostile // "),
(@ENTRY, 0, 2, 0, 0, 0, 100, 0, 5000, 6000, 2500, 2500, 11, 97609, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 5000 and 6000 ms (and later repeats every 2500 and 2500 ms) - Self: Cast spell 97609 on Victim // "),
(@ENTRY, 0, 3, 0, 0, 0, 100, 0, 10000, 10500, 20000, 20500, 11, 97387, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 10000 and 10500 ms (and later repeats every 20000 and 20500 ms) - Self: Cast spell 97387 on Self // "),
(@ENTRY, 0, 4, 0, 0, 0, 100, 0, 21000, 21000, 20000, 20500, 11, 96413, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 21000 and 21000 ms (and later repeats every 20000 and 20500 ms) - Self: Cast spell 96413 on Random hostile // ");

-- Creature Gurubashi Cauldron-Mixer 52088 SAI
SET @ENTRY := 52088;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 4, 0, 100, 0, 0, 0, 0, 0, 11, 96488, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On aggro - Self: Cast spell 96488 on Self // "),
(@ENTRY, 0, 1, 0, 0, 0, 100, 1, 5000, 5000, 0, 0, 11, 96449, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 5000 and 5000 ms (and later repeats every 0 and 0 ms) - Self: Cast spell 96449 on Random hostile // "),
(@ENTRY, 0, 2, 0, 0, 0, 100, 0, 5000, 6000, 2500, 2500, 11, 97609, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 5000 and 6000 ms (and later repeats every 2500 and 2500 ms) - Self: Cast spell 97609 on Victim // "),
(@ENTRY, 0, 3, 0, 0, 0, 100, 0, 10000, 10500, 20000, 20500, 11, 97387, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 10000 and 10500 ms (and later repeats every 20000 and 20500 ms) - Self: Cast spell 97387 on Self // "),
(@ENTRY, 0, 4, 0, 0, 0, 100, 0, 21000, 21000, 20000, 20500, 11, 96413, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 21000 and 21000 ms (and later repeats every 20000 and 20500 ms) - Self: Cast spell 96413 on Random hostile // ");

-- Creature Gurubashi Cauldron-Mixer 52088 SAI
SET @ENTRY := -285223;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 200, 200, 2500, 2500, 11, 97609, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 200 and 200 ms (and later repeats every 2500 and 2500 ms) - Self: Cast spell 97609 on Victim // "),
(@ENTRY, 0, 1, 0, 0, 0, 100, 0, 10000, 10500, 20000, 20500, 11, 97387, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 10000 and 10500 ms (and later repeats every 20000 and 20500 ms) - Self: Cast spell 97387 on Self // "),
(@ENTRY, 0, 2, 0, 0, 0, 100, 0, 21000, 21000, 20000, 20500, 11, 96413, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 21000 and 21000 ms (and later repeats every 20000 and 20500 ms) - Self: Cast spell 96413 on Random hostile // ");

DELETE FROM `conditions` WHERE `SourceEntry` IN (97016, 96488) AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 97016, 0, 0, 31, 0, 3, 52323, 0, 0, 0, '', 'Big Bad Voodoo - Target Chosen of Hethiss'),
(13, 1, 96488, 0, 0, 31, 0, 5, 208314, 0, 0, 0, '', 'Drain Cauldron - Target Zanzil''s Cauldron of Frostburn Formular');

-- Proc Entries
DELETE FROM `spell_proc` WHERE `SpellId` IN (97987);
INSERT INTO `spell_proc` (`SpellId`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `Cooldown`) VALUES
(97987, 0x00000014, 1, 1, 10000);
