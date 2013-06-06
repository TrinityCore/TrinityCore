-- The Mechanar Paths

-- Pathing for Sunseeker Engineer Entry: 20988
SET @NPC := 83213;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=215.6366,`position_y`=-57.85087,`position_z`=0.007587247 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,221.9379,-55.45426,0.008690897,0,0,0,100,0),
(@PATH,2,229.2718,-57.64629,0.009516931,0,0,0,100,0),
(@PATH,3,221.9379,-55.45426,0.008690897,0,0,0,100,0),
(@PATH,4,215.6366,-57.85087,0.007587247,0,0,0,100,0),
(@PATH,5,212.2958,-63.3326,0.007473905,0,0,0,100,0),
(@PATH,6,215.6366,-57.85087,0.007587247,0,0,0,100,0);

-- Pathing for Sunseeker Engineer Entry: 20988
SET @NPC := 83180;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=112.0698,`position_y`=40.35622,`position_z`=14.92426 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,101.2307,46.33547,14.9244,0,0,0,100,0),
(@PATH,2,102.2309,58.49025,14.93429,0,0,0,100,0),
(@PATH,3,110.5797,69.03175,14.91828,1000,0,0,100,0),
(@PATH,4,102.2309,58.49025,14.93429,0,0,0,100,0),
(@PATH,5,101.2307,46.33547,14.9244,0,0,0,100,0),
(@PATH,6,112.0698,40.35622,14.92426,2000,0,0,100,0);

-- Pathing for Sunseeker Engineer Entry: 20988
SET @NPC := 83224;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=103.1169,`position_y`=-38.39568,`position_z`=14.92465 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,115.3089,-32.14138,14.91936,0,0,0,100,0),
(@PATH,2,103.1169,-38.39568,14.92465,0,0,0,100,0),
(@PATH,3,100.0206,-48.74694,14.92466,0,0,0,100,0),
(@PATH,4,104.0157,-60.55514,14.92467,0,0,0,100,0),
(@PATH,5,101.5114,-74.89877,14.93021,1000,0,0,100,0),
(@PATH,6,104.0157,-60.55514,14.92467,0,0,0,100,0),
(@PATH,7,100.0206,-48.74694,14.92466,0,0,0,100,0),
(@PATH,8,103.1169,-38.39568,14.92465,0,0,0,100,0);

-- Pathing for Mechanar Tinkerer Entry: 19716
SET @NPC := 83168;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=173.9945,`position_y`=37.73192,`position_z`=1.01045 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,179.0216,40.52939,-0.006131659,0,0,0,100,0),
(@PATH,2,185.691,41.82604,-0.006107603,0,0,0,100,0),
(@PATH,3,193.5586,41.26056,-0.00603374,0,0,0,100,0),
(@PATH,4,197.7065,37.41517,-0.005917786,0,0,0,100,0),
(@PATH,5,193.5586,41.26056,-0.00603374,0,0,0,100,0),
(@PATH,6,185.691,41.82604,-0.006107603,0,0,0,100,0),
(@PATH,7,179.0216,40.52939,-0.006131659,0,0,0,100,0),
(@PATH,8,173.9945,37.73192,1.01045,1000,0,0,100,0);

-- Pathing for Mechanar Tinkerer Entry: 19716
SET @NPC := 83208;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=201.0571,`position_y`=-94.47349,`position_z`=0.005551513 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,200.5827,-87.17133,0.005753752,0,0,0,100,0),
(@PATH,2,208.2485,-83.39652,0.005116368,0,0,0,100,0),
(@PATH,3,213.2274,-75.13932,0.004827803,0,0,0,100,0),
(@PATH,4,208.2485,-83.39652,0.005116368,0,0,0,100,0),
(@PATH,5,200.5827,-87.17133,0.005753752,0,0,0,100,0),
(@PATH,6,201.0571,-94.47349,0.005551513,0,0,0,100,0),
(@PATH,7,211.3469,-101.7175,0.005551513,0,0,0,100,0),
(@PATH,8,221.7694,-105.0224,0.000142399,0,0,0,100,0),
(@PATH,9,211.3469,-101.7175,0.005551513,0,0,0,100,0),
(@PATH,10,201.0571,-94.47349,0.00555151,0,0,0,100,0);

