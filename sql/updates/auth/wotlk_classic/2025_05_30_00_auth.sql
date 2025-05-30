DELETE FROM `build_info` WHERE `build` IN (61075);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(61075,3,4,4,NULL);

DELETE FROM `build_auth_key` WHERE `build`=61075 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=61075 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=61075 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=61075 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=61075 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=61075 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=61075 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(61075,'Mac','A64','WoW',0x00003ECDA7CF694CBBA1ACA106159B0B),
(61075,'Mac','A64','WoWC',0xBA27650060774F778A0C9894C89B3D9E),
(61075,'Mac','x64','WoW',0x23A873A553395B667769445CD984817F),
(61075,'Mac','x64','WoWC',0xF3D1E0A36EA43035F275BFA24BAA9BC8),
(61075,'Win','A64','WoW',0x40D9900253A9CC00C2A602DF3F6A149D),
(61075,'Win','x64','WoW',0xB8AF912E2E2158E0784BDA4E1F067102),
(61075,'Win','x64','WoWC',0xEF809A8D856B94016817779700D8B9FB);

UPDATE `realmlist` SET `gamebuild`=61075 WHERE `gamebuild`=60892;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '61075';
