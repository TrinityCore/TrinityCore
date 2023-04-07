-- Shift existing rows by 3 bits to reserve space for 3 other tables
UPDATE `waypoint_data` SET `id`=(`id` << 3) ORDER BY `id` DESC;
UPDATE `creature_addon` SET `path_id`=(`path_id` << 3);
UPDATE `event_scripts` SET `datalong`=(`datalong` << 3) WHERE `command`=20 AND `datalong` > 0;
UPDATE `event_scripts` SET `dataint`=(`dataint` << 3) WHERE `command`=35 AND `datalong`=2 AND `dataint` > 0;
UPDATE `spell_scripts` SET `datalong`=(`datalong` << 3) WHERE `command`=20 AND `datalong` > 0;
UPDATE `spell_scripts` SET `dataint`=(`dataint` << 3) WHERE `command`=35 AND `datalong`=2 AND `dataint` > 0;
UPDATE `waypoint_scripts` SET `datalong`=(`datalong` << 3) WHERE `command`=20 AND `datalong` > 0;
UPDATE `waypoint_scripts` SET `dataint`=(`dataint` << 3) WHERE `command`=35 AND `datalong`=2 AND `dataint` > 0;

-- use bit 0 for waypoints
DELETE FROM `waypoint_data` WHERE `id` & 1;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`) 
SELECT ((w.`entry` << 3) | 1), w.`pointid`, w.`position_x`, w.`position_y`, w.`position_z`, w.`orientation`, w.`delay`, MAX(IFNULL(ss.`action_param1`, 0))
FROM `waypoints` w
LEFT JOIN `smart_scripts` ss ON w.`entry`=ss.`action_param2` AND ss.`action_type`=53 AND ss.`action_param2` > 0
GROUP BY ((w.`entry` << 3) | 1), w.`pointid`, w.`position_x`, w.`position_y`, w.`position_z`, w.`orientation`, w.`delay`;

UPDATE `smart_scripts` SET `action_param2`=((`action_param2` << 3) | 1) WHERE `action_type`=53 AND `action_param2` > 0;
UPDATE `smart_scripts` SET `action_param1`=((`action_param1` << 3) | 1) WHERE `action_type`=113 AND `action_param1` > 0;
UPDATE `smart_scripts` SET `action_param2`=((`action_param2` << 3) | 1) WHERE `action_type`=113 AND `action_param2` > 0;
UPDATE `smart_scripts` SET `action_param3`=((`action_param3` << 3) | 1) WHERE `action_type`=113 AND `action_param3` > 0;
UPDATE `smart_scripts` SET `action_param4`=((`action_param4` << 3) | 1) WHERE `action_type`=113 AND `action_param4` > 0;
UPDATE `smart_scripts` SET `action_param5`=((`action_param5` << 3) | 1) WHERE `action_type`=113 AND `action_param5` > 0;
UPDATE `smart_scripts` SET `action_param6`=((`action_param6` << 3) | 1) WHERE `action_type`=113 AND `action_param6` > 0;
UPDATE `smart_scripts` SET `action_param7`=((`action_param7` << 3) | 1) WHERE `action_type`=113 AND `action_param7` > 0;
UPDATE `smart_scripts` SET `event_param2`=((`event_param2` << 3) | 1)  WHERE `event_type` IN(40, 55, 56, 57, 58) AND `event_param2` > 0;

DROP TABLE IF EXISTS `waypoints`;
