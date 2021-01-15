--
DELETE FROM `command` WHERE `name`="debug raidreset";
INSERT INTO `command` (`name`,`permission`,`help`) VALUES ("debug raidreset",414,"Syntax: .debug raidreset mapid [difficulty]
Forces a global reset of the specified map on all difficulties (or only the specific difficulty if specified). Effectively the same as setting the specified map's reset timer to now.");

UPDATE `trinity_string` SET `content_default`="Map: %d | ID: %d | perm: %s | extended: %s | diff: %d | canReset: %s | TTR: %s" WHERE `entry`=5045;
