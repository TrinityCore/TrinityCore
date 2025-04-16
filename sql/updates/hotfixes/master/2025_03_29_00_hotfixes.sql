-- TDB 1110.25031 hotfixes
UPDATE `updates` SET `state`='ARCHIVED',`speed`=0;
REPLACE INTO `updates_include` (`path`, `state`) VALUES ('$/sql/old/11.x/hotfixes', 'ARCHIVED');
