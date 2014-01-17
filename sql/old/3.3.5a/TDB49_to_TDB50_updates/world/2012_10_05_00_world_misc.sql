/*!40101 SET NAMES utf8 */;

/*!40101 SET SQL_MODE=''*/;

/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;
/* Table structure for table `lfg_entrance` */

DROP TABLE IF EXISTS `lfg_entrances`;

CREATE TABLE `lfg_entrances` (
  `dungeonId` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Unique id from LFGDungeons.dbc',
  `name` varchar(255) DEFAULT NULL,
  `position_x` float NOT NULL DEFAULT '0',
  `position_y` float NOT NULL DEFAULT '0',
  `position_z` float NOT NULL DEFAULT '0',
  `orientation` float NOT NULL DEFAULT '0',
  PRIMARY KEY (`dungeonId`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;


-- only The Frost Lord Ahune and The Crown Chemical Co. were taken from sniffs, others from areatrigger_teleport or guessed
-- TODO: replace them by sniffed positions and probably use this table for all dungeons instead of areatrigger_teleport
-- note: this table should be used more in Cataclysm and Mists of Pandaria (there will be all events like Zalazane's Fall and scenarios)
DELETE FROM `lfg_entrances`;
INSERT INTO `lfg_entrances` (`dungeonId`,`name`,`position_x`,`position_y`,`position_z`,`orientation`) VALUES
(18,'Scarlet Monastery - Graveyard',1688.99,1053.48,18.6775,0.00117),
(26,'Maraudon - Orange Crystals',1019.69,-458.31,-43.43,0.31),
(34,'Dire Maul - East',44.4499,-154.822,-2.71201,0),
(36,'Dire Maul - West',-62.9658,159.867,-3.46206,3.14788),
(38,'Dire Maul - North',255.249,-16.0561,-2.58737,4.7),
(40,'Stratholme - Main Gate',3395.09,-3380.25,142.702,0.1),
(163,'Scarlet Monastery - Armory',1610.83,-323.433,18.6738,6.28022),
(164,'Scarlet Monastery - Cathedral',855.683,1321.5,18.6709,0.001747),
(165,'Scarlet Monastery - Library',255.346,-209.09,18.6773,6.26656),
(272,'Maraudon - Purple Crystals',752.91,-616.53,-33.11,1.37),
(273,'Maraudon - Pristine Waters',495.701904,17.337202,-96.31284,3.118538), -- guessed
(274,'Stratholme - Service Entrance',3593.15,-3646.56,138.5,5.33),
(285,'The Headless Horseman',1797.517212,1347.381104,18.8876,3.142), -- guessed
(286,'The Frost Lord Ahune',-100.396,-95.9996,-4.28423,4.712389),
(287,'Coren Direbrew',897.494995,-141.976349,-49.7563,2.125502), -- guessed
(288,'The Crown Chemical Co.',-238.075,2166.43,88.853,1.134464);

DELETE FROM `lfg_dungeon_rewards` WHERE `dungeonId` BETWEEN 285 AND 288;
INSERT INTO `lfg_dungeon_rewards` (`dungeonId`,`maxLevel`,`firstQuestId`,`firstMoneyVar`,`firstXPVar`,`otherQuestId`,`otherMoneyVar`,`otherXPVar`) VALUES
(285,80,25482,0,0,0,0,0),
(286,80,25484,0,0,0,0,0),
(287,80,25483,0,0,0,0,0),
(288,80,25485,0,0,0,0,0);

UPDATE `quest_template` SET `SpecialFlags`=`SpecialFlags`|8|1 WHERE `Id` IN (25482,25483,25484,25485);
