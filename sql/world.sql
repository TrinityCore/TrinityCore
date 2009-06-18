-- MySQL dump 10.11
--
-- Host: localhost    Database: world
-- ------------------------------------------------------
-- Server version	5.0.34-log

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `areatrigger_involvedrelation`
--

DROP TABLE IF EXISTS `areatrigger_involvedrelation`;
CREATE TABLE `areatrigger_involvedrelation` (
  `id` mediumint(8) unsigned NOT NULL default '0' COMMENT 'Identifier',
  `quest` mediumint(8) unsigned NOT NULL default '0' COMMENT 'Quest Identifier',
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Trigger System';

--
-- Dumping data for table `areatrigger_involvedrelation`
--

LOCK TABLES `areatrigger_involvedrelation` WRITE;
/*!40000 ALTER TABLE `areatrigger_involvedrelation` DISABLE KEYS */;
/*!40000 ALTER TABLE `areatrigger_involvedrelation` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `areatrigger_scripts`
--

DROP TABLE IF EXISTS `areatrigger_scripts`;
CREATE TABLE `areatrigger_scripts` (
  `entry` mediumint(8) NOT NULL,
  `ScriptName` char(64) NOT NULL,
  PRIMARY KEY  (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `areatrigger_scripts`
--

LOCK TABLES `areatrigger_scripts` WRITE;
/*!40000 ALTER TABLE `areatrigger_scripts` DISABLE KEYS */;
/*!40000 ALTER TABLE `areatrigger_scripts` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `areatrigger_tavern`
--

DROP TABLE IF EXISTS `areatrigger_tavern`;
CREATE TABLE `areatrigger_tavern` (
  `id` mediumint(8) unsigned NOT NULL default '0' COMMENT 'Identifier',
  `name` text,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Trigger System';

--
-- Dumping data for table `areatrigger_tavern`
--

LOCK TABLES `areatrigger_tavern` WRITE;
/*!40000 ALTER TABLE `areatrigger_tavern` DISABLE KEYS */;
/*!40000 ALTER TABLE `areatrigger_tavern` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `areatrigger_teleport`
--

DROP TABLE IF EXISTS `areatrigger_teleport`;
CREATE TABLE `areatrigger_teleport` (
  `id` mediumint(8) unsigned NOT NULL default '0' COMMENT 'Identifier',
  `name` text,            
  `access_id` bigint(20) unsigned NOT NULL DEFAULT '0',
  `target_map` smallint(5) unsigned NOT NULL default '0',
  `target_position_x` float NOT NULL default '0',
  `target_position_y` float NOT NULL default '0',
  `target_position_z` float NOT NULL default '0',
  `target_orientation` float NOT NULL default '0',
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Trigger System';

--
-- Dumping data for table `areatrigger_teleport`
--

LOCK TABLES `areatrigger_teleport` WRITE;
/*!40000 ALTER TABLE `areatrigger_teleport` DISABLE KEYS */;
/*!40000 ALTER TABLE `areatrigger_teleport` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `access_requirement`
--

DROP TABLE IF EXISTS `access_requirement`;
CREATE TABLE `access_requirement` (
  `id` bigint(20) unsigned NOT NULL COMMENT 'Identifier',
  `level_min` tinyint(3) unsigned NOT NULL default '0',
  `level_max` tinyint(3) unsigned NOT NULL default '0',
  `item` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0',
  `item2` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0',
  `heroic_key` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0',
  `heroic_key2` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0',
  `quest_done` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0',
  `quest_failed_text` TEXT NULL DEFAULT NULL,
  `heroic_quest_done` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0',
  `heroic_quest_failed_text` TEXT NULL DEFAULT NULL,
  `comment` TEXT NULL DEFAULT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC COMMENT='Access Requirements';

--
-- Dumping data for table `access_requirement`
--

LOCK TABLES `access_requirement` WRITE;
/*!40000 ALTER TABLE `access_requirement` DISABLE KEYS */;
/*!40000 ALTER TABLE `access_requirement` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `battleground_template`
--

DROP TABLE IF EXISTS `battleground_template`;
CREATE TABLE `battleground_template` (
  `id` mediumint(8) unsigned NOT NULL,
  `MinPlayersPerTeam` smallint(5) unsigned NOT NULL default '0',
  `MaxPlayersPerTeam` smallint(5) unsigned NOT NULL default '0',
  `MinLvl` tinyint(3) unsigned NOT NULL default '0',
  `MaxLvl` tinyint(3) unsigned NOT NULL default '0',
  `AllianceStartLoc` mediumint(8) unsigned NOT NULL,
  `AllianceStartO` float NOT NULL,
  `HordeStartLoc` mediumint(8) unsigned NOT NULL,
  `HordeStartO` float NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `battleground_template`
--

LOCK TABLES `battleground_template` WRITE;
/*!40000 ALTER TABLE `battleground_template` DISABLE KEYS */;
/*!40000 ALTER TABLE `battleground_template` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `battlemaster_entry`
--

DROP TABLE IF EXISTS `battlemaster_entry`;
CREATE TABLE `battlemaster_entry` (
  `entry` mediumint(8) unsigned NOT NULL default '0' COMMENT 'Entry of a creature',
  `bg_template` mediumint(8) unsigned NOT NULL default '0' COMMENT 'Battleground template id',
  PRIMARY KEY  (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `battlemaster_entry`
--

LOCK TABLES `battlemaster_entry` WRITE;
/*!40000 ALTER TABLE `battlemaster_entry` DISABLE KEYS */;
/*!40000 ALTER TABLE `battlemaster_entry` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `command`
--

DROP TABLE IF EXISTS `command`;
CREATE TABLE `command` (
  `name` varchar(50) NOT NULL default '',
  `security` tinyint(3) unsigned NOT NULL default '0',
  `help` longtext,
  PRIMARY KEY  (`name`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Chat System';

--
-- Dumping data for table `command`
--

LOCK TABLES `command` WRITE;
/*!40000 ALTER TABLE `command` DISABLE KEYS */;
/*!40000 ALTER TABLE `command` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `creature`
--

DROP TABLE IF EXISTS `creature`;
CREATE TABLE `creature` (
  `guid` int(10) unsigned NOT NULL auto_increment COMMENT 'Global Unique Identifier',
  `id` mediumint(8) unsigned NOT NULL default '0' COMMENT 'Creature Identifier',
  `map` smallint(5) unsigned NOT NULL default '0' COMMENT 'Map Identifier',
  `spawnMask` tinyint(3) unsigned NOT NULL default '1',
  `modelid` mediumint(8) unsigned NOT NULL default '0',
  `equipment_id` mediumint(9) NOT NULL default '0',
  `position_x` float NOT NULL default '0',
  `position_y` float NOT NULL default '0',
  `position_z` float NOT NULL default '0',
  `orientation` float NOT NULL default '0',
  `spawntimesecs` int(10) unsigned NOT NULL default '120',
  `spawndist` float NOT NULL default '5',
  `currentwaypoint` mediumint(8) unsigned NOT NULL default '0',
  `curhealth` int(10) unsigned NOT NULL default '1',
  `curmana` int(10) unsigned NOT NULL default '0',
  `DeathState` tinyint(3) unsigned NOT NULL default '0',
  `MovementType` tinyint(3) unsigned NOT NULL default '0',
  PRIMARY KEY  (`guid`),
  KEY `idx_map` (`map`),
  KEY `idx_id` (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC COMMENT='Creature System';

--
-- Dumping data for table `creature`
--

LOCK TABLES `creature` WRITE;
/*!40000 ALTER TABLE `creature` DISABLE KEYS */;
/*!40000 ALTER TABLE `creature` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `creature_addon`
--

DROP TABLE IF EXISTS `creature_addon`;
CREATE TABLE `creature_addon` (
  `guid` int(10) unsigned NOT NULL default '0',
  `path_id` int(11) unsigned NOT NULL default '0',
  `mount` mediumint(8) unsigned NOT NULL default '0',
  `bytes0` int(10) unsigned NOT NULL default '0',
  `bytes1` int(10) unsigned NOT NULL default '0',
  `bytes2` int(10) unsigned NOT NULL default '0',
  `emote` int(10) unsigned NOT NULL default '0',
  `moveflags` int(10) unsigned NOT NULL default '0',
  `auras` text,
  PRIMARY KEY  (`guid`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `creature_addon`
--

LOCK TABLES `creature_addon` WRITE;
/*!40000 ALTER TABLE `creature_addon` DISABLE KEYS */;
/*!40000 ALTER TABLE `creature_addon` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `creature_equip_template`
--

DROP TABLE IF EXISTS `creature_equip_template`;
CREATE TABLE `creature_equip_template` (
  `entry` mediumint(8) unsigned NOT NULL default '0' COMMENT 'Unique entry',
  `equipmodel1` mediumint(8) unsigned NOT NULL default '0',
  `equipmodel2` mediumint(8) unsigned NOT NULL default '0',
  `equipmodel3` mediumint(8) unsigned NOT NULL default '0',
  `equipinfo1` int(10) unsigned NOT NULL default '0',
  `equipinfo2` int(10) unsigned NOT NULL default '0',
  `equipinfo3` int(10) unsigned NOT NULL default '0',
  `equipslot1` int(11) NOT NULL default '0',
  `equipslot2` int(11) NOT NULL default '0',
  `equipslot3` int(11) NOT NULL default '0',
  PRIMARY KEY  (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COMMENT='Creature System (Equipment)';

--
-- Dumping data for table `creature_equip_template`
--

LOCK TABLES `creature_equip_template` WRITE;
/*!40000 ALTER TABLE `creature_equip_template` DISABLE KEYS */;
/*!40000 ALTER TABLE `creature_equip_template` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `creature_formations`
--

DROP TABLE IF EXISTS `creature_formations`;
CREATE TABLE `creature_formations` (
  `leaderGUID` int(11) unsigned NOT NULL,
  `memberGUID` int(11) unsigned NOT NULL,
  `dist` float unsigned NOT NULL,
  `angle` float unsigned NOT NULL,
  `groupAI` int(11) unsigned NOT NULL,
  PRIMARY KEY  (`memberGUID`));

--
-- Dumping data for table `creature_formations`
--

LOCK TABLES `creature_formations` WRITE;
/*!40000 ALTER TABLE `creature_formations` DISABLE KEYS */;
/*!40000 ALTER TABLE `creature_formations` ENABLE KEYS */;
UNLOCK TABLES;


--
-- Table structure for table `creature_involvedrelation`
--

DROP TABLE IF EXISTS `creature_involvedrelation`;
CREATE TABLE `creature_involvedrelation` (
  `id` mediumint(8) unsigned NOT NULL default '0' COMMENT 'Identifier',
  `quest` mediumint(8) unsigned NOT NULL default '0' COMMENT 'Quest Identifier',
  PRIMARY KEY  (`id`,`quest`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Creature System';

--
-- Dumping data for table `creature_involvedrelation`
--

LOCK TABLES `creature_involvedrelation` WRITE;
/*!40000 ALTER TABLE `creature_involvedrelation` DISABLE KEYS */;
/*!40000 ALTER TABLE `creature_involvedrelation` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `creature_loot_template`
--

DROP TABLE IF EXISTS `creature_loot_template`;
CREATE TABLE `creature_loot_template` (
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
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COMMENT='Loot System';

--
-- Dumping data for table `creature_loot_template`
--

LOCK TABLES `creature_loot_template` WRITE;
/*!40000 ALTER TABLE `creature_loot_template` DISABLE KEYS */;
/*!40000 ALTER TABLE `creature_loot_template` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `creature_model_info`
--

DROP TABLE IF EXISTS `creature_model_info`;
CREATE TABLE `creature_model_info` (
  `modelid` mediumint(8) unsigned NOT NULL default '0',
  `bounding_radius` float NOT NULL default '0',
  `combat_reach` float NOT NULL default '0',
  `gender` tinyint(3) unsigned NOT NULL default '2',
  `modelid_other_gender` mediumint(8) unsigned NOT NULL default '0',
  PRIMARY KEY  (`modelid`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COMMENT='Creature System (Model related info)';

--
-- Dumping data for table `creature_model_info`
--

LOCK TABLES `creature_model_info` WRITE;
/*!40000 ALTER TABLE `creature_model_info` DISABLE KEYS */;
/*!40000 ALTER TABLE `creature_model_info` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `creature_onkill_reputation`
--

DROP TABLE IF EXISTS `creature_onkill_reputation`;
CREATE TABLE `creature_onkill_reputation` (
  `creature_id` mediumint(8) unsigned NOT NULL default '0' COMMENT 'Creature Identifier',
  `RewOnKillRepFaction1` smallint(6) NOT NULL default '0',
  `RewOnKillRepFaction2` smallint(6) NOT NULL default '0',
  `MaxStanding1` tinyint(4) NOT NULL default '0',
  `IsTeamAward1` tinyint(4) NOT NULL default '0',
  `RewOnKillRepValue1` mediumint(9) NOT NULL default '0',
  `MaxStanding2` tinyint(4) NOT NULL default '0',
  `IsTeamAward2` tinyint(4) NOT NULL default '0',
  `RewOnKillRepValue2` mediumint(9) NOT NULL default '0',
  `TeamDependent` tinyint(3) unsigned NOT NULL default '0',
  PRIMARY KEY  (`creature_id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC COMMENT='Creature OnKill Reputation gain';

--
-- Dumping data for table `creature_onkill_reputation`
--

LOCK TABLES `creature_onkill_reputation` WRITE;
/*!40000 ALTER TABLE `creature_onkill_reputation` DISABLE KEYS */;
/*!40000 ALTER TABLE `creature_onkill_reputation` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `creature_questrelation`
--

DROP TABLE IF EXISTS `creature_questrelation`;
CREATE TABLE `creature_questrelation` (
  `id` mediumint(8) unsigned NOT NULL default '0' COMMENT 'Identifier',
  `quest` mediumint(8) unsigned NOT NULL default '0' COMMENT 'Quest Identifier',
  PRIMARY KEY  (`id`,`quest`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Creature System';

--
-- Dumping data for table `creature_questrelation`
--

LOCK TABLES `creature_questrelation` WRITE;
/*!40000 ALTER TABLE `creature_questrelation` DISABLE KEYS */;
/*!40000 ALTER TABLE `creature_questrelation` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `creature_respawn`
--

DROP TABLE IF EXISTS `creature_respawn`;
CREATE TABLE `creature_respawn` (
  `guid` int(10) unsigned NOT NULL default '0' COMMENT 'Global Unique Identifier',
  `respawntime` bigint(20) NOT NULL default '0',
  `instance` mediumint(8) unsigned NOT NULL default '0',
  PRIMARY KEY  (`guid`,`instance`),
  KEY `instance` (`instance`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC COMMENT='Grid Loading System';

--
-- Dumping data for table `creature_respawn`
--

LOCK TABLES `creature_respawn` WRITE;
/*!40000 ALTER TABLE `creature_respawn` DISABLE KEYS */;
/*!40000 ALTER TABLE `creature_respawn` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `creature_template`
--

DROP TABLE IF EXISTS `creature_template`;
CREATE TABLE `creature_template` (
  `entry` mediumint(8) unsigned NOT NULL default '0',
  `heroic_entry` mediumint(8) unsigned NOT NULL default '0',
  `modelid_A` mediumint(8) unsigned NOT NULL default '0',
  `modelid_A2` mediumint(8) unsigned NOT NULL default '0',
  `modelid_H` mediumint(8) unsigned NOT NULL default '0',
  `modelid_H2` mediumint(8) unsigned NOT NULL default '0',
  `name` char(100) NOT NULL default '0',
  `subname` char(100) default NULL,
  `IconName` char(100) default NULL,
  `minlevel` tinyint(3) unsigned NOT NULL default '1',
  `maxlevel` tinyint(3) unsigned NOT NULL default '1',
  `minhealth` int(10) unsigned NOT NULL default '0',
  `maxhealth` int(10) unsigned NOT NULL default '0',
  `minmana` int(10) unsigned NOT NULL default '0',
  `maxmana` int(10) unsigned NOT NULL default '0',
  `armor` mediumint(8) unsigned NOT NULL default '0',
  `faction_A` smallint(5) unsigned NOT NULL default '0',
  `faction_H` smallint(5) unsigned NOT NULL default '0',
  `npcflag` int(10) unsigned NOT NULL default '0',
  `speed` float default '1',
  `scale` float NOT NULL default '1',
  `rank` tinyint(3) unsigned NOT NULL default '0',
  `mindmg` float NOT NULL default '0',
  `maxdmg` float NOT NULL default '0',
  `dmgschool` tinyint(4) NOT NULL default '0',
  `attackpower` int(10) unsigned NOT NULL default '0',
  `baseattacktime` int(10) unsigned NOT NULL default '0',
  `rangeattacktime` int(10) unsigned NOT NULL default '0',
  `flags` int(10) unsigned NOT NULL default '0',
  `dynamicflags` int(10) unsigned NOT NULL default '0',
  `family` tinyint(4) NOT NULL default '0',
  `trainer_type` tinyint(4) NOT NULL default '0',
  `trainer_spell` mediumint(8) unsigned NOT NULL default '0',
  `class` tinyint(3) unsigned NOT NULL default '0',
  `race` tinyint(3) unsigned NOT NULL default '0',
  `minrangedmg` float NOT NULL default '0',
  `maxrangedmg` float NOT NULL default '0',
  `rangedattackpower` smallint(5) unsigned NOT NULL default '0',
  `type` tinyint(3) unsigned NOT NULL default '0',
  `flag1` int(10) unsigned NOT NULL default '0',
  `lootid` mediumint(8) unsigned NOT NULL default '0',
  `pickpocketloot` mediumint(8) unsigned NOT NULL default '0',
  `skinloot` mediumint(8) unsigned NOT NULL default '0',
  `resistance1` smallint(5) NOT NULL default '0',
  `resistance2` smallint(5) NOT NULL default '0',
  `resistance3` smallint(5) NOT NULL default '0',
  `resistance4` smallint(5) NOT NULL default '0',
  `resistance5` smallint(5) NOT NULL default '0',
  `resistance6` smallint(5) NOT NULL default '0',
  `spell1` mediumint(8) unsigned NOT NULL default '0',
  `spell2` mediumint(8) unsigned NOT NULL default '0',
  `spell3` mediumint(8) unsigned NOT NULL default '0',
  `spell4` mediumint(8) unsigned NOT NULL default '0',
  `PetSpellDataId` mediumint(8) unsigned NOT NULL default '0',
  `mingold` mediumint(8) unsigned NOT NULL default '0',
  `maxgold` mediumint(8) unsigned NOT NULL default '0',
  `AIName` char(64) NOT NULL default '',
  `MovementType` tinyint(3) unsigned NOT NULL default '0',
  `InhabitType` tinyint(3) unsigned NOT NULL default '3',
  `RacialLeader` tinyint(3) unsigned NOT NULL default '0',
  `RegenHealth` tinyint(3) unsigned NOT NULL default '1',
  `equipment_id` mediumint(8) unsigned NOT NULL default '0',
  `mechanic_immune_mask` int(10) unsigned NOT NULL default '0',
  `flags_extra` int(10) unsigned NOT NULL default '0',
  `ScriptName` char(64) NOT NULL default '',
  PRIMARY KEY  (`entry`),
  KEY `idx_name` (`name`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Creature System';

--
-- Dumping data for table `creature_template`
--

LOCK TABLES `creature_template` WRITE;
/*!40000 ALTER TABLE `creature_template` DISABLE KEYS */;
/*!40000 ALTER TABLE `creature_template` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `creature_template_addon`
--

DROP TABLE IF EXISTS `creature_template_addon`;
CREATE TABLE `creature_template_addon` (
  `entry` mediumint(8) unsigned NOT NULL default '0',
  `path_id` int(11) unsigned NOT NULL default '0',
  `mount` mediumint(8) unsigned NOT NULL default '0',
  `bytes0` int(10) unsigned NOT NULL default '0',
  `bytes1` int(10) unsigned NOT NULL default '0',
  `bytes2` int(10) unsigned NOT NULL default '0',
  `emote` mediumint(8) unsigned NOT NULL default '0',
  `moveflags` int(10) unsigned NOT NULL default '0',
  `auras` text,
  PRIMARY KEY  (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `creature_template_addon`
--

LOCK TABLES `creature_template_addon` WRITE;
/*!40000 ALTER TABLE `creature_template_addon` DISABLE KEYS */;
/*!40000 ALTER TABLE `creature_template_addon` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `custom_texts`
--

DROP TABLE IF EXISTS `custom_texts`;
CREATE TABLE `custom_texts` (
  `entry` mediumint(8) NOT NULL,
  `content_default` text NOT NULL,
  `content_loc1` text,
  `content_loc2` text,
  `content_loc3` text,
  `content_loc4` text,
  `content_loc5` text,
  `content_loc6` text,
  `content_loc7` text,
  `content_loc8` text,
  `sound` mediumint(8) unsigned NOT NULL default '0',
  `type` tinyint unsigned NOT NULL default '0',
  `language` tinyint unsigned NOT NULL default '0',
  `emote` smallint(5) UNSIGNED NOT NULL default '0',
  `comment` text,
  PRIMARY KEY (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Custom Texts';

--
-- Dumping data for table `custom_texts`
--

LOCK TABLES `custom_texts` WRITE;
/*!40000 ALTER TABLE `custom_texts` DISABLE KEYS */;
/*!40000 ALTER TABLE `custom_texts` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `disenchant_loot_template`
--

DROP TABLE IF EXISTS `disenchant_loot_template`;
CREATE TABLE `disenchant_loot_template` (
  `entry` mediumint(8) unsigned NOT NULL default '0' COMMENT 'Recommended id selection: item_level*100 + item_quality',
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

--
-- Dumping data for table `disenchant_loot_template`
--

LOCK TABLES `disenchant_loot_template` WRITE;
/*!40000 ALTER TABLE `disenchant_loot_template` DISABLE KEYS */;
/*!40000 ALTER TABLE `disenchant_loot_template` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `event_scripts`
--

DROP TABLE IF EXISTS `event_scripts`;
CREATE TABLE `event_scripts` (
  `id` mediumint(8) unsigned NOT NULL default '0',
  `delay` int(10) unsigned NOT NULL default '0',
  `command` mediumint(8) unsigned NOT NULL default '0',
  `datalong` mediumint(8) unsigned NOT NULL default '0',
  `datalong2` int(10) unsigned NOT NULL default '0',
  `datatext` text NOT NULL,
  `x` float NOT NULL default '0',
  `y` float NOT NULL default '0',
  `z` float NOT NULL default '0',
  `o` float NOT NULL default '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `event_scripts`
--

LOCK TABLES `event_scripts` WRITE;
/*!40000 ALTER TABLE `event_scripts` DISABLE KEYS */;
/*!40000 ALTER TABLE `event_scripts` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `eventai_localized_texts`
--

DROP TABLE IF EXISTS `eventai_localized_texts`;
CREATE TABLE `eventai_localized_texts` (
  `id` int(11) unsigned NOT NULL auto_increment COMMENT 'Identifier',
  `locale_1` varchar(255) NOT NULL default '',
  `locale_2` varchar(255) NOT NULL default '',
  `locale_3` varchar(255) NOT NULL default '',
  `locale_4` varchar(255) NOT NULL default '',
  `locale_5` varchar(255) NOT NULL default '',
  `locale_6` varchar(255) NOT NULL default '',
  `locale_7` varchar(255) NOT NULL default '',
  `locale_8` varchar(255) NOT NULL default '',
  `comment` varchar(255) NOT NULL default '' COMMENT 'Text Comment',
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='EventAI Localized Text';

--
-- Dumping data for table `eventai_localized_texts`
--

LOCK TABLES `eventai_localized_texts` WRITE;
/*!40000 ALTER TABLE `eventai_localized_texts` DISABLE KEYS */;
/*!40000 ALTER TABLE `eventai_localized_texts` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `eventai_scripts`
--

DROP TABLE IF EXISTS `eventai_scripts`;
CREATE TABLE `eventai_scripts` (
  `id` int(11) unsigned NOT NULL COMMENT 'Identifier' AUTO_INCREMENT,
  `creature_id` int(11) unsigned NOT NULL default '0' COMMENT 'Creature Template Identifier',
  `event_type` tinyint(5) unsigned NOT NULL default '0' COMMENT 'Event Type',
  `event_inverse_phase_mask` int(11) signed NOT NULL default '0' COMMENT 'Mask which phases this event will not trigger in',
  `event_chance` int(3) unsigned NOT NULL default '100',
  `event_flags` int(3) unsigned NOT NULL default '0',
  `event_param1` int(11) signed NOT NULL default '0',
  `event_param2` int(11) signed NOT NULL default '0',
  `event_param3` int(11) signed NOT NULL default '0',
  `event_param4` int(11) signed NOT NULL default '0',
  `action1_type` tinyint(5) unsigned NOT NULL default '0' COMMENT 'Action Type',
  `action1_param1` int(11) signed NOT NULL default '0',
  `action1_param2` int(11) signed NOT NULL default '0',
  `action1_param3` int(11) signed NOT NULL default '0',
  `action2_type` tinyint(5) unsigned NOT NULL default '0' COMMENT 'Action Type',
  `action2_param1` int(11) signed NOT NULL default '0',
  `action2_param2` int(11) signed NOT NULL default '0',
  `action2_param3` int(11) signed NOT NULL default '0',
  `action3_type` tinyint(5) unsigned NOT NULL default '0' COMMENT 'Action Type',
  `action3_param1` int(11) signed NOT NULL default '0',
  `action3_param2` int(11) signed NOT NULL default '0',
  `action3_param3` int(11) signed NOT NULL default '0',
  `comment` varchar(255) NOT NULL default '' COMMENT 'Event Comment',
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='EventAI Scripts';

--
-- Dumping data for table `eventai_scripts`
--

LOCK TABLES `eventai_scripts` WRITE;
/*!40000 ALTER TABLE `eventai_scripts` DISABLE KEYS */;
/*!40000 ALTER TABLE `eventai_scripts` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `eventai_summons`
--

DROP TABLE IF EXISTS `eventai_summons`;
CREATE TABLE `eventai_summons` (
  `id` int(11) unsigned NOT NULL COMMENT 'Location Identifier' AUTO_INCREMENT,
  `position_x` float NOT NULL default '0',
  `position_y` float NOT NULL default '0',
  `position_z` float NOT NULL default '0',
  `orientation` float NOT NULL default '0',
  `spawntimesecs` int(11) unsigned NOT NULL default '120',
  `comment` varchar(255) NOT NULL default '' COMMENT 'Summon Comment',
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='EventAI Summoning Locations';

--
-- Dumping data for table `eventai_summons`
--

LOCK TABLES `eventai_summons` WRITE;
/*!40000 ALTER TABLE `eventai_summons` DISABLE KEYS */;
/*!40000 ALTER TABLE `eventai_summons` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `eventai_texts`
--

DROP TABLE IF EXISTS `eventai_texts`;
CREATE TABLE `eventai_texts` (
  `entry` mediumint(8) NOT NULL,
  `content_default` text NOT NULL,
  `content_loc1` text,
  `content_loc2` text,
  `content_loc3` text,
  `content_loc4` text,
  `content_loc5` text,
  `content_loc6` text,
  `content_loc7` text,
  `content_loc8` text,
  `sound` mediumint(8) unsigned NOT NULL default '0',
  `type` tinyint unsigned NOT NULL default '0',
  `language` tinyint unsigned NOT NULL default '0',
  `comment` text,
  PRIMARY KEY (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Script Texts';

--
-- Dumping data for table `eventai_texts`
--

LOCK TABLES `eventai_texts` WRITE;
/*!40000 ALTER TABLE `eventai_texts` DISABLE KEYS */;
/*!40000 ALTER TABLE `eventai_texts` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `exploration_basexp`
--

DROP TABLE IF EXISTS `exploration_basexp`;
CREATE TABLE `exploration_basexp` (
  `level` tinyint(4) NOT NULL default '0',
  `basexp` mediumint(9) NOT NULL default '0',
  PRIMARY KEY  (`level`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Exploration System';

--
-- Dumping data for table `exploration_basexp`
--

LOCK TABLES `exploration_basexp` WRITE;
/*!40000 ALTER TABLE `exploration_basexp` DISABLE KEYS */;
/*!40000 ALTER TABLE `exploration_basexp` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `fishing_loot_template`
--

DROP TABLE IF EXISTS `fishing_loot_template`;
CREATE TABLE `fishing_loot_template` (
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
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COMMENT='Loot System';

--
-- Dumping data for table `fishing_loot_template`
--

LOCK TABLES `fishing_loot_template` WRITE;
/*!40000 ALTER TABLE `fishing_loot_template` DISABLE KEYS */;
/*!40000 ALTER TABLE `fishing_loot_template` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `game_event`
--

DROP TABLE IF EXISTS `game_event`;
CREATE TABLE `game_event` (
  `entry` mediumint(8) unsigned NOT NULL COMMENT 'Entry of the game event',
  `start_time` timestamp NOT NULL default '0000-00-00 00:00:00' COMMENT 'Absolute start date, the event will never start before',
  `end_time` timestamp NOT NULL default '0000-00-00 00:00:00' COMMENT 'Absolute end date, the event will never start afler',
  `occurence` bigint(20) unsigned NOT NULL default '5184000' COMMENT 'Delay in minutes between occurences of the event',
  `length` bigint(20) unsigned NOT NULL default '2592000' COMMENT 'Length in minutes of the event',
  `description` varchar(255) default NULL COMMENT 'Description of the event displayed in console',
  `world_event` tinyint(3) unsigned NOT NULL default '0' COMMENT '0 if normal event, 1 if world event',
  PRIMARY KEY  (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `game_event`
--

LOCK TABLES `game_event` WRITE;
/*!40000 ALTER TABLE `game_event` DISABLE KEYS */;
/*!40000 ALTER TABLE `game_event` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `game_event_battleground_holiday`
--

DROP TABLE IF EXISTS `game_event_battleground_holiday`;
CREATE TABLE `game_event_battleground_holiday` (
 `event` int(10) unsigned NOT NULL,
 `bgflag` int(10) unsigned NOT NULL default '0',
 PRIMARY KEY  (`event`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `game_event_battleground_holiday`
--

LOCK TABLES `game_event_battleground_holiday` WRITE;
/*!40000 ALTER TABLE `game_event_battleground_holiday` DISABLE KEYS */;
/*!40000 ALTER TABLE `game_event_battleground_holiday` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `game_event_condition`
--

DROP TABLE IF EXISTS `game_event_condition`;
CREATE TABLE `game_event_condition` (
  `event_id` mediumint(8) unsigned NOT NULL default '0',
  `condition_id` mediumint(8) unsigned NOT NULL default '0',
  `req_num` float default '0',
  `max_world_state_field` smallint(5) unsigned NOT NULL default '0',
  `done_world_state_field` smallint(5) unsigned NOT NULL default '0',
  `description` varchar(25) NOT NULL default '',
  PRIMARY KEY  (`event_id`,`condition_id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `game_event_condition`
--

LOCK TABLES `game_event_condition` WRITE;
/*!40000 ALTER TABLE `game_event_condition` DISABLE KEYS */;
/*!40000 ALTER TABLE `game_event_condition` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `game_event_creature`
--

DROP TABLE IF EXISTS `game_event_creature`;
CREATE TABLE `game_event_creature` (
  `guid` int(10) unsigned NOT NULL,
  `event` smallint(6) NOT NULL default '0' COMMENT 'Put negatives values to remove during event',
  PRIMARY KEY  (`guid`,`event`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `game_event_creature`
--

LOCK TABLES `game_event_creature` WRITE;
/*!40000 ALTER TABLE `game_event_creature` DISABLE KEYS */;
/*!40000 ALTER TABLE `game_event_creature` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `game_event_creature_quest`
--

DROP TABLE IF EXISTS `game_event_creature_quest`;
CREATE TABLE `game_event_creature_quest` (
  `id` mediumint(8) unsigned NOT NULL default '0',
  `quest` mediumint(8) unsigned NOT NULL default '0',
  `event` smallint(5) unsigned NOT NULL default '0',
  PRIMARY KEY  (`quest`,`event`,`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `game_event_creature_quest`
--

LOCK TABLES `game_event_creature_quest` WRITE;
/*!40000 ALTER TABLE `game_event_creature_quest` DISABLE KEYS */;
/*!40000 ALTER TABLE `game_event_creature_quest` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `game_event_gameobject`
--

DROP TABLE IF EXISTS `game_event_gameobject`;
CREATE TABLE `game_event_gameobject` (
  `guid` int(10) unsigned NOT NULL,
  `event` smallint(6) NOT NULL default '0' COMMENT 'Put negatives values to remove during event',
  PRIMARY KEY  (`guid`,`event`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `game_event_gameobject`
--

LOCK TABLES `game_event_gameobject` WRITE;
/*!40000 ALTER TABLE `game_event_gameobject` DISABLE KEYS */;
/*!40000 ALTER TABLE `game_event_gameobject` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `game_event_gameobject_quest`
--

DROP TABLE IF EXISTS `game_event_gameobject_quest`;
CREATE TABLE `game_event_gameobject_quest` (
  `id` mediumint(8) unsigned NOT NULL default '0',
  `quest` mediumint(8) unsigned NOT NULL default '0',
  `event` smallint(5) unsigned NOT NULL default '0',
  PRIMARY KEY  (`quest`,`event`,`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `game_event_gameobject_quest`
--

LOCK TABLES `game_event_gameobject_quest` WRITE;
/*!40000 ALTER TABLE `game_event_gameobject_quest` DISABLE KEYS */;
/*!40000 ALTER TABLE `game_event_gameobject_quest` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `game_event_model_equip`
--

DROP TABLE IF EXISTS `game_event_model_equip`;
CREATE TABLE `game_event_model_equip` (
  `guid` int(10) unsigned NOT NULL default '0',
  `modelid` mediumint(8) unsigned NOT NULL default '0',
  `equipment_id` mediumint(8) unsigned NOT NULL default '0',
  `event` smallint(5) unsigned NOT NULL default '0',
  PRIMARY KEY  (`guid`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `game_event_model_equip`
--

LOCK TABLES `game_event_model_equip` WRITE;
/*!40000 ALTER TABLE `game_event_model_equip` DISABLE KEYS */;
/*!40000 ALTER TABLE `game_event_model_equip` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `game_event_npc_gossip`
--

DROP TABLE IF EXISTS `game_event_npc_gossip`;
CREATE TABLE `game_event_npc_gossip` (
  `guid` int(10) unsigned NOT NULL,
  `event_id` mediumint(8) unsigned NOT NULL default '0',
  `textid` mediumint(8) unsigned NOT NULL default '0',
  PRIMARY KEY  (`guid`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `game_event_npc_gossip`
--

LOCK TABLES `game_event_npc_gossip` WRITE;
/*!40000 ALTER TABLE `game_event_npc_gossip` DISABLE KEYS */;
/*!40000 ALTER TABLE `game_event_npc_gossip` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `game_event_npc_vendor`
--

DROP TABLE IF EXISTS `game_event_npc_vendor`;
CREATE TABLE `game_event_npc_vendor` (
  `event` mediumint(8) unsigned NOT NULL default '0',
  `guid` mediumint(8) unsigned NOT NULL default '0',
  `item` mediumint(8) unsigned NOT NULL default '0',
  `maxcount` mediumint(8) unsigned NOT NULL default '0',
  `incrtime` mediumint(8) unsigned NOT NULL default '0',
  `ExtendedCost` mediumint(8) unsigned NOT NULL default '0',
  PRIMARY KEY  (`guid`,`item`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `game_event_npc_vendor`
--

LOCK TABLES `game_event_npc_vendor` WRITE;
/*!40000 ALTER TABLE `game_event_npc_vendor` DISABLE KEYS */;
/*!40000 ALTER TABLE `game_event_npc_vendor` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `game_event_npcflag`
--

DROP TABLE IF EXISTS `game_event_npcflag`;
CREATE TABLE `game_event_npcflag` (
  `guid` mediumint(8) unsigned NOT NULL default '0',
  `event_id` mediumint(8) unsigned NOT NULL default '0',
  `npcflag` int(10) unsigned NOT NULL default '0',
  PRIMARY KEY  (`guid`,`event_id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `game_event_npcflag`
--

LOCK TABLES `game_event_npcflag` WRITE;
/*!40000 ALTER TABLE `game_event_npcflag` DISABLE KEYS */;
/*!40000 ALTER TABLE `game_event_npcflag` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `game_event_prerequisite`
--

DROP TABLE IF EXISTS `game_event_prerequisite`;
CREATE TABLE `game_event_prerequisite` (
  `event_id` mediumint(8) unsigned NOT NULL,
  `prerequisite_event` mediumint(8) unsigned NOT NULL,
  PRIMARY KEY  (`event_id`,`prerequisite_event`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `game_event_prerequisite`
--

LOCK TABLES `game_event_prerequisite` WRITE;
/*!40000 ALTER TABLE `game_event_prerequisite` DISABLE KEYS */;
/*!40000 ALTER TABLE `game_event_prerequisite` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `game_event_quest_condition`
--

DROP TABLE IF EXISTS `game_event_quest_condition`;
CREATE TABLE `game_event_quest_condition` (
  `quest` mediumint(8) unsigned NOT NULL default '0',
  `event_id` mediumint(8) unsigned NOT NULL default '0',
  `condition_id` mediumint(8) unsigned NOT NULL default '0',
  `num` float default '0',
  PRIMARY KEY  (`quest`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `game_event_quest_condition`
--

LOCK TABLES `game_event_quest_condition` WRITE;
/*!40000 ALTER TABLE `game_event_quest_condition` DISABLE KEYS */;
/*!40000 ALTER TABLE `game_event_quest_condition` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `game_graveyard_zone`
--

DROP TABLE IF EXISTS `game_graveyard_zone`;
CREATE TABLE `game_graveyard_zone` (
  `id` mediumint(8) unsigned NOT NULL default '0',
  `ghost_zone` mediumint(8) unsigned NOT NULL default '0',
  `faction` smallint(5) unsigned NOT NULL default '0',
  PRIMARY KEY  (`id`,`ghost_zone`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COMMENT='Trigger System';

--
-- Dumping data for table `game_graveyard_zone`
--

LOCK TABLES `game_graveyard_zone` WRITE;
/*!40000 ALTER TABLE `game_graveyard_zone` DISABLE KEYS */;
/*!40000 ALTER TABLE `game_graveyard_zone` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `game_tele`
--

DROP TABLE IF EXISTS `game_tele`;
CREATE TABLE `game_tele` (
  `id` mediumint(8) unsigned NOT NULL auto_increment,
  `position_x` float NOT NULL default '0',
  `position_y` float NOT NULL default '0',
  `position_z` float NOT NULL default '0',
  `orientation` float NOT NULL default '0',
  `map` smallint(5) unsigned NOT NULL default '0',
  `name` varchar(100) NOT NULL default '',
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COMMENT='Tele Command';

--
-- Dumping data for table `game_tele`
--

LOCK TABLES `game_tele` WRITE;
/*!40000 ALTER TABLE `game_tele` DISABLE KEYS */;
/*!40000 ALTER TABLE `game_tele` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `game_weather`
--

DROP TABLE IF EXISTS `game_weather`;
CREATE TABLE `game_weather` (
  `zone` mediumint(8) unsigned NOT NULL default '0',
  `spring_rain_chance` tinyint(3) unsigned NOT NULL default '25',
  `spring_snow_chance` tinyint(3) unsigned NOT NULL default '25',
  `spring_storm_chance` tinyint(3) unsigned NOT NULL default '25',
  `summer_rain_chance` tinyint(3) unsigned NOT NULL default '25',
  `summer_snow_chance` tinyint(3) unsigned NOT NULL default '25',
  `summer_storm_chance` tinyint(3) unsigned NOT NULL default '25',
  `fall_rain_chance` tinyint(3) unsigned NOT NULL default '25',
  `fall_snow_chance` tinyint(3) unsigned NOT NULL default '25',
  `fall_storm_chance` tinyint(3) unsigned NOT NULL default '25',
  `winter_rain_chance` tinyint(3) unsigned NOT NULL default '25',
  `winter_snow_chance` tinyint(3) unsigned NOT NULL default '25',
  `winter_storm_chance` tinyint(3) unsigned NOT NULL default '25',
  PRIMARY KEY  (`zone`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Weather System';

--
-- Dumping data for table `game_weather`
--

LOCK TABLES `game_weather` WRITE;
/*!40000 ALTER TABLE `game_weather` DISABLE KEYS */;
/*!40000 ALTER TABLE `game_weather` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `gameobject`
--

DROP TABLE IF EXISTS `gameobject`;
CREATE TABLE `gameobject` (
  `guid` int(10) unsigned NOT NULL auto_increment COMMENT 'Global Unique Identifier',
  `id` mediumint(8) unsigned NOT NULL default '0' COMMENT 'Gameobject Identifier',
  `map` smallint(5) unsigned NOT NULL default '0' COMMENT 'Map Identifier',
  `spawnMask` tinyint(3) unsigned NOT NULL default '1',
  `position_x` float NOT NULL default '0',
  `position_y` float NOT NULL default '0',
  `position_z` float NOT NULL default '0',
  `orientation` float NOT NULL default '0',
  `rotation0` float NOT NULL default '0',
  `rotation1` float NOT NULL default '0',
  `rotation2` float NOT NULL default '0',
  `rotation3` float NOT NULL default '0',
  `spawntimesecs` int(11) NOT NULL default '0',
  `animprogress` tinyint(3) unsigned NOT NULL default '0',
  `state` tinyint(3) unsigned NOT NULL default '0',
  PRIMARY KEY  (`guid`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Gameobject System';

--
-- Dumping data for table `gameobject`
--

LOCK TABLES `gameobject` WRITE;
/*!40000 ALTER TABLE `gameobject` DISABLE KEYS */;
/*!40000 ALTER TABLE `gameobject` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `gameobject_involvedrelation`
--

DROP TABLE IF EXISTS `gameobject_involvedrelation`;
CREATE TABLE `gameobject_involvedrelation` (
  `id` mediumint(8) unsigned NOT NULL default '0',
  `quest` mediumint(8) unsigned NOT NULL default '0' COMMENT 'Quest Identifier',
  PRIMARY KEY  (`id`,`quest`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `gameobject_involvedrelation`
--

LOCK TABLES `gameobject_involvedrelation` WRITE;
/*!40000 ALTER TABLE `gameobject_involvedrelation` DISABLE KEYS */;
/*!40000 ALTER TABLE `gameobject_involvedrelation` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `gameobject_loot_template`
--

DROP TABLE IF EXISTS `gameobject_loot_template`;
CREATE TABLE `gameobject_loot_template` (
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
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COMMENT='Loot System';

--
-- Dumping data for table `gameobject_loot_template`
--

LOCK TABLES `gameobject_loot_template` WRITE;
/*!40000 ALTER TABLE `gameobject_loot_template` DISABLE KEYS */;
/*!40000 ALTER TABLE `gameobject_loot_template` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `gameobject_questrelation`
--

DROP TABLE IF EXISTS `gameobject_questrelation`;
CREATE TABLE `gameobject_questrelation` (
  `id` mediumint(8) unsigned NOT NULL default '0',
  `quest` mediumint(8) unsigned NOT NULL default '0' COMMENT 'Quest Identifier',
  PRIMARY KEY  (`id`,`quest`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `gameobject_questrelation`
--

LOCK TABLES `gameobject_questrelation` WRITE;
/*!40000 ALTER TABLE `gameobject_questrelation` DISABLE KEYS */;
/*!40000 ALTER TABLE `gameobject_questrelation` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `gameobject_respawn`
--

DROP TABLE IF EXISTS `gameobject_respawn`;
CREATE TABLE `gameobject_respawn` (
  `guid` int(10) unsigned NOT NULL default '0' COMMENT 'Global Unique Identifier',
  `respawntime` bigint(20) NOT NULL default '0',
  `instance` mediumint(8) unsigned NOT NULL default '0',
  PRIMARY KEY  (`guid`,`instance`),
  KEY `instance` (`instance`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC COMMENT='Grid Loading System';

--
-- Dumping data for table `gameobject_respawn`
--

LOCK TABLES `gameobject_respawn` WRITE;
/*!40000 ALTER TABLE `gameobject_respawn` DISABLE KEYS */;
/*!40000 ALTER TABLE `gameobject_respawn` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `gameobject_scripts`
--

DROP TABLE IF EXISTS `gameobject_scripts`;
CREATE TABLE `gameobject_scripts` (
  `id` mediumint(8) unsigned NOT NULL default '0',
  `delay` int(10) unsigned NOT NULL default '0',
  `command` mediumint(8) unsigned NOT NULL default '0',
  `datalong` mediumint(8) unsigned NOT NULL default '0',
  `datalong2` int(10) unsigned NOT NULL default '0',
  `datatext` text NOT NULL,
  `x` float NOT NULL default '0',
  `y` float NOT NULL default '0',
  `z` float NOT NULL default '0',
  `o` float NOT NULL default '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `gameobject_scripts`
--

LOCK TABLES `gameobject_scripts` WRITE;
/*!40000 ALTER TABLE `gameobject_scripts` DISABLE KEYS */;
/*!40000 ALTER TABLE `gameobject_scripts` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `gameobject_template`
--

DROP TABLE IF EXISTS `gameobject_template`;
CREATE TABLE `gameobject_template` (
  `entry` mediumint(8) unsigned NOT NULL default '0',
  `type` tinyint(3) unsigned NOT NULL default '0',
  `displayId` mediumint(8) unsigned NOT NULL default '0',
  `name` varchar(100) NOT NULL default '',
  `castBarCaption` varchar(100) NOT NULL default '',
  `faction` smallint(5) unsigned NOT NULL default '0',
  `flags` int(10) unsigned NOT NULL default '0',
  `size` float NOT NULL default '1',
  `data0` int(10) unsigned NOT NULL default '0',
  `data1` int(10) unsigned NOT NULL default '0',
  `data2` int(10) unsigned NOT NULL default '0',
  `data3` int(10) unsigned NOT NULL default '0',
  `data4` int(10) unsigned NOT NULL default '0',
  `data5` int(10) unsigned NOT NULL default '0',
  `data6` int(10) unsigned NOT NULL default '0',
  `data7` int(10) unsigned NOT NULL default '0',
  `data8` int(10) unsigned NOT NULL default '0',
  `data9` int(10) unsigned NOT NULL default '0',
  `data10` int(10) unsigned NOT NULL default '0',
  `data11` int(10) unsigned NOT NULL default '0',
  `data12` int(10) unsigned NOT NULL default '0',
  `data13` int(10) unsigned NOT NULL default '0',
  `data14` int(10) unsigned NOT NULL default '0',
  `data15` int(10) unsigned NOT NULL default '0',
  `data16` int(10) unsigned NOT NULL default '0',
  `data17` int(10) unsigned NOT NULL default '0',
  `data18` int(10) unsigned NOT NULL default '0',
  `data19` int(10) unsigned NOT NULL default '0',
  `data20` int(10) unsigned NOT NULL default '0',
  `data21` int(10) unsigned NOT NULL default '0',
  `data22` int(10) unsigned NOT NULL default '0',
  `data23` int(10) unsigned NOT NULL default '0',
  `ScriptName` varchar(64) NOT NULL default '',
  PRIMARY KEY  (`entry`),
  KEY `idx_name` (`name`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Gameobject System';

--
-- Dumping data for table `gameobject_template`
--

LOCK TABLES `gameobject_template` WRITE;
/*!40000 ALTER TABLE `gameobject_template` DISABLE KEYS */;
/*!40000 ALTER TABLE `gameobject_template` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `instance_template`
--

DROP TABLE IF EXISTS `instance_template`;
CREATE TABLE `instance_template` (
  `map` smallint(5) unsigned NOT NULL,
  `parent` int(10) unsigned NOT NULL,
  `maxPlayers` tinyint(3) unsigned NOT NULL default '0',
  `reset_delay` int(10) unsigned NOT NULL default '0',
  `access_id` bigint(20) unsigned NOT NULL DEFAULT '0',
  `startLocX` float default NULL,
  `startLocY` float default NULL,
  `startLocZ` float default NULL,
  `startLocO` float default NULL,
  `script` varchar(128) NOT NULL default '',
  PRIMARY KEY  (`map`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `instance_template`
--

LOCK TABLES `instance_template` WRITE;
/*!40000 ALTER TABLE `instance_template` DISABLE KEYS */;
/*!40000 ALTER TABLE `instance_template` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `item_enchantment_template`
--

DROP TABLE IF EXISTS `item_enchantment_template`;
CREATE TABLE `item_enchantment_template` (
  `entry` mediumint(8) unsigned NOT NULL default '0',
  `ench` mediumint(8) unsigned NOT NULL default '0',
  `chance` float unsigned NOT NULL default '0',
  PRIMARY KEY  (`entry`,`ench`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Item Random Enchantment System';

--
-- Dumping data for table `item_enchantment_template`
--

LOCK TABLES `item_enchantment_template` WRITE;
/*!40000 ALTER TABLE `item_enchantment_template` DISABLE KEYS */;
/*!40000 ALTER TABLE `item_enchantment_template` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `item_loot_template`
--

DROP TABLE IF EXISTS `item_loot_template`;
CREATE TABLE `item_loot_template` (
  `entry` mediumint(8) unsigned NOT NULL default '0',
  `item` mediumint(8) unsigned NOT NULL default '0',
  `ChanceOrQuestChance` float NOT NULL default '100',
  `groupid` tinyint(3) unsigned NOT NULL default '0',
  `mincountOrRef` mediumint(9) NOT NULL default '1',
  `maxcount` smallint(5) unsigned NOT NULL default '1',
  `lootcondition` tinyint(3) unsigned NOT NULL default '0',
  `condition_value1` mediumint(8) unsigned NOT NULL default '0',
  `condition_value2` mediumint(8) unsigned NOT NULL default '0',
  PRIMARY KEY  (`entry`,`item`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Loot System';

--
-- Dumping data for table `item_loot_template`
--

LOCK TABLES `item_loot_template` WRITE;
/*!40000 ALTER TABLE `item_loot_template` DISABLE KEYS */;
/*!40000 ALTER TABLE `item_loot_template` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `item_template`
--

DROP TABLE IF EXISTS `item_template`;
CREATE TABLE `item_template` (
  `entry` mediumint(8) unsigned NOT NULL default '0',
  `class` tinyint(3) unsigned NOT NULL default '0',
  `subclass` tinyint(3) unsigned NOT NULL default '0',
  `unk0` int(11) NOT NULL default '-1',
  `name` varchar(255) NOT NULL default '',
  `displayid` mediumint(8) unsigned NOT NULL default '0',
  `Quality` tinyint(3) unsigned NOT NULL default '0',
  `Flags` int(10) unsigned NOT NULL default '0',
  `BuyCount` tinyint(3) unsigned NOT NULL default '1',
  `BuyPrice` int(10) unsigned NOT NULL default '0',
  `SellPrice` int(10) unsigned NOT NULL default '0',
  `InventoryType` tinyint(3) unsigned NOT NULL default '0',
  `AllowableClass` mediumint(9) NOT NULL default '-1',
  `AllowableRace` mediumint(9) NOT NULL default '-1',
  `ItemLevel` tinyint(3) unsigned NOT NULL default '0',
  `RequiredLevel` tinyint(3) unsigned NOT NULL default '0',
  `RequiredSkill` smallint(5) unsigned NOT NULL default '0',
  `RequiredSkillRank` smallint(5) unsigned NOT NULL default '0',
  `requiredspell` mediumint(8) unsigned NOT NULL default '0',
  `requiredhonorrank` mediumint(8) unsigned NOT NULL default '0',
  `RequiredCityRank` mediumint(8) unsigned NOT NULL default '0',
  `RequiredReputationFaction` smallint(5) unsigned NOT NULL default '0',
  `RequiredReputationRank` smallint(5) unsigned NOT NULL default '0',
  `maxcount` smallint(5) unsigned NOT NULL default '0',
  `stackable` smallint(5) unsigned NOT NULL default '1',
  `ContainerSlots` tinyint(3) unsigned NOT NULL default '0',
  `stat_type1` tinyint(3) unsigned NOT NULL default '0',
  `stat_value1` smallint(6) NOT NULL default '0',
  `stat_type2` tinyint(3) unsigned NOT NULL default '0',
  `stat_value2` smallint(6) NOT NULL default '0',
  `stat_type3` tinyint(3) unsigned NOT NULL default '0',
  `stat_value3` smallint(6) NOT NULL default '0',
  `stat_type4` tinyint(3) unsigned NOT NULL default '0',
  `stat_value4` smallint(6) NOT NULL default '0',
  `stat_type5` tinyint(3) unsigned NOT NULL default '0',
  `stat_value5` smallint(6) NOT NULL default '0',
  `stat_type6` tinyint(3) unsigned NOT NULL default '0',
  `stat_value6` smallint(6) NOT NULL default '0',
  `stat_type7` tinyint(3) unsigned NOT NULL default '0',
  `stat_value7` smallint(6) NOT NULL default '0',
  `stat_type8` tinyint(3) unsigned NOT NULL default '0',
  `stat_value8` smallint(6) NOT NULL default '0',
  `stat_type9` tinyint(3) unsigned NOT NULL default '0',
  `stat_value9` smallint(6) NOT NULL default '0',
  `stat_type10` tinyint(3) unsigned NOT NULL default '0',
  `stat_value10` smallint(6) NOT NULL default '0',
  `dmg_min1` float NOT NULL default '0',
  `dmg_max1` float NOT NULL default '0',
  `dmg_type1` tinyint(3) unsigned NOT NULL default '0',
  `dmg_min2` float NOT NULL default '0',
  `dmg_max2` float NOT NULL default '0',
  `dmg_type2` tinyint(3) unsigned NOT NULL default '0',
  `dmg_min3` float NOT NULL default '0',
  `dmg_max3` float NOT NULL default '0',
  `dmg_type3` tinyint(3) unsigned NOT NULL default '0',
  `dmg_min4` float NOT NULL default '0',
  `dmg_max4` float NOT NULL default '0',
  `dmg_type4` tinyint(3) unsigned NOT NULL default '0',
  `dmg_min5` float NOT NULL default '0',
  `dmg_max5` float NOT NULL default '0',
  `dmg_type5` tinyint(3) unsigned NOT NULL default '0',
  `armor` smallint(5) unsigned NOT NULL default '0',
  `holy_res` tinyint(3) unsigned NOT NULL default '0',
  `fire_res` tinyint(3) unsigned NOT NULL default '0',
  `nature_res` tinyint(3) unsigned NOT NULL default '0',
  `frost_res` tinyint(3) unsigned NOT NULL default '0',
  `shadow_res` tinyint(3) unsigned NOT NULL default '0',
  `arcane_res` tinyint(3) unsigned NOT NULL default '0',
  `delay` smallint(5) unsigned NOT NULL default '1000',
  `ammo_type` tinyint(3) unsigned NOT NULL default '0',
  `RangedModRange` float NOT NULL default '0',
  `spellid_1` mediumint(8) unsigned NOT NULL default '0',
  `spelltrigger_1` tinyint(3) unsigned NOT NULL default '0',
  `spellcharges_1` tinyint(4) NOT NULL default '0',
  `spellppmRate_1` float NOT NULL default '0',
  `spellcooldown_1` int(11) NOT NULL default '-1',
  `spellcategory_1` smallint(5) unsigned NOT NULL default '0',
  `spellcategorycooldown_1` int(11) NOT NULL default '-1',
  `spellid_2` mediumint(8) unsigned NOT NULL default '0',
  `spelltrigger_2` tinyint(3) unsigned NOT NULL default '0',
  `spellcharges_2` tinyint(4) NOT NULL default '0',
  `spellppmRate_2` float NOT NULL default '0',
  `spellcooldown_2` int(11) NOT NULL default '-1',
  `spellcategory_2` smallint(5) unsigned NOT NULL default '0',
  `spellcategorycooldown_2` int(11) NOT NULL default '-1',
  `spellid_3` mediumint(8) unsigned NOT NULL default '0',
  `spelltrigger_3` tinyint(3) unsigned NOT NULL default '0',
  `spellcharges_3` tinyint(4) NOT NULL default '0',
  `spellppmRate_3` float NOT NULL default '0',
  `spellcooldown_3` int(11) NOT NULL default '-1',
  `spellcategory_3` smallint(5) unsigned NOT NULL default '0',
  `spellcategorycooldown_3` int(11) NOT NULL default '-1',
  `spellid_4` mediumint(8) unsigned NOT NULL default '0',
  `spelltrigger_4` tinyint(3) unsigned NOT NULL default '0',
  `spellcharges_4` tinyint(4) NOT NULL default '0',
  `spellppmRate_4` float NOT NULL default '0',
  `spellcooldown_4` int(11) NOT NULL default '-1',
  `spellcategory_4` smallint(5) unsigned NOT NULL default '0',
  `spellcategorycooldown_4` int(11) NOT NULL default '-1',
  `spellid_5` mediumint(8) unsigned NOT NULL default '0',
  `spelltrigger_5` tinyint(3) unsigned NOT NULL default '0',
  `spellcharges_5` tinyint(4) NOT NULL default '0',
  `spellppmRate_5` float NOT NULL default '0',
  `spellcooldown_5` int(11) NOT NULL default '-1',
  `spellcategory_5` smallint(5) unsigned NOT NULL default '0',
  `spellcategorycooldown_5` int(11) NOT NULL default '-1',
  `bonding` tinyint(3) unsigned NOT NULL default '0',
  `description` varchar(255) NOT NULL default '',
  `PageText` mediumint(8) unsigned NOT NULL default '0',
  `LanguageID` tinyint(3) unsigned NOT NULL default '0',
  `PageMaterial` tinyint(3) unsigned NOT NULL default '0',
  `startquest` mediumint(8) unsigned NOT NULL default '0',
  `lockid` mediumint(8) unsigned NOT NULL default '0',
  `Material` tinyint(4) NOT NULL default '0',
  `sheath` tinyint(3) unsigned NOT NULL default '0',
  `RandomProperty` mediumint(8) unsigned NOT NULL default '0',
  `RandomSuffix` mediumint(8) unsigned NOT NULL default '0',
  `block` mediumint(8) unsigned NOT NULL default '0',
  `itemset` mediumint(8) unsigned NOT NULL default '0',
  `MaxDurability` smallint(5) unsigned NOT NULL default '0',
  `area` mediumint(8) unsigned NOT NULL default '0',
  `Map` smallint(6) NOT NULL default '0',
  `BagFamily` mediumint(9) NOT NULL default '0',
  `TotemCategory` tinyint(4) NOT NULL default '0',
  `socketColor_1` tinyint(4) NOT NULL default '0',
  `socketContent_1` mediumint(9) NOT NULL default '0',
  `socketColor_2` tinyint(4) NOT NULL default '0',
  `socketContent_2` mediumint(9) NOT NULL default '0',
  `socketColor_3` tinyint(4) NOT NULL default '0',
  `socketContent_3` mediumint(9) NOT NULL default '0',
  `socketBonus` mediumint(9) NOT NULL default '0',
  `GemProperties` mediumint(9) NOT NULL default '0',
  `RequiredDisenchantSkill` smallint(6) NOT NULL default '-1',
  `ArmorDamageModifier` float NOT NULL default '0',
  `ScriptName` varchar(64) NOT NULL default '',
  `DisenchantID` mediumint(8) unsigned NOT NULL default '0',
  `FoodType` tinyint(3) unsigned NOT NULL default '0',
  `minMoneyLoot` int(10) unsigned NOT NULL default '0',
  `maxMoneyLoot` int(10) unsigned NOT NULL default '0',
  `Duration` int(11) NOT NULL default '0' COMMENT 'Duration in seconds. Negative value means realtime, postive value ingame time',
  PRIMARY KEY  (`entry`),
  KEY `idx_name` (`name`),
  KEY `items_index` (`class`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Item System';

--
-- Dumping data for table `item_template`
--

LOCK TABLES `item_template` WRITE;
/*!40000 ALTER TABLE `item_template` DISABLE KEYS */;
/*!40000 ALTER TABLE `item_template` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `locales_creature`
--

DROP TABLE IF EXISTS `locales_creature`;
CREATE TABLE `locales_creature` (
  `entry` mediumint(8) unsigned NOT NULL default '0',
  `name_loc1` varchar(100) NOT NULL default '',
  `name_loc2` varchar(100) NOT NULL default '',
  `name_loc3` varchar(100) NOT NULL default '',
  `name_loc4` varchar(100) NOT NULL default '',
  `name_loc5` varchar(100) NOT NULL default '',
  `name_loc6` varchar(100) NOT NULL default '',
  `name_loc7` varchar(100) NOT NULL default '',
  `name_loc8` varchar(100) NOT NULL default '',
  `subname_loc1` varchar(100) default NULL,
  `subname_loc2` varchar(100) default NULL,
  `subname_loc3` varchar(100) default NULL,
  `subname_loc4` varchar(100) default NULL,
  `subname_loc5` varchar(100) default NULL,
  `subname_loc6` varchar(100) default NULL,
  `subname_loc7` varchar(100) default NULL,
  `subname_loc8` varchar(100) default NULL,
  PRIMARY KEY  (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `locales_creature`
--

LOCK TABLES `locales_creature` WRITE;
/*!40000 ALTER TABLE `locales_creature` DISABLE KEYS */;
/*!40000 ALTER TABLE `locales_creature` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `locales_gameobject`
--

DROP TABLE IF EXISTS `locales_gameobject`;
CREATE TABLE `locales_gameobject` (
  `entry` mediumint(8) unsigned NOT NULL default '0',
  `name_loc1` varchar(100) NOT NULL default '',
  `name_loc2` varchar(100) NOT NULL default '',
  `name_loc3` varchar(100) NOT NULL default '',
  `name_loc4` varchar(100) NOT NULL default '',
  `name_loc5` varchar(100) NOT NULL default '',
  `name_loc6` varchar(100) NOT NULL default '',
  `name_loc7` varchar(100) NOT NULL default '',
  `name_loc8` varchar(100) NOT NULL default '',
  `castbarcaption_loc1` varchar(100) NOT NULL default '',
  `castbarcaption_loc2` varchar(100) NOT NULL default '',
  `castbarcaption_loc3` varchar(100) NOT NULL default '',
  `castbarcaption_loc4` varchar(100) NOT NULL default '',
  `castbarcaption_loc5` varchar(100) NOT NULL default '',
  `castbarcaption_loc6` varchar(100) NOT NULL default '',
  `castbarcaption_loc7` varchar(100) NOT NULL default '',
  `castbarcaption_loc8` varchar(100) NOT NULL default '',
  PRIMARY KEY  (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `locales_gameobject`
--

LOCK TABLES `locales_gameobject` WRITE;
/*!40000 ALTER TABLE `locales_gameobject` DISABLE KEYS */;
/*!40000 ALTER TABLE `locales_gameobject` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `locales_item`
--

DROP TABLE IF EXISTS `locales_item`;
CREATE TABLE `locales_item` (
  `entry` mediumint(8) unsigned NOT NULL default '0',
  `name_loc1` varchar(100) NOT NULL default '',
  `name_loc2` varchar(100) NOT NULL default '',
  `name_loc3` varchar(100) NOT NULL default '',
  `name_loc4` varchar(100) NOT NULL default '',
  `name_loc5` varchar(100) NOT NULL default '',
  `name_loc6` varchar(100) NOT NULL default '',
  `name_loc7` varchar(100) NOT NULL default '',
  `name_loc8` varchar(100) NOT NULL default '',
  `description_loc1` varchar(255) default NULL,
  `description_loc2` varchar(255) default NULL,
  `description_loc3` varchar(255) default NULL,
  `description_loc4` varchar(255) default NULL,
  `description_loc5` varchar(255) default NULL,
  `description_loc6` varchar(255) default NULL,
  `description_loc7` varchar(255) default NULL,
  `description_loc8` varchar(255) default NULL,
  PRIMARY KEY  (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `locales_item`
--

LOCK TABLES `locales_item` WRITE;
/*!40000 ALTER TABLE `locales_item` DISABLE KEYS */;
/*!40000 ALTER TABLE `locales_item` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `locales_npc_option`
--

DROP TABLE IF EXISTS `locales_npc_option`;
CREATE TABLE `locales_npc_option` (
  `entry` mediumint(8) unsigned NOT NULL default '0',
  `option_text_loc1` text,
  `option_text_loc2` text,
  `option_text_loc3` text,
  `option_text_loc4` text,
  `option_text_loc5` text,
  `option_text_loc6` text,
  `option_text_loc7` text,
  `option_text_loc8` text,
  `box_text_loc1` text,
  `box_text_loc2` text,
  `box_text_loc3` text,
  `box_text_loc4` text,
  `box_text_loc5` text,
  `box_text_loc6` text,
  `box_text_loc7` text,
  `box_text_loc8` text,
  PRIMARY KEY  (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `locales_npc_option`
--

LOCK TABLES `locales_npc_option` WRITE;
/*!40000 ALTER TABLE `locales_npc_option` DISABLE KEYS */;
/*!40000 ALTER TABLE `locales_npc_option` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `locales_npc_text`
--

DROP TABLE IF EXISTS `locales_npc_text`;
CREATE TABLE `locales_npc_text` (
  `entry` mediumint(8) unsigned NOT NULL default '0',
  `Text0_0_loc1` longtext,
  `Text0_0_loc2` longtext,
  `Text0_0_loc3` longtext,
  `Text0_0_loc4` longtext,
  `Text0_0_loc5` longtext,
  `Text0_0_loc6` longtext,
  `Text0_0_loc7` longtext,
  `Text0_0_loc8` longtext,
  `Text0_1_loc1` longtext,
  `Text0_1_loc2` longtext,
  `Text0_1_loc3` longtext,
  `Text0_1_loc4` longtext,
  `Text0_1_loc5` longtext,
  `Text0_1_loc6` longtext,
  `Text0_1_loc7` longtext,
  `Text0_1_loc8` longtext,
  `Text1_0_loc1` longtext,
  `Text1_0_loc2` longtext,
  `Text1_0_loc3` longtext,
  `Text1_0_loc4` longtext,
  `Text1_0_loc5` longtext,
  `Text1_0_loc6` longtext,
  `Text1_0_loc7` longtext,
  `Text1_0_loc8` longtext,
  `Text1_1_loc1` longtext,
  `Text1_1_loc2` longtext,
  `Text1_1_loc3` longtext,
  `Text1_1_loc4` longtext,
  `Text1_1_loc5` longtext,
  `Text1_1_loc6` longtext,
  `Text1_1_loc7` longtext,
  `Text1_1_loc8` longtext,
  `Text2_0_loc1` longtext,
  `Text2_0_loc2` longtext,
  `Text2_0_loc3` longtext,
  `Text2_0_loc4` longtext,
  `Text2_0_loc5` longtext,
  `Text2_0_loc6` longtext,
  `Text2_0_loc7` longtext,
  `Text2_0_loc8` longtext,
  `Text2_1_loc1` longtext,
  `Text2_1_loc2` longtext,
  `Text2_1_loc3` longtext,
  `Text2_1_loc4` longtext,
  `Text2_1_loc5` longtext,
  `Text2_1_loc6` longtext,
  `Text2_1_loc7` longtext,
  `Text2_1_loc8` longtext,
  `Text3_0_loc1` longtext,
  `Text3_0_loc2` longtext,
  `Text3_0_loc3` longtext,
  `Text3_0_loc4` longtext,
  `Text3_0_loc5` longtext,
  `Text3_0_loc6` longtext,
  `Text3_0_loc7` longtext,
  `Text3_0_loc8` longtext,
  `Text3_1_loc1` longtext,
  `Text3_1_loc2` longtext,
  `Text3_1_loc3` longtext,
  `Text3_1_loc4` longtext,
  `Text3_1_loc5` longtext,
  `Text3_1_loc6` longtext,
  `Text3_1_loc7` longtext,
  `Text3_1_loc8` longtext,
  `Text4_0_loc1` longtext,
  `Text4_0_loc2` longtext,
  `Text4_0_loc3` longtext,
  `Text4_0_loc4` longtext,
  `Text4_0_loc5` longtext,
  `Text4_0_loc6` longtext,
  `Text4_0_loc7` longtext,
  `Text4_0_loc8` longtext,
  `Text4_1_loc1` longtext,
  `Text4_1_loc2` longtext,
  `Text4_1_loc3` longtext,
  `Text4_1_loc4` longtext,
  `Text4_1_loc5` longtext,
  `Text4_1_loc6` longtext,
  `Text4_1_loc7` longtext,
  `Text4_1_loc8` longtext,
  `Text5_0_loc1` longtext,
  `Text5_0_loc2` longtext,
  `Text5_0_loc3` longtext,
  `Text5_0_loc4` longtext,
  `Text5_0_loc5` longtext,
  `Text5_0_loc6` longtext,
  `Text5_0_loc7` longtext,
  `Text5_0_loc8` longtext,
  `Text5_1_loc1` longtext,
  `Text5_1_loc2` longtext,
  `Text5_1_loc3` longtext,
  `Text5_1_loc4` longtext,
  `Text5_1_loc5` longtext,
  `Text5_1_loc6` longtext,
  `Text5_1_loc7` longtext,
  `Text5_1_loc8` longtext,
  `Text6_0_loc1` longtext,
  `Text6_0_loc2` longtext,
  `Text6_0_loc3` longtext,
  `Text6_0_loc4` longtext,
  `Text6_0_loc5` longtext,
  `Text6_0_loc6` longtext,
  `Text6_0_loc7` longtext,
  `Text6_0_loc8` longtext,
  `Text6_1_loc1` longtext,
  `Text6_1_loc2` longtext,
  `Text6_1_loc3` longtext,
  `Text6_1_loc4` longtext,
  `Text6_1_loc5` longtext,
  `Text6_1_loc6` longtext,
  `Text6_1_loc7` longtext,
  `Text6_1_loc8` longtext,
  `Text7_0_loc1` longtext,
  `Text7_0_loc2` longtext,
  `Text7_0_loc3` longtext,
  `Text7_0_loc4` longtext,
  `Text7_0_loc5` longtext,
  `Text7_0_loc6` longtext,
  `Text7_0_loc7` longtext,
  `Text7_0_loc8` longtext,
  `Text7_1_loc1` longtext,
  `Text7_1_loc2` longtext,
  `Text7_1_loc3` longtext,
  `Text7_1_loc4` longtext,
  `Text7_1_loc5` longtext,
  `Text7_1_loc6` longtext,
  `Text7_1_loc7` longtext,
  `Text7_1_loc8` longtext,
  PRIMARY KEY  (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `locales_npc_text`
--

LOCK TABLES `locales_npc_text` WRITE;
/*!40000 ALTER TABLE `locales_npc_text` DISABLE KEYS */;
/*!40000 ALTER TABLE `locales_npc_text` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `locales_page_text`
--

DROP TABLE IF EXISTS `locales_page_text`;
CREATE TABLE `locales_page_text` (
  `entry` mediumint(8) unsigned NOT NULL default '0',
  `Text_loc1` longtext,
  `Text_loc2` longtext,
  `Text_loc3` longtext,
  `Text_loc4` longtext,
  `Text_loc5` longtext,
  `Text_loc6` longtext,
  `Text_loc7` longtext,
  `Text_loc8` longtext,
  PRIMARY KEY  (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `locales_page_text`
--

LOCK TABLES `locales_page_text` WRITE;
/*!40000 ALTER TABLE `locales_page_text` DISABLE KEYS */;
/*!40000 ALTER TABLE `locales_page_text` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `locales_quest`
--

DROP TABLE IF EXISTS `locales_quest`;
CREATE TABLE `locales_quest` (
  `entry` mediumint(8) unsigned NOT NULL default '0',
  `Title_loc1` text,
  `Title_loc2` text,
  `Title_loc3` text,
  `Title_loc4` text,
  `Title_loc5` text,
  `Title_loc6` text,
  `Title_loc7` text,
  `Title_loc8` text,
  `Details_loc1` text,
  `Details_loc2` text,
  `Details_loc3` text,
  `Details_loc4` text,
  `Details_loc5` text,
  `Details_loc6` text,
  `Details_loc7` text,
  `Details_loc8` text,
  `Objectives_loc1` text,
  `Objectives_loc2` text,
  `Objectives_loc3` text,
  `Objectives_loc4` text,
  `Objectives_loc5` text,
  `Objectives_loc6` text,
  `Objectives_loc7` text,
  `Objectives_loc8` text,
  `OfferRewardText_loc1` text,
  `OfferRewardText_loc2` text,
  `OfferRewardText_loc3` text,
  `OfferRewardText_loc4` text,
  `OfferRewardText_loc5` text,
  `OfferRewardText_loc6` text,
  `OfferRewardText_loc7` text,
  `OfferRewardText_loc8` text,
  `RequestItemsText_loc1` text,
  `RequestItemsText_loc2` text,
  `RequestItemsText_loc3` text,
  `RequestItemsText_loc4` text,
  `RequestItemsText_loc5` text,
  `RequestItemsText_loc6` text,
  `RequestItemsText_loc7` text,
  `RequestItemsText_loc8` text,
  `EndText_loc1` text,
  `EndText_loc2` text,
  `EndText_loc3` text,
  `EndText_loc4` text,
  `EndText_loc5` text,
  `EndText_loc6` text,
  `EndText_loc7` text,
  `EndText_loc8` text,
  `ObjectiveText1_loc1` text,
  `ObjectiveText1_loc2` text,
  `ObjectiveText1_loc3` text,
  `ObjectiveText1_loc4` text,
  `ObjectiveText1_loc5` text,
  `ObjectiveText1_loc6` text,
  `ObjectiveText1_loc7` text,
  `ObjectiveText1_loc8` text,
  `ObjectiveText2_loc1` text,
  `ObjectiveText2_loc2` text,
  `ObjectiveText2_loc3` text,
  `ObjectiveText2_loc4` text,
  `ObjectiveText2_loc5` text,
  `ObjectiveText2_loc6` text,
  `ObjectiveText2_loc7` text,
  `ObjectiveText2_loc8` text,
  `ObjectiveText3_loc1` text,
  `ObjectiveText3_loc2` text,
  `ObjectiveText3_loc3` text,
  `ObjectiveText3_loc4` text,
  `ObjectiveText3_loc5` text,
  `ObjectiveText3_loc6` text,
  `ObjectiveText3_loc7` text,
  `ObjectiveText3_loc8` text,
  `ObjectiveText4_loc1` text,
  `ObjectiveText4_loc2` text,
  `ObjectiveText4_loc3` text,
  `ObjectiveText4_loc4` text,
  `ObjectiveText4_loc5` text,
  `ObjectiveText4_loc6` text,
  `ObjectiveText4_loc7` text,
  `ObjectiveText4_loc8` text,
  PRIMARY KEY  (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `locales_quest`
--

LOCK TABLES `locales_quest` WRITE;
/*!40000 ALTER TABLE `locales_quest` DISABLE KEYS */;
/*!40000 ALTER TABLE `locales_quest` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `npc_gossip`
--

DROP TABLE IF EXISTS `npc_gossip`;
CREATE TABLE `npc_gossip` (
  `npc_guid` int(10) unsigned NOT NULL default '0',
  `textid` mediumint(8) unsigned NOT NULL default '0',
  PRIMARY KEY  (`npc_guid`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `npc_gossip`
--

LOCK TABLES `npc_gossip` WRITE;
/*!40000 ALTER TABLE `npc_gossip` DISABLE KEYS */;
/*!40000 ALTER TABLE `npc_gossip` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `npc_gossip_textid`
--

DROP TABLE IF EXISTS `npc_gossip_textid`;
CREATE TABLE `npc_gossip_textid` (
  `zoneid` smallint(5) unsigned NOT NULL default '0',
  `action` smallint(5) unsigned NOT NULL default '0',
  `textid` mediumint(8) unsigned NOT NULL default '0',
  KEY `zoneid` (`zoneid`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `npc_gossip_textid`
--

LOCK TABLES `npc_gossip_textid` WRITE;
/*!40000 ALTER TABLE `npc_gossip_textid` DISABLE KEYS */;
/*!40000 ALTER TABLE `npc_gossip_textid` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `npc_option`
--

DROP TABLE IF EXISTS `npc_option`;
CREATE TABLE `npc_option` (
  `id` tinyint(3) unsigned NOT NULL default '0',
  `gossip_id` tinyint(3) unsigned NOT NULL default '0',
  `npcflag` int(10) unsigned NOT NULL default '0',
  `icon` tinyint(3) unsigned NOT NULL default '0',
  `action` tinyint(3) unsigned NOT NULL default '0',
  `box_money` int(10) unsigned NOT NULL default '0',
  `coded` tinyint(3) unsigned NOT NULL default '0',
  `option_text` text,
  `box_text` text,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `npc_option`
--

LOCK TABLES `npc_option` WRITE;
/*!40000 ALTER TABLE `npc_option` DISABLE KEYS */;
/*!40000 ALTER TABLE `npc_option` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `npc_text`
--

DROP TABLE IF EXISTS `npc_text`;
CREATE TABLE `npc_text` (
  `ID` mediumint(8) unsigned NOT NULL default '0',
  `text0_0` longtext,
  `text0_1` longtext,
  `lang0` tinyint(3) unsigned NOT NULL default '0',
  `prob0` float NOT NULL default '0',
  `em0_0` smallint(5) unsigned NOT NULL default '0',
  `em0_1` smallint(5) unsigned NOT NULL default '0',
  `em0_2` smallint(5) unsigned NOT NULL default '0',
  `em0_3` smallint(5) unsigned NOT NULL default '0',
  `em0_4` smallint(5) unsigned NOT NULL default '0',
  `em0_5` smallint(5) unsigned NOT NULL default '0',
  `text1_0` longtext,
  `text1_1` longtext,
  `lang1` tinyint(3) unsigned NOT NULL default '0',
  `prob1` float NOT NULL default '0',
  `em1_0` smallint(5) unsigned NOT NULL default '0',
  `em1_1` smallint(5) unsigned NOT NULL default '0',
  `em1_2` smallint(5) unsigned NOT NULL default '0',
  `em1_3` smallint(5) unsigned NOT NULL default '0',
  `em1_4` smallint(5) unsigned NOT NULL default '0',
  `em1_5` smallint(5) unsigned NOT NULL default '0',
  `text2_0` longtext,
  `text2_1` longtext,
  `lang2` tinyint(3) unsigned NOT NULL default '0',
  `prob2` float NOT NULL default '0',
  `em2_0` smallint(5) unsigned NOT NULL default '0',
  `em2_1` smallint(5) unsigned NOT NULL default '0',
  `em2_2` smallint(5) unsigned NOT NULL default '0',
  `em2_3` smallint(5) unsigned NOT NULL default '0',
  `em2_4` smallint(5) unsigned NOT NULL default '0',
  `em2_5` smallint(5) unsigned NOT NULL default '0',
  `text3_0` longtext,
  `text3_1` longtext,
  `lang3` tinyint(3) unsigned NOT NULL default '0',
  `prob3` float NOT NULL default '0',
  `em3_0` smallint(5) unsigned NOT NULL default '0',
  `em3_1` smallint(5) unsigned NOT NULL default '0',
  `em3_2` smallint(5) unsigned NOT NULL default '0',
  `em3_3` smallint(5) unsigned NOT NULL default '0',
  `em3_4` smallint(5) unsigned NOT NULL default '0',
  `em3_5` smallint(5) unsigned NOT NULL default '0',
  `text4_0` longtext,
  `text4_1` longtext,
  `lang4` tinyint(3) unsigned NOT NULL default '0',
  `prob4` float NOT NULL default '0',
  `em4_0` smallint(5) unsigned NOT NULL default '0',
  `em4_1` smallint(5) unsigned NOT NULL default '0',
  `em4_2` smallint(5) unsigned NOT NULL default '0',
  `em4_3` smallint(5) unsigned NOT NULL default '0',
  `em4_4` smallint(5) unsigned NOT NULL default '0',
  `em4_5` smallint(5) unsigned NOT NULL default '0',
  `text5_0` longtext,
  `text5_1` longtext,
  `lang5` tinyint(3) unsigned NOT NULL default '0',
  `prob5` float NOT NULL default '0',
  `em5_0` smallint(5) unsigned NOT NULL default '0',
  `em5_1` smallint(5) unsigned NOT NULL default '0',
  `em5_2` smallint(5) unsigned NOT NULL default '0',
  `em5_3` smallint(5) unsigned NOT NULL default '0',
  `em5_4` smallint(5) unsigned NOT NULL default '0',
  `em5_5` smallint(5) unsigned NOT NULL default '0',
  `text6_0` longtext,
  `text6_1` longtext,
  `lang6` tinyint(3) unsigned NOT NULL default '0',
  `prob6` float NOT NULL default '0',
  `em6_0` smallint(5) unsigned NOT NULL default '0',
  `em6_1` smallint(5) unsigned NOT NULL default '0',
  `em6_2` smallint(5) unsigned NOT NULL default '0',
  `em6_3` smallint(5) unsigned NOT NULL default '0',
  `em6_4` smallint(5) unsigned NOT NULL default '0',
  `em6_5` smallint(5) unsigned NOT NULL default '0',
  `text7_0` longtext,
  `text7_1` longtext,
  `lang7` tinyint(3) unsigned NOT NULL default '0',
  `prob7` float NOT NULL default '0',
  `em7_0` smallint(5) unsigned NOT NULL default '0',
  `em7_1` smallint(5) unsigned NOT NULL default '0',
  `em7_2` smallint(5) unsigned NOT NULL default '0',
  `em7_3` smallint(5) unsigned NOT NULL default '0',
  `em7_4` smallint(5) unsigned NOT NULL default '0',
  `em7_5` smallint(5) unsigned NOT NULL default '0',
  PRIMARY KEY  (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `npc_text`
--

LOCK TABLES `npc_text` WRITE;
/*!40000 ALTER TABLE `npc_text` DISABLE KEYS */;
/*!40000 ALTER TABLE `npc_text` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `npc_trainer`
--

DROP TABLE IF EXISTS `npc_trainer`;
CREATE TABLE `npc_trainer` (
  `entry` mediumint(8) unsigned NOT NULL default '0',
  `spell` mediumint(8) unsigned NOT NULL default '0',
  `spellcost` int(10) unsigned NOT NULL default '0',
  `reqskill` smallint(5) unsigned NOT NULL default '0',
  `reqskillvalue` smallint(5) unsigned NOT NULL default '0',
  `reqlevel` tinyint(3) unsigned NOT NULL default '0',
  PRIMARY KEY  (`entry`,`spell`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `npc_trainer`
--

LOCK TABLES `npc_trainer` WRITE;
/*!40000 ALTER TABLE `npc_trainer` DISABLE KEYS */;
/*!40000 ALTER TABLE `npc_trainer` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `npc_vendor`
--

DROP TABLE IF EXISTS `npc_vendor`;
CREATE TABLE `npc_vendor` (
  `entry` mediumint(8) unsigned NOT NULL default '0',
  `item` mediumint(8) unsigned NOT NULL default '0',
  `maxcount` tinyint(3) unsigned NOT NULL default '0',
  `incrtime` int(10) unsigned NOT NULL default '0',
  `ExtendedCost` mediumint(8) unsigned NOT NULL default '0',
  PRIMARY KEY  (`entry`,`item`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Npc System';

--
-- Dumping data for table `npc_vendor`
--

LOCK TABLES `npc_vendor` WRITE;
/*!40000 ALTER TABLE `npc_vendor` DISABLE KEYS */;
/*!40000 ALTER TABLE `npc_vendor` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `page_text`
--

DROP TABLE IF EXISTS `page_text`;
CREATE TABLE `page_text` (
  `entry` mediumint(8) unsigned NOT NULL default '0',
  `text` longtext NOT NULL,
  `next_page` mediumint(8) unsigned NOT NULL default '0',
  PRIMARY KEY  (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COMMENT='Item System';

--
-- Dumping data for table `page_text`
--

LOCK TABLES `page_text` WRITE;
/*!40000 ALTER TABLE `page_text` DISABLE KEYS */;
/*!40000 ALTER TABLE `page_text` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `pet_levelstats`
--

DROP TABLE IF EXISTS `pet_levelstats`;
CREATE TABLE `pet_levelstats` (
  `creature_entry` mediumint(8) unsigned NOT NULL,
  `level` tinyint(3) unsigned NOT NULL,
  `hp` smallint(5) unsigned NOT NULL,
  `mana` smallint(5) unsigned NOT NULL,
  `armor` int(10) unsigned NOT NULL default '0',
  `str` smallint(5) unsigned NOT NULL,
  `agi` smallint(5) unsigned NOT NULL,
  `sta` smallint(5) unsigned NOT NULL,
  `inte` smallint(5) unsigned NOT NULL,
  `spi` smallint(5) unsigned NOT NULL,
  PRIMARY KEY  (`creature_entry`,`level`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 PACK_KEYS=0 COMMENT='Stores pet levels stats.';

--
-- Dumping data for table `pet_levelstats`
--

LOCK TABLES `pet_levelstats` WRITE;
/*!40000 ALTER TABLE `pet_levelstats` DISABLE KEYS */;
/*!40000 ALTER TABLE `pet_levelstats` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `pet_name_generation`
--

DROP TABLE IF EXISTS `pet_name_generation`;
CREATE TABLE `pet_name_generation` (
  `id` mediumint(8) unsigned NOT NULL auto_increment,
  `word` tinytext NOT NULL,
  `entry` mediumint(8) unsigned NOT NULL default '0',
  `half` tinyint(4) NOT NULL default '0',
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `pet_name_generation`
--

LOCK TABLES `pet_name_generation` WRITE;
/*!40000 ALTER TABLE `pet_name_generation` DISABLE KEYS */;
/*!40000 ALTER TABLE `pet_name_generation` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `petcreateinfo_spell`
--

DROP TABLE IF EXISTS `petcreateinfo_spell`;
CREATE TABLE `petcreateinfo_spell` (
  `entry` mediumint(8) unsigned NOT NULL default '0',
  `Spell1` mediumint(8) unsigned NOT NULL default '0',
  `Spell2` mediumint(8) unsigned NOT NULL default '0',
  `Spell3` mediumint(8) unsigned NOT NULL default '0',
  `Spell4` mediumint(8) unsigned NOT NULL default '0',
  PRIMARY KEY  (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC COMMENT='Pet Create Spells';

--
-- Dumping data for table `petcreateinfo_spell`
--

LOCK TABLES `petcreateinfo_spell` WRITE;
/*!40000 ALTER TABLE `petcreateinfo_spell` DISABLE KEYS */;
/*!40000 ALTER TABLE `petcreateinfo_spell` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `pickpocketing_loot_template`
--

DROP TABLE IF EXISTS `pickpocketing_loot_template`;
CREATE TABLE `pickpocketing_loot_template` (
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

--
-- Dumping data for table `pickpocketing_loot_template`
--

LOCK TABLES `pickpocketing_loot_template` WRITE;
/*!40000 ALTER TABLE `pickpocketing_loot_template` DISABLE KEYS */;
/*!40000 ALTER TABLE `pickpocketing_loot_template` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `player_classlevelstats`
--

DROP TABLE IF EXISTS `player_classlevelstats`;
CREATE TABLE `player_classlevelstats` (
  `class` tinyint(3) unsigned NOT NULL,
  `level` tinyint(3) unsigned NOT NULL,
  `basehp` smallint(5) unsigned NOT NULL,
  `basemana` smallint(5) unsigned NOT NULL,
  PRIMARY KEY  (`class`,`level`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 PACK_KEYS=0 COMMENT='Stores levels stats.';

--
-- Dumping data for table `player_classlevelstats`
--

LOCK TABLES `player_classlevelstats` WRITE;
/*!40000 ALTER TABLE `player_classlevelstats` DISABLE KEYS */;
/*!40000 ALTER TABLE `player_classlevelstats` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `player_levelstats`
--

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

--
-- Dumping data for table `player_levelstats`
--

LOCK TABLES `player_levelstats` WRITE;
/*!40000 ALTER TABLE `player_levelstats` DISABLE KEYS */;
/*!40000 ALTER TABLE `player_levelstats` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `playercreateinfo`
--

DROP TABLE IF EXISTS `playercreateinfo`;
CREATE TABLE `playercreateinfo` (
  `race` tinyint(3) unsigned NOT NULL default '0',
  `class` tinyint(3) unsigned NOT NULL default '0',
  `map` smallint(5) unsigned NOT NULL default '0',
  `zone` mediumint(8) unsigned NOT NULL default '0',
  `position_x` float NOT NULL default '0',
  `position_y` float NOT NULL default '0',
  `position_z` float NOT NULL default '0',
  PRIMARY KEY  (`race`,`class`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `playercreateinfo`
--

LOCK TABLES `playercreateinfo` WRITE;
/*!40000 ALTER TABLE `playercreateinfo` DISABLE KEYS */;
/*!40000 ALTER TABLE `playercreateinfo` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `playercreateinfo_action`
--

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

--
-- Dumping data for table `playercreateinfo_action`
--

LOCK TABLES `playercreateinfo_action` WRITE;
/*!40000 ALTER TABLE `playercreateinfo_action` DISABLE KEYS */;
/*!40000 ALTER TABLE `playercreateinfo_action` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `playercreateinfo_item`
--

DROP TABLE IF EXISTS `playercreateinfo_item`;
CREATE TABLE `playercreateinfo_item` (
  `race` tinyint(3) unsigned NOT NULL default '0',
  `class` tinyint(3) unsigned NOT NULL default '0',
  `itemid` mediumint(8) unsigned NOT NULL default '0',
  `amount` tinyint(3) unsigned NOT NULL default '1',
  KEY `playercreateinfo_race_class_index` (`race`,`class`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `playercreateinfo_item`
--

LOCK TABLES `playercreateinfo_item` WRITE;
/*!40000 ALTER TABLE `playercreateinfo_item` DISABLE KEYS */;
/*!40000 ALTER TABLE `playercreateinfo_item` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `playercreateinfo_spell`
--

DROP TABLE IF EXISTS `playercreateinfo_spell`;
CREATE TABLE `playercreateinfo_spell` (
  `race` tinyint(3) unsigned NOT NULL default '0',
  `class` tinyint(3) unsigned NOT NULL default '0',
  `Spell` mediumint(8) unsigned NOT NULL default '0',
  `Note` varchar(255) default NULL,
  `Active` tinyint(3) unsigned NOT NULL default '1',
  PRIMARY KEY  (`race`,`class`,`Spell`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `playercreateinfo_spell`
--

LOCK TABLES `playercreateinfo_spell` WRITE;
/*!40000 ALTER TABLE `playercreateinfo_spell` DISABLE KEYS */;
/*!40000 ALTER TABLE `playercreateinfo_spell` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `playercreateinfo_spell_custom`
--

DROP TABLE IF EXISTS `playercreateinfo_spell_custom`;
CREATE TABLE `playercreateinfo_spell_custom` (
  `race` tinyint(3) unsigned NOT NULL default '0',
  `class` tinyint(3) unsigned NOT NULL default '0',
  `Spell` mediumint(8) unsigned NOT NULL default '0',
  `Note` varchar(255) default NULL,
  `Active` tinyint(3) unsigned NOT NULL default '1',
  PRIMARY KEY  (`race`,`class`,`Spell`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `playercreateinfo_spell_custom`
--

LOCK TABLES `playercreateinfo_spell_custom` WRITE;
/*!40000 ALTER TABLE `playercreateinfo_spell_custom` DISABLE KEYS */;
/*!40000 ALTER TABLE `playercreateinfo_spell_custom` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `prospecting_loot_template`
--

DROP TABLE IF EXISTS `prospecting_loot_template`;
CREATE TABLE `prospecting_loot_template` (
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

--
-- Dumping data for table `prospecting_loot_template`
--

LOCK TABLES `prospecting_loot_template` WRITE;
/*!40000 ALTER TABLE `prospecting_loot_template` DISABLE KEYS */;
/*!40000 ALTER TABLE `prospecting_loot_template` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `quest_end_scripts`
--

DROP TABLE IF EXISTS `quest_end_scripts`;
CREATE TABLE `quest_end_scripts` (
  `id` mediumint(8) unsigned NOT NULL default '0',
  `delay` int(10) unsigned NOT NULL default '0',
  `command` mediumint(8) unsigned NOT NULL default '0',
  `datalong` mediumint(8) unsigned NOT NULL default '0',
  `datalong2` int(10) unsigned NOT NULL default '0',
  `datatext` text NOT NULL,
  `x` float NOT NULL default '0',
  `y` float NOT NULL default '0',
  `z` float NOT NULL default '0',
  `o` float NOT NULL default '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `quest_end_scripts`
--

LOCK TABLES `quest_end_scripts` WRITE;
/*!40000 ALTER TABLE `quest_end_scripts` DISABLE KEYS */;
/*!40000 ALTER TABLE `quest_end_scripts` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `quest_mail_loot_template`
--

DROP TABLE IF EXISTS `quest_mail_loot_template`;
CREATE TABLE `quest_mail_loot_template` (
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

--
-- Dumping data for table `quest_mail_loot_template`
--

LOCK TABLES `quest_mail_loot_template` WRITE;
/*!40000 ALTER TABLE `quest_mail_loot_template` DISABLE KEYS */;
/*!40000 ALTER TABLE `quest_mail_loot_template` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `quest_start_scripts`
--

DROP TABLE IF EXISTS `quest_start_scripts`;
CREATE TABLE `quest_start_scripts` (
  `id` mediumint(8) unsigned NOT NULL default '0',
  `delay` int(10) unsigned NOT NULL default '0',
  `command` mediumint(8) unsigned NOT NULL default '0',
  `datalong` mediumint(8) unsigned NOT NULL default '0',
  `datalong2` int(10) unsigned NOT NULL default '0',
  `datatext` text NOT NULL,
  `x` float NOT NULL default '0',
  `y` float NOT NULL default '0',
  `z` float NOT NULL default '0',
  `o` float NOT NULL default '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `quest_start_scripts`
--

LOCK TABLES `quest_start_scripts` WRITE;
/*!40000 ALTER TABLE `quest_start_scripts` DISABLE KEYS */;
/*!40000 ALTER TABLE `quest_start_scripts` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `quest_template`
--

DROP TABLE IF EXISTS `quest_template`;
CREATE TABLE `quest_template` (
  `entry` mediumint(8) unsigned NOT NULL default '0',
  `Method` tinyint(3) unsigned NOT NULL default '2',
  `ZoneOrSort` smallint(6) NOT NULL default '0',
  `SkillOrClass` smallint(6) NOT NULL default '0',
  `MinLevel` tinyint(3) unsigned NOT NULL default '0',
  `QuestLevel` tinyint(3) unsigned NOT NULL default '0',
  `Type` smallint(5) unsigned NOT NULL default '0',
  `RequiredRaces` smallint(5) unsigned NOT NULL default '0',
  `RequiredSkillValue` smallint(5) unsigned NOT NULL default '0',
  `RepObjectiveFaction` smallint(5) unsigned NOT NULL default '0',
  `RepObjectiveValue` mediumint(9) NOT NULL default '0',
  `RequiredMinRepFaction` smallint(5) unsigned NOT NULL default '0',
  `RequiredMinRepValue` mediumint(9) NOT NULL default '0',
  `RequiredMaxRepFaction` smallint(5) unsigned NOT NULL default '0',
  `RequiredMaxRepValue` mediumint(9) NOT NULL default '0',
  `SuggestedPlayers` tinyint(3) unsigned NOT NULL default '0',
  `LimitTime` int(10) unsigned NOT NULL default '0',
  `QuestFlags` smallint(5) unsigned NOT NULL default '0',
  `SpecialFlags` tinyint(3) unsigned NOT NULL default '0',
  `CharTitleId` tinyint(3) unsigned NOT NULL default '0',
  `PrevQuestId` mediumint(9) NOT NULL default '0',
  `NextQuestId` mediumint(9) NOT NULL default '0',
  `ExclusiveGroup` mediumint(9) NOT NULL default '0',
  `NextQuestInChain` mediumint(8) unsigned NOT NULL default '0',
  `SrcItemId` mediumint(8) unsigned NOT NULL default '0',
  `SrcItemCount` tinyint(3) unsigned NOT NULL default '0',
  `SrcSpell` mediumint(8) unsigned NOT NULL default '0',
  `Title` text,
  `Details` text,
  `Objectives` text,
  `OfferRewardText` text,
  `RequestItemsText` text,
  `EndText` text,
  `ObjectiveText1` text,
  `ObjectiveText2` text,
  `ObjectiveText3` text,
  `ObjectiveText4` text,
  `ReqItemId1` mediumint(8) unsigned NOT NULL default '0',
  `ReqItemId2` mediumint(8) unsigned NOT NULL default '0',
  `ReqItemId3` mediumint(8) unsigned NOT NULL default '0',
  `ReqItemId4` mediumint(8) unsigned NOT NULL default '0',
  `ReqItemCount1` smallint(5) unsigned NOT NULL default '0',
  `ReqItemCount2` smallint(5) unsigned NOT NULL default '0',
  `ReqItemCount3` smallint(5) unsigned NOT NULL default '0',
  `ReqItemCount4` smallint(5) unsigned NOT NULL default '0',
  `ReqSourceId1` mediumint(8) unsigned NOT NULL default '0',
  `ReqSourceId2` mediumint(8) unsigned NOT NULL default '0',
  `ReqSourceId3` mediumint(8) unsigned NOT NULL default '0',
  `ReqSourceId4` mediumint(8) unsigned NOT NULL default '0',
  `ReqSourceCount1` smallint(5) unsigned NOT NULL default '0',
  `ReqSourceCount2` smallint(5) unsigned NOT NULL default '0',
  `ReqSourceCount3` smallint(5) unsigned NOT NULL default '0',
  `ReqSourceCount4` smallint(5) unsigned NOT NULL default '0',
  `ReqSourceRef1` tinyint(3) unsigned NOT NULL default '0',
  `ReqSourceRef2` tinyint(3) unsigned NOT NULL default '0',
  `ReqSourceRef3` tinyint(3) unsigned NOT NULL default '0',
  `ReqSourceRef4` tinyint(3) unsigned NOT NULL default '0',
  `ReqCreatureOrGOId1` mediumint(9) NOT NULL default '0',
  `ReqCreatureOrGOId2` mediumint(9) NOT NULL default '0',
  `ReqCreatureOrGOId3` mediumint(9) NOT NULL default '0',
  `ReqCreatureOrGOId4` mediumint(9) NOT NULL default '0',
  `ReqCreatureOrGOCount1` smallint(5) unsigned NOT NULL default '0',
  `ReqCreatureOrGOCount2` smallint(5) unsigned NOT NULL default '0',
  `ReqCreatureOrGOCount3` smallint(5) unsigned NOT NULL default '0',
  `ReqCreatureOrGOCount4` smallint(5) unsigned NOT NULL default '0',
  `ReqSpellCast1` mediumint(8) unsigned NOT NULL default '0',
  `ReqSpellCast2` mediumint(8) unsigned NOT NULL default '0',
  `ReqSpellCast3` mediumint(8) unsigned NOT NULL default '0',
  `ReqSpellCast4` mediumint(8) unsigned NOT NULL default '0',
  `RewChoiceItemId1` mediumint(8) unsigned NOT NULL default '0',
  `RewChoiceItemId2` mediumint(8) unsigned NOT NULL default '0',
  `RewChoiceItemId3` mediumint(8) unsigned NOT NULL default '0',
  `RewChoiceItemId4` mediumint(8) unsigned NOT NULL default '0',
  `RewChoiceItemId5` mediumint(8) unsigned NOT NULL default '0',
  `RewChoiceItemId6` mediumint(8) unsigned NOT NULL default '0',
  `RewChoiceItemCount1` smallint(5) unsigned NOT NULL default '0',
  `RewChoiceItemCount2` smallint(5) unsigned NOT NULL default '0',
  `RewChoiceItemCount3` smallint(5) unsigned NOT NULL default '0',
  `RewChoiceItemCount4` smallint(5) unsigned NOT NULL default '0',
  `RewChoiceItemCount5` smallint(5) unsigned NOT NULL default '0',
  `RewChoiceItemCount6` smallint(5) unsigned NOT NULL default '0',
  `RewItemId1` mediumint(8) unsigned NOT NULL default '0',
  `RewItemId2` mediumint(8) unsigned NOT NULL default '0',
  `RewItemId3` mediumint(8) unsigned NOT NULL default '0',
  `RewItemId4` mediumint(8) unsigned NOT NULL default '0',
  `RewItemCount1` smallint(5) unsigned NOT NULL default '0',
  `RewItemCount2` smallint(5) unsigned NOT NULL default '0',
  `RewItemCount3` smallint(5) unsigned NOT NULL default '0',
  `RewItemCount4` smallint(5) unsigned NOT NULL default '0',
  `RewRepFaction1` smallint(5) unsigned NOT NULL default '0' COMMENT 'faction id from Faction.dbc in this case',
  `RewRepFaction2` smallint(5) unsigned NOT NULL default '0' COMMENT 'faction id from Faction.dbc in this case',
  `RewRepFaction3` smallint(5) unsigned NOT NULL default '0' COMMENT 'faction id from Faction.dbc in this case',
  `RewRepFaction4` smallint(5) unsigned NOT NULL default '0' COMMENT 'faction id from Faction.dbc in this case',
  `RewRepFaction5` smallint(5) unsigned NOT NULL default '0' COMMENT 'faction id from Faction.dbc in this case',
  `RewRepValue1` mediumint(9) NOT NULL default '0',
  `RewRepValue2` mediumint(9) NOT NULL default '0',
  `RewRepValue3` mediumint(9) NOT NULL default '0',
  `RewRepValue4` mediumint(9) NOT NULL default '0',
  `RewRepValue5` mediumint(9) NOT NULL default '0',
  `RewHonorableKills` mediumint(9) unsigned NOT NULL default '0',
  `RewOrReqMoney` int(11) NOT NULL default '0',
  `RewMoneyMaxLevel` int(10) unsigned NOT NULL default '0',
  `RewSpell` mediumint(8) unsigned NOT NULL default '0',
  `RewSpellCast` mediumint(8) unsigned NOT NULL default '0',
  `RewMailTemplateId` mediumint(8) unsigned NOT NULL default '0',
  `RewMailDelaySecs` int(11) unsigned NOT NULL default '0',
  `PointMapId` smallint(5) unsigned NOT NULL default '0',
  `PointX` float NOT NULL default '0',
  `PointY` float NOT NULL default '0',
  `PointOpt` mediumint(8) unsigned NOT NULL default '0',
  `DetailsEmote1` smallint(5) unsigned NOT NULL default '0',
  `DetailsEmote2` smallint(5) unsigned NOT NULL default '0',
  `DetailsEmote3` smallint(5) unsigned NOT NULL default '0',
  `DetailsEmote4` smallint(5) unsigned NOT NULL default '0',
  `IncompleteEmote` smallint(5) unsigned NOT NULL default '0',
  `CompleteEmote` smallint(5) unsigned NOT NULL default '0',
  `OfferRewardEmote1` smallint(5) unsigned NOT NULL default '0',
  `OfferRewardEmote2` smallint(5) unsigned NOT NULL default '0',
  `OfferRewardEmote3` smallint(5) unsigned NOT NULL default '0',
  `OfferRewardEmote4` smallint(5) unsigned NOT NULL default '0',
  `StartScript` mediumint(8) unsigned NOT NULL default '0',
  `CompleteScript` mediumint(8) unsigned NOT NULL default '0',
  PRIMARY KEY  (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COMMENT='Quest System';

--
-- Dumping data for table `quest_template`
--

LOCK TABLES `quest_template` WRITE;
/*!40000 ALTER TABLE `quest_template` DISABLE KEYS */;
/*!40000 ALTER TABLE `quest_template` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `reference_loot_template`
--

DROP TABLE IF EXISTS `reference_loot_template`;
CREATE TABLE `reference_loot_template` (
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

--
-- Dumping data for table `reference_loot_template`
--

LOCK TABLES `reference_loot_template` WRITE;
/*!40000 ALTER TABLE `reference_loot_template` DISABLE KEYS */;
/*!40000 ALTER TABLE `reference_loot_template` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `reserved_name`
--

DROP TABLE IF EXISTS `reserved_name`;
CREATE TABLE `reserved_name` (
  `name` varchar(12) NOT NULL default '',
  PRIMARY KEY  (`name`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC COMMENT='Player Reserved Names';

--
-- Dumping data for table `reserved_name`
--

LOCK TABLES `reserved_name` WRITE;
/*!40000 ALTER TABLE `reserved_name` DISABLE KEYS */;
/*!40000 ALTER TABLE `reserved_name` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `script_texts`
--

DROP TABLE IF EXISTS `script_texts`;
CREATE TABLE `script_texts` (
  `entry` mediumint(8) NOT NULL,
  `content_default` text NOT NULL,
  `content_loc1` text,
  `content_loc2` text,
  `content_loc3` text,
  `content_loc4` text,
  `content_loc5` text,
  `content_loc6` text,
  `content_loc7` text,
  `content_loc8` text,
  `sound` mediumint(8) unsigned NOT NULL default '0',
  `type` tinyint(3) unsigned NOT NULL default '0',
  `language` smallint(5) unsigned NOT NULL default '0',
  `emote` smallint(5) UNSIGNED NOT NULL default '0',
  `comment` text,
  PRIMARY KEY  (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Script Texts';

--
-- Dumping data for table `script_texts`
--

LOCK TABLES `script_texts` WRITE;
/*!40000 ALTER TABLE `script_texts` DISABLE KEYS */;
/*!40000 ALTER TABLE `script_texts` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `skill_discovery_template`
--

DROP TABLE IF EXISTS `skill_discovery_template`;
CREATE TABLE `skill_discovery_template` (
  `spellId` mediumint(8) unsigned NOT NULL default '0' COMMENT 'SpellId of the discoverable spell',
  `reqSpell` mediumint(8) unsigned NOT NULL default '0' COMMENT 'spell requirement',
  `chance` float NOT NULL default '0' COMMENT 'chance to discover',
  PRIMARY KEY  (`spellId`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Skill Discovery System';

--
-- Dumping data for table `skill_discovery_template`
--

LOCK TABLES `skill_discovery_template` WRITE;
/*!40000 ALTER TABLE `skill_discovery_template` DISABLE KEYS */;
/*!40000 ALTER TABLE `skill_discovery_template` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `skill_extra_item_template`
--

DROP TABLE IF EXISTS `skill_extra_item_template`;
CREATE TABLE `skill_extra_item_template` (
  `spellId` mediumint(8) unsigned NOT NULL default '0' COMMENT 'SpellId of the item creation spell',
  `requiredSpecialization` mediumint(8) unsigned NOT NULL default '0' COMMENT 'Specialization spell id',
  `additionalCreateChance` float NOT NULL default '0' COMMENT 'chance to create add',
  `additionalMaxNum` tinyint(3) unsigned NOT NULL default '0' COMMENT 'max num of adds',
  PRIMARY KEY  (`spellId`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Skill Specialization System';

--
-- Dumping data for table `skill_extra_item_template`
--

LOCK TABLES `skill_extra_item_template` WRITE;
/*!40000 ALTER TABLE `skill_extra_item_template` DISABLE KEYS */;
/*!40000 ALTER TABLE `skill_extra_item_template` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `skill_fishing_base_level`
--

DROP TABLE IF EXISTS `skill_fishing_base_level`;
CREATE TABLE `skill_fishing_base_level` (
  `entry` mediumint(8) unsigned NOT NULL default '0' COMMENT 'Area identifier',
  `skill` smallint(6) NOT NULL default '0' COMMENT 'Base skill level requirement',
  PRIMARY KEY  (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Fishing system';

--
-- Dumping data for table `skill_fishing_base_level`
--

LOCK TABLES `skill_fishing_base_level` WRITE;
/*!40000 ALTER TABLE `skill_fishing_base_level` DISABLE KEYS */;
/*!40000 ALTER TABLE `skill_fishing_base_level` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `skinning_loot_template`
--

DROP TABLE IF EXISTS `skinning_loot_template`;
CREATE TABLE `skinning_loot_template` (
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

--
-- Dumping data for table `skinning_loot_template`
--

LOCK TABLES `skinning_loot_template` WRITE;
/*!40000 ALTER TABLE `skinning_loot_template` DISABLE KEYS */;
/*!40000 ALTER TABLE `skinning_loot_template` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `spell_affect`
--

DROP TABLE IF EXISTS `spell_affect`;
CREATE TABLE `spell_affect` (
  `entry` smallint(5) unsigned NOT NULL default '0',
  `effectId` tinyint(3) unsigned NOT NULL default '0',
  `SpellFamilyMask` bigint(20) unsigned NOT NULL default '0',
  PRIMARY KEY  (`entry`,`effectId`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `spell_affect`
--

LOCK TABLES `spell_affect` WRITE;
/*!40000 ALTER TABLE `spell_affect` DISABLE KEYS */;
/*!40000 ALTER TABLE `spell_affect` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `spell_required`
--

DROP TABLE IF EXISTS `spell_required`;
CREATE TABLE `spell_required` (
  `spell_id` mediumint(9) NOT NULL default '0',
  `prev_spell` mediumint(9) NOT NULL default '0',
  `req_spell` mediumint(9) NOT NULL default '0',
  PRIMARY KEY  (`spell_id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Spell Additinal Data';

--
-- Dumping data for table `spell_required`
--

LOCK TABLES `spell_required` WRITE;
/*!40000 ALTER TABLE `spell_required` DISABLE KEYS */;
/*!40000 ALTER TABLE `spell_required` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `spell_disabled`
--

DROP TABLE IF EXISTS `spell_disabled`;
CREATE TABLE `spell_disabled` (
  `entry` int(11) unsigned NOT NULL default '0' COMMENT 'Spell entry',
  `disable_mask` int(8) unsigned NOT NULL default '0',
  `comment` varchar(64) NOT NULL default '',
  PRIMARY KEY  (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Disabled Spell System';

--
-- Dumping data for table `spell_disabled`
--

LOCK TABLES `spell_disabled` WRITE;
/*!40000 ALTER TABLE `spell_disabled` DISABLE KEYS */;
/*!40000 ALTER TABLE `spell_disabled` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `spell_elixir`
--

DROP TABLE IF EXISTS `spell_elixir`;
CREATE TABLE `spell_elixir` (
  `entry` int(11) unsigned NOT NULL default '0' COMMENT 'SpellId of potion',
  `mask` tinyint(1) unsigned NOT NULL default '0' COMMENT 'Mask 0x1 battle 0x2 guardian 0x3 flask 0x7 unstable flasks 0xB shattrath flasks',
  PRIMARY KEY  (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Spell System';

--
-- Dumping data for table `spell_elixir`
--

LOCK TABLES `spell_elixir` WRITE;
/*!40000 ALTER TABLE `spell_elixir` DISABLE KEYS */;
/*!40000 ALTER TABLE `spell_elixir` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `spell_learn_spell`
--

DROP TABLE IF EXISTS `spell_learn_spell`;
CREATE TABLE `spell_learn_spell` (
  `entry` smallint(5) unsigned NOT NULL default '0',
  `SpellID` smallint(5) unsigned NOT NULL default '0',
  PRIMARY KEY  (`entry`,`SpellID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Item System';

--
-- Dumping data for table `spell_learn_spell`
--

LOCK TABLES `spell_learn_spell` WRITE;
/*!40000 ALTER TABLE `spell_learn_spell` DISABLE KEYS */;
/*!40000 ALTER TABLE `spell_learn_spell` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `spell_pet_auras`
--

DROP TABLE IF EXISTS `spell_pet_auras`;
CREATE TABLE `spell_pet_auras` (
  `spell` mediumint(8) unsigned NOT NULL COMMENT 'dummy spell id',
  `pet` mediumint(8) unsigned NOT NULL default '0' COMMENT 'pet id; 0 = all',
  `aura` mediumint(8) unsigned NOT NULL COMMENT 'pet aura id',
  PRIMARY KEY  (`spell`,`pet`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `spell_pet_auras`
--

LOCK TABLES `spell_pet_auras` WRITE;
/*!40000 ALTER TABLE `spell_pet_auras` DISABLE KEYS */;
/*!40000 ALTER TABLE `spell_pet_auras` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `spell_proc_event`
--

DROP TABLE IF EXISTS `spell_proc_event`;
CREATE TABLE `spell_proc_event` (
  `entry` smallint(5) unsigned NOT NULL default '0',
  `SchoolMask` tinyint(4) NOT NULL default '0',
  `Category` smallint(6) NOT NULL default '0',
  `SkillID` smallint(6) NOT NULL default '0',
  `SpellFamilyName` smallint(5) unsigned NOT NULL default '0',
  `SpellFamilyMask` bigint(20) unsigned NOT NULL default '0',
  `procFlags` int(10) unsigned NOT NULL default '0',
  `ppmRate` float NOT NULL default '0',
  `cooldown` int(10) unsigned NOT NULL default '0',
  PRIMARY KEY  (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `spell_proc_event`
--

LOCK TABLES `spell_proc_event` WRITE;
/*!40000 ALTER TABLE `spell_proc_event` DISABLE KEYS */;
/*!40000 ALTER TABLE `spell_proc_event` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `spell_script_target`
--

DROP TABLE IF EXISTS `spell_script_target`;
CREATE TABLE `spell_script_target` (
  `entry` mediumint(8) unsigned NOT NULL,
  `type` tinyint(3) unsigned NOT NULL default '0',
  `targetEntry` mediumint(8) unsigned NOT NULL default '0',
  UNIQUE KEY `entry_type_target` (`entry`,`type`,`targetEntry`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COMMENT='Spell System';

--
-- Dumping data for table `spell_script_target`
--

LOCK TABLES `spell_script_target` WRITE;
/*!40000 ALTER TABLE `spell_script_target` DISABLE KEYS */;
/*!40000 ALTER TABLE `spell_script_target` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `spell_scripts`
--

DROP TABLE IF EXISTS `spell_scripts`;
CREATE TABLE `spell_scripts` (
  `id` mediumint(8) unsigned NOT NULL default '0',
  `delay` int(10) unsigned NOT NULL default '0',
  `command` mediumint(8) unsigned NOT NULL default '0',
  `datalong` mediumint(8) unsigned NOT NULL default '0',
  `datalong2` int(10) unsigned NOT NULL default '0',
  `datatext` text character set latin1 NOT NULL,
  `x` float NOT NULL default '0',
  `y` float NOT NULL default '0',
  `z` float NOT NULL default '0',
  `o` float NOT NULL default '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `spell_scripts`
--

LOCK TABLES `spell_scripts` WRITE;
/*!40000 ALTER TABLE `spell_scripts` DISABLE KEYS */;
/*!40000 ALTER TABLE `spell_scripts` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `spell_target_position`
--

DROP TABLE IF EXISTS `spell_target_position`;
CREATE TABLE `spell_target_position` (
  `id` mediumint(8) unsigned NOT NULL default '0' COMMENT 'Identifier',
  `target_map` smallint(5) unsigned NOT NULL default '0',
  `target_position_x` float NOT NULL default '0',
  `target_position_y` float NOT NULL default '0',
  `target_position_z` float NOT NULL default '0',
  `target_orientation` float NOT NULL default '0',
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Spell System';

--
-- Dumping data for table `spell_target_position`
--

LOCK TABLES `spell_target_position` WRITE;
/*!40000 ALTER TABLE `spell_target_position` DISABLE KEYS */;
/*!40000 ALTER TABLE `spell_target_position` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `spell_threat`
--

DROP TABLE IF EXISTS `spell_threat`;
CREATE TABLE `spell_threat` (
  `entry` mediumint(8) unsigned NOT NULL,
  `Threat` smallint(6) NOT NULL,
  PRIMARY KEY  (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED;

--
-- Dumping data for table `spell_threat`
--

LOCK TABLES `spell_threat` WRITE;
/*!40000 ALTER TABLE `spell_threat` DISABLE KEYS */;
/*!40000 ALTER TABLE `spell_threat` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `transports`
--

DROP TABLE IF EXISTS `transports`;
CREATE TABLE `transports` (
  `entry` mediumint(8) unsigned NOT NULL default '0',
  `name` text,
  `period` mediumint(8) unsigned NOT NULL default '0',
  PRIMARY KEY  (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Transports';

--
-- Dumping data for table `transports`
--

LOCK TABLES `transports` WRITE;
/*!40000 ALTER TABLE `transports` DISABLE KEYS */;
/*!40000 ALTER TABLE `transports` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `trinity_string`
--

DROP TABLE IF EXISTS `trinity_string`;
CREATE TABLE `trinity_string` (
  `entry` mediumint(8) unsigned NOT NULL default '0',
  `content_default` text NOT NULL,
  `content_loc1` text,
  `content_loc2` text,
  `content_loc3` text,
  `content_loc4` text,
  `content_loc5` text,
  `content_loc6` text,
  `content_loc7` text,
  `content_loc8` text,
  PRIMARY KEY  (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `trinity_string`
--

LOCK TABLES `trinity_string` WRITE;
/*!40000 ALTER TABLE `trinity_string` DISABLE KEYS */;
/*!40000 ALTER TABLE `trinity_string` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `transport_events`
--

DROP TABLE IF EXISTS `transport_events`;
CREATE TABLE `transport_events` (
 	`entry` int(11) unsigned NOT NULL default '0',
	`waypoint_id` int(11) unsigned NOT NULL default '0',	
  	`event_id` int(11) unsigned NOT NULL default '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `transport_events`
--

LOCK TABLES `transport_events` WRITE;
/*!40000 ALTER TABLE `transport_events` DISABLE KEYS */;
/*!40000 ALTER TABLE `transport_events` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `uptime`
--

DROP TABLE IF EXISTS `uptime`;
CREATE TABLE `uptime` (
  `starttime` bigint(20) unsigned NOT NULL default '0',
  `startstring` varchar(64) NOT NULL default '',
  `uptime` bigint(20) unsigned NOT NULL default '0',
  `maxplayers` smallint(5) unsigned NOT NULL default '0',
  PRIMARY KEY  (`starttime`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC COMMENT='Uptime system';

--
-- Dumping data for table `uptime`
--

LOCK TABLES `uptime` WRITE;
/*!40000 ALTER TABLE `uptime` DISABLE KEYS */;
/*!40000 ALTER TABLE `uptime` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `version`
--

DROP TABLE IF EXISTS `version`;
CREATE TABLE `version` (
    `core_version` varchar(120) default NULL COMMENT 'Core revision dumped at startup.',
    `core_revision` varchar(120) default '0',
    `db_version` varchar(120) default NULL COMMENT 'Version of world DB.',
    `script_version` varchar(120) default NULL COMMENT 'Version of scripts DB.'
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Version Notes';

--
-- Dumping data for table `version`
--

LOCK TABLES `version` WRITE;
/*!40000 ALTER TABLE `version` DISABLE KEYS */;
/*!40000 ALTER TABLE `version` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `waypoint_data`
--

DROP TABLE IF EXISTS `waypoint_data`;
CREATE TABLE `waypoint_data` (
  `id` int(10) unsigned NOT NULL default '0' COMMENT 'Creature GUID',
  `point` mediumint(8) unsigned NOT NULL default '0',
  `position_x` float NOT NULL default '0',
  `position_y` float NOT NULL default '0',
  `position_z` float NOT NULL default '0',
  `delay` int(10) unsigned NOT NULL default '0',
  `move_flag` tinyint(1) NOT NULL default '0',
  `action` int(11) NOT NULL default '0',
  `action_chance` smallint(3) NOT NULL default '100',
  `wpguid` int(11) NOT NULL default '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `waypoint_data`
--

LOCK TABLES `waypoint_data` WRITE;
/*!40000 ALTER TABLE `waypoint_data` DISABLE KEYS */;
/*!40000 ALTER TABLE `waypoint_data` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `waypoint_scripts`
--

DROP TABLE IF EXISTS `waypoint_scripts`;
CREATE TABLE `waypoint_scripts` (
  `id` int(11) unsigned NOT NULL default '0',
  `delay` int(11) unsigned NOT NULL default '0',
  `command` int(11) unsigned NOT NULL default '0',
  `datalong` int(11) unsigned NOT NULL default '0',
  `datalong2` int(11) unsigned NOT NULL default '0',
  `dataint` int(11) unsigned NOT NULL default '0',
  `x` float NOT NULL default '0',
  `y` float NOT NULL default '0',
  `z` float NOT NULL default '0',
  `o` float NOT NULL default '0',
  `guid` int(11) NOT NULL default '0',
  PRIMARY KEY  (`guid`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `waypoint_scripts`
--

LOCK TABLES `waypoint_scripts` WRITE;
/*!40000 ALTER TABLE `waypoint_scripts` DISABLE KEYS */;
/*!40000 ALTER TABLE `waypoint_scripts` ENABLE KEYS */;
UNLOCK TABLES;

/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2008-10-14 13:23:35
