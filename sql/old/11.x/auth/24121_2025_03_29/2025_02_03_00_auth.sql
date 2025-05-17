DELETE FROM `build_info` WHERE `build` IN (58911);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(58911,11,0,7,NULL);

DELETE FROM `build_auth_key` WHERE `build`=58911 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=58911 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=58911 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=58911 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=58911 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=58911 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=58911 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(58911,'Mac','A64','WoW',0xDEE67D3A0C9D8EDD5A94C7BD8FA1E657),
(58911,'Mac','A64','WoWC',0x6D3C242B3C76686FEEE9B18444C113C7),
(58911,'Mac','x64','WoW',0x78D3576614AED3DE8FB8C90AFF838F3B),
(58911,'Mac','x64','WoWC',0xA4C80CDBC805A19FAB8EF1BAA483DB9A),
(58911,'Win','A64','WoW',0xF02130BA7BFF2C0292F25F3C6240B2E8),
(58911,'Win','x64','WoW',0x5EF341D9F5A27F796D5BD786A5BD5A16),
(58911,'Win','x64','WoWC',0xA9C0BEA1B7351665091E6754A0A90A16);

UPDATE `realmlist` SET `gamebuild`=58911 WHERE `gamebuild`=58867;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '58911';
