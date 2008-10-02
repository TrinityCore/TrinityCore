/* for reference
DROP TABLE IF EXISTS `spell_proc_event`;
CREATE TABLE `spell_proc_event` (
  `entry` smallint(6) unsigned NOT NULL default '0',
  `SchoolMask` tinyint(4) NOT NULL default '0',
  `Category` smallint(6) NOT NULL default '0',
  `SkillID` smallint(6) NOT NULL default '0',
  `SpellFamilyName` smallint(6) unsigned NOT NULL default '0',
  `SpellFamilyMask` bigint(40) unsigned NOT NULL default '0',
  `procFlags` int(11) unsigned NOT NULL default '0',
  `ppmRate` float NOT NULL default '0',
  PRIMARY KEY  (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
*/

DELETE FROM `spell_proc_event` WHERE `entry` IN ( 30675, 30678, 30679, 30680, 30681 );
INSERT INTO `spell_proc_event` VALUES 
(30675,0,0,0,11,3,16384,0),
(30678,0,0,0,11,3,16384,0),
(30679,0,0,0,11,3,16384,0),
(30680,0,0,0,11,3,16384,0),
(30681,0,0,0,11,3,16384,0);

