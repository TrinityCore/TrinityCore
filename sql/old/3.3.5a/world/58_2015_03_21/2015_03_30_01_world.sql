SET @Sinestra1:=23283;  
SET @Sinestra2:=23284;

SET @GUID:=28796; -- 1 free creature guid set by TC
SET @PATH := @Sinestra1*10;
DELETE FROM `creature` WHERE `id` IN (@Sinestra1);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`,`curhealth`) VALUES
(@GUID+0, @Sinestra1, 530, 1, 1, -5240.304199, 682.020081, 157.604004, 5.723090, 900, 151760);

UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@GUID;
UPDATE `creature_template` SET  `InhabitType`=4, `AIName`='SmartAI', `flags_extra`=0 WHERE  `entry`=@Sinestra1;
UPDATE `creature_template` SET  `AIName`='SmartAI', `flags_extra`=0 WHERE  `entry`=@Sinestra2;
DELETE FROM `creature_addon` WHERE `guid`=@GUID;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(@GUID,@PATH,0,33554432,1,0,'');

DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-5120.744629, 783.187988, 208.115173,0,0,0,0,100,0),
(@PATH,2,-5331.205078, 712.656494, 180.570953,0,0,0,0,100,0),
(@PATH,3,-5371.597656, 573.186890, 159.434875,0,0,0,0,100,0),
(@PATH,4,-5299.805176, 490.375488, 150.086655,0,0,0,0,100,0),
(@PATH,5,-5207.269043, 478.922729, 150.908600,0,0,0,0,100,0),
(@PATH,6,-5170.645996, 533.437805, 168.776611,0,0,0,0,100,0),
(@PATH,7,-5132.274902, 632.125549, 177.018936,0,0,0,0,100,0);

DELETE FROM `waypoints` WHERE `entry` IN(@Sinestra1*100);
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(@Sinestra1*100, 1, -5163.216309, 645.610779, 77.3899920, 'Lady Sinestra');

DELETE FROM `waypoints` WHERE `entry` IN(@Sinestra2*100);
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(@Sinestra2*100, 1, -5155.744629, 636.083862, 80.537260, 'Lady Sinestra'),
(@Sinestra2*100, 2, -5130.897949, 609.521179, 83.996864, 'Lady Sinestra'),
(@Sinestra2*100, 3, -5113.644531, 604.067078, 84.993507, 'Lady Sinestra'),
(@Sinestra2*100, 4, -5093.567383, 586.982605, 86.467323, 'Lady Sinestra'),
(@Sinestra2*100, 5, -5113.704590, 604.713928, 85.021675, 'Lady Sinestra'),
(@Sinestra2*100, 6, -5134.045410, 612.111572, 83.530479, 'Lady Sinestra'),
(@Sinestra2*100, 7, -5163.214844, 645.577454, 77.393990, 'Lady Sinestra');

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@Sinestra1, @Sinestra1*100, @Sinestra2, @Sinestra2*100, @Sinestra2*100+1);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Sinestra1,0,0,0,1,0,100,0,7200000,7200000,7200000,7200000,53,1,@Sinestra1*100,0,0,0,1,1,0,0,0,0,0,0,0,"Time Watcher - OOC  - Start wp"),
(@Sinestra1,0,1,0,58,0,100,0,1,@Sinestra1*100,0,0,80,@Sinestra1*100,2,0,0,0,0,1,0,0,0,0,0,0,0,"Lady Sinestra - On way point ended - action list"),
(@Sinestra1*100,9,0,0,0,0,100,0,0,0,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lady Sinestra - Action list - Set visible off"),
(@Sinestra1*100,9,1,0,0,0,100,0,0,0,0,0,12,@Sinestra2,8,0,0,0,0,8,0,0,0,-5163.216309, 645.610779, 77.6899920, 5.328592,"Lady Sinestra - Action list - Spawn"),
(@Sinestra1*100,9,2,0,0,0,100,0,160000,160000,0,0,47,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lady Sinestra - Action list - St visible on"),
(@Sinestra2,0,0,0,54,0,100,0,0,0,0,0,53,0,@Sinestra2*100,0,0,0,1,1,0,0,0,0,0,0,0,"Lady Sinestra - Just summoned - Start wp"),
(@Sinestra2,0,1,0,40,0,100,0,1,@Sinestra2*100,0,0,80,@Sinestra2*100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lady Sinestra - On wp1 - Action list"),
(@Sinestra2*100,9,0,0,0,0,100,0,0,0,0,0,54,20000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lady Sinestra - Action list - Pause waypoint"),
(@Sinestra2*100,9,1,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,19,23146,20,0,0,0,0,0,"Lady Sinestra - Action list - Talk"),
(@Sinestra2*100,9,2,0,0,0,100,0,5000,5000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lady Sinestra - Action list - Talk"),
(@Sinestra2*100,9,3,0,0,0,100,0,9000,9000,0,0,1,1,0,0,0,0,0,19,23146,20,0,0,0,0,0,"Lady Sinestra - Action list - Talk"),
(@Sinestra2*100,9,4,0,0,0,100,0,4000,4000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lady Sinestra - Action list - Talk"),
(@Sinestra2*100,9,5,0,0,0,100,0,2000,2000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lady Sinestra - Action list - Talk"),
(@Sinestra2,0,2,0,40,0,100,0,4,@Sinestra2*100,0,0,80,@Sinestra2*100+1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lady Sinestra - On wp4 - Action list"),
(@Sinestra2*100+1,9,0,0,0,0,100,0,0,0,0,0,54,65000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lady Sinestra - Action list - Pause waypoint"),
(@Sinestra2*100+1,9,1,0,0,0,100,0,0,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lady Sinestra - Action list - Talk"),
(@Sinestra2*100+1,9,2,0,0,0,100,0,5000,5000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lady Sinestra - Action list - Talk"),
(@Sinestra2*100+1,9,3,0,0,0,100,0,4000,4000,0,0,1,8,0,0,0,0,0,19,23139,20,0,0,0,0,0,"Lady Sinestra - Action list - Talk"),
(@Sinestra2*100+1,9,4,0,0,0,100,0,9000,9000,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lady Sinestra - Action list - Talk"),
(@Sinestra2*100+1,9,5,0,0,0,100,0,9000,9000,0,0,1,9,0,0,0,0,0,19,23139,20,0,0,0,0,0,"Lady Sinestra - Action list - Talk"),
(@Sinestra2*100+1,9,6,0,0,0,100,0,3000,3000,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lady Sinestra - Action list - Talk"),
(@Sinestra2*100+1,9,7,0,0,0,100,0,3000,3000,0,0,1,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lady Sinestra - Action list - Talk"),
(@Sinestra2*100+1,9,8,0,0,0,100,0,7000,7000,0,0,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lady Sinestra - Action list - Talk"),
(@Sinestra2*100+1,9,9,0,0,0,100,0,4000,4000,0,0,1,10,0,0,0,0,0,19,23139,20,0,0,0,0,0,"Lady Sinestra - Action list - Talk"),
(@Sinestra2*100+1,9,10,0,0,0,100,0,3000,3000,0,0,1,11,0,0,0,0,0,19,23139,20,0,0,0,0,0,"Lady Sinestra - Action list - Talk"),
(@Sinestra2*100+1,9,11,0,0,0,100,0,8000,8000,0,0,1,9,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lady Sinestra - Action list - Talk"),
(@Sinestra2*100+1,9,12,0,0,0,100,0,8000,8000,0,0,1,10,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lady Sinestra - Action list - Talk"),
(@Sinestra2,0,3,0,58,0,100,0,7,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lady Sinestra - On wp Ended - Despawn");
