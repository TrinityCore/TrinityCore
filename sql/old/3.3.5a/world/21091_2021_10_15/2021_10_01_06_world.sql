--
ALTER TABLE `creature_addon` CHANGE `mountEntry` `MountCreatureID` int(10) unsigned NOT NULL;
ALTER TABLE `creature_template_addon` CHANGE `mountEntry` `MountCreatureID` int(10) unsigned NOT NULL;
