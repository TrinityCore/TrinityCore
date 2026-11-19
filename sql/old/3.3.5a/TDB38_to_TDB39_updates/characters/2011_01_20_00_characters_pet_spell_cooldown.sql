ALTER TABLE `pet_spell_cooldown`
CHANGE `guid` `guid` INT(10) UNSIGNED DEFAULT '0' NOT NULL COMMENT 'Global Unique Identifier, Low part',
CHANGE `spell` `spell` MEDIUMINT(8) UNSIGNED DEFAULT '0' NOT NULL COMMENT 'Spell Identifier',
CHANGE `time` `time` INT(10) UNSIGNED DEFAULT '0' NOT NULL;