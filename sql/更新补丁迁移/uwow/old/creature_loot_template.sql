ALTER TABLE `creature_loot_template`
ADD `difficulty` smallint(6) UNSIGNED DEFAULT '0' NOT NULL AFTER maxcount;