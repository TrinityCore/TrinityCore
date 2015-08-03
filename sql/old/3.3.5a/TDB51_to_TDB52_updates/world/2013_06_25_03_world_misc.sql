-- Add Missing Gossip from sniff
DELETE FROM `gossip_menu` WHERE `entry`=6001 AND `text_id`=7154;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (6001,7154);

-- Add some missing spawns to BRS
SET @GUID := 20;  -- 4 Guids required
DELETE FROM `creature` WHERE `guid` BETWEEN @GUID AND @GUID+3;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@GUID,10447,229,1,1,0,0,202.5113,-421.307,110.9865,3.124139,7200,0,0,1,0,0),
(@GUID+1,10442,229,1,1,0,0,204.0151,-418.4425,110.9892,3.193953,7200,0,0,1,0,0),
(@GUID+2,10442,229,1,1,0,0,203.1424,-423.9987,110.9864,3.071779,7200,0,0,1,0,0),
(@GUID+3,10442,229,1,1,0,0,201.0076,-416.648,110.9738,3.228859,7200,0,0,1,0,0);

-- Add some missing spawns to BWL
SET @GUID := 61997;  -- 3 Guids required
DELETE FROM `creature` WHERE `guid` BETWEEN @GUID AND @GUID+3;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@GUID,12458,469,1,1,0,0,-7663.987,-1021.786,440.242,3.124139,7200,0,0,1,0,2),
(@GUID+1,12458,469,1,1,0,0,-7632.956,-996.5212,440.263,3.193953,7200,0,0,1,0,2),
(@GUID+2,12458,469,1,1,0,0,-7639.315,-1088.736,449.1642,3.071779,7200,0,0,1,0,2);

-- Fix walk speed for BWL npcs

UPDATE `creature_template` SET `speed_walk`=2 WHERE `entry`=11981;
UPDATE `creature_template` SET `speed_walk`=2 WHERE `entry`=11983;
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=12017;
UPDATE `creature_template` SET `speed_walk`=0.888888 WHERE `entry`=12435;
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=12457;
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=12458;
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=12459;
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=12460;
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=12461;
UPDATE `creature_template` SET `speed_walk`=0.888888 WHERE `entry`=12463;
UPDATE `creature_template` SET `speed_walk`=0.888888 WHERE `entry`=12464;
UPDATE `creature_template` SET `speed_walk`=0.888888 WHERE `entry`=12465;
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=12467;
UPDATE `creature_template` SET `speed_walk`=0.888888 WHERE `entry`=12468;
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=12557;
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=13020;
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=13996;
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=14020;
UPDATE `creature_template` SET `speed_walk`=1.11111 WHERE `entry`=14022;
UPDATE `creature_template` SET `speed_walk`=1.11111 WHERE `entry`=14023;
UPDATE `creature_template` SET `speed_walk`=1.11111 WHERE `entry`=14024;
UPDATE `creature_template` SET `speed_walk`=1.11111 WHERE `entry`=14025;
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=14262;
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=14263;
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=14264;
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=14401;
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=14456;
UPDATE `creature_template` SET `speed_walk`=2 WHERE `entry`=14601;

-- Delete bad spawn in BWL

DELETE FROM `creature` WHERE `guid`=85787;

-- some pathing for BWL

