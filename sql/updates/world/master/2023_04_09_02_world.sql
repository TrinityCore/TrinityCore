DROP PROCEDURE IF EXISTS apply_if_exists_2023_04_09_02_world;

DELIMITER ;;
CREATE PROCEDURE apply_if_exists_2023_04_09_02_world() BEGIN
  IF EXISTS (SELECT * FROM `information_schema`.`columns` WHERE `table_schema`=SCHEMA() AND `table_name`='creature_template' AND `column_name`='HoverHeight') THEN
    ALTER TABLE `creature_template` DROP COLUMN `HoverHeight`;
  END IF;
END;;

DELIMITER ;
CALL apply_if_exists_2023_04_09_02_world();

DROP PROCEDURE IF EXISTS apply_if_exists_2023_04_09_02_world;
