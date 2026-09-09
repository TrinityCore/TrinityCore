-- TDB 1210.26091 world
UPDATE `version` SET `db_version`='TDB 1210.26091', `cache_id`=26091 LIMIT 1;
UPDATE `updates` SET `state`='ARCHIVED',`speed`=0;
REPLACE INTO `updates_include` (`path`, `state`) VALUES ('$/sql/old/12.x/world', 'ARCHIVED');
