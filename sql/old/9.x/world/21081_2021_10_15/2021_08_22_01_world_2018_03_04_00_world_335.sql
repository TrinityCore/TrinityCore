-- Fix availability for quest "Zamek's Distraction"
UPDATE `quest_template_addon` SET `PrevQuestID`=0 WHERE `ID`=1191;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceEntry`=1191;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(19,0,1191,0,0,28,0,1190,0,0,0,0,0,'',"Show quest 'Zamek's Distraction' only if quest 'Keeping Pace' is taken but not rewarded"),
(19,0,1191,0,1,8,0,1190,0,0,0,0,0,'',"Show quest 'Zamek's Distraction' only if quest 'Keeping Pace' is rewarded"),
(19,0,1191,0,1,14,0,1194,0,0,0,0,0,'',"Show quest 'Zamek's Distraction' only if quest 'Rizzle's Schematics' is not taken and not rewarded");

-- Add gossip text for gameobjects "Rizzle's Guarded Plans" & "Rizzle's Unguarded Plans"
UPDATE `gossip_menu` SET `TextID`=7182 WHERE `MenuID`=6029;
UPDATE `gossip_menu` SET `TextID`=7181 WHERE `MenuID`=6030;

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID` IN (4709,4720);
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(4709,0,0,'Hehehe! Things go boom!',12,0,100,11,0,0,1540,0,'Zamek'),
(4720,0,0,'What was that!',14,0,100,5,0,0,1541,0,'Rizzle Brassbolts'),
(4720,1,0,"Bloody... Must have been the goblins... Let's see how bad the damage is.",12,0,100,5,0,0,1542,0,'Rizzle Brassbolts'),
(4720,2,0,"Guess there's nothing more to be done. Blast!",12,0,100,6,0,0,1543,0,'Rizzle Brassbolts');

-- Waypoints
DELETE FROM `waypoints` WHERE `entry` IN (4709,4720);
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(4709, 1,-6237.13,-3911.58,-60.5103,'Zamek'),
(4709, 2,-6257.43,-3879.56,-58.8595,'Zamek'),
(4709, 3,-6267.61,-3850.91,-58.7503,'Zamek'),
(4709, 4,-6266.24,-3846.35,-58.7503,'Zamek'),
(4709, 5,-6267.61,-3850.91,-58.7503,'Zamek'),
(4709, 6,-6257.43,-3879.56,-58.8595,'Zamek'),
(4709, 7,-6237.13,-3911.58,-60.5103,'Zamek'),
(4709, 8,-6226.13,-3944.94,-58.6251,'Zamek'),
(4720, 1,-6243.39,-3845.91,-58.7498,'Rizzle Brassbolts'),
(4720, 2,-6250.63,-3847.35,-58.7491,'Rizzle Brassbolts'),
(4720, 3,-6255.06,-3853.64,-58.7491,'Rizzle Brassbolts'),
(4720, 4,-6262.2, -3851.84,-58.7491,'Rizzle Brassbolts'),
(4720, 5,-6266.24,-3846.35,-58.7503,'Rizzle Brassbolts'),
(4720, 6,-6262.2, -3851.84,-58.7491,'Rizzle Brassbolts'),
(4720, 7,-6255.06,-3853.64,-58.7491,'Rizzle Brassbolts'),
(4720, 8,-6250.63,-3847.35,-58.7491,'Rizzle Brassbolts'),
(4720, 9,-6243.39,-3845.91,-58.7498,'Rizzle Brassbolts'),
(4720,10,-6236.99,-3831.23,-58.1364,'Rizzle Brassbolts');

-- Zamek
DELETE FROM `smart_scripts` WHERE `entryorguid`=4709 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=470900 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(4709,0,0,0,20,0,100,0,1191,0,0,0,53,1,4709,0,0,0,0,1,0,0,0,0,0,0,0,"Zamek - On Quest 'Zamek's Distraction' Finished - Start Waypoint"),
(4709,0,1,0,20,0,100,0,1191,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Zamek - On Quest 'Zamek's Distraction' Finished - Remove NPC Flag Questgiver"),
(4709,0,2,0,40,0,100,0,4,4709,0,0,80,470900,0,0,0,0,0,1,0,0,0,0,0,0,0,'Zamek - On Waypoint 4 Reached - Run Script'),
(4709,0,3,0,40,0,100,0,8,4709,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Zamek - On Waypoint 8 Reached - Set Orientation'),
(470900,9,0,0,0,0,100,0,0,0,0,0,54,7000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Zamek - On Script - Pause Waypoint'),
(470900,9,1,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0.943443,'Zamek - On Script - Set Orientation'),
(470900,9,2,0,0,0,100,0,2000,2000,0,0,50,144065,8,0,0,0,0,8,0,0,0,-6265.67,-3845.57,-58.75,0.943443,"Zamek - On Script - Summon Gameobject 'Explosive Charge'"),
(470900,9,3,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Zamek - On Script - Say Line 0'),
(470900,9,4,0,0,0,100,0,7000,7000,0,0,9,0,0,0,0,0,0,20,144065,0,0,0,0,0,0,"Zamek - On Script - Activate Gameobject 'Explosive Charge'"),
(470900,9,5,0,0,0,100,0,1000,1000,0,0,45,1,1,0,0,0,0,19,4720,0,0,0,0,0,0,'Zamek - On Script - Set Data to Rizzle Brassbolts'),
(470900,9,6,0,0,0,100,0,60000,60000,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Zamek - On Script - Add NPC Flag Questgiver');

-- Rizzle Brassbolts
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4720;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4720 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (472000,472001) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(4720,0,0,0,38,0,100,0,1,1,0,0,80,472000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Rizzle Brassbolts - On Data Set - Run Script'),
(4720,0,1,0,40,0,100,0,5,4720,0,0,80,472001,0,0,0,0,0,1,0,0,0,0,0,0,0,'Rizzle Brassbolts - On Waypoint 5 Reached - Run Script'),
(4720,0,2,0,40,0,100,0,10,4720,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Rizzle Brassbolts - On Waypoint 10 Reached - Set Orientation'),
(472000,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Rizzle Brassbolts - On Script - Say Line 0'),
(472000,9,1,0,0,0,100,0,4000,4000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Rizzle Brassbolts - On Script - Say Line 1'),
(472000,9,2,0,0,0,100,0,0,0,0,0,53,0,4720,0,0,0,0,1,0,0,0,0,0,0,0,'Rizzle Brassbolts - On Script - Start Waypoint'),
(472000,9,3,0,0,0,100,0,0,0,0,0,41,0,60,0,0,0,0,14,17087,179888,0,0,0,0,0,"Rizzle Brassbolts - On Script - Despawn Gameobject 'Rizzle's Guarded Plans'"),
(472000,9,4,0,0,0,100,0,0,0,0,0,70,60,0,0,0,0,0,14,13621,20805,0,0,0,0,0,"Rizzle Brassbolts - On Script - Respawn Gameobject 'Rizzle's Unguarded Plans'"),
(472001,9,0,0,0,0,100,0,0,0,0,0,54,25000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Rizzle Brassbolts - On Script - Pause Waypoint'),
(472001,9,1,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0.943443,'Rizzle Brassbolts - On Script - Set Orientation'),
(472001,9,2,0,0,0,100,0,20000,20000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Rizzle Brassbolts - On Script - Say Line 2');
