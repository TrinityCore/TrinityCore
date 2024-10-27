DELETE FROM `build_info` WHERE `build` IN (56489);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(56489,4,4,0,NULL);

DELETE FROM `build_auth_key` WHERE `build`=56489 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(56489,'Win','x64','WoW',0xA3FC116BB68FA279DBB66B4024305D99);

UPDATE `realmlist` SET `gamebuild`=56489 WHERE `gamebuild`=56420;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '56489';
