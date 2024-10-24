--
SET FOREIGN_KEY_CHECKS=0;

DROP TABLE IF EXISTS `characters_npcbot`;
CREATE TABLE `characters_npcbot` (
  `entry` int(10) unsigned NOT NULL COMMENT 'creature_template.entry',
  `owner` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'characters.guid (lowguid)',
  `roles` smallint(5) unsigned NOT NULL COMMENT 'bitmask: tank(1),dps(2),heal(4),ranged(8)',
  `faction` int(10) unsigned NOT NULL DEFAULT '35',
  `equipMhEx` int(10) unsigned NOT NULL DEFAULT '0',
  `equipOhEx` int(10) unsigned NOT NULL DEFAULT '0',
  `equipRhEx` int(10) unsigned NOT NULL DEFAULT '0',
  `equipHead` int(10) unsigned NOT NULL DEFAULT '0',
  `equipShoulders` int(10) unsigned NOT NULL DEFAULT '0',
  `equipChest` int(10) unsigned NOT NULL DEFAULT '0',
  `equipWaist` int(10) unsigned NOT NULL DEFAULT '0',
  `equipLegs` int(10) unsigned NOT NULL DEFAULT '0',
  `equipFeet` int(10) unsigned NOT NULL DEFAULT '0',
  `equipWrist` int(10) unsigned NOT NULL DEFAULT '0',
  `equipHands` int(10) unsigned NOT NULL DEFAULT '0',
  `equipBack` int(10) unsigned NOT NULL DEFAULT '0',
  `equipBody` int(10) unsigned NOT NULL DEFAULT '0',
  `equipFinger1` int(10) unsigned NOT NULL DEFAULT '0',
  `equipFinger2` int(10) unsigned NOT NULL DEFAULT '0',
  `equipTrinket1` int(10) unsigned NOT NULL DEFAULT '0',
  `equipTrinket2` int(10) unsigned NOT NULL DEFAULT '0',
  `equipNeck` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`entry`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
