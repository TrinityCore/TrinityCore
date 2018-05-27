/*
-- Pathing for Princess
UPDATE `creature` SET `position_x`=-9785.24, `position_y`=-880.61, `position_z`=39.6131, `MovementType`=2 WHERE `guid`=80849;
UPDATE `creature` SET `position_x`=-9785.44, `position_y`=-883.454, `position_z`=39.6473 WHERE `guid`=80850;
UPDATE `creature` SET `position_x`=-9781.22, `position_y`=-881.556, `position_z`=39.5677 WHERE `guid`=80848;

DELETE FROM `creature_addon` WHERE `guid`=80849;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(80849,808490,0,0,0,0,"");

DELETE FROM `creature_formations` WHERE `leaderGUID`=80849;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(80849,80849,0,0,515,0,0),
(80849,80850,3,240,515,0,0),
(80849,80848,3,60,515,0,0);

DELETE FROM `waypoint_data` WHERE `id`=808490;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(808490,1,-9785.24,-880.61,39.6131,0,0,0,0,100,0),
(808490,2,-9792.77,-872.876,39.5751,0,0,0,0,100,0),
(808490,3,-9793.2,-867.623,39.4678,0,0,0,0,100,0),
(808490,4,-9774.36,-847.313,39.7919,0,0,0,0,100,0),
(808490,5,-9767.83,-847.814,39.6107,0,0,0,0,100,0),
(808490,6,-9752.2,-863.369,39.4772,0,0,0,0,100,0),
(808490,7,-9753.51,-871.917,39.5511,0,0,0,0,100,0),
(808490,8,-9769.58,-886.229,39.4867,0,0,0,0,100,0),
(808490,9,-9776.63,-887.336,39.5384,0,0,0,0,100,0);
*/