-- Pathing for Blackwing Taskmaster Entry: 12458
SET @NPC := @GUID;
SET @PATH := @NPC * 10;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-7663.987,-1021.786,440.242,0,0,0,0,100,0),
(@PATH,2,-7660.584,-1033.68,440.1774,0,0,0,0,100,0),
(@PATH,3,-7672.197,-1040.59,440.1905,0,0,0,0,100,0),
(@PATH,4,-7677.878,-1033.48,439.9819,0,0,0,0,100,0),
(@PATH,5,-7682.595,-1022.212,439.9823,0,0,0,0,100,0),
(@PATH,6,-7692.392,-1018.374,440.2688,0,0,0,0,100,0),
(@PATH,7,-7700.767,-1021.952,440.5112,0,0,0,0,100,0),
(@PATH,8,-7705.208,-1015.368,440.3909,0,0,0,0,100,0),
(@PATH,9,-7705.208,-1015.368,440.3909,0,0,0,0,100,0),
(@PATH,10,-7700.767,-1021.952,440.5112,0,0,0,0,100,0),
(@PATH,11,-7692.392,-1018.374,440.2688,0,0,0,0,100,0),
(@PATH,12,-7682.595,-1022.212,439.9823,0,0,0,0,100,0),
(@PATH,13,-7677.878,-1033.48,439.9819,0,0,0,0,100,0),
(@PATH,14,-7672.197,-1040.59,440.1905,0,0,0,0,100,0),
(@PATH,15,-7660.584,-1033.68,440.1774,0,0,0,0,100,0),
(@PATH,16,-7663.987,-1021.786,440.242,0,0,0,0,100,0),
(@PATH,17,-7667.698,-1013.725,440.2188,0,0,0,0,100,0),
(@PATH,18,-7674.316,-1009.231,440.1985,0,0,0,0,100,0),
(@PATH,19,-7674.749,-1001.641,440.1816,0,0,0,0,100,0),
(@PATH,20,-7682.151,-1002.882,439.9836,0,0,0,0,100,0),
(@PATH,21,-7691.953,-996.8887,440.1367,0,0,0,0,100,0),
(@PATH,22,-7698.791,-993.4288,440.0823,0,0,0,0,100,0),
(@PATH,23,-7700.935,-1000.517,440.1191,0,0,0,0,100,0),
(@PATH,24,-7704.313,-1004.795,440.1128,0,0,0,0,100,0),
(@PATH,25,-7699.01,-1015.984,440.3897,0,0,0,0,100,0),
(@PATH,26,-7696.855,-1024.059,440.4334,0,0,0,0,100,0),
(@PATH,27,-7690.041,-1030.21,440.3844,0,0,0,0,100,0),
(@PATH,28,-7683.866,-1038.302,440.3743,0,0,0,0,100,0),
(@PATH,29,-7679.78,-1047.461,440.1281,0,0,0,0,100,0),
(@PATH,30,-7695.097,-1052.926,440.6745,0,0,0,0,100,0),
(@PATH,31,-7711.689,-1063.992,445.1763,0,0,0,0,100,0),
(@PATH,32,-7711.689,-1063.992,445.1763,0,0,0,0,100,0),
(@PATH,33,-7695.097,-1052.926,440.6745,0,0,0,0,100,0),
(@PATH,34,-7679.78,-1047.461,440.1281,0,0,0,0,100,0),
(@PATH,35,-7683.866,-1038.302,440.3743,0,0,0,0,100,0),
(@PATH,36,-7690.041,-1030.21,440.3844,0,0,0,0,100,0),
(@PATH,37,-7696.855,-1024.059,440.4334,0,0,0,0,100,0),
(@PATH,38,-7699.01,-1015.984,440.3897,0,0,0,0,100,0),
(@PATH,39,-7704.313,-1004.795,440.1128,0,0,0,0,100,0),
(@PATH,40,-7700.935,-1000.517,440.1191,0,0,0,0,100,0),
(@PATH,41,-7698.791,-993.4288,440.0823,0,0,0,0,100,0),
(@PATH,42,-7691.953,-996.8887,440.1367,0,0,0,0,100,0),
(@PATH,43,-7682.151,-1002.882,439.9836,0,0,0,0,100,0),
(@PATH,44,-7674.749,-1001.641,440.1816,0,0,0,0,100,0),
(@PATH,45,-7674.316,-1009.231,440.1985,0,0,0,0,100,0),
(@PATH,46,-7667.698,-1013.725,440.2188,0,0,0,0,100,0);
-- 0xF13030AA0000B535 .go -7663.987 -1021.786 440.242

