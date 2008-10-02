ALTER TABLE `character_spell_cooldown` ADD COLUMN `item` int(11) unsigned NOT NULL default '0' COMMENT 'Item Identifier' AFTER `spell`;
