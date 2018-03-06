-- TDB 720.00 world
DELETE FROM `updates_include` WHERE `path`='$/sql/old/7/world';
INSERT INTO `updates_include` (`path`, `state`) VALUES ('$/sql/old/7/world', 'ARCHIVED');
UPDATE `updates` SET `state`='ARCHIVED';
UPDATE `version` SET `db_version`='TDB 720.00', `cache_id`=6 LIMIT 1;
