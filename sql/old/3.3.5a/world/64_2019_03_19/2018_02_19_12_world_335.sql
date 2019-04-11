-- Ravasaur Runner
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=6506;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6506 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6506,0,0,0,25,0,100,0,0,0,0,0,11,3417,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ravasaur Runner - On Reset - Cast 'Thrash'"),
(6506,0,1,0,4,0,100,0,0,0,0,0,11,6268,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ravasaur Runner - On Aggro - Cast 'Rushing Charge'");

-- Venomhide Ravasaur
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=6508;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6508 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6508,0,0,0,25,0,100,0,0,0,0,0,11,14108,0,0,0,0,0,1,0,0,0,0,0,0,0,"Venomhide Ravasaur - On Reset - Cast 'Venomhide Poison'");

-- Muculent Ooze
DELETE FROM `smart_scripts` WHERE `entryorguid`=6556 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6556,0,1,0,25,0,100,0,0,0,0,0,11,14133,0,0,0,0,0,1,0,0,0,0,0,0,0,"Muculent Ooze - On Reset - Cast 'Muculent Fever Proc'");

-- Primal Ooze
DELETE FROM `smart_scripts` WHERE `entryorguid`=6557 AND `source_type`=0 AND `id` IN (8,9);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6557,0,8,0,2,0,100,1,0,30,0,0,11,14146,0,0,0,0,0,1,0,0,0,0,0,0,0,"Primal Ooze - Between 0-30% Health - Cast 'Clone' (No Repeat)"),
(6557,0,9,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Primal Ooze - Between 0-30% Health - Say Line 0 (No Repeat)");

DELETE FROM `creature_text` WHERE `CreatureID`=6557;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(6557,0,0,"%s begins to make a copy of itself!",16,0,100,0,0,0,2082,0,"Primal Ooze");

-- Cloned Ooze
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=9477;
DELETE FROM `smart_scripts` WHERE `entryorguid`=9477 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(9477,0,0,0,54,0,100,0,0,0,0,0,49,0,0,0,0,0,0,21,30,0,0,0,0,0,0,"Cloned Ooze - Just Summoned - Start Attacking");

-- Glutinous Ooze
DELETE FROM `smart_scripts` WHERE `entryorguid`=6559 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6559,0,2,0,6,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Glutinous Ooze - On Just Died - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=6559;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(6559,0,0,"%s explodes into chunks of acidic slime!",16,0,100,0,0,0,4838,0,"Glutinous Ooze");

-- Gorishi Wasp
DELETE FROM `smart_scripts` WHERE `entryorguid`=6551 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6551,0,1,0,25,0,100,0,0,0,0,0,11,13299,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gorishi Wasp - On Reset - Cast 'Poison Proc'");

-- Gorishi Worker
DELETE FROM `smart_scripts` WHERE `entryorguid`=6552 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6552,0,1,0,2,0,100,1,0,50,0,0,39,20,1,0,0,0,0,1,0,0,0,0,0,0,0,"Gorishi Worker - Between 0-30% Health - Call For Help (No Repeat)");

-- Gorishi Reaver
DELETE FROM `smart_scripts` WHERE `entryorguid`=6553 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6553,0,1,0,0,0,100,0,8000,12000,21000,25000,11,8137,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gorishi Reaver - In Combat - Cast 'Silithid Pox'");

-- Gorishi Stinger
DELETE FROM `smart_scripts` WHERE `entryorguid`=6554 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6554,0,1,0,25,0,100,0,0,0,0,0,11,8601,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gorishi Stinger - On Reset - Cast 'Slowing Poison'");

-- Gorishi Tunneler
DELETE FROM `smart_scripts` WHERE `entryorguid`=6555 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6555,0,1,0,0,0,100,0,8000,12000,21000,25000,11,8137,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gorishi Tunneler - In Combat - Cast 'Silithid Pox'");

-- Blazing Invader
UPDATE `creature_template` SET `unit_class`=2, `AIName`="SmartAI" WHERE `entry`=14460;
DELETE FROM `smart_scripts` WHERE `entryorguid`=14460 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(14460,0,0,0,0,0,100,0,7000,13000,19000,24000,11,23039,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blazing Invader - In Combat - Cast 'Blast Wave'");

-- Living Blaze
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=6521;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6521 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6521,0,0,0,0,0,100,0,3000,3000,3000,3000,11,11351,0,0,0,0,0,1,0,0,0,0,0,0,0,"Living Blaze - In Combat - Cast 'Fire Shield'");
