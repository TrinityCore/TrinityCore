-- TDB 1210.26091 hotfixes
UPDATE `updates` SET `state`='ARCHIVED',`speed`=0;
REPLACE INTO `updates_include` (`path`, `state`) VALUES ('$/sql/old/12.x/hotfixes', 'ARCHIVED');
