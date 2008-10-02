DELETE FROM `command` WHERE `name` = 'addvendoritem';
INSERT INTO `command` VALUES
('addvendoritem',2,'Syntax: .addvendoritem #itemId <#maxcount><#incrtime><#extendedcost>r\n\r\nAdd item #itemid to item list of selected vendor. Also optionally set max count item in vendor item list and time to item count restoring and items ExtendedCost.');
