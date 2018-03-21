-- Pathing for Notera Entry: 38988 'TDB FORMAT' 
SET @NPC := 309217;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-1300,`position_y`=-5440.625,`position_z`=14.82339 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-1300,-5440.625,14.82339,0,0,0,0,100,0),
(@PATH,2,-1300,-5440.625,14.82339,3.926991,35000,0,0,100,0),
(@PATH,3,-1318.75,-5435.938,14.57339,0,0,0,0,100,0),
(@PATH,4,-1321.913,-5445.783,14.69839,0,0,0,0,100,0),
(@PATH,5,-1325.403,-5455.481,14.82339,0,0,0,0,100,0),
(@PATH,6,-1319.396,-5460.197,14.74741,0,0,0,0,100,0),
(@PATH,7,-1320.642,-5462.503,14.69839,0,0,0,0,100,0),
(@PATH,8,-1320.642,-5462.503,14.69839,0.8552113,35000,0,0,100,0),
(@PATH,9,-1294.852,-5451.76,14.63159,0,0,0,0,100,0),
(@PATH,10,-1288.156,-5450.113,14.63159,0,35000,0,0,100,0),
(@PATH,11,-1294.852,-5451.76,14.63159,0,0,0,0,100,0);

-- Pathing for Swiftclaw Entry: 37989 'TDB FORMAT'
SET @NPC := 309298;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-1526.946,`position_y`=-5293.338,`position_z`=7.036779 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,65536,1,0, '49414');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-1526.946,-5293.338,7.036779,0,0,1,0,100,0),
(@PATH,2,-1513.422,-5261.768,6.022778,0,0,1,0,100,0),
(@PATH,3,-1529.59,-5251.986,5.536449,0,0,1,0,100,0),
(@PATH,4,-1546.019,-5244.101,5.903062,0,0,1,0,100,0),
(@PATH,5,-1571.21,-5227.306,2.966852,0,0,1,0,100,0),
(@PATH,6,-1588.757,-5226.844,2.730524,0,0,1,0,100,0),
(@PATH,7,-1592.734,-5240.252,4.783113,0,0,1,0,100,0),
(@PATH,8,-1587.373,-5256.415,6.222811,0,0,1,0,100,0),
(@PATH,9,-1558.642,-5270.479,7.747675,0,0,1,0,100,0),
(@PATH,10,-1550.734,-5285.778,8.727655,0,0,1,0,100,0),
(@PATH,11,-1562.5,-5319.791,8.162907,0,0,1,0,100,0),
(@PATH,12,-1584.167,-5326.924,7.515139,0,0,1,0,100,0),
(@PATH,13,-1589.431,-5312.096,7.558596,0,0,1,0,100,0),
(@PATH,14,-1588.484,-5282.405,7.868828,0,0,1,0,100,0),
(@PATH,15,-1631.594,-5272.896,3.32178,0,0,1,0,100,0),
(@PATH,16,-1633.125,-5292.288,3.241702,0,0,1,0,100,0),
(@PATH,17,-1606.47,-5307.899,6.649908,0,0,1,0,100,0),
(@PATH,18,-1603.608,-5325.474,6.399908,0,0,1,0,100,0),
(@PATH,19,-1647.531,-5337.802,0.9687176,0,0,1,0,100,0),
(@PATH,20,-1646.438,-5353.684,1.356413,0,0,1,0,100,0),
(@PATH,21,-1613.677,-5353.108,4.665707,0,0,1,0,100,0),
(@PATH,22,-1589.583,-5354.05,6.401405,0,0,1,0,100,0),
(@PATH,23,-1583.773,-5371.53,2.135296,0,0,1,0,100,0),
(@PATH,24,-1612.688,-5366.184,3.239926,0,0,1,0,100,0),
(@PATH,25,-1599.408,-5349.478,6.146034,0,0,1,0,100,0),
(@PATH,26,-1573.696,-5351.231,6.08329,0,0,1,0,100,0),
(@PATH,27,-1562.012,-5336.09,7.905767,0,0,1,0,100,0),
(@PATH,28,-1549.799,-5324.856,7.537907,0,0,1,0,100,0),
(@PATH,29,-1532.8,-5335.096,6.867312,0,0,1,0,100,0),
(@PATH,30,-1532.948,-5342.743,6.367312,0,0,1,0,100,0),
(@PATH,31,-1542.224,-5354.582,5.664557,0,0,1,0,100,0),
(@PATH,32,-1531.813,-5367.337,4.457694,0,0,1,0,100,0),
(@PATH,33,-1516.96,-5356.293,6.370486,0,0,1,0,100,0),
(@PATH,34,-1509.054,-5333.045,5.515051,0,0,1,0,100,0),
(@PATH,35,-1531.285,-5315.335,7.240881,0,0,1,0,100,0),
(@PATH,36,-1552.431,-5298.374,9.102655,0,0,1,0,100,0),
(@PATH,37,-1576.738,-5285.853,8.213554,0,0,1,0,100,0),
(@PATH,38,-1585.991,-5272.233,7.848564,0,0,1,0,100,0),
(@PATH,39,-1561.387,-5265.125,7.278062,0,0,0,0,100,0);

