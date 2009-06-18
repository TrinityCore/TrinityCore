DELETE FROM `command` WHERE `name` IN ('go ticket');
INSERT INTO `command` VALUES 
('go ticket','1','Syntax: .go ticket #ticketid\r\nTeleports the user to the location where $ticketid was created.');
