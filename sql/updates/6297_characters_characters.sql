ALTER TABLE characters
  CHANGE `logout_time` `logout_time` bigint(20) unsigned NOT NULL default '0',
  DROP `last_honor_date`,
  DROP `last_kill_date`;
