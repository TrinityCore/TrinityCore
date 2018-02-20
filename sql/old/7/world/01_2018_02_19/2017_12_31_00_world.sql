DELETE FROM `command` WHERE `name` IN ('debug send playerchoice');
INSERT INTO `command` (`name`,`permission`,`help`) VALUES
('debug send playerchoice', 869, 'Syntax: .debug send playerchoice $choiceId\r\nSend given choice to player.');

--
-- Table structure for table `playerchoice`
--
DROP TABLE IF EXISTS `playerchoice`;
CREATE TABLE `playerchoice` (
  `ChoiceId` int(11) NOT NULL,
  `Question` varchar(255),
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ChoiceId`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `playerchoice_locale`
--
DROP TABLE IF EXISTS `playerchoice_locale`;
CREATE TABLE `playerchoice_locale` (
  `ChoiceId` int(11) NOT NULL,
  `locale` varchar(4) NOT NULL,
  `Question` varchar(255),
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ChoiceId`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `playerchoice_response`
--
DROP TABLE IF EXISTS `playerchoice_response`;
CREATE TABLE `playerchoice_response` (
  `ChoiceId` int(11) NOT NULL,
  `ResponseId` int(11) NOT NULL,
  `Index` int(10) UNSIGNED NOT NULL,
  `ChoiceArtFileId` int(11) NOT NULL DEFAULT '0',
  `Header` varchar(511) NOT NULL,
  `Answer` varchar(511) NOT NULL,
  `Description` varchar(2047) NOT NULL,
  `Confirmation` varchar(127) NOT NULL,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ChoiceId`,`ResponseId`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `playerchoice_response_locale`
--
DROP TABLE IF EXISTS `playerchoice_response_locale`;
CREATE TABLE `playerchoice_response_locale` (
  `ChoiceId` int(11) NOT NULL,
  `ResponseId` int(11) NOT NULL,
  `locale` varchar(4) NOT NULL,
  `Header` varchar(511) NOT NULL DEFAULT '',
  `Answer` varchar(511) NOT NULL DEFAULT '',
  `Description` varchar(2047) NOT NULL DEFAULT '',
  `Confirmation` varchar(127) NOT NULL DEFAULT '',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ChoiceID`,`ResponseID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `playerchoice_response_reward`
--
DROP TABLE IF EXISTS `playerchoice_response_reward`;
CREATE TABLE `playerchoice_response_reward` (
  `ChoiceId` int(11) NOT NULL,
  `ResponseId` int(11) NOT NULL,
  `TitleId` int(11) NOT NULL DEFAULT '0',
  `PackageId` int(11) NOT NULL DEFAULT '0',
  `SkillLineId` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `SkillPointCount` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `ArenaPointCount` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `HonorPointCount` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Money` bigint(20) UNSIGNED NOT NULL DEFAULT '0',
  `Xp` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ChoiceId`, `ResponseId`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `playerchoice_response_reward_currency`
--
DROP TABLE IF EXISTS `playerchoice_response_reward_currency`;
CREATE TABLE `playerchoice_response_reward_currency` (
  `ChoiceId` int(11) NOT NULL,
  `ResponseId` int(11) NOT NULL,
  `Index` int(10) UNSIGNED NOT NULL,
  `CurrencyId` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Quantity` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ChoiceId`, `ResponseId`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `playerchoice_response_reward_faction`
--
DROP TABLE IF EXISTS `playerchoice_response_reward_faction`;
CREATE TABLE `playerchoice_response_reward_faction` (
  `ChoiceId` int(11) NOT NULL,
  `ResponseId` int(11) NOT NULL,
  `Index` int(10) UNSIGNED NOT NULL,
  `FactionId` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Quantity` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ChoiceId`, `ResponseId`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `playerchoice_response_reward_item`
--
DROP TABLE IF EXISTS `playerchoice_response_reward_item`;
CREATE TABLE `playerchoice_response_reward_item` (
  `ChoiceId` int(11) NOT NULL,
  `ResponseId` int(11) NOT NULL,
  `Index` int(10) UNSIGNED NOT NULL,
  `ItemId` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `BonusListIDs` text,
  `Quantity` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ChoiceId`, `ResponseId`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
