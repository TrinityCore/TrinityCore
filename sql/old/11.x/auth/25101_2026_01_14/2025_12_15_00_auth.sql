DELETE FROM `build_info` WHERE `build` IN (64877);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(64877,11,2,7,NULL);

DELETE FROM `build_auth_key` WHERE `build`=64877 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=64877 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=64877 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=64877 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=64877 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=64877 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=64877 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(64877,'Mac','A64','WoW',0xB903471C43EBDC5BABF6FB604A3A5E69),
(64877,'Mac','A64','WoWC',0x3DFEDC25E9BDF2C8C30E0E3F0F6EB6D4),
(64877,'Mac','x64','WoW',0x98464DDFFC9A5786DA1F053EA520BA32),
(64877,'Mac','x64','WoWC',0x01003F46907A168B2BDF036575802098),
(64877,'Win','A64','WoW',0x026ED07009997B857BB37DCBB5B11477),
(64877,'Win','x64','WoW',0x6AB7C89863A9D6CDA9C0FAE710FEB126),
(64877,'Win','x64','WoWC',0xBD52F0D3F7C92642185E963CEA424BD3);

UPDATE `realmlist` SET `gamebuild`=64877 WHERE `gamebuild`=64502;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '64877';
