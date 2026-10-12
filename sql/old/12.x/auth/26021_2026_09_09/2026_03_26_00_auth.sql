DELETE FROM `build_info` WHERE `build` IN (66666);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(66666,12,0,1,NULL);

DELETE FROM `build_auth_key` WHERE `build`=66666 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=66666 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=66666 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=66666 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=66666 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=66666 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=66666 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(66666,'Mac','A64','WoW',0x63DA3BC7E84E15EE58C7503863F96C87),
(66666,'Mac','A64','WoWC',0x00C4CCAB3E1FF64F400FAC50F4133F0E),
(66666,'Mac','x64','WoW',0xD09CC36F366611321CE3B6E3EB1981EB),
(66666,'Mac','x64','WoWC',0x8A98C6903755FD3B4241569B76A92B3F),
(66666,'Win','A64','WoW',0x5BC22F3E44F9E25C24A6EA4716A19B17),
(66666,'Win','x64','WoW',0xAE2F669B86BEC87F325539F9017E7338),
(66666,'Win','x64','WoWC',0xD9BD5A15ED5DCABB77823D9AD30B3E0B);

UPDATE `realmlist` SET `gamebuild`=66666 WHERE `gamebuild`=66562;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '66666';
