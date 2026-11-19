DELETE FROM `build_info` WHERE `build` IN (70391);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(70391,12,1,5,NULL);

DELETE FROM `build_auth_key` WHERE `build`=70391 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=70391 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=70391 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=70391 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=70391 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=70391 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=70391 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(70391,'Mac','A64','WoW',0x531690D6316455DD005DE3247CE1DF81),
(70391,'Mac','A64','WoWC',0x09392F5D460BC09A3D9587E2AC3EDA32),
(70391,'Mac','x64','WoW',0x447BB8C2902C8738E2D0EC161F21602E),
(70391,'Mac','x64','WoWC',0x44632C8ADCDEF4B107319468FFAAED2B),
(70391,'Win','A64','WoW',0xE1406450BB7F5A7B24F8381823453793),
(70391,'Win','x64','WoW',0x19FBE9EDFA1430115BD53529A050EBD4),
(70391,'Win','x64','WoWC',0x66D7799668243085E794E04A90CDA5CC);

UPDATE `realmlist` SET `gamebuild`=70391 WHERE `gamebuild`=69933;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '70391';
