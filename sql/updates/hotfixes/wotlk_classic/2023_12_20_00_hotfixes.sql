-- TDB 343.23121 hotfixes
UPDATE `updates` SET `state`='ARCHIVED',`speed`=0;
REPLACE INTO `updates_include` (`path`, `state`) VALUES ('$/sql/old/10.x/hotfixes', 'ARCHIVED');
REPLACE INTO `updates_include` (`path`, `state`) VALUES ('$/sql/old/3.4.x/hotfixes', 'ARCHIVED');
