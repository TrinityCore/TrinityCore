ALTER TABLE `character_homebind`
    CHANGE `map` `mapId` smallint(5) unsigned NOT NULL DEFAULT '0' COMMENT 'Map Identifier',
    CHANGE `zone` `zoneId` smallint(5) unsigned NOT NULL DEFAULT '0' COMMENT 'Zone Identifier',
    CHANGE `position_x` `posX` float NOT NULL DEFAULT '0',
    CHANGE `position_y` `posY` float NOT NULL DEFAULT '0',
    CHANGE `position_z` `posZ` float NOT NULL DEFAULT '0';
