-- TDB 1105.24111 world
UPDATE `version` SET `db_version`='TDB 1105.24111', `cache_id`=24111 LIMIT 1;
UPDATE `updates` SET `state`='ARCHIVED',`speed`=0;
REPLACE INTO `updates_include` (`path`, `state`) VALUES ('$/sql/old/11.x/world', 'ARCHIVED');
