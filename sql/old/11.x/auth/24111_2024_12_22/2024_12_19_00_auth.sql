DELETE FROM `build_info` WHERE `build` IN (58187);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(58187,11,0,7,NULL);

DELETE FROM `build_auth_key` WHERE `build`=58187 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=58187 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=58187 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=58187 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=58187 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=58187 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=58187 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(58187,'Mac','A64','WoW',0x88D993926D777DC12059988E009A73D6),
(58187,'Mac','A64','WoWC',0x9E794FD5CD76EFF400837338876BA64F),
(58187,'Mac','x64','WoW',0xDE1377202943C1155607090CF884FF66),
(58187,'Mac','x64','WoWC',0xE7777DCE18DB45B7ED3E7ADF23BCB1CB),
(58187,'Win','A64','WoW',0xFFEAC8B1B547FD10EFCA8BCF30DF9F51),
(58187,'Win','x64','WoW',0xD92C35D6904B0945992B0801E53822E7),
(58187,'Win','x64','WoWC',0x8AC21CC640359F276C2F6153FAA28638);

UPDATE `realmlist` SET `gamebuild`=58187 WHERE `gamebuild`=58162;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '58187';
