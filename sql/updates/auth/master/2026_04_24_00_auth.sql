DELETE FROM `build_info` WHERE `build` IN (67186);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(67186,12,0,5,NULL);

DELETE FROM `build_auth_key` WHERE `build`=67186 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=67186 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=67186 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=67186 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=67186 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=67186 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=67186 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(67186,'Mac','A64','WoW',0x0A0433C230A5895C449D8ABE99CF052A),
(67186,'Mac','A64','WoWC',0x47996D60D76FF43568834B90CC3F548E),
(67186,'Mac','x64','WoW',0x1DF32222DD9B14301166008F3DC97873),
(67186,'Mac','x64','WoWC',0x0A718FA5FFE7C1BDE3CE590D178F3EF2),
(67186,'Win','A64','WoW',0xA77179F88A613F96E96F9C5D01278390),
(67186,'Win','x64','WoW',0xBB01E8BE61269F022557F8E3D51A93D7),
(67186,'Win','x64','WoWC',0x564D029956263E4861450F664717ED7C);

UPDATE `realmlist` SET `gamebuild`=67186 WHERE `gamebuild`=67114;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '67186';
