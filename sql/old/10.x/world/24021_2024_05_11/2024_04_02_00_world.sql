DELIMITER ;;
CREATE PROCEDURE waypoint_path_velocity_2024_04_02_00() BEGIN
    IF NOT EXISTS (SELECT * FROM `information_schema`.`columns` WHERE `table_schema`=SCHEMA() AND `table_name`='waypoint_path' AND `column_name`='Velocity') THEN

    ALTER TABLE `waypoint_path` 
       ADD COLUMN `Velocity` float NULL DEFAULT NULL AFTER `Flags`;

    END IF;
END;;

DELIMITER ;
CALL waypoint_path_velocity_2024_04_02_00();

DROP PROCEDURE IF EXISTS waypoint_path_velocity_2024_04_02_00;

UPDATE `waypoint_path` SET `Velocity`=4.0 WHERE `PathId`=9301100;
UPDATE `waypoint_path` SET `Velocity`=35.0 WHERE `PathId` IN(11432300, 11432301, 11432302, 11432303, 11432304);
