DELETE FROM `build_info` WHERE `build` IN (70448);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(70448,12,1,5,NULL);

DELETE FROM `build_auth_key` WHERE `build`=70448 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=70448 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=70448 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=70448 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=70448 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=70448 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=70448 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(70448,'Mac','A64','WoW',0x20D53526BAAEED648A696123DC244528),
(70448,'Mac','A64','WoWC',0x8BA73B25C5B606AD5CB1944E1279528A),
(70448,'Mac','x64','WoW',0x5A3C37F24A07D4AF104CF93F93EDA637),
(70448,'Mac','x64','WoWC',0xCC1A5A7271901F83C28CB7305B5A9CE9),
(70448,'Win','A64','WoW',0x79FB0F9849E81055870938498E7F345B),
(70448,'Win','x64','WoW',0x68E1A09ED8B0E55FB7F17D8EA109EE1B),
(70448,'Win','x64','WoWC',0x4CB59A069AE9A645A46921048F8AE031);

UPDATE `realmlist` SET `gamebuild`=70448 WHERE `gamebuild`=70391;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '70448';
