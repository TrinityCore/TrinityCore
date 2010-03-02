DELETE FROM `command` WHERE `name`='gobject info';
INSERT INTO `command` (`name`,`security`,`help`) VALUES ('gobject info', 2, 'Syntax: .gobject info [$object_entry]\r\n\r\nQuery Gameobject information for selected gameobject or given entry.');
