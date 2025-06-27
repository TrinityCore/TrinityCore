--
ALTER TABLE `creature_addon` ADD COLUMN `mountEntry` mediumint(8) unsigned NOT NULL AFTER `mount`;
ALTER TABLE `creature_template_addon` ADD COLUMN `mountEntry` mediumint(8) unsigned NOT NULL AFTER `mount`;

UPDATE `creature_template_addon` SET `mountEntry` = 25187 WHERE `entry` = 23346;
UPDATE `creature_template_addon` SET `mountEntry` = 25182 WHERE `entry` = 23344;
