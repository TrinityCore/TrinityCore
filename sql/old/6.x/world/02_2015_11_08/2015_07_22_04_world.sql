-- 
-- Den Cage SAI
SET @ENTRY := 202580;
UPDATE `gameobject_template` SET `AIName`="SmartGameObjectAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,1,0,0,70,0,100,0,2,0,0,0,45,1,1,0,0,0,0,19,39215,1,0,0,0,0,0,"Den Cage - On Gameobject State Changed - Set Data 1 1");

-- Captured Northwatch Scout SAI
SET @ENTRY := 39215;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,12000,20000,11,75356,0,0,0,0,0,2,0,0,0,0,0,0,0,"Captured Northwatch Scout - In Combat - Cast 'Fisticuffs'"),
(@ENTRY,0,1,2,38,0,100,0,1,1,0,0,19,256,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Northwatch Scout - On Data Set 1 1 - Remove Flag Immune To Players"),
(@ENTRY,0,2,0,61,0,100,0,1,1,0,0,49,0,0,0,0,0,0,21,10,0,0,0,0,0,0,"Captured Northwatch Scout - On Data Set 1 1 - Start Attacking");
