/*
DROP TABLE IF EXISTS `spell_affect`;
CREATE TABLE `spell_affect` (
  `entry` smallint(5) unsigned NOT NULL default '0',
  `effectId` tinyint(3) unsigned NOT NULL default '0',
  `SpellId` smallint(5) unsigned NOT NULL default '0',
  `SchoolMask` tinyint(3) unsigned NOT NULL default '0',
  `Category` smallint(5) unsigned NOT NULL default '0',
  `SkillID` smallint(5) unsigned NOT NULL default '0',
  `SpellFamily` tinyint(3) unsigned NOT NULL default '0',
  `SpellFamilyMask` bigint(20) unsigned NOT NULL default '0',
  `Charges` smallint(5) unsigned NOT NULL default '0',
  PRIMARY KEY  (`entry`,`effectId`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
*/

DELETE FROM `spell_affect` WHERE `entry` IN (34936);
INSERT INTO `spell_affect` VALUES 
(34936,0,0,0,0,0,0,274877906945,1);
