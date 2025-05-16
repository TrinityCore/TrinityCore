DELETE FROM `build_info` WHERE `build` IN (60842);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(60842,3,4,4,NULL);

DELETE FROM `build_auth_key` WHERE `build`=60842 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=60842 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=60842 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=60842 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=60842 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=60842 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=60842 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(60842,'Mac','A64','WoW',0xCDA9B50960C94FBB92BE762F3BB8C7B3),
(60842,'Mac','A64','WoWC',0x319CAF024D514EA56C80CF91CAB60496),
(60842,'Mac','x64','WoW',0x77FABDA0109634F174A955BFE153B0FE),
(60842,'Mac','x64','WoWC',0x04EC6ACB4F8CA096CF2157B39DF84568),
(60842,'Win','A64','WoW',0xB4B946A7321248E79DB156994670BB11),
(60842,'Win','x64','WoW',0xD4280B8097A97489CD74ECDE3B816036),
(60842,'Win','x64','WoWC',0x9483D95B39950C22CDBB1991BE7EA669);

UPDATE `realmlist` SET `gamebuild`=60842 WHERE `gamebuild`=60430;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '60842';
