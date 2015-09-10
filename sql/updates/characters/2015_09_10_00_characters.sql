ALTER TABLE `character_spell_cooldown`
  ADD `categoryId` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Spell category Id' AFTER `time`,
  ADD `categoryEnd` int(10) unsigned NOT NULL DEFAULT '0' AFTER `categoryId`;

ALTER TABLE `pet_spell_cooldown`
  ADD `categoryId` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Spell category Id' AFTER `time`,
  ADD `categoryEnd` int(10) unsigned NOT NULL DEFAULT '0' AFTER `categoryId`;
