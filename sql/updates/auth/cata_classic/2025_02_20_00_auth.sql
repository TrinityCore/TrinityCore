DELETE FROM `build_info` WHERE `build` IN (59297);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(59297,4,4,2,NULL);

DELETE FROM `build_auth_key` WHERE `build`=59297 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=59297 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=59297 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=59297 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=59297 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=59297 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=59297 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(59297,'Mac','A64','WoW',0xFE7894BCAFA58F624BC354291683E0F1),
(59297,'Mac','A64','WoWC',0x2D4A7F3417689BB8633DA25B426EC93A),
(59297,'Mac','x64','WoW',0xA8F1B170342E673FBD4F8EB5013E36E2),
(59297,'Mac','x64','WoWC',0xCC0FF87C541C2456F7FB7E1A8DA25855),
(59297,'Win','A64','WoW',0xA3C147112D0D20D267FDCED3F23B428E),
(59297,'Win','x64','WoW',0xA6BC4433D709D113DAC4643BC5B708D9),
(59297,'Win','x64','WoWC',0xC3BD68A0D95B54AD42A81F2612C7EA85);
