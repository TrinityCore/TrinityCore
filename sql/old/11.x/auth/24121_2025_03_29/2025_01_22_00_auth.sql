DELETE FROM `build_info` WHERE `build` IN (58680);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(58680,11,0,7,NULL);

DELETE FROM `build_auth_key` WHERE `build`=58680 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=58680 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=58680 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=58680 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=58680 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=58680 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(58680,'Mac','A64','WoW',0x5EE6ABE5386E08867F642B3DFD15A9D4),
(58680,'Mac','A64','WoWC',0x22C636BB4ABBC4AD9AE8F30B6D947774),
(58680,'Mac','x64','WoWC',0xA5FF81211CDCDD60B53C14F932732969),
(58680,'Win','A64','WoW',0x9D6DC8BED265C898836593A9E654A1E1),
(58680,'Win','x64','WoW',0xC1CEFF499F2C2ABF1913E55F65CF278C),
(58680,'Win','x64','WoWC',0x0D6FC77C1D3830AAA871A9E29DCBE380);

UPDATE `realmlist` SET `gamebuild`=58680 WHERE `gamebuild`=58630;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '58680';
