-- TDB 720.00 characters
DELETE FROM `updates_include` WHERE `path`='$/sql/old/7/characters';
INSERT INTO `updates_include` (`path`, `state`) VALUES ('$/sql/old/7/characters', 'ARCHIVED');
UPDATE `updates` SET `state`='ARCHIVED';
