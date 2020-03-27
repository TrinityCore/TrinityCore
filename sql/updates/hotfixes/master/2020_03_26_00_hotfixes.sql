--
-- Table structure for table `item_name_description`
--
DROP TABLE IF EXISTS `item_name_description`;
CREATE TABLE `item_name_description` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Description` text,
  `Color` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `item_name_description_locale`
--
DROP TABLE IF EXISTS `item_name_description_locale`;
CREATE TABLE `item_name_description_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Description_lang` text,
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
