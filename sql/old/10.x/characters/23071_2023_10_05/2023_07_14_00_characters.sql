-- TDB 1015.23071 characters
UPDATE `updates` SET `state`='ARCHIVED',`speed`=0;
REPLACE INTO `updates_include` (`path`, `state`) VALUES ('$/sql/old/10.x/characters', 'ARCHIVED');
