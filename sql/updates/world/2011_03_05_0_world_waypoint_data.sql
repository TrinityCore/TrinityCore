-- Dragonmaw Skybreaker Pathing From sniff
UPDATE `creature_template` SET `speed_walk`=1,`speed_run`=1.2125 WHERE `entry`=22274;
DELETE FROM `creature` WHERE `guid`=132538;
DELETE FROM `creature_addon` WHERE `guid`=132538;

SET @NPC := 78291;
SET @PATH := @NPC*10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4919.375,`position_y`=764.9185,`position_z`=115.8213 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes2`) VALUES (@NPC,@PATH,20684,1);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4899.598,731.2864,115.8213,0,0,0,100,0),
(@PATH,2,-4897.536,699.804,115.8213,0,0,0,100,0),
(@PATH,3,-4907.958,682.649,115.8213,0,0,0,100,0),
(@PATH,4,-4928.547,677.3654,115.8213,0,0,0,100,0),
(@PATH,5,-4957.558,679.2119,115.8213,0,0,0,100,0),
(@PATH,6,-4979.058,694.0054,115.8213,0,0,0,100,0),
(@PATH,7,-5001.202,695.435,115.8213,0,0,0,100,0),
(@PATH,8,-5045.799,679.8455,115.8213,0,0,0,100,0),
(@PATH,9,-5082.077,674.1318,115.8213,0,0,0,100,0),
(@PATH,10,-5105.458,688.3859,126.0714,0,0,0,100,0),
(@PATH,11,-5124.419,708.7602,115.8213,0,0,0,100,0),
(@PATH,12,-5131.542,743.6093,115.8213,0,0,0,100,0),
(@PATH,13,-5122.893,762.6793,115.8213,0,0,0,100,0),
(@PATH,14,-5109.942,776.4905,127.7102,0,0,0,100,0),
(@PATH,15,-5082.581,787.4044,140.2658,0,0,0,100,0),
(@PATH,16,-5048.687,787.3963,129.2936,0,0,0,100,0),
(@PATH,17,-5029.247,794.6903,105.6824,0,0,0,100,0),
(@PATH,18,-5004.71,788.2552,111.238,0,0,0,100,0),
(@PATH,19,-4974.424,775.7346,115.8213,0,0,0,100,0),
(@PATH,20,-4944.215,765.6434,115.8213,0,0,0,100,0),
(@PATH,21,-4919.375,764.9185,115.8213,0,0,0,100,0);

SET @NPC := 78292;
SET @PATH := @NPC*10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4914.272,`position_y`=182.6655,`position_z`=105.3898 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes2`) VALUES (@NPC,@PATH,20684,1);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4927.019,212.1301,105.3898,0,0,0,100,0),
(@PATH,2,-4948.965,230.0244,105.3898,0,0,0,100,0),
(@PATH,3,-4975.733,226.1698,105.3898,0,0,0,100,0),
(@PATH,4,-4991.351,199.1344,103.001,0,0,0,100,0),
(@PATH,5,-5005.696,153.1891,116.7409,0,0,0,100,0),
(@PATH,6,-4998.949,135.7159,116.7409,0,0,0,100,0),
(@PATH,7,-4970.921,115.2041,116.7409,0,0,0,100,0),
(@PATH,8,-4920.846,153.8924,105.3898,0,0,0,100,0),
(@PATH,9,-4914.272,182.6655,105.3898,0,0,0,100,0);

