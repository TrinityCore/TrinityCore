-- 
DELETE FROM `smart_scripts` WHERE `entryorguid`=27530 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(27530,0,1,0,8,0,100,1,49349,0,0,0,41,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ruby Keeper - On Spellhit - Despawn');

DELETE FROM `creature_addon` WHERE `guid` IN (108202,108203,108328,108329, 108330);
INSERT INTO `creature_addon` (`guid`, `bytes1`, `auras`) VALUES
(108202,33554432 ,""),(108203,33554432 ,""),(108328,33554432 ,""),(108329,33554432 ,""),(108330,33554432 ,"");
UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry`=27530;
UPDATE `creature` SET `MovementType`=1, `spawndist`=10 WHERE `guid` IN (108202,108203,108328,108329, 108330);

SET @GUID := 48254;
DELETE FROM `creature` WHERE `guid` IN (@GUID,@GUID+1,@GUID+2,@GUID+3);
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`, `unit_flags`, `dynamicflags`) VALUES
(@GUID,27530,571,1,1,24137,0,3690.58, 1034.33, 55.7121, 1.43117,300,0,0,102820,0,0,537133568,32),
(@GUID+1,27530,571,1,1,24137,0,3690.58, 1034.33, 55.7121, 1.43117,300,0,0,102820,0,0,537133568,32),
(@GUID+2,27530,571,1,1,24137,0,3722.78, 872.282, 56.4471, 3.56587,300,0,0,102820,0,0,537133568,32),
(@GUID+3,27530,571,1,1,24137,0,3678.09, 938.621, 57.2201, 1.50971,300,0,0,102820,0,0,537133568,32);
UPDATE `creature` SET `unit_flags`=537133568 WHERE `id`=27530 AND `dynamicflags`=32;
