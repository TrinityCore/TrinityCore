-- Consortium Overseer -- http://wotlk.openwow.com/npc=18274
SET @MAXGUID := 914; 
SET @SCRIPTID := 6556600;
DELETE FROM `waypoint_scripts` WHERE `id` IN (@SCRIPTID+0);
INSERT INTO `waypoint_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`, `guid`) VALUES 
(@SCRIPTID+0, 15, 0, 0, 0, 16960, 0, 0, 0, 0, (@MAXGUID := @MAXGUID + 1));

SET @NPC := 65566;
SET @POINT := 0;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`, `action`, `orientation`) VALUES
(@PATH, 1, -2086, 8569.04, 21.5988, 0, 0, 2.25497),
(@PATH, 2, -2104.1, 8587.69, 18.2267, 0, 0, 2.44975),
(@PATH, 3, -2076.87, 8558.08, 22.9817, 0, 0, 5.41856),
(@PATH, 4, -2065.22, 8536.39, 23.9165, 60000, @SCRIPTID, 5.10126),
(@PATH, 5, -2074.9, 8545.01, 22.9726, 0, 0, 1.88819),
(@PATH, 6, -2078.75, 8557.38, 22.8488, 0, 0, 2.1081),
(@PATH, 7, -2086.85, 8569.92, 21.4582, 0, 0, 2.22591),
(@PATH, 8, -2103.09, 8588.28, 18.2584, 0, 0, 0.444629),
(@PATH, 9, -2091.81, 8599.37, 20.2861, 0, 0, 0.0809899),
(@PATH, 10, -2068.57, 8594.29, 21.5667, 0, 0, 5.19236),
(@PATH, 11, -2064.07, 8583.91, 21.4222, 0, 0, 4.72034),
(@PATH, 12, -2063.53, 8571.92, 23.4418, 0, 0, 4.72539),
(@PATH, 13, -2063.37, 8546.69, 23.9351, 60000,0, 4.61544);

UPDATE `waypoint_data` SET `action_chance`=100 WHERE `action` IN (@SCRIPTID);
