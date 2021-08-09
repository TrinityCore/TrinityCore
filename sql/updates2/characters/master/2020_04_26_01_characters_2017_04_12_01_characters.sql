ALTER TABLE `creature_respawn` CHANGE `respawnTime` `respawnTime` bigint(20) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `gameobject_respawn` CHANGE `respawnTime` `respawnTime` bigint(20) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `instance` CHANGE `resettime` `resettime` bigint(20) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `instance_reset` CHANGE `resettime` `resettime` bigint(20) unsigned NOT NULL DEFAULT '0';