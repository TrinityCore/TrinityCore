ALTER TABLE `creature_template` DROP `exp`;
ALTER TABLE `creature_template` ADD `exp` smallint(2) NOT NULL DEFAULT 0 AFTER `maxlevel`;
