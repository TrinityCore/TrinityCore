-- Fixup Blackrock Worg
UPDATE `creature_template` SET `flags_extra`=2 WHERE `entry`=49871;

-- Fix up Blackrock Spy Entry: 49874
UPDATE `creature` SET `spawndist`=0,`MovementType`=0 WHERE `id`=49874;
UPDATE `creature_template_addon` SET `auras`='80676' WHERE `entry`=49874;
DELETE FROM `smart_scripts` WHERE `entryorguid`=49874 AND `id` IN (1,2);

-- Pathing for Blackrock Spy Entry: 49874 'TDB FORMAT' 
SET @NPC := 279993;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9017.051,`position_y`=-186.1771,`position_z`=76.99114 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '92857');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9017.051,-186.1771,76.99114,0,0,0,0,100,0),
(@PATH,2,-9022.958,-180.9201,76.68597,0,0,0,0,100,0),
(@PATH,3,-9025.415,-177.9479,76.53362,0,0,0,0,100,0),
(@PATH,4,-9026.482,-173.7778,77.33782,0,0,0,0,100,0),
(@PATH,5,-9024.309,-167.1191,78.75359,0,0,0,0,100,0),
(@PATH,6,-9026.482,-173.7773,77.37859,0,0,0,0,100,0),
(@PATH,7,-9025.415,-177.9479,76.53362,0,0,0,0,100,0),
(@PATH,8,-9022.958,-180.9201,76.68597,0,0,0,0,100,0);

-- Pathing for Blackrock Spy Entry: 49874 'TDB FORMAT' 
SET @NPC := 279970;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8975.587,`position_y`=-210.8681,`position_z`=74.38621 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '92857');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8975.587,-210.8681,74.38621,0,0,0,0,100,0),
(@PATH,2,-8982.348,-208.6354,73.94993,0,0,0,0,100,0),
(@PATH,3,-8982.997,-201.5851,74.64426,0,0,0,0,100,0),
(@PATH,4,-8982.348,-208.6354,73.94993,0,0,0,0,100,0);

-- Pathing for Blackrock Spy Entry: 49874 'TDB FORMAT' 
SET @NPC := 279996;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8959.651,`position_y`=-62.3316,`position_z`=92.46779 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '92857');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8959.651,-62.3316,92.46779,0,0,0,0,100,0),
(@PATH,2,-8962.094,-58.05729,92.43849,0,0,0,0,100,0),
(@PATH,3,-8966.278,-58.07465,92.18849,0,0,0,0,100,0),
(@PATH,4,-8966.953,-59.75868,91.97262,0,0,0,0,100,0),
(@PATH,5,-8962.488,-59.94618,92.25246,0,0,0,0,100,0),
(@PATH,6,-8966.278,-58.07465,92.18849,0,0,0,0,100,0),
(@PATH,7,-8962.094,-58.05729,92.43849,0,0,0,0,100,0),
(@PATH,8,-8958.906,-60.77083,92.43849,0,0,0,0,100,0);

-- Pathing for Blackrock Spy Entry: 49874 'TDB FORMAT' 
SET @NPC := 279821;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8937.439,`position_y`=-246.7691,`position_z`=79.06224 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '92857');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8937.439,-246.7691,79.06224,0,0,0,0,100,0),
(@PATH,2,-8930.792,-241.4774,79.49934,0,0,0,0,100,0),
(@PATH,3,-8933.103,-246.651,78.92879,0,0,0,0,100,0);

-- Pathing for Blackrock Spy Entry: 49874 'TDB FORMAT' 
SET @NPC := 279952;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8906.613,`position_y`=-39.17014,`position_z`=89.14458 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '92857');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8906.613,-39.17014,89.14458,0,0,0,0,100,0),
(@PATH,2,-8900.656,-43.30903,86.97442,0,0,0,0,100,0),
(@PATH,3,-8906.398,-39.31641,89.20806,0,0,0,0,100,0),
(@PATH,4,-8911.556,-40.54688,89.57232,0,0,0,0,100,0);

-- Pathing for Blackrock Spy Entry: 49874 'TDB FORMAT' 
SET @NPC := 279950;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8926.372,`position_y`=-68.80903,`position_z`=89.75582 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '92857');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8926.372,-68.80903,89.75582,0,0,0,0,100,0),
(@PATH,2,-8929.808,-68.91666,89.97311,0,0,0,0,100,0),
(@PATH,3,-8922.819,-71.70834,89.15719,0,0,0,0,100,0);

-- Pathing for Blackrock Spy Entry: 49874 'TDB FORMAT' 
SET @NPC := 279936;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8878.366,`position_y`=-92.23785,`position_z`=83.897 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '92857');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8878.366,-92.23785,83.897,0,0,0,0,100,0),
(@PATH,2,-8873.397,-91.30903,83.17702,0,0,0,0,100,0),
(@PATH,3,-8870.214,-93.74132,82.54983,0,0,0,0,100,0);

-- Pathing for Blackrock Spy Entry: 49874 'TDB FORMAT' 
SET @NPC := 279918;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8832.973,`position_y`=-120.3351,`position_z`=80.8506 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '92857');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8832.973,-120.3351,80.8506,0,0,0,0,100,0),
(@PATH,2,-8831.473,-124.0399,80.79787,0,0,0,0,100,0),
(@PATH,3,-8837.326,-118.8611,80.59762,0,0,0,0,100,0);

-- Pathing for Blackrock Spy Entry: 49874 'TDB FORMAT' 
SET @NPC := 279756;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-8784.361,`position_y`=-78.68403,`position_z`=89.64127 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '92857');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-8784.361,-78.68403,89.64127,0,0,0,0,100,0),
(@PATH,2,-8776.549,-79.15799,89.33903,0,0,0,0,100,0),
(@PATH,3,-8772.433,-83.78646,88.66227,0,0,0,0,100,0),
(@PATH,4,-8776.549,-79.15799,89.33903,0,0,0,0,100,0);
