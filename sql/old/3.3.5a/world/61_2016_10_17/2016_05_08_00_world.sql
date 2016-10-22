SET @CGUID:=84737;

-- Add missing Caravan Mule & Guard Didier <Brotherhood of the Light> spawns
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+5;
INSERT INTO `creature` (`guid`, `id`, `map`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `curhealth`) VALUES 
(@CGUID+0, 16232, 0, 2308.195, -5297.163, 82.0796, 1.780236, 120, 0), -- [65] Caravan Mule
(@CGUID+1, 16232, 0, 2309.498, -5294.246, 82.07687, 1.727876, 120, 0),  -- [66] Caravan Mule
(@CGUID+2, 16232, 0, 2306.324, -5294.137, 82.07687, 1.815142, 120, 0),  -- [67] Caravan Mule
(@CGUID+3, 16232, 0, 2308.93, -5290.619, 82.10618, 1.797689, 120, 0),  -- [68] Caravan Mule
(@CGUID+4, 16232, 0, 2305.878, -5290.338, 82.33588, 1.832596, 120, 0),  -- [69] Caravan Mule
(@CGUID+5, 16226, 0, 2305.295, -5286.124, 82.02069, 4.834562, 120, 0);  -- [70] Guard Didier <Brotherhood of the Light>
