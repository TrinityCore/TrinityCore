DELETE FROM `build_info` WHERE `build` IN (56461);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(56461,11,0,2,NULL);

DELETE FROM `build_auth_key` WHERE `build`=56461 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=56461 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=56461 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=56461 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=56461 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=56461 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=56461 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(56461,'Mac','A64','WoW',0xE51FE6EAE45322991916F619481DB0B1),
(56461,'Mac','A64','WoWC',0x85447CD695C2DC2F618B23996B4A503C),
(56461,'Mac','x64','WoW',0xE26878DF3437782F6E93E833B4CD843A),
(56461,'Mac','x64','WoWC',0x8B60B0DDD55907673FD1C11EDAE58859),
(56461,'Win','A64','WoW',0x2F862AB724092B99C8A1F6A7B53F6A9D),
(56461,'Win','x64','WoW',0x153CD89E30C4D5C3DBE603EECB470FB4),
(56461,'Win','x64','WoWC',0x79BD4C88012F0DA42605D76A153722CC);

UPDATE `realmlist` SET `gamebuild`=56461 WHERE `gamebuild`=56421;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '56461';
