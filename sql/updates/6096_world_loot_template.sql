
-- Currently utilized in the following tables (1 = default, 0 = disabled)
ALTER TABLE `creature_loot_template` ADD COLUMN `lootmode` SMALLINT UNSIGNED NOT NULL DEFAULT 1 BEFORE `groupid`;
ALTER TABLE `gameobject_loot_template` ADD COLUMN `lootmode` SMALLINT UNSIGNED NOT NULL DEFAULT 1 BEFORE `groupid`;
ALTER TABLE `reference_loot_template` ADD COLUMN `lootmode` SMALLINT UNSIGNED NOT NULL DEFAULT 1 BEFORE `groupid`;

-- Currently not utilized in the following tables (1 = enabled, any other value = disabled)
ALTER TABLE `fishing_loot_template` ADD COLUMN `lootmode` SMALLINT UNSIGNED NOT NULL DEFAULT 1 BEFORE `groupid`;
ALTER TABLE `disenchant_loot_template` ADD COLUMN `lootmode` SMALLINT UNSIGNED NOT NULL DEFAULT 1 BEFORE `groupid`;
ALTER TABLE `item_loot_template` ADD COLUMN `lootmode` SMALLINT UNSIGNED NOT NULL DEFAULT 1 BEFORE `groupid`;
ALTER TABLE `milling_loot_template` ADD COLUMN `lootmode` SMALLINT UNSIGNED NOT NULL DEFAULT 1 BEFORE `groupid`;
ALTER TABLE `pickpocketing_loot_template` ADD COLUMN `lootmode` SMALLINT UNSIGNED NOT NULL DEFAULT 1 BEFORE `groupid`;
ALTER TABLE `prospecting_loot_template` ADD COLUMN `lootmode` SMALLINT UNSIGNED NOT NULL DEFAULT 1 BEFORE `groupid`;
ALTER TABLE `skinning_loot_template` ADD COLUMN `lootmode` SMALLINT UNSIGNED NOT NULL DEFAULT 1 BEFORE `groupid`;
ALTER TABLE `quest_mail_loot_template` ADD COLUMN `lootmode` SMALLINT UNSIGNED NOT NULL DEFAULT 1 BEFORE `groupid`;
