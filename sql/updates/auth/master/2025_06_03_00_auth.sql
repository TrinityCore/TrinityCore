DELETE FROM `build_info` WHERE `build` IN (61188);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(61188,11,1,5,NULL);

DELETE FROM `build_auth_key` WHERE `build`=61188 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=61188 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=61188 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=61188 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=61188 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=61188 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=61188 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(61188,'Mac','A64','WoW',0x5FECA4BA5E5CFE4D965E94C39FEE718A),
(61188,'Mac','A64','WoWC',0xA390F2B83D7A7E35AA30FFCFDAE8E18D),
(61188,'Mac','x64','WoW',0x5F9EA790FD85BCE75E869BDBE8799238),
(61188,'Mac','x64','WoWC',0xC7D2C3C134C5744DBD32C563B5BE9C89),
(61188,'Win','A64','WoW',0x999BF7D43893EF11247355389155B0E7),
(61188,'Win','x64','WoW',0xF8A42EB146A4DDD94FD35FF9AD1E75DF),
(61188,'Win','x64','WoWC',0x43983A4D6435939F6EE7EAE955D6C8AA);

UPDATE `realmlist` SET `gamebuild`=61188 WHERE `gamebuild`=61122;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '61188';
