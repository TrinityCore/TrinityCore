-- 
DROP TABLE IF EXISTS `actionscript_assign`;
CREATE TABLE `actionscript_assign` (
    `spawnType` TINYINT UNSIGNED NOT NULL,
    `entry` INT UNSIGNED NOT NULL,
    `index` INT UNSIGNED NOT NULL,
    `scriptId` INT UNSIGNED NOT NULL,
    PRIMARY KEY USING BTREE (`spawnType`,`entry`,`index`)
);

DROP TABLE IF EXISTS `actionscript_data`;
