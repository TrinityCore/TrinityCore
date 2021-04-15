ALTER TABLE `gameobject_respawn`
    CHANGE `respawntime` `respawnTime` int(10) unsigned NOT NULL DEFAULT '0',
    CHANGE `instance` `instanceId` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Instance Identifier';
