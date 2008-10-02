DELETE FROM `command` WHERE `name` IN ('lookup event','event','event activelist','event start','event stop');

INSERT INTO `command` (`name`,`security`,`help`) VALUES
('lookup event',2,'Syntax: .lookup event $name\r\nAttempts to find the ID of the event with the provided $name.'),
('event',2,'Syntax: .event #event_id\r\nShow details about event with #event_id.'),
('event activelist',2,'Syntax: .event activelist\r\nShow list of currently active events.'),
('event start',2,'Syntax: .event start #event_id\r\nStart event #event_id. Set start time for event to current moment (change not saved in DB).'),
('event stop',2,'Syntax: .event stop #event_id\r\nStop event #event_id. Set start time for event to time in past that make current moment is event stop time (change not saved in DB).');
