DELETE FROM `build_info` WHERE `build` IN (57359);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(57359,4,4,1,NULL);

DELETE FROM `build_auth_key` WHERE `build`=57359 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=57359 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=57359 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=57359 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(57359,'Mac','A64','WoW',0x876DE28FA3F827BC7A1772682C63FB5E),
(57359,'Mac','x64','WoW',0x4CEAE55260F4D660CED9B8CFDA00C6F4),
(57359,'Win','A64','WoW',0x3A8AE83F4A0C497DC6AF62AFEBA04DC4),
(57359,'Win','x64','WoW',0x262A900D4BB08CB24D304AFF6A7FF8EE);

UPDATE `realmlist` SET `gamebuild`=57359 WHERE `gamebuild`=57294;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '57359';
