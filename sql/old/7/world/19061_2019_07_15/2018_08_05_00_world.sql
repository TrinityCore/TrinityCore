DROP TABLE IF EXISTS `spell_areatrigger_circular`;
CREATE TABLE `spell_areatrigger_circular`(
  `SpellMiscId` INT(10) UNSIGNED NOT NULL,
  `StartDelay` INT(10) UNSIGNED NOT NULL DEFAULT 0,
  `CircleRadius` FLOAT NOT NULL DEFAULT 0,
  `BlendFromRadius` FLOAT NOT NULL DEFAULT 0,
  `InitialAngle` FLOAT NOT NULL DEFAULT 0,
  `ZOffset` FLOAT NOT NULL DEFAULT 0,
  `CounterClockwise` TINYINT(3) UNSIGNED NOT NULL DEFAULT 0,
  `CanLoop` TINYINT(3) UNSIGNED NOT NULL DEFAULT 0,
  `VerifiedBuild` INT(10) UNSIGNED NOT NULL DEFAULT 0,
  PRIMARY KEY (`SpellMiscId`)
);
