DELETE FROM `build_info` WHERE `build` IN (57637,57689);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(57637,11,0,5,NULL),
(57689,11,0,5,NULL);

DELETE FROM `build_auth_key` WHERE `build`=57637 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=57637 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=57637 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=57637 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=57637 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=57637 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=57637 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=57689 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=57689 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=57689 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=57689 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=57689 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=57689 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=57689 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(57637,'Mac','A64','WoW',0x25DB682BB3B56D01B3780C446811956E),
(57637,'Mac','A64','WoWC',0x722FCA435AE1E916A4D96EDF8DDCFB3B),
(57637,'Mac','x64','WoW',0xCBB255E59E1031F8CBEB098D26B8E2FA),
(57637,'Mac','x64','WoWC',0x8DA67ECB7268B7FE759CE94F13165B32),
(57637,'Win','A64','WoW',0x4B39C74A7035B6A1C799F0F4FC6735D2),
(57637,'Win','x64','WoW',0x6C4185E973C9CB8382D3721AF1060C66),
(57637,'Win','x64','WoWC',0x71B57F027872393C902BDCBBDDC43A26),
(57689,'Mac','A64','WoW',0x5D064F1364C285F07FF804DCE98A6CC5),
(57689,'Mac','A64','WoWC',0xAB3DF8B79F5BAE839764988EE6530101),
(57689,'Mac','x64','WoW',0x988459790B4B38301350BE4286F979A2),
(57689,'Mac','x64','WoWC',0xCA7AD91741F8E2063CE227D475247212),
(57689,'Win','A64','WoW',0x4910E2142A21616934CD4D714691748C),
(57689,'Win','x64','WoW',0x93B4E50E651A28D8CC4E7CE7447901F6),
(57689,'Win','x64','WoWC',0x6AEDD8258D4E9701F737CBA852728A74);

UPDATE `realmlist` SET `gamebuild`=57689 WHERE `gamebuild` IN (57534,57637);

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '57689';
