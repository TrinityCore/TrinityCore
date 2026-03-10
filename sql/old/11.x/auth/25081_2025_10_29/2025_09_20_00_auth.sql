DELETE FROM `build_info` WHERE `build` IN (63305);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(63305,11,2,0,NULL);

DELETE FROM `build_auth_key` WHERE `build`=63305 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=63305 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=63305 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=63305 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=63305 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=63305 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=63305 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(63305,'Mac','A64','WoW',0x22E7C05A01EA110EFDACFFC2AE4B27DE),
(63305,'Mac','A64','WoWC',0xBEB015F25B21F43EF52AF0FAA572E6E8),
(63305,'Mac','x64','WoW',0xFE6D35D91A23B18C3E05C9CF587CB27F),
(63305,'Mac','x64','WoWC',0x0D600A97C7207828F2DEC0DCA49BC0A8),
(63305,'Win','A64','WoW',0xBA66EFD522EB2CDC8D3FF9184BCD91CA),
(63305,'Win','x64','WoW',0x93C43B6A6902CA37F15C68AAB8E69321),
(63305,'Win','x64','WoWC',0x47BBB811D2AC4DA0D74FEFC0DD32940E);

UPDATE `realmlist` SET `gamebuild`=63305 WHERE `gamebuild`=63163;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '63305';
