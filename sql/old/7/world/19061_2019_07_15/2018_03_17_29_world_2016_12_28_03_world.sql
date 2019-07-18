-- LBRS Pathing
SET @NPC := 43503;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH,1, -24.539305,-514.424866,29.163296, 0),
(@PATH,2, -24.539305,-514.424866,29.163296, 30000),
(@PATH,3, -49.821911,-513.863159,29.187195, 0),
(@PATH,4, -49.821911,-513.863159,29.187195, 30000);

UPDATE `creature` SET `position_x`=-39.0271, `position_y`=-547.342, `position_z`=16.1255, `orientation`=4.97512 WHERE `guid`=43559;
SET @NPC := 43559;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH,1, -39.107231,-547.148987,16.125872, 60*1000),
(@PATH,2, -39.597519,-523.890381,4.992621, 30*1000);

SET @NPC := 40154;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH,1, -48.089626,-460.303558,16.398632, 0),
(@PATH,2, -8.386492,-461.059998,16.728352, 0),
(@PATH,3, -47.694778,-460.330566,16.402576, 0),
(@PATH,4, -47.758339,-472.839417,16.333258, 0),
(@PATH,5, -40.366806,-493.487183,16.186602, 0),
(@PATH,6, -39.576500,-509.575165,5.856623, 30*1000),
(@PATH,7, -39.994362,-493.414276,16.188383, 0),
(@PATH,8, -47.637386,-472.980103,16.333862, 0);

UPDATE `creature` SET `position_x`=-72.9836, `position_y`=-517.218, `position_z`=-7.14286, `orientation`=4.7285 WHERE `guid`=43560;
SET @NPC := 43560;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH,1, -73.970467,-517.234009,-7.142864, 0),
(@PATH,2, -73.874817,-523.169250,-7.142920, 0),
(@PATH,3, -73.265968,-540.061218,-18.795183, 0),
(@PATH,4, -73.173820,-545.779480,-18.800999, 0),
(@PATH,5, -63.243862,-549.406189,-18.812057, 0),
(@PATH,6, -18.329285,-549.121521,-18.785419, 0),
(@PATH,7, -5.791784,-542.450745,-18.793913, 0),
(@PATH,8, -5.484589,-523.005493,-7.142718, 0),
(@PATH,9, -5.638316,-512.436646,-7.142718, 0),
(@PATH,10, -5.917571,-493.237671,-18.795147, 0),
(@PATH,11, -14.509295,-487.841888,-18.789783, 0),
(@PATH,12, -66.097374,-487.162323,-18.788757, 0),
(@PATH,13, -73.520866,-493.968750,-18.793919, 0),
(@PATH,14, -73.070999,-511.362244,-7.242242, 0);

DELETE FROM `creature_formations` WHERE `leaderGUID`=43560;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(43560, 43560, 0, 0, 2, 0, 0),
(43560, 43561, 3, 0, 2, 0, 0);

UPDATE `creature` SET `position_x`=-111.52, `position_y`=-495.227, `position_z`=-18.4569, `orientation`=1.48874 WHERE `guid`=43764;

SET @NPC := 43764;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`) VALUES
(@PATH,1, -111.519859,-495.227142,-18.456940),
(@PATH,2, -109.896652,-464.849060,-18.934961),
(@PATH,3, -84.653816,-439.250580,-18.934961),
(@PATH,4, -67.780334,-419.889923,-18.934961),
(@PATH,5, -60.713531,-417.953033,-18.934961),
(@PATH,6, -9.332710,-420.316162,-18.934961),
(@PATH,7, -2.238527,-422.439362,-18.934961),
(@PATH,8, -1.244248,-446.211823,-18.934753),
(@PATH,9, 19.821653,-447.426331,-18.934378),
(@PATH,10, 18.931326,-493.151703,-18.483871),
(@PATH,11, 15.599535,-504.352753,-18.405764),
(@PATH,12, 16.812010,-512.320251,-18.463589),
(@PATH,13, 16.011930,-504.230652,-18.412947),
(@PATH,14, 19.295931,-492.924255,-18.492430),
(@PATH,15, 19.841694,-448.336029,-18.933733),
(@PATH,16, -0.717553,-446.633148,-18.934631),
(@PATH,17, -1.842408,-422.642365,-18.934040),
(@PATH,18, -9.304630,-420.401215,-18.934040),
(@PATH,19, -60.141975,-418.226532,-18.934040),
(@PATH,20, -67.558952,-420.345734,-18.934040),
(@PATH,21, -84.157814,-439.430664,-18.934040),
(@PATH,22, -109.428772,-465.330292,-18.934040),
(@PATH,23, -111.255486,-495.324738,-18.456909);

-- Grunt in the middle of the main corridor patrolling back and forth between two tents
UPDATE `creature` SET `position_x`=-41.9485, `position_y`=-425.748, `position_z`=-18.935, `orientation`=0.458297 WHERE `guid`=43764;

SET @NPC := 43767;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH,1, -42.213486,-425.895782,-18.934973, 30*1000),
(@PATH,2, -53.331005,-413.390137,-18.934973, 30*1000);

-- Patrol of one grunt and one darkweaver patrolling all the way
UPDATE `creature` SET `position_x`=-109.985, `position_y`=-456.958, `position_z`=-18.9344, `orientation`=4.69159 WHERE `guid`=43763;
UPDATE `creature` SET `position_x`=-112.677, `position_y`=-458.12, `position_z`=-18.9344, `orientation`=4.69159 WHERE `guid`=43771;
SET @NPC := 43763;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`) VALUES
(@PATH,1, -111.095695,-457.167389,-18.934425, 0),
(@PATH,2, -111.467453,-475.041534,-18.539604, 0),
(@PATH,3, -110.836365,-457.761536,-18.933743, 0),
(@PATH,4, -90.937553,-443.860382,-18.933743, 0),
(@PATH,5, -65.725304,-416.266144,-18.933743, 0),
(@PATH,6, -1.099830,-418.993073,-18.759935, 0),
(@PATH,7, 0.389136,-443.609253,-18.934147, 0),
(@PATH,8, 23.756561,-446.480286,-18.934437, 0),
(@PATH,9, 20.058512,-473.346893,-18.416866, 0),
(@PATH,10, 19.636366,-497.844696,-18.437708, 0),
(@PATH,11, 16.802956,-496.517242,-18.383026, 0),
(@PATH,12, 15.794456,-472.194489,-18.580204, 0),
(@PATH,13, 19.537477,-449.352936,-18.934959, 0),
(@PATH,14, -1.293265,-448.573944,-18.935009, 0),
(@PATH,15, -4.664356,-423.750244,-18.933882, 0),
(@PATH,16, -24.780350,-420.808136,-18.933882, 0),
(@PATH,17, -65.957001,-420.163727,-18.933882, 0),
(@PATH,18, -90.123260,-445.283661,-18.933882, 0);

DELETE FROM `creature_formations` WHERE `leaderGUID`=43763;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(43763, 43763, 0, 0, 2, 0, 0),
(43763, 43771, 3, 0, 2, 0, 0);
