-- Quest "The Final Code" --> Outro Event
-- Texts
DELETE FROM `creature_text` WHERE `CreatureID` IN (18459,21400,21397);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(18459,0,0,"Rejoice, my friends! $n has saved us from the looming shadow that threatened our very lives!",14,7,100,22,0,0,19075,0,"Jenai Starwhisper"),
(21400,0,0,"We're saved? We're really saved?! YAHOO!",12,7,100,5,0,0,19076,0,"Eckert"),
(21400,1,0,"It's time to PARTY!",12,7,100,0,0,0,19077,0,"Eckert"),
(21397,0,0,"%s applauds lightly, smiling.",16,0,100,21,0,0,19078,0,"Aeman Brightsong"),
(21397,1,0,"How fortuitous. I believe this calls for some wine.",12,7,100,1,0,0,19079,0,"Aeman Brightsong"),
(21397,2,0,"A fine vintage in celebration of our salvation!",12,7,100,1,0,0,19080,0,"Aeman Brightsong");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=18459;
DELETE FROM `smart_scripts` WHERE `entryorguid`=18459 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1845900 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(18459,0,0,0,11,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jenai Starwhisper - On Respawn - Set Event Phase 1"),
(18459,0,1,0,20,1,100,0,10446,0,0,0,80,1845900,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jenai Starwhisper - On Quest 'The Final Code' Finished - Run Script"),
(1845900,9,0,0,0,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jenai Starwhisper - On Script - Set Event Phase 0"),
(1845900,9,1,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jenai Starwhisper - On Script - Say Line 0"),
(1845900,9,2,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,19,21400,0,0,0,0,0,0,"Jenai Starwhisper - On Script - Set Data to Eckert"),
(1845900,9,3,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,19,21397,0,0,0,0,0,0,"Jenai Starwhisper - On Script - Set Data to Aeman Brightsong"),
(1845900,9,4,0,0,0,100,0,60000,60000,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jenai Starwhisper - On Script - Set Event Phase 1");

-- Eckert
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=21400;
DELETE FROM `smart_scripts` WHERE `entryorguid`=21400 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2140000 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(21400,0,0,0,38,0,100,0,1,1,0,0,53,1,21400,0,0,0,0,1,0,0,0,0,0,0,0,"Eckert - On Data Set - Start Waypoint"),
(21400,0,1,0,38,0,100,0,1,1,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eckert - On Data Set - Set Emote State 'None'"),
(21400,0,2,0,40,0,100,0,1,21400,0,0,54,6000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eckert - On Waypoint 1 Reached - Pause Waypoint"),
(21400,0,3,0,40,0,100,0,1,21400,0,0,80,2140000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eckert - On Waypoint 1 Reached - Run Script"),
(21400,0,4,0,40,0,100,0,2,21400,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,3.71374,"Eckert - On Waypoint 2 Reached - Set Orientation"),
(21400,0,5,0,40,0,100,0,2,21400,0,0,17,10,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eckert - On Waypoint 2 Reached - Set Emote State 'Dance'"),
(21400,0,6,0,40,0,100,0,2,21400,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eckert - On Waypoint 2 Reached - Say Line 1"),
(2140000,9,0,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,1.34305,"Eckert - On Script - Set Orientation"),
(2140000,9,1,0,0,0,100,0,500,500,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eckert - On Script - Say Line 0"),
(2140000,9,2,0,0,0,100,0,3000,3000,0,0,5,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eckert - On Script - Play Emote 'Cheer'");

-- Aeman Brightsong
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=21397;
DELETE FROM `smart_scripts` WHERE `entryorguid`=21397 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2139700,2139701) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(21397,0,0,0,38,0,100,0,1,1,0,0,53,0,21397,0,0,0,0,1,0,0,0,0,0,0,0,"Aeman Brightsong - On Data Set - Start Waypoint"),
(21397,0,1,0,40,0,100,0,1,21397,0,0,54,9000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aeman Brightsong - On Waypoint 1 Reached - Pause Waypoint"),
(21397,0,2,0,40,0,100,0,1,21397,0,0,80,2139700,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aeman Brightsong - On Waypoint 1 Reached - Run Script"),
(21397,0,3,0,40,0,100,0,2,21397,0,0,80,2139701,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aeman Brightsong - On Waypoint 2 Reached - Run Script"),
(2139700,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aeman Brightsong - On Script - Say Line 0"),
(2139700,9,1,0,0,0,100,0,3000,3000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aeman Brightsong - On Script - Say Line 1"),
(2139701,9,0,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,5.56465,"Aeman Brightsong - On Script - Set Orientation"),
(2139701,9,1,0,0,0,100,0,0,0,0,0,41,0,0,0,0,0,0,15,184753,20,0,0,0,0,0,"Aeman Brightsong - On Script - Despawn Gameobject 'Brightsong Wine'"),
(2139701,9,2,0,0,0,100,0,0,0,0,0,50,184753,300,0,0,0,0,8,0,0,0,-2965.37,4012.68,1.49919,6.03974,"Aeman Brightsong - On Script - Summon Gameobject 'Brightsong Wine'"),
(2139701,9,3,0,0,0,100,0,500,500,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aeman Brightsong - On Script - Say Line 2");

-- WP
DELETE FROM `waypoints` WHERE `entry` IN (21400,21397);
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(21400,1,-2930.29,3996.8,-0.606507,""),
(21400,2,-2919.26,3969.4,0.28936,""),
(21397,1,-2938.29,4007.75,-1.12266,""),
(21397,2,-2965.84,4011.33,1.37422,"");
