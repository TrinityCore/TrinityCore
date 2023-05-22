-- TDB 1005.23021 world
UPDATE `version` SET `db_version`='TDB 1005.23021', `cache_id`=23021 LIMIT 1;
UPDATE `updates` SET `state`='ARCHIVED',`speed`=0;
REPLACE INTO `updates_include` (`path`, `state`) VALUES ('$/sql/old/10.x/world', 'ARCHIVED');
