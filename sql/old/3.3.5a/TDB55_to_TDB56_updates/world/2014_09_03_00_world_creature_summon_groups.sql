-- SWP: Move Muru summons to database
SET @MURU := 25741;
DELETE FROM `creature_summon_groups` WHERE `summonerId` = @MURU AND `entry` IN (25798, 25799, 25744);
INSERT INTO `creature_summon_groups` (`summonerId`, `summonerType`, `groupId`, `entry`, `position_x`, `position_y`, `position_z`, `orientation`, `summonType`, `summonTime`) VALUES
(@MURU, 0, 0, 25799, 1780.16, 666.83, 71.19, 5.21, 5, 0), -- Shadowsword Fury Mage
(@MURU, 0, 0, 25799, 1847.93, 600.30, 71.30, 2.57, 5, 0),
(@MURU, 0, 0, 25798, 1779.97, 660.64, 71.19, 5.28, 5, 0), -- Shadowsword Berserker
(@MURU, 0, 0, 25798, 1786.20, 661.01, 71.19, 4.51, 5, 0),
(@MURU, 0, 0, 25798, 1845.17, 602.63, 71.28, 2.43, 5, 0),
(@MURU, 0, 0, 25798, 1842.91, 599.93, 71.23, 2.44, 5, 0),
(@MURU, 0, 1, 25744, 1819.90, 609.80, 69.74, 1.94, 5, 0), -- Darkfiend
(@MURU, 0, 1, 25744, 1829.39, 617.89, 69.73, 2.61, 5, 0),
(@MURU, 0, 1, 25744, 1801.98, 633.62, 69.74, 5.71, 5, 0),
(@MURU, 0, 1, 25744, 1830.88, 629.99, 69.73, 3.52, 5, 0),
(@MURU, 0, 1, 25744, 1800.38, 621.41, 69.74, 0.22, 5, 0),
(@MURU, 0, 1, 25744, 1808.30, 612.45, 69.73, 1.02, 5, 0),
(@MURU, 0, 1, 25744, 1823.90, 639.69, 69.74, 4.12, 5, 0),
(@MURU, 0, 1, 25744, 1811.85, 640.46, 69.73, 4.97, 5, 0);
