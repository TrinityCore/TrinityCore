--
-- Table structure for table `artifact_tier`
--
DROP TABLE IF EXISTS `artifact_tier`;
CREATE TABLE `artifact_tier` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `ArtifactTier` int(10) unsigned NOT NULL DEFAULT '0',
  `MaxNumTraits` int(10) unsigned NOT NULL DEFAULT '0',
  `MaxArtifactKnowledge` int(10) unsigned NOT NULL DEFAULT '0',
  `KnowledgePlayerCondition` int(10) unsigned NOT NULL DEFAULT '0',
  `MinimumEmpowerKnowledge` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `artifact_unlock`
--
DROP TABLE IF EXISTS `artifact_unlock`;
CREATE TABLE `artifact_unlock` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemBonusListID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `PowerRank` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `PowerID` int(10) unsigned NOT NULL DEFAULT '0',
  `PlayerConditionID` int(10) unsigned NOT NULL DEFAULT '0',
  `ArtifactID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
