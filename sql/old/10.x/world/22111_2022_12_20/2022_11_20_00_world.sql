-- TDB 927.22111 world
UPDATE `version` SET `db_version`='TDB 927.22111', `cache_id`=22111 LIMIT 1;
UPDATE `updates` SET `state`='ARCHIVED',`speed`=0;
REPLACE INTO `updates_include` (`path`, `state`) VALUES ('$/sql/old/9.x/world', 'ARCHIVED');
