ALTER TABLE corpse
  ADD COLUMN corpse_type tinyint(3) unsigned NOT NULL default '0' AFTER bones_flag;

UPDATE corpse
  SET corpse_type = 1 WHERE bones_flag = 0;

ALTER TABLE corpse
  DROP bones_flag;
