DELETE FROM `build_info` WHERE `build` IN (60430);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(60430,3,4,4,NULL);

DELETE FROM `build_auth_key` WHERE `build`=60430 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=60430 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=60430 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=60430 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=60430 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=60430 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=60430 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(60430,'Mac','A64','WoW',0x609EC45C91EDB8321661544F86B9A096),
(60430,'Mac','A64','WoWC',0x3B6ED9376281DB0E6339A625BB9743F0),
(60430,'Mac','x64','WoW',0xA34871650A57BDD5D2BE82D70C58B5E3),
(60430,'Mac','x64','WoWC',0xBB2A13A903B977D07C309E4DACBB71EB),
(60430,'Win','A64','WoW',0x97F797102416865C120CD4B3EC417262),
(60430,'Win','x64','WoW',0xD3F12533E7E9078A55A81965C446E06E),
(60430,'Win','x64','WoWC',0xEAF61FBF3CA18961A86B62A54191D000);

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '60430';
