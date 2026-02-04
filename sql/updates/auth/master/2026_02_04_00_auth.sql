DELETE FROM `build_info` WHERE `build` IN (65699);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(65699,12,0,0,NULL);

DELETE FROM `build_auth_key` WHERE `build`=65699 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=65699 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=65699 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=65699 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=65699 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=65699 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=65699 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(65699,'Mac','A64','WoW',0x99F019A567847CAA4AC0DECAA65B8E5F),
(65699,'Mac','A64','WoWC',0xE00A3E912B4AF02A8A73C098C8F0AB6A),
(65699,'Mac','x64','WoW',0x1CB6CEC1096BE0E47E8F93926A313DB3),
(65699,'Mac','x64','WoWC',0x8A89A9667C683F850BE2DF072CA32DC0),
(65699,'Win','A64','WoW',0xEF93325AD77048AED046477629C143C1),
(65699,'Win','x64','WoW',0xBD8A12611753BC1CFBAF50D93FC3F98B),
(65699,'Win','x64','WoWC',0x4F7D2B451DC4039CF10DD51056D918A3);

UPDATE `realmlist` SET `gamebuild`=65699 WHERE `gamebuild`=65655;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '65699';
