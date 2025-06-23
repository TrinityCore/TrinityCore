DELETE FROM `build_info` WHERE `build` IN (61581);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(61581,3,4,4,NULL);

DELETE FROM `build_auth_key` WHERE `build`=61581 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=61581 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=61581 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=61581 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=61581 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=61581 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=61581 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(61581,'Mac','A64','WoW',0xFAFB43685A89450E09BFE56A2911E7A6),
(61581,'Mac','A64','WoWC',0xB068F808C672388EBF0AF1D4DEDE0AEF),
(61581,'Mac','x64','WoW',0x166CC5C85F33EC6E317AA89D40E8015F),
(61581,'Mac','x64','WoWC',0x9C0D3563B7F808F7AB17CA9B93E3823F),
(61581,'Win','A64','WoW',0xCE7F5A2B3C61C0278BA4F3304CFFFD6D),
(61581,'Win','x64','WoW',0xEAE46A634ED8C2487475C3DD8B4F95F9),
(61581,'Win','x64','WoWC',0x1AA635E3B83FC844BD106DD147261E23);

UPDATE `realmlist` SET `gamebuild`=61581 WHERE `gamebuild`=61256;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '61581';
