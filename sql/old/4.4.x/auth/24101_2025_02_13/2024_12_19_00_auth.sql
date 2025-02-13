DELETE FROM `build_info` WHERE `build` IN (58158);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(58158,4,4,1,NULL);

DELETE FROM `build_auth_key` WHERE `build`=58158 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=58158 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=58158 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=58158 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(58158,'Mac','A64','WoW',0x10EBC722A3FDD740E42B45C7FDD20EF0),
(58158,'Mac','x64','WoW',0xD7450A6103A5DEB74D818F0C2F4C9085),
(58158,'Win','A64','WoW',0x31ACD1E756B86D16D8EB5E7A47BB2DBF),
(58158,'Win','x64','WoW',0x071CE2ACCDCC49D66F160B4218F01915);

UPDATE `realmlist` SET `gamebuild`=58158 WHERE `gamebuild`=57916;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '58158';
