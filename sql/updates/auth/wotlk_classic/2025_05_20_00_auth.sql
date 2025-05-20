DELETE FROM `build_info` WHERE `build` IN (60892);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(60892,3,4,4,NULL);

DELETE FROM `build_auth_key` WHERE `build`=60892 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=60892 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=60892 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=60892 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=60892 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=60892 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=60892 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(60892,'Mac','A64','WoW',0xB0B4A1AFCCFAAE39CCB547391628572D),
(60892,'Mac','A64','WoWC',0xCB4622EA4CDEC492944626D9B8054FA5),
(60892,'Mac','x64','WoW',0x4BD5723B0BEC3FDB314BEA2BB349FD29),
(60892,'Mac','x64','WoWC',0x65536EE5AF0E5D29022D3110BAEDAEC1),
(60892,'Win','A64','WoW',0xF181771372B41F7042B2E707DCB709C9),
(60892,'Win','x64','WoW',0x9D0E93C445045C1BD106F5F266EB8B3F),
(60892,'Win','x64','WoWC',0x5E443303F989CF4C067FBD750525C4B3);

UPDATE `realmlist` SET `gamebuild`=60892 WHERE `gamebuild`=60842;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '60892';
