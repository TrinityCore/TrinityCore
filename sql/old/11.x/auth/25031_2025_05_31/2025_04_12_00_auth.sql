DELETE FROM `build_info` WHERE `build` IN (60257);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(60257,11,1,0,NULL);

DELETE FROM `build_auth_key` WHERE `build`=60257 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=60257 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=60257 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=60257 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=60257 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=60257 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=60257 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(60257,'Mac','A64','WoW',0xB59EBBBA00139714D2CA755DBA71A58A),
(60257,'Mac','A64','WoWC',0x01DCFC44C27452F3B7E33EE6F01E067F),
(60257,'Mac','x64','WoW',0x3A0DB5ECBECCA5C80B704FA405DA5389),
(60257,'Mac','x64','WoWC',0x174D184200D89BF13A62DEDF6E265827),
(60257,'Win','A64','WoW',0x5DE295571BA573F16EC0D27F9B256953),
(60257,'Win','x64','WoW',0x04863309B886141AAB63893CD2414960),
(60257,'Win','x64','WoWC',0x6D386FDACBABA88604AFAE3826FE31FA);

UPDATE `realmlist` SET `gamebuild`=60257 WHERE `gamebuild`=60228;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '60257';
