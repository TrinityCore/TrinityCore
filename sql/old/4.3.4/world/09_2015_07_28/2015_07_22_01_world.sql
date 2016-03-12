-- Durotar - Startzoneupdates
-- Randommovement + Waypointmovement
-- Pigmovement
UPDATE `creature` SET `spawndist`=5, `MovementType`=1 WHERE  `id` IN (3098, 3101);
UPDATE `creature` SET `spawndist`=4, `MovementType`=1 WHERE  `id` IN (3102);
UPDATE `creature` SET `spawndist`=8, `MovementType`=1 WHERE  `id` IN (39317, 3124, 3281);
-- Farmermovement
-- 1.
SET @NPC := 308507;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-470.4855,`position_y`=-4334.59,`position_z`=42.1432 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-470.4855,-4334.59,42.1432,0,0,0,0,100,0),
(@PATH,2,-469.9855,-4334.34,42.1432,0,0,0,0,100,0),
(@PATH,3,-468.7355,-4340.09,42.6432,0,0,0,0,100,0),
(@PATH,4,-467.8931,-4344.839,43.07516,0,0,0,0,100,0),
(@PATH,5,-473.3931,-4350.339,42.57516,0,0,0,0,100,0),
(@PATH,6,-477.8931,-4355.589,42.07516,0,0,0,0,100,0),
(@PATH,7,-478.342,-4355.535,42.01758,0,0,0,0,100,0),
(@PATH,8,-479.842,-4357.535,41.51758,0,0,0,0,100,0),
(@PATH,9,-483.342,-4355.785,41.01758,0,0,0,0,100,0),
(@PATH,10,-488.842,-4353.785,40.76758,0,0,0,0,100,0),
(@PATH,11,-489.1438,-4353.508,40.40612,0,0,0,0,100,0),
(@PATH,12,-489.6438,-4353.258,40.40612,0,0,0,0,100,0),
(@PATH,13,-492.253,-4347.719,39.57664,0,0,0,0,100,0),
(@PATH,14,-496.253,-4345.469,39.07664,0,0,0,0,100,0),
(@PATH,15,-498.9978,-4344.259,38.67751,0,0,0,0,100,0),
(@PATH,16,-505.2267,-4348.039,38.5797,0,0,0,0,100,0),
(@PATH,17,-513.0696,-4349.037,38.37053,0,0,0,0,100,0),
(@PATH,18,-518.1443,-4344.313,38.52625,0,0,0,0,100,0),
(@PATH,19,-510.8358,-4334.11,38.34673,0,0,0,0,100,0),
(@PATH,20,-490.9166,-4330.492,38.92451,0,0,0,0,100,0),
(@PATH,21,-486.9166,-4332.992,39.42451,0,0,0,0,100,0),
(@PATH,22,-484.4166,-4334.492,39.92451,0,0,0,0,100,0),
(@PATH,23,-480.9166,-4336.742,40.42451,0,0,0,0,100,0),
(@PATH,24,-480.716,-4336.729,40.76037,0,0,0,0,100,0),
(@PATH,25,-479.966,-4337.229,41.01037,0,0,0,0,100,0),
(@PATH,26,-474.466,-4335.479,41.26037,0,0,0,0,100,0),
(@PATH,27,-470.466,-4334.729,42.01037,0,0,0,0,100,0);

-- 2.
SET @NPC := 308475;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-460.2335,`position_y`=-4256.43,`position_z`=43.14126 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-460.2335,-4256.43,43.14126,0,0,0,0,100,0),
(@PATH,2,-460.2335,-4258.43,43.14126,0,0,0,0,100,0),
(@PATH,3,-458.2335,-4260.93,43.14126,0,0,0,0,100,0),
(@PATH,4,-457.7335,-4262.43,43.14126,0,0,0,0,100,0),
(@PATH,5,-457.7335,-4263.43,43.14126,0,0,0,0,100,0),
(@PATH,6,-457.7335,-4264.68,43.14126,0,0,0,0,100,0),
(@PATH,7,-457.7335,-4265.43,43.14126,0,0,0,0,100,0),
(@PATH,8,-457.7335,-4266.43,43.14126,0,0,0,0,100,0),
(@PATH,9,-457.2335,-4268.43,43.14126,0,0,0,0,100,0),
(@PATH,10,-457.2335,-4270.68,43.14126,0,0,0,0,100,0),
(@PATH,11,-454.2335,-4273.68,42.89126,0,0,0,0,100,0),
(@PATH,12,-453.9291,-4273.851,42.87144,0,0,0,0,100,0),
(@PATH,13,-453.1791,-4273.101,42.87144,0,0,0,0,100,0),
(@PATH,14,-440.3085,-4275.724,43.10865,0,0,0,0,100,0),
(@PATH,15,-424.7609,-4273.33,43.14249,0,0,0,0,100,0),
(@PATH,16,-417.6437,-4280.91,43.13181,0,0,0,0,100,0),
(@PATH,17,-418.515,-4286.642,43.13166,0,0,0,0,100,0),
(@PATH,18,-417.89,-4292.721,43.1136,0,0,0,0,100,0),
(@PATH,19,-424.2942,-4297.117,43.115,0,0,0,0,100,0),
(@PATH,20,-438.5636,-4296.199,43.1162,0,0,0,0,100,0),
(@PATH,21,-462.0463,-4281.595,43.15679,0,0,0,0,100,0),
(@PATH,22,-480.2531,-4278.673,43.19115,0,0,0,0,100,0),
(@PATH,23,-484.8112,-4277.182,43.2122,0,0,0,0,100,0),
(@PATH,24,-485.0693,-4266.113,43.25116,0,0,0,0,100,0);

