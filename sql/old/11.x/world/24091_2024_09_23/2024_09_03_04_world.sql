-- TDB 1102.24091 world
UPDATE `version` SET `db_version`='TDB 1102.24091', `cache_id`=24091 LIMIT 1;
UPDATE `updates` SET `state`='ARCHIVED',`speed`=0;
REPLACE INTO `updates_include` (`path`, `state`) VALUES ('$/sql/old/11.x/world', 'ARCHIVED');
