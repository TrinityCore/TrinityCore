DROP TABLE IF EXISTS `instance_difficulty_multiplier`;
CREATE TABLE `instance_difficulty_multiplier`(
    `mapId` INT(10) UNSIGNED NOT NULL,
    `difficultyId` INT(10) UNSIGNED NOT NULL,
    `healthMultiplier` FLOAT NOT NULL DEFAULT 1,
    `damageMultiplier` FLOAT NOT NULL DEFAULT 1,
    PRIMARY KEY (`mapId`, `difficultyId`)
);


INSERT INTO `instance_difficulty_multiplier` (`mapId`, `difficultyId`, `healthMultiplier`, `damageMultiplier`) VALUES
(1841, 2,  1.29,  1.29),
(1841, 23, 1.612, 1.612);
