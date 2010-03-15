DELETE FROM `command` WHERE `name`='server shutdown';
INSERT INTO `command` (`name`,`security`,`help`) VALUES ('server shutdown','3','Syntax: .server shutdown #delay [#exit_code]\r\n\r\nShut the server down after #delay seconds. Use #exit_code or 0 as program exit code.');

