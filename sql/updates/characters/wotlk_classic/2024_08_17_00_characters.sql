-- TDB 343.24081 characters
UPDATE `updates` SET `state`='ARCHIVED',`speed`=0;
REPLACE INTO `updates_include` (`path`, `state`) VALUES ('$/sql/old/3.4.x/characters', 'ARCHIVED');
