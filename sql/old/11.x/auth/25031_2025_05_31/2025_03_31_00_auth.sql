DELETE FROM `build_info` WHERE `build` IN (60037);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(60037,11,1,0,NULL);

DELETE FROM `build_auth_key` WHERE `build`=60037 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=60037 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=60037 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=60037 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=60037 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=60037 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=60037 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(60037,'Mac','A64','WoW',0x2D9FE76E6A93DD0C93DF0D3D8B192FAD),
(60037,'Mac','A64','WoWC',0x7AE0E5804DD7DD5D707BE74DB290C807),
(60037,'Mac','x64','WoW',0xBCD051513C5A8DB78BF7B0A8EC18E5EC),
(60037,'Mac','x64','WoWC',0x64E76DF99C69D852656979829D8600CE),
(60037,'Win','A64','WoW',0x2A4939EC8440AB977FE9282A2CCE3E24),
(60037,'Win','x64','WoW',0x474FF52EF47D47521EF138291B43723D),
(60037,'Win','x64','WoWC',0x75EBBD3C1C1D088F2597E40CA3924B5E);

UPDATE `realmlist` SET `gamebuild`=60037 WHERE `gamebuild`=59888;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '60037';
