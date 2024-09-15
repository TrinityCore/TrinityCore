DELETE FROM `build_info` WHERE `build` IN (56421);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(56421,11,0,2,NULL);

DELETE FROM `build_auth_key` WHERE `build`=56421 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=56421 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(56421,'Win','x64','WoW',0x3BDFA9AA4B70041F2C8B8CDE3C8DC255),
(56421,'Win','x64','WoWC',0x0DDB8F8738647F3CD8FD585A3A78ED1B);

UPDATE `realmlist` SET `gamebuild`=56421 WHERE `gamebuild`=56313;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '56421';