-- Vile Familar
-- 1.
SET @NPC := 308396;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-132.0332,`position_y`=-4361.079,`position_z`=67.2796 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-132.0332,-4361.079,67.2796,0,0,0,0,100,0),
(@PATH,2,-131.7832,-4359.829,67.2796,0,0,0,0,100,0),
(@PATH,3,-131.0332,-4353.829,67.2796,0,0,0,0,100,0),
(@PATH,4,-130.5332,-4351.579,67.2796,0,0,0,0,100,0),
(@PATH,5,-130.2832,-4349.579,67.0296,0,0,0,0,100,0),
(@PATH,6,-130.0332,-4347.829,66.5296,0,0,0,0,100,0),
(@PATH,7,-129.6539,-4347.781,66.6899,0,0,0,0,100,0),
(@PATH,8,-129.6539,-4346.781,66.4399,0,0,0,0,100,0),
(@PATH,9,-127.9039,-4339.031,64.9399,0,0,0,0,100,0),
(@PATH,10,-127.7698,-4338.86,64.83606,0,0,0,0,100,0),
(@PATH,11,-127.5198,-4337.36,64.58606,0,0,0,0,100,0),
(@PATH,12,-124.0198,-4336.36,64.83606,0,0,0,0,100,0),
(@PATH,13,-121.7698,-4335.36,64.58606,0,0,0,0,100,0),
(@PATH,14,-120.0198,-4334.86,65.33606,0,0,0,0,100,0),
(@PATH,15,-118.0198,-4333.86,66.08606,0,0,0,0,100,0),
(@PATH,16,-114.1429,-4332.386,66.20154,0,0,0,0,100,0),
(@PATH,17,-108.6429,-4331.386,65.45154,0,0,0,0,100,0),
(@PATH,18,-103.6429,-4330.636,65.20154,0,0,0,0,100,0),
(@PATH,19,-98.39288,-4329.886,64.70154,0,0,0,0,100,0),
(@PATH,20,-97.14288,-4329.636,64.70154,0,0,0,0,100,0),
(@PATH,21,-97.10904,-4329.532,64.85739,0,0,0,0,100,0),
(@PATH,22,-95.60904,-4329.282,64.85739,0,0,0,0,100,0),
(@PATH,23,-89.35904,-4329.782,65.60739,0,0,0,0,100,0),
(@PATH,24,-84.60904,-4329.782,66.35739,0,0,0,0,100,0),
(@PATH,25,-83.10904,-4330.032,66.60739,0,0,0,0,100,0),
(@PATH,26,-77.75907,-4330.204,67.30329,0,0,0,0,100,0),
(@PATH,27,-75.25907,-4332.454,67.55329,0,0,0,0,100,0),
(@PATH,28,-73.25907,-4334.204,67.55329,0,0,0,0,100,0),
(@PATH,29,-69.03862,-4337.666,67.99888,0,0,0,0,100,0),
(@PATH,30,-64.78862,-4336.166,68.49888,0,0,0,0,100,0),
(@PATH,31,-58.53862,-4333.916,68.24888,0,0,0,0,100,0),
(@PATH,32,-57.53862,-4333.666,67.99888,0,0,0,0,100,0),
(@PATH,33,-55.78862,-4332.916,68.24888,0,0,0,0,100,0),
(@PATH,34,-55.71005,-4332.89,68.12064,0,0,0,0,100,0),
(@PATH,35,-57.21005,-4333.39,68.12064,0,0,0,0,100,0),
(@PATH,36,-58.46005,-4333.89,68.12064,0,0,0,0,100,0),
(@PATH,37,-64.96005,-4336.14,68.62064,0,0,0,0,100,0),
(@PATH,38,-69.23517,-4337.551,68.13313,0,0,0,0,100,0),
(@PATH,39,-72.98517,-4334.301,67.63313,0,0,0,0,100,0),
(@PATH,40,-75.23517,-4332.551,67.63313,0,0,0,0,100,0),
(@PATH,41,-78.0438,-4330.29,67.16,0,0,0,0,100,0),
(@PATH,42,-82.5438,-4330.04,66.41,0,0,0,0,100,0),
(@PATH,43,-84.5438,-4329.79,66.16,0,0,0,0,100,0),
(@PATH,44,-89.2938,-4329.79,65.91,0,0,0,0,100,0),
(@PATH,45,-95.85461,-4329.497,65.00662,0,0,0,0,100,0),
(@PATH,46,-97.35461,-4329.747,64.75662,0,0,0,0,100,0),
(@PATH,47,-98.35461,-4329.747,64.75662,0,0,0,0,100,0),
(@PATH,48,-103.3546,-4330.747,65.25662,0,0,0,0,100,0),
(@PATH,49,-108.8546,-4331.247,65.50662,0,0,0,0,100,0),
(@PATH,50,-114.0874,-4332.393,65.97079,0,0,0,0,100,0),
(@PATH,51,-118.0874,-4333.893,65.97079,0,0,0,0,100,0),
(@PATH,52,-119.8374,-4334.643,65.22079,0,0,0,0,100,0),
(@PATH,53,-121.8374,-4335.143,64.47079,0,0,0,0,100,0),
(@PATH,54,-124.0874,-4335.893,64.72079,0,0,0,0,100,0),
(@PATH,55,-127.4013,-4337.554,64.54872,0,0,0,0,100,0),
(@PATH,56,-127.6513,-4339.054,65.04872,0,0,0,0,100,0),
(@PATH,57,-129.8121,-4346.878,66.48911,0,0,0,0,100,0),
(@PATH,58,-130.0621,-4347.878,66.73911,0,0,0,0,100,0),
(@PATH,59,-130.0621,-4348.878,66.98911,0,0,0,0,100,0),
(@PATH,60,-130.5621,-4351.628,67.23911,0,0,0,0,100,0),
(@PATH,61,-130.8121,-4353.378,67.48911,0,0,0,0,100,0),
(@PATH,62,-131.5621,-4359.128,67.23911,0,0,0,0,100,0),
(@PATH,63,-131.8749,-4359.559,67.24004,0,0,0,0,100,0),
(@PATH,64,-132.1249,-4361.559,67.24004,0,0,0,0,100,0),
(@PATH,65,-135.8749,-4365.809,66.74004,0,0,0,0,100,0),
(@PATH,66,-136.8749,-4366.809,66.49004,0,0,0,0,100,0),
(@PATH,67,-137.8749,-4368.059,66.49004,0,0,0,0,100,0),
(@PATH,68,-138.2061,-4368.095,66.24431,0,0,0,0,100,0),
(@PATH,69,-139.7061,-4369.845,66.49431,0,0,0,0,100,0),
(@PATH,70,-141.4561,-4368.345,66.99431,0,0,0,0,100,0),
(@PATH,71,-144.2061,-4365.845,67.49431,0,0,0,0,100,0),
(@PATH,72,-146.7061,-4363.345,68.24431,0,0,0,0,100,0),
(@PATH,73,-147.7061,-4362.345,68.49431,0,0,0,0,100,0),
(@PATH,74,-148.9561,-4361.345,68.49431,0,0,0,0,100,0),
(@PATH,75,-150.9561,-4359.845,68.49431,0,0,0,0,100,0),
(@PATH,76,-152.7061,-4358.095,67.24431,0,0,0,0,100,0),
(@PATH,77,-152.8712,-4358.307,67.39958,0,0,0,0,100,0),
(@PATH,78,-154.1212,-4357.057,67.14958,0,0,0,0,100,0),
(@PATH,79,-155.8712,-4357.807,67.14958,0,0,0,0,100,0),
(@PATH,80,-156.8712,-4358.057,67.14958,0,0,0,0,100,0),
(@PATH,81,-160.1212,-4359.307,67.39958,0,0,0,0,100,0),
(@PATH,82,-160.0587,-4359.212,67.28593,0,0,0,0,100,0),
(@PATH,83,-157.0587,-4358.212,67.03593,0,0,0,0,100,0),
(@PATH,84,-155.8087,-4357.712,67.03593,0,0,0,0,100,0),
(@PATH,85,-155.5322,-4357.633,67.04594,0,0,0,0,100,0),
(@PATH,86,-154.0322,-4357.133,67.04594,0,0,0,0,100,0),
(@PATH,87,-152.7822,-4358.133,67.29594,0,0,0,0,100,0),
(@PATH,88,-151.0322,-4359.633,68.29594,0,0,0,0,100,0),
(@PATH,89,-149.0322,-4361.383,68.54594,0,0,0,0,100,0),
(@PATH,90,-148.0322,-4362.633,68.54594,0,0,0,0,100,0),
(@PATH,91,-147.0322,-4363.383,68.29594,0,0,0,0,100,0),
(@PATH,92,-144.2822,-4365.883,67.54594,0,0,0,0,100,0),
(@PATH,93,-141.2822,-4368.383,67.04594,0,0,0,0,100,0);

