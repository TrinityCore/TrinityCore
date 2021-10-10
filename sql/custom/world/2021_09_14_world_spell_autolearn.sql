CREATE TABLE `spell_autolearn` (
	`spell` INT(10) UNSIGNED NOT NULL,
	`racemask` INT(10) UNSIGNED NOT NULL DEFAULT '0',
	`classmask` INT(10) UNSIGNED NOT NULL DEFAULT '0',
	`level` INT(10) UNSIGNED NOT NULL DEFAULT '0',
	PRIMARY KEY (`spell`, `racemask`, `classmask`)
)