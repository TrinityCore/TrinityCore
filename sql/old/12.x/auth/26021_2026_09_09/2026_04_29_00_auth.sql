DELETE FROM `build_info` WHERE `build` IN (67235);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(67235,12,0,5,NULL);

DELETE FROM `build_auth_key` WHERE `build`=67235 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=67235 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=67235 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=67235 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=67235 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=67235 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=67235 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(67235,'Mac','A64','WoW',0xEC0F6ED11D2C44DCC9F1A232A5A851DE),
(67235,'Mac','A64','WoWC',0x0451CEB0D4744ECE9E8178BB2631590C),
(67235,'Mac','x64','WoW',0x562C1648F20378EE01F7B1B55EA708C8),
(67235,'Mac','x64','WoWC',0x97A87270D118A5D6FD3FC976176FA74D),
(67235,'Win','A64','WoW',0xE810FC55C5B08E825A6230BDCB4E6117),
(67235,'Win','x64','WoW',0x1F42DA2BE67CA1FB2970945D89AF137E),
(67235,'Win','x64','WoWC',0x71B8F38D7E5BF20D428D8B8BF4DDCBD7);

UPDATE `realmlist` SET `gamebuild`=67235 WHERE `gamebuild`=67186;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '67235';
