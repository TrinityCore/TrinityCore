DELETE FROM `build_info` WHERE `build` IN (63796);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(63796,11,2,5,NULL);

DELETE FROM `build_auth_key` WHERE `build`=63796 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=63796 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=63796 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=63796 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=63796 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=63796 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=63796 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(63796,'Mac','A64','WoW',0x37C6D6728FE1C680594B374DE295759F),
(63796,'Mac','A64','WoWC',0x5F1902882D5525027A0F0255A68285E4),
(63796,'Mac','x64','WoW',0xA154B606D59E981AABE1D089ED766062),
(63796,'Mac','x64','WoWC',0x9874169656A5E844FDE8E89FDC4D01B6),
(63796,'Win','A64','WoW',0xF11BB1558CDEF01264E8D0D7D0159463),
(63796,'Win','x64','WoW',0x2D124FB65A2BAA4288570C2F8C4A5468),
(63796,'Win','x64','WoWC',0x439696AE133D1F8F28E78D40E0113F41);

UPDATE `realmlist` SET `gamebuild`=63796 WHERE `gamebuild`=63704;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '63796';
