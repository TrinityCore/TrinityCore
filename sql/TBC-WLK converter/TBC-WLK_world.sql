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


DELETE FROM battleground_template WHERE id IN (9,10,11);
INSERT INTO battleground_template VALUES
(9,0,0,0,0,1367,0,1368,0),
(10,5,5,10,80,1362,0,1363,0),
(11,5,5,10,80,1364,0,1365,0);

TRUNCATE creature_equip_template;
alter table `creature_equip_template`
    drop column `equipinfo1`,
    drop column `equipinfo2`,
    drop column `equipinfo3`,
    drop column `equipslot1`,
    drop column `equipslot2`,
    drop column `equipslot3`,
    change `equipmodel1` `equipentry1` mediumint(8) UNSIGNED default '0' NOT NULL,
    change `equipmodel2` `equipentry2` mediumint(8) UNSIGNED default '0' NOT NULL,
    change `equipmodel3` `equipentry3` mediumint(8) UNSIGNED default '0' NOT NULL;
update `creature_template` set equipment_id = 0;
	
alter table `item_template`
    add column `ScalingStatDistribution` smallint(6) DEFAULT '0' NOT NULL after `stat_value10`,
    add column `ScalingStatValue` smallint(6) DEFAULT '0' NOT NULL after `ScalingStatDistribution`,
    add column `ItemLimitCategory` smallint(6) DEFAULT '0' NOT NULL after `ArmorDamageModifier`,
    change `Duration` `Duration` int(11) NOT NULL default '0' COMMENT 'Duration in seconds. Negative value means realtime, postive value ingame time' after ArmorDamageModifier,
    add column `StatsCount` tinyint(3) UNSIGNED DEFAULT '0' NOT NULL after `ContainerSlots`,
    CHANGE COLUMN `TotemCategory` `TotemCategory` mediumint(9) NOT NULL default '0';

UPDATE item_template
    SET maxcount = 0 WHERE maxcount > 32000;
UPDATE item_template
    SET stackable = 0 WHERE stackable > 32000;
ALTER TABLE item_template
    CHANGE COLUMN maxcount  maxcount  smallint(5) NOT NULL default '-1',
    CHANGE COLUMN stackable stackable smallint(5) NOT NULL default '1';
UPDATE item_template
    SET stackable = -1 WHERE stackable = 0;	

alter table `quest_template`
    add column `PlayersSlain` tinyint(3) UNSIGNED DEFAULT '0' NOT NULL after `CharTitleId`,
    add column `BonusTalents` tinyint(3) UNSIGNED DEFAULT '0' NOT NULL after `PlayersSlain`,
    CHANGE `RewHonorableKills` `RewHonorableKills` int unsigned NOT NULL default '0';

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


-- command
DELETE FROM `command` WHERE `name` = 'modify runicpower';
INSERT INTO `command` VALUES
('modify runicpower',1,'Syntax: .modify runicpower #newrunicpower\r\n\r\nModify the runic power of the selected player. If no player is selected, modify your runic power.');

DELETE FROM `command` WHERE name = 'reload';


