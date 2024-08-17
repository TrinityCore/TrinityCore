-- TDB 343.24081 world
UPDATE `version` SET `db_version`='TDB 343.24081', `cache_id`=24081 LIMIT 1;
UPDATE `updates` SET `state`='ARCHIVED',`speed`=0;
REPLACE INTO `updates_include` (`path`, `state`) VALUES ('$/sql/old/3.4.x/world', 'ARCHIVED');
