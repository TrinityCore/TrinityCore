DELETE FROM `build_info` WHERE `build` IN (60189);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(60189,11,1,0,NULL);

DELETE FROM `build_auth_key` WHERE `build`=60189 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=60189 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=60189 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=60189 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=60189 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=60189 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=60189 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(60189,'Mac','A64','WoW',0x7C532E0F4D4429430D54BB1DD5D88336),
(60189,'Mac','A64','WoWC',0xCF51D223D48B246FC13A9376A8C933F5),
(60189,'Mac','x64','WoW',0x59B56E50D2A1D3EB28325F57BF637428),
(60189,'Mac','x64','WoWC',0x40CE6676DC47E77D6BED686D31429BE6),
(60189,'Win','A64','WoW',0xE8F789C79EED914C872AEF6D7351EDF8),
(60189,'Win','x64','WoW',0xD9A3ACC3E1222318D951DC0F3FB8AEC4),
(60189,'Win','x64','WoWC',0xA7A07FBE9E0C2D9E9CA3DFBD2670A0AD);

UPDATE `realmlist` SET `gamebuild`=60189 WHERE `gamebuild`=60037;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '60189';
