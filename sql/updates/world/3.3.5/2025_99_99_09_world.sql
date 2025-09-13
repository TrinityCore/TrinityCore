UPDATE `world_state` SET `Comment`='Battlegrounds - Horde bases' WHERE `ID`=1778;
UPDATE `world_state` SET `Comment`='Battlegrounds - Alliance bases' WHERE `ID`=1779;

DELETE FROM `world_state` WHERE `ID` IN (3191,3901);
INSERT INTO `world_state` (`ID`,`DefaultValue`,`MapIDs`,`AreaIDs`,`ScriptName`,`Comment`) VALUES
(3191,0,NULL,NULL,'','PvpSeason - Current season ID'),
(3901,0,NULL,NULL,'','PvpSeason - Previous season ID');
