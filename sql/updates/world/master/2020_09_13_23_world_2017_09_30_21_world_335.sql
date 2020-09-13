-- Vile Sprite
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2189;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2189 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2189,0,0,0,0,0,100,0,4000,9000,8000,17000,11,744,32,0,0,0,0,2,0,0,0,0,0,0,0,"Vile Sprite - In Combat - Cast Poison");

-- Young Reef Crawler
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2234;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2234 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2234,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Young Reef Crawler - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Thistle Bear
DELETE FROM `smart_scripts` WHERE `entryorguid`=2163 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2163,0,0,0,0,0,100,0,6000,9000,10000,16000,11,3242,0,0,0,0,0,2,0,0,0,0,0,0,0,"Thistle Bear - In Combat - Cast Ravage");

-- Thistle Cub
DELETE FROM `smart_scripts` WHERE `entryorguid`=6789 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6789,0,0,0,0,0,100,0,4000,12000,12000,20000,11,3242,0,0,0,0,0,2,0,0,0,0,0,0,0,"Thistle Cub - In Combat - Cast Ravage");

-- Den Mother
DELETE FROM `smart_scripts` WHERE `entryorguid`=6788 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6788,0,0,0,0,0,100,0,6000,8000,9000,13000,11,3242,0,0,0,0,0,2,0,0,0,0,0,0,0,"Den Mother - In Combat - Cast Ravage");

-- Marosh the Devious
DELETE FROM `smart_scripts` WHERE `entryorguid`=11714 AND `source_type`=0 AND `id` IN (2, 3);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11714,0,2,0,0,0,100,0,6000,12000,30000,40000,11,6950,2,0,0,0,0,2,0,0,0,0,0,0,0,"Marosh the Devious - In Combat - Cast Faerie Fire"),
(11714,0,3,0,0,0,100,0,2000,5000,3000,12000,11,3391,0,0,0,0,0,2,0,0,0,0,0,0,0,"Marosh the Devious - In Combat - Cast Thrash");

-- Blackwood Tracker
DELETE FROM `smart_scripts` WHERE `entryorguid`=11713 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11713,0,1,0,0,0,100,0,6000,12000,30000,40000,11,6950,32,0,0,0,0,2,0,0,0,0,0,0,0,"Blackwood Tracker - In Combat - Cast Faerie Fire");

-- Athrikus Narassin
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=3660;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3660 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3660,0,0,0,5,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Athrikus Narassin - On Killed Unit - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=3660;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(3660,0,0,"Athrikus points at you as he bellows forth words that scrape apart the inside of your ears. They are the last thing you hear.",16,0,100,0,0,0,1223,0,"Athrikus Narassin");
