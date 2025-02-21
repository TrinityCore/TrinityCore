DELETE FROM `build_info` WHERE `build` IN (59302);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(59302,11,0,7,NULL);

DELETE FROM `build_auth_key` WHERE `build`=59302 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=59302 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=59302 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=59302 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=59302 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=59302 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=59302 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(59302,'Mac','A64','WoW',0x70A6BE00213BB70AB96C51280D72D186),
(59302,'Mac','A64','WoWC',0x6A5CFE0D3A4BDEC7D16D33E9ACA7D71D),
(59302,'Mac','x64','WoW',0x9FD959000AFAA2E5F10A4ABE33AC62BE),
(59302,'Mac','x64','WoWC',0xD39B478EFD342D568DCBC2E85FCA574D),
(59302,'Win','A64','WoW',0x60B1757CA707789C9ACD6F1FB69E28D5),
(59302,'Win','x64','WoW',0x330E4E7EF1E07DA8382C813650D7E7B5),
(59302,'Win','x64','WoWC',0xB5A0C54F6B334515E68260F6334E7593);

UPDATE `realmlist` SET `gamebuild`=59302 WHERE `gamebuild`=59207;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '59302';
