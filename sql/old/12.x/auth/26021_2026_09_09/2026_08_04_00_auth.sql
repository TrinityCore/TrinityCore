DELETE FROM `build_info` WHERE `build` IN (68974);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(68974,12,0,7,NULL);

DELETE FROM `build_auth_key` WHERE `build`=68974 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=68974 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=68974 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=68974 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=68974 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=68974 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=68974 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(68974,'Mac','A64','WoW',0x85DD40DEE35AB993417DB525B6B77A29),
(68974,'Mac','A64','WoWC',0xFC4DCA5DF2E85C3ECC29B7A378320BBB),
(68974,'Mac','x64','WoW',0x731561ADB563C0DF0FADC297F58EB6B1),
(68974,'Mac','x64','WoWC',0xC45758865E9D79B0AC35B489C0C69891),
(68974,'Win','A64','WoW',0x940DD79F8BF0EEA09A5EAE8200411D50),
(68974,'Win','x64','WoW',0xF76807CCEA2336A3973D3D33EDEF7B76),
(68974,'Win','x64','WoWC',0xE6091ECC24198181EFB2385B83EFD729);

UPDATE `realmlist` SET `gamebuild`=68974 WHERE `gamebuild`=68887;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '68974';
