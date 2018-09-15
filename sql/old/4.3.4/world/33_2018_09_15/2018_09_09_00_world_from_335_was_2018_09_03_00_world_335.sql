/*
-- 
DELETE FROM `smart_scripts` WHERE `entryorguid`=738 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (73800,73803,73804) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(738,0,1,0,11,0,100,0,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Private Thorsen - On Respawn - Set Active On"),
(738,0,2,0,11,0,100,0,0,0,0,0,0,80,73800,2,0,0,0,0,1,0,0,0,0,0,0,0,"Private Thorsen - On Respawn - Run Sript"),
(738,0,3,0,40,0,100,0,14,73800,0,0,0,80,73801,2,0,0,0,0,1,0,0,0,0,0,0,0,"Private Thorsen - On Waypoint 14 Reached - Run Script"),
(738,0,4,0,40,0,100,0,16,73800,0,0,0,80,73802,2,0,0,0,0,1,0,0,0,0,0,0,0,"Private Thorsen - On Waypoint 16 Reached - Run Script"),
(738,0,5,0,38,0,100,0,1,1,0,0,0,80,73803,0,0,0,0,0,1,0,0,0,0,0,0,0,"Private Thorsen - On Data Set - Run Script"),
(738,0,6,0,40,0,100,0,16,73801,0,0,0,80,73804,2,0,0,0,0,1,0,0,0,0,0,0,0,"Private Thorsen - On Waypoint 16 Reached - Run Script"),
(73800,9,0,0,0,0,100,0,600000,600000,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Private Thorsen - On Script - Say Line 0"),
(73800,9,1,0,0,0,100,0,5000,5000,0,0,0,53,0,73800,0,0,0,2,1,0,0,0,0,0,0,0,"Private Thorsen - On Script - Start Waypoint"),
(73800,9,2,0,0,0,100,0,0,0,0,0,0,83,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Private Thorsen - On Script - Remove Npc Flag Questgiver"),
(73803,9,0,0,0,0,100,0,2000,2000,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Private Thorsen - On Script - Say Line 3"),
(73803,9,1,0,0,0,100,0,0,0,0,0,0,82,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Private Thorsen - On Script - Add Npc Flag Questgiver"),
(73803,9,3,0,0,0,100,0,120000,120000,0,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Private Thorsen - On Script - Say Line 4"),
(73803,9,4,0,0,0,100,0,5000,5000,0,0,0,53,0,73801,0,0,0,2,1,0,0,0,0,0,0,0,"Private Thorsen - On Script - Start Waypoint"),
(73803,9,5,0,0,0,100,0,0,0,0,0,0,83,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Private Thorsen - On Script - Remove Npc Flag Questgiver"),
(73804,9,0,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,5.5676,"Private Thorsen - On Script - Set Orientation"),
(73804,9,1,0,0,0,100,0,0,0,0,0,0,82,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Private Thorsen - On Script - add Npc Flag Questgiver"),
(73804,9,2,0,0,0,100,0,500,500,0,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Private Thorsen - On Script - Say Line 5"),
(73804,9,3,0,0,0,100,0,7000,7000,0,0,0,1,0,0,0,0,0,0,19,733,0,0,0,0,0,0,"Private Thorsen - On Script - Say Line 0 (Sergeant Yohwa)"),
(73804,9,4,0,0,0,100,0,900000,900000,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Private Thorsen - On Script - Say Line 0"),
(73804,9,6,0,0,0,100,0,5000,5000,0,0,0,53,0,73800,0,0,0,2,1,0,0,0,0,0,0,0,"Private Thorsen - On Script - Start Waypoint"),
(73804,9,5,0,0,0,100,0,0,0,0,0,0,83,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Private Thorsen - On Script - Remove Npc Flag Questgiver");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceEntry`=215;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(19,0,215,0,0,23,0,99,0,0,1,0,0,"","Quest 'Jungle Secrets' can only be taken if Private Thorsen is not in area 99");
*/
