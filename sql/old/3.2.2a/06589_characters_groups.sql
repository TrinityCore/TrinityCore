ALTER TABLE `groups`
    ADD COLUMN `raiddifficulty` int(11) UNSIGNED DEFAULT '0' NOT NULL AFTER `difficulty`;