--
DROP PROCEDURE IF EXISTS waypoint_data_refactor;

DELIMITER ;;
CREATE PROCEDURE waypoint_data_refactor() BEGIN
  IF EXISTS (SELECT * FROM `information_schema`.`columns` WHERE `table_schema`=SCHEMA() AND `table_name`='waypoint_data') THEN
    DROP TABLE IF EXISTS `waypoint_path`;
    CREATE TABLE `waypoint_path`  (
      `PathId` bigint UNSIGNED NOT NULL,
      `Type` tinyint UNSIGNED NOT NULL DEFAULT 0,
      `Flags` tinyint UNSIGNED NOT NULL DEFAULT 0,
      `Comment` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL DEFAULT NULL,
      PRIMARY KEY (`PathId`) USING BTREE
    ) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_unicode_ci ROW_FORMAT = DYNAMIC;

    ALTER TABLE `waypoint_data` 
        CHANGE COLUMN `id` `PathId` int UNSIGNED NOT NULL DEFAULT 0 FIRST,
        CHANGE COLUMN `point` `NodeId` int UNSIGNED NOT NULL DEFAULT 0 AFTER `PathId`,
        CHANGE COLUMN `position_x` `PositionX` float NOT NULL DEFAULT 0 AFTER `NodeId`,
        CHANGE COLUMN `position_y` `PositionY` float NOT NULL DEFAULT 0 AFTER `PositionX`,
        CHANGE COLUMN `position_z` `PositionZ` float NOT NULL DEFAULT 0 AFTER `PositionY`,
        CHANGE COLUMN `orientation` `Orientation` float NULL DEFAULT NULL AFTER `PositionZ`,
        CHANGE COLUMN `delay` `Delay` int UNSIGNED NOT NULL DEFAULT 0 AFTER `Orientation`,
        CHANGE COLUMN `move_type` `MoveType` int NOT NULL DEFAULT 0 AFTER `Delay`,
        DROP COLUMN `wpguid`,
        DROP PRIMARY KEY,
        ADD PRIMARY KEY (`PathId`, `NodeId`) USING BTREE;
        
    RENAME TABLE `waypoint_data` TO `waypoint_path_node`;

    ALTER TABLE `creature_addon` CHANGE COLUMN `path_id` `PathId` int UNSIGNED NOT NULL DEFAULT 0 AFTER `guid`;
    ALTER TABLE `creature_template_addon` CHANGE COLUMN `path_id` `PathId` int UNSIGNED NOT NULL DEFAULT 0 AFTER `entry`;

    INSERT INTO `waypoint_path` (`PathId`, `Comment`) SELECT `PathId`, 'Migrated from refactor' FROM `waypoint_path_node` GROUP BY `PathId`;

    DELETE FROM `command` WHERE `name` IN('reload waypoint_data', 'reload waypoint_path');
    INSERT INTO `command` (`name`, `help`) VALUES 
    ('reload waypoint_path', 'Syntax: .reload waypoint_path will reload waypoint_path and waypoint_path_node tables.');
  END IF;
END;;

DELIMITER ;
CALL waypoint_data_refactor();

DROP PROCEDURE IF EXISTS waypoint_data_refactor;
