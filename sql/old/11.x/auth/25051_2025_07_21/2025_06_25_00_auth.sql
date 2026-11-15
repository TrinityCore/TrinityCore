DELETE FROM `build_info` WHERE `build` IN (61609);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(61609,11,1,7,NULL);

DELETE FROM `build_auth_key` WHERE `build`=61609 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=61609 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=61609 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=61609 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=61609 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=61609 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=61609 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(61609,'Mac','A64','WoW',0x9D3B5F3D2DDEB29ABB6DB48EF29D38C9),
(61609,'Mac','A64','WoWC',0x5949F3AE2B51A3B03155A13952E82F77),
(61609,'Mac','x64','WoW',0x7C8665EED3E4C902E8B2FC4972F4636C),
(61609,'Mac','x64','WoWC',0x36FBCBD0CC7A8E88AAAF9BD3CF14FC81),
(61609,'Win','A64','WoW',0x21493F8D8C078FDA669E42AEA8724351),
(61609,'Win','x64','WoW',0x9F18C02CC5868A925CDD4201A8D7F9DA),
(61609,'Win','x64','WoWC',0x15F4CA6C215113B4B47EC3AB65C65419);

UPDATE `realmlist` SET `gamebuild`=61609 WHERE `gamebuild`=61559;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '61609';
