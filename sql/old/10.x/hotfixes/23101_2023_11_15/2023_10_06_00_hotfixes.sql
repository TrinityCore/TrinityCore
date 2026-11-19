-- TDB 1017.23101 hotfixes
UPDATE `updates` SET `state`='ARCHIVED',`speed`=0;
REPLACE INTO `updates_include` (`path`, `state`) VALUES ('$/sql/old/10.x/hotfixes', 'ARCHIVED');
