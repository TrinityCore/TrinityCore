
DROP PROCEDURE IF EXISTS apply_if_not_exists_9999_99_99_99_world;

DELIMITER ;;
CREATE PROCEDURE apply_if_not_exists_9999_99_99_99_world() BEGIN
  IF NOT EXISTS (SELECT * FROM `information_schema`.`columns` WHERE `table_schema`=SCHEMA() AND `table_name`='creature_summoned_data' AND `column_name`='QuestsToDespawnOnQuestRemove') THEN
    ALTER TABLE `creature_summoned_data` ADD COLUMN `QuestsToDespawnOnQuestRemove` mediumtext CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `FlyingMountDisplayID`;
  END IF;
END;;

DELIMITER ;
CALL apply_if_not_exists_9999_99_99_99_world;

DROP PROCEDURE IF EXISTS apply_if_not_exists_9999_99_99_99_world;
