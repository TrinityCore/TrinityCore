UPDATE `creature` SET `spawndist`= 7, `MovementType`= 1 WHERE `guid` IN (317700, 317699, 317702, 317706, 317708, 317707, 317719, 317726, 317710, 317732, 317735, 317733, 317734);
DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (206, 920);
INSERT INTO `creature_template_movement` (`CreatureId`, `Random`) VALUES
(206, 2),
(920, 2);

UPDATE `creature_template_addon`  SET `emote`= 27 WHERE `entry` IN (206, 920);

-- Creature Nightbane Tainted One 920 SAI
SET @ENTRY := 920;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 1, 0, 100, 0, 1000, 10000, 11000, 15000, 127, 0, 6000, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Update (OOC) 1000 min and 10000 max ms (repeat 11000 min 15000 max ms) - Self: Pause Movement for 6000 milliseconds // "),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 5, 479, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Play emote ONESHOT_SNIFF (479) // "),
(@ENTRY, 0, 2, 3, 0, 0, 100, 0, 10000, 10000, 61000, 61000, 11, 85244, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 10000 min and 10000 max ms (repeat 61000 min 61000 max ms) - Self: Cast spell Worgen Taint (85244) on Victim // "),
(@ENTRY, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 98531, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Cast spell Worgen Taint (98531) on Victim // ");

-- Creature Nightbane Vile Fang 206 SAI
SET @ENTRY := 206;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 1, 0, 100, 0, 1000, 10000, 11000, 15000, 127, 0, 6000, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Update (OOC) 1000 min and 10000 max ms (repeat 11000 min 15000 max ms) - Self: Pause Movement for 6000 milliseconds // "),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 5, 479, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Play emote ONESHOT_SNIFF (479) // "),
(@ENTRY, 0, 2, 0, 0, 0, 100, 0, 7000, 8000, 20000, 21000, 11, 84308, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 7000 min and 8000 max ms (repeat 20000 min 21000 max ms) - Self: Cast spell Furious Howl (84308) on Self // "),
(@ENTRY, 0, 3, 0, 0, 0, 100, 0, 11000, 12000, 31000, 31000, 11, 3427, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 11000 min and 12000 max ms (repeat 31000 min 31000 max ms) - Self: Cast spell Infected Wound (3427) on Victim // ");

-- Creature Black Ravager 628 SAI
SET @ENTRY := 628;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 7000, 8000, 31000, 31000, 11, 80365, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 7000 min and 8000 max ms (repeat 31000 min 31000 max ms) - Self: Cast spell Flurry of Claws (80365) on Self // ");

DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_gen_flurry_of_claws';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(53032, 'spell_gen_flurry_of_claws'),
(76490, 'spell_gen_flurry_of_claws'),
(80365, 'spell_gen_flurry_of_claws');

-- Creature Blackbelly Forager 44089 SAI
SET @ENTRY := 44089;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 1, 100, 100, 0, 0, 11, 6268, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 100 min and 100 max ms (repeat 0 min 0 max ms) - Self: Cast spell Rushing Charge (6268) on Victim // "),
(@ENTRY, 0, 1, 0, 0, 0, 100, 0, 12000, 12000, 34000, 34000, 11, 84873, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 12000 min and 12000 max ms (repeat 34000 min 34000 max ms) - Self: Cast spell Wallow (84873) on Self // ");

-- Creature Barn Owl 44020 SAI
SET @ENTRY := 44020;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 18000, 19000, 20000, 21000, 11, 49865, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 18000 min and 19000 max ms (repeat 20000 min 21000 max ms) - Self: Cast spell Eye Peck (49865) on Victim // "),
(@ENTRY, 0, 1, 0, 0, 0, 100, 0, 25000, 26000, 20000, 21000, 11, 81680, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 25000 min and 26000 max ms (repeat 20000 min 21000 max ms) - Self: Cast spell Howling Screech (81680) on Self // ");

-- Creature Splinter Fist Ogre 889 SAI
SET @ENTRY := 889;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 4, 0, 20, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On aggro (20% chance) - Self: Talk 0 // "),
(@ENTRY, 0, 1, 0, 0, 0, 100, 0, 7000, 9000, 31000, 31000, 11, 80182, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 7000 min and 9000 max ms (repeat 31000 min 31000 max ms) - Self: Cast spell Uppercut (80182) on Victim // ");

-- Creature Splinter Fist Firemonger 1251 SAI
SET @ENTRY := 1251;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 4, 0, 20, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On aggro (20% chance) - Self: Talk 0 // "),
(@ENTRY, 0, 1, 0, 0, 0, 100, 0, 11000, 12000, 23000, 24000, 11, 78509, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 11000 min and 12000 max ms (repeat 23000 min 24000 max ms) - Self: Cast spell Torch Toss (78509) on Victim // "),
(@ENTRY, 0, 2, 0, 0, 0, 100, 0, 3000, 4000, 8000, 12000, 11, 13878, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 3000 min and 4000 max ms (repeat 8000 min 12000 max ms) - Self: Cast spell Scorch (13878) on Victim // ");

-- Creature Splinter Fist Warrior 212 SAI
SET @ENTRY := 212;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On reset (e.g. after reaching home) - Self: Set event phase to 1 // "),
(@ENTRY, 0, 1, 0, 4, 0, 20, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On aggro (20% chance) - Self: Talk 0 // "),
(@ENTRY, 0, 2, 0, 4, 0, 100, 0, 0, 0, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On aggro - Self: Set event phase to 2 // "),
(@ENTRY, 0, 3, 0, 0, 0, 100, 0, 11000, 12000, 31000, 31000, 11, 78828, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Update (In Combat) 11000 min and 12000 max ms (repeat 31000 min 31000 max ms) - Self: Cast spell Bladestorm (78828) on Self // "),
(@ENTRY, 0, 4, 0, 8, 0, 100, 0, 78828, 0, 0, 0, 67, 0, 6000, 6000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell Bladestorm (78828) hit  - Trigger timed event #0 in 6000 - 6000 ms // "),
(@ENTRY, 0, 5, 0, 59, 2, 100, 0, 0, 0, 0, 0, 11, 35856, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On timed event 0 triggered - Self: Cast spell Stun (35856) on Self // "),
(@ENTRY, 0, 6, 0, 8, 0, 100, 0, 35856, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell Stun (35856) hit  - Self: Talk 1 // ");


DELETE FROM `creature_text` WHERE `CreatureID`= 212 AND `GroupID`= 1;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(212, 1, 0, 'Me not feel so good.', 12, 0, 100, 0, 0, 0, 43512, 'Splinter Fist Warrior - Stun');
