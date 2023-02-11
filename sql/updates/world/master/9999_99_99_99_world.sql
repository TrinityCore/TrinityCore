-- 
SET @WPS_OFFSET := 20000000;
SET @WPS_REQUIRED_SPACE := 10000000;

DELETE FROM `waypoint_data` WHERE `id` BETWEEN @WPS_OFFSET AND @WPS_OFFSET+@WPS_REQUIRED_SPACE;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) SELECT w.`entry` + @WPS_OFFSET, w.`pointid`, w.`position_x`, w.`position_y`, w.`position_z`, w.`orientation`, w.`delay` FROM `waypoints` w;

UPDATE `smart_scripts` SET `action_param2`=`action_param2`+@WPS_OFFSET WHERE `action_type`=53;
UPDATE `smart_scripts` SET `event_param2`=`event_param2`+@WPS_OFFSET WHERE `event_type`=40;

DROP TABLE IF EXISTS `waypoints`;
