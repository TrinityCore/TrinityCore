DELETE FROM `build_info` WHERE `build` IN (65940);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(65940,12,0,1,NULL);

DELETE FROM `build_auth_key` WHERE `build`=65940 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=65940 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=65940 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=65940 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=65940 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=65940 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=65940 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(65940,'Mac','A64','WoW',0x5A447AB7C835A4B4D5B0024340C53AA0),
(65940,'Mac','A64','WoWC',0x2DD4E31BF410987C10122CFDB24ED70C),
(65940,'Mac','x64','WoW',0x90FD0C84E213FA7654A543D8B5F3E9F2),
(65940,'Mac','x64','WoWC',0xDE5D58F115E5ED88522351D8619A1367),
(65940,'Win','A64','WoW',0xDDC39F5861F0F3DF9269181A1AAF1B74),
(65940,'Win','x64','WoW',0x98B935D949F5D31A99CDB6545871FEB1),
(65940,'Win','x64','WoWC',0xF4EEDF5C1826A90C8B65C6F823839DDE);

UPDATE `realmlist` SET `gamebuild`=65940 WHERE `gamebuild`=65893;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '65940';
