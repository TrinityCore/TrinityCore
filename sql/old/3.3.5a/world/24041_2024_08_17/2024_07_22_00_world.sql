-- Return to Obadei 9423 / Makuru's Vengeance 9424

-- Add Anchorite Obadei text
DELETE FROM `creature_text` WHERE `CreatureID`=16834;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(16834,0,0,"What have you done, Makuru?!  These are not our ways!",12,0,100,0,0,0,13991,0,'Anchorite Obadei'),
(16834,1,0,"I understand how you feel Makuru.  Sedai was my brother after all.  Yet we can't disgrace his memory by going against his very ideals.",12,0,100,0,0,0,13992,0,'Anchorite Obadei');

-- Add Makuru text
DELETE FROM `creature_text` WHERE `CreatureID` = 16833 AND `GroupID` IN (0,1);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(16833,0,0,"No!  Not... Sedai!  The orcs must pay!",12,0,100,0,0,0,13997,0,'Makuru'),
(16833,1,0,"The orcs hate us, Obadei!  They've killed many of us before!  They deserve death and worse.",12,0,100,0,0,0,13996,0,'Makuru');

-- "Return to Obadei" Script
DELETE FROM `smart_scripts` WHERE `entryorguid`=16834 AND `source_type`=0 AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(16834,0,0,0,20,0,100,0,9423,0,0,0,0,1,0,0,0,0,0,0,19,16833,0,0,0,0,0,0,0,"Anchorite Obadei - On Quest 'Return to Obadei' Rewarded - Makuru Say Line 0");

-- "Makurus Vengeance" Script
DELETE FROM `smart_scripts` WHERE `entryorguid`=16833 AND `source_type`=0 AND `id` IN (0,1,2,3);
DELETE FROM `smart_scripts` WHERE `entryorguid`=16834 AND `source_type`=0 AND `id` IN (1,2,3);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (1683300,1683400) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(16833,0,1,0,20,0,100,0,9424,25000,25000,0,0,80,1683300,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Makuru - On Quest 'Makurus Vengeance' Rewarded - Run Script"),

(16834,0,1,2,38,0,100,0,0,1,0,0,0,83,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Anchorite Obadei - On Data Set - Remove Gossip + Quest Giver npc flag"),
(16834,0,2,0,61,0,100,0,0,0,0,0,0,53,0,16834,0,0,0,0,1,0,0,0,0,0,0,0,0,"Anchorite Obadei - On Link - Start WP"),
(16834,0,3,0,40,0,100,0,2,16834,0,0,0,80,1683400,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Anchorite Obadei - On Waypoint 2 Reached - Run Script"),

(1683300,9,0,0,0,0,100,0,0,0,0,0,0,45,0,1,0,0,0,0,19,16834,0,0,0,0,0,0,0,"Makuru - On Script - Set Data to Anchorite Obadei"),
(1683300,9,1,0,0,0,100,0,5000,5000,0,0,0,66,0,0,0,0,0,0,19,16834,0,0,0,0,0,0,0,"Makuru - On Script - Set Orientation"),
(1683300,9,2,0,0,0,100,0,20000,20000,0,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Makuru - On Script - Set Orientation Home Position"),

(1683400,9,3,0,0,0,100,0,0,0,0,0,0,54,20000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Anchorite Obadei - On Script - Pause Waypoint"),
(1683400,9,4,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,19,16833,0,0,0,0,0,0,0,"Anchorite Obadei - On Script - Set Orientation"),
(1683400,9,5,0,0,0,100,0,1000,1000,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Anchorite Obadei - On Script - Say Line 0"),
(1683400,9,6,0,0,0,100,0,7000,7000,0,0,0,1,1,0,0,0,0,0,19,16833,0,0,0,0,0,0,0,"Anchorite Obadei - On Script - Say Line 1 (Makuru)"),
(1683400,9,7,0,0,0,100,0,4000,4000,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Anchorite Obadei - On Script - Say Line 1"),
(1683400,9,8,0,0,0,100,0,10000,10000,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0,4.643,"Anchorite Obadei - On Script - Set Orientation"),
(1683400,9,9,0,0,0,100,0,1000,1000,0,0,0,82,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Anchorite Obadei - Script Set - Add Gossip + Quest Giver npc flag");

-- Waypoints
DELETE FROM `waypoints` WHERE `entry`=16834;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(16834,1,93.944,4345.056,101.698,"Anchorite Obadei"),
(16834,2,96.005,4344.833,101.767,"Anchorite Obadei"),
(16834,3,93.944,4345.056,101.698,"Anchorite Obadei"),
(16834,4,90.838,4351.730,103.178,"Anchorite Obadei");
