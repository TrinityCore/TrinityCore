-- TDB 1027.24051 world
UPDATE `version` SET `db_version`='TDB 1027.24051', `cache_id`=24051 LIMIT 1;
UPDATE `updates` SET `state`='ARCHIVED',`speed`=0;
REPLACE INTO `updates_include` (`path`, `state`) VALUES ('$/sql/old/10.x/world', 'ARCHIVED');
