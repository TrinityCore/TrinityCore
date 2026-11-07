DELETE FROM `build_info` WHERE `build` IN (62876);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(62876,11,2,0,NULL);

DELETE FROM `build_auth_key` WHERE `build`=62876 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=62876 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=62876 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=62876 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=62876 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=62876 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=62876 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(62876,'Mac','A64','WoW',0x93D9177AE7FCF5D5353CC368882BA6AB),
(62876,'Mac','A64','WoWC',0x7EAEA45F071D0DF95878AA4B6C1E0A3B),
(62876,'Mac','x64','WoW',0xC981B22C49FE45D1E89F8F85E3F1474E),
(62876,'Mac','x64','WoWC',0x3405E814B5F2738F5358E7BA95D20783),
(62876,'Win','A64','WoW',0xA0BE8304E27CB1DDE6CAE9DEADEDD2CE),
(62876,'Win','x64','WoW',0x477ADDD4838B7C1017F48EE3C82437BA),
(62876,'Win','x64','WoWC',0xCD36DAABF5EFF54B47BC25F40B408A54);

UPDATE `realmlist` SET `gamebuild`=62876 WHERE `gamebuild`=62801;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '62876';
