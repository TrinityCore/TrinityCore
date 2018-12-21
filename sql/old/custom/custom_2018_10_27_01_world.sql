-- Pathing for  Entry: 46402 'TDB FORMAT' 
SET @NPC := 264940;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9554.9,`position_y`=-939.823,`position_z`=100.3798 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9554.9,-939.823,100.3798,0,1,0,0,100,0),
(@PATH,2,-9560.75,-931.833,100.2973,0,1,0,0,100,0),
(@PATH,3,-9569,-926.535,100.2999,0,1,0,0,100,0),
(@PATH,4,-9575.53,-925.012,100.2999,0,1,0,0,100,0),
(@PATH,5,-9569,-926.535,100.2999,0,1,0,0,100,0),
(@PATH,6,-9560.75,-931.833,100.2973,0,1,0,0,100,0),
(@PATH,7,-9554.9,-939.823,100.3798,0,1,0,0,100,0),
(@PATH,8,-9549.63,-945.835,100.3798,0,1,0,0,100,0),
(@PATH,9,-9533.89,-946.705,104.7548,0,1,0,0,100,0),
(@PATH,10,-9510.48,-945.682,104.7723,0,1,0,0,100,0),
(@PATH,11,-9490.02,-945.651,109.2862,0,1,0,0,100,0),
(@PATH,12,-9481.64,-925.976,109.2723,0,1,0,0,100,0),
(@PATH,13,-9464.31,-923.748,112.5456,0,1,0,0,100,0),
(@PATH,14,-9445.52,-922.311,112.5456,0,1,0,0,100,0),
(@PATH,15,-9464.31,-923.748,112.5456,0,1,0,0,100,0),
(@PATH,16,-9575.53,-925.012,100.2999,0,1,0,0,100,0),
(@PATH,17,-9569,-926.535,100.2999,0,1,0,0,100,0),
(@PATH,18,-9560.75,-931.833,100.2973,0,1,0,0,100,0);
-- 0x203EF000202D50800012DE00010179E0 .go xyz -9554.9 -939.823 100.3798

-- Pathing for  Entry: 46402 'TDB FORMAT' 
SET @NPC := 264918;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9484.29,`position_y`=-969.646,`position_z`=109.2723 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9484.29,-969.646,109.2723,0,0,0,0,100,0),
(@PATH,2,-9469.68,-976.174,109.2723,0,0,0,0,100,0),
(@PATH,3,-9458.85,-979.596,111.0884,0,0,0,0,100,0),
(@PATH,4,-9449.62,-988.665,111.0884,0,0,0,0,100,0),
(@PATH,5,-9442.48,-1009.54,111.0884,0,0,0,0,100,0),
(@PATH,6,-9449.62,-988.665,111.0884,0,0,0,0,100,0),
(@PATH,7,-9458.85,-979.596,111.0884,0,0,0,0,100,0),
(@PATH,8,-9469.68,-976.174,109.2723,0,0,0,0,100,0),
(@PATH,9,-9484.29,-969.646,109.2723,0,0,0,0,100,0),
(@PATH,10,-9508.17,-970.24,104.7574,0,0,0,0,100,0),
(@PATH,11,-9517.24,-974.8,104.7574,0,0,0,0,100,0),
(@PATH,12,-9518.43,-984.09,104.7574,0,0,0,0,100,0),
(@PATH,13,-9517.24,-974.8,104.7574,0,0,0,0,100,0),
(@PATH,14,-9508.17,-970.24,104.7574,0,0,0,0,100,0);
-- 0x203EF000202D50800012DE00038179D8 .go xyz -9484.29 -969.646 109.2723

-- Pathing for  Entry: 48883 'TDB FORMAT' 
SET @NPC := 263867;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-9478.011,`position_y`=-956.4583,`position_z`=109.2862 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9478.011,-956.4583,109.2862,0,0,0,0,100,0),
(@PATH,2,-9483.828,-947.7882,109.2862,0,0,0,0,100,0),
(@PATH,3,-9493.745,-946.2916,109.288,0,0,0,0,100,0),
(@PATH,4,-9507.291,-946.875,104.7723,0,0,0,0,100,0),
(@PATH,5,-9527.058,-945.5486,104.7723,0,0,0,0,100,0),
(@PATH,6,-9549.873,-945.8264,100.3798,0,0,0,0,100,0),
(@PATH,7,-9553.707,-951.0538,100.3798,0,0,0,0,100,0),
(@PATH,8,-9555.106,-961.9149,100.3798,0,0,0,0,100,0),
(@PATH,9,-9552.356,-965.5,100.3798,0,0,0,0,100,0),
(@PATH,10,-9544.797,-967.2292,101.4913,0,0,0,0,100,0),
(@PATH,11,-9531.134,-967.6788,104.7574,0,0,0,0,100,0),
(@PATH,12,-9513.389,-968.243,104.7574,0,0,0,0,100,0),
(@PATH,13,-9500.127,-969.6476,107.0643,0,0,0,0,100,0),
(@PATH,14,-9488.435,-969.3143,109.2723,0,0,0,0,100,0),
(@PATH,15,-9479.194,-964.6597,109.2862,0,0,0,0,100,0);
-- 0x2030A400202FBCC000003B0000176451 .go xyz -9478.011 -956.4583 109.2862
