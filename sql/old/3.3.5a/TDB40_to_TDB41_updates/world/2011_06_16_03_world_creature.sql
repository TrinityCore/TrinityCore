-- Pathing for Gjalerhorn Scavenger Entry: 27699
SET @NPC := 209069;
SET @PATH := @NPC * 10;
DELETE FROM `creature` WHERE `guid`=@NPC;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`curhealth`,`MovementType`) VALUES
(@NPC,27699,571,1,1,0,0,2697.419,-4016.824,376.924,0,120,1,2);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2720.878,-4016.57,377.9195,0,0,0,100,0),
(@PATH,2,2697.828,-4016.585,377.0644,0,0,0,100,0),
(@PATH,3,2688.135,-4019.685,375.1393,0,0,0,100,0),
(@PATH,4,2697.419,-4016.824,376.924,0,0,0,100,0);
-- Pathing for Gjalerhorn Scavenger Entry: 27699
SET @NPC := 209070;
SET @PATH := @NPC * 10;
DELETE FROM `creature` WHERE `guid`=@NPC;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`curhealth`,`MovementType`) VALUES
(@NPC,27699,571,1,1,0,0,2638.914,-3954.672,325.1407,0,120,1,2);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2654.15,-3942.158,338.6407,0,0,0,100,0),
(@PATH,2,2673.78,-3936.003,356.7825,0,0,0,100,0),
(@PATH,3,2687.534,-3933.731,366.9075,0,0,0,100,0),
(@PATH,4,2673.78,-3936.003,356.7825,0,0,0,100,0),
(@PATH,5,2654.15,-3942.158,338.6407,0,0,0,100,0),
(@PATH,6,2638.914,-3954.672,325.1407,0,0,0,100,0);
-- Pathing for Gjalerhorn Scavenger Entry: 27699
SET @NPC := 209071;
SET @PATH := @NPC * 10;
DELETE FROM `creature` WHERE `guid`=@NPC;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`curhealth`,`MovementType`) VALUES
(@NPC,27699,571,1,1,0,0,2736.774,-4092.956,380.9239,0,120,1,2);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2715.542,-4118.895,366.3432,0,0,0,100,0),
(@PATH,2,2694.547,-4124.934,358.1958,0,0,0,100,0),
(@PATH,3,2715.542,-4118.895,366.3432,0,0,0,100,0),
(@PATH,4,2736.774,-4092.956,380.9239,0,0,0,100,0);
-- Pathing for Gjalerhorn Scavenger Entry: 27699
SET @NPC := 209072;
SET @PATH := @NPC * 10;
DELETE FROM `creature` WHERE `guid`=@NPC;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`curhealth`,`MovementType`) VALUES
(@NPC,27699,571,1,1,0,0,2731.569,-4059.094,387.1922,0,120,1,2);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2703.275,-4056.196,372.1922,0,0,0,100,0),
(@PATH,2,2689.402,-4037.676,372.4806,0,0,0,100,0),
(@PATH,3,2703.275,-4056.196,372.1922,0,0,0,100,0),
(@PATH,4,2731.569,-4059.094,387.1922,0,0,0,100,0);
-- Pathing for Gjalerhorn Scavenger Entry: 27699
SET @NPC := 209073;
SET @PATH := @NPC * 10;
DELETE FROM `creature` WHERE `guid`=@NPC;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`curhealth`,`MovementType`) VALUES
(@NPC,27699,571,1,1,0,0,2708.681,-3949.61,375.7774,0,120,1,2);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2705.178,-3961.799,375.6524,0,0,0,100,0),
(@PATH,2,2696.735,-3974.133,375.7,0,0,0,100,0),
(@PATH,3,2696.953,-3984.144,375.95,0,0,0,100,0),
(@PATH,4,2699.271,-3976.043,375.7,0,0,0,100,0),
(@PATH,5,2707.984,-3965.564,376.0274,0,0,0,100,0),
(@PATH,6,2712.257,-3950.983,376.0274,0,0,0,100,0),
(@PATH,7,2708.681,-3949.61,375.7774,0,0,0,100,0);
-- Pathing for Gjalerhorn Scavenger Entry: 27699
SET @NPC := 209074;
SET @PATH := @NPC * 10;
DELETE FROM `creature` WHERE `guid`=@NPC;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`curhealth`,`MovementType`) VALUES
(@NPC,27699,571,1,1,0,0,2714.579,-3939.838,375.1524,0,120,1,2);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2708.935,-3922.262,375.2774,0,0,0,100,0),
(@PATH,2,2714.446,-3919.956,375.2774,0,0,0,100,0),
(@PATH,3,2729.402,-3932.177,374.5274,0,0,0,100,0),
(@PATH,4,2714.446,-3919.956,375.2774,0,0,0,100,0),
(@PATH,5,2708.935,-3922.262,375.2774,0,0,0,100,0),
(@PATH,6,2714.579,-3939.838,375.1524,0,0,0,100,0);
-- Pathing for Gjalerhorn Scavenger Entry: 27699
SET @NPC := 209075;
SET @PATH := @NPC * 10;
DELETE FROM `creature` WHERE `guid`=@NPC;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`curhealth`,`MovementType`) VALUES
(@NPC,27699,571,1,1,0,0,2784.569,-4011.168,379.6814,0,120,1,2);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2779.109,-4015.134,378.8367,0,0,0,100,0),
(@PATH,2,2772.743,-4003.694,378.4659,0,0,0,100,0),
(@PATH,3,2784.437,-4003.582,379.5116,0,0,0,100,0),
(@PATH,4,2784.569,-4011.168,379.6814,0,0,0,100,0);
-- Pathing for Gjalerhorn Scavenger Entry: 27699
SET @NPC := 209076;
SET @PATH := @NPC * 10;
DELETE FROM `creature` WHERE `guid`=@NPC;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`curhealth`,`MovementType`) VALUES
(@NPC,27699,571,1,1,0,0,2628.199,-4141.459,327.4775,0,120,1,2);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2611.351,-4128.365,318.1612,0,0,0,100,0),
(@PATH,2,2593.124,-4125.909,308.7285,0,0,0,100,0),
(@PATH,3,2611.351,-4128.365,318.1612,0,0,0,100,0),
(@PATH,4,2628.199,-4141.459,327.4775,0,0,0,100,0),
(@PATH,5,2624.449,-4161.107,331.8525,0,0,0,100,0),
(@PATH,6,2614.918,-4174.501,333.1044,0,0,0,100,0),
(@PATH,7,2624.413,-4161.336,331.8525,0,0,0,100,0),
(@PATH,8,2628.199,-4141.459,327.4775,0,0,0,100,0);
-- Pathing for Gjalerhorn Scavenger Entry: 27699
SET @NPC := 209077;
SET @PATH := @NPC * 10;
DELETE FROM `creature` WHERE `guid`=@NPC;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`curhealth`,`MovementType`) VALUES
(@NPC,27699,571,1,1,0,0,2673.117,-4088.239,356.8162,0,120,1,2);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2662.794,-4065.665,356.5576,0,0,0,100,0),
(@PATH,2,2676.103,-4058.589,361.4806,0,0,0,100,0),
(@PATH,3,2662.794,-4065.665,356.5576,0,0,0,100,0),
(@PATH,4,2673.117,-4088.239,356.8162,0,0,0,100,0),
(@PATH,5,2679.449,-4110.017,355.3208,0,0,0,100,0),
(@PATH,6,2673.117,-4088.239,356.8162,0,0,0,100,0);
-- Pathing for Gjalerhorn Scavenger Entry: 27699
SET @NPC := 209078;
SET @PATH := @NPC * 10;
DELETE FROM `creature` WHERE `guid`=@NPC;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`curhealth`,`MovementType`) VALUES
(@NPC,27699,571,1,1,0,0,2571.937,-3991.866,280.0677,0,120,1,2);
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2596.033,-3983.378,293.1927,0,0,0,100,0),
(@PATH,2,2571.937,-3991.866,280.0677,0,0,0,100,0);
