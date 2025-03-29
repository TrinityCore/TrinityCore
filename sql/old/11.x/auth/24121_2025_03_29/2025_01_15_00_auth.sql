DELETE FROM `build_info` WHERE `build` IN (58608);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(58608,11,0,7,NULL);

DELETE FROM `build_auth_key` WHERE `build`=58608 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=58608 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=58608 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=58608 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=58608 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=58608 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=58608 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(58608,'Mac','A64','WoW',0x3A3B639B7FC344EDB4314860638110F1),
(58608,'Mac','A64','WoWC',0x8F46148144EDF86BD45D23B0F23CE38B),
(58608,'Mac','x64','WoW',0x29EC11F81992F19AD9707B272419ADDA),
(58608,'Mac','x64','WoWC',0x2BF5613D82AD3A242B5DD0B140CE4416),
(58608,'Win','A64','WoW',0x6FD8AD7CCB3B7DAD45115CA93D3A68F3),
(58608,'Win','x64','WoW',0x21B3EDEB1A65388DD5988056D2BE72B2),
(58608,'Win','x64','WoWC',0xAC65E4DC868EFE4362E72BBCDD746853);

UPDATE `realmlist` SET `gamebuild`=58608 WHERE `gamebuild`=58533;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '58608';
