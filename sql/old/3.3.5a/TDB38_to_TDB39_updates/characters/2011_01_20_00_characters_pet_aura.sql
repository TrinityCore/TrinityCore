ALTER TABLE `pet_aura`
ROW_FORMAT=DEFAULT,
CHANGE `guid` `guid` INT(10) UNSIGNED DEFAULT '0' NOT NULL COMMENT 'Global Unique Identifier',
CHANGE `spell` `spell` MEDIUMINT(8) UNSIGNED DEFAULT '0' NOT NULL,
CHANGE `amount0` `amount0` MEDIUMINT(8) NOT NULL,
CHANGE `amount1` `amount1` MEDIUMINT(8) NOT NULL,
CHANGE `amount2` `amount2` MEDIUMINT(8) NOT NULL,
CHANGE `base_amount0` `base_amount0` MEDIUMINT(8) NOT NULL,
CHANGE `base_amount1` `base_amount1` MEDIUMINT(8) NOT NULL,
CHANGE `base_amount2` `base_amount2` MEDIUMINT(8) NOT NULL;