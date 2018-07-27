DROP TABLE IF EXISTS `character_garrison_mission_rewards`;
CREATE TABLE `character_garrison_mission_rewards`(
    `dbId` INT(10) UNSIGNED NOT NULL,
    `type` TINYINT(3) UNSIGNED NOT NULL,
    `itemId` INT(10) NOT NULL DEFAULT 0,
    `itemQuantity` INT(10) UNSIGNED NOT NULL DEFAULT 0,
    `currencyId` INT(10) NOT NULL DEFAULT 0,
    `currencyQuantity` INT(10) UNSIGNED NOT NULL DEFAULT 0,
    `FollowerXP` INT(10) UNSIGNED NOT NULL DEFAULT 0,
    `BonusAbilityId` INT(10) UNSIGNED NOT NULL DEFAULT 0
);
