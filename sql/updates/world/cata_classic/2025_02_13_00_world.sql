-- TDB 441.25021 world
UPDATE `version` SET `db_version`='TDB 441.25021', `cache_id`=25021 LIMIT 1;
UPDATE `updates` SET `state`='ARCHIVED',`speed`=0;
REPLACE INTO `updates_include` (`path`, `state`) VALUES ('$/sql/old/4.4.x/world', 'ARCHIVED');
