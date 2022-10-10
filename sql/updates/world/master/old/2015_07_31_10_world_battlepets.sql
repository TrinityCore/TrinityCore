/*!40101 SET NAMES utf8 */;

DROP TABLE IF EXISTS `battle_pet_npc_team_member`;

CREATE TABLE `battle_pet_npc_team_member` (
  `npcEntry` mediumint(10) NOT NULL DEFAULT '0',
  `slot0` mediumint(10) NOT NULL DEFAULT '0',
  `slot1` mediumint(10) NOT NULL DEFAULT '0',
  `slot2` mediumint(10) NOT NULL DEFAULT '0',
  PRIMARY KEY (`npcEntry`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
