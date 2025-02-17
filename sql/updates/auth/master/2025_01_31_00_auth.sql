DELETE FROM `build_info` WHERE `build` IN (58867);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(58867,11,0,7,NULL);

DELETE FROM `build_auth_key` WHERE `build`=58867 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=58867 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=58867 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=58867 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=58867 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=58867 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=58867 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(58867,'Mac','A64','WoW',0x0BA2958770DFBFDB933851A4AADB4950),
(58867,'Mac','A64','WoWC',0x0D747A5931DF5B155B5CC4892D63E1D8),
(58867,'Mac','x64','WoW',0xA3696DF215AAB11F4F340C5C4393FB89),
(58867,'Mac','x64','WoWC',0xB7C65FC1DA519ED5304019262FEFEFA6),
(58867,'Win','A64','WoW',0xEF8C2258197FDBC6DA5C39699BDEB7A1),
(58867,'Win','x64','WoW',0x7C1627A7325C57FAD21A29D57BBF80A6),
(58867,'Win','x64','WoWC',0x3F8E07E581847B644D6F76489477540D);

UPDATE `realmlist` SET `gamebuild`=58867 WHERE `gamebuild`=58773;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '58867';
