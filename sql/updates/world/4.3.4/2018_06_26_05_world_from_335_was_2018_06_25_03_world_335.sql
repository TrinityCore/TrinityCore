/*
-- Corporal Sethman
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1422;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1422 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=142200 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(1422,0,0,0,20,0,100,0,330,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Corporal Sethman - On Quest 'Patrol Schedules' Finished - Store Targetlist"),
(1422,0,1,0,20,0,100,0,330,0,0,0,0,80,142200,0,0,0,0,0,1,0,0,0,0,0,0,0,"Corporal Sethman - On Quest 'Patrol Schedules' Finished - Run Script"),
(142200,9,0,0,0,0,100,0,0,0,0,0,0,45,1,1,0,0,0,0,19,1421,0,0,0,0,0,0,"Corporal Sethman - On Script - Set Data to Private Merle"),
(142200,9,1,0,0,0,100,0,0,0,0,0,0,100,1,0,0,0,0,0,19,1421,0,0,0,0,0,0,"Corporal Sethman - On Script - Send Target");

-- Private Merle
UPDATE `creature` SET `spawntimesecs`=10 WHERE `guid` IN (2243,1626);

DELETE FROM `creature_text` WHERE `CreatureID`=1421;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(1421,0,0,"Curse you, $n!  One day, vengeance will be mine!",14,7,100,14,0,0,229,0,"Private Merle");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1421;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1421 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (142100,142101,142102,142103,142104) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(1421,0,0,0,38,0,100,1,1,1,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Private Merle - On Data Set - Set Active On"),
(1421,0,1,0,38,0,100,1,1,1,0,0,0,53,1,1421,0,0,0,2,1,0,0,0,0,0,0,0,"Private Merle - On Data Set - Start Waypoint"),
(1421,0,2,0,38,0,100,1,1,1,0,0,0,2,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Private Merle - On Data Set - Set Faction 7"),
(1421,0,3,0,40,0,100,0,2,1421,0,0,0,80,142100,2,0,0,0,0,1,0,0,0,0,0,0,0,"Private Merle - On Waypoint 2 Reached - Run Script"),
(1421,0,4,0,40,0,100,0,14,1421,0,0,0,80,142101,2,0,0,0,0,1,0,0,0,0,0,0,0,"Private Merle - On Waypoint 14 Reached - Run Script"),
(142100,9,0,0,0,0,100,0,0,0,0,0,0,54,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Private Merle - On Script - Pause Waypoint"),
(142100,9,1,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,12,1,0,0,0,0,0,0,"Private Merle - On Script - Set Orientation"),
(142100,9,2,0,0,0,100,0,500,500,0,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,"Private Merle - On Script - Say Line 0"),
(142101,9,0,0,0,0,100,0,0,0,0,0,0,12,604,1,10000,0,0,0,8,0,0,0,-11293,-370.476,64.4972,3.08568,"Private Merle - On Script - Summon Creature 'Plague Spreader'"),
(142101,9,1,0,0,0,100,0,0,0,0,0,0,12,604,1,10000,0,0,0,8,0,0,0,-11295.3,-359.83,63.561,4.18131,"Private Merle - On Script - Summon Creature 'Plague Spreader'"),
(142101,9,2,0,0,0,100,0,0,0,0,0,0,12,604,1,10000,0,0,0,8,0,0,0,-11291,-364.689,64.1733,3.44304,"Private Merle - On Script - Summon Creature 'Plague Spreader'"),
(142101,9,3,0,0,0,100,0,5000,5000,0,0,0,2,33,0,0,0,0,0,1,0,0,0,0,0,0,0,"Private Merle - On Script - Set Faction 33"),
(142101,9,4,0,0,0,100,0,0,0,0,0,0,45,1,1,0,0,0,0,11,604,30,0,0,0,0,0,"Private Merle - On Script - Set Data to Plague Spreader"),
(142101,9,5,0,0,0,100,0,0,0,0,0,0,41,60000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Private Merle - On Script - Despawn in 60 seconds");

DELETE FROM `waypoints` WHERE `entry`=1421;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(1421,1,-11330.5,-224.416,75.2209,""),
(1421,2,-11321.5,-201.289,75.7666,""),
(1421,3,-11342.3,-212.545,75.2202,""),
(1421,4,-11371.4,-215.524,75.2802,""),
(1421,5,-11378.1,-225.526,74.0602,""),
(1421,6,-11380.6,-235.847,69.3212,""),
(1421,7,-11381.2,-253.24,64.1387,""),
(1421,8,-11388.2,-273.483,59.8605,""),
(1421,9,-11387.9,-287.5,59.4897,""),
(1421,10,-11381.8,-317.855,65.0236,""),
(1421,11,-11366.9,-365.866,65.9376,""),
(1421,12,-11355.5,-381.122,65.1301,""),
(1421,13,-11344.7,-381.814,65.1715,""),
(1421,14,-11300.1,-368.146,65.676,"");

-- Plague Spreader
DELETE FROM `smart_scripts` WHERE `entryorguid`=604 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(604,0,2,0,38,0,100,0,1,1,0,0,0,49,0,0,0,0,0,0,19,1421,0,0,0,0,0,0,"Plague Spreader - On Data Set - Start Attacking");
*/