SET @NPC := 78293;
SET @PATH := @NPC*10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-5001.053,`position_y`=507.8676,`position_z`=125.1893 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes2`) VALUES (@NPC,@PATH,20684,1);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4976.919,535.0216,125.1893,0,0,0,100,0),
(@PATH,2,-4945.772,544.8293,125.1893,0,0,0,100,0),
(@PATH,3,-4916.477,541.136,125.1893,0,0,0,100,0),
(@PATH,4,-4894.755,534.1898,125.1893,0,0,0,100,0),
(@PATH,5,-4878.672,517.9357,125.1893,0,0,0,100,0),
(@PATH,6,-4867.688,472.2867,125.1893,0,0,0,100,0),
(@PATH,7,-4866.018,440.9231,125.1893,0,0,0,100,0),
(@PATH,8,-4884.331,411.0111,125.1893,0,0,0,100,0),
(@PATH,9,-4909.612,389.5723,125.1893,0,0,0,100,0),
(@PATH,10,-4945.339,386.204,125.1893,0,0,0,100,0),
(@PATH,11,-4967.832,409.3968,125.1893,0,0,0,100,0),
(@PATH,12,-4986.726,443.7907,125.1893,0,0,0,100,0),
(@PATH,13,-4997.688,466.8292,125.1893,0,0,0,100,0),
(@PATH,14,-5001.053,507.8676,125.1893,0,0,0,100,0);

SET @NPC := 78294;
SET @PATH := @NPC*10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4957.768,`position_y`=-85.91428,`position_z`=117.7407 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes2`) VALUES (@NPC,@PATH,20684,1);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4979.801,-54.69292,117.2962,0,0,0,100,0),
(@PATH,2,-4973.231,-17.18837,111.824,0,0,0,100,0),
(@PATH,3,-4911.041,4.472439,118.324,0,0,0,100,0),
(@PATH,4,-4873.144,-22.93349,119.0185,0,0,0,100,0),
(@PATH,5,-4870.32,-65.83746,122.9629,0,0,0,100,0),
(@PATH,6,-4885.412,-99.36697,120.2129,0,0,0,100,0),
(@PATH,7,-4918.261,-108.4286,117.824,0,0,0,100,0),
(@PATH,8,-4957.768,-85.91428,117.7407,0,0,0,100,0);

SET @NPC := 78295;
SET @PATH := @NPC*10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-4989.571,`position_y`=277.2158,`position_z`=129.4455 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes2`) VALUES (@NPC,@PATH,20684,1);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-4981.606,252.022,129.4455,0,0,0,100,0),
(@PATH,2,-4961.62,234.8766,129.4455,0,0,0,100,0),
(@PATH,3,-4923.01,242.2214,129.4455,0,0,0,100,0),
(@PATH,4,-4900.703,257.2026,129.4455,0,0,0,100,0),
(@PATH,5,-4879.407,279.7445,129.4455,0,0,0,100,0),
(@PATH,6,-4865.226,310.3156,129.4455,0,0,0,100,0),
(@PATH,7,-4859.635,335.26,129.4455,0,0,0,100,0),
(@PATH,8,-4863.772,361.1568,129.4455,0,0,0,100,0),
(@PATH,9,-4897.918,374.3784,129.4455,0,0,0,100,0),
(@PATH,10,-4935.554,362.9577,129.4455,0,0,0,100,0),
(@PATH,11,-4956.634,339.5631,129.4455,0,0,0,100,0),
(@PATH,12,-4972.443,308.4228,129.4455,0,0,0,100,0),
(@PATH,13,-4989.571,277.2158,129.4455,0,0,0,100,0);

SET @NPC := 78296;
SET @PATH := @NPC*10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-5013.096,`position_y`=529.8334,`position_z`=147.466 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes2`) VALUES (@NPC,@PATH,20684,1);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-5034.7,530.1956,147.466,0,0,0,100,0),
(@PATH,2,-5058.567,549.2531,147.466,0,0,0,100,0),
(@PATH,3,-5077.942,585.5693,147.466,0,0,0,100,0),
(@PATH,4,-5085.871,616.8538,147.466,0,0,0,100,0),
(@PATH,5,-5073.225,640.2809,147.466,0,0,0,100,0),
(@PATH,6,-5046.584,656.348,147.466,0,0,0,100,0),
(@PATH,7,-5016.901,662.3196,147.466,0,0,0,100,0),
(@PATH,8,-4990.232,642.3178,147.466,0,0,0,100,0),
(@PATH,9,-4965.018,595.1047,147.466,0,0,0,100,0),
(@PATH,10,-4970.888,561.2855,147.466,0,0,0,100,0),
(@PATH,11,-4988.07,544.9948,147.466,0,0,0,100,0),
(@PATH,12,-5013.096,529.8334,147.466,0,0,0,100,0);

