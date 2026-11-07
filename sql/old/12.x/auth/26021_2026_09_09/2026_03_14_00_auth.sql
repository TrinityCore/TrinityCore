DELETE FROM `build_info` WHERE `build` IN (66384);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(66384,12,0,1,NULL);

DELETE FROM `build_auth_key` WHERE `build`=66384 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=66384 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=66384 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=66384 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=66384 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=66384 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=66384 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(66384,'Mac','A64','WoW',0x87D16F8EC6A4CBA38485316A72C5A478),
(66384,'Mac','A64','WoWC',0xBF3BCB512E4CA1917DE50EBEC1D94043),
(66384,'Mac','x64','WoW',0xF8050A3316BB26DE89759FA88C6B5BEB),
(66384,'Mac','x64','WoWC',0x2609FE52C7AE7B34BBB12D20A9996EBD),
(66384,'Win','A64','WoW',0x17EC84E86461C73BE691F77602F726E1),
(66384,'Win','x64','WoW',0x08D2D00AEF8C36B6701EC255E092E22F),
(66384,'Win','x64','WoWC',0xAAF50C5D9E54868645DC62BABCD17F2C);

UPDATE `realmlist` SET `gamebuild`=66384 WHERE `gamebuild`=66337;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '66384';
