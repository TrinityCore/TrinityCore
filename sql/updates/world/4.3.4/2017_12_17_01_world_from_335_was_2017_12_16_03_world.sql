--
ALTER TABLE `creature_template` ADD COLUMN `spell_school_immune_mask` int(3) unsigned NOT NULL DEFAULT '0' AFTER `mechanic_immune_mask`;

