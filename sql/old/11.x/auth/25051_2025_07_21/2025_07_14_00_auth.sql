DELETE FROM `build_info` WHERE `build` IN (61967);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(61967,11,1,7,NULL);

DELETE FROM `build_auth_key` WHERE `build`=61967 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=61967 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=61967 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=61967 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=61967 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=61967 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=61967 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(61967,'Mac','A64','WoW',0xDAB6F778C37531255AC22F3FB9065EAA),
(61967,'Mac','A64','WoWC',0x3F10FF17698D9F938B04707C0B8A7E00),
(61967,'Mac','x64','WoW',0x2B9DB4F2B70E849871A8F95FEEF357E9),
(61967,'Mac','x64','WoWC',0x4DE3D440D1D46A38EC32D0D524004ABA),
(61967,'Win','A64','WoW',0x7B443BB6B4F355B9E389F4F0ACB04FE8),
(61967,'Win','x64','WoW',0x6E194B4B53038E76E01E9538107AFF4D),
(61967,'Win','x64','WoWC',0x9E135BF0B40BDD210EAF318AEB72801C);

UPDATE `realmlist` SET `gamebuild`=61967 WHERE `gamebuild`=61609;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '61967';
