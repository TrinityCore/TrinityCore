DELETE FROM `build_info` WHERE `build` IN (57388);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(57388,11,0,5,NULL);

DELETE FROM `build_auth_key` WHERE `build`=57388 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=57388 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=57388 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=57388 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=57388 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=57388 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=57388 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(57388,'Mac','A64','WoW',0xFA9D6F044063948AB74FB3FDE335C0D5),
(57388,'Mac','A64','WoWC',0x3962974506F57EF33BBBD4C904A82157),
(57388,'Mac','x64','WoW',0xE7E3432357BC634EBD7B76BA40D51FD2),
(57388,'Mac','x64','WoWC',0xBFFDD44D892A2143B61BB59E448E348C),
(57388,'Win','A64','WoW',0x92129DE92D2BA5F67581C5DE642B1289),
(57388,'Win','x64','WoW',0x16F9CB724C662E3E8029A442443C6305),
(57388,'Win','x64','WoWC',0xDFD9BFFD00FBEFECBF0AEF0FFC9E8F2D);

UPDATE `realmlist` SET `gamebuild`=57388 WHERE `gamebuild`=57292;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '57388';
