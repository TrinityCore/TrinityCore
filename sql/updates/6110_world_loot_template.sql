
ALTER TABLE `spell_loot_template` ADD COLUMN `lootmode` SMALLINT UNSIGNED NOT NULL DEFAULT 1 AFTER `ChanceOrQuestChance`;
