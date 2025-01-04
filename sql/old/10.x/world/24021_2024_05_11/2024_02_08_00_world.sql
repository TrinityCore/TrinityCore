-- TDB 1025.24021 world
UPDATE `version` SET `db_version`='TDB 1025.24021', `cache_id`=24021 LIMIT 1;
UPDATE `updates` SET `state`='ARCHIVED',`speed`=0;
REPLACE INTO `updates_include` (`path`, `state`) VALUES ('$/sql/old/10.x/world', 'ARCHIVED');
