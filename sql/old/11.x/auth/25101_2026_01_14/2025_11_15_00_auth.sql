DELETE FROM `build_info` WHERE `build` IN (64395);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(64395,11,2,5,NULL);

DELETE FROM `build_auth_key` WHERE `build`=64395 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=64395 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=64395 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=64395 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=64395 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=64395 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=64395 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(64395,'Mac','A64','WoW',0x4359DE80C563F692768A35B79CD50056),
(64395,'Mac','A64','WoWC',0x6E47FFCC59C09705FDAAEAE2A55BD95F),
(64395,'Mac','x64','WoW',0x2D612B841DE59198FDEB4819508DD879),
(64395,'Mac','x64','WoWC',0xB9EE0DED365A0D1ADCC780CF91708136),
(64395,'Win','A64','WoW',0x3084B511A81DBD956D09C74BE18E6C12),
(64395,'Win','x64','WoW',0x927C362C2B951B50D63F203C88BBB4BD),
(64395,'Win','x64','WoWC',0xB00C9B95D14079E04B937B0DED2C1247);

UPDATE `realmlist` SET `gamebuild`=64395 WHERE `gamebuild`=64270;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '64395';
