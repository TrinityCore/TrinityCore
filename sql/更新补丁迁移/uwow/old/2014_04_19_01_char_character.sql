ALTER TABLE  `characters` CHANGE  `instance_mode_mask`  `instance_mode_mask` INT( 11 ) UNSIGNED NOT NULL DEFAULT  '0';
UPDATE `characters` SET instance_mode_mask = 0;