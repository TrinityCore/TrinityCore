ALTER TABLE `item_instance` ADD `context` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `battlePetDisplayId`;

ALTER TABLE `character_void_storage` ADD `context` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `artifactKnowledgeLevel`;

ALTER TABLE `item_loot_items`
  ADD `context` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `rnd_suffix`,
  ADD `bonus_list_ids` text COMMENT 'Space separated list of bonus list ids' AFTER `context`;
