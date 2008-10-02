DELETE FROM `command` WHERE `name` = 'item';
DELETE FROM `command` WHERE `name` = 'itemrmv';
DELETE FROM `command` WHERE `name` = 'addvendoritem';
DELETE FROM `command` WHERE `name` = 'delvendoritem';

INSERT INTO `command` VALUES('addvendoritem',2,'Syntax: .addvendoritem #itemId <#maxcount><#incrtime>\r\n\r\nAdd item #itemid to item list of selected vendor. Also optionally set max count item in vendor item list and time to item count restoring.');
INSERT INTO `command` VALUES('delvendoritem',2,'Syntax: .delvendoritem #itemId\r\n\r\nRemove item #itemid from item list of selected vendor.');
