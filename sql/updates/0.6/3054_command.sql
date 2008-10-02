DELETE FROM `command` WHERE `name` = 'searchtele'; 
INSERT INTO `command` VALUES('lookuptele',1,'Syntax: .lookuptele $substring\r\n\r\nSearch and output all .tele command locations with provide $substring in name.');
INSERT INTO `command` VALUES('lookupquest',3,'Syntax: .lookupquest $namepart\r\n\r\nLooks up a quest by $namepart, and returns all matches with their quest ID\'s.');
INSERT INTO `command` VALUES('lookupspell',3,'Syntax: .lookupspell $namepart\r\n\r\nLooks up a spell by $namepart, and returns all matches with their spell ID\'s.');

