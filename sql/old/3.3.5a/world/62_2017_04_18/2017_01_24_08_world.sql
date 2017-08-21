-- Thrallmar Peon Worker Script 
SET @MAXGUID := 938; 
SET @SCRIPTID := 5757600; 
DELETE FROM `waypoint_scripts` WHERE `id` IN (@SCRIPTID+0,@SCRIPTID+1);
INSERT INTO `waypoint_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`, `guid`) VALUES 
(@SCRIPTID+0, 3, 1, 233, 1, 0, 0, 0, 0, 0, (@MAXGUID := @MAXGUID + 1)),
(@SCRIPTID+0, 57, 1, 0, 1, 0, 0, 0, 0, 0, (@MAXGUID := @MAXGUID + 1)),
(@SCRIPTID+1, 3, 1, 69, 1, 0, 0, 0, 0, 0, (@MAXGUID := @MAXGUID + 1)),
(@SCRIPTID+1, 57, 1, 0, 1, 0, 0, 0, 0, 0, (@MAXGUID := @MAXGUID + 1));

SET @NPC := 57576;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `orientation`, `delay`, `action`) VALUES
(@PATH, 1, 23.7, 2677.07, 76.7947, 4.65552, 0, 0),
(@PATH, 2, 29.5186, 2662.79, 75.5889, 5.97498, 0, 0),
(@PATH, 3, 36.7549, 2663.57, 76.6482, 0.389553, 0, 0),
(@PATH, 4, 57.1088, 2670.26, 79.1019, 5.93525, 0, 0),
(@PATH, 5, 65.1478, 2663.53, 79.9572, 5.34777, 0, 0),
(@PATH, 6, 68.2604, 2653.86, 80.6543, 4.51761, 0, 0),
(@PATH, 7, 66.6964, 2647.89, 79.1051, 4.01889, 60000, @SCRIPTID+0),
(@PATH, 8, 69.3452, 2654.17, 80.9377, 1.86925, 0, 0),
(@PATH, 9, 65.8566, 2661.81, 80.4231, 2.45123, 0, 0),
(@PATH, 10, 54.4738, 2667.41, 78.6493, 3.32538, 0, 0),
(@PATH, 11, 41.6966, 2665.8, 77.3675, 3.71022, 0, 0),
(@PATH, 12, 31.8775, 2658.08, 75.2857, 4.39666, 0, 0),
(@PATH, 13, 32.2505, 2643.01, 74.3166, 5.25981, 0, 0),
(@PATH, 14, 35.6496, 2635.57, 75.9404, 5.43495, 0, 0),
(@PATH, 15, 41.5567, 2626.67, 74.4366, 6.22431, 0, 0),
(@PATH, 16, 45.3727, 2626.16, 73.861, 0.135119, 60000, @SCRIPTID+1),
(@PATH, 17, 42.0584, 2627.08, 74.4471, 2.53294, 0, 0),
(@PATH, 18, 33.2927, 2635.99, 75.411, 2.20307, 0, 0),
(@PATH, 19, 32.4661, 2641.63, 74.3467, 1.65329, 0, 0),
(@PATH, 20, 27.458, 2663.08, 75.3224, 1.86142, 0, 0),
(@PATH, 21, 24.2932, 2669.6, 76.2387, 1.78838, 0, 0),
(@PATH, 22, 23.1339, 2680.03, 76.8103, 0.750085, 0, 0),
(@PATH, 23, 26.3861, 2681.9, 77.2808, 0.227795, 60000, @SCRIPTID+1);

UPDATE `waypoint_data` SET `action_chance`=100 WHERE `action` IN (@SCRIPTID+0,@SCRIPTID+1);
