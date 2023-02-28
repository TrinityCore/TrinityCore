-- Shift existing rows by 3 bits to reserve space for 3 other tables
UPDATE `waypoint_data` SET `id`=(`id` << 3) ORDER BY `id` DESC;
UPDATE `creature_addon` SET `path_id`=(`path_id` << 3);
UPDATE `smart_scripts` SET `event_param2`=((`event_param2` << 3))  WHERE `event_type`=34 AND `event_param2` <> 4294967295; -- skip -1

-- use bit 0 for waypoints
DELETE FROM `waypoint_data` WHERE `id` & 1;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) SELECT ((w.`entry` << 3) | 1), w.`pointid`, w.`position_x`, w.`position_y`, w.`position_z`, w.`orientation`, w.`delay` FROM `waypoints` w;

UPDATE `smart_scripts` SET `action_param2`=((`action_param2` << 3) | 1) WHERE `action_type`=53;
UPDATE `smart_scripts` SET `action_param1`=((`action_param1` << 3) | 1), `action_param2`=((`action_param2` << 3) | 1), `action_param3`=((`action_param3` << 3) | 1), `action_param4`=((`action_param4` << 3) | 1), `action_param5`=((`action_param5` << 3) | 1), `action_param6`=((`action_param6` << 3) | 1), `action_param7`=((`action_param7` << 3) | 1) WHERE `action_type`=113;
UPDATE `smart_scripts` SET `event_param2`=((`event_param2` << 3) | 1)  WHERE `event_type` IN(40, 55, 56, 57, 58);
