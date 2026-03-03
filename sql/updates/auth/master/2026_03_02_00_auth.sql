DELETE FROM `build_info` WHERE `build` IN (66198);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(66198,12,0,1,NULL);

DELETE FROM `build_auth_key` WHERE `build`=66198 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=66198 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=66198 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=66198 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=66198 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=66198 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=66198 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(66198,'Mac','A64','WoW',0x43E860DFC8EB2AF312573058DD4F9F78),
(66198,'Mac','A64','WoWC',0xFB8BA2A0AD8A892E73E1F6AD8754F735),
(66198,'Mac','x64','WoW',0x4780A4C0158F7EFB7FF538FB21192C9C),
(66198,'Mac','x64','WoWC',0xAEF62044240B9657D54EE2ED7B22A2CD),
(66198,'Win','A64','WoW',0x684FAED34FA60E23854BD1673204E317),
(66198,'Win','x64','WoW',0x64C1CBF59BC8EE9B6681FCD5A5A14F7B),
(66198,'Win','x64','WoWC',0x60B099C9F1CE2A2E48A99920090B3BB5);

UPDATE `realmlist` SET `gamebuild`=66198 WHERE `gamebuild`=66192;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '66198';
