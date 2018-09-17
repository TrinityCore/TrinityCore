/*
--
-- Apprentice Morlann
DELETE FROM `creature_text` WHERE `CreatureID` IN (23600,23601);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(23600,0,0,"Hmm... I wonder...",12,0,100,0,0,0,22042,0,"Apprentice Morlann"),
(23600,1,0,"Now, where is it?",12,0,100,6,0,0,22045,0,"Apprentice Morlann"),
(23600,2,0,"Stupid mages... always using the last of a reagent and never replacing it.",12,0,100,1,0,0,22043,0,"Apprentice Morlann"),
(23601,0,0,"Is he complaining about the reagents again? Does he even remember how he left the summoning tomes last time?",12,0,100,6,0,0,22044,0,"Apprentice Garion");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=23600;
DELETE FROM `smart_scripts` WHERE `entryorguid`=23600 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2360000,2360001) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(23600,0,0,0,25,0,100,0,0,0,0,0,0,53,0,23600,1,0,0,0,1,0,0,0,0,0,0,0,"Apprentice Garion - On Reset - Start Waypoint"),
(23600,0,1,0,40,0,100,0,1,23600,0,0,0,80,2360000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Apprentice Garion - On Waypoint 1 Reached - Run Script"),
(23600,0,2,0,40,0,100,0,4,23600,0,0,0,80,2360001,0,0,0,0,0,1,0,0,0,0,0,0,0,"Apprentice Garion - On Waypoint 4 Reached - Run Script"),
(23600,0,3,0,40,0,100,0,6,23600,0,0,0,54,180000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Apprentice Garion - On Waypoint 6 Reached - Pause Waypoint"),
(2360000,9,0,0,0,0,100,0,0,0,0,0,0,54,6000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Apprentice Garion - On Script - Pause Waypoint"),
(2360000,9,1,0,0,0,100,0,1000,1000,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Apprentice Garion - On Script - Say Line 0"),
(2360000,9,2,0,0,0,100,0,5000,5000,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Apprentice Garion - On Script - Say Line 1"),
(2360001,9,0,0,0,0,100,0,0,0,0,0,0,54,14000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Apprentice Garion - On Script - Pause Waypoint"),
(2360001,9,1,0,0,0,100,0,2000,2000,0,0,0,5,16,0,0,0,0,0,1,0,0,0,0,0,0,0,"Apprentice Garion - On Script - Play Emote 'Kneel'"),
(2360001,9,2,0,0,0,100,0,6000,6000,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Apprentice Garion - On Script - Say Line 2"),
(2360001,9,3,0,0,0,100,0,6000,6000,0,0,0,1,0,0,0,0,0,0,19,23601,0,0,0,0,0,0,"Apprentice Garion - On Script - Say Line 0 (Apprentice Garion)");

DELETE FROM `waypoints` WHERE `entry`=23600;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(23600,1,-4044.27,-3393.28,38.1284,""),
(23600,2,-4045.51,-3394.92,38.1749,""),
(23600,3,-4042.77,-3396.91,38.1887,""),
(23600,4,-4040.72,-3397.23,38.1476,""),
(23600,5,-4043.21,-3395.28,38.1581,""),
(23600,6,-4043.43,-3395.4,38.2663,"");

UPDATE `creature` SET `MovementType`=0 WHERE `guid`=18604;
UPDATE `creature_addon` SET `path_id`=0 WHERE `guid`=18604;
DELETE FROM `waypoint_data` WHERE `id`=186040;
DELETE FROM `waypoint_scripts` WHERE `id` IN (1006,1007,1008);
*/
