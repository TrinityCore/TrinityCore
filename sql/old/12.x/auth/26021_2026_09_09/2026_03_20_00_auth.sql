DELETE FROM `build_info` WHERE `build` IN (66527);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(66527,12,0,1,NULL);

DELETE FROM `build_auth_key` WHERE `build`=66527 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=66527 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=66527 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=66527 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=66527 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=66527 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=66527 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(66527,'Mac','A64','WoW',0xF927750F046450185D353A921E06244D),
(66527,'Mac','A64','WoWC',0x475C0906F09121CB86D2B225BE7F3E6B),
(66527,'Mac','x64','WoW',0x22AA9B05F64B2117E941E923A5E2452B),
(66527,'Mac','x64','WoWC',0xF40A1B10E7367BE4B742A9E25CA93DB9),
(66527,'Win','A64','WoW',0xE928E091C823F9127583959F3E688D2E),
(66527,'Win','x64','WoW',0xCBAE2BD108168495CCE1AF55F6D050B0),
(66527,'Win','x64','WoWC',0x949DD36DBB35F4FD024D8F97A5378B19);

UPDATE `realmlist` SET `gamebuild`=66527 WHERE `gamebuild`=66431;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '66527';
