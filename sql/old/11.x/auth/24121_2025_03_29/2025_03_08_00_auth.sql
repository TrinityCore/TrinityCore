DELETE FROM `build_info` WHERE `build` IN (59570);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(59570,11,1,0,NULL);

DELETE FROM `build_auth_key` WHERE `build`=59570 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=59570 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=59570 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=59570 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=59570 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=59570 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=59570 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(59570,'Mac','A64','WoW',0x6318C6C300367C8E114042584DA7F82C),
(59570,'Mac','A64','WoWC',0x6F1554122133FA8F4EE189022CFFD122),
(59570,'Mac','x64','WoW',0x13968B08B91BD4A922C3340A77E30C87),
(59570,'Mac','x64','WoWC',0x29D0C5C6E3F8408D064EA76930EE92E7),
(59570,'Win','A64','WoW',0x1ED3EA5DBEF495E4A01AE989E8F44CD8),
(59570,'Win','x64','WoW',0x7571E0C3459C7F9BFDC64BF5AF035F08),
(59570,'Win','x64','WoWC',0xC5CA2210F4E39657EE415FCAA53D4B23);

UPDATE `realmlist` SET `gamebuild`=59570 WHERE `gamebuild`=59538;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '59570';
