DELETE FROM `build_info` WHERE `build` IN (57244);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(57244,4,4,0,NULL);

DELETE FROM `build_auth_key` WHERE `build`=57244 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=57244 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=57244 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=57244 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(57244,'Mac','A64','WoW',0x4DC6904ECDDB8D45209C9A1A1EAFDF34),
(57244,'Mac','x64','WoW',0x0D662EAB1F2F0EC74F6D11F167F378B6),
(57244,'Win','A64','WoW',0x9A849BAEEC89BDBF3ADE5FEDDBB27A74),
(57244,'Win','x64','WoW',0xF972E54BD89E8AD83420C6E3DEFA267F);

UPDATE `realmlist` SET `gamebuild`=57244 WHERE `gamebuild`=56713;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '57244';
