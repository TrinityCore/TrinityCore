ALTER TABLE `character_glyphs` CHANGE `spec` `talentGroup` tinyint(3) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `character_talent` CHANGE `spec` `talentGroup` tinyint(3) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `characters` CHANGE `speccount` `talentGroupsCount` tinyint(3) unsigned NOT NULL DEFAULT '1';
ALTER TABLE `characters` CHANGE `activespec` `activeTalentGroup` tinyint(3) unsigned NOT NULL DEFAULT '0';
