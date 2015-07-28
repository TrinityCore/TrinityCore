-- 4.x + 6.x
-- Duokna SAI
SET @ENTRY := 3158;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,2000,2000,30000,30000,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Duokna - Out of Combat - Run Script");

-- Actionlist SAI
SET @ENTRY := 315800;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,69,1,0,0,0,0,0,8,0,0,0,-563.079041,-4217.333,42.8817,5.002828,"On Script - Move To Position"),
(@ENTRY,9,1,0,0,0,100,0,3000,3000,0,0,17,10,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Set Emote State 10"),
(@ENTRY,9,2,0,0,0,100,0,2000,2000,0,0,1,0,0,0,0,0,0,19,9796,20,0,0,0,0,0,"On Script - Say Line 0"),
(@ENTRY,9,3,0,0,0,100,0,8000,8000,0,0,69,2,0,0,0,0,0,8,0,0,0,-565.393,-4213.930,41.661,0,"On Script - Move To Position"),
(@ENTRY,9,4,0,0,0,100,0,0,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Set Emote State 0"),
(@ENTRY,9,5,0,0,0,100,0,3000,3000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,5.183630,"On Script - Set Orientation 5,183630");

DELETE FROM `creature_text` WHERE `entry`=9796;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES 
(9796, 0, 0, 'Duokna... this is embarrassing.', 12, 0, 100, 0, 0, 0, 39266, 'Galgar'),
(9796, 0, 1, 'Duokna, what are you doing?', 12, 0, 100, 0, 0, 0, 39267, 'Galgar'),
(9796, 0, 2, 'Get down from there this instant!', 12, 0, 100, 0, 0, 0, 39268, 'Galgar'),
(9796, 0, 3, 'How are you not burning your feet?', 12, 0, 100, 0, 0, 0, 39269, 'Galgar');
