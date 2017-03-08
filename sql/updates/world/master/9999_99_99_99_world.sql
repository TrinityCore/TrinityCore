ALTER TABLE `creature_template` ADD COLUMN `levelScalingDelta` SMALLINT(5) DEFAULT 0 NOT NULL AFTER `maxlevel`, CHANGE `flags_extra` `flags_extra` BIGINT(20) UNSIGNED DEFAULT 0 NOT NULL;