-- string
DELETE FROM trinity_string WHERE entry in (345,346);
INSERT INTO `trinity_string` VALUES
(345,'Forced customize for player %s will be requested at next login.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(346,'Forced customize for player %s (GUID #%u) will be requested at next login.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);

DELETE FROM trinity_string WHERE entry in (712,717,718,719);
INSERT INTO trinity_string VALUES
(712,'|cffff0000[BG Queue Announcer]:|r %s -- [%u-%u] A: %u/%u, H: %u/%u|r',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(717,'|cffff0000[BG Queue Announcer]:|r %s -- [%u-%u] Started!|r',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(718,'|cffff0000[Arena Queue Announcer]:|r %s -- Joined : %ux%u : %u|r',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(719,'|cffff0000[Arena Queue Announcer]:|r %s -- Exited : %ux%u : %u|r',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);

DELETE FROM trinity_string WHERE entry in (720,721,722,723,724,725,726,727,728,729,730,731,732,733,734,735,736);
INSERT INTO trinity_string VALUES
(720,'Your group is too large for this battleground. Please regroup to join.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(721,'Your group is too large for this arena. Please regroup to join.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(722,'Your group has members not in your arena team. Please regroup to join.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(723,'Your group does not have enough players to join this match.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(724,'The Gold Team wins!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(725,'The Green Team wins!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(726,'There aren\'t enough players in this battleground. It will end soon unless some more players join to balance the fight.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(727,'Your group has an offline member. Please remove him before joining.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(728,'Your group has players from the opposing faction. You can\'t join the battleground as a group.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(729,'Your group has players from different battleground brakets. You can\'t join as group.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(730,'Someone in your party is already in this battleground queue. (S)he must leave it before joining as group.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(731,'Someone in your party is Deserter. You can\'t join as group.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(732,'Someone in your party is already in three battleground queues. You cannot join as group.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(733,'You cannot teleport to a battleground or arena map.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(734,'You cannot summon players to a battleground or arena map.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(735,'You must be in GM mode to teleport to a player in a battleground.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(736,'You cannot teleport to a battleground from another battleground. Please leave the current battleground first.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);

DELETE FROM trinity_string WHERE entry in (1122,1123,1124,1125,1126,1127,1128,1129,1130,1131,1132,1133,1134,1135,1136,1137,1138);

DELETE FROM `trinity_string` WHERE `entry` IN (173,174);
INSERT INTO `trinity_string` VALUES
(173,'You changed runic power of %s to %i/%i.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(174,'%s changed your runic power to %i/%i.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);


-- data

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

INSERT INTO world.player_classlevelstats SELECT * FROM mangos.player_classlevelstats;
INSERT INTO world.player_levelstats SELECT * FROM mangos.player_levelstats;
INSERT INTO world.playercreateinfo_spell SELECT * FROM mangos.playercreateinfo_spell;
INSERT INTO world.playercreateinfo_action SELECT * FROM mangos.playercreateinfo_action;
INSERT INTO world.spell_learn_spell SELECT * FROM mangos.spell_learn_spell;


DELETE FROM item_template WHERE entry IN (34648,34649,34650,34651,34652,34653,34655,34656,34657,34658,34659,38145,38147,41751);
INSERT INTO item_template VALUES
(34648,4,4,-1,'Acherus Knight\'s Greaves',51496,2,32768,1,51,10,8,-1,-1,60,55,0,0,0,0,0,0,0,0,1,0,3,4,10,7,12,3,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,392,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,1,'',0,0,0,0,0,6,0,0,0,0,0,55,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,'',0,0,0,0),
(34649,4,4,-1,'Acherus Knight\'s Gauntlets',51498,2,32768,1,34,6,10,-1,-1,60,55,0,0,0,0,0,0,0,0,1,0,3,4,15,7,6,32,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,356,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,1,'',0,0,0,0,0,6,0,0,0,0,0,40,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,'',0,0,0,0),
(34650,4,4,-1,'Acherus Knight\'s Tunic',51494,2,32768,1,69,13,5,-1,-1,60,55,0,0,0,0,0,0,0,0,1,0,3,4,20,7,11,32,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,570,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,1,'',0,0,0,0,0,6,0,0,0,0,0,115,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,'',0,0,0,0),
(34651,4,4,-1,'Acherus Knight\'s Girdle',51497,2,32768,1,35,7,6,-1,-1,60,55,0,0,0,0,0,0,0,0,1,0,2,4,10,32,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,320,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,1,'',0,0,0,0,0,6,0,0,0,0,0,40,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,'',0,0,0,0),
(34652,4,4,-1,'Acherus Knight\'s Hood',51495,2,32768,1,52,10,1,-1,-1,60,55,0,0,0,0,0,0,0,0,1,0,3,4,15,7,15,32,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,463,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,1,'',0,0,0,0,0,6,0,0,0,0,0,70,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,'',0,0,0,0),
(34653,4,4,-1,'Acherus Knight\'s Wristguard',51500,2,32768,1,36,7,9,-1,-1,60,55,0,0,0,0,0,0,0,0,1,0,3,4,7,31,7,7,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,249,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,1,'',0,0,0,0,0,6,0,0,0,0,0,40,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,'',0,0,0,0),
(34655,4,4,-1,'Acherus Knight\'s Pauldrons',51501,2,32768,1,54,10,3,-1,-1,60,55,0,0,0,0,0,0,0,0,1,0,3,4,11,3,9,7,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,427,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,1,'',0,0,0,0,0,6,0,0,0,0,0,70,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,'',0,0,0,0),
(34656,4,4,-1,'Acherus Knight\'s Cover',51499,2,32768,1,73,14,7,-1,-1,60,55,0,0,0,0,0,0,0,0,1,0,3,4,13,3,10,7,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,499,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,1,'',0,0,0,0,0,6,0,0,0,0,0,85,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,'',0,0,0,0),
(34657,4,0,-1,'Choker of Damnation',6539,2,32768,1,2303,575,2,-1,-1,60,55,0,0,0,0,0,0,0,0,1,0,3,4,9,7,8,31,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,1,'',0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,'',0,0,0,0),
(34658,4,0,-1,'Plague Band',963,2,32768,1,534,133,11,-1,-1,60,55,0,0,0,0,0,0,0,0,1,0,3,4,11,3,6,7,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,1,'',0,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,'',0,0,0,0),
(34659,4,1,-1,'Acherus Knight\'s Shroud',49738,2,32768,1,31,6,16,-1,-1,60,55,0,0,0,0,0,0,0,0,1,0,2,4,12,7,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,39,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,1,'',0,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,'',0,0,0,0),
(38145,1,0,-1,'Deathweave Bag',1282,1,32768,1,0,0,18,-1,-1,35,0,0,0,0,0,0,0,0,0,1,12,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,1,'',0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,'',0,0,0,0),
(38147,4,0,-1,'Corrupted Band',963,2,32768,1,534,133,11,-1,-1,60,55,0,0,0,0,0,0,0,0,1,0,3,4,11,3,6,32,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,1,'',0,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,'',0,0,0,0),
(41751,0,5,-1,'Black Mushroom',36728,1,0,1,100,5,0,-1,-1,65,55,0,0,0,0,0,0,0,0,20,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,27094,0,-1,0,0,11,1000,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,0,0,0,-1,0,-1,0,'',0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,'',0,0,0,0);
