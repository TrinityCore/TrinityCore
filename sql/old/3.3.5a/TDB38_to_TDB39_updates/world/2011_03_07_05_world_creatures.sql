SET @ENTRY := 28297;
SET @NPC := 151894;
SET @PATH := @NPC * 10;
-- Template update
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|32768,`speed_run`=1.38571 WHERE `entry`=@ENTRY; -- Shango
-- Spawn
DELETE FROM `creature` WHERE `id`=@ENTRY;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`DeathState`,`MovementType`) VALUES
(@NPC,@ENTRY,571,1,1,0,0,6203.80664,5528.569,-51.8230972,2.62550282,120,0,0,1,0,0,2);
-- Addon data
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES
(@NPC,@PATH,1,0, NULL); -- Shango
DELETE FROM `creature_template_addon` WHERE `entry`=@ENTRY;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(@ENTRY,0,0,1,0, NULL); -- Shango
-- Pathing for Shango
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,6213.67,5522.98,-51.8231,0,0,0,100,0),
(@PATH,2,6221.91,5519.84,-50.9481,0,0,0,100,0),
(@PATH,3,6228.36,5517.6,-49.2341,0,0,0,100,0),
(@PATH,4,6237.21,5503.82,-44.4988,0,0,0,100,0),
(@PATH,5,6247.96,5494.78,-44.9726,0,0,0,100,0),
(@PATH,6,6260.08,5484.58,-45.4597,0,0,0,100,0),
(@PATH,7,6274.67,5480.42,-45.1359,0,0,0,100,0),
(@PATH,8,6288.82,5476,-46.3803,0,0,0,100,0),
(@PATH,9,6305.17,5470.43,-44.6878,0,0,0,100,0),
(@PATH,10,6311.82,5459.03,-48.2749,0,0,0,100,0),
(@PATH,11,6310.37,5444.21,-52.0538,0,0,0,100,0),
(@PATH,12,6294.56,5445.27,-54.3711,0,0,0,100,0),
(@PATH,13,6277.3,5459.18,-51.4723,0,0,0,100,0),
(@PATH,14,6260.51,5469.62,-51.1171,0,0,0,100,0),
(@PATH,15,6248.49,5480.35,-50.1687,0,0,0,100,0),
(@PATH,16,6235.66,5488.57,-51.2285,0,0,0,100,0),
(@PATH,17,6220.07,5498.48,-58.4601,0,0,0,100,0),
(@PATH,18,6211.14,5508.38,-58.7072,0,0,0,100,0),
(@PATH,19,6203.5,5519.82,-56.4056,0,0,0,100,0),
(@PATH,20,6204.61,5524.55,-53.8457,0,0,0,100,0),
(@PATH,21,6207.23,5525.67,-52.505,0,0,0,100,0);
