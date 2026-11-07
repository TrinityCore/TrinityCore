DELETE FROM `build_info` WHERE `build` IN (58123,58162);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(58123,11,0,7,NULL),
(58162,11,0,7,NULL);

DELETE FROM `build_auth_key` WHERE `build`=58123 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=58123 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=58123 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=58123 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=58123 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=58123 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=58123 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=58162 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=58162 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=58162 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=58162 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=58162 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=58162 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=58162 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(58123,'Mac','A64','WoW',0x7C63CE8A068940D4D019C7CF999E3DC7),
(58123,'Mac','A64','WoWC',0xCF2625300DA905CC9B6D10379C58B590),
(58123,'Mac','x64','WoW',0x1B68981860A6EB24BEAA070FD022B3B9),
(58123,'Mac','x64','WoWC',0x3037FB1C6A73F7468DD11180000BB133),
(58123,'Win','A64','WoW',0x84B75C8F0FF380C3B3970EB63AFB4962),
(58123,'Win','x64','WoW',0x29050AA0D62EF99634CCB7B5F9F6AC1E),
(58123,'Win','x64','WoWC',0x2D5EEEAB57AFFE31856D0DEAC73944DA),
(58162,'Mac','A64','WoW',0x086BB93AF9122791E6CDA58A5F20AAC1),
(58162,'Mac','A64','WoWC',0x280BD3A4F223E1D8F3CF893BBFAEFBC5),
(58162,'Mac','x64','WoW',0x47586B32BD556FA08C966D7F4FC9FF24),
(58162,'Mac','x64','WoWC',0xE861315673972C1B986650C1242196FE),
(58162,'Win','A64','WoW',0x5B1F97D43762F0F1BEC75E99CDD18D35),
(58162,'Win','x64','WoW',0xDA3B48B9A60F4486F27BA9D8858D5688),
(58162,'Win','x64','WoWC',0x25146ED771DC629F2B8CF58126BA562C);

UPDATE `realmlist` SET `gamebuild`=58162 WHERE `gamebuild` IN (57689,58123);

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '58162';
