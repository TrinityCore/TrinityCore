DELETE FROM `build_info` WHERE `build` IN (59207);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(59207,11,0,7,NULL);

DELETE FROM `build_auth_key` WHERE `build`=59207 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=59207 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=59207 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=59207 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=59207 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=59207 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=59207 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(59207,'Mac','A64','WoW',0x2EC5EAA28DA705573D808A7E911F5D00),
(59207,'Mac','A64','WoWC',0x23A35FDC661E9761FEAC93BF20A926EE),
(59207,'Mac','x64','WoW',0x9E2B97FF7DEA87E951DDE91A65C2595B),
(59207,'Mac','x64','WoWC',0x5FB60ADC82C68D1E50B70956BFBC77BC),
(59207,'Win','A64','WoW',0x41AF3D9F83318D4FC4406BF5C23B20AB),
(59207,'Win','x64','WoW',0x170FB48807771D186547DF96C59E5306),
(59207,'Win','x64','WoWC',0xA9038B171DE62AF741304A4C0F273814);

UPDATE `realmlist` SET `gamebuild`=59207 WHERE `gamebuild`=58911;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '59207';
