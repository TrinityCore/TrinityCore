-- Malykriss Altar of Sacrifice Bunny SAI
SET @ENTRY := 31065;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,4000,4000,4000,4000,11,58196,0,0,0,0,0,1,0,0,0,0,0,0,0,"Malykriss Altar of Sacrifice Bunny - OOC - Cast Malykriss Altar of Sacrifice Pulse");

-- Malykriss Blood Forge Bunny SAI
SET @ENTRY := 31068;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,4000,4000,4000,4000,11,58198,0,0,0,0,0,1,0,0,0,0,0,0,0,"Malykriss Blood Forge Bunny - OOC - Cast Malykriss Blood Forge Pulse");

-- Malykriss Icy Lookout Bunny SAI
SET @ENTRY := 31064;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,4000,4000,4000,4000,11,58195,0,0,0,0,0,1,0,0,0,0,0,0,0,"Malykriss Icy Lookout Bunny - OOC - Cast Malykriss Icy Lookout Pulse");

-- Malykriss Runeworks Bunny SAI
SET @ENTRY := 31066;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,4000,4000,4000,4000,11,58197,0,0,0,0,0,1,0,0,0,0,0,0,0,"Malykriss Runeworks Bunny - OOC - Cast Malykriss Runeworks Pulse");

-- Update creatures
UPDATE `creature` SET `modelid`=0,`spawndist`=0,`MovementType`=0 WHERE `id` IN (31064,31065,31066,31068,31075);
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|128 WHERE `entry` IN (31064,31065,31066,31068);
