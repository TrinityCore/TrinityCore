DELETE FROM `build_info` WHERE `build` IN (66017);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(66017,12,0,1,NULL);

DELETE FROM `build_auth_key` WHERE `build`=66017 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=66017 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=66017 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=66017 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=66017 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=66017 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=66017 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(66017,'Mac','A64','WoW',0x3A6281BB06D98E0FE3A77E33C1B20A14),
(66017,'Mac','A64','WoWC',0x5F819CF149A8FA084138118BB6F3B6F5),
(66017,'Mac','x64','WoW',0x3EBAB7AA582A2DC0142686FBE1B1BC22),
(66017,'Mac','x64','WoWC',0x30B479D4D0A2AB34E0F60975D76DADBE),
(66017,'Win','A64','WoW',0x4B54E3099ABDC90D87FE76C6F6705114),
(66017,'Win','x64','WoW',0xACE3EABDC640DA11F4E44D2E2AB62D2E),
(66017,'Win','x64','WoWC',0x28494443B571597C180EF82C320324CD);

UPDATE `realmlist` SET `gamebuild`=66017 WHERE `gamebuild`=65940;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '66017';
