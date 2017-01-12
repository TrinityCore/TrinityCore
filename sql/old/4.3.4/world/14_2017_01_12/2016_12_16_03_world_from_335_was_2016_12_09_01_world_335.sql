/*
-- [Q] Elixir of Agony -- http://wotlk.openwow.com/quest=524
-- Dusty Rug SAI
SET @ENTRY := 1728;
UPDATE `gameobject_template` SET `AIName`="SmartGameObjectAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,1,0,0,20,0,100,0,524,0,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Dusty Rug - On Quest 'Elixir of Agony' Finished - Run Script");

-- Actionlist SAI
SET @ENTRY := 172800;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,50,1729,120,0,0,0,0,8,0,0,0,0.437117,-942.794,61.9384,-2.54818,"Dusty Rug - On Script - Summon Gameobject 'Tainted Keg'"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,9,2284,0,50,0,0,0,0,"Dusty Rug - On Script - Set Data 1 1"),
(@ENTRY,9,2,0,0,0,100,0,12000,12000,0,0,50,1730,110,0,0,0,0,8,0,0,0,0.437117,-942.794,61.9384,-2.54818,"Dusty Rug - On Script - Summon Gameobject 'Tainted Keg Smoke'");

-- Captured Farmer SAI
SET @GUID := -15892;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2284;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,38,0,100,0,1,1,0,0,80,1589200,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Farmer - On Data Set 1 1 - Run Script");

-- Actionlist SAI
SET @ENTRY := 1589200;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,3000,3000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Farmer - On Script - Say Line 0"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,-0.954329,-942.685,61.938,6.23103,"Captured Farmer - On Script - Move To Position"),
(@ENTRY,9,2,0,0,0,100,0,3000,3000,0,0,5,16,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Farmer - On Script - Set Emote State kneel"),
(@ENTRY,9,3,0,0,0,100,0,1000,1000,0,0,5,26,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Farmer - On Script - Set Emote State stand"),
(@ENTRY,9,4,0,0,0,100,0,3000,3000,0,0,5,418,0,0,0,0,0,7,0,0,0,0,0,0,0,"Captured Farmer - On Script - Set Emote State Eat"),
(@ENTRY,9,5,0,0,0,100,0,5000,5000,0,0,51,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Farmer - On Script - Kill Target");

-- Captured Farmer SAI
SET @GUID := -15891;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2284;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,38,0,100,0,1,1,0,0,80,1589100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Farmer - On Data Set 1 1 - Run Script");

-- Actionlist SAI
SET @ENTRY := 1589100;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,4000,4000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Farmer - On Script - Say Line 0"),
(@ENTRY,9,1,0,0,0,100,0,2000,2000,0,0,5,16,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Farmer - On Script - Set Emote State kneel"),
(@ENTRY,9,2,0,0,0,100,0,1000,1000,0,0,5,26,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Farmer - On Script - Set Emote State stand"),
(@ENTRY,9,3,0,0,0,100,0,3000,3000,0,0,5,418,0,0,0,0,0,7,0,0,0,0,0,0,0,"Captured Farmer - On Script - Set Emote State Eat"),
(@ENTRY,9,4,0,0,0,100,0,5000,5000,0,0,51,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Farmer - On Script - Kill Target");

-- Captured Farmer SAI
SET @GUID := -15893;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2284;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,38,0,100,0,1,1,0,0,80,1589300,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Farmer - On Data Set 1 1 - Run Script");

-- Actionlist SAI
SET @ENTRY := 1589300;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,3000,3000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Farmer - On Script - Say Line 0"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,0.542607,-941.692,61.9395,4.71364,"Captured Farmer - On Script - Move To Position"),
(@ENTRY,9,2,0,0,0,100,0,3000,3000,0,0,5,16,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Farmer - On Script - Set Emote State kneel"),
(@ENTRY,9,3,0,0,0,100,0,1000,1000,0,0,5,26,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Farmer - On Script - Set Emote State stand"),
(@ENTRY,9,4,0,0,0,100,0,3000,3000,0,0,5,418,0,0,0,0,0,7,0,0,0,0,0,0,0,"Captured Farmer - On Script - Set Emote State Eat"),
(@ENTRY,9,5,0,0,0,100,0,5000,5000,0,0,51,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Farmer - On Script - Kill Target");


DELETE FROM `creature_text` WHERE `entry`=2284;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES 
(2284, 0, 0, 'Finally they show mercy!  They''ve given us something to drink!', 12, 0, 100, 0, 0, 0, 581, 'Captured Farmer'),
(2284, 1, 0, 'And Shindigger Stout too!  Thank the Light!  I was parched!', 12, 0, 100, 0, 0, 0, 582, 'Captured Farmer');

-- Captured Farmer
UPDATE creature SET spawntimesecs = 90 WHERE id = 2284;
-- Tainted Keg - respawntime updated
DELETE FROM `gameobject` WHERE `guid`=30031;
*/
