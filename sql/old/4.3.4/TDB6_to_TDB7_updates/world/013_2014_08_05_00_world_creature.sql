-- This spawn is 4.3.4 only
SET @CGUID := 213222; -- set by TDB team (1)
DELETE FROM `creature` WHERE `guid`=@CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 51512, 571, 1, 1, 5762.483, 616.3195, 650.175, 2.129302, 120, 0, 0); -- Mirla Silverblaze (Area: 4395)
