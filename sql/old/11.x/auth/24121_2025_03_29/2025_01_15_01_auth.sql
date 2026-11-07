DELETE FROM `build_info` WHERE `build` IN (58630);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(58630,11,0,7,NULL);

DELETE FROM `build_auth_key` WHERE `build`=58630 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=58630 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=58630 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=58630 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=58630 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=58630 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=58630 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(58630,'Mac','A64','WoW',0x045A964F3B8D153E273A3AD862C5C38A),
(58630,'Mac','A64','WoWC',0x3CDC1868FD7BB4E50629421328ED8269),
(58630,'Mac','x64','WoW',0x0D58880FA5FA7A7FD5C2466CEB398601),
(58630,'Mac','x64','WoWC',0x9745E7626C0D7D0A7F57DF1BB1EA4F16),
(58630,'Win','A64','WoW',0xF74A9CB9D6918780C813E2EEE0F24DE0),
(58630,'Win','x64','WoW',0x8C9CDCC711892EAAEA793DBBF3B0C850),
(58630,'Win','x64','WoWC',0xC6A3638E0BAB3A98F40B8371E1BDAECA);

UPDATE `realmlist` SET `gamebuild`=58630 WHERE `gamebuild`=58608;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '58630';
