DELETE FROM `build_info` WHERE `build` IN (63834);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(63834,11,2,5,NULL);

DELETE FROM `build_auth_key` WHERE `build`=63834 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=63834 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=63834 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=63834 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=63834 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=63834 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=63834 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(63834,'Mac','A64','WoW',0xFBDB4BFD98FAF22C118CFB91D4B0CF56),
(63834,'Mac','A64','WoWC',0x7AC2021D201FCB81BC24A3541B7E44AD),
(63834,'Mac','x64','WoW',0xD1E411CB89026C549C8F2E4043CE596F),
(63834,'Mac','x64','WoWC',0xC1D16D8E2893A07529F54B150D1E9478),
(63834,'Win','A64','WoW',0x9ABF336240A8D5D8A53807CA03009809),
(63834,'Win','x64','WoW',0xA7E739F0FDF745A879791DECE8066BF2),
(63834,'Win','x64','WoWC',0x67808AA1E78AAFDD345070F4AB40DD5C);

UPDATE `realmlist` SET `gamebuild`=63834 WHERE `gamebuild`=63796;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '63834';
