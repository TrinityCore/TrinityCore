-- The following are the paths for the newly added mobs that have the same spawn spot as a mob (different phase and id) that already had a path. The paths are exactly the same as their already spawned counterparts.
-- Pathing for newly added Wrathstrike Gargoyles
-- -----------------------------------------------------------------------------------------------------------
SET @NEXT := 134704;
-- Wrathstrike Gargoyle 1
SET @NPC = @NEXT+103;
SET @PATH := @NPC * 10;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`) VALUES (@NPC,@PATH);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7060.05,455.727,581.492,0,0,0,100,0),
(@PATH,2,6982.99,465.858,581.492,0,0,0,100,0),
(@PATH,3,6963.94,516.342,581.492,0,0,0,100,0),
(@PATH,4,7012.51,555.944,581.492,0,0,0,100,0),
(@PATH,5,7062.92,517.784,566.464,0,0,0,100,0),
(@PATH,6,7074.5,487.171,566.464,0,0,0,100,0);
UPDATE `creature` SET `currentwaypoint`=0 WHERE `id`=30482 AND `currentwaypoint`=1217550;
-- -----------------------------------------------------------------------------------------------------------
-- Wrathstrike Gargoyle 2
SET @NPC = @NEXT+104;
SET @PATH := @NPC * 10;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`) VALUES (@NPC,@PATH);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,6975.12,457.238,608.122,0,0,0,100,0),
(@PATH,2,6994.13,442.679,608.122,0,0,0,100,0),
(@PATH,3,7024.58,437.239,608.122,0,0,0,100,0),
(@PATH,4,7055.78,456.622,580.705,0,0,0,100,0),
(@PATH,5,7069.78,488.277,580.705,0,0,0,100,0),
(@PATH,6,7057.18,540.235,608.205,0,0,0,100,0),
(@PATH,7,6978.62,537.405,608.205,0,0,0,100,0),
(@PATH,8,6960.95,489.864,595.233,0,0,0,100,0);
UPDATE `creature` SET `currentwaypoint`=0 WHERE `id`=30482 AND `currentwaypoint`=1217540;
-- -----------------------------------------------------------------------------------------------------------
-- Wrathstrike Gargoyle 3
SET @NPC = @NEXT+105;
SET @PATH := @NPC * 10;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`) VALUES (@NPC,@PATH);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,6817.71,701.731,436.81,0,0,0,100,0),
(@PATH,2,6839.81,671.33,438.476,0,0,0,100,0),
(@PATH,3,6771.48,625.298,444.032,0,0,0,100,0),
(@PATH,4,6729.31,607.063,451.504,0,0,0,100,0),
(@PATH,5,6689.26,569.483,444.032,0,0,0,100,0),
(@PATH,6,6664.17,580.683,449.976,0,0,0,100,0),
(@PATH,7,6657.52,638.465,440.893,0,0,0,100,0),
(@PATH,8,6664.19,665.048,444.032,0,0,0,100,0),
(@PATH,9,6735.33,692.836,433.938,0,0,0,100,0),
(@PATH,10,6741.25,694.33,433.56,0,0,0,100,0);
UPDATE `creature` SET `currentwaypoint`=0 WHERE `id`=30482 AND `currentwaypoint`=1217530;
-- -----------------------------------------------------------------------------------------------------------
-- Wrathstrike Gargoyle 4
SET @NPC = @NEXT+106;
SET @PATH := @NPC * 10;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`) VALUES (@NPC,@PATH);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,6808.92,649.929,459.327,0,0,0,100,0),
(@PATH,2,6779.63,606.717,465.077,0,0,0,100,0),
(@PATH,3,6799.14,541.206,474.66,0,0,0,100,0),
(@PATH,4,6863.37,520.467,465.077,0,0,0,100,0),
(@PATH,5,6900.8,554.799,459.216,0,0,0,100,0),
(@PATH,6,6904.96,624.433,471.549,0,0,0,100,0),
(@PATH,7,6860.9,661.477,465.077,0,0,0,100,0);
UPDATE `creature` SET `currentwaypoint`=0 WHERE `id`=30482 AND `currentwaypoint`=1217520;
-- -----------------------------------------------------------------------------------------------------------
-- Wrathstrike Gargoyle 5
SET @NPC = @NEXT+107;
SET @PATH := @NPC * 10;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`) VALUES (@NPC,@PATH);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,6764.29,413.94,446.625,0,0,0,100,0),
(@PATH,2,6727.13,417.659,446.625,0,0,0,100,0),
(@PATH,3,6709.2,445.43,446.625,0,0,0,100,0),
(@PATH,4,6714.21,476.942,446.625,0,0,0,100,0),
(@PATH,5,6760.44,491.312,446.625,0,0,0,100,0),
(@PATH,6,6786.47,463.163,446.625,0,0,0,100,0);
UPDATE `creature` SET `currentwaypoint`=0 WHERE `id`=30482 AND `currentwaypoint`=1217510;
-- -----------------------------------------------------------------------------------------------------------
-- Wrathstrike Gargoyle 6
SET @NPC = @NEXT+108;
SET @PATH := @NPC * 10;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`) VALUES (@NPC,@PATH);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,6589.56,608.719,445.037,0,0,0,100,0),
(@PATH,2,6536.49,613.397,445.037,0,0,0,100,0),
(@PATH,3,6515.31,571.263,445.037,0,0,0,100,0),
(@PATH,4,6540.83,538.391,445.037,0,0,0,100,0),
(@PATH,5,6561.1,543.055,445.037,0,0,0,100,0),
(@PATH,6,6595.09,559.099,445.037,0,0,0,100,0);
UPDATE `creature` SET `currentwaypoint`=0 WHERE `id`=30482 AND `currentwaypoint`=1217500;
-- -----------------------------------------------------------------------------------------------------------
-- Wrathstrike Gargoyle 7
SET @NPC = @NEXT+109;
SET @PATH := @NPC * 10;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`) VALUES (@NPC,@PATH);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,6661.58,545.496,432.795,0,0,0,100,0),
(@PATH,2,6659.48,589.326,447.184,0,0,0,100,0),
(@PATH,3,6628.78,594.459,446.434,0,0,0,100,0),
(@PATH,4,6613.69,584.967,446.434,0,0,0,100,0),
(@PATH,5,6595.45,562.222,444.795,0,0,0,100,0),
(@PATH,6,6595.77,535.16,436.934,0,0,0,100,0),
(@PATH,7,6631,528.616,450.823,0,0,0,100,0);
UPDATE `creature` SET `currentwaypoint`=0 WHERE `id`=30482 AND `currentwaypoint`=1217490;
-- -----------------------------------------------------------------------------------------------------------
-- Wrathstrike Gargoyle 8
SET @NPC = @NEXT+110;
SET @PATH := @NPC * 10;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`) VALUES (@NPC,@PATH);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,6585.6,408.848,446.514,0,0,0,100,0),
(@PATH,2,6607.57,400.701,444.745,0,0,0,100,0),
(@PATH,3,6647.89,401.573,444.745,0,0,0,100,0),
(@PATH,4,6667.63,414.847,433.912,0,0,0,100,0),
(@PATH,5,6648.87,462.506,444.745,0,0,0,100,0),
(@PATH,6,6592.11,478.371,444.745,0,0,0,100,0),
(@PATH,7,6501.26,474.703,444.745,0,0,0,100,0),
(@PATH,8,6484.09,430.145,485.097,0,0,0,100,0),
(@PATH,9,6519.88,419.711,485.097,0,0,0,100,0);
UPDATE `creature` SET `currentwaypoint`=0 WHERE `id`=30482 AND `currentwaypoint`=1217480;
-- -----------------------------------------------------------------------------------------------------------
-- Pathing for newly added Forgotten Depths Underkings
-- -----------------------------------------------------------------------------------------------------------
-- Forgotten Depths Underking 1
SET @NPC = @NEXT+96;
SET @PATH := @NPC * 10;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`) VALUES (@NPC,@PATH);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,6788.09,633.101,426.095,0,0,0,100,0),
(@PATH,2,6789.98,619.743,423.47,0,0,0,100,0),
(@PATH,3,6766.65,606.497,423.42,0,0,0,100,0),
(@PATH,4,6740.19,597.458,425.39,0,0,0,100,0),
(@PATH,5,6725.25,595.632,423.432,0,0,0,100,0),
(@PATH,6,6713.96,602.526,423.595,0,0,0,100,0),
(@PATH,7,6720.27,613.862,423.47,0,0,0,100,0),
(@PATH,8,6736.25,614.921,423.545,0,0,0,100,0),
(@PATH,9,6769.89,628.623,425.97,0,0,0,100,0);
UPDATE `creature` SET `currentwaypoint`=0 WHERE `id`=30541 AND `currentwaypoint`=1217290;
-- -----------------------------------------------------------------------------------------------------------
-- Forgotten Depths Underking 2
SET @NPC = @NEXT+97;
SET @PATH := @NPC * 10;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`) VALUES (@NPC,@PATH);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,6698.5,458.598,404.586,0,0,0,100,0),
(@PATH,2,6695.69,473.044,401.838,0,0,0,100,0),
(@PATH,3,6665,494.007,397.863,0,0,0,100,0),
(@PATH,4,6621.27,520.385,397.423,0,0,0,100,0),
(@PATH,5,6601.79,552.183,399.092,0,0,0,100,0),
(@PATH,6,6579.75,536.627,401.438,0,0,0,100,0),
(@PATH,7,6599.6,508.629,398.578,0,0,0,100,0),
(@PATH,8,6627.41,480.195,397.408,0,0,0,100,0),
(@PATH,9,6643.31,442.918,399.225,0,0,0,100,0),
(@PATH,10,6674.23,416.566,405.944,0,0,0,100,0),
(@PATH,11,6697.87,429.598,406.569,0,0,0,100,0);
UPDATE `creature` SET `currentwaypoint`=0 WHERE `id`=30541 AND `currentwaypoint`=1217300;
-- -----------------------------------------------------------------------------------------------------------
-- Forgotten Depths Underking 3-A
SET @NPC = @NEXT+98;
SET @PATH := @NPC * 10;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`) VALUES (@NPC,@PATH);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,6395.82,618.184,452.633,0,0,0,100,0),
(@PATH,2,6358.26,637.18,462.167,0,0,0,100,0),
(@PATH,3,6370.71,666.535,453.289,0,0,0,100,0),
(@PATH,4,6375.45,676.189,445.42,0,0,0,100,0),
(@PATH,5,6407.42,688.589,434.416,0,0,0,100,0),
(@PATH,6,6429.66,650.562,435.434,0,0,0,100,0),
(@PATH,7,6461.86,627.093,426.405,0,0,0,100,0),
(@PATH,8,6482.61,623.854,419.051,0,0,0,100,0),
(@PATH,9,6486.97,594.615,420.488,0,0,0,100,0),
(@PATH,10,6457.97,595.352,432.948,0,0,0,100,0),
(@PATH,11,6437.59,604.262,439.155,0,0,0,100,0);
UPDATE `creature` SET `currentwaypoint`=0 WHERE `id`=30541 AND `currentwaypoint`=1217310;
-- -----------------------------------------------------------------------------------------------------------
-- Forgotten Depths Underking 3-B
SET @NPC = @Next+87;
SET @PATH := @NPC * 10;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`) VALUES (@NPC,@PATH);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,6395.82,618.184,452.633,0,0,0,100,0),
(@PATH,2,6358.26,637.18,462.167,0,0,0,100,0),
(@PATH,3,6370.71,666.535,453.289,0,0,0,100,0),
(@PATH,4,6375.45,676.189,445.42,0,0,0,100,0),
(@PATH,5,6407.42,688.589,434.416,0,0,0,100,0),
(@PATH,6,6429.66,650.562,435.434,0,0,0,100,0),
(@PATH,7,6461.86,627.093,426.405,0,0,0,100,0),
(@PATH,8,6482.61,623.854,419.051,0,0,0,100,0),
(@PATH,9,6486.97,594.615,420.488,0,0,0,100,0),
(@PATH,10,6457.97,595.352,432.948,0,0,0,100,0),
(@PATH,11,6437.59,604.262,439.155,0,0,0,100,0);
UPDATE `creature` SET `currentwaypoint`=0 WHERE `id`=30544 AND `currentwaypoint`=1217310;
-- -----------------------------------------------------------------------------------------------------------
-- Forgotten Depths Underking 4
SET @NPC = @NEXT+99;
SET @PATH := @NPC * 10;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`) VALUES (@NPC,@PATH);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,6618.91,606.085,403.839,0,0,0,100,0),
(@PATH,2,6608.22,599.539,403.875,0,0,0,100,0),
(@PATH,3,6613.37,574.047,401.125,0,0,0,100,0),
(@PATH,4,6638.76,543.87,399.563,0,0,0,100,0),
(@PATH,5,6667.59,521.002,401.025,0,0,0,100,0),
(@PATH,6,6697.97,501.482,400.775,0,0,0,100,0),
(@PATH,7,6711.98,522.746,404.353,0,0,0,100,0),
(@PATH,8,6702.31,534.57,405.75,0,0,0,100,0),
(@PATH,9,6679.62,541.533,402.209,0,0,0,100,0),
(@PATH,10,6660.61,557.771,404.938,0,0,0,100,0),
(@PATH,11,6639.28,577.426,402.927,0,0,0,100,0),
(@PATH,12,6622.62,585.661,402.875,0,0,0,100,0);
UPDATE `creature` SET `currentwaypoint`=0 WHERE `id`=30541 AND `currentwaypoint`=1217320;
-- -----------------------------------------------------------------------------------------------------------
-- Forgotten Depths Underking 5
SET @NPC = @NEXT+100;
SET @PATH := @NPC * 10;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`) VALUES (@NPC,@PATH);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,6746.43,700.445,407.534,0,0,0,100,0),
(@PATH,2,6767.77,702.447,407.514,0,0,0,100,0),
(@PATH,3,6780.88,716.948,410.264,0,0,0,100,0),
(@PATH,4,6761.32,729.055,407.659,0,0,0,100,0),
(@PATH,5,6723.36,725.67,406.194,0,0,0,100,0),
(@PATH,6,6706.1,712.006,411.069,0,0,0,100,0),
(@PATH,7,6687.8,701.721,412.302,0,0,0,100,0),
(@PATH,8,6668.08,685.327,409.231,0,0,0,100,0),
(@PATH,9,6660.25,674.05,407.891,0,0,0,100,0),
(@PATH,10,6667.72,662.234,407.017,0,0,0,100,0),
(@PATH,11,6710.23,685.938,408.296,0,0,0,100,0);
UPDATE `creature` SET `currentwaypoint`=0 WHERE `id`=30541 AND `currentwaypoint`=1217330;
-- -----------------------------------------------------------------------------------------------------------
-- Forgotten Depths Underking 6
SET @NPC = @NEXT+101;
SET @PATH := @NPC * 10;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`) VALUES (@NPC,@PATH);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,6552.96,457.401,412.93,0,0,0,100,0),
(@PATH,2,6551.69,432.508,416.436,0,0,0,100,0),
(@PATH,3,6568.85,415.311,415.444,0,0,0,100,0),
(@PATH,4,6572.9,410.44,415.694,0,0,0,100,0),
(@PATH,5,6577.95,406.559,415.694,0,0,0,100,0),
(@PATH,6,6591.15,393.959,416.312,0,0,0,100,0),
(@PATH,7,6624.85,389.377,412.855,0,0,0,100,0),
(@PATH,8,6642.71,398.137,408.048,0,0,0,100,0),
(@PATH,9,6642.51,414.137,403.978,0,0,0,100,0),
(@PATH,10,6613.73,435.694,403.495,0,0,0,100,0),
(@PATH,11,6598.72,453.969,403.196,0,0,0,100,0),
(@PATH,12,6575.6,465.094,407.446,0,0,0,100,0);
UPDATE `creature` SET `currentwaypoint`=0 WHERE `id`=30541 AND `currentwaypoint`=1217360;
-- -----------------------------------------------------------------------------------------------------------
-- Forgotten Depths Underking 7
SET @NPC = @NEXT+102;
SET @PATH := @NPC * 10;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`) VALUES (@NPC,@PATH);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,6665.69,385.118,411.923,0,0,0,100,0),
(@PATH,2,6688.12,372.121,414.309,0,0,0,100,0),
(@PATH,3,6681.71,337.864,421.782,0,0,0,100,0),
(@PATH,4,6711.15,330.663,422.912,0,0,0,100,0),
(@PATH,5,6729,353.407,426.957,0,0,0,100,0),
(@PATH,6,6759.39,371.963,426.169,0,0,0,100,0),
(@PATH,7,6742.83,378.436,419.544,0,0,0,100,0),
(@PATH,8,6710.78,380.507,415.679,0,0,0,100,0),
(@PATH,9,6685.82,397.148,408.809,0,0,0,100,0),
(@PATH,10,6655.42,406.866,405.478,0,0,0,100,0),
(@PATH,11,6641.92,396.595,408.673,0,0,0,100,0);
UPDATE `creature` SET `currentwaypoint`=0 WHERE `id`=30541 AND `currentwaypoint`=1217370;
-- -----------------------------------------------------------------------------------------------------------
-- Forgotten Depths Underking 8
SET @NPC = @NEXT+93;
SET @PATH := @NPC * 10;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`) VALUES (@NPC,@PATH);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,6751.58,521.709,409.087,0,0,0,100,0),
(@PATH,2,6775.59,535.639,418.22,0,0,0,100,0),
(@PATH,3,6790.69,546.924,424.095,0,0,0,100,0),
(@PATH,4,6797.82,545.099,424.47,0,0,0,100,0),
(@PATH,5,6787.22,530.424,421.059,0,0,0,100,0),
(@PATH,6,6760.42,515.039,411.837,0,0,0,100,0);
UPDATE `creature` SET `currentwaypoint`=0 WHERE `id`=30541 AND `currentwaypoint`=1217270;
-- -----------------------------------------------------------------------------------------------------------
-- Pathing for newly added Forgotten Depths High Priests. There are A and B versions because only the ones from the last phase were already spawned in DB and had their pathing. This didn't occur with the Forgotten Depths Underkings because their first phase counterpats were already spawned (at least the ones with paths,the rest weren't). 2 of them don't get the current waypoint removed yet because its used for a guideline for creature_formations later.
-- -----------------------------------------------------------------------------------------------------------
-- Forgotten Depths High Priest 1-A
SET @NPC = @NEXT+25;
SET @PATH := @NPC * 10;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`) VALUES (@NPC,@PATH);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,6845.23,827.966,390.654,0,0,0,100,0),
(@PATH,2,6869.87,814.437,394.231,0,0,0,100,0),
(@PATH,3,6885.91,795.247,398.76,0,0,0,100,0),
(@PATH,4,6889.42,776.747,410.135,0,0,0,100,0),
(@PATH,5,6887.17,765.483,417.106,0,0,0,100,0),
(@PATH,6,6916.54,751.385,415.552,0,0,0,100,0),
(@PATH,7,6922.71,770.234,412.379,0,0,0,100,0),
(@PATH,8,6936.68,795.657,409.292,0,0,0,100,0),
(@PATH,9,6946.95,821.291,405.551,0,0,0,100,0),
(@PATH,10,6940.67,819.911,406.551,0,0,0,100,0),
(@PATH,11,6918.09,776.126,411.879,0,0,0,100,0),
(@PATH,12,6903.68,745.868,416.802,0,0,0,100,0),
(@PATH,13,6892.57,727.713,418.396,0,0,0,100,0),
(@PATH,14,6855.19,723.309,414.328,0,0,0,100,0),
(@PATH,15,6810.95,714.736,409.567,0,0,0,100,0),
(@PATH,16,6778.23,711.31,408.139,0,0,0,100,0),
(@PATH,17,6749.77,708.742,407.159,0,0,0,100,0),
(@PATH,18,6724.11,709.65,409.563,0,0,0,100,0),
(@PATH,19,6720.02,695.631,407.296,0,0,0,100,0),
(@PATH,20,6730.44,731.649,404.319,0,0,0,100,0),
(@PATH,21,6727.1,774.371,385.328,0,0,0,100,0),
(@PATH,22,6722.82,816.964,376.654,0,0,0,100,0),
(@PATH,23,6733.84,849.984,376.012,0,0,0,100,0),
(@PATH,24,6753.25,867.14,376.46,0,0,0,100,0),
(@PATH,25,6786.71,850.127,379.337,0,0,0,100,0),
(@PATH,26,6817.16,840.912,382.21,0,0,0,100,0);
-- -----------------------------------------------------------------------------------------------------------
-- Forgotten Depths High Priest 1-B
SET @NPC = @NEXT+42;
SET @PATH := @NPC * 10;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`) VALUES (@NPC,@PATH);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,6845.23,827.966,390.654,0,0,0,100,0),
(@PATH,2,6869.87,814.437,394.231,0,0,0,100,0),
(@PATH,3,6885.91,795.247,398.76,0,0,0,100,0),
(@PATH,4,6889.42,776.747,410.135,0,0,0,100,0),
(@PATH,5,6887.17,765.483,417.106,0,0,0,100,0),
(@PATH,6,6916.54,751.385,415.552,0,0,0,100,0),
(@PATH,7,6922.71,770.234,412.379,0,0,0,100,0),
(@PATH,8,6936.68,795.657,409.292,0,0,0,100,0),
(@PATH,9,6946.95,821.291,405.551,0,0,0,100,0),
(@PATH,10,6940.67,819.911,406.551,0,0,0,100,0),
(@PATH,11,6918.09,776.126,411.879,0,0,0,100,0),
(@PATH,12,6903.68,745.868,416.802,0,0,0,100,0),
(@PATH,13,6892.57,727.713,418.396,0,0,0,100,0),
(@PATH,14,6855.19,723.309,414.328,0,0,0,100,0),
(@PATH,15,6810.95,714.736,409.567,0,0,0,100,0),
(@PATH,16,6778.23,711.31,408.139,0,0,0,100,0),
(@PATH,17,6749.77,708.742,407.159,0,0,0,100,0),
(@PATH,18,6724.11,709.65,409.563,0,0,0,100,0),
(@PATH,19,6720.02,695.631,407.296,0,0,0,100,0),
(@PATH,20,6730.44,731.649,404.319,0,0,0,100,0),
(@PATH,21,6727.1,774.371,385.328,0,0,0,100,0),
(@PATH,22,6722.82,816.964,376.654,0,0,0,100,0),
(@PATH,23,6733.84,849.984,376.012,0,0,0,100,0),
(@PATH,24,6753.25,867.14,376.46,0,0,0,100,0),
(@PATH,25,6786.71,850.127,379.337,0,0,0,100,0),
(@PATH,26,6817.16,840.912,382.21,0,0,0,100,0);
-- -----------------------------------------------------------------------------------------------------------
-- Forgotten Depths High Priest 2-A
SET @NPC = @NEXT+26;
SET @PATH := @NPC * 10;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`) VALUES (@NPC,@PATH);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,6877.06,727.294,415.646,0,0,0,100,0),
(@PATH,2,6840.86,720.367,413.578,0,0,0,100,0),
(@PATH,3,6804.06,715.519,409.067,0,0,0,100,0),
(@PATH,4,6775.7,711.378,408.139,0,0,0,100,0),
(@PATH,5,6775.7,706.114,408.014,0,0,0,100,0),
(@PATH,6,6806.69,710.446,409.317,0,0,0,100,0),
(@PATH,7,6840.86,715.128,414.078,0,0,0,100,0),
(@PATH,8,6885.64,719.654,417.771,0,0,0,100,0),
(@PATH,9,6901.58,727.055,420.546,0,0,0,100,0);
UPDATE `creature` SET `currentwaypoint`=0 WHERE `id`=30203 AND `currentwaypoint`=1217170;
-- -----------------------------------------------------------------------------------------------------------
-- Forgotten Depths High Priest 2-B
SET @NPC = @NEXT+43;
SET @PATH := @NPC * 10;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`) VALUES (@NPC,@PATH);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,6877.06,727.294,415.646,0,0,0,100,0),
(@PATH,2,6840.86,720.367,413.578,0,0,0,100,0),
(@PATH,3,6804.06,715.519,409.067,0,0,0,100,0),
(@PATH,4,6775.7,711.378,408.139,0,0,0,100,0),
(@PATH,5,6775.7,706.114,408.014,0,0,0,100,0),
(@PATH,6,6806.69,710.446,409.317,0,0,0,100,0),
(@PATH,7,6840.86,715.128,414.078,0,0,0,100,0),
(@PATH,8,6885.64,719.654,417.771,0,0,0,100,0),
(@PATH,9,6901.58,727.055,420.546,0,0,0,100,0);
UPDATE `creature` SET `currentwaypoint`=0 WHERE `id`=30543 AND `currentwaypoint`=1217170;
-- -----------------------------------------------------------------------------------------------------------
-- Forgotten Depths High Priest 3-A
SET @NPC = @NEXT+27;
SET @PATH := @NPC * 10;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`) VALUES (@NPC,@PATH);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7028.06,593.528,484.848,0,0,0,100,0),
(@PATH,2,7050.86,587.232,490.487,0,0,0,100,0),
(@PATH,3,7088.02,583.536,496.767,0,0,0,100,0),
(@PATH,4,7135.53,587.626,498.11,0,0,0,100,0),
(@PATH,5,7174.15,581.088,498.373,0,0,0,100,0),
(@PATH,6,7200,579.166,498.248,0,0,0,100,0),
(@PATH,7,7217.31,586.021,496.983,0,0,0,100,0),
(@PATH,8,7203.83,615.728,490.388,0,0,0,100,0),
(@PATH,9,7164.62,625.286,496.707,0,0,0,100,0),
(@PATH,10,7126.29,619.13,497.944,0,0,0,100,0),
(@PATH,11,7094.89,587.951,498.017,0,0,0,100,0),
(@PATH,12,7050.28,590.763,490.362,0,0,0,100,0),
(@PATH,13,7013.81,602.295,479.513,0,0,0,100,0),
(@PATH,14,6987.71,624.076,465.805,0,0,0,100,0),
(@PATH,15,6964.91,625.148,460.924,0,0,0,100,0),
(@PATH,16,6944.73,587.153,467.576,0,0,0,100,0),
(@PATH,17,6927.86,556.953,466.828,0,0,0,100,0),
(@PATH,18,6919.79,527.804,467.056,0,0,0,100,0),
(@PATH,19,6907.68,497.326,466.719,0,0,0,100,0),
(@PATH,20,6914.34,512.11,466.681,0,0,0,100,0),
(@PATH,21,6926.01,537.956,466.578,0,0,0,100,0),
(@PATH,22,6938.29,577.003,466.951,0,0,0,100,0),
(@PATH,23,6952.16,594.699,466.951,0,0,0,100,0),
(@PATH,24,6969.78,616.559,463.68,0,0,0,100,0),
(@PATH,25,6985.14,615.594,467.305,0,0,0,100,0),
(@PATH,26,7002.27,602.799,476.138,0,0,0,100,0);
-- -----------------------------------------------------------------------------------------------------------
-- Forgotten Depths High Priest 3-B
SET @NPC = @NEXT+44;
SET @PATH := @NPC * 10;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`) VALUES (@NPC,@PATH);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7028.06,593.528,484.848,0,0,0,100,0),
(@PATH,2,7050.86,587.232,490.487,0,0,0,100,0),
(@PATH,3,7088.02,583.536,496.767,0,0,0,100,0),
(@PATH,4,7135.53,587.626,498.11,0,0,0,100,0),
(@PATH,5,7174.15,581.088,498.373,0,0,0,100,0),
(@PATH,6,7200,579.166,498.248,0,0,0,100,0),
(@PATH,7,7217.31,586.021,496.983,0,0,0,100,0),
(@PATH,8,7203.83,615.728,490.388,0,0,0,100,0),
(@PATH,9,7164.62,625.286,496.707,0,0,0,100,0),
(@PATH,10,7126.29,619.13,497.944,0,0,0,100,0),
(@PATH,11,7094.89,587.951,498.017,0,0,0,100,0),
(@PATH,12,7050.28,590.763,490.362,0,0,0,100,0),
(@PATH,13,7013.81,602.295,479.513,0,0,0,100,0),
(@PATH,14,6987.71,624.076,465.805,0,0,0,100,0),
(@PATH,15,6964.91,625.148,460.924,0,0,0,100,0),
(@PATH,16,6944.73,587.153,467.576,0,0,0,100,0),
(@PATH,17,6927.86,556.953,466.828,0,0,0,100,0),
(@PATH,18,6919.79,527.804,467.056,0,0,0,100,0),
(@PATH,19,6907.68,497.326,466.719,0,0,0,100,0),
(@PATH,20,6914.34,512.11,466.681,0,0,0,100,0),
(@PATH,21,6926.01,537.956,466.578,0,0,0,100,0),
(@PATH,22,6938.29,577.003,466.951,0,0,0,100,0),
(@PATH,23,6952.16,594.699,466.951,0,0,0,100,0),
(@PATH,24,6969.78,616.559,463.68,0,0,0,100,0),
(@PATH,25,6985.14,615.594,467.305,0,0,0,100,0),
(@PATH,26,7002.27,602.799,476.138,0,0,0,100,0);
-- --------------------------------------------------------------------------------------------------
-- Create creature formations based on already existing ones. Also remove the final current waypoints.
-- Creature Formation 1-A
-- --------------------------------------------------------------------------------------------------
SET @LEADER = @NEXT+27;
SET @NPC = @NEXT+89;
DELETE FROM `creature_formations` WHERE `leaderGUID`=@LEADER;
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`) VALUES
(@LEADER,@LEADER,0,0,2),
(@LEADER,@NPC,3,0,2);
UPDATE `creature` SET `currentwaypoint`=0 WHERE `id`=30203 AND `currentwaypoint`=1217200;
UPDATE `creature` SET `currentwaypoint`=0 WHERE `id`=30544 AND `currentwaypoint`=1217350;
-- Creature Formation 1-B
SET @LEADER = @NEXT+44;
SET @NPC = @NEXT+95;
DELETE FROM `creature_formations` WHERE `leaderGUID`=@LEADER;
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`) VALUES
(@LEADER,@LEADER,0,0,2),
(@LEADER,@NPC,3,0,2);
UPDATE `creature` SET `currentwaypoint`=0 WHERE `id`=30543 AND `currentwaypoint`=1217200;
UPDATE `creature` SET `currentwaypoint`=0 WHERE `id`=30541 AND `currentwaypoint`=1217350;
-- Creature Formation 2-A
SET @LEADER = @NEXT+25;
SET @NPC = @NEXT+86;
DELETE FROM `creature_formations` WHERE `leaderGUID`=@LEADER;
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`) VALUES
(@LEADER,@LEADER,0,0,2),
(@LEADER,@NPC,3,0,2);
UPDATE `creature` SET `currentwaypoint`=0 WHERE `id`=30203 AND `currentwaypoint`=1217160;
UPDATE `creature` SET `currentwaypoint`=0 WHERE `id`=30544 AND `currentwaypoint`=1217280;
-- Creature Formation 2-B
SET @LEADER = @NEXT+42;
SET @NPC = @NEXT+94;
DELETE FROM `creature_formations` WHERE `leaderGUID`=@LEADER;
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`) VALUES
(@LEADER,@LEADER,0,0,2),
(@LEADER,@NPC,3,0,2);
UPDATE `creature` SET `currentwaypoint`=0 WHERE `id`=30543 AND `currentwaypoint`=1217160;
UPDATE `creature` SET `currentwaypoint`=0 WHERE `id`=30541 AND `currentwaypoint`=1217280;
