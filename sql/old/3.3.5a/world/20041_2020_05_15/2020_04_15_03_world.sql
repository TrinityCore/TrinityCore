-- 
DELETE FROM `creature_template_movement` WHERE `CreatureId`  IN (38391, 38392);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`) VALUES 
(38391, 2, 1, 1, 0),
(38392, 2, 1, 1, 0);

DELETE FROM `creature_template_addon` WHERE `entry` IN (38391, 38392);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `visibilityDistanceType`, `auras`) VALUES 
(38391, 0, 0, 33554432, 2049, 0, 0, ""),
(38392, 0, 0, 33554432, 2049, 0, 0, "");

-- Val'kyr Protector SAI
SET @ENTRY := 38392;
UPDATE `creature_template` SET `AIName`="SmartAI" , `scriptname` ="" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1500,2500,1500,2500,11,71842,0,0,0,0,0,2,0,0,0,0,0,0,0,"Val'kyr Protector - In Combat - Cast 'Smite' with CastFlag: 0 and TriggerFlag: 0 (TargetLimit: 0)");
-- Val'kyr Guardian SAI
SET @ENTRY := 38391;
UPDATE `creature_template` SET `AIName`="SmartAI" , `scriptname` ="" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1500,2500,1500,2500,11,71841,0,0,0,0,0,2,0,0,0,0,0,0,0,"Val'kyr Guardian - In Combat - Cast 'Smite' with CastFlag: 0 and TriggerFlag: 0 (TargetLimit: 0)");
