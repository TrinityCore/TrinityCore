ALTER TABLE `corpse` DROP `phaseMask`;

DROP TABLE IF EXISTS `corpse_phases`;
CREATE TABLE `corpse_phases` (
  `Guid` int(10) unsigned NOT NULL,
  `PhaseId` int(10) unsigned NOT NULL,
  `OwnerGuid` int(10) unsigned NOT NULL,
  `Time` int(10) unsigned NOT NULL DEFAULT '0',
  `CorpseType` tinyint(3) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`Guid`,`PhaseId`)
);
