--
-- Table structure for table `spell_visual_kit`
--
DROP TABLE IF EXISTS `spell_visual_kit`;
CREATE TABLE `spell_visual_kit` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags` int(11) NOT NULL DEFAULT '0',
  `FallbackPriority` tinyint(3) NOT NULL DEFAULT '0',
  `FallbackSpellVisualKitId` int(11) unsigned NOT NULL DEFAULT '0',
  `DelayMin` smallint(5) unsigned NOT NULL DEFAULT '0',
  `DelayMax` smallint(5) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
