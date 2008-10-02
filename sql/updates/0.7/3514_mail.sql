ALTER TABLE `mail`
  CHANGE COLUMN `time` `expire_time` bigint(40) NOT NULL default '0',
  ADD `deliver_time` bigint(40) NOT NULL default '0' AFTER `expire_time`;