-- 2.
SET @NPC := 308372;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-53.24252,`position_y`=-4300.978,`position_z`=70.41556 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-53.24252,-4300.978,70.41556,0,0,0,0,100,0),
(@PATH,2,-53.24252,-4302.228,70.41556,0,0,0,0,100,0),
(@PATH,3,-51.49252,-4303.228,69.91556,0,0,0,0,100,0),
(@PATH,4,-45.49252,-4306.978,70.16556,0,0,0,0,100,0),
(@PATH,5,-40.24252,-4310.478,70.41556,0,0,0,0,100,0),
(@PATH,6,-45.55837,-4307.058,70.08119,0,0,0,0,100,0),
(@PATH,7,-51.55837,-4303.308,70.08119,0,0,0,0,100,0),
(@PATH,8,-53.48653,-4301.826,70.06717,0,0,0,0,100,0),
(@PATH,9,-53.48653,-4300.826,70.31717,0,0,0,0,100,0),
(@PATH,10,-53.98653,-4298.076,71.06717,0,0,0,0,100,0),
(@PATH,11,-53.98653,-4295.826,70.81717,0,0,0,0,100,0),
(@PATH,12,-54.48653,-4292.076,71.06717,0,0,0,0,100,0),
(@PATH,13,-55.73653,-4283.076,69.81717,0,0,0,0,100,0),
(@PATH,14,-55.83473,-4282.814,69.83765,0,0,0,0,100,0),
(@PATH,15,-56.08473,-4280.064,70.08765,0,0,0,0,100,0),
(@PATH,16,-51.58473,-4277.814,69.33765,0,0,0,0,100,0),
(@PATH,17,-49.58473,-4276.814,69.33765,0,0,0,0,100,0),
(@PATH,18,-40.08473,-4272.314,68.08765,0,0,0,0,100,0),
(@PATH,19,-36.33473,-4270.564,67.33765,0,0,0,0,100,0),
(@PATH,20,-36.12806,-4270.257,67.21318,0,0,0,0,100,0),
(@PATH,21,-35.37806,-4270.007,66.96318,0,0,0,0,100,0),
(@PATH,22,-31.62806,-4266.507,66.96318,0,0,0,0,100,0),
(@PATH,23,-30.37806,-4265.007,66.96318,0,0,0,0,100,0),
(@PATH,24,-28.62806,-4263.507,66.96318,0,0,0,0,100,0),
(@PATH,25,-27.62806,-4262.757,66.96318,0,0,0,0,100,0),
(@PATH,26,-25.12806,-4260.257,66.96318,0,0,0,0,100,0),
(@PATH,27,-25.17934,-4259.919,67.09102,0,0,0,0,100,0),
(@PATH,28,-23.67934,-4258.669,67.09102,0,0,0,0,100,0),
(@PATH,29,-24.92934,-4255.169,67.59102,0,0,0,0,100,0),
(@PATH,30,-25.92934,-4252.919,67.84102,0,0,0,0,100,0),
(@PATH,31,-26.17934,-4251.669,68.09102,0,0,0,0,100,0),
(@PATH,32,-26.67934,-4250.419,68.09102,0,0,0,0,100,0),
(@PATH,33,-27.42934,-4248.169,68.59102,0,0,0,0,100,0),
(@PATH,34,-27.67934,-4247.169,68.84102,0,0,0,0,100,0),
(@PATH,35,-27.60041,-4246.875,68.79475,0,0,0,0,100,0),
(@PATH,36,-28.35041,-4245.125,68.54475,0,0,0,0,100,0),
(@PATH,37,-26.35041,-4240.875,68.29475,0,0,0,0,100,0),
(@PATH,38,-25.85041,-4240.125,68.29475,0,0,0,0,100,0),
(@PATH,39,-25.35041,-4238.875,68.29475,0,0,0,0,100,0),
(@PATH,40,-25.29353,-4238.765,68.20535,0,0,0,0,100,0),
(@PATH,41,-25.04353,-4238.265,68.20535,0,0,0,0,100,0),
(@PATH,42,-27.79353,-4235.765,68.20535,0,0,0,0,100,0),
(@PATH,43,-30.79353,-4232.765,67.45535,0,0,0,0,100,0),
(@PATH,44,-33.54353,-4230.015,66.70535,0,0,0,0,100,0),
(@PATH,45,-34.54353,-4229.015,66.20535,0,0,0,0,100,0),
(@PATH,46,-35.84145,-4227.769,65.30698,0,0,0,0,100,0),
(@PATH,47,-38.34145,-4226.769,65.30698,0,0,0,0,100,0),
(@PATH,48,-39.59145,-4226.269,65.05698,0,0,0,0,100,0),
(@PATH,49,-40.59145,-4226.019,64.55698,0,0,0,0,100,0),
(@PATH,50,-44.09145,-4224.769,63.80698,0,0,0,0,100,0),
(@PATH,51,-44.13584,-4224.733,63.74107,0,0,0,0,100,0),
(@PATH,52,-40.63584,-4225.983,64.74107,0,0,0,0,100,0),
(@PATH,53,-39.63584,-4226.483,64.99107,0,0,0,0,100,0),
(@PATH,54,-38.38584,-4226.733,65.24107,0,0,0,0,100,0),
(@PATH,55,-35.60578,-4228.208,65.62875,0,0,0,0,100,0),
(@PATH,56,-34.35578,-4229.208,66.37875,0,0,0,0,100,0),
(@PATH,57,-33.60578,-4229.958,66.62875,0,0,0,0,100,0),
(@PATH,58,-31.35578,-4232.458,67.37875,0,0,0,0,100,0),
(@PATH,59,-27.85578,-4235.708,68.12875,0,0,0,0,100,0),
(@PATH,60,-25.85578,-4237.458,68.37875,0,0,0,0,100,0),
(@PATH,61,-25.83818,-4237.783,68.29486,0,0,0,0,100,0),
(@PATH,62,-25.08818,-4238.533,68.29486,0,0,0,0,100,0),
(@PATH,63,-25.58818,-4239.533,68.29486,0,0,0,0,100,0),
(@PATH,64,-26.33818,-4241.033,68.29486,0,0,0,0,100,0),
(@PATH,65,-28.08818,-4244.783,68.54486,0,0,0,0,100,0),
(@PATH,66,-28.01328,-4244.973,68.70169,0,0,0,0,100,0),
(@PATH,67,-28.26328,-4245.473,68.70169,0,0,0,0,100,0),
(@PATH,68,-27.76328,-4247.223,68.70169,0,0,0,0,100,0),
(@PATH,69,-27.26328,-4248.223,68.70169,0,0,0,0,100,0),
(@PATH,70,-26.51328,-4250.223,68.20169,0,0,0,0,100,0),
(@PATH,71,-26.01328,-4251.473,67.95169,0,0,0,0,100,0),
(@PATH,72,-25.51328,-4252.723,67.95169,0,0,0,0,100,0),
(@PATH,73,-24.76328,-4255.223,67.45169,0,0,0,0,100,0),
(@PATH,74,-23.68482,-4258.861,67.03264,0,0,0,0,100,0),
(@PATH,75,-24.68482,-4259.861,67.03264,0,0,0,0,100,0),
(@PATH,76,-27.18482,-4262.361,67.03264,0,0,0,0,100,0),
(@PATH,77,-28.43482,-4263.111,67.03264,0,0,0,0,100,0),
(@PATH,78,-30.18482,-4265.111,67.03264,0,0,0,0,100,0),
(@PATH,79,-31.18482,-4265.861,67.03264,0,0,0,0,100,0),
(@PATH,80,-34.93482,-4269.361,67.03264,0,0,0,0,100,0),
(@PATH,81,-35.24422,-4269.766,67.16302,0,0,0,0,100,0),
(@PATH,82,-35.74422,-4270.266,67.41302,0,0,0,0,100,0),
(@PATH,83,-39.49422,-4272.016,67.91302,0,0,0,0,100,0),
(@PATH,84,-48.99422,-4276.516,69.16302,0,0,0,0,100,0),
(@PATH,85,-51.74422,-4278.016,69.41302,0,0,0,0,100,0),
(@PATH,86,-56.08315,-4280.23,70.16069,0,0,0,0,100,0),
(@PATH,87,-55.83315,-4282.48,69.91069,0,0,0,0,100,0),
(@PATH,88,-54.58315,-4291.98,71.16069,0,0,0,0,100,0);

