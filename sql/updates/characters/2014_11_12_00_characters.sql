ALTER TABLE `character_glyphs` ADD COLUMN `spec` TINYINT(3) UNSIGNED NOT NULL DEFAULT '0';
ALTER TABLE `character_talent` ADD COLUMN `spec` TINYINT(3) UNSIGNED NOT NULL DEFAULT '0';
ALTER TABLE `characters` CHANGE `speccount` `talentGroupsCount` tinyint(3) unsigned NOT NULL DEFAULT '1';
ALTER TABLE `characters` CHANGE `activespec` `activeTalentGroup` tinyint(3) unsigned NOT NULL DEFAULT '0';
