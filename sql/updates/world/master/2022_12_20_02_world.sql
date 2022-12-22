-- TDB 1002.22121 world
UPDATE `version` SET `db_version`='TDB 1002.22121', `cache_id`=22121 LIMIT 1;
UPDATE `updates` SET `state`='ARCHIVED',`speed`=0;
REPLACE INTO `updates_include` (`path`, `state`) VALUES ('$/sql/old/10.x/world', 'ARCHIVED');
