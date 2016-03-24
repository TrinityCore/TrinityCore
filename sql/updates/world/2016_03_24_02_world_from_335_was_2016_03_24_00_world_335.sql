--
/*
UPDATE `creature` SET `MovementType`=0 WHERE `guid` IN (46414, 46416);
UPDATE `creature_addon` SET `path_id`=0 WHERE `guid` IN (46414, 46416);
DELETE FROM `waypoint_data` WHERE `id` IN (464140, 464160);
DELETE FROM `creature_formations` WHERE `leaderGUID`=46394;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(46394, 46394, 0, 0, 2, 0, 0),
(46394, 46414, 4, 260, 2, 1, 5),
(46394, 46416, 4, 100, 2, 1, 5);
*/
