DELETE FROM `build_info` WHERE `build` IN (67403);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(67403,12,0,5,NULL);

DELETE FROM `build_auth_key` WHERE `build`=67403 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=67403 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=67403 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=67403 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=67403 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=67403 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=67403 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(67403,'Mac','A64','WoW',0xEE573F9EA729A9F9E090CDFBDA5BE22B),
(67403,'Mac','A64','WoWC',0x1C5A89C904201AD2B2A7DA370BD0E7B3),
(67403,'Mac','x64','WoW',0x96347A82EE58B9974108F24508251DC9),
(67403,'Mac','x64','WoWC',0xB041BFA73FBF99A6515368A5DEBF9DA2),
(67403,'Win','A64','WoW',0x0BE63FC149F0CB6987130C9FC797B057),
(67403,'Win','x64','WoW',0xB8E645E203411CEE3C29871128EB4620),
(67403,'Win','x64','WoWC',0x5ED83A95B93FAD32FC6FCF167DD8CB94);

UPDATE `realmlist` SET `gamebuild`=67403 WHERE `gamebuild`=67314;

ALTER TABLE `realmlist` CHANGE `gamebuild` `gamebuild` int unsigned NOT NULL DEFAULT '67403';
