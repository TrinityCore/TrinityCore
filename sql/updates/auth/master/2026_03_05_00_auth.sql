DELETE FROM `build_info` WHERE `build` IN (66263);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(66263,12,0,1,NULL);

DELETE FROM `build_auth_key` WHERE `build`=66263 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=66263 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=66263 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=66263 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=66263 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=66263 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=66263 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(66263,'Mac','A64','WoW',0x21AE3D9DA8DD3D6835C2BBB928821D95),
(66263,'Mac','A64','WoWC',0x7A7D31C2BA2E048E04D88BE613E2450F),
(66263,'Mac','x64','WoW',0x9D5D0EAE5F86691AB886B48A91313C40),
(66263,'Mac','x64','WoWC',0xB4D3757D691FD5C244B029E441B5D000),
(66263,'Win','A64','WoW',0xA81104F0DFA3C4EF63C25465C69AFDD7),
(66263,'Win','x64','WoW',0xD411DB36DC1510355B5F9BB6ADB459D3),
(66263,'Win','x64','WoWC',0x0754C5B79F8C25CA337E47158827190F);

UPDATE `realmlist` SET `gamebuild`=66263 WHERE `gamebuild`=66220;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '66263';
