--
-- Table structure for table `creature_default_trainer`
--
DROP TABLE IF EXISTS `creature_default_trainer`;
CREATE TABLE `creature_default_trainer` (
  `CreatureId` int(11) UNSIGNED NOT NULL,
  `TrainerId` int(11) UNSIGNED NOT NULL DEFAULT '0',
  PRIMARY KEY (`CreatureId`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

UPDATE `creature_template` SET `ScriptName`='' WHERE `ScriptName`='npc_multi_profession_trainer';

--
-- Table structure for table `gossip_menu_option_action`
--
DROP TABLE IF EXISTS `gossip_menu_option_action`;
CREATE TABLE `gossip_menu_option_action` (
  `MenuId` int(11) UNSIGNED NOT NULL DEFAULT '0',
  `OptionIndex` int(11) UNSIGNED NOT NULL DEFAULT '0',
  `ActionMenuId` int(11) UNSIGNED NOT NULL DEFAULT '0',
  `ActionPoiId` int(11) UNSIGNED NOT NULL DEFAULT '0',
  PRIMARY KEY (`MenuId`,`OptionIndex`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
 
--
-- Table structure for table `gossip_menu_option_box`
--
DROP TABLE IF EXISTS `gossip_menu_option_box`;
CREATE TABLE `gossip_menu_option_box` (
  `MenuId` int(11) UNSIGNED NOT NULL DEFAULT '0',
  `OptionIndex` int(11) UNSIGNED NOT NULL DEFAULT '0',
  `BoxCoded` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `BoxMoney` int(11) UNSIGNED NOT NULL DEFAULT '0',
  `BoxText` text,
  `BoxBroadcastTextId` int(11) UNSIGNED NOT NULL DEFAULT '0',
  PRIMARY KEY (`MenuId`,`OptionIndex`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `gossip_menu_option_trainer`
--
DROP TABLE IF EXISTS `gossip_menu_option_trainer`;
CREATE TABLE `gossip_menu_option_trainer` (
  `MenuId` int(11) UNSIGNED NOT NULL DEFAULT '0',
  `OptionIndex` int(11) UNSIGNED NOT NULL DEFAULT '0',
  `TrainerId` int(11) UNSIGNED NOT NULL DEFAULT '0',
  PRIMARY KEY (`MenuId`,`OptionIndex`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
 
INSERT INTO `gossip_menu_option_action` SELECT `MenuID`,`OptionID`,`ActionMenuID`,`ActionPoiID` FROM `gossip_menu_option` WHERE `ActionMenuID`!=0 OR `ActionPoiID`!=0;
INSERT INTO `gossip_menu_option_box` SELECT `MenuID`,`OptionID`,`BoxCoded`,`BoxMoney`,`BoxText`,`BoxBroadcastTextID` FROM `gossip_menu_option` WHERE `BoxCoded`!=0 OR `BoxMoney`!=0 OR LENGTH(`BoxText`)>0;

ALTER TABLE `gossip_menu_option` DROP PRIMARY KEY;
ALTER TABLE `gossip_menu_option`
  CHANGE `MenuID` `MenuId` int(11) UNSIGNED NOT NULL DEFAULT '0' FIRST,
  CHANGE `OptionID` `OptionIndex` int(11) UNSIGNED NOT NULL DEFAULT '0' AFTER `MenuId`,
  CHANGE `OptionIcon` `OptionIcon` tinyint(3) UNSIGNED NOT NULL DEFAULT '0' AFTER `OptionIndex`,
  CHANGE `OptionText` `OptionText` text AFTER `OptionIcon`,
  CHANGE `OptionBroadcastTextID` `OptionBroadcastTextId` int(11) UNSIGNED NOT NULL DEFAULT '0' AFTER `OptionText`,
  CHANGE `OptionType` `OptionType` int(11) UNSIGNED NOT NULL DEFAULT '0' AFTER `OptionBroadcastTextId`,
  CHANGE `OptionNpcflag` `OptionNpcflag` bigint(20) UNSIGNED NOT NULL DEFAULT '0' AFTER `OptionType`,
  DROP `ActionMenuID`,
  DROP `ActionPoiID`,
  DROP `BoxCoded`,
  DROP `BoxMoney`,
  DROP `BoxText`,
  DROP `BoxBroadcastTextID`;
ALTER TABLE `gossip_menu_option` ADD PRIMARY KEY (`MenuId`,`OptionIndex`);

--
-- Table structure for table `trainer`
--
DROP TABLE IF EXISTS `trainer`;
CREATE TABLE `trainer` (
  `Id` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `Type` tinyint(2) UNSIGNED NOT NULL DEFAULT '2',
  `Requirement` mediumint(8) UNSIGNED NOT NULL DEFAULT '0',
  `Greeting` TEXT,
  `VerifiedBuild` SMALLINT (5) DEFAULT '0',
  PRIMARY KEY (`Id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
 
--
-- Table structure for table `trainer_locale`
--
DROP TABLE IF EXISTS `trainer_locale`;
CREATE TABLE `trainer_locale` (
  `Id` INT(10) UNSIGNED NOT NULL DEFAULT '0',
  `locale` VARCHAR(4) NOT NULL,
  `Greeting_lang` text,
  `VerifiedBuild` SMALLINT(5) DEFAULT '0',
  PRIMARY KEY (`Id`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
 
--
-- Table structure for table `trainer_spell`
--
DROP TABLE IF EXISTS `trainer_spell`;
CREATE TABLE `trainer_spell` (
  `TrainerId` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `SpellId` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `MoneyCost` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `ReqSkillLine` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `ReqSkillRank` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `ReqAbility1` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `ReqAbility2` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `ReqAbility3` int(10) UNSIGNED NOT NULL DEFAULT '0',
  `ReqLevel` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `VerifiedBuild` SMALLINT (5) DEFAULT '0',
  PRIMARY KEY (`TrainerId`,`SpellId`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `npc_trainer`;

DELETE FROM `command` WHERE `name` IN ('reload npc_trainer','reload trainer');
INSERT INTO `command` (`name`,`permission`,`help`) VALUES
('reload trainer', 672, 'Syntax: .reload trainer\nReloads trainer, trainer_locale and trainer_spell tables.');