-- 3.
SET @NPC := 308352;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-110.1336,`position_y`=-4210.384,`position_z`=54.94224 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-110.1336,-4210.384,54.94224,0,0,0,0,100,0),
(@PATH,2,-106.3836,-4207.884,54.69224,0,0,0,0,100,0),
(@PATH,3,-104.8836,-4206.884,54.19224,0,0,0,0,100,0),
(@PATH,4,-100.8836,-4204.634,52.44224,0,0,0,0,100,0),
(@PATH,5,-96.12328,-4201.613,51.64252,0,0,0,0,100,0),
(@PATH,6,-94.62328,-4201.863,51.14252,0,0,0,0,100,0),
(@PATH,7,-88.87328,-4202.863,50.89252,0,0,0,0,100,0),
(@PATH,8,-86.62328,-4203.363,50.39252,0,0,0,0,100,0),
(@PATH,9,-83.12328,-4203.863,50.14252,0,0,0,0,100,0),
(@PATH,10,-80.73439,-4204.514,50.17667,0,0,0,0,100,0),
(@PATH,11,-80.73439,-4207.514,50.42667,0,0,0,0,100,0),
(@PATH,12,-80.48439,-4212.014,51.17667,0,0,0,0,100,0),
(@PATH,13,-80.23439,-4214.764,51.17667,0,0,0,0,100,0),
(@PATH,14,-79.98439,-4217.514,51.92667,0,0,0,0,100,0),
(@PATH,15,-79.98439,-4218.764,52.42667,0,0,0,0,100,0),
(@PATH,16,-79.73439,-4221.014,53.17667,0,0,0,0,100,0),
(@PATH,17,-79.95529,-4221.4,53.16322,0,0,0,0,100,0),
(@PATH,18,-79.70529,-4223.9,53.16322,0,0,0,0,100,0),
(@PATH,19,-79.95529,-4225.65,53.16322,0,0,0,0,100,0),
(@PATH,20,-80.45529,-4228.15,53.41322,0,0,0,0,100,0),
(@PATH,21,-81.20529,-4231.15,53.66322,0,0,0,0,100,0),
(@PATH,22,-81.70529,-4233.4,53.66322,0,0,0,0,100,0),
(@PATH,23,-82.20529,-4236.4,53.41322,0,0,0,0,100,0),
(@PATH,24,-82.95529,-4240.4,53.16322,0,0,0,0,100,0),
(@PATH,25,-78.98962,-4213.033,51.07714,0,0,0,0,100,0),
(@PATH,26,-80.73962,-4215.033,51.07714,0,0,0,0,100,0),
(@PATH,27,-82.23962,-4216.533,51.07714,0,0,0,0,100,0),
(@PATH,28,-83.32472,-4240.692,53.09307,0,0,0,0,100,0),
(@PATH,29,-83.57472,-4241.942,52.84307,0,0,0,0,100,0),
(@PATH,30,-88.07472,-4244.942,51.84307,0,0,0,0,100,0),
(@PATH,31,-89.57472,-4245.942,51.84307,0,0,0,0,100,0),
(@PATH,32,-94.57472,-4249.442,52.09307,0,0,0,0,100,0),
(@PATH,33,-89.78734,-4247.307,51.866,0,0,0,0,100,0),
(@PATH,34,-94.49548,-4249.424,52.1338,0,0,0,0,100,0),
(@PATH,35,-89.49548,-4246.174,51.8838,0,0,0,0,100,0),
(@PATH,36,-88.24548,-4245.174,51.8838,0,0,0,0,100,0),
(@PATH,37,-83.99548,-4242.424,52.8838,0,0,0,0,100,0),
(@PATH,38,-83.67764,-4242.228,52.90353,0,0,0,0,100,0),
(@PATH,39,-83.17764,-4241.728,52.90353,0,0,0,0,100,0),
(@PATH,40,-82.92764,-4240.478,53.15353,0,0,0,0,100,0),
(@PATH,41,-82.42764,-4236.478,53.40353,0,0,0,0,100,0),
(@PATH,42,-81.67764,-4233.728,53.40353,0,0,0,0,100,0),
(@PATH,43,-81.17764,-4231.478,53.65353,0,0,0,0,100,0),
(@PATH,44,-80.42764,-4227.978,53.65353,0,0,0,0,100,0),
(@PATH,45,-79.92764,-4225.728,53.15353,0,0,0,0,100,0),
(@PATH,46,-80.0696,-4225.407,53.28567,0,0,0,0,100,0),
(@PATH,47,-79.5696,-4223.657,53.28567,0,0,0,0,100,0),
(@PATH,48,-79.8196,-4221.157,53.03567,0,0,0,0,100,0),
(@PATH,49,-80.0696,-4218.907,52.28567,0,0,0,0,100,0),
(@PATH,50,-80.0696,-4217.407,51.78567,0,0,0,0,100,0),
(@PATH,51,-80.3196,-4215.157,51.28567,0,0,0,0,100,0),
(@PATH,52,-80.3196,-4211.907,51.03567,0,0,0,0,100,0),
(@PATH,53,-80.5696,-4207.657,50.28567,0,0,0,0,100,0),
(@PATH,54,-80.8242,-4204.057,50.14382,0,0,0,0,100,0),
(@PATH,55,-83.0742,-4203.807,50.14382,0,0,0,0,100,0),
(@PATH,56,-86.5742,-4203.307,50.39382,0,0,0,0,100,0),
(@PATH,57,-88.5742,-4202.807,50.64382,0,0,0,0,100,0),
(@PATH,58,-94.0742,-4201.807,51.14382,0,0,0,0,100,0),
(@PATH,59,-96.38052,-4201.482,51.88694,0,0,0,0,100,0),
(@PATH,60,-101.1305,-4204.482,52.38694,0,0,0,0,100,0),
(@PATH,61,-104.8805,-4206.732,54.13694,0,0,0,0,100,0),
(@PATH,62,-106.3805,-4207.982,54.63694,0,0,0,0,100,0),
(@PATH,63,-110.251,-4210.546,55.33146,0,0,0,0,100,0),
(@PATH,64,-111.751,-4212.046,55.58146,0,0,0,0,100,0),
(@PATH,65,-115.001,-4215.796,55.08146,0,0,0,0,100,0),
(@PATH,66,-120.001,-4221.296,55.08146,0,0,0,0,100,0),
(@PATH,67,-122.751,-4224.296,54.83146,0,0,0,0,100,0),
(@PATH,68,-124.001,-4225.546,55.83146,0,0,0,0,100,0),
(@PATH,69,-126.001,-4227.796,56.08146,0,0,0,0,100,0),
(@PATH,70,-127.501,-4229.296,57.33146,0,0,0,0,100,0),
(@PATH,71,-91.31506,-4205.91,50.59808,0,0,0,0,100,0),
(@PATH,72,-91.81506,-4207.91,50.59808,0,0,0,0,100,0),
(@PATH,73,-91.81506,-4208.91,49.59808,0,0,0,0,100,0),
(@PATH,74,-126.1015,-4228.112,56.14558,0,0,0,0,100,0),
(@PATH,75,-127.6015,-4229.612,57.39558,0,0,0,0,100,0),
(@PATH,76,-127.8515,-4230.112,57.39558,0,0,0,0,100,0),
(@PATH,77,-129.8515,-4230.612,57.64558,0,0,0,0,100,0),
(@PATH,78,-134.1015,-4231.862,58.39558,0,0,0,0,100,0),
(@PATH,79,-138.3515,-4233.112,58.14558,0,0,0,0,100,0),
(@PATH,80,-140.2947,-4233.915,58.41685,0,0,0,0,100,0),
(@PATH,81,-142.5447,-4237.665,58.66685,0,0,0,0,100,0),
(@PATH,82,-144.0447,-4240.415,57.91685,0,0,0,0,100,0),
(@PATH,83,-144.7947,-4242.165,58.41685,0,0,0,0,100,0),
(@PATH,84,-145.2947,-4242.915,58.91685,0,0,0,0,100,0),
(@PATH,85,-148.2947,-4247.915,58.91685,0,0,0,0,100,0),
(@PATH,86,-125.7708,-4228.285,56.13358,0,0,0,0,100,0),
(@PATH,87,-126.7708,-4229.535,56.88358,0,0,0,0,100,0),
(@PATH,88,-128.7708,-4232.035,57.63358,0,0,0,0,100,0),
(@PATH,89,-130.0208,-4233.285,57.88358,0,0,0,0,100,0),
(@PATH,90,-150.7726,-4252,60.15183,0,0,0,0,100,0),
(@PATH,91,-151.0226,-4253.75,60.40183,0,0,0,0,100,0),
(@PATH,92,-151.2726,-4255,60.40183,0,0,0,0,100,0),
(@PATH,93,-151.7726,-4259,61.15183,0,0,0,0,100,0),
(@PATH,94,-152.0226,-4260.75,61.15183,0,0,0,0,100,0),
(@PATH,95,-152.2726,-4262,61.15183,0,0,0,0,100,0),
(@PATH,96,-152.3025,-4262.248,61.37363,0,0,0,0,100,0),
(@PATH,97,-152.5525,-4264.248,61.87363,0,0,0,0,100,0),
(@PATH,98,-151.0525,-4266.748,62.12363,0,0,0,0,100,0),
(@PATH,99,-149.0525,-4269.748,62.87363,0,0,0,0,100,0),
(@PATH,100,-146.3025,-4274.498,63.37363,0,0,0,0,100,0),
(@PATH,101,-146.5197,-4258.174,60.4844,0,0,0,0,100,0),
(@PATH,102,-147.0197,-4261.174,60.7344,0,0,0,0,100,0),
(@PATH,103,-147.5197,-4263.924,62.2344,0,0,0,0,100,0),
(@PATH,104,-147.7697,-4266.424,62.7344,0,0,0,0,100,0),
(@PATH,105,-148.5197,-4269.674,62.9844,0,0,0,0,100,0),
(@PATH,106,-146.4677,-4274.327,63.41321,0,0,0,0,100,0),
(@PATH,107,-149.2177,-4270.077,62.91321,0,0,0,0,100,0),
(@PATH,108,-150.9677,-4266.577,62.41321,0,0,0,0,100,0),
(@PATH,109,-152.4147,-4264.165,61.5908,0,0,0,0,100,0),
(@PATH,110,-152.1647,-4262.165,61.0908,0,0,0,0,100,0),
(@PATH,111,-151.9147,-4260.665,61.0908,0,0,0,0,100,0),
(@PATH,112,-151.6647,-4259.165,61.0908,0,0,0,0,100,0),
(@PATH,113,-151.1647,-4255.415,60.8408,0,0,0,0,100,0),
(@PATH,114,-151.1647,-4253.665,60.5908,0,0,0,0,100,0),
(@PATH,115,-150.8275,-4253.3,60.19576,0,0,0,0,100,0),
(@PATH,116,-150.5775,-4251.8,59.94576,0,0,0,0,100,0),
(@PATH,117,-148.3275,-4248.05,59.19576,0,0,0,0,100,0),
(@PATH,118,-145.8275,-4243.3,59.19576,0,0,0,0,100,0),
(@PATH,119,-145.0775,-4242.3,58.44576,0,0,0,0,100,0),
(@PATH,120,-144.0775,-4240.55,57.94576,0,0,0,0,100,0),
(@PATH,121,-142.3275,-4237.8,58.69576,0,0,0,0,100,0),
(@PATH,122,-140.118,-4234.043,58.1931,0,0,0,0,100,0),
(@PATH,123,-138.118,-4233.293,58.1931,0,0,0,0,100,0),
(@PATH,124,-134.368,-4232.293,58.4431,0,0,0,0,100,0),
(@PATH,125,-129.868,-4230.543,57.6931,0,0,0,0,100,0),
(@PATH,126,-129.5206,-4230.47,57.8318,0,0,0,0,100,0),
(@PATH,127,-127.7706,-4229.72,57.3318,0,0,0,0,100,0),
(@PATH,128,-126.0206,-4227.72,56.3318,0,0,0,0,100,0),
(@PATH,129,-124.0206,-4225.47,55.8318,0,0,0,0,100,0),
(@PATH,130,-123.0206,-4224.47,55.0818,0,0,0,0,100,0),
(@PATH,131,-120.2706,-4221.22,55.0818,0,0,0,0,100,0),
(@PATH,132,-115.7706,-4216.47,54.8318,0,0,0,0,100,0),
(@PATH,133,-111.7706,-4211.97,55.3318,0,0,0,0,100,0),
(@PATH,134,-111.5342,-4211.826,55.12441,0,0,0,0,100,0),
(@PATH,135,-110.2842,-4210.576,55.12441,0,0,0,0,100,0),
(@PATH,136,-106.2842,-4208.076,54.62441,0,0,0,0,100,0),
(@PATH,137,-104.7842,-4207.076,54.37441,0,0,0,0,100,0),
(@PATH,138,-101.0342,-4204.576,52.62441,0,0,0,0,100,0);

