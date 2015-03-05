CREATE TABLE `pool_spawns`
(
  `pool_id` mediumint(8) unsigned NOT NULL,
  `guid` mediumint(8) unsigned NOT NULL,
  `map` smallint(5) unsigned NOT NULL DEFAULT '0',
  `zoneId` smallint(5) unsigned NOT NULL DEFAULT '0',
  `areaId` smallint(5) unsigned NOT NULL DEFAULT '0',
  `position_x` float NOT NULL DEFAULT '0',
  `position_y` float NOT NULL DEFAULT '0',
  `position_z` float NOT NULL DEFAULT '0',
  `orientation` float NOT NULL DEFAULT '0',
  PRIMARY KEY (`pool_id`, `guid`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC COMMENT='Pool Spawn Points';

CREATE TABLE `pool_creature_info`
(
  `pool_id` mediumint(8) unsigned NOT NULL,
  `creature_id` mediumint(8) unsigned NOT NULL,
  `creature_qualifier` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `chance` float NOT NULL DEFAULT '0',
  `spawnMask` tinyint(3) unsigned NOT NULL DEFAULT '1',
  `phaseMask` int(10) unsigned NOT NULL DEFAULT '1',
  `modelid` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `equipment_id` tinyint(3) NOT NULL DEFAULT '0',
  `spawntimesecs` int(10) unsigned NOT NULL DEFAULT '0',
  `corpsetimesecsloot` int(10) unsigned NOT NULL DEFAULT '0',
  `corpsetimesecsnoloot` int(10) unsigned NOT NULL DEFAULT '0',
  `spawndist` float NOT NULL DEFAULT '0',
  `currentwaypoint` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `curhealth` int(10) unsigned NOT NULL DEFAULT '1',
  `curmana` int(10) unsigned NOT NULL DEFAULT '0',
  `MovementType` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `npcflag` int(10) unsigned NOT NULL DEFAULT '0',
  `unit_flags` int(10) unsigned NOT NULL DEFAULT '0',
  `dynamicflags` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`pool_id`, `creature_id`, `creature_qualifier`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC COMMENT='Pool Creature Data';

ALTER TABLE pool_template ADD COLUMN min_limit int(10) unsigned NOT NULL DEFAULT 0 AFTER entry;

