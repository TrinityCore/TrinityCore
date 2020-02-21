-- Fix Quest 27928 "A Favor for the Furrier"

-- Fix loot

UPDATE `creature_loot_template` SET `Chance`=80, `GroupId`=1, `Comment`='Rending Fang' WHERE `Entry`=47190 AND `Item`=60576;
UPDATE `creature_loot_template` SET `Chance`=20, `GroupId`=1, `Comment`='Fire-Scorched Claw' WHERE `Entry`=47190 AND `Item`=60577;
UPDATE `creature_loot_template` SET `Chance`=33, `QuestRequired`=1, `GroupId`=2, `Comment`='Desert Coyote Pelt' WHERE `Entry`=47190 AND `Item`=62776;
UPDATE `creature_loot_template` SET `Chance`=33, `GroupId`=2, `Comment`='Toughened Flesh' WHERE `Entry`=47190 AND `Item`=62778;

-- Misc fixes for general area

-- Fix Shaggy Desert Coyote
UPDATE `creature` SET `spawndist`=10,`MovementType`=1 WHERE `id` IN (47190);
-- Fix Diseased Vulture
UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry`=47202;
UPDATE `creature_template_addon` SET `bytes1`=50331648 WHERE `entry` IN (47202);
-- Fix Armadillo
UPDATE `creature` SET `spawndist`=10,`MovementType`=1 WHERE `id` IN (48239);
UPDATE `creature_template_addon` SET `auras`= '' WHERE `entry` IN (48239);

-- Shaggy Desert Coyote & Diseased Vulture & Armadillo Loot to be redone in future

-- Add waypoints for Diseased Vulture

-- Pathing for Diseased Vulture Entry: 47202 'TDB FORMAT' 
SET @NPC := 266478;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-10993.2,`position_y`=-205.691,`position_z`=33.94123 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,50331648,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-10993.2,-205.691,33.94123,0,0,0,0,100,0),
(@PATH,2,-10982.95,-180.9422,33.94123,0,0,0,0,100,0),
(@PATH,3,-10958.2,-170.691,33.94123,0,0,0,0,100,0),
(@PATH,4,-10933.45,-180.9422,33.94123,0,0,0,0,100,0),
(@PATH,5,-10923.2,-205.691,33.94123,0,0,0,0,100,0),
(@PATH,6,-10933.45,-230.4397,33.94123,0,0,0,0,100,0),
(@PATH,7,-10958.2,-240.691,33.94123,0,0,0,0,100,0),
(@PATH,8,-10982.95,-230.4397,33.94123,0,0,0,0,100,0);

-- Pathing for Diseased Vulture Entry: 47202 'TDB FORMAT' 
SET @NPC := 266208;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-11038.6,`position_y`=-440.132,`position_z`=52.40772 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,50331648,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-11038.6,-440.132,52.40772,0,0,0,0,100,0),
(@PATH,2,-11028.35,-415.3832,52.40772,0,0,0,0,100,0),
(@PATH,3,-11003.6,-405.132,52.40772,0,0,0,0,100,0),
(@PATH,4,-10978.85,-415.3832,52.40772,0,0,0,0,100,0),
(@PATH,5,-10968.6,-440.132,52.40772,0,0,0,0,100,0),
(@PATH,6,-10978.85,-464.8807,52.40772,0,0,0,0,100,0),
(@PATH,7,-11003.6,-475.132,52.40772,0,0,0,0,100,0),
(@PATH,8,-11028.35,-464.8807,52.40772,0,0,0,0,100,0);

-- Pathing for Diseased Vulture Entry: 47202 'TDB FORMAT' 
SET @NPC := 266234;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-11037.2,`position_y`=-381.7188,`position_z`=48.39005 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,50331648,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-11037.2,-381.7188,48.39005,0,0,0,0,100,0),
(@PATH,2,-11026.95,-356.97,48.39005,0,0,0,0,100,0),
(@PATH,3,-11002.2,-346.7188,48.39005,0,0,0,0,100,0),
(@PATH,4,-10977.45,-356.97,48.39005,0,0,0,0,100,0),
(@PATH,5,-10967.2,-381.7188,48.39005,0,0,0,0,100,0),
(@PATH,6,-10977.45,-406.4675,48.39005,0,0,0,0,100,0),
(@PATH,7,-11002.2,-416.7188,48.39005,0,0,0,0,100,0),
(@PATH,8,-11026.95,-406.4675,48.39005,0,0,0,0,100,0);

-- Pathing for Diseased Vulture Entry: 47202 'TDB FORMAT' 
SET @NPC := 266402;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-10765.15,`position_y`=-27.47696,`position_z`=34.79253 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,50331648,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-10765.15,-27.47696,34.79253,0,0,0,0,100,0),
(@PATH,2,-10754.9,-52.2257,34.79253,0,0,0,0,100,0),
(@PATH,3,-10765.15,-76.97444,34.79253,0,0,0,0,100,0),
(@PATH,4,-10789.9,-87.22569,34.79253,0,0,0,0,100,0),
(@PATH,5,-10814.65,-76.97443,34.79253,0,0,0,0,100,0),
(@PATH,6,-10824.9,-52.22569,34.79253,0,0,0,0,100,0),
(@PATH,7,-10814.65,-27.47696,34.79253,0,0,0,0,100,0),
(@PATH,8,-10789.9,-17.2257,34.79253,0,0,0,0,100,0);

-- Pathing for Diseased Vulture Entry: 47202 'TDB FORMAT' 
SET @NPC := 266462;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-11101.2,`position_y`=-219.3785,`position_z`=44.44303 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,50331648,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-11101.2,-219.3785,44.44303,0,0,0,0,100,0),
(@PATH,2,-11090.95,-194.6297,44.44303,0,0,0,0,100,0),
(@PATH,3,-11066.2,-184.3785,44.44303,0,0,0,0,100,0),
(@PATH,4,-11041.45,-194.6297,44.44303,0,0,0,0,100,0),
(@PATH,5,-11031.2,-219.3785,44.44303,0,0,0,0,100,0),
(@PATH,6,-11041.45,-244.1272,44.44303,0,0,0,0,100,0),
(@PATH,7,-11066.2,-254.3785,44.44303,0,0,0,0,100,0),
(@PATH,8,-11090.95,-244.1272,44.44303,0,0,0,0,100,0);

-- Pathing for Diseased Vulture Entry: 47202 'TDB FORMAT' 
SET @NPC := 266478;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-10993.2,`position_y`=-205.691,`position_z`=33.94123 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,50331648,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-10993.2,-205.691,33.94123,0,0,0,0,100,0),
(@PATH,2,-10982.95,-180.9422,33.94123,0,0,0,0,100,0),
(@PATH,3,-10958.2,-170.691,33.94123,0,0,0,0,100,0),
(@PATH,4,-10933.45,-180.9422,33.94123,0,0,0,0,100,0),
(@PATH,5,-10923.2,-205.691,33.94123,0,0,0,0,100,0),
(@PATH,6,-10933.45,-230.4397,33.94123,0,0,0,0,100,0),
(@PATH,7,-10958.2,-240.691,33.94123,0,0,0,0,100,0),
(@PATH,8,-10982.95,-230.4397,33.94123,0,0,0,0,100,0);

-- Pathing for Diseased Vulture Entry: 47202 'TDB FORMAT' 
SET @NPC := 266479;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-10966.5,`position_y`=-153.9496,`position_z`=39.42795 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,50331648,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-10966.5,-153.9496,39.42795,0,0,0,0,100,0),
(@PATH,2,-10956.25,-129.2009,39.42795,0,0,0,0,100,0),
(@PATH,3,-10931.5,-118.9497,39.42795,0,0,0,0,100,0),
(@PATH,4,-10906.75,-129.2009,39.42795,0,0,0,0,100,0),
(@PATH,5,-10896.5,-153.9497,39.42795,0,0,0,0,100,0),
(@PATH,6,-10906.75,-178.6984,39.42795,0,0,0,0,100,0),
(@PATH,7,-10931.5,-188.9497,39.42795,0,0,0,0,100,0),
(@PATH,8,-10956.25,-178.6984,39.42795,0,0,0,0,100,0);

-- Pathing for Diseased Vulture Entry: 47202 'TDB FORMAT' 
SET @NPC := 266214;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-11100.9,`position_y`=-407.7899,`position_z`=53.69572 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,50331648,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-11100.9,-407.7899,53.69572,0,0,0,0,100,0),
(@PATH,2,-11090.65,-383.0412,53.69572,0,0,0,0,100,0),
(@PATH,3,-11065.9,-372.7899,53.69572,0,0,0,0,100,0),
(@PATH,4,-11041.15,-383.0412,53.69572,0,0,0,0,100,0),
(@PATH,5,-11030.9,-407.7899,53.69572,0,0,0,0,100,0),
(@PATH,6,-11041.15,-432.5387,53.69572,0,0,0,0,100,0),
(@PATH,7,-11065.9,-442.7899,53.69572,0,0,0,0,100,0),
(@PATH,8,-11090.65,-432.5387,53.69572,0,0,0,0,100,0);

-- Pathing for Diseased Vulture Entry: 47202 'TDB FORMAT' 
SET @NPC := 266476;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-10888.6,`position_y`=-78.94965,`position_z`=31.04124 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,50331648,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-10888.6,-78.94965,31.04124,0,0,0,0,100,0),
(@PATH,2,-10878.35,-54.20092,31.04124,0,0,0,0,100,0),
(@PATH,3,-10853.6,-43.94965,31.04124,0,0,0,0,100,0),
(@PATH,4,-10828.85,-54.20092,31.04124,0,0,0,0,100,0),
(@PATH,5,-10818.6,-78.94966,31.04124,0,0,0,0,100,0),
(@PATH,6,-10828.85,-103.6984,31.04124,0,0,0,0,100,0),
(@PATH,7,-10853.6,-113.9497,31.04124,0,0,0,0,100,0),
(@PATH,8,-10878.35,-103.6984,31.04124,0,0,0,0,100,0);

-- Pathing for Diseased Vulture Entry: 47202 'TDB FORMAT' 
SET @NPC := 266259;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-10923.2,`position_y`=-401.8715,`position_z`=51.43432 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,50331648,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-10923.2,-401.8715,51.43432,0,0,0,0,100,0),
(@PATH,2,-10912.95,-377.1228,51.43432,0,0,0,0,100,0),
(@PATH,3,-10888.2,-366.8715,51.43432,0,0,0,0,100,0),
(@PATH,4,-10863.45,-377.1228,51.43432,0,0,0,0,100,0),
(@PATH,5,-10853.2,-401.8715,51.43432,0,0,0,0,100,0),
(@PATH,6,-10863.45,-426.6203,51.43432,0,0,0,0,100,0),
(@PATH,7,-10888.2,-436.8715,51.43432,0,0,0,0,100,0),
(@PATH,8,-10912.95,-426.6202,51.43432,0,0,0,0,100,0);

-- Pathing for Diseased Vulture Entry: 47202 'TDB FORMAT' 
SET @NPC := 266423;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-10854.01,`position_y`=-358.0712,`position_z`=66.60728 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,50331648,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-10854.01,-358.0712,66.60728,0,0,0,0,100,0),
(@PATH,2,-10878.76,-347.8199,66.60728,0,0,0,0,100,0),
(@PATH,3,-10889.01,-323.0712,66.60728,0,0,0,0,100,0),
(@PATH,4,-10878.76,-298.3224,66.60728,0,0,0,0,100,0),
(@PATH,5,-10854.01,-288.0712,66.60728,0,0,0,0,100,0),
(@PATH,6,-10829.26,-298.3225,66.60728,0,0,0,0,100,0),
(@PATH,7,-10819.01,-323.0712,66.60728,0,0,0,0,100,0),
(@PATH,8,-10829.26,-347.8199,66.60728,0,0,0,0,100,0);

-- Pathing for Diseased Vulture Entry: 47202 'TDB FORMAT' 
SET @NPC := 266425;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-10750.8,`position_y`=-195.4045,`position_z`=70.55527 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,50331648,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-10750.8,-195.4045,70.55527,0,0,0,0,100,0),
(@PATH,2,-10775.55,-185.1532,70.55527,0,0,0,0,100,0),
(@PATH,3,-10785.8,-160.4045,70.55527,0,0,0,0,100,0),
(@PATH,4,-10775.55,-135.6558,70.55527,0,0,0,0,100,0),
(@PATH,5,-10750.8,-125.4045,70.55527,0,0,0,0,100,0),
(@PATH,6,-10726.05,-135.6558,70.55527,0,0,0,0,100,0),
(@PATH,7,-10715.8,-160.4045,70.55527,0,0,0,0,100,0),
(@PATH,8,-10726.05,-185.1533,70.55527,0,0,0,0,100,0);

-- Pathing for Diseased Vulture Entry: 47202 'TDB FORMAT' 
SET @NPC := 266463;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-11041.25,`position_y`=-216.6245,`position_z`=38.39705 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,50331648,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-11041.25,-216.6245,38.39705,0,0,0,0,100,0),
(@PATH,2,-10991.75,-216.6245,38.39705,0,0,0,0,100,0),
(@PATH,3,-10981.5,-241.3733,38.39705,0,0,0,0,100,0),
(@PATH,4,-10991.75,-266.122,38.39705,0,0,0,0,100,0),
(@PATH,5,-11016.5,-276.3733,38.39705,0,0,0,0,100,0),
(@PATH,6,-11041.25,-266.122,38.39705,0,0,0,0,100,0),
(@PATH,7,-11051.5,-241.3732,38.39705,0,0,0,0,100,0);

-- Pathing for Diseased Vulture Entry: 47202 'TDB FORMAT' 
SET @NPC := 266432;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-10900.1,`position_y`=-189.7622,`position_z`=39.58143 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,50331648,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-10900.1,-189.7622,39.58143,0,0,0,0,100,0),
(@PATH,2,-10889.85,-165.0134,39.58143,0,0,0,0,100,0),
(@PATH,3,-10865.1,-154.7622,39.58143,0,0,0,0,100,0),
(@PATH,4,-10840.35,-165.0134,39.58143,0,0,0,0,100,0),
(@PATH,5,-10830.1,-189.7622,39.58143,0,0,0,0,100,0),
(@PATH,6,-10840.35,-214.5109,39.58143,0,0,0,0,100,0),
(@PATH,7,-10865.1,-224.7622,39.58143,0,0,0,0,100,0),
(@PATH,8,-10889.85,-214.5109,39.58143,0,0,0,0,100,0);

-- Pathing for Diseased Vulture Entry: 47202 'TDB FORMAT' 
SET @NPC := 266434;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-10910.85,`position_y`=-250.904,`position_z`=50.73249 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,50331648,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-10910.85,-250.904,50.73249,0,0,0,0,100,0),
(@PATH,2,-10886.1,-240.6528,50.73249,0,0,0,0,100,0),
(@PATH,3,-10861.35,-250.904,50.73249,0,0,0,0,100,0),
(@PATH,4,-10851.1,-275.6528,50.73249,0,0,0,0,100,0),
(@PATH,5,-10861.35,-300.4015,50.73249,0,0,0,0,100,0),
(@PATH,6,-10886.1,-310.6528,50.73249,0,0,0,0,100,0),
(@PATH,7,-10910.85,-300.4015,50.73249,0,0,0,0,100,0),
(@PATH,8,-10921.1,-275.6528,50.73249,0,0,0,0,100,0);

-- Pathing for Diseased Vulture Entry: 47202 'TDB FORMAT' 
SET @NPC := 266233;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-10831.9,`position_y`=-489.3871,`position_z`=56.80947 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,50331648,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-10831.9,-489.3871,56.80947,0,0,0,0,100,0),
(@PATH,2,-10821.65,-464.6384,56.80947,0,0,0,0,100,0),
(@PATH,3,-10796.9,-454.3871,56.80947,0,0,0,0,100,0),
(@PATH,4,-10772.15,-464.6384,56.80947,0,0,0,0,100,0),
(@PATH,5,-10761.9,-489.3871,56.80947,0,0,0,0,100,0),
(@PATH,6,-10772.15,-514.1359,56.80947,0,0,0,0,100,0),
(@PATH,7,-10796.9,-524.3871,56.80947,0,0,0,0,100,0),
(@PATH,8,-10821.65,-514.1359,56.80947,0,0,0,0,100,0);

-- Pathing for Diseased Vulture Entry: 47202 'TDB FORMAT' 
SET @NPC := 266427;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-11088.3,`position_y`=-260.7465,`position_z`=45.79294 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,50331648,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-11088.3,-260.7465,45.79294,0,0,0,0,100,0),
(@PATH,2,-11078.05,-235.9978,45.79294,0,0,0,0,100,0),
(@PATH,3,-11053.3,-225.7465,45.79294,0,0,0,0,100,0),
(@PATH,4,-11028.55,-235.9978,45.79294,0,0,0,0,100,0),
(@PATH,5,-11018.3,-260.7465,45.79294,0,0,0,0,100,0),
(@PATH,6,-11028.55,-285.4953,45.79294,0,0,0,0,100,0),
(@PATH,7,-11053.3,-295.7465,45.79294,0,0,0,0,100,0),
(@PATH,8,-11078.05,-285.4952,45.79294,0,0,0,0,100,0);

-- Pathing for Diseased Vulture Entry: 47202 'TDB FORMAT' 
SET @NPC := 266461;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-10813.6,`position_y`=-196.3906,`position_z`=36.95673 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,50331648,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-10813.6,-196.3906,36.95673,0,0,0,0,100,0),
(@PATH,2,-10803.35,-171.6419,36.95673,0,0,0,0,100,0),
(@PATH,3,-10778.6,-161.3906,36.95673,0,0,0,0,100,0),
(@PATH,4,-10753.85,-171.6419,36.95673,0,0,0,0,100,0),
(@PATH,5,-10743.6,-196.3906,36.95673,0,0,0,0,100,0),
(@PATH,6,-10753.85,-221.1394,36.95673,0,0,0,0,100,0),
(@PATH,7,-10778.6,-231.3906,36.95673,0,0,0,0,100,0),
(@PATH,8,-10803.35,-221.1394,36.95673,0,0,0,0,100,0);

-- Pathing for Diseased Vulture Entry: 47202 'TDB FORMAT' 
SET @NPC := 266424;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-11013.5,`position_y`=-307.6215,`position_z`=51.17212 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,50331648,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-11013.5,-307.6215,51.17212,0,0,0,0,100,0),
(@PATH,2,-11003.25,-282.8728,51.17212,0,0,0,0,100,0),
(@PATH,3,-10978.5,-272.6215,51.17212,0,0,0,0,100,0),
(@PATH,4,-10953.75,-282.8728,51.17212,0,0,0,0,100,0),
(@PATH,5,-10943.5,-307.6215,51.17212,0,0,0,0,100,0),
(@PATH,6,-10953.75,-332.3703,51.17212,0,0,0,0,100,0),
(@PATH,7,-10978.5,-342.6215,51.17212,0,0,0,0,100,0),
(@PATH,8,-11003.25,-332.3702,51.17212,0,0,0,0,100,0);

-- Pathing for Diseased Vulture Entry: 47202 'TDB FORMAT' 
SET @NPC := 266260;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-10962.9,`position_y`=-362.3854,`position_z`=69.45817 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,50331648,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-10962.9,-362.3854,69.45817,0,0,0,0,100,0),
(@PATH,2,-10952.65,-337.6367,69.45817,0,0,0,0,100,0),
(@PATH,3,-10927.9,-327.3854,69.45817,0,0,0,0,100,0),
(@PATH,4,-10903.15,-337.6367,69.45817,0,0,0,0,100,0),
(@PATH,5,-10892.9,-362.3854,69.45817,0,0,0,0,100,0),
(@PATH,6,-10903.15,-387.1342,69.45817,0,0,0,0,100,0),
(@PATH,7,-10927.9,-397.3854,69.45817,0,0,0,0,100,0),
(@PATH,8,-10952.65,-387.1341,69.45817,0,0,0,0,100,0);

-- Pathing for Diseased Vulture Entry: 47202 'TDB FORMAT' 
SET @NPC := 266235;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-10847.3,`position_y`=-425.5833,`position_z`=60.31668 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,50331648,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-10847.3,-425.5833,60.31668,0,0,0,0,100,0),
(@PATH,2,-10837.05,-400.8346,60.31668,0,0,0,0,100,0),
(@PATH,3,-10812.3,-390.5833,60.31668,0,0,0,0,100,0),
(@PATH,4,-10787.55,-400.8346,60.31668,0,0,0,0,100,0),
(@PATH,5,-10777.3,-425.5833,60.31668,0,0,0,0,100,0),
(@PATH,6,-10787.55,-450.3321,60.31668,0,0,0,0,100,0),
(@PATH,7,-10812.3,-460.5833,60.31668,0,0,0,0,100,0),
(@PATH,8,-10837.05,-450.3321,60.31668,0,0,0,0,100,0);

-- Pathing for Diseased Vulture Entry: 47202 'TDB FORMAT' 
SET @NPC := 266460;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-10858.65,`position_y`=-116.6801,`position_z`=38.24604 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,50331648,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-10858.65,-116.6801,38.24604,0,0,0,0,100,0),
(@PATH,2,-10833.9,-106.4288,38.24604,0,0,0,0,100,0),
(@PATH,3,-10809.15,-116.6801,38.24604,0,0,0,0,100,0),
(@PATH,4,-10798.9,-141.4288,38.24604,0,0,0,0,100,0),
(@PATH,5,-10809.15,-166.1776,38.24604,0,0,0,0,100,0),
(@PATH,6,-10833.9,-176.4288,38.24604,0,0,0,0,100,0),
(@PATH,7,-10858.65,-166.1776,38.24604,0,0,0,0,100,0),
(@PATH,8,-10868.9,-141.4288,38.24604,0,0,0,0,100,0);

-- Pathing for Diseased Vulture Entry: 47202 'TDB FORMAT' 
SET @NPC := 266426;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-10764.15,`position_y`=-54.53426,`position_z`=34.36977 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,50331648,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-10764.15,-54.53426,34.36977,0,0,0,0,100,0),
(@PATH,2,-10753.9,-79.283,34.36977,0,0,0,0,100,0),
(@PATH,3,-10764.15,-104.0317,34.36977,0,0,0,0,100,0),
(@PATH,4,-10788.9,-114.283,34.36977,0,0,0,0,100,0),
(@PATH,5,-10813.65,-104.0317,34.36977,0,0,0,0,100,0),
(@PATH,6,-10823.9,-79.28298,34.36977,0,0,0,0,100,0),
(@PATH,7,-10813.65,-54.53425,34.36977,0,0,0,0,100,0),
(@PATH,8,-10788.9,-44.28299,34.36977,0,0,0,0,100,0);

-- Pathing for Diseased Vulture Entry: 47202 'TDB FORMAT' 
SET @NPC := 266475;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-10911.6,`position_y`=-98.13715,`position_z`=38.62015 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,50331648,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-10911.6,-98.13715,38.62015,0,0,0,0,100,0),
(@PATH,2,-10901.35,-73.38841,38.62015,0,0,0,0,100,0),
(@PATH,3,-10876.6,-63.13715,38.62015,0,0,0,0,100,0),
(@PATH,4,-10851.85,-73.38842,38.62015,0,0,0,0,100,0),
(@PATH,5,-10841.6,-98.13716,38.62015,0,0,0,0,100,0),
(@PATH,6,-10851.85,-122.8859,38.62015,0,0,0,0,100,0),
(@PATH,7,-10876.6,-133.1371,38.62015,0,0,0,0,100,0),
(@PATH,8,-10901.35,-122.8859,38.62015,0,0,0,0,100,0);

-- Pathing for Diseased Vulture Entry: 47202 'TDB FORMAT' 
SET @NPC := 266477;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-10856.8,`position_y`=-252.1076,`position_z`=60.53147 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,50331648,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-10856.8,-252.1076,60.53147,0,0,0,0,100,0),
(@PATH,2,-10846.55,-227.3589,60.53147,0,0,0,0,100,0),
(@PATH,3,-10821.8,-217.1076,60.53147,0,0,0,0,100,0),
(@PATH,4,-10797.05,-227.3589,60.53147,0,0,0,0,100,0),
(@PATH,5,-10786.8,-252.1076,60.53147,0,0,0,0,100,0),
(@PATH,6,-10797.05,-276.8564,60.53147,0,0,0,0,100,0),
(@PATH,7,-10821.8,-287.1076,60.53147,0,0,0,0,100,0),
(@PATH,8,-10846.55,-276.8564,60.53147,0,0,0,0,100,0);

-- Pathing for Diseased Vulture Entry: 47202 'TDB FORMAT' 
SET @NPC := 266474;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-10892.9,`position_y`=-362.3854,`position_z`=52.33913 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,50331648,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-10892.9,-362.3854,52.33913,0,0,0,0,100,0),
(@PATH,2,-10903.15,-387.1342,52.33913,0,0,0,0,100,0),
(@PATH,3,-10927.9,-397.3854,52.33913,0,0,0,0,100,0),
(@PATH,4,-10952.65,-387.1341,52.33913,0,0,0,0,100,0),
(@PATH,5,-10962.9,-362.3854,52.33913,0,0,0,0,100,0),
(@PATH,6,-10952.65,-337.6367,52.33913,0,0,0,0,100,0),
(@PATH,7,-10927.9,-327.3854,52.33913,0,0,0,0,100,0),
(@PATH,8,-10903.15,-337.6367,52.33913,0,0,0,0,100,0);
