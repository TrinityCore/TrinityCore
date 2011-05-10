ALTER TABLE `instance_template`
DROP COLUMN `startLocX`,
DROP COLUMN `startLocY`,
DROP COLUMN `startLocZ`,
DROP COLUMN `startLocO`,
CHANGE `parent` `parent` SMALLINT(5) UNSIGNED NOT NULL;
