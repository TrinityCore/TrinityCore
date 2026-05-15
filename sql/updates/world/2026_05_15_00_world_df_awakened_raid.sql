-- Worldstate for Awakened raids in Dragonflight
DELETE FROM `world_state` WHERE `ID` = 25589;
INSERT INTO `world_state` (`ID`, `DefaultValue`, `MapIDs`, `AreaIDs`, `ScriptName`, `Comment`) VALUES
(25589, 0, NULL, NULL, '', 'Dragonflight - Awakened raids');
