ALTER TABLE `quest_template` ADD COLUMN `CharTitleId` tinyint(3) unsigned NOT NULL default '0' AFTER `SpecialFlags`;
ALTER TABLE `quest_template` ADD COLUMN `RewSpellCast` mediumint(8) unsigned NOT NULL default '0' AFTER `RewSpell`;

