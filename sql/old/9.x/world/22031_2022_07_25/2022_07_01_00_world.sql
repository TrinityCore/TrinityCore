DELETE FROM `world_state` WHERE `ID` IN (17042,17043);
INSERT INTO `world_state` (`ID`,`DefaultValue`,`MapIDs`,`AreaIDs`,`Comment`) VALUES
(17042,10,NULL,NULL,'Horde War Mode bonus'),
(17043,10,NULL,NULL,'Alliance War Mode bonus');
