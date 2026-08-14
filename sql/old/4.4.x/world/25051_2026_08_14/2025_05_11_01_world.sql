-- TDB 442.25051 world
UPDATE `version` SET `db_version`='TDB 442.25051', `cache_id`=25051 LIMIT 1;
UPDATE `updates` SET `state`='ARCHIVED',`speed`=0;
REPLACE INTO `updates_include` (`path`, `state`) VALUES ('$/sql/old/4.4.x/world', 'ARCHIVED');
