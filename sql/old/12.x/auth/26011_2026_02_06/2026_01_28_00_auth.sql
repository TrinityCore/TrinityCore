DELETE FROM `build_info` WHERE `build` IN (65560);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(65560,12,0,0,NULL);

DELETE FROM `build_auth_key` WHERE `build`=65560 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=65560 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=65560 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=65560 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=65560 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=65560 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=65560 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(65560,'Mac','A64','WoW',0x764AEDCD3D0598B4B0E4800952F35B21),
(65560,'Mac','A64','WoWC',0x6C5142AD00EF0409698E7F15CEC59432),
(65560,'Mac','x64','WoW',0x8277339BE0CE9EF84EF69A88A9986D50),
(65560,'Mac','x64','WoWC',0x066F8A98D49D6795583A2152C36A7B9B),
(65560,'Win','A64','WoW',0xD46670909EAA1861344E421111A4D8AE),
(65560,'Win','x64','WoW',0xAA9B762F17CBDDF63B367E8A4047E301),
(65560,'Win','x64','WoWC',0x438E7EE1E17B986E55B828609FD1773D);

UPDATE `realmlist` SET `gamebuild`=65560 WHERE `gamebuild`=65299;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '65560';
