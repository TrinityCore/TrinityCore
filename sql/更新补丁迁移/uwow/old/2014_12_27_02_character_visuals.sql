ALTER TABLE `character_visuals` ADD `tabard` INT(11) UNSIGNED DEFAULT '0' NOT NULL AFTER ranged;
ALTER TABLE `character_visuals` ADD `shirt` INT(11) UNSIGNED DEFAULT '0' NOT NULL AFTER tabard;