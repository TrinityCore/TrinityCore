DELETE FROM `build_info` WHERE `build` IN (56420);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(56420,4,4,0,NULL);

DELETE FROM `build_auth_key` WHERE `build`=56420 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(56420,'Win','x64','WoW',0xA8E98C37F813D988C81256424A024AB0);

UPDATE `realmlist` SET `gamebuild`=56420 WHERE `gamebuild`=56014;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '56420';
