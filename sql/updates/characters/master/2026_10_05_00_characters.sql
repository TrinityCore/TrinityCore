DROP PROCEDURE IF EXISTS characters_2026_10_05_00;

DELIMITER ;;
CREATE PROCEDURE characters_2026_10_05_00() BEGIN
  IF EXISTS (SELECT * FROM `information_schema`.`table_constraints` WHERE `constraint_schema`=SCHEMA() AND `constraint_type`='PRIMARY KEY' AND `table_name`='item_loot_items') THEN
    ALTER TABLE `item_loot_items` DROP PRIMARY KEY;
  END IF;
END;;

DELIMITER ;
CALL characters_2026_10_05_00();

DROP PROCEDURE IF EXISTS characters_2026_10_05_00;

ALTER TABLE `item_loot_items` 
  ADD COLUMN `temp_id` int NOT NULL AUTO_INCREMENT,
  ADD PRIMARY KEY (`temp_id`);

UPDATE `item_loot_items` `ili`
INNER JOIN (SELECT `temp_id`, ROW_NUMBER() OVER (PARTITION BY `container_id` ORDER BY `item_index`, `item_id`) AS `new_index` FROM `item_loot_items`) `params` ON `ili`.`temp_id` = `params`.`temp_id`
SET `ili`.`item_index` = `params`.`new_index` - 1;

ALTER TABLE `item_loot_items`
  DROP PRIMARY KEY,
  DROP COLUMN `temp_id`;

ALTER TABLE `item_loot_items` ADD PRIMARY KEY (`container_id`, `item_index`);
