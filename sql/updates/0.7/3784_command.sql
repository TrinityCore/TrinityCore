DELETE FROM `command` WHERE `name` = 'notify';
INSERT INTO `command` VALUES('notify',1,'Syntax: .notify $MessageToBroadcast\r\n\r\nSend a global message to all players online in screen.');
UPDATE `command` SET help='Syntax: .announce $MessageToBroadcast\r\n\r\nSend a global message to all players online in chat log.' WHERE name='announce';

