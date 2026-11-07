DELETE FROM `build_info` WHERE `build` IN (64978);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(64978,11,2,7,NULL);

DELETE FROM `build_auth_key` WHERE `build`=64978 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=64978 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=64978 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=64978 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=64978 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=64978 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=64978 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(64978,'Mac','A64','WoW',0x2D3D9A591D1750ACBFA38450225218E0),
(64978,'Mac','A64','WoWC',0x0FA46AA62D9E1DEC723F01B16CE26442),
(64978,'Mac','x64','WoW',0x8C4D1BA36574C6E68716DB455C3B73FD),
(64978,'Mac','x64','WoWC',0xD1EE6F8E00507CC771F4AAD86B91F7AA),
(64978,'Win','A64','WoW',0x04FB74A28B1A31D7A2A3126DD2B71AB7),
(64978,'Win','x64','WoW',0x706BA57AEDD9816B5A58209FA6A3B728),
(64978,'Win','x64','WoWC',0x96B417D4D1F12CF8B0C855A23C674C2C);

UPDATE `realmlist` SET `gamebuild`=64978 WHERE `gamebuild`=64877;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '64978';
