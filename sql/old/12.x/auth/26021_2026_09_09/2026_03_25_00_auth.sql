DELETE FROM `build_info` WHERE `build` IN (66562);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(66562,12,0,1,NULL);

DELETE FROM `build_auth_key` WHERE `build`=66562 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=66562 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=66562 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=66562 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=66562 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=66562 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=66562 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(66562,'Mac','A64','WoW',0x68422269B293771D8EE7EF57EB8FAFD4),
(66562,'Mac','A64','WoWC',0x38259127937E9E149B3BE3EE3357C40D),
(66562,'Mac','x64','WoW',0xD3431C99AFC2D768CC71134590BC5EC6),
(66562,'Mac','x64','WoWC',0x7084CF7EF6BEB8E9AD51B4162DB03801),
(66562,'Win','A64','WoW',0xB41A779F15EEC97EA4843377C6338306),
(66562,'Win','x64','WoW',0xE91BD215E3A61567A75E414272AF79FD),
(66562,'Win','x64','WoWC',0xF785954126005B294FFC373F2767AFC1);

UPDATE `realmlist` SET `gamebuild`=66562 WHERE `gamebuild`=66527;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '66562';
