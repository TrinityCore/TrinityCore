DELETE FROM `build_info` WHERE `build` IN (62801);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(62801,11,2,0,NULL);

DELETE FROM `build_auth_key` WHERE `build`=62801 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=62801 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=62801 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=62801 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=62801 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=62801 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(62801,'Mac','A64','WoW',0x470490902700B0F9A4EAC34B47B71328),
(62801,'Mac','A64','WoWC',0xF2318FBA8B75E3B8A22E4B602341BF62),
(62801,'Mac','x64','WoWC',0x9D82076D2C5C4D2970873585DDC4743D),
(62801,'Win','A64','WoW',0xDFC8340DB35969E4B793EF298A3AE2B7),
(62801,'Win','x64','WoW',0x8C156FABF29ABC1D11599FAFA1E3CB77),
(62801,'Win','x64','WoWC',0x55C4950FE311327C27A7E5101ADAEE42);

UPDATE `realmlist` SET `gamebuild`=62801 WHERE `gamebuild`=62748;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '62801';