-- Pathing for Blackwing Taskmaster Entry: 12458
SET @NPC := @GUID+1;
SET @PATH := @NPC * 10;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-7632.956,-996.5212,440.263,0,0,0,0,100,0),
(@PATH,2,-7626.135,-996.6401,440.2635,0,0,0,0,100,0),
(@PATH,3,-7619.718,-993.6684,440.0176,0,0,0,0,100,0),
(@PATH,4,-7614.898,-986.8362,440.0524,0,0,0,0,100,0),
(@PATH,5,-7619.713,-975.4172,440.2763,0,0,0,0,100,0),
(@PATH,6,-7626.255,-967.6956,440.3156,0,0,0,0,100,0),
(@PATH,7,-7634.491,-969.407,440.0258,0,0,0,0,100,0),
(@PATH,8,-7637.204,-978.4598,439.993,0,0,0,0,100,0),
(@PATH,9,-7649.554,-984.3552,440.2628,0,0,0,0,100,0),
(@PATH,10,-7661.772,-988.5689,439.9864,0,0,0,0,100,0),
(@PATH,11,-7658.341,-1002.132,439.9857,0,0,0,0,100,0),
(@PATH,12,-7647.332,-1011.346,439.9858,0,0,0,0,100,0),
(@PATH,13,-7637.399,-1010.427,439.9867,0,0,0,0,100,0),
(@PATH,14,-7636.273,-1000.11,440.2625,0,0,0,0,100,0),
(@PATH,15,-7622.676,-987.7399,440.0219,0,0,0,0,100,0),
(@PATH,16,-7625.999,-977.4044,440.0362,0,0,0,0,100,0),
(@PATH,17,-7649.094,-972.2944,440.2316,0,0,0,0,100,0),
(@PATH,18,-7644.41,-979.6061,440.2635,0,0,0,0,100,0),
(@PATH,19,-7634.969,-989.9937,440.2634,0,0,0,0,100,0),
(@PATH,20,-7624.835,-986.701,440.0168,0,0,0,0,100,0),
(@PATH,21,-7620.448,-985.0109,440.037,0,0,0,0,100,0),
(@PATH,22,-7610.641,-984.5477,440.2049,0,0,0,0,100,0),
(@PATH,23,-7595.672,-988.9937,440.0914,0,0,0,0,100,0),
(@PATH,24,-7595.672,-988.9937,440.0914,0,0,0,0,100,0),
(@PATH,25,-7610.641,-984.5477,440.2049,0,0,0,0,100,0),
(@PATH,26,-7620.448,-985.0109,440.037,0,0,0,0,100,0),
(@PATH,27,-7624.835,-986.701,440.0168,0,0,0,0,100,0),
(@PATH,28,-7634.969,-989.9937,440.2634,0,0,0,0,100,0),
(@PATH,29,-7644.41,-979.6061,440.2635,0,0,0,0,100,0),
(@PATH,30,-7649.094,-972.2944,440.2316,0,0,0,0,100,0),
(@PATH,31,-7625.999,-977.4044,440.0362,0,0,0,0,100,0),
(@PATH,32,-7622.676,-987.7399,440.0219,0,0,0,0,100,0),
(@PATH,33,-7636.273,-1000.11,440.2625,0,0,0,0,100,0),
(@PATH,34,-7637.399,-1010.427,439.9867,0,0,0,0,100,0),
(@PATH,35,-7647.332,-1011.346,439.9858,0,0,0,0,100,0),
(@PATH,36,-7658.341,-1002.132,439.9857,0,0,0,0,100,0),
(@PATH,37,-7661.772,-988.5689,439.9864,0,0,0,0,100,0),
(@PATH,38,-7649.554,-984.3552,440.2628,0,0,0,0,100,0),
(@PATH,39,-7637.204,-978.4598,439.993,0,0,0,0,100,0),
(@PATH,40,-7634.491,-969.407,440.0258,0,0,0,0,100,0),
(@PATH,41,-7626.357,-967.7826,440.0594,0,0,0,0,100,0),
(@PATH,42,-7619.713,-975.4172,440.2763,0,0,0,0,100,0),
(@PATH,43,-7614.898,-986.8362,440.0524,0,0,0,0,100,0),
(@PATH,44,-7619.718,-993.6684,440.0176,0,0,0,0,100,0),
(@PATH,45,-7626.135,-996.6401,440.2635,0,0,0,0,100,0),
(@PATH,46,-7632.956,-996.5212,440.263,0,0,0,0,100,0),
(@PATH,47,-7653.352,-993.4436,439.9867,0,0,0,0,100,0),
(@PATH,48,-7653.352,-993.4436,439.9867,0,0,0,0,100,0);
-- 0xF13030AA0000B53D .go -7632.956 -996.5212 440.263

