DELETE FROM `build_info` WHERE `build` IN (57171);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(57171,11,0,5,NULL);

DELETE FROM `build_auth_key` WHERE `build`=57171 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=57171 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=57171 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=57171 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=57171 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=57171 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=57171 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(57171,'Mac','A64','WoW',0x4327288A88EBDC1EBE58F27BA30F69E6),
(57171,'Mac','A64','WoWC',0x2279265138F9516F382CA160CABDB128),
(57171,'Mac','x64','WoW',0x28D502237C9E250B31CE081A6C540D7F),
(57171,'Mac','x64','WoWC',0x36B3B18FA95E1F153289340FA437C311),
(57171,'Win','A64','WoW',0x9F1E52B1F144DA385F8C6F1E9167D057),
(57171,'Win','x64','WoW',0x967B99503C5D7A0B8B47941E16F60948),
(57171,'Win','x64','WoWC',0x3E17E628F236DA642C9EB0B8624C8499);
