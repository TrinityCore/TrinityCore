DELETE FROM `build_info` WHERE `build` IN (56380,56382);
INSERT INTO `build_info` (`build`,`majorVersion`,`minorVersion`,`bugfixVersion`,`hotfixVersion`) VALUES
(56380,11,0,2,NULL),
(56382,11,0,2,NULL);

DELETE FROM `build_auth_key` WHERE `build`=56380 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=56380 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
DELETE FROM `build_auth_key` WHERE `build`=56382 AND `platform`='Win' AND `arch`='x64' AND `type`='WoW';
DELETE FROM `build_auth_key` WHERE `build`=56382 AND `platform`='Win' AND `arch`='x64' AND `type`='WoWC';
INSERT INTO `build_auth_key` (`build`,`platform`,`arch`,`type`,`key`) VALUES
(56380,'Win','x64','WoW',0xD081784493233E2869933FCC01F1A3C1),
(56380,'Win','x64','WoWC',0x4FB3D72D89F5FF01DD7F4E028494A4E6),
(56382,'Win','x64','WoW',0x67C36A3EF655534C58AD50942192BFDA),
(56382,'Win','x64','WoWC',0xA5BD7A1C33039F58CD45CD5C7EBDF122);
