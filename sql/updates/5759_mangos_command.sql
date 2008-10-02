DELETE FROM `command` WHERE `name` IN ('gograveyard','drunk');
INSERT INTO `command` VALUES 
('drunk',1,'Syntax: .drunk #value\r\n Set drunk level to #value (0..100). Value 0 remove drunk state, 100 is max drunked state.'),
('gograveyard',2,'Syntax: .gograveyard #graveyardId\r\n Teleport to graveyard with the graveyardId specified.'); 
