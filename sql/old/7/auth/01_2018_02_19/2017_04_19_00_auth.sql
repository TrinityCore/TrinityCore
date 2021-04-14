-- TDB 720.00 auth
DELETE FROM `updates_include` WHERE `path`='$/sql/old/7/auth';
INSERT INTO `updates_include` (`path`, `state`) VALUES ('$/sql/old/7/auth', 'ARCHIVED');
UPDATE `updates` SET `state`='ARCHIVED';
