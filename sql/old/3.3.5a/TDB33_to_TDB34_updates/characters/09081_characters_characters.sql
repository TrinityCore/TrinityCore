ALTER TABLE `characters` CHANGE `dungeon_difficulty` `instance_mode_mask`  tinyint(2) UNSIGNED NOT NULL DEFAULT 0 AFTER `instance_id`;
