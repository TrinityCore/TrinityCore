DELETE FROM `build_info` WHERE `build` IN (57916);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(57916,4,4,1,NULL);

DELETE FROM `build_auth_key` WHERE `build`=57916 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=57916 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=57916 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=57916 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(57916,'Mac','A64','WoW',0x6D5239A8150D6F988929E03A76782836),
(57916,'Mac','x64','WoW',0x35F1A99195794D82981336E2A92695E7),
(57916,'Win','A64','WoW',0xDEB31A3F7A285EB69D27F4C1C6134D29),
(57916,'Win','x64','WoW',0x20696E852F3B5EE83866BF2A0D34470B);

UPDATE `realmlist` SET `gamebuild`=57916 WHERE `gamebuild`=57564;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '57916';
