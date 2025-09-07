-- TDB 1117.25071 world
UPDATE `version` SET `db_version`='TDB 1117.25071', `cache_id`=25071 LIMIT 1;
UPDATE `updates` SET `state`='ARCHIVED',`speed`=0;
REPLACE INTO `updates_include` (`path`, `state`) VALUES ('$/sql/old/11.x/world', 'ARCHIVED');
