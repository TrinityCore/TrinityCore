-- TDB 1210.26091 characters
UPDATE `updates` SET `state`='ARCHIVED',`speed`=0;
REPLACE INTO `updates_include` (`path`, `state`) VALUES ('$/sql/old/12.x/characters', 'ARCHIVED');
