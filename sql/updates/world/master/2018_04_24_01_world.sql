--
-- Table structure for table `quest_greeting_locale`
--
DROP TABLE IF EXISTS `quest_greeting_locale`;
CREATE TABLE `quest_greeting_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `type` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Greeting` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`type`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
