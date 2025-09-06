-- append guid as hex to characters who have duplicate names in database except the one with lowest guid (assumed to have been created first)
-- and flag them for rename
CREATE TEMPORARY TABLE `characters_to_rename` SELECT
    c2.`guid`
  FROM
    (
      SELECT
        c1.`name` AS `name`,
        MIN(c1.`guid`) AS originalGuid
      FROM
        `characters` c1 
      WHERE
        LENGTH(c1.`name`) > 0 
      GROUP BY
        1 
      HAVING
        COUNT(*) > 1
    ) c3
    INNER JOIN `characters` c2 ON c3.`name` = c2.`name`
  WHERE
    c2.guid <> c3.originalGuid;

UPDATE `characters` SET `name` = CONCAT(SUBSTRING(`name` FROM 1 FOR 12 - LENGTH(CONV(`guid`, 10, 16))), CONV(`guid`, 10, 16)), `at_login` = `at_login` | 1 WHERE `guid` IN (SELECT `guid` FROM `characters_to_rename`);

-- recreate name index with unique constraint
ALTER TABLE `characters` DROP INDEX `idx_name`;
ALTER TABLE `characters` MODIFY COLUMN `name` varchar(12) CHARACTER SET utf8mb4 COLLATE utf8mb4_bin NULL AFTER `account`;
UPDATE `characters` SET `name` = NULL WHERE `name` = '';
ALTER TABLE `characters` ADD UNIQUE INDEX `idx_name` (`name` ASC);
