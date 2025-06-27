-- Gilmorian
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=14447;
DELETE FROM `smart_scripts` WHERE `entryorguid`=14447 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(14447,0,0,0,0,0,100,0,3000,5000,5000,8000,0,11,19472,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Gilmorian - In Combat - Cast 'Sinister Strike'"),
(14447,0,1,0,0,0,100,0,7000,11000,9000,13000,0,11,13579,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Gilmorian - In Combat - Cast 'Gouge'"),
(14447,0,2,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Gilmorian - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Monstrous Crawler
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1088;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1088 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1088,0,0,0,0,0,100,0,5000,7000,15000,19000,0,11,13443,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Monstrous Crawler - In Combat - Cast 'Rend'");

-- Acidic Swamp Ooze
DELETE FROM `smart_scripts` WHERE `entryorguid`=4393 AND `source_type`=0 AND `id`=3;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4393,0,3,0,2,0,100,1,0,15,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Acidic Swamp Ooze - Between 0-15% Health - Say Line 0 (No Repeat)");

DELETE FROM `creature_text` WHERE `CreatureID`=4393;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(4393,0,0,"The surface of the %s begins to bubble.",16,0,100,0,0,0,16647,0,"Acidic Swamp Ooze");

-- Bubbling Swamp Ooze
DELETE FROM `smart_scripts` WHERE `entryorguid`=4394 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4394,0,2,0,2,0,100,1,0,15,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bubbling Swamp Ooze - Between 0-15% Health - Say Line 0 (No Repeat)");

DELETE FROM `creature_text` WHERE `CreatureID`=4394;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(4394,0,0,"The surface of the %s begins to bubble.",16,0,100,0,0,0,16647,0,"Bubbling Swamp Ooze");
