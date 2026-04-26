DELETE FROM `build_info` WHERE `build` IN (67088);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(67088,12,0,5,NULL);

DELETE FROM `build_auth_key` WHERE `build`=67088 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=67088 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=67088 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=67088 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=67088 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=67088 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=67088 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(67088,'Mac','A64','WoW',0x33CE8730AD20F33963F7E76597385EFA),
(67088,'Mac','A64','WoWC',0x85FA523866710862D4F3B37112B5AE70),
(67088,'Mac','x64','WoW',0xB7A01B3F50CA147FED6A4C61992B9432),
(67088,'Mac','x64','WoWC',0xE52362D75762001B2961C76AE3967E8F),
(67088,'Win','A64','WoW',0x015B0FF86D65C231A5CD1E387EB2A524),
(67088,'Win','x64','WoW',0xD2B5473E8CF4825839F1688BBA3ED5B0),
(67088,'Win','x64','WoWC',0xD746049A30EB089597C443743D74847B);

UPDATE `realmlist` SET `gamebuild`=67088 WHERE `gamebuild`=66838;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '67088';
