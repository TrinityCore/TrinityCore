DELETE FROM `build_info` WHERE `build` IN (58773);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(58773,11,0,7,NULL);

DELETE FROM `build_auth_key` WHERE `build`=58773 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=58773 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=58773 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=58773 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=58773 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=58773 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=58773 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(58773,'Mac','A64','WoW',0x52D40564B2DF8D1DC02AC698F3FCF9C1),
(58773,'Mac','A64','WoWC',0xF0EBD5EF23A71883AF137174E4B1B01A),
(58773,'Mac','x64','WoW',0xAC2A56DCB12639F43F15F43BA9A9F996),
(58773,'Mac','x64','WoWC',0x8431C2D85A026E13E3E114C7AE83F0DE),
(58773,'Win','A64','WoW',0x9ADF3B9E70DF0176CEC196480BA407A3),
(58773,'Win','x64','WoW',0x648474DEE9F16AF1C02BD63F7F3E9B01),
(58773,'Win','x64','WoWC',0x362C80C4498FFA1DE3CC0AF243E1337A);

UPDATE `realmlist` SET `gamebuild`=58773 WHERE `gamebuild`=58680;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '58773';
