DROP PROCEDURE IF EXISTS apply_if_not_exists_2023_07_03_01_world;

DELIMITER ;;
CREATE PROCEDURE apply_if_not_exists_2023_07_03_01_world() BEGIN
  IF NOT EXISTS (SELECT * FROM `information_schema`.`columns` WHERE `table_schema`=SCHEMA() AND `table_name`='conversation_line_template' AND `column_name`='ChatType') THEN
    ALTER TABLE `conversation_line_template` ADD COLUMN `ChatType` tinyint UNSIGNED NOT NULL DEFAULT 0 AFTER `Flags`;
  END IF;
END;;

DELIMITER ;
CALL apply_if_not_exists_2023_07_03_01_world;

DROP PROCEDURE IF EXISTS apply_if_not_exists_2023_07_03_01_world;
