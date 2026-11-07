DELETE FROM `build_info` WHERE `build` IN (67451);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(67451,12,0,5,NULL);

DELETE FROM `build_auth_key` WHERE `build`=67451 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=67451 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=67451 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=67451 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=67451 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=67451 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=67451 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(67451,'Mac','A64','WoW',0x889201CF5539DADA1FFBFF71E0BBE280),
(67451,'Mac','A64','WoWC',0x4160C109D8DE331C89400BED2F05FC03),
(67451,'Mac','x64','WoW',0x9CA9D05C4B207F774B044494E1D708E1),
(67451,'Mac','x64','WoWC',0x410CDD2A04375CA5D0D88C349C52C55A),
(67451,'Win','A64','WoW',0x5C995E2429DE358EFE6EAB87AE04D875),
(67451,'Win','x64','WoW',0x79881A8B0B6482BD73DB99F9C69456EA),
(67451,'Win','x64','WoWC',0x2B20FCC4EDB252C81601F9C1E05A1C6B);

UPDATE `realmlist` SET `gamebuild`=67451 WHERE `gamebuild`=67403;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '67451';
