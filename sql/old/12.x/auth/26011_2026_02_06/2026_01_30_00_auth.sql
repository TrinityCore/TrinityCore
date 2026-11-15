DELETE FROM `build_info` WHERE `build` IN (65655);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(65655,12,0,0,NULL);

DELETE FROM `build_auth_key` WHERE `build`=65655 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=65655 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=65655 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=65655 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=65655 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=65655 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=65655 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(65655,'Mac','A64','WoW',0x5FC92211657DC1246AADF3BD3014C0C9),
(65655,'Mac','A64','WoWC',0xA9ACEE99FDDF226CFC172C3340DB0465),
(65655,'Mac','x64','WoW',0xC9EB424F23C63A43C1A376216919BDB7),
(65655,'Mac','x64','WoWC',0x68082F937F8D7D6054C76F7F763F1E73),
(65655,'Win','A64','WoW',0x72D550C377B457C06D6D80AC1A10FE6C),
(65655,'Win','x64','WoW',0x6AD49B69F4FAD3568234489DD1908960),
(65655,'Win','x64','WoWC',0xB83E762977DA190419A418FD4EB9539C);

UPDATE `realmlist` SET `gamebuild`=65655 WHERE `gamebuild`=65560;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '65655';
