-- TDB 1005.23021 auth
UPDATE `updates` SET `state`='ARCHIVED',`speed`=0;
REPLACE INTO `updates_include` (`path`, `state`) VALUES ('$/sql/old/10.x/auth', 'ARCHIVED');
