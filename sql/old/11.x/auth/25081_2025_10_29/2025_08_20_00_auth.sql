DELETE FROM `build_info` WHERE `build` IN (62706);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(62706,11,2,0,NULL);

DELETE FROM `build_auth_key` WHERE `build`=62706 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=62706 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=62706 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=62706 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=62706 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=62706 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=62706 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(62706,'Mac','A64','WoW',0x7372D28C666F784572DD68134C7BE334),
(62706,'Mac','A64','WoWC',0x051D00671FF57B9EDB916F132486DB36),
(62706,'Mac','x64','WoW',0xC38F4C4BE255E157128BC8A37B462F13),
(62706,'Mac','x64','WoWC',0xBCFAE421FED4748F8B02AE95E967EEED),
(62706,'Win','A64','WoW',0x30ACDD80A1EB57C6A7F2E42F00FC7D23),
(62706,'Win','x64','WoW',0xE2D46634684B91376459DB726284F1E2),
(62706,'Win','x64','WoWC',0xB09CA7D4EC722C8F3D8190A540AD4146);

UPDATE `realmlist` SET `gamebuild`=62706 WHERE `gamebuild`=62680;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '62706';
