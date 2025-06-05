DELETE FROM `build_info` WHERE `build` IN (60228);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(60228,11,1,0,NULL);

DELETE FROM `build_auth_key` WHERE `build`=60228 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=60228 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=60228 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=60228 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=60228 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=60228 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=60228 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(60228,'Mac','A64','WoW',0xB14CFCF7D92AE48EFCF4BCC7D263039D),
(60228,'Mac','A64','WoWC',0xF3D26ACC7F83A3FC6CEB494818C27756),
(60228,'Mac','x64','WoW',0x8BB5518B0818D0FD086A055D06AD2515),
(60228,'Mac','x64','WoWC',0x9F1CE1C8259537F6B0F8B9BCC423D241),
(60228,'Win','A64','WoW',0xD05C9119A81C564EDC48EABFB6F9D06F),
(60228,'Win','x64','WoW',0x5B6F19D30DCC37D1C3D9CB94A44EB34E),
(60228,'Win','x64','WoWC',0xCEC40F04254DFD2314D1AAC86762182A);

UPDATE `realmlist` SET `gamebuild`=60228 WHERE `gamebuild`=60189;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '60228';
