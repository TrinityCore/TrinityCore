UPDATE `character_queststatus` SET `itemcount1` = 0 WHERE `itemcount1` > 65535;
UPDATE `character_queststatus` SET `itemcount2` = 0 WHERE `itemcount2` > 65535;
UPDATE `character_queststatus` SET `itemcount3` = 0 WHERE `itemcount3` > 65535;
UPDATE `character_queststatus` SET `itemcount4` = 0 WHERE `itemcount4` > 65535;

ALTER TABLE `character_queststatus` CHANGE `status` `status` TINYINT( 1 ) UNSIGNED NOT NULL DEFAULT 0,
CHANGE `mobcount1` `mobcount1` SMALLINT( 3 ) UNSIGNED NOT NULL DEFAULT 0,
CHANGE `mobcount2` `mobcount2` SMALLINT( 3 ) UNSIGNED NOT NULL DEFAULT 0,
CHANGE `mobcount3` `mobcount3` SMALLINT( 3 ) UNSIGNED NOT NULL DEFAULT 0,
CHANGE `mobcount4` `mobcount4` SMALLINT( 3 ) UNSIGNED NOT NULL DEFAULT 0,
CHANGE `itemcount1` `itemcount1` SMALLINT( 3 ) UNSIGNED NOT NULL DEFAULT 0,
CHANGE `itemcount2` `itemcount2` SMALLINT( 3 ) UNSIGNED NOT NULL DEFAULT 0,
CHANGE `itemcount3` `itemcount3` SMALLINT( 3 ) UNSIGNED NOT NULL DEFAULT 0,
CHANGE `itemcount4` `itemcount4` SMALLINT( 3 ) UNSIGNED NOT NULL DEFAULT 0;
