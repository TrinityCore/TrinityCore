ALTER TABLE `character_social`
ROW_FORMAT=DEFAULT,
CHANGE `guid` `guid` INT(10) UNSIGNED DEFAULT '0' NOT NULL COMMENT 'Character Global Unique Identifier',
CHANGE `friend` `friend` INT(10) UNSIGNED DEFAULT '0' NOT NULL COMMENT 'Friend Global Unique Identifier',
CHANGE `flags` `flags` TINYINT(3) UNSIGNED DEFAULT '0' NOT NULL COMMENT 'Friend Flags',
DROP INDEX `guid`,
DROP INDEX `guid_flags`,
DROP INDEX `friend_flags`;