ALTER TABLE `character_equipmentsets` ADD `AssignedSpecIndex` int(11) NOT NULL DEFAULT '-1' AFTER `ignore_mask`;

ALTER TABLE `item_instance_artifact` CHANGE `xp` `xp` bigint(20) unsigned NOT NULL DEFAULT '0';
