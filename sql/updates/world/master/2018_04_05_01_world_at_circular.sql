DROP TABLE IF EXISTS `spell_areatrigger_circular`;
CREATE TABLE `spell_areatrigger_circular`(
    `SpellMiscId` INT(10) UNSIGNED NOT NULL,
    `CircleRadius` FLOAT NOT NULL DEFAULT 0,
    `BlendFromRadius` FLOAT NOT NULL DEFAULT 0,
    `InitialAngle` FLOAT NOT NULL DEFAULT 0,
    `ZOffset` FLOAT NOT NULL DEFAULT 0,
    `CounterClockwise` TINYINT(3) UNSIGNED NOT NULL DEFAULT 0,
    `CanLoop` TINYINT(3) UNSIGNED NOT NULL DEFAULT 0,
    `VerifiedBuild` INT(10) UNSIGNED NOT NULL DEFAULT 0,
    PRIMARY KEY (`SpellMiscId`)
);

DELETE FROM `spell_areatrigger` WHERE `SpellMiscId` = 5016;
INSERT INTO `spell_areatrigger` (`SpellMiscId`, `AreaTriggerId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `VerifiedBuild`) VALUES 
(5016, 10407, 26, 31636, 21000, 25996);

DELETE FROM `spell_areatrigger_circular` WHERE `SpellMiscId` = 5016; 
INSERT INTO `spell_areatrigger_circular` (`SpellMiscId`, `CircleRadius`, `BlendFromRadius`, `InitialAngle`, `CanLoop`, `VerifiedBuild`) VALUES 
(5016, 12.27271, 12.27271, 2.286397, 1, 25996);
