-- Spawn & Pathing for Nethervine Inciter Entry: 19511 "Not Spawned"
SET @NPC := 40252;
DELETE FROM `creature` WHERE `guid` IN (@NPC);
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@NPC,19511,553,1,1,0,0,13.71129,556.805,-18.16187,0.41887,300,0,0,1,0,2);
SET @PATH := @NPC * 10;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,34.53745,554.1877,-18.31396,0,0,0,0,100,0),
(@PATH,2,13.71129,556.805,-18.16187,0,0,0,0,100,0),
(@PATH,3,-11.50565,559.8253,-18.09619,0,0,0,0,100,0),
(@PATH,4,-29.17254,568.2135,-17.99052,0,0,0,0,100,0),
(@PATH,5,-11.50565,559.8253,-18.09619,0,0,0,0,100,0),
(@PATH,6,13.71129,556.805,-18.16187,0,0,0,0,100,0);
-- .go 34.53745 554.1877 -18.31396

-- Pathing for Nethervine Inciter Entry: 19511
SET @NPC := 83086;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-37.1817,`position_y`=524.0293,`position_z`=-10.16431 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-21.58225,517.7063,-6.475254,0,0,0,0,100,0),
(@PATH,2,-9.34382,516.5084,-5.636462,0,0,0,0,100,0),
(@PATH,3,4.990617,518.1604,-7.138422,0,0,0,0,100,0),
(@PATH,4,19.44558,526.3201,-11.25785,0,0,0,0,100,0),
(@PATH,5,23.91135,540.4265,-18.37715,0,0,0,0,100,0),
(@PATH,6,18.10396,548.5428,-18.3295,0,0,0,0,100,0),
(@PATH,7,-1.83314,553.5635,-18.1602,0,0,0,0,100,0),
(@PATH,8,-17.95817,553.2923,-18.19155,0,0,0,0,100,0),
(@PATH,9,-30.42817,550.3372,-18.30474,0,0,0,0,100,0),
(@PATH,10,-43.32164,544.6859,-18.35999,0,0,0,0,100,0),
(@PATH,11,-46.76561,533.5467,-15.89331,0,0,0,0,100,0),
(@PATH,12,-37.1817,524.0293,-10.16431,0,0,0,0,100,0);
-- .go -21.58225 517.7063 -6.475254

-- Pathing for Nethervine Inciter Entry: 19511
SET @NPC := 83072;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-10.81185,`position_y`=498.6948,`position_z`=-5.355443 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-10.5063,509.9379,-5.275531,0,0,0,0,100,0),
(@PATH,2,-10.81185,498.6948,-5.355443,0,0,0,0,100,0),
(@PATH,3,2.500325,493.4179,-5.437914,0,0,0,0,100,0),
(@PATH,4,15.09316,496.8965,-5.464271,0,0,0,0,100,0),
(@PATH,5,2.500325,493.4179,-5.437914,0,0,0,0,100,0),
(@PATH,6,-10.81185,498.6948,-5.355443,0,0,0,0,100,0);
-- .go -10.5063 509.9379 -5.275531

-- Pathing for Nethervine Inciter Entry: 19511
SET @NPC := 83073;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-6.525395,`position_y`=482.9323,`position_z`=-5.492778 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1.63937,482.4999,-5.53459,0,0,0,0,100,0),
(@PATH,2,-6.525395,482.9323,-5.492778,0,0,0,0,100,0),
(@PATH,3,-13.81937,488.856,-5.425375,0,0,0,0,100,0),
(@PATH,4,-17.63536,496.55,-5.370692,0,0,0,0,100,0),
(@PATH,5,-16.29433,503.0782,-5.324292,0,0,0,0,100,0),
(@PATH,6,-17.63536,496.55,-5.370692,0,0,0,0,100,0),
(@PATH,7,-13.81937,488.856,-5.425375,0,0,0,0,100,0),
(@PATH,8,-6.525395,482.9323,-5.492778,0,0,0,0,100,0);
-- .go 1.63937 482.4999 -5.53459
