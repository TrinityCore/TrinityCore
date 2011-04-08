ALTER TABLE `character_battleground_data`
    CHANGE `instance_id` `instanceId` int(10) unsigned NOT NULL COMMENT 'Instance Identifier',
    CHANGE `join_map` `joinMapId` smallint(5) unsigned NOT NULL DEFAULT '0' COMMENT 'Map Identifier',
    CHANGE `join_x` `joinX` float NOT NULL DEFAULT '0',
    CHANGE `join_y` `joinY` float NOT NULL DEFAULT '0',
    CHANGE `join_z` `joinZ` float NOT NULL DEFAULT '0',
    CHANGE `join_o` `joinO` float NOT NULL DEFAULT '0',
    CHANGE `taxi_start` `taxiStart` int(10) unsigned NOT NULL DEFAULT '0',
    CHANGE `taxi_end` `taxiEnd` int(10) unsigned NOT NULL DEFAULT '0',
    CHANGE `mount_spell` `mountSpell` mediumint(8) unsigned NOT NULL DEFAULT '0';
