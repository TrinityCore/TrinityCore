-- Sand Scavenger + Stonehide Riverbeast
UPDATE `creature` SET `spawndist`=5, `MovementType`=1 WHERE  `id` IN (88076, 88075);
-- Sand Scavenger SAI
SET @ENTRY := 88076;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,0,0,0,0,0,11,117380,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sand Scavenger - On Aggro - Cast 'Scuttle!'"),
(@ENTRY,0,1,0,0,0,100,0,3000,4000,12000,16000,11,120468,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sand Scavenger - In Combat - Cast 'Pinch'");

-- Stonehide Riverbeast SAI
SET @ENTRY := 88075;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,7000,15000,18000,11,167439,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stonehide Riverbeast - In Combat - Cast 'Whip Splash'");
