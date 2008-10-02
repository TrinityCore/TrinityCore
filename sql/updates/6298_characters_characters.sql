ALTER TABLE characters
  ADD COLUMN death_expire_time bigint(20) unsigned NOT NULL default '0' AFTER zone;
