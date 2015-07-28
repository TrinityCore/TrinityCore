--
UPDATE `creature` SET `spawntimesecs`=1 WHERE  `guid`=325668;

-- Captured Scarlet Zealot SAI
SET @ENTRY := 1931;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,20,0,100,0,24977,0,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Scarlet Zealot - On Quest 'Johaan's Experiment' Finished - Run Script"),
(@ENTRY,0,1,0,6,0,100,0,0,0,0,0,41,3000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Scarlet Zealot - On Just Died - Despawn In 3000 ms");

-- Actionlist SAI
SET @ENTRY := 193100;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Scarlet Zealot - On Script - Say Line 0"),
(@ENTRY,9,1,0,0,0,100,0,3000,3000,0,0,11,3287,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Scarlet Zealot - On Script - Cast 'Ghoul Form'"),
(@ENTRY,9,2,0,0,0,100,0,2000,2000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Scarlet Zealot - On Script - Say Line 1"),
(@ENTRY,9,3,0,0,0,100,0,0,0,0,0,89,6,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Scarlet Zealot - On Script - Start Random Movement"),
(@ENTRY,9,4,0,0,0,100,0,6000,6000,0,0,37,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Scarlet Zealot - On Script - Kill Self");

UPDATE `creature_template_addon` SET `emote`=431 WHERE  `entry`=1931;