-- 
-- Den Cage SAI
SET @ENTRY := 202580;
UPDATE `gameobject_template` SET `AIName`="SmartGameObjectAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,1,0,0,70,0,100,0,2,0,0,0,45,1,1,0,0,0,0,19,39215,1,0,0,0,0,0,"Den Cage - On Gameobject State Changed - Set Data 1 1");

-- Captured Northwatch Scout SAI
SET @ENTRY := 39215;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,12000,20000,11,75356,0,0,0,0,0,2,0,0,0,0,0,0,0,"Captured Northwatch Scout - In Combat - Cast 'Fisticuffs'"),
(@ENTRY,0,1,2,38,0,100,0,1,1,0,0,19,256,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Northwatch Scout - On Data Set 1 1 - Remove Flag Immune To Players"),
(@ENTRY,0,2,0,61,0,100,0,1,1,0,0,49,0,0,0,0,0,0,21,10,0,0,0,0,0,0,"Captured Northwatch Scout - On Data Set 1 1 - Start Attacking");

-- DB/SAI: Update Durotar

-- 1.
-- Armored Scorpid SAI
SET @ENTRY := 3126;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,50,24000,26000,11,79840,0,0,0,0,0,1,0,0,0,0,0,0,0,"Armored Scorpid - Between 0-50% Health - Cast 'Harden'");

-- 2.
-- Bloodtalon Raptor SAI
SET @ENTRY := 37956;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,6268,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodtalon Raptor - On Aggro - Cast 'Rushing Charge' (No Repeat)");

-- 3.
-- Bloodtalon Scythemaw SAI
SET @ENTRY := 3123;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,6268,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodtalon Scythemaw - On Aggro - Cast 'Rushing Charge' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,3000,4500,24000,25000,11,13443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodtalon Scythemaw - In Combat - Cast 'Rend'");

-- 4.
-- Bloodtalon Taillasher SAI
SET @ENTRY := 3122;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,6268,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodtalon Taillasher - On Aggro - Cast 'Rushing Charge' (No Repeat)");

-- 5.
-- Burning Blade Apprentice SAI
SET @ENTRY := 3198;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,77721,64,0,0,0,0,2,0,0,0,0,0,0,0,"Burning Blade Apprentice - In Combat - Cast 'Shadow Weave'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Apprentice - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,1,0,100,1,3000,5000,0,0,11,12746,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Apprentice - Out of Combat - Cast 'Summon Voidwalker' (No Repeat)"),
(@ENTRY,0,3,0,0,0,100,0,6000,8000,60000,65000,11,80174,1,0,0,0,0,2,0,0,0,0,0,0,0,"Burning Blade Apprentice - In Combat - Cast 'Felblood'");

-- 6.
-- Burning Blade Cultist SAI
SET @ENTRY := 3199;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,79938,64,0,0,0,0,2,0,0,0,0,0,0,0,"Burning Blade Cultist - In Combat - Cast 'Incinerate'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Cultist - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,1,0,100,1,3000,5000,0,0,11,11939,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Cultist - Out of Combat - Cast 'Summon Imp' (No Repeat)"),
(@ENTRY,0,3,0,0,0,100,0,6000,8000,60000,65000,11,80174,1,0,0,0,0,2,0,0,0,0,0,0,0,"Burning Blade Cultist - In Combat - Cast 'Felblood'");

-- 7.
-- Burning Blade Fanatic SAI
SET @ENTRY := 3197;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,11000,16000,22000,11,5262,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Fanatic - In Combat - Cast 'Fanatic Blade'"),
(@ENTRY,0,1,0,0,0,100,0,6000,8000,60000,65000,11,80174,1,0,0,0,0,2,0,0,0,0,0,0,0,"Burning Blade Fanatic - In Combat - Cast 'Felblood'");

-- 8.
-- Burning Blade Neophyte SAI
SET @ENTRY := 3196;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,79932,64,0,0,0,0,2,0,0,0,0,0,0,0,"Burning Blade Neophyte - In Combat - Cast 'Shadow Bolt'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Neophyte - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,1,0,100,0,500,1000,600000,600000,11,79954,0,0,0,0,0,1,0,0,0,0,0,0,0,"Burning Blade Neophyte - Out of Combat - Cast 'Fel Armor'"),
(@ENTRY,0,3,0,0,0,100,0,6000,8000,60000,65000,11,80174,1,0,0,0,0,2,0,0,0,0,0,0,0,"Burning Blade Neophyte - In Combat - Cast 'Felblood'");

