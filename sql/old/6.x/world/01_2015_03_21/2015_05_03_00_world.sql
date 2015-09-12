DELETE FROM `areatrigger_teleport` WHERE `ID` IN (2068, 3606, 4901, 4909, 4953, 5254, 5493, 5495);
INSERT INTO `areatrigger_teleport` (`ID`, `PortLocID`, `Name`) VALUES
(2068, 3647, 'Blackrock Spire - Target - Shaft'),
(3606, 3697, 'Molten Core Entrance Target'),
(4901, 3797, 'Clayton Teleporter'),
(4909, 3798, 'TEST - CSteele Teleporter Target'),
(4953, 3818, 'Scott Test Target'),
(5254, 3877, 'Teleport to Reliquary of Agony (Target)'),
(5493, 3912, 'Mini House Target'),
(5495, 3913, 'Mega House Target');
