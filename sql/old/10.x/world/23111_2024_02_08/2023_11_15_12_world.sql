-- TDB 1020.23111 world
UPDATE `version` SET `db_version`='TDB 1020.23111', `cache_id`=23111 LIMIT 1;
UPDATE `updates` SET `state`='ARCHIVED',`speed`=0;
REPLACE INTO `updates_include` (`path`, `state`) VALUES ('$/sql/old/10.x/world', 'ARCHIVED');
