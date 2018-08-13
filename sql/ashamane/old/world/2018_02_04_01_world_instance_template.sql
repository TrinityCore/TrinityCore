ALTER TABLE `instance_template` ADD COLUMN `insideResurrection` TINYINT(3) UNSIGNED DEFAULT 0 NOT NULL AFTER `allowMount`;
