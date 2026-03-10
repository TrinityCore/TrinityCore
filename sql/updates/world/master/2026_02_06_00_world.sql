-- TDB 1200.26021 world
UPDATE `version` SET `db_version`='TDB 1200.26021', `cache_id`=26021 LIMIT 1;
UPDATE `updates` SET `state`='ARCHIVED',`speed`=0;
REPLACE INTO `updates_include` (`path`, `state`) VALUES ('$/sql/old/12.x/world', 'ARCHIVED');