SET @NPC := 78297;
SET @PATH := @NPC*10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-5115.668,`position_y`=15.1122,`position_z`=156.0377 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes2`) VALUES (@NPC,@PATH,20684,1);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-5081.034,3.025608,156.0377,0,0,0,100,0),
(@PATH,2,-5054.209,-29.95432,156.0377,0,0,0,100,0),
(@PATH,3,-5044.757,-53.49219,156.0377,0,0,0,100,0),
(@PATH,4,-5063.791,-87.67003,156.0377,0,0,0,100,0),
(@PATH,5,-5100.97,-101.5627,156.0377,0,0,0,100,0),
(@PATH,6,-5139.875,-93.61002,156.0377,0,0,0,100,0),
(@PATH,7,-5157.834,-72.95584,158.5654,0,0,0,100,0),
(@PATH,8,-5150.443,-50.55273,150.9543,0,0,0,100,0),
(@PATH,9,-5154.681,-12.24284,156.0377,0,0,0,100,0),
(@PATH,10,-5139.686,8.807183,156.0377,0,0,0,100,0),
(@PATH,11,-5115.668,15.1122,156.0377,0,0,0,100,0);

SET @NPC := 78298;
SET @PATH := @NPC*10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-5128.899,`position_y`=485.1413,`position_z`=149.4686 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes2`) VALUES (@NPC,@PATH,20684,1);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-5096.786,491.9447,149.4686,0,0,0,100,0),
(@PATH,2,-5081.393,520.9803,149.5797,0,0,0,100,0),
(@PATH,3,-5082.821,560.8444,149.4686,0,0,0,100,0),
(@PATH,4,-5081.688,587.3782,149.4686,0,0,0,100,0),
(@PATH,5,-5096.75,614.0341,149.4686,0,0,0,100,0),
(@PATH,6,-5121.846,626.2573,149.4686,0,0,0,100,0),
(@PATH,7,-5143.037,616.5057,149.4686,0,0,0,100,0),
(@PATH,8,-5162.803,600.3235,149.4686,0,0,0,100,0),
(@PATH,9,-5175.979,585.7052,149.4686,0,0,0,100,0),
(@PATH,10,-5191.311,553.0349,149.4686,0,0,0,100,0),
(@PATH,11,-5182.97,516.0972,149.4686,0,0,0,100,0),
(@PATH,12,-5169.338,495.5091,149.4686,0,0,0,100,0),
(@PATH,13,-5128.899,485.1413,149.4686,0,0,0,100,0);

SET @NPC := 78299;
SET @PATH := @NPC*10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-5203.09,`position_y`=230.2053,`position_z`=125.2333 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes2`) VALUES (@NPC,@PATH,20684,1);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-5200.994,194.2652,125.2333,0,0,0,100,0),
(@PATH,2,-5209.843,162.355,125.2333,0,0,0,100,0),
(@PATH,3,-5223.84,126.7766,125.2333,0,0,0,100,0),
(@PATH,4,-5254.94,108.4594,125.2333,0,0,0,100,0),
(@PATH,5,-5272.563,119.1082,125.2333,0,0,0,100,0),
(@PATH,6,-5293.776,154.223,125.2333,0,0,0,100,0),
(@PATH,7,-5298.729,171.8369,125.2333,0,0,0,100,0),
(@PATH,8,-5300.312,208.0347,125.2333,0,0,0,100,0),
(@PATH,9,-5283.916,251.8668,125.2333,0,0,0,100,0),
(@PATH,10,-5241.004,262.8554,125.2333,0,0,0,100,0),
(@PATH,11,-5203.09,230.2053,125.2333,0,0,0,100,0);

SET @NPC := 78300;
SET @PATH := @NPC*10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-5234.025,`position_y`=262.7202,`position_z`=131.392 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes2`) VALUES (@NPC,@PATH,20684,1);
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-5255.758,267.988,131.392,0,0,0,100,0),
(@PATH,2,-5280.832,303.0705,131.392,0,0,0,100,0),
(@PATH,3,-5282.729,322.4258,131.392,0,0,0,100,0),
(@PATH,4,-5269.899,354.7595,131.392,0,0,0,100,0),
(@PATH,5,-5244.224,370.2118,131.392,0,0,0,100,0),
(@PATH,6,-5201.63,377.0772,131.392,0,0,0,100,0),
(@PATH,7,-5186.241,362.2412,131.392,0,0,0,100,0),
(@PATH,8,-5178.872,334.1438,131.392,0,0,0,100,0),
(@PATH,9,-5178.549,305.8703,131.392,0,0,0,100,0),
(@PATH,10,-5190.308,282.2744,131.392,0,0,0,100,0),
(@PATH,11,-5208.153,267.4322,131.392,0,0,0,100,0),
(@PATH,12,-5234.025,262.7202,131.392,0,0,0,100,0);
