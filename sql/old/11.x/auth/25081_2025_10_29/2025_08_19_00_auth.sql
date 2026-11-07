DELETE FROM `build_info` WHERE `build` IN (62680);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(62680,11,2,0,NULL);

DELETE FROM `build_auth_key` WHERE `build`=62680 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=62680 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=62680 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=62680 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=62680 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=62680 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=62680 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(62680,'Mac','A64','WoW',0x52D3CFF8AE101B720C4DF1B5288A1E8B),
(62680,'Mac','A64','WoWC',0x7FBBF2377E83B980B2501106B2F88CA9),
(62680,'Mac','x64','WoW',0xE8E4D9C538DAB507F623EBF3F7A503A8),
(62680,'Mac','x64','WoWC',0xACAF4F2E279ECFCD00787BB199F92F2C),
(62680,'Win','A64','WoW',0xFB08879F4B65374123CF59A650885A58),
(62680,'Win','x64','WoW',0x2E4DDEDE233C86BE7967901A85134A89),
(62680,'Win','x64','WoWC',0x539619B1D95663BBB7AB003BB6D0BA5E);

UPDATE `realmlist` SET `gamebuild`=62680 WHERE `gamebuild`=62493;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '62680';
