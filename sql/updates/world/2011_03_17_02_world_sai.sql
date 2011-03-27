-- Pathing for Fizzcrank Airman Entry: 26601
SET @NPC := 117944;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4120.091,`position_y`=5343.777,`position_z`=29.24856 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4111.694,5334.971,28.74856,0,0,0,100,0),
(@PATH,2,4102.274,5325.254,28.6343,0,0,0,100,0),
(@PATH,3,4091.229,5314.824,29.10337,0,0,0,100,0),
(@PATH,4,4083.519,5306.313,28.47837,0,0,0,100,0),
(@PATH,5,4072.305,5295.377,28.82582,0,0,0,100,0),
(@PATH,6,4083.519,5306.313,28.47837,0,0,0,100,0),
(@PATH,7,4091.229,5314.824,29.10337,0,0,0,100,0),
(@PATH,8,4102.274,5325.254,28.6343,0,0,0,100,0),
(@PATH,9,4111.694,5334.971,28.74856,0,0,0,100,0),
(@PATH,10,4120.091,5343.777,29.24856,0,0,0,100,0);

-- Pathing for Fizzcrank Airman Entry: 26601
SET @NPC := 117922;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4171.854,`position_y`=5364.676,`position_z`=29.09072 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4162.717,5358.622,28.71572,0,0,0,100,0),
(@PATH,2,4171.854,5364.676,29.09072,0,0,0,100,0),
(@PATH,3,4175.919,5373.461,28.73422,0,0,0,100,0),
(@PATH,4,4180.79,5375.921,28.85922,0,0,0,100,0),
(@PATH,5,4189.647,5383.252,28.98422,0,0,0,100,0),
(@PATH,6,4196.353,5389.414,28.98422,0,0,0,100,0),
(@PATH,7,4205.784,5399.744,29.17458,0,0,0,100,0),
(@PATH,8,4175.919,5373.461,28.73422,0,0,0,100,0),
(@PATH,9,4171.854,5364.676,29.09072,0,0,0,100,0);

-- Pathing for Fizzcrank Airman Entry: 26601
SET @NPC := 117952;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4114.012,`position_y`=5310.07,`position_z`=28.7593 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4114.952,5312.266,28.7593,0,0,0,100,0),
(@PATH,2,4120.03,5314.749,28.8843,0,0,0,100,0),
(@PATH,3,4128.648,5324.809,28.7593,0,0,0,100,0),
(@PATH,4,4132.928,5329.057,28.7593,0,0,0,100,0),
(@PATH,5,4129.167,5323.958,28.7593,0,0,0,100,0),
(@PATH,6,4120.03,5314.749,28.8843,0,0,0,100,0),
(@PATH,7,4114.952,5312.266,28.7593,0,0,0,100,0),
(@PATH,8,4114.012,5310.07,28.7593,0,0,0,100,0),
(@PATH,9,4110.154,5305.583,28.7593,0,0,0,100,0),
(@PATH,10,4106.395,5299.221,29.22841,0,0,0,100,0),
(@PATH,11,4098.468,5291.356,29.32582,0,0,0,100,0),
(@PATH,12,4087.384,5281.144,29.20082,0,0,0,100,0),
(@PATH,13,4098.468,5291.356,29.32582,0,0,0,100,0),
(@PATH,14,4106.395,5299.221,29.22841,0,0,0,100,0),
(@PATH,15,4110.154,5305.583,28.7593,0,0,0,100,0),
(@PATH,16,4114.012,5310.07,28.7593,0,0,0,100,0);

-- Pathing for Fizzcrank Airman Entry: 26601
SET @NPC := 117951;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4156.205,`position_y`=5379.297,`position_z`=28.60338 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4145.584,5368.483,28.97838,0,0,0,100,0),
(@PATH,2,4137.288,5361.018,28.96572,0,0,0,100,0),
(@PATH,3,4145.584,5368.483,28.97838,0,0,0,100,0),
(@PATH,4,4156.205,5379.297,28.60338,0,0,0,100,0),
(@PATH,5,4165.664,5389.022,28.97838,0,0,0,100,0),
(@PATH,6,4175.249,5398.305,29.10922,0,0,0,100,0),
(@PATH,7,4165.664,5389.022,28.97838,0,0,0,100,0),
(@PATH,8,4156.205,5379.297,28.60338,0,0,0,100,0);