-- Pathing for Blackwing Taskmaster Entry: 12458
SET @NPC := @GUID+2;
SET @PATH := @NPC * 10;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-7639.315,-1088.736,449.1642,0,0,0,0,100,0),
(@PATH,2,-7644.75,-1097.218,449.1642,0,0,0,0,100,0),
(@PATH,3,-7651.393,-1110.778,449.193,0,0,0,0,100,0),
(@PATH,4,-7661.635,-1091.063,449.1826,0,0,0,0,100,0),
(@PATH,5,-7672.317,-1084.581,449.166,0,0,0,0,100,0),
(@PATH,6,-7678.168,-1087.581,449.1542,0,0,0,0,100,0),
(@PATH,7,-7671.085,-1100.425,449.1617,0,0,0,0,100,0),
(@PATH,8,-7665.083,-1108.27,449.1694,0,0,0,0,100,0),
(@PATH,9,-7658.763,-1114.884,449.1781,0,0,0,0,100,0),
(@PATH,10,-7670.01,-1119.684,449.1523,0,0,0,0,100,0),
(@PATH,11,-7680.338,-1118.28,449.134,0,0,0,0,100,0),
(@PATH,12,-7687.568,-1104.841,449.1463,0,0,0,0,100,0),
(@PATH,13,-7693.229,-1096.283,449.1507,0,0,0,0,100,0),
(@PATH,14,-7701.18,-1089.753,449.1177,0,0,0,0,100,0),
(@PATH,15,-7712.01,-1073.58,445.1763,0,0,0,0,100,0),
(@PATH,16,-7701.18,-1089.753,449.1177,0,0,0,0,100,0),
(@PATH,17,-7693.229,-1096.283,449.1507,0,0,0,0,100,0),
(@PATH,18,-7687.568,-1104.841,449.1463,0,0,0,0,100,0),
(@PATH,19,-7680.338,-1118.28,449.134,0,0,0,0,100,0),
(@PATH,20,-7670.01,-1119.684,449.1523,0,0,0,0,100,0),
(@PATH,21,-7658.763,-1114.884,449.1781,0,0,0,0,100,0),
(@PATH,22,-7665.083,-1108.27,449.1694,0,0,0,0,100,0),
(@PATH,23,-7671.085,-1100.425,449.1617,0,0,0,0,100,0),
(@PATH,24,-7678.168,-1087.581,449.1542,0,0,0,0,100,0),
(@PATH,25,-7672.317,-1084.581,449.166,0,0,0,0,100,0),
(@PATH,26,-7661.635,-1091.063,449.1826,0,0,0,0,100,0),
(@PATH,27,-7651.393,-1110.778,449.193,0,0,0,0,100,0),
(@PATH,28,-7644.75,-1097.218,449.1642,0,0,0,0,100,0);
-- 0xF13030AA0000B540 .go -7639.315 -1088.736 449.1642

-- Pathing for Blackwing Spellbinder Entry: 12457
SET @NPC := 85758;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-7446.97,`position_y`=-945.069,`position_z`=464.9834 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-7446.97,-945.069,464.9834,0,0,0,0,100,0),
(@PATH,2,-7449.199,-935.9932,464.9834,0,0,0,0,100,0),
(@PATH,3,-7453.252,-931.2498,464.9834,0,0,0,0,100,0),
(@PATH,4,-7463.244,-933.8245,464.9834,0,7000,0,0,100,0),
(@PATH,5,-7456.518,-929.4488,464.9834,0,0,0,0,100,0),
(@PATH,6,-7451.187,-934.4731,464.9834,0,0,0,0,100,0),
(@PATH,7,-7440.787,-950.2525,464.9834,0,19000,0,0,100,0),
(@PATH,8,-7437.717,-955.0467,464.9747,0,0,0,0,100,0),
(@PATH,9,-7443.361,-947.8978,464.9834,0,12000,0,0,100,0);
-- 0xF13030A90000B57B .go -7446.97 -945.069 464.9834

-- Pathing for Death Talon Overseer Entry: 12461
SET @NPC := 84557;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-7513.689,`position_y`=-1048.273,`position_z`=449.242 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-7513.689,-1048.273,449.242,0,0,0,0,100,0),
(@PATH,2,-7502.118,-1040.439,449.242,0,0,0,0,100,0),
(@PATH,3,-7492.288,-1033.455,449.242,0,0,0,0,100,0),
(@PATH,4,-7502.118,-1040.439,449.242,0,0,0,0,100,0),
(@PATH,5,-7513.689,-1048.273,449.242,0,0,0,0,100,0),
(@PATH,6,-7525.79,-1057.795,449.242,0,0,0,0,100,0);
-- 0xF13030AD0000B58D .go -7513.689 -1048.273 449.242
