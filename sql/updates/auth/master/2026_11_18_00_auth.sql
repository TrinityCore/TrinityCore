DELETE FROM `build_info` WHERE `build` IN (70961);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(70961,12,1,5,NULL);

DELETE FROM `build_auth_key` WHERE `build`=70961 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=70961 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=70961 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=70961 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=70961 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=70961 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=70961 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(70961,'Mac','A64','WoW',0xB3E7B53078DFE20AF4EB052A9CE92331),
(70961,'Mac','A64','WoWC',0xC11F69562D5105723BDE9669208A9317),
(70961,'Mac','x64','WoW',0x2BE8C03F4CD11B22A2C22241E048EC02),
(70961,'Mac','x64','WoWC',0x50B323D744C714B80FA50ED5857A4F92),
(70961,'Win','A64','WoW',0xB124B7530201D0FA6486586FA058070E),
(70961,'Win','x64','WoW',0x162AFD0D470E2AF6B534C61C44829451),
(70961,'Win','x64','WoWC',0xD45C544B3E137934D10B00FE3C59FF2C);

UPDATE `realmlist` SET `gamebuild`=70961 WHERE `gamebuild`=70783;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '70961';
