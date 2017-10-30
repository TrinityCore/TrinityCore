-- TDB 720.00 hotfixes
DELETE FROM `updates_include` WHERE `path`='$/sql/old/7/hotfixes';
INSERT INTO `updates_include` (`path`, `state`) VALUES ('$/sql/old/7/hotfixes', 'ARCHIVED');
UPDATE `updates` SET `state`='ARCHIVED';
