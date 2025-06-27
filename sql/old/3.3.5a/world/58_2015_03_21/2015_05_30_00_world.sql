-- 
-- Niby the Almighty SAI
SET @ENTRY := 14469;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,20,0,100,0,7603,0,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Niby the Almighty - On Quest 'Kroshius' Infernal Core' Finished - Run Script");

-- Actionlist SAI
SET @ENTRY := 1446900;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Niby the Almighty - On Script - Set Run Off"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,5407.19,-753,350.82,0,"Niby the Almighty - On Script - Move To Position"),
(@ENTRY,9,2,0,0,0,100,0,6200,6200,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,1.2,"Niby the Almighty - On Script - Set Orientation 1,2"),
(@ENTRY,9,3,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Niby the Almighty - On Script - Say Line 0"),
(@ENTRY,9,4,0,0,0,100,0,2000,2000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Niby the Almighty - On Script - Say Line 1"),
(@ENTRY,9,5,0,0,0,100,0,0,0,0,0,11,23056,0,0,0,0,0,1,0,0,0,0,0,0,0,"Niby the Almighty - On Script - Cast 'Call Infernal Destroyer'"),
(@ENTRY,9,6,0,0,0,100,0,2500,2500,0,0,1,0,0,0,0,0,0,19,14470,100,0,0,0,0,0,"Niby the Almighty - On Script - Say Line 0"),
(@ENTRY,9,7,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,19,14470,100,0,0,0,0,0,"Niby the Almighty - On Script - Say Line 1"),
(@ENTRY,9,8,0,0,0,100,0,2500,2500,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Niby the Almighty - On Script - Say Line 2"),
(@ENTRY,9,9,0,0,0,100,0,40000,40000,0,0,69,0,0,0,0,0,0,8,0,0,0,5412.48,-738.44,344.639,1.79643,"Niby the Almighty - On Script - Move To Position"),
(@ENTRY,9,10,0,0,0,100,0,5000,5000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,1.653,"Niby the Almighty - On Script - Set Orientation 1,653");

DELETE FROM `creature_text` WHERE `entry` IN (14469, 14470);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES 
(14469, 0, 0, 'Stand back! Stand clear! The infernal will need to be given a wide berth!', 12, 0, 100, 0, 0, 0, 9634, 'Niby the Almighty'),
(14469, 1, 0, 'BOW DOWN TO THE ALMIGHTY! BOW DOWN BEFORE MY INFERNAL DESTRO... chicken?', 12, 0, 100, 0, 0, 0, 9635, 'Niby the Almighty'),
(14469, 2, 0, 'Silence, servant! Vengeance will be mine! Death to Stormwind! Death by chicken!', 12, 0, 100, 0, 0, 0, 9638, 'Niby the Almighty'),
(14470, 0, 0, '%s rolls on the floor laughing.', 16, 0, 100, 0, 0, 0, 9636, 'Impsy'),
(14470, 1, 0, 'Niby, you''re an idiot.', 12, 0, 100, 0, 0, 0, 9637, 'Impsy');
