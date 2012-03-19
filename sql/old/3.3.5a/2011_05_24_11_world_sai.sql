-- Plagued Proto-Dragon SAI
SET @ENTRY  := 23680;
SET @SPELL  := 21862; -- Radiation
SET @SPELL1 := 9573;  -- Flame Breath
SET @SPELL2 := 3391;  -- Thrash
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,23,0,100,0,@SPELL,0,2000,2000,11,@SPELL,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Plagued Proto-Dragon - Aura Radiation not present - Add Aura Radiation'),
(@ENTRY,0,1,0,0,0,100,0,5000,7000,10000,15000,11,@SPELL1,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Plagued Proto-Dragon - Combat - Cast Flame Breath on victim'),
(@ENTRY,0,2,0,0,0,100,0,10000,15000,20000,25000,11,@SPELL2,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Plagued Proto-Dragon - Combat - Cast Thrash on victim');
-- Plagued Proto-Dragon fix InhabitType
UPDATE `creature_template` SET `InhabitType`=7 WHERE entry=@ENTRY;
-- Plagued Proto-Dragon fix model info
UPDATE `creature_model_info` SET `bounding_radius`=0.225,`combat_reach`=3.75,`gender`=0 WHERE `modelid`=24874; -- Plagued Proto-Dragon
-- Plagued Proto-Dragon fix bytes1 and bytes2
DELETE FROM `creature_template_addon` WHERE `entry`=@ENTRY;
INSERT INTO `creature_template_addon` (`entry`,`bytes1`,`bytes2`) VALUES
(@ENTRY,50331648,1); -- Plagued Proto-Dragon
-- Pathing for Plagued Proto-Dragon Entry: 23680
SET @NPC := 107626;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=847.8322,`position_y`=-4441.198,`position_z`=159.749 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,838.0903,-4421.268,159.749,0,0,0,100,0),
(@PATH,2,801.8729,-4407.143,179.2211,0,0,0,100,0),
(@PATH,3,782.8507,-4413.701,194.3322,0,0,0,100,0),
(@PATH,4,777.4731,-4419.182,198.0821,0,0,0,100,0),
(@PATH,5,774.1382,-4438.679,206.8877,0,0,0,100,0),
(@PATH,6,814.439,-4462.499,206.8877,0,0,0,100,0),
(@PATH,7,848.4948,-4489.605,206.8877,0,0,0,100,0),
(@PATH,8,876.2105,-4490.642,206.8877,0,0,0,100,0),
(@PATH,9,896.0039,-4450.317,192.8044,0,0,0,100,0),
(@PATH,10,897.2634,-4422.887,179.6656,0,0,0,100,0),
(@PATH,11,907.506,-4392.95,179.6656,0,0,0,100,0),
(@PATH,12,933.834,-4369.785,166.0267,0,0,0,100,0),
(@PATH,13,956.7077,-4379.646,166.0267,0,0,0,100,0),
(@PATH,14,967.011,-4400.757,158.8045,0,0,0,100,0),
(@PATH,15,966.2571,-4425.053,159.749,0,0,0,100,0),
(@PATH,16,932.5647,-4461.108,159.749,0,0,0,100,0),
(@PATH,17,891.5416,-4476.208,159.749,0,0,0,100,0),
(@PATH,18,861.6124,-4460.188,159.749,0,0,0,100,0),
(@PATH,19,847.8322,-4441.198,159.749,0,0,0,100,0);
