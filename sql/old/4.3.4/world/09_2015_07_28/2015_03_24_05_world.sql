-- Remove Clockwork Mechanic & Arachnopod Destroyer Incorrect spawns "Ulduar"
DELETE FROM `creature` WHERE `guid` IN (137561,137562,137563,136543,136544,136547,136551);

-- Arachnopod Destroyer SAI "Still needs combat AI"
SET @ENTRY := 34183;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,11,64703,0,0,0,0,0,1,0,0,0,0,0,0,0,"Arachnopod Destroyer - OOC - Cast Summon Clockwork Mechanic");

-- Clockwork Mechanic SAI "Still needs combat AI"
SET @ENTRY := 34184;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,0,0,0,0,0,11,63313,0,0,0,0,0,7,0,0,0,0,0,0,0,"Clockwork Mechanic - Just Summoned - Cast Ride Vehicle");
