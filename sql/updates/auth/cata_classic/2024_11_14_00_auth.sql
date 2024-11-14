DELETE FROM `build_info` WHERE `build` IN (57564);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(57564,4,4,1,NULL);

DELETE FROM `build_auth_key` WHERE `build`=57564 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=57564 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=57564 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=57564 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(57564,'Mac','A64','WoW',0x2A136B5D92F275399D865907EAE4785D),
(57564,'Mac','x64','WoW',0x7274992DA094F6438C37CC7AD1206542),
(57564,'Win','A64','WoW',0xDF63590B1034D8DE12C329B31C35759B),
(57564,'Win','x64','WoW',0x75891D08FD96EBFE8C3952155B69098B);

UPDATE `realmlist` SET `gamebuild`=57564 WHERE `gamebuild`=57359;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '57564';
