DELETE FROM `command` WHERE `name` IN ('modify aspeed', 'modify bwalk', 'modify fly', 'modify scale', 'modify speed', 'modify swim');
INSERT INTO `command` VALUES
('modify aspeed',1,'Syntax: .modify aspeed #rate\r\n\r\nModify all speeds -run,swim,run back,swim back- of the selected player to \"normalbase speed for this move type\"*rate. If no player is selected, modify your speed.\r\n\r\n #rate may range from 0.1 to 50.'),
('modify bwalk',1,'Syntax: .modify bwalk #rate\r\n\r\nModify the speed of the selected player while running backwards to \"normal walk back speed\"*rate. If no player is selected, modify your speed.\r\n\r\n #rate may range from 0.1 to 50.'),
('modify fly',1,'.modify fly $parameter\nModify the flying speed of the selected player to \"normal flying speed\"*rate. If no player is selected, modify your speed.\n #rate may range from 0.1 to 50.'),
('modify scale',1,'.modify scale $parameter\nModify size of the selected player to \"normal scale\"*rate. If no player is selected, modify your size.\n#rate may range from 0.1 to 10.'),
('modify speed',1,'Syntax: .modify speed #rate\r\n.speed #rate\r\n\r\nModify the running speed of the selected player to \"normal base run speed\"*rate. If no player is selected, modify your speed.\r\n\r\n #rate may range from 0.1 to 50.'),
('modify swim',1,'Syntax: .modify swim #rate\r\n\r\nModify the swim speed of the selected player to \"normal swim speed\"*rate. If no player is selected, modify your speed.\r\n\r\n #rate may range from 0.1 to 50.');
