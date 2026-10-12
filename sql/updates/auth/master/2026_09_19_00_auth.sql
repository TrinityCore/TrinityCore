DELETE FROM `build_info` WHERE `build` IN (69875);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(69875,12,1,0,NULL);

DELETE FROM `build_auth_key` WHERE `build`=69875 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=69875 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=69875 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=69875 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=69875 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=69875 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=69875 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(69875,'Mac','A64','WoW',0xD88093682EC77460858BB7B29E69F968),
(69875,'Mac','A64','WoWC',0x3171A821092246CE74F7F06144C3CBB3),
(69875,'Mac','x64','WoW',0x3DBF6AF950B2D6A367BC2D7940F7433F),
(69875,'Mac','x64','WoWC',0x3B2E6D42A6E5CADE919093EF78960D35),
(69875,'Win','A64','WoW',0x4CFEB2811C1940D0346014B367BD0325),
(69875,'Win','x64','WoW',0xE0AA3015AD5C595869F13B6B8BECC231),
(69875,'Win','x64','WoWC',0xE8C0198E6721AAF2B1C748AC4284A574);

UPDATE `realmlist` SET `gamebuild`=69875 WHERE `gamebuild`=69814;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '69875';
