DELIMITER ;;
CREATE PROCEDURE characters_2026_01_28_00() BEGIN
  IF NOT EXISTS (SELECT * FROM `information_schema`.`columns` WHERE `table_schema`=SCHEMA() AND `table_name`='character_stats' AND `column_name`='spirit') THEN
    ALTER TABLE `character_stats` ADD `spirit` int unsigned NOT NULL DEFAULT '0' AFTER `intellect`;
  END IF;
END;;

DELIMITER ;
CALL characters_2026_01_28_00();

DROP PROCEDURE IF EXISTS characters_2026_01_28_00;
