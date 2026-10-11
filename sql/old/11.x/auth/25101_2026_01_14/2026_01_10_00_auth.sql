DELETE FROM `build_info` WHERE `build` IN (65299);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(65299,11,2,7,NULL);

DELETE FROM `build_auth_key` WHERE `build`=65299 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=65299 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=65299 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=65299 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=65299 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=65299 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=65299 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(65299,'Mac','A64','WoW',0x13D67C8B31E6E0438DDD546E6B6089C3),
(65299,'Mac','A64','WoWC',0x17925BF5662AEC818451F0772B811591),
(65299,'Mac','x64','WoW',0x5C513A31174CD2E91CE5926BB263C459),
(65299,'Mac','x64','WoWC',0xAB4CD08C656FFE091ADFD470BCE0D5F9),
(65299,'Win','A64','WoW',0xD0802EFF536A2E14117DBFE0A555EA47),
(65299,'Win','x64','WoW',0x11922598FBB8B92F694511DDAE4B065E),
(65299,'Win','x64','WoWC',0xB608B58A94A4BB567281137B2ED80465);

UPDATE `realmlist` SET `gamebuild`=65299 WHERE `gamebuild`=64978;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '65299';
