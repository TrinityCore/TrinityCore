ALTER TABLE `corpse` DROP `phaseMask`;

DROP TABLE IF EXISTS `corpse_phases`;
CREATE TABLE `corpse_phases` (
  `Guid` int(10) unsigned NOT NULL,
  `PhaseId` int(10) unsigned NOT NULL,
  PRIMARY KEY (`Guid`,`PhaseId`)
);
