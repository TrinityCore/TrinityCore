DELETE FROM `build_info` WHERE `build` IN (67823);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(67823,12,0,5,NULL);

DELETE FROM `build_auth_key` WHERE `build`=67823 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=67823 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=67823 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=67823 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=67823 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=67823 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=67823 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(67823,'Mac','A64','WoW',0x9760C20B4933D21074E5C097CF9815DE),
(67823,'Mac','A64','WoWC',0x16198BAE2F3D221C5F4348A5F567F140),
(67823,'Mac','x64','WoW',0xE279BC6789301855C635717EA5AC0010),
(67823,'Mac','x64','WoWC',0x6A8C7E821379C0914428D82EF5A77C02),
(67823,'Win','A64','WoW',0x0D63AD190AB158988AE0857CD425A1FD),
(67823,'Win','x64','WoW',0x5CE1ED7C31C2477936185ABA32253B0A),
(67823,'Win','x64','WoWC',0x026B786F3129477E285D3C150C6D35F4);

UPDATE `realmlist` SET `gamebuild`=67823 WHERE `gamebuild`=67602;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '67823';
