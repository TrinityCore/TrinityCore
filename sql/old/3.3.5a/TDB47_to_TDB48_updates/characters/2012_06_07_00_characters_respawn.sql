ALTER TABLE `creature_respawn` ADD `mapId` SMALLINT(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `respawnTime`;
ALTER TABLE `gameobject_respawn` ADD `mapId` SMALLINT(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `respawnTime`;
