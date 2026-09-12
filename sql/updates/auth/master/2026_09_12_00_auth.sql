DELETE FROM `build_info` WHERE `build` IN (69814);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(69814,12,1,0,NULL);

DELETE FROM `build_auth_key` WHERE `build`=69814 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=69814 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=69814 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=69814 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=69814 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=69814 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=69814 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(69814,'Mac','A64','WoW',0xD497A69BF6FB25BE54AE23E41A1AFA6E),
(69814,'Mac','A64','WoWC',0x9694CB1E8B652A07C776A30220393858),
(69814,'Mac','x64','WoW',0xFCD40D024C0EE8F8207F60593D41DD91),
(69814,'Mac','x64','WoWC',0xC278DA09AFA8C593143A2E2583F904A9),
(69814,'Win','A64','WoW',0x7EEA3C940FC8A5314EAD50E5C627A530),
(69814,'Win','x64','WoW',0x534805439760F1DD48DD1B68DFE03AC7),
(69814,'Win','x64','WoWC',0x21F435C122C5FD68B5DB3BC2D903AA1B);

UPDATE `realmlist` SET `gamebuild`=69814 WHERE `gamebuild`=69587;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '69814';
