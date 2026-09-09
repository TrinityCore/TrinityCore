DELETE FROM `build_info` WHERE `build` IN (66192);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(66192,12,0,1,NULL);

DELETE FROM `build_auth_key` WHERE `build`=66192 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=66192 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=66192 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=66192 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=66192 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=66192 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=66192 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(66192,'Mac','A64','WoW',0x8A6A4FF9F0AA54E6079F2E0D493B0F88),
(66192,'Mac','A64','WoWC',0x68666612063EBC72FB964E50B6813D24),
(66192,'Mac','x64','WoW',0x359D0C76F1487223D236D3776D9A4691),
(66192,'Mac','x64','WoWC',0xF0E0870A7F9BFBA9AEDD7FB644B5A374),
(66192,'Win','A64','WoW',0x72F1DF83D5DFD2F030054B5B2B8E0F29),
(66192,'Win','x64','WoW',0xEC07B9D9B8C91E1F14192AF984D79CE5),
(66192,'Win','x64','WoWC',0xE8A2B8EDCFCA47DCA085D6EC1EEC3471);

UPDATE `realmlist` SET `gamebuild`=66192 WHERE `gamebuild`=66102;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '66192';
