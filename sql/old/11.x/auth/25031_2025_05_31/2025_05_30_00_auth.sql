DELETE FROM `build_info` WHERE `build` IN (61122);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(61122,11,1,5,NULL);

DELETE FROM `build_auth_key` WHERE `build`=61122 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=61122 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=61122 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=61122 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=61122 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=61122 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(61122,'Mac','A64','WoW',0xD898830AEFC000E41A8DEEAA7DD04B51),
(61122,'Mac','A64','WoWC',0x58AF686E1A37B550D31375028105D6CB),
(61122,'Mac','x64','WoW',0x56AEFFFCFEB892A2A8C4788AF03AD7BC),
(61122,'Win','A64','WoW',0x9AC43579FE8BE4E76A20251A2F563C61),
(61122,'Win','x64','WoW',0x5DE6B3E0046D8F38E0566DD620469916),
(61122,'Win','x64','WoWC',0x8E849FE11AA7F2181E16585A4691F451);

UPDATE `realmlist` SET `gamebuild`=61122 WHERE `gamebuild`=60822;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '61122';
