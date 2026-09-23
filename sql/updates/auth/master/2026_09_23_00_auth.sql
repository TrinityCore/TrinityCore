DELETE FROM `build_info` WHERE `build` IN (69933);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(69933,12,1,0,NULL);

DELETE FROM `build_auth_key` WHERE `build`=69933 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=69933 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=69933 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=69933 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=69933 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=69933 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=69933 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(69933,'Mac','A64','WoW',0x855F995BA81FABAEC8282A64623EF654),
(69933,'Mac','A64','WoWC',0x87753E122E07CFF1C89D513425D51F16),
(69933,'Mac','x64','WoW',0x4F461CA5A8E12A654EE7ECFF66577256),
(69933,'Mac','x64','WoWC',0x55CEFA786E7BAD5C88814CB42A440A4C),
(69933,'Win','A64','WoW',0x8D8FD4D1186C83F2641AF2ADBBB1E674),
(69933,'Win','x64','WoW',0xDE452B2BD2640E83AD944B07B4C76649),
(69933,'Win','x64','WoWC',0x7CD51CFAFB5CE86AFE85D6EDDEC7CF61);

UPDATE `realmlist` SET `gamebuild`=69933 WHERE `gamebuild`=69875;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '69933';
