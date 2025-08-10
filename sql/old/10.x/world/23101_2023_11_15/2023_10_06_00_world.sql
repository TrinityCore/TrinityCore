-- TDB 1017.23101 world
UPDATE `version` SET `db_version`='TDB 1017.23101', `cache_id`=23101 LIMIT 1;
UPDATE `updates` SET `state`='ARCHIVED',`speed`=0;
REPLACE INTO `updates_include` (`path`, `state`) VALUES ('$/sql/old/10.x/world', 'ARCHIVED');
