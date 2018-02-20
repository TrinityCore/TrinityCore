--
SET @NPC := 322219;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1395.607,`position_y`=1967.916,`position_z`=18.21449 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1395.607,1967.916,18.21449,0,0,0,0,100,0),
(@PATH,2,1394.16,1971.855,18.46909,0,0,0,0,100,0),
(@PATH,3,1384.627,1984.173,18.75889,0,0,0,0,100,0),
(@PATH,4,1378.888,1992.172,18.40506,0,0,0,0,100,0),
(@PATH,5,1368.135,1992.527,17.40968,0,0,0,0,100,0),
(@PATH,6,1376.495,1993.365,18.46769,0,0,0,0,100,0),
(@PATH,7,1381.746,1987.858,18.92303,0,0,0,0,100,0),
(@PATH,8,1391.86,1975.847,18.5155,0,0,0,0,100,0);

SET @NPC := 322231;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1391.356,`position_y`=2009.19,`position_z`=15.90081 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1391.356,2009.19,15.90081,0,0,0,0,100,0),
(@PATH,2,1396.165,2010.43,15.85461,0,0,0,0,100,0),
(@PATH,3,1411.213,2008.864,14.35008,0,0,0,0,100,0),
(@PATH,4,1422.343,2006.244,12.90728,0,0,0,0,100,0),
(@PATH,5,1434.081,2000.935,11.78559,0,0,0,0,100,0),
(@PATH,6,1448.412,1987.407,11.08783,0,0,0,0,100,0),
(@PATH,7,1444.67,1979.197,12.00837,0,0,0,0,100,0),
(@PATH,8,1448.225,1985.995,11.50098,0,0,0,0,100,0),
(@PATH,9,1440.929,1996.727,11.48743,0,0,0,0,100,0),
(@PATH,10,1425.209,2004.932,12.75235,0,0,0,0,100,0),
(@PATH,11,1412.675,2008.376,13.90751,0,0,0,0,100,0),
(@PATH,12,1403.565,2011.907,15.41258,0,0,0,0,100,0);

SET @NPC := 322230;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1411.675,`position_y`=1959.445,`position_z`=15.54728 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1411.675,1959.445,15.54728,0,0,0,0,100,0),
(@PATH,2,1408.175,1957.945,16.29728,0,0,0,0,100,0);

SET @NPC := 322213;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1292.105,`position_y`=1954.99,`position_z`=19.55139 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1292.105,1954.99,19.55139,0,0,0,0,100,0),
(@PATH,2,1312.855,1964.24,15.80139,0,0,0,0,100,0);

UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='71764' WHERE `entry`=1766; -- 1766 (Rabid Worg)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=1797; -- 1797 (Giant Rabid Bear)
UPDATE `creature_template_addon` SET `auras`='83859' WHERE `entry`=44923; -- 44923 (North Tide's Invisible Stalker (Large))
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=1412; -- 1412 (Squirrel)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='13886' WHERE `entry`=1780; -- 1780 (Skitterweb Striker)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=1781; -- 1781 (Skitterweb Lurker)

UPDATE `creature_template` SET `maxlevel`=11, `speed_run`=1 WHERE `entry`=1797; -- Giant Rabid Bear
UPDATE `creature_template` SET `npcflag`=0 WHERE `entry`=44906; -- Skitterweb Matriarch
