ALTER TABLE `character_queststatus_seasonal` ADD `completedTime` bigint NOT NULL DEFAULT '0' AFTER `event`;

UPDATE `character_queststatus_seasonal` SET `completedTime` = UNIX_TIMESTAMP();

DELETE FROM `worldstates` WHERE `entry` BETWEEN 1 AND 85;
