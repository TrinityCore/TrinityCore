-- TDB 1125.25101 world
UPDATE `version` SET `db_version`='TDB 1125.25101', `cache_id`=25101 LIMIT 1;
UPDATE `updates` SET `state`='ARCHIVED',`speed`=0;
REPLACE INTO `updates_include` (`path`, `state`) VALUES ('$/sql/old/11.x/world', 'ARCHIVED');
