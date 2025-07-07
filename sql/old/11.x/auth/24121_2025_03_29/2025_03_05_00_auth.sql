DELETE FROM `build_info` WHERE `build` IN (59538);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(59538,11,1,0,NULL);

DELETE FROM `build_auth_key` WHERE `build`=59538 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=59538 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=59538 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=59538 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=59538 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=59538 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=59538 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(59538,'Mac','A64','WoW',0x1DDC6F14195D1F85B7026AEDCCFE2875),
(59538,'Mac','A64','WoWC',0xE34E2419F557FA85EE5D026CB1BC6246),
(59538,'Mac','x64','WoW',0xCBC396C3E20090798DF9CF8B67DCDBEE),
(59538,'Mac','x64','WoWC',0x73DDA3618C8D13A0DAA79C2007B894DD),
(59538,'Win','A64','WoW',0x498203B085106FA1A039A8B5E55DD31C),
(59538,'Win','x64','WoW',0x72B905CC388F523E1A30FBF23DA0C9AB),
(59538,'Win','x64','WoWC',0xA198A8FF303007EAC43B74AA90489BBC);

UPDATE `realmlist` SET `gamebuild`=59538 WHERE `gamebuild`=59466;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '59538';
