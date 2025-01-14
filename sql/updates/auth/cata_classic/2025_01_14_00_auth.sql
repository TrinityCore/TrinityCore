DELETE FROM `build_info` WHERE `build` IN (58558);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(58558,4,4,1,NULL);

DELETE FROM `build_auth_key` WHERE `build`=58558 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=58558 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=58558 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=58558 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(58558,'Mac','A64','WoW',0x7FD54AE255B9757285A661630FA707B8),
(58558,'Mac','x64','WoW',0x2D8D31D0DD1BF85E89292619CCF4317F),
(58558,'Win','A64','WoW',0x498916D48F0C962F162FF425A443FA52),
(58558,'Win','x64','WoW',0x80FEC2B5AC7846BAFB99FCF9C963DEF1);

UPDATE `realmlist` SET `gamebuild`=58558 WHERE `gamebuild`=58158;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '58558';
