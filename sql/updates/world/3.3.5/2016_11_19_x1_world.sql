UPDATE `command` SET `help`='Syntax: .gobject turn [guid|link] [oz [oy [ox]]]\r\n\r\nSet the orientation of the gameobject to player\'s orientation or the given orientation.' WHERE  `name`='gobject turn';
UPDATE `trinity_string` SET `content_default`='>> Add Game Object \'%u\' (%s) (GUID: %u) added at \'%f %f %f\'.' WHERE  `entry`=525;
UPDATE `command` SET `name`='event info', `help`='Syntax: .event info #event_id\r\nShow details about event with #event_id.' WHERE  `name`='event';
