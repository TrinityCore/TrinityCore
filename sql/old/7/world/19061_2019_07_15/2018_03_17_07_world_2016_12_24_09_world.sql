-- 
-- [Q] Birds of a Feather -- http://wotlk.openwow.com/quest=9397
UPDATE `creature` SET `MovementType`=0 WHERE  `guid`=57793;
DELETE FROM `creature_addon` WHERE  `guid`=57793;
DELETE FROM `waypoint_data` WHERE `id`=577930;
-- Falconer Drenna Riverwind SAI
SET @ENTRY := 16790;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,20,0,100,0,9397,0,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Falconer Drenna Riverwind - On Quest 'Birds of a Feather' Finished - Run Script"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Falconer Drenna Riverwind - On Quest 'Birds of a Feather' Finished - Store Targetlist");

-- Actionlist SAI
SET @ENTRY := 1679000;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Set Run Off"),
(@ENTRY,9,1,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,-597.806,4110.68,90.848,2.02116,"On Script - Move To Position"),
(@ENTRY,9,2,0,0,0,100,0,2000,2000,0,0,5,16,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Play Emote 16"),
(@ENTRY,9,3,0,0,0,100,0,2000,2000,0,0,12,17262,1,20000,0,0,0,8,0,0,0,-597.244,4111.88,90.7789,0.805268,"On Script - Summon Creature 'Captive Female Kaliri'"),
(@ENTRY,9,4,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,"On Script - Say Line 0"),
(@ENTRY,9,5,0,0,0,100,0,4000,4000,0,0,69,0,0,0,0,0,0,8,0,0,0,-596.347,4108.47,91.0061,5.15176,"On Script - Move To Position"),
(@ENTRY,9,6,0,0,0,100,0,2000,2000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.10152,"On Script - Set Orientation 4,10152");

DELETE FROM `creature_text` WHERE `CreatureID`=16790;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `Comment`) VALUES 
(16790, 0, 0, 'Thank you, $N. It looks like they''re going to get along just fine.', 12, 0, 100, 0, 0, 0, 13666, 'Falconer Drenna Riverwind');
