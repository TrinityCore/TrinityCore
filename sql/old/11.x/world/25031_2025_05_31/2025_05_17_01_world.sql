-- Phase
DELETE FROM `phase_name` WHERE `ID` IN (10892,10893,10894,10895,10896,11356);
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(10892, 'Cosmetic - See Horde Krazzlefrazz Outpost Building 1'),
(10893, 'Cosmetic - See Horde Krazzlefrazz Outpost Building 2'),
(10894, 'Cosmetic - See Horde Krazzlefrazz Outpost Building 5 - Torch'),
(10895, 'Cosmetic - See Horde Krazzlefrazz Outpost Building 4'),
(10896, 'Cosmetic - See Horde Krazzlefrazz Outpost Building 5'),
(11356, 'Cosmetic - See Horde Swiftwind Post Buildings');

DELETE FROM `phase_area` WHERE `PhaseId` IN (10892,10893,10894,10895,10896,11356);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(8721, 10892, 'See Horde Krazzlefrazz Outpost Building 1'),
(8721, 10893, 'See Horde Krazzlefrazz Outpost Building 2'),
(8721, 10894, 'See Horde Krazzlefrazz Outpost Building 5 - Torch'),
(8721, 10895, 'See Horde Krazzlefrazz Outpost Building 4'),
(8721, 10896, 'See Horde Krazzlefrazz Outpost Building 5'),
(8721, 11356, 'See Horde Swiftwind Post Buildings');
