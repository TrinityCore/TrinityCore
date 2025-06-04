DELETE FROM `build_info` WHERE `build` IN (61256);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(61256,3,4,4,NULL);

DELETE FROM `build_auth_key` WHERE `build`=61256 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=61256 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=61256 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=61256 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=61256 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=61256 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=61256 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(61256,'Mac','A64','WoW',0xA3A7B5570E1A0BE5FE4613FD47BF8AB3),
(61256,'Mac','A64','WoWC',0x34EF1B459635E3E41C040DF0D8BB995C),
(61256,'Mac','x64','WoW',0x4226C7D6969CB6E76DFD274992C09FAB),
(61256,'Mac','x64','WoWC',0xDA649A34A62C43ABB963C81EB9BDBAAE),
(61256,'Win','A64','WoW',0x201B7A7C2253B59A077F4CC0751893E8),
(61256,'Win','x64','WoW',0x577BEA31B620444736382DF98EAF39A0),
(61256,'Win','x64','WoWC',0x277C02F00D4FACE8994E8FF45469B94C);

UPDATE `realmlist` SET `gamebuild`=61256 WHERE `gamebuild`=61187;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '61256';
