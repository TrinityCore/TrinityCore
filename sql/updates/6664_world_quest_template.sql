ALTER TABLE `quest_template` ADD `RepObjectiveFaction2` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `RepObjectiveValue`;
ALTER TABLE `quest_template` ADD `RepObjectiveValue2` mediumint(9) NOT NULL DEFAULT 0 AFTER `RepObjectiveFaction2`;

