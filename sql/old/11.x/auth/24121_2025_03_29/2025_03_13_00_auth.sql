DELETE FROM `build_info` WHERE `build` IN (59679);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(59679,11,1,0,NULL);

DELETE FROM `build_auth_key` WHERE `build`=59679 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=59679 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=59679 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=59679 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=59679 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=59679 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=59679 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(59679,'Mac','A64','WoW',0x721E18C6BB25D4878A91801985A0D18F),
(59679,'Mac','A64','WoWC',0x45CB8600B7404B46B032183CCE4B340A),
(59679,'Mac','x64','WoW',0x2E3CD97FD83976BB7D56D3489CE40D79),
(59679,'Mac','x64','WoWC',0x4D28DE9F333624311D3150F871C472EF),
(59679,'Win','A64','WoW',0xE4435EE6E4968B5106E6596B60EE2DB6),
(59679,'Win','x64','WoW',0x54E4C53C5DC1930794DE4D1DD0365FE2),
(59679,'Win','x64','WoWC',0xB23BFD99EBCD872EA39230E1AABCD19B);

UPDATE `realmlist` SET `gamebuild`=59679 WHERE `gamebuild`=59570;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '59679';
