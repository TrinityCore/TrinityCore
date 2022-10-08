ALTER TABLE `world_states`   
	ADD COLUMN `ScriptName` VARCHAR(64) NOT NULL AFTER `MapID`,
	CHANGE `Comment` `Comment` TEXT CHARSET utf8mb4 COLLATE utf8mb4_unicode_ci;

RENAME TABLE `world_states` TO `world_state`;
