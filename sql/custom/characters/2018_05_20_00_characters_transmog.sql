SET @dbname = DATABASE();
SET @tablename = "item_instance";
SET @columnname = "transmog";
SET @preparedStatement = (SELECT IF(
  (
    SELECT COUNT(*) FROM INFORMATION_SCHEMA.COLUMNS
    WHERE
      (table_name = @tablename)
      AND (table_schema = @dbname)
      AND (column_name = @columnname)
  ) > 0,
  "SELECT 1",
  CONCAT("ALTER TABLE ", @tablename, " ADD ", @columnname, " INT UNSIGNED NOT NULL DEFAULT '0' AFTER `text`;")
));
PREPARE alterIfNotExists FROM @preparedStatement;
EXECUTE alterIfNotExists;
DEALLOCATE PREPARE alterIfNotExists;

UPDATE `item_instance` AS `ii` INNER JOIN `custom_transmogrification` AS `ct` ON  `ii`.`guid` = `ct`.`GUID` SET `transmog` = `FakeEntry`;
DROP TABLE IF EXISTS `custom_transmogrification`;