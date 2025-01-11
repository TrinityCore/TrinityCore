DELETE FROM `build_info` WHERE `build` IN (58533);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(58533,11,0,7,NULL);

DELETE FROM `build_auth_key` WHERE `build`=58533 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=58533 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=58533 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=58533 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=58533 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=58533 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=58533 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(58533,'Mac','A64','WoW',0xE637AA32D5DE914B119AF68CC9C9BAAB),
(58533,'Mac','A64','WoWC',0xE693DD275CEEE2D682EC973D79251977),
(58533,'Mac','x64','WoW',0xDE3723EF7EB991A1B27684E6513934D6),
(58533,'Mac','x64','WoWC',0xA93EF4385174001B69F43FF0DF345701),
(58533,'Win','A64','WoW',0x3823D2E16D6E314884CD586949524F2C),
(58533,'Win','x64','WoW',0x18490A077F4FBA0973E0B62A489EE664),
(58533,'Win','x64','WoWC',0x3DC9E22F553D631A5CA067F7809A3D2D);

UPDATE `realmlist` SET `gamebuild`=58533 WHERE `gamebuild`=58238;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '58533';
