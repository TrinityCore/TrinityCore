DELETE FROM `achievement_criteria_data` WHERE `ScriptName`= 'achievement_ascendant_descending';

DELETE FROM `world_states` WHERE `ID`= 5637;
INSERT INTO `world_states` (`ID`, `DefaultValue`, `MapID`, `Comment`) VALUES
(5637, 0, 645, 'Blackrock Caverns - Ascendant Lord Obsidius - Ascendant Descending');