-- Pathing for Gatewatcher Iron-Hand Entry: 19710
SET @NPC := 83240;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=167.8726,`position_y`=-78.7667,`position_z`=1.007633 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,181.8516,-77.11685,0.007727642,0,0,0,100,0),
(@PATH,2,193.6146,-39.96439,0.002376378,0,0,0,100,0),
(@PATH,3,189.3122,-44.15557,0,0,0,0,100,0),
(@PATH,4,193.6146,-39.96439,0.002376378,0,0,0,100,0),
(@PATH,5,181.8516,-77.11685,0.007727642,0,0,0,100,0),
(@PATH,6,167.8726,-78.7667,1.007633,0,0,0,100,0),
(@PATH,7,120.1477,-74.05254,14.92782,0,0,0,100,0),
(@PATH,8,167.8726,-78.7667,1.007633,0,0,0,100,0);

-- Pathing for Tempest-Forge Patroller Entry: 19166
SET @NPC := 83229;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=73.91813,`position_y`=-56.71242,`position_z`=14.92467 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,38.8435,-56.28604,0.2243272,0,0,0,100,0),
(@PATH,2,30.62484,-54.90739,0.2658595,0,0,0,100,0),
(@PATH,3,31.93092,-34.87634,0.01095478,0,0,0,100,0),
(@PATH,4,30.62484,-54.90739,0.2658595,0,0,0,100,0),
(@PATH,5,38.8435,-56.28604,0.2243272,0,0,0,100,0),
(@PATH,6,73.91813,-56.71242,14.92467,0,0,0,100,0);

-- Pathing for Tempest-Forge Patroller Entry: 19166
SET @NPC := 83189;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=38.19203,`position_y`=59.68785,`position_z`=0.1630622 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,30.01177,55.23014,0.1630622,0,0,0,100,0),
(@PATH,2,32.04149,39.38673,0.01430552,0,0,0,100,0),
(@PATH,3,30.01177,55.23014,0.1630622,0,0,0,100,0),
(@PATH,4,38.19203,59.68785,0.1630622,0,0,0,100,0),
(@PATH,5,72.142265,59.692062,14.924672,0,0,0,100,0),
(@PATH,6,76.85091,59.6219,14.92467,0,0,0,100,0),
(@PATH,7,72.142265,59.692062,14.924672,0,0,0,100,0),
(@PATH,8,38.19203,59.68785,0.1630622,0,0,0,100,0);

-- Pathing for Tempest-Forge Patroller Entry: 19166
SET @NPC := 83177;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=149.6304,`position_y`=81.24523,`position_z`=6.46902 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,169.9373,81.2677,0.3694459,0,0,0,100,0),
(@PATH,2,188.186,64.12248,-0.005838666,0,0,0,100,0),
(@PATH,3,186.6127,47.3467,-0.006220245,0,0,0,100,0),
(@PATH,4,164.6416,49.95449,-0.001837493,0,0,0,100,0),
(@PATH,5,186.6127,47.3467,-0.006220245,0,0,0,100,0),
(@PATH,6,188.186,64.12248,-0.005838666,0,0,0,100,0),
(@PATH,7,169.9373,81.2677,0.3694459,0,0,0,100,0),
(@PATH,8,149.6304,81.24523,6.46902,0,0,0,100,0),
(@PATH,9,117.6222,78.36094,14.92448,0,0,0,100,0),
(@PATH,10,149.6304,81.24523,6.46902,0,0,0,100,0);

-- Pathing for Tempest-Forge Patroller Entry: 19166
SET @NPC := 83197;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=43.61107,`position_y`=-26.75192,`position_z`=0.006033891 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,35.5806,-23.74641,-0.0007913045,0,0,0,100,0),
(@PATH,2,28.9233,-18.14311,-0.0005735573,0,0,0,100,0),
(@PATH,3,26.3567,-5.986794,-0.0003807611,9000,0,8319701,100,0),
(@PATH,4,29.69342,-15.44835,-0.0005828599,0,0,0,100,0),
(@PATH,5,35.8448,-23.9074,-0.000488915,0,0,0,100,0),
(@PATH,6,43.61107,-26.75192,0.006033891,15000,0,8319702,100,0);

-- Pathing for Tempest-Forge Patroller Entry: 19166
SET @NPC := 83195;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=41.32706,`position_y`=29.44866,`position_z`=0.006104112 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,32.22061,26.5157,0.007136924,0,0,0,100,0),
(@PATH,2,27.24365,18.83135,-0.0004997473,0,0,0,100,0),
(@PATH,3,24.29777,7.923412,-0.000286215,11000,0,8319501,100,0),
(@PATH,4,28.08634,21.93921,-0.0005085135,0,0,0,100,0),
(@PATH,5,41.32706,29.44866,0.006104112,13000,0,8319502,100,0);

