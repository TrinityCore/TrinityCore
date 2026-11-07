DELETE FROM `build_info` WHERE `build` IN (57292);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(57292,11,0,5,NULL);

DELETE FROM `build_auth_key` WHERE `build`=57292 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=57292 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=57292 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=57292 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=57292 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=57292 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=57292 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(57292,'Mac','A64','WoW',0xAB48CDD3449440EAA6E72D43914A3824),
(57292,'Mac','A64','WoWC',0x46E6FC16392B1B0B686BDC12C92A6D18),
(57292,'Mac','x64','WoW',0x375B0734567192503CC9F9C8028DC6F3),
(57292,'Mac','x64','WoWC',0xE59F7530C7BFF77CB62E62D4E6D3EEC8),
(57292,'Win','A64','WoW',0xF42B862D0559CCD3204B2DF58E995761),
(57292,'Win','x64','WoW',0xED8353327D5538F75FAF2E0C584D2EF3),
(57292,'Win','x64','WoWC',0x67FC9D56CC96C6F4ACE29151375962F4);

UPDATE `realmlist` SET `gamebuild`=57292 WHERE `gamebuild` IN (56819,57171,57212);

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '57292';
