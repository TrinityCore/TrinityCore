DELETE FROM `build_info` WHERE `build` IN (61187);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(61187,3,4,4,NULL);

DELETE FROM `build_auth_key` WHERE `build`=61187 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=61187 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=61187 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=61187 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=61187 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=61187 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=61187 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(61187,'Mac','A64','WoW',0xAFF863C426AA1740CD3748855E55FC86),
(61187,'Mac','A64','WoWC',0xCAA8BD4C5747BED48D679B4C92BBFAF6),
(61187,'Mac','x64','WoW',0xD22C0644CC635A4A136AE55DB5A72BB3),
(61187,'Mac','x64','WoWC',0xBF46F7B7A9C1C7458496088C074CA8CC),
(61187,'Win','A64','WoW',0xD4D048FD8B9BD2EFB494E54AB6A67FB2),
(61187,'Win','x64','WoW',0xD93471EEF270187F46F83CB8E1E2EAB0),
(61187,'Win','x64','WoWC',0x667E36F0B271F4DFC27F6296700870B4);

UPDATE `realmlist` SET `gamebuild`=61187 WHERE `gamebuild`=61075;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '61187';
