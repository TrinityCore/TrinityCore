DELETE FROM `build_info` WHERE `build` IN (69465);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(69465,12,1,0,NULL);

DELETE FROM `build_auth_key` WHERE `build`=69465 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=69465 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=69465 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=69465 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=69465 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=69465 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=69465 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(69465,'Mac','A64','WoW',0xD93824734F44799FF0FE0E1CE8368DFA),
(69465,'Mac','A64','WoWC',0x2337F8DF514048173B5B1C11E1EF180B),
(69465,'Mac','x64','WoW',0xCEA58B2695F70335D7B3C107DEF5A487),
(69465,'Mac','x64','WoWC',0xE30DFA7F99958105AE363A525E502F88),
(69465,'Win','A64','WoW',0xEDBF0C17BD0C054758919085999845D2),
(69465,'Win','x64','WoW',0x9CAB38EF27A662F070FA9E0B39A3BF7E),
(69465,'Win','x64','WoWC',0x2FD2193ABEB81E97819F5AF336735FEF);

UPDATE `realmlist` SET `gamebuild`=69465 WHERE `gamebuild`=69404;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '69465';
