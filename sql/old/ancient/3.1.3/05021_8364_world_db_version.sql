ALTER TABLE version
  ADD COLUMN cache_id int(10) default '0' AFTER script_version;
