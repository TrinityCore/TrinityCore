-- 
SET @WPS_OFFSET := 20000000;
SET @WPS_REQUIRED_SPACE := 10000000;

DELETE FROM `waypoint_data` WHERE `id` BETWEEN @WPS_OFFSET AND @WPS_OFFSET+@WPS_REQUIRED_SPACE;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) SELECT w.`entry` + @WPS_OFFSET, w.`pointid`, w.`position_x`, w.`position_y`, w.`position_z`, w.`orientation`, w.`delay` FROM `waypoints` w;

UPDATE `smart_scripts` SET `action_param2`=`action_param2`+@WPS_OFFSET WHERE `action_type`=53;
UPDATE `smart_scripts` SET `action_param1`=`action_param1`+@WPS_OFFSET, `action_param2`=`action_param2`+@WPS_OFFSET, `action_param3`=`action_param3`+@WPS_OFFSET, `action_param4`=`action_param4`+@WPS_OFFSET, `action_param5`=`action_param5`+@WPS_OFFSET, `action_param6`=`action_param6`+@WPS_OFFSET, `action_param7`=`action_param7`+@WPS_OFFSET WHERE `action_type`=113;
UPDATE `smart_scripts` SET `event_param2`=`event_param2`+@WPS_OFFSET WHERE `event_type` IN(40, 55, 56, 57, 58);

DROP TABLE IF EXISTS `waypoints`;
