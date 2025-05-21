DELETE FROM `build_info` WHERE `build` IN (60895);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(60895,4,4,2,NULL);

DELETE FROM `build_auth_key` WHERE `build`=60895 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=60895 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=60895 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=60895 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=60895 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=60895 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=60895 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(60895,'Mac','A64','WoW',0x3EB8484A7F8BD3C993891E10396E182F),
(60895,'Mac','A64','WoWC',0xC1F12AD6FB05A5F92B9152D3505DC025),
(60895,'Mac','x64','WoW',0x324477347CCC88C66C12835377288474),
(60895,'Mac','x64','WoWC',0x35192970DDC99E61776C2C65AA479222),
(60895,'Win','A64','WoW',0x078E2CC82A4F3C342A4CE340341567AE),
(60895,'Win','x64','WoW',0x5885E3019AE3F51D0227F92C365BABD3),
(60895,'Win','x64','WoWC',0x0CAE464F32D03F1EEF0F14B2529907D2);

UPDATE `realmlist` SET `gamebuild`=60895 WHERE `gamebuild`=60192;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '60895';
