DELETE FROM `trinity_string` WHERE `entry` IN (1151, 1152, 1153, 1154, 1155,1156);
INSERT INTO `trinity_string` (`entry`,`content_default`) VALUES
(1151, 'Mail List Info: # of mails: %u , For Player: %s(%u)'),
(1152, 'Mail Id: %u Title: \"%s\" Money: %ug%us%uc'),
(1153, 'Sender: %s(%u), Receiver: %s(%u)'),
(1154, 'Time deliver: %s, Time expire: %s'),
(1155, 'Item: %s[Entry:%u Guid:%u Count:%u]'),
(1156, 'Mail List Info: No mail found to this character.');

DELETE FROM `command` WHERE `name` = 'list mail';
INSERT INTO `command` (`name`,`security`,`help`) VALUES ('list mail', 3, 'Syntax: .list mail $character\nGive you list of the characters mails they received ');
