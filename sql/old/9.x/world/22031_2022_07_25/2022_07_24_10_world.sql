DELETE FROM `world_state` WHERE `ID` IN (4485,4486);
INSERT INTO `world_state` (`ID`, `DefaultValue`, `MapIDs`, `ScriptName`, `Comment`) VALUES
(4485, 0, '-1', '', 'Instances - Generic - Team In Instance - Alliance'),
(4486, 0, '-1', '', 'Instances - Generic - Team In Instance - Horde');
