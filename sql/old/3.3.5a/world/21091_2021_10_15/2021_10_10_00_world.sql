--
ALTER TABLE `creature_addon` MODIFY COLUMN `MountCreatureID` int(10) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `creature_template_addon` MODIFY COLUMN `MountCreatureID` int(10) unsigned NOT NULL DEFAULT '0';
