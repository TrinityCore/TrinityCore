/*
-- Golorn Frostbeard - Path rework
SET @NPC := 219;
UPDATE `creature` SET `position_x`=-5633.440, `position_y`=-496.4770, `position_z`=396.8753, `orientation`=2.539195, `MovementType`=2 WHERE `guid`=@NPC;
SET @POINT := 0;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`, `orientation`) VALUES
(@PATH, (@POINT := @POINT + 1), -5636.061, -495.8329, 396.7780, 0, 0),
(@PATH, (@POINT := @POINT + 1), -5641.399, -498.8961, 396.7780, 0, 0),
(@PATH, (@POINT := @POINT + 1), -5640.832, -501.3918, 396.7937, 20000, 4.936115),
(@PATH, (@POINT := @POINT + 1), -5641.399, -498.8961, 396.7780, 0, 0),
(@PATH, (@POINT := @POINT + 1), -5640.068, -496.7379, 396.7780, 0, 0),
(@PATH, (@POINT := @POINT + 1), -5636.061, -495.8329, 396.7780, 0, 0),
(@PATH, (@POINT := @POINT + 1), -5633.440, -496.4770, 396.7780, 0, 0),
(@PATH, (@POINT := @POINT + 1), -5633.440, -496.4770, 396.7780, 30000, 2.199115);

-- Curator Thorius
DELETE FROM `smart_scripts` WHERE `entryorguid`=8256;
DELETE FROM `creature_text` WHERE  `entry`=8256 AND `groupid`=0 AND `id`=0;

SET @MAXGUID := 901;
SET @SCRIPTID := 188700;
DELETE FROM `waypoint_scripts` WHERE `id` IN (@SCRIPTID+0, @SCRIPTID+1, @SCRIPTID+2);
INSERT INTO `waypoint_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`, `guid`) VALUES 
(@SCRIPTID+0, 2, 0, 2, 0, 4285, 0, 0, 0, 0, (@MAXGUID := @MAXGUID + 1)),
(@SCRIPTID+0, 2, 1, 16, 0, 0, 0, 0, 0, 0, (@MAXGUID := @MAXGUID + 1)),
(@SCRIPTID+1, 2, 1, 69, 1, 0, 0, 0, 0, 0, (@MAXGUID := @MAXGUID + 1)),
(@SCRIPTID+1, 2, 0, 2, 0, 4286, 0, 0, 0, 0, (@MAXGUID := @MAXGUID + 1)),
(@SCRIPTID+1, 5, 1, 26, 1, 0, 0, 0, 0, 0, (@MAXGUID := @MAXGUID + 1)),
(@SCRIPTID+2, 2, 0, 0, 0, 4287, 0, 0, 0, 0, (@MAXGUID := @MAXGUID + 1));

SET @NPC := 1887;
SET @POINT := 0;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `delay`, `action`, `orientation`) VALUES
(@PATH, (@POINT := @POINT + 1), -4646.738, -1273.377, 503.3816, 0, 0, 0),
(@PATH, (@POINT := @POINT + 1), -4643.056, -1269.847, 503.3816, 0, 0, 0),
(@PATH, (@POINT := @POINT + 1), -4638.852, -1265.486, 503.3816, 0, 0, 0),
(@PATH, (@POINT := @POINT + 1), -4633.741, -1261.104, 503.3824, 0, 0, 0),
(@PATH, (@POINT := @POINT + 1), -4629.312, -1256.385, 503.3824, 0, 0, 0),
(@PATH, (@POINT := @POINT + 1), -4623.375, -1256.475, 503.3830, 0, 0, 0),
(@PATH, (@POINT := @POINT + 1), -4622.471, -1258.746, 503.3833, 0, 0, 0),
(@PATH, (@POINT := @POINT + 1), -4622.471, -1258.746, 503.3833, 4500, @SCRIPTID+0, 4.066617),
(@PATH, (@POINT := @POINT + 1), -4615.686, -1255.442, 503.3816, 0, 0, 0),
(@PATH, (@POINT := @POINT + 1), -4608.177, -1249.271, 503.3816, 0, 0, 0),
(@PATH, (@POINT := @POINT + 1), -4603.862, -1251.563, 503.3816, 0, 0, 0),
(@PATH, (@POINT := @POINT + 1), -4603.862, -1251.563, 503.3816, 6000, @SCRIPTID+1, 0.3316126),
(@PATH, (@POINT := @POINT + 1), -4598.436, -1240.892, 503.3816, 0, 0, 0),
(@PATH, (@POINT := @POINT + 1), -4592.448, -1232.214, 503.3816, 0, 0, 0),
(@PATH, (@POINT := @POINT + 1), -4588.735, -1222.179, 503.3816, 0, 0, 0),
(@PATH, (@POINT := @POINT + 1), -4588.735, -1222.179, 503.3816, 6000, @SCRIPTID+2, 5.742133),
(@PATH, (@POINT := @POINT + 1), -4593.644, -1214.160, 503.3816, 0, 0, 0),
(@PATH, (@POINT := @POINT + 1), -4598.711, -1219.354, 503.3816, 0, 0, 0),
(@PATH, (@POINT := @POINT + 1), -4604.790, -1227.240, 503.3816, 0, 0, 0),
(@PATH, (@POINT := @POINT + 1), -4610.729, -1236.657, 503.3816, 0, 0, 0),
(@PATH, (@POINT := @POINT + 1), -4613.158, -1252.017, 503.3816, 0, 0, 0),
(@PATH, (@POINT := @POINT + 1), -4618.215, -1264.094, 503.3841, 0, 0, 0),
(@PATH, (@POINT := @POINT + 1), -4633.393, -1276.797, 503.3816, 0, 0, 0),
(@PATH, (@POINT := @POINT + 1), -4652.419, -1285.877, 503.3816, 0, 0, 0),
(@PATH, (@POINT := @POINT + 1), -4667.360, -1293.999, 503.3816, 0, 0, 0),
(@PATH, (@POINT := @POINT + 1), -4678.205, -1296.404, 503.3816, 0, 0, 0),
(@PATH, (@POINT := @POINT + 1), -4689.225, -1301.691, 503.3816, 0, 0, 0),
(@PATH, (@POINT := @POINT + 1), -4699.487, -1307.610, 503.3816, 0, 0, 0),
(@PATH, (@POINT := @POINT + 1), -4709.615, -1317.365, 503.3816, 0, 0, 0),
(@PATH, (@POINT := @POINT + 1), -4711.283, -1322.386, 503.3816, 0, 0, 0),
(@PATH, (@POINT := @POINT + 1), -4711.283, -1322.386, 503.3816, 3000, 0, 3.577925),
(@PATH, (@POINT := @POINT + 1), -4702.810, -1325.272, 503.3816, 0, 0, 0),
(@PATH, (@POINT := @POINT + 1), -4696.292, -1325.815, 503.3816, 0, 0, 0),
(@PATH, (@POINT := @POINT + 1), -4689.635, -1325.204, 503.3816, 0, 0, 0),
(@PATH, (@POINT := @POINT + 1), -4686.068, -1319.191, 503.3816, 0, 0, 0),
(@PATH, (@POINT := @POINT + 1), -4683.053, -1314.015, 503.3816, 0, 0, 0),
(@PATH, (@POINT := @POINT + 1), -4675.000, -1312.604, 503.3816, 0, 0, 0),
(@PATH, (@POINT := @POINT + 1), -4664.885, -1306.134, 503.3816, 0, 0, 0),
(@PATH, (@POINT := @POINT + 1), -4662.038, -1298.117, 503.3816, 0, 0, 0),
(@PATH, (@POINT := @POINT + 1), -4659.426, -1288.833, 503.3816, 0, 0, 0),
(@PATH, (@POINT := @POINT + 1), -4654.313, -1281.536, 503.3816, 75000, 0, 0.959392);

UPDATE `waypoint_data` SET `action_chance`=100 WHERE `action` IN (@SCRIPTID+0, @SCRIPTID+1, @SCRIPTID+2);
*/
