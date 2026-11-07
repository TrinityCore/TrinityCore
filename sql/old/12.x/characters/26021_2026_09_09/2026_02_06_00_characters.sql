-- TDB 1200.26021 characters
UPDATE `updates` SET `state`='ARCHIVED',`speed`=0;
REPLACE INTO `updates_include` (`path`, `state`) VALUES ('$/sql/old/12.x/characters', 'ARCHIVED');
