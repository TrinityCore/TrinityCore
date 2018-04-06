DROP TABLE IF EXISTS `spell_areatrigger_circular`;
CREATE TABLE `spell_areatrigger_circular`(
    `SpellMiscId` INT(10) UNSIGNED NOT NULL,
    `CircleRadius` FLOAT NOT NULL DEFAULT 0,
    `BlendFromRadius` FLOAT NOT NULL DEFAULT 0,
    `InitialAngle` FLOAT NOT NULL DEFAULT 0,
    `ZOffset` FLOAT NOT NULL DEFAULT 0,
    `CounterClockWise` TINYINT(3) NOT NULL DEFAULT 0,
    `CanLoop` TINYINT(3) NOT NULL DEFAULT 0,
    `VerifiedBuild` INT(10) NOT NULL DEFAULT 0,
    PRIMARY KEY (`SpellMiscId`)
);

DELETE FROM `spell_areatrigger` WHERE SpellMiscId = 5016;
INSERT INTO `spell_areatrigger` VALUES (5016, 10407, 0, 0, 0, 0, 26, 31636, 21000, 25996);

INSERT INTO `spell_areatrigger_circular` VALUES (5016, 12.27271, 12.27271, 2.286397, 0, 0, 1, 25996);