-- Pathing for Spitescale Wavethrasher Entry: 38300 'TDB FORMAT' 
SET @NPC := 308676;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-719.8108,`position_y`=-5533.647,`position_z`=-35.9404 WHERE `guid`=@NPC;
UPDATE `creature` SET `position_x`=-719.8108,`position_y`=-5533.647,`position_z`=-35.9404 WHERE `guid`=308674;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-719.8108,-5533.647,-35.9404,0,0,0,0,100,0),
(@PATH,2,-712.1268,-5517.988,-37.16269,0,0,0,0,100,0),
(@PATH,3,-705.4427,-5506.236,-37.62453,0,0,0,0,100,0),
(@PATH,4,-696.7188,-5490.587,-37.25265,0,0,0,0,100,0),
(@PATH,5,-685.1129,-5489.99,-37.37149,0,0,0,0,100,0),
(@PATH,6,-667.4531,-5498.359,-38.40761,0,0,0,0,100,0),
(@PATH,7,-685.1129,-5489.99,-37.37149,0,0,0,0,100,0),
(@PATH,8,-696.7188,-5490.587,-37.25265,0,0,0,0,100,0),
(@PATH,9,-705.4427,-5506.236,-37.62453,0,0,0,0,100,0),
(@PATH,10,-712.1268,-5517.988,-37.16269,0,0,0,0,100,0);
-- Set Formation/Group Combat Assistance
DELETE FROM `creature_formations` WHERE `leaderGUID`=@NPC;
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(@NPC,@NPC,0,0,515,0,0),
(@NPC,308674,4,360,515,0,0);

-- Pathing for Spitescale Wavethrasher Entry: 38300 'TDB FORMAT' 
SET @NPC := 308762;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-729.5243,`position_y`=-5580.568,`position_z`=-10.72262 WHERE `guid`=@NPC;
UPDATE `creature` SET `position_x`=-729.5243,`position_y`=-5580.568,`position_z`=-10.72262 WHERE `guid`=308759;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-729.5243,-5580.568,-10.72262,0,0,0,0,100,0),
(@PATH,2,-741.3333,-5588.672,-8.715025,0,0,0,0,100,0),
(@PATH,3,-739.7118,-5605.749,-10.09575,0,0,0,0,100,0),
(@PATH,4,-717.2795,-5622.351,-9.488791,0,0,0,0,100,0),
(@PATH,5,-699.3924,-5633.299,-8.781458,0,0,0,0,100,0),
(@PATH,6,-692.5035,-5626.893,-8.834947,0,0,0,0,100,0),
(@PATH,7,-688.3559,-5613.681,-8.36482,0,0,0,0,100,0),
(@PATH,8,-692.5035,-5626.893,-8.834947,0,0,0,0,100,0),
(@PATH,9,-699.3924,-5633.299,-8.781458,0,0,0,0,100,0),
(@PATH,10,-717.2795,-5622.351,-9.488791,0,0,0,0,100,0),
(@PATH,11,-739.7118,-5605.749,-10.09575,0,0,0,0,100,0),
(@PATH,12,-741.3333,-5588.672,-8.715025,0,0,0,0,100,0);
-- Set Formation/Group Combat Assistance
DELETE FROM `creature_formations` WHERE `leaderGUID`=@NPC;
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(@NPC,@NPC,0,0,515,0,0),
(@NPC,308759,4,360,515,0,0);

-- Pathing for Spitescale Wavethrasher Entry: 38300 'TDB FORMAT' 
SET @NPC := 308744;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-655.7292,`position_y`=-5628.372,`position_z`=-25.27461 WHERE `guid`=@NPC;
UPDATE `creature` SET `position_x`=-655.7292,`position_y`=-5628.372,`position_z`=-25.27461 WHERE `guid`=308739;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-655.7292,-5628.372,-25.27461,0,0,0,0,100,0),
(@PATH,2,-655.7031,-5612.156,-23.81702,0,0,0,0,100,0),
(@PATH,3,-663.7952,-5597.663,-22.21065,0,0,0,0,100,0),
(@PATH,4,-683.7379,-5583.715,-17.73336,0,0,0,0,100,0),
(@PATH,5,-703.5156,-5580.063,-15.14296,0,0,0,0,100,0),
(@PATH,6,-717.4965,-5580.391,-11.91345,0,0,0,0,100,0),
(@PATH,7,-703.5156,-5580.063,-15.14296,0,0,0,0,100,0),
(@PATH,8,-683.7379,-5583.715,-17.73336,0,0,0,0,100,0),
(@PATH,9,-663.7952,-5597.663,-22.21065,0,0,0,0,100,0),
(@PATH,10,-655.7031,-5612.156,-23.81702,0,0,0,0,100,0);
-- Set Formation/Group Combat Assistance
DELETE FROM `creature_formations` WHERE `leaderGUID`=@NPC;
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(@NPC,@NPC,0,0,515,0,0),
(@NPC,308739,4,360,515,0,0);

