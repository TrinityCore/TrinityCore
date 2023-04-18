DELETE FROM `command` WHERE `name` = 'freeze' or `name` = 'unfreeze' or name = 'listfreeze';
INSERT INTO `command` (`name`,`security`,`help`) VALUES ('freeze','3','语法: .freeze (#player)\r\n\"冻结玩家\" #讲一个玩家进行冻结。');
INSERT INTO `command` (`name`,`security`,`help`) VALUES ('unfreeze','3','语法: .unfreeze (#player)\r\n\"玩家解冻\" #将一个玩家进行解冻。');
INSERT INTO `command` (`name`,`security`,`help`) VALUES ('listfreeze','1','语法: .listfreeze\r\n\r\n查找和输出所有被冻结的玩家。');