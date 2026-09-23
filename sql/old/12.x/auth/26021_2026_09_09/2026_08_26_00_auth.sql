DELETE FROM `build_info` WHERE `build` IN (69497);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(69497,12,1,0,NULL);

DELETE FROM `build_auth_key` WHERE `build`=69497 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=69497 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=69497 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=69497 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=69497 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=69497 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=69497 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(69497,'Mac','A64','WoW',0xAD2DD5E363F9182F99C06433B498D20F),
(69497,'Mac','A64','WoWC',0xB87E8FBB4BF74FD0E1A2BB2A025D9F90),
(69497,'Mac','x64','WoW',0xCA0A9C2A2421B283D181D0FE752D8919),
(69497,'Mac','x64','WoWC',0x2AC0E1C0504B076A0CAAF1214397480F),
(69497,'Win','A64','WoW',0xB40CE00FAA74C3FAAD87BD45FD5FBFB4),
(69497,'Win','x64','WoW',0x53F580479D745CBB9B8AE90A2DB752CC),
(69497,'Win','x64','WoWC',0x46436999D97A13A220693F04DE28E013);

UPDATE `realmlist` SET `gamebuild`=69497 WHERE `gamebuild`=69465;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '69497';
