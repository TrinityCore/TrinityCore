DELETE FROM `build_info` WHERE `build` IN (69404);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(69404,12,1,0,NULL);

DELETE FROM `build_auth_key` WHERE `build`=69404 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=69404 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=69404 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=69404 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=69404 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=69404 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=69404 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(69404,'Mac','A64','WoW',0xBDA04532B8ADFC14EB0303A039BF7048),
(69404,'Mac','A64','WoWC',0x77C294D2234949A948354CD87CF8EC48),
(69404,'Mac','x64','WoW',0x90AC968F93FD22006D841AECA9238FAF),
(69404,'Mac','x64','WoWC',0xA44B02A5B1B1C180856DAB378492ED45),
(69404,'Win','A64','WoW',0xDB4BB15219663DA52CBF361EFD2E6553),
(69404,'Win','x64','WoW',0xB86BE5F3F07C24ACB8EA41D76E0702FC),
(69404,'Win','x64','WoWC',0x4FE59E2D64FABB732B5864EF37300FFE);

UPDATE `realmlist` SET `gamebuild`=69404 WHERE `gamebuild`=68974;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '69404';
