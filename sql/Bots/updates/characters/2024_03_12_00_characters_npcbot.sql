--
/*!50003 DROP PROCEDURE IF EXISTS `sp__drop_column_if_exists`*/;
DELIMITER ;;
/*!50003 CREATE*/
/*!50003 PROCEDURE `sp__drop_column_if_exists`(`@TABLE` varchar(100), `@COLUMN` varchar(100))
BEGIN
DECLARE `@EXISTS` INT DEFAULT 0;
SELECT COUNT(*) INTO `@EXISTS` FROM `information_schema`.`columns`WHERE `TABLE_SCHEMA` = DATABASE() AND `TABLE_NAME` = `@TABLE` AND `COLUMN_NAME` = `@COLUMN`;
IF (`@EXISTS` > 0) THEN
    ALTER TABLE `characters_npcbot` DROP COLUMN `hire_time`;
END IF;
END */;;

DELIMITER ;

CALL `sp__drop_column_if_exists`('characters_npcbot', 'hire_time');

DROP PROCEDURE IF EXISTS `sp__drop_column_if_exists`;

ALTER TABLE `characters_npcbot` ADD `hire_time` timestamp NULL DEFAULT CURRENT_TIMESTAMP AFTER `faction`;