-- 9.
-- Burning Blade Thug SAI
SET @ENTRY := 3195;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,15000,18000,11,80146,0,0,0,0,0,2,0,0,0,0,0,0,0,"Burning Blade Thug - In Combat - Cast 'Bonk'"),
(@ENTRY,0,1,0,0,0,100,0,6000,8000,60000,65000,11,80174,1,0,0,0,0,2,0,0,0,0,0,0,0,"Burning Blade Thug - In Combat - Cast 'Felblood'"),
(@ENTRY,0,2,0,0,0,100,0,2000,4000,25000,26000,11,80182,1,0,0,0,0,2,0,0,0,0,0,0,0,"Burning Blade Thug - In Combat - Cast 'Uppercut'");

-- 10.
-- Captain Flat Tusk SAI
SET @ENTRY := 5824;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,5280,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Flat Tusk - On Respawn - Cast 'Razor Mane' (No Repeat)"),
(@ENTRY,0,1,0,9,0,100,0,0,5,7000,12000,11,77558,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Flat Tusk - Within 0-5 Range - Cast 'Bloody Strike'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Flat Tusk - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,3,0,4,0,100,1,0,0,0,0,11,79733,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Flat Tusk - On Aggro - Cast 'Commanding Shout' (No Repeat)");

-- 12.
-- Clattering Scorpid SAI
SET @ENTRY := 3125;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,4500,32000,38000,11,79687,0,0,0,0,0,2,0,0,0,0,0,0,0,"Clattering Scorpid - In Combat - Cast 'Sundering Cleave'"),
(@ENTRY,0,1,0,0,0,100,0,2000,9000,15000,24000,11,73672,0,0,0,0,0,2,0,0,0,0,0,0,0,"Clattering Scorpid - In Combat - Cast 'Envenom'");

-- 13.
-- Corrupted Bloodtalon SAI
SET @ENTRY := 37961;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,6268,0,0,0,0,0,1,0,0,0,0,0,0,0,"Corrupted Bloodtalon - On Aggro - Cast 'Rushing Charge' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,2000,4500,25000,26000,11,79774,0,0,0,0,0,2,0,0,0,0,0,0,0,"Corrupted Bloodtalon - In Combat - Cast 'Corrupted'");

-- 14.
-- Darkspear Shaman SAI
SET @ENTRY := 38326;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,73212,64,0,0,0,0,2,0,0,0,0,0,0,0,"Darkspear Shaman - In Combat - Cast 'Lightning Bolt'");

-- 15.
-- Darkspear Watcher SAI
SET @ENTRY := 38217;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,95826,64,0,0,0,0,2,0,0,0,0,0,0,0,"Darkspear Watcher - In Combat - Cast 'Shoot'");

-- 16.
-- Death Flayer SAI
SET @ENTRY := 5823;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,50,24000,26000,11,79840,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death Flayer - Between 0-50% Health - Cast 'Harden'"),
(@ENTRY,0,1,0,0,0,100,0,3500,4500,15000,24000,11,79607,0,0,0,0,0,2,0,0,0,0,0,0,0,"Death Flayer - In Combat - Cast 'Venom Splash'");

-- 17.
-- Den Grunt SAI
SET @ENTRY := 5952;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,95826,64,0,0,0,0,2,0,0,0,0,0,0,0,"Den Grunt - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Den Grunt - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Den Grunt - Between 0-30% Health - Say Line 0 (No Repeat)");

-- NPC talk text insert
SET @ENTRY := 5952;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage',10677);

-- 18.
-- Dire Mottled Boar SAI
SET @ENTRY := 3099;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,6268,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dire Mottled Boar - On Aggro - Cast 'Rushing Charge' (No Repeat)");

-- 19.
-- Dreadmaw Crocolisk SAI
SET @ENTRY := 3110;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,12000,16000,11,12166,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dreadmaw Crocolisk - Within 0-5 Range - Cast 'Muscle Tear'");

-- 20.
-- Dreadmaw Toothgnasher SAI
SET @ENTRY := 39452;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,12000,16000,11,12166,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dreadmaw Toothgnasher - Within 0-5 Range - Cast 'Muscle Tear'");

-- 21.
-- Drowned Thunder Lizard SAI
SET @ENTRY := 39464;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,7000,22000,25000,11,73958,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drowned Thunder Lizard - In Combat - Cast 'Lightning Discharge'");

-- 22.
-- Dustwind Harpy SAI
SET @ENTRY := 3115;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dustwind Harpy - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,4000,5000,12000,19000,11,77522,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dustwind Harpy - In Combat - Cast 'Swoop'"),
(@ENTRY,0,2,0,2,0,100,0,0,50,13000,24000,11,80215,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dustwind Harpy - Between 0-50% Health - Cast 'Dustwind'");

-- 23.
-- Dustwind Pillager SAI
SET @ENTRY := 3116;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dustwind Pillager - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,5000,11000,18000,24000,11,3147,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dustwind Pillager - In Combat - Cast 'Rend Flesh'"),
(@ENTRY,0,2,0,2,0,100,0,0,50,13000,24000,11,80215,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dustwind Pillager - Between 0-50% Health - Cast 'Dustwind'");

-- 24.
-- Dustwind Savage SAI
SET @ENTRY := 3117;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dustwind Savage - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,5000,5000,18000,22000,11,75930,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dustwind Savage - In Combat - Cast 'Mangle'"),
(@ENTRY,0,2,0,2,0,100,0,0,50,13000,24000,11,80215,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dustwind Savage - Between 0-50% Health - Cast 'Dustwind'");

-- 25.
-- Dustwind Storm Witch SAI
SET @ENTRY := 3118;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,77160,64,0,0,0,0,2,0,0,0,0,0,0,0,"Dustwind Storm Witch - In Combat - Cast 'Nimbus Bolt'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dustwind Storm Witch - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,2,0,100,0,0,50,13000,24000,11,80215,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dustwind Storm Witch - Between 0-50% Health - Cast 'Dustwind'"),
(@ENTRY,0,3,0,0,0,100,0,7000,9000,24000,26000,11,12058,0,0,0,0,0,4,0,0,0,0,0,0,0,"Dustwind Storm Witch - In Combat - Cast 'Chain Lightning'");

-- 26.
-- Elder Mottled Boar SAI
SET @ENTRY := 3100;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,3385,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Mottled Boar - On Aggro - Cast 'Boar Charge' (No Repeat)");

-- 27.
-- Encrusted Surf Crawler SAI
SET @ENTRY := 3108;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,50,24000,26000,11,79840,0,0,0,0,0,1,0,0,0,0,0,0,0,"Encrusted Surf Crawler - Between 0-50% Health - Cast 'Harden'");

-- 28.
-- Felstalker SAI
SET @ENTRY := 3102;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,40,18000,24000,11,79616,0,0,0,0,0,2,1,0,0,0,0,0,0,"Felstalker - Between 0-40% Health - Cast 'Drain Life'");

-- 29.
-- Felweaver Scornn SAI
SET @ENTRY := 5822;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,3000,5000,0,0,11,30842,0,0,0,0,0,1,0,0,0,0,0,0,0,"Felweaver Scornn - Out of Combat - Cast 'Summon Felhunter' (No Repeat)"),
(@ENTRY,0,1,0,1,0,100,0,500,1000,600000,600000,11,79934,0,0,0,0,0,1,0,0,0,0,0,0,0,"Felweaver Scornn - Out of Combat - Cast 'Demon Armor'"),
(@ENTRY,0,2,0,2,0,100,0,0,40,16000,23000,11,79933,0,0,0,0,0,2,1,0,0,0,0,0,0,"Felweaver Scornn - Between 0-40% Health - Cast 'Drain Life'");

-- 30.
-- Foaming Sea Elemental SAI
SET @ENTRY := 39272;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,12000,15000,11,32011,0,0,0,0,0,2,0,0,0,0,0,0,0,"Foaming Sea Elemental - In Combat - Cast 'Water Bolt'"),
(@ENTRY,0,1,0,0,0,100,0,7000,9000,24000,27000,11,79831,0,0,0,0,0,2,0,0,0,0,0,0,0,"Foaming Sea Elemental - In Combat - Cast 'Wave Crash'");

-- 31.
-- Furious Earthguard SAI
SET @ENTRY := 39595;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,6000,16000,18000,11,80117,0,0,0,0,0,2,0,0,0,0,0,0,0,"Furious Earthguard - In Combat - Cast 'Earth Spike'");

