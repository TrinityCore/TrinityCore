-- Living Storm
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=9397;
DELETE FROM `smart_scripts` WHERE `entryorguid`=9397 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(9397,0,0,0,16,0,100,0,12550,1,5000,5000,11,12550,0,0,0,0,0,1,0,0,0,0,0,0,0,"Living Storm - On Friendly Unit Missing Buff 'Lightning Shield' - Cast Lightning Shield");

-- Land Rager
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5465;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5465 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5465,0,0,0,2,0,100,1,0,50,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Land Rager - Between 0-50% Health - Cast Enrage (No Repeat)"),
(5465,0,1,0,2,0,100,1,0,50,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Land Rager - Between 0-50% Health - Say Line 0 (No Repeat)");

DELETE FROM `creature_text` WHERE `CreatureID`=5465;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(5465,0,0,"%s becomes enraged!",16,0,100,0,0,0,10677,0,"Land Rager");

-- Gusting Vortex
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=8667;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8667 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(8667,0,0,0,0,0,100,0,8000,11000,22000,26000,11,6982,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gusting Vortex - In Combat - Cast Gust of Wind");
