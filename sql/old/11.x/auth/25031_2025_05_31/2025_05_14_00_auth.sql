DELETE FROM `build_info` WHERE `build` IN (60822);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(60822,11,1,5,NULL);

DELETE FROM `build_auth_key` WHERE `build`=60822 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=60822 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=60822 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=60822 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=60822 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=60822 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=60822 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(60822,'Mac','A64','WoW',0xAFC18687E2318BB620E4972B5A3D69BF),
(60822,'Mac','A64','WoWC',0x9F6E6D114F14EED0D0FB202842572E2E),
(60822,'Mac','x64','WoW',0xDE216E4A7FA5861A9526E4914CFD867A),
(60822,'Mac','x64','WoWC',0xC07CBC1D65C06EDCC6D90914A59D76DA),
(60822,'Win','A64','WoW',0x5696DD4936320D7F8781688A0730950A),
(60822,'Win','x64','WoW',0x3AAC5F8EB768DFC9161C1506903E19AB),
(60822,'Win','x64','WoWC',0x0B5F6A7B210ED77012F4341DEF9445F7);

UPDATE `realmlist` SET `gamebuild`=60822 WHERE `gamebuild`=60568;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '60822';
