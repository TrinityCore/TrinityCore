DROP TABLE IF EXISTS `locales_quest`;

DROP TABLE IF EXISTS `quest_template_locale`;
CREATE TABLE IF NOT EXISTS `quest_template_locale` (
  `ID` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0',
  `locale` VARCHAR(4) NOT NULL,
  `LogTitle` TEXT,
  `LogDescription` TEXT,
  `QuestDescription` TEXT,
  `AreaDescription` TEXT,
  `PortraitGiverText` TEXT,
  `PortraitGiverName` TEXT,
  `PortraitTurnInText` TEXT,
  `PortraitTurnInName` TEXT,
  `QuestCompletionLog` TEXT,
  `VerifiedBuild` SMALLINT(5) DEFAULT '0'
) ENGINE=MYISAM DEFAULT CHARSET=utf8;

ALTER TABLE `quest_template_locale`
 ADD PRIMARY KEY (`ID`,`locale`);

DROP TABLE IF EXISTS `quest_objectives_locale`;
CREATE TABLE IF NOT EXISTS `quest_objectives_locale` (
  `ID` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0',
  `locale` VARCHAR(4) NOT NULL,
  `QuestId` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0',
  `StorageIndex` TINYINT(3) NOT NULL DEFAULT '0',
  `Description` TEXT,
  `VerifiedBuild` SMALLINT(5) DEFAULT '0'
) ENGINE=MYISAM DEFAULT CHARSET=utf8;

ALTER TABLE `quest_objectives_locale`
 ADD PRIMARY KEY (`ID`,`locale`);
