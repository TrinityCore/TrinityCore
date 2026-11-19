DELETE FROM `build_info` WHERE `build` IN (56647);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(56647,11,0,2,NULL);

DELETE FROM `build_auth_key` WHERE `build`=56647 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=56647 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=56647 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=56647 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=56647 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=56647 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(56647,'Mac','A64','WoW',0x1911B50FA20E5DEF8C1E5D3C7479E4E2),
(56647,'Mac','A64','WoWC',0xF0F2BEC3DE590AE7A59CCFDB42201D5F),
(56647,'Mac','x64','WoW',0x022A06825C7CF55528A5ED03E87D6AE4),
(56647,'Win','A64','WoW',0x0F36C48D68E358598318F0B30FDFCB61),
(56647,'Win','x64','WoW',0x2E9C456B66C0D5CAD601E8FD7A2FEA7A),
(56647,'Win','x64','WoWC',0x543A69AB802D0873D84AB08DEC4D8CAC);

UPDATE `realmlist` SET `gamebuild`=56647 WHERE `gamebuild`=56625;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '56647';
