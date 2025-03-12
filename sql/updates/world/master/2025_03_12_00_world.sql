ALTER TABLE `creature_loot_template` ADD COLUMN `id` INT AUTO_INCREMENT PRIMARY KEY;

WITH CTE AS (
    SELECT
        `id`,
        `Entry`,
        `ItemType`,
        `Item`,
        ROW_NUMBER() OVER (PARTITION BY `Entry`, `ItemType`, `Item` ORDER BY `Chance` DESC) AS RowNum
    FROM `creature_loot_template`
)
DELETE FROM `creature_loot_template`
WHERE `id` IN (
    SELECT `id`
    FROM CTE
    WHERE RowNum > 1
);

ALTER TABLE `creature_loot_template` DROP COLUMN `id`;

ALTER TABLE `creature_loot_template` DROP INDEX `idx_primary`;

ALTER TABLE `creature_loot_template` ADD UNIQUE INDEX `idx_primary` (`Entry`, `ItemType`, `Item`);