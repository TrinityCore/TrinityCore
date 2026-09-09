DELETE FROM `build_info` WHERE `build` IN (69587);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(69587,12,1,0,NULL);

DELETE FROM `build_auth_key` WHERE `build`=69587 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=69587 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=69587 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=69587 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=69587 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=69587 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=69587 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(69587,'Mac','A64','WoW',0x7FA9BFC62ACCD945E65A523ACC1F5EDE),
(69587,'Mac','A64','WoWC',0x352327CB18DFF32F75337C368E6F07EA),
(69587,'Mac','x64','WoW',0x1360FA09EC48BBACF779FD8BFCD5979F),
(69587,'Mac','x64','WoWC',0xE22AD5AF37CB1E02A0C8A8A3CC80D950),
(69587,'Win','A64','WoW',0x1D301623C394178B5BBC90BF0CC2468D),
(69587,'Win','x64','WoW',0xEE9E0616CA2E563E9903A519573599CF),
(69587,'Win','x64','WoWC',0x8CD796511F75479A66E6BCE3F1D7BF31);

UPDATE `realmlist` SET `gamebuild`=69587 WHERE `gamebuild`=69497;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '69587';
