-- TDB 442.26081 world
UPDATE `version` SET `db_version`='TDB 442.26081', `cache_id`=26081 LIMIT 1;
UPDATE `updates` SET `state`='ARCHIVED',`speed`=0;
REPLACE INTO `updates_include` (`path`, `state`) VALUES ('$/sql/old/4.4.x/world', 'ARCHIVED');
