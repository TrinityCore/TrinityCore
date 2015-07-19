-- Master Gadrin SAI
SET @ENTRY := 3188;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,20,0,100,0,808,0,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Master Gadrin - On Quest 'Minshina's Skull' Finished - Run Script");

-- Actionlist SAI
SET @ENTRY := 318800;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,2000,2000,0,0,12,3289,5,14000,0,0,0,8,0,0,0,-822.91,-4923.33,19.6365,3.41642,"Master Gadrin - On Script - Summon Creature 'Spirit of Minshina'"),
(@ENTRY,9,1,0,0,0,100,0,2000,2000,0,0,66,0,0,0,0,0,0,21,20,0,0,0,0,0,0,"Master Gadrin - On Script - Set Orientation Closest Player"),
(@ENTRY,9,2,0,0,0,100,0,3000,3000,0,0,1,0,0,0,0,0,0,21,20,0,0,0,0,0,0,"Master Gadrin - On Script - Say Line 0");

-- Spirit of Minshina SAI
SET @ENTRY := 3289;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,0,0,0,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Spirit of Minshina - On Just Summoned - Run Script");

-- Actionlist SAI
SET @ENTRY := 328900;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,2000,2000,0,0,66,0,0,0,0,0,0,21,20,0,0,0,0,0,0,"Spirit of Minshina - On Script - Set Orientation Closest Player"),
(@ENTRY,9,1,0,0,0,100,0,2000,2000,0,0,5,2,0,0,0,0,0,1,2000,2000,0,0,0,0,0,"Spirit of Minshina - On Script - Play Emote 2"),
(@ENTRY,9,2,0,0,0,100,0,11000,11000,0,0,41,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spirit of Minshina - On Script - Despawn Instant");

DELETE FROM `creature_text` WHERE `entry`=3188;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES 
(3188, 0, 0, 'I thank you, $n.  And my brother thanks you.', 12, 0, 100, 0, 0, 0, 'Master Gadrin', 983);
