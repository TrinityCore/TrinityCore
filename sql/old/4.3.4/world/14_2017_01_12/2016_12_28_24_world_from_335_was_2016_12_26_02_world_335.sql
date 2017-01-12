/*
-- 
-- [Q] To Catch A Sparrowhawk -- http://wotlk.openwow.com/quest=10987
-- Watcher Elaira SAI
SET @ENTRY := 22981;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,20,0,100,0,10987,0,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Watcher Elaira - On Quest 'To Catch A Sparrowhawk' Finished - Run Script"),
(@ENTRY,0,1,0,61,0,100,0,10987,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Watcher Elaira - On Quest 'To Catch A Sparrowhawk' Finished - Store Targetlist");

-- Actionlist SAI
SET @ENTRY := 2298100;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,2000,2000,0,0,12,23036,1,17000,0,0,0,8,0,0,0,-1272.48,9164.06,217.776,4.20625,"Watcher Elaira - On Script - Summon Creature 'Captive Sparrowhawk'"),
(@ENTRY,9,1,0,0,0,100,0,2000,2000,0,0,1,0,3000,0,0,0,0,12,1,0,0,0,0,0,0,"Watcher Elaira - On Script - Say Line 0"),
(@ENTRY,9,2,0,0,0,100,0,2000,2000,0,0,45,1,1,0,0,0,0,19,23036,60,0,0,0,0,0,"Watcher Elaira - On Script - Set Data 1 1"),
(@ENTRY,9,3,0,0,0,100,0,0,0,0,0,1,0,4000,0,0,0,0,19,23036,30,0,0,0,0,0,"Watcher Elaira - On Script - Say Line 0"),
(@ENTRY,9,4,0,0,0,100,0,4000,4000,0,0,1,1,4000,0,0,0,0,12,1,0,0,0,0,0,0,"Watcher Elaira - On Script - Say Line 1"),
(@ENTRY,9,5,0,0,0,100,0,4000,4000,0,0,1,2,1000,0,0,0,0,12,1,0,0,0,0,0,0,"Watcher Elaira - On Script - Say Line 2"),
(@ENTRY,9,6,0,0,0,100,0,2000,2000,0,0,45,2,2,0,0,0,0,19,23036,60,0,0,0,0,0,"Watcher Elaira - On Script - Set Data 2 2");

-- Captive Sparrowhawk SAI
SET @ENTRY := 23036;
UPDATE `creature_template` SET `AIName`="SmartAI", `InhabitType`=4 WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,38,0,100,0,1,1,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captive Sparrowhawk - On Data Set 1 1 - Set Run Off"),
(@ENTRY,0,1,0,61,0,100,0,1,1,0,0,69,0,0,0,0,0,0,8,0,0,0,-1273.05,9161.96,217.298,4.34369,"Captive Sparrowhawk - On Data Set 1 1 - Move To Position"),
(@ENTRY,0,2,3,38,0,100,0,2,2,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captive Sparrowhawk - On Data Set 2 2 - Set Run On"),
(@ENTRY,0,3,0,61,0,100,0,2,2,0,0,69,0,0,0,0,0,0,8,0,0,0,-1335.43,9128.58,251.388,3.6604,"Captive Sparrowhawk - On Data Set 2 2 - Move To Position");

DELETE FROM `creature_text` WHERE `entry` IN (22981, 23036);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES 
(22981, 0, 0, 'Come closer, young one. There\'s nothing to fear from me or $n.', 12, 0, 100, 1, 0, 0, 20738, 'Watcher Elaira'),
(23036, 0, 0, '%s cautiously approaches Wather Elaira.', 16, 0, 100, 0, 0, 0, 20739, 'Captive Sparrowhawk'),
(22981, 1, 0, 'I\'m going to train you to help $N with very important task. After that, I promose you\'ll be free to return home.', 12, 0, 100, 1, 0, 0, 20740, 'Watcher Elaira'),
(22981, 2, 0, 'You will hear the call when you are needed. Fly east, to Skettis, and wait there for $N\'s signal.', 12, 0, 100, 1, 0, 0, 20751, 'Watcher Elaira');
*/
