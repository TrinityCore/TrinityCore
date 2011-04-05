-- Fix for quests: 
-- From Sniff:
SET @guid := 78; -- Set by TDB
DELETE FROM `creature` WHERE `id` IN (25664,25665,25666);
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`DeathState`,`MovementType`) VALUES 
(@guid  ,25664,571,1,1,0,0,3487.67456,4516.643,11.441596,2.18166161,120,0,0,1,0,0,0), -- South Killcredit
(@guid+1,25665,571,1,1,0,0,3645.95483,4551.105,12.4051342,0.715585,120,0,0,1,0,0,0), -- Northeast Killcredit
(@guid+2,25666,571,1,1,0,0,3649.16748,4744.338,12.3212109,0.8901179,120,0,0,1,0,0,0); -- Northwest Killcredit
-- template updates (if needed)
UPDATE `creature_template` SET `baseattacktime`=2000,`faction_A`=35,`faction_H`=35,`minlevel`=70,`maxlevel`=70,`scale`=1,`speed_run`=1.142857,`speed_walk`=1,`unit_flags`=`unit_flags`|512|33554432 WHERE `entry`=25664;
UPDATE `creature_template` SET `baseattacktime`=2000,`faction_A`=35,`faction_H`=35,`minlevel`=70,`maxlevel`=70,`scale`=1,`speed_run`=1.142857,`speed_walk`=1,`unit_flags`=`unit_flags`|512|33554432 WHERE `entry`=25665;
UPDATE `creature_template` SET `baseattacktime`=2000,`faction_A`=35,`faction_H`=35,`minlevel`=70,`maxlevel`=70,`scale`=1,`speed_run`=1.142857,`speed_walk`=1,`unit_flags`=`unit_flags`|512|33554432 WHERE `entry`=25666;

-- SAI for the Killcredits:
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (25664,25665,25666);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (25664,25665,25666);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(25664,0,0,0,8,0,100,0,45853,1,0,0,33,25664,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Mark Sinkhole Killcredit: South'),
(25665,0,0,0,8,0,100,0,45853,1,0,0,33,25665,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Mark Sinkhole Killcredit: NorthEast'),
(25666,0,0,0,8,0,100,0,45853,1,0,0,33,25666,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Mark Sinkhole Killcredit: NorthWest');
