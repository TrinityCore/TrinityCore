DELETE FROM `build_info` WHERE `build` IN (65727);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(65727,12,0,0,NULL);

DELETE FROM `build_auth_key` WHERE `build`=65727 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=65727 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=65727 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=65727 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=65727 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=65727 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=65727 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(65727,'Mac','A64','WoW',0xDFBCE4A4A707A6E40B826BC765CFD2C3),
(65727,'Mac','A64','WoWC',0xB592E8CC636F8C8D0942273CBD888ED3),
(65727,'Mac','x64','WoW',0xA2DD238DF367395ADB4218369057E9AF),
(65727,'Mac','x64','WoWC',0x6B0B37F8F3D87736FA9C82009ACD0CFB),
(65727,'Win','A64','WoW',0xEFAB5EAAC583CBF8D5B1F78E3FEB7004),
(65727,'Win','x64','WoW',0xC2D8FE2AB89A557A0700B53B04B2E152),
(65727,'Win','x64','WoWC',0xC25BCE27CE4DC62302FAC67BB2ABCF2A);

UPDATE `realmlist` SET `gamebuild`=65727 WHERE `gamebuild`=65699;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '65727';
