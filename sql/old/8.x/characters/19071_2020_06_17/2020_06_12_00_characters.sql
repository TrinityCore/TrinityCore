ALTER TABLE `character_aura` ADD `difficulty` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `recalculateMask`;
ALTER TABLE `pet_aura` ADD `difficulty` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `recalculateMask`;
