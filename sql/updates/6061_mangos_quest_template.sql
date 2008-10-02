ALTER TABLE quest_template
  ADD COLUMN `RewMailTemplateId` mediumint(8) unsigned NOT NULL default '0' AFTER `RewSpellCast`,
  ADD COLUMN `RewMailDelaySecs` int(11) unsigned NOT NULL default '0' AFTER `RewMailTemplateId`;
