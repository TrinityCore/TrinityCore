-- TDB 440.24101 world
UPDATE `version` SET `db_version`='TDB 440.24101', `cache_id`=24101 LIMIT 1;
UPDATE `updates` SET `state`='ARCHIVED',`speed`=0;
REPLACE INTO `updates_include` (`path`, `state`) VALUES ('$/sql/old/4.4.x/world', 'ARCHIVED');
