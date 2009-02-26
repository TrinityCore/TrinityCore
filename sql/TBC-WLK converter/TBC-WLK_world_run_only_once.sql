DROP TABLE IF EXISTS `achievement_reward`;
CREATE TABLE `achievement_reward` (
  `entry` mediumint(8) unsigned NOT NULL default '0',
  `title_A` mediumint(8) unsigned NOT NULL default '0',
  `title_H` mediumint(8) unsigned NOT NULL default '0',
  `item` mediumint(8) unsigned NOT NULL default '0',
  `sender` mediumint(8) unsigned NOT NULL default '0',
  `subject` varchar(255) default NULL,
  `text` text,
  PRIMARY KEY  (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Loot System';


DROP TABLE IF EXISTS `locales_achievement_reward`;
CREATE TABLE `locales_achievement_reward` (
  `entry` mediumint(8) unsigned NOT NULL default '0',
  `subject_loc1` varchar(100) NOT NULL default '',
  `subject_loc2` varchar(100) NOT NULL default '',
  `subject_loc3` varchar(100) NOT NULL default '',
  `subject_loc4` varchar(100) NOT NULL default '',
  `subject_loc5` varchar(100) NOT NULL default '',
  `subject_loc6` varchar(100) NOT NULL default '',
  `subject_loc7` varchar(100) NOT NULL default '',
  `subject_loc8` varchar(100) NOT NULL default '',
  `text_loc1` text default NULL,
  `text_loc2` text default NULL,
  `text_loc3` text default NULL,
  `text_loc4` text default NULL,
  `text_loc5` text default NULL,
  `text_loc6` text default NULL,
  `text_loc7` text default NULL,
  `text_loc8` text default NULL,
  PRIMARY KEY  (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

TRUNCATE `creature_equip_template`;
ALTER TABLE `creature_equip_template`
    DROP COLUMN `equipinfo1`,
    DROP COLUMN `equipinfo2`,
    DROP COLUMN `equipinfo3`,
    DROP COLUMN `equipslot1`,
    DROP COLUMN `equipslot2`,
    DROP COLUMN `equipslot3`,
    CHANGE COLUMN `equipmodel1` `equipentry1` mediumint(8) UNSIGNED default '0' NOT NULL,
    CHANGE COLUMN `equipmodel2` `equipentry2` mediumint(8) UNSIGNED default '0' NOT NULL,
    CHANGE COLUMN `equipmodel3` `equipentry3` mediumint(8) UNSIGNED default '0' NOT NULL;
UPDATE `creature_template` set equipment_id = 0;

ALTER TABLE `item_template`
    ADD COLUMN `ScalingStatDistribution` smallint(6) DEFAULT '0' NOT NULL after `stat_value10`,
    ADD COLUMN `ScalingStatValue` smallint(6) DEFAULT '0' NOT NULL after `ScalingStatDistribution`,
    ADD COLUMN `ItemLimitCategory` smallint(6) DEFAULT '0' NOT NULL after `ArmorDamageModifier`,
    CHANGE COLUMN `Duration` `Duration` int(11) NOT NULL default '0' COMMENT 'Duration in seconds. Negative value means realtime, postive value ingame time' after ArmorDamageModifier,
    ADD COLUMN `StatsCount` tinyint(3) UNSIGNED DEFAULT '0' NOT NULL after `ContainerSlots`,
    CHANGE COLUMN `TotemCategory` `TotemCategory` mediumint(9) NOT NULL default '0';

UPDATE `item_template`
    SET `maxcount`=0 WHERE `maxcount` > 32000;
UPDATE `item_template`
    SET `stackable`=0 WHERE `stackable` > 32000;
ALTER TABLE `item_template`
    CHANGE COLUMN `maxcount` `maxcount` smallint(5) NOT NULL default '-1',
    CHANGE COLUMN `stackable` `stackable` smallint(5) NOT NULL default '1';
UPDATE `item_template`
    SET `stackable`=-1 WHERE `stackable` = 0;	

ALTER TABLE `quest_template`
    ADD COLUMN `PlayersSlain` tinyint(3) UNSIGNED DEFAULT '0' NOT NULL after `CharTitleId`,
    ADD COLUMN `BonusTalents` tinyint(3) UNSIGNED DEFAULT '0' NOT NULL after `PlayersSlain`,
    CHANGE COLUMN `RewHonorableKills` `RewHonorableKills` int unsigned NOT NULL default '0';
    
DROP TABLE IF EXISTS `milling_loot_template`;
CREATE TABLE `milling_loot_template` (
  `entry` mediumint(8) unsigned NOT NULL default '0',
  `item` mediumint(8) unsigned NOT NULL default '0',
  `ChanceOrQuestChance` float NOT NULL default '100',
  `groupid` tinyint(3) unsigned NOT NULL default '0',
  `mincountOrRef` mediumint(9) NOT NULL default '1',
  `maxcount` tinyint(3) unsigned NOT NULL default '1',
  `lootcondition` tinyint(3) unsigned NOT NULL default '0',
  `condition_value1` mediumint(8) unsigned NOT NULL default '0',
  `condition_value2` mediumint(8) unsigned NOT NULL default '0',
  PRIMARY KEY  (`entry`,`item`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Loot System';

DROP TABLE IF EXISTS `spell_affect`;
CREATE TABLE `spell_affect` (
  `entry` smallint(5) unsigned NOT NULL default '0',
  `effectId` tinyint(3) unsigned NOT NULL default '0',
  `SpellClassMask0` int(5) unsigned NOT NULL default '0',
  `SpellClassMask1` int(5) unsigned NOT NULL default '0',
  `SpellClassMask2` int(5) unsigned NOT NULL default '0',
  PRIMARY KEY  (`entry`,`effectId`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

ALTER TABLE `skill_discovery_template`
   DROP PRIMARY KEY,
   ADD PRIMARY KEY (`spellId`,`reqSpell`),
   ADD COLUMN `reqClass` tinyint(2) unsigned NOT NULL default '0' COMMENT 'class requirement' AFTER reqSpell;
ALTER TABLE skill_discovery_template
   DROP COLUMN `reqClass`,
   ADD COLUMN `reqSkillValue` smallint(5) unsigned NOT NULL default '0' COMMENT 'skill points requirement' AFTER reqSpell;
   
DROP TABLE IF EXISTS `player_classlevelstats`;
CREATE TABLE `player_classlevelstats` (
  `class` tinyint(3) unsigned NOT NULL,
  `level` tinyint(3) unsigned NOT NULL,
  `basehp` smallint(5) unsigned NOT NULL,
  `basemana` smallint(5) unsigned NOT NULL,
  PRIMARY KEY  (`class`,`level`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 PACK_KEYS=0 COMMENT='Stores levels stats.';

DROP TABLE IF EXISTS `player_levelstats`;
CREATE TABLE `player_levelstats` (
  `race` tinyint(3) unsigned NOT NULL,
  `class` tinyint(3) unsigned NOT NULL,
  `level` tinyint(3) unsigned NOT NULL,
  `str` tinyint(3) unsigned NOT NULL,
  `agi` tinyint(3) unsigned NOT NULL,
  `sta` tinyint(3) unsigned NOT NULL,
  `inte` tinyint(3) unsigned NOT NULL,
  `spi` tinyint(3) unsigned NOT NULL,
  PRIMARY KEY  (`race`,`class`,`level`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 PACK_KEYS=0 COMMENT='Stores levels stats.';

DROP TABLE IF EXISTS `playercreateinfo_spell`;
CREATE TABLE `playercreateinfo_spell` (
  `race` tinyint(3) unsigned NOT NULL default '0',
  `class` tinyint(3) unsigned NOT NULL default '0',
  `Spell` mediumint(8) unsigned NOT NULL default '0',
  `Note` varchar(255) default NULL,
  PRIMARY KEY  (`race`,`class`,`Spell`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `playercreateinfo_action`;
CREATE TABLE `playercreateinfo_action` (
  `race` tinyint(3) unsigned NOT NULL default '0',
  `class` tinyint(3) unsigned NOT NULL default '0',
  `button` smallint(5) unsigned NOT NULL default '0',
  `action` smallint(5) unsigned NOT NULL default '0',
  `type` smallint(5) unsigned NOT NULL default '0',
  `misc` smallint(5) unsigned NOT NULL default '0',
  KEY `playercreateinfo_race_class_index` (`race`,`class`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `spell_learn_spell`;
CREATE TABLE `spell_learn_spell` (
  `entry` smallint(5) unsigned NOT NULL default '0',
  `SpellID` smallint(5) unsigned NOT NULL default '0',
  `Active` tinyint(3) unsigned NOT NULL default '1',
  PRIMARY KEY  (`entry`,`SpellID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Item System';

DROP TABLE IF EXISTS `spell_proc_event`;
CREATE TABLE `spell_proc_event` (
  `entry` smallint(5) unsigned NOT NULL default '0',
  `SchoolMask` tinyint(4) NOT NULL default '0',
  `SpellFamilyName` smallint(5) unsigned NOT NULL default '0',
  `SpellFamilyMask0` int(10) unsigned NOT NULL default '0',
  `SpellFamilyMask1` int(10) unsigned NOT NULL default '0',
  `SpellFamilyMask2` int(10) unsigned NOT NULL default '0',
  `procFlags` int(10) unsigned NOT NULL default '0',
  `procEx` int(10) unsigned NOT NULL default '0',
  `ppmRate` float NOT NULL default '0',
  `CustomChance` float NOT NULL default '0',
  `Cooldown` int(10) unsigned NOT NULL default '0',
  PRIMARY KEY  (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `player_xp_for_level`;
CREATE TABLE `player_xp_for_level` (
  `lvl` int(3) unsigned NOT NULL,
  `xp_for_next_level` int(10) unsigned NOT NULL,
  PRIMARY KEY  (`lvl`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `spell_loot_template`;
CREATE TABLE `spell_loot_template` (
  `entry` mediumint(8) unsigned NOT NULL default '0',
  `item` mediumint(8) unsigned NOT NULL default '0',
  `ChanceOrQuestChance` float NOT NULL default '100',
  `groupid` tinyint(3) unsigned NOT NULL default '0',
  `mincountOrRef` mediumint(9) NOT NULL default '1',
  `maxcount` tinyint(3) unsigned NOT NULL default '1',
  `lootcondition` tinyint(3) unsigned NOT NULL default '0',
  `condition_value1` mediumint(8) unsigned NOT NULL default '0',
  `condition_value2` mediumint(8) unsigned NOT NULL default '0',
  PRIMARY KEY  (`entry`,`item`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Loot System';