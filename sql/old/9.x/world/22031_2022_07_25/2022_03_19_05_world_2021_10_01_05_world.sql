--
ALTER TABLE `creature_addon` ADD COLUMN `MountCreatureID` int unsigned NOT NULL AFTER `mount`;
ALTER TABLE `creature_template_addon` ADD COLUMN `MountCreatureID` int unsigned NOT NULL AFTER `mount`;

UPDATE `creature_template_addon` SET `MountCreatureID` = 25187 WHERE `entry` = 23346;
UPDATE `creature_template_addon` SET `MountCreatureID` = 25182 WHERE `entry` = 23344;
