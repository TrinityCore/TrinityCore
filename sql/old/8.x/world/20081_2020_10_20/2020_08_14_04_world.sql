-- TDB 837.20081 world
UPDATE `version` SET `db_version`='TDB 837.20081', `cache_id`=20081 LIMIT 1;
UPDATE `updates` SET `state`='ARCHIVED',`speed`=0;
REPLACE INTO `updates_include` (`path`, `state`) VALUES ('$/sql/old/8.x/world', 'ARCHIVED');
