-- TDB 910.21101 hotfixes
UPDATE `updates` SET `state`='ARCHIVED',`speed`=0;
REPLACE INTO `updates_include` (`path`, `state`) VALUES ('$/sql/old/9.x/hotfixes', 'ARCHIVED');
