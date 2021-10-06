-- THIS SQL UPDATE HAS BEEN EDITED TO FIX MYSQL 5.7 COMPATIBILITY
-- ADD COLUMN IF NOT EXISTS
SET @dbname = DATABASE();
SET @preparedStatement = (SELECT IF(
  (
    SELECT COUNT(*) FROM INFORMATION_SCHEMA.COLUMNS
    WHERE
      (table_name = 'characters')
      AND (table_schema = @dbname)
      AND (column_name = 'createTime')
  ) > 0,
  "SELECT 'Skipped adding column, already exists.'",
  CONCAT("ALTER TABLE characters ADD `createTime` bigint(20) NOT NULL DEFAULT '0' AFTER `online`, ADD `createMode` tinyint(4) NOT NULL DEFAULT '0' AFTER `createTime`")
));
PREPARE alterIfNotExists FROM @preparedStatement;
EXECUTE alterIfNotExists;
DEALLOCATE PREPARE alterIfNotExists;

-- EDITED NOTE: updates safe to reapply unconditionally

 -- AT_LOGIN_FIRST: Characters that have never logged in have accurate creation timestamp in `logout_time`
UPDATE `characters` SET `createTime`=`logout_time` WHERE (`at_login` & 0x20) != 0;
 -- attempt to find lowest criteria timestamp for characters that have logged in already
UPDATE `characters` c
  INNER JOIN
  (
    SELECT cap.`guid` `guid`, COALESCE(MIN(cap.`date`), UNIX_TIMESTAMP()) `date`
    FROM `character_achievement_progress` cap
    GROUP BY cap.`guid`
  ) criteria ON criteria.`guid` = c.`guid`
  INNER JOIN
  (
    SELECT ca.`guid` `guid`, COALESCE(MIN(ca.`date`), UNIX_TIMESTAMP()) `date`
    FROM `character_achievement` ca
    GROUP BY ca.`guid`
  ) achievement ON achievement.`guid` = c.`guid` 
SET 
  `createTime` = IF(criteria.`date` < achievement.`date`,
    criteria.`date`,
    achievement.`date`)
WHERE
  (`at_login` & 0x20) = 0;