-- 32.
-- Gaur Icehorn SAI
SET @ENTRY := 39352;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,76423,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gaur Icehorn - Between 0-30% Health - Cast 'Taunka Rage' (No Repeat)"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gaur Icehorn - Between 0-30% Health - Say Line 0 (No Repeat)");

-- NPC talk text insert
SET @ENTRY := 39352;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Taunka Rage',10677);

-- 33.
-- Gazz'uz SAI
SET @ENTRY := 3204;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,20791,64,0,0,0,0,2,0,0,0,0,0,0,0,"Gazz'uz - In Combat - Cast 'Shadow Bolt'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gazz'uz - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,1,0,100,0,500,1000,600000,600000,11,20798,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gazz'uz - Out of Combat - Cast 'Demon Skin'"),
(@ENTRY,0,3,0,0,0,100,0,12000,18000,25000,35000,11,172,0,0,0,0,0,4,0,0,0,0,0,0,0,"Gazz'uz - In Combat - Cast 'Corruption'");

-- 34.
-- Geolord Mottle SAI
SET @ENTRY := 5826;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,6000,16000,18000,11,80117,0,0,0,0,0,2,0,0,0,0,0,0,0,"Geolord Mottle - In Combat - Cast 'Earth Spike'"),
(@ENTRY,0,1,0,1,0,100,0,500,1000,600000,600000,11,79927,0,0,0,0,0,1,0,0,0,0,0,0,0,"Geolord Mottle - Out of Combat - Cast 'Earth Shield'");

-- 35.
-- Ghislania SAI
SET @ENTRY := 39351;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,76429,64,0,0,0,0,2,0,0,0,0,0,0,0,"Ghislania - In Combat - Cast 'Static Burst'"),
(@ENTRY,0,1,0,0,0,100,0,5000,5000,19000,21000,11,79913,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ghislania - In Combat - Cast 'Chain Lightning'");

-- 36.
-- Griswold Hanniston SAI
SET @ENTRY := 39353;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Griswold Hanniston - On Aggro - Say Line 0 (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,22000,26000,11,76490,0,0,0,0,0,1,0,0,0,0,0,0,0,"Griswold Hanniston - In Combat - Cast 'Flurry of Claws'");

-- NPC talk text insert
SET @ENTRY := 39353;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'What''s the matter, chum... never seen a worgen before?',12,0,100,0,0,0, 'on Aggro Text',39521);

-- 37.
-- Kor'kron Deathbringer SAI
SET @ENTRY := 42946;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,77808,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kor'kron Deathbringer - On Aggro - Cast 'Battle Shout' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,4500,6500,15400,19200,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kor'kron Deathbringer - In Combat - Cast 'Cleave'");

-- 38.
-- Mature Surf Crawler SAI
SET @ENTRY := 3107;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5000,17000,22000,11,78744,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mature Surf Crawler - In Combat - Cast 'Bubblebeam'");

-- 39.
-- Mottled Boar SAI
SET @ENTRY := 3098;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,12000,15000,11,79581,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mottled Boar - In Combat - Cast 'Angry Snort'");

-- 40.
-- Naj'tess SAI
SET @ENTRY := 39072;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,24000,32000,11,79782,0,0,0,0,0,2,0,0,0,0,0,0,0,"Naj'tess - In Combat - Cast 'Orb of Corruption'"),
(@ENTRY,0,1,0,0,0,100,0,2000,4000,34000,38000,11,73424,0,0,0,0,0,2,0,0,0,0,0,0,0,"Naj'tess - In Combat - Cast 'Shrink'");

-- 41.
-- Northwatch Infantryman SAI
SET @ENTRY := 39260;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,40,14000,15000,11,78826,0,0,0,0,0,1,0,0,0,0,0,0,0,"Northwatch Infantryman - Between 0-40% Health - Cast 'Evasion'"),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,11,78894,0,0,0,0,0,2,0,0,0,0,0,0,0,"Northwatch Infantryman - On Aggro - Cast 'Leaping Cleave' (No Repeat)");

-- 42.
-- Northwatch Lug SAI
SET @ENTRY := 39245;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,14000,17000,11,75356,0,0,0,0,0,2,0,0,0,0,0,0,0,"Northwatch Lug - In Combat - Cast 'Fisticuffs'");

-- 43.
-- Northwatch Lug SAI
SET @ENTRY := 39249;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,14000,17000,11,75356,0,0,0,0,0,2,0,0,0,0,0,0,0,"Northwatch Lug - In Combat - Cast 'Fisticuffs'");

-- 44.
-- Northwatch Marine SAI
SET @ENTRY := 39267;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3000,18000,19000,11,9080,0,0,0,0,0,2,0,0,0,0,0,0,0,"Northwatch Marine - In Combat - Cast 'Hamstring'"),
(@ENTRY,0,1,0,0,0,100,0,7000,9000,22000,27000,11,79726,0,0,0,0,0,2,0,0,0,0,0,0,0,"Northwatch Marine - In Combat - Cast 'Ticking Time Bomb'");

-- 45.
-- Ticking Time Bomb SAI
SET @ENTRY := 42776;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,11,0,100,1,0,0,0,0,11,79728,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ticking Time Bomb - On Respawn - Cast 'Explosion' (No Repeat)"),
(@ENTRY,0,1,0,61,0,100,1,0,0,0,0,41,3000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ticking Time Bomb - On Respawn - Despawn In 3000 ms (No Repeat)");

-- 46.
-- Northwatch Ranger SAI
SET @ENTRY := 39261;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Northwatch Ranger - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,5,9,0,100,0,5,30,15000,18000,11,78754,1,0,0,0,0,2,0,0,0,0,0,0,0,"Northwatch Ranger - Within 5-30 Range - Cast 'Arcane Shot'"),
(@ENTRY,0,2,5,9,0,100,0,0,10,60000,65000,11,78578,1,0,0,0,0,1,0,0,0,0,0,0,0,"Northwatch Ranger - Within 0-10 Range - Cast 'Immolation Trap'");

-- 47.
-- Northwatch Scout SAI
SET @ENTRY := 39317;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Northwatch Scout - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,11,0,100,1,0,0,0,0,11,58506,0,0,0,0,0,1,0,0,0,0,0,0,0,"Northwatch Scout - On Respawn - Cast 'Stealth' (No Repeat)"),
(@ENTRY,0,2,0,7,0,100,1,0,0,0,0,11,58506,0,0,0,0,0,1,0,0,0,0,0,0,0,"Northwatch Scout - On Evade - Cast 'Stealth' (No Repeat)"),
(@ENTRY,0,3,5,9,0,100,0,0,10,15000,22000,11,79584,0,0,0,0,0,1,0,0,0,0,0,0,0,"Northwatch Scout - Within 0-10 Range - Cast 'Fan of Knives'");

-- 48.
-- Northwatch Sharpshooter SAI
SET @ENTRY := 39268;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Northwatch Sharpshooter - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,5,9,0,100,0,5,30,18000,21000,11,79721,1,0,0,0,0,2,0,0,0,0,0,0,0,"Northwatch Sharpshooter - Within 5-30 Range - Cast 'Explosive Shot'"),
(@ENTRY,0,2,5,9,0,100,0,5,30,35000,45000,11,79719,1,0,0,0,0,2,0,0,0,0,0,0,0,"Northwatch Sharpshooter - Within 5-30 Range - Cast 'Pinpoint'");

-- 49.
-- Pygmy Surf Crawler SAI
SET @ENTRY := 39004;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,15000,19000,11,79765,0,0,0,0,0,2,0,0,0,0,0,0,0,"Pygmy Surf Crawler - In Combat - Cast 'Bubble Blast'");

-- 50.
-- Raider Jhash SAI
SET @ENTRY := 10676;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Raider Jhash - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,1,0,9,0,100,0,0,20,7000,9000,11,6533,0,0,0,0,0,2,0,0,0,0,0,0,0,"Raider Jhash - Within 0-20 Range - Cast 'Net'");

