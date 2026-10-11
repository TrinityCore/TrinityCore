DELETE FROM `build_info` WHERE `build` IN (67314);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(67314,12,0,5,NULL);

DELETE FROM `build_auth_key` WHERE `build`=67314 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=67314 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=67314 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=67314 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=67314 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=67314 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=67314 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(67314,'Mac','A64','WoW',0x6EED68C3FAE96B65EFC1048F7A0683F7),
(67314,'Mac','A64','WoWC',0xA4ECA4C76304AA666F8623C438A63A74),
(67314,'Mac','x64','WoW',0x0F6292DFEE3EC8F17C0866BFD69A79A2),
(67314,'Mac','x64','WoWC',0x49B611A88AA140811257FFB6D8AC4CAA),
(67314,'Win','A64','WoW',0xF38339612437BADE56FD23DAE7D51C76),
(67314,'Win','x64','WoW',0xA4EDEEFFF3372B893DCB37867DE69FD1),
(67314,'Win','x64','WoWC',0x62498C0192429CA9BAA13D2CA8CA6B12);

UPDATE `realmlist` SET `gamebuild`=67314 WHERE `gamebuild`=67235;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '67314';
