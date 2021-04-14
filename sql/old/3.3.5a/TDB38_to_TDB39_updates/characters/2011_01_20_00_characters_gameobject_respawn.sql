ALTER TABLE `gameobject_respawn`
CHANGE `respawntime` `respawntime` INT(10) UNSIGNED DEFAULT '0' NOT NULL,
CHANGE `instance` `instance` INT(10) UNSIGNED DEFAULT '0' NOT NULL;