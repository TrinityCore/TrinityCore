DELETE FROM `command` WHERE `name` = 'modify gold'; 
INSERT INTO `command` VALUES('modify money',1,'Syntax:\r\n.modify money #money\r\n.money #money\r\n\r\nAdd or remove money to the selected player. If no player is selected, modify your money.\r\n\r\n #gold can be negative to remove money.');
INSERT INTO `command` VALUES('money',1,'Syntax:\r\n.modify money #money\r\n.money #money\r\n\r\nAdd or remove money to the selected player. If no player is selected, modify your money.\r\n\r\n #gold can be negative to remove money.');
UPDATE `command` SET `help` = 'Syntax:\r\n.modify speed #speed\r\n.speed #speed\r\n\r\nModify the running speed of the selected player. If no player is selected, modify your speed.\r\n\r\n #speed may range from 0 to 50.' WHERE `name` = 'modify speed';
INSERT INTO `command` VALUES('speed',1,'Syntax:\r\n.modify speed #speed\r\n.speed #speed\r\n\r\nModify the running speed of the selected player. If no player is selected, modify your speed.\r\n\r\n #speed may range from 0 to 50.');
DELETE FROM `command` WHERE `name` = 'lookupmob'; 
INSERT INTO `command` VALUES('lookupcreature',3,'Syntax: .lookupcreature $namepart\r\n\r\nLooks up a creature by $namepart, and returns all matches with their creature ID\'s.');

