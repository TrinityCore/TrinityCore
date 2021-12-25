-- TDB 910.21101 world
UPDATE `version` SET `db_version`='TDB 910.21101', `cache_id`=21101 LIMIT 1;
UPDATE `updates` SET `state`='ARCHIVED',`speed`=0;
REPLACE INTO `updates_include` (`path`, `state`) VALUES ('$/sql/old/9.x/world', 'ARCHIVED');
