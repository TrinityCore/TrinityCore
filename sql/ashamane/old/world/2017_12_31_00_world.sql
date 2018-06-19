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

INSERT INTO playerchoice VALUES (231, "Which demon hunter specialization do you want to learn?", 25549);

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

INSERT INTO playerchoice_locale VALUES (231, "frFR", "Quelle spécialisation de chasseur de démons voulez-vous apprendre ?", 25549);

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

INSERT INTO playerchoice_response VALUES
(231, 478, 0, 1274664, "Devastation", "Devastation", "Continue your mastery of Havoc.

Havos specialized demon hunters can use Metamorphosis to turn into winged demons. They focus on Melee DPS.

Choosing Havoc grants |cFFFF0000|Hspell:162264|h[Metamorphosis]|h|r as well as |cFFFF0000|Hspell:185164|h[Mastery: Furious Havoc]|h|r.", "", 25549),
(231, 479, 1, 1274665, "Vengeance", "Vengeance", "Change to mastery of Vengeance.

Vengeance specialized demon hunters can use Metamorphosis to turn into spiked demons. They focus on Tanking.

Choosing Vengeance grants |cFFFF0000|Hspell:187827|h[Metamorphosis]|h|r as well as |cFFFF0000|Hspell:203747|h[Mastery: Fel Blood]|h|r.

Your |cFFFF0000|Hspell:193921|h[Eye Beam]|h|r will change into |cFFFF0000|Hspell:203720|h[Demon Spikes]|h|r.", "", 25549);

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

INSERT INTO playerchoice_response_locale VALUES
(231, 478, "frFR", "Dévastation", "Dévastation", "Conserver votre spécialisation : Dévastation.

Les chasseurs de démons Dévastation peuvent utiliser Métamorphose pour se transformer en démons ailés. Ils se concentrent sur les dégâts en mêlée.

Choisir Dévastation confère |cFFFF0000|Hspell:162264|h[Métamorphose]|h|r et |cFFFF0000|Hspell:185164|h[Maîtrise : Présence démoniaque]|h|r.", "", 25549),
(231, 479, "frFR", "Vengeance", "Vengeance", "Changer de spécialisation : Vengeance.

Les chasseurs de démons Vengeance peuvent utiliser Métamorphose pour se transformer en démons couverts de pointes. Ils se concentrent sur le rôle de tank.

Choisir Vengeance confère |cFFFF0000|Hspell:187827|h[Métamorphose]|h|r et |cFFFF0000|Hspell:203747|h[Maîtrise : Gangresang]|h|r.

Votre technique |cFFFF0000|Hspell:193921|h[Rayon accablant]|h|r est remplacée par |cFFFF0000|Hspell:203720|h[Pointes démoniaques]|h|r.", "", 25549);

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

INSERT INTO playerchoice_response_reward VALUES
(231, 478, 0, 0, 0, 0, 0, 0, 0, 0, 25549),
(231, 479, 0, 0, 0, 0, 0, 0, 0, 0, 25549);

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
