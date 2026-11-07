-- TDB 1025.24021 hotfixes
UPDATE `updates` SET `state`='ARCHIVED',`speed`=0;
REPLACE INTO `updates_include` (`path`, `state`) VALUES ('$/sql/old/10.x/hotfixes', 'ARCHIVED');
