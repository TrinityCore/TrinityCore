-- TDB 441.25021 characters
UPDATE `updates` SET `state`='ARCHIVED',`speed`=0;
REPLACE INTO `updates_include` (`path`, `state`) VALUES ('$/sql/old/4.4.x/characters', 'ARCHIVED');
