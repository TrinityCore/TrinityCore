DELETE FROM `build_info` WHERE `build` IN (64270);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(64270,11,2,5,NULL);

DELETE FROM `build_auth_key` WHERE `build`=64270 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=64270 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=64270 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=64270 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=64270 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=64270 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=64270 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(64270,'Mac','A64','WoW',0x928E0021891CF98BC5727C651400435C),
(64270,'Mac','A64','WoWC',0xEA26214831B30ACBC2512A01E0E7068D),
(64270,'Mac','x64','WoW',0x6D60AB2F23453C2366443D74824630C8),
(64270,'Mac','x64','WoWC',0x8AAB201281BC74F62858CF3493637589),
(64270,'Win','A64','WoW',0xE8DD93206BEB87858012BC2881822691),
(64270,'Win','x64','WoW',0x60EBEDB6842317893E4C317EB449A1B7),
(64270,'Win','x64','WoWC',0x456D3AF6C7EC9967B36DF439C55BD0EE);

UPDATE `realmlist` SET `gamebuild`=64270 WHERE `gamebuild`=64154;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '64270';
