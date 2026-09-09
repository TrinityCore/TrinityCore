DELETE FROM `build_info` WHERE `build` IN (66220);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(66220,12,0,1,NULL);

DELETE FROM `build_auth_key` WHERE `build`=66220 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=66220 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=66220 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=66220 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=66220 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=66220 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=66220 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(66220,'Mac','A64','WoW',0x4385ED9D10459B4C60EDC870C9EEE17A),
(66220,'Mac','A64','WoWC',0xBB8F1891046195F34FF37D02230B3068),
(66220,'Mac','x64','WoW',0xE69739F70296531F9330F7E766C29D75),
(66220,'Mac','x64','WoWC',0xADE47B3180CAADE4C3E0517CF8184F07),
(66220,'Win','A64','WoW',0xF38707CC641DB628993957D7B2262895),
(66220,'Win','x64','WoW',0x88C34460E28D65B62FA6F1CACE8107E3),
(66220,'Win','x64','WoWC',0x9B3C1C2FB9E9F2401B0F5F2AD6CDA84E);

UPDATE `realmlist` SET `gamebuild`=66220 WHERE `gamebuild`=66198;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '66220';
