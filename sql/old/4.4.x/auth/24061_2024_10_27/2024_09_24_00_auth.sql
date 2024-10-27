DELETE FROM `build_info` WHERE `build` IN (56713);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(56713,4,4,0,NULL);

DELETE FROM `build_auth_key` WHERE `build`=56713 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=56713 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=56713 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=56713 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(56713,'Mac','A64','WoW',0x52EA30F5FC879526462F8FB65B9797AC),
(56713,'Mac','x64','WoW',0x0DFE481E53DF3B21DF98B8598E0CA674),
(56713,'Win','A64','WoW',0x7CD3F3C05BAA6B377202616A1D2C2504),
(56713,'Win','x64','WoW',0x63D7153C3703C7E7FAB7C92F1BA7822C);

UPDATE `realmlist` SET `gamebuild`=56713 WHERE `gamebuild`=56489;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '56713';
