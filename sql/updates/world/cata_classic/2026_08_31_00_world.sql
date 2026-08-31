DELETE FROM `world_safe_locs` WHERE `ID`= 3671;
INSERT INTO `world_safe_locs` (`ID`, `MapID`, `LocX`, `LocY`, `LocZ`, `Facing`, `Comment`) VALUES
(3671, 289, 199.876, 125.346, 138.43, 268, 'Scholomance 1.0 - Entrance target');

DELETE FROM `areatrigger_teleport` WHERE `ID` IN (1468, 2567);
INSERT INTO `areatrigger_teleport` (`ID`, `PortLocID`, `Name`) VALUES
(1468, 3644, 'Blackrock Spire Entrance Target'),
(2567, 3671, 'Scholomance Entrance Target');
