DELETE FROM `build_info` WHERE `build` IN (68453);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(68453,12,0,7,NULL);

DELETE FROM `build_auth_key` WHERE `build`=68453 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=68453 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=68453 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=68453 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=68453 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=68453 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=68453 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(68453,'Mac','A64','WoW',0xF75A30EE8680432BCCB9E82F126CAC2A),
(68453,'Mac','A64','WoWC',0x65D8638C8AEA812D943E19A713C95CE4),
(68453,'Mac','x64','WoW',0xB8825330648658BF39130E439174CE26),
(68453,'Mac','x64','WoWC',0x88477E39E83C2A3E032760163F982A67),
(68453,'Win','A64','WoW',0x2908E5C883715DFD6201B57B0E479067),
(68453,'Win','x64','WoW',0x4BE7186213EDE43354CB69744C7A41E3),
(68453,'Win','x64','WoWC',0x526540167D7E9433D46719CAF0785F10);

UPDATE `realmlist` SET `gamebuild`=68453 WHERE `gamebuild` IN (68275,68367);

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '68453';
