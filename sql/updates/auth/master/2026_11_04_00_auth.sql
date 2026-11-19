DELETE FROM `build_info` WHERE `build` IN (70783);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(70783,12,1,5,NULL);

DELETE FROM `build_auth_key` WHERE `build`=70783 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=70783 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=70783 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=70783 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=70783 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=70783 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=70783 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(70783,'Mac','A64','WoW',0xDB953D2549AE293DD30AD4B0EDADDD99),
(70783,'Mac','A64','WoWC',0x3671A328C0AD12AC3D765C450C6FF1E7),
(70783,'Mac','x64','WoW',0xBD59160580B44FC708AB8E4A27DA17D4),
(70783,'Mac','x64','WoWC',0xE17D1518696CEB34EDA26A09D57E29AF),
(70783,'Win','A64','WoW',0xBD6E0D1D0F932947EB9383560536157C),
(70783,'Win','x64','WoW',0x3195B7C936CFC04CA98D89C3997012FC),
(70783,'Win','x64','WoWC',0xC246FD6597BAA167659F5FBAEA901FE7);

UPDATE `realmlist` SET `gamebuild`=70783 WHERE `gamebuild`=70688;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '70783';
