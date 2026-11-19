DELETE FROM `build_info` WHERE `build` IN (58238);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(58238,11,0,7,NULL);

DELETE FROM `build_auth_key` WHERE `build`=58238 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=58238 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=58238 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=58238 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=58238 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=58238 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=58238 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(58238,'Mac','A64','WoW',0x87705176E4D29CD7DCA47A3DB8B20CE9),
(58238,'Mac','A64','WoWC',0xEC7206B740D162429B4ACCC637132C3D),
(58238,'Mac','x64','WoW',0x1A40852B2F5EEEE2EB80497B691C88AF),
(58238,'Mac','x64','WoWC',0x48E25221E6F84CA49685B91B96E1345A),
(58238,'Win','A64','WoW',0x6AA610F0820BE535EA7017E4C5BD857B),
(58238,'Win','x64','WoW',0x9D91F6D23C62F0CB538D8D4E4BAA4FC1),
(58238,'Win','x64','WoWC',0x7B4A168DADC9A598A40794D6165EA95C);

UPDATE `realmlist` SET `gamebuild`=58238 WHERE `gamebuild`=58187;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '58238';
