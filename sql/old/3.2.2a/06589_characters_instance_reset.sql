ALTER TABLE instance_reset
  ADD COLUMN difficulty tinyint(1) unsigned NOT NULL default '0' AFTER mapid,
  DROP PRIMARY KEY,
  ADD  PRIMARY KEY  (`mapid`,`difficulty`);