-- Pathing for Spitescale Wavethrasher Entry: 38300 'TDB FORMAT' 
SET @NPC := 308761;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-723.8455,`position_y`=-5559.859,`position_z`=-34.88156 WHERE `guid`=@NPC;
UPDATE `creature` SET `position_x`=-723.8455,`position_y`=-5559.859,`position_z`=-34.88156 WHERE `guid`=308765;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-723.8455,-5559.859,-34.88156,0,0,0,0,100,0),
(@PATH,2,-733.3472,-5575.132,-36.39593,0,0,0,0,100,0),
(@PATH,3,-747.6949,-5601.841,-43.93761,0,0,0,0,100,0),
(@PATH,4,-758.1007,-5622.559,-42.44852,0,0,0,0,100,0),
(@PATH,5,-754.4948,-5638.569,-40.36657,0,0,0,0,100,0),
(@PATH,6,-758.1007,-5622.559,-42.44852,0,0,0,0,100,0),
(@PATH,7,-747.6962,-5601.844,-43.94424,0,0,0,0,100,0),
(@PATH,8,-733.4958,-5575.409,-36.37019,0,0,0,0,100,0);
-- Set Formation/Group Combat Assistance
DELETE FROM `creature_formations` WHERE `leaderGUID`=@NPC;
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(@NPC,@NPC,0,0,515,0,0),
(@NPC,308765,4,360,515,0,0);

-- Pathing for Spitescale Wavethrasher Entry: 38300 'TDB FORMAT' 
SET @NPC := 308711;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-702.9913,`position_y`=-5651.726,`position_z`=-31.03225 WHERE `guid`=@NPC;
UPDATE `creature` SET `position_x`=-702.9913,`position_y`=-5651.726,`position_z`=-31.03225 WHERE `guid`=308709;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-702.9913,-5651.726,-31.03225,0,0,0,0,100,0),
(@PATH,2,-715.7882,-5646.854,-34.36124,0,0,0,0,100,0),
(@PATH,3,-727.4496,-5638.446,-37.77372,0,0,0,0,100,0),
(@PATH,4,-743.7813,-5635.285,-39.44044,0,0,0,0,100,0),
(@PATH,5,-727.4496,-5638.446,-37.77372,0,0,0,0,100,0),
(@PATH,6,-715.7882,-5646.854,-34.36124,0,0,0,0,100,0),
(@PATH,7,-702.9913,-5651.726,-31.03225,0,0,0,0,100,0),
(@PATH,8,-680.066,-5643.766,-27.30419,0,0,0,0,100,0),
(@PATH,9,-667.5208,-5637.434,-25.56453,0,0,0,0,100,0),
(@PATH,10,-680.066,-5643.766,-27.30419,0,0,0,0,100,0);
-- Set Formation/Group Combat Assistance
DELETE FROM `creature_formations` WHERE `leaderGUID`=@NPC;
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(@NPC,@NPC,0,0,515,0,0),
(@NPC,308709,4,360,515,0,0);

UPDATE `creature` SET `unit_flags`=537166080,`dynamicflags`=64 WHERE `guid` IN (308778,308782);
DELETE FROM `creature_queststarter` WHERE `id` IN (38300,38560,39157);
UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry` IN (38003,38560);
UPDATE `waypoint_data` SET `delay`=30000 WHERE `id`=3090350 AND `point`=4;
UPDATE `creature_addon` SET `auras`='65017' WHERE `guid`=309061;
DELETE FROM `creature_addon` WHERE `guid` IN (309031,309041,309035,308767,308775,308778,308782);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(309031,0,0,65536,1,0, '65017'),(309041,0,0,65536,1,0, '65017'),(309035,0,0,65536,257,0, '65017'),
(308767,0,0,50331648,1,0, '51195'),(308775,0,0,50331648,1,0, '51195'),(308778,0,0,0,1,0, '29266'),(308782,0,0,0,1,0, '29266');
