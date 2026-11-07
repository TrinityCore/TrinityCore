DELETE FROM `build_info` WHERE `build` IN (68275);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(68275,12,0,7,NULL);

DELETE FROM `build_auth_key` WHERE `build`=68275 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=68275 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=68275 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=68275 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=68275 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=68275 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=68275 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(68275,'Mac','A64','WoW',0xEDDA38F261BC4A68F52F1F9989A61ADB),
(68275,'Mac','A64','WoWC',0x96D17885D4DC5411877EDBEC4E857CA9),
(68275,'Mac','x64','WoW',0x5B38EC1BB973F4828772D27B21F8932A),
(68275,'Mac','x64','WoWC',0x7DB29B27BEFDB6A59EA9C895667B0F67),
(68275,'Win','A64','WoW',0xC314AF40D9FA4D2AB1F754C4AECF197E),
(68275,'Win','x64','WoW',0x6DBF18A96DC21131E7C2D674498C8ACC),
(68275,'Win','x64','WoWC',0x7846A7A3DC8FEA3593165361E452201B);

UPDATE `realmlist` SET `gamebuild`=68275 WHERE `gamebuild`=68256;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '68275';
