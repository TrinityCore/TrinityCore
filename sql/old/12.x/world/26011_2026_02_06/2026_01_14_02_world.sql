-- TDB 1127.26011 world
UPDATE `version` SET `db_version`='TDB 1127.26011', `cache_id`=26011 LIMIT 1;
UPDATE `updates` SET `state`='ARCHIVED',`speed`=0;
REPLACE INTO `updates_include` (`path`, `state`) VALUES ('$/sql/old/11.x/world', 'ARCHIVED');