DELETE FROM `waypoint_scripts` WHERE `guid` BETWEEN 817 AND 820;
INSERT INTO `waypoint_scripts` (`id`,`delay`,`command`,`datalong`,`datalong2`,`o`,`guid`) VALUES
(8319701,0,30,0,0,3.333579,817),
(8319702,0,30,0,0,3.036873,818),
(8319501,0,30,0,0,2.96706,819),
(8319502,0,30,0,0,3.263766,820);

-- Pathing for Tempest-Forge Destroyer Entry: 19735
SET @NPC := 83173;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=233.3129,`position_y`=52.31844,`position_z`=0.02142466 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,203.6965,53.04169,-0.004259702,0,0,0,100,0),
(@PATH,2,233.3129,52.31844,0.02142466,0,0,0,100,0);

-- Pathing for Mechano-Lord Capacitus Entry: 19219
SET @NPC := 83160;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=209.7744,`position_y`=-12.69758,`position_z`=-2.192125 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,209.7744,-12.69758,-2.192125,2000,0,8316001,100,0),
(@PATH,2,228.1113,-0.829701,-0.8854336,0,0,0,100,0),
(@PATH,3,226.6032,19.45208,-1.726556,0,0,0,100,0),
(@PATH,4,204.9646,26.38312,-0.005853632,10000,0,0,100,0),
(@PATH,5,209.7744,-12.69758,-2.192125,2000,0,8316001,100,0),
(@PATH,6,228.1113,-0.829701,-0.8854336,0,0,0,100,0),
(@PATH,7,226.6032,19.45208,-1.726556,0,0,0,100,0),
(@PATH,8,204.9646,26.38312,-0.005853632,10000,0,0,100,0),
(@PATH,9,209.7744,-12.69758,-2.192125,2000,0,8316001,100,0),
(@PATH,10,224.3664,-23.35326,-2.192125,0,0,0,100,0),
(@PATH,11,231.1084,-38.22675,8.909556,14000,0,0,100,0),
(@PATH,12,209.7744,-12.69758,-2.192125,2000,0,8316001,100,0),
(@PATH,13,224.3664,-23.35326,-2.192125,0,0,0,100,0),
(@PATH,14,231.1084,-38.22675,8.909556,13000,0,0,100,0),
(@PATH,15,209.7744,-12.69758,-2.192125,2000,0,8316001,100,0),
(@PATH,16,189.2316,-17.36449,-2.192126,0,0,0,100,0),
(@PATH,17,185.7177,-4.297129,-1.142366,0,0,0,100,0),
(@PATH,18,191.9589,6.435908,-0.7838742,0,0,0,100,0),
(@PATH,19,196.1359,21.01234,-1.426585,0,0,0,100,0),
(@PATH,20,207.8954,18.24695,-2.192125,0,0,0,100,0),
(@PATH,21,213.9077,10.01895,-2.192125,8000,0,0,100,0),
(@PATH,22,209.7744,-12.69758,-2.192125,2000,0,8316001,100,0),
(@PATH,23,189.2316,-17.36449,-2.192126,0,0,0,100,0),
(@PATH,24,191.9589,6.435908,-0.7838742,0,0,0,100,0),
(@PATH,25,196.1359,21.01234,-1.426585,0,0,0,100,0),
(@PATH,26,207.8954,18.24695,-2.192125,0,0,0,100,0),
(@PATH,27,213.9077,10.01895,-2.192125,14000,0,0,100,0),
(@PATH,28,209.7744,-12.69758,-2.192125,2000,0,8316001,100,0),
(@PATH,29,224.3664,-23.35326,-2.192125,0,0,0,100,0),
(@PATH,30,231.1084,-38.22675,8.909556,14000,0,0,100,0),
(@PATH,31,209.7744,-12.69758,-2.192125,2000,0,8316001,100,0);
DELETE FROM `waypoint_scripts` WHERE `guid` BETWEEN 821 AND 821;
INSERT INTO `waypoint_scripts` (`id`,`delay`,`command`,`datalong`,`datalong2`,`o`,`guid`) VALUES
(8316001,1,30,0,0,3.141593,821);

-- Pathing for Mechanar Crusher Entry: 19231
SET @NPC := 83221;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=90.85117,`position_y`=-74.31637,`position_z`=14.92653 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,96.89394,-71.07658,14.92652,0,0,0,100,0),
(@PATH,2,105.0891,-74.9791,14.92981,0,0,0,100,0),
(@PATH,3,107.6678,-81.30888,14.93107,0,0,0,100,0),
(@PATH,4,105.0891,-74.9791,14.92981,0,0,0,100,0),
(@PATH,5,96.89394,-71.07658,14.92652,0,0,0,100,0),
(@PATH,6,90.85117,-74.31637,14.92653,0,0,0,100,0);
