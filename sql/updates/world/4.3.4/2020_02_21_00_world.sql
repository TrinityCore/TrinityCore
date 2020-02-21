UPDATE `version` SET `db_version`='TDB 434.35', `cache_id`=35 LIMIT 1;

UPDATE `updates` SET `state`='ARCHIVED';

DELETE FROM `updates_include` WHERE `path`= '$/sql/old/custom/world';
INSERT INTO `updates_include` (`path`, `state`) VALUES
('$/sql/old/custom/world', 'ARCHIVED');
