DROP TABLE IF EXISTS `spell_areatrigger_rollpitchyaw`;
CREATE TABLE `spell_areatrigger_rollpitchyaw`(
    `SpellMiscId` INT(10) UNSIGNED NOT NULL,
    `X` FLOAT NOT NULL DEFAULT 0,
    `Y` FLOAT NOT NULL DEFAULT 0,
    `Z` FLOAT NOT NULL DEFAULT 0,
    `TargetX` FLOAT NOT NULL DEFAULT 0,
    `TargetY` FLOAT NOT NULL DEFAULT 0,
    `TargetZ` FLOAT NOT NULL DEFAULT 0,
    `VerifiedBuild` INT UNSIGNED NOT NULL DEFAULT 0,
    PRIMARY KEY (`SpellMiscId`)
);
