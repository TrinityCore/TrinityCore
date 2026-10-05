DELIMITER ;;
CREATE PROCEDURE characters_2026_10_05_00() BEGIN
  IF EXISTS (SELECT * FROM `information_schema`.`table_constraints` WHERE `constraint_schema`=SCHEMA() AND `constraint_type`='PRIMARY KEY' AND `table_name`='item_loot_items') THEN
    ALTER TABLE `item_loot_items` DROP PRIMARY KEY;
  END IF;
END;;

DELIMITER ;
CALL characters_2026_10_05_00();

DROP PROCEDURE IF EXISTS characters_2026_10_05_00;

ALTER TABLE `item_loot_items` ADD PRIMARY KEY (`container_id`, `item_index`);
