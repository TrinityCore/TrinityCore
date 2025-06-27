-- High Priest Rohan -- http://wotlk.openwow.com/npc=11406
SET @NPC := 1777;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`, `orientation`) VALUES
(@PATH, 1, -4603.22, -905.336, 502.767, 0, 0),
(@PATH, 2, -4602.8, -903.233, 502.767, 0, 0),
(@PATH, 3, -4607.16, -897.28, 502.767, 0, 0),
(@PATH, 4, -4607.16, -897.28, 502.767, 90000, 5.358161),
(@PATH, 5, -4601.63, -904.615, 502.767, 0, 0),
(@PATH, 6, -4602.05, -906.355, 502.767, 0, 0),
(@PATH, 7, -4608.62, -913.508, 501.061, 0, 0),
(@PATH, 8, -4610.18, -921.852, 501.068, 0, 0),
(@PATH, 9, -4607.63, -926.901, 501.071, 0, 0),
(@PATH, 10, -4607.63, -926.901, 501.071, 180000, 2.338741),
(@PATH, 11, -4612.25, -909.152, 501.062, 0, 0),
(@PATH, 12, -4612.25, -909.152, 501.062, 90000, 4.328416);
