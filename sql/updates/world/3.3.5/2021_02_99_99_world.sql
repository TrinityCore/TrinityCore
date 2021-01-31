--
ALTER TABLE `creature_template_movement` ADD COLUMN `SkipHeightNormalization` TINYINT(3) UNSIGNED DEFAULT NULL NULL COMMENT 'Specifies if Z normalization with map/vmap when building a path should be skipped' AFTER `InteractionPauseTimer`;

ALTER TABLE `creature_movement_override` ADD COLUMN `SkipHeightNormalization` TINYINT(3) UNSIGNED DEFAULT NULL NULL COMMENT 'Specifies if Z normalization with map/vmap when building a path should be skipped' AFTER `InteractionPauseTimer`;
