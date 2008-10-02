ALTER TABLE mail
  ADD COLUMN `mailTemplateId` mediumint(8) unsigned NOT NULL default '0' AFTER `stationery`;
