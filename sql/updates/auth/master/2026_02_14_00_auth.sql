DELETE FROM `build_info` WHERE `build` IN (65893);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(65893,12,0,1,NULL);

DELETE FROM `build_auth_key` WHERE `build`=65893 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=65893 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=65893 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=65893 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=65893 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=65893 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=65893 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(65893,'Mac','A64','WoW',0xF3567C27E5659D41FC511230B827ECD7),
(65893,'Mac','A64','WoWC',0xB90316206791ABA6D47F6D6C39274F92),
(65893,'Mac','x64','WoW',0x8B885914B0D6E3855266B230E67FAE5D),
(65893,'Mac','x64','WoWC',0xAF95C1D91DE7E6F39547591EC1CD2F84),
(65893,'Win','A64','WoW',0x324A883ACF36AAEB66661E671E43F347),
(65893,'Win','x64','WoW',0x5553755B209786102B0BAE410C95DB89),
(65893,'Win','x64','WoWC',0xB2AF8F8DE1722F6CC2F0FB597B32523C);

UPDATE `realmlist` SET `gamebuild`=65893 WHERE `gamebuild`=65867;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '65893';
