DELETE FROM `build_info` WHERE `build` IN (64154);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(64154,11,2,5,NULL);

DELETE FROM `build_auth_key` WHERE `build`=64154 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=64154 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=64154 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=64154 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=64154 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=64154 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=64154 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(64154,'Mac','A64','WoW',0x2B47687B97FB51EFCC28274BF094EF7B),
(64154,'Mac','A64','WoWC',0x676F3B5CD92799B5CE6ECBFD42EBBC96),
(64154,'Mac','x64','WoW',0xD39F3B03CD34DC2CDDB7173EA9DA008E),
(64154,'Mac','x64','WoWC',0x410B672FD200829F2B39E91CA637DDBD),
(64154,'Win','A64','WoW',0xBDE661AFFD07520A536913612098913A),
(64154,'Win','x64','WoW',0x205D71769E2A1C2C04516A5CE36B35C2),
(64154,'Win','x64','WoWC',0x38F784495ED0129FF391B27EC34548E0);

UPDATE `realmlist` SET `gamebuild`=64154 WHERE `gamebuild`=63906;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '64154';
