DELETE FROM `build_info` WHERE `build` IN (70688);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(70688,12,1,5,NULL);

DELETE FROM `build_auth_key` WHERE `build`=70688 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=70688 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=70688 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=70688 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=70688 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=70688 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=70688 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(70688,'Mac','A64','WoW',0xCAD6DE23F550CED3E87F12588921A2F4),
(70688,'Mac','A64','WoWC',0x1F5B1A9C3650087D07C421AD7435F8B0),
(70688,'Mac','x64','WoW',0x76DC2F024B5D5B9010DE983D1095C0D3),
(70688,'Mac','x64','WoWC',0x707C18827DCD195511CDD282F4E88D24),
(70688,'Win','A64','WoW',0xF3A5A8F64BAC4461EAD40C6ED4CD1911),
(70688,'Win','x64','WoW',0xDE9DFE0BA8C872E4A41440A96C67DD64),
(70688,'Win','x64','WoWC',0xEA9A3D165C3A70E852EC193CDF833939);

UPDATE `realmlist` SET `gamebuild`=70688 WHERE `gamebuild`=70575;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '70688';
