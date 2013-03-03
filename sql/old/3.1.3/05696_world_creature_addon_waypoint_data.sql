-- *TrullyOne/MeanMachine Waypoint System Restored. Patch by XTElite1.
-- This should be applied to world_script_waypoints.sql ASAP
ALTER TABLE `creature_addon`
    ADD `path_id` int(11) unsigned NOT NULL default '0' AFTER `guid`;
ALTER TABLE `creature_template_addon`
    ADD `path_id` int(11) unsigned NOT NULL default '0' AFTER `entry`;

ALTER TABLE `waypoint_data` ADD COLUMN `id_old` int(10) unsigned NOT NULL default '0' COMMENT 'Creature GUID' AFTER `wpguid`;
UPDATE `waypoint_data` SET `id_old`=`id`*0.1;

REPLACE INTO `creature_addon` ( `guid` ) SELECT `id_old` FROM `waypoint_data`;

UPDATE `creature_addon`,`waypoint_data` SET `creature_addon`.`path_id` = `waypoint_data`.`id` WHERE `creature_addon`.`guid`=`waypoint_data`.`id_old`;

ALTER TABLE `waypoint_data` DROP COLUMN `id_old`;
