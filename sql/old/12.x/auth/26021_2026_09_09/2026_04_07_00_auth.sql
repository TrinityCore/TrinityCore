DELETE FROM `build_info` WHERE `build` IN (66838);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(66838,12,0,1,NULL);

DELETE FROM `build_auth_key` WHERE `build`=66838 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=66838 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=66838 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=66838 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=66838 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=66838 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=66838 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(66838,'Mac','A64','WoW',0x0DF087CEC90FD63C141640CDA44BED4D),
(66838,'Mac','A64','WoWC',0x5DFC3FC183FE0B1643BEEA2C8DD653D0),
(66838,'Mac','x64','WoW',0x6FBB1E9AE33FF34B1EB26AFD9C8AB9EA),
(66838,'Mac','x64','WoWC',0xF30391E577B93E4F405C12B7410DE4D2),
(66838,'Win','A64','WoW',0x0BF2D8325ACDA262E4067CA94E9A74E2),
(66838,'Win','x64','WoW',0x3311F0FE50F95B1F2FED73D88EBEF674),
(66838,'Win','x64','WoWC',0x16CB76E27B2953AD7155A9DBE924827F);

UPDATE `realmlist` SET `gamebuild`=66838 WHERE `gamebuild`=66709;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '66838';
