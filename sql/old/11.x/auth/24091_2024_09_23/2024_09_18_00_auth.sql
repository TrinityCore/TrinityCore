DELETE FROM `build_info` WHERE `build` IN (56625);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(56625,11,0,2,NULL);

DELETE FROM `build_auth_key` WHERE `build`=56625 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=56625 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=56625 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=56625 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=56625 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=56625 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=56625 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(56625,'Mac','A64','WoW',0xC7AD97B9970260D0BDE7AA03EEF87E2D),
(56625,'Mac','A64','WoWC',0xDEBDB4589756730F5EF60B337226E515),
(56625,'Mac','x64','WoW',0xEB5665FDC81E3538944BA82E435A53E6),
(56625,'Mac','x64','WoWC',0xAA5B3910A3D13C89F3D9467058080836),
(56625,'Win','A64','WoW',0x684153873E5023671685B270DA879668),
(56625,'Win','x64','WoW',0x80859C23C3E7F827829D47A08A1B8C92),
(56625,'Win','x64','WoWC',0x606914ED212277FDDBBAE49BE6E8CCAF);

UPDATE `realmlist` SET `gamebuild`=56625 WHERE `gamebuild`=56513;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '56625';
