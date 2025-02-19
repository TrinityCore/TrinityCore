DELETE FROM `build_info` WHERE `build` IN (59185);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(59185,4,4,2,NULL);

DELETE FROM `build_auth_key` WHERE `build`=59185 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=59185 AND `platform`='Mac' AND `arch`='A64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=59185 AND `platform`='Mac' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=59185 AND `platform`='Win' AND `arch`='A64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=59185 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=59185 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(59185,'Mac','A64','WoW',0x6CFE66A02B1B3BFC3244E545B6441A3C),
(59185,'Mac','A64','WoWC',0x457EF06E5D847ABAA1301BF46FEC8821),
(59185,'Mac','x64','WoWC',0x059271AD396A89DCB4D6C717003799F0),
(59185,'Win','A64','WoW',0x57E3FCEAE73BFAAEB3FCCE9E3F7653BA),
(59185,'Win','x64','WoW',0x60F053E069B404839B6F7DEE88F40C97),
(59185,'Win','x64','WoWC',0x291C3548C275691818AB78FB047A2F7D);
