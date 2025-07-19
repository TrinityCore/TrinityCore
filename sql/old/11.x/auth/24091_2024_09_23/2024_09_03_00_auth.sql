-- TDB 1102.24091 auth
UPDATE `updates` SET `state`='ARCHIVED',`speed`=0;
REPLACE INTO `updates_include` (`path`, `state`) VALUES ('$/sql/old/11.x/auth', 'ARCHIVED');
