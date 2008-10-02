ALTER TABLE corpse
  CHANGE time time_old timestamp NOT NULL default '0000-00-00 00:00:00',
  ADD COLUMN time bigint(20) unsigned NOT NULL default '0' AFTER data;

UPDATE corpse
  SET time = UNIX_TIMESTAMP(time_old);

ALTER TABLE corpse
  DROP time_old;
