
-- ----------------------------
-- Table structure for `spell`
-- ----------------------------
DROP TABLE IF EXISTS `spell`;
CREATE TABLE `spell` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `NameSubtext` text,
  `Description` text,
  `AuraDescription` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;


-- ----------------------------
-- Table structure for `spell_locale`
-- ----------------------------
DROP TABLE IF EXISTS `spell_locale`;
CREATE TABLE `spell_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `NameSubtext_Lang` text,
  `Description_Lang` text,
  `AuraDescription_Lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

