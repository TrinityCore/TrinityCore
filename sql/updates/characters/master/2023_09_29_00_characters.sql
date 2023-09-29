ALTER TABLE `character_stats`
	ADD COLUMN `mastery` FLOAT UNSIGNED NOT NULL DEFAULT '0' AFTER `resilience`;
ALTER TABLE `character_stats`
	ADD COLUMN `versatility` FLOAT UNSIGNED NOT NULL DEFAULT '0' AFTER `mastery`;
