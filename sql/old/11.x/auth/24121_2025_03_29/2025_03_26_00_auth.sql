DELETE FROM `build_info` WHERE `build` IN (59888);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(59888,11,1,0,NULL);

DELETE FROM `build_auth_key` WHERE `build`=59888 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=59888 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=59888 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=59888 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=59888 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=59888 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=59888 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(59888,'Mac','A64','WoW',0xB64283161581FFC8D5FA9D5EF2689C1D),
(59888,'Mac','A64','WoWC',0xB9E0C8C20A63C3B7EA8037A6968C1305),
(59888,'Mac','x64','WoW',0x92D62F3B10B01DF8A6FF042BE8567D19),
(59888,'Mac','x64','WoWC',0xB0F4010BAF63ECC5E798BC49827016E9),
(59888,'Win','A64','WoW',0x7BC71337460CB90B26FEBEC9FC14B553),
(59888,'Win','x64','WoW',0x17B6A2C47452572A8EBF9200C1CA1C92),
(59888,'Win','x64','WoWC',0x709AD6F51891994D41CBA1F49F812123);

UPDATE `realmlist` SET `gamebuild`=59888 WHERE `gamebuild`=59679;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '59888';
