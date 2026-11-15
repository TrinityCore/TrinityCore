DELETE FROM `build_info` WHERE `build` IN (64484);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(64484,11,2,5,NULL);

DELETE FROM `build_auth_key` WHERE `build`=64484 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=64484 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=64484 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=64484 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=64484 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=64484 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=64484 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(64484,'Mac','A64','WoW',0x208FD6C24C40FDA62A4B3314E4E25336),
(64484,'Mac','A64','WoWC',0xD2D29647DE175101CEF35C10D671BF94),
(64484,'Mac','x64','WoW',0x3B2D2B6D9CE0957F7307E4D8E649B1B0),
(64484,'Mac','x64','WoWC',0x7F843C10B9FE9A3F2C200E8DDEF7CFAD),
(64484,'Win','A64','WoW',0x0D7B806EF0D5640724866D8842590992),
(64484,'Win','x64','WoW',0x2DD6D7583BB976AF101585B572C4CC41),
(64484,'Win','x64','WoWC',0x21F23079D5EA654F8D21B80C93DD1A34);

UPDATE `realmlist` SET `gamebuild`=64484 WHERE `gamebuild`=64395;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '64484';
