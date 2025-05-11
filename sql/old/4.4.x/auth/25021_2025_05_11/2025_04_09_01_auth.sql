DELETE FROM `build_info` WHERE `build` IN (60192);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(60192,4,4,2,NULL);

DELETE FROM `build_auth_key` WHERE `build`=60192 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=60192 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=60192 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=60192 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=60192 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=60192 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=60192 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(60192,'Mac','A64','WoW',0x5909246906AB38CBDAB76B805B32684F),
(60192,'Mac','A64','WoWC',0xCB12A6091F8811F63A63E751D9F91B60),
(60192,'Mac','x64','WoW',0x5AD4530C21977C9CF132353CA248367C),
(60192,'Mac','x64','WoWC',0xBD3205EC191FE1DE0E7A207EF459DE97),
(60192,'Win','A64','WoW',0xA6F329ED8EBC1B43E59997AFD82BD5C1),
(60192,'Win','x64','WoW',0x6987F36EEE27CBF05AF1D7841E77EE73),
(60192,'Win','x64','WoWC',0xDC9D44DF6087F92CFE81F3CF3DAF8615);

UPDATE `realmlist` SET `gamebuild`=60192 WHERE `gamebuild`=60142;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '60192';