-- 51.
-- Razor Hill Grunt SAI
SET @ENTRY := 5953;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,95826,64,0,0,0,0,2,0,0,0,0,0,0,0,"Razor Hill Grunt - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razor Hill Grunt - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razor Hill Grunt - Between 0-30% Health - Say Line 0 (No Repeat)"),
(@ENTRY,0,3,5,9,0,100,0,0,5,14000,19000,11,40505,0,0,0,0,0,2,0,0,0,0,0,0,0,"Razor Hill Grunt - Within 0-5 Range - Cast 'Cleave'");

-- NPC talk text insert
SET @ENTRY := 5953;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage',10677);

-- 52.
-- Razormane Battleguard SAI
SET @ENTRY := 3114;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,32064,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Battleguard - On Aggro - Cast 'Battle Shout' (No Repeat)"),
(@ENTRY,0,1,0,1,0,100,0,500,1000,300000,300000,11,5280,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Battleguard - Out of Combat - Cast 'Razor Mane'"),
(@ENTRY,0,2,0,0,0,100,0,4000,6000,25000,31000,11,77558,0,0,0,0,0,2,0,0,0,0,0,0,0,"Razormane Battleguard - In Combat - Cast 'Bloody Strike'"),
(@ENTRY,0,3,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Battleguard - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,4,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Battleguard - Between 0-30% Health - Say Line 0 (No Repeat)");

-- NPC talk text insert
SET @ENTRY := 3114;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage',10677);

-- 53.
-- Razormane Dustrunner SAI
SET @ENTRY := 3113;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9739,64,0,0,0,0,2,0,0,0,0,0,0,0,"Razormane Dustrunner - In Combat - Cast 'Wrath'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Dustrunner - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,1,0,100,0,500,1000,300000,300000,11,5280,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Dustrunner - Out of Combat - Cast 'Razor Mane'"),
(@ENTRY,0,3,0,0,0,100,0,6000,8000,27000,33000,11,6950,1,0,0,0,0,2,0,0,0,0,0,0,0,"Razormane Dustrunner - In Combat - Cast 'Faerie Fire'");

-- 54.
-- Razormane Quilboar SAI
SET @ENTRY := 3111;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,4500,17000,24500,11,80146,0,0,0,0,0,2,0,0,0,0,0,0,0,"Razormane Quilboar - In Combat - Cast 'Bonk'"),
(@ENTRY,0,1,0,1,0,100,0,500,1000,300000,300000,11,5280,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Quilboar - Out of Combat - Cast 'Razor Mane'");

-- 55.
-- Razormane Scout SAI
SET @ENTRY := 3112;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,80149,0,0,0,0,0,2,0,0,0,0,0,0,0,"Razormane Scout - On Aggro - Cast 'Throw Axe' (No Repeat)"),
(@ENTRY,0,1,0,1,0,100,0,500,1000,300000,300000,11,5280,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Scout - Out of Combat - Cast 'Razor Mane'");

-- 56.
-- Sarkoth SAI
SET @ENTRY := 3281;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,6000,18000,25000,11,79607,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sarkoth - In Combat - Cast 'Venom Splash'");

-- 57.
-- Scorpid Worker SAI
SET @ENTRY := 3124;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,4000,18500,24900,11,6751,32,0,0,0,0,2,0,0,0,0,0,0,0,"Scorpid Worker - In Combat - Cast 'Weak Poison'");

-- 58.
-- Screamslash SAI
SET @ENTRY := 39385;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,6268,0,0,0,0,0,1,0,0,0,0,0,0,0,"Screamslash - On Aggro - Cast 'Rushing Charge' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,24000,26000,11,13443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Screamslash - In Combat - Cast 'Rend'");

-- 59.
-- Sen'jin Watcher SAI
SET @ENTRY := 3297;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,95826,64,0,0,0,0,2,0,0,0,0,0,0,0,"Sen'jin Watcher - In Combat - Cast 'Shoot'");

-- 60.
-- Sergeant Curtis SAI
SET @ENTRY := 5809;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,78894,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sergeant Curtis - On Aggro - Cast 'Leaping Cleave' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,7000,9000,22000,27000,11,79726,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sergeant Curtis - In Combat - Cast 'Ticking Time Bomb'");

-- 61.
-- Spitescale Siren SAI
SET @ENTRY := 38301;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,32011,64,0,0,0,0,2,0,0,0,0,0,0,0,"Spitescale Siren - In Combat - Cast 'Water Bolt'"),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,22000,24000,11,15117,1,0,0,0,0,4,0,0,0,0,0,0,0,"Spitescale Siren - In Combat - Cast 'Chain Lightning'");

-- 62.
-- Spitescale Wavethrasher SAI
SET @ENTRY := 38300;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5000,17000,23000,11,79810,0,0,0,0,0,2,0,0,0,0,0,0,0,"Spitescale Wavethrasher - In Combat - Cast 'Frost Cleave'");

-- 63.
-- Surf Crawler SAI
SET @ENTRY := 3106;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5000,17000,22000,11,78744,0,0,0,0,0,2,0,0,0,0,0,0,0,"Surf Crawler - In Combat - Cast 'Bubblebeam'");

-- 64.
-- Swollen Voidwalker SAI
SET @ENTRY := 39603;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,8000,19000,25000,11,80132,0,0,0,0,0,2,0,0,0,0,0,0,0,"Swollen Voidwalker - In Combat - Cast 'Unbound Darkness'");

-- 65.
-- Teeming Waterguard SAI
SET @ENTRY := 39596;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,6000,24000,26000,11,78542,0,0,0,0,0,1,0,0,0,0,0,0,0,"Teeming Waterguard - In Combat - Cast 'Splash'");

-- 66.
-- Venomtail Scorpid SAI
SET @ENTRY := 3127;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3500,4500,15000,24000,11,79607,0,0,0,0,0,2,0,0,0,0,0,0,0,"Venomtail Scorpid - In Combat - Cast 'Venom Splash'");

-- 67.
-- Vile Familiar SAI
SET @ENTRY := 3101;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,11921,64,0,0,0,0,2,0,0,0,0,0,0,0,"Vile Familiar - In Combat - Cast 'Fireball'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vile Familiar - Between 0-15% Health - Flee For Assist (No Repeat)");

-- 68.
-- Wayward Plainstrider SAI
SET @ENTRY := 39337;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,6268,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wayward Plainstrider - On Aggro - Cast 'Rushing Charge' (No Repeat)"),
(@ENTRY,0,1,0,1,0,100,1,2000,3000,0,0,11,73757,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wayward Plainstrider - Out of Combat - Cast 'Water Walk' (No Repeat)");

-- 69.
-- Wildmane Cat SAI
SET @ENTRY := 38046;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,75002,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wildmane Cat - On Aggro - Cast 'Leaping Rush' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,4000,4500,18000,22000,11,31279,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wildmane Cat - In Combat - Cast 'Swipe'"),
(@ENTRY,0,2,0,1,0,30,0,45000,55000,120000,300000,11,71232,0,0,0,0,0,9,38141,8,25,0,0,0,0,"Wildmane Cat - Out of Combat - Cast 'Wild Pounce'");

-- 70.
-- Yarrog Baneshadow SAI
SET @ENTRY := 3183;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,35913,64,0,0,0,0,2,0,0,0,0,0,0,0,"Yarrog Baneshadow - In Combat - Cast 'Fel Fireball'"),
(@ENTRY,0,1,0,1,0,100,1,1000,1000,1000,1000,11,51733,2,0,0,0,0,1,0,0,0,0,0,0,0,"Yarrog Baneshadow - Out of Combat - Cast 'Shadow Channelling' (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,8000,12000,22000,29000,11,37628,0,0,0,0,0,2,0,0,0,0,0,0,0,"Yarrog Baneshadow - In Combat - Cast 'Fel Immolate'");

-- 71.
-- Docile Island Boar SAI
SET @ENTRY := 38141;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,0,71232,0,1000,2000,37,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Docile Island Boar - On Spellhit 'Wild Pounce' - Kill Self"),
(@ENTRY,0,1,0,61,0,100,0,71232,0,1000,2000,41,2000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Docile Island Boar - On Spellhit 'Wild Pounce' - Despawn In 2000 ms");

