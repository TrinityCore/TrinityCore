DELETE FROM `criteria_data` WHERE `ScriptName`='achievement_three_faced';

DELETE FROM `world_state` WHERE `ID`=4927;
INSERT INTO `world_state` (`ID`,`DefaultValue`,`MapIDs`,`AreaIDs`,`Comment`) VALUES
(4927,0,'632',NULL,'The Forge of Souls - Devourer of Souls - Three Faced achievement failed');
